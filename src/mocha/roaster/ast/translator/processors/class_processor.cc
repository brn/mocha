#include <sstream>
#include <mocha/roaster/ast/translator/processors/class_processor.h>
#include <mocha/roaster/ast/translator/processors/processor_info.h>
#include <mocha/roaster/ast/translator/processors/dsta_processor.h>
#include <mocha/roaster/ast/translator/processors/trait_processor.h>
#include <mocha/roaster/ast/translator/translator_data/translator_data.h>
#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/ast/builder/ast_builder.h>
#include <mocha/roaster/nexc/tokens/js_token.h>
#include <mocha/roaster/nexc/tokens/token_info.h>
#include <mocha/roaster/nexc/tokens/symbol_list.h>

#define TOKEN yy::ParserImplementation::token

namespace mocha {


class ClassProcessorUtils : public Processor{
 public :

  ClassProcessorUtils(ClassProcessor* processor)
      : Processor(), processor_(processor) {}

  ~ClassProcessorUtils(){}
                                
  inline CallExp* CreateHiddenMember(NodeList* args, int64_t line) {
    Literal* unenum = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kCreateUnenumProp),
                                                Token::JS_IDENTIFIER, line, Literal::kProperty);
    CallExp* mod = builder()->CreateRuntimeMod(unenum, line);
    return builder()->CreateNormalAccessor(mod, args, line);
  }

  inline Literal* CreateThisNode(int64_t line) {
    return builder()->CreateNameNode(SymbolList::symbol(SymbolList::kThis),
                                     Token::JS_IDENTIFIER, line, Literal::kIdentifier);
  }


  inline CallExp* CreatePrivateFieldAccessor(AstNode* name) {
    Literal* private_field = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kGetPrivateRecord),
                                                       Token::JS_IDENTIFIER, name->line_number(), Literal::kProperty);
    Literal* this_node = CreateThisNode(name->line_number());
    NodeList* args = builder()->CreateNodeList(1, this_node);
    CallExp* call = builder()->CreateNormalAccessor(private_field, args, name->line_number());
    return builder()->CreateRuntimeMod(call, name->line_number());
  }

  inline CallExp* CreateInitializer(int64_t line) {
    Literal* this_sym = CreateThisNode(line);
    Literal* init = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kInitializeClass),
                                              Token::JS_IDENTIFIER, line, Literal::kProperty);
    Literal* private_holder = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kPrivateHolder),
                                                        Token::JS_IDENTIFIER, line, Literal::kIdentifier);
    Literal* constructor = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kConstructor),
                                                     Token::JS_IDENTIFIER, line, Literal::kIdentifier);
    Literal* arguments = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kArguments),
                                                   Token::JS_IDENTIFIER, line, Literal::kIdentifier);
    Literal* name = builder()->CreateNameNode(processor_->GetName(),
                                              Token::JS_IDENTIFIER, line, Literal::kIdentifier);
    std::stringstream st;
    st << '\'' << processor_->GetName() << '\'';
    std::stringstream line_st;
    line_st << line;
    Literal* name_string = builder()->CreateNameNode(st,
                                                     Token::JS_STRING_LITERAL, line, Literal::kString);
    Literal* line_string = builder()->CreateNameNode(line_st,
                                                     Token::JS_STRING_LITERAL, line, Literal::kString);
    NodeList* args = builder()->CreateNodeList(7, this_sym, name, private_holder, constructor, arguments, name_string, line_string);
    CallExp* runtime_call = builder()->CreateRuntimeMod(init, line);
    CallExp* normal = builder()->CreateNormalAccessor(runtime_call, args, line);
    return normal;
  }

  inline ExpressionStmt* SetMark(Function* fn) {
    std::stringstream str_st;
    str_st << "\"" << SymbolList::symbol(SymbolList::kClassMark) << "\"";
    Literal* mark = builder()->CreateNameNode(str_st.str().c_str(), Token::JS_STRING_LITERAL,
                                              fn->line_number(), Literal::kProperty);
    Literal* constructor = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kConstructor),
                                                     Token::JS_IDENTIFIER, fn->line_number(), Literal::kIdentifier);
    Literal* one = builder()->CreateNameNode("1", Token::JS_NUMERIC_LITERAL, fn->line_number(),
                                             Literal::kNumeric);
    NodeList* args = builder()->CreateNodeList(3, constructor, mark, one);
    CallExp* exp = CreateHiddenMember(args, fn->line_number());
    return builder()->CreateExpStmt(exp, fn->line_number());
  }

                                
  inline AstNode* CreateHiddenConstructor (const char* name, int64_t line) {
    Literal* name_sym = builder()->CreateNameNode(name, Token::JS_IDENTIFIER, line, Literal::kIdentifier);
    CallExp* prototype = builder()->CreatePrototypeNode(name_sym, line);
    Literal* constructor_sym = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kConstructor),
                                                         Token::JS_IDENTIFIER, line, Literal::kIdentifier);
    std::string constructor_string_expression = "\"";
    constructor_string_expression += SymbolList::symbol(SymbolList::kConstructor);
    constructor_string_expression += "\"";
    Literal* constructor_string = builder()->CreateNameNode(constructor_string_expression.c_str(),
                                                            Token::JS_IDENTIFIER, line, Literal::kProperty);
    NodeList* args = builder()->CreateNodeList(3, prototype, constructor_string, constructor_sym);
    AstNode* hidden_constructor = CreateHiddenMember(args, line);
    return builder()->CreateExpStmt(hidden_constructor, line);
  }
                                

  void CreateMixinStmt(const char* name, AstNode* mixin_list, AstNode* body) {
    Literal* mixin = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kClassMixin),
                                               Token::JS_IDENTIFIER, body->last_child()->line_number(), Literal::kProperty);
    NodeIterator iterator = mixin_list->ChildNodes();
    while (iterator.HasNext()) {
      AstNode* item = iterator.Next();
      AstNode* rename = item->first_child();
      AstNode* remove = rename->next_sibling();
      AstNode* name_node = remove->next_sibling();
      Literal* name_sym = builder()->CreateNameNode(name, Token::JS_IDENTIFIER, body->last_child()->line_number(), Literal::kIdentifier);
      Literal* private_holder = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kPrivateHolder),
                                                          Token::JS_IDENTIFIER, body->last_child()->line_number(), Literal::kIdentifier);
                                                                
      NodeList* args = builder()->CreateNodeList(5, name_sym, private_holder, name_node->Clone(pool()), rename->Clone(pool()), remove->Clone(pool()));
      CallExp* runtime_accessor = builder()->CreateRuntimeMod(mixin, rename->line_number());
      CallExp* runtime_call = builder()->CreateNormalAccessor(runtime_accessor, args, rename->line_number());
      ExpressionStmt* stmt = builder()->CreateExpStmt(runtime_call, rename->line_number());
      body->AddChild(stmt);
    }
  }

  void CreateRequirementsCheck(const char* name, const char* filename, AstNode* mixin_list, AstNode* body) {
    Literal* check_requirements = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kCheckRequirements),
                                                            Token::JS_IDENTIFIER, mixin_list->line_number(), Literal::kProperty);
    NodeIterator iterator = mixin_list->ChildNodes();
    ArrayLikeLiteral* array = new(pool()) ArrayLikeLiteral(body->line_number());
    int64_t line = 0;
    while (iterator.HasNext()) {
      AstNode* item = iterator.Next();
      AstNode* rename = item->first_child();
      AstNode* remove = rename->next_sibling();
      AstNode* name_node = remove->next_sibling();
      line = name_node->line_number();
      array->set_element(name_node);
    }
    Literal* name_sym = builder()->CreateNameNode(name, Token::JS_IDENTIFIER, mixin_list->line_number(), Literal::kIdentifier);
    Literal* filename_node = builder()->CreateNameNode(filename, Token::JS_STRING_LITERAL, mixin_list->line_number(), Literal::kString);
    Literal* private_field = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kPrivateHolder),
                                                       Token::JS_IDENTIFIER, mixin_list->line_number(), Literal::kIdentifier);
    std::stringstream st;
    st << line;
    Literal* line_num = builder()->CreateNameNode(st, Token::JS_NUMERIC_LITERAL, mixin_list->line_number(), Literal::kNumeric);
    NodeList* args = builder()->CreateNodeList(5, name_sym, private_field, array, filename_node, line_num);
    CallExp* runtime_accessor = builder()->CreateRuntimeMod(check_requirements, body->line_number());
    CallExp* runtime_call = builder()->CreateNormalAccessor(runtime_accessor, args, body->line_number());
    ExpressionStmt* stmt = builder()->CreateExpStmt(runtime_call, body->line_number());
    body->AddChild(stmt);
  }


  inline void Finish(const char* name, Class* class_, AstNode* closure_, ProcessorInfo* info) {
    if (class_->parent_node()->node_type() == AstNode::kExpressionStmt ||
         class_->inner()) {
      TokenInfo* info = new(pool()) TokenInfo(name, Token::JS_IDENTIFIER, class_->line_number());
      Literal* vars = builder()->CreateVarInitiliser(info, closure_->first_child(), class_->line_number());
      VariableStmt* stmt = builder()->CreateVarStmt(builder()->CreateVarDeclList(class_->line_number(), 1, vars), class_->line_number());
      if (!class_->inner()) {
        class_->parent_node()->parent_node()->ReplaceChild(class_->parent_node(), stmt);
      } else {
        class_->AddChild(stmt);
      }
    } else {
      if (class_->parent_node()->node_type() == AstNode::kExportStmt) {
        Literal* name_node = builder()->CreateNameNode(name, Token::JS_IDENTIFIER, class_->line_number(), Literal::kProperty);
        Literal* local_export = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kLocalExport),
                                                          Token::JS_IDENTIFIER, class_->line_number(), Literal::kIdentifier);
        CallExp* dot_accessor = builder()->CreateDotAccessor(local_export, name_node, class_->line_number());
        AssignmentExp* assign = builder()->CreateAssignment('=', dot_accessor, closure_->first_child(), class_->line_number());
        Literal* var_node = builder()->CreateVarInitiliser(name_node->Clone(pool())->CastToLiteral()->value(), assign, class_->line_number());
        VariableDeclarationList* list = builder()->CreateVarDeclList(class_->line_number(), 1, var_node);
        VariableStmt* var_stmt = builder()->CreateVarStmt(list, class_->line_number());
        class_->parent_node()->parent_node()->ReplaceChild(class_->parent_node(), var_stmt);
      } else {
        class_->AddChild(closure_->first_child());
      }
    }
  }


  inline VariableStmt* CreatePrivateHolder(Class* class_, ProcessorInfo* info) {
    Function* fn =
        builder()->CreateFunctionDecl(new(pool()) Empty(), new(pool()) Empty,
                                      new(pool()) Empty, class_->line_number());
    Literal* private_holder_name = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kPrivateHolder),
                                                             Token::JS_IDENTIFIER, class_->line_number(), Literal::kIdentifier);
    Literal* value = builder()->CreateVarInitiliser(private_holder_name->value(), fn, class_->line_number());
    VariableDeclarationList* list = builder()->CreateVarDeclList(class_->line_number(), 1, value);
    VariableStmt* stmt = builder()->CreateVarStmt(list, class_->line_number());
    return stmt;
  }

                                
  inline AstNode* GetSafeValue(Literal* value) {
    AstNode* lhs = value->first_child();
    return (lhs)? lhs : builder()->CreateNameNode(SymbolList::symbol(SymbolList::kUndefined),
                                                    Token::JS_IDENTIFIER, value->line_number(), Literal::kIdentifier);
  }



  inline ExpressionStmt* InstancePrivate(Literal* value) {
    CallExp* private_accessor = CreatePrivateFieldAccessor(value);
    CallExp* dot_accessor = builder()->CreateDotAccessor(private_accessor, value, value->line_number());
    return builder()->CreateExpStmt(builder()->CreateAssignment('=', dot_accessor, GetSafeValue(value), value->line_number()),
                                    value->line_number());
  }



  inline ExpressionStmt* InstancePublic(Literal* value) {
    Literal* this_node = CreateThisNode(value->line_number());
    CallExp* dot_accessor = builder()->CreateDotAccessor(this_node, value, value->line_number());
    return builder()->CreateExpStmt(builder()->CreateAssignment('=', dot_accessor, GetSafeValue(value), value->line_number()),
                                    value->line_number());
  }



  inline ExpressionStmt* ConstantInstancePrivate(Literal* value) {
    CallExp* constant_accessor = builder()->CreateConstantProp(CreatePrivateFieldAccessor(value),
                                                               value, GetSafeValue(value), value->line_number());
    return builder()->CreateExpStmt(constant_accessor, value->line_number());
  }



  inline ExpressionStmt* ConstantInstancePublic(Literal* value) {
    Literal* this_node = CreateThisNode(value->line_number());
    CallExp* dot_accessor = builder()->CreateDotAccessor(this_node, value, value->line_number());
    CallExp* constant_accessor = builder()->CreateConstantProp(dot_accessor,
                                                               value, GetSafeValue(value), value->line_number());
    return builder()->CreateExpStmt(constant_accessor, value->line_number());
  }



  inline ExpressionStmt* PrototypePrivate(AstNode* name_node, AstNode* val) {
    Literal* name = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kPrivateHolder),
                                              Token::JS_IDENTIFIER, val->line_number(), Literal::kIdentifier);
    CallExp* prototype_accessor = builder()->CreatePrototypeNode(name, val->line_number());
    CallExp* name_accessor = builder()->CreateDotAccessor(prototype_accessor, name_node, val->line_number());
    return builder()->CreateExpStmt(builder()->CreateAssignment('=', name_accessor, val, val->line_number()),
                                    val->line_number());
  }



  inline ExpressionStmt* PrototypePublic(const char* class_name, AstNode* name_node, AstNode* val) {
    Literal* name = builder()->CreateNameNode(class_name,
                                              Token::JS_IDENTIFIER, val->line_number(), Literal::kIdentifier);
    CallExp* prototype_accessor = builder()->CreatePrototypeNode(name, val->line_number());
    CallExp* name_accessor = builder()->CreateDotAccessor(prototype_accessor, name_node, val->line_number());
    return builder()->CreateExpStmt(builder()->CreateAssignment('=', name_accessor, val, val->line_number()),
                                    val->line_number());
  }



  inline ExpressionStmt* ConstantPrototypePrivate(AstNode* name_node, AstNode* val) {
    Literal* name = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kPrivateHolder),
                                              Token::JS_IDENTIFIER, val->line_number(), Literal::kIdentifier);
    CallExp* prototype_accessor = builder()->CreatePrototypeNode(name, val->line_number());
    CallExp* constant_accessor = builder()->CreateConstantProp(prototype_accessor,
                                                               name_node, val, val->line_number());
    return builder()->CreateExpStmt(constant_accessor, val->line_number());
  }



  inline ExpressionStmt* ConstantPrototypePublic(const char* class_name, AstNode* name_node, AstNode* val) {
    Literal* name = builder()->CreateNameNode(class_name,
                                              Token::JS_IDENTIFIER, val->line_number(), Literal::kIdentifier);
    CallExp* prototype_accessor = builder()->CreatePrototypeNode(name, val->line_number());
    CallExp* constant_accessor = builder()->CreateConstantProp(prototype_accessor,
                                                               name_node, val, val->line_number());
    return builder()->CreateExpStmt(constant_accessor, val->line_number());
  }



  inline ExpressionStmt* PublicStatic(const char* class_name, AstNode* name_node, AstNode* val) {
    Literal* name = builder()->CreateNameNode(class_name,
                                              Token::JS_IDENTIFIER, val->line_number(), Literal::kIdentifier);
    CallExp* dot_accessor = builder()->CreateDotAccessor(name, name_node, val->line_number());
    return builder()->CreateExpStmt(builder()->CreateAssignment('=', dot_accessor, val, val->line_number()),
                                    val->line_number());
  }



  inline ExpressionStmt* PublicConstantStatic(const char* class_name, AstNode* name_node, AstNode* val) {
    Literal* name = builder()->CreateNameNode(class_name,
                                              Token::JS_IDENTIFIER, val->line_number(), Literal::kIdentifier);
    CallExp* constant_accessor = builder()->CreateConstantProp(name, name_node, val, val->line_number());
    return builder()->CreateExpStmt(constant_accessor, val->line_number());
  }


  inline ExpressionStmt* PrivateStatic(AstNode* name_node, AstNode* val) {
    Literal* name = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kPrivateHolder),
                                              Token::JS_IDENTIFIER, val->line_number(), Literal::kIdentifier);
    CallExp* dot_accessor = builder()->CreateDotAccessor(name, name_node, val->line_number());
    return builder()->CreateExpStmt(builder()->CreateAssignment('=', dot_accessor, val, val->line_number()),
                                    val->line_number());
  }

  inline ExpressionStmt* PrivateConstantStatic(AstNode* name_node, AstNode* val) {
    Literal* name = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kPrivateHolder),
                                              Token::JS_IDENTIFIER, val->line_number(), Literal::kIdentifier);
    CallExp* constant_accessor = builder()->CreateConstantProp(name, name_node, val, val->line_number());
    return builder()->CreateExpStmt(constant_accessor, val->line_number());
  }



