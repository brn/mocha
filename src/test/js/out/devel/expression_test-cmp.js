!function() {
  var __FILE__ = "Runtime",
      __LINE__ = 0;
  
  __LINE__ = 25;
  var _mochaGlobalExport = {};
  
  __LINE__ = 33;
  ( function ( _mochaLocalTmp0,_mochaLocalTmp1,_mochaLocalTmp2,_mochaLocalTmp3 ) {
    try {
      __LINE__ = 33;
      var stringProto = _mochaLocalTmp0.prototype,
          arrayProto = _mochaLocalTmp1.prototype,
          functionProto = _mochaLocalTmp2.prototype,
          dateProto = _mochaLocalTmp3.prototype;
      
      function builtinTypeError( message ) {
        try {
          try {
            __LINE__ = 36;
            throw new TypeError( message );
          } catch( e ){
            __LINE__ = 38;
            throw new Error( e );
          };
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }
      function callbackCheck( callback,type ) {
        try {
          
          __LINE__ = 43;
          Runtime.assert( true,typeof type === "string","typeof type === \"string\"",43,'./mocha_runtime.js' );
          
          __LINE__ = 44;
          if ( typeof callback !== "function" ){
            
            __LINE__ = 45;
            builtinTypeError( type+" : first argument is not callable" );
          };
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }
      function defineBuiltin( obj,name,value ) {
        try {
          __LINE__ = 49;
          return Object.defineProperty( obj,name, {
            value : value,
            configurable : true,
            enumerable : false,
            writable : true
          });
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }
      __LINE__ = 56;
      if ( !Object.keys ){
        
        __LINE__ = 64;
        Object.keys = function ( obj ) {
          try {
            __LINE__ = 65;
            if ( !obj ){
              
              __LINE__ = 66;
              builtinTypeError( "Object.keys : first arguments is null or not defined." );
            };
            
            __LINE__ = 68;
            var ret = [],
                iter = -1;
            
            __LINE__ = 70;
            for ( var i in obj ){
              
              __LINE__ = 71;
              if ( obj.hasOwnProperty( i ) ){
                
                __LINE__ = 72;
                ret[ ++ iter] = obj[i];
              };
            };
            __LINE__ = 75;
            return ret;
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        };
      };
      
      __LINE__ = 79;
      if ( !Object.preventExtensions ){
        
        __LINE__ = 84;
        Object.preventExtensions = function ( o ) {
          try {
            __LINE__ = 84;
            return o;
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        };
      };
      
      __LINE__ = 87;
      if ( !Object.seal ){
        
        __LINE__ = 92;
        Object.seal = function ( o ) {
          try {
            __LINE__ = 92;
            return o;
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        };
      };
      
      __LINE__ = 95;
      if ( !Object.freeze ){
        
        __LINE__ = 100;
        Object.freeze = function ( o ) {
          try {
            __LINE__ = 100;
            return o;
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        };
      };
      
      __LINE__ = 108;
      var hasRealEcma5 = function () {
            try {
              __LINE__ = 109;
              var ret;
              
              try {
                
                __LINE__ = 111;
                var obj = {};
                
                __LINE__ = 112;
                Object.defineProperty( obj,"test", {
                  configurable : false,
                  writable : false,
                  enumerable : false,
                  value : 0
                });
                
                __LINE__ = 118;
                obj.test = 200;
                
                __LINE__ = 119;
                ret = ( obj.test === 200 )?false : true;
              } catch( e ){
                
                __LINE__ = 121;
                ret = false;
              };
              __LINE__ = 123;
              return ret;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }();
      
      __LINE__ = 126;
      if ( !hasRealEcma5 ){
        
        __LINE__ = 134;
        Object.defineProperty = function ( obj,prop,valobj ) {
          try {
            __LINE__ = 135;
            if ( "value" in valobj ){
              
              __LINE__ = 136;
              obj[prop] = valobj.value;
            };
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        };
      };
      
      __LINE__ = 141;
      if ( !stringProto.trim ){
        
        __LINE__ = 147;
        stringProto.trim = function () {
          try {
            __LINE__ = 147;
            return this.replace( stringProto.trim.rtrim,"" );
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        };
        
        __LINE__ = 149;
        stringProto.trim.rtrim = /^\s*|\s*$/g;
      };
      
      __LINE__ = 153;
      if ( !stringProto.repeat ){
        
        __LINE__ = 154;
        defineBuiltin( stringProto,"repeat",
        function ( num ) {
          try {
            __LINE__ = 154;
            return Array( num+1 ).join( this.toString() );
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        });
      };
      
      __LINE__ = 157;
      if ( !stringProto.startsWith ){
        
        __LINE__ = 158;
        defineBuiltin( stringProto,"startsWith",
        function ( str ) {
          try {
            __LINE__ = 158;
            return !this.indexOf( str );
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        });
      };
      
      __LINE__ = 161;
      if ( !stringProto.endsWith ){
        
        __LINE__ = 162;
        defineBuiltin( stringProto,"endsWith",
        function ( str ) {
          try {
            __LINE__ = 163;
            var t = String( str ),
                index = this.lastIndexOf( t );
            __LINE__ = 165;
            return index >= 0 && index === this.length-t.length;
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        });
      };
      
      __LINE__ = 169;
      if ( !stringProto.contains ){
        
        __LINE__ = 170;
        defineBuiltin( stringProto,"contains",
        function ( str ) {
          try {
            __LINE__ = 170;
            return this.indexOf( str ) !== -1;
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        });
      };
      
      __LINE__ = 173;
      if ( !stringProto.toArray ){
        
        __LINE__ = 174;
        defineBuiltin( stringProto,"toArray",
        function ( str ) {
          try {
            __LINE__ = 174;
            return this.split( "" );
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        });
      };
      
      __LINE__ = 179;
      if ( !functionProto.bind ){
        
        __LINE__ = 189;
        defineBuiltin( functionProto,"bind",
        function () {
          try {
            __LINE__ = 190;
            var argArray = arrayProto.slice.call( arguments ),
                context = argArray.shift(),
                ret = function () {
                  try {
                    __LINE__ = 193;
                    var args = argArray.concat( arrayProto.slice.call( arguments ) );
                    
                    __LINE__ = 194;
                    if ( this !== null && this !== window && this instanceof ret ){
                      __LINE__ = 195;
                      return ret.context.apply( this,args );
                    } else {
                      __LINE__ = 197;
                      return ret.context.apply( context,args );
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
            
            __LINE__ = 201;
            ret.prototype = this.prototype;
            
            __LINE__ = 202;
            ret.context = this;
            __LINE__ = 203;
            return ret;
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        });
      };
      
      __LINE__ = 208;
      if ( !arrayProto.forEach ){
        
        __LINE__ = 222;
        defineBuiltin( arrayProto,"forEach",
        function ( callback,that ) {
          try {
            __LINE__ = 223;
            callbackCheck( callback,"Array.forEach" );
            
            __LINE__ = 224;
            var iter = -1,
                ta;
            
            __LINE__ = 226;
            if ( this === null ){
              
              __LINE__ = 227;
              builtinTypeError( "Array.forEach : this is null or not defined" );
            };
            
            __LINE__ = 229;
            if ( that ){
              
              __LINE__ = 230;
              while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                
                __LINE__ = 231;
                callback.call( that,ta,iter,this );
              };
            } else {
              
              __LINE__ = 234;
              while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                
                __LINE__ = 235;
                callback( ta,iter,this );
              };
            };
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        });
      };
      
      __LINE__ = 241;
      if ( !arrayProto.every ){
        
        __LINE__ = 255;
        defineBuiltin( arrayProto,"every",
        function ( callback,that ) {
          try {
            __LINE__ = 256;
            callbackCheck( callback,"Array.every" );
            
            __LINE__ = 257;
            var iter = -1,
                ta;
            
            __LINE__ = 259;
            if ( this === null ){
              
              __LINE__ = 260;
              builtinTypeError( "Array.every : this is null or not defined" );
            };
            
            __LINE__ = 262;
            if ( that ){
              
              __LINE__ = 263;
              while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                
                __LINE__ = 264;
                if ( !( callback.call( that,ta,iter,this ) ) ){
                  __LINE__ = 265;
                  return false;
                };
              };
            } else {
              
              __LINE__ = 269;
              while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                if ( !( callback( ta,iter,this ) ) ){
                  __LINE__ = 271;
                  return false;
                };
              };
            };
            __LINE__ = 275;
            return true;
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        });
      };
      
      __LINE__ = 279;
      if ( !arrayProto.some ){
        
        __LINE__ = 293;
        defineBuiltin( arrayProto,"some",
        function ( callback,that ) {
          try {
            __LINE__ = 294;
            callbackCheck( callback,"Array.some" );
            
            __LINE__ = 295;
            var iter = -1,
                ta;
            
            __LINE__ = 297;
            if ( this === null ){
              
              __LINE__ = 298;
              builtinTypeError( "Array.some : this is null or not defined" );
            };
            
            __LINE__ = 300;
            if ( that ){
              
              __LINE__ = 301;
              while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                
                __LINE__ = 302;
                if ( callback.call( that,ta,iter,this ) ){
                  __LINE__ = 303;
                  return true;
                };
              };
            } else {
              
              __LINE__ = 307;
              while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                if ( callback( ta,iter,this ) ){
                  __LINE__ = 309;
                  return true;
                };
              };
            };
            __LINE__ = 313;
            return false;
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        });
      };
      
      __LINE__ = 317;
      if ( !arrayProto.filter ){
        
        __LINE__ = 331;
        defineBuiltin( arrayProto,"filter",
        function ( callback,that ) {
          try {
            __LINE__ = 332;
            callbackCheck( callback,"Array.filter" );
            
            __LINE__ = 333;
            var len = this.length,
                iter = -1,
                ret = [],
                ta;
            
            __LINE__ = 337;
            if ( this === null ){
              
              __LINE__ = 338;
              builtinTypeError( "Array.filter : this is null or not defined" );
            };
            
            __LINE__ = 340;
            if ( that ){
              
              __LINE__ = 341;
              for ( var i = 0,len = this.length;i<len; ++ i ){
                
                __LINE__ = 342;
                if ( ( ta = this[i] ) !== null && ta !== undefined ){
                  
                  __LINE__ = 343;
                  if ( callback.call( that,ta,i,this ) ){
                    
                    __LINE__ = 344;
                    ret[ ++ iter] = ta;
                  };
                };
              };
            } else {
              
              __LINE__ = 349;
              for ( var i = 0,len = this.length;i<len; ++ i ){
                if ( ( ta = this[i] ) !== null && ta !== undefined ){
                  if ( callback( ta,i,this ) ){
                    
                    __LINE__ = 352;
                    ret[ ++ iter] = ta;
                  };
                };
              };
            };
            __LINE__ = 357;
            return ret;
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        });
      };
      
      __LINE__ = 361;
      if ( !arrayProto.indexOf ){
        
        __LINE__ = 368;
        defineBuiltin( arrayProto,"indexOf",
        function ( subject,fromIndex ) {
          try {
            __LINE__ = 369;
            var iter = ( fromIndex )?fromIndex-1 : -1,
                index = -1,
                ta;
            
            __LINE__ = 372;
            if ( this === null ){
              
              __LINE__ = 373;
              builtinTypeError( "Array.indexOf : this is null or not defined." );
            };
            
            __LINE__ = 375;
            while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
              
              __LINE__ = 376;
              if ( ta === subject ){
                
                __LINE__ = 377;
                index = iter;
                __LINE__ = 378;
                break;
              };
            };
            __LINE__ = 381;
            return index;
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        });
      };
      
      __LINE__ = 385;
      if ( !arrayProto.lastIndexOf ){
        
        __LINE__ = 393;
        defineBuiltin( arrayProto,"lastIndexOf",
        function ( target,fromIndex ) {
          try {
            __LINE__ = 394;
            var len = this.length,
                iter = ( fromIndex )?fromIndex+1 : len,
                index = -1,
                ta;
            
            __LINE__ = 398;
            if ( this === null ){
              
              __LINE__ = 399;
              builtinTypeError( "Array.lastIndexOf : this is null or not defined." );
            };
            
            __LINE__ = 401;
            while ( ( ta = this[ -- iter] ) !== null && ta !== undefined ){
              
              __LINE__ = 402;
              if ( ta === target ){
                
                __LINE__ = 403;
                index = iter;
                __LINE__ = 404;
                break;
              };
            };
            __LINE__ = 407;
            return index;
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        });
      };
      
      __LINE__ = 413;
      if ( !arrayProto.map ){
        
        __LINE__ = 427;
        defineBuiltin( arrayProto,"map",
        function ( callback,that ) {
          try {
            __LINE__ = 428;
            callbackCheck( callback,"Array.map" );
            
            __LINE__ = 429;
            var ret = [],
                iter = -1,
                len = this.length,
                i = 0,
                ta;
            
            __LINE__ = 434;
            if ( this === null ){
              
              __LINE__ = 435;
              builtinTypeError( "Array.map : this is null or not defined." );
            };
            
            __LINE__ = 437;
            if ( that ){
              
              __LINE__ = 438;
              for ( i;i<len; ++ i ){
                
                __LINE__ = 439;
                if ( ( ta = this[i] ) !== null && ta !== undefined ){
                  
                  __LINE__ = 440;
                  ret[ ++ iter] = callback.call( that,ta,i,this );
                };
              };
            } else {
              
              __LINE__ = 444;
              for ( i;i<len; ++ i ){
                if ( ( ta = this[i] ) !== null && ta !== undefined ){
                  
                  __LINE__ = 446;
                  ret[ ++ iter] = callback( ta,i,this );
                };
              };
            };
            __LINE__ = 450;
            return ret;
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        });
      };
      
      __LINE__ = 456;
      if ( !arrayProto.reduce ){
        
        __LINE__ = 473;
        defineBuiltin( arrayProto,"reduce",
        function ( callback,initial ) {
          try {
            __LINE__ = 474;
            callbackCheck( callback,"Array.reduce" );
            
            __LINE__ = 475;
            var ret = initial || this[0],
                i = ( initial )?0 : 1,
                len = this.length,
                ta;
            
            __LINE__ = 479;
            if ( ( len === 0 || len === null ) && arguments.length<2 ){
              
              __LINE__ = 480;
              builtinTypeError( "Array length is 0 and no second argument" );
            };
            
            __LINE__ = 482;
            for ( i;i<len; ++ i ){
              
              __LINE__ = 483;
              if ( ( ta = this[i] ) !== null && ta !== undefined ){
                
                __LINE__ = 484;
                ret = callback( ret,ta,i,this );
              };
            };
            __LINE__ = 487;
            return ret;
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        });
      };
      
      __LINE__ = 493;
      if ( !arrayProto.reduceRight ){
        
        __LINE__ = 510;
        defineBuiltin( arrayProto,"reduceRight",
        function ( callback,initial ) {
          try {
            __LINE__ = 511;
            callbackCheck( callback,"Array.reduceRight" );
            
            __LINE__ = 512;
            var len = this.length,
                ret = initial || this[len-1],
                i = ( initial )?len-1 : len-2,
                ta;
            
            __LINE__ = 516;
            if ( ( len === 0 || len === null ) && arguments.length<2 ){
              
              __LINE__ = 517;
              builtinTypeError( "Array length is 0 and no second argument" );
            };
            
            __LINE__ = 519;
            for ( i;i>-1; -- i ){
              
              __LINE__ = 520;
              if ( ( ta = this[i] ) !== null && ta !== undefined ){
                
                __LINE__ = 521;
                ret = callback( ret,ta,i,this );
              };
            };
            __LINE__ = 524;
            return ret;
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        });
      };
      
      __LINE__ = 530;
      if ( !dateProto.toJSON ){
        
        __LINE__ = 536;
        defineBuiltin( dateProto,"toJSON",
        function () {
          try {
            __LINE__ = 537;
            var _mochaLocalTmp4 = [],
                month = _mochaLocalTmp4[0],
                date = _mochaLocalTmp4[1],
                hour = _mochaLocalTmp4[2],
                minute = _mochaLocalTmp4[3],
                second = _mochaLocalTmp4[4];
            __LINE__ = 544;
            return '"'+this.getUTCFullYear()+'-'+( month>8?month+1 : "0"+( month+1 ) )+'-'+( date>9?date : "0"+date )+'T'+( hour>9?hour : "0"+hour )+':'+( minute>9?minute : "0"+minute )+':'+( second>9?second : "0"+second )+'.'+this.getUTCMilliseconds()+'Z"';
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        });
      };
      
      __LINE__ = 554;
      if ( !Date.now ){
        
        __LINE__ = 560;
        defineBuiltin( Date,"now",
        function () {
          try {
            __LINE__ = 560;
            return +new Date();
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        });
      };
      
      __LINE__ = 564;
      if ( !Array.isArray ){
        
        __LINE__ = 570;
        defineBuiltin( Array,"isArray",
        function ( arr ) {
          try {
            __LINE__ = 571;
            if ( arguments.length === 0 ){
              __LINE__ = 572;
              return false;
            };
            __LINE__ = 574;
            return ( arr )?Object.prototype.toString.call( arr ) === "[object Array]" : false;
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        });
      };
    } catch( e ){
      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  }).call( this,String,Array,Function,Date );
  
  __LINE__ = 586;
  var Runtime = function () {
        try {
          __LINE__ = 586;
          var _mochaLocalExport = {};
          "use strict"__LINE__ = 586;
          return _mochaLocalExport;
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }();
  
  __LINE__ = 926;
  if ( !( "StopIteration" in window ) ){
    
    __LINE__ = 927;
    window.StopIteration =  {
      toString : function () {
        try {
          __LINE__ = 928;
          return "[object StopIteration]";
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }
    };
  };
  
  function Tuple(  ) {
    try {
      __LINE__ = 932;
      var args = Runtime.toArray( arguments,1 );
      
      __LINE__ = 933;
      var ret = {};
      
      __LINE__ = 934;
      ret.length = 0;
      
      __LINE__ = 935;
      Array.prototype.push.apply( ret,args );
      
      __LINE__ = 936;
      Runtime.createTuple( ret,arguments.length );
      __LINE__ = 937;
      return ret;
    } catch( e ){
      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  }
  function Record( member ) {
    try {
      __LINE__ = 939;
      return Runtime.createRecord( member );
    } catch( e ){
      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  }
  __LINE__ = 0;
  function () {
    try {
      var __FILE__ = "/Users/aono_taketoshi/github/mocha/src/test/js/262/expression_test.js",
          __LINE__ = 0;
      __LINE__ = 2;
      _mochaGlobalExport['./expression_test.js'] = {};
      
      __LINE__ = 3;
      var _mochaGlobalAlias = _mochaGlobalExport['./expression_test.js'];
      
      __LINE__ = 1;
      /aaaa/.test( "aaaa" );
      
      function parseTest() {
        try {
          __LINE__ = 3;
          var x = .200*10;
          
          __LINE__ = 4;
          Runtime.assert( true,x === 2,"x === 2",4,'./expression_test.js' );
          
          __LINE__ = 6;
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
          
          __LINE__ = 11;
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
          
          __LINE__ = 20;
          testObject.testProp = {};
          
          __LINE__ = 21;
          testObject.testProp.testProp = {};
          
          __LINE__ = 22;
          testObject.testProp.testProp.testProp = {};
          
          __LINE__ = 23;
          testObject.testFn = function () {
            try {
              __LINE__ = 23;
              return true;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 24;
          testObject.testProp.testFn = function () {
            try {
              __LINE__ = 24;
              return false;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 25;
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
          
          __LINE__ = 71;
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
          
          __LINE__ = 78;
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
            
            __LINE__ = 88;
            val = 1;
          };
          
          __LINE__ = 90;
          Runtime.assert( true,val === 1,"val === 1",90,'./expression_test.js' );
          
          __LINE__ = 91;
          if ( ( item && trueValue ) || falseValue ){
            
            __LINE__ = 92;
            val = 2;
          };
          
          __LINE__ = 94;
          Runtime.assert( true,val === 2,"val === 2",94,'./expression_test.js' );
          
          __LINE__ = 95;
          if ( ( item && falseValue ) || !trueValue ){
            
            __LINE__ = 96;
            val = 3;
          };
          
          __LINE__ = 98;
          Runtime.assert( false,val === 3,"val === 3",98,'./expression_test.js' );
          
          __LINE__ = 100;
          var changeVal = function ( value ) {
                try {
                  __LINE__ = 101;
                  val = value;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
          
          __LINE__ = 104;
          ( item ) && ( trueValue ) && ( !falseValue ) && ( changeVal( 4 ) );
          
          __LINE__ = 105;
          Runtime.assert( true,val === 4,"val === 4",105,'./expression_test.js' );
          
          __LINE__ = 107;
          var eq = 0,
              eqVal = 0;
          
          __LINE__ = 109;
          if ( eq == 0 ){
            
            __LINE__ = 110;
            eqVal = 1;
          };
          
          __LINE__ = 112;
          Runtime.assert( true,eqVal === 1,"eqVal === 1",112,'./expression_test.js' );
          
          __LINE__ = 114;
          if ( eq === 0 ){
            
            __LINE__ = 115;
            eqVal = 2;
          };
          
          __LINE__ = 117;
          Runtime.assert( true,eqVal === 2,"eqVal === 2",117,'./expression_test.js' );
          
          __LINE__ = 119;
          var bit = 1,
              ret = 0;
          
          __LINE__ = 121;
          ret = bit << 1;
          
          __LINE__ = 122;
          Runtime.assert( true,ret === 2,"ret === 2",122,'./expression_test.js' );
          
          __LINE__ = 123;
          ret = bit >> 1;
          
          __LINE__ = 124;
          Runtime.assert( true,ret === 0,"ret === 0",124,'./expression_test.js' );
          
          __LINE__ = 125;
          ret = bit|2;
          
          __LINE__ = 126;
          Runtime.assert( true,ret === 3,"ret === 3",126,'./expression_test.js' );
          
          __LINE__ = 128;
          bit = 1;
          
          __LINE__ = 129;
          bit <<= 1;
          
          __LINE__ = 130;
          Runtime.assert( true,bit === 2,"bit === 2",130,'./expression_test.js' );
          
          __LINE__ = 131;
          bit = 1;
          
          __LINE__ = 132;
          bit >>= 1;
          
          __LINE__ = 133;
          Runtime.assert( true,bit === 0,"bit === 0",133,'./expression_test.js' );
          
          __LINE__ = 134;
          bit = 1;
          
          __LINE__ = 135;
          bit |= 2;
          
          __LINE__ = 136;
          Runtime.assert( true,bit === 3,"bit === 3",136,'./expression_test.js' );
          
          __LINE__ = 138;
          bit = 10;
          
          __LINE__ = 139;
          ret = bit >>> 2;
          
          __LINE__ = 140;
          Runtime.assert( true,ret === 2,"ret === 2",140,'./expression_test.js' );
          
          __LINE__ = 141;
          bit = 10;
          
          __LINE__ = 142;
          bit >>>= 2;
          
          __LINE__ = 143;
          Runtime.assert( true,bit === 2,"bit === 2",143,'./expression_test.js' );
          
          __LINE__ = 145;
          bit = 3;
          
          __LINE__ = 146;
          ret = bit&1;
          
          __LINE__ = 147;
          Runtime.assert( true,ret === 1,"ret === 1",147,'./expression_test.js' );
          
          __LINE__ = 148;
          bit &= 1;
          
          __LINE__ = 149;
          Runtime.assert( true,bit === 1,"bit === 1",149,'./expression_test.js' );
          
          __LINE__ = 151;
          bit = 2;
          
          __LINE__ = 152;
          ret = bit^1;
          
          __LINE__ = 153;
          Runtime.assert( true,ret === 3,"ret === 3",153,'./expression_test.js' );
          
          __LINE__ = 154;
          bit = 2;
          
          __LINE__ = 155;
          bit ^= 1;
          
          __LINE__ = 156;
          Runtime.assert( true,bit === 3,"bit === 3",156,'./expression_test.js' );
          
          __LINE__ = 158;
          var lt = 0,
              gt = 1,
              cmpVal = 0;
          
          __LINE__ = 162;
          if ( lt>gt ){
            
            __LINE__ = 163;
            cmpVal = 1;
          };
          
          __LINE__ = 165;
          Runtime.assert( true,cmpVal === 0,"cmpVal === 0",165,'./expression_test.js' );
          
          __LINE__ = 167;
          cmpVal = 0;
          
          __LINE__ = 168;
          if ( lt<gt ){
            
            __LINE__ = 169;
            cmpVal = 1;
          };
          
          __LINE__ = 171;
          Runtime.assert( true,cmpVal === 1,"cmpVal === 1",171,'./expression_test.js' );
          
          __LINE__ = 173;
          cmpVal = 0;
          
          __LINE__ = 174;
          if ( lt <= gt ){
            
            __LINE__ = 175;
            cmpVal = 1;
          };
          
          __LINE__ = 177;
          Runtime.assert( true,cmpVal === 1,"cmpVal === 1",177,'./expression_test.js' );
          
          __LINE__ = 179;
          cmpVal = 0;
          
          __LINE__ = 180;
          if ( lt >= gt ){
            
            __LINE__ = 181;
            cmpVal = 1;
          };
          
          __LINE__ = 183;
          Runtime.assert( false,cmpVal === 1,"cmpVal === 1",183,'./expression_test.js' );
          
          __LINE__ = 185;
          cmpVal = 0;
          
          __LINE__ = 186;
          lt = 1;
          
          __LINE__ = 187;
          if ( lt <= gt ){
            
            __LINE__ = 188;
            cmpVal = 1;
          };
          
          __LINE__ = 190;
          Runtime.assert( true,cmpVal === 1,"cmpVal === 1",190,'./expression_test.js' );
          
          __LINE__ = 192;
          cmpVal = 1;
          
          __LINE__ = 193;
          if ( lt >= gt ){
            
            __LINE__ = 194;
            cmpVal = 1;
          };
          
          __LINE__ = 196;
          Runtime.assert( true,cmpVal === 1,"cmpVal === 1",196,'./expression_test.js' );
          
          __LINE__ = 198;
          var pl = 0;
          
          __LINE__ = 199;
          ret = pl+1;
          
          __LINE__ = 200;
          Runtime.assert( true,ret === 1,"ret === 1",200,'./expression_test.js' );
          
          __LINE__ = 202;
          var mi = 1;
          
          __LINE__ = 203;
          ret = mi-1;
          
          __LINE__ = 204;
          Runtime.assert( true,ret === 0,"ret === 0",204,'./expression_test.js' );
          
          __LINE__ = 206;
          var mul = 1;
          
          __LINE__ = 207;
          ret = mul*2;
          
          __LINE__ = 208;
          Runtime.assert( true,ret === 2,"ret === 2",208,'./expression_test.js' );
          
          __LINE__ = 210;
          var div = 2;
          
          __LINE__ = 211;
          ret = div/2;
          
          __LINE__ = 212;
          Runtime.assert( true,ret === 1,"ret === 1",212,'./expression_test.js' );
          
          __LINE__ = 214;
          var mod = 3;
          
          __LINE__ = 215;
          ret = mod%2;
          
          __LINE__ = 216;
          Runtime.assert( true,ret === 1,"ret === 1",216,'./expression_test.js' );
          
          __LINE__ = 218;
          pl = 0;
          
          __LINE__ = 219;
          pl += 1;
          
          __LINE__ = 220;
          Runtime.assert( true,pl === 1,"pl === 1",220,'./expression_test.js' );
          
          __LINE__ = 222;
          mi = 1;
          
          __LINE__ = 223;
          mi -= 1;
          
          __LINE__ = 224;
          Runtime.assert( true,mi === 0,"mi === 0",224,'./expression_test.js' );
          
          __LINE__ = 226;
          mul = 1;
          
          __LINE__ = 227;
          mul *= 2;
          
          __LINE__ = 228;
          Runtime.assert( true,mul === 2,"mul === 2",228,'./expression_test.js' );
          
          __LINE__ = 230;
          div = 2;
          
          __LINE__ = 231;
          div /= 2;
          
          __LINE__ = 232;
          Runtime.assert( true,div === 1,"div === 1",232,'./expression_test.js' );
          
          __LINE__ = 234;
          mod = 3;
          
          __LINE__ = 235;
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
          
          __LINE__ = 250;
          add ++ ;
          
          __LINE__ = 251;
          Runtime.assert( true,add === 1,"add === 1",251,'./expression_test.js' );
          
          __LINE__ = 253;
          var sub = 1;
          
          __LINE__ = 254;
          sub -- ;
          
          __LINE__ = 255;
          Runtime.assert( true,sub === 0,"sub === 0",255,'./expression_test.js' );
          
          __LINE__ = 257;
          add = 0;
          
          __LINE__ = 258;
          sub = add;
          
          __LINE__ = 259;
           ++ sub;
          
          __LINE__ = 260;
          Runtime.assert( true,sub === 1,"sub === 1",260,'./expression_test.js' );
          
          __LINE__ = 262;
          add = 1;
          
          __LINE__ = 263;
          sub = add;
          
          __LINE__ = 264;
           -- sub;
          
          __LINE__ = 265;
          Runtime.assert( true,sub === 0,"sub === 0",265,'./expression_test.js' );
          
          __LINE__ = 267;
          sub = 1;
          
          __LINE__ = 268;
          sub -- ;
          
          __LINE__ = 269;
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
          
          __LINE__ = 279;
          ret = -strNum;
          
          __LINE__ = 280;
          Runtime.assert( true,ret === -1,"ret === -1",280,'./expression_test.js' );
          
          __LINE__ = 282;
          var num = -5;
          
          __LINE__ = 283;
          ret = ~num;
          
          __LINE__ = 284;
          Runtime.assert( true,ret === 4,"ret === 4",284,'./expression_test.js' );
          
          __LINE__ = 286;
          var flg = true;
          
          __LINE__ = 287;
          ret = !flg;
          
          __LINE__ = 288;
          Runtime.assert( true,ret === false,"ret === false",288,'./expression_test.js' );
          
          __LINE__ = 290;
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
          
          __LINE__ = 317;
          exp = ( a = 0 , b = 1 , c = 2 );
          
          __LINE__ = 318;
          Runtime.assert( true,a === 0,"a === 0",318,'./expression_test.js' );
          
          __LINE__ = 319;
          Runtime.assert( true,b === 1,"b === 1",319,'./expression_test.js' );
          
          __LINE__ = 320;
          Runtime.assert( true,c === 2,"c === 2",320,'./expression_test.js' );
          
          __LINE__ = 321;
          Runtime.assert( true,exp === 2,"exp === 2",321,'./expression_test.js' );
          
          __LINE__ = 323;
          ( function () {
            try {
              __LINE__ = 324;
              exp = 10;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })();
          
          __LINE__ = 327;
          Runtime.assert( true,exp === 10,"exp === 10",327,'./expression_test.js' );
          
          __LINE__ = 329;
          ( function ( a,b ) {
            try {
              __LINE__ = 330;
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
          
          __LINE__ = 335;
          !function () {
            try {
              __LINE__ = 336;
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
          var array = [];
          
          __LINE__ = 343;
          Runtime.assert( true,array.length === 3,"array.length === 3",343,'./expression_test.js' );
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }
      __LINE__ = 346;
      parseTest();
      
      __LINE__ = 347;
      objectAndNewTest();
      
      __LINE__ = 348;
      callExpressionTest();
      
      __LINE__ = 349;
      binaryExpressionTest();
      
      __LINE__ = 350;
      postfixExpressionTest();
      
      __LINE__ = 351;
      unaryExpressionTest();
      
      __LINE__ = 352;
      memberExpressionTest();
      
      __LINE__ = 353;
      expressionTest();
      
      __LINE__ = 354;
      primaryTest();
    } catch( e ){
      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  }();
}();
