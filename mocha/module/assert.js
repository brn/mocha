import {global} from "global"
module {
  @pragma( __debug )
  @pragma( __noassign )
  const assert = ( global.console && typeof global.console.assert === "function" )? 
    global.console.assert.bind( console ) :
    ( global.console && global.console.assert )?
    ( args ) -> console.assert( args ) : 
    ( args ) -> {
      if ( !args ) {
        Runtime.throwException( "assertion failed." );
      }
    }
}