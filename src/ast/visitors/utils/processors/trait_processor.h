#ifndef mocha_trait_processor_h_
#define mocha_trait_processor_h_
#include <ast/ast_foward_decl.h>
namespace mocha {
class ProcessorInfo;
class TraitProcessor {
 private :
  typedef NodeIterator (*IteratorGetter)( Trait* trait );
 public :
  TraitProcessor( Trait* trait , ProcessorInfo* info );
  ~TraitProcessor(){}
  void ProcessNode();
 private :
  void CommonProcessor_( NodeList* list , IteratorGetter getter , const char* type );
  void ProcessPrivate_( NodeList* list );
  void ProcessPublic_( NodeList* list );
  void ProcessMixin_( AstNode* mark );
  void ProcessRequires_( NodeList* list );

  Trait* trait_;
  ProcessorInfo* info_;
  ValueNode* name_;
  AstNode* body_;
};

}

#endif
