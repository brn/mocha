/**
 *@author Taketoshi Aono
 *@fileOverview
 *Implementation of destructuring assignment processor.
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
#ifndef mocha_dsta_processor_h_
#define mocha_dsta_processor_h_
#include <mocha/roaster/ast/ast_foward_decl.h>
#include <mocha/roaster/ast/translator/processors/processor.h>
namespace mocha {
class ProcessorInfo;
/**
 * @class
 * Transform the Destructuring Assignment to
 * the Conditional Expression or simple property accessor.
 */
class DstaProcessor : public Processor{
 public :
  enum {
    kSuccess,
    kError
  };
  DstaProcessor(AstNode* ast_node, ProcessorInfo* info)
      : Processor(), ast_node_(ast_node), info_(info){}
  ~DstaProcessor(){}
  /**
   * @param {AstNode*} ast_node
   * @param {ProcessorInfo*} info
   * @returns {int}
   * Begin process.
   * NO THROW
   */
  Literal* ProcessNode();

  /**
   * @param {Statement*} stmt
   * @param {ProcessorInfo*} info
   * @returns {NodeList*}
   * Create a variable statement from the parse results of destructuring assignment.
   * NO THROW
   */
  static NodeList* CreateDstaExtractedVarStmt(Statement* stmt, ProcessorInfo* info);

  /**
   * @param {Statement*} stmt
   * @param {ProcessorInfo*} info
   * @returns {NodeList*}
   * Create a Assignment Expression from the parse results of destructuring assignment.
   */
  static NodeList* CreateDstaExtractedAssignment(Statement* stmt, ProcessorInfo* info);

  /**
   * @param {Statement*} stmt
   * @param {ProcessorInfo*} info
   * @returns {VariableStmt*}
   * Create tmporary variable declaration list.
   */
  static VariableStmt* CreateTmpVarDecl(Statement*, ProcessorInfo* info);

 private :
  void ProcessMember(Literal* ast_node, DstaTree* tree);
  DstaTree* ProcessPropertyMember(Literal* value, DstaTree* tree, int depth);
  void ProcessObject(ObjectLikeLiteral* ast_node, DstaTree* tree, int depth);
  void ArrayHelper(ArrayLikeLiteral* ast_node, DstaTree* tree, int index, Literal* symbol, bool is_rest);
  DstaTree* ProcessArrayElement(ArrayLikeLiteral* ast_node, AstNode* element, DstaTree* tree, int depth, int index);
  void ProcessArray(ArrayLikeLiteral* ast_node, DstaTree* tree, int depth);
  static AstNode* CreateConditional(AstNode* last_exp, AstNode* first, ProcessorInfo *info, bool is_assign);
  static NodeList* IterateTree(NodeList* result, AstNode* first, ProcessorInfo *info, bool is_assign);
  static AstNode* CreateSimpleAccessor(AstNode* first, TranslatorData* info, bool is_assign);
  static NodeList* CreateDstaExtractedNode(Statement* stmt, ProcessorInfo* info, bool is_assign);
  AstNode* node() { return ast_node_; }
  ProcessorInfo* info() { return info_; }
  AstNode* ast_node_;
  ProcessorInfo* info_;
};

}

#endif
