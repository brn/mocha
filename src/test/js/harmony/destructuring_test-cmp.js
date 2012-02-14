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
            privateRecord.set( self,new privateHolder );
          };
          
          getPrivateRecord = function ( self ) {
            if ( privateRecord.has( self ) ){
              return privateRecord.get( self );
            };
          };
        } else {
          var _uid = ( new Date() );
          
          privateRecord = {};
          
          createPrivateRecord = function ( self,privateHolder ) {
            if ( !self.__typeid__ ){
              var id = _uid ++ ;
              
              createUnenumProp( self,"__typeid__",id );
              
              privateRecord[id] = new privateHolder;
            };
          };
          
          getPrivateRecord = function ( self ) {
            if ( self.__typeid__ ){
              return privateRecord[self.__typeid__];
            };
          };
          if ( "addEventListener" in document ){
            window.addEventListener( "unload",
            function () {
              for ( var i in privateRecord ){
                delete privateRecord[i];
              };
            },false);
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
      var __FILE__ = "/Users/aono_taketoshi/github/mocha/src/test/js/harmony/destructuring_test.js",
          __LINE__ = 0;
      __LINE__ = 2;
      _mochaGlobalExport['./destructuring_test.js'] = {};
      
      __LINE__ = 3;
      var _mochaGlobalAlias = _mochaGlobalExport['./destructuring_test.js'];
      
      __LINE__ = 2;
      var object =  {
            value1 : 100,
            value2 :  {
              value3 : 100
            },
            value4 : [100,200,300],
            value5 :  {
              value6 : [ {
                value7 : 100
              }]
            },
            "@value" :  {
              strvalue : 100
            }
          },
          array = [ {
            value1 : 100
          },200, {
            value2 : 100
          }, {
            "value3" : 100
          }, {
            value4 :  {
              value5 : [100,200]
            }
          }];
      
      __LINE__ = 0;
      ( function () {
        try {
          __LINE__ = 18;
          var _mochaLocalTmp0 = object,
              value1 = _mochaLocalTmp0.value1,
              value3 = _mochaLocalTmp0.value2 && _mochaLocalTmp0.value2.value3?_mochaLocalTmp0.value2.value3 : undefined,
              value5_ = _mochaLocalTmp0.value4 && _mochaLocalTmp0.value4[0]?_mochaLocalTmp0.value4[0] : undefined,
              value6_ = _mochaLocalTmp0.value4 && _mochaLocalTmp0.value4[1]?_mochaLocalTmp0.value4[1] : undefined,
              value7_ = _mochaLocalTmp0.value4 && _mochaLocalTmp0.value4[2]?_mochaLocalTmp0.value4[2] : undefined,
              value7 = _mochaLocalTmp0.value5 && _mochaLocalTmp0.value5.value6 && _mochaLocalTmp0.value5.value6[0] && _mochaLocalTmp0.value5.value6[0].value7?_mochaLocalTmp0.value5.value6[0].value7 : undefined,
              strvalue = _mochaLocalTmp0["@value"] && _mochaLocalTmp0["@value"].strvalue?_mochaLocalTmp0["@value"].strvalue : undefined;
          
          __LINE__ = 19;
          Runtime.assert( true,value1 === 100,"value1 === 100",19,'./destructuring_test.js' );
          
          __LINE__ = 20;
          Runtime.assert( true,value3 === 100,"value3 === 100",20,'./destructuring_test.js' );
          
          __LINE__ = 21;
          Runtime.assert( true,value5_ === 100,"value5_ === 100",21,'./destructuring_test.js' );
          
          __LINE__ = 22;
          Runtime.assert( true,value6_ === 200,"value6_ === 200",22,'./destructuring_test.js' );
          
          __LINE__ = 23;
          Runtime.assert( true,value7_ === 300,"value7_ === 300",23,'./destructuring_test.js' );
          
          __LINE__ = 24;
          Runtime.assert( true,value7 === 100,"value7 === 100",24,'./destructuring_test.js' );
          
          __LINE__ = 25;
          Runtime.assert( true,strvalue === 100,"strvalue === 100",25,'./destructuring_test.js' );
          
          __LINE__ = 0;
          var _mochaLocalTmp1;
          
          __LINE__ = 0;
          _mochaLocalTmp1 = object;
          
          __LINE__ = 0;
          value1 = _mochaLocalTmp1.value1;
          
          __LINE__ = 0;
          value3 = _mochaLocalTmp1.value2 && _mochaLocalTmp1.value2.value3?_mochaLocalTmp1.value2.value3 : undefined;
          
          __LINE__ = 0;
          value5_ = _mochaLocalTmp1.value4 && _mochaLocalTmp1.value4[0]?_mochaLocalTmp1.value4[0] : undefined;
          
          __LINE__ = 0;
          value6_ = _mochaLocalTmp1.value4 && _mochaLocalTmp1.value4[1]?_mochaLocalTmp1.value4[1] : undefined;
          
          __LINE__ = 0;
          value7_ = _mochaLocalTmp1.value4 && _mochaLocalTmp1.value4[2]?_mochaLocalTmp1.value4[2] : undefined;
          
          __LINE__ = 0;
          value7 = _mochaLocalTmp1.value5 && _mochaLocalTmp1.value5.value6 && _mochaLocalTmp1.value5.value6[0] && _mochaLocalTmp1.value5.value6[0].value7?_mochaLocalTmp1.value5.value6[0].value7 : undefined;
          
          __LINE__ = 0;
          strvalue = _mochaLocalTmp1["@value"] && _mochaLocalTmp1["@value"].strvalue?_mochaLocalTmp1["@value"].strvalue : undefined;
          
          __LINE__ = 28;
          Runtime.assert( true,value1 === 100,"value1 === 100",28,'./destructuring_test.js' );
          
          __LINE__ = 29;
          Runtime.assert( true,value3 === 100,"value3 === 100",29,'./destructuring_test.js' );
          
          __LINE__ = 30;
          Runtime.assert( true,value5_ === 100,"value5_ === 100",30,'./destructuring_test.js' );
          
          __LINE__ = 31;
          Runtime.assert( true,value6_ === 200,"value6_ === 200",31,'./destructuring_test.js' );
          
          __LINE__ = 32;
          Runtime.assert( true,value7_ === 300,"value7_ === 300",32,'./destructuring_test.js' );
          
          __LINE__ = 33;
          Runtime.assert( true,value7 === 100,"value7 === 100",33,'./destructuring_test.js' );
          
          __LINE__ = 34;
          Runtime.assert( true,strvalue === 100,"strvalue === 100",34,'./destructuring_test.js' );
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      })();
      
      __LINE__ = 0;
      ( function () {
        try {
          __LINE__ = 39;
          var _mochaLocalTmp2 = array,
              value1 = _mochaLocalTmp2[0] && _mochaLocalTmp2[0].value1?_mochaLocalTmp2[0].value1 : undefined,
              arr_value1 = _mochaLocalTmp2[1],
              value2 = _mochaLocalTmp2[2] && _mochaLocalTmp2[2].value2?_mochaLocalTmp2[2].value2 : undefined,
              value3 = _mochaLocalTmp2[3] && _mochaLocalTmp2[3]["value3"]?_mochaLocalTmp2[3]["value3"] : undefined,
              arr_value2 = _mochaLocalTmp2[4] && _mochaLocalTmp2[4].value4 && _mochaLocalTmp2[4].value4.value5 && _mochaLocalTmp2[4].value4.value5[0]?_mochaLocalTmp2[4].value4.value5[0] : undefined,
              arr_value3 = _mochaLocalTmp2[4] && _mochaLocalTmp2[4].value4 && _mochaLocalTmp2[4].value4.value5 && _mochaLocalTmp2[4].value4.value5[1]?_mochaLocalTmp2[4].value4.value5[1] : undefined;
          
          __LINE__ = 40;
          Runtime.assert( true,value1 === 100,"value1 === 100",40,'./destructuring_test.js' );
          
          __LINE__ = 41;
          Runtime.assert( true,arr_value1 === 200,"arr_value1 === 200",41,'./destructuring_test.js' );
          
          __LINE__ = 42;
          Runtime.assert( true,value2 === 100,"value2 === 100",42,'./destructuring_test.js' );
          
          __LINE__ = 43;
          Runtime.assert( true,value3 === 100,"value3 === 100",43,'./destructuring_test.js' );
          
          __LINE__ = 44;
          Runtime.assert( true,arr_value2 === 100,"arr_value2 === 100",44,'./destructuring_test.js' );
          
          __LINE__ = 45;
          Runtime.assert( true,arr_value3 === 200,"arr_value3 === 200",45,'./destructuring_test.js' );
          
          __LINE__ = 0;
          var _mochaLocalTmp3;
          
          __LINE__ = 0;
          _mochaLocalTmp3 = array;
          
          __LINE__ = 0;
          value1 = _mochaLocalTmp3[0] && _mochaLocalTmp3[0].value1?_mochaLocalTmp3[0].value1 : undefined;
          
          __LINE__ = 0;
          arr_value1 = _mochaLocalTmp3[1];
          
          __LINE__ = 0;
          value2 = _mochaLocalTmp3[2] && _mochaLocalTmp3[2].value2?_mochaLocalTmp3[2].value2 : undefined;
          
          __LINE__ = 0;
          value3 = _mochaLocalTmp3[3] && _mochaLocalTmp3[3]["value3"]?_mochaLocalTmp3[3]["value3"] : undefined;
          
          __LINE__ = 0;
          arr_value2 = _mochaLocalTmp3[4] && _mochaLocalTmp3[4].value4 && _mochaLocalTmp3[4].value4.value5 && _mochaLocalTmp3[4].value4.value5[0]?_mochaLocalTmp3[4].value4.value5[0] : undefined;
          
          __LINE__ = 0;
          arr_value3 = _mochaLocalTmp3[4] && _mochaLocalTmp3[4].value4 && _mochaLocalTmp3[4].value4.value5 && _mochaLocalTmp3[4].value4.value5[1]?_mochaLocalTmp3[4].value4.value5[1] : undefined;
          
          __LINE__ = 47;
          Runtime.assert( true,value1 === 100,"value1 === 100",47,'./destructuring_test.js' );
          
          __LINE__ = 48;
          Runtime.assert( true,arr_value1 === 200,"arr_value1 === 200",48,'./destructuring_test.js' );
          
          __LINE__ = 49;
          Runtime.assert( true,value2 === 100,"value2 === 100",49,'./destructuring_test.js' );
          
          __LINE__ = 50;
          Runtime.assert( true,value3 === 100,"value3 === 100",50,'./destructuring_test.js' );
          
          __LINE__ = 51;
          Runtime.assert( true,arr_value2 === 100,"arr_value2 === 100",51,'./destructuring_test.js' );
          
          __LINE__ = 52;
          Runtime.assert( true,arr_value3 === 200,"arr_value3 === 200",52,'./destructuring_test.js' );
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      })();
      
      __LINE__ = 0;
      ( function () {
        try {
          __LINE__ = 56;
          var _mochaLocalTmp4 = array,
              value1 = _mochaLocalTmp4[0] && _mochaLocalTmp4[0].value1?_mochaLocalTmp4[0].value1 : undefined,
              arr_value1 = _mochaLocalTmp4[1],
              value2 = _mochaLocalTmp4[2] && _mochaLocalTmp4[2].value2?_mochaLocalTmp4[2].value2 : undefined,
              value3 = _mochaLocalTmp4[3] && _mochaLocalTmp4[3]["value3"]?_mochaLocalTmp4[3]["value3"] : undefined,
              arr_value2 = _mochaLocalTmp4[4] && _mochaLocalTmp4[4].value4 && _mochaLocalTmp4[4].value4.value5?Runtime.toArray( _mochaLocalTmp4[4].value4.value5,0 ) : undefined;
          
          __LINE__ = 57;
          Runtime.assert( true,value1 === 100,"value1 === 100",57,'./destructuring_test.js' );
          
          __LINE__ = 58;
          Runtime.assert( true,arr_value1 === 200,"arr_value1 === 200",58,'./destructuring_test.js' );
          
          __LINE__ = 59;
          Runtime.assert( true,value2 === 100,"value2 === 100",59,'./destructuring_test.js' );
          
          __LINE__ = 60;
          Runtime.assert( true,value3 === 100,"value3 === 100",60,'./destructuring_test.js' );
          
          __LINE__ = 61;
          Runtime.assert( true,arr_value2[0] === 100,"arr_value2[0] === 100",61,'./destructuring_test.js' );
          
          __LINE__ = 62;
          Runtime.assert( true,arr_value2[1] === 200,"arr_value2[1] === 200",62,'./destructuring_test.js' );
          
          __LINE__ = 63;
          var arr_value4;
          
          __LINE__ = 0;
          var _mochaLocalTmp5;
          
          __LINE__ = 0;
          _mochaLocalTmp5 = array;
          
          __LINE__ = 0;
          value1 = _mochaLocalTmp5[0] && _mochaLocalTmp5[0].value1?_mochaLocalTmp5[0].value1 : undefined;
          
          __LINE__ = 0;
          arr_value1 = _mochaLocalTmp5[1];
          
          __LINE__ = 0;
          value2 = _mochaLocalTmp5[2] && _mochaLocalTmp5[2].value2?_mochaLocalTmp5[2].value2 : undefined;
          
          __LINE__ = 0;
          value3 = _mochaLocalTmp5[3] && _mochaLocalTmp5[3]["value3"]?_mochaLocalTmp5[3]["value3"] : undefined;
          
          __LINE__ = 0;
          arr_value4 = _mochaLocalTmp5[4] && _mochaLocalTmp5[4].value4 && _mochaLocalTmp5[4].value4.value5?Runtime.toArray( _mochaLocalTmp5[4].value4.value5,0 ) : undefined;
          
          __LINE__ = 65;
          Runtime.assert( true,value1 === 100,"value1 === 100",65,'./destructuring_test.js' );
          
          __LINE__ = 66;
          Runtime.assert( true,arr_value1 === 200,"arr_value1 === 200",66,'./destructuring_test.js' );
          
          __LINE__ = 67;
          Runtime.assert( true,value2 === 100,"value2 === 100",67,'./destructuring_test.js' );
          
          __LINE__ = 68;
          Runtime.assert( true,value3 === 100,"value3 === 100",68,'./destructuring_test.js' );
          
          __LINE__ = 69;
          Runtime.assert( true,arr_value4[0] === 100,"arr_value4[0] === 100",69,'./destructuring_test.js' );
          
          __LINE__ = 70;
          Runtime.assert( true,arr_value4[1] === 200,"arr_value4[1] === 200",70,'./destructuring_test.js' );
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      })();
      
      __LINE__ = 0;
      ( function ( _mochaLocalTmp6 ) {
        try {
          __LINE__ = 0;
          var value1 = _mochaLocalTmp6.value1,
              value3 = _mochaLocalTmp6.value2 && _mochaLocalTmp6.value2.value3?_mochaLocalTmp6.value2.value3 : undefined,
              value5_ = _mochaLocalTmp6.value4 && _mochaLocalTmp6.value4[0]?_mochaLocalTmp6.value4[0] : undefined,
              value6_ = _mochaLocalTmp6.value4 && _mochaLocalTmp6.value4[1]?_mochaLocalTmp6.value4[1] : undefined,
              value7_ = _mochaLocalTmp6.value4 && _mochaLocalTmp6.value4[2]?_mochaLocalTmp6.value4[2] : undefined,
              value7 = _mochaLocalTmp6.value5 && _mochaLocalTmp6.value5.value6 && _mochaLocalTmp6.value5.value6[0] && _mochaLocalTmp6.value5.value6[0].value7?_mochaLocalTmp6.value5.value6[0].value7 : undefined,
              strvalue = _mochaLocalTmp6["@value"] && _mochaLocalTmp6["@value"].strvalue?_mochaLocalTmp6["@value"].strvalue : undefined;
          
          __LINE__ = 74;
          Runtime.assert( true,value1 === 100,"value1 === 100",74,'./destructuring_test.js' );
          
          __LINE__ = 75;
          Runtime.assert( true,value3 === 100,"value3 === 100",75,'./destructuring_test.js' );
          
          __LINE__ = 76;
          Runtime.assert( true,value5_ === 100,"value5_ === 100",76,'./destructuring_test.js' );
          
          __LINE__ = 77;
          Runtime.assert( true,value6_ === 200,"value6_ === 200",77,'./destructuring_test.js' );
          
          __LINE__ = 78;
          Runtime.assert( true,value7_ === 300,"value7_ === 300",78,'./destructuring_test.js' );
          
          __LINE__ = 79;
          Runtime.assert( true,value7 === 100,"value7 === 100",79,'./destructuring_test.js' );
          
          __LINE__ = 80;
          Runtime.assert( true,strvalue === 100,"strvalue === 100",80,'./destructuring_test.js' );
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      })( object );
      
      __LINE__ = 0;
      ( function ( _mochaLocalTmp7 ) {
        try {
          __LINE__ = 0;
          var value1 = _mochaLocalTmp7[0] && _mochaLocalTmp7[0].value1?_mochaLocalTmp7[0].value1 : undefined,
              arr_value1 = _mochaLocalTmp7[1],
              value2 = _mochaLocalTmp7[2] && _mochaLocalTmp7[2].value2?_mochaLocalTmp7[2].value2 : undefined,
              value3 = _mochaLocalTmp7[3] && _mochaLocalTmp7[3]["value3"]?_mochaLocalTmp7[3]["value3"] : undefined,
              arr_value2 = _mochaLocalTmp7[4] && _mochaLocalTmp7[4].value4 && _mochaLocalTmp7[4].value4.value5 && _mochaLocalTmp7[4].value4.value5[0]?_mochaLocalTmp7[4].value4.value5[0] : undefined,
              arr_value3 = _mochaLocalTmp7[4] && _mochaLocalTmp7[4].value4 && _mochaLocalTmp7[4].value4.value5 && _mochaLocalTmp7[4].value4.value5[1]?_mochaLocalTmp7[4].value4.value5[1] : undefined;
          
          __LINE__ = 85;
          Runtime.assert( true,value1 === 100,"value1 === 100",85,'./destructuring_test.js' );
          
          __LINE__ = 86;
          Runtime.assert( true,arr_value1 === 200,"arr_value1 === 200",86,'./destructuring_test.js' );
          
          __LINE__ = 87;
          Runtime.assert( true,value2 === 100,"value2 === 100",87,'./destructuring_test.js' );
          
          __LINE__ = 88;
          Runtime.assert( true,value3 === 100,"value3 === 100",88,'./destructuring_test.js' );
          
          __LINE__ = 89;
          Runtime.assert( true,arr_value2 === 100,"arr_value2 === 100",89,'./destructuring_test.js' );
          
          __LINE__ = 90;
          Runtime.assert( true,arr_value3 === 200,"arr_value3 === 200",90,'./destructuring_test.js' );
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      })( array );
      
      __LINE__ = 0;
      ( function ( _mochaLocalTmp8 ) {
        try {
          __LINE__ = 0;
          var value1 = _mochaLocalTmp8[0] && _mochaLocalTmp8[0].value1?_mochaLocalTmp8[0].value1 : undefined,
              arr_value1 = _mochaLocalTmp8[1],
              value2 = _mochaLocalTmp8[2] && _mochaLocalTmp8[2].value2?_mochaLocalTmp8[2].value2 : undefined,
              value3 = _mochaLocalTmp8[3] && _mochaLocalTmp8[3]["value3"]?_mochaLocalTmp8[3]["value3"] : undefined,
              arr_value2 = _mochaLocalTmp8[4] && _mochaLocalTmp8[4].value4 && _mochaLocalTmp8[4].value4.value5?Runtime.toArray( _mochaLocalTmp8[4].value4.value5,0 ) : undefined;
          
          __LINE__ = 95;
          Runtime.assert( true,value1 === 100,"value1 === 100",95,'./destructuring_test.js' );
          
          __LINE__ = 96;
          Runtime.assert( true,arr_value1 === 200,"arr_value1 === 200",96,'./destructuring_test.js' );
          
          __LINE__ = 97;
          Runtime.assert( true,value2 === 100,"value2 === 100",97,'./destructuring_test.js' );
          
          __LINE__ = 98;
          Runtime.assert( true,value3 === 100,"value3 === 100",98,'./destructuring_test.js' );
          
          __LINE__ = 99;
          Runtime.assert( true,arr_value2[0] === 100,"arr_value2[0] === 100",99,'./destructuring_test.js' );
          
          __LINE__ = 100;
          Runtime.assert( true,arr_value2[1] === 200,"arr_value2[1] === 200",100,'./destructuring_test.js' );
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      })( array );
    } catch( e ){
      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  })();
})();