#define INSTANCE_DSTA(accessor)                                 \
  inline void Instance##accessor##Dsta(const char* class_name, \
                                        Function* closure_body, \
                                        Literal* val,           \
                                        bool is_const) {       \
    if (is_const) {                                           \
      ExpressionStmt* stmt = ConstantInstance##accessor(val); \
      closure_body->AddChild(stmt);                           \
    } else {                                                    \
      ExpressionStmt* stmt = Instance##accessor(val);         \
      closure_body->AddChild(stmt);                           \
    }                                                           \
  }
  INSTANCE_DSTA(Public);
  INSTANCE_DSTA(Private);


#undef INSTANCE_DSTA

#define PROTOTYPE_DSTA(accessor,args)                                   \
  inline void Prototype##accessor##Dsta(const char* class_name,        \
                                         Function* closure_body,        \
                                         Literal* val,                  \
                                         bool is_const) {              \
    if (is_const) {                                                   \
      ExpressionStmt* stmt = ConstantPrototype##accessor(args);       \
      closure_body->AddChild(stmt);                                   \
    } else {                                                            \
      ExpressionStmt* stmt = Prototype##accessor(args);               \
      closure_body->AddChild(stmt);                                   \
    }                                                                   \
  }
#define PUBLIC_ARGS class_name, val, val->first_child()
#define PRIVATE_ARGS val, val->first_child()
  PROTOTYPE_DSTA(Public,PUBLIC_ARGS);
  PROTOTYPE_DSTA(Private,PRIVATE_ARGS);
