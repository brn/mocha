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
      var __FILE__ = "/Users/aono_taketoshi/github/mocha/src/test/js/harmony/yield_test.js",
          __LINE__ = 0;
      __LINE__ = 2;
      _mochaGlobalExport['./yield_test.js'] = {};
      
      __LINE__ = 3;
      var _mochaGlobalAlias = _mochaGlobalExport['./yield_test.js'];
      
      __LINE__ = 1;
      var tests =  {
            case1 : function () {
              try {
                function yieldTest2(  ) {
                  try {
                    __LINE__ = 3;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 3;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 3;
                    var _yieldState = 0;
                    
                    __LINE__ = 4;
                    var i = 0;
                    
                    __LINE__ = 3;
                    var _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 3;
                            if ( !_isYieldSend ){
                              
                              __LINE__ = 3;
                              _mochaIsNewBorn = false;
                            } else if ( _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined ){
                              
                              __LINE__ = 3;
                              Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 3;
                            while ( 1 ){
                              __LINE__ = 3;
                              switch ( _yieldState ) {
                                case 0 :
                                  
                                  __LINE__ = 4;
                                  if ( !( i<10 ) ){
                                    
                                    __LINE__ = 4;
                                    _yieldState = -1;
                                    __LINE__ = 4;
                                    break;
                                  };
                                case 1 :
                                  i
                                  __LINE__ = 4;
                                  i ++ ;
                                  
                                  __LINE__ = 4;
                                  if ( i<10 ){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 1;
                                    __LINE__ = 4;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 3;
                                  if ( _isYieldSafe ){
                                    __LINE__ = 3;
                                    return undefined;
                                  } else {
                                    __LINE__ = 3;
                                    Runtime.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 3;
                    return Runtime.createGenerator( _mochaGenerator,
                    function (  ) {
                      try {
                        __LINE__ = 3;
                        _yieldState = -1;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
                __LINE__ = 9;
                var generator = yieldTest2();
                
                __LINE__ = 11;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",11,'./yield_test.js' );
                
                __LINE__ = 12;
                Runtime.assert( true,generator.next() === 1,"generator.next() === 1",12,'./yield_test.js' );
                
                __LINE__ = 13;
                Runtime.assert( true,generator.next() === 2,"generator.next() === 2",13,'./yield_test.js' );
                
                __LINE__ = 14;
                Runtime.assert( true,generator.next() === 3,"generator.next() === 3",14,'./yield_test.js' );
                
                __LINE__ = 15;
                Runtime.assert( true,generator.next() === 4,"generator.next() === 4",15,'./yield_test.js' );
                
                __LINE__ = 16;
                Runtime.assert( true,generator.next() === 5,"generator.next() === 5",16,'./yield_test.js' );
                
                __LINE__ = 17;
                Runtime.assert( true,generator.next() === 6,"generator.next() === 6",17,'./yield_test.js' );
                
                __LINE__ = 18;
                Runtime.assert( true,generator.next() === 7,"generator.next() === 7",18,'./yield_test.js' );
                
                __LINE__ = 19;
                Runtime.assert( true,generator.next() === 8,"generator.next() === 8",19,'./yield_test.js' );
                
                __LINE__ = 20;
                Runtime.assert( true,generator.next() === 9,"generator.next() === 9",20,'./yield_test.js' );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case2 : function () {
              try {
                function yieldTest3(  ) {
                  try {
                    __LINE__ = 24;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 24;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 24;
                    var _yieldState = 0;
                    
                    __LINE__ = 25;
                    var i = 0;
                    
                    __LINE__ = 24;
                    var _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 24;
                            if ( !_isYieldSend ){
                              
                              __LINE__ = 24;
                              _mochaIsNewBorn = false;
                            } else if ( _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined ){
                              
                              __LINE__ = 24;
                              Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 24;
                            while ( 1 ){
                              __LINE__ = 24;
                              switch ( _yieldState ) {
                                case 0 :
                                  
                                  __LINE__ = 25;
                                  if ( !( i<10 ) ){
                                    
                                    __LINE__ = 25;
                                    _yieldState = -1;
                                    __LINE__ = 25;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 25;
                                  i ++ ;
                                  
                                  __LINE__ = 25;
                                  if ( i<10 ){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 1;
                                    __LINE__ = 25;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 24;
                                  if ( _isYieldSafe ){
                                    __LINE__ = 24;
                                    return undefined;
                                  } else {
                                    __LINE__ = 24;
                                    Runtime.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 24;
                    return Runtime.createGenerator( _mochaGenerator,
                    function (  ) {
                      try {
                        __LINE__ = 24;
                        _yieldState = -1;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
                __LINE__ = 31;
                generator = yieldTest3();
                
                __LINE__ = 32;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",32,'./yield_test.js' );
                
                __LINE__ = 33;
                Runtime.assert( true,generator.next() === 2,"generator.next() === 2",33,'./yield_test.js' );
                
                __LINE__ = 34;
                Runtime.assert( true,generator.next() === 4,"generator.next() === 4",34,'./yield_test.js' );
                
                __LINE__ = 35;
                Runtime.assert( true,generator.next() === 6,"generator.next() === 6",35,'./yield_test.js' );
                
                __LINE__ = 36;
                Runtime.assert( true,generator.next() === 8,"generator.next() === 8",36,'./yield_test.js' );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case3 : function () {
              try {
                function yieldTest4(  ) {
                  try {
                    __LINE__ = 39;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 39;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 39;
                    var _yieldState = 0;
                    
                    __LINE__ = 40;
                    var i = 0;
                    
                    __LINE__ = 39;
                    var _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 39;
                            if ( !_isYieldSend ){
                              
                              __LINE__ = 39;
                              _mochaIsNewBorn = false;
                            } else if ( _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined ){
                              
                              __LINE__ = 39;
                              Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 39;
                            while ( 1 ){
                              __LINE__ = 39;
                              switch ( _yieldState ) {
                                case 0 :
                                  
                                  __LINE__ = 40;
                                  if ( !( i<10 ) ){
                                    
                                    __LINE__ = 40;
                                    _yieldState = -1;
                                    __LINE__ = 40;
                                    break;
                                  };
                                case 1 :
                                  
                                  {
                                    
                                  };
                                  
                                  __LINE__ = 40;
                                  i ++ ;
                                  
                                  __LINE__ = 40;
                                  if ( i<10 ){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 1;
                                    __LINE__ = 40;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 39;
                                  if ( _isYieldSafe ){
                                    __LINE__ = 39;
                                    return undefined;
                                  } else {
                                    __LINE__ = 39;
                                    Runtime.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 39;
                    return Runtime.createGenerator( _mochaGenerator,
                    function (  ) {
                      try {
                        __LINE__ = 39;
                        _yieldState = -1;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
                __LINE__ = 48;
                generator = yieldTest4();
                
                __LINE__ = 49;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",49,'./yield_test.js' );
                
                __LINE__ = 50;
                Runtime.assert( true,generator.next() === 2,"generator.next() === 2",50,'./yield_test.js' );
                
                __LINE__ = 51;
                Runtime.assert( true,generator.next() === 4,"generator.next() === 4",51,'./yield_test.js' );
                
                __LINE__ = 52;
                Runtime.assert( true,generator.next() === 6,"generator.next() === 6",52,'./yield_test.js' );
                
                __LINE__ = 53;
                Runtime.assert( true,generator.next() === 8,"generator.next() === 8",53,'./yield_test.js' );
                
                __LINE__ = 55;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",55,'./yield_test.js' );
                
                __LINE__ = 56;
                Runtime.assert( true,generator.next() === 2,"generator.next() === 2",56,'./yield_test.js' );
                
                __LINE__ = 57;
                Runtime.assert( true,generator.next() === 4,"generator.next() === 4",57,'./yield_test.js' );
                
                __LINE__ = 58;
                Runtime.assert( true,generator.next() === 6,"generator.next() === 6",58,'./yield_test.js' );
                
                __LINE__ = 59;
                Runtime.assert( true,generator.next() === 8,"generator.next() === 8",59,'./yield_test.js' );
                
                __LINE__ = 61;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",61,'./yield_test.js' );
                
                __LINE__ = 62;
                Runtime.assert( true,generator.next() === 2,"generator.next() === 2",62,'./yield_test.js' );
                
                __LINE__ = 63;
                Runtime.assert( true,generator.next() === 4,"generator.next() === 4",63,'./yield_test.js' );
                
                __LINE__ = 64;
                Runtime.assert( true,generator.next() === 6,"generator.next() === 6",64,'./yield_test.js' );
                
                __LINE__ = 65;
                Runtime.assert( true,generator.next() === 8,"generator.next() === 8",65,'./yield_test.js' );
                
                __LINE__ = 67;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",67,'./yield_test.js' );
                
                __LINE__ = 68;
                Runtime.assert( true,generator.next() === 2,"generator.next() === 2",68,'./yield_test.js' );
                
                __LINE__ = 69;
                Runtime.assert( true,generator.next() === 4,"generator.next() === 4",69,'./yield_test.js' );
                
                __LINE__ = 70;
                Runtime.assert( true,generator.next() === 6,"generator.next() === 6",70,'./yield_test.js' );
                
                __LINE__ = 71;
                Runtime.assert( true,generator.next() === 8,"generator.next() === 8",71,'./yield_test.js' );
                
                __LINE__ = 73;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",73,'./yield_test.js' );
                
                __LINE__ = 74;
                Runtime.assert( true,generator.next() === 2,"generator.next() === 2",74,'./yield_test.js' );
                
                __LINE__ = 75;
                Runtime.assert( true,generator.next() === 4,"generator.next() === 4",75,'./yield_test.js' );
                
                __LINE__ = 76;
                Runtime.assert( true,generator.next() === 6,"generator.next() === 6",76,'./yield_test.js' );
                
                __LINE__ = 77;
                Runtime.assert( true,generator.next() === 8,"generator.next() === 8",77,'./yield_test.js' );
                
                __LINE__ = 79;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",79,'./yield_test.js' );
                
                __LINE__ = 80;
                Runtime.assert( true,generator.next() === 2,"generator.next() === 2",80,'./yield_test.js' );
                
                __LINE__ = 81;
                Runtime.assert( true,generator.next() === 4,"generator.next() === 4",81,'./yield_test.js' );
                
                __LINE__ = 82;
                Runtime.assert( true,generator.next() === 6,"generator.next() === 6",82,'./yield_test.js' );
                
                __LINE__ = 83;
                Runtime.assert( true,generator.next() === 8,"generator.next() === 8",83,'./yield_test.js' );
                
                __LINE__ = 85;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",85,'./yield_test.js' );
                
                __LINE__ = 86;
                Runtime.assert( true,generator.next() === 2,"generator.next() === 2",86,'./yield_test.js' );
                
                __LINE__ = 87;
                Runtime.assert( true,generator.next() === 4,"generator.next() === 4",87,'./yield_test.js' );
                
                __LINE__ = 88;
                Runtime.assert( true,generator.next() === 6,"generator.next() === 6",88,'./yield_test.js' );
                
                __LINE__ = 89;
                Runtime.assert( true,generator.next() === 8,"generator.next() === 8",89,'./yield_test.js' );
                
                __LINE__ = 91;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",91,'./yield_test.js' );
                
                __LINE__ = 92;
                Runtime.assert( true,generator.next() === 2,"generator.next() === 2",92,'./yield_test.js' );
                
                __LINE__ = 93;
                Runtime.assert( true,generator.next() === 4,"generator.next() === 4",93,'./yield_test.js' );
                
                __LINE__ = 94;
                Runtime.assert( true,generator.next() === 6,"generator.next() === 6",94,'./yield_test.js' );
                
                __LINE__ = 95;
                Runtime.assert( true,generator.next() === 8,"generator.next() === 8",95,'./yield_test.js' );
                
                __LINE__ = 97;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",97,'./yield_test.js' );
                
                __LINE__ = 98;
                Runtime.assert( true,generator.next() === 2,"generator.next() === 2",98,'./yield_test.js' );
                
                __LINE__ = 99;
                Runtime.assert( true,generator.next() === 4,"generator.next() === 4",99,'./yield_test.js' );
                
                __LINE__ = 100;
                Runtime.assert( true,generator.next() === 6,"generator.next() === 6",100,'./yield_test.js' );
                
                __LINE__ = 101;
                Runtime.assert( true,generator.next() === 8,"generator.next() === 8",101,'./yield_test.js' );
                
                __LINE__ = 103;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",103,'./yield_test.js' );
                
                __LINE__ = 104;
                Runtime.assert( true,generator.next() === 2,"generator.next() === 2",104,'./yield_test.js' );
                
                __LINE__ = 105;
                Runtime.assert( true,generator.next() === 4,"generator.next() === 4",105,'./yield_test.js' );
                
                __LINE__ = 106;
                Runtime.assert( true,generator.next() === 6,"generator.next() === 6",106,'./yield_test.js' );
                
                __LINE__ = 107;
                Runtime.assert( true,generator.next() === 8,"generator.next() === 8",107,'./yield_test.js' );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case4 : function () {
              try {
                function yieldTest5(  ) {
                  try {
                    __LINE__ = 110;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 110;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 110;
                    var _yieldState = 0;
                    
                    __LINE__ = 111;
                    var i;
                    
                    __LINE__ = 110;
                    var _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 110;
                            if ( !_isYieldSend ){
                              
                              __LINE__ = 110;
                              _mochaIsNewBorn = false;
                            } else if ( _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined ){
                              
                              __LINE__ = 110;
                              Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 110;
                            while ( 1 ){
                              __LINE__ = 110;
                              switch ( _yieldState ) {
                                case 0 :
                                  
                                  __LINE__ = 112;
                                  if ( !(  ++ i<10 ) ){
                                    
                                    __LINE__ = 112;
                                    _yieldState = -1;
                                    __LINE__ = 112;
                                    break;
                                  };
                                case 1 :
                                  i
                                  __LINE__ = 112;
                                  if (  ++ i<10 ){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 1;
                                    __LINE__ = 112;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 110;
                                  if ( _isYieldSafe ){
                                    __LINE__ = 110;
                                    return undefined;
                                  } else {
                                    __LINE__ = 110;
                                    Runtime.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 110;
                    return Runtime.createGenerator( _mochaGenerator,
                    function (  ) {
                      try {
                        __LINE__ = 110;
                        _yieldState = -1;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
                __LINE__ = 117;
                generator = yieldTest5();
                
                __LINE__ = 118;
                Runtime.assert( true,generator.next() === 1,"generator.next() === 1",118,'./yield_test.js' );
                
                __LINE__ = 119;
                Runtime.assert( true,generator.next() === 2,"generator.next() === 2",119,'./yield_test.js' );
                
                __LINE__ = 120;
                Runtime.assert( true,generator.next() === 3,"generator.next() === 3",120,'./yield_test.js' );
                
                __LINE__ = 121;
                Runtime.assert( true,generator.next() === 4,"generator.next() === 4",121,'./yield_test.js' );
                
                __LINE__ = 122;
                Runtime.assert( true,generator.next() === 5,"generator.next() === 5",122,'./yield_test.js' );
                
                __LINE__ = 123;
                Runtime.assert( true,generator.next() === 6,"generator.next() === 6",123,'./yield_test.js' );
                
                __LINE__ = 124;
                Runtime.assert( true,generator.next() === 7,"generator.next() === 7",124,'./yield_test.js' );
                
                __LINE__ = 125;
                Runtime.assert( true,generator.next() === 8,"generator.next() === 8",125,'./yield_test.js' );
                
                __LINE__ = 126;
                Runtime.assert( true,generator.next() === 9,"generator.next() === 9",126,'./yield_test.js' );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case5 : function () {
              try {
                function yieldTest6(  ) {
                  try {
                    __LINE__ = 129;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 129;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 129;
                    var _yieldState = 0;
                    
                    __LINE__ = 130;
                    var i;
                    
                    __LINE__ = 129;
                    var _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 129;
                            if ( !_isYieldSend ){
                              
                              __LINE__ = 129;
                              _mochaIsNewBorn = false;
                            } else if ( _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined ){
                              
                              __LINE__ = 129;
                              Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 129;
                            while ( 1 ){
                              __LINE__ = 129;
                              switch ( _yieldState ) {
                                case 0 :
                                  i
                                  __LINE__ = 133;
                                  if (  ++ i<10 ){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 0;
                                    __LINE__ = 133;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = 1;
                                  };
                                case 1 :
                                case -1 :
                                  
                                  __LINE__ = 129;
                                  if ( _isYieldSafe ){
                                    __LINE__ = 129;
                                    return undefined;
                                  } else {
                                    __LINE__ = 129;
                                    Runtime.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 129;
                    return Runtime.createGenerator( _mochaGenerator,
                    function (  ) {
                      try {
                        __LINE__ = 129;
                        _yieldState = -1;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
                __LINE__ = 136;
                generator = yieldTest6();
                
                __LINE__ = 137;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",137,'./yield_test.js' );
                
                __LINE__ = 138;
                Runtime.assert( true,generator.next() === 1,"generator.next() === 1",138,'./yield_test.js' );
                
                __LINE__ = 139;
                Runtime.assert( true,generator.next() === 2,"generator.next() === 2",139,'./yield_test.js' );
                
                __LINE__ = 140;
                Runtime.assert( true,generator.next() === 3,"generator.next() === 3",140,'./yield_test.js' );
                
                __LINE__ = 141;
                Runtime.assert( true,generator.next() === 4,"generator.next() === 4",141,'./yield_test.js' );
                
                __LINE__ = 142;
                Runtime.assert( true,generator.next() === 5,"generator.next() === 5",142,'./yield_test.js' );
                
                __LINE__ = 143;
                Runtime.assert( true,generator.next() === 6,"generator.next() === 6",143,'./yield_test.js' );
                
                __LINE__ = 144;
                Runtime.assert( true,generator.next() === 7,"generator.next() === 7",144,'./yield_test.js' );
                
                __LINE__ = 145;
                Runtime.assert( true,generator.next() === 8,"generator.next() === 8",145,'./yield_test.js' );
                
                __LINE__ = 146;
                Runtime.assert( true,generator.next() === 9,"generator.next() === 9",146,'./yield_test.js' );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case6 : function () {
              try {
                function yieldTest7(  ) {
                  try {
                    __LINE__ = 149;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 149;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 149;
                    var _yieldState = 0;
                    
                    __LINE__ = 151;
                    var m;
                    
                    __LINE__ = 150;
                    var i = 0;
                    
                    __LINE__ = 149;
                    var _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 149;
                            if ( !_isYieldSend ){
                              
                              __LINE__ = 149;
                              _mochaIsNewBorn = false;
                            } else if ( _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined ){
                              
                              __LINE__ = 149;
                              Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 149;
                            while ( 1 ){
                              __LINE__ = 149;
                              switch ( _yieldState ) {
                                case 0 :
                                  
                                  __LINE__ = 150;
                                  if ( !( i<10 ) ){
                                    
                                    __LINE__ = 150;
                                    _yieldState = -1;
                                    __LINE__ = 150;
                                    break;
                                  };
                                case 1 :
                                  i
                                  __LINE__ = 150;
                                  i ++ ;
                                  
                                  __LINE__ = 150;
                                  if ( i<10 ){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 1;
                                    __LINE__ = 150;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 149;
                                  if ( _isYieldSafe ){
                                    __LINE__ = 149;
                                    return undefined;
                                  } else {
                                    __LINE__ = 149;
                                    Runtime.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 149;
                    return Runtime.createGenerator( _mochaGenerator,
                    function (  ) {
                      try {
                        __LINE__ = 149;
                        _yieldState = -1;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
                __LINE__ = 162;
                generator = yieldTest7();
                
                __LINE__ = 163;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",163,'./yield_test.js' );
                
                __LINE__ = 164;
                Runtime.assert( true,generator.send( true ) === 1,"generator.send( true ) === 1",164,'./yield_test.js' );
                
                __LINE__ = 165;
                Runtime.assert( true,generator.send( false ) === 1,"generator.send( false ) === 1",165,'./yield_test.js' );
                
                __LINE__ = 166;
                Runtime.assert( true,generator.send( true ) === 2,"generator.send( true ) === 2",166,'./yield_test.js' );
                
                __LINE__ = 167;
                Runtime.assert( true,generator.send( false ) === 2,"generator.send( false ) === 2",167,'./yield_test.js' );
                
                __LINE__ = 168;
                Runtime.assert( true,generator.send( true ) === 3,"generator.send( true ) === 3",168,'./yield_test.js' );
                
                __LINE__ = 169;
                Runtime.assert( true,generator.send( true ) === 3,"generator.send( true ) === 3",169,'./yield_test.js' );
                
                __LINE__ = 170;
                Runtime.assert( true,generator.send( true ) === 4,"generator.send( true ) === 4",170,'./yield_test.js' );
                
                __LINE__ = 171;
                Runtime.assert( true,generator.send( false ) === 4,"generator.send( false ) === 4",171,'./yield_test.js' );
                
                __LINE__ = 172;
                Runtime.assert( true,generator.send( true ) === 5,"generator.send( true ) === 5",172,'./yield_test.js' );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case7 : function () {
              try {
                function yieldTest8(  ) {
                  try {
                    __LINE__ = 175;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 175;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 175;
                    var _yieldState = 0;
                    
                    __LINE__ = 177;
                    var m;
                    
                    __LINE__ = 176;
                    var i = 0;
                    
                    __LINE__ = 175;
                    var _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 175;
                            if ( !_isYieldSend ){
                              
                              __LINE__ = 175;
                              _mochaIsNewBorn = false;
                            } else if ( _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined ){
                              
                              __LINE__ = 175;
                              Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 175;
                            while ( 1 ){
                              __LINE__ = 175;
                              switch ( _yieldState ) {
                                case 0 :
                                  
                                  __LINE__ = 176;
                                  if ( !( i<10 ) ){
                                    
                                    __LINE__ = 176;
                                    _yieldState = -1;
                                    __LINE__ = 176;
                                    break;
                                  };
                                case 1 :
                                  i
                                  __LINE__ = 176;
                                  i ++ ;
                                  
                                  __LINE__ = 176;
                                  if ( i<10 ){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 1;
                                    __LINE__ = 176;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 175;
                                  if ( _isYieldSafe ){
                                    __LINE__ = 175;
                                    return undefined;
                                  } else {
                                    __LINE__ = 175;
                                    Runtime.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 175;
                    return Runtime.createGenerator( _mochaGenerator,
                    function (  ) {
                      try {
                        __LINE__ = 175;
                        _yieldState = -1;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
                __LINE__ = 191;
                generator = yieldTest8();
                
                __LINE__ = 192;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",192,'./yield_test.js' );
                
                __LINE__ = 193;
                Runtime.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",193,'./yield_test.js' );
                
                __LINE__ = 194;
                Runtime.assert( true,generator.send( false ) === 2,"generator.send( false ) === 2",194,'./yield_test.js' );
                
                __LINE__ = 195;
                Runtime.assert( true,generator.send( true ) === 4,"generator.send( true ) === 4",195,'./yield_test.js' );
                
                __LINE__ = 196;
                Runtime.assert( true,generator.send( false ) === 6,"generator.send( false ) === 6",196,'./yield_test.js' );
                
                __LINE__ = 197;
                Runtime.assert( true,generator.send( true ) === 8,"generator.send( true ) === 8",197,'./yield_test.js' );
                
                __LINE__ = 198;
                Runtime.assert( true,generator.send( true ) === 10,"generator.send( true ) === 10",198,'./yield_test.js' );
                
                __LINE__ = 199;
                Runtime.assert( true,generator.send( true ) === 12,"generator.send( true ) === 12",199,'./yield_test.js' );
                
                __LINE__ = 200;
                Runtime.assert( true,generator.send( false ) === 14,"generator.send( false ) === 14",200,'./yield_test.js' );
                
                __LINE__ = 201;
                Runtime.assert( true,generator.send( true ) === 16,"generator.send( true ) === 16",201,'./yield_test.js' );
                
                __LINE__ = 202;
                Runtime.assert( true,generator.send( true ) === 18,"generator.send( true ) === 18",202,'./yield_test.js' );
                
                __LINE__ = 203;
                Runtime.assert( true,generator.send( false ) === 1,"generator.send( false ) === 1",203,'./yield_test.js' );
                
                __LINE__ = 204;
                Runtime.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",204,'./yield_test.js' );
                
                __LINE__ = 205;
                Runtime.assert( true,generator.send( false ) === 2,"generator.send( false ) === 2",205,'./yield_test.js' );
                
                __LINE__ = 206;
                Runtime.assert( true,generator.send( true ) === 4,"generator.send( true ) === 4",206,'./yield_test.js' );
                
                __LINE__ = 207;
                Runtime.assert( true,generator.send( true ) === 6,"generator.send( true ) === 6",207,'./yield_test.js' );
                
                __LINE__ = 208;
                Runtime.assert( true,generator.send( true ) === 8,"generator.send( true ) === 8",208,'./yield_test.js' );
                
                __LINE__ = 209;
                Runtime.assert( true,generator.send( false ) === 10,"generator.send( false ) === 10",209,'./yield_test.js' );
                
                __LINE__ = 210;
                Runtime.assert( true,generator.send( true ) === 12,"generator.send( true ) === 12",210,'./yield_test.js' );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case8 : function () {
              try {
                function yieldTest9(  ) {
                  try {
                    __LINE__ = 214;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 214;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 214;
                    var _yieldState = 0;
                    
                    __LINE__ = 217;
                    var m;
                    
                    __LINE__ = 215;
                    var i = 0;
                    
                    __LINE__ = 214;
                    var _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 214;
                            if ( !_isYieldSend ){
                              
                              __LINE__ = 214;
                              _mochaIsNewBorn = false;
                            } else if ( _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined ){
                              
                              __LINE__ = 214;
                              Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 214;
                            while ( 1 ){
                              __LINE__ = 214;
                              switch ( _yieldState ) {
                                case 0 :
                                  
                                  __LINE__ = 215;
                                  if ( !( i<10 ) ){
                                    
                                    __LINE__ = 215;
                                    _yieldState = -1;
                                    __LINE__ = 215;
                                    break;
                                  };
                                case 1 :
                                  
                                  {
                                    
                                  };
                                  
                                  __LINE__ = 215;
                                  i ++ ;
                                  
                                  __LINE__ = 215;
                                  if ( i<10 ){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 1;
                                    __LINE__ = 215;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 214;
                                  if ( _isYieldSafe ){
                                    __LINE__ = 214;
                                    return undefined;
                                  } else {
                                    __LINE__ = 214;
                                    Runtime.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 214;
                    return Runtime.createGenerator( _mochaGenerator,
                    function (  ) {
                      try {
                        __LINE__ = 214;
                        _yieldState = -1;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
                __LINE__ = 230;
                generator = yieldTest9();
                
                __LINE__ = 231;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",231,'./yield_test.js' );
                
                __LINE__ = 232;
                Runtime.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",232,'./yield_test.js' );
                
                __LINE__ = 233;
                Runtime.assert( true,generator.send( false ) === 0,"generator.send( false ) === 0",233,'./yield_test.js' );
                
                __LINE__ = 234;
                Runtime.assert( true,generator.send( true ) === 2,"generator.send( true ) === 2",234,'./yield_test.js' );
                
                __LINE__ = 235;
                Runtime.assert( true,generator.send( false ) === 0,"generator.send( false ) === 0",235,'./yield_test.js' );
                
                __LINE__ = 236;
                Runtime.assert( true,generator.send( true ) === 4,"generator.send( true ) === 4",236,'./yield_test.js' );
                
                __LINE__ = 237;
                Runtime.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",237,'./yield_test.js' );
                
                __LINE__ = 238;
                Runtime.assert( true,generator.send( true ) === 6,"generator.send( true ) === 6",238,'./yield_test.js' );
                
                __LINE__ = 239;
                Runtime.assert( true,generator.send( false ) === 0,"generator.send( false ) === 0",239,'./yield_test.js' );
                
                __LINE__ = 240;
                Runtime.assert( true,generator.send( true ) === 8,"generator.send( true ) === 8",240,'./yield_test.js' );
                
                __LINE__ = 241;
                Runtime.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",241,'./yield_test.js' );
                
                __LINE__ = 242;
                Runtime.assert( true,generator.send( false ) === 2.5,"generator.send( false ) === 2.5",242,'./yield_test.js' );
                
                __LINE__ = 243;
                Runtime.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",243,'./yield_test.js' );
                
                __LINE__ = 244;
                Runtime.assert( true,generator.send( false ) === 3,"generator.send( false ) === 3",244,'./yield_test.js' );
                
                __LINE__ = 245;
                Runtime.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",245,'./yield_test.js' );
                
                __LINE__ = 246;
                Runtime.assert( true,generator.send( true ) === 14,"generator.send( true ) === 14",246,'./yield_test.js' );
                
                __LINE__ = 247;
                Runtime.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",247,'./yield_test.js' );
                
                __LINE__ = 248;
                Runtime.assert( true,generator.send( false ) === 4,"generator.send( false ) === 4",248,'./yield_test.js' );
                
                __LINE__ = 249;
                Runtime.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",249,'./yield_test.js' );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case9 : function () {
              try {
                function yieldTest10(  ) {
                  try {
                    __LINE__ = 253;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 253;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 253;
                    var _yieldState = 0;
                    
                    __LINE__ = 253;
                    var _mochaFinallyCache;
                    
                    __LINE__ = 253;
                    var _mochaCatchCache;
                    
                    __LINE__ = 257;
                    var m;
                    
                    __LINE__ = 254;
                    var flg;
                    
                    __LINE__ = 255;
                    var i = 0;
                    
                    __LINE__ = 253;
                    var _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 253;
                            if ( !_isYieldSend ){
                              
                              __LINE__ = 253;
                              _mochaIsNewBorn = false;
                            } else if ( _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined ){
                              
                              __LINE__ = 253;
                              Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 253;
                            while ( 1 ){
                              try {
                                __LINE__ = 253;
                                switch ( _yieldState ) {
                                  case 0 :
                                    
                                    __LINE__ = 255;
                                    if ( !( i<10 ) ){
                                      
                                      __LINE__ = 255;
                                      _yieldState = -1;
                                      __LINE__ = 255;
                                      break;
                                    };
                                  case 1 :
                                    
                                    {
                                      
                                    };
                                    
                                    __LINE__ = 255;
                                    i ++ ;
                                    
                                    __LINE__ = 255;
                                    if ( i<10 ){
                                      
                                      __LINE__ = 0;
                                      _yieldState = 1;
                                      __LINE__ = 255;
                                      break;
                                    } else {
                                      
                                      __LINE__ = 0;
                                      _yieldState = -1;
                                    };
                                  case -1 :
                                    
                                    __LINE__ = 253;
                                    if ( _isYieldSafe ){
                                      __LINE__ = 253;
                                      return undefined;
                                    } else {
                                      __LINE__ = 253;
                                      Runtime.throwStopIteration();
                                    };
                                    
                                };
                              } catch( _mochaException ){
                                __LINE__ = 253;
                                if ( _mochaCatchCache ){
                                  
                                  __LINE__ = 253;
                                  var _mochaLocalTmp0 = _mochaCatchCache( _mochaException );
                                  
                                  __LINE__ = 253;
                                  if ( _mochaLocalTmp0 !== undefined ){
                                    __LINE__ = 253;
                                    return _mochaLocalTmp0;
                                  };
                                } else {
                                  __LINE__ = 253;
                                  Runtime.throwException( _mochaException );
                                };
                              } finally {
                                __LINE__ = 253;
                                if ( _mochaFinallyCache ){
                                  
                                  __LINE__ = 253;
                                  var _mochaLocalTmp1 = _mochaFinallyCache(  );
                                  
                                  __LINE__ = 253;
                                  if ( _mochaLocalTmp1 !== undefined ){
                                    __LINE__ = 253;
                                    return _mochaLocalTmp1;
                                  };
                                };
                              };
                            };
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 253;
                    return Runtime.createGenerator( _mochaGenerator,
                    function (  ) {
                      try {
                        __LINE__ = 253;
                        _yieldState = -1;
                        
                        __LINE__ = 253;
                        if ( _mochaFinallyCache ){
                          __LINE__ = 253;
                          _mochaFinallyCache(  );
                        };
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
                __LINE__ = 266;
                generator = yieldTest10();
                
                __LINE__ = 267;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",267,'./yield_test.js' );
                
                __LINE__ = 268;
                Runtime.assert( true,generator.next() === 1,"generator.next() === 1",268,'./yield_test.js' );
                
                __LINE__ = 269;
                Runtime.assert( true,generator.next() === 1,"generator.next() === 1",269,'./yield_test.js' );
                
                __LINE__ = 270;
                Runtime.assert( true,generator.next() === 1,"generator.next() === 1",270,'./yield_test.js' );
                
                __LINE__ = 271;
                Runtime.assert( true,generator.next() === 1,"generator.next() === 1",271,'./yield_test.js' );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case10 : function () {
              try {
                function yieldTest11(  ) {
                  try {
                    __LINE__ = 274;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 274;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 274;
                    var _yieldState = 0;
                    
                    __LINE__ = 276;
                    var type;
                    
                    __LINE__ = 275;
                    var i = 0;
                    
                    __LINE__ = 274;
                    var _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 274;
                            if ( !_isYieldSend ){
                              
                              __LINE__ = 274;
                              _mochaIsNewBorn = false;
                            } else if ( _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined ){
                              
                              __LINE__ = 274;
                              Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 274;
                            while ( 1 ){
                              __LINE__ = 274;
                              switch ( _yieldState ) {
                                case 0 :
                                  
                                  __LINE__ = 275;
                                  if ( !( i<10 ) ){
                                    
                                    __LINE__ = 275;
                                    _yieldState = -1;
                                    __LINE__ = 275;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 275;
                                  i ++ ;
                                  
                                  __LINE__ = 275;
                                  if ( i<10 ){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 1;
                                    __LINE__ = 275;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 274;
                                  if ( _isYieldSafe ){
                                    __LINE__ = 274;
                                    return undefined;
                                  } else {
                                    __LINE__ = 274;
                                    Runtime.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 274;
                    return Runtime.createGenerator( _mochaGenerator,
                    function (  ) {
                      try {
                        __LINE__ = 274;
                        _yieldState = -1;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
                __LINE__ = 289;
                generator = yieldTest11();
                
                __LINE__ = 290;
                generator.next();
                
                __LINE__ = 291;
                Runtime.assert( true,generator.send( 0 ) === 200,"generator.send( 0 ) === 200",291,'./yield_test.js' );
                
                __LINE__ = 292;
                generator.next();
                
                __LINE__ = 293;
                Runtime.assert( true,generator.send( 2 ) === 400,"generator.send( 2 ) === 400",293,'./yield_test.js' );
                
                __LINE__ = 294;
                generator.next();
                
                __LINE__ = 295;
                Runtime.assert( true,generator.send( 3 ) === 600,"generator.send( 3 ) === 600",295,'./yield_test.js' );
                
                __LINE__ = 296;
                generator.next();
                
                __LINE__ = 297;
                Runtime.assert( true,generator.send( null ) === 700,"generator.send( null ) === 700",297,'./yield_test.js' );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case11 : function () {
              try {
                function yieldTest12(  ) {
                  try {
                    __LINE__ = 301;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 301;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 301;
                    var _yieldState = 0;
                    
                    __LINE__ = 303;
                    var type;
                    
                    __LINE__ = 302;
                    var i = 0;
                    
                    __LINE__ = 301;
                    var _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 301;
                            if ( !_isYieldSend ){
                              
                              __LINE__ = 301;
                              _mochaIsNewBorn = false;
                            } else if ( _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined ){
                              
                              __LINE__ = 301;
                              Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 301;
                            while ( 1 ){
                              __LINE__ = 301;
                              switch ( _yieldState ) {
                                case 0 :
                                  
                                  __LINE__ = 302;
                                  if ( !( i<15 ) ){
                                    
                                    __LINE__ = 302;
                                    _yieldState = -1;
                                    __LINE__ = 302;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 302;
                                  i ++ ;
                                  
                                  __LINE__ = 302;
                                  if ( i<15 ){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 1;
                                    __LINE__ = 302;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 301;
                                  if ( _isYieldSafe ){
                                    __LINE__ = 301;
                                    return undefined;
                                  } else {
                                    __LINE__ = 301;
                                    Runtime.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 301;
                    return Runtime.createGenerator( _mochaGenerator,
                    function (  ) {
                      try {
                        __LINE__ = 301;
                        _yieldState = -1;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
                __LINE__ = 320;
                generator = yieldTest12();
                
                __LINE__ = 321;
                generator.next();
                
                __LINE__ = 322;
                Runtime.assert( true,generator.send( 0 ) === 200,"generator.send( 0 ) === 200",322,'./yield_test.js' );
                
                __LINE__ = 323;
                generator.next();
                
                __LINE__ = 324;
                Runtime.assert( true,generator.send( 4 ) === 200,"generator.send( 4 ) === 200",324,'./yield_test.js' );
                
                __LINE__ = 325;
                generator.next();
                
                __LINE__ = 326;
                Runtime.assert( true,generator.send( 2 ) === 400,"generator.send( 2 ) === 400",326,'./yield_test.js' );
                
                __LINE__ = 327;
                generator.next();
                
                __LINE__ = 328;
                Runtime.assert( true,generator.send( 5 ) === undefined,"generator.send( 5 ) === undefined",328,'./yield_test.js' );
                
                __LINE__ = 329;
                Runtime.assert( true,generator.send( 3 ) === 600,"generator.send( 3 ) === 600",329,'./yield_test.js' );
                
                __LINE__ = 330;
                generator.next();
                
                __LINE__ = 331;
                Runtime.assert( true,generator.send( null ) === 700,"generator.send( null ) === 700",331,'./yield_test.js' );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case12 : function () {
              try {
                function yieldTest13() {
                  try {
                    __LINE__ = 335;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 335;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 335;
                    var _yieldState = 0;
                    
                    __LINE__ = 337;
                    var length;
                    
                    __LINE__ = 337;
                    var _mochaLocalTmp4;
                    
                    __LINE__ = 337;
                    var i;
                    
                    __LINE__ = 336;
                    var obj;
                    
                    __LINE__ = 337;
                    var _mochaLocalTmp3 = [];
                    
                    __LINE__ = 335;
                    var _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 335;
                            if ( !_isYieldSend ){
                              
                              __LINE__ = 335;
                              _mochaIsNewBorn = false;
                            } else if ( _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined ){
                              
                              __LINE__ = 335;
                              Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 335;
                            while ( 1 ){
                              __LINE__ = 335;
                              switch ( _yieldState ) {
                                case 0 :
                                  
                                  __LINE__ = 337;
                                  for ( var _mochaLocalTmp2 in obj ){
                                    
                                    __LINE__ = 337;
                                    _mochaLocalTmp3.push( _mochaLocalTmp2 );
                                  };
                                  
                                  __LINE__ = 337;
                                  if ( !( _mochaLocalTmp4<length ) ){
                                    
                                    __LINE__ = 337;
                                    _yieldState = -1;
                                    __LINE__ = 337;
                                    break;
                                  };
                                case 1 :
                                  []
                                  __LINE__ = 337;
                                   ++ _mochaLocalTmp4;
                                  
                                  __LINE__ = 337;
                                  if ( _mochaLocalTmp4<length ){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 1;
                                    __LINE__ = 337;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 335;
                                  if ( _isYieldSafe ){
                                    __LINE__ = 335;
                                    return undefined;
                                  } else {
                                    __LINE__ = 335;
                                    Runtime.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 335;
                    return Runtime.createGenerator( _mochaGenerator,
                    function (  ) {
                      try {
                        __LINE__ = 335;
                        _yieldState = -1;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
                __LINE__ = 342;
                generator = yieldTest13();
                
                __LINE__ = 343;
                var ret = generator.next();
                
                __LINE__ = 344;
                Runtime.assert( true,ret[0] === "x","ret[0] === \"x\"",344,'./yield_test.js' );
                
                __LINE__ = 345;
                Runtime.assert( true,ret[1] === 200,"ret[1] === 200",345,'./yield_test.js' );
                
                __LINE__ = 346;
                ret = generator.next();
                
                __LINE__ = 347;
                Runtime.assert( true,ret[0] === "y","ret[0] === \"y\"",347,'./yield_test.js' );
                
                __LINE__ = 348;
                Runtime.assert( true,ret[1] === 300,"ret[1] === 300",348,'./yield_test.js' );
                
                __LINE__ = 349;
                ret = generator.next();
                
                __LINE__ = 350;
                Runtime.assert( true,ret[0] === "z","ret[0] === \"z\"",350,'./yield_test.js' );
                
                __LINE__ = 351;
                Runtime.assert( true,ret[1] === 400,"ret[1] === 400",351,'./yield_test.js' );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case13 : function () {
              try {
                function keys( obj ) {
                  try {
                    __LINE__ = 354;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 354;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 354;
                    var _yieldState = 0;
                    
                    __LINE__ = 355;
                    var length;
                    
                    __LINE__ = 355;
                    var _mochaLocalTmp7;
                    
                    __LINE__ = 355;
                    var prop;
                    
                    __LINE__ = 355;
                    var _mochaLocalTmp6 = [];
                    
                    __LINE__ = 354;
                    var _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 354;
                            if ( !_isYieldSend ){
                              
                              __LINE__ = 354;
                              _mochaIsNewBorn = false;
                            } else if ( _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined ){
                              
                              __LINE__ = 354;
                              Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 354;
                            while ( 1 ){
                              __LINE__ = 354;
                              switch ( _yieldState ) {
                                case 0 :
                                  
                                  __LINE__ = 355;
                                  for ( var _mochaLocalTmp5 in obj ){
                                    
                                    __LINE__ = 355;
                                    _mochaLocalTmp6.push( _mochaLocalTmp5 );
                                  };
                                  
                                  __LINE__ = 355;
                                  if ( !( _mochaLocalTmp7<length ) ){
                                    
                                    __LINE__ = 355;
                                    _yieldState = -1;
                                    __LINE__ = 355;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 355;
                                   ++ _mochaLocalTmp7;
                                  
                                  __LINE__ = 355;
                                  if ( _mochaLocalTmp7<length ){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 1;
                                    __LINE__ = 355;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 354;
                                  if ( _isYieldSafe ){
                                    __LINE__ = 354;
                                    return undefined;
                                  } else {
                                    __LINE__ = 354;
                                    Runtime.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 354;
                    return Runtime.createGenerator( _mochaGenerator,
                    function (  ) {
                      try {
                        __LINE__ = 354;
                        _yieldState = -1;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
                __LINE__ = 362;
                var testObject =  {
                      value1 : 1,
                      value2 : 2,
                      value3 : 3,
                      value4 : 4
                    };
                
                try {
                  
                  __LINE__ = 369;
                  var itemGen = keys( testObject );
                  __LINE__ = 370;
                  Runtime.assert( true,itemGen.next() == "value1","itemGen.next() == \"value1\"",370,'./yield_test.js' );
                  __LINE__ = 371;
                  Runtime.assert( true,itemGen.next() == "value2","itemGen.next() == \"value2\"",371,'./yield_test.js' );
                  __LINE__ = 372;
                  Runtime.assert( true,itemGen.next() == "value3","itemGen.next() == \"value3\"",372,'./yield_test.js' );
                  __LINE__ = 373;
                  Runtime.assert( true,itemGen.next() == "value4","itemGen.next() == \"value4\"",373,'./yield_test.js' );
                } catch( e ){
                  
                };
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            }
          };
      
      __LINE__ = 382;
      for ( var i = 1;i<13;i ++  ){
        
        __LINE__ = 383;
        tests["case"+i]();
      };
    } catch( e ){
      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  }();
}();
