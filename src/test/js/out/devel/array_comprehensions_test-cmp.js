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
  
  Runtime.extend(Runtime, {
    Generator : function (){},
    createGenerator : function (generatorFn,closeFn,context) {
      var ret = new  this .Generator;
      
       this .createUnenumProp(ret,"next",generatorFn.bind(context, false , false ));
      
       this .createUnenumProp(ret,"send",generatorFn.bind(context, true , false ));
      
       this .createUnenumProp(ret,"close",closeFn.bind(context));
      
       this .createUnenumProp(ret,"__nothrowNext__",generatorFn.bind(context, false , true ));
      
       this .createUnenumProp(ret,"toString",
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
      return obj instanceof  this .Generator;
    },
    getIterator : function (obj) {
      var ret = obj.iterator(),
          newObj;
      
      if ( this .isGenerator(ret)){
        return ret;
      }
      
      newObj = {};
      
      if (ret.next){
        
         this .createUnenumProp(newObj,"next",
        function () {
          var result = ret.next();
          
          if (result === undefined){
            
             this .throwStopIteration();
          }
          return result;
        });
      } else {
        return {};
      }
      
      if (!("__nothrowNext__" in ret)){
        
         this .createUnenumProp(newObj,"__nothrowNext__",ret.next.bind(ret));
      }
      
      for (var prop in ret){
        
        if (prop !== "next" && prop !== "__nothrowNext__"){
          
          newObj[prop] = ret[prop];
        }
        
      }
      
      if (!("toString" in ret)){
        
         this .createUnenumProp(newObj,"toString",
        function () {
          return "[object Iterator]";
        });
      }
      return newObj;
    },
    hasIterator : function (obj) {
      return 'iterator' in obj;
    }
  });
  
  !("StopIteration" in Runtime._global) && (Runtime._global.StopIteration =  {
    toString : function () {
      return "[object StopIteration]";
    }
  });
  
  Runtime.extend(Runtime, {
    modules : (function () {
      function Module(){}
      function ModuleContainer(){}
      
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
      return new ModuleContainer;
    })()
  });
  
  __LINE__ = 2;
  !function () {
    try {
      var __FILE__ = "iterators",
          __LINE__ = 0;
      __LINE__ = 2;
      Runtime.modules.add('iterators');
      
      __LINE__ = 2;
      var iterators = Runtime.modules.get('iterators').iterators = function () {
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
                                    Runtime.exceptionHandler('attempt to send to newborn generator.');
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
                                          Runtime.throwStopIteration();
                                        }
                                        
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
                  }
                };
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
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
                                    Runtime.exceptionHandler('attempt to send to newborn generator.');
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
                                          Runtime.throwStopIteration();
                                        }
                                        
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
                  }
                };
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
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
                                    Runtime.exceptionHandler('attempt to send to newborn generator.');
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
                                          Runtime.throwStopIteration();
                                        }
                                        
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
                  }
                };
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
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
                                    Runtime.exceptionHandler('attempt to send to newborn generator.');
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
                                          Runtime.throwStopIteration();
                                        }
                                        
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
                  }
                };
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
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
                                    Runtime.exceptionHandler('attempt to send to newborn generator.');
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
                                          Runtime.throwStopIteration();
                                        }
                                        
                                    }
                                    
                                  }
                                  
                                } catch(e){
                                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                                }
                              };
                          __LINE__ = 18;
                          return Runtime.createGenerator(_mochaGenerator,
                          function () {
                            try {
                              __LINE__ = 18;
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
                  }
                };
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
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
                                    Runtime.exceptionHandler('attempt to send to newborn generator.');
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
                                          Runtime.throwStopIteration();
                                        }
                                        
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
                  }
                };
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
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
      var __FILE__ = "-839149963-array_comprehensions_test.js",
          __LINE__ = 0;
      __LINE__ = 1;
      var _mochaLocalTmp0 = Runtime.modules.get('iterators').iterators,
          items = _mochaLocalTmp0.items,
          testTarget =  {
            value1 : 100,
            value2 : 200,
            value3 : 300
          },
          cmpTest = function () {
            try {
              __LINE__ = 9;
              var _mochaLocalTmp1 = [];
              
              __LINE__ = 9;
              for (var prop in testTarget){
                
                __LINE__ = 9;
                prop = testTarget[prop];
                
                __LINE__ = 9;
                _mochaLocalTmp1.push(prop);
              }
              __LINE__ = 9;
              return _mochaLocalTmp1;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          }.call( this );
      
      __LINE__ = 10;
      Runtime.assert( true ,cmpTest[0] === 100,"cmpTest[0] === 100",10,'array_comprehensions_test.js');
      
      __LINE__ = 11;
      Runtime.assert( true ,cmpTest[1] === 200,"cmpTest[1] === 200",11,'array_comprehensions_test.js');
      
      __LINE__ = 12;
      Runtime.assert( true ,cmpTest[2] === 300,"cmpTest[2] === 300",12,'array_comprehensions_test.js');
      
      __LINE__ = 14;
      cmpTest = function () {
        try {
          __LINE__ = 14;
          var _mochaLocalTmp2 = [];
          
          __LINE__ = 14;
          for (var prop in testTarget){
            
            __LINE__ = 14;
            _mochaLocalTmp2.push(prop);
          }
          __LINE__ = 14;
          return _mochaLocalTmp2;
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }.call( this );
      
      __LINE__ = 15;
      Runtime.assert( true ,cmpTest[0] === "value1","cmpTest[0] === \"value1\"",15,'array_comprehensions_test.js');
      
      __LINE__ = 16;
      Runtime.assert( true ,cmpTest[1] === "value2","cmpTest[1] === \"value2\"",16,'array_comprehensions_test.js');
      
      __LINE__ = 17;
      Runtime.assert( true ,cmpTest[2] === "value3","cmpTest[2] === \"value3\"",17,'array_comprehensions_test.js');
      
      __LINE__ = 19;
      cmpTest = function () {
        try {
          __LINE__ = 19;
          var _mochaLocalTmp3 = [],
              prop,
              _mochaLocalTmp4 = items(testTarget);
          
          __LINE__ = 19;
          _mochaLocalTmp4 = Runtime.hasIterator(_mochaLocalTmp4)?Runtime.getIterator(_mochaLocalTmp4) : _mochaLocalTmp4;
          
          __LINE__ = 19;
          if (_mochaLocalTmp4.__nothrowNext__){
            __LINE__ = 19;
            while ((prop = _mochaLocalTmp4.__nothrowNext__())){
              __LINE__ = 19;
              _mochaLocalTmp3.push(prop);
            }
            
          } else {
            __LINE__ = 19;
            Runtime.exceptionHandler(19,'array_comprehensions_test.js','for of statement expect iterator or generator object.');
          }
          __LINE__ = 19;
          return _mochaLocalTmp3;
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }.call( this );
      
      __LINE__ = 20;
      Runtime.assert( true ,cmpTest[0][0] === "value1","cmpTest[0][0] === \"value1\"",20,'array_comprehensions_test.js');
      
      __LINE__ = 21;
      Runtime.assert( true ,cmpTest[0][1] === 100,"cmpTest[0][1] === 100",21,'array_comprehensions_test.js');
      
      __LINE__ = 22;
      Runtime.assert( true ,cmpTest[1][0] === "value2","cmpTest[1][0] === \"value2\"",22,'array_comprehensions_test.js');
      
      __LINE__ = 23;
      Runtime.assert( true ,cmpTest[1][1] === 200,"cmpTest[1][1] === 200",23,'array_comprehensions_test.js');
      
      __LINE__ = 24;
      Runtime.assert( true ,cmpTest[2][0] === "value3","cmpTest[2][0] === \"value3\"",24,'array_comprehensions_test.js');
      
      __LINE__ = 25;
      Runtime.assert( true ,cmpTest[2][1] === 300,"cmpTest[2][1] === 300",25,'array_comprehensions_test.js');
      
      __LINE__ = 28;
      var cmpTest = function () {
            try {
              __LINE__ = 28;
              var _mochaLocalTmp5 = [];
              
              __LINE__ = 28;
              for (var prop in testTarget){
                
                __LINE__ = 28;
                prop = testTarget[prop];
                
                __LINE__ = 28;
                prop === 200 && _mochaLocalTmp5.push(prop);
              }
              __LINE__ = 28;
              return _mochaLocalTmp5;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          }.call( this );
      
      __LINE__ = 29;
      Runtime.assert( true ,cmpTest[0] === 200,"cmpTest[0] === 200",29,'array_comprehensions_test.js');
      
      __LINE__ = 31;
      cmpTest = function () {
        try {
          __LINE__ = 31;
          var _mochaLocalTmp6 = [];
          
          __LINE__ = 31;
          for (var prop in testTarget){
            
            __LINE__ = 31;
            prop === "value2" && _mochaLocalTmp6.push(prop);
          }
          __LINE__ = 31;
          return _mochaLocalTmp6;
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }.call( this );
      
      __LINE__ = 32;
      Runtime.assert( true ,cmpTest[0] === "value2","cmpTest[0] === \"value2\"",32,'array_comprehensions_test.js');
      
      __LINE__ = 34;
      cmpTest = function () {
        try {
          __LINE__ = 34;
          var _mochaLocalTmp7 = [],
              prop,
              _mochaLocalTmp8 = items(testTarget);
          
          __LINE__ = 34;
          _mochaLocalTmp8 = Runtime.hasIterator(_mochaLocalTmp8)?Runtime.getIterator(_mochaLocalTmp8) : _mochaLocalTmp8;
          
          __LINE__ = 34;
          if (_mochaLocalTmp8.__nothrowNext__){
            __LINE__ = 34;
            while ((prop = _mochaLocalTmp8.__nothrowNext__())){
              __LINE__ = 34;
              prop[1] === 200 && _mochaLocalTmp7.push(prop);
            }
            
          } else {
            __LINE__ = 34;
            Runtime.exceptionHandler(34,'array_comprehensions_test.js','for of statement expect iterator or generator object.');
          }
          __LINE__ = 34;
          return _mochaLocalTmp7;
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }.call( this );
      
      __LINE__ = 35;
      Runtime.assert( true ,cmpTest[0][0] === "value2","cmpTest[0][0] === \"value2\"",35,'array_comprehensions_test.js');
      
      __LINE__ = 36;
      Runtime.assert( true ,cmpTest[0][1] === 200,"cmpTest[0][1] === 200",36,'array_comprehensions_test.js');
      
      __LINE__ = 38;
      testTarget =  {
        value1 :  {
          value1 : 100
        },
        value2 :  {
          value2 : 200
        },
        value3 :  {
          value3 : 300
        }
      };
      
      __LINE__ = 44;
      cmpTest = function () {
        try {
          __LINE__ = 44;
          var _mochaLocalTmp9 = [];
          
          __LINE__ = 44;
          for (var prop in testTarget){
            
            __LINE__ = 44;
            prop = testTarget[prop];
            
            __LINE__ = 44;
            for (var x in prop){
              
              __LINE__ = 44;
              x = prop[x];
              
              __LINE__ = 44;
              _mochaLocalTmp9.push(x);
            }
            
          }
          __LINE__ = 44;
          return _mochaLocalTmp9;
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }.call( this );
      
      __LINE__ = 45;
      Runtime.assert( true ,cmpTest[0] === 100,"cmpTest[0] === 100",45,'array_comprehensions_test.js');
      
      __LINE__ = 46;
      Runtime.assert( true ,cmpTest[1] === 200,"cmpTest[1] === 200",46,'array_comprehensions_test.js');
      
      __LINE__ = 47;
      Runtime.assert( true ,cmpTest[2] === 300,"cmpTest[2] === 300",47,'array_comprehensions_test.js');
      
      __LINE__ = 49;
      cmpTest = function () {
        try {
          __LINE__ = 49;
          var _mochaLocalTmp10 = [];
          
          __LINE__ = 49;
          for (var prop in testTarget){
            
            __LINE__ = 49;
            prop = testTarget[prop];
            
            __LINE__ = 49;
            for (var x in prop){
              __LINE__ = 49;
              _mochaLocalTmp10.push(x);
            }
            
          }
          __LINE__ = 49;
          return _mochaLocalTmp10;
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }.call( this );
      
      __LINE__ = 50;
      Runtime.assert( true ,cmpTest[0] === "value1","cmpTest[0] === \"value1\"",50,'array_comprehensions_test.js');
      
      __LINE__ = 51;
      Runtime.assert( true ,cmpTest[1] === "value2","cmpTest[1] === \"value2\"",51,'array_comprehensions_test.js');
      
      __LINE__ = 52;
      Runtime.assert( true ,cmpTest[2] === "value3","cmpTest[2] === \"value3\"",52,'array_comprehensions_test.js');
      
      __LINE__ = 54;
      cmpTest = function () {
        try {
          __LINE__ = 54;
          var _mochaLocalTmp11 = [];
          
          __LINE__ = 54;
          for (var prop in testTarget){
            
            __LINE__ = 54;
            prop = testTarget[prop];
            
            __LINE__ = 54;
            var x;
            
            __LINE__ = 54;
            var _mochaLocalTmp12 = items(prop);
            
            __LINE__ = 54;
            _mochaLocalTmp12 = Runtime.hasIterator(_mochaLocalTmp12)?Runtime.getIterator(_mochaLocalTmp12) : _mochaLocalTmp12;
            
            __LINE__ = 54;
            if (_mochaLocalTmp12.__nothrowNext__){
              __LINE__ = 54;
              while ((x = _mochaLocalTmp12.__nothrowNext__())){
                __LINE__ = 54;
                _mochaLocalTmp11.push(x);
              }
              
            } else {
              __LINE__ = 54;
              Runtime.exceptionHandler(54,'array_comprehensions_test.js','for of statement expect iterator or generator object.');
            }
            
          }
          __LINE__ = 54;
          return _mochaLocalTmp11;
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }.call( this );
      
      __LINE__ = 55;
      Runtime.assert( true ,cmpTest[0][0] === "value1","cmpTest[0][0] === \"value1\"",55,'array_comprehensions_test.js');
      
      __LINE__ = 56;
      Runtime.assert( true ,cmpTest[0][1] === 100,"cmpTest[0][1] === 100",56,'array_comprehensions_test.js');
      
      __LINE__ = 57;
      Runtime.assert( true ,cmpTest[1][0] === "value2","cmpTest[1][0] === \"value2\"",57,'array_comprehensions_test.js');
      
      __LINE__ = 58;
      Runtime.assert( true ,cmpTest[1][1] === 200,"cmpTest[1][1] === 200",58,'array_comprehensions_test.js');
      
      __LINE__ = 59;
      Runtime.assert( true ,cmpTest[2][0] === "value3","cmpTest[2][0] === \"value3\"",59,'array_comprehensions_test.js');
      
      __LINE__ = 60;
      Runtime.assert( true ,cmpTest[2][1] === 300,"cmpTest[2][1] === 300",60,'array_comprehensions_test.js');
      
      __LINE__ = 63;
      var m = function (_mochaLocalTmp13) {
            "use strict";
            try {
              __LINE__ = 63;
              var v = _mochaLocalTmp13.v;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          };
    } catch(e){
      Runtime.exceptionHandler(__LINE__, __FILE__, e);
    }
  }();
}();
