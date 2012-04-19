!function() {
  var __FILE__ = "Runtime",
      __LINE__ = 0;
  
  var global = ( this  !==  null )? this  : typeof window === 'object'?window : {};
  
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
        
        Runtime.assert( true ,typeof type === "string","typeof type === \"string\"",44,'runtime.js');
        
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
              
              ret =  false ;
            }
            return ret;
          }();
      
      !hasRealEcma5 && (Object.defineProperty = function (obj,prop,valobj) {
        "value" in valobj && (obj[prop] = valobj.value);
      });
      
      if (!stringProto.trim){
        
        stringProto.trim = function () {
          return  this .replace(stringProto.trim.rtrim,"");
        };
        
        stringProto.trim.rtrim = /^\s*|\s*$/g;
      }
      
      !stringProto.repeat && defineBuiltin(stringProto,"repeat",
      function (num) {
        return Array(num+1).join( this .toString());
      });
      
      !stringProto.startsWith && defineBuiltin(stringProto,"startsWith",
      function (str) {
        return ! this .indexOf(str);
      });
      
      !stringProto.endsWith && defineBuiltin(stringProto,"endsWith",
      function (str) {
        var t = String(str),
            index =  this .lastIndexOf(t);
        return index >= 0 && index ===  this .length-t.length;
      });
      
      !stringProto.contains && defineBuiltin(stringProto,"contains",
      function (str) {
        return  this .indexOf(str) !== -1;
      });
      
      !stringProto.toArray && defineBuiltin(stringProto,"toArray",
      function (str) {
        return  this .split("");
      });
      
      !functionProto.bind && defineBuiltin(functionProto,"bind",
      function () {
        var argArray = arrayProto.slice.call(arguments),
            context = argArray.shift(),
            ret = function () {
              var args = argArray.concat(arrayProto.slice.call(arguments));
              return  this  !==  null  &&  this  !== global &&  this  instanceof ret?ret.context.apply( this ,args) : ret.context.apply(context,args);
            };
        
        ret.prototype =  this .prototype;
        
        ret.context =  this ;
        return ret;
      });
      
      !arrayProto.forEach && defineBuiltin(arrayProto,"forEach",
      function (callback,that) {
        callbackCheck(callback,"Array.forEach");
        
        var iter = -1,
            ta;
        
         this  ===  null  && builtinTypeError("Array.forEach : this is null or not defined");
        
        if (that){
          while ((ta =  this [ ++ iter]) !==  null  && ta !== undefined){
            callback.call(that,ta,iter, this );
          }
          
        } else {
          while ((ta =  this [ ++ iter]) !==  null  && ta !== undefined){
            callback(ta,iter, this );
          }
          
        }
        
      });
      
      !arrayProto.every && defineBuiltin(arrayProto,"every",
      function (callback,that) {
        callbackCheck(callback,"Array.every");
        
        var iter = -1,
            ta;
        
         this  ===  null  && builtinTypeError("Array.every : this is null or not defined");
        
        if (that){
          while ((ta =  this [ ++ iter]) !==  null  && ta !== undefined){
            if (!(callback.call(that,ta,iter, this ))){
              return  false ;
            }
            
          }
          
        } else {
          while ((ta =  this [ ++ iter]) !==  null  && ta !== undefined){
            if (!(callback(ta,iter, this ))){
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
        
         this  ===  null  && builtinTypeError("Array.some : this is null or not defined");
        
        if (that){
          while ((ta =  this [ ++ iter]) !==  null  && ta !== undefined){
            if (callback.call(that,ta,iter, this )){
              return  true ;
            }
            
          }
          
        } else {
          while ((ta =  this [ ++ iter]) !==  null  && ta !== undefined){
            if (callback(ta,iter, this )){
              return  true ;
            }
            
          }
          
        }
        return  false ;
      });
      
      !arrayProto.filter && defineBuiltin(arrayProto,"filter",
      function (callback,that) {
        callbackCheck(callback,"Array.filter");
        
        var len =  this .length,
            iter = -1,
            ret = [],
            ta;
        
         this  ===  null  && builtinTypeError("Array.filter : this is null or not defined");
        
        if (that){
          for (var i = 0,len =  this .length;i<len; ++ i){
            
            (ta =  this [i]) !==  null  && ta !== undefined && callback.call(that,ta,i, this ) && (ret[ ++ iter] = ta);
          }
          
        } else {
          for (var i = 0,len =  this .length;i<len; ++ i){
            
            (ta =  this [i]) !==  null  && ta !== undefined && callback(ta,i, this ) && (ret[ ++ iter] = ta);
          }
          
        }
        return ret;
      });
      
      !arrayProto.indexOf && defineBuiltin(arrayProto,"indexOf",
      function (subject,fromIndex) {
        var iter = (fromIndex)?fromIndex-1 : -1,
            index = -1,
            ta;
        
         this  ===  null  && builtinTypeError("Array.indexOf : this is null or not defined.");
        
        while ((ta =  this [ ++ iter]) !==  null  && ta !== undefined){
          if (ta === subject){
            
            index = iter;
            break;
          }
          
        }
        return index;
      });
      
      !arrayProto.lastIndexOf && defineBuiltin(arrayProto,"lastIndexOf",
      function (target,fromIndex) {
        var len =  this .length,
            iter = (fromIndex)?fromIndex+1 : len,
            index = -1,
            ta;
        
         this  ===  null  && builtinTypeError("Array.lastIndexOf : this is null or not defined.");
        
        while ((ta =  this [ -- iter]) !==  null  && ta !== undefined){
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
            len =  this .length,
            i = 0,
            ta;
        
         this  ===  null  && builtinTypeError("Array.map : this is null or not defined.");
        
        if (that){
          for (i;i<len; ++ i){
            (ta =  this [i]) !==  null  && ta !== undefined && (ret[ ++ iter] = callback.call(that,ta,i, this ));
          }
          
        } else {
          for (i;i<len; ++ i){
            (ta =  this [i]) !==  null  && ta !== undefined && (ret[ ++ iter] = callback(ta,i, this ));
          }
          
        }
        return ret;
      });
      
      !arrayProto.reduce && defineBuiltin(arrayProto,"reduce",
      function (callback,initial) {
        callbackCheck(callback,"Array.reduce");
        
        var ret = initial ||  this [0],
            i = (initial)?0 : 1,
            len =  this .length,
            ta;
        
        (len === 0 || len ===  null ) && arguments.length<2 && builtinTypeError("Array length is 0 and no second argument");
        
        for (i;i<len; ++ i){
          (ta =  this [i]) !==  null  && ta !== undefined && (ret = callback(ret,ta,i, this ));
        }
        return ret;
      });
      
      !arrayProto.reduceRight && defineBuiltin(arrayProto,"reduceRight",
      function (callback,initial) {
        callbackCheck(callback,"Array.reduceRight");
        
        var len =  this .length,
            ret = initial ||  this [len-1],
            i = (initial)?len-1 : len-2,
            ta;
        
        (len === 0 || len ===  null ) && arguments.length<2 && builtinTypeError("Array length is 0 and no second argument");
        
        for (i;i>-1; -- i){
          (ta =  this [i]) !==  null  && ta !== undefined && (ret = callback(ret,ta,i, this ));
        }
        return ret;
      });
      
      !dateProto.toJSON && defineBuiltin(dateProto,"toJSON",
      function () {
        var _mochaLocalTmp4 = [ this .getUTCMonth(), this .getUTCDate(), this .getUTCHours(), this .getMinutes(), this .getSeconds()],
            month = _mochaLocalTmp4[0],
            date = _mochaLocalTmp4[1],
            hour = _mochaLocalTmp4[2],
            minute = _mochaLocalTmp4[3],
            second = _mochaLocalTmp4[4];
        return '"'+ this .getUTCFullYear()+'-'+(month>8?month+1 : "0"+(month+1))+'-'+(date>9?date : "0"+date)+'T'+(hour>9?hour : "0"+hour)+':'+(minute>9?minute : "0"+minute)+':'+(second>9?second : "0"+second)+'.'+ this .getUTCMilliseconds()+'Z"';
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
    }.call( this ,String,Array,Function,Date);
  }.call( this );
  
  var Runtime = function () {
        "use strict";
        function spreadCall(context,fn,args,isNew) {
          var newArgs = [];
          
          for (var i = 0,len = args.length;i<len;i += 2){
            
            args[i] ===  true ?push.apply(newArgs,args[i+1]) : newArgs.push(args[i+1]);
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
            
             this [i] = obj[i];
          }
          
          Object.freeze( this );
        }
        function TupleConstructor(args) {
          push.apply( this ,args);
          
          Object.freeze( this );
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
          
          createUnenumProp(ret,"next",generatorFn.bind(context, false , false ));
          
          createUnenumProp(ret,"send",generatorFn.bind(context, true , false ));
          
          createUnenumProp(ret,"close",closeFn.bind(context));
          
          createUnenumProp(ret,"__nothrowNext__",generatorFn.bind(context, false , true ));
          
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
            configurable :  false ,
            enumerable :  false ,
            writable :  false ,
            value : value
          });
        }
        function createUnenumProp(obj,prop,value) {
          return Object.defineProperty(obj,prop, {
            configurable :  true ,
            enumerable :  false ,
            writable :  true ,
            value : value
          });
        }
        function Exception(line,file,e) {
           this .toString = function () {
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
                  
                   this .throwException(e);
                } else {
                  
                   this .throwException(new Exception(line,file,e));
                }
                
              },
              throwException : function (exception) {
                try {
                  throw exception;
                } catch(e){
                  
                  if (isStopIteration(e)){
                    throw new Error(e);
                  } else {
                    throw new Error( this .getErrorMessage(e));
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
            var maxIndex = max(tuple.length, this .length),
                i = -1;
            
            while ( ++ i<maxIndex && tuple[i] ===  this [i]){
              
            }
            return maxIndex === i;
          },
          tupleToArray : function () {
            return slice.call( this );
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
          writable :  true 
        });
        
        Object.defineProperty(ModuleContainer.prototype,'add', {
          value : function (name) {
            return  this ._modules[name] = new Module;
          }
        });
        
        Object.defineProperty(ModuleContainer.prototype,'get', {
          value : function (name) {
            return  this ._modules[name];
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
        }.call( this );
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
      var __FILE__ = "-839149963-harmony_function_test.js",
          __LINE__ = 0;
      __LINE__ = 2;
      Runtime.modules.add('-839149963-harmony_function_test.js');
      
      __LINE__ = 1;
      !function () {
        function testWithContext() {
          try {
            __LINE__ = 32;
            return console.log(1);
          } catch(e){
            Runtime.exceptionHandler(__LINE__, __FILE__, e);
          }
        }
        function testHasFormalWithContext() {
          try {
            __LINE__ = 31;
            return console.log(1);
          } catch(e){
            Runtime.exceptionHandler(__LINE__, __FILE__, e);
          }
        }
        function testHasFormalHasBlockWithContext() {
          try {
            __LINE__ = 29;
            console.log(1);
          } catch(e){
            Runtime.exceptionHandler(__LINE__, __FILE__, e);
          }
        }
        function test() {
          try {
            __LINE__ = 26;
            return console.log(1);
          } catch(e){
            Runtime.exceptionHandler(__LINE__, __FILE__, e);
          }
        }
        function testHasFormal() {
          try {
            __LINE__ = 25;
            return console.log(1);
          } catch(e){
            Runtime.exceptionHandler(__LINE__, __FILE__, e);
          }
        }
        function testHasFormalHasBlock() {
          try {
            __LINE__ = 23;
            console.log(1);
          } catch(e){
            Runtime.exceptionHandler(__LINE__, __FILE__, e);
          }
        }
        function testConstFunctionWithContext() {
          try {
            __LINE__ = 17;
            return console.log(1);
          } catch(e){
            Runtime.exceptionHandler(__LINE__, __FILE__, e);
          }
        }
        function testConstFunctionHasFormalWithContext() {
          try {
            __LINE__ = 16;
            return console.log(1);
          } catch(e){
            Runtime.exceptionHandler(__LINE__, __FILE__, e);
          }
        }
        function testConstFunctionNonFormal() {
          try {
            __LINE__ = 14;
            return console.log(1);
          } catch(e){
            Runtime.exceptionHandler(__LINE__, __FILE__, e);
          }
        }
        function testConstFunctionHasForaml() {
          try {
            __LINE__ = 13;
            return console.log(1);
          } catch(e){
            Runtime.exceptionHandler(__LINE__, __FILE__, e);
          }
        }
        function testConstFunctionHasBlockHasFormal() {
          try {
            __LINE__ = 8;
            console.log(1);
          } catch(e){
            Runtime.exceptionHandler(__LINE__, __FILE__, e);
          }
        }
        function testDeclNonForamlWithContext() {
          try {
            __LINE__ = 5;
            return console.log(1);
          } catch(e){
            Runtime.exceptionHandler(__LINE__, __FILE__, e);
          }
        }
        function testDeclHasFormalWithContext() {
          try {
            __LINE__ = 4;
            return console.log(1);
          } catch(e){
            Runtime.exceptionHandler(__LINE__, __FILE__, e);
          }
        }
        function testDeclNonFormal() {
          try {
            __LINE__ = 3;
            return console.log(1);
          } catch(e){
            Runtime.exceptionHandler(__LINE__, __FILE__, e);
          }
        }
        function testDeclHasFormal() {
          try {
            __LINE__ = 2;
            return console.log(1);
          } catch(e){
            Runtime.exceptionHandler(__LINE__, __FILE__, e);
          }
        }
        try {
          
          __LINE__ = 32;
          testWithContext = testWithContext.bind( this );
          
          __LINE__ = 31;
          testHasFormalWithContext = testHasFormalWithContext.bind( this );
          
          __LINE__ = 28;
          testHasFormalHasBlockWithContext = testHasFormalHasBlockWithContext.bind( this );
          
          __LINE__ = 17;
          testConstFunctionWithContext = testConstFunctionWithContext.bind( this );
          
          __LINE__ = 16;
          testConstFunctionHasFormalWithContext = testConstFunctionHasFormalWithContext.bind( this );
          
          __LINE__ = 5;
          testDeclNonForamlWithContext = testDeclNonForamlWithContext.bind( this );
          
          __LINE__ = 4;
          testDeclHasFormalWithContext = testDeclHasFormalWithContext.bind( this );
          
          __LINE__ = 11;
          var contextTest = function () {
                try {
                  __LINE__ = 11;
                  return console.log( this );
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              }.bind(this);
          
          __LINE__ = 18;
          var x = function (a,b,c) {
                try {
                  __LINE__ = 19;
                  return a+b;
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              },
              x2 = function (a,b,c) {
                try {
                  __LINE__ = 21;
                  return a+b;
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              };
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }();
      
      __LINE__ = 35;
      !function () {
        function testHasFormalDstaWithContext(_mochaLocalTmp24,_mochaLocalTmp25,_mochaLocalTmp26,args8) {
          try {
            __LINE__ = 68;
            args8 = Runtime.toArray(arguments,3);
            
            __LINE__ = 68;
            var args = _mochaLocalTmp24.args,
                args2 = _mochaLocalTmp25.tmp && _mochaLocalTmp25.tmp["args2"]?_mochaLocalTmp25.tmp.args2 : undefined,
                args3 = _mochaLocalTmp26[0],
                args4 = _mochaLocalTmp26[1],
                args5 = _mochaLocalTmp26[2] && _mochaLocalTmp26[2].args5?_mochaLocalTmp26[2].args5 : undefined,
                args7 = _mochaLocalTmp26[2] && _mochaLocalTmp26[2].args6 && _mochaLocalTmp26[2].args6.args7?_mochaLocalTmp26[2].args6.args7 : undefined;
            __LINE__ = 68;
            return console.log(1);
          } catch(e){
            Runtime.exceptionHandler(__LINE__, __FILE__, e);
          }
        }
        function testHasFormalWithContext(args,args2,args3) {
          try {
            __LINE__ = 67;
            return console.log(1);
          } catch(e){
            Runtime.exceptionHandler(__LINE__, __FILE__, e);
          }
        }
        function testHasFormalDstaHasBlockWithContext(_mochaLocalTmp21,_mochaLocalTmp22,_mochaLocalTmp23,args8) {
          try {
            __LINE__ = 64;
            args8 = Runtime.toArray(arguments,3);
            
            __LINE__ = 64;
            var args = _mochaLocalTmp21.args,
                args2 = _mochaLocalTmp22.tmp && _mochaLocalTmp22.tmp["args2"]?_mochaLocalTmp22.tmp.args2 : undefined,
                args3 = _mochaLocalTmp23[0],
                args4 = _mochaLocalTmp23[1],
                args5 = _mochaLocalTmp23[2] && _mochaLocalTmp23[2].args5?_mochaLocalTmp23[2].args5 : undefined,
                args7 = _mochaLocalTmp23[2] && _mochaLocalTmp23[2].args6 && _mochaLocalTmp23[2].args6.args7?_mochaLocalTmp23[2].args6.args7 : undefined;
            
            __LINE__ = 65;
            console.log(1);
          } catch(e){
            Runtime.exceptionHandler(__LINE__, __FILE__, e);
          }
        }
        function testHasFormalHasBlockWithContext(args,args2,args3) {
          try {
            __LINE__ = 62;
            console.log(1);
          } catch(e){
            Runtime.exceptionHandler(__LINE__, __FILE__, e);
          }
        }
        function testHasFormalDsta(_mochaLocalTmp18,_mochaLocalTmp19,_mochaLocalTmp20,args8) {
          try {
            __LINE__ = 60;
            args8 = Runtime.toArray(arguments,3);
            
            __LINE__ = 60;
            var args = _mochaLocalTmp18.args,
                args2 = _mochaLocalTmp19.tmp && _mochaLocalTmp19.tmp["args2"]?_mochaLocalTmp19.tmp.args2 : undefined,
                args3 = _mochaLocalTmp20[0],
                args4 = _mochaLocalTmp20[1],
                args5 = _mochaLocalTmp20[2] && _mochaLocalTmp20[2].args5?_mochaLocalTmp20[2].args5 : undefined,
                args7 = _mochaLocalTmp20[2] && _mochaLocalTmp20[2].args6 && _mochaLocalTmp20[2].args6.args7?_mochaLocalTmp20[2].args6.args7 : undefined;
            __LINE__ = 60;
            return console.log(1);
          } catch(e){
            Runtime.exceptionHandler(__LINE__, __FILE__, e);
          }
        }
        function testHasFormal(args,args2,args3) {
          try {
            __LINE__ = 59;
            return console.log(1);
          } catch(e){
            Runtime.exceptionHandler(__LINE__, __FILE__, e);
          }
        }
        function testHasFormalDstaHasBlock(_mochaLocalTmp15,_mochaLocalTmp16,_mochaLocalTmp17,args8) {
          try {
            __LINE__ = 56;
            args8 = Runtime.toArray(arguments,3);
            
            __LINE__ = 56;
            var args = _mochaLocalTmp15.args,
                args2 = _mochaLocalTmp16.tmp && _mochaLocalTmp16.tmp["args2"]?_mochaLocalTmp16.tmp.args2 : undefined,
                args3 = _mochaLocalTmp17[0],
                args4 = _mochaLocalTmp17[1],
                args5 = _mochaLocalTmp17[2] && _mochaLocalTmp17[2].args5?_mochaLocalTmp17[2].args5 : undefined,
                args7 = _mochaLocalTmp17[2] && _mochaLocalTmp17[2].args6 && _mochaLocalTmp17[2].args6.args7?_mochaLocalTmp17[2].args6.args7 : undefined;
            
            __LINE__ = 57;
            console.log(1);
          } catch(e){
            Runtime.exceptionHandler(__LINE__, __FILE__, e);
          }
        }
        function testHasFormalHasBlock(args,args2,args3) {
          try {
            __LINE__ = 54;
            console.log(1);
          } catch(e){
            Runtime.exceptionHandler(__LINE__, __FILE__, e);
          }
        }
        function testConstFunctionHasFormalDstaWithContext(_mochaLocalTmp12,_mochaLocalTmp13,_mochaLocalTmp14,args8) {
          try {
            __LINE__ = 51;
            args8 = Runtime.toArray(arguments,3);
            
            __LINE__ = 51;
            var args = _mochaLocalTmp12.args,
                args2 = _mochaLocalTmp13.tmp && _mochaLocalTmp13.tmp["args2"]?_mochaLocalTmp13.tmp.args2 : undefined,
                args3 = _mochaLocalTmp14[0],
                args4 = _mochaLocalTmp14[1],
                args5 = _mochaLocalTmp14[2] && _mochaLocalTmp14[2].args5?_mochaLocalTmp14[2].args5 : undefined,
                args7 = _mochaLocalTmp14[2] && _mochaLocalTmp14[2].args6 && _mochaLocalTmp14[2].args6.args7?_mochaLocalTmp14[2].args6.args7 : undefined;
            __LINE__ = 51;
            return console.log(1);
          } catch(e){
            Runtime.exceptionHandler(__LINE__, __FILE__, e);
          }
        }
        function testConstFunctionHasFormalWithContext(args,args2,args3) {
          try {
            __LINE__ = 50;
            return console.log(1);
          } catch(e){
            Runtime.exceptionHandler(__LINE__, __FILE__, e);
          }
        }
        function testConstFunctionHasForamlDsta(_mochaLocalTmp9,_mochaLocalTmp10,_mochaLocalTmp11,args8) {
          try {
            __LINE__ = 49;
            args8 = Runtime.toArray(arguments,3);
            
            __LINE__ = 49;
            var args = _mochaLocalTmp9.args,
                args2 = _mochaLocalTmp10.tmp && _mochaLocalTmp10.tmp["args2"]?_mochaLocalTmp10.tmp.args2 : undefined,
                args3 = _mochaLocalTmp11[0],
                args4 = _mochaLocalTmp11[1],
                args5 = _mochaLocalTmp11[2] && _mochaLocalTmp11[2].args5?_mochaLocalTmp11[2].args5 : undefined,
                args7 = _mochaLocalTmp11[2] && _mochaLocalTmp11[2].args6 && _mochaLocalTmp11[2].args6.args7?_mochaLocalTmp11[2].args6.args7 : undefined;
            __LINE__ = 49;
            return console.log(1);
          } catch(e){
            Runtime.exceptionHandler(__LINE__, __FILE__, e);
          }
        }
        function testConstFunctionHasForaml(args,args2,args3) {
          try {
            __LINE__ = 48;
            return console.log(1);
          } catch(e){
            Runtime.exceptionHandler(__LINE__, __FILE__, e);
          }
        }
        function testConstFunctionHasBlockHasFormalDsta(_mochaLocalTmp6,_mochaLocalTmp7,_mochaLocalTmp8,args8) {
          try {
            __LINE__ = 44;
            args8 = Runtime.toArray(arguments,3);
            
            __LINE__ = 44;
            var args = _mochaLocalTmp6.args,
                args2 = _mochaLocalTmp7.tmp && _mochaLocalTmp7.tmp["args2"]?_mochaLocalTmp7.tmp.args2 : undefined,
                args3 = _mochaLocalTmp8[0],
                args4 = _mochaLocalTmp8[1],
                args5 = _mochaLocalTmp8[2] && _mochaLocalTmp8[2].args5?_mochaLocalTmp8[2].args5 : undefined,
                args7 = _mochaLocalTmp8[2] && _mochaLocalTmp8[2].args6 && _mochaLocalTmp8[2].args6.args7?_mochaLocalTmp8[2].args6.args7 : undefined;
            
            __LINE__ = 45;
            console.log(1);
          } catch(e){
            Runtime.exceptionHandler(__LINE__, __FILE__, e);
          }
        }
        function testConstFunctionHasBlockHasFormal(args,args2,args3) {
          try {
            __LINE__ = 42;
            console.log(1);
          } catch(e){
            Runtime.exceptionHandler(__LINE__, __FILE__, e);
          }
        }
        function testDeclHasFormalDstaWithContext(_mochaLocalTmp3,_mochaLocalTmp4,_mochaLocalTmp5,args8) {
          try {
            __LINE__ = 40;
            args8 = Runtime.toArray(arguments,3);
            
            __LINE__ = 40;
            var args = _mochaLocalTmp3.args,
                args2 = _mochaLocalTmp4.tmp && _mochaLocalTmp4.tmp["args2"]?_mochaLocalTmp4.tmp.args2 : undefined,
                args3 = _mochaLocalTmp5[0],
                args4 = _mochaLocalTmp5[1],
                args5 = _mochaLocalTmp5[2] && _mochaLocalTmp5[2].args5?_mochaLocalTmp5[2].args5 : undefined,
                args7 = _mochaLocalTmp5[2] && _mochaLocalTmp5[2].args6 && _mochaLocalTmp5[2].args6.args7?_mochaLocalTmp5[2].args6.args7 : undefined;
            __LINE__ = 40;
            return console.log( this );
          } catch(e){
            Runtime.exceptionHandler(__LINE__, __FILE__, e);
          }
        }
        function testDeclHasFormalWithContext(args,args2,args3) {
          try {
            __LINE__ = 39;
            return console.log(1);
          } catch(e){
            Runtime.exceptionHandler(__LINE__, __FILE__, e);
          }
        }
        function testDeclHasFormalDsta(_mochaLocalTmp0,_mochaLocalTmp1,_mochaLocalTmp2,args8) {
          try {
            __LINE__ = 38;
            args8 = Runtime.toArray(arguments,3);
            
            __LINE__ = 38;
            var args = _mochaLocalTmp0.args,
                args2 = _mochaLocalTmp1.tmp && _mochaLocalTmp1.tmp["args2"]?_mochaLocalTmp1.tmp.args2 : undefined,
                args3 = _mochaLocalTmp2[0],
                args4 = _mochaLocalTmp2[1],
                args5 = _mochaLocalTmp2[2] && _mochaLocalTmp2[2].args5?_mochaLocalTmp2[2].args5 : undefined,
                args7 = _mochaLocalTmp2[2] && _mochaLocalTmp2[2].args6 && _mochaLocalTmp2[2].args6.args7?_mochaLocalTmp2[2].args6.args7 : undefined;
            __LINE__ = 38;
            return console.log(1);
          } catch(e){
            Runtime.exceptionHandler(__LINE__, __FILE__, e);
          }
        }
        function testDeclHasFormal(args,args2,args3) {
          try {
            __LINE__ = 37;
            return console.log(1);
          } catch(e){
            Runtime.exceptionHandler(__LINE__, __FILE__, e);
          }
        }
        try {
          
          __LINE__ = 68;
          testHasFormalDstaWithContext = testHasFormalDstaWithContext.bind( this );
          
          __LINE__ = 67;
          testHasFormalWithContext = testHasFormalWithContext.bind( this );
          
          __LINE__ = 64;
          testHasFormalDstaHasBlockWithContext = testHasFormalDstaHasBlockWithContext.bind( this );
          
          __LINE__ = 61;
          testHasFormalHasBlockWithContext = testHasFormalHasBlockWithContext.bind( this );
          
          __LINE__ = 51;
          testConstFunctionHasFormalDstaWithContext = testConstFunctionHasFormalDstaWithContext.bind( this );
          
          __LINE__ = 50;
          testConstFunctionHasFormalWithContext = testConstFunctionHasFormalWithContext.bind( this );
          
          __LINE__ = 40;
          testDeclHasFormalDstaWithContext = testDeclHasFormalDstaWithContext.bind( this );
          
          __LINE__ = 39;
          testDeclHasFormalWithContext = testDeclHasFormalWithContext.bind( this );
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }();
      
      __LINE__ = 71;
      !function () {
        function newSpreadWithArgs($1,a,b,c,d,$2,e,f) {
          try {
            
            __LINE__ = 134;
            Runtime.assert( true ,$1 === 0,"$1 === 0",134,'harmony_function_test.js');
            
            __LINE__ = 135;
            Runtime.assert( true ,a === 1,"a === 1",135,'harmony_function_test.js');
            
            __LINE__ = 136;
            Runtime.assert( true ,b === 2,"b === 2",136,'harmony_function_test.js');
            
            __LINE__ = 137;
            Runtime.assert( true ,c === 3,"c === 3",137,'harmony_function_test.js');
            
            __LINE__ = 138;
            Runtime.assert( true ,$2 === 0,"$2 === 0",138,'harmony_function_test.js');
            
            __LINE__ = 139;
            Runtime.assert( true ,d === 4,"d === 4",139,'harmony_function_test.js');
            
            __LINE__ = 140;
            Runtime.assert( true ,e === 100,"e === 100",140,'harmony_function_test.js');
            
            __LINE__ = 141;
            Runtime.assert( true ,f === 200,"f === 200",141,'harmony_function_test.js');
            
            __LINE__ = 142;
            Runtime.assert( true , this .valid," this .valid",142,'harmony_function_test.js');
          } catch(e){
            Runtime.exceptionHandler(__LINE__, __FILE__, e);
          }
        }
        function normalSpreadWithArgs($1,a,b,c,d,$2,e,f) {
          try {
            
            __LINE__ = 109;
            Runtime.assert( true ,$1 === 0,"$1 === 0",109,'harmony_function_test.js');
            
            __LINE__ = 110;
            Runtime.assert( true ,a === 1,"a === 1",110,'harmony_function_test.js');
            
            __LINE__ = 111;
            Runtime.assert( true ,b === 2,"b === 2",111,'harmony_function_test.js');
            
            __LINE__ = 112;
            Runtime.assert( true ,c === 3,"c === 3",112,'harmony_function_test.js');
            
            __LINE__ = 113;
            Runtime.assert( true ,$2 === 0,"$2 === 0",113,'harmony_function_test.js');
            
            __LINE__ = 114;
            Runtime.assert( true ,d === 4,"d === 4",114,'harmony_function_test.js');
            
            __LINE__ = 115;
            Runtime.assert( true ,e === 100,"e === 100",115,'harmony_function_test.js');
            
            __LINE__ = 116;
            Runtime.assert( true ,f === 200,"f === 200",116,'harmony_function_test.js');
          } catch(e){
            Runtime.exceptionHandler(__LINE__, __FILE__, e);
          }
        }
        function newSpread(a,b,c,d) {
          try {
            
            __LINE__ = 91;
            Runtime.assert( true ,a === 1,"a === 1",91,'harmony_function_test.js');
            
            __LINE__ = 92;
            Runtime.assert( true ,b === 2,"b === 2",92,'harmony_function_test.js');
            
            __LINE__ = 93;
            Runtime.assert( true ,c === 3,"c === 3",93,'harmony_function_test.js');
            
            __LINE__ = 94;
            Runtime.assert( true ,d === 4,"d === 4",94,'harmony_function_test.js');
            
            __LINE__ = 95;
            Runtime.assert( true , this .valid," this .valid",95,'harmony_function_test.js');
          } catch(e){
            Runtime.exceptionHandler(__LINE__, __FILE__, e);
          }
        }
        function normalSpread(a,b,c,d) {
          try {
            
            __LINE__ = 74;
            Runtime.assert( true ,a === 1,"a === 1",74,'harmony_function_test.js');
            
            __LINE__ = 75;
            Runtime.assert( true ,b === 2,"b === 2",75,'harmony_function_test.js');
            
            __LINE__ = 76;
            Runtime.assert( true ,c === 3,"c === 3",76,'harmony_function_test.js');
            
            __LINE__ = 77;
            Runtime.assert( true ,d === 4,"d === 4",77,'harmony_function_test.js');
          } catch(e){
            Runtime.exceptionHandler(__LINE__, __FILE__, e);
          }
        }
        try {
          
          __LINE__ = 72;
          var args = [1,2,3,4];
          
          __LINE__ = 80;
          var propertySpread =  {
                invoke : function (a,b,c,d) {
                  try {
                    
                    __LINE__ = 82;
                    Runtime.assert( true ,a === 1,"a === 1",82,'harmony_function_test.js');
                    
                    __LINE__ = 83;
                    Runtime.assert( true ,b === 2,"b === 2",83,'harmony_function_test.js');
                    
                    __LINE__ = 84;
                    Runtime.assert( true ,c === 3,"c === 3",84,'harmony_function_test.js');
                    
                    __LINE__ = 85;
                    Runtime.assert( true ,d === 4,"d === 4",85,'harmony_function_test.js');
                    
                    __LINE__ = 86;
                    Runtime.assert( true , this  === propertySpread," this  === propertySpread",86,'harmony_function_test.js');
                  } catch(e){
                    Runtime.exceptionHandler(__LINE__, __FILE__, e);
                  }
                }
              };
          
          __LINE__ = 97;
          newSpread.prototype.valid =  true ;
          
          __LINE__ = 99;
          Runtime.spreadCall(undefined,normalSpread,[ true ,args], false );
          
          __LINE__ = 100;
          Runtime.spreadCall(propertySpread,propertySpread.invoke,[ true ,args], false );
          
          __LINE__ = 101;
          Runtime.spreadCall(undefined,newSpread,[ true ,args], true );
          
          __LINE__ = 103;
          var tinyArgs = [100,200],
              argtest =  {
                args : [1,2,3,4]
              };
          
          __LINE__ = 119;
          var propertySpreadWithArgs =  {
                invoke : function ($1,a,b,c,d,$2,e,f) {
                  try {
                    
                    __LINE__ = 121;
                    Runtime.assert( true ,$1 === 0,"$1 === 0",121,'harmony_function_test.js');
                    
                    __LINE__ = 122;
                    Runtime.assert( true ,a === 1,"a === 1",122,'harmony_function_test.js');
                    
                    __LINE__ = 123;
                    Runtime.assert( true ,b === 2,"b === 2",123,'harmony_function_test.js');
                    
                    __LINE__ = 124;
                    Runtime.assert( true ,c === 3,"c === 3",124,'harmony_function_test.js');
                    
                    __LINE__ = 125;
                    Runtime.assert( true ,$2 === 0,"$2 === 0",125,'harmony_function_test.js');
                    
                    __LINE__ = 126;
                    Runtime.assert( true ,d === 4,"d === 4",126,'harmony_function_test.js');
                    
                    __LINE__ = 127;
                    Runtime.assert( true ,e === 100,"e === 100",127,'harmony_function_test.js');
                    
                    __LINE__ = 128;
                    Runtime.assert( true ,f === 200,"f === 200",128,'harmony_function_test.js');
                    
                    __LINE__ = 129;
                    Runtime.assert( true , this  === propertySpreadWithArgs," this  === propertySpreadWithArgs",129,'harmony_function_test.js');
                  } catch(e){
                    Runtime.exceptionHandler(__LINE__, __FILE__, e);
                  }
                }
              };
          
          __LINE__ = 144;
          newSpreadWithArgs.prototype.valid =  true ;
          
          __LINE__ = 145;
          Runtime.spreadCall(undefined,normalSpread,[ true ,argtest.args], false );
          
          __LINE__ = 146;
          Runtime.spreadCall(undefined,normalSpreadWithArgs,[ false ,0, true ,args, false ,0, true ,tinyArgs], false );
          
          __LINE__ = 147;
          Runtime.spreadCall(propertySpreadWithArgs,propertySpreadWithArgs.invoke,[ false ,0, true ,args, false ,0, true ,tinyArgs], false );
          
          __LINE__ = 148;
          var inst = Runtime.spreadCall(undefined,newSpreadWithArgs,[ false ,0, true ,args, false ,0, true ,tinyArgs], true );
          
          __LINE__ = 149;
          Runtime.assert( true ,inst instanceof newSpreadWithArgs,"inst instanceof newSpreadWithArgs",149,'harmony_function_test.js');
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }();
    } catch(e){
      Runtime.exceptionHandler(__LINE__, __FILE__, e);
    }
  }();
}();
