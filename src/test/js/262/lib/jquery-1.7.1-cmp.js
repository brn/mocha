!function() {
  
  var b = {};
  
  !function ( f,g,h,i ) {
    var c = f.prototype,
        d = g.prototype,
        j = h.prototype,
        k = i.prototype;
    
    "use strict";
    
    function b( a ) {
      try {
        throw new TypeError( a );
      } catch( e ){
        throw new Error( e );
      };
    };
    
    function e( c,d ) {
      
      if ( typeof c !== "function" ){
        b( d+" : first argument is not callable" );
      };
    };
    
    if ( !Object.keys ){
      Object.keys = function ( a ) {
        if ( !a ){
          b( "Object.keys : first arguments is null or not defined." );
        };
        
        var c = [],
            d = -1;
        
        for ( var e in a )
        if ( a.hasOwnProperty( e ) ){
          c[ ++ d] = a[e];
        };
        return c;
      };
    };
    
    if ( !Object.preventExtensions ){
      Object.preventExtensions = function ( a ) {
        return a;
      };
    };
    
    if ( !Object.seal ){
      Object.seal = function ( a ) {
        return a;
      };
    };
    
    if ( !Object.freeze ){
      Object.freeze = function ( a ) {
        return a;
      };
    };
    
    var l = function () {
          var a;
          
          try {
            var b = {};
            
            Object.defineProperty( b,"test", {
              configurable : false,
              writable : false,
              enumerable : false,
              value : 0
            });
            
            b.test = 200;
            
            a = ( b.test === 200 )?false : true;
          } catch( e ){
            a = false;
          };
          return a;
        }();
    
    if ( !l ){
      Object.defineProperty = function ( a,b,c ) {
        if ( c.value ){
          a[b] = c.value;
        };
      };
    };
    
    if ( !c.trim ){
      c.trim = function () {
        return this.replace( c.trim.rtrim,"" );
      };
      
      c.trim.rtrim = /^\s*|\s*$/g;
    };
    
    if ( !c.repeat ){
      Object.defineProperty( c,"repeat", {
        value : function m( a ) {
          return Array( a+1 ).join( this.toString() );
        },
        configurable : true,
        enumerable : false,
        writable : true
      });
    };
    
    if ( !c.startsWith ){
      Object.defineProperty( c,"startsWith", {
        value : function m( a ) {
          return !this.indexOf( a );
        },
        configurable : true,
        enumerable : false,
        writable : true
      });
    };
    
    if ( !c.endsWith ){
      Object.defineProperty( c,"endsWith", {
        value : function m( a ) {
          var b = String( a );
          
          var c = this.lastIndexOf( b );
          return c >= 0 && c === this.length-b.length;
        },
        configurable : true,
        enumerable : false,
        writable : true
      });
    };
    
    if ( !c.contains ){
      Object.defineProperty( c,"contains", {
        value : function m( a ) {
          return this.indexOf( a ) !== -1;
        },
        configurable : true,
        enumerable : false,
        writable : true
      });
    };
    
    if ( !c.toArray ){
      Object.defineProperty( c,"toArray", {
        value : function m( a ) {
          return this.split( "" );
        },
        configurable : true,
        enumerable : false,
        writable : true
      });
    };
    
    if ( !j.bind ){
      j.bind = function () {
        var a = d.slice.call( arguments ),
            c = a.shift(),
            b = function () {
              var e = a.concat( d.slice.call( arguments ) );
              
              if ( this !== null && this !== window && this instanceof b ){
                return b.context.apply( this,e );
              } else {
                return b.context.apply( c,e );
              };
            };
        
        b.prototype = this.prototype;
        
        b.context = this;
        return b;
      };
    };
    
    if ( !d.forEach ){
      d.forEach = function ( f,g ) {
        e( f,"Array.forEach" );
        
        var h = -1,
            i;
        
        if ( this === null ){
          b( "Array.forEach : this is null or not defined" );
        };
        
        if ( g ){
          while ( ( i = this[ ++ h] ) !== null && i !== undefined )f.call( g,i,h,this );
        } else {
          while ( ( i = this[ ++ h] ) !== null && i !== undefined )f( i,h,this );
        };
      };
    };
    
    if ( !d.every ){
      d.every = function ( a,c ) {
        e( a,"Array.every" );
        
        var d = -1,
            f;
        
        if ( this === null ){
          b( "Array.every : this is null or not defined" );
        };
        
        if ( c ){
          while ( ( f = this[ ++ d] ) !== null && f !== undefined )if ( !( a.call( c,f,d,this ) ) ){
            return false;
          };
        } else {
          while ( ( f = this[ ++ d] ) !== null && f !== undefined )if ( !( a( f,d,this ) ) ){
            return false;
          };
        };
        return true;
      };
    };
    
    if ( !d.some ){
      d.some = function ( a,c ) {
        e( a,"Array.some" );
        
        var d = -1,
            f;
        
        if ( this === null ){
          b( "Array.some : this is null or not defined" );
        };
        
        if ( c ){
          while ( ( f = this[ ++ d] ) !== null && f !== undefined )if ( a.call( c,f,d,this ) ){
            return true;
          };
        } else {
          while ( ( f = this[ ++ d] ) !== null && f !== undefined )if ( a( f,d,this ) ){
            return true;
          };
        };
        return false;
      };
    };
    
    if ( !d.filter ){
      d.filter = function ( a,c ) {
        e( a,"Array.filter" );
        
        var d = this.length,
            f = -1,
            g = [],
            h;
        
        if ( this === null ){
          b( "Array.filter : this is null or not defined" );
        };
        
        if ( c ){
          for ( var i = 0,d = this.length;i<d; ++ i )
          if ( ( h = this[i] ) !== null && h !== undefined ){
            if ( a.call( c,h,i,this ) ){
              g[ ++ f] = h;
            };
          };
        } else {
          for ( var i = 0,d = this.length;i<d; ++ i )if ( ( h = this[i] ) !== null && h !== undefined ){
            if ( a( h,i,this ) ){
              g[ ++ f] = h;
            };
          };
        };
        return g;
      };
    };
    
    if ( !d.indexOf ){
      d.indexOf = function ( a,c ) {
        var d = ( c )?c-1 : -1,
            e = -1,
            f;
        
        if ( this === null ){
          b( "Array.indexOf : this is null or not defined." );
        };
        
        while ( ( f = this[ ++ d] ) !== null && f !== undefined )if ( f === a ){
          e = d;
          break;
        };
        return e;
      };
    };
    
    if ( !d.lastIndexOf ){
      d.lastIndexOf = function ( a,c ) {
        var d = this.length,
            e = ( c )?c+1 : d,
            f = -1,
            g;
        
        if ( this === null ){
          b( "Array.lastIndexOf : this is null or not defined." );
        };
        
        while ( ( g = this[ -- e] ) !== null && g !== undefined )if ( g === a ){
          f = e;
          break;
        };
        return f;
      };
    };
    
    if ( !d.map ){
      d.map = function ( a,c ) {
        e( a,"Array.map" );
        
        var d = [],
            f = -1,
            g = this.length,
            h = 0,
            i;
        
        if ( this === null ){
          b( "Array.map : this is null or not defined." );
        };
        
        if ( c ){
          for ( h;h<g; ++ h )if ( ( i = this[h] ) !== null && i !== undefined ){
            d[ ++ f] = a.call( c,i,h,this );
          };
        } else {
          for ( h;h<g; ++ h )if ( ( i = this[h] ) !== null && i !== undefined ){
            d[ ++ f] = a( i,h,this );
          };
        };
        return d;
      };
    };
    
    if ( !d.reduce ){
      d.reduce = function ( a,c ) {
        e( a,"Array.reduce" );
        
        var d = c || this[0],
            f = ( c )?0 : 1,
            g = this.length,
            h;
        
        if ( ( g === 0 || g === null ) && arguments.length<2 ){
          b( "Array length is 0 and no second argument" );
        };
        
        for ( f;f<g; ++ f )if ( ( h = this[f] ) !== null && h !== undefined ){
          d = a( d,h,f,this );
        };
        return d;
      };
    };
    
    if ( !d.reduceRight ){
      d.reduceRight = function ( a,c ) {
        e( a,"Array.reduceRight" );
        
        var d = this.length,
            f = c || this[d-1],
            g = ( c )?d-1 : d-2,
            h;
        
        if ( ( d === 0 || d === null ) && arguments.length<2 ){
          b( "Array length is 0 and no second argument" );
        };
        
        for ( g;g>-1; -- g )if ( ( h = this[g] ) !== null && h !== undefined ){
          f = a( f,h,g,this );
        };
        return f;
      };
    };
    
    if ( !k.toJSON ){
      k.toJSON = function () {
        var a = [this.getUTCMonth(),this.getUTCDate(),this.getUTCHours(),this.getMinutes(),this.getSeconds()],
            b = a[0],
            c = a[1],
            d = a[2],
            e = a[3],
            f = a[4];
        return '"'+this.getUTCFullYear()+'-'+( b>8?b+1 : "0"+( b+1 ) )+'-'+( c>9?c : "0"+c )+'T'+( d>9?d : "0"+d )+':'+( e>9?e : "0"+e )+':'+( f>9?f : "0"+f )+'.'+this.getUTCMilliseconds()+'Z"';
      };
    };
    
    if ( !Date.now ){
      Date.now = function () {
        return +new Date();
      };
    };
    
    if ( !Array.isArray ){
      Array.isArray = function ( a ) {
        if ( arguments.length === 0 ){
          return false;
        };
        return ( a )?Object.prototype.toString.call( a ) === "[object Array]" : false;
      };
    };
  }.call( this,String,Array,Function,Date );
  
  var a = function () {
        "use strict";
        var p = {};
        
        function c( d,c,b ) {
          this.toString = function () {
            return a.getErrorMessage( b )+" in file "+c+" at : "+d;
          };
        }
        var g = Math.max;
        
        var a =  {
              getErrorMessage : function q( a ) {
                return ( a.message )?a.message : ( a.description )?a.description : a.toString();
              },
              exceptionHandler : function r( d,e,f ) {
                if ( b( f ) ){
                  this.throwException( f );
                } else {
                  this.throwException( new c( d,e,f ) );
                };
              },
              throwException : function s( a ) {
                try {
                  throw a;
                } catch( e ){
                  if ( b( e ) ){
                    throw new Error( e );
                  } else {
                    throw new Error( this.getErrorMessage( e ) );
                  };
                };
              },
              hasProto : "__proto__" in {}
            };
        
        var d = Array.prototype.slice;
        
        function f( a,b,c ) {
          return Object.defineProperty( a,b, {
            configurable : true,
            enumerable : false,
            writable : true,
            value : c
          });
        };
        
        p.createUnenumProp = f;
        
        function t( a,b,c ) {
          return Object.defineProperty( a,b, {
            configurable : false,
            enumerable : false,
            writable : false,
            value : c
          });
        };
        
        p.constant = t;
        
        function u( e,f ) {
          return ( e )?d.call( e,f ) : [];
        };
        
        p.toArray = u;
        
        var e = function (){};
        
        function v( g,h,i ) {
          var j = new e;
          
          f( j,"next",g.bind( i,false,false ) );
          
          f( j,"send",g.bind( i,true,false ) );
          
          f( j,"close",h.bind( i ) );
          
          f( j,"__nothrowNext__",g.bind( i,false,true ) );
          
          f( j,"toString",
          function () {
            return "[object Generator]";
          });
          
          Object.freeze( j );
          return j;
        };
        
        p.createGenerator = v;
        
        function q( a ) {
          return ( a.message )?a.message : ( a.description )?a.description : a.toString();
        }
        var s = p.throwException = a.throwException.bind( a );
        
        var r = p.exceptionHandler = a.exceptionHandler.bind( a );
        
        function w( a,b ) {
          for ( var c in b )
          a[c] = b[c];
          return a;
        };
        
        p.extend = w;
        
        function h( h ) {
          var i = g( h.length,this.length ),
              j = -1;
          
          while (  ++ j<i && h[j] === this[j] )return i === j;
        };
        
        function i() {
          return Array.prototype.slice.call( this );
        };
        
        function x( j,k ) {
          f( j,"length",k );
          
          f( j,"equal",h );
          
          f( j,"toArray",i );
          
          f( j,"toString",
          function () {
            return "[object Tuple]";
          });
          return Object.freeze( j );
        };
        
        p.createTuple = x;
        
        function y( a ) {
          if ( a.toString() === "[object Object]" ){
            f( a,"toString",
            function () {
              return "[object Record]";
            });
          };
          return Object.freeze( a );
        };
        
        p.createRecord = y;
        
        var z = p.extendPrototype = function ( a,b ) {
              a.prototype = b;
            };
        
        var j = ( "getPrototypeOf" in Object )?function ( a ) {
              return Object.getPrototypeOf( a );
            } : function ( a ) {
              var b = {};
              
              for ( var c in a )
              if ( !a.hasOwnProperty( c ) ){
                b[c] = a[c];
              };
              return b;
            };
        
        var A = p.extendClass = ( a.hasProto )?function ( a,b ) {
              if ( typeof b === 'function' ){
                a.prototype.__proto__ = b.prototype;
                
                for ( var c in b )
                a[c] = b[c];
              } else {
                a.prototype.__proto__ = b.__proto__;
              };
            } : function ( k,l ) {
              var m = typeof l;
              
              if ( m === "function" ){
                var n = function (){};
                
                n.prototype = l.prototype;
                
                k.prototype = new n;
                
                for ( var o in l )
                k[o] = l[o];
              } else {
                var n = function (){},
                    p = j( l );
                
                n.prototype = p;
                
                k.prototype = new n;
              };
            };
        
        var k = p.__ref_iterator__ = "__mocha_iterator_special_key__";
        
        function m() {
          try {
            throw StopIteration;
          } catch( e ){
            throw new Error( e.toString() );
          };
        };
        
        p.throwStopIteration = m;
        
        function l( a ) {
          return a instanceof e;
        };
        
        p.isGenerator = l;
        
        function B( n ) {
          var a = n[k](),
              o;
          
          if ( l( a ) ){
            return a;
          };
          
          o = {};
          
          if ( a.next ){
            f( o,"next",
            function () {
              var b = a.next();
              
              if ( b === undefined ){
                m();
              };
              return b;
            });
          } else {
            return {};
          };
          
          if ( !( "__nothrowNext__" in a ) ){
            f( o,"__nothrowNext__",a.next.bind( a ) );
          };
          
          for ( var p in a )
          if ( p !== "next" && p !== "__nothrowNext__" ){
            o[p] = a[p];
          };
          
          if ( !( "toString" in a ) ){
            f( o,"toString",
            function () {
              return "[object Iterator]";
            });
          };
          return o;
        };
        
        p.getIterator = B;
        
        function C( a ) {
          return k in a;
        };
        
        p.hasIterator = C;
        
        var n = /StopIteration/;
        
        function b( o ) {
          return o === StopIteration || n.test( o );
        };
        
        p.isStopIteration = b;
        
        var o,
            D,
            E;
        
        if ( "WeakMap" in window ){
          o = new WeakMap();
          
          D = function ( self,p ) {
            var q = new p;
            
            f( q.constructor,"__is_private__",1 );
            
            o.set( self,q );
          };
          
          E = function ( self ) {
            if ( o.has( self ) ){
              return o.get( self );
            } else if ( self.constructor === "__is_private__" ){
              return self;
            };
          };
        } else {
          D = function ( self,a ) {
            if ( !self.__typeid__ ){
              var b = new a;
              
              f( b.constructor,"__is_private__",1 );
              
              f( self,"__private__",b );
            };
          };
          
          E = function ( self ) {
            if ( self.__private__ ){
              return self.__private__;
            } else if ( self.constructor === "__is_private__" ){
              return self;
            };
          };
        };
        
        p.createPrivateRecord = D;
        
        p.getPrivateRecord = E;
        
        function F( a ) {
          var b = typeof a,
              c;
          
          if ( b === "function" ){
            c = function (){};
            
            c.prototype = a.prototype;
            
            c = new c();
            
            if ( a.__harmony_class__ ){
              c.constructor = a.constructor;
            } else {
              c.constructor = a;
            };
            return c;
          };
          return c;
        };
        
        p.getSuper = F;
        
        function G( b,c,d,e ) {
          if ( !b._mochaTraitMark || !c._mochaTraitMark ){
            a.throwException( "mixin only used for trait." );
          } else {
            var f = b._mochaTraitPrivate,
                g = c._mochaTraitPrivate,
                h = b._mochaTraitPublic,
                i = c._mochaTraitPublic,
                j = c._mochaRequires,
                k = b._mochaRequires,
                l;
            
            for ( var m in g )if ( !e[m] ){
              l = ( !d[m] )?m : d[m];
              
              f[l] = g[m];
            };
            
            for ( m in i )if ( !e[m] ){
              l = ( !d[m] )?m : d[m];
              
              h[l] = i[m];
            };
            
            for ( m in j )k[m] = j[m];
          };
        };
        
        p.traitMixin = G;
        
        function H( b,c,d,e,f ) {
          var g = b.prototype,
              h = c.prototype,
              i = d._mochaTraitMark,
              j = d._mochaTraitPublic,
              k = d._mochaTraitPrivate;
          
          if ( !i ){
            a.throwException( "mixin only used for trait." );
          } else {
            var l;
            
            for ( var m in j )if ( !f[m] ){
              l = ( !e[m] )?m : e[m];
              
              g[l] = j[m];
            };
            
            for ( m in k )if ( !f[m] ){
              l = ( !e[m] )?m : e[m];
              
              h[l] = k[m];
            };
          };
        };
        
        p.classMixin = H;
        
        function I( b,c,d,e,f ) {
          var g = b.prototype,
              h = c.prototype;
          
          for ( var i = 0,j = d.length;i<j;i ++  ){
            var k = d[i],
                l = k._mochaRequires;
            
            for ( var m in l )
            if ( !( m in g ) && !( m in h ) ){
              a.throwException( "Class dose not meet the traits requirement. traits require implementation of property "+m+"\nin file "+e+" at line "+f );
            };
          };
        };
        
        p.checkRequirements = I;
        return p;
      }();
  
  if ( !( "StopIteration" in window ) ){
    window.StopIteration =  {
      toString : function c() {
        return "[object StopIteration]";
      }
    };
  };
  
  !function () {
    b['./jquery-1.7.1.js'] = {};
    
    var d = b['./jquery-1.7.1.js'];
    
    !function ( a,undefined ) {
      var document = a.document,
          navigator = a.navigator,
          u8 = a.location;
      
      var e = function () {
            var b = function ( d,e ) {
                  return new b.fn.init( d,e,c );
                },
                j = a.jQuery,
                i = a.$,
                c,
                d = /^(?:[^#<]*(<[\w\W]+>)[^>]*$|#([\w\-]*)$)/,
                t = /\S/,
                y = /^\s+/,
                z = /\s+$/,
                e = /^<(\w+)\s*\/?>(?:<\/\1>)?$/,
                p = /^[\],:{}\s]*$/,
                q = /\\(?:["\\\/bfnrt]|u[0-9a-fA-F]{4})/g,
                r = /"[^"\\\n\r]*"|true|false|null|-?\d+(?:\.\d*)?(?:[eE][+\-]?\d+)?/g,
                s = /(?:^|:|,)(?:\s*\[)+/g,
                B = /(webkit)[ \/]([\w.]+)/,
                C = /(opera)(?:.*version)?[ \/]([\w.]+)/,
                D = /(msie) ([\w.]+)/,
                E = /(mozilla)(?:.*? rv:([\w.]+))?/,
                v = /-([a-z]|[0-9])/ig,
                u = /^-ms-/,
                w = function ( a,b ) {
                  return ( b+"" ).toUpperCase();
                },
                F = navigator.userAgent,
                G,
                h,
                k,
                n = Object.prototype.toString,
                o = Object.prototype.hasOwnProperty,
                g = Array.prototype.push,
                f = Array.prototype.slice,
                x = String.prototype.trim,
                A = Array.prototype.indexOf,
                m = {};
            
            b.fn = b.prototype =  {
              constructor : b,
              init : function ( f,g,h ) {
                var i,
                    j,
                    k,
                    l;
                
                if ( !f ){
                  return this;
                };
                
                if ( f.nodeType ){
                  this.context = this[0] = f;
                  
                  this.length = 1;
                  return this;
                };
                
                if ( f === "body" && !g && document.body ){
                  this.context = document;
                  
                  this[0] = document.body;
                  
                  this.selector = f;
                  
                  this.length = 1;
                  return this;
                };
                
                if ( typeof f === "string" ){
                  if ( f.charAt( 0 ) === "<" && f.charAt( f.length-1 ) === ">" && f.length >= 3 ){
                    i = [null,f,null];
                  } else {
                    i = d.exec( f );
                  };
                  
                  if ( i && ( i[1] || !g ) ){
                    if ( i[1] ){
                      g = g instanceof b?g[0] : g;
                      
                      l = ( g?g.ownerDocument || g : document );
                      
                      k = e.exec( f );
                      
                      if ( k ){
                        if ( b.isPlainObject( g ) ){
                          f = [document.createElement( k[1] )];
                          
                          b.fn.attr.call( f,g,true );
                        } else {
                          f = [l.createElement( k[1] )];
                        };
                      } else {
                        k = b.buildFragment( [i[1]],[l] );
                        
                        f = ( k.cacheable?b.clone( k.fragment ) : k.fragment ).childNodes;
                      };
                      return b.merge( this,f );
                    } else {
                      j = document.getElementById( i[2] );
                      if ( j && j.parentNode ){
                        if ( j.id !== i[2] ){
                          return h.find( f );
                        };
                        
                        this.length = 1;
                        
                        this[0] = j;
                      };
                      
                      this.context = document;
                      
                      this.selector = f;
                      return this;
                    };
                  } else if ( !g || g.jquery ){
                    return ( g || h ).find( f );
                  } else {
                    return this.constructor( g ).find( f );
                  };
                } else if ( b.isFunction( f ) ){
                  return h.ready( f );
                };
                
                if ( f.selector !== undefined ){
                  this.selector = f.selector;
                  
                  this.context = f.context;
                };
                return b.makeArray( f,this );
              },
              selector : "",
              jquery : "1.7.1",
              length : 0,
              size : function () {
                return this.length;
              },
              toArray : function () {
                return f.call( this,0 );
              },
              get : function ( a ) {
                return a == null?this.toArray() : ( a<0?this[this.length+a] : this[a] );
              },
              pushStack : function ( h,i,j ) {
                var k = this.constructor();
                
                if ( b.isArray( h ) ){
                  g.apply( k,h );
                } else {
                  b.merge( k,h );
                };
                
                k.prevObject = this;
                
                k.context = this.context;
                
                if ( i === "find" ){
                  k.selector = this.selector+( this.selector?" " : "" )+j;
                } else if ( i ){
                  k.selector = this.selector+"."+i+"("+j+")";
                };
                return k;
              },
              each : function ( a,c ) {
                return b.each( this,a,c );
              },
              ready : function ( i ) {
                b.bindReady();
                
                h.add( i );
                return this;
              },
              eq : function ( a ) {
                a = +a;
                return a === -1?this.slice( a ) : this.slice( a,a+1 );
              },
              first : function () {
                return this.eq( 0 );
              },
              last : function () {
                return this.eq( -1 );
              },
              slice : function () {
                return this.pushStack( f.apply( this,arguments ),"slice",f.call( arguments ).join( "," ) );
              },
              map : function ( a ) {
                return this.pushStack( b.map( this,
                function ( b,c ) {
                  return a.call( b,c,b );
                }) );
              },
              end : function () {
                return this.prevObject || this.constructor( null );
              },
              push : g,
              sort : [].sort,
              splice : [].splice
            };
            
            b.fn.init.prototype = b.fn;
            
            b.extend = b.fn.extend = function () {
              var a,
                  c,
                  d,
                  e,
                  f,
                  g,
                  h = arguments[0] || {},
                  i = 1,
                  j = arguments.length,
                  k = false;
              
              if ( typeof h === "boolean" ){
                k = h;
                
                h = arguments[1] || {};
                
                i = 2;
              };
              
              if ( typeof h !== "object" && !b.isFunction( h ) ){
                h = {};
              };
              
              if ( j === i ){
                h = this;
                
                 -- i;
              };
              
              for ( ;i<j;i ++  )if ( ( a = arguments[i] ) != null ){
                for ( c in a ){
                  d = h[c];
                  
                  e = a[c];
                  
                  if ( h === e ){
                    continue ;
                  };
                  
                  if ( k && e && ( b.isPlainObject( e ) || ( f = b.isArray( e ) ) ) ){
                    if ( f ){
                      f = false;
                      
                      g = d && b.isArray( d )?d : [];
                    } else {
                      g = d && b.isPlainObject( d )?d : {};
                    };
                    
                    h[c] = b.extend( k,g,e );
                  } else if ( e !== undefined ){
                    h[c] = e;
                  };
                };
              };
              return h;
            };
            
            b.extend(  {
              noConflict : function ( k ) {
                if ( a.$ === b ){
                  a.$ = i;
                };
                
                if ( k && a.jQuery === b ){
                  a.jQuery = j;
                };
                return b;
              },
              isReady : false,
              readyWait : 1,
              holdReady : function ( a ) {
                if ( a ){
                  b.readyWait ++ ;
                } else {
                  b.ready( true );
                };
              },
              ready : function ( a ) {
                if ( ( a === true && ! -- b.readyWait ) || ( a !== true && !b.isReady ) ){
                  if ( !document.body ){
                    return setTimeout( b.ready,1 );
                  };
                  
                  b.isReady = true;
                  
                  if ( a !== true &&  -- b.readyWait>0 ){
                    return ;
                  };
                  
                  h.fireWith( document,[b] );
                  
                  if ( b.fn.trigger ){
                    b( document ).trigger( "ready" ).off( "ready" );
                  };
                };
              },
              bindReady : function () {
                if ( h ){
                  return ;
                };
                
                h = b.Callbacks( "once memory" );
                
                if ( document.readyState === "complete" ){
                  return setTimeout( b.ready,1 );
                };
                
                if ( document.addEventListener ){
                  document.addEventListener( "DOMContentLoaded",k,false );
                  
                  a.addEventListener( "load",b.ready,false );
                } else if ( document.attachEvent ){
                  document.attachEvent( "onreadystatechange",k );
                  
                  a.attachEvent( "onload",b.ready );
                  
                  var m = false;
                  
                  try {
                    m = a.frameElement == null;
                  } catch( e ){
                    
                  };
                  if ( document.documentElement.doScroll && m ){
                    l();
                  };
                };
              },
              isFunction : function ( a ) {
                return b.type( a ) === "function";
              },
              isArray : Array.isArray || function ( a ) {
                return b.type( a ) === "array";
              },
              isWindow : function ( a ) {
                return a && typeof a === "object" && "setInterval" in a;
              },
              isNumeric : function ( a ) {
                return !isNaN( parseFloat( a ) ) && isFinite( a );
              },
              type : function ( o ) {
                return o == null?String( o ) : m[n.call( o )] || "object";
              },
              isPlainObject : function ( p ) {
                if ( !p || b.type( p ) !== "object" || p.nodeType || b.isWindow( p ) ){
                  return false;
                };
                
                try {
                  if ( p.constructor && !o.call( p,"constructor" ) && !o.call( p.constructor.prototype,"isPrototypeOf" ) ){
                    return false;
                  };
                } catch( e ){
                  return false;
                };
                
                var q;
                
                for ( q in p ){
                  
                };
                return q === undefined || o.call( p,q );
              },
              isEmptyObject : function ( a ) {
                for ( var b in a )return false;
                return true;
              },
              error : function ( a ) {
                throw new Error( a );
              },
              parseJSON : function ( t ) {
                if ( typeof t !== "string" || !t ){
                  return null;
                };
                
                t = b.trim( t );
                
                if ( a.JSON && a.JSON.parse ){
                  return a.JSON.parse( t );
                };
                
                if ( p.test( t.replace( q,"@" ).replace( r,"]" ).replace( s,"" ) ) ){
                  return ( new Function( "return "+t ) )();
                };
                
                b.error( "Invalid JSON: "+t );
              },
              parseXML : function ( c ) {
                var d,
                    e;
                
                try {
                  if ( a.DOMParser ){
                    e = new DOMParser();
                    
                    d = e.parseFromString( c,"text/xml" );
                  } else {
                    d = new ActiveXObject( "Microsoft.XMLDOM" );
                    
                    d.async = "false";
                    
                    d.loadXML( c );
                  };
                } catch( e ){
                  d = undefined;
                };
                
                if ( !d || !d.documentElement || d.getElementsByTagName( "parsererror" ).length ){
                  b.error( "Invalid XML: "+c );
                };
                return d;
              },
              noop : function (){},
              globalEval : function ( u ) {
                if ( u && t.test( u ) ){
                  ( a.execScript || function ( b ) {
                    a["eval"].call( a,b );
                  })( u );
                };
              },
              camelCase : function ( x ) {
                return x.replace( u,"ms-" ).replace( v,w );
              },
              nodeName : function ( a,b ) {
                return a.nodeName && a.nodeName.toUpperCase() === b.toUpperCase();
              },
              each : function ( a,c,d ) {
                var e,
                    f = 0,
                    g = a.length,
                    h = g === undefined || b.isFunction( a );
                
                if ( d ){
                  if ( h ){
                    for ( e in a )if ( c.apply( a[e],d ) === false ){
                      break;
                    };
                  } else {
                    for ( ;f<g; )if ( c.apply( a[f ++ ],d ) === false ){
                      break;
                    };
                  };
                } else if ( h ){
                  for ( e in a )if ( c.call( a[e],e,a[e] ) === false ){
                    break;
                  };
                } else {
                  for ( ;f<g; )if ( c.call( a[f],f,a[f ++ ] ) === false ){
                    break;
                  };
                };
                return a;
              },
              trim : x?function ( y ) {
                return y == null?"" : x.call( y );
              } : function ( A ) {
                return A == null?"" : A.toString().replace( y,"" ).replace( z,"" );
              },
              makeArray : function ( a,c ) {
                var d = c || [];
                
                if ( a != null ){
                  var e = b.type( a );
                  
                  if ( a.length == null || e === "string" || e === "function" || e === "regexp" || b.isWindow( a ) ){
                    g.call( d,a );
                  } else {
                    b.merge( d,a );
                  };
                };
                return d;
              },
              inArray : function ( B,C,D ) {
                var E;
                
                if ( C ){
                  if ( A ){
                    return A.call( C,B,D );
                  };
                  
                  E = C.length;
                  
                  D = D?D<0?Math.max( 0,E+D ) : D : 0;
                  
                  for ( ;D<E;D ++  )if ( D in C && C[D] === B ){
                    return D;
                  };
                };
                return -1;
              },
              merge : function ( a,b ) {
                var c = a.length,
                    d = 0;
                
                if ( typeof b.length === "number" ){
                  for ( var e = b.length;d<e;d ++  )
                  a[c ++ ] = b[d];
                } else {
                  while ( b[d] !== undefined )a[c ++ ] = b[d ++ ];
                };
                
                a.length = c;
                return a;
              },
              grep : function ( a,b,c ) {
                var d = [],
                    e;
                
                c = !!c;
                
                for ( var f = 0,g = a.length;f<g;f ++  ){
                  e = !!b( a[f],f );
                  
                  if ( c !== e ){
                    d.push( a[f] );
                  };
                };
                return d;
              },
              map : function ( a,c,d ) {
                var e,
                    f,
                    g = [],
                    h = 0,
                    i = a.length,
                    j = a instanceof b || i !== undefined && typeof i === "number" && ( ( i>0 && a[0] && a[i-1] ) || i === 0 || b.isArray( a ) );
                
                if ( j ){
                  for ( ;h<i;h ++  ){
                    e = c( a[h],h,d );
                    
                    if ( e != null ){
                      g[g.length] = e;
                    };
                  };
                } else {
                  for ( f in a ){
                    e = c( a[f],f,d );
                    if ( e != null ){
                      g[g.length] = e;
                    };
                  };
                };
                return g.concat.apply( [],g );
              },
              guid : 1,
              proxy : function ( a,c ) {
                if ( typeof c === "string" ){
                  var e = a[c];
                  
                  c = a;
                  
                  a = e;
                };
                
                if ( !b.isFunction( a ) ){
                  return undefined;
                };
                
                var d = f.call( arguments,2 ),
                    g = function () {
                      return a.apply( c,d.concat( f.call( arguments ) ) );
                    };
                
                g.guid = a.guid = a.guid || g.guid || b.guid ++ ;
                return g;
              },
              access : function ( a,c,d,e,f,g ) {
                var h = a.length;
                
                if ( typeof c === "object" ){
                  for ( var i in c )
                  b.access( a,i,c[i],e,f,d );
                  return a;
                };
                
                if ( d !== undefined ){
                  e = !g && e && b.isFunction( d );
                  
                  for ( var j = 0;j<h;j ++  )
                  f( a[j],c,e?d.call( a[j],j,f( a[j],c ) ) : d,g );
                  return a;
                };
                return h?f( a[0],c ) : undefined;
              },
              now : function () {
                return ( new Date() ).getTime();
              },
              uaMatch : function ( F ) {
                F = F.toLowerCase();
                
                var G = B.exec( F ) || C.exec( F ) || D.exec( F ) || F.indexOf( "compatible" )<0 && E.exec( F ) || [];
                return  {
                  browser : G[1] || "",
                  version : G[2] || "0"
                };
              },
              sub : function () {
                function a( b,c ) {
                  return new a.fn.init( b,c );
                }
                b.extend( true,a,this );
                
                a.superclass = this;
                
                a.fn = a.prototype = this();
                
                a.fn.constructor = a;
                
                a.sub = this.sub;
                
                a.fn.init = function d( d,e ) {
                  if ( e && e instanceof b && !( e instanceof a ) ){
                    e = a( e );
                  };
                  return b.fn.init.call( this,d,e,c );
                };
                
                a.fn.init.prototype = a.fn;
                
                var c = a( document );
                return a;
              },
              browser : {}
            });
            
            b.each( "Boolean Number String Function Array Date RegExp Object".split( " " ),
            function ( a,b ) {
              m["[object "+b+"]"] = b.toLowerCase();
            });
            
            G = b.uaMatch( F );
            
            if ( G.browser ){
              b.browser[G.browser] = true;
              
              b.browser.version = G.version;
            };
            
            if ( b.browser.webkit ){
              b.browser.safari = true;
            };
            
            if ( t.test( "\xA0" ) ){
              y = /^[\s\xA0]+/;
              
              z = /[\s\xA0]+$/;
            };
            
            c = b( document );
            
            if ( document.addEventListener ){
              k = function () {
                document.removeEventListener( "DOMContentLoaded",k,false );
                
                b.ready();
              };
            } else if ( document.attachEvent ){
              k = function () {
                if ( document.readyState === "complete" ){
                  document.detachEvent( "onreadystatechange",k );
                  
                  b.ready();
                };
              };
            };
            
            function l() {
              if ( b.isReady ){
                return ;
              };
              
              try {
                document.documentElement.doScroll( "left" );
              } catch( e ){
                setTimeout( l,1 );
                return ;
              };
              
              b.ready();
            }return b;
          }();
      
      var b = {};
      
      function d( c ) {
        var d = b[c] = {},
            e,
            f;
        
        c = c.split( /\s+/ );
        
        for ( e = 0 , f = c.length;e<f;e ++  )d[c[e]] = true;
        return d;
      }
      e.Callbacks = function ( c ) {
        c = c?( b[c] || d( c ) ) : {};
        
        var f = [],
            l = [],
            g,
            h,
            j,
            k,
            i,
            a = function ( g ) {
              var h,
                  i,
                  j,
                  k,
                  l;
              
              for ( h = 0 , i = g.length;h<i;h ++  ){
                j = g[h];
                
                k = e.type( j );
                
                if ( k === "array" ){
                  a( j );
                } else if ( k === "function" ){
                  if ( !c.unique || !self.has( j ) ){
                    f.push( j );
                  };
                };
              };
            },
            m = function ( m,n ) {
              n = n || [];
              
              g = !c.memory || [m,n];
              
              h = true;
              
              i = j || 0;
              
              j = 0;
              
              k = f.length;
              
              for ( ;f && i<k;i ++  )if ( f[i].apply( m,n ) === false && c.stopOnFalse ){
                g = true;
                break;
              };
              
              h = false;
              
              if ( f ){
                if ( !c.once ){
                  if ( l && l.length ){
                    g = l.shift();
                    
                    self.fireWith( g[0],g[1] );
                  };
                } else if ( g === true ){
                  self.disable();
                } else {
                  f = [];
                };
              };
            },
            self =  {
              add : function () {
                if ( f ){
                  var n = f.length;
                  
                  a( arguments );
                  
                  if ( h ){
                    k = f.length;
                  } else if ( g && g !== true ){
                    j = n;
                    
                    m( g[0],g[1] );
                  };
                };
                return this;
              },
              remove : function () {
                if ( f ){
                  var a = arguments,
                      b = 0,
                      d = a.length;
                  
                  for ( ;b<d;b ++  )for ( var e = 0;e<f.length;e ++  )
                  if ( a[b] === f[e] ){
                    if ( h ){
                      if ( e <= k ){
                        k -- ;
                        
                        if ( e <= i ){
                          i -- ;
                        };
                      };
                    };
                    
                    f.splice( e -- ,1 );
                    
                    if ( c.unique ){
                      break;
                    };
                  };
                };
                return this;
              },
              has : function ( a ) {
                if ( f ){
                  var b = 0,
                      c = f.length;
                  
                  for ( ;b<c;b ++  )if ( a === f[b] ){
                    return true;
                  };
                };
                return false;
              },
              empty : function () {
                f = [];
                return this;
              },
              disable : function () {
                f = l = g = undefined;
                return this;
              },
              disabled : function () {
                return !f;
              },
              lock : function () {
                l = undefined;
                
                if ( !g || g === true ){
                  self.disable();
                };
                return this;
              },
              locked : function () {
                return !l;
              },
              fireWith : function ( a,b ) {
                if ( l ){
                  if ( h ){
                    if ( !c.once ){
                      l.push( [a,b] );
                    };
                  } else if ( !( c.once && g ) ){
                    m( a,b );
                  };
                };
                return this;
              },
              fire : function () {
                self.fireWith( this,arguments );
                return this;
              },
              fired : function () {
                return !!g;
              }
            };
        return self;
      };
      
      var f = [].slice;
      
      e.extend(  {
        Deferred : function ( d ) {
          var f = e.Callbacks( "once memory" ),
              g = e.Callbacks( "once memory" ),
              h = e.Callbacks( "memory" ),
              a = "pending",
              i =  {
                resolve : f,
                reject : g,
                notify : h
              },
              c =  {
                done : f.add,
                fail : g.add,
                progress : h.add,
                state : function () {
                  return a;
                },
                isResolved : f.fired,
                isRejected : g.fired,
                then : function ( c,d,e ) {
                  b.done( c ).fail( d ).progress( e );
                  return this;
                },
                always : function () {
                  b.done.apply( b,arguments ).fail.apply( b,arguments );
                  return this;
                },
                pipe : function ( a,c,d ) {
                  return e.Deferred( function ( f ) {
                    e.each(  {
                      done : [a,"resolve"],
                      fail : [c,"reject"],
                      progress : [d,"notify"]
                    },
                    function ( g,h ) {
                      var c = h[0],
                          d = h[1],
                          a;
                      
                      if ( e.isFunction( c ) ){
                        b[g]( function () {
                          a = c.apply( this,arguments );
                          
                          if ( a && e.isFunction( a.promise ) ){
                            a.promise().then( f.resolve,f.reject,f.notify );
                          } else {
                            f[d+"With"]( this === b?f : this,[a] );
                          };
                        });
                      } else {
                        b[g]( f[d] );
                      };
                    });
                  }).promise();
                },
                promise : function ( d ) {
                  if ( d == null ){
                    d = c;
                  } else {
                    for ( var e in c )
                    d[e] = c[e];
                  };
                  return d;
                }
              },
              b = c.promise( {} ),
              j;
          
          for ( j in i ){
            b[j] = i[j].fire;
            
            b[j+"With"] = i[j].fireWith;
          };
          
          b.done( function () {
            a = "resolved";
          },g.disable,h.lock ).fail( function () {
            a = "rejected";
          },f.disable,h.lock );
          
          if ( d ){
            d.call( b,b );
          };
          return b;
        },
        when : function ( h ) {
          var a = f.call( arguments,0 ),
              i = 0,
              j = a.length,
              d = new Array( j ),
              b = j,
              k = j,
              c = j <= 1 && h && e.isFunction( h.promise )?h : e.Deferred(),
              g = c.promise();
          
          function l( d ) {
            return function ( e ) {
              a[d] = arguments.length>1?f.call( arguments,0 ) : e;
              
              if ( !(  -- b ) ){
                c.resolveWith( c,a );
              };
            };
          }
          function m( a ) {
            return function ( b ) {
              d[a] = arguments.length>1?f.call( arguments,0 ) : b;
              
              c.notifyWith( g,d );
            };
          }
          if ( j>1 ){
            for ( ;i<j;i ++  )if ( a[i] && a[i].promise && e.isFunction( a[i].promise ) ){
              a[i].promise().then( l( i ),c.reject,m( i ) );
            } else {
               -- b;
            };
            
            if ( !b ){
              c.resolveWith( c,a );
            };
          } else if ( c !== h ){
            c.resolveWith( c,j?[h] : [] );
          };
          return g;
        }
      });
      
      e.support = function () {
        var b,
            g,
            h,
            i,
            j,
            k,
            l,
            m,
            d,
            n,
            o,
            p,
            f,
            c = document.createElement( "div" ),
            q = document.documentElement;
        
        c.setAttribute( "className","t" );
        
        c.innerHTML = "   <link/><table></table><a href='/a' style='top:1px;float:left;opacity:.55;'>a</a><input type='checkbox'/>";
        
        g = c.getElementsByTagName( "*" );
        
        h = c.getElementsByTagName( "a" )[0];
        
        if ( !g || !g.length || !h ){
          return {};
        };
        
        i = document.createElement( "select" );
        
        j = i.appendChild( document.createElement( "option" ) );
        
        k = c.getElementsByTagName( "input" )[0];
        
        b =  {
          leadingWhitespace : ( c.firstChild.nodeType === 3 ),
          tbody : !c.getElementsByTagName( "tbody" ).length,
          htmlSerialize : !!c.getElementsByTagName( "link" ).length,
          style : /top/.test( h.getAttribute( "style" ) ),
          hrefNormalized : ( h.getAttribute( "href" ) === "/a" ),
          opacity : /^0.55/.test( h.style.opacity ),
          cssFloat : !!h.style.cssFloat,
          checkOn : ( k.value === "on" ),
          optSelected : j.selected,
          getSetAttribute : c.className !== "t",
          enctype : !!document.createElement( "form" ).enctype,
          html5Clone : document.createElement( "nav" ).cloneNode( true ).outerHTML !== "<:nav></:nav>",
          submitBubbles : true,
          changeBubbles : true,
          focusinBubbles : false,
          deleteExpando : true,
          noCloneEvent : true,
          inlineBlockNeedsLayout : false,
          shrinkWrapBlocks : false,
          reliableMarginRight : true
        };
        
        k.checked = true;
        
        b.noCloneChecked = k.cloneNode( true ).checked;
        
        i.disabled = true;
        
        b.optDisabled = !j.disabled;
        
        try {
          delete c.test;
        } catch( e ){
          b.deleteExpando = false;
        };
        
        if ( !c.addEventListener && c.attachEvent && c.fireEvent ){
          c.attachEvent( "onclick",
          function () {
            b.noCloneEvent = false;
          });
          
          c.cloneNode( true ).fireEvent( "onclick" );
        };
        
        k = document.createElement( "input" );
        
        k.value = "t";
        
        k.setAttribute( "type","radio" );
        
        b.radioValue = k.value === "t";
        
        k.setAttribute( "checked","checked" );
        
        c.appendChild( k );
        
        m = document.createDocumentFragment();
        
        m.appendChild( c.lastChild );
        
        b.checkClone = m.cloneNode( true ).cloneNode( true ).lastChild.checked;
        
        b.appendChecked = k.checked;
        
        m.removeChild( k );
        
        m.appendChild( c );
        
        c.innerHTML = "";
        
        if ( a.getComputedStyle ){
          l = document.createElement( "div" );
          
          l.style.width = "0";
          
          l.style.marginRight = "0";
          
          c.style.width = "2px";
          
          c.appendChild( l );
          
          b.reliableMarginRight = ( parseInt( ( a.getComputedStyle( l,null ) ||  {
            marginRight : 0
          }).marginRight,10 ) || 0 ) === 0;
        };
        
        if ( c.attachEvent ){
          for ( p in  {
            submit : 1,
            change : 1,
            focusin : 1
          }){
            o = "on"+p;
            
            f = ( o in c );
            
            if ( !f ){
              c.setAttribute( o,"return;" );
              
              f = ( typeof c[o] === "function" );
            };
            
            b[p+"Bubbles"] = f;
          };
        };
        
        m.removeChild( c );
        
        m = i = j = l = c = k = null;
        
        e( function () {
          var g,
              h,
              i,
              j,
              k,
              l,
              m,
              n,
              o,
              p,
              q,
              r = document.getElementsByTagName( "body" )[0];
          
          if ( !r ){
            return ;
          };
          
          m = 1;
          
          n = "position:absolute;top:0;left:0;width:1px;height:1px;margin:0;";
          
          o = "visibility:hidden;border:0;";
          
          p = "style='"+n+"border:5px solid #000;padding:0;'";
          
          q = "<div "+p+"><div></div></div>"+"<table "+p+" cellpadding='0' cellspacing='0'>"+"<tr><td></td></tr></table>";
          
          g = document.createElement( "div" );
          
          g.style.cssText = o+"width:0;height:0;position:static;top:0;margin-top:"+m+"px";
          
          r.insertBefore( g,r.firstChild );
          
          c = document.createElement( "div" );
          
          g.appendChild( c );
          
          c.innerHTML = "<table><tr><td style='padding:0;border:0;display:none'></td><td>t</td></tr></table>";
          
          d = c.getElementsByTagName( "td" );
          
          f = ( d[0].offsetHeight === 0 );
          
          d[0].style.display = "";
          
          d[1].style.display = "none";
          
          b.reliableHiddenOffsets = f && ( d[0].offsetHeight === 0 );
          
          c.innerHTML = "";
          
          c.style.width = c.style.paddingLeft = "1px";
          
          e.boxModel = b.boxModel = c.offsetWidth === 2;
          
          if ( typeof c.style.zoom !== "undefined" ){
            c.style.display = "inline";
            
            c.style.zoom = 1;
            
            b.inlineBlockNeedsLayout = ( c.offsetWidth === 2 );
            
            c.style.display = "";
            
            c.innerHTML = "<div style='width:4px;'></div>";
            
            b.shrinkWrapBlocks = ( c.offsetWidth !== 2 );
          };
          
          c.style.cssText = n+o;
          
          c.innerHTML = q;
          
          h = c.firstChild;
          
          i = h.firstChild;
          
          k = h.nextSibling.firstChild.firstChild;
          
          l =  {
            doesNotAddBorder : ( i.offsetTop !== 5 ),
            doesAddBorderForTableAndCells : ( k.offsetTop === 5 )
          };
          
          i.style.position = "fixed";
          
          i.style.top = "20px";
          
          l.fixedPosition = ( i.offsetTop === 20 || i.offsetTop === 15 );
          
          i.style.position = i.style.top = "";
          
          h.style.overflow = "hidden";
          
          h.style.position = "relative";
          
          l.subtractsBorderForOverflowNotVisible = ( i.offsetTop === -5 );
          
          l.doesNotIncludeMarginInBodyOffset = ( r.offsetTop !== m );
          
          r.removeChild( g );
          
          c = g = null;
          
          e.extend( b,l );
        });
        return b;
      }();
      
      var j = /^(?:\{.*\}|\[.*\])$/,
          i = /([A-Z])/g;
      
      e.extend(  {
        cache : {},
        uuid : 0,
        expando : "jQuery"+( e.fn.jquery+Math.random() ).replace( /\D/g,"" ),
        noData :  {
          "embed" : true,
          "object" : "clsid:D27CDB6E-AE6D-11cf-96B8-444553540000",
          "applet" : true
        },
        hasData : function ( h ) {
          h = h.nodeType?e.cache[h[e.expando]] : h[e.expando];
          return !!h && !g( h );
        },
        data : function ( a,b,c,d ) {
          if ( !e.acceptData( a ) ){
            return ;
          };
          
          var f,
              g,
              h,
              i = e.expando,
              j = typeof b === "string",
              k = a.nodeType,
              l = k?e.cache : a,
              m = k?a[i] : a[i] && i,
              n = b === "events";
          
          if ( ( !m || !l[m] || ( !n && !d && !l[m].data ) ) && j && c === undefined ){
            return ;
          };
          
          if ( !m ){
            if ( k ){
              a[i] = m =  ++ e.uuid;
            } else {
              m = i;
            };
          };
          
          if ( !l[m] ){
            l[m] = {};
            
            if ( !k ){
              l[m].toJSON = e.noop;
            };
          };
          
          if ( typeof b === "object" || typeof b === "function" ){
            if ( d ){
              l[m] = e.extend( l[m],b );
            } else {
              l[m].data = e.extend( l[m].data,b );
            };
          };
          
          f = g = l[m];
          
          if ( !d ){
            if ( !g.data ){
              g.data = {};
            };
            
            g = g.data;
          };
          
          if ( c !== undefined ){
            g[e.camelCase( b )] = c;
          };
          
          if ( n && !g[b] ){
            return f.events;
          };
          
          if ( j ){
            h = g[b];
            
            if ( h == null ){
              h = g[e.camelCase( b )];
            };
          } else {
            h = g;
          };
          return h;
        },
        removeData : function ( a,b,c ) {
          if ( !e.acceptData( a ) ){
            return ;
          };
          
          var d,
              f,
              h,
              i = e.expando,
              j = a.nodeType,
              k = j?e.cache : a,
              l = j?a[i] : i;
          
          if ( !k[l] ){
            return ;
          };
          
          if ( b ){
            d = c?k[l] : k[l].data;
            
            if ( d ){
              if ( !e.isArray( b ) ){
                if ( b in d ){
                  b = [b];
                } else {
                  b = e.camelCase( b );
                  if ( b in d ){
                    b = [b];
                  } else {
                    b = b.split( " " );
                  };
                };
              };
              
              for ( f = 0 , h = b.length;f<h;f ++  )delete d[b[f]];
              
              if ( !( c?g : e.isEmptyObject )( d ) ){
                return ;
              };
            };
          };
          
          if ( !c ){
            delete k[l].data;
            
            if ( !g( k[l] ) ){
              return ;
            };
          };
          
          if ( e.support.deleteExpando || !k.setInterval ){
            delete k[l];
          } else {
            k[l] = null;
          };
          
          if ( j ){
            if ( e.support.deleteExpando ){
              delete a[i];
            } else if ( a.removeAttribute ){
              a.removeAttribute( i );
            } else {
              a[i] = null;
            };
          };
        },
        _data : function ( a,b,c ) {
          return e.data( a,b,c,true );
        },
        acceptData : function ( a ) {
          if ( a.nodeName ){
            var b = e.noData[a.nodeName.toLowerCase()];
            
            if ( b ){
              return !( b === true || a.getAttribute( "classid" ) !== b );
            };
          };
          return true;
        }
      });
      
      e.fn.extend(  {
        data : function ( a,c ) {
          var b,
              i,
              j,
              k = null;
          
          if ( typeof a === "undefined" ){
            if ( this.length ){
              k = e.data( this[0] );
              
              if ( this[0].nodeType === 1 && !e._data( this[0],"parsedAttrs" ) ){
                i = this[0].attributes;
                
                for ( var l = 0,m = i.length;l<m;l ++  ){
                  j = i[l].name;
                  
                  if ( j.indexOf( "data-" ) === 0 ){
                    j = e.camelCase( j.substring( 5 ) );
                    
                    h( this[0],j,k[j] );
                  };
                };
                
                e._data( this[0],"parsedAttrs",true );
              };
            };
            return k;
          } else if ( typeof a === "object" ){
            return this.each( function () {
              e.data( this,a );
            });
          };
          
          b = a.split( "." );
          
          b[1] = b[1]?"."+b[1] : "";
          
          if ( c === undefined ){
            k = this.triggerHandler( "getData"+b[1]+"!",[b[0]] );
            
            if ( k === undefined && this.length ){
              k = e.data( this[0],a );
              
              k = h( this[0],a,k );
            };
            return k === undefined && b[1]?this.data( b[0] ) : k;
          } else {
            return this.each( function () {
              var self = e( this ),
                  d = [b[0],c];
              
              self.triggerHandler( "setData"+b[1]+"!",d );
              
              e.data( this,a,c );
              
              self.triggerHandler( "changeData"+b[1]+"!",d );
            });
          };
        },
        removeData : function ( a ) {
          return this.each( function () {
            e.removeData( this,a );
          });
        }
      });
      
      function h( k,l,m ) {
        if ( m === undefined && k.nodeType === 1 ){
          var n = "data-"+l.replace( i,"-$1" ).toLowerCase();
          
          m = k.getAttribute( n );
          
          if ( typeof m === "string" ){
            try {
              m = m === "true"?true : m === "false"?false : m === "null"?null : e.isNumeric( m )?parseFloat( m ) : j.test( m )?e.parseJSON( m ) : m;
            } catch( e ){
              
            };
            
            e.data( k,l,m );
          } else {
            m = undefined;
          };
        };
        return m;
      }
      function g( a ) {
        for ( var b in a ){
          if ( b === "data" && e.isEmptyObject( a[b] ) ){
            continue ;
          };
          
          if ( b !== "toJSON" ){
            return false;
          };
        };
        return true;
      }
      function k( a,g,h ) {
        var d = g+"defer",
            b = g+"queue",
            c = g+"mark",
            f = e._data( a,d );
        
        if ( f && ( h === "queue" || !e._data( a,b ) ) && ( h === "mark" || !e._data( a,c ) ) ){
          setTimeout( function () {
            if ( !e._data( a,b ) && !e._data( a,c ) ){
              e.removeData( a,d,true );
              
              f.fire();
            };
          },0);
        };
      }
      e.extend(  {
        _mark : function ( a,b ) {
          if ( a ){
            b = ( b || "fx" )+"mark";
            
            e._data( a,b,( e._data( a,b ) || 0 )+1 );
          };
        },
        _unmark : function ( l,m,n ) {
          if ( l !== true ){
            n = m;
            
            m = l;
            
            l = false;
          };
          
          if ( m ){
            n = n || "fx";
            
            var o = n+"mark",
                p = l?0 : ( ( e._data( m,o ) || 1 )-1 );
            
            if ( p ){
              e._data( m,o,p );
            } else {
              e.removeData( m,o,true );
              
              k( m,n,"mark" );
            };
          };
        },
        queue : function ( a,b,c ) {
          var d;
          
          if ( a ){
            b = ( b || "fx" )+"queue";
            
            d = e._data( a,b );
            
            if ( c ){
              if ( !d || e.isArray( c ) ){
                d = e._data( a,b,e.makeArray( c ) );
              } else {
                d.push( c );
              };
            };
            return d || [];
          };
        },
        dequeue : function ( a,b ) {
          b = b || "fx";
          
          var c = e.queue( a,b ),
              d = c.shift(),
              f = {};
          
          if ( d === "inprogress" ){
            d = c.shift();
          };
          
          if ( d ){
            if ( b === "fx" ){
              c.unshift( "inprogress" );
            };
            
            e._data( a,b+".run",f );
            
            d.call( a,
            function () {
              e.dequeue( a,b );
            },f);
          };
          
          if ( !c.length ){
            e.removeData( a,b+"queue "+b+".run",true );
            
            k( a,b,"queue" );
          };
        }
      });
      
      e.fn.extend(  {
        queue : function ( a,b ) {
          if ( typeof a !== "string" ){
            b = a;
            
            a = "fx";
          };
          
          if ( b === undefined ){
            return e.queue( this[0],a );
          };
          return this.each( function () {
            var c = e.queue( this,a,b );
            
            if ( a === "fx" && c[0] !== "inprogress" ){
              e.dequeue( this,a );
            };
          });
        },
        dequeue : function ( a ) {
          return this.each( function () {
            e.dequeue( this,a );
          });
        },
        delay : function ( a,b ) {
          a = e.fx?e.fx.speeds[a] || a : a;
          
          b = b || "fx";
          return this.queue( b,
          function ( c,d ) {
            var b = setTimeout( c,a );
            
            d.stop = function () {
              clearTimeout( b );
            };
          });
        },
        clearQueue : function ( a ) {
          return this.queue( a || "fx",[] );
        },
        promise : function ( d,f ) {
          if ( typeof d !== "string" ){
            f = d;
            
            d = undefined;
          };
          
          d = d || "fx";
          
          var b = e.Deferred(),
              c = this,
              g = c.length,
              a = 1,
              h = d+"defer",
              i = d+"queue",
              j = d+"mark",
              k;
          
          function l() {
            if ( !(  -- a ) ){
              b.resolveWith( c,[c] );
            };
          }
          while ( g --  )if ( ( k = e.data( c[g],h,undefined,true ) || ( e.data( c[g],i,undefined,true ) || e.data( c[g],j,undefined,true ) ) && e.data( c[g],h,e.Callbacks( "once memory" ),true ) ) ){
            a ++ ;
            
            k.add( l );
          };
          
          l();
          return b.promise();
        }
      });
      
      var m = /[\n\t\r]/g,
          l = /\s+/,
          n = /\r/g,
          s = /^(?:button|input)$/i,
          t = /^(?:button|input|object|select|textarea)$/i,
          u = /^a(?:rea)?$/i,
          o = /^(?:autofocus|autoplay|async|checked|controls|defer|disabled|hidden|loop|multiple|open|readonly|required|scoped|selected)$/i,
          r = e.support.getSetAttribute,
          q,
          p,
          v;
      
      e.fn.extend(  {
        attr : function ( a,b ) {
          return e.access( this,a,b,true,e.attr );
        },
        removeAttr : function ( a ) {
          return this.each( function () {
            e.removeAttr( this,a );
          });
        },
        prop : function ( a,b ) {
          return e.access( this,a,b,true,e.prop );
        },
        removeProp : function ( a ) {
          a = e.propFix[a] || a;
          return this.each( function () {
            try {
              this[a] = undefined;
              
              delete this[a];
            } catch( e ){
              
            };
          });
        },
        addClass : function ( a ) {
          var m,
              n,
              o,
              p,
              q,
              r,
              s;
          
          if ( e.isFunction( a ) ){
            return this.each( function ( b ) {
              e( this ).addClass( a.call( this,b,this.className ) );
            });
          };
          
          if ( a && typeof a === "string" ){
            m = a.split( l );
            
            for ( n = 0 , o = this.length;n<o;n ++  ){
              p = this[n];
              
              if ( p.nodeType === 1 ){
                if ( !p.className && m.length === 1 ){
                  p.className = a;
                } else {
                  q = " "+p.className+" ";
                  
                  for ( r = 0 , s = m.length;r<s;r ++  )if ( !~q.indexOf( " "+m[r]+" " ) ){
                    q += m[r]+" ";
                  };
                  
                  p.className = e.trim( q );
                };
              };
            };
          };
          return this;
        },
        removeClass : function ( a ) {
          var n,
              o,
              p,
              q,
              r,
              s,
              t;
          
          if ( e.isFunction( a ) ){
            return this.each( function ( b ) {
              e( this ).removeClass( a.call( this,b,this.className ) );
            });
          };
          
          if ( ( a && typeof a === "string" ) || a === undefined ){
            n = ( a || "" ).split( l );
            
            for ( o = 0 , p = this.length;o<p;o ++  ){
              q = this[o];
              
              if ( q.nodeType === 1 && q.className ){
                if ( a ){
                  r = ( " "+q.className+" " ).replace( m," " );
                  
                  for ( s = 0 , t = n.length;s<t;s ++  )r = r.replace( " "+n[s]+" "," " );
                  
                  q.className = e.trim( r );
                } else {
                  q.className = "";
                };
              };
            };
          };
          return this;
        },
        toggleClass : function ( a,b ) {
          var c = typeof a,
              d = typeof b === "boolean";
          
          if ( e.isFunction( a ) ){
            return this.each( function ( c ) {
              e( this ).toggleClass( a.call( this,c,this.className,b ),b );
            });
          };
          return this.each( function () {
            if ( c === "string" ){
              var f,
                  g = 0,
                  self = e( this ),
                  h = b,
                  i = a.split( l );
              
              while ( ( f = i[g ++ ] ) ){
                h = d?h : !self.hasClass( f );
                
                self[h?"addClass" : "removeClass"]( f );
              };
            } else if ( c === "undefined" || c === "boolean" ){
              if ( this.className ){
                e._data( this,"__className__",this.className );
              };
              
              this.className = this.className || a === false?"" : e._data( this,"__className__" ) || "";
            };
          });
        },
        hasClass : function ( a ) {
          var b = " "+a+" ",
              c = 0,
              d = this.length;
          
          for ( ;c<d;c ++  )if ( this[c].nodeType === 1 && ( " "+this[c].className+" " ).replace( m," " ).indexOf( b )>-1 ){
            return true;
          };
          return false;
        },
        val : function ( b ) {
          var c,
              o,
              a,
              p = this[0];
          
          if ( !arguments.length ){
            if ( p ){
              c = e.valHooks[p.nodeName.toLowerCase()] || e.valHooks[p.type];
              
              if ( c && "get" in c && ( o = c.get( p,"value" ) ) !== undefined ){
                return o;
              };
              
              o = p.value;
              return typeof o === "string"?o.replace( n,"" ) : o == null?"" : o;
            };
            return ;
          };
          
          a = e.isFunction( b );
          return this.each( function ( d ) {
            var self = e( this ),
                f;
            
            if ( this.nodeType !== 1 ){
              return ;
            };
            
            if ( a ){
              f = b.call( this,d,self.val() );
            } else {
              f = b;
            };
            
            if ( f == null ){
              f = "";
            } else if ( typeof f === "number" ){
              f += "";
            } else if ( e.isArray( f ) ){
              f = e.map( f,
              function ( a ) {
                return a == null?"" : a+"";
              });
            };
            
            c = e.valHooks[this.nodeName.toLowerCase()] || e.valHooks[this.type];
            
            if ( !c || !( "set" in c ) || c.set( this,f,"value" ) === undefined ){
              this.value = f;
            };
          });
        }
      });
      
      e.extend(  {
        valHooks :  {
          option :  {
            get : function ( a ) {
              var b = a.attributes.value;
              return !b || b.specified?a.value : a.text;
            }
          },
          select :  {
            get : function ( a ) {
              var b,
                  c,
                  d,
                  f,
                  g = a.selectedIndex,
                  h = [],
                  i = a.options,
                  j = a.type === "select-one";
              
              if ( g<0 ){
                return null;
              };
              
              c = j?g : 0;
              
              d = j?g+1 : i.length;
              
              for ( ;c<d;c ++  ){
                f = i[c];
                
                if ( f.selected && ( e.support.optDisabled?!f.disabled : f.getAttribute( "disabled" ) === null ) && ( !f.parentNode.disabled || !e.nodeName( f.parentNode,"optgroup" ) ) ){
                  b = e( f ).val();
                  
                  if ( j ){
                    return b;
                  };
                  
                  h.push( b );
                };
              };
              
              if ( j && !h.length && i.length ){
                return e( i[g] ).val();
              };
              return h;
            },
            set : function ( b,c ) {
              var a = e.makeArray( c );
              
              e( b ).find( "option" ).each( function () {
                this.selected = e.inArray( e( this ).val(),a ) >= 0;
              });
              
              if ( !a.length ){
                b.selectedIndex = -1;
              };
              return a;
            }
          }
        },
        attrFn :  {
          val : true,
          css : true,
          html : true,
          text : true,
          data : true,
          width : true,
          height : true,
          offset : true
        },
        attr : function ( r,s,t,u ) {
          var v,
              w,
              x,
              y = r.nodeType;
          
          if ( !r || y === 3 || y === 8 || y === 2 ){
            return ;
          };
          
          if ( u && s in e.attrFn ){
            return e( r )[s]( t );
          };
          
          if ( typeof r.getAttribute === "undefined" ){
            return e.prop( r,s,t );
          };
          
          x = y !== 1 || !e.isXMLDoc( r );
          
          if ( x ){
            s = s.toLowerCase();
            
            w = e.attrHooks[s] || ( o.test( s )?p : q );
          };
          
          if ( t !== undefined ){
            if ( t === null ){
              e.removeAttr( r,s );
              return ;
            } else if ( w && "set" in w && x && ( v = w.set( r,t,s ) ) !== undefined ){
              return v;
            } else {
              r.setAttribute( s,""+t );
              return t;
            };
          } else if ( w && "get" in w && x && ( v = w.get( r,s ) ) !== null ){
            return v;
          } else {
            v = r.getAttribute( s );
            return v === null?undefined : v;
          };
        },
        removeAttr : function ( s,t ) {
          var u,
              v,
              w,
              x,
              y = 0;
          
          if ( t && s.nodeType === 1 ){
            v = t.toLowerCase().split( l );
            
            x = v.length;
            
            for ( ;y<x;y ++  ){
              w = v[y];
              
              if ( w ){
                u = e.propFix[w] || w;
                
                e.attr( s,w,"" );
                
                s.removeAttribute( r?w : u );
                
                if ( o.test( w ) && u in s ){
                  s[u] = false;
                };
              };
            };
          };
        },
        attrHooks :  {
          type :  {
            set : function ( t,u ) {
              if ( s.test( t.nodeName ) && t.parentNode ){
                e.error( "type property can't be changed" );
              } else if ( !e.support.radioValue && u === "radio" && e.nodeName( t,"input" ) ){
                var v = t.value;
                
                t.setAttribute( "type",u );
                if ( v ){
                  t.value = v;
                };
                return u;
              };
            }
          },
          value :  {
            get : function ( a,b ) {
              if ( q && e.nodeName( a,"button" ) ){
                return q.get( a,b );
              };
              return b in a?a.value : null;
            },
            set : function ( a,b,c ) {
              if ( q && e.nodeName( a,"button" ) ){
                return q.set( a,b,c );
              };
              
              a.value = b;
            }
          }
        },
        propFix :  {
          tabindex : "tabIndex",
          readonly : "readOnly",
          "for" : "htmlFor",
          "class" : "className",
          maxlength : "maxLength",
          cellspacing : "cellSpacing",
          cellpadding : "cellPadding",
          rowspan : "rowSpan",
          colspan : "colSpan",
          usemap : "useMap",
          frameborder : "frameBorder",
          contenteditable : "contentEditable"
        },
        prop : function ( a,b,c ) {
          var d,
              f,
              g,
              h = a.nodeType;
          
          if ( !a || h === 3 || h === 8 || h === 2 ){
            return ;
          };
          
          g = h !== 1 || !e.isXMLDoc( a );
          
          if ( g ){
            b = e.propFix[b] || b;
            
            f = e.propHooks[b];
          };
          
          if ( c !== undefined ){
            if ( f && "set" in f && ( d = f.set( a,c,b ) ) !== undefined ){
              return d;
            } else {
              return ( a[b] = c );
            };
          } else if ( f && "get" in f && ( d = f.get( a,b ) ) !== null ){
            return d;
          } else {
            return a[b];
          };
        },
        propHooks :  {
          tabIndex :  {
            get : function ( v ) {
              var w = v.getAttributeNode( "tabindex" );
              return w && w.specified?parseInt( w.value,10 ) : t.test( v.nodeName ) || u.test( v.nodeName ) && v.href?0 : undefined;
            }
          }
        }
      });
      
      e.attrHooks.tabindex = e.propHooks.tabIndex;
      
      p =  {
        get : function ( a,b ) {
          var c,
              d = e.prop( a,b );
          return d === true || typeof d !== "boolean" && ( c = a.getAttributeNode( b ) ) && c.nodeValue !== false?b.toLowerCase() : undefined;
        },
        set : function ( a,b,c ) {
          var d;
          
          if ( b === false ){
            e.removeAttr( a,c );
          } else {
            d = e.propFix[c] || c;
            if ( d in a ){
              a[d] = true;
            };
            
            a.setAttribute( c,c.toLowerCase() );
          };
          return c;
        }
      };
      
      if ( !r ){
        v =  {
          name : true,
          id : true
        };
        
        q = e.valHooks.button =  {
          get : function ( w,x ) {
            var y;
            
            y = w.getAttributeNode( x );
            return y && ( v[x]?y.nodeValue !== "" : y.specified )?y.nodeValue : undefined;
          },
          set : function ( a,b,c ) {
            var d = a.getAttributeNode( c );
            
            if ( !d ){
              d = document.createAttribute( c );
              
              a.setAttributeNode( d );
            };
            return ( d.nodeValue = b+"" );
          }
        };
        
        e.attrHooks.tabindex.set = q.set;
        
        e.each( ["width","height"],
        function ( b,a ) {
          e.attrHooks[a] = e.extend( e.attrHooks[a], {
            set : function ( b,c ) {
              if ( c === "" ){
                b.setAttribute( a,"auto" );
                return c;
              };
            }
          });
        });
        
        e.attrHooks.contenteditable =  {
          get : q.get,
          set : function ( a,b,c ) {
            if ( b === "" ){
              b = "false";
            };
            
            q.set( a,b,c );
          }
        };
      };
      
      if ( !e.support.hrefNormalized ){
        e.each( ["href","src","width","height"],
        function ( b,a ) {
          e.attrHooks[a] = e.extend( e.attrHooks[a], {
            get : function ( b ) {
              var c = b.getAttribute( a,2 );
              return c === null?undefined : c;
            }
          });
        });
      };
      
      if ( !e.support.style ){
        e.attrHooks.style =  {
          get : function ( a ) {
            return a.style.cssText.toLowerCase() || undefined;
          },
          set : function ( a,b ) {
            return ( a.style.cssText = ""+b );
          }
        };
      };
      
      if ( !e.support.optSelected ){
        e.propHooks.selected = e.extend( e.propHooks.selected, {
          get : function ( a ) {
            var b = a.parentNode;
            
            if ( b ){
              b.selectedIndex;
              
              if ( b.parentNode ){
                b.parentNode.selectedIndex;
              };
            };
            return null;
          }
        });
      };
      
      if ( !e.support.enctype ){
        e.propFix.enctype = "encoding";
      };
      
      if ( !e.support.checkOn ){
        e.each( ["radio","checkbox"],
        function () {
          e.valHooks[this] =  {
            get : function ( a ) {
              return a.getAttribute( "value" ) === null?"on" : a.value;
            }
          };
        });
      };
      
      e.each( ["radio","checkbox"],
      function () {
        e.valHooks[this] = e.extend( e.valHooks[this], {
          set : function ( a,b ) {
            if ( e.isArray( b ) ){
              return ( a.checked = e.inArray( e( a ).val(),b ) >= 0 );
            };
          }
        });
      });
      
      var F = /^(?:textarea|input|select)$/i,
          z = /^([^\.]*)?(?:\.(.+))?$/,
          x = /\bhover(\.\S+)?\b/,
          G = /^key/,
          H = /^(?:mouse|contextmenu)|click/,
          B = /^(?:focusinfocus|focusoutblur)$/,
          w = /^(\w*)(?:#([\w\-]+))?(?:\.([\w\-]+))?$/,
          A = function ( x ) {
            var y = w.exec( x );
            
            if ( y ){
              y[1] = ( y[1] || "" ).toLowerCase();
              
              y[3] = y[3] && new RegExp( "(?:^|\\s)"+y[3]+"(?:\\s|$)" );
            };
            return y;
          },
          C = function ( a,b ) {
            var c = a.attributes || {};
            return ( ( !b[1] || a.nodeName.toLowerCase() === b[1] ) && ( !b[2] || ( c.id || {} ).value === b[2] ) && ( !b[3] || b[3].test( ( c["class"] || {} ).value ) ) );
          },
          y = function ( y ) {
            return e.event.special.hover?y : y.replace( x,"mouseenter$1 mouseleave$1" );
          };
      
      e.event =  {
        add : function ( B,C,D,E,F ) {
          var G,
              a,
              H,
              I,
              J,
              K,
              L,
              M,
              N,
              O,
              P,
              Q;
          
          if ( B.nodeType === 3 || B.nodeType === 8 || !C || !D || !( G = e._data( B ) ) ){
            return ;
          };
          
          if ( D.handler ){
            N = D;
            
            D = N.handler;
          };
          
          if ( !D.guid ){
            D.guid = e.guid ++ ;
          };
          
          H = G.events;
          
          if ( !H ){
            G.events = H = {};
          };
          
          a = G.handle;
          
          if ( !a ){
            G.handle = a = function ( b ) {
              return typeof e !== "undefined" && ( !b || e.event.triggered !== b.type )?e.event.dispatch.apply( a.elem,arguments ) : undefined;
            };
            
            a.elem = B;
          };
          
          C = e.trim( y( C ) ).split( " " );
          
          for ( I = 0;I<C.length;I ++  ){
            J = z.exec( C[I] ) || [];
            
            K = J[1];
            
            L = ( J[2] || "" ).split( "." ).sort();
            
            Q = e.event.special[K] || {};
            
            K = ( F?Q.delegateType : Q.bindType ) || K;
            
            Q = e.event.special[K] || {};
            
            M = e.extend(  {
              type : K,
              origType : J[1],
              data : E,
              handler : D,
              guid : D.guid,
              selector : F,
              quick : A( F ),
              namespace : L.join( "." )
            },N);
            
            P = H[K];
            
            if ( !P ){
              P = H[K] = [];
              
              P.delegateCount = 0;
              
              if ( !Q.setup || Q.setup.call( B,E,L,a ) === false ){
                if ( B.addEventListener ){
                  B.addEventListener( K,a,false );
                } else if ( B.attachEvent ){
                  B.attachEvent( "on"+K,a );
                };
              };
            };
            
            if ( Q.add ){
              Q.add.call( B,M );
              
              if ( !M.handler.guid ){
                M.handler.guid = D.guid;
              };
            };
            
            if ( F ){
              P.splice( P.delegateCount ++ ,0,M );
            } else {
              P.push( M );
            };
            
            e.event.global[K] = true;
          };
          
          B = null;
        },
        global : {},
        remove : function ( a,b,c,d,f ) {
          var g = e.hasData( a ) && e._data( a ),
              h,
              i,
              j,
              k,
              l,
              m,
              n,
              o,
              p,
              q,
              r,
              s;
          
          if ( !g || !( o = g.events ) ){
            return ;
          };
          
          b = e.trim( y( b || "" ) ).split( " " );
          
          for ( h = 0;h<b.length;h ++  ){
            i = z.exec( b[h] ) || [];
            
            j = k = i[1];
            
            l = i[2];
            
            if ( !j ){
              for ( j in o )e.event.remove( a,j+b[h],c,d,true );
              continue ;
            };
            
            p = e.event.special[j] || {};
            
            j = ( d?p.delegateType : p.bindType ) || j;
            
            r = o[j] || [];
            
            m = r.length;
            
            l = l?new RegExp( "(^|\\.)"+l.split( "." ).sort().join( "\\.(?:.*\\.)?" )+"(\\.|$)" ) : null;
            
            for ( n = 0;n<r.length;n ++  ){
              s = r[n];
              
              if ( ( f || k === s.origType ) && ( !c || c.guid === s.guid ) && ( !l || l.test( s.namespace ) ) && ( !d || d === s.selector || d === "**" && s.selector ) ){
                r.splice( n -- ,1 );
                
                if ( s.selector ){
                  r.delegateCount -- ;
                };
                
                if ( p.remove ){
                  p.remove.call( a,s );
                };
              };
            };
            
            if ( r.length === 0 && m !== r.length ){
              if ( !p.teardown || p.teardown.call( a,l ) === false ){
                e.removeEvent( a,j,g.handle );
              };
              
              delete o[j];
            };
          };
          
          if ( e.isEmptyObject( o ) ){
            q = g.handle;
            
            if ( q ){
              q.elem = null;
            };
            
            e.removeData( a,["events","handle"],true );
          };
        },
        customEvent :  {
          "getData" : true,
          "setData" : true,
          "changeData" : true
        },
        trigger : function ( C,D,E,F ) {
          if ( E && ( E.nodeType === 3 || E.nodeType === 8 ) ){
            return ;
          };
          
          var G = C.type || C,
              H = [],
              I,
              J,
              K,
              L,
              M,
              N,
              O,
              P,
              Q,
              R;
          
          if ( B.test( G+e.event.triggered ) ){
            return ;
          };
          
          if ( G.indexOf( "!" ) >= 0 ){
            G = G.slice( 0,-1 );
            
            J = true;
          };
          
          if ( G.indexOf( "." ) >= 0 ){
            H = G.split( "." );
            
            G = H.shift();
            
            H.sort();
          };
          
          if ( ( !E || e.event.customEvent[G] ) && !e.event.global[G] ){
            return ;
          };
          
          C = typeof C === "object"?C[e.expando]?C : new e.Event( G,C ) : new e.Event( G );
          
          C.type = G;
          
          C.isTrigger = true;
          
          C.exclusive = J;
          
          C.namespace = H.join( "." );
          
          C.namespace_re = C.namespace?new RegExp( "(^|\\.)"+H.join( "\\.(?:.*\\.)?" )+"(\\.|$)" ) : null;
          
          N = G.indexOf( ":" )<0?"on"+G : "";
          
          if ( !E ){
            I = e.cache;
            
            for ( K in I )if ( I[K].events && I[K].events[G] ){
              e.event.trigger( C,D,I[K].handle.elem,true );
            };
            return ;
          };
          
          C.result = undefined;
          
          if ( !C.target ){
            C.target = E;
          };
          
          D = D != null?e.makeArray( D ) : [];
          
          D.unshift( C );
          
          O = e.event.special[G] || {};
          
          if ( O.trigger && O.trigger.apply( E,D ) === false ){
            return ;
          };
          
          Q = [[E,O.bindType || G]];
          
          if ( !F && !O.noBubble && !e.isWindow( E ) ){
            R = O.delegateType || G;
            
            L = B.test( R+G )?E : E.parentNode;
            
            M = null;
            
            for ( ;L;L = L.parentNode ){
              Q.push( [L,R] );
              
              M = L;
            };
            
            if ( M && M === E.ownerDocument ){
              Q.push( [M.defaultView || M.parentWindow || a,R] );
            };
          };
          
          for ( K = 0;K<Q.length && !C.isPropagationStopped();K ++  ){
            L = Q[K][0];
            
            C.type = Q[K][1];
            
            P = ( e._data( L,"events" ) || {} )[C.type] && e._data( L,"handle" );
            
            if ( P ){
              P.apply( L,D );
            };
            
            P = N && L[N];
            
            if ( P && e.acceptData( L ) && P.apply( L,D ) === false ){
              C.preventDefault();
            };
          };
          
          C.type = G;
          
          if ( !F && !C.isDefaultPrevented() ){
            if ( ( !O._default || O._default.apply( E.ownerDocument,D ) === false ) && !( G === "click" && e.nodeName( E,"a" ) ) && e.acceptData( E ) ){
              if ( N && E[G] && ( ( G !== "focus" && G !== "blur" ) || C.target.offsetWidth !== 0 ) && !e.isWindow( E ) ){
                M = E[N];
                
                if ( M ){
                  E[N] = null;
                };
                
                e.event.triggered = G;
                
                E[G]();
                
                e.event.triggered = undefined;
                
                if ( M ){
                  E[N] = M;
                };
              };
            };
          };
          return C.result;
        },
        dispatch : function ( D ) {
          D = e.event.fix( D || a.event );
          
          var E = ( ( e._data( this,"events" ) || {} )[D.type] || [] ),
              F = E.delegateCount,
              G = [].slice.call( arguments,0 ),
              H = !D.exclusive && !D.namespace,
              I = [],
              J,
              K,
              L,
              M,
              N,
              O,
              P,
              Q,
              R,
              S,
              T;
          
          G[0] = D;
          
          D.delegateTarget = this;
          
          if ( F && !D.target.disabled && !( D.button && D.type === "click" ) ){
            M = e( this );
            
            M.context = this.ownerDocument || this;
            
            for ( L = D.target;L != this;L = L.parentNode || this ){
              O = {};
              
              Q = [];
              
              M[0] = L;
              
              for ( J = 0;J<F;J ++  ){
                R = E[J];
                
                S = R.selector;
                
                if ( O[S] === undefined ){
                  O[S] = ( R.quick?C( L,R.quick ) : M.is( S ) );
                };
                
                if ( O[S] ){
                  Q.push( R );
                };
              };
              
              if ( Q.length ){
                I.push(  {
                  elem : L,
                  matches : Q
                });
              };
            };
          };
          
          if ( E.length>F ){
            I.push(  {
              elem : this,
              matches : E.slice( F )
            });
          };
          
          for ( J = 0;J<I.length && !D.isPropagationStopped();J ++  ){
            P = I[J];
            
            D.currentTarget = P.elem;
            
            for ( K = 0;K<P.matches.length && !D.isImmediatePropagationStopped();K ++  ){
              R = P.matches[K];
              
              if ( H || ( !D.namespace && !R.namespace ) || D.namespace_re && D.namespace_re.test( R.namespace ) ){
                D.data = R.data;
                
                D.handleObj = R;
                
                N = ( ( e.event.special[R.origType] || {} ).handle || R.handler ).apply( P.elem,G );
                
                if ( N !== undefined ){
                  D.result = N;
                  
                  if ( N === false ){
                    D.preventDefault();
                    
                    D.stopPropagation();
                  };
                };
              };
            };
          };
          return D.result;
        },
        props : "attrChange attrName relatedNode srcElement altKey bubbles cancelable ctrlKey currentTarget eventPhase metaKey relatedTarget shiftKey target timeStamp view which".split( " " ),
        fixHooks : {},
        keyHooks :  {
          props : "char charCode key keyCode".split( " " ),
          filter : function ( a,b ) {
            if ( a.which == null ){
              a.which = b.charCode != null?b.charCode : b.keyCode;
            };
            return a;
          }
        },
        mouseHooks :  {
          props : "button buttons clientX clientY fromElement offsetX offsetY pageX pageY screenX screenY toElement".split( " " ),
          filter : function ( a,b ) {
            var c,
                d,
                e,
                f = b.button,
                g = b.fromElement;
            
            if ( a.pageX == null && b.clientX != null ){
              c = a.target.ownerDocument || document;
              
              d = c.documentElement;
              
              e = c.body;
              
              a.pageX = b.clientX+( d && d.scrollLeft || e && e.scrollLeft || 0 )-( d && d.clientLeft || e && e.clientLeft || 0 );
              
              a.pageY = b.clientY+( d && d.scrollTop || e && e.scrollTop || 0 )-( d && d.clientTop || e && e.clientTop || 0 );
            };
            
            if ( !a.relatedTarget && g ){
              a.relatedTarget = g === a.target?b.toElement : g;
            };
            
            if ( !a.which && f !== undefined ){
              a.which = ( f&1?1 : ( f&2?3 : ( f&4?2 : 0 ) ) );
            };
            return a;
          }
        },
        fix : function ( a ) {
          if ( a[e.expando] ){
            return a;
          };
          
          var b,
              c,
              d = a,
              f = e.event.fixHooks[a.type] || {},
              g = f.props?this.props.concat( f.props ) : this.props;
          
          a = e.Event( d );
          
          for ( b = g.length;b; ){
            c = g[ -- b];
            
            a[c] = d[c];
          };
          
          if ( !a.target ){
            a.target = d.srcElement || document;
          };
          
          if ( a.target.nodeType === 3 ){
            a.target = a.target.parentNode;
          };
          
          if ( a.metaKey === undefined ){
            a.metaKey = a.ctrlKey;
          };
          return f.filter?f.filter( a,d ) : a;
        },
        special :  {
          ready :  {
            setup : e.bindReady
          },
          load :  {
            noBubble : true
          },
          focus :  {
            delegateType : "focusin"
          },
          blur :  {
            delegateType : "focusout"
          },
          beforeunload :  {
            setup : function ( a,b,c ) {
              if ( e.isWindow( this ) ){
                this.onbeforeunload = c;
              };
            },
            teardown : function ( a,b ) {
              if ( this.onbeforeunload === b ){
                this.onbeforeunload = null;
              };
            }
          }
        },
        simulate : function ( a,b,c,d ) {
          var f = e.extend( new e.Event(),c, {
                type : a,
                isSimulated : true,
                originalEvent : {}
              });
          
          if ( d ){
            e.event.trigger( f,null,b );
          } else {
            e.event.dispatch.call( b,f );
          };
          
          if ( f.isDefaultPrevented() ){
            c.preventDefault();
          };
        }
      };
      
      e.event.handle = e.event.dispatch;
      
      e.removeEvent = document.removeEventListener?function ( a,b,c ) {
        if ( a.removeEventListener ){
          a.removeEventListener( b,c,false );
        };
      } : function ( a,b,c ) {
        if ( a.detachEvent ){
          a.detachEvent( "on"+b,c );
        };
      };
      
      e.Event = function ( F,G ) {
        if ( !( this instanceof e.Event ) ){
          return new e.Event( F,G );
        };
        
        if ( F && F.type ){
          this.originalEvent = F;
          
          this.type = F.type;
          
          this.isDefaultPrevented = ( F.defaultPrevented || F.returnValue === false || F.getPreventDefault && F.getPreventDefault() )?D : E;
        } else {
          this.type = F;
        };
        
        if ( G ){
          e.extend( this,G );
        };
        
        this.timeStamp = F && F.timeStamp || e.now();
        
        this[e.expando] = true;
      };
      
      function E() {
        return false;
      }
      function D() {
        return true;
      }
      e.Event.prototype =  {
        preventDefault : function () {
          this.isDefaultPrevented = D;
          
          var a = this.originalEvent;
          
          if ( !a ){
            return ;
          };
          
          if ( a.preventDefault ){
            a.preventDefault();
          } else {
            a.returnValue = false;
          };
        },
        stopPropagation : function () {
          this.isPropagationStopped = D;
          
          var a = this.originalEvent;
          
          if ( !a ){
            return ;
          };
          
          if ( a.stopPropagation ){
            a.stopPropagation();
          };
          
          a.cancelBubble = true;
        },
        stopImmediatePropagation : function () {
          this.isImmediatePropagationStopped = D;
          
          this.stopPropagation();
        },
        isDefaultPrevented : E,
        isPropagationStopped : E,
        isImmediatePropagationStopped : E
      };
      
      e.each(  {
        mouseenter : "mouseover",
        mouseleave : "mouseout"
      },
      function ( b,a ) {
        e.event.special[b] =  {
          delegateType : a,
          bindType : a,
          handle : function ( b ) {
            var c = this,
                d = b.relatedTarget,
                f = b.handleObj,
                g = f.selector,
                h;
            
            if ( !d || ( d !== c && !e.contains( c,d ) ) ){
              b.type = f.origType;
              
              h = f.handler.apply( this,arguments );
              
              b.type = a;
            };
            return h;
          }
        };
      });
      
      if ( !e.support.submitBubbles ){
        e.event.special.submit =  {
          setup : function () {
            if ( e.nodeName( this,"form" ) ){
              return false;
            };
            
            e.event.add( this,"click._submit keypress._submit",
            function ( a ) {
              var b = a.target,
                  c = e.nodeName( b,"input" ) || e.nodeName( b,"button" )?b.form : undefined;
              
              if ( c && !c._submit_attached ){
                e.event.add( c,"submit._submit",
                function ( a ) {
                  if ( this.parentNode && !a.isTrigger ){
                    e.event.simulate( "submit",this.parentNode,a,true );
                  };
                });
                
                c._submit_attached = true;
              };
            });
          },
          teardown : function () {
            if ( e.nodeName( this,"form" ) ){
              return false;
            };
            
            e.event.remove( this,"._submit" );
          }
        };
      };
      
      if ( !e.support.changeBubbles ){
        e.event.special.change =  {
          setup : function () {
            if ( F.test( this.nodeName ) ){
              if ( this.type === "checkbox" || this.type === "radio" ){
                e.event.add( this,"propertychange._change",
                function ( a ) {
                  if ( a.originalEvent.propertyName === "checked" ){
                    this._just_changed = true;
                  };
                });
                
                e.event.add( this,"click._change",
                function ( a ) {
                  if ( this._just_changed && !a.isTrigger ){
                    this._just_changed = false;
                    
                    e.event.simulate( "change",this,a,true );
                  };
                });
              };
              return false;
            };
            
            e.event.add( this,"beforeactivate._change",
            function ( a ) {
              var b = a.target;
              
              if ( F.test( b.nodeName ) && !b._change_attached ){
                e.event.add( b,"change._change",
                function ( a ) {
                  if ( this.parentNode && !a.isSimulated && !a.isTrigger ){
                    e.event.simulate( "change",this.parentNode,a,true );
                  };
                });
                
                b._change_attached = true;
              };
            });
          },
          handle : function ( a ) {
            var b = a.target;
            
            if ( this !== b || a.isSimulated || a.isTrigger || ( b.type !== "radio" && b.type !== "checkbox" ) ){
              return a.handleObj.handler.apply( this,arguments );
            };
          },
          teardown : function () {
            e.event.remove( this,"._change" );
            return F.test( this.nodeName );
          }
        };
      };
      
      if ( !e.support.focusinBubbles ){
        e.each(  {
          focus : "focusin",
          blur : "focusout"
        },
        function ( c,a ) {
          var b = 0,
              d = function ( b ) {
                e.event.simulate( a,b.target,e.event.fix( b ),true );
              };
          
          e.event.special[a] =  {
            setup : function () {
              if ( b ++  === 0 ){
                document.addEventListener( c,d,true );
              };
            },
            teardown : function () {
              if (  -- b === 0 ){
                document.removeEventListener( c,d,true );
              };
            }
          };
        });
      };
      
      e.fn.extend(  {
        on : function ( b,f,d,c,g ) {
          var a,
              h;
          
          if ( typeof b === "object" ){
            if ( typeof f !== "string" ){
              d = f;
              
              f = undefined;
            };
            
            for ( h in b )this.on( h,f,d,b[h],g );
            return this;
          };
          
          if ( d == null && c == null ){
            c = f;
            
            d = f = undefined;
          } else if ( c == null ){
            if ( typeof f === "string" ){
              c = d;
              
              d = undefined;
            } else {
              c = d;
              
              d = f;
              
              f = undefined;
            };
          };
          
          if ( c === false ){
            c = E;
          } else if ( !c ){
            return this;
          };
          
          if ( g === 1 ){
            a = c;
            
            c = function ( b ) {
              e().off( b );
              return a.apply( this,arguments );
            };
            
            c.guid = a.guid || ( a.guid = e.guid ++  );
          };
          return this.each( function () {
            e.event.add( this,b,c,d,f );
          });
        },
        one : function ( a,b,c,d ) {
          return this.on.call( this,a,b,c,d,1 );
        },
        off : function ( a,c,b ) {
          if ( a && a.preventDefault && a.handleObj ){
            var d = a.handleObj;
            
            e( a.delegateTarget ).off( d.namespace?d.type+"."+d.namespace : d.type,d.selector,d.handler );
            return this;
          };
          
          if ( typeof a === "object" ){
            for ( var f in a )
            this.off( f,c,a[f] );
            return this;
          };
          
          if ( c === false || typeof c === "function" ){
            b = c;
            
            c = undefined;
          };
          
          if ( b === false ){
            b = E;
          };
          return this.each( function () {
            e.event.remove( this,a,b,c );
          });
        },
        bind : function ( a,b,c ) {
          return this.on( a,null,b,c );
        },
        unbind : function ( a,b ) {
          return this.off( a,null,b );
        },
        live : function ( a,b,c ) {
          e( this.context ).on( a,this.selector,b,c );
          return this;
        },
        die : function ( a,b ) {
          e( this.context ).off( a,this.selector || "**",b );
          return this;
        },
        delegate : function ( a,b,c,d ) {
          return this.on( b,a,c,d );
        },
        undelegate : function ( a,b,c ) {
          return arguments.length == 1?this.off( a,"**" ) : this.off( b,a,c );
        },
        trigger : function ( a,b ) {
          return this.each( function () {
            e.event.trigger( a,b,this );
          });
        },
        triggerHandler : function ( a,b ) {
          if ( this[0] ){
            return e.event.trigger( a,b,this[0],true );
          };
        },
        toggle : function ( a ) {
          var c = arguments,
              d = a.guid || e.guid ++ ,
              b = 0,
              f = function ( d ) {
                var f = ( e._data( this,"lastToggle"+a.guid ) || 0 )%b;
                
                e._data( this,"lastToggle"+a.guid,f+1 );
                
                d.preventDefault();
                return c[f].apply( this,arguments ) || false;
              };
          
          f.guid = d;
          
          while ( b<c.length )c[b ++ ].guid = d;
          return this.click( f );
        },
        hover : function ( a,b ) {
          return this.mouseenter( a ).mouseleave( b || a );
        }
      });
      
      e.each( ( "blur focus focusin focusout load resize scroll unload click dblclick mousedown mouseup mousemove mouseover mouseout mouseenter mouseleave change select submit keydown keypress keyup error contextmenu" ).split( " " ),
      function ( I,a ) {
        e.fn[a] = function ( b,c ) {
          if ( c == null ){
            c = b;
            
            b = null;
          };
          return arguments.length>0?this.on( a,null,b,c ) : this.trigger( a );
        };
        
        if ( e.attrFn ){
          e.attrFn[a] = true;
        };
        
        if ( G.test( a ) ){
          e.event.fixHooks[a] = e.event.keyHooks;
        };
        
        if ( H.test( a ) ){
          e.event.fixHooks[a] = e.event.mouseHooks;
        };
      });
      
      !function () {
        var c = /((?:\((?:\([^()]+\)|[^()]+)+\)|\[(?:\[[^\[\]]*\]|['"][^'"]*['"]|[^\[\]'"]+)+\]|\\.|[^ >+~,(\[\\]+)+|[>+~])(\s*,\s*)?((?:.|\r|\n)*)/g,
            s = "sizcache"+( Math.random()+'' ).replace( '.','' ),
            p = 0,
            i = Object.prototype.toString,
            k = false,
            a = true,
            l = /\\/g,
            m = /\r\n/g,
            o = /\W/;
        
        [0,0].sort( function () {
          a = false;
          return 0;
        });
        
        var b = function ( j,k,l,m ) {
              l = l || [];
              
              k = k || document;
              
              var n = k;
              
              if ( k.nodeType !== 1 && k.nodeType !== 9 ){
                return [];
              };
              
              if ( !j || typeof j !== "string" ){
                return l;
              };
              
              var o,
                  p,
                  q,
                  r,
                  s,
                  t,
                  u,
                  v,
                  w = true,
                  x = b.isXML( k ),
                  y = [],
                  z = j;
              
              do {
                c.exec( "" );
                
                o = c.exec( z );
                
                if ( o ){
                  z = o[3];
                  
                  y.push( o[1] );
                  
                  if ( o[2] ){
                    r = o[3];
                    break;
                  };
                };
              }while ( o );
              
              if ( y.length>1 && d.exec( j ) ){
                if ( y.length === 2 && f.relative[y[0]] ){
                  p = g( y[0]+y[1],k,m );
                } else {
                  p = f.relative[y[0]]?[k] : b( y.shift(),k );
                  
                  while ( y.length ){
                    j = y.shift();
                    if ( f.relative[j] ){
                      j += y.shift();
                    };
                    
                    p = g( j,p,m );
                  };
                };
              } else {
                if ( !m && y.length>1 && k.nodeType === 9 && !x && f.match.ID.test( y[0] ) && !f.match.ID.test( y[y.length-1] ) ){
                  s = b.find( y.shift(),k,x );
                  
                  k = s.expr?b.filter( s.expr,s.set )[0] : s.set[0];
                };
                if ( k ){
                  s = m? {
                    expr : y.pop(),
                    set : h( m )
                  } : b.find( y.pop(),y.length === 1 && ( y[0] === "~" || y[0] === "+" ) && k.parentNode?k.parentNode : k,x );
                  
                  p = s.expr?b.filter( s.expr,s.set ) : s.set;
                  if ( y.length>0 ){
                    q = h( p );
                  } else {
                    w = false;
                  };
                  
                  while ( y.length ){
                    t = y.pop();
                    
                    u = t;
                    if ( !f.relative[t] ){
                      t = "";
                    } else {
                      u = y.pop();
                    };
                    if ( u == null ){
                      u = k;
                    };
                    
                    f.relative[t]( q,u,x );
                  };
                } else {
                  q = y = [];
                };
              };
              
              if ( !q ){
                q = p;
              };
              
              if ( !q ){
                b.error( t || j );
              };
              
              if ( i.call( q ) === "[object Array]" ){
                if ( !w ){
                  l.push.apply( l,q );
                } else if ( k && k.nodeType === 1 ){
                  for ( v = 0;q[v] != null;v ++  )if ( q[v] && ( q[v] === true || q[v].nodeType === 1 && b.contains( k,q[v] ) ) ){
                    l.push( p[v] );
                  };
                } else {
                  for ( v = 0;q[v] != null;v ++  )if ( q[v] && q[v].nodeType === 1 ){
                    l.push( p[v] );
                  };
                };
              } else {
                h( q,l );
              };
              
              if ( r ){
                b( r,n,l,m );
                
                b.uniqueSort( l );
              };
              return l;
            };
        
        b.uniqueSort = function ( l ) {
          if ( j ){
            k = a;
            
            l.sort( j );
            
            if ( k ){
              for ( var m = 1;m<l.length;m ++  )
              if ( l[m] === l[m-1] ){
                l.splice( m -- ,1 );
              };
            };
          };
          return l;
        };
        
        b.matches = function ( a,c ) {
          return b( a,null,null,c );
        };
        
        b.matchesSelector = function ( a,c ) {
          return b( c,null,null,[a] ).length>0;
        };
        
        b.find = function ( m,n,o ) {
          var p,
              q,
              r,
              s,
              t,
              u;
          
          if ( !m ){
            return [];
          };
          
          for ( q = 0 , r = f.order.length;q<r;q ++  ){
            t = f.order[q];
            
            if ( ( s = f.leftMatch[t].exec( m ) ) ){
              u = s[1];
              
              s.splice( 1,1 );
              
              if ( u.substr( u.length-1 ) !== "\\" ){
                s[1] = ( s[1] || "" ).replace( l,"" );
                
                p = f.find[t]( s,n,o );
                
                if ( p != null ){
                  m = m.replace( f.match[t],"" );
                  break;
                };
              };
            };
          };
          
          if ( !p ){
            p = typeof n.getElementsByTagName !== "undefined"?n.getElementsByTagName( "*" ) : [];
          };
          return  {
            set : p,
            expr : m
          };
        };
        
        b.filter = function ( a,c,d,e ) {
          var g,
              h,
              i,
              j,
              k,
              l,
              m,
              n,
              o,
              p = a,
              q = [],
              r = c,
              s = c && c[0] && b.isXML( c[0] );
          
          while ( a && c.length ){
            for ( i in f.filter )if ( ( g = f.leftMatch[i].exec( a ) ) != null && g[2] ){
              l = f.filter[i];
              
              m = g[1];
              
              h = false;
              
              g.splice( 1,1 );
              
              if ( m.substr( m.length-1 ) === "\\" ){
                continue ;
              };
              
              if ( r === q ){
                q = [];
              };
              
              if ( f.preFilter[i] ){
                g = f.preFilter[i]( g,r,d,q,e,s );
                
                if ( !g ){
                  h = j = true;
                } else if ( g === true ){
                  continue ;
                };
              };
              
              if ( g ){
                for ( n = 0;( k = r[n] ) != null;n ++  )if ( k ){
                  j = l( k,g,n,r );
                  
                  o = e^j;
                  
                  if ( d && j != null ){
                    if ( o ){
                      h = true;
                    } else {
                      r[n] = false;
                    };
                  } else if ( o ){
                    q.push( k );
                    
                    h = true;
                  };
                };
              };
              
              if ( j !== undefined ){
                if ( !d ){
                  r = q;
                };
                
                a = a.replace( f.match[i],"" );
                
                if ( !h ){
                  return [];
                };
                break;
              };
            };
            
            if ( a === p ){
              if ( h == null ){
                b.error( a );
              } else {
                break;
              };
            };
            
            p = a;
          };
          return r;
        };
        
        b.error = function ( a ) {
          throw new Error( "Syntax error, unrecognized expression: "+a );
        };
        
        var n = b.getText = function ( o ) {
              var p,
                  q,
                  r = o.nodeType,
                  s = "";
              
              if ( r ){
                if ( r === 1 || r === 9 ){
                  if ( typeof o.textContent === 'string' ){
                    return o.textContent;
                  } else if ( typeof o.innerText === 'string' ){
                    return o.innerText.replace( m,'' );
                  } else {
                    for ( o = o.firstChild;o;o = o.nextSibling )s += n( o );
                  };
                } else if ( r === 3 || r === 4 ){
                  return o.nodeValue;
                };
              } else {
                for ( p = 0;( q = o[p] );p ++  )if ( q.nodeType !== 8 ){
                  s += n( q );
                };
              };
              return s;
            };
        
        var f = b.selectors =  {
              order : ["ID","NAME","TAG"],
              match :  {
                ID : /#((?:[\w\u00c0-\uFFFF\-]|\\.)+)/,
                CLASS : /\.((?:[\w\u00c0-\uFFFF\-]|\\.)+)/,
                NAME : /\[name=['"]*((?:[\w\u00c0-\uFFFF\-]|\\.)+)['"]*\]/,
                ATTR : /\[\s*((?:[\w\u00c0-\uFFFF\-]|\\.)+)\s*(?:(\S?=)\s*(?:(['"])(.*?)\3|(#?(?:[\w\u00c0-\uFFFF\-]|\\.)*)|)|)\s*\]/,
                TAG : /^((?:[\w\u00c0-\uFFFF\*\-]|\\.)+)/,
                CHILD : /:(only|nth|last|first)-child(?:\(\s*(even|odd|(?:[+\-]?\d+|(?:[+\-]?\d*)?n\s*(?:[+\-]\s*\d+)?))\s*\))?/,
                POS : /:(nth|eq|gt|lt|first|last|even|odd)(?:\((\d*)\))?(?=[^\-]|$)/,
                PSEUDO : /:((?:[\w\u00c0-\uFFFF\-]|\\.)+)(?:\((['"]?)((?:\([^\)]+\)|[^\(\)]*)+)\2\))?/
              },
              leftMatch : {},
              attrMap :  {
                "class" : "className",
                "for" : "htmlFor"
              },
              attrHandle :  {
                href : function ( a ) {
                  return a.getAttribute( "href" );
                },
                type : function ( a ) {
                  return a.getAttribute( "type" );
                }
              },
              relative :  {
                "+" : function ( p,q ) {
                  var r = typeof q === "string",
                      s = r && !o.test( q ),
                      t = r && !s;
                  
                  if ( s ){
                    q = q.toLowerCase();
                  };
                  
                  for ( var u = 0,v = p.length,w;u<v;u ++  )
                  if ( ( w = p[u] ) ){
                    while ( ( w = w.previousSibling ) && w.nodeType !== 1 ){
                      
                    };
                    
                    p[u] = t || w && w.nodeName.toLowerCase() === q?w || false : w === q;
                  };
                  
                  if ( t ){
                    b.filter( q,p,true );
                  };
                },
                ">" : function ( a,c ) {
                  var d,
                      e = typeof c === "string",
                      f = 0,
                      g = a.length;
                  
                  if ( e && !o.test( c ) ){
                    c = c.toLowerCase();
                    
                    for ( ;f<g;f ++  ){
                      d = a[f];
                      
                      if ( d ){
                        var h = d.parentNode;
                        
                        a[f] = h.nodeName.toLowerCase() === c?h : false;
                      };
                    };
                  } else {
                    for ( ;f<g;f ++  ){
                      d = a[f];
                      if ( d ){
                        a[f] = e?d.parentNode : d.parentNode === c;
                      };
                    };
                    if ( e ){
                      b.filter( c,a,true );
                    };
                  };
                },
                "" : function ( s,t,u ) {
                  var v,
                      w = p ++ ,
                      x = q;
                  
                  if ( typeof t === "string" && !o.test( t ) ){
                    t = t.toLowerCase();
                    
                    v = t;
                    
                    x = r;
                  };
                  
                  x( "parentNode",t,w,s,v,u );
                },
                "~" : function ( a,b,c ) {
                  var d,
                      e = p ++ ,
                      f = q;
                  
                  if ( typeof b === "string" && !o.test( b ) ){
                    b = b.toLowerCase();
                    
                    d = b;
                    
                    f = r;
                  };
                  
                  f( "previousSibling",b,e,a,d,c );
                }
              },
              find :  {
                ID : function ( a,b,c ) {
                  if ( typeof b.getElementById !== "undefined" && !c ){
                    var d = b.getElementById( a[1] );
                    return d && d.parentNode?[d] : [];
                  };
                },
                NAME : function ( a,b ) {
                  if ( typeof b.getElementsByName !== "undefined" ){
                    var c = [],
                        d = b.getElementsByName( a[1] );
                    
                    for ( var e = 0,f = d.length;e<f;e ++  )
                    if ( d[e].getAttribute( "name" ) === a[1] ){
                      c.push( d[e] );
                    };
                    return c.length === 0?null : c;
                  };
                },
                TAG : function ( a,b ) {
                  if ( typeof b.getElementsByTagName !== "undefined" ){
                    return b.getElementsByTagName( a[1] );
                  };
                }
              },
              preFilter :  {
                CLASS : function ( a,b,c,d,e,f ) {
                  a = " "+a[1].replace( l,"" )+" ";
                  
                  if ( f ){
                    return a;
                  };
                  
                  for ( var g = 0,h;( h = b[g] ) != null;g ++  )
                  if ( h ){
                    if ( e^( h.className && ( " "+h.className+" " ).replace( /[\t\n\r]/g," " ).indexOf( a ) >= 0 ) ){
                      if ( !c ){
                        d.push( h );
                      };
                    } else if ( c ){
                      b[g] = false;
                    };
                  };
                  return false;
                },
                ID : function ( a ) {
                  return a[1].replace( l,"" );
                },
                TAG : function ( a,b ) {
                  return a[1].replace( l,"" ).toLowerCase();
                },
                CHILD : function ( a ) {
                  if ( a[1] === "nth" ){
                    if ( !a[2] ){
                      b.error( a[0] );
                    };
                    
                    a[2] = a[2].replace( /^\+|\s*/g,'' );
                    
                    var c = /(-?)(\d*)(?:n([+\-]?\d*))?/.exec( a[2] === "even" && "2n" || a[2] === "odd" && "2n+1" || !/\D/.test( a[2] ) && "0n+"+a[2] || a[2] );
                    
                    a[2] = ( c[1]+( c[2] || 1 ) )-0;
                    
                    a[3] = c[3]-0;
                  } else if ( a[2] ){
                    b.error( a[0] );
                  };
                  
                  a[0] = p ++ ;
                  return a;
                },
                ATTR : function ( a,b,c,d,e,g ) {
                  var h = a[1] = a[1].replace( l,"" );
                  
                  if ( !g && f.attrMap[h] ){
                    a[1] = f.attrMap[h];
                  };
                  
                  a[4] = ( a[4] || a[5] || "" ).replace( l,"" );
                  
                  if ( a[2] === "~=" ){
                    a[4] = " "+a[4]+" ";
                  };
                  return a;
                },
                PSEUDO : function ( a,d,e,g,h ) {
                  if ( a[1] === "not" ){
                    if ( ( c.exec( a[3] ) || "" ).length>1 || /^\w/.test( a[3] ) ){
                      a[3] = b( a[3],null,null,d );
                    } else {
                      var i = b.filter( a[3],d,e,true^h );
                      if ( !e ){
                        g.push.apply( g,i );
                      };
                      return false;
                    };
                  } else if ( f.match.POS.test( a[0] ) || f.match.CHILD.test( a[0] ) ){
                    return true;
                  };
                  return a;
                },
                POS : function ( a ) {
                  a.unshift( true );
                  return a;
                }
              },
              filters :  {
                enabled : function ( a ) {
                  return a.disabled === false && a.type !== "hidden";
                },
                disabled : function ( a ) {
                  return a.disabled === true;
                },
                checked : function ( a ) {
                  return a.checked === true;
                },
                selected : function ( a ) {
                  if ( a.parentNode ){
                    a.parentNode.selectedIndex;
                  };
                  return a.selected === true;
                },
                parent : function ( a ) {
                  return !!a.firstChild;
                },
                empty : function ( a ) {
                  return !a.firstChild;
                },
                has : function ( a,c,d ) {
                  return !!b( d[3],a ).length;
                },
                header : function ( a ) {
                  return ( /h\d/i ).test( a.nodeName );
                },
                text : function ( a ) {
                  var b = a.getAttribute( "type" ),
                      c = a.type;
                  return a.nodeName.toLowerCase() === "input" && "text" === c && ( b === c || b === null );
                },
                radio : function ( a ) {
                  return a.nodeName.toLowerCase() === "input" && "radio" === a.type;
                },
                checkbox : function ( a ) {
                  return a.nodeName.toLowerCase() === "input" && "checkbox" === a.type;
                },
                file : function ( a ) {
                  return a.nodeName.toLowerCase() === "input" && "file" === a.type;
                },
                password : function ( a ) {
                  return a.nodeName.toLowerCase() === "input" && "password" === a.type;
                },
                submit : function ( a ) {
                  var b = a.nodeName.toLowerCase();
                  return ( b === "input" || b === "button" ) && "submit" === a.type;
                },
                image : function ( a ) {
                  return a.nodeName.toLowerCase() === "input" && "image" === a.type;
                },
                reset : function ( a ) {
                  var b = a.nodeName.toLowerCase();
                  return ( b === "input" || b === "button" ) && "reset" === a.type;
                },
                button : function ( a ) {
                  var b = a.nodeName.toLowerCase();
                  return b === "input" && "button" === a.type || b === "button";
                },
                input : function ( a ) {
                  return ( /input|select|textarea|button/i ).test( a.nodeName );
                },
                focus : function ( a ) {
                  return a === a.ownerDocument.activeElement;
                }
              },
              setFilters :  {
                first : function ( a,b ) {
                  return b === 0;
                },
                last : function ( a,b,c,d ) {
                  return b === d.length-1;
                },
                even : function ( a,b ) {
                  return b%2 === 0;
                },
                odd : function ( a,b ) {
                  return b%2 === 1;
                },
                lt : function ( a,b,c ) {
                  return b<c[3]-0;
                },
                gt : function ( a,b,c ) {
                  return b>c[3]-0;
                },
                nth : function ( a,b,c ) {
                  return c[3]-0 === b;
                },
                eq : function ( a,b,c ) {
                  return c[3]-0 === b;
                }
              },
              filter :  {
                PSEUDO : function ( a,c,d,e ) {
                  var g = c[1],
                      h = f.filters[g];
                  
                  if ( h ){
                    return h( a,d,c,e );
                  } else if ( g === "contains" ){
                    return ( a.textContent || a.innerText || n( [a] ) || "" ).indexOf( c[3] ) >= 0;
                  } else if ( g === "not" ){
                    var i = c[3];
                    
                    for ( var j = 0,k = i.length;j<k;j ++  )if ( i[j] === a ){
                      return false;
                    };
                    return true;
                  } else {
                    b.error( g );
                  };
                },
                CHILD : function ( t,u ) {
                  var v,
                      w,
                      x,
                      y,
                      z,
                      A,
                      B,
                      C = u[1],
                      D = t;
                  
                  switch ( C ) {
                    case "only" :
                    case "first" :
                      
                      while ( ( D = D.previousSibling ) )if ( D.nodeType === 1 ){
                        return false;
                      };
                      
                      if ( C === "first" ){
                        return true;
                      };
                      
                      D = t;
                    case "last" :
                      
                      while ( ( D = D.nextSibling ) )if ( D.nodeType === 1 ){
                        return false;
                      };
                      return true;
                    case "nth" :
                      
                      v = u[2];
                      
                      w = u[3];
                      
                      if ( v === 1 && w === 0 ){
                        return true;
                      };
                      
                      x = u[0];
                      
                      y = t.parentNode;
                      
                      if ( y && ( y[s] !== x || !t.nodeIndex ) ){
                        A = 0;
                        
                        for ( D = y.firstChild;D;D = D.nextSibling )if ( D.nodeType === 1 ){
                          D.nodeIndex =  ++ A;
                        };
                        
                        y[s] = x;
                      };
                      
                      B = t.nodeIndex-w;
                      
                      if ( v === 0 ){
                        return B === 0;
                      } else {
                        return ( B%v === 0 && B/v >= 0 );
                      };
                      
                  };
                },
                ID : function ( a,b ) {
                  return a.nodeType === 1 && a.getAttribute( "id" ) === b;
                },
                TAG : function ( a,b ) {
                  return ( b === "*" && a.nodeType === 1 ) || !!a.nodeName && a.nodeName.toLowerCase() === b;
                },
                CLASS : function ( a,b ) {
                  return ( " "+( a.className || a.getAttribute( "class" ) )+" " ).indexOf( b )>-1;
                },
                ATTR : function ( a,c ) {
                  var d = c[1],
                      e = b.attr?b.attr( a,d ) : f.attrHandle[d]?f.attrHandle[d]( a ) : a[d] != null?a[d] : a.getAttribute( d ),
                      g = e+"",
                      h = c[2],
                      i = c[4];
                  return e == null?h === "!=" : !h && b.attr?e != null : h === "="?g === i : h === "*="?g.indexOf( i ) >= 0 : h === "~="?( " "+g+" " ).indexOf( i ) >= 0 : !i?g && e !== false : h === "!="?g !== i : h === "^="?g.indexOf( i ) === 0 : h === "$="?g.substr( g.length-i.length ) === i : h === "|="?g === i || g.substr( 0,i.length+1 ) === i+"-" : false;
                },
                POS : function ( a,b,c,d ) {
                  var e = b[2],
                      g = f.setFilters[e];
                  
                  if ( g ){
                    return g( a,c,b,d );
                  };
                }
              }
            };
        
        var d = f.match.POS,
            u = function ( a,b ) {
              return "\\"+( b-0+1 );
            };
        
        for ( var v in f.match ){
          f.match[v] = new RegExp( f.match[v].source+( /(?![^\[]*\])(?![^\(]*\))/.source ) );
          
          f.leftMatch[v] = new RegExp( /(^(?:.|\r|\n)*?)/.source+f.match[v].source.replace( /\\(\d+)/g,u ) );
        };
        
        var h = function ( a,b ) {
              a = Array.prototype.slice.call( a,0 );
              
              if ( b ){
                b.push.apply( b,a );
                return b;
              };
              return a;
            };
        
        try {
          Array.prototype.slice.call( document.documentElement.childNodes,0 )[0].nodeType;
        } catch( e ){
          h = function ( a,b ) {
            var c = 0,
                d = b || [];
            
            if ( i.call( a ) === "[object Array]" ){
              Array.prototype.push.apply( d,a );
            } else if ( typeof a.length === "number" ){
              for ( var e = a.length;c<e;c ++  )
              d.push( a[c] );
            } else {
              for ( ;a[c];c ++  )d.push( a[c] );
            };
            return d;
          };
        };
        
        var j,
            t;
        
        if ( document.documentElement.compareDocumentPosition ){
          j = function ( a,b ) {
            if ( a === b ){
              k = true;
              return 0;
            };
            
            if ( !a.compareDocumentPosition || !b.compareDocumentPosition ){
              return a.compareDocumentPosition?-1 : 1;
            };
            return a.compareDocumentPosition( b )&4?-1 : 1;
          };
        } else {
          j = function ( u,v ) {
            if ( u === v ){
              k = true;
              return 0;
            } else if ( u.sourceIndex && v.sourceIndex ){
              return u.sourceIndex-v.sourceIndex;
            };
            
            var w,
                x,
                y = [],
                z = [],
                A = u.parentNode,
                B = v.parentNode,
                C = A;
            if ( A === B ){
              return t( u,v );
            } else if ( !A ){
              return -1;
            } else if ( !B ){
              return 1;
            };
            
            while ( C ){
              y.unshift( C );
              
              C = C.parentNode;
            };
            
            C = B;
            
            while ( C ){
              z.unshift( C );
              
              C = C.parentNode;
            };
            
            w = y.length;
            
            x = z.length;
            
            for ( var D = 0;D<w && D<x;D ++  )if ( y[D] !== z[D] ){
              return t( y[D],z[D] );
            };
            return D === w?t( u,z[D],-1 ) : t( y[D],v,1 );
          };
          
          t = function ( a,b,c ) {
            if ( a === b ){
              return c;
            };
            
            var d = a.nextSibling;
            
            while ( d ){
              if ( d === b ){
                return -1;
              };
              
              d = d.nextSibling;
            };
            return 1;
          };
        };
        
        !function () {
          var a = document.createElement( "div" ),
              b = "script"+( new Date() ).getTime(),
              c = document.documentElement;
          
          a.innerHTML = "<a name='"+b+"'/>";
          
          c.insertBefore( a,c.firstChild );
          
          if ( document.getElementById( b ) ){
            f.find.ID = function ( a,b,c ) {
              if ( typeof b.getElementById !== "undefined" && !c ){
                var d = b.getElementById( a[1] );
                return d?d.id === a[1] || typeof d.getAttributeNode !== "undefined" && d.getAttributeNode( "id" ).nodeValue === a[1]?[d] : undefined : [];
              };
            };
            
            f.filter.ID = function ( a,b ) {
              var c = typeof a.getAttributeNode !== "undefined" && a.getAttributeNode( "id" );
              return a.nodeType === 1 && c && c.nodeValue === b;
            };
          };
          
          c.removeChild( a );
          
          c = a = null;
        }();
        
        !function () {
          var a = document.createElement( "div" );
          
          a.appendChild( document.createComment( "" ) );
          
          if ( a.getElementsByTagName( "*" ).length>0 ){
            f.find.TAG = function ( a,b ) {
              var c = b.getElementsByTagName( a[1] );
              
              if ( a[1] === "*" ){
                var d = [];
                
                for ( var e = 0;c[e];e ++  )
                if ( c[e].nodeType === 1 ){
                  d.push( c[e] );
                };
                
                c = d;
              };
              return c;
            };
          };
          
          a.innerHTML = "<a href='#'></a>";
          
          if ( a.firstChild && typeof a.firstChild.getAttribute !== "undefined" && a.firstChild.getAttribute( "href" ) !== "#" ){
            f.attrHandle.href = function ( a ) {
              return a.getAttribute( "href",2 );
            };
          };
          
          a = null;
        }();
        
        if ( document.querySelectorAll ){
          !function () {
            var c = b,
                d = document.createElement( "div" ),
                a = "__sizzle__";
            
            d.innerHTML = "<p class='TEST'></p>";
            
            if ( d.querySelectorAll && d.querySelectorAll( ".TEST" ).length === 0 ){
              return ;
            };
            
            b = function ( d,e,g,i ) {
              e = e || document;
              
              if ( !i && !b.isXML( e ) ){
                var j = /^(\w+$)|^\.([\w\-]+$)|^#([\w\-]+$)/.exec( d );
                
                if ( j && ( e.nodeType === 1 || e.nodeType === 9 ) ){
                  if ( j[1] ){
                    return h( e.getElementsByTagName( d ),g );
                  } else if ( j[2] && f.find.CLASS && e.getElementsByClassName ){
                    return h( e.getElementsByClassName( j[2] ),g );
                  };
                };
                
                if ( e.nodeType === 9 ){
                  if ( d === "body" && e.body ){
                    return h( [e.body],g );
                  } else if ( j && j[3] ){
                    var k = e.getElementById( j[3] );
                    if ( k && k.parentNode ){
                      if ( k.id === j[3] ){
                        return h( [k],g );
                      };
                    } else {
                      return h( [],g );
                    };
                  };
                  
                  try {
                    return h( e.querySelectorAll( d ),g );
                  } catch( qsaError ){
                    
                  };
                } else if ( e.nodeType === 1 && e.nodeName.toLowerCase() !== "object" ){
                  var l = e,
                      m = e.getAttribute( "id" ),
                      n = m || a,
                      o = e.parentNode,
                      p = /^\s*[+~]/.test( d );
                  if ( !m ){
                    e.setAttribute( "id",n );
                  } else {
                    n = n.replace( /'/g,"\\$&" );
                  };
                  if ( p && o ){
                    e = e.parentNode;
                  };
                  
                  try {
                    if ( !p || o ){
                      return h( e.querySelectorAll( "[id='"+n+"'] "+d ),g );
                    };
                  } catch( pseudoError ){
                    
                  } finally {
                    if ( !m ){
                      l.removeAttribute( "id" );
                    };
                  };
                };
              };
              return c( d,e,g,i );
            };
            
            for ( var e in c )
            b[e] = c[e];
            
            d = null;
          }();
        };
        
        !function () {
          var e = document.documentElement,
              c = e.matchesSelector || e.mozMatchesSelector || e.webkitMatchesSelector || e.msMatchesSelector;
          
          if ( c ){
            var d = !c.call( document.createElement( "div" ),"div" ),
                a = false;
            
            try {
              c.call( document.documentElement,"[test!='']:sizzle" );
            } catch( pseudoError ){
              a = true;
            };
            
            b.matchesSelector = function ( e,g ) {
              g = g.replace( /\=\s*([^'"\]]*)\s*\]/g,"='$1']" );
              
              if ( !b.isXML( e ) ){
                try {
                  if ( a || !f.match.PSEUDO.test( g ) && !/!=/.test( g ) ){
                    var h = c.call( e,g );
                    
                    if ( h || !d || e.document && e.document.nodeType !== 11 ){
                      return h;
                    };
                  };
                } catch( e ){
                  
                };
              };
              return b( g,null,null,[e] ).length>0;
            };
          };
        }();
        
        !function () {
          var a = document.createElement( "div" );
          
          a.innerHTML = "<div class='test e'></div><div class='test'></div>";
          
          if ( !a.getElementsByClassName || a.getElementsByClassName( "e" ).length === 0 ){
            return ;
          };
          
          a.lastChild.className = "e";
          
          if ( a.getElementsByClassName( "e" ).length === 1 ){
            return ;
          };
          
          f.order.splice( 1,0,"CLASS" );
          
          f.find.CLASS = function ( a,b,c ) {
            if ( typeof b.getElementsByClassName !== "undefined" && !c ){
              return b.getElementsByClassName( a[1] );
            };
          };
          
          a = null;
        }();
        
        function r( a,b,c,d,e,f ) {
          for ( var g = 0,h = d.length;g<h;g ++  ){
            var i = d[g];
            
            if ( i ){
              var j = false;
              
              i = i[a];
              
              while ( i ){
                if ( i[s] === c ){
                  j = d[i.sizset];
                  break;
                };
                
                if ( i.nodeType === 1 && !f ){
                  i[s] = c;
                  
                  i.sizset = g;
                };
                
                if ( i.nodeName.toLowerCase() === b ){
                  j = i;
                  break;
                };
                
                i = i[a];
              };
              
              d[g] = j;
            };
          };
        }
        function q( a,c,d,e,f,g ) {
          for ( var h = 0,i = e.length;h<i;h ++  ){
            var j = e[h];
            
            if ( j ){
              var k = false;
              
              j = j[a];
              
              while ( j ){
                if ( j[s] === d ){
                  k = e[j.sizset];
                  break;
                };
                
                if ( j.nodeType === 1 ){
                  if ( !g ){
                    j[s] = d;
                    
                    j.sizset = h;
                  };
                  
                  if ( typeof c !== "string" ){
                    if ( j === c ){
                      k = true;
                      break;
                    };
                  } else if ( b.filter( c,[j] ).length>0 ){
                    k = j;
                    break;
                  };
                };
                
                j = j[a];
              };
              
              e[h] = k;
            };
          };
        }
        if ( document.documentElement.contains ){
          b.contains = function ( a,b ) {
            return a !== b && ( a.contains?a.contains( b ) : true );
          };
        } else if ( document.documentElement.compareDocumentPosition ){
          b.contains = function ( a,b ) {
            return !!( a.compareDocumentPosition( b )&16 );
          };
        } else {
          b.contains = function () {
            return false;
          };
        };
        
        b.isXML = function ( a ) {
          var b = ( a?a.ownerDocument || a : 0 ).documentElement;
          return b?b.nodeName !== "HTML" : false;
        };
        
        var g = function ( a,c,d ) {
              var e,
                  g = [],
                  h = "",
                  i = c.nodeType?[c] : c;
              
              while ( ( e = f.match.PSEUDO.exec( a ) ) ){
                h += e[0];
                
                a = a.replace( f.match.PSEUDO,"" );
              };
              
              a = f.relative[a]?a+"*" : a;
              
              for ( var j = 0,k = i.length;j<k;j ++  )
              b( a,i[j],g,d );
              return b.filter( h,g );
            };
        
        b.attr = e.attr;
        
        b.selectors.attrMap = {};
        
        e.find = b;
        
        e.expr = b.selectors;
        
        e.expr[":"] = e.expr.filters;
        
        e.unique = b.uniqueSort;
        
        e.text = b.getText;
        
        e.isXMLDoc = b.isXML;
        
        e.contains = b.contains;
      }();
      
      var L = /Until$/,
          O = /^(?:parents|prevUntil|prevAll)/,
          N = /,/,
          Q = /^.[^:#\[\.,]*$/,
          P = Array.prototype.slice,
          J = e.expr.match.POS,
          M =  {
            children : true,
            contents : true,
            next : true,
            prev : true
          };
      
      e.fn.extend(  {
        find : function ( c ) {
          var self = this,
              a,
              b;
          
          if ( typeof c !== "string" ){
            return e( c ).filter( function () {
              for ( a = 0 , b = self.length;a<b;a ++  )if ( e.contains( self[a],this ) ){
                return true;
              };
            });
          };
          
          var d = this.pushStack( "","find",c ),
              f,
              g,
              h;
          
          for ( a = 0 , b = this.length;a<b;a ++  ){
            f = d.length;
            
            e.find( c,this[a],d );
            
            if ( a>0 ){
              for ( g = f;g<d.length;g ++  )for ( h = 0;h<f;h ++  )if ( d[h] === d[g] ){
                d.splice( g -- ,1 );
                break;
              };
            };
          };
          return d;
        },
        has : function ( b ) {
          var a = e( b );
          return this.filter( function () {
            for ( var b = 0,c = a.length;b<c;b ++  )
            if ( e.contains( this,a[b] ) ){
              return true;
            };
          });
        },
        not : function ( J ) {
          return this.pushStack( I( this,J,false ),"not",J );
        },
        filter : function ( a ) {
          return this.pushStack( I( this,a,true ),"filter",a );
        },
        is : function ( K ) {
          return !!K && ( typeof K === "string"?J.test( K )?e( K,this.context ).index( this[0] ) >= 0 : e.filter( K,this ).length>0 : this.filter( K ).length>0 );
        },
        closest : function ( a,b ) {
          var c = [],
              d,
              f,
              g = this[0];
          
          if ( e.isArray( a ) ){
            var h = 1;
            
            while ( g && g.ownerDocument && g !== b ){
              for ( d = 0;d<a.length;d ++  )if ( e( g ).is( a[d] ) ){
                c.push(  {
                  selector : a[d],
                  elem : g,
                  level : h
                });
              };
              
              g = g.parentNode;
              
              h ++ ;
            };
            return c;
          };
          
          var i = J.test( a ) || typeof a !== "string"?e( a,b || this.context ) : 0;
          
          for ( d = 0 , f = this.length;d<f;d ++  ){
            g = this[d];
            
            while ( g )if ( i?i.index( g )>-1 : e.find.matchesSelector( g,a ) ){
              c.push( g );
              break;
            } else {
              g = g.parentNode;
              if ( !g || !g.ownerDocument || g === b || g.nodeType === 11 ){
                break;
              };
            };
          };
          
          c = c.length>1?e.unique( c ) : c;
          return this.pushStack( c,"closest",a );
        },
        index : function ( a ) {
          if ( !a ){
            return ( this[0] && this[0].parentNode )?this.prevAll().length : -1;
          };
          
          if ( typeof a === "string" ){
            return e.inArray( this[0],e( a ) );
          };
          return e.inArray( a.jquery?a[0] : a,this );
        },
        add : function ( L,M ) {
          var N = typeof L === "string"?e( L,M ) : e.makeArray( L && L.nodeType?[L] : L ),
              O = e.merge( this.get(),N );
          return this.pushStack( K( N[0] ) || K( O[0] )?O : e.unique( O ) );
        },
        andSelf : function () {
          return this.add( this.prevObject );
        }
      });
      
      function K( a ) {
        return !a || !a.parentNode || a.parentNode.nodeType === 11;
      }
      e.each(  {
        parent : function ( a ) {
          var b = a.parentNode;
          return b && b.nodeType !== 11?b : null;
        },
        parents : function ( a ) {
          return e.dir( a,"parentNode" );
        },
        parentsUntil : function ( a,b,c ) {
          return e.dir( a,"parentNode",c );
        },
        next : function ( a ) {
          return e.nth( a,2,"nextSibling" );
        },
        prev : function ( a ) {
          return e.nth( a,2,"previousSibling" );
        },
        nextAll : function ( a ) {
          return e.dir( a,"nextSibling" );
        },
        prevAll : function ( a ) {
          return e.dir( a,"previousSibling" );
        },
        nextUntil : function ( a,b,c ) {
          return e.dir( a,"nextSibling",c );
        },
        prevUntil : function ( a,b,c ) {
          return e.dir( a,"previousSibling",c );
        },
        siblings : function ( a ) {
          return e.sibling( a.parentNode.firstChild,a );
        },
        children : function ( a ) {
          return e.sibling( a.firstChild );
        },
        contents : function ( a ) {
          return e.nodeName( a,"iframe" )?a.contentDocument || a.contentWindow.document : e.makeArray( a.childNodes );
        }
      },
      function ( b,a ) {
        e.fn[b] = function ( c,d ) {
          var f = e.map( this,a,c );
          
          if ( !L.test( b ) ){
            d = c;
          };
          
          if ( d && typeof d === "string" ){
            f = e.filter( d,f );
          };
          
          f = this.length>1 && !M[b]?e.unique( f ) : f;
          
          if ( ( this.length>1 || N.test( d ) ) && O.test( b ) ){
            f = f.reverse();
          };
          return this.pushStack( f,b,P.call( arguments ).join( "," ) );
        };
      });
      
      e.extend(  {
        filter : function ( a,b,c ) {
          if ( c ){
            a = ":not("+a+")";
          };
          return b.length === 1?e.find.matchesSelector( b[0],a )?[b[0]] : [] : e.find.matches( a,b );
        },
        dir : function ( a,b,c ) {
          var d = [],
              f = a[b];
          
          while ( f && f.nodeType !== 9 && ( c === undefined || f.nodeType !== 1 || !e( f ).is( c ) ) ){
            if ( f.nodeType === 1 ){
              d.push( f );
            };
            
            f = f[b];
          };
          return d;
        },
        nth : function ( a,b,c,d ) {
          b = b || 1;
          
          var e = 0;
          
          for ( ;a;a = a[c] )if ( a.nodeType === 1 &&  ++ e === b ){
            break;
          };
          return a;
        },
        sibling : function ( a,b ) {
          var c = [];
          
          for ( ;a;a = a.nextSibling )if ( a.nodeType === 1 && a !== b ){
            c.push( a );
          };
          return c;
        }
      });
      
      function I( R,a,b ) {
        a = a || 0;
        
        if ( e.isFunction( a ) ){
          return e.grep( R,
          function ( c,d ) {
            var e = !!a.call( c,d,c );
            return e === b;
          });
        } else if ( a.nodeType ){
          return e.grep( R,
          function ( c,d ) {
            return ( c === a ) === b;
          });
        } else if ( typeof a === "string" ){
          var S = e.grep( R,
              function ( a ) {
                return a.nodeType === 1;
              });
          if ( Q.test( a ) ){
            return e.filter( a,S,!b );
          } else {
            a = e.filter( a,S );
          };
        };
        return e.grep( R,
        function ( c,d ) {
          return ( e.inArray( c,a ) >= 0 ) === b;
        });
      }
      function bj( document ) {
        var S = R.split( "|" ),
            T = document.createDocumentFragment();
        
        if ( T.createElement ){
          while ( S.length )T.createElement( S.pop() );
        };
        return T;
      }
      var R = "abbr|article|aside|audio|canvas|datalist|details|figcaption|figure|footer|header|hgroup|mark|meter|nav|output|progress|section|summary|time|video",
          S = / jQuery\d+="(?:\d+|null)"/g,
          U = /^\s+/,
          X = /<(?!area|br|col|embed|hr|img|input|link|meta|param)(([\w:]+)[^>]*)\/>/ig,
          W = /<([\w:]+)/,
          bk = /<tbody/i,
          bi = /<|&#?\w+;/,
          T = /<(?:script|style)/i,
          $ = /<(?:script|object|embed|option|style)/i,
          bb = new RegExp( "<(?:"+R+")","i" ),
          Y = /checked\s*(?:[^=]|=\s*.checked.)/i,
          bm = /\/(java|ecma)script/i,
          bn = /^\s*<!(?:\[CDATA\[|\-\-)/,
          V =  {
            option : [1,"<select multiple='multiple'>","</select>"],
            legend : [1,"<fieldset>","</fieldset>"],
            thead : [1,"<table>","</table>"],
            tr : [2,"<table><tbody>","</tbody></table>"],
            td : [3,"<table><tbody><tr>","</tr></tbody></table>"],
            col : [2,"<table><tbody></tbody><colgroup>","</colgroup></table>"],
            area : [1,"<map>","</map>"],
            _default : [0,"",""]
          },
          bd = bj( document );
      
      V.optgroup = V.option;
      
      V.tbody = V.tfoot = V.colgroup = V.caption = V.thead;
      
      V.th = V.td;
      
      if ( !e.support.htmlSerialize ){
        V._default = [1,"div<div>","</div>"];
      };
      
      e.fn.extend(  {
        text : function ( a ) {
          if ( e.isFunction( a ) ){
            return this.each( function ( b ) {
              var self = e( this );
              
              self.text( a.call( this,b,self.text() ) );
            });
          };
          
          if ( typeof a !== "object" && a !== undefined ){
            return this.empty().append( ( this[0] && this[0].ownerDocument || document ).createTextNode( a ) );
          };
          return e.text( this );
        },
        wrapAll : function ( a ) {
          if ( e.isFunction( a ) ){
            return this.each( function ( b ) {
              e( this ).wrapAll( a.call( this,b ) );
            });
          };
          
          if ( this[0] ){
            var b = e( a,this[0].ownerDocument ).eq( 0 ).clone( true );
            
            if ( this[0].parentNode ){
              b.insertBefore( this[0] );
            };
            
            b.map( function () {
              var a = this;
              
              while ( a.firstChild && a.firstChild.nodeType === 1 )a = a.firstChild;
              return a;
            }).append( this );
          };
          return this;
        },
        wrapInner : function ( a ) {
          if ( e.isFunction( a ) ){
            return this.each( function ( b ) {
              e( this ).wrapInner( a.call( this,b ) );
            });
          };
          return this.each( function () {
            var self = e( this ),
                b = self.contents();
            
            if ( b.length ){
              b.wrapAll( a );
            } else {
              self.append( a );
            };
          });
        },
        wrap : function ( b ) {
          var a = e.isFunction( b );
          return this.each( function ( c ) {
            e( this ).wrapAll( a?b.call( this,c ) : b );
          });
        },
        unwrap : function () {
          return this.parent().each( function () {
            if ( !e.nodeName( this,"body" ) ){
              e( this ).replaceWith( this.childNodes );
            };
          }).end();
        },
        append : function () {
          return this.domManip( arguments,true,
          function ( a ) {
            if ( this.nodeType === 1 ){
              this.appendChild( a );
            };
          });
        },
        prepend : function () {
          return this.domManip( arguments,true,
          function ( a ) {
            if ( this.nodeType === 1 ){
              this.insertBefore( a,this.firstChild );
            };
          });
        },
        before : function () {
          if ( this[0] && this[0].parentNode ){
            return this.domManip( arguments,false,
            function ( a ) {
              this.parentNode.insertBefore( a,this );
            });
          } else if ( arguments.length ){
            var a = e.clean( arguments );
            
            a.push.apply( a,this.toArray() );
            return this.pushStack( a,"before",arguments );
          };
        },
        after : function () {
          if ( this[0] && this[0].parentNode ){
            return this.domManip( arguments,false,
            function ( a ) {
              this.parentNode.insertBefore( a,this.nextSibling );
            });
          } else if ( arguments.length ){
            var a = this.pushStack( this,"after",arguments );
            
            a.push.apply( a,e.clean( arguments ) );
            return a;
          };
        },
        remove : function ( a,b ) {
          for ( var c = 0,d;( d = this[c] ) != null;c ++  )
          if ( !a || e.filter( a,[d] ).length ){
            if ( !b && d.nodeType === 1 ){
              e.cleanData( d.getElementsByTagName( "*" ) );
              
              e.cleanData( [d] );
            };
            
            if ( d.parentNode ){
              d.parentNode.removeChild( d );
            };
          };
          return this;
        },
        empty : function () {
          for ( var a = 0,b;( b = this[a] ) != null;a ++  ){
            if ( b.nodeType === 1 ){
              e.cleanData( b.getElementsByTagName( "*" ) );
            };
            
            while ( b.firstChild )b.removeChild( b.firstChild );
          };
          return this;
        },
        clone : function ( a,b ) {
          a = a == null?false : a;
          
          b = b == null?a : b;
          return this.map( function () {
            return e.clone( this,a,b );
          });
        },
        html : function ( a ) {
          if ( a === undefined ){
            return this[0] && this[0].nodeType === 1?this[0].innerHTML.replace( S,"" ) : null;
          } else if ( typeof a === "string" && !T.test( a ) && ( e.support.leadingWhitespace || !U.test( a ) ) && !V[( W.exec( a ) || ["",""] )[1].toLowerCase()] ){
            a = a.replace( X,"<$1></$2>" );
            
            try {
              for ( var Y = 0,Z = this.length;Y<Z;Y ++  )if ( this[Y].nodeType === 1 ){
                e.cleanData( this[Y].getElementsByTagName( "*" ) );
                
                this[Y].innerHTML = a;
              };
            } catch( e ){
              this.empty().append( a );
            };
          } else if ( e.isFunction( a ) ){
            this.each( function ( b ) {
              var self = e( this );
              
              self.html( a.call( this,b,self.html() ) );
            });
          } else {
            this.empty().append( a );
          };
          return this;
        },
        replaceWith : function ( a ) {
          if ( this[0] && this[0].parentNode ){
            if ( e.isFunction( a ) ){
              return this.each( function ( b ) {
                var self = e( this ),
                    c = self.html();
                
                self.replaceWith( a.call( this,b,c ) );
              });
            };
            
            if ( typeof a !== "string" ){
              a = e( a ).detach();
            };
            return this.each( function () {
              var b = this.nextSibling,
                  c = this.parentNode;
              
              e( this ).remove();
              
              if ( b ){
                e( b ).before( a );
              } else {
                e( c ).append( a );
              };
            });
          } else {
            return this.length?this.pushStack( e( e.isFunction( a )?a() : a ),"replaceWith",a ) : this;
          };
        },
        detach : function ( a ) {
          return this.remove( a,true );
        },
        domManip : function ( a,b,c ) {
          var $,
              bb,
              bc,
              bd,
              d = a[0],
              be = [];
          
          if ( !e.support.checkClone && arguments.length === 3 && typeof d === "string" && Y.test( d ) ){
            return this.each( function () {
              e( this ).domManip( a,b,c,true );
            });
          };
          
          if ( e.isFunction( d ) ){
            return this.each( function ( f ) {
              var self = e( this );
              
              a[0] = d.call( this,f,b?self.html() : undefined );
              
              self.domManip( a,b,c );
            });
          };
          
          if ( this[0] ){
            bd = d && d.parentNode;
            
            if ( e.support.parentNode && bd && bd.nodeType === 11 && bd.childNodes.length === this.length ){
              $ =  {
                fragment : bd
              };
            } else {
              $ = e.buildFragment( a,this,be );
            };
            
            bc = $.fragment;
            
            if ( bc.childNodes.length === 1 ){
              bb = bc = bc.firstChild;
            } else {
              bb = bc.firstChild;
            };
            
            if ( bb ){
              b = b && e.nodeName( bb,"tr" );
              
              for ( var bf = 0,bg = this.length,bh = bg-1;bf<bg;bf ++  )
              c.call( b?Z( this[bf],bb ) : this[bf],$.cacheable || ( bg>1 && bf<bh )?e.clone( bc,true,true ) : bc );
            };
            
            if ( be.length ){
              e.each( be,_ );
            };
          };
          return this;
        }
      });
      
      function Z( a,b ) {
        return e.nodeName( a,"table" )?( a.getElementsByTagName( "tbody" )[0] || a.appendChild( a.ownerDocument.createElement( "tbody" ) ) ) : a;
      }
      function bh( a,b ) {
        if ( b.nodeType !== 1 || !e.hasData( a ) ){
          return ;
        };
        
        var c,
            d,
            f,
            g = e._data( a ),
            h = e._data( b,g ),
            i = g.events;
        
        if ( i ){
          delete h.handle;
          
          h.events = {};
          
          for ( c in i )for ( d = 0 , f = i[c].length;d<f;d ++  )e.event.add( b,c+( i[c][d].namespace?"." : "" )+i[c][d].namespace,i[c][d],i[c][d].data );
        };
        
        if ( h.data ){
          h.data = e.extend( {},h.data );
        };
      }
      function bf( a,b ) {
        var c;
        
        if ( b.nodeType !== 1 ){
          return ;
        };
        
        if ( b.clearAttributes ){
          b.clearAttributes();
        };
        
        if ( b.mergeAttributes ){
          b.mergeAttributes( a );
        };
        
        c = b.nodeName.toLowerCase();
        
        if ( c === "object" ){
          b.outerHTML = a.outerHTML;
        } else if ( c === "input" && ( a.type === "checkbox" || a.type === "radio" ) ){
          if ( a.checked ){
            b.defaultChecked = b.checked = a.checked;
          };
          if ( b.value !== a.value ){
            b.value = a.value;
          };
        } else if ( c === "option" ){
          b.selected = a.defaultSelected;
        } else if ( c === "input" || c === "textarea" ){
          b.defaultValue = a.defaultValue;
        };
        
        b.removeAttribute( e.expando );
      }
      e.buildFragment = function ( bc,bd,be ) {
        var bf,
            bg,
            bh,
            bi,
            bj = bc[0];
        
        if ( bd && bd[0] ){
          bi = bd[0].ownerDocument || bd[0];
        };
        
        if ( !bi.createDocumentFragment ){
          bi = document;
        };
        
        if ( bc.length === 1 && typeof bj === "string" && bj.length<512 && bi === document && bj.charAt( 0 ) === "<" && !$.test( bj ) && ( e.support.checkClone || !Y.test( bj ) ) && ( e.support.html5Clone || !bb.test( bj ) ) ){
          bg = true;
          
          bh = e.fragments[bj];
          
          if ( bh && bh !== 1 ){
            bf = bh;
          };
        };
        
        if ( !bf ){
          bf = bi.createDocumentFragment();
          
          e.clean( bc,bi,bf,be );
        };
        
        if ( bg ){
          e.fragments[bj] = bh?bf : 1;
        };
        return  {
          fragment : bf,
          cacheable : bg
        };
      };
      
      e.fragments = {};
      
      e.each(  {
        appendTo : "append",
        prependTo : "prepend",
        insertBefore : "before",
        insertAfter : "after",
        replaceAll : "replaceWith"
      },
      function ( b,a ) {
        e.fn[b] = function ( c ) {
          var d = [],
              f = e( c ),
              g = this.length === 1 && this[0].parentNode;
          
          if ( g && g.nodeType === 11 && g.childNodes.length === 1 && f.length === 1 ){
            f[a]( this[0] );
            return this;
          } else {
            for ( var h = 0,i = f.length;h<i;h ++  ){
              var j = ( h>0?this.clone( true ) : this ).get();
              
              e( f[h] )[a]( j );
              
              d = d.concat( j );
            };
            return this.pushStack( d,b,f.selector );
          };
        };
      });
      
      function bg( a ) {
        if ( typeof a.getElementsByTagName !== "undefined" ){
          return a.getElementsByTagName( "*" );
        } else if ( typeof a.querySelectorAll !== "undefined" ){
          return a.querySelectorAll( "*" );
        } else {
          return [];
        };
      }
      function bc( a ) {
        if ( a.type === "checkbox" || a.type === "radio" ){
          a.defaultChecked = a.checked;
        };
      }
      function bl( bd ) {
        var be = ( bd.nodeName || "" ).toLowerCase();
        
        if ( be === "input" ){
          bc( bd );
        } else if ( be !== "script" && typeof bd.getElementsByTagName !== "undefined" ){
          e.grep( bd.getElementsByTagName( "input" ),bc );
        };
      }
      function be( be ) {
        var bf = document.createElement( "div" );
        
        bd.appendChild( bf );
        
        bf.innerHTML = be.outerHTML;
        return bf.firstChild;
      }
      e.extend(  {
        clone : function ( bi,bj,bk ) {
          var bl,
              bm,
              bn,
              bo = e.support.html5Clone || !bb.test( "<"+bi.nodeName )?bi.cloneNode( true ) : be( bi );
          
          if ( ( !e.support.noCloneEvent || !e.support.noCloneChecked ) && ( bi.nodeType === 1 || bi.nodeType === 11 ) && !e.isXMLDoc( bi ) ){
            bf( bi,bo );
            
            bl = bg( bi );
            
            bm = bg( bo );
            
            for ( bn = 0;bl[bn]; ++ bn )if ( bm[bn] ){
              bf( bl[bn],bm[bn] );
            };
          };
          
          if ( bj ){
            bh( bi,bo );
            
            if ( bk ){
              bl = bg( bi );
              
              bm = bg( bo );
              
              for ( bn = 0;bl[bn]; ++ bn )bh( bl[bn],bm[bn] );
            };
          };
          
          bl = bm = null;
          return bo;
        },
        clean : function ( bn,bo,bp,bq ) {
          var br;
          
          bo = bo || document;
          
          if ( typeof bo.createElement === "undefined" ){
            bo = bo.ownerDocument || bo[0] && bo[0].ownerDocument || document;
          };
          
          var bs = [],
              bt;
          
          for ( var bu = 0,bv;( bv = bn[bu] ) != null;bu ++  ){
            if ( typeof bv === "number" ){
              bv += "";
            };
            
            if ( !bv ){
              continue ;
            };
            
            if ( typeof bv === "string" ){
              if ( !bi.test( bv ) ){
                bv = bo.createTextNode( bv );
              } else {
                bv = bv.replace( X,"<$1></$2>" );
                
                var bw = ( W.exec( bv ) || ["",""] )[1].toLowerCase(),
                    bx = V[bw] || V._default,
                    by = bx[0],
                    bz = bo.createElement( "div" );
                if ( bo === document ){
                  bd.appendChild( bz );
                } else {
                  bj( bo ).appendChild( bz );
                };
                
                bz.innerHTML = bx[1]+bv+bx[2];
                
                while ( by --  )bz = bz.lastChild;
                if ( !e.support.tbody ){
                  var bA = bk.test( bv ),
                      bB = bw === "table" && !bA?bz.firstChild && bz.firstChild.childNodes : bx[1] === "<table>" && !bA?bz.childNodes : [];
                  
                  for ( bt = bB.length-1;bt >= 0; -- bt )if ( e.nodeName( bB[bt],"tbody" ) && !bB[bt].childNodes.length ){
                    bB[bt].parentNode.removeChild( bB[bt] );
                  };
                };
                if ( !e.support.leadingWhitespace && U.test( bv ) ){
                  bz.insertBefore( bo.createTextNode( U.exec( bv )[0] ),bz.firstChild );
                };
                
                bv = bz.childNodes;
              };
            };
            
            var bC;
            
            if ( !e.support.appendChecked ){
              if ( bv[0] && typeof ( bC = bv.length ) === "number" ){
                for ( bt = 0;bt<bC;bt ++  )bl( bv[bt] );
              } else {
                bl( bv );
              };
            };
            
            if ( bv.nodeType ){
              bs.push( bv );
            } else {
              bs = e.merge( bs,bv );
            };
          };
          
          if ( bp ){
            br = function ( a ) {
              return !a.type || bm.test( a.type );
            };
            
            for ( bu = 0;bs[bu];bu ++  )if ( bq && e.nodeName( bs[bu],"script" ) && ( !bs[bu].type || bs[bu].type.toLowerCase() === "text/javascript" ) ){
              bq.push( bs[bu].parentNode?bs[bu].parentNode.removeChild( bs[bu] ) : bs[bu] );
            } else {
              if ( bs[bu].nodeType === 1 ){
                var bD = e.grep( bs[bu].getElementsByTagName( "script" ),br );
                
                bs.splice.apply( bs,[bu+1,0].concat( bD ) );
              };
              
              bp.appendChild( bs[bu] );
            };
          };
          return bs;
        },
        cleanData : function ( a ) {
          var b,
              c,
              d = e.cache,
              f = e.event.special,
              g = e.support.deleteExpando;
          
          for ( var h = 0,i;( i = a[h] ) != null;h ++  ){
            if ( i.nodeName && e.noData[i.nodeName.toLowerCase()] ){
              continue ;
            };
            
            c = i[e.expando];
            
            if ( c ){
              b = d[c];
              
              if ( b && b.events ){
                for ( var j in b.events )
                if ( f[j] ){
                  e.event.remove( i,j );
                } else {
                  e.removeEvent( i,j,b.handle );
                };
                
                if ( b.handle ){
                  b.handle.elem = null;
                };
              };
              
              if ( g ){
                delete i[e.expando];
              } else if ( i.removeAttribute ){
                i.removeAttribute( e.expando );
              };
              
              delete d[c];
            };
          };
        }
      });
      
      function _( bo,bp ) {
        if ( bp.src ){
          e.ajax(  {
            url : bp.src,
            async : false,
            dataType : "script"
          });
        } else {
          e.globalEval( ( bp.text || bp.textContent || bp.innerHTML || "" ).replace( bn,"/*$0*/" ) );
        };
        
        if ( bp.parentNode ){
          bp.parentNode.removeChild( bp );
        };
      }
      var bu = /alpha\([^)]*\)/i,
          bt = /opacity=([^)]*)/,
          bv = /([A-Z]|^ms)/g,
          bs = /^-?\d+(?:px)?$/i,
          bw = /^-?\d/,
          bp = /^([\-+])=([\-+.\de]+)/,
          br =  {
            position : "absolute",
            visibility : "hidden",
            display : "block"
          },
          bx = ["Left","Right"],
          by = ["Top","Bottom"],
          bo,
          w8,
          y8;
      
      e.fn.css = function ( a,b ) {
        if ( arguments.length === 2 && b === undefined ){
          return this;
        };
        return e.access( this,a,b,true,
        function ( a,b,c ) {
          return c !== undefined?e.style( a,b,c ) : e.css( a,b );
        });
      };
      
      e.extend(  {
        cssHooks :  {
          opacity :  {
            get : function ( bp,bq ) {
              if ( bq ){
                var br = bo( bp,"opacity","opacity" );
                return br === ""?"1" : br;
              } else {
                return bp.style.opacity;
              };
            }
          }
        },
        cssNumber :  {
          "fillOpacity" : true,
          "fontWeight" : true,
          "lineHeight" : true,
          "opacity" : true,
          "orphans" : true,
          "widows" : true,
          "zIndex" : true,
          "zoom" : true
        },
        cssProps :  {
          "float" : e.support.cssFloat?"cssFloat" : "styleFloat"
        },
        style : function ( bq,br,bs,bt ) {
          if ( !bq || bq.nodeType === 3 || bq.nodeType === 8 || !bq.style ){
            return ;
          };
          
          var bu,
              bv,
              bw = e.camelCase( br ),
              bx = bq.style,
              by = e.cssHooks[bw];
          
          br = e.cssProps[bw] || bw;
          
          if ( bs !== undefined ){
            bv = typeof bs;
            
            if ( bv === "string" && ( bu = bp.exec( bs ) ) ){
              bs = ( +( bu[1]+1 )*+bu[2] )+parseFloat( e.css( bq,br ) );
              
              bv = "number";
            };
            
            if ( bs == null || bv === "number" && isNaN( bs ) ){
              return ;
            };
            
            if ( bv === "number" && !e.cssNumber[bw] ){
              bs += "px";
            };
            
            if ( !by || !( "set" in by ) || ( bs = by.set( bq,bs ) ) !== undefined ){
              try {
                bx[br] = bs;
              } catch( e ){
                
              };
            };
          } else {
            if ( by && "get" in by && ( bu = by.get( bq,false,bt ) ) !== undefined ){
              return bu;
            };
            return bx[br];
          };
        },
        css : function ( a,b,c ) {
          var d,
              f;
          
          b = e.camelCase( b );
          
          f = e.cssHooks[b];
          
          b = e.cssProps[b] || b;
          
          if ( b === "cssFloat" ){
            b = "float";
          };
          
          if ( f && "get" in f && ( d = f.get( a,true,c ) ) !== undefined ){
            return d;
          } else if ( bo ){
            return bo( a,b );
          };
        },
        swap : function ( a,b,c ) {
          var d = {};
          
          for ( var e in b ){
            d[e] = a.style[e];
            
            a.style[e] = b[e];
          };
          
          c.call( a );
          
          for ( e in b )a.style[e] = d[e];
        }
      });
      
      e.curCSS = e.css;
      
      e.each( ["height","width"],
      function ( bt,a ) {
        e.cssHooks[a] =  {
          get : function ( c,f,d ) {
            var b;
            
            if ( f ){
              if ( c.offsetWidth !== 0 ){
                return bq( c,a,d );
              } else {
                e.swap( c,br,
                function () {
                  b = bq( c,a,d );
                });
              };
              return b;
            };
          },
          set : function ( a,b ) {
            if ( bs.test( b ) ){
              b = parseFloat( b );
              
              if ( b >= 0 ){
                return b+"px";
              };
            } else {
              return b;
            };
          }
        };
      });
      
      if ( !e.support.opacity ){
        e.cssHooks.opacity =  {
          get : function ( bu,bv ) {
            return bt.test( ( bv && bu.currentStyle?bu.currentStyle.filter : bu.style.filter ) || "" )?( parseFloat( RegExp.$1 )/100 )+"" : bv?"1" : "";
          },
          set : function ( bv,bw ) {
            var bx = bv.style,
                by = bv.currentStyle,
                bz = e.isNumeric( bw )?"alpha(opacity="+bw*100+")" : "",
                bA = by && by.filter || bx.filter || "";
            
            bx.zoom = 1;
            
            if ( bw >= 1 && e.trim( bA.replace( bu,"" ) ) === "" ){
              bx.removeAttribute( "filter" );
              
              if ( by && !by.filter ){
                return ;
              };
            };
            
            bx.filter = bu.test( bA )?bA.replace( bu,bz ) : bA+" "+bz;
          }
        };
      };
      
      e( function () {
        if ( !e.support.reliableMarginRight ){
          e.cssHooks.marginRight =  {
            get : function ( c,a ) {
              var b;
              
              e.swap( c, {
                "display" : "inline-block"
              },
              function () {
                if ( a ){
                  b = bo( c,"margin-right","marginRight" );
                } else {
                  b = c.style.marginRight;
                };
              });
              return b;
            }
          };
        };
      });
      
      if ( document.defaultView && document.defaultView.getComputedStyle ){
        w8 = function ( bw,bx ) {
          var by,
              bz,
              bA;
          
          bx = bx.replace( bv,"-$1" ).toLowerCase();
          
          if ( ( bz = bw.ownerDocument.defaultView ) && ( bA = bz.getComputedStyle( bw,null ) ) ){
            by = bA.getPropertyValue( bx );
            
            if ( by === "" && !e.contains( bw.ownerDocument.documentElement,bw ) ){
              by = e.style( bw,bx );
            };
          };
          return by;
        };
      };
      
      if ( document.documentElement.currentStyle ){
        y8 = function ( bx,by ) {
          var bz,
              bA,
              bB,
              bC = bx.currentStyle && bx.currentStyle[by],
              bD = bx.style;
          
          if ( bC === null && bD && ( bB = bD[by] ) ){
            bC = bB;
          };
          
          if ( !bs.test( bC ) && bw.test( bC ) ){
            bz = bD.left;
            
            bA = bx.runtimeStyle && bx.runtimeStyle.left;
            
            if ( bA ){
              bx.runtimeStyle.left = bx.currentStyle.left;
            };
            
            bD.left = by === "fontSize"?"1em" : ( bC || 0 );
            
            bC = bD.pixelLeft+"px";
            
            bD.left = bz;
            
            if ( bA ){
              bx.runtimeStyle.left = bA;
            };
          };
          return bC === ""?"auto" : bC;
        };
      };
      
      bo = w8 || y8;
      
      function bq( bz,bA,bB ) {
        var bC = bA === "width"?bz.offsetWidth : bz.offsetHeight,
            bD = bA === "width"?bx : by,
            bE = 0,
            bF = bD.length;
        
        if ( bC>0 ){
          if ( bB !== "border" ){
            for ( ;bE<bF;bE ++  ){
              if ( !bB ){
                bC -= parseFloat( e.css( bz,"padding"+bD[bE] ) ) || 0;
              };
              
              if ( bB === "margin" ){
                bC += parseFloat( e.css( bz,bB+bD[bE] ) ) || 0;
              } else {
                bC -= parseFloat( e.css( bz,"border"+bD[bE]+"Width" ) ) || 0;
              };
            };
          };
          return bC+"px";
        };
        
        bC = bo( bz,bA,bA );
        
        if ( bC<0 || bC == null ){
          bC = bz.style[bA] || 0;
        };
        
        bC = parseFloat( bC ) || 0;
        
        if ( bB ){
          for ( ;bE<bF;bE ++  ){
            bC += parseFloat( e.css( bz,"padding"+bD[bE] ) ) || 0;
            
            if ( bB !== "padding" ){
              bC += parseFloat( e.css( bz,"border"+bD[bE]+"Width" ) ) || 0;
            };
            
            if ( bB === "margin" ){
              bC += parseFloat( e.css( bz,bB+bD[bE] ) ) || 0;
            };
          };
        };
        return bC+"px";
      }
      if ( e.expr && e.expr.filters ){
        e.expr.filters.hidden = function ( a ) {
          var b = a.offsetWidth,
              c = a.offsetHeight;
          return ( b === 0 && c === 0 ) || ( !e.support.reliableHiddenOffsets && ( ( a.style && a.style.display ) || e.css( a,"display" ) ) === "none" );
        };
        
        e.expr.filters.visible = function ( a ) {
          return !e.expr.filters.hidden( a );
        };
      };
      
      var bV = /%20/g,
          bW = /\[\]$/,
          bG = /\r?\n/g,
          bI = /#.*$/,
          bR = /^(.*?):[ \t]*([^\r\n]*)\r?$/mg,
          bF = /^(?:color|date|datetime|datetime-local|email|hidden|month|number|password|range|search|tel|text|time|url|week)$/i,
          A8 = /^(?:about|app|app\-storage|.+\-extension|file|res|widget):$/,
          bM = /^(?:GET|HEAD)$/,
          bJ = /^\/\//,
          bN = /\?/,
          bD = /<script\b[^<]*(?:(?!<\/script>)<[^<]*)*<\/script>/gi,
          bE = /^(?:select|textarea)/i,
          bz = /\s+/,
          bO = /([?&])_=[^&]*/,
          bL = /^([\w\+\.\-]+:)(?:\/\/([^\/?#:]*)(?::(\d+))?)?/,
          bC = e.fn.load,
          bA = {},
          bQ = {},
          C8,
          bK,
          bP = ["*/"]+["*"];
      
      try {
        C8 = u8.href;
      } catch( e ){
        C8 = document.createElement( "a" );
        
        C8.href = "";
        
        C8 = C8.href;
      };
      
      bK = bL.exec( C8.toLowerCase() ) || [];
      
      function E8( a ) {
        return function ( b,c ) {
          if ( typeof b !== "string" ){
            c = b;
            
            b = "*";
          };
          
          if ( e.isFunction( c ) ){
            var d = b.toLowerCase().split( bz ),
                f = 0,
                g = d.length,
                h,
                i,
                j;
            
            for ( ;f<g;f ++  ){
              h = d[f];
              
              j = /^\+/.test( h );
              
              if ( j ){
                h = h.substr( 1 ) || "*";
              };
              
              i = a[h] = a[h] || [];
              
              i[j?"unshift" : "push"]( c );
            };
          };
        };
      }
      function bB( bC,bD,bE,bF,bG,bH ) {
        bG = bG || bD.dataTypes[0];
        
        bH = bH || {};
        
        bH[bG] = true;
        
        var bI = bC[bG],
            bJ = 0,
            bK = bI?bI.length : 0,
            bL = ( bC === bA ),
            bM;
        
        for ( ;bJ<bK && ( bL || !bM );bJ ++  ){
          bM = bI[bJ]( bD,bE,bF );
          
          if ( typeof bM === "string" ){
            if ( !bL || bH[bM] ){
              bM = undefined;
            } else {
              bD.dataTypes.unshift( bM );
              
              bM = bB( bC,bD,bE,bF,bM,bH );
            };
          };
        };
        
        if ( ( bL || !bM ) && !bH["*"] ){
          bM = bB( bC,bD,bE,bF,"*",bH );
        };
        return bM;
      }
      function bH( a,b ) {
        var c,
            d,
            f = e.ajaxSettings.flatOptions || {};
        
        for ( c in b )if ( b[c] !== undefined ){
          ( f[c]?a : ( d || ( d = {} ) ) )[c] = b[c];
        };
        
        if ( d ){
          e.extend( true,a,d );
        };
      }
      e.fn.extend(  {
        load : function ( bE,bF,b ) {
          if ( typeof bE !== "string" && bC ){
            return bC.apply( this,arguments );
          } else if ( !this.length ){
            return this;
          };
          
          var bG = bE.indexOf( " " );
          
          if ( bG >= 0 ){
            var a = bE.slice( bG,bE.length );
            
            bE = bE.slice( 0,bG );
          };
          
          var bH = "GET";
          
          if ( bF ){
            if ( e.isFunction( bF ) ){
              b = bF;
              
              bF = undefined;
            } else if ( typeof bF === "object" ){
              bF = e.param( bF,e.ajaxSettings.traditional );
              
              bH = "POST";
            };
          };
          
          var self = this;
          
          e.ajax(  {
            url : bE,
            type : bH,
            dataType : "html",
            data : bF,
            complete : function ( d,f,c ) {
              c = d.responseText;
              
              if ( d.isResolved() ){
                d.done( function ( d ) {
                  c = d;
                });
                
                self.html( a?e( "<div>" ).append( c.replace( bD,"" ) ).find( a ) : c );
              };
              
              if ( b ){
                self.each( b,[c,f,d] );
              };
            }
          });
          return this;
        },
        serialize : function () {
          return e.param( this.serializeArray() );
        },
        serializeArray : function () {
          return this.map( function () {
            return this.elements?e.makeArray( this.elements ) : this;
          }).filter( function () {
            return this.name && !this.disabled && ( this.checked || bE.test( this.nodeName ) || bF.test( this.type ) );
          }).map( function ( b,a ) {
            var c = e( this ).val();
            return c == null?null : e.isArray( c )?e.map( c,
            function ( b,c ) {
              return  {
                name : a.name,
                value : b.replace( bG,"\r\n" )
              };
            }) :  {
              name : a.name,
              value : c.replace( bG,"\r\n" )
            };
          }).get();
        }
      });
      
      e.each( "ajaxStart ajaxStop ajaxComplete ajaxError ajaxSuccess ajaxSend".split( " " ),
      function ( b,a ) {
        e.fn[a] = function ( b ) {
          return this.on( a,b );
        };
      });
      
      e.each( ["get","post"],
      function ( b,a ) {
        e[a] = function ( b,c,d,f ) {
          if ( e.isFunction( c ) ){
            f = f || d;
            
            d = c;
            
            c = undefined;
          };
          return e.ajax(  {
            type : a,
            url : b,
            data : c,
            success : d,
            dataType : f
          });
        };
      });
      
      e.extend(  {
        getScript : function ( a,b ) {
          return e.get( a,undefined,b,"script" );
        },
        getJSON : function ( a,b,c ) {
          return e.get( a,b,c,"json" );
        },
        ajaxSetup : function ( bI,bJ ) {
          if ( bJ ){
            bH( bI,e.ajaxSettings );
          } else {
            bJ = bI;
            
            bI = e.ajaxSettings;
          };
          
          bH( bI,bJ );
          return bI;
        },
        ajaxSettings :  {
          url : C8,
          isLocal : A8.test( bK[1] ),
          global : true,
          type : "GET",
          contentType : "application/x-www-form-urlencoded",
          processData : true,
          async : true,
          accepts :  {
            xml : "application/xml, text/xml",
            html : "text/html",
            text : "text/plain",
            json : "application/json, text/javascript",
            "*" : bP
          },
          contents :  {
            xml : /xml/,
            html : /html/,
            json : /json/
          },
          responseFields :  {
            xml : "responseXML",
            text : "responseText"
          },
          converters :  {
            "* text" : a.String,
            "text html" : true,
            "text json" : e.parseJSON,
            "text xml" : e.parseXML
          },
          flatOptions :  {
            context : true,
            url : true
          }
        },
        ajaxPrefilter : E8( bA ),
        ajaxTransport : E8( bQ ),
        ajax : function ( bU,bV ) {
          if ( typeof bU === "object" ){
            bV = bU;
            
            bU = undefined;
          };
          
          bV = bV || {};
          
          var g = e.ajaxSetup( {},bV ),
              n = g.context || g,
              q = n !== g && ( n.nodeType || n instanceof e )?e( n ) : e.event,
              m = e.Deferred(),
              r = e.Callbacks( "once memory" ),
              o = g.statusCode || {},
              l,
              c = {},
              b = {},
              d,
              f,
              h,
              j,
              bW,
              a = 0,
              p,
              bX,
              k =  {
                readyState : 0,
                setRequestHeader : function ( d,e ) {
                  if ( !a ){
                    var f = d.toLowerCase();
                    
                    d = b[f] = b[f] || d;
                    
                    c[d] = e;
                  };
                  return this;
                },
                getAllResponseHeaders : function () {
                  return a === 2?d : null;
                },
                getResponseHeader : function ( g ) {
                  var h;
                  
                  if ( a === 2 ){
                    if ( !f ){
                      f = {};
                      
                      while ( ( h = bR.exec( d ) ) )f[h[1].toLowerCase()] = h[2];
                    };
                    
                    h = f[g.toLowerCase()];
                  };
                  return h === undefined?null : h;
                },
                overrideMimeType : function ( h ) {
                  if ( !a ){
                    g.mimeType = h;
                  };
                  return this;
                },
                abort : function ( j ) {
                  j = j || "abort";
                  
                  if ( h ){
                    h.abort( j );
                  };
                  
                  i( 0,j );
                  return this;
                }
              };
          
          function i( s,t,u,v ) {
            if ( a === 2 ){
              return ;
            };
            
            a = 2;
            
            if ( j ){
              clearTimeout( j );
            };
            
            h = undefined;
            
            d = v || "";
            
            k.readyState = s>0?4 : 0;
            
            var w,
                x,
                y,
                z = t,
                A = u?bS( g,k,u ) : undefined,
                B,
                C;
            
            if ( s >= 200 && s<300 || s === 304 ){
              if ( g.ifModified ){
                if ( ( B = k.getResponseHeader( "Last-Modified" ) ) ){
                  e.lastModified[l] = B;
                };
                
                if ( ( C = k.getResponseHeader( "Etag" ) ) ){
                  e.etag[l] = C;
                };
              };
              
              if ( s === 304 ){
                z = "notmodified";
                
                w = true;
              } else {
                try {
                  x = bT( g,A );
                  
                  z = "success";
                  
                  w = true;
                } catch( e ){
                  z = "parsererror";
                  
                  y = e;
                };
              };
            } else {
              y = z;
              if ( !z || s ){
                z = "error";
                if ( s<0 ){
                  s = 0;
                };
              };
            };
            
            k.status = s;
            
            k.statusText = ""+( t || z );
            
            if ( w ){
              m.resolveWith( n,[x,z,k] );
            } else {
              m.rejectWith( n,[k,z,y] );
            };
            
            k.statusCode( o );
            
            o = undefined;
            
            if ( p ){
              q.trigger( "ajax"+( w?"Success" : "Error" ),[k,g,w?x : y] );
            };
            
            r.fireWith( n,[k,z] );
            
            if ( p ){
              q.trigger( "ajaxComplete",[k,g] );
              
              if ( !(  -- e.active ) ){
                e.event.trigger( "ajaxStop" );
              };
            };
          }
          m.promise( k );
          
          k.success = k.done;
          
          k.error = k.fail;
          
          k.complete = r.add;
          
          k.statusCode = function ( b ) {
            if ( b ){
              var c;
              
              if ( a<2 ){
                for ( c in b )o[c] = [o[c],b[c]];
              } else {
                c = b[k.status];
                
                k.then( c,c );
              };
            };
            return this;
          };
          
          g.url = ( ( bU || g.url )+"" ).replace( bI,"" ).replace( bJ,bK[1]+"//" );
          
          g.dataTypes = e.trim( g.dataType || "*" ).toLowerCase().split( bz );
          
          if ( g.crossDomain == null ){
            bW = bL.exec( g.url.toLowerCase() );
            
            g.crossDomain = !!( bW && ( bW[1] != bK[1] || bW[2] != bK[2] || ( bW[3] || ( bW[1] === "http:"?80 : 443 ) ) != ( bK[3] || ( bK[1] === "http:"?80 : 443 ) ) ) );
          };
          
          if ( g.data && g.processData && typeof g.data !== "string" ){
            g.data = e.param( g.data,g.traditional );
          };
          
          bB( bA,g,bV,k );
          
          if ( a === 2 ){
            return false;
          };
          
          p = g.global;
          
          g.type = g.type.toUpperCase();
          
          g.hasContent = !bM.test( g.type );
          
          if ( p && e.active ++  === 0 ){
            e.event.trigger( "ajaxStart" );
          };
          
          if ( !g.hasContent ){
            if ( g.data ){
              g.url += ( bN.test( g.url )?"&" : "?" )+g.data;
              
              delete g.data;
            };
            
            l = g.url;
            
            if ( g.cache === false ){
              var bY = e.now(),
                  bZ = g.url.replace( bO,"$1_="+bY );
              
              g.url = bZ+( ( bZ === g.url )?( bN.test( g.url )?"&" : "?" )+"_="+bY : "" );
            };
          };
          
          if ( g.data && g.hasContent && g.contentType !== false || bV.contentType ){
            k.setRequestHeader( "Content-Type",g.contentType );
          };
          
          if ( g.ifModified ){
            l = l || g.url;
            
            if ( e.lastModified[l] ){
              k.setRequestHeader( "If-Modified-Since",e.lastModified[l] );
            };
            
            if ( e.etag[l] ){
              k.setRequestHeader( "If-None-Match",e.etag[l] );
            };
          };
          
          k.setRequestHeader( "Accept",g.dataTypes[0] && g.accepts[g.dataTypes[0]]?g.accepts[g.dataTypes[0]]+( g.dataTypes[0] !== "*"?", "+bP+"; q=0.01" : "" ) : g.accepts["*"] );
          
          for ( bX in g.headers )k.setRequestHeader( bX,g.headers[bX] );
          
          if ( g.beforeSend && ( g.beforeSend.call( n,k,g ) === false || a === 2 ) ){
            k.abort();
            return false;
          };
          
          for ( bX in  {
            success : 1,
            error : 1,
            complete : 1
          })k[bX]( g[bX] );
          
          h = bB( bQ,g,bV,k );
          
          if ( !h ){
            i( -1,"No Transport" );
          } else {
            k.readyState = 1;
            if ( p ){
              q.trigger( "ajaxSend",[k,g] );
            };
            if ( g.async && g.timeout>0 ){
              j = setTimeout( function () {
                k.abort( "timeout" );
              },g.timeout );
            };
            
            try {
              a = 1;
              
              h.send( c,i );
            } catch( e ){
              if ( a<2 ){
                i( -1,e );
              } else {
                throw e;
              };
            };
          };
          return k;
        },
        param : function ( bW,bX ) {
          var a = [],
              b = function ( b,c ) {
                c = e.isFunction( c )?c() : c;
                
                a[a.length] = encodeURIComponent( b )+"="+encodeURIComponent( c );
              };
          
          if ( bX === undefined ){
            bX = e.ajaxSettings.traditional;
          };
          
          if ( e.isArray( bW ) || ( bW.jquery && !e.isPlainObject( bW ) ) ){
            e.each( bW,
            function () {
              b( this.name,this.value );
            });
          } else {
            for ( var bY in bW )
            bU( bY,bW[bY],bX,b );
          };
          return a.join( "&" ).replace( bV,"+" );
        }
      });
      
      function bU( b,bX,a,c ) {
        if ( e.isArray( bX ) ){
          e.each( bX,
          function ( d,f ) {
            if ( a || bW.test( b ) ){
              c( b,f );
            } else {
              bU( b+"["+( typeof f === "object" || e.isArray( f )?d : "" )+"]",f,a,c );
            };
          });
        } else if ( !a && bX != null && typeof bX === "object" ){
          for ( var bY in bX )
          bU( b+"["+bY+"]",bX[bY],a,c );
        } else {
          c( b,bX );
        };
      }
      e.extend(  {
        active : 0,
        lastModified : {},
        etag : {}
      });
      
      function bS( a,b,c ) {
        var d = a.contents,
            e = a.dataTypes,
            f = a.responseFields,
            g,
            h,
            i,
            j;
        
        for ( h in f )if ( h in c ){
          b[f[h]] = c[h];
        };
        
        while ( e[0] === "*" ){
          e.shift();
          
          if ( g === undefined ){
            g = a.mimeType || b.getResponseHeader( "content-type" );
          };
        };
        
        if ( g ){
          for ( h in d )if ( d[h] && d[h].test( g ) ){
            e.unshift( h );
            break;
          };
        };
        
        if ( e[0] in c ){
          i = e[0];
        } else {
          for ( h in c ){
            if ( !e[0] || a.converters[h+" "+e[0]] ){
              i = h;
              break;
            };
            if ( !j ){
              j = h;
            };
          };
          
          i = i || j;
        };
        
        if ( i ){
          if ( i !== e[0] ){
            e.unshift( i );
          };
          return c[i];
        };
      }
      function bT( a,b ) {
        if ( a.dataFilter ){
          b = a.dataFilter( b,a.dataType );
        };
        
        var c = a.dataTypes,
            d = {},
            f,
            g,
            h = c.length,
            i,
            j = c[0],
            k,
            l,
            m,
            n,
            o;
        
        for ( f = 1;f<h;f ++  ){
          if ( f === 1 ){
            for ( g in a.converters )if ( typeof g === "string" ){
              d[g.toLowerCase()] = a.converters[g];
            };
          };
          
          k = j;
          
          j = c[f];
          
          if ( j === "*" ){
            j = k;
          } else if ( k !== "*" && k !== j ){
            l = k+" "+j;
            
            m = d[l] || d["* "+j];
            if ( !m ){
              o = undefined;
              
              for ( n in d ){
                i = n.split( " " );
                if ( i[0] === k || i[0] === "*" ){
                  o = d[i[1]+" "+j];
                  if ( o ){
                    n = d[n];
                    if ( n === true ){
                      m = o;
                    } else if ( o === true ){
                      m = n;
                    };
                    break;
                  };
                };
              };
            };
            if ( !( m || o ) ){
              e.error( "No conversion from "+l.replace( " "," to " ) );
            };
            if ( m !== true ){
              b = m?m( b ) : o( n( b ) );
            };
          };
        };
        return b;
      }
      var bX = e.now(),
          bY = /(\=)\?(&|$)|\?\?/i;
      
      e.ajaxSetup(  {
        jsonp : "callback",
        jsonpCallback : function () {
          return e.expando+"_"+( bX ++  );
        }
      });
      
      e.ajaxPrefilter( "json jsonp",
      function ( bZ,b_,b$ ) {
        var b0 = bZ.contentType === "application/x-www-form-urlencoded" && ( typeof bZ.data === "string" );
        
        if ( bZ.dataTypes[0] === "jsonp" || bZ.jsonp !== false && ( bY.test( bZ.url ) || b0 && bY.test( bZ.data ) ) ){
          var b,
              c = bZ.jsonpCallback = e.isFunction( bZ.jsonpCallback )?bZ.jsonpCallback() : bZ.jsonpCallback,
              d = a[c],
              b1 = bZ.url,
              b2 = bZ.data,
              b3 = "$1"+c+"$2";
          
          if ( bZ.jsonp !== false ){
            b1 = b1.replace( bY,b3 );
            
            if ( bZ.url === b1 ){
              if ( b0 ){
                b2 = b2.replace( bY,b3 );
              };
              
              if ( bZ.data === b2 ){
                b1 += ( /\?/.test( b1 )?"&" : "?" )+bZ.jsonp+"="+c;
              };
            };
          };
          
          bZ.url = b1;
          
          bZ.data = b2;
          
          a[c] = function ( c ) {
            b = [c];
          };
          
          b$.always( function () {
            a[c] = d;
            
            if ( b && e.isFunction( d ) ){
              a[c]( b[0] );
            };
          });
          
          bZ.converters["script json"] = function () {
            if ( !b ){
              e.error( c+" was not called" );
            };
            return b[0];
          };
          
          bZ.dataTypes[0] = "json";
          return "script";
        };
      });
      
      e.ajaxSetup(  {
        accepts :  {
          script : "text/javascript, application/javascript, application/ecmascript, application/x-ecmascript"
        },
        contents :  {
          script : /javascript|ecmascript/
        },
        converters :  {
          "text script" : function ( a ) {
            e.globalEval( a );
            return a;
          }
        }
      });
      
      e.ajaxPrefilter( "script",
      function ( a ) {
        if ( a.cache === undefined ){
          a.cache = false;
        };
        
        if ( a.crossDomain ){
          a.type = "GET";
          
          a.global = false;
        };
      });
      
      e.ajaxTransport( "script",
      function ( b ) {
        if ( b.crossDomain ){
          var a,
              c = document.head || document.getElementsByTagName( "head" )[0] || document.documentElement;
          return  {
            send : function ( e,d ) {
              a = document.createElement( "script" );
              
              a.async = "async";
              
              if ( b.scriptCharset ){
                a.charset = b.scriptCharset;
              };
              
              a.src = b.url;
              
              a.onload = a.onreadystatechange = function ( e,f ) {
                if ( f || !a.readyState || /loaded|complete/.test( a.readyState ) ){
                  a.onload = a.onreadystatechange = null;
                  
                  if ( c && a.parentNode ){
                    c.removeChild( a );
                  };
                  
                  a = undefined;
                  
                  if ( !f ){
                    d( 200,"success" );
                  };
                };
              };
              
              c.insertBefore( a,c.firstChild );
            },
            abort : function () {
              if ( a ){
                a.onload( 0,1 );
              };
            }
          };
        };
      });
      
      var b0 = a.ActiveXObject?function () {
            for ( var b_ in bZ )
            bZ[b_]( 0,1 );
          } : false,
          b1 = 0,
          bZ;
      
      function b_() {
        try {
          return new a.XMLHttpRequest();
        } catch( e ){
          
        };
      }
      function b$() {
        try {
          return new a.ActiveXObject( "Microsoft.XMLHTTP" );
        } catch( e ){
          
        };
      }
      e.ajaxSettings.xhr = a.ActiveXObject?function () {
        return !this.isLocal && b_() || b$();
      } : b_;
      
      !function ( a ) {
        e.extend( e.support, {
          ajax : !!a,
          cors : !!a && ( "withCredentials" in a )
        });
      }( e.ajaxSettings.xhr() );
      
      if ( e.support.ajax ){
        e.ajaxTransport( function ( b ) {
          if ( !b.crossDomain || e.support.cors ){
            var c;
            return  {
              send : function ( h,g ) {
                var d = b.xhr(),
                    f,
                    i;
                
                if ( b.username ){
                  d.open( b.type,b.url,b.async,b.username,b.password );
                } else {
                  d.open( b.type,b.url,b.async );
                };
                
                if ( b.xhrFields ){
                  for ( i in b.xhrFields )d[i] = b.xhrFields[i];
                };
                
                if ( b.mimeType && d.overrideMimeType ){
                  d.overrideMimeType( b.mimeType );
                };
                
                if ( !b.crossDomain && !h["X-Requested-With"] ){
                  h["X-Requested-With"] = "XMLHttpRequest";
                };
                
                try {
                  for ( i in h )d.setRequestHeader( i,h[i] );
                } catch( _ ){
                  
                };
                
                d.send( ( b.hasContent && b.data ) || null );
                
                c = function ( h,i ) {
                  var j,
                      k,
                      l,
                      m,
                      n;
                  
                  try {
                    if ( c && ( i || d.readyState === 4 ) ){
                      c = undefined;
                      
                      if ( f ){
                        d.onreadystatechange = e.noop;
                        
                        if ( b0 ){
                          delete bZ[f];
                        };
                      };
                      
                      if ( i ){
                        if ( d.readyState !== 4 ){
                          d.abort();
                        };
                      } else {
                        j = d.status;
                        
                        l = d.getAllResponseHeaders();
                        
                        m = {};
                        
                        n = d.responseXML;
                        if ( n && n.documentElement ){
                          m.xml = n;
                        };
                        
                        m.text = d.responseText;
                        
                        try {
                          k = d.statusText;
                        } catch( e ){
                          k = "";
                        };
                        if ( !j && b.isLocal && !b.crossDomain ){
                          j = m.text?200 : 404;
                        } else if ( j === 1223 ){
                          j = 204;
                        };
                      };
                    };
                  } catch( firefoxAccessException ){
                    if ( !i ){
                      g( -1,firefoxAccessException );
                    };
                  };
                  
                  if ( m ){
                    g( j,k,m,l );
                  };
                };
                
                if ( !b.async || d.readyState === 4 ){
                  c();
                } else {
                  f =  ++ b1;
                  if ( b0 ){
                    if ( !bZ ){
                      bZ = {};
                      
                      e( a ).unload( b0 );
                    };
                    
                    bZ[f] = c;
                  };
                  
                  d.onreadystatechange = c;
                };
              },
              abort : function () {
                if ( c ){
                  c( 0,1 );
                };
              }
            };
          };
        });
      };
      
      var i8 = {},
          k8,
          m8,
          b4 = /^(?:toggle|show|hide)$/,
          b5 = /^([+\-]=)?([\d+.\-]+)([a-z%]*)$/i,
          g8,
          c8 = [["height","marginTop","marginBottom","paddingTop","paddingBottom"],["width","marginLeft","marginRight","paddingLeft","paddingRight"],["opacity"]],
          b7;
      
      e.fn.extend(  {
        show : function ( b4,b5,b6 ) {
          var b7,
              c8;
          
          if ( b4 || b4 === 0 ){
            return this.animate( b2( "show",3 ),b4,b5,b6 );
          } else {
            for ( var e8 = 0,g8 = this.length;e8<g8;e8 ++  ){
              b7 = this[e8];
              if ( b7.style ){
                c8 = b7.style.display;
                if ( !e._data( b7,"olddisplay" ) && c8 === "none" ){
                  c8 = b7.style.display = "";
                };
                if ( c8 === "" && e.css( b7,"display" ) === "none" ){
                  e._data( b7,"olddisplay",b3( b7.nodeName ) );
                };
              };
            };
            
            for ( e8 = 0;e8<g8;e8 ++  ){
              b7 = this[e8];
              if ( b7.style ){
                c8 = b7.style.display;
                if ( c8 === "" || c8 === "none" ){
                  b7.style.display = e._data( b7,"olddisplay" ) || "";
                };
              };
            };
            return this;
          };
        },
        hide : function ( a,b,c ) {
          if ( a || a === 0 ){
            return this.animate( b2( "hide",3 ),a,b,c );
          } else {
            var d,
                f,
                g = 0,
                h = this.length;
            
            for ( ;g<h;g ++  ){
              d = this[g];
              if ( d.style ){
                f = e.css( d,"display" );
                if ( f !== "none" && !e._data( d,"olddisplay" ) ){
                  e._data( d,"olddisplay",f );
                };
              };
            };
            
            for ( g = 0;g<h;g ++  )if ( this[g].style ){
              this[g].style.display = "none";
            };
            return this;
          };
        },
        _toggle : e.fn.toggle,
        toggle : function ( b,c,d ) {
          var a = typeof b === "boolean";
          
          if ( e.isFunction( b ) && e.isFunction( c ) ){
            this._toggle.apply( this,arguments );
          } else if ( b == null || a ){
            this.each( function () {
              var c = a?b : e( this ).is( ":hidden" );
              
              e( this )[c?"show" : "hide"]();
            });
          } else {
            this.animate( b2( "toggle",3 ),b,c,d );
          };
          return this;
        },
        fadeTo : function ( a,b,c,d ) {
          return this.filter( ":hidden" ).css( "opacity",0 ).show().end().animate(  {
            opacity : b
          },a,c,d);
        },
        animate : function ( b,b6,b7,c8 ) {
          var a = e.speed( b6,b7,c8 );
          
          if ( e.isEmptyObject( b ) ){
            return this.each( a.complete,[false] );
          };
          
          b = e.extend( {},b );
          
          function e8() {
            if ( a.queue === false ){
              e._mark( this );
            };
            
            var c = e.extend( {},a ),
                d = this.nodeType === 1,
                f = d && e( this ).is( ":hidden" ),
                g,
                h,
                i,
                j,
                k,
                l,
                m,
                n,
                o;
            
            c.animatedProperties = {};
            
            for ( i in b ){
              g = e.camelCase( i );
              
              if ( i !== g ){
                b[g] = b[i];
                
                delete b[i];
              };
              
              h = b[g];
              
              if ( e.isArray( h ) ){
                c.animatedProperties[g] = h[1];
                
                h = b[g] = h[0];
              } else {
                c.animatedProperties[g] = c.specialEasing && c.specialEasing[g] || c.easing || 'swing';
              };
              
              if ( h === "hide" && f || h === "show" && !f ){
                return c.complete.call( this );
              };
              
              if ( d && ( g === "height" || g === "width" ) ){
                c.overflow = [this.style.overflow,this.style.overflowX,this.style.overflowY];
                
                if ( e.css( this,"display" ) === "inline" && e.css( this,"float" ) === "none" ){
                  if ( !e.support.inlineBlockNeedsLayout || b3( this.nodeName ) === "inline" ){
                    this.style.display = "inline-block";
                  } else {
                    this.style.zoom = 1;
                  };
                };
              };
            };
            
            if ( c.overflow != null ){
              this.style.overflow = "hidden";
            };
            
            for ( i in b ){
              j = new e.fx( this,c,i );
              
              h = b[i];
              
              if ( b4.test( h ) ){
                o = e._data( this,"toggle"+i ) || ( h === "toggle"?f?"show" : "hide" : 0 );
                
                if ( o ){
                  e._data( this,"toggle"+i,o === "show"?"hide" : "show" );
                  
                  j[o]();
                } else {
                  j[h]();
                };
              } else {
                k = b5.exec( h );
                
                l = j.cur();
                if ( k ){
                  m = parseFloat( k[2] );
                  
                  n = k[3] || ( e.cssNumber[i]?"" : "px" );
                  if ( n !== "px" ){
                    e.style( this,i,( m || 1 )+n );
                    
                    l = ( ( m || 1 )/j.cur() )*l;
                    
                    e.style( this,i,l+n );
                  };
                  if ( k[1] ){
                    m = ( ( k[1] === "-="?-1 : 1 )*m )+l;
                  };
                  
                  j.custom( l,m,n );
                } else {
                  j.custom( l,h,"" );
                };
              };
            };
            return true;
          }return a.queue === false?this.each( e8 ) : this.queue( a.queue,e8 );
        },
        stop : function ( b,c,a ) {
          if ( typeof b !== "string" ){
            a = c;
            
            c = b;
            
            b = undefined;
          };
          
          if ( c && b !== false ){
            this.queue( b || "fx",[] );
          };
          return this.each( function () {
            var c,
                d = false,
                f = e.timers,
                g = e._data( this );
            
            if ( !a ){
              e._unmark( true,this );
            };
            
            function h( b,c,d ) {
              var f = c[d];
              
              e.removeData( b,d,true );
              
              f.stop( a );
            }
            if ( b == null ){
              for ( c in g )if ( g[c] && g[c].stop && c.indexOf( ".run" ) === c.length-4 ){
                h( this,g,c );
              };
            } else if ( g[c = b+".run"] && g[c].stop ){
              h( this,g,c );
            };
            
            for ( c = f.length;c -- ; )if ( f[c].elem === this && ( b == null || f[c].queue === b ) ){
              if ( a ){
                f[c]( true );
              } else {
                f[c].saveState();
              };
              
              d = true;
              
              f.splice( c,1 );
            };
            
            if ( !( a && d ) ){
              e.dequeue( this,b );
            };
          });
        }
      });
      
      function e8() {
        setTimeout( b6,0 );
        return ( b7 = e.now() );
      }
      function b6() {
        b7 = undefined;
      }
      function b2( b,e8 ) {
        var a = {};
        
        e.each( c8.concat.apply( [],c8.slice( 0,e8 ) ),
        function () {
          a[this] = b;
        });
        return a;
      }
      e.each(  {
        slideDown : b2( "show",1 ),
        slideUp : b2( "hide",1 ),
        slideToggle : b2( "toggle",1 ),
        fadeIn :  {
          opacity : "show"
        },
        fadeOut :  {
          opacity : "hide"
        },
        fadeToggle :  {
          opacity : "toggle"
        }
      },
      function ( b,a ) {
        e.fn[b] = function ( b,c,d ) {
          return this.animate( a,b,c,d );
        };
      });
      
      e.extend(  {
        speed : function ( b,c,d ) {
          var a = b && typeof b === "object"?e.extend( {},b ) :  {
                complete : d || !d && c || e.isFunction( b ) && b,
                duration : b,
                easing : d && c || c && !e.isFunction( c ) && c
              };
          
          a.duration = e.fx.off?0 : typeof a.duration === "number"?a.duration : a.duration in e.fx.speeds?e.fx.speeds[a.duration] : e.fx.speeds._default;
          
          if ( a.queue == null || a.queue === true ){
            a.queue = "fx";
          };
          
          a.old = a.complete;
          
          a.complete = function ( b ) {
            if ( e.isFunction( a.old ) ){
              a.old.call( this );
            };
            
            if ( a.queue ){
              e.dequeue( this,a.queue );
            } else if ( b !== false ){
              e._unmark( this );
            };
          };
          return a;
        },
        easing :  {
          linear : function ( a,b,c,d ) {
            return c+d*a;
          },
          swing : function ( a,b,c,d ) {
            return ( ( -Math.cos( a*Math.PI )/2 )+0.5 )*d+c;
          }
        },
        timers : [],
        fx : function ( a,b,c ) {
          this.options = b;
          
          this.elem = a;
          
          this.prop = c;
          
          b.orig = b.orig || {};
        }
      });
      
      e.fx.prototype =  {
        update : function () {
          if ( this.options.step ){
            this.options.step.call( this.elem,this.now,this );
          };
          
          ( e.fx.step[this.prop] || e.fx.step._default )( this );
        },
        cur : function () {
          if ( this.elem[this.prop] != null && ( !this.elem.style || this.elem.style[this.prop] == null ) ){
            return this.elem[this.prop];
          };
          
          var a,
              b = e.css( this.elem,this.prop );
          return isNaN( a = parseFloat( b ) )?!b || b === "auto"?0 : b : a;
        },
        custom : function ( i8,k8,m8 ) {
          var self = this,
              o8 = e.fx;
          
          this.startTime = b7 || e8();
          
          this.end = k8;
          
          this.now = this.start = i8;
          
          this.pos = this.state = 0;
          
          this.unit = m8 || this.unit || ( e.cssNumber[this.prop]?"" : "px" );
          
          function q8( a ) {
            return self.step( a );
          }
          q8.queue = this.options.queue;
          
          q8.elem = this.elem;
          
          q8.saveState = function () {
            if ( self.options.hide && e._data( self.elem,"fxshow"+self.prop ) === undefined ){
              e._data( self.elem,"fxshow"+self.prop,self.start );
            };
          };
          
          if ( q8() && e.timers.push( q8 ) && !g8 ){
            g8 = setInterval( o8.tick,o8.interval );
          };
        },
        show : function () {
          var a = e._data( this.elem,"fxshow"+this.prop );
          
          this.options.orig[this.prop] = a || e.style( this.elem,this.prop );
          
          this.options.show = true;
          
          if ( a !== undefined ){
            this.custom( this.cur(),a );
          } else {
            this.custom( this.prop === "width" || this.prop === "height"?1 : 0,this.cur() );
          };
          
          e( this.elem ).show();
        },
        hide : function () {
          this.options.orig[this.prop] = e._data( this.elem,"fxshow"+this.prop ) || e.style( this.elem,this.prop );
          
          this.options.hide = true;
          
          this.custom( this.cur(),0 );
        },
        step : function ( c ) {
          var d,
              f,
              g,
              h = b7 || e8(),
              i = true,
              a = this.elem,
              b = this.options;
          
          if ( c || h >= b.duration+this.startTime ){
            this.now = this.end;
            
            this.pos = this.state = 1;
            
            this.update();
            
            b.animatedProperties[this.prop] = true;
            
            for ( d in b.animatedProperties )if ( b.animatedProperties[d] !== true ){
              i = false;
            };
            
            if ( i ){
              if ( b.overflow != null && !e.support.shrinkWrapBlocks ){
                e.each( ["","X","Y"],
                function ( c,d ) {
                  a.style["overflow"+d] = b.overflow[c];
                });
              };
              
              if ( b.hide ){
                e( a ).hide();
              };
              
              if ( b.hide || b.show ){
                for ( d in b.animatedProperties ){
                  e.style( a,d,b.orig[d] );
                  
                  e.removeData( a,"fxshow"+d,true );
                  
                  e.removeData( a,"toggle"+d,true );
                };
              };
              
              g = b.complete;
              
              if ( g ){
                b.complete = false;
                
                g.call( a );
              };
            };
            return false;
          } else {
            if ( b.duration == Infinity ){
              this.now = h;
            } else {
              f = h-this.startTime;
              
              this.state = f/b.duration;
              
              this.pos = e.easing[b.animatedProperties[this.prop]]( this.state,f,0,1,b.duration );
              
              this.now = this.start+( ( this.end-this.start )*this.pos );
            };
            
            this.update();
          };
          return true;
        }
      };
      
      e.extend( e.fx, {
        tick : function () {
          var a,
              b = e.timers,
              c = 0;
          
          for ( ;c<b.length;c ++  ){
            a = b[c];
            
            if ( !a() && b[c] === a ){
              b.splice( c -- ,1 );
            };
          };
          
          if ( !b.length ){
            e.fx.stop();
          };
        },
        interval : 13,
        stop : function () {
          clearInterval( g8 );
          
          g8 = null;
        },
        speeds :  {
          slow : 600,
          fast : 200,
          _default : 400
        },
        step :  {
          opacity : function ( a ) {
            e.style( a.elem,"opacity",a.now );
          },
          _default : function ( a ) {
            if ( a.elem.style && a.elem.style[a.prop] != null ){
              a.elem.style[a.prop] = a.now+a.unit;
            } else {
              a.elem[a.prop] = a.now;
            };
          }
        }
      });
      
      e.each( ["width","height"],
      function ( b,a ) {
        e.fx.step[a] = function ( b ) {
          e.style( b.elem,a,Math.max( 0,b.now )+b.unit );
        };
      });
      
      if ( e.expr && e.expr.filters ){
        e.expr.filters.animated = function ( a ) {
          return e.grep( e.timers,
          function ( b ) {
            return a === b.elem;
          }).length;
        };
      };
      
      function b3( o8 ) {
        if ( !i8[o8] ){
          var q8 = document.body,
              s8 = e( "<"+o8+">" ).appendTo( q8 ),
              u8 = s8.css( "display" );
          
          s8.remove();
          
          if ( u8 === "none" || u8 === "" ){
            if ( !k8 ){
              k8 = document.createElement( "iframe" );
              
              k8.frameBorder = k8.width = k8.height = 0;
            };
            
            q8.appendChild( k8 );
            
            if ( !m8 || !k8.createElement ){
              m8 = ( k8.contentWindow || k8.contentDocument ).document;
              
              m8.write( ( document.compatMode === "CSS1Compat"?"<!doctype html>" : "" )+"<html><body>" );
              
              m8.close();
            };
            
            s8 = m8.createElement( o8 );
            
            m8.body.appendChild( s8 );
            
            u8 = e.css( s8,"display" );
            
            q8.removeChild( k8 );
          };
          
          i8[o8] = u8;
        };
        return i8[o8];
      }
      var q8 = /^t(?:able|d|h)$/i,
          s8 = /^(?:body|html)$/i;
      
      if ( "getBoundingClientRect" in document.documentElement ){
        e.fn.offset = function ( a ) {
          var q8 = this[0],
              s8;
          
          if ( a ){
            return this.each( function ( b ) {
              e.offset.setOffset( this,a,b );
            });
          };
          
          if ( !q8 || !q8.ownerDocument ){
            return null;
          };
          
          if ( q8 === q8.ownerDocument.body ){
            return e.offset.bodyOffset( q8 );
          };
          
          try {
            s8 = q8.getBoundingClientRect();
          } catch( e ){
            
          };
          
          var u8 = q8.ownerDocument,
              w8 = u8.documentElement;
          
          if ( !s8 || !e.contains( w8,q8 ) ){
            return s8? {
              top : s8.top,
              left : s8.left
            } :  {
              top : 0,
              left : 0
            };
          };
          
          var y8 = u8.body,
              A8 = o8( u8 ),
              C8 = w8.clientTop || y8.clientTop || 0,
              E8 = w8.clientLeft || y8.clientLeft || 0,
              G8 = A8.pageYOffset || e.support.boxModel && w8.scrollTop || y8.scrollTop,
              I8 = A8.pageXOffset || e.support.boxModel && w8.scrollLeft || y8.scrollLeft,
              top = s8.top+G8-C8,
              K8 = s8.left+I8-E8;
          return  {
            top : top,
            left : K8
          };
        };
      } else {
        e.fn.offset = function ( a ) {
          var s8 = this[0];
          if ( a ){
            return this.each( function ( b ) {
              e.offset.setOffset( this,a,b );
            });
          };
          if ( !s8 || !s8.ownerDocument ){
            return null;
          };
          if ( s8 === s8.ownerDocument.body ){
            return e.offset.bodyOffset( s8 );
          };
          
          var u8,
              w8 = s8.offsetParent,
              y8 = s8,
              A8 = s8.ownerDocument,
              C8 = A8.documentElement,
              E8 = A8.body,
              G8 = A8.defaultView,
              I8 = G8?G8.getComputedStyle( s8,null ) : s8.currentStyle,
              top = s8.offsetTop,
              K8 = s8.offsetLeft;
          
          while ( ( s8 = s8.parentNode ) && s8 !== E8 && s8 !== C8 ){
            if ( e.support.fixedPosition && I8.position === "fixed" ){
              break;
            };
            
            u8 = G8?G8.getComputedStyle( s8,null ) : s8.currentStyle;
            
            top -= s8.scrollTop;
            
            K8 -= s8.scrollLeft;
            if ( s8 === w8 ){
              top += s8.offsetTop;
              
              K8 += s8.offsetLeft;
              if ( e.support.doesNotAddBorder && !( e.support.doesAddBorderForTableAndCells && q8.test( s8.nodeName ) ) ){
                top += parseFloat( u8.borderTopWidth ) || 0;
                
                K8 += parseFloat( u8.borderLeftWidth ) || 0;
              };
              
              y8 = w8;
              
              w8 = s8.offsetParent;
            };
            if ( e.support.subtractsBorderForOverflowNotVisible && u8.overflow !== "visible" ){
              top += parseFloat( u8.borderTopWidth ) || 0;
              
              K8 += parseFloat( u8.borderLeftWidth ) || 0;
            };
            
            I8 = u8;
          };
          if ( I8.position === "relative" || I8.position === "static" ){
            top += E8.offsetTop;
            
            K8 += E8.offsetLeft;
          };
          if ( e.support.fixedPosition && I8.position === "fixed" ){
            top += Math.max( C8.scrollTop,E8.scrollTop );
            
            K8 += Math.max( C8.scrollLeft,E8.scrollLeft );
          };
          return  {
            top : top,
            left : K8
          };
        };
      };
      
      e.offset =  {
        bodyOffset : function ( a ) {
          var top = a.offsetTop,
              b = a.offsetLeft;
          
          if ( e.support.doesNotIncludeMarginInBodyOffset ){
            top += parseFloat( e.css( a,"marginTop" ) ) || 0;
            
            b += parseFloat( e.css( a,"marginLeft" ) ) || 0;
          };
          return  {
            top : top,
            left : b
          };
        },
        setOffset : function ( a,b,c ) {
          var d = e.css( a,"position" );
          
          if ( d === "static" ){
            a.style.position = "relative";
          };
          
          var f = e( a ),
              g = f.offset(),
              h = e.css( a,"top" ),
              i = e.css( a,"left" ),
              j = ( d === "absolute" || d === "fixed" ) && e.inArray( "auto",[h,i] )>-1,
              k = {},
              l = {},
              m,
              n;
          
          if ( j ){
            l = f.position();
            
            m = l.top;
            
            n = l.left;
          } else {
            m = parseFloat( h ) || 0;
            
            n = parseFloat( i ) || 0;
          };
          
          if ( e.isFunction( b ) ){
            b = b.call( a,c,g );
          };
          
          if ( b.top != null ){
            k.top = ( b.top-g.top )+m;
          };
          
          if ( b.left != null ){
            k.left = ( b.left-g.left )+n;
          };
          
          if ( "using" in b ){
            b.using.call( a,k );
          } else {
            f.css( k );
          };
        }
      };
      
      e.fn.extend(  {
        position : function () {
          if ( !this[0] ){
            return null;
          };
          
          var u8 = this[0],
              w8 = this.offsetParent(),
              y8 = this.offset(),
              A8 = s8.test( w8[0].nodeName )? {
                top : 0,
                left : 0
              } : w8.offset();
          
          y8.top -= parseFloat( e.css( u8,"marginTop" ) ) || 0;
          
          y8.left -= parseFloat( e.css( u8,"marginLeft" ) ) || 0;
          
          A8.top += parseFloat( e.css( w8[0],"borderTopWidth" ) ) || 0;
          
          A8.left += parseFloat( e.css( w8[0],"borderLeftWidth" ) ) || 0;
          return  {
            top : y8.top-A8.top,
            left : y8.left-A8.left
          };
        },
        offsetParent : function () {
          return this.map( function () {
            var a = this.offsetParent || document.body;
            
            while ( a && ( !s8.test( a.nodeName ) && e.css( a,"position" ) === "static" ) )a = a.offsetParent;
            return a;
          });
        }
      });
      
      e.each( ["Left","Top"],
      function ( a,c ) {
        var b = "scroll"+c;
        
        e.fn[b] = function ( d ) {
          var f,
              c;
          
          if ( d === undefined ){
            f = this[0];
            
            if ( !f ){
              return null;
            };
            
            c = o8( f );
            return c?( "pageXOffset" in c )?c[a?"pageYOffset" : "pageXOffset"] : e.support.boxModel && c.document.documentElement[b] || c.document.body[b] : f[b];
          };
          return this.each( function () {
            c = o8( this );
            
            if ( c ){
              c.scrollTo( !a?d : e( c ).scrollLeft(),a?d : e( c ).scrollTop() );
            } else {
              this[b] = d;
            };
          });
        };
      });
      
      function o8( a ) {
        return e.isWindow( a )?a : a.nodeType === 9?a.defaultView || a.parentWindow : false;
      }
      e.each( ["Height","Width"],
      function ( c,b ) {
        var a = b.toLowerCase();
        
        e.fn["inner"+b] = function () {
          var b = this[0];
          return b?b.style?parseFloat( e.css( b,a,"padding" ) ) : this[a]() : null;
        };
        
        e.fn["outer"+b] = function ( b ) {
          var c = this[0];
          return c?c.style?parseFloat( e.css( c,a,b?"margin" : "border" ) ) : this[a]() : null;
        };
        
        e.fn[a] = function ( c ) {
          var d = this[0];
          
          if ( !d ){
            return c == null?null : this;
          };
          
          if ( e.isFunction( c ) ){
            return this.each( function ( d ) {
              var self = e( this );
              
              self[a]( c.call( this,d,self[a]() ) );
            });
          };
          
          if ( e.isWindow( d ) ){
            var f = d.document.documentElement["client"+b],
                g = d.document.body;
            return d.document.compatMode === "CSS1Compat" && f || g && g["client"+b] || f;
          } else if ( d.nodeType === 9 ){
            return Math.max( d.documentElement["client"+b],d.body["scroll"+b],d.documentElement["scroll"+b],d.body["offset"+b],d.documentElement["offset"+b] );
          } else if ( c === undefined ){
            var h = e.css( d,a ),
                i = parseFloat( h );
            return e.isNumeric( i )?i : h;
          } else {
            return this.css( a,typeof c === "string"?c : c+"px" );
          };
        };
      });
      
      a.jQuery = a.$ = e;
      
      if ( typeof define === "function" && define.amd && define.amd.jQuery ){
        define( "jquery",[],
        function () {
          return e;
        });
      };
    }( window );
  }();
}();
