this.x=0;
var _mochaGlobalExport = {},
    _mochaClassTable = {},
    _mochaInstanceTable = {},
    _mochaInstanceId = (+new Date());

module Runtime {

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
            if ( this instanceof ret ) {
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
  
  var instanceProp = {},
      slice = Array.prototype.slice;  
  
  export createPrivateProp( id , prop , value , isConst ) {
    if ( !( id in instance_prop ) ) {
      instance_prop[ id ] = {}
    }
    Object.defineProperty( instance_prop[ id ] , prop , {
      enumerable : true,
      configurable : isConst,
      writable : isConst,
      value : value
    });
  }
  
  export getPrivateProp( id , prop ) {
    if ( id in _mochaInstanceProp ) {
      return _mochaInstanceProp[ id ];
    } else {
      try {
        throw new TypeError( prop + "is not defined." );
      } catch( e ) {
        throw new Error( e );
      }
    }
  }
  
  export createUnenumProp = ( obj , prop , value ) -> Object.defineProperty( obj , prop , {
    configurable : true,
    enumerable : false,
    writable : true,
    value : value
  });
  
  export constant = ( obj , prop , value ) -> Object.defineProp( obj , prop , {
    configurable : false,
    enumerable : false,
    writable : false,
    value : value
  });
  
  export toArray = ( likeArray ) -> ( likeArray )? slice.call( likeArray ) : [];
}


