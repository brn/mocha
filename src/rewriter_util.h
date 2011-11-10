#ifndef mocha_rewriter_util_h_
#define mocha_rewriter_util_h_

namespace mocha {

class RewriterUtil {
 public :
  typedef enum {
    kAstRoot,
    kAstTree,
    kRootBlock,
    kUnaryExp,
    kArrayAccessor,
    kDotAccessor,
    kNewCallAccessor,
    kNewAccessor,
    kCallAccessor,
    kPostfixExp,
    kMultiplicativeExp,
    kAdditiveExp,
    kShiftExp,
    kRelationalExp,
    kEqualityExp,
    kBitwiseANDExp,
    kBitwiseXORExp,
    kBitwiseORExp,
    kLogicalANDExp,
    kLogicalORExp,
    kConditionalExp,
    kAssign,
    kFormalParameter,
    kBlock,
    kVariableDeclaration,
    kVariableDeclarationList,
    kStmtList,
    kExpression,
    kExpressionStmt,
    kIFStmt,
    kContinue,
    kBreak,
    kReturn,
    kWith,
    kLabel,
    kSwitch,
    kThrow,
    kTry,
    kCatch,
    kFinally,
    kFunction,
    kFor,
    kForIn,
    kWhile,
    kDoWhile,
    kCaseClause,
    kCaseClauses,
    kDefaultClause,
    kSymbol,
    kConstantLiteral,
    kArguments,
    kObjectLiteral,
    kArrayLiteral,
    kElementList,
    kObjectMember,
    kNumberLiteral,
    kThis,
    kStringLiteral,
    kNullLiteral,
    kRegExpLiteral,
    kBooleanLiteral,
    kUndefinedLiteral,
    kIdentifier
  } kAstTypeTag;
  void AddNode( AstTypeBase* node , kAstTypeTag tag );
  void Connect( AstTypeBase* node , kAstTypeTag tag );
 private :
  kAstTypeTag tag_;
  AstTypeBase* node_;
};

}

#endif