#undef PROTOTYPE_DSTA
#undef PUBLIC_ARGS
#undef PRIVATE_ARGS


#define STATIC(accessor,args)                                   \
  inline void accessor##StaticDsta(const char* class_name,     \
                                    Function* closure_body,     \
                                    Literal* exp,               \
                                    bool is_const) {           \
    if (is_const) {                                           \
      ExpressionStmt* stmt = accessor##ConstantStatic(args);  \
      closure_body->AddChild(stmt);                           \
    } else {                                                    \
      ExpressionStmt* stmt = accessor##Static(args);          \
      closure_body->AddChild(stmt);                           \
    }                                                           \
  }
                                
#define PUBLIC_ARGS class_name, exp, exp->first_child()
#define PRIVATE_ARGS exp, exp->first_child()
  STATIC(Private, PRIVATE_ARGS);
  STATIC(Public, PUBLIC_ARGS);
#undef PUBLIC_ARGS
#undef PRIVATE_ARGS
#undef STATIC
                                
 private :
  ClassProcessor* processor_;
};


ClassProcessor::ClassProcessor(ProcessorInfo* info, Class* ast_node, Statement* tmp_stmt)
    : Processor(), info_(info), class_(ast_node), utils_(new ClassProcessorUtils(this)), tmp_stmt_(tmp_stmt){
  Initialize();
}


