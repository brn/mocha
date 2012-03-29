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
      var __FILE__ = "-759650552-yield_test.js",
          __LINE__ = 0;
      __LINE__ = 2;
      _mochaGlobalExport/*_mochaGlobalExport*/['-759650552-yield_test.js'] = {};
      
      __LINE__ = 3;
      var _mochaGlobalAlias/*_mochaGlobalAlias*/ = _mochaGlobalExport/*_mochaGlobalExport*/['-759650552-yield_test.js'],
          generator/*generator*/,
          tests/*tests*/ =  {
            case1 : function () {
              try {
                function yieldTest2/*yieldTest2*/() {
                  try {
                    __LINE__ = 4;
                    var _mochaIsNewBorn/*_mochaIsNewBorn*/ = true;
                    
                    __LINE__ = 4;
                    var _yieldResult/*_yieldResult*/ = undefined;
                    
                    __LINE__ = 4;
                    var _yieldState/*_yieldState*/ = 0;
                    
                    __LINE__ = 5;
                    var i/*i*/;
                    
                    __LINE__ = 4;
                    var _mochaGenerator/*_mochaGenerator*/ = function (_isYieldSend/*_isYieldSend*/,_isYieldSafe/*_isYieldSafe*/) {
                          try {
                            __LINE__ = 4;
                            if (!_isYieldSend/*_isYieldSend*/){
                              
                              __LINE__ = 4;
                              _mochaIsNewBorn/*_mochaIsNewBorn*/ = false;
                            } else if (_isYieldSend/*_isYieldSend*/ && _mochaIsNewBorn/*_mochaIsNewBorn*/ && arguments[1] !== undefined){
                              
                              __LINE__ = 4;
                              Runtime/*Runtime*/.exceptionHandler('attempt to send to newborn generator.');
                            }
                            
                            __LINE__ = 4;
                            while (1){
                              __LINE__ = 4;
                              switch (_yieldState/*_yieldState*/) {
                                case 0 :
                                  
                                  __LINE__ = 5;
                                  i/*i*/ = 0;
                                  
                                  __LINE__ = 5;
                                  if (!(i/*i*/<10)){
                                    
                                    __LINE__ = 5;
                                    _yieldState/*_yieldState*/ = -1;
                                    __LINE__ = 5;
                                    break;
                                  }
                                case 1 :
                                  
                                  __LINE__ = 6;
                                  _yieldState/*_yieldState*/ = 2;
                                  __LINE__ = 6;
                                  return i/*i*/;
                                case 2 :
                                  
                                  __LINE__ = 5;
                                  i/*i*/ ++ ;
                                  
                                  __LINE__ = 5;
                                  if (i/*i*/<10){
                                    
                                    __LINE__ = 0;
                                    _yieldState/*_yieldState*/ = 1;
                                    __LINE__ = 5;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState/*_yieldState*/ = -1;
                                  }
                                case -1 :
                                  
                                  __LINE__ = 4;
                                  if (_isYieldSafe/*_isYieldSafe*/){
                                    __LINE__ = 4;
                                    return undefined;
                                  } else {
                                    __LINE__ = 4;
                                    Runtime/*Runtime*/.throwStopIteration();
                                  }
                                  
                              }
                              
                            }
                            
                          } catch(e){
                            Runtime.exceptionHandler(__LINE__, __FILE__, e);
                          }
                        };
                    __LINE__ = 4;
                    return Runtime/*Runtime*/.createGenerator(_mochaGenerator/*_mochaGenerator*/,
                    function () {
                      try {
                        __LINE__ = 4;
                        _yieldState/*_yieldState*/ = -1;
                      } catch(e){
                        Runtime.exceptionHandler(__LINE__, __FILE__, e);
                      }
                    },this);
                  } catch(e){
                    Runtime.exceptionHandler(__LINE__, __FILE__, e);
                  }
                }
                __LINE__ = 10;
                generator/*generator*/ = yieldTest2/*yieldTest2*/();
                
                __LINE__ = 12;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 0,"generator.next() === 0",12,'yield_test.js');
                
                __LINE__ = 13;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 1,"generator.next() === 1",13,'yield_test.js');
                
                __LINE__ = 14;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 2,"generator.next() === 2",14,'yield_test.js');
                
                __LINE__ = 15;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 3,"generator.next() === 3",15,'yield_test.js');
                
                __LINE__ = 16;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 4,"generator.next() === 4",16,'yield_test.js');
                
                __LINE__ = 17;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 5,"generator.next() === 5",17,'yield_test.js');
                
                __LINE__ = 18;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 6,"generator.next() === 6",18,'yield_test.js');
                
                __LINE__ = 19;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 7,"generator.next() === 7",19,'yield_test.js');
                
                __LINE__ = 20;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 8,"generator.next() === 8",20,'yield_test.js');
                
                __LINE__ = 21;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 9,"generator.next() === 9",21,'yield_test.js');
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            },
            case2 : function () {
              try {
                function yieldTest3/*yieldTest3*/() {
                  try {
                    __LINE__ = 25;
                    var _mochaIsNewBorn/*_mochaIsNewBorn*/ = true;
                    
                    __LINE__ = 25;
                    var _yieldResult/*_yieldResult*/ = undefined;
                    
                    __LINE__ = 25;
                    var _yieldState/*_yieldState*/ = 0;
                    
                    __LINE__ = 26;
                    var i/*i*/;
                    
                    __LINE__ = 25;
                    var _mochaGenerator/*_mochaGenerator*/ = function (_isYieldSend/*_isYieldSend*/,_isYieldSafe/*_isYieldSafe*/) {
                          try {
                            __LINE__ = 25;
                            if (!_isYieldSend/*_isYieldSend*/){
                              
                              __LINE__ = 25;
                              _mochaIsNewBorn/*_mochaIsNewBorn*/ = false;
                            } else if (_isYieldSend/*_isYieldSend*/ && _mochaIsNewBorn/*_mochaIsNewBorn*/ && arguments[1] !== undefined){
                              
                              __LINE__ = 25;
                              Runtime/*Runtime*/.exceptionHandler('attempt to send to newborn generator.');
                            }
                            
                            __LINE__ = 25;
                            while (1){
                              __LINE__ = 25;
                              switch (_yieldState/*_yieldState*/) {
                                case 0 :
                                  
                                  __LINE__ = 26;
                                  i/*i*/ = 0;
                                  
                                  __LINE__ = 26;
                                  if (!(i/*i*/<10)){
                                    
                                    __LINE__ = 26;
                                    _yieldState/*_yieldState*/ = -1;
                                    __LINE__ = 26;
                                    break;
                                  }
                                case 1 :
                                  
                                  __LINE__ = 27;
                                  if (i/*i*/%2 === 0){
                                    
                                    __LINE__ = 27;
                                    _yieldState/*_yieldState*/ = 2;
                                    __LINE__ = 27;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 27;
                                    _yieldState/*_yieldState*/ = 3;
                                    __LINE__ = 27;
                                    break;
                                  }
                                case 2 :
                                  
                                  __LINE__ = 28;
                                  _yieldState/*_yieldState*/ = 3;
                                  __LINE__ = 28;
                                  return i/*i*/;
                                case 3 :
                                  
                                  __LINE__ = 27;
                                  _yieldState/*_yieldState*/ = 4;
                                  __LINE__ = 27;
                                  break;
                                case 4 :
                                  
                                  __LINE__ = 26;
                                  i/*i*/ ++ ;
                                  
                                  __LINE__ = 26;
                                  if (i/*i*/<10){
                                    
                                    __LINE__ = 0;
                                    _yieldState/*_yieldState*/ = 1;
                                    __LINE__ = 26;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState/*_yieldState*/ = -1;
                                  }
                                case -1 :
                                  
                                  __LINE__ = 25;
                                  if (_isYieldSafe/*_isYieldSafe*/){
                                    __LINE__ = 25;
                                    return undefined;
                                  } else {
                                    __LINE__ = 25;
                                    Runtime/*Runtime*/.throwStopIteration();
                                  }
                                  
                              }
                              
                            }
                            
                          } catch(e){
                            Runtime.exceptionHandler(__LINE__, __FILE__, e);
                          }
                        };
                    __LINE__ = 25;
                    return Runtime/*Runtime*/.createGenerator(_mochaGenerator/*_mochaGenerator*/,
                    function () {
                      try {
                        __LINE__ = 25;
                        _yieldState/*_yieldState*/ = -1;
                      } catch(e){
                        Runtime.exceptionHandler(__LINE__, __FILE__, e);
                      }
                    },this);
                  } catch(e){
                    Runtime.exceptionHandler(__LINE__, __FILE__, e);
                  }
                }
                __LINE__ = 32;
                generator/*generator*/ = yieldTest3/*yieldTest3*/();
                
                __LINE__ = 33;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 0,"generator.next() === 0",33,'yield_test.js');
                
                __LINE__ = 34;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 2,"generator.next() === 2",34,'yield_test.js');
                
                __LINE__ = 35;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 4,"generator.next() === 4",35,'yield_test.js');
                
                __LINE__ = 36;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 6,"generator.next() === 6",36,'yield_test.js');
                
                __LINE__ = 37;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 8,"generator.next() === 8",37,'yield_test.js');
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            },
            case3 : function () {
              try {
                function yieldTest4/*yieldTest4*/() {
                  try {
                    __LINE__ = 40;
                    var _mochaIsNewBorn/*_mochaIsNewBorn*/ = true;
                    
                    __LINE__ = 40;
                    var _yieldResult/*_yieldResult*/ = undefined;
                    
                    __LINE__ = 40;
                    var _yieldState/*_yieldState*/ = 0;
                    
                    __LINE__ = 42;
                    var j/*j*/;
                    
                    __LINE__ = 41;
                    var i/*i*/;
                    
                    __LINE__ = 40;
                    var _mochaGenerator/*_mochaGenerator*/ = function (_isYieldSend/*_isYieldSend*/,_isYieldSafe/*_isYieldSafe*/) {
                          try {
                            __LINE__ = 40;
                            if (!_isYieldSend/*_isYieldSend*/){
                              
                              __LINE__ = 40;
                              _mochaIsNewBorn/*_mochaIsNewBorn*/ = false;
                            } else if (_isYieldSend/*_isYieldSend*/ && _mochaIsNewBorn/*_mochaIsNewBorn*/ && arguments[1] !== undefined){
                              
                              __LINE__ = 40;
                              Runtime/*Runtime*/.exceptionHandler('attempt to send to newborn generator.');
                            }
                            
                            __LINE__ = 40;
                            while (1){
                              __LINE__ = 40;
                              switch (_yieldState/*_yieldState*/) {
                                case 0 :
                                  
                                  __LINE__ = 41;
                                  i/*i*/ = 0;
                                  
                                  __LINE__ = 41;
                                  if (!(i/*i*/<10)){
                                    
                                    __LINE__ = 41;
                                    _yieldState/*_yieldState*/ = -1;
                                    __LINE__ = 41;
                                    break;
                                  }
                                case 1 :
                                  
                                  __LINE__ = 42;
                                  j/*j*/ = 0;
                                  
                                  __LINE__ = 42;
                                  if (!(j/*j*/<10)){
                                    
                                    __LINE__ = 42;
                                    _yieldState/*_yieldState*/ = 6;
                                    __LINE__ = 42;
                                    break;
                                  }
                                case 2 :
                                  
                                  __LINE__ = 43;
                                  if (j/*j*/%2 === 0){
                                    
                                    __LINE__ = 43;
                                    _yieldState/*_yieldState*/ = 3;
                                    __LINE__ = 43;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 43;
                                    _yieldState/*_yieldState*/ = 4;
                                    __LINE__ = 43;
                                    break;
                                  }
                                case 3 :
                                  
                                  __LINE__ = 44;
                                  _yieldState/*_yieldState*/ = 4;
                                  __LINE__ = 44;
                                  return j/*j*/;
                                case 4 :
                                  
                                  __LINE__ = 43;
                                  _yieldState/*_yieldState*/ = 5;
                                  __LINE__ = 43;
                                  break;
                                case 5 :
                                  
                                  __LINE__ = 42;
                                  j/*j*/ ++ ;
                                  
                                  __LINE__ = 42;
                                  if (j/*j*/<10){
                                    
                                    __LINE__ = 0;
                                    _yieldState/*_yieldState*/ = 2;
                                    __LINE__ = 42;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState/*_yieldState*/ = 6;
                                  }
                                case 6 :
                                  
                                  __LINE__ = 41;
                                  i/*i*/ ++ ;
                                  
                                  __LINE__ = 41;
                                  if (i/*i*/<10){
                                    
                                    __LINE__ = 0;
                                    _yieldState/*_yieldState*/ = 1;
                                    __LINE__ = 41;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState/*_yieldState*/ = -1;
                                  }
                                case -1 :
                                  
                                  __LINE__ = 40;
                                  if (_isYieldSafe/*_isYieldSafe*/){
                                    __LINE__ = 40;
                                    return undefined;
                                  } else {
                                    __LINE__ = 40;
                                    Runtime/*Runtime*/.throwStopIteration();
                                  }
                                  
                              }
                              
                            }
                            
                          } catch(e){
                            Runtime.exceptionHandler(__LINE__, __FILE__, e);
                          }
                        };
                    __LINE__ = 40;
                    return Runtime/*Runtime*/.createGenerator(_mochaGenerator/*_mochaGenerator*/,
                    function () {
                      try {
                        __LINE__ = 40;
                        _yieldState/*_yieldState*/ = -1;
                      } catch(e){
                        Runtime.exceptionHandler(__LINE__, __FILE__, e);
                      }
                    },this);
                  } catch(e){
                    Runtime.exceptionHandler(__LINE__, __FILE__, e);
                  }
                }
                __LINE__ = 49;
                generator/*generator*/ = yieldTest4/*yieldTest4*/();
                
                __LINE__ = 50;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 0,"generator.next() === 0",50,'yield_test.js');
                
                __LINE__ = 51;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 2,"generator.next() === 2",51,'yield_test.js');
                
                __LINE__ = 52;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 4,"generator.next() === 4",52,'yield_test.js');
                
                __LINE__ = 53;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 6,"generator.next() === 6",53,'yield_test.js');
                
                __LINE__ = 54;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 8,"generator.next() === 8",54,'yield_test.js');
                
                __LINE__ = 56;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 0,"generator.next() === 0",56,'yield_test.js');
                
                __LINE__ = 57;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 2,"generator.next() === 2",57,'yield_test.js');
                
                __LINE__ = 58;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 4,"generator.next() === 4",58,'yield_test.js');
                
                __LINE__ = 59;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 6,"generator.next() === 6",59,'yield_test.js');
                
                __LINE__ = 60;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 8,"generator.next() === 8",60,'yield_test.js');
                
                __LINE__ = 62;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 0,"generator.next() === 0",62,'yield_test.js');
                
                __LINE__ = 63;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 2,"generator.next() === 2",63,'yield_test.js');
                
                __LINE__ = 64;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 4,"generator.next() === 4",64,'yield_test.js');
                
                __LINE__ = 65;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 6,"generator.next() === 6",65,'yield_test.js');
                
                __LINE__ = 66;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 8,"generator.next() === 8",66,'yield_test.js');
                
                __LINE__ = 68;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 0,"generator.next() === 0",68,'yield_test.js');
                
                __LINE__ = 69;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 2,"generator.next() === 2",69,'yield_test.js');
                
                __LINE__ = 70;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 4,"generator.next() === 4",70,'yield_test.js');
                
                __LINE__ = 71;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 6,"generator.next() === 6",71,'yield_test.js');
                
                __LINE__ = 72;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 8,"generator.next() === 8",72,'yield_test.js');
                
                __LINE__ = 74;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 0,"generator.next() === 0",74,'yield_test.js');
                
                __LINE__ = 75;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 2,"generator.next() === 2",75,'yield_test.js');
                
                __LINE__ = 76;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 4,"generator.next() === 4",76,'yield_test.js');
                
                __LINE__ = 77;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 6,"generator.next() === 6",77,'yield_test.js');
                
                __LINE__ = 78;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 8,"generator.next() === 8",78,'yield_test.js');
                
                __LINE__ = 80;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 0,"generator.next() === 0",80,'yield_test.js');
                
                __LINE__ = 81;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 2,"generator.next() === 2",81,'yield_test.js');
                
                __LINE__ = 82;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 4,"generator.next() === 4",82,'yield_test.js');
                
                __LINE__ = 83;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 6,"generator.next() === 6",83,'yield_test.js');
                
                __LINE__ = 84;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 8,"generator.next() === 8",84,'yield_test.js');
                
                __LINE__ = 86;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 0,"generator.next() === 0",86,'yield_test.js');
                
                __LINE__ = 87;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 2,"generator.next() === 2",87,'yield_test.js');
                
                __LINE__ = 88;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 4,"generator.next() === 4",88,'yield_test.js');
                
                __LINE__ = 89;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 6,"generator.next() === 6",89,'yield_test.js');
                
                __LINE__ = 90;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 8,"generator.next() === 8",90,'yield_test.js');
                
                __LINE__ = 92;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 0,"generator.next() === 0",92,'yield_test.js');
                
                __LINE__ = 93;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 2,"generator.next() === 2",93,'yield_test.js');
                
                __LINE__ = 94;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 4,"generator.next() === 4",94,'yield_test.js');
                
                __LINE__ = 95;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 6,"generator.next() === 6",95,'yield_test.js');
                
                __LINE__ = 96;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 8,"generator.next() === 8",96,'yield_test.js');
                
                __LINE__ = 98;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 0,"generator.next() === 0",98,'yield_test.js');
                
                __LINE__ = 99;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 2,"generator.next() === 2",99,'yield_test.js');
                
                __LINE__ = 100;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 4,"generator.next() === 4",100,'yield_test.js');
                
                __LINE__ = 101;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 6,"generator.next() === 6",101,'yield_test.js');
                
                __LINE__ = 102;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 8,"generator.next() === 8",102,'yield_test.js');
                
                __LINE__ = 104;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 0,"generator.next() === 0",104,'yield_test.js');
                
                __LINE__ = 105;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 2,"generator.next() === 2",105,'yield_test.js');
                
                __LINE__ = 106;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 4,"generator.next() === 4",106,'yield_test.js');
                
                __LINE__ = 107;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 6,"generator.next() === 6",107,'yield_test.js');
                
                __LINE__ = 108;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 8,"generator.next() === 8",108,'yield_test.js');
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            },
            case4 : function () {
              try {
                function yieldTest5/*yieldTest5*/() {
                  try {
                    __LINE__ = 111;
                    var _mochaIsNewBorn/*_mochaIsNewBorn*/ = true;
                    
                    __LINE__ = 111;
                    var _yieldResult/*_yieldResult*/ = undefined;
                    
                    __LINE__ = 111;
                    var _yieldState/*_yieldState*/ = 0;
                    
                    __LINE__ = 112;
                    var i/*i*/;
                    
                    __LINE__ = 111;
                    var _mochaGenerator/*_mochaGenerator*/ = function (_isYieldSend/*_isYieldSend*/,_isYieldSafe/*_isYieldSafe*/) {
                          try {
                            __LINE__ = 111;
                            if (!_isYieldSend/*_isYieldSend*/){
                              
                              __LINE__ = 111;
                              _mochaIsNewBorn/*_mochaIsNewBorn*/ = false;
                            } else if (_isYieldSend/*_isYieldSend*/ && _mochaIsNewBorn/*_mochaIsNewBorn*/ && arguments[1] !== undefined){
                              
                              __LINE__ = 111;
                              Runtime/*Runtime*/.exceptionHandler('attempt to send to newborn generator.');
                            }
                            
                            __LINE__ = 111;
                            while (1){
                              __LINE__ = 111;
                              switch (_yieldState/*_yieldState*/) {
                                case 0 :
                                  
                                  __LINE__ = 112;
                                  i/*i*/ = 0;
                                  
                                  __LINE__ = 113;
                                  if (!( ++ i/*i*/<10)){
                                    
                                    __LINE__ = 113;
                                    _yieldState/*_yieldState*/ = -1;
                                    __LINE__ = 113;
                                    break;
                                  }
                                case 1 :
                                  
                                  __LINE__ = 114;
                                  _yieldState/*_yieldState*/ = 2;
                                  __LINE__ = 114;
                                  return i/*i*/;
                                case 2 :
                                  
                                  __LINE__ = 113;
                                  if ( ++ i/*i*/<10){
                                    
                                    __LINE__ = 0;
                                    _yieldState/*_yieldState*/ = 1;
                                    __LINE__ = 113;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState/*_yieldState*/ = -1;
                                  }
                                case -1 :
                                  
                                  __LINE__ = 111;
                                  if (_isYieldSafe/*_isYieldSafe*/){
                                    __LINE__ = 111;
                                    return undefined;
                                  } else {
                                    __LINE__ = 111;
                                    Runtime/*Runtime*/.throwStopIteration();
                                  }
                                  
                              }
                              
                            }
                            
                          } catch(e){
                            Runtime.exceptionHandler(__LINE__, __FILE__, e);
                          }
                        };
                    __LINE__ = 111;
                    return Runtime/*Runtime*/.createGenerator(_mochaGenerator/*_mochaGenerator*/,
                    function () {
                      try {
                        __LINE__ = 111;
                        _yieldState/*_yieldState*/ = -1;
                      } catch(e){
                        Runtime.exceptionHandler(__LINE__, __FILE__, e);
                      }
                    },this);
                  } catch(e){
                    Runtime.exceptionHandler(__LINE__, __FILE__, e);
                  }
                }
                __LINE__ = 118;
                generator/*generator*/ = yieldTest5/*yieldTest5*/();
                
                __LINE__ = 119;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 1,"generator.next() === 1",119,'yield_test.js');
                
                __LINE__ = 120;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 2,"generator.next() === 2",120,'yield_test.js');
                
                __LINE__ = 121;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 3,"generator.next() === 3",121,'yield_test.js');
                
                __LINE__ = 122;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 4,"generator.next() === 4",122,'yield_test.js');
                
                __LINE__ = 123;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 5,"generator.next() === 5",123,'yield_test.js');
                
                __LINE__ = 124;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 6,"generator.next() === 6",124,'yield_test.js');
                
                __LINE__ = 125;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 7,"generator.next() === 7",125,'yield_test.js');
                
                __LINE__ = 126;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 8,"generator.next() === 8",126,'yield_test.js');
                
                __LINE__ = 127;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 9,"generator.next() === 9",127,'yield_test.js');
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            },
            case5 : function () {
              try {
                function yieldTest6/*yieldTest6*/() {
                  try {
                    __LINE__ = 130;
                    var _mochaIsNewBorn/*_mochaIsNewBorn*/ = true;
                    
                    __LINE__ = 130;
                    var _yieldResult/*_yieldResult*/ = undefined;
                    
                    __LINE__ = 130;
                    var _yieldState/*_yieldState*/ = 0;
                    
                    __LINE__ = 131;
                    var i/*i*/;
                    
                    __LINE__ = 130;
                    var _mochaGenerator/*_mochaGenerator*/ = function (_isYieldSend/*_isYieldSend*/,_isYieldSafe/*_isYieldSafe*/) {
                          try {
                            __LINE__ = 130;
                            if (!_isYieldSend/*_isYieldSend*/){
                              
                              __LINE__ = 130;
                              _mochaIsNewBorn/*_mochaIsNewBorn*/ = false;
                            } else if (_isYieldSend/*_isYieldSend*/ && _mochaIsNewBorn/*_mochaIsNewBorn*/ && arguments[1] !== undefined){
                              
                              __LINE__ = 130;
                              Runtime/*Runtime*/.exceptionHandler('attempt to send to newborn generator.');
                            }
                            
                            __LINE__ = 130;
                            while (1){
                              __LINE__ = 130;
                              switch (_yieldState/*_yieldState*/) {
                                case 0 :
                                  
                                  __LINE__ = 131;
                                  i/*i*/ = 0;
                                case 1 :
                                  
                                  __LINE__ = 133;
                                  _yieldState/*_yieldState*/ = 2;
                                  __LINE__ = 133;
                                  return i/*i*/;
                                case 2 :
                                  
                                  __LINE__ = 134;
                                  if ( ++ i/*i*/<10){
                                    
                                    __LINE__ = 0;
                                    _yieldState/*_yieldState*/ = 1;
                                    __LINE__ = 134;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState/*_yieldState*/ = 3;
                                  }
                                case 3 :
                                case -1 :
                                  
                                  __LINE__ = 130;
                                  if (_isYieldSafe/*_isYieldSafe*/){
                                    __LINE__ = 130;
                                    return undefined;
                                  } else {
                                    __LINE__ = 130;
                                    Runtime/*Runtime*/.throwStopIteration();
                                  }
                                  
                              }
                              
                            }
                            
                          } catch(e){
                            Runtime.exceptionHandler(__LINE__, __FILE__, e);
                          }
                        };
                    __LINE__ = 130;
                    return Runtime/*Runtime*/.createGenerator(_mochaGenerator/*_mochaGenerator*/,
                    function () {
                      try {
                        __LINE__ = 130;
                        _yieldState/*_yieldState*/ = -1;
                      } catch(e){
                        Runtime.exceptionHandler(__LINE__, __FILE__, e);
                      }
                    },this);
                  } catch(e){
                    Runtime.exceptionHandler(__LINE__, __FILE__, e);
                  }
                }
                __LINE__ = 137;
                generator/*generator*/ = yieldTest6/*yieldTest6*/();
                
                __LINE__ = 138;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 0,"generator.next() === 0",138,'yield_test.js');
                
                __LINE__ = 139;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 1,"generator.next() === 1",139,'yield_test.js');
                
                __LINE__ = 140;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 2,"generator.next() === 2",140,'yield_test.js');
                
                __LINE__ = 141;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 3,"generator.next() === 3",141,'yield_test.js');
                
                __LINE__ = 142;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 4,"generator.next() === 4",142,'yield_test.js');
                
                __LINE__ = 143;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 5,"generator.next() === 5",143,'yield_test.js');
                
                __LINE__ = 144;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 6,"generator.next() === 6",144,'yield_test.js');
                
                __LINE__ = 145;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 7,"generator.next() === 7",145,'yield_test.js');
                
                __LINE__ = 146;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 8,"generator.next() === 8",146,'yield_test.js');
                
                __LINE__ = 147;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 9,"generator.next() === 9",147,'yield_test.js');
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            },
            case6 : function () {
              try {
                function yieldTest7/*yieldTest7*/() {
                  try {
                    __LINE__ = 150;
                    var _mochaIsNewBorn/*_mochaIsNewBorn*/ = true;
                    
                    __LINE__ = 150;
                    var _yieldResult/*_yieldResult*/ = undefined;
                    
                    __LINE__ = 150;
                    var _yieldState/*_yieldState*/ = 0;
                    
                    __LINE__ = 151;
                    var i/*i*/;
                    
                    __LINE__ = 152;
                    var m/*m*/;
                    
                    __LINE__ = 150;
                    var _mochaGenerator/*_mochaGenerator*/ = function (_isYieldSend/*_isYieldSend*/,_isYieldSafe/*_isYieldSafe*/) {
                          try {
                            __LINE__ = 150;
                            if (!_isYieldSend/*_isYieldSend*/){
                              
                              __LINE__ = 150;
                              _mochaIsNewBorn/*_mochaIsNewBorn*/ = false;
                            } else if (_isYieldSend/*_isYieldSend*/ && _mochaIsNewBorn/*_mochaIsNewBorn*/ && arguments[1] !== undefined){
                              
                              __LINE__ = 150;
                              Runtime/*Runtime*/.exceptionHandler('attempt to send to newborn generator.');
                            }
                            
                            __LINE__ = 150;
                            while (1){
                              __LINE__ = 150;
                              switch (_yieldState/*_yieldState*/) {
                                case 0 :
                                  
                                  __LINE__ = 151;
                                  i/*i*/ = 0;
                                  
                                  __LINE__ = 151;
                                  if (!(i/*i*/<10)){
                                    
                                    __LINE__ = 151;
                                    _yieldState/*_yieldState*/ = -1;
                                    __LINE__ = 151;
                                    break;
                                  }
                                case 1 :
                                  
                                  __LINE__ = 152;
                                  _yieldState/*_yieldState*/ = 2;
                                  __LINE__ = 152;
                                  return i/*i*/;
                                case 2 :
                                  
                                  __LINE__ = 152;
                                  _yieldResult/*_yieldResult*/ = _isYieldSend/*_isYieldSend*/ && arguments.length>2?Runtime/*Runtime*/.toArray(arguments,2)[0] : _isYieldSend/*_isYieldSend*/?i/*i*/ : undefined;
                                  
                                  __LINE__ = 152;
                                  m/*m*/ = _yieldResult/*_yieldResult*/;
                                  
                                  __LINE__ = 153;
                                  if (m/*m*/ === true){
                                    
                                    __LINE__ = 153;
                                    _yieldState/*_yieldState*/ = 3;
                                    __LINE__ = 153;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 153;
                                    _yieldState/*_yieldState*/ = 5;
                                    __LINE__ = 153;
                                    break;
                                  }
                                case 3 :
                                  
                                  __LINE__ = 154;
                                  _yieldState/*_yieldState*/ = 4;
                                  __LINE__ = 154;
                                  return i/*i*/+1;
                                case 4 :
                                  
                                  __LINE__ = 153;
                                  _yieldState/*_yieldState*/ = 9;
                                  __LINE__ = 153;
                                  break;
                                case 5 :
                                  
                                  __LINE__ = 155;
                                  if (m/*m*/ === false){
                                    
                                    __LINE__ = 155;
                                    _yieldState/*_yieldState*/ = 6;
                                    __LINE__ = 155;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 155;
                                    _yieldState/*_yieldState*/ = 8;
                                    __LINE__ = 155;
                                    break;
                                  }
                                case 6 :
                                  
                                  __LINE__ = 156;
                                  _yieldState/*_yieldState*/ = 7;
                                  __LINE__ = 156;
                                  return i/*i*/-1;
                                case 7 :
                                  
                                  __LINE__ = 155;
                                  _yieldState/*_yieldState*/ = 9;
                                  __LINE__ = 155;
                                  break;
                                case 8 :
                                  
                                  __LINE__ = 158;
                                  _yieldState/*_yieldState*/ = 9;
                                  __LINE__ = 158;
                                  return i/*i*/;
                                case 9 :
                                  
                                  __LINE__ = 151;
                                  i/*i*/ ++ ;
                                  
                                  __LINE__ = 151;
                                  if (i/*i*/<10){
                                    
                                    __LINE__ = 0;
                                    _yieldState/*_yieldState*/ = 1;
                                    __LINE__ = 151;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState/*_yieldState*/ = -1;
                                  }
                                case -1 :
                                  
                                  __LINE__ = 150;
                                  if (_isYieldSafe/*_isYieldSafe*/){
                                    __LINE__ = 150;
                                    return undefined;
                                  } else {
                                    __LINE__ = 150;
                                    Runtime/*Runtime*/.throwStopIteration();
                                  }
                                  
                              }
                              
                            }
                            
                          } catch(e){
                            Runtime.exceptionHandler(__LINE__, __FILE__, e);
                          }
                        };
                    __LINE__ = 150;
                    return Runtime/*Runtime*/.createGenerator(_mochaGenerator/*_mochaGenerator*/,
                    function () {
                      try {
                        __LINE__ = 150;
                        _yieldState/*_yieldState*/ = -1;
                      } catch(e){
                        Runtime.exceptionHandler(__LINE__, __FILE__, e);
                      }
                    },this);
                  } catch(e){
                    Runtime.exceptionHandler(__LINE__, __FILE__, e);
                  }
                }
                __LINE__ = 163;
                generator/*generator*/ = yieldTest7/*yieldTest7*/();
                
                __LINE__ = 164;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 0,"generator.next() === 0",164,'yield_test.js');
                
                __LINE__ = 165;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(true) === 1,"generator.send(true) === 1",165,'yield_test.js');
                
                __LINE__ = 166;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(false) === 1,"generator.send(false) === 1",166,'yield_test.js');
                
                __LINE__ = 167;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(true) === 2,"generator.send(true) === 2",167,'yield_test.js');
                
                __LINE__ = 168;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(false) === 2,"generator.send(false) === 2",168,'yield_test.js');
                
                __LINE__ = 169;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(true) === 3,"generator.send(true) === 3",169,'yield_test.js');
                
                __LINE__ = 170;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(true) === 3,"generator.send(true) === 3",170,'yield_test.js');
                
                __LINE__ = 171;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(true) === 4,"generator.send(true) === 4",171,'yield_test.js');
                
                __LINE__ = 172;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(false) === 4,"generator.send(false) === 4",172,'yield_test.js');
                
                __LINE__ = 173;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(true) === 5,"generator.send(true) === 5",173,'yield_test.js');
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            },
            case7 : function () {
              try {
                function yieldTest8/*yieldTest8*/() {
                  try {
                    __LINE__ = 176;
                    var _mochaIsNewBorn/*_mochaIsNewBorn*/ = true;
                    
                    __LINE__ = 176;
                    var _yieldResult/*_yieldResult*/ = undefined;
                    
                    __LINE__ = 176;
                    var _yieldState/*_yieldState*/ = 0;
                    
                    __LINE__ = 179;
                    var j/*j*/;
                    
                    __LINE__ = 177;
                    var i/*i*/;
                    
                    __LINE__ = 178;
                    var m/*m*/;
                    
                    __LINE__ = 176;
                    var _mochaGenerator/*_mochaGenerator*/ = function (_isYieldSend/*_isYieldSend*/,_isYieldSafe/*_isYieldSafe*/) {
                          try {
                            __LINE__ = 176;
                            if (!_isYieldSend/*_isYieldSend*/){
                              
                              __LINE__ = 176;
                              _mochaIsNewBorn/*_mochaIsNewBorn*/ = false;
                            } else if (_isYieldSend/*_isYieldSend*/ && _mochaIsNewBorn/*_mochaIsNewBorn*/ && arguments[1] !== undefined){
                              
                              __LINE__ = 176;
                              Runtime/*Runtime*/.exceptionHandler('attempt to send to newborn generator.');
                            }
                            
                            __LINE__ = 176;
                            while (1){
                              __LINE__ = 176;
                              switch (_yieldState/*_yieldState*/) {
                                case 0 :
                                  
                                  __LINE__ = 177;
                                  i/*i*/ = 0;
                                  
                                  __LINE__ = 177;
                                  if (!(i/*i*/<10)){
                                    
                                    __LINE__ = 177;
                                    _yieldState/*_yieldState*/ = -1;
                                    __LINE__ = 177;
                                    break;
                                  }
                                case 1 :
                                  
                                  __LINE__ = 178;
                                  _yieldState/*_yieldState*/ = 2;
                                  __LINE__ = 178;
                                  return i/*i*/;
                                case 2 :
                                  
                                  __LINE__ = 178;
                                  _yieldResult/*_yieldResult*/ = _isYieldSend/*_isYieldSend*/ && arguments.length>2?Runtime/*Runtime*/.toArray(arguments,2)[0] : _isYieldSend/*_isYieldSend*/?i/*i*/ : undefined;
                                  
                                  __LINE__ = 178;
                                  m/*m*/ = _yieldResult/*_yieldResult*/;
                                  
                                  __LINE__ = 179;
                                  j/*j*/ = 0;
                                  
                                  __LINE__ = 179;
                                  if (!(j/*j*/<10)){
                                    
                                    __LINE__ = 179;
                                    _yieldState/*_yieldState*/ = 11;
                                    __LINE__ = 179;
                                    break;
                                  }
                                case 3 :
                                  
                                  __LINE__ = 180;
                                  if (m/*m*/ === true){
                                    
                                    __LINE__ = 180;
                                    _yieldState/*_yieldState*/ = 4;
                                    __LINE__ = 180;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 180;
                                    _yieldState/*_yieldState*/ = 6;
                                    __LINE__ = 180;
                                    break;
                                  }
                                case 4 :
                                  
                                  __LINE__ = 181;
                                  _yieldState/*_yieldState*/ = 5;
                                  __LINE__ = 181;
                                  return j/*j*/*2;
                                case 5 :
                                  
                                  __LINE__ = 180;
                                  _yieldState/*_yieldState*/ = 10;
                                  __LINE__ = 180;
                                  break;
                                case 6 :
                                  
                                  __LINE__ = 182;
                                  if (m/*m*/ === false){
                                    
                                    __LINE__ = 182;
                                    _yieldState/*_yieldState*/ = 7;
                                    __LINE__ = 182;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 182;
                                    _yieldState/*_yieldState*/ = 9;
                                    __LINE__ = 182;
                                    break;
                                  }
                                case 7 :
                                  
                                  __LINE__ = 183;
                                  _yieldState/*_yieldState*/ = 8;
                                  __LINE__ = 183;
                                  return j/*j*//2;
                                case 8 :
                                  
                                  __LINE__ = 182;
                                  _yieldState/*_yieldState*/ = 10;
                                  __LINE__ = 182;
                                  break;
                                case 9 :
                                  
                                  __LINE__ = 185;
                                  _yieldState/*_yieldState*/ = 10;
                                  __LINE__ = 185;
                                  return j/*j*/;
                                case 10 :
                                  
                                  __LINE__ = 179;
                                  j/*j*/ ++ ;
                                  
                                  __LINE__ = 179;
                                  if (j/*j*/<10){
                                    
                                    __LINE__ = 0;
                                    _yieldState/*_yieldState*/ = 3;
                                    __LINE__ = 179;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState/*_yieldState*/ = 11;
                                  }
                                case 11 :
                                  
                                  __LINE__ = 177;
                                  i/*i*/ ++ ;
                                  
                                  __LINE__ = 177;
                                  if (i/*i*/<10){
                                    
                                    __LINE__ = 0;
                                    _yieldState/*_yieldState*/ = 1;
                                    __LINE__ = 177;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState/*_yieldState*/ = -1;
                                  }
                                case -1 :
                                  
                                  __LINE__ = 176;
                                  if (_isYieldSafe/*_isYieldSafe*/){
                                    __LINE__ = 176;
                                    return undefined;
                                  } else {
                                    __LINE__ = 176;
                                    Runtime/*Runtime*/.throwStopIteration();
                                  }
                                  
                              }
                              
                            }
                            
                          } catch(e){
                            Runtime.exceptionHandler(__LINE__, __FILE__, e);
                          }
                        };
                    __LINE__ = 176;
                    return Runtime/*Runtime*/.createGenerator(_mochaGenerator/*_mochaGenerator*/,
                    function () {
                      try {
                        __LINE__ = 176;
                        _yieldState/*_yieldState*/ = -1;
                      } catch(e){
                        Runtime.exceptionHandler(__LINE__, __FILE__, e);
                      }
                    },this);
                  } catch(e){
                    Runtime.exceptionHandler(__LINE__, __FILE__, e);
                  }
                }
                __LINE__ = 192;
                generator/*generator*/ = yieldTest8/*yieldTest8*/();
                
                __LINE__ = 193;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 0,"generator.next() === 0",193,'yield_test.js');
                
                __LINE__ = 194;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(true) === 0,"generator.send(true) === 0",194,'yield_test.js');
                
                __LINE__ = 195;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(false) === 2,"generator.send(false) === 2",195,'yield_test.js');
                
                __LINE__ = 196;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(true) === 4,"generator.send(true) === 4",196,'yield_test.js');
                
                __LINE__ = 197;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(false) === 6,"generator.send(false) === 6",197,'yield_test.js');
                
                __LINE__ = 198;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(true) === 8,"generator.send(true) === 8",198,'yield_test.js');
                
                __LINE__ = 199;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(true) === 10,"generator.send(true) === 10",199,'yield_test.js');
                
                __LINE__ = 200;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(true) === 12,"generator.send(true) === 12",200,'yield_test.js');
                
                __LINE__ = 201;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(false) === 14,"generator.send(false) === 14",201,'yield_test.js');
                
                __LINE__ = 202;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(true) === 16,"generator.send(true) === 16",202,'yield_test.js');
                
                __LINE__ = 203;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(true) === 18,"generator.send(true) === 18",203,'yield_test.js');
                
                __LINE__ = 204;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(false) === 1,"generator.send(false) === 1",204,'yield_test.js');
                
                __LINE__ = 205;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(true) === 0,"generator.send(true) === 0",205,'yield_test.js');
                
                __LINE__ = 206;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(false) === 2,"generator.send(false) === 2",206,'yield_test.js');
                
                __LINE__ = 207;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(true) === 4,"generator.send(true) === 4",207,'yield_test.js');
                
                __LINE__ = 208;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(true) === 6,"generator.send(true) === 6",208,'yield_test.js');
                
                __LINE__ = 209;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(true) === 8,"generator.send(true) === 8",209,'yield_test.js');
                
                __LINE__ = 210;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(false) === 10,"generator.send(false) === 10",210,'yield_test.js');
                
                __LINE__ = 211;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(true) === 12,"generator.send(true) === 12",211,'yield_test.js');
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            },
            case8 : function () {
              try {
                function yieldTest9/*yieldTest9*/() {
                  try {
                    __LINE__ = 215;
                    var _mochaIsNewBorn/*_mochaIsNewBorn*/ = true;
                    
                    __LINE__ = 215;
                    var _yieldResult/*_yieldResult*/ = undefined;
                    
                    __LINE__ = 215;
                    var _yieldState/*_yieldState*/ = 0;
                    
                    __LINE__ = 217;
                    var j/*j*/;
                    
                    __LINE__ = 216;
                    var i/*i*/;
                    
                    __LINE__ = 218;
                    var m/*m*/;
                    
                    __LINE__ = 215;
                    var _mochaGenerator/*_mochaGenerator*/ = function (_isYieldSend/*_isYieldSend*/,_isYieldSafe/*_isYieldSafe*/) {
                          try {
                            __LINE__ = 215;
                            if (!_isYieldSend/*_isYieldSend*/){
                              
                              __LINE__ = 215;
                              _mochaIsNewBorn/*_mochaIsNewBorn*/ = false;
                            } else if (_isYieldSend/*_isYieldSend*/ && _mochaIsNewBorn/*_mochaIsNewBorn*/ && arguments[1] !== undefined){
                              
                              __LINE__ = 215;
                              Runtime/*Runtime*/.exceptionHandler('attempt to send to newborn generator.');
                            }
                            
                            __LINE__ = 215;
                            while (1){
                              __LINE__ = 215;
                              switch (_yieldState/*_yieldState*/) {
                                case 0 :
                                  
                                  __LINE__ = 216;
                                  i/*i*/ = 0;
                                  
                                  __LINE__ = 216;
                                  if (!(i/*i*/<10)){
                                    
                                    __LINE__ = 216;
                                    _yieldState/*_yieldState*/ = -1;
                                    __LINE__ = 216;
                                    break;
                                  }
                                case 1 :
                                  
                                  __LINE__ = 217;
                                  j/*j*/ = 0;
                                  
                                  __LINE__ = 217;
                                  if (!(j/*j*/<10)){
                                    
                                    __LINE__ = 217;
                                    _yieldState/*_yieldState*/ = 11;
                                    __LINE__ = 217;
                                    break;
                                  }
                                case 2 :
                                  
                                  __LINE__ = 218;
                                  _yieldState/*_yieldState*/ = 3;
                                  __LINE__ = 218;
                                  return i/*i*/;
                                case 3 :
                                  
                                  __LINE__ = 218;
                                  _yieldResult/*_yieldResult*/ = _isYieldSend/*_isYieldSend*/ && arguments.length>2?Runtime/*Runtime*/.toArray(arguments,2)[0] : _isYieldSend/*_isYieldSend*/?i/*i*/ : undefined;
                                  
                                  __LINE__ = 218;
                                  m/*m*/ = _yieldResult/*_yieldResult*/;
                                  
                                  __LINE__ = 219;
                                  if (m/*m*/ === true){
                                    
                                    __LINE__ = 219;
                                    _yieldState/*_yieldState*/ = 4;
                                    __LINE__ = 219;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 219;
                                    _yieldState/*_yieldState*/ = 6;
                                    __LINE__ = 219;
                                    break;
                                  }
                                case 4 :
                                  
                                  __LINE__ = 220;
                                  _yieldState/*_yieldState*/ = 5;
                                  __LINE__ = 220;
                                  return j/*j*/*2;
                                case 5 :
                                  
                                  __LINE__ = 219;
                                  _yieldState/*_yieldState*/ = 10;
                                  __LINE__ = 219;
                                  break;
                                case 6 :
                                  
                                  __LINE__ = 221;
                                  if (m/*m*/ === false){
                                    
                                    __LINE__ = 221;
                                    _yieldState/*_yieldState*/ = 7;
                                    __LINE__ = 221;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 221;
                                    _yieldState/*_yieldState*/ = 9;
                                    __LINE__ = 221;
                                    break;
                                  }
                                case 7 :
                                  
                                  __LINE__ = 222;
                                  _yieldState/*_yieldState*/ = 8;
                                  __LINE__ = 222;
                                  return j/*j*//2;
                                case 8 :
                                  
                                  __LINE__ = 221;
                                  _yieldState/*_yieldState*/ = 10;
                                  __LINE__ = 221;
                                  break;
                                case 9 :
                                  
                                  __LINE__ = 224;
                                  _yieldState/*_yieldState*/ = 10;
                                  __LINE__ = 224;
                                  return j/*j*/;
                                case 10 :
                                  
                                  __LINE__ = 217;
                                  j/*j*/ ++ ;
                                  
                                  __LINE__ = 217;
                                  if (j/*j*/<10){
                                    
                                    __LINE__ = 0;
                                    _yieldState/*_yieldState*/ = 2;
                                    __LINE__ = 217;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState/*_yieldState*/ = 11;
                                  }
                                case 11 :
                                  
                                  __LINE__ = 216;
                                  i/*i*/ ++ ;
                                  
                                  __LINE__ = 216;
                                  if (i/*i*/<10){
                                    
                                    __LINE__ = 0;
                                    _yieldState/*_yieldState*/ = 1;
                                    __LINE__ = 216;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState/*_yieldState*/ = -1;
                                  }
                                case -1 :
                                  
                                  __LINE__ = 215;
                                  if (_isYieldSafe/*_isYieldSafe*/){
                                    __LINE__ = 215;
                                    return undefined;
                                  } else {
                                    __LINE__ = 215;
                                    Runtime/*Runtime*/.throwStopIteration();
                                  }
                                  
                              }
                              
                            }
                            
                          } catch(e){
                            Runtime.exceptionHandler(__LINE__, __FILE__, e);
                          }
                        };
                    __LINE__ = 215;
                    return Runtime/*Runtime*/.createGenerator(_mochaGenerator/*_mochaGenerator*/,
                    function () {
                      try {
                        __LINE__ = 215;
                        _yieldState/*_yieldState*/ = -1;
                      } catch(e){
                        Runtime.exceptionHandler(__LINE__, __FILE__, e);
                      }
                    },this);
                  } catch(e){
                    Runtime.exceptionHandler(__LINE__, __FILE__, e);
                  }
                }
                __LINE__ = 231;
                generator/*generator*/ = yieldTest9/*yieldTest9*/();
                
                __LINE__ = 232;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 0,"generator.next() === 0",232,'yield_test.js');
                
                __LINE__ = 233;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(true) === 0,"generator.send(true) === 0",233,'yield_test.js');
                
                __LINE__ = 234;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(false) === 0,"generator.send(false) === 0",234,'yield_test.js');
                
                __LINE__ = 235;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(true) === 2,"generator.send(true) === 2",235,'yield_test.js');
                
                __LINE__ = 236;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(false) === 0,"generator.send(false) === 0",236,'yield_test.js');
                
                __LINE__ = 237;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(true) === 4,"generator.send(true) === 4",237,'yield_test.js');
                
                __LINE__ = 238;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(true) === 0,"generator.send(true) === 0",238,'yield_test.js');
                
                __LINE__ = 239;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(true) === 6,"generator.send(true) === 6",239,'yield_test.js');
                
                __LINE__ = 240;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(false) === 0,"generator.send(false) === 0",240,'yield_test.js');
                
                __LINE__ = 241;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(true) === 8,"generator.send(true) === 8",241,'yield_test.js');
                
                __LINE__ = 242;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(true) === 0,"generator.send(true) === 0",242,'yield_test.js');
                
                __LINE__ = 243;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(false) === 2.5,"generator.send(false) === 2.5",243,'yield_test.js');
                
                __LINE__ = 244;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(true) === 0,"generator.send(true) === 0",244,'yield_test.js');
                
                __LINE__ = 245;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(false) === 3,"generator.send(false) === 3",245,'yield_test.js');
                
                __LINE__ = 246;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(true) === 0,"generator.send(true) === 0",246,'yield_test.js');
                
                __LINE__ = 247;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(true) === 14,"generator.send(true) === 14",247,'yield_test.js');
                
                __LINE__ = 248;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(true) === 0,"generator.send(true) === 0",248,'yield_test.js');
                
                __LINE__ = 249;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(false) === 4,"generator.send(false) === 4",249,'yield_test.js');
                
                __LINE__ = 250;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(true) === 0,"generator.send(true) === 0",250,'yield_test.js');
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            },
            case9 : function () {
              try {
                function yieldTest10/*yieldTest10*/() {
                  try {
                    __LINE__ = 254;
                    var _mochaIsNewBorn/*_mochaIsNewBorn*/ = true;
                    
                    __LINE__ = 254;
                    var _yieldResult/*_yieldResult*/ = undefined;
                    
                    __LINE__ = 254;
                    var _yieldState/*_yieldState*/ = 0;
                    
                    __LINE__ = 254;
                    var _mochaFinallyCache/*_mochaFinallyCache*/;
                    
                    __LINE__ = 254;
                    var _mochaCatchCache/*_mochaCatchCache*/;
                    
                    __LINE__ = 256;
                    var i/*i*/;
                    
                    __LINE__ = 258;
                    var m/*m*/;
                    
                    __LINE__ = 255;
                    var flg/*flg*/;
                    
                    __LINE__ = 254;
                    var _mochaGenerator/*_mochaGenerator*/ = function (_isYieldSend/*_isYieldSend*/,_isYieldSafe/*_isYieldSafe*/) {
                          try {
                            __LINE__ = 254;
                            if (!_isYieldSend/*_isYieldSend*/){
                              
                              __LINE__ = 254;
                              _mochaIsNewBorn/*_mochaIsNewBorn*/ = false;
                            } else if (_isYieldSend/*_isYieldSend*/ && _mochaIsNewBorn/*_mochaIsNewBorn*/ && arguments[1] !== undefined){
                              
                              __LINE__ = 254;
                              Runtime/*Runtime*/.exceptionHandler('attempt to send to newborn generator.');
                            }
                            
                            __LINE__ = 254;
                            while (1){
                              try {
                                __LINE__ = 254;
                                switch (_yieldState/*_yieldState*/) {
                                  case 0 :
                                    
                                    __LINE__ = 255;
                                    flg/*flg*/ = false;
                                    
                                    __LINE__ = 256;
                                    i/*i*/ = 0;
                                    
                                    __LINE__ = 256;
                                    if (!(i/*i*/<10)){
                                      
                                      __LINE__ = 256;
                                      _yieldState/*_yieldState*/ = -1;
                                      __LINE__ = 256;
                                      break;
                                    }
                                  case 1 :
                                    
                                    __LINE__ = 259;
                                    _yieldState/*_yieldState*/ = 2;
                                    
                                    __LINE__ = 257;
                                    _mochaCatchCache/*_mochaCatchCache*/ = function (e/*e*/) {
                                      try {
                                        __LINE__ = 257;
                                        _yieldState/*_yieldState*/ = 3;
                                      } catch(e){
                                        Runtime.exceptionHandler(__LINE__, __FILE__, e);
                                      }
                                    };
                                    
                                    __LINE__ = 257;
                                    _mochaFinallyCache/*_mochaFinallyCache*/ = function () {
                                      try {
                                        flg/*flg*/ = true
                                      } catch(e){
                                        Runtime.exceptionHandler(__LINE__, __FILE__, e);
                                      }
                                    };
                                    
                                    __LINE__ = 258;
                                    m/*m*/ = (flg/*flg*/)?1 : 0;
                                    __LINE__ = 259;
                                    return m/*m*/;
                                  case 2 :
                                    
                                    __LINE__ = 260;
                                    ddddd();
                                    
                                    __LINE__ = 254;
                                    _mochaCatchCache/*_mochaCatchCache*/ = undefined;
                                    
                                    __LINE__ = 254;
                                    _mochaFinallyCache/*_mochaFinallyCache*/ = undefined;
                                  case 3 :
                                    
                                    __LINE__ = 256;
                                    i/*i*/ ++ ;
                                    
                                    __LINE__ = 256;
                                    if (i/*i*/<10){
                                      
                                      __LINE__ = 0;
                                      _yieldState/*_yieldState*/ = 1;
                                      __LINE__ = 256;
                                      break;
                                    } else {
                                      
                                      __LINE__ = 0;
                                      _yieldState/*_yieldState*/ = -1;
                                    }
                                  case -1 :
                                    
                                    __LINE__ = 254;
                                    if (_isYieldSafe/*_isYieldSafe*/){
                                      __LINE__ = 254;
                                      return undefined;
                                    } else {
                                      __LINE__ = 254;
                                      Runtime/*Runtime*/.throwStopIteration();
                                    }
                                    
                                }
                                
                              } catch(_mochaException){
                                __LINE__ = 254;
                                if (_mochaCatchCache/*_mochaCatchCache*/){
                                  
                                  __LINE__ = 254;
                                  var _mochaLocalTmp0/*_mochaLocalTmp0*/ = _mochaCatchCache/*_mochaCatchCache*/(_mochaException);
                                  
                                  __LINE__ = 254;
                                  if (_mochaLocalTmp0/*_mochaLocalTmp0*/ !== undefined){
                                    __LINE__ = 254;
                                    return _mochaLocalTmp0/*_mochaLocalTmp0*/;
                                  }
                                  
                                } else {
                                  __LINE__ = 254;
                                  Runtime/*Runtime*/.throwException(_mochaException);
                                }
                                
                              } finally {
                                __LINE__ = 254;
                                if (_mochaFinallyCache/*_mochaFinallyCache*/){
                                  
                                  __LINE__ = 254;
                                  var _mochaLocalTmp1 = _mochaFinallyCache/*_mochaFinallyCache*/();
                                  
                                  __LINE__ = 254;
                                  if (_mochaLocalTmp1 !== undefined){
                                    __LINE__ = 254;
                                    return _mochaLocalTmp1;
                                  }
                                  
                                }
                                
                              }
                              
                            }
                            
                          } catch(e){
                            Runtime.exceptionHandler(__LINE__, __FILE__, e);
                          }
                        };
                    __LINE__ = 254;
                    return Runtime/*Runtime*/.createGenerator(_mochaGenerator/*_mochaGenerator*/,
                    function () {
                      try {
                        __LINE__ = 254;
                        _yieldState/*_yieldState*/ = -1;
                        
                        __LINE__ = 254;
                        if (_mochaFinallyCache/*_mochaFinallyCache*/){
                          __LINE__ = 254;
                          _mochaFinallyCache/*_mochaFinallyCache*/();
                        }
                        
                      } catch(e){
                        Runtime.exceptionHandler(__LINE__, __FILE__, e);
                      }
                    },this);
                  } catch(e){
                    Runtime.exceptionHandler(__LINE__, __FILE__, e);
                  }
                }
                __LINE__ = 267;
                generator/*generator*/ = yieldTest10/*yieldTest10*/();
                
                __LINE__ = 268;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 0,"generator.next() === 0",268,'yield_test.js');
                
                __LINE__ = 269;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 1,"generator.next() === 1",269,'yield_test.js');
                
                __LINE__ = 270;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 1,"generator.next() === 1",270,'yield_test.js');
                
                __LINE__ = 271;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 1,"generator.next() === 1",271,'yield_test.js');
                
                __LINE__ = 272;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.next() === 1,"generator.next() === 1",272,'yield_test.js');
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            },
            case10 : function () {
              try {
                function yieldTest11/*yieldTest11*/() {
                  try {
                    __LINE__ = 275;
                    var _mochaIsNewBorn/*_mochaIsNewBorn*/ = true;
                    
                    __LINE__ = 275;
                    var _yieldResult/*_yieldResult*/ = undefined;
                    
                    __LINE__ = 275;
                    var _yieldState/*_yieldState*/ = 0;
                    
                    __LINE__ = 276;
                    var i/*i*/;
                    
                    __LINE__ = 277;
                    var type/*type*/;
                    
                    __LINE__ = 275;
                    var _mochaGenerator/*_mochaGenerator*/ = function (_isYieldSend/*_isYieldSend*/,_isYieldSafe/*_isYieldSafe*/) {
                          try {
                            __LINE__ = 275;
                            if (!_isYieldSend/*_isYieldSend*/){
                              
                              __LINE__ = 275;
                              _mochaIsNewBorn/*_mochaIsNewBorn*/ = false;
                            } else if (_isYieldSend/*_isYieldSend*/ && _mochaIsNewBorn/*_mochaIsNewBorn*/ && arguments[1] !== undefined){
                              
                              __LINE__ = 275;
                              Runtime/*Runtime*/.exceptionHandler('attempt to send to newborn generator.');
                            }
                            
                            __LINE__ = 275;
                            while (1){
                              __LINE__ = 275;
                              switch (_yieldState/*_yieldState*/) {
                                case 0 :
                                  
                                  __LINE__ = 276;
                                  i/*i*/ = 0;
                                  
                                  __LINE__ = 276;
                                  if (!(i/*i*/<10)){
                                    
                                    __LINE__ = 276;
                                    _yieldState/*_yieldState*/ = -1;
                                    __LINE__ = 276;
                                    break;
                                  }
                                case 1 :
                                  
                                  __LINE__ = 277;
                                  _yieldState/*_yieldState*/ = 2;
                                  __LINE__ = 277;
                                  return ;
                                case 2 :
                                  
                                  __LINE__ = 277;
                                  _yieldResult/*_yieldResult*/ = _isYieldSend/*_isYieldSend*/ && arguments.length>2?Runtime/*Runtime*/.toArray(arguments,2)[0] : undefined;
                                  
                                  __LINE__ = 277;
                                  type/*type*/ = _yieldResult/*_yieldResult*/;
                                  
                                  __LINE__ = 278;
                                  switch (type/*type*/) {
                                    case 0 :
                                      
                                      __LINE__ = 278;
                                      _yieldState/*_yieldState*/ = 3;
                                      __LINE__ = 279;
                                      break;
                                    case 2 :
                                      
                                      __LINE__ = 278;
                                      _yieldState/*_yieldState*/ = 4;
                                      __LINE__ = 281;
                                      break;
                                    case 3 :
                                      
                                      __LINE__ = 278;
                                      _yieldState/*_yieldState*/ = 5;
                                      __LINE__ = 283;
                                      break;
                                    default :
                                      
                                      __LINE__ = 278;
                                      _yieldState/*_yieldState*/ = 6;
                                      __LINE__ = 285;
                                      break;
                                      
                                  }
                                  __LINE__ = 278;
                                  break;
                                case 3 :
                                  
                                  __LINE__ = 278;
                                  _yieldState/*_yieldState*/ = 7;
                                  __LINE__ = 280;
                                  return 200;
                                case 4 :
                                  
                                  __LINE__ = 278;
                                  _yieldState/*_yieldState*/ = 7;
                                  __LINE__ = 282;
                                  return 400;
                                case 5 :
                                  
                                  __LINE__ = 278;
                                  _yieldState/*_yieldState*/ = 7;
                                  __LINE__ = 284;
                                  return 600;
                                case 6 :
                                  
                                  __LINE__ = 278;
                                  _yieldState/*_yieldState*/ = 7;
                                  __LINE__ = 286;
                                  return 700;
                                case 7 :
                                  
                                  __LINE__ = 276;
                                  i/*i*/ ++ ;
                                  
                                  __LINE__ = 276;
                                  if (i/*i*/<10){
                                    
                                    __LINE__ = 0;
                                    _yieldState/*_yieldState*/ = 1;
                                    __LINE__ = 276;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState/*_yieldState*/ = -1;
                                  }
                                case -1 :
                                  
                                  __LINE__ = 275;
                                  if (_isYieldSafe/*_isYieldSafe*/){
                                    __LINE__ = 275;
                                    return undefined;
                                  } else {
                                    __LINE__ = 275;
                                    Runtime/*Runtime*/.throwStopIteration();
                                  }
                                  
                              }
                              
                            }
                            
                          } catch(e){
                            Runtime.exceptionHandler(__LINE__, __FILE__, e);
                          }
                        };
                    __LINE__ = 275;
                    return Runtime/*Runtime*/.createGenerator(_mochaGenerator/*_mochaGenerator*/,
                    function () {
                      try {
                        __LINE__ = 275;
                        _yieldState/*_yieldState*/ = -1;
                      } catch(e){
                        Runtime.exceptionHandler(__LINE__, __FILE__, e);
                      }
                    },this);
                  } catch(e){
                    Runtime.exceptionHandler(__LINE__, __FILE__, e);
                  }
                }
                __LINE__ = 290;
                generator/*generator*/ = yieldTest11/*yieldTest11*/();
                
                __LINE__ = 291;
                generator/*generator*/.next();
                
                __LINE__ = 292;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(0) === 200,"generator.send(0) === 200",292,'yield_test.js');
                
                __LINE__ = 293;
                generator/*generator*/.next();
                
                __LINE__ = 294;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(2) === 400,"generator.send(2) === 400",294,'yield_test.js');
                
                __LINE__ = 295;
                generator/*generator*/.next();
                
                __LINE__ = 296;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(3) === 600,"generator.send(3) === 600",296,'yield_test.js');
                
                __LINE__ = 297;
                generator/*generator*/.next();
                
                __LINE__ = 298;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(null) === 700,"generator.send(null) === 700",298,'yield_test.js');
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            },
            case11 : function () {
              try {
                function yieldTest12/*yieldTest12*/() {
                  try {
                    __LINE__ = 302;
                    var _mochaIsNewBorn/*_mochaIsNewBorn*/ = true;
                    
                    __LINE__ = 302;
                    var _yieldResult/*_yieldResult*/ = undefined;
                    
                    __LINE__ = 302;
                    var _yieldState/*_yieldState*/ = 0;
                    
                    __LINE__ = 303;
                    var i/*i*/;
                    
                    __LINE__ = 304;
                    var type/*type*/;
                    
                    __LINE__ = 302;
                    var _mochaGenerator/*_mochaGenerator*/ = function (_isYieldSend/*_isYieldSend*/,_isYieldSafe/*_isYieldSafe*/) {
                          try {
                            __LINE__ = 302;
                            if (!_isYieldSend/*_isYieldSend*/){
                              
                              __LINE__ = 302;
                              _mochaIsNewBorn/*_mochaIsNewBorn*/ = false;
                            } else if (_isYieldSend/*_isYieldSend*/ && _mochaIsNewBorn/*_mochaIsNewBorn*/ && arguments[1] !== undefined){
                              
                              __LINE__ = 302;
                              Runtime/*Runtime*/.exceptionHandler('attempt to send to newborn generator.');
                            }
                            
                            __LINE__ = 302;
                            while (1){
                              __LINE__ = 302;
                              switch (_yieldState/*_yieldState*/) {
                                case 0 :
                                  
                                  __LINE__ = 303;
                                  i/*i*/ = 0;
                                  
                                  __LINE__ = 303;
                                  if (!(i/*i*/<15)){
                                    
                                    __LINE__ = 303;
                                    _yieldState/*_yieldState*/ = -1;
                                    __LINE__ = 303;
                                    break;
                                  }
                                case 1 :
                                  
                                  __LINE__ = 304;
                                  _yieldState/*_yieldState*/ = 2;
                                  __LINE__ = 304;
                                  return ;
                                case 2 :
                                  
                                  __LINE__ = 304;
                                  _yieldResult/*_yieldResult*/ = _isYieldSend/*_isYieldSend*/ && arguments.length>2?Runtime/*Runtime*/.toArray(arguments,2)[0] : undefined;
                                  
                                  __LINE__ = 304;
                                  type/*type*/ = _yieldResult/*_yieldResult*/;
                                  
                                  __LINE__ = 305;
                                  switch (type/*type*/) {
                                    case 4 :
                                    case 0 :
                                      
                                      __LINE__ = 305;
                                      _yieldState/*_yieldState*/ = 3;
                                      __LINE__ = 307;
                                      break;
                                    case 5 :
                                      
                                      __LINE__ = 305;
                                      _yieldState/*_yieldState*/ = 7;
                                      __LINE__ = 309;
                                      break;
                                    case 6 :
                                    case 2 :
                                      
                                      __LINE__ = 305;
                                      _yieldState/*_yieldState*/ = 4;
                                      __LINE__ = 312;
                                      break;
                                    case 3 :
                                      
                                      __LINE__ = 305;
                                      _yieldState/*_yieldState*/ = 5;
                                      __LINE__ = 314;
                                      break;
                                    default :
                                      
                                      __LINE__ = 305;
                                      _yieldState/*_yieldState*/ = 6;
                                      __LINE__ = 316;
                                      break;
                                      
                                  }
                                  __LINE__ = 305;
                                  break;
                                case 3 :
                                  
                                  __LINE__ = 305;
                                  _yieldState/*_yieldState*/ = 8;
                                  __LINE__ = 308;
                                  return 200;
                                case 4 :
                                  
                                  __LINE__ = 305;
                                  _yieldState/*_yieldState*/ = 8;
                                  __LINE__ = 313;
                                  return 400;
                                case 5 :
                                  
                                  __LINE__ = 305;
                                  _yieldState/*_yieldState*/ = 8;
                                  __LINE__ = 315;
                                  return 600;
                                case 6 :
                                  
                                  __LINE__ = 305;
                                  _yieldState/*_yieldState*/ = 8;
                                  __LINE__ = 317;
                                  return 700;
                                case 7 :
                                  
                                  __LINE__ = 305;
                                  _yieldState/*_yieldState*/ = 8;
                                  __LINE__ = 309;
                                  break;
                                case 8 :
                                  
                                  __LINE__ = 303;
                                  i/*i*/ ++ ;
                                  
                                  __LINE__ = 303;
                                  if (i/*i*/<15){
                                    
                                    __LINE__ = 0;
                                    _yieldState/*_yieldState*/ = 1;
                                    __LINE__ = 303;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState/*_yieldState*/ = -1;
                                  }
                                case -1 :
                                  
                                  __LINE__ = 302;
                                  if (_isYieldSafe/*_isYieldSafe*/){
                                    __LINE__ = 302;
                                    return undefined;
                                  } else {
                                    __LINE__ = 302;
                                    Runtime/*Runtime*/.throwStopIteration();
                                  }
                                  
                              }
                              
                            }
                            
                          } catch(e){
                            Runtime.exceptionHandler(__LINE__, __FILE__, e);
                          }
                        };
                    __LINE__ = 302;
                    return Runtime/*Runtime*/.createGenerator(_mochaGenerator/*_mochaGenerator*/,
                    function () {
                      try {
                        __LINE__ = 302;
                        _yieldState/*_yieldState*/ = -1;
                      } catch(e){
                        Runtime.exceptionHandler(__LINE__, __FILE__, e);
                      }
                    },this);
                  } catch(e){
                    Runtime.exceptionHandler(__LINE__, __FILE__, e);
                  }
                }
                __LINE__ = 321;
                generator/*generator*/ = yieldTest12/*yieldTest12*/();
                
                __LINE__ = 322;
                generator/*generator*/.next();
                
                __LINE__ = 323;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(0) === 200,"generator.send(0) === 200",323,'yield_test.js');
                
                __LINE__ = 324;
                generator/*generator*/.next();
                
                __LINE__ = 325;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(4) === 200,"generator.send(4) === 200",325,'yield_test.js');
                
                __LINE__ = 326;
                generator/*generator*/.next();
                
                __LINE__ = 327;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(2) === 400,"generator.send(2) === 400",327,'yield_test.js');
                
                __LINE__ = 328;
                generator/*generator*/.next();
                
                __LINE__ = 329;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(5) === undefined,"generator.send(5) === undefined",329,'yield_test.js');
                
                __LINE__ = 330;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(3) === 600,"generator.send(3) === 600",330,'yield_test.js');
                
                __LINE__ = 331;
                generator/*generator*/.next();
                
                __LINE__ = 332;
                Runtime/*Runtime*/.assert(true,generator/*generator*/.send(null) === 700,"generator.send(null) === 700",332,'yield_test.js');
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            },
            case12 : function () {
              try {
                function yieldTest13/*yieldTest13*/() {
                  try {
                    __LINE__ = 336;
                    var _mochaIsNewBorn/*_mochaIsNewBorn*/ = true;
                    
                    __LINE__ = 336;
                    var _yieldResult/*_yieldResult*/ = undefined;
                    
                    __LINE__ = 336;
                    var _yieldState/*_yieldState*/ = 0;
                    
                    __LINE__ = 338;
                    var length/*length*/;
                    
                    __LINE__ = 338;
                    var _mochaLocalTmp4/*_mochaLocalTmp4*/;
                    
                    __LINE__ = 338;
                    var i/*i*/;
                    
                    __LINE__ = 337;
                    var obj/*obj*/;
                    
                    __LINE__ = 338;
                    var _mochaLocalTmp3/*_mochaLocalTmp3*/ = [];
                    
                    __LINE__ = 336;
                    var _mochaGenerator/*_mochaGenerator*/ = function (_isYieldSend/*_isYieldSend*/,_isYieldSafe/*_isYieldSafe*/) {
                          try {
                            __LINE__ = 336;
                            if (!_isYieldSend/*_isYieldSend*/){
                              
                              __LINE__ = 336;
                              _mochaIsNewBorn/*_mochaIsNewBorn*/ = false;
                            } else if (_isYieldSend/*_isYieldSend*/ && _mochaIsNewBorn/*_mochaIsNewBorn*/ && arguments[1] !== undefined){
                              
                              __LINE__ = 336;
                              Runtime/*Runtime*/.exceptionHandler('attempt to send to newborn generator.');
                            }
                            
                            __LINE__ = 336;
                            while (1){
                              __LINE__ = 336;
                              switch (_yieldState/*_yieldState*/) {
                                case 0 :
                                  
                                  __LINE__ = 337;
                                  obj/*obj*/ =  {
                                    x : 200,
                                    y : 300,
                                    z : 400
                                  };
                                  
                                  __LINE__ = 338;
                                  for (var _mochaLocalTmp2/*_mochaLocalTmp2*/ in obj/*obj*/){
                                    
                                    __LINE__ = 338;
                                    _mochaLocalTmp3/*_mochaLocalTmp3*/.push(_mochaLocalTmp2/*_mochaLocalTmp2*/);
                                  }
                                  
                                  __LINE__ = 338;
                                  _mochaLocalTmp4/*_mochaLocalTmp4*/ = 0;
                                  
                                  __LINE__ = 338;
                                  length/*length*/ = _mochaLocalTmp3/*_mochaLocalTmp3*/.length;
                                  
                                  __LINE__ = 338;
                                  if (!(_mochaLocalTmp4/*_mochaLocalTmp4*/<length/*length*/)){
                                    
                                    __LINE__ = 338;
                                    _yieldState/*_yieldState*/ = -1;
                                    __LINE__ = 338;
                                    break;
                                  }
                                case 1 :
                                  
                                  __LINE__ = 339;
                                  _yieldState/*_yieldState*/ = 2;
                                  
                                  __LINE__ = 338;
                                  i/*i*/ = _mochaLocalTmp3/*_mochaLocalTmp3*/[_mochaLocalTmp4/*_mochaLocalTmp4*/];
                                  __LINE__ = 339;
                                  return [i/*i*/,obj/*obj*/[i/*i*/]];
                                case 2 :
                                  
                                  __LINE__ = 338;
                                   ++ _mochaLocalTmp4/*_mochaLocalTmp4*/;
                                  
                                  __LINE__ = 338;
                                  if (_mochaLocalTmp4/*_mochaLocalTmp4*/<length/*length*/){
                                    
                                    __LINE__ = 0;
                                    _yieldState/*_yieldState*/ = 1;
                                    __LINE__ = 338;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState/*_yieldState*/ = -1;
                                  }
                                case -1 :
                                  
                                  __LINE__ = 336;
                                  if (_isYieldSafe/*_isYieldSafe*/){
                                    __LINE__ = 336;
                                    return undefined;
                                  } else {
                                    __LINE__ = 336;
                                    Runtime/*Runtime*/.throwStopIteration();
                                  }
                                  
                              }
                              
                            }
                            
                          } catch(e){
                            Runtime.exceptionHandler(__LINE__, __FILE__, e);
                          }
                        };
                    __LINE__ = 336;
                    return Runtime/*Runtime*/.createGenerator(_mochaGenerator/*_mochaGenerator*/,
                    function () {
                      try {
                        __LINE__ = 336;
                        _yieldState/*_yieldState*/ = -1;
                      } catch(e){
                        Runtime.exceptionHandler(__LINE__, __FILE__, e);
                      }
                    },this);
                  } catch(e){
                    Runtime.exceptionHandler(__LINE__, __FILE__, e);
                  }
                }
                __LINE__ = 343;
                generator/*generator*/ = yieldTest13/*yieldTest13*/();
                
                __LINE__ = 344;
                var ret/*ret*/ = generator/*generator*/.next();
                
                __LINE__ = 345;
                Runtime/*Runtime*/.assert(true,ret/*ret*/[0] === "x","ret[0] === \"x\"",345,'yield_test.js');
                
                __LINE__ = 346;
                Runtime/*Runtime*/.assert(true,ret/*ret*/[1] === 200,"ret[1] === 200",346,'yield_test.js');
                
                __LINE__ = 347;
                ret/*ret*/ = generator/*generator*/.next();
                
                __LINE__ = 348;
                Runtime/*Runtime*/.assert(true,ret/*ret*/[0] === "y","ret[0] === \"y\"",348,'yield_test.js');
                
                __LINE__ = 349;
                Runtime/*Runtime*/.assert(true,ret/*ret*/[1] === 300,"ret[1] === 300",349,'yield_test.js');
                
                __LINE__ = 350;
                ret/*ret*/ = generator/*generator*/.next();
                
                __LINE__ = 351;
                Runtime/*Runtime*/.assert(true,ret/*ret*/[0] === "z","ret[0] === \"z\"",351,'yield_test.js');
                
                __LINE__ = 352;
                Runtime/*Runtime*/.assert(true,ret/*ret*/[1] === 400,"ret[1] === 400",352,'yield_test.js');
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            },
            case13 : function () {
              try {
                function keys/*keys*/(obj/*obj*/) {
                  try {
                    __LINE__ = 355;
                    var _mochaIsNewBorn/*_mochaIsNewBorn*/ = true;
                    
                    __LINE__ = 355;
                    var _yieldResult/*_yieldResult*/ = undefined;
                    
                    __LINE__ = 355;
                    var _yieldState/*_yieldState*/ = 0;
                    
                    __LINE__ = 356;
                    var length/*length*/;
                    
                    __LINE__ = 356;
                    var _mochaLocalTmp7/*_mochaLocalTmp7*/;
                    
                    __LINE__ = 356;
                    var prop/*prop*/;
                    
                    __LINE__ = 356;
                    var _mochaLocalTmp6/*_mochaLocalTmp6*/ = [];
                    
                    __LINE__ = 355;
                    var _mochaGenerator/*_mochaGenerator*/ = function (_isYieldSend/*_isYieldSend*/,_isYieldSafe/*_isYieldSafe*/) {
                          try {
                            __LINE__ = 355;
                            if (!_isYieldSend/*_isYieldSend*/){
                              
                              __LINE__ = 355;
                              _mochaIsNewBorn/*_mochaIsNewBorn*/ = false;
                            } else if (_isYieldSend/*_isYieldSend*/ && _mochaIsNewBorn/*_mochaIsNewBorn*/ && arguments[1] !== undefined){
                              
                              __LINE__ = 355;
                              Runtime/*Runtime*/.exceptionHandler('attempt to send to newborn generator.');
                            }
                            
                            __LINE__ = 355;
                            while (1){
                              __LINE__ = 355;
                              switch (_yieldState/*_yieldState*/) {
                                case 0 :
                                  
                                  __LINE__ = 356;
                                  for (var _mochaLocalTmp5/*_mochaLocalTmp5*/ in obj/*obj*/){
                                    
                                    __LINE__ = 356;
                                    _mochaLocalTmp6/*_mochaLocalTmp6*/.push(_mochaLocalTmp5/*_mochaLocalTmp5*/);
                                  }
                                  
                                  __LINE__ = 356;
                                  _mochaLocalTmp7/*_mochaLocalTmp7*/ = 0;
                                  
                                  __LINE__ = 356;
                                  length/*length*/ = _mochaLocalTmp6/*_mochaLocalTmp6*/.length;
                                  
                                  __LINE__ = 356;
                                  if (!(_mochaLocalTmp7/*_mochaLocalTmp7*/<length/*length*/)){
                                    
                                    __LINE__ = 356;
                                    _yieldState/*_yieldState*/ = -1;
                                    __LINE__ = 356;
                                    break;
                                  }
                                case 1 :
                                  
                                  __LINE__ = 356;
                                  prop/*prop*/ = _mochaLocalTmp6/*_mochaLocalTmp6*/[_mochaLocalTmp7/*_mochaLocalTmp7*/];
                                  
                                  __LINE__ = 357;
                                  if (obj/*obj*/.hasOwnProperty(prop/*prop*/)){
                                    
                                    __LINE__ = 357;
                                    _yieldState/*_yieldState*/ = 2;
                                    __LINE__ = 357;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 357;
                                    _yieldState/*_yieldState*/ = 3;
                                    __LINE__ = 357;
                                    break;
                                  }
                                case 2 :
                                  
                                  __LINE__ = 358;
                                  _yieldState/*_yieldState*/ = 3;
                                  __LINE__ = 358;
                                  return prop/*prop*/;
                                case 3 :
                                  
                                  __LINE__ = 357;
                                  _yieldState/*_yieldState*/ = 4;
                                  __LINE__ = 357;
                                  break;
                                case 4 :
                                  
                                  __LINE__ = 356;
                                   ++ _mochaLocalTmp7/*_mochaLocalTmp7*/;
                                  
                                  __LINE__ = 356;
                                  if (_mochaLocalTmp7/*_mochaLocalTmp7*/<length/*length*/){
                                    
                                    __LINE__ = 0;
                                    _yieldState/*_yieldState*/ = 1;
                                    __LINE__ = 356;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState/*_yieldState*/ = -1;
                                  }
                                case -1 :
                                  
                                  __LINE__ = 355;
                                  if (_isYieldSafe/*_isYieldSafe*/){
                                    __LINE__ = 355;
                                    return undefined;
                                  } else {
                                    __LINE__ = 355;
                                    Runtime/*Runtime*/.throwStopIteration();
                                  }
                                  
                              }
                              
                            }
                            
                          } catch(e){
                            Runtime.exceptionHandler(__LINE__, __FILE__, e);
                          }
                        };
                    __LINE__ = 355;
                    return Runtime/*Runtime*/.createGenerator(_mochaGenerator/*_mochaGenerator*/,
                    function () {
                      try {
                        __LINE__ = 355;
                        _yieldState/*_yieldState*/ = -1;
                      } catch(e){
                        Runtime.exceptionHandler(__LINE__, __FILE__, e);
                      }
                    },this);
                  } catch(e){
                    Runtime.exceptionHandler(__LINE__, __FILE__, e);
                  }
                }
                __LINE__ = 363;
                var testObject/*testObject*/ =  {
                      value1 : 1,
                      value2 : 2,
                      value3 : 3,
                      value4 : 4
                    };
                
                try {
                  
                  __LINE__ = 370;
                  var itemGen/*itemGen*/ = keys/*keys*/(testObject/*testObject*/);
                  __LINE__ = 371;
                  Runtime/*Runtime*/.assert(true,itemGen/*itemGen*/.next() == "value1","itemGen.next() == \"value1\"",371,'yield_test.js');
                  __LINE__ = 372;
                  Runtime/*Runtime*/.assert(true,itemGen/*itemGen*/.next() == "value2","itemGen.next() == \"value2\"",372,'yield_test.js');
                  __LINE__ = 373;
                  Runtime/*Runtime*/.assert(true,itemGen/*itemGen*/.next() == "value3","itemGen.next() == \"value3\"",373,'yield_test.js');
                  __LINE__ = 374;
                  Runtime/*Runtime*/.assert(true,itemGen/*itemGen*/.next() == "value4","itemGen.next() == \"value4\"",374,'yield_test.js');
                } catch(e){
                  
                }
                
              } catch(e){
                Runtime.exceptionHandler(__LINE__, __FILE__, e);
              }
            }
          };
      
      __LINE__ = 383;
      for (var i/*i*/ = 1;i/*i*/<13;i/*i*/ ++ ){
        
        __LINE__ = 384;
        tests/*tests*/["case"+i/*i*/]();
      }
      
    } catch(e){
      Runtime.exceptionHandler(__LINE__, __FILE__, e);
    }
  }();
}();
