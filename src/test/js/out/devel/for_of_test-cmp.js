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
  
  __LINE__ = 2;
  !function () {
    try {
      var __FILE__ = "iterators",
          __LINE__ = 0;
      __LINE__ = 2;
      Runtime.modules.add('iterators');
      
      __LINE__ = 0;
      var iterators = Runtime.modules.get('iterators').iterators = function () {
            function allItems(obj) {
              try {
                __LINE__ = 54;
                var _mochaLocalTmp23 = {};
                
                __LINE__ = 54;
                Runtime.createUnenumProp(_mochaLocalTmp23,iterator,
                function () {
                  try {
                    __LINE__ = 54;
                    return function () {
                      try {
                        __LINE__ = 54;
                        var _mochaIsNewBorn = true,
                            _yieldResult = undefined,
                            _yieldState = 0,
                            length,
                            _mochaLocalTmp22,
                            x,
                            _mochaLocalTmp21 = [],
                            _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                              try {
                                __LINE__ = 54;
                                !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler('attempt to send to newborn generator.');
                                
                                __LINE__ = 54;
                                while (1){
                                  
                                  __LINE__ = 54;
                                  switch (_yieldState) {
                                    case 0 :
                                      
                                      __LINE__ = 54;
                                      for (var _mochaLocalTmp20 in obj){
                                        
                                        __LINE__ = 54;
                                        _mochaLocalTmp21.push(_mochaLocalTmp20);
                                      }
                                      
                                      __LINE__ = 54;
                                      _mochaLocalTmp22 = 0;
                                      
                                      __LINE__ = 54;
                                      length = _mochaLocalTmp21.length;
                                      
                                      __LINE__ = 54;
                                      if (!(_mochaLocalTmp22<length)){
                                        
                                        __LINE__ = 54;
                                        _yieldState = -1;
                                        __LINE__ = 54;
                                        break;
                                      }
                                    case 1 :
                                      
                                      __LINE__ = 56;
                                      _yieldState = 2;
                                      
                                      __LINE__ = 54;
                                      x = _mochaLocalTmp21[_mochaLocalTmp22];
                                      __LINE__ = 56;
                                      return [x,obj[x]];
                                    case 2 :
                                      
                                      __LINE__ = 54;
                                       ++ _mochaLocalTmp22;
                                      
                                      __LINE__ = 54;
                                      if (_mochaLocalTmp22<length){
                                        
                                        __LINE__ = 2;
                                        _yieldState = 1;
                                        __LINE__ = 54;
                                        break;
                                      } else {
                                        __LINE__ = 2;
                                        _yieldState = -1;
                                      }
                                    case -1 :
                                      
                                      __LINE__ = 54;
                                      if (_isYieldSafe){
                                        __LINE__ = 54;
                                        return undefined;
                                      }
                                      
                                      __LINE__ = 54;
                                      Runtime.throwStopIteration();
                                      
                                  }
                                  
                                }
                                
                              } catch(e){
                                Runtime.exceptionHandler(__LINE__, __FILE__, e);
                              }
                            };
                        __LINE__ = 54;
                        return Runtime.createGenerator(_mochaGenerator,
                        function () {
                          try {
                            __LINE__ = 54;
                            _yieldState = -1;
                          } catch(e){
                            Runtime.exceptionHandler(__LINE__, __FILE__, e);
                          }
                        },this);
                      } catch(e){
                        Runtime.exceptionHandler(__LINE__, __FILE__, e);
                      }
                    }();
                  } catch(e){
                    Runtime.exceptionHandler(__LINE__, __FILE__, e);
                  }
                });
                __LINE__ = 52;
                return _mochaLocalTmp23;
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            }
            function allValues(obj) {
              try {
                __LINE__ = 46;
                var _mochaLocalTmp19 = {};
                
                __LINE__ = 46;
                Runtime.createUnenumProp(_mochaLocalTmp19,iterator,
                function () {
                  try {
                    __LINE__ = 46;
                    return function () {
                      try {
                        __LINE__ = 46;
                        var _mochaIsNewBorn = true,
                            _yieldResult = undefined,
                            _yieldState = 0,
                            length,
                            _mochaLocalTmp18,
                            x,
                            _mochaLocalTmp17 = [],
                            _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                              try {
                                __LINE__ = 46;
                                !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler('attempt to send to newborn generator.');
                                
                                __LINE__ = 46;
                                while (1){
                                  
                                  __LINE__ = 46;
                                  switch (_yieldState) {
                                    case 0 :
                                      
                                      __LINE__ = 46;
                                      for (var _mochaLocalTmp16 in obj){
                                        
                                        __LINE__ = 46;
                                        _mochaLocalTmp17.push(_mochaLocalTmp16);
                                      }
                                      
                                      __LINE__ = 46;
                                      _mochaLocalTmp18 = 0;
                                      
                                      __LINE__ = 46;
                                      length = _mochaLocalTmp17.length;
                                      
                                      __LINE__ = 46;
                                      if (!(_mochaLocalTmp18<length)){
                                        
                                        __LINE__ = 46;
                                        _yieldState = -1;
                                        __LINE__ = 46;
                                        break;
                                      }
                                    case 1 :
                                      
                                      __LINE__ = 48;
                                      _yieldState = 2;
                                      
                                      __LINE__ = 46;
                                      x = _mochaLocalTmp17[_mochaLocalTmp18];
                                      __LINE__ = 48;
                                      return obj[x];
                                    case 2 :
                                      
                                      __LINE__ = 46;
                                       ++ _mochaLocalTmp18;
                                      
                                      __LINE__ = 46;
                                      if (_mochaLocalTmp18<length){
                                        
                                        __LINE__ = 2;
                                        _yieldState = 1;
                                        __LINE__ = 46;
                                        break;
                                      } else {
                                        __LINE__ = 2;
                                        _yieldState = -1;
                                      }
                                    case -1 :
                                      
                                      __LINE__ = 46;
                                      if (_isYieldSafe){
                                        __LINE__ = 46;
                                        return undefined;
                                      }
                                      
                                      __LINE__ = 46;
                                      Runtime.throwStopIteration();
                                      
                                  }
                                  
                                }
                                
                              } catch(e){
                                Runtime.exceptionHandler(__LINE__, __FILE__, e);
                              }
                            };
                        __LINE__ = 46;
                        return Runtime.createGenerator(_mochaGenerator,
                        function () {
                          try {
                            __LINE__ = 46;
                            _yieldState = -1;
                          } catch(e){
                            Runtime.exceptionHandler(__LINE__, __FILE__, e);
                          }
                        },this);
                      } catch(e){
                        Runtime.exceptionHandler(__LINE__, __FILE__, e);
                      }
                    }();
                  } catch(e){
                    Runtime.exceptionHandler(__LINE__, __FILE__, e);
                  }
                });
                __LINE__ = 44;
                return _mochaLocalTmp19;
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            }
            function allKeys(obj) {
              try {
                __LINE__ = 38;
                var _mochaLocalTmp15 = {};
                
                __LINE__ = 38;
                Runtime.createUnenumProp(_mochaLocalTmp15,iterator,
                function () {
                  try {
                    __LINE__ = 38;
                    return function () {
                      try {
                        __LINE__ = 38;
                        var _mochaIsNewBorn = true,
                            _yieldResult = undefined,
                            _yieldState = 0,
                            length,
                            _mochaLocalTmp14,
                            x,
                            _mochaLocalTmp13 = [],
                            _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                              try {
                                __LINE__ = 38;
                                !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler('attempt to send to newborn generator.');
                                
                                __LINE__ = 38;
                                while (1){
                                  
                                  __LINE__ = 38;
                                  switch (_yieldState) {
                                    case 0 :
                                      
                                      __LINE__ = 38;
                                      for (var _mochaLocalTmp12 in obj){
                                        
                                        __LINE__ = 38;
                                        _mochaLocalTmp13.push(_mochaLocalTmp12);
                                      }
                                      
                                      __LINE__ = 38;
                                      _mochaLocalTmp14 = 0;
                                      
                                      __LINE__ = 38;
                                      length = _mochaLocalTmp13.length;
                                      
                                      __LINE__ = 38;
                                      if (!(_mochaLocalTmp14<length)){
                                        
                                        __LINE__ = 38;
                                        _yieldState = -1;
                                        __LINE__ = 38;
                                        break;
                                      }
                                    case 1 :
                                      
                                      __LINE__ = 40;
                                      _yieldState = 2;
                                      
                                      __LINE__ = 38;
                                      x = _mochaLocalTmp13[_mochaLocalTmp14];
                                      __LINE__ = 40;
                                      return x;
                                    case 2 :
                                      
                                      __LINE__ = 38;
                                       ++ _mochaLocalTmp14;
                                      
                                      __LINE__ = 38;
                                      if (_mochaLocalTmp14<length){
                                        
                                        __LINE__ = 2;
                                        _yieldState = 1;
                                        __LINE__ = 38;
                                        break;
                                      } else {
                                        __LINE__ = 2;
                                        _yieldState = -1;
                                      }
                                    case -1 :
                                      
                                      __LINE__ = 38;
                                      if (_isYieldSafe){
                                        __LINE__ = 38;
                                        return undefined;
                                      }
                                      
                                      __LINE__ = 38;
                                      Runtime.throwStopIteration();
                                      
                                  }
                                  
                                }
                                
                              } catch(e){
                                Runtime.exceptionHandler(__LINE__, __FILE__, e);
                              }
                            };
                        __LINE__ = 38;
                        return Runtime.createGenerator(_mochaGenerator,
                        function () {
                          try {
                            __LINE__ = 38;
                            _yieldState = -1;
                          } catch(e){
                            Runtime.exceptionHandler(__LINE__, __FILE__, e);
                          }
                        },this);
                      } catch(e){
                        Runtime.exceptionHandler(__LINE__, __FILE__, e);
                      }
                    }();
                  } catch(e){
                    Runtime.exceptionHandler(__LINE__, __FILE__, e);
                  }
                });
                __LINE__ = 36;
                return _mochaLocalTmp15;
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            }
            function items(obj) {
              try {
                __LINE__ = 28;
                var _mochaLocalTmp11 = {};
                
                __LINE__ = 28;
                Runtime.createUnenumProp(_mochaLocalTmp11,iterator,
                function () {
                  try {
                    __LINE__ = 28;
                    return function () {
                      try {
                        __LINE__ = 28;
                        var _mochaIsNewBorn = true,
                            _yieldResult = undefined,
                            _yieldState = 0,
                            length,
                            _mochaLocalTmp10,
                            x,
                            _mochaLocalTmp9 = [],
                            _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                              try {
                                __LINE__ = 28;
                                !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler('attempt to send to newborn generator.');
                                
                                __LINE__ = 28;
                                while (1){
                                  
                                  __LINE__ = 28;
                                  switch (_yieldState) {
                                    case 0 :
                                      
                                      __LINE__ = 28;
                                      for (var _mochaLocalTmp8 in obj){
                                        
                                        __LINE__ = 28;
                                        _mochaLocalTmp9.push(_mochaLocalTmp8);
                                      }
                                      
                                      __LINE__ = 28;
                                      _mochaLocalTmp10 = 0;
                                      
                                      __LINE__ = 28;
                                      length = _mochaLocalTmp9.length;
                                      
                                      __LINE__ = 28;
                                      if (!(_mochaLocalTmp10<length)){
                                        
                                        __LINE__ = 28;
                                        _yieldState = -1;
                                        __LINE__ = 28;
                                        break;
                                      }
                                    case 1 :
                                      
                                      __LINE__ = 28;
                                      x = _mochaLocalTmp9[_mochaLocalTmp10];
                                      
                                      __LINE__ = 30;
                                      if (hasOwn.call(obj,x)){
                                        
                                        __LINE__ = 30;
                                        _yieldState = 2;
                                        __LINE__ = 30;
                                        break;
                                      } else {
                                        
                                        __LINE__ = 30;
                                        _yieldState = 3;
                                        __LINE__ = 30;
                                        break;
                                      }
                                    case 2 :
                                      
                                      __LINE__ = 30;
                                      _yieldState = 3;
                                      __LINE__ = 30;
                                      return [x,obj[x]];
                                    case 3 :
                                      
                                      __LINE__ = 30;
                                      _yieldState = 4;
                                      __LINE__ = 30;
                                      break;
                                    case 4 :
                                      
                                      __LINE__ = 28;
                                       ++ _mochaLocalTmp10;
                                      
                                      __LINE__ = 28;
                                      if (_mochaLocalTmp10<length){
                                        
                                        __LINE__ = 2;
                                        _yieldState = 1;
                                        __LINE__ = 28;
                                        break;
                                      } else {
                                        __LINE__ = 2;
                                        _yieldState = -1;
                                      }
                                    case -1 :
                                      
                                      __LINE__ = 28;
                                      if (_isYieldSafe){
                                        __LINE__ = 28;
                                        return undefined;
                                      }
                                      
                                      __LINE__ = 28;
                                      Runtime.throwStopIteration();
                                      
                                  }
                                  
                                }
                                
                              } catch(e){
                                Runtime.exceptionHandler(__LINE__, __FILE__, e);
                              }
                            };
                        __LINE__ = 28;
                        return Runtime.createGenerator(_mochaGenerator,
                        function () {
                          try {
                            __LINE__ = 28;
                            _yieldState = -1;
                          } catch(e){
                            Runtime.exceptionHandler(__LINE__, __FILE__, e);
                          }
                        },this);
                      } catch(e){
                        Runtime.exceptionHandler(__LINE__, __FILE__, e);
                      }
                    }();
                  } catch(e){
                    Runtime.exceptionHandler(__LINE__, __FILE__, e);
                  }
                });
                __LINE__ = 26;
                return _mochaLocalTmp11;
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            }
            function values(obj) {
              try {
                __LINE__ = 16;
                var _mochaLocalTmp7 = {};
                
                __LINE__ = 16;
                Runtime.createUnenumProp(_mochaLocalTmp7,iterator,
                function () {
                  try {
                    __LINE__ = 16;
                    return function () {
                      try {
                        __LINE__ = 16;
                        var _mochaIsNewBorn = true,
                            _yieldResult = undefined,
                            _yieldState = 0,
                            length,
                            _mochaLocalTmp6,
                            x,
                            _mochaLocalTmp5 = [],
                            _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                              try {
                                __LINE__ = 16;
                                !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler('attempt to send to newborn generator.');
                                
                                __LINE__ = 16;
                                while (1){
                                  
                                  __LINE__ = 16;
                                  switch (_yieldState) {
                                    case 0 :
                                      
                                      __LINE__ = 18;
                                      for (var _mochaLocalTmp4 in obj){
                                        
                                        __LINE__ = 18;
                                        _mochaLocalTmp5.push(_mochaLocalTmp4);
                                      }
                                      
                                      __LINE__ = 18;
                                      _mochaLocalTmp6 = 0;
                                      
                                      __LINE__ = 18;
                                      length = _mochaLocalTmp5.length;
                                      
                                      __LINE__ = 18;
                                      if (!(_mochaLocalTmp6<length)){
                                        
                                        __LINE__ = 18;
                                        _yieldState = -1;
                                        __LINE__ = 18;
                                        break;
                                      }
                                    case 1 :
                                      
                                      __LINE__ = 18;
                                      x = _mochaLocalTmp5[_mochaLocalTmp6];
                                      
                                      __LINE__ = 18;
                                      if (hasOwn.call(obj,x)){
                                        
                                        __LINE__ = 18;
                                        _yieldState = 2;
                                        __LINE__ = 18;
                                        break;
                                      } else {
                                        
                                        __LINE__ = 18;
                                        _yieldState = 3;
                                        __LINE__ = 18;
                                        break;
                                      }
                                    case 2 :
                                      
                                      __LINE__ = 20;
                                      _yieldState = 3;
                                      __LINE__ = 20;
                                      return obj[x];
                                    case 3 :
                                      
                                      __LINE__ = 18;
                                      _yieldState = 4;
                                      __LINE__ = 18;
                                      break;
                                    case 4 :
                                      
                                      __LINE__ = 18;
                                       ++ _mochaLocalTmp6;
                                      
                                      __LINE__ = 18;
                                      if (_mochaLocalTmp6<length){
                                        
                                        __LINE__ = 2;
                                        _yieldState = 1;
                                        __LINE__ = 18;
                                        break;
                                      } else {
                                        __LINE__ = 2;
                                        _yieldState = -1;
                                      }
                                    case -1 :
                                      
                                      __LINE__ = 16;
                                      if (_isYieldSafe){
                                        __LINE__ = 16;
                                        return undefined;
                                      }
                                      
                                      __LINE__ = 16;
                                      Runtime.throwStopIteration();
                                      
                                  }
                                  
                                }
                                
                              } catch(e){
                                Runtime.exceptionHandler(__LINE__, __FILE__, e);
                              }
                            };
                        __LINE__ = 16;
                        return Runtime.createGenerator(_mochaGenerator,
                        function () {
                          try {
                            __LINE__ = 16;
                            _yieldState = -1;
                          } catch(e){
                            Runtime.exceptionHandler(__LINE__, __FILE__, e);
                          }
                        },this);
                      } catch(e){
                        Runtime.exceptionHandler(__LINE__, __FILE__, e);
                      }
                    }();
                  } catch(e){
                    Runtime.exceptionHandler(__LINE__, __FILE__, e);
                  }
                });
                __LINE__ = 16;
                return _mochaLocalTmp7;
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            }
            function keys(obj) {
              try {
                __LINE__ = 6;
                var _mochaLocalTmp3 = {};
                
                __LINE__ = 6;
                Runtime.createUnenumProp(_mochaLocalTmp3,iterator,
                function () {
                  try {
                    __LINE__ = 6;
                    return function () {
                      try {
                        __LINE__ = 6;
                        var _mochaIsNewBorn = true,
                            _yieldResult = undefined,
                            _yieldState = 0,
                            length,
                            _mochaLocalTmp2,
                            x,
                            _mochaLocalTmp1 = [],
                            _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                              try {
                                __LINE__ = 6;
                                !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler('attempt to send to newborn generator.');
                                
                                __LINE__ = 6;
                                while (1){
                                  
                                  __LINE__ = 6;
                                  switch (_yieldState) {
                                    case 0 :
                                      
                                      __LINE__ = 6;
                                      for (var _mochaLocalTmp0 in obj){
                                        
                                        __LINE__ = 6;
                                        _mochaLocalTmp1.push(_mochaLocalTmp0);
                                      }
                                      
                                      __LINE__ = 6;
                                      _mochaLocalTmp2 = 0;
                                      
                                      __LINE__ = 6;
                                      length = _mochaLocalTmp1.length;
                                      
                                      __LINE__ = 6;
                                      if (!(_mochaLocalTmp2<length)){
                                        
                                        __LINE__ = 6;
                                        _yieldState = -1;
                                        __LINE__ = 6;
                                        break;
                                      }
                                    case 1 :
                                      
                                      __LINE__ = 6;
                                      x = _mochaLocalTmp1[_mochaLocalTmp2];
                                      
                                      __LINE__ = 8;
                                      if (hasOwn.call(obj,x)){
                                        
                                        __LINE__ = 8;
                                        _yieldState = 2;
                                        __LINE__ = 8;
                                        break;
                                      } else {
                                        
                                        __LINE__ = 8;
                                        _yieldState = 3;
                                        __LINE__ = 8;
                                        break;
                                      }
                                    case 2 :
                                      
                                      __LINE__ = 8;
                                      _yieldState = 3;
                                      __LINE__ = 8;
                                      return x;
                                    case 3 :
                                      
                                      __LINE__ = 8;
                                      _yieldState = 4;
                                      __LINE__ = 8;
                                      break;
                                    case 4 :
                                      
                                      __LINE__ = 6;
                                       ++ _mochaLocalTmp2;
                                      
                                      __LINE__ = 6;
                                      if (_mochaLocalTmp2<length){
                                        
                                        __LINE__ = 2;
                                        _yieldState = 1;
                                        __LINE__ = 6;
                                        break;
                                      } else {
                                        __LINE__ = 2;
                                        _yieldState = -1;
                                      }
                                    case -1 :
                                      
                                      __LINE__ = 6;
                                      if (_isYieldSafe){
                                        __LINE__ = 6;
                                        return undefined;
                                      }
                                      
                                      __LINE__ = 6;
                                      Runtime.throwStopIteration();
                                      
                                  }
                                  
                                }
                                
                              } catch(e){
                                Runtime.exceptionHandler(__LINE__, __FILE__, e);
                              }
                            };
                        __LINE__ = 6;
                        return Runtime.createGenerator(_mochaGenerator,
                        function () {
                          try {
                            __LINE__ = 6;
                            _yieldState = -1;
                          } catch(e){
                            Runtime.exceptionHandler(__LINE__, __FILE__, e);
                          }
                        },this);
                      } catch(e){
                        Runtime.exceptionHandler(__LINE__, __FILE__, e);
                      }
                    }();
                  } catch(e){
                    Runtime.exceptionHandler(__LINE__, __FILE__, e);
                  }
                });
                __LINE__ = 4;
                return _mochaLocalTmp3;
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            }
            try {
              
              __LINE__ = 0;
              var _mochaLocalExport = {},
                  hasOwn = {}.hasOwnProperty,
                  iterator = _mochaLocalExport.iterator = "__mocha_iterator_special_key__";
              
              __LINE__ = 4;
              _mochaLocalExport.keys = keys;
              
              __LINE__ = 14;
              _mochaLocalExport.values = values;
              
              __LINE__ = 26;
              _mochaLocalExport.items = items;
              
              __LINE__ = 36;
              _mochaLocalExport.allKeys = allKeys;
              
              __LINE__ = 44;
              _mochaLocalExport.allValues = allValues;
              
              __LINE__ = 52;
              _mochaLocalExport.allItems = allItems;
              __LINE__ = 0;
              return _mochaLocalExport;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          }();
    } catch(e){
      Runtime.exceptionHandler(__LINE__, __FILE__, e);
    }
  }();
  
  __LINE__ = 0;
  !function () {
    try {
      var __FILE__ = "-759650552-for_of_test.js",
          __LINE__ = 0;
      __LINE__ = 2;
      Runtime.modules.add('-759650552-for_of_test.js');
      
      __LINE__ = 1;
      var _mochaLocalTmp0 = Runtime.modules.get('iterators').iterators,
          iterator = _mochaLocalTmp0.iterator,
          _mochaLocalTmp9 =  {
            arr : [],
            add : function (value) {
              try {
                __LINE__ = 23;
                 this .arr.push(value);
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            }
          };
      
      __LINE__ = 21;
      Runtime.createUnenumProp(_mochaLocalTmp9,iterator,
      function () {
        try {
          __LINE__ = 26;
          var arr =  this .arr;
          __LINE__ = 27;
          return  {
            index : 0,
            next : function () {
              try {
                __LINE__ = 30;
                if (arr.length> this .index){
                  
                  __LINE__ = 31;
                  var ret = arr[ this .index];
                  
                  __LINE__ = 32;
                   this .index ++ ;
                  __LINE__ = 33;
                  return ret;
                } else {
                  __LINE__ = 35;
                  return undefined;
                }
                
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            }
          };
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      });
      
      __LINE__ = 2;
      var item = function (obj) {
            try {
              __LINE__ = 4;
              var _mochaLocalTmp4 = {};
              
              __LINE__ = 4;
              Runtime.createUnenumProp(_mochaLocalTmp4,iterator,
              function () {
                try {
                  __LINE__ = 4;
                  var _mochaIsNewBorn = true,
                      _yieldResult = undefined,
                      _yieldState = 0,
                      length,
                      _mochaLocalTmp3,
                      i,
                      _mochaLocalTmp2 = [],
                      _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                        try {
                          __LINE__ = 4;
                          !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler('attempt to send to newborn generator.');
                          
                          __LINE__ = 4;
                          while (1){
                            
                            __LINE__ = 4;
                            switch (_yieldState) {
                              case 0 :
                                
                                __LINE__ = 5;
                                for (var _mochaLocalTmp1 in obj){
                                  
                                  __LINE__ = 5;
                                  _mochaLocalTmp2.push(_mochaLocalTmp1);
                                }
                                
                                __LINE__ = 5;
                                _mochaLocalTmp3 = 0;
                                
                                __LINE__ = 5;
                                length = _mochaLocalTmp2.length;
                                
                                __LINE__ = 5;
                                if (!(_mochaLocalTmp3<length)){
                                  
                                  __LINE__ = 5;
                                  _yieldState = -1;
                                  __LINE__ = 5;
                                  break;
                                }
                              case 1 :
                                
                                __LINE__ = 6;
                                _yieldState = 2;
                                
                                __LINE__ = 5;
                                i = _mochaLocalTmp2[_mochaLocalTmp3];
                                
                                __LINE__ = 5;
                                i = obj[i];
                                __LINE__ = 6;
                                return i;
                              case 2 :
                                
                                __LINE__ = 5;
                                 ++ _mochaLocalTmp3;
                                
                                __LINE__ = 5;
                                if (_mochaLocalTmp3<length){
                                  
                                  __LINE__ = 0;
                                  _yieldState = 1;
                                  __LINE__ = 5;
                                  break;
                                } else {
                                  __LINE__ = 0;
                                  _yieldState = -1;
                                }
                              case -1 :
                                
                                __LINE__ = 4;
                                if (_isYieldSafe){
                                  __LINE__ = 4;
                                  return undefined;
                                }
                                
                                __LINE__ = 4;
                                Runtime.throwStopIteration();
                                
                            }
                            
                          }
                          
                        } catch(e){
                          Runtime.exceptionHandler(__LINE__, __FILE__, e);
                        }
                      };
                  __LINE__ = 4;
                  return Runtime.createGenerator(_mochaGenerator,
                  function () {
                    try {
                      __LINE__ = 4;
                      _yieldState = -1;
                    } catch(e){
                      Runtime.exceptionHandler(__LINE__, __FILE__, e);
                    }
                  },this);
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              });
              __LINE__ = 3;
              return _mochaLocalTmp4;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          },
          key = function (obj) {
            try {
              __LINE__ = 13;
              var _mochaLocalTmp8 = {};
              
              __LINE__ = 13;
              Runtime.createUnenumProp(_mochaLocalTmp8,iterator,
              function () {
                try {
                  __LINE__ = 13;
                  var _mochaIsNewBorn = true,
                      _yieldResult = undefined,
                      _yieldState = 0,
                      length,
                      _mochaLocalTmp7,
                      i,
                      _mochaLocalTmp6 = [],
                      _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                        try {
                          __LINE__ = 13;
                          !_isYieldSend?_mochaIsNewBorn = false : _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined && Runtime.exceptionHandler('attempt to send to newborn generator.');
                          
                          __LINE__ = 13;
                          while (1){
                            
                            __LINE__ = 13;
                            switch (_yieldState) {
                              case 0 :
                                
                                __LINE__ = 14;
                                for (var _mochaLocalTmp5 in obj){
                                  
                                  __LINE__ = 14;
                                  _mochaLocalTmp6.push(_mochaLocalTmp5);
                                }
                                
                                __LINE__ = 14;
                                _mochaLocalTmp7 = 0;
                                
                                __LINE__ = 14;
                                length = _mochaLocalTmp6.length;
                                
                                __LINE__ = 14;
                                if (!(_mochaLocalTmp7<length)){
                                  
                                  __LINE__ = 14;
                                  _yieldState = -1;
                                  __LINE__ = 14;
                                  break;
                                }
                              case 1 :
                                
                                __LINE__ = 15;
                                _yieldState = 2;
                                
                                __LINE__ = 14;
                                i = _mochaLocalTmp6[_mochaLocalTmp7];
                                __LINE__ = 15;
                                return i;
                              case 2 :
                                
                                __LINE__ = 14;
                                 ++ _mochaLocalTmp7;
                                
                                __LINE__ = 14;
                                if (_mochaLocalTmp7<length){
                                  
                                  __LINE__ = 0;
                                  _yieldState = 1;
                                  __LINE__ = 14;
                                  break;
                                } else {
                                  __LINE__ = 0;
                                  _yieldState = -1;
                                }
                              case -1 :
                                
                                __LINE__ = 13;
                                if (_isYieldSafe){
                                  __LINE__ = 13;
                                  return undefined;
                                }
                                
                                __LINE__ = 13;
                                Runtime.throwStopIteration();
                                
                            }
                            
                          }
                          
                        } catch(e){
                          Runtime.exceptionHandler(__LINE__, __FILE__, e);
                        }
                      };
                  __LINE__ = 13;
                  return Runtime.createGenerator(_mochaGenerator,
                  function () {
                    try {
                      __LINE__ = 13;
                      _yieldState = -1;
                    } catch(e){
                      Runtime.exceptionHandler(__LINE__, __FILE__, e);
                    }
                  },this);
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              });
              __LINE__ = 12;
              return _mochaLocalTmp8;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          },
          iter = _mochaLocalTmp9,
          testObj =  {
            value1 : 100,
            value2 : 200,
            value3 : 300,
            value4 : 400
          },
          ret = [],
          i,
          _mochaLocalTmp10 = item(testObj);
      
      __LINE__ = 49;
      _mochaLocalTmp10 = Runtime.hasIterator(_mochaLocalTmp10)?Runtime.getIterator(_mochaLocalTmp10) : _mochaLocalTmp10;
      
      __LINE__ = 49;
      if (_mochaLocalTmp10.__nothrowNext__){
        __LINE__ = 49;
        while ((i = _mochaLocalTmp10.__nothrowNext__())){
          __LINE__ = 50;
          ret.push(i);
        }
        
      } else {
        __LINE__ = 49;
        Runtime.exceptionHandler(49,'for_of_test.js','for of statement expect iterator or generator object.');
      }
      
      __LINE__ = 52;
      Runtime.assert( true ,ret[0] === 100,"ret[0] === 100",52,'for_of_test.js');
      
      __LINE__ = 53;
      Runtime.assert( true ,ret[1] === 200,"ret[1] === 200",53,'for_of_test.js');
      
      __LINE__ = 54;
      Runtime.assert( true ,ret[2] === 300,"ret[2] === 300",54,'for_of_test.js');
      
      __LINE__ = 55;
      Runtime.assert( true ,ret[3] === 400,"ret[3] === 400",55,'for_of_test.js');
      
      __LINE__ = 57;
      ret = [];
      
      __LINE__ = 58;
      var x,
          _mochaLocalTmp11 = key(testObj);
      
      __LINE__ = 58;
      _mochaLocalTmp11 = Runtime.hasIterator(_mochaLocalTmp11)?Runtime.getIterator(_mochaLocalTmp11) : _mochaLocalTmp11;
      
      __LINE__ = 58;
      if (_mochaLocalTmp11.__nothrowNext__){
        __LINE__ = 58;
        while ((x = _mochaLocalTmp11.__nothrowNext__())){
          __LINE__ = 59;
          ret.push(x);
        }
        
      } else {
        __LINE__ = 58;
        Runtime.exceptionHandler(58,'for_of_test.js','for of statement expect iterator or generator object.');
      }
      
      __LINE__ = 61;
      Runtime.assert( true ,ret[0] === "value1","ret[0] === \"value1\"",61,'for_of_test.js');
      
      __LINE__ = 62;
      Runtime.assert( true ,ret[1] === "value2","ret[1] === \"value2\"",62,'for_of_test.js');
      
      __LINE__ = 63;
      Runtime.assert( true ,ret[2] === "value3","ret[2] === \"value3\"",63,'for_of_test.js');
      
      __LINE__ = 64;
      Runtime.assert( true ,ret[3] === "value4","ret[3] === \"value4\"",64,'for_of_test.js');
      
      __LINE__ = 66;
      ret = [];
      
      __LINE__ = 67;
      iter.add(100);
      
      __LINE__ = 68;
      iter.add(200);
      
      __LINE__ = 69;
      iter.add(300);
      
      __LINE__ = 70;
      iter.add(400);
      
      __LINE__ = 71;
      var _mochaLocalTmp12 = iter;
      
      __LINE__ = 71;
      _mochaLocalTmp12 = Runtime.hasIterator(_mochaLocalTmp12)?Runtime.getIterator(_mochaLocalTmp12) : _mochaLocalTmp12;
      
      __LINE__ = 71;
      if (_mochaLocalTmp12.__nothrowNext__){
        __LINE__ = 71;
        while ((i = _mochaLocalTmp12.__nothrowNext__())){
          __LINE__ = 72;
          ret.push(i);
        }
        
      } else {
        __LINE__ = 71;
        Runtime.exceptionHandler(71,'for_of_test.js','for of statement expect iterator or generator object.');
      }
      
      __LINE__ = 74;
      Runtime.assert( true ,ret[0] === 100,"ret[0] === 100",74,'for_of_test.js');
      
      __LINE__ = 75;
      Runtime.assert( true ,ret[1] === 200,"ret[1] === 200",75,'for_of_test.js');
      
      __LINE__ = 76;
      Runtime.assert( true ,ret[2] === 300,"ret[2] === 300",76,'for_of_test.js');
      
      __LINE__ = 77;
      Runtime.assert( true ,ret[3] === 400,"ret[3] === 400",77,'for_of_test.js');
    } catch(e){
      Runtime.exceptionHandler(__LINE__, __FILE__, e);
    }
  }();
}();
