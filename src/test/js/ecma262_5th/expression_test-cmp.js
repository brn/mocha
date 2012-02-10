(function() {
  var __FILE__ = "Runtime",
      __LINE__ = 0;
  
  var _mochaGlobalExport = {},
      _mochaClassTable = {};
  
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
          Array.prototype.forEach = function ( fn,that ) {
            var iter = -1,
                ta;
            
            if ( that ){
              while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                fn.call( that,ta,iter,this );
              };
            } else {
              while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                fn( ta,iter,this );
              };
            };
          };
        };
        
        if ( !Array.prototype.every ){
          Array.prototype.every = function ( fn,that ) {
            var iter = -1,
                ta;
            
            if ( that ){
              while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                if ( !( fn.call( that,ta,iter,this ) ) ){
                  return false;
                };
              };
            } else {
              while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                if ( !( fn( ta,iter,this ) ) ){
                  return false;
                };
              };
            };
            return true;
          };
        };
        
        if ( !Array.prototype.some ){
          Array.prototype.some = function ( fn,that ) {
            var iter = -1,
                ta;
            
            if ( that ){
              while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                if ( fn.call( that,ta,iter,this ) ){
                  return true;
                };
              };
            } else {
              while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                if ( fn( ta,iter,this ) ){
                  return true;
                };
              };
            };
            return false;
          };
        };
        
        if ( !Array.prototype.filter ){
          Array.prototype.filter = function ( fn,that ) {
            var iter = -1,
                ret = [],
                ta;
            
            if ( that ){
              for ( var i = 0,len = this.length;i<len; ++ i ){
                if ( ( ta = this[i] ) !== null && ta !== undefined ){
                  if ( fn.call( that,ta,i,this ) ){
                    ret[ ++ iter] = ta;
                  };
                };
              };
            } else {
              for ( var i = 0,len = this.length;i<len; ++ i ){
                if ( ( ta = this[i] ) !== null && ta !== undefined ){
                  if ( fn( ta,i,this ) ){
                    ret[ ++ iter] = ta;
                  };
                };
              };
            };
            return ret;
          };
        };
        
        if ( !Array.prototype.indexOf ){
          Array.prototype.indexOf = function ( subject ) {
            var iter = -1,
                index = -1,
                ta;
            
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
          Array.prototype.lastIndexOf = function ( subject ) {
            var iter = this.length,
                index = -1,
                ta;
            
            while ( ( ta = this[ -- iter] ) !== null && ta !== undefined ){
              if ( ta === subject ){
                index = iter;
                break;
              };
            };
            return index;
          };
        };
        
        if ( !Array.prototype.map ){
          Array.prototype.map = function ( fn,that ) {
            var ret = [],
                iter = -1,
                ta;
            
            if ( that ){
              for ( var i = 0,len = this.length;i<len; ++ i ){
                if ( ( ta = this[i] ) !== null && ta !== undefined ){
                  ret[ ++ iter] = fn.call( that,ta,i,this );
                };
              };
            } else {
              for ( var i = 0,len = this.length;i<len; ++ i ){
                if ( ( ta = this[i] ) !== null && ta !== undefined ){
                  ret[ ++ iter] = fn( ta,i,this );
                };
              };
            };
            return ret;
          };
        };
        
        if ( !Array.prototype.reduce ){
          Array.prototype.reduce = function ( fn,initial ) {
            var ret = initial || this[0],
                i = ( initial )?0 : 1,
                ta,
                len;
            
            for ( i , len = this.length;i<len; ++ i ){
              if ( ( ta = this[i] ) !== null && ta !== undefined ){
                ret = fn( ret,ta,i,this );
              };
            };
            return ret;
          };
        };
        
        if ( !Array.prototype.reduceRight ){
          Array.prototype.reduceRight = function ( fn,initial ) {
            var ret = initial || this[this.length-1],
                i = ( initial )?this.length-1 : this.length-2,
                ta;
            
            for ( i;i>-1; -- i ){
              if ( ( ta = this[i] ) !== null && ta !== undefined ){
                ret = fn( ret,ta,i,this );
              };
            };
            return ret;
          };
        };
        
        if ( !Date.prototype.toJSON ){
          Date.prototype.toJSON = function () {
            return '"'+this.getUTCFullYear()+'-'+"0"+( this.getUTCMonth()+1 )+'-'+"0"+( this.getUTCDate()-1 )+'T'+this.getUTCHours()+':'+this.getMinutes()+':'+this.getSeconds()+'.'+this.getUTCMilliseconds()+'"';
          };
        };
        
        if ( !Date.now ){
          Date.now = function () {
            return +new Date();
          };
        };
        
        if ( !Object.keys ){
          Object.keys = function ( obj ) {
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
          var arrayString = "[object Array]";
          
          Array.isArray = function ( arr ) {
            if ( arguments.length === 0 ){
              return false;
            };
            return ( arr )?Object.prototype.toString.call( arr ) === arrayString : false;
          };
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
              if ( "constructor" in obj ){
                return obj.constructor.prototype || {};
              };
            };
        
        var extendClass = _mochaLocalExport.extendClass = ( Runtime.hasProto )?function ( derived,base ) {
              if ( typeof base === 'function' ){
                derived.prototype.__proto__ = base.prototype;
              } else {
                derived.prototype.__proto__ = base.__proto__;
              };
            } : function ( derived,base ) {
              var baseType = typeof base;
              
              if ( baseType === "function" ){
                var inherit = function (){};
                
                inherit.prototype = base.prototype;
                
                derived.prototype = new inherit;
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
              return obj[__ref_iterator__]();
            };
        
        var hasIterator = _mochaLocalExport.hasIterator = function hasIterator( obj ) {
              return __ref_iterator__ in obj;
            };
        
        var rstopIteration = /StopIteration/;
        
        var isStopIteration = _mochaLocalExport.isStopIteration = function isStopIteration( obj ) {
              return obj === StopIteration || rstopIteration.test( obj );
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
      var __FILE__ = "/var/samba/mocha/src/test/js/ecma262_5th/expression_test.js",
          __LINE__ = 0;
      __LINE__ = 2;
      _mochaGlobalExport['./expression_test.js'] = {};
      
      __LINE__ = 3;
      var _mochaGlobalAlias = _mochaGlobalExport['./expression_test.js'];
      
      function objectAndNewTest() {
        try {
          __LINE__ = 2;
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
              __LINE__ = 6;
              return true;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          testObject.testProp.testFn = function () {
            try {
              __LINE__ = 7;
              return false;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          testObject.testProp.testProp.testFn = function () {
            try {
              __LINE__ = 8;
              return 2;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 10;
          Runtime.assert( true,testObject.testFn() === true,"testObject.testFn() === true",10,'./expression_test.js' );
          
          __LINE__ = 11;
          Runtime.assert( true,testObject.testProp.testFn() === false,"testObject.testProp.testFn() === false",11,'./expression_test.js' );
          
          __LINE__ = 12;
          Runtime.assert( true,testObject.testProp.testProp.testFn() === 2,"testObject.testProp.testProp.testFn() === 2",12,'./expression_test.js' );
          
          __LINE__ = 14;
          var highFn = function () {
                try {
                  __LINE__ = 14;
                  return inner1;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
          
          __LINE__ = 15;
          var inner1 = function () {
                try {
                  __LINE__ = 15;
                  return inner2;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
          
          __LINE__ = 16;
          var inner2 = function (){};
          
          __LINE__ = 17;
          var instance = new highFn();
          
          __LINE__ = 18;
          var instance2 = new new highFn();
          
          __LINE__ = 19;
          var instance3 = new new new highFn();
          
          __LINE__ = 20;
          Runtime.assert( true,instance === inner1,"instance === inner1",20,'./expression_test.js' );
          
          __LINE__ = 21;
          Runtime.assert( true,instance2 === inner2,"instance2 === inner2",21,'./expression_test.js' );
          
          __LINE__ = 22;
          Runtime.assert( true,instance3 instanceof inner2,"instance3 instanceof inner2",22,'./expression_test.js' );
          
          __LINE__ = 24;
          var fnObj =  {
                highFn : highFn,
                highFnInner :  {
                  highFn : highFn
                }
              };
          
          __LINE__ = 31;
          var instance4 = new fnObj.highFn();
          
          __LINE__ = 32;
          var instance5 = new new fnObj.highFn();
          
          __LINE__ = 33;
          var instance6 = new new new fnObj.highFn();
          
          __LINE__ = 34;
          Runtime.assert( true,instance4 === inner1,"instance4 === inner1",34,'./expression_test.js' );
          
          __LINE__ = 35;
          Runtime.assert( true,instance5 === inner2,"instance5 === inner2",35,'./expression_test.js' );
          
          __LINE__ = 36;
          Runtime.assert( true,instance6 instanceof inner2,"instance6 instanceof inner2",36,'./expression_test.js' );
          
          __LINE__ = 37;
          var instance7 = new fnObj.highFnInner.highFn();
          
          __LINE__ = 38;
          var instance8 = new new fnObj.highFnInner.highFn();
          
          __LINE__ = 39;
          var instance9 = new new new fnObj.highFnInner.highFn();
          
          __LINE__ = 40;
          Runtime.assert( true,instance7 === inner1,"instance7 === inner1",40,'./expression_test.js' );
          
          __LINE__ = 41;
          Runtime.assert( true,instance8 === inner2,"instance8 === inner2",41,'./expression_test.js' );
          
          __LINE__ = 42;
          Runtime.assert( true,instance9 instanceof inner2,"instance9 instanceof inner2",42,'./expression_test.js' );
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }
      function callExpressionTest() {
        try {
          __LINE__ = 46;
          var highFn = function () {
                try {
                  __LINE__ = 47;
                  return function () {
                    try {
                      __LINE__ = 48;
                      return function () {
                        try {
                          __LINE__ = 49;
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
          
          __LINE__ = 53;
          Runtime.assert( true,highFn()()() === true,"highFn()()() === true",53,'./expression_test.js' );
          
          __LINE__ = 0;
          highFn = function () {
            try {
              __LINE__ = 54;
              return inner1;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 55;
          var inner1 = function () {
                try {
                  __LINE__ = 55;
                  return inner2;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
          
          __LINE__ = 56;
          var inner2 = function (){};
          
          __LINE__ = 57;
          var flg = 1;
          
          __LINE__ = 58;
          var instance = new ( ( flg )?highFn : inner1 );
          
          __LINE__ = 59;
          Runtime.assert( true,instance === inner1,"instance === inner1",59,'./expression_test.js' );
          
          __LINE__ = 60;
          var flg2 = 0;
          
          __LINE__ = 0;
          instance = new ( ( flg2 )?highFn : inner1 );
          
          __LINE__ = 62;
          Runtime.assert( true,instance === inner2,"instance === inner2",62,'./expression_test.js' );
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }
      function binaryExpressionTest() {
        try {
          __LINE__ = 66;
          var item = 100,
              trueValue = true,
              falseValue = false,
              val = 0;
          
          __LINE__ = 70;
          if ( item && trueValue && !falseValue ){
            __LINE__ = 0;
            val = 1;
          };
          
          __LINE__ = 73;
          Runtime.assert( true,val === 1,"val === 1",73,'./expression_test.js' );
          
          __LINE__ = 74;
          if ( ( item && trueValue ) || falseValue ){
            __LINE__ = 0;
            val = 2;
          };
          
          __LINE__ = 77;
          Runtime.assert( true,val === 2,"val === 2",77,'./expression_test.js' );
          
          __LINE__ = 78;
          if ( ( item && falseValue ) || !trueValue ){
            __LINE__ = 0;
            val = 3;
          };
          
          __LINE__ = 81;
          Runtime.assert( false,val === 3,"val === 3",81,'./expression_test.js' );
          
          __LINE__ = 83;
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
          
          __LINE__ = 88;
          Runtime.assert( true,val === 4,"val === 4",88,'./expression_test.js' );
          
          __LINE__ = 90;
          var eq = 0,
              eqVal = 0;
          
          __LINE__ = 92;
          if ( eq == 0 ){
            __LINE__ = 0;
            eqVal = 1;
          };
          
          __LINE__ = 95;
          Runtime.assert( true,eqVal === 1,"eqVal === 1",95,'./expression_test.js' );
          
          __LINE__ = 97;
          if ( eq === 0 ){
            __LINE__ = 0;
            eqVal = 2;
          };
          
          __LINE__ = 100;
          Runtime.assert( true,eqVal === 2,"eqVal === 2",100,'./expression_test.js' );
          
          __LINE__ = 102;
          var bit = 1,
              ret = 0;
          
          __LINE__ = 0;
          ret = bit << 1;
          
          __LINE__ = 105;
          Runtime.assert( true,ret === 2,"ret === 2",105,'./expression_test.js' );
          
          __LINE__ = 0;
          ret = bit >> 1;
          
          __LINE__ = 107;
          Runtime.assert( true,ret === 0,"ret === 0",107,'./expression_test.js' );
          
          __LINE__ = 0;
          ret = bit|2;
          
          __LINE__ = 109;
          Runtime.assert( true,ret === 3,"ret === 3",109,'./expression_test.js' );
          
          __LINE__ = 0;
          bit = 1;
          
          __LINE__ = 0;
          bit <<= 1;
          
          __LINE__ = 113;
          Runtime.assert( true,bit === 2,"bit === 2",113,'./expression_test.js' );
          
          __LINE__ = 0;
          bit = 1;
          
          __LINE__ = 0;
          bit >>= 1;
          
          __LINE__ = 116;
          Runtime.assert( true,bit === 0,"bit === 0",116,'./expression_test.js' );
          
          __LINE__ = 0;
          bit = 1;
          
          __LINE__ = 0;
          bit |= 2;
          
          __LINE__ = 119;
          Runtime.assert( true,bit === 3,"bit === 3",119,'./expression_test.js' );
          
          __LINE__ = 0;
          bit = 10;
          
          __LINE__ = 0;
          ret = bit >>> 2;
          
          __LINE__ = 123;
          Runtime.assert( true,ret === 2,"ret === 2",123,'./expression_test.js' );
          
          __LINE__ = 0;
          bit = 10;
          
          __LINE__ = 0;
          bit >>>= 2;
          
          __LINE__ = 126;
          Runtime.assert( true,bit === 2,"bit === 2",126,'./expression_test.js' );
          
          __LINE__ = 0;
          bit = 3;
          
          __LINE__ = 0;
          ret = bit&1;
          
          __LINE__ = 130;
          Runtime.assert( true,ret === 1,"ret === 1",130,'./expression_test.js' );
          
          __LINE__ = 0;
          bit &= 1;
          
          __LINE__ = 132;
          Runtime.assert( true,bit === 1,"bit === 1",132,'./expression_test.js' );
          
          __LINE__ = 0;
          bit = 2;
          
          __LINE__ = 0;
          ret = bit^1;
          
          __LINE__ = 136;
          Runtime.assert( true,ret === 3,"ret === 3",136,'./expression_test.js' );
          
          __LINE__ = 0;
          bit = 2;
          
          __LINE__ = 0;
          bit ^= 1;
          
          __LINE__ = 139;
          Runtime.assert( true,bit === 3,"bit === 3",139,'./expression_test.js' );
          
          __LINE__ = 141;
          var lt = 0,
              gt = 1,
              cmpVal = 0;
          
          __LINE__ = 145;
          if ( lt>gt ){
            __LINE__ = 0;
            cmpVal = 1;
          };
          
          __LINE__ = 148;
          Runtime.assert( true,cmpVal === 0,"cmpVal === 0",148,'./expression_test.js' );
          
          __LINE__ = 0;
          cmpVal = 0;
          
          __LINE__ = 151;
          if ( lt<gt ){
            __LINE__ = 0;
            cmpVal = 1;
          };
          
          __LINE__ = 154;
          Runtime.assert( true,cmpVal === 1,"cmpVal === 1",154,'./expression_test.js' );
          
          __LINE__ = 0;
          cmpVal = 0;
          
          __LINE__ = 157;
          if ( lt <= gt ){
            __LINE__ = 0;
            cmpVal = 1;
          };
          
          __LINE__ = 160;
          Runtime.assert( true,cmpVal === 1,"cmpVal === 1",160,'./expression_test.js' );
          
          __LINE__ = 0;
          cmpVal = 0;
          
          __LINE__ = 163;
          if ( lt >= gt ){
            __LINE__ = 0;
            cmpVal = 1;
          };
          
          __LINE__ = 166;
          Runtime.assert( false,cmpVal === 1,"cmpVal === 1",166,'./expression_test.js' );
          
          __LINE__ = 0;
          cmpVal = 0;
          
          __LINE__ = 0;
          lt = 1;
          
          __LINE__ = 170;
          if ( lt <= gt ){
            __LINE__ = 0;
            cmpVal = 1;
          };
          
          __LINE__ = 173;
          Runtime.assert( true,cmpVal === 1,"cmpVal === 1",173,'./expression_test.js' );
          
          __LINE__ = 0;
          cmpVal = 1;
          
          __LINE__ = 176;
          if ( lt >= gt ){
            __LINE__ = 0;
            cmpVal = 1;
          };
          
          __LINE__ = 179;
          Runtime.assert( true,cmpVal === 1,"cmpVal === 1",179,'./expression_test.js' );
          
          __LINE__ = 181;
          var pl = 0;
          
          __LINE__ = 0;
          ret = pl+1;
          
          __LINE__ = 183;
          Runtime.assert( true,ret === 1,"ret === 1",183,'./expression_test.js' );
          
          __LINE__ = 185;
          var mi = 1;
          
          __LINE__ = 0;
          ret = mi-1;
          
          __LINE__ = 187;
          Runtime.assert( true,ret === 0,"ret === 0",187,'./expression_test.js' );
          
          __LINE__ = 189;
          var mul = 1;
          
          __LINE__ = 0;
          ret = mul*2;
          
          __LINE__ = 191;
          Runtime.assert( true,ret === 2,"ret === 2",191,'./expression_test.js' );
          
          __LINE__ = 193;
          var div = 2;
          
          __LINE__ = 0;
          ret = div/2;
          
          __LINE__ = 195;
          Runtime.assert( true,ret === 1,"ret === 1",195,'./expression_test.js' );
          
          __LINE__ = 197;
          var mod = 3;
          
          __LINE__ = 0;
          ret = mod%2;
          
          __LINE__ = 199;
          Runtime.assert( true,ret === 1,"ret === 1",199,'./expression_test.js' );
          
          __LINE__ = 0;
          pl = 0;
          
          __LINE__ = 0;
          pl += 1;
          
          __LINE__ = 203;
          Runtime.assert( true,pl === 1,"pl === 1",203,'./expression_test.js' );
          
          __LINE__ = 0;
          mi = 1;
          
          __LINE__ = 0;
          mi -= 1;
          
          __LINE__ = 207;
          Runtime.assert( true,mi === 0,"mi === 0",207,'./expression_test.js' );
          
          __LINE__ = 0;
          mul = 1;
          
          __LINE__ = 0;
          mul *= 2;
          
          __LINE__ = 211;
          Runtime.assert( true,mul === 2,"mul === 2",211,'./expression_test.js' );
          
          __LINE__ = 0;
          div = 2;
          
          __LINE__ = 0;
          div /= 2;
          
          __LINE__ = 215;
          Runtime.assert( true,div === 1,"div === 1",215,'./expression_test.js' );
          
          __LINE__ = 0;
          mod = 3;
          
          __LINE__ = 0;
          mod %= 2;
          
          __LINE__ = 219;
          Runtime.assert( true,mod === 1,"mod === 1",219,'./expression_test.js' );
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }
      function postfixExpressionTest() {
        try {
          __LINE__ = 223;
          var add = 0;
          
          __LINE__ = 0;
          add ++ ;
          
          __LINE__ = 225;
          Runtime.assert( true,add === 1,"add === 1",225,'./expression_test.js' );
          
          __LINE__ = 227;
          var sub = 1;
          
          __LINE__ = 0;
          sub -- ;
          
          __LINE__ = 229;
          Runtime.assert( true,sub === 0,"sub === 0",229,'./expression_test.js' );
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }
      function unaryExpressionTest() {
        try {
          __LINE__ = 233;
          var strNum = "1",
              ret = +strNum;
          
          __LINE__ = 235;
          Runtime.assert( true,ret === 1,"ret === 1",235,'./expression_test.js' );
          
          __LINE__ = 0;
          ret = -strNum;
          
          __LINE__ = 238;
          Runtime.assert( true,ret === -1,"ret === -1",238,'./expression_test.js' );
          
          __LINE__ = 240;
          var num = -5;
          
          __LINE__ = 0;
          ret = ~num;
          
          __LINE__ = 242;
          Runtime.assert( true,ret === 4,"ret === 4",242,'./expression_test.js' );
          
          __LINE__ = 244;
          var flg = true;
          
          __LINE__ = 0;
          ret = !flg;
          
          __LINE__ = 246;
          Runtime.assert( true,ret === false,"ret === false",246,'./expression_test.js' );
          
          __LINE__ = 0;
          ret = !!flg;
          
          __LINE__ = 249;
          Runtime.assert( true,ret === true,"ret === true",249,'./expression_test.js' );
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }
      function memberExpressionTest() {
        try {
          __LINE__ = 253;
          var test =  {
                test2 :  {
                  "@test" :  {
                    0 :  {
                      "1" : function () {
                        try {
                          __LINE__ = 258;
                          return function () {
                            try {
                              __LINE__ = 258;
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
          
          __LINE__ = 264;
          Runtime.assert( true,test["test2"]["@test"]["0"]["1"]()() === 1,"test[\"test2\"][\"@test\"][\"0\"][\"1\"]()() === 1",264,'./expression_test.js' );
          
          __LINE__ = 265;
          Runtime.assert( true,test.test2["@test"][0]["1"]()() === 1,"test.test2[\"@test\"][0][\"1\"]()() === 1",265,'./expression_test.js' );
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }
      function expressionTest() {
        try {
          __LINE__ = 269;
          var exp = function () {
                try {
                  __LINE__ = 270;
                  return 1;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }();
          
          __LINE__ = 272;
          Runtime.assert( true,exp === 1,"exp === 1",272,'./expression_test.js' );
          
          __LINE__ = 274;
          var a,
              b,
              c;
          
          __LINE__ = 0;
          exp = ( a = 0 , b = 1 , c = 2 );
          
          __LINE__ = 276;
          Runtime.assert( true,a === 0,"a === 0",276,'./expression_test.js' );
          
          __LINE__ = 277;
          Runtime.assert( true,b === 1,"b === 1",277,'./expression_test.js' );
          
          __LINE__ = 278;
          Runtime.assert( true,c === 2,"c === 2",278,'./expression_test.js' );
          
          __LINE__ = 279;
          Runtime.assert( true,exp === 2,"exp === 2",279,'./expression_test.js' );
          
          __LINE__ = 0;
          ( function () {
            try {
              __LINE__ = 0;
              exp = 10;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })();
          
          __LINE__ = 285;
          Runtime.assert( true,exp === 10,"exp === 10",285,'./expression_test.js' );
          
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
              __LINE__ = 289;
              return 100;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })(),function () {
            try {
              __LINE__ = 289;
              return 200;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }());
          
          __LINE__ = 291;
          Runtime.assert( true,exp === 300,"exp === 300",291,'./expression_test.js' );
          
          __LINE__ = 0;
          !function () {
            try {
              __LINE__ = 0;
              exp = 1;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }();
          
          __LINE__ = 296;
          Runtime.assert( true,exp === 1,"exp === 1",296,'./expression_test.js' );
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }
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
    } catch( e ){
      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  })();
})();
