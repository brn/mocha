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
  
  __Runtime.extend(__Runtime, {
    Generator : function (){},
    createGenerator : function (generatorFn,closeFn,context) {
      var ret = new this.Generator;
      
      this.createUnenumProp(ret,"next",generatorFn.bind(context, false , false ));
      
      this.createUnenumProp(ret,"send",generatorFn.bind(context, true , false ));
      
      this.createUnenumProp(ret,"close",closeFn.bind(context));
      
      this.createUnenumProp(ret,"__nothrowNext__",generatorFn.bind(context, false , true ));
      
      this.createUnenumProp(ret,"toString",
      function () {
        return "[object Generator]";
      });
      
      Object.freeze(ret);
      return ret;
    },
    throwStopIteration : function () {
      try {
        throw StopIteration;
      } catch(e){
        throw new Error(e.toString());
      }
      
    },
    isGenerator : function (obj) {
      return obj instanceof this.Generator;
    },
    getIterator : function (obj) {
      var ret = obj.iterator();
      
      if (this.isGenerator(ret)){
        return ret;
      }
      
      if (ret.next){
        
        var next = ret.next.bind(ret);
        
        this.createUnenumProp(ret,"next",
        function (nothrow) {
          var result = next();
          
          if (result === undefined && !nothrow){
            
            this.throwStopIteration();
          }
          return result;
        });
      } else {
        return {};
      }
      
      if (!("__nothrowNext__" in ret)){
        
        this.createUnenumProp(ret,"__nothrowNext__",ret.next.bind(ret, true ));
      }
      
      if (!("toString" in ret)){
        
        this.createUnenumProp(ret,"toString",
        function () {
          return "[object Iterator]";
        });
      }
      return ret;
    },
    hasIterator : function (obj) {
      return 'iterator' in obj;
    }
  });
  
  !("StopIteration" in __Runtime._global) && (__Runtime._global.StopIteration =  {
    toString : function () {
      return "[object StopIteration]";
    }
  });
  
  __Runtime.extend(__Runtime, {
    modules : (function () {
      function Module(){}
      function ModuleContainer(){}
      
      Object.defineProperty(ModuleContainer.prototype,'_modules', {
        value : {},
        writable :  true 
      });
      
      Object.defineProperty(ModuleContainer.prototype,'add', {
        value : function (name) {
          return this._modules[name] = new Module;
        }
      });
      
      Object.defineProperty(ModuleContainer.prototype,'get', {
        value : function (name) {
          return this._modules[name];
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
      return new ModuleContainer;
    })()
  });
  
  __LINE__ = 2;
  !function () {
    try {
      var __FILE__ = "iterators",
          __LINE__ = 0;
      __LINE__ = 2;
      __Runtime.modules.add('iterators');
      
      __LINE__ = 2;
      var iterators = __Runtime.modules.get('iterators').iterators = function () {
            function allItems(obj) {
              try {
                __LINE__ = 54;
                return  {
                  iterator : function () {
                    try {
                      __LINE__ = 54;
                      return function () {
                        try {
                          __LINE__ = 54;
                          var _mochaIsNewBorn = true;
                          
                          __LINE__ = 54;
                          var _yieldResult = undefined;
                          
                          __LINE__ = 54;
                          var _yieldState = 0;
                          
                          __LINE__ = 56;
                          var length;
                          
                          __LINE__ = 56;
                          var _mochaLocalTmp17;
                          
                          __LINE__ = 56;
                          var x;
                          
                          __LINE__ = 56;
                          var _mochaLocalTmp16 = [];
                          
                          __LINE__ = 54;
                          var _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                                try {
                                  __LINE__ = 54;
                                  if (!_isYieldSend){
                                    
                                    __LINE__ = 54;
                                    _mochaIsNewBorn = false;
                                  } else if (_isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined){
                                    
                                    __LINE__ = 54;
                                    __Runtime.exceptionHandler('attempt to send to newborn generator.');
                                  }
                                  
                                  __LINE__ = 54;
                                  while (1){
                                    __LINE__ = 54;
                                    switch (_yieldState) {
                                      case 0 :
                                        
                                        __LINE__ = 56;
                                        for (var _mochaLocalTmp15 in obj){
                                          
                                          __LINE__ = 56;
                                          _mochaLocalTmp16.push(_mochaLocalTmp15);
                                        }
                                        
                                        __LINE__ = 56;
                                        _mochaLocalTmp17 = 0;
                                        
                                        __LINE__ = 56;
                                        length = _mochaLocalTmp16.length;
                                        
                                        __LINE__ = 56;
                                        if (!(_mochaLocalTmp17<length)){
                                          
                                          __LINE__ = 56;
                                          _yieldState = -1;
                                          __LINE__ = 56;
                                          break;
                                        }
                                      case 1 :
                                        
                                        __LINE__ = 56;
                                        _yieldState = 2;
                                        
                                        __LINE__ = 56;
                                        x = _mochaLocalTmp16[_mochaLocalTmp17];
                                        __LINE__ = 56;
                                        return [x,obj[x]];
                                      case 2 :
                                        
                                        __LINE__ = 56;
                                         ++ _mochaLocalTmp17;
                                        
                                        __LINE__ = 56;
                                        if (_mochaLocalTmp17<length){
                                          
                                          __LINE__ = 2;
                                          _yieldState = 1;
                                          __LINE__ = 56;
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
                                        } else {
                                          __LINE__ = 54;
                                          __Runtime.throwStopIteration();
                                        }
                                        
                                    }
                                    
                                  }
                                  
                                } catch(e){
                                  __Runtime.exceptionHandler(__LINE__, __FILE__, e);
                                }
                              };
                          __LINE__ = 54;
                          return __Runtime.createGenerator(_mochaGenerator,
                          function () {
                            try {
                              __LINE__ = 54;
                              _yieldState = -1;
                            } catch(e){
                              __Runtime.exceptionHandler(__LINE__, __FILE__, e);
                            }
                          },this);
                        } catch(e){
                          __Runtime.exceptionHandler(__LINE__, __FILE__, e);
                        }
                      }();
                    } catch(e){
                      __Runtime.exceptionHandler(__LINE__, __FILE__, e);
                    }
                  }
                };
              } catch(e){
                __Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            }
            function allValues(obj) {
              try {
                __LINE__ = 46;
                return  {
                  iterator : function () {
                    try {
                      __LINE__ = 46;
                      return function () {
                        try {
                          __LINE__ = 46;
                          var _mochaIsNewBorn = true;
                          
                          __LINE__ = 46;
                          var _yieldResult = undefined;
                          
                          __LINE__ = 46;
                          var _yieldState = 0;
                          
                          __LINE__ = 48;
                          var length;
                          
                          __LINE__ = 48;
                          var _mochaLocalTmp14;
                          
                          __LINE__ = 48;
                          var x;
                          
                          __LINE__ = 48;
                          var _mochaLocalTmp13 = [];
                          
                          __LINE__ = 46;
                          var _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                                try {
                                  __LINE__ = 46;
                                  if (!_isYieldSend){
                                    
                                    __LINE__ = 46;
                                    _mochaIsNewBorn = false;
                                  } else if (_isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined){
                                    
                                    __LINE__ = 46;
                                    __Runtime.exceptionHandler('attempt to send to newborn generator.');
                                  }
                                  
                                  __LINE__ = 46;
                                  while (1){
                                    __LINE__ = 46;
                                    switch (_yieldState) {
                                      case 0 :
                                        
                                        __LINE__ = 48;
                                        for (var _mochaLocalTmp12 in obj){
                                          
                                          __LINE__ = 48;
                                          _mochaLocalTmp13.push(_mochaLocalTmp12);
                                        }
                                        
                                        __LINE__ = 48;
                                        _mochaLocalTmp14 = 0;
                                        
                                        __LINE__ = 48;
                                        length = _mochaLocalTmp13.length;
                                        
                                        __LINE__ = 48;
                                        if (!(_mochaLocalTmp14<length)){
                                          
                                          __LINE__ = 48;
                                          _yieldState = -1;
                                          __LINE__ = 48;
                                          break;
                                        }
                                      case 1 :
                                        
                                        __LINE__ = 48;
                                        _yieldState = 2;
                                        
                                        __LINE__ = 48;
                                        x = _mochaLocalTmp13[_mochaLocalTmp14];
                                        __LINE__ = 48;
                                        return obj[x];
                                      case 2 :
                                        
                                        __LINE__ = 48;
                                         ++ _mochaLocalTmp14;
                                        
                                        __LINE__ = 48;
                                        if (_mochaLocalTmp14<length){
                                          
                                          __LINE__ = 2;
                                          _yieldState = 1;
                                          __LINE__ = 48;
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
                                        } else {
                                          __LINE__ = 46;
                                          __Runtime.throwStopIteration();
                                        }
                                        
                                    }
                                    
                                  }
                                  
                                } catch(e){
                                  __Runtime.exceptionHandler(__LINE__, __FILE__, e);
                                }
                              };
                          __LINE__ = 46;
                          return __Runtime.createGenerator(_mochaGenerator,
                          function () {
                            try {
                              __LINE__ = 46;
                              _yieldState = -1;
                            } catch(e){
                              __Runtime.exceptionHandler(__LINE__, __FILE__, e);
                            }
                          },this);
                        } catch(e){
                          __Runtime.exceptionHandler(__LINE__, __FILE__, e);
                        }
                      }();
                    } catch(e){
                      __Runtime.exceptionHandler(__LINE__, __FILE__, e);
                    }
                  }
                };
              } catch(e){
                __Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            }
            function allKeys(obj) {
              try {
                __LINE__ = 38;
                return  {
                  iterator : function () {
                    try {
                      __LINE__ = 38;
                      return function () {
                        try {
                          __LINE__ = 38;
                          var _mochaIsNewBorn = true;
                          
                          __LINE__ = 38;
                          var _yieldResult = undefined;
                          
                          __LINE__ = 38;
                          var _yieldState = 0;
                          
                          __LINE__ = 40;
                          var length;
                          
                          __LINE__ = 40;
                          var _mochaLocalTmp11;
                          
                          __LINE__ = 40;
                          var x;
                          
                          __LINE__ = 40;
                          var _mochaLocalTmp10 = [];
                          
                          __LINE__ = 38;
                          var _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                                try {
                                  __LINE__ = 38;
                                  if (!_isYieldSend){
                                    
                                    __LINE__ = 38;
                                    _mochaIsNewBorn = false;
                                  } else if (_isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined){
                                    
                                    __LINE__ = 38;
                                    __Runtime.exceptionHandler('attempt to send to newborn generator.');
                                  }
                                  
                                  __LINE__ = 38;
                                  while (1){
                                    __LINE__ = 38;
                                    switch (_yieldState) {
                                      case 0 :
                                        
                                        __LINE__ = 40;
                                        for (var _mochaLocalTmp9 in obj){
                                          
                                          __LINE__ = 40;
                                          _mochaLocalTmp10.push(_mochaLocalTmp9);
                                        }
                                        
                                        __LINE__ = 40;
                                        _mochaLocalTmp11 = 0;
                                        
                                        __LINE__ = 40;
                                        length = _mochaLocalTmp10.length;
                                        
                                        __LINE__ = 40;
                                        if (!(_mochaLocalTmp11<length)){
                                          
                                          __LINE__ = 40;
                                          _yieldState = -1;
                                          __LINE__ = 40;
                                          break;
                                        }
                                      case 1 :
                                        
                                        __LINE__ = 40;
                                        _yieldState = 2;
                                        
                                        __LINE__ = 40;
                                        x = _mochaLocalTmp10[_mochaLocalTmp11];
                                        __LINE__ = 40;
                                        return x;
                                      case 2 :
                                        
                                        __LINE__ = 40;
                                         ++ _mochaLocalTmp11;
                                        
                                        __LINE__ = 40;
                                        if (_mochaLocalTmp11<length){
                                          
                                          __LINE__ = 2;
                                          _yieldState = 1;
                                          __LINE__ = 40;
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
                                        } else {
                                          __LINE__ = 38;
                                          __Runtime.throwStopIteration();
                                        }
                                        
                                    }
                                    
                                  }
                                  
                                } catch(e){
                                  __Runtime.exceptionHandler(__LINE__, __FILE__, e);
                                }
                              };
                          __LINE__ = 38;
                          return __Runtime.createGenerator(_mochaGenerator,
                          function () {
                            try {
                              __LINE__ = 38;
                              _yieldState = -1;
                            } catch(e){
                              __Runtime.exceptionHandler(__LINE__, __FILE__, e);
                            }
                          },this);
                        } catch(e){
                          __Runtime.exceptionHandler(__LINE__, __FILE__, e);
                        }
                      }();
                    } catch(e){
                      __Runtime.exceptionHandler(__LINE__, __FILE__, e);
                    }
                  }
                };
              } catch(e){
                __Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            }
            function items(obj) {
              try {
                __LINE__ = 28;
                return  {
                  iterator : function () {
                    try {
                      __LINE__ = 28;
                      return function () {
                        try {
                          __LINE__ = 28;
                          var _mochaIsNewBorn = true;
                          
                          __LINE__ = 28;
                          var _yieldResult = undefined;
                          
                          __LINE__ = 28;
                          var _yieldState = 0;
                          
                          __LINE__ = 30;
                          var length;
                          
                          __LINE__ = 30;
                          var _mochaLocalTmp8;
                          
                          __LINE__ = 30;
                          var x;
                          
                          __LINE__ = 30;
                          var _mochaLocalTmp7 = [];
                          
                          __LINE__ = 28;
                          var _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                                try {
                                  __LINE__ = 28;
                                  if (!_isYieldSend){
                                    
                                    __LINE__ = 28;
                                    _mochaIsNewBorn = false;
                                  } else if (_isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined){
                                    
                                    __LINE__ = 28;
                                    __Runtime.exceptionHandler('attempt to send to newborn generator.');
                                  }
                                  
                                  __LINE__ = 28;
                                  while (1){
                                    __LINE__ = 28;
                                    switch (_yieldState) {
                                      case 0 :
                                        
                                        __LINE__ = 30;
                                        for (var _mochaLocalTmp6 in obj){
                                          
                                          __LINE__ = 30;
                                          _mochaLocalTmp7.push(_mochaLocalTmp6);
                                        }
                                        
                                        __LINE__ = 30;
                                        _mochaLocalTmp8 = 0;
                                        
                                        __LINE__ = 30;
                                        length = _mochaLocalTmp7.length;
                                        
                                        __LINE__ = 30;
                                        if (!(_mochaLocalTmp8<length)){
                                          
                                          __LINE__ = 30;
                                          _yieldState = -1;
                                          __LINE__ = 30;
                                          break;
                                        }
                                      case 1 :
                                        
                                        __LINE__ = 30;
                                        x = _mochaLocalTmp7[_mochaLocalTmp8];
                                        
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
                                        
                                        __LINE__ = 32;
                                        _yieldState = 3;
                                        __LINE__ = 32;
                                        return [x,obj[x]];
                                      case 3 :
                                        
                                        __LINE__ = 30;
                                        _yieldState = 4;
                                        __LINE__ = 30;
                                        break;
                                      case 4 :
                                        
                                        __LINE__ = 30;
                                         ++ _mochaLocalTmp8;
                                        
                                        __LINE__ = 30;
                                        if (_mochaLocalTmp8<length){
                                          
                                          __LINE__ = 2;
                                          _yieldState = 1;
                                          __LINE__ = 30;
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
                                        } else {
                                          __LINE__ = 28;
                                          __Runtime.throwStopIteration();
                                        }
                                        
                                    }
                                    
                                  }
                                  
                                } catch(e){
                                  __Runtime.exceptionHandler(__LINE__, __FILE__, e);
                                }
                              };
                          __LINE__ = 28;
                          return __Runtime.createGenerator(_mochaGenerator,
                          function () {
                            try {
                              __LINE__ = 28;
                              _yieldState = -1;
                            } catch(e){
                              __Runtime.exceptionHandler(__LINE__, __FILE__, e);
                            }
                          },this);
                        } catch(e){
                          __Runtime.exceptionHandler(__LINE__, __FILE__, e);
                        }
                      }();
                    } catch(e){
                      __Runtime.exceptionHandler(__LINE__, __FILE__, e);
                    }
                  }
                };
              } catch(e){
                __Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            }
            function values(obj) {
              try {
                __LINE__ = 16;
                return  {
                  iterator : function () {
                    try {
                      __LINE__ = 18;
                      return function () {
                        try {
                          __LINE__ = 18;
                          var _mochaIsNewBorn = true;
                          
                          __LINE__ = 18;
                          var _yieldResult = undefined;
                          
                          __LINE__ = 18;
                          var _yieldState = 0;
                          
                          __LINE__ = 18;
                          var length;
                          
                          __LINE__ = 18;
                          var _mochaLocalTmp5;
                          
                          __LINE__ = 18;
                          var x;
                          
                          __LINE__ = 18;
                          var _mochaLocalTmp4 = [];
                          
                          __LINE__ = 18;
                          var _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                                try {
                                  __LINE__ = 18;
                                  if (!_isYieldSend){
                                    
                                    __LINE__ = 18;
                                    _mochaIsNewBorn = false;
                                  } else if (_isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined){
                                    
                                    __LINE__ = 18;
                                    __Runtime.exceptionHandler('attempt to send to newborn generator.');
                                  }
                                  
                                  __LINE__ = 18;
                                  while (1){
                                    __LINE__ = 18;
                                    switch (_yieldState) {
                                      case 0 :
                                        
                                        __LINE__ = 18;
                                        for (var _mochaLocalTmp3 in obj){
                                          
                                          __LINE__ = 18;
                                          _mochaLocalTmp4.push(_mochaLocalTmp3);
                                        }
                                        
                                        __LINE__ = 18;
                                        _mochaLocalTmp5 = 0;
                                        
                                        __LINE__ = 18;
                                        length = _mochaLocalTmp4.length;
                                        
                                        __LINE__ = 18;
                                        if (!(_mochaLocalTmp5<length)){
                                          
                                          __LINE__ = 18;
                                          _yieldState = -1;
                                          __LINE__ = 18;
                                          break;
                                        }
                                      case 1 :
                                        
                                        __LINE__ = 18;
                                        x = _mochaLocalTmp4[_mochaLocalTmp5];
                                        
                                        __LINE__ = 20;
                                        if (hasOwn.call(obj,x)){
                                          
                                          __LINE__ = 20;
                                          _yieldState = 2;
                                          __LINE__ = 20;
                                          break;
                                        } else {
                                          
                                          __LINE__ = 20;
                                          _yieldState = 3;
                                          __LINE__ = 20;
                                          break;
                                        }
                                      case 2 :
                                        
                                        __LINE__ = 20;
                                        _yieldState = 3;
                                        __LINE__ = 20;
                                        return obj[x];
                                      case 3 :
                                        
                                        __LINE__ = 20;
                                        _yieldState = 4;
                                        __LINE__ = 20;
                                        break;
                                      case 4 :
                                        
                                        __LINE__ = 18;
                                         ++ _mochaLocalTmp5;
                                        
                                        __LINE__ = 18;
                                        if (_mochaLocalTmp5<length){
                                          
                                          __LINE__ = 2;
                                          _yieldState = 1;
                                          __LINE__ = 18;
                                          break;
                                        } else {
                                          
                                          __LINE__ = 2;
                                          _yieldState = -1;
                                        }
                                      case -1 :
                                        
                                        __LINE__ = 18;
                                        if (_isYieldSafe){
                                          __LINE__ = 18;
                                          return undefined;
                                        } else {
                                          __LINE__ = 18;
                                          __Runtime.throwStopIteration();
                                        }
                                        
                                    }
                                    
                                  }
                                  
                                } catch(e){
                                  __Runtime.exceptionHandler(__LINE__, __FILE__, e);
                                }
                              };
                          __LINE__ = 18;
                          return __Runtime.createGenerator(_mochaGenerator,
                          function () {
                            try {
                              __LINE__ = 18;
                              _yieldState = -1;
                            } catch(e){
                              __Runtime.exceptionHandler(__LINE__, __FILE__, e);
                            }
                          },this);
                        } catch(e){
                          __Runtime.exceptionHandler(__LINE__, __FILE__, e);
                        }
                      }();
                    } catch(e){
                      __Runtime.exceptionHandler(__LINE__, __FILE__, e);
                    }
                  }
                };
              } catch(e){
                __Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            }
            function keys(obj) {
              try {
                __LINE__ = 6;
                return  {
                  iterator : function () {
                    try {
                      __LINE__ = 6;
                      return function () {
                        try {
                          __LINE__ = 6;
                          var _mochaIsNewBorn = true;
                          
                          __LINE__ = 6;
                          var _yieldResult = undefined;
                          
                          __LINE__ = 6;
                          var _yieldState = 0;
                          
                          __LINE__ = 8;
                          var length;
                          
                          __LINE__ = 8;
                          var _mochaLocalTmp2;
                          
                          __LINE__ = 8;
                          var x;
                          
                          __LINE__ = 8;
                          var _mochaLocalTmp1 = [];
                          
                          __LINE__ = 6;
                          var _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                                try {
                                  __LINE__ = 6;
                                  if (!_isYieldSend){
                                    
                                    __LINE__ = 6;
                                    _mochaIsNewBorn = false;
                                  } else if (_isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined){
                                    
                                    __LINE__ = 6;
                                    __Runtime.exceptionHandler('attempt to send to newborn generator.');
                                  }
                                  
                                  __LINE__ = 6;
                                  while (1){
                                    __LINE__ = 6;
                                    switch (_yieldState) {
                                      case 0 :
                                        
                                        __LINE__ = 8;
                                        for (var _mochaLocalTmp0 in obj){
                                          
                                          __LINE__ = 8;
                                          _mochaLocalTmp1.push(_mochaLocalTmp0);
                                        }
                                        
                                        __LINE__ = 8;
                                        _mochaLocalTmp2 = 0;
                                        
                                        __LINE__ = 8;
                                        length = _mochaLocalTmp1.length;
                                        
                                        __LINE__ = 8;
                                        if (!(_mochaLocalTmp2<length)){
                                          
                                          __LINE__ = 8;
                                          _yieldState = -1;
                                          __LINE__ = 8;
                                          break;
                                        }
                                      case 1 :
                                        
                                        __LINE__ = 8;
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
                                        
                                        __LINE__ = 10;
                                        _yieldState = 3;
                                        __LINE__ = 10;
                                        return x;
                                      case 3 :
                                        
                                        __LINE__ = 8;
                                        _yieldState = 4;
                                        __LINE__ = 8;
                                        break;
                                      case 4 :
                                        
                                        __LINE__ = 8;
                                         ++ _mochaLocalTmp2;
                                        
                                        __LINE__ = 8;
                                        if (_mochaLocalTmp2<length){
                                          
                                          __LINE__ = 2;
                                          _yieldState = 1;
                                          __LINE__ = 8;
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
                                        } else {
                                          __LINE__ = 6;
                                          __Runtime.throwStopIteration();
                                        }
                                        
                                    }
                                    
                                  }
                                  
                                } catch(e){
                                  __Runtime.exceptionHandler(__LINE__, __FILE__, e);
                                }
                              };
                          __LINE__ = 6;
                          return __Runtime.createGenerator(_mochaGenerator,
                          function () {
                            try {
                              __LINE__ = 6;
                              _yieldState = -1;
                            } catch(e){
                              __Runtime.exceptionHandler(__LINE__, __FILE__, e);
                            }
                          },this);
                        } catch(e){
                          __Runtime.exceptionHandler(__LINE__, __FILE__, e);
                        }
                      }();
                    } catch(e){
                      __Runtime.exceptionHandler(__LINE__, __FILE__, e);
                    }
                  }
                };
              } catch(e){
                __Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            }
            try {
              
              __LINE__ = 2;
              var _mochaLocalExport = {},
                  hasOwn = {}.hasOwnProperty;
              
              __LINE__ = 4;
              _mochaLocalExport.keys = keys;
              
              __LINE__ = 16;
              _mochaLocalExport.values = values;
              
              __LINE__ = 26;
              _mochaLocalExport.items = items;
              
              __LINE__ = 36;
              _mochaLocalExport.allKeys = allKeys;
              
              __LINE__ = 44;
              _mochaLocalExport.allValues = allValues;
              
              __LINE__ = 52;
              _mochaLocalExport.allItems = allItems;
              __LINE__ = 2;
              return _mochaLocalExport;
            } catch(e){
              __Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          }();
    } catch(e){
      __Runtime.exceptionHandler(__LINE__, __FILE__, e);
    }
  }();
  
  __LINE__ = 0;
  !function () {
    try {
      var __FILE__ = "-839149963-for_of_test.js",
          __LINE__ = 0;
      __LINE__ = 1;
      var _mochaLocalTmp0 = __Runtime.modules.get('iterators'),
          values = _mochaLocalTmp0.values,
          item = function (obj) {
            try {
              __LINE__ = 3;
              return  {
                iterator : function () {
                  try {
                    __LINE__ = 4;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 4;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 4;
                    var _yieldState = 0;
                    
                    __LINE__ = 5;
                    var length;
                    
                    __LINE__ = 5;
                    var _mochaLocalTmp3;
                    
                    __LINE__ = 5;
                    var i;
                    
                    __LINE__ = 5;
                    var _mochaLocalTmp2 = [];
                    
                    __LINE__ = 4;
                    var _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                          try {
                            __LINE__ = 4;
                            if (!_isYieldSend){
                              
                              __LINE__ = 4;
                              _mochaIsNewBorn = false;
                            } else if (_isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined){
                              
                              __LINE__ = 4;
                              __Runtime.exceptionHandler('attempt to send to newborn generator.');
                            }
                            
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
                                  } else {
                                    __LINE__ = 4;
                                    __Runtime.throwStopIteration();
                                  }
                                  
                              }
                              
                            }
                            
                          } catch(e){
                            __Runtime.exceptionHandler(__LINE__, __FILE__, e);
                          }
                        };
                    __LINE__ = 4;
                    return __Runtime.createGenerator(_mochaGenerator,
                    function () {
                      try {
                        __LINE__ = 4;
                        _yieldState = -1;
                      } catch(e){
                        __Runtime.exceptionHandler(__LINE__, __FILE__, e);
                      }
                    },this);
                  } catch(e){
                    __Runtime.exceptionHandler(__LINE__, __FILE__, e);
                  }
                }
              };
            } catch(e){
              __Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          },
          key = function (obj) {
            try {
              __LINE__ = 12;
              return  {
                iterator : function () {
                  try {
                    __LINE__ = 13;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 13;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 13;
                    var _yieldState = 0;
                    
                    __LINE__ = 14;
                    var length;
                    
                    __LINE__ = 14;
                    var _mochaLocalTmp6;
                    
                    __LINE__ = 14;
                    var i;
                    
                    __LINE__ = 14;
                    var _mochaLocalTmp5 = [];
                    
                    __LINE__ = 13;
                    var _mochaGenerator = function (_isYieldSend,_isYieldSafe) {
                          try {
                            __LINE__ = 13;
                            if (!_isYieldSend){
                              
                              __LINE__ = 13;
                              _mochaIsNewBorn = false;
                            } else if (_isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined){
                              
                              __LINE__ = 13;
                              __Runtime.exceptionHandler('attempt to send to newborn generator.');
                            }
                            
                            __LINE__ = 13;
                            while (1){
                              __LINE__ = 13;
                              switch (_yieldState) {
                                case 0 :
                                  
                                  __LINE__ = 14;
                                  for (var _mochaLocalTmp4 in obj){
                                    
                                    __LINE__ = 14;
                                    _mochaLocalTmp5.push(_mochaLocalTmp4);
                                  }
                                  
                                  __LINE__ = 14;
                                  _mochaLocalTmp6 = 0;
                                  
                                  __LINE__ = 14;
                                  length = _mochaLocalTmp5.length;
                                  
                                  __LINE__ = 14;
                                  if (!(_mochaLocalTmp6<length)){
                                    
                                    __LINE__ = 14;
                                    _yieldState = -1;
                                    __LINE__ = 14;
                                    break;
                                  }
                                case 1 :
                                  
                                  __LINE__ = 15;
                                  _yieldState = 2;
                                  
                                  __LINE__ = 14;
                                  i = _mochaLocalTmp5[_mochaLocalTmp6];
                                  __LINE__ = 15;
                                  return i;
                                case 2 :
                                  
                                  __LINE__ = 14;
                                   ++ _mochaLocalTmp6;
                                  
                                  __LINE__ = 14;
                                  if (_mochaLocalTmp6<length){
                                    
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
                                  } else {
                                    __LINE__ = 13;
                                    __Runtime.throwStopIteration();
                                  }
                                  
                              }
                              
                            }
                            
                          } catch(e){
                            __Runtime.exceptionHandler(__LINE__, __FILE__, e);
                          }
                        };
                    __LINE__ = 13;
                    return __Runtime.createGenerator(_mochaGenerator,
                    function () {
                      try {
                        __LINE__ = 13;
                        _yieldState = -1;
                      } catch(e){
                        __Runtime.exceptionHandler(__LINE__, __FILE__, e);
                      }
                    },this);
                  } catch(e){
                    __Runtime.exceptionHandler(__LINE__, __FILE__, e);
                  }
                }
              };
            } catch(e){
              __Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          },
          iter =  {
            arr : [],
            add : function (value) {
              try {
                __LINE__ = 23;
                this.arr.push(value);
              } catch(e){
                __Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            },
            iterator : function () {
              try {
                __LINE__ = 26;
                var arr = this.arr;
                __LINE__ = 27;
                return  {
                  index : 0,
                  next : function () {
                    try {
                      __LINE__ = 30;
                      if (arr.length>this.index){
                        
                        __LINE__ = 31;
                        var ret = arr[this.index];
                        
                        __LINE__ = 32;
                        this.index ++ ;
                        __LINE__ = 33;
                        return ret;
                      } else {
                        __LINE__ = 35;
                        return undefined;
                      }
                      
                    } catch(e){
                      __Runtime.exceptionHandler(__LINE__, __FILE__, e);
                    }
                  }
                };
              } catch(e){
                __Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            }
          },
          testObj =  {
            value1 : 100,
            value2 : 200,
            value3 : 300,
            value4 : 400
          },
          ret = [],
          i,
          _mochaLocalTmp7 = item(testObj);
      
      __LINE__ = 49;
      _mochaLocalTmp7 = __Runtime.hasIterator(_mochaLocalTmp7)?__Runtime.getIterator(_mochaLocalTmp7) : _mochaLocalTmp7;
      
      __LINE__ = 49;
      if (_mochaLocalTmp7.__nothrowNext__){
        __LINE__ = 49;
        while ((i = _mochaLocalTmp7.__nothrowNext__())){
          __LINE__ = 50;
          ret.push(i);
        }
        
      } else {
        __LINE__ = 49;
        __Runtime.exceptionHandler(49,'for_of_test.js','for of statement expect iterator or generator object.');
      }
      
      __LINE__ = 52;
      __Runtime.assert( true ,ret[0] === 100,"ret[0] === 100",52,'for_of_test.js');
      
      __LINE__ = 53;
      __Runtime.assert( true ,ret[1] === 200,"ret[1] === 200",53,'for_of_test.js');
      
      __LINE__ = 54;
      __Runtime.assert( true ,ret[2] === 300,"ret[2] === 300",54,'for_of_test.js');
      
      __LINE__ = 55;
      __Runtime.assert( true ,ret[3] === 400,"ret[3] === 400",55,'for_of_test.js');
      
      __LINE__ = 57;
      ret = [];
      
      __LINE__ = 58;
      var x,
          _mochaLocalTmp8 = key(testObj);
      
      __LINE__ = 58;
      _mochaLocalTmp8 = __Runtime.hasIterator(_mochaLocalTmp8)?__Runtime.getIterator(_mochaLocalTmp8) : _mochaLocalTmp8;
      
      __LINE__ = 58;
      if (_mochaLocalTmp8.__nothrowNext__){
        __LINE__ = 58;
        while ((x = _mochaLocalTmp8.__nothrowNext__())){
          __LINE__ = 59;
          ret.push(x);
        }
        
      } else {
        __LINE__ = 58;
        __Runtime.exceptionHandler(58,'for_of_test.js','for of statement expect iterator or generator object.');
      }
      
      __LINE__ = 61;
      __Runtime.assert( true ,ret[0] === "value1","ret[0] === \"value1\"",61,'for_of_test.js');
      
      __LINE__ = 62;
      __Runtime.assert( true ,ret[1] === "value2","ret[1] === \"value2\"",62,'for_of_test.js');
      
      __LINE__ = 63;
      __Runtime.assert( true ,ret[2] === "value3","ret[2] === \"value3\"",63,'for_of_test.js');
      
      __LINE__ = 64;
      __Runtime.assert( true ,ret[3] === "value4","ret[3] === \"value4\"",64,'for_of_test.js');
      
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
      var _mochaLocalTmp9 = iter;
      
      __LINE__ = 71;
      _mochaLocalTmp9 = __Runtime.hasIterator(_mochaLocalTmp9)?__Runtime.getIterator(_mochaLocalTmp9) : _mochaLocalTmp9;
      
      __LINE__ = 71;
      if (_mochaLocalTmp9.__nothrowNext__){
        __LINE__ = 71;
        while ((i = _mochaLocalTmp9.__nothrowNext__())){
          __LINE__ = 72;
          ret.push(i);
        }
        
      } else {
        __LINE__ = 71;
        __Runtime.exceptionHandler(71,'for_of_test.js','for of statement expect iterator or generator object.');
      }
      
      __LINE__ = 74;
      __Runtime.assert( true ,ret[0] === 100,"ret[0] === 100",74,'for_of_test.js');
      
      __LINE__ = 75;
      __Runtime.assert( true ,ret[1] === 200,"ret[1] === 200",75,'for_of_test.js');
      
      __LINE__ = 76;
      __Runtime.assert( true ,ret[2] === 300,"ret[2] === 300",76,'for_of_test.js');
      
      __LINE__ = 77;
      __Runtime.assert( true ,ret[3] === 400,"ret[3] === 400",77,'for_of_test.js');
    } catch(e){
      __Runtime.exceptionHandler(__LINE__, __FILE__, e);
    }
  }();
}();
