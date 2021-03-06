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
      __LINE__ = 1;
      !function () {
        function testWithContext() {
          try {
            __LINE__ = 32;
            return console.log(1);
          } catch(__mocha_error){
            __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
          }
        }
        function testHasFormalWithContext() {
          try {
            __LINE__ = 31;
            return console.log(1);
          } catch(__mocha_error){
            __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
          }
        }
        function testHasFormalHasBlockWithContext() {
          try {
            __LINE__ = 29;
            console.log(1);
          } catch(__mocha_error){
            __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
          }
        }
        function test() {
          try {
            __LINE__ = 26;
            return console.log(1);
          } catch(__mocha_error){
            __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
          }
        }
        function testHasFormal() {
          try {
            __LINE__ = 25;
            return console.log(1);
          } catch(__mocha_error){
            __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
          }
        }
        function testHasFormalHasBlock() {
          try {
            __LINE__ = 23;
            console.log(1);
          } catch(__mocha_error){
            __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
          }
        }
        function testConstFunctionWithContext() {
          try {
            __LINE__ = 17;
            return console.log(1);
          } catch(__mocha_error){
            __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
          }
        }
        function testConstFunctionHasFormalWithContext() {
          try {
            __LINE__ = 16;
            return console.log(1);
          } catch(__mocha_error){
            __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
          }
        }
        function testConstFunctionNonFormal() {
          try {
            __LINE__ = 14;
            return console.log(1);
          } catch(__mocha_error){
            __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
          }
        }
        function testConstFunctionHasForaml() {
          try {
            __LINE__ = 13;
            return console.log(1);
          } catch(__mocha_error){
            __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
          }
        }
        function testConstFunctionHasBlockHasFormal() {
          try {
            __LINE__ = 8;
            console.log(1);
          } catch(__mocha_error){
            __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
          }
        }
        function testDeclNonForamlWithContext() {
          try {
            __LINE__ = 5;
            return console.log(1);
          } catch(__mocha_error){
            __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
          }
        }
        function testDeclHasFormalWithContext() {
          try {
            __LINE__ = 4;
            return console.log(1);
          } catch(__mocha_error){
            __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
          }
        }
        function testDeclNonFormal() {
          try {
            __LINE__ = 3;
            return console.log(1);
          } catch(__mocha_error){
            __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
          }
        }
        function testDeclHasFormal() {
          try {
            __LINE__ = 2;
            return console.log(1);
          } catch(__mocha_error){
            __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
          }
        }
        try {
          
          __LINE__ = 32;
          testWithContext = testWithContext.bind(this);
          
          __LINE__ = 31;
          testHasFormalWithContext = testHasFormalWithContext.bind(this);
          
          __LINE__ = 28;
          testHasFormalHasBlockWithContext = testHasFormalHasBlockWithContext.bind(this);
          
          __LINE__ = 17;
          testConstFunctionWithContext = testConstFunctionWithContext.bind(this);
          
          __LINE__ = 16;
          testConstFunctionHasFormalWithContext = testConstFunctionHasFormalWithContext.bind(this);
          
          __LINE__ = 5;
          testDeclNonForamlWithContext = testDeclNonForamlWithContext.bind(this);
          
          __LINE__ = 4;
          testDeclHasFormalWithContext = testDeclHasFormalWithContext.bind(this);
          
          __LINE__ = 11;
          var contextTest = function () {
                try {
                  __LINE__ = 11;
                  return console.log(this);
                } catch(__mocha_error){
                  __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
                }
              }.bind(this);
          
          __LINE__ = 18;
          var x = function (a,b,c) {
                try {
                  __LINE__ = 19;
                  a+b;
                } catch(__mocha_error){
                  __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
                }
              },
              x = function (a,b,c) {
                try {
                  __LINE__ = 21;
                  return a+b;
                } catch(__mocha_error){
                  __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
                }
              };
        } catch(__mocha_error){
          __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
        }
      }();
      
      __LINE__ = 35;
      !function () {
        function testHasFormalDstaWithContext(_mochaLocalTmp24,_mochaLocalTmp25,_mochaLocalTmp26,args8) {
          try {
            __LINE__ = 68;
            args8 = __Runtime.toArray(arguments,3);
            
            __LINE__ = 68;
            var args = _mochaLocalTmp24.args,
                args2 = _mochaLocalTmp25.tmp && _mochaLocalTmp25.tmp["args2"]?_mochaLocalTmp25.tmp.args2 : undefined,
                args3 = _mochaLocalTmp26[0],
                args4 = _mochaLocalTmp26[1],
                args5 = _mochaLocalTmp26[2] && _mochaLocalTmp26[2].args5?_mochaLocalTmp26[2].args5 : undefined,
                args7 = _mochaLocalTmp26[2] && _mochaLocalTmp26[2].args6 && _mochaLocalTmp26[2].args6.args7?_mochaLocalTmp26[2].args6.args7 : undefined;
            __LINE__ = 68;
            return console.log(1);
          } catch(__mocha_error){
            __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
          }
        }
        function testHasFormalWithContext(args,args2,args3) {
          try {
            __LINE__ = 67;
            return console.log(1);
          } catch(__mocha_error){
            __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
          }
        }
        function testHasFormalDstaHasBlockWithContext(_mochaLocalTmp21,_mochaLocalTmp22,_mochaLocalTmp23,args8) {
          try {
            __LINE__ = 64;
            args8 = __Runtime.toArray(arguments,3);
            
            __LINE__ = 64;
            var args = _mochaLocalTmp21.args,
                args2 = _mochaLocalTmp22.tmp && _mochaLocalTmp22.tmp["args2"]?_mochaLocalTmp22.tmp.args2 : undefined,
                args3 = _mochaLocalTmp23[0],
                args4 = _mochaLocalTmp23[1],
                args5 = _mochaLocalTmp23[2] && _mochaLocalTmp23[2].args5?_mochaLocalTmp23[2].args5 : undefined,
                args7 = _mochaLocalTmp23[2] && _mochaLocalTmp23[2].args6 && _mochaLocalTmp23[2].args6.args7?_mochaLocalTmp23[2].args6.args7 : undefined;
            
            __LINE__ = 65;
            console.log(1);
          } catch(__mocha_error){
            __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
          }
        }
        function testHasFormalHasBlockWithContext(args,args2,args3) {
          try {
            __LINE__ = 62;
            console.log(1);
          } catch(__mocha_error){
            __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
          }
        }
        function testHasFormalDsta(_mochaLocalTmp18,_mochaLocalTmp19,_mochaLocalTmp20,args8) {
          try {
            __LINE__ = 60;
            args8 = __Runtime.toArray(arguments,3);
            
            __LINE__ = 60;
            var args = _mochaLocalTmp18.args,
                args2 = _mochaLocalTmp19.tmp && _mochaLocalTmp19.tmp["args2"]?_mochaLocalTmp19.tmp.args2 : undefined,
                args3 = _mochaLocalTmp20[0],
                args4 = _mochaLocalTmp20[1],
                args5 = _mochaLocalTmp20[2] && _mochaLocalTmp20[2].args5?_mochaLocalTmp20[2].args5 : undefined,
                args7 = _mochaLocalTmp20[2] && _mochaLocalTmp20[2].args6 && _mochaLocalTmp20[2].args6.args7?_mochaLocalTmp20[2].args6.args7 : undefined;
            __LINE__ = 60;
            return console.log(1);
          } catch(__mocha_error){
            __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
          }
        }
        function testHasFormal(args,args2,args3) {
          try {
            __LINE__ = 59;
            return console.log(1);
          } catch(__mocha_error){
            __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
          }
        }
        function testHasFormalDstaHasBlock(_mochaLocalTmp15,_mochaLocalTmp16,_mochaLocalTmp17,args8) {
          try {
            __LINE__ = 56;
            args8 = __Runtime.toArray(arguments,3);
            
            __LINE__ = 56;
            var args = _mochaLocalTmp15.args,
                args2 = _mochaLocalTmp16.tmp && _mochaLocalTmp16.tmp["args2"]?_mochaLocalTmp16.tmp.args2 : undefined,
                args3 = _mochaLocalTmp17[0],
                args4 = _mochaLocalTmp17[1],
                args5 = _mochaLocalTmp17[2] && _mochaLocalTmp17[2].args5?_mochaLocalTmp17[2].args5 : undefined,
                args7 = _mochaLocalTmp17[2] && _mochaLocalTmp17[2].args6 && _mochaLocalTmp17[2].args6.args7?_mochaLocalTmp17[2].args6.args7 : undefined;
            
            __LINE__ = 57;
            console.log(1);
          } catch(__mocha_error){
            __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
          }
        }
        function testHasFormalHasBlock(args,args2,args3) {
          try {
            __LINE__ = 54;
            console.log(1);
          } catch(__mocha_error){
            __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
          }
        }
        function testConstFunctionHasFormalDstaWithContext(_mochaLocalTmp12,_mochaLocalTmp13,_mochaLocalTmp14,args8) {
          try {
            __LINE__ = 51;
            args8 = __Runtime.toArray(arguments,3);
            
            __LINE__ = 51;
            var args = _mochaLocalTmp12.args,
                args2 = _mochaLocalTmp13.tmp && _mochaLocalTmp13.tmp["args2"]?_mochaLocalTmp13.tmp.args2 : undefined,
                args3 = _mochaLocalTmp14[0],
                args4 = _mochaLocalTmp14[1],
                args5 = _mochaLocalTmp14[2] && _mochaLocalTmp14[2].args5?_mochaLocalTmp14[2].args5 : undefined,
                args7 = _mochaLocalTmp14[2] && _mochaLocalTmp14[2].args6 && _mochaLocalTmp14[2].args6.args7?_mochaLocalTmp14[2].args6.args7 : undefined;
            __LINE__ = 51;
            return console.log(1);
          } catch(__mocha_error){
            __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
          }
        }
        function testConstFunctionHasFormalWithContext(args,args2,args3) {
          try {
            __LINE__ = 50;
            return console.log(1);
          } catch(__mocha_error){
            __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
          }
        }
        function testConstFunctionHasForamlDsta(_mochaLocalTmp9,_mochaLocalTmp10,_mochaLocalTmp11,args8) {
          try {
            __LINE__ = 49;
            args8 = __Runtime.toArray(arguments,3);
            
            __LINE__ = 49;
            var args = _mochaLocalTmp9.args,
                args2 = _mochaLocalTmp10.tmp && _mochaLocalTmp10.tmp["args2"]?_mochaLocalTmp10.tmp.args2 : undefined,
                args3 = _mochaLocalTmp11[0],
                args4 = _mochaLocalTmp11[1],
                args5 = _mochaLocalTmp11[2] && _mochaLocalTmp11[2].args5?_mochaLocalTmp11[2].args5 : undefined,
                args7 = _mochaLocalTmp11[2] && _mochaLocalTmp11[2].args6 && _mochaLocalTmp11[2].args6.args7?_mochaLocalTmp11[2].args6.args7 : undefined;
            __LINE__ = 49;
            return console.log(1);
          } catch(__mocha_error){
            __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
          }
        }
        function testConstFunctionHasForaml(args,args2,args3) {
          try {
            __LINE__ = 48;
            return console.log(1);
          } catch(__mocha_error){
            __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
          }
        }
        function testConstFunctionHasBlockHasFormalDsta(_mochaLocalTmp6,_mochaLocalTmp7,_mochaLocalTmp8,args8) {
          try {
            __LINE__ = 44;
            args8 = __Runtime.toArray(arguments,3);
            
            __LINE__ = 44;
            var args = _mochaLocalTmp6.args,
                args2 = _mochaLocalTmp7.tmp && _mochaLocalTmp7.tmp["args2"]?_mochaLocalTmp7.tmp.args2 : undefined,
                args3 = _mochaLocalTmp8[0],
                args4 = _mochaLocalTmp8[1],
                args5 = _mochaLocalTmp8[2] && _mochaLocalTmp8[2].args5?_mochaLocalTmp8[2].args5 : undefined,
                args7 = _mochaLocalTmp8[2] && _mochaLocalTmp8[2].args6 && _mochaLocalTmp8[2].args6.args7?_mochaLocalTmp8[2].args6.args7 : undefined;
            
            __LINE__ = 45;
            console.log(1);
          } catch(__mocha_error){
            __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
          }
        }
        function testConstFunctionHasBlockHasFormal(args,args2,args3) {
          try {
            __LINE__ = 42;
            console.log(1);
          } catch(__mocha_error){
            __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
          }
        }
        function testDeclHasFormalDstaWithContext(_mochaLocalTmp3,_mochaLocalTmp4,_mochaLocalTmp5,args8) {
          try {
            __LINE__ = 40;
            args8 = __Runtime.toArray(arguments,3);
            
            __LINE__ = 40;
            var args = _mochaLocalTmp3.args,
                args2 = _mochaLocalTmp4.tmp && _mochaLocalTmp4.tmp["args2"]?_mochaLocalTmp4.tmp.args2 : undefined,
                args3 = _mochaLocalTmp5[0],
                args4 = _mochaLocalTmp5[1],
                args5 = _mochaLocalTmp5[2] && _mochaLocalTmp5[2].args5?_mochaLocalTmp5[2].args5 : undefined,
                args7 = _mochaLocalTmp5[2] && _mochaLocalTmp5[2].args6 && _mochaLocalTmp5[2].args6.args7?_mochaLocalTmp5[2].args6.args7 : undefined;
            __LINE__ = 40;
            return console.log(this);
          } catch(__mocha_error){
            __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
          }
        }
        function testDeclHasFormalWithContext(args,args2,args3) {
          try {
            __LINE__ = 39;
            return console.log(1);
          } catch(__mocha_error){
            __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
          }
        }
        function testDeclHasFormalDsta(_mochaLocalTmp0,_mochaLocalTmp1,_mochaLocalTmp2,args8) {
          try {
            __LINE__ = 38;
            args8 = __Runtime.toArray(arguments,3);
            
            __LINE__ = 38;
            var args = _mochaLocalTmp0.args,
                args2 = _mochaLocalTmp1.tmp && _mochaLocalTmp1.tmp["args2"]?_mochaLocalTmp1.tmp.args2 : undefined,
                args3 = _mochaLocalTmp2[0],
                args4 = _mochaLocalTmp2[1],
                args5 = _mochaLocalTmp2[2] && _mochaLocalTmp2[2].args5?_mochaLocalTmp2[2].args5 : undefined,
                args7 = _mochaLocalTmp2[2] && _mochaLocalTmp2[2].args6 && _mochaLocalTmp2[2].args6.args7?_mochaLocalTmp2[2].args6.args7 : undefined;
            __LINE__ = 38;
            return console.log(1);
          } catch(__mocha_error){
            __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
          }
        }
        function testDeclHasFormal(args,args2,args3) {
          try {
            __LINE__ = 37;
            return console.log(1);
          } catch(__mocha_error){
            __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
          }
        }
        try {
          
          __LINE__ = 68;
          testHasFormalDstaWithContext = testHasFormalDstaWithContext.bind(this);
          
          __LINE__ = 67;
          testHasFormalWithContext = testHasFormalWithContext.bind(this);
          
          __LINE__ = 64;
          testHasFormalDstaHasBlockWithContext = testHasFormalDstaHasBlockWithContext.bind(this);
          
          __LINE__ = 61;
          testHasFormalHasBlockWithContext = testHasFormalHasBlockWithContext.bind(this);
          
          __LINE__ = 51;
          testConstFunctionHasFormalDstaWithContext = testConstFunctionHasFormalDstaWithContext.bind(this);
          
          __LINE__ = 50;
          testConstFunctionHasFormalWithContext = testConstFunctionHasFormalWithContext.bind(this);
          
          __LINE__ = 40;
          testDeclHasFormalDstaWithContext = testDeclHasFormalDstaWithContext.bind(this);
          
          __LINE__ = 39;
          testDeclHasFormalWithContext = testDeclHasFormalWithContext.bind(this);
        } catch(__mocha_error){
          __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
        }
      }();
    } catch(__mocha_error){
      __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
    }
  }();
}();
