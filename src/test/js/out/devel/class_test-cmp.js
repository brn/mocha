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
      var __FILE__ = "/Users/aono_taketoshi/github/mocha/src/test/js/harmony/class_test.js",
          __LINE__ = 0;
      __LINE__ = 2;
      _mochaGlobalExport['./class_test.js'] = {};
      
      __LINE__ = 3;
      var _mochaGlobalAlias = _mochaGlobalExport['./class_test.js'];
      
      __LINE__ = 1;
      var Monster = function () {
            try {
              __LINE__ = 1;
              var _mochaPrivateHolder = function (){};
              
              function Monster() {
                try {
                  __LINE__ = 1;
                  Runtime.initializeClass( this,Monster,_mochaPrivateHolder,constructor,arguments,'Monster','1' );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
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
              __LINE__ = 7;
              Runtime.createUnenumProp( constructor,"__harmony_class__",1 );
              
              __LINE__ = 15;
              Monster.prototype.attack = function ( target ) {
                try {
                  __LINE__ = 16;
                  log( 'The monster attacks '+target );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 22;
              Monster.prototype.isAlive = function () {
                try {
                  __LINE__ = 23;
                  return Runtime.getPrivateRecord( this ).health>0;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 27;
              Monster.prototype.health = function ( value ) {
                try {
                  __LINE__ = 28;
                  if ( value<0 ){
                    __LINE__ = 29;
                    throw new Error( 'Health must be non-negative.' );
                  };
                  
                  __LINE__ = 31;
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
              
              __LINE__ = 1;
              Runtime.createUnenumProp( Monster.prototype,"constructor",constructor );
              __LINE__ = 1;
              return Monster;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }();
      
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
      var BaseTest = function () {
            try {
              __LINE__ = 52;
              var _mochaPrivateHolder = function (){};
              
              function BaseTest() {
                try {
                  __LINE__ = 52;
                  Runtime.initializeClass( this,BaseTest,_mochaPrivateHolder,constructor,arguments,'BaseTest','52' );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              function constructor( _mochaLocalTmp0,_mochaLocalTmp1,_mochaLocalTmp2 ) {
                try {
                  __LINE__ = 53;
                  this.name = _mochaLocalTmp0 || 200;
                  
                  __LINE__ = 53;
                  Runtime.getPrivateRecord( this ).addr = _mochaLocalTmp1 || "tokyo";
                  
                  __LINE__ = 53;
                  Runtime.getPrivateRecord( this ).age = _mochaLocalTmp2;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              __LINE__ = 53;
              Runtime.createUnenumProp( constructor,"__harmony_class__",1 );
              
              __LINE__ = 54;
              BaseTest.prototype.getName = function () {
                try {
                  __LINE__ = 55;
                  return "hogehoge";
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 57;
              BaseTest.getName = function () {
                try {
                  __LINE__ = 57;
                  return "static hogehoge";
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 52;
              Runtime.createUnenumProp( BaseTest.prototype,"constructor",constructor );
              __LINE__ = 52;
              return BaseTest;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }();
      
      __LINE__ = 60;
      var DeriveTest = function () {
            try {
              __LINE__ = 60;
              var _mochaPrivateHolder = function (){};
              
              function DeriveTest() {
                try {
                  __LINE__ = 60;
                  Runtime.initializeClass( this,DeriveTest,_mochaPrivateHolder,constructor,arguments,'DeriveTest','60' );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              __LINE__ = 60;
              var _mochaLocalTmp3 = BaseTest;
              
              __LINE__ = 60;
              Runtime.extendClass( DeriveTest,_mochaLocalTmp3 );
              
              __LINE__ = 60;
              var _mochaSuper = Runtime.getSuper( _mochaLocalTmp3 );
              
              function constructor() {
                try {
                  __LINE__ = 62;
                  _mochaSuper.constructor.call( this );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              __LINE__ = 61;
              Runtime.createUnenumProp( constructor,"__harmony_class__",1 );
              
              __LINE__ = 64;
              _mochaPrivateHolder.prototype.getName = function () {
                try {
                  __LINE__ = 65;
                  return _mochaSuper.getName.constructor.call( this );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 60;
              Runtime.createUnenumProp( DeriveTest.prototype,"constructor",constructor );
              __LINE__ = 60;
              return DeriveTest;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }();
      
      __LINE__ = 70;
      var Derive2 = function () {
            try {
              __LINE__ = 70;
              var _mochaPrivateHolder = function (){};
              
              function Derive2() {
                try {
                  __LINE__ = 70;
                  Runtime.initializeClass( this,Derive2,_mochaPrivateHolder,constructor,arguments,'Derive2','70' );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              __LINE__ = 70;
              var _mochaLocalTmp4 = DeriveTest;
              
              __LINE__ = 70;
              Runtime.extendClass( Derive2,_mochaLocalTmp4 );
              
              __LINE__ = 70;
              var _mochaSuper = Runtime.getSuper( _mochaLocalTmp4 );
              
              function constructor() {
                try {
                  __LINE__ = 71;
                  return _mochaSuper.constructor.call( this );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              __LINE__ = 71;
              Runtime.createUnenumProp( constructor,"__harmony_class__",1 );
              
              __LINE__ = 72;
              Derive2.prototype.getAddr = function () {
                try {
                  __LINE__ = 72;
                  return Runtime.getPrivateRecord( this ).addr;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 70;
              Runtime.createUnenumProp( Derive2.prototype,"constructor",constructor );
              __LINE__ = 70;
              return Derive2;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }();
      
      __LINE__ = 76;
      var TestClass = function () {
            try {
              __LINE__ = 76;
              var _mochaPrivateHolder = function (){};
              
              function _mochaLocalTmp5() {
                try {
                  __LINE__ = 76;
                  Runtime.initializeClass( this,_mochaLocalTmp5,_mochaPrivateHolder,constructor,arguments,'_mochaLocalTmp5','76' );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              function constructor( _mochaLocalTmp6,_mochaLocalTmp7 ) {
                try {
                  __LINE__ = 77;
                  Runtime.getPrivateRecord( this )._name = _mochaLocalTmp6 || "test";
                  
                  __LINE__ = 77;
                  Runtime.getPrivateRecord( this )._age = _mochaLocalTmp7 || 20;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              __LINE__ = 77;
              Runtime.createUnenumProp( constructor,"__harmony_class__",1 );
              
              __LINE__ = 78;
              _mochaLocalTmp5.prototype.getName = function () {
                try {
                  __LINE__ = 78;
                  return Runtime.getPrivateRecord( this )._name;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 79;
              _mochaLocalTmp5.prototype.getAge = function () {
                try {
                  __LINE__ = 79;
                  return Runtime.getPrivateRecord( this )._age;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 76;
              Runtime.createUnenumProp( _mochaLocalTmp5.prototype,"constructor",constructor );
              __LINE__ = 76;
              return _mochaLocalTmp5;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }();
      
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
      
      __LINE__ = 92;
      function () {
        try {
          __LINE__ = 92;
          var TestTrait =  {
                _mochaTraitPrivate : {},
                _mochaTraitPublic :  {
                  testm1 : function testm1(  ) {
                    try {
                      __LINE__ = 94;
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
          __LINE__ = 92;
          return TestTrait;
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }();
      
      __LINE__ = 97;
      function () {
        try {
          __LINE__ = 97;
          var TestTrait2 =  {
                _mochaTraitPrivate : {},
                _mochaTraitPublic :  {
                  testm2 : function testm2(  ) {
                    try {
                      __LINE__ = 99;
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
          __LINE__ = 97;
          return TestTrait2;
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }();
      
      __LINE__ = 103;
      var MixinTest = function () {
            try {
              __LINE__ = 103;
              var _mochaPrivateHolder = function (){};
              
              function MixinTest() {
                try {
                  __LINE__ = 103;
                  Runtime.initializeClass( this,MixinTest,_mochaPrivateHolder,constructor,arguments,'MixinTest','103' );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              function constructor(){}
              __LINE__ = 103;
              Runtime.createUnenumProp( constructor,"__harmony_class__",1 );
              
              __LINE__ = 104;
              MixinTest.prototype.doTestm1 = function () {
                try {
                  __LINE__ = 104;
                  return "aaa";
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 105;
              MixinTest.prototype.doTestm2 = function () {
                try {
                  __LINE__ = 105;
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
              
              __LINE__ = 103;
              Runtime.checkRequirements( MixinTest,_mochaPrivateHolder,[],'./class_test.js',107 );
              
              __LINE__ = 103;
              Runtime.createUnenumProp( MixinTest.prototype,"constructor",constructor );
              __LINE__ = 103;
              return MixinTest;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }();
      
      __LINE__ = 109;
      var instance2 = new MixinTest();
      
      __LINE__ = 110;
      Runtime.assert( true,instance2.m1( "foo" ) === "foo","instance2.m1( \"foo\" ) === \"foo\"",110,'./class_test.js' );
      
      __LINE__ = 111;
      Runtime.assert( true,instance2.m2 === undefined,"instance2.m2 === undefined",111,'./class_test.js' );
      
      __LINE__ = 114;
      var Box = function () {
            try {
              __LINE__ = 114;
              var _mochaPrivateHolder = function (){};
              
              function Box() {
                try {
                  __LINE__ = 114;
                  Runtime.initializeClass( this,Box,_mochaPrivateHolder,constructor,arguments,'Box','114' );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              function constructor( _mochaLocalTmp8,_mochaLocalTmp9 ) {
                try {
                  __LINE__ = 115;
                  Runtime.getPrivateRecord( this ).width = _mochaLocalTmp8 || 100;
                  
                  __LINE__ = 115;
                  Runtime.getPrivateRecord( this ).height = _mochaLocalTmp9 || 100;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              __LINE__ = 115;
              Runtime.createUnenumProp( constructor,"__harmony_class__",1 );
              
              __LINE__ = 116;
              Box.prototype.height = function () {
                try {
                  __LINE__ = 116;
                  return Runtime.getPrivateRecord( this ).height;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 117;
              Box.prototype.width = function () {
                try {
                  __LINE__ = 117;
                  return Runtime.getPrivateRecord( this ).width;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 118;
              var _mochaLocalTmp10 =  {
                    type : 200,
                    _max : 400
                  };
              
              __LINE__ = 118;
              _mochaPrivateHolder.prototype._type = _mochaLocalTmp10._type;
              
              __LINE__ = 118;
              _mochaPrivateHolder.prototype._max = _mochaLocalTmp10._max;
              
              __LINE__ = 114;
              Runtime.createUnenumProp( Box.prototype,"constructor",constructor );
              __LINE__ = 114;
              return Box;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }();
      
      __LINE__ = 121;
      var inst = new Box();
      
      __LINE__ = 122;
      console.log( inst.height() );
      
      __LINE__ = 123;
      console.log( inst.width() );
    } catch( e ){
      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  }();
}();