ClassProcessor::~ClassProcessor() {
  delete utils_;
}


void ClassProcessor::Initialize() {
  closure_body_ =
      builder()->CreateFunctionDecl(new(pool()) Empty, new(pool()) Empty,
                                    new(pool()) StatementList, class_->line_number());
  closure_ = builder()->CreateAnonymousFnCall(closure_body_, new(pool()) Empty, class_->line_number());
  SetName(class_->name());
}

void ClassProcessor::ProcessNode() {
  AstNode* body = class_->body();
  Function* base_constructor = CreateBaseConstructor();
  closure_body_->InsertBefore(utils_->CreatePrivateHolder(class_, info_));
  ExpressionStmt *init = builder()->CreateExpStmt(utils_->CreateInitializer(class_->line_number()), class_->line_number());
  base_constructor->AddChild(init);
  closure_body_->AddChild(base_constructor);
  ProcessExtends(class_->expandar());
  ProcessBody(body);
  AstNode* hidden = utils_->CreateHiddenConstructor(name_.c_str(), class_->line_number());
  closure_body_->AddChild(hidden);
  ReturnStmt* ret = builder()->CreateReturnStmt(base_constructor->name()->Clone(pool()), class_->line_number());
  closure_body_->AddChild(ret);
  utils_->Finish(name_.c_str(), class_, closure_, info_);
}

