!function() {
  var __FILE__ = "__Runtime",
      __LINE__ = 0;
  
  var global = (this !==  null )?this : typeof window === 'object'?window : {},
      __Runtime =  {
        _global : global,
        _push : Array.prototype.push,
        _slice : Array.prototype.slice,
        getErrorMessage : function (e) {
          return (e.message)?e.message : (e.description)?e.description : e.toString();
        },
        isStopIteration : (function () {
          
          function isStopIteration(obj) {
            return obj === __Runtime.StopIteration || rstopIteration.test(obj);
          }
          var rstopIteration = /StopIteration/;
          return isStopIteration;
        })(),
        throwException : function (exception) {
          try {
            throw exception;
          } catch(e){
            
            if (__Runtime.isStopIteration(e)){
              throw new Error(e);
            } else {
              throw new Error(this.getErrorMessage(e));
            }
            
          }
          
        },
        createUnenumProp : function (obj,prop,value) {
          return Object.defineProperty(obj,prop, {
            configurable :  true ,
            enumerable :  false ,
            writable :  true ,
            value : value
          });
        },
        constant : function (obj,prop,value) {
          return Object.defineProperty(obj,prop, {
            configurable :  false ,
            enumerable :  false ,
            writable :  false ,
            value : value
          });
        },
        toArray : function (likeArray,index) {
          return (likeArray)?this._slice.call(likeArray,index) : [];
        },
        extend : function (dest,source) {
          for (var prop in source){
            
            dest[prop] = source[prop];
          }
          return dest;
        }
      };
  
  !function () {
    !function (_mochaLocalTmp0,_mochaLocalTmp1,_mochaLocalTmp2,_mochaLocalTmp3) {
      function defineBuiltin(obj,name,value) {
        return Object.defineProperty(obj,name, {
          value : value,
          configurable :  true ,
          enumerable :  false ,
          writable :  true 
        });
      }
      function callbackCheck(callback,type) {
        
        __Runtime.assert( true ,typeof type === "string","typeof type === \"string\"",40,'_prototype.js');
        
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
                configurable :  false ,
                writable :  false ,
                enumerable :  false ,
                value : 0
              });
              
              obj.test = 200;
              
              ret = (obj.test === 200)? false  :  true ;
            } catch(e){
              return ret =  false ;
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
              return this !==  null  && this !== global && this instanceof ret?ret.context.apply(this,args) : ret.context.apply(context,args);
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
        
        this ===  null  && builtinTypeError("Array.forEach : this is null or not defined");
        
        if (that){
          while ((ta = this[ ++ iter]) !==  null  && ta !== undefined){
            callback.call(that,ta,iter,this);
          }
          
        } else {
          while ((ta = this[ ++ iter]) !==  null  && ta !== undefined){
            callback(ta,iter,this);
          }
          
        }
        
      });
      
      !arrayProto.every && defineBuiltin(arrayProto,"every",
      function (callback,that) {
        callbackCheck(callback,"Array.every");
        
        var iter = -1,
            ta;
        
        this ===  null  && builtinTypeError("Array.every : this is null or not defined");
        
        if (that){
          while ((ta = this[ ++ iter]) !==  null  && ta !== undefined){
            if (!(callback.call(that,ta,iter,this))){
              return  false ;
            }
            
          }
          
        } else {
          while ((ta = this[ ++ iter]) !==  null  && ta !== undefined){
            if (!(callback(ta,iter,this))){
              return  false ;
            }
            
          }
          
        }
        return  true ;
      });
      
      !arrayProto.some && defineBuiltin(arrayProto,"some",
      function (callback,that) {
        callbackCheck(callback,"Array.some");
        
        var iter = -1,
            ta;
        
        this ===  null  && builtinTypeError("Array.some : this is null or not defined");
        
        if (that){
          while ((ta = this[ ++ iter]) !==  null  && ta !== undefined){
            if (callback.call(that,ta,iter,this)){
              return  true ;
            }
            
          }
          
        } else {
          while ((ta = this[ ++ iter]) !==  null  && ta !== undefined){
            if (callback(ta,iter,this)){
              return  true ;
            }
            
          }
          
        }
        return  false ;
      });
      
      !arrayProto.filter && defineBuiltin(arrayProto,"filter",
      function (callback,that) {
        callbackCheck(callback,"Array.filter");
        
        var len = this.length,
            iter = -1,
            ret = [],
            ta;
        
        this ===  null  && builtinTypeError("Array.filter : this is null or not defined");
        
        if (that){
          for (var i = 0,len = this.length;i<len; ++ i){
            
            (ta = this[i]) !==  null  && ta !== undefined && callback.call(that,ta,i,this) && (ret[ ++ iter] = ta);
          }
          
        } else {
          for (var i = 0,len = this.length;i<len; ++ i){
            
            (ta = this[i]) !==  null  && ta !== undefined && callback(ta,i,this) && (ret[ ++ iter] = ta);
          }
          
        }
        return ret;
      });
      
      !arrayProto.indexOf && defineBuiltin(arrayProto,"indexOf",
      function (subject,fromIndex) {
        var iter = (fromIndex)?fromIndex-1 : -1,
            index = -1,
            ta;
        
        this ===  null  && builtinTypeError("Array.indexOf : this is null or not defined.");
        
        while ((ta = this[ ++ iter]) !==  null  && ta !== undefined){
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
        
        this ===  null  && builtinTypeError("Array.lastIndexOf : this is null or not defined.");
        
        while ((ta = this[ -- iter]) !==  null  && ta !== undefined){
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
        
        this ===  null  && builtinTypeError("Array.map : this is null or not defined.");
        
        if (that){
          for (i;i<len; ++ i){
            (ta = this[i]) !==  null  && ta !== undefined && (ret[ ++ iter] = callback.call(that,ta,i,this));
          }
          
        } else {
          for (i;i<len; ++ i){
            (ta = this[i]) !==  null  && ta !== undefined && (ret[ ++ iter] = callback(ta,i,this));
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
        
        (len === 0 || len ===  null ) && arguments.length<2 && builtinTypeError("Array length is 0 and no second argument");
        
        for (i;i<len; ++ i){
          (ta = this[i]) !==  null  && ta !== undefined && (ret = callback(ret,ta,i,this));
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
        
        (len === 0 || len ===  null ) && arguments.length<2 && builtinTypeError("Array length is 0 and no second argument");
        
        for (i;i>-1; -- i){
          (ta = this[i]) !==  null  && ta !== undefined && (ret = callback(ret,ta,i,this));
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
          return  false ;
        }
        return (arr)?({}).toString.call(arr) === "[object Array]" :  false ;
      });
    }.call(this,String,Array,Function,Date);
  }.call(this);
  
  __Runtime.extend(__Runtime, {
    traitMixin : function (dest,source,with_,without) {
      if (!dest._mochaTraitMark || !source._mochaTraitMark){
        
        __Runtime.throwException("mixin only used for trait.");
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
      
    },
    classMixin : function (_mochaLocalTmp0,_mochaLocalTmp1,_mochaLocalTmp2,with_,without) {
      var constructorProto = _mochaLocalTmp0.prototype,
          privateProto = _mochaLocalTmp1.prototype,
          mark = _mochaLocalTmp2._mochaTraitMark,
          traitPublic = _mochaLocalTmp2._mochaTraitPublic,
          traitPrivate = _mochaLocalTmp2._mochaTraitPrivate;
      
      if (!mark){
        
        __Runtime.throwException("mixin only used for trait.");
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
      
    },
    checkRequirements : function (_mochaLocalTmp3,_mochaLocalTmp4,traits,file,line) {
      var proto1 = _mochaLocalTmp3.prototype,
          proto2 = _mochaLocalTmp4.prototype;
      
      for (var i = 0,len = traits.length;i<len;i ++ ){
        
        var _mochaLocalTmp5 = traits[i],
            _mochaRequires = _mochaLocalTmp5._mochaRequires;
        
        for (var prop in _mochaRequires){
          
          if (!(prop in proto1) && !(prop in proto2)){
            
            __Runtime.throwException("Class dose not meet the traits requirement. traits require implementation of property "+prop+"\nin file "+file+" at line "+line);
          }
          
        }
        
      }
      
    }
  });
  
  __Runtime.extend(__Runtime, {
    Exception : function (line,file,e) {
      this.toString = function () {
        return __Runtime.getErrorMessage(e)+" in file "+file+" at : "+line;
      };
    },
    exceptionHandler : function (line,file,e) {
      if (__Runtime.isStopIteration(e)){
        
        this.throwException(e);
      } else {
        
        this.throwException(new this.Exception(line,file,e));
      }
      
    }
  });
  
  !function () {
    var getPrototype = ("getPrototypeOf" in Object)?function (obj) {
          return Object.getPrototypeOf(obj);
        } : function (obj) {
          var ret = {};
          
          for (var i in obj){
            
            !obj.hasOwnProperty(i) && (ret[i] = obj[i]);
          }
          return ret;
        },
        privateRecord,
        createPrivateRecord,
        getPrivateRecord,
        getInstanceBody;
    
    if ("WeakMap" in __Runtime._global){
      
      privateRecord = new WeakMap();
      
      createPrivateRecord = function (self,privateHolder,constructor) {
        var holder = new privateHolder;
        
        __Runtime.createUnenumProp(holder,"__is_private__",1);
        
        Rutnime.createUnenumProp(self,"constructor",constructor);
        
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
          
          __Runtime.createUnenumProp(constructor,"__private__",holder);
          
          __Runtime.createUnenumProp(self,"constructor",constructor);
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
    
    var hasProto = '__proto__' in {};
    return __Runtime.extend(__Runtime, {
      extendClass : (hasProto)?function (derived,base) {
        if (typeof base === 'function'){
          
          derived.prototype.__proto__ = base.prototype;
          
          for (var i in base){
            
            if (i !== 'prototype'){
              
              derived[i] = base[i];
            }
            
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
            
            if (i !== 'prototype'){
              
              derived[i] = base[i];
            }
            
          }
          
        } else {
          
          var inherit = function (){},
              proto = getPrototype(base);
          
          inherit.prototype = proto;
          
          derived.prototype = new inherit;
        }
        
      },
      extendPrototype : function (derived,base) {
        derived.prototype = base;
      },
      getPrivateRecord : getPrivateRecord,
      getInstanceBody : getInstanceBody,
      initializeClass : function (instance,classObject,privateHolder,constructor,args,name,line) {
        if (!instance || !(instance instanceof classObject)){
          
          throwException("class "+name+" must be called by new. line : "+line);
        }
        
        createPrivateRecord(instance,privateHolder,constructor);
        
        constructor.apply(instance,args);
      },
      getSuper : function (obj) {
        var type = typeof obj,
            ret;
        
        if (type === "function"){
          
          ret = function (){};
          
          ret.prototype = obj.prototype;
          
          ret = new ret();
          
          if (obj.__harmony_class__){
            
            ret.constructor = obj.constructor;
          } else {
            
            ret.constructor = obj;
          }
          return ret;
        }
        return ret;
      }
    });
  }();
  
  !function () {
    __Runtime.extend(__Runtime, {
      assert : (__Runtime._global.console && __Runtime._global.console.assert)?function (expect,exp,str,line,filename) {
        return __Runtime._global.console.assert(expect === exp,"assertion failed : "+str+"\nexpect "+expect+" but got "+exp+"\nin file "+filename+" at : "+line);
      } : function (expect,exp,str,line,filename) {
        if (expect !== exp){
          
          __Runtime.throwException("assertion failed : "+str+"\nexpect "+expect+" but got "+exp+"\nin file "+filename+" at : "+line);
        }
        
      }
    });
  }.call(this);
  
  __LINE__ = 0;
  !function () {
    try {
      var __FILE__ = "-839149963-class_test.js",
          __LINE__ = 0;
      __LINE__ = 1;
      var Monster = function () {
            function constructor(name,health) {
              try {
                __LINE__ = 8;
                this.name = name;
                
                __LINE__ = 9;
                __Runtime.getPrivateRecord(this).health = health;
              } catch(__mocha_error){
                __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
              }
            }
            function Monster() {
              try {
                __LINE__ = 1;
                __Runtime.initializeClass(this,Monster,_mochaPrivateHolder,constructor,arguments,'Monster',1);
              } catch(__mocha_error){
                __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
              }
            }
            try {
              
              __LINE__ = 1;
              var _mochaPrivateHolder = function (){};
              
              __LINE__ = 7;
              __Runtime.createUnenumProp(constructor,"__harmony_class__",1);
              
              __LINE__ = 15;
              Monster.prototype.attack = function (target) {
                try {
                  __LINE__ = 16;
                  log('The monster attacks '+target);
                } catch(__mocha_error){
                  __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
                }
              };
              
              __LINE__ = 22;
              Monster.prototype.isAlive = function () {
                try {
                  __LINE__ = 23;
                  return __Runtime.getPrivateRecord(this).health>0;
                } catch(__mocha_error){
                  __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
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
                  __Runtime.getPrivateRecord(this).health = value;
                } catch(__mocha_error){
                  __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
                }
              };
              
              __LINE__ = 38;
              Monster.prototype.numAttacks = 0;
              
              __LINE__ = 43;
              __Runtime.constant(Monster.prototype,'attackMessage','The monster hits you!');
              
              __LINE__ = 44;
              __Runtime.constant(Monster,'DEFAULT_LIFE',100);
              
              __LINE__ = 1;
              __Runtime.createUnenumProp(Monster.prototype,"constructor",constructor);
              __LINE__ = 1;
              return Monster;
            } catch(__mocha_error){
              __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
            }
          }(),
          monster = new Monster("slime",100);
      
      __LINE__ = 48;
      __Runtime.assert( true ,monster.isAlive(),"monster.isAlive()",48,'class_test.js');
      
      __LINE__ = 49;
      __Runtime.assert(0,monster.numAttacks,"monster.numAttacks",49,'class_test.js');
      
      __LINE__ = 50;
      __Runtime.assert(100,Monster.DEFAULT_LIFE,"Monster.DEFAULT_LIFE",50,'class_test.js');
      
      __LINE__ = 51;
      __Runtime.assert(undefined,Monster.health,"Monster.health",51,'class_test.js');
      
      __LINE__ = 52;
      var BaseTest = function () {
            function constructor(_mochaLocalTmp0,_mochaLocalTmp1,_mochaLocalTmp2) {
              try {
                __LINE__ = 53;
                __Runtime.getPrivateRecord(this)._name = _mochaLocalTmp0 || "foo";
                
                __LINE__ = 53;
                __Runtime.getPrivateRecord(this)._addr = _mochaLocalTmp1 || "tokyo";
                
                __LINE__ = 53;
                __Runtime.getPrivateRecord(this)._age = _mochaLocalTmp2;
              } catch(__mocha_error){
                __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
              }
            }
            function BaseTest() {
              try {
                __LINE__ = 52;
                __Runtime.initializeClass(this,BaseTest,_mochaPrivateHolder,constructor,arguments,'BaseTest',52);
              } catch(__mocha_error){
                __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
              }
            }
            try {
              
              __LINE__ = 52;
              var _mochaPrivateHolder = function (){};
              
              __LINE__ = 53;
              __Runtime.createUnenumProp(constructor,"__harmony_class__",1);
              
              __LINE__ = 54;
              BaseTest.prototype.getName = function () {
                try {
                  __LINE__ = 54;
                  return __Runtime.getPrivateRecord(this)._name;
                } catch(__mocha_error){
                  __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
                }
              };
              
              __LINE__ = 52;
              __Runtime.createUnenumProp(BaseTest.prototype,"constructor",constructor);
              __LINE__ = 52;
              return BaseTest;
            } catch(__mocha_error){
              __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
            }
          }(),
          DeriveTest = function () {
            function constructor() {
              try {
                __LINE__ = 58;
                return _mochaSuper.constructor.call(this);
              } catch(__mocha_error){
                __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
              }
            }
            function DeriveTest() {
              try {
                __LINE__ = 57;
                __Runtime.initializeClass(this,DeriveTest,_mochaPrivateHolder,constructor,arguments,'DeriveTest',57);
              } catch(__mocha_error){
                __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
              }
            }
            try {
              
              __LINE__ = 57;
              var _mochaPrivateHolder = function (){};
              
              __LINE__ = 57;
              var _mochaLocalTmp3 = BaseTest;
              
              __LINE__ = 57;
              __Runtime.extendClass(DeriveTest,_mochaLocalTmp3);
              
              __LINE__ = 57;
              var _mochaSuper = __Runtime.getSuper(_mochaLocalTmp3);
              
              __LINE__ = 58;
              __Runtime.createUnenumProp(constructor,"__harmony_class__",1);
              
              __LINE__ = 59;
              DeriveTest.prototype.getName = function () {
                try {
                  __LINE__ = 59;
                  return _mochaSuper.getName.call(this);
                } catch(__mocha_error){
                  __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
                }
              };
              
              __LINE__ = 57;
              __Runtime.createUnenumProp(DeriveTest.prototype,"constructor",constructor);
              __LINE__ = 57;
              return DeriveTest;
            } catch(__mocha_error){
              __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
            }
          }(),
          Derive2 = function () {
            function constructor() {
              try {
                __LINE__ = 64;
                return _mochaSuper.constructor.call(this);
              } catch(__mocha_error){
                __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
              }
            }
            function Derive2() {
              try {
                __LINE__ = 63;
                __Runtime.initializeClass(this,Derive2,_mochaPrivateHolder,constructor,arguments,'Derive2',63);
              } catch(__mocha_error){
                __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
              }
            }
            try {
              
              __LINE__ = 63;
              var _mochaPrivateHolder = function (){};
              
              __LINE__ = 63;
              var _mochaLocalTmp4 = DeriveTest;
              
              __LINE__ = 63;
              __Runtime.extendClass(Derive2,_mochaLocalTmp4);
              
              __LINE__ = 63;
              var _mochaSuper = __Runtime.getSuper(_mochaLocalTmp4);
              
              __LINE__ = 64;
              __Runtime.createUnenumProp(constructor,"__harmony_class__",1);
              
              __LINE__ = 65;
              Derive2.prototype.getAddr = function () {
                try {
                  __LINE__ = 65;
                  return __Runtime.getPrivateRecord(this)._addr;
                } catch(__mocha_error){
                  __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
                }
              };
              
              __LINE__ = 63;
              __Runtime.createUnenumProp(Derive2.prototype,"constructor",constructor);
              __LINE__ = 63;
              return Derive2;
            } catch(__mocha_error){
              __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
            }
          }(),
          Drive3 = function () {
            function constructor() {
              try {
                __LINE__ = 71;
                _mochaSuper.constructor.call(this,200,'tokyo',20);
              } catch(__mocha_error){
                __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
              }
            }
            function Drive3() {
              try {
                __LINE__ = 69;
                __Runtime.initializeClass(this,Drive3,_mochaPrivateHolder,constructor,arguments,'Drive3',69);
              } catch(__mocha_error){
                __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
              }
            }
            try {
              
              __LINE__ = 69;
              var _mochaPrivateHolder = function (){};
              
              __LINE__ = 69;
              var _mochaLocalTmp5 = BaseTest;
              
              __LINE__ = 69;
              __Runtime.extendPrototype(Drive3,_mochaLocalTmp5);
              
              __LINE__ = 69;
              var _mochaSuper = __Runtime.getSuper(_mochaLocalTmp5);
              
              __LINE__ = 70;
              __Runtime.createUnenumProp(constructor,"__harmony_class__",1);
              
              __LINE__ = 69;
              __Runtime.createUnenumProp(Drive3.prototype,"constructor",constructor);
              __LINE__ = 69;
              return Drive3;
            } catch(__mocha_error){
              __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
            }
          }(),
          TestClass = function () {
            function constructor(_mochaLocalTmp7,_mochaLocalTmp8) {
              try {
                __LINE__ = 76;
                __Runtime.getPrivateRecord(this)._name = _mochaLocalTmp7 || "test";
                
                __LINE__ = 76;
                __Runtime.getPrivateRecord(this)._age = _mochaLocalTmp8 || 20;
                
                __LINE__ = 77;
                this.testProp = 1;
              } catch(__mocha_error){
                __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
              }
            }
            function _mochaLocalTmp6() {
              try {
                __LINE__ = 75;
                __Runtime.initializeClass(this,_mochaLocalTmp6,_mochaPrivateHolder,constructor,arguments,'_mochaLocalTmp6',75);
              } catch(__mocha_error){
                __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
              }
            }
            try {
              
              __LINE__ = 75;
              var _mochaPrivateHolder = function (){};
              
              __LINE__ = 76;
              __Runtime.createUnenumProp(constructor,"__harmony_class__",1);
              
              __LINE__ = 79;
              _mochaLocalTmp6.prototype.getName = function () {
                try {
                  __LINE__ = 79;
                  return __Runtime.getPrivateRecord(this)._name;
                } catch(__mocha_error){
                  __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
                }
              };
              
              __LINE__ = 80;
              _mochaLocalTmp6.prototype.getAge = function () {
                try {
                  __LINE__ = 80;
                  return __Runtime.getPrivateRecord(this)._age;
                } catch(__mocha_error){
                  __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
                }
              };
              
              __LINE__ = 81;
              _mochaLocalTmp6.prototype.ptest = function () {
                try {
                  __LINE__ = 81;
                  return __Runtime.getPrivateRecord(this).test();
                } catch(__mocha_error){
                  __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
                }
              };
              
              __LINE__ = 82;
              _mochaPrivateHolder.prototype.Inner = function () {
                function constructor(){}
                function Inner() {
                  try {
                    __LINE__ = 82;
                    __Runtime.initializeClass(this,Inner,_mochaPrivateHolder,constructor,arguments,'Inner',82);
                  } catch(__mocha_error){
                    __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
                  }
                }
                try {
                  
                  __LINE__ = 82;
                  var _mochaPrivateHolder = function (){};
                  
                  __LINE__ = 83;
                  __Runtime.createUnenumProp(constructor,"__harmony_class__",1);
                  
                  __LINE__ = 82;
                  __Runtime.createUnenumProp(Inner.prototype,"constructor",constructor);
                  __LINE__ = 82;
                  return Inner;
                } catch(__mocha_error){
                  __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
                }
              }();
              
              __LINE__ = 85;
              _mochaPrivateHolder.prototype.test = function () {
                try {
                  __LINE__ = 85;
                  return __Runtime.getInstanceBody(this).testProp;
                } catch(__mocha_error){
                  __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
                }
              };
              
              __LINE__ = 75;
              __Runtime.createUnenumProp(_mochaLocalTmp6.prototype,"constructor",constructor);
              __LINE__ = 75;
              return _mochaLocalTmp6;
            } catch(__mocha_error){
              __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
            }
          }();
      
      __LINE__ = 88;
      __Runtime.assert( true ,new DeriveTest().getName() === "foo","new DeriveTest().getName() === \"foo\"",88,'class_test.js');
      
      __LINE__ = 89;
      __Runtime.assert( true ,new Derive2().getAddr() === "tokyo","new Derive2().getAddr() === \"tokyo\"",89,'class_test.js');
      
      __LINE__ = 90;
      var instance = new TestClass();
      
      __LINE__ = 91;
      __Runtime.assert( true ,instance.getName() === "test","instance.getName() === \"test\"",91,'class_test.js');
      
      __LINE__ = 92;
      __Runtime.assert( true ,instance.getAge() === 20,"instance.getAge() === 20",92,'class_test.js');
      
      __LINE__ = 93;
      __Runtime.assert( true ,instance.ptest() === 1,"instance.ptest() === 1",93,'class_test.js');
      
      __LINE__ = 95;
      var TestTrait =  {
            _mochaTraitPrivate : {},
            _mochaTraitPublic :  {
              testm1 : function testm1(arg) {
                try {
                  __LINE__ = 97;
                  arg = __Runtime.toArray(arguments,0);
                  __LINE__ = 97;
                  return arg[0];
                } catch(__mocha_error){
                  __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
                }
              }
            },
            _mochaRequires :  {
              doTestm1 :  true 
            },
            _mochaTraitMark :  true 
          },
          TestTrait2 =  {
            _mochaTraitPrivate : {},
            _mochaTraitPublic :  {
              testm2 : function testm2(arg) {
                try {
                  __LINE__ = 102;
                  arg = __Runtime.toArray(arguments,0);
                  __LINE__ = 102;
                  return arg[0];
                } catch(__mocha_error){
                  __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
                }
              },
              testm3 : function testm3() {
                try {
                  __LINE__ = 103;
                  return "ok";
                } catch(__mocha_error){
                  __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
                }
              }
            },
            _mochaRequires :  {
              doTestm2 :  true 
            },
            _mochaTraitMark :  true 
          },
          MixinTest = function () {
            function constructor(){}
            function MixinTest() {
              try {
                __LINE__ = 106;
                __Runtime.initializeClass(this,MixinTest,_mochaPrivateHolder,constructor,arguments,'MixinTest',106);
              } catch(__mocha_error){
                __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
              }
            }
            try {
              
              __LINE__ = 106;
              var _mochaPrivateHolder = function (){};
              
              __LINE__ = 106;
              __Runtime.createUnenumProp(constructor,"__harmony_class__",1);
              
              __LINE__ = 107;
              MixinTest.prototype.doTestm1 = function () {
                try {
                  __LINE__ = 107;
                  return "aaa";
                } catch(__mocha_error){
                  __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
                }
              };
              
              __LINE__ = 108;
              MixinTest.prototype.doTestm2 = function () {
                try {
                  __LINE__ = 108;
                  return "bbb";
                } catch(__mocha_error){
                  __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
                }
              };
              
              __LINE__ = 0;
              __Runtime.classMixin(MixinTest,_mochaPrivateHolder,TestTrait, {
                testm1 : "m1"
              },{});
              
              __LINE__ = 0;
              __Runtime.classMixin(MixinTest,_mochaPrivateHolder,TestTrait2,{}, {
                testm2 : true,
                testm3 : true
              });
              
              __LINE__ = 106;
              __Runtime.checkRequirements(MixinTest,_mochaPrivateHolder,[TestTrait,TestTrait2],'class_test.js',110);
              
              __LINE__ = 106;
              __Runtime.createUnenumProp(MixinTest.prototype,"constructor",constructor);
              __LINE__ = 106;
              return MixinTest;
            } catch(__mocha_error){
              __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
            }
          }(),
          instance2 = new MixinTest();
      
      __LINE__ = 114;
      __Runtime.assert( true ,instance2.m1("foo") === "foo","instance2.m1(\"foo\") === \"foo\"",114,'class_test.js');
      
      __LINE__ = 115;
      __Runtime.assert( true ,instance2.m2 === undefined,"instance2.m2 === undefined",115,'class_test.js');
      
      __LINE__ = 118;
      var Box = function () {
            function constructor(_mochaLocalTmp9,_mochaLocalTmp10) {
              try {
                __LINE__ = 119;
                __Runtime.getPrivateRecord(this)._width = _mochaLocalTmp9 || 100;
                
                __LINE__ = 119;
                __Runtime.getPrivateRecord(this)._height = _mochaLocalTmp10 || 100;
              } catch(__mocha_error){
                __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
              }
            }
            function Box() {
              try {
                __LINE__ = 118;
                __Runtime.initializeClass(this,Box,_mochaPrivateHolder,constructor,arguments,'Box',118);
              } catch(__mocha_error){
                __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
              }
            }
            try {
              
              __LINE__ = 118;
              var _mochaPrivateHolder = function (){};
              
              __LINE__ = 119;
              __Runtime.createUnenumProp(constructor,"__harmony_class__",1);
              
              __LINE__ = 120;
              Box.prototype.height = function () {
                try {
                  __LINE__ = 120;
                  return __Runtime.getPrivateRecord(this)._height;
                } catch(__mocha_error){
                  __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
                }
              };
              
              __LINE__ = 121;
              Box.prototype.width = function () {
                try {
                  __LINE__ = 121;
                  return __Runtime.getPrivateRecord(this)._width;
                } catch(__mocha_error){
                  __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
                }
              };
              
              __LINE__ = 122;
              var _mochaLocalTmp11 =  {
                    type : 200,
                    _max : 400
                  };
              
              __LINE__ = 122;
              _mochaPrivateHolder.prototype._type = _mochaLocalTmp11._type;
              
              __LINE__ = 122;
              _mochaPrivateHolder.prototype._max = _mochaLocalTmp11._max;
              
              __LINE__ = 118;
              __Runtime.createUnenumProp(Box.prototype,"constructor",constructor);
              __LINE__ = 118;
              return Box;
            } catch(__mocha_error){
              __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
            }
          }(),
          inst = new Box();
      
      __LINE__ = 126;
      __Runtime.assert( true ,inst.height() === 100,"inst.height() === 100",126,'class_test.js');
      
      __LINE__ = 127;
      __Runtime.assert( true ,inst.width() === 100,"inst.width() === 100",127,'class_test.js');
    } catch(__mocha_error){
      __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
    }
  }();
}();
