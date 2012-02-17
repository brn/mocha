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
  
  var q/*Runtime*/ = ( function q/*Runtime*/() {
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
    p/*_mochaGlobalExport*/['./knockout-2.0.0.debug.js'] = {};
    
    var l/*_mochaGlobalAlias*/ = p/*_mochaGlobalExport*/['./knockout-2.0.0.debug.js'];
    
    ( function ( k/*window*/,l/*undefined*/ ) {
      var b/*ko*/ = k/*window*/["ko"] = {};
      
      b/*ko*/.exportSymbol = function ( b/*publicPath*/,c/*object*/ ) {
        var d/*tokens*/ = b/*publicPath*/.split( "." );
        
        var e/*target*/ = k/*window*/;
        
        for ( var i = 0;i<d/*tokens*/.length-1;i ++  ){
          e/*target*/ = e/*target*/[d/*tokens*/[i]];
        };
        
        e/*target*/[d/*tokens*/[d/*tokens*/.length-1]] = c/*object*/;
      };
      
      b/*ko*/.exportProperty = function ( a/*owner*/,b/*publicName*/,c/*object*/ ) {
        a/*owner*/[b/*publicName*/] = c/*object*/;
      };
      
      b/*ko*/.utils = new ( function () {
        var j/*stringTrimRegex*/ = /^(\s|\u00A0)+|(\s|\u00A0)+$/g;
        
        var k/*knownEvents*/ = {},
            l/*knownEventTypesByEventName*/ = {};
        
        var m/*keyEventTypeName*/ = /Firefox\/2/i.test( navigator.userAgent )?'KeyboardEvent' : 'UIEvents';
        
        k/*knownEvents*/[m/*keyEventTypeName*/] = ['keyup','keydown','keypress'];
        
        k/*knownEvents*/['MouseEvents'] = ['click','dblclick','mousedown','mouseup','mousemove','mouseover','mouseout','mouseenter','mouseleave'];
        
        for ( var eventType in k/*knownEvents*/ ){
          var n/*knownEventsForType*/ = k/*knownEvents*/[eventType];
          
          if ( n/*knownEventsForType*/.length ){
            for ( var i = 0,j = n/*knownEventsForType*/.length;i<j;i ++  ){
              l/*knownEventTypesByEventName*/[n/*knownEventsForType*/[i]] = eventType;
            };
          };
        };
        
        var o/*ieVersion*/ = ( function () {
              var b/*version*/ = 3,
                  c/*div*/ = document.createElement( 'div' ),
                  d/*iElems*/ = c/*div*/.getElementsByTagName( 'i' );
              
              while ( c/*div*/.innerHTML = '<!--[if gt IE '+(  ++ b/*version*/ )+']><i></i><![endif]-->' , d/*iElems*/[0] ){
                
              };
              return b/*version*/>4?b/*version*/ : l/*undefined*/;
            }());
        
        var p/*isIe6*/ = o/*ieVersion*/ === 6,
            q/*isIe7*/ = o/*ieVersion*/ === 7;
        
        function r/*isClickOnCheckableElement*/( a/*element*/,b/*eventType*/ ) {
          if ( ( a/*element*/.tagName != "INPUT" ) || !a/*element*/.type )return false;
          
          if ( b/*eventType*/.toLowerCase() != "click" )return false;
          
          var c/*inputType*/ = a/*element*/.type.toLowerCase();
          return ( c/*inputType*/ == "checkbox" ) || ( c/*inputType*/ == "radio" );
        }return  {
          fieldsIncludedWithJsonPost : ['authenticity_token',/^__RequestVerificationToken(_.*)?$/],
          arrayForEach : function ( b/*array*/,c/*action*/ ) {
            for ( var i = 0,j = b/*array*/.length;i<j;i ++  ){
              c/*action*/( b/*array*/[i] );
            };
          },
          arrayIndexOf : function ( c/*array*/,d/*item*/ ) {
            if ( typeof Array.prototype.indexOf == "function" )return Array.prototype.indexOf.call( c/*array*/,d/*item*/ );
            
            for ( var i = 0,j = c/*array*/.length;i<j;i ++  ){
              if ( c/*array*/[i] === d/*item*/ )return i;
            };
            return -1;
          },
          arrayFirst : function ( b/*array*/,c/*predicate*/,d/*predicateOwner*/ ) {
            for ( var i = 0,j = b/*array*/.length;i<j;i ++  ){
              if ( c/*predicate*/.call( d/*predicateOwner*/,b/*array*/[i] ) )return b/*array*/[i];
            };
            return null;
          },
          arrayRemoveItem : function ( a/*array*/,b/*itemToRemove*/ ) {
            var c/*index*/ = b/*ko*/.utils.arrayIndexOf( a/*array*/,b/*itemToRemove*/ );
            
            if ( c/*index*/ >= 0 )a/*array*/.splice( c/*index*/,1 );
          },
          arrayGetDistinctValues : function ( b/*array*/ ) {
            b/*array*/ = b/*array*/ || [];
            
            var c/*result*/ = [];
            
            for ( var i = 0,j = b/*array*/.length;i<j;i ++  ){
              if ( b/*ko*/.utils.arrayIndexOf( c/*result*/,b/*array*/[i] )<0 )c/*result*/.push( b/*array*/[i] );
            };
            return c/*result*/;
          },
          arrayMap : function ( b/*array*/,c/*mapping*/ ) {
            b/*array*/ = b/*array*/ || [];
            
            var d/*result*/ = [];
            
            for ( var i = 0,j = b/*array*/.length;i<j;i ++  ){
              d/*result*/.push( c/*mapping*/( b/*array*/[i] ) );
            };
            return d/*result*/;
          },
          arrayFilter : function ( b/*array*/,c/*predicate*/ ) {
            b/*array*/ = b/*array*/ || [];
            
            var d/*result*/ = [];
            
            for ( var i = 0,j = b/*array*/.length;i<j;i ++  ){
              if ( c/*predicate*/( b/*array*/[i] ) )d/*result*/.push( b/*array*/[i] );
            };
            return d/*result*/;
          },
          arrayPushAll : function ( b/*array*/,c/*valuesToPush*/ ) {
            for ( var i = 0,j = c/*valuesToPush*/.length;i<j;i ++  ){
              b/*array*/.push( c/*valuesToPush*/[i] );
            };
            return b/*array*/;
          },
          extend : function ( b/*target*/,c/*source*/ ) {
            for ( var prop in c/*source*/ ){
              if ( c/*source*/.hasOwnProperty( prop ) ){
                b/*target*/[prop] = c/*source*/[prop];
              };
            };
            return b/*target*/;
          },
          emptyDomNode : function ( a/*domNode*/ ) {
            while ( a/*domNode*/.firstChild ){
              b/*ko*/.removeNode( a/*domNode*/.firstChild );
            };
          },
          setDomNodeChildren : function ( a/*domNode*/,b/*childNodes*/ ) {
            b/*ko*/.utils.emptyDomNode( a/*domNode*/ );
            
            if ( b/*childNodes*/ ){
              b/*ko*/.utils.arrayForEach( b/*childNodes*/,
              function ( a/*childNode*/ ) {
                a/*domNode*/.appendChild( a/*childNode*/ );
              });
            };
          },
          replaceDomNodes : function ( b/*nodeToReplaceOrNodeArray*/,c/*newNodesArray*/ ) {
            var d/*nodesToReplaceArray*/ = b/*nodeToReplaceOrNodeArray*/.nodeType?[b/*nodeToReplaceOrNodeArray*/] : b/*nodeToReplaceOrNodeArray*/;
            
            if ( d/*nodesToReplaceArray*/.length>0 ){
              var e/*insertionPoint*/ = d/*nodesToReplaceArray*/[0];
              
              var f/*parent*/ = e/*insertionPoint*/.parentNode;
              
              for ( var i = 0,j = c/*newNodesArray*/.length;i<j;i ++  ){
                f/*parent*/.insertBefore( c/*newNodesArray*/[i],e/*insertionPoint*/ );
              };
              
              for ( var i = 0,j = d/*nodesToReplaceArray*/.length;i<j;i ++  ){
                b/*ko*/.removeNode( d/*nodesToReplaceArray*/[i] );
              };
            };
          },
          setOptionNodeSelectionState : function ( b/*optionNode*/,c/*isSelected*/ ) {
            if ( navigator.userAgent.indexOf( "MSIE 6" ) >= 0 )b/*optionNode*/.setAttribute( "selected",c/*isSelected*/ );
             else b/*optionNode*/.selected = c/*isSelected*/;
          },
          stringTrim : function ( a/*string*/ ) {
            return ( a/*string*/ || "" ).replace( j/*stringTrimRegex*/,"" );
          },
          stringTokenize : function ( b/*string*/,c/*delimiter*/ ) {
            var d/*result*/ = [];
            
            var e/*tokens*/ = ( b/*string*/ || "" ).split( c/*delimiter*/ );
            
            for ( var i = 0,j = e/*tokens*/.length;i<j;i ++  ){
              var f/*trimmed*/ = b/*ko*/.utils.stringTrim( e/*tokens*/[i] );
              
              if ( f/*trimmed*/ !== "" )d/*result*/.push( f/*trimmed*/ );
            };
            return d/*result*/;
          },
          stringStartsWith : function ( a/*string*/,b/*startsWith*/ ) {
            a/*string*/ = a/*string*/ || "";
            
            if ( b/*startsWith*/.length>a/*string*/.length )return false;
            return a/*string*/.substring( 0,b/*startsWith*/.length ) === b/*startsWith*/;
          },
          evalWithinScope : function ( e/*expression*/ ) {
            var f/*scopes*/ = Array.prototype.slice.call( arguments,1 );
            
            var g/*functionBody*/ = "return ("+e/*expression*/+")";
            
            for ( var i = 0;i<f/*scopes*/.length;i ++  ){
              if ( f/*scopes*/[i] && typeof f/*scopes*/[i] == "object" )g/*functionBody*/ = "with(sc["+i+"]) { "+g/*functionBody*/+" } ";
            };
            return ( new Function( "sc",g/*functionBody*/ ) )( f/*scopes*/ );
          },
          domNodeIsContainedBy : function ( a/*node*/,b/*containedByNode*/ ) {
            if ( b/*containedByNode*/.compareDocumentPosition )return ( b/*containedByNode*/.compareDocumentPosition( a/*node*/ )&16 ) == 16;
            
            while ( a/*node*/ != null ){
              if ( a/*node*/ == b/*containedByNode*/ )return true;
              
              a/*node*/ = a/*node*/.parentNode;
            };
            return false;
          },
          domNodeIsAttachedToDocument : function ( b/*node*/ ) {
            return b/*ko*/.utils.domNodeIsContainedBy( b/*node*/,document );
          },
          registerEventHandler : function ( c/*element*/,d/*eventType*/,e/*handler*/ ) {
            if ( typeof jQuery != "undefined" ){
              if ( r/*isClickOnCheckableElement*/( c/*element*/,d/*eventType*/ ) ){
                var f/*originalHandler*/ = e/*handler*/;
                
                e/*handler*/ = function ( a/*event*/,b/*eventData*/ ) {
                  var c/*jQuerySuppliedCheckedState*/ = this.checked;
                  
                  if ( b/*eventData*/ )this.checked = b/*eventData*/.checkedStateBeforeEvent !== true;
                  
                  f/*originalHandler*/.call( this,a/*event*/ );
                  
                  this.checked = c/*jQuerySuppliedCheckedState*/;
                };
              };
              
              jQuery( c/*element*/ )['bind']( d/*eventType*/,e/*handler*/ );
            } else if ( typeof c/*element*/.addEventListener == "function" )c/*element*/.addEventListener( d/*eventType*/,e/*handler*/,false );
             else if ( typeof c/*element*/.attachEvent != "undefined" )c/*element*/.attachEvent( "on"+d/*eventType*/,
            function ( a/*event*/ ) {
              e/*handler*/.call( c/*element*/,a/*event*/ );
            });
             else throw new Error( "Browser doesn't support addEventListener or attachEvent" );
          },
          triggerEvent : function ( d/*element*/,e/*eventType*/ ) {
            if ( !( d/*element*/ && d/*element*/.nodeType ) )throw new Error( "element must be a DOM node when calling triggerEvent" );
            
            if ( typeof jQuery != "undefined" ){
              var f/*eventData*/ = [];
              
              if ( r/*isClickOnCheckableElement*/( d/*element*/,e/*eventType*/ ) ){
                f/*eventData*/.push(  {
                  checkedStateBeforeEvent : d/*element*/.checked
                });
              };
              
              jQuery( d/*element*/ )['trigger']( e/*eventType*/,f/*eventData*/ );
            } else if ( typeof document.createEvent == "function" ){
              if ( typeof d/*element*/.dispatchEvent == "function" ){
                var g/*eventCategory*/ = l/*knownEventTypesByEventName*/[e/*eventType*/] || "HTMLEvents";
                
                var h/*event*/ = document.createEvent( g/*eventCategory*/ );
                
                h/*event*/.initEvent( e/*eventType*/,true,true,k/*window*/,0,0,0,0,0,false,false,false,false,0,d/*element*/ );
                
                d/*element*/.dispatchEvent( h/*event*/ );
              } else throw new Error( "The supplied element doesn't support dispatchEvent" );
            } else if ( typeof d/*element*/.fireEvent != "undefined" ){
              if ( e/*eventType*/ == "click" ){
                if ( ( d/*element*/.tagName == "INPUT" ) && ( ( d/*element*/.type.toLowerCase() == "checkbox" ) || ( d/*element*/.type.toLowerCase() == "radio" ) ) )d/*element*/.checked = d/*element*/.checked !== true;
              };
              
              d/*element*/.fireEvent( "on"+e/*eventType*/ );
            } else throw new Error( "Browser doesn't support triggering events" );
          },
          unwrapObservable : function ( a/*value*/ ) {
            return b/*ko*/.isObservable( a/*value*/ )?a/*value*/() : a/*value*/;
          },
          domNodeHasCssClass : function ( a/*node*/,b/*className*/ ) {
            var c/*currentClassNames*/ = ( a/*node*/.className || "" ).split( /\s+/ );
            return b/*ko*/.utils.arrayIndexOf( c/*currentClassNames*/,b/*className*/ ) >= 0;
          },
          toggleDomNodeCssClass : function ( b/*node*/,c/*className*/,d/*shouldHaveClass*/ ) {
            var e/*hasClass*/ = b/*ko*/.utils.domNodeHasCssClass( b/*node*/,c/*className*/ );
            
            if ( d/*shouldHaveClass*/ && !e/*hasClass*/ ){
              b/*node*/.className = ( b/*node*/.className || "" )+" "+c/*className*/;
            } else if ( e/*hasClass*/ && !d/*shouldHaveClass*/ ){
              var f/*currentClassNames*/ = ( b/*node*/.className || "" ).split( /\s+/ );
              
              var g/*newClassName*/ = "";
              
              for ( var i = 0;i<f/*currentClassNames*/.length;i ++  ){
                if ( f/*currentClassNames*/[i] != c/*className*/ )g/*newClassName*/ += f/*currentClassNames*/[i]+" ";
              };
              
              b/*node*/.className = b/*ko*/.utils.stringTrim( g/*newClassName*/ );
            };
          },
          outerHTML : function ( a/*node*/ ) {
            if ( o/*ieVersion*/ === l/*undefined*/ ){
              var b/*nativeOuterHtml*/ = a/*node*/.outerHTML;
              
              if ( typeof b/*nativeOuterHtml*/ == "string" )return b/*nativeOuterHtml*/;
            };
            
            var c/*dummyContainer*/ = k/*window*/.document.createElement( "div" );
            
            c/*dummyContainer*/.appendChild( a/*node*/.cloneNode( true ) );
            return c/*dummyContainer*/.innerHTML;
          },
          setTextContent : function ( a/*element*/,b/*textContent*/ ) {
            var c/*value*/ = b/*ko*/.utils.unwrapObservable( b/*textContent*/ );
            
            if ( ( c/*value*/ === null ) || ( c/*value*/ === l/*undefined*/ ) )c/*value*/ = "";
            
            'innerText' in a/*element*/?a/*element*/.innerText = c/*value*/ : a/*element*/.textContent = c/*value*/;
            
            if ( o/*ieVersion*/ >= 9 ){
              a/*element*/.innerHTML = a/*element*/.innerHTML;
            };
          },
          range : function ( b/*min*/,c/*max*/ ) {
            b/*min*/ = b/*ko*/.utils.unwrapObservable( b/*min*/ );
            
            c/*max*/ = b/*ko*/.utils.unwrapObservable( c/*max*/ );
            
            var d/*result*/ = [];
            
            for ( var i = b/*min*/;i <= c/*max*/;i ++  ){
              d/*result*/.push( i );
            };
            return d/*result*/;
          },
          makeArray : function ( b/*arrayLikeObject*/ ) {
            var c/*result*/ = [];
            
            for ( var i = 0,j = b/*arrayLikeObject*/.length;i<j;i ++  ){
              c/*result*/.push( b/*arrayLikeObject*/[i] );
            };
            return c/*result*/;
          },
          isIe6 : p/*isIe6*/,
          isIe7 : q/*isIe7*/,
          getFormFields : function ( b/*form*/,c/*fieldName*/ ) {
            var d/*fields*/ = b/*ko*/.utils.makeArray( b/*form*/.getElementsByTagName( "INPUT" ) ).concat( b/*ko*/.utils.makeArray( b/*form*/.getElementsByTagName( "TEXTAREA" ) ) );
            
            var e/*isMatchingField*/ = ( typeof c/*fieldName*/ == 'string' )?function ( a/*field*/ ) {
                  return a/*field*/.name === c/*fieldName*/;
                } : function ( a/*field*/ ) {
                  return c/*fieldName*/.test( a/*field*/.name );
                };
            
            var f/*matches*/ = [];
            
            for ( var i = d/*fields*/.length-1;i >= 0;i --  ){
              if ( e/*isMatchingField*/( d/*fields*/[i] ) )f/*matches*/.push( d/*fields*/[i] );
            };
            return f/*matches*/;
          },
          parseJson : function ( b/*jsonString*/ ) {
            if ( typeof b/*jsonString*/ == "string" ){
              b/*jsonString*/ = b/*ko*/.utils.stringTrim( b/*jsonString*/ );
              
              if ( b/*jsonString*/ ){
                if ( k/*window*/.JSON && k/*window*/.JSON.parse )return k/*window*/.JSON.parse( b/*jsonString*/ );
                return ( new Function( "return "+b/*jsonString*/ ) )();
              };
            };
            return null;
          },
          stringifyJson : function ( c/*data*/ ) {
            if ( ( typeof JSON == "undefined" ) || ( typeof JSON.stringify == "undefined" ) )throw new Error( "Cannot find JSON.stringify(). Some browsers (e.g., IE < 8) don't support it natively, but you can overcome this by adding a script reference to json2.js, downloadable from http://www.json.org/json2.js" );
            return JSON.stringify( b/*ko*/.utils.unwrapObservable( c/*data*/ ) );
          },
          postJson : function ( g/*urlOrForm*/,h/*data*/,i/*options*/ ) {
            i/*options*/ = i/*options*/ || {};
            
            var j/*params*/ = i/*options*/['params'] || {};
            
            var k/*includeFields*/ = i/*options*/['includeFields'] || this.fieldsIncludedWithJsonPost;
            
            var l/*url*/ = g/*urlOrForm*/;
            
            if ( ( typeof g/*urlOrForm*/ == 'object' ) && ( g/*urlOrForm*/.tagName == "FORM" ) ){
              var m/*originalForm*/ = g/*urlOrForm*/;
              
              l/*url*/ = m/*originalForm*/.action;
              
              for ( var i = k/*includeFields*/.length-1;i >= 0;i --  ){
                var n/*fields*/ = b/*ko*/.utils.getFormFields( m/*originalForm*/,k/*includeFields*/[i] );
                
                for ( var j = n/*fields*/.length-1;j >= 0;j --  ){
                  j/*params*/[n/*fields*/[j].name] = n/*fields*/[j].value;
                };
              };
            };
            
            h/*data*/ = b/*ko*/.utils.unwrapObservable( h/*data*/ );
            
            var a/*form*/ = document.createElement( "FORM" );
            
            a/*form*/.style.display = "none";
            
            a/*form*/.action = l/*url*/;
            
            a/*form*/.method = "post";
            
            for ( var key in h/*data*/ ){
              var o/*input*/ = document.createElement( "INPUT" );
              
              o/*input*/.name = key;
              
              o/*input*/.value = b/*ko*/.utils.stringifyJson( b/*ko*/.utils.unwrapObservable( h/*data*/[key] ) );
              
              a/*form*/.appendChild( o/*input*/ );
            };
            
            for ( var key in j/*params*/ ){
              var o/*input*/ = document.createElement( "INPUT" );
              
              o/*input*/.name = key;
              
              o/*input*/.value = j/*params*/[key];
              
              a/*form*/.appendChild( o/*input*/ );
            };
            
            document.body.appendChild( a/*form*/ );
            
            i/*options*/['submitter']?i/*options*/['submitter']( a/*form*/ ) : a/*form*/.submit();
            
            setTimeout( function () {
              form.parentNode.removeChild( form );
            },0);
          }
        };
      })();
      
      b/*ko*/.exportSymbol( 'ko.utils',b/*ko*/.utils );
      
      b/*ko*/.utils.arrayForEach( [['arrayForEach',b/*ko*/.utils.arrayForEach],['arrayFirst',b/*ko*/.utils.arrayFirst],['arrayFilter',b/*ko*/.utils.arrayFilter],['arrayGetDistinctValues',b/*ko*/.utils.arrayGetDistinctValues],['arrayIndexOf',b/*ko*/.utils.arrayIndexOf],['arrayMap',b/*ko*/.utils.arrayMap],['arrayPushAll',b/*ko*/.utils.arrayPushAll],['arrayRemoveItem',b/*ko*/.utils.arrayRemoveItem],['extend',b/*ko*/.utils.extend],['fieldsIncludedWithJsonPost',b/*ko*/.utils.fieldsIncludedWithJsonPost],['getFormFields',b/*ko*/.utils.getFormFields],['postJson',b/*ko*/.utils.postJson],['parseJson',b/*ko*/.utils.parseJson],['registerEventHandler',b/*ko*/.utils.registerEventHandler],['stringifyJson',b/*ko*/.utils.stringifyJson],['range',b/*ko*/.utils.range],['toggleDomNodeCssClass',b/*ko*/.utils.toggleDomNodeCssClass],['triggerEvent',b/*ko*/.utils.triggerEvent],['unwrapObservable',b/*ko*/.utils.unwrapObservable]],
      function ( a/*item*/ ) {
        b/*ko*/.exportSymbol( 'ko.utils.'+a/*item*/[0],a/*item*/[1] );
      });
      
      if ( !Function.prototype['bind'] ){
        Function.prototype['bind'] = function ( b/*object*/ ) {
          var a/*originalFunction*/ = this,
              c/*args*/ = Array.prototype.slice.call( arguments ),
              b/*object*/ = c/*args*/.shift();
          return function () {
            return originalFunction.apply( object,args.concat( Array.prototype.slice.call( arguments ) ) );
          };
        };
      };
      
      b/*ko*/.utils.domData = new ( function () {
        var b/*uniqueId*/ = 0;
        
        var c/*dataStoreKeyExpandoPropertyName*/ = "__ko__"+( new Date ).getTime();
        
        var d/*dataStore*/ = {};
        return  {
          get : function ( a/*node*/,b/*key*/ ) {
            var c/*allDataForNode*/ = b/*ko*/.utils.domData.getAll( a/*node*/,false );
            return c/*allDataForNode*/ === l/*undefined*/?l/*undefined*/ : c/*allDataForNode*/[b/*key*/];
          },
          set : function ( a/*node*/,b/*key*/,c/*value*/ ) {
            if ( c/*value*/ === l/*undefined*/ ){
              if ( b/*ko*/.utils.domData.getAll( a/*node*/,false ) === l/*undefined*/ )return ;
            };
            
            var d/*allDataForNode*/ = b/*ko*/.utils.domData.getAll( a/*node*/,true );
            
            d/*allDataForNode*/[b/*key*/] = c/*value*/;
          },
          getAll : function ( a/*node*/,b/*createIfNotFound*/ ) {
            var c/*dataStoreKey*/ = a/*node*/[c/*dataStoreKeyExpandoPropertyName*/];
            
            var d/*hasExistingDataStore*/ = c/*dataStoreKey*/ && ( c/*dataStoreKey*/ !== "null" );
            
            if ( !d/*hasExistingDataStore*/ ){
              if ( !b/*createIfNotFound*/ )return l/*undefined*/;
              
              c/*dataStoreKey*/ = a/*node*/[c/*dataStoreKeyExpandoPropertyName*/] = "ko"+b/*uniqueId*/ ++ ;
              
              d/*dataStore*/[c/*dataStoreKey*/] = {};
            };
            return d/*dataStore*/[c/*dataStoreKey*/];
          },
          clear : function ( a/*node*/ ) {
            var b/*dataStoreKey*/ = a/*node*/[c/*dataStoreKeyExpandoPropertyName*/];
            
            if ( b/*dataStoreKey*/ ){
              delete d/*dataStore*/[b/*dataStoreKey*/];
              
              a/*node*/[c/*dataStoreKeyExpandoPropertyName*/] = null;
            };
          }
        };
      })();
      
      b/*ko*/.exportSymbol( 'ko.utils.domData',b/*ko*/.utils.domData );
      
      b/*ko*/.exportSymbol( 'ko.utils.domData.clear',b/*ko*/.utils.domData.clear );
      
      b/*ko*/.utils.domNodeDisposal = new ( function () {
        var d/*domDataKey*/ = "__ko_domNodeDisposal__"+( new Date ).getTime();
        
        function e/*getDisposeCallbacksCollection*/( a/*node*/,b/*createIfNotFound*/ ) {
          var c/*allDisposeCallbacks*/ = b/*ko*/.utils.domData.get( a/*node*/,d/*domDataKey*/ );
          
          if ( ( c/*allDisposeCallbacks*/ === l/*undefined*/ ) && b/*createIfNotFound*/ ){
            c/*allDisposeCallbacks*/ = [];
            
            b/*ko*/.utils.domData.set( a/*node*/,d/*domDataKey*/,c/*allDisposeCallbacks*/ );
          };
          return c/*allDisposeCallbacks*/;
        }
        function f/*destroyCallbacksCollection*/( a/*node*/ ) {
          b/*ko*/.utils.domData.set( a/*node*/,d/*domDataKey*/,l/*undefined*/ );
        }
        function g/*cleanSingleNode*/( c/*node*/ ) {
          var d/*callbacks*/ = e/*getDisposeCallbacksCollection*/( c/*node*/,false );
          
          if ( d/*callbacks*/ ){
            d/*callbacks*/ = d/*callbacks*/.slice( 0 );
            
            for ( var i = 0;i<d/*callbacks*/.length;i ++  ){
              d/*callbacks*/[i]( c/*node*/ );
            };
          };
          
          b/*ko*/.utils.domData.clear( c/*node*/ );
          
          if ( ( typeof jQuery == "function" ) && ( typeof jQuery['cleanData'] == "function" ) )jQuery['cleanData']( [c/*node*/] );
        }return  {
          addDisposeCallback : function ( b/*node*/,c/*callback*/ ) {
            if ( typeof c/*callback*/ != "function" )throw new Error( "Callback must be a function" );
            
            e/*getDisposeCallbacksCollection*/( b/*node*/,true ).push( c/*callback*/ );
          },
          removeDisposeCallback : function ( a/*node*/,b/*callback*/ ) {
            var c/*callbacksCollection*/ = e/*getDisposeCallbacksCollection*/( a/*node*/,false );
            
            if ( c/*callbacksCollection*/ ){
              b/*ko*/.utils.arrayRemoveItem( c/*callbacksCollection*/,b/*callback*/ );
              
              if ( c/*callbacksCollection*/.length == 0 )f/*destroyCallbacksCollection*/( a/*node*/ );
            };
          },
          cleanNode : function ( b/*node*/ ) {
            if ( ( b/*node*/.nodeType != 1 ) && ( b/*node*/.nodeType != 9 ) )return ;
            
            g/*cleanSingleNode*/( b/*node*/ );
            
            var c/*descendants*/ = [];
            
            b/*ko*/.utils.arrayPushAll( c/*descendants*/,b/*node*/.getElementsByTagName( "*" ) );
            
            for ( var i = 0,j = c/*descendants*/.length;i<j;i ++  ){
              g/*cleanSingleNode*/( c/*descendants*/[i] );
            };
          },
          removeNode : function ( a/*node*/ ) {
            b/*ko*/.cleanNode( a/*node*/ );
            
            if ( a/*node*/.parentNode )a/*node*/.parentNode.removeChild( a/*node*/ );
          }
        };
      })();
      
      b/*ko*/.cleanNode = b/*ko*/.utils.domNodeDisposal.cleanNode;
      
      b/*ko*/.removeNode = b/*ko*/.utils.domNodeDisposal.removeNode;
      
      b/*ko*/.exportSymbol( 'ko.cleanNode',b/*ko*/.cleanNode );
      
      b/*ko*/.exportSymbol( 'ko.removeNode',b/*ko*/.removeNode );
      
      b/*ko*/.exportSymbol( 'ko.utils.domNodeDisposal',b/*ko*/.utils.domNodeDisposal );
      
      b/*ko*/.exportSymbol( 'ko.utils.domNodeDisposal.addDisposeCallback',b/*ko*/.utils.domNodeDisposal.addDisposeCallback );
      
      b/*ko*/.exportSymbol( 'ko.utils.domNodeDisposal.removeDisposeCallback',b/*ko*/.utils.domNodeDisposal.removeDisposeCallback );
      
      ( function () {
        var c/*leadingCommentRegex*/ = /^(\s*)<!--(.*?)-->/;
        
        function d/*simpleHtmlParse*/( b/*html*/ ) {
          var c/*tags*/ = b/*ko*/.utils.stringTrim( b/*html*/ ).toLowerCase(),
              d/*div*/ = document.createElement( "div" );
          
          var e/*wrap*/ = c/*tags*/.match( /^<(thead|tbody|tfoot)/ ) && [1,"<table>","</table>"] || !c/*tags*/.indexOf( "<tr" ) && [2,"<table><tbody>","</tbody></table>"] || ( !c/*tags*/.indexOf( "<td" ) || !c/*tags*/.indexOf( "<th" ) ) && [3,"<table><tbody><tr>","</tr></tbody></table>"] || [0,"",""];
          
          var f/*markup*/ = "ignored<div>"+e/*wrap*/[1]+b/*html*/+e/*wrap*/[2]+"</div>";
          
          if ( typeof k/*window*/['innerShiv'] == "function" ){
            d/*div*/.appendChild( k/*window*/['innerShiv']( f/*markup*/ ) );
          } else {
            d/*div*/.innerHTML = f/*markup*/;
          };
          
          while ( e/*wrap*/[0] --  ){
            d/*div*/ = d/*div*/.lastChild;
          };
          return b/*ko*/.utils.makeArray( d/*div*/.lastChild.childNodes );
        }
        function e/*jQueryHtmlParse*/( b/*html*/ ) {
          var c/*elems*/ = jQuery['clean']( [b/*html*/] );
          
          if ( c/*elems*/ && c/*elems*/[0] ){
            var d/*elem*/ = c/*elems*/[0];
            
            while ( d/*elem*/.parentNode && d/*elem*/.parentNode.nodeType !== 11 ){
              d/*elem*/ = d/*elem*/.parentNode;
            };
            
            if ( d/*elem*/.parentNode )d/*elem*/.parentNode.removeChild( d/*elem*/ );
          };
          return c/*elems*/;
        }
        b/*ko*/.utils.parseHtmlFragment = function ( b/*html*/ ) {
          return typeof jQuery != 'undefined'?e/*jQueryHtmlParse*/( b/*html*/ ) : d/*simpleHtmlParse*/( b/*html*/ );
        };
        
        b/*ko*/.utils.setHtml = function ( c/*node*/,d/*html*/ ) {
          b/*ko*/.utils.emptyDomNode( c/*node*/ );
          
          if ( ( d/*html*/ !== null ) && ( d/*html*/ !== l/*undefined*/ ) ){
            if ( typeof d/*html*/ != 'string' )d/*html*/ = d/*html*/.toString();
            
            if ( typeof jQuery != 'undefined' ){
              jQuery( c/*node*/ )['html']( d/*html*/ );
            } else {
              var e/*parsedNodes*/ = b/*ko*/.utils.parseHtmlFragment( d/*html*/ );
              
              for ( var i = 0;i<e/*parsedNodes*/.length;i ++  ){
                c/*node*/.appendChild( e/*parsedNodes*/[i] );
              };
            };
          };
        };
      })();
      
      b/*ko*/.exportSymbol( 'ko.utils.parseHtmlFragment',b/*ko*/.utils.parseHtmlFragment );
      
      b/*ko*/.exportSymbol( 'ko.utils.setHtml',b/*ko*/.utils.setHtml );
      
      b/*ko*/.memoization = ( function () {
        var c/*memos*/ = {};
        
        function a/*randomMax8HexChars*/() {
          return ( ( ( 1+Math.random() )*0x00000000 )|0 ).toString( 16 ).substring( 1 );
        }
        function d/*generateRandomId*/() {
          return randomMax8HexChars()+randomMax8HexChars();
        }
        function e/*findMemoNodes*/( c/*rootNode*/,d/*appendToArray*/ ) {
          if ( !c/*rootNode*/ )return ;
          
          if ( c/*rootNode*/.nodeType == 8 ){
            var e/*memoId*/ = b/*ko*/.memoization.parseMemoText( c/*rootNode*/.nodeValue );
            
            if ( e/*memoId*/ != null )d/*appendToArray*/.push(  {
              domNode : c/*rootNode*/,
              memoId : e/*memoId*/
            });
          } else if ( c/*rootNode*/.nodeType == 1 ){
            for ( var i = 0,childNodes = c/*rootNode*/.childNodes,j = childNodes.length;i<j;i ++  ){
              e/*findMemoNodes*/( childNodes[i],d/*appendToArray*/ );
            };
          };
        }return  {
          memoize : function ( b/*callback*/ ) {
            if ( typeof b/*callback*/ != "function" )throw new Error( "You can only pass a function to ko.memoization.memoize()" );
            
            var c/*memoId*/ = d/*generateRandomId*/();
            
            c/*memos*/[c/*memoId*/] = b/*callback*/;
            return "<!--[ko_memo:"+c/*memoId*/+"]-->";
          },
          unmemoize : function ( b/*memoId*/,c/*callbackParams*/ ) {
            var d/*callback*/ = c/*memos*/[b/*memoId*/];
            
            if ( d/*callback*/ === l/*undefined*/ )throw new Error( "Couldn't find any memo with ID "+b/*memoId*/+". Perhaps it's already been unmemoized." );
            
            try {
              d/*callback*/.apply( null,c/*callbackParams*/ || [] );
              return true;
            } finally {
              delete c/*memos*/[b/*memoId*/];
            };
          },
          unmemoizeDomNodeAndDescendants : function ( b/*domNode*/,c/*extraCallbackParamsArray*/ ) {
            var d/*memos*/ = [];
            
            e/*findMemoNodes*/( b/*domNode*/,d/*memos*/ );
            
            for ( var i = 0,j = d/*memos*/.length;i<j;i ++  ){
              var e/*node*/ = d/*memos*/[i].domNode;
              
              var f/*combinedParams*/ = [e/*node*/];
              
              if ( c/*extraCallbackParamsArray*/ )b/*ko*/.utils.arrayPushAll( f/*combinedParams*/,c/*extraCallbackParamsArray*/ );
              
              b/*ko*/.memoization.unmemoize( d/*memos*/[i].memoId,f/*combinedParams*/ );
              
              e/*node*/.nodeValue = "";
              
              if ( e/*node*/.parentNode )e/*node*/.parentNode.removeChild( e/*node*/ );
            };
          },
          parseMemoText : function ( a/*memoText*/ ) {
            var b/*match*/ = a/*memoText*/.match( /^\[ko_memo\:(.*?)\]$/ );
            return b/*match*/?b/*match*/[1] : null;
          }
        };
      })();
      
      b/*ko*/.exportSymbol( 'ko.memoization',b/*ko*/.memoization );
      
      b/*ko*/.exportSymbol( 'ko.memoization.memoize',b/*ko*/.memoization.memoize );
      
      b/*ko*/.exportSymbol( 'ko.memoization.unmemoize',b/*ko*/.memoization.unmemoize );
      
      b/*ko*/.exportSymbol( 'ko.memoization.parseMemoText',b/*ko*/.memoization.parseMemoText );
      
      b/*ko*/.exportSymbol( 'ko.memoization.unmemoizeDomNodeAndDescendants',b/*ko*/.memoization.unmemoizeDomNodeAndDescendants );
      
      b/*ko*/.extenders =  {
        'throttle' : function ( a/*target*/,b/*timeout*/ ) {
          a/*target*/['throttleEvaluation'] = b/*timeout*/;
          
          var e/*writeTimeoutInstance*/ = null;
          return b/*ko*/.dependentObservable(  {
            'read' : a/*target*/,
            'write' : function ( b/*value*/ ) {
              clearTimeout( e/*writeTimeoutInstance*/ );
              
              e/*writeTimeoutInstance*/ = setTimeout( function () {
                target( value );
              },b/*timeout*/);
            }
          });
        },
        'notify' : function ( a/*target*/,b/*notifyWhen*/ ) {
          a/*target*/["equalityComparer"] = b/*notifyWhen*/ == "always"?function () {
            return false;
          } : b/*ko*/.observable["fn"]["equalityComparer"];
          return a/*target*/;
        }
      };
      
      function m/*applyExtenders*/( b/*requestedExtenders*/ ) {
        var c/*target*/ = this;
        
        if ( b/*requestedExtenders*/ ){
          for ( var key in b/*requestedExtenders*/ ){
            var d/*extenderHandler*/ = b/*ko*/.extenders[key];
            
            if ( typeof d/*extenderHandler*/ == 'function' ){
              c/*target*/ = d/*extenderHandler*/( c/*target*/,b/*requestedExtenders*/[key] );
            };
          };
        };
        return c/*target*/;
      }
      b/*ko*/.exportSymbol( 'ko.extenders',b/*ko*/.extenders );
      
      b/*ko*/.subscription = function ( a/*callback*/,b/*disposeCallback*/ ) {
        this.callback = a/*callback*/;
        
        this.disposeCallback = b/*disposeCallback*/;
        
        b/*ko*/.exportProperty( this,'dispose',this.dispose );
      };
      
      b/*ko*/.subscription.prototype.dispose = function () {
        this.isDisposed = true;
        
        this.disposeCallback();
      };
      
      b/*ko*/.subscribable = function () {
        this._subscriptions = {};
        
        ko.utils.extend( this,ko.subscribable['fn'] );
        
        ko.exportProperty( this,'subscribe',this.subscribe );
        
        ko.exportProperty( this,'extend',this.extend );
        
        ko.exportProperty( this,'getSubscriptionsCount',this.getSubscriptionsCount );
      };
      
      var n/*defaultEvent*/ = "change";
      
      b/*ko*/.subscribable['fn'] =  {
        subscribe : function ( d/*callback*/,e/*callbackTarget*/,b/*event*/ ) {
          b/*event*/ = b/*event*/ || n/*defaultEvent*/;
          
          var f/*boundCallback*/ = e/*callbackTarget*/?d/*callback*/.bind( e/*callbackTarget*/ ) : d/*callback*/;
          
          var c/*subscription*/ = new b/*ko*/.subscription( f/*boundCallback*/,function () {
                ko.utils.arrayRemoveItem( this._subscriptions[event],subscription );
              }.bind( this ) );
          
          if ( !this._subscriptions[b/*event*/] )this._subscriptions[b/*event*/] = [];
          
          this._subscriptions[b/*event*/].push( c/*subscription*/ );
          return c/*subscription*/;
        },
        "notifySubscribers" : function ( b/*valueToNotify*/,c/*event*/ ) {
          c/*event*/ = c/*event*/ || n/*defaultEvent*/;
          
          if ( this._subscriptions[c/*event*/] ){
            b/*ko*/.utils.arrayForEach( this._subscriptions[c/*event*/].slice( 0 ),
            function ( a/*subscription*/ ) {
              if ( a/*subscription*/ && ( a/*subscription*/.isDisposed !== true ) )a/*subscription*/.callback( b/*valueToNotify*/ );
            });
          };
        },
        getSubscriptionsCount : function () {
          var b/*total*/ = 0;
          
          for ( var eventName in this._subscriptions ){
            if ( this._subscriptions.hasOwnProperty( eventName ) )b/*total*/ += this._subscriptions[eventName].length;
          };
          return b/*total*/;
        },
        extend : m/*applyExtenders*/
      };
      
      b/*ko*/.isSubscribable = function ( a/*instance*/ ) {
        return typeof a/*instance*/.subscribe == "function" && typeof a/*instance*/["notifySubscribers"] == "function";
      };
      
      b/*ko*/.exportSymbol( 'ko.subscribable',b/*ko*/.subscribable );
      
      b/*ko*/.exportSymbol( 'ko.isSubscribable',b/*ko*/.isSubscribable );
      
      b/*ko*/.dependencyDetection = ( function () {
        var a/*_frames*/ = [];
        return  {
          begin : function ( a/*callback*/ ) {
            a/*_frames*/.push(  {
              callback : a/*callback*/,
              distinctDependencies : []
            });
          },
          end : function () {
            _frames.pop();
          },
          registerDependency : function ( b/*subscribable*/ ) {
            if ( !b/*ko*/.isSubscribable( b/*subscribable*/ ) )throw "Only subscribable things can act as dependencies";
            
            if ( a/*_frames*/.length>0 ){
              var c/*topFrame*/ = a/*_frames*/[a/*_frames*/.length-1];
              
              if ( b/*ko*/.utils.arrayIndexOf( c/*topFrame*/.distinctDependencies,b/*subscribable*/ ) >= 0 )return ;
              
              c/*topFrame*/.distinctDependencies.push( b/*subscribable*/ );
              
              c/*topFrame*/.callback( b/*subscribable*/ );
            };
          }
        };
      })();
      
      var o/*primitiveTypes*/ =  {
            'undefined' : true,
            'boolean' : true,
            'number' : true,
            'string' : true
          };
      
      b/*ko*/.observable = function ( e/*initialValue*/ ) {
        var b/*_latestValue*/ = e/*initialValue*/;
        
        function a/*observable*/() {
          if ( arguments.length>0 ){
            if ( ( !observable['equalityComparer'] ) || !observable['equalityComparer']( _latestValue,arguments[0] ) ){
              observable.valueWillMutate();
              
              _latestValue = arguments[0];
              
              observable.valueHasMutated();
            };
            return this;
          } else {
            ko.dependencyDetection.registerDependency( observable );
            return _latestValue;
          };
        }
        b/*ko*/.subscribable.call( a/*observable*/ );
        
        a/*observable*/.valueHasMutated = function () {
          observable["notifySubscribers"]( _latestValue );
        };
        
        a/*observable*/.valueWillMutate = function () {
          observable["notifySubscribers"]( _latestValue,"beforeChange" );
        };
        
        b/*ko*/.utils.extend( a/*observable*/,b/*ko*/.observable['fn'] );
        
        b/*ko*/.exportProperty( a/*observable*/,"valueHasMutated",a/*observable*/.valueHasMutated );
        
        b/*ko*/.exportProperty( a/*observable*/,"valueWillMutate",a/*observable*/.valueWillMutate );
        return a/*observable*/;
      };
      
      b/*ko*/.observable['fn'] =  {
        __ko_proto__ : b/*ko*/.observable,
        "equalityComparer" : function p/*valuesArePrimitiveAndEqual*/( c/*a*/,d/*b*/ ) {
          var e/*oldValueIsPrimitive*/ = ( c/*a*/ === null ) || ( typeof ( c/*a*/ ) in o/*primitiveTypes*/ );
          return e/*oldValueIsPrimitive*/?( c/*a*/ === d/*b*/ ) : false;
        }
      };
      
      b/*ko*/.isObservable = function ( a/*instance*/ ) {
        if ( ( a/*instance*/ === null ) || ( a/*instance*/ === l/*undefined*/ ) || ( a/*instance*/.__ko_proto__ === l/*undefined*/ ) )return false;
        
        if ( a/*instance*/.__ko_proto__ === b/*ko*/.observable )return true;
        return b/*ko*/.isObservable( a/*instance*/.__ko_proto__ );
      };
      
      b/*ko*/.isWriteableObservable = function ( a/*instance*/ ) {
        if ( ( typeof a/*instance*/ == "function" ) && a/*instance*/.__ko_proto__ === b/*ko*/.observable )return true;
        
        if ( ( typeof a/*instance*/ == "function" ) && ( a/*instance*/.__ko_proto__ === b/*ko*/.dependentObservable ) && ( a/*instance*/.hasWriteFunction ) )return true;
        return false;
      };
      
      b/*ko*/.exportSymbol( 'ko.observable',b/*ko*/.observable );
      
      b/*ko*/.exportSymbol( 'ko.isObservable',b/*ko*/.isObservable );
      
      b/*ko*/.exportSymbol( 'ko.isWriteableObservable',b/*ko*/.isWriteableObservable );
      
      b/*ko*/.observableArray = function ( c/*initialValues*/ ) {
        if ( arguments.length == 0 ){
          c/*initialValues*/ = [];
        };
        
        if ( ( c/*initialValues*/ !== null ) && ( c/*initialValues*/ !== l/*undefined*/ ) && !( 'length' in c/*initialValues*/ ) )throw new Error( "The argument passed when initializing an observable array must be an array, or null, or undefined." );
        
        var e/*result*/ = new b/*ko*/.observable( c/*initialValues*/ );
        
        b/*ko*/.utils.extend( e/*result*/,b/*ko*/.observableArray['fn'] );
        
        b/*ko*/.exportProperty( e/*result*/,"remove",e/*result*/.remove );
        
        b/*ko*/.exportProperty( e/*result*/,"removeAll",e/*result*/.removeAll );
        
        b/*ko*/.exportProperty( e/*result*/,"destroy",e/*result*/.destroy );
        
        b/*ko*/.exportProperty( e/*result*/,"destroyAll",e/*result*/.destroyAll );
        
        b/*ko*/.exportProperty( e/*result*/,"indexOf",e/*result*/.indexOf );
        
        b/*ko*/.exportProperty( e/*result*/,"replace",e/*result*/.replace );
        return e/*result*/;
      };
      
      b/*ko*/.observableArray['fn'] =  {
        remove : function ( b/*valueOrPredicate*/ ) {
          var c/*underlyingArray*/ = this();
          
          var d/*removedValues*/ = [];
          
          var e/*predicate*/ = typeof b/*valueOrPredicate*/ == "function"?b/*valueOrPredicate*/ : function ( a/*value*/ ) {
                return a/*value*/ === b/*valueOrPredicate*/;
              };
          
          for ( var i = 0;i<c/*underlyingArray*/.length;i ++  ){
            var f/*value*/ = c/*underlyingArray*/[i];
            
            if ( e/*predicate*/( f/*value*/ ) ){
              if ( d/*removedValues*/.length === 0 ){
                this.valueWillMutate();
              };
              
              d/*removedValues*/.push( f/*value*/ );
              
              c/*underlyingArray*/.splice( i,1 );
              
              i -- ;
            };
          };
          
          if ( d/*removedValues*/.length ){
            this.valueHasMutated();
          };
          return d/*removedValues*/;
        },
        removeAll : function ( a/*arrayOfValues*/ ) {
          if ( a/*arrayOfValues*/ === l/*undefined*/ ){
            var b/*underlyingArray*/ = this();
            
            var c/*allValues*/ = b/*underlyingArray*/.slice( 0 );
            
            this.valueWillMutate();
            
            b/*underlyingArray*/.splice( 0,b/*underlyingArray*/.length );
            
            this.valueHasMutated();
            return c/*allValues*/;
          };
          
          if ( !a/*arrayOfValues*/ )return [];
          return this.remove( function ( a/*value*/ ) {
            return b/*ko*/.utils.arrayIndexOf( a/*arrayOfValues*/,a/*value*/ ) >= 0;
          });
        },
        destroy : function ( b/*valueOrPredicate*/ ) {
          var c/*underlyingArray*/ = this();
          
          var d/*predicate*/ = typeof b/*valueOrPredicate*/ == "function"?b/*valueOrPredicate*/ : function ( a/*value*/ ) {
                return a/*value*/ === b/*valueOrPredicate*/;
              };
          
          this.valueWillMutate();
          
          for ( var i = c/*underlyingArray*/.length-1;i >= 0;i --  ){
            var e/*value*/ = c/*underlyingArray*/[i];
            
            if ( d/*predicate*/( e/*value*/ ) )c/*underlyingArray*/[i]["_destroy"] = true;
          };
          
          this.valueHasMutated();
        },
        destroyAll : function ( a/*arrayOfValues*/ ) {
          if ( a/*arrayOfValues*/ === l/*undefined*/ )return this.destroy( function () {
            return true;
          });
          
          if ( !a/*arrayOfValues*/ )return [];
          return this.destroy( function ( a/*value*/ ) {
            return b/*ko*/.utils.arrayIndexOf( a/*arrayOfValues*/,a/*value*/ ) >= 0;
          });
        },
        indexOf : function ( a/*item*/ ) {
          var b/*underlyingArray*/ = this();
          return b/*ko*/.utils.arrayIndexOf( b/*underlyingArray*/,a/*item*/ );
        },
        replace : function ( a/*oldItem*/,b/*newItem*/ ) {
          var c/*index*/ = this.indexOf( a/*oldItem*/ );
          
          if ( c/*index*/ >= 0 ){
            this.valueWillMutate();
            
            this()[c/*index*/] = b/*newItem*/;
            
            this.valueHasMutated();
          };
        }
      };
      
      b/*ko*/.utils.arrayForEach( ["pop","push","reverse","shift","sort","splice","unshift"],
      function ( b/*methodName*/ ) {
        b/*ko*/.observableArray['fn'][b/*methodName*/] = function () {
          var b/*underlyingArray*/ = this();
          
          this.valueWillMutate();
          
          var c/*methodCallResult*/ = b/*underlyingArray*/[b/*methodName*/].apply( b/*underlyingArray*/,arguments );
          
          this.valueHasMutated();
          return c/*methodCallResult*/;
        };
      });
      
      b/*ko*/.utils.arrayForEach( ["slice"],
      function ( b/*methodName*/ ) {
        b/*ko*/.observableArray['fn'][b/*methodName*/] = function () {
          var b/*underlyingArray*/ = this();
          return b/*underlyingArray*/[b/*methodName*/].apply( b/*underlyingArray*/,arguments );
        };
      });
      
      b/*ko*/.exportSymbol( 'ko.observableArray',b/*ko*/.observableArray );
      
      function q/*prepareOptions*/( a/*evaluatorFunctionOrOptions*/,b/*evaluatorFunctionTarget*/,c/*options*/ ) {
        if ( a/*evaluatorFunctionOrOptions*/ && typeof a/*evaluatorFunctionOrOptions*/ == "object" ){
          c/*options*/ = a/*evaluatorFunctionOrOptions*/;
        } else {
          c/*options*/ = c/*options*/ || {};
          
          c/*options*/["read"] = a/*evaluatorFunctionOrOptions*/ || c/*options*/["read"];
        };
        
        if ( typeof c/*options*/["read"] != "function" )throw "Pass a function that returns the value of the dependentObservable";
        return c/*options*/;
      }
      b/*ko*/.dependentObservable = function ( e/*evaluatorFunctionOrOptions*/,f/*evaluatorFunctionTarget*/,g/*options*/ ) {
        var h/*_latestValue*/,
            i/*_hasBeenEvaluated*/ = false,
            g/*options*/ = q/*prepareOptions*/( e/*evaluatorFunctionOrOptions*/,f/*evaluatorFunctionTarget*/,g/*options*/ );
        
        var a/*disposeWhenNodeIsRemoved*/ = ( typeof g/*options*/["disposeWhenNodeIsRemoved"] == "object" )?g/*options*/["disposeWhenNodeIsRemoved"] : null;
        
        var c/*disposeWhenNodeIsRemovedCallback*/ = null;
        
        if ( a/*disposeWhenNodeIsRemoved*/ ){
          c/*disposeWhenNodeIsRemovedCallback*/ = function () {
            dependentObservable.dispose();
          };
          
          b/*ko*/.utils.domNodeDisposal.addDisposeCallback( a/*disposeWhenNodeIsRemoved*/,c/*disposeWhenNodeIsRemovedCallback*/ );
          
          var c/*existingDisposeWhenFunction*/ = g/*options*/["disposeWhen"];
          
          g/*options*/["disposeWhen"] = function () {
            return ( !ko.utils.domNodeIsAttachedToDocument( disposeWhenNodeIsRemoved ) ) || ( ( typeof existingDisposeWhenFunction == "function" ) && existingDisposeWhenFunction() );
          };
        };
        
        var a/*_subscriptionsToDependencies*/ = [];
        
        function d/*disposeAllSubscriptionsToDependencies*/() {
          ko.utils.arrayForEach( _subscriptionsToDependencies,
          function ( a/*subscription*/ ) {
            a/*subscription*/.dispose();
          });
          
          _subscriptionsToDependencies = [];
        }
        var j/*evaluationTimeoutInstance*/ = null;
        
        function k/*evaluatePossiblyAsync*/() {
          var d/*throttleEvaluationTimeout*/ = a/*dependentObservable*/['throttleEvaluation'];
          
          if ( d/*throttleEvaluationTimeout*/ && d/*throttleEvaluationTimeout*/ >= 0 ){
            clearTimeout( j/*evaluationTimeoutInstance*/ );
            
            j/*evaluationTimeoutInstance*/ = setTimeout( l/*evaluateImmediate*/,d/*throttleEvaluationTimeout*/ );
          } else l/*evaluateImmediate*/();
        }
        function l/*evaluateImmediate*/() {
          if ( ( i/*_hasBeenEvaluated*/ ) && typeof g/*options*/["disposeWhen"] == "function" ){
            if ( g/*options*/["disposeWhen"]() ){
              a/*dependentObservable*/.dispose();
              return ;
            };
          };
          
          try {
            d/*disposeAllSubscriptionsToDependencies*/();
            
            b/*ko*/.dependencyDetection.begin( function ( a/*subscribable*/ ) {
              a/*_subscriptionsToDependencies*/.push( a/*subscribable*/.subscribe( k/*evaluatePossiblyAsync*/ ) );
            });
            
            var b/*valueForThis*/ = g/*options*/["owner"] || f/*evaluatorFunctionTarget*/;
            
            var c/*newValue*/ = g/*options*/["read"].call( b/*valueForThis*/ );
            
            a/*dependentObservable*/["notifySubscribers"]( h/*_latestValue*/,"beforeChange" );
            
            h/*_latestValue*/ = c/*newValue*/;
          } finally {
            b/*ko*/.dependencyDetection.end();
          };
          
          a/*dependentObservable*/["notifySubscribers"]( h/*_latestValue*/ );
          
          i/*_hasBeenEvaluated*/ = true;
        }
        function a/*dependentObservable*/() {
          if ( arguments.length>0 ){
            if ( typeof g/*options*/["write"] === "function" ){
              var b/*valueForThis*/ = g/*options*/["owner"] || f/*evaluatorFunctionTarget*/;
              
              g/*options*/["write"].apply( b/*valueForThis*/,arguments );
            } else {
              throw "Cannot write a value to a dependentObservable unless you specify a 'write' option. If you wish to read the current value, don't pass any parameters.";
            };
          } else {
            if ( !i/*_hasBeenEvaluated*/ )l/*evaluateImmediate*/();
            
            b/*ko*/.dependencyDetection.registerDependency( a/*dependentObservable*/ );
            return h/*_latestValue*/;
          };
        }
        a/*dependentObservable*/.getDependenciesCount = function () {
          return _subscriptionsToDependencies.length;
        };
        
        a/*dependentObservable*/.hasWriteFunction = typeof g/*options*/["write"] === "function";
        
        a/*dependentObservable*/.dispose = function () {
          if ( disposeWhenNodeIsRemoved )ko.utils.domNodeDisposal.removeDisposeCallback( disposeWhenNodeIsRemoved,disposeWhenNodeIsRemovedCallback );
          
          disposeAllSubscriptionsToDependencies();
        };
        
        b/*ko*/.subscribable.call( a/*dependentObservable*/ );
        
        b/*ko*/.utils.extend( a/*dependentObservable*/,b/*ko*/.dependentObservable['fn'] );
        
        if ( g/*options*/['deferEvaluation'] !== true )l/*evaluateImmediate*/();
        
        b/*ko*/.exportProperty( a/*dependentObservable*/,'dispose',a/*dependentObservable*/.dispose );
        
        b/*ko*/.exportProperty( a/*dependentObservable*/,'getDependenciesCount',a/*dependentObservable*/.getDependenciesCount );
        return a/*dependentObservable*/;
      };
      
      b/*ko*/.dependentObservable['fn'] =  {
        __ko_proto__ : b/*ko*/.dependentObservable
      };
      
      b/*ko*/.dependentObservable.__ko_proto__ = b/*ko*/.observable;
      
      b/*ko*/.exportSymbol( 'ko.dependentObservable',b/*ko*/.dependentObservable );
      
      b/*ko*/.exportSymbol( 'ko.computed',b/*ko*/.dependentObservable );
      
      ( function () {
        var d/*maxNestedObservableDepth*/ = 10;
        
        b/*ko*/.toJS = function ( c/*rootObject*/ ) {
          if ( arguments.length == 0 )throw new Error( "When calling ko.toJS, pass the object you want to convert." );
          return e/*mapJsObjectGraph*/( c/*rootObject*/,
          function ( a/*valueToMap*/ ) {
            for ( var i = 0;b/*ko*/.isObservable( a/*valueToMap*/ ) && ( i<d/*maxNestedObservableDepth*/ );i ++  ){
              a/*valueToMap*/ = a/*valueToMap*/();
            };
            return a/*valueToMap*/;
          });
        };
        
        b/*ko*/.toJSON = function ( a/*rootObject*/ ) {
          var c/*plainJavaScriptObject*/ = b/*ko*/.toJS( a/*rootObject*/ );
          return b/*ko*/.utils.stringifyJson( c/*plainJavaScriptObject*/ );
        };
        
        function e/*mapJsObjectGraph*/( c/*rootObject*/,d/*mapInputCallback*/,e/*visitedObjects*/ ) {
          e/*visitedObjects*/ = e/*visitedObjects*/ || new g/*objectLookup*/();
          
          c/*rootObject*/ = d/*mapInputCallback*/( c/*rootObject*/ );
          
          var f/*canHaveProperties*/ = ( typeof c/*rootObject*/ == "object" ) && ( c/*rootObject*/ !== null ) && ( c/*rootObject*/ !== l/*undefined*/ ) && ( !( c/*rootObject*/ instanceof Date ) );
          
          if ( !f/*canHaveProperties*/ )return c/*rootObject*/;
          
          var g/*outputProperties*/ = c/*rootObject*/ instanceof Array?[] : {};
          
          e/*visitedObjects*/.save( c/*rootObject*/,g/*outputProperties*/ );
          
          f/*visitPropertiesOrArrayEntries*/( c/*rootObject*/,
          function ( a/*indexer*/ ) {
            var b/*propertyValue*/ = d/*mapInputCallback*/( c/*rootObject*/[a/*indexer*/] );
            
            switch ( typeof b/*propertyValue*/ ) {
              case "boolean" :
              case "number" :
              case "string" :
              case "function" :
                
                g/*outputProperties*/[a/*indexer*/] = b/*propertyValue*/;
                break;
              case "object" :
              case "undefined" :
                
                var c/*previouslyMappedValue*/ = e/*visitedObjects*/.get( b/*propertyValue*/ );
                
                g/*outputProperties*/[a/*indexer*/] = ( c/*previouslyMappedValue*/ !== l/*undefined*/ )?c/*previouslyMappedValue*/ : e/*mapJsObjectGraph*/( b/*propertyValue*/,d/*mapInputCallback*/,e/*visitedObjects*/ );
                break;
                
            };
          });
          return g/*outputProperties*/;
        }
        function f/*visitPropertiesOrArrayEntries*/( d/*rootObject*/,e/*visitorCallback*/ ) {
          if ( d/*rootObject*/ instanceof Array ){
            for ( var i = 0;i<d/*rootObject*/.length;i ++  ){
              e/*visitorCallback*/( i );
            };
          } else {
            for ( var propertyName in d/*rootObject*/ ){
              e/*visitorCallback*/( propertyName );
            };
          };
        }
        function g/*objectLookup*/() {
          var a/*keys*/ = [];
          
          var b/*values*/ = [];
          
          this.save = function ( a/*key*/,c/*value*/ ) {
            var d/*existingIndex*/ = b/*ko*/.utils.arrayIndexOf( a/*keys*/,a/*key*/ );
            
            if ( d/*existingIndex*/ >= 0 )b/*values*/[d/*existingIndex*/] = c/*value*/;
             else {
              a/*keys*/.push( a/*key*/ );
              
              b/*values*/.push( c/*value*/ );
            };
          };
          
          this.get = function ( a/*key*/ ) {
            var c/*existingIndex*/ = b/*ko*/.utils.arrayIndexOf( a/*keys*/,a/*key*/ );
            return ( c/*existingIndex*/ >= 0 )?b/*values*/[c/*existingIndex*/] : l/*undefined*/;
          };
        }
      })();
      
      b/*ko*/.exportSymbol( 'ko.toJS',b/*ko*/.toJS );
      
      b/*ko*/.exportSymbol( 'ko.toJSON',b/*ko*/.toJSON );
      
      ( function () {
        var c/*hasDomDataExpandoProperty*/ = '__ko__hasDomDataOptionValue__';
        
        b/*ko*/.selectExtensions =  {
          readValue : function ( a/*element*/ ) {
            if ( a/*element*/.tagName == 'OPTION' ){
              if ( a/*element*/[c/*hasDomDataExpandoProperty*/] === true )return b/*ko*/.utils.domData.get( a/*element*/,b/*ko*/.bindingHandlers.options.optionValueDomDataKey );
              return a/*element*/.getAttribute( "value" );
            } else if ( a/*element*/.tagName == 'SELECT' )return a/*element*/.selectedIndex >= 0?b/*ko*/.selectExtensions.readValue( a/*element*/.options[a/*element*/.selectedIndex] ) : l/*undefined*/;
             else return a/*element*/.value;
          },
          writeValue : function ( c/*element*/,d/*value*/ ) {
            if ( c/*element*/.tagName == 'OPTION' ){
              switch ( typeof d/*value*/ ) {
                case "string" :
                  
                  b/*ko*/.utils.domData.set( c/*element*/,b/*ko*/.bindingHandlers.options.optionValueDomDataKey,l/*undefined*/ );
                  
                  if ( c/*hasDomDataExpandoProperty*/ in c/*element*/ ){
                    delete c/*element*/[c/*hasDomDataExpandoProperty*/];
                  };
                  
                  c/*element*/.value = d/*value*/;
                  break;
                default :
                  
                  b/*ko*/.utils.domData.set( c/*element*/,b/*ko*/.bindingHandlers.options.optionValueDomDataKey,d/*value*/ );
                  
                  c/*element*/[c/*hasDomDataExpandoProperty*/] = true;
                  
                  c/*element*/.value = typeof d/*value*/ === "number"?d/*value*/ : "";
                  break;
                  
              };
            } else if ( c/*element*/.tagName == 'SELECT' ){
              for ( var i = c/*element*/.options.length-1;i >= 0;i --  ){
                if ( b/*ko*/.selectExtensions.readValue( c/*element*/.options[i] ) == d/*value*/ ){
                  c/*element*/.selectedIndex = i;
                  break;
                };
              };
            } else {
              if ( ( d/*value*/ === null ) || ( d/*value*/ === l/*undefined*/ ) )d/*value*/ = "";
              
              c/*element*/.value = d/*value*/;
            };
          }
        };
      })();
      
      b/*ko*/.exportSymbol( 'ko.selectExtensions',b/*ko*/.selectExtensions );
      
      b/*ko*/.exportSymbol( 'ko.selectExtensions.readValue',b/*ko*/.selectExtensions.readValue );
      
      b/*ko*/.exportSymbol( 'ko.selectExtensions.writeValue',b/*ko*/.selectExtensions.writeValue );
      
      b/*ko*/.jsonExpressionRewriting = ( function () {
        var b/*restoreCapturedTokensRegex*/ = /\@ko_token_(\d+)\@/g;
        
        var c/*javaScriptAssignmentTarget*/ = /^[\_$a-z][\_$a-z0-9]*(\[.*?\])*(\.[\_$a-z][\_$a-z0-9]*(\[.*?\])*)*$/i;
        
        var e/*javaScriptReservedWords*/ = ["true","false"];
        
        function f/*restoreTokens*/( a/*string*/,b/*tokens*/ ) {
          var c/*prevValue*/ = null;
          
          while ( a/*string*/ != c/*prevValue*/ ){
            c/*prevValue*/ = a/*string*/;
            
            a/*string*/ = a/*string*/.replace( b/*restoreCapturedTokensRegex*/,
            function ( a/*match*/,b/*tokenIndex*/ ) {
              return b/*tokens*/[b/*tokenIndex*/];
            });
          };
          return a/*string*/;
        }
        function g/*isWriteableValue*/( a/*expression*/ ) {
          if ( b/*ko*/.utils.arrayIndexOf( e/*javaScriptReservedWords*/,b/*ko*/.utils.stringTrim( a/*expression*/ ).toLowerCase() ) >= 0 )return false;
          return a/*expression*/.match( c/*javaScriptAssignmentTarget*/ ) !== null;
        }
        function h/*ensureQuoted*/( a/*key*/ ) {
          var c/*trimmedKey*/ = b/*ko*/.utils.stringTrim( a/*key*/ );
          
          switch ( c/*trimmedKey*/.length && c/*trimmedKey*/.charAt( 0 ) ) {
            case "'" :
            case '"' :
              return a/*key*/;
            default :
              return "'"+c/*trimmedKey*/+"'";
              
          };
        }return  {
          bindingRewriteValidators : [],
          parseObjectLiteral : function ( e/*objectLiteralString*/ ) {
            var f/*str*/ = b/*ko*/.utils.stringTrim( e/*objectLiteralString*/ );
            
            if ( f/*str*/.length<3 )return [];
            
            if ( f/*str*/.charAt( 0 ) === "{" )f/*str*/ = f/*str*/.substring( 1,f/*str*/.length-1 );
            
            var g/*tokens*/ = [];
            
            var h/*tokenStart*/ = null,
                i/*tokenEndChar*/;
            
            for ( var position = 0;position<f/*str*/.length;position ++  ){
              var j/*c*/ = f/*str*/.charAt( position );
              
              if ( h/*tokenStart*/ === null ){
                switch ( j/*c*/ ) {
                  case '"' :
                  case "'" :
                  case "/" :
                    
                    h/*tokenStart*/ = position;
                    
                    i/*tokenEndChar*/ = j/*c*/;
                    break;
                    
                };
              } else if ( ( j/*c*/ == i/*tokenEndChar*/ ) && ( f/*str*/.charAt( position-1 ) !== "\\" ) ){
                var k/*token*/ = f/*str*/.substring( h/*tokenStart*/,position+1 );
                
                g/*tokens*/.push( k/*token*/ );
                
                var l/*replacement*/ = "@ko_token_"+( g/*tokens*/.length-1 )+"@";
                
                f/*str*/ = f/*str*/.substring( 0,h/*tokenStart*/ )+l/*replacement*/+f/*str*/.substring( position+1 );
                
                position -= ( k/*token*/.length-l/*replacement*/.length );
                
                h/*tokenStart*/ = null;
              };
            };
            
            h/*tokenStart*/ = null;
            
            i/*tokenEndChar*/ = null;
            
            var m/*tokenDepth*/ = 0,
                n/*tokenStartChar*/ = null;
            
            for ( var position = 0;position<f/*str*/.length;position ++  ){
              var j/*c*/ = f/*str*/.charAt( position );
              
              if ( h/*tokenStart*/ === null ){
                switch ( j/*c*/ ) {
                  case "{" :
                    
                    h/*tokenStart*/ = position;
                    
                    n/*tokenStartChar*/ = j/*c*/;
                    
                    i/*tokenEndChar*/ = "}";
                    break;
                  case "(" :
                    
                    h/*tokenStart*/ = position;
                    
                    n/*tokenStartChar*/ = j/*c*/;
                    
                    i/*tokenEndChar*/ = ")";
                    break;
                  case "[" :
                    
                    h/*tokenStart*/ = position;
                    
                    n/*tokenStartChar*/ = j/*c*/;
                    
                    i/*tokenEndChar*/ = "]";
                    break;
                    
                };
              };
              
              if ( j/*c*/ === n/*tokenStartChar*/ )m/*tokenDepth*/ ++ ;
               else if ( j/*c*/ === i/*tokenEndChar*/ ){
                m/*tokenDepth*/ -- ;
                if ( m/*tokenDepth*/ === 0 ){
                  var k/*token*/ = f/*str*/.substring( h/*tokenStart*/,position+1 );
                  
                  g/*tokens*/.push( k/*token*/ );
                  
                  var l/*replacement*/ = "@ko_token_"+( g/*tokens*/.length-1 )+"@";
                  
                  f/*str*/ = f/*str*/.substring( 0,h/*tokenStart*/ )+l/*replacement*/+f/*str*/.substring( position+1 );
                  
                  position -= ( k/*token*/.length-l/*replacement*/.length );
                  
                  h/*tokenStart*/ = null;
                };
              };
            };
            
            var o/*result*/ = [];
            
            var p/*keyValuePairs*/ = f/*str*/.split( "," );
            
            for ( var i = 0,j = p/*keyValuePairs*/.length;i<j;i ++  ){
              var q/*pair*/ = p/*keyValuePairs*/[i];
              
              var r/*colonPos*/ = q/*pair*/.indexOf( ":" );
              
              if ( ( r/*colonPos*/>0 ) && ( r/*colonPos*/<q/*pair*/.length-1 ) ){
                var s/*key*/ = q/*pair*/.substring( 0,r/*colonPos*/ );
                
                var t/*value*/ = q/*pair*/.substring( r/*colonPos*/+1 );
                
                o/*result*/.push(  {
                  'key' : f/*restoreTokens*/( s/*key*/,g/*tokens*/ ),
                  'value' : f/*restoreTokens*/( t/*value*/,g/*tokens*/ )
                });
              } else {
                o/*result*/.push(  {
                  'unknown' : f/*restoreTokens*/( q/*pair*/,g/*tokens*/ )
                });
              };
            };
            return o/*result*/;
          },
          insertPropertyAccessorsIntoJson : function ( a/*objectLiteralStringOrKeyValueArray*/ ) {
            var c/*keyValueArray*/ = typeof a/*objectLiteralStringOrKeyValueArray*/ === "string"?b/*ko*/.jsonExpressionRewriting.parseObjectLiteral( a/*objectLiteralStringOrKeyValueArray*/ ) : a/*objectLiteralStringOrKeyValueArray*/;
            
            var d/*resultStrings*/ = [],
                e/*propertyAccessorResultStrings*/ = [];
            
            var f/*keyValueEntry*/;
            
            for ( var i = 0;f/*keyValueEntry*/ = c/*keyValueArray*/[i];i ++  ){
              if ( d/*resultStrings*/.length>0 )d/*resultStrings*/.push( "," );
              
              if ( f/*keyValueEntry*/['key'] ){
                var g/*quotedKey*/ = h/*ensureQuoted*/( f/*keyValueEntry*/['key'] ),
                    h/*val*/ = f/*keyValueEntry*/['value'];
                
                d/*resultStrings*/.push( g/*quotedKey*/ );
                
                d/*resultStrings*/.push( ":" );
                
                d/*resultStrings*/.push( h/*val*/ );
                
                if ( g/*isWriteableValue*/( b/*ko*/.utils.stringTrim( h/*val*/ ) ) ){
                  if ( e/*propertyAccessorResultStrings*/.length>0 )e/*propertyAccessorResultStrings*/.push( ", " );
                  
                  e/*propertyAccessorResultStrings*/.push( g/*quotedKey*/+" : function(__ko_value) { "+h/*val*/+" = __ko_value; }" );
                };
              } else if ( f/*keyValueEntry*/['unknown'] ){
                d/*resultStrings*/.push( f/*keyValueEntry*/['unknown'] );
              };
            };
            
            var i/*combinedResult*/ = d/*resultStrings*/.join( "" );
            
            if ( e/*propertyAccessorResultStrings*/.length>0 ){
              var j/*allPropertyAccessors*/ = e/*propertyAccessorResultStrings*/.join( "" );
              
              i/*combinedResult*/ = i/*combinedResult*/+", '_ko_property_writers' : { "+j/*allPropertyAccessors*/+" } ";
            };
            return i/*combinedResult*/;
          },
          keyValueArrayContainsKey : function ( c/*keyValueArray*/,d/*key*/ ) {
            for ( var i = 0;i<c/*keyValueArray*/.length;i ++  ){
              if ( b/*ko*/.utils.stringTrim( c/*keyValueArray*/[i]['key'] ) == d/*key*/ )return true;
            };
            return false;
          }
        };
      })();
      
      b/*ko*/.exportSymbol( 'ko.jsonExpressionRewriting',b/*ko*/.jsonExpressionRewriting );
      
      b/*ko*/.exportSymbol( 'ko.jsonExpressionRewriting.bindingRewriteValidators',b/*ko*/.jsonExpressionRewriting.bindingRewriteValidators );
      
      b/*ko*/.exportSymbol( 'ko.jsonExpressionRewriting.parseObjectLiteral',b/*ko*/.jsonExpressionRewriting.parseObjectLiteral );
      
      b/*ko*/.exportSymbol( 'ko.jsonExpressionRewriting.insertPropertyAccessorsIntoJson',b/*ko*/.jsonExpressionRewriting.insertPropertyAccessorsIntoJson );
      
      ( function () {
        var d/*commentNodesHaveTextProperty*/ = document.createComment( "test" ).text === "<!--test-->";
        
        var e/*startCommentRegex*/ = d/*commentNodesHaveTextProperty*/?/^<!--\s*ko\s+(.*\:.*)\s*-->$/ : /^\s*ko\s+(.*\:.*)\s*$/;
        
        var f/*endCommentRegex*/ = d/*commentNodesHaveTextProperty*/?/^<!--\s*\/ko\s*-->$/ : /^\s*\/ko\s*$/;
        
        var g/*htmlTagsWithOptionallyClosingChildren*/ =  {
              'ul' : true,
              'ol' : true
            };
        
        function h/*isStartComment*/( a/*node*/ ) {
          return ( a/*node*/.nodeType == 8 ) && ( d/*commentNodesHaveTextProperty*/?a/*node*/.text : a/*node*/.nodeValue ).match( e/*startCommentRegex*/ );
        }
        function i/*isEndComment*/( a/*node*/ ) {
          return ( a/*node*/.nodeType == 8 ) && ( d/*commentNodesHaveTextProperty*/?a/*node*/.text : a/*node*/.nodeValue ).match( f/*endCommentRegex*/ );
        }
        function j/*getVirtualChildren*/( b/*startComment*/,c/*allowUnbalanced*/ ) {
          var d/*currentNode*/ = b/*startComment*/;
          
          var e/*depth*/ = 1;
          
          var f/*children*/ = [];
          
          while ( d/*currentNode*/ = d/*currentNode*/.nextSibling ){
            if ( i/*isEndComment*/( d/*currentNode*/ ) ){
              e/*depth*/ -- ;
              
              if ( e/*depth*/ === 0 )return f/*children*/;
            };
            
            f/*children*/.push( d/*currentNode*/ );
            
            if ( h/*isStartComment*/( d/*currentNode*/ ) )e/*depth*/ ++ ;
          };
          
          if ( !c/*allowUnbalanced*/ )throw new Error( "Cannot find closing comment tag to match: "+b/*startComment*/.nodeValue );
          return null;
        }
        function k/*getMatchingEndComment*/( a/*startComment*/,b/*allowUnbalanced*/ ) {
          var c/*allVirtualChildren*/ = j/*getVirtualChildren*/( a/*startComment*/,b/*allowUnbalanced*/ );
          
          if ( c/*allVirtualChildren*/ ){
            if ( c/*allVirtualChildren*/.length>0 )return c/*allVirtualChildren*/[c/*allVirtualChildren*/.length-1].nextSibling;
            return a/*startComment*/.nextSibling;
          } else return null;
        }
        function l/*nodeArrayToText*/( d/*nodeArray*/,e/*cleanNodes*/ ) {
          var f/*texts*/ = [];
          
          for ( var i = 0,j = d/*nodeArray*/.length;i<j;i ++  ){
            if ( e/*cleanNodes*/ )b/*ko*/.utils.domNodeDisposal.cleanNode( d/*nodeArray*/[i] );
            
            f/*texts*/.push( b/*ko*/.utils.outerHTML( d/*nodeArray*/[i] ) );
          };
          return String.prototype.concat.apply( "",f/*texts*/ );
        }
        function m/*getUnbalancedChildTags*/( a/*node*/ ) {
          var b/*childNode*/ = a/*node*/.firstChild,
              c/*captureRemaining*/ = null;
          
          if ( b/*childNode*/ ){
            do {
              if ( c/*captureRemaining*/ )c/*captureRemaining*/.push( b/*childNode*/ );
               else if ( h/*isStartComment*/( b/*childNode*/ ) ){
                var d/*matchingEndComment*/ = k/*getMatchingEndComment*/( b/*childNode*/,true );
                if ( d/*matchingEndComment*/ )b/*childNode*/ = d/*matchingEndComment*/;
                 else c/*captureRemaining*/ = [b/*childNode*/];
              } else if ( i/*isEndComment*/( b/*childNode*/ ) ){
                c/*captureRemaining*/ = [b/*childNode*/];
              };
            }while ( b/*childNode*/ = b/*childNode*/.nextSibling );
          };
          return c/*captureRemaining*/;
        }
        b/*ko*/.virtualElements =  {
          allowedBindings : {},
          childNodes : function ( a/*node*/ ) {
            return h/*isStartComment*/( a/*node*/ )?j/*getVirtualChildren*/( a/*node*/ ) : a/*node*/.childNodes;
          },
          emptyNode : function ( c/*node*/ ) {
            if ( !h/*isStartComment*/( c/*node*/ ) )b/*ko*/.utils.emptyDomNode( c/*node*/ );
             else {
              var d/*virtualChildren*/ = b/*ko*/.virtualElements.childNodes( c/*node*/ );
              
              for ( var i = 0,j = d/*virtualChildren*/.length;i<j;i ++  ){
                b/*ko*/.removeNode( d/*virtualChildren*/[i] );
              };
            };
          },
          setDomNodeChildren : function ( c/*node*/,d/*childNodes*/ ) {
            if ( !h/*isStartComment*/( c/*node*/ ) )b/*ko*/.utils.setDomNodeChildren( c/*node*/,d/*childNodes*/ );
             else {
              b/*ko*/.virtualElements.emptyNode( c/*node*/ );
              
              var e/*endCommentNode*/ = c/*node*/.nextSibling;
              
              for ( var i = 0,j = d/*childNodes*/.length;i<j;i ++  ){
                e/*endCommentNode*/.parentNode.insertBefore( d/*childNodes*/[i],e/*endCommentNode*/ );
              };
            };
          },
          prepend : function ( a/*containerNode*/,b/*nodeToPrepend*/ ) {
            if ( !h/*isStartComment*/( a/*containerNode*/ ) ){
              if ( a/*containerNode*/.firstChild )a/*containerNode*/.insertBefore( b/*nodeToPrepend*/,a/*containerNode*/.firstChild );
               else a/*containerNode*/.appendChild( b/*nodeToPrepend*/ );
            } else {
              a/*containerNode*/.parentNode.insertBefore( b/*nodeToPrepend*/,a/*containerNode*/.nextSibling );
            };
          },
          insertAfter : function ( a/*containerNode*/,b/*nodeToInsert*/,c/*insertAfterNode*/ ) {
            if ( !h/*isStartComment*/( a/*containerNode*/ ) ){
              if ( c/*insertAfterNode*/.nextSibling )a/*containerNode*/.insertBefore( b/*nodeToInsert*/,c/*insertAfterNode*/.nextSibling );
               else a/*containerNode*/.appendChild( b/*nodeToInsert*/ );
            } else {
              a/*containerNode*/.parentNode.insertBefore( b/*nodeToInsert*/,c/*insertAfterNode*/.nextSibling );
            };
          },
          nextSibling : function ( a/*node*/ ) {
            if ( !h/*isStartComment*/( a/*node*/ ) ){
              if ( a/*node*/.nextSibling && i/*isEndComment*/( a/*node*/.nextSibling ) )return l/*undefined*/;
              return a/*node*/.nextSibling;
            } else {
              return k/*getMatchingEndComment*/( a/*node*/ ).nextSibling;
            };
          },
          virtualNodeBindingValue : function ( a/*node*/ ) {
            var b/*regexMatch*/ = h/*isStartComment*/( a/*node*/ );
            return b/*regexMatch*/?b/*regexMatch*/[1] : null;
          },
          extractAnonymousTemplateIfVirtualElement : function ( a/*node*/ ) {
            if ( b/*ko*/.virtualElements.virtualNodeBindingValue( a/*node*/ ) ){
              var c/*virtualChildren*/ = b/*ko*/.virtualElements.childNodes( a/*node*/ );
              
              var d/*anonymousTemplateText*/ = l/*nodeArrayToText*/( c/*virtualChildren*/,true );
              
              b/*ko*/.virtualElements.emptyNode( a/*node*/ );
              
              new b/*ko*/.templateSources.anonymousTemplate( a/*node*/ ).text( d/*anonymousTemplateText*/ );
            };
          },
          normaliseVirtualElementDomStructure : function ( b/*elementVerified*/ ) {
            if ( !g/*htmlTagsWithOptionallyClosingChildren*/[b/*elementVerified*/.tagName.toLowerCase()] )return ;
            
            var c/*childNode*/ = b/*elementVerified*/.firstChild;
            
            if ( c/*childNode*/ ){
              do {
                if ( c/*childNode*/.nodeType === 1 ){
                  var d/*unbalancedTags*/ = m/*getUnbalancedChildTags*/( c/*childNode*/ );
                  
                  if ( d/*unbalancedTags*/ ){
                    var e/*nodeToInsertBefore*/ = c/*childNode*/.nextSibling;
                    
                    for ( var i = 0;i<d/*unbalancedTags*/.length;i ++  ){
                      if ( e/*nodeToInsertBefore*/ )b/*elementVerified*/.insertBefore( d/*unbalancedTags*/[i],e/*nodeToInsertBefore*/ );
                       else b/*elementVerified*/.appendChild( d/*unbalancedTags*/[i] );
                    };
                  };
                };
              }while ( c/*childNode*/ = c/*childNode*/.nextSibling );
            };
          }
        };
      })();
      
      ( function () {
        var d/*defaultBindingAttributeName*/ = "data-bind";
        
        b/*ko*/.bindingProvider = function (){};
        
        b/*ko*/.utils.extend( b/*ko*/.bindingProvider.prototype, {
          'nodeHasBindings' : function ( a/*node*/ ) {
            switch ( a/*node*/.nodeType ) {
              case 1 :
                return a/*node*/.getAttribute( d/*defaultBindingAttributeName*/ ) != null;
              case 8 :
                return b/*ko*/.virtualElements.virtualNodeBindingValue( a/*node*/ ) != null;
              default :
                return false;
                
            };
          },
          'getBindings' : function ( a/*node*/,b/*bindingContext*/ ) {
            var c/*bindingsString*/ = this['getBindingsString']( a/*node*/,b/*bindingContext*/ );
            return c/*bindingsString*/?this['parseBindingsString']( c/*bindingsString*/,b/*bindingContext*/ ) : null;
          },
          'getBindingsString' : function ( a/*node*/,c/*bindingContext*/ ) {
            switch ( a/*node*/.nodeType ) {
              case 1 :
                return a/*node*/.getAttribute( d/*defaultBindingAttributeName*/ );
              case 8 :
                return b/*ko*/.virtualElements.virtualNodeBindingValue( a/*node*/ );
              default :
                return null;
                
            };
          },
          'parseBindingsString' : function ( d/*bindingsString*/,e/*bindingContext*/ ) {
            try {
              var f/*viewModel*/ = e/*bindingContext*/['$data'];
              
              var g/*rewrittenBindings*/ = " { "+b/*ko*/.jsonExpressionRewriting.insertPropertyAccessorsIntoJson( d/*bindingsString*/ )+" } ";
              return b/*ko*/.utils.evalWithinScope( g/*rewrittenBindings*/,f/*viewModel*/ === null?k/*window*/ : f/*viewModel*/,e/*bindingContext*/ );
            } catch( ex ){
              throw new Error( "Unable to parse bindings.\nMessage: "+ex+";\nBindings value: "+d/*bindingsString*/ );
            };
          }
        });
        
        b/*ko*/.bindingProvider['instance'] = new b/*ko*/.bindingProvider();
      })();
      
      b/*ko*/.exportSymbol( 'ko.bindingProvider',b/*ko*/.bindingProvider );
      
      ( function () {
        b/*ko*/.bindingHandlers = {};
        
        b/*ko*/.bindingContext = function ( a/*dataItem*/,b/*parentBindingContext*/ ) {
          this['$data'] = a/*dataItem*/;
          
          if ( b/*parentBindingContext*/ ){
            this['$parent'] = b/*parentBindingContext*/['$data'];
            
            this['$parents'] = ( b/*parentBindingContext*/['$parents'] || [] ).slice( 0 );
            
            this['$parents'].unshift( this['$parent'] );
            
            this['$root'] = b/*parentBindingContext*/['$root'];
          } else {
            this['$parents'] = [];
            
            this['$root'] = a/*dataItem*/;
          };
        };
        
        b/*ko*/.bindingContext.prototype['createChildContext'] = function ( a/*dataItem*/ ) {
          return new b/*ko*/.bindingContext( a/*dataItem*/,this );
        };
        
        function e/*validateThatBindingIsAllowedForVirtualElements*/( c/*bindingName*/ ) {
          var d/*validator*/ = b/*ko*/.virtualElements.allowedBindings[c/*bindingName*/];
          
          if ( !d/*validator*/ )throw new Error( "The binding '"+c/*bindingName*/+"' cannot be used with virtual elements" );
        }
        function f/*applyBindingsToDescendantsInternal*/( a/*viewModel*/,c/*elementVerified*/ ) {
          var d/*currentChild*/,
              e/*nextInQueue*/ = c/*elementVerified*/.childNodes[0];
          
          while ( d/*currentChild*/ = e/*nextInQueue*/ ){
            e/*nextInQueue*/ = b/*ko*/.virtualElements.nextSibling( d/*currentChild*/ );
            
            g/*applyBindingsToNodeAndDescendantsInternal*/( a/*viewModel*/,d/*currentChild*/,false );
          };
        }
        function g/*applyBindingsToNodeAndDescendantsInternal*/( a/*viewModel*/,c/*nodeVerified*/,d/*isRootNodeForBindingContext*/ ) {
          var e/*shouldBindDescendants*/ = true;
          
          var f/*isElement*/ = ( c/*nodeVerified*/.nodeType == 1 );
          
          if ( f/*isElement*/ )b/*ko*/.virtualElements.normaliseVirtualElementDomStructure( c/*nodeVerified*/ );
          
          var g/*shouldApplyBindings*/ = ( f/*isElement*/ && d/*isRootNodeForBindingContext*/ ) || b/*ko*/.bindingProvider['instance']['nodeHasBindings']( c/*nodeVerified*/ );
          
          if ( g/*shouldApplyBindings*/ )e/*shouldBindDescendants*/ = h/*applyBindingsToNodeInternal*/( c/*nodeVerified*/,null,a/*viewModel*/,d/*isRootNodeForBindingContext*/ ).shouldBindDescendants;
          
          if ( f/*isElement*/ && e/*shouldBindDescendants*/ )f/*applyBindingsToDescendantsInternal*/( a/*viewModel*/,c/*nodeVerified*/ );
        }
        function h/*applyBindingsToNodeInternal*/( e/*node*/,f/*bindings*/,g/*viewModelOrBindingContext*/,h/*isRootNodeForBindingContext*/ ) {
          var i/*initPhase*/ = 0;
          
          b/*ko*/.virtualElements.extractAnonymousTemplateIfVirtualElement( e/*node*/ );
          
          var a/*parsedBindings*/;
          
          function j/*makeValueAccessor*/( b/*bindingKey*/ ) {
            return function () {
              return parsedBindings[bindingKey];
            };
          }
          function k/*parsedBindingsAccessor*/() {
            return parsedBindings;
          }
          var l/*bindingHandlerThatControlsDescendantBindings*/;
          
          new b/*ko*/.dependentObservable( function () {
            var e/*bindingContextInstance*/ = g/*viewModelOrBindingContext*/ && ( g/*viewModelOrBindingContext*/ instanceof b/*ko*/.bindingContext )?g/*viewModelOrBindingContext*/ : new b/*ko*/.bindingContext( b/*ko*/.utils.unwrapObservable( g/*viewModelOrBindingContext*/ ) );
            
            var f/*viewModel*/ = e/*bindingContextInstance*/['$data'];
            
            if ( h/*isRootNodeForBindingContext*/ )b/*ko*/.storedBindingContextForNode( e/*node*/,e/*bindingContextInstance*/ );
            
            var g/*evaluatedBindings*/ = ( typeof f/*bindings*/ == "function" )?f/*bindings*/() : f/*bindings*/;
            
            a/*parsedBindings*/ = g/*evaluatedBindings*/ || b/*ko*/.bindingProvider['instance']['getBindings']( e/*node*/,e/*bindingContextInstance*/ );
            
            if ( a/*parsedBindings*/ ){
              if ( i/*initPhase*/ === 0 ){
                i/*initPhase*/ = 1;
                
                for ( var bindingKey in a/*parsedBindings*/ ){
                  var h/*binding*/ = b/*ko*/.bindingHandlers[bindingKey];
                  
                  if ( h/*binding*/ && e/*node*/.nodeType === 8 )e/*validateThatBindingIsAllowedForVirtualElements*/( bindingKey );
                  
                  if ( h/*binding*/ && typeof h/*binding*/["init"] == "function" ){
                    var i/*handlerInitFn*/ = h/*binding*/["init"];
                    
                    var j/*initResult*/ = i/*handlerInitFn*/( e/*node*/,j/*makeValueAccessor*/( bindingKey ),k/*parsedBindingsAccessor*/,f/*viewModel*/,e/*bindingContextInstance*/ );
                    
                    if ( j/*initResult*/ && j/*initResult*/['controlsDescendantBindings'] ){
                      if ( l/*bindingHandlerThatControlsDescendantBindings*/ !== l/*undefined*/ )throw new Error( "Multiple bindings ("+l/*bindingHandlerThatControlsDescendantBindings*/+" and "+bindingKey+") are trying to control descendant bindings of the same element. You cannot use these bindings together on the same element." );
                      
                      l/*bindingHandlerThatControlsDescendantBindings*/ = bindingKey;
                    };
                  };
                };
                
                i/*initPhase*/ = 2;
              };
              
              if ( i/*initPhase*/ === 2 ){
                for ( var bindingKey in a/*parsedBindings*/ ){
                  var h/*binding*/ = b/*ko*/.bindingHandlers[bindingKey];
                  
                  if ( h/*binding*/ && typeof h/*binding*/["update"] == "function" ){
                    var k/*handlerUpdateFn*/ = h/*binding*/["update"];
                    
                    k/*handlerUpdateFn*/( e/*node*/,j/*makeValueAccessor*/( bindingKey ),k/*parsedBindingsAccessor*/,f/*viewModel*/,e/*bindingContextInstance*/ );
                  };
                };
              };
            };
          },null, {
            'disposeWhenNodeIsRemoved' : e/*node*/
          });
          return  {
            shouldBindDescendants : l/*bindingHandlerThatControlsDescendantBindings*/ === l/*undefined*/
          };
        }
        var i/*storedBindingContextDomDataKey*/ = "__ko_bindingContext__";
        
        b/*ko*/.storedBindingContextForNode = function ( c/*node*/,d/*bindingContext*/ ) {
          if ( arguments.length == 2 )b/*ko*/.utils.domData.set( c/*node*/,i/*storedBindingContextDomDataKey*/,d/*bindingContext*/ );
           else return b/*ko*/.utils.domData.get( c/*node*/,i/*storedBindingContextDomDataKey*/ );
        };
        
        b/*ko*/.applyBindingsToNode = function ( a/*node*/,c/*bindings*/,d/*viewModel*/ ) {
          if ( a/*node*/.nodeType === 1 )b/*ko*/.virtualElements.normaliseVirtualElementDomStructure( a/*node*/ );
          return h/*applyBindingsToNodeInternal*/( a/*node*/,c/*bindings*/,d/*viewModel*/,true );
        };
        
        b/*ko*/.applyBindingsToDescendants = function ( a/*viewModel*/,b/*rootNode*/ ) {
          if ( b/*rootNode*/.nodeType === 1 )f/*applyBindingsToDescendantsInternal*/( a/*viewModel*/,b/*rootNode*/ );
        };
        
        b/*ko*/.applyBindings = function ( b/*viewModel*/,c/*rootNode*/ ) {
          if ( c/*rootNode*/ && ( c/*rootNode*/.nodeType !== 1 ) && ( c/*rootNode*/.nodeType !== 8 ) )throw new Error( "ko.applyBindings: first parameter should be your view model; second parameter should be a DOM node" );
          
          c/*rootNode*/ = c/*rootNode*/ || k/*window*/.document.body;
          
          g/*applyBindingsToNodeAndDescendantsInternal*/( b/*viewModel*/,c/*rootNode*/,true );
        };
        
        b/*ko*/.contextFor = function ( a/*node*/ ) {
          switch ( a/*node*/.nodeType ) {
            case 1 :
            case 8 :
              
              var c/*context*/ = b/*ko*/.storedBindingContextForNode( a/*node*/ );
              
              if ( c/*context*/ )return c/*context*/;
              
              if ( a/*node*/.parentNode )return b/*ko*/.contextFor( a/*node*/.parentNode );
              break;
              
          };
          return l/*undefined*/;
        };
        
        b/*ko*/.dataFor = function ( a/*node*/ ) {
          var c/*context*/ = b/*ko*/.contextFor( a/*node*/ );
          return c/*context*/?c/*context*/['$data'] : l/*undefined*/;
        };
        
        b/*ko*/.exportSymbol( 'ko.bindingHandlers',b/*ko*/.bindingHandlers );
        
        b/*ko*/.exportSymbol( 'ko.applyBindings',b/*ko*/.applyBindings );
        
        b/*ko*/.exportSymbol( 'ko.applyBindingsToDescendants',b/*ko*/.applyBindingsToDescendants );
        
        b/*ko*/.exportSymbol( 'ko.applyBindingsToNode',b/*ko*/.applyBindingsToNode );
        
        b/*ko*/.exportSymbol( 'ko.contextFor',b/*ko*/.contextFor );
        
        b/*ko*/.exportSymbol( 'ko.dataFor',b/*ko*/.dataFor );
      })();
      
      var r/*eventHandlersWithShortcuts*/ = ['click'];
      
      b/*ko*/.utils.arrayForEach( r/*eventHandlersWithShortcuts*/,
      function ( a/*eventName*/ ) {
        b/*ko*/.bindingHandlers[a/*eventName*/] =  {
          'init' : function ( a/*element*/,c/*valueAccessor*/,d/*allBindingsAccessor*/,e/*viewModel*/ ) {
            var f/*newValueAccessor*/ = function () {
                  var a/*result*/ = {};
                  
                  a/*result*/[a/*eventName*/] = c/*valueAccessor*/();
                  return a/*result*/;
                };
            return b/*ko*/.bindingHandlers['event']['init'].call( this,a/*element*/,f/*newValueAccessor*/,d/*allBindingsAccessor*/,e/*viewModel*/ );
          }
        };
      });
      
      b/*ko*/.bindingHandlers['event'] =  {
        'init' : function ( c/*element*/,d/*valueAccessor*/,e/*allBindingsAccessor*/,f/*viewModel*/ ) {
          var g/*eventsToHandle*/ = d/*valueAccessor*/() || {};
          
          for ( var eventNameOutsideClosure in g/*eventsToHandle*/ ){
            ( function () {
              var c/*eventName*/ = eventNameOutsideClosure;
              
              if ( typeof c/*eventName*/ == "string" ){
                b/*ko*/.utils.registerEventHandler( c/*element*/,c/*eventName*/,
                function ( c/*event*/ ) {
                  var d/*handlerReturnValue*/;
                  
                  var e/*handlerFunction*/ = d/*valueAccessor*/()[c/*eventName*/];
                  
                  if ( !e/*handlerFunction*/ )return ;
                  
                  var f/*allBindings*/ = e/*allBindingsAccessor*/();
                  
                  try {
                    var g/*argsForHandler*/ = b/*ko*/.utils.makeArray( arguments );
                    
                    g/*argsForHandler*/.unshift( f/*viewModel*/ );
                    
                    d/*handlerReturnValue*/ = e/*handlerFunction*/.apply( f/*viewModel*/,g/*argsForHandler*/ );
                  } finally {
                    if ( d/*handlerReturnValue*/ !== true ){
                      if ( c/*event*/.preventDefault )c/*event*/.preventDefault();
                       else c/*event*/.returnValue = false;
                    };
                  };
                  
                  var h/*bubble*/ = f/*allBindings*/[c/*eventName*/+'Bubble'] !== false;
                  
                  if ( !h/*bubble*/ ){
                    c/*event*/.cancelBubble = true;
                    
                    if ( c/*event*/.stopPropagation )c/*event*/.stopPropagation();
                  };
                });
              };
            })();
          };
        }
      };
      
      b/*ko*/.bindingHandlers['submit'] =  {
        'init' : function ( c/*element*/,d/*valueAccessor*/,e/*allBindingsAccessor*/,f/*viewModel*/ ) {
          if ( typeof d/*valueAccessor*/() != "function" )throw new Error( "The value for a submit binding must be a function" );
          
          b/*ko*/.utils.registerEventHandler( c/*element*/,"submit",
          function ( a/*event*/ ) {
            var b/*handlerReturnValue*/;
            
            var c/*value*/ = d/*valueAccessor*/();
            
            try {
              b/*handlerReturnValue*/ = c/*value*/.call( f/*viewModel*/,c/*element*/ );
            } finally {
              if ( b/*handlerReturnValue*/ !== true ){
                if ( a/*event*/.preventDefault )a/*event*/.preventDefault();
                 else a/*event*/.returnValue = false;
              };
            };
          });
        }
      };
      
      b/*ko*/.bindingHandlers['visible'] =  {
        'update' : function ( a/*element*/,c/*valueAccessor*/ ) {
          var d/*value*/ = b/*ko*/.utils.unwrapObservable( c/*valueAccessor*/() );
          
          var e/*isCurrentlyVisible*/ = !( a/*element*/.style.display == "none" );
          
          if ( d/*value*/ && !e/*isCurrentlyVisible*/ )a/*element*/.style.display = "";
           else if ( ( !d/*value*/ ) && e/*isCurrentlyVisible*/ )a/*element*/.style.display = "none";
        }
      };
      
      b/*ko*/.bindingHandlers['enable'] =  {
        'update' : function ( a/*element*/,c/*valueAccessor*/ ) {
          var d/*value*/ = b/*ko*/.utils.unwrapObservable( c/*valueAccessor*/() );
          
          if ( d/*value*/ && a/*element*/.disabled )a/*element*/.removeAttribute( "disabled" );
           else if ( ( !d/*value*/ ) && ( !a/*element*/.disabled ) )a/*element*/.disabled = true;
        }
      };
      
      b/*ko*/.bindingHandlers['disable'] =  {
        'update' : function ( c/*element*/,b/*valueAccessor*/ ) {
          b/*ko*/.bindingHandlers['enable']['update']( c/*element*/,
          function () {
            return !ko.utils.unwrapObservable( valueAccessor() );
          });
        }
      };
      
      function s/*ensureDropdownSelectionIsConsistentWithModelValue*/( b/*element*/,c/*modelValue*/,d/*preferModelValue*/ ) {
        if ( d/*preferModelValue*/ ){
          if ( c/*modelValue*/ !== b/*ko*/.selectExtensions.readValue( b/*element*/ ) )b/*ko*/.selectExtensions.writeValue( b/*element*/,c/*modelValue*/ );
        };
        
        if ( c/*modelValue*/ !== b/*ko*/.selectExtensions.readValue( b/*element*/ ) )b/*ko*/.utils.triggerEvent( b/*element*/,"change" );
      }
      b/*ko*/.bindingHandlers['value'] =  {
        'init' : function ( c/*element*/,a/*valueAccessor*/,d/*allBindingsAccessor*/ ) {
          var e/*eventsToCatch*/ = ["change"];
          
          var f/*requestedEventsToCatch*/ = d/*allBindingsAccessor*/()["valueUpdate"];
          
          if ( f/*requestedEventsToCatch*/ ){
            if ( typeof f/*requestedEventsToCatch*/ == "string" )f/*requestedEventsToCatch*/ = [f/*requestedEventsToCatch*/];
            
            b/*ko*/.utils.arrayPushAll( e/*eventsToCatch*/,f/*requestedEventsToCatch*/ );
            
            e/*eventsToCatch*/ = b/*ko*/.utils.arrayGetDistinctValues( e/*eventsToCatch*/ );
          };
          
          b/*ko*/.utils.arrayForEach( e/*eventsToCatch*/,
          function ( f/*eventName*/ ) {
            var g/*handleEventAsynchronously*/ = false;
            
            if ( b/*ko*/.utils.stringStartsWith( f/*eventName*/,"after" ) ){
              g/*handleEventAsynchronously*/ = true;
              
              f/*eventName*/ = f/*eventName*/.substring( "after".length );
            };
            
            var e/*runEventHandler*/ = g/*handleEventAsynchronously*/?function ( b/*handler*/ ) {
                  setTimeout( b/*handler*/,0 );
                } : function ( a/*handler*/ ) {
                  a/*handler*/();
                };
            
            b/*ko*/.utils.registerEventHandler( c/*element*/,f/*eventName*/,
            function () {
              runEventHandler( function () {
                var e/*modelValue*/ = valueAccessor();
                
                var f/*elementValue*/ = ko.selectExtensions.readValue( element );
                
                if ( ko.isWriteableObservable( e/*modelValue*/ ) )e/*modelValue*/( f/*elementValue*/ );
                 else {
                  var g/*allBindings*/ = allBindingsAccessor();
                  if ( g/*allBindings*/['_ko_property_writers'] && g/*allBindings*/['_ko_property_writers']['value'] )g/*allBindings*/['_ko_property_writers']['value']( f/*elementValue*/ );
                };
              });
            });
          });
        },
        'update' : function ( b/*element*/,e/*valueAccessor*/ ) {
          var c/*newValue*/ = b/*ko*/.utils.unwrapObservable( e/*valueAccessor*/() );
          
          var f/*elementValue*/ = b/*ko*/.selectExtensions.readValue( b/*element*/ );
          
          var g/*valueHasChanged*/ = ( c/*newValue*/ != f/*elementValue*/ );
          
          if ( ( c/*newValue*/ === 0 ) && ( f/*elementValue*/ !== 0 ) && ( f/*elementValue*/ !== "0" ) )g/*valueHasChanged*/ = true;
          
          if ( g/*valueHasChanged*/ ){
            var h/*applyValueAction*/ = function () {
                  ko.selectExtensions.writeValue( element,newValue );
                };
            
            h/*applyValueAction*/();
            
            var i/*alsoApplyAsynchronously*/ = b/*element*/.tagName == "SELECT";
            
            if ( i/*alsoApplyAsynchronously*/ )setTimeout( h/*applyValueAction*/,0 );
          };
          
          if ( ( b/*element*/.tagName == "SELECT" ) && ( b/*element*/.length>0 ) )s/*ensureDropdownSelectionIsConsistentWithModelValue*/( b/*element*/,c/*newValue*/,false );
        }
      };
      
      b/*ko*/.bindingHandlers['options'] =  {
        'update' : function ( d/*element*/,e/*valueAccessor*/,f/*allBindingsAccessor*/ ) {
          if ( d/*element*/.tagName != "SELECT" )throw new Error( "options binding applies only to SELECT elements" );
          
          var g/*selectWasPreviouslyEmpty*/ = d/*element*/.length == 0;
          
          var h/*previousSelectedValues*/ = b/*ko*/.utils.arrayMap( b/*ko*/.utils.arrayFilter( d/*element*/.childNodes,
              function ( a/*node*/ ) {
                return a/*node*/.tagName && a/*node*/.tagName == "OPTION" && a/*node*/.selected;
              }),
              function ( b/*node*/ ) {
                return b/*ko*/.selectExtensions.readValue( b/*node*/ ) || b/*node*/.innerText || b/*node*/.textContent;
              });
          
          var i/*previousScrollTop*/ = d/*element*/.scrollTop;
          
          d/*element*/.scrollTop = 0;
          
          var j/*value*/ = b/*ko*/.utils.unwrapObservable( e/*valueAccessor*/() );
          
          var k/*selectedValue*/ = d/*element*/.value;
          
          while ( d/*element*/.length>0 ){
            b/*ko*/.cleanNode( d/*element*/.options[0] );
            
            d/*element*/.remove( 0 );
          };
          
          if ( j/*value*/ ){
            var l/*allBindings*/ = f/*allBindingsAccessor*/();
            
            if ( typeof j/*value*/.length != "number" )j/*value*/ = [j/*value*/];
            
            if ( l/*allBindings*/['optionsCaption'] ){
              var m/*option*/ = document.createElement( "OPTION" );
              
              b/*ko*/.utils.setHtml( m/*option*/,l/*allBindings*/['optionsCaption'] );
              
              b/*ko*/.selectExtensions.writeValue( m/*option*/,l/*undefined*/ );
              
              d/*element*/.appendChild( m/*option*/ );
            };
            
            for ( var i = 0,j = j/*value*/.length;i<j;i ++  ){
              var m/*option*/ = document.createElement( "OPTION" );
              
              var n/*optionValue*/ = typeof l/*allBindings*/['optionsValue'] == "string"?j/*value*/[i][l/*allBindings*/['optionsValue']] : j/*value*/[i];
              
              n/*optionValue*/ = b/*ko*/.utils.unwrapObservable( n/*optionValue*/ );
              
              b/*ko*/.selectExtensions.writeValue( m/*option*/,n/*optionValue*/ );
              
              var o/*optionsTextValue*/ = l/*allBindings*/['optionsText'];
              
              var p/*optionText*/;
              
              if ( typeof o/*optionsTextValue*/ == "function" )p/*optionText*/ = o/*optionsTextValue*/( j/*value*/[i] );
               else if ( typeof o/*optionsTextValue*/ == "string" )p/*optionText*/ = j/*value*/[i][o/*optionsTextValue*/];
               else p/*optionText*/ = n/*optionValue*/;
              
              if ( ( p/*optionText*/ === null ) || ( p/*optionText*/ === l/*undefined*/ ) )p/*optionText*/ = "";
              
              b/*ko*/.utils.setTextContent( m/*option*/,p/*optionText*/ );
              
              d/*element*/.appendChild( m/*option*/ );
            };
            
            var q/*newOptions*/ = d/*element*/.getElementsByTagName( "OPTION" );
            
            var r/*countSelectionsRetained*/ = 0;
            
            for ( var i = 0,j = q/*newOptions*/.length;i<j;i ++  ){
              if ( b/*ko*/.utils.arrayIndexOf( h/*previousSelectedValues*/,b/*ko*/.selectExtensions.readValue( q/*newOptions*/[i] ) ) >= 0 ){
                b/*ko*/.utils.setOptionNodeSelectionState( q/*newOptions*/[i],true );
                
                r/*countSelectionsRetained*/ ++ ;
              };
            };
            
            if ( i/*previousScrollTop*/ )d/*element*/.scrollTop = i/*previousScrollTop*/;
            
            if ( g/*selectWasPreviouslyEmpty*/ && ( 'value' in l/*allBindings*/ ) ){
              s/*ensureDropdownSelectionIsConsistentWithModelValue*/( d/*element*/,b/*ko*/.utils.unwrapObservable( l/*allBindings*/['value'] ),true );
            };
          };
        }
      };
      
      b/*ko*/.bindingHandlers['options'].optionValueDomDataKey = '__ko.optionValueDomData__';
      
      b/*ko*/.bindingHandlers['selectedOptions'] =  {
        getSelectedValuesFromSelectNode : function ( b/*selectNode*/ ) {
          var c/*result*/ = [];
          
          var d/*nodes*/ = b/*selectNode*/.childNodes;
          
          for ( var i = 0,j = d/*nodes*/.length;i<j;i ++  ){
            var e/*node*/ = d/*nodes*/[i];
            
            if ( ( e/*node*/.tagName == "OPTION" ) && e/*node*/.selected )c/*result*/.push( b/*ko*/.selectExtensions.readValue( e/*node*/ ) );
          };
          return c/*result*/;
        },
        'init' : function ( b/*element*/,c/*valueAccessor*/,d/*allBindingsAccessor*/ ) {
          b/*ko*/.utils.registerEventHandler( b/*element*/,"change",
          function () {
            var b/*value*/ = c/*valueAccessor*/();
            
            if ( b/*ko*/.isWriteableObservable( b/*value*/ ) )b/*value*/( b/*ko*/.bindingHandlers['selectedOptions'].getSelectedValuesFromSelectNode( this ) );
             else {
              var c/*allBindings*/ = d/*allBindingsAccessor*/();
              if ( c/*allBindings*/['_ko_property_writers'] && c/*allBindings*/['_ko_property_writers']['value'] )c/*allBindings*/['_ko_property_writers']['value']( b/*ko*/.bindingHandlers['selectedOptions'].getSelectedValuesFromSelectNode( this ) );
            };
          });
        },
        'update' : function ( c/*element*/,d/*valueAccessor*/ ) {
          if ( c/*element*/.tagName != "SELECT" )throw new Error( "values binding applies only to SELECT elements" );
          
          var e/*newValue*/ = b/*ko*/.utils.unwrapObservable( d/*valueAccessor*/() );
          
          if ( e/*newValue*/ && typeof e/*newValue*/.length == "number" ){
            var f/*nodes*/ = c/*element*/.childNodes;
            
            for ( var i = 0,j = f/*nodes*/.length;i<j;i ++  ){
              var g/*node*/ = f/*nodes*/[i];
              
              if ( g/*node*/.tagName == "OPTION" )b/*ko*/.utils.setOptionNodeSelectionState( g/*node*/,b/*ko*/.utils.arrayIndexOf( e/*newValue*/,b/*ko*/.selectExtensions.readValue( g/*node*/ ) ) >= 0 );
            };
          };
        }
      };
      
      b/*ko*/.bindingHandlers['text'] =  {
        'update' : function ( b/*element*/,c/*valueAccessor*/ ) {
          b/*ko*/.utils.setTextContent( b/*element*/,c/*valueAccessor*/() );
        }
      };
      
      b/*ko*/.bindingHandlers['html'] =  {
        'init' : function () {
          return  {
            'controlsDescendantBindings' : true
          };
        },
        'update' : function ( b/*element*/,c/*valueAccessor*/ ) {
          var d/*value*/ = b/*ko*/.utils.unwrapObservable( c/*valueAccessor*/() );
          
          b/*ko*/.utils.setHtml( b/*element*/,d/*value*/ );
        }
      };
      
      b/*ko*/.bindingHandlers['css'] =  {
        'update' : function ( c/*element*/,d/*valueAccessor*/ ) {
          var e/*value*/ = b/*ko*/.utils.unwrapObservable( d/*valueAccessor*/() || {} );
          
          for ( var className in e/*value*/ ){
            if ( typeof className == "string" ){
              var f/*shouldHaveClass*/ = b/*ko*/.utils.unwrapObservable( e/*value*/[className] );
              
              b/*ko*/.utils.toggleDomNodeCssClass( c/*element*/,className,f/*shouldHaveClass*/ );
            };
          };
        }
      };
      
      b/*ko*/.bindingHandlers['style'] =  {
        'update' : function ( c/*element*/,d/*valueAccessor*/ ) {
          var e/*value*/ = b/*ko*/.utils.unwrapObservable( d/*valueAccessor*/() || {} );
          
          for ( var styleName in e/*value*/ ){
            if ( typeof styleName == "string" ){
              var f/*styleValue*/ = b/*ko*/.utils.unwrapObservable( e/*value*/[styleName] );
              
              c/*element*/.style[styleName] = f/*styleValue*/ || "";
            };
          };
        }
      };
      
      b/*ko*/.bindingHandlers['uniqueName'] =  {
        'init' : function ( c/*element*/,d/*valueAccessor*/ ) {
          if ( d/*valueAccessor*/() ){
            c/*element*/.name = "ko_unique_"+(  ++ b/*ko*/.bindingHandlers['uniqueName'].currentIndex );
            
            if ( b/*ko*/.utils.isIe6 || b/*ko*/.utils.isIe7 )c/*element*/.mergeAttributes( document.createElement( "<input name='"+c/*element*/.name+"'/>" ),false );
          };
        }
      };
      
      b/*ko*/.bindingHandlers['uniqueName'].currentIndex = 0;
      
      b/*ko*/.bindingHandlers['checked'] =  {
        'init' : function ( c/*element*/,d/*valueAccessor*/,e/*allBindingsAccessor*/ ) {
          var f/*updateHandler*/ = function () {
                var c/*valueToWrite*/;
                
                if ( c/*element*/.type == "checkbox" ){
                  c/*valueToWrite*/ = c/*element*/.checked;
                } else if ( ( c/*element*/.type == "radio" ) && ( c/*element*/.checked ) ){
                  c/*valueToWrite*/ = c/*element*/.value;
                } else {
                  return ;
                };
                
                var d/*modelValue*/ = d/*valueAccessor*/();
                
                if ( ( c/*element*/.type == "checkbox" ) && ( b/*ko*/.utils.unwrapObservable( d/*modelValue*/ ) instanceof Array ) ){
                  var e/*existingEntryIndex*/ = b/*ko*/.utils.arrayIndexOf( b/*ko*/.utils.unwrapObservable( d/*modelValue*/ ),c/*element*/.value );
                  
                  if ( c/*element*/.checked && ( e/*existingEntryIndex*/<0 ) )d/*modelValue*/.push( c/*element*/.value );
                   else if ( ( !c/*element*/.checked ) && ( e/*existingEntryIndex*/ >= 0 ) )d/*modelValue*/.splice( e/*existingEntryIndex*/,1 );
                } else if ( b/*ko*/.isWriteableObservable( d/*modelValue*/ ) ){
                  if ( d/*modelValue*/() !== c/*valueToWrite*/ ){
                    d/*modelValue*/( c/*valueToWrite*/ );
                  };
                } else {
                  var f/*allBindings*/ = e/*allBindingsAccessor*/();
                  if ( f/*allBindings*/['_ko_property_writers'] && f/*allBindings*/['_ko_property_writers']['checked'] ){
                    f/*allBindings*/['_ko_property_writers']['checked']( c/*valueToWrite*/ );
                  };
                };
              };
          
          b/*ko*/.utils.registerEventHandler( c/*element*/,"click",f/*updateHandler*/ );
          
          if ( ( c/*element*/.type == "radio" ) && !c/*element*/.name )b/*ko*/.bindingHandlers['uniqueName']['init']( c/*element*/,
          function () {
            return true;
          });
        },
        'update' : function ( c/*element*/,d/*valueAccessor*/ ) {
          var e/*value*/ = b/*ko*/.utils.unwrapObservable( d/*valueAccessor*/() );
          
          if ( c/*element*/.type == "checkbox" ){
            if ( e/*value*/ instanceof Array ){
              c/*element*/.checked = b/*ko*/.utils.arrayIndexOf( e/*value*/,c/*element*/.value ) >= 0;
            } else {
              c/*element*/.checked = e/*value*/;
            };
          } else if ( c/*element*/.type == "radio" ){
            c/*element*/.checked = ( c/*element*/.value == e/*value*/ );
          };
        }
      };
      
      b/*ko*/.bindingHandlers['attr'] =  {
        'update' : function ( c/*element*/,d/*valueAccessor*/,e/*allBindingsAccessor*/ ) {
          var f/*value*/ = b/*ko*/.utils.unwrapObservable( d/*valueAccessor*/() ) || {};
          
          for ( var attrName in f/*value*/ ){
            if ( typeof attrName == "string" ){
              var g/*attrValue*/ = b/*ko*/.utils.unwrapObservable( f/*value*/[attrName] );
              
              if ( ( g/*attrValue*/ === false ) || ( g/*attrValue*/ === null ) || ( g/*attrValue*/ === l/*undefined*/ ) )c/*element*/.removeAttribute( attrName );
               else c/*element*/.setAttribute( attrName,g/*attrValue*/.toString() );
            };
          };
        }
      };
      
      b/*ko*/.bindingHandlers['hasfocus'] =  {
        'init' : function ( b/*element*/,c/*valueAccessor*/,d/*allBindingsAccessor*/ ) {
          var a/*writeValue*/ = function ( b/*valueToWrite*/ ) {
                var c/*modelValue*/ = c/*valueAccessor*/();
                
                if ( b/*valueToWrite*/ == b/*ko*/.utils.unwrapObservable( c/*modelValue*/ ) )return ;
                
                if ( b/*ko*/.isWriteableObservable( c/*modelValue*/ ) )c/*modelValue*/( b/*valueToWrite*/ );
                 else {
                  var d/*allBindings*/ = d/*allBindingsAccessor*/();
                  if ( d/*allBindings*/['_ko_property_writers'] && d/*allBindings*/['_ko_property_writers']['hasfocus'] ){
                    d/*allBindings*/['_ko_property_writers']['hasfocus']( b/*valueToWrite*/ );
                  };
                };
              };
          
          b/*ko*/.utils.registerEventHandler( b/*element*/,"focus",
          function () {
            writeValue( true );
          });
          
          b/*ko*/.utils.registerEventHandler( b/*element*/,"focusin",
          function () {
            writeValue( true );
          });
          
          b/*ko*/.utils.registerEventHandler( b/*element*/,"blur",
          function () {
            writeValue( false );
          });
          
          b/*ko*/.utils.registerEventHandler( b/*element*/,"focusout",
          function () {
            writeValue( false );
          });
        },
        'update' : function ( b/*element*/,c/*valueAccessor*/ ) {
          var d/*value*/ = b/*ko*/.utils.unwrapObservable( c/*valueAccessor*/() );
          
          d/*value*/?b/*element*/.focus() : b/*element*/.blur();
          
          b/*ko*/.utils.triggerEvent( b/*element*/,d/*value*/?"focusin" : "focusout" );
        }
      };
      
      b/*ko*/.bindingHandlers['with'] =  {
        makeTemplateValueAccessor : function ( a/*valueAccessor*/ ) {
          return function () {
            var b/*value*/ = a/*valueAccessor*/();
            return  {
              'if' : b/*value*/,
              'data' : b/*value*/,
              'templateEngine' : b/*ko*/.nativeTemplateEngine.instance
            };
          };
        },
        'init' : function ( b/*element*/,c/*valueAccessor*/,d/*allBindingsAccessor*/,e/*viewModel*/,f/*bindingContext*/ ) {
          return b/*ko*/.bindingHandlers['template']['init']( b/*element*/,b/*ko*/.bindingHandlers['with'].makeTemplateValueAccessor( c/*valueAccessor*/ ) );
        },
        'update' : function ( b/*element*/,c/*valueAccessor*/,d/*allBindingsAccessor*/,e/*viewModel*/,f/*bindingContext*/ ) {
          return b/*ko*/.bindingHandlers['template']['update']( b/*element*/,b/*ko*/.bindingHandlers['with'].makeTemplateValueAccessor( c/*valueAccessor*/ ),d/*allBindingsAccessor*/,e/*viewModel*/,f/*bindingContext*/ );
        }
      };
      
      b/*ko*/.jsonExpressionRewriting.bindingRewriteValidators['with'] = false;
      
      b/*ko*/.virtualElements.allowedBindings['with'] = true;
      
      b/*ko*/.bindingHandlers['if'] =  {
        makeTemplateValueAccessor : function ( a/*valueAccessor*/ ) {
          return function () {
            return  {
              'if' : valueAccessor(),
              'templateEngine' : ko.nativeTemplateEngine.instance
            };
          };
        },
        'init' : function ( a/*element*/,c/*valueAccessor*/,d/*allBindingsAccessor*/,e/*viewModel*/,f/*bindingContext*/ ) {
          return b/*ko*/.bindingHandlers['template']['init']( a/*element*/,b/*ko*/.bindingHandlers['if'].makeTemplateValueAccessor( c/*valueAccessor*/ ) );
        },
        'update' : function ( a/*element*/,c/*valueAccessor*/,d/*allBindingsAccessor*/,e/*viewModel*/,f/*bindingContext*/ ) {
          return b/*ko*/.bindingHandlers['template']['update']( a/*element*/,b/*ko*/.bindingHandlers['if'].makeTemplateValueAccessor( c/*valueAccessor*/ ),d/*allBindingsAccessor*/,e/*viewModel*/,f/*bindingContext*/ );
        }
      };
      
      b/*ko*/.jsonExpressionRewriting.bindingRewriteValidators['if'] = false;
      
      b/*ko*/.virtualElements.allowedBindings['if'] = true;
      
      b/*ko*/.bindingHandlers['ifnot'] =  {
        makeTemplateValueAccessor : function ( a/*valueAccessor*/ ) {
          return function () {
            return  {
              'ifnot' : valueAccessor(),
              'templateEngine' : ko.nativeTemplateEngine.instance
            };
          };
        },
        'init' : function ( a/*element*/,c/*valueAccessor*/,d/*allBindingsAccessor*/,e/*viewModel*/,f/*bindingContext*/ ) {
          return b/*ko*/.bindingHandlers['template']['init']( a/*element*/,b/*ko*/.bindingHandlers['ifnot'].makeTemplateValueAccessor( c/*valueAccessor*/ ) );
        },
        'update' : function ( a/*element*/,c/*valueAccessor*/,d/*allBindingsAccessor*/,e/*viewModel*/,f/*bindingContext*/ ) {
          return b/*ko*/.bindingHandlers['template']['update']( a/*element*/,b/*ko*/.bindingHandlers['ifnot'].makeTemplateValueAccessor( c/*valueAccessor*/ ),d/*allBindingsAccessor*/,e/*viewModel*/,f/*bindingContext*/ );
        }
      };
      
      b/*ko*/.jsonExpressionRewriting.bindingRewriteValidators['ifnot'] = false;
      
      b/*ko*/.virtualElements.allowedBindings['ifnot'] = true;
      
      b/*ko*/.bindingHandlers['foreach'] =  {
        makeTemplateValueAccessor : function ( a/*valueAccessor*/ ) {
          return function () {
            var a/*bindingValue*/ = b/*ko*/.utils.unwrapObservable( a/*valueAccessor*/() );
            
            if ( ( !a/*bindingValue*/ ) || typeof a/*bindingValue*/.length == "number" )return  {
              'foreach' : a/*bindingValue*/,
              'templateEngine' : b/*ko*/.nativeTemplateEngine.instance
            };
            return  {
              'foreach' : a/*bindingValue*/['data'],
              'includeDestroyed' : a/*bindingValue*/['includeDestroyed'],
              'afterAdd' : a/*bindingValue*/['afterAdd'],
              'beforeRemove' : a/*bindingValue*/['beforeRemove'],
              'afterRender' : a/*bindingValue*/['afterRender'],
              'templateEngine' : b/*ko*/.nativeTemplateEngine.instance
            };
          };
        },
        'init' : function ( a/*element*/,c/*valueAccessor*/,d/*allBindingsAccessor*/,e/*viewModel*/,f/*bindingContext*/ ) {
          return b/*ko*/.bindingHandlers['template']['init']( a/*element*/,b/*ko*/.bindingHandlers['foreach'].makeTemplateValueAccessor( c/*valueAccessor*/ ) );
        },
        'update' : function ( a/*element*/,c/*valueAccessor*/,d/*allBindingsAccessor*/,e/*viewModel*/,f/*bindingContext*/ ) {
          return b/*ko*/.bindingHandlers['template']['update']( a/*element*/,b/*ko*/.bindingHandlers['foreach'].makeTemplateValueAccessor( c/*valueAccessor*/ ),d/*allBindingsAccessor*/,e/*viewModel*/,f/*bindingContext*/ );
        }
      };
      
      b/*ko*/.jsonExpressionRewriting.bindingRewriteValidators['foreach'] = false;
      
      b/*ko*/.virtualElements.allowedBindings['foreach'] = true;
      
      b/*ko*/.exportSymbol( 'ko.allowedVirtualElementBindings',b/*ko*/.virtualElements.allowedBindings );
      
      b/*ko*/.templateEngine = function (){};
      
      b/*ko*/.templateEngine.prototype['renderTemplateSource'] = function ( a/*templateSource*/,b/*bindingContext*/,c/*options*/ ) {
        throw "Override renderTemplateSource";
      };
      
      b/*ko*/.templateEngine.prototype['createJavaScriptEvaluatorBlock'] = function ( a/*script*/ ) {
        throw "Override createJavaScriptEvaluatorBlock";
      };
      
      b/*ko*/.templateEngine.prototype['makeTemplateSource'] = function ( c/*template*/ ) {
        if ( typeof c/*template*/ == "string" ){
          var d/*elem*/ = document.getElementById( c/*template*/ );
          
          if ( !d/*elem*/ )throw new Error( "Cannot find template with ID "+c/*template*/ );
          return new b/*ko*/.templateSources.domElement( d/*elem*/ );
        } else if ( ( c/*template*/.nodeType == 1 ) || ( c/*template*/.nodeType == 8 ) ){
          return new b/*ko*/.templateSources.anonymousTemplate( c/*template*/ );
        } else throw new Error( "Unknown template type: "+c/*template*/ );
      };
      
      b/*ko*/.templateEngine.prototype['renderTemplate'] = function ( a/*template*/,b/*bindingContext*/,c/*options*/ ) {
        var d/*templateSource*/ = this['makeTemplateSource']( a/*template*/ );
        return this['renderTemplateSource']( d/*templateSource*/,b/*bindingContext*/,c/*options*/ );
      };
      
      b/*ko*/.templateEngine.prototype['isTemplateRewritten'] = function ( a/*template*/ ) {
        if ( this['allowTemplateRewriting'] === false )return true;
        
        if ( this.knownRewrittenTemplates && this.knownRewrittenTemplates[a/*template*/] )return true;
        return this['makeTemplateSource']( a/*template*/ )['data']( "isRewritten" );
      };
      
      b/*ko*/.templateEngine.prototype['rewriteTemplate'] = function ( a/*template*/,b/*rewriterCallback*/ ) {
        var c/*templateSource*/ = this['makeTemplateSource']( a/*template*/ );
        
        var d/*rewritten*/ = b/*rewriterCallback*/( c/*templateSource*/['text']() );
        
        c/*templateSource*/['text']( d/*rewritten*/ );
        
        c/*templateSource*/['data']( "isRewritten",true );
        
        if ( typeof a/*template*/ == "string" ){
          this.knownRewrittenTemplates = this.knownRewrittenTemplates || {};
          
          this.knownRewrittenTemplates[a/*template*/] = true;
        };
      };
      
      b/*ko*/.exportSymbol( 'ko.templateEngine',b/*ko*/.templateEngine );
      
      b/*ko*/.templateRewriting = ( function () {
        var d/*memoizeDataBindingAttributeSyntaxRegex*/ = /(<[a-z]+\d*(\s+(?!data-bind=)[a-z0-9\-]+(=(\"[^\"]*\"|\'[^\']*\'))?)*\s+)data-bind=(["'])([\s\S]*?)\5/gi;
        
        var e/*memoizeVirtualContainerBindingSyntaxRegex*/ = /<!--\s*ko\b\s*([\s\S]*?)\s*-->/g;
        
        function f/*validateDataBindValuesForRewriting*/( d/*keyValueArray*/ ) {
          var e/*allValidators*/ = b/*ko*/.jsonExpressionRewriting.bindingRewriteValidators;
          
          for ( var i = 0;i<d/*keyValueArray*/.length;i ++  ){
            var f/*key*/ = d/*keyValueArray*/[i]['key'];
            
            if ( e/*allValidators*/.hasOwnProperty( f/*key*/ ) ){
              var g/*validator*/ = e/*allValidators*/[f/*key*/];
              
              if ( typeof g/*validator*/ === "function" ){
                var h/*possibleErrorMessage*/ = g/*validator*/( d/*keyValueArray*/[i]['value'] );
                
                if ( h/*possibleErrorMessage*/ )throw new Error( h/*possibleErrorMessage*/ );
              } else if ( !g/*validator*/ ){
                throw new Error( "This template engine does not support the '"+f/*key*/+"' binding within its templates" );
              };
            };
          };
        }
        function a/*constructMemoizedTagReplacement*/( a/*dataBindAttributeValue*/,c/*tagToRetain*/,d/*templateEngine*/ ) {
          var e/*dataBindKeyValueArray*/ = b/*ko*/.jsonExpressionRewriting.parseObjectLiteral( a/*dataBindAttributeValue*/ );
          
          f/*validateDataBindValuesForRewriting*/( e/*dataBindKeyValueArray*/ );
          
          var f/*rewrittenDataBindAttributeValue*/ = b/*ko*/.jsonExpressionRewriting.insertPropertyAccessorsIntoJson( e/*dataBindKeyValueArray*/ );
          
          var g/*applyBindingsToNextSiblingScript*/ = "ko.templateRewriting.applyMemoizedBindingsToNextSibling(function() { \
            return (function() { return { "+f/*rewrittenDataBindAttributeValue*/+" } })() \
        })";
          return d/*templateEngine*/['createJavaScriptEvaluatorBlock']( g/*applyBindingsToNextSiblingScript*/ )+c/*tagToRetain*/;
        }return  {
          ensureTemplateIsRewritten : function ( a/*template*/,b/*templateEngine*/ ) {
            if ( !b/*templateEngine*/['isTemplateRewritten']( a/*template*/ ) )b/*templateEngine*/['rewriteTemplate']( a/*template*/,
            function ( a/*htmlString*/ ) {
              return b/*ko*/.templateRewriting.memoizeBindingAttributeSyntax( a/*htmlString*/,b/*templateEngine*/ );
            });
          },
          memoizeBindingAttributeSyntax : function ( d/*htmlString*/,c/*templateEngine*/ ) {
            return d/*htmlString*/.replace( d/*memoizeDataBindingAttributeSyntaxRegex*/,
            function () {
              return constructMemoizedTagReplacement( arguments[6],arguments[1],templateEngine );
            }).replace( e/*memoizeVirtualContainerBindingSyntaxRegex*/,
            function () {
              return constructMemoizedTagReplacement( arguments[1],"<!-- ko -->",templateEngine );
            });
          },
          applyMemoizedBindingsToNextSibling : function ( a/*bindings*/ ) {
            return b/*ko*/.memoization.memoize( function ( a/*domNode*/,c/*bindingContext*/ ) {
              if ( a/*domNode*/.nextSibling )b/*ko*/.applyBindingsToNode( a/*domNode*/.nextSibling,a/*bindings*/,c/*bindingContext*/ );
            });
          }
        };
      })();
      
      b/*ko*/.exportSymbol( 'ko.templateRewriting',b/*ko*/.templateRewriting );
      
      b/*ko*/.exportSymbol( 'ko.templateRewriting.applyMemoizedBindingsToNextSibling',b/*ko*/.templateRewriting.applyMemoizedBindingsToNextSibling );
      
      ( function () {
        b/*ko*/.templateSources = {};
        
        b/*ko*/.templateSources.domElement = function ( a/*element*/ ) {
          this.domElement = a/*element*/;
        };
        
        b/*ko*/.templateSources.domElement.prototype['text'] = function () {
          if ( arguments.length == 0 ){
            return this.domElement.tagName.toLowerCase() == "script"?this.domElement.text : this.domElement.innerHTML;
          } else {
            var c/*valueToWrite*/ = arguments[0];
            if ( this.domElement.tagName.toLowerCase() == "script" )this.domElement.text = c/*valueToWrite*/;
             else b/*ko*/.utils.setHtml( this.domElement,c/*valueToWrite*/ );
          };
        };
        
        b/*ko*/.templateSources.domElement.prototype['data'] = function ( c/*key*/ ) {
          if ( arguments.length === 1 ){
            return b/*ko*/.utils.domData.get( this.domElement,"templateSourceData_"+c/*key*/ );
          } else {
            b/*ko*/.utils.domData.set( this.domElement,"templateSourceData_"+c/*key*/,arguments[1] );
          };
        };
        
        var c/*anonymousTemplatesDomDataKey*/ = "__ko_anon_template__";
        
        b/*ko*/.templateSources.anonymousTemplate = function ( a/*element*/ ) {
          this.domElement = a/*element*/;
        };
        
        b/*ko*/.templateSources.anonymousTemplate.prototype = new b/*ko*/.templateSources.domElement();
        
        b/*ko*/.templateSources.anonymousTemplate.prototype['text'] = function () {
          if ( arguments.length == 0 ){
            return b/*ko*/.utils.domData.get( this.domElement,c/*anonymousTemplatesDomDataKey*/ );
          } else {
            var c/*valueToWrite*/ = arguments[0];
            
            b/*ko*/.utils.domData.set( this.domElement,c/*anonymousTemplatesDomDataKey*/,c/*valueToWrite*/ );
          };
        };
        
        b/*ko*/.exportSymbol( 'ko.templateSources',b/*ko*/.templateSources );
        
        b/*ko*/.exportSymbol( 'ko.templateSources.domElement',b/*ko*/.templateSources.domElement );
        
        b/*ko*/.exportSymbol( 'ko.templateSources.anonymousTemplate',b/*ko*/.templateSources.anonymousTemplate );
      })();
      
      ( function () {
        var c/*_templateEngine*/;
        
        b/*ko*/.setTemplateEngine = function ( a/*templateEngine*/ ) {
          if ( ( a/*templateEngine*/ != l/*undefined*/ ) && !( a/*templateEngine*/ instanceof b/*ko*/.templateEngine ) )throw "templateEngine must inherit from ko.templateEngine";
          
          c/*_templateEngine*/ = a/*templateEngine*/;
        };
        
        function d/*invokeForEachNodeOrCommentInParent*/( b/*nodeArray*/,c/*parent*/,d/*action*/ ) {
          for ( var i = 0;node = b/*nodeArray*/[i];i ++  ){
            if ( node.parentNode !== c/*parent*/ )continue ;
            
            if ( ( node.nodeType === 1 ) || ( node.nodeType === 8 ) )d/*action*/( node );
          };
        }
        b/*ko*/.activateBindingsOnTemplateRenderedNodes = function ( a/*nodeArray*/,c/*bindingContext*/ ) {
          var d/*nodeArrayClone*/ = b/*ko*/.utils.arrayPushAll( [],a/*nodeArray*/ );
          
          var e/*commonParentElement*/ = ( a/*nodeArray*/.length>0 )?a/*nodeArray*/[0].parentNode : null;
          
          d/*invokeForEachNodeOrCommentInParent*/( d/*nodeArrayClone*/,e/*commonParentElement*/,
          function ( a/*node*/ ) {
            b/*ko*/.applyBindings( c/*bindingContext*/,a/*node*/ );
          });
          
          d/*invokeForEachNodeOrCommentInParent*/( d/*nodeArrayClone*/,e/*commonParentElement*/,
          function ( a/*node*/ ) {
            b/*ko*/.memoization.unmemoizeDomNodeAndDescendants( a/*node*/,[c/*bindingContext*/] );
          });
        };
        
        function e/*getFirstNodeFromPossibleArray*/( a/*nodeOrNodeArray*/ ) {
          return a/*nodeOrNodeArray*/.nodeType?a/*nodeOrNodeArray*/ : a/*nodeOrNodeArray*/.length>0?a/*nodeOrNodeArray*/[0] : null;
        }
        function f/*executeTemplate*/( c/*targetNodeOrNodeArray*/,d/*renderMode*/,e/*template*/,f/*bindingContext*/,g/*options*/ ) {
          g/*options*/ = g/*options*/ || {};
          
          var h/*templateEngineToUse*/ = ( g/*options*/['templateEngine'] || c/*_templateEngine*/ );
          
          b/*ko*/.templateRewriting.ensureTemplateIsRewritten( e/*template*/,h/*templateEngineToUse*/ );
          
          var i/*renderedNodesArray*/ = h/*templateEngineToUse*/['renderTemplate']( e/*template*/,f/*bindingContext*/,g/*options*/ );
          
          if ( ( typeof i/*renderedNodesArray*/.length != "number" ) || ( i/*renderedNodesArray*/.length>0 && typeof i/*renderedNodesArray*/[0].nodeType != "number" ) )throw "Template engine must return an array of DOM nodes";
          
          var j/*haveAddedNodesToParent*/ = false;
          
          switch ( d/*renderMode*/ ) {
            case "replaceChildren" :
              
              b/*ko*/.virtualElements.setDomNodeChildren( c/*targetNodeOrNodeArray*/,i/*renderedNodesArray*/ );
              
              j/*haveAddedNodesToParent*/ = true;
              break;
            case "replaceNode" :
              
              b/*ko*/.utils.replaceDomNodes( c/*targetNodeOrNodeArray*/,i/*renderedNodesArray*/ );
              
              j/*haveAddedNodesToParent*/ = true;
              break;
            case "ignoreTargetNode" :
              break;
            default :
              throw new Error( "Unknown renderMode: "+d/*renderMode*/ );
              
          };
          
          if ( j/*haveAddedNodesToParent*/ ){
            b/*ko*/.activateBindingsOnTemplateRenderedNodes( i/*renderedNodesArray*/,f/*bindingContext*/ );
            
            if ( g/*options*/['afterRender'] )g/*options*/['afterRender']( i/*renderedNodesArray*/,f/*bindingContext*/['$data'] );
          };
          return i/*renderedNodesArray*/;
        }
        b/*ko*/.renderTemplate = function ( c/*template*/,d/*dataOrBindingContext*/,e/*options*/,f/*targetNodeOrNodeArray*/,g/*renderMode*/ ) {
          e/*options*/ = e/*options*/ || {};
          
          if ( ( e/*options*/['templateEngine'] || c/*_templateEngine*/ ) == l/*undefined*/ )throw "Set a template engine before calling renderTemplate";
          
          g/*renderMode*/ = g/*renderMode*/ || "replaceChildren";
          
          if ( f/*targetNodeOrNodeArray*/ ){
            var a/*firstTargetNode*/ = e/*getFirstNodeFromPossibleArray*/( f/*targetNodeOrNodeArray*/ );
            
            var h/*whenToDispose*/ = function () {
                  return ( !firstTargetNode ) || !ko.utils.domNodeIsAttachedToDocument( firstTargetNode );
                };
            
            var i/*activelyDisposeWhenNodeIsRemoved*/ = ( a/*firstTargetNode*/ && g/*renderMode*/ == "replaceNode" )?a/*firstTargetNode*/.parentNode : a/*firstTargetNode*/;
            return new b/*ko*/.dependentObservable( function () {
              var c/*bindingContext*/ = ( d/*dataOrBindingContext*/ && ( d/*dataOrBindingContext*/ instanceof b/*ko*/.bindingContext ) )?d/*dataOrBindingContext*/ : new b/*ko*/.bindingContext( b/*ko*/.utils.unwrapObservable( d/*dataOrBindingContext*/ ) );
              
              var d/*templateName*/ = typeof ( c/*template*/ ) == 'function'?c/*template*/( c/*bindingContext*/['$data'] ) : c/*template*/;
              
              var e/*renderedNodesArray*/ = f/*executeTemplate*/( f/*targetNodeOrNodeArray*/,g/*renderMode*/,d/*templateName*/,c/*bindingContext*/,e/*options*/ );
              
              if ( g/*renderMode*/ == "replaceNode" ){
                f/*targetNodeOrNodeArray*/ = e/*renderedNodesArray*/;
                
                a/*firstTargetNode*/ = e/*getFirstNodeFromPossibleArray*/( f/*targetNodeOrNodeArray*/ );
              };
            },null, {
              'disposeWhen' : h/*whenToDispose*/,
              'disposeWhenNodeIsRemoved' : i/*activelyDisposeWhenNodeIsRemoved*/
            });
          } else {
            return b/*ko*/.memoization.memoize( function ( a/*domNode*/ ) {
              b/*ko*/.renderTemplate( c/*template*/,d/*dataOrBindingContext*/,e/*options*/,a/*domNode*/,"replaceNode" );
            });
          };
        };
        
        b/*ko*/.renderTemplateForEach = function ( a/*template*/,c/*arrayOrObservableArray*/,d/*options*/,e/*targetNode*/,f/*parentBindingContext*/ ) {
          var g/*createInnerBindingContext*/ = function ( a/*arrayValue*/ ) {
                return f/*parentBindingContext*/['createChildContext']( b/*ko*/.utils.unwrapObservable( a/*arrayValue*/ ) );
              };
          
          var h/*activateBindingsCallback*/ = function ( a/*arrayValue*/,c/*addedNodesArray*/ ) {
                var d/*bindingContext*/ = g/*createInnerBindingContext*/( a/*arrayValue*/ );
                
                b/*ko*/.activateBindingsOnTemplateRenderedNodes( c/*addedNodesArray*/,d/*bindingContext*/ );
                
                if ( d/*options*/['afterRender'] )d/*options*/['afterRender']( c/*addedNodesArray*/,d/*bindingContext*/['$data'] );
              };
          return new b/*ko*/.dependentObservable( function () {
            var a/*unwrappedArray*/ = b/*ko*/.utils.unwrapObservable( c/*arrayOrObservableArray*/ ) || [];
            
            if ( typeof a/*unwrappedArray*/.length == "undefined" )a/*unwrappedArray*/ = [a/*unwrappedArray*/];
            
            var c/*filteredArray*/ = b/*ko*/.utils.arrayFilter( a/*unwrappedArray*/,
                function ( a/*item*/ ) {
                  return d/*options*/['includeDestroyed'] || a/*item*/ === l/*undefined*/ || a/*item*/ === null || !b/*ko*/.utils.unwrapObservable( a/*item*/['_destroy'] );
                });
            
            b/*ko*/.utils.setDomNodeChildrenFromArrayMapping( e/*targetNode*/,c/*filteredArray*/,
            function ( a/*arrayValue*/ ) {
              var b/*templateName*/ = typeof ( a/*template*/ ) == 'function'?a/*template*/( a/*arrayValue*/ ) : a/*template*/;
              return f/*executeTemplate*/( null,"ignoreTargetNode",b/*templateName*/,g/*createInnerBindingContext*/( a/*arrayValue*/ ),d/*options*/ );
            },d/*options*/,h/*activateBindingsCallback*/);
          },null, {
            'disposeWhenNodeIsRemoved' : e/*targetNode*/
          });
        };
        
        var g/*templateSubscriptionDomDataKey*/ = '__ko__templateSubscriptionDomDataKey__';
        
        function h/*disposeOldSubscriptionAndStoreNewOne*/( a/*element*/,c/*newSubscription*/ ) {
          var d/*oldSubscription*/ = b/*ko*/.utils.domData.get( a/*element*/,g/*templateSubscriptionDomDataKey*/ );
          
          if ( d/*oldSubscription*/ && ( typeof ( d/*oldSubscription*/.dispose ) == 'function' ) )d/*oldSubscription*/.dispose();
          
          b/*ko*/.utils.domData.set( a/*element*/,g/*templateSubscriptionDomDataKey*/,c/*newSubscription*/ );
        }
        b/*ko*/.bindingHandlers['template'] =  {
          'init' : function ( a/*element*/,c/*valueAccessor*/ ) {
            var d/*bindingValue*/ = b/*ko*/.utils.unwrapObservable( c/*valueAccessor*/() );
            
            if ( ( typeof d/*bindingValue*/ != "string" ) && ( !d/*bindingValue*/.name ) && ( a/*element*/.nodeType == 1 ) ){
              new b/*ko*/.templateSources.anonymousTemplate( a/*element*/ ).text( a/*element*/.innerHTML );
              
              b/*ko*/.utils.emptyDomNode( a/*element*/ );
            };
            return  {
              'controlsDescendantBindings' : true
            };
          },
          'update' : function ( a/*element*/,c/*valueAccessor*/,d/*allBindingsAccessor*/,e/*viewModel*/,f/*bindingContext*/ ) {
            var g/*bindingValue*/ = b/*ko*/.utils.unwrapObservable( c/*valueAccessor*/() );
            
            var h/*templateName*/;
            
            var i/*shouldDisplay*/ = true;
            
            if ( typeof g/*bindingValue*/ == "string" ){
              h/*templateName*/ = g/*bindingValue*/;
            } else {
              h/*templateName*/ = g/*bindingValue*/.name;
              if ( 'if' in g/*bindingValue*/ )i/*shouldDisplay*/ = i/*shouldDisplay*/ && b/*ko*/.utils.unwrapObservable( g/*bindingValue*/['if'] );
              if ( 'ifnot' in g/*bindingValue*/ )i/*shouldDisplay*/ = i/*shouldDisplay*/ && !b/*ko*/.utils.unwrapObservable( g/*bindingValue*/['ifnot'] );
            };
            
            var j/*templateSubscription*/ = null;
            
            if ( ( typeof g/*bindingValue*/ === 'object' ) && ( 'foreach' in g/*bindingValue*/ ) ){
              var k/*dataArray*/ = ( i/*shouldDisplay*/ && g/*bindingValue*/['foreach'] ) || [];
              
              j/*templateSubscription*/ = b/*ko*/.renderTemplateForEach( h/*templateName*/ || a/*element*/,k/*dataArray*/,g/*bindingValue*/,a/*element*/,f/*bindingContext*/ );
            } else {
              if ( i/*shouldDisplay*/ ){
                var l/*innerBindingContext*/ = ( typeof g/*bindingValue*/ == 'object' ) && ( 'data' in g/*bindingValue*/ )?f/*bindingContext*/['createChildContext']( b/*ko*/.utils.unwrapObservable( g/*bindingValue*/['data'] ) ) : f/*bindingContext*/;
                
                j/*templateSubscription*/ = b/*ko*/.renderTemplate( h/*templateName*/ || a/*element*/,l/*innerBindingContext*/,g/*bindingValue*/,a/*element*/ );
              } else b/*ko*/.virtualElements.emptyNode( a/*element*/ );
            };
            
            h/*disposeOldSubscriptionAndStoreNewOne*/( a/*element*/,j/*templateSubscription*/ );
          }
        };
        
        b/*ko*/.jsonExpressionRewriting.bindingRewriteValidators['template'] = function ( a/*bindingValue*/ ) {
          var c/*parsedBindingValue*/ = b/*ko*/.jsonExpressionRewriting.parseObjectLiteral( a/*bindingValue*/ );
          
          if ( ( c/*parsedBindingValue*/.length == 1 ) && c/*parsedBindingValue*/[0]['unknown'] )return null;
          
          if ( b/*ko*/.jsonExpressionRewriting.keyValueArrayContainsKey( c/*parsedBindingValue*/,"name" ) )return null;
          return "This template engine does not support anonymous templates nested within its templates";
        };
        
        b/*ko*/.virtualElements.allowedBindings['template'] = true;
      })();
      
      b/*ko*/.exportSymbol( 'ko.setTemplateEngine',b/*ko*/.setTemplateEngine );
      
      b/*ko*/.exportSymbol( 'ko.renderTemplate',b/*ko*/.renderTemplate );
      
      ( function () {
        function d/*calculateEditDistanceMatrix*/( d/*oldArray*/,e/*newArray*/,f/*maxAllowedDistance*/ ) {
          var g/*distances*/ = [];
          
          for ( var i = 0;i <= e/*newArray*/.length;i ++  ){
            g/*distances*/[i] = [];
          };
          
          for ( var i = 0,j = Math.min( d/*oldArray*/.length,f/*maxAllowedDistance*/ );i <= j;i ++  ){
            g/*distances*/[0][i] = i;
          };
          
          for ( var i = 1,j = Math.min( e/*newArray*/.length,f/*maxAllowedDistance*/ );i <= j;i ++  ){
            g/*distances*/[i][0] = i;
          };
          
          var h/*oldIndex*/,
              i/*oldIndexMax*/ = d/*oldArray*/.length,
              j/*newIndex*/,
              k/*newIndexMax*/ = e/*newArray*/.length;
          
          var l/*distanceViaAddition*/,
              m/*distanceViaDeletion*/;
          
          for ( h/*oldIndex*/ = 1;h/*oldIndex*/ <= i/*oldIndexMax*/;h/*oldIndex*/ ++  ){
            var n/*newIndexMinForRow*/ = Math.max( 1,h/*oldIndex*/-f/*maxAllowedDistance*/ );
            
            var o/*newIndexMaxForRow*/ = Math.min( k/*newIndexMax*/,h/*oldIndex*/+f/*maxAllowedDistance*/ );
            
            for ( j/*newIndex*/ = n/*newIndexMinForRow*/;j/*newIndex*/ <= o/*newIndexMaxForRow*/;j/*newIndex*/ ++  ){
              if ( d/*oldArray*/[h/*oldIndex*/-1] === e/*newArray*/[j/*newIndex*/-1] )g/*distances*/[j/*newIndex*/][h/*oldIndex*/] = g/*distances*/[j/*newIndex*/-1][h/*oldIndex*/-1];
               else {
                var p/*northDistance*/ = g/*distances*/[j/*newIndex*/-1][h/*oldIndex*/] === l/*undefined*/?Number.MAX_VALUE : g/*distances*/[j/*newIndex*/-1][h/*oldIndex*/]+1;
                
                var q/*westDistance*/ = g/*distances*/[j/*newIndex*/][h/*oldIndex*/-1] === l/*undefined*/?Number.MAX_VALUE : g/*distances*/[j/*newIndex*/][h/*oldIndex*/-1]+1;
                
                g/*distances*/[j/*newIndex*/][h/*oldIndex*/] = Math.min( p/*northDistance*/,q/*westDistance*/ );
              };
            };
          };
          return g/*distances*/;
        }
        function e/*findEditScriptFromEditDistanceMatrix*/( a/*editDistanceMatrix*/,b/*oldArray*/,c/*newArray*/ ) {
          var d/*oldIndex*/ = b/*oldArray*/.length;
          
          var e/*newIndex*/ = c/*newArray*/.length;
          
          var f/*editScript*/ = [];
          
          var g/*maxDistance*/ = a/*editDistanceMatrix*/[e/*newIndex*/][d/*oldIndex*/];
          
          if ( g/*maxDistance*/ === l/*undefined*/ )return null;
          
          while ( ( d/*oldIndex*/>0 ) || ( e/*newIndex*/>0 ) ){
            var h/*me*/ = a/*editDistanceMatrix*/[e/*newIndex*/][d/*oldIndex*/];
            
            var i/*distanceViaAdd*/ = ( e/*newIndex*/>0 )?a/*editDistanceMatrix*/[e/*newIndex*/-1][d/*oldIndex*/] : g/*maxDistance*/+1;
            
            var j/*distanceViaDelete*/ = ( d/*oldIndex*/>0 )?a/*editDistanceMatrix*/[e/*newIndex*/][d/*oldIndex*/-1] : g/*maxDistance*/+1;
            
            var k/*distanceViaRetain*/ = ( e/*newIndex*/>0 ) && ( d/*oldIndex*/>0 )?a/*editDistanceMatrix*/[e/*newIndex*/-1][d/*oldIndex*/-1] : g/*maxDistance*/+1;
            
            if ( ( i/*distanceViaAdd*/ === l/*undefined*/ ) || ( i/*distanceViaAdd*/<h/*me*/-1 ) )i/*distanceViaAdd*/ = g/*maxDistance*/+1;
            
            if ( ( j/*distanceViaDelete*/ === l/*undefined*/ ) || ( j/*distanceViaDelete*/<h/*me*/-1 ) )j/*distanceViaDelete*/ = g/*maxDistance*/+1;
            
            if ( k/*distanceViaRetain*/<h/*me*/-1 )k/*distanceViaRetain*/ = g/*maxDistance*/+1;
            
            if ( ( i/*distanceViaAdd*/ <= j/*distanceViaDelete*/ ) && ( i/*distanceViaAdd*/<k/*distanceViaRetain*/ ) ){
              f/*editScript*/.push(  {
                status : "added",
                value : c/*newArray*/[e/*newIndex*/-1]
              });
              
              e/*newIndex*/ -- ;
            } else if ( ( j/*distanceViaDelete*/<i/*distanceViaAdd*/ ) && ( j/*distanceViaDelete*/<k/*distanceViaRetain*/ ) ){
              f/*editScript*/.push(  {
                status : "deleted",
                value : b/*oldArray*/[d/*oldIndex*/-1]
              });
              
              d/*oldIndex*/ -- ;
            } else {
              f/*editScript*/.push(  {
                status : "retained",
                value : b/*oldArray*/[d/*oldIndex*/-1]
              });
              
              e/*newIndex*/ -- ;
              
              d/*oldIndex*/ -- ;
            };
          };
          return f/*editScript*/.reverse();
        }
        b/*ko*/.utils.compareArrays = function ( c/*oldArray*/,d/*newArray*/,e/*maxEditsToConsider*/ ) {
          if ( e/*maxEditsToConsider*/ === l/*undefined*/ ){
            return b/*ko*/.utils.compareArrays( c/*oldArray*/,d/*newArray*/,1 ) || b/*ko*/.utils.compareArrays( c/*oldArray*/,d/*newArray*/,10 ) || b/*ko*/.utils.compareArrays( c/*oldArray*/,d/*newArray*/,Number.MAX_VALUE );
          } else {
            c/*oldArray*/ = c/*oldArray*/ || [];
            
            d/*newArray*/ = d/*newArray*/ || [];
            
            var f/*editDistanceMatrix*/ = d/*calculateEditDistanceMatrix*/( c/*oldArray*/,d/*newArray*/,e/*maxEditsToConsider*/ );
            return e/*findEditScriptFromEditDistanceMatrix*/( f/*editDistanceMatrix*/,c/*oldArray*/,d/*newArray*/ );
          };
        };
      })();
      
      b/*ko*/.exportSymbol( 'ko.utils.compareArrays',b/*ko*/.utils.compareArrays );
      
      ( function () {
        function e/*fixUpVirtualElements*/( b/*contiguousNodeArray*/ ) {
          if ( b/*contiguousNodeArray*/.length>2 ){
            var c/*current*/ = b/*contiguousNodeArray*/[0],
                d/*last*/ = b/*contiguousNodeArray*/[b/*contiguousNodeArray*/.length-1],
                e/*newContiguousSet*/ = [c/*current*/];
            
            while ( c/*current*/ !== d/*last*/ ){
              c/*current*/ = c/*current*/.nextSibling;
              
              if ( !c/*current*/ )return ;
              
              e/*newContiguousSet*/.push( c/*current*/ );
            };
            
            Array.prototype.splice.apply( b/*contiguousNodeArray*/,[0,b/*contiguousNodeArray*/.length].concat( e/*newContiguousSet*/ ) );
          };
        }
        function f/*mapNodeAndRefreshWhenChanged*/( c/*containerNode*/,d/*mapping*/,e/*valueToMap*/,f/*callbackAfterAddingNodes*/ ) {
          var a/*mappedNodes*/ = [];
          
          var g/*dependentObservable*/ = b/*ko*/.dependentObservable( function () {
                var a/*newMappedNodes*/ = d/*mapping*/( e/*valueToMap*/ ) || [];
                
                if ( a/*mappedNodes*/.length>0 ){
                  e/*fixUpVirtualElements*/( a/*mappedNodes*/ );
                  
                  b/*ko*/.utils.replaceDomNodes( a/*mappedNodes*/,a/*newMappedNodes*/ );
                  
                  if ( f/*callbackAfterAddingNodes*/ )f/*callbackAfterAddingNodes*/( e/*valueToMap*/,a/*newMappedNodes*/ );
                };
                
                a/*mappedNodes*/.splice( 0,a/*mappedNodes*/.length );
                
                b/*ko*/.utils.arrayPushAll( a/*mappedNodes*/,a/*newMappedNodes*/ );
              },null, {
                'disposeWhenNodeIsRemoved' : c/*containerNode*/,
                'disposeWhen' : function () {
                  return ( mappedNodes.length == 0 ) || !ko.utils.domNodeIsAttachedToDocument( mappedNodes[0] );
                }
              });
          return  {
            mappedNodes : a/*mappedNodes*/,
            dependentObservable : g/*dependentObservable*/
          };
        }
        var g/*lastMappingResultDomDataKey*/ = "setDomNodeChildrenFromArrayMapping_lastMappingResult";
        
        b/*ko*/.utils.setDomNodeChildrenFromArrayMapping = function ( e/*domNode*/,f/*array*/,g/*mapping*/,h/*options*/,i/*callbackAfterAddingNodes*/ ) {
          f/*array*/ = f/*array*/ || [];
          
          h/*options*/ = h/*options*/ || {};
          
          var j/*isFirstExecution*/ = b/*ko*/.utils.domData.get( e/*domNode*/,g/*lastMappingResultDomDataKey*/ ) === l/*undefined*/;
          
          var k/*lastMappingResult*/ = b/*ko*/.utils.domData.get( e/*domNode*/,g/*lastMappingResultDomDataKey*/ ) || [];
          
          var l/*lastArray*/ = b/*ko*/.utils.arrayMap( k/*lastMappingResult*/,
              function ( a/*x*/ ) {
                return a/*x*/.arrayEntry;
              });
          
          var m/*editScript*/ = b/*ko*/.utils.compareArrays( l/*lastArray*/,f/*array*/ );
          
          var n/*newMappingResult*/ = [];
          
          var o/*lastMappingResultIndex*/ = 0;
          
          var p/*nodesToDelete*/ = [];
          
          var q/*nodesAdded*/ = [];
          
          var r/*insertAfterNode*/ = null;
          
          for ( var i = 0,j = m/*editScript*/.length;i<j;i ++  ){
            switch ( m/*editScript*/[i].status ) {
              case "retained" :
                
                var s/*dataToRetain*/ = k/*lastMappingResult*/[o/*lastMappingResultIndex*/];
                
                n/*newMappingResult*/.push( s/*dataToRetain*/ );
                
                if ( s/*dataToRetain*/.domNodes.length>0 )r/*insertAfterNode*/ = s/*dataToRetain*/.domNodes[s/*dataToRetain*/.domNodes.length-1];
                
                o/*lastMappingResultIndex*/ ++ ;
                break;
              case "deleted" :
                
                k/*lastMappingResult*/[o/*lastMappingResultIndex*/].dependentObservable.dispose();
                
                e/*fixUpVirtualElements*/( k/*lastMappingResult*/[o/*lastMappingResultIndex*/].domNodes );
                
                b/*ko*/.utils.arrayForEach( k/*lastMappingResult*/[o/*lastMappingResultIndex*/].domNodes,
                function ( b/*node*/ ) {
                  p/*nodesToDelete*/.push(  {
                    element : b/*node*/,
                    index : i,
                    value : m/*editScript*/[i].value
                  });
                  
                  r/*insertAfterNode*/ = b/*node*/;
                });
                
                o/*lastMappingResultIndex*/ ++ ;
                break;
              case "added" :
                
                var t/*valueToMap*/ = m/*editScript*/[i].value;
                
                var u/*mapData*/ = f/*mapNodeAndRefreshWhenChanged*/( e/*domNode*/,g/*mapping*/,t/*valueToMap*/,i/*callbackAfterAddingNodes*/ );
                
                var v/*mappedNodes*/ = u/*mapData*/.mappedNodes;
                
                n/*newMappingResult*/.push(  {
                  arrayEntry : m/*editScript*/[i].value,
                  domNodes : v/*mappedNodes*/,
                  dependentObservable : u/*mapData*/.dependentObservable
                });
                
                for ( var nodeIndex = 0,nodeIndexMax = v/*mappedNodes*/.length;nodeIndex<nodeIndexMax;nodeIndex ++  ){
                  var w/*node*/ = v/*mappedNodes*/[nodeIndex];
                  
                  q/*nodesAdded*/.push(  {
                    element : w/*node*/,
                    index : i,
                    value : m/*editScript*/[i].value
                  });
                  
                  if ( r/*insertAfterNode*/ == null ){
                    b/*ko*/.virtualElements.prepend( e/*domNode*/,w/*node*/ );
                  } else {
                    b/*ko*/.virtualElements.insertAfter( e/*domNode*/,w/*node*/,r/*insertAfterNode*/ );
                  };
                  
                  r/*insertAfterNode*/ = w/*node*/;
                };
                
                if ( i/*callbackAfterAddingNodes*/ )i/*callbackAfterAddingNodes*/( t/*valueToMap*/,v/*mappedNodes*/ );
                break;
                
            };
          };
          
          b/*ko*/.utils.arrayForEach( p/*nodesToDelete*/,
          function ( a/*node*/ ) {
            b/*ko*/.cleanNode( a/*node*/.element );
          });
          
          var x/*invokedBeforeRemoveCallback*/ = false;
          
          if ( !j/*isFirstExecution*/ ){
            if ( h/*options*/['afterAdd'] ){
              for ( var i = 0;i<q/*nodesAdded*/.length;i ++  ){
                h/*options*/['afterAdd']( q/*nodesAdded*/[i].element,q/*nodesAdded*/[i].index,q/*nodesAdded*/[i].value );
              };
            };
            
            if ( h/*options*/['beforeRemove'] ){
              for ( var i = 0;i<p/*nodesToDelete*/.length;i ++  ){
                h/*options*/['beforeRemove']( p/*nodesToDelete*/[i].element,p/*nodesToDelete*/[i].index,p/*nodesToDelete*/[i].value );
              };
              
              x/*invokedBeforeRemoveCallback*/ = true;
            };
          };
          
          if ( !x/*invokedBeforeRemoveCallback*/ )b/*ko*/.utils.arrayForEach( p/*nodesToDelete*/,
          function ( a/*node*/ ) {
            b/*ko*/.removeNode( a/*node*/.element );
          });
          
          b/*ko*/.utils.domData.set( e/*domNode*/,g/*lastMappingResultDomDataKey*/,n/*newMappingResult*/ );
        };
      })();
      
      b/*ko*/.exportSymbol( 'ko.utils.setDomNodeChildrenFromArrayMapping',b/*ko*/.utils.setDomNodeChildrenFromArrayMapping );
      
      b/*ko*/.nativeTemplateEngine = function () {
        this['allowTemplateRewriting'] = false;
      };
      
      b/*ko*/.nativeTemplateEngine.prototype = new b/*ko*/.templateEngine();
      
      b/*ko*/.nativeTemplateEngine.prototype['renderTemplateSource'] = function ( a/*templateSource*/,c/*bindingContext*/,d/*options*/ ) {
        var e/*templateText*/ = a/*templateSource*/.text();
        return b/*ko*/.utils.parseHtmlFragment( e/*templateText*/ );
      };
      
      b/*ko*/.nativeTemplateEngine.instance = new b/*ko*/.nativeTemplateEngine();
      
      b/*ko*/.setTemplateEngine( b/*ko*/.nativeTemplateEngine.instance );
      
      b/*ko*/.exportSymbol( 'ko.nativeTemplateEngine',b/*ko*/.nativeTemplateEngine );
      
      ( function () {
        b/*ko*/.jqueryTmplTemplateEngine = function () {
          var a/*jQueryTmplVersion*/ = this.jQueryTmplVersion = ( function () {
                if ( ( typeof ( jQuery ) == "undefined" ) || !( jQuery['tmpl'] ) )return 0;
                
                try {
                  if ( jQuery['tmpl']['tag']['tmpl']['open'].toString().indexOf( '__' ) >= 0 ){
                    return 2;
                  };
                } catch( ex ){
                  
                };
                return 1;
              })();
          
          function d/*ensureHasReferencedJQueryTemplates*/() {
            if ( jQueryTmplVersion<2 )throw new Error( "Your version of jQuery.tmpl is too old. Please upgrade to jQuery.tmpl 1.0.0pre or later." );
          }
          function e/*executeTemplate*/( b/*compiledTemplate*/,c/*data*/,d/*jQueryTemplateOptions*/ ) {
            return jQuery['tmpl']( b/*compiledTemplate*/,c/*data*/,d/*jQueryTemplateOptions*/ );
          }
          this['renderTemplateSource'] = function ( c/*templateSource*/,d/*bindingContext*/,e/*options*/ ) {
            e/*options*/ = e/*options*/ || {};
            
            d/*ensureHasReferencedJQueryTemplates*/();
            
            var f/*precompiled*/ = c/*templateSource*/['data']( 'precompiled' );
            
            if ( !f/*precompiled*/ ){
              var g/*templateText*/ = c/*templateSource*/.text() || "";
              
              g/*templateText*/ = "{{ko_with $item.koBindingContext}}"+g/*templateText*/+"{{/ko_with}}";
              
              f/*precompiled*/ = jQuery['template']( null,g/*templateText*/ );
              
              c/*templateSource*/['data']( 'precompiled',f/*precompiled*/ );
            };
            
            var h/*data*/ = [d/*bindingContext*/['$data']];
            
            var i/*jQueryTemplateOptions*/ = jQuery['extend'](  {
                  'koBindingContext' : d/*bindingContext*/
                },e/*options*/['templateOptions'] );
            
            var j/*resultNodes*/ = e/*executeTemplate*/( f/*precompiled*/,h/*data*/,i/*jQueryTemplateOptions*/ );
            
            j/*resultNodes*/['appendTo']( document.createElement( "div" ) );
            
            jQuery['fragments'] = {};
            return j/*resultNodes*/;
          };
          
          this['createJavaScriptEvaluatorBlock'] = function ( a/*script*/ ) {
            return "{{ko_code ((function() { return "+a/*script*/+" })()) }}";
          };
          
          this['addTemplate'] = function ( b/*templateName*/,c/*templateMarkup*/ ) {
            document.write( "<script type='text/html' id='"+b/*templateName*/+"'>"+c/*templateMarkup*/+"</script>" );
          };
          
          if ( a/*jQueryTmplVersion*/>0 ){
            jQuery['tmpl']['tag']['ko_code'] =  {
              open : "__.push($1 || '');"
            };
            
            jQuery['tmpl']['tag']['ko_with'] =  {
              open : "with($1) {",
              close : "} "
            };
          };
        };
        
        b/*ko*/.jqueryTmplTemplateEngine.prototype = new b/*ko*/.templateEngine();
        
        var d/*jqueryTmplTemplateEngineInstance*/ = new b/*ko*/.jqueryTmplTemplateEngine();
        
        if ( d/*jqueryTmplTemplateEngineInstance*/.jQueryTmplVersion>0 )b/*ko*/.setTemplateEngine( d/*jqueryTmplTemplateEngineInstance*/ );
        
        b/*ko*/.exportSymbol( 'ko.jqueryTmplTemplateEngine',b/*ko*/.jqueryTmplTemplateEngine );
      })();
    })( window );
  })();
})();
