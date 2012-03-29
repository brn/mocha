!function() {
  
  var b/*_mochaGlobalExport*/ = {};
  
  !function (m/*_mochaLocalTmp0*/,l/*_mochaLocalTmp1*/,i/*_mochaLocalTmp2*/,h/*_mochaLocalTmp3*/) {
    function f/*defineBuiltin*/(c/*obj*/,b/*name*/,a/*value*/) {
      return Object.defineProperty(c/*obj*/,b/*name*/, {
        value : a/*value*/,
        configurable : true,
        enumerable : false,
        writable : true
      });
    }
    function e/*callbackCheck*/(d/*callback*/,c/*type*/) {
      
      typeof d/*callback*/ !== "function" && b/*builtinTypeError*/(c/*type*/+" : first argument is not callable");
    }
    function b/*builtinTypeError*/(a/*message*/) {
      try {
        throw new TypeError(a/*message*/)
        
      } catch(e){
        throw new Error(e)
        
      }
      
    }
    var c/*stringProto*/ = m/*_mochaLocalTmp0*/.prototype,
        d/*arrayProto*/ = l/*_mochaLocalTmp1*/.prototype,
        j/*functionProto*/ = i/*_mochaLocalTmp2*/.prototype,
        g/*dateProto*/ = h/*_mochaLocalTmp3*/.prototype;
    
    !Object.keys && (Object.keys = function (e/*obj*/) {
      !e/*obj*/ && b/*builtinTypeError*/("Object.keys : first arguments is null or not defined.");
      
      var d/*ret*/ = [],
          a/*iter*/ = -1;
      
      for (var c/*i*/ in e/*obj*/)
      e/*obj*/.hasOwnProperty(c/*i*/) && (d/*ret*/[ ++ a/*iter*/] = e/*obj*/[c/*i*/]);
      return d/*ret*/;
    });
    
    !Object.preventExtensions && (Object.preventExtensions = function (a/*o*/) {
      return a/*o*/;
    });
    
    !Object.seal && (Object.seal = function (a/*o*/) {
      return a/*o*/;
    });
    
    !Object.freeze && (Object.freeze = function (a/*o*/) {
      return a/*o*/;
    });
    
    var k/*hasRealEcma5*/ = function () {
          var b/*ret*/;
          
          try {
            
            var a/*obj*/ = {};
            
            Object.defineProperty(a/*obj*/,"test", {
              configurable : false,
              writable : false,
              enumerable : false,
              value : 0
            });
            
            a/*obj*/.test = 200;
            
            b/*ret*/ = (a/*obj*/.test === 200)?false : true;
          } catch(e){
            
            b/*ret*/ = false;
          }
          return b/*ret*/;
        }();
    
    !k/*hasRealEcma5*/ && (Object.defineProperty = function (c/*obj*/,b/*prop*/,a/*valobj*/) {
      "value" in a/*valobj*/ && (c/*obj*/[b/*prop*/] = a/*valobj*/.value);
    });
    
    if (!c/*stringProto*/.trim){
      
      c/*stringProto*/.trim = function () {
        return this.replace(c/*stringProto*/.trim.rtrim,"");
      };
      
      c/*stringProto*/.trim.rtrim = /^\s*|\s*$/g;
    }
    
    !c/*stringProto*/.repeat && f/*defineBuiltin*/(c/*stringProto*/,"repeat",
    function (a/*num*/) {
      return Array(a/*num*/+1).join(this.toString());
    });
    
    !c/*stringProto*/.startsWith && f/*defineBuiltin*/(c/*stringProto*/,"startsWith",
    function (a/*str*/) {
      return !this.indexOf(a/*str*/);
    });
    
    !c/*stringProto*/.endsWith && f/*defineBuiltin*/(c/*stringProto*/,"endsWith",
    function (c/*str*/) {
      var b/*t*/ = String(c/*str*/),
          a/*index*/ = this.lastIndexOf(b/*t*/);
      return a/*index*/ >= 0 && a/*index*/ === this.length-b/*t*/.length;
    });
    
    !c/*stringProto*/.contains && f/*defineBuiltin*/(c/*stringProto*/,"contains",
    function (a/*str*/) {
      return this.indexOf(a/*str*/) !== -1;
    });
    
    !c/*stringProto*/.toArray && f/*defineBuiltin*/(c/*stringProto*/,"toArray",
    function (a/*str*/) {
      return this.split("");
    });
    
    !j/*functionProto*/.bind && f/*defineBuiltin*/(j/*functionProto*/,"bind",
    function () {
      var c/*argArray*/ = d/*arrayProto*/.slice.call(arguments),
          a/*context*/ = c/*argArray*/.shift(),
          b/*ret*/ = function () {
            var e/*args*/ = c/*argArray*/.concat(d/*arrayProto*/.slice.call(arguments));
            return this !== null && this !== window && this instanceof b/*ret*/?b/*ret*/.context.apply(this,e/*args*/) : b/*ret*/.context.apply(a/*context*/,e/*args*/);
          };
      
      b/*ret*/.prototype = this.prototype;
      
      b/*ret*/.context = this;
      return b/*ret*/;
    });
    
    !d/*arrayProto*/.forEach && f/*defineBuiltin*/(d/*arrayProto*/,"forEach",
    function (i/*callback*/,h/*that*/) {
      e/*callbackCheck*/(i/*callback*/,"Array.forEach");
      
      var f/*iter*/ = -1,
          g/*ta*/;
      
      this === null && b/*builtinTypeError*/("Array.forEach : this is null or not defined");
      
      if (h/*that*/)while ((g/*ta*/ = this[ ++ f/*iter*/]) !== null && g/*ta*/ !== undefined)i/*callback*/.call(h/*that*/,g/*ta*/,f/*iter*/,this);
       else while ((g/*ta*/ = this[ ++ f/*iter*/]) !== null && g/*ta*/ !== undefined)i/*callback*/(g/*ta*/,f/*iter*/,this);
    });
    
    !d/*arrayProto*/.every && f/*defineBuiltin*/(d/*arrayProto*/,"every",
    function (f/*callback*/,d/*that*/) {
      e/*callbackCheck*/(f/*callback*/,"Array.every");
      
      var a/*iter*/ = -1,
          c/*ta*/;
      
      this === null && b/*builtinTypeError*/("Array.every : this is null or not defined");
      
      if (d/*that*/)while ((c/*ta*/ = this[ ++ a/*iter*/]) !== null && c/*ta*/ !== undefined)if (!(f/*callback*/.call(d/*that*/,c/*ta*/,a/*iter*/,this)))return false;
       else while ((c/*ta*/ = this[ ++ a/*iter*/]) !== null && c/*ta*/ !== undefined)if (!(f/*callback*/(c/*ta*/,a/*iter*/,this)))return false;
      return true;
    });
    
    !d/*arrayProto*/.some && f/*defineBuiltin*/(d/*arrayProto*/,"some",
    function (f/*callback*/,d/*that*/) {
      e/*callbackCheck*/(f/*callback*/,"Array.some");
      
      var a/*iter*/ = -1,
          c/*ta*/;
      
      this === null && b/*builtinTypeError*/("Array.some : this is null or not defined");
      
      if (d/*that*/)while ((c/*ta*/ = this[ ++ a/*iter*/]) !== null && c/*ta*/ !== undefined)if (f/*callback*/.call(d/*that*/,c/*ta*/,a/*iter*/,this))return true;
       else while ((c/*ta*/ = this[ ++ a/*iter*/]) !== null && c/*ta*/ !== undefined)if (f/*callback*/(c/*ta*/,a/*iter*/,this))return true;
      return false;
    });
    
    !d/*arrayProto*/.filter && f/*defineBuiltin*/(d/*arrayProto*/,"filter",
    function (i/*callback*/,h/*that*/) {
      e/*callbackCheck*/(i/*callback*/,"Array.filter");
      
      var f/*len*/ = this.length,
          d/*iter*/ = -1,
          c/*ret*/ = [],
          g/*ta*/;
      
      this === null && b/*builtinTypeError*/("Array.filter : this is null or not defined");
      
      if (h/*that*/)for (var a/*i*/ = 0,f/*len*/ = this.length;a/*i*/<f/*len*/; ++ a/*i*/)
      (g/*ta*/ = this[a/*i*/]) !== null && g/*ta*/ !== undefined && i/*callback*/.call(h/*that*/,g/*ta*/,a/*i*/,this) && (c/*ret*/[ ++ d/*iter*/] = g/*ta*/);
       else for (var a/*i*/ = 0,f/*len*/ = this.length;a/*i*/<f/*len*/; ++ a/*i*/)
      (g/*ta*/ = this[a/*i*/]) !== null && g/*ta*/ !== undefined && i/*callback*/(g/*ta*/,a/*i*/,this) && (c/*ret*/[ ++ d/*iter*/] = g/*ta*/);
      return c/*ret*/;
    });
    
    !d/*arrayProto*/.indexOf && f/*defineBuiltin*/(d/*arrayProto*/,"indexOf",
    function (f/*subject*/,c/*fromIndex*/) {
      var a/*iter*/ = (c/*fromIndex*/)?c/*fromIndex*/-1 : -1,
          e/*index*/ = -1,
          d/*ta*/;
      
      this === null && b/*builtinTypeError*/("Array.indexOf : this is null or not defined.");
      
      while ((d/*ta*/ = this[ ++ a/*iter*/]) !== null && d/*ta*/ !== undefined)if (d/*ta*/ === f/*subject*/){
        
        e/*index*/ = a/*iter*/;
        break;
      }
      return e/*index*/;
    });
    
    !d/*arrayProto*/.lastIndexOf && f/*defineBuiltin*/(d/*arrayProto*/,"lastIndexOf",
    function (g/*target*/,e/*fromIndex*/) {
      var f/*len*/ = this.length,
          d/*iter*/ = (e/*fromIndex*/)?e/*fromIndex*/+1 : f/*len*/,
          c/*index*/ = -1,
          a/*ta*/;
      
      this === null && b/*builtinTypeError*/("Array.lastIndexOf : this is null or not defined.");
      
      while ((a/*ta*/ = this[ -- d/*iter*/]) !== null && a/*ta*/ !== undefined)if (a/*ta*/ === g/*target*/){
        
        c/*index*/ = d/*iter*/;
        break;
      }
      return c/*index*/;
    });
    
    !d/*arrayProto*/.map && f/*defineBuiltin*/(d/*arrayProto*/,"map",
    function (i/*callback*/,h/*that*/) {
      e/*callbackCheck*/(i/*callback*/,"Array.map");
      
      var f/*ret*/ = [],
          c/*iter*/ = -1,
          a/*len*/ = this.length,
          d/*i*/ = 0,
          g/*ta*/;
      
      this === null && b/*builtinTypeError*/("Array.map : this is null or not defined.");
      
      if (h/*that*/)for (d/*i*/;d/*i*/<a/*len*/; ++ d/*i*/)(g/*ta*/ = this[d/*i*/]) !== null && g/*ta*/ !== undefined && (f/*ret*/[ ++ c/*iter*/] = i/*callback*/.call(h/*that*/,g/*ta*/,d/*i*/,this));
       else for (d/*i*/;d/*i*/<a/*len*/; ++ d/*i*/)(g/*ta*/ = this[d/*i*/]) !== null && g/*ta*/ !== undefined && (f/*ret*/[ ++ c/*iter*/] = i/*callback*/(g/*ta*/,d/*i*/,this));
      return f/*ret*/;
    });
    
    !d/*arrayProto*/.reduce && f/*defineBuiltin*/(d/*arrayProto*/,"reduce",
    function (h/*callback*/,g/*initial*/) {
      e/*callbackCheck*/(h/*callback*/,"Array.reduce");
      
      var f/*ret*/ = g/*initial*/ || this[0],
          d/*i*/ = (g/*initial*/)?0 : 1,
          c/*len*/ = this.length,
          a/*ta*/;
      
      (c/*len*/ === 0 || c/*len*/ === null) && arguments.length<2 && b/*builtinTypeError*/("Array length is 0 and no second argument");
      
      for (d/*i*/;d/*i*/<c/*len*/; ++ d/*i*/)(a/*ta*/ = this[d/*i*/]) !== null && a/*ta*/ !== undefined && (f/*ret*/ = h/*callback*/(f/*ret*/,a/*ta*/,d/*i*/,this));
      return f/*ret*/;
    });
    
    !d/*arrayProto*/.reduceRight && f/*defineBuiltin*/(d/*arrayProto*/,"reduceRight",
    function (h/*callback*/,g/*initial*/) {
      e/*callbackCheck*/(h/*callback*/,"Array.reduceRight");
      
      var f/*len*/ = this.length,
          d/*ret*/ = g/*initial*/ || this[f/*len*/-1],
          c/*i*/ = (g/*initial*/)?f/*len*/-1 : f/*len*/-2,
          a/*ta*/;
      
      (f/*len*/ === 0 || f/*len*/ === null) && arguments.length<2 && b/*builtinTypeError*/("Array length is 0 and no second argument");
      
      for (c/*i*/;c/*i*/>-1; -- c/*i*/)(a/*ta*/ = this[c/*i*/]) !== null && a/*ta*/ !== undefined && (d/*ret*/ = h/*callback*/(d/*ret*/,a/*ta*/,c/*i*/,this));
      return d/*ret*/;
    });
    
    !g/*dateProto*/.toJSON && f/*defineBuiltin*/(g/*dateProto*/,"toJSON",
    function () {
      var f/*_mochaLocalTmp4*/ = [this.getUTCMonth(),this.getUTCDate(),this.getUTCHours(),this.getMinutes(),this.getSeconds()],
          e/*month*/ = f/*_mochaLocalTmp4*/[0],
          d/*date*/ = f/*_mochaLocalTmp4*/[1],
          c/*hour*/ = f/*_mochaLocalTmp4*/[2],
          b/*minute*/ = f/*_mochaLocalTmp4*/[3],
          a/*second*/ = f/*_mochaLocalTmp4*/[4];
      return '"'+this.getUTCFullYear()+'-'+(e/*month*/>8?e/*month*/+1 : "0"+(e/*month*/+1))+'-'+(d/*date*/>9?d/*date*/ : "0"+d/*date*/)+'T'+(c/*hour*/>9?c/*hour*/ : "0"+c/*hour*/)+':'+(b/*minute*/>9?b/*minute*/ : "0"+b/*minute*/)+':'+(a/*second*/>9?a/*second*/ : "0"+a/*second*/)+'.'+this.getUTCMilliseconds()+'Z"';
    });
    
    !Date.now && f/*defineBuiltin*/(Date,"now",
    function () {
      return +new Date();
    });
    
    !Array.isArray && f/*defineBuiltin*/(Array,"isArray",
    function (a/*arr*/) {
      if (arguments.length === 0)return false;
      return (a/*arr*/)?({}).toString.call(a/*arr*/) === "[object Array]" : false;
    });
  }.call(this,String,Array,Function,Date);
  
  var a/*Runtime*/ = function () {
        "use strict";
        function s/*checkRequirements*/(m/*_mochaLocalTmp9*/,l/*_mochaLocalTmp10*/,k/*traits*/,g/*file*/,f/*line*/) {
          var i/*proto1*/ = m/*_mochaLocalTmp9*/.prototype,
              h/*proto2*/ = l/*_mochaLocalTmp10*/.prototype;
          
          for (var d/*i*/ = 0,e/*len*/ = k/*traits*/.length;d/*i*/<e/*len*/;d/*i*/ ++ ){
            
            var c/*_mochaLocalTmp11*/ = k/*traits*/[d/*i*/],
                b/*_mochaRequires*/ = c/*_mochaLocalTmp11*/._mochaRequires;
            
            for (var j/*prop*/ in b/*_mochaRequires*/)!(j/*prop*/ in i/*proto1*/) && !(j/*prop*/ in h/*proto2*/) && a/*Runtime*/.throwException("Class dose not meet the traits requirement. traits require implementation of property "+j/*prop*/+"\nin file "+g/*file*/+" at line "+f/*line*/);
          }
          
        }
        function t/*classMixin*/(m/*_mochaLocalTmp6*/,k/*_mochaLocalTmp7*/,i/*_mochaLocalTmp8*/,g/*with_*/,h/*without*/) {
          var d/*constructorProto*/ = m/*_mochaLocalTmp6*/.prototype,
              e/*privateProto*/ = k/*_mochaLocalTmp7*/.prototype,
              f/*mark*/ = i/*_mochaLocalTmp8*/._mochaTraitMark,
              c/*traitPublic*/ = i/*_mochaLocalTmp8*/._mochaTraitPublic,
              l/*traitPrivate*/ = i/*_mochaLocalTmp8*/._mochaTraitPrivate;
          
          if (!f/*mark*/)a/*Runtime*/.throwException("mixin only used for trait.");
           else {
            
            var j/*tmp*/;
            
            for (var b/*i*/ in c/*traitPublic*/)if (!h/*without*/[b/*i*/]){
              
              j/*tmp*/ = (!g/*with_*/[b/*i*/])?b/*i*/ : g/*with_*/[b/*i*/];
              
              d/*constructorProto*/[j/*tmp*/] = c/*traitPublic*/[b/*i*/];
            }
            
            for (b/*i*/ in l/*traitPrivate*/)if (!h/*without*/[b/*i*/]){
              
              j/*tmp*/ = (!g/*with_*/[b/*i*/])?b/*i*/ : g/*with_*/[b/*i*/];
              
              e/*privateProto*/[j/*tmp*/] = l/*traitPrivate*/[b/*i*/];
            }
            
          }
          
        }
        function u/*traitMixin*/(m/*dest*/,i/*source*/,l/*with_*/,h/*without*/) {
          if (!m/*dest*/._mochaTraitMark || !i/*source*/._mochaTraitMark)a/*Runtime*/.throwException("mixin only used for trait.");
           else {
            
            var g/*destTraitPrivate*/ = m/*dest*/._mochaTraitPrivate,
                f/*sourceTraitPrivate*/ = i/*source*/._mochaTraitPrivate,
                j/*destTraitPublic*/ = m/*dest*/._mochaTraitPublic,
                k/*sourceTraitPublic*/ = i/*source*/._mochaTraitPublic,
                e/*sourceRequires*/ = i/*source*/._mochaRequires,
                d/*destRequires*/ = m/*dest*/._mochaRequires,
                c/*tmp*/;
            
            for (var b/*i*/ in f/*sourceTraitPrivate*/)if (!h/*without*/[b/*i*/]){
              
              c/*tmp*/ = (!l/*with_*/[b/*i*/])?b/*i*/ : l/*with_*/[b/*i*/];
              
              g/*destTraitPrivate*/[c/*tmp*/] = f/*sourceTraitPrivate*/[b/*i*/];
            }
            
            for (b/*i*/ in k/*sourceTraitPublic*/)if (!h/*without*/[b/*i*/]){
              
              c/*tmp*/ = (!l/*with_*/[b/*i*/])?b/*i*/ : l/*with_*/[b/*i*/];
              
              j/*destTraitPublic*/[c/*tmp*/] = k/*sourceTraitPublic*/[b/*i*/];
            }
            
            for (b/*i*/ in e/*sourceRequires*/)d/*destRequires*/[b/*i*/] = e/*sourceRequires*/[b/*i*/];
          }
          
        }
        function v/*getSuper*/(c/*obj*/) {
          var a/*type*/ = typeof c/*obj*/,
              b/*ret*/;
          
          if (a/*type*/ === "function"){
            
            b/*ret*/ = function (){};
            
            b/*ret*/.prototype = c/*obj*/.prototype;
            
            b/*ret*/ = new b/*ret*/();
            
            c/*obj*/.__harmony_class__?b/*ret*/.constructor = c/*obj*/.constructor : b/*ret*/.constructor = c/*obj*/;
            return b/*ret*/;
          }
          return b/*ret*/;
        }
        function F/*initializeClass*/(x/*instance*/,w/*classObject*/,u/*privateHolder*/,t/*constructor*/,v/*args*/,s/*name*/,r/*line*/) {
          (!x/*instance*/ || !(x/*instance*/ instanceof w/*classObject*/)) && q/*throwException*/("class "+s/*name*/+" must be called by new. line : "+r/*line*/);
          
          p/*createPrivateRecord*/(x/*instance*/,u/*privateHolder*/);
          
          t/*constructor*/.apply(x/*instance*/,v/*args*/);
        }
        function c/*isStopIteration*/(o/*obj*/) {
          return o/*obj*/ === StopIteration || n/*rstopIteration*/.test(o/*obj*/);
        }
        function x/*hasIterator*/(a/*obj*/) {
          return m/*__ref_iterator__*/ in a/*obj*/;
        }
        function K/*getIterator*/(p/*obj*/) {
          var a/*ret*/ = p/*obj*/[m/*__ref_iterator__*/](),
              o/*newObj*/;
          
          if (l/*isGenerator*/(a/*ret*/))return a/*ret*/;
          
          o/*newObj*/ = {};
          
          if (a/*ret*/.next)e/*createUnenumProp*/(o/*newObj*/,"next",
          function () {
            var b/*result*/ = a/*ret*/.next();
            
            b/*result*/ === undefined && k/*throwStopIteration*/();
            return b/*result*/;
          });
           else return {};
          
          !("__nothrowNext__" in a/*ret*/) && e/*createUnenumProp*/(o/*newObj*/,"__nothrowNext__",a/*ret*/.next.bind(a/*ret*/));
          
          for (var n/*prop*/ in a/*ret*/)
          n/*prop*/ !== "next" && n/*prop*/ !== "__nothrowNext__" && (o/*newObj*/[n/*prop*/] = a/*ret*/[n/*prop*/]);
          
          !("toString" in a/*ret*/) && e/*createUnenumProp*/(o/*newObj*/,"toString",
          function () {
            return "[object Iterator]";
          });
          return o/*newObj*/;
        }
        function l/*isGenerator*/(a/*obj*/) {
          return a/*obj*/ instanceof f/*Generator*/;
        }
        function k/*throwStopIteration*/() {
          try {
            throw StopIteration
            
          } catch(e){
            throw new Error(e.toString())
            
          }
          
        }
        function y/*createRecord*/(a/*obj*/) {
          a/*obj*/.toString() === "[object Object]" && e/*createUnenumProp*/(a/*obj*/,"toString",
          function () {
            return "[object Record]";
          });
          return Object.freeze(a/*obj*/);
        }
        function I/*createTuple*/(k/*obj*/,j/*size*/) {
          e/*createUnenumProp*/(k/*obj*/,"length",j/*size*/);
          
          e/*createUnenumProp*/(k/*obj*/,"equal",i/*compareTuple*/);
          
          e/*createUnenumProp*/(k/*obj*/,"toArray",h/*tupleToArray*/);
          
          e/*createUnenumProp*/(k/*obj*/,"toString",
          function () {
            return "[object Tuple]";
          });
          return Object.freeze(k/*obj*/);
        }
        function h/*tupleToArray*/() {
          return [].slice.call(this);
        }
        function i/*compareTuple*/(j/*tuple*/) {
          var i/*maxIndex*/ = g/*max*/(j/*tuple*/.length,this.length),
              h/*i*/ = -1;
          
          while ( ++ h/*i*/<i/*maxIndex*/ && j/*tuple*/[h/*i*/] === this[h/*i*/]){
            
          }
          return i/*maxIndex*/ === h/*i*/;
        }
        function G/*extend*/(c/*dest*/,b/*source*/) {
          for (var a/*prop*/ in b/*source*/)
          c/*dest*/[a/*prop*/] = b/*source*/[a/*prop*/];
          return c/*dest*/;
        }
        function z/*getErrorMessage*/(a/*e*/) {
          return (a/*e*/.message)?a/*e*/.message : (a/*e*/.description)?a/*e*/.description : a/*e*/.toString();
        }
        function B/*createGenerator*/(j/*generatorFn*/,i/*closeFn*/,h/*context*/) {
          var g/*ret*/ = new f/*Generator*/;
          
          e/*createUnenumProp*/(g/*ret*/,"next",j/*generatorFn*/.bind(h/*context*/,false,false));
          
          e/*createUnenumProp*/(g/*ret*/,"send",j/*generatorFn*/.bind(h/*context*/,true,false));
          
          e/*createUnenumProp*/(g/*ret*/,"close",i/*closeFn*/.bind(h/*context*/));
          
          e/*createUnenumProp*/(g/*ret*/,"__nothrowNext__",j/*generatorFn*/.bind(h/*context*/,false,true));
          
          e/*createUnenumProp*/(g/*ret*/,"toString",
          function () {
            return "[object Generator]";
          });
          
          Object.freeze(g/*ret*/);
          return g/*ret*/;
        }
        function f/*Generator*/(){}
        function J/*toArray*/(f/*likeArray*/,e/*index*/) {
          return (f/*likeArray*/)?d/*slice*/.call(f/*likeArray*/,e/*index*/) : [];
        }
        function D/*constant*/(c/*obj*/,b/*prop*/,a/*value*/) {
          return Object.defineProperty(c/*obj*/,b/*prop*/, {
            configurable : false,
            enumerable : false,
            writable : false,
            value : a/*value*/
          });
        }
        function e/*createUnenumProp*/(c/*obj*/,b/*prop*/,a/*value*/) {
          return Object.defineProperty(c/*obj*/,b/*prop*/, {
            configurable : true,
            enumerable : false,
            writable : true,
            value : a/*value*/
          });
        }
        function b/*Exception*/(b/*line*/,c/*file*/,d/*e*/) {
          this.toString = function () {
            return a/*Runtime*/.getErrorMessage(d/*e*/)+" in file "+c/*file*/+" at : "+b/*line*/;
          };
        }
        var r/*_mochaLocalExport*/ = {};
        
        var g/*max*/ = Math.max,
            H/*_mochaLocalTmp5*/ = Array.prototype,
            d/*slice*/ = H/*_mochaLocalTmp5*/.slice,
            a/*Runtime*/ =  {
              getErrorMessage : function (a/*e*/) {
                return (a/*e*/.message)?a/*e*/.message : (a/*e*/.description)?a/*e*/.description : a/*e*/.toString();
              },
              exceptionHandler : function (f/*line*/,e/*file*/,d/*e*/) {
                if (c/*isStopIteration*/(d/*e*/)){
                  
                  this.throwException(d/*e*/);
                } else {
                  
                  this.throwException(new b/*Exception*/(f/*line*/,e/*file*/,d/*e*/));
                }
                
              },
              throwException : function (a/*exception*/) {
                try {
                  throw a/*exception*/
                  
                } catch(e){
                  
                  if (c/*isStopIteration*/(e)){
                    throw new Error(e)
                    
                  } else {
                    throw new Error(this.getErrorMessage(e))
                    
                  }
                  
                }
                
              },
              hasProto : "__proto__" in {}
            };
        
        r/*_mochaLocalExport*/.createUnenumProp = e/*createUnenumProp*/;
        
        r/*_mochaLocalExport*/.constant = D/*constant*/;
        
        r/*_mochaLocalExport*/.toArray = J/*toArray*/;
        
        r/*_mochaLocalExport*/.createGenerator = B/*createGenerator*/;
        
        var q/*throwException*/ = r/*_mochaLocalExport*/.throwException = a/*Runtime*/.throwException.bind(a/*Runtime*/),
            A/*exceptionHandler*/ = r/*_mochaLocalExport*/.exceptionHandler = a/*Runtime*/.exceptionHandler.bind(a/*Runtime*/);
        
        r/*_mochaLocalExport*/.extend = G/*extend*/;
        
        r/*_mochaLocalExport*/.createTuple = I/*createTuple*/;
        
        r/*_mochaLocalExport*/.createRecord = y/*createRecord*/;
        
        var E/*extendPrototype*/ = r/*_mochaLocalExport*/.extendPrototype = function (b/*derived*/,a/*base*/) {
              b/*derived*/.prototype = a/*base*/;
            },
            j/*getPrototype*/ = ("getPrototypeOf" in Object)?function (a/*obj*/) {
              return Object.getPrototypeOf(a/*obj*/);
            } : function (c/*obj*/) {
              var b/*ret*/ = {};
              
              for (var a/*i*/ in c/*obj*/)
              !c/*obj*/.hasOwnProperty(a/*i*/) && (b/*ret*/[a/*i*/] = c/*obj*/[a/*i*/]);
              return b/*ret*/;
            },
            C/*extendClass*/ = r/*_mochaLocalExport*/.extendClass = (a/*Runtime*/.hasProto)?function (c/*derived*/,b/*base*/) {
              if (typeof b/*base*/ === 'function'){
                
                c/*derived*/.prototype.__proto__ = b/*base*/.prototype;
                
                for (var a/*i*/ in b/*base*/)c/*derived*/[a/*i*/] = b/*base*/[a/*i*/];
              } else c/*derived*/.prototype.__proto__ = b/*base*/.__proto__;
            } : function (p/*derived*/,o/*base*/) {
              var n/*baseType*/ = typeof o/*base*/;
              
              if (n/*baseType*/ === "function"){
                
                var m/*inherit*/ = function (){};
                
                m/*inherit*/.prototype = o/*base*/.prototype;
                
                p/*derived*/.prototype = new m/*inherit*/;
                
                for (var l/*i*/ in o/*base*/)p/*derived*/[l/*i*/] = o/*base*/[l/*i*/];
              } else {
                
                var m/*inherit*/ = function (){},
                    k/*proto*/ = j/*getPrototype*/(o/*base*/);
                
                m/*inherit*/.prototype = k/*proto*/;
                
                p/*derived*/.prototype = new m/*inherit*/;
              }
              
            },
            m/*__ref_iterator__*/ = r/*_mochaLocalExport*/.__ref_iterator__ = "__mocha_iterator_special_key__";
        
        r/*_mochaLocalExport*/.throwStopIteration = k/*throwStopIteration*/;
        
        r/*_mochaLocalExport*/.isGenerator = l/*isGenerator*/;
        
        r/*_mochaLocalExport*/.getIterator = K/*getIterator*/;
        
        r/*_mochaLocalExport*/.hasIterator = x/*hasIterator*/;
        
        var n/*rstopIteration*/ = /StopIteration/;
        
        r/*_mochaLocalExport*/.isStopIteration = c/*isStopIteration*/;
        
        var o/*privateRecord*/,
            p/*createPrivateRecord*/,
            w/*getPrivateRecord*/;
        
        if ("WeakMap" in window){
          
          o/*privateRecord*/ = new WeakMap();
          
          p/*createPrivateRecord*/ = function (self,q/*privateHolder*/) {
            var p/*holder*/ = new q/*privateHolder*/;
            
            e/*createUnenumProp*/(p/*holder*/.constructor,"__is_private__",1);
            
            o/*privateRecord*/.set(self,p/*holder*/);
          };
          
          w/*getPrivateRecord*/ = function (self) {
            if (o/*privateRecord*/.has(self))return o/*privateRecord*/.get(self);
             else if (self.constructor === "__is_private__")return self;
          };
        } else {
          
          p/*createPrivateRecord*/ = function (self,b/*privateHolder*/) {
            if (!self.__typeid__){
              
              var a/*holder*/ = new b/*privateHolder*/;
              
              e/*createUnenumProp*/(a/*holder*/.constructor,"__is_private__",1);
              
              e/*createUnenumProp*/(self,"__private__",a/*holder*/);
            }
            
          };
          
          w/*getPrivateRecord*/ = function (self) {
            if (self.__private__)return self.__private__;
             else if (self.constructor === "__is_private__")return self;
          };
        }
        
        r/*_mochaLocalExport*/.getPrivateRecord = w/*getPrivateRecord*/;
        
        r/*_mochaLocalExport*/.initializeClass = F/*initializeClass*/;
        
        r/*_mochaLocalExport*/.getSuper = v/*getSuper*/;
        
        r/*_mochaLocalExport*/.traitMixin = u/*traitMixin*/;
        
        r/*_mochaLocalExport*/.classMixin = t/*classMixin*/;
        
        r/*_mochaLocalExport*/.checkRequirements = s/*checkRequirements*/;
        return r/*_mochaLocalExport*/;
      }();
  
  !("StopIteration" in window) && (window.StopIteration =  {
    toString : function () {
      return "[object StopIteration]";
    }
  });
  
  function c/*Tuple*/() {
    var c/*args*/ = a/*Runtime*/.toArray(arguments,0),
        b/*ret*/ = {};
    
    b/*ret*/.length = 0;
    
    [].push.apply(b/*ret*/,c/*args*/);
    
    a/*Runtime*/.createTuple(b/*ret*/,arguments.length);
    return b/*ret*/;
  }
  function d/*Record*/(b/*member*/) {
    return a/*Runtime*/.createRecord(b/*member*/);
  }
  !function () {
    b/*_mochaGlobalExport*/.iterators = {};
    
    var c/*_mochaGlobalAlias*/ = b/*_mochaGlobalExport*/.iterators;
    
    !function () {
      function h/*allItems*/(c/*obj*/) {
        var d/*_mochaLocalTmp23*/ = {};
        
        a/*Runtime*/.createUnenumProp(d/*_mochaLocalTmp23*/,b/*iterator*/,
        function () {
          return function () {
            var h/*_mochaIsNewBorn*/ = true,
                j/*_yieldResult*/ = undefined,
                g/*_yieldState*/ = 0,
                d/*length*/,
                e/*_mochaLocalTmp22*/,
                b/*x*/,
                f/*_mochaLocalTmp21*/ = [],
                i/*_mochaGenerator*/ = function (k/*_isYieldSend*/,j/*_isYieldSafe*/) {
                  !k/*_isYieldSend*/?h/*_mochaIsNewBorn*/ = false : k/*_isYieldSend*/ && h/*_mochaIsNewBorn*/ && arguments[1] !== undefined && a/*Runtime*/.exceptionHandler('attempt to send to newborn generator.');
                  
                  while (1)
                  switch (g/*_yieldState*/) {
                    case 0 :
                      
                      for (var i/*_mochaLocalTmp20*/ in c/*obj*/)
                      f/*_mochaLocalTmp21*/.push(i/*_mochaLocalTmp20*/);
                      
                      e/*_mochaLocalTmp22*/ = 0;
                      
                      d/*length*/ = f/*_mochaLocalTmp21*/.length;
                      
                      if (!(e/*_mochaLocalTmp22*/<d/*length*/)){
                        
                        g/*_yieldState*/ = -1;
                        break;
                      }
                    case 1 :
                      
                      g/*_yieldState*/ = 2;
                      
                      b/*x*/ = f/*_mochaLocalTmp21*/[e/*_mochaLocalTmp22*/];
                      return [b/*x*/,c/*obj*/[b/*x*/]];
                    case 2 :
                      
                       ++ e/*_mochaLocalTmp22*/;
                      
                      if (e/*_mochaLocalTmp22*/<d/*length*/){
                        
                        g/*_yieldState*/ = 1;
                        break;
                      } else g/*_yieldState*/ = -1;
                    case -1 :
                      
                      if (j/*_isYieldSafe*/)return undefined;
                      
                      a/*Runtime*/.throwStopIteration();
                      
                  }
                  
                };
            return a/*Runtime*/.createGenerator(i/*_mochaGenerator*/,
            function () {
              g/*_yieldState*/ = -1;
            },this);
          }();
        });
        return d/*_mochaLocalTmp23*/;
      }
      function e/*allValues*/(c/*obj*/) {
        var d/*_mochaLocalTmp19*/ = {};
        
        a/*Runtime*/.createUnenumProp(d/*_mochaLocalTmp19*/,b/*iterator*/,
        function () {
          return function () {
            var h/*_mochaIsNewBorn*/ = true,
                j/*_yieldResult*/ = undefined,
                e/*_yieldState*/ = 0,
                d/*length*/,
                f/*_mochaLocalTmp18*/,
                b/*x*/,
                g/*_mochaLocalTmp17*/ = [],
                i/*_mochaGenerator*/ = function (k/*_isYieldSend*/,j/*_isYieldSafe*/) {
                  !k/*_isYieldSend*/?h/*_mochaIsNewBorn*/ = false : k/*_isYieldSend*/ && h/*_mochaIsNewBorn*/ && arguments[1] !== undefined && a/*Runtime*/.exceptionHandler('attempt to send to newborn generator.');
                  
                  while (1)
                  switch (e/*_yieldState*/) {
                    case 0 :
                      
                      for (var i/*_mochaLocalTmp16*/ in c/*obj*/)
                      g/*_mochaLocalTmp17*/.push(i/*_mochaLocalTmp16*/);
                      
                      f/*_mochaLocalTmp18*/ = 0;
                      
                      d/*length*/ = g/*_mochaLocalTmp17*/.length;
                      
                      if (!(f/*_mochaLocalTmp18*/<d/*length*/)){
                        
                        e/*_yieldState*/ = -1;
                        break;
                      }
                    case 1 :
                      
                      e/*_yieldState*/ = 2;
                      
                      b/*x*/ = g/*_mochaLocalTmp17*/[f/*_mochaLocalTmp18*/];
                      return c/*obj*/[b/*x*/];
                    case 2 :
                      
                       ++ f/*_mochaLocalTmp18*/;
                      
                      if (f/*_mochaLocalTmp18*/<d/*length*/){
                        
                        e/*_yieldState*/ = 1;
                        break;
                      } else e/*_yieldState*/ = -1;
                    case -1 :
                      
                      if (j/*_isYieldSafe*/)return undefined;
                      
                      a/*Runtime*/.throwStopIteration();
                      
                  }
                  
                };
            return a/*Runtime*/.createGenerator(i/*_mochaGenerator*/,
            function () {
              e/*_yieldState*/ = -1;
            },this);
          }();
        });
        return d/*_mochaLocalTmp19*/;
      }
      function f/*allKeys*/(c/*obj*/) {
        var d/*_mochaLocalTmp15*/ = {};
        
        a/*Runtime*/.createUnenumProp(d/*_mochaLocalTmp15*/,b/*iterator*/,
        function () {
          return function () {
            var f/*_mochaIsNewBorn*/ = true,
                j/*_yieldResult*/ = undefined,
                e/*_yieldState*/ = 0,
                d/*length*/,
                g/*_mochaLocalTmp14*/,
                b/*x*/,
                h/*_mochaLocalTmp13*/ = [],
                i/*_mochaGenerator*/ = function (k/*_isYieldSend*/,j/*_isYieldSafe*/) {
                  !k/*_isYieldSend*/?f/*_mochaIsNewBorn*/ = false : k/*_isYieldSend*/ && f/*_mochaIsNewBorn*/ && arguments[1] !== undefined && a/*Runtime*/.exceptionHandler('attempt to send to newborn generator.');
                  
                  while (1)
                  switch (e/*_yieldState*/) {
                    case 0 :
                      
                      for (var i/*_mochaLocalTmp12*/ in c/*obj*/)
                      h/*_mochaLocalTmp13*/.push(i/*_mochaLocalTmp12*/);
                      
                      g/*_mochaLocalTmp14*/ = 0;
                      
                      d/*length*/ = h/*_mochaLocalTmp13*/.length;
                      
                      if (!(g/*_mochaLocalTmp14*/<d/*length*/)){
                        
                        e/*_yieldState*/ = -1;
                        break;
                      }
                    case 1 :
                      
                      e/*_yieldState*/ = 2;
                      
                      b/*x*/ = h/*_mochaLocalTmp13*/[g/*_mochaLocalTmp14*/];
                      return b/*x*/;
                    case 2 :
                      
                       ++ g/*_mochaLocalTmp14*/;
                      
                      if (g/*_mochaLocalTmp14*/<d/*length*/){
                        
                        e/*_yieldState*/ = 1;
                        break;
                      } else e/*_yieldState*/ = -1;
                    case -1 :
                      
                      if (j/*_isYieldSafe*/)return undefined;
                      
                      a/*Runtime*/.throwStopIteration();
                      
                  }
                  
                };
            return a/*Runtime*/.createGenerator(i/*_mochaGenerator*/,
            function () {
              e/*_yieldState*/ = -1;
            },this);
          }();
        });
        return d/*_mochaLocalTmp15*/;
      }
      function g/*items*/(c/*obj*/) {
        var e/*_mochaLocalTmp11*/ = {};
        
        a/*Runtime*/.createUnenumProp(e/*_mochaLocalTmp11*/,b/*iterator*/,
        function () {
          return function () {
            var h/*_mochaIsNewBorn*/ = true,
                k/*_yieldResult*/ = undefined,
                g/*_yieldState*/ = 0,
                e/*length*/,
                f/*_mochaLocalTmp10*/,
                b/*x*/,
                i/*_mochaLocalTmp9*/ = [],
                j/*_mochaGenerator*/ = function (l/*_isYieldSend*/,k/*_isYieldSafe*/) {
                  !l/*_isYieldSend*/?h/*_mochaIsNewBorn*/ = false : l/*_isYieldSend*/ && h/*_mochaIsNewBorn*/ && arguments[1] !== undefined && a/*Runtime*/.exceptionHandler('attempt to send to newborn generator.');
                  
                  while (1)
                  switch (g/*_yieldState*/) {
                    case 0 :
                      
                      for (var j/*_mochaLocalTmp8*/ in c/*obj*/)
                      i/*_mochaLocalTmp9*/.push(j/*_mochaLocalTmp8*/);
                      
                      f/*_mochaLocalTmp10*/ = 0;
                      
                      e/*length*/ = i/*_mochaLocalTmp9*/.length;
                      
                      if (!(f/*_mochaLocalTmp10*/<e/*length*/)){
                        
                        g/*_yieldState*/ = -1;
                        break;
                      }
                    case 1 :
                      
                      b/*x*/ = i/*_mochaLocalTmp9*/[f/*_mochaLocalTmp10*/];
                      
                      if (d/*hasOwn*/.call(c/*obj*/,b/*x*/)){
                        
                        g/*_yieldState*/ = 2;
                        break;
                      } else {
                        
                        g/*_yieldState*/ = 3;
                        break;
                      }
                    case 2 :
                      
                      g/*_yieldState*/ = 3;
                      return [b/*x*/,c/*obj*/[b/*x*/]];
                    case 3 :
                      
                      g/*_yieldState*/ = 4;
                      break;
                    case 4 :
                      
                       ++ f/*_mochaLocalTmp10*/;
                      
                      if (f/*_mochaLocalTmp10*/<e/*length*/){
                        
                        g/*_yieldState*/ = 1;
                        break;
                      } else g/*_yieldState*/ = -1;
                    case -1 :
                      
                      if (k/*_isYieldSafe*/)return undefined;
                      
                      a/*Runtime*/.throwStopIteration();
                      
                  }
                  
                };
            return a/*Runtime*/.createGenerator(j/*_mochaGenerator*/,
            function () {
              g/*_yieldState*/ = -1;
            },this);
          }();
        });
        return e/*_mochaLocalTmp11*/;
      }
      function i/*values*/(c/*obj*/) {
        var e/*_mochaLocalTmp7*/ = {};
        
        a/*Runtime*/.createUnenumProp(e/*_mochaLocalTmp7*/,b/*iterator*/,
        function () {
          return function () {
            var i/*_mochaIsNewBorn*/ = true,
                k/*_yieldResult*/ = undefined,
                f/*_yieldState*/ = 0,
                b/*length*/,
                e/*_mochaLocalTmp6*/,
                h/*x*/,
                g/*_mochaLocalTmp5*/ = [],
                j/*_mochaGenerator*/ = function (l/*_isYieldSend*/,k/*_isYieldSafe*/) {
                  !l/*_isYieldSend*/?i/*_mochaIsNewBorn*/ = false : l/*_isYieldSend*/ && i/*_mochaIsNewBorn*/ && arguments[1] !== undefined && a/*Runtime*/.exceptionHandler('attempt to send to newborn generator.');
                  
                  while (1)
                  switch (f/*_yieldState*/) {
                    case 0 :
                      
                      for (var j/*_mochaLocalTmp4*/ in c/*obj*/)
                      g/*_mochaLocalTmp5*/.push(j/*_mochaLocalTmp4*/);
                      
                      e/*_mochaLocalTmp6*/ = 0;
                      
                      b/*length*/ = g/*_mochaLocalTmp5*/.length;
                      
                      if (!(e/*_mochaLocalTmp6*/<b/*length*/)){
                        
                        f/*_yieldState*/ = -1;
                        break;
                      }
                    case 1 :
                      
                      h/*x*/ = g/*_mochaLocalTmp5*/[e/*_mochaLocalTmp6*/];
                      
                      if (d/*hasOwn*/.call(c/*obj*/,h/*x*/)){
                        
                        f/*_yieldState*/ = 2;
                        break;
                      } else {
                        
                        f/*_yieldState*/ = 3;
                        break;
                      }
                    case 2 :
                      
                      f/*_yieldState*/ = 3;
                      return c/*obj*/[h/*x*/];
                    case 3 :
                      
                      f/*_yieldState*/ = 4;
                      break;
                    case 4 :
                      
                       ++ e/*_mochaLocalTmp6*/;
                      
                      if (e/*_mochaLocalTmp6*/<b/*length*/){
                        
                        f/*_yieldState*/ = 1;
                        break;
                      } else f/*_yieldState*/ = -1;
                    case -1 :
                      
                      if (k/*_isYieldSafe*/)return undefined;
                      
                      a/*Runtime*/.throwStopIteration();
                      
                  }
                  
                };
            return a/*Runtime*/.createGenerator(j/*_mochaGenerator*/,
            function () {
              f/*_yieldState*/ = -1;
            },this);
          }();
        });
        return e/*_mochaLocalTmp7*/;
      }
      function j/*keys*/(c/*obj*/) {
        var e/*_mochaLocalTmp3*/ = {};
        
        a/*Runtime*/.createUnenumProp(e/*_mochaLocalTmp3*/,b/*iterator*/,
        function () {
          return function () {
            var i/*_mochaIsNewBorn*/ = true,
                k/*_yieldResult*/ = undefined,
                f/*_yieldState*/ = 0,
                e/*length*/,
                h/*_mochaLocalTmp2*/,
                b/*x*/,
                g/*_mochaLocalTmp1*/ = [],
                j/*_mochaGenerator*/ = function (l/*_isYieldSend*/,k/*_isYieldSafe*/) {
                  !l/*_isYieldSend*/?i/*_mochaIsNewBorn*/ = false : l/*_isYieldSend*/ && i/*_mochaIsNewBorn*/ && arguments[1] !== undefined && a/*Runtime*/.exceptionHandler('attempt to send to newborn generator.');
                  
                  while (1)
                  switch (f/*_yieldState*/) {
                    case 0 :
                      
                      for (var j/*_mochaLocalTmp0*/ in c/*obj*/)
                      g/*_mochaLocalTmp1*/.push(j/*_mochaLocalTmp0*/);
                      
                      h/*_mochaLocalTmp2*/ = 0;
                      
                      e/*length*/ = g/*_mochaLocalTmp1*/.length;
                      
                      if (!(h/*_mochaLocalTmp2*/<e/*length*/)){
                        
                        f/*_yieldState*/ = -1;
                        break;
                      }
                    case 1 :
                      
                      b/*x*/ = g/*_mochaLocalTmp1*/[h/*_mochaLocalTmp2*/];
                      
                      if (d/*hasOwn*/.call(c/*obj*/,b/*x*/)){
                        
                        f/*_yieldState*/ = 2;
                        break;
                      } else {
                        
                        f/*_yieldState*/ = 3;
                        break;
                      }
                    case 2 :
                      
                      f/*_yieldState*/ = 3;
                      return b/*x*/;
                    case 3 :
                      
                      f/*_yieldState*/ = 4;
                      break;
                    case 4 :
                      
                       ++ h/*_mochaLocalTmp2*/;
                      
                      if (h/*_mochaLocalTmp2*/<e/*length*/){
                        
                        f/*_yieldState*/ = 1;
                        break;
                      } else f/*_yieldState*/ = -1;
                    case -1 :
                      
                      if (k/*_isYieldSafe*/)return undefined;
                      
                      a/*Runtime*/.throwStopIteration();
                      
                  }
                  
                };
            return a/*Runtime*/.createGenerator(j/*_mochaGenerator*/,
            function () {
              f/*_yieldState*/ = -1;
            },this);
          }();
        });
        return e/*_mochaLocalTmp3*/;
      }
      var k/*_mochaLocalExport*/ = c/*_mochaGlobalAlias*/,
          d/*hasOwn*/ = {}.hasOwnProperty,
          b/*iterator*/ = k/*_mochaLocalExport*/.iterator = "__mocha_iterator_special_key__";
      
      k/*_mochaLocalExport*/.keys = j/*keys*/;
      
      k/*_mochaLocalExport*/.values = i/*values*/;
      
      k/*_mochaLocalExport*/.items = g/*items*/;
      
      k/*_mochaLocalExport*/.allKeys = f/*allKeys*/;
      
      k/*_mochaLocalExport*/.allValues = e/*allValues*/;
      
      k/*_mochaLocalExport*/.allItems = h/*allItems*/;
      return k/*_mochaLocalExport*/;
    }();
  }();
  
  !function () {
    b/*_mochaGlobalExport*/['-759650552-array_comprehensions_test.js'] = {};
    
    var h/*_mochaGlobalAlias*/ = b/*_mochaGlobalExport*/['-759650552-array_comprehensions_test.js'],
        g/*_mochaLocalTmp0*/ = b/*_mochaGlobalExport*/.iterators,
        d/*items*/ = g/*_mochaLocalTmp0*/.items,
        c/*testTarget*/ =  {
          value1 : 100,
          value2 : 200,
          value3 : 300
        },
        f/*cmpTest*/ = function () {
          var e/*_mochaLocalTmp1*/ = [];
          
          for (var d/*prop*/ in c/*testTarget*/){
            
            d/*prop*/ = c/*testTarget*/[d/*prop*/];
            
            e/*_mochaLocalTmp1*/.push(d/*prop*/);
          }
          return e/*_mochaLocalTmp1*/;
        }.call(this);
    
    f/*cmpTest*/ = function () {
      var b/*_mochaLocalTmp2*/ = [];
      
      for (var a/*prop*/ in c/*testTarget*/)
      b/*_mochaLocalTmp2*/.push(a/*prop*/);
      return b/*_mochaLocalTmp2*/;
    }.call(this);
    
    f/*cmpTest*/ = function () {
      var g/*_mochaLocalTmp3*/ = [],
          f/*prop*/,
          e/*_mochaLocalTmp4*/ = d/*items*/(c/*testTarget*/);
      
      e/*_mochaLocalTmp4*/ = a/*Runtime*/.hasIterator(e/*_mochaLocalTmp4*/)?a/*Runtime*/.getIterator(e/*_mochaLocalTmp4*/) : e/*_mochaLocalTmp4*/;
      
      if (e/*_mochaLocalTmp4*/.__nothrowNext__)while ((f/*prop*/ = e/*_mochaLocalTmp4*/.__nothrowNext__()))g/*_mochaLocalTmp3*/.push(f/*prop*/);
       else a/*Runtime*/.exceptionHandler(19,'..///Users/aono_taketoshi/github/mocha/src/test/js/harmony/array_comprehensions_test.js','for of statement expect iterator or generator object.');
      return g/*_mochaLocalTmp3*/;
    }.call(this);
    
    var f/*cmpTest*/ = function () {
          var b/*_mochaLocalTmp5*/ = [];
          
          for (var a/*prop*/ in c/*testTarget*/){
            
            a/*prop*/ = c/*testTarget*/[a/*prop*/];
            
            a/*prop*/ === 200 && b/*_mochaLocalTmp5*/.push(a/*prop*/);
          }
          return b/*_mochaLocalTmp5*/;
        }.call(this);
    
    f/*cmpTest*/ = function () {
      var b/*_mochaLocalTmp6*/ = [];
      
      for (var a/*prop*/ in c/*testTarget*/)
      a/*prop*/ === "value2" && b/*_mochaLocalTmp6*/.push(a/*prop*/);
      return b/*_mochaLocalTmp6*/;
    }.call(this);
    
    f/*cmpTest*/ = function () {
      var f/*_mochaLocalTmp7*/ = [],
          e/*prop*/,
          b/*_mochaLocalTmp8*/ = d/*items*/(c/*testTarget*/);
      
      b/*_mochaLocalTmp8*/ = a/*Runtime*/.hasIterator(b/*_mochaLocalTmp8*/)?a/*Runtime*/.getIterator(b/*_mochaLocalTmp8*/) : b/*_mochaLocalTmp8*/;
      
      if (b/*_mochaLocalTmp8*/.__nothrowNext__)while ((e/*prop*/ = b/*_mochaLocalTmp8*/.__nothrowNext__()))e/*prop*/[1] === 200 && f/*_mochaLocalTmp7*/.push(e/*prop*/);
       else a/*Runtime*/.exceptionHandler(34,'..///Users/aono_taketoshi/github/mocha/src/test/js/harmony/array_comprehensions_test.js','for of statement expect iterator or generator object.');
      return f/*_mochaLocalTmp7*/;
    }.call(this);
    
    c/*testTarget*/ =  {
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
    
    f/*cmpTest*/ = function () {
      var d/*_mochaLocalTmp9*/ = [];
      
      for (var b/*prop*/ in c/*testTarget*/){
        
        b/*prop*/ = c/*testTarget*/[b/*prop*/];
        
        for (var a/*x*/ in b/*prop*/){
          
          a/*x*/ = b/*prop*/[a/*x*/];
          
          d/*_mochaLocalTmp9*/.push(a/*x*/);
        }
        
      }
      return d/*_mochaLocalTmp9*/;
    }.call(this);
    
    f/*cmpTest*/ = function () {
      var d/*_mochaLocalTmp10*/ = [];
      
      for (var b/*prop*/ in c/*testTarget*/){
        
        b/*prop*/ = c/*testTarget*/[b/*prop*/];
        
        for (var a/*x*/ in b/*prop*/)d/*_mochaLocalTmp10*/.push(a/*x*/);
      }
      return d/*_mochaLocalTmp10*/;
    }.call(this);
    
    f/*cmpTest*/ = function () {
      var g/*_mochaLocalTmp11*/ = [];
      
      for (var e/*prop*/ in c/*testTarget*/){
        
        e/*prop*/ = c/*testTarget*/[e/*prop*/];
        
        var f/*x*/;
        
        var b/*_mochaLocalTmp12*/ = d/*items*/(e/*prop*/);
        
        b/*_mochaLocalTmp12*/ = a/*Runtime*/.hasIterator(b/*_mochaLocalTmp12*/)?a/*Runtime*/.getIterator(b/*_mochaLocalTmp12*/) : b/*_mochaLocalTmp12*/;
        
        if (b/*_mochaLocalTmp12*/.__nothrowNext__)while ((f/*x*/ = b/*_mochaLocalTmp12*/.__nothrowNext__()))g/*_mochaLocalTmp11*/.push(f/*x*/);
         else a/*Runtime*/.exceptionHandler(54,'..///Users/aono_taketoshi/github/mocha/src/test/js/harmony/array_comprehensions_test.js','for of statement expect iterator or generator object.');
      }
      return g/*_mochaLocalTmp11*/;
    }.call(this);
    
    var e/*m*/ = function (b/*_mochaLocalTmp13*/) {
          "use strict";
          var a/*v*/ = b/*_mochaLocalTmp13*/.v;
        };
  }();
}();
