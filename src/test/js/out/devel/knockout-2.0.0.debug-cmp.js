!function() {
  
  var c = {},
      b = (this !== null)?this : typeof window === 'object'?window : {};
  
  !function () {
    !function (n,m,j,i) {
      function g(c,b,a) {
        return Object.defineProperty(c,b, {
          value : a,
          configurable : true,
          enumerable : false,
          writable : true
        });
      }
      function f(e,d) {
        
        typeof e !== "function" && c(d+" : first argument is not callable");
      }
      function c(a) {
        try {
          throw new TypeError(a);
        } catch(e){
          throw new Error(e);
        }
        
      }
      var d = n.prototype,
          e = m.prototype,
          k = j.prototype,
          h = i.prototype;
      
      !Object.keys && (Object.keys = function (e) {
        !e && c("Object.keys : first arguments is null or not defined.");
        
        var d = [],
            a = -1;
        
        for (var b in e)
        e.hasOwnProperty(b) && (d[ ++ a] = e[b]);
        return d;
      });
      
      !Object.preventExtensions && (Object.preventExtensions = function (a) {
        return a;
      });
      
      !Object.seal && (Object.seal = function (a) {
        return a;
      });
      
      !Object.freeze && (Object.freeze = function (a) {
        return a;
      });
      
      var l = function () {
            var b;
            
            try {
              
              var a = {};
              
              Object.defineProperty(a,"test", {
                configurable : false,
                writable : false,
                enumerable : false,
                value : 0
              });
              
              a.test = 200;
              
              b = (a.test === 200)?false : true;
            } catch(e){
              
              b = false;
            }
            return b;
          }();
      
      !l && (Object.defineProperty = function (c,b,a) {
        "value" in a && (c[b] = a.value);
      });
      
      if (!d.trim){
        
        d.trim = function () {
          return this.replace(d.trim.rtrim,"");
        };
        
        d.trim.rtrim = /^\s*|\s*$/g;
      }
      
      !d.repeat && g(d,"repeat",
      function (a) {
        return Array(a+1).join(this.toString());
      });
      
      !d.startsWith && g(d,"startsWith",
      function (a) {
        return !this.indexOf(a);
      });
      
      !d.endsWith && g(d,"endsWith",
      function (c) {
        var b = String(c),
            a = this.lastIndexOf(b);
        return a >= 0 && a === this.length-b.length;
      });
      
      !d.contains && g(d,"contains",
      function (a) {
        return this.indexOf(a) !== -1;
      });
      
      !d.toArray && g(d,"toArray",
      function (a) {
        return this.split("");
      });
      
      !k.bind && g(k,"bind",
      function () {
        var d = e.slice.call(arguments),
            a = d.shift(),
            c = function () {
              var f = d.concat(e.slice.call(arguments));
              return this !== null && this !== b && this instanceof c?c.context.apply(this,f) : c.context.apply(a,f);
            };
        
        c.prototype = this.prototype;
        
        c.context = this;
        return c;
      });
      
      !e.forEach && g(e,"forEach",
      function (j,i) {
        f(j,"Array.forEach");
        
        var g = -1,
            h;
        
        this === null && c("Array.forEach : this is null or not defined");
        
        if (i)while ((h = this[ ++ g]) !== null && h !== undefined)j.call(i,h,g,this);
         else while ((h = this[ ++ g]) !== null && h !== undefined)j(h,g,this);
      });
      
      !e.every && g(e,"every",
      function (e,d) {
        f(e,"Array.every");
        
        var a = -1,
            b;
        
        this === null && c("Array.every : this is null or not defined");
        
        if (d)while ((b = this[ ++ a]) !== null && b !== undefined)if (!(e.call(d,b,a,this)))return false;
         else while ((b = this[ ++ a]) !== null && b !== undefined)if (!(e(b,a,this)))return false;
        return true;
      });
      
      !e.some && g(e,"some",
      function (e,d) {
        f(e,"Array.some");
        
        var a = -1,
            b;
        
        this === null && c("Array.some : this is null or not defined");
        
        if (d)while ((b = this[ ++ a]) !== null && b !== undefined)if (e.call(d,b,a,this))return true;
         else while ((b = this[ ++ a]) !== null && b !== undefined)if (e(b,a,this))return true;
        return false;
      });
      
      !e.filter && g(e,"filter",
      function (i,h) {
        f(i,"Array.filter");
        
        var e = this.length,
            d = -1,
            b = [],
            g;
        
        this === null && c("Array.filter : this is null or not defined");
        
        if (h)for (var a = 0,e = this.length;a<e; ++ a)
        (g = this[a]) !== null && g !== undefined && i.call(h,g,a,this) && (b[ ++ d] = g);
         else for (var a = 0,e = this.length;a<e; ++ a)
        (g = this[a]) !== null && g !== undefined && i(g,a,this) && (b[ ++ d] = g);
        return b;
      });
      
      !e.indexOf && g(e,"indexOf",
      function (f,b) {
        var a = (b)?b-1 : -1,
            e = -1,
            d;
        
        this === null && c("Array.indexOf : this is null or not defined.");
        
        while ((d = this[ ++ a]) !== null && d !== undefined)if (d === f){
          
          e = a;
          break;
        }
        return e;
      });
      
      !e.lastIndexOf && g(e,"lastIndexOf",
      function (g,e) {
        var f = this.length,
            d = (e)?e+1 : f,
            b = -1,
            a;
        
        this === null && c("Array.lastIndexOf : this is null or not defined.");
        
        while ((a = this[ -- d]) !== null && a !== undefined)if (a === g){
          
          b = d;
          break;
        }
        return b;
      });
      
      !e.map && g(e,"map",
      function (i,h) {
        f(i,"Array.map");
        
        var e = [],
            b = -1,
            a = this.length,
            d = 0,
            g;
        
        this === null && c("Array.map : this is null or not defined.");
        
        if (h)for (d;d<a; ++ d)(g = this[d]) !== null && g !== undefined && (e[ ++ b] = i.call(h,g,d,this));
         else for (d;d<a; ++ d)(g = this[d]) !== null && g !== undefined && (e[ ++ b] = i(g,d,this));
        return e;
      });
      
      !e.reduce && g(e,"reduce",
      function (h,g) {
        f(h,"Array.reduce");
        
        var e = g || this[0],
            d = (g)?0 : 1,
            b = this.length,
            a;
        
        (b === 0 || b === null) && arguments.length<2 && c("Array length is 0 and no second argument");
        
        for (d;d<b; ++ d)(a = this[d]) !== null && a !== undefined && (e = h(e,a,d,this));
        return e;
      });
      
      !e.reduceRight && g(e,"reduceRight",
      function (h,g) {
        f(h,"Array.reduceRight");
        
        var e = this.length,
            d = g || this[e-1],
            b = (g)?e-1 : e-2,
            a;
        
        (e === 0 || e === null) && arguments.length<2 && c("Array length is 0 and no second argument");
        
        for (b;b>-1; -- b)(a = this[b]) !== null && a !== undefined && (d = h(d,a,b,this));
        return d;
      });
      
      !h.toJSON && g(h,"toJSON",
      function () {
        var f = [this.getUTCMonth(),this.getUTCDate(),this.getUTCHours(),this.getMinutes(),this.getSeconds()],
            e = f[0],
            d = f[1],
            c = f[2],
            b = f[3],
            a = f[4];
        return '"'+this.getUTCFullYear()+'-'+(e>8?e+1 : "0"+(e+1))+'-'+(d>9?d : "0"+d)+'T'+(c>9?c : "0"+c)+':'+(b>9?b : "0"+b)+':'+(a>9?a : "0"+a)+'.'+this.getUTCMilliseconds()+'Z"';
      });
      
      !Date.now && g(Date,"now",
      function () {
        return +new Date();
      });
      
      !Array.isArray && g(Array,"isArray",
      function (a) {
        if (arguments.length === 0)return false;
        return (a)?({}).toString.call(a) === "[object Array]" : false;
      });
    }.call(this,String,Array,Function,Date);
  }.call(this);
  
  var a = function () {
        "use strict";
        function s(i,g,f,e) {
          var d = [];
          
          for (var c = 0,a = f.length;c<a;c += 2)
          f[c] === true?h.apply(d,f[c+1]) : d.push(f[c+1]);
          
          if (e){
            
            var b = function (){};
            
            b.prototype = g.prototype;
            
            b = new b;
            return g.apply(b,d);
          } else return g.apply(i,d);
        }
        function t(e,m,l,h,g) {
          var j = e.prototype,
              i = m.prototype;
          
          for (var d = 0,f = l.length;d<f;d ++ ){
            
            var c = l[d],
                b = c._mochaRequires;
            
            for (var k in b)!(k in j) && !(k in i) && a.throwException("Class dose not meet the traits requirement. traits require implementation of property "+k+"\nin file "+h+" at line "+g);
          }
          
        }
        function u(j,m,h,k,f) {
          var d = j.prototype,
              e = m.prototype,
              l = h._mochaTraitMark,
              c = h._mochaTraitPublic,
              i = h._mochaTraitPrivate;
          
          if (!l)a.throwException("mixin only used for trait.");
           else {
            
            var g;
            
            for (var b in c)if (!f[b]){
              
              g = (!k[b])?b : k[b];
              
              d[g] = c[b];
            }
            
            for (b in i)if (!f[b]){
              
              g = (!k[b])?b : k[b];
              
              e[g] = i[b];
            }
            
          }
          
        }
        function w(m,i,l,h) {
          if (!m._mochaTraitMark || !i._mochaTraitMark)a.throwException("mixin only used for trait.");
           else {
            
            var g = m._mochaTraitPrivate,
                f = i._mochaTraitPrivate,
                j = m._mochaTraitPublic,
                k = i._mochaTraitPublic,
                e = i._mochaRequires,
                d = m._mochaRequires,
                c;
            
            for (var b in f)if (!h[b]){
              
              c = (!l[b])?b : l[b];
              
              g[c] = f[b];
            }
            
            for (b in k)if (!h[b]){
              
              c = (!l[b])?b : l[b];
              
              j[c] = k[b];
            }
            
            for (b in e)d[b] = e[b];
          }
          
        }
        function v(c) {
          var a = typeof c,
              b;
          
          if (a === "function"){
            
            b = function (){};
            
            b.prototype = c.prototype;
            
            b = new b();
            
            c.__harmony_class__?b.constructor = c.constructor : b.constructor = c;
            return b;
          }
          return b;
        }
        function D(x,w,u,t,v,s,r) {
          (!x || !(x instanceof w)) && q("class "+s+" must be called by new. line : "+r);
          
          p(x,u,t);
          
          t.apply(x,v);
        }
        function d(o) {
          return o === StopIteration || n.test(o);
        }
        function K(a) {
          return m in a;
        }
        function J(p) {
          var a = p[m](),
              o;
          
          if (l(a))return a;
          
          o = {};
          
          if (a.next)f(o,"next",
          function () {
            var b = a.next();
            
            b === undefined && k();
            return b;
          });
           else return {};
          
          !("__nothrowNext__" in a) && f(o,"__nothrowNext__",a.next.bind(a));
          
          for (var n in a)
          n !== "next" && n !== "__nothrowNext__" && (o[n] = a[n]);
          
          !("toString" in a) && f(o,"toString",
          function () {
            return "[object Iterator]";
          });
          return o;
        }
        function l(a) {
          return a instanceof g;
        }
        function k() {
          try {
            throw StopIteration;
          } catch(e){
            throw new Error(e.toString());
          }
          
        }
        function M(b) {
          for (var a in b)
          this[a] = b[a];
          
          Object.freeze(this);
        }
        function z(i) {
          h.apply(this,i);
          
          Object.freeze(this);
        }
        function E(c,b) {
          for (var a in b)
          c[a] = b[a];
          return c;
        }
        function A(a) {
          return (a.message)?a.message : (a.description)?a.description : a.toString();
        }
        function C(k,j,i) {
          var h = new g;
          
          f(h,"next",k.bind(i,false,false));
          
          f(h,"send",k.bind(i,true,false));
          
          f(h,"close",j.bind(i));
          
          f(h,"__nothrowNext__",k.bind(i,false,true));
          
          f(h,"toString",
          function () {
            return "[object Generator]";
          });
          
          Object.freeze(h);
          return h;
        }
        function g(){}
        function L(g,f) {
          return (g)?e.call(g,f) : [];
        }
        function H(c,b,a) {
          return Object.defineProperty(c,b, {
            configurable : false,
            enumerable : false,
            writable : false,
            value : a
          });
        }
        function f(c,b,a) {
          return Object.defineProperty(c,b, {
            configurable : true,
            enumerable : false,
            writable : true,
            value : a
          });
        }
        function c(b,c,d) {
          this.toString = function () {
            return a.getErrorMessage(d)+" in file "+c+" at : "+b;
          };
        }
        var r = {};
        
        var i = Math.max,
            F = Array.prototype,
            e = F.slice,
            h = F.push,
            a =  {
              getErrorMessage : function (a) {
                return (a.message)?a.message : (a.description)?a.description : a.toString();
              },
              exceptionHandler : function (g,f,e) {
                if (d(e)){
                  
                  this.throwException(e);
                } else {
                  
                  this.throwException(new c(g,f,e));
                }
                
              },
              throwException : function (a) {
                try {
                  throw a;
                } catch(e){
                  
                  if (d(e)){
                    throw new Error(e);
                  } else {
                    throw new Error(this.getErrorMessage(e));
                  }
                  
                }
                
              },
              hasProto : "__proto__" in {}
            };
        
        r.createUnenumProp = f;
        
        r.constant = H;
        
        r.toArray = L;
        
        r.createGenerator = C;
        
        var q = r.throwException = a.throwException.bind(a),
            B = r.exceptionHandler = a.exceptionHandler.bind(a);
        
        r.extend = E;
        
        r.TupleConstructor = z;
        
        z.prototype =  {
          compareTuple : function (l) {
            var k = i(l.length,this.length),
                j = -1;
            
            while ( ++ j<k && l[j] === this[j]){
              
            }
            return k === j;
          },
          tupleToArray : function () {
            return e.call(this);
          },
          toString : function () {
            return "[object Tuple]";
          }
        };
        
        r.RecordConstructor = M;
        
        M.prototpye =  {
          toString : function () {
            return "[object Record]";
          }
        };
        
        var I = r.extendPrototype = function (b,a) {
              b.prototype = a;
            },
            j = ("getPrototypeOf" in Object)?function (a) {
              return Object.getPrototypeOf(a);
            } : function (c) {
              var b = {};
              
              for (var a in c)
              !c.hasOwnProperty(a) && (b[a] = c[a]);
              return b;
            },
            G = r.extendClass = (a.hasProto)?function (c,b) {
              if (typeof b === 'function'){
                
                c.prototype.__proto__ = b.prototype;
                
                for (var a in b)a !== 'prototype' && (c[a] = b[a]);
              } else c.prototype.__proto__ = b.__proto__;
            } : function (p,o) {
              var n = typeof o;
              
              if (n === "function"){
                
                var m = function (){};
                
                m.prototype = o.prototype;
                
                p.prototype = new m;
                
                for (var l in o)p[l] = o[l];
              } else {
                
                var m = function (){},
                    k = j(o);
                
                m.prototype = k;
                
                p.prototype = new m;
              }
              
            },
            m = r.__ref_iterator__ = "__mocha_iterator_special_key__";
        
        r.throwStopIteration = k;
        
        r.isGenerator = l;
        
        r.getIterator = J;
        
        r.hasIterator = K;
        
        var n = /StopIteration/;
        
        r.isStopIteration = d;
        
        var o,
            p,
            y,
            x;
        
        if ("WeakMap" in b){
          
          o = new WeakMap();
          
          p = function (self,r,q) {
            var p = new r;
            
            f(p,"__is_private__",1);
            
            f(self,"constructor",q);
            
            o.set(self,p);
            
            o.set(p,self);
          };
          
          y = function (self) {
            if (o.has(self))return o.get(self);
             else if (self.__is_private__ === 1)return self;
          };
          
          x = function (a) {
            return o.get(a);
          };
        } else {
          
          p = function (self,d,c) {
            if (!self.__typeid__){
              
              var b = new d,
                  a = {};
              
              Object.defineProperty(a,"__is_private__", {
                value : 1
              });
              
              Object.defineProperty(a,"__parent__", {
                value : self
              });
              
              Object.defineProperty(b,"constructor", {
                value : a
              });
              
              f(c,"__private__",b);
              
              f(self,"constructor",c);
            }
            
          };
          
          y = function (self) {
            if (self.constructor.__private__)return self.constructor.__private__;
             else if (self.constructor.__is_private__ === 1)return self;
          };
          
          x = function (a) {
            return a.constructor.__parent__;
          };
        }
        
        r.getPrivateRecord = y;
        
        r.getInstanceBody = x;
        
        r.initializeClass = D;
        
        r.getSuper = v;
        
        r.traitMixin = w;
        
        r.classMixin = u;
        
        r.checkRequirements = t;
        
        r.spreadCall = s;
        return r;
      }();
  
  !("StopIteration" in b) && (b.StopIteration =  {
    toString : function () {
      return "[object StopIteration]";
    }
  });
  
  function d() {
    var b = a.toArray(arguments,0);
    return new a.TupleConstructor(b);
  }
  d.prototype = a.TupleConstructor.prototype;
  
  function e(b) {
    return new a.RecordConstructor(b);
  }
  e.prototype = a.RecordConstructor.prototype;
  
  !function () {
    c['-1426553882-knockout-2.0.0.debug.js'] = {};
    
    var d = c['-1426553882-knockout-2.0.0.debug.js'];
    
    !function (a,undefined) {
      function f(d,c,a) {
        a && c !== b.selectExtensions.readValue(d) && b.selectExtensions.writeValue(d,c);
        
        c !== b.selectExtensions.readValue(d) && b.utils.triggerEvent(d,"change");
      }
      function e(c,b,a) {
        if (c && typeof c == "object")a = c;
         else {
          
          a = a || {};
          
          a.read = c || a.read;
        }
        
        if (typeof a.read != "function")throw "Pass a function that returns the value of the dependentObservable";
        return a;
      }
      function i(e) {
        var d = this;
        
        if (e)for (var c in e){
          
          var a = b.extenders[c];
          
          typeof a == 'function' && (d = a(d,e[c]));
        }
        return d;
      }
      var b = a.ko = {};
      
      b.exportSymbol = function (f,d) {
        var c = f.split("."),
            b = a;
        
        for (var e = 0;e<c.length-1;e ++ )
        b = b[c[e]];
        
        b[c[c.length-1]] = d;
      };
      
      b.exportProperty = function (c,a,b) {
        c[a] = b;
      };
      
      b.utils = new function () {
        function d(c,b) {
          if ((c.tagName != "INPUT") || !c.type)return false;
          
          if (b.toLowerCase() != "click")return false;
          
          var a = c.type.toLowerCase();
          return (a == "checkbox") || (a == "radio");
        }
        var c = /^(\s|\u00A0)+|(\s|\u00A0)+$/g,
            n = {},
            e = {},
            m = /Firefox\/2/i.test(navigator.userAgent)?'KeyboardEvent' : 'UIEvents';
        
        n[m] = ['keyup','keydown','keypress'];
        
        n.MouseEvents = ['click','dblclick','mousedown','mouseup','mousemove','mouseover','mouseout','mouseenter','mouseleave'];
        
        for (var k in n){
          
          var j = n[k];
          
          if (j.length)for (var i = 0,l = j.length;i<l;i ++ )
          e[j[i]] = k;
        }
        
        var f = (function () {
              var c = 3,
                  b = document.createElement('div'),
                  a = b.getElementsByTagName('i');
              
              while (b.innerHTML = '<!--[if gt IE '+( ++ c)+']><i></i><![endif]-->', a[0]){
                
              }
              return c>4?c : undefined;
            }()),
            g = f === 6,
            h = f === 7;
        return  {
          fieldsIncludedWithJsonPost : ['authenticity_token',/^__RequestVerificationToken(_.*)?$/],
          arrayForEach : function (d,c) {
            for (var b = 0,a = d.length;b<a;b ++ ){
              
              c(d[b]);
            }
            
          },
          arrayIndexOf : function (d,c) {
            if (typeof Array.prototype.indexOf == "function"){
              return Array.prototype.indexOf.call(d,c);
            }
            
            for (var b = 0,a = d.length;b<a;b ++ ){
              
              if (d[b] === c){
                return b;
              }
              
            }
            return -1;
          },
          arrayFirst : function (e,d,c) {
            for (var b = 0,a = e.length;b<a;b ++ ){
              
              if (d.call(c,e[b])){
                return e[b];
              }
              
            }
            return null;
          },
          arrayRemoveItem : function (d,c) {
            var a = b.utils.arrayIndexOf(d,c);
            
            if (a >= 0){
              
              d.splice(a,1);
            }
            
          },
          arrayGetDistinctValues : function (e) {
            e = e || [];
            
            var d = [];
            
            for (var c = 0,a = e.length;c<a;c ++ ){
              
              if (b.utils.arrayIndexOf(d,e[c])<0){
                
                d.push(e[c]);
              }
              
            }
            return d;
          },
          arrayMap : function (e,d) {
            e = e || [];
            
            var c = [];
            
            for (var b = 0,a = e.length;b<a;b ++ ){
              
              c.push(d(e[b]));
            }
            return c;
          },
          arrayFilter : function (e,d) {
            e = e || [];
            
            var c = [];
            
            for (var b = 0,a = e.length;b<a;b ++ ){
              
              if (d(e[b])){
                
                c.push(e[b]);
              }
              
            }
            return c;
          },
          arrayPushAll : function (d,c) {
            for (var b = 0,a = c.length;b<a;b ++ ){
              
              d.push(c[b]);
            }
            return d;
          },
          extend : function (c,b) {
            for (var a in b){
              
              if (b.hasOwnProperty(a)){
                
                c[a] = b[a];
              }
              
            }
            return c;
          },
          emptyDomNode : function (a) {
            while (a.firstChild){
              
              b.removeNode(a.firstChild);
            }
            
          },
          setDomNodeChildren : function (a,c) {
            b.utils.emptyDomNode(a);
            
            if (c){
              
              b.utils.arrayForEach(c,
              function (b) {
                a.appendChild(b);
              });
            }
            
          },
          replaceDomNodes : function (h,g) {
            var f = h.nodeType?[h] : h;
            
            if (f.length>0){
              
              var d = f[0];
              
              var e = d.parentNode;
              
              for (var c = 0,a = g.length;c<a;c ++ ){
                
                e.insertBefore(g[c],d);
              }
              
              for (var c = 0,a = f.length;c<a;c ++ ){
                
                b.removeNode(f[c]);
              }
              
            }
            
          },
          setOptionNodeSelectionState : function (b,a) {
            if (navigator.userAgent.indexOf("MSIE 6") >= 0){
              
              b.setAttribute("selected",a);
            } else b.selected = a;
          },
          stringTrim : function (d) {
            return (d || "").replace(c,"");
          },
          stringTokenize : function (h,f) {
            var e = [];
            
            var g = (h || "").split(f);
            
            for (var d = 0,c = g.length;d<c;d ++ ){
              
              var a = b.utils.stringTrim(g[d]);
              
              if (a !== ""){
                
                e.push(a);
              }
              
            }
            return e;
          },
          stringStartsWith : function (b,a) {
            b = b || "";
            
            if (a.length>b.length){
              return false;
            }
            return b.substring(0,a.length) === a;
          },
          evalWithinScope : function (d) {
            var b = Array.prototype.slice.call(arguments,1);
            
            var c = "return ("+d+")";
            
            for (var a = 0;a<b.length;a ++ ){
              
              if (b[a] && typeof b[a] == "object"){
                
                c = "with(sc["+a+"]) { "+c+" } ";
              }
              
            }
            return (new Function("sc",c))(b);
          },
          domNodeIsContainedBy : function (b,a) {
            if (a.compareDocumentPosition){
              return (a.compareDocumentPosition(b)&16) == 16;
            }
            
            while (b != null){
              
              if (b == a){
                return true;
              }
              
              b = b.parentNode;
            }
            return false;
          },
          domNodeIsAttachedToDocument : function (a) {
            return b.utils.domNodeIsContainedBy(a,document);
          },
          registerEventHandler : function (b,e,c) {
            if (typeof jQuery != "undefined"){
              
              if (d(b,e)){
                
                var a = c;
                
                c = function (d,c) {
                  var b = this.checked;
                  
                  if (c){
                    
                    this.checked = c.checkedStateBeforeEvent !== true;
                  }
                  
                  a.call(this,d);
                  
                  this.checked = b;
                };
              }
              
              jQuery(b)['bind'](e,c);
            } else if (typeof b.addEventListener == "function"){
              
              b.addEventListener(e,c,false);
            } else if (typeof b.attachEvent != "undefined"){
              
              b.attachEvent("on"+e,
              function (d) {
                c.call(b,d);
              });
            } else throw new Error("Browser doesn't support addEventListener or attachEvent");
          },
          triggerEvent : function (j,i) {
            if (!(j && j.nodeType)){
              throw new Error("element must be a DOM node when calling triggerEvent");
            }
            
            if (typeof jQuery != "undefined"){
              
              var h = [];
              
              if (d(j,i)){
                
                h.push( {
                  checkedStateBeforeEvent : j.checked
                });
              }
              
              jQuery(j)['trigger'](i,h);
            } else if (typeof document.createEvent == "function"){
              if (typeof j.dispatchEvent == "function"){
                
                var g = e[i] || "HTMLEvents";
                
                var f = document.createEvent(g);
                
                f.initEvent(i,true,true,a,0,0,0,0,0,false,false,false,false,0,j);
                
                j.dispatchEvent(f);
              } else throw new Error("The supplied element doesn't support dispatchEvent");
            } else if (typeof j.fireEvent != "undefined"){
              if (i == "click"){
                if ((j.tagName == "INPUT") && ((j.type.toLowerCase() == "checkbox") || (j.type.toLowerCase() == "radio"))){
                  
                  j.checked = j.checked !== true;
                }
                
              }
              
              j.fireEvent("on"+i);
            } else throw new Error("Browser doesn't support triggering events");
          },
          unwrapObservable : function (a) {
            return b.isObservable(a)?a() : a;
          },
          domNodeHasCssClass : function (d,c) {
            var a = (d.className || "").split(/\s+/);
            return b.utils.arrayIndexOf(a,c) >= 0;
          },
          toggleDomNodeCssClass : function (h,g,f) {
            var e = b.utils.domNodeHasCssClass(h,g);
            
            if (f && !e){
              
              h.className = (h.className || "")+" "+g;
            } else if (e && !f){
              
              var c = (h.className || "").split(/\s+/);
              
              var d = "";
              
              for (var a = 0;a<c.length;a ++ ){
                if (c[a] != g){
                  
                  d += c[a]+" ";
                }
                
              }
              
              h.className = b.utils.stringTrim(d);
            }
            
          },
          outerHTML : function (i) {
            if (f === undefined){
              
              var h = i.outerHTML;
              
              if (typeof h == "string"){
                return h;
              }
              
            }
            
            var g = a.document.createElement("div");
            
            g.appendChild(i.cloneNode(true));
            return g.innerHTML;
          },
          setTextContent : function (d,c) {
            var a = b.utils.unwrapObservable(c);
            
            if ((a === null) || (a === undefined)){
              
              a = "";
            }
            
            'innerText' in d?d.innerText = a : d.textContent = a;
            
            if (f >= 9){
              
              d.innerHTML = d.innerHTML;
            }
            
          },
          range : function (e,d) {
            e = b.utils.unwrapObservable(e);
            
            d = b.utils.unwrapObservable(d);
            
            var c = [];
            
            for (var a = e;a <= d;a ++ ){
              
              c.push(a);
            }
            return c;
          },
          makeArray : function (d) {
            var c = [];
            
            for (var b = 0,a = d.length;b<a;b ++ ){
              
              c.push(d[b]);
            }
            return c;
          },
          isIe6 : g,
          isIe7 : h,
          getFormFields : function (g,a) {
            var e = b.utils.makeArray(g.getElementsByTagName("INPUT")).concat(b.utils.makeArray(g.getElementsByTagName("TEXTAREA")));
            
            var f = (typeof a == 'string')?function (b) {
                  return b.name === a;
                } : function (b) {
                  return a.test(b.name);
                };
            
            var d = [];
            
            for (var c = e.length-1;c >= 0;c -- ){
              
              if (f(e[c])){
                
                d.push(e[c]);
              }
              
            }
            return d;
          },
          parseJson : function (c) {
            if (typeof c == "string"){
              
              c = b.utils.stringTrim(c);
              
              if (c){
                
                if (a.JSON && a.JSON.parse){
                  return a.JSON.parse(c);
                }
                return (new Function("return "+c))();
              }
              
            }
            return null;
          },
          stringifyJson : function (a) {
            if ((typeof JSON == "undefined") || (typeof JSON.stringify == "undefined")){
              throw new Error("Cannot find JSON.stringify(). Some browsers (e.g., IE < 8) don't support it natively, but you can overcome this by adding a script reference to json2.js, downloadable from http://www.json.org/json2.js");
            }
            return JSON.stringify(b.utils.unwrapObservable(a));
          },
          postJson : function (i,n,m) {
            m = m || {};
            
            var k = m['params'] || {};
            
            var j = m['includeFields'] || this.fieldsIncludedWithJsonPost;
            
            var e = i;
            
            if ((typeof i == 'object') && (i.tagName == "FORM")){
              
              var g = i;
              
              e = g.action;
              
              for (var h = j.length-1;h >= 0;h -- ){
                
                var f = b.utils.getFormFields(g,j[h]);
                
                for (var d = f.length-1;d >= 0;d -- ){
                  
                  k[f[d].name] = f[d].value;
                }
                
              }
              
            }
            
            n = b.utils.unwrapObservable(n);
            
            var a = document.createElement("FORM");
            
            a.style.display = "none";
            
            a.action = e;
            
            a.method = "post";
            
            for (var l in n){
              
              var c = document.createElement("INPUT");
              
              c.name = l;
              
              c.value = b.utils.stringifyJson(b.utils.unwrapObservable(n[l]));
              
              a.appendChild(c);
            }
            
            for (var l in k){
              
              var c = document.createElement("INPUT");
              
              c.name = l;
              
              c.value = k[l];
              
              a.appendChild(c);
            }
            
            document.body.appendChild(a);
            
            m['submitter']?m['submitter'](a) : a.submit();
            
            setTimeout(function () {
              a.parentNode.removeChild(a);
            },0);
          }
        };
      }();
      
      b.exportSymbol('ko.utils',b.utils);
      
      b.utils.arrayForEach([['arrayForEach',b.utils.arrayForEach],['arrayFirst',b.utils.arrayFirst],['arrayFilter',b.utils.arrayFilter],['arrayGetDistinctValues',b.utils.arrayGetDistinctValues],['arrayIndexOf',b.utils.arrayIndexOf],['arrayMap',b.utils.arrayMap],['arrayPushAll',b.utils.arrayPushAll],['arrayRemoveItem',b.utils.arrayRemoveItem],['extend',b.utils.extend],['fieldsIncludedWithJsonPost',b.utils.fieldsIncludedWithJsonPost],['getFormFields',b.utils.getFormFields],['postJson',b.utils.postJson],['parseJson',b.utils.parseJson],['registerEventHandler',b.utils.registerEventHandler],['stringifyJson',b.utils.stringifyJson],['range',b.utils.range],['toggleDomNodeCssClass',b.utils.toggleDomNodeCssClass],['triggerEvent',b.utils.triggerEvent],['unwrapObservable',b.utils.unwrapObservable]],
      function (a) {
        b.exportSymbol('ko.utils.'+a[0],a[1]);
      });
      
      !Function.prototype.bind && (Function.prototype.bind = function (a) {
        var c = this,
            b = [].slice.call(arguments),
            a = b.shift();
        return function () {
          return c.apply(a,b.concat([].slice.call(arguments)));
        };
      });
      
      b.utils.domData = new function () {
        var a = 0,
            d = "__ko__"+(new Date).getTime(),
            c = {};
        return  {
          get : function (d,c) {
            var a = b.utils.domData.getAll(d,false);
            return a === undefined?undefined : a[c];
          },
          set : function (e,c,d) {
            if (d === undefined){
              
              if (b.utils.domData.getAll(e,false) === undefined){
                return ;
              }
              
            }
            
            var a = b.utils.domData.getAll(e,true);
            
            a[c] = d;
          },
          getAll : function (h,g) {
            var e = h[d];
            
            var f = e && (e !== "null");
            
            if (!f){
              
              if (!g){
                return undefined;
              }
              
              e = h[d] = "ko"+a ++ ;
              
              c[e] = {};
            }
            return c[e];
          },
          clear : function (b) {
            var a = b[d];
            
            if (a){
              
              delete c[a];
              
              b[d] = null;
            }
            
          }
        };
      }();
      
      b.exportSymbol('ko.utils.domData',b.utils.domData);
      
      b.exportSymbol('ko.utils.domData.clear',b.utils.domData.clear);
      
      b.utils.domNodeDisposal = new function () {
        function e(f) {
          var e = c(f,false);
          
          if (e){
            
            e = e.slice(0);
            
            for (var d = 0;d<e.length;d ++ )e[d](f);
          }
          
          b.utils.domData.clear(f);
          
          (typeof jQuery == "function") && (typeof jQuery.cleanData == "function") && jQuery.cleanData([f]);
        }
        function d(c) {
          b.utils.domData.set(c,a,undefined);
        }
        function c(e,d) {
          var c = b.utils.domData.get(e,a);
          
          if ((c === undefined) && d){
            
            c = [];
            
            b.utils.domData.set(e,a,c);
          }
          return c;
        }
        var a = "__ko_domNodeDisposal__"+(new Date).getTime();
        return  {
          addDisposeCallback : function (b,a) {
            if (typeof a != "function"){
              throw new Error("Callback must be a function");
            }
            
            c(b,true).push(a);
          },
          removeDisposeCallback : function (g,f) {
            var e = c(g,false);
            
            if (e){
              
              b.utils.arrayRemoveItem(e,f);
              
              if (e.length == 0){
                
                d(g);
              }
              
            }
            
          },
          cleanNode : function (i) {
            if ((i.nodeType != 1) && (i.nodeType != 9)){
              return ;
            }
            
            e(i);
            
            var h = [];
            
            b.utils.arrayPushAll(h,i.getElementsByTagName("*"));
            
            for (var f = 0,g = h.length;f<g;f ++ ){
              
              e(h[f]);
            }
            
          },
          removeNode : function (a) {
            b.cleanNode(a);
            
            if (a.parentNode){
              
              a.parentNode.removeChild(a);
            }
            
          }
        };
      }();
      
      b.cleanNode = b.utils.domNodeDisposal.cleanNode;
      
      b.removeNode = b.utils.domNodeDisposal.removeNode;
      
      b.exportSymbol('ko.cleanNode',b.cleanNode);
      
      b.exportSymbol('ko.removeNode',b.removeNode);
      
      b.exportSymbol('ko.utils.domNodeDisposal',b.utils.domNodeDisposal);
      
      b.exportSymbol('ko.utils.domNodeDisposal.addDisposeCallback',b.utils.domNodeDisposal.addDisposeCallback);
      
      b.exportSymbol('ko.utils.domNodeDisposal.removeDisposeCallback',b.utils.domNodeDisposal.removeDisposeCallback);
      
      !function () {
        function d(c) {
          var b = jQuery.clean([c]);
          
          if (b && b[0]){
            
            var a = b[0];
            
            while (a.parentNode && a.parentNode.nodeType !== 11)a = a.parentNode;
            
            a.parentNode && a.parentNode.removeChild(a);
          }
          return b;
        }
        function c(g) {
          var f = b.utils.stringTrim(g).toLowerCase(),
              e = document.createElement("div"),
              c = f.match(/^<(thead|tbody|tfoot)/) && [1,"<table>","</table>"] || !f.indexOf("<tr") && [2,"<table><tbody>","</tbody></table>"] || (!f.indexOf("<td") || !f.indexOf("<th")) && [3,"<table><tbody><tr>","</tr></tbody></table>"] || [0,"",""],
              d = "ignored<div>"+c[1]+g+c[2]+"</div>";
          
          typeof a.innerShiv == "function"?e.appendChild(a.innerShiv(d)) : e.innerHTML = d;
          
          while (c[0] -- )e = e.lastChild;
          return b.utils.makeArray(e.lastChild.childNodes);
        }
        var e = /^(\s*)<!--(.*?)-->/;
        
        b.utils.parseHtmlFragment = function (e) {
          return typeof jQuery != 'undefined'?d(e) : c(e);
        };
        
        b.utils.setHtml = function (e,d) {
          b.utils.emptyDomNode(e);
          
          if ((d !== null) && (d !== undefined)){
            
            typeof d != 'string' && (d = d.toString());
            
            if (typeof jQuery != 'undefined')jQuery(e).html(d);
             else {
              
              var c = b.utils.parseHtmlFragment(d);
              
              for (var a = 0;a<c.length;a ++ )e.appendChild(c[a]);
            }
            
          }
          
        };
      }();
      
      b.exportSymbol('ko.utils.parseHtmlFragment',b.utils.parseHtmlFragment);
      
      b.exportSymbol('ko.utils.setHtml',b.utils.setHtml);
      
      b.memoization = function () {
        function c(i,h) {
          if (!i)return ;
          
          if (i.nodeType == 8){
            
            var g = b.memoization.parseMemoText(i.nodeValue);
            
            g != null && h.push( {
              domNode : i,
              memoId : g
            });
          } else if (i.nodeType == 1)for (var f = 0,e = i.childNodes,d = e.length;f<d;f ++ )
          c(e[f],h);
        }
        function e() {
          return a()+a();
        }
        function a() {
          return (((1+Math.random())*0x00000000)|0).toString(16).substring(1);
        }
        var d = {};
        return  {
          memoize : function (g) {
            if (typeof g != "function"){
              throw new Error("You can only pass a function to ko.memoization.memoize()");
            }
            
            var f = e();
            
            d[f] = g;
            return "<!--[ko_memo:"+f+"]-->";
          },
          unmemoize : function (c,b) {
            var a = d[c];
            
            if (a === undefined){
              throw new Error("Couldn't find any memo with ID "+c+". Perhaps it's already been unmemoized.");
            }
            
            try {
              
              a.apply(null,b || []);
              return true;
            } finally {
              
              delete d[c];
            }
            
          },
          unmemoizeDomNodeAndDescendants : function (i,f) {
            var h = [];
            
            c(i,h);
            
            for (var d = 0,g = h.length;d<g;d ++ ){
              
              var a = h[d].domNode;
              
              var e = [a];
              
              if (f){
                
                b.utils.arrayPushAll(e,f);
              }
              
              b.memoization.unmemoize(h[d].memoId,e);
              
              a.nodeValue = "";
              
              if (a.parentNode){
                
                a.parentNode.removeChild(a);
              }
              
            }
            
          },
          parseMemoText : function (b) {
            var a = b.match(/^\[ko_memo\:(.*?)\]$/);
            return a?a[1] : null;
          }
        };
      }();
      
      b.exportSymbol('ko.memoization',b.memoization);
      
      b.exportSymbol('ko.memoization.memoize',b.memoization.memoize);
      
      b.exportSymbol('ko.memoization.unmemoize',b.memoization.unmemoize);
      
      b.exportSymbol('ko.memoization.parseMemoText',b.memoization.parseMemoText);
      
      b.exportSymbol('ko.memoization.unmemoizeDomNodeAndDescendants',b.memoization.unmemoizeDomNodeAndDescendants);
      
      b.extenders =  {
        'throttle' : function (a,c) {
          a['throttleEvaluation'] = c;
          
          var d = null;
          return b.dependentObservable( {
            'read' : a,
            'write' : function (b) {
              clearTimeout(d);
              
              d = setTimeout(function () {
                a(b);
              },c);
            }
          });
        },
        'notify' : function (c,a) {
          c["equalityComparer"] = a == "always"?function () {
            return false;
          } : b.observable["fn"]["equalityComparer"];
          return c;
        }
      };
      
      b.exportSymbol('ko.extenders',b.extenders);
      
      b.subscription = function (c,a) {
        this.callback = c;
        
        this.disposeCallback = a;
        
        b.exportProperty(this,'dispose',this.dispose);
      };
      
      b.subscription.prototype.dispose = function () {
        this.isDisposed = true;
        
        this.disposeCallback();
      };
      
      b.subscribable = function () {
        this._subscriptions = {};
        
        b.utils.extend(this,b.subscribable.fn);
        
        b.exportProperty(this,'subscribe',this.subscribe);
        
        b.exportProperty(this,'extend',this.extend);
        
        b.exportProperty(this,'getSubscriptionsCount',this.getSubscriptionsCount);
      };
      
      var c = "change";
      
      b.subscribable.fn =  {
        subscribe : function (g,f,d) {
          d = d || c;
          
          var e = f?g.bind(f) : g;
          
          var a = new b.subscription(e,function () {
                b.utils.arrayRemoveItem(this._subscriptions[d],a);
              }.bind(this));
          
          if (!this._subscriptions[d]){
            
            this._subscriptions[d] = [];
          }
          
          this._subscriptions[d].push(a);
          return a;
        },
        "notifySubscribers" : function (a,d) {
          d = d || c;
          
          if (this._subscriptions[d]){
            
            b.utils.arrayForEach(this._subscriptions[d].slice(0),
            function (b) {
              if (b && (b.isDisposed !== true)){
                
                b.callback(a);
              }
              
            });
          }
          
        },
        getSubscriptionsCount : function () {
          var b = 0;
          
          for (var a in this._subscriptions){
            
            if (this._subscriptions.hasOwnProperty(a)){
              
              b += this._subscriptions[a].length;
            }
            
          }
          return b;
        },
        extend : i
      };
      
      b.isSubscribable = function (a) {
        return typeof a.subscribe == "function" && typeof a.notifySubscribers == "function";
      };
      
      b.exportSymbol('ko.subscribable',b.subscribable);
      
      b.exportSymbol('ko.isSubscribable',b.isSubscribable);
      
      b.dependencyDetection = function () {
        var a = [];
        return  {
          begin : function (b) {
            a.push( {
              callback : b,
              distinctDependencies : []
            });
          },
          end : function () {
            a.pop();
          },
          registerDependency : function (d) {
            if (!b.isSubscribable(d)){
              throw "Only subscribable things can act as dependencies";
            }
            
            if (a.length>0){
              
              var c = a[a.length-1];
              
              if (b.utils.arrayIndexOf(c.distinctDependencies,d) >= 0){
                return ;
              }
              
              c.distinctDependencies.push(d);
              
              c.callback(d);
            }
            
          }
        };
      }();
      
      var d =  {
            'undefined' : true,
            'boolean' : true,
            'number' : true,
            'string' : true
          };
      
      b.observable = function (d) {
        function c() {
          if (arguments.length>0){
            
            if ((!c.equalityComparer) || !c.equalityComparer(a,arguments[0])){
              
              c.valueWillMutate();
              
              a = arguments[0];
              
              c.valueHasMutated();
            }
            return this;
          } else {
            
            b.dependencyDetection.registerDependency(c);
            return a;
          }
          
        }
        var a = d;
        
        b.subscribable.call(c);
        
        c.valueHasMutated = function () {
          c.notifySubscribers(a);
        };
        
        c.valueWillMutate = function () {
          c.notifySubscribers(a,"beforeChange");
        };
        
        b.utils.extend(c,b.observable.fn);
        
        b.exportProperty(c,"valueHasMutated",c.valueHasMutated);
        
        b.exportProperty(c,"valueWillMutate",c.valueWillMutate);
        return c;
      };
      
      b.observable.fn =  {
        __ko_proto__ : b.observable,
        "equalityComparer" : function h(g,f) {
          var e = (g === null) || (typeof (g) in d);
          return e?(g === f) : false;
        }
      };
      
      b.isObservable = function (a) {
        if ((a === null) || (a === undefined) || (a.__ko_proto__ === undefined))return false;
        
        if (a.__ko_proto__ === b.observable)return true;
        return b.isObservable(a.__ko_proto__);
      };
      
      b.isWriteableObservable = function (a) {
        if ((typeof a == "function") && a.__ko_proto__ === b.observable)return true;
        
        if ((typeof a == "function") && (a.__ko_proto__ === b.dependentObservable) && (a.hasWriteFunction))return true;
        return false;
      };
      
      b.exportSymbol('ko.observable',b.observable);
      
      b.exportSymbol('ko.isObservable',b.isObservable);
      
      b.exportSymbol('ko.isWriteableObservable',b.isWriteableObservable);
      
      b.observableArray = function (c) {
        arguments.length == 0 && (c = []);
        
        if ((c !== null) && (c !== undefined) && !('length' in c))throw new Error("The argument passed when initializing an observable array must be an array, or null, or undefined.");
        
        var a = new b.observable(c);
        
        b.utils.extend(a,b.observableArray.fn);
        
        b.exportProperty(a,"remove",a.remove);
        
        b.exportProperty(a,"removeAll",a.removeAll);
        
        b.exportProperty(a,"destroy",a.destroy);
        
        b.exportProperty(a,"destroyAll",a.destroyAll);
        
        b.exportProperty(a,"indexOf",a.indexOf);
        
        b.exportProperty(a,"replace",a.replace);
        return a;
      };
      
      b.observableArray.fn =  {
        remove : function (a) {
          var f = this();
          
          var e = [];
          
          var d = typeof a == "function"?a : function (b) {
                return b === a;
              };
          
          for (var c = 0;c<f.length;c ++ ){
            
            var b = f[c];
            
            if (d(b)){
              
              if (e.length === 0){
                
                this.valueWillMutate();
              }
              
              e.push(b);
              
              f.splice(c,1);
              
              c -- ;
            }
            
          }
          
          if (e.length){
            
            this.valueHasMutated();
          }
          return e;
        },
        removeAll : function (a) {
          if (a === undefined){
            
            var d = this();
            
            var c = d.slice(0);
            
            this.valueWillMutate();
            
            d.splice(0,d.length);
            
            this.valueHasMutated();
            return c;
          }
          
          if (!a){
            return [];
          }
          return this.remove(function (c) {
            return b.utils.arrayIndexOf(a,c) >= 0;
          });
        },
        destroy : function (a) {
          var e = this();
          
          var d = typeof a == "function"?a : function (b) {
                return b === a;
              };
          
          this.valueWillMutate();
          
          for (var c = e.length-1;c >= 0;c -- ){
            
            var b = e[c];
            
            if (d(b)){
              
              e[c]["_destroy"] = true;
            }
            
          }
          
          this.valueHasMutated();
        },
        destroyAll : function (a) {
          if (a === undefined){
            return this.destroy(function () {
              return true;
            });
          }
          
          if (!a){
            return [];
          }
          return this.destroy(function (c) {
            return b.utils.arrayIndexOf(a,c) >= 0;
          });
        },
        indexOf : function (c) {
          var a = this();
          return b.utils.arrayIndexOf(a,c);
        },
        replace : function (c,b) {
          var a = this.indexOf(c);
          
          if (a >= 0){
            
            this.valueWillMutate();
            
            this()[a] = b;
            
            this.valueHasMutated();
          }
          
        }
      };
      
      b.utils.arrayForEach(["pop","push","reverse","shift","sort","splice","unshift"],
      function (a) {
        b.observableArray.fn[a] = function () {
          var c = this();
          
          this.valueWillMutate();
          
          var b = c[a].apply(c,arguments);
          
          this.valueHasMutated();
          return b;
        };
      });
      
      b.utils.arrayForEach(["slice"],
      function (a) {
        b.observableArray.fn[a] = function () {
          var b = this();
          return b[a].apply(b,arguments);
        };
      });
      
      b.exportSymbol('ko.observableArray',b.observableArray);
      
      b.dependentObservable = function (p,j,m) {
        function a() {
          if (arguments.length>0)if (typeof m.write === "function"){
            
            var c = m.owner || j;
            
            m.write.apply(c,arguments);
          } else throw "Cannot write a value to a dependentObservable unless you specify a 'write' option. If you wish to read the current value, don't pass any parameters.";
           else {
            
            !n && h();
            
            b.dependencyDetection.registerDependency(a);
            return i;
          }
          
        }
        function h() {
          if ((n) && typeof m.disposeWhen == "function")if (m.disposeWhen()){
            
            a.dispose();
            return ;
          }
          
          try {
            
            l();
            
            b.dependencyDetection.begin(function (a) {
              f.push(a.subscribe(k));
            });
            
            var p = m.owner || j;
            
            var o = m.read.call(p);
            
            a.notifySubscribers(i,"beforeChange");
            
            i = o;
          } finally {
            
            b.dependencyDetection.end();
          }
          
          a.notifySubscribers(i);
          
          n = true;
        }
        function k() {
          var i = a.throttleEvaluation;
          
          if (i && i >= 0){
            
            clearTimeout(g);
            
            g = setTimeout(h,i);
          } else h();
        }
        function l() {
          b.utils.arrayForEach(f,
          function (a) {
            a.dispose();
          });
          
          f = [];
        }
        var i,
            n = false,
            m = e(p,j,m),
            d = (typeof m.disposeWhenNodeIsRemoved == "object")?m.disposeWhenNodeIsRemoved : null,
            o = null;
        
        if (d){
          
          o = function () {
            a.dispose();
          };
          
          b.utils.domNodeDisposal.addDisposeCallback(d,o);
          
          var c = m.disposeWhen;
          
          m.disposeWhen = function () {
            return (!b.utils.domNodeIsAttachedToDocument(d)) || ((typeof c == "function") && c());
          };
        }
        
        var f = [];
        
        var g = null;
        
        a.getDependenciesCount = function () {
          return f.length;
        };
        
        a.hasWriteFunction = typeof m.write === "function";
        
        a.dispose = function () {
          d && b.utils.domNodeDisposal.removeDisposeCallback(d,o);
          
          l();
        };
        
        b.subscribable.call(a);
        
        b.utils.extend(a,b.dependentObservable.fn);
        
        m.deferEvaluation !== true && h();
        
        b.exportProperty(a,'dispose',a.dispose);
        
        b.exportProperty(a,'getDependenciesCount',a.getDependenciesCount);
        return a;
      };
      
      b.dependentObservable.fn =  {
        __ko_proto__ : b.dependentObservable
      };
      
      b.dependentObservable.__ko_proto__ = b.observable;
      
      b.exportSymbol('ko.dependentObservable',b.dependentObservable);
      
      b.exportSymbol('ko.computed',b.dependentObservable);
      
      !function () {
        function e() {
          var c = [],
              a = [];
          
          this.save = function (f,e) {
            var d = b.utils.arrayIndexOf(c,f);
            
            if (d >= 0)a[d] = e;
             else {
              
              c.push(f);
              
              a.push(e);
            }
            
          };
          
          this.get = function (e) {
            var d = b.utils.arrayIndexOf(c,e);
            return (d >= 0)?a[d] : undefined;
          };
        }
        function d(d,c) {
          if (d instanceof Array)for (var b = 0;b<d.length;b ++ )
          c(b);
           else for (var a in d)
          c(a);
        }
        function c(f,g,b) {
          b = b || new e();
          
          f = g(f);
          
          var h = (typeof f == "object") && (f !== null) && (f !== undefined) && (!(f instanceof Date));
          
          if (!h)return f;
          
          var a = f instanceof Array?[] : {};
          
          b.save(f,a);
          
          d(f,
          function (j) {
            var i = g(f[j]);
            
            switch (typeof i) {
              case "boolean" :
              case "number" :
              case "string" :
              case "function" :
                
                a[j] = i;
                break;
              case "object" :
              case "undefined" :
                
                var h = b.get(i);
                
                a[j] = (h !== undefined)?h : c(i,g,b);
                break;
                
            }
            
          });
          return a;
        }
        var a = 10;
        
        b.toJS = function (d) {
          if (arguments.length == 0)throw new Error("When calling ko.toJS, pass the object you want to convert.");
          return c(d,
          function (d) {
            for (var c = 0;b.isObservable(d) && (c<a);c ++ )
            d = d();
            return d;
          });
        };
        
        b.toJSON = function (c) {
          var a = b.toJS(c);
          return b.utils.stringifyJson(a);
        };
      }();
      
      b.exportSymbol('ko.toJS',b.toJS);
      
      b.exportSymbol('ko.toJSON',b.toJSON);
      
      !function () {
        var a = '__ko__hasDomDataOptionValue__';
        
        b.selectExtensions =  {
          readValue : function (c) {
            if (c.tagName == 'OPTION'){
              
              if (c[a] === true){
                return b.utils.domData.get(c,b.bindingHandlers.options.optionValueDomDataKey);
              }
              return c.getAttribute("value");
            } else if (c.tagName == 'SELECT'){
              return c.selectedIndex >= 0?b.selectExtensions.readValue(c.options[c.selectedIndex]) : undefined;
            } else return c.value;
          },
          writeValue : function (e,d) {
            if (e.tagName == 'OPTION'){
              
              switch (typeof d) {
                case "string" :
                  
                  b.utils.domData.set(e,b.bindingHandlers.options.optionValueDomDataKey,undefined);
                  
                  if (a in e){
                    
                    delete e[a];
                  }
                  
                  e.value = d;
                  break;
                default :
                  
                  b.utils.domData.set(e,b.bindingHandlers.options.optionValueDomDataKey,d);
                  
                  e[a] = true;
                  
                  e.value = typeof d === "number"?d : "";
                  break;
                  
              }
              
            } else if (e.tagName == 'SELECT'){
              
              for (var c = e.options.length-1;c >= 0;c -- ){
                if (b.selectExtensions.readValue(e.options[c]) == d){
                  
                  e.selectedIndex = c;
                  break;
                }
                
              }
              
            } else {
              if ((d === null) || (d === undefined)){
                
                d = "";
              }
              
              e.value = d;
            }
            
          }
        };
      }();
      
      b.exportSymbol('ko.selectExtensions',b.selectExtensions);
      
      b.exportSymbol('ko.selectExtensions.readValue',b.selectExtensions.readValue);
      
      b.exportSymbol('ko.selectExtensions.writeValue',b.selectExtensions.writeValue);
      
      b.jsonExpressionRewriting = function () {
        function g(c) {
          var a = b.utils.stringTrim(c);
          
          switch (a.length && a.charAt(0)) {
            case "'" :
            case '"' :
              return c;
            default :
              return "'"+a+"'";
              
          }
          
        }
        function f(e) {
          if (b.utils.arrayIndexOf(d,b.utils.stringTrim(e).toLowerCase()) >= 0)return false;
          return e.match(c) !== null;
        }
        function e(d,b) {
          var c = null;
          
          while (d != c){
            
            c = d;
            
            d = d.replace(a,
            function (d,c) {
              return b[c];
            });
          }
          return d;
        }
        var a = /\@ko_token_(\d+)\@/g,
            c = /^[\_$a-z][\_$a-z0-9]*(\[.*?\])*(\.[\_$a-z][\_$a-z0-9]*(\[.*?\])*)*$/i,
            d = ["true","false"];
        return  {
          bindingRewriteValidators : [],
          parseObjectLiteral : function (j) {
            var x = b.utils.stringTrim(j);
            
            if (x.length<3){
              return [];
            }
            
            if (x.charAt(0) === "{"){
              
              x = x.substring(1,x.length-1);
            }
            
            var l = [];
            
            var p = null,
                u;
            
            for (var w = 0;w<x.length;w ++ ){
              
              var n = x.charAt(w);
              
              if (p === null){
                
                switch (n) {
                  case '"' :
                  case "'" :
                  case "/" :
                    
                    p = w;
                    
                    u = n;
                    break;
                    
                }
                
              } else if ((n == u) && (x.charAt(w-1) !== "\\")){
                
                var t = x.substring(p,w+1);
                
                l.push(t);
                
                var r = "@ko_token_"+(l.length-1)+"@";
                
                x = x.substring(0,p)+r+x.substring(w+1);
                
                w -= (t.length-r.length);
                
                p = null;
              }
              
            }
            
            p = null;
            
            u = null;
            
            var q = 0,
                o = null;
            
            for (var w = 0;w<x.length;w ++ ){
              
              var n = x.charAt(w);
              
              if (p === null){
                
                switch (n) {
                  case "{" :
                    
                    p = w;
                    
                    o = n;
                    
                    u = "}";
                    break;
                  case "(" :
                    
                    p = w;
                    
                    o = n;
                    
                    u = ")";
                    break;
                  case "[" :
                    
                    p = w;
                    
                    o = n;
                    
                    u = "]";
                    break;
                    
                }
                
              }
              
              if (n === o){
                
                q ++ ;
              } else if (n === u){
                
                q -- ;
                if (q === 0){
                  
                  var t = x.substring(p,w+1);
                  
                  l.push(t);
                  
                  var r = "@ko_token_"+(l.length-1)+"@";
                  
                  x = x.substring(0,p)+r+x.substring(w+1);
                  
                  w -= (t.length-r.length);
                  
                  p = null;
                }
                
              }
              
            }
            
            var v = [];
            
            var k = x.split(",");
            
            for (var i = 0,h = k.length;i<h;i ++ ){
              
              var m = k[i];
              
              var g = m.indexOf(":");
              
              if ((g>0) && (g<m.length-1)){
                
                var s = m.substring(0,g);
                
                var f = m.substring(g+1);
                
                v.push( {
                  'key' : e(s,l),
                  'value' : e(f,l)
                });
              } else {
                
                v.push( {
                  'unknown' : e(m,l)
                });
              }
              
            }
            return v;
          },
          insertPropertyAccessorsIntoJson : function (q) {
            var n = typeof q === "string"?b.jsonExpressionRewriting.parseObjectLiteral(q) : q;
            
            var l = [],
                k = [];
            
            var j;
            
            for (var p = 0;j = n[p];p ++ ){
              
              if (l.length>0){
                
                l.push(",");
              }
              
              if (j['key']){
                
                var i = g(j['key']),
                    o = j['value'];
                
                l.push(i);
                
                l.push(":");
                
                l.push(o);
                
                if (f(b.utils.stringTrim(o))){
                  
                  if (k.length>0){
                    
                    k.push(", ");
                  }
                  
                  k.push(i+" : function(__ko_value) { "+o+" = __ko_value; }");
                }
                
              } else if (j['unknown']){
                
                l.push(j['unknown']);
              }
              
            }
            
            var m = l.join("");
            
            if (k.length>0){
              
              var h = k.join("");
              
              m = m+", '_ko_property_writers' : { "+h+" } ";
            }
            return m;
          },
          keyValueArrayContainsKey : function (d,c) {
            for (var a = 0;a<d.length;a ++ ){
              
              if (b.utils.stringTrim(d[a]['key']) == c){
                return true;
              }
              
            }
            return false;
          }
        };
      }();
      
      b.exportSymbol('ko.jsonExpressionRewriting',b.jsonExpressionRewriting);
      
      b.exportSymbol('ko.jsonExpressionRewriting.bindingRewriteValidators',b.jsonExpressionRewriting.bindingRewriteValidators);
      
      b.exportSymbol('ko.jsonExpressionRewriting.parseObjectLiteral',b.jsonExpressionRewriting.parseObjectLiteral);
      
      b.exportSymbol('ko.jsonExpressionRewriting.insertPropertyAccessorsIntoJson',b.jsonExpressionRewriting.insertPropertyAccessorsIntoJson);
      
      !function () {
        function j(l) {
          var k = l.firstChild,
              i = null;
          
          if (k){
            
            do if (i)i.push(k);
             else if (e(k)){
              
              var j = h(k,true);
              
              j?k = j : i = [k];
            } else f(k) && (i = [k]);
            while (k = k.nextSibling);
          }
          return i;
        }
        function i(f,d) {
          var c = [];
          
          for (var a = 0,e = f.length;a<e;a ++ ){
            
            d && b.utils.domNodeDisposal.cleanNode(f[a]);
            
            c.push(b.utils.outerHTML(f[a]));
          }
          return ''.concat.apply("",c);
        }
        function h(j,i) {
          var h = g(j,i);
          
          if (h){
            
            if (h.length>0)return h[h.length-1].nextSibling;
            return j.nextSibling;
          } else return null;
        }
        function g(k,j) {
          var i = k,
              h = 1,
              g = [];
          
          while (i = i.nextSibling){
            
            if (f(i)){
              
              h -- ;
              
              if (h === 0)return g;
            }
            
            g.push(i);
            
            e(i) && h ++ ;
          }
          
          if (!j)throw new Error("Cannot find closing comment tag to match: "+k.nodeValue);
          return null;
        }
        function f(e) {
          return (e.nodeType == 8) && (c?e.text : e.nodeValue).match(d);
        }
        function e(d) {
          return (d.nodeType == 8) && (c?d.text : d.nodeValue).match(a);
        }
        var c = document.createComment("test").text === "<!--test-->",
            a = c?/^<!--\s*ko\s+(.*\:.*)\s*-->$/ : /^\s*ko\s+(.*\:.*)\s*$/,
            d = c?/^<!--\s*\/ko\s*-->$/ : /^\s*\/ko\s*$/,
            k =  {
              'ul' : true,
              'ol' : true
            };
        
        b.virtualElements =  {
          allowedBindings : {},
          childNodes : function (a) {
            return e(a)?g(a) : a.childNodes;
          },
          emptyNode : function (f) {
            if (!e(f)){
              
              b.utils.emptyDomNode(f);
            } else {
              
              var d = b.virtualElements.childNodes(f);
              
              for (var c = 0,a = d.length;c<a;c ++ ){
                
                b.removeNode(d[c]);
              }
              
            }
            
          },
          setDomNodeChildren : function (g,f) {
            if (!e(g)){
              
              b.utils.setDomNodeChildren(g,f);
            } else {
              
              b.virtualElements.emptyNode(g);
              
              var d = g.nextSibling;
              
              for (var a = 0,c = f.length;a<c;a ++ ){
                
                d.parentNode.insertBefore(f[a],d);
              }
              
            }
            
          },
          prepend : function (b,a) {
            if (!e(b)){
              
              if (b.firstChild){
                
                b.insertBefore(a,b.firstChild);
              } else b.appendChild(a);
            } else {
              
              b.parentNode.insertBefore(a,b.nextSibling);
            }
            
          },
          insertAfter : function (c,b,a) {
            if (!e(c)){
              
              if (a.nextSibling){
                
                c.insertBefore(b,a.nextSibling);
              } else c.appendChild(b);
            } else {
              
              c.parentNode.insertBefore(b,a.nextSibling);
            }
            
          },
          nextSibling : function (a) {
            if (!e(a)){
              
              if (a.nextSibling && f(a.nextSibling)){
                return undefined;
              }
              return a.nextSibling;
            } else {
              return h(a).nextSibling;
            }
            
          },
          virtualNodeBindingValue : function (b) {
            var a = e(b);
            return a?a[1] : null;
          },
          extractAnonymousTemplateIfVirtualElement : function (l) {
            if (b.virtualElements.virtualNodeBindingValue(l)){
              
              var k = b.virtualElements.childNodes(l);
              
              var j = i(k,true);
              
              b.virtualElements.emptyNode(l);
              
              new b.templateSources.anonymousTemplate(l).text(j);
            }
            
          },
          normaliseVirtualElementDomStructure : function (p) {
            if (!k[p.tagName.toLowerCase()]){
              return ;
            }
            
            var n = p.firstChild;
            
            if (n){
              
              do {
                
                if (n.nodeType === 1){
                  
                  var m = j(n);
                  
                  if (m){
                    
                    var l = n.nextSibling;
                    
                    for (var o = 0;o<m.length;o ++ ){
                      
                      if (l){
                        
                        p.insertBefore(m[o],l);
                      } else p.appendChild(m[o]);
                    }
                    
                  }
                  
                }
                
              }while (n = n.nextSibling);
            }
            
          }
        };
      }();
      
      !function () {
        var c = "data-bind";
        
        b.bindingProvider = function (){};
        
        b.utils.extend(b.bindingProvider.prototype, {
          'nodeHasBindings' : function (d) {
            switch (d.nodeType) {
              case 1 :
                return d.getAttribute(c) != null;
              case 8 :
                return b.virtualElements.virtualNodeBindingValue(d) != null;
              default :
                return false;
                
            }
            
          },
          'getBindings' : function (c,b) {
            var a = this['getBindingsString'](c,b);
            return a?this['parseBindingsString'](a,b) : null;
          },
          'getBindingsString' : function (d,a) {
            switch (d.nodeType) {
              case 1 :
                return d.getAttribute(c);
              case 8 :
                return b.virtualElements.virtualNodeBindingValue(d);
              default :
                return null;
                
            }
            
          },
          'parseBindingsString' : function (f,e) {
            try {
              
              var d = e['$data'];
              
              var c = " { "+b.jsonExpressionRewriting.insertPropertyAccessorsIntoJson(f)+" } ";
              return b.utils.evalWithinScope(c,d === null?a : d,e);
            } catch(ex){
              throw new Error("Unable to parse bindings.\nMessage: "+ex+";\nBindings value: "+f);
            }
            
          }
        });
        
        b.bindingProvider.instance = new b.bindingProvider();
      }();
      
      b.exportSymbol('ko.bindingProvider',b.bindingProvider);
      
      !function () {
        function e(c,i,g,j) {
          function d() {
            return a;
          }
          function e(b) {
            return function () {
              return a[b];
            };
          }
          var k = 0;
          
          b.virtualElements.extractAnonymousTemplateIfVirtualElement(c);
          
          var a;
          
          var h;
          
          new b.dependentObservable(function () {
            var s = g && (g instanceof b.bindingContext)?g : new b.bindingContext(b.utils.unwrapObservable(g)),
                r = s.$data;
            
            j && b.storedBindingContextForNode(c,s);
            
            var o = (typeof i == "function")?i() : i;
            
            a = o || b.bindingProvider.instance.getBindings(c,s);
            
            if (a){
              
              if (k === 0){
                
                k = 1;
                
                for (var m in a){
                  
                  var q = b.bindingHandlers[m];
                  
                  q && c.nodeType === 8 && f(m);
                  
                  if (q && typeof q.init == "function"){
                    
                    var p = q.init;
                    
                    var l = p(c,e(m),d,r,s);
                    
                    if (l && l.controlsDescendantBindings){
                      
                      if (h !== undefined)throw new Error("Multiple bindings ("+h+" and "+m+") are trying to control descendant bindings of the same element. You cannot use these bindings together on the same element.");
                      
                      h = m;
                    }
                    
                  }
                  
                }
                
                k = 2;
              }
              
              if (k === 2)for (var m in a){
                
                var q = b.bindingHandlers[m];
                
                if (q && typeof q.update == "function"){
                  
                  var n = q.update;
                  
                  n(c,e(m),d,r,s);
                }
                
              }
              
            }
            
          },null, {
            'disposeWhenNodeIsRemoved' : c
          });
          return  {
            shouldBindDescendants : h === undefined
          };
        }
        function c(k,j,h) {
          var g = true,
              f = (j.nodeType == 1);
          
          f && b.virtualElements.normaliseVirtualElementDomStructure(j);
          
          var i = (f && h) || b.bindingProvider.instance.nodeHasBindings(j);
          
          i && (g = e(j,null,k,h).shouldBindDescendants);
          
          f && g && d(k,j);
        }
        function d(g,f) {
          var e,
              d = f.childNodes[0];
          
          while (e = d){
            
            d = b.virtualElements.nextSibling(e);
            
            c(g,e,false);
          }
          
        }
        function f(c) {
          var a = b.virtualElements.allowedBindings[c];
          
          if (!a)throw new Error("The binding '"+c+"' cannot be used with virtual elements");
        }
        b.bindingHandlers = {};
        
        b.bindingContext = function (b,a) {
          this.$data = b;
          
          if (a){
            
            this.$parent = a.$data;
            
            this.$parents = (a.$parents || []).slice(0);
            
            this.$parents.unshift(this.$parent);
            
            this.$root = a.$root;
          } else {
            
            this.$parents = [];
            
            this.$root = b;
          }
          
        };
        
        b.bindingContext.prototype.createChildContext = function (a) {
          return new b.bindingContext(a,this);
        };
        
        var g = "__ko_bindingContext__";
        
        b.storedBindingContextForNode = function (i,h) {
          if (arguments.length == 2)b.utils.domData.set(i,g,h);
           else return b.utils.domData.get(i,g);
        };
        
        b.applyBindingsToNode = function (d,c,a) {
          d.nodeType === 1 && b.virtualElements.normaliseVirtualElementDomStructure(d);
          return e(d,c,a,true);
        };
        
        b.applyBindingsToDescendants = function (b,a) {
          a.nodeType === 1 && d(b,a);
        };
        
        b.applyBindings = function (d,b) {
          if (b && (b.nodeType !== 1) && (b.nodeType !== 8))throw new Error("ko.applyBindings: first parameter should be your view model; second parameter should be a DOM node");
          
          b = b || a.document.body;
          
          c(d,b,true);
        };
        
        b.contextFor = function (c) {
          switch (c.nodeType) {
            case 1 :
            case 8 :
              
              var a = b.storedBindingContextForNode(c);
              
              if (a){
                return a;
              }
              
              if (c.parentNode){
                return b.contextFor(c.parentNode);
              }
              break;
              
          }
          return undefined;
        };
        
        b.dataFor = function (c) {
          var a = b.contextFor(c);
          return a?a.$data : undefined;
        };
        
        b.exportSymbol('ko.bindingHandlers',b.bindingHandlers);
        
        b.exportSymbol('ko.applyBindings',b.applyBindings);
        
        b.exportSymbol('ko.applyBindingsToDescendants',b.applyBindingsToDescendants);
        
        b.exportSymbol('ko.applyBindingsToNode',b.applyBindingsToNode);
        
        b.exportSymbol('ko.contextFor',b.contextFor);
        
        b.exportSymbol('ko.dataFor',b.dataFor);
      }();
      
      var g = ['click'];
      
      b.utils.arrayForEach(g,
      function (a) {
        b.bindingHandlers[a] =  {
          'init' : function (g,c,e,f) {
            var d = function () {
                  var d = {};
                  
                  d[a] = c();
                  return d;
                };
            return b.bindingHandlers['event']['init'].call(this,g,d,e,f);
          }
        };
      });
      
      b.bindingHandlers.event =  {
        'init' : function (f,a,d,c) {
          var g = a() || {};
          
          for (var e in g){
            
            (function () {
              var g = e;
              
              if (typeof g == "string"){
                
                b.utils.registerEventHandler(f,g,
                function (m) {
                  var l;
                  
                  var k = a()[g];
                  
                  if (!k){
                    return ;
                  }
                  
                  var i = d();
                  
                  try {
                    
                    var j = b.utils.makeArray(arguments);
                    
                    j.unshift(c);
                    
                    l = k.apply(c,j);
                  } finally {
                    
                    if (l !== true){
                      
                      if (m.preventDefault){
                        
                        m.preventDefault();
                      } else m.returnValue = false;
                    }
                    
                  }
                  
                  var h = i[g+'Bubble'] !== false;
                  
                  if (!h){
                    
                    m.cancelBubble = true;
                    
                    if (m.stopPropagation){
                      
                      m.stopPropagation();
                    }
                    
                  }
                  
                });
              }
              
            })();
          }
          
        }
      };
      
      b.bindingHandlers.submit =  {
        'init' : function (a,d,e,c) {
          if (typeof d() != "function"){
            throw new Error("The value for a submit binding must be a function");
          }
          
          b.utils.registerEventHandler(a,"submit",
          function (g) {
            var f;
            
            var e = d();
            
            try {
              
              f = e.call(c,a);
            } finally {
              
              if (f !== true){
                
                if (g.preventDefault){
                  
                  g.preventDefault();
                } else g.returnValue = false;
              }
              
            }
            
          });
        }
      };
      
      b.bindingHandlers.visible =  {
        'update' : function (e,d) {
          var c = b.utils.unwrapObservable(d());
          
          var a = !(e.style.display == "none");
          
          if (c && !a){
            
            e.style.display = "";
          } else if ((!c) && a){
            
            e.style.display = "none";
          }
          
        }
      };
      
      b.bindingHandlers.enable =  {
        'update' : function (d,c) {
          var a = b.utils.unwrapObservable(c());
          
          if (a && d.disabled){
            
            d.removeAttribute("disabled");
          } else if ((!a) && (!d.disabled)){
            
            d.disabled = true;
          }
          
        }
      };
      
      b.bindingHandlers.disable =  {
        'update' : function (c,a) {
          b.bindingHandlers['enable']['update'](c,
          function () {
            return !b.utils.unwrapObservable(a());
          });
        }
      };
      
      b.bindingHandlers.value =  {
        'init' : function (d,a,c) {
          var f = ["change"];
          
          var e = c()["valueUpdate"];
          
          if (e){
            
            if (typeof e == "string"){
              
              e = [e];
            }
            
            b.utils.arrayPushAll(f,e);
            
            f = b.utils.arrayGetDistinctValues(f);
          }
          
          b.utils.arrayForEach(f,
          function (g) {
            var f = false;
            
            if (b.utils.stringStartsWith(g,"after")){
              
              f = true;
              
              g = g.substring("after".length);
            }
            
            var e = f?function (a) {
                  setTimeout(a,0);
                } : function (a) {
                  a();
                };
            
            b.utils.registerEventHandler(d,g,
            function () {
              e(function () {
                var g = a();
                
                var f = b.selectExtensions.readValue(d);
                
                if (b.isWriteableObservable(g)){
                  
                  g(f);
                } else {
                  
                  var e = c();
                  if (e['_ko_property_writers'] && e['_ko_property_writers']['value']){
                    
                    e['_ko_property_writers']['value'](f);
                  }
                  
                }
                
              });
            });
          });
        },
        'update' : function (c,k) {
          var a = b.utils.unwrapObservable(k());
          
          var j = b.selectExtensions.readValue(c);
          
          var i = (a != j);
          
          if ((a === 0) && (j !== 0) && (j !== "0")){
            
            i = true;
          }
          
          if (i){
            
            var h = function () {
                  b.selectExtensions.writeValue(c,a);
                };
            
            h();
            
            var g = c.tagName == "SELECT";
            
            if (g){
              
              setTimeout(h,0);
            }
            
          }
          
          if ((c.tagName == "SELECT") && (c.length>0)){
            
            f(c,a,false);
          }
          
        }
      };
      
      b.bindingHandlers.options =  {
        'update' : function (s,q,j) {
          if (s.tagName != "SELECT"){
            throw new Error("options binding applies only to SELECT elements");
          }
          
          var r = s.length == 0;
          
          var e = b.utils.arrayMap(b.utils.arrayFilter(s.childNodes,
              function (a) {
                return a.tagName && a.tagName == "OPTION" && a.selected;
              }),
              function (a) {
                return b.selectExtensions.readValue(a) || a.innerText || a.textContent;
              });
          
          var p = s.scrollTop;
          
          s.scrollTop = 0;
          
          var o = b.utils.unwrapObservable(q());
          
          var l = s.value;
          
          while (s.length>0){
            
            b.cleanNode(s.options[0]);
            
            s.remove(0);
          }
          
          if (o){
            
            var i = j();
            
            if (typeof o.length != "number"){
              
              o = [o];
            }
            
            if (i['optionsCaption']){
              
              var h = document.createElement("OPTION");
              
              b.utils.setHtml(h,i['optionsCaption']);
              
              b.selectExtensions.writeValue(h,undefined);
              
              s.appendChild(h);
            }
            
            for (var k = 0,n = o.length;k<n;k ++ ){
              
              var h = document.createElement("OPTION");
              
              var m = typeof i['optionsValue'] == "string"?o[k][i['optionsValue']] : o[k];
              
              m = b.utils.unwrapObservable(m);
              
              b.selectExtensions.writeValue(h,m);
              
              var g = i['optionsText'];
              
              var d;
              
              if (typeof g == "function"){
                
                d = g(o[k]);
              } else if (typeof g == "string"){
                
                d = o[k][g];
              } else d = m;
              
              if ((d === null) || (d === undefined)){
                
                d = "";
              }
              
              b.utils.setTextContent(h,d);
              
              s.appendChild(h);
            }
            
            var c = s.getElementsByTagName("OPTION");
            
            var a = 0;
            
            for (var k = 0,n = c.length;k<n;k ++ ){
              
              if (b.utils.arrayIndexOf(e,b.selectExtensions.readValue(c[k])) >= 0){
                
                b.utils.setOptionNodeSelectionState(c[k],true);
                
                a ++ ;
              }
              
            }
            
            if (p){
              
              s.scrollTop = p;
            }
            
            if (r && ('value' in i)){
              
              f(s,b.utils.unwrapObservable(i['value']),true);
            }
            
          }
          
        }
      };
      
      b.bindingHandlers.options.optionValueDomDataKey = '__ko.optionValueDomData__';
      
      b.bindingHandlers.selectedOptions =  {
        getSelectedValuesFromSelectNode : function (g) {
          var f = [];
          
          var e = g.childNodes;
          
          for (var c = 0,d = e.length;c<d;c ++ ){
            
            var a = e[c];
            
            if ((a.tagName == "OPTION") && a.selected){
              
              f.push(b.selectExtensions.readValue(a));
            }
            
          }
          return f;
        },
        'init' : function (d,c,a) {
          b.utils.registerEventHandler(d,"change",
          function () {
            var e = c();
            
            if (b.isWriteableObservable(e)){
              
              e(b.bindingHandlers['selectedOptions'].getSelectedValuesFromSelectNode(this));
            } else {
              
              var d = a();
              if (d['_ko_property_writers'] && d['_ko_property_writers']['value']){
                
                d['_ko_property_writers']['value'](b.bindingHandlers['selectedOptions'].getSelectedValuesFromSelectNode(this));
              }
              
            }
            
          });
        },
        'update' : function (h,e) {
          if (h.tagName != "SELECT"){
            throw new Error("values binding applies only to SELECT elements");
          }
          
          var d = b.utils.unwrapObservable(e());
          
          if (d && typeof d.length == "number"){
            
            var g = h.childNodes;
            
            for (var c = 0,f = g.length;c<f;c ++ ){
              
              var a = g[c];
              
              if (a.tagName == "OPTION"){
                
                b.utils.setOptionNodeSelectionState(a,b.utils.arrayIndexOf(d,b.selectExtensions.readValue(a)) >= 0);
              }
              
            }
            
          }
          
        }
      };
      
      b.bindingHandlers.text =  {
        'update' : function (c,a) {
          b.utils.setTextContent(c,a());
        }
      };
      
      b.bindingHandlers.html =  {
        'init' : function () {
          return  {
            'controlsDescendantBindings' : true
          };
        },
        'update' : function (d,c) {
          var a = b.utils.unwrapObservable(c());
          
          b.utils.setHtml(d,a);
        }
      };
      
      b.bindingHandlers.css =  {
        'update' : function (f,e) {
          var d = b.utils.unwrapObservable(e() || {});
          
          for (var c in d){
            
            if (typeof c == "string"){
              
              var a = b.utils.unwrapObservable(d[c]);
              
              b.utils.toggleDomNodeCssClass(f,c,a);
            }
            
          }
          
        }
      };
      
      b.bindingHandlers.style =  {
        'update' : function (f,e) {
          var d = b.utils.unwrapObservable(e() || {});
          
          for (var c in d){
            
            if (typeof c == "string"){
              
              var a = b.utils.unwrapObservable(d[c]);
              
              f.style[c] = a || "";
            }
            
          }
          
        }
      };
      
      b.bindingHandlers.uniqueName =  {
        'init' : function (c,a) {
          if (a()){
            
            c.name = "ko_unique_"+( ++ b.bindingHandlers['uniqueName'].currentIndex);
            
            if (b.utils.isIe6 || b.utils.isIe7){
              
              c.mergeAttributes(document.createElement("<input name='"+c.name+"'/>"),false);
            }
            
          }
          
        }
      };
      
      b.bindingHandlers.uniqueName.currentIndex = 0;
      
      b.bindingHandlers.checked =  {
        'init' : function (d,c,a) {
          var e = function () {
                var h;
                
                if (d.type == "checkbox"){
                  
                  h = d.checked;
                } else if ((d.type == "radio") && (d.checked)){
                  
                  h = d.value;
                } else {
                  return ;
                }
                
                var g = c();
                
                if ((d.type == "checkbox") && (b.utils.unwrapObservable(g) instanceof Array)){
                  
                  var f = b.utils.arrayIndexOf(b.utils.unwrapObservable(g),d.value);
                  
                  if (d.checked && (f<0)){
                    
                    g.push(d.value);
                  } else if ((!d.checked) && (f >= 0)){
                    
                    g.splice(f,1);
                  }
                  
                } else if (b.isWriteableObservable(g)){
                  if (g() !== h){
                    
                    g(h);
                  }
                  
                } else {
                  
                  var e = a();
                  if (e['_ko_property_writers'] && e['_ko_property_writers']['checked']){
                    
                    e['_ko_property_writers']['checked'](h);
                  }
                  
                }
                
              };
          
          b.utils.registerEventHandler(d,"click",e);
          
          if ((d.type == "radio") && !d.name){
            
            b.bindingHandlers['uniqueName']['init'](d,
            function () {
              return true;
            });
          }
          
        },
        'update' : function (d,c) {
          var a = b.utils.unwrapObservable(c());
          
          if (d.type == "checkbox"){
            
            if (a instanceof Array){
              
              d.checked = b.utils.arrayIndexOf(a,d.value) >= 0;
            } else {
              
              d.checked = a;
            }
            
          } else if (d.type == "radio"){
            
            d.checked = (d.value == a);
          }
          
        }
      };
      
      b.bindingHandlers.attr =  {
        'update' : function (g,e,d) {
          var c = b.utils.unwrapObservable(e()) || {};
          
          for (var f in c){
            
            if (typeof f == "string"){
              
              var a = b.utils.unwrapObservable(c[f]);
              
              if ((a === false) || (a === null) || (a === undefined)){
                
                g.removeAttribute(f);
              } else g.setAttribute(f,a.toString());
            }
            
          }
          
        }
      };
      
      b.bindingHandlers.hasfocus =  {
        'init' : function (e,c,a) {
          var d = function (f) {
                var e = c();
                
                if (f == b.utils.unwrapObservable(e)){
                  return ;
                }
                
                if (b.isWriteableObservable(e)){
                  
                  e(f);
                } else {
                  
                  var d = a();
                  if (d['_ko_property_writers'] && d['_ko_property_writers']['hasfocus']){
                    
                    d['_ko_property_writers']['hasfocus'](f);
                  }
                  
                }
                
              };
          
          b.utils.registerEventHandler(e,"focus",
          function () {
            d(true);
          });
          
          b.utils.registerEventHandler(e,"focusin",
          function () {
            d(true);
          });
          
          b.utils.registerEventHandler(e,"blur",
          function () {
            d(false);
          });
          
          b.utils.registerEventHandler(e,"focusout",
          function () {
            d(false);
          });
        },
        'update' : function (d,c) {
          var a = b.utils.unwrapObservable(c());
          
          a?d.focus() : d.blur();
          
          b.utils.triggerEvent(d,a?"focusin" : "focusout");
        }
      };
      
      b.bindingHandlers['with'] =  {
        makeTemplateValueAccessor : function (a) {
          return function () {
            var c = a();
            return  {
              'if' : c,
              'data' : c,
              'templateEngine' : b.nativeTemplateEngine.instance
            };
          };
        },
        'init' : function (f,e,c,d,a) {
          return b.bindingHandlers['template']['init'](f,b.bindingHandlers['with'].makeTemplateValueAccessor(e));
        },
        'update' : function (f,e,c,d,a) {
          return b.bindingHandlers['template']['update'](f,b.bindingHandlers['with'].makeTemplateValueAccessor(e),c,d,a);
        }
      };
      
      b.jsonExpressionRewriting.bindingRewriteValidators['with'] = false;
      
      b.virtualElements.allowedBindings['with'] = true;
      
      b.bindingHandlers['if'] =  {
        makeTemplateValueAccessor : function (a) {
          return function () {
            return  {
              'if' : a(),
              'templateEngine' : b.nativeTemplateEngine.instance
            };
          };
        },
        'init' : function (f,e,c,d,a) {
          return b.bindingHandlers['template']['init'](f,b.bindingHandlers['if'].makeTemplateValueAccessor(e));
        },
        'update' : function (f,e,c,d,a) {
          return b.bindingHandlers['template']['update'](f,b.bindingHandlers['if'].makeTemplateValueAccessor(e),c,d,a);
        }
      };
      
      b.jsonExpressionRewriting.bindingRewriteValidators['if'] = false;
      
      b.virtualElements.allowedBindings['if'] = true;
      
      b.bindingHandlers.ifnot =  {
        makeTemplateValueAccessor : function (a) {
          return function () {
            return  {
              'ifnot' : a(),
              'templateEngine' : b.nativeTemplateEngine.instance
            };
          };
        },
        'init' : function (f,e,c,d,a) {
          return b.bindingHandlers['template']['init'](f,b.bindingHandlers['ifnot'].makeTemplateValueAccessor(e));
        },
        'update' : function (f,e,c,d,a) {
          return b.bindingHandlers['template']['update'](f,b.bindingHandlers['ifnot'].makeTemplateValueAccessor(e),c,d,a);
        }
      };
      
      b.jsonExpressionRewriting.bindingRewriteValidators.ifnot = false;
      
      b.virtualElements.allowedBindings.ifnot = true;
      
      b.bindingHandlers.foreach =  {
        makeTemplateValueAccessor : function (a) {
          return function () {
            var c = b.utils.unwrapObservable(a());
            
            if ((!c) || typeof c.length == "number"){
              return  {
                'foreach' : c,
                'templateEngine' : b.nativeTemplateEngine.instance
              };
            }
            return  {
              'foreach' : c['data'],
              'includeDestroyed' : c['includeDestroyed'],
              'afterAdd' : c['afterAdd'],
              'beforeRemove' : c['beforeRemove'],
              'afterRender' : c['afterRender'],
              'templateEngine' : b.nativeTemplateEngine.instance
            };
          };
        },
        'init' : function (f,e,c,d,a) {
          return b.bindingHandlers['template']['init'](f,b.bindingHandlers['foreach'].makeTemplateValueAccessor(e));
        },
        'update' : function (f,e,c,d,a) {
          return b.bindingHandlers['template']['update'](f,b.bindingHandlers['foreach'].makeTemplateValueAccessor(e),c,d,a);
        }
      };
      
      b.jsonExpressionRewriting.bindingRewriteValidators.foreach = false;
      
      b.virtualElements.allowedBindings.foreach = true;
      
      b.exportSymbol('ko.allowedVirtualElementBindings',b.virtualElements.allowedBindings);
      
      b.templateEngine = function (){};
      
      b.templateEngine.prototype.renderTemplateSource = function (c,b,a) {
        throw "Override renderTemplateSource";
      };
      
      b.templateEngine.prototype.createJavaScriptEvaluatorBlock = function (a) {
        throw "Override createJavaScriptEvaluatorBlock";
      };
      
      b.templateEngine.prototype.makeTemplateSource = function (c) {
        if (typeof c == "string"){
          
          var a = document.getElementById(c);
          
          if (!a)throw new Error("Cannot find template with ID "+c);
          return new b.templateSources.domElement(a);
        } else if ((c.nodeType == 1) || (c.nodeType == 8))return new b.templateSources.anonymousTemplate(c);
      };
      
      b.templateEngine.prototype.renderTemplate = function (d,c,b) {
        var a = this.makeTemplateSource(d);
        return this.renderTemplateSource(a,c,b);
      };
      
      b.templateEngine.prototype.isTemplateRewritten = function (a) {
        if (this.allowTemplateRewriting === false)return true;
        
        if (this.knownRewrittenTemplates && this.knownRewrittenTemplates[a])return true;
        return this.makeTemplateSource(a).data("isRewritten");
      };
      
      b.templateEngine.prototype.rewriteTemplate = function (d,c) {
        var a = this.makeTemplateSource(d),
            b = c(a.text());
        
        a.text(b);
        
        a.data("isRewritten",true);
        
        if (typeof d == "string"){
          
          this.knownRewrittenTemplates = this.knownRewrittenTemplates || {};
          
          this.knownRewrittenTemplates[d] = true;
        }
        
      };
      
      b.exportSymbol('ko.templateEngine',b.templateEngine);
      
      b.templateRewriting = function () {
        function c(h,g,f) {
          var e = b.jsonExpressionRewriting.parseObjectLiteral(h);
          
          a(e);
          
          var d = b.jsonExpressionRewriting.insertPropertyAccessorsIntoJson(e),
              c = "ko.templateRewriting.applyMemoizedBindingsToNextSibling(function() { \
            return (function() { return { "+d+" } })() \
        })";
          return f.createJavaScriptEvaluatorBlock(c)+g;
        }
        function a(g) {
          var f = b.jsonExpressionRewriting.bindingRewriteValidators;
          
          for (var d = 0;d<g.length;d ++ ){
            
            var c = g[d].key;
            
            if (f.hasOwnProperty(c)){
              
              var a = f[c];
              
              if (typeof a === "function"){
                
                var e = a(g[d].value);
                
                if (e)throw new Error(e);
              } else if (!a)throw new Error("This template engine does not support the '"+c+"' binding within its templates");
            }
            
          }
          
        }
        var e = /(<[a-z]+\d*(\s+(?!data-bind=)[a-z0-9\-]+(=(\"[^\"]*\"|\'[^\']*\'))?)*\s+)data-bind=(["'])([\s\S]*?)\5/gi,
            d = /<!--\s*ko\b\s*([\s\S]*?)\s*-->/g;
        return  {
          ensureTemplateIsRewritten : function (c,a) {
            if (!a['isTemplateRewritten'](c)){
              
              a['rewriteTemplate'](c,
              function (c) {
                return b.templateRewriting.memoizeBindingAttributeSyntax(c,a);
              });
            }
            
          },
          memoizeBindingAttributeSyntax : function (f,a) {
            return f.replace(e,
            function () {
              return c(arguments[6],arguments[1],a);
            }).replace(d,
            function () {
              return c(arguments[1],"<!-- ko -->",a);
            });
          },
          applyMemoizedBindingsToNextSibling : function (a) {
            return b.memoization.memoize(function (d,c) {
              if (d.nextSibling){
                
                b.applyBindingsToNode(d.nextSibling,a,c);
              }
              
            });
          }
        };
      }();
      
      b.exportSymbol('ko.templateRewriting',b.templateRewriting);
      
      b.exportSymbol('ko.templateRewriting.applyMemoizedBindingsToNextSibling',b.templateRewriting.applyMemoizedBindingsToNextSibling);
      
      !function () {
        b.templateSources = {};
        
        b.templateSources.domElement = function (a) {
          this.domElement = a;
        };
        
        b.templateSources.domElement.prototype.text = function () {
          if (arguments.length == 0)return this.domElement.tagName.toLowerCase() == "script"?this.domElement.text : this.domElement.innerHTML;
          
          {
            
            var a = arguments[0];
            
            this.domElement.tagName.toLowerCase() == "script"?this.domElement.text = a : b.utils.setHtml(this.domElement,a);
          }
          
        };
        
        b.templateSources.domElement.prototype.data = function (a) {
          if (arguments.length === 1)return b.utils.domData.get(this.domElement,"templateSourceData_"+a);
          
          b.utils.domData.set(this.domElement,"templateSourceData_"+a,arguments[1]);
        };
        
        var a = "__ko_anon_template__";
        
        b.templateSources.anonymousTemplate = function (a) {
          this.domElement = a;
        };
        
        b.templateSources.anonymousTemplate.prototype = new b.templateSources.domElement();
        
        b.templateSources.anonymousTemplate.prototype.text = function () {
          if (arguments.length == 0)return b.utils.domData.get(this.domElement,a);
          
          {
            
            var c = arguments[0];
            
            b.utils.domData.set(this.domElement,a,c);
          }
          
        };
        
        b.exportSymbol('ko.templateSources',b.templateSources);
        
        b.exportSymbol('ko.templateSources.domElement',b.templateSources.domElement);
        
        b.exportSymbol('ko.templateSources.anonymousTemplate',b.templateSources.anonymousTemplate);
      }();
      
      !function () {
        function g(i,h) {
          var g = b.utils.domData.get(i,f);
          
          g && (typeof (g.dispose) == 'function') && g.dispose();
          
          b.utils.domData.set(i,f,h);
        }
        function d(j,i,h,g,f) {
          f = f || {};
          
          var e = (f.templateEngine || a);
          
          b.templateRewriting.ensureTemplateIsRewritten(h,e);
          
          var c = e.renderTemplate(h,g,f);
          
          if ((typeof c.length != "number") || (c.length>0 && typeof c[0].nodeType != "number"))throw "Template engine must return an array of DOM nodes";
          
          var d = false;
          
          switch (i) {
            case "replaceChildren" :
              
              b.virtualElements.setDomNodeChildren(j,c);
              
              d = true;
              break;
            case "replaceNode" :
              
              b.utils.replaceDomNodes(j,c);
              
              d = true;
              break;
            case "ignoreTargetNode" :
              break;
            default :
              throw new Error("Unknown renderMode: "+i);
              
          }
          
          if (d){
            
            b.activateBindingsOnTemplateRenderedNodes(c,g);
            
            f.afterRender && f.afterRender(c,g.$data);
          }
          return c;
        }
        function e(a) {
          return a.nodeType?a : a.length>0?a[0] : null;
        }
        function c(d,c,b) {
          for (var a = 0;node = d[a];a ++ ){
            
            if (node.parentNode !== c)continue ;
            
            ((node.nodeType === 1) || (node.nodeType === 8)) && b(node);
          }
          
        }
        var a;
        
        b.setTemplateEngine = function (c) {
          if ((c != undefined) && !(c instanceof b.templateEngine))throw "templateEngine must inherit from ko.templateEngine";
          
          a = c;
        };
        
        b.activateBindingsOnTemplateRenderedNodes = function (f,a) {
          var e = b.utils.arrayPushAll([],f),
              d = (f.length>0)?f[0].parentNode : null;
          
          c(e,d,
          function (c) {
            b.applyBindings(a,c);
          });
          
          c(e,d,
          function (c) {
            b.memoization.unmemoizeDomNodeAndDescendants(c,[a]);
          });
        };
        
        b.renderTemplate = function (g,j,f,i,h) {
          f = f || {};
          
          if ((f.templateEngine || a) == undefined)throw "Set a template engine before calling renderTemplate";
          
          h = h || "replaceChildren";
          
          if (i){
            
            var c = e(i);
            
            var l = function () {
                  return (!c) || !b.utils.domNodeIsAttachedToDocument(c);
                };
            
            var k = (c && h == "replaceNode")?c.parentNode : c;
            return new b.dependentObservable(function () {
              var m = (j && (j instanceof b.bindingContext))?j : new b.bindingContext(b.utils.unwrapObservable(j)),
                  l = typeof (g) == 'function'?g(m.$data) : g,
                  k = d(i,h,l,m,f);
              
              if (h == "replaceNode"){
                
                i = k;
                
                c = e(i);
              }
              
            },null, {
              'disposeWhen' : l,
              'disposeWhenNodeIsRemoved' : k
            });
          } else return b.memoization.memoize(function (a) {
            b.renderTemplate(g,j,f,a,"replaceNode");
          });
        };
        
        b.renderTemplateForEach = function (i,g,c,h,a) {
          var e = function (c) {
                return a.createChildContext(b.utils.unwrapObservable(c));
              },
              f = function (h,g) {
                var f = e(h);
                
                b.activateBindingsOnTemplateRenderedNodes(g,f);
                
                c.afterRender && c.afterRender(g,f.$data);
              };
          return new b.dependentObservable(function () {
            var k = b.utils.unwrapObservable(g) || [];
            
            typeof k.length == "undefined" && (k = [k]);
            
            var j = b.utils.arrayFilter(k,
                function (a) {
                  return c.includeDestroyed || a === undefined || a === null || !b.utils.unwrapObservable(a._destroy);
                });
            
            b.utils.setDomNodeChildrenFromArrayMapping(h,j,
            function (b) {
              var a = typeof (i) == 'function'?i(b) : i;
              return d(null,"ignoreTargetNode",a,e(b),c);
            },c,f);
          },null, {
            'disposeWhenNodeIsRemoved' : h
          });
        };
        
        var f = '__ko__templateSubscriptionDomDataKey__';
        
        b.bindingHandlers.template =  {
          'init' : function (d,c) {
            var a = b.utils.unwrapObservable(c());
            
            if ((typeof a != "string") && (!a.name) && (d.nodeType == 1)){
              
              new b.templateSources.anonymousTemplate(d).text(d.innerHTML);
              
              b.utils.emptyDomNode(d);
            }
            return  {
              'controlsDescendantBindings' : true
            };
          },
          'update' : function (r,k,o,q,h) {
            var p = b.utils.unwrapObservable(k());
            
            var m;
            
            var l = true;
            
            if (typeof p == "string"){
              
              m = p;
            } else {
              
              m = p.name;
              if ('if' in p){
                
                l = l && b.utils.unwrapObservable(p['if']);
              }
              if ('ifnot' in p){
                
                l = l && !b.utils.unwrapObservable(p['ifnot']);
              }
              
            }
            
            var j = null;
            
            if ((typeof p === 'object') && ('foreach' in p)){
              
              var i = (l && p['foreach']) || [];
              
              j = b.renderTemplateForEach(m || r,i,p,r,h);
            } else {
              if (l){
                
                var n = (typeof p == 'object') && ('data' in p)?h['createChildContext'](b.utils.unwrapObservable(p['data'])) : h;
                
                j = b.renderTemplate(m || r,n,p,r);
              } else b.virtualElements.emptyNode(r);
            }
            
            g(r,j);
          }
        };
        
        b.jsonExpressionRewriting.bindingRewriteValidators.template = function (c) {
          var a = b.jsonExpressionRewriting.parseObjectLiteral(c);
          
          if ((a.length == 1) && a[0].unknown)return null;
          
          if (b.jsonExpressionRewriting.keyValueArrayContainsKey(a,"name"))return null;
          return "This template engine does not support anonymous templates nested within its templates";
        };
        
        b.virtualElements.allowedBindings.template = true;
      }();
      
      b.exportSymbol('ko.setTemplateEngine',b.setTemplateEngine);
      
      b.exportSymbol('ko.renderTemplate',b.renderTemplate);
      
      !function () {
        function a(k,i,b) {
          var h = i.length,
              f = b.length,
              j = [],
              d = k[f][h];
          
          if (d === undefined)return null;
          
          while ((h>0) || (f>0)){
            
            var g = k[f][h];
            
            var e = (f>0)?k[f-1][h] : d+1;
            
            var c = (h>0)?k[f][h-1] : d+1;
            
            var a = (f>0) && (h>0)?k[f-1][h-1] : d+1;
            
            ((e === undefined) || (e<g-1)) && (e = d+1);
            
            ((c === undefined) || (c<g-1)) && (c = d+1);
            
            a<g-1 && (a = d+1);
            
            if ((e <= c) && (e<a)){
              
              j.push( {
                status : "added",
                value : b[f-1]
              });
              
              f -- ;
            } else if ((c<e) && (c<a)){
              
              j.push( {
                status : "deleted",
                value : i[h-1]
              });
              
              h -- ;
            } else {
              
              j.push( {
                status : "retained",
                value : i[h-1]
              });
              
              f -- ;
              
              h -- ;
            }
            
          }
          return j.reverse();
        }
        function c(p,g,o) {
          var m = [];
          
          for (var l = 0;l <= g.length;l ++ )
          m[l] = [];
          
          for (var l = 0,n = Math.min(p.length,o);l <= n;l ++ )
          m[0][l] = l;
          
          for (var l = 1,n = Math.min(g.length,o);l <= n;l ++ )
          m[l][0] = l;
          
          var k,
              i = p.length,
              e,
              h = g.length,
              c,
              a;
          
          for (k = 1;k <= i;k ++ ){
            
            var j = Math.max(1,k-o);
            
            var f = Math.min(h,k+o);
            
            for (e = j;e <= f;e ++ )if (p[k-1] === g[e-1])m[e][k] = m[e-1][k-1];
             else {
              
              var d = m[e-1][k] === undefined?Number.MAX_VALUE : m[e-1][k]+1;
              
              var b = m[e][k-1] === undefined?Number.MAX_VALUE : m[e][k-1]+1;
              
              m[e][k] = Math.min(d,b);
            }
            
          }
          return m;
        }
        b.utils.compareArrays = function (g,f,e) {
          if (e === undefined)return b.utils.compareArrays(g,f,1) || b.utils.compareArrays(g,f,10) || b.utils.compareArrays(g,f,Number.MAX_VALUE);
          
          {
            
            g = g || [];
            
            f = f || [];
            
            var d = c(g,f,e);
            return a(d,g,f);
          }
          
        };
      }();
      
      b.exportSymbol('ko.utils.compareArrays',b.utils.compareArrays);
      
      !function () {
        function c(h,f,e,c) {
          var d = [],
              g = b.dependentObservable(function () {
                var g = f(e) || [];
                
                if (d.length>0){
                  
                  a(d);
                  
                  b.utils.replaceDomNodes(d,g);
                  
                  c && c(e,g);
                }
                
                d.splice(0,d.length);
                
                b.utils.arrayPushAll(d,g);
              },null, {
                'disposeWhenNodeIsRemoved' : h,
                'disposeWhen' : function () {
                  return (d.length == 0) || !b.utils.domNodeIsAttachedToDocument(d[0]);
                }
              });
          return  {
            mappedNodes : d,
            dependentObservable : g
          };
        }
        function a(d) {
          if (d.length>2){
            
            var a = d[0],
                c = d[d.length-1],
                b = [a];
            
            while (a !== c){
              
              a = a.nextSibling;
              
              if (!a)return ;
              
              b.push(a);
            }
            
            [].splice.apply(d,[0,d.length].concat(b));
          }
          
        }
        var d = "setDomNodeChildrenFromArrayMapping_lastMappingResult";
        
        b.utils.setDomNodeChildrenFromArrayMapping = function (o,p,z,v,r) {
          p = p || [];
          
          v = v || {};
          
          var x = b.utils.domData.get(o,d) === undefined,
              B = b.utils.domData.get(o,d) || [],
              u = b.utils.arrayMap(B,
              function (a) {
                return a.arrayEntry;
              }),
              f = b.utils.compareArrays(u,p),
              q = [],
              m = 0,
              h = [],
              s = [],
              e = null;
          
          for (var g = 0,w = f.length;g<w;g ++ )
          switch (f[g].status) {
            case "retained" :
              
              var n = B[m];
              
              q.push(n);
              
              n.domNodes.length>0 && (e = n.domNodes[n.domNodes.length-1]);
              
              m ++ ;
              break;
            case "deleted" :
              
              B[m].dependentObservable.dispose();
              
              a(B[m].domNodes);
              
              b.utils.arrayForEach(B[m].domNodes,
              function (i) {
                h.push( {
                  element : i,
                  index : g,
                  value : f[g].value
                });
                
                e = i;
              });
              
              m ++ ;
              break;
            case "added" :
              
              var k = f[g].value;
              
              var j = c(o,z,k,r);
              
              var t = j.mappedNodes;
              
              q.push( {
                arrayEntry : f[g].value,
                domNodes : t,
                dependentObservable : j.dependentObservable
              });
              
              for (var y = 0,i = t.length;y<i;y ++ ){
                
                var A = t[y];
                
                s.push( {
                  element : A,
                  index : g,
                  value : f[g].value
                });
                
                if (e == null){
                  
                  b.virtualElements.prepend(o,A);
                } else {
                  
                  b.virtualElements.insertAfter(o,A,e);
                }
                
                e = A;
              }
              
              if (r){
                
                r(k,t);
              }
              break;
              
          }
          
          b.utils.arrayForEach(h,
          function (a) {
            b.cleanNode(a.element);
          });
          
          var l = false;
          
          if (!x){
            
            if (v.afterAdd)for (var g = 0;g<s.length;g ++ )
            v.afterAdd(s[g].element,s[g].index,s[g].value);
            
            if (v.beforeRemove){
              
              for (var g = 0;g<h.length;g ++ )v.beforeRemove(h[g].element,h[g].index,h[g].value);
              
              l = true;
            }
            
          }
          
          !l && b.utils.arrayForEach(h,
          function (a) {
            b.removeNode(a.element);
          });
          
          b.utils.domData.set(o,d,q);
        };
      }();
      
      b.exportSymbol('ko.utils.setDomNodeChildrenFromArrayMapping',b.utils.setDomNodeChildrenFromArrayMapping);
      
      b.nativeTemplateEngine = function () {
        this.allowTemplateRewriting = false;
      };
      
      b.nativeTemplateEngine.prototype = new b.templateEngine();
      
      b.nativeTemplateEngine.prototype.renderTemplateSource = function (e,d,c) {
        var a = e.text();
        return b.utils.parseHtmlFragment(a);
      };
      
      b.nativeTemplateEngine.instance = new b.nativeTemplateEngine();
      
      b.setTemplateEngine(b.nativeTemplateEngine.instance);
      
      b.exportSymbol('ko.nativeTemplateEngine',b.nativeTemplateEngine);
      
      !function () {
        b.jqueryTmplTemplateEngine = function () {
          function b(c,b,a) {
            return jQuery.tmpl(c,b,a);
          }
          function c() {
            if (a<2)throw new Error("Your version of jQuery.tmpl is too old. Please upgrade to jQuery.tmpl 1.0.0pre or later.");
          }
          var a = this.jQueryTmplVersion = function () {
                if ((typeof (jQuery) == "undefined") || !(jQuery.tmpl))return 0;
                
                try {
                  
                  if (jQuery.tmpl.tag.tmpl.open.toString().indexOf('__') >= 0)return 2;
                } catch(ex){
                  
                }
                return 1;
              }();
          
          this.renderTemplateSource = function (k,i,g) {
            g = g || {};
            
            c();
            
            var f = k.data('precompiled');
            
            if (!f){
              
              var e = k.text() || "";
              
              e = "{{ko_with $item.koBindingContext}}"+e+"{{/ko_with}}";
              
              f = jQuery.template(null,e);
              
              k.data('precompiled',f);
            }
            
            var j = [i['$data']],
                d = jQuery.extend( {
                  'koBindingContext' : i
                },g.templateOptions),
                h = b(f,j,d);
            
            h.appendTo(document.createElement("div"));
            
            jQuery.fragments = {};
            return h;
          };
          
          this.createJavaScriptEvaluatorBlock = function (a) {
            return "{{ko_code ((function() { return "+a+" })()) }}";
          };
          
          this.addTemplate = function (b,a) {
            document.write("<script type='text/html' id='"+b+"'>"+a+"</script>");
          };
          
          if (a>0){
            
            jQuery.tmpl.tag.ko_code =  {
              open : "__.push($1 || '');"
            };
            
            jQuery.tmpl.tag.ko_with =  {
              open : "with($1) {",
              close : "} "
            };
          }
          
        };
        
        b.jqueryTmplTemplateEngine.prototype = new b.templateEngine();
        
        var a = new b.jqueryTmplTemplateEngine();
        
        a.jQueryTmplVersion>0 && b.setTemplateEngine(a);
        
        b.exportSymbol('ko.jqueryTmplTemplateEngine',b.jqueryTmplTemplateEngine);
      }();
    }(window);
  }();
}();
