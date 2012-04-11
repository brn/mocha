!function() {
  
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
        
        typeof callback !== "function" && builtinTypeError(type+" : first argument is not callable");
      }
      function builtinTypeError(message) {
        try {
          throw new TypeError(message)
          
        } catch(e){
          throw new Error(e)
          
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
        
        for (var i in obj)
        obj.hasOwnProperty(i) && (ret[ ++ iter] = obj[i]);
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
        
        if (that)while ((ta = this[ ++ iter]) !== null && ta !== undefined)callback.call(that,ta,iter,this);
         else while ((ta = this[ ++ iter]) !== null && ta !== undefined)callback(ta,iter,this);
      });
      
      !arrayProto.every && defineBuiltin(arrayProto,"every",
      function (callback,that) {
        callbackCheck(callback,"Array.every");
        
        var iter = -1,
            ta;
        
        this === null && builtinTypeError("Array.every : this is null or not defined");
        
        if (that)while ((ta = this[ ++ iter]) !== null && ta !== undefined)if (!(callback.call(that,ta,iter,this)))return false;
         else while ((ta = this[ ++ iter]) !== null && ta !== undefined)if (!(callback(ta,iter,this)))return false;
        return true;
      });
      
      !arrayProto.some && defineBuiltin(arrayProto,"some",
      function (callback,that) {
        callbackCheck(callback,"Array.some");
        
        var iter = -1,
            ta;
        
        this === null && builtinTypeError("Array.some : this is null or not defined");
        
        if (that)while ((ta = this[ ++ iter]) !== null && ta !== undefined)if (callback.call(that,ta,iter,this))return true;
         else while ((ta = this[ ++ iter]) !== null && ta !== undefined)if (callback(ta,iter,this))return true;
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
        
        if (that)for (var i = 0,len = this.length;i<len; ++ i)
        (ta = this[i]) !== null && ta !== undefined && callback.call(that,ta,i,this) && (ret[ ++ iter] = ta);
         else for (var i = 0,len = this.length;i<len; ++ i)
        (ta = this[i]) !== null && ta !== undefined && callback(ta,i,this) && (ret[ ++ iter] = ta);
        return ret;
      });
      
      !arrayProto.indexOf && defineBuiltin(arrayProto,"indexOf",
      function (subject,fromIndex) {
        var iter = (fromIndex)?fromIndex-1 : -1,
            index = -1,
            ta;
        
        this === null && builtinTypeError("Array.indexOf : this is null or not defined.");
        
        while ((ta = this[ ++ iter]) !== null && ta !== undefined)if (ta === subject){
          
          index = iter;
          break;
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
        
        while ((ta = this[ -- iter]) !== null && ta !== undefined)if (ta === target){
          
          index = iter;
          break;
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
        
        if (that)for (i;i<len; ++ i)(ta = this[i]) !== null && ta !== undefined && (ret[ ++ iter] = callback.call(that,ta,i,this));
         else for (i;i<len; ++ i)(ta = this[i]) !== null && ta !== undefined && (ret[ ++ iter] = callback(ta,i,this));
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
        
        for (i;i<len; ++ i)(ta = this[i]) !== null && ta !== undefined && (ret = callback(ret,ta,i,this));
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
        
        for (i;i>-1; -- i)(ta = this[i]) !== null && ta !== undefined && (ret = callback(ret,ta,i,this));
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
        if (arguments.length === 0)return false;
        return (arr)?({}).toString.call(arr) === "[object Array]" : false;
      });
    }.call(this,String,Array,Function,Date);
  }.call(this);
  
  var Runtime = function () {
        "use strict";
        function checkRequirements(_mochaLocalTmp9,_mochaLocalTmp10,traits,file,line) {
          var proto1 = _mochaLocalTmp9.prototype,
              proto2 = _mochaLocalTmp10.prototype;
          
          for (var i = 0,len = traits.length;i<len;i ++ ){
            
            var _mochaLocalTmp11 = traits[i],
                _mochaRequires = _mochaLocalTmp11._mochaRequires;
            
            for (var prop in _mochaRequires)!(prop in proto1) && !(prop in proto2) && Runtime.throwException("Class dose not meet the traits requirement. traits require implementation of property "+prop+"\nin file "+file+" at line "+line);
          }
          
        }
        function classMixin(_mochaLocalTmp6,_mochaLocalTmp7,_mochaLocalTmp8,with_,without) {
          var constructorProto = _mochaLocalTmp6.prototype,
              privateProto = _mochaLocalTmp7.prototype,
              mark = _mochaLocalTmp8._mochaTraitMark,
              traitPublic = _mochaLocalTmp8._mochaTraitPublic,
              traitPrivate = _mochaLocalTmp8._mochaTraitPrivate;
          
          if (!mark)Runtime.throwException("mixin only used for trait.");
           else {
            
            var tmp;
            
            for (var i in traitPublic)if (!without[i]){
              
              tmp = (!with_[i])?i : with_[i];
              
              constructorProto[tmp] = traitPublic[i];
            }
            
            for (i in traitPrivate)if (!without[i]){
              
              tmp = (!with_[i])?i : with_[i];
              
              privateProto[tmp] = traitPrivate[i];
            }
            
          }
          
        }
        function traitMixin(dest,source,with_,without) {
          if (!dest._mochaTraitMark || !source._mochaTraitMark)Runtime.throwException("mixin only used for trait.");
           else {
            
            var destTraitPrivate = dest._mochaTraitPrivate,
                sourceTraitPrivate = source._mochaTraitPrivate,
                destTraitPublic = dest._mochaTraitPublic,
                sourceTraitPublic = source._mochaTraitPublic,
                sourceRequires = source._mochaRequires,
                destRequires = dest._mochaRequires,
                tmp;
            
            for (var i in sourceTraitPrivate)if (!without[i]){
              
              tmp = (!with_[i])?i : with_[i];
              
              destTraitPrivate[tmp] = sourceTraitPrivate[i];
            }
            
            for (i in sourceTraitPublic)if (!without[i]){
              
              tmp = (!with_[i])?i : with_[i];
              
              destTraitPublic[tmp] = sourceTraitPublic[i];
            }
            
            for (i in sourceRequires)destRequires[i] = sourceRequires[i];
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
          
          if (isGenerator(ret))return ret;
          
          newObj = {};
          
          if (ret.next)createUnenumProp(newObj,"next",
          function () {
            var result = ret.next();
            
            result === undefined && throwStopIteration();
            return result;
          });
           else return {};
          
          !("__nothrowNext__" in ret) && createUnenumProp(newObj,"__nothrowNext__",ret.next.bind(ret));
          
          for (var prop in ret)
          prop !== "next" && prop !== "__nothrowNext__" && (newObj[prop] = ret[prop]);
          
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
            throw StopIteration
            
          } catch(e){
            throw new Error(e.toString())
            
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
          for (var prop in source)
          dest[prop] = source[prop];
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
                  throw exception
                  
                } catch(e){
                  
                  if (isStopIteration(e)){
                    throw new Error(e)
                    
                  } else {
                    throw new Error(this.getErrorMessage(e))
                    
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
              
              for (var i in obj)
              !obj.hasOwnProperty(i) && (ret[i] = obj[i]);
              return ret;
            },
            extendClass = _mochaLocalExport.extendClass = (Runtime.hasProto)?function (derived,base) {
              if (typeof base === 'function'){
                
                derived.prototype.__proto__ = base.prototype;
                
                for (var i in base)derived[i] = base[i];
              } else derived.prototype.__proto__ = base.__proto__;
            } : function (derived,base) {
              var baseType = typeof base;
              
              if (baseType === "function"){
                
                var inherit = function (){};
                
                inherit.prototype = base.prototype;
                
                derived.prototype = new inherit;
                
                for (var i in base)derived[i] = base[i];
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
            
            createUnenumProp(holder.constructor,"__is_private__",1);
            
            privateRecord.set(self,holder);
          };
          
          getPrivateRecord = function (self) {
            if (privateRecord.has(self))return privateRecord.get(self);
             else if (self.constructor === "__is_private__")return self;
          };
        } else {
          
          createPrivateRecord = function (self,privateHolder) {
            if (!self.__typeid__){
              
              var holder = new privateHolder;
              
              createUnenumProp(holder.constructor,"__is_private__",1);
              
              createUnenumProp(self,"__private__",holder);
            }
            
          };
          
          getPrivateRecord = function (self) {
            if (self.__private__)return self.__private__;
             else if (self.constructor === "__is_private__")return self;
          };
        }
        
        _mochaLocalExport.getPrivateRecord = getPrivateRecord;
        
        _mochaLocalExport.initializeClass = initializeClass;
        
        _mochaLocalExport.getSuper = getSuper;
        
        _mochaLocalExport.traitMixin = traitMixin;
        
        _mochaLocalExport.classMixin = classMixin;
        
        _mochaLocalExport.checkRequirements = checkRequirements;
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
  !function () {
    _mochaGlobalExport['-1426553882-knockout-2.0.0.debug.js'] = {};
    
    var _mochaGlobalAlias = _mochaGlobalExport['-1426553882-knockout-2.0.0.debug.js'];
    
    !function (window,undefined) {
      function ensureDropdownSelectionIsConsistentWithModelValue(element,modelValue,preferModelValue) {
        preferModelValue && modelValue !== ko.selectExtensions.readValue(element) && ko.selectExtensions.writeValue(element,modelValue);
        
        modelValue !== ko.selectExtensions.readValue(element) && ko.utils.triggerEvent(element,"change");
      }
      function prepareOptions(evaluatorFunctionOrOptions,evaluatorFunctionTarget,options) {
        if (evaluatorFunctionOrOptions && typeof evaluatorFunctionOrOptions == "object")options = evaluatorFunctionOrOptions;
         else {
          
          options = options || {};
          
          options.read = evaluatorFunctionOrOptions || options.read;
        }
        
        if (typeof options.read != "function")throw "Pass a function that returns the value of the dependentObservable"
        return options;
      }
      function applyExtenders(requestedExtenders) {
        var target = this;
        
        if (requestedExtenders)for (var key in requestedExtenders){
          
          var extenderHandler = ko.extenders[key];
          
          typeof extenderHandler == 'function' && (target = extenderHandler(target,requestedExtenders[key]));
        }
        return target;
      }
      var ko = window.ko = {};
      
      ko.exportSymbol = function (publicPath,object) {
        var tokens = publicPath.split("."),
            target = window;
        
        for (var i = 0;i<tokens.length-1;i ++ )
        target = target[tokens[i]];
        
        target[tokens[tokens.length-1]] = object;
      };
      
      ko.exportProperty = function (owner,publicName,object) {
        owner[publicName] = object;
      };
      
      ko.utils = new function () {
        function isClickOnCheckableElement(element,eventType) {
          if ((element.tagName != "INPUT") || !element.type)return false;
          
          if (eventType.toLowerCase() != "click")return false;
          
          var inputType = element.type.toLowerCase();
          return (inputType == "checkbox") || (inputType == "radio");
        }
        var stringTrimRegex = /^(\s|\u00A0)+|(\s|\u00A0)+$/g,
            knownEvents = {},
            knownEventTypesByEventName = {},
            keyEventTypeName = /Firefox\/2/i.test(navigator.userAgent)?'KeyboardEvent' : 'UIEvents';
        
        knownEvents[keyEventTypeName] = ['keyup','keydown','keypress'];
        
        knownEvents.MouseEvents = ['click','dblclick','mousedown','mouseup','mousemove','mouseover','mouseout','mouseenter','mouseleave'];
        
        for (var eventType in knownEvents){
          
          var knownEventsForType = knownEvents[eventType];
          
          if (knownEventsForType.length)for (var i = 0,j = knownEventsForType.length;i<j;i ++ )
          knownEventTypesByEventName[knownEventsForType[i]] = eventType;
        }
        
        var ieVersion = (function () {
              var version = 3,
                  div = document.createElement('div'),
                  iElems = div.getElementsByTagName('i');
              
              while (div.innerHTML = '<!--[if gt IE '+( ++ version)+']><i></i><![endif]-->', iElems[0])return version>4?version : undefined;
            }()),
            isIe6 = ieVersion === 6,
            isIe7 = ieVersion === 7;
        return  {
          fieldsIncludedWithJsonPost : ['authenticity_token',/^__RequestVerificationToken(_.*)?$/],
          arrayForEach : function (array,action) {
            for (var i = 0,j = array.length;i<j;i ++ ){
              
              action(array[i]);
            }
            
          },
          arrayIndexOf : function (array,item) {
            if (typeof Array.prototype.indexOf == "function"){
              return Array.prototype.indexOf.call(array,item);
            }
            
            for (var i = 0,j = array.length;i<j;i ++ ){
              
              if (array[i] === item){
                return i;
              }
              
            }
            return -1;
          },
          arrayFirst : function (array,predicate,predicateOwner) {
            for (var i = 0,j = array.length;i<j;i ++ ){
              
              if (predicate.call(predicateOwner,array[i])){
                return array[i];
              }
              
            }
            return null;
          },
          arrayRemoveItem : function (array,itemToRemove) {
            var index = ko.utils.arrayIndexOf(array,itemToRemove);
            
            if (index >= 0){
              
              array.splice(index,1);
            }
            
          },
          arrayGetDistinctValues : function (array) {
            array = array || [];
            
            var result = [];
            
            for (var i = 0,j = array.length;i<j;i ++ ){
              
              if (ko.utils.arrayIndexOf(result,array[i])<0){
                
                result.push(array[i]);
              }
              
            }
            return result;
          },
          arrayMap : function (array,mapping) {
            array = array || [];
            
            var result = [];
            
            for (var i = 0,j = array.length;i<j;i ++ ){
              
              result.push(mapping(array[i]));
            }
            return result;
          },
          arrayFilter : function (array,predicate) {
            array = array || [];
            
            var result = [];
            
            for (var i = 0,j = array.length;i<j;i ++ ){
              
              if (predicate(array[i])){
                
                result.push(array[i]);
              }
              
            }
            return result;
          },
          arrayPushAll : function (array,valuesToPush) {
            for (var i = 0,j = valuesToPush.length;i<j;i ++ ){
              
              array.push(valuesToPush[i]);
            }
            return array;
          },
          extend : function (target,source) {
            for (var prop in source){
              
              if (source.hasOwnProperty(prop)){
                
                target[prop] = source[prop];
              }
              
            }
            return target;
          },
          emptyDomNode : function (domNode) {
            while (domNode.firstChild){
              
              ko.removeNode(domNode.firstChild);
            }
            
          },
          setDomNodeChildren : function (domNode,childNodes) {
            ko.utils.emptyDomNode(domNode);
            
            if (childNodes){
              
              ko.utils.arrayForEach(childNodes,
              function (childNode) {
                domNode.appendChild(childNode);
              });
            }
            
          },
          replaceDomNodes : function (nodeToReplaceOrNodeArray,newNodesArray) {
            var nodesToReplaceArray = nodeToReplaceOrNodeArray.nodeType?[nodeToReplaceOrNodeArray] : nodeToReplaceOrNodeArray;
            
            if (nodesToReplaceArray.length>0){
              
              var insertionPoint = nodesToReplaceArray[0];
              
              var parent = insertionPoint.parentNode;
              
              for (var i = 0,j = newNodesArray.length;i<j;i ++ ){
                
                parent.insertBefore(newNodesArray[i],insertionPoint);
              }
              
              for (var i = 0,j = nodesToReplaceArray.length;i<j;i ++ ){
                
                ko.removeNode(nodesToReplaceArray[i]);
              }
              
            }
            
          },
          setOptionNodeSelectionState : function (optionNode,isSelected) {
            if (navigator.userAgent.indexOf("MSIE 6") >= 0){
              
              optionNode.setAttribute("selected",isSelected);
            } else optionNode.selected = isSelected;
          },
          stringTrim : function (string) {
            return (string || "").replace(stringTrimRegex,"");
          },
          stringTokenize : function (string,delimiter) {
            var result = [];
            
            var tokens = (string || "").split(delimiter);
            
            for (var i = 0,j = tokens.length;i<j;i ++ ){
              
              var trimmed = ko.utils.stringTrim(tokens[i]);
              
              if (trimmed !== ""){
                
                result.push(trimmed);
              }
              
            }
            return result;
          },
          stringStartsWith : function (string,startsWith) {
            string = string || "";
            
            if (startsWith.length>string.length){
              return false;
            }
            return string.substring(0,startsWith.length) === startsWith;
          },
          evalWithinScope : function (expression) {
            var scopes = Array.prototype.slice.call(arguments,1);
            
            var functionBody = "return ("+expression+")";
            
            for (var i = 0;i<scopes.length;i ++ ){
              
              if (scopes[i] && typeof scopes[i] == "object"){
                
                functionBody = "with(sc["+i+"]) { "+functionBody+" } ";
              }
              
            }
            return (new Function("sc",functionBody))(scopes);
          },
          domNodeIsContainedBy : function (node,containedByNode) {
            if (containedByNode.compareDocumentPosition){
              return (containedByNode.compareDocumentPosition(node)&16) == 16;
            }
            
            while (node != null){
              
              if (node == containedByNode){
                return true;
              }
              
              node = node.parentNode;
            }
            return false;
          },
          domNodeIsAttachedToDocument : function (node) {
            return ko.utils.domNodeIsContainedBy(node,document);
          },
          registerEventHandler : function (element,eventType,handler) {
            if (typeof jQuery != "undefined"){
              
              if (isClickOnCheckableElement(element,eventType)){
                
                var originalHandler = handler;
                
                handler = function (event,eventData) {
                  var jQuerySuppliedCheckedState = this.checked;
                  
                  if (eventData){
                    
                    this.checked = eventData.checkedStateBeforeEvent !== true;
                  }
                  
                  originalHandler.call(this,event);
                  
                  this.checked = jQuerySuppliedCheckedState;
                };
              }
              
              jQuery(element)['bind'](eventType,handler);
            } else if (typeof element.addEventListener == "function"){
              
              element.addEventListener(eventType,handler,false);
            } else if (typeof element.attachEvent != "undefined"){
              
              element.attachEvent("on"+eventType,
              function (event) {
                handler.call(element,event);
              });
            } else throw new Error("Browser doesn't support addEventListener or attachEvent")
            
          },
          triggerEvent : function (element,eventType) {
            if (!(element && element.nodeType)){
              throw new Error("element must be a DOM node when calling triggerEvent")
              
            }
            
            if (typeof jQuery != "undefined"){
              
              var eventData = [];
              
              if (isClickOnCheckableElement(element,eventType)){
                
                eventData.push( {
                  checkedStateBeforeEvent : element.checked
                });
              }
              
              jQuery(element)['trigger'](eventType,eventData);
            } else if (typeof document.createEvent == "function"){
              if (typeof element.dispatchEvent == "function"){
                
                var eventCategory = knownEventTypesByEventName[eventType] || "HTMLEvents";
                
                var event = document.createEvent(eventCategory);
                
                event.initEvent(eventType,true,true,window,0,0,0,0,0,false,false,false,false,0,element);
                
                element.dispatchEvent(event);
              } else throw new Error("The supplied element doesn't support dispatchEvent")
              
            } else if (typeof element.fireEvent != "undefined"){
              if (eventType == "click"){
                if ((element.tagName == "INPUT") && ((element.type.toLowerCase() == "checkbox") || (element.type.toLowerCase() == "radio"))){
                  
                  element.checked = element.checked !== true;
                }
                
              }
              
              element.fireEvent("on"+eventType);
            } else throw new Error("Browser doesn't support triggering events")
            
          },
          unwrapObservable : function (value) {
            return ko.isObservable(value)?value() : value;
          },
          domNodeHasCssClass : function (node,className) {
            var currentClassNames = (node.className || "").split(/\s+/);
            return ko.utils.arrayIndexOf(currentClassNames,className) >= 0;
          },
          toggleDomNodeCssClass : function (node,className,shouldHaveClass) {
            var hasClass = ko.utils.domNodeHasCssClass(node,className);
            
            if (shouldHaveClass && !hasClass){
              
              node.className = (node.className || "")+" "+className;
            } else if (hasClass && !shouldHaveClass){
              
              var currentClassNames = (node.className || "").split(/\s+/);
              
              var newClassName = "";
              
              for (var i = 0;i<currentClassNames.length;i ++ ){
                if (currentClassNames[i] != className){
                  
                  newClassName += currentClassNames[i]+" ";
                }
                
              }
              
              node.className = ko.utils.stringTrim(newClassName);
            }
            
          },
          outerHTML : function (node) {
            if (ieVersion === undefined){
              
              var nativeOuterHtml = node.outerHTML;
              
              if (typeof nativeOuterHtml == "string"){
                return nativeOuterHtml;
              }
              
            }
            
            var dummyContainer = window.document.createElement("div");
            
            dummyContainer.appendChild(node.cloneNode(true));
            return dummyContainer.innerHTML;
          },
          setTextContent : function (element,textContent) {
            var value = ko.utils.unwrapObservable(textContent);
            
            if ((value === null) || (value === undefined)){
              
              value = "";
            }
            
            'innerText' in element?element.innerText = value : element.textContent = value;
            
            if (ieVersion >= 9){
              
              element.innerHTML = element.innerHTML;
            }
            
          },
          range : function (min,max) {
            min = ko.utils.unwrapObservable(min);
            
            max = ko.utils.unwrapObservable(max);
            
            var result = [];
            
            for (var i = min;i <= max;i ++ ){
              
              result.push(i);
            }
            return result;
          },
          makeArray : function (arrayLikeObject) {
            var result = [];
            
            for (var i = 0,j = arrayLikeObject.length;i<j;i ++ ){
              
              result.push(arrayLikeObject[i]);
            }
            return result;
          },
          isIe6 : isIe6,
          isIe7 : isIe7,
          getFormFields : function (form,fieldName) {
            var fields = ko.utils.makeArray(form.getElementsByTagName("INPUT")).concat(ko.utils.makeArray(form.getElementsByTagName("TEXTAREA")));
            
            var isMatchingField = (typeof fieldName == 'string')?function (field) {
                  return field.name === fieldName;
                } : function (field) {
                  return fieldName.test(field.name);
                };
            
            var matches = [];
            
            for (var i = fields.length-1;i >= 0;i -- ){
              
              if (isMatchingField(fields[i])){
                
                matches.push(fields[i]);
              }
              
            }
            return matches;
          },
          parseJson : function (jsonString) {
            if (typeof jsonString == "string"){
              
              jsonString = ko.utils.stringTrim(jsonString);
              
              if (jsonString){
                
                if (window.JSON && window.JSON.parse){
                  return window.JSON.parse(jsonString);
                }
                return (new Function("return "+jsonString))();
              }
              
            }
            return null;
          },
          stringifyJson : function (data) {
            if ((typeof JSON == "undefined") || (typeof JSON.stringify == "undefined")){
              throw new Error("Cannot find JSON.stringify(). Some browsers (e.g., IE < 8) don't support it natively, but you can overcome this by adding a script reference to json2.js, downloadable from http://www.json.org/json2.js")
              
            }
            return JSON.stringify(ko.utils.unwrapObservable(data));
          },
          postJson : function (urlOrForm,data,options) {
            options = options || {};
            
            var params = options['params'] || {};
            
            var includeFields = options['includeFields'] || this.fieldsIncludedWithJsonPost;
            
            var url = urlOrForm;
            
            if ((typeof urlOrForm == 'object') && (urlOrForm.tagName == "FORM")){
              
              var originalForm = urlOrForm;
              
              url = originalForm.action;
              
              for (var i = includeFields.length-1;i >= 0;i -- ){
                
                var fields = ko.utils.getFormFields(originalForm,includeFields[i]);
                
                for (var j = fields.length-1;j >= 0;j -- ){
                  
                  params[fields[j].name] = fields[j].value;
                }
                
              }
              
            }
            
            data = ko.utils.unwrapObservable(data);
            
            var form = document.createElement("FORM");
            
            form.style.display = "none";
            
            form.action = url;
            
            form.method = "post";
            
            for (var key in data){
              
              var input = document.createElement("INPUT");
              
              input.name = key;
              
              input.value = ko.utils.stringifyJson(ko.utils.unwrapObservable(data[key]));
              
              form.appendChild(input);
            }
            
            for (var key in params){
              
              var input = document.createElement("INPUT");
              
              input.name = key;
              
              input.value = params[key];
              
              form.appendChild(input);
            }
            
            document.body.appendChild(form);
            
            options['submitter']?options['submitter'](form) : form.submit();
            
            setTimeout(function () {
              form.parentNode.removeChild(form);
            },0);
          }
        };
      }();
      
      ko.exportSymbol('ko.utils',ko.utils);
      
      ko.utils.arrayForEach([['arrayForEach',ko.utils.arrayForEach],['arrayFirst',ko.utils.arrayFirst],['arrayFilter',ko.utils.arrayFilter],['arrayGetDistinctValues',ko.utils.arrayGetDistinctValues],['arrayIndexOf',ko.utils.arrayIndexOf],['arrayMap',ko.utils.arrayMap],['arrayPushAll',ko.utils.arrayPushAll],['arrayRemoveItem',ko.utils.arrayRemoveItem],['extend',ko.utils.extend],['fieldsIncludedWithJsonPost',ko.utils.fieldsIncludedWithJsonPost],['getFormFields',ko.utils.getFormFields],['postJson',ko.utils.postJson],['parseJson',ko.utils.parseJson],['registerEventHandler',ko.utils.registerEventHandler],['stringifyJson',ko.utils.stringifyJson],['range',ko.utils.range],['toggleDomNodeCssClass',ko.utils.toggleDomNodeCssClass],['triggerEvent',ko.utils.triggerEvent],['unwrapObservable',ko.utils.unwrapObservable]],
      function (item) {
        ko.exportSymbol('ko.utils.'+item[0],item[1]);
      });
      
      !Function.prototype.bind && (Function.prototype.bind = function (object) {
        var originalFunction = this,
            args = [].slice.call(arguments),
            object = args.shift();
        return function () {
          return originalFunction.apply(object,args.concat([].slice.call(arguments)));
        };
      });
      
      ko.utils.domData = new function () {
        var uniqueId = 0,
            dataStoreKeyExpandoPropertyName = "__ko__"+(new Date).getTime(),
            dataStore = {};
        return  {
          get : function (node,key) {
            var allDataForNode = ko.utils.domData.getAll(node,false);
            return allDataForNode === undefined?undefined : allDataForNode[key];
          },
          set : function (node,key,value) {
            if (value === undefined){
              
              if (ko.utils.domData.getAll(node,false) === undefined){
                return ;
              }
              
            }
            
            var allDataForNode = ko.utils.domData.getAll(node,true);
            
            allDataForNode[key] = value;
          },
          getAll : function (node,createIfNotFound) {
            var dataStoreKey = node[dataStoreKeyExpandoPropertyName];
            
            var hasExistingDataStore = dataStoreKey && (dataStoreKey !== "null");
            
            if (!hasExistingDataStore){
              
              if (!createIfNotFound){
                return undefined;
              }
              
              dataStoreKey = node[dataStoreKeyExpandoPropertyName] = "ko"+uniqueId ++ ;
              
              dataStore[dataStoreKey] = {};
            }
            return dataStore[dataStoreKey];
          },
          clear : function (node) {
            var dataStoreKey = node[dataStoreKeyExpandoPropertyName];
            
            if (dataStoreKey){
              
              delete dataStore[dataStoreKey];
              
              node[dataStoreKeyExpandoPropertyName] = null;
            }
            
          }
        };
      }();
      
      ko.exportSymbol('ko.utils.domData',ko.utils.domData);
      
      ko.exportSymbol('ko.utils.domData.clear',ko.utils.domData.clear);
      
      ko.utils.domNodeDisposal = new function () {
        function cleanSingleNode(node) {
          var callbacks = getDisposeCallbacksCollection(node,false);
          
          if (callbacks){
            
            callbacks = callbacks.slice(0);
            
            for (var i = 0;i<callbacks.length;i ++ )callbacks[i](node);
          }
          
          ko.utils.domData.clear(node);
          
          (typeof jQuery == "function") && (typeof jQuery.cleanData == "function") && jQuery.cleanData([node]);
        }
        function destroyCallbacksCollection(node) {
          ko.utils.domData.set(node,domDataKey,undefined);
        }
        function getDisposeCallbacksCollection(node,createIfNotFound) {
          var allDisposeCallbacks = ko.utils.domData.get(node,domDataKey);
          
          if ((allDisposeCallbacks === undefined) && createIfNotFound){
            
            allDisposeCallbacks = [];
            
            ko.utils.domData.set(node,domDataKey,allDisposeCallbacks);
          }
          return allDisposeCallbacks;
        }
        var domDataKey = "__ko_domNodeDisposal__"+(new Date).getTime();
        return  {
          addDisposeCallback : function (node,callback) {
            if (typeof callback != "function"){
              throw new Error("Callback must be a function")
              
            }
            
            getDisposeCallbacksCollection(node,true).push(callback);
          },
          removeDisposeCallback : function (node,callback) {
            var callbacksCollection = getDisposeCallbacksCollection(node,false);
            
            if (callbacksCollection){
              
              ko.utils.arrayRemoveItem(callbacksCollection,callback);
              
              if (callbacksCollection.length == 0){
                
                destroyCallbacksCollection(node);
              }
              
            }
            
          },
          cleanNode : function (node) {
            if ((node.nodeType != 1) && (node.nodeType != 9)){
              return ;
            }
            
            cleanSingleNode(node);
            
            var descendants = [];
            
            ko.utils.arrayPushAll(descendants,node.getElementsByTagName("*"));
            
            for (var i = 0,j = descendants.length;i<j;i ++ ){
              
              cleanSingleNode(descendants[i]);
            }
            
          },
          removeNode : function (node) {
            ko.cleanNode(node);
            
            if (node.parentNode){
              
              node.parentNode.removeChild(node);
            }
            
          }
        };
      }();
      
      ko.cleanNode = ko.utils.domNodeDisposal.cleanNode;
      
      ko.removeNode = ko.utils.domNodeDisposal.removeNode;
      
      ko.exportSymbol('ko.cleanNode',ko.cleanNode);
      
      ko.exportSymbol('ko.removeNode',ko.removeNode);
      
      ko.exportSymbol('ko.utils.domNodeDisposal',ko.utils.domNodeDisposal);
      
      ko.exportSymbol('ko.utils.domNodeDisposal.addDisposeCallback',ko.utils.domNodeDisposal.addDisposeCallback);
      
      ko.exportSymbol('ko.utils.domNodeDisposal.removeDisposeCallback',ko.utils.domNodeDisposal.removeDisposeCallback);
      
      !function () {
        function jQueryHtmlParse(html) {
          var elems = jQuery.clean([html]);
          
          if (elems && elems[0]){
            
            var elem = elems[0];
            
            while (elem.parentNode && elem.parentNode.nodeType !== 11)elem = elem.parentNode;
            
            elem.parentNode && elem.parentNode.removeChild(elem);
          }
          return elems;
        }
        function simpleHtmlParse(html) {
          var tags = ko.utils.stringTrim(html).toLowerCase(),
              div = document.createElement("div"),
              wrap = tags.match(/^<(thead|tbody|tfoot)/) && [1,"<table>","</table>"] || !tags.indexOf("<tr") && [2,"<table><tbody>","</tbody></table>"] || (!tags.indexOf("<td") || !tags.indexOf("<th")) && [3,"<table><tbody><tr>","</tr></tbody></table>"] || [0,"",""],
              markup = "ignored<div>"+wrap[1]+html+wrap[2]+"</div>";
          
          typeof window.innerShiv == "function"?div.appendChild(window.innerShiv(markup)) : div.innerHTML = markup;
          
          while (wrap[0] -- )div = div.lastChild;
          return ko.utils.makeArray(div.lastChild.childNodes);
        }
        var leadingCommentRegex = /^(\s*)<!--(.*?)-->/;
        
        ko.utils.parseHtmlFragment = function (html) {
          return typeof jQuery != 'undefined'?jQueryHtmlParse(html) : simpleHtmlParse(html);
        };
        
        ko.utils.setHtml = function (node,html) {
          ko.utils.emptyDomNode(node);
          
          if ((html !== null) && (html !== undefined)){
            
            typeof html != 'string' && (html = html.toString());
            
            if (typeof jQuery != 'undefined')jQuery(node).html(html);
             else {
              
              var parsedNodes = ko.utils.parseHtmlFragment(html);
              
              for (var i = 0;i<parsedNodes.length;i ++ )node.appendChild(parsedNodes[i]);
            }
            
          }
          
        };
      }();
      
      ko.exportSymbol('ko.utils.parseHtmlFragment',ko.utils.parseHtmlFragment);
      
      ko.exportSymbol('ko.utils.setHtml',ko.utils.setHtml);
      
      ko.memoization = function () {
        function findMemoNodes(rootNode,appendToArray) {
          if (!rootNode)return ;
          
          if (rootNode.nodeType == 8){
            
            var memoId = ko.memoization.parseMemoText(rootNode.nodeValue);
            
            memoId != null && appendToArray.push( {
              domNode : rootNode,
              memoId : memoId
            });
          } else if (rootNode.nodeType == 1)for (var i = 0,childNodes = rootNode.childNodes,j = childNodes.length;i<j;i ++ )
          findMemoNodes(childNodes[i],appendToArray);
        }
        function generateRandomId() {
          return randomMax8HexChars()+randomMax8HexChars();
        }
        function randomMax8HexChars() {
          return (((1+Math.random())*0x00000000)|0).toString(16).substring(1);
        }
        var memos = {};
        return  {
          memoize : function (callback) {
            if (typeof callback != "function"){
              throw new Error("You can only pass a function to ko.memoization.memoize()")
              
            }
            
            var memoId = generateRandomId();
            
            memos[memoId] = callback;
            return "<!--[ko_memo:"+memoId+"]-->";
          },
          unmemoize : function (memoId,callbackParams) {
            var callback = memos[memoId];
            
            if (callback === undefined){
              throw new Error("Couldn't find any memo with ID "+memoId+". Perhaps it's already been unmemoized.")
              
            }
            
            try {
              
              callback.apply(null,callbackParams || []);
              return true;
            } finally {
              
              delete memos[memoId];
            }
            
          },
          unmemoizeDomNodeAndDescendants : function (domNode,extraCallbackParamsArray) {
            var memos = [];
            
            findMemoNodes(domNode,memos);
            
            for (var i = 0,j = memos.length;i<j;i ++ ){
              
              var node = memos[i].domNode;
              
              var combinedParams = [node];
              
              if (extraCallbackParamsArray){
                
                ko.utils.arrayPushAll(combinedParams,extraCallbackParamsArray);
              }
              
              ko.memoization.unmemoize(memos[i].memoId,combinedParams);
              
              node.nodeValue = "";
              
              if (node.parentNode){
                
                node.parentNode.removeChild(node);
              }
              
            }
            
          },
          parseMemoText : function (memoText) {
            var match = memoText.match(/^\[ko_memo\:(.*?)\]$/);
            return match?match[1] : null;
          }
        };
      }();
      
      ko.exportSymbol('ko.memoization',ko.memoization);
      
      ko.exportSymbol('ko.memoization.memoize',ko.memoization.memoize);
      
      ko.exportSymbol('ko.memoization.unmemoize',ko.memoization.unmemoize);
      
      ko.exportSymbol('ko.memoization.parseMemoText',ko.memoization.parseMemoText);
      
      ko.exportSymbol('ko.memoization.unmemoizeDomNodeAndDescendants',ko.memoization.unmemoizeDomNodeAndDescendants);
      
      ko.extenders =  {
        'throttle' : function (target,timeout) {
          target['throttleEvaluation'] = timeout;
          
          var writeTimeoutInstance = null;
          return ko.dependentObservable( {
            'read' : target,
            'write' : function (value) {
              clearTimeout(writeTimeoutInstance);
              
              writeTimeoutInstance = setTimeout(function () {
                target(value);
              },timeout);
            }
          });
        },
        'notify' : function (target,notifyWhen) {
          target["equalityComparer"] = notifyWhen == "always"?function () {
            return false;
          } : ko.observable["fn"]["equalityComparer"];
          return target;
        }
      };
      
      ko.exportSymbol('ko.extenders',ko.extenders);
      
      ko.subscription = function (callback,disposeCallback) {
        this.callback = callback;
        
        this.disposeCallback = disposeCallback;
        
        ko.exportProperty(this,'dispose',this.dispose);
      };
      
      ko.subscription.prototype.dispose = function () {
        this.isDisposed = true;
        
        this.disposeCallback();
      };
      
      ko.subscribable = function () {
        this._subscriptions = {};
        
        ko.utils.extend(this,ko.subscribable.fn);
        
        ko.exportProperty(this,'subscribe',this.subscribe);
        
        ko.exportProperty(this,'extend',this.extend);
        
        ko.exportProperty(this,'getSubscriptionsCount',this.getSubscriptionsCount);
      };
      
      var defaultEvent = "change";
      
      ko.subscribable.fn =  {
        subscribe : function (callback,callbackTarget,event) {
          event = event || defaultEvent;
          
          var boundCallback = callbackTarget?callback.bind(callbackTarget) : callback;
          
          var subscription = new ko.subscription(boundCallback,function () {
                ko.utils.arrayRemoveItem(this._subscriptions[event],subscription);
              }.bind(this));
          
          if (!this._subscriptions[event]){
            
            this._subscriptions[event] = [];
          }
          
          this._subscriptions[event].push(subscription);
          return subscription;
        },
        "notifySubscribers" : function (valueToNotify,event) {
          event = event || defaultEvent;
          
          if (this._subscriptions[event]){
            
            ko.utils.arrayForEach(this._subscriptions[event].slice(0),
            function (subscription) {
              if (subscription && (subscription.isDisposed !== true)){
                
                subscription.callback(valueToNotify);
              }
              
            });
          }
          
        },
        getSubscriptionsCount : function () {
          var total = 0;
          
          for (var eventName in this._subscriptions){
            
            if (this._subscriptions.hasOwnProperty(eventName)){
              
              total += this._subscriptions[eventName].length;
            }
            
          }
          return total;
        },
        extend : applyExtenders
      };
      
      ko.isSubscribable = function (instance) {
        return typeof instance.subscribe == "function" && typeof instance.notifySubscribers == "function";
      };
      
      ko.exportSymbol('ko.subscribable',ko.subscribable);
      
      ko.exportSymbol('ko.isSubscribable',ko.isSubscribable);
      
      ko.dependencyDetection = function () {
        var _frames = [];
        return  {
          begin : function (callback) {
            _frames.push( {
              callback : callback,
              distinctDependencies : []
            });
          },
          end : function () {
            _frames.pop();
          },
          registerDependency : function (subscribable) {
            if (!ko.isSubscribable(subscribable)){
              throw "Only subscribable things can act as dependencies"
              
            }
            
            if (_frames.length>0){
              
              var topFrame = _frames[_frames.length-1];
              
              if (ko.utils.arrayIndexOf(topFrame.distinctDependencies,subscribable) >= 0){
                return ;
              }
              
              topFrame.distinctDependencies.push(subscribable);
              
              topFrame.callback(subscribable);
            }
            
          }
        };
      }();
      
      var primitiveTypes =  {
            'undefined' : true,
            'boolean' : true,
            'number' : true,
            'string' : true
          };
      
      ko.observable = function (initialValue) {
        function observable() {
          if (arguments.length>0){
            
            if ((!observable.equalityComparer) || !observable.equalityComparer(_latestValue,arguments[0])){
              
              observable.valueWillMutate();
              
              _latestValue = arguments[0];
              
              observable.valueHasMutated();
            }
            return this;
          } else {
            
            ko.dependencyDetection.registerDependency(observable);
            return _latestValue;
          }
          
        }
        var _latestValue = initialValue;
        
        ko.subscribable.call(observable);
        
        observable.valueHasMutated = function () {
          observable.notifySubscribers(_latestValue);
        };
        
        observable.valueWillMutate = function () {
          observable.notifySubscribers(_latestValue,"beforeChange");
        };
        
        ko.utils.extend(observable,ko.observable.fn);
        
        ko.exportProperty(observable,"valueHasMutated",observable.valueHasMutated);
        
        ko.exportProperty(observable,"valueWillMutate",observable.valueWillMutate);
        return observable;
      };
      
      ko.observable.fn =  {
        __ko_proto__ : ko.observable,
        "equalityComparer" : function valuesArePrimitiveAndEqual(a,b) {
          var oldValueIsPrimitive = (a === null) || (typeof (a) in primitiveTypes);
          return oldValueIsPrimitive?(a === b) : false;
        }
      };
      
      ko.isObservable = function (instance) {
        if ((instance === null) || (instance === undefined) || (instance.__ko_proto__ === undefined))return false;
        
        if (instance.__ko_proto__ === ko.observable)return true;
        return ko.isObservable(instance.__ko_proto__);
      };
      
      ko.isWriteableObservable = function (instance) {
        if ((typeof instance == "function") && instance.__ko_proto__ === ko.observable)return true;
        
        if ((typeof instance == "function") && (instance.__ko_proto__ === ko.dependentObservable) && (instance.hasWriteFunction))return true;
        return false;
      };
      
      ko.exportSymbol('ko.observable',ko.observable);
      
      ko.exportSymbol('ko.isObservable',ko.isObservable);
      
      ko.exportSymbol('ko.isWriteableObservable',ko.isWriteableObservable);
      
      ko.observableArray = function (initialValues) {
        arguments.length == 0 && (initialValues = []);
        
        if ((initialValues !== null) && (initialValues !== undefined) && !('length' in initialValues))throw new Error("The argument passed when initializing an observable array must be an array, or null, or undefined.")
        
        var result = new ko.observable(initialValues);
        
        ko.utils.extend(result,ko.observableArray.fn);
        
        ko.exportProperty(result,"remove",result.remove);
        
        ko.exportProperty(result,"removeAll",result.removeAll);
        
        ko.exportProperty(result,"destroy",result.destroy);
        
        ko.exportProperty(result,"destroyAll",result.destroyAll);
        
        ko.exportProperty(result,"indexOf",result.indexOf);
        
        ko.exportProperty(result,"replace",result.replace);
        return result;
      };
      
      ko.observableArray.fn =  {
        remove : function (valueOrPredicate) {
          var underlyingArray = this();
          
          var removedValues = [];
          
          var predicate = typeof valueOrPredicate == "function"?valueOrPredicate : function (value) {
                return value === valueOrPredicate;
              };
          
          for (var i = 0;i<underlyingArray.length;i ++ ){
            
            var value = underlyingArray[i];
            
            if (predicate(value)){
              
              if (removedValues.length === 0){
                
                this.valueWillMutate();
              }
              
              removedValues.push(value);
              
              underlyingArray.splice(i,1);
              
              i -- ;
            }
            
          }
          
          if (removedValues.length){
            
            this.valueHasMutated();
          }
          return removedValues;
        },
        removeAll : function (arrayOfValues) {
          if (arrayOfValues === undefined){
            
            var underlyingArray = this();
            
            var allValues = underlyingArray.slice(0);
            
            this.valueWillMutate();
            
            underlyingArray.splice(0,underlyingArray.length);
            
            this.valueHasMutated();
            return allValues;
          }
          
          if (!arrayOfValues){
            return [];
          }
          return this.remove(function (value) {
            return ko.utils.arrayIndexOf(arrayOfValues,value) >= 0;
          });
        },
        destroy : function (valueOrPredicate) {
          var underlyingArray = this();
          
          var predicate = typeof valueOrPredicate == "function"?valueOrPredicate : function (value) {
                return value === valueOrPredicate;
              };
          
          this.valueWillMutate();
          
          for (var i = underlyingArray.length-1;i >= 0;i -- ){
            
            var value = underlyingArray[i];
            
            if (predicate(value)){
              
              underlyingArray[i]["_destroy"] = true;
            }
            
          }
          
          this.valueHasMutated();
        },
        destroyAll : function (arrayOfValues) {
          if (arrayOfValues === undefined){
            return this.destroy(function () {
              return true;
            });
          }
          
          if (!arrayOfValues){
            return [];
          }
          return this.destroy(function (value) {
            return ko.utils.arrayIndexOf(arrayOfValues,value) >= 0;
          });
        },
        indexOf : function (item) {
          var underlyingArray = this();
          return ko.utils.arrayIndexOf(underlyingArray,item);
        },
        replace : function (oldItem,newItem) {
          var index = this.indexOf(oldItem);
          
          if (index >= 0){
            
            this.valueWillMutate();
            
            this()[index] = newItem;
            
            this.valueHasMutated();
          }
          
        }
      };
      
      ko.utils.arrayForEach(["pop","push","reverse","shift","sort","splice","unshift"],
      function (methodName) {
        ko.observableArray.fn[methodName] = function () {
          var underlyingArray = this();
          
          this.valueWillMutate();
          
          var methodCallResult = underlyingArray[methodName].apply(underlyingArray,arguments);
          
          this.valueHasMutated();
          return methodCallResult;
        };
      });
      
      ko.utils.arrayForEach(["slice"],
      function (methodName) {
        ko.observableArray.fn[methodName] = function () {
          var underlyingArray = this();
          return underlyingArray[methodName].apply(underlyingArray,arguments);
        };
      });
      
      ko.exportSymbol('ko.observableArray',ko.observableArray);
      
      ko.dependentObservable = function (evaluatorFunctionOrOptions,evaluatorFunctionTarget,options) {
        function dependentObservable() {
          if (arguments.length>0)if (typeof options.write === "function"){
            
            var valueForThis = options.owner || evaluatorFunctionTarget;
            
            options.write.apply(valueForThis,arguments);
          } else throw "Cannot write a value to a dependentObservable unless you specify a 'write' option. If you wish to read the current value, don't pass any parameters."
           else {
            
            !_hasBeenEvaluated && evaluateImmediate();
            
            ko.dependencyDetection.registerDependency(dependentObservable);
            return _latestValue;
          }
          
        }
        function evaluateImmediate() {
          if ((_hasBeenEvaluated) && typeof options.disposeWhen == "function")if (options.disposeWhen()){
            
            dependentObservable.dispose();
            return ;
          }
          
          try {
            
            disposeAllSubscriptionsToDependencies();
            
            ko.dependencyDetection.begin(function (subscribable) {
              _subscriptionsToDependencies.push(subscribable.subscribe(evaluatePossiblyAsync));
            });
            
            var valueForThis = options.owner || evaluatorFunctionTarget;
            
            var newValue = options.read.call(valueForThis);
            
            dependentObservable.notifySubscribers(_latestValue,"beforeChange");
            
            _latestValue = newValue;
          } finally {
            
            ko.dependencyDetection.end();
          }
          
          dependentObservable.notifySubscribers(_latestValue);
          
          _hasBeenEvaluated = true;
        }
        function evaluatePossiblyAsync() {
          var throttleEvaluationTimeout = dependentObservable.throttleEvaluation;
          
          if (throttleEvaluationTimeout && throttleEvaluationTimeout >= 0){
            
            clearTimeout(evaluationTimeoutInstance);
            
            evaluationTimeoutInstance = setTimeout(evaluateImmediate,throttleEvaluationTimeout);
          } else evaluateImmediate();
        }
        function disposeAllSubscriptionsToDependencies() {
          ko.utils.arrayForEach(_subscriptionsToDependencies,
          function (subscription) {
            subscription.dispose();
          });
          
          _subscriptionsToDependencies = [];
        }
        var _latestValue,
            _hasBeenEvaluated = false,
            options = prepareOptions(evaluatorFunctionOrOptions,evaluatorFunctionTarget,options),
            disposeWhenNodeIsRemoved = (typeof options.disposeWhenNodeIsRemoved == "object")?options.disposeWhenNodeIsRemoved : null,
            disposeWhenNodeIsRemovedCallback = null;
        
        if (disposeWhenNodeIsRemoved){
          
          disposeWhenNodeIsRemovedCallback = function () {
            dependentObservable.dispose();
          };
          
          ko.utils.domNodeDisposal.addDisposeCallback(disposeWhenNodeIsRemoved,disposeWhenNodeIsRemovedCallback);
          
          var existingDisposeWhenFunction = options.disposeWhen;
          
          options.disposeWhen = function () {
            return (!ko.utils.domNodeIsAttachedToDocument(disposeWhenNodeIsRemoved)) || ((typeof existingDisposeWhenFunction == "function") && existingDisposeWhenFunction());
          };
        }
        
        var _subscriptionsToDependencies = [];
        
        var evaluationTimeoutInstance = null;
        
        dependentObservable.getDependenciesCount = function () {
          return _subscriptionsToDependencies.length;
        };
        
        dependentObservable.hasWriteFunction = typeof options.write === "function";
        
        dependentObservable.dispose = function () {
          disposeWhenNodeIsRemoved && ko.utils.domNodeDisposal.removeDisposeCallback(disposeWhenNodeIsRemoved,disposeWhenNodeIsRemovedCallback);
          
          disposeAllSubscriptionsToDependencies();
        };
        
        ko.subscribable.call(dependentObservable);
        
        ko.utils.extend(dependentObservable,ko.dependentObservable.fn);
        
        options.deferEvaluation !== true && evaluateImmediate();
        
        ko.exportProperty(dependentObservable,'dispose',dependentObservable.dispose);
        
        ko.exportProperty(dependentObservable,'getDependenciesCount',dependentObservable.getDependenciesCount);
        return dependentObservable;
      };
      
      ko.dependentObservable.fn =  {
        __ko_proto__ : ko.dependentObservable
      };
      
      ko.dependentObservable.__ko_proto__ = ko.observable;
      
      ko.exportSymbol('ko.dependentObservable',ko.dependentObservable);
      
      ko.exportSymbol('ko.computed',ko.dependentObservable);
      
      !function () {
        function objectLookup() {
          var keys = [],
              values = [];
          
          this.save = function (key,value) {
            var existingIndex = ko.utils.arrayIndexOf(keys,key);
            
            if (existingIndex >= 0)values[existingIndex] = value;
             else {
              
              keys.push(key);
              
              values.push(value);
            }
            
          };
          
          this.get = function (key) {
            var existingIndex = ko.utils.arrayIndexOf(keys,key);
            return (existingIndex >= 0)?values[existingIndex] : undefined;
          };
        }
        function visitPropertiesOrArrayEntries(rootObject,visitorCallback) {
          if (rootObject instanceof Array)for (var i = 0;i<rootObject.length;i ++ )
          visitorCallback(i);
           else for (var propertyName in rootObject)
          visitorCallback(propertyName);
        }
        function mapJsObjectGraph(rootObject,mapInputCallback,visitedObjects) {
          visitedObjects = visitedObjects || new objectLookup();
          
          rootObject = mapInputCallback(rootObject);
          
          var canHaveProperties = (typeof rootObject == "object") && (rootObject !== null) && (rootObject !== undefined) && (!(rootObject instanceof Date));
          
          if (!canHaveProperties)return rootObject;
          
          var outputProperties = rootObject instanceof Array?[] : {};
          
          visitedObjects.save(rootObject,outputProperties);
          
          visitPropertiesOrArrayEntries(rootObject,
          function (indexer) {
            var propertyValue = mapInputCallback(rootObject[indexer]);
            
            switch (typeof propertyValue) {
              case "boolean" :
              case "number" :
              case "string" :
              case "function" :
                
                outputProperties[indexer] = propertyValue;
                break;
              case "object" :
              case "undefined" :
                
                var previouslyMappedValue = visitedObjects.get(propertyValue);
                
                outputProperties[indexer] = (previouslyMappedValue !== undefined)?previouslyMappedValue : mapJsObjectGraph(propertyValue,mapInputCallback,visitedObjects);
                break;
                
            }
            
          });
          return outputProperties;
        }
        var maxNestedObservableDepth = 10;
        
        ko.toJS = function (rootObject) {
          if (arguments.length == 0)throw new Error("When calling ko.toJS, pass the object you want to convert.")
          return mapJsObjectGraph(rootObject,
          function (valueToMap) {
            for (var i = 0;ko.isObservable(valueToMap) && (i<maxNestedObservableDepth);i ++ )
            valueToMap = valueToMap();
            return valueToMap;
          });
        };
        
        ko.toJSON = function (rootObject) {
          var plainJavaScriptObject = ko.toJS(rootObject);
          return ko.utils.stringifyJson(plainJavaScriptObject);
        };
      }();
      
      ko.exportSymbol('ko.toJS',ko.toJS);
      
      ko.exportSymbol('ko.toJSON',ko.toJSON);
      
      !function () {
        var hasDomDataExpandoProperty = '__ko__hasDomDataOptionValue__';
        
        ko.selectExtensions =  {
          readValue : function (element) {
            if (element.tagName == 'OPTION'){
              
              if (element[hasDomDataExpandoProperty] === true){
                return ko.utils.domData.get(element,ko.bindingHandlers.options.optionValueDomDataKey);
              }
              return element.getAttribute("value");
            } else if (element.tagName == 'SELECT'){
              return element.selectedIndex >= 0?ko.selectExtensions.readValue(element.options[element.selectedIndex]) : undefined;
            } else return element.value;
          },
          writeValue : function (element,value) {
            if (element.tagName == 'OPTION'){
              
              switch (typeof value) {
                case "string" :
                  
                  ko.utils.domData.set(element,ko.bindingHandlers.options.optionValueDomDataKey,undefined);
                  
                  if (hasDomDataExpandoProperty in element){
                    
                    delete element[hasDomDataExpandoProperty];
                  }
                  
                  element.value = value;
                  break;
                default :
                  
                  ko.utils.domData.set(element,ko.bindingHandlers.options.optionValueDomDataKey,value);
                  
                  element[hasDomDataExpandoProperty] = true;
                  
                  element.value = typeof value === "number"?value : "";
                  break;
                  
              }
              
            } else if (element.tagName == 'SELECT'){
              
              for (var i = element.options.length-1;i >= 0;i -- ){
                if (ko.selectExtensions.readValue(element.options[i]) == value){
                  
                  element.selectedIndex = i;
                  break;
                }
                
              }
              
            } else {
              if ((value === null) || (value === undefined)){
                
                value = "";
              }
              
              element.value = value;
            }
            
          }
        };
      }();
      
      ko.exportSymbol('ko.selectExtensions',ko.selectExtensions);
      
      ko.exportSymbol('ko.selectExtensions.readValue',ko.selectExtensions.readValue);
      
      ko.exportSymbol('ko.selectExtensions.writeValue',ko.selectExtensions.writeValue);
      
      ko.jsonExpressionRewriting = function () {
        function ensureQuoted(key) {
          var trimmedKey = ko.utils.stringTrim(key);
          
          switch (trimmedKey.length && trimmedKey.charAt(0)) {
            case "'" :
            case '"' :
              return key;
            default :
              return "'"+trimmedKey+"'";
              
          }
          
        }
        function isWriteableValue(expression) {
          if (ko.utils.arrayIndexOf(javaScriptReservedWords,ko.utils.stringTrim(expression).toLowerCase()) >= 0)return false;
          return expression.match(javaScriptAssignmentTarget) !== null;
        }
        function restoreTokens(string,tokens) {
          var prevValue = null;
          
          while (string != prevValue){
            
            prevValue = string;
            
            string = string.replace(restoreCapturedTokensRegex,
            function (match,tokenIndex) {
              return tokens[tokenIndex];
            });
          }
          return string;
        }
        var restoreCapturedTokensRegex = /\@ko_token_(\d+)\@/g,
            javaScriptAssignmentTarget = /^[\_$a-z][\_$a-z0-9]*(\[.*?\])*(\.[\_$a-z][\_$a-z0-9]*(\[.*?\])*)*$/i,
            javaScriptReservedWords = ["true","false"];
        return  {
          bindingRewriteValidators : [],
          parseObjectLiteral : function (objectLiteralString) {
            var str = ko.utils.stringTrim(objectLiteralString);
            
            if (str.length<3){
              return [];
            }
            
            if (str.charAt(0) === "{"){
              
              str = str.substring(1,str.length-1);
            }
            
            var tokens = [];
            
            var tokenStart = null,
                tokenEndChar;
            
            for (var position = 0;position<str.length;position ++ ){
              
              var c = str.charAt(position);
              
              if (tokenStart === null){
                
                switch (c) {
                  case '"' :
                  case "'" :
                  case "/" :
                    
                    tokenStart = position;
                    
                    tokenEndChar = c;
                    break;
                    
                }
                
              } else if ((c == tokenEndChar) && (str.charAt(position-1) !== "\\")){
                
                var token = str.substring(tokenStart,position+1);
                
                tokens.push(token);
                
                var replacement = "@ko_token_"+(tokens.length-1)+"@";
                
                str = str.substring(0,tokenStart)+replacement+str.substring(position+1);
                
                position -= (token.length-replacement.length);
                
                tokenStart = null;
              }
              
            }
            
            tokenStart = null;
            
            tokenEndChar = null;
            
            var tokenDepth = 0,
                tokenStartChar = null;
            
            for (var position = 0;position<str.length;position ++ ){
              
              var c = str.charAt(position);
              
              if (tokenStart === null){
                
                switch (c) {
                  case "{" :
                    
                    tokenStart = position;
                    
                    tokenStartChar = c;
                    
                    tokenEndChar = "}";
                    break;
                  case "(" :
                    
                    tokenStart = position;
                    
                    tokenStartChar = c;
                    
                    tokenEndChar = ")";
                    break;
                  case "[" :
                    
                    tokenStart = position;
                    
                    tokenStartChar = c;
                    
                    tokenEndChar = "]";
                    break;
                    
                }
                
              }
              
              if (c === tokenStartChar){
                
                tokenDepth ++ ;
              } else if (c === tokenEndChar){
                
                tokenDepth -- ;
                if (tokenDepth === 0){
                  
                  var token = str.substring(tokenStart,position+1);
                  
                  tokens.push(token);
                  
                  var replacement = "@ko_token_"+(tokens.length-1)+"@";
                  
                  str = str.substring(0,tokenStart)+replacement+str.substring(position+1);
                  
                  position -= (token.length-replacement.length);
                  
                  tokenStart = null;
                }
                
              }
              
            }
            
            var result = [];
            
            var keyValuePairs = str.split(",");
            
            for (var i = 0,j = keyValuePairs.length;i<j;i ++ ){
              
              var pair = keyValuePairs[i];
              
              var colonPos = pair.indexOf(":");
              
              if ((colonPos>0) && (colonPos<pair.length-1)){
                
                var key = pair.substring(0,colonPos);
                
                var value = pair.substring(colonPos+1);
                
                result.push( {
                  'key' : restoreTokens(key,tokens),
                  'value' : restoreTokens(value,tokens)
                });
              } else {
                
                result.push( {
                  'unknown' : restoreTokens(pair,tokens)
                });
              }
              
            }
            return result;
          },
          insertPropertyAccessorsIntoJson : function (objectLiteralStringOrKeyValueArray) {
            var keyValueArray = typeof objectLiteralStringOrKeyValueArray === "string"?ko.jsonExpressionRewriting.parseObjectLiteral(objectLiteralStringOrKeyValueArray) : objectLiteralStringOrKeyValueArray;
            
            var resultStrings = [],
                propertyAccessorResultStrings = [];
            
            var keyValueEntry;
            
            for (var i = 0;keyValueEntry = keyValueArray[i];i ++ ){
              
              if (resultStrings.length>0){
                
                resultStrings.push(",");
              }
              
              if (keyValueEntry['key']){
                
                var quotedKey = ensureQuoted(keyValueEntry['key']),
                    val = keyValueEntry['value'];
                
                resultStrings.push(quotedKey);
                
                resultStrings.push(":");
                
                resultStrings.push(val);
                
                if (isWriteableValue(ko.utils.stringTrim(val))){
                  
                  if (propertyAccessorResultStrings.length>0){
                    
                    propertyAccessorResultStrings.push(", ");
                  }
                  
                  propertyAccessorResultStrings.push(quotedKey+" : function(__ko_value) { "+val+" = __ko_value; }");
                }
                
              } else if (keyValueEntry['unknown']){
                
                resultStrings.push(keyValueEntry['unknown']);
              }
              
            }
            
            var combinedResult = resultStrings.join("");
            
            if (propertyAccessorResultStrings.length>0){
              
              var allPropertyAccessors = propertyAccessorResultStrings.join("");
              
              combinedResult = combinedResult+", '_ko_property_writers' : { "+allPropertyAccessors+" } ";
            }
            return combinedResult;
          },
          keyValueArrayContainsKey : function (keyValueArray,key) {
            for (var i = 0;i<keyValueArray.length;i ++ ){
              
              if (ko.utils.stringTrim(keyValueArray[i]['key']) == key){
                return true;
              }
              
            }
            return false;
          }
        };
      }();
      
      ko.exportSymbol('ko.jsonExpressionRewriting',ko.jsonExpressionRewriting);
      
      ko.exportSymbol('ko.jsonExpressionRewriting.bindingRewriteValidators',ko.jsonExpressionRewriting.bindingRewriteValidators);
      
      ko.exportSymbol('ko.jsonExpressionRewriting.parseObjectLiteral',ko.jsonExpressionRewriting.parseObjectLiteral);
      
      ko.exportSymbol('ko.jsonExpressionRewriting.insertPropertyAccessorsIntoJson',ko.jsonExpressionRewriting.insertPropertyAccessorsIntoJson);
      
      !function () {
        function getUnbalancedChildTags(node) {
          var childNode = node.firstChild,
              captureRemaining = null;
          
          if (childNode){
            
            do if (captureRemaining)captureRemaining.push(childNode);
             else if (isStartComment(childNode)){
              
              var matchingEndComment = getMatchingEndComment(childNode,true);
              
              matchingEndComment?childNode = matchingEndComment : captureRemaining = [childNode];
            } else isEndComment(childNode) && (captureRemaining = [childNode]);
            while (childNode = childNode.nextSibling);
          }
          return captureRemaining;
        }
        function nodeArrayToText(nodeArray,cleanNodes) {
          var texts = [];
          
          for (var i = 0,j = nodeArray.length;i<j;i ++ ){
            
            cleanNodes && ko.utils.domNodeDisposal.cleanNode(nodeArray[i]);
            
            texts.push(ko.utils.outerHTML(nodeArray[i]));
          }
          return ''.concat.apply("",texts);
        }
        function getMatchingEndComment(startComment,allowUnbalanced) {
          var allVirtualChildren = getVirtualChildren(startComment,allowUnbalanced);
          
          if (allVirtualChildren){
            
            if (allVirtualChildren.length>0)return allVirtualChildren[allVirtualChildren.length-1].nextSibling;
            return startComment.nextSibling;
          } else return null;
        }
        function getVirtualChildren(startComment,allowUnbalanced) {
          var currentNode = startComment,
              depth = 1,
              children = [];
          
          while (currentNode = currentNode.nextSibling){
            
            if (isEndComment(currentNode)){
              
              depth -- ;
              
              if (depth === 0)return children;
            }
            
            children.push(currentNode);
            
            isStartComment(currentNode) && depth ++ ;
          }
          
          if (!allowUnbalanced)throw new Error("Cannot find closing comment tag to match: "+startComment.nodeValue)
          return null;
        }
        function isEndComment(node) {
          return (node.nodeType == 8) && (commentNodesHaveTextProperty?node.text : node.nodeValue).match(endCommentRegex);
        }
        function isStartComment(node) {
          return (node.nodeType == 8) && (commentNodesHaveTextProperty?node.text : node.nodeValue).match(startCommentRegex);
        }
        var commentNodesHaveTextProperty = document.createComment("test").text === "<!--test-->",
            startCommentRegex = commentNodesHaveTextProperty?/^<!--\s*ko\s+(.*\:.*)\s*-->$/ : /^\s*ko\s+(.*\:.*)\s*$/,
            endCommentRegex = commentNodesHaveTextProperty?/^<!--\s*\/ko\s*-->$/ : /^\s*\/ko\s*$/,
            htmlTagsWithOptionallyClosingChildren =  {
              'ul' : true,
              'ol' : true
            };
        
        ko.virtualElements =  {
          allowedBindings : {},
          childNodes : function (node) {
            return isStartComment(node)?getVirtualChildren(node) : node.childNodes;
          },
          emptyNode : function (node) {
            if (!isStartComment(node)){
              
              ko.utils.emptyDomNode(node);
            } else {
              
              var virtualChildren = ko.virtualElements.childNodes(node);
              
              for (var i = 0,j = virtualChildren.length;i<j;i ++ ){
                
                ko.removeNode(virtualChildren[i]);
              }
              
            }
            
          },
          setDomNodeChildren : function (node,childNodes) {
            if (!isStartComment(node)){
              
              ko.utils.setDomNodeChildren(node,childNodes);
            } else {
              
              ko.virtualElements.emptyNode(node);
              
              var endCommentNode = node.nextSibling;
              
              for (var i = 0,j = childNodes.length;i<j;i ++ ){
                
                endCommentNode.parentNode.insertBefore(childNodes[i],endCommentNode);
              }
              
            }
            
          },
          prepend : function (containerNode,nodeToPrepend) {
            if (!isStartComment(containerNode)){
              
              if (containerNode.firstChild){
                
                containerNode.insertBefore(nodeToPrepend,containerNode.firstChild);
              } else containerNode.appendChild(nodeToPrepend);
            } else {
              
              containerNode.parentNode.insertBefore(nodeToPrepend,containerNode.nextSibling);
            }
            
          },
          insertAfter : function (containerNode,nodeToInsert,insertAfterNode) {
            if (!isStartComment(containerNode)){
              
              if (insertAfterNode.nextSibling){
                
                containerNode.insertBefore(nodeToInsert,insertAfterNode.nextSibling);
              } else containerNode.appendChild(nodeToInsert);
            } else {
              
              containerNode.parentNode.insertBefore(nodeToInsert,insertAfterNode.nextSibling);
            }
            
          },
          nextSibling : function (node) {
            if (!isStartComment(node)){
              
              if (node.nextSibling && isEndComment(node.nextSibling)){
                return undefined;
              }
              return node.nextSibling;
            } else {
              return getMatchingEndComment(node).nextSibling;
            }
            
          },
          virtualNodeBindingValue : function (node) {
            var regexMatch = isStartComment(node);
            return regexMatch?regexMatch[1] : null;
          },
          extractAnonymousTemplateIfVirtualElement : function (node) {
            if (ko.virtualElements.virtualNodeBindingValue(node)){
              
              var virtualChildren = ko.virtualElements.childNodes(node);
              
              var anonymousTemplateText = nodeArrayToText(virtualChildren,true);
              
              ko.virtualElements.emptyNode(node);
              
              new ko.templateSources.anonymousTemplate(node).text(anonymousTemplateText);
            }
            
          },
          normaliseVirtualElementDomStructure : function (elementVerified) {
            if (!htmlTagsWithOptionallyClosingChildren[elementVerified.tagName.toLowerCase()]){
              return ;
            }
            
            var childNode = elementVerified.firstChild;
            
            if (childNode){
              
              do {
                
                if (childNode.nodeType === 1){
                  
                  var unbalancedTags = getUnbalancedChildTags(childNode);
                  
                  if (unbalancedTags){
                    
                    var nodeToInsertBefore = childNode.nextSibling;
                    
                    for (var i = 0;i<unbalancedTags.length;i ++ ){
                      
                      if (nodeToInsertBefore){
                        
                        elementVerified.insertBefore(unbalancedTags[i],nodeToInsertBefore);
                      } else elementVerified.appendChild(unbalancedTags[i]);
                    }
                    
                  }
                  
                }
                
              }while (childNode = childNode.nextSibling);
            }
            
          }
        };
      }();
      
      !function () {
        var defaultBindingAttributeName = "data-bind";
        
        ko.bindingProvider = function (){};
        
        ko.utils.extend(ko.bindingProvider.prototype, {
          'nodeHasBindings' : function (node) {
            switch (node.nodeType) {
              case 1 :
                return node.getAttribute(defaultBindingAttributeName) != null;
              case 8 :
                return ko.virtualElements.virtualNodeBindingValue(node) != null;
              default :
                return false;
                
            }
            
          },
          'getBindings' : function (node,bindingContext) {
            var bindingsString = this['getBindingsString'](node,bindingContext);
            return bindingsString?this['parseBindingsString'](bindingsString,bindingContext) : null;
          },
          'getBindingsString' : function (node,bindingContext) {
            switch (node.nodeType) {
              case 1 :
                return node.getAttribute(defaultBindingAttributeName);
              case 8 :
                return ko.virtualElements.virtualNodeBindingValue(node);
              default :
                return null;
                
            }
            
          },
          'parseBindingsString' : function (bindingsString,bindingContext) {
            try {
              
              var viewModel = bindingContext['$data'];
              
              var rewrittenBindings = " { "+ko.jsonExpressionRewriting.insertPropertyAccessorsIntoJson(bindingsString)+" } ";
              return ko.utils.evalWithinScope(rewrittenBindings,viewModel === null?window : viewModel,bindingContext);
            } catch(ex){
              throw new Error("Unable to parse bindings.\nMessage: "+ex+";\nBindings value: "+bindingsString)
              
            }
            
          }
        });
        
        ko.bindingProvider.instance = new ko.bindingProvider();
      }();
      
      ko.exportSymbol('ko.bindingProvider',ko.bindingProvider);
      
      !function () {
        function applyBindingsToNodeInternal(node,bindings,viewModelOrBindingContext,isRootNodeForBindingContext) {
          function parsedBindingsAccessor() {
            return parsedBindings;
          }
          function makeValueAccessor(bindingKey) {
            return function () {
              return parsedBindings[bindingKey];
            };
          }
          var initPhase = 0;
          
          ko.virtualElements.extractAnonymousTemplateIfVirtualElement(node);
          
          var parsedBindings;
          
          var bindingHandlerThatControlsDescendantBindings;
          
          new ko.dependentObservable(function () {
            var bindingContextInstance = viewModelOrBindingContext && (viewModelOrBindingContext instanceof ko.bindingContext)?viewModelOrBindingContext : new ko.bindingContext(ko.utils.unwrapObservable(viewModelOrBindingContext)),
                viewModel = bindingContextInstance.$data;
            
            isRootNodeForBindingContext && ko.storedBindingContextForNode(node,bindingContextInstance);
            
            var evaluatedBindings = (typeof bindings == "function")?bindings() : bindings;
            
            parsedBindings = evaluatedBindings || ko.bindingProvider.instance.getBindings(node,bindingContextInstance);
            
            if (parsedBindings){
              
              if (initPhase === 0){
                
                initPhase = 1;
                
                for (var bindingKey in parsedBindings){
                  
                  var binding = ko.bindingHandlers[bindingKey];
                  
                  binding && node.nodeType === 8 && validateThatBindingIsAllowedForVirtualElements(bindingKey);
                  
                  if (binding && typeof binding.init == "function"){
                    
                    var handlerInitFn = binding.init;
                    
                    var initResult = handlerInitFn(node,makeValueAccessor(bindingKey),parsedBindingsAccessor,viewModel,bindingContextInstance);
                    
                    if (initResult && initResult.controlsDescendantBindings){
                      
                      if (bindingHandlerThatControlsDescendantBindings !== undefined)throw new Error("Multiple bindings ("+bindingHandlerThatControlsDescendantBindings+" and "+bindingKey+") are trying to control descendant bindings of the same element. You cannot use these bindings together on the same element.")
                      
                      bindingHandlerThatControlsDescendantBindings = bindingKey;
                    }
                    
                  }
                  
                }
                
                initPhase = 2;
              }
              
              if (initPhase === 2)for (var bindingKey in parsedBindings){
                
                var binding = ko.bindingHandlers[bindingKey];
                
                if (binding && typeof binding.update == "function"){
                  
                  var handlerUpdateFn = binding.update;
                  
                  handlerUpdateFn(node,makeValueAccessor(bindingKey),parsedBindingsAccessor,viewModel,bindingContextInstance);
                }
                
              }
              
            }
            
          },null, {
            'disposeWhenNodeIsRemoved' : node
          });
          return  {
            shouldBindDescendants : bindingHandlerThatControlsDescendantBindings === undefined
          };
        }
        function applyBindingsToNodeAndDescendantsInternal(viewModel,nodeVerified,isRootNodeForBindingContext) {
          var shouldBindDescendants = true,
              isElement = (nodeVerified.nodeType == 1);
          
          isElement && ko.virtualElements.normaliseVirtualElementDomStructure(nodeVerified);
          
          var shouldApplyBindings = (isElement && isRootNodeForBindingContext) || ko.bindingProvider.instance.nodeHasBindings(nodeVerified);
          
          shouldApplyBindings && (shouldBindDescendants = applyBindingsToNodeInternal(nodeVerified,null,viewModel,isRootNodeForBindingContext).shouldBindDescendants);
          
          isElement && shouldBindDescendants && applyBindingsToDescendantsInternal(viewModel,nodeVerified);
        }
        function applyBindingsToDescendantsInternal(viewModel,elementVerified) {
          var currentChild,
              nextInQueue = elementVerified.childNodes[0];
          
          while (currentChild = nextInQueue){
            
            nextInQueue = ko.virtualElements.nextSibling(currentChild);
            
            applyBindingsToNodeAndDescendantsInternal(viewModel,currentChild,false);
          }
          
        }
        function validateThatBindingIsAllowedForVirtualElements(bindingName) {
          var validator = ko.virtualElements.allowedBindings[bindingName];
          
          if (!validator)throw new Error("The binding '"+bindingName+"' cannot be used with virtual elements")
          
        }
        ko.bindingHandlers = {};
        
        ko.bindingContext = function (dataItem,parentBindingContext) {
          this.$data = dataItem;
          
          if (parentBindingContext){
            
            this.$parent = parentBindingContext.$data;
            
            this.$parents = (parentBindingContext.$parents || []).slice(0);
            
            this.$parents.unshift(this.$parent);
            
            this.$root = parentBindingContext.$root;
          } else {
            
            this.$parents = [];
            
            this.$root = dataItem;
          }
          
        };
        
        ko.bindingContext.prototype.createChildContext = function (dataItem) {
          return new ko.bindingContext(dataItem,this);
        };
        
        var storedBindingContextDomDataKey = "__ko_bindingContext__";
        
        ko.storedBindingContextForNode = function (node,bindingContext) {
          if (arguments.length == 2)ko.utils.domData.set(node,storedBindingContextDomDataKey,bindingContext);
           else return ko.utils.domData.get(node,storedBindingContextDomDataKey);
        };
        
        ko.applyBindingsToNode = function (node,bindings,viewModel) {
          node.nodeType === 1 && ko.virtualElements.normaliseVirtualElementDomStructure(node);
          return applyBindingsToNodeInternal(node,bindings,viewModel,true);
        };
        
        ko.applyBindingsToDescendants = function (viewModel,rootNode) {
          rootNode.nodeType === 1 && applyBindingsToDescendantsInternal(viewModel,rootNode);
        };
        
        ko.applyBindings = function (viewModel,rootNode) {
          if (rootNode && (rootNode.nodeType !== 1) && (rootNode.nodeType !== 8))throw new Error("ko.applyBindings: first parameter should be your view model; second parameter should be a DOM node")
          
          rootNode = rootNode || window.document.body;
          
          applyBindingsToNodeAndDescendantsInternal(viewModel,rootNode,true);
        };
        
        ko.contextFor = function (node) {
          switch (node.nodeType) {
            case 1 :
            case 8 :
              
              var context = ko.storedBindingContextForNode(node);
              
              if (context){
                return context;
              }
              
              if (node.parentNode){
                return ko.contextFor(node.parentNode);
              }
              break;
              
          }
          return undefined;
        };
        
        ko.dataFor = function (node) {
          var context = ko.contextFor(node);
          return context?context.$data : undefined;
        };
        
        ko.exportSymbol('ko.bindingHandlers',ko.bindingHandlers);
        
        ko.exportSymbol('ko.applyBindings',ko.applyBindings);
        
        ko.exportSymbol('ko.applyBindingsToDescendants',ko.applyBindingsToDescendants);
        
        ko.exportSymbol('ko.applyBindingsToNode',ko.applyBindingsToNode);
        
        ko.exportSymbol('ko.contextFor',ko.contextFor);
        
        ko.exportSymbol('ko.dataFor',ko.dataFor);
      }();
      
      var eventHandlersWithShortcuts = ['click'];
      
      ko.utils.arrayForEach(eventHandlersWithShortcuts,
      function (eventName) {
        ko.bindingHandlers[eventName] =  {
          'init' : function (element,valueAccessor,allBindingsAccessor,viewModel) {
            var newValueAccessor = function () {
                  var result = {};
                  
                  result[eventName] = valueAccessor();
                  return result;
                };
            return ko.bindingHandlers['event']['init'].call(this,element,newValueAccessor,allBindingsAccessor,viewModel);
          }
        };
      });
      
      ko.bindingHandlers.event =  {
        'init' : function (element,valueAccessor,allBindingsAccessor,viewModel) {
          var eventsToHandle = valueAccessor() || {};
          
          for (var eventNameOutsideClosure in eventsToHandle){
            
            (function () {
              var eventName = eventNameOutsideClosure;
              
              if (typeof eventName == "string"){
                
                ko.utils.registerEventHandler(element,eventName,
                function (event) {
                  var handlerReturnValue;
                  
                  var handlerFunction = valueAccessor()[eventName];
                  
                  if (!handlerFunction){
                    return ;
                  }
                  
                  var allBindings = allBindingsAccessor();
                  
                  try {
                    
                    var argsForHandler = ko.utils.makeArray(arguments);
                    
                    argsForHandler.unshift(viewModel);
                    
                    handlerReturnValue = handlerFunction.apply(viewModel,argsForHandler);
                  } finally {
                    
                    if (handlerReturnValue !== true){
                      
                      if (event.preventDefault){
                        
                        event.preventDefault();
                      } else event.returnValue = false;
                    }
                    
                  }
                  
                  var bubble = allBindings[eventName+'Bubble'] !== false;
                  
                  if (!bubble){
                    
                    event.cancelBubble = true;
                    
                    if (event.stopPropagation){
                      
                      event.stopPropagation();
                    }
                    
                  }
                  
                });
              }
              
            })();
          }
          
        }
      };
      
      ko.bindingHandlers.submit =  {
        'init' : function (element,valueAccessor,allBindingsAccessor,viewModel) {
          if (typeof valueAccessor() != "function"){
            throw new Error("The value for a submit binding must be a function")
            
          }
          
          ko.utils.registerEventHandler(element,"submit",
          function (event) {
            var handlerReturnValue;
            
            var value = valueAccessor();
            
            try {
              
              handlerReturnValue = value.call(viewModel,element);
            } finally {
              
              if (handlerReturnValue !== true){
                
                if (event.preventDefault){
                  
                  event.preventDefault();
                } else event.returnValue = false;
              }
              
            }
            
          });
        }
      };
      
      ko.bindingHandlers.visible =  {
        'update' : function (element,valueAccessor) {
          var value = ko.utils.unwrapObservable(valueAccessor());
          
          var isCurrentlyVisible = !(element.style.display == "none");
          
          if (value && !isCurrentlyVisible){
            
            element.style.display = "";
          } else if ((!value) && isCurrentlyVisible){
            
            element.style.display = "none";
          }
          
        }
      };
      
      ko.bindingHandlers.enable =  {
        'update' : function (element,valueAccessor) {
          var value = ko.utils.unwrapObservable(valueAccessor());
          
          if (value && element.disabled){
            
            element.removeAttribute("disabled");
          } else if ((!value) && (!element.disabled)){
            
            element.disabled = true;
          }
          
        }
      };
      
      ko.bindingHandlers.disable =  {
        'update' : function (element,valueAccessor) {
          ko.bindingHandlers['enable']['update'](element,
          function () {
            return !ko.utils.unwrapObservable(valueAccessor());
          });
        }
      };
      
      ko.bindingHandlers.value =  {
        'init' : function (element,valueAccessor,allBindingsAccessor) {
          var eventsToCatch = ["change"];
          
          var requestedEventsToCatch = allBindingsAccessor()["valueUpdate"];
          
          if (requestedEventsToCatch){
            
            if (typeof requestedEventsToCatch == "string"){
              
              requestedEventsToCatch = [requestedEventsToCatch];
            }
            
            ko.utils.arrayPushAll(eventsToCatch,requestedEventsToCatch);
            
            eventsToCatch = ko.utils.arrayGetDistinctValues(eventsToCatch);
          }
          
          ko.utils.arrayForEach(eventsToCatch,
          function (eventName) {
            var handleEventAsynchronously = false;
            
            if (ko.utils.stringStartsWith(eventName,"after")){
              
              handleEventAsynchronously = true;
              
              eventName = eventName.substring("after".length);
            }
            
            var runEventHandler = handleEventAsynchronously?function (handler) {
                  setTimeout(handler,0);
                } : function (handler) {
                  handler();
                };
            
            ko.utils.registerEventHandler(element,eventName,
            function () {
              runEventHandler(function () {
                var modelValue = valueAccessor();
                
                var elementValue = ko.selectExtensions.readValue(element);
                
                if (ko.isWriteableObservable(modelValue)){
                  
                  modelValue(elementValue);
                } else {
                  
                  var allBindings = allBindingsAccessor();
                  if (allBindings['_ko_property_writers'] && allBindings['_ko_property_writers']['value']){
                    
                    allBindings['_ko_property_writers']['value'](elementValue);
                  }
                  
                }
                
              });
            });
          });
        },
        'update' : function (element,valueAccessor) {
          var newValue = ko.utils.unwrapObservable(valueAccessor());
          
          var elementValue = ko.selectExtensions.readValue(element);
          
          var valueHasChanged = (newValue != elementValue);
          
          if ((newValue === 0) && (elementValue !== 0) && (elementValue !== "0")){
            
            valueHasChanged = true;
          }
          
          if (valueHasChanged){
            
            var applyValueAction = function () {
                  ko.selectExtensions.writeValue(element,newValue);
                };
            
            applyValueAction();
            
            var alsoApplyAsynchronously = element.tagName == "SELECT";
            
            if (alsoApplyAsynchronously){
              
              setTimeout(applyValueAction,0);
            }
            
          }
          
          if ((element.tagName == "SELECT") && (element.length>0)){
            
            ensureDropdownSelectionIsConsistentWithModelValue(element,newValue,false);
          }
          
        }
      };
      
      ko.bindingHandlers.options =  {
        'update' : function (element,valueAccessor,allBindingsAccessor) {
          if (element.tagName != "SELECT"){
            throw new Error("options binding applies only to SELECT elements")
            
          }
          
          var selectWasPreviouslyEmpty = element.length == 0;
          
          var previousSelectedValues = ko.utils.arrayMap(ko.utils.arrayFilter(element.childNodes,
              function (node) {
                return node.tagName && node.tagName == "OPTION" && node.selected;
              }),
              function (node) {
                return ko.selectExtensions.readValue(node) || node.innerText || node.textContent;
              });
          
          var previousScrollTop = element.scrollTop;
          
          element.scrollTop = 0;
          
          var value = ko.utils.unwrapObservable(valueAccessor());
          
          var selectedValue = element.value;
          
          while (element.length>0){
            
            ko.cleanNode(element.options[0]);
            
            element.remove(0);
          }
          
          if (value){
            
            var allBindings = allBindingsAccessor();
            
            if (typeof value.length != "number"){
              
              value = [value];
            }
            
            if (allBindings['optionsCaption']){
              
              var option = document.createElement("OPTION");
              
              ko.utils.setHtml(option,allBindings['optionsCaption']);
              
              ko.selectExtensions.writeValue(option,undefined);
              
              element.appendChild(option);
            }
            
            for (var i = 0,j = value.length;i<j;i ++ ){
              
              var option = document.createElement("OPTION");
              
              var optionValue = typeof allBindings['optionsValue'] == "string"?value[i][allBindings['optionsValue']] : value[i];
              
              optionValue = ko.utils.unwrapObservable(optionValue);
              
              ko.selectExtensions.writeValue(option,optionValue);
              
              var optionsTextValue = allBindings['optionsText'];
              
              var optionText;
              
              if (typeof optionsTextValue == "function"){
                
                optionText = optionsTextValue(value[i]);
              } else if (typeof optionsTextValue == "string"){
                
                optionText = value[i][optionsTextValue];
              } else optionText = optionValue;
              
              if ((optionText === null) || (optionText === undefined)){
                
                optionText = "";
              }
              
              ko.utils.setTextContent(option,optionText);
              
              element.appendChild(option);
            }
            
            var newOptions = element.getElementsByTagName("OPTION");
            
            var countSelectionsRetained = 0;
            
            for (var i = 0,j = newOptions.length;i<j;i ++ ){
              
              if (ko.utils.arrayIndexOf(previousSelectedValues,ko.selectExtensions.readValue(newOptions[i])) >= 0){
                
                ko.utils.setOptionNodeSelectionState(newOptions[i],true);
                
                countSelectionsRetained ++ ;
              }
              
            }
            
            if (previousScrollTop){
              
              element.scrollTop = previousScrollTop;
            }
            
            if (selectWasPreviouslyEmpty && ('value' in allBindings)){
              
              ensureDropdownSelectionIsConsistentWithModelValue(element,ko.utils.unwrapObservable(allBindings['value']),true);
            }
            
          }
          
        }
      };
      
      ko.bindingHandlers.options.optionValueDomDataKey = '__ko.optionValueDomData__';
      
      ko.bindingHandlers.selectedOptions =  {
        getSelectedValuesFromSelectNode : function (selectNode) {
          var result = [];
          
          var nodes = selectNode.childNodes;
          
          for (var i = 0,j = nodes.length;i<j;i ++ ){
            
            var node = nodes[i];
            
            if ((node.tagName == "OPTION") && node.selected){
              
              result.push(ko.selectExtensions.readValue(node));
            }
            
          }
          return result;
        },
        'init' : function (element,valueAccessor,allBindingsAccessor) {
          ko.utils.registerEventHandler(element,"change",
          function () {
            var value = valueAccessor();
            
            if (ko.isWriteableObservable(value)){
              
              value(ko.bindingHandlers['selectedOptions'].getSelectedValuesFromSelectNode(this));
            } else {
              
              var allBindings = allBindingsAccessor();
              if (allBindings['_ko_property_writers'] && allBindings['_ko_property_writers']['value']){
                
                allBindings['_ko_property_writers']['value'](ko.bindingHandlers['selectedOptions'].getSelectedValuesFromSelectNode(this));
              }
              
            }
            
          });
        },
        'update' : function (element,valueAccessor) {
          if (element.tagName != "SELECT"){
            throw new Error("values binding applies only to SELECT elements")
            
          }
          
          var newValue = ko.utils.unwrapObservable(valueAccessor());
          
          if (newValue && typeof newValue.length == "number"){
            
            var nodes = element.childNodes;
            
            for (var i = 0,j = nodes.length;i<j;i ++ ){
              
              var node = nodes[i];
              
              if (node.tagName == "OPTION"){
                
                ko.utils.setOptionNodeSelectionState(node,ko.utils.arrayIndexOf(newValue,ko.selectExtensions.readValue(node)) >= 0);
              }
              
            }
            
          }
          
        }
      };
      
      ko.bindingHandlers.text =  {
        'update' : function (element,valueAccessor) {
          ko.utils.setTextContent(element,valueAccessor());
        }
      };
      
      ko.bindingHandlers.html =  {
        'init' : function () {
          return  {
            'controlsDescendantBindings' : true
          };
        },
        'update' : function (element,valueAccessor) {
          var value = ko.utils.unwrapObservable(valueAccessor());
          
          ko.utils.setHtml(element,value);
        }
      };
      
      ko.bindingHandlers.css =  {
        'update' : function (element,valueAccessor) {
          var value = ko.utils.unwrapObservable(valueAccessor() || {});
          
          for (var className in value){
            
            if (typeof className == "string"){
              
              var shouldHaveClass = ko.utils.unwrapObservable(value[className]);
              
              ko.utils.toggleDomNodeCssClass(element,className,shouldHaveClass);
            }
            
          }
          
        }
      };
      
      ko.bindingHandlers.style =  {
        'update' : function (element,valueAccessor) {
          var value = ko.utils.unwrapObservable(valueAccessor() || {});
          
          for (var styleName in value){
            
            if (typeof styleName == "string"){
              
              var styleValue = ko.utils.unwrapObservable(value[styleName]);
              
              element.style[styleName] = styleValue || "";
            }
            
          }
          
        }
      };
      
      ko.bindingHandlers.uniqueName =  {
        'init' : function (element,valueAccessor) {
          if (valueAccessor()){
            
            element.name = "ko_unique_"+( ++ ko.bindingHandlers['uniqueName'].currentIndex);
            
            if (ko.utils.isIe6 || ko.utils.isIe7){
              
              element.mergeAttributes(document.createElement("<input name='"+element.name+"'/>"),false);
            }
            
          }
          
        }
      };
      
      ko.bindingHandlers.uniqueName.currentIndex = 0;
      
      ko.bindingHandlers.checked =  {
        'init' : function (element,valueAccessor,allBindingsAccessor) {
          var updateHandler = function () {
                var valueToWrite;
                
                if (element.type == "checkbox"){
                  
                  valueToWrite = element.checked;
                } else if ((element.type == "radio") && (element.checked)){
                  
                  valueToWrite = element.value;
                } else {
                  return ;
                }
                
                var modelValue = valueAccessor();
                
                if ((element.type == "checkbox") && (ko.utils.unwrapObservable(modelValue) instanceof Array)){
                  
                  var existingEntryIndex = ko.utils.arrayIndexOf(ko.utils.unwrapObservable(modelValue),element.value);
                  
                  if (element.checked && (existingEntryIndex<0)){
                    
                    modelValue.push(element.value);
                  } else if ((!element.checked) && (existingEntryIndex >= 0)){
                    
                    modelValue.splice(existingEntryIndex,1);
                  }
                  
                } else if (ko.isWriteableObservable(modelValue)){
                  if (modelValue() !== valueToWrite){
                    
                    modelValue(valueToWrite);
                  }
                  
                } else {
                  
                  var allBindings = allBindingsAccessor();
                  if (allBindings['_ko_property_writers'] && allBindings['_ko_property_writers']['checked']){
                    
                    allBindings['_ko_property_writers']['checked'](valueToWrite);
                  }
                  
                }
                
              };
          
          ko.utils.registerEventHandler(element,"click",updateHandler);
          
          if ((element.type == "radio") && !element.name){
            
            ko.bindingHandlers['uniqueName']['init'](element,
            function () {
              return true;
            });
          }
          
        },
        'update' : function (element,valueAccessor) {
          var value = ko.utils.unwrapObservable(valueAccessor());
          
          if (element.type == "checkbox"){
            
            if (value instanceof Array){
              
              element.checked = ko.utils.arrayIndexOf(value,element.value) >= 0;
            } else {
              
              element.checked = value;
            }
            
          } else if (element.type == "radio"){
            
            element.checked = (element.value == value);
          }
          
        }
      };
      
      ko.bindingHandlers.attr =  {
        'update' : function (element,valueAccessor,allBindingsAccessor) {
          var value = ko.utils.unwrapObservable(valueAccessor()) || {};
          
          for (var attrName in value){
            
            if (typeof attrName == "string"){
              
              var attrValue = ko.utils.unwrapObservable(value[attrName]);
              
              if ((attrValue === false) || (attrValue === null) || (attrValue === undefined)){
                
                element.removeAttribute(attrName);
              } else element.setAttribute(attrName,attrValue.toString());
            }
            
          }
          
        }
      };
      
      ko.bindingHandlers.hasfocus =  {
        'init' : function (element,valueAccessor,allBindingsAccessor) {
          var writeValue = function (valueToWrite) {
                var modelValue = valueAccessor();
                
                if (valueToWrite == ko.utils.unwrapObservable(modelValue)){
                  return ;
                }
                
                if (ko.isWriteableObservable(modelValue)){
                  
                  modelValue(valueToWrite);
                } else {
                  
                  var allBindings = allBindingsAccessor();
                  if (allBindings['_ko_property_writers'] && allBindings['_ko_property_writers']['hasfocus']){
                    
                    allBindings['_ko_property_writers']['hasfocus'](valueToWrite);
                  }
                  
                }
                
              };
          
          ko.utils.registerEventHandler(element,"focus",
          function () {
            writeValue(true);
          });
          
          ko.utils.registerEventHandler(element,"focusin",
          function () {
            writeValue(true);
          });
          
          ko.utils.registerEventHandler(element,"blur",
          function () {
            writeValue(false);
          });
          
          ko.utils.registerEventHandler(element,"focusout",
          function () {
            writeValue(false);
          });
        },
        'update' : function (element,valueAccessor) {
          var value = ko.utils.unwrapObservable(valueAccessor());
          
          value?element.focus() : element.blur();
          
          ko.utils.triggerEvent(element,value?"focusin" : "focusout");
        }
      };
      
      ko.bindingHandlers['with'] =  {
        makeTemplateValueAccessor : function (valueAccessor) {
          return function () {
            var value = valueAccessor();
            return  {
              'if' : value,
              'data' : value,
              'templateEngine' : ko.nativeTemplateEngine.instance
            };
          };
        },
        'init' : function (element,valueAccessor,allBindingsAccessor,viewModel,bindingContext) {
          return ko.bindingHandlers['template']['init'](element,ko.bindingHandlers['with'].makeTemplateValueAccessor(valueAccessor));
        },
        'update' : function (element,valueAccessor,allBindingsAccessor,viewModel,bindingContext) {
          return ko.bindingHandlers['template']['update'](element,ko.bindingHandlers['with'].makeTemplateValueAccessor(valueAccessor),allBindingsAccessor,viewModel,bindingContext);
        }
      };
      
      ko.jsonExpressionRewriting.bindingRewriteValidators['with'] = false;
      
      ko.virtualElements.allowedBindings['with'] = true;
      
      ko.bindingHandlers['if'] =  {
        makeTemplateValueAccessor : function (valueAccessor) {
          return function () {
            return  {
              'if' : valueAccessor(),
              'templateEngine' : ko.nativeTemplateEngine.instance
            };
          };
        },
        'init' : function (element,valueAccessor,allBindingsAccessor,viewModel,bindingContext) {
          return ko.bindingHandlers['template']['init'](element,ko.bindingHandlers['if'].makeTemplateValueAccessor(valueAccessor));
        },
        'update' : function (element,valueAccessor,allBindingsAccessor,viewModel,bindingContext) {
          return ko.bindingHandlers['template']['update'](element,ko.bindingHandlers['if'].makeTemplateValueAccessor(valueAccessor),allBindingsAccessor,viewModel,bindingContext);
        }
      };
      
      ko.jsonExpressionRewriting.bindingRewriteValidators['if'] = false;
      
      ko.virtualElements.allowedBindings['if'] = true;
      
      ko.bindingHandlers.ifnot =  {
        makeTemplateValueAccessor : function (valueAccessor) {
          return function () {
            return  {
              'ifnot' : valueAccessor(),
              'templateEngine' : ko.nativeTemplateEngine.instance
            };
          };
        },
        'init' : function (element,valueAccessor,allBindingsAccessor,viewModel,bindingContext) {
          return ko.bindingHandlers['template']['init'](element,ko.bindingHandlers['ifnot'].makeTemplateValueAccessor(valueAccessor));
        },
        'update' : function (element,valueAccessor,allBindingsAccessor,viewModel,bindingContext) {
          return ko.bindingHandlers['template']['update'](element,ko.bindingHandlers['ifnot'].makeTemplateValueAccessor(valueAccessor),allBindingsAccessor,viewModel,bindingContext);
        }
      };
      
      ko.jsonExpressionRewriting.bindingRewriteValidators.ifnot = false;
      
      ko.virtualElements.allowedBindings.ifnot = true;
      
      ko.bindingHandlers.foreach =  {
        makeTemplateValueAccessor : function (valueAccessor) {
          return function () {
            var bindingValue = ko.utils.unwrapObservable(valueAccessor());
            
            if ((!bindingValue) || typeof bindingValue.length == "number"){
              return  {
                'foreach' : bindingValue,
                'templateEngine' : ko.nativeTemplateEngine.instance
              };
            }
            return  {
              'foreach' : bindingValue['data'],
              'includeDestroyed' : bindingValue['includeDestroyed'],
              'afterAdd' : bindingValue['afterAdd'],
              'beforeRemove' : bindingValue['beforeRemove'],
              'afterRender' : bindingValue['afterRender'],
              'templateEngine' : ko.nativeTemplateEngine.instance
            };
          };
        },
        'init' : function (element,valueAccessor,allBindingsAccessor,viewModel,bindingContext) {
          return ko.bindingHandlers['template']['init'](element,ko.bindingHandlers['foreach'].makeTemplateValueAccessor(valueAccessor));
        },
        'update' : function (element,valueAccessor,allBindingsAccessor,viewModel,bindingContext) {
          return ko.bindingHandlers['template']['update'](element,ko.bindingHandlers['foreach'].makeTemplateValueAccessor(valueAccessor),allBindingsAccessor,viewModel,bindingContext);
        }
      };
      
      ko.jsonExpressionRewriting.bindingRewriteValidators.foreach = false;
      
      ko.virtualElements.allowedBindings.foreach = true;
      
      ko.exportSymbol('ko.allowedVirtualElementBindings',ko.virtualElements.allowedBindings);
      
      ko.templateEngine = function (){};
      
      ko.templateEngine.prototype.renderTemplateSource = function (templateSource,bindingContext,options) {
        throw "Override renderTemplateSource"
        
      };
      
      ko.templateEngine.prototype.createJavaScriptEvaluatorBlock = function (script) {
        throw "Override createJavaScriptEvaluatorBlock"
        
      };
      
      ko.templateEngine.prototype.makeTemplateSource = function (template) {
        if (typeof template == "string"){
          
          var elem = document.getElementById(template);
          
          if (!elem)throw new Error("Cannot find template with ID "+template)
          return new ko.templateSources.domElement(elem);
        } else if ((template.nodeType == 1) || (template.nodeType == 8))return new ko.templateSources.anonymousTemplate(template);
      };
      
      ko.templateEngine.prototype.renderTemplate = function (template,bindingContext,options) {
        var templateSource = this.makeTemplateSource(template);
        return this.renderTemplateSource(templateSource,bindingContext,options);
      };
      
      ko.templateEngine.prototype.isTemplateRewritten = function (template) {
        if (this.allowTemplateRewriting === false)return true;
        
        if (this.knownRewrittenTemplates && this.knownRewrittenTemplates[template])return true;
        return this.makeTemplateSource(template).data("isRewritten");
      };
      
      ko.templateEngine.prototype.rewriteTemplate = function (template,rewriterCallback) {
        var templateSource = this.makeTemplateSource(template),
            rewritten = rewriterCallback(templateSource.text());
        
        templateSource.text(rewritten);
        
        templateSource.data("isRewritten",true);
        
        if (typeof template == "string"){
          
          this.knownRewrittenTemplates = this.knownRewrittenTemplates || {};
          
          this.knownRewrittenTemplates[template] = true;
        }
        
      };
      
      ko.exportSymbol('ko.templateEngine',ko.templateEngine);
      
      ko.templateRewriting = function () {
        function constructMemoizedTagReplacement(dataBindAttributeValue,tagToRetain,templateEngine) {
          var dataBindKeyValueArray = ko.jsonExpressionRewriting.parseObjectLiteral(dataBindAttributeValue);
          
          validateDataBindValuesForRewriting(dataBindKeyValueArray);
          
          var rewrittenDataBindAttributeValue = ko.jsonExpressionRewriting.insertPropertyAccessorsIntoJson(dataBindKeyValueArray),
              applyBindingsToNextSiblingScript = "ko.templateRewriting.applyMemoizedBindingsToNextSibling(function() { \
            return (function() { return { "+rewrittenDataBindAttributeValue+" } })() \
        })";
          return templateEngine.createJavaScriptEvaluatorBlock(applyBindingsToNextSiblingScript)+tagToRetain;
        }
        function validateDataBindValuesForRewriting(keyValueArray) {
          var allValidators = ko.jsonExpressionRewriting.bindingRewriteValidators;
          
          for (var i = 0;i<keyValueArray.length;i ++ ){
            
            var key = keyValueArray[i].key;
            
            if (allValidators.hasOwnProperty(key)){
              
              var validator = allValidators[key];
              
              if (typeof validator === "function"){
                
                var possibleErrorMessage = validator(keyValueArray[i].value);
                
                if (possibleErrorMessage)throw new Error(possibleErrorMessage)
                
              } else if (!validator)throw new Error("This template engine does not support the '"+key+"' binding within its templates")
              
            }
            
          }
          
        }
        var memoizeDataBindingAttributeSyntaxRegex = /(<[a-z]+\d*(\s+(?!data-bind=)[a-z0-9\-]+(=(\"[^\"]*\"|\'[^\']*\'))?)*\s+)data-bind=(["'])([\s\S]*?)\5/gi,
            memoizeVirtualContainerBindingSyntaxRegex = /<!--\s*ko\b\s*([\s\S]*?)\s*-->/g;
        return  {
          ensureTemplateIsRewritten : function (template,templateEngine) {
            if (!templateEngine['isTemplateRewritten'](template)){
              
              templateEngine['rewriteTemplate'](template,
              function (htmlString) {
                return ko.templateRewriting.memoizeBindingAttributeSyntax(htmlString,templateEngine);
              });
            }
            
          },
          memoizeBindingAttributeSyntax : function (htmlString,templateEngine) {
            return htmlString.replace(memoizeDataBindingAttributeSyntaxRegex,
            function () {
              return constructMemoizedTagReplacement(arguments[6],arguments[1],templateEngine);
            }).replace(memoizeVirtualContainerBindingSyntaxRegex,
            function () {
              return constructMemoizedTagReplacement(arguments[1],"<!-- ko -->",templateEngine);
            });
          },
          applyMemoizedBindingsToNextSibling : function (bindings) {
            return ko.memoization.memoize(function (domNode,bindingContext) {
              if (domNode.nextSibling){
                
                ko.applyBindingsToNode(domNode.nextSibling,bindings,bindingContext);
              }
              
            });
          }
        };
      }();
      
      ko.exportSymbol('ko.templateRewriting',ko.templateRewriting);
      
      ko.exportSymbol('ko.templateRewriting.applyMemoizedBindingsToNextSibling',ko.templateRewriting.applyMemoizedBindingsToNextSibling);
      
      !function () {
        ko.templateSources = {};
        
        ko.templateSources.domElement = function (element) {
          this.domElement = element;
        };
        
        ko.templateSources.domElement.prototype.text = function () {
          if (arguments.length == 0)return this.domElement.tagName.toLowerCase() == "script"?this.domElement.text : this.domElement.innerHTML;
          
          {
            
            var valueToWrite = arguments[0];
            
            this.domElement.tagName.toLowerCase() == "script"?this.domElement.text = valueToWrite : ko.utils.setHtml(this.domElement,valueToWrite);
          }
          
        };
        
        ko.templateSources.domElement.prototype.data = function (key) {
          if (arguments.length === 1)return ko.utils.domData.get(this.domElement,"templateSourceData_"+key);
          
          ko.utils.domData.set(this.domElement,"templateSourceData_"+key,arguments[1]);
        };
        
        var anonymousTemplatesDomDataKey = "__ko_anon_template__";
        
        ko.templateSources.anonymousTemplate = function (element) {
          this.domElement = element;
        };
        
        ko.templateSources.anonymousTemplate.prototype = new ko.templateSources.domElement();
        
        ko.templateSources.anonymousTemplate.prototype.text = function () {
          if (arguments.length == 0)return ko.utils.domData.get(this.domElement,anonymousTemplatesDomDataKey);
          
          {
            
            var valueToWrite = arguments[0];
            
            ko.utils.domData.set(this.domElement,anonymousTemplatesDomDataKey,valueToWrite);
          }
          
        };
        
        ko.exportSymbol('ko.templateSources',ko.templateSources);
        
        ko.exportSymbol('ko.templateSources.domElement',ko.templateSources.domElement);
        
        ko.exportSymbol('ko.templateSources.anonymousTemplate',ko.templateSources.anonymousTemplate);
      }();
      
      !function () {
        function disposeOldSubscriptionAndStoreNewOne(element,newSubscription) {
          var oldSubscription = ko.utils.domData.get(element,templateSubscriptionDomDataKey);
          
          oldSubscription && (typeof (oldSubscription.dispose) == 'function') && oldSubscription.dispose();
          
          ko.utils.domData.set(element,templateSubscriptionDomDataKey,newSubscription);
        }
        function executeTemplate(targetNodeOrNodeArray,renderMode,template,bindingContext,options) {
          options = options || {};
          
          var templateEngineToUse = (options.templateEngine || _templateEngine);
          
          ko.templateRewriting.ensureTemplateIsRewritten(template,templateEngineToUse);
          
          var renderedNodesArray = templateEngineToUse.renderTemplate(template,bindingContext,options);
          
          if ((typeof renderedNodesArray.length != "number") || (renderedNodesArray.length>0 && typeof renderedNodesArray[0].nodeType != "number"))throw "Template engine must return an array of DOM nodes"
          
          var haveAddedNodesToParent = false;
          
          switch (renderMode) {
            case "replaceChildren" :
              
              ko.virtualElements.setDomNodeChildren(targetNodeOrNodeArray,renderedNodesArray);
              
              haveAddedNodesToParent = true;
              break;
            case "replaceNode" :
              
              ko.utils.replaceDomNodes(targetNodeOrNodeArray,renderedNodesArray);
              
              haveAddedNodesToParent = true;
              break;
            case "ignoreTargetNode" :
              break;
            default :
              throw new Error("Unknown renderMode: "+renderMode)
              
          }
          
          if (haveAddedNodesToParent){
            
            ko.activateBindingsOnTemplateRenderedNodes(renderedNodesArray,bindingContext);
            
            options.afterRender && options.afterRender(renderedNodesArray,bindingContext.$data);
          }
          return renderedNodesArray;
        }
        function getFirstNodeFromPossibleArray(nodeOrNodeArray) {
          return nodeOrNodeArray.nodeType?nodeOrNodeArray : nodeOrNodeArray.length>0?nodeOrNodeArray[0] : null;
        }
        function invokeForEachNodeOrCommentInParent(nodeArray,parent,action) {
          for (var i = 0;node = nodeArray[i];i ++ ){
            
            if (node.parentNode !== parent)continue ;
            
            ((node.nodeType === 1) || (node.nodeType === 8)) && action(node);
          }
          
        }
        var _templateEngine;
        
        ko.setTemplateEngine = function (templateEngine) {
          if ((templateEngine != undefined) && !(templateEngine instanceof ko.templateEngine))throw "templateEngine must inherit from ko.templateEngine"
          
          _templateEngine = templateEngine;
        };
        
        ko.activateBindingsOnTemplateRenderedNodes = function (nodeArray,bindingContext) {
          var nodeArrayClone = ko.utils.arrayPushAll([],nodeArray),
              commonParentElement = (nodeArray.length>0)?nodeArray[0].parentNode : null;
          
          invokeForEachNodeOrCommentInParent(nodeArrayClone,commonParentElement,
          function (node) {
            ko.applyBindings(bindingContext,node);
          });
          
          invokeForEachNodeOrCommentInParent(nodeArrayClone,commonParentElement,
          function (node) {
            ko.memoization.unmemoizeDomNodeAndDescendants(node,[bindingContext]);
          });
        };
        
        ko.renderTemplate = function (template,dataOrBindingContext,options,targetNodeOrNodeArray,renderMode) {
          options = options || {};
          
          if ((options.templateEngine || _templateEngine) == undefined)throw "Set a template engine before calling renderTemplate"
          
          renderMode = renderMode || "replaceChildren";
          
          if (targetNodeOrNodeArray){
            
            var firstTargetNode = getFirstNodeFromPossibleArray(targetNodeOrNodeArray);
            
            var whenToDispose = function () {
                  return (!firstTargetNode) || !ko.utils.domNodeIsAttachedToDocument(firstTargetNode);
                };
            
            var activelyDisposeWhenNodeIsRemoved = (firstTargetNode && renderMode == "replaceNode")?firstTargetNode.parentNode : firstTargetNode;
            return new ko.dependentObservable(function () {
              var bindingContext = (dataOrBindingContext && (dataOrBindingContext instanceof ko.bindingContext))?dataOrBindingContext : new ko.bindingContext(ko.utils.unwrapObservable(dataOrBindingContext)),
                  templateName = typeof (template) == 'function'?template(bindingContext.$data) : template,
                  renderedNodesArray = executeTemplate(targetNodeOrNodeArray,renderMode,templateName,bindingContext,options);
              
              if (renderMode == "replaceNode"){
                
                targetNodeOrNodeArray = renderedNodesArray;
                
                firstTargetNode = getFirstNodeFromPossibleArray(targetNodeOrNodeArray);
              }
              
            },null, {
              'disposeWhen' : whenToDispose,
              'disposeWhenNodeIsRemoved' : activelyDisposeWhenNodeIsRemoved
            });
          } else return ko.memoization.memoize(function (domNode) {
            ko.renderTemplate(template,dataOrBindingContext,options,domNode,"replaceNode");
          });
        };
        
        ko.renderTemplateForEach = function (template,arrayOrObservableArray,options,targetNode,parentBindingContext) {
          var createInnerBindingContext = function (arrayValue) {
                return parentBindingContext.createChildContext(ko.utils.unwrapObservable(arrayValue));
              },
              activateBindingsCallback = function (arrayValue,addedNodesArray) {
                var bindingContext = createInnerBindingContext(arrayValue);
                
                ko.activateBindingsOnTemplateRenderedNodes(addedNodesArray,bindingContext);
                
                options.afterRender && options.afterRender(addedNodesArray,bindingContext.$data);
              };
          return new ko.dependentObservable(function () {
            var unwrappedArray = ko.utils.unwrapObservable(arrayOrObservableArray) || [];
            
            typeof unwrappedArray.length == "undefined" && (unwrappedArray = [unwrappedArray]);
            
            var filteredArray = ko.utils.arrayFilter(unwrappedArray,
                function (item) {
                  return options.includeDestroyed || item === undefined || item === null || !ko.utils.unwrapObservable(item._destroy);
                });
            
            ko.utils.setDomNodeChildrenFromArrayMapping(targetNode,filteredArray,
            function (arrayValue) {
              var templateName = typeof (template) == 'function'?template(arrayValue) : template;
              return executeTemplate(null,"ignoreTargetNode",templateName,createInnerBindingContext(arrayValue),options);
            },options,activateBindingsCallback);
          },null, {
            'disposeWhenNodeIsRemoved' : targetNode
          });
        };
        
        var templateSubscriptionDomDataKey = '__ko__templateSubscriptionDomDataKey__';
        
        ko.bindingHandlers.template =  {
          'init' : function (element,valueAccessor) {
            var bindingValue = ko.utils.unwrapObservable(valueAccessor());
            
            if ((typeof bindingValue != "string") && (!bindingValue.name) && (element.nodeType == 1)){
              
              new ko.templateSources.anonymousTemplate(element).text(element.innerHTML);
              
              ko.utils.emptyDomNode(element);
            }
            return  {
              'controlsDescendantBindings' : true
            };
          },
          'update' : function (element,valueAccessor,allBindingsAccessor,viewModel,bindingContext) {
            var bindingValue = ko.utils.unwrapObservable(valueAccessor());
            
            var templateName;
            
            var shouldDisplay = true;
            
            if (typeof bindingValue == "string"){
              
              templateName = bindingValue;
            } else {
              
              templateName = bindingValue.name;
              if ('if' in bindingValue){
                
                shouldDisplay = shouldDisplay && ko.utils.unwrapObservable(bindingValue['if']);
              }
              if ('ifnot' in bindingValue){
                
                shouldDisplay = shouldDisplay && !ko.utils.unwrapObservable(bindingValue['ifnot']);
              }
              
            }
            
            var templateSubscription = null;
            
            if ((typeof bindingValue === 'object') && ('foreach' in bindingValue)){
              
              var dataArray = (shouldDisplay && bindingValue['foreach']) || [];
              
              templateSubscription = ko.renderTemplateForEach(templateName || element,dataArray,bindingValue,element,bindingContext);
            } else {
              if (shouldDisplay){
                
                var innerBindingContext = (typeof bindingValue == 'object') && ('data' in bindingValue)?bindingContext['createChildContext'](ko.utils.unwrapObservable(bindingValue['data'])) : bindingContext;
                
                templateSubscription = ko.renderTemplate(templateName || element,innerBindingContext,bindingValue,element);
              } else ko.virtualElements.emptyNode(element);
            }
            
            disposeOldSubscriptionAndStoreNewOne(element,templateSubscription);
          }
        };
        
        ko.jsonExpressionRewriting.bindingRewriteValidators.template = function (bindingValue) {
          var parsedBindingValue = ko.jsonExpressionRewriting.parseObjectLiteral(bindingValue);
          
          if ((parsedBindingValue.length == 1) && parsedBindingValue[0].unknown)return null;
          
          if (ko.jsonExpressionRewriting.keyValueArrayContainsKey(parsedBindingValue,"name"))return null;
          return "This template engine does not support anonymous templates nested within its templates";
        };
        
        ko.virtualElements.allowedBindings.template = true;
      }();
      
      ko.exportSymbol('ko.setTemplateEngine',ko.setTemplateEngine);
      
      ko.exportSymbol('ko.renderTemplate',ko.renderTemplate);
      
      !function () {
        function findEditScriptFromEditDistanceMatrix(editDistanceMatrix,oldArray,newArray) {
          var oldIndex = oldArray.length,
              newIndex = newArray.length,
              editScript = [],
              maxDistance = editDistanceMatrix[newIndex][oldIndex];
          
          if (maxDistance === undefined)return null;
          
          while ((oldIndex>0) || (newIndex>0)){
            
            var me = editDistanceMatrix[newIndex][oldIndex];
            
            var distanceViaAdd = (newIndex>0)?editDistanceMatrix[newIndex-1][oldIndex] : maxDistance+1;
            
            var distanceViaDelete = (oldIndex>0)?editDistanceMatrix[newIndex][oldIndex-1] : maxDistance+1;
            
            var distanceViaRetain = (newIndex>0) && (oldIndex>0)?editDistanceMatrix[newIndex-1][oldIndex-1] : maxDistance+1;
            
            ((distanceViaAdd === undefined) || (distanceViaAdd<me-1)) && (distanceViaAdd = maxDistance+1);
            
            ((distanceViaDelete === undefined) || (distanceViaDelete<me-1)) && (distanceViaDelete = maxDistance+1);
            
            distanceViaRetain<me-1 && (distanceViaRetain = maxDistance+1);
            
            if ((distanceViaAdd <= distanceViaDelete) && (distanceViaAdd<distanceViaRetain)){
              
              editScript.push( {
                status : "added",
                value : newArray[newIndex-1]
              });
              
              newIndex -- ;
            } else if ((distanceViaDelete<distanceViaAdd) && (distanceViaDelete<distanceViaRetain)){
              
              editScript.push( {
                status : "deleted",
                value : oldArray[oldIndex-1]
              });
              
              oldIndex -- ;
            } else {
              
              editScript.push( {
                status : "retained",
                value : oldArray[oldIndex-1]
              });
              
              newIndex -- ;
              
              oldIndex -- ;
            }
            
          }
          return editScript.reverse();
        }
        function calculateEditDistanceMatrix(oldArray,newArray,maxAllowedDistance) {
          var distances = [];
          
          for (var i = 0;i <= newArray.length;i ++ )
          distances[i] = [];
          
          for (var i = 0,j = Math.min(oldArray.length,maxAllowedDistance);i <= j;i ++ )
          distances[0][i] = i;
          
          for (var i = 1,j = Math.min(newArray.length,maxAllowedDistance);i <= j;i ++ )
          distances[i][0] = i;
          
          var oldIndex,
              oldIndexMax = oldArray.length,
              newIndex,
              newIndexMax = newArray.length,
              distanceViaAddition,
              distanceViaDeletion;
          
          for (oldIndex = 1;oldIndex <= oldIndexMax;oldIndex ++ ){
            
            var newIndexMinForRow = Math.max(1,oldIndex-maxAllowedDistance);
            
            var newIndexMaxForRow = Math.min(newIndexMax,oldIndex+maxAllowedDistance);
            
            for (newIndex = newIndexMinForRow;newIndex <= newIndexMaxForRow;newIndex ++ )if (oldArray[oldIndex-1] === newArray[newIndex-1])distances[newIndex][oldIndex] = distances[newIndex-1][oldIndex-1];
             else {
              
              var northDistance = distances[newIndex-1][oldIndex] === undefined?Number.MAX_VALUE : distances[newIndex-1][oldIndex]+1;
              
              var westDistance = distances[newIndex][oldIndex-1] === undefined?Number.MAX_VALUE : distances[newIndex][oldIndex-1]+1;
              
              distances[newIndex][oldIndex] = Math.min(northDistance,westDistance);
            }
            
          }
          return distances;
        }
        ko.utils.compareArrays = function (oldArray,newArray,maxEditsToConsider) {
          if (maxEditsToConsider === undefined)return ko.utils.compareArrays(oldArray,newArray,1) || ko.utils.compareArrays(oldArray,newArray,10) || ko.utils.compareArrays(oldArray,newArray,Number.MAX_VALUE);
          
          {
            
            oldArray = oldArray || [];
            
            newArray = newArray || [];
            
            var editDistanceMatrix = calculateEditDistanceMatrix(oldArray,newArray,maxEditsToConsider);
            return findEditScriptFromEditDistanceMatrix(editDistanceMatrix,oldArray,newArray);
          }
          
        };
      }();
      
      ko.exportSymbol('ko.utils.compareArrays',ko.utils.compareArrays);
      
      !function () {
        function mapNodeAndRefreshWhenChanged(containerNode,mapping,valueToMap,callbackAfterAddingNodes) {
          var mappedNodes = [],
              dependentObservable = ko.dependentObservable(function () {
                var newMappedNodes = mapping(valueToMap) || [];
                
                if (mappedNodes.length>0){
                  
                  fixUpVirtualElements(mappedNodes);
                  
                  ko.utils.replaceDomNodes(mappedNodes,newMappedNodes);
                  
                  callbackAfterAddingNodes && callbackAfterAddingNodes(valueToMap,newMappedNodes);
                }
                
                mappedNodes.splice(0,mappedNodes.length);
                
                ko.utils.arrayPushAll(mappedNodes,newMappedNodes);
              },null, {
                'disposeWhenNodeIsRemoved' : containerNode,
                'disposeWhen' : function () {
                  return (mappedNodes.length == 0) || !ko.utils.domNodeIsAttachedToDocument(mappedNodes[0]);
                }
              });
          return  {
            mappedNodes : mappedNodes,
            dependentObservable : dependentObservable
          };
        }
        function fixUpVirtualElements(contiguousNodeArray) {
          if (contiguousNodeArray.length>2){
            
            var current = contiguousNodeArray[0],
                last = contiguousNodeArray[contiguousNodeArray.length-1],
                newContiguousSet = [current];
            
            while (current !== last){
              
              current = current.nextSibling;
              
              if (!current)return ;
              
              newContiguousSet.push(current);
            }
            
            [].splice.apply(contiguousNodeArray,[0,contiguousNodeArray.length].concat(newContiguousSet));
          }
          
        }
        var lastMappingResultDomDataKey = "setDomNodeChildrenFromArrayMapping_lastMappingResult";
        
        ko.utils.setDomNodeChildrenFromArrayMapping = function (domNode,array,mapping,options,callbackAfterAddingNodes) {
          array = array || [];
          
          options = options || {};
          
          var isFirstExecution = ko.utils.domData.get(domNode,lastMappingResultDomDataKey) === undefined,
              lastMappingResult = ko.utils.domData.get(domNode,lastMappingResultDomDataKey) || [],
              lastArray = ko.utils.arrayMap(lastMappingResult,
              function (x) {
                return x.arrayEntry;
              }),
              editScript = ko.utils.compareArrays(lastArray,array),
              newMappingResult = [],
              lastMappingResultIndex = 0,
              nodesToDelete = [],
              nodesAdded = [],
              insertAfterNode = null;
          
          for (var i = 0,j = editScript.length;i<j;i ++ )
          switch (editScript[i].status) {
            case "retained" :
              
              var dataToRetain = lastMappingResult[lastMappingResultIndex];
              
              newMappingResult.push(dataToRetain);
              
              dataToRetain.domNodes.length>0 && (insertAfterNode = dataToRetain.domNodes[dataToRetain.domNodes.length-1]);
              
              lastMappingResultIndex ++ ;
              break;
            case "deleted" :
              
              lastMappingResult[lastMappingResultIndex].dependentObservable.dispose();
              
              fixUpVirtualElements(lastMappingResult[lastMappingResultIndex].domNodes);
              
              ko.utils.arrayForEach(lastMappingResult[lastMappingResultIndex].domNodes,
              function (node) {
                nodesToDelete.push( {
                  element : node,
                  index : i,
                  value : editScript[i].value
                });
                
                insertAfterNode = node;
              });
              
              lastMappingResultIndex ++ ;
              break;
            case "added" :
              
              var valueToMap = editScript[i].value;
              
              var mapData = mapNodeAndRefreshWhenChanged(domNode,mapping,valueToMap,callbackAfterAddingNodes);
              
              var mappedNodes = mapData.mappedNodes;
              
              newMappingResult.push( {
                arrayEntry : editScript[i].value,
                domNodes : mappedNodes,
                dependentObservable : mapData.dependentObservable
              });
              
              for (var nodeIndex = 0,nodeIndexMax = mappedNodes.length;nodeIndex<nodeIndexMax;nodeIndex ++ ){
                
                var node = mappedNodes[nodeIndex];
                
                nodesAdded.push( {
                  element : node,
                  index : i,
                  value : editScript[i].value
                });
                
                if (insertAfterNode == null){
                  
                  ko.virtualElements.prepend(domNode,node);
                } else {
                  
                  ko.virtualElements.insertAfter(domNode,node,insertAfterNode);
                }
                
                insertAfterNode = node;
              }
              
              if (callbackAfterAddingNodes){
                
                callbackAfterAddingNodes(valueToMap,mappedNodes);
              }
              break;
              
          }
          
          ko.utils.arrayForEach(nodesToDelete,
          function (node) {
            ko.cleanNode(node.element);
          });
          
          var invokedBeforeRemoveCallback = false;
          
          if (!isFirstExecution){
            
            if (options.afterAdd)for (var i = 0;i<nodesAdded.length;i ++ )
            options.afterAdd(nodesAdded[i].element,nodesAdded[i].index,nodesAdded[i].value);
            
            if (options.beforeRemove){
              
              for (var i = 0;i<nodesToDelete.length;i ++ )options.beforeRemove(nodesToDelete[i].element,nodesToDelete[i].index,nodesToDelete[i].value);
              
              invokedBeforeRemoveCallback = true;
            }
            
          }
          
          !invokedBeforeRemoveCallback && ko.utils.arrayForEach(nodesToDelete,
          function (node) {
            ko.removeNode(node.element);
          });
          
          ko.utils.domData.set(domNode,lastMappingResultDomDataKey,newMappingResult);
        };
      }();
      
      ko.exportSymbol('ko.utils.setDomNodeChildrenFromArrayMapping',ko.utils.setDomNodeChildrenFromArrayMapping);
      
      ko.nativeTemplateEngine = function () {
        this.allowTemplateRewriting = false;
      };
      
      ko.nativeTemplateEngine.prototype = new ko.templateEngine();
      
      ko.nativeTemplateEngine.prototype.renderTemplateSource = function (templateSource,bindingContext,options) {
        var templateText = templateSource.text();
        return ko.utils.parseHtmlFragment(templateText);
      };
      
      ko.nativeTemplateEngine.instance = new ko.nativeTemplateEngine();
      
      ko.setTemplateEngine(ko.nativeTemplateEngine.instance);
      
      ko.exportSymbol('ko.nativeTemplateEngine',ko.nativeTemplateEngine);
      
      !function () {
        ko.jqueryTmplTemplateEngine = function () {
          function executeTemplate(compiledTemplate,data,jQueryTemplateOptions) {
            return jQuery.tmpl(compiledTemplate,data,jQueryTemplateOptions);
          }
          function ensureHasReferencedJQueryTemplates() {
            if (jQueryTmplVersion<2)throw new Error("Your version of jQuery.tmpl is too old. Please upgrade to jQuery.tmpl 1.0.0pre or later.")
            
          }
          var jQueryTmplVersion = this.jQueryTmplVersion = function () {
                if ((typeof (jQuery) == "undefined") || !(jQuery.tmpl))return 0;
                
                try {
                  
                  if (jQuery.tmpl.tag.tmpl.open.toString().indexOf('__') >= 0)return 2;
                } catch(ex){
                  
                }
                return 1;
              }();
          
          this.renderTemplateSource = function (templateSource,bindingContext,options) {
            options = options || {};
            
            ensureHasReferencedJQueryTemplates();
            
            var precompiled = templateSource.data('precompiled');
            
            if (!precompiled){
              
              var templateText = templateSource.text() || "";
              
              templateText = "{{ko_with $item.koBindingContext}}"+templateText+"{{/ko_with}}";
              
              precompiled = jQuery.template(null,templateText);
              
              templateSource.data('precompiled',precompiled);
            }
            
            var data = [bindingContext['$data']],
                jQueryTemplateOptions = jQuery.extend( {
                  'koBindingContext' : bindingContext
                },options.templateOptions),
                resultNodes = executeTemplate(precompiled,data,jQueryTemplateOptions);
            
            resultNodes.appendTo(document.createElement("div"));
            
            jQuery.fragments = {};
            return resultNodes;
          };
          
          this.createJavaScriptEvaluatorBlock = function (script) {
            return "{{ko_code ((function() { return "+script+" })()) }}";
          };
          
          this.addTemplate = function (templateName,templateMarkup) {
            document.write("<script type='text/html' id='"+templateName+"'>"+templateMarkup+"</script>");
          };
          
          if (jQueryTmplVersion>0){
            
            jQuery.tmpl.tag.ko_code =  {
              open : "__.push($1 || '');"
            };
            
            jQuery.tmpl.tag.ko_with =  {
              open : "with($1) {",
              close : "} "
            };
          }
          
        };
        
        ko.jqueryTmplTemplateEngine.prototype = new ko.templateEngine();
        
        var jqueryTmplTemplateEngineInstance = new ko.jqueryTmplTemplateEngine();
        
        jqueryTmplTemplateEngineInstance.jQueryTmplVersion>0 && ko.setTemplateEngine(jqueryTmplTemplateEngineInstance);
        
        ko.exportSymbol('ko.jqueryTmplTemplateEngine',ko.jqueryTmplTemplateEngine);
      }();
    }(window);
  }();
}();
