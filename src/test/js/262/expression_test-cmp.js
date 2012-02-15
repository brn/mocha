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
        
        var traitMixin = _mochaLocalExport.traitMixin = function traitMixin( dest,source ) {
              if ( !dest._mochaTraitMark || !source._mochaTraitMark ){
                
              } else {
                var destTraitPrivate = dest._mochaTraitPrivate,
                    sourceTraitPrivate = source._mochaTraitPrivate,
                    destTraitPublic = dest._mochaTraitPublic,
                    sourceTraitPublic = source._mochaTraitPublic;
                
                for ( var i in sourceTraitPrivate ){
                  destTraitPrivate[i] = sourceTraitPrivate[i];
                };
                
                for ( i in sourceTraitPublic ){
                  destTraitPublic[i] = sourceTraitPublic[i];
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
      var __FILE__ = "/Users/aono_taketoshi/github/mocha/src/test/js/262/expression_test.js",
          __LINE__ = 0;
      __LINE__ = 2;
      _mochaGlobalExport['./expression_test.js'] = {};
      
      __LINE__ = 3;
      var _mochaGlobalAlias = _mochaGlobalExport['./expression_test.js'];
      
      __LINE__ = 0;
      /aaaa/.test( "aaaa" );
      
      function parseTest() {
        try {
          __LINE__ = 3;
          var x = .200*10;
          
          __LINE__ = 4;
          Runtime.assert( true,x === 2,"x === 2",4,'./expression_test.js' );
          
          __LINE__ = 0;
          x = function () {
            try {
              __LINE__ = 7;
              return .200*10;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 9;
          Runtime.assert( true,x() === 2,"x() === 2",9,'./expression_test.js' );
          
          __LINE__ = 0;
          x = function () {
            try {
              __LINE__ = 12;
              return /aaa/;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 14;
          Runtime.assert( true,Object.prototype.toString.call( x() ) === "[object RegExp]","Object.prototype.toString.call( x() ) === \"[object RegExp]\"",14,'./expression_test.js' );
          
          __LINE__ = 15;
          Runtime.assert( true,/aaa/.test( "aaa" ) === true,"/aaa/.test( \"aaa\" ) === true",15,'./expression_test.js' );
          
          __LINE__ = 16;
          Runtime.assert( true,.200*10 === 2,".200*10 === 2",16,'./expression_test.js' );
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }
      function objectAndNewTest() {
        try {
          __LINE__ = 19;
          var testObject = {};
          
          __LINE__ = 0;
          testObject.testProp = {};
          
          __LINE__ = 0;
          testObject.testProp.testProp = {};
          
          __LINE__ = 0;
          testObject.testProp.testProp.testProp = {};
          
          __LINE__ = 0;
          testObject.testFn = function () {
            try {
              __LINE__ = 23;
              return true;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          testObject.testProp.testFn = function () {
            try {
              __LINE__ = 24;
              return false;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          testObject.testProp.testProp.testFn = function () {
            try {
              __LINE__ = 25;
              return 2;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 27;
          Runtime.assert( true,testObject.testFn() === true,"testObject.testFn() === true",27,'./expression_test.js' );
          
          __LINE__ = 28;
          Runtime.assert( true,testObject.testProp.testFn() === false,"testObject.testProp.testFn() === false",28,'./expression_test.js' );
          
          __LINE__ = 29;
          Runtime.assert( true,testObject.testProp.testProp.testFn() === 2,"testObject.testProp.testProp.testFn() === 2",29,'./expression_test.js' );
          
          __LINE__ = 31;
          var highFn = function () {
                try {
                  __LINE__ = 31;
                  return inner1;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
          
          __LINE__ = 32;
          var inner1 = function () {
                try {
                  __LINE__ = 32;
                  return inner2;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
          
          __LINE__ = 33;
          var inner2 = function (){};
          
          __LINE__ = 34;
          var instance = new highFn();
          
          __LINE__ = 35;
          var instance2 = new new highFn();
          
          __LINE__ = 36;
          var instance3 = new new new highFn();
          
          __LINE__ = 37;
          Runtime.assert( true,instance === inner1,"instance === inner1",37,'./expression_test.js' );
          
          __LINE__ = 38;
          Runtime.assert( true,instance2 === inner2,"instance2 === inner2",38,'./expression_test.js' );
          
          __LINE__ = 39;
          Runtime.assert( true,instance3 instanceof inner2,"instance3 instanceof inner2",39,'./expression_test.js' );
          
          __LINE__ = 41;
          var fnObj =  {
                highFn : highFn,
                highFnInner :  {
                  highFn : highFn
                }
              };
          
          __LINE__ = 48;
          var instance4 = new fnObj.highFn();
          
          __LINE__ = 49;
          var instance5 = new new fnObj.highFn();
          
          __LINE__ = 50;
          var instance6 = new new new fnObj.highFn();
          
          __LINE__ = 51;
          Runtime.assert( true,instance4 === inner1,"instance4 === inner1",51,'./expression_test.js' );
          
          __LINE__ = 52;
          Runtime.assert( true,instance5 === inner2,"instance5 === inner2",52,'./expression_test.js' );
          
          __LINE__ = 53;
          Runtime.assert( true,instance6 instanceof inner2,"instance6 instanceof inner2",53,'./expression_test.js' );
          
          __LINE__ = 54;
          var instance7 = new fnObj.highFnInner.highFn();
          
          __LINE__ = 55;
          var instance8 = new new fnObj.highFnInner.highFn();
          
          __LINE__ = 56;
          var instance9 = new new new fnObj.highFnInner.highFn();
          
          __LINE__ = 57;
          Runtime.assert( true,instance7 === inner1,"instance7 === inner1",57,'./expression_test.js' );
          
          __LINE__ = 58;
          Runtime.assert( true,instance8 === inner2,"instance8 === inner2",58,'./expression_test.js' );
          
          __LINE__ = 59;
          Runtime.assert( true,instance9 instanceof inner2,"instance9 instanceof inner2",59,'./expression_test.js' );
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }
      function callExpressionTest() {
        try {
          __LINE__ = 63;
          var highFn = function () {
                try {
                  __LINE__ = 64;
                  return function () {
                    try {
                      __LINE__ = 65;
                      return function () {
                        try {
                          __LINE__ = 66;
                          return true;
                        } catch( e ){
                          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      };
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  };
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
          
          __LINE__ = 70;
          Runtime.assert( true,highFn()()() === true,"highFn()()() === true",70,'./expression_test.js' );
          
          __LINE__ = 0;
          highFn = function () {
            try {
              __LINE__ = 71;
              return inner1;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 72;
          var inner1 = function () {
                try {
                  __LINE__ = 72;
                  return inner2;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
          
          __LINE__ = 73;
          var inner2 = function (){};
          
          __LINE__ = 74;
          var flg = 1;
          
          __LINE__ = 75;
          var instance = new ( ( flg )?highFn : inner1 );
          
          __LINE__ = 76;
          Runtime.assert( true,instance === inner1,"instance === inner1",76,'./expression_test.js' );
          
          __LINE__ = 77;
          var flg2 = 0;
          
          __LINE__ = 0;
          instance = new ( ( flg2 )?highFn : inner1 );
          
          __LINE__ = 79;
          Runtime.assert( true,instance === inner2,"instance === inner2",79,'./expression_test.js' );
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }
      function binaryExpressionTest() {
        try {
          __LINE__ = 83;
          var item = 100,
              trueValue = true,
              falseValue = false,
              val = 0;
          
          __LINE__ = 87;
          if ( item && trueValue && !falseValue ){
            __LINE__ = 0;
            val = 1;
          };
          
          __LINE__ = 90;
          Runtime.assert( true,val === 1,"val === 1",90,'./expression_test.js' );
          
          __LINE__ = 91;
          if ( ( item && trueValue ) || falseValue ){
            __LINE__ = 0;
            val = 2;
          };
          
          __LINE__ = 94;
          Runtime.assert( true,val === 2,"val === 2",94,'./expression_test.js' );
          
          __LINE__ = 95;
          if ( ( item && falseValue ) || !trueValue ){
            __LINE__ = 0;
            val = 3;
          };
          
          __LINE__ = 98;
          Runtime.assert( false,val === 3,"val === 3",98,'./expression_test.js' );
          
          __LINE__ = 100;
          var changeVal = function ( value ) {
                try {
                  __LINE__ = 0;
                  val = value;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
          
          __LINE__ = 0;
          ( item ) && ( trueValue ) && ( !falseValue ) && ( changeVal( 4 ) );
          
          __LINE__ = 105;
          Runtime.assert( true,val === 4,"val === 4",105,'./expression_test.js' );
          
          __LINE__ = 107;
          var eq = 0,
              eqVal = 0;
          
          __LINE__ = 109;
          if ( eq == 0 ){
            __LINE__ = 0;
            eqVal = 1;
          };
          
          __LINE__ = 112;
          Runtime.assert( true,eqVal === 1,"eqVal === 1",112,'./expression_test.js' );
          
          __LINE__ = 114;
          if ( eq === 0 ){
            __LINE__ = 0;
            eqVal = 2;
          };
          
          __LINE__ = 117;
          Runtime.assert( true,eqVal === 2,"eqVal === 2",117,'./expression_test.js' );
          
          __LINE__ = 119;
          var bit = 1,
              ret = 0;
          
          __LINE__ = 0;
          ret = bit << 1;
          
          __LINE__ = 122;
          Runtime.assert( true,ret === 2,"ret === 2",122,'./expression_test.js' );
          
          __LINE__ = 0;
          ret = bit >> 1;
          
          __LINE__ = 124;
          Runtime.assert( true,ret === 0,"ret === 0",124,'./expression_test.js' );
          
          __LINE__ = 0;
          ret = bit|2;
          
          __LINE__ = 126;
          Runtime.assert( true,ret === 3,"ret === 3",126,'./expression_test.js' );
          
          __LINE__ = 0;
          bit = 1;
          
          __LINE__ = 0;
          bit <<= 1;
          
          __LINE__ = 130;
          Runtime.assert( true,bit === 2,"bit === 2",130,'./expression_test.js' );
          
          __LINE__ = 0;
          bit = 1;
          
          __LINE__ = 0;
          bit >>= 1;
          
          __LINE__ = 133;
          Runtime.assert( true,bit === 0,"bit === 0",133,'./expression_test.js' );
          
          __LINE__ = 0;
          bit = 1;
          
          __LINE__ = 0;
          bit |= 2;
          
          __LINE__ = 136;
          Runtime.assert( true,bit === 3,"bit === 3",136,'./expression_test.js' );
          
          __LINE__ = 0;
          bit = 10;
          
          __LINE__ = 0;
          ret = bit >>> 2;
          
          __LINE__ = 140;
          Runtime.assert( true,ret === 2,"ret === 2",140,'./expression_test.js' );
          
          __LINE__ = 0;
          bit = 10;
          
          __LINE__ = 0;
          bit >>>= 2;
          
          __LINE__ = 143;
          Runtime.assert( true,bit === 2,"bit === 2",143,'./expression_test.js' );
          
          __LINE__ = 0;
          bit = 3;
          
          __LINE__ = 0;
          ret = bit&1;
          
          __LINE__ = 147;
          Runtime.assert( true,ret === 1,"ret === 1",147,'./expression_test.js' );
          
          __LINE__ = 0;
          bit &= 1;
          
          __LINE__ = 149;
          Runtime.assert( true,bit === 1,"bit === 1",149,'./expression_test.js' );
          
          __LINE__ = 0;
          bit = 2;
          
          __LINE__ = 0;
          ret = bit^1;
          
          __LINE__ = 153;
          Runtime.assert( true,ret === 3,"ret === 3",153,'./expression_test.js' );
          
          __LINE__ = 0;
          bit = 2;
          
          __LINE__ = 0;
          bit ^= 1;
          
          __LINE__ = 156;
          Runtime.assert( true,bit === 3,"bit === 3",156,'./expression_test.js' );
          
          __LINE__ = 158;
          var lt = 0,
              gt = 1,
              cmpVal = 0;
          
          __LINE__ = 162;
          if ( lt>gt ){
            __LINE__ = 0;
            cmpVal = 1;
          };
          
          __LINE__ = 165;
          Runtime.assert( true,cmpVal === 0,"cmpVal === 0",165,'./expression_test.js' );
          
          __LINE__ = 0;
          cmpVal = 0;
          
          __LINE__ = 168;
          if ( lt<gt ){
            __LINE__ = 0;
            cmpVal = 1;
          };
          
          __LINE__ = 171;
          Runtime.assert( true,cmpVal === 1,"cmpVal === 1",171,'./expression_test.js' );
          
          __LINE__ = 0;
          cmpVal = 0;
          
          __LINE__ = 174;
          if ( lt <= gt ){
            __LINE__ = 0;
            cmpVal = 1;
          };
          
          __LINE__ = 177;
          Runtime.assert( true,cmpVal === 1,"cmpVal === 1",177,'./expression_test.js' );
          
          __LINE__ = 0;
          cmpVal = 0;
          
          __LINE__ = 180;
          if ( lt >= gt ){
            __LINE__ = 0;
            cmpVal = 1;
          };
          
          __LINE__ = 183;
          Runtime.assert( false,cmpVal === 1,"cmpVal === 1",183,'./expression_test.js' );
          
          __LINE__ = 0;
          cmpVal = 0;
          
          __LINE__ = 0;
          lt = 1;
          
          __LINE__ = 187;
          if ( lt <= gt ){
            __LINE__ = 0;
            cmpVal = 1;
          };
          
          __LINE__ = 190;
          Runtime.assert( true,cmpVal === 1,"cmpVal === 1",190,'./expression_test.js' );
          
          __LINE__ = 0;
          cmpVal = 1;
          
          __LINE__ = 193;
          if ( lt >= gt ){
            __LINE__ = 0;
            cmpVal = 1;
          };
          
          __LINE__ = 196;
          Runtime.assert( true,cmpVal === 1,"cmpVal === 1",196,'./expression_test.js' );
          
          __LINE__ = 198;
          var pl = 0;
          
          __LINE__ = 0;
          ret = pl+1;
          
          __LINE__ = 200;
          Runtime.assert( true,ret === 1,"ret === 1",200,'./expression_test.js' );
          
          __LINE__ = 202;
          var mi = 1;
          
          __LINE__ = 0;
          ret = mi-1;
          
          __LINE__ = 204;
          Runtime.assert( true,ret === 0,"ret === 0",204,'./expression_test.js' );
          
          __LINE__ = 206;
          var mul = 1;
          
          __LINE__ = 0;
          ret = mul*2;
          
          __LINE__ = 208;
          Runtime.assert( true,ret === 2,"ret === 2",208,'./expression_test.js' );
          
          __LINE__ = 210;
          var div = 2;
          
          __LINE__ = 0;
          ret = div/2;
          
          __LINE__ = 212;
          Runtime.assert( true,ret === 1,"ret === 1",212,'./expression_test.js' );
          
          __LINE__ = 214;
          var mod = 3;
          
          __LINE__ = 0;
          ret = mod%2;
          
          __LINE__ = 216;
          Runtime.assert( true,ret === 1,"ret === 1",216,'./expression_test.js' );
          
          __LINE__ = 0;
          pl = 0;
          
          __LINE__ = 0;
          pl += 1;
          
          __LINE__ = 220;
          Runtime.assert( true,pl === 1,"pl === 1",220,'./expression_test.js' );
          
          __LINE__ = 0;
          mi = 1;
          
          __LINE__ = 0;
          mi -= 1;
          
          __LINE__ = 224;
          Runtime.assert( true,mi === 0,"mi === 0",224,'./expression_test.js' );
          
          __LINE__ = 0;
          mul = 1;
          
          __LINE__ = 0;
          mul *= 2;
          
          __LINE__ = 228;
          Runtime.assert( true,mul === 2,"mul === 2",228,'./expression_test.js' );
          
          __LINE__ = 0;
          div = 2;
          
          __LINE__ = 0;
          div /= 2;
          
          __LINE__ = 232;
          Runtime.assert( true,div === 1,"div === 1",232,'./expression_test.js' );
          
          __LINE__ = 0;
          mod = 3;
          
          __LINE__ = 0;
          mod %= 2;
          
          __LINE__ = 236;
          Runtime.assert( true,mod === 1,"mod === 1",236,'./expression_test.js' );
          
          __LINE__ = 238;
          var obj =  {
                'onmouseenter' : 1,
                'onmouseleave' : 1
              };
          
          __LINE__ = 243;
          var testInAnd = 'onmouseenter' in obj && 'onmouseleave' in obj;
          
          __LINE__ = 245;
          Runtime.assert( true,testInAnd === true,"testInAnd === true",245,'./expression_test.js' );
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }
      function postfixExpressionTest() {
        try {
          __LINE__ = 249;
          var add = 0;
          
          __LINE__ = 0;
          add ++ ;
          
          __LINE__ = 251;
          Runtime.assert( true,add === 1,"add === 1",251,'./expression_test.js' );
          
          __LINE__ = 253;
          var sub = 1;
          
          __LINE__ = 0;
          sub -- ;
          
          __LINE__ = 255;
          Runtime.assert( true,sub === 0,"sub === 0",255,'./expression_test.js' );
          
          __LINE__ = 0;
          add = 0;
          
          __LINE__ = 0;
          sub = add;
          
          __LINE__ = 0;
           ++ sub;
          
          __LINE__ = 260;
          Runtime.assert( true,sub === 1,"sub === 1",260,'./expression_test.js' );
          
          __LINE__ = 0;
          add = 1;
          
          __LINE__ = 0;
          sub = add;
          
          __LINE__ = 0;
           -- sub;
          
          __LINE__ = 265;
          Runtime.assert( true,sub === 0,"sub === 0",265,'./expression_test.js' );
          
          __LINE__ = 0;
          sub = 1;
          
          __LINE__ = 0;
          sub -- ;
          
          __LINE__ = 0;
          add = sub;
          
          __LINE__ = 270;
          Runtime.assert( true,add === 0,"add === 0",270,'./expression_test.js' );
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }
      function unaryExpressionTest() {
        try {
          __LINE__ = 275;
          var strNum = "1",
              ret = +strNum;
          
          __LINE__ = 277;
          Runtime.assert( true,ret === 1,"ret === 1",277,'./expression_test.js' );
          
          __LINE__ = 0;
          ret = -strNum;
          
          __LINE__ = 280;
          Runtime.assert( true,ret === -1,"ret === -1",280,'./expression_test.js' );
          
          __LINE__ = 282;
          var num = -5;
          
          __LINE__ = 0;
          ret = ~num;
          
          __LINE__ = 284;
          Runtime.assert( true,ret === 4,"ret === 4",284,'./expression_test.js' );
          
          __LINE__ = 286;
          var flg = true;
          
          __LINE__ = 0;
          ret = !flg;
          
          __LINE__ = 288;
          Runtime.assert( true,ret === false,"ret === false",288,'./expression_test.js' );
          
          __LINE__ = 0;
          ret = !!flg;
          
          __LINE__ = 291;
          Runtime.assert( true,ret === true,"ret === true",291,'./expression_test.js' );
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }
      function memberExpressionTest() {
        try {
          __LINE__ = 295;
          var test =  {
                test2 :  {
                  "@test" :  {
                    0 :  {
                      "1" : function () {
                        try {
                          __LINE__ = 300;
                          return function () {
                            try {
                              __LINE__ = 300;
                              return 1;
                            } catch( e ){
                              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                            }
                          };
                        } catch( e ){
                          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      }
                    }
                  }
                }
              };
          
          __LINE__ = 306;
          Runtime.assert( true,test["test2"]["@test"]["0"]["1"]()() === 1,"test[\"test2\"][\"@test\"][\"0\"][\"1\"]()() === 1",306,'./expression_test.js' );
          
          __LINE__ = 307;
          Runtime.assert( true,test.test2["@test"][0]["1"]()() === 1,"test.test2[\"@test\"][0][\"1\"]()() === 1",307,'./expression_test.js' );
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }
      function expressionTest() {
        try {
          __LINE__ = 311;
          var exp = function () {
                try {
                  __LINE__ = 312;
                  return 1;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }();
          
          __LINE__ = 314;
          Runtime.assert( true,exp === 1,"exp === 1",314,'./expression_test.js' );
          
          __LINE__ = 316;
          var a,
              b,
              c;
          
          __LINE__ = 0;
          exp = ( a = 0 , b = 1 , c = 2 );
          
          __LINE__ = 318;
          Runtime.assert( true,a === 0,"a === 0",318,'./expression_test.js' );
          
          __LINE__ = 319;
          Runtime.assert( true,b === 1,"b === 1",319,'./expression_test.js' );
          
          __LINE__ = 320;
          Runtime.assert( true,c === 2,"c === 2",320,'./expression_test.js' );
          
          __LINE__ = 321;
          Runtime.assert( true,exp === 2,"exp === 2",321,'./expression_test.js' );
          
          __LINE__ = 0;
          ( function () {
            try {
              __LINE__ = 0;
              exp = 10;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })();
          
          __LINE__ = 327;
          Runtime.assert( true,exp === 10,"exp === 10",327,'./expression_test.js' );
          
          __LINE__ = 0;
          ( function ( a,b ) {
            try {
              __LINE__ = 0;
              exp = a+b;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })( ( function () {
            try {
              __LINE__ = 331;
              return 100;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })(),function () {
            try {
              __LINE__ = 331;
              return 200;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }());
          
          __LINE__ = 333;
          Runtime.assert( true,exp === 300,"exp === 300",333,'./expression_test.js' );
          
          __LINE__ = 0;
          !function () {
            try {
              __LINE__ = 0;
              exp = 1;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }();
          
          __LINE__ = 338;
          Runtime.assert( true,exp === 1,"exp === 1",338,'./expression_test.js' );
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }
      function primaryTest() {
        try {
          __LINE__ = 342;
          var array = [,,,];
          
          __LINE__ = 343;
          Runtime.assert( true,array.length === 3,"array.length === 3",343,'./expression_test.js' );
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }
      __LINE__ = 0;
      parseTest();
      
      __LINE__ = 0;
      objectAndNewTest();
      
      __LINE__ = 0;
      callExpressionTest();
      
      __LINE__ = 0;
      binaryExpressionTest();
      
      __LINE__ = 0;
      postfixExpressionTest();
      
      __LINE__ = 0;
      unaryExpressionTest();
      
      __LINE__ = 0;
      memberExpressionTest();
      
      __LINE__ = 0;
      expressionTest();
      
      __LINE__ = 0;
      primaryTest();
    } catch( e ){
      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  })();
})();
