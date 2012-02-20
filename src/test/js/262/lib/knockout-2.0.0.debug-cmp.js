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
    b['./knockout-2.0.0.debug.js'] = {};
    
    var c = b['./knockout-2.0.0.debug.js'];
    
    !function ( a,undefined ) {
      var b = a["ko"] = {};
      
      b.exportSymbol = function ( b,c ) {
        var d = b.split( "." );
        
        var e = a;
        
        for ( var f = 0;f<d.length-1;f ++  )
        e = e[d[f]];
        
        e[d[d.length-1]] = c;
      };
      
      b.exportProperty = function ( a,b,c ) {
        a[b] = c;
      };
      
      b.utils = new function () {
        var c = /^(\s|\u00A0)+|(\s|\u00A0)+$/g;
        
        var g = {},
            e = {};
        
        var h = /Firefox\/2/i.test( navigator.userAgent )?'KeyboardEvent' : 'UIEvents';
        
        g[h] = ['keyup','keydown','keypress'];
        
        g['MouseEvents'] = ['click','dblclick','mousedown','mouseup','mousemove','mouseover','mouseout','mouseenter','mouseleave'];
        
        for ( var i in g ){
          var j = g[i];
          
          if ( j.length ){
            for ( var k = 0,l = j.length;k<l;k ++  )
            e[j[k]] = i;
          };
        };
        
        var f = ( function () {
              var a = 3,
                  b = document.createElement( 'div' ),
                  c = b.getElementsByTagName( 'i' );
              
              while ( b.innerHTML = '<!--[if gt IE '+(  ++ a )+']><i></i><![endif]-->' , c[0] )return a>4?a : undefined;
            }());
        
        var m = f === 6,
            n = f === 7;
        
        function d( a,b ) {
          if ( ( a.tagName != "INPUT" ) || !a.type ){
            return false;
          };
          
          if ( b.toLowerCase() != "click" ){
            return false;
          };
          
          var c = a.type.toLowerCase();
          return ( c == "checkbox" ) || ( c == "radio" );
        }return  {
          fieldsIncludedWithJsonPost : ['authenticity_token',/^__RequestVerificationToken(_.*)?$/],
          arrayForEach : function ( a,b ) {
            for ( var c = 0,d = a.length;c<d;c ++  )
            b( a[c] );
          },
          arrayIndexOf : function ( a,b ) {
            if ( typeof Array.prototype.indexOf == "function" ){
              return Array.prototype.indexOf.call( a,b );
            };
            
            for ( var c = 0,d = a.length;c<d;c ++  )
            if ( a[c] === b ){
              return c;
            };
            return -1;
          },
          arrayFirst : function ( a,b,c ) {
            for ( var d = 0,e = a.length;d<e;d ++  )
            if ( b.call( c,a[d] ) ){
              return a[d];
            };
            return null;
          },
          arrayRemoveItem : function ( a,c ) {
            var d = b.utils.arrayIndexOf( a,c );
            
            if ( d >= 0 ){
              a.splice( d,1 );
            };
          },
          arrayGetDistinctValues : function ( a ) {
            a = a || [];
            
            var c = [];
            
            for ( var d = 0,e = a.length;d<e;d ++  )
            if ( b.utils.arrayIndexOf( c,a[d] )<0 ){
              c.push( a[d] );
            };
            return c;
          },
          arrayMap : function ( a,b ) {
            a = a || [];
            
            var c = [];
            
            for ( var d = 0,e = a.length;d<e;d ++  )
            c.push( b( a[d] ) );
            return c;
          },
          arrayFilter : function ( a,b ) {
            a = a || [];
            
            var c = [];
            
            for ( var d = 0,e = a.length;d<e;d ++  )
            if ( b( a[d] ) ){
              c.push( a[d] );
            };
            return c;
          },
          arrayPushAll : function ( a,b ) {
            for ( var c = 0,d = b.length;c<d;c ++  )
            a.push( b[c] );
            return a;
          },
          extend : function ( a,b ) {
            for ( var c in b )
            if ( b.hasOwnProperty( c ) ){
              a[c] = b[c];
            };
            return a;
          },
          emptyDomNode : function ( a ) {
            while ( a.firstChild )b.removeNode( a.firstChild );
          },
          setDomNodeChildren : function ( a,c ) {
            b.utils.emptyDomNode( a );
            
            if ( c ){
              b.utils.arrayForEach( c,
              function ( b ) {
                a.appendChild( b );
              });
            };
          },
          replaceDomNodes : function ( a,c ) {
            var d = a.nodeType?[a] : a;
            
            if ( d.length>0 ){
              var e = d[0];
              
              var f = e.parentNode;
              
              for ( var g = 0,h = c.length;g<h;g ++  )
              f.insertBefore( c[g],e );
              
              for ( var g = 0,h = d.length;g<h;g ++  )
              b.removeNode( d[g] );
            };
          },
          setOptionNodeSelectionState : function ( a,b ) {
            if ( navigator.userAgent.indexOf( "MSIE 6" ) >= 0 ){
              a.setAttribute( "selected",b );
            } else {
              a.selected = b;
            };
          },
          stringTrim : function ( d ) {
            return ( d || "" ).replace( c,"" );
          },
          stringTokenize : function ( a,c ) {
            var d = [];
            
            var e = ( a || "" ).split( c );
            
            for ( var f = 0,g = e.length;f<g;f ++  ){
              var h = b.utils.stringTrim( e[f] );
              
              if ( h !== "" ){
                d.push( h );
              };
            };
            return d;
          },
          stringStartsWith : function ( a,b ) {
            a = a || "";
            
            if ( b.length>a.length ){
              return false;
            };
            return a.substring( 0,b.length ) === b;
          },
          evalWithinScope : function ( a ) {
            var b = Array.prototype.slice.call( arguments,1 );
            
            var c = "return ("+a+")";
            
            for ( var d = 0;d<b.length;d ++  )
            if ( b[d] && typeof b[d] == "object" ){
              c = "with(sc["+d+"]) { "+c+" } ";
            };
            return ( new Function( "sc",c ) )( b );
          },
          domNodeIsContainedBy : function ( a,b ) {
            if ( b.compareDocumentPosition ){
              return ( b.compareDocumentPosition( a )&16 ) == 16;
            };
            
            while ( a != null ){
              if ( a == b ){
                return true;
              };
              
              a = a.parentNode;
            };
            return false;
          },
          domNodeIsAttachedToDocument : function ( a ) {
            return b.utils.domNodeIsContainedBy( a,document );
          },
          registerEventHandler : function ( c,e,b ) {
            if ( typeof jQuery != "undefined" ){
              if ( d( c,e ) ){
                var a = b;
                
                b = function ( b,c ) {
                  var d = this.checked;
                  
                  if ( c ){
                    this.checked = c.checkedStateBeforeEvent !== true;
                  };
                  
                  a.call( this,b );
                  
                  this.checked = d;
                };
              };
              
              jQuery( c )['bind']( e,b );
            } else if ( typeof c.addEventListener == "function" ){
              c.addEventListener( e,b,false );
            } else if ( typeof c.attachEvent != "undefined" ){
              c.attachEvent( "on"+e,
              function ( d ) {
                b.call( c,d );
              });
            } else {
              throw new Error( "Browser doesn't support addEventListener or attachEvent" );
            };
          },
          triggerEvent : function ( f,g ) {
            if ( !( f && f.nodeType ) ){
              throw new Error( "element must be a DOM node when calling triggerEvent" );
            };
            
            if ( typeof jQuery != "undefined" ){
              var h = [];
              
              if ( d( f,g ) ){
                h.push(  {
                  checkedStateBeforeEvent : f.checked
                });
              };
              
              jQuery( f )['trigger']( g,h );
            } else if ( typeof document.createEvent == "function" ){
              if ( typeof f.dispatchEvent == "function" ){
                var i = e[g] || "HTMLEvents";
                
                var j = document.createEvent( i );
                
                j.initEvent( g,true,true,a,0,0,0,0,0,false,false,false,false,0,f );
                
                f.dispatchEvent( j );
              } else {
                throw new Error( "The supplied element doesn't support dispatchEvent" );
              };
            } else if ( typeof f.fireEvent != "undefined" ){
              if ( g == "click" ){
                if ( ( f.tagName == "INPUT" ) && ( ( f.type.toLowerCase() == "checkbox" ) || ( f.type.toLowerCase() == "radio" ) ) ){
                  f.checked = f.checked !== true;
                };
              };
              
              f.fireEvent( "on"+g );
            } else {
              throw new Error( "Browser doesn't support triggering events" );
            };
          },
          unwrapObservable : function ( a ) {
            return b.isObservable( a )?a() : a;
          },
          domNodeHasCssClass : function ( a,c ) {
            var d = ( a.className || "" ).split( /\s+/ );
            return b.utils.arrayIndexOf( d,c ) >= 0;
          },
          toggleDomNodeCssClass : function ( a,c,d ) {
            var e = b.utils.domNodeHasCssClass( a,c );
            
            if ( d && !e ){
              a.className = ( a.className || "" )+" "+c;
            } else if ( e && !d ){
              var f = ( a.className || "" ).split( /\s+/ );
              
              var g = "";
              
              for ( var h = 0;h<f.length;h ++  )if ( f[h] != c ){
                g += f[h]+" ";
              };
              
              a.className = b.utils.stringTrim( g );
            };
          },
          outerHTML : function ( g ) {
            if ( f === undefined ){
              var h = g.outerHTML;
              
              if ( typeof h == "string" ){
                return h;
              };
            };
            
            var i = a.document.createElement( "div" );
            
            i.appendChild( g.cloneNode( true ) );
            return i.innerHTML;
          },
          setTextContent : function ( a,c ) {
            var d = b.utils.unwrapObservable( c );
            
            if ( ( d === null ) || ( d === undefined ) ){
              d = "";
            };
            
            'innerText' in a?a.innerText = d : a.textContent = d;
            
            if ( f >= 9 ){
              a.innerHTML = a.innerHTML;
            };
          },
          range : function ( a,c ) {
            a = b.utils.unwrapObservable( a );
            
            c = b.utils.unwrapObservable( c );
            
            var d = [];
            
            for ( var e = a;e <= c;e ++  )
            d.push( e );
            return d;
          },
          makeArray : function ( a ) {
            var b = [];
            
            for ( var c = 0,d = a.length;c<d;c ++  )
            b.push( a[c] );
            return b;
          },
          isIe6 : m,
          isIe7 : n,
          getFormFields : function ( c,a ) {
            var d = b.utils.makeArray( c.getElementsByTagName( "INPUT" ) ).concat( b.utils.makeArray( c.getElementsByTagName( "TEXTAREA" ) ) );
            
            var e = ( typeof a == 'string' )?function ( b ) {
                  return b.name === a;
                } : function ( b ) {
                  return a.test( b.name );
                };
            
            var f = [];
            
            for ( var g = d.length-1;g >= 0;g --  )
            if ( e( d[g] ) ){
              f.push( d[g] );
            };
            return f;
          },
          parseJson : function ( c ) {
            if ( typeof c == "string" ){
              c = b.utils.stringTrim( c );
              
              if ( c ){
                if ( a.JSON && a.JSON.parse ){
                  return a.JSON.parse( c );
                };
                return ( new Function( "return "+c ) )();
              };
            };
            return null;
          },
          stringifyJson : function ( a ) {
            if ( ( typeof JSON == "undefined" ) || ( typeof JSON.stringify == "undefined" ) ){
              throw new Error( "Cannot find JSON.stringify(). Some browsers (e.g., IE < 8) don't support it natively, but you can overcome this by adding a script reference to json2.js, downloadable from http://www.json.org/json2.js" );
            };
            return JSON.stringify( b.utils.unwrapObservable( a ) );
          },
          postJson : function ( c,d,e ) {
            e = e || {};
            
            var f = e['params'] || {};
            
            var g = e['includeFields'] || this.fieldsIncludedWithJsonPost;
            
            var h = c;
            
            if ( ( typeof c == 'object' ) && ( c.tagName == "FORM" ) ){
              var i = c;
              
              h = i.action;
              
              for ( var j = g.length-1;j >= 0;j --  ){
                var k = b.utils.getFormFields( i,g[j] );
                
                for ( var l = k.length-1;l >= 0;l --  )
                f[k[l].name] = k[l].value;
              };
            };
            
            d = b.utils.unwrapObservable( d );
            
            var a = document.createElement( "FORM" );
            
            a.style.display = "none";
            
            a.action = h;
            
            a.method = "post";
            
            for ( var m in d ){
              var n = document.createElement( "INPUT" );
              
              n.name = m;
              
              n.value = b.utils.stringifyJson( b.utils.unwrapObservable( d[m] ) );
              
              a.appendChild( n );
            };
            
            for ( var m in f ){
              var n = document.createElement( "INPUT" );
              
              n.name = m;
              
              n.value = f[m];
              
              a.appendChild( n );
            };
            
            document.body.appendChild( a );
            
            e['submitter']?e['submitter']( a ) : a.submit();
            
            setTimeout( function () {
              a.parentNode.removeChild( a );
            },0);
          }
        };
      }();
      
      b.exportSymbol( 'ko.utils',b.utils );
      
      b.utils.arrayForEach( [['arrayForEach',b.utils.arrayForEach],['arrayFirst',b.utils.arrayFirst],['arrayFilter',b.utils.arrayFilter],['arrayGetDistinctValues',b.utils.arrayGetDistinctValues],['arrayIndexOf',b.utils.arrayIndexOf],['arrayMap',b.utils.arrayMap],['arrayPushAll',b.utils.arrayPushAll],['arrayRemoveItem',b.utils.arrayRemoveItem],['extend',b.utils.extend],['fieldsIncludedWithJsonPost',b.utils.fieldsIncludedWithJsonPost],['getFormFields',b.utils.getFormFields],['postJson',b.utils.postJson],['parseJson',b.utils.parseJson],['registerEventHandler',b.utils.registerEventHandler],['stringifyJson',b.utils.stringifyJson],['range',b.utils.range],['toggleDomNodeCssClass',b.utils.toggleDomNodeCssClass],['triggerEvent',b.utils.triggerEvent],['unwrapObservable',b.utils.unwrapObservable]],
      function ( a ) {
        b.exportSymbol( 'ko.utils.'+a[0],a[1] );
      });
      
      if ( !Function.prototype['bind'] ){
        Function.prototype['bind'] = function ( b ) {
          var a = this,
              c = Array.prototype.slice.call( arguments ),
              b = c.shift();
          return function () {
            return a.apply( b,c.concat( Array.prototype.slice.call( arguments ) ) );
          };
        };
      };
      
      b.utils.domData = new function () {
        var c = 0;
        
        var a = "__ko__"+( new Date ).getTime();
        
        var d = {};
        return  {
          get : function ( a,c ) {
            var d = b.utils.domData.getAll( a,false );
            return d === undefined?undefined : d[c];
          },
          set : function ( a,c,d ) {
            if ( d === undefined ){
              if ( b.utils.domData.getAll( a,false ) === undefined ){
                return ;
              };
            };
            
            var e = b.utils.domData.getAll( a,true );
            
            e[c] = d;
          },
          getAll : function ( e,f ) {
            var g = e[a];
            
            var h = g && ( g !== "null" );
            
            if ( !h ){
              if ( !f ){
                return undefined;
              };
              
              g = e[a] = "ko"+c ++ ;
              
              d[g] = {};
            };
            return d[g];
          },
          clear : function ( b ) {
            var c = b[a];
            
            if ( c ){
              delete d[c];
              
              b[a] = null;
            };
          }
        };
      }();
      
      b.exportSymbol( 'ko.utils.domData',b.utils.domData );
      
      b.exportSymbol( 'ko.utils.domData.clear',b.utils.domData.clear );
      
      b.utils.domNodeDisposal = new function () {
        var a = "__ko_domNodeDisposal__"+( new Date ).getTime();
        
        function c( c,d ) {
          var e = b.utils.domData.get( c,a );
          
          if ( ( e === undefined ) && d ){
            e = [];
            
            b.utils.domData.set( c,a,e );
          };
          return e;
        }
        function d( c ) {
          b.utils.domData.set( c,a,undefined );
        }
        function e( d ) {
          var e = c( d,false );
          
          if ( e ){
            e = e.slice( 0 );
            
            for ( var f = 0;f<e.length;f ++  )
            e[f]( d );
          };
          
          b.utils.domData.clear( d );
          
          if ( ( typeof jQuery == "function" ) && ( typeof jQuery['cleanData'] == "function" ) ){
            jQuery['cleanData']( [d] );
          };
        }return  {
          addDisposeCallback : function ( a,b ) {
            if ( typeof b != "function" ){
              throw new Error( "Callback must be a function" );
            };
            
            c( a,true ).push( b );
          },
          removeDisposeCallback : function ( e,f ) {
            var g = c( e,false );
            
            if ( g ){
              b.utils.arrayRemoveItem( g,f );
              
              if ( g.length == 0 ){
                d( e );
              };
            };
          },
          cleanNode : function ( f ) {
            if ( ( f.nodeType != 1 ) && ( f.nodeType != 9 ) ){
              return ;
            };
            
            e( f );
            
            var g = [];
            
            b.utils.arrayPushAll( g,f.getElementsByTagName( "*" ) );
            
            for ( var h = 0,i = g.length;h<i;h ++  )
            e( g[h] );
          },
          removeNode : function ( a ) {
            b.cleanNode( a );
            
            if ( a.parentNode ){
              a.parentNode.removeChild( a );
            };
          }
        };
      }();
      
      b.cleanNode = b.utils.domNodeDisposal.cleanNode;
      
      b.removeNode = b.utils.domNodeDisposal.removeNode;
      
      b.exportSymbol( 'ko.cleanNode',b.cleanNode );
      
      b.exportSymbol( 'ko.removeNode',b.removeNode );
      
      b.exportSymbol( 'ko.utils.domNodeDisposal',b.utils.domNodeDisposal );
      
      b.exportSymbol( 'ko.utils.domNodeDisposal.addDisposeCallback',b.utils.domNodeDisposal.addDisposeCallback );
      
      b.exportSymbol( 'ko.utils.domNodeDisposal.removeDisposeCallback',b.utils.domNodeDisposal.removeDisposeCallback );
      
      !function () {
        var e = /^(\s*)<!--(.*?)-->/;
        
        function d( c ) {
          var d = b.utils.stringTrim( c ).toLowerCase(),
              e = document.createElement( "div" );
          
          var f = d.match( /^<(thead|tbody|tfoot)/ ) && [1,"<table>","</table>"] || !d.indexOf( "<tr" ) && [2,"<table><tbody>","</tbody></table>"] || ( !d.indexOf( "<td" ) || !d.indexOf( "<th" ) ) && [3,"<table><tbody><tr>","</tr></tbody></table>"] || [0,"",""];
          
          var g = "ignored<div>"+f[1]+c+f[2]+"</div>";
          
          if ( typeof a['innerShiv'] == "function" ){
            e.appendChild( a['innerShiv']( g ) );
          } else {
            e.innerHTML = g;
          };
          
          while ( f[0] --  )e = e.lastChild;
          return b.utils.makeArray( e.lastChild.childNodes );
        }
        function c( a ) {
          var b = jQuery['clean']( [a] );
          
          if ( b && b[0] ){
            var c = b[0];
            
            while ( c.parentNode && c.parentNode.nodeType !== 11 )c = c.parentNode;
            
            if ( c.parentNode ){
              c.parentNode.removeChild( c );
            };
          };
          return b;
        }
        b.utils.parseHtmlFragment = function ( e ) {
          return typeof jQuery != 'undefined'?c( e ) : d( e );
        };
        
        b.utils.setHtml = function ( a,c ) {
          b.utils.emptyDomNode( a );
          
          if ( ( c !== null ) && ( c !== undefined ) ){
            if ( typeof c != 'string' ){
              c = c.toString();
            };
            
            if ( typeof jQuery != 'undefined' ){
              jQuery( a )['html']( c );
            } else {
              var d = b.utils.parseHtmlFragment( c );
              
              for ( var e = 0;e<d.length;e ++  )
              a.appendChild( d[e] );
            };
          };
        };
      }();
      
      b.exportSymbol( 'ko.utils.parseHtmlFragment',b.utils.parseHtmlFragment );
      
      b.exportSymbol( 'ko.utils.setHtml',b.utils.setHtml );
      
      b.memoization = function () {
        var e = {};
        
        function a() {
          return ( ( ( 1+Math.random() )*0x00000000 )|0 ).toString( 16 ).substring( 1 );
        }
        function d() {
          return a()+a();
        }
        function c( d,e ) {
          if ( !d ){
            return ;
          };
          
          if ( d.nodeType == 8 ){
            var f = b.memoization.parseMemoText( d.nodeValue );
            
            if ( f != null ){
              e.push(  {
                domNode : d,
                memoId : f
              });
            };
          } else if ( d.nodeType == 1 ){
            for ( var g = 0,h = d.childNodes,i = h.length;g<i;g ++  )
            c( h[g],e );
          };
        }return  {
          memoize : function ( f ) {
            if ( typeof f != "function" ){
              throw new Error( "You can only pass a function to ko.memoization.memoize()" );
            };
            
            var g = d();
            
            e[g] = f;
            return "<!--[ko_memo:"+g+"]-->";
          },
          unmemoize : function ( a,b ) {
            var c = e[a];
            
            if ( c === undefined ){
              throw new Error( "Couldn't find any memo with ID "+a+". Perhaps it's already been unmemoized." );
            };
            
            try {
              c.apply( null,b || [] );
              return true;
            } finally {
              delete e[a];
            };
          },
          unmemoizeDomNodeAndDescendants : function ( a,d ) {
            var e = [];
            
            c( a,e );
            
            for ( var f = 0,g = e.length;f<g;f ++  ){
              var h = e[f].domNode;
              
              var i = [h];
              
              if ( d ){
                b.utils.arrayPushAll( i,d );
              };
              
              b.memoization.unmemoize( e[f].memoId,i );
              
              h.nodeValue = "";
              
              if ( h.parentNode ){
                h.parentNode.removeChild( h );
              };
            };
          },
          parseMemoText : function ( a ) {
            var b = a.match( /^\[ko_memo\:(.*?)\]$/ );
            return b?b[1] : null;
          }
        };
      }();
      
      b.exportSymbol( 'ko.memoization',b.memoization );
      
      b.exportSymbol( 'ko.memoization.memoize',b.memoization.memoize );
      
      b.exportSymbol( 'ko.memoization.unmemoize',b.memoization.unmemoize );
      
      b.exportSymbol( 'ko.memoization.parseMemoText',b.memoization.parseMemoText );
      
      b.exportSymbol( 'ko.memoization.unmemoizeDomNodeAndDescendants',b.memoization.unmemoizeDomNodeAndDescendants );
      
      b.extenders =  {
        'throttle' : function ( d,c ) {
          d['throttleEvaluation'] = c;
          
          var a = null;
          return b.dependentObservable(  {
            'read' : d,
            'write' : function ( b ) {
              clearTimeout( a );
              
              a = setTimeout( function () {
                d( b );
              },c);
            }
          });
        },
        'notify' : function ( a,c ) {
          a["equalityComparer"] = c == "always"?function () {
            return false;
          } : b.observable["fn"]["equalityComparer"];
          return a;
        }
      };
      
      function g( a ) {
        var c = this;
        
        if ( a ){
          for ( var d in a ){
            var e = b.extenders[d];
            
            if ( typeof e == 'function' ){
              c = e( c,a[d] );
            };
          };
        };
        return c;
      }
      b.exportSymbol( 'ko.extenders',b.extenders );
      
      b.subscription = function ( a,c ) {
        this.callback = a;
        
        this.disposeCallback = c;
        
        b.exportProperty( this,'dispose',this.dispose );
      };
      
      b.subscription.prototype.dispose = function () {
        this.isDisposed = true;
        
        this.disposeCallback();
      };
      
      b.subscribable = function () {
        this._subscriptions = {};
        
        b.utils.extend( this,b.subscribable['fn'] );
        
        b.exportProperty( this,'subscribe',this.subscribe );
        
        b.exportProperty( this,'extend',this.extend );
        
        b.exportProperty( this,'getSubscriptionsCount',this.getSubscriptionsCount );
      };
      
      var c = "change";
      
      b.subscribable['fn'] =  {
        subscribe : function ( e,f,a ) {
          a = a || c;
          
          var g = f?e.bind( f ) : e;
          
          var d = new b.subscription( g,function () {
                b.utils.arrayRemoveItem( this._subscriptions[a],d );
              }.bind( this ) );
          
          if ( !this._subscriptions[a] ){
            this._subscriptions[a] = [];
          };
          
          this._subscriptions[a].push( d );
          return d;
        },
        "notifySubscribers" : function ( a,d ) {
          d = d || c;
          
          if ( this._subscriptions[d] ){
            b.utils.arrayForEach( this._subscriptions[d].slice( 0 ),
            function ( b ) {
              if ( b && ( b.isDisposed !== true ) ){
                b.callback( a );
              };
            });
          };
        },
        getSubscriptionsCount : function () {
          var a = 0;
          
          for ( var b in this._subscriptions )
          if ( this._subscriptions.hasOwnProperty( b ) ){
            a += this._subscriptions[b].length;
          };
          return a;
        },
        extend : g
      };
      
      b.isSubscribable = function ( a ) {
        return typeof a.subscribe == "function" && typeof a["notifySubscribers"] == "function";
      };
      
      b.exportSymbol( 'ko.subscribable',b.subscribable );
      
      b.exportSymbol( 'ko.isSubscribable',b.isSubscribable );
      
      b.dependencyDetection = function () {
        var a = [];
        return  {
          begin : function ( b ) {
            a.push(  {
              callback : b,
              distinctDependencies : []
            });
          },
          end : function () {
            a.pop();
          },
          registerDependency : function ( c ) {
            if ( !b.isSubscribable( c ) ){
              throw "Only subscribable things can act as dependencies";
            };
            
            if ( a.length>0 ){
              var d = a[a.length-1];
              
              if ( b.utils.arrayIndexOf( d.distinctDependencies,c ) >= 0 ){
                return ;
              };
              
              d.distinctDependencies.push( c );
              
              d.callback( c );
            };
          }
        };
      }();
      
      var d =  {
            'undefined' : true,
            'boolean' : true,
            'number' : true,
            'string' : true
          };
      
      b.observable = function ( d ) {
        var c = d;
        
        function a() {
          if ( arguments.length>0 ){
            if ( ( !a['equalityComparer'] ) || !a['equalityComparer']( c,arguments[0] ) ){
              a.valueWillMutate();
              
              c = arguments[0];
              
              a.valueHasMutated();
            };
            return this;
          } else {
            b.dependencyDetection.registerDependency( a );
            return c;
          };
        }
        b.subscribable.call( a );
        
        a.valueHasMutated = function () {
          a["notifySubscribers"]( c );
        };
        
        a.valueWillMutate = function () {
          a["notifySubscribers"]( c,"beforeChange" );
        };
        
        b.utils.extend( a,b.observable['fn'] );
        
        b.exportProperty( a,"valueHasMutated",a.valueHasMutated );
        
        b.exportProperty( a,"valueWillMutate",a.valueWillMutate );
        return a;
      };
      
      b.observable['fn'] =  {
        __ko_proto__ : b.observable,
        "equalityComparer" : function h( e,f ) {
          var g = ( e === null ) || ( typeof ( e ) in d );
          return g?( e === f ) : false;
        }
      };
      
      b.isObservable = function ( a ) {
        if ( ( a === null ) || ( a === undefined ) || ( a.__ko_proto__ === undefined ) ){
          return false;
        };
        
        if ( a.__ko_proto__ === b.observable ){
          return true;
        };
        return b.isObservable( a.__ko_proto__ );
      };
      
      b.isWriteableObservable = function ( a ) {
        if ( ( typeof a == "function" ) && a.__ko_proto__ === b.observable ){
          return true;
        };
        
        if ( ( typeof a == "function" ) && ( a.__ko_proto__ === b.dependentObservable ) && ( a.hasWriteFunction ) ){
          return true;
        };
        return false;
      };
      
      b.exportSymbol( 'ko.observable',b.observable );
      
      b.exportSymbol( 'ko.isObservable',b.isObservable );
      
      b.exportSymbol( 'ko.isWriteableObservable',b.isWriteableObservable );
      
      b.observableArray = function ( a ) {
        if ( arguments.length == 0 ){
          a = [];
        };
        
        if ( ( a !== null ) && ( a !== undefined ) && !( 'length' in a ) ){
          throw new Error( "The argument passed when initializing an observable array must be an array, or null, or undefined." );
        };
        
        var c = new b.observable( a );
        
        b.utils.extend( c,b.observableArray['fn'] );
        
        b.exportProperty( c,"remove",c.remove );
        
        b.exportProperty( c,"removeAll",c.removeAll );
        
        b.exportProperty( c,"destroy",c.destroy );
        
        b.exportProperty( c,"destroyAll",c.destroyAll );
        
        b.exportProperty( c,"indexOf",c.indexOf );
        
        b.exportProperty( c,"replace",c.replace );
        return c;
      };
      
      b.observableArray['fn'] =  {
        remove : function ( a ) {
          var b = this();
          
          var c = [];
          
          var d = typeof a == "function"?a : function ( b ) {
                return b === a;
              };
          
          for ( var e = 0;e<b.length;e ++  ){
            var f = b[e];
            
            if ( d( f ) ){
              if ( c.length === 0 ){
                this.valueWillMutate();
              };
              
              c.push( f );
              
              b.splice( e,1 );
              
              e -- ;
            };
          };
          
          if ( c.length ){
            this.valueHasMutated();
          };
          return c;
        },
        removeAll : function ( a ) {
          if ( a === undefined ){
            var c = this();
            
            var d = c.slice( 0 );
            
            this.valueWillMutate();
            
            c.splice( 0,c.length );
            
            this.valueHasMutated();
            return d;
          };
          
          if ( !a ){
            return [];
          };
          return this.remove( function ( c ) {
            return b.utils.arrayIndexOf( a,c ) >= 0;
          });
        },
        destroy : function ( a ) {
          var b = this();
          
          var c = typeof a == "function"?a : function ( b ) {
                return b === a;
              };
          
          this.valueWillMutate();
          
          for ( var d = b.length-1;d >= 0;d --  ){
            var e = b[d];
            
            if ( c( e ) ){
              b[d]["_destroy"] = true;
            };
          };
          
          this.valueHasMutated();
        },
        destroyAll : function ( a ) {
          if ( a === undefined ){
            return this.destroy( function () {
              return true;
            });
          };
          
          if ( !a ){
            return [];
          };
          return this.destroy( function ( c ) {
            return b.utils.arrayIndexOf( a,c ) >= 0;
          });
        },
        indexOf : function ( a ) {
          var c = this();
          return b.utils.arrayIndexOf( c,a );
        },
        replace : function ( a,b ) {
          var c = this.indexOf( a );
          
          if ( c >= 0 ){
            this.valueWillMutate();
            
            this()[c] = b;
            
            this.valueHasMutated();
          };
        }
      };
      
      b.utils.arrayForEach( ["pop","push","reverse","shift","sort","splice","unshift"],
      function ( a ) {
        b.observableArray['fn'][a] = function () {
          var b = this();
          
          this.valueWillMutate();
          
          var c = b[a].apply( b,arguments );
          
          this.valueHasMutated();
          return c;
        };
      });
      
      b.utils.arrayForEach( ["slice"],
      function ( a ) {
        b.observableArray['fn'][a] = function () {
          var b = this();
          return b[a].apply( b,arguments );
        };
      });
      
      b.exportSymbol( 'ko.observableArray',b.observableArray );
      
      function e( a,b,c ) {
        if ( a && typeof a == "object" ){
          c = a;
        } else {
          c = c || {};
          
          c["read"] = a || c["read"];
        };
        
        if ( typeof c["read"] != "function" ){
          throw "Pass a function that returns the value of the dependentObservable";
        };
        return c;
      }
      b.dependentObservable = function ( p,l,j ) {
        var m,
            i = false,
            j = e( p,l,j );
        
        var c = ( typeof j["disposeWhenNodeIsRemoved"] == "object" )?j["disposeWhenNodeIsRemoved"] : null;
        
        var o = null;
        
        if ( c ){
          o = function () {
            a.dispose();
          };
          
          b.utils.domNodeDisposal.addDisposeCallback( c,o );
          
          var d = j["disposeWhen"];
          
          j["disposeWhen"] = function () {
            return ( !b.utils.domNodeIsAttachedToDocument( c ) ) || ( ( typeof d == "function" ) && d() );
          };
        };
        
        var f = [];
        
        function k() {
          b.utils.arrayForEach( f,
          function ( a ) {
            a.dispose();
          });
          
          f = [];
        }
        var g = null;
        
        function n() {
          var i = a['throttleEvaluation'];
          
          if ( i && i >= 0 ){
            clearTimeout( g );
            
            g = setTimeout( h,i );
          } else {
            h();
          };
        }
        function h() {
          if ( ( i ) && typeof j["disposeWhen"] == "function" ){
            if ( j["disposeWhen"]() ){
              a.dispose();
              return ;
            };
          };
          
          try {
            k();
            
            b.dependencyDetection.begin( function ( a ) {
              f.push( a.subscribe( n ) );
            });
            
            var o = j["owner"] || l;
            
            var p = j["read"].call( o );
            
            a["notifySubscribers"]( m,"beforeChange" );
            
            m = p;
          } finally {
            b.dependencyDetection.end();
          };
          
          a["notifySubscribers"]( m );
          
          i = true;
        }
        function a() {
          if ( arguments.length>0 ){
            if ( typeof j["write"] === "function" ){
              var c = j["owner"] || l;
              
              j["write"].apply( c,arguments );
            } else {
              throw "Cannot write a value to a dependentObservable unless you specify a 'write' option. If you wish to read the current value, don't pass any parameters.";
            };
          } else {
            if ( !i ){
              h();
            };
            
            b.dependencyDetection.registerDependency( a );
            return m;
          };
        }
        a.getDependenciesCount = function () {
          return f.length;
        };
        
        a.hasWriteFunction = typeof j["write"] === "function";
        
        a.dispose = function () {
          if ( c ){
            b.utils.domNodeDisposal.removeDisposeCallback( c,o );
          };
          
          k();
        };
        
        b.subscribable.call( a );
        
        b.utils.extend( a,b.dependentObservable['fn'] );
        
        if ( j['deferEvaluation'] !== true ){
          h();
        };
        
        b.exportProperty( a,'dispose',a.dispose );
        
        b.exportProperty( a,'getDependenciesCount',a.getDependenciesCount );
        return a;
      };
      
      b.dependentObservable['fn'] =  {
        __ko_proto__ : b.dependentObservable
      };
      
      b.dependentObservable.__ko_proto__ = b.observable;
      
      b.exportSymbol( 'ko.dependentObservable',b.dependentObservable );
      
      b.exportSymbol( 'ko.computed',b.dependentObservable );
      
      !function () {
        var c = 10;
        
        b.toJS = function ( d ) {
          if ( arguments.length == 0 ){
            throw new Error( "When calling ko.toJS, pass the object you want to convert." );
          };
          return a( d,
          function ( a ) {
            for ( var d = 0;b.isObservable( a ) && ( d<c );d ++  )
            a = a();
            return a;
          });
        };
        
        b.toJSON = function ( a ) {
          var c = b.toJS( a );
          return b.utils.stringifyJson( c );
        };
        
        function a( c,b,g ) {
          g = g || new d();
          
          c = b( c );
          
          var h = ( typeof c == "object" ) && ( c !== null ) && ( c !== undefined ) && ( !( c instanceof Date ) );
          
          if ( !h ){
            return c;
          };
          
          var f = c instanceof Array?[] : {};
          
          g.save( c,f );
          
          e( c,
          function ( h ) {
            var i = b( c[h] );
            
            switch ( typeof i ) {
              case "boolean" :
              case "number" :
              case "string" :
              case "function" :
                
                f[h] = i;
                break;
              case "object" :
              case "undefined" :
                
                var j = g.get( i );
                
                f[h] = ( j !== undefined )?j : a( i,b,g );
                break;
                
            };
          });
          return f;
        }
        function e( a,b ) {
          if ( a instanceof Array ){
            for ( var c = 0;c<a.length;c ++  )
            b( c );
          } else {
            for ( var d in a )
            b( d );
          };
        }
        function d() {
          var a = [];
          
          var c = [];
          
          this.save = function ( d,e ) {
            var f = b.utils.arrayIndexOf( a,d );
            
            if ( f >= 0 ){
              c[f] = e;
            } else {
              a.push( d );
              
              c.push( e );
            };
          };
          
          this.get = function ( d ) {
            var e = b.utils.arrayIndexOf( a,d );
            return ( e >= 0 )?c[e] : undefined;
          };
        }
      }();
      
      b.exportSymbol( 'ko.toJS',b.toJS );
      
      b.exportSymbol( 'ko.toJSON',b.toJSON );
      
      !function () {
        var a = '__ko__hasDomDataOptionValue__';
        
        b.selectExtensions =  {
          readValue : function ( c ) {
            if ( c.tagName == 'OPTION' ){
              if ( c[a] === true ){
                return b.utils.domData.get( c,b.bindingHandlers.options.optionValueDomDataKey );
              };
              return c.getAttribute( "value" );
            } else if ( c.tagName == 'SELECT' ){
              return c.selectedIndex >= 0?b.selectExtensions.readValue( c.options[c.selectedIndex] ) : undefined;
            } else {
              return c.value;
            };
          },
          writeValue : function ( c,d ) {
            if ( c.tagName == 'OPTION' ){
              switch ( typeof d ) {
                case "string" :
                  
                  b.utils.domData.set( c,b.bindingHandlers.options.optionValueDomDataKey,undefined );
                  
                  if ( a in c ){
                    delete c[a];
                  };
                  
                  c.value = d;
                  break;
                default :
                  
                  b.utils.domData.set( c,b.bindingHandlers.options.optionValueDomDataKey,d );
                  
                  c[a] = true;
                  
                  c.value = typeof d === "number"?d : "";
                  break;
                  
              };
            } else if ( c.tagName == 'SELECT' ){
              for ( var e = c.options.length-1;e >= 0;e --  )if ( b.selectExtensions.readValue( c.options[e] ) == d ){
                c.selectedIndex = e;
                break;
              };
            } else {
              if ( ( d === null ) || ( d === undefined ) ){
                d = "";
              };
              
              c.value = d;
            };
          }
        };
      }();
      
      b.exportSymbol( 'ko.selectExtensions',b.selectExtensions );
      
      b.exportSymbol( 'ko.selectExtensions.readValue',b.selectExtensions.readValue );
      
      b.exportSymbol( 'ko.selectExtensions.writeValue',b.selectExtensions.writeValue );
      
      b.jsonExpressionRewriting = function () {
        var a = /\@ko_token_(\d+)\@/g;
        
        var d = /^[\_$a-z][\_$a-z0-9]*(\[.*?\])*(\.[\_$a-z][\_$a-z0-9]*(\[.*?\])*)*$/i;
        
        var c = ["true","false"];
        
        function e( c,b ) {
          var d = null;
          
          while ( c != d ){
            d = c;
            
            c = c.replace( a,
            function ( c,d ) {
              return b[d];
            });
          };
          return c;
        }
        function g( e ) {
          if ( b.utils.arrayIndexOf( c,b.utils.stringTrim( e ).toLowerCase() ) >= 0 ){
            return false;
          };
          return e.match( d ) !== null;
        }
        function f( a ) {
          var c = b.utils.stringTrim( a );
          
          switch ( c.length && c.charAt( 0 ) ) {
            case "'" :
            case '"' :
              return a;
            default :
              return "'"+c+"'";
              
          };
        }return  {
          bindingRewriteValidators : [],
          parseObjectLiteral : function ( f ) {
            var g = b.utils.stringTrim( f );
            
            if ( g.length<3 ){
              return [];
            };
            
            if ( g.charAt( 0 ) === "{" ){
              g = g.substring( 1,g.length-1 );
            };
            
            var h = [];
            
            var i = null,
                j;
            
            for ( var k = 0;k<g.length;k ++  ){
              var l = g.charAt( k );
              
              if ( i === null ){
                switch ( l ) {
                  case '"' :
                  case "'" :
                  case "/" :
                    
                    i = k;
                    
                    j = l;
                    break;
                    
                };
              } else if ( ( l == j ) && ( g.charAt( k-1 ) !== "\\" ) ){
                var m = g.substring( i,k+1 );
                
                h.push( m );
                
                var n = "@ko_token_"+( h.length-1 )+"@";
                
                g = g.substring( 0,i )+n+g.substring( k+1 );
                
                k -= ( m.length-n.length );
                
                i = null;
              };
            };
            
            i = null;
            
            j = null;
            
            var o = 0,
                p = null;
            
            for ( var k = 0;k<g.length;k ++  ){
              var l = g.charAt( k );
              
              if ( i === null ){
                switch ( l ) {
                  case "{" :
                    
                    i = k;
                    
                    p = l;
                    
                    j = "}";
                    break;
                  case "(" :
                    
                    i = k;
                    
                    p = l;
                    
                    j = ")";
                    break;
                  case "[" :
                    
                    i = k;
                    
                    p = l;
                    
                    j = "]";
                    break;
                    
                };
              };
              
              if ( l === p ){
                o ++ ;
              } else if ( l === j ){
                o -- ;
                if ( o === 0 ){
                  var m = g.substring( i,k+1 );
                  
                  h.push( m );
                  
                  var n = "@ko_token_"+( h.length-1 )+"@";
                  
                  g = g.substring( 0,i )+n+g.substring( k+1 );
                  
                  k -= ( m.length-n.length );
                  
                  i = null;
                };
              };
            };
            
            var q = [];
            
            var r = g.split( "," );
            
            for ( var s = 0,t = r.length;s<t;s ++  ){
              var u = r[s];
              
              var v = u.indexOf( ":" );
              
              if ( ( v>0 ) && ( v<u.length-1 ) ){
                var w = u.substring( 0,v );
                
                var x = u.substring( v+1 );
                
                q.push(  {
                  'key' : e( w,h ),
                  'value' : e( x,h )
                });
              } else {
                q.push(  {
                  'unknown' : e( u,h )
                });
              };
            };
            return q;
          },
          insertPropertyAccessorsIntoJson : function ( h ) {
            var i = typeof h === "string"?b.jsonExpressionRewriting.parseObjectLiteral( h ) : h;
            
            var j = [],
                k = [];
            
            var l;
            
            for ( var m = 0;l = i[m];m ++  ){
              if ( j.length>0 ){
                j.push( "," );
              };
              
              if ( l['key'] ){
                var n = f( l['key'] ),
                    o = l['value'];
                
                j.push( n );
                
                j.push( ":" );
                
                j.push( o );
                
                if ( g( b.utils.stringTrim( o ) ) ){
                  if ( k.length>0 ){
                    k.push( ", " );
                  };
                  
                  k.push( n+" : function(__ko_value) { "+o+" = __ko_value; }" );
                };
              } else if ( l['unknown'] ){
                j.push( l['unknown'] );
              };
            };
            
            var p = j.join( "" );
            
            if ( k.length>0 ){
              var q = k.join( "" );
              
              p = p+", '_ko_property_writers' : { "+q+" } ";
            };
            return p;
          },
          keyValueArrayContainsKey : function ( a,c ) {
            for ( var d = 0;d<a.length;d ++  )
            if ( b.utils.stringTrim( a[d]['key'] ) == c ){
              return true;
            };
            return false;
          }
        };
      }();
      
      b.exportSymbol( 'ko.jsonExpressionRewriting',b.jsonExpressionRewriting );
      
      b.exportSymbol( 'ko.jsonExpressionRewriting.bindingRewriteValidators',b.jsonExpressionRewriting.bindingRewriteValidators );
      
      b.exportSymbol( 'ko.jsonExpressionRewriting.parseObjectLiteral',b.jsonExpressionRewriting.parseObjectLiteral );
      
      b.exportSymbol( 'ko.jsonExpressionRewriting.insertPropertyAccessorsIntoJson',b.jsonExpressionRewriting.insertPropertyAccessorsIntoJson );
      
      !function () {
        var a = document.createComment( "test" ).text === "<!--test-->";
        
        var c = a?/^<!--\s*ko\s+(.*\:.*)\s*-->$/ : /^\s*ko\s+(.*\:.*)\s*$/;
        
        var d = a?/^<!--\s*\/ko\s*-->$/ : /^\s*\/ko\s*$/;
        
        var j =  {
              'ul' : true,
              'ol' : true
            };
        
        function f( d ) {
          return ( d.nodeType == 8 ) && ( a?d.text : d.nodeValue ).match( c );
        }
        function e( e ) {
          return ( e.nodeType == 8 ) && ( a?e.text : e.nodeValue ).match( d );
        }
        function g( g,h ) {
          var i = g;
          
          var j = 1;
          
          var k = [];
          
          while ( i = i.nextSibling ){
            if ( e( i ) ){
              j -- ;
              
              if ( j === 0 ){
                return k;
              };
            };
            
            k.push( i );
            
            if ( f( i ) ){
              j ++ ;
            };
          };
          
          if ( !h ){
            throw new Error( "Cannot find closing comment tag to match: "+g.nodeValue );
          };
          return null;
        }
        function h( h,i ) {
          var j = g( h,i );
          
          if ( j ){
            if ( j.length>0 ){
              return j[j.length-1].nextSibling;
            };
            return h.nextSibling;
          } else {
            return null;
          };
        }
        function i( a,c ) {
          var d = [];
          
          for ( var e = 0,f = a.length;e<f;e ++  ){
            if ( c ){
              b.utils.domNodeDisposal.cleanNode( a[e] );
            };
            
            d.push( b.utils.outerHTML( a[e] ) );
          };
          return String.prototype.concat.apply( "",d );
        }
        function k( i ) {
          var j = i.firstChild,
              k = null;
          
          if ( j ){
            do if ( k ){
              k.push( j );
            } else if ( f( j ) ){
              var l = h( j,true );
              if ( l ){
                j = l;
              } else {
                k = [j];
              };
            } else if ( e( j ) ){
              k = [j];
            };
            while ( j = j.nextSibling );
          };
          return k;
        }
        b.virtualElements =  {
          allowedBindings : {},
          childNodes : function ( a ) {
            return f( a )?g( a ) : a.childNodes;
          },
          emptyNode : function ( a ) {
            if ( !f( a ) ){
              b.utils.emptyDomNode( a );
            } else {
              var c = b.virtualElements.childNodes( a );
              
              for ( var d = 0,e = c.length;d<e;d ++  )
              b.removeNode( c[d] );
            };
          },
          setDomNodeChildren : function ( a,c ) {
            if ( !f( a ) ){
              b.utils.setDomNodeChildren( a,c );
            } else {
              b.virtualElements.emptyNode( a );
              
              var d = a.nextSibling;
              
              for ( var e = 0,g = c.length;e<g;e ++  )
              d.parentNode.insertBefore( c[e],d );
            };
          },
          prepend : function ( a,b ) {
            if ( !f( a ) ){
              if ( a.firstChild ){
                a.insertBefore( b,a.firstChild );
              } else {
                a.appendChild( b );
              };
            } else {
              a.parentNode.insertBefore( b,a.nextSibling );
            };
          },
          insertAfter : function ( a,b,c ) {
            if ( !f( a ) ){
              if ( c.nextSibling ){
                a.insertBefore( b,c.nextSibling );
              } else {
                a.appendChild( b );
              };
            } else {
              a.parentNode.insertBefore( b,c.nextSibling );
            };
          },
          nextSibling : function ( a ) {
            if ( !f( a ) ){
              if ( a.nextSibling && e( a.nextSibling ) ){
                return undefined;
              };
              return a.nextSibling;
            } else {
              return h( a ).nextSibling;
            };
          },
          virtualNodeBindingValue : function ( a ) {
            var b = f( a );
            return b?b[1] : null;
          },
          extractAnonymousTemplateIfVirtualElement : function ( j ) {
            if ( b.virtualElements.virtualNodeBindingValue( j ) ){
              var k = b.virtualElements.childNodes( j );
              
              var l = i( k,true );
              
              b.virtualElements.emptyNode( j );
              
              new b.templateSources.anonymousTemplate( j ).text( l );
            };
          },
          normaliseVirtualElementDomStructure : function ( l ) {
            if ( !j[l.tagName.toLowerCase()] ){
              return ;
            };
            
            var m = l.firstChild;
            
            if ( m ){
              do if ( m.nodeType === 1 ){
                var n = k( m );
                
                if ( n ){
                  var o = m.nextSibling;
                  
                  for ( var p = 0;p<n.length;p ++  )
                  if ( o ){
                    l.insertBefore( n[p],o );
                  } else {
                    l.appendChild( n[p] );
                  };
                };
              };
              while ( m = m.nextSibling );
            };
          }
        };
      }();
      
      !function () {
        var c = "data-bind";
        
        b.bindingProvider = function (){};
        
        b.utils.extend( b.bindingProvider.prototype, {
          'nodeHasBindings' : function ( d ) {
            switch ( d.nodeType ) {
              case 1 :
                return d.getAttribute( c ) != null;
              case 8 :
                return b.virtualElements.virtualNodeBindingValue( d ) != null;
              default :
                return false;
                
            };
          },
          'getBindings' : function ( a,b ) {
            var c = this['getBindingsString']( a,b );
            return c?this['parseBindingsString']( c,b ) : null;
          },
          'getBindingsString' : function ( a,d ) {
            switch ( a.nodeType ) {
              case 1 :
                return a.getAttribute( c );
              case 8 :
                return b.virtualElements.virtualNodeBindingValue( a );
              default :
                return null;
                
            };
          },
          'parseBindingsString' : function ( c,d ) {
            try {
              var e = d['$data'];
              
              var f = " { "+b.jsonExpressionRewriting.insertPropertyAccessorsIntoJson( c )+" } ";
              return b.utils.evalWithinScope( f,e === null?a : e,d );
            } catch( ex ){
              throw new Error( "Unable to parse bindings.\nMessage: "+ex+";\nBindings value: "+c );
            };
          }
        });
        
        b.bindingProvider['instance'] = new b.bindingProvider();
      }();
      
      b.exportSymbol( 'ko.bindingProvider',b.bindingProvider );
      
      !function () {
        b.bindingHandlers = {};
        
        b.bindingContext = function ( a,b ) {
          this['$data'] = a;
          
          if ( b ){
            this['$parent'] = b['$data'];
            
            this['$parents'] = ( b['$parents'] || [] ).slice( 0 );
            
            this['$parents'].unshift( this['$parent'] );
            
            this['$root'] = b['$root'];
          } else {
            this['$parents'] = [];
            
            this['$root'] = a;
          };
        };
        
        b.bindingContext.prototype['createChildContext'] = function ( a ) {
          return new b.bindingContext( a,this );
        };
        
        function f( a ) {
          var c = b.virtualElements.allowedBindings[a];
          
          if ( !c ){
            throw new Error( "The binding '"+a+"' cannot be used with virtual elements" );
          };
        }
        function e( d,e ) {
          var f,
              g = e.childNodes[0];
          
          while ( f = g ){
            g = b.virtualElements.nextSibling( f );
            
            c( d,f,false );
          };
        }
        function c( f,g,h ) {
          var i = true;
          
          var j = ( g.nodeType == 1 );
          
          if ( j ){
            b.virtualElements.normaliseVirtualElementDomStructure( g );
          };
          
          var k = ( j && h ) || b.bindingProvider['instance']['nodeHasBindings']( g );
          
          if ( k ){
            i = d( g,null,f,h ).shouldBindDescendants;
          };
          
          if ( j && i ){
            e( f,g );
          };
        }
        function d( e,g,c,d ) {
          var h = 0;
          
          b.virtualElements.extractAnonymousTemplateIfVirtualElement( e );
          
          var a;
          
          function i( b ) {
            return function () {
              return a[b];
            };
          }
          function j() {
            return a;
          }
          var k;
          
          new b.dependentObservable( function () {
            var l = c && ( c instanceof b.bindingContext )?c : new b.bindingContext( b.utils.unwrapObservable( c ) );
            
            var m = l['$data'];
            
            if ( d ){
              b.storedBindingContextForNode( e,l );
            };
            
            var n = ( typeof g == "function" )?g() : g;
            
            a = n || b.bindingProvider['instance']['getBindings']( e,l );
            
            if ( a ){
              if ( h === 0 ){
                h = 1;
                
                for ( var o in a ){
                  var p = b.bindingHandlers[o];
                  
                  if ( p && e.nodeType === 8 ){
                    f( o );
                  };
                  
                  if ( p && typeof p["init"] == "function" ){
                    var q = p["init"];
                    
                    var r = q( e,i( o ),j,m,l );
                    
                    if ( r && r['controlsDescendantBindings'] ){
                      if ( k !== undefined ){
                        throw new Error( "Multiple bindings ("+k+" and "+o+") are trying to control descendant bindings of the same element. You cannot use these bindings together on the same element." );
                      };
                      
                      k = o;
                    };
                  };
                };
                
                h = 2;
              };
              
              if ( h === 2 ){
                for ( var o in a ){
                  var p = b.bindingHandlers[o];
                  
                  if ( p && typeof p["update"] == "function" ){
                    var s = p["update"];
                    
                    s( e,i( o ),j,m,l );
                  };
                };
              };
            };
          },null, {
            'disposeWhenNodeIsRemoved' : e
          });
          return  {
            shouldBindDescendants : k === undefined
          };
        }
        var g = "__ko_bindingContext__";
        
        b.storedBindingContextForNode = function ( h,i ) {
          if ( arguments.length == 2 ){
            b.utils.domData.set( h,g,i );
          } else {
            return b.utils.domData.get( h,g );
          };
        };
        
        b.applyBindingsToNode = function ( a,c,e ) {
          if ( a.nodeType === 1 ){
            b.virtualElements.normaliseVirtualElementDomStructure( a );
          };
          return d( a,c,e,true );
        };
        
        b.applyBindingsToDescendants = function ( a,b ) {
          if ( b.nodeType === 1 ){
            e( a,b );
          };
        };
        
        b.applyBindings = function ( b,d ) {
          if ( d && ( d.nodeType !== 1 ) && ( d.nodeType !== 8 ) ){
            throw new Error( "ko.applyBindings: first parameter should be your view model; second parameter should be a DOM node" );
          };
          
          d = d || a.document.body;
          
          c( b,d,true );
        };
        
        b.contextFor = function ( a ) {
          switch ( a.nodeType ) {
            case 1 :
            case 8 :
              
              var c = b.storedBindingContextForNode( a );
              
              if ( c ){
                return c;
              };
              
              if ( a.parentNode ){
                return b.contextFor( a.parentNode );
              };
              break;
              
          };
          return undefined;
        };
        
        b.dataFor = function ( a ) {
          var c = b.contextFor( a );
          return c?c['$data'] : undefined;
        };
        
        b.exportSymbol( 'ko.bindingHandlers',b.bindingHandlers );
        
        b.exportSymbol( 'ko.applyBindings',b.applyBindings );
        
        b.exportSymbol( 'ko.applyBindingsToDescendants',b.applyBindingsToDescendants );
        
        b.exportSymbol( 'ko.applyBindingsToNode',b.applyBindingsToNode );
        
        b.exportSymbol( 'ko.contextFor',b.contextFor );
        
        b.exportSymbol( 'ko.dataFor',b.dataFor );
      }();
      
      var i = ['click'];
      
      b.utils.arrayForEach( i,
      function ( a ) {
        b.bindingHandlers[a] =  {
          'init' : function ( d,c,e,f ) {
            var g = function () {
                  var d = {};
                  
                  d[a] = c();
                  return d;
                };
            return b.bindingHandlers['event']['init'].call( this,d,g,e,f );
          }
        };
      });
      
      b.bindingHandlers['event'] =  {
        'init' : function ( c,d,e,f ) {
          var g = d() || {};
          
          for ( var a in g )
          !function () {
            var g = a;
            
            if ( typeof g == "string" ){
              b.utils.registerEventHandler( c,g,
              function ( h ) {
                var i;
                
                var j = d()[g];
                
                if ( !j ){
                  return ;
                };
                
                var k = e();
                
                try {
                  var l = b.utils.makeArray( arguments );
                  
                  l.unshift( f );
                  
                  i = j.apply( f,l );
                } finally {
                  if ( i !== true ){
                    if ( h.preventDefault ){
                      h.preventDefault();
                    } else {
                      h.returnValue = false;
                    };
                  };
                };
                
                var m = k[g+'Bubble'] !== false;
                
                if ( !m ){
                  h.cancelBubble = true;
                  
                  if ( h.stopPropagation ){
                    h.stopPropagation();
                  };
                };
              });
            };
          }();
        }
      };
      
      b.bindingHandlers['submit'] =  {
        'init' : function ( d,a,e,c ) {
          if ( typeof a() != "function" ){
            throw new Error( "The value for a submit binding must be a function" );
          };
          
          b.utils.registerEventHandler( d,"submit",
          function ( e ) {
            var f;
            
            var g = a();
            
            try {
              f = g.call( c,d );
            } finally {
              if ( f !== true ){
                if ( e.preventDefault ){
                  e.preventDefault();
                } else {
                  e.returnValue = false;
                };
              };
            };
          });
        }
      };
      
      b.bindingHandlers['visible'] =  {
        'update' : function ( a,c ) {
          var d = b.utils.unwrapObservable( c() );
          
          var e = !( a.style.display == "none" );
          
          if ( d && !e ){
            a.style.display = "";
          } else if ( ( !d ) && e ){
            a.style.display = "none";
          };
        }
      };
      
      b.bindingHandlers['enable'] =  {
        'update' : function ( a,c ) {
          var d = b.utils.unwrapObservable( c() );
          
          if ( d && a.disabled ){
            a.removeAttribute( "disabled" );
          } else if ( ( !d ) && ( !a.disabled ) ){
            a.disabled = true;
          };
        }
      };
      
      b.bindingHandlers['disable'] =  {
        'update' : function ( c,a ) {
          b.bindingHandlers['enable']['update']( c,
          function () {
            return !b.utils.unwrapObservable( a() );
          });
        }
      };
      
      function f( a,c,d ) {
        if ( d ){
          if ( c !== b.selectExtensions.readValue( a ) ){
            b.selectExtensions.writeValue( a,c );
          };
        };
        
        if ( c !== b.selectExtensions.readValue( a ) ){
          b.utils.triggerEvent( a,"change" );
        };
      }
      b.bindingHandlers['value'] =  {
        'init' : function ( a,c,d ) {
          var e = ["change"];
          
          var f = d()["valueUpdate"];
          
          if ( f ){
            if ( typeof f == "string" ){
              f = [f];
            };
            
            b.utils.arrayPushAll( e,f );
            
            e = b.utils.arrayGetDistinctValues( e );
          };
          
          b.utils.arrayForEach( e,
          function ( f ) {
            var g = false;
            
            if ( b.utils.stringStartsWith( f,"after" ) ){
              g = true;
              
              f = f.substring( "after".length );
            };
            
            var e = g?function ( a ) {
                  setTimeout( a,0 );
                } : function ( a ) {
                  a();
                };
            
            b.utils.registerEventHandler( a,f,
            function () {
              e( function () {
                var e = c();
                
                var f = b.selectExtensions.readValue( a );
                
                if ( b.isWriteableObservable( e ) ){
                  e( f );
                } else {
                  var g = d();
                  if ( g['_ko_property_writers'] && g['_ko_property_writers']['value'] ){
                    g['_ko_property_writers']['value']( f );
                  };
                };
              });
            });
          });
        },
        'update' : function ( a,g ) {
          var c = b.utils.unwrapObservable( g() );
          
          var h = b.selectExtensions.readValue( a );
          
          var i = ( c != h );
          
          if ( ( c === 0 ) && ( h !== 0 ) && ( h !== "0" ) ){
            i = true;
          };
          
          if ( i ){
            var j = function () {
                  b.selectExtensions.writeValue( a,c );
                };
            
            j();
            
            var k = a.tagName == "SELECT";
            
            if ( k ){
              setTimeout( j,0 );
            };
          };
          
          if ( ( a.tagName == "SELECT" ) && ( a.length>0 ) ){
            f( a,c,false );
          };
        }
      };
      
      b.bindingHandlers['options'] =  {
        'update' : function ( a,c,d ) {
          if ( a.tagName != "SELECT" ){
            throw new Error( "options binding applies only to SELECT elements" );
          };
          
          var e = a.length == 0;
          
          var g = b.utils.arrayMap( b.utils.arrayFilter( a.childNodes,
              function ( a ) {
                return a.tagName && a.tagName == "OPTION" && a.selected;
              }),
              function ( a ) {
                return b.selectExtensions.readValue( a ) || a.innerText || a.textContent;
              });
          
          var h = a.scrollTop;
          
          a.scrollTop = 0;
          
          var i = b.utils.unwrapObservable( c() );
          
          var j = a.value;
          
          while ( a.length>0 ){
            b.cleanNode( a.options[0] );
            
            a.remove( 0 );
          };
          
          if ( i ){
            var k = d();
            
            if ( typeof i.length != "number" ){
              i = [i];
            };
            
            if ( k['optionsCaption'] ){
              var l = document.createElement( "OPTION" );
              
              b.utils.setHtml( l,k['optionsCaption'] );
              
              b.selectExtensions.writeValue( l,undefined );
              
              a.appendChild( l );
            };
            
            for ( var m = 0,n = i.length;m<n;m ++  ){
              var l = document.createElement( "OPTION" );
              
              var o = typeof k['optionsValue'] == "string"?i[m][k['optionsValue']] : i[m];
              
              o = b.utils.unwrapObservable( o );
              
              b.selectExtensions.writeValue( l,o );
              
              var p = k['optionsText'];
              
              var q;
              
              if ( typeof p == "function" ){
                q = p( i[m] );
              } else if ( typeof p == "string" ){
                q = i[m][p];
              } else {
                q = o;
              };
              
              if ( ( q === null ) || ( q === undefined ) ){
                q = "";
              };
              
              b.utils.setTextContent( l,q );
              
              a.appendChild( l );
            };
            
            var r = a.getElementsByTagName( "OPTION" );
            
            var s = 0;
            
            for ( var m = 0,n = r.length;m<n;m ++  )
            if ( b.utils.arrayIndexOf( g,b.selectExtensions.readValue( r[m] ) ) >= 0 ){
              b.utils.setOptionNodeSelectionState( r[m],true );
              
              s ++ ;
            };
            
            if ( h ){
              a.scrollTop = h;
            };
            
            if ( e && ( 'value' in k ) ){
              f( a,b.utils.unwrapObservable( k['value'] ),true );
            };
          };
        }
      };
      
      b.bindingHandlers['options'].optionValueDomDataKey = '__ko.optionValueDomData__';
      
      b.bindingHandlers['selectedOptions'] =  {
        getSelectedValuesFromSelectNode : function ( a ) {
          var c = [];
          
          var d = a.childNodes;
          
          for ( var e = 0,f = d.length;e<f;e ++  ){
            var g = d[e];
            
            if ( ( g.tagName == "OPTION" ) && g.selected ){
              c.push( b.selectExtensions.readValue( g ) );
            };
          };
          return c;
        },
        'init' : function ( d,a,c ) {
          b.utils.registerEventHandler( d,"change",
          function () {
            var d = a();
            
            if ( b.isWriteableObservable( d ) ){
              d( b.bindingHandlers['selectedOptions'].getSelectedValuesFromSelectNode( this ) );
            } else {
              var e = c();
              if ( e['_ko_property_writers'] && e['_ko_property_writers']['value'] ){
                e['_ko_property_writers']['value']( b.bindingHandlers['selectedOptions'].getSelectedValuesFromSelectNode( this ) );
              };
            };
          });
        },
        'update' : function ( a,c ) {
          if ( a.tagName != "SELECT" ){
            throw new Error( "values binding applies only to SELECT elements" );
          };
          
          var d = b.utils.unwrapObservable( c() );
          
          if ( d && typeof d.length == "number" ){
            var e = a.childNodes;
            
            for ( var f = 0,g = e.length;f<g;f ++  ){
              var h = e[f];
              
              if ( h.tagName == "OPTION" ){
                b.utils.setOptionNodeSelectionState( h,b.utils.arrayIndexOf( d,b.selectExtensions.readValue( h ) ) >= 0 );
              };
            };
          };
        }
      };
      
      b.bindingHandlers['text'] =  {
        'update' : function ( a,c ) {
          b.utils.setTextContent( a,c() );
        }
      };
      
      b.bindingHandlers['html'] =  {
        'init' : function () {
          return  {
            'controlsDescendantBindings' : true
          };
        },
        'update' : function ( a,c ) {
          var d = b.utils.unwrapObservable( c() );
          
          b.utils.setHtml( a,d );
        }
      };
      
      b.bindingHandlers['css'] =  {
        'update' : function ( a,c ) {
          var d = b.utils.unwrapObservable( c() || {} );
          
          for ( var e in d )
          if ( typeof e == "string" ){
            var f = b.utils.unwrapObservable( d[e] );
            
            b.utils.toggleDomNodeCssClass( a,e,f );
          };
        }
      };
      
      b.bindingHandlers['style'] =  {
        'update' : function ( a,c ) {
          var d = b.utils.unwrapObservable( c() || {} );
          
          for ( var e in d )
          if ( typeof e == "string" ){
            var f = b.utils.unwrapObservable( d[e] );
            
            a.style[e] = f || "";
          };
        }
      };
      
      b.bindingHandlers['uniqueName'] =  {
        'init' : function ( a,c ) {
          if ( c() ){
            a.name = "ko_unique_"+(  ++ b.bindingHandlers['uniqueName'].currentIndex );
            
            if ( b.utils.isIe6 || b.utils.isIe7 ){
              a.mergeAttributes( document.createElement( "<input name='"+a.name+"'/>" ),false );
            };
          };
        }
      };
      
      b.bindingHandlers['uniqueName'].currentIndex = 0;
      
      b.bindingHandlers['checked'] =  {
        'init' : function ( a,c,d ) {
          var e = function () {
                var e;
                
                if ( a.type == "checkbox" ){
                  e = a.checked;
                } else if ( ( a.type == "radio" ) && ( a.checked ) ){
                  e = a.value;
                } else {
                  return ;
                };
                
                var f = c();
                
                if ( ( a.type == "checkbox" ) && ( b.utils.unwrapObservable( f ) instanceof Array ) ){
                  var g = b.utils.arrayIndexOf( b.utils.unwrapObservable( f ),a.value );
                  
                  if ( a.checked && ( g<0 ) ){
                    f.push( a.value );
                  } else if ( ( !a.checked ) && ( g >= 0 ) ){
                    f.splice( g,1 );
                  };
                } else if ( b.isWriteableObservable( f ) ){
                  if ( f() !== e ){
                    f( e );
                  };
                } else {
                  var h = d();
                  if ( h['_ko_property_writers'] && h['_ko_property_writers']['checked'] ){
                    h['_ko_property_writers']['checked']( e );
                  };
                };
              };
          
          b.utils.registerEventHandler( a,"click",e );
          
          if ( ( a.type == "radio" ) && !a.name ){
            b.bindingHandlers['uniqueName']['init']( a,
            function () {
              return true;
            });
          };
        },
        'update' : function ( a,c ) {
          var d = b.utils.unwrapObservable( c() );
          
          if ( a.type == "checkbox" ){
            if ( d instanceof Array ){
              a.checked = b.utils.arrayIndexOf( d,a.value ) >= 0;
            } else {
              a.checked = d;
            };
          } else if ( a.type == "radio" ){
            a.checked = ( a.value == d );
          };
        }
      };
      
      b.bindingHandlers['attr'] =  {
        'update' : function ( a,c,d ) {
          var e = b.utils.unwrapObservable( c() ) || {};
          
          for ( var f in e )
          if ( typeof f == "string" ){
            var g = b.utils.unwrapObservable( e[f] );
            
            if ( ( g === false ) || ( g === null ) || ( g === undefined ) ){
              a.removeAttribute( f );
            } else {
              a.setAttribute( f,g.toString() );
            };
          };
        }
      };
      
      b.bindingHandlers['hasfocus'] =  {
        'init' : function ( e,a,c ) {
          var d = function ( d ) {
                var e = a();
                
                if ( d == b.utils.unwrapObservable( e ) ){
                  return ;
                };
                
                if ( b.isWriteableObservable( e ) ){
                  e( d );
                } else {
                  var f = c();
                  if ( f['_ko_property_writers'] && f['_ko_property_writers']['hasfocus'] ){
                    f['_ko_property_writers']['hasfocus']( d );
                  };
                };
              };
          
          b.utils.registerEventHandler( e,"focus",
          function () {
            d( true );
          });
          
          b.utils.registerEventHandler( e,"focusin",
          function () {
            d( true );
          });
          
          b.utils.registerEventHandler( e,"blur",
          function () {
            d( false );
          });
          
          b.utils.registerEventHandler( e,"focusout",
          function () {
            d( false );
          });
        },
        'update' : function ( a,c ) {
          var d = b.utils.unwrapObservable( c() );
          
          d?a.focus() : a.blur();
          
          b.utils.triggerEvent( a,d?"focusin" : "focusout" );
        }
      };
      
      b.bindingHandlers['with'] =  {
        makeTemplateValueAccessor : function ( a ) {
          return function () {
            var c = a();
            return  {
              'if' : c,
              'data' : c,
              'templateEngine' : b.nativeTemplateEngine.instance
            };
          };
        },
        'init' : function ( a,c,d,e,f ) {
          return b.bindingHandlers['template']['init']( a,b.bindingHandlers['with'].makeTemplateValueAccessor( c ) );
        },
        'update' : function ( a,c,d,e,f ) {
          return b.bindingHandlers['template']['update']( a,b.bindingHandlers['with'].makeTemplateValueAccessor( c ),d,e,f );
        }
      };
      
      b.jsonExpressionRewriting.bindingRewriteValidators['with'] = false;
      
      b.virtualElements.allowedBindings['with'] = true;
      
      b.bindingHandlers['if'] =  {
        makeTemplateValueAccessor : function ( a ) {
          return function () {
            return  {
              'if' : a(),
              'templateEngine' : b.nativeTemplateEngine.instance
            };
          };
        },
        'init' : function ( a,c,d,e,f ) {
          return b.bindingHandlers['template']['init']( a,b.bindingHandlers['if'].makeTemplateValueAccessor( c ) );
        },
        'update' : function ( a,c,d,e,f ) {
          return b.bindingHandlers['template']['update']( a,b.bindingHandlers['if'].makeTemplateValueAccessor( c ),d,e,f );
        }
      };
      
      b.jsonExpressionRewriting.bindingRewriteValidators['if'] = false;
      
      b.virtualElements.allowedBindings['if'] = true;
      
      b.bindingHandlers['ifnot'] =  {
        makeTemplateValueAccessor : function ( a ) {
          return function () {
            return  {
              'ifnot' : a(),
              'templateEngine' : b.nativeTemplateEngine.instance
            };
          };
        },
        'init' : function ( a,c,d,e,f ) {
          return b.bindingHandlers['template']['init']( a,b.bindingHandlers['ifnot'].makeTemplateValueAccessor( c ) );
        },
        'update' : function ( a,c,d,e,f ) {
          return b.bindingHandlers['template']['update']( a,b.bindingHandlers['ifnot'].makeTemplateValueAccessor( c ),d,e,f );
        }
      };
      
      b.jsonExpressionRewriting.bindingRewriteValidators['ifnot'] = false;
      
      b.virtualElements.allowedBindings['ifnot'] = true;
      
      b.bindingHandlers['foreach'] =  {
        makeTemplateValueAccessor : function ( a ) {
          return function () {
            var c = b.utils.unwrapObservable( a() );
            
            if ( ( !c ) || typeof c.length == "number" ){
              return  {
                'foreach' : c,
                'templateEngine' : b.nativeTemplateEngine.instance
              };
            };
            return  {
              'foreach' : c['data'],
              'includeDestroyed' : c['includeDestroyed'],
              'afterAdd' : c['afterAdd'],
              'beforeRemove' : c['beforeRemove'],
              'afterRender' : c['afterRender'],
              'templateEngine' : b.nativeTemplateEngine.instance
            };
          };
        },
        'init' : function ( a,c,d,e,f ) {
          return b.bindingHandlers['template']['init']( a,b.bindingHandlers['foreach'].makeTemplateValueAccessor( c ) );
        },
        'update' : function ( a,c,d,e,f ) {
          return b.bindingHandlers['template']['update']( a,b.bindingHandlers['foreach'].makeTemplateValueAccessor( c ),d,e,f );
        }
      };
      
      b.jsonExpressionRewriting.bindingRewriteValidators['foreach'] = false;
      
      b.virtualElements.allowedBindings['foreach'] = true;
      
      b.exportSymbol( 'ko.allowedVirtualElementBindings',b.virtualElements.allowedBindings );
      
      b.templateEngine = function (){};
      
      b.templateEngine.prototype['renderTemplateSource'] = function ( a,b,c ) {
        throw "Override renderTemplateSource";
      };
      
      b.templateEngine.prototype['createJavaScriptEvaluatorBlock'] = function ( a ) {
        throw "Override createJavaScriptEvaluatorBlock";
      };
      
      b.templateEngine.prototype['makeTemplateSource'] = function ( a ) {
        if ( typeof a == "string" ){
          var c = document.getElementById( a );
          
          if ( !c ){
            throw new Error( "Cannot find template with ID "+a );
          };
          return new b.templateSources.domElement( c );
        } else if ( ( a.nodeType == 1 ) || ( a.nodeType == 8 ) ){
          return new b.templateSources.anonymousTemplate( a );
        } else {
          throw new Error( "Unknown template type: "+a );
        };
      };
      
      b.templateEngine.prototype['renderTemplate'] = function ( a,b,c ) {
        var d = this['makeTemplateSource']( a );
        return this['renderTemplateSource']( d,b,c );
      };
      
      b.templateEngine.prototype['isTemplateRewritten'] = function ( a ) {
        if ( this['allowTemplateRewriting'] === false ){
          return true;
        };
        
        if ( this.knownRewrittenTemplates && this.knownRewrittenTemplates[a] ){
          return true;
        };
        return this['makeTemplateSource']( a )['data']( "isRewritten" );
      };
      
      b.templateEngine.prototype['rewriteTemplate'] = function ( a,b ) {
        var c = this['makeTemplateSource']( a );
        
        var d = b( c['text']() );
        
        c['text']( d );
        
        c['data']( "isRewritten",true );
        
        if ( typeof a == "string" ){
          this.knownRewrittenTemplates = this.knownRewrittenTemplates || {};
          
          this.knownRewrittenTemplates[a] = true;
        };
      };
      
      b.exportSymbol( 'ko.templateEngine',b.templateEngine );
      
      b.templateRewriting = function () {
        var c = /(<[a-z]+\d*(\s+(?!data-bind=)[a-z0-9\-]+(=(\"[^\"]*\"|\'[^\']*\'))?)*\s+)data-bind=(["'])([\s\S]*?)\5/gi;
        
        var d = /<!--\s*ko\b\s*([\s\S]*?)\s*-->/g;
        
        function a( a ) {
          var c = b.jsonExpressionRewriting.bindingRewriteValidators;
          
          for ( var d = 0;d<a.length;d ++  ){
            var e = a[d]['key'];
            
            if ( c.hasOwnProperty( e ) ){
              var f = c[e];
              
              if ( typeof f === "function" ){
                var g = f( a[d]['value'] );
                
                if ( g ){
                  throw new Error( g );
                };
              } else if ( !f ){
                throw new Error( "This template engine does not support the '"+e+"' binding within its templates" );
              };
            };
          };
        }
        function e( c,d,e ) {
          var f = b.jsonExpressionRewriting.parseObjectLiteral( c );
          
          a( f );
          
          var g = b.jsonExpressionRewriting.insertPropertyAccessorsIntoJson( f );
          
          var h = "ko.templateRewriting.applyMemoizedBindingsToNextSibling(function() { \
            return (function() { return { "+g+" } })() \
        })";
          return e['createJavaScriptEvaluatorBlock']( h )+d;
        }return  {
          ensureTemplateIsRewritten : function ( c,a ) {
            if ( !a['isTemplateRewritten']( c ) ){
              a['rewriteTemplate']( c,
              function ( c ) {
                return b.templateRewriting.memoizeBindingAttributeSyntax( c,a );
              });
            };
          },
          memoizeBindingAttributeSyntax : function ( f,a ) {
            return f.replace( c,
            function () {
              return e( arguments[6],arguments[1],a );
            }).replace( d,
            function () {
              return e( arguments[1],"<!-- ko -->",a );
            });
          },
          applyMemoizedBindingsToNextSibling : function ( a ) {
            return b.memoization.memoize( function ( c,d ) {
              if ( c.nextSibling ){
                b.applyBindingsToNode( c.nextSibling,a,d );
              };
            });
          }
        };
      }();
      
      b.exportSymbol( 'ko.templateRewriting',b.templateRewriting );
      
      b.exportSymbol( 'ko.templateRewriting.applyMemoizedBindingsToNextSibling',b.templateRewriting.applyMemoizedBindingsToNextSibling );
      
      !function () {
        b.templateSources = {};
        
        b.templateSources.domElement = function ( a ) {
          this.domElement = a;
        };
        
        b.templateSources.domElement.prototype['text'] = function () {
          if ( arguments.length == 0 ){
            return this.domElement.tagName.toLowerCase() == "script"?this.domElement.text : this.domElement.innerHTML;
          } else {
            var a = arguments[0];
            if ( this.domElement.tagName.toLowerCase() == "script" ){
              this.domElement.text = a;
            } else {
              b.utils.setHtml( this.domElement,a );
            };
          };
        };
        
        b.templateSources.domElement.prototype['data'] = function ( a ) {
          if ( arguments.length === 1 ){
            return b.utils.domData.get( this.domElement,"templateSourceData_"+a );
          } else {
            b.utils.domData.set( this.domElement,"templateSourceData_"+a,arguments[1] );
          };
        };
        
        var a = "__ko_anon_template__";
        
        b.templateSources.anonymousTemplate = function ( a ) {
          this.domElement = a;
        };
        
        b.templateSources.anonymousTemplate.prototype = new b.templateSources.domElement();
        
        b.templateSources.anonymousTemplate.prototype['text'] = function () {
          if ( arguments.length == 0 ){
            return b.utils.domData.get( this.domElement,a );
          } else {
            var c = arguments[0];
            
            b.utils.domData.set( this.domElement,a,c );
          };
        };
        
        b.exportSymbol( 'ko.templateSources',b.templateSources );
        
        b.exportSymbol( 'ko.templateSources.domElement',b.templateSources.domElement );
        
        b.exportSymbol( 'ko.templateSources.anonymousTemplate',b.templateSources.anonymousTemplate );
      }();
      
      !function () {
        var a;
        
        b.setTemplateEngine = function ( c ) {
          if ( ( c != undefined ) && !( c instanceof b.templateEngine ) ){
            throw "templateEngine must inherit from ko.templateEngine";
          };
          
          a = c;
        };
        
        function c( a,b,c ) {
          for ( var d = 0;node = a[d];d ++  ){
            if ( node.parentNode !== b ){
              continue ;
            };
            
            if ( ( node.nodeType === 1 ) || ( node.nodeType === 8 ) ){
              c( node );
            };
          };
        }
        b.activateBindingsOnTemplateRenderedNodes = function ( d,a ) {
          var e = b.utils.arrayPushAll( [],d );
          
          var f = ( d.length>0 )?d[0].parentNode : null;
          
          c( e,f,
          function ( c ) {
            b.applyBindings( a,c );
          });
          
          c( e,f,
          function ( c ) {
            b.memoization.unmemoizeDomNodeAndDescendants( c,[a] );
          });
        };
        
        function d( a ) {
          return a.nodeType?a : a.length>0?a[0] : null;
        }
        function e( c,d,e,f,g ) {
          g = g || {};
          
          var h = ( g['templateEngine'] || a );
          
          b.templateRewriting.ensureTemplateIsRewritten( e,h );
          
          var i = h['renderTemplate']( e,f,g );
          
          if ( ( typeof i.length != "number" ) || ( i.length>0 && typeof i[0].nodeType != "number" ) ){
            throw "Template engine must return an array of DOM nodes";
          };
          
          var j = false;
          
          switch ( d ) {
            case "replaceChildren" :
              
              b.virtualElements.setDomNodeChildren( c,i );
              
              j = true;
              break;
            case "replaceNode" :
              
              b.utils.replaceDomNodes( c,i );
              
              j = true;
              break;
            case "ignoreTargetNode" :
              break;
            default :
              throw new Error( "Unknown renderMode: "+d );
              
          };
          
          if ( j ){
            b.activateBindingsOnTemplateRenderedNodes( i,f );
            
            if ( g['afterRender'] ){
              g['afterRender']( i,f['$data'] );
            };
          };
          return i;
        }
        b.renderTemplate = function ( g,f,j,h,i ) {
          j = j || {};
          
          if ( ( j['templateEngine'] || a ) == undefined ){
            throw "Set a template engine before calling renderTemplate";
          };
          
          i = i || "replaceChildren";
          
          if ( h ){
            var c = d( h );
            
            var k = function () {
                  return ( !c ) || !b.utils.domNodeIsAttachedToDocument( c );
                };
            
            var l = ( c && i == "replaceNode" )?c.parentNode : c;
            return new b.dependentObservable( function () {
              var k = ( f && ( f instanceof b.bindingContext ) )?f : new b.bindingContext( b.utils.unwrapObservable( f ) );
              
              var l = typeof ( g ) == 'function'?g( k['$data'] ) : g;
              
              var m = e( h,i,l,k,j );
              
              if ( i == "replaceNode" ){
                h = m;
                
                c = d( h );
              };
            },null, {
              'disposeWhen' : k,
              'disposeWhenNodeIsRemoved' : l
            });
          } else {
            return b.memoization.memoize( function ( a ) {
              b.renderTemplate( g,f,j,a,"replaceNode" );
            });
          };
        };
        
        b.renderTemplateForEach = function ( i,f,d,g,a ) {
          var c = function ( c ) {
                return a['createChildContext']( b.utils.unwrapObservable( c ) );
              };
          
          var h = function ( e,f ) {
                var g = c( e );
                
                b.activateBindingsOnTemplateRenderedNodes( f,g );
                
                if ( d['afterRender'] ){
                  d['afterRender']( f,g['$data'] );
                };
              };
          return new b.dependentObservable( function () {
            var j = b.utils.unwrapObservable( f ) || [];
            
            if ( typeof j.length == "undefined" ){
              j = [j];
            };
            
            var k = b.utils.arrayFilter( j,
                function ( a ) {
                  return d['includeDestroyed'] || a === undefined || a === null || !b.utils.unwrapObservable( a['_destroy'] );
                });
            
            b.utils.setDomNodeChildrenFromArrayMapping( g,k,
            function ( a ) {
              var b = typeof ( i ) == 'function'?i( a ) : i;
              return e( null,"ignoreTargetNode",b,c( a ),d );
            },d,h);
          },null, {
            'disposeWhenNodeIsRemoved' : g
          });
        };
        
        var f = '__ko__templateSubscriptionDomDataKey__';
        
        function g( g,h ) {
          var i = b.utils.domData.get( g,f );
          
          if ( i && ( typeof ( i.dispose ) == 'function' ) ){
            i.dispose();
          };
          
          b.utils.domData.set( g,f,h );
        }
        b.bindingHandlers['template'] =  {
          'init' : function ( a,c ) {
            var d = b.utils.unwrapObservable( c() );
            
            if ( ( typeof d != "string" ) && ( !d.name ) && ( a.nodeType == 1 ) ){
              new b.templateSources.anonymousTemplate( a ).text( a.innerHTML );
              
              b.utils.emptyDomNode( a );
            };
            return  {
              'controlsDescendantBindings' : true
            };
          },
          'update' : function ( h,i,j,k,l ) {
            var m = b.utils.unwrapObservable( i() );
            
            var n;
            
            var o = true;
            
            if ( typeof m == "string" ){
              n = m;
            } else {
              n = m.name;
              if ( 'if' in m ){
                o = o && b.utils.unwrapObservable( m['if'] );
              };
              if ( 'ifnot' in m ){
                o = o && !b.utils.unwrapObservable( m['ifnot'] );
              };
            };
            
            var p = null;
            
            if ( ( typeof m === 'object' ) && ( 'foreach' in m ) ){
              var q = ( o && m['foreach'] ) || [];
              
              p = b.renderTemplateForEach( n || h,q,m,h,l );
            } else if ( o ){
              var r = ( typeof m == 'object' ) && ( 'data' in m )?l['createChildContext']( b.utils.unwrapObservable( m['data'] ) ) : l;
              
              p = b.renderTemplate( n || h,r,m,h );
            } else {
              b.virtualElements.emptyNode( h );
            };
            
            g( h,p );
          }
        };
        
        b.jsonExpressionRewriting.bindingRewriteValidators['template'] = function ( a ) {
          var c = b.jsonExpressionRewriting.parseObjectLiteral( a );
          
          if ( ( c.length == 1 ) && c[0]['unknown'] ){
            return null;
          };
          
          if ( b.jsonExpressionRewriting.keyValueArrayContainsKey( c,"name" ) ){
            return null;
          };
          return "This template engine does not support anonymous templates nested within its templates";
        };
        
        b.virtualElements.allowedBindings['template'] = true;
      }();
      
      b.exportSymbol( 'ko.setTemplateEngine',b.setTemplateEngine );
      
      b.exportSymbol( 'ko.renderTemplate',b.renderTemplate );
      
      !function () {
        function a( a,b,c ) {
          var d = [];
          
          for ( var e = 0;e <= b.length;e ++  )
          d[e] = [];
          
          for ( var e = 0,f = Math.min( a.length,c );e <= f;e ++  )
          d[0][e] = e;
          
          for ( var e = 1,f = Math.min( b.length,c );e <= f;e ++  )
          d[e][0] = e;
          
          var g,
              h = a.length,
              i,
              j = b.length;
          
          var k,
              l;
          
          for ( g = 1;g <= h;g ++  ){
            var m = Math.max( 1,g-c );
            
            var n = Math.min( j,g+c );
            
            for ( i = m;i <= n;i ++  )if ( a[g-1] === b[i-1] ){
              d[i][g] = d[i-1][g-1];
            } else {
              var o = d[i-1][g] === undefined?Number.MAX_VALUE : d[i-1][g]+1;
              
              var p = d[i][g-1] === undefined?Number.MAX_VALUE : d[i][g-1]+1;
              
              d[i][g] = Math.min( o,p );
            };
          };
          return d;
        }
        function c( a,b,c ) {
          var d = b.length;
          
          var e = c.length;
          
          var f = [];
          
          var g = a[e][d];
          
          if ( g === undefined ){
            return null;
          };
          
          while ( ( d>0 ) || ( e>0 ) ){
            var h = a[e][d];
            
            var i = ( e>0 )?a[e-1][d] : g+1;
            
            var j = ( d>0 )?a[e][d-1] : g+1;
            
            var k = ( e>0 ) && ( d>0 )?a[e-1][d-1] : g+1;
            
            if ( ( i === undefined ) || ( i<h-1 ) ){
              i = g+1;
            };
            
            if ( ( j === undefined ) || ( j<h-1 ) ){
              j = g+1;
            };
            
            if ( k<h-1 ){
              k = g+1;
            };
            
            if ( ( i <= j ) && ( i<k ) ){
              f.push(  {
                status : "added",
                value : c[e-1]
              });
              
              e -- ;
            } else if ( ( j<i ) && ( j<k ) ){
              f.push(  {
                status : "deleted",
                value : b[d-1]
              });
              
              d -- ;
            } else {
              f.push(  {
                status : "retained",
                value : b[d-1]
              });
              
              e -- ;
              
              d -- ;
            };
          };
          return f.reverse();
        }
        b.utils.compareArrays = function ( d,e,f ) {
          if ( f === undefined ){
            return b.utils.compareArrays( d,e,1 ) || b.utils.compareArrays( d,e,10 ) || b.utils.compareArrays( d,e,Number.MAX_VALUE );
          } else {
            d = d || [];
            
            e = e || [];
            
            var g = a( d,e,f );
            return c( g,d,e );
          };
        };
      }();
      
      b.exportSymbol( 'ko.utils.compareArrays',b.utils.compareArrays );
      
      !function () {
        function a( a ) {
          if ( a.length>2 ){
            var b = a[0],
                c = a[a.length-1],
                d = [b];
            
            while ( b !== c ){
              b = b.nextSibling;
              
              if ( !b ){
                return ;
              };
              
              d.push( b );
            };
            
            Array.prototype.splice.apply( a,[0,a.length].concat( d ) );
          };
        }
        function d( g,c,d,f ) {
          var e = [];
          
          var h = b.dependentObservable( function () {
                var g = c( d ) || [];
                
                if ( e.length>0 ){
                  a( e );
                  
                  b.utils.replaceDomNodes( e,g );
                  
                  if ( f ){
                    f( d,g );
                  };
                };
                
                e.splice( 0,e.length );
                
                b.utils.arrayPushAll( e,g );
              },null, {
                'disposeWhenNodeIsRemoved' : g,
                'disposeWhen' : function () {
                  return ( e.length == 0 ) || !b.utils.domNodeIsAttachedToDocument( e[0] );
                }
              });
          return  {
            mappedNodes : e,
            dependentObservable : h
          };
        }
        var c = "setDomNodeChildrenFromArrayMapping_lastMappingResult";
        
        b.utils.setDomNodeChildrenFromArrayMapping = function ( i,j,k,l,m ) {
          j = j || [];
          
          l = l || {};
          
          var n = b.utils.domData.get( i,c ) === undefined;
          
          var o = b.utils.domData.get( i,c ) || [];
          
          var p = b.utils.arrayMap( o,
              function ( a ) {
                return a.arrayEntry;
              });
          
          var g = b.utils.compareArrays( p,j );
          
          var q = [];
          
          var r = 0;
          
          var e = [];
          
          var s = [];
          
          var h = null;
          
          for ( var f = 0,t = g.length;f<t;f ++  )
          switch ( g[f].status ) {
            case "retained" :
              
              var u = o[r];
              
              q.push( u );
              
              if ( u.domNodes.length>0 ){
                h = u.domNodes[u.domNodes.length-1];
              };
              
              r ++ ;
              break;
            case "deleted" :
              
              o[r].dependentObservable.dispose();
              
              a( o[r].domNodes );
              
              b.utils.arrayForEach( o[r].domNodes,
              function ( i ) {
                e.push(  {
                  element : i,
                  index : f,
                  value : g[f].value
                });
                
                h = i;
              });
              
              r ++ ;
              break;
            case "added" :
              
              var v = g[f].value;
              
              var w = d( i,k,v,m );
              
              var x = w.mappedNodes;
              
              q.push(  {
                arrayEntry : g[f].value,
                domNodes : x,
                dependentObservable : w.dependentObservable
              });
              
              for ( var y = 0,z = x.length;y<z;y ++  ){
                var A = x[y];
                
                s.push(  {
                  element : A,
                  index : f,
                  value : g[f].value
                });
                
                if ( h == null ){
                  b.virtualElements.prepend( i,A );
                } else {
                  b.virtualElements.insertAfter( i,A,h );
                };
                
                h = A;
              };
              
              if ( m ){
                m( v,x );
              };
              break;
              
          };
          
          b.utils.arrayForEach( e,
          function ( a ) {
            b.cleanNode( a.element );
          });
          
          var B = false;
          
          if ( !n ){
            if ( l['afterAdd'] ){
              for ( var f = 0;f<s.length;f ++  )
              l['afterAdd']( s[f].element,s[f].index,s[f].value );
            };
            
            if ( l['beforeRemove'] ){
              for ( var f = 0;f<e.length;f ++  )
              l['beforeRemove']( e[f].element,e[f].index,e[f].value );
              
              B = true;
            };
          };
          
          if ( !B ){
            b.utils.arrayForEach( e,
            function ( a ) {
              b.removeNode( a.element );
            });
          };
          
          b.utils.domData.set( i,c,q );
        };
      }();
      
      b.exportSymbol( 'ko.utils.setDomNodeChildrenFromArrayMapping',b.utils.setDomNodeChildrenFromArrayMapping );
      
      b.nativeTemplateEngine = function () {
        this['allowTemplateRewriting'] = false;
      };
      
      b.nativeTemplateEngine.prototype = new b.templateEngine();
      
      b.nativeTemplateEngine.prototype['renderTemplateSource'] = function ( a,c,d ) {
        var e = a.text();
        return b.utils.parseHtmlFragment( e );
      };
      
      b.nativeTemplateEngine.instance = new b.nativeTemplateEngine();
      
      b.setTemplateEngine( b.nativeTemplateEngine.instance );
      
      b.exportSymbol( 'ko.nativeTemplateEngine',b.nativeTemplateEngine );
      
      !function () {
        b.jqueryTmplTemplateEngine = function () {
          var a = this.jQueryTmplVersion = function () {
                if ( ( typeof ( jQuery ) == "undefined" ) || !( jQuery['tmpl'] ) ){
                  return 0;
                };
                
                try {
                  if ( jQuery['tmpl']['tag']['tmpl']['open'].toString().indexOf( '__' ) >= 0 ){
                    return 2;
                  };
                } catch( ex ){
                  
                };
                return 1;
              }();
          
          function b() {
            if ( a<2 ){
              throw new Error( "Your version of jQuery.tmpl is too old. Please upgrade to jQuery.tmpl 1.0.0pre or later." );
            };
          }
          function c( a,b,c ) {
            return jQuery['tmpl']( a,b,c );
          }
          this['renderTemplateSource'] = function ( d,e,f ) {
            f = f || {};
            
            b();
            
            var g = d['data']( 'precompiled' );
            
            if ( !g ){
              var h = d.text() || "";
              
              h = "{{ko_with $item.koBindingContext}}"+h+"{{/ko_with}}";
              
              g = jQuery['template']( null,h );
              
              d['data']( 'precompiled',g );
            };
            
            var i = [e['$data']];
            
            var j = jQuery['extend'](  {
                  'koBindingContext' : e
                },f['templateOptions'] );
            
            var k = c( g,i,j );
            
            k['appendTo']( document.createElement( "div" ) );
            
            jQuery['fragments'] = {};
            return k;
          };
          
          this['createJavaScriptEvaluatorBlock'] = function ( a ) {
            return "{{ko_code ((function() { return "+a+" })()) }}";
          };
          
          this['addTemplate'] = function ( a,b ) {
            document.write( "<script type='text/html' id='"+a+"'>"+b+"</script>" );
          };
          
          if ( a>0 ){
            jQuery['tmpl']['tag']['ko_code'] =  {
              open : "__.push($1 || '');"
            };
            
            jQuery['tmpl']['tag']['ko_with'] =  {
              open : "with($1) {",
              close : "} "
            };
          };
        };
        
        b.jqueryTmplTemplateEngine.prototype = new b.templateEngine();
        
        var a = new b.jqueryTmplTemplateEngine();
        
        if ( a.jQueryTmplVersion>0 ){
          b.setTemplateEngine( a );
        };
        
        b.exportSymbol( 'ko.jqueryTmplTemplateEngine',b.jqueryTmplTemplateEngine );
      }();
    }( window );
  }();
}();
