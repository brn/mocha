!function(){var a={};!function (h,i,j,k){function b(h,i){if(typeof h!=="function"){c(i+" : first argument is not callable");};}function c(h){try{throw new TypeError(h);} catch(e){throw new Error(e);};}var g=h.prototype,e=i.prototype,f=j.prototype,d=k.prototype;if(!Object.keys)Object.keys=function (i){if(!i)c("Object.keys : first arguments is null or not defined.")var h=[],j=-1;for(var k in i){if(i.hasOwnProperty(k))h[++j]=i[k]};return h;}if(!Object.preventExtensions)Object.preventExtensions=function (i){return i;}if(!Object.seal)Object.seal=function (i){return i;}if(!Object.freeze)Object.freeze=function (i){return i;}var hasRealEcma5=function (){var h;try{var i={};Object.defineProperty(i,"test",{configurable:false,writable:false,enumerable:false,value:0});i.test=200;h=(i.test===200)?false:true;} catch(e){h=false;};return h;}();if(!j)Object.defineProperty=function (i,j,k){if(k.value)i[j]=k.value}if(!g.trim)g.trim=function (){return this.replace(g.trim.rtrim,"");}if(!g.repeat)Object.defineProperty(g,"repeat",{value:function (i){return Array(i+1).join(this.toString());},configurable:true,enumerable:false,writable:true})if(!g.startsWith)Object.defineProperty(g,"startsWith",{value:function (i){return !this.indexOf(i);},configurable:true,enumerable:false,writable:true})if(!g.endsWith)Object.defineProperty(g,"endsWith",{value:function (i){var j=String(i);var k=this.lastIndexOf(j);return k>=0&&k===this.length-j.length;},configurable:true,enumerable:false,writable:true})if(!g.contains)Object.defineProperty(g,"contains",{value:function (g){return this.indexOf(g)!==-1;},configurable:true,enumerable:false,writable:true})if(!g.toArray)Object.defineProperty(g,"toArray",{value:function (f){return this.split("");},configurable:true,enumerable:false,writable:true})if(!f.bind)f.bind=function (){var f=e.slice.call(arguments),h=f.shift(),g=function (){var i=f.concat(e.slice.call(arguments));if(this!==null&&this!==window&&this instanceof g){return g.context.apply(this,i);}else {return g.context.apply(h,i);};};g.prototype=this.prototype;g.context=this;return g;}if(!e.forEach)e.forEach=function (f,h){b(f,"Array.forEach");var i=-1,j;if(this===null)c("Array.forEach : this is null or not defined")if(h)f.call(h,j,i,this)else f(j,i,this)}if(!e.every)e.every=function (f,h){b(f,"Array.every");var i=-1,j;if(this===null)c("Array.every : this is null or not defined")if(h){if(!(f.call(h,j,i,this)))false}else {if(!(f(j,i,this)))false};return true;}if(!e.some)e.some=function (f,h){b(f,"Array.some");var i=-1,j;if(this===null)c("Array.some : this is null or not defined")if(h){if(f.call(h,j,i,this))true}else {if(f(j,i,this))true};return false;}if(!e.filter)e.filter=function (g,h){b(g,"Array.filter");var i=this.length,j=-1,f=[],k;if(this===null)c("Array.filter : this is null or not defined")if(h){if((k=this[l])!==null&&k!==undefined){if(g.call(h,k,l,this))f[++j]=k};}else {if((k=this[l])!==null&&k!==undefined){if(g(k,l,this))f[++j]=k};};return f;}if(!e.indexOf)e.indexOf=function (g,h){var i=(h)?h-1:-1,j=-1,k;if(this===null)c("Array.indexOf : this is null or not defined.")while((k=this[++i])!==null&&k!==undefined){if(k===g)j=i};return j;}if(!e.lastIndexOf)e.lastIndexOf=function (g,h){var i=this.length,j=(h)?h+1:i,k=-1,l;if(this===null)c("Array.lastIndexOf : this is null or not defined.")while((l=this[--j])!==null&&l!==undefined){if(l===g)k=j};return k;}if(!e.map)e.map=function (f,g){b(f,"Array.map");var h=[],i=-1,j=this.length,k=0,l;if(this===null)c("Array.map : this is null or not defined.")if(g){if((l=this[k])!==null&&l!==undefined)h[++i]=f.call(g,l,k,this)}else {if((l=this[k])!==null&&l!==undefined)h[++i]=f(l,k,this)};return h;}if(!e.reduce)e.reduce=function (e,f){b(e,"Array.reduce");var g=f||this[0],h=(f)?0:1,i=this.length,j;if((i===0||i===null)&&arguments.length<2)c("Array length is 0 and no second argument")for(h;h<i;++h){if((j=this[h])!==null&&j!==undefined)g=e(g,j,h,this)};return g;}if(!e.reduceRight)e.reduceRight=function (e,f){b(e,"Array.reduceRight");var g=this.length,d=f||this[g-1],h=(f)?g-1:g-2,i;if((g===0||g===null)&&arguments.length<2)c("Array length is 0 and no second argument")for(h;h>-1;--h){if((i=this[h])!==null&&i!==undefined)d=e(d,i,h,this)};return d;}if(!d.toJSON)d.toJSON=function (){var e=[],f=e[0],g=e[1],h=e[2],i=e[3],j=e[4];return '"'+this.getUTCFullYear()+'-'+(f>8?f+1:"0"+(f+1))+'-'+(g>9?g:"0"+g)+'T'+(h>9?h:"0"+h)+':'+(i>9?i:"0"+i)+':'+(j>9?j:"0"+j)+'.'+this.getUTCMilliseconds()+'Z"';}if(!Date.now)Date.now=function (){return +new Date();}if(!Array.isArray)Array.isArray=function (b){if(arguments.length===0)falsereturn (b)?({}).toString.call(b)==="[object Array]":false;}}.call(this,String,Array,Function,Date);var Runtime=function (){"use strict";var b={};function f(i,h,g){this.toString=function (){return Runtime.getErrorMessage(g)+" in file "+h+" at : "+i;};}var g=Math,c=g.max;var h=Array.prototype,e=h.slice;var Runtime={getErrorMessage:function (g){return (g.message)?g.message:(g.description)?g.description:g.toString();},exceptionHandler:function (j,k,g){if(isStopIteration(g)){this.throwException(g);}else {this.throwException(new f(j,k,g));};},throwException:function (j){try{throw j;} catch(e){if(isStopIteration(g)){throw new Error(g);}else {throw new Error(this.getErrorMessage(g));};};},hasProto:"__proto__" in {}};function h(k,l,m){return Object.defineProperty(k,l,{configurable:true,enumerable:false,writable:true,value:m});}b.createUnenumProp=h;function f(k,l,m){return Object.defineProperty(k,l,{configurable:false,enumerable:false,writable:false,value:m});}b.constant=f;function j(k,l){return (k)?e.call(k,l):[];}b.toArray=j;function f(){}function j(e,j,k){var d=new f;h(d,"next",e.bind(k,false,false));h(d,"send",e.bind(k,true,false));h(d,"close",j.bind(k));h(d,"__nothrowNext__",e.bind(k,false,true));h(d,"toString",function (){return "[object Generator]";});Object.freeze(d);return d;}b.createGenerator=j;function k(g){return (g.message)?g.message:(g.description)?g.description:g.toString();}var b.throwException=i.throwException.bind(i);var b.exceptionHandler=i.exceptionHandler.bind(i);function e(l,m){for(var n in m){l[n]=m[n];};return l;}b.extend=e;function k(m){var n=c(m.length,this.length),o=-1;while(++o<n&&m[o]===this[o]){};return n===o;}function e(){return Array.prototype.slice.call(this);}function l(l,m){h(l,"length",m);h(l,"equal",k);h(l,"toArray",e);h(l,"toString",function (){return "[object Tuple]";});return Object.freeze(l);}b.createTuple=l;function c(c){if(c.toString()==="[object Object]"){h(c,"toString",function (){return "[object Record]";});};return Object.freeze(c);}b.createRecord=c;var b.extendPrototype=function (e,c){e.prototype=c;};var getPrototype=("getPrototypeOf" in Object)?function (l){return Object.getPrototypeOf(l);}:function (l){var d={};for(var m in l){if(!l.hasOwnProperty(m)){d[m]=l[m];};};return d;};var b.extendClass=(i.hasProto)?function (e,l){if(typeof l==='function'){e.prototype.__proto__=l.prototype;for(var m in l){e[m]=l[m];};}else {e.prototype.__proto__=l.__proto__;};}:function (e,c){var n=typeof c;if(n==="function"){var o=function (){};o.prototype=c.prototype;e.prototype=new o;for(var p in c){e[p]=c[p];};}else {var o=function (){},o=k(c);n.prototype=o;e.prototype=new n;};};var b.__ref_iterator__="__mocha_iterator_special_key__";function m(){try{throw StopIteration;} catch(e){throw new Error(g.toString());};}b.throwStopIteration=m;function c(g){return g instanceof f;}b.isGenerator=c;function e(k){var d=k[l](),f;if(c(d)){return d;};f={};if(d.next){h(f,"next",function (){var k=d.next();if(k===undefined){m();};return k;});}else {return {};};if(!("__nothrowNext__" in d)){h(f,"__nothrowNext__",d.next.bind(d));};for(var n in d){if(n!=="next"&&n!=="__nothrowNext__"){f[n]=d[n];};};if(!("toString" in d)){h(f,"toString",function (){return "[object Iterator]";});};return f;}b.getIterator=e;function g(k){return l in k;}b.hasIterator=g;var d=/StopIteration/;function c(k){return k===StopIteration||d.test(k);}b.isStopIteration=c;var g,f,e;if("WeakMap" in window){g=new WeakMap();f=function (self,c){var d=new c;h(d.constructor,"__is_private__",1);g.set(self,d);};e=function (self){if(g.has(self)){return g.get(self);}else if(self.constructor==="__is_private__"){return self;};};}else {f=function (self,d){if(!self.__typeid__){var g=new d;h(g.constructor,"__is_private__",1);h(self,"__private__",g);};};e=function (self){if(self.__private__){return self.__private__;}else if(self.constructor==="__is_private__"){return self;};};};b.getPrivateRecord=e;function c(e,g,h,k,l,m,n){if(!e||!(e instanceof g)){j("class "+m+" must be called by new. line : "+n);};f(e,h);k.apply(e,l);}b.initializeClass=c;function d(d){var e=typeof d,f;if(e==="function"){f=function (){};f.prototype=d.prototype;f=new f();if(d.__harmony_class__){f.constructor=d.constructor;}else {f.constructor=d;};return f;};return f;}b.getSuper=d;function c(e,f,g,h){if(!e._mochaTraitMark||!f._mochaTraitMark){i.throwException("mixin only used for trait.");}else {var j=e._mochaTraitPrivate,k=f._mochaTraitPrivate,l=e._mochaTraitPublic,m=f._mochaTraitPublic,n=f._mochaRequires,o=e._mochaRequires,p;for(var q in k){if(!h[q]){p=(!g[q])?q:g[q];j[p]=k[q];};};for(q in m){if(!h[q]){p=(!g[q])?q:g[q];l[p]=m[q];};};for(q in n){o[q]=n[q];};};}b.traitMixin=c;function d(d,e,f,g,h){var j=d.prototype,k=e.prototype,l=f._mochaTraitMark,m=f._mochaTraitPublic,n=f._mochaTraitPrivate;if(!l){i.throwException("mixin only used for trait.");}else {var o;for(var p in m){if(!h[p]){o=(!g[p])?p:g[p];j[o]=m[p];};};for(p in n){if(!h[p]){o=(!g[p])?p:g[p];k[o]=n[p];};};};}b.classMixin=d;function c(d,e,f,g,h){var i=d.prototype,j=e.prototype;for(var k=0,l=f.length;k<l;k++){var m=f[k],n=m._mochaRequires;for(var o in n){if(!(o in i)&&!(o in j)){c.throwException("Class dose not meet the traits requirement. traits require implementation of property "+o+"\nin file "+g+" at line "+h);};};};}b.checkRequirements=c;return b;}();if(!("StopIteration" in window))window.StopIteration={toString:function (){return "[object StopIteration]";}}function h(){var b=c.toArray(arguments,1),d={};d.length=0;[].push.apply(d,b);c.createTuple(d,arguments.length);return d;}function b(b){return c.createRecord(b);}function (){a['./trait_test.js']={};var b=a['./trait_test.js'];function (){var TestTraitP={_mochaTraitPrivate:{_greaterThant:function a(a,b){return a<b;}},_mochaTraitPublic:{greaterThan:function b(a,b){return a<b;}},_mochaRequires:{},_mochaTraitMark:true};return c;}();function (){var TestTrait={_mochaTraitPrivate:{_lessThan:function a(a,b){return a<b;}},_mochaTraitPublic:{lessThan:function b(a,b){return a<b;}},_mochaRequires:{compare:true,test1:true,test2:true,test3:true,test4:true},_mochaTraitMark:true};return c;}();var traitexp=function (){var h={_mochaTraitPrivate:{mastercmp:function a(a,b){return a>b;}},_mochaTraitPublic:{lessthan:function b(a,b){return a>b;}},_mochaRequires:{},_mochaTraitMark:true};return c;}();}();}();