inline void ClassProcessor::SetName(AstNode* name_node) {
  if (!name_node->IsEmpty()) {
    TokenInfo *info = name_node->CastToLiteral()->value();
    name_ = info->token();
  } else {
    name_ = builder()->CreateTmpRef(info_->translator_data()->tmp_index());
  }
}

inline Function* ClassProcessor::CreateBaseConstructor() {
  Literal* name = builder()->CreateNameNode(name_.c_str(), Token::JS_IDENTIFIER, class_->line_number(), Literal::kIdentifier);
  return builder()->CreateFunctionDecl(name, new(pool()) Empty, new(pool()) Empty, class_->line_number());
}

inline void ClassProcessor::ProcessExtends(AstNode* node) {
  if (!node->IsEmpty()) {
    ClassExpandar* expandar = reinterpret_cast<ClassExpandar*>(node);
    const char* extend_fn = (expandar->attribute() == ClassExpandar::kExtends)?
        SymbolList::symbol(SymbolList::kExtendClass) :
        SymbolList::symbol(SymbolList::kExtendPrototype);
    Literal* tmp_node = builder()->CreateTmpNode(info_->translator_data()->tmp_index(), expandar->line_number());
    Literal* tmp_init = builder()->CreateVarInitiliser(tmp_node->value(), node->first_child(), expandar->line_number());
    VariableDeclarationList* decl_list = builder()->CreateVarDeclList(expandar->line_number(), 1, tmp_init);
    VariableStmt* var_stmt = builder()->CreateVarStmt(decl_list, expandar->line_number());
    closure_body_->AddChild(var_stmt);
                                                                
    Literal* extend = builder()->CreateNameNode(extend_fn, Token::JS_IDENTIFIER,
                                                class_->line_number(), Literal::kProperty);
    CallExp* runtime_prop = builder()->CreateRuntimeMod(extend, expandar->line_number());
    NodeList* arg = new(pool()) NodeList;
    Literal* class_name = builder()->CreateNameNode(name_.c_str(), Token::JS_IDENTIFIER,
                                                    class_->line_number(), Literal::kIdentifier);
    arg->AddChild(class_name);
    arg->AddChild(tmp_node->Clone(pool()));
    CallExp* normal_fn_call = builder()->CreateNormalAccessor(runtime_prop, arg, expandar->line_number());
    ExpressionStmt* stmt = builder()->CreateExpStmt(normal_fn_call, expandar->line_number());
    closure_body_->AddChild(stmt);
    Literal* super_obj = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kSuper),
                                                   Token::JS_IDENTIFIER, node->line_number(), Literal::kIdentifier);
    Literal* create_super = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kGetSuper),
                                                      Token::JS_IDENTIFIER, node->line_number(), Literal::kProperty);
    NodeList* super_args = builder()->CreateNodeList(1, tmp_node->Clone(pool()));
    CallExp* create_super_call = builder()->CreateNormalAccessor(create_super, super_args, expandar->line_number());
    CallExp* runtime_exp = builder()->CreateRuntimeMod(create_super_call, expandar->line_number());
    Literal* var_init = builder()->CreateVarInitiliser(super_obj->value(), runtime_exp, expandar->line_number());
    decl_list = builder()->CreateVarDeclList(expandar->line_number(), 1, var_init);
    VariableStmt* runtime_super_stmt = builder()->CreateVarStmt(decl_list, expandar->line_number());
    closure_body_->AddChild(runtime_super_stmt);
  }
}


