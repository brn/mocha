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
      var __FILE__ = "/Users/aono_taketoshi/.mocha/module/iterators.js",
          __LINE__ = 0;
      __LINE__ = 2;
      b['../../../../../../.mocha/module/iterators.js'] = {};
      
      __LINE__ = 3;
      var c = b['../../../../../../.mocha/module/iterators.js'];
      
      __LINE__ = 1;
      !function () {
        try {
          __LINE__ = 1;
          var e = c,
              d = {}.hasOwnProperty,
              b = e.iterator = "__mocha_iterator_special_key__";
          
          __LINE__ = 0;
          function f( c ) {
            try {
              __LINE__ = 0;
              var e =  {
                    
                  };
              
              __LINE__ = 0;
              a.createUnenumProp( e,b,
              function () {
                try {
                  __LINE__ = 12;
                  return function () {
                    try {
                      __LINE__ = 0;
                      var b = true,
                          j = undefined,
                          e = 0,
                          h,
                          g,
                          i,
                          f = [],
                          k = function ( j,k ) {
                            try {
                              __LINE__ = 0;
                              if ( !j ){
                                __LINE__ = 0;
                                b = false;
                              } else if ( j && b && arguments[1] !== undefined ){
                                __LINE__ = 0;
                                a.exceptionHandler( 'attempt to send to newborn generator.' );
                              };
                              
                              __LINE__ = 0;
                              while ( 1 ){
                                __LINE__ = 0;
                                switch ( e ) {
                                  case 0 :
                                    
                                    __LINE__ = 0;
                                    for ( var l in c ){
                                      
                                      __LINE__ = 0;
                                      f.push( l );
                                    };
                                    
                                    __LINE__ = 7;
                                    g = 0;
                                    
                                    __LINE__ = 7;
                                    h = f.length;
                                    
                                    __LINE__ = 0;
                                    if ( !( g<h ) ){
                                      __LINE__ = 0;
                                      e = -1;
                                      __LINE__ = 0;
                                      break;
                                    };
                                  case 1 :
                                    
                                    __LINE__ = 0;
                                    i = f[g];
                                    
                                    __LINE__ = 0;
                                    if ( d.call( c,i ) ){
                                      __LINE__ = 0;
                                      e = 2;
                                      __LINE__ = 0;
                                      break;
                                    } else {
                                      __LINE__ = 0;
                                      e = 3;
                                      __LINE__ = 0;
                                      break;
                                    };
                                  case 2 :
                                    
                                    __LINE__ = 0;
                                    e = 3;
                                    __LINE__ = 0;
                                    return i;
                                  case 3 :
                                    
                                    __LINE__ = 0;
                                    e = 4;
                                    __LINE__ = 0;
                                    break;
                                  case 4 :
                                    
                                    __LINE__ = 0;
                                     ++ g;
                                    
                                    __LINE__ = 0;
                                    if ( g<h ){
                                      __LINE__ = 0;
                                      e = 1;
                                      __LINE__ = 0;
                                      break;
                                    } else {
                                      __LINE__ = 0;
                                      e = -1;
                                    };
                                  case -1 :
                                    
                                    __LINE__ = 0;
                                    if ( k ){
                                      __LINE__ = 0;
                                      return undefined;
                                    } else {
                                      __LINE__ = 0;
                                      a.throwStopIteration();
                                    };
                                    
                                };
                              };
                            } catch( e ){
                              a.exceptionHandler( __LINE__ , __FILE__ , e );
                            }
                          };
                      __LINE__ = 0;
                      return a.createGenerator( k,
                      function (  ) {
                        try {
                          __LINE__ = 0;
                          e = -1;
                        } catch( e ){
                          a.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      },this);
                    } catch( e ){
                      a.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  }();
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              });
              __LINE__ = 5;
              return e;
            } catch( e ){
              a.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          e.keys = f;
          
          __LINE__ = 0;
          function g( c ) {
            try {
              __LINE__ = 0;
              var e =  {
                    
                  };
              
              __LINE__ = 0;
              a.createUnenumProp( e,b,
              function () {
                try {
                  __LINE__ = 23;
                  return function () {
                    try {
                      __LINE__ = 0;
                      var b = true,
                          j = undefined,
                          e = 0,
                          h,
                          g,
                          i,
                          f = [],
                          k = function ( j,k ) {
                            try {
                              __LINE__ = 0;
                              if ( !j ){
                                __LINE__ = 0;
                                b = false;
                              } else if ( j && b && arguments[1] !== undefined ){
                                __LINE__ = 0;
                                a.exceptionHandler( 'attempt to send to newborn generator.' );
                              };
                              
                              __LINE__ = 0;
                              while ( 1 ){
                                __LINE__ = 0;
                                switch ( e ) {
                                  case 0 :
                                    
                                    __LINE__ = 0;
                                    for ( var l in c ){
                                      
                                      __LINE__ = 0;
                                      f.push( l );
                                    };
                                    
                                    __LINE__ = 18;
                                    g = 0;
                                    
                                    __LINE__ = 18;
                                    h = f.length;
                                    
                                    __LINE__ = 0;
                                    if ( !( g<h ) ){
                                      __LINE__ = 0;
                                      e = -1;
                                      __LINE__ = 0;
                                      break;
                                    };
                                  case 1 :
                                    
                                    __LINE__ = 0;
                                    i = f[g];
                                    
                                    __LINE__ = 0;
                                    if ( d.call( c,i ) ){
                                      __LINE__ = 0;
                                      e = 2;
                                      __LINE__ = 0;
                                      break;
                                    } else {
                                      __LINE__ = 0;
                                      e = 3;
                                      __LINE__ = 0;
                                      break;
                                    };
                                  case 2 :
                                    
                                    __LINE__ = 0;
                                    e = 3;
                                    __LINE__ = 0;
                                    return c[i];
                                  case 3 :
                                    
                                    __LINE__ = 0;
                                    e = 4;
                                    __LINE__ = 0;
                                    break;
                                  case 4 :
                                    
                                    __LINE__ = 0;
                                     ++ g;
                                    
                                    __LINE__ = 0;
                                    if ( g<h ){
                                      __LINE__ = 0;
                                      e = 1;
                                      __LINE__ = 0;
                                      break;
                                    } else {
                                      __LINE__ = 0;
                                      e = -1;
                                    };
                                  case -1 :
                                    
                                    __LINE__ = 0;
                                    if ( k ){
                                      __LINE__ = 0;
                                      return undefined;
                                    } else {
                                      __LINE__ = 0;
                                      a.throwStopIteration();
                                    };
                                    
                                };
                              };
                            } catch( e ){
                              a.exceptionHandler( __LINE__ , __FILE__ , e );
                            }
                          };
                      __LINE__ = 0;
                      return a.createGenerator( k,
                      function (  ) {
                        try {
                          __LINE__ = 0;
                          e = -1;
                        } catch( e ){
                          a.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      },this);
                    } catch( e ){
                      a.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  }();
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              });
              __LINE__ = 16;
              return e;
            } catch( e ){
              a.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          e.values = g;
          
          __LINE__ = 0;
          function h( c ) {
            try {
              __LINE__ = 0;
              var e =  {
                    
                  };
              
              __LINE__ = 0;
              a.createUnenumProp( e,b,
              function () {
                try {
                  __LINE__ = 34;
                  return function () {
                    try {
                      __LINE__ = 0;
                      var b = true,
                          j = undefined,
                          e = 0,
                          h,
                          g,
                          i,
                          f = [],
                          k = function ( j,k ) {
                            try {
                              __LINE__ = 0;
                              if ( !j ){
                                __LINE__ = 0;
                                b = false;
                              } else if ( j && b && arguments[1] !== undefined ){
                                __LINE__ = 0;
                                a.exceptionHandler( 'attempt to send to newborn generator.' );
                              };
                              
                              __LINE__ = 0;
                              while ( 1 ){
                                __LINE__ = 0;
                                switch ( e ) {
                                  case 0 :
                                    
                                    __LINE__ = 0;
                                    for ( var l in c ){
                                      
                                      __LINE__ = 0;
                                      f.push( l );
                                    };
                                    
                                    __LINE__ = 29;
                                    g = 0;
                                    
                                    __LINE__ = 29;
                                    h = f.length;
                                    
                                    __LINE__ = 0;
                                    if ( !( g<h ) ){
                                      __LINE__ = 0;
                                      e = -1;
                                      __LINE__ = 0;
                                      break;
                                    };
                                  case 1 :
                                    
                                    __LINE__ = 0;
                                    i = f[g];
                                    
                                    __LINE__ = 0;
                                    if ( d.call( c,i ) ){
                                      __LINE__ = 0;
                                      e = 2;
                                      __LINE__ = 0;
                                      break;
                                    } else {
                                      __LINE__ = 0;
                                      e = 3;
                                      __LINE__ = 0;
                                      break;
                                    };
                                  case 2 :
                                    
                                    __LINE__ = 0;
                                    e = 3;
                                    __LINE__ = 0;
                                    return [i,c[i]];
                                  case 3 :
                                    
                                    __LINE__ = 0;
                                    e = 4;
                                    __LINE__ = 0;
                                    break;
                                  case 4 :
                                    
                                    __LINE__ = 0;
                                     ++ g;
                                    
                                    __LINE__ = 0;
                                    if ( g<h ){
                                      __LINE__ = 0;
                                      e = 1;
                                      __LINE__ = 0;
                                      break;
                                    } else {
                                      __LINE__ = 0;
                                      e = -1;
                                    };
                                  case -1 :
                                    
                                    __LINE__ = 0;
                                    if ( k ){
                                      __LINE__ = 0;
                                      return undefined;
                                    } else {
                                      __LINE__ = 0;
                                      a.throwStopIteration();
                                    };
                                    
                                };
                              };
                            } catch( e ){
                              a.exceptionHandler( __LINE__ , __FILE__ , e );
                            }
                          };
                      __LINE__ = 0;
                      return a.createGenerator( k,
                      function (  ) {
                        try {
                          __LINE__ = 0;
                          e = -1;
                        } catch( e ){
                          a.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      },this);
                    } catch( e ){
                      a.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  }();
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              });
              __LINE__ = 27;
              return e;
            } catch( e ){
              a.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          e.items = h;
          
          __LINE__ = 0;
          function i( c ) {
            try {
              __LINE__ = 0;
              var d =  {
                    
                  };
              
              __LINE__ = 0;
              a.createUnenumProp( d,b,
              function () {
                try {
                  __LINE__ = 42;
                  return function () {
                    try {
                      __LINE__ = 0;
                      var b = true,
                          i = undefined,
                          d = 0,
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
                              
                              __LINE__ = 0;
                              while ( 1 ){
                                __LINE__ = 0;
                                switch ( d ) {
                                  case 0 :
                                    
                                    __LINE__ = 0;
                                    for ( var k in c ){
                                      
                                      __LINE__ = 0;
                                      e.push( k );
                                    };
                                    
                                    __LINE__ = 39;
                                    f = 0;
                                    
                                    __LINE__ = 39;
                                    g = e.length;
                                    
                                    __LINE__ = 0;
                                    if ( !( f<g ) ){
                                      __LINE__ = 0;
                                      d = -1;
                                      __LINE__ = 0;
                                      break;
                                    };
                                  case 1 :
                                    
                                    __LINE__ = 0;
                                    d = 2;
                                    
                                    __LINE__ = 0;
                                    h = e[f];
                                    __LINE__ = 0;
                                    return h;
                                  case 2 :
                                    
                                    __LINE__ = 0;
                                     ++ f;
                                    
                                    __LINE__ = 0;
                                    if ( f<g ){
                                      __LINE__ = 0;
                                      d = 1;
                                      __LINE__ = 0;
                                      break;
                                    } else {
                                      __LINE__ = 0;
                                      d = -1;
                                    };
                                  case -1 :
                                    
                                    __LINE__ = 0;
                                    if ( j ){
                                      __LINE__ = 0;
                                      return undefined;
                                    } else {
                                      __LINE__ = 0;
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
                          d = -1;
                        } catch( e ){
                          a.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      },this);
                    } catch( e ){
                      a.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  }();
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              });
              __LINE__ = 37;
              return d;
            } catch( e ){
              a.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          e.allKeys = i;
          
          __LINE__ = 0;
          function j( c ) {
            try {
              __LINE__ = 0;
              var d =  {
                    
                  };
              
              __LINE__ = 0;
              a.createUnenumProp( d,b,
              function () {
                try {
                  __LINE__ = 50;
                  return function () {
                    try {
                      __LINE__ = 0;
                      var b = true,
                          i = undefined,
                          d = 0,
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
                              
                              __LINE__ = 0;
                              while ( 1 ){
                                __LINE__ = 0;
                                switch ( d ) {
                                  case 0 :
                                    
                                    __LINE__ = 0;
                                    for ( var k in c ){
                                      
                                      __LINE__ = 0;
                                      e.push( k );
                                    };
                                    
                                    __LINE__ = 47;
                                    f = 0;
                                    
                                    __LINE__ = 47;
                                    g = e.length;
                                    
                                    __LINE__ = 0;
                                    if ( !( f<g ) ){
                                      __LINE__ = 0;
                                      d = -1;
                                      __LINE__ = 0;
                                      break;
                                    };
                                  case 1 :
                                    
                                    __LINE__ = 0;
                                    d = 2;
                                    
                                    __LINE__ = 0;
                                    h = e[f];
                                    __LINE__ = 0;
                                    return c[h];
                                  case 2 :
                                    
                                    __LINE__ = 0;
                                     ++ f;
                                    
                                    __LINE__ = 0;
                                    if ( f<g ){
                                      __LINE__ = 0;
                                      d = 1;
                                      __LINE__ = 0;
                                      break;
                                    } else {
                                      __LINE__ = 0;
                                      d = -1;
                                    };
                                  case -1 :
                                    
                                    __LINE__ = 0;
                                    if ( j ){
                                      __LINE__ = 0;
                                      return undefined;
                                    } else {
                                      __LINE__ = 0;
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
                          d = -1;
                        } catch( e ){
                          a.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      },this);
                    } catch( e ){
                      a.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  }();
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              });
              __LINE__ = 45;
              return d;
            } catch( e ){
              a.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          e.allValues = j;
          
          __LINE__ = 0;
          function k( c ) {
            try {
              __LINE__ = 0;
              var d =  {
                    
                  };
              
              __LINE__ = 0;
              a.createUnenumProp( d,b,
              function () {
                try {
                  __LINE__ = 58;
                  return function () {
                    try {
                      __LINE__ = 0;
                      var b = true,
                          i = undefined,
                          d = 0,
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
                              
                              __LINE__ = 0;
                              while ( 1 ){
                                __LINE__ = 0;
                                switch ( d ) {
                                  case 0 :
                                    
                                    __LINE__ = 0;
                                    for ( var k in c ){
                                      
                                      __LINE__ = 0;
                                      e.push( k );
                                    };
                                    
                                    __LINE__ = 55;
                                    f = 0;
                                    
                                    __LINE__ = 55;
                                    g = e.length;
                                    
                                    __LINE__ = 0;
                                    if ( !( f<g ) ){
                                      __LINE__ = 0;
                                      d = -1;
                                      __LINE__ = 0;
                                      break;
                                    };
                                  case 1 :
                                    
                                    __LINE__ = 0;
                                    d = 2;
                                    
                                    __LINE__ = 0;
                                    h = e[f];
                                    __LINE__ = 0;
                                    return [h,c[h]];
                                  case 2 :
                                    
                                    __LINE__ = 0;
                                     ++ f;
                                    
                                    __LINE__ = 0;
                                    if ( f<g ){
                                      __LINE__ = 0;
                                      d = 1;
                                      __LINE__ = 0;
                                      break;
                                    } else {
                                      __LINE__ = 0;
                                      d = -1;
                                    };
                                  case -1 :
                                    
                                    __LINE__ = 0;
                                    if ( j ){
                                      __LINE__ = 0;
                                      return undefined;
                                    } else {
                                      __LINE__ = 0;
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
                          d = -1;
                        } catch( e ){
                          a.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      },this);
                    } catch( e ){
                      a.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  }();
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              });
              __LINE__ = 53;
              return d;
            } catch( e ){
              a.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          e.allItems = k;
          __LINE__ = 0;
          return e;
        } catch( e ){
          a.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }();
    } catch( e ){
      a.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  }();
  
  __LINE__ = 0;
  !function () {
    try {
      var __FILE__ = "/Users/aono_taketoshi/github/mocha/src/test/js/harmony/for_of_test.js",
          __LINE__ = 0;
      __LINE__ = 2;
      b['./for_of_test.js'] = {};
      
      __LINE__ = 3;
      var e = b['./for_of_test.js'],
          f = b['../../../../../../.mocha/module/iterators.js'],
          c = f.iterator,
          g =  {
            arr : [],
            add : function ( b ) {
              try {
                __LINE__ = 0;
                this.arr.push( b );
              } catch( e ){
                a.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            
          };
      
      __LINE__ = 0;
      a.createUnenumProp( g,c,
      function () {
        try {
          __LINE__ = 0;
          var b = this.arr;
          __LINE__ = 27;
          return  {
            index : 0,
            next : function () {
              try {
                __LINE__ = 0;
                if ( b.length>this.index ){
                  __LINE__ = 0;
                  var c = b[this.index];
                  
                  __LINE__ = 0;
                  this.index ++ ;
                  __LINE__ = 33;
                  return c;
                } else {
                  __LINE__ = 0;
                  return undefined;
                };
              } catch( e ){
                a.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            }
          };
        } catch( e ){
          a.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      });
      
      __LINE__ = 2;
      var h = function ( b ) {
            try {
              __LINE__ = 0;
              var e =  {
                    
                  };
              
              __LINE__ = 0;
              a.createUnenumProp( e,c,
              function () {
                try {
                  __LINE__ = 0;
                  var c = true,
                      i = undefined,
                      d = 0,
                      g,
                      f,
                      h,
                      e = [],
                      j = function ( i,j ) {
                        try {
                          __LINE__ = 0;
                          if ( !i ){
                            __LINE__ = 0;
                            c = false;
                          } else if ( i && c && arguments[1] !== undefined ){
                            __LINE__ = 0;
                            a.exceptionHandler( 'attempt to send to newborn generator.' );
                          };
                          
                          __LINE__ = 0;
                          while ( 1 ){
                            __LINE__ = 0;
                            switch ( d ) {
                              case 0 :
                                
                                __LINE__ = 0;
                                for ( var k in b ){
                                  
                                  __LINE__ = 9;
                                  e.push( k );
                                };
                                
                                __LINE__ = 5;
                                f = 0;
                                
                                __LINE__ = 5;
                                g = e.length;
                                
                                __LINE__ = 0;
                                if ( !( f<g ) ){
                                  __LINE__ = 9;
                                  d = -1;
                                  __LINE__ = 9;
                                  break;
                                };
                              case 1 :
                                
                                __LINE__ = 0;
                                d = 2;
                                
                                __LINE__ = 0;
                                h = e[f];
                                
                                __LINE__ = 0;
                                h = b[h];
                                __LINE__ = 0;
                                return h;
                              case 2 :
                                
                                __LINE__ = 0;
                                 ++ f;
                                
                                __LINE__ = 0;
                                if ( f<g ){
                                  __LINE__ = 9;
                                  d = 1;
                                  __LINE__ = 0;
                                  break;
                                } else {
                                  __LINE__ = 9;
                                  d = -1;
                                };
                              case -1 :
                                
                                __LINE__ = 0;
                                if ( j ){
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
                  return a.createGenerator( j,
                  function (  ) {
                    try {
                      __LINE__ = 0;
                      d = -1;
                    } catch( e ){
                      a.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  },this);
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              });
              __LINE__ = 3;
              return e;
            } catch( e ){
              a.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          },
          i = function ( b ) {
            try {
              __LINE__ = 0;
              var e =  {
                    
                  };
              
              __LINE__ = 0;
              a.createUnenumProp( e,c,
              function () {
                try {
                  __LINE__ = 0;
                  var c = true,
                      i = undefined,
                      d = 0,
                      g,
                      f,
                      h,
                      e = [],
                      j = function ( i,j ) {
                        try {
                          __LINE__ = 0;
                          if ( !i ){
                            __LINE__ = 0;
                            c = false;
                          } else if ( i && c && arguments[1] !== undefined ){
                            __LINE__ = 0;
                            a.exceptionHandler( 'attempt to send to newborn generator.' );
                          };
                          
                          __LINE__ = 0;
                          while ( 1 ){
                            __LINE__ = 0;
                            switch ( d ) {
                              case 0 :
                                
                                __LINE__ = 0;
                                for ( var k in b ){
                                  
                                  __LINE__ = 18;
                                  e.push( k );
                                };
                                
                                __LINE__ = 14;
                                f = 0;
                                
                                __LINE__ = 14;
                                g = e.length;
                                
                                __LINE__ = 0;
                                if ( !( f<g ) ){
                                  __LINE__ = 18;
                                  d = -1;
                                  __LINE__ = 18;
                                  break;
                                };
                              case 1 :
                                
                                __LINE__ = 0;
                                d = 2;
                                
                                __LINE__ = 0;
                                h = e[f];
                                __LINE__ = 0;
                                return h;
                              case 2 :
                                
                                __LINE__ = 0;
                                 ++ f;
                                
                                __LINE__ = 0;
                                if ( f<g ){
                                  __LINE__ = 18;
                                  d = 1;
                                  __LINE__ = 0;
                                  break;
                                } else {
                                  __LINE__ = 18;
                                  d = -1;
                                };
                              case -1 :
                                
                                __LINE__ = 0;
                                if ( j ){
                                  __LINE__ = 0;
                                  return undefined;
                                } else {
                                  __LINE__ = 18;
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
                      d = -1;
                    } catch( e ){
                      a.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  },this);
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              });
              __LINE__ = 12;
              return e;
            } catch( e ){
              a.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          },
          j = g,
          k =  {
            value1 : 100,
            value2 : 200,
            value3 : 300,
            value4 : 400
          },
          l = [],
          d,
          m = h( k );
      
      __LINE__ = 0;
      m = a.hasIterator( m )?a.getIterator( m ) : m;
      
      __LINE__ = 0;
      if ( m.__nothrowNext__ ){
        __LINE__ = 0;
        while ( ( d = m.__nothrowNext__(  ) ) ){
          __LINE__ = 0;
          l.push( d );
        };
      } else {
        __LINE__ = 0;
        a.exceptionHandler( 49,'./for_of_test.js','for of statement expect iterator or generator object.' );
      };
      
      __LINE__ = 52;
      a.assert( true,l[0] === 100,"ret[0] === 100",52,'./for_of_test.js' );
      
      __LINE__ = 53;
      a.assert( true,l[1] === 200,"ret[1] === 200",53,'./for_of_test.js' );
      
      __LINE__ = 54;
      a.assert( true,l[2] === 300,"ret[2] === 300",54,'./for_of_test.js' );
      
      __LINE__ = 55;
      a.assert( true,l[3] === 400,"ret[3] === 400",55,'./for_of_test.js' );
      
      __LINE__ = 0;
      l = [];
      
      __LINE__ = 0;
      var n,
          o = i( k );
      
      __LINE__ = 0;
      o = a.hasIterator( o )?a.getIterator( o ) : o;
      
      __LINE__ = 0;
      if ( o.__nothrowNext__ ){
        __LINE__ = 0;
        while ( ( n = o.__nothrowNext__(  ) ) ){
          __LINE__ = 0;
          l.push( n );
        };
      } else {
        __LINE__ = 0;
        a.exceptionHandler( 58,'./for_of_test.js','for of statement expect iterator or generator object.' );
      };
      
      __LINE__ = 61;
      a.assert( true,l[0] === "value1","ret[0] === \"value1\"",61,'./for_of_test.js' );
      
      __LINE__ = 62;
      a.assert( true,l[1] === "value2","ret[1] === \"value2\"",62,'./for_of_test.js' );
      
      __LINE__ = 63;
      a.assert( true,l[2] === "value3","ret[2] === \"value3\"",63,'./for_of_test.js' );
      
      __LINE__ = 64;
      a.assert( true,l[3] === "value4","ret[3] === \"value4\"",64,'./for_of_test.js' );
      
      __LINE__ = 0;
      l = [];
      
      __LINE__ = 0;
      j.add( 100 );
      
      __LINE__ = 0;
      j.add( 200 );
      
      __LINE__ = 0;
      j.add( 300 );
      
      __LINE__ = 0;
      j.add( 400 );
      
      __LINE__ = 0;
      var p = j;
      
      __LINE__ = 0;
      p = a.hasIterator( p )?a.getIterator( p ) : p;
      
      __LINE__ = 0;
      if ( p.__nothrowNext__ ){
        __LINE__ = 0;
        while ( ( d = p.__nothrowNext__(  ) ) ){
          __LINE__ = 0;
          l.push( d );
        };
      } else {
        __LINE__ = 0;
        a.exceptionHandler( 71,'./for_of_test.js','for of statement expect iterator or generator object.' );
      };
      
      __LINE__ = 74;
      a.assert( true,l[0] === 100,"ret[0] === 100",74,'./for_of_test.js' );
      
      __LINE__ = 75;
      a.assert( true,l[1] === 200,"ret[1] === 200",75,'./for_of_test.js' );
      
      __LINE__ = 76;
      a.assert( true,l[2] === 300,"ret[2] === 300",76,'./for_of_test.js' );
      
      __LINE__ = 77;
      a.assert( true,l[3] === 400,"ret[3] === 400",77,'./for_of_test.js' );
    } catch( e ){
      a.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  }();
}();
