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
      var __FILE__ = "/Users/aono_taketoshi/github/mocha/src/test/js/262/expression_test.js",
          __LINE__ = 0;
      __LINE__ = 2;
      b['./expression_test.js'] = {};
      
      __LINE__ = 3;
      var c = b['./expression_test.js'];
      
      __LINE__ = 0;
      /aaaa/.test( "aaaa" );
      
      function d() {
        try {
          __LINE__ = 3;
          var b = 2.000000;
          
          __LINE__ = 4;
          a.assert( true,b === 2,"x === 2",4,'./expression_test.js' );
          
          __LINE__ = 0;
          b = function () {
            try {
              __LINE__ = 7;
              return 2.000000;
            } catch( e ){
              a.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 9;
          a.assert( true,b() === 2,"x() === 2",9,'./expression_test.js' );
          
          __LINE__ = 0;
          b = function () {
            try {
              __LINE__ = 12;
              return /aaa/;
            } catch( e ){
              a.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 14;
          a.assert( true,Object.prototype.toString.call( b() ) === "[object RegExp]","Object.prototype.toString.call( x() ) === \"[object RegExp]\"",14,'./expression_test.js' );
          
          __LINE__ = 15;
          a.assert( true,/aaa/.test( "aaa" ) === true,"/aaa/.test( \"aaa\" ) === true",15,'./expression_test.js' );
          
          __LINE__ = 16;
          a.assert( true,.200*10 === 2,".200*10 === 2",16,'./expression_test.js' );
        } catch( e ){
          a.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }
      function e() {
        try {
          __LINE__ = 19;
          var d = {};
          
          __LINE__ = 0;
          d.testProp = {};
          
          __LINE__ = 0;
          d.testProp.testProp = {};
          
          __LINE__ = 0;
          d.testProp.testProp.testProp = {};
          
          __LINE__ = 0;
          d.testFn = function () {
            try {
              __LINE__ = 23;
              return true;
            } catch( e ){
              a.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          d.testProp.testFn = function () {
            try {
              __LINE__ = 24;
              return false;
            } catch( e ){
              a.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          d.testProp.testProp.testFn = function () {
            try {
              __LINE__ = 25;
              return 2;
            } catch( e ){
              a.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 27;
          a.assert( true,d.testFn() === true,"testObject.testFn() === true",27,'./expression_test.js' );
          
          __LINE__ = 28;
          a.assert( true,d.testProp.testFn() === false,"testObject.testProp.testFn() === false",28,'./expression_test.js' );
          
          __LINE__ = 29;
          a.assert( true,d.testProp.testProp.testFn() === 2,"testObject.testProp.testProp.testFn() === 2",29,'./expression_test.js' );
          
          __LINE__ = 31;
          var e = function () {
                try {
                  __LINE__ = 31;
                  return b;
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              },
              b = function () {
                try {
                  __LINE__ = 32;
                  return c;
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              },
              c = function (){},
              f = new e(),
              g = new new e(),
              h = new new new e();
          
          __LINE__ = 37;
          a.assert( true,f === b,"instance === inner1",37,'./expression_test.js' );
          
          __LINE__ = 38;
          a.assert( true,g === c,"instance2 === inner2",38,'./expression_test.js' );
          
          __LINE__ = 39;
          a.assert( true,h instanceof c,"instance3 instanceof inner2",39,'./expression_test.js' );
          
          __LINE__ = 41;
          var i =  {
                highFn : e,
                highFnInner :  {
                  highFn : e
                }
              },
              j = new i.highFn(),
              k = new new i.highFn(),
              l = new new new i.highFn();
          
          __LINE__ = 51;
          a.assert( true,j === b,"instance4 === inner1",51,'./expression_test.js' );
          
          __LINE__ = 52;
          a.assert( true,k === c,"instance5 === inner2",52,'./expression_test.js' );
          
          __LINE__ = 53;
          a.assert( true,l instanceof c,"instance6 instanceof inner2",53,'./expression_test.js' );
          
          __LINE__ = 54;
          var m = new i.highFnInner.highFn(),
              n = new new i.highFnInner.highFn(),
              o = new new new i.highFnInner.highFn();
          
          __LINE__ = 57;
          a.assert( true,m === b,"instance7 === inner1",57,'./expression_test.js' );
          
          __LINE__ = 58;
          a.assert( true,n === c,"instance8 === inner2",58,'./expression_test.js' );
          
          __LINE__ = 59;
          a.assert( true,o instanceof c,"instance9 instanceof inner2",59,'./expression_test.js' );
        } catch( e ){
          a.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }
      function f() {
        try {
          __LINE__ = 63;
          var d = function () {
                try {
                  __LINE__ = 64;
                  return function () {
                    try {
                      __LINE__ = 65;
                      return function () {
                        try {
                          __LINE__ = 66;
                          return true;
                        } catch( e ){
                          a.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      };
                    } catch( e ){
                      a.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  };
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
          
          __LINE__ = 70;
          a.assert( true,d()()() === true,"highFn()()() === true",70,'./expression_test.js' );
          
          __LINE__ = 0;
          d = function () {
            try {
              __LINE__ = 71;
              return b;
            } catch( e ){
              a.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 72;
          var b = function () {
                try {
                  __LINE__ = 72;
                  return c;
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              },
              c = function (){},
              e = 1,
              f = new ( e?d : b );
          
          __LINE__ = 76;
          a.assert( true,f === b,"instance === inner1",76,'./expression_test.js' );
          
          __LINE__ = 77;
          var g = 0;
          
          __LINE__ = 0;
          f = new ( g?d : b );
          
          __LINE__ = 79;
          a.assert( true,f === c,"instance === inner2",79,'./expression_test.js' );
        } catch( e ){
          a.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }
      function g() {
        try {
          __LINE__ = 83;
          var c = 100,
              d = true,
              e = false,
              b = 0;
          
          __LINE__ = 87;
          if ( c && d && !e ){
            __LINE__ = 0;
            b = 1;
          };
          
          __LINE__ = 90;
          a.assert( true,b === 1,"val === 1",90,'./expression_test.js' );
          
          __LINE__ = 91;
          if ( ( c && d ) || e ){
            __LINE__ = 0;
            b = 2;
          };
          
          __LINE__ = 94;
          a.assert( true,b === 2,"val === 2",94,'./expression_test.js' );
          
          __LINE__ = 95;
          if ( ( c && e ) || !d ){
            __LINE__ = 0;
            b = 3;
          };
          
          __LINE__ = 98;
          a.assert( false,b === 3,"val === 3",98,'./expression_test.js' );
          
          __LINE__ = 100;
          var f = function ( c ) {
                try {
                  __LINE__ = 0;
                  b = c;
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
          
          __LINE__ = 0;
          c && d && ( !e ) && ( f( 4 ) );
          
          __LINE__ = 105;
          a.assert( true,b === 4,"val === 4",105,'./expression_test.js' );
          
          __LINE__ = 107;
          var g = 0,
              h = 0;
          
          __LINE__ = 109;
          if ( g == 0 ){
            __LINE__ = 0;
            h = 1;
          };
          
          __LINE__ = 112;
          a.assert( true,h === 1,"eqVal === 1",112,'./expression_test.js' );
          
          __LINE__ = 114;
          if ( g === 0 ){
            __LINE__ = 0;
            h = 2;
          };
          
          __LINE__ = 117;
          a.assert( true,h === 2,"eqVal === 2",117,'./expression_test.js' );
          
          __LINE__ = 119;
          var i = 1,
              j = 0;
          
          __LINE__ = 0;
          j = i << 1;
          
          __LINE__ = 122;
          a.assert( true,j === 2,"ret === 2",122,'./expression_test.js' );
          
          __LINE__ = 0;
          j = i >> 1;
          
          __LINE__ = 124;
          a.assert( true,j === 0,"ret === 0",124,'./expression_test.js' );
          
          __LINE__ = 0;
          j = i|2;
          
          __LINE__ = 126;
          a.assert( true,j === 3,"ret === 3",126,'./expression_test.js' );
          
          __LINE__ = 0;
          i = 1;
          
          __LINE__ = 0;
          i <<= 1;
          
          __LINE__ = 130;
          a.assert( true,i === 2,"bit === 2",130,'./expression_test.js' );
          
          __LINE__ = 0;
          i = 1;
          
          __LINE__ = 0;
          i >>= 1;
          
          __LINE__ = 133;
          a.assert( true,i === 0,"bit === 0",133,'./expression_test.js' );
          
          __LINE__ = 0;
          i = 1;
          
          __LINE__ = 0;
          i |= 2;
          
          __LINE__ = 136;
          a.assert( true,i === 3,"bit === 3",136,'./expression_test.js' );
          
          __LINE__ = 0;
          i = 10;
          
          __LINE__ = 0;
          j = i >>> 2;
          
          __LINE__ = 140;
          a.assert( true,j === 2,"ret === 2",140,'./expression_test.js' );
          
          __LINE__ = 0;
          i = 10;
          
          __LINE__ = 0;
          i >>>= 2;
          
          __LINE__ = 143;
          a.assert( true,i === 2,"bit === 2",143,'./expression_test.js' );
          
          __LINE__ = 0;
          i = 3;
          
          __LINE__ = 0;
          j = i&1;
          
          __LINE__ = 147;
          a.assert( true,j === 1,"ret === 1",147,'./expression_test.js' );
          
          __LINE__ = 0;
          i &= 1;
          
          __LINE__ = 149;
          a.assert( true,i === 1,"bit === 1",149,'./expression_test.js' );
          
          __LINE__ = 0;
          i = 2;
          
          __LINE__ = 0;
          j = i^1;
          
          __LINE__ = 153;
          a.assert( true,j === 3,"ret === 3",153,'./expression_test.js' );
          
          __LINE__ = 0;
          i = 2;
          
          __LINE__ = 0;
          i ^= 1;
          
          __LINE__ = 156;
          a.assert( true,i === 3,"bit === 3",156,'./expression_test.js' );
          
          __LINE__ = 158;
          var k = 0,
              l = 1,
              m = 0;
          
          __LINE__ = 162;
          if ( k>l ){
            __LINE__ = 0;
            m = 1;
          };
          
          __LINE__ = 165;
          a.assert( true,m === 0,"cmpVal === 0",165,'./expression_test.js' );
          
          __LINE__ = 0;
          m = 0;
          
          __LINE__ = 168;
          if ( k<l ){
            __LINE__ = 0;
            m = 1;
          };
          
          __LINE__ = 171;
          a.assert( true,m === 1,"cmpVal === 1",171,'./expression_test.js' );
          
          __LINE__ = 0;
          m = 0;
          
          __LINE__ = 174;
          if ( k <= l ){
            __LINE__ = 0;
            m = 1;
          };
          
          __LINE__ = 177;
          a.assert( true,m === 1,"cmpVal === 1",177,'./expression_test.js' );
          
          __LINE__ = 0;
          m = 0;
          
          __LINE__ = 180;
          if ( k >= l ){
            __LINE__ = 0;
            m = 1;
          };
          
          __LINE__ = 183;
          a.assert( false,m === 1,"cmpVal === 1",183,'./expression_test.js' );
          
          __LINE__ = 0;
          m = 0;
          
          __LINE__ = 0;
          k = 1;
          
          __LINE__ = 187;
          if ( k <= l ){
            __LINE__ = 0;
            m = 1;
          };
          
          __LINE__ = 190;
          a.assert( true,m === 1,"cmpVal === 1",190,'./expression_test.js' );
          
          __LINE__ = 0;
          m = 1;
          
          __LINE__ = 193;
          if ( k >= l ){
            __LINE__ = 0;
            m = 1;
          };
          
          __LINE__ = 196;
          a.assert( true,m === 1,"cmpVal === 1",196,'./expression_test.js' );
          
          __LINE__ = 198;
          var n = 0;
          
          __LINE__ = 0;
          j = n+1;
          
          __LINE__ = 200;
          a.assert( true,j === 1,"ret === 1",200,'./expression_test.js' );
          
          __LINE__ = 202;
          var o = 1;
          
          __LINE__ = 0;
          j = o-1;
          
          __LINE__ = 204;
          a.assert( true,j === 0,"ret === 0",204,'./expression_test.js' );
          
          __LINE__ = 206;
          var p = 1;
          
          __LINE__ = 0;
          j = p*2;
          
          __LINE__ = 208;
          a.assert( true,j === 2,"ret === 2",208,'./expression_test.js' );
          
          __LINE__ = 210;
          var q = 2;
          
          __LINE__ = 0;
          j = q/2;
          
          __LINE__ = 212;
          a.assert( true,j === 1,"ret === 1",212,'./expression_test.js' );
          
          __LINE__ = 214;
          var r = 3;
          
          __LINE__ = 0;
          j = r%2;
          
          __LINE__ = 216;
          a.assert( true,j === 1,"ret === 1",216,'./expression_test.js' );
          
          __LINE__ = 0;
          n = 0;
          
          __LINE__ = 0;
          n += 1;
          
          __LINE__ = 220;
          a.assert( true,n === 1,"pl === 1",220,'./expression_test.js' );
          
          __LINE__ = 0;
          o = 1;
          
          __LINE__ = 0;
          o -= 1;
          
          __LINE__ = 224;
          a.assert( true,o === 0,"mi === 0",224,'./expression_test.js' );
          
          __LINE__ = 0;
          p = 1;
          
          __LINE__ = 0;
          p *= 2;
          
          __LINE__ = 228;
          a.assert( true,p === 2,"mul === 2",228,'./expression_test.js' );
          
          __LINE__ = 0;
          q = 2;
          
          __LINE__ = 0;
          q /= 2;
          
          __LINE__ = 232;
          a.assert( true,q === 1,"div === 1",232,'./expression_test.js' );
          
          __LINE__ = 0;
          r = 3;
          
          __LINE__ = 0;
          r %= 2;
          
          __LINE__ = 236;
          a.assert( true,r === 1,"mod === 1",236,'./expression_test.js' );
          
          __LINE__ = 238;
          var s =  {
                'onmouseenter' : 1,
                'onmouseleave' : 1
              },
              t = 'onmouseenter' in s && 'onmouseleave' in s;
          
          __LINE__ = 245;
          a.assert( true,t === true,"testInAnd === true",245,'./expression_test.js' );
        } catch( e ){
          a.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }
      function h() {
        try {
          __LINE__ = 249;
          var b = 0;
          
          __LINE__ = 0;
          b ++ ;
          
          __LINE__ = 251;
          a.assert( true,b === 1,"add === 1",251,'./expression_test.js' );
          
          __LINE__ = 253;
          var c = 1;
          
          __LINE__ = 0;
          c -- ;
          
          __LINE__ = 255;
          a.assert( true,c === 0,"sub === 0",255,'./expression_test.js' );
          
          __LINE__ = 0;
          b = 0;
          
          __LINE__ = 0;
          c = b;
          
          __LINE__ = 0;
           ++ c;
          
          __LINE__ = 260;
          a.assert( true,c === 1,"sub === 1",260,'./expression_test.js' );
          
          __LINE__ = 0;
          b = 1;
          
          __LINE__ = 0;
          c = b;
          
          __LINE__ = 0;
           -- c;
          
          __LINE__ = 265;
          a.assert( true,c === 0,"sub === 0",265,'./expression_test.js' );
          
          __LINE__ = 0;
          c = 1;
          
          __LINE__ = 0;
          c -- ;
          
          __LINE__ = 0;
          b = c;
          
          __LINE__ = 270;
          a.assert( true,b === 0,"add === 0",270,'./expression_test.js' );
        } catch( e ){
          a.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }
      function i() {
        try {
          __LINE__ = 275;
          var b = "1",
              c = +b;
          
          __LINE__ = 277;
          a.assert( true,c === 1,"ret === 1",277,'./expression_test.js' );
          
          __LINE__ = 0;
          c = -b;
          
          __LINE__ = 280;
          a.assert( true,c === -1,"ret === -1",280,'./expression_test.js' );
          
          __LINE__ = 282;
          var d = -5;
          
          __LINE__ = 0;
          c = ~d;
          
          __LINE__ = 284;
          a.assert( true,c === 4,"ret === 4",284,'./expression_test.js' );
          
          __LINE__ = 286;
          var e = true;
          
          __LINE__ = 0;
          c = !e;
          
          __LINE__ = 288;
          a.assert( true,c === false,"ret === false",288,'./expression_test.js' );
          
          __LINE__ = 0;
          c = !!e;
          
          __LINE__ = 291;
          a.assert( true,c === true,"ret === true",291,'./expression_test.js' );
        } catch( e ){
          a.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }
      function j() {
        try {
          __LINE__ = 295;
          var b =  {
                test2 :  {
                  "@test" :  {
                    0 :  {
                      "1" : function () {
                        try {
                          __LINE__ = 300;
                          return function () {
                            try {
                              __LINE__ = 300;
                              return 1;
                            } catch( e ){
                              a.exceptionHandler( __LINE__ , __FILE__ , e );
                            }
                          };
                        } catch( e ){
                          a.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      }
                    }
                  }
                }
              };
          
          __LINE__ = 306;
          a.assert( true,b["test2"]["@test"]["0"]["1"]()() === 1,"test[\"test2\"][\"@test\"][\"0\"][\"1\"]()() === 1",306,'./expression_test.js' );
          
          __LINE__ = 307;
          a.assert( true,b.test2["@test"][0]["1"]()() === 1,"test.test2[\"@test\"][0][\"1\"]()() === 1",307,'./expression_test.js' );
        } catch( e ){
          a.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }
      function k() {
        try {
          __LINE__ = 311;
          var b = function () {
                try {
                  __LINE__ = 312;
                  return 1;
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }();
          
          __LINE__ = 314;
          a.assert( true,b === 1,"exp === 1",314,'./expression_test.js' );
          
          __LINE__ = 316;
          var c,
              d,
              e;
          
          __LINE__ = 0;
          b = ( c = 0 , d = 1 , e = 2 );
          
          __LINE__ = 318;
          a.assert( true,c === 0,"a === 0",318,'./expression_test.js' );
          
          __LINE__ = 319;
          a.assert( true,d === 1,"b === 1",319,'./expression_test.js' );
          
          __LINE__ = 320;
          a.assert( true,e === 2,"c === 2",320,'./expression_test.js' );
          
          __LINE__ = 321;
          a.assert( true,b === 2,"exp === 2",321,'./expression_test.js' );
          
          __LINE__ = 0;
          !function () {
            try {
              __LINE__ = 0;
              b = 10;
            } catch( e ){
              a.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }();
          
          __LINE__ = 327;
          a.assert( true,b === 10,"exp === 10",327,'./expression_test.js' );
          
          __LINE__ = 0;
          !function ( c,d ) {
            try {
              __LINE__ = 0;
              b = c+d;
            } catch( e ){
              a.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }( ( function () {
            try {
              __LINE__ = 331;
              return 100;
            } catch( e ){
              a.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })(),function () {
            try {
              __LINE__ = 331;
              return 200;
            } catch( e ){
              a.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }());
          
          __LINE__ = 333;
          a.assert( true,b === 300,"exp === 300",333,'./expression_test.js' );
          
          __LINE__ = 0;
          !function () {
            try {
              __LINE__ = 0;
              b = 1;
            } catch( e ){
              a.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }();
          
          __LINE__ = 338;
          a.assert( true,b === 1,"exp === 1",338,'./expression_test.js' );
        } catch( e ){
          a.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }
      function l() {
        try {
          __LINE__ = 342;
          var b = [,,,];
          
          __LINE__ = 343;
          a.assert( true,b.length === 3,"array.length === 3",343,'./expression_test.js' );
        } catch( e ){
          a.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }
      __LINE__ = 0;
      d();
      
      __LINE__ = 0;
      e();
      
      __LINE__ = 0;
      f();
      
      __LINE__ = 0;
      g();
      
      __LINE__ = 0;
      h();
      
      __LINE__ = 0;
      i();
      
      __LINE__ = 0;
      j();
      
      __LINE__ = 0;
      k();
      
      __LINE__ = 0;
      l();
    } catch( e ){
      a.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  }();
}();
