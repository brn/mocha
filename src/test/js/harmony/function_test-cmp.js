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
      var __FILE__ = "/var/samba/mocha/src/test/js/harmony/function_test.js",
          __LINE__ = 0;
      __LINE__ = 2;
      _mochaGlobalExport['./function_test.js'] = {};
      
      __LINE__ = 3;
      var _mochaGlobalAlias = _mochaGlobalExport['./function_test.js'];
      
      __LINE__ = 1;
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
              return function () {
                try {
                  __LINE__ = 3;
                  return console.log( 1 );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          function testDeclHasFormalWithContext() {
            try {
              __LINE__ = 4;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }.bind( this )
          function testDeclNonForamlWithContext() {
            try {
              __LINE__ = 5;
              return function () {
                try {
                  __LINE__ = 5;
                  return console.log( 1 );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }.bind( this );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }.bind( this )
          function testConstFunctionHasBlockHasFormal() {
            try {
              __LINE__ = 8;
              console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          function testConstFunctionHasForaml() {
            try {
              __LINE__ = 11;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          function testConstFunctionNonFormal() {
            try {
              __LINE__ = 12;
              return function () {
                try {
                  __LINE__ = 12;
                  return console.log( 1 );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          function testConstFunctionHasFormalWithContext() {
            try {
              __LINE__ = 14;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }.bind( this )
          function testConstFunctionWithContext() {
            try {
              __LINE__ = 15;
              return function () {
                try {
                  __LINE__ = 15;
                  return console.log( 1 );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }.bind( this );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }.bind( this )
          __LINE__ = 17;
          function testHasFormalHasBlock(  ) {
            try {
              __LINE__ = 18;
              console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 20;
          function testHasFormal(  ) {
            try {
              __LINE__ = 20;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 21;
          function test() {
            try {
              __LINE__ = 21;
              return function () {
                try {
                  __LINE__ = 21;
                  return console.log( 1 );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 23;
          function testHasFormalHasBlockWithContext(  ) {
            try {
              __LINE__ = 24;
              console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }.bind( this );
          
          __LINE__ = 26;
          function testHasFormalWithContext(  ) {
            try {
              __LINE__ = 26;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }.bind( this );
          
          __LINE__ = 27;
          function testWithContext() {
            try {
              __LINE__ = 27;
              return function () {
                try {
                  __LINE__ = 27;
                  return console.log( 1 );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }.bind( this );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }.bind( this );
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      })();
      
      __LINE__ = 30;
      ( function () {
        try {
          function testDeclHasFormal( args,args2,args3 ) {
            try {
              __LINE__ = 32;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          function testDeclHasFormalDsta( _mochaLocalTmp0,_mochaLocalTmp1,_mochaLocalTmp2 ) {
            try {
              __LINE__ = 0;
              var args = _mochaLocalTmp0.args,
                  args2 = ( _mochaLocalTmp1.tmp && _mochaLocalTmp1.tmp["args2"] )?_mochaLocalTmp1.tmp["args2"] : undefined,
                  args3 = _mochaLocalTmp2[0],
                  args4 = _mochaLocalTmp2[1],
                  args5 = ( _mochaLocalTmp2[2] && _mochaLocalTmp2[2].args5 )?_mochaLocalTmp2[2].args5 : undefined,
                  args7 = ( _mochaLocalTmp2[2] && _mochaLocalTmp2[2].args6 && _mochaLocalTmp2[2].args6.args7 )?_mochaLocalTmp2[2].args6.args7 : undefined;
              __LINE__ = 33;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          function testDeclHasFormalWithContext( args,args2,args3 ) {
            try {
              __LINE__ = 34;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }.bind( this )
          function testDeclHasFormalDstaWithContext( _mochaLocalTmp3,_mochaLocalTmp4,_mochaLocalTmp5 ) {
            try {
              __LINE__ = 0;
              var args = _mochaLocalTmp3.args,
                  args2 = ( _mochaLocalTmp4.tmp && _mochaLocalTmp4.tmp["args2"] )?_mochaLocalTmp4.tmp["args2"] : undefined,
                  args3 = _mochaLocalTmp5[0],
                  args4 = _mochaLocalTmp5[1],
                  args5 = ( _mochaLocalTmp5[2] && _mochaLocalTmp5[2].args5 )?_mochaLocalTmp5[2].args5 : undefined,
                  args7 = ( _mochaLocalTmp5[2] && _mochaLocalTmp5[2].args6 && _mochaLocalTmp5[2].args6.args7 )?_mochaLocalTmp5[2].args6.args7 : undefined;
              __LINE__ = 35;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }.bind( this )
          function testConstFunctionHasBlockHasFormal( args,args2,args3 ) {
            try {
              __LINE__ = 37;
              console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          function testConstFunctionHasBlockHasFormalDsta( _mochaLocalTmp6,_mochaLocalTmp7,_mochaLocalTmp8 ) {
            try {
              __LINE__ = 0;
              var args = _mochaLocalTmp6.args,
                  args2 = ( _mochaLocalTmp7.tmp && _mochaLocalTmp7.tmp["args2"] )?_mochaLocalTmp7.tmp["args2"] : undefined,
                  args3 = _mochaLocalTmp8[0],
                  args4 = _mochaLocalTmp8[1],
                  args5 = ( _mochaLocalTmp8[2] && _mochaLocalTmp8[2].args5 )?_mochaLocalTmp8[2].args5 : undefined,
                  args7 = ( _mochaLocalTmp8[2] && _mochaLocalTmp8[2].args6 && _mochaLocalTmp8[2].args6.args7 )?_mochaLocalTmp8[2].args6.args7 : undefined;
              
              __LINE__ = 40;
              console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          function testConstFunctionHasForaml( args,args2,args3 ) {
            try {
              __LINE__ = 43;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          function testConstFunctionHasForamlDsta( _mochaLocalTmp9,_mochaLocalTmp10,_mochaLocalTmp11 ) {
            try {
              __LINE__ = 0;
              var args = _mochaLocalTmp9.args,
                  args2 = ( _mochaLocalTmp10.tmp && _mochaLocalTmp10.tmp["args2"] )?_mochaLocalTmp10.tmp["args2"] : undefined,
                  args3 = _mochaLocalTmp11[0],
                  args4 = _mochaLocalTmp11[1],
                  args5 = ( _mochaLocalTmp11[2] && _mochaLocalTmp11[2].args5 )?_mochaLocalTmp11[2].args5 : undefined,
                  args7 = ( _mochaLocalTmp11[2] && _mochaLocalTmp11[2].args6 && _mochaLocalTmp11[2].args6.args7 )?_mochaLocalTmp11[2].args6.args7 : undefined;
              __LINE__ = 44;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          function testConstFunctionHasFormalWithContext( args,args2,args3 ) {
            try {
              __LINE__ = 45;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }.bind( this )
          function testConstFunctionHasFormalDstaWithContext( _mochaLocalTmp12,_mochaLocalTmp13,_mochaLocalTmp14 ) {
            try {
              __LINE__ = 0;
              var args = _mochaLocalTmp12.args,
                  args2 = ( _mochaLocalTmp13.tmp && _mochaLocalTmp13.tmp["args2"] )?_mochaLocalTmp13.tmp["args2"] : undefined,
                  args3 = _mochaLocalTmp14[0],
                  args4 = _mochaLocalTmp14[1],
                  args5 = ( _mochaLocalTmp14[2] && _mochaLocalTmp14[2].args5 )?_mochaLocalTmp14[2].args5 : undefined,
                  args7 = ( _mochaLocalTmp14[2] && _mochaLocalTmp14[2].args6 && _mochaLocalTmp14[2].args6.args7 )?_mochaLocalTmp14[2].args6.args7 : undefined;
              __LINE__ = 46;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }.bind( this )
          __LINE__ = 48;
          function testHasFormalHasBlock( args,args2,args3 ) {
            try {
              __LINE__ = 49;
              console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 51;
          function testHasFormalDstaHasBlock( _mochaLocalTmp15,_mochaLocalTmp16,_mochaLocalTmp17 ) {
            try {
              __LINE__ = 0;
              var args = _mochaLocalTmp15.args,
                  args2 = ( _mochaLocalTmp16.tmp && _mochaLocalTmp16.tmp["args2"] )?_mochaLocalTmp16.tmp["args2"] : undefined,
                  args3 = _mochaLocalTmp17[0],
                  args4 = _mochaLocalTmp17[1],
                  args5 = ( _mochaLocalTmp17[2] && _mochaLocalTmp17[2].args5 )?_mochaLocalTmp17[2].args5 : undefined,
                  args7 = ( _mochaLocalTmp17[2] && _mochaLocalTmp17[2].args6 && _mochaLocalTmp17[2].args6.args7 )?_mochaLocalTmp17[2].args6.args7 : undefined,
                  args8 = Runtime.toArray( arguments,3 );
              
              __LINE__ = 52;
              console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 54;
          function testHasFormal( args,args2,args3 ) {
            try {
              __LINE__ = 54;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 55;
          function testHasFormalDsta( _mochaLocalTmp18,_mochaLocalTmp19,_mochaLocalTmp20 ) {
            try {
              __LINE__ = 0;
              var args = _mochaLocalTmp18.args,
                  args2 = ( _mochaLocalTmp19.tmp && _mochaLocalTmp19.tmp["args2"] )?_mochaLocalTmp19.tmp["args2"] : undefined,
                  args3 = _mochaLocalTmp20[0],
                  args4 = _mochaLocalTmp20[1],
                  args5 = ( _mochaLocalTmp20[2] && _mochaLocalTmp20[2].args5 )?_mochaLocalTmp20[2].args5 : undefined,
                  args7 = ( _mochaLocalTmp20[2] && _mochaLocalTmp20[2].args6 && _mochaLocalTmp20[2].args6.args7 )?_mochaLocalTmp20[2].args6.args7 : undefined,
                  args8 = Runtime.toArray( arguments,3 );
              __LINE__ = 55;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 56;
          function testHasFormalHasBlockWithContext( args,args2,args3 ) {
            try {
              __LINE__ = 57;
              console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }.bind( this );
          
          __LINE__ = 59;
          function testHasFormalDstaHasBlockWithContext( _mochaLocalTmp21,_mochaLocalTmp22,_mochaLocalTmp23 ) {
            try {
              __LINE__ = 0;
              var args = _mochaLocalTmp21.args,
                  args2 = ( _mochaLocalTmp22.tmp && _mochaLocalTmp22.tmp["args2"] )?_mochaLocalTmp22.tmp["args2"] : undefined,
                  args3 = _mochaLocalTmp23[0],
                  args4 = _mochaLocalTmp23[1],
                  args5 = ( _mochaLocalTmp23[2] && _mochaLocalTmp23[2].args5 )?_mochaLocalTmp23[2].args5 : undefined,
                  args7 = ( _mochaLocalTmp23[2] && _mochaLocalTmp23[2].args6 && _mochaLocalTmp23[2].args6.args7 )?_mochaLocalTmp23[2].args6.args7 : undefined,
                  args8 = Runtime.toArray( arguments,3 );
              
              __LINE__ = 60;
              console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }.bind( this );
          
          __LINE__ = 62;
          function testHasFormalWithContext( args,args2,args3 ) {
            try {
              __LINE__ = 62;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }.bind( this );
          
          __LINE__ = 63;
          function testHasFormalDstaWithContext( _mochaLocalTmp24,_mochaLocalTmp25,_mochaLocalTmp26 ) {
            try {
              __LINE__ = 0;
              var args = _mochaLocalTmp24.args,
                  args2 = ( _mochaLocalTmp25.tmp && _mochaLocalTmp25.tmp["args2"] )?_mochaLocalTmp25.tmp["args2"] : undefined,
                  args3 = _mochaLocalTmp26[0],
                  args4 = _mochaLocalTmp26[1],
                  args5 = ( _mochaLocalTmp26[2] && _mochaLocalTmp26[2].args5 )?_mochaLocalTmp26[2].args5 : undefined,
                  args7 = ( _mochaLocalTmp26[2] && _mochaLocalTmp26[2].args6 && _mochaLocalTmp26[2].args6.args7 )?_mochaLocalTmp26[2].args6.args7 : undefined,
                  args8 = Runtime.toArray( arguments,3 );
              __LINE__ = 63;
              return console.log( 1 );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }.bind( this );
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      })();
    } catch( e ){
      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  })();
})();
