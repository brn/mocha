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
    kExtendPrototype,
    kScopeModule,
    kFile,
    kLine,
    kYieldState,
    kYieldNext,
    kYieldSend,
    kExceptionHandler,
    kYieldResult,
    kYieldSendFlag,
    kYieldSafeFlag,
    kGenerator,
    kIsNewBorn,
    kStopIteration,
    kThrowException,
    kClose,
    kFinallyCache,
    kCatchCache,
    kException,
    kCreateGenerator,
    kNoThrow,
    kExtend,
    kAssert
  } RuntimeSymbol;

  typedef enum {
    kArguments,
    kUndefined,
    kConstructor,
    kThis,
    kApply,
    kPrototype,
    kLength,
    kTrue,
    kFalse,
    kBind,
    kPush
  } BuiltinSymbol;
  
  static const char* GetSymbol( RuntimeSymbol runtime_symbol );
  static const char* GetSymbol( BuiltinSymbol builtin_symbol );
};

}

#endif
