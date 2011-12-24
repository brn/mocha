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
  "__FILE__"
};

static const char builtin[][50] = {
  "arguments",
  "undefined",
  "constructor",
  "this",
  "apply",
  "prototype"
};


const char* SymbolList::GetSymbol( RuntimeSymbol runtime_symbol ) {
  return runtime[ runtime_symbol ];
}
const char* SymbolList::GetSymbol( BuiltinSymbol builtin_symbol ) {
  return builtin[ builtin_symbol ];
}

}
