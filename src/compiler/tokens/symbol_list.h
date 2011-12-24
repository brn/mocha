#ifndef mocha_symbol_list_h_
#define mocha_symbol_list_h_
#include <utils/class_traits/static.h>
namespace mocha {

class SymbolList : private Static {
 public :
  typedef enum {
    kGlobalExport,
    kGlobalAlias,
    kLocalExport,
    kLocalTmp,
    kPrivateHolder,
    kToArray,
    kRuntime,
    kCreateUnenumProp,
    kTypeId,
    kConstant,
    kPrivateField,
    kExtendClass,
    kExtendPrototype
  } RuntimeSymbol;

  typedef enum {
    kArguments,
    kUndefined,
    kConstructor,
    kThis,
    kApply,
    kPrototype
  } BuiltinSymbol;
  
  static const char* GetSymbol( RuntimeSymbol runtime_symbol );
  static const char* GetSymbol( BuiltinSymbol builtin_symbol );
};

}

#endif
