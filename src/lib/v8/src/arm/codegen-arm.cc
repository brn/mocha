// Copyright 2011 the V8 project authors. All rights reserved.
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
//       copyright notice, this list of conditions and the following
//       disclaimer in the documentation and/or other materials provided
//       with the distribution.
//     * Neither the name of Google Inc. nor the names of its
//       contributors may be used to endorse or promote products derived
//       from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include "v8.h"

#if defined(V8_TARGET_ARCH_ARM)

#include "codegen.h"
#include "macro-assembler.h"

namespace v8 {
namespace internal {

#define __ ACCESS_MASM(masm)

// -------------------------------------------------------------------------
// Platform-specific RuntimeCallHelper functions.

void StubRuntimeCallHelper::BeforeCall(MacroAssembler* masm) const {
  masm->EnterFrame(StackFrame::INTERNAL);
  ASSERT(!masm->has_frame());
  masm->set_has_frame(true);
}


void StubRuntimeCallHelper::AfterCall(MacroAssembler* masm) const {
  masm->LeaveFrame(StackFrame::INTERNAL);
  ASSERT(masm->has_frame());
  masm->set_has_frame(false);
}


// -------------------------------------------------------------------------
// Code generators

void ElementsTransitionGenerator::GenerateSmiOnlyToObject(
    MacroAssembler* masm) {
  // ----------- S t a t e -------------
  //  -- r0    : value
  //  -- r1    : key
  //  -- r2    : receiver
  //  -- lr    : return address
  //  -- r3    : target map, scratch for subsequent call
  //  -- r4    : scratch (elements)
  // -----------------------------------
  // Set transitioned map.
  __ str(r3, FieldMemOperand(r2, HeapObject::kMapOffset));
  __ RecordWriteField(r2,
                      HeapObject::kMapOffset,
                      r3,
                      r9,
                      kLRHasNotBeenSaved,
                      kDontSaveFPRegs,
                      EMIT_REMEMBERED_SET,
                      OMIT_SMI_CHECK);
}


void ElementsTransitionGenerator::GenerateSmiOnlyToDouble(
    MacroAssembler* masm, Label* fail) {
  // ----------- S t a t e -------------
  //  -- r0    : value
  //  -- r1    : key
  //  -- r2    : receiver
  //  -- lr    : return address
  //  -- r3    : target map, scratch for subsequent call
  //  -- r4    : scratch (elements)
  // -----------------------------------
  Label loop, entry, convert_hole, gc_required;
  bool vfp3_supported = CpuFeatures::IsSupported(VFP3);
  __ push(lr);

  __ ldr(r4, FieldMemOperand(r2, JSObject::kElementsOffset));
  __ ldr(r5, FieldMemOperand(r4, FixedArray::kLengthOffset));
  // r4: source FixedArray
  // r5: number of elements (smi-tagged)

  // Allocate new FixedDoubleArray.
  __ mov(lr, Operand(FixedDoubleArray::kHeaderSize));
  __ add(lr, lr, Operand(r5, LSL, 2));
  __ AllocateInNewSpace(lr, r6, r7, r9, &gc_required, NO_ALLOCATION_FLAGS);
  // r6: destination FixedDoubleArray, not tagged as heap object
  __ LoadRoot(r9, Heap::kFixedDoubleArrayMapRootIndex);
  __ str(r9, MemOperand(r6, HeapObject::kMapOffset));
  // Set destination FixedDoubleArray's length.
  __ str(r5, MemOperand(r6, FixedDoubleArray::kLengthOffset));
  // Update receiver's map.

  __ str(r3, FieldMemOperand(r2, HeapObject::kMapOffset));
  __ RecordWriteField(r2,
                      HeapObject::kMapOffset,
                      r3,
                      r9,
                      kLRHasBeenSaved,
                      kDontSaveFPRegs,
                      EMIT_REMEMBERED_SET,
                      OMIT_SMI_CHECK);
  // Replace receiver's backing store with newly created FixedDoubleArray.
  __ add(r3, r6, Operand(kHeapObjectTag));
  __ str(r3, FieldMemOperand(r2, JSObject::kElementsOffset));
  __ RecordWriteField(r2,
                      JSObject::kElementsOffset,
                      r3,
                      r9,
                      kLRHasBeenSaved,
                      kDontSaveFPRegs,
                      EMIT_REMEMBERED_SET,
                      OMIT_SMI_CHECK);

  // Prepare for conversion loop.
  __ add(r3, r4, Operand(FixedArray::kHeaderSize - kHeapObjectTag));
  __ add(r7, r6, Operand(FixedDoubleArray::kHeaderSize));
  __ add(r6, r7, Operand(r5, LSL, 2));
  __ mov(r4, Operand(kHoleNanLower32));
  __ mov(r5, Operand(kHoleNanUpper32));
  // r3: begin of source FixedArray element fields, not tagged
  // r4: kHoleNanLower32
  // r5: kHoleNanUpper32
  // r6: end of destination FixedDoubleArray, not tagged
  // r7: begin of FixedDoubleArray element fields, not tagged
  if (!vfp3_supported) __ Push(r1, r0);

  __ b(&entry);

  // Call into runtime if GC is required.
  __ bind(&gc_required);
  __ pop(lr);
  __ b(fail);

  // Convert and copy elements.
  __ bind(&loop);
  __ ldr(r9, MemOperand(r3, 4, PostIndex));
  // r9: current element
  __ JumpIfNotSmi(r9, &convert_hole);

  // Normal smi, convert to double and store.
  __ SmiUntag(r9);
  if (vfp3_supported) {
    CpuFeatures::Scope scope(VFP3);
    __ vmov(s0, r9);
    __ vcvt_f64_s32(d0, s0);
    __ vstr(d0, r7, 0);
    __ add(r7, r7, Operand(8));
  } else {
    FloatingPointHelper::ConvertIntToDouble(masm,
                                            r9,
                                            FloatingPointHelper::kCoreRegisters,
                                            d0,
                                            r0,
                                            r1,
                                            lr,
                                            s0);
    __ Strd(r0, r1, MemOperand(r7, 8, PostIndex));
  }
  __ b(&entry);

  // Hole found, store the-hole NaN.
  __ bind(&convert_hole);
  if (FLAG_debug_code) {
    __ CompareRoot(r9, Heap::kTheHoleValueRootIndex);
    __ Assert(eq, "object found in smi-only array");
  }
  __ Strd(r4, r5, MemOperand(r7, 8, PostIndex));

  __ bind(&entry);
  __ cmp(r7, r6);
  __ b(lt, &loop);

  if (!vfp3_supported) __ Pop(r1, r0);
  __ pop(lr);
}


void ElementsTransitionGenerator::GenerateDoubleToObject(
    MacroAssembler* masm, Label* fail) {
  // ----------- S t a t e -------------
  //  -- r0    : value
  //  -- r1    : key
  //  -- r2    : receiver
  //  -- lr    : return address
  //  -- r3    : target map, scratch for subsequent call
  //  -- r4    : scratch (elements)
  // -----------------------------------
  Label entry, loop, convert_hole, gc_required;

  __ push(lr);
  __ Push(r3, r2, r1, r0);

  __ ldr(r4, FieldMemOperand(r2, JSObject::kElementsOffset));
  __ ldr(r5, FieldMemOperand(r4, FixedArray::kLengthOffset));
  // r4: source FixedDoubleArray
  // r5: number of elements (smi-tagged)

  // Allocate new FixedArray.
  __ mov(r0, Operand(FixedDoubleArray::kHeaderSize));
  __ add(r0, r0, Operand(r5, LSL, 1));
  __ AllocateInNewSpace(r0, r6, r7, r9, &gc_required, NO_ALLOCATION_FLAGS);
  // r6: destination FixedArray, not tagged as heap object
  __ LoadRoot(r9, Heap::kFixedArrayMapRootIndex);
  __ str(r9, MemOperand(r6, HeapObject::kMapOffset));
  // Set destination FixedDoubleArray's length.
  __ str(r5, MemOperand(r6, FixedDoubleArray::kLengthOffset));

  // Prepare for conversion loop.
  __ add(r4, r4, Operand(FixedDoubleArray::kHeaderSize - kHeapObjectTag + 4));
  __ add(r3, r6, Operand(FixedArray::kHeaderSize));
  __ add(r6, r6, Operand(kHeapObjectTag));
  __ add(r5, r3, Operand(r5, LSL, 1));
  __ LoadRoot(r7, Heap::kTheHoleValueRootIndex);
  __ LoadRoot(r9, Heap::kHeapNumberMapRootIndex);
  // Using offsetted addresses in r4 to fully take advantage of post-indexing.
  // r3: begin of destination FixedArray element fields, not tagged
  // r4: begin of source FixedDoubleArray element fields, not tagged, +4
  // r5: end of destination FixedArray, not tagged
  // r6: destination FixedArray
  // r7: the-hole pointer
  // r9: heap number map
  __ b(&entry);

  // Call into runtime if GC is required.
  __ bind(&gc_required);
  __ Pop(r3, r2, r1, r0);
  __ pop(lr);
  __ b(fail);

  __ bind(&loop);
  __ ldr(r1, MemOperand(r4, 8, PostIndex));
  // lr: current element's upper 32 bit
  // r4: address of next element's upper 32 bit
  __ cmp(r1, Operand(kHoleNanUpper32));
  __ b(eq, &convert_hole);

  // Non-hole double, copy value into a heap number.
  __ AllocateHeapNumber(r2, r0, lr, r9, &gc_required);
  // r2: new heap number
  __ ldr(r0, MemOperand(r4, 12, NegOffset));
  __ Strd(r0, r1, FieldMemOperand(r2, HeapNumber::kValueOffset));
  __ mov(r0, r3);
  __ str(r2, MemOperand(r3, 4, PostIndex));
  __ RecordWrite(r6,
                 r0,
                 r2,
                 kLRHasBeenSaved,
                 kDontSaveFPRegs,
                 EMIT_REMEMBERED_SET,
                 OMIT_SMI_CHECK);
  __ b(&entry);

  // Replace the-hole NaN with the-hole pointer.
  __ bind(&convert_hole);
  __ str(r7, MemOperand(r3, 4, PostIndex));

  __ bind(&entry);
  __ cmp(r3, r5);
  __ b(lt, &loop);

  __ Pop(r3, r2, r1, r0);
  // Update receiver's map.
  __ str(r3, FieldMemOperand(r2, HeapObject::kMapOffset));
  __ RecordWriteField(r2,
                      HeapObject::kMapOffset,
                      r3,
                      r9,
                      kLRHasBeenSaved,
                      kDontSaveFPRegs,
                      EMIT_REMEMBERED_SET,
                      OMIT_SMI_CHECK);
  // Replace receiver's backing store with newly created and filled FixedArray.
  __ str(r6, FieldMemOperand(r2, JSObject::kElementsOffset));
  __ RecordWriteField(r2,
                      JSObject::kElementsOffset,
                      r6,
                      r9,
                      kLRHasBeenSaved,
                      kDontSaveFPRegs,
                      EMIT_REMEMBERED_SET,
                      OMIT_SMI_CHECK);
  __ pop(lr);
}


void StringCharLoadGenerator::Generate(MacroAssembler* masm,
                                       Register string,
                                       Register index,
                                       Register result,
                                       Label* call_runtime) {
  // Fetch the instance type of the receiver into result register.
  __ ldr(result, FieldMemOperand(string, HeapObject::kMapOffset));
  __ ldrb(result, FieldMemOperand(result, Map::kInstanceTypeOffset));

  // We need special handling for indirect strings.
  Label check_sequential;
  __ tst(result, Operand(kIsIndirectStringMask));
  __ b(eq, &check_sequential);

  // Dispatch on the indirect string shape: slice or cons.
  Label cons_string;
  __ tst(result, Operand(kSlicedNotConsMask));
  __ b(eq, &cons_string);

  // Handle slices.
  Label indirect_string_loaded;
  __ ldr(result, FieldMemOperand(string, SlicedString::kOffsetOffset));
  __ add(index, index, Operand(result, ASR, kSmiTagSize));
  __ ldr(string, FieldMemOperand(string, SlicedString::kParentOffset));
  __ jmp(&indirect_string_loaded);

  // Handle cons strings.
  // Check whether the right hand side is the empty string (i.e. if
  // this is really a flat string in a cons string). If that is not
  // the case we would rather go to the runtime system now to flatten
  // the string.
  __ bind(&cons_string);
  __ ldr(result, FieldMemOperand(string, ConsString::kSecondOffset));
  __ LoadRoot(ip, Heap::kEmptyStringRootIndex);
  __ cmp(result, ip);
  __ b(ne, call_runtime);
  // Get the first of the two strings and load its instance type.
  __ ldr(string, FieldMemOperand(string, ConsString::kFirstOffset));

  __ bind(&indirect_string_loaded);
  __ ldr(result, FieldMemOperand(string, HeapObject::kMapOffset));
  __ ldrb(result, FieldMemOperand(result, Map::kInstanceTypeOffset));

  // Distinguish sequential and external strings. Only these two string
  // representations can reach here (slices and flat cons strings have been
  // reduced to the underlying sequential or external string).
  Label external_string, check_encoding;
  __ bind(&check_sequential);
  STATIC_ASSERT(kSeqStringTag == 0);
  __ tst(result, Operand(kStringRepresentationMask));
  __ b(ne, &external_string);

  // Prepare sequential strings
  STATIC_ASSERT(SeqTwoByteString::kHeaderSize == SeqAsciiString::kHeaderSize);
  __ add(string,
         string,
         Operand(SeqTwoByteString::kHeaderSize - kHeapObjectTag));
  __ jmp(&check_encoding);

  // Handle external strings.
  __ bind(&external_string);
  if (FLAG_debug_code) {
    // Assert that we do not have a cons or slice (indirect strings) here.
    // Sequential strings have already been ruled out.
    __ tst(result, Operand(kIsIndirectStringMask));
    __ Assert(eq, "external string expected, but not found");
  }
  // Rule out short external strings.
  STATIC_CHECK(kShortExternalStringTag != 0);
  __ tst(result, Operand(kShortExternalStringMask));
  __ b(ne, call_runtime);
  __ ldr(string, FieldMemOperand(string, ExternalString::kResourceDataOffset));

  Label ascii, done;
  __ bind(&check_encoding);
  STATIC_ASSERT(kTwoByteStringTag == 0);
  __ tst(result, Operand(kStringEncodingMask));
  __ b(ne, &ascii);
  // Two-byte string.
  __ ldrh(result, MemOperand(string, index, LSL, 1));
  __ jmp(&done);
  __ bind(&ascii);
  // Ascii string.
  __ ldrb(result, MemOperand(string, index));
  __ bind(&done);
}

#undef __

} }  // namespace v8::internal

#endif  // V8_TARGET_ARCH_ARM
