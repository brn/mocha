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
  
  function Tuple() {
    var args = Runtime.toArray(arguments,0);
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
      var __FILE__ = "-1075407889-class_test.js",
          __LINE__ = 0;
      __LINE__ = 2;
      _mochaGlobalExport['-1075407889-class_test.js'] = {};
      
      __LINE__ = 3;
      var _mochaGlobalAlias = _mochaGlobalExport['-1075407889-class_test.js'],
          Monster = function () {
            try {
              function constructor(name,health) {
                try {
                  __LINE__ = 8;
                  this.name = name;
                  
                  __LINE__ = 9;
                  Runtime.getPrivateRecord(this).health = health;
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              }
              function Monster() {
                try {
                  __LINE__ = 1;
                  Runtime.initializeClass(this,Monster,_mochaPrivateHolder,constructor,arguments,'Monster',1);
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              }
              __LINE__ = 1;
              var _mochaPrivateHolder = function (){};
              
              __LINE__ = 7;
              Runtime.createUnenumProp(constructor,"__harmony_class__",1);
              
              __LINE__ = 15;
              Monster.prototype.attack = function (target) {
                try {
                  __LINE__ = 16;
                  log('The monster attacks '+target);
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              };
              
              __LINE__ = 22;
              Monster.prototype.isAlive = function () {
                try {
                  __LINE__ = 23;
                  return Runtime.getPrivateRecord(this).health>0;
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              };
              
              __LINE__ = 27;
              Monster.prototype.health = function (value) {
                try {
                  __LINE__ = 28;
                  if (value<0){
                    __LINE__ = 29;
                    throw new Error('Health must be non-negative.');
                  }
                  
                  __LINE__ = 31;
                  Runtime.getPrivateRecord(this).health = value;
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              };
              
              __LINE__ = 38;
              Monster.prototype.numAttacks = 0;
              
              __LINE__ = 43;
              Runtime.constant(Monster.prototype,'attackMessage','The monster hits you!');
              
              __LINE__ = 44;
              Runtime.constant(Monster,'DEFAULT_LIFE',100);
              
              __LINE__ = 1;
              Runtime.createUnenumProp(Monster.prototype,"constructor",constructor);
              __LINE__ = 1;
              return Monster;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          }(),
          monster = new Monster("slime",100);
      
      __LINE__ = 48;
      Runtime.assert(true,monster.isAlive(),"monster.isAlive()",48,'class_test.js');
      
      __LINE__ = 49;
      Runtime.assert(0,monster.numAttacks,"monster.numAttacks",49,'class_test.js');
      
      __LINE__ = 50;
      Runtime.assert(100,Monster.DEFAULT_LIFE,"Monster.DEFAULT_LIFE",50,'class_test.js');
      
      __LINE__ = 51;
      Runtime.assert(undefined,Monster.health,"Monster.health",51,'class_test.js');
      
      __LINE__ = 52;
      var BaseTest = function () {
            try {
              function constructor(_mochaLocalTmp0,_mochaLocalTmp1,_mochaLocalTmp2) {
                try {
                  __LINE__ = 53;
                  Runtime.getPrivateRecord(this).name = _mochaLocalTmp0 || "foo";
                  
                  __LINE__ = 53;
                  Runtime.getPrivateRecord(this).addr = _mochaLocalTmp1 || "tokyo";
                  
                  __LINE__ = 53;
                  Runtime.getPrivateRecord(this).age = _mochaLocalTmp2;
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              }
              function BaseTest() {
                try {
                  __LINE__ = 52;
                  Runtime.initializeClass(this,BaseTest,_mochaPrivateHolder,constructor,arguments,'BaseTest',52);
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              }
              __LINE__ = 52;
              var _mochaPrivateHolder = function (){};
              
              __LINE__ = 53;
              Runtime.createUnenumProp(constructor,"__harmony_class__",1);
              
              __LINE__ = 54;
              BaseTest.prototype.getName = function () {
                try {
                  __LINE__ = 54;
                  return Runtime.getPrivateRecord(this).name;
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              };
              
              __LINE__ = 52;
              Runtime.createUnenumProp(BaseTest.prototype,"constructor",constructor);
              __LINE__ = 52;
              return BaseTest;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          }(),
          DeriveTest = function () {
            try {
              function constructor() {
                try {
                  __LINE__ = 58;
                  return _mochaSuper.constructor.call(this);
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              }
              function DeriveTest() {
                try {
                  __LINE__ = 57;
                  Runtime.initializeClass(this,DeriveTest,_mochaPrivateHolder,constructor,arguments,'DeriveTest',57);
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              }
              __LINE__ = 57;
              var _mochaPrivateHolder = function (){};
              
              __LINE__ = 57;
              var _mochaLocalTmp3 = BaseTest;
              
              __LINE__ = 57;
              Runtime.extendClass(DeriveTest,_mochaLocalTmp3);
              
              __LINE__ = 57;
              var _mochaSuper = Runtime.getSuper(_mochaLocalTmp3);
              
              __LINE__ = 58;
              Runtime.createUnenumProp(constructor,"__harmony_class__",1);
              
              __LINE__ = 59;
              DeriveTest.prototype.getName = function () {
                try {
                  __LINE__ = 59;
                  return _mochaSuper.getName.call(this);
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              };
              
              __LINE__ = 57;
              Runtime.createUnenumProp(DeriveTest.prototype,"constructor",constructor);
              __LINE__ = 57;
              return DeriveTest;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          }(),
          Derive2 = function () {
            try {
              function constructor() {
                try {
                  __LINE__ = 64;
                  return _mochaSuper.constructor.call(this);
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              }
              function Derive2() {
                try {
                  __LINE__ = 63;
                  Runtime.initializeClass(this,Derive2,_mochaPrivateHolder,constructor,arguments,'Derive2',63);
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              }
              __LINE__ = 63;
              var _mochaPrivateHolder = function (){};
              
              __LINE__ = 63;
              var _mochaLocalTmp4 = DeriveTest;
              
              __LINE__ = 63;
              Runtime.extendClass(Derive2,_mochaLocalTmp4);
              
              __LINE__ = 63;
              var _mochaSuper = Runtime.getSuper(_mochaLocalTmp4);
              
              __LINE__ = 64;
              Runtime.createUnenumProp(constructor,"__harmony_class__",1);
              
              __LINE__ = 65;
              Derive2.prototype.getAddr = function () {
                try {
                  __LINE__ = 65;
                  return Runtime.getPrivateRecord(this).addr;
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              };
              
              __LINE__ = 63;
              Runtime.createUnenumProp(Derive2.prototype,"constructor",constructor);
              __LINE__ = 63;
              return Derive2;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          }(),
          Drive3 = function () {
            try {
              function constructor() {
                try {
                  __LINE__ = 71;
                  _mochaSuper.constructor.call(this,200,'tokyo',20);
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              }
              function Drive3() {
                try {
                  __LINE__ = 69;
                  Runtime.initializeClass(this,Drive3,_mochaPrivateHolder,constructor,arguments,'Drive3',69);
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              }
              __LINE__ = 69;
              var _mochaPrivateHolder = function (){};
              
              __LINE__ = 69;
              var _mochaLocalTmp5 = BaseTest;
              
              __LINE__ = 69;
              Runtime.extendPrototype(Drive3,_mochaLocalTmp5);
              
              __LINE__ = 69;
              var _mochaSuper = Runtime.getSuper(_mochaLocalTmp5);
              
              __LINE__ = 70;
              Runtime.createUnenumProp(constructor,"__harmony_class__",1);
              
              __LINE__ = 69;
              Runtime.createUnenumProp(Drive3.prototype,"constructor",constructor);
              __LINE__ = 69;
              return Drive3;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          }(),
          TestClass = function () {
            try {
              function constructor(_mochaLocalTmp7,_mochaLocalTmp8) {
                try {
                  __LINE__ = 76;
                  Runtime.getPrivateRecord(this)._name = _mochaLocalTmp7 || "test";
                  
                  __LINE__ = 76;
                  Runtime.getPrivateRecord(this)._age = _mochaLocalTmp8 || 20;
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              }
              function _mochaLocalTmp6() {
                try {
                  __LINE__ = 75;
                  Runtime.initializeClass(this,_mochaLocalTmp6,_mochaPrivateHolder,constructor,arguments,'_mochaLocalTmp6',75);
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              }
              __LINE__ = 75;
              var _mochaPrivateHolder = function (){};
              
              __LINE__ = 76;
              Runtime.createUnenumProp(constructor,"__harmony_class__",1);
              
              __LINE__ = 77;
              _mochaLocalTmp6.prototype.getName = function () {
                try {
                  __LINE__ = 77;
                  return Runtime.getPrivateRecord(this)._name;
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              };
              
              __LINE__ = 78;
              _mochaLocalTmp6.prototype.getAge = function () {
                try {
                  __LINE__ = 78;
                  return Runtime.getPrivateRecord(this)._age;
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              };
              
              __LINE__ = 75;
              Runtime.createUnenumProp(_mochaLocalTmp6.prototype,"constructor",constructor);
              __LINE__ = 75;
              return _mochaLocalTmp6;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          }();
      
      __LINE__ = 84;
      Runtime.assert(true,new DeriveTest().getName() === "foo","new DeriveTest().getName() === \"foo\"",84,'class_test.js');
      
      __LINE__ = 85;
      Runtime.assert(true,new Derive2().getAddr() === "tokyo","new Derive2().getAddr() === \"tokyo\"",85,'class_test.js');
      
      __LINE__ = 86;
      var instance = new TestClass();
      
      __LINE__ = 87;
      Runtime.assert(true,instance.getName() === "test","instance.getName() === \"test\"",87,'class_test.js');
      
      __LINE__ = 88;
      Runtime.assert(true,instance.getAge() === 20,"instance.getAge() === 20",88,'class_test.js');
      
      __LINE__ = 90;
      var TestTrait =  {
            _mochaTraitPrivate : {},
            _mochaTraitPublic :  {
              testm1 : function testm1() {
                try {
                  __LINE__ = 92;
                  var arg = Runtime.toArray(arguments,0);
                  __LINE__ = 92;
                  return arg[0];
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              }
            },
            _mochaRequires :  {
              doTestm1 : true
            },
            _mochaTraitMark : true
          },
          TestTrait2 =  {
            _mochaTraitPrivate : {},
            _mochaTraitPublic :  {
              testm2 : function testm2() {
                try {
                  __LINE__ = 97;
                  var arg = Runtime.toArray(arguments,0);
                  __LINE__ = 97;
                  return arg[0];
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              },
              testm3 : function testm3() {
                try {
                  __LINE__ = 98;
                  return "ok";
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              }
            },
            _mochaRequires :  {
              doTestm2 : true
            },
            _mochaTraitMark : true
          },
          MixinTest = function () {
            try {
              function constructor(){}
              function MixinTest() {
                try {
                  __LINE__ = 101;
                  Runtime.initializeClass(this,MixinTest,_mochaPrivateHolder,constructor,arguments,'MixinTest',101);
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              }
              __LINE__ = 101;
              var _mochaPrivateHolder = function (){};
              
              __LINE__ = 101;
              Runtime.createUnenumProp(constructor,"__harmony_class__",1);
              
              __LINE__ = 102;
              MixinTest.prototype.doTestm1 = function () {
                try {
                  __LINE__ = 102;
                  return "aaa";
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              };
              
              __LINE__ = 103;
              MixinTest.prototype.doTestm2 = function () {
                try {
                  __LINE__ = 103;
                  return "bbb";
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              };
              
              __LINE__ = 0;
              Runtime.classMixin(MixinTest,_mochaPrivateHolder,TestTrait, {
                testm1 : "m1"
              },{});
              
              __LINE__ = 0;
              Runtime.classMixin(MixinTest,_mochaPrivateHolder,TestTrait2,{}, {
                testm2 : true,
                testm3 : true
              });
              
              __LINE__ = 101;
              Runtime.checkRequirements(MixinTest,_mochaPrivateHolder,[TestTrait,TestTrait2],'class_test.js',105);
              
              __LINE__ = 101;
              Runtime.createUnenumProp(MixinTest.prototype,"constructor",constructor);
              __LINE__ = 101;
              return MixinTest;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          }(),
          instance2 = new MixinTest();
      
      __LINE__ = 108;
      Runtime.assert(true,instance2.m1("foo") === "foo","instance2.m1(\"foo\") === \"foo\"",108,'class_test.js');
      
      __LINE__ = 109;
      Runtime.assert(true,instance2.m2 === undefined,"instance2.m2 === undefined",109,'class_test.js');
      
      __LINE__ = 112;
      var Box = function () {
            try {
              function constructor(_mochaLocalTmp9,_mochaLocalTmp10) {
                try {
                  __LINE__ = 113;
                  Runtime.getPrivateRecord(this).width = _mochaLocalTmp9 || 100;
                  
                  __LINE__ = 113;
                  Runtime.getPrivateRecord(this).height = _mochaLocalTmp10 || 100;
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              }
              function Box() {
                try {
                  __LINE__ = 112;
                  Runtime.initializeClass(this,Box,_mochaPrivateHolder,constructor,arguments,'Box',112);
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              }
              __LINE__ = 112;
              var _mochaPrivateHolder = function (){};
              
              __LINE__ = 113;
              Runtime.createUnenumProp(constructor,"__harmony_class__",1);
              
              __LINE__ = 114;
              Box.prototype.height = function () {
                try {
                  __LINE__ = 114;
                  return Runtime.getPrivateRecord(this).height;
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              };
              
              __LINE__ = 115;
              Box.prototype.width = function () {
                try {
                  __LINE__ = 115;
                  return Runtime.getPrivateRecord(this).width;
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              };
              
              __LINE__ = 116;
              var _mochaLocalTmp11 =  {
                    type : 200,
                    _max : 400
                  };
              
              __LINE__ = 116;
              _mochaPrivateHolder.prototype._type = _mochaLocalTmp11._type;
              
              __LINE__ = 116;
              _mochaPrivateHolder.prototype._max = _mochaLocalTmp11._max;
              
              __LINE__ = 112;
              Runtime.createUnenumProp(Box.prototype,"constructor",constructor);
              __LINE__ = 112;
              return Box;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          }(),
          inst = new Box();
      
      __LINE__ = 120;
      Runtime.assert(true,inst.height() === 100,"inst.height() === 100",120,'class_test.js');
      
      __LINE__ = 121;
      Runtime.assert(true,inst.width() === 100,"inst.width() === 100",121,'class_test.js');
    } catch(e){
      Runtime.exceptionHandler(__LINE__, __FILE__, e);
    }
  }();
}();