inline void ClassProcessor::ProcessBody(AstNode* body) {
  if (!body->IsEmpty()) {
    ProcessMember(reinterpret_cast<ClassProperties*>(body));
  } else {
    CreateEmptyConstructor();
  }
}



inline void ClassProcessor::ProcessMember(ClassProperties* body) {
  NodeList* public_list = body->public_member();
  NodeList* private_list = body->private_member();
  NodeList* prototype_list = body->prototype_member();
  NodeList* public_static_list = body->public_static_member();
  NodeList* private_static_list = body->private_static_member();
  NodeList* mixin = body->mixin_member();
  AstNode* constructor_decl = body->constructor();

  if (constructor_decl) {
    Function* constructor = constructor_decl->first_child()->CastToExpression()->CastToFunction();
    constructor_ = constructor;
    ProcessConstructor(constructor);
  } else {
    CreateEmptyConstructor();
  }

  IterateMember(public_list, true, false, false);
  IterateMember(private_list, true, true, false);
  IterateMember(prototype_list, true, true, false);
  IterateMember(public_static_list, false, false, false);
  IterateMember(private_static_list, false, true, false);
  if (mixin->child_length() > 0) {
    AstNode* mixin_list = TraitProcessor::ProcessMixin(mixin, info_, mixin->line_number());
    utils_->CreateMixinStmt(name_.c_str(), mixin_list, closure_body_);
    utils_->CreateRequirementsCheck(name_.c_str(), info_->translator_data()->relative_path(), mixin_list, closure_body_);
  }
}



