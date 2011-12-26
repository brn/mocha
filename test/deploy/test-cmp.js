(function() {
  var __LINE__ = 0;
  var __FILE__ = "Runtime";
  
  __LINE__ = 0;
  this.x = 0;
  
  __LINE__ = 1;
  var _mochaGlobalExport = {},
      _mochaClassTable = {},
      _mochaInstanceTable = {},
      _mochaInstanceId = ( +(new Date) );
  
  __LINE__ = 6;
  var Runtime = ( function Runtime() {
        try {
          __LINE__ = 6;
          var _mochaLocalExport = {};
          
          __LINE__ = 8;
          if ( !String.prototype.trim ){
            __LINE__ = 9;
            String.prototype.trim = function () {
              try {
                __LINE__ = 9;
                return this.replace( String.prototype.trim.rtrim,"" );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
            
            __LINE__ = 10;
            String.prototype.trim.rtrim = /^\s*|\s*$/g;
          };
          
          __LINE__ = 13;
          if ( !Function.prototype.bind ){
            __LINE__ = 14;
            Function.prototype.bind = function () {
              try {
                __LINE__ = 15;
                var argArray = Array.prototype.slice.call( arguments ),
                    context = argArray.shift(),
                    ret = function () {
                      try {
                        __LINE__ = 18;
                        var args = argArray.concat( Array.prototype.slice.call( arguments ) );
                        
                        __LINE__ = 19;
                        if ( this instanceof ret ){
                          __LINE__ = 20;
                          return ret.context.apply( this,args );
                        } else {
                          __LINE__ = 22;
                          return ret.context.apply( context,args );
                        };
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    };
                
                __LINE__ = 25;
                ret.prototype = this.prototype;
                
                __LINE__ = 26;
                ret.context = this;
                __LINE__ = 27;
                return ret;
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          };
          
          __LINE__ = 31;
          if ( !Array.prototype.forEach ){
            __LINE__ = 32;
            Array.prototype.forEach = function ( fn,that ) {
              try {
                __LINE__ = 33;
                var iter = -1,
                    ta;
                
                __LINE__ = 35;
                if ( that ){
                  __LINE__ = 36;
                  while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                    __LINE__ = 37;
                    fn.call( that,ta,iter,this );
                  };
                } else {
                  __LINE__ = 40;
                  while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                    __LINE__ = 41;
                    fn( ta,iter,this );
                  };
                };
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          };
          
          __LINE__ = 47;
          if ( !Array.prototype.every ){
            __LINE__ = 48;
            Array.prototype.every = function ( fn,that ) {
              try {
                __LINE__ = 49;
                var iter = -1,
                    ta;
                
                __LINE__ = 51;
                if ( that ){
                  __LINE__ = 52;
                  while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                    __LINE__ = 53;
                    if ( !( fn.call( that,ta,iter,this ) ) ){
                      __LINE__ = 54;
                      return false;
                    };
                  };
                } else {
                  __LINE__ = 58;
                  while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                    if ( !( fn( ta,iter,this ) ) ){
                      __LINE__ = 60;
                      return false;
                    };
                  };
                };
                __LINE__ = 64;
                return true;
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          };
          
          __LINE__ = 68;
          if ( !Array.prototype.some ){
            __LINE__ = 69;
            Array.prototype.some = function ( fn,that ) {
              try {
                __LINE__ = 70;
                var iter = -1,
                    ta;
                
                __LINE__ = 72;
                if ( that ){
                  __LINE__ = 73;
                  while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                    __LINE__ = 74;
                    if ( fn.call( that,ta,iter,this ) ){
                      __LINE__ = 75;
                      return true;
                    };
                  };
                } else {
                  __LINE__ = 79;
                  while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                    if ( fn( ta,iter,this ) ){
                      __LINE__ = 81;
                      return true;
                    };
                  };
                };
                __LINE__ = 85;
                return false;
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          };
          
          __LINE__ = 89;
          if ( !Array.prototype.filter ){
            __LINE__ = 90;
            Array.prototype.filter = function ( fn,that ) {
              try {
                __LINE__ = 91;
                var iter = -1,
                    ret = [],
                    ta;
                
                __LINE__ = 94;
                if ( that ){
                  __LINE__ = 95;
                  for ( var i = 0,len = this.length;i<len; ++ i )
                  {
                    __LINE__ = 96;
                    if ( ( ta = this[i] ) !== null && ta !== undefined ){
                      __LINE__ = 97;
                      if ( fn.call( that,ta,i,this ) ){
                        __LINE__ = 98;
                        ret[ ++ iter] = ta;
                      };
                    };
                  };
                } else {
                  __LINE__ = 103;
                  for ( var i = 0,len = this.length;i<len; ++ i )
                  {
                    if ( ( ta = this[i] ) !== null && ta !== undefined ){
                      if ( fn( ta,i,this ) ){
                        __LINE__ = 106;
                        ret[ ++ iter] = ta;
                      };
                    };
                  };
                };
                __LINE__ = 111;
                return ret;
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          };
          
          __LINE__ = 115;
          if ( !Array.prototype.indexOf ){
            __LINE__ = 116;
            Array.prototype.indexOf = function ( subject ) {
              try {
                __LINE__ = 117;
                var iter = -1,
                    index = -1,
                    ta;
                
                __LINE__ = 120;
                while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                  __LINE__ = 121;
                  if ( ta === subject ){
                    __LINE__ = 122;
                    index = iter;
                    __LINE__ = 123;
                    break;
                  };
                };
                __LINE__ = 126;
                return index;
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          };
          
          __LINE__ = 130;
          if ( !Array.prototype.lastIndexOf ){
            __LINE__ = 131;
            Array.prototype.lastIndexOf = function ( subject ) {
              try {
                __LINE__ = 132;
                var iter = this.length,
                    index = -1,
                    ta;
                
                __LINE__ = 135;
                while ( ( ta = this[ -- iter] ) !== null && ta !== undefined ){
                  __LINE__ = 136;
                  if ( ta === subject ){
                    __LINE__ = 137;
                    index = iter;
                    __LINE__ = 138;
                    break;
                  };
                };
                __LINE__ = 141;
                return index;
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          };
          
          __LINE__ = 145;
          if ( !Array.prototype.map ){
            __LINE__ = 146;
            Array.prototype.map = function ( fn,that ) {
              try {
                __LINE__ = 147;
                var ret = [],
                    iter = -1,
                    ta;
                
                __LINE__ = 150;
                if ( that ){
                  __LINE__ = 151;
                  for ( var i = 0,len = this.length;i<len; ++ i )
                  {
                    __LINE__ = 152;
                    if ( ( ta = this[i] ) !== null && ta !== undefined ){
                      __LINE__ = 153;
                      ret[ ++ iter] = fn.call( that,ta,i,this );
                    };
                  };
                } else {
                  __LINE__ = 157;
                  for ( var i = 0,len = this.length;i<len; ++ i )
                  {
                    if ( ( ta = this[i] ) !== null && ta !== undefined ){
                      __LINE__ = 159;
                      ret[ ++ iter] = fn( ta,i,this );
                    };
                  };
                };
                __LINE__ = 163;
                return ret;
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          };
          
          __LINE__ = 167;
          if ( !Array.prototype.reduce ){
            __LINE__ = 168;
            Array.prototype.reduce = function ( fn,initial ) {
              try {
                __LINE__ = 169;
                var ret = initial || this[0],
                    i = ( ( initial ) )?0 : 1,
                    ta,
                    len;
                
                __LINE__ = 173;
                for ( i , len = this.length;i<len; ++ i ){
                  __LINE__ = 174;
                  if ( ( ta = this[i] ) !== null && ta !== undefined ){
                    __LINE__ = 175;
                    ret = fn( ret,ta,i,this );
                  };
                };
                __LINE__ = 178;
                return ret;
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          };
          
          __LINE__ = 182;
          if ( !Array.prototype.reduceRight ){
            __LINE__ = 183;
            Array.prototype.reduceRight = function ( fn,initial ) {
              try {
                __LINE__ = 184;
                var ret = initial || this[this.length-1],
                    i = ( ( initial ) )?this.length-1 : this.length-2,
                    ta;
                
                __LINE__ = 187;
                for ( i;i>-1; -- i ){
                  __LINE__ = 188;
                  if ( ( ta = this[i] ) !== null && ta !== undefined ){
                    __LINE__ = 189;
                    ret = fn( ret,ta,i,this );
                  };
                };
                __LINE__ = 192;
                return ret;
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          };
          
          __LINE__ = 196;
          if ( !Date.prototype.toJSON ){
            __LINE__ = 197;
            Date.prototype.toJSON = function () {
              try {
                __LINE__ = 204;
                return '"'+this.getUTCFullYear()+'-'+"0"+( this.getUTCMonth()+1 )+'-'+"0"+( this.getUTCDate()-1 )+'T'+this.getUTCHours()+':'+this.getMinutes()+':'+this.getSeconds()+'.'+this.getUTCMilliseconds()+'"';
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          };
          
          __LINE__ = 207;
          if ( !Date.now ){
            __LINE__ = 208;
            Date.now = function () {
              try {
                __LINE__ = 208;
                return +(new Date);
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          };
          
          __LINE__ = 211;
          if ( !Object.keys ){
            __LINE__ = 212;
            Object.keys = function ( obj ) {
              try {
                __LINE__ = 213;
                var ret = [],
                    iter = -1;
                
                __LINE__ = 216;
                for ( var i in obj )
                {
                  __LINE__ = 217;
                  if ( obj.hasOwnProperty( i ) ){
                    __LINE__ = 218;
                    ret[ ++ iter] = obj[i];
                  };
                };
                __LINE__ = 222;
                return ret;
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          };
          
          __LINE__ = 227;
          if ( !Object.preventExtensions ){
            __LINE__ = 228;
            Object.preventExtensions = function ( o ) {
              try {
                __LINE__ = 228;
                return o;
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          };
          
          __LINE__ = 231;
          if ( !Object.seal ){
            __LINE__ = 232;
            Object.seal = function ( o ) {
              try {
                __LINE__ = 232;
                return o;
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          };
          
          __LINE__ = 235;
          if ( !Object.freeze ){
            __LINE__ = 236;
            Object.freeze = function ( o ) {
              try {
                __LINE__ = 236;
                return o;
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          };
          
          __LINE__ = 239;
          var hasRealEcma5 = ( function () {
                try {
                  try {
                    __LINE__ = 241;
                    var obj = {};
                    
                    __LINE__ = 242;
                    Object.defineProperty( obj,"test", {
                      configurable : false,
                      writable : false,
                      enumerable : false,
                      value : 0
                    });
                    
                    __LINE__ = 248;
                    obj.test = 200;
                    __LINE__ = 249;
                    return ( ( obj.test === 200 ) )?false : true;
                  } catch( e ){
                    __LINE__ = 251;
                    return false;
                  };
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              })();
          
          __LINE__ = 255;
          if ( !hasRealEcma5 ){
            __LINE__ = 256;
            Object.defineProperty = function ( obj,prop,valobj ) {
              try {
                __LINE__ = 257;
                if ( valobj.value ){
                  __LINE__ = 258;
                  obj[prop] = valobj.value;
                };
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          };
          
          __LINE__ = 263;
          if ( !Array.isArray ){
            __LINE__ = 264;
            var arrayString = "[object Array]";
            
            __LINE__ = 265;
            Array.isArray = function ( arr ) {
              try {
                __LINE__ = 266;
                if ( arguments.length === 0 ){
                  __LINE__ = 267;
                  return false;
                };
                __LINE__ = 269;
                return ( ( arr ) )?Object.prototype.toString.call( arr ) === arrayString : false;
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          };
          
          __LINE__ = 273;
          var instanceProp = {},
              slice = Array.prototype.slice;
          
          __LINE__ = 276;
          var createUnenumProp = _mochaLocalExport.createUnenumProp = function ( obj,prop,value ) {
                try {
                  __LINE__ = 276;
                  return Object.defineProperty( obj,prop, {
                    configurable : true,
                    enumerable : false,
                    writable : true,
                    value : value
                  });
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
          
          __LINE__ = 283;
          var constant = _mochaLocalExport.constant = function ( obj,prop,value ) {
                try {
                  __LINE__ = 283;
                  return Object.defineProperty( obj,prop, {
                    configurable : false,
                    enumerable : false,
                    writable : false,
                    value : value
                  });
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
          
          __LINE__ = 290;
          var toArray = _mochaLocalExport.toArray = function ( likeArray ) {
                try {
                  __LINE__ = 290;
                  return ( ( likeArray ) )?slice.call( likeArray ) : [];
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
          __LINE__ = 0;
          return _mochaLocalExport;
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      })();
  
  __LINE__ = 0;
  ( function () {
    try {
      var __FILE__ = "/Users/aono_taketoshi/github/mocha/test/mains/fmt.js";
      __LINE__ = 2;
      _mochaGlobalExport['{1-397-1092-205522212-1695-60819241-2230-fmt.js}'] = {};
      
      __LINE__ = 3;
      var _mochaGlobalAlias = _mochaGlobalExport['{1-397-1092-205522212-1695-60819241-2230-fmt.js}'];
      
      __LINE__ = 0;
      var x = function ( _mochaLocalTmp0,_mochaLocalTmp1 ) {
            try {
              __LINE__ = 0;
              _mochaLocalTmp1 = _mochaLocalTmp1 || [ {
                y : 200
              }];
              
              __LINE__ = 0;
              var m = _mochaLocalTmp0.m,
                  y = _mochaLocalTmp1[0],
                  rest = Runtime.toArray( arguments,2 );
              
              __LINE__ = 1;
              var _mochaLocalTmp2 = [0,1,2,3],
                  x = ( _mochaLocalTmp2.x && _mochaLocalTmp2.x[0] )?_mochaLocalTmp2.x[0] : undefined,
                  m2 = ( _mochaLocalTmp2.x )?Runtime.toArray( _mochaLocalTmp2,1 ) : undefined;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
      
      __LINE__ = 4;
      var m = function ( v,g ) {
            try {
              __LINE__ = 0;
              v = v || 200;
              
              __LINE__ = 0;
              g = g || 200;
              __LINE__ = 4;
              return v+g;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
      
      __LINE__ = 5;
      var _mochaLocalTmp3 = [0,1,2],
          x = _mochaLocalTmp3[0],
          y = _mochaLocalTmp3[1],
          z = _mochaLocalTmp3[2];
      
      __LINE__ = 0;
      var _mochaLocalTmp4;
      
      __LINE__ = 7;
      _mochaLocalTmp4 = [z,y,x];
      
      __LINE__ = 10;
      ( function () {
        try {
          __LINE__ = 10;
          var _mochaLocalExport = _mochaGlobalAlias;
          
          __LINE__ = 0;
          _mochaLocalExport.name = function name(){};
          __LINE__ = 0;
          return _mochaLocalExport;
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      })();
      
      __LINE__ = 14;
      console.log( _mochaGlobalAlias.name );
    } catch( e ){
      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  })();
  
  __LINE__ = 0;
  ( function () {
    try {
      var __FILE__ = "/Users/aono_taketoshi/github/mocha/test/mains/test.js";
      __LINE__ = 2;
      _mochaGlobalExport['{1-397-1092-205522212-1695-60819241-2230-test.js}'] = {};
      
      __LINE__ = 3;
      var _mochaGlobalAlias = _mochaGlobalExport['{1-397-1092-205522212-1695-60819241-2230-test.js}'];
      
      __LINE__ = 0;
      var _mochaLocalTmp0 = _mochaGlobalExport['{1-397-1092-205522212-1695-60819241-2230-fmt.js}'],
          fmt = _mochaLocalTmp0.fmt;
      
      __LINE__ = 1;
      if ( x ){
        
      } else if ( z ){
        
      };
      
      __LINE__ = 4;
      ( function () {
        try {
          __LINE__ = 4;
          var _mochaLocalExport = _mochaGlobalAlias;
          
          __LINE__ = 5;
          var x = _mochaLocalExport.x = 0;
          
          __LINE__ = 6;
          var Monster = _mochaLocalExport.Monster = ( function () {
                try {
                  __LINE__ = 0;
                  var _mochaPrivateHolder = function (){};
                  
                  __LINE__ = 6;
                  function Monster() {
                    try {
                      __LINE__ = 0;
                      Runtime.createUnenumProp( this,'__private__',new _mochaPrivateHolder );
                      
                      __LINE__ = 0;
                      Monster.constructor.apply( this,arguments );
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  };
                  
                  __LINE__ = 6;
                  Runtime.extendClass( Monster,test["200"] );
                  
                  __LINE__ = 12;
                  Runtime.createUnenumProp( Monster,'constructor',
                  function constructor( name,health ) {
                    try {
                      
                      __LINE__ = 13;
                      this.name = name;
                      
                      __LINE__ = 14;
                      var _mochaLocalTmp2 =  {
                            x : 200
                          };
                      
                      __LINE__ = 14;
                      Runtime.constant( this.__private__,'name',( _mochaLocalTmp2.x && _mochaLocalTmp2.x[0] )?_mochaLocalTmp2.x[0] : undefined );
                      
                      __LINE__ = 14;
                      Runtime.constant( this.__private__,'age',( _mochaLocalTmp2.x && _mochaLocalTmp2.x[1] )?_mochaLocalTmp2.x[1] : undefined );
                      
                      __LINE__ = 14;
                      Runtime.constant( this.__private__,'hobby',( _mochaLocalTmp2.x && _mochaLocalTmp2.x[2] && _mochaLocalTmp2.x[2].hobby )?_mochaLocalTmp2.x[2].hobby : undefined );
                      
                      __LINE__ = 15;
                      Runtime.constant( this.__private__,'_tmpName',name );
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  });
                  
                  __LINE__ = 49;
                  Monster.prototype.numAttacks = 0;
                  
                  __LINE__ = 56;
                  Runtime.constant( Monster.prototype,'attackMessage','The monster hits you!' );
                  
                  __LINE__ = 28;
                  _mochaPrivateHolder.prototype.isAlive = function isAlive() {
                    try {
                      __LINE__ = 29;
                      return this.__private__._health>0;
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  };
                  
                  __LINE__ = 33;
                  _mochaPrivateHolder.prototype.health = function health( value ) {
                    try {
                      __LINE__ = 0;
                      if ( value<0 ){
                        __LINE__ = 0;
                        throw new Error( 'Health must be non-negative.' );
                      };
                      
                      __LINE__ = 37;
                      this.__private__._health = value;
                      __LINE__ = 38;
                      return this.__private__.value+"tmpName";
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  };
                  
                  __LINE__ = 40;
                  _mochaPrivateHolder.prototype.x = ( function () {
                    try {
                      __LINE__ = 0;
                      var _mochaPrivateHolder = function (){};
                      
                      __LINE__ = 40;
                      function x() {
                        try {
                          __LINE__ = 0;
                          Runtime.createUnenumProp( this,'__private__',new _mochaPrivateHolder );
                          
                          __LINE__ = 0;
                          x.constructor.apply( this,arguments );
                        } catch( e ){
                          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      };
                      
                      __LINE__ = 41;
                      _mochaPrivateHolder.prototype.constructor = function constructor() {
                        try {
                          __LINE__ = 42;
                          this.m = 200;
                        } catch( e ){
                          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      };
                      __LINE__ = 0;
                      return x;
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  })();
                  
                  __LINE__ = 21;
                  _mochaPrivateHolder.prototype.attack = function attack( target ) {
                    try {
                      __LINE__ = 22;
                      log( 'The monster attacks '+target );
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  };
                  
                  __LINE__ = 50;
                  Runtime.constant( Monster,'constant',200 );
                  
                  __LINE__ = 51;
                  var _mochaLocalTmp4 = human;
                  
                  __LINE__ = 51;
                  Monster.h1 = ( _mochaLocalTmp4.human && _mochaLocalTmp4.human.name && _mochaLocalTmp4.human.name.age && _mochaLocalTmp4.human.name.age.hobby && _mochaLocalTmp4.human.name.age.hobby[0] )?_mochaLocalTmp4.human.name.age.hobby[0] : undefined;
                  
                  __LINE__ = 51;
                  Monster.h2 = ( _mochaLocalTmp4.human && _mochaLocalTmp4.human.name && _mochaLocalTmp4.human.name.age && _mochaLocalTmp4.human.name.age.hobby && _mochaLocalTmp4.human.name.age.hobby[1] )?_mochaLocalTmp4.human.name.age.hobby[1] : undefined;
                  
                  __LINE__ = 51;
                  Monster.h3 = ( _mochaLocalTmp4.human && _mochaLocalTmp4.human.name && _mochaLocalTmp4.human.name.age && _mochaLocalTmp4.human.name.age.hobby && _mochaLocalTmp4.human.name.age.hobby[2] )?_mochaLocalTmp4.human.name.age.hobby[2] : undefined;
                  
                  __LINE__ = 52;
                  var _mochaLocalTmp5 = human_;
                  
                  __LINE__ = 52;
                  Monster.h1_ = ( _mochaLocalTmp5.human_ && _mochaLocalTmp5.human_.name_ && _mochaLocalTmp5.human_.name_.age_ && _mochaLocalTmp5.human_.name_.age_.hobby_ && _mochaLocalTmp5.human_.name_.age_.hobby_[0] )?_mochaLocalTmp5.human_.name_.age_.hobby_[0] : undefined;
                  
                  __LINE__ = 52;
                  Monster.h2_ = ( _mochaLocalTmp5.human_ && _mochaLocalTmp5.human_.name_ && _mochaLocalTmp5.human_.name_.age_ && _mochaLocalTmp5.human_.name_.age_.hobby_ && _mochaLocalTmp5.human_.name_.age_.hobby_[1] )?_mochaLocalTmp5.human_.name_.age_.hobby_[1] : undefined;
                  
                  __LINE__ = 52;
                  Monster.h3_ = ( _mochaLocalTmp5.human_ && _mochaLocalTmp5.human_.name_ && _mochaLocalTmp5.human_.name_.age_ && _mochaLocalTmp5.human_.name_.age_.hobby_ && _mochaLocalTmp5.human_.name_.age_.hobby_[2] )?_mochaLocalTmp5.human_.name_.age_.hobby_[2] : undefined;
                  __LINE__ = 0;
                  return Monster;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              })();
          
          __LINE__ = 59;
          var _mochaLocalTmp6 = {},
              time = ( _mochaLocalTmp6.name && _mochaLocalTmp6.name.age && _mochaLocalTmp6.name.age.time )?_mochaLocalTmp6.name.age.time : undefined;
          
          __LINE__ = 60;
          console.log( time );
          __LINE__ = 0;
          return _mochaLocalExport;
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      })();
    } catch( e ){
      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  })();
})();
