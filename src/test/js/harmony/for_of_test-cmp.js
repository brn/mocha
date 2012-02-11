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
                return ( e.message )?e.message : ( e.description )?e.description : e.toString();
              },
              exceptionHandler : function exceptionHandler( line,file,e ) {
                if ( isStopIteration( e ) ){
                  this.throwException( e );
                } else {
                  this.throwException( new Exception( line,file,e ) );
                };
              },
              throwException : function throwException( exception ) {
                try {
                  throw exception;
                } catch( e ){
                  if ( isStopIteration( e ) ){
                    throw new Error( e );
                  } else {
                    throw new Error( this.getErrorMessage( e ) );
                  };
                };
              },
              hasProto : "__proto__" in {}
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
                  
                  if ( this !== null && this !== window && this instanceof ret ){
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
                i = ( initial )?0 : 1,
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
                i = ( initial )?this.length-1 : this.length-2,
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
                return ( obj.test === 200 )?false : true;
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
            return ( arr )?Object.prototype.toString.call( arr ) === arrayString : false;
          };
        };
        
        var slice = Array.prototype.slice;
        
        var createUnenumProp = _mochaLocalExport.createUnenumProp = function createUnenumProp( obj,prop,value ) {
              return Object.defineProperty( obj,prop, {
                configurable : true,
                enumerable : false,
                writable : true,
                value : value
              });
            };
        
        var constant = _mochaLocalExport.constant = function constant( obj,prop,value ) {
              return Object.defineProperty( obj,prop, {
                configurable : false,
                enumerable : false,
                writable : false,
                value : value
              });
            };
        
        var toArray = _mochaLocalExport.toArray = function toArray( likeArray,index ) {
              return ( likeArray )?slice.call( likeArray,index ) : [];
            };
        
        var Generator = function (){};
        
        var createGenerator = _mochaLocalExport.createGenerator = function createGenerator( generatorFn,closeFn,context ) {
              var ret = new Generator;
              
              createUnenumProp( ret,"next",generatorFn.bind( context,false,false ) );
              
              createUnenumProp( ret,"send",generatorFn.bind( context,true,false ) );
              
              createUnenumProp( ret,"close",closeFn.bind( context ) );
              
              createUnenumProp( ret,"__nothrowNext__",generatorFn.bind( context,false,true ) );
              
              createUnenumProp( ret,"toString",
              function () {
                return "[object Generator]";
              });
              
              Object.freeze( ret );
              return ret;
            };
        
        function getErrorMessage( e ) {
          return ( e.message )?e.message : ( e.description )?e.description : e.toString();
        }
        var throwException = _mochaLocalExport.throwException = Runtime.throwException.bind( Runtime );
        
        var exceptionHandler = _mochaLocalExport.exceptionHandler = Runtime.exceptionHandler.bind( Runtime );
        
        var extendPrototype = _mochaLocalExport.extendPrototype = function ( derived,base ) {
              derived.prototype = base;
            };
        
        var getPrototype = ( "getPrototypeOf" in Object )?function ( obj ) {
              return Object.getPrototypeOf( obj );
            } : function ( obj ) {
              if ( "constructor" in obj ){
                return obj.constructor.prototype || {};
              };
            };
        
        var extendClass = _mochaLocalExport.extendClass = ( Runtime.hasProto )?function ( derived,base ) {
              if ( typeof base === 'function' ){
                derived.prototype.__proto__ = base.prototype;
              } else {
                derived.prototype.__proto__ = base.__proto__;
              };
            } : function ( derived,base ) {
              var baseType = typeof base;
              
              if ( baseType === "function" ){
                var inherit = function (){};
                
                inherit.prototype = base.prototype;
                
                derived.prototype = new inherit;
              } else {
                var inherit = function (){},
                    proto = getPrototype( base );
                
                inherit.prototype = proto;
                
                derived.prototype = new inherit;
              };
            };
        
        var __ref_iterator__ = _mochaLocalExport.__ref_iterator__ = "__mocha_iterator_special_key__";
        
        var throwStopIteration = _mochaLocalExport.throwStopIteration = function throwStopIteration() {
              try {
                throw StopIteration;
              } catch( e ){
                throw new Error( e.toString() );
              };
            };
        
        var isGenerator = _mochaLocalExport.isGenerator = function isGenerator( obj ) {
              return obj instanceof Generator;
            };
        
        var getIterator = _mochaLocalExport.getIterator = function getIterator( obj ) {
              var ret = obj[__ref_iterator__](),
                  newObj;
              
              if ( isGenerator( ret ) ){
                return ret;
              };
              
              newObj = {};
              
              if ( ret.next ){
                createUnenumProp( newObj,"next",
                function () {
                  var result = ret.next();
                  
                  if ( result === undefined ){
                    throwStopIteration();
                  };
                  return result;
                });
              } else {
                return {};
              };
              
              if ( !( "__nothrowNext__" in ret ) ){
                createUnenumProp( newObj,"__nothrowNext__",ret.next.bind( ret ) );
              };
              
              for ( var prop in ret ){
                if ( prop !== "next" && prop !== "__nothrowNext__" ){
                  newObj[prop] = ret[prop];
                };
              };
              
              if ( !( "toString" in ret ) ){
                createUnenumProp( newObj,"toString",
                function () {
                  return "[object Iterator]";
                });
              };
              return newObj;
            };
        
        var hasIterator = _mochaLocalExport.hasIterator = function hasIterator( obj ) {
              return __ref_iterator__ in obj;
            };
        
        var rstopIteration = /StopIteration/;
        
        var isStopIteration = _mochaLocalExport.isStopIteration = function isStopIteration( obj ) {
              return obj === StopIteration || rstopIteration.test( obj );
            };
        
        ( function () {
          var assert = _mochaLocalExport.assert = ( console && console.assert )?function ( expect,exp,str,line,filename ) {
                return console.assert( expect === exp,"assertion failed : "+str+"\nexpect "+expect+" but got "+exp+"\nin file "+filename+" at : "+line );
              } : function ( expect,exp,str,line,filename ) {
                if ( expect !== exp ){
                  Runtime.throwException( "assertion failed : "+str+"\nexpect "+expect+" but got "+exp+"\nin file "+filename+" at : "+line );
                };
              };
        })();
        return _mochaLocalExport;
      })();
  
  if ( !( "StopIteration" in window ) ){
    window.StopIteration =  {
      toString : function toString() {
        return "[object StopIteration]";
      }
    };
  };
  
  __LINE__ = 0;
  ( function () {
    try {
      var __FILE__ = "/home/brn/.mocha/module/iterators.js",
          __LINE__ = 0;
      __LINE__ = 2;
      _mochaGlobalExport['../../../../../../../home/brn/.mocha/module/iterators.js'] = {};
      
      __LINE__ = 3;
      var _mochaGlobalAlias = _mochaGlobalExport['../../../../../../../home/brn/.mocha/module/iterators.js'];
      
      __LINE__ = 1;
      ( function () {
        try {
          __LINE__ = 1;
          var _mochaLocalExport = _mochaGlobalAlias;
          
          __LINE__ = 2;
          var hasOwn = Object.prototype.hasOwnProperty;
          
          __LINE__ = 0;
          var iterator = _mochaLocalExport.iterator = "__mocha_iterator_special_key__";
          
          __LINE__ = 0;
          var keys = _mochaLocalExport.keys = function keys( obj ) {
                try {
                  __LINE__ = 0;
                  var _mochaLocalTmp3 =  {
                        
                      };
                  
                  __LINE__ = 0;
                  Runtime.createUnenumProp( _mochaLocalTmp3,iterator,
                  function () {
                    try {
                      __LINE__ = 12;
                      return function () {
                        try {
                          __LINE__ = 0;
                          var _mochaIsNewBorn = true;
                          
                          __LINE__ = 0;
                          var _yieldResult = undefined;
                          
                          __LINE__ = 0;
                          var _yieldState = 0;
                          
                          __LINE__ = 0;
                          var length;
                          
                          __LINE__ = 0;
                          var _mochaLocalTmp2;
                          
                          __LINE__ = 0;
                          var x;
                          
                          __LINE__ = 0;
                          var _mochaLocalTmp1 = [];
                          
                          __LINE__ = 0;
                          var _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                                try {
                                  __LINE__ = 0;
                                  if ( !_isYieldSend ){
                                    __LINE__ = 0;
                                    _mochaIsNewBorn = false;
                                  } else if ( _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined ){
                                    __LINE__ = 0;
                                    Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                                  };
                                  
                                  __LINE__ = 0;
                                  while ( 1 ){
                                    __LINE__ = 0;
                                    switch ( _yieldState ) {
                                      case 0 :
                                        
                                        __LINE__ = 0;
                                        for ( var _mochaLocalTmp0 in obj ){
                                          
                                          __LINE__ = 0;
                                          _mochaLocalTmp1.push( _mochaLocalTmp0 );
                                        };
                                        
                                        __LINE__ = 7;
                                        _mochaLocalTmp2 = 0;
                                        
                                        __LINE__ = 7;
                                        length = _mochaLocalTmp1.length;
                                        
                                        __LINE__ = 0;
                                        if ( !( _mochaLocalTmp2<length ) ){
                                          __LINE__ = 0;
                                          _yieldState = -1;
                                          __LINE__ = 0;
                                          break;
                                        };
                                      case 1 :
                                        
                                        __LINE__ = 0;
                                        x = _mochaLocalTmp1[_mochaLocalTmp2];
                                        
                                        __LINE__ = 0;
                                        if ( hasOwn.call( obj,x ) ){
                                          __LINE__ = 0;
                                          _yieldState = 2;
                                          __LINE__ = 0;
                                          break;
                                        } else {
                                          __LINE__ = 0;
                                          _yieldState = 3;
                                          __LINE__ = 0;
                                          break;
                                        };
                                      case 2 :
                                        
                                        __LINE__ = 0;
                                        _yieldState = 3;
                                        __LINE__ = 0;
                                        return x;
                                      case 3 :
                                        
                                        __LINE__ = 0;
                                        _yieldState = 4;
                                        __LINE__ = 0;
                                        break;
                                      case 4 :
                                        
                                        __LINE__ = 0;
                                         ++ _mochaLocalTmp2;
                                        
                                        __LINE__ = 0;
                                        if ( _mochaLocalTmp2<length ){
                                          __LINE__ = 0;
                                          _yieldState = 1;
                                          __LINE__ = 0;
                                          break;
                                        } else {
                                          __LINE__ = 0;
                                          _yieldState = -1;
                                        };
                                      case -1 :
                                        
                                        __LINE__ = 0;
                                        if ( _isYieldSafe ){
                                          __LINE__ = 0;
                                          return undefined;
                                        } else {
                                          __LINE__ = 0;
                                          Runtime.throwStopIteration();
                                        };
                                        
                                    };
                                  };
                                } catch( e ){
                                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                                }
                              };
                          __LINE__ = 0;
                          return Runtime.createGenerator( _mochaGenerator,
                          function (  ) {
                            try {
                              __LINE__ = 0;
                              _yieldState = -1;
                            } catch( e ){
                              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                            }
                          },this);
                        } catch( e ){
                          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      }();
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  });
                  __LINE__ = 5;
                  return _mochaLocalTmp3;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
          
          __LINE__ = 0;
          var values = _mochaLocalExport.values = function values( obj ) {
                try {
                  __LINE__ = 0;
                  var _mochaLocalTmp7 =  {
                        
                      };
                  
                  __LINE__ = 0;
                  Runtime.createUnenumProp( _mochaLocalTmp7,iterator,
                  function () {
                    try {
                      __LINE__ = 23;
                      return function () {
                        try {
                          __LINE__ = 0;
                          var _mochaIsNewBorn = true;
                          
                          __LINE__ = 0;
                          var _yieldResult = undefined;
                          
                          __LINE__ = 0;
                          var _yieldState = 0;
                          
                          __LINE__ = 0;
                          var length;
                          
                          __LINE__ = 0;
                          var _mochaLocalTmp6;
                          
                          __LINE__ = 0;
                          var x;
                          
                          __LINE__ = 0;
                          var _mochaLocalTmp5 = [];
                          
                          __LINE__ = 0;
                          var _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                                try {
                                  __LINE__ = 0;
                                  if ( !_isYieldSend ){
                                    __LINE__ = 0;
                                    _mochaIsNewBorn = false;
                                  } else if ( _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined ){
                                    __LINE__ = 0;
                                    Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                                  };
                                  
                                  __LINE__ = 0;
                                  while ( 1 ){
                                    __LINE__ = 0;
                                    switch ( _yieldState ) {
                                      case 0 :
                                        
                                        __LINE__ = 0;
                                        for ( var _mochaLocalTmp4 in obj ){
                                          
                                          __LINE__ = 0;
                                          _mochaLocalTmp5.push( _mochaLocalTmp4 );
                                        };
                                        
                                        __LINE__ = 18;
                                        _mochaLocalTmp6 = 0;
                                        
                                        __LINE__ = 18;
                                        length = _mochaLocalTmp5.length;
                                        
                                        __LINE__ = 0;
                                        if ( !( _mochaLocalTmp6<length ) ){
                                          __LINE__ = 0;
                                          _yieldState = -1;
                                          __LINE__ = 0;
                                          break;
                                        };
                                      case 1 :
                                        
                                        __LINE__ = 0;
                                        x = _mochaLocalTmp5[_mochaLocalTmp6];
                                        
                                        __LINE__ = 0;
                                        if ( hasOwn.call( obj,x ) ){
                                          __LINE__ = 0;
                                          _yieldState = 2;
                                          __LINE__ = 0;
                                          break;
                                        } else {
                                          __LINE__ = 0;
                                          _yieldState = 3;
                                          __LINE__ = 0;
                                          break;
                                        };
                                      case 2 :
                                        
                                        __LINE__ = 0;
                                        _yieldState = 3;
                                        __LINE__ = 0;
                                        return obj[x];
                                      case 3 :
                                        
                                        __LINE__ = 0;
                                        _yieldState = 4;
                                        __LINE__ = 0;
                                        break;
                                      case 4 :
                                        
                                        __LINE__ = 0;
                                         ++ _mochaLocalTmp6;
                                        
                                        __LINE__ = 0;
                                        if ( _mochaLocalTmp6<length ){
                                          __LINE__ = 0;
                                          _yieldState = 1;
                                          __LINE__ = 0;
                                          break;
                                        } else {
                                          __LINE__ = 0;
                                          _yieldState = -1;
                                        };
                                      case -1 :
                                        
                                        __LINE__ = 0;
                                        if ( _isYieldSafe ){
                                          __LINE__ = 0;
                                          return undefined;
                                        } else {
                                          __LINE__ = 0;
                                          Runtime.throwStopIteration();
                                        };
                                        
                                    };
                                  };
                                } catch( e ){
                                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                                }
                              };
                          __LINE__ = 0;
                          return Runtime.createGenerator( _mochaGenerator,
                          function (  ) {
                            try {
                              __LINE__ = 0;
                              _yieldState = -1;
                            } catch( e ){
                              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                            }
                          },this);
                        } catch( e ){
                          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      }();
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  });
                  __LINE__ = 16;
                  return _mochaLocalTmp7;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
          
          __LINE__ = 0;
          var items = _mochaLocalExport.items = function items( obj ) {
                try {
                  __LINE__ = 0;
                  var _mochaLocalTmp11 =  {
                        
                      };
                  
                  __LINE__ = 0;
                  Runtime.createUnenumProp( _mochaLocalTmp11,iterator,
                  function () {
                    try {
                      __LINE__ = 34;
                      return function () {
                        try {
                          __LINE__ = 0;
                          var _mochaIsNewBorn = true;
                          
                          __LINE__ = 0;
                          var _yieldResult = undefined;
                          
                          __LINE__ = 0;
                          var _yieldState = 0;
                          
                          __LINE__ = 0;
                          var length;
                          
                          __LINE__ = 0;
                          var _mochaLocalTmp10;
                          
                          __LINE__ = 0;
                          var x;
                          
                          __LINE__ = 0;
                          var _mochaLocalTmp9 = [];
                          
                          __LINE__ = 0;
                          var _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                                try {
                                  __LINE__ = 0;
                                  if ( !_isYieldSend ){
                                    __LINE__ = 0;
                                    _mochaIsNewBorn = false;
                                  } else if ( _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined ){
                                    __LINE__ = 0;
                                    Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                                  };
                                  
                                  __LINE__ = 0;
                                  while ( 1 ){
                                    __LINE__ = 0;
                                    switch ( _yieldState ) {
                                      case 0 :
                                        
                                        __LINE__ = 0;
                                        for ( var _mochaLocalTmp8 in obj ){
                                          
                                          __LINE__ = 0;
                                          _mochaLocalTmp9.push( _mochaLocalTmp8 );
                                        };
                                        
                                        __LINE__ = 29;
                                        _mochaLocalTmp10 = 0;
                                        
                                        __LINE__ = 29;
                                        length = _mochaLocalTmp9.length;
                                        
                                        __LINE__ = 0;
                                        if ( !( _mochaLocalTmp10<length ) ){
                                          __LINE__ = 0;
                                          _yieldState = -1;
                                          __LINE__ = 0;
                                          break;
                                        };
                                      case 1 :
                                        
                                        __LINE__ = 0;
                                        x = _mochaLocalTmp9[_mochaLocalTmp10];
                                        
                                        __LINE__ = 0;
                                        if ( hasOwn.call( obj,x ) ){
                                          __LINE__ = 0;
                                          _yieldState = 2;
                                          __LINE__ = 0;
                                          break;
                                        } else {
                                          __LINE__ = 0;
                                          _yieldState = 3;
                                          __LINE__ = 0;
                                          break;
                                        };
                                      case 2 :
                                        
                                        __LINE__ = 0;
                                        _yieldState = 3;
                                        __LINE__ = 0;
                                        return [x,obj[x]];
                                      case 3 :
                                        
                                        __LINE__ = 0;
                                        _yieldState = 4;
                                        __LINE__ = 0;
                                        break;
                                      case 4 :
                                        
                                        __LINE__ = 0;
                                         ++ _mochaLocalTmp10;
                                        
                                        __LINE__ = 0;
                                        if ( _mochaLocalTmp10<length ){
                                          __LINE__ = 0;
                                          _yieldState = 1;
                                          __LINE__ = 0;
                                          break;
                                        } else {
                                          __LINE__ = 0;
                                          _yieldState = -1;
                                        };
                                      case -1 :
                                        
                                        __LINE__ = 0;
                                        if ( _isYieldSafe ){
                                          __LINE__ = 0;
                                          return undefined;
                                        } else {
                                          __LINE__ = 0;
                                          Runtime.throwStopIteration();
                                        };
                                        
                                    };
                                  };
                                } catch( e ){
                                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                                }
                              };
                          __LINE__ = 0;
                          return Runtime.createGenerator( _mochaGenerator,
                          function (  ) {
                            try {
                              __LINE__ = 0;
                              _yieldState = -1;
                            } catch( e ){
                              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                            }
                          },this);
                        } catch( e ){
                          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      }();
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  });
                  __LINE__ = 27;
                  return _mochaLocalTmp11;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
          
          __LINE__ = 0;
          var allKeys = _mochaLocalExport.allKeys = function allKeys( obj ) {
                try {
                  __LINE__ = 0;
                  var _mochaLocalTmp15 =  {
                        
                      };
                  
                  __LINE__ = 0;
                  Runtime.createUnenumProp( _mochaLocalTmp15,iterator,
                  function () {
                    try {
                      __LINE__ = 42;
                      return function () {
                        try {
                          __LINE__ = 0;
                          var _mochaIsNewBorn = true;
                          
                          __LINE__ = 0;
                          var _yieldResult = undefined;
                          
                          __LINE__ = 0;
                          var _yieldState = 0;
                          
                          __LINE__ = 0;
                          var length;
                          
                          __LINE__ = 0;
                          var _mochaLocalTmp14;
                          
                          __LINE__ = 0;
                          var x;
                          
                          __LINE__ = 0;
                          var _mochaLocalTmp13 = [];
                          
                          __LINE__ = 0;
                          var _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                                try {
                                  __LINE__ = 0;
                                  if ( !_isYieldSend ){
                                    __LINE__ = 0;
                                    _mochaIsNewBorn = false;
                                  } else if ( _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined ){
                                    __LINE__ = 0;
                                    Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                                  };
                                  
                                  __LINE__ = 0;
                                  while ( 1 ){
                                    __LINE__ = 0;
                                    switch ( _yieldState ) {
                                      case 0 :
                                        
                                        __LINE__ = 0;
                                        for ( var _mochaLocalTmp12 in obj ){
                                          
                                          __LINE__ = 0;
                                          _mochaLocalTmp13.push( _mochaLocalTmp12 );
                                        };
                                        
                                        __LINE__ = 39;
                                        _mochaLocalTmp14 = 0;
                                        
                                        __LINE__ = 39;
                                        length = _mochaLocalTmp13.length;
                                        
                                        __LINE__ = 0;
                                        if ( !( _mochaLocalTmp14<length ) ){
                                          __LINE__ = 0;
                                          _yieldState = -1;
                                          __LINE__ = 0;
                                          break;
                                        };
                                      case 1 :
                                        
                                        __LINE__ = 0;
                                        _yieldState = 2;
                                        
                                        __LINE__ = 0;
                                        x = _mochaLocalTmp13[_mochaLocalTmp14];
                                        __LINE__ = 0;
                                        return x;
                                      case 2 :
                                        
                                        __LINE__ = 0;
                                         ++ _mochaLocalTmp14;
                                        
                                        __LINE__ = 0;
                                        if ( _mochaLocalTmp14<length ){
                                          __LINE__ = 0;
                                          _yieldState = 1;
                                          __LINE__ = 0;
                                          break;
                                        } else {
                                          __LINE__ = 0;
                                          _yieldState = -1;
                                        };
                                      case -1 :
                                        
                                        __LINE__ = 0;
                                        if ( _isYieldSafe ){
                                          __LINE__ = 0;
                                          return undefined;
                                        } else {
                                          __LINE__ = 0;
                                          Runtime.throwStopIteration();
                                        };
                                        
                                    };
                                  };
                                } catch( e ){
                                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                                }
                              };
                          __LINE__ = 0;
                          return Runtime.createGenerator( _mochaGenerator,
                          function (  ) {
                            try {
                              __LINE__ = 0;
                              _yieldState = -1;
                            } catch( e ){
                              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                            }
                          },this);
                        } catch( e ){
                          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      }();
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  });
                  __LINE__ = 37;
                  return _mochaLocalTmp15;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
          
          __LINE__ = 0;
          var allValues = _mochaLocalExport.allValues = function allValues( obj ) {
                try {
                  __LINE__ = 0;
                  var _mochaLocalTmp19 =  {
                        
                      };
                  
                  __LINE__ = 0;
                  Runtime.createUnenumProp( _mochaLocalTmp19,iterator,
                  function () {
                    try {
                      __LINE__ = 50;
                      return function () {
                        try {
                          __LINE__ = 0;
                          var _mochaIsNewBorn = true;
                          
                          __LINE__ = 0;
                          var _yieldResult = undefined;
                          
                          __LINE__ = 0;
                          var _yieldState = 0;
                          
                          __LINE__ = 0;
                          var length;
                          
                          __LINE__ = 0;
                          var _mochaLocalTmp18;
                          
                          __LINE__ = 0;
                          var x;
                          
                          __LINE__ = 0;
                          var _mochaLocalTmp17 = [];
                          
                          __LINE__ = 0;
                          var _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                                try {
                                  __LINE__ = 0;
                                  if ( !_isYieldSend ){
                                    __LINE__ = 0;
                                    _mochaIsNewBorn = false;
                                  } else if ( _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined ){
                                    __LINE__ = 0;
                                    Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                                  };
                                  
                                  __LINE__ = 0;
                                  while ( 1 ){
                                    __LINE__ = 0;
                                    switch ( _yieldState ) {
                                      case 0 :
                                        
                                        __LINE__ = 0;
                                        for ( var _mochaLocalTmp16 in obj ){
                                          
                                          __LINE__ = 0;
                                          _mochaLocalTmp17.push( _mochaLocalTmp16 );
                                        };
                                        
                                        __LINE__ = 47;
                                        _mochaLocalTmp18 = 0;
                                        
                                        __LINE__ = 47;
                                        length = _mochaLocalTmp17.length;
                                        
                                        __LINE__ = 0;
                                        if ( !( _mochaLocalTmp18<length ) ){
                                          __LINE__ = 0;
                                          _yieldState = -1;
                                          __LINE__ = 0;
                                          break;
                                        };
                                      case 1 :
                                        
                                        __LINE__ = 0;
                                        _yieldState = 2;
                                        
                                        __LINE__ = 0;
                                        x = _mochaLocalTmp17[_mochaLocalTmp18];
                                        __LINE__ = 0;
                                        return obj[x];
                                      case 2 :
                                        
                                        __LINE__ = 0;
                                         ++ _mochaLocalTmp18;
                                        
                                        __LINE__ = 0;
                                        if ( _mochaLocalTmp18<length ){
                                          __LINE__ = 0;
                                          _yieldState = 1;
                                          __LINE__ = 0;
                                          break;
                                        } else {
                                          __LINE__ = 0;
                                          _yieldState = -1;
                                        };
                                      case -1 :
                                        
                                        __LINE__ = 0;
                                        if ( _isYieldSafe ){
                                          __LINE__ = 0;
                                          return undefined;
                                        } else {
                                          __LINE__ = 0;
                                          Runtime.throwStopIteration();
                                        };
                                        
                                    };
                                  };
                                } catch( e ){
                                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                                }
                              };
                          __LINE__ = 0;
                          return Runtime.createGenerator( _mochaGenerator,
                          function (  ) {
                            try {
                              __LINE__ = 0;
                              _yieldState = -1;
                            } catch( e ){
                              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                            }
                          },this);
                        } catch( e ){
                          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      }();
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  });
                  __LINE__ = 45;
                  return _mochaLocalTmp19;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
          
          __LINE__ = 0;
          var allItems = _mochaLocalExport.allItems = function allItems( obj ) {
                try {
                  __LINE__ = 0;
                  var _mochaLocalTmp23 =  {
                        
                      };
                  
                  __LINE__ = 0;
                  Runtime.createUnenumProp( _mochaLocalTmp23,iterator,
                  function () {
                    try {
                      __LINE__ = 58;
                      return function () {
                        try {
                          __LINE__ = 0;
                          var _mochaIsNewBorn = true;
                          
                          __LINE__ = 0;
                          var _yieldResult = undefined;
                          
                          __LINE__ = 0;
                          var _yieldState = 0;
                          
                          __LINE__ = 0;
                          var length;
                          
                          __LINE__ = 0;
                          var _mochaLocalTmp22;
                          
                          __LINE__ = 0;
                          var x;
                          
                          __LINE__ = 0;
                          var _mochaLocalTmp21 = [];
                          
                          __LINE__ = 0;
                          var _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                                try {
                                  __LINE__ = 0;
                                  if ( !_isYieldSend ){
                                    __LINE__ = 0;
                                    _mochaIsNewBorn = false;
                                  } else if ( _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined ){
                                    __LINE__ = 0;
                                    Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                                  };
                                  
                                  __LINE__ = 0;
                                  while ( 1 ){
                                    __LINE__ = 0;
                                    switch ( _yieldState ) {
                                      case 0 :
                                        
                                        __LINE__ = 0;
                                        for ( var _mochaLocalTmp20 in obj ){
                                          
                                          __LINE__ = 0;
                                          _mochaLocalTmp21.push( _mochaLocalTmp20 );
                                        };
                                        
                                        __LINE__ = 55;
                                        _mochaLocalTmp22 = 0;
                                        
                                        __LINE__ = 55;
                                        length = _mochaLocalTmp21.length;
                                        
                                        __LINE__ = 0;
                                        if ( !( _mochaLocalTmp22<length ) ){
                                          __LINE__ = 0;
                                          _yieldState = -1;
                                          __LINE__ = 0;
                                          break;
                                        };
                                      case 1 :
                                        
                                        __LINE__ = 0;
                                        _yieldState = 2;
                                        
                                        __LINE__ = 0;
                                        x = _mochaLocalTmp21[_mochaLocalTmp22];
                                        __LINE__ = 0;
                                        return [x,obj[x]];
                                      case 2 :
                                        
                                        __LINE__ = 0;
                                         ++ _mochaLocalTmp22;
                                        
                                        __LINE__ = 0;
                                        if ( _mochaLocalTmp22<length ){
                                          __LINE__ = 0;
                                          _yieldState = 1;
                                          __LINE__ = 0;
                                          break;
                                        } else {
                                          __LINE__ = 0;
                                          _yieldState = -1;
                                        };
                                      case -1 :
                                        
                                        __LINE__ = 0;
                                        if ( _isYieldSafe ){
                                          __LINE__ = 0;
                                          return undefined;
                                        } else {
                                          __LINE__ = 0;
                                          Runtime.throwStopIteration();
                                        };
                                        
                                    };
                                  };
                                } catch( e ){
                                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                                }
                              };
                          __LINE__ = 0;
                          return Runtime.createGenerator( _mochaGenerator,
                          function (  ) {
                            try {
                              __LINE__ = 0;
                              _yieldState = -1;
                            } catch( e ){
                              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                            }
                          },this);
                        } catch( e ){
                          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      }();
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  });
                  __LINE__ = 53;
                  return _mochaLocalTmp23;
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
  
  __LINE__ = 0;
  ( function () {
    try {
      var __FILE__ = "/var/samba/mocha/src/test/js/harmony/for_of_test.js",
          __LINE__ = 0;
      __LINE__ = 2;
      _mochaGlobalExport['./for_of_test.js'] = {};
      
      __LINE__ = 3;
      var _mochaGlobalAlias = _mochaGlobalExport['./for_of_test.js'];
      
      __LINE__ = 0;
      var _mochaLocalTmp0 = _mochaGlobalExport['../../../../../../../home/brn/.mocha/module/iterators.js'],
          iterator = _mochaLocalTmp0.iterator;
      
      __LINE__ = 0;
      var _mochaLocalTmp9 =  {
            arr : [],
            add : function ( value ) {
              try {
                __LINE__ = 0;
                this.arr.push( value );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            
          };
      
      __LINE__ = 0;
      Runtime.createUnenumProp( _mochaLocalTmp9,iterator,
      function () {
        try {
          __LINE__ = 0;
          var arr = this.arr;
          __LINE__ = 27;
          return  {
            index : 0,
            next : function () {
              try {
                __LINE__ = 0;
                if ( arr.length>this.index ){
                  __LINE__ = 0;
                  var ret = arr[this.index];
                  
                  __LINE__ = 0;
                  this.index ++ ;
                  __LINE__ = 33;
                  return ret;
                } else {
                  __LINE__ = 0;
                  return undefined;
                };
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            }
          };
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      });
      
      __LINE__ = 2;
      var item = function ( obj ) {
            try {
              __LINE__ = 0;
              var _mochaLocalTmp4 =  {
                    
                  };
              
              __LINE__ = 0;
              Runtime.createUnenumProp( _mochaLocalTmp4,iterator,
              function () {
                try {
                  __LINE__ = 0;
                  var _mochaIsNewBorn = true;
                  
                  __LINE__ = 0;
                  var _yieldResult = undefined;
                  
                  __LINE__ = 0;
                  var _yieldState = 0;
                  
                  __LINE__ = 0;
                  var length;
                  
                  __LINE__ = 0;
                  var _mochaLocalTmp3;
                  
                  __LINE__ = 0;
                  var i;
                  
                  __LINE__ = 0;
                  var _mochaLocalTmp2 = [];
                  
                  __LINE__ = 0;
                  var _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                        try {
                          __LINE__ = 0;
                          if ( !_isYieldSend ){
                            __LINE__ = 0;
                            _mochaIsNewBorn = false;
                          } else if ( _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined ){
                            __LINE__ = 0;
                            Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                          };
                          
                          __LINE__ = 0;
                          while ( 1 ){
                            __LINE__ = 0;
                            switch ( _yieldState ) {
                              case 0 :
                                
                                __LINE__ = 0;
                                for ( var _mochaLocalTmp1 in obj ){
                                  
                                  __LINE__ = 9;
                                  _mochaLocalTmp2.push( _mochaLocalTmp1 );
                                };
                                
                                __LINE__ = 5;
                                _mochaLocalTmp3 = 0;
                                
                                __LINE__ = 5;
                                length = _mochaLocalTmp2.length;
                                
                                __LINE__ = 0;
                                if ( !( _mochaLocalTmp3<length ) ){
                                  __LINE__ = 9;
                                  _yieldState = -1;
                                  __LINE__ = 9;
                                  break;
                                };
                              case 1 :
                                
                                __LINE__ = 0;
                                _yieldState = 2;
                                
                                __LINE__ = 0;
                                i = _mochaLocalTmp2[_mochaLocalTmp3];
                                
                                __LINE__ = 0;
                                i = obj[i];
                                __LINE__ = 0;
                                return i;
                              case 2 :
                                
                                __LINE__ = 0;
                                 ++ _mochaLocalTmp3;
                                
                                __LINE__ = 0;
                                if ( _mochaLocalTmp3<length ){
                                  __LINE__ = 9;
                                  _yieldState = 1;
                                  __LINE__ = 0;
                                  break;
                                } else {
                                  __LINE__ = 9;
                                  _yieldState = -1;
                                };
                              case -1 :
                                
                                __LINE__ = 0;
                                if ( _isYieldSafe ){
                                  __LINE__ = 0;
                                  return undefined;
                                } else {
                                  __LINE__ = 9;
                                  Runtime.throwStopIteration();
                                };
                                
                            };
                          };
                        } catch( e ){
                          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      };
                  __LINE__ = 0;
                  return Runtime.createGenerator( _mochaGenerator,
                  function (  ) {
                    try {
                      __LINE__ = 0;
                      _yieldState = -1;
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  },this);
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              });
              __LINE__ = 3;
              return _mochaLocalTmp4;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          },
          key = function ( obj ) {
            try {
              __LINE__ = 0;
              var _mochaLocalTmp8 =  {
                    
                  };
              
              __LINE__ = 0;
              Runtime.createUnenumProp( _mochaLocalTmp8,iterator,
              function () {
                try {
                  __LINE__ = 0;
                  var _mochaIsNewBorn = true;
                  
                  __LINE__ = 0;
                  var _yieldResult = undefined;
                  
                  __LINE__ = 0;
                  var _yieldState = 0;
                  
                  __LINE__ = 0;
                  var length;
                  
                  __LINE__ = 0;
                  var _mochaLocalTmp7;
                  
                  __LINE__ = 0;
                  var i;
                  
                  __LINE__ = 0;
                  var _mochaLocalTmp6 = [];
                  
                  __LINE__ = 0;
                  var _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                        try {
                          __LINE__ = 0;
                          if ( !_isYieldSend ){
                            __LINE__ = 0;
                            _mochaIsNewBorn = false;
                          } else if ( _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined ){
                            __LINE__ = 0;
                            Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                          };
                          
                          __LINE__ = 0;
                          while ( 1 ){
                            __LINE__ = 0;
                            switch ( _yieldState ) {
                              case 0 :
                                
                                __LINE__ = 0;
                                for ( var _mochaLocalTmp5 in obj ){
                                  
                                  __LINE__ = 18;
                                  _mochaLocalTmp6.push( _mochaLocalTmp5 );
                                };
                                
                                __LINE__ = 14;
                                _mochaLocalTmp7 = 0;
                                
                                __LINE__ = 14;
                                length = _mochaLocalTmp6.length;
                                
                                __LINE__ = 0;
                                if ( !( _mochaLocalTmp7<length ) ){
                                  __LINE__ = 18;
                                  _yieldState = -1;
                                  __LINE__ = 18;
                                  break;
                                };
                              case 1 :
                                
                                __LINE__ = 0;
                                _yieldState = 2;
                                
                                __LINE__ = 0;
                                i = _mochaLocalTmp6[_mochaLocalTmp7];
                                __LINE__ = 0;
                                return i;
                              case 2 :
                                
                                __LINE__ = 0;
                                 ++ _mochaLocalTmp7;
                                
                                __LINE__ = 0;
                                if ( _mochaLocalTmp7<length ){
                                  __LINE__ = 18;
                                  _yieldState = 1;
                                  __LINE__ = 0;
                                  break;
                                } else {
                                  __LINE__ = 18;
                                  _yieldState = -1;
                                };
                              case -1 :
                                
                                __LINE__ = 0;
                                if ( _isYieldSafe ){
                                  __LINE__ = 0;
                                  return undefined;
                                } else {
                                  __LINE__ = 18;
                                  Runtime.throwStopIteration();
                                };
                                
                            };
                          };
                        } catch( e ){
                          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      };
                  __LINE__ = 0;
                  return Runtime.createGenerator( _mochaGenerator,
                  function (  ) {
                    try {
                      __LINE__ = 0;
                      _yieldState = -1;
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  },this);
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              });
              __LINE__ = 12;
              return _mochaLocalTmp8;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          },
          iter = _mochaLocalTmp9;
      
      __LINE__ = 42;
      var testObj =  {
            value1 : 100,
            value2 : 200,
            value3 : 300,
            value4 : 400
          };
      
      __LINE__ = 48;
      var ret = [];
      
      __LINE__ = 0;
      var i;
      
      __LINE__ = 0;
      var _mochaLocalTmp10 = item( testObj );
      
      __LINE__ = 0;
      _mochaLocalTmp10 = Runtime.hasIterator( _mochaLocalTmp10 )?Runtime.getIterator( _mochaLocalTmp10 ) : _mochaLocalTmp10;
      
      __LINE__ = 0;
      if ( _mochaLocalTmp10.__nothrowNext__ ){
        __LINE__ = 0;
        while ( ( i = _mochaLocalTmp10.__nothrowNext__(  ) ) ){
          __LINE__ = 0;
          ret.push( i );
        };
      } else {
        __LINE__ = 0;
        Runtime.exceptionHandler( 49,'./for_of_test.js','for of statement expect iterator or generator object.' );
      };
      
      __LINE__ = 52;
      Runtime.assert( true,ret[0] === 100,"ret[0] === 100",52,'./for_of_test.js' );
      
      __LINE__ = 53;
      Runtime.assert( true,ret[1] === 200,"ret[1] === 200",53,'./for_of_test.js' );
      
      __LINE__ = 54;
      Runtime.assert( true,ret[2] === 300,"ret[2] === 300",54,'./for_of_test.js' );
      
      __LINE__ = 55;
      Runtime.assert( true,ret[3] === 400,"ret[3] === 400",55,'./for_of_test.js' );
      
      __LINE__ = 0;
      ret = [];
      
      __LINE__ = 0;
      var x;
      
      __LINE__ = 0;
      var _mochaLocalTmp11 = key( testObj );
      
      __LINE__ = 0;
      _mochaLocalTmp11 = Runtime.hasIterator( _mochaLocalTmp11 )?Runtime.getIterator( _mochaLocalTmp11 ) : _mochaLocalTmp11;
      
      __LINE__ = 0;
      if ( _mochaLocalTmp11.__nothrowNext__ ){
        __LINE__ = 0;
        while ( ( x = _mochaLocalTmp11.__nothrowNext__(  ) ) ){
          __LINE__ = 0;
          ret.push( x );
        };
      } else {
        __LINE__ = 0;
        Runtime.exceptionHandler( 58,'./for_of_test.js','for of statement expect iterator or generator object.' );
      };
      
      __LINE__ = 61;
      Runtime.assert( true,ret[0] === "value1","ret[0] === \"value1\"",61,'./for_of_test.js' );
      
      __LINE__ = 62;
      Runtime.assert( true,ret[1] === "value2","ret[1] === \"value2\"",62,'./for_of_test.js' );
      
      __LINE__ = 63;
      Runtime.assert( true,ret[2] === "value3","ret[2] === \"value3\"",63,'./for_of_test.js' );
      
      __LINE__ = 64;
      Runtime.assert( true,ret[3] === "value4","ret[3] === \"value4\"",64,'./for_of_test.js' );
      
      __LINE__ = 0;
      ret = [];
      
      __LINE__ = 0;
      iter.add( 100 );
      
      __LINE__ = 0;
      iter.add( 200 );
      
      __LINE__ = 0;
      iter.add( 300 );
      
      __LINE__ = 0;
      iter.add( 400 );
      
      __LINE__ = 0;
      var _mochaLocalTmp12 = iter;
      
      __LINE__ = 0;
      _mochaLocalTmp12 = Runtime.hasIterator( _mochaLocalTmp12 )?Runtime.getIterator( _mochaLocalTmp12 ) : _mochaLocalTmp12;
      
      __LINE__ = 0;
      if ( _mochaLocalTmp12.__nothrowNext__ ){
        __LINE__ = 0;
        while ( ( i = _mochaLocalTmp12.__nothrowNext__(  ) ) ){
          __LINE__ = 0;
          ret.push( i );
        };
      } else {
        __LINE__ = 0;
        Runtime.exceptionHandler( 71,'./for_of_test.js','for of statement expect iterator or generator object.' );
      };
      
      __LINE__ = 74;
      Runtime.assert( true,ret[0] === 100,"ret[0] === 100",74,'./for_of_test.js' );
      
      __LINE__ = 75;
      Runtime.assert( true,ret[1] === 200,"ret[1] === 200",75,'./for_of_test.js' );
      
      __LINE__ = 76;
      Runtime.assert( true,ret[2] === 300,"ret[2] === 300",76,'./for_of_test.js' );
      
      __LINE__ = 77;
      Runtime.assert( true,ret[3] === 400,"ret[3] === 400",77,'./for_of_test.js' );
    } catch( e ){
      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  })();
})();
