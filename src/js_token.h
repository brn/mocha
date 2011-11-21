
#ifndef JsToken_h
#define JsToken_h

namespace mocha{
  
  class JsToken {
  public:
    JsToken ();
    static int getType ( const char* token , bool isOperator = false );
    static const char* GetOperatorFromNumber( int id );
    
  private :
    static char operators_[];
    static char keywordsList_ [][ 20 ];
    static char combineOperators_ [] [ 20 ];
    static int keywordToken_ [];
    static int operatorToken_ [];
    static int operatorsLength_;
    static int keywordsLength_;
    static int combineOperatorsLength_;
  };

}

#endif


