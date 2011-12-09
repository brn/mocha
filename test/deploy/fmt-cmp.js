(function() {
  var __global_export__ = {},
      __MC_tmp__ = undefined;
  (function() {
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
          throw new TypeError( "Array.isArray expect at least one argument." );
        };
        return ( ( arr ) )?Object.prototype.toString.call( arr ) === arrayString : false;
      };
    };
    __MC_global_alias__.ext = ( function ext() {
      var __MC_local_export__ = {};
      var Objects =  {
            extend : function ( source,dest ) {
              for ( var i in source ){
                dest[i] = source[i];
              };
            },
            each : function ( dest,fn ) {
              for ( var i in dest ){
                fn.call( dest[i],dest[i],i,dest );
              };
            }
          };
      __MC_local_export__.Objects = Objects;
      return __MC_local_export__;
    })();
  })();
  (function() {
    var __MC_local_tmp__0 = __MC_global_export__['{1-397-1092-205522212-1695-60819241-2230-ecma262-5th-compatible-devel.js}'],
        Objects = ( __MC_local_tmp__0.ext && __MC_local_tmp__0.ext.Objects )?__MC_local_tmp__0.ext.Objects : undefined;
    var __MC_local_tmp__1 = [200,2,2],
        name = ( __MC_local_tmp__1.a && __MC_local_tmp__1.a[0] && __MC_local_tmp__1.a[0].z && __MC_local_tmp__1.a[0].z[0] )?__MC_local_tmp__1.a[0].z[0] : undefined,
        test = ( __MC_local_tmp__1.a && __MC_local_tmp__1.a[0] && __MC_local_tmp__1.a[0].z && __MC_local_tmp__1.a[0].z[1] )?__MC_local_tmp__1.a[0].z[1] : undefined,
        yt = ( __MC_local_tmp__1.a && __MC_local_tmp__1.a[0] && __MC_local_tmp__1.a[0].z && __MC_local_tmp__1.a[0].z[1] )?__MC_local_tmp__1.a[0].z[1] : undefined,
        x = ( __MC_local_tmp__1.a && __MC_local_tmp__1.a[0] && __MC_local_tmp__1.a[0].z && __MC_local_tmp__1.a[0].z[2] && __MC_local_tmp__1.a[0].z[2].x )?__MC_local_tmp__1.a[0].z[2].x : undefined;
    var x = function ( __MC_local_tmp__2,__MC_local_tmp__3 ) {
          var x = __MC_local_tmp__2.x,
              z = ( __MC_local_tmp__2.g && __MC_local_tmp__2.g[0] )?__MC_local_tmp__2.g[0] : undefined,
              yg = ( __MC_local_tmp__2.g && __MC_local_tmp__2.g[1] )?__MC_local_tmp__2.g[1] : undefined,
              aaa = __MC_local_tmp__3[0],
              bbb = __MC_local_tmp__3[1],
              rest = __std.__MC_toArray__( arguments,2 );
          return x*y*z;
        };
    var __MC_local_tmp__4;
    __MC_local_tmp__4 = [100,200,300];
    ( x = __MC_local_tmp__4[0] , y = __MC_local_tmp__4[1] , z = __MC_local_tmp__4[2] );
    var m = 200;
    for ( var x in obj ){
      x = obj[x];
      console.log( x );
    };
  })();
})();
