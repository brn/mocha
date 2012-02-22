!function() {
  var __FILE__ = "Runtime",
      __LINE__ = 0;
  
  var b = {};
  
  !function ( f,g,h,i ) {
    var c = f.prototype,
        d = g.prototype,
        j = h.prototype,
        k = i.prototype;
    
    function b( b ) {
      try {
        throw new TypeError( b );
      } catch( e ){
        throw new Error( e );
      };
    };
    
    function e( c,d ) {
      
      a.assert( true,typeof d === "string","typeof type === \"string\"",43,'./mocha_runtime.js' );
      
      if ( typeof c !== "function" ){
        b( d+" : first argument is not callable" );
      };
    };
    
    if ( !Object.keys ){
      Object.keys = function ( c ) {
        if ( !c ){
          b( "Object.keys : first arguments is null or not defined." );
        };
        
        var d = [],
            e = -1;
        
        for ( var f in c ){
          
          if ( c.hasOwnProperty( f ) ){
            d[ ++ e] = c[f];
          };
        };
        return d;
      };
    };
    
    if ( !Object.preventExtensions ){
      Object.preventExtensions = function ( b ) {
        return b;
      };
    };
    
    if ( !Object.seal ){
      Object.seal = function ( b ) {
        return b;
      };
    };
    
    if ( !Object.freeze ){
      Object.freeze = function ( b ) {
        return b;
      };
    };
    
    var l = function () {
          var b;
          
          try {
            var c = {};
            
            Object.defineProperty( c,"test", {
              configurable : false,
              writable : false,
              enumerable : false,
              value : 0
            });
            
            c.test = 200;
            
            b = ( c.test === 200 )?false : true;
          } catch( e ){
            b = false;
          };
          return b;
        }();
    
    if ( !l ){
      Object.defineProperty = function ( b,c,d ) {
        if ( d.value ){
          b[c] = d.value;
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
        value : function m( b ) {
          return Array( b+1 ).join( this.toString() );
        },
        configurable : true,
        enumerable : false,
        writable : true
      });
    };
    
    if ( !c.startsWith ){
      Object.defineProperty( c,"startsWith", {
        value : function m( b ) {
          return !this.indexOf( b );
        },
        configurable : true,
        enumerable : false,
        writable : true
      });
    };
    
    if ( !c.endsWith ){
      Object.defineProperty( c,"endsWith", {
        value : function m( b ) {
          var c = String( b ),
              d = this.lastIndexOf( c );
          return d >= 0 && d === this.length-c.length;
        },
        configurable : true,
        enumerable : false,
        writable : true
      });
    };
    
    if ( !c.contains ){
      Object.defineProperty( c,"contains", {
        value : function m( b ) {
          return this.indexOf( b ) !== -1;
        },
        configurable : true,
        enumerable : false,
        writable : true
      });
    };
    
    if ( !c.toArray ){
      Object.defineProperty( c,"toArray", {
        value : function m( b ) {
          return this.split( "" );
        },
        configurable : true,
        enumerable : false,
        writable : true
      });
    };
    
    if ( !j.bind ){
      j.bind = function () {
        var b = d.slice.call( arguments ),
            e = b.shift(),
            c = function () {
              var f = b.concat( d.slice.call( arguments ) );
              
              if ( this !== null && this !== window && this instanceof c ){
                return c.context.apply( this,f );
              } else {
                return c.context.apply( e,f );
              };
            };
        
        c.prototype = this.prototype;
        
        c.context = this;
        return c;
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
          while ( ( i = this[ ++ h] ) !== null && i !== undefined ){
            f.call( g,i,h,this );
          };
        } else {
          while ( ( i = this[ ++ h] ) !== null && i !== undefined ){
            f( i,h,this );
          };
        };
      };
    };
    
    if ( !d.every ){
      d.every = function ( c,d ) {
        e( c,"Array.every" );
        
        var f = -1,
            g;
        
        if ( this === null ){
          b( "Array.every : this is null or not defined" );
        };
        
        if ( d ){
          while ( ( g = this[ ++ f] ) !== null && g !== undefined ){
            if ( !( c.call( d,g,f,this ) ) ){
              return false;
            };
          };
        } else {
          while ( ( g = this[ ++ f] ) !== null && g !== undefined ){
            if ( !( c( g,f,this ) ) ){
              return false;
            };
          };
        };
        return true;
      };
    };
    
    if ( !d.some ){
      d.some = function ( c,d ) {
        e( c,"Array.some" );
        
        var f = -1,
            g;
        
        if ( this === null ){
          b( "Array.some : this is null or not defined" );
        };
        
        if ( d ){
          while ( ( g = this[ ++ f] ) !== null && g !== undefined ){
            if ( c.call( d,g,f,this ) ){
              return true;
            };
          };
        } else {
          while ( ( g = this[ ++ f] ) !== null && g !== undefined ){
            if ( c( g,f,this ) ){
              return true;
            };
          };
        };
        return false;
      };
    };
    
    if ( !d.filter ){
      d.filter = function ( c,d ) {
        e( c,"Array.filter" );
        
        var f = this.length,
            g = -1,
            h = [],
            i;
        
        if ( this === null ){
          b( "Array.filter : this is null or not defined" );
        };
        
        if ( d ){
          for ( var j = 0,f = this.length;j<f; ++ j ){
            
            if ( ( i = this[j] ) !== null && i !== undefined ){
              if ( c.call( d,i,j,this ) ){
                h[ ++ g] = i;
              };
            };
          };
        } else {
          for ( var j = 0,f = this.length;j<f; ++ j ){
            if ( ( i = this[j] ) !== null && i !== undefined ){
              if ( c( i,j,this ) ){
                h[ ++ g] = i;
              };
            };
          };
        };
        return h;
      };
    };
    
    if ( !d.indexOf ){
      d.indexOf = function ( c,d ) {
        var e = d?d-1 : -1,
            f = -1,
            g;
        
        if ( this === null ){
          b( "Array.indexOf : this is null or not defined." );
        };
        
        while ( ( g = this[ ++ e] ) !== null && g !== undefined ){
          if ( g === c ){
            f = e;
            break;
          };
        };
        return f;
      };
    };
    
    if ( !d.lastIndexOf ){
      d.lastIndexOf = function ( c,d ) {
        var e = this.length,
            f = d?d+1 : e,
            g = -1,
            h;
        
        if ( this === null ){
          b( "Array.lastIndexOf : this is null or not defined." );
        };
        
        while ( ( h = this[ -- f] ) !== null && h !== undefined ){
          if ( h === c ){
            g = f;
            break;
          };
        };
        return g;
      };
    };
    
    if ( !d.map ){
      d.map = function ( c,d ) {
        e( c,"Array.map" );
        
        var f = [],
            g = -1,
            h = this.length,
            i = 0,
            j;
        
        if ( this === null ){
          b( "Array.map : this is null or not defined." );
        };
        
        if ( d ){
          for ( i;i<h; ++ i ){
            if ( ( j = this[i] ) !== null && j !== undefined ){
              f[ ++ g] = c.call( d,j,i,this );
            };
          };
        } else {
          for ( i;i<h; ++ i ){
            if ( ( j = this[i] ) !== null && j !== undefined ){
              f[ ++ g] = c( j,i,this );
            };
          };
        };
        return f;
      };
    };
    
    if ( !d.reduce ){
      d.reduce = function ( c,d ) {
        e( c,"Array.reduce" );
        
        var f = d || this[0],
            g = d?0 : 1,
            h = this.length,
            i;
        
        if ( ( h === 0 || h === null ) && arguments.length<2 ){
          b( "Array length is 0 and no second argument" );
        };
        
        for ( g;g<h; ++ g ){
          if ( ( i = this[g] ) !== null && i !== undefined ){
            f = c( f,i,g,this );
          };
        };
        return f;
      };
    };
    
    if ( !d.reduceRight ){
      d.reduceRight = function ( c,d ) {
        e( c,"Array.reduceRight" );
        
        var f = this.length,
            g = d || this[f-1],
            h = d?f-1 : f-2,
            i;
        
        if ( ( f === 0 || f === null ) && arguments.length<2 ){
          b( "Array length is 0 and no second argument" );
        };
        
        for ( h;h>-1; -- h ){
          if ( ( i = this[h] ) !== null && i !== undefined ){
            g = c( g,i,h,this );
          };
        };
        return g;
      };
    };
    
    if ( !k.toJSON ){
      k.toJSON = function () {
        var b = [this.getUTCMonth(),this.getUTCDate(),this.getUTCHours(),this.getMinutes(),this.getSeconds()],
            c = b[0],
            d = b[1],
            e = b[2],
            f = b[3],
            g = b[4];
        return '"'+this.getUTCFullYear()+'-'+( c>8?c+1 : "0"+( c+1 ) )+'-'+( d>9?d : "0"+d )+'T'+( e>9?e : "0"+e )+':'+( f>9?f : "0"+f )+':'+( g>9?g : "0"+g )+'.'+this.getUTCMilliseconds()+'Z"';
      };
    };
    
    if ( !Date.now ){
      Date.now = function () {
        return +new Date();
      };
    };
    
    if ( !Array.isArray ){
      Array.isArray = function ( b ) {
        if ( arguments.length === 0 ){
          return false;
        };
        return b?( {} ).toString.call( b ) === "[object Array]" : false;
      };
    };
  }.call( this,String,Array,Function,Date );
  
  var a = function () {
        var r = {};
        
        function c( d,c,b ) {
          this.toString = function () {
            return a.getErrorMessage( b )+" in file "+c+" at : "+d;
          };
        }
        var s = Math,
            g = s.max,
            t = [],
            d = t.slice,
            a =  {
              getErrorMessage : function u( b ) {
                return ( b.message )?b.message : ( b.description )?b.description : b.toString();
              },
              exceptionHandler : function v( d,e,f ) {
                if ( b( f ) ){
                  this.throwException( f );
                } else {
                  this.throwException( new c( d,e,f ) );
                };
              },
              throwException : function p( c ) {
                try {
                  throw c;
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
        
        function f( b,c,d ) {
          return Object.defineProperty( b,c, {
            configurable : true,
            enumerable : false,
            writable : true,
            value : d
          });
        };
        
        r.createUnenumProp = f;
        
        function w( b,c,d ) {
          return Object.defineProperty( b,c, {
            configurable : false,
            enumerable : false,
            writable : false,
            value : d
          });
        };
        
        r.constant = w;
        
        function x( e,f ) {
          return e?d.call( e,f ) : [];
        };
        
        r.toArray = x;
        
        function e(  ){};
        
        function y( g,h,i ) {
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
        
        r.createGenerator = y;
        
        function u( b ) {
          return ( b.message )?b.message : ( b.description )?b.description : b.toString();
        }
        var p = r.throwException = a.throwException.bind( a ),
            v = r.exceptionHandler = a.exceptionHandler.bind( a );
        
        function z( b,c ) {
          for ( var d in c ){
            
            b[d] = c[d];
          };
          return b;
        };
        
        r.extend = z;
        
        function h( h ) {
          var i = g( h.length,this.length ),
              j = -1;
          
          while (  ++ j<i && h[j] === this[j] ){
            
          };
          return i === j;
        };
        
        function i() {
          return [].slice.call( this );
        };
        
        function A( j,k ) {
          f( j,"length",k );
          
          f( j,"equal",h );
          
          f( j,"toArray",i );
          
          f( j,"toString",
          function () {
            return "[object Tuple]";
          });
          return Object.freeze( j );
        };
        
        r.createTuple = A;
        
        function B( b ) {
          if ( b.toString() === "[object Object]" ){
            f( b,"toString",
            function () {
              return "[object Record]";
            });
          };
          return Object.freeze( b );
        };
        
        r.createRecord = B;
        
        var C = r.extendPrototype = function ( b,c ) {
              b.prototype = c;
            },
            j = ( "getPrototypeOf" in Object )?function ( b ) {
              return Object.getPrototypeOf( b );
            } : function ( b ) {
              var c = {};
              
              for ( var d in b ){
                
                if ( !b.hasOwnProperty( d ) ){
                  c[d] = b[d];
                };
              };
              return c;
            },
            D = r.extendClass = ( a.hasProto )?function ( b,c ) {
              if ( typeof c === 'function' ){
                b.prototype.__proto__ = c.prototype;
                
                for ( var d in c ){
                  
                  b[d] = c[d];
                };
              } else {
                b.prototype.__proto__ = c.__proto__;
              };
            } : function ( k,l ) {
              var m = typeof l;
              
              if ( m === "function" ){
                var n = function (){};
                
                n.prototype = l.prototype;
                
                k.prototype = new n;
                
                for ( var o in l ){
                  
                  k[o] = l[o];
                };
              } else {
                var n = function (){},
                    p = j( l );
                
                n.prototype = p;
                
                k.prototype = new n;
              };
            },
            k = r.__ref_iterator__ = "__mocha_iterator_special_key__";
        
        function m() {
          try {
            throw StopIteration;
          } catch( e ){
            throw new Error( e.toString() );
          };
        };
        
        r.throwStopIteration = m;
        
        function l( b ) {
          return b instanceof e;
        };
        
        r.isGenerator = l;
        
        function E( n ) {
          var b = n[k](),
              o;
          
          if ( l( b ) ){
            return b;
          };
          
          o = {};
          
          if ( b.next ){
            f( o,"next",
            function () {
              var c = b.next();
              
              if ( c === undefined ){
                m();
              };
              return c;
            });
          } else {
            return {};
          };
          
          if ( !( "__nothrowNext__" in b ) ){
            f( o,"__nothrowNext__",b.next.bind( b ) );
          };
          
          for ( var p in b ){
            
            if ( p !== "next" && p !== "__nothrowNext__" ){
              o[p] = b[p];
            };
          };
          
          if ( !( "toString" in b ) ){
            f( o,"toString",
            function () {
              return "[object Iterator]";
            });
          };
          return o;
        };
        
        r.getIterator = E;
        
        function F( b ) {
          return k in b;
        };
        
        r.hasIterator = F;
        
        var n = /StopIteration/;
        
        function b( o ) {
          return o === StopIteration || n.test( o );
        };
        
        r.isStopIteration = b;
        
        var o,
            q,
            G;
        
        if ( "WeakMap" in window ){
          o = new WeakMap();
          
          q = function ( self,p ) {
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
          q = function ( self,b ) {
            if ( !self.__typeid__ ){
              var c = new b;
              
              f( c.constructor,"__is_private__",1 );
              
              f( self,"__private__",c );
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
        
        r.getPrivateRecord = G;
        
        function H( r,s,t,u,v,w,x ) {
          if ( !r || !( r instanceof s ) ){
            p( "class "+w+" must be called by new. line : "+x );
          };
          
          q( r,t );
          
          u.apply( r,v );
        };
        
        r.initializeClass = H;
        
        function I( b ) {
          var c = typeof b,
              d;
          
          if ( c === "function" ){
            d = function (){};
            
            d.prototype = b.prototype;
            
            d = new d();
            
            if ( b.__harmony_class__ ){
              d.constructor = b.constructor;
            } else {
              d.constructor = b;
            };
            return d;
          };
          return d;
        };
        
        r.getSuper = I;
        
        function J( b,c,d,e ) {
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
            
            for ( var m in g ){
              if ( !e[m] ){
                l = ( !d[m] )?m : d[m];
                
                f[l] = g[m];
              };
            };
            
            for ( m in i ){
              if ( !e[m] ){
                l = ( !d[m] )?m : d[m];
                
                h[l] = i[m];
              };
            };
            
            for ( m in j ){
              k[m] = j[m];
            };
          };
        };
        
        r.traitMixin = J;
        
        function K( b,c,d,e,f ) {
          var g = b.prototype,
              h = c.prototype,
              i = d._mochaTraitMark,
              j = d._mochaTraitPublic,
              k = d._mochaTraitPrivate;
          
          if ( !i ){
            a.throwException( "mixin only used for trait." );
          } else {
            var l;
            
            for ( var m in j ){
              if ( !f[m] ){
                l = ( !e[m] )?m : e[m];
                
                g[l] = j[m];
              };
            };
            
            for ( m in k ){
              if ( !f[m] ){
                l = ( !e[m] )?m : e[m];
                
                h[l] = k[m];
              };
            };
          };
        };
        
        r.classMixin = K;
        
        function L( b,c,d,e,f ) {
          var g = b.prototype,
              h = c.prototype;
          
          for ( var i = 0,j = d.length;i<j;i ++  ){
            var k = d[i],
                l = k._mochaRequires;
            
            for ( var m in l ){
              
              if ( !( m in g ) && !( m in h ) ){
                a.throwException( "Class dose not meet the traits requirement. traits require implementation of property "+m+"\nin file "+e+" at line "+f );
              };
            };
          };
        };
        
        r.checkRequirements = L;
        
        !function () {
          var s = r.assert = ( console && console.assert )?function ( b,c,d,e,f ) {
                return console.assert( b === c,"assertion failed : "+d+"\nexpect "+b+" but got "+c+"\nin file "+f+" at : "+e );
              } : function ( b,c,d,e,f ) {
                if ( b !== c ){
                  a.throwException( "assertion failed : "+d+"\nexpect "+b+" but got "+c+"\nin file "+f+" at : "+e );
                };
              };
        }();
        return r;
      }();
  
  if ( !( "StopIteration" in window ) ){
    window.StopIteration =  {
      toString : function c() {
        return "[object StopIteration]";
      }
    };
  };
  
  function d(  ) {
    var b = a.toArray( arguments,0 ),
        c = {};
    
    c.length = 0;
    
    [].push.apply( c,b );
    
    a.createTuple( c,arguments.length );
    return c;
  };
  
  function e( b ) {
    return a.createRecord( b );
  };
  
  __LINE__ = 0;
  !function () {
    try {
      var __FILE__ = "/Users/aono_taketoshi/github/mocha/src/test/js/harmony/yield_test.js",
          __LINE__ = 0;
      __LINE__ = 2;
      b['./yield_test.js'] = {};
      
      __LINE__ = 3;
      var d = b['./yield_test.js'],
          r =  {
            case1 : function e() {
              try {
                __LINE__ = 0;
                function d(  ) {
                  try {
                    __LINE__ = 0;
                    var b = true,
                        e = undefined,
                        c = 0,
                        d,
                        f = function ( e,f ) {
                          try {
                            __LINE__ = 0;
                            if ( !e ){
                              __LINE__ = 0;
                              b = false;
                            } else if ( e && b && arguments[1] !== undefined ){
                              __LINE__ = 0;
                              a.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 9;
                            while ( 1 ){
                              __LINE__ = 9;
                              switch ( c ) {
                                case 0 :
                                  
                                  __LINE__ = 4;
                                  d = 0;
                                  
                                  __LINE__ = 4;
                                  if ( !( d<10 ) ){
                                    __LINE__ = 9;
                                    c = -1;
                                    __LINE__ = 9;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 0;
                                  c = 2;
                                  __LINE__ = 0;
                                  return d;
                                case 2 :
                                  
                                  __LINE__ = 0;
                                  d ++ ;
                                  
                                  __LINE__ = 9;
                                  if ( d<10 ){
                                    __LINE__ = 9;
                                    c = 1;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 9;
                                    c = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 0;
                                  if ( f ){
                                    __LINE__ = 0;
                                    return undefined;
                                  } else {
                                    __LINE__ = 9;
                                    a.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            a.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 0;
                    return a.createGenerator( f,
                    function (  ) {
                      try {
                        __LINE__ = 0;
                        c = -1;
                      } catch( e ){
                        a.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    a.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
                
                __LINE__ = 9;
                var e = d();
                
                __LINE__ = 11;
                a.assert( true,e.next() === 0,"generator.next() === 0",11,'./yield_test.js' );
                
                __LINE__ = 12;
                a.assert( true,e.next() === 1,"generator.next() === 1",12,'./yield_test.js' );
                
                __LINE__ = 13;
                a.assert( true,e.next() === 2,"generator.next() === 2",13,'./yield_test.js' );
                
                __LINE__ = 14;
                a.assert( true,e.next() === 3,"generator.next() === 3",14,'./yield_test.js' );
                
                __LINE__ = 15;
                a.assert( true,e.next() === 4,"generator.next() === 4",15,'./yield_test.js' );
                
                __LINE__ = 16;
                a.assert( true,e.next() === 5,"generator.next() === 5",16,'./yield_test.js' );
                
                __LINE__ = 17;
                a.assert( true,e.next() === 6,"generator.next() === 6",17,'./yield_test.js' );
                
                __LINE__ = 18;
                a.assert( true,e.next() === 7,"generator.next() === 7",18,'./yield_test.js' );
                
                __LINE__ = 19;
                a.assert( true,e.next() === 8,"generator.next() === 8",19,'./yield_test.js' );
                
                __LINE__ = 20;
                a.assert( true,e.next() === 9,"generator.next() === 9",20,'./yield_test.js' );
              } catch( e ){
                a.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case2 : function f() {
              try {
                __LINE__ = 0;
                function b(  ) {
                  try {
                    __LINE__ = 0;
                    var b = true,
                        e = undefined,
                        c = 0,
                        d,
                        f = function ( e,f ) {
                          try {
                            __LINE__ = 0;
                            if ( !e ){
                              __LINE__ = 0;
                              b = false;
                            } else if ( e && b && arguments[1] !== undefined ){
                              __LINE__ = 0;
                              a.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 31;
                            while ( 1 ){
                              __LINE__ = 31;
                              switch ( c ) {
                                case 0 :
                                  
                                  __LINE__ = 25;
                                  d = 0;
                                  
                                  __LINE__ = 25;
                                  if ( !( d<10 ) ){
                                    __LINE__ = 31;
                                    c = -1;
                                    __LINE__ = 31;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 26;
                                  if ( d%2 === 0 ){
                                    __LINE__ = 31;
                                    c = 2;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 31;
                                    c = 3;
                                    __LINE__ = 0;
                                    break;
                                  };
                                case 2 :
                                  
                                  __LINE__ = 0;
                                  c = 3;
                                  __LINE__ = 0;
                                  return d;
                                case 3 :
                                  
                                  __LINE__ = 0;
                                  c = 4;
                                  __LINE__ = 0;
                                  break;
                                case 4 :
                                  
                                  __LINE__ = 0;
                                  d ++ ;
                                  
                                  __LINE__ = 31;
                                  if ( d<10 ){
                                    __LINE__ = 31;
                                    c = 1;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 31;
                                    c = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 0;
                                  if ( f ){
                                    __LINE__ = 0;
                                    return undefined;
                                  } else {
                                    __LINE__ = 31;
                                    a.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            a.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 0;
                    return a.createGenerator( f,
                    function (  ) {
                      try {
                        __LINE__ = 0;
                        c = -1;
                      } catch( e ){
                        a.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    a.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
                
                __LINE__ = 0;
                generator = b();
                
                __LINE__ = 32;
                a.assert( true,generator.next() === 0,"generator.next() === 0",32,'./yield_test.js' );
                
                __LINE__ = 33;
                a.assert( true,generator.next() === 2,"generator.next() === 2",33,'./yield_test.js' );
                
                __LINE__ = 34;
                a.assert( true,generator.next() === 4,"generator.next() === 4",34,'./yield_test.js' );
                
                __LINE__ = 35;
                a.assert( true,generator.next() === 6,"generator.next() === 6",35,'./yield_test.js' );
                
                __LINE__ = 36;
                a.assert( true,generator.next() === 8,"generator.next() === 8",36,'./yield_test.js' );
              } catch( e ){
                a.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case3 : function g() {
              try {
                __LINE__ = 0;
                function b(  ) {
                  try {
                    __LINE__ = 0;
                    var b = true,
                        f = undefined,
                        c = 0,
                        e,
                        d,
                        g = function ( f,g ) {
                          try {
                            __LINE__ = 0;
                            if ( !f ){
                              __LINE__ = 0;
                              b = false;
                            } else if ( f && b && arguments[1] !== undefined ){
                              __LINE__ = 0;
                              a.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 48;
                            while ( 1 ){
                              __LINE__ = 48;
                              switch ( c ) {
                                case 0 :
                                  
                                  __LINE__ = 40;
                                  d = 0;
                                  
                                  __LINE__ = 40;
                                  if ( !( d<10 ) ){
                                    __LINE__ = 48;
                                    c = -1;
                                    __LINE__ = 48;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 41;
                                  e = 0;
                                  
                                  __LINE__ = 41;
                                  if ( !( e<10 ) ){
                                    __LINE__ = 48;
                                    c = 6;
                                    __LINE__ = 48;
                                    break;
                                  };
                                case 2 :
                                  
                                  __LINE__ = 42;
                                  if ( e%2 === 0 ){
                                    __LINE__ = 48;
                                    c = 3;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 48;
                                    c = 4;
                                    __LINE__ = 0;
                                    break;
                                  };
                                case 3 :
                                  
                                  __LINE__ = 0;
                                  c = 4;
                                  __LINE__ = 0;
                                  return e;
                                case 4 :
                                  
                                  __LINE__ = 0;
                                  c = 5;
                                  __LINE__ = 0;
                                  break;
                                case 5 :
                                  
                                  __LINE__ = 0;
                                  e ++ ;
                                  
                                  __LINE__ = 48;
                                  if ( e<10 ){
                                    __LINE__ = 48;
                                    c = 2;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 48;
                                    c = 6;
                                  };
                                case 6 :
                                  
                                  __LINE__ = 0;
                                  d ++ ;
                                  
                                  __LINE__ = 48;
                                  if ( d<10 ){
                                    __LINE__ = 48;
                                    c = 1;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 48;
                                    c = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 0;
                                  if ( g ){
                                    __LINE__ = 0;
                                    return undefined;
                                  } else {
                                    __LINE__ = 48;
                                    a.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            a.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 0;
                    return a.createGenerator( g,
                    function (  ) {
                      try {
                        __LINE__ = 0;
                        c = -1;
                      } catch( e ){
                        a.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    a.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
                
                __LINE__ = 0;
                generator = b();
                
                __LINE__ = 49;
                a.assert( true,generator.next() === 0,"generator.next() === 0",49,'./yield_test.js' );
                
                __LINE__ = 50;
                a.assert( true,generator.next() === 2,"generator.next() === 2",50,'./yield_test.js' );
                
                __LINE__ = 51;
                a.assert( true,generator.next() === 4,"generator.next() === 4",51,'./yield_test.js' );
                
                __LINE__ = 52;
                a.assert( true,generator.next() === 6,"generator.next() === 6",52,'./yield_test.js' );
                
                __LINE__ = 53;
                a.assert( true,generator.next() === 8,"generator.next() === 8",53,'./yield_test.js' );
                
                __LINE__ = 55;
                a.assert( true,generator.next() === 0,"generator.next() === 0",55,'./yield_test.js' );
                
                __LINE__ = 56;
                a.assert( true,generator.next() === 2,"generator.next() === 2",56,'./yield_test.js' );
                
                __LINE__ = 57;
                a.assert( true,generator.next() === 4,"generator.next() === 4",57,'./yield_test.js' );
                
                __LINE__ = 58;
                a.assert( true,generator.next() === 6,"generator.next() === 6",58,'./yield_test.js' );
                
                __LINE__ = 59;
                a.assert( true,generator.next() === 8,"generator.next() === 8",59,'./yield_test.js' );
                
                __LINE__ = 61;
                a.assert( true,generator.next() === 0,"generator.next() === 0",61,'./yield_test.js' );
                
                __LINE__ = 62;
                a.assert( true,generator.next() === 2,"generator.next() === 2",62,'./yield_test.js' );
                
                __LINE__ = 63;
                a.assert( true,generator.next() === 4,"generator.next() === 4",63,'./yield_test.js' );
                
                __LINE__ = 64;
                a.assert( true,generator.next() === 6,"generator.next() === 6",64,'./yield_test.js' );
                
                __LINE__ = 65;
                a.assert( true,generator.next() === 8,"generator.next() === 8",65,'./yield_test.js' );
                
                __LINE__ = 67;
                a.assert( true,generator.next() === 0,"generator.next() === 0",67,'./yield_test.js' );
                
                __LINE__ = 68;
                a.assert( true,generator.next() === 2,"generator.next() === 2",68,'./yield_test.js' );
                
                __LINE__ = 69;
                a.assert( true,generator.next() === 4,"generator.next() === 4",69,'./yield_test.js' );
                
                __LINE__ = 70;
                a.assert( true,generator.next() === 6,"generator.next() === 6",70,'./yield_test.js' );
                
                __LINE__ = 71;
                a.assert( true,generator.next() === 8,"generator.next() === 8",71,'./yield_test.js' );
                
                __LINE__ = 73;
                a.assert( true,generator.next() === 0,"generator.next() === 0",73,'./yield_test.js' );
                
                __LINE__ = 74;
                a.assert( true,generator.next() === 2,"generator.next() === 2",74,'./yield_test.js' );
                
                __LINE__ = 75;
                a.assert( true,generator.next() === 4,"generator.next() === 4",75,'./yield_test.js' );
                
                __LINE__ = 76;
                a.assert( true,generator.next() === 6,"generator.next() === 6",76,'./yield_test.js' );
                
                __LINE__ = 77;
                a.assert( true,generator.next() === 8,"generator.next() === 8",77,'./yield_test.js' );
                
                __LINE__ = 79;
                a.assert( true,generator.next() === 0,"generator.next() === 0",79,'./yield_test.js' );
                
                __LINE__ = 80;
                a.assert( true,generator.next() === 2,"generator.next() === 2",80,'./yield_test.js' );
                
                __LINE__ = 81;
                a.assert( true,generator.next() === 4,"generator.next() === 4",81,'./yield_test.js' );
                
                __LINE__ = 82;
                a.assert( true,generator.next() === 6,"generator.next() === 6",82,'./yield_test.js' );
                
                __LINE__ = 83;
                a.assert( true,generator.next() === 8,"generator.next() === 8",83,'./yield_test.js' );
                
                __LINE__ = 85;
                a.assert( true,generator.next() === 0,"generator.next() === 0",85,'./yield_test.js' );
                
                __LINE__ = 86;
                a.assert( true,generator.next() === 2,"generator.next() === 2",86,'./yield_test.js' );
                
                __LINE__ = 87;
                a.assert( true,generator.next() === 4,"generator.next() === 4",87,'./yield_test.js' );
                
                __LINE__ = 88;
                a.assert( true,generator.next() === 6,"generator.next() === 6",88,'./yield_test.js' );
                
                __LINE__ = 89;
                a.assert( true,generator.next() === 8,"generator.next() === 8",89,'./yield_test.js' );
                
                __LINE__ = 91;
                a.assert( true,generator.next() === 0,"generator.next() === 0",91,'./yield_test.js' );
                
                __LINE__ = 92;
                a.assert( true,generator.next() === 2,"generator.next() === 2",92,'./yield_test.js' );
                
                __LINE__ = 93;
                a.assert( true,generator.next() === 4,"generator.next() === 4",93,'./yield_test.js' );
                
                __LINE__ = 94;
                a.assert( true,generator.next() === 6,"generator.next() === 6",94,'./yield_test.js' );
                
                __LINE__ = 95;
                a.assert( true,generator.next() === 8,"generator.next() === 8",95,'./yield_test.js' );
                
                __LINE__ = 97;
                a.assert( true,generator.next() === 0,"generator.next() === 0",97,'./yield_test.js' );
                
                __LINE__ = 98;
                a.assert( true,generator.next() === 2,"generator.next() === 2",98,'./yield_test.js' );
                
                __LINE__ = 99;
                a.assert( true,generator.next() === 4,"generator.next() === 4",99,'./yield_test.js' );
                
                __LINE__ = 100;
                a.assert( true,generator.next() === 6,"generator.next() === 6",100,'./yield_test.js' );
                
                __LINE__ = 101;
                a.assert( true,generator.next() === 8,"generator.next() === 8",101,'./yield_test.js' );
                
                __LINE__ = 103;
                a.assert( true,generator.next() === 0,"generator.next() === 0",103,'./yield_test.js' );
                
                __LINE__ = 104;
                a.assert( true,generator.next() === 2,"generator.next() === 2",104,'./yield_test.js' );
                
                __LINE__ = 105;
                a.assert( true,generator.next() === 4,"generator.next() === 4",105,'./yield_test.js' );
                
                __LINE__ = 106;
                a.assert( true,generator.next() === 6,"generator.next() === 6",106,'./yield_test.js' );
                
                __LINE__ = 107;
                a.assert( true,generator.next() === 8,"generator.next() === 8",107,'./yield_test.js' );
              } catch( e ){
                a.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case4 : function h() {
              try {
                __LINE__ = 0;
                function b(  ) {
                  try {
                    __LINE__ = 0;
                    var b = true,
                        e = undefined,
                        c = 0,
                        d,
                        f = function ( e,f ) {
                          try {
                            __LINE__ = 0;
                            if ( !e ){
                              __LINE__ = 0;
                              b = false;
                            } else if ( e && b && arguments[1] !== undefined ){
                              __LINE__ = 0;
                              a.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 117;
                            while ( 1 ){
                              __LINE__ = 117;
                              switch ( c ) {
                                case 0 :
                                  
                                  __LINE__ = 111;
                                  d = 0;
                                  
                                  __LINE__ = 112;
                                  if ( !(  ++ d<10 ) ){
                                    __LINE__ = 117;
                                    c = -1;
                                    __LINE__ = 117;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 0;
                                  c = 2;
                                  __LINE__ = 0;
                                  return d;
                                case 2 :
                                  
                                  __LINE__ = 117;
                                  if (  ++ d<10 ){
                                    __LINE__ = 117;
                                    c = 1;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 117;
                                    c = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 0;
                                  if ( f ){
                                    __LINE__ = 0;
                                    return undefined;
                                  } else {
                                    __LINE__ = 117;
                                    a.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            a.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 0;
                    return a.createGenerator( f,
                    function (  ) {
                      try {
                        __LINE__ = 0;
                        c = -1;
                      } catch( e ){
                        a.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    a.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
                
                __LINE__ = 0;
                generator = b();
                
                __LINE__ = 118;
                a.assert( true,generator.next() === 1,"generator.next() === 1",118,'./yield_test.js' );
                
                __LINE__ = 119;
                a.assert( true,generator.next() === 2,"generator.next() === 2",119,'./yield_test.js' );
                
                __LINE__ = 120;
                a.assert( true,generator.next() === 3,"generator.next() === 3",120,'./yield_test.js' );
                
                __LINE__ = 121;
                a.assert( true,generator.next() === 4,"generator.next() === 4",121,'./yield_test.js' );
                
                __LINE__ = 122;
                a.assert( true,generator.next() === 5,"generator.next() === 5",122,'./yield_test.js' );
                
                __LINE__ = 123;
                a.assert( true,generator.next() === 6,"generator.next() === 6",123,'./yield_test.js' );
                
                __LINE__ = 124;
                a.assert( true,generator.next() === 7,"generator.next() === 7",124,'./yield_test.js' );
                
                __LINE__ = 125;
                a.assert( true,generator.next() === 8,"generator.next() === 8",125,'./yield_test.js' );
                
                __LINE__ = 126;
                a.assert( true,generator.next() === 9,"generator.next() === 9",126,'./yield_test.js' );
              } catch( e ){
                a.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case5 : function i() {
              try {
                __LINE__ = 0;
                function b(  ) {
                  try {
                    __LINE__ = 0;
                    var b = true,
                        e = undefined,
                        c = 0,
                        d,
                        f = function ( e,f ) {
                          try {
                            __LINE__ = 0;
                            if ( !e ){
                              __LINE__ = 0;
                              b = false;
                            } else if ( e && b && arguments[1] !== undefined ){
                              __LINE__ = 0;
                              a.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 136;
                            while ( 1 ){
                              __LINE__ = 136;
                              switch ( c ) {
                                case 0 :
                                  
                                  __LINE__ = 130;
                                  d = 0;
                                case 1 :
                                  
                                  __LINE__ = 0;
                                  c = 2;
                                  __LINE__ = 0;
                                  return d;
                                case 2 :
                                  
                                  __LINE__ = 136;
                                  if (  ++ d<10 ){
                                    __LINE__ = 136;
                                    c = 1;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 136;
                                    c = 3;
                                  };
                                case 3 :
                                case -1 :
                                  
                                  __LINE__ = 0;
                                  if ( f ){
                                    __LINE__ = 0;
                                    return undefined;
                                  } else {
                                    __LINE__ = 136;
                                    a.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            a.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 0;
                    return a.createGenerator( f,
                    function (  ) {
                      try {
                        __LINE__ = 0;
                        c = -1;
                      } catch( e ){
                        a.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    a.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
                
                __LINE__ = 0;
                generator = b();
                
                __LINE__ = 137;
                a.assert( true,generator.next() === 0,"generator.next() === 0",137,'./yield_test.js' );
                
                __LINE__ = 138;
                a.assert( true,generator.next() === 1,"generator.next() === 1",138,'./yield_test.js' );
                
                __LINE__ = 139;
                a.assert( true,generator.next() === 2,"generator.next() === 2",139,'./yield_test.js' );
                
                __LINE__ = 140;
                a.assert( true,generator.next() === 3,"generator.next() === 3",140,'./yield_test.js' );
                
                __LINE__ = 141;
                a.assert( true,generator.next() === 4,"generator.next() === 4",141,'./yield_test.js' );
                
                __LINE__ = 142;
                a.assert( true,generator.next() === 5,"generator.next() === 5",142,'./yield_test.js' );
                
                __LINE__ = 143;
                a.assert( true,generator.next() === 6,"generator.next() === 6",143,'./yield_test.js' );
                
                __LINE__ = 144;
                a.assert( true,generator.next() === 7,"generator.next() === 7",144,'./yield_test.js' );
                
                __LINE__ = 145;
                a.assert( true,generator.next() === 8,"generator.next() === 8",145,'./yield_test.js' );
                
                __LINE__ = 146;
                a.assert( true,generator.next() === 9,"generator.next() === 9",146,'./yield_test.js' );
              } catch( e ){
                a.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case6 : function j() {
              try {
                __LINE__ = 0;
                function b(  ) {
                  try {
                    __LINE__ = 0;
                    var b = true,
                        e = undefined,
                        c = 0,
                        f,
                        d,
                        g = function ( g,h ) {
                          try {
                            __LINE__ = 0;
                            if ( !g ){
                              __LINE__ = 0;
                              b = false;
                            } else if ( g && b && arguments[1] !== undefined ){
                              __LINE__ = 0;
                              a.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 162;
                            while ( 1 ){
                              __LINE__ = 162;
                              switch ( c ) {
                                case 0 :
                                  
                                  __LINE__ = 150;
                                  d = 0;
                                  
                                  __LINE__ = 150;
                                  if ( !( d<10 ) ){
                                    __LINE__ = 162;
                                    c = -1;
                                    __LINE__ = 162;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 151;
                                  c = 2;
                                  __LINE__ = 151;
                                  return d;
                                case 2 :
                                  
                                  __LINE__ = 0;
                                  e = g && arguments.length>2?a.toArray( arguments,2 )[0] : g?d : undefined;
                                  
                                  __LINE__ = 151;
                                  f = e;
                                  
                                  __LINE__ = 152;
                                  if ( f === true ){
                                    __LINE__ = 162;
                                    c = 3;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 162;
                                    c = 5;
                                    __LINE__ = 0;
                                    break;
                                  };
                                case 3 :
                                  
                                  __LINE__ = 0;
                                  c = 4;
                                  __LINE__ = 0;
                                  return d+1;
                                case 4 :
                                  
                                  __LINE__ = 0;
                                  c = 9;
                                  __LINE__ = 0;
                                  break;
                                case 5 :
                                  
                                  __LINE__ = 154;
                                  if ( f === false ){
                                    __LINE__ = 162;
                                    c = 6;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 162;
                                    c = 8;
                                    __LINE__ = 0;
                                    break;
                                  };
                                case 6 :
                                  
                                  __LINE__ = 0;
                                  c = 7;
                                  __LINE__ = 0;
                                  return d-1;
                                case 7 :
                                  
                                  __LINE__ = 0;
                                  c = 9;
                                  __LINE__ = 0;
                                  break;
                                case 8 :
                                  
                                  __LINE__ = 0;
                                  c = 9;
                                  __LINE__ = 0;
                                  return d;
                                case 9 :
                                  
                                  __LINE__ = 0;
                                  d ++ ;
                                  
                                  __LINE__ = 162;
                                  if ( d<10 ){
                                    __LINE__ = 162;
                                    c = 1;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 162;
                                    c = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 0;
                                  if ( h ){
                                    __LINE__ = 0;
                                    return undefined;
                                  } else {
                                    __LINE__ = 162;
                                    a.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            a.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 0;
                    return a.createGenerator( g,
                    function (  ) {
                      try {
                        __LINE__ = 0;
                        c = -1;
                      } catch( e ){
                        a.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    a.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
                
                __LINE__ = 0;
                generator = b();
                
                __LINE__ = 163;
                a.assert( true,generator.next() === 0,"generator.next() === 0",163,'./yield_test.js' );
                
                __LINE__ = 164;
                a.assert( true,generator.send( true ) === 1,"generator.send( true ) === 1",164,'./yield_test.js' );
                
                __LINE__ = 165;
                a.assert( true,generator.send( false ) === 1,"generator.send( false ) === 1",165,'./yield_test.js' );
                
                __LINE__ = 166;
                a.assert( true,generator.send( true ) === 2,"generator.send( true ) === 2",166,'./yield_test.js' );
                
                __LINE__ = 167;
                a.assert( true,generator.send( false ) === 2,"generator.send( false ) === 2",167,'./yield_test.js' );
                
                __LINE__ = 168;
                a.assert( true,generator.send( true ) === 3,"generator.send( true ) === 3",168,'./yield_test.js' );
                
                __LINE__ = 169;
                a.assert( true,generator.send( true ) === 3,"generator.send( true ) === 3",169,'./yield_test.js' );
                
                __LINE__ = 170;
                a.assert( true,generator.send( true ) === 4,"generator.send( true ) === 4",170,'./yield_test.js' );
                
                __LINE__ = 171;
                a.assert( true,generator.send( false ) === 4,"generator.send( false ) === 4",171,'./yield_test.js' );
                
                __LINE__ = 172;
                a.assert( true,generator.send( true ) === 5,"generator.send( true ) === 5",172,'./yield_test.js' );
              } catch( e ){
                a.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case7 : function k() {
              try {
                __LINE__ = 0;
                function b(  ) {
                  try {
                    __LINE__ = 0;
                    var b = true,
                        e = undefined,
                        c = 0,
                        g,
                        f,
                        d,
                        h = function ( h,i ) {
                          try {
                            __LINE__ = 0;
                            if ( !h ){
                              __LINE__ = 0;
                              b = false;
                            } else if ( h && b && arguments[1] !== undefined ){
                              __LINE__ = 0;
                              a.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 191;
                            while ( 1 ){
                              __LINE__ = 191;
                              switch ( c ) {
                                case 0 :
                                  
                                  __LINE__ = 176;
                                  d = 0;
                                  
                                  __LINE__ = 176;
                                  if ( !( d<10 ) ){
                                    __LINE__ = 191;
                                    c = -1;
                                    __LINE__ = 191;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 177;
                                  c = 2;
                                  __LINE__ = 177;
                                  return d;
                                case 2 :
                                  
                                  __LINE__ = 0;
                                  e = h && arguments.length>2?a.toArray( arguments,2 )[0] : h?d : undefined;
                                  
                                  __LINE__ = 177;
                                  f = e;
                                  
                                  __LINE__ = 178;
                                  g = 0;
                                  
                                  __LINE__ = 178;
                                  if ( !( g<10 ) ){
                                    __LINE__ = 191;
                                    c = 11;
                                    __LINE__ = 191;
                                    break;
                                  };
                                case 3 :
                                  
                                  __LINE__ = 179;
                                  if ( f === true ){
                                    __LINE__ = 191;
                                    c = 4;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 191;
                                    c = 6;
                                    __LINE__ = 0;
                                    break;
                                  };
                                case 4 :
                                  
                                  __LINE__ = 0;
                                  c = 5;
                                  __LINE__ = 0;
                                  return g*2;
                                case 5 :
                                  
                                  __LINE__ = 0;
                                  c = 10;
                                  __LINE__ = 0;
                                  break;
                                case 6 :
                                  
                                  __LINE__ = 181;
                                  if ( f === false ){
                                    __LINE__ = 191;
                                    c = 7;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 191;
                                    c = 9;
                                    __LINE__ = 0;
                                    break;
                                  };
                                case 7 :
                                  
                                  __LINE__ = 0;
                                  c = 8;
                                  __LINE__ = 0;
                                  return g/2;
                                case 8 :
                                  
                                  __LINE__ = 0;
                                  c = 10;
                                  __LINE__ = 0;
                                  break;
                                case 9 :
                                  
                                  __LINE__ = 0;
                                  c = 10;
                                  __LINE__ = 0;
                                  return g;
                                case 10 :
                                  
                                  __LINE__ = 0;
                                  g ++ ;
                                  
                                  __LINE__ = 191;
                                  if ( g<10 ){
                                    __LINE__ = 191;
                                    c = 3;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 191;
                                    c = 11;
                                  };
                                case 11 :
                                  
                                  __LINE__ = 0;
                                  d ++ ;
                                  
                                  __LINE__ = 191;
                                  if ( d<10 ){
                                    __LINE__ = 191;
                                    c = 1;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 191;
                                    c = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 0;
                                  if ( i ){
                                    __LINE__ = 0;
                                    return undefined;
                                  } else {
                                    __LINE__ = 191;
                                    a.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            a.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 0;
                    return a.createGenerator( h,
                    function (  ) {
                      try {
                        __LINE__ = 0;
                        c = -1;
                      } catch( e ){
                        a.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    a.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
                
                __LINE__ = 0;
                generator = b();
                
                __LINE__ = 192;
                a.assert( true,generator.next() === 0,"generator.next() === 0",192,'./yield_test.js' );
                
                __LINE__ = 193;
                a.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",193,'./yield_test.js' );
                
                __LINE__ = 194;
                a.assert( true,generator.send( false ) === 2,"generator.send( false ) === 2",194,'./yield_test.js' );
                
                __LINE__ = 195;
                a.assert( true,generator.send( true ) === 4,"generator.send( true ) === 4",195,'./yield_test.js' );
                
                __LINE__ = 196;
                a.assert( true,generator.send( false ) === 6,"generator.send( false ) === 6",196,'./yield_test.js' );
                
                __LINE__ = 197;
                a.assert( true,generator.send( true ) === 8,"generator.send( true ) === 8",197,'./yield_test.js' );
                
                __LINE__ = 198;
                a.assert( true,generator.send( true ) === 10,"generator.send( true ) === 10",198,'./yield_test.js' );
                
                __LINE__ = 199;
                a.assert( true,generator.send( true ) === 12,"generator.send( true ) === 12",199,'./yield_test.js' );
                
                __LINE__ = 200;
                a.assert( true,generator.send( false ) === 14,"generator.send( false ) === 14",200,'./yield_test.js' );
                
                __LINE__ = 201;
                a.assert( true,generator.send( true ) === 16,"generator.send( true ) === 16",201,'./yield_test.js' );
                
                __LINE__ = 202;
                a.assert( true,generator.send( true ) === 18,"generator.send( true ) === 18",202,'./yield_test.js' );
                
                __LINE__ = 203;
                a.assert( true,generator.send( false ) === 1,"generator.send( false ) === 1",203,'./yield_test.js' );
                
                __LINE__ = 204;
                a.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",204,'./yield_test.js' );
                
                __LINE__ = 205;
                a.assert( true,generator.send( false ) === 2,"generator.send( false ) === 2",205,'./yield_test.js' );
                
                __LINE__ = 206;
                a.assert( true,generator.send( true ) === 4,"generator.send( true ) === 4",206,'./yield_test.js' );
                
                __LINE__ = 207;
                a.assert( true,generator.send( true ) === 6,"generator.send( true ) === 6",207,'./yield_test.js' );
                
                __LINE__ = 208;
                a.assert( true,generator.send( true ) === 8,"generator.send( true ) === 8",208,'./yield_test.js' );
                
                __LINE__ = 209;
                a.assert( true,generator.send( false ) === 10,"generator.send( false ) === 10",209,'./yield_test.js' );
                
                __LINE__ = 210;
                a.assert( true,generator.send( true ) === 12,"generator.send( true ) === 12",210,'./yield_test.js' );
              } catch( e ){
                a.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case8 : function l() {
              try {
                __LINE__ = 0;
                function b(  ) {
                  try {
                    __LINE__ = 0;
                    var b = true,
                        f = undefined,
                        c = 0,
                        g,
                        e,
                        d,
                        h = function ( h,i ) {
                          try {
                            __LINE__ = 0;
                            if ( !h ){
                              __LINE__ = 0;
                              b = false;
                            } else if ( h && b && arguments[1] !== undefined ){
                              __LINE__ = 0;
                              a.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 230;
                            while ( 1 ){
                              __LINE__ = 230;
                              switch ( c ) {
                                case 0 :
                                  
                                  __LINE__ = 215;
                                  d = 0;
                                  
                                  __LINE__ = 215;
                                  if ( !( d<10 ) ){
                                    __LINE__ = 230;
                                    c = -1;
                                    __LINE__ = 230;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 216;
                                  e = 0;
                                  
                                  __LINE__ = 216;
                                  if ( !( e<10 ) ){
                                    __LINE__ = 230;
                                    c = 11;
                                    __LINE__ = 230;
                                    break;
                                  };
                                case 2 :
                                  
                                  __LINE__ = 217;
                                  c = 3;
                                  __LINE__ = 217;
                                  return d;
                                case 3 :
                                  
                                  __LINE__ = 0;
                                  f = h && arguments.length>2?a.toArray( arguments,2 )[0] : h?d : undefined;
                                  
                                  __LINE__ = 217;
                                  g = f;
                                  
                                  __LINE__ = 218;
                                  if ( g === true ){
                                    __LINE__ = 230;
                                    c = 4;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 230;
                                    c = 6;
                                    __LINE__ = 0;
                                    break;
                                  };
                                case 4 :
                                  
                                  __LINE__ = 0;
                                  c = 5;
                                  __LINE__ = 0;
                                  return e*2;
                                case 5 :
                                  
                                  __LINE__ = 0;
                                  c = 10;
                                  __LINE__ = 0;
                                  break;
                                case 6 :
                                  
                                  __LINE__ = 220;
                                  if ( g === false ){
                                    __LINE__ = 230;
                                    c = 7;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 230;
                                    c = 9;
                                    __LINE__ = 0;
                                    break;
                                  };
                                case 7 :
                                  
                                  __LINE__ = 0;
                                  c = 8;
                                  __LINE__ = 0;
                                  return e/2;
                                case 8 :
                                  
                                  __LINE__ = 0;
                                  c = 10;
                                  __LINE__ = 0;
                                  break;
                                case 9 :
                                  
                                  __LINE__ = 0;
                                  c = 10;
                                  __LINE__ = 0;
                                  return e;
                                case 10 :
                                  
                                  __LINE__ = 0;
                                  e ++ ;
                                  
                                  __LINE__ = 230;
                                  if ( e<10 ){
                                    __LINE__ = 230;
                                    c = 2;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 230;
                                    c = 11;
                                  };
                                case 11 :
                                  
                                  __LINE__ = 0;
                                  d ++ ;
                                  
                                  __LINE__ = 230;
                                  if ( d<10 ){
                                    __LINE__ = 230;
                                    c = 1;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 230;
                                    c = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 0;
                                  if ( i ){
                                    __LINE__ = 0;
                                    return undefined;
                                  } else {
                                    __LINE__ = 230;
                                    a.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            a.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 0;
                    return a.createGenerator( h,
                    function (  ) {
                      try {
                        __LINE__ = 0;
                        c = -1;
                      } catch( e ){
                        a.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    a.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
                
                __LINE__ = 0;
                generator = b();
                
                __LINE__ = 231;
                a.assert( true,generator.next() === 0,"generator.next() === 0",231,'./yield_test.js' );
                
                __LINE__ = 232;
                a.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",232,'./yield_test.js' );
                
                __LINE__ = 233;
                a.assert( true,generator.send( false ) === 0,"generator.send( false ) === 0",233,'./yield_test.js' );
                
                __LINE__ = 234;
                a.assert( true,generator.send( true ) === 2,"generator.send( true ) === 2",234,'./yield_test.js' );
                
                __LINE__ = 235;
                a.assert( true,generator.send( false ) === 0,"generator.send( false ) === 0",235,'./yield_test.js' );
                
                __LINE__ = 236;
                a.assert( true,generator.send( true ) === 4,"generator.send( true ) === 4",236,'./yield_test.js' );
                
                __LINE__ = 237;
                a.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",237,'./yield_test.js' );
                
                __LINE__ = 238;
                a.assert( true,generator.send( true ) === 6,"generator.send( true ) === 6",238,'./yield_test.js' );
                
                __LINE__ = 239;
                a.assert( true,generator.send( false ) === 0,"generator.send( false ) === 0",239,'./yield_test.js' );
                
                __LINE__ = 240;
                a.assert( true,generator.send( true ) === 8,"generator.send( true ) === 8",240,'./yield_test.js' );
                
                __LINE__ = 241;
                a.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",241,'./yield_test.js' );
                
                __LINE__ = 242;
                a.assert( true,generator.send( false ) === 2.5,"generator.send( false ) === 2.5",242,'./yield_test.js' );
                
                __LINE__ = 243;
                a.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",243,'./yield_test.js' );
                
                __LINE__ = 244;
                a.assert( true,generator.send( false ) === 3,"generator.send( false ) === 3",244,'./yield_test.js' );
                
                __LINE__ = 245;
                a.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",245,'./yield_test.js' );
                
                __LINE__ = 246;
                a.assert( true,generator.send( true ) === 14,"generator.send( true ) === 14",246,'./yield_test.js' );
                
                __LINE__ = 247;
                a.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",247,'./yield_test.js' );
                
                __LINE__ = 248;
                a.assert( true,generator.send( false ) === 4,"generator.send( false ) === 4",248,'./yield_test.js' );
                
                __LINE__ = 249;
                a.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",249,'./yield_test.js' );
              } catch( e ){
                a.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case9 : function m() {
              try {
                __LINE__ = 0;
                function b(  ) {
                  try {
                    __LINE__ = 0;
                    var b = true,
                        i = undefined,
                        c = 0,
                        g,
                        f,
                        h,
                        e,
                        d,
                        j = function ( i,j ) {
                          try {
                            __LINE__ = 0;
                            if ( !i ){
                              __LINE__ = 0;
                              b = false;
                            } else if ( i && b && arguments[1] !== undefined ){
                              __LINE__ = 0;
                              a.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 266;
                            while ( 1 ){
                              try {
                                __LINE__ = 266;
                                switch ( c ) {
                                  case 0 :
                                    
                                    __LINE__ = 254;
                                    d = false;
                                    
                                    __LINE__ = 255;
                                    e = 0;
                                    
                                    __LINE__ = 255;
                                    if ( !( e<10 ) ){
                                      __LINE__ = 266;
                                      c = -1;
                                      __LINE__ = 266;
                                      break;
                                    };
                                  case 1 :
                                    
                                    __LINE__ = 0;
                                    c = 2;
                                    
                                    __LINE__ = 260;
                                    f = function ( b ) {
                                      try {
                                        __LINE__ = 266;
                                        c = 3;
                                      } catch( e ){
                                        a.exceptionHandler( __LINE__ , __FILE__ , e );
                                      }
                                    };
                                    
                                    __LINE__ = 0;
                                    g = function (  ) {
                                      try {
                                        __LINE__ = 0;
                                        d = true;
                                      } catch( e ){
                                        a.exceptionHandler( __LINE__ , __FILE__ , e );
                                      }
                                    };
                                    
                                    __LINE__ = 257;
                                    h = d?1 : 0;
                                    __LINE__ = 0;
                                    return h;
                                  case 2 :
                                    
                                    __LINE__ = 0;
                                    ddddd();
                                    
                                    __LINE__ = 0;
                                    f = undefined;
                                    
                                    __LINE__ = 0;
                                    g = undefined;
                                  case 3 :
                                    
                                    __LINE__ = 0;
                                    e ++ ;
                                    
                                    __LINE__ = 266;
                                    if ( e<10 ){
                                      __LINE__ = 266;
                                      c = 1;
                                      __LINE__ = 0;
                                      break;
                                    } else {
                                      __LINE__ = 266;
                                      c = -1;
                                    };
                                  case -1 :
                                    
                                    __LINE__ = 0;
                                    if ( j ){
                                      __LINE__ = 0;
                                      return undefined;
                                    } else {
                                      __LINE__ = 266;
                                      a.throwStopIteration();
                                    };
                                    
                                };
                              } catch( _mochaException ){
                                __LINE__ = 0;
                                if ( f ){
                                  __LINE__ = 0;
                                  var k = f( _mochaException );
                                  
                                  __LINE__ = 0;
                                  if ( k !== undefined ){
                                    __LINE__ = 0;
                                    return k;
                                  };
                                } else {
                                  __LINE__ = 0;
                                  a.throwException( _mochaException );
                                };
                              } finally {
                                __LINE__ = 0;
                                if ( g ){
                                  __LINE__ = 0;
                                  var _mochaLocalTmp1 = g(  );
                                  
                                  __LINE__ = 0;
                                  if ( _mochaLocalTmp1 !== undefined ){
                                    __LINE__ = 0;
                                    return _mochaLocalTmp1;
                                  };
                                };
                              };
                            };
                          } catch( e ){
                            a.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 0;
                    return a.createGenerator( j,
                    function (  ) {
                      try {
                        __LINE__ = 0;
                        c = -1;
                        
                        __LINE__ = 0;
                        if ( g ){
                          __LINE__ = 0;
                          g(  );
                        };
                      } catch( e ){
                        a.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    a.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
                
                __LINE__ = 0;
                generator = b();
                
                __LINE__ = 267;
                a.assert( true,generator.next() === 0,"generator.next() === 0",267,'./yield_test.js' );
                
                __LINE__ = 268;
                a.assert( true,generator.next() === 1,"generator.next() === 1",268,'./yield_test.js' );
                
                __LINE__ = 269;
                a.assert( true,generator.next() === 1,"generator.next() === 1",269,'./yield_test.js' );
                
                __LINE__ = 270;
                a.assert( true,generator.next() === 1,"generator.next() === 1",270,'./yield_test.js' );
                
                __LINE__ = 271;
                a.assert( true,generator.next() === 1,"generator.next() === 1",271,'./yield_test.js' );
              } catch( e ){
                a.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case10 : function n() {
              try {
                __LINE__ = 0;
                function b(  ) {
                  try {
                    __LINE__ = 0;
                    var b = true,
                        e = undefined,
                        c = 0,
                        f,
                        d,
                        g = function ( g,h ) {
                          try {
                            __LINE__ = 0;
                            if ( !g ){
                              __LINE__ = 0;
                              b = false;
                            } else if ( g && b && arguments[1] !== undefined ){
                              __LINE__ = 0;
                              a.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 289;
                            while ( 1 ){
                              __LINE__ = 289;
                              switch ( c ) {
                                case 0 :
                                  
                                  __LINE__ = 275;
                                  d = 0;
                                  
                                  __LINE__ = 275;
                                  if ( !( d<10 ) ){
                                    __LINE__ = 289;
                                    c = -1;
                                    __LINE__ = 289;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 276;
                                  c = 2;
                                  __LINE__ = 276;
                                  return ;
                                case 2 :
                                  
                                  __LINE__ = 0;
                                  e = g && arguments.length>2?a.toArray( arguments,2 )[0] : undefined;
                                  
                                  __LINE__ = 276;
                                  f = e;
                                  
                                  __LINE__ = 0;
                                  switch ( f ) {
                                    case 0 :
                                      
                                      __LINE__ = 0;
                                      c = 3;
                                      __LINE__ = 0;
                                      break;
                                    case 2 :
                                      
                                      __LINE__ = 0;
                                      c = 4;
                                      __LINE__ = 0;
                                      break;
                                    case 3 :
                                      
                                      __LINE__ = 0;
                                      c = 5;
                                      __LINE__ = 0;
                                      break;
                                    default :
                                      
                                      __LINE__ = 0;
                                      c = 6;
                                      __LINE__ = 0;
                                      break;
                                      
                                  };
                                  __LINE__ = 0;
                                  break;
                                case 3 :
                                  
                                  __LINE__ = 0;
                                  c = 7;
                                  __LINE__ = 0;
                                  return 200;
                                case 4 :
                                  
                                  __LINE__ = 0;
                                  c = 7;
                                  __LINE__ = 0;
                                  return 400;
                                case 5 :
                                  
                                  __LINE__ = 0;
                                  c = 7;
                                  __LINE__ = 0;
                                  return 600;
                                case 6 :
                                  
                                  __LINE__ = 0;
                                  c = 7;
                                  __LINE__ = 0;
                                  return 700;
                                case 7 :
                                  
                                  __LINE__ = 0;
                                  d ++ ;
                                  
                                  __LINE__ = 289;
                                  if ( d<10 ){
                                    __LINE__ = 289;
                                    c = 1;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 289;
                                    c = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 0;
                                  if ( h ){
                                    __LINE__ = 0;
                                    return undefined;
                                  } else {
                                    __LINE__ = 289;
                                    a.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            a.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 0;
                    return a.createGenerator( g,
                    function (  ) {
                      try {
                        __LINE__ = 0;
                        c = -1;
                      } catch( e ){
                        a.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    a.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
                
                __LINE__ = 0;
                generator = b();
                
                __LINE__ = 0;
                generator.next();
                
                __LINE__ = 291;
                a.assert( true,generator.send( 0 ) === 200,"generator.send( 0 ) === 200",291,'./yield_test.js' );
                
                __LINE__ = 0;
                generator.next();
                
                __LINE__ = 293;
                a.assert( true,generator.send( 2 ) === 400,"generator.send( 2 ) === 400",293,'./yield_test.js' );
                
                __LINE__ = 0;
                generator.next();
                
                __LINE__ = 295;
                a.assert( true,generator.send( 3 ) === 600,"generator.send( 3 ) === 600",295,'./yield_test.js' );
                
                __LINE__ = 0;
                generator.next();
                
                __LINE__ = 297;
                a.assert( true,generator.send( null ) === 700,"generator.send( null ) === 700",297,'./yield_test.js' );
              } catch( e ){
                a.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case11 : function o() {
              try {
                __LINE__ = 0;
                function b(  ) {
                  try {
                    __LINE__ = 0;
                    var b = true,
                        e = undefined,
                        c = 0,
                        f,
                        d,
                        g = function ( g,h ) {
                          try {
                            __LINE__ = 0;
                            if ( !g ){
                              __LINE__ = 0;
                              b = false;
                            } else if ( g && b && arguments[1] !== undefined ){
                              __LINE__ = 0;
                              a.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 320;
                            while ( 1 ){
                              __LINE__ = 320;
                              switch ( c ) {
                                case 0 :
                                  
                                  __LINE__ = 302;
                                  d = 0;
                                  
                                  __LINE__ = 302;
                                  if ( !( d<15 ) ){
                                    __LINE__ = 320;
                                    c = -1;
                                    __LINE__ = 320;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 303;
                                  c = 2;
                                  __LINE__ = 303;
                                  return ;
                                case 2 :
                                  
                                  __LINE__ = 0;
                                  e = g && arguments.length>2?a.toArray( arguments,2 )[0] : undefined;
                                  
                                  __LINE__ = 303;
                                  f = e;
                                  
                                  __LINE__ = 0;
                                  switch ( f ) {
                                    case 4 :
                                    case 0 :
                                      
                                      __LINE__ = 0;
                                      c = 3;
                                      __LINE__ = 0;
                                      break;
                                    case 5 :
                                      
                                      __LINE__ = 0;
                                      c = 7;
                                      __LINE__ = 0;
                                      break;
                                    case 6 :
                                    case 2 :
                                      
                                      __LINE__ = 0;
                                      c = 4;
                                      __LINE__ = 0;
                                      break;
                                    case 3 :
                                      
                                      __LINE__ = 0;
                                      c = 5;
                                      __LINE__ = 0;
                                      break;
                                    default :
                                      
                                      __LINE__ = 0;
                                      c = 6;
                                      __LINE__ = 0;
                                      break;
                                      
                                  };
                                  __LINE__ = 0;
                                  break;
                                case 3 :
                                  
                                  __LINE__ = 0;
                                  c = 8;
                                  __LINE__ = 0;
                                  return 200;
                                case 4 :
                                  
                                  __LINE__ = 0;
                                  c = 8;
                                  __LINE__ = 0;
                                  return 400;
                                case 5 :
                                  
                                  __LINE__ = 0;
                                  c = 8;
                                  __LINE__ = 0;
                                  return 600;
                                case 6 :
                                  
                                  __LINE__ = 0;
                                  c = 8;
                                  __LINE__ = 0;
                                  return 700;
                                case 7 :
                                  
                                  __LINE__ = 0;
                                  c = 8;
                                  __LINE__ = 0;
                                  break;
                                case 8 :
                                  
                                  __LINE__ = 0;
                                  d ++ ;
                                  
                                  __LINE__ = 320;
                                  if ( d<15 ){
                                    __LINE__ = 320;
                                    c = 1;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 320;
                                    c = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 0;
                                  if ( h ){
                                    __LINE__ = 0;
                                    return undefined;
                                  } else {
                                    __LINE__ = 320;
                                    a.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            a.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 0;
                    return a.createGenerator( g,
                    function (  ) {
                      try {
                        __LINE__ = 0;
                        c = -1;
                      } catch( e ){
                        a.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    a.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
                
                __LINE__ = 0;
                generator = b();
                
                __LINE__ = 0;
                generator.next();
                
                __LINE__ = 322;
                a.assert( true,generator.send( 0 ) === 200,"generator.send( 0 ) === 200",322,'./yield_test.js' );
                
                __LINE__ = 0;
                generator.next();
                
                __LINE__ = 324;
                a.assert( true,generator.send( 4 ) === 200,"generator.send( 4 ) === 200",324,'./yield_test.js' );
                
                __LINE__ = 0;
                generator.next();
                
                __LINE__ = 326;
                a.assert( true,generator.send( 2 ) === 400,"generator.send( 2 ) === 400",326,'./yield_test.js' );
                
                __LINE__ = 0;
                generator.next();
                
                __LINE__ = 328;
                a.assert( true,generator.send( 5 ) === undefined,"generator.send( 5 ) === undefined",328,'./yield_test.js' );
                
                __LINE__ = 329;
                a.assert( true,generator.send( 3 ) === 600,"generator.send( 3 ) === 600",329,'./yield_test.js' );
                
                __LINE__ = 0;
                generator.next();
                
                __LINE__ = 331;
                a.assert( true,generator.send( null ) === 700,"generator.send( null ) === 700",331,'./yield_test.js' );
              } catch( e ){
                a.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case12 : function p() {
              try {
                __LINE__ = 0;
                function b() {
                  try {
                    __LINE__ = 0;
                    var b = true,
                        i = undefined,
                        c = 0,
                        g,
                        f,
                        h,
                        d,
                        e = [],
                        j = function ( i,j ) {
                          try {
                            __LINE__ = 0;
                            if ( !i ){
                              __LINE__ = 0;
                              b = false;
                            } else if ( i && b && arguments[1] !== undefined ){
                              __LINE__ = 0;
                              a.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 342;
                            while ( 1 ){
                              __LINE__ = 342;
                              switch ( c ) {
                                case 0 :
                                  
                                  __LINE__ = 336;
                                  d =  {
                                    x : 200,
                                    y : 300,
                                    z : 400
                                  };
                                  
                                  __LINE__ = 337;
                                  for ( var k in d ){
                                    
                                    __LINE__ = 342;
                                    e.push( k );
                                  };
                                  
                                  __LINE__ = 337;
                                  f = 0;
                                  
                                  __LINE__ = 337;
                                  g = e.length;
                                  
                                  __LINE__ = 337;
                                  if ( !( f<g ) ){
                                    __LINE__ = 342;
                                    c = -1;
                                    __LINE__ = 342;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 0;
                                  c = 2;
                                  
                                  __LINE__ = 0;
                                  h = e[f];
                                  __LINE__ = 0;
                                  return [h,d[h]];
                                case 2 :
                                  
                                  __LINE__ = 0;
                                   ++ f;
                                  
                                  __LINE__ = 342;
                                  if ( f<g ){
                                    __LINE__ = 342;
                                    c = 1;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 342;
                                    c = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 0;
                                  if ( j ){
                                    __LINE__ = 0;
                                    return undefined;
                                  } else {
                                    __LINE__ = 342;
                                    a.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            a.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 0;
                    return a.createGenerator( j,
                    function (  ) {
                      try {
                        __LINE__ = 0;
                        c = -1;
                      } catch( e ){
                        a.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    a.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
                
                __LINE__ = 0;
                generator = b();
                
                __LINE__ = 343;
                var d = generator.next();
                
                __LINE__ = 344;
                a.assert( true,d[0] === "x","ret[0] === \"x\"",344,'./yield_test.js' );
                
                __LINE__ = 345;
                a.assert( true,d[1] === 200,"ret[1] === 200",345,'./yield_test.js' );
                
                __LINE__ = 0;
                d = generator.next();
                
                __LINE__ = 347;
                a.assert( true,d[0] === "y","ret[0] === \"y\"",347,'./yield_test.js' );
                
                __LINE__ = 348;
                a.assert( true,d[1] === 300,"ret[1] === 300",348,'./yield_test.js' );
                
                __LINE__ = 0;
                d = generator.next();
                
                __LINE__ = 350;
                a.assert( true,d[0] === "z","ret[0] === \"z\"",350,'./yield_test.js' );
                
                __LINE__ = 351;
                a.assert( true,d[1] === 400,"ret[1] === 400",351,'./yield_test.js' );
              } catch( e ){
                a.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case13 : function q() {
              try {
                __LINE__ = 0;
                function b( d ) {
                  try {
                    __LINE__ = 0;
                    var b = true,
                        i = undefined,
                        c = 0,
                        g,
                        f,
                        h,
                        e = [],
                        j = function ( i,j ) {
                          try {
                            __LINE__ = 0;
                            if ( !i ){
                              __LINE__ = 0;
                              b = false;
                            } else if ( i && b && arguments[1] !== undefined ){
                              __LINE__ = 0;
                              a.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 362;
                            while ( 1 ){
                              __LINE__ = 362;
                              switch ( c ) {
                                case 0 :
                                  
                                  __LINE__ = 355;
                                  for ( var k in d ){
                                    
                                    __LINE__ = 362;
                                    e.push( k );
                                  };
                                  
                                  __LINE__ = 355;
                                  f = 0;
                                  
                                  __LINE__ = 355;
                                  g = e.length;
                                  
                                  __LINE__ = 355;
                                  if ( !( f<g ) ){
                                    __LINE__ = 362;
                                    c = -1;
                                    __LINE__ = 362;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 0;
                                  h = e[f];
                                  
                                  __LINE__ = 356;
                                  if ( d.hasOwnProperty( h ) ){
                                    __LINE__ = 362;
                                    c = 2;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 362;
                                    c = 3;
                                    __LINE__ = 0;
                                    break;
                                  };
                                case 2 :
                                  
                                  __LINE__ = 0;
                                  c = 3;
                                  __LINE__ = 0;
                                  return h;
                                case 3 :
                                  
                                  __LINE__ = 0;
                                  c = 4;
                                  __LINE__ = 0;
                                  break;
                                case 4 :
                                  
                                  __LINE__ = 0;
                                   ++ f;
                                  
                                  __LINE__ = 362;
                                  if ( f<g ){
                                    __LINE__ = 362;
                                    c = 1;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 362;
                                    c = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 0;
                                  if ( j ){
                                    __LINE__ = 0;
                                    return undefined;
                                  } else {
                                    __LINE__ = 362;
                                    a.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            a.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 0;
                    return a.createGenerator( j,
                    function (  ) {
                      try {
                        __LINE__ = 0;
                        c = -1;
                      } catch( e ){
                        a.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    a.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
                
                __LINE__ = 362;
                var c =  {
                      value1 : 1,
                      value2 : 2,
                      value3 : 3,
                      value4 : 4
                    };
                
                try {
                  __LINE__ = 369;
                  var d = b( c );
                  
                  __LINE__ = 370;
                  a.assert( true,d.next() == "value1","itemGen.next() == \"value1\"",370,'./yield_test.js' );
                  
                  __LINE__ = 371;
                  a.assert( true,d.next() == "value2","itemGen.next() == \"value2\"",371,'./yield_test.js' );
                  
                  __LINE__ = 372;
                  a.assert( true,d.next() == "value3","itemGen.next() == \"value3\"",372,'./yield_test.js' );
                  
                  __LINE__ = 373;
                  a.assert( true,d.next() == "value4","itemGen.next() == \"value4\"",373,'./yield_test.js' );
                } catch( e ){
                  
                };
              } catch( e ){
                a.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            }
          };
      
      __LINE__ = 382;
      for ( var c = 1;c<13;c ++  ){
        
        __LINE__ = 0;
        r["case"+c]();
      };
    } catch( e ){
      a.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  }();
}();
