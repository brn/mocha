(function() {
  var __global_export__ = {},
      __MC_tmp__ = undefined;
  this.x = 0;
  var _mochaGlobalExport = {},
      _mochaClassTable = {},
      _mochaInstanceTable = {},
      _mochaInstanceId = ( +(new Date) );
  var Runtime = ( function Runtime() {
        var _mochaLocalExport = {};
        if ( !String.prototype.trim ){
          String.prototype.trim = function () {
            return this.replace( String.prototype.trim.rtrim,"" );
          };
          String.prototype.trim.rtrim = /^\s*|\s*$/g;
        };
        if ( !Function.prototype.bind ){
          Function.prototype.bind = function () {
            var argArray = Array.prototype.slice.call( arguments ),
                context = argArray.shift(),
                ret = function () {
                  var args = argArray.concat( Array.prototype.slice.call( arguments ) );
                  if ( this instanceof ret ){
                    return ret.context.apply( this,args );
                  } else {
                    return ret.context.apply( context,args );
                    
                  }
                  
                };
            ret.prototype = this.prototype;
            ret.context = this;
            return ret;
          };
        };
        if ( !Array.prototype.forEach ){
          Array.prototype.forEach = function ( fn,that ) {
            var iter = -1,
                ta;
            if ( that ){
              while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                fn.call( that,ta,iter,this );
              };
            } else {
              while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                fn( ta,iter,this );
              };
              
            }
            
          };
        };
        if ( !Array.prototype.every ){
          Array.prototype.every = function ( fn,that ) {
            var iter = -1,
                ta;
            if ( that ){
              while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                if ( !( fn.call( that,ta,iter,this ) ) ){
                  return false;
                };
              };
            } else {
              while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                if ( !( fn( ta,iter,this ) ) ){
                  return false;
                };
              };
              
            }
            return true;
          };
        };
        if ( !Array.prototype.some ){
          Array.prototype.some = function ( fn,that ) {
            var iter = -1,
                ta;
            if ( that ){
              while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                if ( fn.call( that,ta,iter,this ) ){
                  return true;
                };
              };
            } else {
              while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                if ( fn( ta,iter,this ) ){
                  return true;
                };
              };
              
            }
            return false;
          };
        };
        if ( !Array.prototype.filter ){
          Array.prototype.filter = function ( fn,that ) {
            var iter = -1,
                ret = [],
                ta;
            if ( that ){
              for ( var i = 0,len = this.length;i<len; ++ i ){
                if ( ( ta = this[i] ) !== null && ta !== undefined ){
                  if ( fn.call( that,ta,i,this ) ){
                    ret[ ++ iter] = ta;
                  };
                };
              };
            } else {
              for ( var i = 0,len = this.length;i<len; ++ i ){
                if ( ( ta = this[i] ) !== null && ta !== undefined ){
                  if ( fn( ta,i,this ) ){
                    ret[ ++ iter] = ta;
                  };
                };
              };
              
            }
            return ret;
          };
        };
        if ( !Array.prototype.indexOf ){
          Array.prototype.indexOf = function ( subject ) {
            var iter = -1,
                index = -1,
                ta;
            while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
              if ( ta === subject ){
                index = iter;
                break;
              };
            };
            return index;
          };
        };
        if ( !Array.prototype.lastIndexOf ){
          Array.prototype.lastIndexOf = function ( subject ) {
            var iter = this.length,
                index = -1,
                ta;
            while ( ( ta = this[ -- iter] ) !== null && ta !== undefined ){
              if ( ta === subject ){
                index = iter;
                break;
              };
            };
            return index;
          };
        };
        if ( !Array.prototype.map ){
          Array.prototype.map = function ( fn,that ) {
            var ret = [],
                iter = -1,
                ta;
            if ( that ){
              for ( var i = 0,len = this.length;i<len; ++ i ){
                if ( ( ta = this[i] ) !== null && ta !== undefined ){
                  ret[ ++ iter] = fn.call( that,ta,i,this );
                };
              };
            } else {
              for ( var i = 0,len = this.length;i<len; ++ i ){
                if ( ( ta = this[i] ) !== null && ta !== undefined ){
                  ret[ ++ iter] = fn( ta,i,this );
                };
              };
              
            }
            return ret;
          };
        };
        if ( !Array.prototype.reduce ){
          Array.prototype.reduce = function ( fn,initial ) {
            var ret = initial || this[0],
                i = ( ( initial ) )?0 : 1,
                ta,
                len;
            for ( i , len = this.length;i<len; ++ i ){
              if ( ( ta = this[i] ) !== null && ta !== undefined ){
                ret = fn( ret,ta,i,this );
              };
            };
            return ret;
          };
        };
        if ( !Array.prototype.reduceRight ){
          Array.prototype.reduceRight = function ( fn,initial ) {
            var ret = initial || this[this.length-1],
                i = ( ( initial ) )?this.length-1 : this.length-2,
                ta;
            for ( i;i>-1; -- i ){
              if ( ( ta = this[i] ) !== null && ta !== undefined ){
                ret = fn( ret,ta,i,this );
              };
            };
            return ret;
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
          Object.keys = function ( obj ) {
            var ret = [],
                iter = -1;
            for ( var i in obj ){
              if ( obj.hasOwnProperty( i ) ){
                ret[ ++ iter] = obj[i];
              };
            };
            return ret;
          };
        };
        if ( !Object.preventExtensions ){
          Object.preventExtensions = function ( o ) {
            return o;
          };
        };
        if ( !Object.seal ){
          Object.seal = function ( o ) {
            return o;
          };
        };
        if ( !Object.freeze ){
          Object.freeze = function ( o ) {
            return o;
          };
        };
        var hasRealEcma5 = ( function () {
              try {
                var obj = {};
                Object.defineProperty( obj,"test", {
                  configurable : false,
                  writable : false,
                  enumerable : false,
                  value : 0
                });
                obj.test = 200;
                return ( ( obj.test === 200 ) )?false : true;
              } catch( e ){
                return false;
              };
            })();
        if ( !hasRealEcma5 ){
          Object.defineProperty = function ( obj,prop,valobj ) {
            if ( valobj.value ){
              obj[prop] = valobj.value;
            };
          };
        };
        if ( !Array.isArray ){
          var arrayString = "[object Array]";
          Array.isArray = function ( arr ) {
            if ( arguments.length === 0 ){
              return false;
            };
            return ( ( arr ) )?Object.prototype.toString.call( arr ) === arrayString : false;
          };
        };
        var instanceProp = {},
            slice = Array.prototype.slice;
        var createUnenumProp = _mochaLocalExport.createUnenumProp = function ( obj,prop,value ) {
              return Object.defineProperty( obj,prop, {
                configurable : true,
                enumerable : false,
                writable : true,
                value : value
              });
            };
        var constant = _mochaLocalExport.constant = function ( obj,prop,value ) {
              return Object.defineProperty( obj,prop, {
                configurable : false,
                enumerable : false,
                writable : false,
                value : value
              });
            };
        var toArray = _mochaLocalExport.toArray = function ( likeArray ) {
              return ( ( likeArray ) )?slice.call( likeArray ) : [];
            };
        return _mochaLocalExport;
      })();
  ( function () {
    var Monster = ( function () {
          var x = 0;
          var _MochaPrivateHolder = function () {
                
              };
          function Monster() {
            Runtime.createUnenumProp( this,'__private__',new _MochaPrivateHolder );
            Monster.constructor.apply( this,arguments );
          };
          Runtime.createUnenumProp( Monster,'constructor',function constructor( name,health ) {
            this.name = name;
            this.__private__._health = health;
            Runtime.constant( this.__private__,'_tmpName',name );
          });
          Monster.prototype.numAttacks = 0;
          Monster.prototype.attackMessage = 'The monster hits you!';
          _MochaPrivateHolder.prototype.isAlive = function isAlive() {
            return this._health>0;
          };
          _MochaPrivateHolder.prototype.health = function health( value ) {
            if ( value<0 ){
              throw new Error( 'Health must be non-negative.' );
            };
            this._health = value;
            return this.value+"tmpName";
          };
          _MochaPrivateHolder.prototype.attack = function attack( target ) {
            log( 'The monster attacks '+target );
          };
          return Monster;
        })();
    ;
  })();
})();