inline void ClassProcessor::ProcessConstructor(Function* constructor) {
  IVisitor* visitor = info_->visitor();
  closure_body_->AddChild(constructor);
  Function *backup = closure_body_;
  NodeIterator iterator = constructor->ChildNodes();
  closure_body_ = constructor;
  while (iterator.HasNext()) {
    AstNode* item = iterator.Next();
    if (item->node_type() == AstNode::kClassMember) {
      ClassMember* member = reinterpret_cast<ClassMember*>(item);
      if (member->attribute() == ClassMember::kPrivate) {
        ProcessEachMember(member->first_child(), false, true, true);
      } else {
        ProcessEachMember(member->first_child(), false, false, true);
      }
    }
  }
  constructor->Accept(visitor);
  closure_body_ = backup;
  closure_body_->AddChild(utils_->SetMark(constructor));
}


inline void ClassProcessor::CreateEmptyConstructor() {
  Literal* constructor = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kConstructor),
                                                   Token::JS_IDENTIFIER, class_->line_number(), Literal::kIdentifier);
  Function* fn =
      builder()->CreateFunctionDecl(constructor, new(pool()) Empty,
                                    new(pool()) Empty, class_->line_number());
  closure_body_->AddChild(fn);
  closure_body_->AddChild(utils_->SetMark(fn));
}

inline void ClassProcessor::IterateMember(AstNode *list, bool is_prototype, bool is_private, bool is_instance) {
  NodeIterator iterator = list->ChildNodes();
  while (iterator.HasNext()) {
    AstNode* member = iterator.Next()->first_child();
    ProcessEachMember(member, is_prototype, is_private, is_instance);
  }
}



void ClassProcessor::ProcessEachMember(AstNode* node, bool is_prototype, bool is_private, bool is_instance) {
  switch (node->node_type()) {

    case AstNode::kFunction : {
      ProcessFunction(reinterpret_cast<Function*>(node), is_prototype, is_private, is_instance);
    }
      break;
                                                                                                
    case AstNode::kVariableDeclarationList : {
      ProcessVariable(node, is_prototype, is_private, is_instance,
                       node->CastToExpression()->CastToVariableDeclarationList()->IsDeclaredAsConst());
    }
      break;

    case AstNode::kClass : {
      Statement* tmp_stmt = new(pool()) Statement;
      info_->translator_data()->set_current_statement(tmp_stmt);
      Class* class_node = reinterpret_cast<Class*>(node);
      class_node->set_inner();
      ClassProcessor cls(info_, class_node, tmp_stmt);
      cls.ProcessNode();
      ProcessVariable(class_node->first_child(), is_prototype, is_private, is_instance, class_node->IsDeclaredAsConst());
    }
  }
}


inline void ClassProcessor::ProcessDsta(AstNode *value,
                                         bool is_const,
                                         DstaCallback callback) {
  Statement* tmp_stmt = new(pool()) Statement;
  info_->translator_data()->set_current_statement(tmp_stmt);
  DstaProcessor processor(value, info_);
  Literal* ret = processor.ProcessNode();
  if (tmp_stmt->IsContainDestructuring()) {
    ret->set_value_type(Literal::kVariable);
    VariableDeclarationList* decl_list = builder()->CreateVarDeclList(value->line_number(), 1, ret);
    VariableStmt* stmt = builder()->CreateVarStmt(decl_list,  value->line_number());
    closure_body_->AddChild(stmt);
    NodeList* list = DstaProcessor::CreateDstaExtractedVarStmt(tmp_stmt, info_);
    NodeIterator iterator = list->ChildNodes();
    while (iterator.HasNext()) {
      Literal* dsta_value = iterator.Next()->CastToLiteral();
      dsta_value->set_value_type(Literal::kIdentifier);
      (utils_->*callback)(name_.c_str(), closure_body_, dsta_value, is_const);
    }
  }
}



inline void ClassProcessor::SimpleVariables(AstNode* node, bool is_const) {
  NodeIterator iterator = node->ChildNodes();
  while (iterator.HasNext()) {
    AstNode* item = iterator.Next();
    Literal* value = item->CastToLiteral();
    ArrayLikeLiteral* array = item->CastToExpression()->CastToArrayLikeLiteral();
    ObjectLikeLiteral* object = item->CastToExpression()->CastToObjectLikeLiteral();
    if (value) {
      value->set_value_type(Literal::kProperty);
      ExpressionStmt* result = 0;
      if (is_const) {
        result = utils_->ConstantPrototypePrivate(value, utils_->GetSafeValue(value));
      } else {
        result = utils_->PrototypePrivate(value, utils_->GetSafeValue(value));
      }
      closure_body_->AddChild(result);
    } else if (array || object) {
      ProcessDsta(item, is_const, &ClassProcessorUtils::PrototypePrivateDsta);
    }
  }
}



