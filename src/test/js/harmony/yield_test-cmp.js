!function() {
  
  var b = {};
  
  !function ( f,g,h,i ) {
    var c = f.prototype,
        d = g.prototype,
        j = h.prototype,
        k = i.prototype;
    
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
        var q = Math,
            g = q.max;
        
        var r = Array.prototype,
            d = r.slice;
        
        var a =  {
              getErrorMessage : function s( a ) {
                return ( a.message )?a.message : ( a.description )?a.description : a.toString();
              },
              exceptionHandler : function t( d,e,f ) {
                if ( b( f ) ){
                  this.throwException( f );
                } else {
                  this.throwException( new c( d,e,f ) );
                };
              },
              throwException : function u( a ) {
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
        
        function f( a,b,c ) {
          return Object.defineProperty( a,b, {
            configurable : true,
            enumerable : false,
            writable : true,
            value : c
          });
        };
        
        p.createUnenumProp = f;
        
        function v( a,b,c ) {
          return Object.defineProperty( a,b, {
            configurable : false,
            enumerable : false,
            writable : false,
            value : c
          });
        };
        
        p.constant = v;
        
        function w( e,f ) {
          return ( e )?d.call( e,f ) : [];
        };
        
        p.toArray = w;
        
        function e(  ){};
        
        function x( g,h,i ) {
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
        
        p.createGenerator = x;
        
        function s( a ) {
          return ( a.message )?a.message : ( a.description )?a.description : a.toString();
        }
        var u = p.throwException = a.throwException.bind( a );
        
        var t = p.exceptionHandler = a.exceptionHandler.bind( a );
        
        function y( a,b ) {
          for ( var c in b )
          a[c] = b[c];
          return a;
        };
        
        p.extend = y;
        
        function h( h ) {
          var i = g( h.length,this.length ),
              j = -1;
          
          while (  ++ j<i && h[j] === this[j] ){
            
          };
          return i === j;
        };
        
        function i() {
          return Array.prototype.slice.call( this );
        };
        
        function z( j,k ) {
          f( j,"length",k );
          
          f( j,"equal",h );
          
          f( j,"toArray",i );
          
          f( j,"toString",
          function () {
            return "[object Tuple]";
          });
          return Object.freeze( j );
        };
        
        p.createTuple = z;
        
        function A( a ) {
          if ( a.toString() === "[object Object]" ){
            f( a,"toString",
            function () {
              return "[object Record]";
            });
          };
          return Object.freeze( a );
        };
        
        p.createRecord = A;
        
        var B = p.extendPrototype = function ( a,b ) {
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
        
        var C = p.extendClass = ( a.hasProto )?function ( a,b ) {
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
        
        function D( n ) {
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
        
        p.getIterator = D;
        
        function E( a ) {
          return k in a;
        };
        
        p.hasIterator = E;
        
        var n = /StopIteration/;
        
        function b( o ) {
          return o === StopIteration || n.test( o );
        };
        
        p.isStopIteration = b;
        
        var o,
            F,
            G;
        
        if ( "WeakMap" in window ){
          o = new WeakMap();
          
          F = function ( self,p ) {
            var q = new p;
            
            f( q.constructor,"__is_private__",1 );
            
            o.set( self,q );
          };
          
          G = function ( self ) {
            if ( o.has( self ) ){
              return o.get( self );
            } else if ( self.constructor === "__is_private__" ){
              return self;
            };
          };
        } else {
          F = function ( self,a ) {
            if ( !self.__typeid__ ){
              var b = new a;
              
              f( b.constructor,"__is_private__",1 );
              
              f( self,"__private__",b );
            };
          };
          
          G = function ( self ) {
            if ( self.__private__ ){
              return self.__private__;
            } else if ( self.constructor === "__is_private__" ){
              return self;
            };
          };
        };
        
        p.createPrivateRecord = F;
        
        p.getPrivateRecord = G;
        
        function H( a ) {
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
        
        p.getSuper = H;
        
        function I( b,c,d,e ) {
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
        
        p.traitMixin = I;
        
        function J( b,c,d,e,f ) {
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
        
        p.classMixin = J;
        
        function K( b,c,d,e,f ) {
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
        
        p.checkRequirements = K;
        return p;
      }();
  
  if ( !( "StopIteration" in window ) ){
    window.StopIteration =  {
      toString : function c() {
        return "[object StopIteration]";
      }
    };
  };
  
  function d(  ) {
    var b = a.toArray( arguments,0 );
    
    var c = {};
    
    c.length = 0;
    
    Array.prototype.push.apply( c,b );
    
    a.createTuple( c,arguments.length );
    return c;
  };
  
  function e( b ) {
    return a.createRecord( b );
  };
  
  !function () {
    b['./yield_test.js'] = {};
    
    var d = b['./yield_test.js'];
    
    var r =  {
          case1 : function e() {
            function d(  ) {
              var b = true;
              
              var e = undefined;
              
              var c = 0;
              
              var d;
              
              var f = function ( e,f ) {
                    if ( !e ){
                      b = false;
                    } else if ( e && b && arguments[1] !== undefined ){
                      a.exceptionHandler( 'attempt to send to newborn generator.' );
                    };
                    
                    while ( 1 )switch ( c ) {
                      case 0 :
                        
                        d = 0;
                        
                        if ( !( d<10 ) ){
                          c = -1;
                          break;
                        };
                      case 1 :
                        
                        c = 2;
                        return d;
                      case 2 :
                        
                        d ++ ;
                        
                        if ( d<10 ){
                          c = 1;
                          break;
                        } else {
                          c = -1;
                        };
                      case -1 :
                        
                        if ( f ){
                          return undefined;
                        } else {
                          a.throwStopIteration();
                        };
                        
                    };
                  };
              return a.createGenerator( f,
              function (  ) {
                c = -1;
              },this);
            };
            
            var e = d();
          },
          case2 : function f() {
            function b(  ) {
              var b = true;
              
              var e = undefined;
              
              var c = 0;
              
              var d;
              
              var f = function ( e,f ) {
                    if ( !e ){
                      b = false;
                    } else if ( e && b && arguments[1] !== undefined ){
                      a.exceptionHandler( 'attempt to send to newborn generator.' );
                    };
                    
                    while ( 1 )switch ( c ) {
                      case 0 :
                        
                        d = 0;
                        
                        if ( !( d<10 ) ){
                          c = -1;
                          break;
                        };
                      case 1 :
                        
                        if ( d%2 === 0 ){
                          c = 2;
                          break;
                        } else {
                          c = 3;
                          break;
                        };
                      case 2 :
                        
                        c = 3;
                        return d;
                      case 3 :
                        
                        c = 4;
                        break;
                      case 4 :
                        
                        d ++ ;
                        
                        if ( d<10 ){
                          c = 1;
                          break;
                        } else {
                          c = -1;
                        };
                      case -1 :
                        
                        if ( f ){
                          return undefined;
                        } else {
                          a.throwStopIteration();
                        };
                        
                    };
                  };
              return a.createGenerator( f,
              function (  ) {
                c = -1;
              },this);
            };
            
            generator = b();
          },
          case3 : function g() {
            function b(  ) {
              var b = true;
              
              var f = undefined;
              
              var c = 0;
              
              var e;
              
              var d;
              
              var g = function ( f,g ) {
                    if ( !f ){
                      b = false;
                    } else if ( f && b && arguments[1] !== undefined ){
                      a.exceptionHandler( 'attempt to send to newborn generator.' );
                    };
                    
                    while ( 1 )switch ( c ) {
                      case 0 :
                        
                        d = 0;
                        
                        if ( !( d<10 ) ){
                          c = -1;
                          break;
                        };
                      case 1 :
                        
                        e = 0;
                        
                        if ( !( e<10 ) ){
                          c = 6;
                          break;
                        };
                      case 2 :
                        
                        if ( e%2 === 0 ){
                          c = 3;
                          break;
                        } else {
                          c = 4;
                          break;
                        };
                      case 3 :
                        
                        c = 4;
                        return e;
                      case 4 :
                        
                        c = 5;
                        break;
                      case 5 :
                        
                        e ++ ;
                        
                        if ( e<10 ){
                          c = 2;
                          break;
                        } else {
                          c = 6;
                        };
                      case 6 :
                        
                        d ++ ;
                        
                        if ( d<10 ){
                          c = 1;
                          break;
                        } else {
                          c = -1;
                        };
                      case -1 :
                        
                        if ( g ){
                          return undefined;
                        } else {
                          a.throwStopIteration();
                        };
                        
                    };
                  };
              return a.createGenerator( g,
              function (  ) {
                c = -1;
              },this);
            };
            
            generator = b();
          },
          case4 : function h() {
            function b(  ) {
              var b = true;
              
              var e = undefined;
              
              var c = 0;
              
              var d;
              
              var f = function ( e,f ) {
                    if ( !e ){
                      b = false;
                    } else if ( e && b && arguments[1] !== undefined ){
                      a.exceptionHandler( 'attempt to send to newborn generator.' );
                    };
                    
                    while ( 1 )switch ( c ) {
                      case 0 :
                        
                        d = 0;
                        
                        if ( !(  ++ d<10 ) ){
                          c = -1;
                          break;
                        };
                      case 1 :
                        
                        c = 2;
                        return d;
                      case 2 :
                        
                        if (  ++ d<10 ){
                          c = 1;
                          break;
                        } else {
                          c = -1;
                        };
                      case -1 :
                        
                        if ( f ){
                          return undefined;
                        } else {
                          a.throwStopIteration();
                        };
                        
                    };
                  };
              return a.createGenerator( f,
              function (  ) {
                c = -1;
              },this);
            };
            
            generator = b();
          },
          case5 : function i() {
            function b(  ) {
              var b = true;
              
              var e = undefined;
              
              var c = 0;
              
              var d;
              
              var f = function ( e,f ) {
                    if ( !e ){
                      b = false;
                    } else if ( e && b && arguments[1] !== undefined ){
                      a.exceptionHandler( 'attempt to send to newborn generator.' );
                    };
                    
                    while ( 1 )switch ( c ) {
                      case 0 :
                        
                        d = 0;
                      case 1 :
                        
                        c = 2;
                        return d;
                      case 2 :
                        
                        if (  ++ d<10 ){
                          c = 1;
                          break;
                        } else {
                          c = 3;
                        };
                      case 3 :
                      case -1 :
                        
                        if ( f ){
                          return undefined;
                        } else {
                          a.throwStopIteration();
                        };
                        
                    };
                  };
              return a.createGenerator( f,
              function (  ) {
                c = -1;
              },this);
            };
            
            generator = b();
          },
          case6 : function j() {
            function b(  ) {
              var b = true;
              
              var e = undefined;
              
              var c = 0;
              
              var f;
              
              var d;
              
              var g = function ( g,h ) {
                    if ( !g ){
                      b = false;
                    } else if ( g && b && arguments[1] !== undefined ){
                      a.exceptionHandler( 'attempt to send to newborn generator.' );
                    };
                    
                    while ( 1 )switch ( c ) {
                      case 0 :
                        
                        d = 0;
                        
                        if ( !( d<10 ) ){
                          c = -1;
                          break;
                        };
                      case 1 :
                        
                        c = 2;
                        return d;
                      case 2 :
                        
                        e = g && arguments.length>2?a.toArray( arguments,2 )[0] : g?d : undefined;
                        
                        f = e;
                        
                        if ( f === true ){
                          c = 3;
                          break;
                        } else {
                          c = 5;
                          break;
                        };
                      case 3 :
                        
                        c = 4;
                        return d+1;
                      case 4 :
                        
                        c = 9;
                        break;
                      case 5 :
                        
                        if ( f === false ){
                          c = 6;
                          break;
                        } else {
                          c = 8;
                          break;
                        };
                      case 6 :
                        
                        c = 7;
                        return d-1;
                      case 7 :
                        
                        c = 9;
                        break;
                      case 8 :
                        
                        c = 9;
                        return d;
                      case 9 :
                        
                        d ++ ;
                        
                        if ( d<10 ){
                          c = 1;
                          break;
                        } else {
                          c = -1;
                        };
                      case -1 :
                        
                        if ( h ){
                          return undefined;
                        } else {
                          a.throwStopIteration();
                        };
                        
                    };
                  };
              return a.createGenerator( g,
              function (  ) {
                c = -1;
              },this);
            };
            
            generator = b();
          },
          case7 : function k() {
            function b(  ) {
              var b = true;
              
              var e = undefined;
              
              var c = 0;
              
              var g;
              
              var f;
              
              var d;
              
              var h = function ( h,i ) {
                    if ( !h ){
                      b = false;
                    } else if ( h && b && arguments[1] !== undefined ){
                      a.exceptionHandler( 'attempt to send to newborn generator.' );
                    };
                    
                    while ( 1 )switch ( c ) {
                      case 0 :
                        
                        d = 0;
                        
                        if ( !( d<10 ) ){
                          c = -1;
                          break;
                        };
                      case 1 :
                        
                        c = 2;
                        return d;
                      case 2 :
                        
                        e = h && arguments.length>2?a.toArray( arguments,2 )[0] : h?d : undefined;
                        
                        f = e;
                        
                        g = 0;
                        
                        if ( !( g<10 ) ){
                          c = 11;
                          break;
                        };
                      case 3 :
                        
                        if ( f === true ){
                          c = 4;
                          break;
                        } else {
                          c = 6;
                          break;
                        };
                      case 4 :
                        
                        c = 5;
                        return g*2;
                      case 5 :
                        
                        c = 10;
                        break;
                      case 6 :
                        
                        if ( f === false ){
                          c = 7;
                          break;
                        } else {
                          c = 9;
                          break;
                        };
                      case 7 :
                        
                        c = 8;
                        return g/2;
                      case 8 :
                        
                        c = 10;
                        break;
                      case 9 :
                        
                        c = 10;
                        return g;
                      case 10 :
                        
                        g ++ ;
                        
                        if ( g<10 ){
                          c = 3;
                          break;
                        } else {
                          c = 11;
                        };
                      case 11 :
                        
                        d ++ ;
                        
                        if ( d<10 ){
                          c = 1;
                          break;
                        } else {
                          c = -1;
                        };
                      case -1 :
                        
                        if ( i ){
                          return undefined;
                        } else {
                          a.throwStopIteration();
                        };
                        
                    };
                  };
              return a.createGenerator( h,
              function (  ) {
                c = -1;
              },this);
            };
            
            generator = b();
          },
          case8 : function l() {
            function b(  ) {
              var b = true;
              
              var f = undefined;
              
              var c = 0;
              
              var g;
              
              var e;
              
              var d;
              
              var h = function ( h,i ) {
                    if ( !h ){
                      b = false;
                    } else if ( h && b && arguments[1] !== undefined ){
                      a.exceptionHandler( 'attempt to send to newborn generator.' );
                    };
                    
                    while ( 1 )switch ( c ) {
                      case 0 :
                        
                        d = 0;
                        
                        if ( !( d<10 ) ){
                          c = -1;
                          break;
                        };
                      case 1 :
                        
                        e = 0;
                        
                        if ( !( e<10 ) ){
                          c = 11;
                          break;
                        };
                      case 2 :
                        
                        c = 3;
                        return d;
                      case 3 :
                        
                        f = h && arguments.length>2?a.toArray( arguments,2 )[0] : h?d : undefined;
                        
                        g = f;
                        
                        if ( g === true ){
                          c = 4;
                          break;
                        } else {
                          c = 6;
                          break;
                        };
                      case 4 :
                        
                        c = 5;
                        return e*2;
                      case 5 :
                        
                        c = 10;
                        break;
                      case 6 :
                        
                        if ( g === false ){
                          c = 7;
                          break;
                        } else {
                          c = 9;
                          break;
                        };
                      case 7 :
                        
                        c = 8;
                        return e/2;
                      case 8 :
                        
                        c = 10;
                        break;
                      case 9 :
                        
                        c = 10;
                        return e;
                      case 10 :
                        
                        e ++ ;
                        
                        if ( e<10 ){
                          c = 2;
                          break;
                        } else {
                          c = 11;
                        };
                      case 11 :
                        
                        d ++ ;
                        
                        if ( d<10 ){
                          c = 1;
                          break;
                        } else {
                          c = -1;
                        };
                      case -1 :
                        
                        if ( i ){
                          return undefined;
                        } else {
                          a.throwStopIteration();
                        };
                        
                    };
                  };
              return a.createGenerator( h,
              function (  ) {
                c = -1;
              },this);
            };
            
            generator = b();
          },
          case9 : function m() {
            function b(  ) {
              var b = true;
              
              var i = undefined;
              
              var c = 0;
              
              var g;
              
              var f;
              
              var h;
              
              var e;
              
              var d;
              
              var j = function ( i,j ) {
                    if ( !i ){
                      b = false;
                    } else if ( i && b && arguments[1] !== undefined ){
                      a.exceptionHandler( 'attempt to send to newborn generator.' );
                    };
                    
                    while ( 1 )try {
                      switch ( c ) {
                        case 0 :
                          
                          d = false;
                          
                          e = 0;
                          
                          if ( !( e<10 ) ){
                            c = -1;
                            break;
                          };
                        case 1 :
                          
                          c = 2;
                          
                          f = function ( a ) {
                            c = 3;
                          };
                          
                          g = function (  ) {
                            d = true;
                          };
                          
                          h = ( d )?1 : 0;
                          return h;
                        case 2 :
                          
                          ddddd();
                          
                          f = undefined;
                          
                          g = undefined;
                        case 3 :
                          
                          e ++ ;
                          
                          if ( e<10 ){
                            c = 1;
                            break;
                          } else {
                            c = -1;
                          };
                        case -1 :
                          
                          if ( j ){
                            return undefined;
                          } else {
                            a.throwStopIteration();
                          };
                          
                      };
                    } catch( _mochaException ){
                      if ( f ){
                        var k = f( _mochaException );
                        
                        if ( k !== undefined ){
                          return k;
                        };
                      } else {
                        a.throwException( _mochaException );
                      };
                    } finally {
                      if ( g ){
                        var _mochaLocalTmp1 = g(  );
                        
                        if ( _mochaLocalTmp1 !== undefined ){
                          return _mochaLocalTmp1;
                        };
                      };
                    };
                  };
              return a.createGenerator( j,
              function (  ) {
                c = -1;
                
                if ( g ){
                  g(  );
                };
              },this);
            };
            
            generator = b();
          },
          case10 : function n() {
            function b(  ) {
              var b = true;
              
              var e = undefined;
              
              var c = 0;
              
              var f;
              
              var d;
              
              var g = function ( g,h ) {
                    if ( !g ){
                      b = false;
                    } else if ( g && b && arguments[1] !== undefined ){
                      a.exceptionHandler( 'attempt to send to newborn generator.' );
                    };
                    
                    while ( 1 )switch ( c ) {
                      case 0 :
                        
                        d = 0;
                        
                        if ( !( d<10 ) ){
                          c = -1;
                          break;
                        };
                      case 1 :
                        
                        c = 2;
                        return ;
                      case 2 :
                        
                        e = g && arguments.length>2?a.toArray( arguments,2 )[0] : undefined;
                        
                        f = e;
                        
                        switch ( f ) {
                          case 0 :
                            
                            c = 3;
                            break;
                          case 2 :
                            
                            c = 4;
                            break;
                          case 3 :
                            
                            c = 5;
                            break;
                          default :
                            
                            c = 6;
                            break;
                            
                        };
                        break;
                      case 3 :
                        
                        c = 7;
                        return 200;
                      case 4 :
                        
                        c = 7;
                        return 400;
                      case 5 :
                        
                        c = 7;
                        return 600;
                      case 6 :
                        
                        c = 7;
                        return 700;
                      case 7 :
                        
                        d ++ ;
                        
                        if ( d<10 ){
                          c = 1;
                          break;
                        } else {
                          c = -1;
                        };
                      case -1 :
                        
                        if ( h ){
                          return undefined;
                        } else {
                          a.throwStopIteration();
                        };
                        
                    };
                  };
              return a.createGenerator( g,
              function (  ) {
                c = -1;
              },this);
            };
            
            generator = b();
            
            generator.next();
            
            generator.next();
            
            generator.next();
            
            generator.next();
          },
          case11 : function o() {
            function b(  ) {
              var b = true;
              
              var e = undefined;
              
              var c = 0;
              
              var f;
              
              var d;
              
              var g = function ( g,h ) {
                    if ( !g ){
                      b = false;
                    } else if ( g && b && arguments[1] !== undefined ){
                      a.exceptionHandler( 'attempt to send to newborn generator.' );
                    };
                    
                    while ( 1 )switch ( c ) {
                      case 0 :
                        
                        d = 0;
                        
                        if ( !( d<15 ) ){
                          c = -1;
                          break;
                        };
                      case 1 :
                        
                        c = 2;
                        return ;
                      case 2 :
                        
                        e = g && arguments.length>2?a.toArray( arguments,2 )[0] : undefined;
                        
                        f = e;
                        
                        switch ( f ) {
                          case 4 :
                          case 0 :
                            
                            c = 3;
                            break;
                          case 5 :
                            
                            c = 7;
                            break;
                          case 6 :
                          case 2 :
                            
                            c = 4;
                            break;
                          case 3 :
                            
                            c = 5;
                            break;
                          default :
                            
                            c = 6;
                            break;
                            
                        };
                        break;
                      case 3 :
                        
                        c = 8;
                        return 200;
                      case 4 :
                        
                        c = 8;
                        return 400;
                      case 5 :
                        
                        c = 8;
                        return 600;
                      case 6 :
                        
                        c = 8;
                        return 700;
                      case 7 :
                        
                        c = 8;
                        break;
                      case 8 :
                        
                        d ++ ;
                        
                        if ( d<15 ){
                          c = 1;
                          break;
                        } else {
                          c = -1;
                        };
                      case -1 :
                        
                        if ( h ){
                          return undefined;
                        } else {
                          a.throwStopIteration();
                        };
                        
                    };
                  };
              return a.createGenerator( g,
              function (  ) {
                c = -1;
              },this);
            };
            
            generator = b();
            
            generator.next();
            
            generator.next();
            
            generator.next();
            
            generator.next();
            
            generator.next();
          },
          case12 : function p() {
            function b() {
              var b = true;
              
              var i = undefined;
              
              var c = 0;
              
              var g;
              
              var f;
              
              var h;
              
              var d;
              
              var e = [];
              
              var j = function ( i,j ) {
                    if ( !i ){
                      b = false;
                    } else if ( i && b && arguments[1] !== undefined ){
                      a.exceptionHandler( 'attempt to send to newborn generator.' );
                    };
                    
                    while ( 1 )switch ( c ) {
                      case 0 :
                        
                        d =  {
                          x : 200,
                          y : 300,
                          z : 400
                        };
                        
                        for ( var k in d )
                        e.push( k );
                        
                        f = 0;
                        
                        g = e.length;
                        
                        if ( !( f<g ) ){
                          c = -1;
                          break;
                        };
                      case 1 :
                        
                        c = 2;
                        
                        h = e[f];
                        return [h,d[h]];
                      case 2 :
                        
                         ++ f;
                        
                        if ( f<g ){
                          c = 1;
                          break;
                        } else {
                          c = -1;
                        };
                      case -1 :
                        
                        if ( j ){
                          return undefined;
                        } else {
                          a.throwStopIteration();
                        };
                        
                    };
                  };
              return a.createGenerator( j,
              function (  ) {
                c = -1;
              },this);
            };
            
            generator = b();
            
            var d = generator.next();
            
            d = generator.next();
            
            d = generator.next();
          },
          case13 : function q() {
            function b( d ) {
              var b = true;
              
              var i = undefined;
              
              var c = 0;
              
              var g;
              
              var f;
              
              var h;
              
              var e = [];
              
              var j = function ( i,j ) {
                    if ( !i ){
                      b = false;
                    } else if ( i && b && arguments[1] !== undefined ){
                      a.exceptionHandler( 'attempt to send to newborn generator.' );
                    };
                    
                    while ( 1 )switch ( c ) {
                      case 0 :
                        
                        for ( var k in d )
                        e.push( k );
                        
                        f = 0;
                        
                        g = e.length;
                        
                        if ( !( f<g ) ){
                          c = -1;
                          break;
                        };
                      case 1 :
                        
                        h = e[f];
                        
                        if ( d.hasOwnProperty( h ) ){
                          c = 2;
                          break;
                        } else {
                          c = 3;
                          break;
                        };
                      case 2 :
                        
                        c = 3;
                        return h;
                      case 3 :
                        
                        c = 4;
                        break;
                      case 4 :
                        
                         ++ f;
                        
                        if ( f<g ){
                          c = 1;
                          break;
                        } else {
                          c = -1;
                        };
                      case -1 :
                        
                        if ( j ){
                          return undefined;
                        } else {
                          a.throwStopIteration();
                        };
                        
                    };
                  };
              return a.createGenerator( j,
              function (  ) {
                c = -1;
              },this);
            };
            
            var c =  {
                  value1 : 1,
                  value2 : 2,
                  value3 : 3,
                  value4 : 4
                };
            
            try {
              var d = b( c );
            } catch( e ){
              
            };
          }
        };
    
    for ( var c = 1;c<13;c ++  )
    r["case"+c]();
  }();
}();
