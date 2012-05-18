!function() {
  var __FILE__ = "__Runtime",
      __LINE__ = 0;
  
  var global = (this !==  null )?this : typeof window === 'object'?window : {},
      __Runtime =  {
        _global : global,
        _NULL : {},
        _push : [].push,
        _slice : [].slice,
        getErrorMessage : function (e) {
          return (e.message)?e.message : (e.description)?e.description : e.toString();
        },
        isStopIteration : function () {
          function isStopIteration(obj) {
            return obj === __Runtime.StopIteration || rstopIteration.test(obj);
          }
          
          var rstopIteration = /StopIteration/;
          return isStopIteration;
        }(),
        throwException : function (exception) {
          try {
            throw exception;
          } catch(e){
            
            if (__Runtime.isStopIteration(e)){
              throw new Error(e);
            }
            throw new Error(this.getErrorMessage(e));
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
            
            ret =  false ;
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
  
  __Runtime.extend(__Runtime, {
    Exception : function (line,file,e) {
      this.toString = function () {
        return __Runtime.getErrorMessage(e)+" in file "+file+" at : "+line;
      };
    },
    exceptionHandler : function (line,file,e) {
      __Runtime.isStopIteration(e)?this.throwException(e) : this.throwException(new this.Exception(line,file,e));
    }
  });
  
  __Runtime.extend(__Runtime, {
    assert : (__Runtime._global.console && __Runtime._global.console.assert)?function (expect,exp,str,line,filename) {
      return __Runtime._global.console.assert(expect === exp,"assertion failed : "+str+"\nexpect "+expect+" but got "+exp+"\nin file "+filename+" at : "+line);
    } : function (expect,exp,str,line,filename) {
      expect !== exp && __Runtime.throwException("assertion failed : "+str+"\nexpect "+expect+" but got "+exp+"\nin file "+filename+" at : "+line);
    }
  });
  
  __LINE__ = 0;
  !function () {
    try {
      __LINE__ = 2;
      var object =  {
            value1 : 100,
            value2 :  {
              value3 : 100
            },
            value4 : [100,200,300],
            value5 :  {
              value6 : [ {
                value7 : 100
              }]
            },
            "@value" :  {
              strvalue : 100
            }
          },
          array = [ {
            value1 : 100
          },200, {
            value2 : 100
          }, {
            "value3" : 100
          }, {
            value4 :  {
              value5 : [100,200]
            }
          }];
      
      __LINE__ = 17;
      !function () {
        try {
          __LINE__ = 18;
          var value1 = object.value1,
              value3 = object.value2 && object.value2.value3?object.value2.value3 : undefined,
              value5_ = object.value4 && object.value4[0]?object.value4[0] : undefined,
              value6_ = object.value4 && object.value4[1]?object.value4[1] : undefined,
              value7_ = object.value4 && object.value4[2]?object.value4[2] : undefined,
              value7 = object.value5 && object.value5.value6 && object.value5.value6[0] && object.value5.value6[0].value7?object.value5.value6[0].value7 : undefined,
              strvalue = object["@value"] && object["@value"].strvalue?object["@value"].strvalue : undefined;
          
          __LINE__ = 19;
          __Runtime.assert( true ,value1 === 100,"value1 === 100",19,'destructuring_test.js');
          
          __LINE__ = 20;
          __Runtime.assert( true ,value3 === 100,"value3 === 100",20,'destructuring_test.js');
          
          __LINE__ = 21;
          __Runtime.assert( true ,value5_ === 100,"value5_ === 100",21,'destructuring_test.js');
          
          __LINE__ = 22;
          __Runtime.assert( true ,value6_ === 200,"value6_ === 200",22,'destructuring_test.js');
          
          __LINE__ = 23;
          __Runtime.assert( true ,value7_ === 300,"value7_ === 300",23,'destructuring_test.js');
          
          __LINE__ = 24;
          __Runtime.assert( true ,value7 === 100,"value7 === 100",24,'destructuring_test.js');
          
          __LINE__ = 25;
          __Runtime.assert( true ,strvalue === 100,"strvalue === 100",25,'destructuring_test.js');
          
          __LINE__ = 27;
          value1 = object.value1;
          
          __LINE__ = 28;
          __Runtime.assert( true ,value1 === 100,"value1 === 100",28,'destructuring_test.js');
          
          __LINE__ = 29;
          __Runtime.assert( true ,value3 === 100,"value3 === 100",29,'destructuring_test.js');
          
          __LINE__ = 30;
          __Runtime.assert( true ,value5_ === 100,"value5_ === 100",30,'destructuring_test.js');
          
          __LINE__ = 31;
          __Runtime.assert( true ,value6_ === 200,"value6_ === 200",31,'destructuring_test.js');
          
          __LINE__ = 32;
          __Runtime.assert( true ,value7_ === 300,"value7_ === 300",32,'destructuring_test.js');
          
          __LINE__ = 33;
          __Runtime.assert( true ,value7 === 100,"value7 === 100",33,'destructuring_test.js');
          
          __LINE__ = 34;
          __Runtime.assert( true ,strvalue === 100,"strvalue === 100",34,'destructuring_test.js');
        } catch(__mocha_error){
          __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
        }
      }();
      
      __LINE__ = 38;
      !function () {
        try {
          __LINE__ = 39;
          var value1 = array[0] && array[0].value1?array[0].value1 : undefined,
              arr_value1 = array[1],
              value2 = array[2] && array[2].value2?array[2].value2 : undefined,
              value3 = array[3] && array[3]["value3"]?array[3].value3 : undefined,
              arr_value2 = array[4] && array[4].value4 && array[4].value4.value5 && array[4].value4.value5[0]?array[4].value4.value5[0] : undefined,
              arr_value3 = array[4] && array[4].value4 && array[4].value4.value5 && array[4].value4.value5[1]?array[4].value4.value5[1] : undefined;
          
          __LINE__ = 40;
          __Runtime.assert( true ,value1 === 100,"value1 === 100",40,'destructuring_test.js');
          
          __LINE__ = 41;
          __Runtime.assert( true ,arr_value1 === 200,"arr_value1 === 200",41,'destructuring_test.js');
          
          __LINE__ = 42;
          __Runtime.assert( true ,value2 === 100,"value2 === 100",42,'destructuring_test.js');
          
          __LINE__ = 43;
          __Runtime.assert( true ,value3 === 100,"value3 === 100",43,'destructuring_test.js');
          
          __LINE__ = 44;
          __Runtime.assert( true ,arr_value2 === 100,"arr_value2 === 100",44,'destructuring_test.js');
          
          __LINE__ = 45;
          __Runtime.assert( true ,arr_value3 === 200,"arr_value3 === 200",45,'destructuring_test.js');
          
          __LINE__ = 46;
          value1 = array[0] && array[0].value1?array[0].value1 : undefined;
          
          __LINE__ = 47;
          __Runtime.assert( true ,value1 === 100,"value1 === 100",47,'destructuring_test.js');
          
          __LINE__ = 48;
          __Runtime.assert( true ,arr_value1 === 200,"arr_value1 === 200",48,'destructuring_test.js');
          
          __LINE__ = 49;
          __Runtime.assert( true ,value2 === 100,"value2 === 100",49,'destructuring_test.js');
          
          __LINE__ = 50;
          __Runtime.assert( true ,value3 === 100,"value3 === 100",50,'destructuring_test.js');
          
          __LINE__ = 51;
          __Runtime.assert( true ,arr_value2 === 100,"arr_value2 === 100",51,'destructuring_test.js');
          
          __LINE__ = 52;
          __Runtime.assert( true ,arr_value3 === 200,"arr_value3 === 200",52,'destructuring_test.js');
        } catch(__mocha_error){
          __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
        }
      }();
      
      __LINE__ = 55;
      !function () {
        try {
          __LINE__ = 56;
          var value1 = array[0] && array[0].value1?array[0].value1 : undefined,
              arr_value1 = array[1],
              value2 = array[2] && array[2].value2?array[2].value2 : undefined,
              value3 = array[3] && array[3]["value3"]?array[3].value3 : undefined,
              arr_value2 = array[4] && array[4].value4 && array[4].value4.value5?__Runtime.toArray(array[4].value4.value5,0) : undefined;
          
          __LINE__ = 57;
          __Runtime.assert( true ,value1 === 100,"value1 === 100",57,'destructuring_test.js');
          
          __LINE__ = 58;
          __Runtime.assert( true ,arr_value1 === 200,"arr_value1 === 200",58,'destructuring_test.js');
          
          __LINE__ = 59;
          __Runtime.assert( true ,value2 === 100,"value2 === 100",59,'destructuring_test.js');
          
          __LINE__ = 60;
          __Runtime.assert( true ,value3 === 100,"value3 === 100",60,'destructuring_test.js');
          
          __LINE__ = 61;
          __Runtime.assert( true ,arr_value2[0] === 100,"arr_value2[0] === 100",61,'destructuring_test.js');
          
          __LINE__ = 62;
          __Runtime.assert( true ,arr_value2[1] === 200,"arr_value2[1] === 200",62,'destructuring_test.js');
          
          __LINE__ = 63;
          var arr_value4;
          
          __LINE__ = 64;
          value1 = array[0] && array[0].value1?array[0].value1 : undefined;
          
          __LINE__ = 65;
          __Runtime.assert( true ,value1 === 100,"value1 === 100",65,'destructuring_test.js');
          
          __LINE__ = 66;
          __Runtime.assert( true ,arr_value1 === 200,"arr_value1 === 200",66,'destructuring_test.js');
          
          __LINE__ = 67;
          __Runtime.assert( true ,value2 === 100,"value2 === 100",67,'destructuring_test.js');
          
          __LINE__ = 68;
          __Runtime.assert( true ,value3 === 100,"value3 === 100",68,'destructuring_test.js');
          
          __LINE__ = 69;
          __Runtime.assert( true ,arr_value4[0] === 100,"arr_value4[0] === 100",69,'destructuring_test.js');
          
          __LINE__ = 70;
          __Runtime.assert( true ,arr_value4[1] === 200,"arr_value4[1] === 200",70,'destructuring_test.js');
        } catch(__mocha_error){
          __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
        }
      }();
      
      __LINE__ = 73;
      !function (_mochaLocalTmp0) {
        try {
          __LINE__ = 73;
          var value1 = _mochaLocalTmp0.value1,
              value3 = _mochaLocalTmp0.value2 && _mochaLocalTmp0.value2.value3?_mochaLocalTmp0.value2.value3 : undefined,
              value5_ = _mochaLocalTmp0.value4 && _mochaLocalTmp0.value4[0]?_mochaLocalTmp0.value4[0] : undefined,
              value6_ = _mochaLocalTmp0.value4 && _mochaLocalTmp0.value4[1]?_mochaLocalTmp0.value4[1] : undefined,
              value7_ = _mochaLocalTmp0.value4 && _mochaLocalTmp0.value4[2]?_mochaLocalTmp0.value4[2] : undefined,
              value7 = _mochaLocalTmp0.value5 && _mochaLocalTmp0.value5.value6 && _mochaLocalTmp0.value5.value6[0] && _mochaLocalTmp0.value5.value6[0].value7?_mochaLocalTmp0.value5.value6[0].value7 : undefined,
              strvalue = _mochaLocalTmp0["@value"] && _mochaLocalTmp0["@value"].strvalue?_mochaLocalTmp0["@value"].strvalue : undefined;
          
          __LINE__ = 74;
          __Runtime.assert( true ,value1 === 100,"value1 === 100",74,'destructuring_test.js');
          
          __LINE__ = 75;
          __Runtime.assert( true ,value3 === 100,"value3 === 100",75,'destructuring_test.js');
          
          __LINE__ = 76;
          __Runtime.assert( true ,value5_ === 100,"value5_ === 100",76,'destructuring_test.js');
          
          __LINE__ = 77;
          __Runtime.assert( true ,value6_ === 200,"value6_ === 200",77,'destructuring_test.js');
          
          __LINE__ = 78;
          __Runtime.assert( true ,value7_ === 300,"value7_ === 300",78,'destructuring_test.js');
          
          __LINE__ = 79;
          __Runtime.assert( true ,value7 === 100,"value7 === 100",79,'destructuring_test.js');
          
          __LINE__ = 80;
          __Runtime.assert( true ,strvalue === 100,"strvalue === 100",80,'destructuring_test.js');
        } catch(__mocha_error){
          __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
        }
      }(object);
      
      __LINE__ = 84;
      !function (_mochaLocalTmp1) {
        try {
          __LINE__ = 84;
          var value1 = _mochaLocalTmp1[0] && _mochaLocalTmp1[0].value1?_mochaLocalTmp1[0].value1 : undefined,
              arr_value1 = _mochaLocalTmp1[1],
              value2 = _mochaLocalTmp1[2] && _mochaLocalTmp1[2].value2?_mochaLocalTmp1[2].value2 : undefined,
              value3 = _mochaLocalTmp1[3] && _mochaLocalTmp1[3]["value3"]?_mochaLocalTmp1[3].value3 : undefined,
              arr_value2 = _mochaLocalTmp1[4] && _mochaLocalTmp1[4].value4 && _mochaLocalTmp1[4].value4.value5 && _mochaLocalTmp1[4].value4.value5[0]?_mochaLocalTmp1[4].value4.value5[0] : undefined,
              arr_value3 = _mochaLocalTmp1[4] && _mochaLocalTmp1[4].value4 && _mochaLocalTmp1[4].value4.value5 && _mochaLocalTmp1[4].value4.value5[1]?_mochaLocalTmp1[4].value4.value5[1] : undefined;
          
          __LINE__ = 85;
          __Runtime.assert( true ,value1 === 100,"value1 === 100",85,'destructuring_test.js');
          
          __LINE__ = 86;
          __Runtime.assert( true ,arr_value1 === 200,"arr_value1 === 200",86,'destructuring_test.js');
          
          __LINE__ = 87;
          __Runtime.assert( true ,value2 === 100,"value2 === 100",87,'destructuring_test.js');
          
          __LINE__ = 88;
          __Runtime.assert( true ,value3 === 100,"value3 === 100",88,'destructuring_test.js');
          
          __LINE__ = 89;
          __Runtime.assert( true ,arr_value2 === 100,"arr_value2 === 100",89,'destructuring_test.js');
          
          __LINE__ = 90;
          __Runtime.assert( true ,arr_value3 === 200,"arr_value3 === 200",90,'destructuring_test.js');
        } catch(__mocha_error){
          __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
        }
      }(array);
      
      __LINE__ = 94;
      !function (_mochaLocalTmp2) {
        try {
          __LINE__ = 94;
          var value1 = _mochaLocalTmp2[0] && _mochaLocalTmp2[0].value1?_mochaLocalTmp2[0].value1 : undefined,
              arr_value1 = _mochaLocalTmp2[1],
              value2 = _mochaLocalTmp2[2] && _mochaLocalTmp2[2].value2?_mochaLocalTmp2[2].value2 : undefined,
              value3 = _mochaLocalTmp2[3] && _mochaLocalTmp2[3]["value3"]?_mochaLocalTmp2[3].value3 : undefined,
              arr_value2 = _mochaLocalTmp2[4] && _mochaLocalTmp2[4].value4 && _mochaLocalTmp2[4].value4.value5?__Runtime.toArray(_mochaLocalTmp2[4].value4.value5,0) : undefined;
          
          __LINE__ = 95;
          __Runtime.assert( true ,value1 === 100,"value1 === 100",95,'destructuring_test.js');
          
          __LINE__ = 96;
          __Runtime.assert( true ,arr_value1 === 200,"arr_value1 === 200",96,'destructuring_test.js');
          
          __LINE__ = 97;
          __Runtime.assert( true ,value2 === 100,"value2 === 100",97,'destructuring_test.js');
          
          __LINE__ = 98;
          __Runtime.assert( true ,value3 === 100,"value3 === 100",98,'destructuring_test.js');
          
          __LINE__ = 99;
          __Runtime.assert( true ,arr_value2[0] === 100,"arr_value2[0] === 100",99,'destructuring_test.js');
          
          __LINE__ = 100;
          __Runtime.assert( true ,arr_value2[1] === 200,"arr_value2[1] === 200",100,'destructuring_test.js');
        } catch(__mocha_error){
          __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
        }
      }(array);
      
      __LINE__ = 104;
      var fn = function () {
            try {
              __LINE__ = 104;
              return [0,1,2];
            } catch(__mocha_error){
              __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
            }
          },
          _mochaLocalTmp3 = fn(),
          ret1 = _mochaLocalTmp3[0],
          re2 = _mochaLocalTmp3[1];
    } catch(__mocha_error){
      __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
    }
  }();
}();
