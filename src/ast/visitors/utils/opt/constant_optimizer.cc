#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <utils/int_types.h>
#include <ast/visitors/utils/opt/constant_optimizer.h>
#include <ast/utils/ast_utils.h>
#include <ast/ast.h>
#include <compiler/tokens/js_token.h>
#include <compiler/tokens/symbol_list.h>

namespace mocha {

bool ConstantOptimizer::CheckOperatorAssoc( int left , int right ) {
  if ( left == '%' || left == '/' || left == '*' ) {
    return true;
  } else if ( ( left != '%' && left != '/' && left != '*' ) &&
              ( right == '%' || right == '/' || right == '*' ) ) {
    return false;
  } else if ( ( left != '+' && left != '-' ) &&
              ( right == '+' || right == '-' ) ){
    return false;
  } else {
    return true;
  }
}

bool ConstantOptimizer::IsOptimizable( AstNode* left , AstNode* right , int op ) {
  Literal* lvalue = 0;//init after;
  Literal* rvalue = 0;//init after;
  if ( left->node_type() == AstNode::kLiteral ) {
    lvalue = left->CastToLiteral();
  }
  if ( right->node_type() == AstNode::kLiteral ) {
    rvalue = right->CastToLiteral();
  }
  if ( lvalue && rvalue ) {
    int ltype = lvalue->ValueType();
    int rtype = rvalue->ValueType();
    return ( ( ltype == Literal::kNumeric ||
               ltype == Literal::kString ) &&
             ( rtype == Literal::kNumeric ||
               rtype == Literal::kString ) &&
             ( op == '+' ||
               op == '-' ||
               op == '/' ||
               op == '%' ||
               op == '*' ||
               op == Token::JS_SHIFT_LEFT ||
               op == Token::JS_SHIFT_RIGHT ||
               op == '^' ||
               op == '&' ||
               op == '|' ||
               op == Token::JS_U_SHIFT_RIGHT ) );
  }
  return false;
}

bool IsFloat( const char* val , int op ) {
  bool is_float = false;
  if ( op == Token::JS_SHIFT_LEFT ||
       op == Token::JS_SHIFT_RIGHT ||
       op == '^' ||
       op == '&' ||
       op == '|' ||
       op == Token::JS_U_SHIFT_RIGHT ) {
    return false;
  }
  for ( int i = 0,len = strlen( val ); i < len; i++ ) {
    if ( val[ i ] == '.' ) {
      is_float = true;
    }
  }
  return is_float;
}


AstNode* ConstantOptimizer::Optimize( AstNode* left , AstNode* right , int op ) {
  Literal* lvalue = left->CastToLiteral();
  Literal* rvalue = right->CastToLiteral();
  int ltype = lvalue->ValueType();
  int rtype = rvalue->ValueType();
  if ( ltype == Literal::kNumeric && rtype == Literal::kNumeric ) {
    const char* lstr = lvalue->Symbol()->GetToken();
    const char* rstr = rvalue->Symbol()->GetToken();
    bool is_float = ( IsFloat( lstr , op ) || IsFloat( rstr , op ) );
    double ld = strtod( lstr , NULL );
    double rd = strtod( rstr , NULL );
    char tmp[100];
    double ret = ( op == '+' )? ( ld + rd ) : ( op == '-' )? ( ld - rd ) :
        ( op == '*' )? ( ld * rd ) : ( op == '/' )? ( ld / rd ) :
        ( op == '%' )? fmod( ld , rd ) :
        ( op == Token::JS_SHIFT_LEFT )? static_cast<int64_t>( ld ) << static_cast<int64_t>( rd ) :
        ( op == Token::JS_SHIFT_RIGHT )? static_cast<int64_t>( ld ) >> static_cast<int64_t>( rd ) :
        ( op == '^' )? static_cast<int64_t>( ld ) ^ static_cast<int64_t>( rd ) :
        ( op == '&' )? static_cast<int64_t>( ld ) & static_cast<int64_t>( rd ) :
        ( op == '|' )? static_cast<int64_t>( ld ) | static_cast<int64_t>( rd ) :
        static_cast<uint64_t>( ld ) << static_cast<uint64_t>( rd );
    if ( is_float ) {
      sprintf( tmp , "%f" , ret );
    } else {
      sprintf( tmp , "%ld" , static_cast<long>( ret ) );
    }
    Literal* result = AstUtils::CreateNameNode( tmp , Token::JS_NUMERIC_LITERAL,
                                                  left->Line() , Literal::kNumeric );
    return result;
  } else {
    if ( op == '+' ) {
      std::string ret = lvalue->Symbol()->GetToken();
      if ( ltype == Literal::kString && rtype == Literal::kString ) {
        ret.erase( ret.size() - 1 , ret.size() );
        ret += &( rvalue->Symbol()->GetToken()[ 1 ] );
        if ( ret[ 0 ] != ret[ ret.size() - 1 ] ) {
          ret[ 0 ] = ret[ ret.size() - 1 ];
        }
      } else if ( ltype == Literal::kString ) {
        ret.erase( ret.size() - 1 , ret.size() );
        ret += rvalue->Symbol()->GetToken();
        ret += ret[ 0 ];
      } else {
        const char* str = rvalue->Symbol()->GetToken();
        ret.insert( 0 , 1 , str[ 0 ] );
        ret += &str[ 1 ];
      }
      return AstUtils::CreateNameNode( ret.c_str() , Token::JS_STRING_LITERAL,
                                       left->Line() , Literal::kString );
    } else {
      return AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kNaN ) , Token::JS_NAN,
                                       left->Line() , Literal::kNaN );
    }
  }
}
}