inline void ClassProcessor::NoSimpleVariables(AstNode* node,
                                               bool is_prototype,
                                               bool is_private,
                                               bool is_instance,
                                               bool is_const) {

  const char* class_name = name_.c_str();
  NodeIterator iterator = node->ChildNodes();
  while (iterator.HasNext()) {
    AstNode* item = iterator.Next();
    Literal* value = item->CastToLiteral();
    ArrayLikeLiteral* array = item->CastToExpression()->CastToArrayLikeLiteral();
    ObjectLikeLiteral* object = item->CastToExpression()->CastToObjectLikeLiteral();
    if (value) {
      ExpressionStmt* result = 0;
      value->set_value_type(Literal::kProperty);
      AstNode* safe_val = utils_->GetSafeValue(value);
      if (!is_instance && !is_prototype) {
        if (!is_private) {
          if (is_const) {
            result = utils_->PublicConstantStatic(class_name, value, safe_val);
          } else {
            result = utils_->PublicStatic(class_name, value, safe_val);
          }
        } else {
          if (is_const) {
            result = utils_->PrivateConstantStatic(value, safe_val);
          } else {
            result = utils_->PrivateStatic(value, safe_val);
          }
        }
      } else if (is_prototype) {
        if (is_const) {
          result = utils_->ConstantPrototypePublic(class_name, value, safe_val);
        } else {
          result = utils_->PrototypePublic(class_name, value, safe_val);
        }
      } else if (is_private) {
        if (is_const) {
          result = utils_->ConstantInstancePrivate(value);
        } else {
          result = utils_->InstancePrivate(value);
        }
      } else {
        if (is_const) {
          result = utils_->ConstantInstancePublic(value);
        } else {
          result = utils_->InstancePublic(value);
        }
      }
      closure_body_->AddChild(result);
    } else if (array || object) {
      if (!is_instance && !is_prototype) {
        if (!is_private) {
          ProcessDsta(item, is_const, &ClassProcessorUtils::PublicStaticDsta);
        } else {
          ProcessDsta(item, is_const, &ClassProcessorUtils::PrivateStaticDsta);
        }
      } else if (is_prototype) {
        ProcessDsta(item, is_const, &ClassProcessorUtils::PrototypePublicDsta);
      } else if (is_private){
        ProcessDsta(item, is_const, &ClassProcessorUtils::InstancePrivateDsta);
      } else {
        ProcessDsta(item, is_const, &ClassProcessorUtils::InstancePublicDsta);
      }
    }
  }
}


inline void ClassProcessor::ProcessVariable(AstNode* node,
                                             bool is_prototype,
                                             bool is_private,
                                             bool is_instance,
                                             bool is_const) {
  if (is_private && is_prototype) {
    SimpleVariables(node->Clone(pool()), is_const);
  } else {
    NoSimpleVariables(node->Clone(pool()), is_prototype, is_private, is_instance, is_const);
  }
}



inline void ClassProcessor::ProcessFunction(Function* fn, bool is_prototype, bool is_private, bool is_instance) {
  fn = reinterpret_cast<Function*>(fn->Clone(pool()));
  Literal* value = fn->name()->CastToLiteral();
  fn->set_name(new(pool()) Empty);
  const char* class_name = name_.c_str();
  value->set_value_type(Literal::kProperty);
  if (!is_instance && !is_prototype) {
    fn->Accept(info_->visitor());
    ExpressionStmt* stmt;
    if (!is_private) {
      stmt = utils_->PublicStatic(class_name, value, fn);
    } else {
      stmt = utils_->PrivateStatic(value, fn);
    }
    closure_body_->AddChild(stmt);
  } else if (is_prototype) {
    if (is_private) {
      info_->translator_data()->EnterPrivate();
      fn->Accept(info_->visitor());
      info_->translator_data()->EscapePrivate();
      ExpressionStmt* stmt = utils_->PrototypePrivate(value, fn);
      closure_body_->AddChild(stmt);
    } else {
      fn->Accept(info_->visitor());
      ExpressionStmt* stmt = utils_->PrototypePublic(class_name, value, fn);
      closure_body_->AddChild(stmt);
    }
  } else {
    if (is_private) {
      info_->translator_data()->EnterPrivate();
      fn->Accept(info_->visitor());
      info_->translator_data()->EscapePrivate();
      ExpressionStmt* stmt = utils_->PrototypePrivate(value, fn);
      closure_body_->AddChild(stmt);
    } else {
      fn->Accept(info_->visitor());
      ExpressionStmt* stmt = utils_->PrototypePublic(class_name, value, fn);
      closure_body_->AddChild(stmt);
    }
  }
}

}

