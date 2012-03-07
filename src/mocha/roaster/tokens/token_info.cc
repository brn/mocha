#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mocha/roaster/tokens/token_info.h>
#include <mocha/roaster/ast/ast.h>

using namespace mocha;

TokenInfo::TokenInfo(){};
TokenInfo::TokenInfo(const char* token, int type, int64_t line)
    : type_(type), line_(line) {
  value_.assign(token);
};

TokenInfo& TokenInfo::operator = (const TokenInfo& info) {
  type_ = info.type_;
  line_ = info.line_;
  value_ = info.value_;
  compressed_value_ = info.compressed_value_;
  flags_ = info.flags_;
  return (*this);
}

TokenInfo::~TokenInfo(){}

