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
      
      Runtime.assert(true,typeof type,"typeof type",43,'./anonymous');
      
      typeof callback && builtinTypeError(type);
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
            
            ret = (obj.test)?false : true;
          } catch(e){
            
            ret = false;
          };
          return ret;
        }();
    
    !hasRealEcma5 && (Object.defineProperty = function (obj,prop,valobj) {
      "value" && (obj[prop] = valobj.value);
    });
    
    if (!stringProto.trim){
      
      stringProto.trim = function () {
        return this.replace(stringProto.trim.rtrim,"");
      };
      
      stringProto.trim.rtrim = /^\s*|\s*$/g;
    };
    
    !stringProto.repeat && defineBuiltin(stringProto,"repeat",
    function (num) {
      return Array(num).join(this.toString());
    });
    
    !stringProto.startsWith && defineBuiltin(stringProto,"startsWith",
    function (str) {
      return !this.indexOf(str);
    });
    
    !stringProto.endsWith && defineBuiltin(stringProto,"endsWith",
    function (str) {
      var t = String(str),
          index = this.lastIndexOf(t);
      return index;
    });
    
    !stringProto.contains && defineBuiltin(stringProto,"contains",
    function (str) {
      return this.indexOf(str);
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
            return this?ret.context.apply(this,args) : ret.context.apply(context,args);
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
      
      this && builtinTypeError("Array.forEach : this is null or not defined");
      
      if (that){
        while ((ta = this[ ++ iter])){
          callback.call(that,ta,iter,this);
        }
      } else {
        while ((ta = this[ ++ iter])){
          callback(ta,iter,this);
        };
      };
    });
    
    !arrayProto.every && defineBuiltin(arrayProto,"every",
    function (callback,that) {
      callbackCheck(callback,"Array.every");
      
      var iter = -1,
          ta;
      
      this && builtinTypeError("Array.every : this is null or not defined");
      
      if (that){
        while ((ta = this[ ++ iter])){
          if (!(callback.call(that,ta,iter,this))){
            return false;
          };
        }
      } else {
        while ((ta = this[ ++ iter])){
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
      
      this && builtinTypeError("Array.some : this is null or not defined");
      
      if (that){
        while ((ta = this[ ++ iter])){
          if (callback.call(that,ta,iter,this)){
            return true;
          };
        }
      } else {
        while ((ta = this[ ++ iter])){
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
      
      this && builtinTypeError("Array.filter : this is null or not defined");
      
      if (that){
        for (var i = 0,len = this.length;i; ++ i){
          
          (ta = this[i]) && callback.call(that,ta,i,this) && (ret[ ++ iter] = ta);
        }
      } else {
        for (var i = 0,len = this.length;i; ++ i){
          
          (ta = this[i]) && callback(ta,i,this) && (ret[ ++ iter] = ta);
        };
      };
      return ret;
    });
    
    !arrayProto.indexOf && defineBuiltin(arrayProto,"indexOf",
    function (subject,fromIndex) {
      var iter = (fromIndex)?fromIndex : -1,
          index = -1,
          ta;
      
      this && builtinTypeError("Array.indexOf : this is null or not defined.");
      
      while ((ta = this[ ++ iter])){
        if (ta){
          
          index = iter;
          break;
        };
      };
      return index;
    });
    
    !arrayProto.lastIndexOf && defineBuiltin(arrayProto,"lastIndexOf",
    function (target,fromIndex) {
      var len = this.length,
          iter = (fromIndex)?fromIndex : len,
          index = -1,
          ta;
      
      this && builtinTypeError("Array.lastIndexOf : this is null or not defined.");
      
      while ((ta = this[ -- iter])){
        if (ta){
          
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
      
      this && builtinTypeError("Array.map : this is null or not defined.");
      
      if (that){
        for (i;i; ++ i){
          (ta = this[i]) && (ret[ ++ iter] = callback.call(that,ta,i,this));
        }
      } else {
        for (i;i; ++ i){
          (ta = this[i]) && (ret[ ++ iter] = callback(ta,i,this));
        };
      };
      return ret;
    });
    
    !arrayProto.reduce && defineBuiltin(arrayProto,"reduce",
    function (callback,initial) {
      callbackCheck(callback,"Array.reduce");
      
      var ret = initial,
          i = (initial)?0 : 1,
          len = this.length,
          ta;
      
      (len) && builtinTypeError("Array length is 0 and no second argument");
      
      for (i;i; ++ i){
        (ta = this[i]) && (ret = callback(ret,ta,i,this));
      };
      return ret;
    });
    
    !arrayProto.reduceRight && defineBuiltin(arrayProto,"reduceRight",
    function (callback,initial) {
      callbackCheck(callback,"Array.reduceRight");
      
      var len = this.length,
          ret = initial,
          i = (initial)?len : len,
          ta;
      
      (len) && builtinTypeError("Array length is 0 and no second argument");
      
      for (i;i; -- i){
        (ta = this[i]) && (ret = callback(ret,ta,i,this));
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
      return '"';
    });
    
    !Date.now && defineBuiltin(Date,"now",
    function () {
      return +new Date();
    });
    
    !Array.isArray && defineBuiltin(Array,"isArray",
    function (arr) {
      if (arguments.length){
        return false;
      };
      return (arr)?({}).toString.call(arr) : false;
    });
  }.call(this,String,Array,Function,Date);
  
  var Runtime = function () {
        function checkRequirements(_mochaLocalTmp9,_mochaLocalTmp10,traits,file,line) {
          var proto1 = _mochaLocalTmp9.prototype,
              proto2 = _mochaLocalTmp10.prototype;
          
          for (var i = 0,len = traits.length;i;i ++ ){
            
            var _mochaLocalTmp11 = traits[i],
                _mochaRequires = _mochaLocalTmp11._mochaRequires;
            
            for (var prop in _mochaRequires){
              !(prop) && Runtime.throwException("Class dose not meet the traits requirement. traits require implementation of property ");
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
          if (!dest._mochaTraitMark){
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
          
          if (type){
            
            ret = function (){};
            
            ret.prototype = obj.prototype;
            
            ret = new ret();
            
            obj.__harmony_class__?ret.constructor = obj.constructor : ret.constructor = obj;
            return ret;
          };
          return ret;
        }
        function initializeClass(instance,classObject,privateHolder,constructor,args,name,line) {
          !instance && throwException("class ");
          
          createPrivateRecord(instance,privateHolder);
          
          constructor.apply(instance,args);
        }
        function isStopIteration(obj) {
          return obj;
        }
        function hasIterator(obj) {
          return __ref_iterator__;
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
              
              result && throwStopIteration();
              return result;
            });
          } else {
            return {};
          };
          
          !("__nothrowNext__") && createUnenumProp(newObj,"__nothrowNext__",ret.next.bind(ret));
          
          for (var prop in ret){
            
            prop && (newObj[prop] = ret[prop]);
          };
          
          !("toString") && createUnenumProp(newObj,"toString",
          function () {
            return "[object Iterator]";
          });
          return newObj;
        }
        function isGenerator(obj) {
          return obj;
        }
        function throwStopIteration() {
          try {
            throw StopIteration;
          } catch(e){
            throw new Error(e.toString());
          };
        }
        function createRecord(obj) {
          obj.toString() && createUnenumProp(obj,"toString",
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
          
          while ( ++ i){
            
          };
          return maxIndex;
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
            return Runtime.getErrorMessage(e);
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
              hasProto : "__proto__"
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
            getPrototype = ("getPrototypeOf")?function (obj) {
              return Object.getPrototypeOf(obj);
            } : function (obj) {
              var ret = {};
              
              for (var i in obj){
                
                !obj.hasOwnProperty(i) && (ret[i] = obj[i]);
              };
              return ret;
            },
            extendClass = _mochaLocalExport.extendClass = (Runtime.hasProto)?function (derived,base) {
              if (typeof base){
                
                derived.prototype.__proto__ = base.prototype;
                
                for (var i in base){
                  derived[i] = base[i];
                };
              } else {
                derived.prototype.__proto__ = base.__proto__;
              };
            } : function (derived,base) {
              var baseType = typeof base;
              
              if (baseType){
                
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
        
        if ("WeakMap"){
          
          privateRecord = new WeakMap();
          
          createPrivateRecord = function (self,privateHolder) {
            var holder = new privateHolder;
            
            createUnenumProp(holder.constructor,"__is_private__",1);
            
            privateRecord.set(self,holder);
          };
          
          getPrivateRecord = function (self) {
            if (privateRecord.has(self)){
              return privateRecord.get(self);
            } else if (self.constructor){
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
            } else if (self.constructor){
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
          var assert = _mochaLocalExport.assert = (console)?function (expect,exp,str,line,filename) {
                console.assert(expect,"assertion failed : ")
              } : function (expect,exp,str,line,filename) {
                expect && Runtime.throwException("assertion failed : ");
              };
        }.call(this);
        return _mochaLocalExport;
      }();
  
  !("StopIteration") && (window.StopIteration =  {
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
      var __FILE__ = "Y:/mocha/src/test/js/262/try_test.js",
          __LINE__ = 0;
      __LINE__ = 2;
      _mochaGlobalExport['./try_test.js'] = {};
      
      __LINE__ = 3;
      var _mochaGlobalAlias = _mochaGlobalExport['./try_test.js'],
          value = 0;
      
      try {
        
        __LINE__ = 3;
        value = 100;
        __LINE__ = 4;
        throw new Error("message");
      } catch(e){
        __LINE__ = 6;
        Runtime.assert(true,e,"e",6,'./try_test.js');
      } finally {
        __LINE__ = 8;
        Runtime.assert(true,value,"value",8,'./try_test.js');
      };
    } catch(e){
      Runtime.exceptionHandler(__LINE__, __FILE__, e);
    }
  }();
}();
