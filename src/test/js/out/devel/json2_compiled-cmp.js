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
      var g =  null ,
          json_parse = function () {
            function h(a) {
              try {
                __LINE__ = 1;
                throw  {
                  name : "SyntaxError",
                  message : a,
                  a : i,
                  text : k
                };
              } catch(__mocha_error){
                __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
              }
            }
            function b(b) {
              try {
                __LINE__ = 1;
                b && b !== a && h("Expected '"+b+"' instead of '"+a+"'");
                
                __LINE__ = 1;
                a = k.charAt(i);
                
                __LINE__ = 1;
                i += 1;
                __LINE__ = 1;
                return a;
              } catch(__mocha_error){
                __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
              }
            }
            function n() {
              try {
                __LINE__ = 1;
                var c;
                
                __LINE__ = 1;
                c = "";
                
                __LINE__ = 1;
                a === "-" && (c = "-", b("-"));
                
                __LINE__ = 1;
                for (;a >= "0" && a <= "9";){
                  __LINE__ = 1;
                  c += a, b(g);
                }
                
                __LINE__ = 1;
                if (a === "."){
                  __LINE__ = 1;
                  for (c += ".";b(g) && a >= "0" && a <= "9";){
                    __LINE__ = 1;
                    c += a;
                  }
                  
                }
                
                __LINE__ = 1;
                if (a === "e" || a === "E"){
                  
                  __LINE__ = 1;
                  c += a;
                  
                  __LINE__ = 1;
                  b(g);
                  
                  __LINE__ = 1;
                  a === "-" || a === "+" && (c += a, b(g));
                  
                  __LINE__ = 1;
                  for (;a >= "0" && a <= "9";){
                    __LINE__ = 1;
                    c += a, b(g);
                  }
                  
                }
                
                __LINE__ = 1;
                c = +c;
                
                __LINE__ = 1;
                if (isFinite(c)){
                  __LINE__ = 1;
                  return c;
                }
                
                __LINE__ = 1;
                h("Bad number");
              } catch(__mocha_error){
                __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
              }
            }
            function l() {
              try {
                __LINE__ = 1;
                var c,
                    f,
                    d = "",
                    e;
                
                __LINE__ = 1;
                if (a === '"'){
                  __LINE__ = 1;
                  for (;b(g);){
                    __LINE__ = 1;
                    if (a === '"'){
                      __LINE__ = 1;
                      return b(g), d;
                    } else if (a === "\\"){
                      if (b(g), a === "u"){
                        
                        __LINE__ = 1;
                        for (f = e = 0;f<4;f += 1){
                          
                          __LINE__ = 1;
                          c = parseInt(b(g),16);
                          if (!isFinite(c)){
                            __LINE__ = 1;
                            break;
                          }
                          
                          __LINE__ = 1;
                          e = e*16+c;
                        }
                        
                        __LINE__ = 1;
                        d += String.fromCharCode(e);
                      } else if (typeof m[a] === "string"){
                        __LINE__ = 1;
                        d += m[a];
                      } else {
                        __LINE__ = 1;
                        break;
                      }
                      
                    } else {
                      __LINE__ = 1;
                      d += a;
                    }
                    
                  }
                  
                }
                
                __LINE__ = 1;
                h("Bad string");
              } catch(__mocha_error){
                __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
              }
            }
            function e() {
              try {
                __LINE__ = 1;
                for (;a && a <= " ";){
                  __LINE__ = 1;
                  b(g);
                }
                
              } catch(__mocha_error){
                __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
              }
            }
            function o() {
              try {
                __LINE__ = 1;
                switch (a) {
                  case "t" :
                    __LINE__ = 1;
                    return b("t"), b("r"), b("u"), b("e"), !0;
                  case "f" :
                    __LINE__ = 1;
                    return b("f"), b("a"), b("l"), b("s"), b("e"), !1;
                  case "n" :
                    __LINE__ = 1;
                    return b("n"), b("u"), b("l"), b("l"), g;
                    
                }
                
                __LINE__ = 1;
                h("Unexpected '"+a+"'");
              } catch(__mocha_error){
                __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
              }
            }
            try {
              
              __LINE__ = 1;
              var i,
                  a,
                  m =  {
                    '"' : '"',
                    "\\" : "\\",
                    "/" : "/",
                    b : "\u0008",
                    f : "\u000c",
                    n : "\n",
                    r : "\r",
                    t : "\t"
                  },
                  k,
                  ja;
              
              __LINE__ = 1;
              ja = function () {
                try {
                  __LINE__ = 1;
                  e();
                  
                  __LINE__ = 1;
                  switch (a) {
                    case "{" :
                      
                      __LINE__ = 1;
                      var cv;
                      __LINE__ = 4329965320;
                      a : 
                      {
                        
                        __LINE__ = 1;
                        var f,
                            d = {};
                        
                        __LINE__ = 1;
                        if (a === "{"){
                          
                          __LINE__ = 1;
                          b("{");
                          
                          __LINE__ = 1;
                          e();
                          
                          __LINE__ = 1;
                          if (a === "}"){
                            
                            __LINE__ = 1;
                            b("}");
                            
                            __LINE__ = 1;
                            cv = d;
                            __LINE__ = 1;
                            break a;
                          }
                          
                          __LINE__ = 1;
                          for (;a;){
                            
                            __LINE__ = 1;
                            f = l();
                            
                            __LINE__ = 1;
                            e();
                            
                            __LINE__ = 1;
                            b(":");
                            
                            __LINE__ = 1;
                            Object.hasOwnProperty.call(d,f) && h('Duplicate key "'+f+'"');
                            
                            __LINE__ = 1;
                            d[f] = ja();
                            
                            __LINE__ = 1;
                            e();
                            
                            __LINE__ = 1;
                            if (a === "}"){
                              
                              __LINE__ = 1;
                              b("}");
                              
                              __LINE__ = 1;
                              cv = d;
                              __LINE__ = 1;
                              break a;
                            }
                            
                            __LINE__ = 1;
                            b(",");
                            
                            __LINE__ = 1;
                            e();
                          }
                          
                        }
                        
                        __LINE__ = 1;
                        h("Bad object");
                      }
                      __LINE__ = 1;
                      return cv;
                    case "[" :
                      __LINE__ = 4329995648;
                      a : 
                      {
                        
                        __LINE__ = 1;
                        cv = [];
                        
                        __LINE__ = 1;
                        if (a === "["){
                          
                          __LINE__ = 1;
                          b("[");
                          
                          __LINE__ = 1;
                          e();
                          
                          __LINE__ = 1;
                          if (a === "]"){
                            
                            __LINE__ = 1;
                            b("]");
                            
                            __LINE__ = 1;
                            f = cv;
                            __LINE__ = 1;
                            break a;
                          }
                          
                          __LINE__ = 1;
                          for (;a;){
                            
                            __LINE__ = 1;
                            cv.push(ja());
                            
                            __LINE__ = 1;
                            e();
                            
                            __LINE__ = 1;
                            if (a === "]"){
                              
                              __LINE__ = 1;
                              b("]");
                              
                              __LINE__ = 1;
                              f = cv;
                              __LINE__ = 1;
                              break a;
                            }
                            
                            __LINE__ = 1;
                            b(",");
                            
                            __LINE__ = 1;
                            e();
                          }
                          
                        }
                        
                        __LINE__ = 1;
                        h("Bad array");
                      }
                      __LINE__ = 1;
                      return f;
                    case '"' :
                      __LINE__ = 1;
                      return l();
                    case "-" :
                      __LINE__ = 1;
                      return n();
                    default :
                      __LINE__ = 1;
                      return a >= "0" && a <= "9"?n() : o();
                      
                  }
                  
                } catch(__mocha_error){
                  __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
                }
              };
              __LINE__ = 1;
              return function (b,f) {
                try {
                  __LINE__ = 1;
                  var d;
                  
                  __LINE__ = 1;
                  k = b;
                  
                  __LINE__ = 1;
                  i = 0;
                  
                  __LINE__ = 1;
                  a = " ";
                  
                  __LINE__ = 1;
                  d = ja();
                  
                  __LINE__ = 1;
                  e();
                  
                  __LINE__ = 1;
                  a && h("Syntax error");
                  __LINE__ = 1;
                  return typeof f === "function"?function p(a,b) {
                    try {
                      __LINE__ = 1;
                      var c,
                          e,
                          d = a[b];
                      
                      __LINE__ = 1;
                      if (d && typeof d === "object"){
                        __LINE__ = 1;
                        for (c in d){
                          __LINE__ = 1;
                          ({}).hasOwnProperty.call(d,c) && (e = p(d,c), e !== void 0?d[c] = e : delete d[c]);
                        }
                        
                      }
                      __LINE__ = 1;
                      return f.call(a,b,d);
                    } catch(__mocha_error){
                      __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
                    }
                  }( {
                    "" : d
                  },"") : d;
                } catch(__mocha_error){
                  __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
                }
              };
            } catch(__mocha_error){
              __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
            }
          }();
      
      __LINE__ = 3;
      !function () {
        try {
          __LINE__ = 4;
          var json_str = '{"test" : 1,"test2":"test2","test3":null,"test4":{"test5":5}}',
              json = json_parse(json_str);
          
          __LINE__ = 6;
          __Runtime.assert( true ,json.test === 1,"json[\"test\"] === 1",6,'json2_compiled.js');
          
          __LINE__ = 7;
          __Runtime.assert( true ,json.test2 === "test2","json[\"test2\"] === \"test2\"",7,'json2_compiled.js');
          
          __LINE__ = 8;
          __Runtime.assert( true ,json.test3 ===  null ,"json[\"test3\"] ===  null ",8,'json2_compiled.js');
          
          __LINE__ = 9;
          __Runtime.assert( true ,json.test4.test5 === 5,"json[\"test4\"][\"test5\"] === 5",9,'json2_compiled.js');
        } catch(__mocha_error){
          __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
        }
      }();
    } catch(__mocha_error){
      __Runtime.exceptionHandler(__LINE__, __FILE__, __mocha_error);
    }
  }();
}();
