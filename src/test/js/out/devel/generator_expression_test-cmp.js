!function() {
  var __FILE__ = "Runtime",
      __LINE__ = 0;
  
  var _mochaGlobalExport = {},
      global = (this !== null)?this : typeof window === 'object'?window : {};
  
  !function () {
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
        
        Runtime.assert(true,typeof type === "string","typeof type === \"string\"",45,'runtime.js');
        
        typeof callback !== "function" && builtinTypeError(type+" : first argument is not callable");
      }
      function builtinTypeError(message) {
        try {
          throw new TypeError(message);
        } catch(e){
          throw new Error(e);
        }
        
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
        }
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
            }
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
      }
      
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
              return this !== null && this !== global && this instanceof ret?ret.context.apply(this,args) : ret.context.apply(context,args);
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
          }
          
        }
        
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
            }
            
          }
          
        } else {
          while ((ta = this[ ++ iter]) !== null && ta !== undefined){
            if (!(callback(ta,iter,this))){
              return false;
            }
            
          }
          
        }
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
            }
            
          }
          
        } else {
          while ((ta = this[ ++ iter]) !== null && ta !== undefined){
            if (callback(ta,iter,this)){
              return true;
            }
            
          }
          
        }
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
          }
          
        }
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
          }
          
        }
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
          }
          
        }
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
          }
          
        }
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
        }
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
        }
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
        }
        return (arr)?({}).toString.call(arr) === "[object Array]" : false;
      });
    }.call(this,String,Array,Function,Date);
  }.call(this);
  
  var Runtime = function () {
        function checkRequirements(_mochaLocalTmp9,_mochaLocalTmp10,traits,file,line) {
          var proto1 = _mochaLocalTmp9.prototype,
              proto2 = _mochaLocalTmp10.prototype;
          
          for (var i = 0,len = traits.length;i<len;i ++ ){
            
            var _mochaLocalTmp11 = traits[i],
                _mochaRequires = _mochaLocalTmp11._mochaRequires;
            
            for (var prop in _mochaRequires){
              !(prop in proto1) && !(prop in proto2) && Runtime.throwException("Class dose not meet the traits requirement. traits require implementation of property "+prop+"\nin file "+file+" at line "+line);
            }
            
          }
          
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
              }
              
            }
            
            for (i in traitPrivate){
              if (!without[i]){
                
                tmp = (!with_[i])?i : with_[i];
                
                privateProto[tmp] = traitPrivate[i];
              }
              
            }
            
          }
          
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
              }
              
            }
            
            for (i in sourceTraitPublic){
              if (!without[i]){
                
                tmp = (!with_[i])?i : with_[i];
                
                destTraitPublic[tmp] = sourceTraitPublic[i];
              }
              
            }
            
            for (i in sourceRequires){
              destRequires[i] = sourceRequires[i];
            }
            
          }
          
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
          }
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
          }
          
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
          }
          
          !("__nothrowNext__" in ret) && createUnenumProp(newObj,"__nothrowNext__",ret.next.bind(ret));
          
          for (var prop in ret){
            
            prop !== "next" && prop !== "__nothrowNext__" && (newObj[prop] = ret[prop]);
          }
          
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
          }
          
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
            
          }
          return maxIndex === i;
        }
        function extend(dest,source) {
          for (var prop in source){
            
            dest[prop] = source[prop];
          }
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
                }
                
              },
              throwException : function (exception) {
                try {
                  throw exception;
                } catch(e){
                  
                  if (isStopIteration(e)){
                    throw new Error(e);
                  } else {
                    throw new Error(this.getErrorMessage(e));
                  }
                  
                }
                
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
              }
              return ret;
            },
            extendClass = _mochaLocalExport.extendClass = (Runtime.hasProto)?function (derived,base) {
              if (typeof base === 'function'){
                
                derived.prototype.__proto__ = base.prototype;
                
                for (var i in base){
                  derived[i] = base[i];
                }
                
              } else {
                derived.prototype.__proto__ = base.__proto__;
              }
              
            } : function (derived,base) {
              var baseType = typeof base;
              
              if (baseType === "function"){
                
                var inherit = function (){};
                
                inherit.prototype = base.prototype;
                
                derived.prototype = new inherit;
                
                for (var i in base){
                  derived[i] = base[i];
                }
                
              } else {
                
                var inherit = function (){},
                    proto = getPrototype(base);
                
                inherit.prototype = proto;
                
                derived.prototype = new inherit;
              }
              
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
        
        if ("WeakMap" in global){
          
          privateRecord = new WeakMap();
          
          createPrivateRecord = function (self,privateHolder) {
            var holder = new privateHolder;
            
            createUnenumProp(holder,"__is_private__",1);
            
            privateRecord.set(self,holder);
          };
          
          getPrivateRecord = function (self) {
            if (privateRecord.has(self)){
              return privateRecord.get(self);
            } else if (self.__is_private__ === 1){
              return self;
            }
            
          };
        } else {
          
          createPrivateRecord = function (self,privateHolder) {
            if (!self.__typeid__){
              
              var holder = new privateHolder;
              
              createUnenumProp(holder,"__is_private__",1);
              
              createUnenumProp(self,"__private__",holder);
            }
            
          };
          
          getPrivateRecord = function (self) {
            if (self.__private__){
              return self.__private__;
            } else if (self.__is_private__ === 1){
              return self;
            }
            
          };
        }
        
        _mochaLocalExport.getPrivateRecord = getPrivateRecord;
        
        _mochaLocalExport.initializeClass = initializeClass;
        
        _mochaLocalExport.getSuper = getSuper;
        
        _mochaLocalExport.traitMixin = traitMixin;
        
        _mochaLocalExport.classMixin = classMixin;
        
        _mochaLocalExport.checkRequirements = checkRequirements;
        
        !function () {
          var assert = _mochaLocalExport.assert = (console && console.assert)?function (expect,exp,str,line,filename) {
                return console.assert(expect === exp,"assertion failed : "+str+"\nexpect "+expect+" but got "+exp+"\nin file "+filename+" at : "+line);
              } : function (expect,exp,str,line,filename) {
                expect !== exp && Runtime.throwException("assertion failed : "+str+"\nexpect "+expect+" but got "+exp+"\nin file "+filename+" at : "+line);
              };
        }.call(this);
        return _mochaLocalExport;
      }();
  
  !("StopIteration" in global) && (global.StopIteration =  {
    toString : function () {
      return "[object StopIteration]";
    }
  });
  
  function Tuple() {
    var args = Runtime.toArray(arguments,0),
        ret = {};
    
    ret.length = 0;
    
    [].push.apply(ret,args);
    
    Runtime.createTuple(ret,arguments.length);
    return ret;
  }
  function Record(member) {
    return Runtime.createRecord(member);
  }
  __LINE__ = 2;
  !function () {
    try {
      var __FILE__ = "iterators",
          __LINE__ = 0;
      __LINE__ = 2;
      _mochaGlobalExport.iterators = {};
      
      __LINE__ = 2;
      var _mochaGlobalAlias = _mochaGlobalExport.iterators;
      
      __LINE__ = 0;
      !function () {
        try {
          function allItems(obj) {
            try {
              __LINE__ = 54;
              var _mochaLocalTmp23 = {};
              
              __LINE__ = 54;
              Runtime.createUnenumProp(_mochaLocalTmp23,iterator,
              function () {
                try {
                  __LINE__ = 54;
                  return function () {
                    try {
                      __LINE__ = 54;
                      var _mochaIsNewBorn = true,
                          _yieldResult = undefined,
                          _yieldState = 0,
                          length,
                          _mochaLocalTmp22,
                          x,
                          _mochaLocalTmp21 = [],
                          _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                            try {
                              __LINE__ = 54;
                              !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler('attempt to send to newborn generator.');
                              
                              __LINE__ = 54;
                              while (1){
                                
                                __LINE__ = 54;
                                switch (_yieldState) {
                                  case 0 :
                                    
                                    __LINE__ = 54;
                                    for (var _mochaLocalTmp20 in obj){
                                      
                                      __LINE__ = 54;
                                      _mochaLocalTmp21.push(_mochaLocalTmp20);
                                    }
                                    
                                    __LINE__ = 54;
                                    _mochaLocalTmp22 = 0;
                                    
                                    __LINE__ = 54;
                                    length = _mochaLocalTmp21.length;
                                    
                                    __LINE__ = 54;
                                    if (!(_mochaLocalTmp22<length)){
                                      
                                      __LINE__ = 54;
                                      _yieldState = -1;
                                      __LINE__ = 54;
                                      break;
                                    }
                                  case 1 :
                                    
                                    __LINE__ = 56;
                                    _yieldState = 2;
                                    
                                    __LINE__ = 54;
                                    x = _mochaLocalTmp21[_mochaLocalTmp22];
                                    __LINE__ = 56;
                                    return [x,obj[x]];
                                  case 2 :
                                    
                                    __LINE__ = 54;
                                     ++ _mochaLocalTmp22;
                                    
                                    __LINE__ = 54;
                                    if (_mochaLocalTmp22<length){
                                      
                                      __LINE__ = 2;
                                      _yieldState = 1;
                                      __LINE__ = 54;
                                      break;
                                    } else {
                                      __LINE__ = 2;
                                      _yieldState = -1;
                                    }
                                  case -1 :
                                    
                                    __LINE__ = 54;
                                    if (_isYieldSafe){
                                      __LINE__ = 54;
                                      return undefined;
                                    }
                                    
                                    __LINE__ = 54;
                                    Runtime.throwStopIteration();
                                    
                                }
                                
                              }
                              
                            } catch(e){
                              Runtime.exceptionHandler(__LINE__, __FILE__, e);
                            }
                          };
                      __LINE__ = 54;
                      return Runtime.createGenerator(_mochaGenerator,
                      function () {
                        try {
                          __LINE__ = 54;
                          _yieldState = -1;
                        } catch(e){
                          Runtime.exceptionHandler(__LINE__, __FILE__, e);
                        }
                      },this);
                    } catch(e){
                      Runtime.exceptionHandler(__LINE__, __FILE__, e);
                    }
                  }();
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              });
              __LINE__ = 52;
              return _mochaLocalTmp23;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          }
          function allValues(obj) {
            try {
              __LINE__ = 46;
              var _mochaLocalTmp19 = {};
              
              __LINE__ = 46;
              Runtime.createUnenumProp(_mochaLocalTmp19,iterator,
              function () {
                try {
                  __LINE__ = 46;
                  return function () {
                    try {
                      __LINE__ = 46;
                      var _mochaIsNewBorn = true,
                          _yieldResult = undefined,
                          _yieldState = 0,
                          length,
                          _mochaLocalTmp18,
                          x,
                          _mochaLocalTmp17 = [],
                          _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                            try {
                              __LINE__ = 46;
                              !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler('attempt to send to newborn generator.');
                              
                              __LINE__ = 46;
                              while (1){
                                
                                __LINE__ = 46;
                                switch (_yieldState) {
                                  case 0 :
                                    
                                    __LINE__ = 46;
                                    for (var _mochaLocalTmp16 in obj){
                                      
                                      __LINE__ = 46;
                                      _mochaLocalTmp17.push(_mochaLocalTmp16);
                                    }
                                    
                                    __LINE__ = 46;
                                    _mochaLocalTmp18 = 0;
                                    
                                    __LINE__ = 46;
                                    length = _mochaLocalTmp17.length;
                                    
                                    __LINE__ = 46;
                                    if (!(_mochaLocalTmp18<length)){
                                      
                                      __LINE__ = 46;
                                      _yieldState = -1;
                                      __LINE__ = 46;
                                      break;
                                    }
                                  case 1 :
                                    
                                    __LINE__ = 48;
                                    _yieldState = 2;
                                    
                                    __LINE__ = 46;
                                    x = _mochaLocalTmp17[_mochaLocalTmp18];
                                    __LINE__ = 48;
                                    return obj[x];
                                  case 2 :
                                    
                                    __LINE__ = 46;
                                     ++ _mochaLocalTmp18;
                                    
                                    __LINE__ = 46;
                                    if (_mochaLocalTmp18<length){
                                      
                                      __LINE__ = 2;
                                      _yieldState = 1;
                                      __LINE__ = 46;
                                      break;
                                    } else {
                                      __LINE__ = 2;
                                      _yieldState = -1;
                                    }
                                  case -1 :
                                    
                                    __LINE__ = 46;
                                    if (_isYieldSafe){
                                      __LINE__ = 46;
                                      return undefined;
                                    }
                                    
                                    __LINE__ = 46;
                                    Runtime.throwStopIteration();
                                    
                                }
                                
                              }
                              
                            } catch(e){
                              Runtime.exceptionHandler(__LINE__, __FILE__, e);
                            }
                          };
                      __LINE__ = 46;
                      return Runtime.createGenerator(_mochaGenerator,
                      function () {
                        try {
                          __LINE__ = 46;
                          _yieldState = -1;
                        } catch(e){
                          Runtime.exceptionHandler(__LINE__, __FILE__, e);
                        }
                      },this);
                    } catch(e){
                      Runtime.exceptionHandler(__LINE__, __FILE__, e);
                    }
                  }();
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              });
              __LINE__ = 44;
              return _mochaLocalTmp19;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          }
          function allKeys(obj) {
            try {
              __LINE__ = 38;
              var _mochaLocalTmp15 = {};
              
              __LINE__ = 38;
              Runtime.createUnenumProp(_mochaLocalTmp15,iterator,
              function () {
                try {
                  __LINE__ = 38;
                  return function () {
                    try {
                      __LINE__ = 38;
                      var _mochaIsNewBorn = true,
                          _yieldResult = undefined,
                          _yieldState = 0,
                          length,
                          _mochaLocalTmp14,
                          x,
                          _mochaLocalTmp13 = [],
                          _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                            try {
                              __LINE__ = 38;
                              !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler('attempt to send to newborn generator.');
                              
                              __LINE__ = 38;
                              while (1){
                                
                                __LINE__ = 38;
                                switch (_yieldState) {
                                  case 0 :
                                    
                                    __LINE__ = 38;
                                    for (var _mochaLocalTmp12 in obj){
                                      
                                      __LINE__ = 38;
                                      _mochaLocalTmp13.push(_mochaLocalTmp12);
                                    }
                                    
                                    __LINE__ = 38;
                                    _mochaLocalTmp14 = 0;
                                    
                                    __LINE__ = 38;
                                    length = _mochaLocalTmp13.length;
                                    
                                    __LINE__ = 38;
                                    if (!(_mochaLocalTmp14<length)){
                                      
                                      __LINE__ = 38;
                                      _yieldState = -1;
                                      __LINE__ = 38;
                                      break;
                                    }
                                  case 1 :
                                    
                                    __LINE__ = 40;
                                    _yieldState = 2;
                                    
                                    __LINE__ = 38;
                                    x = _mochaLocalTmp13[_mochaLocalTmp14];
                                    __LINE__ = 40;
                                    return x;
                                  case 2 :
                                    
                                    __LINE__ = 38;
                                     ++ _mochaLocalTmp14;
                                    
                                    __LINE__ = 38;
                                    if (_mochaLocalTmp14<length){
                                      
                                      __LINE__ = 2;
                                      _yieldState = 1;
                                      __LINE__ = 38;
                                      break;
                                    } else {
                                      __LINE__ = 2;
                                      _yieldState = -1;
                                    }
                                  case -1 :
                                    
                                    __LINE__ = 38;
                                    if (_isYieldSafe){
                                      __LINE__ = 38;
                                      return undefined;
                                    }
                                    
                                    __LINE__ = 38;
                                    Runtime.throwStopIteration();
                                    
                                }
                                
                              }
                              
                            } catch(e){
                              Runtime.exceptionHandler(__LINE__, __FILE__, e);
                            }
                          };
                      __LINE__ = 38;
                      return Runtime.createGenerator(_mochaGenerator,
                      function () {
                        try {
                          __LINE__ = 38;
                          _yieldState = -1;
                        } catch(e){
                          Runtime.exceptionHandler(__LINE__, __FILE__, e);
                        }
                      },this);
                    } catch(e){
                      Runtime.exceptionHandler(__LINE__, __FILE__, e);
                    }
                  }();
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              });
              __LINE__ = 36;
              return _mochaLocalTmp15;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          }
          function items(obj) {
            try {
              __LINE__ = 28;
              var _mochaLocalTmp11 = {};
              
              __LINE__ = 28;
              Runtime.createUnenumProp(_mochaLocalTmp11,iterator,
              function () {
                try {
                  __LINE__ = 28;
                  return function () {
                    try {
                      __LINE__ = 28;
                      var _mochaIsNewBorn = true,
                          _yieldResult = undefined,
                          _yieldState = 0,
                          length,
                          _mochaLocalTmp10,
                          x,
                          _mochaLocalTmp9 = [],
                          _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                            try {
                              __LINE__ = 28;
                              !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler('attempt to send to newborn generator.');
                              
                              __LINE__ = 28;
                              while (1){
                                
                                __LINE__ = 28;
                                switch (_yieldState) {
                                  case 0 :
                                    
                                    __LINE__ = 28;
                                    for (var _mochaLocalTmp8 in obj){
                                      
                                      __LINE__ = 28;
                                      _mochaLocalTmp9.push(_mochaLocalTmp8);
                                    }
                                    
                                    __LINE__ = 28;
                                    _mochaLocalTmp10 = 0;
                                    
                                    __LINE__ = 28;
                                    length = _mochaLocalTmp9.length;
                                    
                                    __LINE__ = 28;
                                    if (!(_mochaLocalTmp10<length)){
                                      
                                      __LINE__ = 28;
                                      _yieldState = -1;
                                      __LINE__ = 28;
                                      break;
                                    }
                                  case 1 :
                                    
                                    __LINE__ = 28;
                                    x = _mochaLocalTmp9[_mochaLocalTmp10];
                                    
                                    __LINE__ = 30;
                                    if (hasOwn.call(obj,x)){
                                      
                                      __LINE__ = 30;
                                      _yieldState = 2;
                                      __LINE__ = 30;
                                      break;
                                    } else {
                                      
                                      __LINE__ = 30;
                                      _yieldState = 3;
                                      __LINE__ = 30;
                                      break;
                                    }
                                  case 2 :
                                    
                                    __LINE__ = 30;
                                    _yieldState = 3;
                                    __LINE__ = 30;
                                    return [x,obj[x]];
                                  case 3 :
                                    
                                    __LINE__ = 30;
                                    _yieldState = 4;
                                    __LINE__ = 30;
                                    break;
                                  case 4 :
                                    
                                    __LINE__ = 28;
                                     ++ _mochaLocalTmp10;
                                    
                                    __LINE__ = 28;
                                    if (_mochaLocalTmp10<length){
                                      
                                      __LINE__ = 2;
                                      _yieldState = 1;
                                      __LINE__ = 28;
                                      break;
                                    } else {
                                      __LINE__ = 2;
                                      _yieldState = -1;
                                    }
                                  case -1 :
                                    
                                    __LINE__ = 28;
                                    if (_isYieldSafe){
                                      __LINE__ = 28;
                                      return undefined;
                                    }
                                    
                                    __LINE__ = 28;
                                    Runtime.throwStopIteration();
                                    
                                }
                                
                              }
                              
                            } catch(e){
                              Runtime.exceptionHandler(__LINE__, __FILE__, e);
                            }
                          };
                      __LINE__ = 28;
                      return Runtime.createGenerator(_mochaGenerator,
                      function () {
                        try {
                          __LINE__ = 28;
                          _yieldState = -1;
                        } catch(e){
                          Runtime.exceptionHandler(__LINE__, __FILE__, e);
                        }
                      },this);
                    } catch(e){
                      Runtime.exceptionHandler(__LINE__, __FILE__, e);
                    }
                  }();
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              });
              __LINE__ = 26;
              return _mochaLocalTmp11;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          }
          function values(obj) {
            try {
              __LINE__ = 16;
              var _mochaLocalTmp7 = {};
              
              __LINE__ = 16;
              Runtime.createUnenumProp(_mochaLocalTmp7,iterator,
              function () {
                try {
                  __LINE__ = 16;
                  return function () {
                    try {
                      __LINE__ = 16;
                      var _mochaIsNewBorn = true,
                          _yieldResult = undefined,
                          _yieldState = 0,
                          length,
                          _mochaLocalTmp6,
                          x,
                          _mochaLocalTmp5 = [],
                          _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                            try {
                              __LINE__ = 16;
                              !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler('attempt to send to newborn generator.');
                              
                              __LINE__ = 16;
                              while (1){
                                
                                __LINE__ = 16;
                                switch (_yieldState) {
                                  case 0 :
                                    
                                    __LINE__ = 18;
                                    for (var _mochaLocalTmp4 in obj){
                                      
                                      __LINE__ = 18;
                                      _mochaLocalTmp5.push(_mochaLocalTmp4);
                                    }
                                    
                                    __LINE__ = 18;
                                    _mochaLocalTmp6 = 0;
                                    
                                    __LINE__ = 18;
                                    length = _mochaLocalTmp5.length;
                                    
                                    __LINE__ = 18;
                                    if (!(_mochaLocalTmp6<length)){
                                      
                                      __LINE__ = 18;
                                      _yieldState = -1;
                                      __LINE__ = 18;
                                      break;
                                    }
                                  case 1 :
                                    
                                    __LINE__ = 18;
                                    x = _mochaLocalTmp5[_mochaLocalTmp6];
                                    
                                    __LINE__ = 18;
                                    if (hasOwn.call(obj,x)){
                                      
                                      __LINE__ = 18;
                                      _yieldState = 2;
                                      __LINE__ = 18;
                                      break;
                                    } else {
                                      
                                      __LINE__ = 18;
                                      _yieldState = 3;
                                      __LINE__ = 18;
                                      break;
                                    }
                                  case 2 :
                                    
                                    __LINE__ = 20;
                                    _yieldState = 3;
                                    __LINE__ = 20;
                                    return obj[x];
                                  case 3 :
                                    
                                    __LINE__ = 18;
                                    _yieldState = 4;
                                    __LINE__ = 18;
                                    break;
                                  case 4 :
                                    
                                    __LINE__ = 18;
                                     ++ _mochaLocalTmp6;
                                    
                                    __LINE__ = 18;
                                    if (_mochaLocalTmp6<length){
                                      
                                      __LINE__ = 2;
                                      _yieldState = 1;
                                      __LINE__ = 18;
                                      break;
                                    } else {
                                      __LINE__ = 2;
                                      _yieldState = -1;
                                    }
                                  case -1 :
                                    
                                    __LINE__ = 16;
                                    if (_isYieldSafe){
                                      __LINE__ = 16;
                                      return undefined;
                                    }
                                    
                                    __LINE__ = 16;
                                    Runtime.throwStopIteration();
                                    
                                }
                                
                              }
                              
                            } catch(e){
                              Runtime.exceptionHandler(__LINE__, __FILE__, e);
                            }
                          };
                      __LINE__ = 16;
                      return Runtime.createGenerator(_mochaGenerator,
                      function () {
                        try {
                          __LINE__ = 16;
                          _yieldState = -1;
                        } catch(e){
                          Runtime.exceptionHandler(__LINE__, __FILE__, e);
                        }
                      },this);
                    } catch(e){
                      Runtime.exceptionHandler(__LINE__, __FILE__, e);
                    }
                  }();
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              });
              __LINE__ = 16;
              return _mochaLocalTmp7;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          }
          function keys(obj) {
            try {
              __LINE__ = 6;
              var _mochaLocalTmp3 = {};
              
              __LINE__ = 6;
              Runtime.createUnenumProp(_mochaLocalTmp3,iterator,
              function () {
                try {
                  __LINE__ = 6;
                  return function () {
                    try {
                      __LINE__ = 6;
                      var _mochaIsNewBorn = true,
                          _yieldResult = undefined,
                          _yieldState = 0,
                          length,
                          _mochaLocalTmp2,
                          x,
                          _mochaLocalTmp1 = [],
                          _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                            try {
                              __LINE__ = 6;
                              !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler('attempt to send to newborn generator.');
                              
                              __LINE__ = 6;
                              while (1){
                                
                                __LINE__ = 6;
                                switch (_yieldState) {
                                  case 0 :
                                    
                                    __LINE__ = 6;
                                    for (var _mochaLocalTmp0 in obj){
                                      
                                      __LINE__ = 6;
                                      _mochaLocalTmp1.push(_mochaLocalTmp0);
                                    }
                                    
                                    __LINE__ = 6;
                                    _mochaLocalTmp2 = 0;
                                    
                                    __LINE__ = 6;
                                    length = _mochaLocalTmp1.length;
                                    
                                    __LINE__ = 6;
                                    if (!(_mochaLocalTmp2<length)){
                                      
                                      __LINE__ = 6;
                                      _yieldState = -1;
                                      __LINE__ = 6;
                                      break;
                                    }
                                  case 1 :
                                    
                                    __LINE__ = 6;
                                    x = _mochaLocalTmp1[_mochaLocalTmp2];
                                    
                                    __LINE__ = 8;
                                    if (hasOwn.call(obj,x)){
                                      
                                      __LINE__ = 8;
                                      _yieldState = 2;
                                      __LINE__ = 8;
                                      break;
                                    } else {
                                      
                                      __LINE__ = 8;
                                      _yieldState = 3;
                                      __LINE__ = 8;
                                      break;
                                    }
                                  case 2 :
                                    
                                    __LINE__ = 8;
                                    _yieldState = 3;
                                    __LINE__ = 8;
                                    return x;
                                  case 3 :
                                    
                                    __LINE__ = 8;
                                    _yieldState = 4;
                                    __LINE__ = 8;
                                    break;
                                  case 4 :
                                    
                                    __LINE__ = 6;
                                     ++ _mochaLocalTmp2;
                                    
                                    __LINE__ = 6;
                                    if (_mochaLocalTmp2<length){
                                      
                                      __LINE__ = 2;
                                      _yieldState = 1;
                                      __LINE__ = 6;
                                      break;
                                    } else {
                                      __LINE__ = 2;
                                      _yieldState = -1;
                                    }
                                  case -1 :
                                    
                                    __LINE__ = 6;
                                    if (_isYieldSafe){
                                      __LINE__ = 6;
                                      return undefined;
                                    }
                                    
                                    __LINE__ = 6;
                                    Runtime.throwStopIteration();
                                    
                                }
                                
                              }
                              
                            } catch(e){
                              Runtime.exceptionHandler(__LINE__, __FILE__, e);
                            }
                          };
                      __LINE__ = 6;
                      return Runtime.createGenerator(_mochaGenerator,
                      function () {
                        try {
                          __LINE__ = 6;
                          _yieldState = -1;
                        } catch(e){
                          Runtime.exceptionHandler(__LINE__, __FILE__, e);
                        }
                      },this);
                    } catch(e){
                      Runtime.exceptionHandler(__LINE__, __FILE__, e);
                    }
                  }();
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              });
              __LINE__ = 4;
              return _mochaLocalTmp3;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          }
          __LINE__ = 0;
          var _mochaLocalExport = _mochaGlobalAlias,
              hasOwn = {}.hasOwnProperty,
              iterator = _mochaLocalExport.iterator = "__mocha_iterator_special_key__";
          
          __LINE__ = 4;
          _mochaLocalExport.keys = keys;
          
          __LINE__ = 14;
          _mochaLocalExport.values = values;
          
          __LINE__ = 26;
          _mochaLocalExport.items = items;
          
          __LINE__ = 36;
          _mochaLocalExport.allKeys = allKeys;
          
          __LINE__ = 44;
          _mochaLocalExport.allValues = allValues;
          
          __LINE__ = 52;
          _mochaLocalExport.allItems = allItems;
          __LINE__ = 0;
          return _mochaLocalExport;
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }();
    } catch(e){
      Runtime.exceptionHandler(__LINE__, __FILE__, e);
    }
  }();
  
  __LINE__ = 0;
  !function () {
    try {
      var __FILE__ = "-759650552-generator_expression_test.js",
          __LINE__ = 0;
      __LINE__ = 2;
      _mochaGlobalExport['-759650552-generator_expression_test.js'] = {};
      
      __LINE__ = 3;
      var _mochaGlobalAlias = _mochaGlobalExport['-759650552-generator_expression_test.js'],
          _mochaLocalTmp0 = _mochaGlobalExport.iterators,
          keys = _mochaLocalTmp0.keys,
          allItems = _mochaLocalTmp0.allItems,
          testObject =  {
            value1 : 100,
            value2 : 200,
            value3 : 300
          },
          test = function () {
            try {
              __LINE__ = 4362602312;
              var _mochaIsNewBorn = true,
                  _yieldResult = undefined,
                  _yieldState = 0,
                  length,
                  _mochaLocalTmp3,
                  x,
                  _mochaLocalTmp2 = [],
                  _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                    try {
                      __LINE__ = 4362602312;
                      !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler('attempt to send to newborn generator.');
                      
                      __LINE__ = 4362602312;
                      while (1){
                        
                        __LINE__ = 4362602312;
                        switch (_yieldState) {
                          case 0 :
                            
                            __LINE__ = 8;
                            for (var _mochaLocalTmp1 in testObject){
                              
                              __LINE__ = 8;
                              _mochaLocalTmp2.push(_mochaLocalTmp1);
                            }
                            
                            __LINE__ = 8;
                            _mochaLocalTmp3 = 0;
                            
                            __LINE__ = 8;
                            length = _mochaLocalTmp2.length;
                            
                            __LINE__ = 8;
                            if (!(_mochaLocalTmp3<length)){
                              
                              __LINE__ = 8;
                              _yieldState = -1;
                              __LINE__ = 8;
                              break;
                            }
                          case 1 :
                            
                            __LINE__ = 4362602312;
                            _yieldState = 2;
                            
                            __LINE__ = 8;
                            x = _mochaLocalTmp2[_mochaLocalTmp3];
                            
                            __LINE__ = 8;
                            x = testObject[x];
                            __LINE__ = 4362602312;
                            return x;
                          case 2 :
                            
                            __LINE__ = 8;
                             ++ _mochaLocalTmp3;
                            
                            __LINE__ = 8;
                            if (_mochaLocalTmp3<length){
                              
                              __LINE__ = 0;
                              _yieldState = 1;
                              __LINE__ = 8;
                              break;
                            } else {
                              __LINE__ = 0;
                              _yieldState = -1;
                            }
                          case -1 :
                            
                            __LINE__ = 4362602312;
                            if (_isYieldSafe){
                              __LINE__ = 4362602312;
                              return undefined;
                            }
                            
                            __LINE__ = 4362602312;
                            Runtime.throwStopIteration();
                            
                        }
                        
                      }
                      
                    } catch(e){
                      Runtime.exceptionHandler(__LINE__, __FILE__, e);
                    }
                  };
              __LINE__ = 4362602312;
              return Runtime.createGenerator(_mochaGenerator,
              function () {
                try {
                  __LINE__ = 4362602312;
                  _yieldState = -1;
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              },this);
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          }.call(this);
      
      __LINE__ = 10;
      Runtime.assert(true,test.next() === 100,"test.next() === 100",10,'generator_expression_test.js');
      
      __LINE__ = 11;
      Runtime.assert(true,test.next() === 200,"test.next() === 200",11,'generator_expression_test.js');
      
      __LINE__ = 12;
      Runtime.assert(true,test.next() === 300,"test.next() === 300",12,'generator_expression_test.js');
      
      __LINE__ = 14;
      test = function () {
        try {
          __LINE__ = 4362613064;
          var _mochaIsNewBorn = true,
              _yieldResult = undefined,
              _yieldState = 0,
              x,
              _mochaLocalTmp4 = keys(testObject),
              _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                try {
                  __LINE__ = 4362613064;
                  !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler('attempt to send to newborn generator.');
                  
                  __LINE__ = 4362613064;
                  while (1){
                    
                    __LINE__ = 4362613064;
                    switch (_yieldState) {
                      case 0 :
                        
                        __LINE__ = 14;
                        _mochaLocalTmp4 = Runtime.hasIterator(_mochaLocalTmp4)?Runtime.getIterator(_mochaLocalTmp4) : _mochaLocalTmp4;
                        
                        __LINE__ = 14;
                        if (_mochaLocalTmp4.__nothrowNext__){
                          
                          __LINE__ = 14;
                          _yieldState = 1;
                          __LINE__ = 14;
                          break;
                        } else {
                          
                          __LINE__ = 14;
                          _yieldState = 5;
                          __LINE__ = 14;
                          break;
                        }
                      case 1 :
                        
                        __LINE__ = 14;
                        if (!((x = _mochaLocalTmp4.__nothrowNext__()))){
                          
                          __LINE__ = 14;
                          _yieldState = 4;
                          __LINE__ = 14;
                          break;
                        }
                      case 2 :
                        
                        __LINE__ = 4362613064;
                        _yieldState = 3;
                        __LINE__ = 4362613064;
                        return x;
                      case 3 :
                        
                        __LINE__ = 14;
                        if ((x = _mochaLocalTmp4.__nothrowNext__())){
                          
                          __LINE__ = 0;
                          _yieldState = 2;
                          __LINE__ = 14;
                          break;
                        } else {
                          __LINE__ = 0;
                          _yieldState = 4;
                        }
                      case 4 :
                        
                        __LINE__ = 14;
                        _yieldState = -1;
                        __LINE__ = 14;
                        break;
                      case 5 :
                        
                        __LINE__ = 14;
                        Runtime.exceptionHandler(14,generator_expression_test.js,'for of statement expect iterator or generator object.');
                      case 6 :
                      case -1 :
                        
                        __LINE__ = 4362613064;
                        if (_isYieldSafe){
                          __LINE__ = 4362613064;
                          return undefined;
                        }
                        
                        __LINE__ = 4362613064;
                        Runtime.throwStopIteration();
                        
                    }
                    
                  }
                  
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              };
          __LINE__ = 4362613064;
          return Runtime.createGenerator(_mochaGenerator,
          function () {
            try {
              __LINE__ = 4362613064;
              _yieldState = -1;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          },this);
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }.call(this);
      
      __LINE__ = 16;
      Runtime.assert(true,test.next() === "value1","test.next() === \"value1\"",16,'generator_expression_test.js');
      
      __LINE__ = 17;
      Runtime.assert(true,test.next() === "value2","test.next() === \"value2\"",17,'generator_expression_test.js');
      
      __LINE__ = 18;
      Runtime.assert(true,test.next() === "value3","test.next() === \"value3\"",18,'generator_expression_test.js');
      
      __LINE__ = 20;
      test = function () {
        try {
          __LINE__ = 20;
          var _mochaIsNewBorn = true,
              _yieldResult = undefined,
              _yieldState = 0,
              length,
              _mochaLocalTmp7,
              x,
              _mochaLocalTmp6 = [],
              _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                try {
                  __LINE__ = 20;
                  !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler('attempt to send to newborn generator.');
                  
                  __LINE__ = 20;
                  while (1){
                    
                    __LINE__ = 20;
                    switch (_yieldState) {
                      case 0 :
                        
                        __LINE__ = 20;
                        for (var _mochaLocalTmp5 in testObject){
                          
                          __LINE__ = 20;
                          _mochaLocalTmp6.push(_mochaLocalTmp5);
                        }
                        
                        __LINE__ = 20;
                        _mochaLocalTmp7 = 0;
                        
                        __LINE__ = 20;
                        length = _mochaLocalTmp6.length;
                        
                        __LINE__ = 20;
                        if (!(_mochaLocalTmp7<length)){
                          
                          __LINE__ = 20;
                          _yieldState = -1;
                          __LINE__ = 20;
                          break;
                        }
                      case 1 :
                        
                        __LINE__ = 20;
                        x = _mochaLocalTmp6[_mochaLocalTmp7];
                        
                        __LINE__ = 20;
                        x = testObject[x];
                        
                        __LINE__ = 20;
                        if (x === 200){
                          
                          __LINE__ = 20;
                          _yieldState = 2;
                          __LINE__ = 20;
                          break;
                        } else {
                          
                          __LINE__ = 20;
                          _yieldState = 3;
                          __LINE__ = 20;
                          break;
                        }
                      case 2 :
                        
                        __LINE__ = 20;
                        _yieldState = 3;
                        __LINE__ = 20;
                        return x;
                      case 3 :
                        
                        __LINE__ = 20;
                        _yieldState = 4;
                        __LINE__ = 20;
                        break;
                      case 4 :
                        
                        __LINE__ = 20;
                         ++ _mochaLocalTmp7;
                        
                        __LINE__ = 20;
                        if (_mochaLocalTmp7<length){
                          
                          __LINE__ = 0;
                          _yieldState = 1;
                          __LINE__ = 20;
                          break;
                        } else {
                          __LINE__ = 0;
                          _yieldState = -1;
                        }
                      case -1 :
                        
                        __LINE__ = 20;
                        if (_isYieldSafe){
                          __LINE__ = 20;
                          return undefined;
                        }
                        
                        __LINE__ = 20;
                        Runtime.throwStopIteration();
                        
                    }
                    
                  }
                  
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              };
          __LINE__ = 20;
          return Runtime.createGenerator(_mochaGenerator,
          function () {
            try {
              __LINE__ = 20;
              _yieldState = -1;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          },this);
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }.call(this);
      
      __LINE__ = 21;
      Runtime.assert(true,test.next() === 200,"test.next() === 200",21,'generator_expression_test.js');
      
      __LINE__ = 23;
      test = function () {
        try {
          __LINE__ = 23;
          var _mochaIsNewBorn = true,
              _yieldResult = undefined,
              _yieldState = 0,
              x,
              _mochaLocalTmp8 = keys(testObject),
              _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                try {
                  __LINE__ = 23;
                  !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler('attempt to send to newborn generator.');
                  
                  __LINE__ = 23;
                  while (1){
                    
                    __LINE__ = 23;
                    switch (_yieldState) {
                      case 0 :
                        
                        __LINE__ = 23;
                        _mochaLocalTmp8 = Runtime.hasIterator(_mochaLocalTmp8)?Runtime.getIterator(_mochaLocalTmp8) : _mochaLocalTmp8;
                        
                        __LINE__ = 23;
                        if (_mochaLocalTmp8.__nothrowNext__){
                          
                          __LINE__ = 23;
                          _yieldState = 1;
                          __LINE__ = 23;
                          break;
                        } else {
                          
                          __LINE__ = 23;
                          _yieldState = 7;
                          __LINE__ = 23;
                          break;
                        }
                      case 1 :
                        
                        __LINE__ = 23;
                        if (!((x = _mochaLocalTmp8.__nothrowNext__()))){
                          
                          __LINE__ = 23;
                          _yieldState = 6;
                          __LINE__ = 23;
                          break;
                        }
                      case 2 :
                        
                        __LINE__ = 23;
                        if (x === "value2"){
                          
                          __LINE__ = 23;
                          _yieldState = 3;
                          __LINE__ = 23;
                          break;
                        } else {
                          
                          __LINE__ = 23;
                          _yieldState = 4;
                          __LINE__ = 23;
                          break;
                        }
                      case 3 :
                        
                        __LINE__ = 23;
                        _yieldState = 4;
                        __LINE__ = 23;
                        return x;
                      case 4 :
                        
                        __LINE__ = 23;
                        _yieldState = 5;
                        __LINE__ = 23;
                        break;
                      case 5 :
                        
                        __LINE__ = 23;
                        if ((x = _mochaLocalTmp8.__nothrowNext__())){
                          
                          __LINE__ = 0;
                          _yieldState = 2;
                          __LINE__ = 23;
                          break;
                        } else {
                          __LINE__ = 0;
                          _yieldState = 6;
                        }
                      case 6 :
                        
                        __LINE__ = 23;
                        _yieldState = -1;
                        __LINE__ = 23;
                        break;
                      case 7 :
                        
                        __LINE__ = 23;
                        Runtime.exceptionHandler(23,generator_expression_test.js,'for of statement expect iterator or generator object.');
                      case 8 :
                      case -1 :
                        
                        __LINE__ = 23;
                        if (_isYieldSafe){
                          __LINE__ = 23;
                          return undefined;
                        }
                        
                        __LINE__ = 23;
                        Runtime.throwStopIteration();
                        
                    }
                    
                  }
                  
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              };
          __LINE__ = 23;
          return Runtime.createGenerator(_mochaGenerator,
          function () {
            try {
              __LINE__ = 23;
              _yieldState = -1;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          },this);
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }.call(this);
      
      __LINE__ = 24;
      Runtime.assert(true,test.next() === "value2","test.next() === \"value2\"",24,'generator_expression_test.js');
    } catch(e){
      Runtime.exceptionHandler(__LINE__, __FILE__, e);
    }
  }();
}();
