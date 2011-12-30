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
          
          __LINE__ = 0;
          _mochaLocalExport.createPrivateProp = function createPrivateProp( id,prop,value,isConst ) {
            try {
              __LINE__ = 277;
              if ( !( id in instance_prop ) ){
                __LINE__ = 278;
                instance_prop[id] = {};
              };
              
              __LINE__ = 280;
              Object.defineProperty( instance_prop[id],prop, {
                enumerable : true,
                configurable : isConst,
                writable : isConst,
                value : value
              });
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          _mochaLocalExport.getPrivateProp = function getPrivateProp( id,prop ) {
            try {
              __LINE__ = 289;
              if ( id in _mochaInstanceProp ){
                __LINE__ = 290;
                return _mochaInstanceProp[id];
              } else {
                try {
                  __LINE__ = 293;
                  throw new TypeError( prop+"is not defined." );
                } catch( e ){
                  __LINE__ = 295;
                  throw new Error( e );
                };
              };
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 300;
          var createUnenumProp = _mochaLocalExport.createUnenumProp = function ( obj,prop,value ) {
                try {
                  __LINE__ = 300;
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
          
          __LINE__ = 307;
          var constant = _mochaLocalExport.constant = function ( obj,prop,value ) {
                try {
                  __LINE__ = 307;
                  return Object.defineProp( obj,prop, {
                    configurable : false,
                    enumerable : false,
                    writable : false,
                    value : value
                  });
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
          
          __LINE__ = 314;
          var toArray = _mochaLocalExport.toArray = function ( likeArray ) {
                try {
                  __LINE__ = 314;
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
      var __FILE__ = "/var/samba/mocha/test/mains/test.js";
      __LINE__ = 2;
      _mochaGlobalExport['{1-302-567-849-60818395-1384-test.js}'] = {};
      
      __LINE__ = 3;
      var _mochaGlobalAlias = _mochaGlobalExport['{1-302-567-849-60818395-1384-test.js}'];
      
      __LINE__ = 0;
      ( function () {
        try {
          __LINE__ = 2;
          var m = function ( x,y ) {
                try {
                  __LINE__ = 0;
                  var x = Runtime.toArray( arguments,2 );
                  
                  __LINE__ = 0;
                  var _yieldState = 0;
                  
                  __LINE__ = 0;
                  var _yieldResult = undefined;
                  
                  __LINE__ = 0;
                  var i;
                  
                  __LINE__ = 6;
                  var _mochaLocalTmp0,
                      x;
                  
                  __LINE__ = 7;
                  var m;
                  
                  __LINE__ = 0;
                  var _mochaGenerator = function ( _isYieldSend ) {
                        try {
                          __LINE__ = 2;
                          while ( 1 ){
                            __LINE__ = 2;
                            switch ( _yieldState ) {
                              case 0 :
                                __LINE__ = 2;
                                
                                __LINE__ = 0;
                                _yieldState = 1;
                                
                                __LINE__ = 0;
                                i = 0;
                                
                                __LINE__ = 0;
                                _yieldResult = ( _isYieldSend && arguments.length>1 )?Runtime.toArray( arguments,1 ) : ( _isYieldSend )?x : undefined;
                                __LINE__ = 0;
                                return x;
                              case 1 :
                                __LINE__ = 2;
                                
                                __LINE__ = 4;
                                fx( _yieldResult );
                                
                                __LINE__ = 0;
                                i ++ ;
                                
                                __LINE__ = 2;
                                if ( i<20 ){
                                  __LINE__ = 0;
                                  _yieldState = 0;
                                  __LINE__ = 0;
                                  break;
                                } else {
                                  __LINE__ = 0;
                                  _yieldState = 2;
                                };
                                
                                __LINE__ = 0;
                                _yieldResult = ( _isYieldSend && arguments.length>1 )?Runtime.toArray( arguments,1 ) : ( _isYieldSend )?x+y : undefined;
                              case 1 :
                                __LINE__ = 2;
                                
                                __LINE__ = 0;
                                _yieldState = -1;
                                
                                __LINE__ = 0;
                                _mochaLocalTmp0 = _yieldResult;
                                
                                __LINE__ = 0;
                                x = _mochaLocalTmp0.x;
                                
                                __LINE__ = 0;
                                m = 200;
                                
                                __LINE__ = 8;
                                if ( x>200 ){
                                  __LINE__ = 0;
                                  return x+y+m*200;
                                };
                              case -1 :
                                __LINE__ = 2;
                                
                                __LINE__ = 0;
                                Runtime.exceptionHandler(  );
                                
                            };
                          };
                        } catch( e ){
                          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      };
                  __LINE__ = 0;
                  return  {
                    next : _mochaGenerator.bind( this,true ),
                    send : _mochaGenerator.bind( this,false )
                  };
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      })();
      
      __LINE__ = 13;
      var x =  {
            x : 200,
            y : 300
          };
      
      __LINE__ = 15;
      ( function () {
        try {
          __LINE__ = 15;
          var _mochaLocalExport = _mochaGlobalAlias;
          
          __LINE__ = 16;
          var x = _mochaLocalExport.x = 0;
          
          __LINE__ = 17;
          var Monster = _mochaLocalExport.Monster = ( function () {
                try {
                  __LINE__ = 0;
                  var _mochaPrivateHolder = function (){};
                  
                  __LINE__ = 17;
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
                  
                  __LINE__ = 17;
                  Runtime.extendClass( Monster,test["200"] );
                  
                  __LINE__ = 23;
                  Runtime.createUnenumProp( Monster,'constructor',
                  function constructor( name,health ) {
                    try {
                      
                      __LINE__ = 24;
                      this.name = name;
                      
                      __LINE__ = 25;
                      var _mochaLocalTmp2 =  {
                            x : 200
                          };
                      
                      __LINE__ = 25;
                      Runtime.constant( this.__private__,'name',( _mochaLocalTmp2.x && _mochaLocalTmp2.x[0] )?_mochaLocalTmp2.x[0] : undefined );
                      
                      __LINE__ = 25;
                      Runtime.constant( this.__private__,'age',( _mochaLocalTmp2.x && _mochaLocalTmp2.x[1] )?_mochaLocalTmp2.x[1] : undefined );
                      
                      __LINE__ = 25;
                      Runtime.constant( this.__private__,'hobby',( _mochaLocalTmp2.x && _mochaLocalTmp2.x[2] && _mochaLocalTmp2.x[2].hobby )?_mochaLocalTmp2.x[2].hobby : undefined );
                      
                      __LINE__ = 26;
                      Runtime.constant( this.__private__,'_tmpName',name );
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  });
                  
                  __LINE__ = 60;
                  Monster.prototype.numAttacks = 0;
                  
                  __LINE__ = 67;
                  Runtime.constant( Monster.prototype,'attackMessage','The monster hits you!' );
                  
                  __LINE__ = 39;
                  _mochaPrivateHolder.prototype.isAlive = function isAlive() {
                    try {
                      __LINE__ = 40;
                      return this._health>0;
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  };
                  
                  __LINE__ = 44;
                  _mochaPrivateHolder.prototype.health = function health( value ) {
                    try {
                      __LINE__ = 0;
                      if ( value<0 ){
                        __LINE__ = 0;
                        throw new Error( 'Health must be non-negative.' );
                      };
                      
                      __LINE__ = 48;
                      this._health = value;
                      __LINE__ = 49;
                      return this.value+"tmpName";
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  };
                  
                  __LINE__ = 51;
                  _mochaPrivateHolder.prototype.x = ( function () {
                    try {
                      __LINE__ = 0;
                      var _mochaPrivateHolder = function (){};
                      
                      __LINE__ = 51;
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
                      
                      __LINE__ = 52;
                      _mochaPrivateHolder.prototype.constructor = function constructor() {
                        try {
                          __LINE__ = 53;
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
                  
                  __LINE__ = 32;
                  _mochaPrivateHolder.prototype.attack = function attack( target ) {
                    try {
                      __LINE__ = 33;
                      log( 'The monster attacks '+target );
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  };
                  
                  __LINE__ = 61;
                  Runtime.constant( Monster,'constant',200 );
                  
                  __LINE__ = 62;
                  var _mochaLocalTmp4 = human;
                  
                  __LINE__ = 62;
                  Monster.h1 = ( _mochaLocalTmp4.human && _mochaLocalTmp4.human.name && _mochaLocalTmp4.human.name.age && _mochaLocalTmp4.human.name.age.hobby && _mochaLocalTmp4.human.name.age.hobby[0] )?_mochaLocalTmp4.human.name.age.hobby[0] : undefined;
                  
                  __LINE__ = 62;
                  Monster.h2 = ( _mochaLocalTmp4.human && _mochaLocalTmp4.human.name && _mochaLocalTmp4.human.name.age && _mochaLocalTmp4.human.name.age.hobby && _mochaLocalTmp4.human.name.age.hobby[1] )?_mochaLocalTmp4.human.name.age.hobby[1] : undefined;
                  
                  __LINE__ = 62;
                  Monster.h3 = ( _mochaLocalTmp4.human && _mochaLocalTmp4.human.name && _mochaLocalTmp4.human.name.age && _mochaLocalTmp4.human.name.age.hobby && _mochaLocalTmp4.human.name.age.hobby[2] )?_mochaLocalTmp4.human.name.age.hobby[2] : undefined;
                  
                  __LINE__ = 63;
                  var _mochaLocalTmp5 = human_;
                  
                  __LINE__ = 63;
                  Monster.h1_ = ( _mochaLocalTmp5.human_ && _mochaLocalTmp5.human_.name_ && _mochaLocalTmp5.human_.name_.age_ && _mochaLocalTmp5.human_.name_.age_.hobby_ && _mochaLocalTmp5.human_.name_.age_.hobby_[0] )?_mochaLocalTmp5.human_.name_.age_.hobby_[0] : undefined;
                  
                  __LINE__ = 63;
                  Monster.h2_ = ( _mochaLocalTmp5.human_ && _mochaLocalTmp5.human_.name_ && _mochaLocalTmp5.human_.name_.age_ && _mochaLocalTmp5.human_.name_.age_.hobby_ && _mochaLocalTmp5.human_.name_.age_.hobby_[1] )?_mochaLocalTmp5.human_.name_.age_.hobby_[1] : undefined;
                  
                  __LINE__ = 63;
                  Monster.h3_ = ( _mochaLocalTmp5.human_ && _mochaLocalTmp5.human_.name_ && _mochaLocalTmp5.human_.name_.age_ && _mochaLocalTmp5.human_.name_.age_.hobby_ && _mochaLocalTmp5.human_.name_.age_.hobby_[2] )?_mochaLocalTmp5.human_.name_.age_.hobby_[2] : undefined;
                  __LINE__ = 0;
                  return Monster;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              })();
          
          __LINE__ = 70;
          var _mochaLocalTmp6 = {},
              time = ( _mochaLocalTmp6.name && _mochaLocalTmp6.name.age && _mochaLocalTmp6.name.age.time )?_mochaLocalTmp6.name.age.time : undefined;
          
          __LINE__ = 71;
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
