var _mochaGlobalExport = {},
    _mochaClassTable = {}

module Runtime {
  
  const Exception( line , file , e ) {
          this.toString = -> Runtime.getErrorMessage( e ) + " in file " + file + " at : " + line;
        }
  //Minimal runtime object.
  var Runtime = {
        getErrorMessage ( e ) -> ( e.message )? e.message : ( e.description )? e.description : e.toString(),
        exceptionHandler ( line , file , e ){
          if ( isStopIteration( e ) ) {
            this.throwException( e );
          } else {
            this.throwException( new Exception( line , file , e ) );
          }
        },
        throwException ( exception ) {
          try {
            throw exception;
          } catch( e ) {
            if ( isStopIteration( e ) ) {
              throw new Error( e );
            } else {
              throw new Error( this.getErrorMessage( e ) );
            }
          }
        },
        hasProto : "__proto__" in {}
      }
  
  if( !String.prototype.trim ){
    String.prototype.trim = -> this.replace( String.prototype.trim.rtrim , "" );
    String.prototype.trim.rtrim = /^\s*|\s*$/g;
  }

  if( !Function.prototype.bind ){
    Function.prototype.bind = -> {
      var argArray = Array.prototype.slice.call ( arguments ),
          context = argArray.shift (),
          ret = ->{
            var args = argArray.concat ( Array.prototype.slice.call ( arguments ) );
            if ( this !== null && this !== window && this instanceof ret ) {
              return ret.context.apply ( this , args );
            } else {
              return ret.context.apply( context , args );
            }
          }
      ret.prototype = this.prototype;
      ret.context = this;
      return ret;
    }
  }

  if( !Array.prototype.forEach ){
    Array.prototype.forEach = ( fn , that ) -> {
      var iter = -1,
          ta;
      if( that ){
        while( ( ta = this[ ++iter ] ) !== null && ta !== undefined ){
          fn.call( that , ta , iter , this );
        }
      }else{
        while( ( ta = this[ ++iter ] ) !== null && ta !== undefined ){
          fn( ta , iter , this );
        }
      }
    }
  }

  if( !Array.prototype.every ){
    Array.prototype.every = ( fn , that ) -> {
      var iter = -1,
          ta;
      if( that ){
        while( ( ta = this[ ++iter ] ) !== null && ta !== undefined ){
          if( ! ( fn.call( that , ta , iter , this ) ) ){
            return false;
          }
        }
      }else{
        while( ( ta = this[ ++iter ] ) !== null && ta !== undefined ){
          if( !( fn( ta , iter , this ) ) ){
            return false;
          }
        }
      }
      return true;
    }
  }

  if( !Array.prototype.some ){
    Array.prototype.some = ( fn , that ) -> {
      var iter = -1,
          ta;
      if( that ){
        while( ( ta = this[ ++iter ] ) !== null && ta !== undefined ){
          if( fn.call( that , ta , iter , this ) ){
            return true;
          }
        }
      }else{
        while( ( ta = this[ ++iter ] ) !== null && ta !== undefined ){
          if( fn( ta , iter , this ) ){
            return true;
          }
        }
      }
      return false;
    }
  }

  if( !Array.prototype.filter ){
    Array.prototype.filter = ( fn , that ) -> {
      var iter = -1,
          ret = [],
          ta;
      if( that ){
        for( var i = 0,len = this.length; i < len; ++i ){
          if( ( ta = this[ i ] ) !== null && ta !== undefined ){
            if( fn.call( that , ta , i , this ) ){
              ret[ ++iter ] = ta;
            }
          }
        }
      }else{
        for( var i = 0,len = this.length; i < len; ++i ){
          if( ( ta = this[ i ] ) !== null && ta !== undefined ){
            if( fn( ta , i , this ) ){
              ret[ ++iter ] = ta;
            }
          }
        }
      }
      return ret;
    }
  }

  if( !Array.prototype.indexOf ){
    Array.prototype.indexOf = ( subject ) -> {
      var iter = -1,
          index = -1,
          ta;
      while( ( ta = this[ ++iter ] ) !== null && ta !== undefined ){
        if( ta === subject ){
          index = iter;
          break;
        }
      }
      return index;
    }
  }

  if( !Array.prototype.lastIndexOf ){
    Array.prototype.lastIndexOf = ( subject ) -> {
      var iter = this.length,
          index = -1,
          ta;
      while( ( ta = this[ --iter ] ) !== null && ta !== undefined ){
        if( ta === subject ){
          index = iter;
          break;
        }
      }
      return index;
    }
  }

