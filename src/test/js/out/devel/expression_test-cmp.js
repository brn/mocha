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
  __LINE__ = 0;
  !function () {
    try {
      var __FILE__ = "1653259312-expression_test.js",
          __LINE__ = 0;
      function primaryTest/*primaryTest*/() {
        try {
          __LINE__ = 342;
          var array/*array*/ = [,,,];
          
          __LINE__ = 343;
          Runtime/*Runtime*/.assert(true,array/*array*/.length === 3,"array.length === 3",343,'expression_test.js');
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }
      function expressionTest/*expressionTest*/() {
        try {
          __LINE__ = 311;
          var exp/*exp*/ = function () {
                try {
                  __LINE__ = 312;
                  return 1;
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              }();
          
          __LINE__ = 314;
          Runtime/*Runtime*/.assert(true,exp/*exp*/ === 1,"exp === 1",314,'expression_test.js');
          
          __LINE__ = 316;
          var a/*a*/,
              b/*b*/,
              c/*c*/;
          
          __LINE__ = 317;
          exp/*exp*/ = (a/*a*/ = 0, b/*b*/ = 1, c/*c*/ = 2);
          
          __LINE__ = 318;
          Runtime/*Runtime*/.assert(true,a/*a*/ === 0,"a === 0",318,'expression_test.js');
          
          __LINE__ = 319;
          Runtime/*Runtime*/.assert(true,b/*b*/ === 1,"b === 1",319,'expression_test.js');
          
          __LINE__ = 320;
          Runtime/*Runtime*/.assert(true,c/*c*/ === 2,"c === 2",320,'expression_test.js');
          
          __LINE__ = 321;
          Runtime/*Runtime*/.assert(true,exp/*exp*/ === 2,"exp === 2",321,'expression_test.js');
          
          __LINE__ = 323;
          !function () {
            try {
              __LINE__ = 324;
              exp/*exp*/ = 10;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          }();
          
          __LINE__ = 327;
          Runtime/*Runtime*/.assert(true,exp/*exp*/ === 10,"exp === 10",327,'expression_test.js');
          
          __LINE__ = 329;
          !function (a/*a*/,b/*b*/) {
            try {
              __LINE__ = 330;
              exp/*exp*/ = a/*a*/+b/*b*/;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          }((function () {
            try {
              __LINE__ = 331;
              return 100;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          })(),function () {
            try {
              __LINE__ = 331;
              return 200;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          }());
          
          __LINE__ = 333;
          Runtime/*Runtime*/.assert(true,exp/*exp*/ === 300,"exp === 300",333,'expression_test.js');
          
          __LINE__ = 335;
          !function () {
            try {
              __LINE__ = 336;
              exp/*exp*/ = 1;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          }();
          
          __LINE__ = 338;
          Runtime/*Runtime*/.assert(true,exp/*exp*/ === 1,"exp === 1",338,'expression_test.js');
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }
      function memberExpressionTest/*memberExpressionTest*/() {
        try {
          __LINE__ = 295;
          var test/*test*/ =  {
                test2 :  {
                  "@test" :  {
                    0 :  {
                      "1" : function () {
                        try {
                          __LINE__ = 300;
                          return function () {
                            try {
                              __LINE__ = 300;
                              return 1;
                            } catch(e){
                              Runtime.exceptionHandler(__LINE__, __FILE__, e);
                            }
                          };
                        } catch(e){
                          Runtime.exceptionHandler(__LINE__, __FILE__, e);
                        }
                      }
                    }
                  }
                }
              };
          
          __LINE__ = 306;
          Runtime/*Runtime*/.assert(true,test/*test*/["test2"]["@test"]["0"]["1"]()() === 1,"test[\"test2\"][\"@test\"][\"0\"][\"1\"]()() === 1",306,'expression_test.js');
          
          __LINE__ = 307;
          Runtime/*Runtime*/.assert(true,test/*test*/.test2["@test"][0]["1"]()() === 1,"test.test2[\"@test\"][0][\"1\"]()() === 1",307,'expression_test.js');
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }
      function unaryExpressionTest/*unaryExpressionTest*/() {
        try {
          __LINE__ = 275;
          var strNum/*strNum*/ = "1",
              ret/*ret*/ = +strNum/*strNum*/;
          
          __LINE__ = 277;
          Runtime/*Runtime*/.assert(true,ret/*ret*/ === 1,"ret === 1",277,'expression_test.js');
          
          __LINE__ = 279;
          ret/*ret*/ = -strNum/*strNum*/;
          
          __LINE__ = 280;
          Runtime/*Runtime*/.assert(true,ret/*ret*/ === -1,"ret === -1",280,'expression_test.js');
          
          __LINE__ = 282;
          var num/*num*/ = -5;
          
          __LINE__ = 283;
          ret/*ret*/ = ~num/*num*/;
          
          __LINE__ = 284;
          Runtime/*Runtime*/.assert(true,ret/*ret*/ === 4,"ret === 4",284,'expression_test.js');
          
          __LINE__ = 286;
          var flg/*flg*/ = true;
          
          __LINE__ = 287;
          ret/*ret*/ = !flg/*flg*/;
          
          __LINE__ = 288;
          Runtime/*Runtime*/.assert(true,ret/*ret*/ === false,"ret === false",288,'expression_test.js');
          
          __LINE__ = 290;
          ret/*ret*/ = !!flg/*flg*/;
          
          __LINE__ = 291;
          Runtime/*Runtime*/.assert(true,ret/*ret*/ === true,"ret === true",291,'expression_test.js');
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }
      function postfixExpressionTest/*postfixExpressionTest*/() {
        try {
          __LINE__ = 249;
          var add/*add*/ = 0;
          
          __LINE__ = 250;
          add/*add*/ ++ ;
          
          __LINE__ = 251;
          Runtime/*Runtime*/.assert(true,add/*add*/ === 1,"add === 1",251,'expression_test.js');
          
          __LINE__ = 253;
          var sub/*sub*/ = 1;
          
          __LINE__ = 254;
          sub/*sub*/ -- ;
          
          __LINE__ = 255;
          Runtime/*Runtime*/.assert(true,sub/*sub*/ === 0,"sub === 0",255,'expression_test.js');
          
          __LINE__ = 257;
          add/*add*/ = 0;
          
          __LINE__ = 258;
          sub/*sub*/ = add/*add*/;
          
          __LINE__ = 259;
           ++ sub/*sub*/;
          
          __LINE__ = 260;
          Runtime/*Runtime*/.assert(true,sub/*sub*/ === 1,"sub === 1",260,'expression_test.js');
          
          __LINE__ = 262;
          add/*add*/ = 1;
          
          __LINE__ = 263;
          sub/*sub*/ = add/*add*/;
          
          __LINE__ = 264;
           -- sub/*sub*/;
          
          __LINE__ = 265;
          Runtime/*Runtime*/.assert(true,sub/*sub*/ === 0,"sub === 0",265,'expression_test.js');
          
          __LINE__ = 267;
          sub/*sub*/ = 1;
          
          __LINE__ = 268;
          sub/*sub*/ -- ;
          
          __LINE__ = 269;
          add/*add*/ = sub/*sub*/;
          
          __LINE__ = 270;
          Runtime/*Runtime*/.assert(true,add/*add*/ === 0,"add === 0",270,'expression_test.js');
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }
      function binaryExpressionTest/*binaryExpressionTest*/() {
        try {
          __LINE__ = 83;
          var item/*item*/ = 100,
              trueValue/*trueValue*/ = true,
              falseValue/*falseValue*/ = false,
              val/*val*/ = 0;
          
          __LINE__ = 88;
          item/*item*/ && trueValue/*trueValue*/ && !falseValue/*falseValue*/ && (val/*val*/ = 1);
          
          __LINE__ = 90;
          Runtime/*Runtime*/.assert(true,val/*val*/ === 1,"val === 1",90,'expression_test.js');
          
          __LINE__ = 92;
          ((item/*item*/ && trueValue/*trueValue*/) || falseValue/*falseValue*/) && (val/*val*/ = 2);
          
          __LINE__ = 94;
          Runtime/*Runtime*/.assert(true,val/*val*/ === 2,"val === 2",94,'expression_test.js');
          
          __LINE__ = 96;
          ((item/*item*/ && falseValue/*falseValue*/) || !trueValue/*trueValue*/) && (val/*val*/ = 3);
          
          __LINE__ = 98;
          Runtime/*Runtime*/.assert(false,val/*val*/ === 3,"val === 3",98,'expression_test.js');
          
          __LINE__ = 100;
          var changeVal/*changeVal*/ = function (value/*value*/) {
                try {
                  __LINE__ = 101;
                  val/*val*/ = value/*value*/;
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              };
          
          __LINE__ = 104;
          (item/*item*/) && (trueValue/*trueValue*/) && (!falseValue/*falseValue*/) && (changeVal/*changeVal*/(4));
          
          __LINE__ = 105;
          Runtime/*Runtime*/.assert(true,val/*val*/ === 4,"val === 4",105,'expression_test.js');
          
          __LINE__ = 107;
          var eq/*eq*/ = 0,
              eqVal/*eqVal*/ = 0;
          
          __LINE__ = 110;
          eq/*eq*/ == 0 && (eqVal/*eqVal*/ = 1);
          
          __LINE__ = 112;
          Runtime/*Runtime*/.assert(true,eqVal/*eqVal*/ === 1,"eqVal === 1",112,'expression_test.js');
          
          __LINE__ = 115;
          eq/*eq*/ === 0 && (eqVal/*eqVal*/ = 2);
          
          __LINE__ = 117;
          Runtime/*Runtime*/.assert(true,eqVal/*eqVal*/ === 2,"eqVal === 2",117,'expression_test.js');
          
          __LINE__ = 119;
          var bit/*bit*/ = 1,
              ret/*ret*/ = 0;
          
          __LINE__ = 121;
          ret/*ret*/ = bit/*bit*/ << 1;
          
          __LINE__ = 122;
          Runtime/*Runtime*/.assert(true,ret/*ret*/ === 2,"ret === 2",122,'expression_test.js');
          
          __LINE__ = 123;
          ret/*ret*/ = bit/*bit*/ >> 1;
          
          __LINE__ = 124;
          Runtime/*Runtime*/.assert(true,ret/*ret*/ === 0,"ret === 0",124,'expression_test.js');
          
          __LINE__ = 125;
          ret/*ret*/ = bit/*bit*/|2;
          
          __LINE__ = 126;
          Runtime/*Runtime*/.assert(true,ret/*ret*/ === 3,"ret === 3",126,'expression_test.js');
          
          __LINE__ = 128;
          bit/*bit*/ = 1;
          
          __LINE__ = 129;
          bit/*bit*/ <<= 1;
          
          __LINE__ = 130;
          Runtime/*Runtime*/.assert(true,bit/*bit*/ === 2,"bit === 2",130,'expression_test.js');
          
          __LINE__ = 131;
          bit/*bit*/ = 1;
          
          __LINE__ = 132;
          bit/*bit*/ >>= 1;
          
          __LINE__ = 133;
          Runtime/*Runtime*/.assert(true,bit/*bit*/ === 0,"bit === 0",133,'expression_test.js');
          
          __LINE__ = 134;
          bit/*bit*/ = 1;
          
          __LINE__ = 135;
          bit/*bit*/ |= 2;
          
          __LINE__ = 136;
          Runtime/*Runtime*/.assert(true,bit/*bit*/ === 3,"bit === 3",136,'expression_test.js');
          
          __LINE__ = 138;
          bit/*bit*/ = 10;
          
          __LINE__ = 139;
          ret/*ret*/ = bit/*bit*/ >>> 2;
          
          __LINE__ = 140;
          Runtime/*Runtime*/.assert(true,ret/*ret*/ === 2,"ret === 2",140,'expression_test.js');
          
          __LINE__ = 141;
          bit/*bit*/ = 10;
          
          __LINE__ = 142;
          bit/*bit*/ >>>= 2;
          
          __LINE__ = 143;
          Runtime/*Runtime*/.assert(true,bit/*bit*/ === 2,"bit === 2",143,'expression_test.js');
          
          __LINE__ = 145;
          bit/*bit*/ = 3;
          
          __LINE__ = 146;
          ret/*ret*/ = bit/*bit*/&1;
          
          __LINE__ = 147;
          Runtime/*Runtime*/.assert(true,ret/*ret*/ === 1,"ret === 1",147,'expression_test.js');
          
          __LINE__ = 148;
          bit/*bit*/ &= 1;
          
          __LINE__ = 149;
          Runtime/*Runtime*/.assert(true,bit/*bit*/ === 1,"bit === 1",149,'expression_test.js');
          
          __LINE__ = 151;
          bit/*bit*/ = 2;
          
          __LINE__ = 152;
          ret/*ret*/ = bit/*bit*/^1;
          
          __LINE__ = 153;
          Runtime/*Runtime*/.assert(true,ret/*ret*/ === 3,"ret === 3",153,'expression_test.js');
          
          __LINE__ = 154;
          bit/*bit*/ = 2;
          
          __LINE__ = 155;
          bit/*bit*/ ^= 1;
          
          __LINE__ = 156;
          Runtime/*Runtime*/.assert(true,bit/*bit*/ === 3,"bit === 3",156,'expression_test.js');
          
          __LINE__ = 158;
          var lt/*lt*/ = 0,
              gt/*gt*/ = 1,
              cmpVal/*cmpVal*/ = 0;
          
          __LINE__ = 163;
          lt/*lt*/>gt/*gt*/ && (cmpVal/*cmpVal*/ = 1);
          
          __LINE__ = 165;
          Runtime/*Runtime*/.assert(true,cmpVal/*cmpVal*/ === 0,"cmpVal === 0",165,'expression_test.js');
          
          __LINE__ = 167;
          cmpVal/*cmpVal*/ = 0;
          
          __LINE__ = 169;
          lt/*lt*/<gt/*gt*/ && (cmpVal/*cmpVal*/ = 1);
          
          __LINE__ = 171;
          Runtime/*Runtime*/.assert(true,cmpVal/*cmpVal*/ === 1,"cmpVal === 1",171,'expression_test.js');
          
          __LINE__ = 173;
          cmpVal/*cmpVal*/ = 0;
          
          __LINE__ = 175;
          lt/*lt*/ <= gt/*gt*/ && (cmpVal/*cmpVal*/ = 1);
          
          __LINE__ = 177;
          Runtime/*Runtime*/.assert(true,cmpVal/*cmpVal*/ === 1,"cmpVal === 1",177,'expression_test.js');
          
          __LINE__ = 179;
          cmpVal/*cmpVal*/ = 0;
          
          __LINE__ = 181;
          lt/*lt*/ >= gt/*gt*/ && (cmpVal/*cmpVal*/ = 1);
          
          __LINE__ = 183;
          Runtime/*Runtime*/.assert(false,cmpVal/*cmpVal*/ === 1,"cmpVal === 1",183,'expression_test.js');
          
          __LINE__ = 185;
          cmpVal/*cmpVal*/ = 0;
          
          __LINE__ = 186;
          lt/*lt*/ = 1;
          
          __LINE__ = 188;
          lt/*lt*/ <= gt/*gt*/ && (cmpVal/*cmpVal*/ = 1);
          
          __LINE__ = 190;
          Runtime/*Runtime*/.assert(true,cmpVal/*cmpVal*/ === 1,"cmpVal === 1",190,'expression_test.js');
          
          __LINE__ = 192;
          cmpVal/*cmpVal*/ = 1;
          
          __LINE__ = 194;
          lt/*lt*/ >= gt/*gt*/ && (cmpVal/*cmpVal*/ = 1);
          
          __LINE__ = 196;
          Runtime/*Runtime*/.assert(true,cmpVal/*cmpVal*/ === 1,"cmpVal === 1",196,'expression_test.js');
          
          __LINE__ = 198;
          var pl/*pl*/ = 0;
          
          __LINE__ = 199;
          ret/*ret*/ = pl/*pl*/+1;
          
          __LINE__ = 200;
          Runtime/*Runtime*/.assert(true,ret/*ret*/ === 1,"ret === 1",200,'expression_test.js');
          
          __LINE__ = 202;
          var mi/*mi*/ = 1;
          
          __LINE__ = 203;
          ret/*ret*/ = mi/*mi*/-1;
          
          __LINE__ = 204;
          Runtime/*Runtime*/.assert(true,ret/*ret*/ === 0,"ret === 0",204,'expression_test.js');
          
          __LINE__ = 206;
          var mul/*mul*/ = 1;
          
          __LINE__ = 207;
          ret/*ret*/ = mul/*mul*/*2;
          
          __LINE__ = 208;
          Runtime/*Runtime*/.assert(true,ret/*ret*/ === 2,"ret === 2",208,'expression_test.js');
          
          __LINE__ = 210;
          var div/*div*/ = 2;
          
          __LINE__ = 211;
          ret/*ret*/ = div/*div*//2;
          
          __LINE__ = 212;
          Runtime/*Runtime*/.assert(true,ret/*ret*/ === 1,"ret === 1",212,'expression_test.js');
          
          __LINE__ = 214;
          var mod/*mod*/ = 3;
          
          __LINE__ = 215;
          ret/*ret*/ = mod/*mod*/%2;
          
          __LINE__ = 216;
          Runtime/*Runtime*/.assert(true,ret/*ret*/ === 1,"ret === 1",216,'expression_test.js');
          
          __LINE__ = 218;
          pl/*pl*/ = 0;
          
          __LINE__ = 219;
          pl/*pl*/ += 1;
          
          __LINE__ = 220;
          Runtime/*Runtime*/.assert(true,pl/*pl*/ === 1,"pl === 1",220,'expression_test.js');
          
          __LINE__ = 222;
          mi/*mi*/ = 1;
          
          __LINE__ = 223;
          mi/*mi*/ -= 1;
          
          __LINE__ = 224;
          Runtime/*Runtime*/.assert(true,mi/*mi*/ === 0,"mi === 0",224,'expression_test.js');
          
          __LINE__ = 226;
          mul/*mul*/ = 1;
          
          __LINE__ = 227;
          mul/*mul*/ *= 2;
          
          __LINE__ = 228;
          Runtime/*Runtime*/.assert(true,mul/*mul*/ === 2,"mul === 2",228,'expression_test.js');
          
          __LINE__ = 230;
          div/*div*/ = 2;
          
          __LINE__ = 231;
          div/*div*/ /= 2;
          
          __LINE__ = 232;
          Runtime/*Runtime*/.assert(true,div/*div*/ === 1,"div === 1",232,'expression_test.js');
          
          __LINE__ = 234;
          mod/*mod*/ = 3;
          
          __LINE__ = 235;
          mod/*mod*/ %= 2;
          
          __LINE__ = 236;
          Runtime/*Runtime*/.assert(true,mod/*mod*/ === 1,"mod === 1",236,'expression_test.js');
          
          __LINE__ = 238;
          var obj/*obj*/ =  {
                'onmouseenter' : 1,
                'onmouseleave' : 1
              },
              testInAnd/*testInAnd*/ = 'onmouseenter' in obj/*obj*/ && 'onmouseleave' in obj/*obj*/;
          
          __LINE__ = 245;
          Runtime/*Runtime*/.assert(true,testInAnd/*testInAnd*/ === true,"testInAnd === true",245,'expression_test.js');
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }
      function callExpressionTest/*callExpressionTest*/() {
        try {
          __LINE__ = 63;
          var highFn/*highFn*/ = function () {
                try {
                  __LINE__ = 64;
                  return function () {
                    try {
                      __LINE__ = 65;
                      return function () {
                        try {
                          __LINE__ = 66;
                          return true;
                        } catch(e){
                          Runtime.exceptionHandler(__LINE__, __FILE__, e);
                        }
                      };
                    } catch(e){
                      Runtime.exceptionHandler(__LINE__, __FILE__, e);
                    }
                  };
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              };
          
          __LINE__ = 70;
          Runtime/*Runtime*/.assert(true,highFn/*highFn*/()()() === true,"highFn()()() === true",70,'expression_test.js');
          
          __LINE__ = 71;
          highFn/*highFn*/ = function () {
            try {
              __LINE__ = 71;
              return inner1/*inner1*/;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          };
          
          __LINE__ = 72;
          var inner1/*inner1*/ = function () {
                try {
                  __LINE__ = 72;
                  return inner2/*inner2*/;
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              },
              inner2/*inner2*/ = function (){},
              flg/*flg*/ = 1,
              instance/*instance*/ = new ((flg/*flg*/)?highFn/*highFn*/ : inner1/*inner1*/);
          
          __LINE__ = 76;
          Runtime/*Runtime*/.assert(true,instance/*instance*/ === inner1/*inner1*/,"instance === inner1",76,'expression_test.js');
          
          __LINE__ = 77;
          var flg2/*flg2*/ = 0;
          
          __LINE__ = 78;
          instance/*instance*/ = new ((flg2/*flg2*/)?highFn/*highFn*/ : inner1/*inner1*/);
          
          __LINE__ = 79;
          Runtime/*Runtime*/.assert(true,instance/*instance*/ === inner2/*inner2*/,"instance === inner2",79,'expression_test.js');
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }
      function objectAndNewTest/*objectAndNewTest*/() {
        try {
          __LINE__ = 19;
          var testObject/*testObject*/ = {};
          
          __LINE__ = 20;
          testObject/*testObject*/.testProp = {};
          
          __LINE__ = 21;
          testObject/*testObject*/.testProp.testProp = {};
          
          __LINE__ = 22;
          testObject/*testObject*/.testProp.testProp.testProp = {};
          
          __LINE__ = 23;
          testObject/*testObject*/.testFn = function () {
            try {
              __LINE__ = 23;
              return true;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          };
          
          __LINE__ = 24;
          testObject/*testObject*/.testProp.testFn = function () {
            try {
              __LINE__ = 24;
              return false;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          };
          
          __LINE__ = 25;
          testObject/*testObject*/.testProp.testProp.testFn = function () {
            try {
              __LINE__ = 25;
              return 2;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          };
          
          __LINE__ = 27;
          Runtime/*Runtime*/.assert(true,testObject/*testObject*/.testFn() === true,"testObject.testFn() === true",27,'expression_test.js');
          
          __LINE__ = 28;
          Runtime/*Runtime*/.assert(true,testObject/*testObject*/.testProp.testFn() === false,"testObject.testProp.testFn() === false",28,'expression_test.js');
          
          __LINE__ = 29;
          Runtime/*Runtime*/.assert(true,testObject/*testObject*/.testProp.testProp.testFn() === 2,"testObject.testProp.testProp.testFn() === 2",29,'expression_test.js');
          
          __LINE__ = 31;
          var highFn/*highFn*/ = function () {
                try {
                  __LINE__ = 31;
                  return inner1/*inner1*/;
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              },
              inner1/*inner1*/ = function () {
                try {
                  __LINE__ = 32;
                  return inner2/*inner2*/;
                } catch(e){
                  Runtime.exceptionHandler(__LINE__, __FILE__, e);
                }
              },
              inner2/*inner2*/ = function (){},
              instance/*instance*/ = new highFn/*highFn*/(),
              instance2/*instance2*/ = new new highFn/*highFn*/(),
              instance3/*instance3*/ = new new new highFn/*highFn*/();
          
          __LINE__ = 37;
          Runtime/*Runtime*/.assert(true,instance/*instance*/ === inner1/*inner1*/,"instance === inner1",37,'expression_test.js');
          
          __LINE__ = 38;
          Runtime/*Runtime*/.assert(true,instance2/*instance2*/ === inner2/*inner2*/,"instance2 === inner2",38,'expression_test.js');
          
          __LINE__ = 39;
          Runtime/*Runtime*/.assert(true,instance3/*instance3*/ instanceof inner2/*inner2*/,"instance3 instanceof inner2",39,'expression_test.js');
          
          __LINE__ = 41;
          var fnObj/*fnObj*/ =  {
                highFn : highFn/*highFn*/,
                highFnInner :  {
                  highFn : highFn/*highFn*/
                }
              },
              instance4/*instance4*/ = new fnObj/*fnObj*/.highFn(),
              instance5/*instance5*/ = new new fnObj/*fnObj*/.highFn(),
              instance6/*instance6*/ = new new new fnObj/*fnObj*/.highFn();
          
          __LINE__ = 51;
          Runtime/*Runtime*/.assert(true,instance4/*instance4*/ === inner1/*inner1*/,"instance4 === inner1",51,'expression_test.js');
          
          __LINE__ = 52;
          Runtime/*Runtime*/.assert(true,instance5/*instance5*/ === inner2/*inner2*/,"instance5 === inner2",52,'expression_test.js');
          
          __LINE__ = 53;
          Runtime/*Runtime*/.assert(true,instance6/*instance6*/ instanceof inner2/*inner2*/,"instance6 instanceof inner2",53,'expression_test.js');
          
          __LINE__ = 54;
          var instance7/*instance7*/ = new fnObj/*fnObj*/.highFnInner.highFn(),
              instance8/*instance8*/ = new new fnObj/*fnObj*/.highFnInner.highFn(),
              instance9/*instance9*/ = new new new fnObj/*fnObj*/.highFnInner.highFn();
          
          __LINE__ = 57;
          Runtime/*Runtime*/.assert(true,instance7/*instance7*/ === inner1/*inner1*/,"instance7 === inner1",57,'expression_test.js');
          
          __LINE__ = 58;
          Runtime/*Runtime*/.assert(true,instance8/*instance8*/ === inner2/*inner2*/,"instance8 === inner2",58,'expression_test.js');
          
          __LINE__ = 59;
          Runtime/*Runtime*/.assert(true,instance9/*instance9*/ instanceof inner2/*inner2*/,"instance9 instanceof inner2",59,'expression_test.js');
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }
      function parseTest/*parseTest*/() {
        try {
          __LINE__ = 3;
          var x/*x*/ = 2.000000;
          
          __LINE__ = 4;
          Runtime/*Runtime*/.assert(true,x/*x*/ === 2,"x === 2",4,'expression_test.js');
          
          __LINE__ = 6;
          x/*x*/ = function () {
            try {
              __LINE__ = 7;
              return 2.000000;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          };
          
          __LINE__ = 9;
          Runtime/*Runtime*/.assert(true,x/*x*/() === 2,"x() === 2",9,'expression_test.js');
          
          __LINE__ = 11;
          x/*x*/ = function () {
            try {
              __LINE__ = 12;
              return /aaa/;
            } catch(e){
              Runtime.exceptionHandler(__LINE__, __FILE__, e);
            }
          };
          
          __LINE__ = 14;
          Runtime/*Runtime*/.assert(true,Object.prototype.toString.call(x/*x*/()) === "[object RegExp]","Object.prototype.toString.call(x()) === \"[object RegExp]\"",14,'expression_test.js');
          
          __LINE__ = 15;
          Runtime/*Runtime*/.assert(true,/aaa/.test("aaa") === true,"/aaa/.test(\"aaa\") === true",15,'expression_test.js');
          
          __LINE__ = 16;
          Runtime/*Runtime*/.assert(true,.200*10 === 2,".200*10 === 2",16,'expression_test.js');
        } catch(e){
          Runtime.exceptionHandler(__LINE__, __FILE__, e);
        }
      }
      __LINE__ = 2;
      _mochaGlobalExport/*_mochaGlobalExport*/['1653259312-expression_test.js'] = {};
      
      __LINE__ = 3;
      var _mochaGlobalAlias/*_mochaGlobalAlias*/ = _mochaGlobalExport/*_mochaGlobalExport*/['1653259312-expression_test.js'];
      
      __LINE__ = 1;
      /aaaa/.test("aaaa");
      
      __LINE__ = 346;
      parseTest/*parseTest*/();
      
      __LINE__ = 347;
      objectAndNewTest/*objectAndNewTest*/();
      
      __LINE__ = 348;
      callExpressionTest/*callExpressionTest*/();
      
      __LINE__ = 349;
      binaryExpressionTest/*binaryExpressionTest*/();
      
      __LINE__ = 350;
      postfixExpressionTest/*postfixExpressionTest*/();
      
      __LINE__ = 351;
      unaryExpressionTest/*unaryExpressionTest*/();
      
      __LINE__ = 352;
      memberExpressionTest/*memberExpressionTest*/();
      
      __LINE__ = 353;
      expressionTest/*expressionTest*/();
      
      __LINE__ = 354;
      primaryTest/*primaryTest*/();
    } catch(e){
      Runtime.exceptionHandler(__LINE__, __FILE__, e);
    }
  }();
}();
