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

#include <stdlib.h>

#include "v8.h"

#include "factory.h"
#include "macro-assembler.h"
#include "cctest.h"
#include "code-stubs.h"
#include "objects.h"

#ifdef USE_SIMULATOR
#include "simulator.h"
#endif

using namespace v8::internal;


typedef uint32_t (*HASH_FUNCTION)();

static v8::Persistent<v8::Context> env;

#define __ assm->


void generate(MacroAssembler* assm, i::Vector<const char> string) {
#ifdef V8_TARGET_ARCH_IA32
  __ push(ebx);
  __ push(ecx);
  __ mov(eax, Immediate(0));
  if (string.length() > 0) {
    __ mov(ebx, Immediate(string.at(0)));
    StringHelper::GenerateHashInit(assm, eax, ebx, ecx);
  }
  for (int i = 1; i < string.length(); i++) {
    __ mov(ebx, Immediate(string.at(i)));
    StringHelper::GenerateHashAddCharacter(assm, eax, ebx, ecx);
  }
  StringHelper::GenerateHashGetHash(assm, eax, ecx);
  __ pop(ecx);
  __ pop(ebx);
  __ Ret();
#elif V8_TARGET_ARCH_X64
  __ push(rbx);
  __ push(rcx);
  __ movq(rax, Immediate(0));
  if (string.length() > 0) {
    __ movq(rbx, Immediate(string.at(0)));
    StringHelper::GenerateHashInit(assm, rax, rbx, rcx);
  }
  for (int i = 1; i < string.length(); i++) {
    __ movq(rbx, Immediate(string.at(i)));
    StringHelper::GenerateHashAddCharacter(assm, rax, rbx, rcx);
  }
  StringHelper::GenerateHashGetHash(assm, rax, rcx);
  __ pop(rcx);
  __ pop(rbx);
  __ Ret();
#elif V8_TARGET_ARCH_ARM
  __ mov(r0, Operand(0));
  if (string.length() > 0) {
    __ mov(ip, Operand(string.at(0)));
    StringHelper::GenerateHashInit(assm, r0, ip);
  }
  for (int i = 1; i < string.length(); i++) {
    __ mov(ip, Operand(string.at(i)));
    StringHelper::GenerateHashAddCharacter(assm, r0, ip);
  }
  StringHelper::GenerateHashGetHash(assm, r0);
  __ mov(pc, Operand(lr));
#elif V8_TARGET_ARCH_MIPS
  __ li(v0, Operand(0));
  if (string.length() > 0) {
    __ li(t1, Operand(string.at(0)));
    StringHelper::GenerateHashInit(assm, v0, t1);
  }
  for (int i = 1; i < string.length(); i++) {
    __ li(t1, Operand(string.at(i)));
    StringHelper::GenerateHashAddCharacter(assm, v0, t1);
  }
  StringHelper::GenerateHashGetHash(assm, v0);
  __ jr(ra);
  __ nop();
#endif
}


void check(i::Vector<const char> string) {
  v8::HandleScope scope;
  v8::internal::byte buffer[2048];
  MacroAssembler assm(Isolate::Current(), buffer, sizeof buffer);

  generate(&assm, string);

  CodeDesc desc;
  assm.GetCode(&desc);
  Code* code = Code::cast(HEAP->CreateCode(
      desc,
      Code::ComputeFlags(Code::STUB),
      Handle<Object>(HEAP->undefined_value()))->ToObjectChecked());
  CHECK(code->IsCode());

  HASH_FUNCTION hash = FUNCTION_CAST<HASH_FUNCTION>(code->entry());
  Handle<String> v8_string = FACTORY->NewStringFromAscii(string);
  v8_string->set_hash_field(String::kEmptyHashField);
#ifdef USE_SIMULATOR
  uint32_t codegen_hash =
      reinterpret_cast<uint32_t>(CALL_GENERATED_CODE(hash, 0, 0, 0, 0, 0));
#else
  uint32_t codegen_hash = hash();
#endif
  uint32_t runtime_hash = v8_string->Hash();
  CHECK(runtime_hash == codegen_hash);
}


void check_twochars(char a, char b) {
  char ab[2] = {a, b};
  check(i::Vector<const char>(ab, 2));
}


TEST(StringHash) {
  if (env.IsEmpty()) env = v8::Context::New();
  for (int a = 0; a < String::kMaxAsciiCharCode; a++) {
    // Numbers are hashed differently.
    if (a >= '0' && a <= '9') continue;
    for (int b = 0; b < String::kMaxAsciiCharCode; b++) {
      if (b >= '0' && b <= '9') continue;
      check_twochars(static_cast<char>(a), static_cast<char>(b));
    }
  }
  check(i::Vector<const char>("",        0));
  check(i::Vector<const char>("*",       1));
  check(i::Vector<const char>(".zZ",     3));
  check(i::Vector<const char>("muc",     3));
  check(i::Vector<const char>("(>'_')>", 7));
  check(i::Vector<const char>("-=[ vee eight ftw ]=-", 21));
}

#undef __
