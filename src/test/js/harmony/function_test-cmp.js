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
        
        var _uid = +( new Date() );
        
        var getUid = _mochaLocalExport.getUid = function getUid() {
              return _uid ++ ;
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
      var __FILE__ = "/var/samba/mocha/src/test/js/harmony/function_test.js",
          __LINE__ = 0;
      __LINE__ = 2;
      _mochaGlobalExport['./function_test.js'] = {};
      
      __LINE__ = 3;
      var _mochaGlobalAlias = _mochaGlobalExport['./function_test.js'];
      
      __LINE__ = 0;
      ( function () {
        try {
          function testDeclHasFormal() {
            try {
              __LINE__ = 2;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          function testDeclNonFormal() {
            try {
              __LINE__ = 3;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          __LINE__ = 0;
          var _mochaLocalTmp0 = this;
          
          function testDeclHasFormalWithContext() {
            try {
              __LINE__ = 4;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          __LINE__ = 0;
          var _mochaLocalTmp1 = this;
          
          function testDeclNonForamlWithContext() {
            try {
              __LINE__ = 5;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          function testConstFunctionHasBlockHasFormal() {
            try {
              __LINE__ = 0;
              console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          __LINE__ = 11;
          var contextTest = function () {
                try {
                  __LINE__ = 11;
                  return console.log( this );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }.bind( this );
          
          function testConstFunctionHasForaml() {
            try {
              __LINE__ = 13;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          function testConstFunctionNonFormal() {
            try {
              __LINE__ = 14;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          __LINE__ = 0;
          var _mochaLocalTmp2 = this;
          
          function testConstFunctionHasFormalWithContext() {
            try {
              __LINE__ = 16;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          __LINE__ = 0;
          var _mochaLocalTmp3 = this;
          
          function testConstFunctionWithContext() {
            try {
              __LINE__ = 17;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          __LINE__ = 0;
          function testHasFormalHasBlock(  ) {
            try {
              __LINE__ = 0;
              console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          function testHasFormal(  ) {
            try {
              __LINE__ = 22;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          function test() {
            try {
              __LINE__ = 23;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          
          function testHasFormalHasBlockWithContext(  ) {
            try {
              __LINE__ = 0;
              console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          
          function testHasFormalWithContext(  ) {
            try {
              __LINE__ = 28;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          
          function testWithContext() {
            try {
              __LINE__ = 29;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      })();
      
      __LINE__ = 0;
      ( function () {
        try {
          function testDeclHasFormal( args,args2,args3 ) {
            try {
              __LINE__ = 34;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          function testDeclHasFormalDsta( _mochaLocalTmp7,_mochaLocalTmp8,_mochaLocalTmp9 ) {
            try {
              __LINE__ = 0;
              var args = _mochaLocalTmp7.args,
                  args2 = _mochaLocalTmp8.tmp && _mochaLocalTmp8.tmp["args2"]?_mochaLocalTmp8.tmp["args2"] : undefined,
                  args3 = _mochaLocalTmp9[0],
                  args4 = _mochaLocalTmp9[1],
                  args5 = _mochaLocalTmp9[2] && _mochaLocalTmp9[2].args5?_mochaLocalTmp9[2].args5 : undefined,
                  args7 = _mochaLocalTmp9[2] && _mochaLocalTmp9[2].args6 && _mochaLocalTmp9[2].args6.args7?_mochaLocalTmp9[2].args6.args7 : undefined;
              __LINE__ = 35;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          __LINE__ = 0;
          var _mochaLocalTmp10 = this;
          
          function testDeclHasFormalWithContext( args,args2,args3 ) {
            try {
              __LINE__ = 36;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          __LINE__ = 0;
          var _mochaLocalTmp14 = this;
          
          function testDeclHasFormalDstaWithContext( _mochaLocalTmp11,_mochaLocalTmp12,_mochaLocalTmp13 ) {
            try {
              __LINE__ = 0;
              var args = _mochaLocalTmp11.args,
                  args2 = _mochaLocalTmp12.tmp && _mochaLocalTmp12.tmp["args2"]?_mochaLocalTmp12.tmp["args2"] : undefined,
                  args3 = _mochaLocalTmp13[0],
                  args4 = _mochaLocalTmp13[1],
                  args5 = _mochaLocalTmp13[2] && _mochaLocalTmp13[2].args5?_mochaLocalTmp13[2].args5 : undefined,
                  args7 = _mochaLocalTmp13[2] && _mochaLocalTmp13[2].args6 && _mochaLocalTmp13[2].args6.args7?_mochaLocalTmp13[2].args6.args7 : undefined;
              __LINE__ = 37;
              return console.log( _mochaLocalTmp14 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          function testConstFunctionHasBlockHasFormal( args,args2,args3 ) {
            try {
              __LINE__ = 0;
              console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          function testConstFunctionHasBlockHasFormalDsta( _mochaLocalTmp15,_mochaLocalTmp16,_mochaLocalTmp17 ) {
            try {
              __LINE__ = 0;
              var args = _mochaLocalTmp15.args,
                  args2 = _mochaLocalTmp16.tmp && _mochaLocalTmp16.tmp["args2"]?_mochaLocalTmp16.tmp["args2"] : undefined,
                  args3 = _mochaLocalTmp17[0],
                  args4 = _mochaLocalTmp17[1],
                  args5 = _mochaLocalTmp17[2] && _mochaLocalTmp17[2].args5?_mochaLocalTmp17[2].args5 : undefined,
                  args7 = _mochaLocalTmp17[2] && _mochaLocalTmp17[2].args6 && _mochaLocalTmp17[2].args6.args7?_mochaLocalTmp17[2].args6.args7 : undefined;
              
              __LINE__ = 0;
              console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          function testConstFunctionHasForaml( args,args2,args3 ) {
            try {
              __LINE__ = 45;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          function testConstFunctionHasForamlDsta( _mochaLocalTmp18,_mochaLocalTmp19,_mochaLocalTmp20 ) {
            try {
              __LINE__ = 0;
              var args = _mochaLocalTmp18.args,
                  args2 = _mochaLocalTmp19.tmp && _mochaLocalTmp19.tmp["args2"]?_mochaLocalTmp19.tmp["args2"] : undefined,
                  args3 = _mochaLocalTmp20[0],
                  args4 = _mochaLocalTmp20[1],
                  args5 = _mochaLocalTmp20[2] && _mochaLocalTmp20[2].args5?_mochaLocalTmp20[2].args5 : undefined,
                  args7 = _mochaLocalTmp20[2] && _mochaLocalTmp20[2].args6 && _mochaLocalTmp20[2].args6.args7?_mochaLocalTmp20[2].args6.args7 : undefined;
              __LINE__ = 46;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          __LINE__ = 0;
          var _mochaLocalTmp21 = this;
          
          function testConstFunctionHasFormalWithContext( args,args2,args3 ) {
            try {
              __LINE__ = 47;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          __LINE__ = 0;
          var _mochaLocalTmp25 = this;
          
          function testConstFunctionHasFormalDstaWithContext( _mochaLocalTmp22,_mochaLocalTmp23,_mochaLocalTmp24 ) {
            try {
              __LINE__ = 0;
              var args = _mochaLocalTmp22.args,
                  args2 = _mochaLocalTmp23.tmp && _mochaLocalTmp23.tmp["args2"]?_mochaLocalTmp23.tmp["args2"] : undefined,
                  args3 = _mochaLocalTmp24[0],
                  args4 = _mochaLocalTmp24[1],
                  args5 = _mochaLocalTmp24[2] && _mochaLocalTmp24[2].args5?_mochaLocalTmp24[2].args5 : undefined,
                  args7 = _mochaLocalTmp24[2] && _mochaLocalTmp24[2].args6 && _mochaLocalTmp24[2].args6.args7?_mochaLocalTmp24[2].args6.args7 : undefined;
              __LINE__ = 48;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          __LINE__ = 0;
          function testHasFormalHasBlock( args,args2,args3 ) {
            try {
              __LINE__ = 0;
              console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          function testHasFormalDstaHasBlock( _mochaLocalTmp26,_mochaLocalTmp27,_mochaLocalTmp28 ) {
            try {
              __LINE__ = 0;
              var args = _mochaLocalTmp26.args,
                  args2 = _mochaLocalTmp27.tmp && _mochaLocalTmp27.tmp["args2"]?_mochaLocalTmp27.tmp["args2"] : undefined,
                  args3 = _mochaLocalTmp28[0],
                  args4 = _mochaLocalTmp28[1],
                  args5 = _mochaLocalTmp28[2] && _mochaLocalTmp28[2].args5?_mochaLocalTmp28[2].args5 : undefined,
                  args7 = _mochaLocalTmp28[2] && _mochaLocalTmp28[2].args6 && _mochaLocalTmp28[2].args6.args7?_mochaLocalTmp28[2].args6.args7 : undefined,
                  args8 = Runtime.toArray( arguments,3 );
              
              __LINE__ = 0;
              console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          function testHasFormal( args,args2,args3 ) {
            try {
              __LINE__ = 56;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          function testHasFormalDsta( _mochaLocalTmp29,_mochaLocalTmp30,_mochaLocalTmp31 ) {
            try {
              __LINE__ = 0;
              var args = _mochaLocalTmp29.args,
                  args2 = _mochaLocalTmp30.tmp && _mochaLocalTmp30.tmp["args2"]?_mochaLocalTmp30.tmp["args2"] : undefined,
                  args3 = _mochaLocalTmp31[0],
                  args4 = _mochaLocalTmp31[1],
                  args5 = _mochaLocalTmp31[2] && _mochaLocalTmp31[2].args5?_mochaLocalTmp31[2].args5 : undefined,
                  args7 = _mochaLocalTmp31[2] && _mochaLocalTmp31[2].args6 && _mochaLocalTmp31[2].args6.args7?_mochaLocalTmp31[2].args6.args7 : undefined,
                  args8 = Runtime.toArray( arguments,3 );
              __LINE__ = 57;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          
          function testHasFormalHasBlockWithContext( args,args2,args3 ) {
            try {
              __LINE__ = 0;
              console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          
          function testHasFormalDstaHasBlockWithContext( _mochaLocalTmp33,_mochaLocalTmp34,_mochaLocalTmp35 ) {
            try {
              __LINE__ = 0;
              var args = _mochaLocalTmp33.args,
                  args2 = _mochaLocalTmp34.tmp && _mochaLocalTmp34.tmp["args2"]?_mochaLocalTmp34.tmp["args2"] : undefined,
                  args3 = _mochaLocalTmp35[0],
                  args4 = _mochaLocalTmp35[1],
                  args5 = _mochaLocalTmp35[2] && _mochaLocalTmp35[2].args5?_mochaLocalTmp35[2].args5 : undefined,
                  args7 = _mochaLocalTmp35[2] && _mochaLocalTmp35[2].args6 && _mochaLocalTmp35[2].args6.args7?_mochaLocalTmp35[2].args6.args7 : undefined,
                  args8 = Runtime.toArray( arguments,3 );
              
              __LINE__ = 0;
              console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          
          function testHasFormalWithContext( args,args2,args3 ) {
            try {
              __LINE__ = 64;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          
          function testHasFormalDstaWithContext( _mochaLocalTmp38,_mochaLocalTmp39,_mochaLocalTmp40 ) {
            try {
              __LINE__ = 0;
              var args = _mochaLocalTmp38.args,
                  args2 = _mochaLocalTmp39.tmp && _mochaLocalTmp39.tmp["args2"]?_mochaLocalTmp39.tmp["args2"] : undefined,
                  args3 = _mochaLocalTmp40[0],
                  args4 = _mochaLocalTmp40[1],
                  args5 = _mochaLocalTmp40[2] && _mochaLocalTmp40[2].args5?_mochaLocalTmp40[2].args5 : undefined,
                  args7 = _mochaLocalTmp40[2] && _mochaLocalTmp40[2].args6 && _mochaLocalTmp40[2].args6.args7?_mochaLocalTmp40[2].args6.args7 : undefined,
                  args8 = Runtime.toArray( arguments,3 );
              __LINE__ = 65;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      })();
    } catch( e ){
      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  })();
})();
