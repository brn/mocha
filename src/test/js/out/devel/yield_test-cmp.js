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
    _mochaGlobalExport['-759650552-yield_test.js'] = {};
    
    var _mochaGlobalAlias = _mochaGlobalExport['-759650552-yield_test.js'],
        generator,
        tests =  {
          case1 : function () {
            function yieldTest2() {
              var _mochaIsNewBorn = true;
              
              var _yieldResult = undefined;
              
              var _yieldState = 0;
              
              var i;
              
              var i;
              
              var _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                    if (!_isYieldSend){
                      
                      _mochaIsNewBorn = false;
                    } else if (_isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined){
                      
                      Runtime.exceptionHandler('attempt to send to newborn generator.');
                    }
                    
                    while (1){
                      switch (_yieldState) {
                        case 0 :
                          
                          i = 0;
                          
                          i = 0;
                          
                          if (!(i<10)){
                            
                            _yieldState = -1;
                            break;
                          }
                        case 1 :
                          
                          _yieldState = 2;
                          return i;
                        case 2 :
                          
                          i ++ ;
                          
                          if (i<10){
                            
                            _yieldState = 1;
                            break;
                          } else {
                            
                            _yieldState = -1;
                          }
                        case -1 :
                          
                          if (_isYieldSafe)return undefined;
                           else Runtime.throwStopIteration();
                          
                      }
                      
                    }
                    
                  };
              return Runtime.createGenerator(_mochaGenerator,
              function () {
                _yieldState = -1;
              },this);
            }
            generator = yieldTest2();
          },
          case2 : function () {
            function yieldTest3() {
              var _mochaIsNewBorn = true;
              
              var _yieldResult = undefined;
              
              var _yieldState = 0;
              
              var i;
              
              var i;
              
              var _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                    if (!_isYieldSend){
                      
                      _mochaIsNewBorn = false;
                    } else if (_isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined){
                      
                      Runtime.exceptionHandler('attempt to send to newborn generator.');
                    }
                    
                    while (1){
                      switch (_yieldState) {
                        case 0 :
                          
                          i = 0;
                          
                          i = 0;
                          
                          if (!(i<10)){
                            
                            _yieldState = -1;
                            break;
                          }
                        case 1 :
                          
                          if (i%2 === 0){
                            
                            _yieldState = 2;
                            break;
                          } else {
                            
                            _yieldState = 3;
                            break;
                          }
                        case 2 :
                          
                          _yieldState = 3;
                          return i;
                        case 3 :
                          
                          _yieldState = 4;
                          break;
                        case 4 :
                          
                          i ++ ;
                          
                          if (i<10){
                            
                            _yieldState = 1;
                            break;
                          } else {
                            
                            _yieldState = -1;
                          }
                        case -1 :
                          
                          if (_isYieldSafe)return undefined;
                           else Runtime.throwStopIteration();
                          
                      }
                      
                    }
                    
                  };
              return Runtime.createGenerator(_mochaGenerator,
              function () {
                _yieldState = -1;
              },this);
            }
            generator = yieldTest3();
          },
          case3 : function () {
            function yieldTest4() {
              var _mochaIsNewBorn = true;
              
              var _yieldResult = undefined;
              
              var _yieldState = 0;
              
              var j;
              
              var i;
              
              var j;
              
              var i;
              
              var _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                    if (!_isYieldSend){
                      
                      _mochaIsNewBorn = false;
                    } else if (_isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined){
                      
                      Runtime.exceptionHandler('attempt to send to newborn generator.');
                    }
                    
                    while (1){
                      switch (_yieldState) {
                        case 0 :
                          
                          i = 0;
                          
                          i = 0;
                          
                          if (!(i<10)){
                            
                            _yieldState = -1;
                            break;
                          }
                        case 1 :
                          
                          j = 0;
                          
                          j = 0;
                          
                          if (!(j<10)){
                            
                            _yieldState = 6;
                            break;
                          }
                        case 2 :
                          
                          if (j%2 === 0){
                            
                            _yieldState = 3;
                            break;
                          } else {
                            
                            _yieldState = 4;
                            break;
                          }
                        case 3 :
                          
                          _yieldState = 4;
                          return j;
                        case 4 :
                          
                          _yieldState = 5;
                          break;
                        case 5 :
                          
                          j ++ ;
                          
                          if (j<10){
                            
                            _yieldState = 2;
                            break;
                          } else {
                            
                            _yieldState = 6;
                          }
                        case 6 :
                          
                          i ++ ;
                          
                          if (i<10){
                            
                            _yieldState = 1;
                            break;
                          } else {
                            
                            _yieldState = -1;
                          }
                        case -1 :
                          
                          if (_isYieldSafe)return undefined;
                           else Runtime.throwStopIteration();
                          
                      }
                      
                    }
                    
                  };
              return Runtime.createGenerator(_mochaGenerator,
              function () {
                _yieldState = -1;
              },this);
            }
            generator = yieldTest4();
          },
          case4 : function () {
            function yieldTest5() {
              var _mochaIsNewBorn = true;
              
              var _yieldResult = undefined;
              
              var _yieldState = 0;
              
              var i;
              
              var _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                    if (!_isYieldSend){
                      
                      _mochaIsNewBorn = false;
                    } else if (_isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined){
                      
                      Runtime.exceptionHandler('attempt to send to newborn generator.');
                    }
                    
                    while (1){
                      switch (_yieldState) {
                        case 0 :
                          
                          i = 0;
                          
                          if (!( ++ i<10)){
                            
                            _yieldState = -1;
                            break;
                          }
                        case 1 :
                          
                          _yieldState = 2;
                          return i;
                        case 2 :
                          
                          if ( ++ i<10){
                            
                            _yieldState = 1;
                            break;
                          } else {
                            
                            _yieldState = -1;
                          }
                        case -1 :
                          
                          if (_isYieldSafe)return undefined;
                           else Runtime.throwStopIteration();
                          
                      }
                      
                    }
                    
                  };
              return Runtime.createGenerator(_mochaGenerator,
              function () {
                _yieldState = -1;
              },this);
            }
            generator = yieldTest5();
          },
          case5 : function () {
            function yieldTest6() {
              var _mochaIsNewBorn = true;
              
              var _yieldResult = undefined;
              
              var _yieldState = 0;
              
              var i;
              
              var _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                    if (!_isYieldSend){
                      
                      _mochaIsNewBorn = false;
                    } else if (_isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined){
                      
                      Runtime.exceptionHandler('attempt to send to newborn generator.');
                    }
                    
                    while (1){
                      switch (_yieldState) {
                        case 0 :
                          
                          i = 0;
                        case 1 :
                          
                          _yieldState = 2;
                          return i;
                        case 2 :
                          
                          if ( ++ i<10){
                            
                            _yieldState = 1;
                            break;
                          } else {
                            
                            _yieldState = 3;
                          }
                        case 3 :
                        case -1 :
                          
                          if (_isYieldSafe)return undefined;
                           else Runtime.throwStopIteration();
                          
                      }
                      
                    }
                    
                  };
              return Runtime.createGenerator(_mochaGenerator,
              function () {
                _yieldState = -1;
              },this);
            }
            generator = yieldTest6();
          },
          case6 : function () {
            function yieldTest7() {
              var _mochaIsNewBorn = true;
              
              var _yieldResult = undefined;
              
              var _yieldState = 0;
              
              var i;
              
              var m;
              
              var i;
              
              var _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                    if (!_isYieldSend){
                      
                      _mochaIsNewBorn = false;
                    } else if (_isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined){
                      
                      Runtime.exceptionHandler('attempt to send to newborn generator.');
                    }
                    
                    while (1){
                      switch (_yieldState) {
                        case 0 :
                          
                          i = 0;
                          
                          i = 0;
                          
                          if (!(i<10)){
                            
                            _yieldState = -1;
                            break;
                          }
                        case 1 :
                          
                          _yieldState = 2;
                          return i;
                        case 2 :
                          
                          _yieldResult = _isYieldSend && arguments.length>2?Runtime.toArray(arguments,2)[0] : _isYieldSend?i : undefined;
                          
                          m = _yieldResult;
                          
                          if (m === true){
                            
                            _yieldState = 3;
                            break;
                          } else {
                            
                            _yieldState = 5;
                            break;
                          }
                        case 3 :
                          
                          _yieldState = 4;
                          return i+1;
                        case 4 :
                          
                          _yieldState = 9;
                          break;
                        case 5 :
                          
                          if (m === false){
                            
                            _yieldState = 6;
                            break;
                          } else {
                            
                            _yieldState = 8;
                            break;
                          }
                        case 6 :
                          
                          _yieldState = 7;
                          return i-1;
                        case 7 :
                          
                          _yieldState = 9;
                          break;
                        case 8 :
                          
                          _yieldState = 9;
                          return i;
                        case 9 :
                          
                          i ++ ;
                          
                          if (i<10){
                            
                            _yieldState = 1;
                            break;
                          } else {
                            
                            _yieldState = -1;
                          }
                        case -1 :
                          
                          if (_isYieldSafe)return undefined;
                           else Runtime.throwStopIteration();
                          
                      }
                      
                    }
                    
                  };
              return Runtime.createGenerator(_mochaGenerator,
              function () {
                _yieldState = -1;
              },this);
            }
            generator = yieldTest7();
          },
          case7 : function () {
            function yieldTest8() {
              var _mochaIsNewBorn = true;
              
              var _yieldResult = undefined;
              
              var _yieldState = 0;
              
              var j;
              
              var i;
              
              var j;
              
              var m;
              
              var i;
              
              var _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                    if (!_isYieldSend){
                      
                      _mochaIsNewBorn = false;
                    } else if (_isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined){
                      
                      Runtime.exceptionHandler('attempt to send to newborn generator.');
                    }
                    
                    while (1){
                      switch (_yieldState) {
                        case 0 :
                          
                          i = 0;
                          
                          i = 0;
                          
                          if (!(i<10)){
                            
                            _yieldState = -1;
                            break;
                          }
                        case 1 :
                          
                          _yieldState = 2;
                          return i;
                        case 2 :
                          
                          _yieldResult = _isYieldSend && arguments.length>2?Runtime.toArray(arguments,2)[0] : _isYieldSend?i : undefined;
                          
                          m = _yieldResult;
                          
                          j = 0;
                          
                          j = 0;
                          
                          if (!(j<10)){
                            
                            _yieldState = 11;
                            break;
                          }
                        case 3 :
                          
                          if (m === true){
                            
                            _yieldState = 4;
                            break;
                          } else {
                            
                            _yieldState = 6;
                            break;
                          }
                        case 4 :
                          
                          _yieldState = 5;
                          return j*2;
                        case 5 :
                          
                          _yieldState = 10;
                          break;
                        case 6 :
                          
                          if (m === false){
                            
                            _yieldState = 7;
                            break;
                          } else {
                            
                            _yieldState = 9;
                            break;
                          }
                        case 7 :
                          
                          _yieldState = 8;
                          return j/2;
                        case 8 :
                          
                          _yieldState = 10;
                          break;
                        case 9 :
                          
                          _yieldState = 10;
                          return j;
                        case 10 :
                          
                          j ++ ;
                          
                          if (j<10){
                            
                            _yieldState = 3;
                            break;
                          } else {
                            
                            _yieldState = 11;
                          }
                        case 11 :
                          
                          i ++ ;
                          
                          if (i<10){
                            
                            _yieldState = 1;
                            break;
                          } else {
                            
                            _yieldState = -1;
                          }
                        case -1 :
                          
                          if (_isYieldSafe)return undefined;
                           else Runtime.throwStopIteration();
                          
                      }
                      
                    }
                    
                  };
              return Runtime.createGenerator(_mochaGenerator,
              function () {
                _yieldState = -1;
              },this);
            }
            generator = yieldTest8();
          },
          case8 : function () {
            function yieldTest9() {
              var _mochaIsNewBorn = true;
              
              var _yieldResult = undefined;
              
              var _yieldState = 0;
              
              var j;
              
              var i;
              
              var m;
              
              var j;
              
              var i;
              
              var _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                    if (!_isYieldSend){
                      
                      _mochaIsNewBorn = false;
                    } else if (_isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined){
                      
                      Runtime.exceptionHandler('attempt to send to newborn generator.');
                    }
                    
                    while (1){
                      switch (_yieldState) {
                        case 0 :
                          
                          i = 0;
                          
                          i = 0;
                          
                          if (!(i<10)){
                            
                            _yieldState = -1;
                            break;
                          }
                        case 1 :
                          
                          j = 0;
                          
                          j = 0;
                          
                          if (!(j<10)){
                            
                            _yieldState = 11;
                            break;
                          }
                        case 2 :
                          
                          _yieldState = 3;
                          return i;
                        case 3 :
                          
                          _yieldResult = _isYieldSend && arguments.length>2?Runtime.toArray(arguments,2)[0] : _isYieldSend?i : undefined;
                          
                          m = _yieldResult;
                          
                          if (m === true){
                            
                            _yieldState = 4;
                            break;
                          } else {
                            
                            _yieldState = 6;
                            break;
                          }
                        case 4 :
                          
                          _yieldState = 5;
                          return j*2;
                        case 5 :
                          
                          _yieldState = 10;
                          break;
                        case 6 :
                          
                          if (m === false){
                            
                            _yieldState = 7;
                            break;
                          } else {
                            
                            _yieldState = 9;
                            break;
                          }
                        case 7 :
                          
                          _yieldState = 8;
                          return j/2;
                        case 8 :
                          
                          _yieldState = 10;
                          break;
                        case 9 :
                          
                          _yieldState = 10;
                          return j;
                        case 10 :
                          
                          j ++ ;
                          
                          if (j<10){
                            
                            _yieldState = 2;
                            break;
                          } else {
                            
                            _yieldState = 11;
                          }
                        case 11 :
                          
                          i ++ ;
                          
                          if (i<10){
                            
                            _yieldState = 1;
                            break;
                          } else {
                            
                            _yieldState = -1;
                          }
                        case -1 :
                          
                          if (_isYieldSafe)return undefined;
                           else Runtime.throwStopIteration();
                          
                      }
                      
                    }
                    
                  };
              return Runtime.createGenerator(_mochaGenerator,
              function () {
                _yieldState = -1;
              },this);
            }
            generator = yieldTest9();
          },
          case9 : function () {
            function yieldTest10() {
              var _mochaIsNewBorn = true;
              
              var _yieldResult = undefined;
              
              var _yieldState = 0;
              
              var _mochaFinallyCache;
              
              var _mochaCatchCache;
              
              var i;
              
              var m;
              
              var i;
              
              var flg;
              
              var _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                    if (!_isYieldSend){
                      
                      _mochaIsNewBorn = false;
                    } else if (_isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined){
                      
                      Runtime.exceptionHandler('attempt to send to newborn generator.');
                    }
                    
                    while (1)try {
                      switch (_yieldState) {
                        case 0 :
                          
                          flg = false;
                          
                          i = 0;
                          
                          i = 0;
                          
                          if (!(i<10)){
                            
                            _yieldState = -1;
                            break;
                          }
                        case 1 :
                          
                          _yieldState = 2;
                          
                          _mochaCatchCache = function (e) {
                            _yieldState = 3;
                          };
                          
                          _mochaFinallyCache = function () {
                            flg = true
                          };
                          
                          m = (flg)?1 : 0;
                          return m;
                        case 2 :
                          
                          ddddd();
                          
                          _mochaCatchCache = undefined;
                          
                          _mochaFinallyCache = undefined;
                        case 3 :
                          
                          i ++ ;
                          
                          if (i<10){
                            
                            _yieldState = 1;
                            break;
                          } else {
                            
                            _yieldState = -1;
                          }
                        case -1 :
                          
                          if (_isYieldSafe)return undefined;
                           else Runtime.throwStopIteration();
                          
                      }
                      
                    } catch(_mochaException){
                      if (_mochaCatchCache){
                        
                        var _mochaLocalTmp0 = _mochaCatchCache(_mochaException);
                        
                        if (_mochaLocalTmp0 !== undefined){
                          return _mochaLocalTmp0;
                        }
                        
                      } else Runtime.throwException(_mochaException);
                    } finally {
                      if (_mochaFinallyCache){
                        
                        var _mochaLocalTmp1 = _mochaFinallyCache();
                        
                        if (_mochaLocalTmp1 !== undefined){
                          return _mochaLocalTmp1;
                        }
                        
                      }
                      
                    }
                    
                  };
              return Runtime.createGenerator(_mochaGenerator,
              function () {
                _yieldState = -1;
                
                if (_mochaFinallyCache)_mochaFinallyCache();
              },this);
            }
            generator = yieldTest10();
          },
          case10 : function () {
            function yieldTest11() {
              var _mochaIsNewBorn = true;
              
              var _yieldResult = undefined;
              
              var _yieldState = 0;
              
              var i;
              
              var type;
              
              var i;
              
              var _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                    if (!_isYieldSend){
                      
                      _mochaIsNewBorn = false;
                    } else if (_isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined){
                      
                      Runtime.exceptionHandler('attempt to send to newborn generator.');
                    }
                    
                    while (1){
                      switch (_yieldState) {
                        case 0 :
                          
                          i = 0;
                          
                          i = 0;
                          
                          if (!(i<10)){
                            
                            _yieldState = -1;
                            break;
                          }
                        case 1 :
                          
                          _yieldState = 2;
                          return ;
                        case 2 :
                          
                          _yieldResult = _isYieldSend && arguments.length>2?Runtime.toArray(arguments,2)[0] : undefined;
                          
                          type = _yieldResult;
                          
                          switch (type) {
                            case 0 :
                              
                              _yieldState = 3;
                              break;
                            case 2 :
                              
                              _yieldState = 4;
                              break;
                            case 3 :
                              
                              _yieldState = 5;
                              break;
                            default :
                              
                              _yieldState = 6;
                              break;
                              
                          }
                          break;
                        case 3 :
                          
                          _yieldState = 7;
                          return 200;
                        case 4 :
                          
                          _yieldState = 7;
                          return 400;
                        case 5 :
                          
                          _yieldState = 7;
                          return 600;
                        case 6 :
                          
                          _yieldState = 7;
                          return 700;
                        case 7 :
                          
                          i ++ ;
                          
                          if (i<10){
                            
                            _yieldState = 1;
                            break;
                          } else {
                            
                            _yieldState = -1;
                          }
                        case -1 :
                          
                          if (_isYieldSafe)return undefined;
                           else Runtime.throwStopIteration();
                          
                      }
                      
                    }
                    
                  };
              return Runtime.createGenerator(_mochaGenerator,
              function () {
                _yieldState = -1;
              },this);
            }
            generator = yieldTest11();
            
            generator.next();
            
            generator.next();
            
            generator.next();
            
            generator.next();
          },
          case11 : function () {
            function yieldTest12() {
              var _mochaIsNewBorn = true;
              
              var _yieldResult = undefined;
              
              var _yieldState = 0;
              
              var i;
              
              var type;
              
              var i;
              
              var _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                    if (!_isYieldSend){
                      
                      _mochaIsNewBorn = false;
                    } else if (_isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined){
                      
                      Runtime.exceptionHandler('attempt to send to newborn generator.');
                    }
                    
                    while (1){
                      switch (_yieldState) {
                        case 0 :
                          
                          i = 0;
                          
                          i = 0;
                          
                          if (!(i<15)){
                            
                            _yieldState = -1;
                            break;
                          }
                        case 1 :
                          
                          _yieldState = 2;
                          return ;
                        case 2 :
                          
                          _yieldResult = _isYieldSend && arguments.length>2?Runtime.toArray(arguments,2)[0] : undefined;
                          
                          type = _yieldResult;
                          
                          switch (type) {
                            case 4 :
                            case 0 :
                              
                              _yieldState = 3;
                              break;
                            case 5 :
                              
                              _yieldState = 7;
                              break;
                            case 6 :
                            case 2 :
                              
                              _yieldState = 4;
                              break;
                            case 3 :
                              
                              _yieldState = 5;
                              break;
                            default :
                              
                              _yieldState = 6;
                              break;
                              
                          }
                          break;
                        case 3 :
                          
                          _yieldState = 8;
                          return 200;
                        case 4 :
                          
                          _yieldState = 8;
                          return 400;
                        case 5 :
                          
                          _yieldState = 8;
                          return 600;
                        case 6 :
                          
                          _yieldState = 8;
                          return 700;
                        case 7 :
                          
                          _yieldState = 8;
                          break;
                        case 8 :
                          
                          i ++ ;
                          
                          if (i<15){
                            
                            _yieldState = 1;
                            break;
                          } else {
                            
                            _yieldState = -1;
                          }
                        case -1 :
                          
                          if (_isYieldSafe)return undefined;
                           else Runtime.throwStopIteration();
                          
                      }
                      
                    }
                    
                  };
              return Runtime.createGenerator(_mochaGenerator,
              function () {
                _yieldState = -1;
              },this);
            }
            generator = yieldTest12();
            
            generator.next();
            
            generator.next();
            
            generator.next();
            
            generator.next();
            
            generator.next();
          },
          case12 : function () {
            function yieldTest13() {
              var _mochaIsNewBorn = true;
              
              var _yieldResult = undefined;
              
              var _yieldState = 0;
              
              var length;
              
              var _mochaLocalTmp4;
              
              var i;
              
              var obj;
              
              var _mochaLocalTmp3 = [];
              
              var _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                    if (!_isYieldSend){
                      
                      _mochaIsNewBorn = false;
                    } else if (_isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined){
                      
                      Runtime.exceptionHandler('attempt to send to newborn generator.');
                    }
                    
                    while (1){
                      switch (_yieldState) {
                        case 0 :
                          
                          obj =  {
                            x : 200,
                            y : 300,
                            z : 400
                          };
                          
                          for (var _mochaLocalTmp2 in obj)
                          _mochaLocalTmp3.push(_mochaLocalTmp2);
                          
                          _mochaLocalTmp4 = 0;
                          
                          length = _mochaLocalTmp3.length;
                          
                          if (!(_mochaLocalTmp4<length)){
                            
                            _yieldState = -1;
                            break;
                          }
                        case 1 :
                          
                          _yieldState = 2;
                          
                          i = _mochaLocalTmp3[_mochaLocalTmp4];
                          return [i,obj[i]];
                        case 2 :
                          
                           ++ _mochaLocalTmp4;
                          
                          if (_mochaLocalTmp4<length){
                            
                            _yieldState = 1;
                            break;
                          } else {
                            
                            _yieldState = -1;
                          }
                        case -1 :
                          
                          if (_isYieldSafe)return undefined;
                           else Runtime.throwStopIteration();
                          
                      }
                      
                    }
                    
                  };
              return Runtime.createGenerator(_mochaGenerator,
              function () {
                _yieldState = -1;
              },this);
            }
            generator = yieldTest13();
            
            var ret = generator.next();
            
            ret = generator.next();
            
            ret = generator.next();
          },
          case13 : function () {
            function keys(obj) {
              var _mochaIsNewBorn = true;
              
              var _yieldResult = undefined;
              
              var _yieldState = 0;
              
              var length;
              
              var _mochaLocalTmp7;
              
              var prop;
              
              var _mochaLocalTmp6 = [];
              
              var _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                    if (!_isYieldSend){
                      
                      _mochaIsNewBorn = false;
                    } else if (_isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined){
                      
                      Runtime.exceptionHandler('attempt to send to newborn generator.');
                    }
                    
                    while (1){
                      switch (_yieldState) {
                        case 0 :
                          
                          for (var _mochaLocalTmp5 in obj)
                          _mochaLocalTmp6.push(_mochaLocalTmp5);
                          
                          _mochaLocalTmp7 = 0;
                          
                          length = _mochaLocalTmp6.length;
                          
                          if (!(_mochaLocalTmp7<length)){
                            
                            _yieldState = -1;
                            break;
                          }
                        case 1 :
                          
                          prop = _mochaLocalTmp6[_mochaLocalTmp7];
                          
                          if (obj.hasOwnProperty(prop)){
                            
                            _yieldState = 2;
                            break;
                          } else {
                            
                            _yieldState = 3;
                            break;
                          }
                        case 2 :
                          
                          _yieldState = 3;
                          return prop;
                        case 3 :
                          
                          _yieldState = 4;
                          break;
                        case 4 :
                          
                           ++ _mochaLocalTmp7;
                          
                          if (_mochaLocalTmp7<length){
                            
                            _yieldState = 1;
                            break;
                          } else {
                            
                            _yieldState = -1;
                          }
                        case -1 :
                          
                          if (_isYieldSafe)return undefined;
                           else Runtime.throwStopIteration();
                          
                      }
                      
                    }
                    
                  };
              return Runtime.createGenerator(_mochaGenerator,
              function () {
                _yieldState = -1;
              },this);
            }
            var testObject =  {
                  value1 : 1,
                  value2 : 2,
                  value3 : 3,
                  value4 : 4
                };
            
            try {
              
              var itemGen = keys(testObject);
            } catch(e){
              
            }
            
          }
        };
    
    for (var i = 1;i<13;i ++ )
    tests["case"+i]();
  }();
}();
