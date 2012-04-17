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
    c['-759650552-harmony_function_test.js'] = {};
    
    var d = c['-759650552-harmony_function_test.js'];
    
    !function () {
      function a() {
        return console.log(1);
      }
      function d() {
        return console.log(1);
      }
      function e() {
        console.log(1);
      }
      function c() {
        return console.log(1);
      }
      function n() {
        return console.log(1);
      }
      function f() {
        console.log(1);
      }
      function l() {
        return console.log(1);
      }
      function m() {
        return console.log(1);
      }
      function i() {
        return console.log(1);
      }
      function b() {
        return console.log(1);
      }
      function k() {
        console.log(1);
      }
      function j() {
        return console.log(1);
      }
      function p() {
        return console.log(1);
      }
      function o() {
        return console.log(1);
      }
      function g() {
        return console.log(1);
      }
      a = a.bind(this);
      
      d = d.bind(this);
      
      e = e.bind(this);
      
      l = l.bind(this);
      
      m = m.bind(this);
      
      j = j.bind(this);
      
      p = p.bind(this);
      
      var q = function () {
            return console.log(this);
          }.bind(this);
      
      var h = function (c,b,a) {
            c+b;
          },
          h = function (c,b,a) {
            return c+b;
          };
    }();
    
    !function () {
      function b(k,h,f,d) {
        d = a.toArray(arguments,3);
        
        var j = k.args,
            c = h.tmp && h.tmp["args2"]?h.tmp.args2 : undefined,
            b = f[0],
            g = f[1],
            e = f[2] && f[2].args5?f[2].args5 : undefined,
            i = f[2] && f[2].args6 && f[2].args6.args7?f[2].args6.args7 : undefined;
        return console.log(1);
      }
      function l(c,b,a) {
        return console.log(1);
      }
      function c(k,i,h,g) {
        g = a.toArray(arguments,3);
        
        var f = k.args,
            d = i.tmp && i.tmp["args2"]?i.tmp.args2 : undefined,
            c = h[0],
            b = h[1],
            j = h[2] && h[2].args5?h[2].args5 : undefined,
            e = h[2] && h[2].args6 && h[2].args6.args7?h[2].args6.args7 : undefined;
        
        console.log(1);
      }
      function f(c,b,a) {
        console.log(1);
      }
      function e(k,h,j,e) {
        e = a.toArray(arguments,3);
        
        var g = k.args,
            d = h.tmp && h.tmp["args2"]?h.tmp.args2 : undefined,
            c = j[0],
            i = j[1],
            b = j[2] && j[2].args5?j[2].args5 : undefined,
            f = j[2] && j[2].args6 && j[2].args6.args7?j[2].args6.args7 : undefined;
        return console.log(1);
      }
      function q(c,b,a) {
        return console.log(1);
      }
      function g(k,j,i,g) {
        g = a.toArray(arguments,3);
        
        var f = k.args,
            d = j.tmp && j.tmp["args2"]?j.tmp.args2 : undefined,
            c = i[0],
            b = i[1],
            h = i[2] && i[2].args5?i[2].args5 : undefined,
            e = i[2] && i[2].args6 && i[2].args6.args7?i[2].args6.args7 : undefined;
        
        console.log(1);
      }
      function h(c,b,a) {
        console.log(1);
      }
      function i(k,i,f,e) {
        e = a.toArray(arguments,3);
        
        var h = k.args,
            d = i.tmp && i.tmp["args2"]?i.tmp.args2 : undefined,
            c = f[0],
            j = f[1],
            b = f[2] && f[2].args5?f[2].args5 : undefined,
            g = f[2] && f[2].args6 && f[2].args6.args7?f[2].args6.args7 : undefined;
        return console.log(1);
      }
      function k(c,b,a) {
        return console.log(1);
      }
      function d(k,h,g,e) {
        e = a.toArray(arguments,3);
        
        var j = k.args,
            d = h.tmp && h.tmp["args2"]?h.tmp.args2 : undefined,
            c = g[0],
            b = g[1],
            f = g[2] && g[2].args5?g[2].args5 : undefined,
            i = g[2] && g[2].args6 && g[2].args6.args7?g[2].args6.args7 : undefined;
        return console.log(1);
      }
      function m(c,b,a) {
        return console.log(1);
      }
      function j(k,j,i,h) {
        h = a.toArray(arguments,3);
        
        var g = k.args,
            e = j.tmp && j.tmp["args2"]?j.tmp.args2 : undefined,
            d = i[0],
            c = i[1],
            b = i[2] && i[2].args5?i[2].args5 : undefined,
            f = i[2] && i[2].args6 && i[2].args6.args7?i[2].args6.args7 : undefined;
        
        console.log(1);
      }
      function o(c,b,a) {
        console.log(1);
      }
      function p(k,i,g,j) {
        j = a.toArray(arguments,3);
        
        var e = k.args,
            h = i.tmp && i.tmp["args2"]?i.tmp.args2 : undefined,
            f = g[0],
            c = g[1],
            b = g[2] && g[2].args5?g[2].args5 : undefined,
            d = g[2] && g[2].args6 && g[2].args6.args7?g[2].args6.args7 : undefined;
        return console.log(this);
      }
      function s(c,b,a) {
        return console.log(1);
      }
      function r(k,i,g,f) {
        f = a.toArray(arguments,3);
        
        var e = k.args,
            j = i.tmp && i.tmp["args2"]?i.tmp.args2 : undefined,
            h = g[0],
            c = g[1],
            b = g[2] && g[2].args5?g[2].args5 : undefined,
            d = g[2] && g[2].args6 && g[2].args6.args7?g[2].args6.args7 : undefined;
        return console.log(1);
      }
      function n(c,b,a) {
        return console.log(1);
      }
      b = b.bind(this);
      
      l = l.bind(this);
      
      c = c.bind(this);
      
      f = f.bind(this);
      
      i = i.bind(this);
      
      k = k.bind(this);
      
      p = p.bind(this);
      
      s = s.bind(this);
    }();
    
    !function () {
      function h(i,g,f,e,h,d,c,b) {
        
      }
      function d(i,g,f,e,h,d,c,b) {
        
      }
      function f(e,d,c,b) {
        
      }
      function g(e,d,c,b) {
        console.log(e === 1,e,d,c,b);
      }
      var i = [1,2,3,4];
      
      var b =  {
            invoke : function (f,e,d,c) {
              
            }
          };
      
      f.prototype.valid = true;
      
      a.spreadCall(undefined,g,[true,i],false);
      
      a.spreadCall(b,b.invoke,[true,i],false);
      
      a.spreadCall(undefined,f,[true,i],true);
      
      var e = [100,200];
      
      var c =  {
            invoke : function (k,i,h,g,j,f,e,d) {
              
            }
          };
      
      h.prototype.valid = true;
      
      a.spreadCall(undefined,d,[false,0,true,i,false,0,true,e],false);
      
      a.spreadCall(c,c.invoke,[false,0,true,i,false,0,true,e],false);
      
      a.spreadCall(undefined,h,[false,0,true,i,false,0,true,e],true);
    }();
  }();
}();
