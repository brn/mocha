#ifndef mocha_trait_processor_h_
#define mocha_trait_processor_h_
#include <ast/ast.h>
namespace mocha {
class ProcessorInfo;
class TraitProcessor {
 private :
  typedef NodeIterator (*IteratorGetter)( Trait* trait );
 public :
  TraitProcessor( Trait* trait , ProcessorInfo* info );
  ~TraitProcessor(){}
  void ProcessNode();
  static AstNode* ProcessMixin( AstNode* mixin , ProcessorInfo* info , int64_t line );
 private :
  void CommonProcessor( NodeList* list , IteratorGetter getter , const char* type );
  void ProcessPrivate( NodeList* list );
  void ProcessPublic( NodeList* list );
  void ProcessRequires( NodeList* list );
  void CreateMixinStmt( AstNode* mixin_list , AstNode* mark );
  Trait* trait_;
  ProcessorInfo* info_;
  Literal* name_;
  AstNode* body_;
};

}

#endif
