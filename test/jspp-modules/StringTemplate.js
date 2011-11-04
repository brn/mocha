

Class ( "StringTemplate" )
  ( function ( self , privates ) {
    
    var r_replace_prefix = "\\$\\{",
        r_replace_suffix = "\\}";
    
    self.__init__ = StringTemplate_new;
    self.update = StringTemplate_update;
    self.updateLast = StringTemplate_updateLast;
    
    /**
    *@constructor
    *@param {String} str
    */
    function StringTemplate_new ( str ) {
      privates ( this , {
        originalSource : str,
        lastReplace : null
      } )
    }
    
    function StringTemplate_update ( obj ) {
      
      var privateVar = privates ( this ),
          result = privateVar.originalSource,
          reg
      
      for ( var i in obj ) {
        reg = new RegExp ( r_replace_prefix + i + r_replace_suffix , "g" );
        result = result.replace ( reg , obj [ i ] )
      }
      
      privateVar.lastReplace = obj;
      return result;
      
    }
    
    function StringTemplate_updateLast ( obj ) {
      
      var privateVar = privates ( this ),
          result = privateVar.originalSource,
          reg
      
      for ( var i in privateVar.lastReplace ) {
        if ( !( i in obj ) ) {
          reg = new RegExp ( r_replace_prefix + i + r_replace_suffix , "g" );
          result = result.replace ( reg , privateVar.lastReplace [ i ] )
        }
      }
      
      for ( var j in obj ) {
        privateVar.lastReplace [ j ] = obj [ j ]
        reg = new RegExp ( r_replace_prefix + j + r_replace_suffix , "g" );
        result = result.replace ( reg , obj [ j ] )
      }
      
      return result;
      
    }
    
  } )
