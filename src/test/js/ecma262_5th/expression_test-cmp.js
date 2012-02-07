(function() {
  var __FILE__ = "Runtime",
      __LINE__ = 0;
  
  var _mochaGlobalExport = {},
      _mochaClassTable = {};
  
  var Runtime = ( function Runtime() {
        var _mochaLocalExport = {};
        
        function Exception( line,file,e ) {
          this.toString = function () {
            return Runtime.getErrorMessage( e )+" in file "+file+" at : "+line;
          };
        }
        var Runtime =  {
              getErrorMessage : function getErrorMessage( e ) {
                return ( ( e.message ) )?e.message : ( ( e.description ) )?e.description : e.toString();
              },
              exceptionHandler : function exceptionHandler( line,file,e ) {
                this.throwException( new Exception( line,file,e ) );
              },
              throwException : function throwException( exception ) {
                try {
                  throw exception;
                } catch( e ){
                  throw new Error( this.getErrorMessage( e ) );
                };
              }
            };
        
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
                  };
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
            };
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
            };
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
            };
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
            };
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
            };
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
            return +new Date();
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
        
        var slice = Array.prototype.slice;
        
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
        
        var toArray = _mochaLocalExport.toArray = function ( likeArray,index ) {
              return ( ( likeArray ) )?slice.call( likeArray,index ) : [];
            };
        
        var Iterator = _mochaLocalExport.Iterator = function ( obj,isKeyOnly ) {
              isKeyOnly = isKeyOnly || false;
              
              var iter = {},
                  isArray,
                  ret,
                  index = 0;
              
              if ( this instanceof Iterator ){
                isArray = Array.isArray( obj );
                
                ret = _ownPropertyIterator( obj,isArray,isKeyOnly );
              } else {
                return _userdefIterator( obj,isKeyOnly );
              };
              
              createUnenumProp( iter,"next",
              function () {
                return ret[index ++ ];
              });
              return iter;
            };
        
        var _objectIterator = function ( obj,isKeyOnly ) {
              var ret = [],
                  iter = -1;
              
              if ( isKeyOnly ){
                for ( var prop in obj ){
                  ret[ ++ iter] = prop;
                };
              } else {
                for ( var prop in obj ){
                  ret[ ++ iter] = [prop,obj[prop]];
                };
              };
              return ret;
            },
            _arrayIterator = function ( obj,isKeyOnly ) {
              var ret = [];
              
              if ( isKeyOnly ){
                for ( var i = 0,len = obj.length;i<len;i ++  ){
                  ret[i] = i;
                };
              } else {
                for ( var i = 0,len = obj.length;i<len;i ++  ){
                  ret[i] = [i,obj[i]];
                };
              };
              return ret;
            },
            _stringIterator = function ( obj,isKeyOnly ) {
              var ret = [];
              
              if ( isKeyOnly ){
                for ( var i = 0,len = obj.length;i<len;i ++  ){
                  ret[i] = i;
                };
              } else {
                for ( var i = 0,len = obj.length;i<len;i ++  ){
                  ret[i] = [i,obj.charAt( i )];
                };
              };
              return ret;
            },
            _ownPropertyIterator = function ( obj,isArray,isKeyOnly ) {
              var type = typeof obj;
              
              if ( type === "object" && !isArray ){
                return _objectIterator( obj,isKeyOnly );
              } else if ( isArray ){
                return _arrayIterator( obj,isKeyOnly );
              } else if ( type === "string" ){
                return _stringIterator( obj,isKeyOnly );
              };
            },
            _userdefIterator = function ( obj,isKeyOnly ) {
              if ( "__iterator__" in obj ){
                return obj.__iterator__( isKeyOnly );
              } else {
                return  {
                  next : function () {
                    try {
                      throw new StopIteration;
                    } catch( e ){
                      throw new Error( e );
                    };
                  }
                };
              };
            };
        
        var createGenerator = _mochaLocalExport.createGenerator = function ( generatorFn,closeFn,context ) {
              var ret = {};
              
              createUnenumProp( ret,"next",generatorFn.bind( context,false,false ) );
              
              createUnenumProp( ret,"send",generatorFn.bind( context,true,false ) );
              
              createUnenumProp( ret,"close",closeFn.bind( context ) );
              
              createUnenumProp( ret,"__nothrowNext__",closeFn.bind( context,false,true ) );
              
              createUnenumProp( ret,"toString",
              function () {
                return "[object Generator]";
              });
              
              Object.freeze( ret );
              return ret;
            };
        
        var getErrorMessage = function ( e ) {
              return ( ( e.message ) )?e.message : ( ( e.description ) )?e.description : e.toString();
            };
        
        var throwException = _mochaLocalExport.throwException = Runtime.throwException.bind( Runtime );
        
        var exceptionHandler = _mochaLocalExport.exceptionHandler = Runtime.exceptionHandler.bind( Runtime );
        
        ( function () {
          var assert = _mochaLocalExport.assert = ( ( console && console.assert ) )?function ( expect,exp,str,line ) {
                return console.assert( expect === exp,str+"\nat : "+line );
              } : function ( expect,exp,str,line ) {
                if ( expect !== exp ){
                  Runtime.throwException( "assertion failed : "+str+"\nat : "+line );
                };
              };
        })();
        return _mochaLocalExport;
      })();
  
  var StopIteration =  {
        toString : function toString() {
          return "StopIteration";
        }
      };
  
  __LINE__ = 0;
  ( function () {
    try {
      var __FILE__ = "/Users/aono_taketoshi/github/mocha/src/test/js/ecma262_5th/expression_test.js",
          __LINE__ = 0;
      __LINE__ = 2;
      _mochaGlobalExport['./expression_test.js'] = {};
      
      __LINE__ = 3;
      var _mochaGlobalAlias = _mochaGlobalExport['./expression_test.js'];
      
      __LINE__ = 0;
      document.getElementById( "id" );
      
      __LINE__ = 0;
      document.test.test2.test3();
      
      __LINE__ = 0;
      document.test.test3 = 1;
      
      __LINE__ = 0;
      Runtime.extend( document, {
        extendtest : true,
        extendtest2 : false
      });
      
      __LINE__ = 0;
      var _mochaLocalTmp0;
      
      __LINE__ = 0;
      _mochaLocalTmp0 =  {
        destructuring : 1,
        destructuring2 : 2
      };
      
      __LINE__ = 0;
      ( destructuring = _mochaLocalTmp0.destructuring , destructuring2 = _mochaLocalTmp0.destructuring2 );
      
      __LINE__ = 0;
      var _mochaLocalTmp1;
      
      __LINE__ = 0;
      _mochaLocalTmp1 =  {
        destructuring : destructuring,
        destructuring2 : destructuring2
      };
      
      __LINE__ = 0;
      ( destructuring = _mochaLocalTmp1.destructuring , destructuring2 = _mochaLocalTmp1.destructuring2 );
      
      __LINE__ = 0;
      var _mochaLocalTmp2;
      
      __LINE__ = 0;
      _mochaLocalTmp2 =  {
        destructuring : 1,
        destructuring2 : 2
      };
      
      __LINE__ = 0;
      ( destructuring = _mochaLocalTmp2.destructuring , destructuring2 = ( _mochaLocalTmp2.dsta2 && _mochaLocalTmp2.dsta2[0] )?_mochaLocalTmp2.dsta2[0] : undefined );
      
      __LINE__ = 0;
      var _mochaLocalTmp3;
      
      __LINE__ = 0;
      _mochaLocalTmp3 =  {
        destructuring : destructuring,
        destructuring2 : destructuring2
      };
      
      __LINE__ = 0;
      ( destructuring = _mochaLocalTmp3.destructuring , destructuring2 = _mochaLocalTmp3.dsta2 , dsta4 = ( _mochaLocalTmp3.dsta3 && _mochaLocalTmp3.dsta3.dsta4 )?_mochaLocalTmp3.dsta3.dsta4 : undefined );
      
      __LINE__ = 0;
      var _mochaLocalTmp4;
      
      __LINE__ = 0;
      _mochaLocalTmp4 = [0,1];
      
      __LINE__ = 0;
      ( destructuring = _mochaLocalTmp4[0] , destructuring2 = _mochaLocalTmp4[1] );
      
      __LINE__ = 0;
      var _mochaLocalTmp5;
      
      __LINE__ = 0;
      _mochaLocalTmp5 = [0,[1]];
      
      __LINE__ = 0;
      ( destructuring = _mochaLocalTmp5[0] , destructuring2 = ( _mochaLocalTmp5[1] && _mochaLocalTmp5[1][0] )?_mochaLocalTmp5[1][0] : undefined );
      
      __LINE__ = 0;
      var _mochaLocalTmp6;
      
      __LINE__ = 0;
      _mochaLocalTmp6 = [ {
        dsta : dsta
      }];
      
      __LINE__ = 0;
      ( dsta = ( _mochaLocalTmp6[0] && _mochaLocalTmp6[0].dsta )?_mochaLocalTmp6[0].dsta : undefined , a = ( _mochaLocalTmp6[0] && _mochaLocalTmp6[0].dsta2 && _mochaLocalTmp6[0].dsta2[0] )?_mochaLocalTmp6[0].dsta2[0] : undefined , dsta2 = ( _mochaLocalTmp6[1] && _mochaLocalTmp6[1].dsta2 )?_mochaLocalTmp6[1].dsta2 : undefined );
      
      __LINE__ = 0;
      var _mochaLocalTmp7;
      
      __LINE__ = 0;
      _mochaLocalTmp7 =  {
        getname : function () {
          try {
            __LINE__ = 20;
            return "aaaa";
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        },
        getage : function () {
          try {
            __LINE__ = 21;
            return "aaaaa";
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        }
      };
      
      __LINE__ = 0;
      ( getname = _mochaLocalTmp7.getname , getage = _mochaLocalTmp7.getage );
      
      __LINE__ = 0;
      var _mochaLocalTmp8;
      
      __LINE__ = 0;
      _mochaLocalTmp8 =  {
        getname : function getname() {
          try {
            __LINE__ = 24;
            return "aaaa";
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        },
        getage : function getage() {
          try {
            __LINE__ = 25;
            return "aaaaa";
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        }
      };
      
      __LINE__ = 0;
      ( getname = _mochaLocalTmp8.getname , getage = _mochaLocalTmp8.getage );
      
      __LINE__ = 0;
      var _mochaLocalTmp9;
      
      __LINE__ = 0;
      _mochaLocalTmp9 =  {
        getname : function getname() {
          try {
            __LINE__ = 28;
            return "aaaa";
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        },
        getage : function getage() {
          try {
            __LINE__ = 30;
            return "aaaaa";
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        }
      };
      
      __LINE__ = 0;
      ( getname = _mochaLocalTmp9.getname , getage = _mochaLocalTmp9.getage );
      
      __LINE__ = 0;
      var _mochaLocalTmp10;
      
      __LINE__ = 0;
      _mochaLocalTmp10 =  {
        getname : function getname() {
          try {
            __LINE__ = 33;
            return function () {
              try {
                __LINE__ = 33;
                return "aaaa";
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        },
        getage : function getage() {
          try {
            __LINE__ = 35;
            return function () {
              try {
                __LINE__ = 35;
                return "aaaaa";
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        }
      };
      
      __LINE__ = 0;
      ( getname = _mochaLocalTmp10.getname , getage = _mochaLocalTmp10.getage );
      
      __LINE__ = 37;
      var m = function () {
            try {
              __LINE__ = 37;
              return function () {
                try {
                  __LINE__ = 37;
                  return function (){};
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
      
      __LINE__ = 38;
      var m2 =  {
            m :  {
              m :  {
                m : function (){}
              }
            }
          };
      
      __LINE__ = 39;
      var m3 =  {
            m :  {
              m :  {
                m : m
              }
            }
          };
      
      __LINE__ = 40;
      var instance = new m();
      
      __LINE__ = 41;
      var instance2 = new new m();
      
      __LINE__ = 42;
      var instance3 = new new new m();
      
      __LINE__ = 43;
      var instance4 = new m2.m.m();
      
      __LINE__ = 44;
      var instance5 = new new new m3.m.m();
    } catch( e ){
      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  })();
})();
