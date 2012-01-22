#ifndef mocha_parser_env_h_
#define mocha_parser_env_h_

namespace mocha {
class ParserEnv {
 public :
  ParserEnv( Scope* scope );
  ~ParserEnv(){}
  void DirectivePrologue() { has_directive_prologue_ = true; }
  bool HasDirectivePrologue() { return has_directive_prologue_; }
 private :
  bool has_directive_prologue_;
};
}

#endif
