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
      var __FILE__ = "/Users/aono_taketoshi/github/mocha/src/test/js/harmony/class_test.js",
          __LINE__ = 0;
      __LINE__ = 2;
      _mochaGlobalExport['./class_test.js'] = {};
      
      __LINE__ = 3;
      var _mochaGlobalAlias = _mochaGlobalExport['./class_test.js'];
      
      __LINE__ = 1;
      var Monster = ( function () {
            try {
              __LINE__ = 0;
              var _mochaPrivateHolder = function (){};
              
              __LINE__ = 1;
              function Monster() {
                try {
                  __LINE__ = 0;
                  Runtime.createPrivateRecord( this,_mochaPrivateHolder );
                  
                  __LINE__ = 0;
                  constructor.apply( this,arguments );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              function constructor( name,health ) {
                try {
                  
                  __LINE__ = 8;
                  this.name = name;
                  
                  __LINE__ = 9;
                  Runtime.getPrivateRecord( this ).health = health;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              __LINE__ = 0;
              Runtime.createUnenumProp( constructor,"__harmony_class__",1 );
              
              __LINE__ = 0;
              Monster.prototype.attack = function attack( target ) {
                try {
                  __LINE__ = 0;
                  log( 'The monster attacks '+target );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              Monster.prototype.isAlive = function isAlive() {
                try {
                  __LINE__ = 23;
                  return Runtime.getPrivateRecord( this ).health>0;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              Monster.prototype.health = function health( value ) {
                try {
                  __LINE__ = 0;
                  if ( value<0 ){
                    __LINE__ = 0;
                    throw new Error( 'Health must be non-negative.' );
                  };
                  
                  __LINE__ = 0;
                  Runtime.getPrivateRecord( this ).health = value;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 38;
              Monster.prototype.numAttacks = 0;
              
              __LINE__ = 43;
              Runtime.constant( Monster.prototype,'attackMessage','The monster hits you!' );
              
              __LINE__ = 44;
              Runtime.constant( Monster,'DEFAULT_LIFE',100 );
              
              __LINE__ = 0;
              Runtime.createUnenumProp( Monster.prototype,"constructor",constructor );
              __LINE__ = 0;
              return Monster;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })();
      
      __LINE__ = 47;
      var monster = new Monster( "slime",100 );
      
      __LINE__ = 48;
      Runtime.assert( true,monster.isAlive(),"monster.isAlive()",48,'./class_test.js' );
      
      __LINE__ = 49;
      Runtime.assert( 0,monster.numAttacks,"monster.numAttacks",49,'./class_test.js' );
      
      __LINE__ = 50;
      Runtime.assert( 100,Monster.DEFAULT_LIFE,"Monster.DEFAULT_LIFE",50,'./class_test.js' );
      
      __LINE__ = 51;
      Runtime.assert( undefined,Monster.health,"Monster.health",51,'./class_test.js' );
      
      __LINE__ = 52;
      var BaseTest = ( function () {
            try {
              __LINE__ = 0;
              var _mochaPrivateHolder = function (){};
              
              __LINE__ = 52;
              function BaseTest() {
                try {
                  __LINE__ = 0;
                  Runtime.createPrivateRecord( this,_mochaPrivateHolder );
                  
                  __LINE__ = 0;
                  constructor.apply( this,arguments );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              function constructor( _mochaLocalTmp2,_mochaLocalTmp3,_mochaLocalTmp4 ) {
                try {
                  __LINE__ = 0;
                  this.name = _mochaLocalTmp2 || 200;
                  
                  __LINE__ = 0;
                  Runtime.getPrivateRecord( this ).addr = _mochaLocalTmp3 || "tokyo";
                  
                  __LINE__ = 0;
                  Runtime.getPrivateRecord( this ).age = _mochaLocalTmp4;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              __LINE__ = 0;
              Runtime.createUnenumProp( constructor,"__harmony_class__",1 );
              
              __LINE__ = 0;
              BaseTest.prototype.getName = function getName() {
                try {
                  __LINE__ = 55;
                  return "hogehoge";
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              BaseTest.getName = function getName() {
                try {
                  __LINE__ = 57;
                  return "static hogehoge";
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              Runtime.createUnenumProp( BaseTest.prototype,"constructor",constructor );
              __LINE__ = 0;
              return BaseTest;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })();
      
      __LINE__ = 60;
      var DeriveTest = ( function () {
            try {
              __LINE__ = 0;
              var _mochaPrivateHolder = function (){};
              
              __LINE__ = 60;
              function DeriveTest() {
                try {
                  __LINE__ = 0;
                  Runtime.createPrivateRecord( this,_mochaPrivateHolder );
                  
                  __LINE__ = 0;
                  constructor.apply( this,arguments );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              var _mochaLocalTmp6 = BaseTest;
              
              __LINE__ = 60;
              Runtime.extendClass( DeriveTest,_mochaLocalTmp6 );
              
              __LINE__ = 0;
              var _mochaSuper = Runtime.getSuper( _mochaLocalTmp6 );
              
              function constructor() {
                try {
                  __LINE__ = 0;
                  _mochaSuper.constructor.call( this );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              __LINE__ = 0;
              Runtime.createUnenumProp( constructor,"__harmony_class__",1 );
              
              __LINE__ = 0;
              _mochaPrivateHolder.prototype.getName = function getName() {
                try {
                  __LINE__ = 65;
                  return _mochaSuper.getName.constructor.call( this );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              Runtime.createUnenumProp( DeriveTest.prototype,"constructor",constructor );
              __LINE__ = 0;
              return DeriveTest;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })();
      
      __LINE__ = 70;
      var Derive2 = ( function () {
            try {
              __LINE__ = 0;
              var _mochaPrivateHolder = function (){};
              
              __LINE__ = 70;
              function Derive2() {
                try {
                  __LINE__ = 0;
                  Runtime.createPrivateRecord( this,_mochaPrivateHolder );
                  
                  __LINE__ = 0;
                  constructor.apply( this,arguments );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              var _mochaLocalTmp8 = DeriveTest;
              
              __LINE__ = 70;
              Runtime.extendClass( Derive2,_mochaLocalTmp8 );
              
              __LINE__ = 0;
              var _mochaSuper = Runtime.getSuper( _mochaLocalTmp8 );
              
              function constructor() {
                try {
                  __LINE__ = 71;
                  return _mochaSuper.constructor.call( this );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              __LINE__ = 0;
              Runtime.createUnenumProp( constructor,"__harmony_class__",1 );
              
              __LINE__ = 0;
              Derive2.prototype.getAddr = function getAddr() {
                try {
                  __LINE__ = 0;
                  return Runtime.getPrivateRecord( this ).addr;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              Runtime.createUnenumProp( Derive2.prototype,"constructor",constructor );
              __LINE__ = 0;
              return Derive2;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })();
      
      __LINE__ = 76;
      var TestClass = ( function () {
            try {
              __LINE__ = 0;
              var _mochaPrivateHolder = function (){};
              
              __LINE__ = 85;
              function _mochaLocalTmp10() {
                try {
                  __LINE__ = 0;
                  Runtime.createPrivateRecord( this,_mochaPrivateHolder );
                  
                  __LINE__ = 0;
                  constructor.apply( this,arguments );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              function constructor( _mochaLocalTmp11,_mochaLocalTmp12 ) {
                try {
                  __LINE__ = 0;
                  Runtime.getPrivateRecord( this )._name = _mochaLocalTmp11 || "test";
                  
                  __LINE__ = 0;
                  Runtime.getPrivateRecord( this )._age = _mochaLocalTmp12 || 20;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              __LINE__ = 0;
              Runtime.createUnenumProp( constructor,"__harmony_class__",1 );
              
              __LINE__ = 0;
              _mochaLocalTmp10.prototype.getName = function getName() {
                try {
                  __LINE__ = 0;
                  return Runtime.getPrivateRecord( this )._name;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              _mochaLocalTmp10.prototype.getAge = function getAge() {
                try {
                  __LINE__ = 0;
                  return Runtime.getPrivateRecord( this )._age;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 80;
              _mochaPrivateHolder.prototype.Inner = ( function () {
                try {
                  __LINE__ = 0;
                  var _mochaPrivateHolder = function (){};
                  
                  __LINE__ = 80;
                  function Inner() {
                    try {
                      __LINE__ = 0;
                      Runtime.createPrivateRecord( this,_mochaPrivateHolder );
                      
                      __LINE__ = 0;
                      constructor.apply( this,arguments );
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  };
                  
                  function constructor(){}
                  __LINE__ = 0;
                  Runtime.createUnenumProp( constructor,"__harmony_class__",1 );
                  
                  __LINE__ = 0;
                  Runtime.createUnenumProp( Inner.prototype,"constructor",constructor );
                  __LINE__ = 0;
                  return Inner;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              })();
              
              __LINE__ = 0;
              Runtime.createUnenumProp( _mochaLocalTmp10.prototype,"constructor",constructor );
              __LINE__ = 0;
              return _mochaLocalTmp10;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })();
      
      __LINE__ = 85;
      Runtime.assert( true,new DeriveTest().getName() === "hogehoge","new DeriveTest().getName() === \"hogehoge\"",85,'./class_test.js' );
      
      __LINE__ = 86;
      Runtime.assert( true,DeriveTest.getName() === "static hogehoge","DeriveTest.getName() === \"static hogehoge\"",86,'./class_test.js' );
      
      __LINE__ = 87;
      Runtime.assert( true,new Derive2().getAddr() === "tokyo","new Derive2().getAddr() === \"tokyo\"",87,'./class_test.js' );
      
      __LINE__ = 88;
      var instance = new TestClass();
      
      __LINE__ = 89;
      Runtime.assert( true,instance.getName() === "test","instance.getName() === \"test\"",89,'./class_test.js' );
      
      __LINE__ = 90;
      Runtime.assert( true,instance.getAge() === 20,"instance.getAge() === 20",90,'./class_test.js' );
      
      __LINE__ = 0;
      var TestTrait =  {
            _mochaTraitPrivate :  {
              
            },
            _mochaTraitPublic :  {
              testm1 : function testm1(  ) {
                try {
                  __LINE__ = 0;
                  var arg = Runtime.toArray( arguments,0 );
                  __LINE__ = 94;
                  return arg[0];
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
            },
            _mochaRequires :  {
              doTestm1 : true
            },
            _mochaTraitMark : true
          };
      
      __LINE__ = 0;
      var TestTrait2 =  {
            _mochaTraitPrivate :  {
              
            },
            _mochaTraitPublic :  {
              testm2 : function testm2(  ) {
                try {
                  __LINE__ = 0;
                  var arg = Runtime.toArray( arguments,0 );
                  __LINE__ = 99;
                  return arg[0];
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              },
              testm3 : function testm3() {
                try {
                  __LINE__ = 100;
                  return "ok";
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
            },
            _mochaRequires :  {
              doTestm2 : true
            },
            _mochaTraitMark : true
          };
      
      __LINE__ = 103;
      var MixinTest = ( function () {
            try {
              __LINE__ = 0;
              var _mochaPrivateHolder = function (){};
              
              __LINE__ = 103;
              function MixinTest() {
                try {
                  __LINE__ = 0;
                  Runtime.createPrivateRecord( this,_mochaPrivateHolder );
                  
                  __LINE__ = 0;
                  constructor.apply( this,arguments );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              function constructor(){}
              __LINE__ = 0;
              Runtime.createUnenumProp( constructor,"__harmony_class__",1 );
              
              __LINE__ = 0;
              MixinTest.prototype.doTestm1 = function doTestm1() {
                try {
                  __LINE__ = 104;
                  return "aaa";
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              MixinTest.prototype.doTestm2 = function doTestm2() {
                try {
                  __LINE__ = 106;
                  return "bbb";
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              Runtime.classMixin( MixinTest,_mochaPrivateHolder,TestTrait, {
                testm1 : "m1"
              },{});
              
              __LINE__ = 0;
              Runtime.classMixin( MixinTest,_mochaPrivateHolder,TestTrait2,{}, {
                testm2 : true,
                testm3 : true
              });
              
              __LINE__ = 0;
              Runtime.checkRequirements( MixinTest,_mochaPrivateHolder,[TestTrait,TestTrait2],'./class_test.js',107 );
              
              __LINE__ = 0;
              Runtime.createUnenumProp( MixinTest.prototype,"constructor",constructor );
              __LINE__ = 0;
              return MixinTest;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })();
      
      __LINE__ = 109;
      var instance2 = new MixinTest();
      
      __LINE__ = 110;
      Runtime.assert( true,instance2.m1( "foo" ) === "foo","instance2.m1( \"foo\" ) === \"foo\"",110,'./class_test.js' );
      
      __LINE__ = 111;
      Runtime.assert( true,instance2.m2 === undefined,"instance2.m2 === undefined",111,'./class_test.js' );
    } catch( e ){
      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  })();
})();
