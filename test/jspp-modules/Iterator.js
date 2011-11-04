
var Iterable = require ( "./Iterable" ).Iterable

Class ( "Iterator" , Iterable )
  (function ( self , privates ) {
    
    var StopIteration = guidgen ();
    
    var getContainerValueHash = function ( privateVar , container , current ) {
      if ( !privateVar.keys [ current ] ) {
        return StopIteration;
      }
      return container.get ( privateVar.keys [ current ] );
    },
    
    getContainerValueArray = function ( privateVar , container , current ) {
      if ( container.length < current ) {
        return StopIteration;
      }
      return container [ current ]
    },
    
    getContainerValueObject = function ( privateVar , container , current ) {
      if ( !privateVar.keys [ current ] ) {
        return StopIteration;
      }
      return container [ privateVar.keys [ current ] ]
    }
    
    self.__init__ = function ( target ) {
      var type = typeOf ( target );
      if ( type === "Hash" ) {
        privates ( this , {
          container : target,
          keys : target.keys (),
          currentIndex : -1,
          getContainerValue : getContainerValueHash
        } )
      }else if ( type === "Object" ) {
        privates ( this , {
          container : target,
          keys : Object.keys ( target ),
          currentIndex : -1,
          getContainerValue : getContainerValueObject
        } )
      }else if ( type === "Array" ) {
        privates ( this , {
          container : target,
          currentIndex : -1,
          getContainerValue : getContainerValueArray
        } )
      }
    }
    
    self.__override__.next = function () {
      
      var privateVar = privates ( this ),
          ret
      
      ++privateVar.currentIndex;
      
      ret = privateVar.getContainerValue ( privateVar , privateVar.container , privateVar.currentIndex );
      
      if ( ret === StopIteration ) {
        privateVar.currentIndex = -1;
        return null;
      }else{
        return ret;
      }
      
    };
    
    self.__override__.prev = function () {
      
      if ( privateVar.currentIndex < 0 ) {
        throw new Error ( "Cannot call prev ()" );
      }
      
      var privateVar = privates ( this ),
          ret = privateVar.getContainerValue ( privateVar , privateVar.container , privateVar.currentIndex );
      
      --privateVar.currentIndex;
      
      return ret;
      
    };
    
    self.__override__.hasNext = function () {
      var privateVar = privates ( this );
      return ( privateVar.getContainerValue ( privateVar , privateVar.container , privateVar.currentIndex + 1 ) !== StopIteration );
    }
    
  })
  
  type ( Iterator , "Iterator" );
  