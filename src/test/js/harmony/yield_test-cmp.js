(function() {
  
  var p/*_mochaGlobalExport*/ = {};
  
  ( function ( g/*_mochaLocalTmp0*/,h/*_mochaLocalTmp1*/,i/*_mochaLocalTmp2*/,j/*_mochaLocalTmp3*/ ) {
    var a/*stringProto*/ = g/*_mochaLocalTmp0*/.prototype,
        k/*arrayProto*/ = h/*_mochaLocalTmp1*/.prototype,
        l/*functionProto*/ = i/*_mochaLocalTmp2*/.prototype,
        m/*dateProto*/ = j/*_mochaLocalTmp3*/.prototype;
    
    "use strict";
    
    function n/*builtinTypeError*/( d/*message*/ ) {
      try {
        throw new TypeError( d/*message*/ );
      } catch( e ){
        throw new Error( e );
      };
    };
    
    function o/*callbackCheck*/( a/*callback*/,b/*type*/ ) {
      
      if ( typeof a/*callback*/ !== "function" ){
        n/*builtinTypeError*/( b/*type*/+" : first argument is not callable" );
      };
    };
    
    if ( !Object.keys ){
      Object.keys = function ( b/*obj*/ ) {
        if ( !b/*obj*/ ){
          n/*builtinTypeError*/( "Object.keys : first arguments is null or not defined." );
        };
        
        var c/*ret*/ = [],
            d/*iter*/ = -1;
        
        for ( var i in b/*obj*/ ){
          if ( b/*obj*/.hasOwnProperty( i ) ){
            c/*ret*/[ ++ d/*iter*/] = b/*obj*/[i];
          };
        };
        return c/*ret*/;
      };
    };
    
    if ( !Object.preventExtensions ){
      Object.preventExtensions = function ( a/*o*/ ) {
        return a/*o*/;
      };
    };
    
    if ( !Object.seal ){
      Object.seal = function ( a/*o*/ ) {
        return a/*o*/;
      };
    };
    
    if ( !Object.freeze ){
      Object.freeze = function ( a/*o*/ ) {
        return a/*o*/;
      };
    };
    
    var p/*hasRealEcma5*/ = ( function () {
          var c/*ret*/;
          
          try {
            var d/*obj*/ = {};
            
            Object.defineProperty( d/*obj*/,"test", {
              configurable : false,
              writable : false,
              enumerable : false,
              value : 0
            });
            
            d/*obj*/.test = 200;
            
            c/*ret*/ = ( d/*obj*/.test === 200 )?false : true;
          } catch( e ){
            c/*ret*/ = false;
          };
          return c/*ret*/;
        })();
    
    if ( !p/*hasRealEcma5*/ ){
      Object.defineProperty = function ( a/*obj*/,b/*prop*/,c/*valobj*/ ) {
        if ( c/*valobj*/.value ){
          a/*obj*/[b/*prop*/] = c/*valobj*/.value;
        };
      };
    };
    
    if ( !a/*stringProto*/.trim ){
      a/*stringProto*/.trim = function () {
        return this.replace( stringProto.trim.rtrim,"" );
      };
      
      a/*stringProto*/.trim.rtrim = /^\s*|\s*$/g;
    };
    
    if ( !a/*stringProto*/.repeat ){
      Object.defineProperty( a/*stringProto*/,"repeat", {
        value : function q/*value*/( b/*num*/ ) {
          return Array( b/*num*/+1 ).join( this.toString() );
        },
        configurable : true,
        enumerable : false,
        writable : true
      });
    };
    
    if ( !a/*stringProto*/.startsWith ){
      Object.defineProperty( a/*stringProto*/,"startsWith", {
        value : function q/*value*/( a/*str*/ ) {
          return !this.indexOf( a/*str*/ );
        },
        configurable : true,
        enumerable : false,
        writable : true
      });
    };
    
    if ( !a/*stringProto*/.endsWith ){
      Object.defineProperty( a/*stringProto*/,"endsWith", {
        value : function q/*value*/( b/*str*/ ) {
          var c/*t*/ = String( b/*str*/ );
          
          var d/*index*/ = this.lastIndexOf( c/*t*/ );
          return d/*index*/ >= 0 && d/*index*/ === this.length-c/*t*/.length;
        },
        configurable : true,
        enumerable : false,
        writable : true
      });
    };
    
    if ( !a/*stringProto*/.contains ){
      Object.defineProperty( a/*stringProto*/,"contains", {
        value : function q/*value*/( a/*str*/ ) {
          return this.indexOf( a/*str*/ ) !== -1;
        },
        configurable : true,
        enumerable : false,
        writable : true
      });
    };
    
    if ( !a/*stringProto*/.toArray ){
      Object.defineProperty( a/*stringProto*/,"toArray", {
        value : function q/*value*/( a/*str*/ ) {
          return this.split( "" );
        },
        configurable : true,
        enumerable : false,
        writable : true
      });
    };
    
    if ( !l/*functionProto*/.bind ){
      l/*functionProto*/.bind = function () {
        var d/*argArray*/ = k/*arrayProto*/.slice.call( arguments ),
            e/*context*/ = d/*argArray*/.shift(),
            f/*ret*/ = function () {
              var c/*args*/ = d/*argArray*/.concat( k/*arrayProto*/.slice.call( arguments ) );
              
              if ( this !== null && this !== window && this instanceof f/*ret*/ ){
                return f/*ret*/.context.apply( this,c/*args*/ );
              } else {
                return f/*ret*/.context.apply( e/*context*/,c/*args*/ );
              };
            };
        
        f/*ret*/.prototype = this.prototype;
        
        f/*ret*/.context = this;
        return f/*ret*/;
      };
    };
    
    if ( !k/*arrayProto*/.forEach ){
      k/*arrayProto*/.forEach = function ( b/*callback*/,c/*that*/ ) {
        o/*callbackCheck*/( b/*callback*/,"Array.forEach" );
        
        var d/*iter*/ = -1,
            e/*ta*/;
        
        if ( this === null ){
          n/*builtinTypeError*/( "Array.forEach : this is null or not defined" );
        };
        
        if ( c/*that*/ ){
          while ( ( e/*ta*/ = this[ ++ d/*iter*/] ) !== null && e/*ta*/ !== undefined ){
            b/*callback*/.call( c/*that*/,e/*ta*/,d/*iter*/,this );
          };
        } else {
          while ( ( e/*ta*/ = this[ ++ d/*iter*/] ) !== null && e/*ta*/ !== undefined ){
            b/*callback*/( e/*ta*/,d/*iter*/,this );
          };
        };
      };
    };
    
    if ( !k/*arrayProto*/.every ){
      k/*arrayProto*/.every = function ( b/*callback*/,c/*that*/ ) {
        o/*callbackCheck*/( b/*callback*/,"Array.every" );
        
        var d/*iter*/ = -1,
            e/*ta*/;
        
        if ( this === null ){
          n/*builtinTypeError*/( "Array.every : this is null or not defined" );
        };
        
        if ( c/*that*/ ){
          while ( ( e/*ta*/ = this[ ++ d/*iter*/] ) !== null && e/*ta*/ !== undefined ){
            if ( !( b/*callback*/.call( c/*that*/,e/*ta*/,d/*iter*/,this ) ) ){
              return false;
            };
          };
        } else {
          while ( ( e/*ta*/ = this[ ++ d/*iter*/] ) !== null && e/*ta*/ !== undefined ){
            if ( !( b/*callback*/( e/*ta*/,d/*iter*/,this ) ) ){
              return false;
            };
          };
        };
        return true;
      };
    };
    
    if ( !k/*arrayProto*/.some ){
      k/*arrayProto*/.some = function ( b/*callback*/,c/*that*/ ) {
        o/*callbackCheck*/( b/*callback*/,"Array.some" );
        
        var d/*iter*/ = -1,
            e/*ta*/;
        
        if ( this === null ){
          n/*builtinTypeError*/( "Array.some : this is null or not defined" );
        };
        
        if ( c/*that*/ ){
          while ( ( e/*ta*/ = this[ ++ d/*iter*/] ) !== null && e/*ta*/ !== undefined ){
            if ( b/*callback*/.call( c/*that*/,e/*ta*/,d/*iter*/,this ) ){
              return true;
            };
          };
        } else {
          while ( ( e/*ta*/ = this[ ++ d/*iter*/] ) !== null && e/*ta*/ !== undefined ){
            if ( b/*callback*/( e/*ta*/,d/*iter*/,this ) ){
              return true;
            };
          };
        };
        return false;
      };
    };
    
    if ( !k/*arrayProto*/.filter ){
      k/*arrayProto*/.filter = function ( c/*callback*/,d/*that*/ ) {
        o/*callbackCheck*/( c/*callback*/,"Array.filter" );
        
        var e/*len*/ = this.length,
            f/*iter*/ = -1,
            g/*ret*/ = [],
            h/*ta*/;
        
        if ( this === null ){
          n/*builtinTypeError*/( "Array.filter : this is null or not defined" );
        };
        
        if ( d/*that*/ ){
          for ( var i = 0,e/*len*/ = this.length;i<e/*len*/; ++ i ){
            if ( ( h/*ta*/ = this[i] ) !== null && h/*ta*/ !== undefined ){
              if ( c/*callback*/.call( d/*that*/,h/*ta*/,i,this ) ){
                g/*ret*/[ ++ f/*iter*/] = h/*ta*/;
              };
            };
          };
        } else {
          for ( var i = 0,e/*len*/ = this.length;i<e/*len*/; ++ i ){
            if ( ( h/*ta*/ = this[i] ) !== null && h/*ta*/ !== undefined ){
              if ( c/*callback*/( h/*ta*/,i,this ) ){
                g/*ret*/[ ++ f/*iter*/] = h/*ta*/;
              };
            };
          };
        };
        return g/*ret*/;
      };
    };
    
    if ( !k/*arrayProto*/.indexOf ){
      k/*arrayProto*/.indexOf = function ( b/*subject*/,c/*fromIndex*/ ) {
        var d/*iter*/ = ( c/*fromIndex*/ )?c/*fromIndex*/-1 : -1,
            e/*index*/ = -1,
            f/*ta*/;
        
        if ( this === null ){
          n/*builtinTypeError*/( "Array.indexOf : this is null or not defined." );
        };
        
        while ( ( f/*ta*/ = this[ ++ d/*iter*/] ) !== null && f/*ta*/ !== undefined ){
          if ( f/*ta*/ === b/*subject*/ ){
            e/*index*/ = d/*iter*/;
            break;
          };
        };
        return e/*index*/;
      };
    };
    
    if ( !k/*arrayProto*/.lastIndexOf ){
      k/*arrayProto*/.lastIndexOf = function ( b/*target*/,c/*fromIndex*/ ) {
        var d/*len*/ = this.length,
            e/*iter*/ = ( c/*fromIndex*/ )?c/*fromIndex*/+1 : d/*len*/,
            f/*index*/ = -1,
            g/*ta*/;
        
        if ( this === null ){
          n/*builtinTypeError*/( "Array.lastIndexOf : this is null or not defined." );
        };
        
        while ( ( g/*ta*/ = this[ -- e/*iter*/] ) !== null && g/*ta*/ !== undefined ){
          if ( g/*ta*/ === b/*target*/ ){
            f/*index*/ = e/*iter*/;
            break;
          };
        };
        return f/*index*/;
      };
    };
    
    if ( !k/*arrayProto*/.map ){
      k/*arrayProto*/.map = function ( b/*callback*/,c/*that*/ ) {
        o/*callbackCheck*/( b/*callback*/,"Array.map" );
        
        var d/*ret*/ = [],
            e/*iter*/ = -1,
            f/*len*/ = this.length,
            g/*i*/ = 0,
            h/*ta*/;
        
        if ( this === null ){
          n/*builtinTypeError*/( "Array.map : this is null or not defined." );
        };
        
        if ( c/*that*/ ){
          for ( g/*i*/;g/*i*/<f/*len*/; ++ g/*i*/ ){
            if ( ( h/*ta*/ = this[g/*i*/] ) !== null && h/*ta*/ !== undefined ){
              d/*ret*/[ ++ e/*iter*/] = b/*callback*/.call( c/*that*/,h/*ta*/,g/*i*/,this );
            };
          };
        } else {
          for ( g/*i*/;g/*i*/<f/*len*/; ++ g/*i*/ ){
            if ( ( h/*ta*/ = this[g/*i*/] ) !== null && h/*ta*/ !== undefined ){
              d/*ret*/[ ++ e/*iter*/] = b/*callback*/( h/*ta*/,g/*i*/,this );
            };
          };
        };
        return d/*ret*/;
      };
    };
    
    if ( !k/*arrayProto*/.reduce ){
      k/*arrayProto*/.reduce = function ( c/*callback*/,d/*initial*/ ) {
        o/*callbackCheck*/( c/*callback*/,"Array.reduce" );
        
        var e/*ret*/ = d/*initial*/ || this[0],
            f/*i*/ = ( d/*initial*/ )?0 : 1,
            g/*len*/ = this.length,
            h/*ta*/;
        
        if ( ( g/*len*/ === 0 || g/*len*/ === null ) && arguments.length<2 ){
          n/*builtinTypeError*/( "Array length is 0 and no second argument" );
        };
        
        for ( f/*i*/;f/*i*/<g/*len*/; ++ f/*i*/ ){
          if ( ( h/*ta*/ = this[f/*i*/] ) !== null && h/*ta*/ !== undefined ){
            e/*ret*/ = c/*callback*/( e/*ret*/,h/*ta*/,f/*i*/,this );
          };
        };
        return e/*ret*/;
      };
    };
    
    if ( !k/*arrayProto*/.reduceRight ){
      k/*arrayProto*/.reduceRight = function ( c/*callback*/,d/*initial*/ ) {
        o/*callbackCheck*/( c/*callback*/,"Array.reduceRight" );
        
        var e/*len*/ = this.length,
            f/*ret*/ = d/*initial*/ || this[e/*len*/-1],
            g/*i*/ = ( d/*initial*/ )?e/*len*/-1 : e/*len*/-2,
            h/*ta*/;
        
        if ( ( e/*len*/ === 0 || e/*len*/ === null ) && arguments.length<2 ){
          n/*builtinTypeError*/( "Array length is 0 and no second argument" );
        };
        
        for ( g/*i*/;g/*i*/>-1; -- g/*i*/ ){
          if ( ( h/*ta*/ = this[g/*i*/] ) !== null && h/*ta*/ !== undefined ){
            f/*ret*/ = c/*callback*/( f/*ret*/,h/*ta*/,g/*i*/,this );
          };
        };
        return f/*ret*/;
      };
    };
    
    if ( !m/*dateProto*/.toJSON ){
      m/*dateProto*/.toJSON = function () {
        var a/*_mochaLocalTmp4*/ = [this.getUTCMonth(),this.getUTCDate(),this.getUTCHours(),this.getMinutes(),this.getSeconds()],
            b/*month*/ = a/*_mochaLocalTmp4*/[0],
            c/*date*/ = a/*_mochaLocalTmp4*/[1],
            d/*hour*/ = a/*_mochaLocalTmp4*/[2],
            e/*minute*/ = a/*_mochaLocalTmp4*/[3],
            f/*second*/ = a/*_mochaLocalTmp4*/[4];
        return '"'+this.getUTCFullYear()+'-'+( b/*month*/>8?b/*month*/+1 : "0"+( b/*month*/+1 ) )+'-'+( c/*date*/>9?c/*date*/ : "0"+c/*date*/ )+'T'+( d/*hour*/>9?d/*hour*/ : "0"+d/*hour*/ )+':'+( e/*minute*/>9?e/*minute*/ : "0"+e/*minute*/ )+':'+( f/*second*/>9?f/*second*/ : "0"+f/*second*/ )+'.'+this.getUTCMilliseconds()+'Z"';
      };
    };
    
    if ( !Date.now ){
      Date.now = function () {
        return +new Date();
      };
    };
    
    if ( !Array.isArray ){
      Array.isArray = function ( c/*arr*/ ) {
        if ( arguments.length === 0 ){
          return false;
        };
        return ( c/*arr*/ )?Object.prototype.toString.call( c/*arr*/ ) === "[object Array]" : false;
      };
    };
  }).call( this,String,Array,Function,Date );
  
  var l/*Runtime*/ = ( function l/*Runtime*/() {
        var k/*_mochaLocalExport*/ = {};
        
        "use strict";
        
        function l/*Exception*/( d/*line*/,c/*file*/,b/*e*/ ) {
          this.toString = function () {
            return Runtime.getErrorMessage( e )+" in file "+file+" at : "+line;
          };
        }
        var m/*fastMax*/ = Math.max;
        
        var a/*Runtime*/ =  {
              getErrorMessage : function n/*getErrorMessage*/( a/*e*/ ) {
                return ( a/*e*/.message )?a/*e*/.message : ( a/*e*/.description )?a/*e*/.description : a/*e*/.toString();
              },
              exceptionHandler : function o/*exceptionHandler*/( a/*line*/,b/*file*/,c/*e*/ ) {
                if ( K/*isStopIteration*/( c/*e*/ ) ){
                  this.throwException( c/*e*/ );
                } else {
                  this.throwException( new l/*Exception*/( a/*line*/,b/*file*/,c/*e*/ ) );
                };
              },
              throwException : function p/*throwException*/( c/*exception*/ ) {
                try {
                  throw c/*exception*/;
                } catch( e ){
                  if ( K/*isStopIteration*/( e ) ){
                    throw new Error( e );
                  } else {
                    throw new Error( this.getErrorMessage( e ) );
                  };
                };
              },
              hasProto : "__proto__" in {}
            };
        
        var q/*slice*/ = Array.prototype.slice;
        
        var r/*createUnenumProp*/ = k/*_mochaLocalExport*/.createUnenumProp = function r/*createUnenumProp*/( b/*obj*/,c/*prop*/,d/*value*/ ) {
              return Object.defineProperty( b/*obj*/,c/*prop*/, {
                configurable : true,
                enumerable : false,
                writable : true,
                value : d/*value*/
              });
            };
        
        var s/*constant*/ = k/*_mochaLocalExport*/.constant = function s/*constant*/( b/*obj*/,c/*prop*/,d/*value*/ ) {
              return Object.defineProperty( b/*obj*/,c/*prop*/, {
                configurable : false,
                enumerable : false,
                writable : false,
                value : d/*value*/
              });
            };
        
        var t/*toArray*/ = k/*_mochaLocalExport*/.toArray = function t/*toArray*/( a/*likeArray*/,b/*index*/ ) {
              return ( a/*likeArray*/ )?q/*slice*/.call( a/*likeArray*/,b/*index*/ ) : [];
            };
        
        var u/*Generator*/ = function (){};
        
        var v/*createGenerator*/ = k/*_mochaLocalExport*/.createGenerator = function v/*createGenerator*/( b/*generatorFn*/,c/*closeFn*/,d/*context*/ ) {
              var e/*ret*/ = new u/*Generator*/;
              
              r/*createUnenumProp*/( e/*ret*/,"next",b/*generatorFn*/.bind( d/*context*/,false,false ) );
              
              r/*createUnenumProp*/( e/*ret*/,"send",b/*generatorFn*/.bind( d/*context*/,true,false ) );
              
              r/*createUnenumProp*/( e/*ret*/,"close",c/*closeFn*/.bind( d/*context*/ ) );
              
              r/*createUnenumProp*/( e/*ret*/,"__nothrowNext__",b/*generatorFn*/.bind( d/*context*/,false,true ) );
              
              r/*createUnenumProp*/( e/*ret*/,"toString",
              function () {
                return "[object Generator]";
              });
              
              Object.freeze( e/*ret*/ );
              return e/*ret*/;
            };
        
        function n/*getErrorMessage*/( a/*e*/ ) {
          return ( a/*e*/.message )?a/*e*/.message : ( a/*e*/.description )?a/*e*/.description : a/*e*/.toString();
        }
        var p/*throwException*/ = k/*_mochaLocalExport*/.throwException = a/*Runtime*/.throwException.bind( a/*Runtime*/ );
        
        var o/*exceptionHandler*/ = k/*_mochaLocalExport*/.exceptionHandler = a/*Runtime*/.exceptionHandler.bind( a/*Runtime*/ );
        
        var w/*extend*/ = k/*_mochaLocalExport*/.extend = function w/*extend*/( b/*dest*/,c/*source*/ ) {
              for ( var prop in c/*source*/ ){
                b/*dest*/[prop] = c/*source*/[prop];
              };
              return b/*dest*/;
            };
        
        function x/*compareTuple*/( a/*tuple*/ ) {
          var b/*max*/ = m/*fastMax*/( a/*tuple*/.length,this.length ),
              c/*i*/ = -1;
          
          while (  ++ c/*i*/<b/*max*/ && a/*tuple*/[c/*i*/] === this[c/*i*/] ){
            
          };
          return b/*max*/ === c/*i*/;
        };
        
        function y/*tupleToArray*/() {
          return Array.prototype.slice.call( this );
        };
        
        var z/*createTuple*/ = k/*_mochaLocalExport*/.createTuple = function z/*createTuple*/( b/*obj*/,c/*size*/ ) {
              r/*createUnenumProp*/( b/*obj*/,"length",c/*size*/ );
              
              r/*createUnenumProp*/( b/*obj*/,"equal",x/*compareTuple*/ );
              
              r/*createUnenumProp*/( b/*obj*/,"toArray",y/*tupleToArray*/ );
              
              r/*createUnenumProp*/( b/*obj*/,"toString",
              function () {
                return "[object Tuple]";
              });
              return Object.freeze( b/*obj*/ );
            };
        
        var A/*createRecord*/ = k/*_mochaLocalExport*/.createRecord = function A/*createRecord*/( b/*obj*/ ) {
              if ( b/*obj*/.toString() === "[object Object]" ){
                r/*createUnenumProp*/( b/*obj*/,"toString",
                function () {
                  return "[object Record]";
                });
              };
              return Object.freeze( b/*obj*/ );
            };
        
        var B/*extendPrototype*/ = k/*_mochaLocalExport*/.extendPrototype = function ( a/*derived*/,b/*base*/ ) {
              a/*derived*/.prototype = b/*base*/;
            };
        
        var C/*getPrototype*/ = ( "getPrototypeOf" in Object )?function ( b/*obj*/ ) {
              return Object.getPrototypeOf( b/*obj*/ );
            } : function ( b/*obj*/ ) {
              var c/*ret*/ = {};
              
              for ( var i in b/*obj*/ ){
                if ( !b/*obj*/.hasOwnProperty( i ) ){
                  c/*ret*/[i] = b/*obj*/[i];
                };
              };
              return c/*ret*/;
            };
        
        var D/*extendClass*/ = k/*_mochaLocalExport*/.extendClass = ( a/*Runtime*/.hasProto )?function ( b/*derived*/,c/*base*/ ) {
              if ( typeof c/*base*/ === 'function' ){
                b/*derived*/.prototype.__proto__ = c/*base*/.prototype;
                
                for ( var i in c/*base*/ ){
                  b/*derived*/[i] = c/*base*/[i];
                };
              } else {
                b/*derived*/.prototype.__proto__ = c/*base*/.__proto__;
              };
            } : function ( b/*derived*/,c/*base*/ ) {
              var d/*baseType*/ = typeof c/*base*/;
              
              if ( d/*baseType*/ === "function" ){
                var e/*inherit*/ = function (){};
                
                e/*inherit*/.prototype = c/*base*/.prototype;
                
                b/*derived*/.prototype = new e/*inherit*/;
                
                for ( var i in c/*base*/ ){
                  b/*derived*/[i] = c/*base*/[i];
                };
              } else {
                var e/*inherit*/ = function (){},
                    f/*proto*/ = C/*getPrototype*/( c/*base*/ );
                
                e/*inherit*/.prototype = f/*proto*/;
                
                b/*derived*/.prototype = new e/*inherit*/;
              };
            };
        
        var E/*__ref_iterator__*/ = k/*_mochaLocalExport*/.__ref_iterator__ = "__mocha_iterator_special_key__";
        
        var F/*throwStopIteration*/ = k/*_mochaLocalExport*/.throwStopIteration = function F/*throwStopIteration*/() {
              try {
                throw StopIteration;
              } catch( e ){
                throw new Error( e.toString() );
              };
            };
        
        var G/*isGenerator*/ = k/*_mochaLocalExport*/.isGenerator = function G/*isGenerator*/( a/*obj*/ ) {
              return a/*obj*/ instanceof u/*Generator*/;
            };
        
        var H/*getIterator*/ = k/*_mochaLocalExport*/.getIterator = function H/*getIterator*/( c/*obj*/ ) {
              var d/*ret*/ = c/*obj*/[E/*__ref_iterator__*/](),
                  e/*newObj*/;
              
              if ( G/*isGenerator*/( d/*ret*/ ) ){
                return d/*ret*/;
              };
              
              e/*newObj*/ = {};
              
              if ( d/*ret*/.next ){
                r/*createUnenumProp*/( e/*newObj*/,"next",
                function () {
                  var b/*result*/ = d/*ret*/.next();
                  
                  if ( b/*result*/ === undefined ){
                    F/*throwStopIteration*/();
                  };
                  return b/*result*/;
                });
              } else {
                return {};
              };
              
              if ( !( "__nothrowNext__" in d/*ret*/ ) ){
                r/*createUnenumProp*/( e/*newObj*/,"__nothrowNext__",d/*ret*/.next.bind( d/*ret*/ ) );
              };
              
              for ( var prop in d/*ret*/ ){
                if ( prop !== "next" && prop !== "__nothrowNext__" ){
                  e/*newObj*/[prop] = d/*ret*/[prop];
                };
              };
              
              if ( !( "toString" in d/*ret*/ ) ){
                r/*createUnenumProp*/( e/*newObj*/,"toString",
                function () {
                  return "[object Iterator]";
                });
              };
              return e/*newObj*/;
            };
        
        var I/*hasIterator*/ = k/*_mochaLocalExport*/.hasIterator = function I/*hasIterator*/( a/*obj*/ ) {
              return E/*__ref_iterator__*/ in a/*obj*/;
            };
        
        var J/*rstopIteration*/ = /StopIteration/;
        
        var K/*isStopIteration*/ = k/*_mochaLocalExport*/.isStopIteration = function K/*isStopIteration*/( b/*obj*/ ) {
              return b/*obj*/ === StopIteration || J/*rstopIteration*/.test( b/*obj*/ );
            };
        
        var L/*privateRecord*/,
            M/*createPrivateRecord*/,
            N/*getPrivateRecord*/;
        
        if ( "WeakMap" in window ){
          L/*privateRecord*/ = new WeakMap();
          
          M/*createPrivateRecord*/ = function ( a/*self*/,b/*privateHolder*/ ) {
            var c/*holder*/ = new b/*privateHolder*/;
            
            r/*createUnenumProp*/( c/*holder*/.constructor,"__is_private__",1 );
            
            L/*privateRecord*/.set( a/*self*/,c/*holder*/ );
          };
          
          N/*getPrivateRecord*/ = function ( a/*self*/ ) {
            if ( L/*privateRecord*/.has( a/*self*/ ) ){
              return L/*privateRecord*/.get( a/*self*/ );
            } else if ( a/*self*/.constructor === "__is_private__" ){
              return a/*self*/;
            };
          };
        } else {
          M/*createPrivateRecord*/ = function ( a/*self*/,b/*privateHolder*/ ) {
            if ( !a/*self*/.__typeid__ ){
              var c/*holder*/ = new b/*privateHolder*/;
              
              r/*createUnenumProp*/( c/*holder*/.constructor,"__is_private__",1 );
              
              r/*createUnenumProp*/( a/*self*/,"__private__",c/*holder*/ );
            };
          };
          
          N/*getPrivateRecord*/ = function ( a/*self*/ ) {
            if ( a/*self*/.__private__ ){
              return a/*self*/.__private__;
            } else if ( a/*self*/.constructor === "__is_private__" ){
              return a/*self*/;
            };
          };
        };
        
        k/*_mochaLocalExport*/.createPrivateRecord = M/*createPrivateRecord*/;
        
        k/*_mochaLocalExport*/.getPrivateRecord = N/*getPrivateRecord*/;
        
        var O/*getSuper*/ = k/*_mochaLocalExport*/.getSuper = function O/*getSuper*/( a/*obj*/ ) {
              var b/*type*/ = typeof a/*obj*/,
                  c/*ret*/;
              
              if ( b/*type*/ === "function" ){
                c/*ret*/ = function (){};
                
                c/*ret*/.prototype = a/*obj*/.prototype;
                
                c/*ret*/ = new c/*ret*/();
                
                if ( a/*obj*/.__harmony_class__ ){
                  c/*ret*/.constructor = a/*obj*/.constructor;
                } else {
                  c/*ret*/.constructor = a/*obj*/;
                };
                return c/*ret*/;
              };
              return c/*ret*/;
            };
        
        var P/*traitMixin*/ = k/*_mochaLocalExport*/.traitMixin = function P/*traitMixin*/( c/*dest*/,d/*source*/,e/*with_*/,f/*without*/ ) {
              if ( !c/*dest*/._mochaTraitMark || !d/*source*/._mochaTraitMark ){
                a/*Runtime*/.throwException( "mixin only used for trait." );
              } else {
                var g/*destTraitPrivate*/ = c/*dest*/._mochaTraitPrivate,
                    h/*sourceTraitPrivate*/ = d/*source*/._mochaTraitPrivate,
                    i/*destTraitPublic*/ = c/*dest*/._mochaTraitPublic,
                    j/*sourceTraitPublic*/ = d/*source*/._mochaTraitPublic,
                    k/*sourceRequires*/ = d/*source*/._mochaRequires,
                    l/*destRequires*/ = c/*dest*/._mochaRequires,
                    m/*tmp*/;
                
                for ( var i in h/*sourceTraitPrivate*/ ){
                  if ( !f/*without*/[i] ){
                    m/*tmp*/ = ( !e/*with_*/[i] )?i : e/*with_*/[i];
                    
                    g/*destTraitPrivate*/[m/*tmp*/] = h/*sourceTraitPrivate*/[i];
                  };
                };
                
                for ( i in j/*sourceTraitPublic*/ ){
                  if ( !f/*without*/[i] ){
                    m/*tmp*/ = ( !e/*with_*/[i] )?i : e/*with_*/[i];
                    
                    i/*destTraitPublic*/[m/*tmp*/] = j/*sourceTraitPublic*/[i];
                  };
                };
                
                for ( i in k/*sourceRequires*/ ){
                  l/*destRequires*/[i] = k/*sourceRequires*/[i];
                };
              };
            };
        
        var Q/*classMixin*/ = k/*_mochaLocalExport*/.classMixin = function Q/*classMixin*/( f/*_mochaLocalTmp5*/,g/*_mochaLocalTmp6*/,h/*_mochaLocalTmp7*/,i/*with_*/,j/*without*/ ) {
              var k/*constructorProto*/ = f/*_mochaLocalTmp5*/.prototype,
                  l/*privateProto*/ = g/*_mochaLocalTmp6*/.prototype,
                  m/*mark*/ = h/*_mochaLocalTmp7*/._mochaTraitMark,
                  n/*traitPublic*/ = h/*_mochaLocalTmp7*/._mochaTraitPublic,
                  o/*traitPrivate*/ = h/*_mochaLocalTmp7*/._mochaTraitPrivate;
              
              if ( !m/*mark*/ ){
                a/*Runtime*/.throwException( "mixin only used for trait." );
              } else {
                var p/*tmp*/;
                
                for ( var i in n/*traitPublic*/ ){
                  if ( !j/*without*/[i] ){
                    p/*tmp*/ = ( !i/*with_*/[i] )?i : i/*with_*/[i];
                    
                    k/*constructorProto*/[p/*tmp*/] = n/*traitPublic*/[i];
                  };
                };
                
                for ( i in o/*traitPrivate*/ ){
                  if ( !j/*without*/[i] ){
                    p/*tmp*/ = ( !i/*with_*/[i] )?i : i/*with_*/[i];
                    
                    l/*privateProto*/[p/*tmp*/] = o/*traitPrivate*/[i];
                  };
                };
              };
            };
        
        var R/*checkRequirements*/ = k/*_mochaLocalExport*/.checkRequirements = function R/*checkRequirements*/( d/*_mochaLocalTmp8*/,e/*_mochaLocalTmp9*/,f/*traits*/,g/*file*/,h/*line*/ ) {
              var i/*proto1*/ = d/*_mochaLocalTmp8*/.prototype,
                  j/*proto2*/ = e/*_mochaLocalTmp9*/.prototype;
              
              for ( var i = 0,len = f/*traits*/.length;i<len;i ++  ){
                var k/*_mochaLocalTmp10*/ = f/*traits*/[i],
                    l/*_mochaRequires*/ = k/*_mochaLocalTmp10*/._mochaRequires;
                
                for ( var prop in l/*_mochaRequires*/ ){
                  if ( !( prop in i/*proto1*/ ) && !( prop in j/*proto2*/ ) ){
                    a/*Runtime*/.throwException( "Class dose not meet the traits requirement. traits require implementation of property "+prop+"\nin file "+g/*file*/+" at line "+h/*line*/ );
                  };
                };
              };
            };
        return k/*_mochaLocalExport*/;
      })();
  
  if ( !( "StopIteration" in window ) ){
    window.StopIteration =  {
      toString : function r/*toString*/() {
        return "[object StopIteration]";
      }
    };
  };
  
  ( function () {
    p/*_mochaGlobalExport*/['./yield_test.js'] = {};
    
    var q/*_mochaGlobalAlias*/ = p/*_mochaGlobalExport*/['./yield_test.js'];
    
    var E/*tests*/ =  {
          case1 : function r/*case1*/() {
            function k/*yieldTest2*/(  ) {
              var k/*_mochaIsNewBorn*/ = true;
              
              var m/*_yieldResult*/ = undefined;
              
              var a/*_yieldState*/ = 0;
              
              var n/*i*/;
              
              var o/*_mochaGenerator*/ = function ( f/*_isYieldSend*/,g/*_isYieldSafe*/ ) {
                    if ( !f/*_isYieldSend*/ ){
                      k/*_mochaIsNewBorn*/ = false;
                    } else if ( f/*_isYieldSend*/ && k/*_mochaIsNewBorn*/ && arguments[1] !== undefined ){
                      l/*Runtime*/.exceptionHandler( 'attempt to send to newborn generator.' );
                    };
                    
                    while ( 1 ){
                      switch ( a/*_yieldState*/ ) {
                        case 0 :
                          
                          n/*i*/ = 0;
                          
                          if ( !( n/*i*/<10 ) ){
                            a/*_yieldState*/ = -1;
                            break;
                          };
                        case 1 :
                          
                          a/*_yieldState*/ = 2;
                          return n/*i*/;
                        case 2 :
                          
                          n/*i*/ ++ ;
                          
                          if ( n/*i*/<10 ){
                            a/*_yieldState*/ = 1;
                            break;
                          } else {
                            a/*_yieldState*/ = -1;
                          };
                        case -1 :
                          
                          if ( g/*_isYieldSafe*/ )return undefined;
                           else l/*Runtime*/.throwStopIteration();
                          
                      };
                    };
                  };
              return l/*Runtime*/.createGenerator( o/*_mochaGenerator*/,
              function (  ) {
                _yieldState = -1;
              },this);
            };
            
            var m/*generator*/ = k/*yieldTest2*/();
          },
          case2 : function s/*case2*/() {
            function m/*yieldTest3*/(  ) {
              var k/*_mochaIsNewBorn*/ = true;
              
              var m/*_yieldResult*/ = undefined;
              
              var a/*_yieldState*/ = 0;
              
              var n/*i*/;
              
              var o/*_mochaGenerator*/ = function ( f/*_isYieldSend*/,g/*_isYieldSafe*/ ) {
                    if ( !f/*_isYieldSend*/ ){
                      k/*_mochaIsNewBorn*/ = false;
                    } else if ( f/*_isYieldSend*/ && k/*_mochaIsNewBorn*/ && arguments[1] !== undefined ){
                      l/*Runtime*/.exceptionHandler( 'attempt to send to newborn generator.' );
                    };
                    
                    while ( 1 ){
                      switch ( a/*_yieldState*/ ) {
                        case 0 :
                          
                          n/*i*/ = 0;
                          
                          if ( !( n/*i*/<10 ) ){
                            a/*_yieldState*/ = -1;
                            break;
                          };
                        case 1 :
                          
                          if ( n/*i*/%2 === 0 ){
                            a/*_yieldState*/ = 2;
                            break;
                          } else {
                            a/*_yieldState*/ = 3;
                            break;
                          };
                        case 2 :
                          
                          a/*_yieldState*/ = 3;
                          return n/*i*/;
                        case 3 :
                          
                          a/*_yieldState*/ = 4;
                          break;
                        case 4 :
                          
                          n/*i*/ ++ ;
                          
                          if ( n/*i*/<10 ){
                            a/*_yieldState*/ = 1;
                            break;
                          } else {
                            a/*_yieldState*/ = -1;
                          };
                        case -1 :
                          
                          if ( g/*_isYieldSafe*/ )return undefined;
                           else l/*Runtime*/.throwStopIteration();
                          
                      };
                    };
                  };
              return l/*Runtime*/.createGenerator( o/*_mochaGenerator*/,
              function (  ) {
                _yieldState = -1;
              },this);
            };
            
            generator = m/*yieldTest3*/();
          },
          case3 : function t/*case3*/() {
            function m/*yieldTest4*/(  ) {
              var k/*_mochaIsNewBorn*/ = true;
              
              var m/*_yieldResult*/ = undefined;
              
              var a/*_yieldState*/ = 0;
              
              var n/*j*/;
              
              var o/*i*/;
              
              var p/*_mochaGenerator*/ = function ( f/*_isYieldSend*/,g/*_isYieldSafe*/ ) {
                    if ( !f/*_isYieldSend*/ ){
                      k/*_mochaIsNewBorn*/ = false;
                    } else if ( f/*_isYieldSend*/ && k/*_mochaIsNewBorn*/ && arguments[1] !== undefined ){
                      l/*Runtime*/.exceptionHandler( 'attempt to send to newborn generator.' );
                    };
                    
                    while ( 1 ){
                      switch ( a/*_yieldState*/ ) {
                        case 0 :
                          
                          o/*i*/ = 0;
                          
                          if ( !( o/*i*/<10 ) ){
                            a/*_yieldState*/ = -1;
                            break;
                          };
                        case 1 :
                          
                          n/*j*/ = 0;
                          
                          if ( !( n/*j*/<10 ) ){
                            a/*_yieldState*/ = 6;
                            break;
                          };
                        case 2 :
                          
                          if ( n/*j*/%2 === 0 ){
                            a/*_yieldState*/ = 3;
                            break;
                          } else {
                            a/*_yieldState*/ = 4;
                            break;
                          };
                        case 3 :
                          
                          a/*_yieldState*/ = 4;
                          return n/*j*/;
                        case 4 :
                          
                          a/*_yieldState*/ = 5;
                          break;
                        case 5 :
                          
                          n/*j*/ ++ ;
                          
                          if ( n/*j*/<10 ){
                            a/*_yieldState*/ = 2;
                            break;
                          } else {
                            a/*_yieldState*/ = 6;
                          };
                        case 6 :
                          
                          o/*i*/ ++ ;
                          
                          if ( o/*i*/<10 ){
                            a/*_yieldState*/ = 1;
                            break;
                          } else {
                            a/*_yieldState*/ = -1;
                          };
                        case -1 :
                          
                          if ( g/*_isYieldSafe*/ )return undefined;
                           else l/*Runtime*/.throwStopIteration();
                          
                      };
                    };
                  };
              return l/*Runtime*/.createGenerator( p/*_mochaGenerator*/,
              function (  ) {
                _yieldState = -1;
              },this);
            };
            
            generator = m/*yieldTest4*/();
          },
          case4 : function u/*case4*/() {
            function m/*yieldTest5*/(  ) {
              var k/*_mochaIsNewBorn*/ = true;
              
              var m/*_yieldResult*/ = undefined;
              
              var a/*_yieldState*/ = 0;
              
              var n/*i*/;
              
              var o/*_mochaGenerator*/ = function ( f/*_isYieldSend*/,g/*_isYieldSafe*/ ) {
                    if ( !f/*_isYieldSend*/ ){
                      k/*_mochaIsNewBorn*/ = false;
                    } else if ( f/*_isYieldSend*/ && k/*_mochaIsNewBorn*/ && arguments[1] !== undefined ){
                      l/*Runtime*/.exceptionHandler( 'attempt to send to newborn generator.' );
                    };
                    
                    while ( 1 ){
                      switch ( a/*_yieldState*/ ) {
                        case 0 :
                          
                          n/*i*/ = 0;
                          
                          if ( !(  ++ n/*i*/<10 ) ){
                            a/*_yieldState*/ = -1;
                            break;
                          };
                        case 1 :
                          
                          a/*_yieldState*/ = 2;
                          return n/*i*/;
                        case 2 :
                          
                          if (  ++ n/*i*/<10 ){
                            a/*_yieldState*/ = 1;
                            break;
                          } else {
                            a/*_yieldState*/ = -1;
                          };
                        case -1 :
                          
                          if ( g/*_isYieldSafe*/ )return undefined;
                           else l/*Runtime*/.throwStopIteration();
                          
                      };
                    };
                  };
              return l/*Runtime*/.createGenerator( o/*_mochaGenerator*/,
              function (  ) {
                _yieldState = -1;
              },this);
            };
            
            generator = m/*yieldTest5*/();
          },
          case5 : function v/*case5*/() {
            function m/*yieldTest6*/(  ) {
              var k/*_mochaIsNewBorn*/ = true;
              
              var m/*_yieldResult*/ = undefined;
              
              var a/*_yieldState*/ = 0;
              
              var n/*i*/;
              
              var o/*_mochaGenerator*/ = function ( f/*_isYieldSend*/,g/*_isYieldSafe*/ ) {
                    if ( !f/*_isYieldSend*/ ){
                      k/*_mochaIsNewBorn*/ = false;
                    } else if ( f/*_isYieldSend*/ && k/*_mochaIsNewBorn*/ && arguments[1] !== undefined ){
                      l/*Runtime*/.exceptionHandler( 'attempt to send to newborn generator.' );
                    };
                    
                    while ( 1 ){
                      switch ( a/*_yieldState*/ ) {
                        case 0 :
                          
                          n/*i*/ = 0;
                        case 1 :
                          
                          a/*_yieldState*/ = 2;
                          return n/*i*/;
                        case 2 :
                          
                          if (  ++ n/*i*/<10 ){
                            a/*_yieldState*/ = 1;
                            break;
                          } else {
                            a/*_yieldState*/ = 3;
                          };
                        case 3 :
                        case -1 :
                          
                          if ( g/*_isYieldSafe*/ )return undefined;
                           else l/*Runtime*/.throwStopIteration();
                          
                      };
                    };
                  };
              return l/*Runtime*/.createGenerator( o/*_mochaGenerator*/,
              function (  ) {
                _yieldState = -1;
              },this);
            };
            
            generator = m/*yieldTest6*/();
          },
          case6 : function w/*case6*/() {
            function m/*yieldTest7*/(  ) {
              var k/*_mochaIsNewBorn*/ = true;
              
              var m/*_yieldResult*/ = undefined;
              
              var a/*_yieldState*/ = 0;
              
              var n/*m*/;
              
              var o/*i*/;
              
              var p/*_mochaGenerator*/ = function ( f/*_isYieldSend*/,g/*_isYieldSafe*/ ) {
                    if ( !f/*_isYieldSend*/ ){
                      k/*_mochaIsNewBorn*/ = false;
                    } else if ( f/*_isYieldSend*/ && k/*_mochaIsNewBorn*/ && arguments[1] !== undefined ){
                      l/*Runtime*/.exceptionHandler( 'attempt to send to newborn generator.' );
                    };
                    
                    while ( 1 ){
                      switch ( a/*_yieldState*/ ) {
                        case 0 :
                          
                          o/*i*/ = 0;
                          
                          if ( !( o/*i*/<10 ) ){
                            a/*_yieldState*/ = -1;
                            break;
                          };
                        case 1 :
                          
                          a/*_yieldState*/ = 2;
                          return o/*i*/;
                        case 2 :
                          
                          m/*_yieldResult*/ = f/*_isYieldSend*/ && arguments.length>2?l/*Runtime*/.toArray( arguments,2 )[0] : f/*_isYieldSend*/?o/*i*/ : undefined;
                          
                          n/*m*/ = m/*_yieldResult*/;
                          
                          if ( n/*m*/ === true ){
                            a/*_yieldState*/ = 3;
                            break;
                          } else {
                            a/*_yieldState*/ = 5;
                            break;
                          };
                        case 3 :
                          
                          a/*_yieldState*/ = 4;
                          return o/*i*/+1;
                        case 4 :
                          
                          a/*_yieldState*/ = 9;
                          break;
                        case 5 :
                          
                          if ( n/*m*/ === false ){
                            a/*_yieldState*/ = 6;
                            break;
                          } else {
                            a/*_yieldState*/ = 8;
                            break;
                          };
                        case 6 :
                          
                          a/*_yieldState*/ = 7;
                          return o/*i*/-1;
                        case 7 :
                          
                          a/*_yieldState*/ = 9;
                          break;
                        case 8 :
                          
                          a/*_yieldState*/ = 9;
                          return o/*i*/;
                        case 9 :
                          
                          o/*i*/ ++ ;
                          
                          if ( o/*i*/<10 ){
                            a/*_yieldState*/ = 1;
                            break;
                          } else {
                            a/*_yieldState*/ = -1;
                          };
                        case -1 :
                          
                          if ( g/*_isYieldSafe*/ )return undefined;
                           else l/*Runtime*/.throwStopIteration();
                          
                      };
                    };
                  };
              return l/*Runtime*/.createGenerator( p/*_mochaGenerator*/,
              function (  ) {
                _yieldState = -1;
              },this);
            };
            
            generator = m/*yieldTest7*/();
          },
          case7 : function x/*case7*/() {
            function m/*yieldTest8*/(  ) {
              var k/*_mochaIsNewBorn*/ = true;
              
              var m/*_yieldResult*/ = undefined;
              
              var a/*_yieldState*/ = 0;
              
              var n/*j*/;
              
              var o/*m*/;
              
              var p/*i*/;
              
              var q/*_mochaGenerator*/ = function ( f/*_isYieldSend*/,g/*_isYieldSafe*/ ) {
                    if ( !f/*_isYieldSend*/ ){
                      k/*_mochaIsNewBorn*/ = false;
                    } else if ( f/*_isYieldSend*/ && k/*_mochaIsNewBorn*/ && arguments[1] !== undefined ){
                      l/*Runtime*/.exceptionHandler( 'attempt to send to newborn generator.' );
                    };
                    
                    while ( 1 ){
                      switch ( a/*_yieldState*/ ) {
                        case 0 :
                          
                          p/*i*/ = 0;
                          
                          if ( !( p/*i*/<10 ) ){
                            a/*_yieldState*/ = -1;
                            break;
                          };
                        case 1 :
                          
                          a/*_yieldState*/ = 2;
                          return p/*i*/;
                        case 2 :
                          
                          m/*_yieldResult*/ = f/*_isYieldSend*/ && arguments.length>2?l/*Runtime*/.toArray( arguments,2 )[0] : f/*_isYieldSend*/?p/*i*/ : undefined;
                          
                          o/*m*/ = m/*_yieldResult*/;
                          
                          n/*j*/ = 0;
                          
                          if ( !( n/*j*/<10 ) ){
                            a/*_yieldState*/ = 11;
                            break;
                          };
                        case 3 :
                          
                          if ( o/*m*/ === true ){
                            a/*_yieldState*/ = 4;
                            break;
                          } else {
                            a/*_yieldState*/ = 6;
                            break;
                          };
                        case 4 :
                          
                          a/*_yieldState*/ = 5;
                          return n/*j*/*2;
                        case 5 :
                          
                          a/*_yieldState*/ = 10;
                          break;
                        case 6 :
                          
                          if ( o/*m*/ === false ){
                            a/*_yieldState*/ = 7;
                            break;
                          } else {
                            a/*_yieldState*/ = 9;
                            break;
                          };
                        case 7 :
                          
                          a/*_yieldState*/ = 8;
                          return n/*j*//2;
                        case 8 :
                          
                          a/*_yieldState*/ = 10;
                          break;
                        case 9 :
                          
                          a/*_yieldState*/ = 10;
                          return n/*j*/;
                        case 10 :
                          
                          n/*j*/ ++ ;
                          
                          if ( n/*j*/<10 ){
                            a/*_yieldState*/ = 3;
                            break;
                          } else {
                            a/*_yieldState*/ = 11;
                          };
                        case 11 :
                          
                          p/*i*/ ++ ;
                          
                          if ( p/*i*/<10 ){
                            a/*_yieldState*/ = 1;
                            break;
                          } else {
                            a/*_yieldState*/ = -1;
                          };
                        case -1 :
                          
                          if ( g/*_isYieldSafe*/ )return undefined;
                           else l/*Runtime*/.throwStopIteration();
                          
                      };
                    };
                  };
              return l/*Runtime*/.createGenerator( q/*_mochaGenerator*/,
              function (  ) {
                _yieldState = -1;
              },this);
            };
            
            generator = m/*yieldTest8*/();
          },
          case8 : function y/*case8*/() {
            function m/*yieldTest9*/(  ) {
              var k/*_mochaIsNewBorn*/ = true;
              
              var m/*_yieldResult*/ = undefined;
              
              var a/*_yieldState*/ = 0;
              
              var n/*m*/;
              
              var o/*j*/;
              
              var p/*i*/;
              
              var q/*_mochaGenerator*/ = function ( f/*_isYieldSend*/,g/*_isYieldSafe*/ ) {
                    if ( !f/*_isYieldSend*/ ){
                      k/*_mochaIsNewBorn*/ = false;
                    } else if ( f/*_isYieldSend*/ && k/*_mochaIsNewBorn*/ && arguments[1] !== undefined ){
                      l/*Runtime*/.exceptionHandler( 'attempt to send to newborn generator.' );
                    };
                    
                    while ( 1 ){
                      switch ( a/*_yieldState*/ ) {
                        case 0 :
                          
                          p/*i*/ = 0;
                          
                          if ( !( p/*i*/<10 ) ){
                            a/*_yieldState*/ = -1;
                            break;
                          };
                        case 1 :
                          
                          o/*j*/ = 0;
                          
                          if ( !( o/*j*/<10 ) ){
                            a/*_yieldState*/ = 11;
                            break;
                          };
                        case 2 :
                          
                          a/*_yieldState*/ = 3;
                          return p/*i*/;
                        case 3 :
                          
                          m/*_yieldResult*/ = f/*_isYieldSend*/ && arguments.length>2?l/*Runtime*/.toArray( arguments,2 )[0] : f/*_isYieldSend*/?p/*i*/ : undefined;
                          
                          n/*m*/ = m/*_yieldResult*/;
                          
                          if ( n/*m*/ === true ){
                            a/*_yieldState*/ = 4;
                            break;
                          } else {
                            a/*_yieldState*/ = 6;
                            break;
                          };
                        case 4 :
                          
                          a/*_yieldState*/ = 5;
                          return o/*j*/*2;
                        case 5 :
                          
                          a/*_yieldState*/ = 10;
                          break;
                        case 6 :
                          
                          if ( n/*m*/ === false ){
                            a/*_yieldState*/ = 7;
                            break;
                          } else {
                            a/*_yieldState*/ = 9;
                            break;
                          };
                        case 7 :
                          
                          a/*_yieldState*/ = 8;
                          return o/*j*//2;
                        case 8 :
                          
                          a/*_yieldState*/ = 10;
                          break;
                        case 9 :
                          
                          a/*_yieldState*/ = 10;
                          return o/*j*/;
                        case 10 :
                          
                          o/*j*/ ++ ;
                          
                          if ( o/*j*/<10 ){
                            a/*_yieldState*/ = 2;
                            break;
                          } else {
                            a/*_yieldState*/ = 11;
                          };
                        case 11 :
                          
                          p/*i*/ ++ ;
                          
                          if ( p/*i*/<10 ){
                            a/*_yieldState*/ = 1;
                            break;
                          } else {
                            a/*_yieldState*/ = -1;
                          };
                        case -1 :
                          
                          if ( g/*_isYieldSafe*/ )return undefined;
                           else l/*Runtime*/.throwStopIteration();
                          
                      };
                    };
                  };
              return l/*Runtime*/.createGenerator( q/*_mochaGenerator*/,
              function (  ) {
                _yieldState = -1;
              },this);
            };
            
            generator = m/*yieldTest9*/();
          },
          case9 : function z/*case9*/() {
            function o/*yieldTest10*/(  ) {
              var o/*_mochaIsNewBorn*/ = true;
              
              var p/*_yieldResult*/ = undefined;
              
              var a/*_yieldState*/ = 0;
              
              var b/*_mochaFinallyCache*/;
              
              var q/*_mochaCatchCache*/;
              
              var r/*m*/;
              
              var s/*i*/;
              
              var a/*flg*/;
              
              var t/*_mochaGenerator*/ = function ( k/*_isYieldSend*/,n/*_isYieldSafe*/ ) {
                    if ( !k/*_isYieldSend*/ ){
                      o/*_mochaIsNewBorn*/ = false;
                    } else if ( k/*_isYieldSend*/ && o/*_mochaIsNewBorn*/ && arguments[1] !== undefined ){
                      l/*Runtime*/.exceptionHandler( 'attempt to send to newborn generator.' );
                    };
                    
                    while ( 1 )try {
                      switch ( a/*_yieldState*/ ) {
                        case 0 :
                          
                          a/*flg*/ = false;
                          
                          s/*i*/ = 0;
                          
                          if ( !( s/*i*/<10 ) ){
                            a/*_yieldState*/ = -1;
                            break;
                          };
                        case 1 :
                          
                          a/*_yieldState*/ = 2;
                          
                          q/*_mochaCatchCache*/ = function ( a/*e*/ ) {
                            a/*_yieldState*/ = 3;
                          };
                          
                          b/*_mochaFinallyCache*/ = function (  ) {
                            flg = true;
                          };
                          
                          r/*m*/ = ( a/*flg*/ )?1 : 0;
                          return r/*m*/;
                        case 2 :
                          
                          ddddd();
                          
                          q/*_mochaCatchCache*/ = undefined;
                          
                          b/*_mochaFinallyCache*/ = undefined;
                        case 3 :
                          
                          s/*i*/ ++ ;
                          
                          if ( s/*i*/<10 ){
                            a/*_yieldState*/ = 1;
                            break;
                          } else {
                            a/*_yieldState*/ = -1;
                          };
                        case -1 :
                          
                          if ( n/*_isYieldSafe*/ )return undefined;
                           else l/*Runtime*/.throwStopIteration();
                          
                      };
                    } catch( _mochaException ){
                      if ( q/*_mochaCatchCache*/ ){
                        var o/*_mochaLocalTmp0*/ = q/*_mochaCatchCache*/( _mochaException );
                        
                        if ( o/*_mochaLocalTmp0*/ !== undefined ){
                          return o/*_mochaLocalTmp0*/;
                        };
                      } else l/*Runtime*/.throwException( _mochaException );
                    } finally {
                      if ( b/*_mochaFinallyCache*/ ){
                        var p/*_mochaLocalTmp1*/ = b/*_mochaFinallyCache*/(  );
                        
                        if ( p/*_mochaLocalTmp1*/ !== undefined ){
                          return p/*_mochaLocalTmp1*/;
                        };
                      };
                    };
                  };
              return l/*Runtime*/.createGenerator( t/*_mochaGenerator*/,
              function (  ) {
                _yieldState = -1;
                
                if ( _mochaFinallyCache )_mochaFinallyCache(  );
              },this);
            };
            
            generator = o/*yieldTest10*/();
          },
          case10 : function A/*case10*/() {
            function m/*yieldTest11*/(  ) {
              var k/*_mochaIsNewBorn*/ = true;
              
              var m/*_yieldResult*/ = undefined;
              
              var a/*_yieldState*/ = 0;
              
              var n/*type*/;
              
              var o/*i*/;
              
              var p/*_mochaGenerator*/ = function ( f/*_isYieldSend*/,g/*_isYieldSafe*/ ) {
                    if ( !f/*_isYieldSend*/ ){
                      k/*_mochaIsNewBorn*/ = false;
                    } else if ( f/*_isYieldSend*/ && k/*_mochaIsNewBorn*/ && arguments[1] !== undefined ){
                      l/*Runtime*/.exceptionHandler( 'attempt to send to newborn generator.' );
                    };
                    
                    while ( 1 ){
                      switch ( a/*_yieldState*/ ) {
                        case 0 :
                          
                          o/*i*/ = 0;
                          
                          if ( !( o/*i*/<10 ) ){
                            a/*_yieldState*/ = -1;
                            break;
                          };
                        case 1 :
                          
                          a/*_yieldState*/ = 2;
                          return ;
                        case 2 :
                          
                          m/*_yieldResult*/ = f/*_isYieldSend*/ && arguments.length>2?l/*Runtime*/.toArray( arguments,2 )[0] : undefined;
                          
                          n/*type*/ = m/*_yieldResult*/;
                          
                          switch ( n/*type*/ ) {
                            case 0 :
                              
                              a/*_yieldState*/ = 3;
                              break;
                            case 2 :
                              
                              a/*_yieldState*/ = 4;
                              break;
                            case 3 :
                              
                              a/*_yieldState*/ = 5;
                              break;
                            default :
                              
                              a/*_yieldState*/ = 6;
                              break;
                              
                          };
                          break;
                        case 3 :
                          
                          a/*_yieldState*/ = 7;
                          return 200;
                        case 4 :
                          
                          a/*_yieldState*/ = 7;
                          return 400;
                        case 5 :
                          
                          a/*_yieldState*/ = 7;
                          return 600;
                        case 6 :
                          
                          a/*_yieldState*/ = 7;
                          return 700;
                        case 7 :
                          
                          o/*i*/ ++ ;
                          
                          if ( o/*i*/<10 ){
                            a/*_yieldState*/ = 1;
                            break;
                          } else {
                            a/*_yieldState*/ = -1;
                          };
                        case -1 :
                          
                          if ( g/*_isYieldSafe*/ )return undefined;
                           else l/*Runtime*/.throwStopIteration();
                          
                      };
                    };
                  };
              return l/*Runtime*/.createGenerator( p/*_mochaGenerator*/,
              function (  ) {
                _yieldState = -1;
              },this);
            };
            
            generator = m/*yieldTest11*/();
            
            generator.next();
            
            generator.next();
            
            generator.next();
            
            generator.next();
          },
          case11 : function B/*case11*/() {
            function n/*yieldTest12*/(  ) {
              var k/*_mochaIsNewBorn*/ = true;
              
              var m/*_yieldResult*/ = undefined;
              
              var a/*_yieldState*/ = 0;
              
              var n/*type*/;
              
              var o/*i*/;
              
              var p/*_mochaGenerator*/ = function ( f/*_isYieldSend*/,g/*_isYieldSafe*/ ) {
                    if ( !f/*_isYieldSend*/ ){
                      k/*_mochaIsNewBorn*/ = false;
                    } else if ( f/*_isYieldSend*/ && k/*_mochaIsNewBorn*/ && arguments[1] !== undefined ){
                      l/*Runtime*/.exceptionHandler( 'attempt to send to newborn generator.' );
                    };
                    
                    while ( 1 ){
                      switch ( a/*_yieldState*/ ) {
                        case 0 :
                          
                          o/*i*/ = 0;
                          
                          if ( !( o/*i*/<15 ) ){
                            a/*_yieldState*/ = -1;
                            break;
                          };
                        case 1 :
                          
                          a/*_yieldState*/ = 2;
                          return ;
                        case 2 :
                          
                          m/*_yieldResult*/ = f/*_isYieldSend*/ && arguments.length>2?l/*Runtime*/.toArray( arguments,2 )[0] : undefined;
                          
                          n/*type*/ = m/*_yieldResult*/;
                          
                          switch ( n/*type*/ ) {
                            case 4 :
                            case 0 :
                              
                              a/*_yieldState*/ = 3;
                              break;
                            case 5 :
                              
                              a/*_yieldState*/ = 7;
                              break;
                            case 6 :
                            case 2 :
                              
                              a/*_yieldState*/ = 4;
                              break;
                            case 3 :
                              
                              a/*_yieldState*/ = 5;
                              break;
                            default :
                              
                              a/*_yieldState*/ = 6;
                              break;
                              
                          };
                          break;
                        case 3 :
                          
                          a/*_yieldState*/ = 8;
                          return 200;
                        case 4 :
                          
                          a/*_yieldState*/ = 8;
                          return 400;
                        case 5 :
                          
                          a/*_yieldState*/ = 8;
                          return 600;
                        case 6 :
                          
                          a/*_yieldState*/ = 8;
                          return 700;
                        case 7 :
                          
                          a/*_yieldState*/ = 8;
                          break;
                        case 8 :
                          
                          o/*i*/ ++ ;
                          
                          if ( o/*i*/<15 ){
                            a/*_yieldState*/ = 1;
                            break;
                          } else {
                            a/*_yieldState*/ = -1;
                          };
                        case -1 :
                          
                          if ( g/*_isYieldSafe*/ )return undefined;
                           else l/*Runtime*/.throwStopIteration();
                          
                      };
                    };
                  };
              return l/*Runtime*/.createGenerator( p/*_mochaGenerator*/,
              function (  ) {
                _yieldState = -1;
              },this);
            };
            
            generator = n/*yieldTest12*/();
            
            generator.next();
            
            generator.next();
            
            generator.next();
            
            generator.next();
            
            generator.next();
          },
          case12 : function C/*case12*/() {
            function m/*yieldTest13*/() {
              var m/*_mochaIsNewBorn*/ = true;
              
              var n/*_yieldResult*/ = undefined;
              
              var a/*_yieldState*/ = 0;
              
              var o/*length*/;
              
              var p/*_mochaLocalTmp4*/;
              
              var q/*i*/;
              
              var r/*obj*/;
              
              var s/*_mochaLocalTmp3*/ = [];
              
              var t/*_mochaGenerator*/ = function ( g/*_isYieldSend*/,h/*_isYieldSafe*/ ) {
                    if ( !g/*_isYieldSend*/ ){
                      m/*_mochaIsNewBorn*/ = false;
                    } else if ( g/*_isYieldSend*/ && m/*_mochaIsNewBorn*/ && arguments[1] !== undefined ){
                      l/*Runtime*/.exceptionHandler( 'attempt to send to newborn generator.' );
                    };
                    
                    while ( 1 ){
                      switch ( a/*_yieldState*/ ) {
                        case 0 :
                          
                          r/*obj*/ =  {
                            x : 200,
                            y : 300,
                            z : 400
                          };
                          
                          for ( var _mochaLocalTmp2 in r/*obj*/ )
                          s/*_mochaLocalTmp3*/.push( _mochaLocalTmp2 );
                          
                          p/*_mochaLocalTmp4*/ = 0;
                          
                          o/*length*/ = s/*_mochaLocalTmp3*/.length;
                          
                          if ( !( p/*_mochaLocalTmp4*/<o/*length*/ ) ){
                            a/*_yieldState*/ = -1;
                            break;
                          };
                        case 1 :
                          
                          a/*_yieldState*/ = 2;
                          
                          q/*i*/ = s/*_mochaLocalTmp3*/[p/*_mochaLocalTmp4*/];
                          return [q/*i*/,r/*obj*/[q/*i*/]];
                        case 2 :
                          
                           ++ p/*_mochaLocalTmp4*/;
                          
                          if ( p/*_mochaLocalTmp4*/<o/*length*/ ){
                            a/*_yieldState*/ = 1;
                            break;
                          } else {
                            a/*_yieldState*/ = -1;
                          };
                        case -1 :
                          
                          if ( h/*_isYieldSafe*/ )return undefined;
                           else l/*Runtime*/.throwStopIteration();
                          
                      };
                    };
                  };
              return l/*Runtime*/.createGenerator( t/*_mochaGenerator*/,
              function (  ) {
                _yieldState = -1;
              },this);
            };
            
            generator = m/*yieldTest13*/();
            
            var n/*ret*/ = generator.next();
            
            n/*ret*/ = generator.next();
            
            n/*ret*/ = generator.next();
          },
          case13 : function D/*case13*/() {
            function n/*keys*/( m/*obj*/ ) {
              var n/*_mochaIsNewBorn*/ = true;
              
              var o/*_yieldResult*/ = undefined;
              
              var a/*_yieldState*/ = 0;
              
              var p/*length*/;
              
              var q/*_mochaLocalTmp7*/;
              
              var r/*prop*/;
              
              var s/*_mochaLocalTmp6*/ = [];
              
              var t/*_mochaGenerator*/ = function ( g/*_isYieldSend*/,h/*_isYieldSafe*/ ) {
                    if ( !g/*_isYieldSend*/ ){
                      n/*_mochaIsNewBorn*/ = false;
                    } else if ( g/*_isYieldSend*/ && n/*_mochaIsNewBorn*/ && arguments[1] !== undefined ){
                      l/*Runtime*/.exceptionHandler( 'attempt to send to newborn generator.' );
                    };
                    
                    while ( 1 ){
                      switch ( a/*_yieldState*/ ) {
                        case 0 :
                          
                          for ( var _mochaLocalTmp5 in m/*obj*/ )
                          s/*_mochaLocalTmp6*/.push( _mochaLocalTmp5 );
                          
                          q/*_mochaLocalTmp7*/ = 0;
                          
                          p/*length*/ = s/*_mochaLocalTmp6*/.length;
                          
                          if ( !( q/*_mochaLocalTmp7*/<p/*length*/ ) ){
                            a/*_yieldState*/ = -1;
                            break;
                          };
                        case 1 :
                          
                          r/*prop*/ = s/*_mochaLocalTmp6*/[q/*_mochaLocalTmp7*/];
                          
                          if ( m/*obj*/.hasOwnProperty( r/*prop*/ ) ){
                            a/*_yieldState*/ = 2;
                            break;
                          } else {
                            a/*_yieldState*/ = 3;
                            break;
                          };
                        case 2 :
                          
                          a/*_yieldState*/ = 3;
                          return r/*prop*/;
                        case 3 :
                          
                          a/*_yieldState*/ = 4;
                          break;
                        case 4 :
                          
                           ++ q/*_mochaLocalTmp7*/;
                          
                          if ( q/*_mochaLocalTmp7*/<p/*length*/ ){
                            a/*_yieldState*/ = 1;
                            break;
                          } else {
                            a/*_yieldState*/ = -1;
                          };
                        case -1 :
                          
                          if ( h/*_isYieldSafe*/ )return undefined;
                           else l/*Runtime*/.throwStopIteration();
                          
                      };
                    };
                  };
              return l/*Runtime*/.createGenerator( t/*_mochaGenerator*/,
              function (  ) {
                _yieldState = -1;
              },this);
            };
            
            var o/*testObject*/ =  {
                  value1 : 1,
                  value2 : 2,
                  value3 : 3,
                  value4 : 4
                };
            
            try {
              var p/*itemGen*/ = n/*keys*/( o/*testObject*/ );
            } catch( e ){
              
            };
          }
        };
    
    for ( var i = 1;i<13;i ++  ){
      E/*tests*/["case"+i]();
    };
  })();
})();
