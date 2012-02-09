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
              return ( ( likeArray ) )?slice.call( likeArray,index ) : [];
            };
        
        var createGenerator = _mochaLocalExport.createGenerator = function createGenerator( generatorFn,closeFn,context ) {
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
        
        function getErrorMessage( e ) {
          return ( ( e.message ) )?e.message : ( ( e.description ) )?e.description : e.toString();
        }
        var throwException = _mochaLocalExport.throwException = Runtime.throwException.bind( Runtime );
        
        var exceptionHandler = _mochaLocalExport.exceptionHandler = Runtime.exceptionHandler.bind( Runtime );
        
        var extendPrototype = _mochaLocalExport.extendPrototype = function ( derived,base ) {
              derived.prototype = base;
            };
        
        var getPrototype = ( ( "getPrototypeOf" in Object ) )?function ( obj ) {
              return Object.getPrototypeOf( obj );
            } : function ( obj ) {
              if ( "constructor" in obj ){
                return obj.constructor.prototype || {};
              };
            };
        
        var extendClass = _mochaLocalExport.extendClass = ( ( Runtime.hasProto ) )?function ( derived,base ) {
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
        
        ( function () {
          var assert = _mochaLocalExport.assert = ( ( console && console.assert ) )?function ( expect,exp,str,line,filename ) {
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
        return "StopIteration";
      }
    };
  };
  
  __LINE__ = 0;
  ( function () {
    try {
      var __FILE__ = "/Users/aono_taketoshi/github/mocha/src/test/js/harmony/yield_test.js",
          __LINE__ = 0;
      __LINE__ = 2;
      _mochaGlobalExport['./yield_test.js'] = {};
      
      __LINE__ = 3;
      var _mochaGlobalAlias = _mochaGlobalExport['./yield_test.js'];
      
      __LINE__ = 0;
      function yieldTest(  ) {
        try {
          __LINE__ = 0;
          var _mochaIsNewBorn = true;
          
          __LINE__ = 0;
          var _yieldResult = undefined;
          
          __LINE__ = 0;
          var _yieldState = 0;
          
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
                  
                  __LINE__ = 5;
                  while ( 1 ){
                    __LINE__ = 5;
                    switch ( _yieldState ) {
                      case 0 :
                        
                        __LINE__ = 0;
                        _yieldState = -1;
                        __LINE__ = 0;
                        return arguments;
                      case -1 :
                        
                        __LINE__ = 0;
                        if ( _isYieldSafe ){
                          __LINE__ = 0;
                          return undefined;
                        } else {
                          __LINE__ = 5;
                          Runtime.throwException( StopIteration );
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
      };
      
      __LINE__ = 0;
      function yieldTest2(  ) {
        try {
          __LINE__ = 0;
          var _mochaIsNewBorn = true;
          
          __LINE__ = 0;
          var _yieldResult = undefined;
          
          __LINE__ = 0;
          var _yieldState = 0;
          
          __LINE__ = 6;
          var i;
          
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
                  
                  __LINE__ = 11;
                  while ( 1 ){
                    __LINE__ = 11;
                    switch ( _yieldState ) {
                      case 0 :
                        
                        __LINE__ = 6;
                        i = 0;
                        
                        __LINE__ = 6;
                        if ( !( i<10 ) ){
                          __LINE__ = 11;
                          _yieldState = -1;
                          __LINE__ = 11;
                          break;
                        };
                      case 1 :
                        
                        __LINE__ = 0;
                        _yieldState = 2;
                        __LINE__ = 0;
                        return i;
                      case 2 :
                        
                        __LINE__ = 0;
                        i ++ ;
                        
                        __LINE__ = 11;
                        if ( i<10 ){
                          __LINE__ = 11;
                          _yieldState = 1;
                          __LINE__ = 0;
                          break;
                        } else {
                          __LINE__ = 11;
                          _yieldState = -1;
                        };
                      case -1 :
                        
                        __LINE__ = 0;
                        if ( _isYieldSafe ){
                          __LINE__ = 0;
                          return undefined;
                        } else {
                          __LINE__ = 11;
                          Runtime.throwException( StopIteration );
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
      };
      
      __LINE__ = 11;
      var generator = yieldTest2();
      
      __LINE__ = 13;
      Runtime.assert( true,generator.next() === 0,"generator.next() === 0",13,'./yield_test.js' );
      
      __LINE__ = 14;
      Runtime.assert( true,generator.next() === 1,"generator.next() === 1",14,'./yield_test.js' );
      
      __LINE__ = 15;
      Runtime.assert( true,generator.next() === 2,"generator.next() === 2",15,'./yield_test.js' );
      
      __LINE__ = 16;
      Runtime.assert( true,generator.next() === 3,"generator.next() === 3",16,'./yield_test.js' );
      
      __LINE__ = 17;
      Runtime.assert( true,generator.next() === 4,"generator.next() === 4",17,'./yield_test.js' );
      
      __LINE__ = 18;
      Runtime.assert( true,generator.next() === 5,"generator.next() === 5",18,'./yield_test.js' );
      
      __LINE__ = 19;
      Runtime.assert( true,generator.next() === 6,"generator.next() === 6",19,'./yield_test.js' );
      
      __LINE__ = 20;
      Runtime.assert( true,generator.next() === 7,"generator.next() === 7",20,'./yield_test.js' );
      
      __LINE__ = 21;
      Runtime.assert( true,generator.next() === 8,"generator.next() === 8",21,'./yield_test.js' );
      
      __LINE__ = 22;
      Runtime.assert( true,generator.next() === 9,"generator.next() === 9",22,'./yield_test.js' );
      
      __LINE__ = 0;
      function yieldTest3(  ) {
        try {
          __LINE__ = 0;
          var _mochaIsNewBorn = true;
          
          __LINE__ = 0;
          var _yieldResult = undefined;
          
          __LINE__ = 0;
          var _yieldState = 0;
          
          __LINE__ = 26;
          var i;
          
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
                  
                  __LINE__ = 32;
                  while ( 1 ){
                    __LINE__ = 32;
                    switch ( _yieldState ) {
                      case 0 :
                        
                        __LINE__ = 26;
                        i = 0;
                        
                        __LINE__ = 26;
                        if ( !( i<10 ) ){
                          __LINE__ = 32;
                          _yieldState = -1;
                          __LINE__ = 32;
                          break;
                        };
                      case 1 :
                        
                        __LINE__ = 27;
                        if ( i%2 === 0 ){
                          __LINE__ = 32;
                          _yieldState = 2;
                          __LINE__ = 0;
                          break;
                        } else {
                          __LINE__ = 32;
                          _yieldState = 3;
                          __LINE__ = 0;
                          break;
                        };
                      case 2 :
                        
                        __LINE__ = 0;
                        _yieldState = 3;
                        __LINE__ = 0;
                        return i;
                      case 3 :
                        
                        __LINE__ = 0;
                        _yieldState = 4;
                        __LINE__ = 0;
                        break;
                      case 4 :
                        
                        __LINE__ = 0;
                        i ++ ;
                        
                        __LINE__ = 32;
                        if ( i<10 ){
                          __LINE__ = 32;
                          _yieldState = 1;
                          __LINE__ = 0;
                          break;
                        } else {
                          __LINE__ = 32;
                          _yieldState = -1;
                        };
                      case -1 :
                        
                        __LINE__ = 0;
                        if ( _isYieldSafe ){
                          __LINE__ = 0;
                          return undefined;
                        } else {
                          __LINE__ = 32;
                          Runtime.throwException( StopIteration );
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
      };
      
      __LINE__ = 0;
      generator = yieldTest3();
      
      __LINE__ = 33;
      Runtime.assert( true,generator.next() === 0,"generator.next() === 0",33,'./yield_test.js' );
      
      __LINE__ = 34;
      Runtime.assert( true,generator.next() === 2,"generator.next() === 2",34,'./yield_test.js' );
      
      __LINE__ = 35;
      Runtime.assert( true,generator.next() === 4,"generator.next() === 4",35,'./yield_test.js' );
      
      __LINE__ = 36;
      Runtime.assert( true,generator.next() === 6,"generator.next() === 6",36,'./yield_test.js' );
      
      __LINE__ = 37;
      Runtime.assert( true,generator.next() === 8,"generator.next() === 8",37,'./yield_test.js' );
      
      __LINE__ = 0;
      function yieldTest3(  ) {
        try {
          __LINE__ = 0;
          var _mochaIsNewBorn = true;
          
          __LINE__ = 0;
          var _yieldResult = undefined;
          
          __LINE__ = 0;
          var _yieldState = 0;
          
          __LINE__ = 41;
          var j;
          
          __LINE__ = 40;
          var i;
          
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
                  
                  __LINE__ = 48;
                  while ( 1 ){
                    __LINE__ = 48;
                    switch ( _yieldState ) {
                      case 0 :
                        
                        __LINE__ = 40;
                        i = 0;
                        
                        __LINE__ = 40;
                        if ( !( i<10 ) ){
                          __LINE__ = 48;
                          _yieldState = -1;
                          __LINE__ = 48;
                          break;
                        };
                      case 1 :
                        
                        __LINE__ = 41;
                        j = 0;
                        
                        __LINE__ = 41;
                        if ( !( j<10 ) ){
                          __LINE__ = 48;
                          _yieldState = 6;
                          __LINE__ = 48;
                          break;
                        };
                      case 2 :
                        
                        __LINE__ = 42;
                        if ( j%2 === 0 ){
                          __LINE__ = 48;
                          _yieldState = 3;
                          __LINE__ = 0;
                          break;
                        } else {
                          __LINE__ = 48;
                          _yieldState = 4;
                          __LINE__ = 0;
                          break;
                        };
                      case 3 :
                        
                        __LINE__ = 0;
                        _yieldState = 4;
                        __LINE__ = 0;
                        return j;
                      case 4 :
                        
                        __LINE__ = 0;
                        _yieldState = 5;
                        __LINE__ = 0;
                        break;
                      case 5 :
                        
                        __LINE__ = 0;
                        j ++ ;
                        
                        __LINE__ = 48;
                        if ( j<10 ){
                          __LINE__ = 48;
                          _yieldState = 2;
                          __LINE__ = 0;
                          break;
                        } else {
                          __LINE__ = 48;
                          _yieldState = 6;
                        };
                      case 6 :
                        
                        __LINE__ = 0;
                        i ++ ;
                        
                        __LINE__ = 48;
                        if ( i<10 ){
                          __LINE__ = 48;
                          _yieldState = 1;
                          __LINE__ = 0;
                          break;
                        } else {
                          __LINE__ = 48;
                          _yieldState = -1;
                        };
                      case -1 :
                        
                        __LINE__ = 0;
                        if ( _isYieldSafe ){
                          __LINE__ = 0;
                          return undefined;
                        } else {
                          __LINE__ = 48;
                          Runtime.throwException( StopIteration );
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
      };
      
      __LINE__ = 0;
      generator = yieldTest3();
      
      __LINE__ = 49;
      Runtime.assert( true,generator.next() === 0,"generator.next() === 0",49,'./yield_test.js' );
      
      __LINE__ = 50;
      Runtime.assert( true,generator.next() === 2,"generator.next() === 2",50,'./yield_test.js' );
      
      __LINE__ = 51;
      Runtime.assert( true,generator.next() === 4,"generator.next() === 4",51,'./yield_test.js' );
      
      __LINE__ = 52;
      Runtime.assert( true,generator.next() === 6,"generator.next() === 6",52,'./yield_test.js' );
      
      __LINE__ = 53;
      Runtime.assert( true,generator.next() === 8,"generator.next() === 8",53,'./yield_test.js' );
      
      __LINE__ = 55;
      Runtime.assert( true,generator.next() === 0,"generator.next() === 0",55,'./yield_test.js' );
      
      __LINE__ = 56;
      Runtime.assert( true,generator.next() === 2,"generator.next() === 2",56,'./yield_test.js' );
      
      __LINE__ = 57;
      Runtime.assert( true,generator.next() === 4,"generator.next() === 4",57,'./yield_test.js' );
      
      __LINE__ = 58;
      Runtime.assert( true,generator.next() === 6,"generator.next() === 6",58,'./yield_test.js' );
      
      __LINE__ = 59;
      Runtime.assert( true,generator.next() === 8,"generator.next() === 8",59,'./yield_test.js' );
      
      __LINE__ = 61;
      Runtime.assert( true,generator.next() === 0,"generator.next() === 0",61,'./yield_test.js' );
      
      __LINE__ = 62;
      Runtime.assert( true,generator.next() === 2,"generator.next() === 2",62,'./yield_test.js' );
      
      __LINE__ = 63;
      Runtime.assert( true,generator.next() === 4,"generator.next() === 4",63,'./yield_test.js' );
      
      __LINE__ = 64;
      Runtime.assert( true,generator.next() === 6,"generator.next() === 6",64,'./yield_test.js' );
      
      __LINE__ = 65;
      Runtime.assert( true,generator.next() === 8,"generator.next() === 8",65,'./yield_test.js' );
      
      __LINE__ = 67;
      Runtime.assert( true,generator.next() === 0,"generator.next() === 0",67,'./yield_test.js' );
      
      __LINE__ = 68;
      Runtime.assert( true,generator.next() === 2,"generator.next() === 2",68,'./yield_test.js' );
      
      __LINE__ = 69;
      Runtime.assert( true,generator.next() === 4,"generator.next() === 4",69,'./yield_test.js' );
      
      __LINE__ = 70;
      Runtime.assert( true,generator.next() === 6,"generator.next() === 6",70,'./yield_test.js' );
      
      __LINE__ = 71;
      Runtime.assert( true,generator.next() === 8,"generator.next() === 8",71,'./yield_test.js' );
      
      __LINE__ = 73;
      Runtime.assert( true,generator.next() === 0,"generator.next() === 0",73,'./yield_test.js' );
      
      __LINE__ = 74;
      Runtime.assert( true,generator.next() === 2,"generator.next() === 2",74,'./yield_test.js' );
      
      __LINE__ = 75;
      Runtime.assert( true,generator.next() === 4,"generator.next() === 4",75,'./yield_test.js' );
      
      __LINE__ = 76;
      Runtime.assert( true,generator.next() === 6,"generator.next() === 6",76,'./yield_test.js' );
      
      __LINE__ = 77;
      Runtime.assert( true,generator.next() === 8,"generator.next() === 8",77,'./yield_test.js' );
      
      __LINE__ = 79;
      Runtime.assert( true,generator.next() === 0,"generator.next() === 0",79,'./yield_test.js' );
      
      __LINE__ = 80;
      Runtime.assert( true,generator.next() === 2,"generator.next() === 2",80,'./yield_test.js' );
      
      __LINE__ = 81;
      Runtime.assert( true,generator.next() === 4,"generator.next() === 4",81,'./yield_test.js' );
      
      __LINE__ = 82;
      Runtime.assert( true,generator.next() === 6,"generator.next() === 6",82,'./yield_test.js' );
      
      __LINE__ = 83;
      Runtime.assert( true,generator.next() === 8,"generator.next() === 8",83,'./yield_test.js' );
      
      __LINE__ = 85;
      Runtime.assert( true,generator.next() === 0,"generator.next() === 0",85,'./yield_test.js' );
      
      __LINE__ = 86;
      Runtime.assert( true,generator.next() === 2,"generator.next() === 2",86,'./yield_test.js' );
      
      __LINE__ = 87;
      Runtime.assert( true,generator.next() === 4,"generator.next() === 4",87,'./yield_test.js' );
      
      __LINE__ = 88;
      Runtime.assert( true,generator.next() === 6,"generator.next() === 6",88,'./yield_test.js' );
      
      __LINE__ = 89;
      Runtime.assert( true,generator.next() === 8,"generator.next() === 8",89,'./yield_test.js' );
      
      __LINE__ = 91;
      Runtime.assert( true,generator.next() === 0,"generator.next() === 0",91,'./yield_test.js' );
      
      __LINE__ = 92;
      Runtime.assert( true,generator.next() === 2,"generator.next() === 2",92,'./yield_test.js' );
      
      __LINE__ = 93;
      Runtime.assert( true,generator.next() === 4,"generator.next() === 4",93,'./yield_test.js' );
      
      __LINE__ = 94;
      Runtime.assert( true,generator.next() === 6,"generator.next() === 6",94,'./yield_test.js' );
      
      __LINE__ = 95;
      Runtime.assert( true,generator.next() === 8,"generator.next() === 8",95,'./yield_test.js' );
      
      __LINE__ = 97;
      Runtime.assert( true,generator.next() === 0,"generator.next() === 0",97,'./yield_test.js' );
      
      __LINE__ = 98;
      Runtime.assert( true,generator.next() === 2,"generator.next() === 2",98,'./yield_test.js' );
      
      __LINE__ = 99;
      Runtime.assert( true,generator.next() === 4,"generator.next() === 4",99,'./yield_test.js' );
      
      __LINE__ = 100;
      Runtime.assert( true,generator.next() === 6,"generator.next() === 6",100,'./yield_test.js' );
      
      __LINE__ = 101;
      Runtime.assert( true,generator.next() === 8,"generator.next() === 8",101,'./yield_test.js' );
      
      __LINE__ = 103;
      Runtime.assert( true,generator.next() === 0,"generator.next() === 0",103,'./yield_test.js' );
      
      __LINE__ = 104;
      Runtime.assert( true,generator.next() === 2,"generator.next() === 2",104,'./yield_test.js' );
      
      __LINE__ = 105;
      Runtime.assert( true,generator.next() === 4,"generator.next() === 4",105,'./yield_test.js' );
      
      __LINE__ = 106;
      Runtime.assert( true,generator.next() === 6,"generator.next() === 6",106,'./yield_test.js' );
      
      __LINE__ = 107;
      Runtime.assert( true,generator.next() === 8,"generator.next() === 8",107,'./yield_test.js' );
      
      __LINE__ = 0;
      function yieldTest4(  ) {
        try {
          __LINE__ = 0;
          var _mochaIsNewBorn = true;
          
          __LINE__ = 0;
          var _yieldResult = undefined;
          
          __LINE__ = 0;
          var _yieldState = 0;
          
          __LINE__ = 111;
          var i;
          
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
                  
                  __LINE__ = 117;
                  while ( 1 ){
                    __LINE__ = 117;
                    switch ( _yieldState ) {
                      case 0 :
                        
                        __LINE__ = 111;
                        i = 0;
                        
                        __LINE__ = 112;
                        if ( !(  ++ i<10 ) ){
                          __LINE__ = 117;
                          _yieldState = -1;
                          __LINE__ = 117;
                          break;
                        };
                      case 1 :
                        
                        __LINE__ = 0;
                        _yieldState = 2;
                        __LINE__ = 0;
                        return i;
                      case 2 :
                        
                        __LINE__ = 117;
                        if (  ++ i<10 ){
                          __LINE__ = 117;
                          _yieldState = 1;
                          __LINE__ = 0;
                          break;
                        } else {
                          __LINE__ = 117;
                          _yieldState = -1;
                        };
                      case -1 :
                        
                        __LINE__ = 0;
                        if ( _isYieldSafe ){
                          __LINE__ = 0;
                          return undefined;
                        } else {
                          __LINE__ = 117;
                          Runtime.throwException( StopIteration );
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
      };
      
      __LINE__ = 0;
      generator = yieldTest4();
      
      __LINE__ = 118;
      Runtime.assert( true,generator.next() === 1,"generator.next() === 1",118,'./yield_test.js' );
      
      __LINE__ = 119;
      Runtime.assert( true,generator.next() === 2,"generator.next() === 2",119,'./yield_test.js' );
      
      __LINE__ = 120;
      Runtime.assert( true,generator.next() === 3,"generator.next() === 3",120,'./yield_test.js' );
      
      __LINE__ = 121;
      Runtime.assert( true,generator.next() === 4,"generator.next() === 4",121,'./yield_test.js' );
      
      __LINE__ = 122;
      Runtime.assert( true,generator.next() === 5,"generator.next() === 5",122,'./yield_test.js' );
      
      __LINE__ = 123;
      Runtime.assert( true,generator.next() === 6,"generator.next() === 6",123,'./yield_test.js' );
      
      __LINE__ = 124;
      Runtime.assert( true,generator.next() === 7,"generator.next() === 7",124,'./yield_test.js' );
      
      __LINE__ = 125;
      Runtime.assert( true,generator.next() === 8,"generator.next() === 8",125,'./yield_test.js' );
      
      __LINE__ = 126;
      Runtime.assert( true,generator.next() === 9,"generator.next() === 9",126,'./yield_test.js' );
      
      __LINE__ = 0;
      function yieldTest5(  ) {
        try {
          __LINE__ = 0;
          var _mochaIsNewBorn = true;
          
          __LINE__ = 0;
          var _yieldResult = undefined;
          
          __LINE__ = 0;
          var _yieldState = 0;
          
          __LINE__ = 129;
          var i;
          
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
                  
                  __LINE__ = 135;
                  while ( 1 ){
                    __LINE__ = 135;
                    switch ( _yieldState ) {
                      case 0 :
                        
                        __LINE__ = 129;
                        i = 0;
                      case 1 :
                        
                        __LINE__ = 0;
                        _yieldState = 2;
                        __LINE__ = 0;
                        return i;
                      case 2 :
                        
                        __LINE__ = 135;
                        if (  ++ i<10 ){
                          __LINE__ = 135;
                          _yieldState = 1;
                          __LINE__ = 0;
                          break;
                        } else {
                          __LINE__ = 135;
                          _yieldState = 3;
                        };
                      case 3 :
                      case -1 :
                        
                        __LINE__ = 0;
                        if ( _isYieldSafe ){
                          __LINE__ = 0;
                          return undefined;
                        } else {
                          __LINE__ = 135;
                          Runtime.throwException( StopIteration );
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
      };
      
      __LINE__ = 0;
      generator = yieldTest5();
      
      __LINE__ = 136;
      Runtime.assert( true,generator.next() === 0,"generator.next() === 0",136,'./yield_test.js' );
      
      __LINE__ = 137;
      Runtime.assert( true,generator.next() === 1,"generator.next() === 1",137,'./yield_test.js' );
      
      __LINE__ = 138;
      Runtime.assert( true,generator.next() === 2,"generator.next() === 2",138,'./yield_test.js' );
      
      __LINE__ = 139;
      Runtime.assert( true,generator.next() === 3,"generator.next() === 3",139,'./yield_test.js' );
      
      __LINE__ = 140;
      Runtime.assert( true,generator.next() === 4,"generator.next() === 4",140,'./yield_test.js' );
      
      __LINE__ = 141;
      Runtime.assert( true,generator.next() === 5,"generator.next() === 5",141,'./yield_test.js' );
      
      __LINE__ = 142;
      Runtime.assert( true,generator.next() === 6,"generator.next() === 6",142,'./yield_test.js' );
      
      __LINE__ = 143;
      Runtime.assert( true,generator.next() === 7,"generator.next() === 7",143,'./yield_test.js' );
      
      __LINE__ = 144;
      Runtime.assert( true,generator.next() === 8,"generator.next() === 8",144,'./yield_test.js' );
      
      __LINE__ = 145;
      Runtime.assert( true,generator.next() === 9,"generator.next() === 9",145,'./yield_test.js' );
      
      __LINE__ = 0;
      function yieldTest6(  ) {
        try {
          __LINE__ = 0;
          var _mochaIsNewBorn = true;
          
          __LINE__ = 0;
          var _yieldResult = undefined;
          
          __LINE__ = 0;
          var _yieldState = 0;
          
          __LINE__ = 149;
          var m;
          
          __LINE__ = 148;
          var i;
          
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
                  
                  __LINE__ = 160;
                  while ( 1 ){
                    __LINE__ = 160;
                    switch ( _yieldState ) {
                      case 0 :
                        
                        __LINE__ = 148;
                        i = 0;
                        
                        __LINE__ = 148;
                        if ( !( i<10 ) ){
                          __LINE__ = 160;
                          _yieldState = -1;
                          __LINE__ = 160;
                          break;
                        };
                      case 1 :
                        
                        __LINE__ = 149;
                        _yieldState = 2;
                        __LINE__ = 149;
                        return i;
                      case 2 :
                        
                        __LINE__ = 0;
                        _yieldResult = ( _isYieldSend && arguments.length>2 )?Runtime.toArray( arguments,2 )[0] : ( _isYieldSend )?i : undefined;
                        
                        __LINE__ = 149;
                        m = _yieldResult;
                        
                        __LINE__ = 150;
                        if ( m === true ){
                          __LINE__ = 160;
                          _yieldState = 3;
                          __LINE__ = 0;
                          break;
                        } else {
                          __LINE__ = 160;
                          _yieldState = 5;
                          __LINE__ = 0;
                          break;
                        };
                      case 3 :
                        
                        __LINE__ = 0;
                        _yieldState = 4;
                        __LINE__ = 0;
                        return i+1;
                      case 4 :
                        
                        __LINE__ = 0;
                        _yieldState = 9;
                        __LINE__ = 0;
                        break;
                      case 5 :
                        
                        __LINE__ = 152;
                        if ( m === false ){
                          __LINE__ = 160;
                          _yieldState = 6;
                          __LINE__ = 0;
                          break;
                        } else {
                          __LINE__ = 160;
                          _yieldState = 8;
                          __LINE__ = 0;
                          break;
                        };
                      case 6 :
                        
                        __LINE__ = 0;
                        _yieldState = 7;
                        __LINE__ = 0;
                        return i-1;
                      case 7 :
                        
                        __LINE__ = 0;
                        _yieldState = 9;
                        __LINE__ = 0;
                        break;
                      case 8 :
                        
                        __LINE__ = 0;
                        _yieldState = 9;
                        __LINE__ = 0;
                        return i;
                      case 9 :
                        
                        __LINE__ = 0;
                        i ++ ;
                        
                        __LINE__ = 160;
                        if ( i<10 ){
                          __LINE__ = 160;
                          _yieldState = 1;
                          __LINE__ = 0;
                          break;
                        } else {
                          __LINE__ = 160;
                          _yieldState = -1;
                        };
                      case -1 :
                        
                        __LINE__ = 0;
                        if ( _isYieldSafe ){
                          __LINE__ = 0;
                          return undefined;
                        } else {
                          __LINE__ = 160;
                          Runtime.throwException( StopIteration );
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
      };
      
      __LINE__ = 0;
      generator = yieldTest6();
      
      __LINE__ = 161;
      Runtime.assert( true,generator.next() === 0,"generator.next() === 0",161,'./yield_test.js' );
      
      __LINE__ = 162;
      Runtime.assert( true,generator.send( true ) === 1,"generator.send( true ) === 1",162,'./yield_test.js' );
      
      __LINE__ = 163;
      Runtime.assert( true,generator.send( false ) === 1,"generator.send( false ) === 1",163,'./yield_test.js' );
      
      __LINE__ = 164;
      Runtime.assert( true,generator.send( true ) === 2,"generator.send( true ) === 2",164,'./yield_test.js' );
      
      __LINE__ = 165;
      Runtime.assert( true,generator.send( false ) === 2,"generator.send( false ) === 2",165,'./yield_test.js' );
      
      __LINE__ = 166;
      Runtime.assert( true,generator.send( true ) === 3,"generator.send( true ) === 3",166,'./yield_test.js' );
      
      __LINE__ = 167;
      Runtime.assert( true,generator.send( true ) === 3,"generator.send( true ) === 3",167,'./yield_test.js' );
      
      __LINE__ = 168;
      Runtime.assert( true,generator.send( true ) === 4,"generator.send( true ) === 4",168,'./yield_test.js' );
      
      __LINE__ = 169;
      Runtime.assert( true,generator.send( false ) === 4,"generator.send( false ) === 4",169,'./yield_test.js' );
      
      __LINE__ = 170;
      Runtime.assert( true,generator.send( true ) === 5,"generator.send( true ) === 5",170,'./yield_test.js' );
      
      __LINE__ = 0;
      function yieldTest7(  ) {
        try {
          __LINE__ = 0;
          var _mochaIsNewBorn = true;
          
          __LINE__ = 0;
          var _yieldResult = undefined;
          
          __LINE__ = 0;
          var _yieldState = 0;
          
          __LINE__ = 175;
          var j;
          
          __LINE__ = 174;
          var m;
          
          __LINE__ = 173;
          var i;
          
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
                  
                  __LINE__ = 188;
                  while ( 1 ){
                    __LINE__ = 188;
                    switch ( _yieldState ) {
                      case 0 :
                        
                        __LINE__ = 173;
                        i = 0;
                        
                        __LINE__ = 173;
                        if ( !( i<10 ) ){
                          __LINE__ = 188;
                          _yieldState = -1;
                          __LINE__ = 188;
                          break;
                        };
                      case 1 :
                        
                        __LINE__ = 174;
                        _yieldState = 2;
                        __LINE__ = 174;
                        return i;
                      case 2 :
                        
                        __LINE__ = 0;
                        _yieldResult = ( _isYieldSend && arguments.length>2 )?Runtime.toArray( arguments,2 )[0] : ( _isYieldSend )?i : undefined;
                        
                        __LINE__ = 174;
                        m = _yieldResult;
                        
                        __LINE__ = 175;
                        j = 0;
                        
                        __LINE__ = 175;
                        if ( !( j<10 ) ){
                          __LINE__ = 188;
                          _yieldState = 11;
                          __LINE__ = 188;
                          break;
                        };
                      case 3 :
                        
                        __LINE__ = 176;
                        if ( m === true ){
                          __LINE__ = 188;
                          _yieldState = 4;
                          __LINE__ = 0;
                          break;
                        } else {
                          __LINE__ = 188;
                          _yieldState = 6;
                          __LINE__ = 0;
                          break;
                        };
                      case 4 :
                        
                        __LINE__ = 0;
                        _yieldState = 5;
                        __LINE__ = 0;
                        return j*2;
                      case 5 :
                        
                        __LINE__ = 0;
                        _yieldState = 10;
                        __LINE__ = 0;
                        break;
                      case 6 :
                        
                        __LINE__ = 178;
                        if ( m === false ){
                          __LINE__ = 188;
                          _yieldState = 7;
                          __LINE__ = 0;
                          break;
                        } else {
                          __LINE__ = 188;
                          _yieldState = 9;
                          __LINE__ = 0;
                          break;
                        };
                      case 7 :
                        
                        __LINE__ = 0;
                        _yieldState = 8;
                        __LINE__ = 0;
                        return j/2;
                      case 8 :
                        
                        __LINE__ = 0;
                        _yieldState = 10;
                        __LINE__ = 0;
                        break;
                      case 9 :
                        
                        __LINE__ = 0;
                        _yieldState = 10;
                        __LINE__ = 0;
                        return j;
                      case 10 :
                        
                        __LINE__ = 0;
                        j ++ ;
                        
                        __LINE__ = 188;
                        if ( j<10 ){
                          __LINE__ = 188;
                          _yieldState = 3;
                          __LINE__ = 0;
                          break;
                        } else {
                          __LINE__ = 188;
                          _yieldState = 11;
                        };
                      case 11 :
                        
                        __LINE__ = 0;
                        i ++ ;
                        
                        __LINE__ = 188;
                        if ( i<10 ){
                          __LINE__ = 188;
                          _yieldState = 1;
                          __LINE__ = 0;
                          break;
                        } else {
                          __LINE__ = 188;
                          _yieldState = -1;
                        };
                      case -1 :
                        
                        __LINE__ = 0;
                        if ( _isYieldSafe ){
                          __LINE__ = 0;
                          return undefined;
                        } else {
                          __LINE__ = 188;
                          Runtime.throwException( StopIteration );
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
      };
      
      __LINE__ = 0;
      generator = yieldTest7();
      
      __LINE__ = 189;
      Runtime.assert( true,generator.next() === 0,"generator.next() === 0",189,'./yield_test.js' );
      
      __LINE__ = 190;
      Runtime.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",190,'./yield_test.js' );
      
      __LINE__ = 191;
      Runtime.assert( true,generator.send( false ) === 2,"generator.send( false ) === 2",191,'./yield_test.js' );
      
      __LINE__ = 192;
      Runtime.assert( true,generator.send( true ) === 4,"generator.send( true ) === 4",192,'./yield_test.js' );
      
      __LINE__ = 193;
      Runtime.assert( true,generator.send( false ) === 6,"generator.send( false ) === 6",193,'./yield_test.js' );
      
      __LINE__ = 194;
      Runtime.assert( true,generator.send( true ) === 8,"generator.send( true ) === 8",194,'./yield_test.js' );
      
      __LINE__ = 195;
      Runtime.assert( true,generator.send( true ) === 10,"generator.send( true ) === 10",195,'./yield_test.js' );
      
      __LINE__ = 196;
      Runtime.assert( true,generator.send( true ) === 12,"generator.send( true ) === 12",196,'./yield_test.js' );
      
      __LINE__ = 197;
      Runtime.assert( true,generator.send( false ) === 14,"generator.send( false ) === 14",197,'./yield_test.js' );
      
      __LINE__ = 198;
      Runtime.assert( true,generator.send( true ) === 16,"generator.send( true ) === 16",198,'./yield_test.js' );
      
      __LINE__ = 199;
      Runtime.assert( true,generator.send( true ) === 18,"generator.send( true ) === 18",199,'./yield_test.js' );
      
      __LINE__ = 200;
      Runtime.assert( true,generator.send( false ) === 1,"generator.send( false ) === 1",200,'./yield_test.js' );
      
      __LINE__ = 201;
      Runtime.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",201,'./yield_test.js' );
      
      __LINE__ = 202;
      Runtime.assert( true,generator.send( false ) === 2,"generator.send( false ) === 2",202,'./yield_test.js' );
      
      __LINE__ = 203;
      Runtime.assert( true,generator.send( true ) === 4,"generator.send( true ) === 4",203,'./yield_test.js' );
      
      __LINE__ = 204;
      Runtime.assert( true,generator.send( true ) === 6,"generator.send( true ) === 6",204,'./yield_test.js' );
      
      __LINE__ = 205;
      Runtime.assert( true,generator.send( true ) === 8,"generator.send( true ) === 8",205,'./yield_test.js' );
      
      __LINE__ = 206;
      Runtime.assert( true,generator.send( false ) === 10,"generator.send( false ) === 10",206,'./yield_test.js' );
      
      __LINE__ = 207;
      Runtime.assert( true,generator.send( true ) === 12,"generator.send( true ) === 12",207,'./yield_test.js' );
      
      __LINE__ = 0;
      function yieldTest8(  ) {
        try {
          __LINE__ = 0;
          var _mochaIsNewBorn = true;
          
          __LINE__ = 0;
          var _yieldResult = undefined;
          
          __LINE__ = 0;
          var _yieldState = 0;
          
          __LINE__ = 213;
          var m;
          
          __LINE__ = 212;
          var j;
          
          __LINE__ = 211;
          var i;
          
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
                  
                  __LINE__ = 226;
                  while ( 1 ){
                    __LINE__ = 226;
                    switch ( _yieldState ) {
                      case 0 :
                        
                        __LINE__ = 211;
                        i = 0;
                        
                        __LINE__ = 211;
                        if ( !( i<10 ) ){
                          __LINE__ = 226;
                          _yieldState = -1;
                          __LINE__ = 226;
                          break;
                        };
                      case 1 :
                        
                        __LINE__ = 212;
                        j = 0;
                        
                        __LINE__ = 212;
                        if ( !( j<10 ) ){
                          __LINE__ = 226;
                          _yieldState = 11;
                          __LINE__ = 226;
                          break;
                        };
                      case 2 :
                        
                        __LINE__ = 213;
                        _yieldState = 3;
                        __LINE__ = 213;
                        return i;
                      case 3 :
                        
                        __LINE__ = 0;
                        _yieldResult = ( _isYieldSend && arguments.length>2 )?Runtime.toArray( arguments,2 )[0] : ( _isYieldSend )?i : undefined;
                        
                        __LINE__ = 213;
                        m = _yieldResult;
                        
                        __LINE__ = 214;
                        if ( m === true ){
                          __LINE__ = 226;
                          _yieldState = 4;
                          __LINE__ = 0;
                          break;
                        } else {
                          __LINE__ = 226;
                          _yieldState = 6;
                          __LINE__ = 0;
                          break;
                        };
                      case 4 :
                        
                        __LINE__ = 0;
                        _yieldState = 5;
                        __LINE__ = 0;
                        return j*2;
                      case 5 :
                        
                        __LINE__ = 0;
                        _yieldState = 10;
                        __LINE__ = 0;
                        break;
                      case 6 :
                        
                        __LINE__ = 216;
                        if ( m === false ){
                          __LINE__ = 226;
                          _yieldState = 7;
                          __LINE__ = 0;
                          break;
                        } else {
                          __LINE__ = 226;
                          _yieldState = 9;
                          __LINE__ = 0;
                          break;
                        };
                      case 7 :
                        
                        __LINE__ = 0;
                        _yieldState = 8;
                        __LINE__ = 0;
                        return j/2;
                      case 8 :
                        
                        __LINE__ = 0;
                        _yieldState = 10;
                        __LINE__ = 0;
                        break;
                      case 9 :
                        
                        __LINE__ = 0;
                        _yieldState = 10;
                        __LINE__ = 0;
                        return j;
                      case 10 :
                        
                        __LINE__ = 0;
                        j ++ ;
                        
                        __LINE__ = 226;
                        if ( j<10 ){
                          __LINE__ = 226;
                          _yieldState = 2;
                          __LINE__ = 0;
                          break;
                        } else {
                          __LINE__ = 226;
                          _yieldState = 11;
                        };
                      case 11 :
                        
                        __LINE__ = 0;
                        i ++ ;
                        
                        __LINE__ = 226;
                        if ( i<10 ){
                          __LINE__ = 226;
                          _yieldState = 1;
                          __LINE__ = 0;
                          break;
                        } else {
                          __LINE__ = 226;
                          _yieldState = -1;
                        };
                      case -1 :
                        
                        __LINE__ = 0;
                        if ( _isYieldSafe ){
                          __LINE__ = 0;
                          return undefined;
                        } else {
                          __LINE__ = 226;
                          Runtime.throwException( StopIteration );
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
      };
      
      __LINE__ = 0;
      generator = yieldTest8();
      
      __LINE__ = 227;
      Runtime.assert( true,generator.next() === 0,"generator.next() === 0",227,'./yield_test.js' );
      
      __LINE__ = 228;
      Runtime.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",228,'./yield_test.js' );
      
      __LINE__ = 229;
      Runtime.assert( true,generator.send( false ) === 0,"generator.send( false ) === 0",229,'./yield_test.js' );
      
      __LINE__ = 230;
      Runtime.assert( true,generator.send( true ) === 2,"generator.send( true ) === 2",230,'./yield_test.js' );
      
      __LINE__ = 231;
      Runtime.assert( true,generator.send( false ) === 0,"generator.send( false ) === 0",231,'./yield_test.js' );
      
      __LINE__ = 232;
      Runtime.assert( true,generator.send( true ) === 4,"generator.send( true ) === 4",232,'./yield_test.js' );
      
      __LINE__ = 233;
      Runtime.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",233,'./yield_test.js' );
      
      __LINE__ = 234;
      Runtime.assert( true,generator.send( true ) === 6,"generator.send( true ) === 6",234,'./yield_test.js' );
      
      __LINE__ = 235;
      Runtime.assert( true,generator.send( false ) === 0,"generator.send( false ) === 0",235,'./yield_test.js' );
      
      __LINE__ = 236;
      Runtime.assert( true,generator.send( true ) === 8,"generator.send( true ) === 8",236,'./yield_test.js' );
      
      __LINE__ = 237;
      Runtime.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",237,'./yield_test.js' );
      
      __LINE__ = 238;
      Runtime.assert( true,generator.send( false ) === 2.5,"generator.send( false ) === 2.5",238,'./yield_test.js' );
      
      __LINE__ = 239;
      Runtime.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",239,'./yield_test.js' );
      
      __LINE__ = 240;
      Runtime.assert( true,generator.send( false ) === 3,"generator.send( false ) === 3",240,'./yield_test.js' );
      
      __LINE__ = 241;
      Runtime.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",241,'./yield_test.js' );
      
      __LINE__ = 242;
      Runtime.assert( true,generator.send( true ) === 14,"generator.send( true ) === 14",242,'./yield_test.js' );
      
      __LINE__ = 243;
      Runtime.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",243,'./yield_test.js' );
      
      __LINE__ = 244;
      Runtime.assert( true,generator.send( false ) === 4,"generator.send( false ) === 4",244,'./yield_test.js' );
      
      __LINE__ = 245;
      Runtime.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",245,'./yield_test.js' );
      
      __LINE__ = 0;
      function yieldTest9(  ) {
        try {
          __LINE__ = 0;
          var _mochaIsNewBorn = true;
          
          __LINE__ = 0;
          var _yieldResult = undefined;
          
          __LINE__ = 0;
          var _yieldState = 0;
          
          __LINE__ = 0;
          var _mochaFinallyCache;
          
          __LINE__ = 0;
          var _mochaCatchCache;
          
          __LINE__ = 251;
          var m;
          
          __LINE__ = 249;
          var i;
          
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
                  
                  __LINE__ = 260;
                  while ( 1 ){
                    try {
                      __LINE__ = 260;
                      switch ( _yieldState ) {
                        case 0 :
                          
                          __LINE__ = 249;
                          i = 0;
                          
                          __LINE__ = 249;
                          if ( !( i<10 ) ){
                            __LINE__ = 260;
                            _yieldState = -1;
                            __LINE__ = 260;
                            break;
                          };
                        case 1 :
                          
                          __LINE__ = 0;
                          _yieldState = 2;
                          
                          __LINE__ = 254;
                          _mochaCatchCache = function ( e ) {
                            try {
                              __LINE__ = 260;
                              _yieldState = 3;
                            } catch( e ){
                              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                            }
                          };
                          
                          __LINE__ = 0;
                          _mochaFinallyCache = function (  ) {
                            try {
                              __LINE__ = 0;
                              return i;
                            } catch( e ){
                              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                            }
                          };
                          
                          __LINE__ = 251;
                          m = 0;
                          __LINE__ = 0;
                          return m;
                        case 2 :
                          
                          __LINE__ = 0;
                          ddddd();
                          
                          __LINE__ = 0;
                          _mochaCatchCache = undefined;
                          
                          __LINE__ = 0;
                          _mochaFinallyCache = undefined;
                        case 3 :
                          
                          __LINE__ = 0;
                          i ++ ;
                          
                          __LINE__ = 260;
                          if ( i<10 ){
                            __LINE__ = 260;
                            _yieldState = 1;
                            __LINE__ = 0;
                            break;
                          } else {
                            __LINE__ = 260;
                            _yieldState = -1;
                          };
                        case -1 :
                          
                          __LINE__ = 0;
                          if ( _isYieldSafe ){
                            __LINE__ = 0;
                            return undefined;
                          } else {
                            __LINE__ = 260;
                            Runtime.throwException( StopIteration );
                          };
                          
                      };
                    } catch( _mochaException ){
                      __LINE__ = 0;
                      if ( _mochaCatchCache ){
                        __LINE__ = 0;
                        var _mochaLocalTmp0 = _mochaCatchCache( _mochaException );
                        
                        __LINE__ = 0;
                        if ( _mochaLocalTmp0 !== undefined ){
                          __LINE__ = 0;
                          return _mochaLocalTmp0;
                        };
                      } else {
                        __LINE__ = 0;
                        Runtime.throwException( _mochaException );
                      };
                    } finally {
                      __LINE__ = 0;
                      if ( _mochaFinallyCache ){
                        __LINE__ = 0;
                        var _mochaLocalTmp1 = _mochaFinallyCache(  );
                        
                        __LINE__ = 0;
                        if ( _mochaLocalTmp1 !== undefined ){
                          __LINE__ = 0;
                          return _mochaLocalTmp1;
                        };
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
              
              __LINE__ = 0;
              if ( _mochaFinallyCache ){
                __LINE__ = 0;
                _mochaFinallyCache(  );
              };
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          },this);
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      };
      
      __LINE__ = 0;
      generator = yieldTest9();
      
      __LINE__ = 261;
      Runtime.assert( true,generator.next() === 0,"generator.next() === 0",261,'./yield_test.js' );
      
      __LINE__ = 262;
      Runtime.assert( true,generator.next() === 0,"generator.next() === 0",262,'./yield_test.js' );
      
      __LINE__ = 263;
      Runtime.assert( true,generator.next() === 0,"generator.next() === 0",263,'./yield_test.js' );
      
      __LINE__ = 264;
      Runtime.assert( true,generator.next() === 1,"generator.next() === 1",264,'./yield_test.js' );
      
      __LINE__ = 265;
      Runtime.assert( true,generator.next() === 0,"generator.next() === 0",265,'./yield_test.js' );
      
      __LINE__ = 266;
      Runtime.assert( true,generator.next() === 2,"generator.next() === 2",266,'./yield_test.js' );
    } catch( e ){
      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  })();
})();