  if( !Array.prototype.map ){
    Array.prototype.map = ( fn , that ) -> {
      var ret = [],
          iter = -1,
          ta;
      if( that ){
        for( var i = 0,len = this.length; i < len; ++i ){
          if( ( ta = this[ i ] ) !== null && ta !== undefined ){
            ret[ ++iter ] = fn.call( that , ta , i , this );
          }
        }
      }else{
        for( var i = 0,len = this.length; i < len; ++i ){
          if( ( ta = this[ i ] ) !== null && ta !== undefined ){
            ret[ ++iter ] = fn( ta , i , this );
          }
        }
      }
      return ret;
    };
  }

  if( !Array.prototype.reduce ){
    Array.prototype.reduce = ( fn , initial ) -> {
      var ret = initial || this[ 0 ],
          i = ( initial )? 0 : 1,
          ta,
          len;
      for( i,len = this.length; i < len; ++i ){
        if( ( ta = this[ i ] ) !== null && ta !== undefined ){
          ret = fn( ret , ta , i , this );
        }
      }
      return ret;
    };
  }

  if( !Array.prototype.reduceRight ){
    Array.prototype.reduceRight = ( fn , initial ) -> {
      var ret = initial || this[ this.length - 1 ],
          i = ( initial )? this.length - 1 : this.length - 2,
          ta;
      for( i; i > -1; --i ){
        if( ( ta = this[ i ] ) !== null && ta !== undefined ){
          ret = fn( ret , ta , i , this );
        }
      }
      return ret;
    };
  }

  if ( !Date.prototype.toJSON ) {
    Date.prototype.toJSON = ->
      '"' + this.getUTCFullYear () + '-' +
      "0" + ( this.getUTCMonth () + 1 ) + '-' +
      "0" + ( this.getUTCDate () - 1 ) + 'T' +
      this.getUTCHours () + ':' +
      this.getMinutes () + ':' +
      this.getSeconds () + '.' +
      this.getUTCMilliseconds () + '"';
  }

  if ( !Date.now ) {
    Date.now = -> +new Date ();
  }

  if ( !Object.keys ) {
    Object.keys = ( obj ) -> {
      var ret = [],
          iter = -1;
      
      for ( var i in obj ) {
        if ( obj.hasOwnProperty ( i ) ) {
          ret [ ++iter ] = obj [ i ]
        }
      }
      
      return ret;
      
    };
  }

  if ( !Object.preventExtensions ) {
    Object.preventExtensions = ( o ) -> o;
  }

  if ( !Object.seal ) {
    Object.seal = ( o ) -> o;
  }

  if ( !Object.freeze ) {
    Object.freeze = ( o ) -> o;
  }

  var hasRealEcma5 = (->{
        try {
          var obj = {}
          Object.defineProperty( obj , "test" , {
            configurable : false,
            writable : false,
            enumerable : false,
            value : 0
          });
          obj.test = 200;
          return ( obj.test === 200 )? false : true;
        } catch (e) {
          return false;
        }
      })();

  if ( !hasRealEcma5 ) {
    Object.defineProperty = ( obj , prop , valobj ) -> {
      if ( valobj.value ) {
        obj[ prop ] = valobj.value;
      }
    }
  }

  if ( !Array.isArray ) {
    var arrayString = "[object Array]";
    Array.isArray = ( arr ) -> {
      if  ( arguments.length === 0 ) {
        return false;
      }
      return ( arr )? Object.prototype.toString.call ( arr ) === arrayString : false;
    }
  }
  
  var slice = Array.prototype.slice;
  
  export createUnenumProp( obj , prop , value ) -> Object.defineProperty( obj , prop , {
    configurable : true,
    enumerable : false,
    writable : true,
    value : value
  });
  
  export constant( obj , prop , value ) -> Object.defineProperty( obj , prop , {
    configurable : false,
    enumerable : false,
    writable : false,
    value : value
  });
  
  export toArray( likeArray , index ) -> ( likeArray )? slice.call( likeArray , index ) : [];
  
  var Generator = function () {}
  
  export createGenerator( generatorFn , closeFn , context ) -> {
    var ret = new Generator;
    createUnenumProp( ret , "next" , generatorFn.bind( context , false , false ) );
    createUnenumProp( ret , "send" , generatorFn.bind( context , true , false ) );
    createUnenumProp( ret , "close" , closeFn.bind( context ) );
    createUnenumProp( ret , "__nothrowNext__" , generatorFn.bind( context , false , true ) );
    createUnenumProp( ret , "toString" , -> "[object Generator]" );
    Object.freeze( ret );
    return ret;
  }
  
