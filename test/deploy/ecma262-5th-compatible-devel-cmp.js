(function() {
  var __global_export__ = {};
  (function() {
    if ( !String.prototype.trim ){
      String.prototype.trim = function () {
        var __tmp__ = this.replace( String.prototype.trim.rtrim,"" );
        return __tmp__;
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
        var __tmp__ = '"'+this.getUTCFullYear()+'-'+"0"+( this.getUTCMonth()+1 )+'-'+"0"+( this.getUTCDate()-1 )+'T'+this.getUTCHours()+':'+this.getMinutes()+':'+this.getSeconds()+'.'+this.getUTCMilliseconds()+'"';
        return __tmp__;
      };
    };
    if ( !Date.now ){
      Date.now = function () {
        var __tmp__ = +(new Date);
        return __tmp__;
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
        var __tmp__ = o;
        return __tmp__;
      };
    };
    if ( !Object.seal ){
      Object.seal = function ( o ) {
        var __tmp__ = o;
        return __tmp__;
      };
    };
    if ( !Object.freeze ){
      Object.freeze = function ( o ) {
        var __tmp__ = o;
        return __tmp__;
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
          throw new TypeError( "Array.isArray expect at least one argument." );
        };
        return ( ( arr ) )?Object.prototype.toString.call( arr ) === arrayString : false;
      };
    };
    __global_export__['{1-397-1092-205522212-1695-1977-60819523-2512-ecma262-5th-compatible-devel.js}'] = {};
    __global_export__['{1-397-1092-205522212-1695-1977-60819523-2512-ecma262-5th-compatible-devel.js}']['ext'] = (function () {
      var __export__ = {};
      var Objects =  {
            extend : function ( source,dest ) {
              for ( var i in source ){
                dest[i] = source[i];
              };
            }
          };
      __export__.Objects = Objects;
      return __export__;
    })();
  })();
})();
