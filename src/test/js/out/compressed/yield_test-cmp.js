!function() {
  var __FILE__ = "Runtime",
      __LINE__ = 0;
  
  var _mochaGlobalExport = {};
  
  !function (_mochaLocalTmp0,_mochaLocalTmp1,_mochaLocalTmp2,_mochaLocalTmp3) {
    function defineBuiltin(obj,name,value) {
      return Object.defineProperty(obj,name, {
        value : value,
        configurable : true,
        enumerable : false,
        writable : true
      });
    }
    function callbackCheck(callback,type) {
      
      Runtime.assert(true,typeof type === "string","typeof type === \"string\"",43,'./anonymous');
      
      typeof callback !== "function" && builtinTypeError(type+" : first argument is not callable");
    }
    function builtinTypeError(message) {
      try {
        throw new TypeError(message);
      } catch(e){
        throw new Error(e);
      };
    }
    var stringProto = _mochaLocalTmp0.prototype,
        arrayProto = _mochaLocalTmp1.prototype,
        functionProto = _mochaLocalTmp2.prototype,
        dateProto = _mochaLocalTmp3.prototype;
    
    !Object.keys && (Object.keys = function (obj) {
      !obj && builtinTypeError("Object.keys : first arguments is null or not defined.");
      
      var ret = [],
          iter = -1;
      
      for (var i in obj){
        
        obj.hasOwnProperty(i) && (ret[ ++ iter] = obj[i]);
      };
      return ret;
    });
    
    !Object.preventExtensions && (Object.preventExtensions = function (o) {
      return o;
    });
    
    !Object.seal && (Object.seal = function (o) {
      return o;
    });
    
    !Object.freeze && (Object.freeze = function (o) {
      return o;
    });
    
    var hasRealEcma5 = function () {
          var ret;
          
          try {
            
            var obj = {};
            
            Object.defineProperty(obj,"test", {
              configurable : false,
              writable : false,
              enumerable : false,
              value : 0
            });
            
            obj.test = 200;
            
            ret = (obj.test === 200)?false : true;
          } catch(e){
            
            ret = false;
          };
          return ret;
        }();
    
    !hasRealEcma5 && (Object.defineProperty = function (obj,prop,valobj) {
      "value" in valobj && (obj[prop] = valobj.value);
    });
    
    if (!stringProto.trim){
      
      stringProto.trim = function () {
        return this.replace(stringProto.trim.rtrim,"");
      };
      
      stringProto.trim.rtrim = /^\s*|\s*$/g;
    };
    
    !stringProto.repeat && defineBuiltin(stringProto,"repeat",
    function (num) {
      return Array(num+1).join(this.toString());
    });
    
    !stringProto.startsWith && defineBuiltin(stringProto,"startsWith",
    function (str) {
      return !this.indexOf(str);
    });
    
    !stringProto.endsWith && defineBuiltin(stringProto,"endsWith",
    function (str) {
      var t = String(str),
          index = this.lastIndexOf(t);
      return index >= 0 && index === this.length-t.length;
    });
    
    !stringProto.contains && defineBuiltin(stringProto,"contains",
    function (str) {
      return this.indexOf(str) !== -1;
    });
    
    !stringProto.toArray && defineBuiltin(stringProto,"toArray",
    function (str) {
      return this.split("");
    });
    
    !functionProto.bind && defineBuiltin(functionProto,"bind",
    function () {
      var argArray = arrayProto.slice.call(arguments),
          context = argArray.shift(),
          ret = function () {
            var args = argArray.concat(arrayProto.slice.call(arguments));
            return this !== null && this !== window && this instanceof ret?ret.context.apply(this,args) : ret.context.apply(context,args);
          };
      
      ret.prototype = this.prototype;
      
      ret.context = this;
      return ret;
    });
    
    !arrayProto.forEach && defineBuiltin(arrayProto,"forEach",
    function (callback,that) {
      callbackCheck(callback,"Array.forEach");
      
      var iter = -1,
          ta;
      
      this === null && builtinTypeError("Array.forEach : this is null or not defined");
      
      if (that){
        while ((ta = this[ ++ iter]) !== null && ta !== undefined){
          callback.call(that,ta,iter,this);
        }
      } else {
        while ((ta = this[ ++ iter]) !== null && ta !== undefined){
          callback(ta,iter,this);
        };
      };
    });
    
    !arrayProto.every && defineBuiltin(arrayProto,"every",
    function (callback,that) {
      callbackCheck(callback,"Array.every");
      
      var iter = -1,
          ta;
      
      this === null && builtinTypeError("Array.every : this is null or not defined");
      
      if (that){
        while ((ta = this[ ++ iter]) !== null && ta !== undefined){
          if (!(callback.call(that,ta,iter,this))){
            return false;
          };
        }
      } else {
        while ((ta = this[ ++ iter]) !== null && ta !== undefined){
          if (!(callback(ta,iter,this))){
            return false;
          };
        };
      };
      return true;
    });
    
    !arrayProto.some && defineBuiltin(arrayProto,"some",
    function (callback,that) {
      callbackCheck(callback,"Array.some");
      
      var iter = -1,
          ta;
      
      this === null && builtinTypeError("Array.some : this is null or not defined");
      
      if (that){
        while ((ta = this[ ++ iter]) !== null && ta !== undefined){
          if (callback.call(that,ta,iter,this)){
            return true;
          };
        }
      } else {
        while ((ta = this[ ++ iter]) !== null && ta !== undefined){
          if (callback(ta,iter,this)){
            return true;
          };
        };
      };
      return false;
    });
    
    !arrayProto.filter && defineBuiltin(arrayProto,"filter",
    function (callback,that) {
      callbackCheck(callback,"Array.filter");
      
      var len = this.length,
          iter = -1,
          ret = [],
          ta;
      
      this === null && builtinTypeError("Array.filter : this is null or not defined");
      
      if (that){
        for (var i = 0,len = this.length;i<len; ++ i){
          
          (ta = this[i]) !== null && ta !== undefined && callback.call(that,ta,i,this) && (ret[ ++ iter] = ta);
        }
      } else {
        for (var i = 0,len = this.length;i<len; ++ i){
          
          (ta = this[i]) !== null && ta !== undefined && callback(ta,i,this) && (ret[ ++ iter] = ta);
        };
      };
      return ret;
    });
    
    !arrayProto.indexOf && defineBuiltin(arrayProto,"indexOf",
    function (subject,fromIndex) {
      var iter = (fromIndex)?fromIndex-1 : -1,
          index = -1,
          ta;
      
      this === null && builtinTypeError("Array.indexOf : this is null or not defined.");
      
      while ((ta = this[ ++ iter]) !== null && ta !== undefined){
        if (ta === subject){
          
          index = iter;
          break;
        };
      };
      return index;
    });
    
    !arrayProto.lastIndexOf && defineBuiltin(arrayProto,"lastIndexOf",
    function (target,fromIndex) {
      var len = this.length,
          iter = (fromIndex)?fromIndex+1 : len,
          index = -1,
          ta;
      
      this === null && builtinTypeError("Array.lastIndexOf : this is null or not defined.");
      
      while ((ta = this[ -- iter]) !== null && ta !== undefined){
        if (ta === target){
          
          index = iter;
          break;
        };
      };
      return index;
    });
    
    !arrayProto.map && defineBuiltin(arrayProto,"map",
    function (callback,that) {
      callbackCheck(callback,"Array.map");
      
      var ret = [],
          iter = -1,
          len = this.length,
          i = 0,
          ta;
      
      this === null && builtinTypeError("Array.map : this is null or not defined.");
      
      if (that){
        for (i;i<len; ++ i){
          (ta = this[i]) !== null && ta !== undefined && (ret[ ++ iter] = callback.call(that,ta,i,this));
        }
      } else {
        for (i;i<len; ++ i){
          (ta = this[i]) !== null && ta !== undefined && (ret[ ++ iter] = callback(ta,i,this));
        };
      };
      return ret;
    });
    
    !arrayProto.reduce && defineBuiltin(arrayProto,"reduce",
    function (callback,initial) {
      callbackCheck(callback,"Array.reduce");
      
      var ret = initial || this[0],
          i = (initial)?0 : 1,
          len = this.length,
          ta;
      
      (len === 0 || len === null) && arguments.length<2 && builtinTypeError("Array length is 0 and no second argument");
      
      for (i;i<len; ++ i){
        (ta = this[i]) !== null && ta !== undefined && (ret = callback(ret,ta,i,this));
      };
      return ret;
    });
    
    !arrayProto.reduceRight && defineBuiltin(arrayProto,"reduceRight",
    function (callback,initial) {
      callbackCheck(callback,"Array.reduceRight");
      
      var len = this.length,
          ret = initial || this[len-1],
          i = (initial)?len-1 : len-2,
          ta;
      
      (len === 0 || len === null) && arguments.length<2 && builtinTypeError("Array length is 0 and no second argument");
      
      for (i;i>-1; -- i){
        (ta = this[i]) !== null && ta !== undefined && (ret = callback(ret,ta,i,this));
      };
      return ret;
    });
    
    !dateProto.toJSON && defineBuiltin(dateProto,"toJSON",
    function () {
      var _mochaLocalTmp4 = [this.getUTCMonth(),this.getUTCDate(),this.getUTCHours(),this.getMinutes(),this.getSeconds()],
          month = _mochaLocalTmp4[0],
          date = _mochaLocalTmp4[1],
          hour = _mochaLocalTmp4[2],
          minute = _mochaLocalTmp4[3],
          second = _mochaLocalTmp4[4];
      return '"'+this.getUTCFullYear()+'-'+(month>8?month+1 : "0"+(month+1))+'-'+(date>9?date : "0"+date)+'T'+(hour>9?hour : "0"+hour)+':'+(minute>9?minute : "0"+minute)+':'+(second>9?second : "0"+second)+'.'+this.getUTCMilliseconds()+'Z"';
    });
    
    !Date.now && defineBuiltin(Date,"now",
    function () {
      return +new Date();
    });
    
    !Array.isArray && defineBuiltin(Array,"isArray",
    function (arr) {
      if (arguments.length === 0){
        return false;
      };
      return (arr)?({}).toString.call(arr) === "[object Array]" : false;
    });
  }.call(this,String,Array,Function,Date);
  
  var Runtime = function () {
        function checkRequirements(_mochaLocalTmp9,_mochaLocalTmp10,traits,file,line) {
          var proto1 = _mochaLocalTmp9.prototype,
              proto2 = _mochaLocalTmp10.prototype;
          
          for (var i = 0,len = traits.length;i<len;i ++ ){
            
            var _mochaLocalTmp11 = traits[i],
                _mochaRequires = _mochaLocalTmp11._mochaRequires;
            
            for (var prop in _mochaRequires){
              !(prop in proto1) && !(prop in proto2) && Runtime.throwException("Class dose not meet the traits requirement. traits require implementation of property "+prop+"\nin file "+file+" at line "+line);
            };
          };
        }
        function classMixin(_mochaLocalTmp6,_mochaLocalTmp7,_mochaLocalTmp8,with_,without) {
          var constructorProto = _mochaLocalTmp6.prototype,
              privateProto = _mochaLocalTmp7.prototype,
              mark = _mochaLocalTmp8._mochaTraitMark,
              traitPublic = _mochaLocalTmp8._mochaTraitPublic,
              traitPrivate = _mochaLocalTmp8._mochaTraitPrivate;
          
          if (!mark){
            Runtime.throwException("mixin only used for trait.");
          } else {
            
            var tmp;
            
            for (var i in traitPublic){
              if (!without[i]){
                
                tmp = (!with_[i])?i : with_[i];
                
                constructorProto[tmp] = traitPublic[i];
              };
            };
            
            for (i in traitPrivate){
              if (!without[i]){
                
                tmp = (!with_[i])?i : with_[i];
                
                privateProto[tmp] = traitPrivate[i];
              };
            };
          };
        }
        function traitMixin(dest,source,with_,without) {
          if (!dest._mochaTraitMark || !source._mochaTraitMark){
            Runtime.throwException("mixin only used for trait.");
          } else {
            
            var destTraitPrivate = dest._mochaTraitPrivate,
                sourceTraitPrivate = source._mochaTraitPrivate,
                destTraitPublic = dest._mochaTraitPublic,
                sourceTraitPublic = source._mochaTraitPublic,
                sourceRequires = source._mochaRequires,
                destRequires = dest._mochaRequires,
                tmp;
            
            for (var i in sourceTraitPrivate){
              if (!without[i]){
                
                tmp = (!with_[i])?i : with_[i];
                
                destTraitPrivate[tmp] = sourceTraitPrivate[i];
              };
            };
            
            for (i in sourceTraitPublic){
              if (!without[i]){
                
                tmp = (!with_[i])?i : with_[i];
                
                destTraitPublic[tmp] = sourceTraitPublic[i];
              };
            };
            
            for (i in sourceRequires){
              destRequires[i] = sourceRequires[i];
            };
          };
        }
        function getSuper(obj) {
          var type = typeof obj,
              ret;
          
          if (type === "function"){
            
            ret = function (){};
            
            ret.prototype = obj.prototype;
            
            ret = new ret();
            
            obj.__harmony_class__?ret.constructor = obj.constructor : ret.constructor = obj;
            return ret;
          };
          return ret;
        }
        function initializeClass(instance,classObject,privateHolder,constructor,args,name,line) {
          (!instance || !(instance instanceof classObject)) && throwException("class "+name+" must be called by new. line : "+line);
          
          createPrivateRecord(instance,privateHolder);
          
          constructor.apply(instance,args);
        }
        function isStopIteration(obj) {
          return obj === StopIteration || rstopIteration.test(obj);
        }
        function hasIterator(obj) {
          return __ref_iterator__ in obj;
        }
        function getIterator(obj) {
          var ret = obj[__ref_iterator__](),
              newObj;
          
          if (isGenerator(ret)){
            return ret;
          };
          
          newObj = {};
          
          if (ret.next){
            createUnenumProp(newObj,"next",
            function () {
              var result = ret.next();
              
              result === undefined && throwStopIteration();
              return result;
            });
          } else {
            return {};
          };
          
          !("__nothrowNext__" in ret) && createUnenumProp(newObj,"__nothrowNext__",ret.next.bind(ret));
          
          for (var prop in ret){
            
            prop !== "next" && prop !== "__nothrowNext__" && (newObj[prop] = ret[prop]);
          };
          
          !("toString" in ret) && createUnenumProp(newObj,"toString",
          function () {
            return "[object Iterator]";
          });
          return newObj;
        }
        function isGenerator(obj) {
          return obj instanceof Generator;
        }
        function throwStopIteration() {
          try {
            throw StopIteration;
          } catch(e){
            throw new Error(e.toString());
          };
        }
        function createRecord(obj) {
          obj.toString() === "[object Object]" && createUnenumProp(obj,"toString",
          function () {
            return "[object Record]";
          });
          return Object.freeze(obj);
        }
        function createTuple(obj,size) {
          createUnenumProp(obj,"length",size);
          
          createUnenumProp(obj,"equal",compareTuple);
          
          createUnenumProp(obj,"toArray",tupleToArray);
          
          createUnenumProp(obj,"toString",
          function () {
            return "[object Tuple]";
          });
          return Object.freeze(obj);
        }
        function tupleToArray() {
          return [].slice.call(this);
        }
        function compareTuple(tuple) {
          var maxIndex = max(tuple.length,this.length),
              i = -1;
          
          while ( ++ i<maxIndex && tuple[i] === this[i]){
            
          };
          return maxIndex === i;
        }
        function extend(dest,source) {
          for (var prop in source){
            
            dest[prop] = source[prop];
          };
          return dest;
        }
        function getErrorMessage(e) {
          return (e.message)?e.message : (e.description)?e.description : e.toString();
        }
        function createGenerator(generatorFn,closeFn,context) {
          var ret = new Generator;
          
          createUnenumProp(ret,"next",generatorFn.bind(context,false,false));
          
          createUnenumProp(ret,"send",generatorFn.bind(context,true,false));
          
          createUnenumProp(ret,"close",closeFn.bind(context));
          
          createUnenumProp(ret,"__nothrowNext__",generatorFn.bind(context,false,true));
          
          createUnenumProp(ret,"toString",
          function () {
            return "[object Generator]";
          });
          
          Object.freeze(ret);
          return ret;
        }
        function Generator(){}
        function toArray(likeArray,index) {
          return (likeArray)?slice.call(likeArray,index) : [];
        }
        function constant(obj,prop,value) {
          return Object.defineProperty(obj,prop, {
            configurable : false,
            enumerable : false,
            writable : false,
            value : value
          });
        }
        function createUnenumProp(obj,prop,value) {
          return Object.defineProperty(obj,prop, {
            configurable : true,
            enumerable : false,
            writable : true,
            value : value
          });
        }
        function Exception(line,file,e) {
          this.toString = function () {
            return Runtime.getErrorMessage(e)+" in file "+file+" at : "+line;
          };
        }
        var _mochaLocalExport = {};
        
        var max = Math.max,
            _mochaLocalTmp5 = Array.prototype,
            slice = _mochaLocalTmp5.slice,
            Runtime =  {
              getErrorMessage : function (e) {
                return (e.message)?e.message : (e.description)?e.description : e.toString();
              },
              exceptionHandler : function (line,file,e) {
                if (isStopIteration(e)){
                  
                  this.throwException(e);
                } else {
                  
                  this.throwException(new Exception(line,file,e));
                };
              },
              throwException : function (exception) {
                try {
                  throw exception;
                } catch(e){
                  
                  if (isStopIteration(e)){
                    throw new Error(e);
                  } else {
                    throw new Error(this.getErrorMessage(e));
                  };
                };
              },
              hasProto : "__proto__" in {}
            };
        
        _mochaLocalExport.createUnenumProp = createUnenumProp;
        
        _mochaLocalExport.constant = constant;
        
        _mochaLocalExport.toArray = toArray;
        
        _mochaLocalExport.createGenerator = createGenerator;
        
        var throwException = _mochaLocalExport.throwException = Runtime.throwException.bind(Runtime),
            exceptionHandler = _mochaLocalExport.exceptionHandler = Runtime.exceptionHandler.bind(Runtime);
        
        _mochaLocalExport.extend = extend;
        
        _mochaLocalExport.createTuple = createTuple;
        
        _mochaLocalExport.createRecord = createRecord;
        
        var extendPrototype = _mochaLocalExport.extendPrototype = function (derived,base) {
              derived.prototype = base;
            },
            getPrototype = ("getPrototypeOf" in Object)?function (obj) {
              return Object.getPrototypeOf(obj);
            } : function (obj) {
              var ret = {};
              
              for (var i in obj){
                
                !obj.hasOwnProperty(i) && (ret[i] = obj[i]);
              };
              return ret;
            },
            extendClass = _mochaLocalExport.extendClass = (Runtime.hasProto)?function (derived,base) {
              if (typeof base === 'function'){
                
                derived.prototype.__proto__ = base.prototype;
                
                for (var i in base){
                  derived[i] = base[i];
                };
              } else {
                derived.prototype.__proto__ = base.__proto__;
              };
            } : function (derived,base) {
              var baseType = typeof base;
              
              if (baseType === "function"){
                
                var inherit = function (){};
                
                inherit.prototype = base.prototype;
                
                derived.prototype = new inherit;
                
                for (var i in base){
                  derived[i] = base[i];
                };
              } else {
                
                var inherit = function (){},
                    proto = getPrototype(base);
                
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
        
        if ("WeakMap" in window){
          
          privateRecord = new WeakMap();
          
          createPrivateRecord = function (self,privateHolder) {
            var holder = new privateHolder;
            
            createUnenumProp(holder.constructor,"__is_private__",1);
            
            privateRecord.set(self,holder);
          };
          
          getPrivateRecord = function (self) {
            if (privateRecord.has(self)){
              return privateRecord.get(self);
            } else if (self.constructor === "__is_private__"){
              return self;
            };
          };
        } else {
          
          createPrivateRecord = function (self,privateHolder) {
            if (!self.__typeid__){
              
              var holder = new privateHolder;
              
              createUnenumProp(holder.constructor,"__is_private__",1);
              
              createUnenumProp(self,"__private__",holder);
            };
          };
          
          getPrivateRecord = function (self) {
            if (self.__private__){
              return self.__private__;
            } else if (self.constructor === "__is_private__"){
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
          var assert = _mochaLocalExport.assert = (console && console.assert)?function (expect,exp,str,line,filename) {
                console.assert(expect === exp,"assertion failed : "+str+"\nexpect "+expect+" but got "+exp+"\nin file "+filename+" at : "+line)
              } : function (expect,exp,str,line,filename) {
                expect !== exp && Runtime.throwException("assertion failed : "+str+"\nexpect "+expect+" but got "+exp+"\nin file "+filename+" at : "+line);
              };
        }.call(this);
        return _mochaLocalExport;
      }();
  
  !("StopIteration" in window) && (window.StopIteration =  {
    toString : function () {
      return "[object StopIteration]";
    }
  });
  
  function Tuple() {
    var args = Runtime.toArray(arguments,1),
        ret = {};
    
    ret.length = 0;
    
    [].push.apply(ret,args);
    
    Runtime.createTuple(ret,arguments.length);
    return ret;
  }
  function Record(member) {
    return Runtime.createRecord(member);
  }
  __LINE__ = 0;
  !function () {
    try {
      var __FILE__ = "/Users/aono_taketoshi/github/mocha/src/test/js/harmony/yield_test.js",
          __LINE__ = 0;
      __LINE__ = 2;
      _mochaGlobalExport['yield_test.js;1'] = {};
      
      __LINE__ = 3;
      var _mochaGlobalAlias = _mochaGlobalExport['yield_test.js;1'],
          generator,
          tests =  {
            case1 : function () {
              try {
                function yieldTest2() {
                  try {
                    __LINE__ = 4;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 4;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 4;
                    var _yieldState = 0;
                    
                    __LINE__ = 5;
                    var i;
                    
                    __LINE__ = 4;
                    var _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                          try {
                            __LINE__ = 4;
                            if (!_isYieldSend){
                              
                              __LINE__ = 4;
                              _mochaIsNewBorn = false;
                            } else if (_isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined){
                              
                              __LINE__ = 4;
                              Runtime.exceptionHandler('attempt to send to newborn generator.');
                            };
                            
                            __LINE__ = 4;
                            while (1){
                              __LINE__ = 4;
                              switch (_yieldState) {
                                case 0 :
                                  
                                  __LINE__ = 5;
                                  i = 0;
                                  
                                  __LINE__ = 5;
                                  if (!(i<10)){
                                    
                                    __LINE__ = 5;
                                    _yieldState = -1;
                                    __LINE__ = 5;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 6;
                                  _yieldState = 2;
                                  __LINE__ = 6;
                                  return i;
                                case 2 :
                                  
                                  __LINE__ = 5;
                                  i ++ ;
                                  
                                  __LINE__ = 5;
                                  if (i<10){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 1;
                                    __LINE__ = 5;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 4;
                                  if (_isYieldSafe){
                                    __LINE__ = 4;
                                    return undefined;
                                  } else {
                                    __LINE__ = 4;
                                    Runtime.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch(e){
                            Runtime.exceptionHandler(__LINE__, __FILE__, e);
                          }
                        };
                    __LINE__ = 4;
                    return Runtime.createGenerator(_mochaGenerator,
                    function () {
                      try {
                        __LINE__ = 4;
                        _yieldState = -1;
                      } catch(e){
                        Runtime.exceptionHandler(__LINE__, __FILE__, e);
                      }
                    },this);
                  } catch(e){
                    Runtime.exceptionHandler(__LINE__, __FILE__, e);
                  }
                }
                __LINE__ = 10;
                generator = yieldTest2();
                
                __LINE__ = 12;
                Runtime.assert(true,generator.next() === 0,"generator.next() === 0",12,'./yield_test.js');
                
                __LINE__ = 13;
                Runtime.assert(true,generator.next() === 1,"generator.next() === 1",13,'./yield_test.js');
                
                __LINE__ = 14;
                Runtime.assert(true,generator.next() === 2,"generator.next() === 2",14,'./yield_test.js');
                
                __LINE__ = 15;
                Runtime.assert(true,generator.next() === 3,"generator.next() === 3",15,'./yield_test.js');
                
                __LINE__ = 16;
                Runtime.assert(true,generator.next() === 4,"generator.next() === 4",16,'./yield_test.js');
                
                __LINE__ = 17;
                Runtime.assert(true,generator.next() === 5,"generator.next() === 5",17,'./yield_test.js');
                
                __LINE__ = 18;
                Runtime.assert(true,generator.next() === 6,"generator.next() === 6",18,'./yield_test.js');
                
                __LINE__ = 19;
                Runtime.assert(true,generator.next() === 7,"generator.next() === 7",19,'./yield_test.js');
                
                __LINE__ = 20;
                Runtime.assert(true,generator.next() === 8,"generator.next() === 8",20,'./yield_test.js');
                
                __LINE__ = 21;
                Runtime.assert(true,generator.next() === 9,"generator.next() === 9",21,'./yield_test.js');
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            },
            case2 : function () {
              try {
                function yieldTest3() {
                  try {
                    __LINE__ = 25;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 25;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 25;
                    var _yieldState = 0;
                    
                    __LINE__ = 26;
                    var i;
                    
                    __LINE__ = 25;
                    var _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                          try {
                            __LINE__ = 25;
                            if (!_isYieldSend){
                              
                              __LINE__ = 25;
                              _mochaIsNewBorn = false;
                            } else if (_isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined){
                              
                              __LINE__ = 25;
                              Runtime.exceptionHandler('attempt to send to newborn generator.');
                            };
                            
                            __LINE__ = 25;
                            while (1){
                              __LINE__ = 25;
                              switch (_yieldState) {
                                case 0 :
                                  
                                  __LINE__ = 26;
                                  i = 0;
                                  
                                  __LINE__ = 26;
                                  if (!(i<10)){
                                    
                                    __LINE__ = 26;
                                    _yieldState = -1;
                                    __LINE__ = 26;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 27;
                                  if (i%2 === 0){
                                    
                                    __LINE__ = 27;
                                    _yieldState = 2;
                                    __LINE__ = 27;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 27;
                                    _yieldState = 3;
                                    __LINE__ = 27;
                                    break;
                                  };
                                case 2 :
                                  
                                  __LINE__ = 28;
                                  _yieldState = 3;
                                  __LINE__ = 28;
                                  return i;
                                case 3 :
                                  
                                  __LINE__ = 27;
                                  _yieldState = 4;
                                  __LINE__ = 27;
                                  break;
                                case 4 :
                                  
                                  __LINE__ = 26;
                                  i ++ ;
                                  
                                  __LINE__ = 26;
                                  if (i<10){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 1;
                                    __LINE__ = 26;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 25;
                                  if (_isYieldSafe){
                                    __LINE__ = 25;
                                    return undefined;
                                  } else {
                                    __LINE__ = 25;
                                    Runtime.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch(e){
                            Runtime.exceptionHandler(__LINE__, __FILE__, e);
                          }
                        };
                    __LINE__ = 25;
                    return Runtime.createGenerator(_mochaGenerator,
                    function () {
                      try {
                        __LINE__ = 25;
                        _yieldState = -1;
                      } catch(e){
                        Runtime.exceptionHandler(__LINE__, __FILE__, e);
                      }
                    },this);
                  } catch(e){
                    Runtime.exceptionHandler(__LINE__, __FILE__, e);
                  }
                }
                __LINE__ = 32;
                generator = yieldTest3();
                
                __LINE__ = 33;
                Runtime.assert(true,generator.next() === 0,"generator.next() === 0",33,'./yield_test.js');
                
                __LINE__ = 34;
                Runtime.assert(true,generator.next() === 2,"generator.next() === 2",34,'./yield_test.js');
                
                __LINE__ = 35;
                Runtime.assert(true,generator.next() === 4,"generator.next() === 4",35,'./yield_test.js');
                
                __LINE__ = 36;
                Runtime.assert(true,generator.next() === 6,"generator.next() === 6",36,'./yield_test.js');
                
                __LINE__ = 37;
                Runtime.assert(true,generator.next() === 8,"generator.next() === 8",37,'./yield_test.js');
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            },
            case3 : function () {
              try {
                function yieldTest4() {
                  try {
                    __LINE__ = 40;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 40;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 40;
                    var _yieldState = 0;
                    
                    __LINE__ = 42;
                    var j;
                    
                    __LINE__ = 41;
                    var i;
                    
                    __LINE__ = 40;
                    var _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                          try {
                            __LINE__ = 40;
                            if (!_isYieldSend){
                              
                              __LINE__ = 40;
                              _mochaIsNewBorn = false;
                            } else if (_isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined){
                              
                              __LINE__ = 40;
                              Runtime.exceptionHandler('attempt to send to newborn generator.');
                            };
                            
                            __LINE__ = 40;
                            while (1){
                              __LINE__ = 40;
                              switch (_yieldState) {
                                case 0 :
                                  
                                  __LINE__ = 41;
                                  i = 0;
                                  
                                  __LINE__ = 41;
                                  if (!(i<10)){
                                    
                                    __LINE__ = 41;
                                    _yieldState = -1;
                                    __LINE__ = 41;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 42;
                                  j = 0;
                                  
                                  __LINE__ = 42;
                                  if (!(j<10)){
                                    
                                    __LINE__ = 42;
                                    _yieldState = 6;
                                    __LINE__ = 42;
                                    break;
                                  };
                                case 2 :
                                  
                                  __LINE__ = 43;
                                  if (j%2 === 0){
                                    
                                    __LINE__ = 43;
                                    _yieldState = 3;
                                    __LINE__ = 43;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 43;
                                    _yieldState = 4;
                                    __LINE__ = 43;
                                    break;
                                  };
                                case 3 :
                                  
                                  __LINE__ = 44;
                                  _yieldState = 4;
                                  __LINE__ = 44;
                                  return j;
                                case 4 :
                                  
                                  __LINE__ = 43;
                                  _yieldState = 5;
                                  __LINE__ = 43;
                                  break;
                                case 5 :
                                  
                                  __LINE__ = 42;
                                  j ++ ;
                                  
                                  __LINE__ = 42;
                                  if (j<10){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 2;
                                    __LINE__ = 42;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = 6;
                                  };
                                case 6 :
                                  
                                  __LINE__ = 41;
                                  i ++ ;
                                  
                                  __LINE__ = 41;
                                  if (i<10){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 1;
                                    __LINE__ = 41;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 40;
                                  if (_isYieldSafe){
                                    __LINE__ = 40;
                                    return undefined;
                                  } else {
                                    __LINE__ = 40;
                                    Runtime.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch(e){
                            Runtime.exceptionHandler(__LINE__, __FILE__, e);
                          }
                        };
                    __LINE__ = 40;
                    return Runtime.createGenerator(_mochaGenerator,
                    function () {
                      try {
                        __LINE__ = 40;
                        _yieldState = -1;
                      } catch(e){
                        Runtime.exceptionHandler(__LINE__, __FILE__, e);
                      }
                    },this);
                  } catch(e){
                    Runtime.exceptionHandler(__LINE__, __FILE__, e);
                  }
                }
                __LINE__ = 49;
                generator = yieldTest4();
                
                __LINE__ = 50;
                Runtime.assert(true,generator.next() === 0,"generator.next() === 0",50,'./yield_test.js');
                
                __LINE__ = 51;
                Runtime.assert(true,generator.next() === 2,"generator.next() === 2",51,'./yield_test.js');
                
                __LINE__ = 52;
                Runtime.assert(true,generator.next() === 4,"generator.next() === 4",52,'./yield_test.js');
                
                __LINE__ = 53;
                Runtime.assert(true,generator.next() === 6,"generator.next() === 6",53,'./yield_test.js');
                
                __LINE__ = 54;
                Runtime.assert(true,generator.next() === 8,"generator.next() === 8",54,'./yield_test.js');
                
                __LINE__ = 56;
                Runtime.assert(true,generator.next() === 0,"generator.next() === 0",56,'./yield_test.js');
                
                __LINE__ = 57;
                Runtime.assert(true,generator.next() === 2,"generator.next() === 2",57,'./yield_test.js');
                
                __LINE__ = 58;
                Runtime.assert(true,generator.next() === 4,"generator.next() === 4",58,'./yield_test.js');
                
                __LINE__ = 59;
                Runtime.assert(true,generator.next() === 6,"generator.next() === 6",59,'./yield_test.js');
                
                __LINE__ = 60;
                Runtime.assert(true,generator.next() === 8,"generator.next() === 8",60,'./yield_test.js');
                
                __LINE__ = 62;
                Runtime.assert(true,generator.next() === 0,"generator.next() === 0",62,'./yield_test.js');
                
                __LINE__ = 63;
                Runtime.assert(true,generator.next() === 2,"generator.next() === 2",63,'./yield_test.js');
                
                __LINE__ = 64;
                Runtime.assert(true,generator.next() === 4,"generator.next() === 4",64,'./yield_test.js');
                
                __LINE__ = 65;
                Runtime.assert(true,generator.next() === 6,"generator.next() === 6",65,'./yield_test.js');
                
                __LINE__ = 66;
                Runtime.assert(true,generator.next() === 8,"generator.next() === 8",66,'./yield_test.js');
                
                __LINE__ = 68;
                Runtime.assert(true,generator.next() === 0,"generator.next() === 0",68,'./yield_test.js');
                
                __LINE__ = 69;
                Runtime.assert(true,generator.next() === 2,"generator.next() === 2",69,'./yield_test.js');
                
                __LINE__ = 70;
                Runtime.assert(true,generator.next() === 4,"generator.next() === 4",70,'./yield_test.js');
                
                __LINE__ = 71;
                Runtime.assert(true,generator.next() === 6,"generator.next() === 6",71,'./yield_test.js');
                
                __LINE__ = 72;
                Runtime.assert(true,generator.next() === 8,"generator.next() === 8",72,'./yield_test.js');
                
                __LINE__ = 74;
                Runtime.assert(true,generator.next() === 0,"generator.next() === 0",74,'./yield_test.js');
                
                __LINE__ = 75;
                Runtime.assert(true,generator.next() === 2,"generator.next() === 2",75,'./yield_test.js');
                
                __LINE__ = 76;
                Runtime.assert(true,generator.next() === 4,"generator.next() === 4",76,'./yield_test.js');
                
                __LINE__ = 77;
                Runtime.assert(true,generator.next() === 6,"generator.next() === 6",77,'./yield_test.js');
                
                __LINE__ = 78;
                Runtime.assert(true,generator.next() === 8,"generator.next() === 8",78,'./yield_test.js');
                
                __LINE__ = 80;
                Runtime.assert(true,generator.next() === 0,"generator.next() === 0",80,'./yield_test.js');
                
                __LINE__ = 81;
                Runtime.assert(true,generator.next() === 2,"generator.next() === 2",81,'./yield_test.js');
                
                __LINE__ = 82;
                Runtime.assert(true,generator.next() === 4,"generator.next() === 4",82,'./yield_test.js');
                
                __LINE__ = 83;
                Runtime.assert(true,generator.next() === 6,"generator.next() === 6",83,'./yield_test.js');
                
                __LINE__ = 84;
                Runtime.assert(true,generator.next() === 8,"generator.next() === 8",84,'./yield_test.js');
                
                __LINE__ = 86;
                Runtime.assert(true,generator.next() === 0,"generator.next() === 0",86,'./yield_test.js');
                
                __LINE__ = 87;
                Runtime.assert(true,generator.next() === 2,"generator.next() === 2",87,'./yield_test.js');
                
                __LINE__ = 88;
                Runtime.assert(true,generator.next() === 4,"generator.next() === 4",88,'./yield_test.js');
                
                __LINE__ = 89;
                Runtime.assert(true,generator.next() === 6,"generator.next() === 6",89,'./yield_test.js');
                
                __LINE__ = 90;
                Runtime.assert(true,generator.next() === 8,"generator.next() === 8",90,'./yield_test.js');
                
                __LINE__ = 92;
                Runtime.assert(true,generator.next() === 0,"generator.next() === 0",92,'./yield_test.js');
                
                __LINE__ = 93;
                Runtime.assert(true,generator.next() === 2,"generator.next() === 2",93,'./yield_test.js');
                
                __LINE__ = 94;
                Runtime.assert(true,generator.next() === 4,"generator.next() === 4",94,'./yield_test.js');
                
                __LINE__ = 95;
                Runtime.assert(true,generator.next() === 6,"generator.next() === 6",95,'./yield_test.js');
                
                __LINE__ = 96;
                Runtime.assert(true,generator.next() === 8,"generator.next() === 8",96,'./yield_test.js');
                
                __LINE__ = 98;
                Runtime.assert(true,generator.next() === 0,"generator.next() === 0",98,'./yield_test.js');
                
                __LINE__ = 99;
                Runtime.assert(true,generator.next() === 2,"generator.next() === 2",99,'./yield_test.js');
                
                __LINE__ = 100;
                Runtime.assert(true,generator.next() === 4,"generator.next() === 4",100,'./yield_test.js');
                
                __LINE__ = 101;
                Runtime.assert(true,generator.next() === 6,"generator.next() === 6",101,'./yield_test.js');
                
                __LINE__ = 102;
                Runtime.assert(true,generator.next() === 8,"generator.next() === 8",102,'./yield_test.js');
                
                __LINE__ = 104;
                Runtime.assert(true,generator.next() === 0,"generator.next() === 0",104,'./yield_test.js');
                
                __LINE__ = 105;
                Runtime.assert(true,generator.next() === 2,"generator.next() === 2",105,'./yield_test.js');
                
                __LINE__ = 106;
                Runtime.assert(true,generator.next() === 4,"generator.next() === 4",106,'./yield_test.js');
                
                __LINE__ = 107;
                Runtime.assert(true,generator.next() === 6,"generator.next() === 6",107,'./yield_test.js');
                
                __LINE__ = 108;
                Runtime.assert(true,generator.next() === 8,"generator.next() === 8",108,'./yield_test.js');
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            },
            case4 : function () {
              try {
                function yieldTest5() {
                  try {
                    __LINE__ = 111;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 111;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 111;
                    var _yieldState = 0;
                    
                    __LINE__ = 112;
                    var i;
                    
                    __LINE__ = 111;
                    var _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                          try {
                            __LINE__ = 111;
                            if (!_isYieldSend){
                              
                              __LINE__ = 111;
                              _mochaIsNewBorn = false;
                            } else if (_isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined){
                              
                              __LINE__ = 111;
                              Runtime.exceptionHandler('attempt to send to newborn generator.');
                            };
                            
                            __LINE__ = 111;
                            while (1){
                              __LINE__ = 111;
                              switch (_yieldState) {
                                case 0 :
                                  
                                  __LINE__ = 112;
                                  i = 0;
                                  
                                  __LINE__ = 113;
                                  if (!( ++ i<10)){
                                    
                                    __LINE__ = 113;
                                    _yieldState = -1;
                                    __LINE__ = 113;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 114;
                                  _yieldState = 2;
                                  __LINE__ = 114;
                                  return i;
                                case 2 :
                                  
                                  __LINE__ = 113;
                                  if ( ++ i<10){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 1;
                                    __LINE__ = 113;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 111;
                                  if (_isYieldSafe){
                                    __LINE__ = 111;
                                    return undefined;
                                  } else {
                                    __LINE__ = 111;
                                    Runtime.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch(e){
                            Runtime.exceptionHandler(__LINE__, __FILE__, e);
                          }
                        };
                    __LINE__ = 111;
                    return Runtime.createGenerator(_mochaGenerator,
                    function () {
                      try {
                        __LINE__ = 111;
                        _yieldState = -1;
                      } catch(e){
                        Runtime.exceptionHandler(__LINE__, __FILE__, e);
                      }
                    },this);
                  } catch(e){
                    Runtime.exceptionHandler(__LINE__, __FILE__, e);
                  }
                }
                __LINE__ = 118;
                generator = yieldTest5();
                
                __LINE__ = 119;
                Runtime.assert(true,generator.next() === 1,"generator.next() === 1",119,'./yield_test.js');
                
                __LINE__ = 120;
                Runtime.assert(true,generator.next() === 2,"generator.next() === 2",120,'./yield_test.js');
                
                __LINE__ = 121;
                Runtime.assert(true,generator.next() === 3,"generator.next() === 3",121,'./yield_test.js');
                
                __LINE__ = 122;
                Runtime.assert(true,generator.next() === 4,"generator.next() === 4",122,'./yield_test.js');
                
                __LINE__ = 123;
                Runtime.assert(true,generator.next() === 5,"generator.next() === 5",123,'./yield_test.js');
                
                __LINE__ = 124;
                Runtime.assert(true,generator.next() === 6,"generator.next() === 6",124,'./yield_test.js');
                
                __LINE__ = 125;
                Runtime.assert(true,generator.next() === 7,"generator.next() === 7",125,'./yield_test.js');
                
                __LINE__ = 126;
                Runtime.assert(true,generator.next() === 8,"generator.next() === 8",126,'./yield_test.js');
                
                __LINE__ = 127;
                Runtime.assert(true,generator.next() === 9,"generator.next() === 9",127,'./yield_test.js');
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            },
            case5 : function () {
              try {
                function yieldTest6() {
                  try {
                    __LINE__ = 130;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 130;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 130;
                    var _yieldState = 0;
                    
                    __LINE__ = 131;
                    var i;
                    
                    __LINE__ = 130;
                    var _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                          try {
                            __LINE__ = 130;
                            if (!_isYieldSend){
                              
                              __LINE__ = 130;
                              _mochaIsNewBorn = false;
                            } else if (_isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined){
                              
                              __LINE__ = 130;
                              Runtime.exceptionHandler('attempt to send to newborn generator.');
                            };
                            
                            __LINE__ = 130;
                            while (1){
                              __LINE__ = 130;
                              switch (_yieldState) {
                                case 0 :
                                  
                                  __LINE__ = 131;
                                  i = 0;
                                case 1 :
                                  
                                  __LINE__ = 133;
                                  _yieldState = 2;
                                  __LINE__ = 133;
                                  return i;
                                case 2 :
                                  
                                  __LINE__ = 134;
                                  if ( ++ i<10){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 1;
                                    __LINE__ = 134;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = 3;
                                  };
                                case 3 :
                                case -1 :
                                  
                                  __LINE__ = 130;
                                  if (_isYieldSafe){
                                    __LINE__ = 130;
                                    return undefined;
                                  } else {
                                    __LINE__ = 130;
                                    Runtime.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch(e){
                            Runtime.exceptionHandler(__LINE__, __FILE__, e);
                          }
                        };
                    __LINE__ = 130;
                    return Runtime.createGenerator(_mochaGenerator,
                    function () {
                      try {
                        __LINE__ = 130;
                        _yieldState = -1;
                      } catch(e){
                        Runtime.exceptionHandler(__LINE__, __FILE__, e);
                      }
                    },this);
                  } catch(e){
                    Runtime.exceptionHandler(__LINE__, __FILE__, e);
                  }
                }
                __LINE__ = 137;
                generator = yieldTest6();
                
                __LINE__ = 138;
                Runtime.assert(true,generator.next() === 0,"generator.next() === 0",138,'./yield_test.js');
                
                __LINE__ = 139;
                Runtime.assert(true,generator.next() === 1,"generator.next() === 1",139,'./yield_test.js');
                
                __LINE__ = 140;
                Runtime.assert(true,generator.next() === 2,"generator.next() === 2",140,'./yield_test.js');
                
                __LINE__ = 141;
                Runtime.assert(true,generator.next() === 3,"generator.next() === 3",141,'./yield_test.js');
                
                __LINE__ = 142;
                Runtime.assert(true,generator.next() === 4,"generator.next() === 4",142,'./yield_test.js');
                
                __LINE__ = 143;
                Runtime.assert(true,generator.next() === 5,"generator.next() === 5",143,'./yield_test.js');
                
                __LINE__ = 144;
                Runtime.assert(true,generator.next() === 6,"generator.next() === 6",144,'./yield_test.js');
                
                __LINE__ = 145;
                Runtime.assert(true,generator.next() === 7,"generator.next() === 7",145,'./yield_test.js');
                
                __LINE__ = 146;
                Runtime.assert(true,generator.next() === 8,"generator.next() === 8",146,'./yield_test.js');
                
                __LINE__ = 147;
                Runtime.assert(true,generator.next() === 9,"generator.next() === 9",147,'./yield_test.js');
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            },
            case6 : function () {
              try {
                function yieldTest7() {
                  try {
                    __LINE__ = 150;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 150;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 150;
                    var _yieldState = 0;
                    
                    __LINE__ = 151;
                    var i;
                    
                    __LINE__ = 152;
                    var m;
                    
                    __LINE__ = 150;
                    var _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                          try {
                            __LINE__ = 150;
                            if (!_isYieldSend){
                              
                              __LINE__ = 150;
                              _mochaIsNewBorn = false;
                            } else if (_isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined){
                              
                              __LINE__ = 150;
                              Runtime.exceptionHandler('attempt to send to newborn generator.');
                            };
                            
                            __LINE__ = 150;
                            while (1){
                              __LINE__ = 150;
                              switch (_yieldState) {
                                case 0 :
                                  
                                  __LINE__ = 151;
                                  i = 0;
                                  
                                  __LINE__ = 151;
                                  if (!(i<10)){
                                    
                                    __LINE__ = 151;
                                    _yieldState = -1;
                                    __LINE__ = 151;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 152;
                                  _yieldState = 2;
                                  __LINE__ = 152;
                                  return i;
                                case 2 :
                                  
                                  __LINE__ = 152;
                                  _yieldResult = _isYieldSend && arguments.length>2?Runtime.toArray(arguments,2)[0] : _isYieldSend?i : undefined;
                                  
                                  __LINE__ = 152;
                                  m = _yieldResult;
                                  
                                  __LINE__ = 153;
                                  if (m === true){
                                    
                                    __LINE__ = 153;
                                    _yieldState = 3;
                                    __LINE__ = 153;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 153;
                                    _yieldState = 5;
                                    __LINE__ = 153;
                                    break;
                                  };
                                case 3 :
                                  
                                  __LINE__ = 154;
                                  _yieldState = 4;
                                  __LINE__ = 154;
                                  return i+1;
                                case 4 :
                                  
                                  __LINE__ = 153;
                                  _yieldState = 9;
                                  __LINE__ = 153;
                                  break;
                                case 5 :
                                  
                                  __LINE__ = 155;
                                  if (m === false){
                                    
                                    __LINE__ = 155;
                                    _yieldState = 6;
                                    __LINE__ = 155;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 155;
                                    _yieldState = 8;
                                    __LINE__ = 155;
                                    break;
                                  };
                                case 6 :
                                  
                                  __LINE__ = 156;
                                  _yieldState = 7;
                                  __LINE__ = 156;
                                  return i-1;
                                case 7 :
                                  
                                  __LINE__ = 155;
                                  _yieldState = 9;
                                  __LINE__ = 155;
                                  break;
                                case 8 :
                                  
                                  __LINE__ = 158;
                                  _yieldState = 9;
                                  __LINE__ = 158;
                                  return i;
                                case 9 :
                                  
                                  __LINE__ = 151;
                                  i ++ ;
                                  
                                  __LINE__ = 151;
                                  if (i<10){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 1;
                                    __LINE__ = 151;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 150;
                                  if (_isYieldSafe){
                                    __LINE__ = 150;
                                    return undefined;
                                  } else {
                                    __LINE__ = 150;
                                    Runtime.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch(e){
                            Runtime.exceptionHandler(__LINE__, __FILE__, e);
                          }
                        };
                    __LINE__ = 150;
                    return Runtime.createGenerator(_mochaGenerator,
                    function () {
                      try {
                        __LINE__ = 150;
                        _yieldState = -1;
                      } catch(e){
                        Runtime.exceptionHandler(__LINE__, __FILE__, e);
                      }
                    },this);
                  } catch(e){
                    Runtime.exceptionHandler(__LINE__, __FILE__, e);
                  }
                }
                __LINE__ = 163;
                generator = yieldTest7();
                
                __LINE__ = 164;
                Runtime.assert(true,generator.next() === 0,"generator.next() === 0",164,'./yield_test.js');
                
                __LINE__ = 165;
                Runtime.assert(true,generator.send(true) === 1,"generator.send(true) === 1",165,'./yield_test.js');
                
                __LINE__ = 166;
                Runtime.assert(true,generator.send(false) === 1,"generator.send(false) === 1",166,'./yield_test.js');
                
                __LINE__ = 167;
                Runtime.assert(true,generator.send(true) === 2,"generator.send(true) === 2",167,'./yield_test.js');
                
                __LINE__ = 168;
                Runtime.assert(true,generator.send(false) === 2,"generator.send(false) === 2",168,'./yield_test.js');
                
                __LINE__ = 169;
                Runtime.assert(true,generator.send(true) === 3,"generator.send(true) === 3",169,'./yield_test.js');
                
                __LINE__ = 170;
                Runtime.assert(true,generator.send(true) === 3,"generator.send(true) === 3",170,'./yield_test.js');
                
                __LINE__ = 171;
                Runtime.assert(true,generator.send(true) === 4,"generator.send(true) === 4",171,'./yield_test.js');
                
                __LINE__ = 172;
                Runtime.assert(true,generator.send(false) === 4,"generator.send(false) === 4",172,'./yield_test.js');
                
                __LINE__ = 173;
                Runtime.assert(true,generator.send(true) === 5,"generator.send(true) === 5",173,'./yield_test.js');
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            },
            case7 : function () {
              try {
                function yieldTest8() {
                  try {
                    __LINE__ = 176;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 176;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 176;
                    var _yieldState = 0;
                    
                    __LINE__ = 179;
                    var j;
                    
                    __LINE__ = 177;
                    var i;
                    
                    __LINE__ = 178;
                    var m;
                    
                    __LINE__ = 176;
                    var _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                          try {
                            __LINE__ = 176;
                            if (!_isYieldSend){
                              
                              __LINE__ = 176;
                              _mochaIsNewBorn = false;
                            } else if (_isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined){
                              
                              __LINE__ = 176;
                              Runtime.exceptionHandler('attempt to send to newborn generator.');
                            };
                            
                            __LINE__ = 176;
                            while (1){
                              __LINE__ = 176;
                              switch (_yieldState) {
                                case 0 :
                                  
                                  __LINE__ = 177;
                                  i = 0;
                                  
                                  __LINE__ = 177;
                                  if (!(i<10)){
                                    
                                    __LINE__ = 177;
                                    _yieldState = -1;
                                    __LINE__ = 177;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 178;
                                  _yieldState = 2;
                                  __LINE__ = 178;
                                  return i;
                                case 2 :
                                  
                                  __LINE__ = 178;
                                  _yieldResult = _isYieldSend && arguments.length>2?Runtime.toArray(arguments,2)[0] : _isYieldSend?i : undefined;
                                  
                                  __LINE__ = 178;
                                  m = _yieldResult;
                                  
                                  __LINE__ = 179;
                                  j = 0;
                                  
                                  __LINE__ = 179;
                                  if (!(j<10)){
                                    
                                    __LINE__ = 179;
                                    _yieldState = 11;
                                    __LINE__ = 179;
                                    break;
                                  };
                                case 3 :
                                  
                                  __LINE__ = 180;
                                  if (m === true){
                                    
                                    __LINE__ = 180;
                                    _yieldState = 4;
                                    __LINE__ = 180;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 180;
                                    _yieldState = 6;
                                    __LINE__ = 180;
                                    break;
                                  };
                                case 4 :
                                  
                                  __LINE__ = 181;
                                  _yieldState = 5;
                                  __LINE__ = 181;
                                  return j*2;
                                case 5 :
                                  
                                  __LINE__ = 180;
                                  _yieldState = 10;
                                  __LINE__ = 180;
                                  break;
                                case 6 :
                                  
                                  __LINE__ = 182;
                                  if (m === false){
                                    
                                    __LINE__ = 182;
                                    _yieldState = 7;
                                    __LINE__ = 182;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 182;
                                    _yieldState = 9;
                                    __LINE__ = 182;
                                    break;
                                  };
                                case 7 :
                                  
                                  __LINE__ = 183;
                                  _yieldState = 8;
                                  __LINE__ = 183;
                                  return j/2;
                                case 8 :
                                  
                                  __LINE__ = 182;
                                  _yieldState = 10;
                                  __LINE__ = 182;
                                  break;
                                case 9 :
                                  
                                  __LINE__ = 185;
                                  _yieldState = 10;
                                  __LINE__ = 185;
                                  return j;
                                case 10 :
                                  
                                  __LINE__ = 179;
                                  j ++ ;
                                  
                                  __LINE__ = 179;
                                  if (j<10){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 3;
                                    __LINE__ = 179;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = 11;
                                  };
                                case 11 :
                                  
                                  __LINE__ = 177;
                                  i ++ ;
                                  
                                  __LINE__ = 177;
                                  if (i<10){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 1;
                                    __LINE__ = 177;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 176;
                                  if (_isYieldSafe){
                                    __LINE__ = 176;
                                    return undefined;
                                  } else {
                                    __LINE__ = 176;
                                    Runtime.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch(e){
                            Runtime.exceptionHandler(__LINE__, __FILE__, e);
                          }
                        };
                    __LINE__ = 176;
                    return Runtime.createGenerator(_mochaGenerator,
                    function () {
                      try {
                        __LINE__ = 176;
                        _yieldState = -1;
                      } catch(e){
                        Runtime.exceptionHandler(__LINE__, __FILE__, e);
                      }
                    },this);
                  } catch(e){
                    Runtime.exceptionHandler(__LINE__, __FILE__, e);
                  }
                }
                __LINE__ = 192;
                generator = yieldTest8();
                
                __LINE__ = 193;
                Runtime.assert(true,generator.next() === 0,"generator.next() === 0",193,'./yield_test.js');
                
                __LINE__ = 194;
                Runtime.assert(true,generator.send(true) === 0,"generator.send(true) === 0",194,'./yield_test.js');
                
                __LINE__ = 195;
                Runtime.assert(true,generator.send(false) === 2,"generator.send(false) === 2",195,'./yield_test.js');
                
                __LINE__ = 196;
                Runtime.assert(true,generator.send(true) === 4,"generator.send(true) === 4",196,'./yield_test.js');
                
                __LINE__ = 197;
                Runtime.assert(true,generator.send(false) === 6,"generator.send(false) === 6",197,'./yield_test.js');
                
                __LINE__ = 198;
                Runtime.assert(true,generator.send(true) === 8,"generator.send(true) === 8",198,'./yield_test.js');
                
                __LINE__ = 199;
                Runtime.assert(true,generator.send(true) === 10,"generator.send(true) === 10",199,'./yield_test.js');
                
                __LINE__ = 200;
                Runtime.assert(true,generator.send(true) === 12,"generator.send(true) === 12",200,'./yield_test.js');
                
                __LINE__ = 201;
                Runtime.assert(true,generator.send(false) === 14,"generator.send(false) === 14",201,'./yield_test.js');
                
                __LINE__ = 202;
                Runtime.assert(true,generator.send(true) === 16,"generator.send(true) === 16",202,'./yield_test.js');
                
                __LINE__ = 203;
                Runtime.assert(true,generator.send(true) === 18,"generator.send(true) === 18",203,'./yield_test.js');
                
                __LINE__ = 204;
                Runtime.assert(true,generator.send(false) === 1,"generator.send(false) === 1",204,'./yield_test.js');
                
                __LINE__ = 205;
                Runtime.assert(true,generator.send(true) === 0,"generator.send(true) === 0",205,'./yield_test.js');
                
                __LINE__ = 206;
                Runtime.assert(true,generator.send(false) === 2,"generator.send(false) === 2",206,'./yield_test.js');
                
                __LINE__ = 207;
                Runtime.assert(true,generator.send(true) === 4,"generator.send(true) === 4",207,'./yield_test.js');
                
                __LINE__ = 208;
                Runtime.assert(true,generator.send(true) === 6,"generator.send(true) === 6",208,'./yield_test.js');
                
                __LINE__ = 209;
                Runtime.assert(true,generator.send(true) === 8,"generator.send(true) === 8",209,'./yield_test.js');
                
                __LINE__ = 210;
                Runtime.assert(true,generator.send(false) === 10,"generator.send(false) === 10",210,'./yield_test.js');
                
                __LINE__ = 211;
                Runtime.assert(true,generator.send(true) === 12,"generator.send(true) === 12",211,'./yield_test.js');
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            },
            case8 : function () {
              try {
                function yieldTest9() {
                  try {
                    __LINE__ = 215;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 215;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 215;
                    var _yieldState = 0;
                    
                    __LINE__ = 217;
                    var j;
                    
                    __LINE__ = 216;
                    var i;
                    
                    __LINE__ = 218;
                    var m;
                    
                    __LINE__ = 215;
                    var _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                          try {
                            __LINE__ = 215;
                            if (!_isYieldSend){
                              
                              __LINE__ = 215;
                              _mochaIsNewBorn = false;
                            } else if (_isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined){
                              
                              __LINE__ = 215;
                              Runtime.exceptionHandler('attempt to send to newborn generator.');
                            };
                            
                            __LINE__ = 215;
                            while (1){
                              __LINE__ = 215;
                              switch (_yieldState) {
                                case 0 :
                                  
                                  __LINE__ = 216;
                                  i = 0;
                                  
                                  __LINE__ = 216;
                                  if (!(i<10)){
                                    
                                    __LINE__ = 216;
                                    _yieldState = -1;
                                    __LINE__ = 216;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 217;
                                  j = 0;
                                  
                                  __LINE__ = 217;
                                  if (!(j<10)){
                                    
                                    __LINE__ = 217;
                                    _yieldState = 11;
                                    __LINE__ = 217;
                                    break;
                                  };
                                case 2 :
                                  
                                  __LINE__ = 218;
                                  _yieldState = 3;
                                  __LINE__ = 218;
                                  return i;
                                case 3 :
                                  
                                  __LINE__ = 218;
                                  _yieldResult = _isYieldSend && arguments.length>2?Runtime.toArray(arguments,2)[0] : _isYieldSend?i : undefined;
                                  
                                  __LINE__ = 218;
                                  m = _yieldResult;
                                  
                                  __LINE__ = 219;
                                  if (m === true){
                                    
                                    __LINE__ = 219;
                                    _yieldState = 4;
                                    __LINE__ = 219;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 219;
                                    _yieldState = 6;
                                    __LINE__ = 219;
                                    break;
                                  };
                                case 4 :
                                  
                                  __LINE__ = 220;
                                  _yieldState = 5;
                                  __LINE__ = 220;
                                  return j*2;
                                case 5 :
                                  
                                  __LINE__ = 219;
                                  _yieldState = 10;
                                  __LINE__ = 219;
                                  break;
                                case 6 :
                                  
                                  __LINE__ = 221;
                                  if (m === false){
                                    
                                    __LINE__ = 221;
                                    _yieldState = 7;
                                    __LINE__ = 221;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 221;
                                    _yieldState = 9;
                                    __LINE__ = 221;
                                    break;
                                  };
                                case 7 :
                                  
                                  __LINE__ = 222;
                                  _yieldState = 8;
                                  __LINE__ = 222;
                                  return j/2;
                                case 8 :
                                  
                                  __LINE__ = 221;
                                  _yieldState = 10;
                                  __LINE__ = 221;
                                  break;
                                case 9 :
                                  
                                  __LINE__ = 224;
                                  _yieldState = 10;
                                  __LINE__ = 224;
                                  return j;
                                case 10 :
                                  
                                  __LINE__ = 217;
                                  j ++ ;
                                  
                                  __LINE__ = 217;
                                  if (j<10){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 2;
                                    __LINE__ = 217;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = 11;
                                  };
                                case 11 :
                                  
                                  __LINE__ = 216;
                                  i ++ ;
                                  
                                  __LINE__ = 216;
                                  if (i<10){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 1;
                                    __LINE__ = 216;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 215;
                                  if (_isYieldSafe){
                                    __LINE__ = 215;
                                    return undefined;
                                  } else {
                                    __LINE__ = 215;
                                    Runtime.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch(e){
                            Runtime.exceptionHandler(__LINE__, __FILE__, e);
                          }
                        };
                    __LINE__ = 215;
                    return Runtime.createGenerator(_mochaGenerator,
                    function () {
                      try {
                        __LINE__ = 215;
                        _yieldState = -1;
                      } catch(e){
                        Runtime.exceptionHandler(__LINE__, __FILE__, e);
                      }
                    },this);
                  } catch(e){
                    Runtime.exceptionHandler(__LINE__, __FILE__, e);
                  }
                }
                __LINE__ = 231;
                generator = yieldTest9();
                
                __LINE__ = 232;
                Runtime.assert(true,generator.next() === 0,"generator.next() === 0",232,'./yield_test.js');
                
                __LINE__ = 233;
                Runtime.assert(true,generator.send(true) === 0,"generator.send(true) === 0",233,'./yield_test.js');
                
                __LINE__ = 234;
                Runtime.assert(true,generator.send(false) === 0,"generator.send(false) === 0",234,'./yield_test.js');
                
                __LINE__ = 235;
                Runtime.assert(true,generator.send(true) === 2,"generator.send(true) === 2",235,'./yield_test.js');
                
                __LINE__ = 236;
                Runtime.assert(true,generator.send(false) === 0,"generator.send(false) === 0",236,'./yield_test.js');
                
                __LINE__ = 237;
                Runtime.assert(true,generator.send(true) === 4,"generator.send(true) === 4",237,'./yield_test.js');
                
                __LINE__ = 238;
                Runtime.assert(true,generator.send(true) === 0,"generator.send(true) === 0",238,'./yield_test.js');
                
                __LINE__ = 239;
                Runtime.assert(true,generator.send(true) === 6,"generator.send(true) === 6",239,'./yield_test.js');
                
                __LINE__ = 240;
                Runtime.assert(true,generator.send(false) === 0,"generator.send(false) === 0",240,'./yield_test.js');
                
                __LINE__ = 241;
                Runtime.assert(true,generator.send(true) === 8,"generator.send(true) === 8",241,'./yield_test.js');
                
                __LINE__ = 242;
                Runtime.assert(true,generator.send(true) === 0,"generator.send(true) === 0",242,'./yield_test.js');
                
                __LINE__ = 243;
                Runtime.assert(true,generator.send(false) === 2.5,"generator.send(false) === 2.5",243,'./yield_test.js');
                
                __LINE__ = 244;
                Runtime.assert(true,generator.send(true) === 0,"generator.send(true) === 0",244,'./yield_test.js');
                
                __LINE__ = 245;
                Runtime.assert(true,generator.send(false) === 3,"generator.send(false) === 3",245,'./yield_test.js');
                
                __LINE__ = 246;
                Runtime.assert(true,generator.send(true) === 0,"generator.send(true) === 0",246,'./yield_test.js');
                
                __LINE__ = 247;
                Runtime.assert(true,generator.send(true) === 14,"generator.send(true) === 14",247,'./yield_test.js');
                
                __LINE__ = 248;
                Runtime.assert(true,generator.send(true) === 0,"generator.send(true) === 0",248,'./yield_test.js');
                
                __LINE__ = 249;
                Runtime.assert(true,generator.send(false) === 4,"generator.send(false) === 4",249,'./yield_test.js');
                
                __LINE__ = 250;
                Runtime.assert(true,generator.send(true) === 0,"generator.send(true) === 0",250,'./yield_test.js');
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            },
            case9 : function () {
              try {
                function yieldTest10() {
                  try {
                    __LINE__ = 254;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 254;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 254;
                    var _yieldState = 0;
                    
                    __LINE__ = 254;
                    var _mochaFinallyCache;
                    
                    __LINE__ = 254;
                    var _mochaCatchCache;
                    
                    __LINE__ = 256;
                    var i;
                    
                    __LINE__ = 258;
                    var m;
                    
                    __LINE__ = 255;
                    var flg;
                    
                    __LINE__ = 254;
                    var _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                          try {
                            __LINE__ = 254;
                            if (!_isYieldSend){
                              
                              __LINE__ = 254;
                              _mochaIsNewBorn = false;
                            } else if (_isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined){
                              
                              __LINE__ = 254;
                              Runtime.exceptionHandler('attempt to send to newborn generator.');
                            };
                            
                            __LINE__ = 254;
                            while (1){
                              try {
                                __LINE__ = 254;
                                switch (_yieldState) {
                                  case 0 :
                                    
                                    __LINE__ = 255;
                                    flg = false;
                                    
                                    __LINE__ = 256;
                                    i = 0;
                                    
                                    __LINE__ = 256;
                                    if (!(i<10)){
                                      
                                      __LINE__ = 256;
                                      _yieldState = -1;
                                      __LINE__ = 256;
                                      break;
                                    };
                                  case 1 :
                                    
                                    __LINE__ = 259;
                                    _yieldState = 2;
                                    
                                    __LINE__ = 257;
                                    _mochaCatchCache = function (e) {
                                      try {
                                        __LINE__ = 257;
                                        _yieldState = 3;
                                      } catch(e){
                                        Runtime.exceptionHandler(__LINE__, __FILE__, e);
                                      }
                                    };
                                    
                                    __LINE__ = 257;
                                    _mochaFinallyCache = function () {
                                      try {
                                        flg = true
                                      } catch(e){
                                        Runtime.exceptionHandler(__LINE__, __FILE__, e);
                                      }
                                    };
                                    
                                    __LINE__ = 258;
                                    m = (flg)?1 : 0;
                                    __LINE__ = 259;
                                    return m;
                                  case 2 :
                                    
                                    __LINE__ = 260;
                                    ddddd();
                                    
                                    __LINE__ = 254;
                                    _mochaCatchCache = undefined;
                                    
                                    __LINE__ = 254;
                                    _mochaFinallyCache = undefined;
                                  case 3 :
                                    
                                    __LINE__ = 256;
                                    i ++ ;
                                    
                                    __LINE__ = 256;
                                    if (i<10){
                                      
                                      __LINE__ = 0;
                                      _yieldState = 1;
                                      __LINE__ = 256;
                                      break;
                                    } else {
                                      
                                      __LINE__ = 0;
                                      _yieldState = -1;
                                    };
                                  case -1 :
                                    
                                    __LINE__ = 254;
                                    if (_isYieldSafe){
                                      __LINE__ = 254;
                                      return undefined;
                                    } else {
                                      __LINE__ = 254;
                                      Runtime.throwStopIteration();
                                    };
                                    
                                };
                              } catch(_mochaException){
                                __LINE__ = 254;
                                if (_mochaCatchCache){
                                  
                                  __LINE__ = 254;
                                  var _mochaLocalTmp0 = _mochaCatchCache(_mochaException);
                                  
                                  __LINE__ = 254;
                                  if (_mochaLocalTmp0 !== undefined){
                                    __LINE__ = 254;
                                    return _mochaLocalTmp0;
                                  };
                                } else {
                                  __LINE__ = 254;
                                  Runtime.throwException(_mochaException);
                                };
                              } finally {
                                __LINE__ = 254;
                                if (_mochaFinallyCache){
                                  
                                  __LINE__ = 254;
                                  var _mochaLocalTmp1 = _mochaFinallyCache();
                                  
                                  __LINE__ = 254;
                                  if (_mochaLocalTmp1 !== undefined){
                                    __LINE__ = 254;
                                    return _mochaLocalTmp1;
                                  };
                                };
                              };
                            };
                          } catch(e){
                            Runtime.exceptionHandler(__LINE__, __FILE__, e);
                          }
                        };
                    __LINE__ = 254;
                    return Runtime.createGenerator(_mochaGenerator,
                    function () {
                      try {
                        __LINE__ = 254;
                        _yieldState = -1;
                        
                        __LINE__ = 254;
                        if (_mochaFinallyCache){
                          __LINE__ = 254;
                          _mochaFinallyCache();
                        };
                      } catch(e){
                        Runtime.exceptionHandler(__LINE__, __FILE__, e);
                      }
                    },this);
                  } catch(e){
                    Runtime.exceptionHandler(__LINE__, __FILE__, e);
                  }
                }
                __LINE__ = 267;
                generator = yieldTest10();
                
                __LINE__ = 268;
                Runtime.assert(true,generator.next() === 0,"generator.next() === 0",268,'./yield_test.js');
                
                __LINE__ = 269;
                Runtime.assert(true,generator.next() === 1,"generator.next() === 1",269,'./yield_test.js');
                
                __LINE__ = 270;
                Runtime.assert(true,generator.next() === 1,"generator.next() === 1",270,'./yield_test.js');
                
                __LINE__ = 271;
                Runtime.assert(true,generator.next() === 1,"generator.next() === 1",271,'./yield_test.js');
                
                __LINE__ = 272;
                Runtime.assert(true,generator.next() === 1,"generator.next() === 1",272,'./yield_test.js');
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            },
            case10 : function () {
              try {
                function yieldTest11() {
                  try {
                    __LINE__ = 275;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 275;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 275;
                    var _yieldState = 0;
                    
                    __LINE__ = 276;
                    var i;
                    
                    __LINE__ = 277;
                    var type;
                    
                    __LINE__ = 275;
                    var _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                          try {
                            __LINE__ = 275;
                            if (!_isYieldSend){
                              
                              __LINE__ = 275;
                              _mochaIsNewBorn = false;
                            } else if (_isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined){
                              
                              __LINE__ = 275;
                              Runtime.exceptionHandler('attempt to send to newborn generator.');
                            };
                            
                            __LINE__ = 275;
                            while (1){
                              __LINE__ = 275;
                              switch (_yieldState) {
                                case 0 :
                                  
                                  __LINE__ = 276;
                                  i = 0;
                                  
                                  __LINE__ = 276;
                                  if (!(i<10)){
                                    
                                    __LINE__ = 276;
                                    _yieldState = -1;
                                    __LINE__ = 276;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 277;
                                  _yieldState = 2;
                                  __LINE__ = 277;
                                  return ;
                                case 2 :
                                  
                                  __LINE__ = 277;
                                  _yieldResult = _isYieldSend && arguments.length>2?Runtime.toArray(arguments,2)[0] : undefined;
                                  
                                  __LINE__ = 277;
                                  type = _yieldResult;
                                  
                                  __LINE__ = 278;
                                  switch (type) {
                                    case 0 :
                                      
                                      __LINE__ = 278;
                                      _yieldState = 3;
                                      __LINE__ = 279;
                                      break;
                                    case 2 :
                                      
                                      __LINE__ = 278;
                                      _yieldState = 4;
                                      __LINE__ = 281;
                                      break;
                                    case 3 :
                                      
                                      __LINE__ = 278;
                                      _yieldState = 5;
                                      __LINE__ = 283;
                                      break;
                                    default :
                                      
                                      __LINE__ = 278;
                                      _yieldState = 6;
                                      __LINE__ = 285;
                                      break;
                                      
                                  };
                                  __LINE__ = 278;
                                  break;
                                case 3 :
                                  
                                  __LINE__ = 278;
                                  _yieldState = 7;
                                  __LINE__ = 280;
                                  return 200;
                                case 4 :
                                  
                                  __LINE__ = 278;
                                  _yieldState = 7;
                                  __LINE__ = 282;
                                  return 400;
                                case 5 :
                                  
                                  __LINE__ = 278;
                                  _yieldState = 7;
                                  __LINE__ = 284;
                                  return 600;
                                case 6 :
                                  
                                  __LINE__ = 278;
                                  _yieldState = 7;
                                  __LINE__ = 286;
                                  return 700;
                                case 7 :
                                  
                                  __LINE__ = 276;
                                  i ++ ;
                                  
                                  __LINE__ = 276;
                                  if (i<10){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 1;
                                    __LINE__ = 276;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 275;
                                  if (_isYieldSafe){
                                    __LINE__ = 275;
                                    return undefined;
                                  } else {
                                    __LINE__ = 275;
                                    Runtime.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch(e){
                            Runtime.exceptionHandler(__LINE__, __FILE__, e);
                          }
                        };
                    __LINE__ = 275;
                    return Runtime.createGenerator(_mochaGenerator,
                    function () {
                      try {
                        __LINE__ = 275;
                        _yieldState = -1;
                      } catch(e){
                        Runtime.exceptionHandler(__LINE__, __FILE__, e);
                      }
                    },this);
                  } catch(e){
                    Runtime.exceptionHandler(__LINE__, __FILE__, e);
                  }
                }
                __LINE__ = 290;
                generator = yieldTest11();
                
                __LINE__ = 291;
                generator.next();
                
                __LINE__ = 292;
                Runtime.assert(true,generator.send(0) === 200,"generator.send(0) === 200",292,'./yield_test.js');
                
                __LINE__ = 293;
                generator.next();
                
                __LINE__ = 294;
                Runtime.assert(true,generator.send(2) === 400,"generator.send(2) === 400",294,'./yield_test.js');
                
                __LINE__ = 295;
                generator.next();
                
                __LINE__ = 296;
                Runtime.assert(true,generator.send(3) === 600,"generator.send(3) === 600",296,'./yield_test.js');
                
                __LINE__ = 297;
                generator.next();
                
                __LINE__ = 298;
                Runtime.assert(true,generator.send(null) === 700,"generator.send(null) === 700",298,'./yield_test.js');
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            },
            case11 : function () {
              try {
                function yieldTest12() {
                  try {
                    __LINE__ = 302;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 302;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 302;
                    var _yieldState = 0;
                    
                    __LINE__ = 303;
                    var i;
                    
                    __LINE__ = 304;
                    var type;
                    
                    __LINE__ = 302;
                    var _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                          try {
                            __LINE__ = 302;
                            if (!_isYieldSend){
                              
                              __LINE__ = 302;
                              _mochaIsNewBorn = false;
                            } else if (_isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined){
                              
                              __LINE__ = 302;
                              Runtime.exceptionHandler('attempt to send to newborn generator.');
                            };
                            
                            __LINE__ = 302;
                            while (1){
                              __LINE__ = 302;
                              switch (_yieldState) {
                                case 0 :
                                  
                                  __LINE__ = 303;
                                  i = 0;
                                  
                                  __LINE__ = 303;
                                  if (!(i<15)){
                                    
                                    __LINE__ = 303;
                                    _yieldState = -1;
                                    __LINE__ = 303;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 304;
                                  _yieldState = 2;
                                  __LINE__ = 304;
                                  return ;
                                case 2 :
                                  
                                  __LINE__ = 304;
                                  _yieldResult = _isYieldSend && arguments.length>2?Runtime.toArray(arguments,2)[0] : undefined;
                                  
                                  __LINE__ = 304;
                                  type = _yieldResult;
                                  
                                  __LINE__ = 305;
                                  switch (type) {
                                    case 4 :
                                    case 0 :
                                      
                                      __LINE__ = 305;
                                      _yieldState = 3;
                                      __LINE__ = 307;
                                      break;
                                    case 5 :
                                      
                                      __LINE__ = 305;
                                      _yieldState = 7;
                                      __LINE__ = 309;
                                      break;
                                    case 6 :
                                    case 2 :
                                      
                                      __LINE__ = 305;
                                      _yieldState = 4;
                                      __LINE__ = 312;
                                      break;
                                    case 3 :
                                      
                                      __LINE__ = 305;
                                      _yieldState = 5;
                                      __LINE__ = 314;
                                      break;
                                    default :
                                      
                                      __LINE__ = 305;
                                      _yieldState = 6;
                                      __LINE__ = 316;
                                      break;
                                      
                                  };
                                  __LINE__ = 305;
                                  break;
                                case 3 :
                                  
                                  __LINE__ = 305;
                                  _yieldState = 8;
                                  __LINE__ = 308;
                                  return 200;
                                case 4 :
                                  
                                  __LINE__ = 305;
                                  _yieldState = 8;
                                  __LINE__ = 313;
                                  return 400;
                                case 5 :
                                  
                                  __LINE__ = 305;
                                  _yieldState = 8;
                                  __LINE__ = 315;
                                  return 600;
                                case 6 :
                                  
                                  __LINE__ = 305;
                                  _yieldState = 8;
                                  __LINE__ = 317;
                                  return 700;
                                case 7 :
                                  
                                  __LINE__ = 305;
                                  _yieldState = 8;
                                  __LINE__ = 309;
                                  break;
                                case 8 :
                                  
                                  __LINE__ = 303;
                                  i ++ ;
                                  
                                  __LINE__ = 303;
                                  if (i<15){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 1;
                                    __LINE__ = 303;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 302;
                                  if (_isYieldSafe){
                                    __LINE__ = 302;
                                    return undefined;
                                  } else {
                                    __LINE__ = 302;
                                    Runtime.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch(e){
                            Runtime.exceptionHandler(__LINE__, __FILE__, e);
                          }
                        };
                    __LINE__ = 302;
                    return Runtime.createGenerator(_mochaGenerator,
                    function () {
                      try {
                        __LINE__ = 302;
                        _yieldState = -1;
                      } catch(e){
                        Runtime.exceptionHandler(__LINE__, __FILE__, e);
                      }
                    },this);
                  } catch(e){
                    Runtime.exceptionHandler(__LINE__, __FILE__, e);
                  }
                }
                __LINE__ = 321;
                generator = yieldTest12();
                
                __LINE__ = 322;
                generator.next();
                
                __LINE__ = 323;
                Runtime.assert(true,generator.send(0) === 200,"generator.send(0) === 200",323,'./yield_test.js');
                
                __LINE__ = 324;
                generator.next();
                
                __LINE__ = 325;
                Runtime.assert(true,generator.send(4) === 200,"generator.send(4) === 200",325,'./yield_test.js');
                
                __LINE__ = 326;
                generator.next();
                
                __LINE__ = 327;
                Runtime.assert(true,generator.send(2) === 400,"generator.send(2) === 400",327,'./yield_test.js');
                
                __LINE__ = 328;
                generator.next();
                
                __LINE__ = 329;
                Runtime.assert(true,generator.send(5) === undefined,"generator.send(5) === undefined",329,'./yield_test.js');
                
                __LINE__ = 330;
                Runtime.assert(true,generator.send(3) === 600,"generator.send(3) === 600",330,'./yield_test.js');
                
                __LINE__ = 331;
                generator.next();
                
                __LINE__ = 332;
                Runtime.assert(true,generator.send(null) === 700,"generator.send(null) === 700",332,'./yield_test.js');
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            },
            case12 : function () {
              try {
                function yieldTest13() {
                  try {
                    __LINE__ = 336;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 336;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 336;
                    var _yieldState = 0;
                    
                    __LINE__ = 338;
                    var length;
                    
                    __LINE__ = 338;
                    var _mochaLocalTmp4;
                    
                    __LINE__ = 338;
                    var i;
                    
                    __LINE__ = 337;
                    var obj;
                    
                    __LINE__ = 338;
                    var _mochaLocalTmp3 = [];
                    
                    __LINE__ = 336;
                    var _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                          try {
                            __LINE__ = 336;
                            if (!_isYieldSend){
                              
                              __LINE__ = 336;
                              _mochaIsNewBorn = false;
                            } else if (_isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined){
                              
                              __LINE__ = 336;
                              Runtime.exceptionHandler('attempt to send to newborn generator.');
                            };
                            
                            __LINE__ = 336;
                            while (1){
                              __LINE__ = 336;
                              switch (_yieldState) {
                                case 0 :
                                  
                                  __LINE__ = 337;
                                  obj =  {
                                    x : 200,
                                    y : 300,
                                    z : 400
                                  };
                                  
                                  __LINE__ = 338;
                                  for (var _mochaLocalTmp2 in obj){
                                    
                                    __LINE__ = 338;
                                    _mochaLocalTmp3.push(_mochaLocalTmp2);
                                  };
                                  
                                  __LINE__ = 338;
                                  _mochaLocalTmp4 = 0;
                                  
                                  __LINE__ = 338;
                                  length = _mochaLocalTmp3.length;
                                  
                                  __LINE__ = 338;
                                  if (!(_mochaLocalTmp4<length)){
                                    
                                    __LINE__ = 338;
                                    _yieldState = -1;
                                    __LINE__ = 338;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 339;
                                  _yieldState = 2;
                                  
                                  __LINE__ = 338;
                                  i = _mochaLocalTmp3[_mochaLocalTmp4];
                                  __LINE__ = 339;
                                  return [i,obj[i]];
                                case 2 :
                                  
                                  __LINE__ = 338;
                                   ++ _mochaLocalTmp4;
                                  
                                  __LINE__ = 338;
                                  if (_mochaLocalTmp4<length){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 1;
                                    __LINE__ = 338;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 336;
                                  if (_isYieldSafe){
                                    __LINE__ = 336;
                                    return undefined;
                                  } else {
                                    __LINE__ = 336;
                                    Runtime.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch(e){
                            Runtime.exceptionHandler(__LINE__, __FILE__, e);
                          }
                        };
                    __LINE__ = 336;
                    return Runtime.createGenerator(_mochaGenerator,
                    function () {
                      try {
                        __LINE__ = 336;
                        _yieldState = -1;
                      } catch(e){
                        Runtime.exceptionHandler(__LINE__, __FILE__, e);
                      }
                    },this);
                  } catch(e){
                    Runtime.exceptionHandler(__LINE__, __FILE__, e);
                  }
                }
                __LINE__ = 343;
                generator = yieldTest13();
                
                __LINE__ = 344;
                var ret = generator.next();
                
                __LINE__ = 345;
                Runtime.assert(true,ret[0] === "x","ret[0] === \"x\"",345,'./yield_test.js');
                
                __LINE__ = 346;
                Runtime.assert(true,ret[1] === 200,"ret[1] === 200",346,'./yield_test.js');
                
                __LINE__ = 347;
                ret = generator.next();
                
                __LINE__ = 348;
                Runtime.assert(true,ret[0] === "y","ret[0] === \"y\"",348,'./yield_test.js');
                
                __LINE__ = 349;
                Runtime.assert(true,ret[1] === 300,"ret[1] === 300",349,'./yield_test.js');
                
                __LINE__ = 350;
                ret = generator.next();
                
                __LINE__ = 351;
                Runtime.assert(true,ret[0] === "z","ret[0] === \"z\"",351,'./yield_test.js');
                
                __LINE__ = 352;
                Runtime.assert(true,ret[1] === 400,"ret[1] === 400",352,'./yield_test.js');
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            },
            case13 : function () {
              try {
                function keys(obj) {
                  try {
                    __LINE__ = 355;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 355;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 355;
                    var _yieldState = 0;
                    
                    __LINE__ = 356;
                    var length;
                    
                    __LINE__ = 356;
                    var _mochaLocalTmp7;
                    
                    __LINE__ = 356;
                    var prop;
                    
                    __LINE__ = 356;
                    var _mochaLocalTmp6 = [];
                    
                    __LINE__ = 355;
                    var _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                          try {
                            __LINE__ = 355;
                            if (!_isYieldSend){
                              
                              __LINE__ = 355;
                              _mochaIsNewBorn = false;
                            } else if (_isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined){
                              
                              __LINE__ = 355;
                              Runtime.exceptionHandler('attempt to send to newborn generator.');
                            };
                            
                            __LINE__ = 355;
                            while (1){
                              __LINE__ = 355;
                              switch (_yieldState) {
                                case 0 :
                                  
                                  __LINE__ = 356;
                                  for (var _mochaLocalTmp5 in obj){
                                    
                                    __LINE__ = 356;
                                    _mochaLocalTmp6.push(_mochaLocalTmp5);
                                  };
                                  
                                  __LINE__ = 356;
                                  _mochaLocalTmp7 = 0;
                                  
                                  __LINE__ = 356;
                                  length = _mochaLocalTmp6.length;
                                  
                                  __LINE__ = 356;
                                  if (!(_mochaLocalTmp7<length)){
                                    
                                    __LINE__ = 356;
                                    _yieldState = -1;
                                    __LINE__ = 356;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 356;
                                  prop = _mochaLocalTmp6[_mochaLocalTmp7];
                                  
                                  __LINE__ = 357;
                                  if (obj.hasOwnProperty(prop)){
                                    
                                    __LINE__ = 357;
                                    _yieldState = 2;
                                    __LINE__ = 357;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 357;
                                    _yieldState = 3;
                                    __LINE__ = 357;
                                    break;
                                  };
                                case 2 :
                                  
                                  __LINE__ = 358;
                                  _yieldState = 3;
                                  __LINE__ = 358;
                                  return prop;
                                case 3 :
                                  
                                  __LINE__ = 357;
                                  _yieldState = 4;
                                  __LINE__ = 357;
                                  break;
                                case 4 :
                                  
                                  __LINE__ = 356;
                                   ++ _mochaLocalTmp7;
                                  
                                  __LINE__ = 356;
                                  if (_mochaLocalTmp7<length){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 1;
                                    __LINE__ = 356;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 355;
                                  if (_isYieldSafe){
                                    __LINE__ = 355;
                                    return undefined;
                                  } else {
                                    __LINE__ = 355;
                                    Runtime.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch(e){
                            Runtime.exceptionHandler(__LINE__, __FILE__, e);
                          }
                        };
                    __LINE__ = 355;
                    return Runtime.createGenerator(_mochaGenerator,
                    function () {
                      try {
                        __LINE__ = 355;
                        _yieldState = -1;
                      } catch(e){
                        Runtime.exceptionHandler(__LINE__, __FILE__, e);
                      }
                    },this);
                  } catch(e){
                    Runtime.exceptionHandler(__LINE__, __FILE__, e);
                  }
                }
                __LINE__ = 363;
                var testObject =  {
                      value1 : 1,
                      value2 : 2,
                      value3 : 3,
                      value4 : 4
                    };
                
                try {
                  
                  __LINE__ = 370;
                  var itemGen = keys(testObject);
                  __LINE__ = 371;
                  Runtime.assert(true,itemGen.next() == "value1","itemGen.next() == \"value1\"",371,'./yield_test.js');
                  __LINE__ = 372;
                  Runtime.assert(true,itemGen.next() == "value2","itemGen.next() == \"value2\"",372,'./yield_test.js');
                  __LINE__ = 373;
                  Runtime.assert(true,itemGen.next() == "value3","itemGen.next() == \"value3\"",373,'./yield_test.js');
                  __LINE__ = 374;
                  Runtime.assert(true,itemGen.next() == "value4","itemGen.next() == \"value4\"",374,'./yield_test.js');
                } catch(e){
                  
                };
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            }
          };
      
      __LINE__ = 383;
      for (var i = 1;i<13;i ++ ){
        
        __LINE__ = 384;
        tests["case"+i]();
      };
    } catch(e){
      Runtime.exceptionHandler(__LINE__, __FILE__, e);
    }
  }();
}();
