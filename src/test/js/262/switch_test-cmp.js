(function() {
  var __FILE__ = "Runtime",
      __LINE__ = 0;
  
  var _mochaGlobalExport = {};
  
  ( function () {
    "use strict";
    
    function builtinTypeError( message ) {
      try {
        throw new TypeError( message );
      } catch( e ){
        throw new Error( e );
      };
    };
    
    function callbackCheck( callback,type ) {
      
      Runtime.assert( true,typeof type === "string","typeof type === \"string\"",39,'./mocha_runtime.js' );
      
      if ( typeof callback !== "function" ){
        builtinTypeError( type+" : first argument is not callable" );
      };
    };
    
    if ( !String.prototype.trim ){
      String.prototype.trim = function () {
        return this.replace( String.prototype.trim.rtrim,"" );
      };
      
      String.prototype.trim.rtrim = /^\s*|\s*$/g;
    };
    
    if ( !Function.prototype.bind ){
      Function.prototype.bind = function () {
        var argArray = Array.prototype.slice.call( arguments ),
            context = argArray.shift(),
            ret = function () {
              var args = argArray.concat( Array.prototype.slice.call( arguments ) );
              
              if ( this !== null && this !== window && this instanceof ret ){
                return ret.context.apply( this,args );
              } else {
                return ret.context.apply( context,args );
              };
            };
        
        ret.prototype = this.prototype;
        
        ret.context = this;
        return ret;
      };
    };
    
    if ( !Array.prototype.forEach ){
      Array.prototype.forEach = function ( callback,that ) {
        callbackCheck( callback,"Array.forEach" );
        
        var iter = -1,
            ta;
        
        if ( this === null ){
          builtinTypeError( "Array.forEach : this is null or not defined" );
        };
        
        if ( that ){
          while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
            callback.call( that,ta,iter,this );
          };
        } else {
          while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
            callback( ta,iter,this );
          };
        };
      };
    };
    
    if ( !Array.prototype.every ){
      Array.prototype.every = function ( callback,that ) {
        callbackCheck( callback,"Array.every" );
        
        var iter = -1,
            ta;
        
        if ( this === null ){
          builtinTypeError( "Array.every : this is null or not defined" );
        };
        
        if ( that ){
          while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
            if ( !( callback.call( that,ta,iter,this ) ) ){
              return false;
            };
          };
        } else {
          while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
            if ( !( callback( ta,iter,this ) ) ){
              return false;
            };
          };
        };
        return true;
      };
    };
    
    if ( !Array.prototype.some ){
      Array.prototype.some = function ( callback,that ) {
        callbackCheck( callback,"Array.some" );
        
        var iter = -1,
            ta;
        
        if ( this === null ){
          builtinTypeError( "Array.some : this is null or not defined" );
        };
        
        if ( that ){
          while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
            if ( callback.call( that,ta,iter,this ) ){
              return true;
            };
          };
        } else {
          while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
            if ( callback( ta,iter,this ) ){
              return true;
            };
          };
        };
        return false;
      };
    };
    
    if ( !Array.prototype.filter ){
      Array.prototype.filter = function ( callback,that ) {
        callbackCheck( callback,"Array.filter" );
        
        var len = this.length,
            iter = -1,
            ret = [],
            ta;
        
        if ( this === null ){
          builtinTypeError( "Array.filter : this is null or not defined" );
        };
        
        if ( that ){
          for ( var i = 0,len = this.length;i<len; ++ i ){
            if ( ( ta = this[i] ) !== null && ta !== undefined ){
              if ( callback.call( that,ta,i,this ) ){
                ret[ ++ iter] = ta;
              };
            };
          };
        } else {
          for ( var i = 0,len = this.length;i<len; ++ i ){
            if ( ( ta = this[i] ) !== null && ta !== undefined ){
              if ( callback( ta,i,this ) ){
                ret[ ++ iter] = ta;
              };
            };
          };
        };
        return ret;
      };
    };
    
    if ( !Array.prototype.indexOf ){
      Array.prototype.indexOf = function ( subject,fromIndex ) {
        var iter = ( fromIndex )?fromIndex-1 : -1,
            index = -1,
            ta;
        
        if ( this === null ){
          builtinTypeError( "Array.indexOf : this is null or not defined." );
        };
        
        while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
          if ( ta === subject ){
            index = iter;
            break;
          };
        };
        return index;
      };
    };
    
    if ( !Array.prototype.lastIndexOf ){
      Array.prototype.lastIndexOf = function ( target,fromIndex ) {
        var len = this.length,
            iter = ( fromIndex )?fromIndex+1 : len,
            index = -1,
            ta;
        
        if ( this === null ){
          builtinTypeError( "Array.lastIndexOf : this is null or not defined." );
        };
        
        while ( ( ta = this[ -- iter] ) !== null && ta !== undefined ){
          if ( ta === target ){
            index = iter;
            break;
          };
        };
        return index;
      };
    };
    
    if ( !Array.prototype.map ){
      Array.prototype.map = function ( callback,that ) {
        callbackCheck( callback,"Array.map" );
        
        var ret = [],
            iter = -1,
            len = this.length,
            i = 0,
            ta;
        
        if ( this === null ){
          builtinTypeError( "Array.map : this is null or not defined." );
        };
        
        if ( that ){
          for ( i;i<len; ++ i ){
            if ( ( ta = this[i] ) !== null && ta !== undefined ){
              ret[ ++ iter] = callback.call( that,ta,i,this );
            };
          };
        } else {
          for ( i;i<len; ++ i ){
            if ( ( ta = this[i] ) !== null && ta !== undefined ){
              ret[ ++ iter] = callback( ta,i,this );
            };
          };
        };
        return ret;
      };
    };
    
    if ( !Array.prototype.reduce ){
      Array.prototype.reduce = function ( callback,initial ) {
        callbackCheck( callback,"Array.reduce" );
        
        var ret = initial || this[0],
            i = ( initial )?0 : 1,
            len = this.length,
            ta;
        
        if ( ( len === 0 || len === null ) && arguments.length<2 ){
          builtinTypeError( "Array length is 0 and no second argument" );
        };
        
        for ( i;i<len; ++ i ){
          if ( ( ta = this[i] ) !== null && ta !== undefined ){
            ret = callback( ret,ta,i,this );
          };
        };
        return ret;
      };
    };
    
    if ( !Array.prototype.reduceRight ){
      Array.prototype.reduceRight = function ( callback,initial ) {
        callbackCheck( callback,"Array.reduceRight" );
        
        var len = this.length,
            ret = initial || this[len-1],
            i = ( initial )?len-1 : len-2,
            ta;
        
        if ( ( len === 0 || len === null ) && arguments.length<2 ){
          builtinTypeError( "Array length is 0 and no second argument" );
        };
        
        for ( i;i>-1; -- i ){
          if ( ( ta = this[i] ) !== null && ta !== undefined ){
            ret = callback( ret,ta,i,this );
          };
        };
        return ret;
      };
    };
    
    if ( !Date.prototype.toJSON ){
      Date.prototype.toJSON = function () {
        var _mochaLocalTmp0 = [this.getUTCMonth(),this.getUTCDate(),this.getUTCHours(),this.getMinutes(),this.getSeconds()],
            month = _mochaLocalTmp0[0],
            date = _mochaLocalTmp0[1],
            hour = _mochaLocalTmp0[2],
            minute = _mochaLocalTmp0[3],
            second = _mochaLocalTmp0[4];
        return '"'+this.getUTCFullYear()+'-'+( month>8?month+1 : "0"+( month+1 ) )+'-'+( date>9?date : "0"+date )+'T'+( hour>9?hour : "0"+hour )+':'+( minute>9?minute : "0"+minute )+':'+( second>9?second : "0"+second )+'.'+this.getUTCMilliseconds()+'Z"';
      };
    };
    
    if ( !Date.now ){
      Date.now = function () {
        return +new Date();
      };
    };
    
    if ( !Object.keys ){
      Object.keys = function ( obj ) {
        if ( !obj ){
          builtinTypeError( "Object.keys : first arguments is null or not defined." );
        };
        
        var ret = [],
            iter = -1;
        
        for ( var i in obj ){
          if ( obj.hasOwnProperty( i ) ){
            ret[ ++ iter] = obj[i];
          };
        };
        return ret;
      };
    };
    
    if ( !Object.preventExtensions ){
      Object.preventExtensions = function ( o ) {
        return o;
      };
    };
    
    if ( !Object.seal ){
      Object.seal = function ( o ) {
        return o;
      };
    };
    
    if ( !Object.freeze ){
      Object.freeze = function ( o ) {
        return o;
      };
    };
    
    var hasRealEcma5 = ( function () {
          try {
            var obj = {};
            
            Object.defineProperty( obj,"test", {
              configurable : false,
              writable : false,
              enumerable : false,
              value : 0
            });
            
            obj.test = 200;
            return ( obj.test === 200 )?false : true;
          } catch( e ){
            return false;
          };
        })();
    
    if ( !hasRealEcma5 ){
      Object.defineProperty = function ( obj,prop,valobj ) {
        if ( valobj.value ){
          obj[prop] = valobj.value;
        };
      };
    };
    
    if ( !Array.isArray ){
      Array.isArray = function ( arr ) {
        if ( arguments.length === 0 ){
          return false;
        };
        return ( arr )?Object.prototype.toString.call( arr ) === "[object Array]" : false;
      };
    };
  })();
  
  var Runtime = ( function Runtime() {
        var _mochaLocalExport = {};
        
        function Exception( line,file,e ) {
          this.toString = function () {
            return Runtime.getErrorMessage( e )+" in file "+file+" at : "+line;
          };
        }
        function fastMax( x,y ) {
          return x>y?x : y;
        }
        var Runtime =  {
              getErrorMessage : function getErrorMessage( e ) {
                return ( e.message )?e.message : ( e.description )?e.description : e.toString();
              },
              exceptionHandler : function exceptionHandler( line,file,e ) {
                if ( isStopIteration( e ) ){
                  this.throwException( e );
                } else {
                  this.throwException( new Exception( line,file,e ) );
                };
              },
              throwException : function throwException( exception ) {
                try {
                  throw exception;
                } catch( e ){
                  if ( isStopIteration( e ) ){
                    throw new Error( e );
                  } else {
                    throw new Error( this.getErrorMessage( e ) );
                  };
                };
              },
              hasProto : "__proto__" in {}
            };
        
        var slice = Array.prototype.slice;
        
        var createUnenumProp = _mochaLocalExport.createUnenumProp = function createUnenumProp( obj,prop,value ) {
              return Object.defineProperty( obj,prop, {
                configurable : true,
                enumerable : false,
                writable : true,
                value : value
              });
            };
        
        var constant = _mochaLocalExport.constant = function constant( obj,prop,value ) {
              return Object.defineProperty( obj,prop, {
                configurable : false,
                enumerable : false,
                writable : false,
                value : value
              });
            };
        
        var toArray = _mochaLocalExport.toArray = function toArray( likeArray,index ) {
              return ( likeArray )?slice.call( likeArray,index ) : [];
            };
        
        var Generator = function (){};
        
        var createGenerator = _mochaLocalExport.createGenerator = function createGenerator( generatorFn,closeFn,context ) {
              var ret = new Generator;
              
              createUnenumProp( ret,"next",generatorFn.bind( context,false,false ) );
              
              createUnenumProp( ret,"send",generatorFn.bind( context,true,false ) );
              
              createUnenumProp( ret,"close",closeFn.bind( context ) );
              
              createUnenumProp( ret,"__nothrowNext__",generatorFn.bind( context,false,true ) );
              
              createUnenumProp( ret,"toString",
              function () {
                return "[object Generator]";
              });
              
              Object.freeze( ret );
              return ret;
            };
        
        function getErrorMessage( e ) {
          return ( e.message )?e.message : ( e.description )?e.description : e.toString();
        }
        var throwException = _mochaLocalExport.throwException = Runtime.throwException.bind( Runtime );
        
        var exceptionHandler = _mochaLocalExport.exceptionHandler = Runtime.exceptionHandler.bind( Runtime );
        
        var extend = _mochaLocalExport.extend = function extend( dest,source ) {
              for ( var prop in source ){
                dest[prop] = source[prop];
              };
              return dest;
            };
        
        function compareTuple( tuple ) {
          var max = fastMax( tuple.length,this.length );
          
          i = 0;
          
          while ( i<max && tuple[i] === this[i] ){
            i ++ ;
          };
          return max === i;
        };
        
        function tupleToArray() {
          return Array.prototype.slice.call( this );
        };
        
        var createTuple = _mochaLocalExport.createTuple = function createTuple( obj,size ) {
              createUnenumProp( obj,"length",size );
              
              createUnenumProp( obj,"equal",compareTuple );
              
              createUnenumProp( obj,"toArray",tupleToArray );
              
              createUnenumProp( obj,"toString",
              function () {
                return "[object Tuple]";
              });
              return Object.freeze( obj );
            };
        
        var extendPrototype = _mochaLocalExport.extendPrototype = function ( derived,base ) {
              derived.prototype = base;
            };
        
        var getPrototype = ( "getPrototypeOf" in Object )?function ( obj ) {
              return Object.getPrototypeOf( obj );
            } : function ( obj ) {
              var ret = {};
              
              for ( var i in obj ){
                if ( !obj.hasOwnProperty( i ) ){
                  ret[i] = obj[i];
                };
              };
              return ret;
            };
        
        var extendClass = _mochaLocalExport.extendClass = ( Runtime.hasProto )?function ( derived,base ) {
              if ( typeof base === 'function' ){
                derived.prototype.__proto__ = base.prototype;
                
                for ( var i in base ){
                  derived[i] = base[i];
                };
              } else {
                derived.prototype.__proto__ = base.__proto__;
              };
            } : function ( derived,base ) {
              var baseType = typeof base;
              
              if ( baseType === "function" ){
                var inherit = function (){};
                
                inherit.prototype = base.prototype;
                
                derived.prototype = new inherit;
                
                for ( var i in base ){
                  derived[i] = base[i];
                };
              } else {
                var inherit = function (){},
                    proto = getPrototype( base );
                
                inherit.prototype = proto;
                
                derived.prototype = new inherit;
              };
            };
        
        var __ref_iterator__ = _mochaLocalExport.__ref_iterator__ = "__mocha_iterator_special_key__";
        
        var throwStopIteration = _mochaLocalExport.throwStopIteration = function throwStopIteration() {
              try {
                throw StopIteration;
              } catch( e ){
                throw new Error( e.toString() );
              };
            };
        
        var isGenerator = _mochaLocalExport.isGenerator = function isGenerator( obj ) {
              return obj instanceof Generator;
            };
        
        var getIterator = _mochaLocalExport.getIterator = function getIterator( obj ) {
              var ret = obj[__ref_iterator__](),
                  newObj;
              
              if ( isGenerator( ret ) ){
                return ret;
              };
              
              newObj = {};
              
              if ( ret.next ){
                createUnenumProp( newObj,"next",
                function () {
                  var result = ret.next();
                  
                  if ( result === undefined ){
                    throwStopIteration();
                  };
                  return result;
                });
              } else {
                return {};
              };
              
              if ( !( "__nothrowNext__" in ret ) ){
                createUnenumProp( newObj,"__nothrowNext__",ret.next.bind( ret ) );
              };
              
              for ( var prop in ret ){
                if ( prop !== "next" && prop !== "__nothrowNext__" ){
                  newObj[prop] = ret[prop];
                };
              };
              
              if ( !( "toString" in ret ) ){
                createUnenumProp( newObj,"toString",
                function () {
                  return "[object Iterator]";
                });
              };
              return newObj;
            };
        
        var hasIterator = _mochaLocalExport.hasIterator = function hasIterator( obj ) {
              return __ref_iterator__ in obj;
            };
        
        var rstopIteration = /StopIteration/;
        
        var isStopIteration = _mochaLocalExport.isStopIteration = function isStopIteration( obj ) {
              return obj === StopIteration || rstopIteration.test( obj );
            };
        
        var privateRecord,
            createPrivateRecord,
            getPrivateRecord;
        
        if ( "WeakMap" in window ){
          privateRecord = new WeakMap();
          
          createPrivateRecord = function ( self,privateHolder ) {
            var holder = new privateHolder;
            
            createUnenumProp( holder.constructor,"__is_private__",1 );
            
            privateRecord.set( self,holder );
          };
          
          getPrivateRecord = function ( self ) {
            if ( privateRecord.has( self ) ){
              return privateRecord.get( self );
            } else if ( self.constructor === "__is_private__" ){
              return self;
            };
          };
        } else {
          createPrivateRecord = function ( self,privateHolder ) {
            if ( !self.__typeid__ ){
              var holder = new privateHolder;
              
              createUnenumProp( holder.constructor,"__is_private__",1 );
              
              createUnenumProp( self,"__private__",holder );
            };
          };
          
          getPrivateRecord = function ( self ) {
            if ( self.__private__ ){
              return self.__private__;
            } else if ( self.constructor === "__is_private__" ){
              return self;
            };
          };
        };
        
        ( _mochaLocalExport.createPrivateRecord = createPrivateRecord );
        
        ( _mochaLocalExport.getPrivateRecord = getPrivateRecord );
        
        var getSuper = _mochaLocalExport.getSuper = function getSuper( obj ) {
              var type = typeof obj,
                  ret;
              
              if ( type === "function" ){
                ret = function (){};
                
                ret.prototype = obj.prototype;
                
                ret = new ret();
                
                if ( obj.__harmony_class__ ){
                  ret.constructor = obj.constructor;
                } else {
                  ret.constructor = obj;
                };
                return ret;
              };
              return ret;
            };
        
        var traitMixin = _mochaLocalExport.traitMixin = function traitMixin( dest,source,with_,without ) {
              if ( !dest._mochaTraitMark || !source._mochaTraitMark ){
                Runtime.throwException( "mixin only used for trait." );
              } else {
                var destTraitPrivate = dest._mochaTraitPrivate,
                    sourceTraitPrivate = source._mochaTraitPrivate,
                    destTraitPublic = dest._mochaTraitPublic,
                    sourceTraitPublic = source._mochaTraitPublic,
                    sourceRequires = source._mochaRequires,
                    destRequires = dest._mochaRequires,
                    tmp;
                
                for ( var i in sourceTraitPrivate ){
                  if ( !without[i] ){
                    tmp = ( !with_[i] )?i : with_[i];
                    
                    destTraitPrivate[tmp] = sourceTraitPrivate[i];
                  };
                };
                
                for ( i in sourceTraitPublic ){
                  if ( !without[i] ){
                    tmp = ( !with_[i] )?i : with_[i];
                    
                    destTraitPublic[tmp] = sourceTraitPublic[i];
                  };
                };
                
                for ( i in sourceRequires ){
                  destRequires[i] = sourceRequires[i];
                };
              };
            };
        
        var classMixin = _mochaLocalExport.classMixin = function classMixin( _mochaLocalTmp1,_mochaLocalTmp2,_mochaLocalTmp3,with_,without ) {
              var constructorProto = _mochaLocalTmp1.prototype,
                  privateProto = _mochaLocalTmp2.prototype,
                  mark = _mochaLocalTmp3._mochaTraitMark,
                  traitPublic = _mochaLocalTmp3._mochaTraitPublic,
                  traitPrivate = _mochaLocalTmp3._mochaTraitPrivate;
              
              if ( !mark ){
                Runtime.throwException( "mixin only used for trait." );
              } else {
                var tmp;
                
                for ( var i in traitPublic ){
                  if ( !without[i] ){
                    tmp = ( !with_[i] )?i : with_[i];
                    
                    constructorProto[tmp] = traitPublic[i];
                  };
                };
                
                for ( i in traitPrivate ){
                  if ( !without[i] ){
                    tmp = ( !with_[i] )?i : with_[i];
                    
                    privateProto[tmp] = traitPrivate[i];
                  };
                };
              };
            };
        
        var checkRequirements = _mochaLocalExport.checkRequirements = function checkRequirements( _mochaLocalTmp4,_mochaLocalTmp5,traits,file,line ) {
              var proto1 = _mochaLocalTmp4.prototype,
                  proto2 = _mochaLocalTmp5.prototype;
              
              for ( var i = 0,len = traits.length;i<len;i ++  ){
                var _mochaLocalTmp6 = traits[i],
                    _mochaRequires = _mochaLocalTmp6._mochaRequires;
                
                for ( var prop in _mochaRequires ){
                  if ( !( prop in proto1 ) && !( prop in proto2 ) ){
                    Runtime.throwException( "Class dose not meet the traits requirement. traits require implementation of property "+prop+"\nin file "+file+" at line "+line );
                  };
                };
              };
            };
        
        ( function () {
          var assert = _mochaLocalExport.assert = ( console && console.assert )?function ( expect,exp,str,line,filename ) {
                return console.assert( expect === exp,"assertion failed : "+str+"\nexpect "+expect+" but got "+exp+"\nin file "+filename+" at : "+line );
              } : function ( expect,exp,str,line,filename ) {
                if ( expect !== exp ){
                  Runtime.throwException( "assertion failed : "+str+"\nexpect "+expect+" but got "+exp+"\nin file "+filename+" at : "+line );
                };
              };
        })();
        return _mochaLocalExport;
      })();
  
  if ( !( "StopIteration" in window ) ){
    window.StopIteration =  {
      toString : function toString() {
        return "[object StopIteration]";
      }
    };
  };
  
  __LINE__ = 0;
  ( function () {
    try {
      var __FILE__ = "/Users/aono_taketoshi/github/mocha/src/test/js/262/switch_test.js",
          __LINE__ = 0;
      __LINE__ = 2;
      _mochaGlobalExport['./switch_test.js'] = {};
      
      __LINE__ = 3;
      var _mochaGlobalAlias = _mochaGlobalExport['./switch_test.js'];
      
      function switchTest( type ) {
        try {
          __LINE__ = 3;
          var ret = 0;
          
          __LINE__ = 0;
          switch ( type ) {
            case 1 :
              
              __LINE__ = 0;
              ret = 0;
              
              __LINE__ = 0;
              ret += 1;
              __LINE__ = 8;
              return ret;
            case 2 :
              
              __LINE__ = 0;
              ret = 100;
              __LINE__ = 11;
              break;
            case 3 :
            case 4 :
              
              __LINE__ = 0;
              ret = 0;
              
              __LINE__ = 0;
              ret ++ ;
              __LINE__ = 17;
              break;
            case 5 :
              
              {
                __LINE__ = 0;
                ret = 0;
                
                __LINE__ = 0;
                ret = 1;
              };
              __LINE__ = 23;
              break;
            case 6 :
            case 7 :
              
              {
                __LINE__ = 0;
                ret = 10;
              };
              __LINE__ = 28;
              break;
            default :
              
              __LINE__ = 0;
              ret = 100;
              
          };
          __LINE__ = 32;
          return ret;
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }
      __LINE__ = 35;
      Runtime.assert( true,switchTest( 1 ) === 1,"switchTest( 1 ) === 1",35,'./switch_test.js' );
      
      __LINE__ = 36;
      Runtime.assert( true,switchTest( 2 ) === 100,"switchTest( 2 ) === 100",36,'./switch_test.js' );
      
      __LINE__ = 37;
      Runtime.assert( true,switchTest( 3 ) === 1,"switchTest( 3 ) === 1",37,'./switch_test.js' );
      
      __LINE__ = 38;
      Runtime.assert( true,switchTest( 4 ) === 1,"switchTest( 4 ) === 1",38,'./switch_test.js' );
      
      __LINE__ = 39;
      Runtime.assert( true,switchTest( 5 ) === 1,"switchTest( 5 ) === 1",39,'./switch_test.js' );
      
      __LINE__ = 40;
      Runtime.assert( true,switchTest( 6 ) === 10,"switchTest( 6 ) === 10",40,'./switch_test.js' );
      
      __LINE__ = 41;
      Runtime.assert( true,switchTest( 7 ) === 10,"switchTest( 7 ) === 10",41,'./switch_test.js' );
      
      __LINE__ = 42;
      Runtime.assert( true,switchTest( 8 ) === 100,"switchTest( 8 ) === 100",42,'./switch_test.js' );
    } catch( e ){
      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  })();
})();
