/**
 *@author Taketoshi Aono
 *@fileOverview
 *@license
 *Copyright (c) 2011 Taketoshi Aono
 *Licensed under the BSD.
 *
 *Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
 *associated doc umentation files (the "Software"), to deal in the Software without restriction,
 *including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 *subject to the following conditions:
 *
 *The above copyright notice and this permission notice shall be included in all copies or
 *substantial portions ofthe Software.
 *
 *THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 *TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 *THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 *CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *DEALINGS IN THE SOFTWARE.
 */
#ifndef mocha_class_processor_h_
#define mocha_class_processor_h_
#include <string>
#include <boost/unordered_map.hpp>
#include <utils/pool/managed.h>
#include <utils/pool/managed_handle.h>
#include <utils/hash/hash_map/hash_map.h>
#include <ast/ast_foward_decl.h>

namespace mocha {

class ProcessorInfo;
class ClassProcessorUtils;
typedef void (ClassProcessorUtils::*DstaCallback)( const char* class_name,
                                                   Function* closure_body,
                                                   ValueNode* exp,
                                                   bool is_const );
class ClassProcessor : public Managed {
 public :
  inline static ClassProcessor* New( ProcessorInfo* info , Class* ast_node , Statement* tmp_stmt ) {
    return ManagedHandle::Retain( new ClassProcessor( info , ast_node , tmp_stmt ) );
  }
  ClassProcessor( ProcessorInfo* info , Class* ast_node , Statement* tmp_stmt );
  ~ClassProcessor();
  void ProcessNode();
  const char* GetName() { return name_.c_str(); }
 private :

  inline void Initialize();
  inline void SetName( AstNode* node );
  inline Function* CreateBaseConstructor();
  inline void ProcessExtends( AstNode* node );
  inline void ProcessBody( AstNode* body );
  inline void ProcessMember( ClassProperties* body );
  inline void IterateMember( AstNode* list , bool is_prototype , bool is_private , bool is_instance );
  inline void ProcessEachMember( AstNode* node , bool is_prototype , bool is_private , bool is_instance );
  inline void ProcessVariable( AstNode* node , bool is_prototype , bool is_private , bool is_instance , bool is_const );
  inline void ProcessFunction( Function* function , bool is_prottoype , bool is_private , bool is_instance );
  inline void ProcessConstructor( Function* constructor );
  inline void CreateEmptyConstructor();
  inline void ProcessDsta( ValueNode* value ,bool is_const , DstaCallback callback );
  inline void SimpleVariables( AstNode* node , bool is_const );
  inline void NoSimpleVariables( AstNode* node , bool is_prototype , bool is_private , bool is_instance , bool is_const );


  std::string name_;
  ProcessorInfo *info_;
  AstNode* closure_;
  Class* class_;
  ClassProcessorUtils* utils_;
  Function* closure_body_;
  Statement* tmp_stmt_;
  Function* constructor_;
};

};

#endif
