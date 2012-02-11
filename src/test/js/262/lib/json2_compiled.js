var g=null; var json_parse=function(){function o(){switch(a){case "t":return b("t"),b("r"),b("u"),b("e"),!0;case "f":return b("f"),b("a"),b("l"),b("s"),b("e"),!1;case "n":return b("n"),b("u"),b("l"),b("l"),g}h("Unexpected '"+a+"'")}function e(){for(;a&&a<=" ";)b(g)}function l(){var c,f,d="",e;if(a==='"')for(;b(g);)if(a==='"')return b(g),d;else if(a==="\\")if(b(g),a==="u"){for(f=e=0;f<4;f+=1){c=parseInt(b(g),16);if(!isFinite(c))break;e=e*16+c}d+=String.fromCharCode(e)}else if(typeof m[a]==="string")d+=m[a]; else break;else d+=a;h("Bad string")}function n(){var c;c="";a==="-"&&(c="-",b("-"));for(;a>="0"&&a<="9";)c+=a,b(g);if(a===".")for(c+=".";b(g)&&a>="0"&&a<="9";)c+=a;if(a==="e"||a==="E"){c+=a;b(g);if(a==="-"||a==="+")c+=a,b(g);for(;a>="0"&&a<="9";)c+=a,b(g)}c=+c;if(isFinite(c))return c;else h("Bad number")}function b(b){b&&b!==a&&h("Expected '"+b+"' instead of '"+a+"'");a=k.charAt(i);i+=1;return a}function h(a){throw{name:"SyntaxError",message:a,a:i,text:k};}var i,a,m={'"':'"',"\\":"\\","/":"/",b:"\u0008", f:"\u000c",n:"\n",r:"\r",t:"\t"},k,j;j=function(){e();switch(a){case "{":var c;a:{var f,d={};if(a==="{"){b("{");e();if(a==="}"){b("}");c=d;break a}for(;a;){f=l();e();b(":");Object.hasOwnProperty.call(d,f)&&h('Duplicate key "'+f+'"');d[f]=j();e();if(a==="}"){b("}");c=d;break a}b(",");e()}}h("Bad object")}return c;case "[":a:{c=[];if(a==="["){b("[");e();if(a==="]"){b("]");f=c;break a}for(;a;){c.push(j());e();if(a==="]"){b("]");f=c;break a}b(",");e()}}h("Bad array")}return f;case '"':return l();case "-":return n(); default:return a>="0"&&a<="9"?n():o()}};return function(b,f){var d;k=b;i=0;a=" ";d=j();e();a&&h("Syntax error");return typeof f==="function"?function p(a,b){var c,e,d=a[b];if(d&&typeof d==="object")for(c in d)Object.prototype.hasOwnProperty.call(d,c)&&(e=p(d,c),e!==void 0?d[c]=e:delete d[c]);return f.call(a,b,d)}({"":d},""):d}}();

(function () {
  var json_str = '{"test" : 1,"test2":"test2","test3":null,"test4":{"test5":5}}';
  var json = json_parse( json_str );
  @assert( true , json["test"] === 1 );
  @assert( true , json["test2"] === "test2" );
  @assert( true , json["test3"] === null );
  @assert( true , json["test4"][ "test5" ] === 5 );
})();


