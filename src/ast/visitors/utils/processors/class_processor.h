#ifndef mocha_class_processor_h_
#define mocha_class_processor_h_
#include <string>
#include <boost/unordered_map.hpp>
#include <utils/pool/managed.h>
#include <ast/ast_foward_decl.h>

namespace mocha {

class ProcessorInfo;
class ClassProcessor : public Managed {
 public :
  ClassProcessor( ProcessorInfo* info , Class* ast_node , Statement* tmp_stmt );
  ~ClassProcessor(){};
  void ProcessNode();
 private :
  inline void ProcessBody_( AstNode* body );
  inline void ProcessMember_( ClassProperties* body );
  inline void IterateMember_( AstNode* list , bool is_prototype , bool is_private , bool is_instance );
  void ProcessEachMember_( AstNode* node , bool is_prototype , bool is_private , bool is_instance );
  inline void ProcessVariable_( AstNode* node , bool is_prototype , bool is_private , bool is_instance , bool is_const );
  inline void ProcessFunction_( Function* function , bool is_prottoype , bool is_private );
  inline void ProcessConstructor_( Function* constructor );

  int class_id_;
  std::string name_;
  ProcessorInfo *info_;
  AstNode* closure_;
  Class* class_;
  Function* closure_body_;
  Statement* tmp_stmt_;
  Function* constructor_;
};

};

#endif
