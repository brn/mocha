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
      var __FILE__ = "/var/samba/mocha/src/test/js/path_array-cmp.js",
          __LINE__ = 0;
      __LINE__ = 2;
      _mochaGlobalExport['./path_array-cmp.js'] = {};
      
      __LINE__ = 3;
      var _mochaGlobalAlias = _mochaGlobalExport['./path_array-cmp.js'];
      
      __LINE__ = 1;
      ( function () {
        try {
          __LINE__ = 2;
          var __FILE__ = "Runtime",
              __LINE__ = 0;
          
          __LINE__ = 5;
          var _mochaGlobalExport = {},
              _mochaClassTable = {};
          
          __LINE__ = 8;
          var Runtime = ( function Runtime() {
                try {
                  __LINE__ = 9;
                  var _mochaLocalExport = {};
                  
                  function Exception( line,file,e ) {
                    try {
                      __LINE__ = 12;
                      this.toString = function () {
                        try {
                          __LINE__ = 13;
                          return Runtime.getErrorMessage( e )+" in file "+file+" at : "+line;
                        } catch( e ){
                          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      };
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  }
                  __LINE__ = 16;
                  var Runtime =  {
                        getErrorMessage : function getErrorMessage( e ) {
                          try {
                            __LINE__ = 18;
                            return ( ( ( e.message ) ) )?e.message : ( ( ( e.description ) ) )?e.description : e.toString();
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        },
                        exceptionHandler : function exceptionHandler( line,file,e ) {
                          try {
                            __LINE__ = 21;
                            this.throwException( new Exception( line,file,e ) );
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        },
                        throwException : function throwException( exception ) {
                          try {
                            try {
                              __LINE__ = 25;
                              throw exception;
                            } catch( e ){
                              __LINE__ = 27;
                              throw new Error( this.getErrorMessage( e ) );
                            };
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        }
                      };
                  
                  __LINE__ = 32;
                  if ( !String.prototype.trim ){
                    __LINE__ = 33;
                    String.prototype.trim = function () {
                      try {
                        __LINE__ = 34;
                        return this.replace( String.prototype.trim.rtrim,"" );
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    };
                    
                    __LINE__ = 37;
                    String.prototype.trim.rtrim = /^\s*|\s*$/g;
                  };
                  
                  __LINE__ = 40;
                  if ( !Function.prototype.bind ){
                    __LINE__ = 41;
                    Function.prototype.bind = function () {
                      try {
                        __LINE__ = 42;
                        var argArray = Array.prototype.slice.call( arguments ),
                            context = argArray.shift(),
                            ret = function () {
                              try {
                                __LINE__ = 45;
                                var args = argArray.concat( Array.prototype.slice.call( arguments ) );
                                
                                __LINE__ = 47;
                                if ( this instanceof ret ){
                                  __LINE__ = 48;
                                  return ret.context.apply( this,args );
                                } else {
                                  __LINE__ = 50;
                                  return ret.context.apply( context,args );
                                };
                              } catch( e ){
                                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                              }
                            };
                        
                        __LINE__ = 54;
                        ret.prototype = this.prototype;
                        
                        __LINE__ = 56;
                        ret.context = this;
                        __LINE__ = 57;
                        return ret;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    };
                  };
                  
                  __LINE__ = 61;
                  if ( !Array.prototype.forEach ){
                    __LINE__ = 62;
                    Array.prototype.forEach = function ( fn,that ) {
                      try {
                        __LINE__ = 63;
                        var iter = -1,
                            ta;
                        
                        __LINE__ = 66;
                        if ( that ){
                          __LINE__ = 67;
                          while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                            __LINE__ = 68;
                            fn.call( that,ta,iter,this );
                          };
                        } else {
                          __LINE__ = 71;
                          while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                            __LINE__ = 72;
                            fn( ta,iter,this );
                          };
                        };
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    };
                  };
                  
                  __LINE__ = 78;
                  if ( !Array.prototype.every ){
                    __LINE__ = 79;
                    Array.prototype.every = function ( fn,that ) {
                      try {
                        __LINE__ = 80;
                        var iter = -1,
                            ta;
                        
                        __LINE__ = 83;
                        if ( that ){
                          __LINE__ = 84;
                          while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                            __LINE__ = 85;
                            if ( !( fn.call( that,ta,iter,this ) ) ){
                              __LINE__ = 86;
                              return false;
                            };
                          };
                        } else {
                          __LINE__ = 90;
                          while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                            if ( !( fn( ta,iter,this ) ) ){
                              __LINE__ = 92;
                              return false;
                            };
                          };
                        };
                        __LINE__ = 96;
                        return true;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    };
                  };
                  
                  __LINE__ = 100;
                  if ( !Array.prototype.some ){
                    __LINE__ = 101;
                    Array.prototype.some = function ( fn,that ) {
                      try {
                        __LINE__ = 102;
                        var iter = -1,
                            ta;
                        
                        __LINE__ = 105;
                        if ( that ){
                          __LINE__ = 106;
                          while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                            __LINE__ = 107;
                            if ( fn.call( that,ta,iter,this ) ){
                              __LINE__ = 108;
                              return true;
                            };
                          };
                        } else {
                          __LINE__ = 112;
                          while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                            if ( fn( ta,iter,this ) ){
                              __LINE__ = 114;
                              return true;
                            };
                          };
                        };
                        __LINE__ = 118;
                        return false;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    };
                  };
                  
                  __LINE__ = 122;
                  if ( !Array.prototype.filter ){
                    __LINE__ = 123;
                    Array.prototype.filter = function ( fn,that ) {
                      try {
                        __LINE__ = 124;
                        var iter = -1,
                            ret = [],
                            ta;
                        
                        __LINE__ = 128;
                        if ( that ){
                          __LINE__ = 129;
                          for ( var i = 0,len = this.length;i<len; ++ i ){
                            __LINE__ = 130;
                            if ( ( ta = this[i] ) !== null && ta !== undefined ){
                              __LINE__ = 131;
                              if ( fn.call( that,ta,i,this ) ){
                                __LINE__ = 132;
                                ret[ ++ iter] = ta;
                              };
                            };
                          };
                        } else {
                          __LINE__ = 137;
                          for ( var i = 0,len = this.length;i<len; ++ i ){
                            if ( ( ta = this[i] ) !== null && ta !== undefined ){
                              if ( fn( ta,i,this ) ){
                                __LINE__ = 140;
                                ret[ ++ iter] = ta;
                              };
                            };
                          };
                        };
                        __LINE__ = 145;
                        return ret;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    };
                  };
                  
                  __LINE__ = 149;
                  if ( !Array.prototype.indexOf ){
                    __LINE__ = 150;
                    Array.prototype.indexOf = function ( subject ) {
                      try {
                        __LINE__ = 151;
                        var iter = -1,
                            index = -1,
                            ta;
                        
                        __LINE__ = 155;
                        while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                          __LINE__ = 156;
                          if ( ta === subject ){
                            __LINE__ = 157;
                            index = iter;
                            __LINE__ = 158;
                            break;
                          };
                        };
                        __LINE__ = 161;
                        return index;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    };
                  };
                  
                  __LINE__ = 165;
                  if ( !Array.prototype.lastIndexOf ){
                    __LINE__ = 166;
                    Array.prototype.lastIndexOf = function ( subject ) {
                      try {
                        __LINE__ = 167;
                        var iter = this.length,
                            index = -1,
                            ta;
                        
                        __LINE__ = 171;
                        while ( ( ta = this[ -- iter] ) !== null && ta !== undefined ){
                          __LINE__ = 172;
                          if ( ta === subject ){
                            __LINE__ = 173;
                            index = iter;
                            __LINE__ = 174;
                            break;
                          };
                        };
                        __LINE__ = 177;
                        return index;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    };
                  };
                  
                  __LINE__ = 181;
                  if ( !Array.prototype.map ){
                    __LINE__ = 182;
                    Array.prototype.map = function ( fn,that ) {
                      try {
                        __LINE__ = 183;
                        var ret = [],
                            iter = -1,
                            ta;
                        
                        __LINE__ = 187;
                        if ( that ){
                          __LINE__ = 188;
                          for ( var i = 0,len = this.length;i<len; ++ i ){
                            __LINE__ = 189;
                            if ( ( ta = this[i] ) !== null && ta !== undefined ){
                              __LINE__ = 190;
                              ret[ ++ iter] = fn.call( that,ta,i,this );
                            };
                          };
                        } else {
                          __LINE__ = 194;
                          for ( var i = 0,len = this.length;i<len; ++ i ){
                            if ( ( ta = this[i] ) !== null && ta !== undefined ){
                              __LINE__ = 196;
                              ret[ ++ iter] = fn( ta,i,this );
                            };
                          };
                        };
                        __LINE__ = 200;
                        return ret;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    };
                  };
                  
                  __LINE__ = 204;
                  if ( !Array.prototype.reduce ){
                    __LINE__ = 205;
                    Array.prototype.reduce = function ( fn,initial ) {
                      try {
                        __LINE__ = 206;
                        var ret = initial || this[0],
                            i = ( ( ( initial ) ) )?0 : 1,
                            ta,
                            len;
                        
                        __LINE__ = 211;
                        for ( i , len = this.length;i<len; ++ i ){
                          __LINE__ = 212;
                          if ( ( ta = this[i] ) !== null && ta !== undefined ){
                            __LINE__ = 213;
                            ret = fn( ret,ta,i,this );
                          };
                        };
                        __LINE__ = 216;
                        return ret;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    };
                  };
                  
                  __LINE__ = 220;
                  if ( !Array.prototype.reduceRight ){
                    __LINE__ = 221;
                    Array.prototype.reduceRight = function ( fn,initial ) {
                      try {
                        __LINE__ = 222;
                        var ret = initial || this[this.length-1],
                            i = ( ( ( initial ) ) )?this.length-1 : this.length-2,
                            ta;
                        
                        __LINE__ = 226;
                        for ( i;i>-1; -- i ){
                          __LINE__ = 227;
                          if ( ( ta = this[i] ) !== null && ta !== undefined ){
                            __LINE__ = 228;
                            ret = fn( ret,ta,i,this );
                          };
                        };
                        __LINE__ = 231;
                        return ret;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    };
                  };
                  
                  __LINE__ = 235;
                  if ( !Date.prototype.toJSON ){
                    __LINE__ = 236;
                    Date.prototype.toJSON = function () {
                      try {
                        __LINE__ = 237;
                        return '"'+this.getUTCFullYear()+'-'+"0"+( this.getUTCMonth()+1 )+'-'+"0"+( this.getUTCDate()-1 )+'T'+this.getUTCHours()+':'+this.getMinutes()+':'+this.getSeconds()+'.'+this.getUTCMilliseconds()+'"';
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    };
                  };
                  
                  __LINE__ = 241;
                  if ( !Date.now ){
                    __LINE__ = 242;
                    Date.now = function () {
                      try {
                        __LINE__ = 243;
                        return +new Date();
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    };
                  };
                  
                  __LINE__ = 247;
                  if ( !Object.keys ){
                    __LINE__ = 248;
                    Object.keys = function ( obj ) {
                      try {
                        __LINE__ = 249;
                        var ret = [],
                            iter = -1;
                        
                        __LINE__ = 252;
                        for ( var i in obj ){
                          __LINE__ = 253;
                          if ( obj.hasOwnProperty( i ) ){
                            __LINE__ = 254;
                            ret[ ++ iter] = obj[i];
                          };
                        };
                        __LINE__ = 257;
                        return ret;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    };
                  };
                  
                  __LINE__ = 261;
                  if ( !Object.preventExtensions ){
                    __LINE__ = 262;
                    Object.preventExtensions = function ( o ) {
                      try {
                        __LINE__ = 263;
                        return o;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    };
                  };
                  
                  __LINE__ = 267;
                  if ( !Object.seal ){
                    __LINE__ = 268;
                    Object.seal = function ( o ) {
                      try {
                        __LINE__ = 269;
                        return o;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    };
                  };
                  
                  __LINE__ = 273;
                  if ( !Object.freeze ){
                    __LINE__ = 274;
                    Object.freeze = function ( o ) {
                      try {
                        __LINE__ = 275;
                        return o;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    };
                  };
                  
                  __LINE__ = 279;
                  var hasRealEcma5 = ( function () {
                        try {
                          try {
                            __LINE__ = 281;
                            var obj = {};
                            
                            __LINE__ = 283;
                            Object.defineProperty( obj,"test", {
                              configurable : false,
                              writable : false,
                              enumerable : false,
                              value : 0
                            });
                            
                            __LINE__ = 290;
                            obj.test = 200;
                            __LINE__ = 291;
                            return ( ( ( obj.test === 200 ) ) )?false : true;
                          } catch( e ){
                            __LINE__ = 293;
                            return false;
                          };
                        } catch( e ){
                          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      })();
                  
                  __LINE__ = 297;
                  if ( !hasRealEcma5 ){
                    __LINE__ = 298;
                    Object.defineProperty = function ( obj,prop,valobj ) {
                      try {
                        __LINE__ = 299;
                        if ( valobj.value ){
                          __LINE__ = 300;
                          obj[prop] = valobj.value;
                        };
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    };
                  };
                  
                  __LINE__ = 305;
                  if ( !Array.isArray ){
                    __LINE__ = 306;
                    var arrayString = "[object Array]";
                    
                    __LINE__ = 308;
                    Array.isArray = function ( arr ) {
                      try {
                        __LINE__ = 309;
                        if ( arguments.length === 0 ){
                          __LINE__ = 310;
                          return false;
                        };
                        __LINE__ = 312;
                        return ( ( ( arr ) ) )?Object.prototype.toString.call( arr ) === arrayString : false;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    };
                  };
                  
                  __LINE__ = 316;
                  var slice = Array.prototype.slice;
                  
                  __LINE__ = 318;
                  var createUnenumProp = _mochaLocalExport.createUnenumProp = function ( obj,prop,value ) {
                        try {
                          __LINE__ = 319;
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
                  
                  __LINE__ = 327;
                  var constant = _mochaLocalExport.constant = function ( obj,prop,value ) {
                        try {
                          __LINE__ = 328;
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
                  
                  __LINE__ = 336;
                  var toArray = _mochaLocalExport.toArray = function ( likeArray,index ) {
                        try {
                          __LINE__ = 337;
                          return ( ( ( likeArray ) ) )?slice.call( likeArray,index ) : [];
                        } catch( e ){
                          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      };
                  
                  __LINE__ = 340;
                  var Iterator = _mochaLocalExport.Iterator = function ( obj,isKeyOnly ) {
                        try {
                          __LINE__ = 341;
                          isKeyOnly = isKeyOnly || false;
                          
                          __LINE__ = 343;
                          var iter = {},
                              isArray,
                              ret,
                              index = 0;
                          
                          __LINE__ = 348;
                          if ( this instanceof Iterator ){
                            __LINE__ = 349;
                            isArray = Array.isArray( obj );
                            
                            __LINE__ = 351;
                            ret = _ownPropertyIterator( obj,isArray,isKeyOnly );
                          } else {
                            __LINE__ = 353;
                            return _userdefIterator( obj,isKeyOnly );
                          };
                          
                          __LINE__ = 356;
                          createUnenumProp( iter,"next",
                          function () {
                            try {
                              __LINE__ = 358;
                              return ret[index ++ ];
                            } catch( e ){
                              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                            }
                          });
                          __LINE__ = 360;
                          return iter;
                        } catch( e ){
                          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      };
                  
                  __LINE__ = 363;
                  var _objectIterator = function ( obj,isKeyOnly ) {
                        try {
                          __LINE__ = 364;
                          var ret = [],
                              iter = -1;
                          
                          __LINE__ = 367;
                          if ( isKeyOnly ){
                            __LINE__ = 368;
                            for ( var prop in obj ){
                              __LINE__ = 369;
                              ret[ ++ iter] = prop;
                            };
                          } else {
                            __LINE__ = 372;
                            for ( var prop in obj ){
                              __LINE__ = 373;
                              ret[ ++ iter] = [prop,obj[prop]];
                            };
                          };
                          __LINE__ = 376;
                          return ret;
                        } catch( e ){
                          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      },
                      _arrayIterator = function ( obj,isKeyOnly ) {
                        try {
                          __LINE__ = 379;
                          var ret = [];
                          
                          __LINE__ = 381;
                          if ( isKeyOnly ){
                            __LINE__ = 382;
                            for ( var i = 0,len = obj.length;i<len;i ++  ){
                              __LINE__ = 383;
                              ret[i] = i;
                            };
                          } else {
                            __LINE__ = 386;
                            for ( var i = 0,len = obj.length;i<len;i ++  ){
                              __LINE__ = 387;
                              ret[i] = [i,obj[i]];
                            };
                          };
                          __LINE__ = 390;
                          return ret;
                        } catch( e ){
                          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      },
                      _stringIterator = function ( obj,isKeyOnly ) {
                        try {
                          __LINE__ = 393;
                          var ret = [];
                          
                          __LINE__ = 395;
                          if ( isKeyOnly ){
                            __LINE__ = 396;
                            for ( var i = 0,len = obj.length;i<len;i ++  ){
                              __LINE__ = 397;
                              ret[i] = i;
                            };
                          } else {
                            __LINE__ = 400;
                            for ( var i = 0,len = obj.length;i<len;i ++  ){
                              __LINE__ = 401;
                              ret[i] = [i,obj.charAt( i )];
                            };
                          };
                          __LINE__ = 404;
                          return ret;
                        } catch( e ){
                          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      },
                      _ownPropertyIterator = function ( obj,isArray,isKeyOnly ) {
                        try {
                          __LINE__ = 407;
                          var type = typeof obj;
                          
                          __LINE__ = 409;
                          if ( type === "object" && !isArray ){
                            __LINE__ = 410;
                            return _objectIterator( obj,isKeyOnly );
                          } else if ( isArray ){
                            __LINE__ = 412;
                            return _arrayIterator( obj,isKeyOnly );
                          } else if ( type === "string" ){
                            __LINE__ = 414;
                            return _stringIterator( obj,isKeyOnly );
                          };
                        } catch( e ){
                          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      },
                      _userdefIterator = function ( obj,isKeyOnly ) {
                        try {
                          __LINE__ = 418;
                          if ( "__iterator__" in obj ){
                            __LINE__ = 419;
                            return obj.__iterator__( isKeyOnly );
                          } else {
                            __LINE__ = 421;
                            return  {
                              next : function () {
                                try {
                                  try {
                                    __LINE__ = 424;
                                    throw new StopIteration;
                                  } catch( e ){
                                    __LINE__ = 426;
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
                  
                  __LINE__ = 433;
                  var createGenerator = _mochaLocalExport.createGenerator = function ( generatorFn,closeFn,context ) {
                        try {
                          __LINE__ = 434;
                          var ret = {};
                          
                          __LINE__ = 436;
                          createUnenumProp( ret,"next",generatorFn.bind( context,false,false ) );
                          
                          __LINE__ = 438;
                          createUnenumProp( ret,"send",generatorFn.bind( context,true,false ) );
                          
                          __LINE__ = 440;
                          createUnenumProp( ret,"close",closeFn.bind( context ) );
                          
                          __LINE__ = 442;
                          createUnenumProp( ret,"__nothrowNext__",closeFn.bind( context,false,true ) );
                          
                          __LINE__ = 444;
                          createUnenumProp( ret,"toString",
                          function () {
                            try {
                              __LINE__ = 446;
                              return "[object Generator]";
                            } catch( e ){
                              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                            }
                          });
                          
                          __LINE__ = 449;
                          Object.freeze( ret );
                          __LINE__ = 450;
                          return ret;
                        } catch( e ){
                          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      };
                  
                  __LINE__ = 453;
                  var getErrorMessage = function ( e ) {
                        try {
                          __LINE__ = 454;
                          return ( ( ( e.message ) ) )?e.message : ( ( ( e.description ) ) )?e.description : e.toString();
                        } catch( e ){
                          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      };
                  
                  __LINE__ = 457;
                  var throwException = _mochaLocalExport.throwException = Runtime.throwException.bind( Runtime );
                  
                  __LINE__ = 459;
                  var exceptionHandler = _mochaLocalExport.exceptionHandler = Runtime.exceptionHandler.bind( Runtime );
                  
                  __LINE__ = 461;
                  ( function () {
                    try {
                      __LINE__ = 462;
                      var assert = _mochaLocalExport.assert = ( ( ( console && console.assert ) ) )?function ( expect,exp,str,line ) {
                            try {
                              __LINE__ = 463;
                              return console.assert( expect === exp,str+"\nat : "+line );
                            } catch( e ){
                              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                            }
                          } : function ( expect,exp,str,line ) {
                            try {
                              __LINE__ = 465;
                              if ( expect !== exp ){
                                __LINE__ = 466;
                                Runtime.throwException( "assertion failed : "+str+"\nat : "+line );
                              };
                            } catch( e ){
                              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                            }
                          };
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  })();
                  __LINE__ = 470;
                  return _mochaLocalExport;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              })();
          
          __LINE__ = 473;
          var StopIteration =  {
                toString : function toString() {
                  try {
                    __LINE__ = 475;
                    return "StopIteration";
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
              };
          
          __LINE__ = 479;
          __LINE__ = 0;
          
          __LINE__ = 480;
          ( function () {
            try {
              try {
                __LINE__ = 482;
                var __FILE__ = "/var/samba/mocha/src/test/js/path_array.js",
                    __LINE__ = 0;
                
                __LINE__ = 484;
                __LINE__ = 2;
                
                __LINE__ = 485;
                _mochaGlobalExport['./path_array.js'] = {};
                
                __LINE__ = 487;
                __LINE__ = 3;
                
                __LINE__ = 488;
                var _mochaGlobalAlias = _mochaGlobalExport['./path_array.js'];
                
                __LINE__ = 490;
                __LINE__ = 0;
                
                __LINE__ = 491;
                var m = "/Users/aono_taketoshi/mocha/test/js";
                
                __LINE__ = 493;
                __LINE__ = 0;
                
                __LINE__ = 494;
                var v = "/url/local/includes";
                
                function getPathArray( path ) {
                  try {
                    try {
                      __LINE__ = 498;
                      __LINE__ = 0;
                      
                      __LINE__ = 499;
                      if ( path[path.length-1] !== '/' ){
                        __LINE__ = 500;
                        __LINE__ = 0;
                        
                        __LINE__ = 501;
                        path += '/';
                      };
                      
                      __LINE__ = 504;
                      __LINE__ = 0;
                      
                      __LINE__ = 505;
                      var i = 0;
                      
                      __LINE__ = 507;
                      __LINE__ = 0;
                      
                      __LINE__ = 508;
                      var arr = [];
                      
                      __LINE__ = 510;
                      __LINE__ = 0;
                      
                      __LINE__ = 511;
                      var tmp = "";
                      
                      __LINE__ = 513;
                      __LINE__ = 8;
                      
                      __LINE__ = 514;
                      while ( path[i] ){
                        __LINE__ = 515;
                        __LINE__ = 0;
                        
                        __LINE__ = 516;
                        if ( path[i] == '/' ){
                          __LINE__ = 517;
                          __LINE__ = 0;
                          
                          __LINE__ = 518;
                          if ( i == 0 ){
                            __LINE__ = 519;
                            __LINE__ = 0;
                            
                            __LINE__ = 520;
                            arr.push( "/" );
                          } else {
                            __LINE__ = 522;
                            __LINE__ = 0;
                            
                            __LINE__ = 523;
                            arr.push( tmp );
                          };
                          
                          __LINE__ = 526;
                          __LINE__ = 0;
                          
                          __LINE__ = 527;
                          tmp = "";
                        } else {
                          __LINE__ = 529;
                          __LINE__ = 0;
                          
                          __LINE__ = 530;
                          tmp += path[i];
                        };
                        
                        __LINE__ = 533;
                        __LINE__ = 0;
                        
                        __LINE__ = 534;
                        i ++ ;
                      };
                      
                      __LINE__ = 536;
                      __LINE__ = 18;
                      __LINE__ = 537;
                      return arr;
                    } catch( e ){
                      __LINE__ = 539;
                      Runtime.exceptionHandler( __LINE__,__FILE__,e );
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
                __LINE__ = 542;
                __LINE__ = 0;
                
                __LINE__ = 543;
                var arr1 = getPathArray( m ),
                    arr2 = getPathArray( v );
                
                function cmp( arr1,arr2 ) {
                  try {
                    try {
                      __LINE__ = 548;
                      __LINE__ = 0;
                      
                      __LINE__ = 549;
                      var ret = "";
                      
                      __LINE__ = 551;
                      __LINE__ = 0;
                      
                      __LINE__ = 552;
                      var i = 0;
                      
                      __LINE__ = 554;
                      __LINE__ = 0;
                      
                      __LINE__ = 555;
                      var unmatch = false;
                      
                      __LINE__ = 557;
                      __LINE__ = 27;
                      
                      __LINE__ = 558;
                      while ( arr1[i] || arr2[i] ){
                        __LINE__ = 559;
                        __LINE__ = 0;
                        
                        __LINE__ = 560;
                        if ( !arr1[i] ){
                          __LINE__ = 561;
                          __LINE__ = 0;
                          
                          __LINE__ = 562;
                          ret += arr2[i]+"/";
                        } else if ( !arr2[i] ){
                          __LINE__ = 564;
                          __LINE__ = 0;
                          
                          __LINE__ = 565;
                          var tmp = "";
                          
                          __LINE__ = 567;
                          __LINE__ = 32;
                          
                          __LINE__ = 568;
                          while ( arr1[i] ){
                            __LINE__ = 569;
                            __LINE__ = 0;
                            
                            __LINE__ = 570;
                            tmp += "../";
                            
                            __LINE__ = 572;
                            __LINE__ = 0;
                            
                            __LINE__ = 573;
                            i ++ ;
                          };
                          
                          __LINE__ = 575;
                          __LINE__ = 36;
                          __LINE__ = 576;
                          return tmp+ret;
                        } else if ( arr1[i] != arr2[i] ){
                          __LINE__ = 578;
                          __LINE__ = 0;
                          
                          __LINE__ = 579;
                          unmatch = true;
                          
                          __LINE__ = 581;
                          __LINE__ = 39;
                          
                          __LINE__ = 582;
                          while ( arr1[i] ){
                            __LINE__ = 583;
                            __LINE__ = 0;
                            
                            __LINE__ = 584;
                            ret += "../";
                            
                            __LINE__ = 586;
                            __LINE__ = 0;
                            
                            __LINE__ = 587;
                            arr1.pop();
                          };
                          
                          __LINE__ = 590;
                          __LINE__ = 43;
                          
                          __LINE__ = 591;
                          while ( arr2[i] ){
                            __LINE__ = 592;
                            __LINE__ = 0;
                            
                            __LINE__ = 593;
                            ret += arr2[i]+"/";
                            
                            __LINE__ = 595;
                            __LINE__ = 0;
                            
                            __LINE__ = 596;
                            i ++ ;
                          };
                          
                          __LINE__ = 598;
                          __LINE__ = 47;
                          __LINE__ = 599;
                          return ret;
                        };
                        
                        __LINE__ = 602;
                        __LINE__ = 0;
                        
                        __LINE__ = 603;
                        i ++ ;
                      };
                      
                      __LINE__ = 605;
                      __LINE__ = 51;
                      __LINE__ = 606;
                      return ret;
                    } catch( e ){
                      __LINE__ = 608;
                      Runtime.exceptionHandler( __LINE__,__FILE__,e );
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
                __LINE__ = 611;
                __LINE__ = 0;
                
                __LINE__ = 612;
                cmp( arr1,arr2 );
              } catch( e ){
                __LINE__ = 614;
                Runtime.exceptionHandler( __LINE__,__FILE__,e );
              };
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })();
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      })();
    } catch( e ){
      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  })();
})();
