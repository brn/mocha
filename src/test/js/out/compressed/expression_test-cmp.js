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
      
      Runtime.assert(true,typeof type === "string","typeof type === \"string\"",43,'./');
      
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
      var __FILE__ = "/var/samba/mocha/src/test/js/262/expression_test.js",
          __LINE__ = 0;
      function primaryTest() {
        try {
          __LINE__ = 342;
          var array = [,,,];
          
          __LINE__ = 343;
          Runtime.assert(true,array.length === 3,"array.length === 3",343,'./expression_test.js');
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }
      function expressionTest() {
        try {
          __LINE__ = 311;
          var exp = function () {
                try {
                  __LINE__ = 312;
                  return 1;
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              }();
          
          __LINE__ = 314;
          Runtime.assert(true,exp === 1,"exp === 1",314,'./expression_test.js');
          
          __LINE__ = 316;
          var a,
              b,
              c;
          
          __LINE__ = 317;
          exp = (a = 0, b = 1, c = 2);
          
          __LINE__ = 318;
          Runtime.assert(true,a === 0,"a === 0",318,'./expression_test.js');
          
          __LINE__ = 319;
          Runtime.assert(true,b === 1,"b === 1",319,'./expression_test.js');
          
          __LINE__ = 320;
          Runtime.assert(true,c === 2,"c === 2",320,'./expression_test.js');
          
          __LINE__ = 321;
          Runtime.assert(true,exp === 2,"exp === 2",321,'./expression_test.js');
          
          __LINE__ = 323;
          !function () {
            try {
              __LINE__ = 324;
              exp = 10;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          }();
          
          __LINE__ = 327;
          Runtime.assert(true,exp === 10,"exp === 10",327,'./expression_test.js');
          
          __LINE__ = 329;
          !function (a,b) {
            try {
              __LINE__ = 330;
              exp = a+b;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          }((function () {
            try {
              __LINE__ = 331;
              return 100;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          })(),function () {
            try {
              __LINE__ = 331;
              return 200;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          }());
          
          __LINE__ = 333;
          Runtime.assert(true,exp === 300,"exp === 300",333,'./expression_test.js');
          
          __LINE__ = 335;
          !function () {
            try {
              __LINE__ = 336;
              exp = 1;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          }();
          
          __LINE__ = 338;
          Runtime.assert(true,exp === 1,"exp === 1",338,'./expression_test.js');
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }
      function memberExpressionTest() {
        try {
          __LINE__ = 295;
          var test =  {
                test2 :  {
                  "@test" :  {
                    0 :  {
                      "1" : function () {
                        try {
                          __LINE__ = 300;
                          return function () {
                            try {
                              __LINE__ = 300;
                              return 1;
                            } catch(e){
                              Runtime.exceptionHandler(__LINE__, __FILE__, e);
                            }
                          };
                        } catch(e){
                          Runtime.exceptionHandler(__LINE__, __FILE__, e);
                        }
                      }
                    }
                  }
                }
              };
          
          __LINE__ = 306;
          Runtime.assert(true,test["test2"]["@test"]["0"]["1"]()() === 1,"test[\"test2\"][\"@test\"][\"0\"][\"1\"]()() === 1",306,'./expression_test.js');
          
          __LINE__ = 307;
          Runtime.assert(true,test.test2["@test"][0]["1"]()() === 1,"test.test2[\"@test\"][0][\"1\"]()() === 1",307,'./expression_test.js');
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }
      function unaryExpressionTest() {
        try {
          __LINE__ = 275;
          var strNum = "1",
              ret = +strNum;
          
          __LINE__ = 277;
          Runtime.assert(true,ret === 1,"ret === 1",277,'./expression_test.js');
          
          __LINE__ = 279;
          ret = -strNum;
          
          __LINE__ = 280;
          Runtime.assert(true,ret === -1,"ret === -1",280,'./expression_test.js');
          
          __LINE__ = 282;
          var num = -5;
          
          __LINE__ = 283;
          ret = ~num;
          
          __LINE__ = 284;
          Runtime.assert(true,ret === 4,"ret === 4",284,'./expression_test.js');
          
          __LINE__ = 286;
          var flg = true;
          
          __LINE__ = 287;
          ret = !flg;
          
          __LINE__ = 288;
          Runtime.assert(true,ret === false,"ret === false",288,'./expression_test.js');
          
          __LINE__ = 290;
          ret = !!flg;
          
          __LINE__ = 291;
          Runtime.assert(true,ret === true,"ret === true",291,'./expression_test.js');
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }
      function postfixExpressionTest() {
        try {
          __LINE__ = 249;
          var add = 0;
          
          __LINE__ = 250;
          add ++ ;
          
          __LINE__ = 251;
          Runtime.assert(true,add === 1,"add === 1",251,'./expression_test.js');
          
          __LINE__ = 253;
          var sub = 1;
          
          __LINE__ = 254;
          sub -- ;
          
          __LINE__ = 255;
          Runtime.assert(true,sub === 0,"sub === 0",255,'./expression_test.js');
          
          __LINE__ = 257;
          add = 0;
          
          __LINE__ = 258;
          sub = add;
          
          __LINE__ = 259;
           ++ sub;
          
          __LINE__ = 260;
          Runtime.assert(true,sub === 1,"sub === 1",260,'./expression_test.js');
          
          __LINE__ = 262;
          add = 1;
          
          __LINE__ = 263;
          sub = add;
          
          __LINE__ = 264;
           -- sub;
          
          __LINE__ = 265;
          Runtime.assert(true,sub === 0,"sub === 0",265,'./expression_test.js');
          
          __LINE__ = 267;
          sub = 1;
          
          __LINE__ = 268;
          sub -- ;
          
          __LINE__ = 269;
          add = sub;
          
          __LINE__ = 270;
          Runtime.assert(true,add === 0,"add === 0",270,'./expression_test.js');
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }
      function binaryExpressionTest() {
        try {
          __LINE__ = 83;
          var item = 100,
              trueValue = true,
              falseValue = false,
              val = 0;
          
          __LINE__ = 88;
          item && trueValue && !falseValue && (val = 1);
          
          __LINE__ = 90;
          Runtime.assert(true,val === 1,"val === 1",90,'./expression_test.js');
          
          __LINE__ = 92;
          ((item && trueValue) || falseValue) && (val = 2);
          
          __LINE__ = 94;
          Runtime.assert(true,val === 2,"val === 2",94,'./expression_test.js');
          
          __LINE__ = 96;
          ((item && falseValue) || !trueValue) && (val = 3);
          
          __LINE__ = 98;
          Runtime.assert(false,val === 3,"val === 3",98,'./expression_test.js');
          
          __LINE__ = 100;
          var changeVal = function (value) {
                try {
                  __LINE__ = 101;
                  val = value;
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              };
          
          __LINE__ = 104;
          (item) && (trueValue) && (!falseValue) && (changeVal(4));
          
          __LINE__ = 105;
          Runtime.assert(true,val === 4,"val === 4",105,'./expression_test.js');
          
          __LINE__ = 107;
          var eq = 0,
              eqVal = 0;
          
          __LINE__ = 110;
          eq == 0 && (eqVal = 1);
          
          __LINE__ = 112;
          Runtime.assert(true,eqVal === 1,"eqVal === 1",112,'./expression_test.js');
          
          __LINE__ = 115;
          eq === 0 && (eqVal = 2);
          
          __LINE__ = 117;
          Runtime.assert(true,eqVal === 2,"eqVal === 2",117,'./expression_test.js');
          
          __LINE__ = 119;
          var bit = 1,
              ret = 0;
          
          __LINE__ = 121;
          ret = bit << 1;
          
          __LINE__ = 122;
          Runtime.assert(true,ret === 2,"ret === 2",122,'./expression_test.js');
          
          __LINE__ = 123;
          ret = bit >> 1;
          
          __LINE__ = 124;
          Runtime.assert(true,ret === 0,"ret === 0",124,'./expression_test.js');
          
          __LINE__ = 125;
          ret = bit|2;
          
          __LINE__ = 126;
          Runtime.assert(true,ret === 3,"ret === 3",126,'./expression_test.js');
          
          __LINE__ = 128;
          bit = 1;
          
          __LINE__ = 129;
          bit <<= 1;
          
          __LINE__ = 130;
          Runtime.assert(true,bit === 2,"bit === 2",130,'./expression_test.js');
          
          __LINE__ = 131;
          bit = 1;
          
          __LINE__ = 132;
          bit >>= 1;
          
          __LINE__ = 133;
          Runtime.assert(true,bit === 0,"bit === 0",133,'./expression_test.js');
          
          __LINE__ = 134;
          bit = 1;
          
          __LINE__ = 135;
          bit |= 2;
          
          __LINE__ = 136;
          Runtime.assert(true,bit === 3,"bit === 3",136,'./expression_test.js');
          
          __LINE__ = 138;
          bit = 10;
          
          __LINE__ = 139;
          ret = bit >>> 2;
          
          __LINE__ = 140;
          Runtime.assert(true,ret === 2,"ret === 2",140,'./expression_test.js');
          
          __LINE__ = 141;
          bit = 10;
          
          __LINE__ = 142;
          bit >>>= 2;
          
          __LINE__ = 143;
          Runtime.assert(true,bit === 2,"bit === 2",143,'./expression_test.js');
          
          __LINE__ = 145;
          bit = 3;
          
          __LINE__ = 146;
          ret = bit&1;
          
          __LINE__ = 147;
          Runtime.assert(true,ret === 1,"ret === 1",147,'./expression_test.js');
          
          __LINE__ = 148;
          bit &= 1;
          
          __LINE__ = 149;
          Runtime.assert(true,bit === 1,"bit === 1",149,'./expression_test.js');
          
          __LINE__ = 151;
          bit = 2;
          
          __LINE__ = 152;
          ret = bit^1;
          
          __LINE__ = 153;
          Runtime.assert(true,ret === 3,"ret === 3",153,'./expression_test.js');
          
          __LINE__ = 154;
          bit = 2;
          
          __LINE__ = 155;
          bit ^= 1;
          
          __LINE__ = 156;
          Runtime.assert(true,bit === 3,"bit === 3",156,'./expression_test.js');
          
          __LINE__ = 158;
          var lt = 0,
              gt = 1,
              cmpVal = 0;
          
          __LINE__ = 163;
          lt>gt && (cmpVal = 1);
          
          __LINE__ = 165;
          Runtime.assert(true,cmpVal === 0,"cmpVal === 0",165,'./expression_test.js');
          
          __LINE__ = 167;
          cmpVal = 0;
          
          __LINE__ = 169;
          lt<gt && (cmpVal = 1);
          
          __LINE__ = 171;
          Runtime.assert(true,cmpVal === 1,"cmpVal === 1",171,'./expression_test.js');
          
          __LINE__ = 173;
          cmpVal = 0;
          
          __LINE__ = 175;
          lt <= gt && (cmpVal = 1);
          
          __LINE__ = 177;
          Runtime.assert(true,cmpVal === 1,"cmpVal === 1",177,'./expression_test.js');
          
          __LINE__ = 179;
          cmpVal = 0;
          
          __LINE__ = 181;
          lt >= gt && (cmpVal = 1);
          
          __LINE__ = 183;
          Runtime.assert(false,cmpVal === 1,"cmpVal === 1",183,'./expression_test.js');
          
          __LINE__ = 185;
          cmpVal = 0;
          
          __LINE__ = 186;
          lt = 1;
          
          __LINE__ = 188;
          lt <= gt && (cmpVal = 1);
          
          __LINE__ = 190;
          Runtime.assert(true,cmpVal === 1,"cmpVal === 1",190,'./expression_test.js');
          
          __LINE__ = 192;
          cmpVal = 1;
          
          __LINE__ = 194;
          lt >= gt && (cmpVal = 1);
          
          __LINE__ = 196;
          Runtime.assert(true,cmpVal === 1,"cmpVal === 1",196,'./expression_test.js');
          
          __LINE__ = 198;
          var pl = 0;
          
          __LINE__ = 199;
          ret = pl+1;
          
          __LINE__ = 200;
          Runtime.assert(true,ret === 1,"ret === 1",200,'./expression_test.js');
          
          __LINE__ = 202;
          var mi = 1;
          
          __LINE__ = 203;
          ret = mi-1;
          
          __LINE__ = 204;
          Runtime.assert(true,ret === 0,"ret === 0",204,'./expression_test.js');
          
          __LINE__ = 206;
          var mul = 1;
          
          __LINE__ = 207;
          ret = mul*2;
          
          __LINE__ = 208;
          Runtime.assert(true,ret === 2,"ret === 2",208,'./expression_test.js');
          
          __LINE__ = 210;
          var div = 2;
          
          __LINE__ = 211;
          ret = div/2;
          
          __LINE__ = 212;
          Runtime.assert(true,ret === 1,"ret === 1",212,'./expression_test.js');
          
          __LINE__ = 214;
          var mod = 3;
          
          __LINE__ = 215;
          ret = mod%2;
          
          __LINE__ = 216;
          Runtime.assert(true,ret === 1,"ret === 1",216,'./expression_test.js');
          
          __LINE__ = 218;
          pl = 0;
          
          __LINE__ = 219;
          pl += 1;
          
          __LINE__ = 220;
          Runtime.assert(true,pl === 1,"pl === 1",220,'./expression_test.js');
          
          __LINE__ = 222;
          mi = 1;
          
          __LINE__ = 223;
          mi -= 1;
          
          __LINE__ = 224;
          Runtime.assert(true,mi === 0,"mi === 0",224,'./expression_test.js');
          
          __LINE__ = 226;
          mul = 1;
          
          __LINE__ = 227;
          mul *= 2;
          
          __LINE__ = 228;
          Runtime.assert(true,mul === 2,"mul === 2",228,'./expression_test.js');
          
          __LINE__ = 230;
          div = 2;
          
          __LINE__ = 231;
          div /= 2;
          
          __LINE__ = 232;
          Runtime.assert(true,div === 1,"div === 1",232,'./expression_test.js');
          
          __LINE__ = 234;
          mod = 3;
          
          __LINE__ = 235;
          mod %= 2;
          
          __LINE__ = 236;
          Runtime.assert(true,mod === 1,"mod === 1",236,'./expression_test.js');
          
          __LINE__ = 238;
          var obj =  {
                'onmouseenter' : 1,
                'onmouseleave' : 1
              },
              testInAnd = 'onmouseenter' in obj && 'onmouseleave' in obj;
          
          __LINE__ = 245;
          Runtime.assert(true,testInAnd === true,"testInAnd === true",245,'./expression_test.js');
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }
      function callExpressionTest() {
        try {
          __LINE__ = 63;
          var highFn = function () {
                try {
                  __LINE__ = 64;
                  return function () {
                    try {
                      __LINE__ = 65;
                      return function () {
                        try {
                          __LINE__ = 66;
                          return true;
                        } catch(e){
                          Runtime.exceptionHandler(__LINE__, __FILE__, e);
                        }
                      };
                    } catch(e){
                      Runtime.exceptionHandler(__LINE__, __FILE__, e);
                    }
                  };
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              };
          
          __LINE__ = 70;
          Runtime.assert(true,highFn()()() === true,"highFn()()() === true",70,'./expression_test.js');
          
          __LINE__ = 71;
          highFn = function () {
            try {
              __LINE__ = 71;
              return inner1;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          };
          
          __LINE__ = 72;
          var inner1 = function () {
                try {
                  __LINE__ = 72;
                  return inner2;
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              },
              inner2 = function (){},
              flg = 1,
              instance = new ((flg)?highFn : inner1);
          
          __LINE__ = 76;
          Runtime.assert(true,instance === inner1,"instance === inner1",76,'./expression_test.js');
          
          __LINE__ = 77;
          var flg2 = 0;
          
          __LINE__ = 78;
          instance = new ((flg2)?highFn : inner1);
          
          __LINE__ = 79;
          Runtime.assert(true,instance === inner2,"instance === inner2",79,'./expression_test.js');
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }
      function objectAndNewTest() {
        try {
          __LINE__ = 19;
          var testObject = {};
          
          __LINE__ = 20;
          testObject.testProp = {};
          
          __LINE__ = 21;
          testObject.testProp.testProp = {};
          
          __LINE__ = 22;
          testObject.testProp.testProp.testProp = {};
          
          __LINE__ = 23;
          testObject.testFn = function () {
            try {
              __LINE__ = 23;
              return true;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          };
          
          __LINE__ = 24;
          testObject.testProp.testFn = function () {
            try {
              __LINE__ = 24;
              return false;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          };
          
          __LINE__ = 25;
          testObject.testProp.testProp.testFn = function () {
            try {
              __LINE__ = 25;
              return 2;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          };
          
          __LINE__ = 27;
          Runtime.assert(true,testObject.testFn() === true,"testObject.testFn() === true",27,'./expression_test.js');
          
          __LINE__ = 28;
          Runtime.assert(true,testObject.testProp.testFn() === false,"testObject.testProp.testFn() === false",28,'./expression_test.js');
          
          __LINE__ = 29;
          Runtime.assert(true,testObject.testProp.testProp.testFn() === 2,"testObject.testProp.testProp.testFn() === 2",29,'./expression_test.js');
          
          __LINE__ = 31;
          var highFn = function () {
                try {
                  __LINE__ = 31;
                  return inner1;
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              },
              inner1 = function () {
                try {
                  __LINE__ = 32;
                  return inner2;
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              },
              inner2 = function (){},
              instance = new highFn(),
              instance2 = new new highFn(),
              instance3 = new new new highFn();
          
          __LINE__ = 37;
          Runtime.assert(true,instance === inner1,"instance === inner1",37,'./expression_test.js');
          
          __LINE__ = 38;
          Runtime.assert(true,instance2 === inner2,"instance2 === inner2",38,'./expression_test.js');
          
          __LINE__ = 39;
          Runtime.assert(true,instance3 instanceof inner2,"instance3 instanceof inner2",39,'./expression_test.js');
          
          __LINE__ = 41;
          var fnObj =  {
                highFn : highFn,
                highFnInner :  {
                  highFn : highFn
                }
              },
              instance4 = new fnObj.highFn(),
              instance5 = new new fnObj.highFn(),
              instance6 = new new new fnObj.highFn();
          
          __LINE__ = 51;
          Runtime.assert(true,instance4 === inner1,"instance4 === inner1",51,'./expression_test.js');
          
          __LINE__ = 52;
          Runtime.assert(true,instance5 === inner2,"instance5 === inner2",52,'./expression_test.js');
          
          __LINE__ = 53;
          Runtime.assert(true,instance6 instanceof inner2,"instance6 instanceof inner2",53,'./expression_test.js');
          
          __LINE__ = 54;
          var instance7 = new fnObj.highFnInner.highFn(),
              instance8 = new new fnObj.highFnInner.highFn(),
              instance9 = new new new fnObj.highFnInner.highFn();
          
          __LINE__ = 57;
          Runtime.assert(true,instance7 === inner1,"instance7 === inner1",57,'./expression_test.js');
          
          __LINE__ = 58;
          Runtime.assert(true,instance8 === inner2,"instance8 === inner2",58,'./expression_test.js');
          
          __LINE__ = 59;
          Runtime.assert(true,instance9 instanceof inner2,"instance9 instanceof inner2",59,'./expression_test.js');
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }
      function parseTest() {
        try {
          __LINE__ = 3;
          var x = 2.000000;
          
          __LINE__ = 4;
          Runtime.assert(true,x === 2,"x === 2",4,'./expression_test.js');
          
          __LINE__ = 6;
          x = function () {
            try {
              __LINE__ = 7;
              return 2.000000;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          };
          
          __LINE__ = 9;
          Runtime.assert(true,x() === 2,"x() === 2",9,'./expression_test.js');
          
          __LINE__ = 11;
          x = function () {
            try {
              __LINE__ = 12;
              return /aaa/;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          };
          
          __LINE__ = 14;
          Runtime.assert(true,Object.prototype.toString.call(x()) === "[object RegExp]","Object.prototype.toString.call(x()) === \"[object RegExp]\"",14,'./expression_test.js');
          
          __LINE__ = 15;
          Runtime.assert(true,/aaa/.test("aaa") === true,"/aaa/.test(\"aaa\") === true",15,'./expression_test.js');
          
          __LINE__ = 16;
          Runtime.assert(true,.200*10 === 2,".200*10 === 2",16,'./expression_test.js');
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }
      __LINE__ = 2;
      _mochaGlobalExport['./expression_test.js'] = {};
      
      __LINE__ = 3;
      var _mochaGlobalAlias = _mochaGlobalExport['./expression_test.js'];
      
      __LINE__ = 1;
      /aaaa/.test("aaaa");
      
      __LINE__ = 346;
      parseTest();
      
      __LINE__ = 347;
      objectAndNewTest();
      
      __LINE__ = 348;
      callExpressionTest();
      
      __LINE__ = 349;
      binaryExpressionTest();
      
      __LINE__ = 350;
      postfixExpressionTest();
      
      __LINE__ = 351;
      unaryExpressionTest();
      
      __LINE__ = 352;
      memberExpressionTest();
      
      __LINE__ = 353;
      expressionTest();
      
      __LINE__ = 354;
      primaryTest();
    } catch(e){
      Runtime.exceptionHandler(__LINE__, __FILE__, e);
    }
  }();
}();
