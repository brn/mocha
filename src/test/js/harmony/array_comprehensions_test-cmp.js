(function() {
  var __FILE__ = "Runtime",
      __LINE__ = 0;
  
  var _mochaGlobalExport = {};
  
  ( function () {
    "use strict";
    
    function builtinTypeError( message ) {
      try {
        throw new TypeError( message );
      } catch( e ){
        throw new Error( e );
      };
    };
    
    function callbackCheck( callback,type ) {
      
      Runtime.assert( true,typeof type === "string","typeof type === \"string\"",39,'./mocha_runtime.js' );
      
      if ( typeof callback !== "function" ){
        builtinTypeError( type+" : first argument is not callable" );
      };
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
      Array.prototype.forEach = function ( callback,that ) {
        callbackCheck( callback,"Array.forEach" );
        
        var iter = -1,
            ta;
        
        if ( this === null ){
          builtinTypeError( "Array.forEach : this is null or not defined" );
        };
        
        if ( that ){
          while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
            callback.call( that,ta,iter,this );
          };
        } else {
          while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
            callback( ta,iter,this );
          };
        };
      };
    };
    
    if ( !Array.prototype.every ){
      Array.prototype.every = function ( callback,that ) {
        callbackCheck( callback,"Array.every" );
        
        var iter = -1,
            ta;
        
        if ( this === null ){
          builtinTypeError( "Array.every : this is null or not defined" );
        };
        
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
      };
    };
    
    if ( !Array.prototype.some ){
      Array.prototype.some = function ( callback,that ) {
        callbackCheck( callback,"Array.some" );
        
        var iter = -1,
            ta;
        
        if ( this === null ){
          builtinTypeError( "Array.some : this is null or not defined" );
        };
        
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
      };
    };
    
    if ( !Array.prototype.filter ){
      Array.prototype.filter = function ( callback,that ) {
        callbackCheck( callback,"Array.filter" );
        
        var len = this.length,
            iter = -1,
            ret = [],
            ta;
        
        if ( this === null ){
          builtinTypeError( "Array.filter : this is null or not defined" );
        };
        
        if ( that ){
          for ( var i = 0,len = this.length;i<len; ++ i ){
            if ( ( ta = this[i] ) !== null && ta !== undefined ){
              if ( callback.call( that,ta,i,this ) ){
                ret[ ++ iter] = ta;
              };
            };
          };
        } else {
          for ( var i = 0,len = this.length;i<len; ++ i ){
            if ( ( ta = this[i] ) !== null && ta !== undefined ){
              if ( callback( ta,i,this ) ){
                ret[ ++ iter] = ta;
              };
            };
          };
        };
        return ret;
      };
    };
    
    if ( !Array.prototype.indexOf ){
      Array.prototype.indexOf = function ( subject,fromIndex ) {
        var iter = ( fromIndex )?fromIndex-1 : -1,
            index = -1,
            ta;
        
        if ( this === null ){
          builtinTypeError( "Array.indexOf : this is null or not defined." );
        };
        
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
      Array.prototype.lastIndexOf = function ( target,fromIndex ) {
        var len = this.length,
            iter = ( fromIndex )?fromIndex+1 : len,
            index = -1,
            ta;
        
        if ( this === null ){
          builtinTypeError( "Array.lastIndexOf : this is null or not defined." );
        };
        
        while ( ( ta = this[ -- iter] ) !== null && ta !== undefined ){
          if ( ta === target ){
            index = iter;
            break;
          };
        };
        return index;
      };
    };
    
    if ( !Array.prototype.map ){
      Array.prototype.map = function ( callback,that ) {
        callbackCheck( callback,"Array.map" );
        
        var ret = [],
            iter = -1,
            len = this.length,
            i = 0,
            ta;
        
        if ( this === null ){
          builtinTypeError( "Array.map : this is null or not defined." );
        };
        
        if ( that ){
          for ( i;i<len; ++ i ){
            if ( ( ta = this[i] ) !== null && ta !== undefined ){
              ret[ ++ iter] = callback.call( that,ta,i,this );
            };
          };
        } else {
          for ( i;i<len; ++ i ){
            if ( ( ta = this[i] ) !== null && ta !== undefined ){
              ret[ ++ iter] = callback( ta,i,this );
            };
          };
        };
        return ret;
      };
    };
    
    if ( !Array.prototype.reduce ){
      Array.prototype.reduce = function ( callback,initial ) {
        callbackCheck( callback,"Array.reduce" );
        
        var ret = initial || this[0],
            i = ( initial )?0 : 1,
            len = this.length,
            ta;
        
        if ( ( len === 0 || len === null ) && arguments.length<2 ){
          builtinTypeError( "Array length is 0 and no second argument" );
        };
        
        for ( i;i<len; ++ i ){
          if ( ( ta = this[i] ) !== null && ta !== undefined ){
            ret = callback( ret,ta,i,this );
          };
        };
        return ret;
      };
    };
    
    if ( !Array.prototype.reduceRight ){
      Array.prototype.reduceRight = function ( callback,initial ) {
        callbackCheck( callback,"Array.reduceRight" );
        
        var len = this.length,
            ret = initial || this[len-1],
            i = ( initial )?len-1 : len-2,
            ta;
        
        if ( ( len === 0 || len === null ) && arguments.length<2 ){
          builtinTypeError( "Array length is 0 and no second argument" );
        };
        
        for ( i;i>-1; -- i ){
          if ( ( ta = this[i] ) !== null && ta !== undefined ){
            ret = callback( ret,ta,i,this );
          };
        };
        return ret;
      };
    };
    
    if ( !Date.prototype.toJSON ){
      Date.prototype.toJSON = function () {
        var _mochaLocalTmp0 = [this.getUTCMonth(),this.getUTCDate(),this.getUTCHours(),this.getMinutes(),this.getSeconds()],
            month = _mochaLocalTmp0[0],
            date = _mochaLocalTmp0[1],
            hour = _mochaLocalTmp0[2],
            minute = _mochaLocalTmp0[3],
            second = _mochaLocalTmp0[4];
        return '"'+this.getUTCFullYear()+'-'+( month>8?month+1 : "0"+( month+1 ) )+'-'+( date>9?date : "0"+date )+'T'+( hour>9?hour : "0"+hour )+':'+( minute>9?minute : "0"+minute )+':'+( second>9?second : "0"+second )+'.'+this.getUTCMilliseconds()+'Z"';
      };
    };
    
    if ( !Date.now ){
      Date.now = function () {
        return +new Date();
      };
    };
    
    if ( !Object.keys ){
      Object.keys = function ( obj ) {
        if ( !obj ){
          builtinTypeError( "Object.keys : first arguments is null or not defined." );
        };
        
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
      Array.isArray = function ( arr ) {
        if ( arguments.length === 0 ){
          return false;
        };
        return ( arr )?Object.prototype.toString.call( arr ) === "[object Array]" : false;
      };
    };
  })();
  
  var Runtime = ( function Runtime() {
        var _mochaLocalExport = {};
        
        function Exception( line,file,e ) {
          this.toString = function () {
            return Runtime.getErrorMessage( e )+" in file "+file+" at : "+line;
          };
        }
        function fastMax( x,y ) {
          return x>y?x : y;
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
        
        var extend = _mochaLocalExport.extend = function extend( dest,source ) {
              for ( var prop in source ){
                dest[prop] = source[prop];
              };
              return dest;
            };
        
        function compareTuple( tuple ) {
          var max = fastMax( tuple.length,this.length );
          
          i = 0;
          
          while ( i<max && tuple[i] === this[i] ){
            i ++ ;
          };
          return max === i;
        };
        
        function tupleToArray() {
          return Array.prototype.slice.call( this );
        };
        
        var createTuple = _mochaLocalExport.createTuple = function createTuple( obj,size ) {
              createUnenumProp( obj,"length",size );
              
              createUnenumProp( obj,"equal",compareTuple );
              
              createUnenumProp( obj,"toArray",tupleToArray );
              
              createUnenumProp( obj,"toString",
              function () {
                return "[object Tuple]";
              });
              return Object.freeze( obj );
            };
        
        var extendPrototype = _mochaLocalExport.extendPrototype = function ( derived,base ) {
              derived.prototype = base;
            };
        
        var getPrototype = ( "getPrototypeOf" in Object )?function ( obj ) {
              return Object.getPrototypeOf( obj );
            } : function ( obj ) {
              var ret = {};
              
              for ( var i in obj ){
                if ( !obj.hasOwnProperty( i ) ){
                  ret[i] = obj[i];
                };
              };
              return ret;
            };
        
        var extendClass = _mochaLocalExport.extendClass = ( Runtime.hasProto )?function ( derived,base ) {
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
        
        ( _mochaLocalExport.createPrivateRecord = createPrivateRecord );
        
        ( _mochaLocalExport.getPrivateRecord = getPrivateRecord );
        
        var getSuper = _mochaLocalExport.getSuper = function getSuper( obj ) {
              var type = typeof obj,
                  ret;
              
              if ( type === "function" ){
                ret = function (){};
                
                ret.prototype = obj.prototype;
                
                ret = new ret();
                
                if ( obj.__harmony_class__ ){
                  ret.constructor = obj.constructor;
                } else {
                  ret.constructor = obj;
                };
                return ret;
              };
              return ret;
            };
        
        var traitMixin = _mochaLocalExport.traitMixin = function traitMixin( dest,source,with_,without ) {
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
            };
        
        var classMixin = _mochaLocalExport.classMixin = function classMixin( _mochaLocalTmp1,_mochaLocalTmp2,_mochaLocalTmp3,with_,without ) {
              var constructorProto = _mochaLocalTmp1.prototype,
                  privateProto = _mochaLocalTmp2.prototype,
                  mark = _mochaLocalTmp3._mochaTraitMark,
                  traitPublic = _mochaLocalTmp3._mochaTraitPublic,
                  traitPrivate = _mochaLocalTmp3._mochaTraitPrivate;
              
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
            };
        
        var checkRequirements = _mochaLocalExport.checkRequirements = function checkRequirements( _mochaLocalTmp4,_mochaLocalTmp5,traits,file,line ) {
              var proto1 = _mochaLocalTmp4.prototype,
                  proto2 = _mochaLocalTmp5.prototype;
              
              for ( var i = 0,len = traits.length;i<len;i ++  ){
                var _mochaLocalTmp6 = traits[i],
                    _mochaRequires = _mochaLocalTmp6._mochaRequires;
                
                for ( var prop in _mochaRequires ){
                  if ( !( prop in proto1 ) && !( prop in proto2 ) ){
                    Runtime.throwException( "Class dose not meet the traits requirement. traits require implementation of property "+prop+"\nin file "+file+" at line "+line );
                  };
                };
              };
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
      var __FILE__ = "/Users/aono_taketoshi/.mocha/module/iterators.js",
          __LINE__ = 0;
      __LINE__ = 2;
      _mochaGlobalExport['../../../../../../.mocha/module/iterators.js'] = {};
      
      __LINE__ = 3;
      var _mochaGlobalAlias = _mochaGlobalExport['../../../../../../.mocha/module/iterators.js'];
      
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
      var __FILE__ = "/Users/aono_taketoshi/github/mocha/src/test/js/harmony/array_comprehensions_test.js",
          __LINE__ = 0;
      __LINE__ = 2;
      _mochaGlobalExport['./array_comprehensions_test.js'] = {};
      
      __LINE__ = 3;
      var _mochaGlobalAlias = _mochaGlobalExport['./array_comprehensions_test.js'];
      
      __LINE__ = 0;
      var _mochaLocalTmp0 = _mochaGlobalExport['../../../../../../.mocha/module/iterators.js'],
          items = _mochaLocalTmp0.items;
      
      __LINE__ = 3;
      var testTarget =  {
            value1 : 100,
            value2 : 200,
            value3 : 300
          };
      
      __LINE__ = 9;
      var cmpTest = ( function () {
            try {
              __LINE__ = 0;
              var _mochaLocalTmp1 = [];
              
              __LINE__ = 9;
              for ( var prop in testTarget ){
                __LINE__ = 0;
                prop = testTarget[prop];
                
                __LINE__ = 0;
                _mochaLocalTmp1.push( prop );
              };
              __LINE__ = 0;
              return _mochaLocalTmp1;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })();
      
      __LINE__ = 10;
      Runtime.assert( true,cmpTest[0] === 100,"cmpTest[0] === 100",10,'./array_comprehensions_test.js' );
      
      __LINE__ = 11;
      Runtime.assert( true,cmpTest[1] === 200,"cmpTest[1] === 200",11,'./array_comprehensions_test.js' );
      
      __LINE__ = 12;
      Runtime.assert( true,cmpTest[2] === 300,"cmpTest[2] === 300",12,'./array_comprehensions_test.js' );
      
      __LINE__ = 0;
      cmpTest = ( function () {
        try {
          __LINE__ = 0;
          var _mochaLocalTmp2 = [];
          
          __LINE__ = 14;
          for ( var prop in testTarget ){
            __LINE__ = 0;
            _mochaLocalTmp2.push( prop );
          };
          __LINE__ = 0;
          return _mochaLocalTmp2;
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      })();
      
      __LINE__ = 15;
      Runtime.assert( true,cmpTest[0] === "value1","cmpTest[0] === \"value1\"",15,'./array_comprehensions_test.js' );
      
      __LINE__ = 16;
      Runtime.assert( true,cmpTest[1] === "value2","cmpTest[1] === \"value2\"",16,'./array_comprehensions_test.js' );
      
      __LINE__ = 17;
      Runtime.assert( true,cmpTest[2] === "value3","cmpTest[2] === \"value3\"",17,'./array_comprehensions_test.js' );
      
      __LINE__ = 0;
      cmpTest = ( function () {
        try {
          __LINE__ = 0;
          var _mochaLocalTmp3 = [];
          
          __LINE__ = 0;
          var prop;
          
          __LINE__ = 0;
          var _mochaLocalTmp4 = items( testTarget );
          
          __LINE__ = 0;
          _mochaLocalTmp4 = Runtime.hasIterator( _mochaLocalTmp4 )?Runtime.getIterator( _mochaLocalTmp4 ) : _mochaLocalTmp4;
          
          __LINE__ = 0;
          if ( _mochaLocalTmp4.__nothrowNext__ ){
            __LINE__ = 0;
            while ( ( prop = _mochaLocalTmp4.__nothrowNext__(  ) ) ){
              __LINE__ = 0;
              _mochaLocalTmp3.push( prop );
            };
          } else {
            __LINE__ = 0;
            Runtime.exceptionHandler( 19,'./array_comprehensions_test.js','for of statement expect iterator or generator object.' );
          };
          __LINE__ = 0;
          return _mochaLocalTmp3;
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      })();
      
      __LINE__ = 20;
      Runtime.assert( true,cmpTest[0][0] === "value1","cmpTest[0][0] === \"value1\"",20,'./array_comprehensions_test.js' );
      
      __LINE__ = 21;
      Runtime.assert( true,cmpTest[0][1] === 100,"cmpTest[0][1] === 100",21,'./array_comprehensions_test.js' );
      
      __LINE__ = 22;
      Runtime.assert( true,cmpTest[1][0] === "value2","cmpTest[1][0] === \"value2\"",22,'./array_comprehensions_test.js' );
      
      __LINE__ = 23;
      Runtime.assert( true,cmpTest[1][1] === 200,"cmpTest[1][1] === 200",23,'./array_comprehensions_test.js' );
      
      __LINE__ = 24;
      Runtime.assert( true,cmpTest[2][0] === "value3","cmpTest[2][0] === \"value3\"",24,'./array_comprehensions_test.js' );
      
      __LINE__ = 25;
      Runtime.assert( true,cmpTest[2][1] === 300,"cmpTest[2][1] === 300",25,'./array_comprehensions_test.js' );
      
      __LINE__ = 28;
      var cmpTest = ( function () {
            try {
              __LINE__ = 0;
              var _mochaLocalTmp5 = [];
              
              __LINE__ = 28;
              for ( var prop in testTarget ){
                __LINE__ = 0;
                prop = testTarget[prop];
                
                __LINE__ = 28;
                if ( prop === 200 ){
                  __LINE__ = 0;
                  _mochaLocalTmp5.push( prop );
                };
              };
              __LINE__ = 0;
              return _mochaLocalTmp5;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })();
      
      __LINE__ = 29;
      Runtime.assert( true,cmpTest[0] === 200,"cmpTest[0] === 200",29,'./array_comprehensions_test.js' );
      
      __LINE__ = 0;
      cmpTest = ( function () {
        try {
          __LINE__ = 0;
          var _mochaLocalTmp6 = [];
          
          __LINE__ = 31;
          for ( var prop in testTarget ){
            __LINE__ = 31;
            if ( prop === "value2" ){
              __LINE__ = 0;
              _mochaLocalTmp6.push( prop );
            };
          };
          __LINE__ = 0;
          return _mochaLocalTmp6;
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      })();
      
      __LINE__ = 32;
      Runtime.assert( true,cmpTest[0] === "value2","cmpTest[0] === \"value2\"",32,'./array_comprehensions_test.js' );
      
      __LINE__ = 0;
      cmpTest = ( function () {
        try {
          __LINE__ = 0;
          var _mochaLocalTmp7 = [];
          
          __LINE__ = 0;
          var prop;
          
          __LINE__ = 0;
          var _mochaLocalTmp8 = items( testTarget );
          
          __LINE__ = 0;
          _mochaLocalTmp8 = Runtime.hasIterator( _mochaLocalTmp8 )?Runtime.getIterator( _mochaLocalTmp8 ) : _mochaLocalTmp8;
          
          __LINE__ = 0;
          if ( _mochaLocalTmp8.__nothrowNext__ ){
            __LINE__ = 0;
            while ( ( prop = _mochaLocalTmp8.__nothrowNext__(  ) ) ){
              __LINE__ = 34;
              if ( prop[1] === 200 ){
                __LINE__ = 0;
                _mochaLocalTmp7.push( prop );
              };
            };
          } else {
            __LINE__ = 0;
            Runtime.exceptionHandler( 34,'./array_comprehensions_test.js','for of statement expect iterator or generator object.' );
          };
          __LINE__ = 0;
          return _mochaLocalTmp7;
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      })();
      
      __LINE__ = 35;
      Runtime.assert( true,cmpTest[0][0] === "value2","cmpTest[0][0] === \"value2\"",35,'./array_comprehensions_test.js' );
      
      __LINE__ = 36;
      Runtime.assert( true,cmpTest[0][1] === 200,"cmpTest[0][1] === 200",36,'./array_comprehensions_test.js' );
      
      __LINE__ = 0;
      testTarget =  {
        value1 :  {
          value1 : 100
        },
        value2 :  {
          value2 : 200
        },
        value3 :  {
          value3 : 300
        }
      };
      
      __LINE__ = 0;
      cmpTest = ( function () {
        try {
          __LINE__ = 0;
          var _mochaLocalTmp9 = [];
          
          __LINE__ = 44;
          for ( var prop in testTarget ){
            __LINE__ = 0;
            prop = testTarget[prop];
            
            __LINE__ = 44;
            for ( var x in prop ){
              __LINE__ = 0;
              x = prop[x];
              
              __LINE__ = 0;
              _mochaLocalTmp9.push( x );
            };
          };
          __LINE__ = 0;
          return _mochaLocalTmp9;
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      })();
      
      __LINE__ = 45;
      Runtime.assert( true,cmpTest[0] === 100,"cmpTest[0] === 100",45,'./array_comprehensions_test.js' );
      
      __LINE__ = 46;
      Runtime.assert( true,cmpTest[1] === 200,"cmpTest[1] === 200",46,'./array_comprehensions_test.js' );
      
      __LINE__ = 47;
      Runtime.assert( true,cmpTest[2] === 300,"cmpTest[2] === 300",47,'./array_comprehensions_test.js' );
      
      __LINE__ = 0;
      cmpTest = ( function () {
        try {
          __LINE__ = 0;
          var _mochaLocalTmp10 = [];
          
          __LINE__ = 49;
          for ( var prop in testTarget ){
            __LINE__ = 0;
            prop = testTarget[prop];
            
            __LINE__ = 49;
            for ( var x in prop ){
              __LINE__ = 0;
              _mochaLocalTmp10.push( x );
            };
          };
          __LINE__ = 0;
          return _mochaLocalTmp10;
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      })();
      
      __LINE__ = 50;
      Runtime.assert( true,cmpTest[0] === "value1","cmpTest[0] === \"value1\"",50,'./array_comprehensions_test.js' );
      
      __LINE__ = 51;
      Runtime.assert( true,cmpTest[1] === "value2","cmpTest[1] === \"value2\"",51,'./array_comprehensions_test.js' );
      
      __LINE__ = 52;
      Runtime.assert( true,cmpTest[2] === "value3","cmpTest[2] === \"value3\"",52,'./array_comprehensions_test.js' );
      
      __LINE__ = 0;
      cmpTest = ( function () {
        try {
          __LINE__ = 0;
          var _mochaLocalTmp11 = [];
          
          __LINE__ = 54;
          for ( var prop in testTarget ){
            __LINE__ = 0;
            prop = testTarget[prop];
            
            __LINE__ = 0;
            var x;
            
            __LINE__ = 0;
            var _mochaLocalTmp12 = items( prop );
            
            __LINE__ = 0;
            _mochaLocalTmp12 = Runtime.hasIterator( _mochaLocalTmp12 )?Runtime.getIterator( _mochaLocalTmp12 ) : _mochaLocalTmp12;
            
            __LINE__ = 0;
            if ( _mochaLocalTmp12.__nothrowNext__ ){
              __LINE__ = 0;
              while ( ( x = _mochaLocalTmp12.__nothrowNext__(  ) ) ){
                __LINE__ = 0;
                _mochaLocalTmp11.push( x );
              };
            } else {
              __LINE__ = 0;
              Runtime.exceptionHandler( 54,'./array_comprehensions_test.js','for of statement expect iterator or generator object.' );
            };
          };
          __LINE__ = 0;
          return _mochaLocalTmp11;
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      })();
      
      __LINE__ = 55;
      Runtime.assert( true,cmpTest[0][0] === "value1","cmpTest[0][0] === \"value1\"",55,'./array_comprehensions_test.js' );
      
      __LINE__ = 56;
      Runtime.assert( true,cmpTest[0][1] === 100,"cmpTest[0][1] === 100",56,'./array_comprehensions_test.js' );
      
      __LINE__ = 57;
      Runtime.assert( true,cmpTest[1][0] === "value2","cmpTest[1][0] === \"value2\"",57,'./array_comprehensions_test.js' );
      
      __LINE__ = 58;
      Runtime.assert( true,cmpTest[1][1] === 200,"cmpTest[1][1] === 200",58,'./array_comprehensions_test.js' );
      
      __LINE__ = 59;
      Runtime.assert( true,cmpTest[2][0] === "value3","cmpTest[2][0] === \"value3\"",59,'./array_comprehensions_test.js' );
      
      __LINE__ = 60;
      Runtime.assert( true,cmpTest[2][1] === 300,"cmpTest[2][1] === 300",60,'./array_comprehensions_test.js' );
    } catch( e ){
      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  })();
})();
