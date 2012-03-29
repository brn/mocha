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
    b/*_mochaGlobalExport*/['-1426553882-knockout-2.0.0.debug.js'] = {};
    
    var c/*_mochaGlobalAlias*/ = b/*_mochaGlobalExport*/['-1426553882-knockout-2.0.0.debug.js'];
    
    !function (a/*window*/,undefined) {
      function f/*ensureDropdownSelectionIsConsistentWithModelValue*/(d/*element*/,c/*modelValue*/,a/*preferModelValue*/) {
        a/*preferModelValue*/ && c/*modelValue*/ !== b/*ko*/.selectExtensions.readValue(d/*element*/) && b/*ko*/.selectExtensions.writeValue(d/*element*/,c/*modelValue*/);
        
        c/*modelValue*/ !== b/*ko*/.selectExtensions.readValue(d/*element*/) && b/*ko*/.utils.triggerEvent(d/*element*/,"change");
      }
      function e/*prepareOptions*/(c/*evaluatorFunctionOrOptions*/,b/*evaluatorFunctionTarget*/,a/*options*/) {
        if (c/*evaluatorFunctionOrOptions*/ && typeof c/*evaluatorFunctionOrOptions*/ == "object")a/*options*/ = c/*evaluatorFunctionOrOptions*/;
         else {
          
          a/*options*/ = a/*options*/ || {};
          
          a/*options*/.read = c/*evaluatorFunctionOrOptions*/ || a/*options*/.read;
        }
        
        if (typeof a/*options*/.read != "function")throw "Pass a function that returns the value of the dependentObservable"
        return a/*options*/;
      }
      function i/*applyExtenders*/(e/*requestedExtenders*/) {
        var d/*target*/ = this;
        
        if (e/*requestedExtenders*/)for (var c/*key*/ in e/*requestedExtenders*/){
          
          var a/*extenderHandler*/ = b/*ko*/.extenders[c/*key*/];
          
          typeof a/*extenderHandler*/ == 'function' && (d/*target*/ = a/*extenderHandler*/(d/*target*/,e/*requestedExtenders*/[c/*key*/]));
        }
        return d/*target*/;
      }
      var b/*ko*/ = a/*window*/.ko = {};
      
      b/*ko*/.exportSymbol = function (f/*publicPath*/,d/*object*/) {
        var c/*tokens*/ = f/*publicPath*/.split("."),
            b/*target*/ = a/*window*/;
        
        for (var e/*i*/ = 0;e/*i*/<c/*tokens*/.length-1;e/*i*/ ++ )
        b/*target*/ = b/*target*/[c/*tokens*/[e/*i*/]];
        
        b/*target*/[c/*tokens*/[c/*tokens*/.length-1]] = d/*object*/;
      };
      
      b/*ko*/.exportProperty = function (c/*owner*/,a/*publicName*/,b/*object*/) {
        c/*owner*/[a/*publicName*/] = b/*object*/;
      };
      
      b/*ko*/.utils = new function () {
        function d/*isClickOnCheckableElement*/(c/*element*/,b/*eventType*/) {
          if ((c/*element*/.tagName != "INPUT") || !c/*element*/.type)return false;
          
          if (b/*eventType*/.toLowerCase() != "click")return false;
          
          var a/*inputType*/ = c/*element*/.type.toLowerCase();
          return (a/*inputType*/ == "checkbox") || (a/*inputType*/ == "radio");
        }
        var c/*stringTrimRegex*/ = /^(\s|\u00A0)+|(\s|\u00A0)+$/g,
            n/*knownEvents*/ = {},
            e/*knownEventTypesByEventName*/ = {},
            m/*keyEventTypeName*/ = /Firefox\/2/i.test(navigator.userAgent)?'KeyboardEvent' : 'UIEvents';
        
        n/*knownEvents*/[m/*keyEventTypeName*/] = ['keyup','keydown','keypress'];
        
        n/*knownEvents*/.MouseEvents = ['click','dblclick','mousedown','mouseup','mousemove','mouseover','mouseout','mouseenter','mouseleave'];
        
        for (var k/*eventType*/ in n/*knownEvents*/){
          
          var j/*knownEventsForType*/ = n/*knownEvents*/[k/*eventType*/];
          
          if (j/*knownEventsForType*/.length)for (var i/*i*/ = 0,l/*j*/ = j/*knownEventsForType*/.length;i/*i*/<l/*j*/;i/*i*/ ++ )
          e/*knownEventTypesByEventName*/[j/*knownEventsForType*/[i/*i*/]] = k/*eventType*/;
        }
        
        var f/*ieVersion*/ = (function () {
              var c/*version*/ = 3,
                  b/*div*/ = document.createElement('div'),
                  a/*iElems*/ = b/*div*/.getElementsByTagName('i');
              
              while (b/*div*/.innerHTML = '<!--[if gt IE '+( ++ c/*version*/)+']><i></i><![endif]-->', a/*iElems*/[0])return c/*version*/>4?c/*version*/ : undefined;
            }()),
            g/*isIe6*/ = f/*ieVersion*/ === 6,
            h/*isIe7*/ = f/*ieVersion*/ === 7;
        return  {
          fieldsIncludedWithJsonPost : ['authenticity_token',/^__RequestVerificationToken(_.*)?$/],
          arrayForEach : function (d/*array*/,c/*action*/) {
            for (var b/*i*/ = 0,a/*j*/ = d/*array*/.length;b/*i*/<a/*j*/;b/*i*/ ++ ){
              
              c/*action*/(d/*array*/[b/*i*/]);
            }
            
          },
          arrayIndexOf : function (d/*array*/,c/*item*/) {
            if (typeof Array.prototype.indexOf == "function"){
              return Array.prototype.indexOf.call(d/*array*/,c/*item*/);
            }
            
            for (var b/*i*/ = 0,a/*j*/ = d/*array*/.length;b/*i*/<a/*j*/;b/*i*/ ++ ){
              
              if (d/*array*/[b/*i*/] === c/*item*/){
                return b/*i*/;
              }
              
            }
            return -1;
          },
          arrayFirst : function (e/*array*/,d/*predicate*/,c/*predicateOwner*/) {
            for (var b/*i*/ = 0,a/*j*/ = e/*array*/.length;b/*i*/<a/*j*/;b/*i*/ ++ ){
              
              if (d/*predicate*/.call(c/*predicateOwner*/,e/*array*/[b/*i*/])){
                return e/*array*/[b/*i*/];
              }
              
            }
            return null;
          },
          arrayRemoveItem : function (d/*array*/,c/*itemToRemove*/) {
            var a/*index*/ = b/*ko*/.utils.arrayIndexOf(d/*array*/,c/*itemToRemove*/);
            
            if (a/*index*/ >= 0){
              
              d/*array*/.splice(a/*index*/,1);
            }
            
          },
          arrayGetDistinctValues : function (e/*array*/) {
            e/*array*/ = e/*array*/ || [];
            
            var d/*result*/ = [];
            
            for (var c/*i*/ = 0,a/*j*/ = e/*array*/.length;c/*i*/<a/*j*/;c/*i*/ ++ ){
              
              if (b/*ko*/.utils.arrayIndexOf(d/*result*/,e/*array*/[c/*i*/])<0){
                
                d/*result*/.push(e/*array*/[c/*i*/]);
              }
              
            }
            return d/*result*/;
          },
          arrayMap : function (e/*array*/,d/*mapping*/) {
            e/*array*/ = e/*array*/ || [];
            
            var c/*result*/ = [];
            
            for (var b/*i*/ = 0,a/*j*/ = e/*array*/.length;b/*i*/<a/*j*/;b/*i*/ ++ ){
              
              c/*result*/.push(d/*mapping*/(e/*array*/[b/*i*/]));
            }
            return c/*result*/;
          },
          arrayFilter : function (e/*array*/,d/*predicate*/) {
            e/*array*/ = e/*array*/ || [];
            
            var c/*result*/ = [];
            
            for (var b/*i*/ = 0,a/*j*/ = e/*array*/.length;b/*i*/<a/*j*/;b/*i*/ ++ ){
              
              if (d/*predicate*/(e/*array*/[b/*i*/])){
                
                c/*result*/.push(e/*array*/[b/*i*/]);
              }
              
            }
            return c/*result*/;
          },
          arrayPushAll : function (d/*array*/,c/*valuesToPush*/) {
            for (var b/*i*/ = 0,a/*j*/ = c/*valuesToPush*/.length;b/*i*/<a/*j*/;b/*i*/ ++ ){
              
              d/*array*/.push(c/*valuesToPush*/[b/*i*/]);
            }
            return d/*array*/;
          },
          extend : function (c/*target*/,b/*source*/) {
            for (var a/*prop*/ in b/*source*/){
              
              if (b/*source*/.hasOwnProperty(a/*prop*/)){
                
                c/*target*/[a/*prop*/] = b/*source*/[a/*prop*/];
              }
              
            }
            return c/*target*/;
          },
          emptyDomNode : function (a/*domNode*/) {
            while (a/*domNode*/.firstChild){
              
              b/*ko*/.removeNode(a/*domNode*/.firstChild);
            }
            
          },
          setDomNodeChildren : function (a/*domNode*/,c/*childNodes*/) {
            b/*ko*/.utils.emptyDomNode(a/*domNode*/);
            
            if (c/*childNodes*/){
              
              b/*ko*/.utils.arrayForEach(c/*childNodes*/,
              function (b/*childNode*/) {
                a/*domNode*/.appendChild(b/*childNode*/);
              });
            }
            
          },
          replaceDomNodes : function (h/*nodeToReplaceOrNodeArray*/,g/*newNodesArray*/) {
            var f/*nodesToReplaceArray*/ = h/*nodeToReplaceOrNodeArray*/.nodeType?[h/*nodeToReplaceOrNodeArray*/] : h/*nodeToReplaceOrNodeArray*/;
            
            if (f/*nodesToReplaceArray*/.length>0){
              
              var d/*insertionPoint*/ = f/*nodesToReplaceArray*/[0];
              
              var e/*parent*/ = d/*insertionPoint*/.parentNode;
              
              for (var c/*i*/ = 0,a/*j*/ = g/*newNodesArray*/.length;c/*i*/<a/*j*/;c/*i*/ ++ ){
                
                e/*parent*/.insertBefore(g/*newNodesArray*/[c/*i*/],d/*insertionPoint*/);
              }
              
              for (var c/*i*/ = 0,a/*j*/ = f/*nodesToReplaceArray*/.length;c/*i*/<a/*j*/;c/*i*/ ++ ){
                
                b/*ko*/.removeNode(f/*nodesToReplaceArray*/[c/*i*/]);
              }
              
            }
            
          },
          setOptionNodeSelectionState : function (b/*optionNode*/,a/*isSelected*/) {
            if (navigator.userAgent.indexOf("MSIE 6") >= 0){
              
              b/*optionNode*/.setAttribute("selected",a/*isSelected*/);
            } else b/*optionNode*/.selected = a/*isSelected*/;
          },
          stringTrim : function (d/*string*/) {
            return (d/*string*/ || "").replace(c/*stringTrimRegex*/,"");
          },
          stringTokenize : function (h/*string*/,f/*delimiter*/) {
            var e/*result*/ = [];
            
            var g/*tokens*/ = (h/*string*/ || "").split(f/*delimiter*/);
            
            for (var d/*i*/ = 0,c/*j*/ = g/*tokens*/.length;d/*i*/<c/*j*/;d/*i*/ ++ ){
              
              var a/*trimmed*/ = b/*ko*/.utils.stringTrim(g/*tokens*/[d/*i*/]);
              
              if (a/*trimmed*/ !== ""){
                
                e/*result*/.push(a/*trimmed*/);
              }
              
            }
            return e/*result*/;
          },
          stringStartsWith : function (b/*string*/,a/*startsWith*/) {
            b/*string*/ = b/*string*/ || "";
            
            if (a/*startsWith*/.length>b/*string*/.length){
              return false;
            }
            return b/*string*/.substring(0,a/*startsWith*/.length) === a/*startsWith*/;
          },
          evalWithinScope : function (d/*expression*/) {
            var b/*scopes*/ = Array.prototype.slice.call(arguments,1);
            
            var c/*functionBody*/ = "return ("+d/*expression*/+")";
            
            for (var a/*i*/ = 0;a/*i*/<b/*scopes*/.length;a/*i*/ ++ ){
              
              if (b/*scopes*/[a/*i*/] && typeof b/*scopes*/[a/*i*/] == "object"){
                
                c/*functionBody*/ = "with(sc["+a/*i*/+"]) { "+c/*functionBody*/+" } ";
              }
              
            }
            return (new Function("sc",c/*functionBody*/))(b/*scopes*/);
          },
          domNodeIsContainedBy : function (b/*node*/,a/*containedByNode*/) {
            if (a/*containedByNode*/.compareDocumentPosition){
              return (a/*containedByNode*/.compareDocumentPosition(b/*node*/)&16) == 16;
            }
            
            while (b/*node*/ != null){
              
              if (b/*node*/ == a/*containedByNode*/){
                return true;
              }
              
              b/*node*/ = b/*node*/.parentNode;
            }
            return false;
          },
          domNodeIsAttachedToDocument : function (a/*node*/) {
            return b/*ko*/.utils.domNodeIsContainedBy(a/*node*/,document);
          },
          registerEventHandler : function (b/*element*/,e/*eventType*/,c/*handler*/) {
            if (typeof jQuery != "undefined"){
              
              if (d/*isClickOnCheckableElement*/(b/*element*/,e/*eventType*/)){
                
                var a/*originalHandler*/ = c/*handler*/;
                
                c/*handler*/ = function (d/*event*/,c/*eventData*/) {
                  var b/*jQuerySuppliedCheckedState*/ = this.checked;
                  
                  if (c/*eventData*/){
                    
                    this.checked = c/*eventData*/.checkedStateBeforeEvent !== true;
                  }
                  
                  a/*originalHandler*/.call(this,d/*event*/);
                  
                  this.checked = b/*jQuerySuppliedCheckedState*/;
                };
              }
              
              jQuery(b/*element*/)['bind'](e/*eventType*/,c/*handler*/);
            } else if (typeof b/*element*/.addEventListener == "function"){
              
              b/*element*/.addEventListener(e/*eventType*/,c/*handler*/,false);
            } else if (typeof b/*element*/.attachEvent != "undefined"){
              
              b/*element*/.attachEvent("on"+e/*eventType*/,
              function (d/*event*/) {
                c/*handler*/.call(b/*element*/,d/*event*/);
              });
            } else throw new Error("Browser doesn't support addEventListener or attachEvent")
            
          },
          triggerEvent : function (j/*element*/,i/*eventType*/) {
            if (!(j/*element*/ && j/*element*/.nodeType)){
              throw new Error("element must be a DOM node when calling triggerEvent")
              
            }
            
            if (typeof jQuery != "undefined"){
              
              var h/*eventData*/ = [];
              
              if (d/*isClickOnCheckableElement*/(j/*element*/,i/*eventType*/)){
                
                h/*eventData*/.push( {
                  checkedStateBeforeEvent : j/*element*/.checked
                });
              }
              
              jQuery(j/*element*/)['trigger'](i/*eventType*/,h/*eventData*/);
            } else if (typeof document.createEvent == "function"){
              if (typeof j/*element*/.dispatchEvent == "function"){
                
                var g/*eventCategory*/ = e/*knownEventTypesByEventName*/[i/*eventType*/] || "HTMLEvents";
                
                var f/*event*/ = document.createEvent(g/*eventCategory*/);
                
                f/*event*/.initEvent(i/*eventType*/,true,true,a/*window*/,0,0,0,0,0,false,false,false,false,0,j/*element*/);
                
                j/*element*/.dispatchEvent(f/*event*/);
              } else throw new Error("The supplied element doesn't support dispatchEvent")
              
            } else if (typeof j/*element*/.fireEvent != "undefined"){
              if (i/*eventType*/ == "click"){
                if ((j/*element*/.tagName == "INPUT") && ((j/*element*/.type.toLowerCase() == "checkbox") || (j/*element*/.type.toLowerCase() == "radio"))){
                  
                  j/*element*/.checked = j/*element*/.checked !== true;
                }
                
              }
              
              j/*element*/.fireEvent("on"+i/*eventType*/);
            } else throw new Error("Browser doesn't support triggering events")
            
          },
          unwrapObservable : function (a/*value*/) {
            return b/*ko*/.isObservable(a/*value*/)?a/*value*/() : a/*value*/;
          },
          domNodeHasCssClass : function (d/*node*/,c/*className*/) {
            var a/*currentClassNames*/ = (d/*node*/.className || "").split(/\s+/);
            return b/*ko*/.utils.arrayIndexOf(a/*currentClassNames*/,c/*className*/) >= 0;
          },
          toggleDomNodeCssClass : function (h/*node*/,g/*className*/,f/*shouldHaveClass*/) {
            var e/*hasClass*/ = b/*ko*/.utils.domNodeHasCssClass(h/*node*/,g/*className*/);
            
            if (f/*shouldHaveClass*/ && !e/*hasClass*/){
              
              h/*node*/.className = (h/*node*/.className || "")+" "+g/*className*/;
            } else if (e/*hasClass*/ && !f/*shouldHaveClass*/){
              
              var c/*currentClassNames*/ = (h/*node*/.className || "").split(/\s+/);
              
              var d/*newClassName*/ = "";
              
              for (var a/*i*/ = 0;a/*i*/<c/*currentClassNames*/.length;a/*i*/ ++ ){
                if (c/*currentClassNames*/[a/*i*/] != g/*className*/){
                  
                  d/*newClassName*/ += c/*currentClassNames*/[a/*i*/]+" ";
                }
                
              }
              
              h/*node*/.className = b/*ko*/.utils.stringTrim(d/*newClassName*/);
            }
            
          },
          outerHTML : function (i/*node*/) {
            if (f/*ieVersion*/ === undefined){
              
              var h/*nativeOuterHtml*/ = i/*node*/.outerHTML;
              
              if (typeof h/*nativeOuterHtml*/ == "string"){
                return h/*nativeOuterHtml*/;
              }
              
            }
            
            var g/*dummyContainer*/ = a/*window*/.document.createElement("div");
            
            g/*dummyContainer*/.appendChild(i/*node*/.cloneNode(true));
            return g/*dummyContainer*/.innerHTML;
          },
          setTextContent : function (d/*element*/,c/*textContent*/) {
            var a/*value*/ = b/*ko*/.utils.unwrapObservable(c/*textContent*/);
            
            if ((a/*value*/ === null) || (a/*value*/ === undefined)){
              
              a/*value*/ = "";
            }
            
            'innerText' in d/*element*/?d/*element*/.innerText = a/*value*/ : d/*element*/.textContent = a/*value*/;
            
            if (f/*ieVersion*/ >= 9){
              
              d/*element*/.innerHTML = d/*element*/.innerHTML;
            }
            
          },
          range : function (e/*min*/,d/*max*/) {
            e/*min*/ = b/*ko*/.utils.unwrapObservable(e/*min*/);
            
            d/*max*/ = b/*ko*/.utils.unwrapObservable(d/*max*/);
            
            var c/*result*/ = [];
            
            for (var a/*i*/ = e/*min*/;a/*i*/ <= d/*max*/;a/*i*/ ++ ){
              
              c/*result*/.push(a/*i*/);
            }
            return c/*result*/;
          },
          makeArray : function (d/*arrayLikeObject*/) {
            var c/*result*/ = [];
            
            for (var b/*i*/ = 0,a/*j*/ = d/*arrayLikeObject*/.length;b/*i*/<a/*j*/;b/*i*/ ++ ){
              
              c/*result*/.push(d/*arrayLikeObject*/[b/*i*/]);
            }
            return c/*result*/;
          },
          isIe6 : g/*isIe6*/,
          isIe7 : h/*isIe7*/,
          getFormFields : function (g/*form*/,a/*fieldName*/) {
            var e/*fields*/ = b/*ko*/.utils.makeArray(g/*form*/.getElementsByTagName("INPUT")).concat(b/*ko*/.utils.makeArray(g/*form*/.getElementsByTagName("TEXTAREA")));
            
            var f/*isMatchingField*/ = (typeof a/*fieldName*/ == 'string')?function (b/*field*/) {
                  return b/*field*/.name === a/*fieldName*/;
                } : function (b/*field*/) {
                  return a/*fieldName*/.test(b/*field*/.name);
                };
            
            var d/*matches*/ = [];
            
            for (var c/*i*/ = e/*fields*/.length-1;c/*i*/ >= 0;c/*i*/ -- ){
              
              if (f/*isMatchingField*/(e/*fields*/[c/*i*/])){
                
                d/*matches*/.push(e/*fields*/[c/*i*/]);
              }
              
            }
            return d/*matches*/;
          },
          parseJson : function (c/*jsonString*/) {
            if (typeof c/*jsonString*/ == "string"){
              
              c/*jsonString*/ = b/*ko*/.utils.stringTrim(c/*jsonString*/);
              
              if (c/*jsonString*/){
                
                if (a/*window*/.JSON && a/*window*/.JSON.parse){
                  return a/*window*/.JSON.parse(c/*jsonString*/);
                }
                return (new Function("return "+c/*jsonString*/))();
              }
              
            }
            return null;
          },
          stringifyJson : function (a/*data*/) {
            if ((typeof JSON == "undefined") || (typeof JSON.stringify == "undefined")){
              throw new Error("Cannot find JSON.stringify(). Some browsers (e.g., IE < 8) don't support it natively, but you can overcome this by adding a script reference to json2.js, downloadable from http://www.json.org/json2.js")
              
            }
            return JSON.stringify(b/*ko*/.utils.unwrapObservable(a/*data*/));
          },
          postJson : function (i/*urlOrForm*/,n/*data*/,m/*options*/) {
            m/*options*/ = m/*options*/ || {};
            
            var k/*params*/ = m/*options*/['params'] || {};
            
            var j/*includeFields*/ = m/*options*/['includeFields'] || this.fieldsIncludedWithJsonPost;
            
            var e/*url*/ = i/*urlOrForm*/;
            
            if ((typeof i/*urlOrForm*/ == 'object') && (i/*urlOrForm*/.tagName == "FORM")){
              
              var g/*originalForm*/ = i/*urlOrForm*/;
              
              e/*url*/ = g/*originalForm*/.action;
              
              for (var h/*i*/ = j/*includeFields*/.length-1;h/*i*/ >= 0;h/*i*/ -- ){
                
                var f/*fields*/ = b/*ko*/.utils.getFormFields(g/*originalForm*/,j/*includeFields*/[h/*i*/]);
                
                for (var d/*j*/ = f/*fields*/.length-1;d/*j*/ >= 0;d/*j*/ -- ){
                  
                  k/*params*/[f/*fields*/[d/*j*/].name] = f/*fields*/[d/*j*/].value;
                }
                
              }
              
            }
            
            n/*data*/ = b/*ko*/.utils.unwrapObservable(n/*data*/);
            
            var a/*form*/ = document.createElement("FORM");
            
            a/*form*/.style.display = "none";
            
            a/*form*/.action = e/*url*/;
            
            a/*form*/.method = "post";
            
            for (var l/*key*/ in n/*data*/){
              
              var c/*input*/ = document.createElement("INPUT");
              
              c/*input*/.name = l/*key*/;
              
              c/*input*/.value = b/*ko*/.utils.stringifyJson(b/*ko*/.utils.unwrapObservable(n/*data*/[l/*key*/]));
              
              a/*form*/.appendChild(c/*input*/);
            }
            
            for (var l/*key*/ in k/*params*/){
              
              var c/*input*/ = document.createElement("INPUT");
              
              c/*input*/.name = l/*key*/;
              
              c/*input*/.value = k/*params*/[l/*key*/];
              
              a/*form*/.appendChild(c/*input*/);
            }
            
            document.body.appendChild(a/*form*/);
            
            m/*options*/['submitter']?m/*options*/['submitter'](a/*form*/) : a/*form*/.submit();
            
            setTimeout(function () {
              a/*form*/.parentNode.removeChild(a/*form*/);
            },0);
          }
        };
      }();
      
      b/*ko*/.exportSymbol('ko.utils',b/*ko*/.utils);
      
      b/*ko*/.utils.arrayForEach([['arrayForEach',b/*ko*/.utils.arrayForEach],['arrayFirst',b/*ko*/.utils.arrayFirst],['arrayFilter',b/*ko*/.utils.arrayFilter],['arrayGetDistinctValues',b/*ko*/.utils.arrayGetDistinctValues],['arrayIndexOf',b/*ko*/.utils.arrayIndexOf],['arrayMap',b/*ko*/.utils.arrayMap],['arrayPushAll',b/*ko*/.utils.arrayPushAll],['arrayRemoveItem',b/*ko*/.utils.arrayRemoveItem],['extend',b/*ko*/.utils.extend],['fieldsIncludedWithJsonPost',b/*ko*/.utils.fieldsIncludedWithJsonPost],['getFormFields',b/*ko*/.utils.getFormFields],['postJson',b/*ko*/.utils.postJson],['parseJson',b/*ko*/.utils.parseJson],['registerEventHandler',b/*ko*/.utils.registerEventHandler],['stringifyJson',b/*ko*/.utils.stringifyJson],['range',b/*ko*/.utils.range],['toggleDomNodeCssClass',b/*ko*/.utils.toggleDomNodeCssClass],['triggerEvent',b/*ko*/.utils.triggerEvent],['unwrapObservable',b/*ko*/.utils.unwrapObservable]],
      function (a/*item*/) {
        b/*ko*/.exportSymbol('ko.utils.'+a/*item*/[0],a/*item*/[1]);
      });
      
      !Function.prototype.bind && (Function.prototype.bind = function (a/*object*/) {
        var c/*originalFunction*/ = this,
            b/*args*/ = [].slice.call(arguments),
            a/*object*/ = b/*args*/.shift();
        return function () {
          return c/*originalFunction*/.apply(a/*object*/,b/*args*/.concat([].slice.call(arguments)));
        };
      });
      
      b/*ko*/.utils.domData = new function () {
        var a/*uniqueId*/ = 0,
            d/*dataStoreKeyExpandoPropertyName*/ = "__ko__"+(new Date).getTime(),
            c/*dataStore*/ = {};
        return  {
          get : function (d/*node*/,c/*key*/) {
            var a/*allDataForNode*/ = b/*ko*/.utils.domData.getAll(d/*node*/,false);
            return a/*allDataForNode*/ === undefined?undefined : a/*allDataForNode*/[c/*key*/];
          },
          set : function (e/*node*/,c/*key*/,d/*value*/) {
            if (d/*value*/ === undefined){
              
              if (b/*ko*/.utils.domData.getAll(e/*node*/,false) === undefined){
                return ;
              }
              
            }
            
            var a/*allDataForNode*/ = b/*ko*/.utils.domData.getAll(e/*node*/,true);
            
            a/*allDataForNode*/[c/*key*/] = d/*value*/;
          },
          getAll : function (h/*node*/,g/*createIfNotFound*/) {
            var e/*dataStoreKey*/ = h/*node*/[d/*dataStoreKeyExpandoPropertyName*/];
            
            var f/*hasExistingDataStore*/ = e/*dataStoreKey*/ && (e/*dataStoreKey*/ !== "null");
            
            if (!f/*hasExistingDataStore*/){
              
              if (!g/*createIfNotFound*/){
                return undefined;
              }
              
              e/*dataStoreKey*/ = h/*node*/[d/*dataStoreKeyExpandoPropertyName*/] = "ko"+a/*uniqueId*/ ++ ;
              
              c/*dataStore*/[e/*dataStoreKey*/] = {};
            }
            return c/*dataStore*/[e/*dataStoreKey*/];
          },
          clear : function (b/*node*/) {
            var a/*dataStoreKey*/ = b/*node*/[d/*dataStoreKeyExpandoPropertyName*/];
            
            if (a/*dataStoreKey*/){
              
              delete c/*dataStore*/[a/*dataStoreKey*/];
              
              b/*node*/[d/*dataStoreKeyExpandoPropertyName*/] = null;
            }
            
          }
        };
      }();
      
      b/*ko*/.exportSymbol('ko.utils.domData',b/*ko*/.utils.domData);
      
      b/*ko*/.exportSymbol('ko.utils.domData.clear',b/*ko*/.utils.domData.clear);
      
      b/*ko*/.utils.domNodeDisposal = new function () {
        function e/*cleanSingleNode*/(f/*node*/) {
          var e/*callbacks*/ = c/*getDisposeCallbacksCollection*/(f/*node*/,false);
          
          if (e/*callbacks*/){
            
            e/*callbacks*/ = e/*callbacks*/.slice(0);
            
            for (var d/*i*/ = 0;d/*i*/<e/*callbacks*/.length;d/*i*/ ++ )e/*callbacks*/[d/*i*/](f/*node*/);
          }
          
          b/*ko*/.utils.domData.clear(f/*node*/);
          
          (typeof jQuery == "function") && (typeof jQuery.cleanData == "function") && jQuery.cleanData([f/*node*/]);
        }
        function d/*destroyCallbacksCollection*/(c/*node*/) {
          b/*ko*/.utils.domData.set(c/*node*/,a/*domDataKey*/,undefined);
        }
        function c/*getDisposeCallbacksCollection*/(e/*node*/,d/*createIfNotFound*/) {
          var c/*allDisposeCallbacks*/ = b/*ko*/.utils.domData.get(e/*node*/,a/*domDataKey*/);
          
          if ((c/*allDisposeCallbacks*/ === undefined) && d/*createIfNotFound*/){
            
            c/*allDisposeCallbacks*/ = [];
            
            b/*ko*/.utils.domData.set(e/*node*/,a/*domDataKey*/,c/*allDisposeCallbacks*/);
          }
          return c/*allDisposeCallbacks*/;
        }
        var a/*domDataKey*/ = "__ko_domNodeDisposal__"+(new Date).getTime();
        return  {
          addDisposeCallback : function (b/*node*/,a/*callback*/) {
            if (typeof a/*callback*/ != "function"){
              throw new Error("Callback must be a function")
              
            }
            
            c/*getDisposeCallbacksCollection*/(b/*node*/,true).push(a/*callback*/);
          },
          removeDisposeCallback : function (g/*node*/,f/*callback*/) {
            var e/*callbacksCollection*/ = c/*getDisposeCallbacksCollection*/(g/*node*/,false);
            
            if (e/*callbacksCollection*/){
              
              b/*ko*/.utils.arrayRemoveItem(e/*callbacksCollection*/,f/*callback*/);
              
              if (e/*callbacksCollection*/.length == 0){
                
                d/*destroyCallbacksCollection*/(g/*node*/);
              }
              
            }
            
          },
          cleanNode : function (i/*node*/) {
            if ((i/*node*/.nodeType != 1) && (i/*node*/.nodeType != 9)){
              return ;
            }
            
            e/*cleanSingleNode*/(i/*node*/);
            
            var h/*descendants*/ = [];
            
            b/*ko*/.utils.arrayPushAll(h/*descendants*/,i/*node*/.getElementsByTagName("*"));
            
            for (var f/*i*/ = 0,g/*j*/ = h/*descendants*/.length;f/*i*/<g/*j*/;f/*i*/ ++ ){
              
              e/*cleanSingleNode*/(h/*descendants*/[f/*i*/]);
            }
            
          },
          removeNode : function (a/*node*/) {
            b/*ko*/.cleanNode(a/*node*/);
            
            if (a/*node*/.parentNode){
              
              a/*node*/.parentNode.removeChild(a/*node*/);
            }
            
          }
        };
      }();
      
      b/*ko*/.cleanNode = b/*ko*/.utils.domNodeDisposal.cleanNode;
      
      b/*ko*/.removeNode = b/*ko*/.utils.domNodeDisposal.removeNode;
      
      b/*ko*/.exportSymbol('ko.cleanNode',b/*ko*/.cleanNode);
      
      b/*ko*/.exportSymbol('ko.removeNode',b/*ko*/.removeNode);
      
      b/*ko*/.exportSymbol('ko.utils.domNodeDisposal',b/*ko*/.utils.domNodeDisposal);
      
      b/*ko*/.exportSymbol('ko.utils.domNodeDisposal.addDisposeCallback',b/*ko*/.utils.domNodeDisposal.addDisposeCallback);
      
      b/*ko*/.exportSymbol('ko.utils.domNodeDisposal.removeDisposeCallback',b/*ko*/.utils.domNodeDisposal.removeDisposeCallback);
      
      !function () {
        function d/*jQueryHtmlParse*/(c/*html*/) {
          var b/*elems*/ = jQuery.clean([c/*html*/]);
          
          if (b/*elems*/ && b/*elems*/[0]){
            
            var a/*elem*/ = b/*elems*/[0];
            
            while (a/*elem*/.parentNode && a/*elem*/.parentNode.nodeType !== 11)a/*elem*/ = a/*elem*/.parentNode;
            
            a/*elem*/.parentNode && a/*elem*/.parentNode.removeChild(a/*elem*/);
          }
          return b/*elems*/;
        }
        function c/*simpleHtmlParse*/(g/*html*/) {
          var f/*tags*/ = b/*ko*/.utils.stringTrim(g/*html*/).toLowerCase(),
              e/*div*/ = document.createElement("div"),
              c/*wrap*/ = f/*tags*/.match(/^<(thead|tbody|tfoot)/) && [1,"<table>","</table>"] || !f/*tags*/.indexOf("<tr") && [2,"<table><tbody>","</tbody></table>"] || (!f/*tags*/.indexOf("<td") || !f/*tags*/.indexOf("<th")) && [3,"<table><tbody><tr>","</tr></tbody></table>"] || [0,"",""],
              d/*markup*/ = "ignored<div>"+c/*wrap*/[1]+g/*html*/+c/*wrap*/[2]+"</div>";
          
          typeof a/*window*/.innerShiv == "function"?e/*div*/.appendChild(a/*window*/.innerShiv(d/*markup*/)) : e/*div*/.innerHTML = d/*markup*/;
          
          while (c/*wrap*/[0] -- )e/*div*/ = e/*div*/.lastChild;
          return b/*ko*/.utils.makeArray(e/*div*/.lastChild.childNodes);
        }
        var e/*leadingCommentRegex*/ = /^(\s*)<!--(.*?)-->/;
        
        b/*ko*/.utils.parseHtmlFragment = function (e/*html*/) {
          return typeof jQuery != 'undefined'?d/*jQueryHtmlParse*/(e/*html*/) : c/*simpleHtmlParse*/(e/*html*/);
        };
        
        b/*ko*/.utils.setHtml = function (e/*node*/,d/*html*/) {
          b/*ko*/.utils.emptyDomNode(e/*node*/);
          
          if ((d/*html*/ !== null) && (d/*html*/ !== undefined)){
            
            typeof d/*html*/ != 'string' && (d/*html*/ = d/*html*/.toString());
            
            if (typeof jQuery != 'undefined')jQuery(e/*node*/).html(d/*html*/);
             else {
              
              var c/*parsedNodes*/ = b/*ko*/.utils.parseHtmlFragment(d/*html*/);
              
              for (var a/*i*/ = 0;a/*i*/<c/*parsedNodes*/.length;a/*i*/ ++ )e/*node*/.appendChild(c/*parsedNodes*/[a/*i*/]);
            }
            
          }
          
        };
      }();
      
      b/*ko*/.exportSymbol('ko.utils.parseHtmlFragment',b/*ko*/.utils.parseHtmlFragment);
      
      b/*ko*/.exportSymbol('ko.utils.setHtml',b/*ko*/.utils.setHtml);
      
      b/*ko*/.memoization = function () {
        function c/*findMemoNodes*/(i/*rootNode*/,h/*appendToArray*/) {
          if (!i/*rootNode*/)return ;
          
          if (i/*rootNode*/.nodeType == 8){
            
            var g/*memoId*/ = b/*ko*/.memoization.parseMemoText(i/*rootNode*/.nodeValue);
            
            g/*memoId*/ != null && h/*appendToArray*/.push( {
              domNode : i/*rootNode*/,
              memoId : g/*memoId*/
            });
          } else if (i/*rootNode*/.nodeType == 1)for (var f/*i*/ = 0,e/*childNodes*/ = i/*rootNode*/.childNodes,d/*j*/ = e/*childNodes*/.length;f/*i*/<d/*j*/;f/*i*/ ++ )
          c/*findMemoNodes*/(e/*childNodes*/[f/*i*/],h/*appendToArray*/);
        }
        function e/*generateRandomId*/() {
          return a/*randomMax8HexChars*/()+a/*randomMax8HexChars*/();
        }
        function a/*randomMax8HexChars*/() {
          return (((1+Math.random())*0x00000000)|0).toString(16).substring(1);
        }
        var d/*memos*/ = {};
        return  {
          memoize : function (g/*callback*/) {
            if (typeof g/*callback*/ != "function"){
              throw new Error("You can only pass a function to ko.memoization.memoize()")
              
            }
            
            var f/*memoId*/ = e/*generateRandomId*/();
            
            d/*memos*/[f/*memoId*/] = g/*callback*/;
            return "<!--[ko_memo:"+f/*memoId*/+"]-->";
          },
          unmemoize : function (c/*memoId*/,b/*callbackParams*/) {
            var a/*callback*/ = d/*memos*/[c/*memoId*/];
            
            if (a/*callback*/ === undefined){
              throw new Error("Couldn't find any memo with ID "+c/*memoId*/+". Perhaps it's already been unmemoized.")
              
            }
            
            try {
              
              a/*callback*/.apply(null,b/*callbackParams*/ || []);
              return true;
            } finally {
              
              delete d/*memos*/[c/*memoId*/];
            }
            
          },
          unmemoizeDomNodeAndDescendants : function (i/*domNode*/,f/*extraCallbackParamsArray*/) {
            var h/*memos*/ = [];
            
            c/*findMemoNodes*/(i/*domNode*/,h/*memos*/);
            
            for (var d/*i*/ = 0,g/*j*/ = h/*memos*/.length;d/*i*/<g/*j*/;d/*i*/ ++ ){
              
              var a/*node*/ = h/*memos*/[d/*i*/].domNode;
              
              var e/*combinedParams*/ = [a/*node*/];
              
              if (f/*extraCallbackParamsArray*/){
                
                b/*ko*/.utils.arrayPushAll(e/*combinedParams*/,f/*extraCallbackParamsArray*/);
              }
              
              b/*ko*/.memoization.unmemoize(h/*memos*/[d/*i*/].memoId,e/*combinedParams*/);
              
              a/*node*/.nodeValue = "";
              
              if (a/*node*/.parentNode){
                
                a/*node*/.parentNode.removeChild(a/*node*/);
              }
              
            }
            
          },
          parseMemoText : function (b/*memoText*/) {
            var a/*match*/ = b/*memoText*/.match(/^\[ko_memo\:(.*?)\]$/);
            return a/*match*/?a/*match*/[1] : null;
          }
        };
      }();
      
      b/*ko*/.exportSymbol('ko.memoization',b/*ko*/.memoization);
      
      b/*ko*/.exportSymbol('ko.memoization.memoize',b/*ko*/.memoization.memoize);
      
      b/*ko*/.exportSymbol('ko.memoization.unmemoize',b/*ko*/.memoization.unmemoize);
      
      b/*ko*/.exportSymbol('ko.memoization.parseMemoText',b/*ko*/.memoization.parseMemoText);
      
      b/*ko*/.exportSymbol('ko.memoization.unmemoizeDomNodeAndDescendants',b/*ko*/.memoization.unmemoizeDomNodeAndDescendants);
      
      b/*ko*/.extenders =  {
        'throttle' : function (a/*target*/,c/*timeout*/) {
          a/*target*/['throttleEvaluation'] = c/*timeout*/;
          
          var d/*writeTimeoutInstance*/ = null;
          return b/*ko*/.dependentObservable( {
            'read' : a/*target*/,
            'write' : function (b/*value*/) {
              clearTimeout(d/*writeTimeoutInstance*/);
              
              d/*writeTimeoutInstance*/ = setTimeout(function () {
                a/*target*/(b/*value*/);
              },c/*timeout*/);
            }
          });
        },
        'notify' : function (c/*target*/,a/*notifyWhen*/) {
          c/*target*/["equalityComparer"] = a/*notifyWhen*/ == "always"?function () {
            return false;
          } : b/*ko*/.observable["fn"]["equalityComparer"];
          return c/*target*/;
        }
      };
      
      b/*ko*/.exportSymbol('ko.extenders',b/*ko*/.extenders);
      
      b/*ko*/.subscription = function (c/*callback*/,a/*disposeCallback*/) {
        this.callback = c/*callback*/;
        
        this.disposeCallback = a/*disposeCallback*/;
        
        b/*ko*/.exportProperty(this,'dispose',this.dispose);
      };
      
      b/*ko*/.subscription.prototype.dispose = function () {
        this.isDisposed = true;
        
        this.disposeCallback();
      };
      
      b/*ko*/.subscribable = function () {
        this._subscriptions = {};
        
        b/*ko*/.utils.extend(this,b/*ko*/.subscribable.fn);
        
        b/*ko*/.exportProperty(this,'subscribe',this.subscribe);
        
        b/*ko*/.exportProperty(this,'extend',this.extend);
        
        b/*ko*/.exportProperty(this,'getSubscriptionsCount',this.getSubscriptionsCount);
      };
      
      var c/*defaultEvent*/ = "change";
      
      b/*ko*/.subscribable.fn =  {
        subscribe : function (g/*callback*/,f/*callbackTarget*/,d/*event*/) {
          d/*event*/ = d/*event*/ || c/*defaultEvent*/;
          
          var e/*boundCallback*/ = f/*callbackTarget*/?g/*callback*/.bind(f/*callbackTarget*/) : g/*callback*/;
          
          var a/*subscription*/ = new b/*ko*/.subscription(e/*boundCallback*/,function () {
                b/*ko*/.utils.arrayRemoveItem(this._subscriptions[d/*event*/],a/*subscription*/);
              }.bind(this));
          
          if (!this._subscriptions[d/*event*/]){
            
            this._subscriptions[d/*event*/] = [];
          }
          
          this._subscriptions[d/*event*/].push(a/*subscription*/);
          return a/*subscription*/;
        },
        "notifySubscribers" : function (a/*valueToNotify*/,d/*event*/) {
          d/*event*/ = d/*event*/ || c/*defaultEvent*/;
          
          if (this._subscriptions[d/*event*/]){
            
            b/*ko*/.utils.arrayForEach(this._subscriptions[d/*event*/].slice(0),
            function (b/*subscription*/) {
              if (b/*subscription*/ && (b/*subscription*/.isDisposed !== true)){
                
                b/*subscription*/.callback(a/*valueToNotify*/);
              }
              
            });
          }
          
        },
        getSubscriptionsCount : function () {
          var b/*total*/ = 0;
          
          for (var a/*eventName*/ in this._subscriptions){
            
            if (this._subscriptions.hasOwnProperty(a/*eventName*/)){
              
              b/*total*/ += this._subscriptions[a/*eventName*/].length;
            }
            
          }
          return b/*total*/;
        },
        extend : i/*applyExtenders*/
      };
      
      b/*ko*/.isSubscribable = function (a/*instance*/) {
        return typeof a/*instance*/.subscribe == "function" && typeof a/*instance*/.notifySubscribers == "function";
      };
      
      b/*ko*/.exportSymbol('ko.subscribable',b/*ko*/.subscribable);
      
      b/*ko*/.exportSymbol('ko.isSubscribable',b/*ko*/.isSubscribable);
      
      b/*ko*/.dependencyDetection = function () {
        var a/*_frames*/ = [];
        return  {
          begin : function (b/*callback*/) {
            a/*_frames*/.push( {
              callback : b/*callback*/,
              distinctDependencies : []
            });
          },
          end : function () {
            a/*_frames*/.pop();
          },
          registerDependency : function (d/*subscribable*/) {
            if (!b/*ko*/.isSubscribable(d/*subscribable*/)){
              throw "Only subscribable things can act as dependencies"
              
            }
            
            if (a/*_frames*/.length>0){
              
              var c/*topFrame*/ = a/*_frames*/[a/*_frames*/.length-1];
              
              if (b/*ko*/.utils.arrayIndexOf(c/*topFrame*/.distinctDependencies,d/*subscribable*/) >= 0){
                return ;
              }
              
              c/*topFrame*/.distinctDependencies.push(d/*subscribable*/);
              
              c/*topFrame*/.callback(d/*subscribable*/);
            }
            
          }
        };
      }();
      
      var d/*primitiveTypes*/ =  {
            'undefined' : true,
            'boolean' : true,
            'number' : true,
            'string' : true
          };
      
      b/*ko*/.observable = function (d/*initialValue*/) {
        function c/*observable*/() {
          if (arguments.length>0){
            
            if ((!c/*observable*/.equalityComparer) || !c/*observable*/.equalityComparer(a/*_latestValue*/,arguments[0])){
              
              c/*observable*/.valueWillMutate();
              
              a/*_latestValue*/ = arguments[0];
              
              c/*observable*/.valueHasMutated();
            }
            return this;
          } else {
            
            b/*ko*/.dependencyDetection.registerDependency(c/*observable*/);
            return a/*_latestValue*/;
          }
          
        }
        var a/*_latestValue*/ = d/*initialValue*/;
        
        b/*ko*/.subscribable.call(c/*observable*/);
        
        c/*observable*/.valueHasMutated = function () {
          c/*observable*/.notifySubscribers(a/*_latestValue*/);
        };
        
        c/*observable*/.valueWillMutate = function () {
          c/*observable*/.notifySubscribers(a/*_latestValue*/,"beforeChange");
        };
        
        b/*ko*/.utils.extend(c/*observable*/,b/*ko*/.observable.fn);
        
        b/*ko*/.exportProperty(c/*observable*/,"valueHasMutated",c/*observable*/.valueHasMutated);
        
        b/*ko*/.exportProperty(c/*observable*/,"valueWillMutate",c/*observable*/.valueWillMutate);
        return c/*observable*/;
      };
      
      b/*ko*/.observable.fn =  {
        __ko_proto__ : b/*ko*/.observable,
        "equalityComparer" : function h/*valuesArePrimitiveAndEqual*/(g/*a*/,f/*b*/) {
          var e/*oldValueIsPrimitive*/ = (g/*a*/ === null) || (typeof (g/*a*/) in d/*primitiveTypes*/);
          return e/*oldValueIsPrimitive*/?(g/*a*/ === f/*b*/) : false;
        }
      };
      
      b/*ko*/.isObservable = function (a/*instance*/) {
        if ((a/*instance*/ === null) || (a/*instance*/ === undefined) || (a/*instance*/.__ko_proto__ === undefined))return false;
        
        if (a/*instance*/.__ko_proto__ === b/*ko*/.observable)return true;
        return b/*ko*/.isObservable(a/*instance*/.__ko_proto__);
      };
      
      b/*ko*/.isWriteableObservable = function (a/*instance*/) {
        if ((typeof a/*instance*/ == "function") && a/*instance*/.__ko_proto__ === b/*ko*/.observable)return true;
        
        if ((typeof a/*instance*/ == "function") && (a/*instance*/.__ko_proto__ === b/*ko*/.dependentObservable) && (a/*instance*/.hasWriteFunction))return true;
        return false;
      };
      
      b/*ko*/.exportSymbol('ko.observable',b/*ko*/.observable);
      
      b/*ko*/.exportSymbol('ko.isObservable',b/*ko*/.isObservable);
      
      b/*ko*/.exportSymbol('ko.isWriteableObservable',b/*ko*/.isWriteableObservable);
      
      b/*ko*/.observableArray = function (c/*initialValues*/) {
        arguments.length == 0 && (c/*initialValues*/ = []);
        
        if ((c/*initialValues*/ !== null) && (c/*initialValues*/ !== undefined) && !('length' in c/*initialValues*/))throw new Error("The argument passed when initializing an observable array must be an array, or null, or undefined.")
        
        var a/*result*/ = new b/*ko*/.observable(c/*initialValues*/);
        
        b/*ko*/.utils.extend(a/*result*/,b/*ko*/.observableArray.fn);
        
        b/*ko*/.exportProperty(a/*result*/,"remove",a/*result*/.remove);
        
        b/*ko*/.exportProperty(a/*result*/,"removeAll",a/*result*/.removeAll);
        
        b/*ko*/.exportProperty(a/*result*/,"destroy",a/*result*/.destroy);
        
        b/*ko*/.exportProperty(a/*result*/,"destroyAll",a/*result*/.destroyAll);
        
        b/*ko*/.exportProperty(a/*result*/,"indexOf",a/*result*/.indexOf);
        
        b/*ko*/.exportProperty(a/*result*/,"replace",a/*result*/.replace);
        return a/*result*/;
      };
      
      b/*ko*/.observableArray.fn =  {
        remove : function (a/*valueOrPredicate*/) {
          var f/*underlyingArray*/ = this();
          
          var e/*removedValues*/ = [];
          
          var d/*predicate*/ = typeof a/*valueOrPredicate*/ == "function"?a/*valueOrPredicate*/ : function (b/*value*/) {
                return b/*value*/ === a/*valueOrPredicate*/;
              };
          
          for (var c/*i*/ = 0;c/*i*/<f/*underlyingArray*/.length;c/*i*/ ++ ){
            
            var b/*value*/ = f/*underlyingArray*/[c/*i*/];
            
            if (d/*predicate*/(b/*value*/)){
              
              if (e/*removedValues*/.length === 0){
                
                this.valueWillMutate();
              }
              
              e/*removedValues*/.push(b/*value*/);
              
              f/*underlyingArray*/.splice(c/*i*/,1);
              
              c/*i*/ -- ;
            }
            
          }
          
          if (e/*removedValues*/.length){
            
            this.valueHasMutated();
          }
          return e/*removedValues*/;
        },
        removeAll : function (a/*arrayOfValues*/) {
          if (a/*arrayOfValues*/ === undefined){
            
            var d/*underlyingArray*/ = this();
            
            var c/*allValues*/ = d/*underlyingArray*/.slice(0);
            
            this.valueWillMutate();
            
            d/*underlyingArray*/.splice(0,d/*underlyingArray*/.length);
            
            this.valueHasMutated();
            return c/*allValues*/;
          }
          
          if (!a/*arrayOfValues*/){
            return [];
          }
          return this.remove(function (c/*value*/) {
            return b/*ko*/.utils.arrayIndexOf(a/*arrayOfValues*/,c/*value*/) >= 0;
          });
        },
        destroy : function (a/*valueOrPredicate*/) {
          var e/*underlyingArray*/ = this();
          
          var d/*predicate*/ = typeof a/*valueOrPredicate*/ == "function"?a/*valueOrPredicate*/ : function (b/*value*/) {
                return b/*value*/ === a/*valueOrPredicate*/;
              };
          
          this.valueWillMutate();
          
          for (var c/*i*/ = e/*underlyingArray*/.length-1;c/*i*/ >= 0;c/*i*/ -- ){
            
            var b/*value*/ = e/*underlyingArray*/[c/*i*/];
            
            if (d/*predicate*/(b/*value*/)){
              
              e/*underlyingArray*/[c/*i*/]["_destroy"] = true;
            }
            
          }
          
          this.valueHasMutated();
        },
        destroyAll : function (a/*arrayOfValues*/) {
          if (a/*arrayOfValues*/ === undefined){
            return this.destroy(function () {
              return true;
            });
          }
          
          if (!a/*arrayOfValues*/){
            return [];
          }
          return this.destroy(function (c/*value*/) {
            return b/*ko*/.utils.arrayIndexOf(a/*arrayOfValues*/,c/*value*/) >= 0;
          });
        },
        indexOf : function (c/*item*/) {
          var a/*underlyingArray*/ = this();
          return b/*ko*/.utils.arrayIndexOf(a/*underlyingArray*/,c/*item*/);
        },
        replace : function (c/*oldItem*/,b/*newItem*/) {
          var a/*index*/ = this.indexOf(c/*oldItem*/);
          
          if (a/*index*/ >= 0){
            
            this.valueWillMutate();
            
            this()[a/*index*/] = b/*newItem*/;
            
            this.valueHasMutated();
          }
          
        }
      };
      
      b/*ko*/.utils.arrayForEach(["pop","push","reverse","shift","sort","splice","unshift"],
      function (a/*methodName*/) {
        b/*ko*/.observableArray.fn[a/*methodName*/] = function () {
          var c/*underlyingArray*/ = this();
          
          this.valueWillMutate();
          
          var b/*methodCallResult*/ = c/*underlyingArray*/[a/*methodName*/].apply(c/*underlyingArray*/,arguments);
          
          this.valueHasMutated();
          return b/*methodCallResult*/;
        };
      });
      
      b/*ko*/.utils.arrayForEach(["slice"],
      function (a/*methodName*/) {
        b/*ko*/.observableArray.fn[a/*methodName*/] = function () {
          var b/*underlyingArray*/ = this();
          return b/*underlyingArray*/[a/*methodName*/].apply(b/*underlyingArray*/,arguments);
        };
      });
      
      b/*ko*/.exportSymbol('ko.observableArray',b/*ko*/.observableArray);
      
      b/*ko*/.dependentObservable = function (p/*evaluatorFunctionOrOptions*/,j/*evaluatorFunctionTarget*/,m/*options*/) {
        function a/*dependentObservable*/() {
          if (arguments.length>0)if (typeof m/*options*/.write === "function"){
            
            var c/*valueForThis*/ = m/*options*/.owner || j/*evaluatorFunctionTarget*/;
            
            m/*options*/.write.apply(c/*valueForThis*/,arguments);
          } else throw "Cannot write a value to a dependentObservable unless you specify a 'write' option. If you wish to read the current value, don't pass any parameters."
           else {
            
            !n/*_hasBeenEvaluated*/ && h/*evaluateImmediate*/();
            
            b/*ko*/.dependencyDetection.registerDependency(a/*dependentObservable*/);
            return i/*_latestValue*/;
          }
          
        }
        function h/*evaluateImmediate*/() {
          if ((n/*_hasBeenEvaluated*/) && typeof m/*options*/.disposeWhen == "function")if (m/*options*/.disposeWhen()){
            
            a/*dependentObservable*/.dispose();
            return ;
          }
          
          try {
            
            l/*disposeAllSubscriptionsToDependencies*/();
            
            b/*ko*/.dependencyDetection.begin(function (a/*subscribable*/) {
              f/*_subscriptionsToDependencies*/.push(a/*subscribable*/.subscribe(k/*evaluatePossiblyAsync*/));
            });
            
            var p/*valueForThis*/ = m/*options*/.owner || j/*evaluatorFunctionTarget*/;
            
            var o/*newValue*/ = m/*options*/.read.call(p/*valueForThis*/);
            
            a/*dependentObservable*/.notifySubscribers(i/*_latestValue*/,"beforeChange");
            
            i/*_latestValue*/ = o/*newValue*/;
          } finally {
            
            b/*ko*/.dependencyDetection.end();
          }
          
          a/*dependentObservable*/.notifySubscribers(i/*_latestValue*/);
          
          n/*_hasBeenEvaluated*/ = true;
        }
        function k/*evaluatePossiblyAsync*/() {
          var i/*throttleEvaluationTimeout*/ = a/*dependentObservable*/.throttleEvaluation;
          
          if (i/*throttleEvaluationTimeout*/ && i/*throttleEvaluationTimeout*/ >= 0){
            
            clearTimeout(g/*evaluationTimeoutInstance*/);
            
            g/*evaluationTimeoutInstance*/ = setTimeout(h/*evaluateImmediate*/,i/*throttleEvaluationTimeout*/);
          } else h/*evaluateImmediate*/();
        }
        function l/*disposeAllSubscriptionsToDependencies*/() {
          b/*ko*/.utils.arrayForEach(f/*_subscriptionsToDependencies*/,
          function (a/*subscription*/) {
            a/*subscription*/.dispose();
          });
          
          f/*_subscriptionsToDependencies*/ = [];
        }
        var i/*_latestValue*/,
            n/*_hasBeenEvaluated*/ = false,
            m/*options*/ = e/*prepareOptions*/(p/*evaluatorFunctionOrOptions*/,j/*evaluatorFunctionTarget*/,m/*options*/),
            d/*disposeWhenNodeIsRemoved*/ = (typeof m/*options*/.disposeWhenNodeIsRemoved == "object")?m/*options*/.disposeWhenNodeIsRemoved : null,
            o/*disposeWhenNodeIsRemovedCallback*/ = null;
        
        if (d/*disposeWhenNodeIsRemoved*/){
          
          o/*disposeWhenNodeIsRemovedCallback*/ = function () {
            a/*dependentObservable*/.dispose();
          };
          
          b/*ko*/.utils.domNodeDisposal.addDisposeCallback(d/*disposeWhenNodeIsRemoved*/,o/*disposeWhenNodeIsRemovedCallback*/);
          
          var c/*existingDisposeWhenFunction*/ = m/*options*/.disposeWhen;
          
          m/*options*/.disposeWhen = function () {
            return (!b/*ko*/.utils.domNodeIsAttachedToDocument(d/*disposeWhenNodeIsRemoved*/)) || ((typeof c/*existingDisposeWhenFunction*/ == "function") && c/*existingDisposeWhenFunction*/());
          };
        }
        
        var f/*_subscriptionsToDependencies*/ = [];
        
        var g/*evaluationTimeoutInstance*/ = null;
        
        a/*dependentObservable*/.getDependenciesCount = function () {
          return f/*_subscriptionsToDependencies*/.length;
        };
        
        a/*dependentObservable*/.hasWriteFunction = typeof m/*options*/.write === "function";
        
        a/*dependentObservable*/.dispose = function () {
          d/*disposeWhenNodeIsRemoved*/ && b/*ko*/.utils.domNodeDisposal.removeDisposeCallback(d/*disposeWhenNodeIsRemoved*/,o/*disposeWhenNodeIsRemovedCallback*/);
          
          l/*disposeAllSubscriptionsToDependencies*/();
        };
        
        b/*ko*/.subscribable.call(a/*dependentObservable*/);
        
        b/*ko*/.utils.extend(a/*dependentObservable*/,b/*ko*/.dependentObservable.fn);
        
        m/*options*/.deferEvaluation !== true && h/*evaluateImmediate*/();
        
        b/*ko*/.exportProperty(a/*dependentObservable*/,'dispose',a/*dependentObservable*/.dispose);
        
        b/*ko*/.exportProperty(a/*dependentObservable*/,'getDependenciesCount',a/*dependentObservable*/.getDependenciesCount);
        return a/*dependentObservable*/;
      };
      
      b/*ko*/.dependentObservable.fn =  {
        __ko_proto__ : b/*ko*/.dependentObservable
      };
      
      b/*ko*/.dependentObservable.__ko_proto__ = b/*ko*/.observable;
      
      b/*ko*/.exportSymbol('ko.dependentObservable',b/*ko*/.dependentObservable);
      
      b/*ko*/.exportSymbol('ko.computed',b/*ko*/.dependentObservable);
      
      !function () {
        function e/*objectLookup*/() {
          var c/*keys*/ = [],
              a/*values*/ = [];
          
          this.save = function (f/*key*/,e/*value*/) {
            var d/*existingIndex*/ = b/*ko*/.utils.arrayIndexOf(c/*keys*/,f/*key*/);
            
            if (d/*existingIndex*/ >= 0)a/*values*/[d/*existingIndex*/] = e/*value*/;
             else {
              
              c/*keys*/.push(f/*key*/);
              
              a/*values*/.push(e/*value*/);
            }
            
          };
          
          this.get = function (e/*key*/) {
            var d/*existingIndex*/ = b/*ko*/.utils.arrayIndexOf(c/*keys*/,e/*key*/);
            return (d/*existingIndex*/ >= 0)?a/*values*/[d/*existingIndex*/] : undefined;
          };
        }
        function d/*visitPropertiesOrArrayEntries*/(d/*rootObject*/,c/*visitorCallback*/) {
          if (d/*rootObject*/ instanceof Array)for (var b/*i*/ = 0;b/*i*/<d/*rootObject*/.length;b/*i*/ ++ )
          c/*visitorCallback*/(b/*i*/);
           else for (var a/*propertyName*/ in d/*rootObject*/)
          c/*visitorCallback*/(a/*propertyName*/);
        }
        function c/*mapJsObjectGraph*/(f/*rootObject*/,g/*mapInputCallback*/,b/*visitedObjects*/) {
          b/*visitedObjects*/ = b/*visitedObjects*/ || new e/*objectLookup*/();
          
          f/*rootObject*/ = g/*mapInputCallback*/(f/*rootObject*/);
          
          var h/*canHaveProperties*/ = (typeof f/*rootObject*/ == "object") && (f/*rootObject*/ !== null) && (f/*rootObject*/ !== undefined) && (!(f/*rootObject*/ instanceof Date));
          
          if (!h/*canHaveProperties*/)return f/*rootObject*/;
          
          var a/*outputProperties*/ = f/*rootObject*/ instanceof Array?[] : {};
          
          b/*visitedObjects*/.save(f/*rootObject*/,a/*outputProperties*/);
          
          d/*visitPropertiesOrArrayEntries*/(f/*rootObject*/,
          function (j/*indexer*/) {
            var i/*propertyValue*/ = g/*mapInputCallback*/(f/*rootObject*/[j/*indexer*/]);
            
            switch (typeof i/*propertyValue*/) {
              case "boolean" :
              case "number" :
              case "string" :
              case "function" :
                
                a/*outputProperties*/[j/*indexer*/] = i/*propertyValue*/;
                break;
              case "object" :
              case "undefined" :
                
                var h/*previouslyMappedValue*/ = b/*visitedObjects*/.get(i/*propertyValue*/);
                
                a/*outputProperties*/[j/*indexer*/] = (h/*previouslyMappedValue*/ !== undefined)?h/*previouslyMappedValue*/ : c/*mapJsObjectGraph*/(i/*propertyValue*/,g/*mapInputCallback*/,b/*visitedObjects*/);
                break;
                
            }
            
          });
          return a/*outputProperties*/;
        }
        var a/*maxNestedObservableDepth*/ = 10;
        
        b/*ko*/.toJS = function (d/*rootObject*/) {
          if (arguments.length == 0)throw new Error("When calling ko.toJS, pass the object you want to convert.")
          return c/*mapJsObjectGraph*/(d/*rootObject*/,
          function (d/*valueToMap*/) {
            for (var c/*i*/ = 0;b/*ko*/.isObservable(d/*valueToMap*/) && (c/*i*/<a/*maxNestedObservableDepth*/);c/*i*/ ++ )
            d/*valueToMap*/ = d/*valueToMap*/();
            return d/*valueToMap*/;
          });
        };
        
        b/*ko*/.toJSON = function (c/*rootObject*/) {
          var a/*plainJavaScriptObject*/ = b/*ko*/.toJS(c/*rootObject*/);
          return b/*ko*/.utils.stringifyJson(a/*plainJavaScriptObject*/);
        };
      }();
      
      b/*ko*/.exportSymbol('ko.toJS',b/*ko*/.toJS);
      
      b/*ko*/.exportSymbol('ko.toJSON',b/*ko*/.toJSON);
      
      !function () {
        var a/*hasDomDataExpandoProperty*/ = '__ko__hasDomDataOptionValue__';
        
        b/*ko*/.selectExtensions =  {
          readValue : function (c/*element*/) {
            if (c/*element*/.tagName == 'OPTION'){
              
              if (c/*element*/[a/*hasDomDataExpandoProperty*/] === true){
                return b/*ko*/.utils.domData.get(c/*element*/,b/*ko*/.bindingHandlers.options.optionValueDomDataKey);
              }
              return c/*element*/.getAttribute("value");
            } else if (c/*element*/.tagName == 'SELECT'){
              return c/*element*/.selectedIndex >= 0?b/*ko*/.selectExtensions.readValue(c/*element*/.options[c/*element*/.selectedIndex]) : undefined;
            } else return c/*element*/.value;
          },
          writeValue : function (e/*element*/,d/*value*/) {
            if (e/*element*/.tagName == 'OPTION'){
              
              switch (typeof d/*value*/) {
                case "string" :
                  
                  b/*ko*/.utils.domData.set(e/*element*/,b/*ko*/.bindingHandlers.options.optionValueDomDataKey,undefined);
                  
                  if (a/*hasDomDataExpandoProperty*/ in e/*element*/){
                    
                    delete e/*element*/[a/*hasDomDataExpandoProperty*/];
                  }
                  
                  e/*element*/.value = d/*value*/;
                  break;
                default :
                  
                  b/*ko*/.utils.domData.set(e/*element*/,b/*ko*/.bindingHandlers.options.optionValueDomDataKey,d/*value*/);
                  
                  e/*element*/[a/*hasDomDataExpandoProperty*/] = true;
                  
                  e/*element*/.value = typeof d/*value*/ === "number"?d/*value*/ : "";
                  break;
                  
              }
              
            } else if (e/*element*/.tagName == 'SELECT'){
              
              for (var c/*i*/ = e/*element*/.options.length-1;c/*i*/ >= 0;c/*i*/ -- ){
                if (b/*ko*/.selectExtensions.readValue(e/*element*/.options[c/*i*/]) == d/*value*/){
                  
                  e/*element*/.selectedIndex = c/*i*/;
                  break;
                }
                
              }
              
            } else {
              if ((d/*value*/ === null) || (d/*value*/ === undefined)){
                
                d/*value*/ = "";
              }
              
              e/*element*/.value = d/*value*/;
            }
            
          }
        };
      }();
      
      b/*ko*/.exportSymbol('ko.selectExtensions',b/*ko*/.selectExtensions);
      
      b/*ko*/.exportSymbol('ko.selectExtensions.readValue',b/*ko*/.selectExtensions.readValue);
      
      b/*ko*/.exportSymbol('ko.selectExtensions.writeValue',b/*ko*/.selectExtensions.writeValue);
      
      b/*ko*/.jsonExpressionRewriting = function () {
        function g/*ensureQuoted*/(c/*key*/) {
          var a/*trimmedKey*/ = b/*ko*/.utils.stringTrim(c/*key*/);
          
          switch (a/*trimmedKey*/.length && a/*trimmedKey*/.charAt(0)) {
            case "'" :
            case '"' :
              return c/*key*/;
            default :
              return "'"+a/*trimmedKey*/+"'";
              
          }
          
        }
        function f/*isWriteableValue*/(e/*expression*/) {
          if (b/*ko*/.utils.arrayIndexOf(d/*javaScriptReservedWords*/,b/*ko*/.utils.stringTrim(e/*expression*/).toLowerCase()) >= 0)return false;
          return e/*expression*/.match(c/*javaScriptAssignmentTarget*/) !== null;
        }
        function e/*restoreTokens*/(d/*string*/,b/*tokens*/) {
          var c/*prevValue*/ = null;
          
          while (d/*string*/ != c/*prevValue*/){
            
            c/*prevValue*/ = d/*string*/;
            
            d/*string*/ = d/*string*/.replace(a/*restoreCapturedTokensRegex*/,
            function (d/*match*/,c/*tokenIndex*/) {
              return b/*tokens*/[c/*tokenIndex*/];
            });
          }
          return d/*string*/;
        }
        var a/*restoreCapturedTokensRegex*/ = /\@ko_token_(\d+)\@/g,
            c/*javaScriptAssignmentTarget*/ = /^[\_$a-z][\_$a-z0-9]*(\[.*?\])*(\.[\_$a-z][\_$a-z0-9]*(\[.*?\])*)*$/i,
            d/*javaScriptReservedWords*/ = ["true","false"];
        return  {
          bindingRewriteValidators : [],
          parseObjectLiteral : function (j/*objectLiteralString*/) {
            var x/*str*/ = b/*ko*/.utils.stringTrim(j/*objectLiteralString*/);
            
            if (x/*str*/.length<3){
              return [];
            }
            
            if (x/*str*/.charAt(0) === "{"){
              
              x/*str*/ = x/*str*/.substring(1,x/*str*/.length-1);
            }
            
            var l/*tokens*/ = [];
            
            var p/*tokenStart*/ = null,
                u/*tokenEndChar*/;
            
            for (var w/*position*/ = 0;w/*position*/<x/*str*/.length;w/*position*/ ++ ){
              
              var n/*c*/ = x/*str*/.charAt(w/*position*/);
              
              if (p/*tokenStart*/ === null){
                
                switch (n/*c*/) {
                  case '"' :
                  case "'" :
                  case "/" :
                    
                    p/*tokenStart*/ = w/*position*/;
                    
                    u/*tokenEndChar*/ = n/*c*/;
                    break;
                    
                }
                
              } else if ((n/*c*/ == u/*tokenEndChar*/) && (x/*str*/.charAt(w/*position*/-1) !== "\\")){
                
                var t/*token*/ = x/*str*/.substring(p/*tokenStart*/,w/*position*/+1);
                
                l/*tokens*/.push(t/*token*/);
                
                var r/*replacement*/ = "@ko_token_"+(l/*tokens*/.length-1)+"@";
                
                x/*str*/ = x/*str*/.substring(0,p/*tokenStart*/)+r/*replacement*/+x/*str*/.substring(w/*position*/+1);
                
                w/*position*/ -= (t/*token*/.length-r/*replacement*/.length);
                
                p/*tokenStart*/ = null;
              }
              
            }
            
            p/*tokenStart*/ = null;
            
            u/*tokenEndChar*/ = null;
            
            var q/*tokenDepth*/ = 0,
                o/*tokenStartChar*/ = null;
            
            for (var w/*position*/ = 0;w/*position*/<x/*str*/.length;w/*position*/ ++ ){
              
              var n/*c*/ = x/*str*/.charAt(w/*position*/);
              
              if (p/*tokenStart*/ === null){
                
                switch (n/*c*/) {
                  case "{" :
                    
                    p/*tokenStart*/ = w/*position*/;
                    
                    o/*tokenStartChar*/ = n/*c*/;
                    
                    u/*tokenEndChar*/ = "}";
                    break;
                  case "(" :
                    
                    p/*tokenStart*/ = w/*position*/;
                    
                    o/*tokenStartChar*/ = n/*c*/;
                    
                    u/*tokenEndChar*/ = ")";
                    break;
                  case "[" :
                    
                    p/*tokenStart*/ = w/*position*/;
                    
                    o/*tokenStartChar*/ = n/*c*/;
                    
                    u/*tokenEndChar*/ = "]";
                    break;
                    
                }
                
              }
              
              if (n/*c*/ === o/*tokenStartChar*/){
                
                q/*tokenDepth*/ ++ ;
              } else if (n/*c*/ === u/*tokenEndChar*/){
                
                q/*tokenDepth*/ -- ;
                if (q/*tokenDepth*/ === 0){
                  
                  var t/*token*/ = x/*str*/.substring(p/*tokenStart*/,w/*position*/+1);
                  
                  l/*tokens*/.push(t/*token*/);
                  
                  var r/*replacement*/ = "@ko_token_"+(l/*tokens*/.length-1)+"@";
                  
                  x/*str*/ = x/*str*/.substring(0,p/*tokenStart*/)+r/*replacement*/+x/*str*/.substring(w/*position*/+1);
                  
                  w/*position*/ -= (t/*token*/.length-r/*replacement*/.length);
                  
                  p/*tokenStart*/ = null;
                }
                
              }
              
            }
            
            var v/*result*/ = [];
            
            var k/*keyValuePairs*/ = x/*str*/.split(",");
            
            for (var i/*i*/ = 0,h/*j*/ = k/*keyValuePairs*/.length;i/*i*/<h/*j*/;i/*i*/ ++ ){
              
              var m/*pair*/ = k/*keyValuePairs*/[i/*i*/];
              
              var g/*colonPos*/ = m/*pair*/.indexOf(":");
              
              if ((g/*colonPos*/>0) && (g/*colonPos*/<m/*pair*/.length-1)){
                
                var s/*key*/ = m/*pair*/.substring(0,g/*colonPos*/);
                
                var f/*value*/ = m/*pair*/.substring(g/*colonPos*/+1);
                
                v/*result*/.push( {
                  'key' : e/*restoreTokens*/(s/*key*/,l/*tokens*/),
                  'value' : e/*restoreTokens*/(f/*value*/,l/*tokens*/)
                });
              } else {
                
                v/*result*/.push( {
                  'unknown' : e/*restoreTokens*/(m/*pair*/,l/*tokens*/)
                });
              }
              
            }
            return v/*result*/;
          },
          insertPropertyAccessorsIntoJson : function (q/*objectLiteralStringOrKeyValueArray*/) {
            var n/*keyValueArray*/ = typeof q/*objectLiteralStringOrKeyValueArray*/ === "string"?b/*ko*/.jsonExpressionRewriting.parseObjectLiteral(q/*objectLiteralStringOrKeyValueArray*/) : q/*objectLiteralStringOrKeyValueArray*/;
            
            var l/*resultStrings*/ = [],
                k/*propertyAccessorResultStrings*/ = [];
            
            var j/*keyValueEntry*/;
            
            for (var p/*i*/ = 0;j/*keyValueEntry*/ = n/*keyValueArray*/[p/*i*/];p/*i*/ ++ ){
              
              if (l/*resultStrings*/.length>0){
                
                l/*resultStrings*/.push(",");
              }
              
              if (j/*keyValueEntry*/['key']){
                
                var i/*quotedKey*/ = g/*ensureQuoted*/(j/*keyValueEntry*/['key']),
                    o/*val*/ = j/*keyValueEntry*/['value'];
                
                l/*resultStrings*/.push(i/*quotedKey*/);
                
                l/*resultStrings*/.push(":");
                
                l/*resultStrings*/.push(o/*val*/);
                
                if (f/*isWriteableValue*/(b/*ko*/.utils.stringTrim(o/*val*/))){
                  
                  if (k/*propertyAccessorResultStrings*/.length>0){
                    
                    k/*propertyAccessorResultStrings*/.push(", ");
                  }
                  
                  k/*propertyAccessorResultStrings*/.push(i/*quotedKey*/+" : function(__ko_value) { "+o/*val*/+" = __ko_value; }");
                }
                
              } else if (j/*keyValueEntry*/['unknown']){
                
                l/*resultStrings*/.push(j/*keyValueEntry*/['unknown']);
              }
              
            }
            
            var m/*combinedResult*/ = l/*resultStrings*/.join("");
            
            if (k/*propertyAccessorResultStrings*/.length>0){
              
              var h/*allPropertyAccessors*/ = k/*propertyAccessorResultStrings*/.join("");
              
              m/*combinedResult*/ = m/*combinedResult*/+", '_ko_property_writers' : { "+h/*allPropertyAccessors*/+" } ";
            }
            return m/*combinedResult*/;
          },
          keyValueArrayContainsKey : function (d/*keyValueArray*/,c/*key*/) {
            for (var a/*i*/ = 0;a/*i*/<d/*keyValueArray*/.length;a/*i*/ ++ ){
              
              if (b/*ko*/.utils.stringTrim(d/*keyValueArray*/[a/*i*/]['key']) == c/*key*/){
                return true;
              }
              
            }
            return false;
          }
        };
      }();
      
      b/*ko*/.exportSymbol('ko.jsonExpressionRewriting',b/*ko*/.jsonExpressionRewriting);
      
      b/*ko*/.exportSymbol('ko.jsonExpressionRewriting.bindingRewriteValidators',b/*ko*/.jsonExpressionRewriting.bindingRewriteValidators);
      
      b/*ko*/.exportSymbol('ko.jsonExpressionRewriting.parseObjectLiteral',b/*ko*/.jsonExpressionRewriting.parseObjectLiteral);
      
      b/*ko*/.exportSymbol('ko.jsonExpressionRewriting.insertPropertyAccessorsIntoJson',b/*ko*/.jsonExpressionRewriting.insertPropertyAccessorsIntoJson);
      
      !function () {
        function j/*getUnbalancedChildTags*/(l/*node*/) {
          var k/*childNode*/ = l/*node*/.firstChild,
              i/*captureRemaining*/ = null;
          
          if (k/*childNode*/){
            
            do if (i/*captureRemaining*/)i/*captureRemaining*/.push(k/*childNode*/);
             else if (e/*isStartComment*/(k/*childNode*/)){
              
              var j/*matchingEndComment*/ = h/*getMatchingEndComment*/(k/*childNode*/,true);
              
              j/*matchingEndComment*/?k/*childNode*/ = j/*matchingEndComment*/ : i/*captureRemaining*/ = [k/*childNode*/];
            } else f/*isEndComment*/(k/*childNode*/) && (i/*captureRemaining*/ = [k/*childNode*/]);
            while (k/*childNode*/ = k/*childNode*/.nextSibling);
          }
          return i/*captureRemaining*/;
        }
        function i/*nodeArrayToText*/(f/*nodeArray*/,d/*cleanNodes*/) {
          var c/*texts*/ = [];
          
          for (var a/*i*/ = 0,e/*j*/ = f/*nodeArray*/.length;a/*i*/<e/*j*/;a/*i*/ ++ ){
            
            d/*cleanNodes*/ && b/*ko*/.utils.domNodeDisposal.cleanNode(f/*nodeArray*/[a/*i*/]);
            
            c/*texts*/.push(b/*ko*/.utils.outerHTML(f/*nodeArray*/[a/*i*/]));
          }
          return ''.concat.apply("",c/*texts*/);
        }
        function h/*getMatchingEndComment*/(j/*startComment*/,i/*allowUnbalanced*/) {
          var h/*allVirtualChildren*/ = g/*getVirtualChildren*/(j/*startComment*/,i/*allowUnbalanced*/);
          
          if (h/*allVirtualChildren*/){
            
            if (h/*allVirtualChildren*/.length>0)return h/*allVirtualChildren*/[h/*allVirtualChildren*/.length-1].nextSibling;
            return j/*startComment*/.nextSibling;
          } else return null;
        }
        function g/*getVirtualChildren*/(k/*startComment*/,j/*allowUnbalanced*/) {
          var i/*currentNode*/ = k/*startComment*/,
              h/*depth*/ = 1,
              g/*children*/ = [];
          
          while (i/*currentNode*/ = i/*currentNode*/.nextSibling){
            
            if (f/*isEndComment*/(i/*currentNode*/)){
              
              h/*depth*/ -- ;
              
              if (h/*depth*/ === 0)return g/*children*/;
            }
            
            g/*children*/.push(i/*currentNode*/);
            
            e/*isStartComment*/(i/*currentNode*/) && h/*depth*/ ++ ;
          }
          
          if (!j/*allowUnbalanced*/)throw new Error("Cannot find closing comment tag to match: "+k/*startComment*/.nodeValue)
          return null;
        }
        function f/*isEndComment*/(e/*node*/) {
          return (e/*node*/.nodeType == 8) && (c/*commentNodesHaveTextProperty*/?e/*node*/.text : e/*node*/.nodeValue).match(d/*endCommentRegex*/);
        }
        function e/*isStartComment*/(d/*node*/) {
          return (d/*node*/.nodeType == 8) && (c/*commentNodesHaveTextProperty*/?d/*node*/.text : d/*node*/.nodeValue).match(a/*startCommentRegex*/);
        }
        var c/*commentNodesHaveTextProperty*/ = document.createComment("test").text === "<!--test-->",
            a/*startCommentRegex*/ = c/*commentNodesHaveTextProperty*/?/^<!--\s*ko\s+(.*\:.*)\s*-->$/ : /^\s*ko\s+(.*\:.*)\s*$/,
            d/*endCommentRegex*/ = c/*commentNodesHaveTextProperty*/?/^<!--\s*\/ko\s*-->$/ : /^\s*\/ko\s*$/,
            k/*htmlTagsWithOptionallyClosingChildren*/ =  {
              'ul' : true,
              'ol' : true
            };
        
        b/*ko*/.virtualElements =  {
          allowedBindings : {},
          childNodes : function (a/*node*/) {
            return e/*isStartComment*/(a/*node*/)?g/*getVirtualChildren*/(a/*node*/) : a/*node*/.childNodes;
          },
          emptyNode : function (f/*node*/) {
            if (!e/*isStartComment*/(f/*node*/)){
              
              b/*ko*/.utils.emptyDomNode(f/*node*/);
            } else {
              
              var d/*virtualChildren*/ = b/*ko*/.virtualElements.childNodes(f/*node*/);
              
              for (var c/*i*/ = 0,a/*j*/ = d/*virtualChildren*/.length;c/*i*/<a/*j*/;c/*i*/ ++ ){
                
                b/*ko*/.removeNode(d/*virtualChildren*/[c/*i*/]);
              }
              
            }
            
          },
          setDomNodeChildren : function (g/*node*/,f/*childNodes*/) {
            if (!e/*isStartComment*/(g/*node*/)){
              
              b/*ko*/.utils.setDomNodeChildren(g/*node*/,f/*childNodes*/);
            } else {
              
              b/*ko*/.virtualElements.emptyNode(g/*node*/);
              
              var d/*endCommentNode*/ = g/*node*/.nextSibling;
              
              for (var a/*i*/ = 0,c/*j*/ = f/*childNodes*/.length;a/*i*/<c/*j*/;a/*i*/ ++ ){
                
                d/*endCommentNode*/.parentNode.insertBefore(f/*childNodes*/[a/*i*/],d/*endCommentNode*/);
              }
              
            }
            
          },
          prepend : function (b/*containerNode*/,a/*nodeToPrepend*/) {
            if (!e/*isStartComment*/(b/*containerNode*/)){
              
              if (b/*containerNode*/.firstChild){
                
                b/*containerNode*/.insertBefore(a/*nodeToPrepend*/,b/*containerNode*/.firstChild);
              } else b/*containerNode*/.appendChild(a/*nodeToPrepend*/);
            } else {
              
              b/*containerNode*/.parentNode.insertBefore(a/*nodeToPrepend*/,b/*containerNode*/.nextSibling);
            }
            
          },
          insertAfter : function (c/*containerNode*/,b/*nodeToInsert*/,a/*insertAfterNode*/) {
            if (!e/*isStartComment*/(c/*containerNode*/)){
              
              if (a/*insertAfterNode*/.nextSibling){
                
                c/*containerNode*/.insertBefore(b/*nodeToInsert*/,a/*insertAfterNode*/.nextSibling);
              } else c/*containerNode*/.appendChild(b/*nodeToInsert*/);
            } else {
              
              c/*containerNode*/.parentNode.insertBefore(b/*nodeToInsert*/,a/*insertAfterNode*/.nextSibling);
            }
            
          },
          nextSibling : function (a/*node*/) {
            if (!e/*isStartComment*/(a/*node*/)){
              
              if (a/*node*/.nextSibling && f/*isEndComment*/(a/*node*/.nextSibling)){
                return undefined;
              }
              return a/*node*/.nextSibling;
            } else {
              return h/*getMatchingEndComment*/(a/*node*/).nextSibling;
            }
            
          },
          virtualNodeBindingValue : function (b/*node*/) {
            var a/*regexMatch*/ = e/*isStartComment*/(b/*node*/);
            return a/*regexMatch*/?a/*regexMatch*/[1] : null;
          },
          extractAnonymousTemplateIfVirtualElement : function (l/*node*/) {
            if (b/*ko*/.virtualElements.virtualNodeBindingValue(l/*node*/)){
              
              var k/*virtualChildren*/ = b/*ko*/.virtualElements.childNodes(l/*node*/);
              
              var j/*anonymousTemplateText*/ = i/*nodeArrayToText*/(k/*virtualChildren*/,true);
              
              b/*ko*/.virtualElements.emptyNode(l/*node*/);
              
              new b/*ko*/.templateSources.anonymousTemplate(l/*node*/).text(j/*anonymousTemplateText*/);
            }
            
          },
          normaliseVirtualElementDomStructure : function (p/*elementVerified*/) {
            if (!k/*htmlTagsWithOptionallyClosingChildren*/[p/*elementVerified*/.tagName.toLowerCase()]){
              return ;
            }
            
            var n/*childNode*/ = p/*elementVerified*/.firstChild;
            
            if (n/*childNode*/){
              
              do {
                
                if (n/*childNode*/.nodeType === 1){
                  
                  var m/*unbalancedTags*/ = j/*getUnbalancedChildTags*/(n/*childNode*/);
                  
                  if (m/*unbalancedTags*/){
                    
                    var l/*nodeToInsertBefore*/ = n/*childNode*/.nextSibling;
                    
                    for (var o/*i*/ = 0;o/*i*/<m/*unbalancedTags*/.length;o/*i*/ ++ ){
                      
                      if (l/*nodeToInsertBefore*/){
                        
                        p/*elementVerified*/.insertBefore(m/*unbalancedTags*/[o/*i*/],l/*nodeToInsertBefore*/);
                      } else p/*elementVerified*/.appendChild(m/*unbalancedTags*/[o/*i*/]);
                    }
                    
                  }
                  
                }
                
              }while (n/*childNode*/ = n/*childNode*/.nextSibling);
            }
            
          }
        };
      }();
      
      !function () {
        var c/*defaultBindingAttributeName*/ = "data-bind";
        
        b/*ko*/.bindingProvider = function (){};
        
        b/*ko*/.utils.extend(b/*ko*/.bindingProvider.prototype, {
          'nodeHasBindings' : function (d/*node*/) {
            switch (d/*node*/.nodeType) {
              case 1 :
                return d/*node*/.getAttribute(c/*defaultBindingAttributeName*/) != null;
              case 8 :
                return b/*ko*/.virtualElements.virtualNodeBindingValue(d/*node*/) != null;
              default :
                return false;
                
            }
            
          },
          'getBindings' : function (c/*node*/,b/*bindingContext*/) {
            var a/*bindingsString*/ = this['getBindingsString'](c/*node*/,b/*bindingContext*/);
            return a/*bindingsString*/?this['parseBindingsString'](a/*bindingsString*/,b/*bindingContext*/) : null;
          },
          'getBindingsString' : function (d/*node*/,a/*bindingContext*/) {
            switch (d/*node*/.nodeType) {
              case 1 :
                return d/*node*/.getAttribute(c/*defaultBindingAttributeName*/);
              case 8 :
                return b/*ko*/.virtualElements.virtualNodeBindingValue(d/*node*/);
              default :
                return null;
                
            }
            
          },
          'parseBindingsString' : function (f/*bindingsString*/,e/*bindingContext*/) {
            try {
              
              var d/*viewModel*/ = e/*bindingContext*/['$data'];
              
              var c/*rewrittenBindings*/ = " { "+b/*ko*/.jsonExpressionRewriting.insertPropertyAccessorsIntoJson(f/*bindingsString*/)+" } ";
              return b/*ko*/.utils.evalWithinScope(c/*rewrittenBindings*/,d/*viewModel*/ === null?a/*window*/ : d/*viewModel*/,e/*bindingContext*/);
            } catch(ex){
              throw new Error("Unable to parse bindings.\nMessage: "+ex+";\nBindings value: "+f/*bindingsString*/)
              
            }
            
          }
        });
        
        b/*ko*/.bindingProvider.instance = new b/*ko*/.bindingProvider();
      }();
      
      b/*ko*/.exportSymbol('ko.bindingProvider',b/*ko*/.bindingProvider);
      
      !function () {
        function e/*applyBindingsToNodeInternal*/(c/*node*/,i/*bindings*/,g/*viewModelOrBindingContext*/,j/*isRootNodeForBindingContext*/) {
          function d/*parsedBindingsAccessor*/() {
            return a/*parsedBindings*/;
          }
          function e/*makeValueAccessor*/(b/*bindingKey*/) {
            return function () {
              return a/*parsedBindings*/[b/*bindingKey*/];
            };
          }
          var k/*initPhase*/ = 0;
          
          b/*ko*/.virtualElements.extractAnonymousTemplateIfVirtualElement(c/*node*/);
          
          var a/*parsedBindings*/;
          
          var h/*bindingHandlerThatControlsDescendantBindings*/;
          
          new b/*ko*/.dependentObservable(function () {
            var s/*bindingContextInstance*/ = g/*viewModelOrBindingContext*/ && (g/*viewModelOrBindingContext*/ instanceof b/*ko*/.bindingContext)?g/*viewModelOrBindingContext*/ : new b/*ko*/.bindingContext(b/*ko*/.utils.unwrapObservable(g/*viewModelOrBindingContext*/)),
                r/*viewModel*/ = s/*bindingContextInstance*/.$data;
            
            j/*isRootNodeForBindingContext*/ && b/*ko*/.storedBindingContextForNode(c/*node*/,s/*bindingContextInstance*/);
            
            var o/*evaluatedBindings*/ = (typeof i/*bindings*/ == "function")?i/*bindings*/() : i/*bindings*/;
            
            a/*parsedBindings*/ = o/*evaluatedBindings*/ || b/*ko*/.bindingProvider.instance.getBindings(c/*node*/,s/*bindingContextInstance*/);
            
            if (a/*parsedBindings*/){
              
              if (k/*initPhase*/ === 0){
                
                k/*initPhase*/ = 1;
                
                for (var m/*bindingKey*/ in a/*parsedBindings*/){
                  
                  var q/*binding*/ = b/*ko*/.bindingHandlers[m/*bindingKey*/];
                  
                  q/*binding*/ && c/*node*/.nodeType === 8 && f/*validateThatBindingIsAllowedForVirtualElements*/(m/*bindingKey*/);
                  
                  if (q/*binding*/ && typeof q/*binding*/.init == "function"){
                    
                    var p/*handlerInitFn*/ = q/*binding*/.init;
                    
                    var l/*initResult*/ = p/*handlerInitFn*/(c/*node*/,e/*makeValueAccessor*/(m/*bindingKey*/),d/*parsedBindingsAccessor*/,r/*viewModel*/,s/*bindingContextInstance*/);
                    
                    if (l/*initResult*/ && l/*initResult*/.controlsDescendantBindings){
                      
                      if (h/*bindingHandlerThatControlsDescendantBindings*/ !== undefined)throw new Error("Multiple bindings ("+h/*bindingHandlerThatControlsDescendantBindings*/+" and "+m/*bindingKey*/+") are trying to control descendant bindings of the same element. You cannot use these bindings together on the same element.")
                      
                      h/*bindingHandlerThatControlsDescendantBindings*/ = m/*bindingKey*/;
                    }
                    
                  }
                  
                }
                
                k/*initPhase*/ = 2;
              }
              
              if (k/*initPhase*/ === 2)for (var m/*bindingKey*/ in a/*parsedBindings*/){
                
                var q/*binding*/ = b/*ko*/.bindingHandlers[m/*bindingKey*/];
                
                if (q/*binding*/ && typeof q/*binding*/.update == "function"){
                  
                  var n/*handlerUpdateFn*/ = q/*binding*/.update;
                  
                  n/*handlerUpdateFn*/(c/*node*/,e/*makeValueAccessor*/(m/*bindingKey*/),d/*parsedBindingsAccessor*/,r/*viewModel*/,s/*bindingContextInstance*/);
                }
                
              }
              
            }
            
          },null, {
            'disposeWhenNodeIsRemoved' : c/*node*/
          });
          return  {
            shouldBindDescendants : h/*bindingHandlerThatControlsDescendantBindings*/ === undefined
          };
        }
        function c/*applyBindingsToNodeAndDescendantsInternal*/(k/*viewModel*/,j/*nodeVerified*/,h/*isRootNodeForBindingContext*/) {
          var g/*shouldBindDescendants*/ = true,
              f/*isElement*/ = (j/*nodeVerified*/.nodeType == 1);
          
          f/*isElement*/ && b/*ko*/.virtualElements.normaliseVirtualElementDomStructure(j/*nodeVerified*/);
          
          var i/*shouldApplyBindings*/ = (f/*isElement*/ && h/*isRootNodeForBindingContext*/) || b/*ko*/.bindingProvider.instance.nodeHasBindings(j/*nodeVerified*/);
          
          i/*shouldApplyBindings*/ && (g/*shouldBindDescendants*/ = e/*applyBindingsToNodeInternal*/(j/*nodeVerified*/,null,k/*viewModel*/,h/*isRootNodeForBindingContext*/).shouldBindDescendants);
          
          f/*isElement*/ && g/*shouldBindDescendants*/ && d/*applyBindingsToDescendantsInternal*/(k/*viewModel*/,j/*nodeVerified*/);
        }
        function d/*applyBindingsToDescendantsInternal*/(g/*viewModel*/,f/*elementVerified*/) {
          var e/*currentChild*/,
              d/*nextInQueue*/ = f/*elementVerified*/.childNodes[0];
          
          while (e/*currentChild*/ = d/*nextInQueue*/){
            
            d/*nextInQueue*/ = b/*ko*/.virtualElements.nextSibling(e/*currentChild*/);
            
            c/*applyBindingsToNodeAndDescendantsInternal*/(g/*viewModel*/,e/*currentChild*/,false);
          }
          
        }
        function f/*validateThatBindingIsAllowedForVirtualElements*/(c/*bindingName*/) {
          var a/*validator*/ = b/*ko*/.virtualElements.allowedBindings[c/*bindingName*/];
          
          if (!a/*validator*/)throw new Error("The binding '"+c/*bindingName*/+"' cannot be used with virtual elements")
          
        }
        b/*ko*/.bindingHandlers = {};
        
        b/*ko*/.bindingContext = function (b/*dataItem*/,a/*parentBindingContext*/) {
          this.$data = b/*dataItem*/;
          
          if (a/*parentBindingContext*/){
            
            this.$parent = a/*parentBindingContext*/.$data;
            
            this.$parents = (a/*parentBindingContext*/.$parents || []).slice(0);
            
            this.$parents.unshift(this.$parent);
            
            this.$root = a/*parentBindingContext*/.$root;
          } else {
            
            this.$parents = [];
            
            this.$root = b/*dataItem*/;
          }
          
        };
        
        b/*ko*/.bindingContext.prototype.createChildContext = function (a/*dataItem*/) {
          return new b/*ko*/.bindingContext(a/*dataItem*/,this);
        };
        
        var g/*storedBindingContextDomDataKey*/ = "__ko_bindingContext__";
        
        b/*ko*/.storedBindingContextForNode = function (i/*node*/,h/*bindingContext*/) {
          if (arguments.length == 2)b/*ko*/.utils.domData.set(i/*node*/,g/*storedBindingContextDomDataKey*/,h/*bindingContext*/);
           else return b/*ko*/.utils.domData.get(i/*node*/,g/*storedBindingContextDomDataKey*/);
        };
        
        b/*ko*/.applyBindingsToNode = function (d/*node*/,c/*bindings*/,a/*viewModel*/) {
          d/*node*/.nodeType === 1 && b/*ko*/.virtualElements.normaliseVirtualElementDomStructure(d/*node*/);
          return e/*applyBindingsToNodeInternal*/(d/*node*/,c/*bindings*/,a/*viewModel*/,true);
        };
        
        b/*ko*/.applyBindingsToDescendants = function (b/*viewModel*/,a/*rootNode*/) {
          a/*rootNode*/.nodeType === 1 && d/*applyBindingsToDescendantsInternal*/(b/*viewModel*/,a/*rootNode*/);
        };
        
        b/*ko*/.applyBindings = function (d/*viewModel*/,b/*rootNode*/) {
          if (b/*rootNode*/ && (b/*rootNode*/.nodeType !== 1) && (b/*rootNode*/.nodeType !== 8))throw new Error("ko.applyBindings: first parameter should be your view model; second parameter should be a DOM node")
          
          b/*rootNode*/ = b/*rootNode*/ || a/*window*/.document.body;
          
          c/*applyBindingsToNodeAndDescendantsInternal*/(d/*viewModel*/,b/*rootNode*/,true);
        };
        
        b/*ko*/.contextFor = function (c/*node*/) {
          switch (c/*node*/.nodeType) {
            case 1 :
            case 8 :
              
              var a/*context*/ = b/*ko*/.storedBindingContextForNode(c/*node*/);
              
              if (a/*context*/){
                return a/*context*/;
              }
              
              if (c/*node*/.parentNode){
                return b/*ko*/.contextFor(c/*node*/.parentNode);
              }
              break;
              
          }
          return undefined;
        };
        
        b/*ko*/.dataFor = function (c/*node*/) {
          var a/*context*/ = b/*ko*/.contextFor(c/*node*/);
          return a/*context*/?a/*context*/.$data : undefined;
        };
        
        b/*ko*/.exportSymbol('ko.bindingHandlers',b/*ko*/.bindingHandlers);
        
        b/*ko*/.exportSymbol('ko.applyBindings',b/*ko*/.applyBindings);
        
        b/*ko*/.exportSymbol('ko.applyBindingsToDescendants',b/*ko*/.applyBindingsToDescendants);
        
        b/*ko*/.exportSymbol('ko.applyBindingsToNode',b/*ko*/.applyBindingsToNode);
        
        b/*ko*/.exportSymbol('ko.contextFor',b/*ko*/.contextFor);
        
        b/*ko*/.exportSymbol('ko.dataFor',b/*ko*/.dataFor);
      }();
      
      var g/*eventHandlersWithShortcuts*/ = ['click'];
      
      b/*ko*/.utils.arrayForEach(g/*eventHandlersWithShortcuts*/,
      function (a/*eventName*/) {
        b/*ko*/.bindingHandlers[a/*eventName*/] =  {
          'init' : function (g/*element*/,c/*valueAccessor*/,e/*allBindingsAccessor*/,f/*viewModel*/) {
            var d/*newValueAccessor*/ = function () {
                  var d/*result*/ = {};
                  
                  d/*result*/[a/*eventName*/] = c/*valueAccessor*/();
                  return d/*result*/;
                };
            return b/*ko*/.bindingHandlers['event']['init'].call(this,g/*element*/,d/*newValueAccessor*/,e/*allBindingsAccessor*/,f/*viewModel*/);
          }
        };
      });
      
      b/*ko*/.bindingHandlers.event =  {
        'init' : function (f/*element*/,a/*valueAccessor*/,d/*allBindingsAccessor*/,c/*viewModel*/) {
          var g/*eventsToHandle*/ = a/*valueAccessor*/() || {};
          
          for (var e/*eventNameOutsideClosure*/ in g/*eventsToHandle*/){
            
            (function () {
              var g/*eventName*/ = e/*eventNameOutsideClosure*/;
              
              if (typeof g/*eventName*/ == "string"){
                
                b/*ko*/.utils.registerEventHandler(f/*element*/,g/*eventName*/,
                function (m/*event*/) {
                  var l/*handlerReturnValue*/;
                  
                  var k/*handlerFunction*/ = a/*valueAccessor*/()[g/*eventName*/];
                  
                  if (!k/*handlerFunction*/){
                    return ;
                  }
                  
                  var i/*allBindings*/ = d/*allBindingsAccessor*/();
                  
                  try {
                    
                    var j/*argsForHandler*/ = b/*ko*/.utils.makeArray(arguments);
                    
                    j/*argsForHandler*/.unshift(c/*viewModel*/);
                    
                    l/*handlerReturnValue*/ = k/*handlerFunction*/.apply(c/*viewModel*/,j/*argsForHandler*/);
                  } finally {
                    
                    if (l/*handlerReturnValue*/ !== true){
                      
                      if (m/*event*/.preventDefault){
                        
                        m/*event*/.preventDefault();
                      } else m/*event*/.returnValue = false;
                    }
                    
                  }
                  
                  var h/*bubble*/ = i/*allBindings*/[g/*eventName*/+'Bubble'] !== false;
                  
                  if (!h/*bubble*/){
                    
                    m/*event*/.cancelBubble = true;
                    
                    if (m/*event*/.stopPropagation){
                      
                      m/*event*/.stopPropagation();
                    }
                    
                  }
                  
                });
              }
              
            })();
          }
          
        }
      };
      
      b/*ko*/.bindingHandlers.submit =  {
        'init' : function (a/*element*/,d/*valueAccessor*/,e/*allBindingsAccessor*/,c/*viewModel*/) {
          if (typeof d/*valueAccessor*/() != "function"){
            throw new Error("The value for a submit binding must be a function")
            
          }
          
          b/*ko*/.utils.registerEventHandler(a/*element*/,"submit",
          function (g/*event*/) {
            var f/*handlerReturnValue*/;
            
            var e/*value*/ = d/*valueAccessor*/();
            
            try {
              
              f/*handlerReturnValue*/ = e/*value*/.call(c/*viewModel*/,a/*element*/);
            } finally {
              
              if (f/*handlerReturnValue*/ !== true){
                
                if (g/*event*/.preventDefault){
                  
                  g/*event*/.preventDefault();
                } else g/*event*/.returnValue = false;
              }
              
            }
            
          });
        }
      };
      
      b/*ko*/.bindingHandlers.visible =  {
        'update' : function (e/*element*/,d/*valueAccessor*/) {
          var c/*value*/ = b/*ko*/.utils.unwrapObservable(d/*valueAccessor*/());
          
          var a/*isCurrentlyVisible*/ = !(e/*element*/.style.display == "none");
          
          if (c/*value*/ && !a/*isCurrentlyVisible*/){
            
            e/*element*/.style.display = "";
          } else if ((!c/*value*/) && a/*isCurrentlyVisible*/){
            
            e/*element*/.style.display = "none";
          }
          
        }
      };
      
      b/*ko*/.bindingHandlers.enable =  {
        'update' : function (d/*element*/,c/*valueAccessor*/) {
          var a/*value*/ = b/*ko*/.utils.unwrapObservable(c/*valueAccessor*/());
          
          if (a/*value*/ && d/*element*/.disabled){
            
            d/*element*/.removeAttribute("disabled");
          } else if ((!a/*value*/) && (!d/*element*/.disabled)){
            
            d/*element*/.disabled = true;
          }
          
        }
      };
      
      b/*ko*/.bindingHandlers.disable =  {
        'update' : function (c/*element*/,a/*valueAccessor*/) {
          b/*ko*/.bindingHandlers['enable']['update'](c/*element*/,
          function () {
            return !b/*ko*/.utils.unwrapObservable(a/*valueAccessor*/());
          });
        }
      };
      
      b/*ko*/.bindingHandlers.value =  {
        'init' : function (d/*element*/,a/*valueAccessor*/,c/*allBindingsAccessor*/) {
          var f/*eventsToCatch*/ = ["change"];
          
          var e/*requestedEventsToCatch*/ = c/*allBindingsAccessor*/()["valueUpdate"];
          
          if (e/*requestedEventsToCatch*/){
            
            if (typeof e/*requestedEventsToCatch*/ == "string"){
              
              e/*requestedEventsToCatch*/ = [e/*requestedEventsToCatch*/];
            }
            
            b/*ko*/.utils.arrayPushAll(f/*eventsToCatch*/,e/*requestedEventsToCatch*/);
            
            f/*eventsToCatch*/ = b/*ko*/.utils.arrayGetDistinctValues(f/*eventsToCatch*/);
          }
          
          b/*ko*/.utils.arrayForEach(f/*eventsToCatch*/,
          function (g/*eventName*/) {
            var f/*handleEventAsynchronously*/ = false;
            
            if (b/*ko*/.utils.stringStartsWith(g/*eventName*/,"after")){
              
              f/*handleEventAsynchronously*/ = true;
              
              g/*eventName*/ = g/*eventName*/.substring("after".length);
            }
            
            var e/*runEventHandler*/ = f/*handleEventAsynchronously*/?function (a/*handler*/) {
                  setTimeout(a/*handler*/,0);
                } : function (a/*handler*/) {
                  a/*handler*/();
                };
            
            b/*ko*/.utils.registerEventHandler(d/*element*/,g/*eventName*/,
            function () {
              e/*runEventHandler*/(function () {
                var g/*modelValue*/ = a/*valueAccessor*/();
                
                var f/*elementValue*/ = b/*ko*/.selectExtensions.readValue(d/*element*/);
                
                if (b/*ko*/.isWriteableObservable(g/*modelValue*/)){
                  
                  g/*modelValue*/(f/*elementValue*/);
                } else {
                  
                  var e/*allBindings*/ = c/*allBindingsAccessor*/();
                  if (e/*allBindings*/['_ko_property_writers'] && e/*allBindings*/['_ko_property_writers']['value']){
                    
                    e/*allBindings*/['_ko_property_writers']['value'](f/*elementValue*/);
                  }
                  
                }
                
              });
            });
          });
        },
        'update' : function (c/*element*/,k/*valueAccessor*/) {
          var a/*newValue*/ = b/*ko*/.utils.unwrapObservable(k/*valueAccessor*/());
          
          var j/*elementValue*/ = b/*ko*/.selectExtensions.readValue(c/*element*/);
          
          var i/*valueHasChanged*/ = (a/*newValue*/ != j/*elementValue*/);
          
          if ((a/*newValue*/ === 0) && (j/*elementValue*/ !== 0) && (j/*elementValue*/ !== "0")){
            
            i/*valueHasChanged*/ = true;
          }
          
          if (i/*valueHasChanged*/){
            
            var h/*applyValueAction*/ = function () {
                  b/*ko*/.selectExtensions.writeValue(c/*element*/,a/*newValue*/);
                };
            
            h/*applyValueAction*/();
            
            var g/*alsoApplyAsynchronously*/ = c/*element*/.tagName == "SELECT";
            
            if (g/*alsoApplyAsynchronously*/){
              
              setTimeout(h/*applyValueAction*/,0);
            }
            
          }
          
          if ((c/*element*/.tagName == "SELECT") && (c/*element*/.length>0)){
            
            f/*ensureDropdownSelectionIsConsistentWithModelValue*/(c/*element*/,a/*newValue*/,false);
          }
          
        }
      };
      
      b/*ko*/.bindingHandlers.options =  {
        'update' : function (s/*element*/,q/*valueAccessor*/,j/*allBindingsAccessor*/) {
          if (s/*element*/.tagName != "SELECT"){
            throw new Error("options binding applies only to SELECT elements")
            
          }
          
          var r/*selectWasPreviouslyEmpty*/ = s/*element*/.length == 0;
          
          var e/*previousSelectedValues*/ = b/*ko*/.utils.arrayMap(b/*ko*/.utils.arrayFilter(s/*element*/.childNodes,
              function (a/*node*/) {
                return a/*node*/.tagName && a/*node*/.tagName == "OPTION" && a/*node*/.selected;
              }),
              function (a/*node*/) {
                return b/*ko*/.selectExtensions.readValue(a/*node*/) || a/*node*/.innerText || a/*node*/.textContent;
              });
          
          var p/*previousScrollTop*/ = s/*element*/.scrollTop;
          
          s/*element*/.scrollTop = 0;
          
          var o/*value*/ = b/*ko*/.utils.unwrapObservable(q/*valueAccessor*/());
          
          var l/*selectedValue*/ = s/*element*/.value;
          
          while (s/*element*/.length>0){
            
            b/*ko*/.cleanNode(s/*element*/.options[0]);
            
            s/*element*/.remove(0);
          }
          
          if (o/*value*/){
            
            var i/*allBindings*/ = j/*allBindingsAccessor*/();
            
            if (typeof o/*value*/.length != "number"){
              
              o/*value*/ = [o/*value*/];
            }
            
            if (i/*allBindings*/['optionsCaption']){
              
              var h/*option*/ = document.createElement("OPTION");
              
              b/*ko*/.utils.setHtml(h/*option*/,i/*allBindings*/['optionsCaption']);
              
              b/*ko*/.selectExtensions.writeValue(h/*option*/,undefined);
              
              s/*element*/.appendChild(h/*option*/);
            }
            
            for (var k/*i*/ = 0,n/*j*/ = o/*value*/.length;k/*i*/<n/*j*/;k/*i*/ ++ ){
              
              var h/*option*/ = document.createElement("OPTION");
              
              var m/*optionValue*/ = typeof i/*allBindings*/['optionsValue'] == "string"?o/*value*/[k/*i*/][i/*allBindings*/['optionsValue']] : o/*value*/[k/*i*/];
              
              m/*optionValue*/ = b/*ko*/.utils.unwrapObservable(m/*optionValue*/);
              
              b/*ko*/.selectExtensions.writeValue(h/*option*/,m/*optionValue*/);
              
              var g/*optionsTextValue*/ = i/*allBindings*/['optionsText'];
              
              var d/*optionText*/;
              
              if (typeof g/*optionsTextValue*/ == "function"){
                
                d/*optionText*/ = g/*optionsTextValue*/(o/*value*/[k/*i*/]);
              } else if (typeof g/*optionsTextValue*/ == "string"){
                
                d/*optionText*/ = o/*value*/[k/*i*/][g/*optionsTextValue*/];
              } else d/*optionText*/ = m/*optionValue*/;
              
              if ((d/*optionText*/ === null) || (d/*optionText*/ === undefined)){
                
                d/*optionText*/ = "";
              }
              
              b/*ko*/.utils.setTextContent(h/*option*/,d/*optionText*/);
              
              s/*element*/.appendChild(h/*option*/);
            }
            
            var c/*newOptions*/ = s/*element*/.getElementsByTagName("OPTION");
            
            var a/*countSelectionsRetained*/ = 0;
            
            for (var k/*i*/ = 0,n/*j*/ = c/*newOptions*/.length;k/*i*/<n/*j*/;k/*i*/ ++ ){
              
              if (b/*ko*/.utils.arrayIndexOf(e/*previousSelectedValues*/,b/*ko*/.selectExtensions.readValue(c/*newOptions*/[k/*i*/])) >= 0){
                
                b/*ko*/.utils.setOptionNodeSelectionState(c/*newOptions*/[k/*i*/],true);
                
                a/*countSelectionsRetained*/ ++ ;
              }
              
            }
            
            if (p/*previousScrollTop*/){
              
              s/*element*/.scrollTop = p/*previousScrollTop*/;
            }
            
            if (r/*selectWasPreviouslyEmpty*/ && ('value' in i/*allBindings*/)){
              
              f/*ensureDropdownSelectionIsConsistentWithModelValue*/(s/*element*/,b/*ko*/.utils.unwrapObservable(i/*allBindings*/['value']),true);
            }
            
          }
          
        }
      };
      
      b/*ko*/.bindingHandlers.options.optionValueDomDataKey = '__ko.optionValueDomData__';
      
      b/*ko*/.bindingHandlers.selectedOptions =  {
        getSelectedValuesFromSelectNode : function (g/*selectNode*/) {
          var f/*result*/ = [];
          
          var e/*nodes*/ = g/*selectNode*/.childNodes;
          
          for (var c/*i*/ = 0,d/*j*/ = e/*nodes*/.length;c/*i*/<d/*j*/;c/*i*/ ++ ){
            
            var a/*node*/ = e/*nodes*/[c/*i*/];
            
            if ((a/*node*/.tagName == "OPTION") && a/*node*/.selected){
              
              f/*result*/.push(b/*ko*/.selectExtensions.readValue(a/*node*/));
            }
            
          }
          return f/*result*/;
        },
        'init' : function (d/*element*/,c/*valueAccessor*/,a/*allBindingsAccessor*/) {
          b/*ko*/.utils.registerEventHandler(d/*element*/,"change",
          function () {
            var e/*value*/ = c/*valueAccessor*/();
            
            if (b/*ko*/.isWriteableObservable(e/*value*/)){
              
              e/*value*/(b/*ko*/.bindingHandlers['selectedOptions'].getSelectedValuesFromSelectNode(this));
            } else {
              
              var d/*allBindings*/ = a/*allBindingsAccessor*/();
              if (d/*allBindings*/['_ko_property_writers'] && d/*allBindings*/['_ko_property_writers']['value']){
                
                d/*allBindings*/['_ko_property_writers']['value'](b/*ko*/.bindingHandlers['selectedOptions'].getSelectedValuesFromSelectNode(this));
              }
              
            }
            
          });
        },
        'update' : function (h/*element*/,e/*valueAccessor*/) {
          if (h/*element*/.tagName != "SELECT"){
            throw new Error("values binding applies only to SELECT elements")
            
          }
          
          var d/*newValue*/ = b/*ko*/.utils.unwrapObservable(e/*valueAccessor*/());
          
          if (d/*newValue*/ && typeof d/*newValue*/.length == "number"){
            
            var g/*nodes*/ = h/*element*/.childNodes;
            
            for (var c/*i*/ = 0,f/*j*/ = g/*nodes*/.length;c/*i*/<f/*j*/;c/*i*/ ++ ){
              
              var a/*node*/ = g/*nodes*/[c/*i*/];
              
              if (a/*node*/.tagName == "OPTION"){
                
                b/*ko*/.utils.setOptionNodeSelectionState(a/*node*/,b/*ko*/.utils.arrayIndexOf(d/*newValue*/,b/*ko*/.selectExtensions.readValue(a/*node*/)) >= 0);
              }
              
            }
            
          }
          
        }
      };
      
      b/*ko*/.bindingHandlers.text =  {
        'update' : function (c/*element*/,a/*valueAccessor*/) {
          b/*ko*/.utils.setTextContent(c/*element*/,a/*valueAccessor*/());
        }
      };
      
      b/*ko*/.bindingHandlers.html =  {
        'init' : function () {
          return  {
            'controlsDescendantBindings' : true
          };
        },
        'update' : function (d/*element*/,c/*valueAccessor*/) {
          var a/*value*/ = b/*ko*/.utils.unwrapObservable(c/*valueAccessor*/());
          
          b/*ko*/.utils.setHtml(d/*element*/,a/*value*/);
        }
      };
      
      b/*ko*/.bindingHandlers.css =  {
        'update' : function (f/*element*/,e/*valueAccessor*/) {
          var d/*value*/ = b/*ko*/.utils.unwrapObservable(e/*valueAccessor*/() || {});
          
          for (var c/*className*/ in d/*value*/){
            
            if (typeof c/*className*/ == "string"){
              
              var a/*shouldHaveClass*/ = b/*ko*/.utils.unwrapObservable(d/*value*/[c/*className*/]);
              
              b/*ko*/.utils.toggleDomNodeCssClass(f/*element*/,c/*className*/,a/*shouldHaveClass*/);
            }
            
          }
          
        }
      };
      
      b/*ko*/.bindingHandlers.style =  {
        'update' : function (f/*element*/,e/*valueAccessor*/) {
          var d/*value*/ = b/*ko*/.utils.unwrapObservable(e/*valueAccessor*/() || {});
          
          for (var c/*styleName*/ in d/*value*/){
            
            if (typeof c/*styleName*/ == "string"){
              
              var a/*styleValue*/ = b/*ko*/.utils.unwrapObservable(d/*value*/[c/*styleName*/]);
              
              f/*element*/.style[c/*styleName*/] = a/*styleValue*/ || "";
            }
            
          }
          
        }
      };
      
      b/*ko*/.bindingHandlers.uniqueName =  {
        'init' : function (c/*element*/,a/*valueAccessor*/) {
          if (a/*valueAccessor*/()){
            
            c/*element*/.name = "ko_unique_"+( ++ b/*ko*/.bindingHandlers['uniqueName'].currentIndex);
            
            if (b/*ko*/.utils.isIe6 || b/*ko*/.utils.isIe7){
              
              c/*element*/.mergeAttributes(document.createElement("<input name='"+c/*element*/.name+"'/>"),false);
            }
            
          }
          
        }
      };
      
      b/*ko*/.bindingHandlers.uniqueName.currentIndex = 0;
      
      b/*ko*/.bindingHandlers.checked =  {
        'init' : function (d/*element*/,c/*valueAccessor*/,a/*allBindingsAccessor*/) {
          var e/*updateHandler*/ = function () {
                var h/*valueToWrite*/;
                
                if (d/*element*/.type == "checkbox"){
                  
                  h/*valueToWrite*/ = d/*element*/.checked;
                } else if ((d/*element*/.type == "radio") && (d/*element*/.checked)){
                  
                  h/*valueToWrite*/ = d/*element*/.value;
                } else {
                  return ;
                }
                
                var g/*modelValue*/ = c/*valueAccessor*/();
                
                if ((d/*element*/.type == "checkbox") && (b/*ko*/.utils.unwrapObservable(g/*modelValue*/) instanceof Array)){
                  
                  var f/*existingEntryIndex*/ = b/*ko*/.utils.arrayIndexOf(b/*ko*/.utils.unwrapObservable(g/*modelValue*/),d/*element*/.value);
                  
                  if (d/*element*/.checked && (f/*existingEntryIndex*/<0)){
                    
                    g/*modelValue*/.push(d/*element*/.value);
                  } else if ((!d/*element*/.checked) && (f/*existingEntryIndex*/ >= 0)){
                    
                    g/*modelValue*/.splice(f/*existingEntryIndex*/,1);
                  }
                  
                } else if (b/*ko*/.isWriteableObservable(g/*modelValue*/)){
                  if (g/*modelValue*/() !== h/*valueToWrite*/){
                    
                    g/*modelValue*/(h/*valueToWrite*/);
                  }
                  
                } else {
                  
                  var e/*allBindings*/ = a/*allBindingsAccessor*/();
                  if (e/*allBindings*/['_ko_property_writers'] && e/*allBindings*/['_ko_property_writers']['checked']){
                    
                    e/*allBindings*/['_ko_property_writers']['checked'](h/*valueToWrite*/);
                  }
                  
                }
                
              };
          
          b/*ko*/.utils.registerEventHandler(d/*element*/,"click",e/*updateHandler*/);
          
          if ((d/*element*/.type == "radio") && !d/*element*/.name){
            
            b/*ko*/.bindingHandlers['uniqueName']['init'](d/*element*/,
            function () {
              return true;
            });
          }
          
        },
        'update' : function (d/*element*/,c/*valueAccessor*/) {
          var a/*value*/ = b/*ko*/.utils.unwrapObservable(c/*valueAccessor*/());
          
          if (d/*element*/.type == "checkbox"){
            
            if (a/*value*/ instanceof Array){
              
              d/*element*/.checked = b/*ko*/.utils.arrayIndexOf(a/*value*/,d/*element*/.value) >= 0;
            } else {
              
              d/*element*/.checked = a/*value*/;
            }
            
          } else if (d/*element*/.type == "radio"){
            
            d/*element*/.checked = (d/*element*/.value == a/*value*/);
          }
          
        }
      };
      
      b/*ko*/.bindingHandlers.attr =  {
        'update' : function (g/*element*/,e/*valueAccessor*/,d/*allBindingsAccessor*/) {
          var c/*value*/ = b/*ko*/.utils.unwrapObservable(e/*valueAccessor*/()) || {};
          
          for (var f/*attrName*/ in c/*value*/){
            
            if (typeof f/*attrName*/ == "string"){
              
              var a/*attrValue*/ = b/*ko*/.utils.unwrapObservable(c/*value*/[f/*attrName*/]);
              
              if ((a/*attrValue*/ === false) || (a/*attrValue*/ === null) || (a/*attrValue*/ === undefined)){
                
                g/*element*/.removeAttribute(f/*attrName*/);
              } else g/*element*/.setAttribute(f/*attrName*/,a/*attrValue*/.toString());
            }
            
          }
          
        }
      };
      
      b/*ko*/.bindingHandlers.hasfocus =  {
        'init' : function (e/*element*/,c/*valueAccessor*/,a/*allBindingsAccessor*/) {
          var d/*writeValue*/ = function (f/*valueToWrite*/) {
                var e/*modelValue*/ = c/*valueAccessor*/();
                
                if (f/*valueToWrite*/ == b/*ko*/.utils.unwrapObservable(e/*modelValue*/)){
                  return ;
                }
                
                if (b/*ko*/.isWriteableObservable(e/*modelValue*/)){
                  
                  e/*modelValue*/(f/*valueToWrite*/);
                } else {
                  
                  var d/*allBindings*/ = a/*allBindingsAccessor*/();
                  if (d/*allBindings*/['_ko_property_writers'] && d/*allBindings*/['_ko_property_writers']['hasfocus']){
                    
                    d/*allBindings*/['_ko_property_writers']['hasfocus'](f/*valueToWrite*/);
                  }
                  
                }
                
              };
          
          b/*ko*/.utils.registerEventHandler(e/*element*/,"focus",
          function () {
            d/*writeValue*/(true);
          });
          
          b/*ko*/.utils.registerEventHandler(e/*element*/,"focusin",
          function () {
            d/*writeValue*/(true);
          });
          
          b/*ko*/.utils.registerEventHandler(e/*element*/,"blur",
          function () {
            d/*writeValue*/(false);
          });
          
          b/*ko*/.utils.registerEventHandler(e/*element*/,"focusout",
          function () {
            d/*writeValue*/(false);
          });
        },
        'update' : function (d/*element*/,c/*valueAccessor*/) {
          var a/*value*/ = b/*ko*/.utils.unwrapObservable(c/*valueAccessor*/());
          
          a/*value*/?d/*element*/.focus() : d/*element*/.blur();
          
          b/*ko*/.utils.triggerEvent(d/*element*/,a/*value*/?"focusin" : "focusout");
        }
      };
      
      b/*ko*/.bindingHandlers['with'] =  {
        makeTemplateValueAccessor : function (a/*valueAccessor*/) {
          return function () {
            var c/*value*/ = a/*valueAccessor*/();
            return  {
              'if' : c/*value*/,
              'data' : c/*value*/,
              'templateEngine' : b/*ko*/.nativeTemplateEngine.instance
            };
          };
        },
        'init' : function (f/*element*/,e/*valueAccessor*/,c/*allBindingsAccessor*/,d/*viewModel*/,a/*bindingContext*/) {
          return b/*ko*/.bindingHandlers['template']['init'](f/*element*/,b/*ko*/.bindingHandlers['with'].makeTemplateValueAccessor(e/*valueAccessor*/));
        },
        'update' : function (f/*element*/,e/*valueAccessor*/,c/*allBindingsAccessor*/,d/*viewModel*/,a/*bindingContext*/) {
          return b/*ko*/.bindingHandlers['template']['update'](f/*element*/,b/*ko*/.bindingHandlers['with'].makeTemplateValueAccessor(e/*valueAccessor*/),c/*allBindingsAccessor*/,d/*viewModel*/,a/*bindingContext*/);
        }
      };
      
      b/*ko*/.jsonExpressionRewriting.bindingRewriteValidators['with'] = false;
      
      b/*ko*/.virtualElements.allowedBindings['with'] = true;
      
      b/*ko*/.bindingHandlers['if'] =  {
        makeTemplateValueAccessor : function (a/*valueAccessor*/) {
          return function () {
            return  {
              'if' : a/*valueAccessor*/(),
              'templateEngine' : b/*ko*/.nativeTemplateEngine.instance
            };
          };
        },
        'init' : function (f/*element*/,e/*valueAccessor*/,c/*allBindingsAccessor*/,d/*viewModel*/,a/*bindingContext*/) {
          return b/*ko*/.bindingHandlers['template']['init'](f/*element*/,b/*ko*/.bindingHandlers['if'].makeTemplateValueAccessor(e/*valueAccessor*/));
        },
        'update' : function (f/*element*/,e/*valueAccessor*/,c/*allBindingsAccessor*/,d/*viewModel*/,a/*bindingContext*/) {
          return b/*ko*/.bindingHandlers['template']['update'](f/*element*/,b/*ko*/.bindingHandlers['if'].makeTemplateValueAccessor(e/*valueAccessor*/),c/*allBindingsAccessor*/,d/*viewModel*/,a/*bindingContext*/);
        }
      };
      
      b/*ko*/.jsonExpressionRewriting.bindingRewriteValidators['if'] = false;
      
      b/*ko*/.virtualElements.allowedBindings['if'] = true;
      
      b/*ko*/.bindingHandlers.ifnot =  {
        makeTemplateValueAccessor : function (a/*valueAccessor*/) {
          return function () {
            return  {
              'ifnot' : a/*valueAccessor*/(),
              'templateEngine' : b/*ko*/.nativeTemplateEngine.instance
            };
          };
        },
        'init' : function (f/*element*/,e/*valueAccessor*/,c/*allBindingsAccessor*/,d/*viewModel*/,a/*bindingContext*/) {
          return b/*ko*/.bindingHandlers['template']['init'](f/*element*/,b/*ko*/.bindingHandlers['ifnot'].makeTemplateValueAccessor(e/*valueAccessor*/));
        },
        'update' : function (f/*element*/,e/*valueAccessor*/,c/*allBindingsAccessor*/,d/*viewModel*/,a/*bindingContext*/) {
          return b/*ko*/.bindingHandlers['template']['update'](f/*element*/,b/*ko*/.bindingHandlers['ifnot'].makeTemplateValueAccessor(e/*valueAccessor*/),c/*allBindingsAccessor*/,d/*viewModel*/,a/*bindingContext*/);
        }
      };
      
      b/*ko*/.jsonExpressionRewriting.bindingRewriteValidators.ifnot = false;
      
      b/*ko*/.virtualElements.allowedBindings.ifnot = true;
      
      b/*ko*/.bindingHandlers.foreach =  {
        makeTemplateValueAccessor : function (a/*valueAccessor*/) {
          return function () {
            var c/*bindingValue*/ = b/*ko*/.utils.unwrapObservable(a/*valueAccessor*/());
            
            if ((!c/*bindingValue*/) || typeof c/*bindingValue*/.length == "number"){
              return  {
                'foreach' : c/*bindingValue*/,
                'templateEngine' : b/*ko*/.nativeTemplateEngine.instance
              };
            }
            return  {
              'foreach' : c/*bindingValue*/['data'],
              'includeDestroyed' : c/*bindingValue*/['includeDestroyed'],
              'afterAdd' : c/*bindingValue*/['afterAdd'],
              'beforeRemove' : c/*bindingValue*/['beforeRemove'],
              'afterRender' : c/*bindingValue*/['afterRender'],
              'templateEngine' : b/*ko*/.nativeTemplateEngine.instance
            };
          };
        },
        'init' : function (f/*element*/,e/*valueAccessor*/,c/*allBindingsAccessor*/,d/*viewModel*/,a/*bindingContext*/) {
          return b/*ko*/.bindingHandlers['template']['init'](f/*element*/,b/*ko*/.bindingHandlers['foreach'].makeTemplateValueAccessor(e/*valueAccessor*/));
        },
        'update' : function (f/*element*/,e/*valueAccessor*/,c/*allBindingsAccessor*/,d/*viewModel*/,a/*bindingContext*/) {
          return b/*ko*/.bindingHandlers['template']['update'](f/*element*/,b/*ko*/.bindingHandlers['foreach'].makeTemplateValueAccessor(e/*valueAccessor*/),c/*allBindingsAccessor*/,d/*viewModel*/,a/*bindingContext*/);
        }
      };
      
      b/*ko*/.jsonExpressionRewriting.bindingRewriteValidators.foreach = false;
      
      b/*ko*/.virtualElements.allowedBindings.foreach = true;
      
      b/*ko*/.exportSymbol('ko.allowedVirtualElementBindings',b/*ko*/.virtualElements.allowedBindings);
      
      b/*ko*/.templateEngine = function (){};
      
      b/*ko*/.templateEngine.prototype.renderTemplateSource = function (c/*templateSource*/,b/*bindingContext*/,a/*options*/) {
        throw "Override renderTemplateSource"
        
      };
      
      b/*ko*/.templateEngine.prototype.createJavaScriptEvaluatorBlock = function (a/*script*/) {
        throw "Override createJavaScriptEvaluatorBlock"
        
      };
      
      b/*ko*/.templateEngine.prototype.makeTemplateSource = function (c/*template*/) {
        if (typeof c/*template*/ == "string"){
          
          var a/*elem*/ = document.getElementById(c/*template*/);
          
          if (!a/*elem*/)throw new Error("Cannot find template with ID "+c/*template*/)
          return new b/*ko*/.templateSources.domElement(a/*elem*/);
        } else if ((c/*template*/.nodeType == 1) || (c/*template*/.nodeType == 8))return new b/*ko*/.templateSources.anonymousTemplate(c/*template*/);
      };
      
      b/*ko*/.templateEngine.prototype.renderTemplate = function (d/*template*/,c/*bindingContext*/,b/*options*/) {
        var a/*templateSource*/ = this.makeTemplateSource(d/*template*/);
        return this.renderTemplateSource(a/*templateSource*/,c/*bindingContext*/,b/*options*/);
      };
      
      b/*ko*/.templateEngine.prototype.isTemplateRewritten = function (a/*template*/) {
        if (this.allowTemplateRewriting === false)return true;
        
        if (this.knownRewrittenTemplates && this.knownRewrittenTemplates[a/*template*/])return true;
        return this.makeTemplateSource(a/*template*/).data("isRewritten");
      };
      
      b/*ko*/.templateEngine.prototype.rewriteTemplate = function (d/*template*/,c/*rewriterCallback*/) {
        var a/*templateSource*/ = this.makeTemplateSource(d/*template*/),
            b/*rewritten*/ = c/*rewriterCallback*/(a/*templateSource*/.text());
        
        a/*templateSource*/.text(b/*rewritten*/);
        
        a/*templateSource*/.data("isRewritten",true);
        
        if (typeof d/*template*/ == "string"){
          
          this.knownRewrittenTemplates = this.knownRewrittenTemplates || {};
          
          this.knownRewrittenTemplates[d/*template*/] = true;
        }
        
      };
      
      b/*ko*/.exportSymbol('ko.templateEngine',b/*ko*/.templateEngine);
      
      b/*ko*/.templateRewriting = function () {
        function c/*constructMemoizedTagReplacement*/(h/*dataBindAttributeValue*/,g/*tagToRetain*/,f/*templateEngine*/) {
          var e/*dataBindKeyValueArray*/ = b/*ko*/.jsonExpressionRewriting.parseObjectLiteral(h/*dataBindAttributeValue*/);
          
          a/*validateDataBindValuesForRewriting*/(e/*dataBindKeyValueArray*/);
          
          var d/*rewrittenDataBindAttributeValue*/ = b/*ko*/.jsonExpressionRewriting.insertPropertyAccessorsIntoJson(e/*dataBindKeyValueArray*/),
              c/*applyBindingsToNextSiblingScript*/ = "ko.templateRewriting.applyMemoizedBindingsToNextSibling(function() { \
            return (function() { return { "+d/*rewrittenDataBindAttributeValue*/+" } })() \
        })";
          return f/*templateEngine*/.createJavaScriptEvaluatorBlock(c/*applyBindingsToNextSiblingScript*/)+g/*tagToRetain*/;
        }
        function a/*validateDataBindValuesForRewriting*/(g/*keyValueArray*/) {
          var f/*allValidators*/ = b/*ko*/.jsonExpressionRewriting.bindingRewriteValidators;
          
          for (var d/*i*/ = 0;d/*i*/<g/*keyValueArray*/.length;d/*i*/ ++ ){
            
            var c/*key*/ = g/*keyValueArray*/[d/*i*/].key;
            
            if (f/*allValidators*/.hasOwnProperty(c/*key*/)){
              
              var a/*validator*/ = f/*allValidators*/[c/*key*/];
              
              if (typeof a/*validator*/ === "function"){
                
                var e/*possibleErrorMessage*/ = a/*validator*/(g/*keyValueArray*/[d/*i*/].value);
                
                if (e/*possibleErrorMessage*/)throw new Error(e/*possibleErrorMessage*/)
                
              } else if (!a/*validator*/)throw new Error("This template engine does not support the '"+c/*key*/+"' binding within its templates")
              
            }
            
          }
          
        }
        var e/*memoizeDataBindingAttributeSyntaxRegex*/ = /(<[a-z]+\d*(\s+(?!data-bind=)[a-z0-9\-]+(=(\"[^\"]*\"|\'[^\']*\'))?)*\s+)data-bind=(["'])([\s\S]*?)\5/gi,
            d/*memoizeVirtualContainerBindingSyntaxRegex*/ = /<!--\s*ko\b\s*([\s\S]*?)\s*-->/g;
        return  {
          ensureTemplateIsRewritten : function (c/*template*/,a/*templateEngine*/) {
            if (!a/*templateEngine*/['isTemplateRewritten'](c/*template*/)){
              
              a/*templateEngine*/['rewriteTemplate'](c/*template*/,
              function (c/*htmlString*/) {
                return b/*ko*/.templateRewriting.memoizeBindingAttributeSyntax(c/*htmlString*/,a/*templateEngine*/);
              });
            }
            
          },
          memoizeBindingAttributeSyntax : function (f/*htmlString*/,a/*templateEngine*/) {
            return f/*htmlString*/.replace(e/*memoizeDataBindingAttributeSyntaxRegex*/,
            function () {
              return c/*constructMemoizedTagReplacement*/(arguments[6],arguments[1],a/*templateEngine*/);
            }).replace(d/*memoizeVirtualContainerBindingSyntaxRegex*/,
            function () {
              return c/*constructMemoizedTagReplacement*/(arguments[1],"<!-- ko -->",a/*templateEngine*/);
            });
          },
          applyMemoizedBindingsToNextSibling : function (a/*bindings*/) {
            return b/*ko*/.memoization.memoize(function (d/*domNode*/,c/*bindingContext*/) {
              if (d/*domNode*/.nextSibling){
                
                b/*ko*/.applyBindingsToNode(d/*domNode*/.nextSibling,a/*bindings*/,c/*bindingContext*/);
              }
              
            });
          }
        };
      }();
      
      b/*ko*/.exportSymbol('ko.templateRewriting',b/*ko*/.templateRewriting);
      
      b/*ko*/.exportSymbol('ko.templateRewriting.applyMemoizedBindingsToNextSibling',b/*ko*/.templateRewriting.applyMemoizedBindingsToNextSibling);
      
      !function () {
        b/*ko*/.templateSources = {};
        
        b/*ko*/.templateSources.domElement = function (a/*element*/) {
          this.domElement = a/*element*/;
        };
        
        b/*ko*/.templateSources.domElement.prototype.text = function () {
          if (arguments.length == 0)return this.domElement.tagName.toLowerCase() == "script"?this.domElement.text : this.domElement.innerHTML;
          
          {
            
            var a/*valueToWrite*/ = arguments[0];
            
            this.domElement.tagName.toLowerCase() == "script"?this.domElement.text = a/*valueToWrite*/ : b/*ko*/.utils.setHtml(this.domElement,a/*valueToWrite*/);
          }
          
        };
        
        b/*ko*/.templateSources.domElement.prototype.data = function (a/*key*/) {
          if (arguments.length === 1)return b/*ko*/.utils.domData.get(this.domElement,"templateSourceData_"+a/*key*/);
          
          b/*ko*/.utils.domData.set(this.domElement,"templateSourceData_"+a/*key*/,arguments[1]);
        };
        
        var a/*anonymousTemplatesDomDataKey*/ = "__ko_anon_template__";
        
        b/*ko*/.templateSources.anonymousTemplate = function (a/*element*/) {
          this.domElement = a/*element*/;
        };
        
        b/*ko*/.templateSources.anonymousTemplate.prototype = new b/*ko*/.templateSources.domElement();
        
        b/*ko*/.templateSources.anonymousTemplate.prototype.text = function () {
          if (arguments.length == 0)return b/*ko*/.utils.domData.get(this.domElement,a/*anonymousTemplatesDomDataKey*/);
          
          {
            
            var c/*valueToWrite*/ = arguments[0];
            
            b/*ko*/.utils.domData.set(this.domElement,a/*anonymousTemplatesDomDataKey*/,c/*valueToWrite*/);
          }
          
        };
        
        b/*ko*/.exportSymbol('ko.templateSources',b/*ko*/.templateSources);
        
        b/*ko*/.exportSymbol('ko.templateSources.domElement',b/*ko*/.templateSources.domElement);
        
        b/*ko*/.exportSymbol('ko.templateSources.anonymousTemplate',b/*ko*/.templateSources.anonymousTemplate);
      }();
      
      !function () {
        function g/*disposeOldSubscriptionAndStoreNewOne*/(i/*element*/,h/*newSubscription*/) {
          var g/*oldSubscription*/ = b/*ko*/.utils.domData.get(i/*element*/,f/*templateSubscriptionDomDataKey*/);
          
          g/*oldSubscription*/ && (typeof (g/*oldSubscription*/.dispose) == 'function') && g/*oldSubscription*/.dispose();
          
          b/*ko*/.utils.domData.set(i/*element*/,f/*templateSubscriptionDomDataKey*/,h/*newSubscription*/);
        }
        function d/*executeTemplate*/(j/*targetNodeOrNodeArray*/,i/*renderMode*/,h/*template*/,g/*bindingContext*/,f/*options*/) {
          f/*options*/ = f/*options*/ || {};
          
          var e/*templateEngineToUse*/ = (f/*options*/.templateEngine || a/*_templateEngine*/);
          
          b/*ko*/.templateRewriting.ensureTemplateIsRewritten(h/*template*/,e/*templateEngineToUse*/);
          
          var c/*renderedNodesArray*/ = e/*templateEngineToUse*/.renderTemplate(h/*template*/,g/*bindingContext*/,f/*options*/);
          
          if ((typeof c/*renderedNodesArray*/.length != "number") || (c/*renderedNodesArray*/.length>0 && typeof c/*renderedNodesArray*/[0].nodeType != "number"))throw "Template engine must return an array of DOM nodes"
          
          var d/*haveAddedNodesToParent*/ = false;
          
          switch (i/*renderMode*/) {
            case "replaceChildren" :
              
              b/*ko*/.virtualElements.setDomNodeChildren(j/*targetNodeOrNodeArray*/,c/*renderedNodesArray*/);
              
              d/*haveAddedNodesToParent*/ = true;
              break;
            case "replaceNode" :
              
              b/*ko*/.utils.replaceDomNodes(j/*targetNodeOrNodeArray*/,c/*renderedNodesArray*/);
              
              d/*haveAddedNodesToParent*/ = true;
              break;
            case "ignoreTargetNode" :
              break;
            default :
              throw new Error("Unknown renderMode: "+i/*renderMode*/)
              
          }
          
          if (d/*haveAddedNodesToParent*/){
            
            b/*ko*/.activateBindingsOnTemplateRenderedNodes(c/*renderedNodesArray*/,g/*bindingContext*/);
            
            f/*options*/.afterRender && f/*options*/.afterRender(c/*renderedNodesArray*/,g/*bindingContext*/.$data);
          }
          return c/*renderedNodesArray*/;
        }
        function e/*getFirstNodeFromPossibleArray*/(a/*nodeOrNodeArray*/) {
          return a/*nodeOrNodeArray*/.nodeType?a/*nodeOrNodeArray*/ : a/*nodeOrNodeArray*/.length>0?a/*nodeOrNodeArray*/[0] : null;
        }
        function c/*invokeForEachNodeOrCommentInParent*/(d/*nodeArray*/,c/*parent*/,b/*action*/) {
          for (var a/*i*/ = 0;node = d/*nodeArray*/[a/*i*/];a/*i*/ ++ ){
            
            if (node.parentNode !== c/*parent*/)continue ;
            
            ((node.nodeType === 1) || (node.nodeType === 8)) && b/*action*/(node);
          }
          
        }
        var a/*_templateEngine*/;
        
        b/*ko*/.setTemplateEngine = function (c/*templateEngine*/) {
          if ((c/*templateEngine*/ != undefined) && !(c/*templateEngine*/ instanceof b/*ko*/.templateEngine))throw "templateEngine must inherit from ko.templateEngine"
          
          a/*_templateEngine*/ = c/*templateEngine*/;
        };
        
        b/*ko*/.activateBindingsOnTemplateRenderedNodes = function (f/*nodeArray*/,a/*bindingContext*/) {
          var e/*nodeArrayClone*/ = b/*ko*/.utils.arrayPushAll([],f/*nodeArray*/),
              d/*commonParentElement*/ = (f/*nodeArray*/.length>0)?f/*nodeArray*/[0].parentNode : null;
          
          c/*invokeForEachNodeOrCommentInParent*/(e/*nodeArrayClone*/,d/*commonParentElement*/,
          function (c/*node*/) {
            b/*ko*/.applyBindings(a/*bindingContext*/,c/*node*/);
          });
          
          c/*invokeForEachNodeOrCommentInParent*/(e/*nodeArrayClone*/,d/*commonParentElement*/,
          function (a/*node*/) {
            b/*ko*/.memoization.unmemoizeDomNodeAndDescendants(a/*node*/,[a/*bindingContext*/]);
          });
        };
        
        b/*ko*/.renderTemplate = function (g/*template*/,j/*dataOrBindingContext*/,f/*options*/,i/*targetNodeOrNodeArray*/,h/*renderMode*/) {
          f/*options*/ = f/*options*/ || {};
          
          if ((f/*options*/.templateEngine || a/*_templateEngine*/) == undefined)throw "Set a template engine before calling renderTemplate"
          
          h/*renderMode*/ = h/*renderMode*/ || "replaceChildren";
          
          if (i/*targetNodeOrNodeArray*/){
            
            var c/*firstTargetNode*/ = e/*getFirstNodeFromPossibleArray*/(i/*targetNodeOrNodeArray*/);
            
            var l/*whenToDispose*/ = function () {
                  return (!c/*firstTargetNode*/) || !b/*ko*/.utils.domNodeIsAttachedToDocument(c/*firstTargetNode*/);
                };
            
            var k/*activelyDisposeWhenNodeIsRemoved*/ = (c/*firstTargetNode*/ && h/*renderMode*/ == "replaceNode")?c/*firstTargetNode*/.parentNode : c/*firstTargetNode*/;
            return new b/*ko*/.dependentObservable(function () {
              var m/*bindingContext*/ = (j/*dataOrBindingContext*/ && (j/*dataOrBindingContext*/ instanceof b/*ko*/.bindingContext))?j/*dataOrBindingContext*/ : new b/*ko*/.bindingContext(b/*ko*/.utils.unwrapObservable(j/*dataOrBindingContext*/)),
                  l/*templateName*/ = typeof (g/*template*/) == 'function'?g/*template*/(m/*bindingContext*/.$data) : g/*template*/,
                  k/*renderedNodesArray*/ = d/*executeTemplate*/(i/*targetNodeOrNodeArray*/,h/*renderMode*/,l/*templateName*/,m/*bindingContext*/,f/*options*/);
              
              if (h/*renderMode*/ == "replaceNode"){
                
                i/*targetNodeOrNodeArray*/ = k/*renderedNodesArray*/;
                
                c/*firstTargetNode*/ = e/*getFirstNodeFromPossibleArray*/(i/*targetNodeOrNodeArray*/);
              }
              
            },null, {
              'disposeWhen' : l/*whenToDispose*/,
              'disposeWhenNodeIsRemoved' : k/*activelyDisposeWhenNodeIsRemoved*/
            });
          } else return b/*ko*/.memoization.memoize(function (a/*domNode*/) {
            b/*ko*/.renderTemplate(g/*template*/,j/*dataOrBindingContext*/,f/*options*/,a/*domNode*/,"replaceNode");
          });
        };
        
        b/*ko*/.renderTemplateForEach = function (i/*template*/,g/*arrayOrObservableArray*/,c/*options*/,h/*targetNode*/,a/*parentBindingContext*/) {
          var e/*createInnerBindingContext*/ = function (c/*arrayValue*/) {
                return a/*parentBindingContext*/.createChildContext(b/*ko*/.utils.unwrapObservable(c/*arrayValue*/));
              },
              f/*activateBindingsCallback*/ = function (h/*arrayValue*/,g/*addedNodesArray*/) {
                var f/*bindingContext*/ = e/*createInnerBindingContext*/(h/*arrayValue*/);
                
                b/*ko*/.activateBindingsOnTemplateRenderedNodes(g/*addedNodesArray*/,f/*bindingContext*/);
                
                c/*options*/.afterRender && c/*options*/.afterRender(g/*addedNodesArray*/,f/*bindingContext*/.$data);
              };
          return new b/*ko*/.dependentObservable(function () {
            var k/*unwrappedArray*/ = b/*ko*/.utils.unwrapObservable(g/*arrayOrObservableArray*/) || [];
            
            typeof k/*unwrappedArray*/.length == "undefined" && (k/*unwrappedArray*/ = [k/*unwrappedArray*/]);
            
            var j/*filteredArray*/ = b/*ko*/.utils.arrayFilter(k/*unwrappedArray*/,
                function (a/*item*/) {
                  return c/*options*/.includeDestroyed || a/*item*/ === undefined || a/*item*/ === null || !b/*ko*/.utils.unwrapObservable(a/*item*/._destroy);
                });
            
            b/*ko*/.utils.setDomNodeChildrenFromArrayMapping(h/*targetNode*/,j/*filteredArray*/,
            function (b/*arrayValue*/) {
              var a/*templateName*/ = typeof (i/*template*/) == 'function'?i/*template*/(b/*arrayValue*/) : i/*template*/;
              return d/*executeTemplate*/(null,"ignoreTargetNode",a/*templateName*/,e/*createInnerBindingContext*/(b/*arrayValue*/),c/*options*/);
            },c/*options*/,f/*activateBindingsCallback*/);
          },null, {
            'disposeWhenNodeIsRemoved' : h/*targetNode*/
          });
        };
        
        var f/*templateSubscriptionDomDataKey*/ = '__ko__templateSubscriptionDomDataKey__';
        
        b/*ko*/.bindingHandlers.template =  {
          'init' : function (d/*element*/,c/*valueAccessor*/) {
            var a/*bindingValue*/ = b/*ko*/.utils.unwrapObservable(c/*valueAccessor*/());
            
            if ((typeof a/*bindingValue*/ != "string") && (!a/*bindingValue*/.name) && (d/*element*/.nodeType == 1)){
              
              new b/*ko*/.templateSources.anonymousTemplate(d/*element*/).text(d/*element*/.innerHTML);
              
              b/*ko*/.utils.emptyDomNode(d/*element*/);
            }
            return  {
              'controlsDescendantBindings' : true
            };
          },
          'update' : function (r/*element*/,k/*valueAccessor*/,o/*allBindingsAccessor*/,q/*viewModel*/,h/*bindingContext*/) {
            var p/*bindingValue*/ = b/*ko*/.utils.unwrapObservable(k/*valueAccessor*/());
            
            var m/*templateName*/;
            
            var l/*shouldDisplay*/ = true;
            
            if (typeof p/*bindingValue*/ == "string"){
              
              m/*templateName*/ = p/*bindingValue*/;
            } else {
              
              m/*templateName*/ = p/*bindingValue*/.name;
              if ('if' in p/*bindingValue*/){
                
                l/*shouldDisplay*/ = l/*shouldDisplay*/ && b/*ko*/.utils.unwrapObservable(p/*bindingValue*/['if']);
              }
              if ('ifnot' in p/*bindingValue*/){
                
                l/*shouldDisplay*/ = l/*shouldDisplay*/ && !b/*ko*/.utils.unwrapObservable(p/*bindingValue*/['ifnot']);
              }
              
            }
            
            var j/*templateSubscription*/ = null;
            
            if ((typeof p/*bindingValue*/ === 'object') && ('foreach' in p/*bindingValue*/)){
              
              var i/*dataArray*/ = (l/*shouldDisplay*/ && p/*bindingValue*/['foreach']) || [];
              
              j/*templateSubscription*/ = b/*ko*/.renderTemplateForEach(m/*templateName*/ || r/*element*/,i/*dataArray*/,p/*bindingValue*/,r/*element*/,h/*bindingContext*/);
            } else {
              if (l/*shouldDisplay*/){
                
                var n/*innerBindingContext*/ = (typeof p/*bindingValue*/ == 'object') && ('data' in p/*bindingValue*/)?h/*bindingContext*/['createChildContext'](b/*ko*/.utils.unwrapObservable(p/*bindingValue*/['data'])) : h/*bindingContext*/;
                
                j/*templateSubscription*/ = b/*ko*/.renderTemplate(m/*templateName*/ || r/*element*/,n/*innerBindingContext*/,p/*bindingValue*/,r/*element*/);
              } else b/*ko*/.virtualElements.emptyNode(r/*element*/);
            }
            
            g/*disposeOldSubscriptionAndStoreNewOne*/(r/*element*/,j/*templateSubscription*/);
          }
        };
        
        b/*ko*/.jsonExpressionRewriting.bindingRewriteValidators.template = function (c/*bindingValue*/) {
          var a/*parsedBindingValue*/ = b/*ko*/.jsonExpressionRewriting.parseObjectLiteral(c/*bindingValue*/);
          
          if ((a/*parsedBindingValue*/.length == 1) && a/*parsedBindingValue*/[0].unknown)return null;
          
          if (b/*ko*/.jsonExpressionRewriting.keyValueArrayContainsKey(a/*parsedBindingValue*/,"name"))return null;
          return "This template engine does not support anonymous templates nested within its templates";
        };
        
        b/*ko*/.virtualElements.allowedBindings.template = true;
      }();
      
      b/*ko*/.exportSymbol('ko.setTemplateEngine',b/*ko*/.setTemplateEngine);
      
      b/*ko*/.exportSymbol('ko.renderTemplate',b/*ko*/.renderTemplate);
      
      !function () {
        function a/*findEditScriptFromEditDistanceMatrix*/(k/*editDistanceMatrix*/,i/*oldArray*/,b/*newArray*/) {
          var h/*oldIndex*/ = i/*oldArray*/.length,
              f/*newIndex*/ = b/*newArray*/.length,
              j/*editScript*/ = [],
              d/*maxDistance*/ = k/*editDistanceMatrix*/[f/*newIndex*/][h/*oldIndex*/];
          
          if (d/*maxDistance*/ === undefined)return null;
          
          while ((h/*oldIndex*/>0) || (f/*newIndex*/>0)){
            
            var g/*me*/ = k/*editDistanceMatrix*/[f/*newIndex*/][h/*oldIndex*/];
            
            var e/*distanceViaAdd*/ = (f/*newIndex*/>0)?k/*editDistanceMatrix*/[f/*newIndex*/-1][h/*oldIndex*/] : d/*maxDistance*/+1;
            
            var c/*distanceViaDelete*/ = (h/*oldIndex*/>0)?k/*editDistanceMatrix*/[f/*newIndex*/][h/*oldIndex*/-1] : d/*maxDistance*/+1;
            
            var a/*distanceViaRetain*/ = (f/*newIndex*/>0) && (h/*oldIndex*/>0)?k/*editDistanceMatrix*/[f/*newIndex*/-1][h/*oldIndex*/-1] : d/*maxDistance*/+1;
            
            ((e/*distanceViaAdd*/ === undefined) || (e/*distanceViaAdd*/<g/*me*/-1)) && (e/*distanceViaAdd*/ = d/*maxDistance*/+1);
            
            ((c/*distanceViaDelete*/ === undefined) || (c/*distanceViaDelete*/<g/*me*/-1)) && (c/*distanceViaDelete*/ = d/*maxDistance*/+1);
            
            a/*distanceViaRetain*/<g/*me*/-1 && (a/*distanceViaRetain*/ = d/*maxDistance*/+1);
            
            if ((e/*distanceViaAdd*/ <= c/*distanceViaDelete*/) && (e/*distanceViaAdd*/<a/*distanceViaRetain*/)){
              
              j/*editScript*/.push( {
                status : "added",
                value : b/*newArray*/[f/*newIndex*/-1]
              });
              
              f/*newIndex*/ -- ;
            } else if ((c/*distanceViaDelete*/<e/*distanceViaAdd*/) && (c/*distanceViaDelete*/<a/*distanceViaRetain*/)){
              
              j/*editScript*/.push( {
                status : "deleted",
                value : i/*oldArray*/[h/*oldIndex*/-1]
              });
              
              h/*oldIndex*/ -- ;
            } else {
              
              j/*editScript*/.push( {
                status : "retained",
                value : i/*oldArray*/[h/*oldIndex*/-1]
              });
              
              f/*newIndex*/ -- ;
              
              h/*oldIndex*/ -- ;
            }
            
          }
          return j/*editScript*/.reverse();
        }
        function c/*calculateEditDistanceMatrix*/(p/*oldArray*/,g/*newArray*/,o/*maxAllowedDistance*/) {
          var m/*distances*/ = [];
          
          for (var l/*i*/ = 0;l/*i*/ <= g/*newArray*/.length;l/*i*/ ++ )
          m/*distances*/[l/*i*/] = [];
          
          for (var l/*i*/ = 0,n/*j*/ = Math.min(p/*oldArray*/.length,o/*maxAllowedDistance*/);l/*i*/ <= n/*j*/;l/*i*/ ++ )
          m/*distances*/[0][l/*i*/] = l/*i*/;
          
          for (var l/*i*/ = 1,n/*j*/ = Math.min(g/*newArray*/.length,o/*maxAllowedDistance*/);l/*i*/ <= n/*j*/;l/*i*/ ++ )
          m/*distances*/[l/*i*/][0] = l/*i*/;
          
          var k/*oldIndex*/,
              i/*oldIndexMax*/ = p/*oldArray*/.length,
              e/*newIndex*/,
              h/*newIndexMax*/ = g/*newArray*/.length,
              c/*distanceViaAddition*/,
              a/*distanceViaDeletion*/;
          
          for (k/*oldIndex*/ = 1;k/*oldIndex*/ <= i/*oldIndexMax*/;k/*oldIndex*/ ++ ){
            
            var j/*newIndexMinForRow*/ = Math.max(1,k/*oldIndex*/-o/*maxAllowedDistance*/);
            
            var f/*newIndexMaxForRow*/ = Math.min(h/*newIndexMax*/,k/*oldIndex*/+o/*maxAllowedDistance*/);
            
            for (e/*newIndex*/ = j/*newIndexMinForRow*/;e/*newIndex*/ <= f/*newIndexMaxForRow*/;e/*newIndex*/ ++ )if (p/*oldArray*/[k/*oldIndex*/-1] === g/*newArray*/[e/*newIndex*/-1])m/*distances*/[e/*newIndex*/][k/*oldIndex*/] = m/*distances*/[e/*newIndex*/-1][k/*oldIndex*/-1];
             else {
              
              var d/*northDistance*/ = m/*distances*/[e/*newIndex*/-1][k/*oldIndex*/] === undefined?Number.MAX_VALUE : m/*distances*/[e/*newIndex*/-1][k/*oldIndex*/]+1;
              
              var b/*westDistance*/ = m/*distances*/[e/*newIndex*/][k/*oldIndex*/-1] === undefined?Number.MAX_VALUE : m/*distances*/[e/*newIndex*/][k/*oldIndex*/-1]+1;
              
              m/*distances*/[e/*newIndex*/][k/*oldIndex*/] = Math.min(d/*northDistance*/,b/*westDistance*/);
            }
            
          }
          return m/*distances*/;
        }
        b/*ko*/.utils.compareArrays = function (g/*oldArray*/,f/*newArray*/,e/*maxEditsToConsider*/) {
          if (e/*maxEditsToConsider*/ === undefined)return b/*ko*/.utils.compareArrays(g/*oldArray*/,f/*newArray*/,1) || b/*ko*/.utils.compareArrays(g/*oldArray*/,f/*newArray*/,10) || b/*ko*/.utils.compareArrays(g/*oldArray*/,f/*newArray*/,Number.MAX_VALUE);
          
          {
            
            g/*oldArray*/ = g/*oldArray*/ || [];
            
            f/*newArray*/ = f/*newArray*/ || [];
            
            var d/*editDistanceMatrix*/ = c/*calculateEditDistanceMatrix*/(g/*oldArray*/,f/*newArray*/,e/*maxEditsToConsider*/);
            return a/*findEditScriptFromEditDistanceMatrix*/(d/*editDistanceMatrix*/,g/*oldArray*/,f/*newArray*/);
          }
          
        };
      }();
      
      b/*ko*/.exportSymbol('ko.utils.compareArrays',b/*ko*/.utils.compareArrays);
      
      !function () {
        function c/*mapNodeAndRefreshWhenChanged*/(h/*containerNode*/,f/*mapping*/,e/*valueToMap*/,c/*callbackAfterAddingNodes*/) {
          var d/*mappedNodes*/ = [],
              g/*dependentObservable*/ = b/*ko*/.dependentObservable(function () {
                var g/*newMappedNodes*/ = f/*mapping*/(e/*valueToMap*/) || [];
                
                if (d/*mappedNodes*/.length>0){
                  
                  a/*fixUpVirtualElements*/(d/*mappedNodes*/);
                  
                  b/*ko*/.utils.replaceDomNodes(d/*mappedNodes*/,g/*newMappedNodes*/);
                  
                  c/*callbackAfterAddingNodes*/ && c/*callbackAfterAddingNodes*/(e/*valueToMap*/,g/*newMappedNodes*/);
                }
                
                d/*mappedNodes*/.splice(0,d/*mappedNodes*/.length);
                
                b/*ko*/.utils.arrayPushAll(d/*mappedNodes*/,g/*newMappedNodes*/);
              },null, {
                'disposeWhenNodeIsRemoved' : h/*containerNode*/,
                'disposeWhen' : function () {
                  return (d/*mappedNodes*/.length == 0) || !b/*ko*/.utils.domNodeIsAttachedToDocument(d/*mappedNodes*/[0]);
                }
              });
          return  {
            mappedNodes : d/*mappedNodes*/,
            dependentObservable : g/*dependentObservable*/
          };
        }
        function a/*fixUpVirtualElements*/(d/*contiguousNodeArray*/) {
          if (d/*contiguousNodeArray*/.length>2){
            
            var a/*current*/ = d/*contiguousNodeArray*/[0],
                c/*last*/ = d/*contiguousNodeArray*/[d/*contiguousNodeArray*/.length-1],
                b/*newContiguousSet*/ = [a/*current*/];
            
            while (a/*current*/ !== c/*last*/){
              
              a/*current*/ = a/*current*/.nextSibling;
              
              if (!a/*current*/)return ;
              
              b/*newContiguousSet*/.push(a/*current*/);
            }
            
            [].splice.apply(d/*contiguousNodeArray*/,[0,d/*contiguousNodeArray*/.length].concat(b/*newContiguousSet*/));
          }
          
        }
        var d/*lastMappingResultDomDataKey*/ = "setDomNodeChildrenFromArrayMapping_lastMappingResult";
        
        b/*ko*/.utils.setDomNodeChildrenFromArrayMapping = function (o/*domNode*/,p/*array*/,z/*mapping*/,v/*options*/,r/*callbackAfterAddingNodes*/) {
          p/*array*/ = p/*array*/ || [];
          
          v/*options*/ = v/*options*/ || {};
          
          var x/*isFirstExecution*/ = b/*ko*/.utils.domData.get(o/*domNode*/,d/*lastMappingResultDomDataKey*/) === undefined,
              B/*lastMappingResult*/ = b/*ko*/.utils.domData.get(o/*domNode*/,d/*lastMappingResultDomDataKey*/) || [],
              u/*lastArray*/ = b/*ko*/.utils.arrayMap(B/*lastMappingResult*/,
              function (a/*x*/) {
                return a/*x*/.arrayEntry;
              }),
              f/*editScript*/ = b/*ko*/.utils.compareArrays(u/*lastArray*/,p/*array*/),
              q/*newMappingResult*/ = [],
              m/*lastMappingResultIndex*/ = 0,
              h/*nodesToDelete*/ = [],
              s/*nodesAdded*/ = [],
              e/*insertAfterNode*/ = null;
          
          for (var g/*i*/ = 0,w/*j*/ = f/*editScript*/.length;g/*i*/<w/*j*/;g/*i*/ ++ )
          switch (f/*editScript*/[g/*i*/].status) {
            case "retained" :
              
              var n/*dataToRetain*/ = B/*lastMappingResult*/[m/*lastMappingResultIndex*/];
              
              q/*newMappingResult*/.push(n/*dataToRetain*/);
              
              n/*dataToRetain*/.domNodes.length>0 && (e/*insertAfterNode*/ = n/*dataToRetain*/.domNodes[n/*dataToRetain*/.domNodes.length-1]);
              
              m/*lastMappingResultIndex*/ ++ ;
              break;
            case "deleted" :
              
              B/*lastMappingResult*/[m/*lastMappingResultIndex*/].dependentObservable.dispose();
              
              a/*fixUpVirtualElements*/(B/*lastMappingResult*/[m/*lastMappingResultIndex*/].domNodes);
              
              b/*ko*/.utils.arrayForEach(B/*lastMappingResult*/[m/*lastMappingResultIndex*/].domNodes,
              function (i/*node*/) {
                h/*nodesToDelete*/.push( {
                  element : i/*node*/,
                  index : g/*i*/,
                  value : f/*editScript*/[g/*i*/].value
                });
                
                e/*insertAfterNode*/ = i/*node*/;
              });
              
              m/*lastMappingResultIndex*/ ++ ;
              break;
            case "added" :
              
              var k/*valueToMap*/ = f/*editScript*/[g/*i*/].value;
              
              var j/*mapData*/ = c/*mapNodeAndRefreshWhenChanged*/(o/*domNode*/,z/*mapping*/,k/*valueToMap*/,r/*callbackAfterAddingNodes*/);
              
              var t/*mappedNodes*/ = j/*mapData*/.mappedNodes;
              
              q/*newMappingResult*/.push( {
                arrayEntry : f/*editScript*/[g/*i*/].value,
                domNodes : t/*mappedNodes*/,
                dependentObservable : j/*mapData*/.dependentObservable
              });
              
              for (var y/*nodeIndex*/ = 0,i/*nodeIndexMax*/ = t/*mappedNodes*/.length;y/*nodeIndex*/<i/*nodeIndexMax*/;y/*nodeIndex*/ ++ ){
                
                var A/*node*/ = t/*mappedNodes*/[y/*nodeIndex*/];
                
                s/*nodesAdded*/.push( {
                  element : A/*node*/,
                  index : g/*i*/,
                  value : f/*editScript*/[g/*i*/].value
                });
                
                if (e/*insertAfterNode*/ == null){
                  
                  b/*ko*/.virtualElements.prepend(o/*domNode*/,A/*node*/);
                } else {
                  
                  b/*ko*/.virtualElements.insertAfter(o/*domNode*/,A/*node*/,e/*insertAfterNode*/);
                }
                
                e/*insertAfterNode*/ = A/*node*/;
              }
              
              if (r/*callbackAfterAddingNodes*/){
                
                r/*callbackAfterAddingNodes*/(k/*valueToMap*/,t/*mappedNodes*/);
              }
              break;
              
          }
          
          b/*ko*/.utils.arrayForEach(h/*nodesToDelete*/,
          function (a/*node*/) {
            b/*ko*/.cleanNode(a/*node*/.element);
          });
          
          var l/*invokedBeforeRemoveCallback*/ = false;
          
          if (!x/*isFirstExecution*/){
            
            if (v/*options*/.afterAdd)for (var g/*i*/ = 0;g/*i*/<s/*nodesAdded*/.length;g/*i*/ ++ )
            v/*options*/.afterAdd(s/*nodesAdded*/[g/*i*/].element,s/*nodesAdded*/[g/*i*/].index,s/*nodesAdded*/[g/*i*/].value);
            
            if (v/*options*/.beforeRemove){
              
              for (var g/*i*/ = 0;g/*i*/<h/*nodesToDelete*/.length;g/*i*/ ++ )v/*options*/.beforeRemove(h/*nodesToDelete*/[g/*i*/].element,h/*nodesToDelete*/[g/*i*/].index,h/*nodesToDelete*/[g/*i*/].value);
              
              l/*invokedBeforeRemoveCallback*/ = true;
            }
            
          }
          
          !l/*invokedBeforeRemoveCallback*/ && b/*ko*/.utils.arrayForEach(h/*nodesToDelete*/,
          function (a/*node*/) {
            b/*ko*/.removeNode(a/*node*/.element);
          });
          
          b/*ko*/.utils.domData.set(o/*domNode*/,d/*lastMappingResultDomDataKey*/,q/*newMappingResult*/);
        };
      }();
      
      b/*ko*/.exportSymbol('ko.utils.setDomNodeChildrenFromArrayMapping',b/*ko*/.utils.setDomNodeChildrenFromArrayMapping);
      
      b/*ko*/.nativeTemplateEngine = function () {
        this.allowTemplateRewriting = false;
      };
      
      b/*ko*/.nativeTemplateEngine.prototype = new b/*ko*/.templateEngine();
      
      b/*ko*/.nativeTemplateEngine.prototype.renderTemplateSource = function (e/*templateSource*/,d/*bindingContext*/,c/*options*/) {
        var a/*templateText*/ = e/*templateSource*/.text();
        return b/*ko*/.utils.parseHtmlFragment(a/*templateText*/);
      };
      
      b/*ko*/.nativeTemplateEngine.instance = new b/*ko*/.nativeTemplateEngine();
      
      b/*ko*/.setTemplateEngine(b/*ko*/.nativeTemplateEngine.instance);
      
      b/*ko*/.exportSymbol('ko.nativeTemplateEngine',b/*ko*/.nativeTemplateEngine);
      
      !function () {
        b/*ko*/.jqueryTmplTemplateEngine = function () {
          function b/*executeTemplate*/(c/*compiledTemplate*/,b/*data*/,a/*jQueryTemplateOptions*/) {
            return jQuery.tmpl(c/*compiledTemplate*/,b/*data*/,a/*jQueryTemplateOptions*/);
          }
          function c/*ensureHasReferencedJQueryTemplates*/() {
            if (a/*jQueryTmplVersion*/<2)throw new Error("Your version of jQuery.tmpl is too old. Please upgrade to jQuery.tmpl 1.0.0pre or later.")
            
          }
          var a/*jQueryTmplVersion*/ = this.jQueryTmplVersion = function () {
                if ((typeof (jQuery) == "undefined") || !(jQuery.tmpl))return 0;
                
                try {
                  
                  if (jQuery.tmpl.tag.tmpl.open.toString().indexOf('__') >= 0)return 2;
                } catch(ex){
                  
                }
                return 1;
              }();
          
          this.renderTemplateSource = function (k/*templateSource*/,i/*bindingContext*/,g/*options*/) {
            g/*options*/ = g/*options*/ || {};
            
            c/*ensureHasReferencedJQueryTemplates*/();
            
            var f/*precompiled*/ = k/*templateSource*/.data('precompiled');
            
            if (!f/*precompiled*/){
              
              var e/*templateText*/ = k/*templateSource*/.text() || "";
              
              e/*templateText*/ = "{{ko_with $item.koBindingContext}}"+e/*templateText*/+"{{/ko_with}}";
              
              f/*precompiled*/ = jQuery.template(null,e/*templateText*/);
              
              k/*templateSource*/.data('precompiled',f/*precompiled*/);
            }
            
            var j/*data*/ = [i/*bindingContext*/['$data']],
                d/*jQueryTemplateOptions*/ = jQuery.extend( {
                  'koBindingContext' : i/*bindingContext*/
                },g/*options*/.templateOptions),
                h/*resultNodes*/ = b/*executeTemplate*/(f/*precompiled*/,j/*data*/,d/*jQueryTemplateOptions*/);
            
            h/*resultNodes*/.appendTo(document.createElement("div"));
            
            jQuery.fragments = {};
            return h/*resultNodes*/;
          };
          
          this.createJavaScriptEvaluatorBlock = function (a/*script*/) {
            return "{{ko_code ((function() { return "+a/*script*/+" })()) }}";
          };
          
          this.addTemplate = function (b/*templateName*/,a/*templateMarkup*/) {
            document.write("<script type='text/html' id='"+b/*templateName*/+"'>"+a/*templateMarkup*/+"</script>");
          };
          
          if (a/*jQueryTmplVersion*/>0){
            
            jQuery.tmpl.tag.ko_code =  {
              open : "__.push($1 || '');"
            };
            
            jQuery.tmpl.tag.ko_with =  {
              open : "with($1) {",
              close : "} "
            };
          }
          
        };
        
        b/*ko*/.jqueryTmplTemplateEngine.prototype = new b/*ko*/.templateEngine();
        
        var a/*jqueryTmplTemplateEngineInstance*/ = new b/*ko*/.jqueryTmplTemplateEngine();
        
        a/*jqueryTmplTemplateEngineInstance*/.jQueryTmplVersion>0 && b/*ko*/.setTemplateEngine(a/*jqueryTmplTemplateEngineInstance*/);
        
        b/*ko*/.exportSymbol('ko.jqueryTmplTemplateEngine',b/*ko*/.jqueryTmplTemplateEngine);
      }();
    }(window);
  }();
}();
