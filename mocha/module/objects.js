import {global} from "global";
import {typeOf} from "utility";
module objects {
  
  export functions( obj ) {
    var ret = [],
        iter = -1;
    for ( var i in obj ) {
      if ( typeof obj === "function" ) {
        ret[ ++iter ] = obj[ i ];
      }
    }
  }
  
  export uneval =
    ( global.uneval )?
    ( obj ) -> uneval( obj ) :
    ( obj , isJson ) -> {
      var type = typeOf( obj )
          ret = [];
      
      if ( type === "Window" || type === "Document" || type === "Element" || type === "NodeList" ) {
        return "({})";
      }
      
      if ( type === "Object" ) {
        ret [ ret.length ] = "({";
        var props = [];
        for ( var prop in obj ) {
          type = typeOf( obj[ prop ] );
          
          ret [ ret.length ] = ( isJson )? ( '"' + ( prop.replace ( /^"|"$/g , "" ) ) + '":' ) : prop + ":";

          switch ( type ) {
          case "Object" :
          case "Array" :
            ret [ ret.length ] = uneval( obj[ prop ] );
            break;
          case "Function" :
            if ( !isJson ) {
              ret [ ret.length ] = Function.prototype.toString.call ( obj[ prop ] );
            }else{
              Runtime.throwException( "TypeError JSON.stringify" );
            }
            break;
          case "String" :
            ret[ ret.length ] = '"' + obj[ prop ] + '"';
            break;
          default :
            ret[ ret.length ] = obj[ prop ].toString ();
          }
          ret[ ret.length ] = ",";
        }
        
        ret[ ret.length - 1 ] = "})";
        return ret.join ( "" );
        
      } else if ( type === "Array" ) {
        ret [ ret.length ] = "[";
        for ( var i = 0,len = obj.length; i < len; ++i ) {
          type = typeOf( obj[ i ] );
          
          switch ( type ) {
          case "Object" :
          case "Array" :
            ret [ ret.length ] = uneval ( obj[ prop ] );
            break;
          case "Function" :
            if ( !isJson ) {
              ret [ ret.length ] = Function.prototype.toString.call ( obj[ prop ] );
            }else{
              throw new Error ( "TypeError JSON.stringify" );
            }
            break;
          case "String" :
            ret [ ret.length ] = '"' + obj[ i ] + '"';
            break;
          default :
            ret [ ret.length ] = obj[ prop ].toString ();
          }
          
          ret [ ret.length ] = ",";
          
        }
        
        ret [ ret.length - 1 ] = "]";
        return ret.join ( "" );
        
      }else if ( type === "Function" ) {
        
        if ( isJson ) {
          Runtime.throwException( "TypeError JSON.stringify" );
        }else{
          ret = Function.prototype.toString.call( obj );
        }
        return ret;
      }else{
        return obj.toString ();
      }
    }
  
  export clone( obj ) {
    return Function( ( "return " + uneval( obj ) ) )();
  }
  
}