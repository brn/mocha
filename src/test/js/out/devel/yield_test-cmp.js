!function() {
  var __FILE__ = "Runtime",
      __LINE__ = 0;
  
  var _mochaGlobalExport = {};
  
  !function ( _mochaLocalTmp0,_mochaLocalTmp1,_mochaLocalTmp2,_mochaLocalTmp3 ) {
    function defineBuiltin( obj,name,value ) {
      return Object.defineProperty( obj,name, {
        value : value,
        configurable : true,
        enumerable : false,
        writable : true
      });
    }
    function callbackCheck( callback,type ) {
      
      Runtime.assert( true,typeof type === "string","typeof type === \"string\"",43,'./mocha_runtime.js' );
      
      typeof callback !== "function" && builtinTypeError( type+" : first argument is not callable" );
    }
    function builtinTypeError( message ) {
      try {
        throw new TypeError( message );
      } catch( e ){
        throw new Error( e );
      };
    }
    var stringProto = _mochaLocalTmp0.prototype,
        arrayProto = _mochaLocalTmp1.prototype,
        functionProto = _mochaLocalTmp2.prototype,
        dateProto = _mochaLocalTmp3.prototype;
    
    !Object.keys && ( Object.keys = function ( obj ) {
      !obj && builtinTypeError( "Object.keys : first arguments is null or not defined." );
      
      var ret = [],
          iter = -1;
      
      for ( var i in obj ){
        
        obj.hasOwnProperty( i ) && ( ret[ ++ iter] = obj[i] );
      };
      return ret;
    });
    
    !Object.preventExtensions && ( Object.preventExtensions = function ( o ) {
      return o;
    });
    
    !Object.seal && ( Object.seal = function ( o ) {
      return o;
    });
    
    !Object.freeze && ( Object.freeze = function ( o ) {
      return o;
    });
    
    var hasRealEcma5 = function () {
          var ret;
          
          try {
            var obj = {};
            
            Object.defineProperty( obj,"test", {
              configurable : false,
              writable : false,
              enumerable : false,
              value : 0
            });
            
            obj.test = 200;
            
            ret = ( obj.test === 200 )?false : true;
          } catch( e ){
            ret = false;
          };
          return ret;
        }();
    
    !hasRealEcma5 && ( Object.defineProperty = function ( obj,prop,valobj ) {
      "value" in valobj && ( obj[prop] = valobj.value );
    });
    
    if ( !stringProto.trim ){
      stringProto.trim = function () {
        return this.replace( stringProto.trim.rtrim,"" );
      };
      
      stringProto.trim.rtrim = /^\s*|\s*$/g;
    };
    
    !stringProto.repeat && defineBuiltin( stringProto,"repeat",
    function ( num ) {
      return Array( num+1 ).join( this.toString() );
    });
    
    !stringProto.startsWith && defineBuiltin( stringProto,"startsWith",
    function ( str ) {
      return !this.indexOf( str );
    });
    
    !stringProto.endsWith && defineBuiltin( stringProto,"endsWith",
    function ( str ) {
      var t = String( str ),
          index = this.lastIndexOf( t );
      return index >= 0 && index === this.length-t.length;
    });
    
    !stringProto.contains && defineBuiltin( stringProto,"contains",
    function ( str ) {
      return this.indexOf( str ) !== -1;
    });
    
    !stringProto.toArray && defineBuiltin( stringProto,"toArray",
    function ( str ) {
      return this.split( "" );
    });
    
    !functionProto.bind && defineBuiltin( functionProto,"bind",
    function () {
      var argArray = arrayProto.slice.call( arguments ),
          context = argArray.shift(),
          ret = function () {
            var args = argArray.concat( arrayProto.slice.call( arguments ) );
            return this !== null && this !== window && this instanceof ret?ret.context.apply( this,args ) : ret.context.apply( context,args );
          };
      
      ret.prototype = this.prototype;
      
      ret.context = this;
      return ret;
    });
    
    !arrayProto.forEach && defineBuiltin( arrayProto,"forEach",
    function ( callback,that ) {
      callbackCheck( callback,"Array.forEach" );
      
      var iter = -1,
          ta;
      
      this === null && builtinTypeError( "Array.forEach : this is null or not defined" );
      
      if ( that ){
        while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
          callback.call( that,ta,iter,this );
        };
      } else {
        while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
          callback( ta,iter,this );
        };
      };
    });
    
    !arrayProto.every && defineBuiltin( arrayProto,"every",
    function ( callback,that ) {
      callbackCheck( callback,"Array.every" );
      
      var iter = -1,
          ta;
      
      this === null && builtinTypeError( "Array.every : this is null or not defined" );
      
      if ( that ){
        while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
          if ( !( callback.call( that,ta,iter,this ) ) ){
            return false;
          };
        };
      } else {
        while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
          if ( !( callback( ta,iter,this ) ) ){
            return false;
          };
        };
      };
      return true;
    });
    
    !arrayProto.some && defineBuiltin( arrayProto,"some",
    function ( callback,that ) {
      callbackCheck( callback,"Array.some" );
      
      var iter = -1,
          ta;
      
      this === null && builtinTypeError( "Array.some : this is null or not defined" );
      
      if ( that ){
        while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
          if ( callback.call( that,ta,iter,this ) ){
            return true;
          };
        };
      } else {
        while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
          if ( callback( ta,iter,this ) ){
            return true;
          };
        };
      };
      return false;
    });
    
    !arrayProto.filter && defineBuiltin( arrayProto,"filter",
    function ( callback,that ) {
      callbackCheck( callback,"Array.filter" );
      
      var len = this.length,
          iter = -1,
          ret = [],
          ta;
      
      this === null && builtinTypeError( "Array.filter : this is null or not defined" );
      
      if ( that ){
        for ( var i = 0,len = this.length;i<len; ++ i ){
          
          ( ta = this[i] ) !== null && ta !== undefined && callback.call( that,ta,i,this ) && ( ret[ ++ iter] = ta );
        };
      } else {
        for ( var i = 0,len = this.length;i<len; ++ i ){
          
          ( ta = this[i] ) !== null && ta !== undefined && callback( ta,i,this ) && ( ret[ ++ iter] = ta );
        };
      };
      return ret;
    });
    
    !arrayProto.indexOf && defineBuiltin( arrayProto,"indexOf",
    function ( subject,fromIndex ) {
      var iter = ( fromIndex )?fromIndex-1 : -1,
          index = -1,
          ta;
      
      this === null && builtinTypeError( "Array.indexOf : this is null or not defined." );
      
      while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
        if ( ta === subject ){
          index = iter;
          break;
        };
      };
      return index;
    });
    
    !arrayProto.lastIndexOf && defineBuiltin( arrayProto,"lastIndexOf",
    function ( target,fromIndex ) {
      var len = this.length,
          iter = ( fromIndex )?fromIndex+1 : len,
          index = -1,
          ta;
      
      this === null && builtinTypeError( "Array.lastIndexOf : this is null or not defined." );
      
      while ( ( ta = this[ -- iter] ) !== null && ta !== undefined ){
        if ( ta === target ){
          index = iter;
          break;
        };
      };
      return index;
    });
    
    !arrayProto.map && defineBuiltin( arrayProto,"map",
    function ( callback,that ) {
      callbackCheck( callback,"Array.map" );
      
      var ret = [],
          iter = -1,
          len = this.length,
          i = 0,
          ta;
      
      this === null && builtinTypeError( "Array.map : this is null or not defined." );
      
      if ( that ){
        for ( i;i<len; ++ i ){
          ( ta = this[i] ) !== null && ta !== undefined && ( ret[ ++ iter] = callback.call( that,ta,i,this ) );
        };
      } else {
        for ( i;i<len; ++ i ){
          ( ta = this[i] ) !== null && ta !== undefined && ( ret[ ++ iter] = callback( ta,i,this ) );
        };
      };
      return ret;
    });
    
    !arrayProto.reduce && defineBuiltin( arrayProto,"reduce",
    function ( callback,initial ) {
      callbackCheck( callback,"Array.reduce" );
      
      var ret = initial || this[0],
          i = ( initial )?0 : 1,
          len = this.length,
          ta;
      
      ( len === 0 || len === null ) && arguments.length<2 && builtinTypeError( "Array length is 0 and no second argument" );
      
      for ( i;i<len; ++ i ){
        ( ta = this[i] ) !== null && ta !== undefined && ( ret = callback( ret,ta,i,this ) );
      };
      return ret;
    });
    
    !arrayProto.reduceRight && defineBuiltin( arrayProto,"reduceRight",
    function ( callback,initial ) {
      callbackCheck( callback,"Array.reduceRight" );
      
      var len = this.length,
          ret = initial || this[len-1],
          i = ( initial )?len-1 : len-2,
          ta;
      
      ( len === 0 || len === null ) && arguments.length<2 && builtinTypeError( "Array length is 0 and no second argument" );
      
      for ( i;i>-1; -- i ){
        ( ta = this[i] ) !== null && ta !== undefined && ( ret = callback( ret,ta,i,this ) );
      };
      return ret;
    });
    
    !dateProto.toJSON && defineBuiltin( dateProto,"toJSON",
    function () {
      var _mochaLocalTmp4 = [this.getUTCMonth(),this.getUTCDate(),this.getUTCHours(),this.getMinutes(),this.getSeconds()],
          month = _mochaLocalTmp4[0],
          date = _mochaLocalTmp4[1],
          hour = _mochaLocalTmp4[2],
          minute = _mochaLocalTmp4[3],
          second = _mochaLocalTmp4[4];
      return '"'+this.getUTCFullYear()+'-'+( month>8?month+1 : "0"+( month+1 ) )+'-'+( date>9?date : "0"+date )+'T'+( hour>9?hour : "0"+hour )+':'+( minute>9?minute : "0"+minute )+':'+( second>9?second : "0"+second )+'.'+this.getUTCMilliseconds()+'Z"';
    });
    
    !Date.now && defineBuiltin( Date,"now",
    function () {
      return +new Date();
    });
    
    !Array.isArray && defineBuiltin( Array,"isArray",
    function ( arr ) {
      if ( arguments.length === 0 ){
        return false;
      };
      return ( arr )?( {} ).toString.call( arr ) === "[object Array]" : false;
    });
  }.call( this,String,Array,Function,Date );
  
  var Runtime = function () {
        function checkRequirements( _mochaLocalTmp10,_mochaLocalTmp11,traits,file,line ) {
          var proto1 = _mochaLocalTmp10.prototype,
              proto2 = _mochaLocalTmp11.prototype;
          
          for ( var i = 0,len = traits.length;i<len;i ++  ){
            var _mochaLocalTmp12 = traits[i],
                _mochaRequires = _mochaLocalTmp12._mochaRequires;
            
            for ( var prop in _mochaRequires ){
              
              !( prop in proto1 ) && !( prop in proto2 ) && Runtime.throwException( "Class dose not meet the traits requirement. traits require implementation of property "+prop+"\nin file "+file+" at line "+line );
            };
          };
        }
        function classMixin( _mochaLocalTmp7,_mochaLocalTmp8,_mochaLocalTmp9,with_,without ) {
          var constructorProto = _mochaLocalTmp7.prototype,
              privateProto = _mochaLocalTmp8.prototype,
              mark = _mochaLocalTmp9._mochaTraitMark,
              traitPublic = _mochaLocalTmp9._mochaTraitPublic,
              traitPrivate = _mochaLocalTmp9._mochaTraitPrivate;
          
          if ( !mark ){
            Runtime.throwException( "mixin only used for trait." );
          } else {
            var tmp;
            
            for ( var i in traitPublic ){
              if ( !without[i] ){
                tmp = ( !with_[i] )?i : with_[i];
                
                constructorProto[tmp] = traitPublic[i];
              };
            };
            
            for ( i in traitPrivate ){
              if ( !without[i] ){
                tmp = ( !with_[i] )?i : with_[i];
                
                privateProto[tmp] = traitPrivate[i];
              };
            };
          };
        }
        function traitMixin( dest,source,with_,without ) {
          if ( !dest._mochaTraitMark || !source._mochaTraitMark ){
            Runtime.throwException( "mixin only used for trait." );
          } else {
            var destTraitPrivate = dest._mochaTraitPrivate,
                sourceTraitPrivate = source._mochaTraitPrivate,
                destTraitPublic = dest._mochaTraitPublic,
                sourceTraitPublic = source._mochaTraitPublic,
                sourceRequires = source._mochaRequires,
                destRequires = dest._mochaRequires,
                tmp;
            
            for ( var i in sourceTraitPrivate ){
              if ( !without[i] ){
                tmp = ( !with_[i] )?i : with_[i];
                
                destTraitPrivate[tmp] = sourceTraitPrivate[i];
              };
            };
            
            for ( i in sourceTraitPublic ){
              if ( !without[i] ){
                tmp = ( !with_[i] )?i : with_[i];
                
                destTraitPublic[tmp] = sourceTraitPublic[i];
              };
            };
            
            for ( i in sourceRequires ){
              destRequires[i] = sourceRequires[i];
            };
          };
        }
        function getSuper( obj ) {
          var type = typeof obj,
              ret;
          
          if ( type === "function" ){
            ret = function (){};
            
            ret.prototype = obj.prototype;
            
            ret = new ret();
            
            obj.__harmony_class__?ret.constructor = obj.constructor : ret.constructor = obj;
            return ret;
          };
          return ret;
        }
        function initializeClass( instance,classObject,privateHolder,constructor,args,name,line ) {
          ( !instance || !( instance instanceof classObject ) ) && throwException( "class "+name+" must be called by new. line : "+line );
          
          createPrivateRecord( instance,privateHolder );
          
          constructor.apply( instance,args );
        }
        function isStopIteration( obj ) {
          return obj === StopIteration || rstopIteration.test( obj );
        }
        function hasIterator( obj ) {
          return __ref_iterator__ in obj;
        }
        function getIterator( obj ) {
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
              
              result === undefined && throwStopIteration();
              return result;
            });
          } else {
            return {};
          };
          
          !( "__nothrowNext__" in ret ) && createUnenumProp( newObj,"__nothrowNext__",ret.next.bind( ret ) );
          
          for ( var prop in ret ){
            
            prop !== "next" && prop !== "__nothrowNext__" && ( newObj[prop] = ret[prop] );
          };
          
          !( "toString" in ret ) && createUnenumProp( newObj,"toString",
          function () {
            return "[object Iterator]";
          });
          return newObj;
        }
        function isGenerator( obj ) {
          return obj instanceof Generator;
        }
        function throwStopIteration() {
          try {
            throw StopIteration;
          } catch( e ){
            throw new Error( e.toString() );
          };
        }
        function createRecord( obj ) {
          obj.toString() === "[object Object]" && createUnenumProp( obj,"toString",
          function () {
            return "[object Record]";
          });
          return Object.freeze( obj );
        }
        function createTuple( obj,size ) {
          createUnenumProp( obj,"length",size );
          
          createUnenumProp( obj,"equal",compareTuple );
          
          createUnenumProp( obj,"toArray",tupleToArray );
          
          createUnenumProp( obj,"toString",
          function () {
            return "[object Tuple]";
          });
          return Object.freeze( obj );
        }
        function tupleToArray() {
          return [].slice.call( this );
        }
        function compareTuple( tuple ) {
          var maxIndex = max( tuple.length,this.length ),
              i = -1;
          
          while (  ++ i<maxIndex && tuple[i] === this[i] ){
            
          };
          return maxIndex === i;
        }
        function extend( dest,source ) {
          for ( var prop in source ){
            
            dest[prop] = source[prop];
          };
          return dest;
        }
        function getErrorMessage( e ) {
          return ( e.message )?e.message : ( e.description )?e.description : e.toString();
        }
        function createGenerator( generatorFn,closeFn,context ) {
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
        }
        function Generator(  ){}
        function toArray( likeArray,index ) {
          return ( likeArray )?slice.call( likeArray,index ) : [];
        }
        function constant( obj,prop,value ) {
          return Object.defineProperty( obj,prop, {
            configurable : false,
            enumerable : false,
            writable : false,
            value : value
          });
        }
        function createUnenumProp( obj,prop,value ) {
          return Object.defineProperty( obj,prop, {
            configurable : true,
            enumerable : false,
            writable : true,
            value : value
          });
        }
        function Exception( line,file,e ) {
          this.toString = function () {
            return Runtime.getErrorMessage( e )+" in file "+file+" at : "+line;
          };
        }
        var _mochaLocalExport = {};
        
        var _mochaLocalTmp5 = Math,
            max = _mochaLocalTmp5.max,
            _mochaLocalTmp6 = Array.prototype,
            slice = _mochaLocalTmp6.slice,
            Runtime =  {
              getErrorMessage : function getErrorMessage( e ) {
                return ( e.message )?e.message : ( e.description )?e.description : e.toString();
              },
              exceptionHandler : function exceptionHandler( line,file,e ) {
                isStopIteration( e )?this.throwException( e ) : this.throwException( new Exception( line,file,e ) );
              },
              throwException : function throwException( exception ) {
                try {
                  throw exception;
                } catch( e ){
                  if ( isStopIteration( e ) ){
                    throw new Error( e );
                  };
                  throw new Error( this.getErrorMessage( e ) );
                };
              },
              hasProto : "__proto__" in {}
            };
        
        _mochaLocalExport.createUnenumProp = createUnenumProp;
        
        _mochaLocalExport.constant = constant;
        
        _mochaLocalExport.toArray = toArray;
        
        _mochaLocalExport.createGenerator = createGenerator;
        
        var throwException = _mochaLocalExport.throwException = Runtime.throwException.bind( Runtime ),
            exceptionHandler = _mochaLocalExport.exceptionHandler = Runtime.exceptionHandler.bind( Runtime );
        
        _mochaLocalExport.extend = extend;
        
        _mochaLocalExport.createTuple = createTuple;
        
        _mochaLocalExport.createRecord = createRecord;
        
        var extendPrototype = _mochaLocalExport.extendPrototype = function ( derived,base ) {
              derived.prototype = base;
            },
            getPrototype = ( "getPrototypeOf" in Object )?function ( obj ) {
              return Object.getPrototypeOf( obj );
            } : function ( obj ) {
              var ret = {};
              
              for ( var i in obj ){
                
                !obj.hasOwnProperty( i ) && ( ret[i] = obj[i] );
              };
              return ret;
            },
            extendClass = _mochaLocalExport.extendClass = ( Runtime.hasProto )?function ( derived,base ) {
              if ( typeof base === 'function' ){
                derived.prototype.__proto__ = base.prototype;
                
                for ( var i in base ){
                  
                  derived[i] = base[i];
                };
              } else {
                derived.prototype.__proto__ = base.__proto__;
              };
            } : function ( derived,base ) {
              var baseType = typeof base;
              
              if ( baseType === "function" ){
                var inherit = function (){};
                
                inherit.prototype = base.prototype;
                
                derived.prototype = new inherit;
                
                for ( var i in base ){
                  
                  derived[i] = base[i];
                };
              } else {
                var inherit = function (){},
                    proto = getPrototype( base );
                
                inherit.prototype = proto;
                
                derived.prototype = new inherit;
              };
            },
            __ref_iterator__ = _mochaLocalExport.__ref_iterator__ = "__mocha_iterator_special_key__";
        
        _mochaLocalExport.throwStopIteration = throwStopIteration;
        
        _mochaLocalExport.isGenerator = isGenerator;
        
        _mochaLocalExport.getIterator = getIterator;
        
        _mochaLocalExport.hasIterator = hasIterator;
        
        var rstopIteration = /StopIteration/;
        
        _mochaLocalExport.isStopIteration = isStopIteration;
        
        var privateRecord,
            createPrivateRecord,
            getPrivateRecord;
        
        if ( "WeakMap" in window ){
          privateRecord = new WeakMap();
          
          createPrivateRecord = function ( self,privateHolder ) {
            var holder = new privateHolder;
            
            createUnenumProp( holder.constructor,"__is_private__",1 );
            
            privateRecord.set( self,holder );
          };
          
          getPrivateRecord = function ( self ) {
            if ( privateRecord.has( self ) ){
              return privateRecord.get( self );
            } else if ( self.constructor === "__is_private__" ){
              return self;
            };
          };
        } else {
          createPrivateRecord = function ( self,privateHolder ) {
            if ( !self.__typeid__ ){
              var holder = new privateHolder;
              
              createUnenumProp( holder.constructor,"__is_private__",1 );
              
              createUnenumProp( self,"__private__",holder );
            };
          };
          
          getPrivateRecord = function ( self ) {
            if ( self.__private__ ){
              return self.__private__;
            } else if ( self.constructor === "__is_private__" ){
              return self;
            };
          };
        };
        
        _mochaLocalExport.getPrivateRecord = getPrivateRecord;
        
        _mochaLocalExport.initializeClass = initializeClass;
        
        _mochaLocalExport.getSuper = getSuper;
        
        _mochaLocalExport.traitMixin = traitMixin;
        
        _mochaLocalExport.classMixin = classMixin;
        
        _mochaLocalExport.checkRequirements = checkRequirements;
        
        !function () {
          var assert = _mochaLocalExport.assert = ( console && console.assert )?function ( expect,exp,str,line,filename ) {
                return console.assert( expect === exp,"assertion failed : "+str+"\nexpect "+expect+" but got "+exp+"\nin file "+filename+" at : "+line );
              } : function ( expect,exp,str,line,filename ) {
                expect !== exp && Runtime.throwException( "assertion failed : "+str+"\nexpect "+expect+" but got "+exp+"\nin file "+filename+" at : "+line );
              };
        }();
        return _mochaLocalExport;
      }();
  
  !( "StopIteration" in window ) && ( window.StopIteration =  {
    toString : function toString() {
      return "[object StopIteration]";
    }
  });
  
  function Tuple(  ) {
    var args = Runtime.toArray( arguments,0 ),
        ret = {};
    
    ret.length = 0;
    
    [].push.apply( ret,args );
    
    Runtime.createTuple( ret,arguments.length );
    return ret;
  }
  function Record( member ) {
    return Runtime.createRecord( member );
  }
  __LINE__ = 0;
  !function () {
    try {
      var __FILE__ = "/Users/aono_taketoshi/github/mocha/src/test/js/harmony/yield_test.js",
          __LINE__ = 0;
      __LINE__ = 2;
      _mochaGlobalExport['./yield_test.js'] = {};
      
      __LINE__ = 3;
      var _mochaGlobalAlias = _mochaGlobalExport['./yield_test.js'],
          tests =  {
            case1 : function case1() {
              try {
                function yieldTest2(  ) {
                  try {
                    __LINE__ = 0;
                    var _mochaIsNewBorn = true,
                        _yieldResult = undefined,
                        _yieldState = 0,
                        i,
                        _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 0;
                            !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            
                            __LINE__ = 9;
                            while ( 1 ){
                              __LINE__ = 9;
                              switch ( _yieldState ) {
                                case 0 :
                                  
                                  __LINE__ = 4;
                                  i = 0;
                                  
                                  __LINE__ = 4;
                                  if ( !( i<10 ) ){
                                    __LINE__ = 9;
                                    _yieldState = -1;
                                    __LINE__ = 9;
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
                                  
                                  __LINE__ = 9;
                                  if ( i<10 ){
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
                                  };
                                  
                                  __LINE__ = 9;
                                  Runtime.throwStopIteration();
                                  
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
                }
                __LINE__ = 9;
                var generator = yieldTest2();
                
                __LINE__ = 11;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",11,'./yield_test.js' );
                
                __LINE__ = 12;
                Runtime.assert( true,generator.next() === 1,"generator.next() === 1",12,'./yield_test.js' );
                
                __LINE__ = 13;
                Runtime.assert( true,generator.next() === 2,"generator.next() === 2",13,'./yield_test.js' );
                
                __LINE__ = 14;
                Runtime.assert( true,generator.next() === 3,"generator.next() === 3",14,'./yield_test.js' );
                
                __LINE__ = 15;
                Runtime.assert( true,generator.next() === 4,"generator.next() === 4",15,'./yield_test.js' );
                
                __LINE__ = 16;
                Runtime.assert( true,generator.next() === 5,"generator.next() === 5",16,'./yield_test.js' );
                
                __LINE__ = 17;
                Runtime.assert( true,generator.next() === 6,"generator.next() === 6",17,'./yield_test.js' );
                
                __LINE__ = 18;
                Runtime.assert( true,generator.next() === 7,"generator.next() === 7",18,'./yield_test.js' );
                
                __LINE__ = 19;
                Runtime.assert( true,generator.next() === 8,"generator.next() === 8",19,'./yield_test.js' );
                
                __LINE__ = 20;
                Runtime.assert( true,generator.next() === 9,"generator.next() === 9",20,'./yield_test.js' );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case2 : function case2() {
              try {
                function yieldTest3(  ) {
                  try {
                    __LINE__ = 0;
                    var _mochaIsNewBorn = true,
                        _yieldResult = undefined,
                        _yieldState = 0,
                        i,
                        _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 0;
                            !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            
                            __LINE__ = 31;
                            while ( 1 ){
                              __LINE__ = 31;
                              switch ( _yieldState ) {
                                case 0 :
                                  
                                  __LINE__ = 25;
                                  i = 0;
                                  
                                  __LINE__ = 25;
                                  if ( !( i<10 ) ){
                                    __LINE__ = 31;
                                    _yieldState = -1;
                                    __LINE__ = 31;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 26;
                                  if ( i%2 === 0 ){
                                    __LINE__ = 31;
                                    _yieldState = 2;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 31;
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
                                  
                                  __LINE__ = 31;
                                  if ( i<10 ){
                                    __LINE__ = 31;
                                    _yieldState = 1;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 31;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 0;
                                  if ( _isYieldSafe ){
                                    __LINE__ = 0;
                                    return undefined;
                                  };
                                  
                                  __LINE__ = 31;
                                  Runtime.throwStopIteration();
                                  
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
                }
                __LINE__ = 0;
                generator = yieldTest3();
                
                __LINE__ = 32;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",32,'./yield_test.js' );
                
                __LINE__ = 33;
                Runtime.assert( true,generator.next() === 2,"generator.next() === 2",33,'./yield_test.js' );
                
                __LINE__ = 34;
                Runtime.assert( true,generator.next() === 4,"generator.next() === 4",34,'./yield_test.js' );
                
                __LINE__ = 35;
                Runtime.assert( true,generator.next() === 6,"generator.next() === 6",35,'./yield_test.js' );
                
                __LINE__ = 36;
                Runtime.assert( true,generator.next() === 8,"generator.next() === 8",36,'./yield_test.js' );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case3 : function case3() {
              try {
                function yieldTest4(  ) {
                  try {
                    __LINE__ = 0;
                    var _mochaIsNewBorn = true,
                        _yieldResult = undefined,
                        _yieldState = 0,
                        j,
                        i,
                        _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 0;
                            !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            
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
                                  };
                                  
                                  __LINE__ = 48;
                                  Runtime.throwStopIteration();
                                  
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
                }
                __LINE__ = 0;
                generator = yieldTest4();
                
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
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case4 : function case4() {
              try {
                function yieldTest5(  ) {
                  try {
                    __LINE__ = 0;
                    var _mochaIsNewBorn = true,
                        _yieldResult = undefined,
                        _yieldState = 0,
                        i,
                        _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 0;
                            !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            
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
                                  };
                                  
                                  __LINE__ = 117;
                                  Runtime.throwStopIteration();
                                  
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
                }
                __LINE__ = 0;
                generator = yieldTest5();
                
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
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case5 : function case5() {
              try {
                function yieldTest6(  ) {
                  try {
                    __LINE__ = 0;
                    var _mochaIsNewBorn = true,
                        _yieldResult = undefined,
                        _yieldState = 0,
                        i,
                        _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 0;
                            !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            
                            __LINE__ = 136;
                            while ( 1 ){
                              __LINE__ = 136;
                              switch ( _yieldState ) {
                                case 0 :
                                  
                                  __LINE__ = 130;
                                  i = 0;
                                case 1 :
                                  
                                  __LINE__ = 0;
                                  _yieldState = 2;
                                  __LINE__ = 0;
                                  return i;
                                case 2 :
                                  
                                  __LINE__ = 136;
                                  if (  ++ i<10 ){
                                    __LINE__ = 136;
                                    _yieldState = 1;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 136;
                                    _yieldState = 3;
                                  };
                                case 3 :
                                case -1 :
                                  
                                  __LINE__ = 0;
                                  if ( _isYieldSafe ){
                                    __LINE__ = 0;
                                    return undefined;
                                  };
                                  
                                  __LINE__ = 136;
                                  Runtime.throwStopIteration();
                                  
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
                }
                __LINE__ = 0;
                generator = yieldTest6();
                
                __LINE__ = 137;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",137,'./yield_test.js' );
                
                __LINE__ = 138;
                Runtime.assert( true,generator.next() === 1,"generator.next() === 1",138,'./yield_test.js' );
                
                __LINE__ = 139;
                Runtime.assert( true,generator.next() === 2,"generator.next() === 2",139,'./yield_test.js' );
                
                __LINE__ = 140;
                Runtime.assert( true,generator.next() === 3,"generator.next() === 3",140,'./yield_test.js' );
                
                __LINE__ = 141;
                Runtime.assert( true,generator.next() === 4,"generator.next() === 4",141,'./yield_test.js' );
                
                __LINE__ = 142;
                Runtime.assert( true,generator.next() === 5,"generator.next() === 5",142,'./yield_test.js' );
                
                __LINE__ = 143;
                Runtime.assert( true,generator.next() === 6,"generator.next() === 6",143,'./yield_test.js' );
                
                __LINE__ = 144;
                Runtime.assert( true,generator.next() === 7,"generator.next() === 7",144,'./yield_test.js' );
                
                __LINE__ = 145;
                Runtime.assert( true,generator.next() === 8,"generator.next() === 8",145,'./yield_test.js' );
                
                __LINE__ = 146;
                Runtime.assert( true,generator.next() === 9,"generator.next() === 9",146,'./yield_test.js' );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case6 : function case6() {
              try {
                function yieldTest7(  ) {
                  try {
                    __LINE__ = 0;
                    var _mochaIsNewBorn = true,
                        _yieldResult = undefined,
                        _yieldState = 0,
                        m,
                        i,
                        _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 0;
                            !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            
                            __LINE__ = 162;
                            while ( 1 ){
                              __LINE__ = 162;
                              switch ( _yieldState ) {
                                case 0 :
                                  
                                  __LINE__ = 150;
                                  i = 0;
                                  
                                  __LINE__ = 150;
                                  if ( !( i<10 ) ){
                                    __LINE__ = 162;
                                    _yieldState = -1;
                                    __LINE__ = 162;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 151;
                                  _yieldState = 2;
                                  __LINE__ = 151;
                                  return i;
                                case 2 :
                                  
                                  __LINE__ = 0;
                                  _yieldResult = _isYieldSend && arguments.length>2?Runtime.toArray( arguments,2 )[0] : _isYieldSend?i : undefined;
                                  
                                  __LINE__ = 151;
                                  m = _yieldResult;
                                  
                                  __LINE__ = 152;
                                  if ( m === true ){
                                    __LINE__ = 162;
                                    _yieldState = 3;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 162;
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
                                  
                                  __LINE__ = 154;
                                  if ( m === false ){
                                    __LINE__ = 162;
                                    _yieldState = 6;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 162;
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
                                  
                                  __LINE__ = 162;
                                  if ( i<10 ){
                                    __LINE__ = 162;
                                    _yieldState = 1;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 162;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 0;
                                  if ( _isYieldSafe ){
                                    __LINE__ = 0;
                                    return undefined;
                                  };
                                  
                                  __LINE__ = 162;
                                  Runtime.throwStopIteration();
                                  
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
                }
                __LINE__ = 0;
                generator = yieldTest7();
                
                __LINE__ = 163;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",163,'./yield_test.js' );
                
                __LINE__ = 164;
                Runtime.assert( true,generator.send( true ) === 1,"generator.send( true ) === 1",164,'./yield_test.js' );
                
                __LINE__ = 165;
                Runtime.assert( true,generator.send( false ) === 1,"generator.send( false ) === 1",165,'./yield_test.js' );
                
                __LINE__ = 166;
                Runtime.assert( true,generator.send( true ) === 2,"generator.send( true ) === 2",166,'./yield_test.js' );
                
                __LINE__ = 167;
                Runtime.assert( true,generator.send( false ) === 2,"generator.send( false ) === 2",167,'./yield_test.js' );
                
                __LINE__ = 168;
                Runtime.assert( true,generator.send( true ) === 3,"generator.send( true ) === 3",168,'./yield_test.js' );
                
                __LINE__ = 169;
                Runtime.assert( true,generator.send( true ) === 3,"generator.send( true ) === 3",169,'./yield_test.js' );
                
                __LINE__ = 170;
                Runtime.assert( true,generator.send( true ) === 4,"generator.send( true ) === 4",170,'./yield_test.js' );
                
                __LINE__ = 171;
                Runtime.assert( true,generator.send( false ) === 4,"generator.send( false ) === 4",171,'./yield_test.js' );
                
                __LINE__ = 172;
                Runtime.assert( true,generator.send( true ) === 5,"generator.send( true ) === 5",172,'./yield_test.js' );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case7 : function case7() {
              try {
                function yieldTest8(  ) {
                  try {
                    __LINE__ = 0;
                    var _mochaIsNewBorn = true,
                        _yieldResult = undefined,
                        _yieldState = 0,
                        j,
                        m,
                        i,
                        _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 0;
                            !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            
                            __LINE__ = 191;
                            while ( 1 ){
                              __LINE__ = 191;
                              switch ( _yieldState ) {
                                case 0 :
                                  
                                  __LINE__ = 176;
                                  i = 0;
                                  
                                  __LINE__ = 176;
                                  if ( !( i<10 ) ){
                                    __LINE__ = 191;
                                    _yieldState = -1;
                                    __LINE__ = 191;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 177;
                                  _yieldState = 2;
                                  __LINE__ = 177;
                                  return i;
                                case 2 :
                                  
                                  __LINE__ = 0;
                                  _yieldResult = _isYieldSend && arguments.length>2?Runtime.toArray( arguments,2 )[0] : _isYieldSend?i : undefined;
                                  
                                  __LINE__ = 177;
                                  m = _yieldResult;
                                  
                                  __LINE__ = 178;
                                  j = 0;
                                  
                                  __LINE__ = 178;
                                  if ( !( j<10 ) ){
                                    __LINE__ = 191;
                                    _yieldState = 11;
                                    __LINE__ = 191;
                                    break;
                                  };
                                case 3 :
                                  
                                  __LINE__ = 179;
                                  if ( m === true ){
                                    __LINE__ = 191;
                                    _yieldState = 4;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 191;
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
                                  
                                  __LINE__ = 181;
                                  if ( m === false ){
                                    __LINE__ = 191;
                                    _yieldState = 7;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 191;
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
                                  
                                  __LINE__ = 191;
                                  if ( j<10 ){
                                    __LINE__ = 191;
                                    _yieldState = 3;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 191;
                                    _yieldState = 11;
                                  };
                                case 11 :
                                  
                                  __LINE__ = 0;
                                  i ++ ;
                                  
                                  __LINE__ = 191;
                                  if ( i<10 ){
                                    __LINE__ = 191;
                                    _yieldState = 1;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 191;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 0;
                                  if ( _isYieldSafe ){
                                    __LINE__ = 0;
                                    return undefined;
                                  };
                                  
                                  __LINE__ = 191;
                                  Runtime.throwStopIteration();
                                  
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
                }
                __LINE__ = 0;
                generator = yieldTest8();
                
                __LINE__ = 192;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",192,'./yield_test.js' );
                
                __LINE__ = 193;
                Runtime.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",193,'./yield_test.js' );
                
                __LINE__ = 194;
                Runtime.assert( true,generator.send( false ) === 2,"generator.send( false ) === 2",194,'./yield_test.js' );
                
                __LINE__ = 195;
                Runtime.assert( true,generator.send( true ) === 4,"generator.send( true ) === 4",195,'./yield_test.js' );
                
                __LINE__ = 196;
                Runtime.assert( true,generator.send( false ) === 6,"generator.send( false ) === 6",196,'./yield_test.js' );
                
                __LINE__ = 197;
                Runtime.assert( true,generator.send( true ) === 8,"generator.send( true ) === 8",197,'./yield_test.js' );
                
                __LINE__ = 198;
                Runtime.assert( true,generator.send( true ) === 10,"generator.send( true ) === 10",198,'./yield_test.js' );
                
                __LINE__ = 199;
                Runtime.assert( true,generator.send( true ) === 12,"generator.send( true ) === 12",199,'./yield_test.js' );
                
                __LINE__ = 200;
                Runtime.assert( true,generator.send( false ) === 14,"generator.send( false ) === 14",200,'./yield_test.js' );
                
                __LINE__ = 201;
                Runtime.assert( true,generator.send( true ) === 16,"generator.send( true ) === 16",201,'./yield_test.js' );
                
                __LINE__ = 202;
                Runtime.assert( true,generator.send( true ) === 18,"generator.send( true ) === 18",202,'./yield_test.js' );
                
                __LINE__ = 203;
                Runtime.assert( true,generator.send( false ) === 1,"generator.send( false ) === 1",203,'./yield_test.js' );
                
                __LINE__ = 204;
                Runtime.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",204,'./yield_test.js' );
                
                __LINE__ = 205;
                Runtime.assert( true,generator.send( false ) === 2,"generator.send( false ) === 2",205,'./yield_test.js' );
                
                __LINE__ = 206;
                Runtime.assert( true,generator.send( true ) === 4,"generator.send( true ) === 4",206,'./yield_test.js' );
                
                __LINE__ = 207;
                Runtime.assert( true,generator.send( true ) === 6,"generator.send( true ) === 6",207,'./yield_test.js' );
                
                __LINE__ = 208;
                Runtime.assert( true,generator.send( true ) === 8,"generator.send( true ) === 8",208,'./yield_test.js' );
                
                __LINE__ = 209;
                Runtime.assert( true,generator.send( false ) === 10,"generator.send( false ) === 10",209,'./yield_test.js' );
                
                __LINE__ = 210;
                Runtime.assert( true,generator.send( true ) === 12,"generator.send( true ) === 12",210,'./yield_test.js' );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case8 : function case8() {
              try {
                function yieldTest9(  ) {
                  try {
                    __LINE__ = 0;
                    var _mochaIsNewBorn = true,
                        _yieldResult = undefined,
                        _yieldState = 0,
                        m,
                        j,
                        i,
                        _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 0;
                            !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            
                            __LINE__ = 230;
                            while ( 1 ){
                              __LINE__ = 230;
                              switch ( _yieldState ) {
                                case 0 :
                                  
                                  __LINE__ = 215;
                                  i = 0;
                                  
                                  __LINE__ = 215;
                                  if ( !( i<10 ) ){
                                    __LINE__ = 230;
                                    _yieldState = -1;
                                    __LINE__ = 230;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 216;
                                  j = 0;
                                  
                                  __LINE__ = 216;
                                  if ( !( j<10 ) ){
                                    __LINE__ = 230;
                                    _yieldState = 11;
                                    __LINE__ = 230;
                                    break;
                                  };
                                case 2 :
                                  
                                  __LINE__ = 217;
                                  _yieldState = 3;
                                  __LINE__ = 217;
                                  return i;
                                case 3 :
                                  
                                  __LINE__ = 0;
                                  _yieldResult = _isYieldSend && arguments.length>2?Runtime.toArray( arguments,2 )[0] : _isYieldSend?i : undefined;
                                  
                                  __LINE__ = 217;
                                  m = _yieldResult;
                                  
                                  __LINE__ = 218;
                                  if ( m === true ){
                                    __LINE__ = 230;
                                    _yieldState = 4;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 230;
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
                                  
                                  __LINE__ = 220;
                                  if ( m === false ){
                                    __LINE__ = 230;
                                    _yieldState = 7;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 230;
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
                                  
                                  __LINE__ = 230;
                                  if ( j<10 ){
                                    __LINE__ = 230;
                                    _yieldState = 2;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 230;
                                    _yieldState = 11;
                                  };
                                case 11 :
                                  
                                  __LINE__ = 0;
                                  i ++ ;
                                  
                                  __LINE__ = 230;
                                  if ( i<10 ){
                                    __LINE__ = 230;
                                    _yieldState = 1;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 230;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 0;
                                  if ( _isYieldSafe ){
                                    __LINE__ = 0;
                                    return undefined;
                                  };
                                  
                                  __LINE__ = 230;
                                  Runtime.throwStopIteration();
                                  
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
                }
                __LINE__ = 0;
                generator = yieldTest9();
                
                __LINE__ = 231;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",231,'./yield_test.js' );
                
                __LINE__ = 232;
                Runtime.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",232,'./yield_test.js' );
                
                __LINE__ = 233;
                Runtime.assert( true,generator.send( false ) === 0,"generator.send( false ) === 0",233,'./yield_test.js' );
                
                __LINE__ = 234;
                Runtime.assert( true,generator.send( true ) === 2,"generator.send( true ) === 2",234,'./yield_test.js' );
                
                __LINE__ = 235;
                Runtime.assert( true,generator.send( false ) === 0,"generator.send( false ) === 0",235,'./yield_test.js' );
                
                __LINE__ = 236;
                Runtime.assert( true,generator.send( true ) === 4,"generator.send( true ) === 4",236,'./yield_test.js' );
                
                __LINE__ = 237;
                Runtime.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",237,'./yield_test.js' );
                
                __LINE__ = 238;
                Runtime.assert( true,generator.send( true ) === 6,"generator.send( true ) === 6",238,'./yield_test.js' );
                
                __LINE__ = 239;
                Runtime.assert( true,generator.send( false ) === 0,"generator.send( false ) === 0",239,'./yield_test.js' );
                
                __LINE__ = 240;
                Runtime.assert( true,generator.send( true ) === 8,"generator.send( true ) === 8",240,'./yield_test.js' );
                
                __LINE__ = 241;
                Runtime.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",241,'./yield_test.js' );
                
                __LINE__ = 242;
                Runtime.assert( true,generator.send( false ) === 2.5,"generator.send( false ) === 2.5",242,'./yield_test.js' );
                
                __LINE__ = 243;
                Runtime.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",243,'./yield_test.js' );
                
                __LINE__ = 244;
                Runtime.assert( true,generator.send( false ) === 3,"generator.send( false ) === 3",244,'./yield_test.js' );
                
                __LINE__ = 245;
                Runtime.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",245,'./yield_test.js' );
                
                __LINE__ = 246;
                Runtime.assert( true,generator.send( true ) === 14,"generator.send( true ) === 14",246,'./yield_test.js' );
                
                __LINE__ = 247;
                Runtime.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",247,'./yield_test.js' );
                
                __LINE__ = 248;
                Runtime.assert( true,generator.send( false ) === 4,"generator.send( false ) === 4",248,'./yield_test.js' );
                
                __LINE__ = 249;
                Runtime.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",249,'./yield_test.js' );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case9 : function case9() {
              try {
                function yieldTest10(  ) {
                  try {
                    __LINE__ = 0;
                    var _mochaIsNewBorn = true,
                        _yieldResult = undefined,
                        _yieldState = 0,
                        _mochaFinallyCache,
                        _mochaCatchCache,
                        m,
                        i,
                        flg,
                        _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 0;
                            !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            
                            __LINE__ = 266;
                            while ( 1 ){
                              try {
                                __LINE__ = 266;
                                switch ( _yieldState ) {
                                  case 0 :
                                    
                                    __LINE__ = 254;
                                    flg = false;
                                    
                                    __LINE__ = 255;
                                    i = 0;
                                    
                                    __LINE__ = 255;
                                    if ( !( i<10 ) ){
                                      __LINE__ = 266;
                                      _yieldState = -1;
                                      __LINE__ = 266;
                                      break;
                                    };
                                  case 1 :
                                    
                                    __LINE__ = 0;
                                    _yieldState = 2;
                                    
                                    __LINE__ = 260;
                                    _mochaCatchCache = function ( e ) {
                                      try {
                                        __LINE__ = 266;
                                        _yieldState = 3;
                                      } catch( e ){
                                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                                      }
                                    };
                                    
                                    __LINE__ = 0;
                                    _mochaFinallyCache = function (  ) {
                                      try {
                                        __LINE__ = 0;
                                        flg = true;
                                      } catch( e ){
                                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                                      }
                                    };
                                    
                                    __LINE__ = 257;
                                    m = ( flg )?1 : 0;
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
                                    
                                    __LINE__ = 266;
                                    if ( i<10 ){
                                      __LINE__ = 266;
                                      _yieldState = 1;
                                      __LINE__ = 0;
                                      break;
                                    } else {
                                      __LINE__ = 266;
                                      _yieldState = -1;
                                    };
                                  case -1 :
                                    
                                    __LINE__ = 0;
                                    if ( _isYieldSafe ){
                                      __LINE__ = 0;
                                      return undefined;
                                    };
                                    
                                    __LINE__ = 266;
                                    Runtime.throwStopIteration();
                                    
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
                        _mochaFinallyCache && _mochaFinallyCache(  );
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
                __LINE__ = 0;
                generator = yieldTest10();
                
                __LINE__ = 267;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",267,'./yield_test.js' );
                
                __LINE__ = 268;
                Runtime.assert( true,generator.next() === 1,"generator.next() === 1",268,'./yield_test.js' );
                
                __LINE__ = 269;
                Runtime.assert( true,generator.next() === 1,"generator.next() === 1",269,'./yield_test.js' );
                
                __LINE__ = 270;
                Runtime.assert( true,generator.next() === 1,"generator.next() === 1",270,'./yield_test.js' );
                
                __LINE__ = 271;
                Runtime.assert( true,generator.next() === 1,"generator.next() === 1",271,'./yield_test.js' );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case10 : function case10() {
              try {
                function yieldTest11(  ) {
                  try {
                    __LINE__ = 0;
                    var _mochaIsNewBorn = true,
                        _yieldResult = undefined,
                        _yieldState = 0,
                        type,
                        i,
                        _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 0;
                            !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            
                            __LINE__ = 289;
                            while ( 1 ){
                              __LINE__ = 289;
                              switch ( _yieldState ) {
                                case 0 :
                                  
                                  __LINE__ = 275;
                                  i = 0;
                                  
                                  __LINE__ = 275;
                                  if ( !( i<10 ) ){
                                    __LINE__ = 289;
                                    _yieldState = -1;
                                    __LINE__ = 289;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 276;
                                  _yieldState = 2;
                                  __LINE__ = 276;
                                  return ;
                                case 2 :
                                  
                                  __LINE__ = 0;
                                  _yieldResult = _isYieldSend && arguments.length>2?Runtime.toArray( arguments,2 )[0] : undefined;
                                  
                                  __LINE__ = 276;
                                  type = _yieldResult;
                                  
                                  __LINE__ = 0;
                                  switch ( type ) {
                                    case 0 :
                                      
                                      __LINE__ = 0;
                                      _yieldState = 3;
                                      __LINE__ = 0;
                                      break;
                                    case 2 :
                                      
                                      __LINE__ = 0;
                                      _yieldState = 4;
                                      __LINE__ = 0;
                                      break;
                                    case 3 :
                                      
                                      __LINE__ = 0;
                                      _yieldState = 5;
                                      __LINE__ = 0;
                                      break;
                                    default :
                                      
                                      __LINE__ = 0;
                                      _yieldState = 6;
                                      __LINE__ = 0;
                                      break;
                                      
                                  };
                                  __LINE__ = 0;
                                  break;
                                case 3 :
                                  
                                  __LINE__ = 0;
                                  _yieldState = 7;
                                  __LINE__ = 0;
                                  return 200;
                                case 4 :
                                  
                                  __LINE__ = 0;
                                  _yieldState = 7;
                                  __LINE__ = 0;
                                  return 400;
                                case 5 :
                                  
                                  __LINE__ = 0;
                                  _yieldState = 7;
                                  __LINE__ = 0;
                                  return 600;
                                case 6 :
                                  
                                  __LINE__ = 0;
                                  _yieldState = 7;
                                  __LINE__ = 0;
                                  return 700;
                                case 7 :
                                  
                                  __LINE__ = 0;
                                  i ++ ;
                                  
                                  __LINE__ = 289;
                                  if ( i<10 ){
                                    __LINE__ = 289;
                                    _yieldState = 1;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 289;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 0;
                                  if ( _isYieldSafe ){
                                    __LINE__ = 0;
                                    return undefined;
                                  };
                                  
                                  __LINE__ = 289;
                                  Runtime.throwStopIteration();
                                  
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
                }
                __LINE__ = 0;
                generator = yieldTest11();
                
                __LINE__ = 0;
                generator.next();
                
                __LINE__ = 291;
                Runtime.assert( true,generator.send( 0 ) === 200,"generator.send( 0 ) === 200",291,'./yield_test.js' );
                
                __LINE__ = 0;
                generator.next();
                
                __LINE__ = 293;
                Runtime.assert( true,generator.send( 2 ) === 400,"generator.send( 2 ) === 400",293,'./yield_test.js' );
                
                __LINE__ = 0;
                generator.next();
                
                __LINE__ = 295;
                Runtime.assert( true,generator.send( 3 ) === 600,"generator.send( 3 ) === 600",295,'./yield_test.js' );
                
                __LINE__ = 0;
                generator.next();
                
                __LINE__ = 297;
                Runtime.assert( true,generator.send( null ) === 700,"generator.send( null ) === 700",297,'./yield_test.js' );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case11 : function case11() {
              try {
                function yieldTest12(  ) {
                  try {
                    __LINE__ = 0;
                    var _mochaIsNewBorn = true,
                        _yieldResult = undefined,
                        _yieldState = 0,
                        type,
                        i,
                        _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 0;
                            !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            
                            __LINE__ = 320;
                            while ( 1 ){
                              __LINE__ = 320;
                              switch ( _yieldState ) {
                                case 0 :
                                  
                                  __LINE__ = 302;
                                  i = 0;
                                  
                                  __LINE__ = 302;
                                  if ( !( i<15 ) ){
                                    __LINE__ = 320;
                                    _yieldState = -1;
                                    __LINE__ = 320;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 303;
                                  _yieldState = 2;
                                  __LINE__ = 303;
                                  return ;
                                case 2 :
                                  
                                  __LINE__ = 0;
                                  _yieldResult = _isYieldSend && arguments.length>2?Runtime.toArray( arguments,2 )[0] : undefined;
                                  
                                  __LINE__ = 303;
                                  type = _yieldResult;
                                  
                                  __LINE__ = 0;
                                  switch ( type ) {
                                    case 4 :
                                    case 0 :
                                      
                                      __LINE__ = 0;
                                      _yieldState = 3;
                                      __LINE__ = 0;
                                      break;
                                    case 5 :
                                      
                                      __LINE__ = 0;
                                      _yieldState = 7;
                                      __LINE__ = 0;
                                      break;
                                    case 6 :
                                    case 2 :
                                      
                                      __LINE__ = 0;
                                      _yieldState = 4;
                                      __LINE__ = 0;
                                      break;
                                    case 3 :
                                      
                                      __LINE__ = 0;
                                      _yieldState = 5;
                                      __LINE__ = 0;
                                      break;
                                    default :
                                      
                                      __LINE__ = 0;
                                      _yieldState = 6;
                                      __LINE__ = 0;
                                      break;
                                      
                                  };
                                  __LINE__ = 0;
                                  break;
                                case 3 :
                                  
                                  __LINE__ = 0;
                                  _yieldState = 8;
                                  __LINE__ = 0;
                                  return 200;
                                case 4 :
                                  
                                  __LINE__ = 0;
                                  _yieldState = 8;
                                  __LINE__ = 0;
                                  return 400;
                                case 5 :
                                  
                                  __LINE__ = 0;
                                  _yieldState = 8;
                                  __LINE__ = 0;
                                  return 600;
                                case 6 :
                                  
                                  __LINE__ = 0;
                                  _yieldState = 8;
                                  __LINE__ = 0;
                                  return 700;
                                case 7 :
                                  
                                  __LINE__ = 0;
                                  _yieldState = 8;
                                  __LINE__ = 0;
                                  break;
                                case 8 :
                                  
                                  __LINE__ = 0;
                                  i ++ ;
                                  
                                  __LINE__ = 320;
                                  if ( i<15 ){
                                    __LINE__ = 320;
                                    _yieldState = 1;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 320;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 0;
                                  if ( _isYieldSafe ){
                                    __LINE__ = 0;
                                    return undefined;
                                  };
                                  
                                  __LINE__ = 320;
                                  Runtime.throwStopIteration();
                                  
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
                }
                __LINE__ = 0;
                generator = yieldTest12();
                
                __LINE__ = 0;
                generator.next();
                
                __LINE__ = 322;
                Runtime.assert( true,generator.send( 0 ) === 200,"generator.send( 0 ) === 200",322,'./yield_test.js' );
                
                __LINE__ = 0;
                generator.next();
                
                __LINE__ = 324;
                Runtime.assert( true,generator.send( 4 ) === 200,"generator.send( 4 ) === 200",324,'./yield_test.js' );
                
                __LINE__ = 0;
                generator.next();
                
                __LINE__ = 326;
                Runtime.assert( true,generator.send( 2 ) === 400,"generator.send( 2 ) === 400",326,'./yield_test.js' );
                
                __LINE__ = 0;
                generator.next();
                
                __LINE__ = 328;
                Runtime.assert( true,generator.send( 5 ) === undefined,"generator.send( 5 ) === undefined",328,'./yield_test.js' );
                
                __LINE__ = 329;
                Runtime.assert( true,generator.send( 3 ) === 600,"generator.send( 3 ) === 600",329,'./yield_test.js' );
                
                __LINE__ = 0;
                generator.next();
                
                __LINE__ = 331;
                Runtime.assert( true,generator.send( null ) === 700,"generator.send( null ) === 700",331,'./yield_test.js' );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case12 : function case12() {
              try {
                function yieldTest13() {
                  try {
                    __LINE__ = 0;
                    var _mochaIsNewBorn = true,
                        _yieldResult = undefined,
                        _yieldState = 0,
                        length,
                        _mochaLocalTmp4,
                        i,
                        obj,
                        _mochaLocalTmp3 = [],
                        _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 0;
                            !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            
                            __LINE__ = 342;
                            while ( 1 ){
                              __LINE__ = 342;
                              switch ( _yieldState ) {
                                case 0 :
                                  
                                  __LINE__ = 336;
                                  obj =  {
                                    x : 200,
                                    y : 300,
                                    z : 400
                                  };
                                  
                                  __LINE__ = 337;
                                  for ( var _mochaLocalTmp2 in obj ){
                                    
                                    __LINE__ = 342;
                                    _mochaLocalTmp3.push( _mochaLocalTmp2 );
                                  };
                                  
                                  __LINE__ = 337;
                                  _mochaLocalTmp4 = 0;
                                  
                                  __LINE__ = 337;
                                  length = _mochaLocalTmp3.length;
                                  
                                  __LINE__ = 337;
                                  if ( !( _mochaLocalTmp4<length ) ){
                                    __LINE__ = 342;
                                    _yieldState = -1;
                                    __LINE__ = 342;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 0;
                                  _yieldState = 2;
                                  
                                  __LINE__ = 0;
                                  i = _mochaLocalTmp3[_mochaLocalTmp4];
                                  __LINE__ = 0;
                                  return [i,obj[i]];
                                case 2 :
                                  
                                  __LINE__ = 0;
                                   ++ _mochaLocalTmp4;
                                  
                                  __LINE__ = 342;
                                  if ( _mochaLocalTmp4<length ){
                                    __LINE__ = 342;
                                    _yieldState = 1;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 342;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 0;
                                  if ( _isYieldSafe ){
                                    __LINE__ = 0;
                                    return undefined;
                                  };
                                  
                                  __LINE__ = 342;
                                  Runtime.throwStopIteration();
                                  
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
                }
                __LINE__ = 0;
                generator = yieldTest13();
                
                __LINE__ = 343;
                var ret = generator.next();
                
                __LINE__ = 344;
                Runtime.assert( true,ret[0] === "x","ret[0] === \"x\"",344,'./yield_test.js' );
                
                __LINE__ = 345;
                Runtime.assert( true,ret[1] === 200,"ret[1] === 200",345,'./yield_test.js' );
                
                __LINE__ = 0;
                ret = generator.next();
                
                __LINE__ = 347;
                Runtime.assert( true,ret[0] === "y","ret[0] === \"y\"",347,'./yield_test.js' );
                
                __LINE__ = 348;
                Runtime.assert( true,ret[1] === 300,"ret[1] === 300",348,'./yield_test.js' );
                
                __LINE__ = 0;
                ret = generator.next();
                
                __LINE__ = 350;
                Runtime.assert( true,ret[0] === "z","ret[0] === \"z\"",350,'./yield_test.js' );
                
                __LINE__ = 351;
                Runtime.assert( true,ret[1] === 400,"ret[1] === 400",351,'./yield_test.js' );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case13 : function case13() {
              try {
                function keys( obj ) {
                  try {
                    __LINE__ = 0;
                    var _mochaIsNewBorn = true,
                        _yieldResult = undefined,
                        _yieldState = 0,
                        length,
                        _mochaLocalTmp7,
                        prop,
                        _mochaLocalTmp6 = [],
                        _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 0;
                            !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            
                            __LINE__ = 362;
                            while ( 1 ){
                              __LINE__ = 362;
                              switch ( _yieldState ) {
                                case 0 :
                                  
                                  __LINE__ = 355;
                                  for ( var _mochaLocalTmp5 in obj ){
                                    
                                    __LINE__ = 362;
                                    _mochaLocalTmp6.push( _mochaLocalTmp5 );
                                  };
                                  
                                  __LINE__ = 355;
                                  _mochaLocalTmp7 = 0;
                                  
                                  __LINE__ = 355;
                                  length = _mochaLocalTmp6.length;
                                  
                                  __LINE__ = 355;
                                  if ( !( _mochaLocalTmp7<length ) ){
                                    __LINE__ = 362;
                                    _yieldState = -1;
                                    __LINE__ = 362;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 0;
                                  prop = _mochaLocalTmp6[_mochaLocalTmp7];
                                  
                                  __LINE__ = 356;
                                  if ( obj.hasOwnProperty( prop ) ){
                                    __LINE__ = 362;
                                    _yieldState = 2;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 362;
                                    _yieldState = 3;
                                    __LINE__ = 0;
                                    break;
                                  };
                                case 2 :
                                  
                                  __LINE__ = 0;
                                  _yieldState = 3;
                                  __LINE__ = 0;
                                  return prop;
                                case 3 :
                                  
                                  __LINE__ = 0;
                                  _yieldState = 4;
                                  __LINE__ = 0;
                                  break;
                                case 4 :
                                  
                                  __LINE__ = 0;
                                   ++ _mochaLocalTmp7;
                                  
                                  __LINE__ = 362;
                                  if ( _mochaLocalTmp7<length ){
                                    __LINE__ = 362;
                                    _yieldState = 1;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 362;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 0;
                                  if ( _isYieldSafe ){
                                    __LINE__ = 0;
                                    return undefined;
                                  };
                                  
                                  __LINE__ = 362;
                                  Runtime.throwStopIteration();
                                  
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
                }
                __LINE__ = 362;
                var testObject =  {
                      value1 : 1,
                      value2 : 2,
                      value3 : 3,
                      value4 : 4
                    };
                
                try {
                  __LINE__ = 369;
                  var itemGen = keys( testObject );
                  
                  __LINE__ = 370;
                  Runtime.assert( true,itemGen.next() == "value1","itemGen.next() == \"value1\"",370,'./yield_test.js' );
                  
                  __LINE__ = 371;
                  Runtime.assert( true,itemGen.next() == "value2","itemGen.next() == \"value2\"",371,'./yield_test.js' );
                  
                  __LINE__ = 372;
                  Runtime.assert( true,itemGen.next() == "value3","itemGen.next() == \"value3\"",372,'./yield_test.js' );
                  
                  __LINE__ = 373;
                  Runtime.assert( true,itemGen.next() == "value4","itemGen.next() == \"value4\"",373,'./yield_test.js' );
                } catch( e ){
                  
                };
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            }
          };
      
      __LINE__ = 382;
      for ( var i = 1;i<13;i ++  ){
        
        __LINE__ = 0;
        tests["case"+i]();
      };
    } catch( e ){
      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  }();
}();
