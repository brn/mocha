!function(){var b={};!function (f,g,h,i){function l(a,b,c){return Object.defineProperty(a,b,{value:c,configurable:true,enumerable:false,writable:true});}function e(c,d){typeof c!=="function"&&b(d+" : first argument is not callable");}function b(a){try{throw new TypeError(a);} catch(e){throw new Error(e);};}var c=f.prototype,d=g.prototype,j=h.prototype,k=i.prototype;!Object.keys&&(Object.keys=function (a){!a&&b("Object.keys : first arguments is null or not defined.");var c=[],d=-1;for(var e in a)a.hasOwnProperty(e)&&(c[++d]=a[e]);return c;});!Object.preventExtensions&&(Object.preventExtensions=function (a){return a;});!Object.seal&&(Object.seal=function (a){return a;});!Object.freeze&&(Object.freeze=function (a){return a;});var m=function (){var a;try{var b={};Object.defineProperty(b,"test",{configurable:false,writable:false,enumerable:false,value:0});b.test=200;a=(b.test===200)?false:true;} catch(e){a=false;};return a;}();!m&&(Object.defineProperty=function (a,b,c){"value" in c&&(a[b]=c.value);});if(!c.trim){c.trim=function (){return this.replace(c.trim.rtrim,"");};c.trim.rtrim=/^\s*|\s*$/g;};!c.repeat&&l(c,"repeat",function (a){return Array(a+1).join(this.toString());});!c.startsWith&&l(c,"startsWith",function (a){return !this.indexOf(a);});!c.endsWith&&l(c,"endsWith",function (a){var b=String(a),c=this.lastIndexOf(b);return c>=0&&c===this.length-b.length;});!c.contains&&l(c,"contains",function (a){return this.indexOf(a)!==-1;});!c.toArray&&l(c,"toArray",function (a){return this.split("");});!j.bind&&l(j,"bind",function (){var a=d.slice.call(arguments),c=a.shift(),b=function (){var e=a.concat(d.slice.call(arguments));return this!==null&&this!==window&&this instanceof b?b.context.apply(this,e):b.context.apply(c,e);};b.prototype=this.prototype;b.context=this;return b;});!d.forEach&&l(d,"forEach",function (f,g){e(f,"Array.forEach");var h=-1,i;this===null&&b("Array.forEach : this is null or not defined");if(g)while((i=this[++h])!==null&&i!==undefined)f.call(g,i,h,this);else while((i=this[++h])!==null&&i!==undefined)f(i,h,this);});!d.every&&l(d,"every",function (a,c){e(a,"Array.every");var d=-1,f;this===null&&b("Array.every : this is null or not defined");if(c)while((f=this[++d])!==null&&f!==undefined)if(!(a.call(c,f,d,this)))return false;else while((f=this[++d])!==null&&f!==undefined)if(!(a(f,d,this)))return false;return true;});!d.some&&l(d,"some",function (a,c){e(a,"Array.some");var d=-1,f;this===null&&b("Array.some : this is null or not defined");if(c)while((f=this[++d])!==null&&f!==undefined)if(a.call(c,f,d,this))return true;else while((f=this[++d])!==null&&f!==undefined)if(a(f,d,this))return true;return false;});!d.filter&&l(d,"filter",function (a,c){e(a,"Array.filter");var d=this.length,f=-1,g=[],h;this===null&&b("Array.filter : this is null or not defined");if(c)for(var i=0,d=this.length;i<d;++i)(h=this[i])!==null&&h!==undefined&&a.call(c,h,i,this)&&(g[++f]=h);else for(var i=0,d=this.length;i<d;++i)(h=this[i])!==null&&h!==undefined&&a(h,i,this)&&(g[++f]=h);return g;});!d.indexOf&&l(d,"indexOf",function (a,c){var d=(c)?c-1:-1,e=-1,f;this===null&&b("Array.indexOf : this is null or not defined.");while((f=this[++d])!==null&&f!==undefined)if(f===a){e=d;break;};return e;});!d.lastIndexOf&&l(d,"lastIndexOf",function (a,c){var d=this.length,e=(c)?c+1:d,f=-1,g;this===null&&b("Array.lastIndexOf : this is null or not defined.");while((g=this[--e])!==null&&g!==undefined)if(g===a){f=e;break;};return f;});!d.map&&l(d,"map",function (a,c){e(a,"Array.map");var d=[],f=-1,g=this.length,h=0,i;this===null&&b("Array.map : this is null or not defined.");if(c)for(h;h<g;++h)(i=this[h])!==null&&i!==undefined&&(d[++f]=a.call(c,i,h,this));else for(h;h<g;++h)(i=this[h])!==null&&i!==undefined&&(d[++f]=a(i,h,this));return d;});!d.reduce&&l(d,"reduce",function (a,c){e(a,"Array.reduce");var d=c||this[0],f=(c)?0:1,g=this.length,h;(g===0||g===null)&&arguments.length<2&&b("Array length is 0 and no second argument");for(f;f<g;++f)(h=this[f])!==null&&h!==undefined&&(d=a(d,h,f,this));return d;});!d.reduceRight&&l(d,"reduceRight",function (a,c){e(a,"Array.reduceRight");var d=this.length,f=c||this[d-1],g=(c)?d-1:d-2,h;(d===0||d===null)&&arguments.length<2&&b("Array length is 0 and no second argument");for(g;g>-1;--g)(h=this[g])!==null&&h!==undefined&&(f=a(f,h,g,this));return f;});!k.toJSON&&l(k,"toJSON",function (){var a=[this.getUTCMonth(),this.getUTCDate(),this.getUTCHours(),this.getMinutes(),this.getSeconds()],b=a[0],c=a[1],d=a[2],e=a[3],f=a[4];return '"'+this.getUTCFullYear()+'-'+(b>8?b+1:"0"+(b+1))+'-'+(c>9?c:"0"+c)+'T'+(d>9?d:"0"+d)+':'+(e>9?e:"0"+e)+':'+(f>9?f:"0"+f)+'.'+this.getUTCMilliseconds()+'Z"';});!Date.now&&l(Date,"now",function (){return +new Date();});!Array.isArray&&l(Array,"isArray",function (a){if(arguments.length===0)return false;return (a)?({}).toString.call(a)==="[object Array]":false;});}.call(this,String,Array,Function,Date);var a=function (){"use strict";function L(b,c,d,e,f){var g=b.prototype,h=c.prototype;for(var i=0,j=d.length;i<j;i++){var k=d[i],l=k._mochaRequires;for(var m in l)!(m in g)&&!(m in h)&&a.throwException("Class dose not meet the traits requirement. traits require implementation of property "+m+"\nin file "+e+" at line "+f);};}function K(b,c,d,e,f){var g=b.prototype,h=c.prototype,i=d._mochaTraitMark,j=d._mochaTraitPublic,k=d._mochaTraitPrivate;if(!i)a.throwException("mixin only used for trait.");else {var l;for(var m in j)if(!f[m]){l=(!e[m])?m:e[m];g[l]=j[m];};for(m in k)if(!f[m]){l=(!e[m])?m:e[m];h[l]=k[m];};};}function J(b,c,d,e){if(!b._mochaTraitMark||!c._mochaTraitMark)a.throwException("mixin only used for trait.");else {var f=b._mochaTraitPrivate,g=c._mochaTraitPrivate,h=b._mochaTraitPublic,i=c._mochaTraitPublic,j=c._mochaRequires,k=b._mochaRequires,l;for(var m in g)if(!e[m]){l=(!d[m])?m:d[m];f[l]=g[m];};for(m in i)if(!e[m]){l=(!d[m])?m:d[m];h[l]=i[m];};for(m in j)k[m]=j[m];};}function I(a){var b=typeof a,c;if(b==="function"){c=function (){};c.prototype=a.prototype;c=new c();a.__harmony_class__?c.constructor=a.constructor:c.constructor=a;return c;};return c;}function H(r,s,t,u,v,w,x){(!r||!(r instanceof s))&&p("class "+w+" must be called by new. line : "+x);q(r,t);u.apply(r,v);}function b(o){return o===StopIteration||n.test(o);}function F(a){return k in a;}function E(n){var a=n[k](),o;if(l(a))return a;o={};if(a.next)f(o,"next",function (){var b=a.next();b===undefined&&m();return b;});else return {};!("__nothrowNext__" in a)&&f(o,"__nothrowNext__",a.next.bind(a));for(var p in a)p!=="next"&&p!=="__nothrowNext__"&&(o[p]=a[p]);!("toString" in a)&&f(o,"toString",function (){return "[object Iterator]";});return o;}function l(a){return a instanceof e;}function m(){try{throw StopIteration;} catch(e){throw new Error(e.toString());};}function B(a){a.toString()==="[object Object]"&&f(a,"toString",function (){return "[object Record]";});return Object.freeze(a);}function A(j,k){f(j,"length",k);f(j,"equal",h);f(j,"toArray",i);f(j,"toString",function (){return "[object Tuple]";});return Object.freeze(j);}function i(){return [].slice.call(this);}function h(h){var i=g(h.length,this.length),j=-1;while(++j<i&&h[j]===this[j]){};return i===j;}function z(a,b){for(var c in b)a[c]=b[c];return a;}function u(a){return (a.message)?a.message:(a.description)?a.description:a.toString();}function y(g,h,i){var j=new e;f(j,"next",g.bind(i,false,false));f(j,"send",g.bind(i,true,false));f(j,"close",h.bind(i));f(j,"__nothrowNext__",g.bind(i,false,true));f(j,"toString",function (){return "[object Generator]";});Object.freeze(j);return j;}function e(){}function x(e,f){return (e)?d.call(e,f):[];}function w(a,b,c){return Object.defineProperty(a,b,{configurable:false,enumerable:false,writable:false,value:c});}function f(a,b,c){return Object.defineProperty(a,b,{configurable:true,enumerable:false,writable:true,value:c});}function c(d,c,b){this.toString=function (){return a.getErrorMessage(b)+" in file "+c+" at : "+d;};}var r={};var s=Math,g=s.max,t=Array.prototype,d=t.slice,a={getErrorMessage:function u(a){return (a.message)?a.message:(a.description)?a.description:a.toString();},exceptionHandler:function v(d,e,f){b(f)?this.throwException(f):this.throwException(new c(d,e,f));},throwException:function p(a){try{throw a;} catch(e){if(b(e))throw new Error(e);throw new Error(this.getErrorMessage(e));};},hasProto:"__proto__" in {}};r.createUnenumProp=f;r.constant=w;r.toArray=x;r.createGenerator=y;var p=r.throwException=a.throwException.bind(a),v=r.exceptionHandler=a.exceptionHandler.bind(a);r.extend=z;r.createTuple=A;r.createRecord=B;var C=r.extendPrototype=function (a,b){a.prototype=b;},j=("getPrototypeOf" in Object)?function (a){return Object.getPrototypeOf(a);}:function (a){var b={};for(var c in a)!a.hasOwnProperty(c)&&(b[c]=a[c]);return b;},D=r.extendClass=(a.hasProto)?function (a,b){if(typeof b==='function'){a.prototype.__proto__=b.prototype;for(var c in b)a[c]=b[c];}else a.prototype.__proto__=b.__proto__;}:function (k,l){var m=typeof l;if(m==="function"){var n=function (){};n.prototype=l.prototype;k.prototype=new n;for(var o in l)k[o]=l[o];}else {var n=function (){},p=j(l);n.prototype=p;k.prototype=new n;};},k=r.__ref_iterator__="__mocha_iterator_special_key__";r.throwStopIteration=m;r.isGenerator=l;r.getIterator=E;r.hasIterator=F;var n=/StopIteration/;r.isStopIteration=b;var o,q,G;if("WeakMap" in window){o=new WeakMap();q=function (self,p){var q=new p;f(q.constructor,"__is_private__",1);o.set(self,q);};G=function (self){if(o.has(self))return o.get(self);else if(self.constructor==="__is_private__")return self;};}else {q=function (self,a){if(!self.__typeid__){var b=new a;f(b.constructor,"__is_private__",1);f(self,"__private__",b);};};G=function (self){if(self.__private__)return self.__private__;else if(self.constructor==="__is_private__")return self;};};r.getPrivateRecord=G;r.initializeClass=H;r.getSuper=I;r.traitMixin=J;r.classMixin=K;r.checkRequirements=L;return r;}();!("StopIteration" in window)&&(window.StopIteration={toString:function c(){return "[object StopIteration]";}});function d(){var b=a.toArray(arguments,0),c={};c.length=0;[].push.apply(c,b);a.createTuple(c,arguments.length);return c;}function e(b){return a.createRecord(b);}!function (){function d(a){return a===1?1:a===2?2:3;}b['./if_test.js']={};var c=b['./if_test.js'];}();}();