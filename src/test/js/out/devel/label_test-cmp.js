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
      var __FILE__ = "1653259312-label_test.js",
          __LINE__ = 0;
      __LINE__ = 2;
      _mochaGlobalExport/*_mochaGlobalExport*/['1653259312-label_test.js'] = {};
      
      __LINE__ = 3;
      var _mochaGlobalAlias/*_mochaGlobalAlias*/ = _mochaGlobalExport/*_mochaGlobalExport*/['1653259312-label_test.js'],
          ret/*ret*/ = 0;
      __LINE__ = 1;
      TEST_LABEL : 
      {
        
        __LINE__ = 3;
        ret/*ret*/ = 100;
        __LINE__ = 4;
        break TEST_LABEL;
        
        __LINE__ = 5;
        ret/*ret*/ = 200;
      }
      
      __LINE__ = 7;
      Runtime/*Runtime*/.assert(true,ret/*ret*/ === 100,"ret === 100",7,'label_test.js');
      __LINE__ = 4319482256;
      TEST_LABEL2 : {
        
        __LINE__ = 9;
        ret/*ret*/ = 200;
      }
      __LINE__ = 10;
      Runtime/*Runtime*/.assert(true,ret/*ret*/ === 200,"ret === 200",10,'label_test.js');
    } catch(e){
      Runtime.exceptionHandler(__LINE__, __FILE__, e);
    }
  }();
}();
