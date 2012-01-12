(function() {
  var __FILE__ = "Runtime",
      __LINE__ = 0;
  
  __LINE__ = 1;
  var f = {},
      m = {};
  
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
          var a = m.StopIteration =  {
                toString : function toString() {
                  try {
                    __LINE__ = 290;
                    return "StopIteration";
                  } catch( e ){
                    h.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
              };
          
          __LINE__ = 293;
          var c = m.Iterator = function ( h,i ) {
                try {
                  __LINE__ = 0;
                  i = i || false;
                  
                  __LINE__ = 294;
                  var j = {},
                      k,
                      a,
                      b = 0;
                  
                  __LINE__ = 298;
                  if ( this instanceof c ){
                    __LINE__ = 299;
                    k = Array.isArray( h );
                    
                    __LINE__ = 300;
                    a = e( h,k,i );
                  } else {
                    __LINE__ = 302;
                    return f( h,i );
                  };
                  
                  __LINE__ = 304;
                  a( j,"next",
                  function () {
                    try {
                      __LINE__ = 304;
                      return a[b ++ ];
                    } catch( e ){
                      h.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  });
                  __LINE__ = 305;
                  return j;
                } catch( e ){
                  h.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
          
          __LINE__ = 308;
          var a = function ( b,c ) {
                try {
                  __LINE__ = 309;
                  var d = [],
                      e = -1;
                  
                  __LINE__ = 311;
                  if ( c ){
                    __LINE__ = 312;
                    for ( var prop in b ){
                      __LINE__ = 313;
                      d[ ++ e] = prop;
                    };
                  } else {
                    __LINE__ = 316;
                    for ( var prop in b ){
                      __LINE__ = 317;
                      d[ ++ e] = [prop,b[prop]];
                    };
                  };
                  __LINE__ = 320;
                  return d;
                } catch( e ){
                  h.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              },
              b = function ( b,c ) {
                try {
                  __LINE__ = 324;
                  var d = [];
                  
                  __LINE__ = 325;
                  if ( c ){
                    __LINE__ = 326;
                    for ( var i = 0,len = b.length;i<len;i ++  ){
                      __LINE__ = 327;
                      d[i] = i;
                    };
                  } else {
                    __LINE__ = 330;
                    for ( var i = 0,len = b.length;i<len;i ++  ){
                      __LINE__ = 331;
                      d[i] = [i,b[i]];
                    };
                  };
                  __LINE__ = 334;
                  return d;
                } catch( e ){
                  h.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              },
              c = function ( b,c ) {
                try {
                  __LINE__ = 338;
                  var d = [];
                  
                  __LINE__ = 339;
                  if ( c ){
                    __LINE__ = 340;
                    for ( var i = 0,len = b.length;i<len;i ++  ){
                      __LINE__ = 341;
                      d[i] = i;
                    };
                  } else {
                    __LINE__ = 344;
                    for ( var i = 0,len = b.length;i<len;i ++  ){
                      __LINE__ = 345;
                      d[i] = [i,b.charAt( i )];
                    };
                  };
                  __LINE__ = 348;
                  return d;
                } catch( e ){
                  h.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              },
              e = function ( d,e,f ) {
                try {
                  __LINE__ = 352;
                  var g = typeof d;
                  
                  __LINE__ = 353;
                  if ( g === "object" && !e ){
                    __LINE__ = 354;
                    return a( d,f );
                  } else if ( e ){
                    __LINE__ = 356;
                    return b( d,f );
                  } else if ( g === "string" ){
                    __LINE__ = 358;
                    return c( d,f );
                  };
                } catch( e ){
                  h.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              },
              f = function ( d,e ) {
                try {
                  __LINE__ = 363;
                  if ( "__iterator__" in d ){
                    __LINE__ = 364;
                    return d.__iterator__( e );
                  } else {
                    __LINE__ = 366;
                    return  {
                      next : function () {
                        try {
                          try {
                            __LINE__ = 369;
                            throw new a;
                          } catch( e ){
                            __LINE__ = 371;
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
          
          __LINE__ = 378;
          var r = m.createGenerator = function ( b,c,d ) {
                try {
                  __LINE__ = 379;
                  var e = {};
                  
                  __LINE__ = 380;
                  a( e,"next",b.bind( d,false,false ) );
                  
                  __LINE__ = 381;
                  a( e,"send",b.bind( d,true,false ) );
                  
                  __LINE__ = 382;
                  a( e,"close",c.bind( d ) );
                  
                  __LINE__ = 383;
                  a( e,"__nothrowNext__",c.bind( d,false,true ) );
                  
                  __LINE__ = 384;
                  a( e,"toString",
                  function () {
                    try {
                      __LINE__ = 384;
                      return "[object Generator]";
                    } catch( e ){
                      h.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  });
                } catch( e ){
                  h.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
          
          __LINE__ = 387;
          var a = function ( a ) {
                try {
                  __LINE__ = 387;
                  return ( ( a.message ) )?a.message : ( ( a.description ) )?a.description : a.toString();
                } catch( e ){
                  h.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
          
          __LINE__ = 389;
          var a = m.throwException = function ( d ) {
                try {
                  try {
                    __LINE__ = 391;
                    throw d;
                  } catch( e ){
                    __LINE__ = 393;
                    throw new Error( a( e ) );
                  };
                } catch( e ){
                  h.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
          
          __LINE__ = 397;
          function b( d,c,b ) {
            try {
              __LINE__ = 398;
              this.message = function () {
                try {
                  __LINE__ = 399;
                  return a( b )+" in file "+c+" at : "+d;
                } catch( e ){
                  h.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
            } catch( e ){
              h.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 403;
          var s = m.exceptionHandler = function ( c,d,e ) {
                try {
                  __LINE__ = 404;
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
  
  __LINE__ = 0;
  ( function () {
    try {
      var __FILE__ = "/var/samba/mocha/test/mains/fmt.js",
          __LINE__ = 0;
      __LINE__ = 2;
      f['{1-302-567-849-60818395-1384-fmt.js}'] = {};
      
      __LINE__ = 3;
      var i = f['{1-302-567-849-60818395-1384-fmt.js}'];
      
      __LINE__ = 2;
      var j = Math.random();
      
      __LINE__ = 0;
      var k =  {
            
          };
      
      __LINE__ = 0;
      k[j] =  {
        v :  {
          gd : {}
        }
      };
      
      __LINE__ = 0;
      k[j].v[j] =  {
        g :  {
          g : function (){}
        }
      };
      
      __LINE__ = 3;
      var l = k;
      
      __LINE__ = 16;
      var m = 
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
      
      __LINE__ = 17;
      var n =  {
            xa : 200,
            ya : 200
          };
      
      __LINE__ = 18;
      h.extend( n, {
        ret : m,
        m : l,
        name : j
      });
    } catch( e ){
      h.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  })();
})();
