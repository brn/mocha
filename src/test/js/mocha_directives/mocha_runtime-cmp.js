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
      var __FILE__ = "/Users/aono_taketoshi/github/mocha/src/test/js/mocha_directives/mocha_runtime.js",
          __LINE__ = 0;
      __LINE__ = 2;
      _mochaGlobalExport['./mocha_runtime.js'] = {};
      
      __LINE__ = 3;
      var _mochaGlobalAlias = _mochaGlobalExport['./mocha_runtime.js'];
      
      __LINE__ = 2;
      var _mochaGlobalExport = {},
          _mochaClassTable = {};
      
      __LINE__ = 0;
      var Runtime = _mochaGlobalAlias.Runtime = ( function Runtime() {
            try {
              __LINE__ = 5;
              var _mochaLocalExport = {};
              
              __LINE__ = 7;
              if ( !String.prototype.trim ){
                __LINE__ = 0;
                String.prototype.trim = function () {
                  try {
                    __LINE__ = 8;
                    return this.replace( String.prototype.trim.rtrim,"" );
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
                
                __LINE__ = 0;
                String.prototype.trim.rtrim = /^\s*|\s*$/g;
              };
              
              __LINE__ = 12;
              if ( !Function.prototype.bind ){
                __LINE__ = 0;
                Function.prototype.bind = function () {
                  try {
                    __LINE__ = 14;
                    var argArray = Array.prototype.slice.call( arguments ),
                        context = argArray.shift(),
                        ret = function () {
                          try {
                            __LINE__ = 17;
                            var args = argArray.concat( Array.prototype.slice.call( arguments ) );
                            
                            __LINE__ = 18;
                            if ( this instanceof ret ){
                              __LINE__ = 19;
                              return ret.context.apply( this,args );
                            } else {
                              __LINE__ = 21;
                              return ret.context.apply( context,args );
                            };
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    
                    __LINE__ = 0;
                    ret.prototype = this.prototype;
                    
                    __LINE__ = 0;
                    ret.context = this;
                    __LINE__ = 26;
                    return ret;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
              };
              
              __LINE__ = 30;
              if ( !Array.prototype.forEach ){
                __LINE__ = 0;
                Array.prototype.forEach = function ( fn,that ) {
                  try {
                    __LINE__ = 32;
                    var iter = -1,
                        ta;
                    
                    __LINE__ = 34;
                    if ( that ){
                      __LINE__ = 35;
                      while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                        __LINE__ = 0;
                        fn.call( that,ta,iter,this );
                      };
                    } else {
                      __LINE__ = 39;
                      while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                        __LINE__ = 0;
                        fn( ta,iter,this );
                      };
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
              };
              
              __LINE__ = 46;
              if ( !Array.prototype.every ){
                __LINE__ = 0;
                Array.prototype.every = function ( fn,that ) {
                  try {
                    __LINE__ = 48;
                    var iter = -1,
                        ta;
                    
                    __LINE__ = 50;
                    if ( that ){
                      __LINE__ = 51;
                      while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                        __LINE__ = 52;
                        if ( !( fn.call( that,ta,iter,this ) ) ){
                          __LINE__ = 53;
                          return false;
                        };
                      };
                    } else {
                      __LINE__ = 57;
                      while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                        if ( !( fn( ta,iter,this ) ) ){
                          __LINE__ = 59;
                          return false;
                        };
                      };
                    };
                    __LINE__ = 63;
                    return true;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
              };
              
              __LINE__ = 67;
              if ( !Array.prototype.some ){
                __LINE__ = 0;
                Array.prototype.some = function ( fn,that ) {
                  try {
                    __LINE__ = 69;
                    var iter = -1,
                        ta;
                    
                    __LINE__ = 71;
                    if ( that ){
                      __LINE__ = 72;
                      while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                        __LINE__ = 73;
                        if ( fn.call( that,ta,iter,this ) ){
                          __LINE__ = 74;
                          return true;
                        };
                      };
                    } else {
                      __LINE__ = 78;
                      while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                        if ( fn( ta,iter,this ) ){
                          __LINE__ = 80;
                          return true;
                        };
                      };
                    };
                    __LINE__ = 84;
                    return false;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
              };
              
              __LINE__ = 88;
              if ( !Array.prototype.filter ){
                __LINE__ = 0;
                Array.prototype.filter = function ( fn,that ) {
                  try {
                    __LINE__ = 90;
                    var iter = -1,
                        ret = [],
                        ta;
                    
                    __LINE__ = 93;
                    if ( that ){
                      __LINE__ = 94;
                      for ( var i = 0,len = this.length;i<len; ++ i ){
                        __LINE__ = 95;
                        if ( ( ta = this[i] ) !== null && ta !== undefined ){
                          __LINE__ = 96;
                          if ( fn.call( that,ta,i,this ) ){
                            __LINE__ = 0;
                            ret[ ++ iter] = ta;
                          };
                        };
                      };
                    } else {
                      __LINE__ = 102;
                      for ( var i = 0,len = this.length;i<len; ++ i ){
                        if ( ( ta = this[i] ) !== null && ta !== undefined ){
                          if ( fn( ta,i,this ) ){
                            __LINE__ = 0;
                            ret[ ++ iter] = ta;
                          };
                        };
                      };
                    };
                    __LINE__ = 110;
                    return ret;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
              };
              
              __LINE__ = 114;
              if ( !Array.prototype.indexOf ){
                __LINE__ = 0;
                Array.prototype.indexOf = function ( subject ) {
                  try {
                    __LINE__ = 116;
                    var iter = -1,
                        index = -1,
                        ta;
                    
                    __LINE__ = 119;
                    while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                      __LINE__ = 120;
                      if ( ta === subject ){
                        __LINE__ = 0;
                        index = iter;
                        __LINE__ = 122;
                        break;
                      };
                    };
                    __LINE__ = 125;
                    return index;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
              };
              
              __LINE__ = 129;
              if ( !Array.prototype.lastIndexOf ){
                __LINE__ = 0;
                Array.prototype.lastIndexOf = function ( subject ) {
                  try {
                    __LINE__ = 131;
                    var iter = this.length,
                        index = -1,
                        ta;
                    
                    __LINE__ = 134;
                    while ( ( ta = this[ -- iter] ) !== null && ta !== undefined ){
                      __LINE__ = 135;
                      if ( ta === subject ){
                        __LINE__ = 0;
                        index = iter;
                        __LINE__ = 137;
                        break;
                      };
                    };
                    __LINE__ = 140;
                    return index;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
              };
              
              __LINE__ = 144;
              if ( !Array.prototype.map ){
                __LINE__ = 0;
                Array.prototype.map = function ( fn,that ) {
                  try {
                    __LINE__ = 146;
                    var ret = [],
                        iter = -1,
                        ta;
                    
                    __LINE__ = 149;
                    if ( that ){
                      __LINE__ = 150;
                      for ( var i = 0,len = this.length;i<len; ++ i ){
                        __LINE__ = 151;
                        if ( ( ta = this[i] ) !== null && ta !== undefined ){
                          __LINE__ = 0;
                          ret[ ++ iter] = fn.call( that,ta,i,this );
                        };
                      };
                    } else {
                      __LINE__ = 156;
                      for ( var i = 0,len = this.length;i<len; ++ i ){
                        if ( ( ta = this[i] ) !== null && ta !== undefined ){
                          __LINE__ = 0;
                          ret[ ++ iter] = fn( ta,i,this );
                        };
                      };
                    };
                    __LINE__ = 162;
                    return ret;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
              };
              
              __LINE__ = 166;
              if ( !Array.prototype.reduce ){
                __LINE__ = 0;
                Array.prototype.reduce = function ( fn,initial ) {
                  try {
                    __LINE__ = 168;
                    var ret = initial || this[0],
                        i = ( ( initial ) )?0 : 1,
                        ta,
                        len;
                    
                    __LINE__ = 172;
                    for ( i , len = this.length;i<len; ++ i ){
                      __LINE__ = 173;
                      if ( ( ta = this[i] ) !== null && ta !== undefined ){
                        __LINE__ = 0;
                        ret = fn( ret,ta,i,this );
                      };
                    };
                    __LINE__ = 177;
                    return ret;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
              };
              
              __LINE__ = 181;
              if ( !Array.prototype.reduceRight ){
                __LINE__ = 0;
                Array.prototype.reduceRight = function ( fn,initial ) {
                  try {
                    __LINE__ = 183;
                    var ret = initial || this[this.length-1],
                        i = ( ( initial ) )?this.length-1 : this.length-2,
                        ta;
                    
                    __LINE__ = 186;
                    for ( i;i>-1; -- i ){
                      __LINE__ = 187;
                      if ( ( ta = this[i] ) !== null && ta !== undefined ){
                        __LINE__ = 0;
                        ret = fn( ret,ta,i,this );
                      };
                    };
                    __LINE__ = 191;
                    return ret;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
              };
              
              __LINE__ = 195;
              if ( !Date.prototype.toJSON ){
                __LINE__ = 0;
                Date.prototype.toJSON = function () {
                  try {
                    __LINE__ = 203;
                    return '"'+this.getUTCFullYear()+'-'+"0"+( this.getUTCMonth()+1 )+'-'+"0"+( this.getUTCDate()-1 )+'T'+this.getUTCHours()+':'+this.getMinutes()+':'+this.getSeconds()+'.'+this.getUTCMilliseconds()+'"';
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
              };
              
              __LINE__ = 206;
              if ( !Date.now ){
                __LINE__ = 0;
                Date.now = function () {
                  try {
                    __LINE__ = 207;
                    return +new Date();
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
              };
              
              __LINE__ = 210;
              if ( !Object.keys ){
                __LINE__ = 0;
                Object.keys = function ( obj ) {
                  try {
                    __LINE__ = 212;
                    var ret = [],
                        iter = -1;
                    
                    __LINE__ = 215;
                    for ( var i in obj ){
                      __LINE__ = 216;
                      if ( obj.hasOwnProperty( i ) ){
                        __LINE__ = 0;
                        ret[ ++ iter] = obj[i];
                      };
                    };
                    __LINE__ = 221;
                    return ret;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
              };
              
              __LINE__ = 226;
              if ( !Object.preventExtensions ){
                __LINE__ = 0;
                Object.preventExtensions = function ( o ) {
                  try {
                    __LINE__ = 227;
                    return o;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
              };
              
              __LINE__ = 230;
              if ( !Object.seal ){
                __LINE__ = 0;
                Object.seal = function ( o ) {
                  try {
                    __LINE__ = 231;
                    return o;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
              };
              
              __LINE__ = 234;
              if ( !Object.freeze ){
                __LINE__ = 0;
                Object.freeze = function ( o ) {
                  try {
                    __LINE__ = 235;
                    return o;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
              };
              
              __LINE__ = 238;
              var hasRealEcma5 = ( function () {
                    try {
                      try {
                        __LINE__ = 240;
                        var obj = {};
                        
                        __LINE__ = 0;
                        Object.defineProperty( obj,"test", {
                          configurable : false,
                          writable : false,
                          enumerable : false,
                          value : 0
                        });
                        
                        __LINE__ = 0;
                        obj.test = 200;
                        __LINE__ = 248;
                        return ( ( obj.test === 200 ) )?false : true;
                      } catch( e ){
                        __LINE__ = 250;
                        return false;
                      };
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  })();
              
              __LINE__ = 254;
              if ( !hasRealEcma5 ){
                __LINE__ = 0;
                Object.defineProperty = function ( obj,prop,valobj ) {
                  try {
                    __LINE__ = 256;
                    if ( valobj.value ){
                      __LINE__ = 0;
                      obj[prop] = valobj.value;
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
              };
              
              __LINE__ = 262;
              if ( !Array.isArray ){
                __LINE__ = 263;
                var arrayString = "[object Array]";
                
                __LINE__ = 0;
                Array.isArray = function ( arr ) {
                  try {
                    __LINE__ = 265;
                    if ( arguments.length === 0 ){
                      __LINE__ = 266;
                      return false;
                    };
                    __LINE__ = 268;
                    return ( ( arr ) )?Object.prototype.toString.call( arr ) === arrayString : false;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
              };
              
              __LINE__ = 272;
              var slice = Array.prototype.slice;
              
              __LINE__ = 0;
              var createUnenumProp = _mochaLocalExport.createUnenumProp = function ( obj,prop,value ) {
                    try {
                      __LINE__ = 279;
                      return Object.defineProperty( obj,prop, {
                        configurable : true,
                        enumerable : false,
                        writable : true,
                        value : value
                      });
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  };
              
              __LINE__ = 0;
              var constant = _mochaLocalExport.constant = function ( obj,prop,value ) {
                    try {
                      __LINE__ = 286;
                      return Object.defineProperty( obj,prop, {
                        configurable : false,
                        enumerable : false,
                        writable : false,
                        value : value
                      });
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  };
              
              __LINE__ = 0;
              var toArray = _mochaLocalExport.toArray = function ( likeArray,index ) {
                    try {
                      __LINE__ = 288;
                      return ( ( likeArray ) )?slice.call( likeArray,index ) : [];
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  };
              
              __LINE__ = 0;
              var StopIteration = _mochaLocalExport.StopIteration =  {
                    toString : function toString() {
                      try {
                        __LINE__ = 291;
                        return "StopIteration";
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    }
                  };
              
              __LINE__ = 0;
              var Iterator = _mochaLocalExport.Iterator = function ( obj,isKeyOnly ) {
                    try {
                      __LINE__ = 0;
                      isKeyOnly = isKeyOnly || false;
                      
                      __LINE__ = 295;
                      var iter = {},
                          isArray,
                          ret,
                          index = 0;
                      
                      __LINE__ = 299;
                      if ( this instanceof Iterator ){
                        __LINE__ = 0;
                        isArray = Array.isArray( obj );
                        
                        __LINE__ = 0;
                        ret = _ownPropertyIterator( obj,isArray,isKeyOnly );
                      } else {
                        __LINE__ = 303;
                        return _userdefIterator( obj,isKeyOnly );
                      };
                      
                      __LINE__ = 0;
                      createUnenumProp( iter,"next",
                      function () {
                        try {
                          __LINE__ = 305;
                          return ret[index ++ ];
                        } catch( e ){
                          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      });
                      __LINE__ = 306;
                      return iter;
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  };
              
              __LINE__ = 309;
              var _objectIterator = function ( obj,isKeyOnly ) {
                    try {
                      __LINE__ = 310;
                      var ret = [],
                          iter = -1;
                      
                      __LINE__ = 312;
                      if ( isKeyOnly ){
                        __LINE__ = 313;
                        for ( var prop in obj ){
                          __LINE__ = 0;
                          ret[ ++ iter] = prop;
                        };
                      } else {
                        __LINE__ = 317;
                        for ( var prop in obj ){
                          __LINE__ = 0;
                          ret[ ++ iter] = [prop,obj[prop]];
                        };
                      };
                      __LINE__ = 321;
                      return ret;
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  },
                  _arrayIterator = function ( obj,isKeyOnly ) {
                    try {
                      __LINE__ = 325;
                      var ret = [];
                      
                      __LINE__ = 326;
                      if ( isKeyOnly ){
                        __LINE__ = 327;
                        for ( var i = 0,len = obj.length;i<len;i ++  ){
                          __LINE__ = 0;
                          ret[i] = i;
                        };
                      } else {
                        __LINE__ = 331;
                        for ( var i = 0,len = obj.length;i<len;i ++  ){
                          __LINE__ = 0;
                          ret[i] = [i,obj[i]];
                        };
                      };
                      __LINE__ = 335;
                      return ret;
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  },
                  _stringIterator = function ( obj,isKeyOnly ) {
                    try {
                      __LINE__ = 339;
                      var ret = [];
                      
                      __LINE__ = 340;
                      if ( isKeyOnly ){
                        __LINE__ = 341;
                        for ( var i = 0,len = obj.length;i<len;i ++  ){
                          __LINE__ = 0;
                          ret[i] = i;
                        };
                      } else {
                        __LINE__ = 345;
                        for ( var i = 0,len = obj.length;i<len;i ++  ){
                          __LINE__ = 0;
                          ret[i] = [i,obj.charAt( i )];
                        };
                      };
                      __LINE__ = 349;
                      return ret;
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  },
                  _ownPropertyIterator = function ( obj,isArray,isKeyOnly ) {
                    try {
                      __LINE__ = 353;
                      var type = typeof obj;
                      
                      __LINE__ = 354;
                      if ( type === "object" && !isArray ){
                        __LINE__ = 355;
                        return _objectIterator( obj,isKeyOnly );
                      } else if ( isArray ){
                        __LINE__ = 357;
                        return _arrayIterator( obj,isKeyOnly );
                      } else if ( type === "string" ){
                        __LINE__ = 359;
                        return _stringIterator( obj,isKeyOnly );
                      };
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  },
                  _userdefIterator = function ( obj,isKeyOnly ) {
                    try {
                      __LINE__ = 364;
                      if ( "__iterator__" in obj ){
                        __LINE__ = 365;
                        return obj.__iterator__( isKeyOnly );
                      } else {
                        __LINE__ = 367;
                        return  {
                          next : function () {
                            try {
                              try {
                                __LINE__ = 370;
                                throw new StopIteration;
                              } catch( e ){
                                __LINE__ = 372;
                                throw new Error( e );
                              };
                            } catch( e ){
                              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                            }
                          }
                        };
                      };
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  };
              
              __LINE__ = 0;
              var createGenerator = _mochaLocalExport.createGenerator = function ( generatorFn,closeFn,context ) {
                    try {
                      __LINE__ = 380;
                      var ret = {};
                      
                      __LINE__ = 0;
                      createUnenumProp( ret,"next",generatorFn.bind( context,false,false ) );
                      
                      __LINE__ = 0;
                      createUnenumProp( ret,"send",generatorFn.bind( context,true,false ) );
                      
                      __LINE__ = 0;
                      createUnenumProp( ret,"close",closeFn.bind( context ) );
                      
                      __LINE__ = 0;
                      createUnenumProp( ret,"__nothrowNext__",closeFn.bind( context,false,true ) );
                      
                      __LINE__ = 0;
                      createUnenumProp( ret,"toString",
                      function () {
                        try {
                          __LINE__ = 385;
                          return "[object Generator]";
                        } catch( e ){
                          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      });
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  };
              
              __LINE__ = 388;
              var getErrorMessage = function ( e ) {
                    try {
                      __LINE__ = 388;
                      return ( ( e.message ) )?e.message : ( ( e.description ) )?e.description : e.toString();
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  };
              
              __LINE__ = 0;
              var throwException = _mochaLocalExport.throwException = function ( exception ) {
                    try {
                      try {
                        __LINE__ = 392;
                        throw exception;
                      } catch( e ){
                        __LINE__ = 394;
                        throw new Error( getErrorMessage( e ) );
                      };
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  };
              
              function Exception( line,file,e ) {
                try {
                  __LINE__ = 0;
                  this.message = function () {
                    try {
                      __LINE__ = 400;
                      return getErrorMessage( e )+" in file "+file+" at : "+line;
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  };
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              __LINE__ = 0;
              var exceptionHandler = _mochaLocalExport.exceptionHandler = function ( line,file,e ) {
                    try {
                      __LINE__ = 0;
                      throwException( new Exception( line,file,e ) );
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  };
              __LINE__ = 0;
              return _mochaLocalExport;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })();
    } catch( e ){
      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  })();
})();
