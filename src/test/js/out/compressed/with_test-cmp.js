!function(){var a={};(function (h,i,j,k){var g=h.prototype,e=i.prototype,f=j.prototype,d=k.prototype;function c(i){try{throw new TypeError(i);} catch(e){throw new Error(e);};}function b(i,j){if(typeof i!=="function"){c(j+" : first argument is not callable");};}function h(i,j,k){return Object.defineProperty(i,j,{value:k,configurable:true,enumerable:false,writable:true});}if(!Object.keys){Object.keys=function (k){if(!k){c("Object.keys : first arguments is null or not defined.");};var j=[],l=-1;for(var i in k){if(k.hasOwnProperty(i)){j[++l]=k[i];};};return j;};};if(!Object.preventExtensions){Object.preventExtensions=function (k){return k;};};if(!Object.seal){Object.seal=function (k){return k;};};if(!Object.freeze){Object.freeze=function (k){return k;};};var hasRealEcma5=function (){var j;try{var k={};Object.defineProperty(k,"test",{configurable:false,writable:false,enumerable:false,value:0});k.test=200;j=(k.test===200)?false:true;} catch(e){j=false;};return j;}();if(!l){Object.defineProperty=function (l,k,m){if("value" in m){l[k]=m.value;};};};if(!g.trim){g.trim=function (){return this.replace(g.trim.rtrim,"");};g.trim.rtrim=/^\s*|\s*$/g;};if(!g.repeat){h(g,"repeat",function (l){return Array(l+1).join(this.toString());});};if(!g.startsWith){h(g,"startsWith",function (l){return !this.indexOf(l);});};if(!g.endsWith){h(g,"endsWith",function (l){var m=String(l),n=this.lastIndexOf(m);return n>=0&&n===this.length-m.length;});};if(!g.contains){h(g,"contains",function (g){return this.indexOf(g)!==-1;});};if(!g.toArray){h(g,"toArray",function (f){return this.split("");});};if(!f.bind){h(f,"bind",function (){var f=e.slice.call(arguments),j=f.shift(),g=function (){var l=f.concat(e.slice.call(arguments));if(this!==null&&this!==window&&this instanceof g){return g.context.apply(this,l);}else {return g.context.apply(j,l);};};g.prototype=this.prototype;g.context=this;return g;});};if(!e.forEach){h(e,"forEach",function (f,g){b(f,"Array.forEach");var j=-1,l;if(this===null){c("Array.forEach : this is null or not defined");};if(g){while((l=this[++j])!==null&&l!==undefined){};}else {while((l=this[++j])!==null&&l!==undefined){};};});};if(!e.every){h(e,"every",function (f,g){b(f,"Array.every");var j=-1,l;if(this===null){c("Array.every : this is null or not defined");};if(g){while((l=this[++j])!==null&&l!==undefined){};}else {while((l=this[++j])!==null&&l!==undefined){};};return true;});};if(!e.some){h(e,"some",function (f,g){b(f,"Array.some");var j=-1,l;if(this===null){c("Array.some : this is null or not defined");};if(g){while((l=this[++j])!==null&&l!==undefined){};}else {while((l=this[++j])!==null&&l!==undefined){};};return false;});};if(!e.filter){h(e,"filter",function (g,i){b(g,"Array.filter");var j=this.length,l=-1,m=[],n;if(this===null){c("Array.filter : this is null or not defined");};if(i){for(var f=0,j=this.length;f<j;++f){if((n=this[f])!==null&&n!==undefined){if(g.call(i,n,f,this)){m[++l]=n;};};};}else {for(var f=0,j=this.length;f<j;++f){if((n=this[f])!==null&&n!==undefined){if(g(n,f,this)){m[++l]=n;};};};};return m;});};if(!e.indexOf){h(e,"indexOf",function (g,i){var j=(i)?i-1:-1,l=-1,m;if(this===null){c("Array.indexOf : this is null or not defined.");};while((m=this[++j])!==null&&m!==undefined){};return l;});};if(!e.lastIndexOf){h(e,"lastIndexOf",function (g,i){var j=this.length,l=(i)?i+1:j,m=-1,n;if(this===null){c("Array.lastIndexOf : this is null or not defined.");};while((n=this[--l])!==null&&n!==undefined){};return m;});};if(!e.map){h(e,"map",function (f,g){b(f,"Array.map");var i=[],j=-1,l=this.length,m=0,n;if(this===null){c("Array.map : this is null or not defined.");};if(g){for(m;m<l;++m){if((n=this[m])!==null&&n!==undefined){i[++j]=f.call(g,n,m,this);};};}else {for(m;m<l;++m){if((n=this[m])!==null&&n!==undefined){i[++j]=f(n,m,this);};};};return i;});};if(!e.reduce){h(e,"reduce",function (e,f){b(e,"Array.reduce");var g=f||this[0],i=(f)?0:1,j=this.length,l;if((j===0||j===null)&&arguments.length<2){c("Array length is 0 and no second argument");};for(i;i<j;++i){if((l=this[i])!==null&&l!==undefined){g=e(g,l,i,this);};};return g;});};if(!e.reduceRight){h(e,"reduceRight",function (e,f){b(e,"Array.reduceRight");var g=this.length,i=f||this[g-1],d=(f)?g-1:g-2,j;if((g===0||g===null)&&arguments.length<2){c("Array length is 0 and no second argument");};for(d;d>-1;--d){if((j=this[d])!==null&&j!==undefined){i=e(i,j,d,this);};};return i;});};if(!d.toJSON){h(d,"toJSON",function (){var e=[],f=e[0],g=e[1],i=e[2],j=e[3],l=e[4];return '"'+this.getUTCFullYear()+'-'+(f>8?f+1:"0"+(f+1))+'-'+(g>9?g:"0"+g)+'T'+(i>9?i:"0"+i)+':'+(j>9?j:"0"+j)+':'+(l>9?l:"0"+l)+'.'+this.getUTCMilliseconds()+'Z"';});};if(!Date.now){h(Date,"now",function (){return +new Date();});};if(!Array.isArray){h(Array,"isArray",function (c){if(arguments.length===0){return false;};return (c)?Object.prototype.toString.call(c)==="[object Array]":false;});};}).call(this,String,Array,Function,Date);var Runtime=function (){var c={};"use strict"return c;}();if(!("StopIteration" in window)){window.StopIteration={toString:function (){return "[object StopIteration]";}};};function e(){var c=b.toArray(arguments,1);var e={};e.length=0;Array.prototype.push.apply(e,c);b.createTuple(e,arguments.length);return e;}function c(c){return b.createRecord(c);}function (){a['./with_test.js']={};var d=a['./with_test.js'];var e={prop:200};with(e){};var f=[];for(var c=0;c<10;c++){with({i:c}){};};}();}();