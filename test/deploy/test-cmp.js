(function() {
  this.x = 0;
  var v = {},
      w = {},
      x = {},
      y = ( +(new Date) );
  var f = ( function f() {
        var m = {};
        if ( !String.prototype.trim ){
          String.prototype.trim = function () {
            return this.replace( String.prototype.trim.rtrim,"" );
          };
          String.prototype.trim.rtrim = /^\s*|\s*$/g;
        };
        if ( !Function.prototype.bind ){
          Function.prototype.bind = function () {
            var a = Array.prototype.slice.call( arguments ),
                e = a.shift(),
                d = function () {
                  var f = a.concat( Array.prototype.slice.call( arguments ) );
                  if ( this instanceof d ){
                    return d.context.apply( this,f );
                  } else {
                    return d.context.apply( e,f );
                    
                  }
                  
                };
            d.prototype = this.prototype;
            d.context = this;
            return d;
          };
        };
        if ( !Array.prototype.forEach ){
          Array.prototype.forEach = function ( b,c ) {
            var d = -1,
                e;
            if ( c ){
              while ( ( e = this[ ++ d] ) !== null && e !== undefined ){
                b.call( c,e,d,this );
              };
            } else {
              while ( ( e = this[ ++ d] ) !== null && e !== undefined ){
                b( e,d,this );
              };
              
            }
            
          };
        };
        if ( !Array.prototype.every ){
          Array.prototype.every = function ( b,c ) {
            var d = -1,
                e;
            if ( c ){
              while ( ( e = this[ ++ d] ) !== null && e !== undefined ){
                if ( !( b.call( c,e,d,this ) ) ){
                  return false;
                };
              };
            } else {
              while ( ( e = this[ ++ d] ) !== null && e !== undefined ){
                if ( !( b( e,d,this ) ) ){
                  return false;
                };
              };
              
            }
            return true;
          };
        };
        if ( !Array.prototype.some ){
          Array.prototype.some = function ( b,c ) {
            var d = -1,
                e;
            if ( c ){
              while ( ( e = this[ ++ d] ) !== null && e !== undefined ){
                if ( b.call( c,e,d,this ) ){
                  return true;
                };
              };
            } else {
              while ( ( e = this[ ++ d] ) !== null && e !== undefined ){
                if ( b( e,d,this ) ){
                  return true;
                };
              };
              
            }
            return false;
          };
        };
        if ( !Array.prototype.filter ){
          Array.prototype.filter = function ( c,d ) {
            var e = -1,
                f = [],
                g;
            if ( d ){
              for ( var i = 0,len = this.length;i<len; ++ i ){
                if ( ( g = this[i] ) !== null && g !== undefined ){
                  if ( c.call( d,g,i,this ) ){
                    f[ ++ e] = g;
                  };
                };
              };
            } else {
              for ( var i = 0,len = this.length;i<len; ++ i ){
                if ( ( g = this[i] ) !== null && g !== undefined ){
                  if ( c( g,i,this ) ){
                    f[ ++ e] = g;
                  };
                };
              };
              
            }
            return f;
          };
        };
        if ( !Array.prototype.indexOf ){
          Array.prototype.indexOf = function ( b ) {
            var c = -1,
                d = -1,
                e;
            while ( ( e = this[ ++ c] ) !== null && e !== undefined ){
              if ( e === b ){
                d = c;
                break;
              };
            };
            return d;
          };
        };
        if ( !Array.prototype.lastIndexOf ){
          Array.prototype.lastIndexOf = function ( b ) {
            var c = this.length,
                d = -1,
                e;
            while ( ( e = this[ -- c] ) !== null && e !== undefined ){
              if ( e === b ){
                d = c;
                break;
              };
            };
            return d;
          };
        };
        if ( !Array.prototype.map ){
          Array.prototype.map = function ( c,d ) {
            var e = [],
                f = -1,
                g;
            if ( d ){
              for ( var i = 0,len = this.length;i<len; ++ i ){
                if ( ( g = this[i] ) !== null && g !== undefined ){
                  e[ ++ f] = c.call( d,g,i,this );
                };
              };
            } else {
              for ( var i = 0,len = this.length;i<len; ++ i ){
                if ( ( g = this[i] ) !== null && g !== undefined ){
                  e[ ++ f] = c( g,i,this );
                };
              };
              
            }
            return e;
          };
        };
        if ( !Array.prototype.reduce ){
          Array.prototype.reduce = function ( b,c ) {
            var d = c || this[0],
                e = ( ( c ) )?0 : 1,
                f,
                g;
            for ( e , g = this.length;e<g; ++ e ){
              if ( ( f = this[e] ) !== null && f !== undefined ){
                d = b( d,f,e,this );
              };
            };
            return d;
          };
        };
        if ( !Array.prototype.reduceRight ){
          Array.prototype.reduceRight = function ( b,c ) {
            var d = c || this[this.length-1],
                e = ( ( c ) )?this.length-1 : this.length-2,
                f;
            for ( e;e>-1; -- e ){
              if ( ( f = this[e] ) !== null && f !== undefined ){
                d = b( d,f,e,this );
              };
            };
            return d;
          };
        };
        if ( !Date.prototype.toJSON ){
          Date.prototype.toJSON = function () {
            return '"'+this.getUTCFullYear()+'-'+"0"+( this.getUTCMonth()+1 )+'-'+"0"+( this.getUTCDate()-1 )+'T'+this.getUTCHours()+':'+this.getMinutes()+':'+this.getSeconds()+'.'+this.getUTCMilliseconds()+'"';
          };
        };
        if ( !Date.now ){
          Date.now = function () {
            return +(new Date);
          };
        };
        if ( !Object.keys ){
          Object.keys = function ( b ) {
            var c = [],
                d = -1;
            for ( var i in b ){
              if ( b.hasOwnProperty( i ) ){
                c[ ++ d] = b[i];
              };
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
        var n = ( function () {
              try {
                var c = {};
                Object.defineProperty( c,"test", {
                  configurable : false,
                  writable : false,
                  enumerable : false,
                  value : 0
                });
                c.test = 200;
                return ( ( c.test === 200 ) )?false : true;
              } catch( e ){
                return false;
              };
            })();
        if ( !n ){
          Object.defineProperty = function ( a,b,c ) {
            if ( c.value ){
              a[b] = c.value;
            };
          };
        };
        if ( !Array.isArray ){
          var c = "[object Array]";
          Array.isArray = function ( d ) {
            if ( arguments.length === 0 ){
              return false;
            };
            return ( ( d ) )?Object.prototype.toString.call( d ) === c : false;
          };
        };
        var o = {},
            a = Array.prototype.slice;
        v.createPrivateProp = function p( c,d,e,f ) {
          if ( !( c in instance_prop ) ){
            instance_prop[c] = {};
          };
          Object.defineProperty( instance_prop[c],d, {
            enumerable : true,
            configurable : f,
            writable : f,
            value : e
          });
        };
        v.getPrivateProp = function q( e,f ) {
          if ( e in _mochaInstanceProp ){
            return _mochaInstanceProp[e];
          } else {
            try {
              throw new TypeError( f+"is not defined." );
            } catch( e ){
              throw new Error( e );
            };
            
          }
          
        };
        var r = m.createUnenumProp = function ( b,c,d ) {
              return Object.defineProperty( b,c, {
                configurable : true,
                enumerable : false,
                writable : true,
                value : d
              });
            };
        var s = m.constant = function ( b,c,d ) {
              return Object.defineProp( b,c, {
                configurable : false,
                enumerable : false,
                writable : false,
                value : d
              });
            };
        var t = m.toArray = function ( b ) {
              return ( ( b ) )?a.call( b ) : [];
            };
        return m;
      })();
  ( function () {
    v['{1-302-567-849-60818395-1384-fmt.js}'] = {};
    var e = v['{1-302-567-849-60818395-1384-fmt.js}'];
    var f = function (  ) {
          var d = f.toArray( arguments,0 );
          var e = [0,1,2,3],
              f = ( e.x && e.x[0] )?e.x[0] : undefined,
              g = ( e.x )?f.toArray( e,1 ) : undefined;
        };
  })();
  ( function () {
    v['{1-302-567-849-60818395-1384-test.js}'] = {};
    var u = v['{1-302-567-849-60818395-1384-test.js}'];
    var w = v['{1-302-567-849-60818395-1384-fmt.js}'],
        x = w.x;
    ( function () {
      var v = u;
      v.Monster = ( function () {
        var c = function () {
              
            };
        function d() {
          f.createUnenumProp( this,'__private__',new c );
          d.constructor.apply( this,arguments );
        };
        f.createUnenumProp( d,'constructor',function u( f,g ) {
          this.name = f;
          var h =  {
                x : 200
              };
          f.constant( this.__private__,'name',( h.x && h.x[0] )?h.x[0] : undefined );
          f.constant( this.__private__,'age',( h.x && h.x[1] )?h.x[1] : undefined );
          f.constant( this.__private__,'hobby',( h.x && h.x[2] && h.x[2].hobby )?h.x[2].hobby : undefined );
          f.constant( this.__private__,'_tmpName',f );
        });
        d.prototype.numAttacks = 0;
        f.constant( d.prototype,'attackMessage','The monster hits you!' );
        c.prototype.v = function v() {
          return this.__private__._health>0;
        };
        c.prototype.w = function w( c ) {
          if ( c<0 ){
            throw new Error( 'Health must be non-negative.' );
          };
          this.__private__._health = c;
          return this.__private__.c+"tmpName";
        };
        c.prototype.x = function x( b ) {
          log( 'The monster attacks '+b );
        };
        f.constant( d,'constant',200 );
        var y = human;
        d.name = ( y.human && y.human.name )?y.human.name : undefined;
        d.age = ( y.human && y.human.age )?y.human.age : undefined;
        d.h1 = ( y.human && y.human.hobby && y.human.hobby[0] )?y.human.hobby[0] : undefined;
        d.h2 = ( y.human && y.human.hobby && y.human.hobby[1] )?y.human.hobby[1] : undefined;
        d.h3 = ( y.human && y.human.hobby && y.human.hobby[2] )?y.human.hobby[2] : undefined;
        var z = human_;
        d.name_ = ( z.human_ && z.human_.name_ )?z.human_.name_ : undefined;
        d.age_ = ( z.human_ && z.human_.age_ )?z.human_.age_ : undefined;
        d.h1_ = ( z.human_ && z.human_.hobby_ && z.human_.hobby_[0] )?z.human_.hobby_[0] : undefined;
        d.h2_ = ( z.human_ && z.human_.hobby_ && z.human_.hobby_[1] )?z.human_.hobby_[1] : undefined;
        d.h3_ = ( z.human_ && z.human_.hobby_ && z.human_.hobby_[2] )?z.human_.hobby_[2] : undefined;
        return d;
      })();
      var w = {},
          x = w.x,
          y = w.y,
          z = w.z;
      return v;
    })();
  })();
})();
