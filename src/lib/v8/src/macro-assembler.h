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

#ifndef V8_MACRO_ASSEMBLER_H_
#define V8_MACRO_ASSEMBLER_H_


// Helper types to make boolean flag easier to read at call-site.
enum InvokeFlag {
  CALL_FUNCTION,
  JUMP_FUNCTION
};


enum CodeLocation {
  IN_JAVASCRIPT,
  IN_JS_ENTRY,
  IN_C_ENTRY
};


enum HandlerType {
  TRY_CATCH_HANDLER,
  TRY_FINALLY_HANDLER,
  JS_ENTRY_HANDLER
};


// Types of uncatchable exceptions.
enum UncatchableExceptionType {
  OUT_OF_MEMORY,
  TERMINATION
};


// Invalid depth in prototype chain.
const int kInvalidProtoDepth = -1;

#if V8_TARGET_ARCH_IA32
#include "assembler.h"
#include "ia32/assembler-ia32.h"
#include "ia32/assembler-ia32-inl.h"
#include "code.h"  // must be after assembler_*.h
#include "ia32/macro-assembler-ia32.h"
#elif V8_TARGET_ARCH_X64
#include "assembler.h"
#include "x64/assembler-x64.h"
#include "x64/assembler-x64-inl.h"
#include "code.h"  // must be after assembler_*.h
#include "x64/macro-assembler-x64.h"
#elif V8_TARGET_ARCH_ARM
#include "arm/constants-arm.h"
#include "assembler.h"
#include "arm/assembler-arm.h"
#include "arm/assembler-arm-inl.h"
#include "code.h"  // must be after assembler_*.h
#include "arm/macro-assembler-arm.h"
#elif V8_TARGET_ARCH_MIPS
#include "mips/constants-mips.h"
#include "assembler.h"
#include "mips/assembler-mips.h"
#include "mips/assembler-mips-inl.h"
#include "code.h"  // must be after assembler_*.h
#include "mips/macro-assembler-mips.h"
#else
#error Unsupported target architecture.
#endif

namespace v8 {
namespace internal {

class FrameScope {
 public:
  explicit FrameScope(MacroAssembler* masm, StackFrame::Type type)
      : masm_(masm), type_(type), old_has_frame_(masm->has_frame()) {
    masm->set_has_frame(true);
    if (type != StackFrame::MANUAL && type_ != StackFrame::NONE) {
      masm->EnterFrame(type);
    }
  }

  ~FrameScope() {
    if (type_ != StackFrame::MANUAL && type_ != StackFrame::NONE) {
      masm_->LeaveFrame(type_);
    }
    masm_->set_has_frame(old_has_frame_);
  }

  // Normally we generate the leave-frame code when this object goes
  // out of scope.  Sometimes we may need to generate the code somewhere else
  // in addition.  Calling this will achieve that, but the object stays in
  // scope, the MacroAssembler is still marked as being in a frame scope, and
  // the code will be generated again when it goes out of scope.
  void GenerateLeaveFrame() {
    masm_->LeaveFrame(type_);
  }

 private:
  MacroAssembler* masm_;
  StackFrame::Type type_;
  bool old_has_frame_;
};


class AllowExternalCallThatCantCauseGC: public FrameScope {
 public:
  explicit AllowExternalCallThatCantCauseGC(MacroAssembler* masm)
      : FrameScope(masm, StackFrame::NONE) { }
};


class NoCurrentFrameScope {
 public:
  explicit NoCurrentFrameScope(MacroAssembler* masm)
      : masm_(masm), saved_(masm->has_frame()) {
    masm->set_has_frame(false);
  }

  ~NoCurrentFrameScope() {
    masm_->set_has_frame(saved_);
  }

 private:
  MacroAssembler* masm_;
  bool saved_;
};


// Support for "structured" code comments.
#ifdef DEBUG

class Comment {
 public:
  Comment(MacroAssembler* masm, const char* msg);
  ~Comment();

 private:
  MacroAssembler* masm_;
  const char* msg_;
};

#else

class Comment {
 public:
  Comment(MacroAssembler*, const char*)  {}
};

#endif  // DEBUG

} }  // namespace v8::internal

#endif  // V8_MACRO_ASSEMBLER_H_