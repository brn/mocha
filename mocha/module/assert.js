@version( debug ) {
  import {global} from "global"
  if ( !global.console || !global.console.assert ) {
    global.console = {
      assert( expressionResult , expressionString ){
        if ( !condExpression ) {
          Runtime.throwException( condExpression.ToValue() );
        }
      };
    }
  }

  @def std{
    @def( __debug ) assert( condExpression ) {
      if ( condExpression.isStatement() ) {
        throw new Error( "arguments of std.assert expect non statement ast." );
      }
      var str = condExpression.toString(),
          message = str + " at " + condExpression.getLineNumber();
      return "console.assert( " + str + "'" + message + "');";
    }
  }
}

var m = 200;
std.assert!( m === 200 );