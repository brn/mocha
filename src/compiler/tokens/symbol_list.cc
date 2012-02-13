#include <compiler/tokens/symbol_list.h>

namespace mocha {

static const char runtime[][50] = {
  "_mochaGlobalExport",
  "_mochaGlobalAlias",
  "_mochaLocalExport",
  "_mochaLocalTmp",
  "_mochaPrivateHolder",
  "toArray",
  "Runtime",
  "createUnenumProp",
  "__typeid__",
  "constant",
  "__private__",
  "extendClass",
  "extendPrototype",
  "__MODULE__",
  "__FILE__",
  "__LINE__",
  "_yieldState",
  "next",
  "send",
  "exceptionHandler",
  "_yieldResult",
  "_isYieldSend",
  "_isYieldSafe",
  "_mochaGenerator",
  "_mochaIsNewBorn",
  "StopIteration",
  "throwException",
  "close",
  "_mochaFinallyCache",
  "_mochaCatchCache",
  "_mochaException",
  "createGenerator",
  "__nothrowNext__",
  "extend",
  "assert",
  "__ref_iterator__",
  "throwStopIteration",
  "hasIterator",
  "getIterator",
  "__typeid__",
  "getUid",
  "createPrivateRecord",
  "getPrivateRecord",
  "_mochaSuper",
  "getSuper"
};

static const char builtin[][50] = {
  "arguments",
  "undefined",
  "constructor",
  "this",
  "apply",
  "call",
  "prototype",
  "length",
  "true",
  "false",
  "bind",
  "push"
};


const char* SymbolList::GetSymbol( RuntimeSymbol runtime_symbol ) {
  return runtime[ runtime_symbol ];
}
const char* SymbolList::GetSymbol( BuiltinSymbol builtin_symbol ) {
  return builtin[ builtin_symbol ];
}

}
