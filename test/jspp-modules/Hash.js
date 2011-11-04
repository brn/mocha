

Class ( "Hash" )(
  function ( self, privates ) {
    
    self.__init__ = Hash_new;
    self.set = Hash_set;
    self.unset = Hash_unset;
    self.get = Hash_get;
    self.keys = Hash_keys;
    self.forEach = Hash_forEach
    self.map = Hash_map;
    self.has = Hash_has;
    self.toArray = Hash_toArray;
    self.toSource = Hash_toSource;
    self.toObject = Hash_toObject;
    self.diff = Hash_diff;
    self.empty = Hash_empty;
    
    function Hash_new ( obj ) {
      privates ( this , {
        source : obj || {},
        keys : ( obj )? Object.keys ( obj ) : []
      } )
    }
    
    function Hash_set ( name , def ) {
      
      var type = typeOf ( name ),
          privateVar = privates ( this )
      
      if ( type === "String" ) {
        privateVar.source [ name ] = def
        privateVar.keys [ privateVar.keys.length ] = name
      }else if ( type === "Object" ) {
        for ( var i in name ) {
          privateVar.source [ i ] = name [ i ];
          privateVar.keys [ privateVar.keys.length ] = i
        }
      }
      
    }
    
    
    function Hash_unset ( key ) {
      var privateVar = privates ( this ),
          index = privateVar.keys.indexOf ( key );
      if ( index > -1 ) {
        delete privateVar.source [ key ]
        privateVar.keys.splice ( index , 1 );
      }
      
    }
    
    function Hash_get ( key ) {
      var privateVar = privates ( this );
      
      if ( privateVar.keys.indexOf ( key ) > -1 ) {
        return privateVar.source [ key ];
      }
    }
    
    function Hash_keys () {
      return privates ( this ).keys;
    }
    
    function Hash_forEach ( fn ) {
      
      var privateVar = privates ( this ),
          hash = privateVar.source,
          keys = privateVar.keys;
      
      for ( var i = 0,len = keys.length; i < len; ++i ) {
        fn ( hash [ keys [ i ] ] , keys [ i ] , this );
      }
      
    }
    
    function Hash_map ( fn ) {
      
      var privateVar = privates ( this ),
          hash = privateVar.source,
          keys = privateVar.keys;
      
      for ( var i = 0,len = keys.length; i < len; ++i ) {
        hash [ keys [ i ] ] = fn ( hash [ keys [ i ] ] , keys [ i ] , this );
      }
      
    }
    
    function Hash_has ( key ) {
      return key in privates ( this ).source
    }
    
    function Hash_toArray () {
      var ret = [],
          source = privates ( this ).source,
          iter = -1;
      
      for ( var i in source ) {
        ret [ ++iter ] = source [ i ];
      }
      
      return ret;
      
    }
    
    function Hash_toSource () {
      return uneval ( privates ( this ).source );
    }
    
    function Hash_toObject () {
      return privates ( this ).source;
    }
    
    function Hash_diff ( target ) {
      
      var type = baseTypeOf ( target ),
          privateVar = privates ( this ),
          ret = [];
      
      if ( type === "Object" && target.constructor === Hash ) {
        
        var keys = target.keys ();
        
        for ( var i = 0,len = keys.length; i < len; ++i ) {
          if ( !this.has ( keys [ i ] ) ) {
            ret [ ret.length ] = keys [ i ];
          }
        }
        
        for ( var i = 0,len = privateVar.keys.length; i < len; ++i ) {
          if ( !target.has ( privateVar.keys [ i ] ) ) {
            ret [ ret.length ] = privateVar.keys [ i ];
          }
        }
          
        return ret;
          
      }else if ( type === "Object" ) {
        
        for ( var name in target ) {
          if ( !this.has ( name ) ) {
            ret [ ret.length ] = name;
          }
        }
        
        for ( var i = 0,len = privateVar.keys.length; i < len; ++i ) {
          if ( !(  privateVar.keys [ i ] in target ) ) {
            ret [ ret.length ] = privateVar.keys [ i ];
          }
        }
        
        return ret;
        
      }else{
        throw new ( "The arguments of Hash::diff is must be a type of Object or Hash." );
      }
      
    }
    
    function Hash_empty () {
      var privateVar = privates ( this );
      privateVar.source = {};
    }
    
  }
)