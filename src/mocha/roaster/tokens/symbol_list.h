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
    kAssert,
    kIteratorKey,
    kThrowStopIteration,
    kHasIterator,
    kGetIterator,
    kTypeid,
    kGetUid,
    kCreatePrivateRecord,
    kGetPrivateRecord,
    kSuper,
    kGetSuper,
    kClassMark,
    kTraitPrivate,
    kTraitPublic,
    kTraitMark,
    kMixin,
    kRequires,
    kClassMixin,
    kCheckRequirements,
    kCreateTuple,
    kCreateRecord,
    kInitializeClass
  } RuntimeSymbol;

  typedef enum {
    kArguments,
    kUndefined,
    kConstructor,
    kThis,
    kApply,
    kCall,
    kPrototype,
    kLength,
    kTrue,
    kFalse,
    kBind,
    kPush,
    kTrait,
    kFrom,
    kOf,
    kNaN,
    kFunctionConstructor,
    kArrayConstructor,
    kObjectConstructor,
    kStringConstructor,
    kNumberConstructor
  } BuiltinSymbol;
  
  static const char* symbol(RuntimeSymbol runtime_symbol);
  static const char* symbol(BuiltinSymbol builtin_symbol);
};

}

#endif
