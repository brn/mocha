!function() {
  var __FILE__ = "Runtime",
      __LINE__ = 0;
  
  var _mochaGlobalExport/*_mochaGlobalExport*/ = {};
  
  !function (_mochaLocalTmp0/*_mochaLocalTmp0*/,_mochaLocalTmp1/*_mochaLocalTmp1*/,_mochaLocalTmp2/*_mochaLocalTmp2*/,_mochaLocalTmp3/*_mochaLocalTmp3*/) {
    function defineBuiltin/*defineBuiltin*/(obj/*obj*/,name/*name*/,value/*value*/) {
      return Object.defineProperty(obj/*obj*/,name/*name*/, {
        value : value/*value*/,
        configurable : true,
        enumerable : false,
        writable : true
      });
    }
    function callbackCheck/*callbackCheck*/(callback/*callback*/,type/*type*/) {
      
      Runtime/*Runtime*/.assert(true,typeof type/*type*/ === "string","typeof type === \"string\"",43,'runtime.js');
      
      typeof callback/*callback*/ !== "function" && builtinTypeError/*builtinTypeError*/(type/*type*/+" : first argument is not callable");
    }
    function builtinTypeError/*builtinTypeError*/(message/*message*/) {
      try {
        throw new TypeError(message/*message*/)
        
      } catch(e){
        throw new Error(e)
        
      }
      
    }
    var stringProto/*stringProto*/ = _mochaLocalTmp0/*_mochaLocalTmp0*/.prototype,
        arrayProto/*arrayProto*/ = _mochaLocalTmp1/*_mochaLocalTmp1*/.prototype,
        functionProto/*functionProto*/ = _mochaLocalTmp2/*_mochaLocalTmp2*/.prototype,
        dateProto/*dateProto*/ = _mochaLocalTmp3/*_mochaLocalTmp3*/.prototype;
    
    !Object.keys && (Object.keys = function (obj/*obj*/) {
      !obj/*obj*/ && builtinTypeError/*builtinTypeError*/("Object.keys : first arguments is null or not defined.");
      
      var ret/*ret*/ = [],
          iter/*iter*/ = -1;
      
      for (var i/*i*/ in obj/*obj*/){
        
        obj/*obj*/.hasOwnProperty(i/*i*/) && (ret/*ret*/[ ++ iter/*iter*/] = obj/*obj*/[i/*i*/]);
      }
      return ret/*ret*/;
    });
    
    !Object.preventExtensions && (Object.preventExtensions = function (o/*o*/) {
      return o/*o*/;
    });
    
    !Object.seal && (Object.seal = function (o/*o*/) {
      return o/*o*/;
    });
    
    !Object.freeze && (Object.freeze = function (o/*o*/) {
      return o/*o*/;
    });
    
    var hasRealEcma5/*hasRealEcma5*/ = function () {
          var ret/*ret*/;
          
          try {
            
            var obj/*obj*/ = {};
            
            Object.defineProperty(obj/*obj*/,"test", {
              configurable : false,
              writable : false,
              enumerable : false,
              value : 0
            });
            
            obj/*obj*/.test = 200;
            
            ret/*ret*/ = (obj/*obj*/.test === 200)?false : true;
          } catch(e){
            
            ret/*ret*/ = false;
          }
          return ret/*ret*/;
        }();
    
    !hasRealEcma5/*hasRealEcma5*/ && (Object.defineProperty = function (obj/*obj*/,prop/*prop*/,valobj/*valobj*/) {
      "value" in valobj/*valobj*/ && (obj/*obj*/[prop/*prop*/] = valobj/*valobj*/.value);
    });
    
    if (!stringProto/*stringProto*/.trim){
      
      stringProto/*stringProto*/.trim = function () {
        return this.replace(stringProto/*stringProto*/.trim.rtrim,"");
      };
      
      stringProto/*stringProto*/.trim.rtrim = /^\s*|\s*$/g;
    }
    
    !stringProto/*stringProto*/.repeat && defineBuiltin/*defineBuiltin*/(stringProto/*stringProto*/,"repeat",
    function (num/*num*/) {
      return Array(num/*num*/+1).join(this.toString());
    });
    
    !stringProto/*stringProto*/.startsWith && defineBuiltin/*defineBuiltin*/(stringProto/*stringProto*/,"startsWith",
    function (str/*str*/) {
      return !this.indexOf(str/*str*/);
    });
    
    !stringProto/*stringProto*/.endsWith && defineBuiltin/*defineBuiltin*/(stringProto/*stringProto*/,"endsWith",
    function (str/*str*/) {
      var t/*t*/ = String(str/*str*/),
          index/*index*/ = this.lastIndexOf(t/*t*/);
      return index/*index*/ >= 0 && index/*index*/ === this.length-t/*t*/.length;
    });
    
    !stringProto/*stringProto*/.contains && defineBuiltin/*defineBuiltin*/(stringProto/*stringProto*/,"contains",
    function (str/*str*/) {
      return this.indexOf(str/*str*/) !== -1;
    });
    
    !stringProto/*stringProto*/.toArray && defineBuiltin/*defineBuiltin*/(stringProto/*stringProto*/,"toArray",
    function (str/*str*/) {
      return this.split("");
    });
    
    !functionProto/*functionProto*/.bind && defineBuiltin/*defineBuiltin*/(functionProto/*functionProto*/,"bind",
    function () {
      var argArray/*argArray*/ = arrayProto/*arrayProto*/.slice.call(arguments),
          context/*context*/ = argArray/*argArray*/.shift(),
          ret/*ret*/ = function () {
            var args/*args*/ = argArray/*argArray*/.concat(arrayProto/*arrayProto*/.slice.call(arguments));
            return this !== null && this !== window && this instanceof ret/*ret*/?ret/*ret*/.context.apply(this,args/*args*/) : ret/*ret*/.context.apply(context/*context*/,args/*args*/);
          };
      
      ret/*ret*/.prototype = this.prototype;
      
      ret/*ret*/.context = this;
      return ret/*ret*/;
    });
    
    !arrayProto/*arrayProto*/.forEach && defineBuiltin/*defineBuiltin*/(arrayProto/*arrayProto*/,"forEach",
    function (callback/*callback*/,that/*that*/) {
      callbackCheck/*callbackCheck*/(callback/*callback*/,"Array.forEach");
      
      var iter/*iter*/ = -1,
          ta/*ta*/;
      
      this === null && builtinTypeError/*builtinTypeError*/("Array.forEach : this is null or not defined");
      
      if (that/*that*/){
        while ((ta/*ta*/ = this[ ++ iter/*iter*/]) !== null && ta/*ta*/ !== undefined){
          callback/*callback*/.call(that/*that*/,ta/*ta*/,iter/*iter*/,this);
        }
        
      } else {
        while ((ta/*ta*/ = this[ ++ iter/*iter*/]) !== null && ta/*ta*/ !== undefined){
          callback/*callback*/(ta/*ta*/,iter/*iter*/,this);
        }
        
      }
      
    });
    
    !arrayProto/*arrayProto*/.every && defineBuiltin/*defineBuiltin*/(arrayProto/*arrayProto*/,"every",
    function (callback/*callback*/,that/*that*/) {
      callbackCheck/*callbackCheck*/(callback/*callback*/,"Array.every");
      
      var iter/*iter*/ = -1,
          ta/*ta*/;
      
      this === null && builtinTypeError/*builtinTypeError*/("Array.every : this is null or not defined");
      
      if (that/*that*/){
        while ((ta/*ta*/ = this[ ++ iter/*iter*/]) !== null && ta/*ta*/ !== undefined){
          if (!(callback/*callback*/.call(that/*that*/,ta/*ta*/,iter/*iter*/,this))){
            return false;
          }
          
        }
        
      } else {
        while ((ta/*ta*/ = this[ ++ iter/*iter*/]) !== null && ta/*ta*/ !== undefined){
          if (!(callback/*callback*/(ta/*ta*/,iter/*iter*/,this))){
            return false;
          }
          
        }
        
      }
      return true;
    });
    
    !arrayProto/*arrayProto*/.some && defineBuiltin/*defineBuiltin*/(arrayProto/*arrayProto*/,"some",
    function (callback/*callback*/,that/*that*/) {
      callbackCheck/*callbackCheck*/(callback/*callback*/,"Array.some");
      
      var iter/*iter*/ = -1,
          ta/*ta*/;
      
      this === null && builtinTypeError/*builtinTypeError*/("Array.some : this is null or not defined");
      
      if (that/*that*/){
        while ((ta/*ta*/ = this[ ++ iter/*iter*/]) !== null && ta/*ta*/ !== undefined){
          if (callback/*callback*/.call(that/*that*/,ta/*ta*/,iter/*iter*/,this)){
            return true;
          }
          
        }
        
      } else {
        while ((ta/*ta*/ = this[ ++ iter/*iter*/]) !== null && ta/*ta*/ !== undefined){
          if (callback/*callback*/(ta/*ta*/,iter/*iter*/,this)){
            return true;
          }
          
        }
        
      }
      return false;
    });
    
    !arrayProto/*arrayProto*/.filter && defineBuiltin/*defineBuiltin*/(arrayProto/*arrayProto*/,"filter",
    function (callback/*callback*/,that/*that*/) {
      callbackCheck/*callbackCheck*/(callback/*callback*/,"Array.filter");
      
      var len/*len*/ = this.length,
          iter/*iter*/ = -1,
          ret/*ret*/ = [],
          ta/*ta*/;
      
      this === null && builtinTypeError/*builtinTypeError*/("Array.filter : this is null or not defined");
      
      if (that/*that*/){
        for (var i/*i*/ = 0,len/*len*/ = this.length;i/*i*/<len/*len*/; ++ i/*i*/){
          
          (ta/*ta*/ = this[i/*i*/]) !== null && ta/*ta*/ !== undefined && callback/*callback*/.call(that/*that*/,ta/*ta*/,i/*i*/,this) && (ret/*ret*/[ ++ iter/*iter*/] = ta/*ta*/);
        }
        
      } else {
        for (var i/*i*/ = 0,len/*len*/ = this.length;i/*i*/<len/*len*/; ++ i/*i*/){
          
          (ta/*ta*/ = this[i/*i*/]) !== null && ta/*ta*/ !== undefined && callback/*callback*/(ta/*ta*/,i/*i*/,this) && (ret/*ret*/[ ++ iter/*iter*/] = ta/*ta*/);
        }
        
      }
      return ret/*ret*/;
    });
    
    !arrayProto/*arrayProto*/.indexOf && defineBuiltin/*defineBuiltin*/(arrayProto/*arrayProto*/,"indexOf",
    function (subject/*subject*/,fromIndex/*fromIndex*/) {
      var iter/*iter*/ = (fromIndex/*fromIndex*/)?fromIndex/*fromIndex*/-1 : -1,
          index/*index*/ = -1,
          ta/*ta*/;
      
      this === null && builtinTypeError/*builtinTypeError*/("Array.indexOf : this is null or not defined.");
      
      while ((ta/*ta*/ = this[ ++ iter/*iter*/]) !== null && ta/*ta*/ !== undefined){
        if (ta/*ta*/ === subject/*subject*/){
          
          index/*index*/ = iter/*iter*/;
          break;
        }
        
      }
      return index/*index*/;
    });
    
    !arrayProto/*arrayProto*/.lastIndexOf && defineBuiltin/*defineBuiltin*/(arrayProto/*arrayProto*/,"lastIndexOf",
    function (target/*target*/,fromIndex/*fromIndex*/) {
      var len/*len*/ = this.length,
          iter/*iter*/ = (fromIndex/*fromIndex*/)?fromIndex/*fromIndex*/+1 : len/*len*/,
          index/*index*/ = -1,
          ta/*ta*/;
      
      this === null && builtinTypeError/*builtinTypeError*/("Array.lastIndexOf : this is null or not defined.");
      
      while ((ta/*ta*/ = this[ -- iter/*iter*/]) !== null && ta/*ta*/ !== undefined){
        if (ta/*ta*/ === target/*target*/){
          
          index/*index*/ = iter/*iter*/;
          break;
        }
        
      }
      return index/*index*/;
    });
    
    !arrayProto/*arrayProto*/.map && defineBuiltin/*defineBuiltin*/(arrayProto/*arrayProto*/,"map",
    function (callback/*callback*/,that/*that*/) {
      callbackCheck/*callbackCheck*/(callback/*callback*/,"Array.map");
      
      var ret/*ret*/ = [],
          iter/*iter*/ = -1,
          len/*len*/ = this.length,
          i/*i*/ = 0,
          ta/*ta*/;
      
      this === null && builtinTypeError/*builtinTypeError*/("Array.map : this is null or not defined.");
      
      if (that/*that*/){
        for (i/*i*/;i/*i*/<len/*len*/; ++ i/*i*/){
          (ta/*ta*/ = this[i/*i*/]) !== null && ta/*ta*/ !== undefined && (ret/*ret*/[ ++ iter/*iter*/] = callback/*callback*/.call(that/*that*/,ta/*ta*/,i/*i*/,this));
        }
        
      } else {
        for (i/*i*/;i/*i*/<len/*len*/; ++ i/*i*/){
          (ta/*ta*/ = this[i/*i*/]) !== null && ta/*ta*/ !== undefined && (ret/*ret*/[ ++ iter/*iter*/] = callback/*callback*/(ta/*ta*/,i/*i*/,this));
        }
        
      }
      return ret/*ret*/;
    });
    
    !arrayProto/*arrayProto*/.reduce && defineBuiltin/*defineBuiltin*/(arrayProto/*arrayProto*/,"reduce",
    function (callback/*callback*/,initial/*initial*/) {
      callbackCheck/*callbackCheck*/(callback/*callback*/,"Array.reduce");
      
      var ret/*ret*/ = initial/*initial*/ || this[0],
          i/*i*/ = (initial/*initial*/)?0 : 1,
          len/*len*/ = this.length,
          ta/*ta*/;
      
      (len/*len*/ === 0 || len/*len*/ === null) && arguments.length<2 && builtinTypeError/*builtinTypeError*/("Array length is 0 and no second argument");
      
      for (i/*i*/;i/*i*/<len/*len*/; ++ i/*i*/){
        (ta/*ta*/ = this[i/*i*/]) !== null && ta/*ta*/ !== undefined && (ret/*ret*/ = callback/*callback*/(ret/*ret*/,ta/*ta*/,i/*i*/,this));
      }
      return ret/*ret*/;
    });
    
    !arrayProto/*arrayProto*/.reduceRight && defineBuiltin/*defineBuiltin*/(arrayProto/*arrayProto*/,"reduceRight",
    function (callback/*callback*/,initial/*initial*/) {
      callbackCheck/*callbackCheck*/(callback/*callback*/,"Array.reduceRight");
      
      var len/*len*/ = this.length,
          ret/*ret*/ = initial/*initial*/ || this[len/*len*/-1],
          i/*i*/ = (initial/*initial*/)?len/*len*/-1 : len/*len*/-2,
          ta/*ta*/;
      
      (len/*len*/ === 0 || len/*len*/ === null) && arguments.length<2 && builtinTypeError/*builtinTypeError*/("Array length is 0 and no second argument");
      
      for (i/*i*/;i/*i*/>-1; -- i/*i*/){
        (ta/*ta*/ = this[i/*i*/]) !== null && ta/*ta*/ !== undefined && (ret/*ret*/ = callback/*callback*/(ret/*ret*/,ta/*ta*/,i/*i*/,this));
      }
      return ret/*ret*/;
    });
    
    !dateProto/*dateProto*/.toJSON && defineBuiltin/*defineBuiltin*/(dateProto/*dateProto*/,"toJSON",
    function () {
      var _mochaLocalTmp4/*_mochaLocalTmp4*/ = [this.getUTCMonth(),this.getUTCDate(),this.getUTCHours(),this.getMinutes(),this.getSeconds()],
          month/*month*/ = _mochaLocalTmp4/*_mochaLocalTmp4*/[0],
          date/*date*/ = _mochaLocalTmp4/*_mochaLocalTmp4*/[1],
          hour/*hour*/ = _mochaLocalTmp4/*_mochaLocalTmp4*/[2],
          minute/*minute*/ = _mochaLocalTmp4/*_mochaLocalTmp4*/[3],
          second/*second*/ = _mochaLocalTmp4/*_mochaLocalTmp4*/[4];
      return '"'+this.getUTCFullYear()+'-'+(month/*month*/>8?month/*month*/+1 : "0"+(month/*month*/+1))+'-'+(date/*date*/>9?date/*date*/ : "0"+date/*date*/)+'T'+(hour/*hour*/>9?hour/*hour*/ : "0"+hour/*hour*/)+':'+(minute/*minute*/>9?minute/*minute*/ : "0"+minute/*minute*/)+':'+(second/*second*/>9?second/*second*/ : "0"+second/*second*/)+'.'+this.getUTCMilliseconds()+'Z"';
    });
    
    !Date.now && defineBuiltin/*defineBuiltin*/(Date,"now",
    function () {
      return +new Date();
    });
    
    !Array.isArray && defineBuiltin/*defineBuiltin*/(Array,"isArray",
    function (arr/*arr*/) {
      if (arguments.length === 0){
        return false;
      }
      return (arr/*arr*/)?({}).toString.call(arr/*arr*/) === "[object Array]" : false;
    });
  }.call(this,String,Array,Function,Date);
  
  var Runtime/*Runtime*/ = function () {
        function checkRequirements/*checkRequirements*/(_mochaLocalTmp9/*_mochaLocalTmp9*/,_mochaLocalTmp10/*_mochaLocalTmp10*/,traits/*traits*/,file/*file*/,line/*line*/) {
          var proto1/*proto1*/ = _mochaLocalTmp9/*_mochaLocalTmp9*/.prototype,
              proto2/*proto2*/ = _mochaLocalTmp10/*_mochaLocalTmp10*/.prototype;
          
          for (var i/*i*/ = 0,len/*len*/ = traits/*traits*/.length;i/*i*/<len/*len*/;i/*i*/ ++ ){
            
            var _mochaLocalTmp11/*_mochaLocalTmp11*/ = traits/*traits*/[i/*i*/],
                _mochaRequires/*_mochaRequires*/ = _mochaLocalTmp11/*_mochaLocalTmp11*/._mochaRequires;
            
            for (var prop/*prop*/ in _mochaRequires/*_mochaRequires*/){
              !(prop/*prop*/ in proto1/*proto1*/) && !(prop/*prop*/ in proto2/*proto2*/) && Runtime/*Runtime*/.throwException("Class dose not meet the traits requirement. traits require implementation of property "+prop/*prop*/+"\nin file "+file/*file*/+" at line "+line/*line*/);
            }
            
          }
          
        }
        function classMixin/*classMixin*/(_mochaLocalTmp6/*_mochaLocalTmp6*/,_mochaLocalTmp7/*_mochaLocalTmp7*/,_mochaLocalTmp8/*_mochaLocalTmp8*/,with_/*with_*/,without/*without*/) {
          var constructorProto/*constructorProto*/ = _mochaLocalTmp6/*_mochaLocalTmp6*/.prototype,
              privateProto/*privateProto*/ = _mochaLocalTmp7/*_mochaLocalTmp7*/.prototype,
              mark/*mark*/ = _mochaLocalTmp8/*_mochaLocalTmp8*/._mochaTraitMark,
              traitPublic/*traitPublic*/ = _mochaLocalTmp8/*_mochaLocalTmp8*/._mochaTraitPublic,
              traitPrivate/*traitPrivate*/ = _mochaLocalTmp8/*_mochaLocalTmp8*/._mochaTraitPrivate;
          
          if (!mark/*mark*/){
            Runtime/*Runtime*/.throwException("mixin only used for trait.");
          } else {
            
            var tmp/*tmp*/;
            
            for (var i/*i*/ in traitPublic/*traitPublic*/){
              if (!without/*without*/[i/*i*/]){
                
                tmp/*tmp*/ = (!with_/*with_*/[i/*i*/])?i/*i*/ : with_/*with_*/[i/*i*/];
                
                constructorProto/*constructorProto*/[tmp/*tmp*/] = traitPublic/*traitPublic*/[i/*i*/];
              }
              
            }
            
            for (i/*i*/ in traitPrivate/*traitPrivate*/){
              if (!without/*without*/[i/*i*/]){
                
                tmp/*tmp*/ = (!with_/*with_*/[i/*i*/])?i/*i*/ : with_/*with_*/[i/*i*/];
                
                privateProto/*privateProto*/[tmp/*tmp*/] = traitPrivate/*traitPrivate*/[i/*i*/];
              }
              
            }
            
          }
          
        }
        function traitMixin/*traitMixin*/(dest/*dest*/,source/*source*/,with_/*with_*/,without/*without*/) {
          if (!dest/*dest*/._mochaTraitMark || !source/*source*/._mochaTraitMark){
            Runtime/*Runtime*/.throwException("mixin only used for trait.");
          } else {
            
            var destTraitPrivate/*destTraitPrivate*/ = dest/*dest*/._mochaTraitPrivate,
                sourceTraitPrivate/*sourceTraitPrivate*/ = source/*source*/._mochaTraitPrivate,
                destTraitPublic/*destTraitPublic*/ = dest/*dest*/._mochaTraitPublic,
                sourceTraitPublic/*sourceTraitPublic*/ = source/*source*/._mochaTraitPublic,
                sourceRequires/*sourceRequires*/ = source/*source*/._mochaRequires,
                destRequires/*destRequires*/ = dest/*dest*/._mochaRequires,
                tmp/*tmp*/;
            
            for (var i/*i*/ in sourceTraitPrivate/*sourceTraitPrivate*/){
              if (!without/*without*/[i/*i*/]){
                
                tmp/*tmp*/ = (!with_/*with_*/[i/*i*/])?i/*i*/ : with_/*with_*/[i/*i*/];
                
                destTraitPrivate/*destTraitPrivate*/[tmp/*tmp*/] = sourceTraitPrivate/*sourceTraitPrivate*/[i/*i*/];
              }
              
            }
            
            for (i/*i*/ in sourceTraitPublic/*sourceTraitPublic*/){
              if (!without/*without*/[i/*i*/]){
                
                tmp/*tmp*/ = (!with_/*with_*/[i/*i*/])?i/*i*/ : with_/*with_*/[i/*i*/];
                
                destTraitPublic/*destTraitPublic*/[tmp/*tmp*/] = sourceTraitPublic/*sourceTraitPublic*/[i/*i*/];
              }
              
            }
            
            for (i/*i*/ in sourceRequires/*sourceRequires*/){
              destRequires/*destRequires*/[i/*i*/] = sourceRequires/*sourceRequires*/[i/*i*/];
            }
            
          }
          
        }
        function getSuper/*getSuper*/(obj/*obj*/) {
          var type/*type*/ = typeof obj/*obj*/,
              ret/*ret*/;
          
          if (type/*type*/ === "function"){
            
            ret/*ret*/ = function (){};
            
            ret/*ret*/.prototype = obj/*obj*/.prototype;
            
            ret/*ret*/ = new ret/*ret*/();
            
            obj/*obj*/.__harmony_class__?ret/*ret*/.constructor = obj/*obj*/.constructor : ret/*ret*/.constructor = obj/*obj*/;
            return ret/*ret*/;
          }
          return ret/*ret*/;
        }
        function initializeClass/*initializeClass*/(instance/*instance*/,classObject/*classObject*/,privateHolder/*privateHolder*/,constructor/*constructor*/,args/*args*/,name/*name*/,line/*line*/) {
          (!instance/*instance*/ || !(instance/*instance*/ instanceof classObject/*classObject*/)) && throwException/*throwException*/("class "+name/*name*/+" must be called by new. line : "+line/*line*/);
          
          createPrivateRecord/*createPrivateRecord*/(instance/*instance*/,privateHolder/*privateHolder*/);
          
          constructor/*constructor*/.apply(instance/*instance*/,args/*args*/);
        }
        function isStopIteration/*isStopIteration*/(obj/*obj*/) {
          return obj/*obj*/ === StopIteration || rstopIteration/*rstopIteration*/.test(obj/*obj*/);
        }
        function hasIterator/*hasIterator*/(obj/*obj*/) {
          return __ref_iterator__/*__ref_iterator__*/ in obj/*obj*/;
        }
        function getIterator/*getIterator*/(obj/*obj*/) {
          var ret/*ret*/ = obj/*obj*/[__ref_iterator__/*__ref_iterator__*/](),
              newObj/*newObj*/;
          
          if (isGenerator/*isGenerator*/(ret/*ret*/)){
            return ret/*ret*/;
          }
          
          newObj/*newObj*/ = {};
          
          if (ret/*ret*/.next){
            createUnenumProp/*createUnenumProp*/(newObj/*newObj*/,"next",
            function () {
              var result/*result*/ = ret/*ret*/.next();
              
              result/*result*/ === undefined && throwStopIteration/*throwStopIteration*/();
              return result/*result*/;
            });
          } else {
            return {};
          }
          
          !("__nothrowNext__" in ret/*ret*/) && createUnenumProp/*createUnenumProp*/(newObj/*newObj*/,"__nothrowNext__",ret/*ret*/.next.bind(ret/*ret*/));
          
          for (var prop/*prop*/ in ret/*ret*/){
            
            prop/*prop*/ !== "next" && prop/*prop*/ !== "__nothrowNext__" && (newObj/*newObj*/[prop/*prop*/] = ret/*ret*/[prop/*prop*/]);
          }
          
          !("toString" in ret/*ret*/) && createUnenumProp/*createUnenumProp*/(newObj/*newObj*/,"toString",
          function () {
            return "[object Iterator]";
          });
          return newObj/*newObj*/;
        }
        function isGenerator/*isGenerator*/(obj/*obj*/) {
          return obj/*obj*/ instanceof Generator/*Generator*/;
        }
        function throwStopIteration/*throwStopIteration*/() {
          try {
            throw StopIteration
            
          } catch(e){
            throw new Error(e.toString())
            
          }
          
        }
        function createRecord/*createRecord*/(obj/*obj*/) {
          obj/*obj*/.toString() === "[object Object]" && createUnenumProp/*createUnenumProp*/(obj/*obj*/,"toString",
          function () {
            return "[object Record]";
          });
          return Object.freeze(obj/*obj*/);
        }
        function createTuple/*createTuple*/(obj/*obj*/,size/*size*/) {
          createUnenumProp/*createUnenumProp*/(obj/*obj*/,"length",size/*size*/);
          
          createUnenumProp/*createUnenumProp*/(obj/*obj*/,"equal",compareTuple/*compareTuple*/);
          
          createUnenumProp/*createUnenumProp*/(obj/*obj*/,"toArray",tupleToArray/*tupleToArray*/);
          
          createUnenumProp/*createUnenumProp*/(obj/*obj*/,"toString",
          function () {
            return "[object Tuple]";
          });
          return Object.freeze(obj/*obj*/);
        }
        function tupleToArray/*tupleToArray*/() {
          return [].slice.call(this);
        }
        function compareTuple/*compareTuple*/(tuple/*tuple*/) {
          var maxIndex/*maxIndex*/ = max/*max*/(tuple/*tuple*/.length,this.length),
              i/*i*/ = -1;
          
          while ( ++ i/*i*/<maxIndex/*maxIndex*/ && tuple/*tuple*/[i/*i*/] === this[i/*i*/]){
            
          }
          return maxIndex/*maxIndex*/ === i/*i*/;
        }
        function extend/*extend*/(dest/*dest*/,source/*source*/) {
          for (var prop/*prop*/ in source/*source*/){
            
            dest/*dest*/[prop/*prop*/] = source/*source*/[prop/*prop*/];
          }
          return dest/*dest*/;
        }
        function getErrorMessage/*getErrorMessage*/(e/*e*/) {
          return (e/*e*/.message)?e/*e*/.message : (e/*e*/.description)?e/*e*/.description : e/*e*/.toString();
        }
        function createGenerator/*createGenerator*/(generatorFn/*generatorFn*/,closeFn/*closeFn*/,context/*context*/) {
          var ret/*ret*/ = new Generator/*Generator*/;
          
          createUnenumProp/*createUnenumProp*/(ret/*ret*/,"next",generatorFn/*generatorFn*/.bind(context/*context*/,false,false));
          
          createUnenumProp/*createUnenumProp*/(ret/*ret*/,"send",generatorFn/*generatorFn*/.bind(context/*context*/,true,false));
          
          createUnenumProp/*createUnenumProp*/(ret/*ret*/,"close",closeFn/*closeFn*/.bind(context/*context*/));
          
          createUnenumProp/*createUnenumProp*/(ret/*ret*/,"__nothrowNext__",generatorFn/*generatorFn*/.bind(context/*context*/,false,true));
          
          createUnenumProp/*createUnenumProp*/(ret/*ret*/,"toString",
          function () {
            return "[object Generator]";
          });
          
          Object.freeze(ret/*ret*/);
          return ret/*ret*/;
        }
        function Generator/*Generator*/(){}
        function toArray/*toArray*/(likeArray/*likeArray*/,index/*index*/) {
          return (likeArray/*likeArray*/)?slice/*slice*/.call(likeArray/*likeArray*/,index/*index*/) : [];
        }
        function constant/*constant*/(obj/*obj*/,prop/*prop*/,value/*value*/) {
          return Object.defineProperty(obj/*obj*/,prop/*prop*/, {
            configurable : false,
            enumerable : false,
            writable : false,
            value : value/*value*/
          });
        }
        function createUnenumProp/*createUnenumProp*/(obj/*obj*/,prop/*prop*/,value/*value*/) {
          return Object.defineProperty(obj/*obj*/,prop/*prop*/, {
            configurable : true,
            enumerable : false,
            writable : true,
            value : value/*value*/
          });
        }
        function Exception/*Exception*/(line/*line*/,file/*file*/,e/*e*/) {
          this.toString = function () {
            return Runtime/*Runtime*/.getErrorMessage(e/*e*/)+" in file "+file/*file*/+" at : "+line/*line*/;
          };
        }
        var _mochaLocalExport/*_mochaLocalExport*/ = {};
        
        var max/*max*/ = Math.max,
            _mochaLocalTmp5/*_mochaLocalTmp5*/ = Array.prototype,
            slice/*slice*/ = _mochaLocalTmp5/*_mochaLocalTmp5*/.slice,
            Runtime/*Runtime*/ =  {
              getErrorMessage : function (e/*e*/) {
                return (e/*e*/.message)?e/*e*/.message : (e/*e*/.description)?e/*e*/.description : e/*e*/.toString();
              },
              exceptionHandler : function (line/*line*/,file/*file*/,e/*e*/) {
                if (isStopIteration/*isStopIteration*/(e/*e*/)){
                  
                  this.throwException(e/*e*/);
                } else {
                  
                  this.throwException(new Exception/*Exception*/(line/*line*/,file/*file*/,e/*e*/));
                }
                
              },
              throwException : function (exception/*exception*/) {
                try {
                  throw exception/*exception*/
                  
                } catch(e){
                  
                  if (isStopIteration/*isStopIteration*/(e)){
                    throw new Error(e)
                    
                  } else {
                    throw new Error(this.getErrorMessage(e))
                    
                  }
                  
                }
                
              },
              hasProto : "__proto__" in {}
            };
        
        _mochaLocalExport/*_mochaLocalExport*/.createUnenumProp = createUnenumProp/*createUnenumProp*/;
        
        _mochaLocalExport/*_mochaLocalExport*/.constant = constant/*constant*/;
        
        _mochaLocalExport/*_mochaLocalExport*/.toArray = toArray/*toArray*/;
        
        _mochaLocalExport/*_mochaLocalExport*/.createGenerator = createGenerator/*createGenerator*/;
        
        var throwException/*throwException*/ = _mochaLocalExport/*_mochaLocalExport*/.throwException = Runtime/*Runtime*/.throwException.bind(Runtime/*Runtime*/),
            exceptionHandler/*exceptionHandler*/ = _mochaLocalExport/*_mochaLocalExport*/.exceptionHandler = Runtime/*Runtime*/.exceptionHandler.bind(Runtime/*Runtime*/);
        
        _mochaLocalExport/*_mochaLocalExport*/.extend = extend/*extend*/;
        
        _mochaLocalExport/*_mochaLocalExport*/.createTuple = createTuple/*createTuple*/;
        
        _mochaLocalExport/*_mochaLocalExport*/.createRecord = createRecord/*createRecord*/;
        
        var extendPrototype/*extendPrototype*/ = _mochaLocalExport/*_mochaLocalExport*/.extendPrototype = function (derived/*derived*/,base/*base*/) {
              derived/*derived*/.prototype = base/*base*/;
            },
            getPrototype/*getPrototype*/ = ("getPrototypeOf" in Object)?function (obj/*obj*/) {
              return Object.getPrototypeOf(obj/*obj*/);
            } : function (obj/*obj*/) {
              var ret/*ret*/ = {};
              
              for (var i/*i*/ in obj/*obj*/){
                
                !obj/*obj*/.hasOwnProperty(i/*i*/) && (ret/*ret*/[i/*i*/] = obj/*obj*/[i/*i*/]);
              }
              return ret/*ret*/;
            },
            extendClass/*extendClass*/ = _mochaLocalExport/*_mochaLocalExport*/.extendClass = (Runtime/*Runtime*/.hasProto)?function (derived/*derived*/,base/*base*/) {
              if (typeof base/*base*/ === 'function'){
                
                derived/*derived*/.prototype.__proto__ = base/*base*/.prototype;
                
                for (var i/*i*/ in base/*base*/){
                  derived/*derived*/[i/*i*/] = base/*base*/[i/*i*/];
                }
                
              } else {
                derived/*derived*/.prototype.__proto__ = base/*base*/.__proto__;
              }
              
            } : function (derived/*derived*/,base/*base*/) {
              var baseType/*baseType*/ = typeof base/*base*/;
              
              if (baseType/*baseType*/ === "function"){
                
                var inherit/*inherit*/ = function (){};
                
                inherit/*inherit*/.prototype = base/*base*/.prototype;
                
                derived/*derived*/.prototype = new inherit/*inherit*/;
                
                for (var i/*i*/ in base/*base*/){
                  derived/*derived*/[i/*i*/] = base/*base*/[i/*i*/];
                }
                
              } else {
                
                var inherit/*inherit*/ = function (){},
                    proto/*proto*/ = getPrototype/*getPrototype*/(base/*base*/);
                
                inherit/*inherit*/.prototype = proto/*proto*/;
                
                derived/*derived*/.prototype = new inherit/*inherit*/;
              }
              
            },
            __ref_iterator__/*__ref_iterator__*/ = _mochaLocalExport/*_mochaLocalExport*/.__ref_iterator__ = "__mocha_iterator_special_key__";
        
        _mochaLocalExport/*_mochaLocalExport*/.throwStopIteration = throwStopIteration/*throwStopIteration*/;
        
        _mochaLocalExport/*_mochaLocalExport*/.isGenerator = isGenerator/*isGenerator*/;
        
        _mochaLocalExport/*_mochaLocalExport*/.getIterator = getIterator/*getIterator*/;
        
        _mochaLocalExport/*_mochaLocalExport*/.hasIterator = hasIterator/*hasIterator*/;
        
        var rstopIteration/*rstopIteration*/ = /StopIteration/;
        
        _mochaLocalExport/*_mochaLocalExport*/.isStopIteration = isStopIteration/*isStopIteration*/;
        
        var privateRecord/*privateRecord*/,
            createPrivateRecord/*createPrivateRecord*/,
            getPrivateRecord/*getPrivateRecord*/;
        
        if ("WeakMap" in window){
          
          privateRecord/*privateRecord*/ = new WeakMap();
          
          createPrivateRecord/*createPrivateRecord*/ = function (self,privateHolder/*privateHolder*/) {
            var holder/*holder*/ = new privateHolder/*privateHolder*/;
            
            createUnenumProp/*createUnenumProp*/(holder/*holder*/.constructor,"__is_private__",1);
            
            privateRecord/*privateRecord*/.set(self,holder/*holder*/);
          };
          
          getPrivateRecord/*getPrivateRecord*/ = function (self) {
            if (privateRecord/*privateRecord*/.has(self)){
              return privateRecord/*privateRecord*/.get(self);
            } else if (self.constructor === "__is_private__"){
              return self;
            }
            
          };
        } else {
          
          createPrivateRecord/*createPrivateRecord*/ = function (self,privateHolder/*privateHolder*/) {
            if (!self.__typeid__){
              
              var holder/*holder*/ = new privateHolder/*privateHolder*/;
              
              createUnenumProp/*createUnenumProp*/(holder/*holder*/.constructor,"__is_private__",1);
              
              createUnenumProp/*createUnenumProp*/(self,"__private__",holder/*holder*/);
            }
            
          };
          
          getPrivateRecord/*getPrivateRecord*/ = function (self) {
            if (self.__private__){
              return self.__private__;
            } else if (self.constructor === "__is_private__"){
              return self;
            }
            
          };
        }
        
        _mochaLocalExport/*_mochaLocalExport*/.getPrivateRecord = getPrivateRecord/*getPrivateRecord*/;
        
        _mochaLocalExport/*_mochaLocalExport*/.initializeClass = initializeClass/*initializeClass*/;
        
        _mochaLocalExport/*_mochaLocalExport*/.getSuper = getSuper/*getSuper*/;
        
        _mochaLocalExport/*_mochaLocalExport*/.traitMixin = traitMixin/*traitMixin*/;
        
        _mochaLocalExport/*_mochaLocalExport*/.classMixin = classMixin/*classMixin*/;
        
        _mochaLocalExport/*_mochaLocalExport*/.checkRequirements = checkRequirements/*checkRequirements*/;
        
        !function () {
          var assert/*assert*/ = _mochaLocalExport/*_mochaLocalExport*/.assert = (console && console.assert)?function (expect/*expect*/,exp/*exp*/,str/*str*/,line/*line*/,filename/*filename*/) {
                return console.assert(expect/*expect*/ === exp/*exp*/,"assertion failed : "+str/*str*/+"\nexpect "+expect/*expect*/+" but got "+exp/*exp*/+"\nin file "+filename/*filename*/+" at : "+line/*line*/);
              } : function (expect/*expect*/,exp/*exp*/,str/*str*/,line/*line*/,filename/*filename*/) {
                expect/*expect*/ !== exp/*exp*/ && Runtime/*Runtime*/.throwException("assertion failed : "+str/*str*/+"\nexpect "+expect/*expect*/+" but got "+exp/*exp*/+"\nin file "+filename/*filename*/+" at : "+line/*line*/);
              };
        }.call(this);
        return _mochaLocalExport/*_mochaLocalExport*/;
      }();
  
  !("StopIteration" in window) && (window.StopIteration =  {
    toString : function () {
      return "[object StopIteration]";
    }
  });
  
  function Tuple/*Tuple*/() {
    var args/*args*/ = Runtime/*Runtime*/.toArray(arguments,0),
        ret/*ret*/ = {};
    
    ret/*ret*/.length = 0;
    
    [].push.apply(ret/*ret*/,args/*args*/);
    
    Runtime/*Runtime*/.createTuple(ret/*ret*/,arguments.length);
    return ret/*ret*/;
  }
  function Record/*Record*/(member/*member*/) {
    return Runtime/*Runtime*/.createRecord(member/*member*/);
  }
  __LINE__ = 2;
  !function () {
    try {
      var __FILE__ = "iterators",
          __LINE__ = 0;
      __LINE__ = 2;
      _mochaGlobalExport/*_mochaGlobalExport*/.iterators = {};
      
      __LINE__ = 2;
      var _mochaGlobalAlias/*_mochaGlobalAlias*/ = _mochaGlobalExport/*_mochaGlobalExport*/.iterators;
      
      __LINE__ = 0;
      !function () {
        try {
          function allItems/*allItems*/(obj/*obj*/) {
            try {
              __LINE__ = 54;
              var _mochaLocalTmp23/*_mochaLocalTmp23*/ = {};
              
              __LINE__ = 54;
              Runtime/*Runtime*/.createUnenumProp(_mochaLocalTmp23/*_mochaLocalTmp23*/,iterator/*iterator*/,
              function () {
                try {
                  __LINE__ = 54;
                  return function () {
                    try {
                      __LINE__ = 54;
                      var _mochaIsNewBorn/*_mochaIsNewBorn*/ = true,
                          _yieldResult/*_yieldResult*/ = undefined,
                          _yieldState/*_yieldState*/ = 0,
                          length/*length*/,
                          _mochaLocalTmp22/*_mochaLocalTmp22*/,
                          x/*x*/,
                          _mochaLocalTmp21/*_mochaLocalTmp21*/ = [],
                          _mochaGenerator/*_mochaGenerator*/ = function (_isYieldSend/*_isYieldSend*/,_isYieldSafe/*_isYieldSafe*/) {
                            try {
                              __LINE__ = 54;
                              !_isYieldSend/*_isYieldSend*/?_mochaIsNewBorn/*_mochaIsNewBorn*/ = false : _isYieldSend/*_isYieldSend*/ && _mochaIsNewBorn/*_mochaIsNewBorn*/ && arguments[1] !== undefined && Runtime/*Runtime*/.exceptionHandler('attempt to send to newborn generator.');
                              
                              __LINE__ = 54;
                              while (1){
                                
                                __LINE__ = 54;
                                switch (_yieldState/*_yieldState*/) {
                                  case 0 :
                                    
                                    __LINE__ = 54;
                                    for (var _mochaLocalTmp20/*_mochaLocalTmp20*/ in obj/*obj*/){
                                      
                                      __LINE__ = 54;
                                      _mochaLocalTmp21/*_mochaLocalTmp21*/.push(_mochaLocalTmp20/*_mochaLocalTmp20*/);
                                    }
                                    
                                    __LINE__ = 54;
                                    _mochaLocalTmp22/*_mochaLocalTmp22*/ = 0;
                                    
                                    __LINE__ = 54;
                                    length/*length*/ = _mochaLocalTmp21/*_mochaLocalTmp21*/.length;
                                    
                                    __LINE__ = 54;
                                    if (!(_mochaLocalTmp22/*_mochaLocalTmp22*/<length/*length*/)){
                                      
                                      __LINE__ = 54;
                                      _yieldState/*_yieldState*/ = -1;
                                      __LINE__ = 54;
                                      break;
                                    }
                                  case 1 :
                                    
                                    __LINE__ = 56;
                                    _yieldState/*_yieldState*/ = 2;
                                    
                                    __LINE__ = 54;
                                    x/*x*/ = _mochaLocalTmp21/*_mochaLocalTmp21*/[_mochaLocalTmp22/*_mochaLocalTmp22*/];
                                    __LINE__ = 56;
                                    return [x/*x*/,obj/*obj*/[x/*x*/]];
                                  case 2 :
                                    
                                    __LINE__ = 54;
                                     ++ _mochaLocalTmp22/*_mochaLocalTmp22*/;
                                    
                                    __LINE__ = 54;
                                    if (_mochaLocalTmp22/*_mochaLocalTmp22*/<length/*length*/){
                                      
                                      __LINE__ = 2;
                                      _yieldState/*_yieldState*/ = 1;
                                      __LINE__ = 54;
                                      break;
                                    } else {
                                      __LINE__ = 2;
                                      _yieldState/*_yieldState*/ = -1;
                                    }
                                  case -1 :
                                    
                                    __LINE__ = 54;
                                    if (_isYieldSafe/*_isYieldSafe*/){
                                      __LINE__ = 54;
                                      return undefined;
                                    }
                                    
                                    __LINE__ = 54;
                                    Runtime/*Runtime*/.throwStopIteration();
                                    
                                }
                                
                              }
                              
                            } catch(e){
                              Runtime.exceptionHandler(__LINE__, __FILE__, e);
                            }
                          };
                      __LINE__ = 54;
                      return Runtime/*Runtime*/.createGenerator(_mochaGenerator/*_mochaGenerator*/,
                      function () {
                        try {
                          __LINE__ = 54;
                          _yieldState/*_yieldState*/ = -1;
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
              return _mochaLocalTmp23/*_mochaLocalTmp23*/;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          }
          function allValues/*allValues*/(obj/*obj*/) {
            try {
              __LINE__ = 46;
              var _mochaLocalTmp19/*_mochaLocalTmp19*/ = {};
              
              __LINE__ = 46;
              Runtime/*Runtime*/.createUnenumProp(_mochaLocalTmp19/*_mochaLocalTmp19*/,iterator/*iterator*/,
              function () {
                try {
                  __LINE__ = 46;
                  return function () {
                    try {
                      __LINE__ = 46;
                      var _mochaIsNewBorn/*_mochaIsNewBorn*/ = true,
                          _yieldResult/*_yieldResult*/ = undefined,
                          _yieldState/*_yieldState*/ = 0,
                          length/*length*/,
                          _mochaLocalTmp18/*_mochaLocalTmp18*/,
                          x/*x*/,
                          _mochaLocalTmp17/*_mochaLocalTmp17*/ = [],
                          _mochaGenerator/*_mochaGenerator*/ = function (_isYieldSend/*_isYieldSend*/,_isYieldSafe/*_isYieldSafe*/) {
                            try {
                              __LINE__ = 46;
                              !_isYieldSend/*_isYieldSend*/?_mochaIsNewBorn/*_mochaIsNewBorn*/ = false : _isYieldSend/*_isYieldSend*/ && _mochaIsNewBorn/*_mochaIsNewBorn*/ && arguments[1] !== undefined && Runtime/*Runtime*/.exceptionHandler('attempt to send to newborn generator.');
                              
                              __LINE__ = 46;
                              while (1){
                                
                                __LINE__ = 46;
                                switch (_yieldState/*_yieldState*/) {
                                  case 0 :
                                    
                                    __LINE__ = 46;
                                    for (var _mochaLocalTmp16/*_mochaLocalTmp16*/ in obj/*obj*/){
                                      
                                      __LINE__ = 46;
                                      _mochaLocalTmp17/*_mochaLocalTmp17*/.push(_mochaLocalTmp16/*_mochaLocalTmp16*/);
                                    }
                                    
                                    __LINE__ = 46;
                                    _mochaLocalTmp18/*_mochaLocalTmp18*/ = 0;
                                    
                                    __LINE__ = 46;
                                    length/*length*/ = _mochaLocalTmp17/*_mochaLocalTmp17*/.length;
                                    
                                    __LINE__ = 46;
                                    if (!(_mochaLocalTmp18/*_mochaLocalTmp18*/<length/*length*/)){
                                      
                                      __LINE__ = 46;
                                      _yieldState/*_yieldState*/ = -1;
                                      __LINE__ = 46;
                                      break;
                                    }
                                  case 1 :
                                    
                                    __LINE__ = 48;
                                    _yieldState/*_yieldState*/ = 2;
                                    
                                    __LINE__ = 46;
                                    x/*x*/ = _mochaLocalTmp17/*_mochaLocalTmp17*/[_mochaLocalTmp18/*_mochaLocalTmp18*/];
                                    __LINE__ = 48;
                                    return obj/*obj*/[x/*x*/];
                                  case 2 :
                                    
                                    __LINE__ = 46;
                                     ++ _mochaLocalTmp18/*_mochaLocalTmp18*/;
                                    
                                    __LINE__ = 46;
                                    if (_mochaLocalTmp18/*_mochaLocalTmp18*/<length/*length*/){
                                      
                                      __LINE__ = 2;
                                      _yieldState/*_yieldState*/ = 1;
                                      __LINE__ = 46;
                                      break;
                                    } else {
                                      __LINE__ = 2;
                                      _yieldState/*_yieldState*/ = -1;
                                    }
                                  case -1 :
                                    
                                    __LINE__ = 46;
                                    if (_isYieldSafe/*_isYieldSafe*/){
                                      __LINE__ = 46;
                                      return undefined;
                                    }
                                    
                                    __LINE__ = 46;
                                    Runtime/*Runtime*/.throwStopIteration();
                                    
                                }
                                
                              }
                              
                            } catch(e){
                              Runtime.exceptionHandler(__LINE__, __FILE__, e);
                            }
                          };
                      __LINE__ = 46;
                      return Runtime/*Runtime*/.createGenerator(_mochaGenerator/*_mochaGenerator*/,
                      function () {
                        try {
                          __LINE__ = 46;
                          _yieldState/*_yieldState*/ = -1;
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
              return _mochaLocalTmp19/*_mochaLocalTmp19*/;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          }
          function allKeys/*allKeys*/(obj/*obj*/) {
            try {
              __LINE__ = 38;
              var _mochaLocalTmp15/*_mochaLocalTmp15*/ = {};
              
              __LINE__ = 38;
              Runtime/*Runtime*/.createUnenumProp(_mochaLocalTmp15/*_mochaLocalTmp15*/,iterator/*iterator*/,
              function () {
                try {
                  __LINE__ = 38;
                  return function () {
                    try {
                      __LINE__ = 38;
                      var _mochaIsNewBorn/*_mochaIsNewBorn*/ = true,
                          _yieldResult/*_yieldResult*/ = undefined,
                          _yieldState/*_yieldState*/ = 0,
                          length/*length*/,
                          _mochaLocalTmp14/*_mochaLocalTmp14*/,
                          x/*x*/,
                          _mochaLocalTmp13/*_mochaLocalTmp13*/ = [],
                          _mochaGenerator/*_mochaGenerator*/ = function (_isYieldSend/*_isYieldSend*/,_isYieldSafe/*_isYieldSafe*/) {
                            try {
                              __LINE__ = 38;
                              !_isYieldSend/*_isYieldSend*/?_mochaIsNewBorn/*_mochaIsNewBorn*/ = false : _isYieldSend/*_isYieldSend*/ && _mochaIsNewBorn/*_mochaIsNewBorn*/ && arguments[1] !== undefined && Runtime/*Runtime*/.exceptionHandler('attempt to send to newborn generator.');
                              
                              __LINE__ = 38;
                              while (1){
                                
                                __LINE__ = 38;
                                switch (_yieldState/*_yieldState*/) {
                                  case 0 :
                                    
                                    __LINE__ = 38;
                                    for (var _mochaLocalTmp12/*_mochaLocalTmp12*/ in obj/*obj*/){
                                      
                                      __LINE__ = 38;
                                      _mochaLocalTmp13/*_mochaLocalTmp13*/.push(_mochaLocalTmp12/*_mochaLocalTmp12*/);
                                    }
                                    
                                    __LINE__ = 38;
                                    _mochaLocalTmp14/*_mochaLocalTmp14*/ = 0;
                                    
                                    __LINE__ = 38;
                                    length/*length*/ = _mochaLocalTmp13/*_mochaLocalTmp13*/.length;
                                    
                                    __LINE__ = 38;
                                    if (!(_mochaLocalTmp14/*_mochaLocalTmp14*/<length/*length*/)){
                                      
                                      __LINE__ = 38;
                                      _yieldState/*_yieldState*/ = -1;
                                      __LINE__ = 38;
                                      break;
                                    }
                                  case 1 :
                                    
                                    __LINE__ = 40;
                                    _yieldState/*_yieldState*/ = 2;
                                    
                                    __LINE__ = 38;
                                    x/*x*/ = _mochaLocalTmp13/*_mochaLocalTmp13*/[_mochaLocalTmp14/*_mochaLocalTmp14*/];
                                    __LINE__ = 40;
                                    return x/*x*/;
                                  case 2 :
                                    
                                    __LINE__ = 38;
                                     ++ _mochaLocalTmp14/*_mochaLocalTmp14*/;
                                    
                                    __LINE__ = 38;
                                    if (_mochaLocalTmp14/*_mochaLocalTmp14*/<length/*length*/){
                                      
                                      __LINE__ = 2;
                                      _yieldState/*_yieldState*/ = 1;
                                      __LINE__ = 38;
                                      break;
                                    } else {
                                      __LINE__ = 2;
                                      _yieldState/*_yieldState*/ = -1;
                                    }
                                  case -1 :
                                    
                                    __LINE__ = 38;
                                    if (_isYieldSafe/*_isYieldSafe*/){
                                      __LINE__ = 38;
                                      return undefined;
                                    }
                                    
                                    __LINE__ = 38;
                                    Runtime/*Runtime*/.throwStopIteration();
                                    
                                }
                                
                              }
                              
                            } catch(e){
                              Runtime.exceptionHandler(__LINE__, __FILE__, e);
                            }
                          };
                      __LINE__ = 38;
                      return Runtime/*Runtime*/.createGenerator(_mochaGenerator/*_mochaGenerator*/,
                      function () {
                        try {
                          __LINE__ = 38;
                          _yieldState/*_yieldState*/ = -1;
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
              return _mochaLocalTmp15/*_mochaLocalTmp15*/;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          }
          function items/*items*/(obj/*obj*/) {
            try {
              __LINE__ = 28;
              var _mochaLocalTmp11/*_mochaLocalTmp11*/ = {};
              
              __LINE__ = 28;
              Runtime/*Runtime*/.createUnenumProp(_mochaLocalTmp11/*_mochaLocalTmp11*/,iterator/*iterator*/,
              function () {
                try {
                  __LINE__ = 28;
                  return function () {
                    try {
                      __LINE__ = 28;
                      var _mochaIsNewBorn/*_mochaIsNewBorn*/ = true,
                          _yieldResult/*_yieldResult*/ = undefined,
                          _yieldState/*_yieldState*/ = 0,
                          length/*length*/,
                          _mochaLocalTmp10/*_mochaLocalTmp10*/,
                          x/*x*/,
                          _mochaLocalTmp9/*_mochaLocalTmp9*/ = [],
                          _mochaGenerator/*_mochaGenerator*/ = function (_isYieldSend/*_isYieldSend*/,_isYieldSafe/*_isYieldSafe*/) {
                            try {
                              __LINE__ = 28;
                              !_isYieldSend/*_isYieldSend*/?_mochaIsNewBorn/*_mochaIsNewBorn*/ = false : _isYieldSend/*_isYieldSend*/ && _mochaIsNewBorn/*_mochaIsNewBorn*/ && arguments[1] !== undefined && Runtime/*Runtime*/.exceptionHandler('attempt to send to newborn generator.');
                              
                              __LINE__ = 28;
                              while (1){
                                
                                __LINE__ = 28;
                                switch (_yieldState/*_yieldState*/) {
                                  case 0 :
                                    
                                    __LINE__ = 28;
                                    for (var _mochaLocalTmp8/*_mochaLocalTmp8*/ in obj/*obj*/){
                                      
                                      __LINE__ = 28;
                                      _mochaLocalTmp9/*_mochaLocalTmp9*/.push(_mochaLocalTmp8/*_mochaLocalTmp8*/);
                                    }
                                    
                                    __LINE__ = 28;
                                    _mochaLocalTmp10/*_mochaLocalTmp10*/ = 0;
                                    
                                    __LINE__ = 28;
                                    length/*length*/ = _mochaLocalTmp9/*_mochaLocalTmp9*/.length;
                                    
                                    __LINE__ = 28;
                                    if (!(_mochaLocalTmp10/*_mochaLocalTmp10*/<length/*length*/)){
                                      
                                      __LINE__ = 28;
                                      _yieldState/*_yieldState*/ = -1;
                                      __LINE__ = 28;
                                      break;
                                    }
                                  case 1 :
                                    
                                    __LINE__ = 28;
                                    x/*x*/ = _mochaLocalTmp9/*_mochaLocalTmp9*/[_mochaLocalTmp10/*_mochaLocalTmp10*/];
                                    
                                    __LINE__ = 30;
                                    if (hasOwn/*hasOwn*/.call(obj/*obj*/,x/*x*/)){
                                      
                                      __LINE__ = 30;
                                      _yieldState/*_yieldState*/ = 2;
                                      __LINE__ = 30;
                                      break;
                                    } else {
                                      
                                      __LINE__ = 30;
                                      _yieldState/*_yieldState*/ = 3;
                                      __LINE__ = 30;
                                      break;
                                    }
                                  case 2 :
                                    
                                    __LINE__ = 30;
                                    _yieldState/*_yieldState*/ = 3;
                                    __LINE__ = 30;
                                    return [x/*x*/,obj/*obj*/[x/*x*/]];
                                  case 3 :
                                    
                                    __LINE__ = 30;
                                    _yieldState/*_yieldState*/ = 4;
                                    __LINE__ = 30;
                                    break;
                                  case 4 :
                                    
                                    __LINE__ = 28;
                                     ++ _mochaLocalTmp10/*_mochaLocalTmp10*/;
                                    
                                    __LINE__ = 28;
                                    if (_mochaLocalTmp10/*_mochaLocalTmp10*/<length/*length*/){
                                      
                                      __LINE__ = 2;
                                      _yieldState/*_yieldState*/ = 1;
                                      __LINE__ = 28;
                                      break;
                                    } else {
                                      __LINE__ = 2;
                                      _yieldState/*_yieldState*/ = -1;
                                    }
                                  case -1 :
                                    
                                    __LINE__ = 28;
                                    if (_isYieldSafe/*_isYieldSafe*/){
                                      __LINE__ = 28;
                                      return undefined;
                                    }
                                    
                                    __LINE__ = 28;
                                    Runtime/*Runtime*/.throwStopIteration();
                                    
                                }
                                
                              }
                              
                            } catch(e){
                              Runtime.exceptionHandler(__LINE__, __FILE__, e);
                            }
                          };
                      __LINE__ = 28;
                      return Runtime/*Runtime*/.createGenerator(_mochaGenerator/*_mochaGenerator*/,
                      function () {
                        try {
                          __LINE__ = 28;
                          _yieldState/*_yieldState*/ = -1;
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
              return _mochaLocalTmp11/*_mochaLocalTmp11*/;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          }
          function values/*values*/(obj/*obj*/) {
            try {
              __LINE__ = 16;
              var _mochaLocalTmp7/*_mochaLocalTmp7*/ = {};
              
              __LINE__ = 16;
              Runtime/*Runtime*/.createUnenumProp(_mochaLocalTmp7/*_mochaLocalTmp7*/,iterator/*iterator*/,
              function () {
                try {
                  __LINE__ = 16;
                  return function () {
                    try {
                      __LINE__ = 16;
                      var _mochaIsNewBorn/*_mochaIsNewBorn*/ = true,
                          _yieldResult/*_yieldResult*/ = undefined,
                          _yieldState/*_yieldState*/ = 0,
                          length/*length*/,
                          _mochaLocalTmp6/*_mochaLocalTmp6*/,
                          x/*x*/,
                          _mochaLocalTmp5/*_mochaLocalTmp5*/ = [],
                          _mochaGenerator/*_mochaGenerator*/ = function (_isYieldSend/*_isYieldSend*/,_isYieldSafe/*_isYieldSafe*/) {
                            try {
                              __LINE__ = 16;
                              !_isYieldSend/*_isYieldSend*/?_mochaIsNewBorn/*_mochaIsNewBorn*/ = false : _isYieldSend/*_isYieldSend*/ && _mochaIsNewBorn/*_mochaIsNewBorn*/ && arguments[1] !== undefined && Runtime/*Runtime*/.exceptionHandler('attempt to send to newborn generator.');
                              
                              __LINE__ = 16;
                              while (1){
                                
                                __LINE__ = 16;
                                switch (_yieldState/*_yieldState*/) {
                                  case 0 :
                                    
                                    __LINE__ = 18;
                                    for (var _mochaLocalTmp4/*_mochaLocalTmp4*/ in obj/*obj*/){
                                      
                                      __LINE__ = 18;
                                      _mochaLocalTmp5/*_mochaLocalTmp5*/.push(_mochaLocalTmp4/*_mochaLocalTmp4*/);
                                    }
                                    
                                    __LINE__ = 18;
                                    _mochaLocalTmp6/*_mochaLocalTmp6*/ = 0;
                                    
                                    __LINE__ = 18;
                                    length/*length*/ = _mochaLocalTmp5/*_mochaLocalTmp5*/.length;
                                    
                                    __LINE__ = 18;
                                    if (!(_mochaLocalTmp6/*_mochaLocalTmp6*/<length/*length*/)){
                                      
                                      __LINE__ = 18;
                                      _yieldState/*_yieldState*/ = -1;
                                      __LINE__ = 18;
                                      break;
                                    }
                                  case 1 :
                                    
                                    __LINE__ = 18;
                                    x/*x*/ = _mochaLocalTmp5/*_mochaLocalTmp5*/[_mochaLocalTmp6/*_mochaLocalTmp6*/];
                                    
                                    __LINE__ = 18;
                                    if (hasOwn/*hasOwn*/.call(obj/*obj*/,x/*x*/)){
                                      
                                      __LINE__ = 18;
                                      _yieldState/*_yieldState*/ = 2;
                                      __LINE__ = 18;
                                      break;
                                    } else {
                                      
                                      __LINE__ = 18;
                                      _yieldState/*_yieldState*/ = 3;
                                      __LINE__ = 18;
                                      break;
                                    }
                                  case 2 :
                                    
                                    __LINE__ = 20;
                                    _yieldState/*_yieldState*/ = 3;
                                    __LINE__ = 20;
                                    return obj/*obj*/[x/*x*/];
                                  case 3 :
                                    
                                    __LINE__ = 18;
                                    _yieldState/*_yieldState*/ = 4;
                                    __LINE__ = 18;
                                    break;
                                  case 4 :
                                    
                                    __LINE__ = 18;
                                     ++ _mochaLocalTmp6/*_mochaLocalTmp6*/;
                                    
                                    __LINE__ = 18;
                                    if (_mochaLocalTmp6/*_mochaLocalTmp6*/<length/*length*/){
                                      
                                      __LINE__ = 2;
                                      _yieldState/*_yieldState*/ = 1;
                                      __LINE__ = 18;
                                      break;
                                    } else {
                                      __LINE__ = 2;
                                      _yieldState/*_yieldState*/ = -1;
                                    }
                                  case -1 :
                                    
                                    __LINE__ = 16;
                                    if (_isYieldSafe/*_isYieldSafe*/){
                                      __LINE__ = 16;
                                      return undefined;
                                    }
                                    
                                    __LINE__ = 16;
                                    Runtime/*Runtime*/.throwStopIteration();
                                    
                                }
                                
                              }
                              
                            } catch(e){
                              Runtime.exceptionHandler(__LINE__, __FILE__, e);
                            }
                          };
                      __LINE__ = 16;
                      return Runtime/*Runtime*/.createGenerator(_mochaGenerator/*_mochaGenerator*/,
                      function () {
                        try {
                          __LINE__ = 16;
                          _yieldState/*_yieldState*/ = -1;
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
              return _mochaLocalTmp7/*_mochaLocalTmp7*/;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          }
          function keys/*keys*/(obj/*obj*/) {
            try {
              __LINE__ = 6;
              var _mochaLocalTmp3/*_mochaLocalTmp3*/ = {};
              
              __LINE__ = 6;
              Runtime/*Runtime*/.createUnenumProp(_mochaLocalTmp3/*_mochaLocalTmp3*/,iterator/*iterator*/,
              function () {
                try {
                  __LINE__ = 6;
                  return function () {
                    try {
                      __LINE__ = 6;
                      var _mochaIsNewBorn/*_mochaIsNewBorn*/ = true,
                          _yieldResult/*_yieldResult*/ = undefined,
                          _yieldState/*_yieldState*/ = 0,
                          length/*length*/,
                          _mochaLocalTmp2/*_mochaLocalTmp2*/,
                          x/*x*/,
                          _mochaLocalTmp1/*_mochaLocalTmp1*/ = [],
                          _mochaGenerator/*_mochaGenerator*/ = function (_isYieldSend/*_isYieldSend*/,_isYieldSafe/*_isYieldSafe*/) {
                            try {
                              __LINE__ = 6;
                              !_isYieldSend/*_isYieldSend*/?_mochaIsNewBorn/*_mochaIsNewBorn*/ = false : _isYieldSend/*_isYieldSend*/ && _mochaIsNewBorn/*_mochaIsNewBorn*/ && arguments[1] !== undefined && Runtime/*Runtime*/.exceptionHandler('attempt to send to newborn generator.');
                              
                              __LINE__ = 6;
                              while (1){
                                
                                __LINE__ = 6;
                                switch (_yieldState/*_yieldState*/) {
                                  case 0 :
                                    
                                    __LINE__ = 6;
                                    for (var _mochaLocalTmp0/*_mochaLocalTmp0*/ in obj/*obj*/){
                                      
                                      __LINE__ = 6;
                                      _mochaLocalTmp1/*_mochaLocalTmp1*/.push(_mochaLocalTmp0/*_mochaLocalTmp0*/);
                                    }
                                    
                                    __LINE__ = 6;
                                    _mochaLocalTmp2/*_mochaLocalTmp2*/ = 0;
                                    
                                    __LINE__ = 6;
                                    length/*length*/ = _mochaLocalTmp1/*_mochaLocalTmp1*/.length;
                                    
                                    __LINE__ = 6;
                                    if (!(_mochaLocalTmp2/*_mochaLocalTmp2*/<length/*length*/)){
                                      
                                      __LINE__ = 6;
                                      _yieldState/*_yieldState*/ = -1;
                                      __LINE__ = 6;
                                      break;
                                    }
                                  case 1 :
                                    
                                    __LINE__ = 6;
                                    x/*x*/ = _mochaLocalTmp1/*_mochaLocalTmp1*/[_mochaLocalTmp2/*_mochaLocalTmp2*/];
                                    
                                    __LINE__ = 8;
                                    if (hasOwn/*hasOwn*/.call(obj/*obj*/,x/*x*/)){
                                      
                                      __LINE__ = 8;
                                      _yieldState/*_yieldState*/ = 2;
                                      __LINE__ = 8;
                                      break;
                                    } else {
                                      
                                      __LINE__ = 8;
                                      _yieldState/*_yieldState*/ = 3;
                                      __LINE__ = 8;
                                      break;
                                    }
                                  case 2 :
                                    
                                    __LINE__ = 8;
                                    _yieldState/*_yieldState*/ = 3;
                                    __LINE__ = 8;
                                    return x/*x*/;
                                  case 3 :
                                    
                                    __LINE__ = 8;
                                    _yieldState/*_yieldState*/ = 4;
                                    __LINE__ = 8;
                                    break;
                                  case 4 :
                                    
                                    __LINE__ = 6;
                                     ++ _mochaLocalTmp2/*_mochaLocalTmp2*/;
                                    
                                    __LINE__ = 6;
                                    if (_mochaLocalTmp2/*_mochaLocalTmp2*/<length/*length*/){
                                      
                                      __LINE__ = 2;
                                      _yieldState/*_yieldState*/ = 1;
                                      __LINE__ = 6;
                                      break;
                                    } else {
                                      __LINE__ = 2;
                                      _yieldState/*_yieldState*/ = -1;
                                    }
                                  case -1 :
                                    
                                    __LINE__ = 6;
                                    if (_isYieldSafe/*_isYieldSafe*/){
                                      __LINE__ = 6;
                                      return undefined;
                                    }
                                    
                                    __LINE__ = 6;
                                    Runtime/*Runtime*/.throwStopIteration();
                                    
                                }
                                
                              }
                              
                            } catch(e){
                              Runtime.exceptionHandler(__LINE__, __FILE__, e);
                            }
                          };
                      __LINE__ = 6;
                      return Runtime/*Runtime*/.createGenerator(_mochaGenerator/*_mochaGenerator*/,
                      function () {
                        try {
                          __LINE__ = 6;
                          _yieldState/*_yieldState*/ = -1;
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
              return _mochaLocalTmp3/*_mochaLocalTmp3*/;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          }
          __LINE__ = 0;
          var _mochaLocalExport/*_mochaLocalExport*/ = _mochaGlobalAlias/*_mochaGlobalAlias*/,
              hasOwn/*hasOwn*/ = {}.hasOwnProperty,
              iterator/*iterator*/ = _mochaLocalExport/*_mochaLocalExport*/.iterator = "__mocha_iterator_special_key__";
          
          __LINE__ = 4;
          _mochaLocalExport/*_mochaLocalExport*/.keys = keys/*keys*/;
          
          __LINE__ = 14;
          _mochaLocalExport/*_mochaLocalExport*/.values = values/*values*/;
          
          __LINE__ = 26;
          _mochaLocalExport/*_mochaLocalExport*/.items = items/*items*/;
          
          __LINE__ = 36;
          _mochaLocalExport/*_mochaLocalExport*/.allKeys = allKeys/*allKeys*/;
          
          __LINE__ = 44;
          _mochaLocalExport/*_mochaLocalExport*/.allValues = allValues/*allValues*/;
          
          __LINE__ = 52;
          _mochaLocalExport/*_mochaLocalExport*/.allItems = allItems/*allItems*/;
          __LINE__ = 0;
          return _mochaLocalExport/*_mochaLocalExport*/;
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
      var __FILE__ = "-759650552-array_comprehensions_test.js",
          __LINE__ = 0;
      __LINE__ = 2;
      _mochaGlobalExport/*_mochaGlobalExport*/['-759650552-array_comprehensions_test.js'] = {};
      
      __LINE__ = 3;
      var _mochaGlobalAlias/*_mochaGlobalAlias*/ = _mochaGlobalExport/*_mochaGlobalExport*/['-759650552-array_comprehensions_test.js'],
          _mochaLocalTmp0/*_mochaLocalTmp0*/ = _mochaGlobalExport/*_mochaGlobalExport*/.iterators,
          items/*items*/ = _mochaLocalTmp0/*_mochaLocalTmp0*/.items,
          testTarget/*testTarget*/ =  {
            value1 : 100,
            value2 : 200,
            value3 : 300
          },
          cmpTest/*cmpTest*/ = function () {
            try {
              __LINE__ = 9;
              var _mochaLocalTmp1/*_mochaLocalTmp1*/ = [];
              
              __LINE__ = 9;
              for (var prop/*prop*/ in testTarget/*testTarget*/){
                
                __LINE__ = 9;
                prop/*prop*/ = testTarget/*testTarget*/[prop/*prop*/];
                
                __LINE__ = 9;
                _mochaLocalTmp1/*_mochaLocalTmp1*/.push(prop/*prop*/);
              }
              __LINE__ = 9;
              return _mochaLocalTmp1/*_mochaLocalTmp1*/;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          }.call(this);
      
      __LINE__ = 10;
      Runtime/*Runtime*/.assert(true,cmpTest/*cmpTest*/[0] === 100,"cmpTest[0] === 100",10,'array_comprehensions_test.js');
      
      __LINE__ = 11;
      Runtime/*Runtime*/.assert(true,cmpTest/*cmpTest*/[1] === 200,"cmpTest[1] === 200",11,'array_comprehensions_test.js');
      
      __LINE__ = 12;
      Runtime/*Runtime*/.assert(true,cmpTest/*cmpTest*/[2] === 300,"cmpTest[2] === 300",12,'array_comprehensions_test.js');
      
      __LINE__ = 14;
      cmpTest/*cmpTest*/ = function () {
        try {
          __LINE__ = 14;
          var _mochaLocalTmp2/*_mochaLocalTmp2*/ = [];
          
          __LINE__ = 14;
          for (var prop/*prop*/ in testTarget/*testTarget*/){
            
            __LINE__ = 14;
            _mochaLocalTmp2/*_mochaLocalTmp2*/.push(prop/*prop*/);
          }
          __LINE__ = 14;
          return _mochaLocalTmp2/*_mochaLocalTmp2*/;
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }.call(this);
      
      __LINE__ = 15;
      Runtime/*Runtime*/.assert(true,cmpTest/*cmpTest*/[0] === "value1","cmpTest[0] === \"value1\"",15,'array_comprehensions_test.js');
      
      __LINE__ = 16;
      Runtime/*Runtime*/.assert(true,cmpTest/*cmpTest*/[1] === "value2","cmpTest[1] === \"value2\"",16,'array_comprehensions_test.js');
      
      __LINE__ = 17;
      Runtime/*Runtime*/.assert(true,cmpTest/*cmpTest*/[2] === "value3","cmpTest[2] === \"value3\"",17,'array_comprehensions_test.js');
      
      __LINE__ = 19;
      cmpTest/*cmpTest*/ = function () {
        try {
          __LINE__ = 19;
          var _mochaLocalTmp3/*_mochaLocalTmp3*/ = [],
              prop/*prop*/,
              _mochaLocalTmp4/*_mochaLocalTmp4*/ = items/*items*/(testTarget/*testTarget*/);
          
          __LINE__ = 19;
          _mochaLocalTmp4/*_mochaLocalTmp4*/ = Runtime/*Runtime*/.hasIterator(_mochaLocalTmp4/*_mochaLocalTmp4*/)?Runtime/*Runtime*/.getIterator(_mochaLocalTmp4/*_mochaLocalTmp4*/) : _mochaLocalTmp4/*_mochaLocalTmp4*/;
          
          __LINE__ = 19;
          if (_mochaLocalTmp4/*_mochaLocalTmp4*/.__nothrowNext__){
            __LINE__ = 19;
            while ((prop/*prop*/ = _mochaLocalTmp4/*_mochaLocalTmp4*/.__nothrowNext__())){
              __LINE__ = 19;
              _mochaLocalTmp3/*_mochaLocalTmp3*/.push(prop/*prop*/);
            }
            
          } else {
            __LINE__ = 19;
            Runtime/*Runtime*/.exceptionHandler(19,'..///Users/aono_taketoshi/github/mocha/src/test/js/harmony/array_comprehensions_test.js','for of statement expect iterator or generator object.');
          }
          __LINE__ = 19;
          return _mochaLocalTmp3/*_mochaLocalTmp3*/;
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }.call(this);
      
      __LINE__ = 20;
      Runtime/*Runtime*/.assert(true,cmpTest/*cmpTest*/[0][0] === "value1","cmpTest[0][0] === \"value1\"",20,'array_comprehensions_test.js');
      
      __LINE__ = 21;
      Runtime/*Runtime*/.assert(true,cmpTest/*cmpTest*/[0][1] === 100,"cmpTest[0][1] === 100",21,'array_comprehensions_test.js');
      
      __LINE__ = 22;
      Runtime/*Runtime*/.assert(true,cmpTest/*cmpTest*/[1][0] === "value2","cmpTest[1][0] === \"value2\"",22,'array_comprehensions_test.js');
      
      __LINE__ = 23;
      Runtime/*Runtime*/.assert(true,cmpTest/*cmpTest*/[1][1] === 200,"cmpTest[1][1] === 200",23,'array_comprehensions_test.js');
      
      __LINE__ = 24;
      Runtime/*Runtime*/.assert(true,cmpTest/*cmpTest*/[2][0] === "value3","cmpTest[2][0] === \"value3\"",24,'array_comprehensions_test.js');
      
      __LINE__ = 25;
      Runtime/*Runtime*/.assert(true,cmpTest/*cmpTest*/[2][1] === 300,"cmpTest[2][1] === 300",25,'array_comprehensions_test.js');
      
      __LINE__ = 28;
      var cmpTest/*cmpTest*/ = function () {
            try {
              __LINE__ = 28;
              var _mochaLocalTmp5/*_mochaLocalTmp5*/ = [];
              
              __LINE__ = 28;
              for (var prop/*prop*/ in testTarget/*testTarget*/){
                
                __LINE__ = 28;
                prop/*prop*/ = testTarget/*testTarget*/[prop/*prop*/];
                
                __LINE__ = 28;
                prop/*prop*/ === 200 && _mochaLocalTmp5/*_mochaLocalTmp5*/.push(prop/*prop*/);
              }
              __LINE__ = 28;
              return _mochaLocalTmp5/*_mochaLocalTmp5*/;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          }.call(this);
      
      __LINE__ = 29;
      Runtime/*Runtime*/.assert(true,cmpTest/*cmpTest*/[0] === 200,"cmpTest[0] === 200",29,'array_comprehensions_test.js');
      
      __LINE__ = 31;
      cmpTest/*cmpTest*/ = function () {
        try {
          __LINE__ = 31;
          var _mochaLocalTmp6/*_mochaLocalTmp6*/ = [];
          
          __LINE__ = 31;
          for (var prop/*prop*/ in testTarget/*testTarget*/){
            
            __LINE__ = 31;
            prop/*prop*/ === "value2" && _mochaLocalTmp6/*_mochaLocalTmp6*/.push(prop/*prop*/);
          }
          __LINE__ = 31;
          return _mochaLocalTmp6/*_mochaLocalTmp6*/;
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }.call(this);
      
      __LINE__ = 32;
      Runtime/*Runtime*/.assert(true,cmpTest/*cmpTest*/[0] === "value2","cmpTest[0] === \"value2\"",32,'array_comprehensions_test.js');
      
      __LINE__ = 34;
      cmpTest/*cmpTest*/ = function () {
        try {
          __LINE__ = 34;
          var _mochaLocalTmp7/*_mochaLocalTmp7*/ = [],
              prop/*prop*/,
              _mochaLocalTmp8/*_mochaLocalTmp8*/ = items/*items*/(testTarget/*testTarget*/);
          
          __LINE__ = 34;
          _mochaLocalTmp8/*_mochaLocalTmp8*/ = Runtime/*Runtime*/.hasIterator(_mochaLocalTmp8/*_mochaLocalTmp8*/)?Runtime/*Runtime*/.getIterator(_mochaLocalTmp8/*_mochaLocalTmp8*/) : _mochaLocalTmp8/*_mochaLocalTmp8*/;
          
          __LINE__ = 34;
          if (_mochaLocalTmp8/*_mochaLocalTmp8*/.__nothrowNext__){
            __LINE__ = 34;
            while ((prop/*prop*/ = _mochaLocalTmp8/*_mochaLocalTmp8*/.__nothrowNext__())){
              __LINE__ = 34;
              prop/*prop*/[1] === 200 && _mochaLocalTmp7/*_mochaLocalTmp7*/.push(prop/*prop*/);
            }
            
          } else {
            __LINE__ = 34;
            Runtime/*Runtime*/.exceptionHandler(34,'..///Users/aono_taketoshi/github/mocha/src/test/js/harmony/array_comprehensions_test.js','for of statement expect iterator or generator object.');
          }
          __LINE__ = 34;
          return _mochaLocalTmp7/*_mochaLocalTmp7*/;
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }.call(this);
      
      __LINE__ = 35;
      Runtime/*Runtime*/.assert(true,cmpTest/*cmpTest*/[0][0] === "value2","cmpTest[0][0] === \"value2\"",35,'array_comprehensions_test.js');
      
      __LINE__ = 36;
      Runtime/*Runtime*/.assert(true,cmpTest/*cmpTest*/[0][1] === 200,"cmpTest[0][1] === 200",36,'array_comprehensions_test.js');
      
      __LINE__ = 38;
      testTarget/*testTarget*/ =  {
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
      cmpTest/*cmpTest*/ = function () {
        try {
          __LINE__ = 44;
          var _mochaLocalTmp9/*_mochaLocalTmp9*/ = [];
          
          __LINE__ = 44;
          for (var prop/*prop*/ in testTarget/*testTarget*/){
            
            __LINE__ = 44;
            prop/*prop*/ = testTarget/*testTarget*/[prop/*prop*/];
            
            __LINE__ = 44;
            for (var x/*x*/ in prop/*prop*/){
              
              __LINE__ = 44;
              x/*x*/ = prop/*prop*/[x/*x*/];
              
              __LINE__ = 44;
              _mochaLocalTmp9/*_mochaLocalTmp9*/.push(x/*x*/);
            }
            
          }
          __LINE__ = 44;
          return _mochaLocalTmp9/*_mochaLocalTmp9*/;
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }.call(this);
      
      __LINE__ = 45;
      Runtime/*Runtime*/.assert(true,cmpTest/*cmpTest*/[0] === 100,"cmpTest[0] === 100",45,'array_comprehensions_test.js');
      
      __LINE__ = 46;
      Runtime/*Runtime*/.assert(true,cmpTest/*cmpTest*/[1] === 200,"cmpTest[1] === 200",46,'array_comprehensions_test.js');
      
      __LINE__ = 47;
      Runtime/*Runtime*/.assert(true,cmpTest/*cmpTest*/[2] === 300,"cmpTest[2] === 300",47,'array_comprehensions_test.js');
      
      __LINE__ = 49;
      cmpTest/*cmpTest*/ = function () {
        try {
          __LINE__ = 49;
          var _mochaLocalTmp10/*_mochaLocalTmp10*/ = [];
          
          __LINE__ = 49;
          for (var prop/*prop*/ in testTarget/*testTarget*/){
            
            __LINE__ = 49;
            prop/*prop*/ = testTarget/*testTarget*/[prop/*prop*/];
            
            __LINE__ = 49;
            for (var x/*x*/ in prop/*prop*/){
              __LINE__ = 49;
              _mochaLocalTmp10/*_mochaLocalTmp10*/.push(x/*x*/);
            }
            
          }
          __LINE__ = 49;
          return _mochaLocalTmp10/*_mochaLocalTmp10*/;
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }.call(this);
      
      __LINE__ = 50;
      Runtime/*Runtime*/.assert(true,cmpTest/*cmpTest*/[0] === "value1","cmpTest[0] === \"value1\"",50,'array_comprehensions_test.js');
      
      __LINE__ = 51;
      Runtime/*Runtime*/.assert(true,cmpTest/*cmpTest*/[1] === "value2","cmpTest[1] === \"value2\"",51,'array_comprehensions_test.js');
      
      __LINE__ = 52;
      Runtime/*Runtime*/.assert(true,cmpTest/*cmpTest*/[2] === "value3","cmpTest[2] === \"value3\"",52,'array_comprehensions_test.js');
      
      __LINE__ = 54;
      cmpTest/*cmpTest*/ = function () {
        try {
          __LINE__ = 54;
          var _mochaLocalTmp11/*_mochaLocalTmp11*/ = [];
          
          __LINE__ = 54;
          for (var prop/*prop*/ in testTarget/*testTarget*/){
            
            __LINE__ = 54;
            prop/*prop*/ = testTarget/*testTarget*/[prop/*prop*/];
            
            __LINE__ = 54;
            var x/*x*/;
            
            __LINE__ = 54;
            var _mochaLocalTmp12/*_mochaLocalTmp12*/ = items/*items*/(prop/*prop*/);
            
            __LINE__ = 54;
            _mochaLocalTmp12/*_mochaLocalTmp12*/ = Runtime/*Runtime*/.hasIterator(_mochaLocalTmp12/*_mochaLocalTmp12*/)?Runtime/*Runtime*/.getIterator(_mochaLocalTmp12/*_mochaLocalTmp12*/) : _mochaLocalTmp12/*_mochaLocalTmp12*/;
            
            __LINE__ = 54;
            if (_mochaLocalTmp12/*_mochaLocalTmp12*/.__nothrowNext__){
              __LINE__ = 54;
              while ((x/*x*/ = _mochaLocalTmp12/*_mochaLocalTmp12*/.__nothrowNext__())){
                __LINE__ = 54;
                _mochaLocalTmp11/*_mochaLocalTmp11*/.push(x/*x*/);
              }
              
            } else {
              __LINE__ = 54;
              Runtime/*Runtime*/.exceptionHandler(54,'..///Users/aono_taketoshi/github/mocha/src/test/js/harmony/array_comprehensions_test.js','for of statement expect iterator or generator object.');
            }
            
          }
          __LINE__ = 54;
          return _mochaLocalTmp11/*_mochaLocalTmp11*/;
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }.call(this);
      
      __LINE__ = 55;
      Runtime/*Runtime*/.assert(true,cmpTest/*cmpTest*/[0][0] === "value1","cmpTest[0][0] === \"value1\"",55,'array_comprehensions_test.js');
      
      __LINE__ = 56;
      Runtime/*Runtime*/.assert(true,cmpTest/*cmpTest*/[0][1] === 100,"cmpTest[0][1] === 100",56,'array_comprehensions_test.js');
      
      __LINE__ = 57;
      Runtime/*Runtime*/.assert(true,cmpTest/*cmpTest*/[1][0] === "value2","cmpTest[1][0] === \"value2\"",57,'array_comprehensions_test.js');
      
      __LINE__ = 58;
      Runtime/*Runtime*/.assert(true,cmpTest/*cmpTest*/[1][1] === 200,"cmpTest[1][1] === 200",58,'array_comprehensions_test.js');
      
      __LINE__ = 59;
      Runtime/*Runtime*/.assert(true,cmpTest/*cmpTest*/[2][0] === "value3","cmpTest[2][0] === \"value3\"",59,'array_comprehensions_test.js');
      
      __LINE__ = 60;
      Runtime/*Runtime*/.assert(true,cmpTest/*cmpTest*/[2][1] === 300,"cmpTest[2][1] === 300",60,'array_comprehensions_test.js');
      
      __LINE__ = 63;
      var m/*m*/ = function (_mochaLocalTmp13/*_mochaLocalTmp13*/) {
            try {
              __LINE__ = 63;
              var v/*v*/ = _mochaLocalTmp13/*_mochaLocalTmp13*/.v;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          };
    } catch(e){
      Runtime.exceptionHandler(__LINE__, __FILE__, e);
    }
  }();
}();
