
/**
 *@author Taketoshi Aono
 *@fileOverview
 *<pre>
 *J++ OOP and Packagable Programing framework for javascript
 *Make development of javascript application to easy and muchbetter for maintainability, and
 *to make cohesion of class to high, this framework provide method of define privates method or member.
 *And include provide method of script module cache to use localStorage.
 *Copyright (c) 2010 Taketoshi Aono
 *
 *#####License####
 *The MIT License
 *
 *Permission is hereby granted, free of charge, to any person obtaining a copy
 *of this software and associated documentation files (the "Software"), to deal
 *in the Software without restriction, including without limitation the rights
 *to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *copies of the Software, and to permit persons to whom the Software is
 *furnished to do so, subject to the following conditions:
 *
 *The above copyright notice and this permission notice shall be included in
 *all copies or substantial portions of the Software.
 *
 *THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *THE SOFTWARE.
 *</pre>
 */

(function ( global , extras ){
 
  /**
  *@namespace
   *Javascript native global namespace.
   */
  global = global || window;
  
  var STD_MODULE_DIR = "jspp-modules/"
  
  /**
   *@const
   */
  var CONST = {
        IF_MODIFIED_SINCE   : "If-Modified-Since",
        DEFAULT_MODIFIED    : "Thu, 01 Jun 1970 00:00:00 GMT",
        LAST_MODIFIED       : "Last-Modified",
        LAST_MODIFIED_SUFFIX : "__lasttime__",
        SCRIPT_CACHE_NAME   : location.pathname + location.search + location.hash,
        MODULE_DIR          : "module/",
        JSON                : "json",
        GET                 : "get",
        USE_STRICT          : '\n"use strict";\n',
        MODULE_ARGUMENTS    : "require , Class , Const , __filename , __dirname , module",
        TYPE_PREFIX         : "[object ",
        TYPE_SUFFIX         : "]",
        TYPED_PROPERTY      : "toString",
        META                : function () { return "[object MetaClass]"; },
        SCRIPT_TAG          : document.createElement ( "script" ),
        SCRIPT_TYPE         : "text/javascript",
        READY_STATE         : " loaded complete ",
        DIR                 : /(\$\{([a-z]+?)\})/g,
        ROOT                : location.protocol + "//" + location.host + "/",
        PAGE                : document.URL,
        GOOLEAPI            : "https://ajax.googleapis.com/ajax/libs/",
        NUMBER_PROPS        : "toFixed toExponential toPrecision".split( " " ),
        DATE_PROPS          : ( "toDateString toTimeString toLocaleDateString toLocaleTimeString " +
                                "getTime getFullYear getUTCFullYear getMonth getUTCMonth getDate " +
                                "getUTCDate getDay getUTCDay getHours getUTCHours getMinutes " +
                                "getUTCMinutes getSeconds getUTCSeconds getMilliseconds " +
                                "getUTCMilliseconds getTimezoneOffset setTime setMilliseconds " +
                                "setUTCMilliseconds setSeconds setUTCSeconds setMinutes " +
                                "setUTCMinutes setHours setUTCHours setDate setUTCDate setMonth " +
                                "setUTCMonth setFullYear setUTCFullYear toUTCString" ).split(" "),
        REG_PROPS           : "exec test".split ( " "),
        FUNCTION_PROPS      : "apply call".split ( " " ),
        SHORTHAND_DICT       : {
          "cwd" : function () { return ModuleHelper.getBasePath (); },
          "root" : function () { return CONST.ROOT; },
          "page" : function () { return CONST.PAGE; },
          "googleapi" : function () { return CONST.GOOLEAPI; },
          "path"  : function () { return ModuleHelper.getIncludePath (); }
        },
        SHORTHAND           : function ( $$ , $ , match ) {
          var ret = CONST.SHORTHAND_DICT [ match ];
          if ( ret ){
            return ret ();
          }else{
            throw new Error ( match + " is undefined shorthand command." );
          }
        },
        MOD_STD : {
          "Notification" : STD_MODULE_DIR,
          "EventDelegator" : STD_MODULE_DIR,
          "Request" : STD_MODULE_DIR,
          "NonblockingIterator" : STD_MODULE_DIR,
          "Cookie" : STD_MODULE_DIR,
          "KVObserver" : STD_MODULE_DIR,
          "Mutex" : STD_MODULE_DIR,
          "StringTemplate" : STD_MODULE_DIR,
          "JsppTestUnit" : STD_MODULE_DIR + "JsppTestUnit/",
          "Hash" : STD_MODULE_DIR
        },
        TO_STRING           : Object.prototype.toString,
        PRIVATE_CLEANER     : [],
        CLASS_ID            : "__id__",
        IS_SCRIPT_FREE      : false,
        DESTROY             : [],
        CLASS_TABLE         : {},
        NOT_COPIEABLE       : {
          toString : true,
          __id__  : true,
          __typeID__ : true,
          constructor : true,
          __typedefed__ : true
        }
      },
      Jspp,
      Jspp_ModuleContext,
      Jspp_evalModule,
      Type,
      Storage,
      Class,
      XBWrapper,
      Module,
      ModuleHelper,
      Utils,
      Types,
      Builtin,
      Envs,
      Macro;
  
  
  if ( !global.uneval ) {
    /**
     *@param {ANY} targetObject => Stringify target.
     *@param {Boolean} isJson => Stringify json or not.
     *@description
     *Dump object like mozilla's uneval;
     */
    global.uneval = function ( targetObject , isJson ) {
      
      var type = Types.baseTypeOf ( targetObject ),
          ret = [];
      
      if ( type === "Window" || type === "Document" || type === "Element" || type === "NodeList" ) {
        return "({})";
      }
      
      if ( type === "Object" ) {
        ret [ ret.length ] = "({";
        var props = [];
        for ( var prop in targetObject ) {
          type = Types.baseTypeOf ( targetObject [ prop ] );
          
          ret [ ret.length ] = ( isJson )? ( '"' + ( prop.replace ( /^"|"$/g , "" ) ) + '":' ) : prop + ":";

          switch ( type ) {
            case "Object" :
            case "Array" :
              ret [ ret.length ] = uneval ( targetObject [ prop ] );
              break;
            case "Function" :
              if ( !isJson ) {
                ret [ ret.length ] = Function.prototype.toString.call ( targetObject [ prop ] );
              }else{
                throw new Error ( "TypeError JSON.stringify" );
              }
              break;
            case "String" :
              ret [ ret.length ] = '"' + targetObject [ prop ] + '"';
              break;
            default :
              ret [ ret.length ] = targetObject [ prop ].toString ();
          }
          ret [ ret.length ] = ",";
        }
        
        ret [ ret.length - 1 ] = "})";
        return ret.join ( "" );
      
      }else if ( type === "Array" ) {
        ret [ ret.length ] = "[";
        for ( var i = 0,len = targetObject.length; i < len; ++i ) {
          type = Types.baseTypeOf ( targetObject [ i ] );
          
          switch ( type ) {
            case "Object" :
            case "Array" :
              ret [ ret.length ] = uneval ( targetObject [ prop ] );
              break;
            case "Function" :
              if ( !isJson ) {
                ret [ ret.length ] = Function.prototype.toString.call ( targetObject [ prop ] );
              }else{
                throw new Error ( "TypeError JSON.stringify" );
              }
              break;
            case "String" :
              ret [ ret.length ] = '"' + targetObject [ i ] + '"';
              break;
            default :
              ret [ ret.length ] = targetObject [ prop ].toString ();
          }
          
          ret [ ret.length ] = ",";
          
        }
        
        ret [ ret.length - 1 ] = "]";
        return ret.join ( "" );
        
      }else if ( type === "Function" ) {
        
        if ( isJson ) {
          throw new Error ( "TypeError JSON.stringify" );
        }else{
          ret = Function.prototype.toString.call ( targetObject );
        }
        return ret;
      }else{
        return targetObject.toString ();
      }
      
    };
    
  }
  
  if ( !global.JSON ) {
    
    /**
     *json_parse from http://www.JSON.org/json_parse.js
     */
    var g=null; var json_parse=function(){function o(){switch(a){case "t":return b("t"),b("r"),b("u"),b("e"),!0;case "f":return b("f"),b("a"),b("l"),b("s"),b("e"),!1;case "n":return b("n"),b("u"),b("l"),b("l"),g}h("Unexpected '"+a+"'")}function e(){for(;a&&a<=" ";)b(g)}function l(){var c,f,d="",e;if(a==='"')for(;b(g);)if(a==='"')return b(g),d;else if(a==="\\")if(b(g),a==="u"){for(f=e=0;f<4;f+=1){c=parseInt(b(g),16);if(!isFinite(c))break;e=e*16+c}d+=String.fromCharCode(e)}else if(typeof m[a]==="string")d+=m[a]; else break;else d+=a;h("Bad string")}function n(){var c;c="";a==="-"&&(c="-",b("-"));for(;a>="0"&&a<="9";)c+=a,b(g);if(a===".")for(c+=".";b(g)&&a>="0"&&a<="9";)c+=a;if(a==="e"||a==="E"){c+=a;b(g);if(a==="-"||a==="+")c+=a,b(g);for(;a>="0"&&a<="9";)c+=a,b(g)}c=+c;if(isFinite(c))return c;else h("Bad number")}function b(b){b&&b!==a&&h("Expected '"+b+"' instead of '"+a+"'");a=k.charAt(i);i+=1;return a}function h(a){throw{name:"SyntaxError",message:a,a:i,text:k};}var i,a,m={'"':'"',"\\":"\\","/":"/",b:"\u0008", f:"\u000c",n:"\n",r:"\r",t:"\t"},k,j;j=function(){e();switch(a){case "{":var c;a:{var f,d={};if(a==="{"){b("{");e();if(a==="}"){b("}");c=d;break a}for(;a;){f=l();e();b(":");Object.hasOwnProperty.call(d,f)&&h('Duplicate key "'+f+'"');d[f]=j();e();if(a==="}"){b("}");c=d;break a}b(",");e()}}h("Bad object")}return c;case "[":a:{c=[];if(a==="["){b("[");e();if(a==="]"){b("]");f=c;break a}for(;a;){c.push(j());e();if(a==="]"){b("]");f=c;break a}b(",");e()}}h("Bad array")}return f;case '"':return l();case "-":return n(); default:return a>="0"&&a<="9"?n():o()}};return function(b,f){var d;k=b;i=0;a=" ";d=j();e();a&&h("Syntax error");return typeof f==="function"?function p(a,b){var c,e,d=a[b];if(d&&typeof d==="object")for(c in d)Object.prototype.hasOwnProperty.call(d,c)&&(e=p(d,c),e!==void 0?d[c]=e:delete d[c]);return f.call(a,b,d)}({"":d},""):d}}();
    
    /**
     *@namespace
     *If builtin JSON object is not defined,
     *define JSON namespace.
     */
    global.JSON = 
    /**lends JSON*/
    {
      /**
       *@ignore
       */
      toString : function () {
        return "[object JSON]"
      },
      
      /**
       *@param {JSON} json => JSON object.
       *@returns {String}
       *@description
       *Stringify json object use uneval.
       */
      stringify : function ( json ) {
        return uneval ( json , true );
      },
      
      parse : function ( text , fn ) {
        return json_parse ( text , fn );
      }
      
    };
    
  }
  
  /**
   *@namespace
   *External API.
   *In basicaly Jspp namespace is used from external of module enviorment.
   *Module is not use Jspp namespace.
   */
  Jspp = 
  /**@lends Jspp*/
  {
    
    /**
     *@private
     *Jspp version.
     */
    __version : "1.0",
    
    /**
     *An empty fucnction.
     */
    __noop : function () {},
    /**
     *@static
     *@param {Object} dest => Copy target object.
     *@param {Object} Source => Copy source object.
     *@description
     *Copy member of source object to destination object.
     */
    extend : function ( dest , source ) {
      for ( var name in source ) {
        dest [ name ] = source [ name ];
      }
    },
    
    /**
    *@param {String} className => Target class path.
    *@retutns {Class}
    *@description
    *Get class definition by name.
    */
    queryClass : function ( className ) {
      
      var Class = CONST.CLASS_TABLE [ className ];
      return ( !Class && Class.privates )? null : Class._class;
      
    },
    
    /**
    *@param {String} iname => Target interface name.
    *@retutns {Interface}
    *@description
    *Get interface definition by name.
    */
    queryType : function ( iname ) {
      var ret = Types.typeContainer [ iname ];
      return ( ret )? ret : null;
    },
    
    /**
    *@param {String} funcName => Target function name.
    *@retuns {Function}
    *Get buitin function by name.
    */
    queryBuiltin : function ( funcName ) {
      
      return Builtin.prototype [ funcName ]
      
    },
    
    /**
    *@param {Function} => Want to evaluate function.
    *@return {ANY} Evaluate results.
    *Evaluate function in module context.
    *<br />
    *<strong>notice</strong>
    *<br />
    *All closure variable cant use in module context.
    */
    evalInModuleContext : function ( fn ) {
      var guid = Utils.guidgen ();
      return new Jspp_ModuleContext ().evalExternalContext ( guid , fn );
    },
    
    /**
    *@param {String} filename => Module filename.
    *@param {Boolean} isEnv => Use env or not.
    *@param {Boolean} isBootMode => Load bootstrap.js or not.
    *Global module loader.
    *@see Module.prototype.require
    */
    require : function ( filename , isEnv , isBootMode ) {
      var newContext = new Jspp_ModuleContext ()
      return newContext.loadModule ( filename , isEnv , isBootMode )
    },
    
    __ecma5Extras : {
      hasDefineProperty : (function () {
        try{
          return Object.defineProperty( {} , "x" , { get : function(){ return true } } ).x
        }catch (e){
          return false;
        }
      })()
    }
    
  }
  
  global.Jspp = Jspp;
  
  /**
  *@class
  *Script context class.
  *This class express module enviorment.
  *@example
  * //If you want to create new context,
  * //do like this.
  * var moduleExportResult = new Jspp_ModuleContext ().loadModule ( "example.js" )
  * //Now load %JSPPDIR%/example.js.
  *@param {String} filename => Base path of module.
  */
  Jspp_ModuleContext = function ( filename ) {
    this.__exports = undefined;
    this.__Module = new Module ( filename )
    this.__scriptContext = undefined;
  }
  
  Jspp.extend ( Jspp_ModuleContext.prototype ,
  /**@lends Jspp_ModuleContext.prototype*/
  {
    
    /**
    *@private
    */
    __boot : function () {
      this.__scriptContext = this.__Module.require ( "bootstrap" , false , true );
      this.__evaluateModule ( false , true );
    },
    
    /**
    *@param {String} filename => Loading target module filename.
    *@param {Boolean} isEnv => Apply env to context or not.
    *@param {Boolean} isBootMode => Load bootstrap.js or not.
    *@see Module.require
    */
    loadModule : function ( filename , isEnv , isBootMode , isMain ) {
      
      isEnv = ( isEnv !== false )? true : isEnv;
      
      if ( isBootMode ) {
        return this.__boot ();
      }
      
      this.__scriptContext = this.__Module.require ( filename , isEnv , isBootMode , isMain )
      if ( this.__scriptContext.cached ) {
        return this.__scriptContext.results;
      }else{
        return this.__evaluateModule ( isEnv , isBootMode );
      }
    },
    
    setActivePath : function ( path ) {
      this.__Module.setActivePath ( path )
    },
    
    getActivePath : function () {
      return this.__Module.getActivePath ()
    },
    
    /**
    *@param {String} id => Guid.
    *@param {Function} fn => Eval target function.
    */
    evalExternalContext : function ( id , fn ) {
      this.__scriptContext = {
        results : {
          filename : id,
          script : "(" + Function.prototype.toString.call ( fn ) + ")()"
        }
      }
      return this.__evaluateModule ( true , false );
    },
    
    /**
    *@param {Boolean} isEnv => Apply env to context or not.
    *@param {Boolean} isBootMode => Load bootstrap.js or not.
    */
    __evaluateModule : function ( isEnv , isBootMode ) {
      return Jspp_evalModule.compile.call ( this , isEnv , isBootMode );
    }
    
  });
  
  
  /**
  *@namespace
  *Module evaluation.
  */
  Jspp_evalModule =
  /**@lends Jspp_evalModule*/
  {
    /**
    *@param {Object} FileObject => 
    *{String} script : script string.
    *{String} fileName : A path of file.
    *@param {Boolean} isEnv => Use env or not.
    *@param {Boolean} isBootMode => Is boot mode or not.
    *@returns {Object} Result of evaluation.
    *
    *@description
    *Evaluate loaded script.
    *If debug parameter of boot option is "true", use eval,
    *and if seted "false", use Function constructor.
    *When loading the bootstrap.js, always use Function constructor.
    *@see Module.prototype.runScript
    */
    compile : function ( isEnv , isBootMode ) {
      
      var FileObject = this.__scriptContext.results;
      
      this.__exports = ModuleHelper.results.exports [ FileObject.filename ] = {};
      
      
      //stric mode
      this.__scriptContext.results.asstrict = ( ModuleHelper.options.JSPP_USE_STRICT === true )? CONST.USE_STRICT : "";
      
      var script = ( ModuleHelper.options.JSPP_USE_MINIFIED )? FileObject.script : ModuleHelper.__getWrappedScript ( isEnv , FileObject ),
          newContext = new Jspp_ModuleContext ( FileObject.filename ),
          exports;
          
      this.__scriptContext.results.wrapped = script;
      
      this.__scriptContext.results.require = newContext.loadModule.bind ( newContext );
      this.__scriptContext.results.require.setActivePath = newContext.setActivePath.bind ( newContext );
      this.__scriptContext.results.require.getActivePath = newContext.getActivePath.bind ( newContext );
      
      this.__scriptContext.results.localEnv = new Envs ();
      
      this.__scriptContext.results.__Class = new Class ( this.__exports , this.__scriptContext.results.localEnv , ( ( isBootMode )? "bootstrap.js" : ( !FileObject.filename )? "main.js" : FileObject.filename ) )
      this.__scriptContext.results.__Class = this.__scriptContext.results.__Class.define.bind ( this.__scriptContext.results.__Class )
      Utils.unenum ( this.__scriptContext.results.__Class , CONST.TYPED_PROPERTY , CONST.META );
      this.__scriptContext.results.localEnv.exports = this.__exports;
      
      //compile.
      Jspp_evalModule.__runScript.call ( this , isEnv , isBootMode );
      //Save data to Storage.
      if ( Storage.hasStorage && !isBootMode ){
      
        ModuleHelper.scriptInfo [ FileObject.filename ] = script;
        ModuleHelper.scriptInfo [ FileObject.filename + "__version__" ] = ModuleHelper.options.JSPP_VERSION;

      
      }else if ( isBootMode ) {
        
        ModuleHelper.scriptInfo.debug        = ModuleHelper.options.JSPP_DEBUG;
        ModuleHelper.scriptInfo.cache        = ModuleHelper.options.JSPP_CACHE;
        ModuleHelper.scriptInfo.use_minified = ModuleHelper.options.JSPP_USE_MINIFIED;
        
      }
      
      return ( ModuleHelper.options.JSPP_USE_MINIFIED )? ModuleHelper.results.exports [ "main" ] : ModuleHelper.results.exports [ FileObject.filename ]
      
    },
    
    /**
    *@private
    *@param {Object} FileObject => 
    *{String} script : Script string.<br />
    *{String} wrapped : Processed script string.<br />
    *{Object} exports : Exports object.<br />
    *{String} filename : Current Module name.<br />
    *{Object} envs : Local env of current Module.<br />
    *{Function} Class : Class API for current Module.
    *@param {fileName} isEnv => A path of file.
    *@param {Boolean} isBootMode => Is boot mode or not. 
    *@description
    *Evaluate script.
    *Result of evaluation is hold by Module.results.exports.
    *Env is added to evaluate script context by with.
    */
    __runScript : function ( isEnv , isBootMode ) {
      var FileObject = this.__scriptContext.results,
          //Get current line number.
          line;
      //when loading bootstrap.js
      if ( isBootMode ) {
      
        line = ( new Error() ).lineNumber;
        Function( "with ( this ){" + FileObject.script + "}" ).call( ModuleHelper.options );
      
      //When use_minified is true.
      }else if ( ModuleHelper.options.JSPP_USE_MINIFIED ) {
         
        line = ( new Error() ).lineNumber;
        Function( "regist,global_exports,global_exports_hash,env,classes,Const,run" , FileObject.script )( ModuleHelper.regist.bind ( this ) , ModuleHelper.globalExports.bind ( this ) , ModuleHelper.results.exports , Env , Class , Utils.Const.bind ( Utils ) , function ( name, fn) { fn ( name ) } );
        
      //When debug is true.
      }else if ( ModuleHelper.options.JSPP_DEBUG ) {
        
        __decl_volatile__ : {
          
          (function ( require , Class , Const , __filename , __dirname , __module ) {
            var runnable = ( ( isEnv === true )? FileObject.wrapped : FileObject.script )
            runnable = [ runnable , ( "\n//@ sourceURL=" + FileObject.filename.replace ( rurl , "" ) )].join ("");
            
            try{
              
              
              ModuleHelper.line = line = ( new Error() ).lineNumber;
              eval ( runnable );
              
            }catch ( e ){
              
              ModuleHelper.scriptInfo = {};
              Storage.set (  CONST.SCRIPT_CACHE_NAME , ModuleHelper.scriptInfo , CONST.JSON )
              
              for ( var i in ModuleHelper.scriptInfo ) {
                delete ModuleHelper.scriptInfo [ i ];
              }
              
              //Error handling.
              //Can fild syntax error.
              if ( line ) {
                
                //Can get linenumber.
                var arr = FileObject.wrapped.split( "\n" )
                if ( global.console ){
                  console.error ( e + "\n >> " + arr [ ( e.lineNumber - ( line + 1 ) ) ] + "\n" + FileObject.filename + "  "+ ( e.lineNumber - ( line + 3 ) ) + "行目" );
                }else{
                  throw new Error ( e + "\n >> " + arr [ ( e.lineNumber - ( line + 1 ) ) ] + "\n" + FileObject.filename + "  "+ ( e.lineNumber - ( line + 3 ) ) + "行目" );
                }
              }else{
                
                //Cant get linenumber.
                var arr = FileObject.wrapped.split( "\n" )
                window.onerror = function ( error , url , line ) {
                  alert ( e.description + "\n >> " + arr [ line - 372 ] + "\n" + FileObject.filename + "  "+ ( line - 374 ) + "行目" );
                }
                throw new Error ( "" );
              }
            }
          }).call( FileObject.localEnv , FileObject.require , FileObject.__Class , Utils.Const.bind ( Utils ).curry ( FileObject.localEnv ) , FileObject.filename , FileObject.filename.slice ( 0 , FileObject.filename.lastIndexOf ( "/" ) + 1 ) , this.__localEnv );
        
        }
      //when debug is false.
      }else{
        
        ModuleHelper.line = line = ( new Error() ).lineNumber;
        Function ( CONST.MODULE_ARGUMENTS ,  FileObject.wrapped ).call( FileObject.localEnv , FileObject.require , FileObject.__Class , Utils.Const.bind ( Utils ).curry ( FileObject.localEnv ) , FileObject.filename ,  FileObject.filename.slice ( 0 , FileObject.filename.lastIndexOf ( "/" ) + 1 ) , this.__localEnv );
        
      }
            
      
    }
  }
  
  /**
  *@namespace
  *Type system module.
  */
  Types =
  /**@lends Types*/
  {
    /**
    *@param {ANY} args => Target object.
    *@description
    *Distinct object type.
    *Result of native typeof is obscure,
    *but result of this typeOf is definite like Array , LikeArray.
    */
    typeOf : function( args ){
      //Check null or undefined.
      if ( args === undefined ){
        return "undefined"
      }else if ( args === null ){
        return "null"
      }
      
      var ret,
          to = CONST.TO_STRING,
          os = Types.__typeString,
          tor = args.toString ();
      
      if ( ( ( args.constructor.__typedefed__ ) && ( ret = os [ args.constructor.__typedefed__ () ] ) ) || ( tor !== "[object Object]" &&  ( ret = os [ tor ] ) ) || ( this.isPrimitive ( args )  && ( ret = "Class" ) ) ){
        return ret;
      }
      
      
      ret = to.call( args )
      
      if ( args.__typeID__ && CONST.CLASS_TABLE [ args.__typeID__ ] ) {
       return "Class" 
      }else if( ( ret = os[ ret ] ) ){
        return ( args[ 0 ] && ( ret === "Object" ) )? "LikeArray" :  ret;
      }else if( args.nodeType ){
        return "Element"
      }else{
        return "Object"
      }
    },
    
    /**
    *@param {ANY} args => Target object.
    *@description
    *Get default type of arguments object.
    */
    baseTypeOf : function ( args ) {
      
      var ret,
          to = CONST.TO_STRING,
          os = Types.__typeString;
      
      ret = to.call( args )
      
      if ( args.__typeID__ && CONST.CLASS_TABLE [ args.__typeID__ ] ) {
       return "Class" 
      }else if( ( ret = os[ ret ] ) ){
        return ret;
      }else if( args.nodeType ){
        return "Element"
      }else{
        return "Object"
      }
      
    },
    
    /**
    *@param {ANY} obj => First compared object.
    *@param {ANY} obj2 => Second compared object.
    *@returns {Boolean} Result of compare.
    *@description
    *Compared first arguments type to second argumetns type.
    *If type of obj equal to type of obj2, return true, but return false.
    */
    isType : function ( obj , obj2 ) {
      var type = Types.typeOf ( obj2 ),
          ret = obj === obj2;
      if ( ret ) {
        return ret;
      }
      if ( type === "MetaClass" ) {
        return obj instanceof Function;
      }
      return obj instanceof obj2;
    },
    
    /**
    *@param {ANY} object => Target object.
    *@description
    *Get type object from javascript object.
    */
    typeFrom : function ( object ) {
      var type = this.typeOf ( object ),
          primRet = this.__typeObject [ type ],
          ret = this.typeContainer [ type ];
      
      return ( primRet )? primRet : ret;
      
    },
    
    /**
    *@param {ANY} object => Target object.
    *@returns {Boolean} Target is primitive or not.
    *@description
    *Distinct primitive or not.
    */
    isPrimitive : function ( object ) {
      switch ( object ) {
      case Array :
      case String :
      case RegExp :
      case Function :
      case Number :
      case Object :
      case Boolean:
        return true;
      default :
        return false;
      }
    },
    
    /**
     * @param {ANY} target => Target object.
     * @returns {String|null}
     * @description
     * Distinct primitives and get type with string.
     */
    getPrimitiveType : function ( target  ) {
      switch ( target ) {
      case Array : 
        return "Array";
        break;
      case String : 
        return "String";
        break;
      case RegExp : 
        return "RegExp";
        break;
      case Function : 
        return "Function";
        break;
      case Number :
        return "Number";
        break;
      case Object :
        return "Object";
        break;
      case Boolean :
        return "Boolean";
        break;
      default :
        return null;
      };
    },
    /**
    *@param {ANY} Class => Target object.
    *@param {String} typeName => Type string.
    *@description
    *Set type to target object.
    *New type is add to typeObject and typeString.
    */
    type : function ( Class , typeName ) {
      
      var toString,
          toStringClass,
          classInfo,
          primType;
      
      if ( ( primType = this.getPrimitiveType ( Class ) ) ) {
        
        if ( !this.typeContainer [ primType ] ) {
         return  this.typeContainer [ typeName ] = this.__typeObject [ primType ];
        }else{
          throw new Error ( "The type " + typeName + " is already exist." );
        }
        
      }
      
      if ( Class.__typeID__ && ( classInfo = CONST.CLASS_TABLE [ Class.__typeID__ ] ) ) {
        
        this.__typeString [ CONST.TYPE_PREFIX + typeName + CONST.TYPE_SUFFIX ] = typeName;
        toString = function () {
          return CONST.TYPE_PREFIX + typeName + CONST.TYPE_SUFFIX;
        }
        
        Utils.unenum ( classInfo._class.prototype , CONST.TYPED_PROPERTY , toString )
        
        classInfo [ CONST.TYPED_PROPERTY ] = toString;
        
      }else{
        
        var type = this.typeOf ( Class ),
            ret;
        
        if ( /Document|Window|NodeList|Element|XML/.test ( type ) ) {
          throw new Error ( "Dom object cannot define type." );
        }
        
        toString = function () {
          return CONST.TYPE_PREFIX + typeName + CONST.TYPE_SUFFIX;
        }
        
        toStringClass = function () {
          return CONST.TYPE_PREFIX + "Class" + CONST.TYPE_SUFFIX;
        }
        
        this.__typeString [ CONST.TYPE_PREFIX + typeName + CONST.TYPE_SUFFIX ] = typeName;
        
        if ( type === "Function" ) {
          this.typeContainer [ typeName ] = Class;
          Utils.unenum ( Class.prototype , CONST.TYPED_PROPERTY , toString )
          Utils.unenum ( Class , CONST.TYPED_PROPERTY , toString );
          return Class;
        }else{
          ret =  this.typeContainer [ typeName ] = this.extensible ( Class , type );
          Utils.unenum ( ret , "__typedefed__" , toString );
          Utils.unenum ( ret , CONST.TYPED_PROPERTY , toStringClass );
        }
        
        return ret ();
      }
      
      
    },
    
    /**
     * @param {ANY} o => Primitive instance.
     * @param {Array} => Primitive method names.
     * @returns {Function}
     * @description
     * Create class that has prototype of primitive.
     */
    __extendsPrim : function ( o, methods ) {
      
      var F = function () {
            
        if ( this === global || this === null || !( this instanceof F ) ) {
          
          return new F ();
        
        }else{
          
          Utils.unenum ( this , "toString"  ,  function () { return o.toString.call ( o ); } );
          Utils.unenum ( this , "toLocaleString"  ,  function () { return o.toLocaleString.call ( o ); } );
          Utils.unenum ( this , "valueOf"  ,  function () { return o.valueOf.call ( o ); } );
          
          for ( var i = 0, that = this , len = methods.length; i < len; ++i ) {
            (function ( method ) {
              that [ method ] = function () { 
                return o [ method ].apply ( o , arguments ) 
              };
            }) ( methods [ i ] );
          }
        }
      
      }
      
      F.prototype = o;
      
      Utils.unenum ( F.prototype , "constructor" , F );
      
      return F;
    
    },
    
    /**
     * @param {ANY} o => Primitive instance.
     * @returns {Function}
     * @see Types.__extendsPrim
     */
    extensible : function ( o , type ) {
     
      switch ( type ) {
        case "String":
        case "Boolean":
        case "Array":
          return this.__extendsPrim ( Object ( o ), [] );
        case "Number":
          return this.__extendsPrim ( Object( o ), CONST.NUMBER_PROPS );
        case "Date":
          return this.__extendsPrim ( o , CONST.DATE_PROPS );
        case "RegExp":
          return this.__extendsPrim ( o , CONST.REG_PROPS );
        case "Function":
          return this.__extendsPrim ( o, CONST.FUNCTION_PROPS );
      }
      var F = function () {
            if ( this === global || this === null || ! ( this instanceof F ) ){
              return new F ();
            }
          };
      F.prototype = o;
      
      Utils.unenum ( F.prototype , "constructor" , F );
      
      return F
    },
    
    /**
     * @default "Object"
     * @description
     * Hold user definition type.
     */
    typeContainer : {
      LikeArray : Object
    },
    
    /**
    *@private
    *@default "Object"
    *@description
    *Type object.
    */
    __typeObject : {
      /**
      *@description
      *Builtin types Function
      */
      Function : Function,
      /**
      *@description
      *Builtin types Array.
      */
      Array : Array,
      /**
      *@description
      *Builtin types String.
      */
      String : String,
      /**
      *@description
      *Builtin types int.
      */
      Number : Number,
      /**
      *@description
      *Builtin types Object.
      */
      Object : Object,
      /**
      *@description
      *Builtin types Element.
      */
      Element : {
        toString : function () { return "[object Element]" }
      },
      /**
      *@description
      *Builtin types NodeList
      */
      NodeList : {
        toString : function () { return "[object NodeList]" }
      },
      /**
      *@description
      *Builtin types LikeArray
      */
      LikeArray : {
        toString : function () { return "[object LikeArray]" }
      },
      /**
      *@description
      *Builtin types Window
      */
      Window : {
        toString : function () { return "[object Window]" }
      },
      /**
      *@description
      *Builtin types Document
      */
      Document : {
        toString : function () { return "[object Document]" }
      },
      /**
      *@description
      *Builtin types Boolean
      */
      Boolean : Boolean,
      /**
      *@description
      *Builtin types RegExp
      */
      RegExp : RegExp
    },
    
    /**
    *@private
    *@default "Object"
    *@description
    *Defined type string.
    *type funciton add this object to new type.
    */
    __typeString : {
      "[object Function]"       :   "Function",
      "[object Array]"          :   "Array",
      "[object String]"         :   "String",
      "[object Boolean]"        :   "Boolean",
      "[object Object]"         :   "Object",
      "[object RegExp]"         :   "RegExp",
      "[object Number]"         :   "Number",
      "[object Window]"         :   "Window",
      "[object global]"         :   "Window",
      "[object HTMLDocument]"   :   "Document",
      "[object HTMLCollection]" :   "NodeList",
      "[object Class]"          :   "Class",
      "[object XML]"            :   "XML",
      "[object Iterator]"       :   "Iterator",
      "[object Element]"        :   "Element",
      "[object Date]"           :   "Date",
      "[object MetaClass]"      :   "MetaClass"
    }
    
  }
  
  /**
  *@namespace
  *Cross browser function wrappers.
  */
  XBWrapper = 
  /**lends XBWrapper*/
  {
    /**
    *@returns {XMLHttpRequest|ActiveXObject}
    *Get cross browser XMLHttpRequest.
    */
    wrappedXMLHttpRequest : function () {
      var hasXhr = (function () {
            try {
              var xhr = new XMLHttpRequest ();
              return true;
            }catch (e){
              return false;
            }
          })()
      
      if ( hasXhr ) {
        /**
        *@ignore
        */
        XBWrapper.wrappedXMLHttpRequest = function () {
          return new XMLHttpRequest ();
        }
      }else{
        /**
        *@ignore
        */
        XBWrapper.wrappedXMLHttpRequest = (function () {
          
          var perfectDict = [
            "Msxml2.XMLHTTP.6.0",
            "Msxml2.XMLHTTP.5.0",
            "Msxml2.XMLHTTP.4.0",
            "Msxml2.XMLHTTP.3.0",
            "Msxml2.XMLHTTP",
            "Microsoft.XMLHTTP",
            "Msxml2.ServerXMLHTTP.6.0",
            "Msxml2.ServerXMLHTTP.5.0",
            "Msxml2.ServerXMLHTTP.4.0",
            "Msxml2.ServerXMLHTTP.3.0",
            "Msxml2.ServerXMLHTTP",
            "Microsoft.ServerXMLHTTP"
          ]
          
          for ( var i = 0,len = perfectDict.length; i < len; i++ ) {
            try{
              var ret = new ActiveXObject ( perfectDict [ i ] );
              return function () {
                return new ActiveXObject ( this );
              }.bind ( perfectDict [ i ] )
            }catch (e){}
          }
        })()
      }
      return XBWrapper.wrappedXMLHttpRequest ();
    },
    
    /**
    *@param {Element} elem => Target element.
    *@param {String} type => Event type.
    *@param {Function} fn => Listener function.
    *Cross browser event listener.
    *If this function called at onece,
    *set wrappedRemoveEvent to XBWrapper.
    */
    wrappedEventListener : function ( elem , type , fn ) {
      /**
      *@ignore
      */
      XBWrapper.wrappedEventListener = ( document.addEventListener )?
        (function () {
          /**
          *@ignore
          */
          XBWrapper.wrappedRemoveEvent = function ( elem , type , fn ) {
            elem.removeEventListener ( type , fn , false );
          }
          
          return function ( elem , type , fn ) {
            elem.addEventListener ( type , fn , false );
          }
          
        })() : 
        (function () {
          /**
          *@ignore
          */
          XBWrapper.wrappedRemoveEvent = function ( elem , type , fn ) {
            elem.detachEvent ( "on" + type , fn );
          }
          return function ( elem , type , fn ) {
            elem.attachEvent ( "on" + type , fn );
          }
        })()
      
      XBWrapper.wrappedEventListener ( elem , type , fn );
      
    }
    
    
  }
  
  /**
  *@namespace
  *@description
  *Controll Storage.
  */
  Storage = 
  /**@lends Storage*/
  {
    /**
    *@default "true"
    *@description
    *Browser has localStorage or not.
    */
    hasStorage : (function () {
      try {
        return !!localStorage
      }catch (e){
        return false;
      }
    }) (),
    
    /**
    *@param {String} key => A key of target.
    *@param {String} type => A type of target.
    *@returns {ANY|Object} Storage value. But value is null or undefined, return empty Object.
    *Get specific data of localStolage.
    *Recognized Type value is "json" or null.
    */
    get :  function ( key , type ) {
      if ( this.hasStorage ) {
        this.get = function ( key , type ) {
          try{
            return ( type === CONST.JSON )? JSON.parse ( ( localStorage.getItem ( key ) || "({})" ) ) : localStorage.getItem ( key )
          }catch(e){
            return {};
          }
        }
        return this.get ( key , type )
      }else{
        this.get = Utils.objId;
        return {};
      }
    },
    
    /**
    *@param {String} key => A key of target.)
    *@param {ANY} data => Value
    *@param {String} type => Value type.
    *set a data to localStolage.
    *Recognized Type value is "json" or null.
    */
    set : function ( key , data, type ) {
      if ( this.hasStorage ) {
        this.set = function ( key , data , type ) {
          if ( type === CONST.JSON ) {
            localStorage.setItem ( key , JSON.stringify ( data ) )
          }else{
            localStorage.setItem ( key , data )
          }
        }
        return this.set ( key , data, type )
      }else{
        this.set = Utils.objId;
      }
    },
    
    /**
    *@param {String} key => A key of target.
    *Clear the specific data of localStolage.
    */
    clear : function ( key ) {
      if ( this.hasStorage ) {
        this.clear = function ( key ) {
          localStorage.removeItem ( key )
        }
      }else{
        this.clear = Utils.objId;
      }
    }
  }
  
  
  /**
  *@namespace
  *Utilities.
  */
  Utils = 
  /**@lends Utils*/
  {
    /**
    *@retutns {Object} An empty object.
    *Return empty object.
    */
    objId : function () {
      return {};
    },
    
    isIE6 : navigator.userAgent.indexOf ( "MSIE 6" ),
    isIE7 : navigator.userAgent.indexOf ( "MSIE 7" ),
    isIE8 : navigator.userAgent.indexOf ( "MSIE 8" ),
    isIE9 : navigator.userAgent.indexOf ( "MSIE 6" ),
    
    /**
    *@returns {String} guid.
    *@description
    *Create guid.
    */
    guidgen : function () {
      var rnd = Math.random;
      return ( "{" + [
      
      rnd().toString(16).slice(2, 10),
      rnd().toString(16).slice(2, 6),

      // Set the four most significant bits (bits 12 through 15) of the
      // time_hi_and_version field to the 4-bit version number from Section
      (rnd() * .0625 /* 0x.1 */ + .25 /* 0x.4 */).toString(16).slice(2, 6),

      // Set the two most significant bits (bits 6 and 7) of the
      // clock_seq_hi_and_reserved to zero and one, respectively
      (rnd() * .25 /* 0x.4 */ + .5 /* 0x.8 */).toString(16).slice(2, 6),

      rnd().toString(16).slice(2, 14)
      
      ].join('-') + "}" );
    },
    
    rebuildFilepath : function ( filename ) {
      filename = filename.replace ( /\/[a-zA-Z\-0-9\.]+?\/\.\.\//g, "/" )
      while ( filename.indexOf ( "../" ) > -1 ) {
        filename = filename.replace ( /\/[a-zA-Z\-0-9\.]+?\/\.\.\//g, "/" )
      }
      return filename;
    },
    
    /**
    *@param {ANY} obj => Target object.
    *@param {String} name => Property name.
    *@param {Object} prop => Ecma5's property descriptor.
    *Set target object to unenumerable property.
    */
    unenum : function ( obj , name , prop ) {
      if ( Jspp.__ecma5Extras.hasDefineProperty ) {
        this.unenum = function ( obj , name , prop ) {
          Object.defineProperty ( obj , name , {
            configurable : true,
            writable : true,
            enumerable : false,
            value : prop
          } )
        }
      }else{
        this.unenum = function ( obj , name , prop ) {
          obj [ name ] = prop;
        }
      }
      return this.unenum ( obj , name , prop );
    },
    
    Const : function ( obj , name , def ) {
      
      if ( Object.hasDefineProperty ) {
        
        this.Const = function ( name , def ) {
          if ( typeof name === "string" ) {
            Object.defineProperty ( obj , name , {
              configurable : false,
              writable : false,
              enumerable : true,
              value : def
            } )
          }else if ( Types.baseTypeOf ( name ) === "Object" ){
            for ( var i in name ) {
              Object.defineProperty ( obj , i , {
                configurable : false,
                writable : false,
                enumerable : true,
                value : name [ i ]
              } )
            }
          }
        }
        
      }else{
        
        this.Const = function ( obj , name , def ) {
          if ( typeof name === "string" ) {
            obj [ name ] = def
          }else if ( Types.baseTypeOf ( name ) === "Object" ){
            for ( var i in name ) {
              obj [ i ] = name [ i ]
            }
          }
        }
        
      }
    }
    
  }
  
  extras ( function ( obj , name , prop ) { Utils.unenum ( obj , name , prop ) } );
  
  /**
  *@class
  *Controll class system.
  */
  Class = function ( exports , localEnvs , filename ) {
    this.exports = exports;
    this.localEnvs = localEnvs;
    this.fileName = filename;
    this.modulePath = this.__createModulePath ();
  }
  
  Jspp.extend ( Class.prototype , 
  /**@lends Class.prototype*/
  {
    /**
    *@param {String} className => Class name of class.
    *@param {ANY} opt_var_args => Class inheritance.
    *@returns {Function} Class.prototype.setProps
    *
    *@description
    *Create class.<br />
    *<strong>overview</strong><br />
    *Add className of first arguments to Module local scope, and exports out of Module.
    *If add two underscore before className, added className to scope but not exports out of Module.
    *After first arguments, path to inherit class.
    *firts inheritance is add to prototype chain, and other inheritance is mixed in.
    *Class name is setted to self types, but inherit from super class, self types is super class types.<br />
    *<br />
    *@example
    *<strong>Detail of arguments of class creation.</strong><br />
    *Class ( "example" )
    * (function ( self , privates ) {
    *   //self is like prototype. If you want to add member to class,
    *   //do like this.
    *   <i>self.example = function...<i>
    *   //Now example.example is created.
    *
    *   //If you want to create constructor,
    *   //do like this.
    *   <i>self.__init__ = function () {...}<i>
    *   //__init__ mean use as constructor.
    *   //and about other attribute
    *   //see Classes.prototype.setProp
    * })<br />
    *@example
    *<strong>Detail of class scope.</strong><br />
    *Class ( "sample" )
    * (function ( self, privates ) {
    *   self.__init__ = function () {
    *   }
    * })
    * //Now exports sample class to the out of Module     * //and added to Module local scope.<br />
    *<br />
    *Class ( "__sample" )
    * (function ( self, privates ) {
    *   self.__init__ = function () {
    *   }
    * })
    * //Now sample class is added to Module local scope,
    * //but not exports sample class to the out of Module.
    *
    */
    define : function ( className , opt_var_args ) {
      if ( ( typeof arguments [ 0 ] !== "string" ) ) {
        throw new Error ( "Class arguments 0 need class name string." )
      }
      
      var class_name = Array.prototype.shift.call ( arguments ),
          classData = {
            privates : !class_name.indexOf ( "__" ),
            privateData : { privatesMember : {} },
            constructor : null,
            statics : null,
            singleton : false,
            results : null,
            dynamic : false,
            _final : false,
            _super : null,
            virtual : {},
            isPureVirtual : false,
            className : class_name,
            toString : function () {
              return CONST.TYPE_PREFIX + class_name + CONST.TYPE_SUFFIX
            }
          }
      
      if ( classData.privates ) {
        class_name = class_name.slice ( 2 , class_name.length )
			}
      
      classData._class = this.__createClass ( classData , class_name );
      
      for ( var i = 0 , len = arguments.length; i < len; ++i ) {
        var inherit = arguments [ i ],
            type = typeof inherit;
        
        if ( type === "object" ) {
          if ( i === 0 ) {
            classData._class.prototype = inherit;
          }else{
            Jspp.extend ( classData._class.prototype , inherit )
          }
        }else{
          if ( inherit.__typeID__ ) {
            var classInfo = CONST.CLASS_TABLE [ inherit.__typeID__ ];
            if ( classInfo._final === true ) {
              throw new Error ( "cant inherit." )
            }
            if ( i === 0 ) {
              classData._super = classInfo;
              classData.privateData = classInfo.privateData
              classData._class.prototype = new classInfo._class ();
            }else{
              Jspp.extend ( classData._class.prototype , classInfo._class.prototype )
            }
          }else{
            if ( i === 0 ) {
              classData._class.prototype = new inherit ();
            }else{
              Jspp.extend ( classData._class.prototype , new inherit () )
            }
          }
        }
      }
      
      
      return this.__setProps.bind ( classData ).curry ( this , class_name );
    },
    
    /**
    *@param {Object} obj => Class.
    *@description
    *Apply ecma5's Object.preventExtension to class prototype and class instance.
    */
    __preventExtensions : function ( object ) {
      if ( Object.preventExtensions ) {
        this.__preventExtensions = function ( _object ) {
          Object.preventExtensions ( _object )
        }
        return this.__preventExtensions ( object )
      }else{
        this.__preventExtensions = Jspp.__noop;
      }
    },
    
    /**
    *@param {Object} self => Class context.
    *@param {String} class_name => Class name.
    *@param {Function} memberDefinitionFn => Function that define class.
    *
    *@description
    *This method is called from Class function by bind new class data and curry
    *classes context and new class name.
    *So in fact, this function arguments is only one,
    *that is function of define class.
    *
    *@example
    * //<strong>Detail of class attributes</strong>
    * <b>__init__</b> => Class constructor. If class is instaniated, this method called.
    * <b>__singleton__</b> => This attribute is only property, if setted true to this value,
    * guarant that this class instance is only one.
    * <b>__final__</b> => This attribute is only property, if setted true to this value,
    * this class cant create subclass.
    * <b>__dynamic__</b> => This attribute is only property, if setted true to this value,
    * this class extend like a normal javascript object.
    * <b>__virtual__</b> => If method set to this slot, that method is use as overridable,
    * and, if this class create subclass, subclasses can use this method through
    * third arguments of class creation.
    * <b>__static__</b> => If method set to this slot, that method treat as class method.
    * That mean method can call even if instance not create .
    * <b>__override__</b> => If method set to this slot and has inheritance, override super
    * class method. super class method is must be setted to virtual slot.
    */
    __setProps : function ( self , class_name , memberDefinitionFn ) {
      
      var props = {
        __init__      : Jspp.__noop,
        __singleton__ : false,
        __final__     : false,
        __dynamic__   : false,
        __virtual__   : {},
        __static__    : {},
        __override__  : {}
      },
      that = this,
      isVirtual = false;
      
      var privateData = ( this._super )? this._super.privateData : this.privateData;
      
      if ( !this._super ) {
        CONST.PRIVATE_CLEANER [ CONST.PRIVATE_CLEANER.length ] = privateData;
      }
      
      memberDefinitionFn ( props , self.__privates.bind ( privateData ) , ( this._super )? this._super.virtual : null );
      
      this.constructor = ( ModuleHelper.options.JSPP_DEBUG )? (function () {
        var fn = props.__init__,
            debugfn = function () {
              try{
                fn.apply ( this , arguments )
              }catch ( e ) {
                var script = ( Storage.hasStorage )? JSON.parse ( global.localStorage.scriptModule ) [ self.fileName ].split ( "\n" ) : null,
                error = ( script && ModuleHelper.line )? script [ e.lineNumber - ModuleHelper.line ] : fn.toString ()
                line = ( ModuleHelper.line )? e.lineNumber - ModuleHelper.line : "";
                throw new Error (  e + "\n >> " + error + "\nError occured in " + class_name + "::constructor\n" + self.fileName + " line " + line + "行目"  );
              }
            }
         debugfn.__length__ = fn.__length__;
         return debugfn;
      })() :
      props.__init__
      
      delete props.__init__
    
      this.singleton = props.__singleton__
      delete props.__singleton__
    
      this._final = props.__final__
      delete props.__final__
    
      this.dynamic = props.__dynamic__;
      delete props.__dynamic__
      
      
      Jspp.extend ( this._class , props.__static__ )
      delete props.__static__
      
      Jspp.extend ( this._class.prototype , props.__virtual__ )
      this.virtual = props.__virtual__;
      for ( var prop in this.virtual ) {
        if ( this.virtual [ prop ] === 0 ) {
          this.isPureVirtual = true;
        }
        isVirtual = true;
      }
      delete props.__virtual__;
      
      if ( this._super ) {
        
        for ( var i in props.__override__ ) {
          if ( ( i in this._super.virtual ) && !( i in CONST.NOT_COPIEABLE ) ) {
            this.virtual [ i ] = this._class.prototype [ i ] = props.__override__ [ i ]
          }else{
            throw new Error ( "invalid __override__ member. name : " + i )
          }
        }
        
        delete props.__override__;
        
        for ( var i in props ) {
          if ( !( i in this._super._class.prototype ) ) {
            this._class.prototype [ i ] = props [ i ]
          }else{
            throw new Error ( "class member cant override super class member. To override, use __override__.  Error at : " + this.className + "::" + i )
          }
        }
        
      }else{
        delete props.__override__;
        if ( isVirtual ) {
          Jspp.extend ( this._class.prototype , props )
        }else{
          this._class.prototype = props
        }
      }
      
      
      if ( !this._super ) {
        Utils.unenum ( this._class.prototype , CONST.TYPED_PROPERTY , this.toString )
        Types.__typeString [ CONST.TYPE_PREFIX + class_name + CONST.TYPE_SUFFIX ] = class_name;
      }else{
        Utils.unenum ( this._class.prototype , CONST.TYPED_PROPERTY , this._super.toString )
      }
      
      if ( !this.dynamic ) {
        self.__preventExtensions ( this._class.prototype );
      }
      
    },
    
    /**
    *@param {Object} classData => Class data object.
    *@param {String} className => Class name.
    *@description
    *Create class instance constructor.
    */
    __createClass : function MetaClass ( classData , className ) {
      
      var self = this,
          typeid = this.modulePath,
          constructor;
      
      typeid = typeid.slice ( 0 , typeid.length - 3 ) + "::" + ( classData.className );
      
      CONST.CLASS_TABLE [ typeid ] = classData;
      
      constructor  = function () {
            
        var instance,
            data = CONST.CLASS_TABLE [ constructor.__typeID__ ];
        
        if ( data.results ) {
          return data.results;
        }else if ( this === global || this === null || !( this instanceof constructor ) ) {
          instance = new constructor ();
        }else{
          return this;
        }
        
        

        if ( data.isPureVirtual ) {
          throw new Error ( "Class that has pure virtual method cannot instaniate." )
        }
        
        Utils.unenum ( instance , CONST.CLASS_ID , Utils.guidgen () )
        Utils.unenum ( instance , CONST.TYPED_PROPERTY , data.toString );
        Utils.unenum ( instance , "constructor" , constructor );
        
        if ( data._super ) {
          self.__setSuper ( instance , data , data._super )
        }
        
        if ( data.constructor ) {
          data.constructor.apply ( instance , arguments )
        }
        
        if ( instance.__super__ ) {
          delete instance.__super__
        }
        
        
        if ( ModuleHelper.options.JSPP_DEBUG ) {
          for ( var prop in instance ) {
            
            if ( typeof instance [ prop ] === "function" && !( prop in CONST.NOT_COPIEABLE ) ) {
              
              with ( { old : instance [ prop ] , name : prop } ){
                instance [ prop ] = function () {
                  try{
                    return old.apply ( this , arguments )
                  }catch ( e ){
                    var script = ( Storage.hasStorage )? JSON.parse ( global.localStorage.scriptModule ) [ self.fileName ].split ( "\n" ) : null,
                    error = ( script && ModuleHelper.line )? script [ e.lineNumber - ModuleHelper.line ] : old.toString ()
                    line = ( ModuleHelper.line )? e.lineNumber - ModuleHelper.line : "";
                    throw new Error (  e + "\n >> " + error + "\nError occured in " + className + "::" + name + "\n" + self.fileName + " line " + line + "行目"  )
                  }
                }
                for ( var i in old ) {
                  instance [ prop ] [ i ] = old [ i ]
                }
                instance [ prop ].__length__ = old.length;
              }
              
            }
            
          }
        }
        
        if ( !data.dynamic ) {
          self.__preventExtensions ( instance )
        }
        
        if ( data.singleton ) {
          data.results = instance;
        }
        
        return instance;
        
      }
      
      
      Utils.unenum ( constructor , CONST.TYPED_PROPERTY , this.__toString )
      
      Utils.unenum ( constructor , "__typeID__" , typeid )
      
      
      
      if ( classData.privates ) {
        this.localEnvs [ className ] = constructor
      }else{
        this.localEnvs [ className ] = this.exports [ className ] = constructor
      }
      
      classData = null;
      
      return constructor;
      
    },
    /**
    *@description
    *This toString function set to class instance constructor.
    */
    __toString : function () {
      return CONST.TYPE_PREFIX + "Class" + CONST.TYPE_SUFFIX;
    },
    
    __createModulePath : function () {
      
      return ( 
        Utils.rebuildFilepath ( this.fileName )
        .replace ( ModuleHelper.__basePath , "" )
        .replace ( /\//g , "." )
      )
    },
    /**
    *@param {Object} instance => Class instance.
    *@param {Object} member => Class private member.
    *@description
    *This method called with object like ({privateMember : {}}) binded to context.
    *Create private member.
    */
    __privates : function ( instance , member ) {
      var id = instance.__id__;
      if ( member ) {
        if ( this.privatesMember [ id ] ) {
          Jspp.extend ( this.privatesMember [ id ] , member )
          
        }else{
          this.privatesMember [ id ] = member
        }
      }else{
        return this.privatesMember [ id ];
      }
    },
    
    /**
    *@param {Object} instance => Class instance.
    *@param {Object} class_data => Class data.
    *@param {Object} inherit => Super class.
    *@description
    *Set __super__ method to instance,
    *to defend super method recrusion.
    */
    __setSuper : function ( instance , class_data , inherit ){
      //Set __super__ member.
      instance.__super__ = function callParent () {
          
        //__super__ can call only one time.
        //Set a temporary __super__ for chain call of the __super__;
        //This __super__ has a reference to the inheritances parent __super__.
        this.__super__ = ( inherit._super )? inherit._super.constructor : function(){ throw new Error ( "cant call __super__." ) };
        
        //Call the super class constructor.
        return inherit.constructor.apply ( this , arguments )
        
      }
    }
  })
  
  var path;
  
  /**
  *@class
  *Module sytem's helper function and properties.
  */
  ModuleHelper = 
  /**@lends ModuleHelper*/
  {
    /**
    *@private
    *path of current script file.
    */
    __basePath : ( function ( scriptTag ){
      
      var currentFilePath = scriptTag [ scriptTag.length - 1 ].src;
      
      currentFilePath = ( ( currentFilePath.indexOf( "://" ) > -1 )? 
              currentFilePath : ( currentFilePath.indexOf( "/" ) === 0 )? 
                location.protocol + "//" + location.hostname + currentFilePath : document.URL.slice ( 0 , document.URL.lastIndexOf( "/" ) + 1 ) + currentFilePath )
      
      return path = currentFilePath.slice ( 0 , currentFilePath.lastIndexOf ( "/" ) + 1 )
      
    } )( document.getElementsByTagName ( "script" ) ),
    
    getBasePath : function () {
      return this.__basePath;
    },
    
    setBasePath : function ( path ) {
      this.__requireBasePath = path.replace ( CONST.DIR , CONST.SHORTHAND )
    },
    
    getIncludePath : function ( path ) {
      return this.__requireBasePath
    },
    
    __requireBasePath : path + CONST.MODULE_DIR,
    
    /**
    *@private
    *use as avoiding script cache (especially in Internet Explorer.)
    */
    __rndParam : ( + new Date() ),
    
    /**
    *@private
    *@param { String } currentFilePath => Loading file path.
    *@returns { String }
    *Set a random nember to Module file path, for avoid chache.
    */
    __pathgen : function ( currentFilePath ) {
      return currentFilePath + "?_=" + ( ++ this.__rndParam )
    },
    
    /**
    *@param {String} currentFilePath => FilePath
    *@param {Boolean} isBootMode => boot file or not.
    *@returns { Object ( script : loaded script , fileName : loaded file name. ) }
    *@description
    *Decide load script from cache or send http request by ModuleHelper.prototype.__checkIsCachable.
    *And call __sendRequest.
    *@see ModuleHelper.prototype.__sendRequest
    */
    loadScript : function ( currentFilePath , isBootMode ) {
          
      var cachedScriptInfo = this.__getScriptInfo (),
          scriptCacheInfo  = this.__checkIsCachable ( currentFilePath , isBootMode , cachedScriptInfo ),
          isFromCache      = scriptCacheInfo.isFromCache,
          notFromCache     = scriptCacheInfo.notFromCache
      
      if ( isFromCache && !notFromCache ){
        return {
          script   : cachedScriptInfo [ currentFilePath ] ,
          filename : currentFilePath ,
          cache    : true
        };
      }else if ( notFromCache && ModuleHelper.isDeleted === false ) {
        //Delete cache.
        cachedScriptInfo = {};
        ModuleHelper.isDeleted = true;
      }
      
      return this.__sendRequest ({
        currentFilePath  : currentFilePath ,
        isBootMode       : isBootMode ,
        isFromCache      : isFromCache ,
        cachedScriptInfo : cachedScriptInfo 
      })
      
    },
    
    
    /**
    *@private
    *@returns {Object}
    *Return script information.
    */
    __getScriptInfo : function () {
      return ( ModuleHelper.scriptInfo )? ModuleHelper.scriptInfo : Storage.get ( CONST.SCRIPT_CACHE_NAME , CONST.JSON );
    },
    
    /**
    *@private
    *@param {String} currentFilePath
    *@param {Boolean} isBootMode
    *@param {Object} cachedScriptInfo
    *@returns {Object} <br />=> {isFromCache : cache is useable or not. notFromCache : delete cache or not.}
    *
    *@description
    *Deciding cache is usable and shoud delete cache.
    *If current mode is debug mode, dont delete cahce.
    *If cache parameter of boot option is "false" , dont use cache.
    *When loading bootstrap.js, always load from server.
    *If cache parameter of boot option was true, but version value or boot mode is different from last time,
    *delete cache.
    */
    __checkIsCachable : function ( currentFilePath , isBootMode , cachedScriptInfo ) {
      
      var isVersionEq         = cachedScriptInfo [ currentFilePath + "__version__" ] === ModuleHelper.options.JSPP_VERSION,
          isDebugModeEq       = cachedScriptInfo.debug === ModuleHelper.options.JSPP_DEBUG,
          isScriptCached      = ( currentFilePath in cachedScriptInfo ),
          isSetOptionCache    = ModuleHelper.options.JSPP_CACHE,
          isSetOptionDebug    = ModuleHelper.options.JSPP_DEBUG;
          
      return {
        isFromCache : (
          Storage.hasStorage    && isScriptCached     &&
          isSetOptionCache   && !isSetOptionDebug  &&
          !isBootMode        && isDebugModeEq      &&
          isVersionEq
        ),
        notFromCache : (
          (!isBootMode && ( !isDebugModeEq || !isVersionEq ) ) ||
          !isSetOptionCache
        )
      }
      
    },
    
    /**
    *@private
    *@param {Object} data => 
    *{String} currentFilePath : filepath , 
    *{Boolean} isBootMode : boot mode or not , 
    *{Boolean} isFromCache : is script load from cache or not , 
    *{Object} cachedScriptInfo : script cache that cached in localStorage.
    *@returns { return value of __checkStatus }
    *
    *@description
    *Helper method of loadScript. Create request and send request.
    *If date of last modefied was cached and script was cached, set date of last modified to "if-Modified-since".
    *Except that, set "Thu, 01 Jun 1970 00:00:00 GMT" to "if-Modified-since".
    *@see ModuleHelper.prototype.__checkStatus.
    */
    __sendRequest : function ( data ) {
			
      var xhr = XBWrapper.wrappedXMLHttpRequest (),
          lastTimeKey = data.currentFilePath + CONST.LAST_MODIFIED_SUFFIX,
          cachedLastTime = data.cachedScriptInfo [ lastTimeKey ];
      
      xhr.open ( CONST.GET , this.__pathgen ( data.currentFilePath ) , false );
      
      if ( cachedLastTime && ( data.currentFilePath in data.cachedScriptInfo ) ) {
        xhr.setRequestHeader ( CONST.IF_MODIFIED_SINCE , ( ( cachedLastTime  )? cachedLastTime : CONST.DEFAULT_MODIFIED ) )
      }else{
        xhr.setRequestHeader ( CONST.IF_MODIFIED_SINCE , CONST.DEFAULT_MODIFIED )
      }

      xhr.send ( "" );
      
      data.xhr = xhr
      
      return this.__checkStatus ( data )
      
    },
    
    
    /**
    *@private
    *@param {Object} data => 
    *{String} currentFilePath : filepath , 
    *{Boolean} isBootMode : boot mode or not , 
    *{Boolean} isFromCache : is script load from cache or not , 
    *{Object} cachedScriptInfo : script cache that cached in localStorage.
    
    *@returns {Object} 
    *{String} script : loaded script.
    *{String} fileName : loaded file name.
    *@description
    *Check the server returning header, confirm use cache or not.
    */
    __checkStatus : function ( data ) {
      
      var lastModifiedKey = data.currentFilePath + CONST.LAST_MODIFIED_SUFFIX;
      
      if ( data.xhr.status === 304 && ( data.currentFilePath in data.cachedScriptInfo ) ){
        return {
          script : data.cachedScriptInfo [ data.currentFilePath ] ,
          filename : data.currentFilePath ,
          cache : true
        };
      }else if ( data.xhr.status === 0 || data.xhr.status === 404 ) {
        throw new Error ( data.currentFilePath + " is not proper path." )
      }
      
      if ( data.xhr.getAllResponseHeaders ().indexOf ( CONST.LAST_MODIFIED ) > -1 && !data.isBootMode ){
        data.cachedScriptInfo [ lastModifiedKey ] = data.xhr.getResponseHeader ( CONST.LAST_MODIFIED )
      }else if ( data.isBootMode ) {
        if ( data.xhr.getAllResponseHeaders ().indexOf ( CONST.LAST_MODIFIED ) > -1 ) {
          data.cachedScriptInfo.latest = data.xhr.getResponseHeader ( CONST.LAST_MODIFIED )
        }
      }
      
      ModuleHelper.scriptInfo = data.cachedScriptInfo
      
      var ret = {
        script : data.xhr.responseText ,
        filename : data.currentFilePath
      };
      
      delete data.xhr;
      data = null
      
      return ret;
      
    },
    
    /**
    *@param {Boolean} isEnv => Use env of not.
    *@param {Object} FileObject => 
    *{String} script : script string.
    *{String} fileName : file name of script.
    *@returns {String} Processed script string.
    *@description
    *Process script string for evaluation.
    *Wrap string in with and in anonymous function, to create scope.
    */
    __getWrappedScript : function ( isEnv , FileObject ) {
      return Macro.replace ( ( isEnv && !FileObject.cache )? ( "with ( this ){\n(function(){" + FileObject.asstrict + ( ( ModuleHelper.options.JSPP_DEBUG )? ( FileObject.script.replace ( rsdebug , "//$1" ).replace ( redebug , "//$1" ) ) : FileObject.script.replace ( rsdebug , "/*$1" ).replace ( redebug , "$1*/" ) ) + "})();\n};" ) : FileObject.script )
    },
    
    /**
    *@param {String} name => current Module name.
    *@description
    *Use in minified script file.
    *Use like require function, but loading target is not in external file but in same file.
    */
    globalExports : function ( name ) {
      var ret;
      if ( ( ret = this.results.namedModuleResults [ name ] ) ) {
        return ret;
      }else if ( ( ret = this.results.exports [ name ] ) ) {
        ret = this.results.namedModuleResults [ name ] = this.results.exports [ name ] ( name );
        return ret;
      }
    },
    
    /**
    *@param {String} name => Module name.
    *@param {Function} fn => Module.
    *@description
    *Use in minified script file.
    *Regist same file Module.
    */
    regist : function ( name , fn ) {
      this.results.exports [ name ] = fn;
    },
    
    /**
    *@private
    *@default "Array"
    *@description
    *Holder of Module file name for check recrusive reference.
    */
    __called : {},
    
    loadExternalScript : function ( script , callback ) {
      
      if ( "onreadystatechange" in script ) {
        script.onreadystatechange = function () {
          if ( CONST.READY_STATE.indexOf ( script.readyState ) > -1 ) {
            script.onreadystatechange.callback ();
            script.onreadystatechange = Jspp.__noop;
          }
        }
        script.onreadystatechange.callback = callback || Jspp.__noop;
      }else{
        script.onload = function () {
          script.onload.callback ();
          script.onload = Jspp.__noop;
        }
        script.onerror = function () {
          throw new Error ( script.src + " is not proper path." )
        }
        script.onload.callback = callback || Jspp.__noop;
      }
      
      document.head.insertBefore ( script , document.head.firstChild )
      
    },
    
    imports : function ( pathToScripts , callback ) {
      
      for ( var i = 0,len = pathToScripts.length; i < len; ++i ) {
        var script = CONST.SCRIPT_TAG.cloneNode ( true );
        
        script.type = CONST.SCRIPT_TYPE;
        script.src = pathToScripts [ i ].replace ( CONST.DIR , CONST.SHORTHAND )
        
        if ( i === len - 1 ) {
          this.loadExternalScript ( script , callback );
        }else{
          this.loadExternalScript ( script , null );
        }
        
      }
    },
    
    depends : function ( pathToScripts , callback ) {
      var script = CONST.SCRIPT_TAG.cloneNode ( true ),
          next,
          _callback = function () {
            pathToScripts.shift ()
            if ( pathToScripts.length > 0 ) {
              return ModuleHelper.depends ( pathToScripts , callback )
            }else{
              return callback ();
            }
          }
      
      script.type = CONST.SCRIPT_TYPE;
      script.src = pathToScripts [ 0 ].replace ( CONST.DIR , CONST.SHORTHAND );
      this.loadExternalScript ( script , _callback );
    },
    
    std : {},
    
    /**
    *@namespace
    *Hold Module evaluation result.
    */
    results : {
      /**
      *@default "Object"
      *@description
      *Hold result of Module evaluattion.
      *Module file has two pattern for add result to results object.
      *@example 
      *One is use exports object. Like this. 
      *exports.sample = sampleFunction
      *Now sampleFunction is exported.<br />
      *One is use exports object. Like this.
      *Class ( "sample" )
      * (function( self , privates ){
      *   self.__init__ = function () { ... }
      * })
      *Now sample class is exported.
      */
      exports : {},
      
      /**
      *@default "Object"
      *@description
      *Use in minified script file.
      *Hold result of Module.prototype.regist.
      */
      namedModuleResults : {}
    },
    
    /**
    *@namespace
    *Boot option.
    */
    options : {
      /**
      *@default "false"
      *@description
      *Boot as debug mode or not.
      */
      JSPP_DEBUG : false,
      
      /**
      *@default "true"
      *@description
      *Cache script file or not.
      */
      JSPP_CACHE : true,
      
      /**
      *@default "true"
      *@description
      *Boot as strict mode or not.
      *If boot as strict mode, all Module load as strict mode.
      */
      JSPP_USE_STRICT : true,
      
      /**
      *@default "0"
      *@description
      *A version of script.
      *This value is use for delete old version cache.
      */
      JSPP_VERSION : 0,
      
      /**
      *@default "false"
      *@description
      *Use minifieded script file or not.
      *If seted true to this value,
      *"-min.js" added to main file path.
      */
      JSPP_USE_MINIFIED : false,
      
      /**
      *@default "null"
      *@description
      *If main poarameter was setted by bootstrap.js,
      *this value is setted.
      */
      JSPP_MAIN : null,
      
      /**
      *@default "Array"
      *@description
      *If args parameter was setted by bootstrap.js,
      *this value is setted.
      *This value is passed to main function of main file.
      */
      JSPP_ARGS : [],
      
      /**
      *@default  "Array"
      *@description
      *Impoert external javascript file.
      */
      JSPP_IMPORTS : [],
      
      /**
      *@default  "Array"
      *@description
      *Impoert external javascript file by order.
      */
      JSPP_DEPENDS : [],
      
      /**
      *@default "null"
      *@description
      *require include paths. 
      */
      JSPP_PATH : null,
      
      JSPP_LIB : {}
      
    }
  };
  
  
  /**
  *@class
  *@param {String} relativePath => Current Module path.
  *@returns {Function} require function.
  *@description
  *Return require function seted each file to base path.
  */
  Module = function ( relativePath , path ) {
    
    if ( relativePath ) {
      this.__basePath = relativePath.slice ( 0 , relativePath.lastIndexOf ( "/" ) + 1 );
    }else{
      this.__basePath = ModuleHelper.requireBasePath;
    }
    
    this.__includePath = ModuleHelper.getIncludePath ();
    
    this.__from = relativePath;
    
  };
  
  var rsdebug = /(\#ifdebug)/g,
      redebug = /(\#endif)/g,
      rurl    = /([^/]*?\/)(\.\.\/)/g;
  
  
  Jspp.extend ( Module.prototype , 
  /**@lends Module.prototype*/
  {
    /**
    *@param {String} currentFilePath => File path.
    *@param {Boolean} isEnv => Use env or not.
    *@param {Boolean} isBootMode => Is boot mode or not.
    *@returns {Object} exported Module class or function.
    *@description
    *Load external Module.
    *Searched file path is called Module directory.
    *Cant load differ domain file.
    *@example 
    *Load normal Module file. <b>require ( "../sample.js" );</b>
    *Load external library like jQuery. <b>require ( "../jQuery.js" , <i>false<i> ( disable envs ) );</b>
    *
    */
    require : function ( currentFilePath , isEnv , isBootMode , isMain ) {
      
      var fullFilePath,
          optionAppliedPath;
      
      if ( CONST.MOD_STD [ currentFilePath ] ) {
        
        optionAppliedPath = ModuleHelper.__basePath + CONST.MOD_STD [ currentFilePath ] + currentFilePath + ".js"
      }else if ( ModuleHelper.options.JSPP_LIB [ currentFilePath ] ) {
        optionAppliedPath = ModuleHelper.__basePath + "jspp-lib" + ModuleHelper.options.JSPP_LIB [ currentFilePath ] + ".js";
      }else{
        
        fullFilePath = ( isBootMode )? ModuleHelper.__basePath + currentFilePath + ".js" : 
          ( isMain )? currentFilePath :
          ( ( !currentFilePath.indexOf ( "./" ) || !currentFilePath.indexOf ( "../" ) )? this.__basePath + currentFilePath : 
            ( !currentFilePath.indexOf ( "/" ) )? CONST.ROOT + currentFilePath.slice ( 1 ) : 
            this.__includePath + currentFilePath ) + ".js";
        
        optionAppliedPath = ( ModuleHelper.options.JSPP_USE_MINIFIED && !isBootMode )? fullFilePath.slice ( 0 , fullFilePath.lastIndexOf ( "." ) ) + "-min.js" : fullFilePath;
        
        optionAppliedPath = Utils.rebuildFilepath ( optionAppliedPath ).replace ( /\.\//g, "" );
      }
      //To check recurusive refference,
      //cache loading file and loaded file.
      if ( this.__from && ModuleHelper.__called [ this.__from ] ) {
        ModuleHelper.__called [ this.__from ] [ optionAppliedPath ] = true;
      }else if ( this.from ) {
        ModuleHelper.__called [ this.__from ] = {};
        ModuleHelper.__called [ this.__from ] [ optionAppliedPath ] = true;
      }
      
      //Check recrusive refference.
      if ( ModuleHelper.__called [ optionAppliedPath ] && ModuleHelper.__called [ optionAppliedPath ] [ this.__from ] ) {
        throw new Error ( "Circular reference occured. current Module name : " + this.__from + " target Module name " + optionAppliedPath );
      }
      
      //Already loaded Module,
      //return result.
      return ( ModuleHelper.results.exports [ optionAppliedPath ] )?
        {
          cached  : true,
          results : ModuleHelper.results.exports [ optionAppliedPath ]
        }:
      { results : ModuleHelper.loadScript ( optionAppliedPath , isBootMode ) }
      
    },
    
    setActivePath : function ( path ) {
      path = path.replace (  CONST.DIR , CONST.SHORTHAND );
      this.__includePath = path;
    },
    
    getActivePath : function () {
      return this.__includePath;
    }
    
  });
  
  /**
  *@private
  *@class
  *Builtin class definition.
  */
  Builtin = function () {};
  
  var _assert = function( cond , opt_m_f ){
    if( ModuleHelper.options.JSPP_DEBUG === true && !cond ){
      if ( !type ) {
        throw new Error ( "Assertion fail." );
      }
      var type = typeof opt_m_f;
      if( type === "string" ){
        throw new Error( opt_m_f );
      }else if( type === "function" ){
        opt_m_f();
      }
    }
  }
  
  Builtin.prototype = Types.typeContainer;
  
  Jspp.extend ( Builtin.prototype ,
  /**@lends Builtin.prototype*/
  {
    /**
    *@methodOf Builtin.prototype
    *@see Types.typeOf
    */
    typeOf : Types.typeOf.bind ( Types ),
    /**
    *@methodOf Builtin.prototype
    *@see Types.isType
    */
    isType : Types.isType.bind ( Types ),
    /**
    *@methodOf Builtin.prototype
    *@see Types.baseTypeOf
    */
    baseTypeOf : Types.baseTypeOf.bind ( Types ),
    /**
    *@methodOf Builtin.prototype
    *@see Types.typeFrom
    */
    typeFrom : Types.typeFrom.bind ( Types ),
    /**
    *@methodOf Builtin.prototype
    *@see Types.isPrimitive
    */
    isPrimitive : Types.isPrimitive.bind ( Types ),
    /**
    *@methodOf Builtin.prototype
    *@see Types.type
    */
    type : Types.type.bind ( Types ),
    /**
    *@methodOf Builtin.prototype
    *@see Jspp.extend
    */
    extend : Jspp.extend,
    
    /**
    *@public
    *@description
    *Free ModuleHelper.scriptInfo data.<br />
    *<strong>Notice</strong>
    *You must use _free_ after all module loaded.
    */
    _free_ : function () {

      if ( CONST.IS_SCRIPT_FREE === false ) {
        
        Storage.set (  CONST.SCRIPT_CACHE_NAME , ModuleHelper.scriptInfo , CONST.JSON )
        
        for ( var i in ModuleHelper.scriptInfo ) {
          delete ModuleHelper.scriptInfo [ i ];
        }
        
        CONST.IS_SCRIPT_FREE = true;
      }
      
    },
    
    /**
    *@param {ANY} value => Target object.
    *@returns {Boolean}
    *@description
    *Distinct value is null or undefined.
    */
    isDef : function ( value ) {
      return value !== undefined && value !== null;
    },
    
    /**
    *@methodOf Builtin.prototype
    *@see Utils.guidgen
    */
    guidgen : Utils.guidgen,
    
    /**
    *@param {String} str => String include number expression.
    *@returns {int}
    *Covert string to int.
    *If result of convertion is NaN,
    *then return zero.
    */
    toInteger : function ( str ) {
      var type = typeof str,
          ret
      if ( str === undefined || str === null ) {
        return 0;
      }else if ( type === "string" ||  type === "number" ){
        ret = parseInt ( str , 10 );
        return ( isNaN ( ret ) )? 0 : ret;
      }else{
        return 0;
      }
    },
    
    /**
    *@namespace
    *Assertion.
    */
    assert : {
      True : function( cond , opt_m_f ){
        _assert ( cond , opt_m_f )
      },
      False : function( cond , opt_m_f ){
        _assert ( !cond , opt_m_f )
      },
      Eq : function( cond1 , cond2 , opt_m_f ){
        _assert ( cond1 === cond2 , opt_m_f )
      },
      Noteq : function( cond1 , cond2 , opt_m_f ){
        _assert ( cond1 !== cond2 , opt_m_f )
      },
      Null : function( cond , opt_m_f ){
        _assert ( cond !== null , opt_m_f )
      },
      Undef : function( cond , opt_m_f ){
        _assert ( cond !== undefined , opt_m_f )
      },
      Type : function( type , target , opt_m_f ){
        _assert ( type !== Base.typeOF( target ) , opt_m_f )
      },
      fail : function( opt_m_f ){
        _assert ( false , opt_m_f )
      }
    },
    
    JSPP_XMLHttpRequest : XBWrapper.wrappedXMLHttpRequest,
    level :  function( obj , m , fn ){
      var m_n = m.split( "." ),
          len = m_n.length - 1,
          tm,
          count = 0,
          iter = -1;
      
      while( ( tm = m_n[ ++iter ] ) ){
        if( obj === undefined || obj === null || obj[ tm ] === null || obj[ tm ] === undefined  ){
          if( len !== iter ){
            obj[ tm ] = {}
            obj = obj[ tm ]
            ++count;
          }else{
            if( fn ){
              obj = fn( obj , tm , count )
            }
          }
        }else{
          obj = obj[ tm ]
        }
      }
      return obj;
    },
    destroy : function ( fn ) {
      if ( typeof fn === "function" ) {
        CONST.DESTROY [ CONST.DESTROY.length ] = fn;
      }else{
        throw new Error ( "arguments of destroy is must Function." )
      }
    },
    singleton : function ( fn ) {
      var singletonFn = function () {
        return ( singletonFn.cache )?  (function ( c ) { fn = null; singletonFn = function () { return singletonFn.cache };singletonFn.cache = c; c = null; return singletonFn.cache })( singletonFn.cache ) : ( singletonFn.cache = fn () );
      }
      return singletonFn;
    }
    
  });
  
  
  (function () {
    var isready = false,
        ready = [];
    if( document.addEventListener ){
      global.addEventListener( "DOMContentLoaded" , function(){
        isready = true;
        ready.forEach(function( fn ){
          fn();
        })
        ready.length = 0;
      } , false )
    }else{
      (function checkInit(){
        try{
          (new Image).doScroll();
          isready = true;
          ready.forEach(function( fn ){
            fn();
          })
          ready.length = 0;
        }catch(e){
          setTimeout( checkInit , 64 )
        }
      })();
    }
    
    Jspp.extend ( Builtin.prototype ,
    /**@lends Builtin.prototype*/
    {
      ready : function ( fn ) {
        if ( isready === false ) {
          ready.push ( fn )
        }else{
          fn ();
        }
      }
    });
    
  })();
  
  /**
  *@class
  *@extends Builtin
  *@description
  *Module local enviorment.
  */
  Envs = function () {};
  
  Envs.prototype = new Builtin ();
  
  Macro = {
    defreg : /\#define(?:\s+?)([a-zA-Z_][a-zA-Z0-9_]*?)(?:\s+?)([\s\S]+?)\#enddef/g,
    rdef : /#define[\s\S]+?#enddef/g,
    srdef : /#define[\s\S]+?#enddef/,
    paren : /\(([a-zA-Z_,0-9\s]*?)\)/,
    space : /[\s\t]+/g,
    n     : /\n|\r\n|\n\r/,
    rreturn : /return[\s\t]/,
    vars : /[a-zA-Z0-9_\[\]\"\']/,
    replace : function ( script ) {
      var that = this,
          ret,
          macroFn,
          vargs,
          fnBody,
          reg;
      
      while ( ( ret = this.defreg.exec ( script ) ) && ret [ 0 ] ) {
        if ( !( ( macroFn = ret [ 2 ].trim () ).indexOf ( "(" ) ) ) {
          vargs = macroFn.match ( this.paren );
          if ( vargs && vargs [ 0 ] ) {
            if ( vargs [ 1 ] ) {
              vargs = vargs [ 1 ].replace ( this.space , "" );
              vargs = vargs.split ( "," );
            }else{
              vargs = [];
            }
            reg = macroFn.replace ( this.paren , "" ).trim ();
            fnBody = reg = ( reg.charAt ( reg.length ) === ";" )? reg.slice ( 1 , reg.length - 2 ) : reg.slice ( 1 , reg.length - 1 );
            reg = new RegExp ( ret [ 1 ] + "\\s*?\\(([\\s\\S]*?)\\)" );
            script = script.replace ( this.srdef , "" );
            script = script.replace ( reg , function ( $$ , $1 , num ) {
              retFn = fnBody;
              var tmpArg = $1.replace ( that.space , "" ).split ( "," );
              for ( var i = 0,len = tmpArg.length; i < len; ++i ) {
                if ( vargs.length > i ) {
                  var rarg = new RegExp ( vargs [ i ] , "g" ),
                      retFn = retFn.replace ( rarg , tmpArg [ i ] );
                }
              }
              return retFn;
            })
          }
        }else{
          script = script.replace ( new RegExp ( ret [ 1 ] , "g" ) , ret [ 2 ] );
          script = script.replace ( this.rdef , "" );
        }
      }
      return script;
    }
  }
  
  XBWrapper.wrappedEventListener ( window , "unload" , function () {
    for ( var i = 0,len = CONST.DESTROY.length; i < len; ++i ) {
      CONST.DESTROY [ i ] ();
    }
    CONST.DESTROY.length = 0;
    
    for ( var className in CONST.CLASS_TABLE ) {
      delete CONST.CLASS_TABLE [ className ];
    }
    
    if ( CONST.IS_SCRIPT_FREE === false ) {
      Storage.set (  CONST.SCRIPT_CACHE_NAME , ModuleHelper.scriptInfo , CONST.JSON );
    }
    
    for ( var i in ModuleHelper.scriptInfo ) {
      delete ModuleHelper.scriptInfo [ i ];
    }
    delete ModuleHelper.scriptInfo;
  } );
  
  CONST.DESTROY.push ( function () {
    for ( var i = 0,len = CONST.PRIVATE_CLEANER.length; i < len; ++i ) {
      for ( var privateData in CONST.PRIVATE_CLEANER [ i ] ) {
        delete CONST.PRIVATE_CLEANER [ i ] [ privateData ];
      }
    }
  } );
  
  var loadMain = function () {
    if ( ModuleHelper.options.JSPP_MAIN ) {
      var ret = new Jspp_ModuleContext ().loadModule ( ModuleHelper.options.JSPP_MAIN.replace ( CONST.DIR , CONST.SHORTHAND ) , true , false , true );
      if ( ret.main ) {
        ret.main.apply ( null ,  ModuleHelper.options.JSPP_ARGS );
      }else{
        throw new Error ( "Cant find entry point. main file need function::main ()." );
      }
    }
  };
  
  new Jspp_ModuleContext ( ModuleHelper.getBasePath () ).loadModule ( null , null , true );
  
  if ( ModuleHelper.options.JSPP_PATH ) {
    ModuleHelper.setBasePath ( ModuleHelper.options.JSPP_PATH );
  }
  
  var imports = ModuleHelper.options.JSPP_IMPORTS,
      depends = ModuleHelper.options.JSPP_DEPENDS;
  
  if ( imports.length > 0 && depends.length > 0 ) {
    ModuleHelper.imports ( imports , function () {
      ModuleHelper.depends ( depends , function () {
        loadMain ();
      } )
    } )
  }else if ( imports.length > 0 ) {
    ModuleHelper.imports ( imports , function () {
      loadMain ();
    } )
  }else if ( depends.length > 0 ) {
    ModuleHelper.depends ( depends , function () {
      loadMain ();
    } )
  }else{
    loadMain ();
  }
  
  
})
(
  (function () {
    return this || window;
  })(),
  
  function ( unenum ) {
    
    try{
      if ( !document.head ) {
        document.head = document.getElementsByTagName ( "head" ) [ 0 ];
      }
    }catch (e){
    }
    
    if( !String.prototype.trim ){
      String.prototype.trim = function(){
        return this.replace( String.prototype.trim.rtrim , "" );
      }
      String.prototype.trim.rtrim = /^\s*|\s*$/g;
    }
    
    if ( !String.prototype.toJSON ) {
      unenum ( String.prototype , "toJSON" , function () {
        return this.toString ();
      })
    }
    
    if ( !Boolean.prototype.toJSON ) {
      unenum (  Boolean.prototype , "toJSON" , function () {
        return this.toString ();
      })
    }
    
     //Function extends compatible with Ecma5's Function.bind
    if( !Function.prototype.bind ){
      Function.prototype.bind = function( targetContextObject ){
        var ret = function(){
          return ret.context.apply( targetContextObject , arguments );
        }
        ret.context = this;
        unenum ( ret , "__length__" , this.length );
        return ret;
      }
    }
    
    if( !Function.prototype.when ){
      unenum ( Function.prototype , "when" , function( fn ){
        var ret = function(){
          return ( fn.apply ( this , arguments ) )? this.apply ( this , arguments ) : null;
        }.bind ( this )
        unenum ( ret , "__length__" , this.length );
        return ret;
      })
    }
    
    if ( !Function.prototype.curry ) {
      (function () {
        var curry = function ( fn , len , arg , context ) {
          if ( len <= 0 ){
            return fn.apply ( context , arg );
          }
          return function () {
            return curry ( fn , len - arguments.length , arg.concat ( slice.call ( arguments ) ) , this );
          };
        },
        slice = Array.prototype.slice;
        
        unenum ( Function.prototype , "curry" , function () {
          return curry ( this , ( this.__length__ || this.length ) - arguments.length , slice.call ( arguments ) , null )
        })
        
        if ( !Function.prototype.ncurry ) {
          unenum ( Function.prototype , "ncurry" , function ( num ) {
            return curry ( this , num , [] , this )
          })
        }
        
      })()
    }
    
    
    //Array extends compatible with javascript1.8 & Ecma5 Array extras
    if( !Array.prototype.forEach ){
      Array.prototype.forEach = function( fn , that ){
        var iter = -1,
            ta;
        if( that ){
          while( ( ta = this[ ++iter ] ) ){
            fn.call( that , ta , iter , this );
          }
        }else{
          while( ( ta = this[ ++iter ] ) ){
            fn( ta , iter , this );
          }
        }
      }
    }
    if( !Array.prototype.every ){
      Array.prototype.every = function( fn , that ){
        var iter = -1,
            ta;
        if( that ){
          while( ( ta = this[ ++iter ] ) ){
            if( ! ( fn.call( that , ta , iter , this ) ) ){
              return false;
            }
          }
        }else{
          while( ( ta = this[ ++iter ] ) ){
            if( !( fn( ta , iter , this ) ) ){
              return false;
            }
          }
        }
        return true;
      }
    }
    if( !Array.prototype.some ){
      Array.prototype.some = function( fn , that ){
        var iter = -1,
            ta;
        if( that ){
          while( ( ta = this[ ++iter ] ) ){
            if( fn.call( that , ta , iter , this ) === true ){
              return true;
            }
          }
        }else{
          while( ( ta = this[ ++iter ] ) ){
            if( fn( ta , iter , this ) === true ){
              return true;
            }
          }
        }
        return false;
      }
    }
    if( !Array.prototype.filter ){
      Array.prototype.filter = function( fn , that ){
        var iter = -1,
            ret = [],
            ta;
        if( that ){
          for( var i = 0,len = this.length; i < len; ++i ){
            if( ( ta = this[ i ] ) ){
              if( fn.call( that , ta , i , this ) ){
                ret[ ++iter ] = ta;
              }
            }
          }
        }else{
          for( var i = 0,len = this.length; i < len; ++i ){
            if( ( ta = this[ i ] ) ){
              if( fn( ta , i , this ) ){
                ret[ ++iter ] = ta;
              }
            }
          }
        }
        return ret;
      }
    }
    if( !Array.prototype.indexOf ){
      Array.prototype.indexOf = function( subject ){
        var iter = -1,
            index = -1,
            ta;
        while( ( ta = this[ ++iter ] ) ){
          if( ta === subject ){
            index = iter;
            break;
          }
        }
        return index;
      }
    }
    if( !Array.prototype.lastIndexOf ){
      Array.prototype.lastIndexOf = function( subject ){
        var iter = this.length,
            index = -1,
            ta;
        while( ( ta = this[ --iter ] ) ){
          if( ta === subject ){
            index = iter;
            break;
          }
        }
        return index;
      }
    }
    if( !Array.prototype.map ){
      Array.prototype.map = function( fn , that ){
        var ret = [],
            iter = -1,
            ta;
        if( that ){
          for( var i = 0,len = this.length; i < len; ++i ){
            if( ( ta = this[ i ] ) ){
              ret[ ++iter ] = fn.call( that , ta , i , this );
            }
          }
        }else{
          for( var i = 0,len = this.length; i < len; ++i ){
            if( ( ta = this[ i ] ) ){
              ret[ ++iter ] = fn( ta , i , this );
            }
          }
        }
        return ret;
      };
    }
    if( !Array.prototype.reduce ){
      Array.prototype.reduce = function( fn , initial ){
        var ret = initial || this[ 0 ],
            i = ( initial )? 0 : 1,
            ta;
        for( i,len = this.length; i < len; ++i ){
          if( ( ta = this[ i ] ) ){
            ret = fn( ret , ta , i , this );
          }
        }
        return ret;
      };
    }
    if( !Array.prototype.reduceRight ){
      Array.prototype.reduceRight = function( fn , initial ){
        var ret = initial || this[ this.length - 1 ],
            i = ( initial )? this.length - 1 : this.length - 2,
            ta;
        for( i; i > -1; --i ){
          if( ( ta = this[ i ] ) ){
            ret = fn( ret , ta , i , this );
          }
        }
        return ret;
      };
    }
    
    if ( !Date.prototype.toJSON ) {
      Date.prototype.toJSON = function() {
        
        return '"' + this.getUTCFullYear () + '-' +
          "0" + ( this.getUTCMonth () + 1 ) + '-' +
          "0" + ( this.getUTCDate () - 1 ) + 'T' +
          this.getUTCHours () + ':' +
          this.getMinutes () + ':' +
          this.getSeconds () + '.' +
          this.getUTCMilliseconds () + '"';
      };
    }
    
    if ( !Object.keys ) {
      Object.keys = function ( obj ) {
        var ret = [],
            iter = -1;
        
        for ( var i in obj ) {
          if ( obj.hasOwnProperty ( i ) ) {
            ret [ ++iter ] = obj [ i ]
          }
        }
        
        return ret;
        
      };
    }
    
    if (!Object.prototype.__defineGetter__ &&
        Jspp.__ecma5Extras.hasDefineProperty ) {
      
      Object.defineProperty( Object.prototype , "__defineGetter__", {
        enumerable   : false,
        configurable : true,
        value        : function ( name , func ) {
          Object.defineProperty( this , name , {
            get          : func,
            enumerable   : true,
            configurable : true
          });
        }
      });
      Object.defineProperty( Object.prototype , "__defineSetter__" , {
        enumerable   : false,
        configurable : true,
        value        : function ( name , func ){
          Object.defineProperty ( this , name , {
            set          : func,
            enumerable   : true,
            configurable : true
          });
        }
      });
    }
    
  }
  
)

