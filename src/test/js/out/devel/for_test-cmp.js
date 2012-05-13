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
      var __FILE__ = "-836421475-for_test.js",
          __LINE__ = 0;
      __LINE__ = 1;
      var target = ['a','b','c','d','e','f','g','h','i','j'],
          arr = [];
      
      __LINE__ = 3;
      for (var i = 0;i<10;i ++ ){
        
        __LINE__ = 4;
        arr.push(target[i]);
      }
      
      __LINE__ = 6;
      __Runtime.assert( true ,arr[0] === 'a',"arr[0] === 'a'",6,'for_test.js');
      
      __LINE__ = 7;
      __Runtime.assert( true ,arr[1] === 'b',"arr[1] === 'b'",7,'for_test.js');
      
      __LINE__ = 8;
      __Runtime.assert( true ,arr[2] === 'c',"arr[2] === 'c'",8,'for_test.js');
      
      __LINE__ = 9;
      __Runtime.assert( true ,arr[3] === 'd',"arr[3] === 'd'",9,'for_test.js');
      
      __LINE__ = 10;
      __Runtime.assert( true ,arr[4] === 'e',"arr[4] === 'e'",10,'for_test.js');
      
      __LINE__ = 11;
      __Runtime.assert( true ,arr[5] === 'f',"arr[5] === 'f'",11,'for_test.js');
      
      __LINE__ = 12;
      __Runtime.assert( true ,arr[6] === 'g',"arr[6] === 'g'",12,'for_test.js');
      
      __LINE__ = 13;
      __Runtime.assert( true ,arr[7] === 'h',"arr[7] === 'h'",13,'for_test.js');
      
      __LINE__ = 14;
      __Runtime.assert( true ,arr[8] === 'i',"arr[8] === 'i'",14,'for_test.js');
      
      __LINE__ = 15;
      __Runtime.assert( true ,arr[9] === 'j',"arr[9] === 'j'",15,'for_test.js');
      
      __LINE__ = 17;
      arr = [];
      
      __LINE__ = 18;
      for (i = 0;i<10;i ++ ){
        __LINE__ = 19;
        arr.push(target[i]);
      }
      
      __LINE__ = 21;
      __Runtime.assert( true ,arr[0] === 'a',"arr[0] === 'a'",21,'for_test.js');
      
      __LINE__ = 22;
      __Runtime.assert( true ,arr[1] === 'b',"arr[1] === 'b'",22,'for_test.js');
      
      __LINE__ = 23;
      __Runtime.assert( true ,arr[2] === 'c',"arr[2] === 'c'",23,'for_test.js');
      
      __LINE__ = 24;
      __Runtime.assert( true ,arr[3] === 'd',"arr[3] === 'd'",24,'for_test.js');
      
      __LINE__ = 25;
      __Runtime.assert( true ,arr[4] === 'e',"arr[4] === 'e'",25,'for_test.js');
      
      __LINE__ = 26;
      __Runtime.assert( true ,arr[5] === 'f',"arr[5] === 'f'",26,'for_test.js');
      
      __LINE__ = 27;
      __Runtime.assert( true ,arr[6] === 'g',"arr[6] === 'g'",27,'for_test.js');
      
      __LINE__ = 28;
      __Runtime.assert( true ,arr[7] === 'h',"arr[7] === 'h'",28,'for_test.js');
      
      __LINE__ = 29;
      __Runtime.assert( true ,arr[8] === 'i',"arr[8] === 'i'",29,'for_test.js');
      
      __LINE__ = 30;
      __Runtime.assert( true ,arr[9] === 'j',"arr[9] === 'j'",30,'for_test.js');
      
      __LINE__ = 32;
      i = 0;
      
      __LINE__ = 33;
      for (;;){
        
        __LINE__ = 34;
        arr.push(target[i]);
        
        __LINE__ = 35;
        i ++ ;
        
        __LINE__ = 36;
        if (i === 10){
          __LINE__ = 36;
          break;
        }
        
      }
      
      __LINE__ = 38;
      __Runtime.assert( true ,arr[0] === 'a',"arr[0] === 'a'",38,'for_test.js');
      
      __LINE__ = 39;
      __Runtime.assert( true ,arr[1] === 'b',"arr[1] === 'b'",39,'for_test.js');
      
      __LINE__ = 40;
      __Runtime.assert( true ,arr[2] === 'c',"arr[2] === 'c'",40,'for_test.js');
      
      __LINE__ = 41;
      __Runtime.assert( true ,arr[3] === 'd',"arr[3] === 'd'",41,'for_test.js');
      
      __LINE__ = 42;
      __Runtime.assert( true ,arr[4] === 'e',"arr[4] === 'e'",42,'for_test.js');
      
      __LINE__ = 43;
      __Runtime.assert( true ,arr[5] === 'f',"arr[5] === 'f'",43,'for_test.js');
      
      __LINE__ = 44;
      __Runtime.assert( true ,arr[6] === 'g',"arr[6] === 'g'",44,'for_test.js');
      
      __LINE__ = 45;
      __Runtime.assert( true ,arr[7] === 'h',"arr[7] === 'h'",45,'for_test.js');
      
      __LINE__ = 46;
      __Runtime.assert( true ,arr[8] === 'i',"arr[8] === 'i'",46,'for_test.js');
      
      __LINE__ = 47;
      __Runtime.assert( true ,arr[9] === 'j',"arr[9] === 'j'",47,'for_test.js');
      
      __LINE__ = 49;
      i = 9;
      
      __LINE__ = 50;
      for (i;i;){
        
        __LINE__ = 51;
        arr.push(target[i]);
        
        __LINE__ = 52;
        i -- ;
      }
      
      __LINE__ = 54;
      __Runtime.assert( true ,arr[0] === 'a',"arr[0] === 'a'",54,'for_test.js');
      
      __LINE__ = 55;
      __Runtime.assert( true ,arr[1] === 'b',"arr[1] === 'b'",55,'for_test.js');
      
      __LINE__ = 56;
      __Runtime.assert( true ,arr[2] === 'c',"arr[2] === 'c'",56,'for_test.js');
      
      __LINE__ = 57;
      __Runtime.assert( true ,arr[3] === 'd',"arr[3] === 'd'",57,'for_test.js');
      
      __LINE__ = 58;
      __Runtime.assert( true ,arr[4] === 'e',"arr[4] === 'e'",58,'for_test.js');
      
      __LINE__ = 59;
      __Runtime.assert( true ,arr[5] === 'f',"arr[5] === 'f'",59,'for_test.js');
      
      __LINE__ = 60;
      __Runtime.assert( true ,arr[6] === 'g',"arr[6] === 'g'",60,'for_test.js');
      
      __LINE__ = 61;
      __Runtime.assert( true ,arr[7] === 'h',"arr[7] === 'h'",61,'for_test.js');
      
      __LINE__ = 62;
      __Runtime.assert( true ,arr[8] === 'i',"arr[8] === 'i'",62,'for_test.js');
      
      __LINE__ = 63;
      __Runtime.assert( true ,arr[9] === 'j',"arr[9] === 'j'",63,'for_test.js');
    } catch(e){
      __Runtime.exceptionHandler(__LINE__, __FILE__, e);
    }
  }();
}();
