

Class ( "KVObserver" )
  (function ( self , privates ) {
    
    var kvpool = {},
        observerPool = {},
        typePool = {}
    
    destroy ( function () {
      for ( var i in kvpool ) {
        delete kvpool [ i ]
      }
      for ( var i in observerPool ) {
        delete observerPool [ i ]
      }
      typePool = null;
    } )
    
    self.__init__ = function () {
      privates ( this , {
        kvpool : {},
        observerPool : {},
        typePool : {}
      } )
    }
    
    self.initObserver = function ( key , type ) {
      
      @start-debug
        assert.True ( isDef ( type ) , "The second arguments of KVObserver::initObserver is need not to be null of undefined." )
      @end-debug
      
      var privateVar = privates ( this )
      privateVar.typePool [ key ] = privateVar.typeOf ( type )
      
    }
    
    self.set = function ( key , value ) {
      
      @start-debug
        assert.True ( isDef ( key ) , "The first arguments of KVObserver::set is need not to be null of undefined." )
      @end-debug
      
      var privateVar = privates ( this )
      if ( privateVar.typePool [ key ] && typeOf ( value ) !== typePool [ key ] ) {
        throw new Error ( "This key need typed value. type : " + privateVar.typePool [ key ] + " current type + " + typeOf ( value ) )
      }else{
        privateVar.kvpool [ key ] = value;
        if ( privateVar.observerPool [ key ] ) {
          privateVar.observerPool [ key ] ( privateVar.kvpool [ key ] , key , "set" )
        }
      }
    }
    
    self.remove = function ( key ) {
      
      @start-debug
        assert.True ( isDef ( key ) , "The first arguments of KVObserver::remove is need not to be null of undefined." )
      @end-debug
      
      var privateVar = privates ( this )
      if ( privateVar.kvpool [ key ] ) {
        if ( privateVar.observerPool [ key ] ) {
          privateVar.observerPool [ key ] ( privateVar.kvpool [ key ] , key , "remove" )
          delete privateVar.observerPool [ key ]
        }
        delete privateVar.kvpool [ key ];
      }
    }
    
    self.change = function ( key , fn ) {
      var privateVar = privates ( this )
      if ( privateVar.kvpool [ key ] ) {
        privateVar.kvpool [ key ] = fn ( privateVar.kvpool [ key ] , key )
        if ( privateVar.observerPool [ key ] ) {
          privateVar.observerPool [ key ] ( privateVar.kvpool [ key ] , key , "change" )
        }
      }
    }
    
    
    self.observe = function ( key , fn ) {
      privates ( this ).observerPool [ key ] = fn
    }
    
    self.__static__.initObserver = function ( key , type ) {
      
      @start-debug
        assert.True ( isDef ( type ) , "The second arguments of KVObserver::@static::initObserver is need not to be null of undefined." )
      @end-debug
      
      typePool [ key ] = typeOf ( type )
      
    }
    
    self.__static__.set = function ( key , value ) {
      
      @start-debug
        assert.True ( isDef ( key ) , "The first arguments of KVObserver::@static::set is need not to be null of undefined." )
      @end-debug
      
      if ( typePool [ key ] && typeOf ( value ) !== typePool [ key ] ) {
        throw new Error ( "This key need typed value. type : " + typePool [ key ] + " current type + " + typeOf ( value ) )
      }else{
        kvpool [ key ] = value;
        if ( observerPool [ key ] ) {
          observerPool [ key ] ( kvpool [ key ] , key , "set" )
        }
      }
      
    }
    
    self.__static__.remove = function ( key ) {
      
      @start-debug
        assert.True ( isDef ( key ) , "The first arguments of KVObserver::@static::remove is need not to be null of undefined." )
      @end-debug
      
      if ( kvpool [ key ] ) {
        if ( observerPool [ key ] ) {
          observerPool [ key ] ( kvpool [ key ] , key , "remove" )
          delete observerPool [ key ]
        }
        delete kvpool [ key ];
      }
    }
    
    self.__static__.change = function ( key , fn ) {
      if ( kvpool [ key ] ) {
        kvpool [ key ] = fn ( kvpool [ key ] , key )
        if ( observerPool [ key ] ) {
          observerPool [ key ] ( kvpool [ key ] , key , "change" )
        }
      }
    }
    
    
    self.__static__.observe = function ( key , fn ) {
      observerPool [ key ] = fn
    }
    
    
  })
