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
    b/*_mochaGlobalExport*/['-759650552-yield_test.js'] = {};
    
    var f/*_mochaGlobalAlias*/ = b/*_mochaGlobalExport*/['-759650552-yield_test.js'],
        d/*generator*/,
        e/*tests*/ =  {
          case1 : function () {
            function e/*yieldTest2*/() {
              var d/*_mochaIsNewBorn*/ = true;
              
              var f/*_yieldResult*/ = undefined;
              
              var b/*_yieldState*/ = 0;
              
              var c/*i*/;
              
              var e/*_mochaGenerator*/ = function (f/*_isYieldSend*/,e/*_isYieldSafe*/) {
                    if (!f/*_isYieldSend*/){
                      
                      d/*_mochaIsNewBorn*/ = false;
                    } else if (f/*_isYieldSend*/ && d/*_mochaIsNewBorn*/ && arguments[1] !== undefined){
                      
                      a/*Runtime*/.exceptionHandler('attempt to send to newborn generator.');
                    }
                    
                    while (1){
                      switch (b/*_yieldState*/) {
                        case 0 :
                          
                          c/*i*/ = 0;
                          
                          if (!(c/*i*/<10)){
                            
                            b/*_yieldState*/ = -1;
                            break;
                          }
                        case 1 :
                          
                          b/*_yieldState*/ = 2;
                          return c/*i*/;
                        case 2 :
                          
                          c/*i*/ ++ ;
                          
                          if (c/*i*/<10){
                            
                            b/*_yieldState*/ = 1;
                            break;
                          } else {
                            
                            b/*_yieldState*/ = -1;
                          }
                        case -1 :
                          
                          if (e/*_isYieldSafe*/)return undefined;
                           else a/*Runtime*/.throwStopIteration();
                          
                      }
                      
                    }
                    
                  };
              return a/*Runtime*/.createGenerator(e/*_mochaGenerator*/,
              function () {
                b/*_yieldState*/ = -1;
              },this);
            }
            d/*generator*/ = e/*yieldTest2*/();
          },
          case2 : function () {
            function b/*yieldTest3*/() {
              var d/*_mochaIsNewBorn*/ = true;
              
              var f/*_yieldResult*/ = undefined;
              
              var b/*_yieldState*/ = 0;
              
              var c/*i*/;
              
              var e/*_mochaGenerator*/ = function (f/*_isYieldSend*/,e/*_isYieldSafe*/) {
                    if (!f/*_isYieldSend*/){
                      
                      d/*_mochaIsNewBorn*/ = false;
                    } else if (f/*_isYieldSend*/ && d/*_mochaIsNewBorn*/ && arguments[1] !== undefined){
                      
                      a/*Runtime*/.exceptionHandler('attempt to send to newborn generator.');
                    }
                    
                    while (1){
                      switch (b/*_yieldState*/) {
                        case 0 :
                          
                          c/*i*/ = 0;
                          
                          if (!(c/*i*/<10)){
                            
                            b/*_yieldState*/ = -1;
                            break;
                          }
                        case 1 :
                          
                          if (c/*i*/%2 === 0){
                            
                            b/*_yieldState*/ = 2;
                            break;
                          } else {
                            
                            b/*_yieldState*/ = 3;
                            break;
                          }
                        case 2 :
                          
                          b/*_yieldState*/ = 3;
                          return c/*i*/;
                        case 3 :
                          
                          b/*_yieldState*/ = 4;
                          break;
                        case 4 :
                          
                          c/*i*/ ++ ;
                          
                          if (c/*i*/<10){
                            
                            b/*_yieldState*/ = 1;
                            break;
                          } else {
                            
                            b/*_yieldState*/ = -1;
                          }
                        case -1 :
                          
                          if (e/*_isYieldSafe*/)return undefined;
                           else a/*Runtime*/.throwStopIteration();
                          
                      }
                      
                    }
                    
                  };
              return a/*Runtime*/.createGenerator(e/*_mochaGenerator*/,
              function () {
                b/*_yieldState*/ = -1;
              },this);
            }
            d/*generator*/ = b/*yieldTest3*/();
          },
          case3 : function () {
            function b/*yieldTest4*/() {
              var e/*_mochaIsNewBorn*/ = true;
              
              var g/*_yieldResult*/ = undefined;
              
              var c/*_yieldState*/ = 0;
              
              var b/*j*/;
              
              var d/*i*/;
              
              var f/*_mochaGenerator*/ = function (g/*_isYieldSend*/,f/*_isYieldSafe*/) {
                    if (!g/*_isYieldSend*/){
                      
                      e/*_mochaIsNewBorn*/ = false;
                    } else if (g/*_isYieldSend*/ && e/*_mochaIsNewBorn*/ && arguments[1] !== undefined){
                      
                      a/*Runtime*/.exceptionHandler('attempt to send to newborn generator.');
                    }
                    
                    while (1){
                      switch (c/*_yieldState*/) {
                        case 0 :
                          
                          d/*i*/ = 0;
                          
                          if (!(d/*i*/<10)){
                            
                            c/*_yieldState*/ = -1;
                            break;
                          }
                        case 1 :
                          
                          b/*j*/ = 0;
                          
                          if (!(b/*j*/<10)){
                            
                            c/*_yieldState*/ = 6;
                            break;
                          }
                        case 2 :
                          
                          if (b/*j*/%2 === 0){
                            
                            c/*_yieldState*/ = 3;
                            break;
                          } else {
                            
                            c/*_yieldState*/ = 4;
                            break;
                          }
                        case 3 :
                          
                          c/*_yieldState*/ = 4;
                          return b/*j*/;
                        case 4 :
                          
                          c/*_yieldState*/ = 5;
                          break;
                        case 5 :
                          
                          b/*j*/ ++ ;
                          
                          if (b/*j*/<10){
                            
                            c/*_yieldState*/ = 2;
                            break;
                          } else {
                            
                            c/*_yieldState*/ = 6;
                          }
                        case 6 :
                          
                          d/*i*/ ++ ;
                          
                          if (d/*i*/<10){
                            
                            c/*_yieldState*/ = 1;
                            break;
                          } else {
                            
                            c/*_yieldState*/ = -1;
                          }
                        case -1 :
                          
                          if (f/*_isYieldSafe*/)return undefined;
                           else a/*Runtime*/.throwStopIteration();
                          
                      }
                      
                    }
                    
                  };
              return a/*Runtime*/.createGenerator(f/*_mochaGenerator*/,
              function () {
                c/*_yieldState*/ = -1;
              },this);
            }
            d/*generator*/ = b/*yieldTest4*/();
          },
          case4 : function () {
            function b/*yieldTest5*/() {
              var d/*_mochaIsNewBorn*/ = true;
              
              var f/*_yieldResult*/ = undefined;
              
              var b/*_yieldState*/ = 0;
              
              var c/*i*/;
              
              var e/*_mochaGenerator*/ = function (f/*_isYieldSend*/,e/*_isYieldSafe*/) {
                    if (!f/*_isYieldSend*/){
                      
                      d/*_mochaIsNewBorn*/ = false;
                    } else if (f/*_isYieldSend*/ && d/*_mochaIsNewBorn*/ && arguments[1] !== undefined){
                      
                      a/*Runtime*/.exceptionHandler('attempt to send to newborn generator.');
                    }
                    
                    while (1){
                      switch (b/*_yieldState*/) {
                        case 0 :
                          
                          c/*i*/ = 0;
                          
                          if (!( ++ c/*i*/<10)){
                            
                            b/*_yieldState*/ = -1;
                            break;
                          }
                        case 1 :
                          
                          b/*_yieldState*/ = 2;
                          return c/*i*/;
                        case 2 :
                          
                          if ( ++ c/*i*/<10){
                            
                            b/*_yieldState*/ = 1;
                            break;
                          } else {
                            
                            b/*_yieldState*/ = -1;
                          }
                        case -1 :
                          
                          if (e/*_isYieldSafe*/)return undefined;
                           else a/*Runtime*/.throwStopIteration();
                          
                      }
                      
                    }
                    
                  };
              return a/*Runtime*/.createGenerator(e/*_mochaGenerator*/,
              function () {
                b/*_yieldState*/ = -1;
              },this);
            }
            d/*generator*/ = b/*yieldTest5*/();
          },
          case5 : function () {
            function b/*yieldTest6*/() {
              var d/*_mochaIsNewBorn*/ = true;
              
              var f/*_yieldResult*/ = undefined;
              
              var b/*_yieldState*/ = 0;
              
              var c/*i*/;
              
              var e/*_mochaGenerator*/ = function (f/*_isYieldSend*/,e/*_isYieldSafe*/) {
                    if (!f/*_isYieldSend*/){
                      
                      d/*_mochaIsNewBorn*/ = false;
                    } else if (f/*_isYieldSend*/ && d/*_mochaIsNewBorn*/ && arguments[1] !== undefined){
                      
                      a/*Runtime*/.exceptionHandler('attempt to send to newborn generator.');
                    }
                    
                    while (1){
                      switch (b/*_yieldState*/) {
                        case 0 :
                          
                          c/*i*/ = 0;
                        case 1 :
                          
                          b/*_yieldState*/ = 2;
                          return c/*i*/;
                        case 2 :
                          
                          if ( ++ c/*i*/<10){
                            
                            b/*_yieldState*/ = 1;
                            break;
                          } else {
                            
                            b/*_yieldState*/ = 3;
                          }
                        case 3 :
                        case -1 :
                          
                          if (e/*_isYieldSafe*/)return undefined;
                           else a/*Runtime*/.throwStopIteration();
                          
                      }
                      
                    }
                    
                  };
              return a/*Runtime*/.createGenerator(e/*_mochaGenerator*/,
              function () {
                b/*_yieldState*/ = -1;
              },this);
            }
            d/*generator*/ = b/*yieldTest6*/();
          },
          case6 : function () {
            function b/*yieldTest7*/() {
              var f/*_mochaIsNewBorn*/ = true;
              
              var e/*_yieldResult*/ = undefined;
              
              var c/*_yieldState*/ = 0;
              
              var d/*i*/;
              
              var b/*m*/;
              
              var g/*_mochaGenerator*/ = function (h/*_isYieldSend*/,g/*_isYieldSafe*/) {
                    if (!h/*_isYieldSend*/){
                      
                      f/*_mochaIsNewBorn*/ = false;
                    } else if (h/*_isYieldSend*/ && f/*_mochaIsNewBorn*/ && arguments[1] !== undefined){
                      
                      a/*Runtime*/.exceptionHandler('attempt to send to newborn generator.');
                    }
                    
                    while (1){
                      switch (c/*_yieldState*/) {
                        case 0 :
                          
                          d/*i*/ = 0;
                          
                          if (!(d/*i*/<10)){
                            
                            c/*_yieldState*/ = -1;
                            break;
                          }
                        case 1 :
                          
                          c/*_yieldState*/ = 2;
                          return d/*i*/;
                        case 2 :
                          
                          e/*_yieldResult*/ = h/*_isYieldSend*/ && arguments.length>2?a/*Runtime*/.toArray(arguments,2)[0] : h/*_isYieldSend*/?d/*i*/ : undefined;
                          
                          b/*m*/ = e/*_yieldResult*/;
                          
                          if (b/*m*/ === true){
                            
                            c/*_yieldState*/ = 3;
                            break;
                          } else {
                            
                            c/*_yieldState*/ = 5;
                            break;
                          }
                        case 3 :
                          
                          c/*_yieldState*/ = 4;
                          return d/*i*/+1;
                        case 4 :
                          
                          c/*_yieldState*/ = 9;
                          break;
                        case 5 :
                          
                          if (b/*m*/ === false){
                            
                            c/*_yieldState*/ = 6;
                            break;
                          } else {
                            
                            c/*_yieldState*/ = 8;
                            break;
                          }
                        case 6 :
                          
                          c/*_yieldState*/ = 7;
                          return d/*i*/-1;
                        case 7 :
                          
                          c/*_yieldState*/ = 9;
                          break;
                        case 8 :
                          
                          c/*_yieldState*/ = 9;
                          return d/*i*/;
                        case 9 :
                          
                          d/*i*/ ++ ;
                          
                          if (d/*i*/<10){
                            
                            c/*_yieldState*/ = 1;
                            break;
                          } else {
                            
                            c/*_yieldState*/ = -1;
                          }
                        case -1 :
                          
                          if (g/*_isYieldSafe*/)return undefined;
                           else a/*Runtime*/.throwStopIteration();
                          
                      }
                      
                    }
                    
                  };
              return a/*Runtime*/.createGenerator(g/*_mochaGenerator*/,
              function () {
                c/*_yieldState*/ = -1;
              },this);
            }
            d/*generator*/ = b/*yieldTest7*/();
          },
          case7 : function () {
            function b/*yieldTest8*/() {
              var g/*_mochaIsNewBorn*/ = true;
              
              var f/*_yieldResult*/ = undefined;
              
              var d/*_yieldState*/ = 0;
              
              var b/*j*/;
              
              var e/*i*/;
              
              var c/*m*/;
              
              var h/*_mochaGenerator*/ = function (i/*_isYieldSend*/,h/*_isYieldSafe*/) {
                    if (!i/*_isYieldSend*/){
                      
                      g/*_mochaIsNewBorn*/ = false;
                    } else if (i/*_isYieldSend*/ && g/*_mochaIsNewBorn*/ && arguments[1] !== undefined){
                      
                      a/*Runtime*/.exceptionHandler('attempt to send to newborn generator.');
                    }
                    
                    while (1){
                      switch (d/*_yieldState*/) {
                        case 0 :
                          
                          e/*i*/ = 0;
                          
                          if (!(e/*i*/<10)){
                            
                            d/*_yieldState*/ = -1;
                            break;
                          }
                        case 1 :
                          
                          d/*_yieldState*/ = 2;
                          return e/*i*/;
                        case 2 :
                          
                          f/*_yieldResult*/ = i/*_isYieldSend*/ && arguments.length>2?a/*Runtime*/.toArray(arguments,2)[0] : i/*_isYieldSend*/?e/*i*/ : undefined;
                          
                          c/*m*/ = f/*_yieldResult*/;
                          
                          b/*j*/ = 0;
                          
                          if (!(b/*j*/<10)){
                            
                            d/*_yieldState*/ = 11;
                            break;
                          }
                        case 3 :
                          
                          if (c/*m*/ === true){
                            
                            d/*_yieldState*/ = 4;
                            break;
                          } else {
                            
                            d/*_yieldState*/ = 6;
                            break;
                          }
                        case 4 :
                          
                          d/*_yieldState*/ = 5;
                          return b/*j*/*2;
                        case 5 :
                          
                          d/*_yieldState*/ = 10;
                          break;
                        case 6 :
                          
                          if (c/*m*/ === false){
                            
                            d/*_yieldState*/ = 7;
                            break;
                          } else {
                            
                            d/*_yieldState*/ = 9;
                            break;
                          }
                        case 7 :
                          
                          d/*_yieldState*/ = 8;
                          return b/*j*//2;
                        case 8 :
                          
                          d/*_yieldState*/ = 10;
                          break;
                        case 9 :
                          
                          d/*_yieldState*/ = 10;
                          return b/*j*/;
                        case 10 :
                          
                          b/*j*/ ++ ;
                          
                          if (b/*j*/<10){
                            
                            d/*_yieldState*/ = 3;
                            break;
                          } else {
                            
                            d/*_yieldState*/ = 11;
                          }
                        case 11 :
                          
                          e/*i*/ ++ ;
                          
                          if (e/*i*/<10){
                            
                            d/*_yieldState*/ = 1;
                            break;
                          } else {
                            
                            d/*_yieldState*/ = -1;
                          }
                        case -1 :
                          
                          if (h/*_isYieldSafe*/)return undefined;
                           else a/*Runtime*/.throwStopIteration();
                          
                      }
                      
                    }
                    
                  };
              return a/*Runtime*/.createGenerator(h/*_mochaGenerator*/,
              function () {
                d/*_yieldState*/ = -1;
              },this);
            }
            d/*generator*/ = b/*yieldTest8*/();
          },
          case8 : function () {
            function b/*yieldTest9*/() {
              var g/*_mochaIsNewBorn*/ = true;
              
              var f/*_yieldResult*/ = undefined;
              
              var d/*_yieldState*/ = 0;
              
              var b/*j*/;
              
              var e/*i*/;
              
              var c/*m*/;
              
              var h/*_mochaGenerator*/ = function (i/*_isYieldSend*/,h/*_isYieldSafe*/) {
                    if (!i/*_isYieldSend*/){
                      
                      g/*_mochaIsNewBorn*/ = false;
                    } else if (i/*_isYieldSend*/ && g/*_mochaIsNewBorn*/ && arguments[1] !== undefined){
                      
                      a/*Runtime*/.exceptionHandler('attempt to send to newborn generator.');
                    }
                    
                    while (1){
                      switch (d/*_yieldState*/) {
                        case 0 :
                          
                          e/*i*/ = 0;
                          
                          if (!(e/*i*/<10)){
                            
                            d/*_yieldState*/ = -1;
                            break;
                          }
                        case 1 :
                          
                          b/*j*/ = 0;
                          
                          if (!(b/*j*/<10)){
                            
                            d/*_yieldState*/ = 11;
                            break;
                          }
                        case 2 :
                          
                          d/*_yieldState*/ = 3;
                          return e/*i*/;
                        case 3 :
                          
                          f/*_yieldResult*/ = i/*_isYieldSend*/ && arguments.length>2?a/*Runtime*/.toArray(arguments,2)[0] : i/*_isYieldSend*/?e/*i*/ : undefined;
                          
                          c/*m*/ = f/*_yieldResult*/;
                          
                          if (c/*m*/ === true){
                            
                            d/*_yieldState*/ = 4;
                            break;
                          } else {
                            
                            d/*_yieldState*/ = 6;
                            break;
                          }
                        case 4 :
                          
                          d/*_yieldState*/ = 5;
                          return b/*j*/*2;
                        case 5 :
                          
                          d/*_yieldState*/ = 10;
                          break;
                        case 6 :
                          
                          if (c/*m*/ === false){
                            
                            d/*_yieldState*/ = 7;
                            break;
                          } else {
                            
                            d/*_yieldState*/ = 9;
                            break;
                          }
                        case 7 :
                          
                          d/*_yieldState*/ = 8;
                          return b/*j*//2;
                        case 8 :
                          
                          d/*_yieldState*/ = 10;
                          break;
                        case 9 :
                          
                          d/*_yieldState*/ = 10;
                          return b/*j*/;
                        case 10 :
                          
                          b/*j*/ ++ ;
                          
                          if (b/*j*/<10){
                            
                            d/*_yieldState*/ = 2;
                            break;
                          } else {
                            
                            d/*_yieldState*/ = 11;
                          }
                        case 11 :
                          
                          e/*i*/ ++ ;
                          
                          if (e/*i*/<10){
                            
                            d/*_yieldState*/ = 1;
                            break;
                          } else {
                            
                            d/*_yieldState*/ = -1;
                          }
                        case -1 :
                          
                          if (h/*_isYieldSafe*/)return undefined;
                           else a/*Runtime*/.throwStopIteration();
                          
                      }
                      
                    }
                    
                  };
              return a/*Runtime*/.createGenerator(h/*_mochaGenerator*/,
              function () {
                d/*_yieldState*/ = -1;
              },this);
            }
            d/*generator*/ = b/*yieldTest9*/();
          },
          case9 : function () {
            function b/*yieldTest10*/() {
              var c/*_mochaIsNewBorn*/ = true;
              
              var j/*_yieldResult*/ = undefined;
              
              var f/*_yieldState*/ = 0;
              
              var b/*_mochaFinallyCache*/;
              
              var e/*_mochaCatchCache*/;
              
              var h/*i*/;
              
              var d/*m*/;
              
              var g/*flg*/;
              
              var i/*_mochaGenerator*/ = function (k/*_isYieldSend*/,j/*_isYieldSafe*/) {
                    if (!k/*_isYieldSend*/){
                      
                      c/*_mochaIsNewBorn*/ = false;
                    } else if (k/*_isYieldSend*/ && c/*_mochaIsNewBorn*/ && arguments[1] !== undefined){
                      
                      a/*Runtime*/.exceptionHandler('attempt to send to newborn generator.');
                    }
                    
                    while (1)try {
                      switch (f/*_yieldState*/) {
                        case 0 :
                          
                          g/*flg*/ = false;
                          
                          h/*i*/ = 0;
                          
                          if (!(h/*i*/<10)){
                            
                            f/*_yieldState*/ = -1;
                            break;
                          }
                        case 1 :
                          
                          f/*_yieldState*/ = 2;
                          
                          e/*_mochaCatchCache*/ = function (a/*e*/) {
                            f/*_yieldState*/ = 3;
                          };
                          
                          b/*_mochaFinallyCache*/ = function () {
                            g/*flg*/ = true
                          };
                          
                          d/*m*/ = (g/*flg*/)?1 : 0;
                          return d/*m*/;
                        case 2 :
                          
                          ddddd();
                          
                          e/*_mochaCatchCache*/ = undefined;
                          
                          b/*_mochaFinallyCache*/ = undefined;
                        case 3 :
                          
                          h/*i*/ ++ ;
                          
                          if (h/*i*/<10){
                            
                            f/*_yieldState*/ = 1;
                            break;
                          } else {
                            
                            f/*_yieldState*/ = -1;
                          }
                        case -1 :
                          
                          if (j/*_isYieldSafe*/)return undefined;
                           else a/*Runtime*/.throwStopIteration();
                          
                      }
                      
                    } catch(_mochaException){
                      if (e/*_mochaCatchCache*/){
                        
                        var i/*_mochaLocalTmp0*/ = e/*_mochaCatchCache*/(_mochaException);
                        
                        if (i/*_mochaLocalTmp0*/ !== undefined){
                          return i/*_mochaLocalTmp0*/;
                        }
                        
                      } else a/*Runtime*/.throwException(_mochaException);
                    } finally {
                      if (b/*_mochaFinallyCache*/){
                        
                        var _mochaLocalTmp1 = b/*_mochaFinallyCache*/();
                        
                        if (_mochaLocalTmp1 !== undefined){
                          return _mochaLocalTmp1;
                        }
                        
                      }
                      
                    }
                    
                  };
              return a/*Runtime*/.createGenerator(i/*_mochaGenerator*/,
              function () {
                f/*_yieldState*/ = -1;
                
                if (b/*_mochaFinallyCache*/)b/*_mochaFinallyCache*/();
              },this);
            }
            d/*generator*/ = b/*yieldTest10*/();
          },
          case10 : function () {
            function b/*yieldTest11*/() {
              var f/*_mochaIsNewBorn*/ = true;
              
              var d/*_yieldResult*/ = undefined;
              
              var b/*_yieldState*/ = 0;
              
              var c/*i*/;
              
              var e/*type*/;
              
              var g/*_mochaGenerator*/ = function (h/*_isYieldSend*/,g/*_isYieldSafe*/) {
                    if (!h/*_isYieldSend*/){
                      
                      f/*_mochaIsNewBorn*/ = false;
                    } else if (h/*_isYieldSend*/ && f/*_mochaIsNewBorn*/ && arguments[1] !== undefined){
                      
                      a/*Runtime*/.exceptionHandler('attempt to send to newborn generator.');
                    }
                    
                    while (1){
                      switch (b/*_yieldState*/) {
                        case 0 :
                          
                          c/*i*/ = 0;
                          
                          if (!(c/*i*/<10)){
                            
                            b/*_yieldState*/ = -1;
                            break;
                          }
                        case 1 :
                          
                          b/*_yieldState*/ = 2;
                          return ;
                        case 2 :
                          
                          d/*_yieldResult*/ = h/*_isYieldSend*/ && arguments.length>2?a/*Runtime*/.toArray(arguments,2)[0] : undefined;
                          
                          e/*type*/ = d/*_yieldResult*/;
                          
                          switch (e/*type*/) {
                            case 0 :
                              
                              b/*_yieldState*/ = 3;
                              break;
                            case 2 :
                              
                              b/*_yieldState*/ = 4;
                              break;
                            case 3 :
                              
                              b/*_yieldState*/ = 5;
                              break;
                            default :
                              
                              b/*_yieldState*/ = 6;
                              break;
                              
                          }
                          break;
                        case 3 :
                          
                          b/*_yieldState*/ = 7;
                          return 200;
                        case 4 :
                          
                          b/*_yieldState*/ = 7;
                          return 400;
                        case 5 :
                          
                          b/*_yieldState*/ = 7;
                          return 600;
                        case 6 :
                          
                          b/*_yieldState*/ = 7;
                          return 700;
                        case 7 :
                          
                          c/*i*/ ++ ;
                          
                          if (c/*i*/<10){
                            
                            b/*_yieldState*/ = 1;
                            break;
                          } else {
                            
                            b/*_yieldState*/ = -1;
                          }
                        case -1 :
                          
                          if (g/*_isYieldSafe*/)return undefined;
                           else a/*Runtime*/.throwStopIteration();
                          
                      }
                      
                    }
                    
                  };
              return a/*Runtime*/.createGenerator(g/*_mochaGenerator*/,
              function () {
                b/*_yieldState*/ = -1;
              },this);
            }
            d/*generator*/ = b/*yieldTest11*/();
            
            d/*generator*/.next();
            
            d/*generator*/.next();
            
            d/*generator*/.next();
            
            d/*generator*/.next();
          },
          case11 : function () {
            function b/*yieldTest12*/() {
              var f/*_mochaIsNewBorn*/ = true;
              
              var d/*_yieldResult*/ = undefined;
              
              var b/*_yieldState*/ = 0;
              
              var c/*i*/;
              
              var e/*type*/;
              
              var g/*_mochaGenerator*/ = function (h/*_isYieldSend*/,g/*_isYieldSafe*/) {
                    if (!h/*_isYieldSend*/){
                      
                      f/*_mochaIsNewBorn*/ = false;
                    } else if (h/*_isYieldSend*/ && f/*_mochaIsNewBorn*/ && arguments[1] !== undefined){
                      
                      a/*Runtime*/.exceptionHandler('attempt to send to newborn generator.');
                    }
                    
                    while (1){
                      switch (b/*_yieldState*/) {
                        case 0 :
                          
                          c/*i*/ = 0;
                          
                          if (!(c/*i*/<15)){
                            
                            b/*_yieldState*/ = -1;
                            break;
                          }
                        case 1 :
                          
                          b/*_yieldState*/ = 2;
                          return ;
                        case 2 :
                          
                          d/*_yieldResult*/ = h/*_isYieldSend*/ && arguments.length>2?a/*Runtime*/.toArray(arguments,2)[0] : undefined;
                          
                          e/*type*/ = d/*_yieldResult*/;
                          
                          switch (e/*type*/) {
                            case 4 :
                            case 0 :
                              
                              b/*_yieldState*/ = 3;
                              break;
                            case 5 :
                              
                              b/*_yieldState*/ = 7;
                              break;
                            case 6 :
                            case 2 :
                              
                              b/*_yieldState*/ = 4;
                              break;
                            case 3 :
                              
                              b/*_yieldState*/ = 5;
                              break;
                            default :
                              
                              b/*_yieldState*/ = 6;
                              break;
                              
                          }
                          break;
                        case 3 :
                          
                          b/*_yieldState*/ = 8;
                          return 200;
                        case 4 :
                          
                          b/*_yieldState*/ = 8;
                          return 400;
                        case 5 :
                          
                          b/*_yieldState*/ = 8;
                          return 600;
                        case 6 :
                          
                          b/*_yieldState*/ = 8;
                          return 700;
                        case 7 :
                          
                          b/*_yieldState*/ = 8;
                          break;
                        case 8 :
                          
                          c/*i*/ ++ ;
                          
                          if (c/*i*/<15){
                            
                            b/*_yieldState*/ = 1;
                            break;
                          } else {
                            
                            b/*_yieldState*/ = -1;
                          }
                        case -1 :
                          
                          if (g/*_isYieldSafe*/)return undefined;
                           else a/*Runtime*/.throwStopIteration();
                          
                      }
                      
                    }
                    
                  };
              return a/*Runtime*/.createGenerator(g/*_mochaGenerator*/,
              function () {
                b/*_yieldState*/ = -1;
              },this);
            }
            d/*generator*/ = b/*yieldTest12*/();
            
            d/*generator*/.next();
            
            d/*generator*/.next();
            
            d/*generator*/.next();
            
            d/*generator*/.next();
            
            d/*generator*/.next();
          },
          case12 : function () {
            function e/*yieldTest13*/() {
              var h/*_mochaIsNewBorn*/ = true;
              
              var j/*_yieldResult*/ = undefined;
              
              var d/*_yieldState*/ = 0;
              
              var b/*length*/;
              
              var g/*_mochaLocalTmp4*/;
              
              var e/*i*/;
              
              var f/*obj*/;
              
              var c/*_mochaLocalTmp3*/ = [];
              
              var i/*_mochaGenerator*/ = function (k/*_isYieldSend*/,j/*_isYieldSafe*/) {
                    if (!k/*_isYieldSend*/){
                      
                      h/*_mochaIsNewBorn*/ = false;
                    } else if (k/*_isYieldSend*/ && h/*_mochaIsNewBorn*/ && arguments[1] !== undefined){
                      
                      a/*Runtime*/.exceptionHandler('attempt to send to newborn generator.');
                    }
                    
                    while (1){
                      switch (d/*_yieldState*/) {
                        case 0 :
                          
                          f/*obj*/ =  {
                            x : 200,
                            y : 300,
                            z : 400
                          };
                          
                          for (var i/*_mochaLocalTmp2*/ in f/*obj*/)
                          c/*_mochaLocalTmp3*/.push(i/*_mochaLocalTmp2*/);
                          
                          g/*_mochaLocalTmp4*/ = 0;
                          
                          b/*length*/ = c/*_mochaLocalTmp3*/.length;
                          
                          if (!(g/*_mochaLocalTmp4*/<b/*length*/)){
                            
                            d/*_yieldState*/ = -1;
                            break;
                          }
                        case 1 :
                          
                          d/*_yieldState*/ = 2;
                          
                          e/*i*/ = c/*_mochaLocalTmp3*/[g/*_mochaLocalTmp4*/];
                          return [e/*i*/,f/*obj*/[e/*i*/]];
                        case 2 :
                          
                           ++ g/*_mochaLocalTmp4*/;
                          
                          if (g/*_mochaLocalTmp4*/<b/*length*/){
                            
                            d/*_yieldState*/ = 1;
                            break;
                          } else {
                            
                            d/*_yieldState*/ = -1;
                          }
                        case -1 :
                          
                          if (j/*_isYieldSafe*/)return undefined;
                           else a/*Runtime*/.throwStopIteration();
                          
                      }
                      
                    }
                    
                  };
              return a/*Runtime*/.createGenerator(i/*_mochaGenerator*/,
              function () {
                d/*_yieldState*/ = -1;
              },this);
            }
            d/*generator*/ = e/*yieldTest13*/();
            
            var b/*ret*/ = d/*generator*/.next();
            
            b/*ret*/ = d/*generator*/.next();
            
            b/*ret*/ = d/*generator*/.next();
          },
          case13 : function () {
            function d/*keys*/(g/*obj*/) {
              var h/*_mochaIsNewBorn*/ = true;
              
              var j/*_yieldResult*/ = undefined;
              
              var d/*_yieldState*/ = 0;
              
              var c/*length*/;
              
              var e/*_mochaLocalTmp7*/;
              
              var b/*prop*/;
              
              var f/*_mochaLocalTmp6*/ = [];
              
              var i/*_mochaGenerator*/ = function (k/*_isYieldSend*/,j/*_isYieldSafe*/) {
                    if (!k/*_isYieldSend*/){
                      
                      h/*_mochaIsNewBorn*/ = false;
                    } else if (k/*_isYieldSend*/ && h/*_mochaIsNewBorn*/ && arguments[1] !== undefined){
                      
                      a/*Runtime*/.exceptionHandler('attempt to send to newborn generator.');
                    }
                    
                    while (1){
                      switch (d/*_yieldState*/) {
                        case 0 :
                          
                          for (var i/*_mochaLocalTmp5*/ in g/*obj*/)
                          f/*_mochaLocalTmp6*/.push(i/*_mochaLocalTmp5*/);
                          
                          e/*_mochaLocalTmp7*/ = 0;
                          
                          c/*length*/ = f/*_mochaLocalTmp6*/.length;
                          
                          if (!(e/*_mochaLocalTmp7*/<c/*length*/)){
                            
                            d/*_yieldState*/ = -1;
                            break;
                          }
                        case 1 :
                          
                          b/*prop*/ = f/*_mochaLocalTmp6*/[e/*_mochaLocalTmp7*/];
                          
                          if (g/*obj*/.hasOwnProperty(b/*prop*/)){
                            
                            d/*_yieldState*/ = 2;
                            break;
                          } else {
                            
                            d/*_yieldState*/ = 3;
                            break;
                          }
                        case 2 :
                          
                          d/*_yieldState*/ = 3;
                          return b/*prop*/;
                        case 3 :
                          
                          d/*_yieldState*/ = 4;
                          break;
                        case 4 :
                          
                           ++ e/*_mochaLocalTmp7*/;
                          
                          if (e/*_mochaLocalTmp7*/<c/*length*/){
                            
                            d/*_yieldState*/ = 1;
                            break;
                          } else {
                            
                            d/*_yieldState*/ = -1;
                          }
                        case -1 :
                          
                          if (j/*_isYieldSafe*/)return undefined;
                           else a/*Runtime*/.throwStopIteration();
                          
                      }
                      
                    }
                    
                  };
              return a/*Runtime*/.createGenerator(i/*_mochaGenerator*/,
              function () {
                d/*_yieldState*/ = -1;
              },this);
            }
            var c/*testObject*/ =  {
                  value1 : 1,
                  value2 : 2,
                  value3 : 3,
                  value4 : 4
                };
            
            try {
              
              var b/*itemGen*/ = d/*keys*/(c/*testObject*/);
            } catch(e){
              
            }
            
          }
        };
    
    for (var c/*i*/ = 1;c/*i*/<13;c/*i*/ ++ )
    e/*tests*/["case"+c/*i*/]();
  }();
}();
