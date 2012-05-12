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
        
        Runtime.assert( true ,typeof type === "string","typeof type === \"string\"",44,'_base.js');
        
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
  
  var Runtime =  {
        _global : global,
        _push : Array.prototype.push,
        _slice : Array.prototype.slice,
        getErrorMessage : function (e) {
          return (e.message)?e.message : (e.description)?e.description : e.toString();
        },
        isStopIteration : (function () {
          
          function isStopIteration(obj) {
            return obj === Runtime.StopIteration || rstopIteration.test(obj);
          }
          var rstopIteration = /StopIteration/;
          return isStopIteration;
        })(),
        throwException : function (exception) {
          try {
            throw exception;
          } catch(e){
            
            if (Runtime.isStopIteration(e)){
              throw new Error(e);
            } else {
              throw new Error( this .getErrorMessage(e));
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
          return (likeArray)? this ._slice.call(likeArray,index) : [];
        },
        extend : function (dest,source) {
          for (var prop in source){
            
            dest[prop] = source[prop];
          }
          return dest;
        }
      };
  
  Runtime.extend(Runtime, {
    Exception : function (line,file,e) {
       this .toString = function () {
        return Runtime.getErrorMessage(e)+" in file "+file+" at : "+line;
      };
    },
    exceptionHandler : function (line,file,e) {
      if (Runtime.isStopIteration(e)){
        
         this .throwException(e);
      } else {
        
         this .throwException(new  this .Exception(line,file,e));
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
    
    if ("WeakMap" in global){
      
      privateRecord = new WeakMap();
      
      createPrivateRecord = function (self,privateHolder,constructor) {
        var holder = new privateHolder;
        
        Runtime.createUnenumProp(holder,"__is_private__",1);
        
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
          
          Runtime.createUnenumProp(constructor,"__private__",holder);
          
          Runtime.createUnenumProp(self,"constructor",constructor);
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
    return Runtime.extend(Runtime, {
      extendClass : (Runtime.hasProto)?function (derived,base) {
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
            
            derived[i] = base[i];
          }
          
        } else {
          
          var inherit = function (){},
              proto = getPrototype(base);
          
          inherit.prototype = proto;
          
          derived.prototype = new inherit;
        }
        
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
    Runtime.extend(Runtime, {
      assert : (Runtime._global.console && Runtime._global.console.assert)?function (expect,exp,str,line,filename) {
        return Runtime._global.console.assert(expect === exp,"assertion failed : "+str+"\nexpect "+expect+" but got "+exp+"\nin file "+filename+" at : "+line);
      } : function (expect,exp,str,line,filename) {
        if (expect !== exp){
          
          Runtime.throwException("assertion failed : "+str+"\nexpect "+expect+" but got "+exp+"\nin file "+filename+" at : "+line);
        }
        
      }
    });
  }.call( this );
  
  __LINE__ = 0;
  !function () {
    try {
      var __FILE__ = "-1301891693-test.js",
          __LINE__ = 0;
      __LINE__ = 2;
      var x = function () {
            function constructor(){}
            function x() {
              try {
                __LINE__ = 2;
                Runtime.initializeClass(this,x,_mochaPrivateHolder,constructor,arguments,'x',2);
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            }
            try {
              
              __LINE__ = 2;
              var _mochaPrivateHolder = function (){};
              
              __LINE__ = 2;
              Runtime.createUnenumProp(constructor,"__harmony_class__",1);
              
              __LINE__ = 3;
              _mochaPrivateHolder.prototype.y = function () {
                function constructor(){}
                function y() {
                  try {
                    __LINE__ = 3;
                    Runtime.initializeClass(this,y,_mochaPrivateHolder,constructor,arguments,'y',3);
                  } catch(e){
                    Runtime.exceptionHandler(__LINE__, __FILE__, e);
                  }
                }
                try {
                  
                  __LINE__ = 3;
                  var _mochaPrivateHolder = function (){};
                  
                  __LINE__ = 3;
                  Runtime.createUnenumProp(constructor,"__harmony_class__",1);
                  
                  __LINE__ = 3;
                  Runtime.createUnenumProp(y.prototype,"constructor",constructor);
                  __LINE__ = 3;
                  return y;
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              }();
              
              __LINE__ = 6;
              _mochaPrivateHolder.prototype.m = function () {
                try {
                  __LINE__ = 6;
                  return Runtime.getInstanceBody( this ).y;
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              };
              
              __LINE__ = 2;
              Runtime.createUnenumProp(x.prototype,"constructor",constructor);
              __LINE__ = 2;
              return x;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          }(),
          m = "\u30c6\u30b9\u30c8\u3067\u30fc\u305f\u3092\u8fd4\u3059\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\n\u30c6\u30b9\u30c8\u3067\u30fc\u305f\u3092\u8fd4\u3059\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042\u3042",
          test = function () {
            try {
              __LINE__ = 15;
              return '\u30c7\u30fc\u30bf';
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          },
          m = [0,1,2,3,4],
          reg = /\u30c6\u30b9\u30c8\u6b63\u898f\u8868\u73fe/;
      
      __LINE__ = 19;
      Runtime.assert( true ,reg.test("\u30c6\u30b9\u30c8\u6b63\u898f\u8868\u73fe"),"reg.test(\"\u30c6\u30b9\u30c8\u6b63\u898f\u8868\u73fe\")",19,'test.js');
    } catch(e){
      Runtime.exceptionHandler(__LINE__, __FILE__, e);
    }
  }();
}();