  const getErrorMessage( e ) -> ( e.message )? e.message : ( e.description )? e.description : e.toString();
  
  export throwException = Runtime.throwException.bind( Runtime );
  
  export exceptionHandler = Runtime.exceptionHandler.bind( Runtime );
  
  export extendPrototype = ( derived , base ) -> {
    derived.prototype = base;
  }
  
  const getPrototype = ( "getPrototypeOf" in Object )?
    ( obj ) -> Object.getPrototypeOf( obj ) :
    ( obj ) -> {
      if ( "constructor" in obj ) {
        return obj.constructor.prototype || {};
      }
    }
  
  export extendClass = ( Runtime.hasProto )?
    ( derived , base ) -> {
      if ( typeof base === 'function' ) {
        derived.prototype.__proto__ = base.prototype;
      } else {
        derived.prototype.__proto__ = base.__proto__;
      }
    } :
    ( derived , base ) -> {
      var baseType = typeof base;
      if ( baseType === "function" ) {
        var inherit = ->{};
        inherit.prototype = base.prototype;
        derived.prototype = new inherit;
      } else {
        var inherit = ->{},
            proto = getPrototype( base );
        inherit.prototype = proto;
        derived.prototype = new inherit;
      }
    }
  
  export __ref_iterator__ = "__mocha_iterator_special_key__";
  
  export throwStopIteration() {
    try {
      throw StopIteration;
    } catch ( e ) {
      throw new Error( e.toString() );
    }
  }
  
  export isGenerator( obj ) {
    return obj instanceof Generator;
  }
  
  export getIterator( obj ) {
    var ret = obj[__ref_iterator__](),
        newObj;
    if ( isGenerator( ret ) ) {
      return ret;
    }
    newObj = {};
    if ( ret.next ) {
      createUnenumProp( newObj , "next" , function () {
        var result = ret.next();
        if ( result === undefined ) {
          throwStopIteration();
        }
        return result;
      });
    } else {
      return {};
    }
    if ( !( "__nothrowNext__" in ret ) ) {
      createUnenumProp( newObj , "__nothrowNext__" , ret.next.bind( ret ) );
    }
    for ( var prop in ret ) {
      if ( prop !== "next" && prop !== "__nothrowNext__" ) {
        newObj[ prop ] = ret[ prop ]
      }
    }
    if ( !( "toString" in ret ) ) {
      createUnenumProp( newObj , "toString" , -> "[object Iterator]" );
    }
    return newObj;
  }
  
  export hasIterator( obj ) {
    return __ref_iterator__ in obj;
  }
  
  const rstopIteration = /StopIteration/;
  export isStopIteration( obj ) {
    return obj === StopIteration || rstopIteration.test( obj );
  }
  
  if ( "WeakMap" in window ) {
    const privateRecord = new WeakMap();
    export createPrivateRecord( self , privateHolder ) {
      privateRecord.set( self , new privateHolder );
    }
    export getPrivateRecord( self ) {
      if ( privateRecord.has( self ) ) {
        return privateRecord.get( self );
      } else {
        Runtime.throwException( "class not has private field." );
      }
    }
  } else {
    const _uid = ( new Date() );
    const privateRecord = {};
    export createPrivateRecord( self , privateHolder ) {
      if ( !self.__typeid__ ) {
        var id = _uid++;
        createUnenumProp( self , "__typeid__", id );
        privateRecord[ id ] = new privateHolder;
      }
    }
    export getPrivateRecord( self ) {
      if ( self.__typeid__ ) {
        return privateRecord[ self.__typeid__ ];
      } else {
        Runtime.throwException( "class not has private field." );
      }
    }
    if ( "addEventListener" in document ) {
      window.addEventListener( "unload" , function () {
        for ( var i in privateRecord ) {
          delete privateRecord[ i ];
        }
      }, false );
    }
  }
  
  @version( debug ) {
    export assert = ( console && console.assert )?
      ( expect , exp , str , line , filename )->console.assert( expect === exp , "assertion failed : " + str + "\nexpect " + expect + " but got " + exp + "\nin file " + filename + " at : " + line ) :
      ( expect , exp , str , line , filename )->{
        if ( expect !== exp ) {
          Runtime.throwException( "assertion failed : " + str + "\nexpect " + expect + " but got " + exp + "\nin file " + filename + " at : " + line );
        }
      }
  }
}

if ( !( "StopIteration" in window ) ) {
  window.StopIteration = {
    toString() { return "[object StopIteration]"; }
  }
}
