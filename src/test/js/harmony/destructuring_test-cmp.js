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
      var __FILE__ = "/Users/aono_taketoshi/github/mocha/src/test/js/harmony/destructuring_test.js",
          __LINE__ = 0;
      __LINE__ = 2;
      b['./destructuring_test.js'] = {};
      
      __LINE__ = 3;
      var e = b['./destructuring_test.js'],
          c =  {
            value1 : 100,
            value2 :  {
              value3 : 100
            },
            value4 : [100,200,300],
            value5 :  {
              value6 : [ {
                value7 : 100
              }]
            },
            "@value" :  {
              strvalue : 100
            }
          },
          d = [ {
            value1 : 100
          },200, {
            value2 : 100
          }, {
            "value3" : 100
          }, {
            value4 :  {
              value5 : [100,200]
            }
          }];
      
      __LINE__ = 0;
      !function () {
        try {
          __LINE__ = 18;
          var d = c,
              e = d.value1,
              f = d.value2 && d.value2.value3?d.value2.value3 : undefined,
              g = d.value4 && d.value4[0]?d.value4[0] : undefined,
              h = d.value4 && d.value4[1]?d.value4[1] : undefined,
              i = d.value4 && d.value4[2]?d.value4[2] : undefined,
              j = d.value5 && d.value5.value6 && d.value5.value6[0] && d.value5.value6[0].value7?d.value5.value6[0].value7 : undefined,
              k = d["@value"] && d["@value"].strvalue?d["@value"].strvalue : undefined;
          
          __LINE__ = 19;
          a.assert( true,e === 100,"value1 === 100",19,'./destructuring_test.js' );
          
          __LINE__ = 20;
          a.assert( true,f === 100,"value3 === 100",20,'./destructuring_test.js' );
          
          __LINE__ = 21;
          a.assert( true,g === 100,"value5_ === 100",21,'./destructuring_test.js' );
          
          __LINE__ = 22;
          a.assert( true,h === 200,"value6_ === 200",22,'./destructuring_test.js' );
          
          __LINE__ = 23;
          a.assert( true,i === 300,"value7_ === 300",23,'./destructuring_test.js' );
          
          __LINE__ = 24;
          a.assert( true,j === 100,"value7 === 100",24,'./destructuring_test.js' );
          
          __LINE__ = 25;
          a.assert( true,k === 100,"strvalue === 100",25,'./destructuring_test.js' );
          
          __LINE__ = 0;
          var l;
          
          __LINE__ = 0;
          l = c;
          
          __LINE__ = 0;
          value1 = l.value1;
          
          __LINE__ = 0;
          value3 = l.value2 && l.value2.value3?l.value2.value3 : undefined;
          
          __LINE__ = 0;
          g = l.value4 && l.value4[0]?l.value4[0] : undefined;
          
          __LINE__ = 0;
          h = l.value4 && l.value4[1]?l.value4[1] : undefined;
          
          __LINE__ = 0;
          i = l.value4 && l.value4[2]?l.value4[2] : undefined;
          
          __LINE__ = 0;
          value7 = l.value5 && l.value5.value6 && l.value5.value6[0] && l.value5.value6[0].value7?l.value5.value6[0].value7 : undefined;
          
          __LINE__ = 0;
          strvalue = l["@value"] && l["@value"].strvalue?l["@value"].strvalue : undefined;
          
          __LINE__ = 28;
          a.assert( true,e === 100,"value1 === 100",28,'./destructuring_test.js' );
          
          __LINE__ = 29;
          a.assert( true,f === 100,"value3 === 100",29,'./destructuring_test.js' );
          
          __LINE__ = 30;
          a.assert( true,g === 100,"value5_ === 100",30,'./destructuring_test.js' );
          
          __LINE__ = 31;
          a.assert( true,h === 200,"value6_ === 200",31,'./destructuring_test.js' );
          
          __LINE__ = 32;
          a.assert( true,i === 300,"value7_ === 300",32,'./destructuring_test.js' );
          
          __LINE__ = 33;
          a.assert( true,j === 100,"value7 === 100",33,'./destructuring_test.js' );
          
          __LINE__ = 34;
          a.assert( true,k === 100,"strvalue === 100",34,'./destructuring_test.js' );
        } catch( e ){
          a.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }();
      
      __LINE__ = 0;
      !function () {
        try {
          __LINE__ = 39;
          var e = d,
              f = e[0] && e[0].value1?e[0].value1 : undefined,
              g = e[1],
              h = e[2] && e[2].value2?e[2].value2 : undefined,
              i = e[3] && e[3]["value3"]?e[3]["value3"] : undefined,
              j = e[4] && e[4].value4 && e[4].value4.value5 && e[4].value4.value5[0]?e[4].value4.value5[0] : undefined,
              k = e[4] && e[4].value4 && e[4].value4.value5 && e[4].value4.value5[1]?e[4].value4.value5[1] : undefined;
          
          __LINE__ = 40;
          a.assert( true,f === 100,"value1 === 100",40,'./destructuring_test.js' );
          
          __LINE__ = 41;
          a.assert( true,g === 200,"arr_value1 === 200",41,'./destructuring_test.js' );
          
          __LINE__ = 42;
          a.assert( true,h === 100,"value2 === 100",42,'./destructuring_test.js' );
          
          __LINE__ = 43;
          a.assert( true,i === 100,"value3 === 100",43,'./destructuring_test.js' );
          
          __LINE__ = 44;
          a.assert( true,j === 100,"arr_value2 === 100",44,'./destructuring_test.js' );
          
          __LINE__ = 45;
          a.assert( true,k === 200,"arr_value3 === 200",45,'./destructuring_test.js' );
          
          __LINE__ = 0;
          var l;
          
          __LINE__ = 0;
          l = d;
          
          __LINE__ = 0;
          value1 = l[0] && l[0].value1?l[0].value1 : undefined;
          
          __LINE__ = 0;
          g = l[1];
          
          __LINE__ = 0;
          value2 = l[2] && l[2].value2?l[2].value2 : undefined;
          
          __LINE__ = 0;
          value3 = l[3] && l[3]["value3"]?l[3]["value3"] : undefined;
          
          __LINE__ = 0;
          j = l[4] && l[4].value4 && l[4].value4.value5 && l[4].value4.value5[0]?l[4].value4.value5[0] : undefined;
          
          __LINE__ = 0;
          k = l[4] && l[4].value4 && l[4].value4.value5 && l[4].value4.value5[1]?l[4].value4.value5[1] : undefined;
          
          __LINE__ = 47;
          a.assert( true,f === 100,"value1 === 100",47,'./destructuring_test.js' );
          
          __LINE__ = 48;
          a.assert( true,g === 200,"arr_value1 === 200",48,'./destructuring_test.js' );
          
          __LINE__ = 49;
          a.assert( true,h === 100,"value2 === 100",49,'./destructuring_test.js' );
          
          __LINE__ = 50;
          a.assert( true,i === 100,"value3 === 100",50,'./destructuring_test.js' );
          
          __LINE__ = 51;
          a.assert( true,j === 100,"arr_value2 === 100",51,'./destructuring_test.js' );
          
          __LINE__ = 52;
          a.assert( true,k === 200,"arr_value3 === 200",52,'./destructuring_test.js' );
        } catch( e ){
          a.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }();
      
      __LINE__ = 0;
      !function () {
        try {
          __LINE__ = 56;
          var b = d,
              c = b[0] && b[0].value1?b[0].value1 : undefined,
              e = b[1],
              f = b[2] && b[2].value2?b[2].value2 : undefined,
              g = b[3] && b[3]["value3"]?b[3]["value3"] : undefined,
              h = b[4] && b[4].value4 && b[4].value4.value5?a.toArray( b[4].value4.value5,0 ) : undefined;
          
          __LINE__ = 57;
          a.assert( true,c === 100,"value1 === 100",57,'./destructuring_test.js' );
          
          __LINE__ = 58;
          a.assert( true,e === 200,"arr_value1 === 200",58,'./destructuring_test.js' );
          
          __LINE__ = 59;
          a.assert( true,f === 100,"value2 === 100",59,'./destructuring_test.js' );
          
          __LINE__ = 60;
          a.assert( true,g === 100,"value3 === 100",60,'./destructuring_test.js' );
          
          __LINE__ = 61;
          a.assert( true,h[0] === 100,"arr_value2[0] === 100",61,'./destructuring_test.js' );
          
          __LINE__ = 62;
          a.assert( true,h[1] === 200,"arr_value2[1] === 200",62,'./destructuring_test.js' );
          
          __LINE__ = 63;
          var i,
              j;
          
          __LINE__ = 0;
          j = d;
          
          __LINE__ = 0;
          value1 = j[0] && j[0].value1?j[0].value1 : undefined;
          
          __LINE__ = 0;
          e = j[1];
          
          __LINE__ = 0;
          value2 = j[2] && j[2].value2?j[2].value2 : undefined;
          
          __LINE__ = 0;
          value3 = j[3] && j[3]["value3"]?j[3]["value3"] : undefined;
          
          __LINE__ = 0;
          i = j[4] && j[4].value4 && j[4].value4.value5?a.toArray( j[4].value4.value5,0 ) : undefined;
          
          __LINE__ = 65;
          a.assert( true,c === 100,"value1 === 100",65,'./destructuring_test.js' );
          
          __LINE__ = 66;
          a.assert( true,e === 200,"arr_value1 === 200",66,'./destructuring_test.js' );
          
          __LINE__ = 67;
          a.assert( true,f === 100,"value2 === 100",67,'./destructuring_test.js' );
          
          __LINE__ = 68;
          a.assert( true,g === 100,"value3 === 100",68,'./destructuring_test.js' );
          
          __LINE__ = 69;
          a.assert( true,i[0] === 100,"arr_value4[0] === 100",69,'./destructuring_test.js' );
          
          __LINE__ = 70;
          a.assert( true,i[1] === 200,"arr_value4[1] === 200",70,'./destructuring_test.js' );
        } catch( e ){
          a.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }();
      
      __LINE__ = 0;
      !function ( b ) {
        try {
          __LINE__ = 0;
          var c = b.value1,
              d = b.value2 && b.value2.value3?b.value2.value3 : undefined,
              e = b.value4 && b.value4[0]?b.value4[0] : undefined,
              f = b.value4 && b.value4[1]?b.value4[1] : undefined,
              g = b.value4 && b.value4[2]?b.value4[2] : undefined,
              h = b.value5 && b.value5.value6 && b.value5.value6[0] && b.value5.value6[0].value7?b.value5.value6[0].value7 : undefined,
              i = b["@value"] && b["@value"].strvalue?b["@value"].strvalue : undefined;
          
          __LINE__ = 74;
          a.assert( true,c === 100,"value1 === 100",74,'./destructuring_test.js' );
          
          __LINE__ = 75;
          a.assert( true,d === 100,"value3 === 100",75,'./destructuring_test.js' );
          
          __LINE__ = 76;
          a.assert( true,e === 100,"value5_ === 100",76,'./destructuring_test.js' );
          
          __LINE__ = 77;
          a.assert( true,f === 200,"value6_ === 200",77,'./destructuring_test.js' );
          
          __LINE__ = 78;
          a.assert( true,g === 300,"value7_ === 300",78,'./destructuring_test.js' );
          
          __LINE__ = 79;
          a.assert( true,h === 100,"value7 === 100",79,'./destructuring_test.js' );
          
          __LINE__ = 80;
          a.assert( true,i === 100,"strvalue === 100",80,'./destructuring_test.js' );
        } catch( e ){
          a.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }( c );
      
      __LINE__ = 0;
      !function ( b ) {
        try {
          __LINE__ = 0;
          var c = b[0] && b[0].value1?b[0].value1 : undefined,
              d = b[1],
              e = b[2] && b[2].value2?b[2].value2 : undefined,
              f = b[3] && b[3]["value3"]?b[3]["value3"] : undefined,
              g = b[4] && b[4].value4 && b[4].value4.value5 && b[4].value4.value5[0]?b[4].value4.value5[0] : undefined,
              h = b[4] && b[4].value4 && b[4].value4.value5 && b[4].value4.value5[1]?b[4].value4.value5[1] : undefined;
          
          __LINE__ = 85;
          a.assert( true,c === 100,"value1 === 100",85,'./destructuring_test.js' );
          
          __LINE__ = 86;
          a.assert( true,d === 200,"arr_value1 === 200",86,'./destructuring_test.js' );
          
          __LINE__ = 87;
          a.assert( true,e === 100,"value2 === 100",87,'./destructuring_test.js' );
          
          __LINE__ = 88;
          a.assert( true,f === 100,"value3 === 100",88,'./destructuring_test.js' );
          
          __LINE__ = 89;
          a.assert( true,g === 100,"arr_value2 === 100",89,'./destructuring_test.js' );
          
          __LINE__ = 90;
          a.assert( true,h === 200,"arr_value3 === 200",90,'./destructuring_test.js' );
        } catch( e ){
          a.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }( d );
      
      __LINE__ = 0;
      !function ( b ) {
        try {
          __LINE__ = 0;
          var c = b[0] && b[0].value1?b[0].value1 : undefined,
              d = b[1],
              e = b[2] && b[2].value2?b[2].value2 : undefined,
              f = b[3] && b[3]["value3"]?b[3]["value3"] : undefined,
              g = b[4] && b[4].value4 && b[4].value4.value5?a.toArray( b[4].value4.value5,0 ) : undefined;
          
          __LINE__ = 95;
          a.assert( true,c === 100,"value1 === 100",95,'./destructuring_test.js' );
          
          __LINE__ = 96;
          a.assert( true,d === 200,"arr_value1 === 200",96,'./destructuring_test.js' );
          
          __LINE__ = 97;
          a.assert( true,e === 100,"value2 === 100",97,'./destructuring_test.js' );
          
          __LINE__ = 98;
          a.assert( true,f === 100,"value3 === 100",98,'./destructuring_test.js' );
          
          __LINE__ = 99;
          a.assert( true,g[0] === 100,"arr_value2[0] === 100",99,'./destructuring_test.js' );
          
          __LINE__ = 100;
          a.assert( true,g[1] === 200,"arr_value2[1] === 200",100,'./destructuring_test.js' );
        } catch( e ){
          a.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }( d );
      
      __LINE__ = 104;
      var f = function () {
            try {
              __LINE__ = 104;
              return [0,1,2];
            } catch( e ){
              a.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          },
          g = f(),
          h = g[0],
          i = g[2];
    } catch( e ){
      a.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  }();
}();
