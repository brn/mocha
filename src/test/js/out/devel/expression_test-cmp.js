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
      var __FILE__ = "Y:/mocha/src/test/js/262/expression_test.js",
          __LINE__ = 0;
      function primaryTest() {
        try {
          __LINE__ = 342;
          var array = [,,,];
          
          __LINE__ = 343;
          Runtime.assert(true,array.length,"array.length",343,'./expression_test.js');
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
          Runtime.assert(true,exp,"exp",314,'./expression_test.js');
          
          __LINE__ = 316;
          var a,
              b,
              c;
          
          __LINE__ = 317;
          exp = (a = 0, b = 1, c = 2);
          
          __LINE__ = 318;
          Runtime.assert(true,a,"a",318,'./expression_test.js');
          
          __LINE__ = 319;
          Runtime.assert(true,b,"b",319,'./expression_test.js');
          
          __LINE__ = 320;
          Runtime.assert(true,c,"c",320,'./expression_test.js');
          
          __LINE__ = 321;
          Runtime.assert(true,exp,"exp",321,'./expression_test.js');
          
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
          Runtime.assert(true,exp,"exp",327,'./expression_test.js');
          
          __LINE__ = 329;
          !function (a,b) {
            try {
              __LINE__ = 330;
              exp = a;
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
          Runtime.assert(true,exp,"exp",333,'./expression_test.js');
          
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
          Runtime.assert(true,exp,"exp",338,'./expression_test.js');
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
          Runtime.assert(true,test["test2"]["@test"]["0"]["1"]()(),"test[\"test2\"][\"@test\"][\"0\"][\"1\"]()()",306,'./expression_test.js');
          
          __LINE__ = 307;
          Runtime.assert(true,test.test2["@test"][0]["1"]()(),"test.test2[\"@test\"][0][\"1\"]()()",307,'./expression_test.js');
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
          Runtime.assert(true,ret,"ret",277,'./expression_test.js');
          
          __LINE__ = 279;
          ret = -strNum;
          
          __LINE__ = 280;
          Runtime.assert(true,ret,"ret",280,'./expression_test.js');
          
          __LINE__ = 282;
          var num = -5;
          
          __LINE__ = 283;
          ret = ~num;
          
          __LINE__ = 284;
          Runtime.assert(true,ret,"ret",284,'./expression_test.js');
          
          __LINE__ = 286;
          var flg = true;
          
          __LINE__ = 287;
          ret = !flg;
          
          __LINE__ = 288;
          Runtime.assert(true,ret,"ret",288,'./expression_test.js');
          
          __LINE__ = 290;
          ret = !!flg;
          
          __LINE__ = 291;
          Runtime.assert(true,ret,"ret",291,'./expression_test.js');
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
          Runtime.assert(true,add,"add",251,'./expression_test.js');
          
          __LINE__ = 253;
          var sub = 1;
          
          __LINE__ = 254;
          sub -- ;
          
          __LINE__ = 255;
          Runtime.assert(true,sub,"sub",255,'./expression_test.js');
          
          __LINE__ = 257;
          add = 0;
          
          __LINE__ = 258;
          sub = add;
          
          __LINE__ = 259;
           ++ sub;
          
          __LINE__ = 260;
          Runtime.assert(true,sub,"sub",260,'./expression_test.js');
          
          __LINE__ = 262;
          add = 1;
          
          __LINE__ = 263;
          sub = add;
          
          __LINE__ = 264;
           -- sub;
          
          __LINE__ = 265;
          Runtime.assert(true,sub,"sub",265,'./expression_test.js');
          
          __LINE__ = 267;
          sub = 1;
          
          __LINE__ = 268;
          sub -- ;
          
          __LINE__ = 269;
          add = sub;
          
          __LINE__ = 270;
          Runtime.assert(true,add,"add",270,'./expression_test.js');
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
          item && (val = 1);
          
          __LINE__ = 90;
          Runtime.assert(true,val,"val",90,'./expression_test.js');
          
          __LINE__ = 92;
          (item) && (val = 2);
          
          __LINE__ = 94;
          Runtime.assert(true,val,"val",94,'./expression_test.js');
          
          __LINE__ = 96;
          (item) && (val = 3);
          
          __LINE__ = 98;
          Runtime.assert(false,val,"val",98,'./expression_test.js');
          
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
          (item);
          
          __LINE__ = 105;
          Runtime.assert(true,val,"val",105,'./expression_test.js');
          
          __LINE__ = 107;
          var eq = 0,
              eqVal = 0;
          
          __LINE__ = 110;
          eq && (eqVal = 1);
          
          __LINE__ = 112;
          Runtime.assert(true,eqVal,"eqVal",112,'./expression_test.js');
          
          __LINE__ = 115;
          eq && (eqVal = 2);
          
          __LINE__ = 117;
          Runtime.assert(true,eqVal,"eqVal",117,'./expression_test.js');
          
          __LINE__ = 119;
          var bit = 1,
              ret = 0;
          
          __LINE__ = 121;
          ret = bit;
          
          __LINE__ = 122;
          Runtime.assert(true,ret,"ret",122,'./expression_test.js');
          
          __LINE__ = 123;
          ret = bit;
          
          __LINE__ = 124;
          Runtime.assert(true,ret,"ret",124,'./expression_test.js');
          
          __LINE__ = 125;
          ret = bit;
          
          __LINE__ = 126;
          Runtime.assert(true,ret,"ret",126,'./expression_test.js');
          
          __LINE__ = 128;
          bit = 1;
          
          __LINE__ = 129;
          bit <<= 1;
          
          __LINE__ = 130;
          Runtime.assert(true,bit,"bit",130,'./expression_test.js');
          
          __LINE__ = 131;
          bit = 1;
          
          __LINE__ = 132;
          bit >>= 1;
          
          __LINE__ = 133;
          Runtime.assert(true,bit,"bit",133,'./expression_test.js');
          
          __LINE__ = 134;
          bit = 1;
          
          __LINE__ = 135;
          bit |= 2;
          
          __LINE__ = 136;
          Runtime.assert(true,bit,"bit",136,'./expression_test.js');
          
          __LINE__ = 138;
          bit = 10;
          
          __LINE__ = 139;
          ret = bit;
          
          __LINE__ = 140;
          Runtime.assert(true,ret,"ret",140,'./expression_test.js');
          
          __LINE__ = 141;
          bit = 10;
          
          __LINE__ = 142;
          bit >>>= 2;
          
          __LINE__ = 143;
          Runtime.assert(true,bit,"bit",143,'./expression_test.js');
          
          __LINE__ = 145;
          bit = 3;
          
          __LINE__ = 146;
          ret = bit;
          
          __LINE__ = 147;
          Runtime.assert(true,ret,"ret",147,'./expression_test.js');
          
          __LINE__ = 148;
          bit &= 1;
          
          __LINE__ = 149;
          Runtime.assert(true,bit,"bit",149,'./expression_test.js');
          
          __LINE__ = 151;
          bit = 2;
          
          __LINE__ = 152;
          ret = bit;
          
          __LINE__ = 153;
          Runtime.assert(true,ret,"ret",153,'./expression_test.js');
          
          __LINE__ = 154;
          bit = 2;
          
          __LINE__ = 155;
          bit ^= 1;
          
          __LINE__ = 156;
          Runtime.assert(true,bit,"bit",156,'./expression_test.js');
          
          __LINE__ = 158;
          var lt = 0,
              gt = 1,
              cmpVal = 0;
          
          __LINE__ = 163;
          lt && (cmpVal = 1);
          
          __LINE__ = 165;
          Runtime.assert(true,cmpVal,"cmpVal",165,'./expression_test.js');
          
          __LINE__ = 167;
          cmpVal = 0;
          
          __LINE__ = 169;
          lt && (cmpVal = 1);
          
          __LINE__ = 171;
          Runtime.assert(true,cmpVal,"cmpVal",171,'./expression_test.js');
          
          __LINE__ = 173;
          cmpVal = 0;
          
          __LINE__ = 175;
          lt && (cmpVal = 1);
          
          __LINE__ = 177;
          Runtime.assert(true,cmpVal,"cmpVal",177,'./expression_test.js');
          
          __LINE__ = 179;
          cmpVal = 0;
          
          __LINE__ = 181;
          lt && (cmpVal = 1);
          
          __LINE__ = 183;
          Runtime.assert(false,cmpVal,"cmpVal",183,'./expression_test.js');
          
          __LINE__ = 185;
          cmpVal = 0;
          
          __LINE__ = 186;
          lt = 1;
          
          __LINE__ = 188;
          lt && (cmpVal = 1);
          
          __LINE__ = 190;
          Runtime.assert(true,cmpVal,"cmpVal",190,'./expression_test.js');
          
          __LINE__ = 192;
          cmpVal = 1;
          
          __LINE__ = 194;
          lt && (cmpVal = 1);
          
          __LINE__ = 196;
          Runtime.assert(true,cmpVal,"cmpVal",196,'./expression_test.js');
          
          __LINE__ = 198;
          var pl = 0;
          
          __LINE__ = 199;
          ret = pl;
          
          __LINE__ = 200;
          Runtime.assert(true,ret,"ret",200,'./expression_test.js');
          
          __LINE__ = 202;
          var mi = 1;
          
          __LINE__ = 203;
          ret = mi;
          
          __LINE__ = 204;
          Runtime.assert(true,ret,"ret",204,'./expression_test.js');
          
          __LINE__ = 206;
          var mul = 1;
          
          __LINE__ = 207;
          ret = mul;
          
          __LINE__ = 208;
          Runtime.assert(true,ret,"ret",208,'./expression_test.js');
          
          __LINE__ = 210;
          var div = 2;
          
          __LINE__ = 211;
          ret = div;
          
          __LINE__ = 212;
          Runtime.assert(true,ret,"ret",212,'./expression_test.js');
          
          __LINE__ = 214;
          var mod = 3;
          
          __LINE__ = 215;
          ret = mod;
          
          __LINE__ = 216;
          Runtime.assert(true,ret,"ret",216,'./expression_test.js');
          
          __LINE__ = 218;
          pl = 0;
          
          __LINE__ = 219;
          pl += 1;
          
          __LINE__ = 220;
          Runtime.assert(true,pl,"pl",220,'./expression_test.js');
          
          __LINE__ = 222;
          mi = 1;
          
          __LINE__ = 223;
          mi -= 1;
          
          __LINE__ = 224;
          Runtime.assert(true,mi,"mi",224,'./expression_test.js');
          
          __LINE__ = 226;
          mul = 1;
          
          __LINE__ = 227;
          mul *= 2;
          
          __LINE__ = 228;
          Runtime.assert(true,mul,"mul",228,'./expression_test.js');
          
          __LINE__ = 230;
          div = 2;
          
          __LINE__ = 231;
          div /= 2;
          
          __LINE__ = 232;
          Runtime.assert(true,div,"div",232,'./expression_test.js');
          
          __LINE__ = 234;
          mod = 3;
          
          __LINE__ = 235;
          mod %= 2;
          
          __LINE__ = 236;
          Runtime.assert(true,mod,"mod",236,'./expression_test.js');
          
          __LINE__ = 238;
          var obj =  {
                'onmouseenter' : 1,
                'onmouseleave' : 1
              },
              testInAnd = 'onmouseenter';
          
          __LINE__ = 245;
          Runtime.assert(true,testInAnd,"testInAnd",245,'./expression_test.js');
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
          Runtime.assert(true,highFn()()(),"highFn()()()",70,'./expression_test.js');
          
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
          Runtime.assert(true,instance,"instance",76,'./expression_test.js');
          
          __LINE__ = 77;
          var flg2 = 0;
          
          __LINE__ = 78;
          instance = new ((flg2)?highFn : inner1);
          
          __LINE__ = 79;
          Runtime.assert(true,instance,"instance",79,'./expression_test.js');
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
          Runtime.assert(true,testObject.testFn(),"testObject.testFn()",27,'./expression_test.js');
          
          __LINE__ = 28;
          Runtime.assert(true,testObject.testProp.testFn(),"testObject.testProp.testFn()",28,'./expression_test.js');
          
          __LINE__ = 29;
          Runtime.assert(true,testObject.testProp.testProp.testFn(),"testObject.testProp.testProp.testFn()",29,'./expression_test.js');
          
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
          Runtime.assert(true,instance,"instance",37,'./expression_test.js');
          
          __LINE__ = 38;
          Runtime.assert(true,instance2,"instance2",38,'./expression_test.js');
          
          __LINE__ = 39;
          Runtime.assert(true,instance3,"instance3",39,'./expression_test.js');
          
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
          Runtime.assert(true,instance4,"instance4",51,'./expression_test.js');
          
          __LINE__ = 52;
          Runtime.assert(true,instance5,"instance5",52,'./expression_test.js');
          
          __LINE__ = 53;
          Runtime.assert(true,instance6,"instance6",53,'./expression_test.js');
          
          __LINE__ = 54;
          var instance7 = new fnObj.highFnInner.highFn(),
              instance8 = new new fnObj.highFnInner.highFn(),
              instance9 = new new new fnObj.highFnInner.highFn();
          
          __LINE__ = 57;
          Runtime.assert(true,instance7,"instance7",57,'./expression_test.js');
          
          __LINE__ = 58;
          Runtime.assert(true,instance8,"instance8",58,'./expression_test.js');
          
          __LINE__ = 59;
          Runtime.assert(true,instance9,"instance9",59,'./expression_test.js');
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }
      function parseTest() {
        try {
          __LINE__ = 3;
          var x = .200;
          
          __LINE__ = 4;
          Runtime.assert(true,x,"x",4,'./expression_test.js');
          
          __LINE__ = 6;
          x = function () {
            try {
              __LINE__ = 7;
              return .200;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          };
          
          __LINE__ = 9;
          Runtime.assert(true,x(),"x()",9,'./expression_test.js');
          
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
          Runtime.assert(true,Object.prototype.toString.call(x()),"Object.prototype.toString.call(x())",14,'./expression_test.js');
          
          __LINE__ = 15;
          Runtime.assert(true,/aaa/.test("aaa"),"/aaa/.test(\"aaa\")",15,'./expression_test.js');
          
          __LINE__ = 16;
          Runtime.assert(true,.200,".200",16,'./expression_test.js');
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
