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
    _mochaGlobalExport.iterators = {};
    
    var _mochaGlobalAlias = _mochaGlobalExport.iterators;
    
    !function () {
      function allItems(obj) {
        var _mochaLocalTmp23 = {};
        
        Runtime.createUnenumProp(_mochaLocalTmp23,iterator,
        function () {
          return function () {
            var _mochaIsNewBorn = true,
                _yieldResult = undefined,
                _yieldState = 0,
                length,
                _mochaLocalTmp22,
                x,
                _mochaLocalTmp21 = [],
                _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                  !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler('attempt to send to newborn generator.');
                  
                  while (1)
                  switch (_yieldState) {
                    case 0 :
                      
                      for (var _mochaLocalTmp20 in obj)
                      _mochaLocalTmp21.push(_mochaLocalTmp20);
                      
                      _mochaLocalTmp22 = 0;
                      
                      length = _mochaLocalTmp21.length;
                      
                      if (!(_mochaLocalTmp22<length)){
                        
                        _yieldState = -1;
                        break;
                      }
                    case 1 :
                      
                      _yieldState = 2;
                      
                      x = _mochaLocalTmp21[_mochaLocalTmp22];
                      return [x,obj[x]];
                    case 2 :
                      
                       ++ _mochaLocalTmp22;
                      
                      if (_mochaLocalTmp22<length){
                        
                        _yieldState = 1;
                        break;
                      } else _yieldState = -1;
                    case -1 :
                      
                      if (_isYieldSafe)return undefined;
                      
                      Runtime.throwStopIteration();
                      
                  }
                  
                };
            return Runtime.createGenerator(_mochaGenerator,
            function () {
              _yieldState = -1;
            },this);
          }();
        });
        return _mochaLocalTmp23;
      }
      function allValues(obj) {
        var _mochaLocalTmp19 = {};
        
        Runtime.createUnenumProp(_mochaLocalTmp19,iterator,
        function () {
          return function () {
            var _mochaIsNewBorn = true,
                _yieldResult = undefined,
                _yieldState = 0,
                length,
                _mochaLocalTmp18,
                x,
                _mochaLocalTmp17 = [],
                _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                  !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler('attempt to send to newborn generator.');
                  
                  while (1)
                  switch (_yieldState) {
                    case 0 :
                      
                      for (var _mochaLocalTmp16 in obj)
                      _mochaLocalTmp17.push(_mochaLocalTmp16);
                      
                      _mochaLocalTmp18 = 0;
                      
                      length = _mochaLocalTmp17.length;
                      
                      if (!(_mochaLocalTmp18<length)){
                        
                        _yieldState = -1;
                        break;
                      }
                    case 1 :
                      
                      _yieldState = 2;
                      
                      x = _mochaLocalTmp17[_mochaLocalTmp18];
                      return obj[x];
                    case 2 :
                      
                       ++ _mochaLocalTmp18;
                      
                      if (_mochaLocalTmp18<length){
                        
                        _yieldState = 1;
                        break;
                      } else _yieldState = -1;
                    case -1 :
                      
                      if (_isYieldSafe)return undefined;
                      
                      Runtime.throwStopIteration();
                      
                  }
                  
                };
            return Runtime.createGenerator(_mochaGenerator,
            function () {
              _yieldState = -1;
            },this);
          }();
        });
        return _mochaLocalTmp19;
      }
      function allKeys(obj) {
        var _mochaLocalTmp15 = {};
        
        Runtime.createUnenumProp(_mochaLocalTmp15,iterator,
        function () {
          return function () {
            var _mochaIsNewBorn = true,
                _yieldResult = undefined,
                _yieldState = 0,
                length,
                _mochaLocalTmp14,
                x,
                _mochaLocalTmp13 = [],
                _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                  !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler('attempt to send to newborn generator.');
                  
                  while (1)
                  switch (_yieldState) {
                    case 0 :
                      
                      for (var _mochaLocalTmp12 in obj)
                      _mochaLocalTmp13.push(_mochaLocalTmp12);
                      
                      _mochaLocalTmp14 = 0;
                      
                      length = _mochaLocalTmp13.length;
                      
                      if (!(_mochaLocalTmp14<length)){
                        
                        _yieldState = -1;
                        break;
                      }
                    case 1 :
                      
                      _yieldState = 2;
                      
                      x = _mochaLocalTmp13[_mochaLocalTmp14];
                      return x;
                    case 2 :
                      
                       ++ _mochaLocalTmp14;
                      
                      if (_mochaLocalTmp14<length){
                        
                        _yieldState = 1;
                        break;
                      } else _yieldState = -1;
                    case -1 :
                      
                      if (_isYieldSafe)return undefined;
                      
                      Runtime.throwStopIteration();
                      
                  }
                  
                };
            return Runtime.createGenerator(_mochaGenerator,
            function () {
              _yieldState = -1;
            },this);
          }();
        });
        return _mochaLocalTmp15;
      }
      function items(obj) {
        var _mochaLocalTmp11 = {};
        
        Runtime.createUnenumProp(_mochaLocalTmp11,iterator,
        function () {
          return function () {
            var _mochaIsNewBorn = true,
                _yieldResult = undefined,
                _yieldState = 0,
                length,
                _mochaLocalTmp10,
                x,
                _mochaLocalTmp9 = [],
                _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                  !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler('attempt to send to newborn generator.');
                  
                  while (1)
                  switch (_yieldState) {
                    case 0 :
                      
                      for (var _mochaLocalTmp8 in obj)
                      _mochaLocalTmp9.push(_mochaLocalTmp8);
                      
                      _mochaLocalTmp10 = 0;
                      
                      length = _mochaLocalTmp9.length;
                      
                      if (!(_mochaLocalTmp10<length)){
                        
                        _yieldState = -1;
                        break;
                      }
                    case 1 :
                      
                      x = _mochaLocalTmp9[_mochaLocalTmp10];
                      
                      if (hasOwn.call(obj,x)){
                        
                        _yieldState = 2;
                        break;
                      } else {
                        
                        _yieldState = 3;
                        break;
                      }
                    case 2 :
                      
                      _yieldState = 3;
                      return [x,obj[x]];
                    case 3 :
                      
                      _yieldState = 4;
                      break;
                    case 4 :
                      
                       ++ _mochaLocalTmp10;
                      
                      if (_mochaLocalTmp10<length){
                        
                        _yieldState = 1;
                        break;
                      } else _yieldState = -1;
                    case -1 :
                      
                      if (_isYieldSafe)return undefined;
                      
                      Runtime.throwStopIteration();
                      
                  }
                  
                };
            return Runtime.createGenerator(_mochaGenerator,
            function () {
              _yieldState = -1;
            },this);
          }();
        });
        return _mochaLocalTmp11;
      }
      function values(obj) {
        var _mochaLocalTmp7 = {};
        
        Runtime.createUnenumProp(_mochaLocalTmp7,iterator,
        function () {
          return function () {
            var _mochaIsNewBorn = true,
                _yieldResult = undefined,
                _yieldState = 0,
                length,
                _mochaLocalTmp6,
                x,
                _mochaLocalTmp5 = [],
                _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                  !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler('attempt to send to newborn generator.');
                  
                  while (1)
                  switch (_yieldState) {
                    case 0 :
                      
                      for (var _mochaLocalTmp4 in obj)
                      _mochaLocalTmp5.push(_mochaLocalTmp4);
                      
                      _mochaLocalTmp6 = 0;
                      
                      length = _mochaLocalTmp5.length;
                      
                      if (!(_mochaLocalTmp6<length)){
                        
                        _yieldState = -1;
                        break;
                      }
                    case 1 :
                      
                      x = _mochaLocalTmp5[_mochaLocalTmp6];
                      
                      if (hasOwn.call(obj,x)){
                        
                        _yieldState = 2;
                        break;
                      } else {
                        
                        _yieldState = 3;
                        break;
                      }
                    case 2 :
                      
                      _yieldState = 3;
                      return obj[x];
                    case 3 :
                      
                      _yieldState = 4;
                      break;
                    case 4 :
                      
                       ++ _mochaLocalTmp6;
                      
                      if (_mochaLocalTmp6<length){
                        
                        _yieldState = 1;
                        break;
                      } else _yieldState = -1;
                    case -1 :
                      
                      if (_isYieldSafe)return undefined;
                      
                      Runtime.throwStopIteration();
                      
                  }
                  
                };
            return Runtime.createGenerator(_mochaGenerator,
            function () {
              _yieldState = -1;
            },this);
          }();
        });
        return _mochaLocalTmp7;
      }
      function keys(obj) {
        var _mochaLocalTmp3 = {};
        
        Runtime.createUnenumProp(_mochaLocalTmp3,iterator,
        function () {
          return function () {
            var _mochaIsNewBorn = true,
                _yieldResult = undefined,
                _yieldState = 0,
                length,
                _mochaLocalTmp2,
                x,
                _mochaLocalTmp1 = [],
                _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                  !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler('attempt to send to newborn generator.');
                  
                  while (1)
                  switch (_yieldState) {
                    case 0 :
                      
                      for (var _mochaLocalTmp0 in obj)
                      _mochaLocalTmp1.push(_mochaLocalTmp0);
                      
                      _mochaLocalTmp2 = 0;
                      
                      length = _mochaLocalTmp1.length;
                      
                      if (!(_mochaLocalTmp2<length)){
                        
                        _yieldState = -1;
                        break;
                      }
                    case 1 :
                      
                      x = _mochaLocalTmp1[_mochaLocalTmp2];
                      
                      if (hasOwn.call(obj,x)){
                        
                        _yieldState = 2;
                        break;
                      } else {
                        
                        _yieldState = 3;
                        break;
                      }
                    case 2 :
                      
                      _yieldState = 3;
                      return x;
                    case 3 :
                      
                      _yieldState = 4;
                      break;
                    case 4 :
                      
                       ++ _mochaLocalTmp2;
                      
                      if (_mochaLocalTmp2<length){
                        
                        _yieldState = 1;
                        break;
                      } else _yieldState = -1;
                    case -1 :
                      
                      if (_isYieldSafe)return undefined;
                      
                      Runtime.throwStopIteration();
                      
                  }
                  
                };
            return Runtime.createGenerator(_mochaGenerator,
            function () {
              _yieldState = -1;
            },this);
          }();
        });
        return _mochaLocalTmp3;
      }
      var _mochaLocalExport = _mochaGlobalAlias,
          hasOwn = {}.hasOwnProperty,
          iterator = _mochaLocalExport.iterator = "__mocha_iterator_special_key__";
      
      _mochaLocalExport.keys = keys;
      
      _mochaLocalExport.values = values;
      
      _mochaLocalExport.items = items;
      
      _mochaLocalExport.allKeys = allKeys;
      
      _mochaLocalExport.allValues = allValues;
      
      _mochaLocalExport.allItems = allItems;
      return _mochaLocalExport;
    }();
  }();
  
  !function () {
    _mochaGlobalExport['-759650552-generator_expression_test.js'] = {};
    
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
          var _mochaIsNewBorn = true,
              _yieldResult = undefined,
              _yieldState = 0,
              length,
              _mochaLocalTmp3,
              x,
              _mochaLocalTmp2 = [],
              _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler('attempt to send to newborn generator.');
                
                while (1)
                switch (_yieldState) {
                  case 0 :
                    
                    for (var _mochaLocalTmp1 in testObject)
                    _mochaLocalTmp2.push(_mochaLocalTmp1);
                    
                    _mochaLocalTmp3 = 0;
                    
                    length = _mochaLocalTmp2.length;
                    
                    if (!(_mochaLocalTmp3<length)){
                      
                      _yieldState = -1;
                      break;
                    }
                  case 1 :
                    
                    _yieldState = 2;
                    
                    x = _mochaLocalTmp2[_mochaLocalTmp3];
                    
                    x = testObject[x];
                    return x;
                  case 2 :
                    
                     ++ _mochaLocalTmp3;
                    
                    if (_mochaLocalTmp3<length){
                      
                      _yieldState = 1;
                      break;
                    } else _yieldState = -1;
                  case -1 :
                    
                    if (_isYieldSafe)return undefined;
                    
                    Runtime.throwStopIteration();
                    
                }
                
              };
          return Runtime.createGenerator(_mochaGenerator,
          function () {
            _yieldState = -1;
          },this);
        }.call(this);
    
    test = function () {
      var _mochaIsNewBorn = true,
          _yieldResult = undefined,
          _yieldState = 0,
          x,
          _mochaLocalTmp4 = keys(testObject),
          _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
            !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler('attempt to send to newborn generator.');
            
            while (1)
            switch (_yieldState) {
              case 0 :
                
                _mochaLocalTmp4 = Runtime.hasIterator(_mochaLocalTmp4)?Runtime.getIterator(_mochaLocalTmp4) : _mochaLocalTmp4;
                
                if (_mochaLocalTmp4.__nothrowNext__){
                  
                  _yieldState = 1;
                  break;
                } else {
                  
                  _yieldState = 5;
                  break;
                }
              case 1 :
                
                if (!((x = _mochaLocalTmp4.__nothrowNext__()))){
                  
                  _yieldState = 4;
                  break;
                }
              case 2 :
                
                _yieldState = 3;
                return x;
              case 3 :
                
                if ((x = _mochaLocalTmp4.__nothrowNext__())){
                  
                  _yieldState = 2;
                  break;
                } else _yieldState = 4;
              case 4 :
                
                _yieldState = -1;
                break;
              case 5 :
                
                Runtime.exceptionHandler(14,'..///Users/aono_taketoshi/github/mocha/src/test/js/harmony/generator_expression_test.js','for of statement expect iterator or generator object.');
              case 6 :
              case -1 :
                
                if (_isYieldSafe)return undefined;
                
                Runtime.throwStopIteration();
                
            }
            
          };
      return Runtime.createGenerator(_mochaGenerator,
      function () {
        _yieldState = -1;
      },this);
    }.call(this);
    
    test = function () {
      var _mochaIsNewBorn = true,
          _yieldResult = undefined,
          _yieldState = 0,
          length,
          _mochaLocalTmp7,
          x,
          _mochaLocalTmp6 = [],
          _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
            !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler('attempt to send to newborn generator.');
            
            while (1)
            switch (_yieldState) {
              case 0 :
                
                for (var _mochaLocalTmp5 in testObject)
                _mochaLocalTmp6.push(_mochaLocalTmp5);
                
                _mochaLocalTmp7 = 0;
                
                length = _mochaLocalTmp6.length;
                
                if (!(_mochaLocalTmp7<length)){
                  
                  _yieldState = -1;
                  break;
                }
              case 1 :
                
                x = _mochaLocalTmp6[_mochaLocalTmp7];
                
                x = testObject[x];
                
                if (x === 200){
                  
                  _yieldState = 2;
                  break;
                } else {
                  
                  _yieldState = 3;
                  break;
                }
              case 2 :
                
                _yieldState = 3;
                return x;
              case 3 :
                
                _yieldState = 4;
                break;
              case 4 :
                
                 ++ _mochaLocalTmp7;
                
                if (_mochaLocalTmp7<length){
                  
                  _yieldState = 1;
                  break;
                } else _yieldState = -1;
              case -1 :
                
                if (_isYieldSafe)return undefined;
                
                Runtime.throwStopIteration();
                
            }
            
          };
      return Runtime.createGenerator(_mochaGenerator,
      function () {
        _yieldState = -1;
      },this);
    }.call(this);
    
    test = function () {
      var _mochaIsNewBorn = true,
          _yieldResult = undefined,
          _yieldState = 0,
          x,
          _mochaLocalTmp8 = keys(testObject),
          _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
            !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler('attempt to send to newborn generator.');
            
            while (1)
            switch (_yieldState) {
              case 0 :
                
                _mochaLocalTmp8 = Runtime.hasIterator(_mochaLocalTmp8)?Runtime.getIterator(_mochaLocalTmp8) : _mochaLocalTmp8;
                
                if (_mochaLocalTmp8.__nothrowNext__){
                  
                  _yieldState = 1;
                  break;
                } else {
                  
                  _yieldState = 7;
                  break;
                }
              case 1 :
                
                if (!((x = _mochaLocalTmp8.__nothrowNext__()))){
                  
                  _yieldState = 6;
                  break;
                }
              case 2 :
                
                if (x === "value2"){
                  
                  _yieldState = 3;
                  break;
                } else {
                  
                  _yieldState = 4;
                  break;
                }
              case 3 :
                
                _yieldState = 4;
                return x;
              case 4 :
                
                _yieldState = 5;
                break;
              case 5 :
                
                if ((x = _mochaLocalTmp8.__nothrowNext__())){
                  
                  _yieldState = 2;
                  break;
                } else _yieldState = 6;
              case 6 :
                
                _yieldState = -1;
                break;
              case 7 :
                
                Runtime.exceptionHandler(23,'..///Users/aono_taketoshi/github/mocha/src/test/js/harmony/generator_expression_test.js','for of statement expect iterator or generator object.');
              case 8 :
              case -1 :
                
                if (_isYieldSafe)return undefined;
                
                Runtime.throwStopIteration();
                
            }
            
          };
      return Runtime.createGenerator(_mochaGenerator,
      function () {
        _yieldState = -1;
      },this);
    }.call(this);
  }();
}();
