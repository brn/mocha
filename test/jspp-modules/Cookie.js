
/**
 *@fileOverview
 * Cookie module.
 * This file exports Class::Cookie.
 * @example
 * "*" is emittable.
 * Cookie.add ({
 *   name : {
 *     expires : 7,
 *     type : "json",
 *     value : {
 *       test : 1
 *     },
 *     *path : "/",
 *     *domain : "example.com"
 *   } 
 * })
 */

Class ( "Cookie" )( 
  function ( self , privates  ) {
    
    //Is cookie enable or not.
    var cookie_enable = navigator.cookieEnabled,
        //Class::Cookie acceptable type field.
        type_table = {
          /**
          *@param { Json }
          *@retuns { String }
          *Convert Json to String.
          */
          json : function( obj ){
            return JSON.stringify( obj )
          },
          /**
          *@param { Array }
          *@retuns { String }
          *Convert Array to String.
          */
          array : function( obj ){
            return "[" + obj.join( "," ) + "]"
          }
        }
    
    /**
    *@memberOf Cookie
    *@oaram { int }
    *@returns { String }
    *Get expires from int.
    */
    function getExpires( period ){
      var nowtime     = new Date().getTime(),
          clear_time  = new Date( nowtime + ( 60 * 60 * 24 * 1000 * period ) ),
          expires     = clear_time.toGMTString()
      return expires;
    }
    
    /**
    *@memberOf Cookie
    *@static
    *@oaram { Object ({
    * name : {
    *  opt expires : ...
    *  opt path : ...
    *  opt domain : ...
    *  opt type : json|array|none
    *  value : ANY
    * }
    *}) }
    *Add data to cookie
    */
    self.__static__.add = function add ( obj ){
      if( !cookie_enable ){
        return false
      }
      
      for( var name in obj ){
        
        var prop = obj[ name ]
        
        document.cookie = ( 
          encodeURIComponent( name ) + "=" + encodeURIComponent( ( ( prop.type && ( prop.type = type_table[ prop.type.toLowerCase() ] ) )? prop.type( prop.value ) : prop.value ) ) + 
          (
            ( prop.path )? ";path=" + prop.path : 
              ( obj.path )? ";path=" + obj.path : ";" + 
            ( prop.expires )? ";expires=" + getExpires( prop.expires ) : 
              ( obj.expires )? ";expires=" + getExpires( obj.expires ) : ";" +
            ( prop.domain )? ";domain=" + prop.domain : 
              ( obj.domain )? ";domain=" + obj.domain : ";"
          )
        )
      }
    }
    
    /**
    *@memberOf Cookie
    *@static
    *@param { String ( Key of data. ) , String ( Type String. json|array ) }
    */
    self.__static__.get = function get ( key , type ){
      
      if( !cookie_enable ){
        return "";
      }
      
      var ck = decodeURIComponent( unescape( document.cookie ) ),
          offset = ck.indexOf( key + '='),
          ret = "",
          isret,
          end;
      type = ( type )? type.toLowerCase() : null;
      if(offset !== -1){
        offset += key.length + 1;
        end     = ck.indexOf(';',offset);
        if(end === -1){
          end = ck.length;
        }
        ret = ck.substring( offset , end );
      }
      
      isret = ret.length > 0
      
      if( !type ){
        return ( isret )? ret : ""
      }else if( type === "array" ){
        if( isret ){
          if( ret.indexOf( "[" ) === 0 ){
            ret.slice( 1 , ckstr.length - 1 )
          }
          return ret.split( "," )
        }
      }else if( type === "json" ){
        return ( isret )? JSON.parse( ret ) : "";
      }else if( type === "object" ){
        return ( isret )? Function ( "return " + ret + ";" )() : "";
      }
    }
    
    self.__static__.getExpires = getExpires
    
  }
)
