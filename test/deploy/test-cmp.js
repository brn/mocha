(function() {
  this.x = 0;
  var j = {},
      x = {},
      y = {},
      z = ( +(new Date) );
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
            b = b || ;
            c = c || ;
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
            b = b || ;
            c = c || ;
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
            b = b || ;
            c = c || ;
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
            c = c || ;
            d = d || ;
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
            b = b || ;
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
            b = b || ;
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
            c = c || ;
            d = d || ;
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
            b = b || ;
            c = c || ;
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
            b = b || ;
            c = c || ;
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
            b = b || ;
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
            a = a || ;
            return a;
          };
        };
        if ( !Object.seal ){
          Object.seal = function ( a ) {
            a = a || ;
            return a;
          };
        };
        if ( !Object.freeze ){
          Object.freeze = function ( a ) {
            a = a || ;
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
            a = a || ;
            b = b || ;
            c = c || ;
            if ( c.value ){
              a[b] = c.value;
            };
          };
        };
        if ( !Array.isArray ){
          var c = "[object Array]";
          Array.isArray = function ( d ) {
            d = d || ;
            if ( arguments.length === 0 ){
              return false;
            };
            return ( ( d ) )?Object.prototype.toString.call( d ) === c : false;
          };
        };
        var o = {},
            a = Array.prototype.slice;
        j.createPrivateProp = function p( c,d,e,f ) {
          c = c || ;
          d = d || ;
          e = e || ;
          f = f || ;
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
        j.getPrivateProp = function q( e,f ) {
          e = e || ;
          f = f || ;
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
              b = b || ;
              c = c || ;
              d = d || ;
              return Object.defineProperty( b,c, {
                configurable : true,
                enumerable : false,
                writable : true,
                value : d
              });
            };
        var s = m.constant = function ( b,c,d ) {
              b = b || ;
              c = c || ;
              d = d || ;
              return Object.defineProp( b,c, {
                configurable : false,
                enumerable : false,
                writable : false,
                value : d
              });
            };
        var t = m.toArray = function ( b ) {
              b = b || ;
              return ( ( b ) )?a.call( b ) : [];
            };
        return m;
      })();
  ( function () {
    j['{1-302-567-849-60818395-1384-fmt.js}'] = {};
    var d = j['{1-302-567-849-60818395-1384-fmt.js}'];
    var e = function (  ) {
          var c = [0,1,2,3],
              d = ( c.x && c.x[0] )?c.x[0] : undefined,
              e = ( c.x )?f.toArray( c,1 ) : undefined;
        };
  })();
  ( function () {
    j['{1-302-567-849-60818395-1384-test.js}'] = {};
    var v = j['{1-302-567-849-60818395-1384-test.js}'];
    var l = j['{1-302-567-849-60818395-1384-fmt.js}'],
        x = l.x;
    ( function () {
      var x = v;
      x.Monster = ( function () {
        var c = function () {
              
            };
        function d() {
          f.createUnenumProp( this,'__private__',new c );
          d.constructor.apply( this,arguments );
        };
        f.extendClass( d,test["200"] );
        f.createUnenumProp( d,'constructor',function v( f,g ) {
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
        c.prototype.isAlive = function isAlive() {
          return this.__private__._health>0;
        };
        c.prototype.health = function health( c ) {
          c = c || ;
          if ( c<0 ){
            throw new Error( 'Health must be non-negative.' );
          };
          this.__private__._health = c;
          return this.__private__.c+"tmpName";
        };
        c.prototype.x = ( function () {
          var c = function () {
                
              };
          function d() {
            f.createUnenumProp( this,'__private__',new c );
            d.constructor.apply( this,arguments );
          };
          c.prototype.constructor = function constructor() {
            this.m = 200;
          };
          return d;
        })();
        c.prototype.attack = function attack( b ) {
          b = b || ;
          log( 'The monster attacks '+b );
        };
        f.constant( d,'constant',200 );
        var z = human;
        d.j = ( z.human && z.human.j )?z.human.j : undefined;
        d.l = ( z.human && z.human.l )?z.human.l : undefined;
        d.h1 = ( z.human && z.human.hobby && z.human.hobby[0] )?z.human.hobby[0] : undefined;
        d.h2 = ( z.human && z.human.hobby && z.human.hobby[1] )?z.human.hobby[1] : undefined;
        d.h3 = ( z.human && z.human.hobby && z.human.hobby[2] )?z.human.hobby[2] : undefined;
        var A = human_;
        d.name_ = ( A.human_ && A.human_.name_ )?A.human_.name_ : undefined;
        d.age_ = ( A.human_ && A.human_.age_ )?A.human_.age_ : undefined;
        d.h1_ = ( A.human_ && A.human_.hobby_ && A.human_.hobby_[0] )?A.human_.hobby_[0] : undefined;
        d.h2_ = ( A.human_ && A.human_.hobby_ && A.human_.hobby_[1] )?A.human_.hobby_[1] : undefined;
        d.h3_ = ( A.human_ && A.human_.hobby_ && A.human_.hobby_[2] )?A.human_.hobby_[2] : undefined;
        return d;
      })();
      var y = {},
          j = y.j,
          l = y.l,
          z = y.z;
      console.log( z );
      return x;
    })();
  })();
})();
