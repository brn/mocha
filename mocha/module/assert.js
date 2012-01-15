@version( debug ) {
  import {global} from "global"
  module {
    var __assert;
    if ( global.console && typeof global.console.assert === "function" ) {
      __assert = global.console.assert.bind( global.console );
    } else if ( global.console && global.console.assert ) {
      __assert = ( expressionResult , expressionString )->{
        console.assert( condExpression.ToValue() );
        console.log( line );
      }
    } else {
      __assert = ( expressionResult , expressionString )->{
        if ( !condExpression ) {
          Runtime.throwException( condExpression.ToValue() );
        }
      };
    }
    export __assert;
  }

  @namespace std{
    @def( __debug ) assert( condExpression ) {
      var message = condExpression.toString() + " at " + condExpression.getLineNumber(),
          result = ast.createCallExp( ast.callType.DOT ,
                                      ast.createCallExp( ast.callType.ARRAY,
                                                         ast.createValueNode( ast.valueType.IDENTIFIER,
                                                                              "_mochaGlobalExport",
                                                                              ast.createEmpty() ),
                                                         ast.createValueNode( env.getFileName() ) ),
                                      ast.createCallExp( ast.callType.NORMAL , 
                                                         ast.createValueNode( ast.valueType.IDENTIFIER,
                                                                              "__assert",
                                                                              ast.createEmpty() ),
                                                         condExpression , message )
                                    );
      return result;
    }
  }
}

