(function() {
  var __FILE__ = "Runtime",
      __LINE__ = 0;
  
  __LINE__ = 0;
  this.x = 0;
  
  __LINE__ = 1;
  var f = {},
      w = {};
  
  __LINE__ = 4;
  var h = ( function h() {
        try {
          __LINE__ = 4;
          var m = {};
          
          __LINE__ = 6;
          if ( !String.prototype.trim ){
            __LINE__ = 7;
            String.prototype.trim = function () {
              try {
                __LINE__ = 7;
                return this.replace( String.prototype.trim.rtrim,"" );
              } catch( e ){
                h.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
            
            __LINE__ = 8;
            String.prototype.trim.rtrim = /^\s*|\s*$/g;
          };
          
          __LINE__ = 11;
          if ( !Function.prototype.bind ){
            __LINE__ = 12;
            Function.prototype.bind = function () {
              try {
                __LINE__ = 13;
                var a = Array.prototype.slice.call( arguments ),
                    e = a.shift(),
                    d = function () {
                      try {
                        __LINE__ = 16;
                        var f = a.concat( Array.prototype.slice.call( arguments ) );
                        
                        __LINE__ = 17;
                        if ( this instanceof d ){
                          __LINE__ = 18;
                          return d.context.apply( this,f );
                        } else {
                          __LINE__ = 20;
                          return d.context.apply( e,f );
                        };
                      } catch( e ){
                        h.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    };
                
                __LINE__ = 23;
                d.prototype = this.prototype;
                
                __LINE__ = 24;
                d.context = this;
                __LINE__ = 25;
                return d;
              } catch( e ){
                h.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          };
          
          __LINE__ = 29;
          if ( !Array.prototype.forEach ){
            __LINE__ = 30;
            Array.prototype.forEach = function ( b,c ) {
              try {
                __LINE__ = 31;
                var d = -1,
                    e;
                
                __LINE__ = 33;
                if ( c ){
                  __LINE__ = 34;
                  while ( ( e = this[ ++ d] ) !== null && e !== undefined ){
                    __LINE__ = 35;
                    b.call( c,e,d,this );
                  };
                } else {
                  __LINE__ = 38;
                  while ( ( e = this[ ++ d] ) !== null && e !== undefined ){
                    __LINE__ = 39;
                    b( e,d,this );
                  };
                };
              } catch( e ){
                h.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          };
          
          __LINE__ = 45;
          if ( !Array.prototype.every ){
            __LINE__ = 46;
            Array.prototype.every = function ( b,c ) {
              try {
                __LINE__ = 47;
                var d = -1,
                    e;
                
                __LINE__ = 49;
                if ( c ){
                  __LINE__ = 50;
                  while ( ( e = this[ ++ d] ) !== null && e !== undefined ){
                    __LINE__ = 51;
                    if ( !( b.call( c,e,d,this ) ) ){
                      __LINE__ = 52;
                      return false;
                    };
                  };
                } else {
                  __LINE__ = 56;
                  while ( ( e = this[ ++ d] ) !== null && e !== undefined ){
                    if ( !( b( e,d,this ) ) ){
                      __LINE__ = 58;
                      return false;
                    };
                  };
                };
                __LINE__ = 62;
                return true;
              } catch( e ){
                h.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          };
          
          __LINE__ = 66;
          if ( !Array.prototype.some ){
            __LINE__ = 67;
            Array.prototype.some = function ( b,c ) {
              try {
                __LINE__ = 68;
                var d = -1,
                    e;
                
                __LINE__ = 70;
                if ( c ){
                  __LINE__ = 71;
                  while ( ( e = this[ ++ d] ) !== null && e !== undefined ){
                    __LINE__ = 72;
                    if ( b.call( c,e,d,this ) ){
                      __LINE__ = 73;
                      return true;
                    };
                  };
                } else {
                  __LINE__ = 77;
                  while ( ( e = this[ ++ d] ) !== null && e !== undefined ){
                    if ( b( e,d,this ) ){
                      __LINE__ = 79;
                      return true;
                    };
                  };
                };
                __LINE__ = 83;
                return false;
              } catch( e ){
                h.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          };
          
          __LINE__ = 87;
          if ( !Array.prototype.filter ){
            __LINE__ = 88;
            Array.prototype.filter = function ( c,d ) {
              try {
                __LINE__ = 89;
                var e = -1,
                    f = [],
                    g;
                
                __LINE__ = 92;
                if ( d ){
                  __LINE__ = 93;
                  for ( var i = 0,len = this.length;i<len; ++ i ){
                    __LINE__ = 94;
                    if ( ( g = this[i] ) !== null && g !== undefined ){
                      __LINE__ = 95;
                      if ( c.call( d,g,i,this ) ){
                        __LINE__ = 96;
                        f[ ++ e] = g;
                      };
                    };
                  };
                } else {
                  __LINE__ = 101;
                  for ( var i = 0,len = this.length;i<len; ++ i ){
                    if ( ( g = this[i] ) !== null && g !== undefined ){
                      if ( c( g,i,this ) ){
                        __LINE__ = 104;
                        f[ ++ e] = g;
                      };
                    };
                  };
                };
                __LINE__ = 109;
                return f;
              } catch( e ){
                h.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          };
          
          __LINE__ = 113;
          if ( !Array.prototype.indexOf ){
            __LINE__ = 114;
            Array.prototype.indexOf = function ( b ) {
              try {
                __LINE__ = 115;
                var c = -1,
                    d = -1,
                    e;
                
                __LINE__ = 118;
                while ( ( e = this[ ++ c] ) !== null && e !== undefined ){
                  __LINE__ = 119;
                  if ( e === b ){
                    __LINE__ = 120;
                    d = c;
                    __LINE__ = 121;
                    break;
                  };
                };
                __LINE__ = 124;
                return d;
              } catch( e ){
                h.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          };
          
          __LINE__ = 128;
          if ( !Array.prototype.lastIndexOf ){
            __LINE__ = 129;
            Array.prototype.lastIndexOf = function ( b ) {
              try {
                __LINE__ = 130;
                var c = this.length,
                    d = -1,
                    e;
                
                __LINE__ = 133;
                while ( ( e = this[ -- c] ) !== null && e !== undefined ){
                  __LINE__ = 134;
                  if ( e === b ){
                    __LINE__ = 135;
                    d = c;
                    __LINE__ = 136;
                    break;
                  };
                };
                __LINE__ = 139;
                return d;
              } catch( e ){
                h.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          };
          
          __LINE__ = 143;
          if ( !Array.prototype.map ){
            __LINE__ = 144;
            Array.prototype.map = function ( c,d ) {
              try {
                __LINE__ = 145;
                var e = [],
                    f = -1,
                    g;
                
                __LINE__ = 148;
                if ( d ){
                  __LINE__ = 149;
                  for ( var i = 0,len = this.length;i<len; ++ i ){
                    __LINE__ = 150;
                    if ( ( g = this[i] ) !== null && g !== undefined ){
                      __LINE__ = 151;
                      e[ ++ f] = c.call( d,g,i,this );
                    };
                  };
                } else {
                  __LINE__ = 155;
                  for ( var i = 0,len = this.length;i<len; ++ i ){
                    if ( ( g = this[i] ) !== null && g !== undefined ){
                      __LINE__ = 157;
                      e[ ++ f] = c( g,i,this );
                    };
                  };
                };
                __LINE__ = 161;
                return e;
              } catch( e ){
                h.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          };
          
          __LINE__ = 165;
          if ( !Array.prototype.reduce ){
            __LINE__ = 166;
            Array.prototype.reduce = function ( b,c ) {
              try {
                __LINE__ = 167;
                var d = c || this[0],
                    e = ( ( c ) )?0 : 1,
                    f,
                    g;
                
                __LINE__ = 171;
                for ( e , g = this.length;e<g; ++ e ){
                  __LINE__ = 172;
                  if ( ( f = this[e] ) !== null && f !== undefined ){
                    __LINE__ = 173;
                    d = b( d,f,e,this );
                  };
                };
                __LINE__ = 176;
                return d;
              } catch( e ){
                h.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          };
          
          __LINE__ = 180;
          if ( !Array.prototype.reduceRight ){
            __LINE__ = 181;
            Array.prototype.reduceRight = function ( b,c ) {
              try {
                __LINE__ = 182;
                var d = c || this[this.length-1],
                    e = ( ( c ) )?this.length-1 : this.length-2,
                    f;
                
                __LINE__ = 185;
                for ( e;e>-1; -- e ){
                  __LINE__ = 186;
                  if ( ( f = this[e] ) !== null && f !== undefined ){
                    __LINE__ = 187;
                    d = b( d,f,e,this );
                  };
                };
                __LINE__ = 190;
                return d;
              } catch( e ){
                h.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          };
          
          __LINE__ = 194;
          if ( !Date.prototype.toJSON ){
            __LINE__ = 195;
            Date.prototype.toJSON = function () {
              try {
                __LINE__ = 202;
                return '"'+this.getUTCFullYear()+'-'+"0"+( this.getUTCMonth()+1 )+'-'+"0"+( this.getUTCDate()-1 )+'T'+this.getUTCHours()+':'+this.getMinutes()+':'+this.getSeconds()+'.'+this.getUTCMilliseconds()+'"';
              } catch( e ){
                h.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          };
          
          __LINE__ = 205;
          if ( !Date.now ){
            __LINE__ = 206;
            Date.now = function () {
              try {
                __LINE__ = 206;
                return +(new Date);
              } catch( e ){
                h.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          };
          
          __LINE__ = 209;
          if ( !Object.keys ){
            __LINE__ = 210;
            Object.keys = function ( b ) {
              try {
                __LINE__ = 211;
                var c = [],
                    d = -1;
                
                __LINE__ = 214;
                for ( var i in b ){
                  __LINE__ = 215;
                  if ( b.hasOwnProperty( i ) ){
                    __LINE__ = 216;
                    c[ ++ d] = b[i];
                  };
                };
                __LINE__ = 220;
                return c;
              } catch( e ){
                h.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          };
          
          __LINE__ = 225;
          if ( !Object.preventExtensions ){
            __LINE__ = 226;
            Object.preventExtensions = function ( a ) {
              try {
                __LINE__ = 226;
                return a;
              } catch( e ){
                h.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          };
          
          __LINE__ = 229;
          if ( !Object.seal ){
            __LINE__ = 230;
            Object.seal = function ( a ) {
              try {
                __LINE__ = 230;
                return a;
              } catch( e ){
                h.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          };
          
          __LINE__ = 233;
          if ( !Object.freeze ){
            __LINE__ = 234;
            Object.freeze = function ( a ) {
              try {
                __LINE__ = 234;
                return a;
              } catch( e ){
                h.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          };
          
          __LINE__ = 237;
          var n = ( function () {
                try {
                  try {
                    __LINE__ = 239;
                    var c = {};
                    
                    __LINE__ = 240;
                    Object.defineProperty( c,"test", {
                      configurable : false,
                      writable : false,
                      enumerable : false,
                      value : 0
                    });
                    
                    __LINE__ = 246;
                    c.test = 200;
                    __LINE__ = 247;
                    return ( ( c.test === 200 ) )?false : true;
                  } catch( e ){
                    __LINE__ = 249;
                    return false;
                  };
                } catch( e ){
                  h.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              })();
          
          __LINE__ = 253;
          if ( !n ){
            __LINE__ = 254;
            Object.defineProperty = function ( a,b,c ) {
              try {
                __LINE__ = 255;
                if ( c.value ){
                  __LINE__ = 256;
                  a[b] = c.value;
                };
              } catch( e ){
                h.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          };
          
          __LINE__ = 261;
          if ( !Array.isArray ){
            __LINE__ = 262;
            var c = "[object Array]";
            
            __LINE__ = 263;
            Array.isArray = function ( d ) {
              try {
                __LINE__ = 264;
                if ( arguments.length === 0 ){
                  __LINE__ = 265;
                  return false;
                };
                __LINE__ = 267;
                return ( ( d ) )?Object.prototype.toString.call( d ) === c : false;
              } catch( e ){
                h.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          };
          
          __LINE__ = 271;
          var a = Array.prototype.slice;
          
          __LINE__ = 273;
          var a = m.createUnenumProp = function ( b,c,d ) {
                try {
                  __LINE__ = 273;
                  return Object.defineProperty( b,c, {
                    configurable : true,
                    enumerable : false,
                    writable : true,
                    value : d
                  });
                } catch( e ){
                  h.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
          
          __LINE__ = 280;
          var o = m.constant = function ( b,c,d ) {
                try {
                  __LINE__ = 280;
                  return Object.defineProperty( b,c, {
                    configurable : false,
                    enumerable : false,
                    writable : false,
                    value : d
                  });
                } catch( e ){
                  h.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
          
          __LINE__ = 287;
          var p = m.toArray = function ( b,c ) {
                try {
                  __LINE__ = 287;
                  return ( ( b ) )?a.call( b,c ) : [];
                } catch( e ){
                  h.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
          
          __LINE__ = 289;
          var c = m.Iterator = function ( h,i ) {
                try {
                  __LINE__ = 0;
                  i = i || false;
                  
                  __LINE__ = 290;
                  var j = {},
                      k,
                      a,
                      b = 0;
                  
                  __LINE__ = 294;
                  if ( this instanceof c ){
                    __LINE__ = 295;
                    k = Array.isArray( h );
                    
                    __LINE__ = 296;
                    a = e( h,k,i );
                  } else {
                    __LINE__ = 298;
                    return f( h,i );
                  };
                  
                  __LINE__ = 300;
                  a( j,"next",
                  function () {
                    try {
                      __LINE__ = 300;
                      return a[b ++ ];
                    } catch( e ){
                      h.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  });
                  __LINE__ = 301;
                  return j;
                } catch( e ){
                  h.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
          
          __LINE__ = 304;
          var a = function ( b,c ) {
                try {
                  __LINE__ = 305;
                  var d = [],
                      e = -1;
                  
                  __LINE__ = 307;
                  if ( c ){
                    __LINE__ = 308;
                    for ( var prop in b ){
                      __LINE__ = 309;
                      d[ ++ e] = prop;
                    };
                  } else {
                    __LINE__ = 312;
                    for ( var prop in b ){
                      __LINE__ = 313;
                      d[ ++ e] = [prop,b[prop]];
                    };
                  };
                  __LINE__ = 316;
                  return d;
                } catch( e ){
                  h.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              },
              b = function ( b,c ) {
                try {
                  __LINE__ = 320;
                  var d = [];
                  
                  __LINE__ = 321;
                  if ( c ){
                    __LINE__ = 322;
                    for ( var i = 0,len = b.length;i<len;i ++  ){
                      __LINE__ = 323;
                      d[i] = i;
                    };
                  } else {
                    __LINE__ = 326;
                    for ( var i = 0,len = b.length;i<len;i ++  ){
                      __LINE__ = 327;
                      d[i] = [i,b[i]];
                    };
                  };
                  __LINE__ = 330;
                  return d;
                } catch( e ){
                  h.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              },
              c = function ( b,c ) {
                try {
                  __LINE__ = 334;
                  var d = [];
                  
                  __LINE__ = 335;
                  if ( c ){
                    __LINE__ = 336;
                    for ( var i = 0,len = b.length;i<len;i ++  ){
                      __LINE__ = 337;
                      d[i] = i;
                    };
                  } else {
                    __LINE__ = 340;
                    for ( var i = 0,len = b.length;i<len;i ++  ){
                      __LINE__ = 341;
                      d[i] = [i,b.charAt( i )];
                    };
                  };
                  __LINE__ = 344;
                  return d;
                } catch( e ){
                  h.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              },
              e = function ( d,e,f ) {
                try {
                  __LINE__ = 348;
                  var g = typeof d;
                  
                  __LINE__ = 349;
                  if ( g === "object" && !e ){
                    __LINE__ = 350;
                    return a( d,f );
                  } else if ( e ){
                    __LINE__ = 352;
                    return b( d,f );
                  } else if ( g === "string" ){
                    __LINE__ = 354;
                    return c( d,f );
                  };
                } catch( e ){
                  h.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              },
              f = function ( d,e ) {
                try {
                  __LINE__ = 359;
                  if ( "__iterator__" in d ){
                    __LINE__ = 360;
                    return d.__iterator__( e );
                  } else {
                    __LINE__ = 362;
                    return  {
                      next : function () {
                        try {
                          try {
                            __LINE__ = 365;
                            throw new a;
                          } catch( e ){
                            __LINE__ = 367;
                            throw new Error( e );
                          };
                        } catch( e ){
                          h.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      }
                    };
                  };
                } catch( e ){
                  h.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
          
          __LINE__ = 374;
          var q = m.createGenerator = function ( c,d,e ) {
                try {
                  __LINE__ = 375;
                  var f = {};
                  
                  __LINE__ = 376;
                  a( f,"next",c.bind( e,false,false ) );
                  
                  __LINE__ = 377;
                  a( f,"send",c.bind( e,true,false ) );
                  
                  __LINE__ = 378;
                  a( f,"close",d.bind( e ) );
                  
                  __LINE__ = 379;
                  a( f,"__nothrowNext__",d.bind( e,false,true ) );
                  
                  __LINE__ = 380;
                  a( f,"toString",
                  function () {
                    try {
                      __LINE__ = 380;
                      return "[object Generator]";
                    } catch( e ){
                      h.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  });
                  
                  __LINE__ = 381;
                  Object.freeze( f );
                  __LINE__ = 382;
                  return f;
                } catch( e ){
                  h.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
          
          __LINE__ = 385;
          var a = function ( a ) {
                try {
                  __LINE__ = 385;
                  return ( ( a.message ) )?a.message : ( ( a.description ) )?a.description : a.toString();
                } catch( e ){
                  h.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
          
          __LINE__ = 387;
          var a = m.throwException = function ( d ) {
                try {
                  try {
                    __LINE__ = 389;
                    throw d;
                  } catch( e ){
                    __LINE__ = 391;
                    throw new Error( a( e ) );
                  };
                } catch( e ){
                  h.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
          
          __LINE__ = 395;
          function b( d,c,b ) {
            try {
              __LINE__ = 396;
              this.message = function () {
                try {
                  __LINE__ = 397;
                  return a( b )+" in file "+c+" at : "+d;
                } catch( e ){
                  h.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
            } catch( e ){
              h.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 401;
          var r = m.exceptionHandler = function ( c,d,e ) {
                try {
                  __LINE__ = 402;
                  a( new b( c , d , e ) );
                } catch( e ){
                  h.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
          __LINE__ = 0;
          return m;
        } catch( e ){
          h.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      })();
  
  __LINE__ = 406;
  var a =  {
        toString : function toString() {
          try {
            __LINE__ = 407;
            return "StopIteration";
          } catch( e ){
            h.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        }
      };
  
  __LINE__ = 0;
  ( function () {
    try {
      var __FILE__ = "/Users/aono_taketoshi/.mocha/module/runtime/iterators.js",
          __LINE__ = 0;
      __LINE__ = 2;
      f['{1-397-1092-26148-1746-829413-iterators.js}'] = {};
      
      __LINE__ = 3;
      var g = f['{1-397-1092-26148-1746-829413-iterators.js}'];
      
      __LINE__ = 0;
      ( function () {
        try {
          __LINE__ = 0;
          var k = g;
          
          __LINE__ = 1;
          var m = Function.prototype.call.bind( Function.prototype.call );
          
          __LINE__ = 2;
          var n = Object.prototype.hasOwnProperty;
          
          __LINE__ = 3;
          var a = k.iterator = "__iterator__";
          
          __LINE__ = 0;
          k.keys = function l( o ) {
            try {
              __LINE__ = 0;
              var g =  {
                    
                  };
              
              __LINE__ = 0;
              g[a] = function () {
                try {
                  __LINE__ = 7;
                  return ( function () {
                    try {
                      __LINE__ = 0;
                      var a = true;
                      
                      __LINE__ = 0;
                      var w = undefined;
                      
                      __LINE__ = 0;
                      var a = 0;
                      
                      __LINE__ = 0;
                      var k;
                      
                      __LINE__ = 0;
                      var j;
                      
                      __LINE__ = 0;
                      var l;
                      
                      __LINE__ = 0;
                      var h = [];
                      
                      __LINE__ = 0;
                      var x = function ( q,r ) {
                            try {
                              __LINE__ = 0;
                              if ( !q ){
                                __LINE__ = 0;
                                a = false;
                              } else if ( q && a && arguments[1] !== undefined ){
                                __LINE__ = 0;
                                h.exceptionHandler( 'attempt to send to newborn generator.' );
                              };
                              
                              __LINE__ = 0;
                              while ( 1 ){
                                __LINE__ = 0;
                                switch ( a ) {
                                  case 0 :
                                    
                                    __LINE__ = 0;
                                    for ( var _mochaLocalTmp0 in o ){
                                      
                                      __LINE__ = 7;
                                      h.push( _mochaLocalTmp0 );
                                    };
                                    
                                    __LINE__ = 8;
                                    j = 0;
                                    
                                    __LINE__ = 8;
                                    k = h.length;
                                    
                                    __LINE__ = 0;
                                    if ( !( j<k ) ){
                                      __LINE__ = 7;
                                      a = -1;
                                      __LINE__ = 7;
                                      break;
                                    };
                                  case 1 :
                                    
                                    __LINE__ = 0;
                                    l = h[j];
                                    
                                    __LINE__ = 0;
                                    if ( m( n,o,l ) ){
                                      __LINE__ = 7;
                                      a = 2;
                                      __LINE__ = 0;
                                      break;
                                    } else {
                                      __LINE__ = 7;
                                      a = 3;
                                      __LINE__ = 0;
                                      break;
                                    };
                                  case 2 :
                                    
                                    __LINE__ = 10;
                                    a = 3;
                                    __LINE__ = 10;
                                    return l;
                                  case 3 :
                                    
                                    __LINE__ = 0;
                                    a = 4;
                                    __LINE__ = 0;
                                    break;
                                  case 4 :
                                    
                                    __LINE__ = 0;
                                     ++ j;
                                    
                                    __LINE__ = 0;
                                    if ( j<k ){
                                      __LINE__ = 7;
                                      a = 1;
                                      __LINE__ = 0;
                                      break;
                                    } else {
                                      __LINE__ = 7;
                                      a = -1;
                                    };
                                  case -1 :
                                    
                                    __LINE__ = 0;
                                    if ( r ){
                                      __LINE__ = 0;
                                      return undefined;
                                    } else {
                                      __LINE__ = 7;
                                      h.throwException( h.StopIteration );
                                    };
                                    
                                };
                              };
                            } catch( e ){
                              h.exceptionHandler( __LINE__ , __FILE__ , e );
                            }
                          };
                      __LINE__ = 0;
                      return h.createGenerator( x,
                      function (  ) {
                        try {
                          __LINE__ = 0;
                          a = -1;
                        } catch( e ){
                          h.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      },this);
                    } catch( e ){
                      h.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  })();
                } catch( e ){
                  h.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              __LINE__ = 5;
              return g;
            } catch( e ){
              h.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          k.values = function w( o ) {
            try {
              __LINE__ = 0;
              var g =  {
                    
                  };
              
              __LINE__ = 0;
              g[a] = function () {
                try {
                  __LINE__ = 19;
                  return ( function () {
                    try {
                      __LINE__ = 0;
                      var a = true;
                      
                      __LINE__ = 0;
                      var w = undefined;
                      
                      __LINE__ = 0;
                      var a = 0;
                      
                      __LINE__ = 0;
                      var k;
                      
                      __LINE__ = 0;
                      var j;
                      
                      __LINE__ = 0;
                      var l;
                      
                      __LINE__ = 0;
                      var h = [];
                      
                      __LINE__ = 0;
                      var x = function ( q,r ) {
                            try {
                              __LINE__ = 0;
                              if ( !q ){
                                __LINE__ = 0;
                                a = false;
                              } else if ( q && a && arguments[1] !== undefined ){
                                __LINE__ = 0;
                                h.exceptionHandler( 'attempt to send to newborn generator.' );
                              };
                              
                              __LINE__ = 0;
                              while ( 1 ){
                                __LINE__ = 0;
                                switch ( a ) {
                                  case 0 :
                                    
                                    __LINE__ = 0;
                                    for ( var _mochaLocalTmp4 in o ){
                                      
                                      __LINE__ = 19;
                                      h.push( _mochaLocalTmp4 );
                                    };
                                    
                                    __LINE__ = 20;
                                    j = 0;
                                    
                                    __LINE__ = 20;
                                    k = h.length;
                                    
                                    __LINE__ = 0;
                                    if ( !( j<k ) ){
                                      __LINE__ = 19;
                                      a = -1;
                                      __LINE__ = 19;
                                      break;
                                    };
                                  case 1 :
                                    
                                    __LINE__ = 0;
                                    l = h[j];
                                    
                                    __LINE__ = 0;
                                    if ( m( n,o,l ) ){
                                      __LINE__ = 19;
                                      a = 2;
                                      __LINE__ = 0;
                                      break;
                                    } else {
                                      __LINE__ = 19;
                                      a = 3;
                                      __LINE__ = 0;
                                      break;
                                    };
                                  case 2 :
                                    
                                    __LINE__ = 22;
                                    a = 3;
                                    __LINE__ = 22;
                                    return o[l];
                                  case 3 :
                                    
                                    __LINE__ = 0;
                                    a = 4;
                                    __LINE__ = 0;
                                    break;
                                  case 4 :
                                    
                                    __LINE__ = 0;
                                     ++ j;
                                    
                                    __LINE__ = 0;
                                    if ( j<k ){
                                      __LINE__ = 19;
                                      a = 1;
                                      __LINE__ = 0;
                                      break;
                                    } else {
                                      __LINE__ = 19;
                                      a = -1;
                                    };
                                  case -1 :
                                    
                                    __LINE__ = 0;
                                    if ( r ){
                                      __LINE__ = 0;
                                      return undefined;
                                    } else {
                                      __LINE__ = 19;
                                      h.throwException( h.StopIteration );
                                    };
                                    
                                };
                              };
                            } catch( e ){
                              h.exceptionHandler( __LINE__ , __FILE__ , e );
                            }
                          };
                      __LINE__ = 0;
                      return h.createGenerator( x,
                      function (  ) {
                        try {
                          __LINE__ = 0;
                          a = -1;
                        } catch( e ){
                          h.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      },this);
                    } catch( e ){
                      h.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  })();
                } catch( e ){
                  h.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              __LINE__ = 17;
              return g;
            } catch( e ){
              h.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          k.items = function x( o ) {
            try {
              __LINE__ = 0;
              var g =  {
                    
                  };
              
              __LINE__ = 0;
              g[a] = function () {
                try {
                  __LINE__ = 31;
                  return ( function () {
                    try {
                      __LINE__ = 0;
                      var a = true;
                      
                      __LINE__ = 0;
                      var w = undefined;
                      
                      __LINE__ = 0;
                      var a = 0;
                      
                      __LINE__ = 0;
                      var k;
                      
                      __LINE__ = 0;
                      var j;
                      
                      __LINE__ = 0;
                      var l;
                      
                      __LINE__ = 0;
                      var h = [];
                      
                      __LINE__ = 0;
                      var x = function ( q,r ) {
                            try {
                              __LINE__ = 0;
                              if ( !q ){
                                __LINE__ = 0;
                                a = false;
                              } else if ( q && a && arguments[1] !== undefined ){
                                __LINE__ = 0;
                                h.exceptionHandler( 'attempt to send to newborn generator.' );
                              };
                              
                              __LINE__ = 0;
                              while ( 1 ){
                                __LINE__ = 0;
                                switch ( a ) {
                                  case 0 :
                                    
                                    __LINE__ = 0;
                                    for ( var _mochaLocalTmp8 in o ){
                                      
                                      __LINE__ = 31;
                                      h.push( _mochaLocalTmp8 );
                                    };
                                    
                                    __LINE__ = 32;
                                    j = 0;
                                    
                                    __LINE__ = 32;
                                    k = h.length;
                                    
                                    __LINE__ = 0;
                                    if ( !( j<k ) ){
                                      __LINE__ = 31;
                                      a = -1;
                                      __LINE__ = 31;
                                      break;
                                    };
                                  case 1 :
                                    
                                    __LINE__ = 0;
                                    l = h[j];
                                    
                                    __LINE__ = 0;
                                    if ( m( n,o,l ) ){
                                      __LINE__ = 31;
                                      a = 2;
                                      __LINE__ = 0;
                                      break;
                                    } else {
                                      __LINE__ = 31;
                                      a = 3;
                                      __LINE__ = 0;
                                      break;
                                    };
                                  case 2 :
                                    
                                    __LINE__ = 34;
                                    a = 3;
                                    __LINE__ = 34;
                                    return [l,o[l]];
                                  case 3 :
                                    
                                    __LINE__ = 0;
                                    a = 4;
                                    __LINE__ = 0;
                                    break;
                                  case 4 :
                                    
                                    __LINE__ = 0;
                                     ++ j;
                                    
                                    __LINE__ = 0;
                                    if ( j<k ){
                                      __LINE__ = 31;
                                      a = 1;
                                      __LINE__ = 0;
                                      break;
                                    } else {
                                      __LINE__ = 31;
                                      a = -1;
                                    };
                                  case -1 :
                                    
                                    __LINE__ = 0;
                                    if ( r ){
                                      __LINE__ = 0;
                                      return undefined;
                                    } else {
                                      __LINE__ = 31;
                                      h.throwException( h.StopIteration );
                                    };
                                    
                                };
                              };
                            } catch( e ){
                              h.exceptionHandler( __LINE__ , __FILE__ , e );
                            }
                          };
                      __LINE__ = 0;
                      return h.createGenerator( x,
                      function (  ) {
                        try {
                          __LINE__ = 0;
                          a = -1;
                        } catch( e ){
                          h.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      },this);
                    } catch( e ){
                      h.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  })();
                } catch( e ){
                  h.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              __LINE__ = 29;
              return g;
            } catch( e ){
              h.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          k.allKeys = function y( g ) {
            try {
              __LINE__ = 0;
              var h =  {
                    
                  };
              
              __LINE__ = 0;
              h[a] = function () {
                try {
                  __LINE__ = 43;
                  return ( function () {
                    try {
                      __LINE__ = 0;
                      var a = true;
                      
                      __LINE__ = 0;
                      var t = undefined;
                      
                      __LINE__ = 0;
                      var a = 0;
                      
                      __LINE__ = 0;
                      var k;
                      
                      __LINE__ = 0;
                      var j;
                      
                      __LINE__ = 0;
                      var l;
                      
                      __LINE__ = 0;
                      var h = [];
                      
                      __LINE__ = 0;
                      var u = function ( n,o ) {
                            try {
                              __LINE__ = 0;
                              if ( !n ){
                                __LINE__ = 0;
                                a = false;
                              } else if ( n && a && arguments[1] !== undefined ){
                                __LINE__ = 0;
                                h.exceptionHandler( 'attempt to send to newborn generator.' );
                              };
                              
                              __LINE__ = 0;
                              while ( 1 ){
                                __LINE__ = 0;
                                switch ( a ) {
                                  case 0 :
                                    
                                    __LINE__ = 0;
                                    for ( var _mochaLocalTmp12 in g ){
                                      
                                      __LINE__ = 43;
                                      h.push( _mochaLocalTmp12 );
                                    };
                                    
                                    __LINE__ = 44;
                                    j = 0;
                                    
                                    __LINE__ = 44;
                                    k = h.length;
                                    
                                    __LINE__ = 0;
                                    if ( !( j<k ) ){
                                      __LINE__ = 43;
                                      a = -1;
                                      __LINE__ = 43;
                                      break;
                                    };
                                  case 1 :
                                    
                                    __LINE__ = 45;
                                    a = 2;
                                    
                                    __LINE__ = 0;
                                    l = h[j];
                                    __LINE__ = 45;
                                    return l;
                                  case 2 :
                                    
                                    __LINE__ = 0;
                                     ++ j;
                                    
                                    __LINE__ = 0;
                                    if ( j<k ){
                                      __LINE__ = 43;
                                      a = 1;
                                      __LINE__ = 0;
                                      break;
                                    } else {
                                      __LINE__ = 43;
                                      a = -1;
                                    };
                                  case -1 :
                                    
                                    __LINE__ = 0;
                                    if ( o ){
                                      __LINE__ = 0;
                                      return undefined;
                                    } else {
                                      __LINE__ = 43;
                                      h.throwException( h.StopIteration );
                                    };
                                    
                                };
                              };
                            } catch( e ){
                              h.exceptionHandler( __LINE__ , __FILE__ , e );
                            }
                          };
                      __LINE__ = 0;
                      return h.createGenerator( u,
                      function (  ) {
                        try {
                          __LINE__ = 0;
                          a = -1;
                        } catch( e ){
                          h.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      },this);
                    } catch( e ){
                      h.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  })();
                } catch( e ){
                  h.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              __LINE__ = 41;
              return h;
            } catch( e ){
              h.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          k.allValues = function z( m ) {
            try {
              __LINE__ = 0;
              var g =  {
                    
                  };
              
              __LINE__ = 0;
              g[a] = function () {
                try {
                  __LINE__ = 53;
                  return ( function () {
                    try {
                      __LINE__ = 0;
                      var a = true;
                      
                      __LINE__ = 0;
                      var u = undefined;
                      
                      __LINE__ = 0;
                      var a = 0;
                      
                      __LINE__ = 0;
                      var k;
                      
                      __LINE__ = 0;
                      var j;
                      
                      __LINE__ = 0;
                      var l;
                      
                      __LINE__ = 0;
                      var h = [];
                      
                      __LINE__ = 0;
                      var v = function ( o,p ) {
                            try {
                              __LINE__ = 0;
                              if ( !o ){
                                __LINE__ = 0;
                                a = false;
                              } else if ( o && a && arguments[1] !== undefined ){
                                __LINE__ = 0;
                                h.exceptionHandler( 'attempt to send to newborn generator.' );
                              };
                              
                              __LINE__ = 0;
                              while ( 1 ){
                                __LINE__ = 0;
                                switch ( a ) {
                                  case 0 :
                                    
                                    __LINE__ = 0;
                                    for ( var _mochaLocalTmp16 in m ){
                                      
                                      __LINE__ = 53;
                                      h.push( _mochaLocalTmp16 );
                                    };
                                    
                                    __LINE__ = 54;
                                    j = 0;
                                    
                                    __LINE__ = 54;
                                    k = h.length;
                                    
                                    __LINE__ = 0;
                                    if ( !( j<k ) ){
                                      __LINE__ = 53;
                                      a = -1;
                                      __LINE__ = 53;
                                      break;
                                    };
                                  case 1 :
                                    
                                    __LINE__ = 55;
                                    a = 2;
                                    
                                    __LINE__ = 0;
                                    l = h[j];
                                    __LINE__ = 55;
                                    return m[l];
                                  case 2 :
                                    
                                    __LINE__ = 0;
                                     ++ j;
                                    
                                    __LINE__ = 0;
                                    if ( j<k ){
                                      __LINE__ = 53;
                                      a = 1;
                                      __LINE__ = 0;
                                      break;
                                    } else {
                                      __LINE__ = 53;
                                      a = -1;
                                    };
                                  case -1 :
                                    
                                    __LINE__ = 0;
                                    if ( p ){
                                      __LINE__ = 0;
                                      return undefined;
                                    } else {
                                      __LINE__ = 53;
                                      h.throwException( h.StopIteration );
                                    };
                                    
                                };
                              };
                            } catch( e ){
                              h.exceptionHandler( __LINE__ , __FILE__ , e );
                            }
                          };
                      __LINE__ = 0;
                      return h.createGenerator( v,
                      function (  ) {
                        try {
                          __LINE__ = 0;
                          a = -1;
                        } catch( e ){
                          h.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      },this);
                    } catch( e ){
                      h.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  })();
                } catch( e ){
                  h.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              __LINE__ = 51;
              return g;
            } catch( e ){
              h.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          k.allItems = function A( m ) {
            try {
              __LINE__ = 0;
              var g =  {
                    
                  };
              
              __LINE__ = 0;
              g[a] = function () {
                try {
                  __LINE__ = 63;
                  return ( function () {
                    try {
                      __LINE__ = 0;
                      var a = true;
                      
                      __LINE__ = 0;
                      var u = undefined;
                      
                      __LINE__ = 0;
                      var a = 0;
                      
                      __LINE__ = 0;
                      var k;
                      
                      __LINE__ = 0;
                      var j;
                      
                      __LINE__ = 0;
                      var l;
                      
                      __LINE__ = 0;
                      var h = [];
                      
                      __LINE__ = 0;
                      var v = function ( o,p ) {
                            try {
                              __LINE__ = 0;
                              if ( !o ){
                                __LINE__ = 0;
                                a = false;
                              } else if ( o && a && arguments[1] !== undefined ){
                                __LINE__ = 0;
                                h.exceptionHandler( 'attempt to send to newborn generator.' );
                              };
                              
                              __LINE__ = 0;
                              while ( 1 ){
                                __LINE__ = 0;
                                switch ( a ) {
                                  case 0 :
                                    
                                    __LINE__ = 0;
                                    for ( var _mochaLocalTmp20 in m ){
                                      
                                      __LINE__ = 63;
                                      h.push( _mochaLocalTmp20 );
                                    };
                                    
                                    __LINE__ = 64;
                                    j = 0;
                                    
                                    __LINE__ = 64;
                                    k = h.length;
                                    
                                    __LINE__ = 0;
                                    if ( !( j<k ) ){
                                      __LINE__ = 63;
                                      a = -1;
                                      __LINE__ = 63;
                                      break;
                                    };
                                  case 1 :
                                    
                                    __LINE__ = 65;
                                    a = 2;
                                    
                                    __LINE__ = 0;
                                    l = h[j];
                                    __LINE__ = 65;
                                    return [l,m[l]];
                                  case 2 :
                                    
                                    __LINE__ = 0;
                                     ++ j;
                                    
                                    __LINE__ = 0;
                                    if ( j<k ){
                                      __LINE__ = 63;
                                      a = 1;
                                      __LINE__ = 0;
                                      break;
                                    } else {
                                      __LINE__ = 63;
                                      a = -1;
                                    };
                                  case -1 :
                                    
                                    __LINE__ = 0;
                                    if ( p ){
                                      __LINE__ = 0;
                                      return undefined;
                                    } else {
                                      __LINE__ = 63;
                                      h.throwException( h.StopIteration );
                                    };
                                    
                                };
                              };
                            } catch( e ){
                              h.exceptionHandler( __LINE__ , __FILE__ , e );
                            }
                          };
                      __LINE__ = 0;
                      return h.createGenerator( v,
                      function (  ) {
                        try {
                          __LINE__ = 0;
                          a = -1;
                        } catch( e ){
                          h.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      },this);
                    } catch( e ){
                      h.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  })();
                } catch( e ){
                  h.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              __LINE__ = 61;
              return g;
            } catch( e ){
              h.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          k.isGenerator = function B( a ) {
            try {
              __LINE__ = 72;
              return a.toString() === "[object Generator]";
            } catch( e ){
              h.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          k.isStopIteration = function C( b ) {
            try {
              __LINE__ = 76;
              return b === a;
            } catch( e ){
              h.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          __LINE__ = 0;
          return k;
        } catch( e ){
          h.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      })();
    } catch( e ){
      h.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  })();
  
  __LINE__ = 0;
  ( function () {
    try {
      var __FILE__ = "/Users/aono_taketoshi/github/mocha/test/mains/fmt.js",
          __LINE__ = 0;
      __LINE__ = 2;
      f['{1-397-1092-205522212-1695-60819241-2230-fmt.js}'] = {};
      
      __LINE__ = 3;
      var i = f['{1-397-1092-205522212-1695-60819241-2230-fmt.js}'];
      
      __LINE__ = 0;
      var j = f['{1-397-1092-26148-1746-829413-iterators.js}'].iterator;
      
      __LINE__ = 3;
      var k = Math.random();
      
      __LINE__ = 0;
      var l =  {
            
          };
      
      __LINE__ = 0;
      l[k] =  {
        v :  {
          gd : {}
        }
      };
      
      __LINE__ = 0;
      l[k].v[k] =  {
        g :  {
          g : function (){}
        }
      };
      
      __LINE__ = 4;
      var m = l;
      
      __LINE__ = 17;
      var n = 
          __LINE__ = 0;
          ( function () {
            try {
              __LINE__ = 0;
              var f = [];
              
              __LINE__ = 0;
              var g = rows;
              
              __LINE__ = 0;
              if ( g.__nothrowNext__ ){
                __LINE__ = 0;
                while ( ( i = g.__nothrowNext__(  ) ) ){
                  __LINE__ = 0;
                  var h = columns;
                  
                  __LINE__ = 0;
                  if ( h.__nothrowNext__ ){
                    __LINE__ = 0;
                    while ( ( j = h.__nothrowNext__(  ) ) ){
                      __LINE__ = 0;
                      f.push( [i,j] );
                    };
                  } else {
                    __LINE__ = 0;
                    exceptionHandler( 0,__FILE__,'for of statement expect iterator or generator object.' );
                  };
                };
              } else {
                __LINE__ = 0;
                exceptionHandler( 0,__FILE__,'for of statement expect iterator or generator object.' );
              };
              __LINE__ = 0;
              return f;
            } catch( e ){
              h.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })();
          ;
      
      __LINE__ = 18;
      var o =  {
            xa : 200,
            ya : 200
          };
      
      __LINE__ = 19;
      h.extend( o, {
        ret : n,
        m : m,
        name : k
      });
    } catch( e ){
      h.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  })();
})();
