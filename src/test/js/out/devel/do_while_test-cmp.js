!function() {
  var __FILE__ = "Runtime",
      __LINE__ = 0;
  
  var global = (this !== null)?this : typeof window === 'object'?window : {};
  
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
        
        Runtime.assert(true,typeof type === "string","typeof type === \"string\"",44,'runtime.js');
        
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
        "use strict";
        function spreadCall(context,fn,args,isNew) {
          var newArgs = [];
          
          for (var i = 0,len = args.length;i<len;i += 2){
            
            args[i] === true?push.apply(newArgs,args[i+1]) : newArgs.push(args[i+1]);
          }
          
          if (isNew){
            
            var tmp = function (){};
            
            tmp.prototype = fn.prototype;
            
            tmp = new tmp;
            
            fn.apply(tmp,newArgs);
            return tmp;
          } else {
            return fn.apply(context,newArgs);
          }
          
        }
        function checkRequirements(_mochaLocalTmp8,_mochaLocalTmp9,traits,file,line) {
          var proto1 = _mochaLocalTmp8.prototype,
              proto2 = _mochaLocalTmp9.prototype;
          
          for (var i = 0,len = traits.length;i<len;i ++ ){
            
            var _mochaLocalTmp10 = traits[i],
                _mochaRequires = _mochaLocalTmp10._mochaRequires;
            
            for (var prop in _mochaRequires){
              !(prop in proto1) && !(prop in proto2) && Runtime.throwException("Class dose not meet the traits requirement. traits require implementation of property "+prop+"\nin file "+file+" at line "+line);
            }
            
          }
          
        }
        function classMixin(_mochaLocalTmp5,_mochaLocalTmp6,_mochaLocalTmp7,with_,without) {
          var constructorProto = _mochaLocalTmp5.prototype,
              privateProto = _mochaLocalTmp6.prototype,
              mark = _mochaLocalTmp7._mochaTraitMark,
              traitPublic = _mochaLocalTmp7._mochaTraitPublic,
              traitPrivate = _mochaLocalTmp7._mochaTraitPrivate;
          
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
          
          createPrivateRecord(instance,privateHolder,constructor);
          
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
        function ModuleContainer(){}
        function Module(){}
        function RecordConstructor(obj) {
          for (var i in obj){
            
            this[i] = obj[i];
          }
          
          Object.freeze(this);
        }
        function TupleConstructor(args) {
          push.apply(this,args);
          
          Object.freeze(this);
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
            arrayProto = Array.prototype,
            slice = arrayProto.slice,
            push = arrayProto.push,
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
        
        _mochaLocalExport.TupleConstructor = TupleConstructor;
        
        TupleConstructor.prototype =  {
          compareTuple : function (tuple) {
            var maxIndex = max(tuple.length,this.length),
                i = -1;
            
            while ( ++ i<maxIndex && tuple[i] === this[i]){
              
            }
            return maxIndex === i;
          },
          tupleToArray : function () {
            return slice.call(this);
          },
          toString : function () {
            return "[object Tuple]";
          }
        };
        
        _mochaLocalExport.RecordConstructor = RecordConstructor;
        
        RecordConstructor.prototpye =  {
          toString : function () {
            return "[object Record]";
          }
        };
        
        var extendPrototype = _mochaLocalExport.extendPrototype = function (derived,base) {
              derived.prototype = base;
            };
        
        Object.defineProperty(ModuleContainer.prototype,'_modules', {
          value : {},
          writable : true
        });
        
        Object.defineProperty(ModuleContainer.prototype,'add', {
          value : function (name) {
            return this._modules[name] = new Module;
          }
        });
        
        Object.defineProperty(ModuleContainer.prototype,'get', {
          value : function (name) {
            return this._modules[name];
          }
        });
        
        Object.defineProperty(ModuleContainer.prototype,'toString', {
          value : function () {
            return "[object ModuleContainer]";
          }
        });
        
        Object.defineProperty(Module.prototype,'toString', {
          value : function () {
            return "[object Module]";
          }
        });
        
        var modules = _mochaLocalExport.modules = new ModuleContainer,
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
                  i !== 'prototype' && (derived[i] = base[i]);
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
            getPrivateRecord,
            getInstanceBody;
        
        if ("WeakMap" in global){
          
          privateRecord = new WeakMap();
          
          createPrivateRecord = function (self,privateHolder,constructor) {
            var holder = new privateHolder;
            
            createUnenumProp(holder,"__is_private__",1);
            
            createUnenumProp(self,"constructor",constructor);
            
            privateRecord.set(self,holder);
            
            privateRecord.set(holder,self);
          };
          
          getPrivateRecord = function (self) {
            if (privateRecord.has(self)){
              return privateRecord.get(self);
            } else if (self.__is_private__ === 1){
              return self;
            }
            
          };
          
          getInstanceBody = function (privateHolder) {
            return privateRecord.get(privateHolder);
          };
        } else {
          
          createPrivateRecord = function (self,privateHolder,constructor) {
            if (!self.__typeid__){
              
              var holder = new privateHolder,
                  privateSlot = {};
              
              Object.defineProperty(privateSlot,"__is_private__", {
                value : 1
              });
              
              Object.defineProperty(privateSlot,"__parent__", {
                value : self
              });
              
              Object.defineProperty(holder,"constructor", {
                value : privateSlot
              });
              
              createUnenumProp(constructor,"__private__",holder);
              
              createUnenumProp(self,"constructor",constructor);
            }
            
          };
          
          getPrivateRecord = function (self) {
            if (self.constructor.__private__){
              return self.constructor.__private__;
            } else if (self.constructor.__is_private__ === 1){
              return self;
            }
            
          };
          
          getInstanceBody = function (privateHolder) {
            return privateHolder.constructor.__parent__;
          };
        }
        
        _mochaLocalExport.getPrivateRecord = getPrivateRecord;
        
        _mochaLocalExport.getInstanceBody = getInstanceBody;
        
        _mochaLocalExport.initializeClass = initializeClass;
        
        _mochaLocalExport.getSuper = getSuper;
        
        _mochaLocalExport.traitMixin = traitMixin;
        
        _mochaLocalExport.classMixin = classMixin;
        
        _mochaLocalExport.checkRequirements = checkRequirements;
        
        _mochaLocalExport.spreadCall = spreadCall;
        
        !function () {
          var assert = _mochaLocalExport.assert = (global.console && global.console.assert)?function (expect,exp,str,line,filename) {
                return global.console.assert(expect === exp,"assertion failed : "+str+"\nexpect "+expect+" but got "+exp+"\nin file "+filename+" at : "+line);
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
  
  function Tuple(args) {
    args = Runtime.toArray(arguments,0);
    return new Runtime.TupleConstructor(args);
  }
  Tuple.prototype = Runtime.TupleConstructor.prototype;
  
  function Record(member) {
    return new Runtime.RecordConstructor(member);
  }
  Record.prototype = Runtime.RecordConstructor.prototype;
  
  __LINE__ = 0;
  !function () {
    try {
      var __FILE__ = "1653259312-do_while_test.js",
          __LINE__ = 0;
      __LINE__ = 2;
      Runtime.modules.add('1653259312-do_while_test.js');
      
      __LINE__ = 1;
      var testvalue = 9,
          table = ['a','b','c','d','e','f','g','h','i','j'],
          ret = [];
      
      __LINE__ = 4;
      do {
        __LINE__ = 5;
        ret.push(table[testvalue]);
      }while (testvalue -- );
      
      __LINE__ = 8;
      Runtime.assert(true,ret[0] === 'j',"ret[0] === 'j'",8,'do_while_test.js');
      
      __LINE__ = 9;
      Runtime.assert(true,ret[1] === 'i',"ret[1] === 'i'",9,'do_while_test.js');
      
      __LINE__ = 10;
      Runtime.assert(true,ret[2] === 'h',"ret[2] === 'h'",10,'do_while_test.js');
      
      __LINE__ = 11;
      Runtime.assert(true,ret[3] === 'g',"ret[3] === 'g'",11,'do_while_test.js');
      
      __LINE__ = 12;
      Runtime.assert(true,ret[4] === 'f',"ret[4] === 'f'",12,'do_while_test.js');
      
      __LINE__ = 13;
      Runtime.assert(true,ret[5] === 'e',"ret[5] === 'e'",13,'do_while_test.js');
      
      __LINE__ = 14;
      Runtime.assert(true,ret[6] === 'd',"ret[6] === 'd'",14,'do_while_test.js');
      
      __LINE__ = 15;
      Runtime.assert(true,ret[7] === 'c',"ret[7] === 'c'",15,'do_while_test.js');
      
      __LINE__ = 16;
      Runtime.assert(true,ret[8] === 'b',"ret[8] === 'b'",16,'do_while_test.js');
      
      __LINE__ = 17;
      Runtime.assert(true,ret[9] === 'a',"ret[9] === 'a'",17,'do_while_test.js');
      
      __LINE__ = 19;
      testvalue = 9;
      
      __LINE__ = 20;
      ret = [];
      
      __LINE__ = 21;
      do {
        __LINE__ = 21;
        ret.push(table[testvalue]);
      }while (testvalue -- );
      
      __LINE__ = 24;
      Runtime.assert(true,ret[0] === 'j',"ret[0] === 'j'",24,'do_while_test.js');
      
      __LINE__ = 25;
      Runtime.assert(true,ret[1] === 'i',"ret[1] === 'i'",25,'do_while_test.js');
      
      __LINE__ = 26;
      Runtime.assert(true,ret[2] === 'h',"ret[2] === 'h'",26,'do_while_test.js');
      
      __LINE__ = 27;
      Runtime.assert(true,ret[3] === 'g',"ret[3] === 'g'",27,'do_while_test.js');
      
      __LINE__ = 28;
      Runtime.assert(true,ret[4] === 'f',"ret[4] === 'f'",28,'do_while_test.js');
      
      __LINE__ = 29;
      Runtime.assert(true,ret[5] === 'e',"ret[5] === 'e'",29,'do_while_test.js');
      
      __LINE__ = 30;
      Runtime.assert(true,ret[6] === 'd',"ret[6] === 'd'",30,'do_while_test.js');
      
      __LINE__ = 31;
      Runtime.assert(true,ret[7] === 'c',"ret[7] === 'c'",31,'do_while_test.js');
      
      __LINE__ = 32;
      Runtime.assert(true,ret[8] === 'b',"ret[8] === 'b'",32,'do_while_test.js');
      
      __LINE__ = 33;
      Runtime.assert(true,ret[9] === 'a',"ret[9] === 'a'",33,'do_while_test.js');
    } catch(e){
      Runtime.exceptionHandler(__LINE__, __FILE__, e);
    }
  }();
}();
