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
      __LINE__ = 162;
      var JSON;
      
      __LINE__ = 164;
      !JSON && (JSON = {});
      
      __LINE__ = 167;
      (function () {
        "use strict";
        function str(key,holder) {
          try {
            __LINE__ = 233;
            var i,
                k,
                v,
                length,
                mind = gap,
                partial,
                value = holder[key];
            
            __LINE__ = 245;
            value && typeof value === 'object' && typeof value.toJSON === 'function' && (value = value.toJSON(key));
            
            __LINE__ = 252;
            typeof rep === 'function' && (value = rep.call(holder,key,value));
            
            __LINE__ = 257;
            switch (typeof value) {
              case 'string' :
                __LINE__ = 259;
                return quote(value);
              case 'number' :
                __LINE__ = 265;
                return isFinite(value)?String(value) : 'null';
              case 'boolean' :
              case 'null' :
                __LINE__ = 274;
                return String(value);
              case 'object' :
                
                __LINE__ = 284;
                if (!value){
                  __LINE__ = 285;
                  return 'null';
                }
                
                __LINE__ = 290;
                gap += indent;
                
                __LINE__ = 291;
                partial = [];
                
                __LINE__ = 295;
                if (Object.prototype.toString.apply(value) === '[object Array]'){
                  
                  __LINE__ = 300;
                  length = value.length;
                  
                  __LINE__ = 301;
                  for (i = 0;i<length;i += 1){
                    
                    __LINE__ = 302;
                    partial[i] = str(i,value) || 'null';
                  }
                  
                  __LINE__ = 308;
                  v = partial.length === 0?'[]' : gap?'[\n'+gap+partial.join(',\n'+gap)+'\n'+mind+']' : '['+partial.join(',')+']';
                  
                  __LINE__ = 313;
                  gap = mind;
                  __LINE__ = 314;
                  return v;
                }
                
                __LINE__ = 319;
                if (rep && typeof rep === 'object'){
                  
                  __LINE__ = 320;
                  length = rep.length;
                  
                  __LINE__ = 321;
                  for (i = 0;i<length;i += 1){
                    
                    __LINE__ = 322;
                    if (typeof rep[i] === 'string'){
                      
                      __LINE__ = 323;
                      k = rep[i];
                      
                      __LINE__ = 324;
                      v = str(k,value);
                      
                      __LINE__ = 325;
                      if (v){
                        
                        __LINE__ = 326;
                        partial.push(quote(k)+(gap?': ' : ':')+v);
                      }
                      
                    }
                    
                  }
                  
                } else {
                  
                  __LINE__ = 334;
                  for (k in value){
                    if (Object.prototype.hasOwnProperty.call(value,k)){
                      
                      __LINE__ = 336;
                      v = str(k,value);
                      if (v){
                        
                        __LINE__ = 338;
                        partial.push(quote(k)+(gap?': ' : ':')+v);
                      }
                      
                    }
                    
                  }
                  
                }
                
                __LINE__ = 347;
                v = partial.length === 0?'{}' : gap?'{\n'+gap+partial.join(',\n'+gap)+'\n'+mind+'}' : '{'+partial.join(',')+'}';
                
                __LINE__ = 352;
                gap = mind;
                __LINE__ = 353;
                return v;
                
            }
            
          } catch(__mocha_error){
            __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
          }
        }
        function quote(string) {
          try {
            __LINE__ = 219;
            escapable.lastIndex = 0;
            __LINE__ = 220;
            return escapable.test(string)?'"'+string.replace(escapable,
            function (a) {
              try {
                __LINE__ = 221;
                var c = meta[a];
                __LINE__ = 222;
                return typeof c === 'string'?c : '\\u'+('0000'+a.charCodeAt(0).toString(16)).slice(-4);
              } catch(__mocha_error){
                __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
              }
            })+'"' : '"'+string+'"';
          } catch(__mocha_error){
            __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
          }
        }
        function f(n) {
          try {
            __LINE__ = 172;
            return n<10?'0'+n : n;
          } catch(__mocha_error){
            __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
          }
        }
        try {
          
          __LINE__ = 175;
          if (typeof Date.prototype.toJSON !== 'function'){
            
            __LINE__ = 177;
            Date.prototype.toJSON = function (key) {
              try {
                __LINE__ = 179;
                return isFinite(this.valueOf())?this.getUTCFullYear()+'-'+f(this.getUTCMonth()+1)+'-'+f(this.getUTCDate())+'T'+f(this.getUTCHours())+':'+f(this.getUTCMinutes())+':'+f(this.getUTCSeconds())+'Z' :  null ;
              } catch(__mocha_error){
                __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
              }
            };
            
            __LINE__ = 189;
            String.prototype.toJSON = Number.prototype.toJSON = Boolean.prototype.toJSON = function (key) {
              try {
                __LINE__ = 192;
                return this.valueOf();
              } catch(__mocha_error){
                __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
              }
            };
          }
          
          __LINE__ = 196;
          var cx = /[\u0000\u00ad\u0600-\u0604\u070f\u17b4\u17b5\u200c-\u200f\u2028-\u202f\u2060-\u206f\ufeff\ufff0-\uffff]/g,
              escapable = /[\\\"\x00-\x1f\x7f-\x9f\u00ad\u0600-\u0604\u070f\u17b4\u17b5\u200c-\u200f\u2028-\u202f\u2060-\u206f\ufeff\ufff0-\uffff]/g,
              gap,
              indent,
              meta =  {
                '\b' : '\\b',
                '\t' : '\\t',
                '\n' : '\\n',
                '\f' : '\\f',
                '\r' : '\\r',
                '"' : '\\"',
                '\\' : '\\\\'
              },
              rep;
          
          __LINE__ = 360;
          typeof JSON.stringify !== 'function' && (JSON.stringify = function (value,replacer,space) {
            try {
              __LINE__ = 368;
              var i;
              
              __LINE__ = 369;
              gap = '';
              
              __LINE__ = 370;
              indent = '';
              
              __LINE__ = 375;
              if (typeof space === 'number'){
                __LINE__ = 376;
                for (i = 0;i<space;i += 1){
                  __LINE__ = 377;
                  indent += ' ';
                }
                
              } else {
                __LINE__ = 383;
                typeof space === 'string' && (indent = space);
              }
              
              __LINE__ = 389;
              rep = replacer;
              
              __LINE__ = 390;
              if (replacer && typeof replacer !== 'function' && (typeof replacer !== 'object' || typeof replacer.length !== 'number')){
                __LINE__ = 393;
                throw new Error('JSON.stringify');
              }
              __LINE__ = 399;
              return str('', {
                '' : value
              });
            } catch(__mocha_error){
              __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
            }
          });
          
          __LINE__ = 407;
          typeof JSON.parse !== 'function' && (JSON.parse = function (text,reviver) {
            function walk(holder,key) {
              try {
                __LINE__ = 419;
                var k,
                    v,
                    value = holder[key];
                
                __LINE__ = 420;
                if (value && typeof value === 'object'){
                  __LINE__ = 421;
                  for (k in value){
                    __LINE__ = 422;
                    if (({}).hasOwnProperty.call(value,k)){
                      
                      __LINE__ = 423;
                      v = walk(value,k);
                      
                      __LINE__ = 425;
                      v !== undefined?value[k] = v : delete value[k];
                    }
                    
                  }
                  
                }
                __LINE__ = 432;
                return reviver.call(holder,key,value);
              } catch(__mocha_error){
                __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
              }
            }
            try {
              
              __LINE__ = 412;
              var j;
              
              __LINE__ = 440;
              text = String(text);
              
              __LINE__ = 441;
              cx.lastIndex = 0;
              
              __LINE__ = 443;
              cx.test(text) && (text = text.replace(cx,
              function (a) {
                try {
                  __LINE__ = 444;
                  return '\\u'+('0000'+a.charCodeAt(0).toString(16)).slice(-4);
                } catch(__mocha_error){
                  __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
                }
              }));
              
              __LINE__ = 462;
              if (/^[\],:{}\s]*$/.test(text.replace(/\\(?:["\\\/bfnrt]|u[0-9a-fA-F]{4})/g,'@').replace(/"[^"\\\n\r]*"|true|false|null|-?\d+(?:\.\d*)?(?:[eE][+\-]?\d+)?/g,']').replace(/(?:^|:|,)(?:\s*\[)+/g,''))){
                
                __LINE__ = 472;
                j = eval('('+text+')');
                __LINE__ = 477;
                return typeof reviver === 'function'?walk( {
                  '' : j
                },'') : j;
              }
              __LINE__ = 484;
              throw new SyntaxError('JSON.parse');
            } catch(__mocha_error){
              __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
            }
          });
        } catch(__mocha_error){
          __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
        }
      }());
    } catch(__mocha_error){
      __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
    }
  }();
}();
