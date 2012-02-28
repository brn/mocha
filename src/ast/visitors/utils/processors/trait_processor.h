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
  static AstNode* ProcessMixin( AstNode* mixin , ProcessorInfo* info , long line );
 private :
  void CommonProcessor_( NodeList* list , IteratorGetter getter , const char* type );
  void ProcessPrivate_( NodeList* list );
  void ProcessPublic_( NodeList* list );
  void ProcessRequires_( NodeList* list );
  void CreateMixinStmt_( AstNode* mixin_list , AstNode* mark );
  Trait* trait_;
  ProcessorInfo* info_;
  Literal* name_;
  AstNode* body_;
};

}

#endif
