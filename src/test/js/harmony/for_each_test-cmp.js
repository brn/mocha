(function() {
  var __FILE__ = "Runtime",
      __LINE__ = 0;
  
  var b/*_mochaGlobalExport*/ = {};
  
  ( function ( g/*_mochaLocalTmp0*/,h/*_mochaLocalTmp1*/,i/*_mochaLocalTmp2*/,j/*_mochaLocalTmp3*/ ) {
    var c/*stringProto*/ = g/*_mochaLocalTmp0*/.prototype,
        d/*arrayProto*/ = h/*_mochaLocalTmp1*/.prototype,
        k/*functionProto*/ = i/*_mochaLocalTmp2*/.prototype,
        l/*dateProto*/ = j/*_mochaLocalTmp3*/.prototype;
    
    "use strict";
    
    function b/*builtinTypeError*/( b/*message*/ ) {
      try {
        throw new TypeError( b/*message*/ );
      } catch( e ){
        throw new Error( e );
      };
    };
    
    function e/*callbackCheck*/( c/*callback*/,d/*type*/ ) {
      
      a/*Runtime*/.assert( true,typeof d/*type*/ === "string","typeof type === \"string\"",44,'./mocha_runtime.js' );
      
      if ( typeof c/*callback*/ !== "function" ){
        b/*builtinTypeError*/( d/*type*/+" : first argument is not callable" );
      };
    };
    
    if ( !Object.keys ){
      Object.keys = function ( c/*obj*/ ) {
        if ( !c/*obj*/ ){
          b/*builtinTypeError*/( "Object.keys : first arguments is null or not defined." );
        };
        
        var d/*ret*/ = [],
            e/*iter*/ = -1;
        
        for ( var f/*i*/ in c/*obj*/ ){
          if ( c/*obj*/.hasOwnProperty( f/*i*/ ) ){
            d/*ret*/[ ++ e/*iter*/] = c/*obj*/[f/*i*/];
          };
        };
        return d/*ret*/;
      };
    };
    
    if ( !Object.preventExtensions ){
      Object.preventExtensions = function ( b/*o*/ ) {
        return b/*o*/;
      };
    };
    
    if ( !Object.seal ){
      Object.seal = function ( b/*o*/ ) {
        return b/*o*/;
      };
    };
    
    if ( !Object.freeze ){
      Object.freeze = function ( b/*o*/ ) {
        return b/*o*/;
      };
    };
    
    var m/*hasRealEcma5*/ = ( function () {
          var b/*ret*/;
          
          try {
            var c/*obj*/ = {};
            
            Object.defineProperty( c/*obj*/,"test", {
              configurable : false,
              writable : false,
              enumerable : false,
              value : 0
            });
            
            c/*obj*/.test = 200;
            
            b/*ret*/ = ( c/*obj*/.test === 200 )?false : true;
          } catch( e ){
            b/*ret*/ = false;
          };
          return b/*ret*/;
        })();
    
    if ( !m/*hasRealEcma5*/ ){
      Object.defineProperty = function ( b/*obj*/,c/*prop*/,d/*valobj*/ ) {
        if ( d/*valobj*/.value ){
          b/*obj*/[c/*prop*/] = d/*valobj*/.value;
        };
      };
    };
    
    if ( !c/*stringProto*/.trim ){
      c/*stringProto*/.trim = function () {
        return this.replace( c/*stringProto*/.trim.rtrim,"" );
      };
      
      c/*stringProto*/.trim.rtrim = /^\s*|\s*$/g;
    };
    
    if ( !c/*stringProto*/.repeat ){
      Object.defineProperty( c/*stringProto*/,"repeat", {
        value : function n/*value*/( b/*num*/ ) {
          return Array( b/*num*/+1 ).join( this.toString() );
        },
        configurable : true,
        enumerable : false,
        writable : true
      });
    };
    
    if ( !c/*stringProto*/.startsWith ){
      Object.defineProperty( c/*stringProto*/,"startsWith", {
        value : function n/*value*/( b/*str*/ ) {
          return !this.indexOf( b/*str*/ );
        },
        configurable : true,
        enumerable : false,
        writable : true
      });
    };
    
    if ( !c/*stringProto*/.endsWith ){
      Object.defineProperty( c/*stringProto*/,"endsWith", {
        value : function n/*value*/( b/*str*/ ) {
          var c/*t*/ = String( b/*str*/ );
          
          var d/*index*/ = this.lastIndexOf( c/*t*/ );
          return d/*index*/ >= 0 && d/*index*/ === this.length-c/*t*/.length;
        },
        configurable : true,
        enumerable : false,
        writable : true
      });
    };
    
    if ( !c/*stringProto*/.contains ){
      Object.defineProperty( c/*stringProto*/,"contains", {
        value : function n/*value*/( b/*str*/ ) {
          return this.indexOf( b/*str*/ ) !== -1;
        },
        configurable : true,
        enumerable : false,
        writable : true
      });
    };
    
    if ( !c/*stringProto*/.toArray ){
      Object.defineProperty( c/*stringProto*/,"toArray", {
        value : function n/*value*/( b/*str*/ ) {
          return this.split( "" );
        },
        configurable : true,
        enumerable : false,
        writable : true
      });
    };
    
    if ( !k/*functionProto*/.bind ){
      k/*functionProto*/.bind = function () {
        var a/*argArray*/ = d/*arrayProto*/.slice.call( arguments ),
            c/*context*/ = a/*argArray*/.shift(),
            e/*ret*/ = function () {
              var f/*args*/ = a/*argArray*/.concat( d/*arrayProto*/.slice.call( arguments ) );
              
              if ( this !== null && this !== window && this instanceof e/*ret*/ ){
                return e/*ret*/.context.apply( this,f/*args*/ );
              } else {
                return e/*ret*/.context.apply( c/*context*/,f/*args*/ );
              };
            };
        
        e/*ret*/.prototype = this.prototype;
        
        e/*ret*/.context = this;
        return e/*ret*/;
      };
    };
    
    if ( !d/*arrayProto*/.forEach ){
      d/*arrayProto*/.forEach = function ( g/*callback*/,h/*that*/ ) {
        e/*callbackCheck*/( g/*callback*/,"Array.forEach" );
        
        var i/*iter*/ = -1,
            j/*ta*/;
        
        if ( this === null ){
          b/*builtinTypeError*/( "Array.forEach : this is null or not defined" );
        };
        
        if ( h/*that*/ ){
          while ( ( j/*ta*/ = this[ ++ i/*iter*/] ) !== null && j/*ta*/ !== undefined ){
            g/*callback*/.call( h/*that*/,j/*ta*/,i/*iter*/,this );
          };
        } else {
          while ( ( j/*ta*/ = this[ ++ i/*iter*/] ) !== null && j/*ta*/ !== undefined ){
            g/*callback*/( j/*ta*/,i/*iter*/,this );
          };
        };
      };
    };
    
    if ( !d/*arrayProto*/.every ){
      d/*arrayProto*/.every = function ( b/*callback*/,c/*that*/ ) {
        e/*callbackCheck*/( b/*callback*/,"Array.every" );
        
        var d/*iter*/ = -1,
            f/*ta*/;
        
        if ( this === null ){
          b/*builtinTypeError*/( "Array.every : this is null or not defined" );
        };
        
        if ( c/*that*/ ){
          while ( ( f/*ta*/ = this[ ++ d/*iter*/] ) !== null && f/*ta*/ !== undefined ){
            if ( !( b/*callback*/.call( c/*that*/,f/*ta*/,d/*iter*/,this ) ) ){
              return false;
            };
          };
        } else {
          while ( ( f/*ta*/ = this[ ++ d/*iter*/] ) !== null && f/*ta*/ !== undefined ){
            if ( !( b/*callback*/( f/*ta*/,d/*iter*/,this ) ) ){
              return false;
            };
          };
        };
        return true;
      };
    };
    
    if ( !d/*arrayProto*/.some ){
      d/*arrayProto*/.some = function ( b/*callback*/,c/*that*/ ) {
        e/*callbackCheck*/( b/*callback*/,"Array.some" );
        
        var d/*iter*/ = -1,
            f/*ta*/;
        
        if ( this === null ){
          b/*builtinTypeError*/( "Array.some : this is null or not defined" );
        };
        
        if ( c/*that*/ ){
          while ( ( f/*ta*/ = this[ ++ d/*iter*/] ) !== null && f/*ta*/ !== undefined ){
            if ( b/*callback*/.call( c/*that*/,f/*ta*/,d/*iter*/,this ) ){
              return true;
            };
          };
        } else {
          while ( ( f/*ta*/ = this[ ++ d/*iter*/] ) !== null && f/*ta*/ !== undefined ){
            if ( b/*callback*/( f/*ta*/,d/*iter*/,this ) ){
              return true;
            };
          };
        };
        return false;
      };
    };
    
    if ( !d/*arrayProto*/.filter ){
      d/*arrayProto*/.filter = function ( b/*callback*/,c/*that*/ ) {
        e/*callbackCheck*/( b/*callback*/,"Array.filter" );
        
        var d/*len*/ = this.length,
            f/*iter*/ = -1,
            g/*ret*/ = [],
            h/*ta*/;
        
        if ( this === null ){
          b/*builtinTypeError*/( "Array.filter : this is null or not defined" );
        };
        
        if ( c/*that*/ ){
          for ( var i/*i*/ = 0,d/*len*/ = this.length;i/*i*/<d/*len*/; ++ i/*i*/ ){
            if ( ( h/*ta*/ = this[i/*i*/] ) !== null && h/*ta*/ !== undefined ){
              if ( b/*callback*/.call( c/*that*/,h/*ta*/,i/*i*/,this ) ){
                g/*ret*/[ ++ f/*iter*/] = h/*ta*/;
              };
            };
          };
        } else {
          for ( var i/*i*/ = 0,d/*len*/ = this.length;i/*i*/<d/*len*/; ++ i/*i*/ ){
            if ( ( h/*ta*/ = this[i/*i*/] ) !== null && h/*ta*/ !== undefined ){
              if ( b/*callback*/( h/*ta*/,i/*i*/,this ) ){
                g/*ret*/[ ++ f/*iter*/] = h/*ta*/;
              };
            };
          };
        };
        return g/*ret*/;
      };
    };
    
    if ( !d/*arrayProto*/.indexOf ){
      d/*arrayProto*/.indexOf = function ( c/*subject*/,d/*fromIndex*/ ) {
        var e/*iter*/ = ( d/*fromIndex*/ )?d/*fromIndex*/-1 : -1,
            f/*index*/ = -1,
            g/*ta*/;
        
        if ( this === null ){
          b/*builtinTypeError*/( "Array.indexOf : this is null or not defined." );
        };
        
        while ( ( g/*ta*/ = this[ ++ e/*iter*/] ) !== null && g/*ta*/ !== undefined ){
          if ( g/*ta*/ === c/*subject*/ ){
            f/*index*/ = e/*iter*/;
            break;
          };
        };
        return f/*index*/;
      };
    };
    
    if ( !d/*arrayProto*/.lastIndexOf ){
      d/*arrayProto*/.lastIndexOf = function ( c/*target*/,d/*fromIndex*/ ) {
        var e/*len*/ = this.length,
            f/*iter*/ = ( d/*fromIndex*/ )?d/*fromIndex*/+1 : e/*len*/,
            g/*index*/ = -1,
            h/*ta*/;
        
        if ( this === null ){
          b/*builtinTypeError*/( "Array.lastIndexOf : this is null or not defined." );
        };
        
        while ( ( h/*ta*/ = this[ -- f/*iter*/] ) !== null && h/*ta*/ !== undefined ){
          if ( h/*ta*/ === c/*target*/ ){
            g/*index*/ = f/*iter*/;
            break;
          };
        };
        return g/*index*/;
      };
    };
    
    if ( !d/*arrayProto*/.map ){
      d/*arrayProto*/.map = function ( b/*callback*/,c/*that*/ ) {
        e/*callbackCheck*/( b/*callback*/,"Array.map" );
        
        var d/*ret*/ = [],
            f/*iter*/ = -1,
            g/*len*/ = this.length,
            h/*i*/ = 0,
            i/*ta*/;
        
        if ( this === null ){
          b/*builtinTypeError*/( "Array.map : this is null or not defined." );
        };
        
        if ( c/*that*/ ){
          for ( h/*i*/;h/*i*/<g/*len*/; ++ h/*i*/ ){
            if ( ( i/*ta*/ = this[h/*i*/] ) !== null && i/*ta*/ !== undefined ){
              d/*ret*/[ ++ f/*iter*/] = b/*callback*/.call( c/*that*/,i/*ta*/,h/*i*/,this );
            };
          };
        } else {
          for ( h/*i*/;h/*i*/<g/*len*/; ++ h/*i*/ ){
            if ( ( i/*ta*/ = this[h/*i*/] ) !== null && i/*ta*/ !== undefined ){
              d/*ret*/[ ++ f/*iter*/] = b/*callback*/( i/*ta*/,h/*i*/,this );
            };
          };
        };
        return d/*ret*/;
      };
    };
    
    if ( !d/*arrayProto*/.reduce ){
      d/*arrayProto*/.reduce = function ( b/*callback*/,c/*initial*/ ) {
        e/*callbackCheck*/( b/*callback*/,"Array.reduce" );
        
        var d/*ret*/ = c/*initial*/ || this[0],
            f/*i*/ = ( c/*initial*/ )?0 : 1,
            g/*len*/ = this.length,
            h/*ta*/;
        
        if ( ( g/*len*/ === 0 || g/*len*/ === null ) && arguments.length<2 ){
          b/*builtinTypeError*/( "Array length is 0 and no second argument" );
        };
        
        for ( f/*i*/;f/*i*/<g/*len*/; ++ f/*i*/ ){
          if ( ( h/*ta*/ = this[f/*i*/] ) !== null && h/*ta*/ !== undefined ){
            d/*ret*/ = b/*callback*/( d/*ret*/,h/*ta*/,f/*i*/,this );
          };
        };
        return d/*ret*/;
      };
    };
    
    if ( !d/*arrayProto*/.reduceRight ){
      d/*arrayProto*/.reduceRight = function ( b/*callback*/,c/*initial*/ ) {
        e/*callbackCheck*/( b/*callback*/,"Array.reduceRight" );
        
        var d/*len*/ = this.length,
            f/*ret*/ = c/*initial*/ || this[d/*len*/-1],
            g/*i*/ = ( c/*initial*/ )?d/*len*/-1 : d/*len*/-2,
            h/*ta*/;
        
        if ( ( d/*len*/ === 0 || d/*len*/ === null ) && arguments.length<2 ){
          b/*builtinTypeError*/( "Array length is 0 and no second argument" );
        };
        
        for ( g/*i*/;g/*i*/>-1; -- g/*i*/ ){
          if ( ( h/*ta*/ = this[g/*i*/] ) !== null && h/*ta*/ !== undefined ){
            f/*ret*/ = b/*callback*/( f/*ret*/,h/*ta*/,g/*i*/,this );
          };
        };
        return f/*ret*/;
      };
    };
    
    if ( !l/*dateProto*/.toJSON ){
      l/*dateProto*/.toJSON = function () {
        var b/*_mochaLocalTmp4*/ = [this.getUTCMonth(),this.getUTCDate(),this.getUTCHours(),this.getMinutes(),this.getSeconds()],
            c/*month*/ = b/*_mochaLocalTmp4*/[0],
            d/*date*/ = b/*_mochaLocalTmp4*/[1],
            e/*hour*/ = b/*_mochaLocalTmp4*/[2],
            f/*minute*/ = b/*_mochaLocalTmp4*/[3],
            g/*second*/ = b/*_mochaLocalTmp4*/[4];
        return '"'+this.getUTCFullYear()+'-'+( c/*month*/>8?c/*month*/+1 : "0"+( c/*month*/+1 ) )+'-'+( d/*date*/>9?d/*date*/ : "0"+d/*date*/ )+'T'+( e/*hour*/>9?e/*hour*/ : "0"+e/*hour*/ )+':'+( f/*minute*/>9?f/*minute*/ : "0"+f/*minute*/ )+':'+( g/*second*/>9?g/*second*/ : "0"+g/*second*/ )+'.'+this.getUTCMilliseconds()+'Z"';
      };
    };
    
    if ( !Date.now ){
      Date.now = function () {
        return +new Date();
      };
    };
    
    if ( !Array.isArray ){
      Array.isArray = function ( b/*arr*/ ) {
        if ( arguments.length === 0 ){
          return false;
        };
        return ( b/*arr*/ )?Object.prototype.toString.call( b/*arr*/ ) === "[object Array]" : false;
      };
    };
  }).call( this,String,Array,Function,Date );
  
  var a/*Runtime*/ = ( function a/*Runtime*/() {
        var l/*_mochaLocalExport*/ = {};
        
        "use strict";
        
        function c/*Exception*/( d/*line*/,c/*file*/,b/*e*/ ) {
          this.toString = function () {
            return a/*Runtime*/.getErrorMessage( b/*e*/ )+" in file "+c/*file*/+" at : "+d/*line*/;
          };
        }
        var g/*fastMax*/ = Math.max;
        
        var a/*Runtime*/ =  {
              getErrorMessage : function n/*getErrorMessage*/( b/*e*/ ) {
                return ( b/*e*/.message )?b/*e*/.message : ( b/*e*/.description )?b/*e*/.description : b/*e*/.toString();
              },
              exceptionHandler : function o/*exceptionHandler*/( e/*line*/,f/*file*/,g/*e*/ ) {
                if ( b/*isStopIteration*/( g/*e*/ ) ){
                  this.throwException( g/*e*/ );
                } else {
                  this.throwException( new c/*Exception*/( e/*line*/,f/*file*/,g/*e*/ ) );
                };
              },
              throwException : function p/*throwException*/( c/*exception*/ ) {
                try {
                  throw c/*exception*/;
                } catch( e ){
                  if ( b/*isStopIteration*/( e ) ){
                    throw new Error( e );
                  } else {
                    throw new Error( this.getErrorMessage( e ) );
                  };
                };
              },
              hasProto : "__proto__" in {}
            };
        
        var d/*slice*/ = Array.prototype.slice;
        
        var f/*createUnenumProp*/ = l/*_mochaLocalExport*/.createUnenumProp = function f/*createUnenumProp*/( b/*obj*/,c/*prop*/,d/*value*/ ) {
              return Object.defineProperty( b/*obj*/,c/*prop*/, {
                configurable : true,
                enumerable : false,
                writable : true,
                value : d/*value*/
              });
            };
        
        var q/*constant*/ = l/*_mochaLocalExport*/.constant = function q/*constant*/( b/*obj*/,c/*prop*/,d/*value*/ ) {
              return Object.defineProperty( b/*obj*/,c/*prop*/, {
                configurable : false,
                enumerable : false,
                writable : false,
                value : d/*value*/
              });
            };
        
        var r/*toArray*/ = l/*_mochaLocalExport*/.toArray = function r/*toArray*/( f/*likeArray*/,g/*index*/ ) {
              return ( f/*likeArray*/ )?d/*slice*/.call( f/*likeArray*/,g/*index*/ ) : [];
            };
        
        var e/*Generator*/ = function (){};
        
        var s/*createGenerator*/ = l/*_mochaLocalExport*/.createGenerator = function s/*createGenerator*/( h/*generatorFn*/,i/*closeFn*/,j/*context*/ ) {
              var k/*ret*/ = new e/*Generator*/;
              
              f/*createUnenumProp*/( k/*ret*/,"next",h/*generatorFn*/.bind( j/*context*/,false,false ) );
              
              f/*createUnenumProp*/( k/*ret*/,"send",h/*generatorFn*/.bind( j/*context*/,true,false ) );
              
              f/*createUnenumProp*/( k/*ret*/,"close",i/*closeFn*/.bind( j/*context*/ ) );
              
              f/*createUnenumProp*/( k/*ret*/,"__nothrowNext__",h/*generatorFn*/.bind( j/*context*/,false,true ) );
              
              f/*createUnenumProp*/( k/*ret*/,"toString",
              function () {
                return "[object Generator]";
              });
              
              Object.freeze( k/*ret*/ );
              return k/*ret*/;
            };
        
        function n/*getErrorMessage*/( b/*e*/ ) {
          return ( b/*e*/.message )?b/*e*/.message : ( b/*e*/.description )?b/*e*/.description : b/*e*/.toString();
        }
        var p/*throwException*/ = l/*_mochaLocalExport*/.throwException = a/*Runtime*/.throwException.bind( a/*Runtime*/ );
        
        var o/*exceptionHandler*/ = l/*_mochaLocalExport*/.exceptionHandler = a/*Runtime*/.exceptionHandler.bind( a/*Runtime*/ );
        
        var t/*extend*/ = l/*_mochaLocalExport*/.extend = function t/*extend*/( b/*dest*/,c/*source*/ ) {
              for ( var d/*prop*/ in c/*source*/ ){
                b/*dest*/[d/*prop*/] = c/*source*/[d/*prop*/];
              };
              return b/*dest*/;
            };
        
        function u/*compareTuple*/( i/*tuple*/ ) {
          var j/*max*/ = g/*fastMax*/( i/*tuple*/.length,this.length ),
              k/*i*/ = -1;
          
          while (  ++ k/*i*/<j/*max*/ && i/*tuple*/[k/*i*/] === this[k/*i*/] ){
            
          };
          return j/*max*/ === k/*i*/;
        };
        
        function v/*tupleToArray*/() {
          return Array.prototype.slice.call( this );
        };
        
        var w/*createTuple*/ = l/*_mochaLocalExport*/.createTuple = function w/*createTuple*/( c/*obj*/,d/*size*/ ) {
              f/*createUnenumProp*/( c/*obj*/,"length",d/*size*/ );
              
              f/*createUnenumProp*/( c/*obj*/,"equal",u/*compareTuple*/ );
              
              f/*createUnenumProp*/( c/*obj*/,"toArray",v/*tupleToArray*/ );
              
              f/*createUnenumProp*/( c/*obj*/,"toString",
              function () {
                return "[object Tuple]";
              });
              return Object.freeze( c/*obj*/ );
            };
        
        var x/*createRecord*/ = l/*_mochaLocalExport*/.createRecord = function x/*createRecord*/( c/*obj*/ ) {
              if ( c/*obj*/.toString() === "[object Object]" ){
                f/*createUnenumProp*/( c/*obj*/,"toString",
                function () {
                  return "[object Record]";
                });
              };
              return Object.freeze( c/*obj*/ );
            };
        
        var y/*extendPrototype*/ = l/*_mochaLocalExport*/.extendPrototype = function ( b/*derived*/,c/*base*/ ) {
              b/*derived*/.prototype = c/*base*/;
            };
        
        var h/*getPrototype*/ = ( "getPrototypeOf" in Object )?function ( b/*obj*/ ) {
              return Object.getPrototypeOf( b/*obj*/ );
            } : function ( b/*obj*/ ) {
              var c/*ret*/ = {};
              
              for ( var d/*i*/ in b/*obj*/ ){
                if ( !b/*obj*/.hasOwnProperty( d/*i*/ ) ){
                  c/*ret*/[d/*i*/] = b/*obj*/[d/*i*/];
                };
              };
              return c/*ret*/;
            };
        
        var z/*extendClass*/ = l/*_mochaLocalExport*/.extendClass = ( a/*Runtime*/.hasProto )?function ( b/*derived*/,c/*base*/ ) {
              if ( typeof c/*base*/ === 'function' ){
                b/*derived*/.prototype.__proto__ = c/*base*/.prototype;
                
                for ( var d/*i*/ in c/*base*/ ){
                  b/*derived*/[d/*i*/] = c/*base*/[d/*i*/];
                };
              } else {
                b/*derived*/.prototype.__proto__ = c/*base*/.__proto__;
              };
            } : function ( i/*derived*/,j/*base*/ ) {
              var k/*baseType*/ = typeof j/*base*/;
              
              if ( k/*baseType*/ === "function" ){
                var l/*inherit*/ = function (){};
                
                l/*inherit*/.prototype = j/*base*/.prototype;
                
                i/*derived*/.prototype = new l/*inherit*/;
                
                for ( var m/*i*/ in j/*base*/ ){
                  i/*derived*/[m/*i*/] = j/*base*/[m/*i*/];
                };
              } else {
                var l/*inherit*/ = function (){},
                    n/*proto*/ = h/*getPrototype*/( j/*base*/ );
                
                l/*inherit*/.prototype = n/*proto*/;
                
                i/*derived*/.prototype = new l/*inherit*/;
              };
            };
        
        var i/*__ref_iterator__*/ = l/*_mochaLocalExport*/.__ref_iterator__ = "__mocha_iterator_special_key__";
        
        var A/*throwStopIteration*/ = l/*_mochaLocalExport*/.throwStopIteration = function A/*throwStopIteration*/() {
              try {
                throw StopIteration;
              } catch( e ){
                throw new Error( e.toString() );
              };
            };
        
        var j/*isGenerator*/ = l/*_mochaLocalExport*/.isGenerator = function j/*isGenerator*/( b/*obj*/ ) {
              return b/*obj*/ instanceof e/*Generator*/;
            };
        
        var B/*getIterator*/ = l/*_mochaLocalExport*/.getIterator = function B/*getIterator*/( l/*obj*/ ) {
              var a/*ret*/ = l/*obj*/[i/*__ref_iterator__*/](),
                  m/*newObj*/;
              
              if ( j/*isGenerator*/( a/*ret*/ ) ){
                return a/*ret*/;
              };
              
              m/*newObj*/ = {};
              
              if ( a/*ret*/.next ){
                f/*createUnenumProp*/( m/*newObj*/,"next",
                function () {
                  var c/*result*/ = a/*ret*/.next();
                  
                  if ( c/*result*/ === undefined ){
                    A/*throwStopIteration*/();
                  };
                  return c/*result*/;
                });
              } else {
                return {};
              };
              
              if ( !( "__nothrowNext__" in a/*ret*/ ) ){
                f/*createUnenumProp*/( m/*newObj*/,"__nothrowNext__",a/*ret*/.next.bind( a/*ret*/ ) );
              };
              
              for ( var n/*prop*/ in a/*ret*/ ){
                if ( n/*prop*/ !== "next" && n/*prop*/ !== "__nothrowNext__" ){
                  m/*newObj*/[n/*prop*/] = a/*ret*/[n/*prop*/];
                };
              };
              
              if ( !( "toString" in a/*ret*/ ) ){
                f/*createUnenumProp*/( m/*newObj*/,"toString",
                function () {
                  return "[object Iterator]";
                });
              };
              return m/*newObj*/;
            };
        
        var C/*hasIterator*/ = l/*_mochaLocalExport*/.hasIterator = function C/*hasIterator*/( b/*obj*/ ) {
              return i/*__ref_iterator__*/ in b/*obj*/;
            };
        
        var D/*rstopIteration*/ = /StopIteration/;
        
        var b/*isStopIteration*/ = l/*_mochaLocalExport*/.isStopIteration = function b/*isStopIteration*/( b/*obj*/ ) {
              return b/*obj*/ === StopIteration || D/*rstopIteration*/.test( b/*obj*/ );
            };
        
        var k/*privateRecord*/,
            E/*createPrivateRecord*/,
            F/*getPrivateRecord*/;
        
        if ( "WeakMap" in window ){
          k/*privateRecord*/ = new WeakMap();
          
          E/*createPrivateRecord*/ = function ( self,b/*privateHolder*/ ) {
            var c/*holder*/ = new b/*privateHolder*/;
            
            f/*createUnenumProp*/( c/*holder*/.constructor,"__is_private__",1 );
            
            k/*privateRecord*/.set( self,c/*holder*/ );
          };
          
          F/*getPrivateRecord*/ = function ( self ) {
            if ( k/*privateRecord*/.has( self ) ){
              return k/*privateRecord*/.get( self );
            } else if ( self.constructor === "__is_private__" ){
              return self;
            };
          };
        } else {
          E/*createPrivateRecord*/ = function ( self,b/*privateHolder*/ ) {
            if ( !self.__typeid__ ){
              var c/*holder*/ = new b/*privateHolder*/;
              
              f/*createUnenumProp*/( c/*holder*/.constructor,"__is_private__",1 );
              
              f/*createUnenumProp*/( self,"__private__",c/*holder*/ );
            };
          };
          
          F/*getPrivateRecord*/ = function ( self ) {
            if ( self.__private__ ){
              return self.__private__;
            } else if ( self.constructor === "__is_private__" ){
              return self;
            };
          };
        };
        
        l/*_mochaLocalExport*/.createPrivateRecord = E/*createPrivateRecord*/;
        
        l/*_mochaLocalExport*/.getPrivateRecord = F/*getPrivateRecord*/;
        
        var G/*getSuper*/ = l/*_mochaLocalExport*/.getSuper = function G/*getSuper*/( b/*obj*/ ) {
              var c/*type*/ = typeof b/*obj*/,
                  d/*ret*/;
              
              if ( c/*type*/ === "function" ){
                d/*ret*/ = function (){};
                
                d/*ret*/.prototype = b/*obj*/.prototype;
                
                d/*ret*/ = new d/*ret*/();
                
                if ( b/*obj*/.__harmony_class__ ){
                  d/*ret*/.constructor = b/*obj*/.constructor;
                } else {
                  d/*ret*/.constructor = b/*obj*/;
                };
                return d/*ret*/;
              };
              return d/*ret*/;
            };
        
        var H/*traitMixin*/ = l/*_mochaLocalExport*/.traitMixin = function H/*traitMixin*/( b/*dest*/,c/*source*/,d/*with_*/,e/*without*/ ) {
              if ( !b/*dest*/._mochaTraitMark || !c/*source*/._mochaTraitMark ){
                a/*Runtime*/.throwException( "mixin only used for trait." );
              } else {
                var f/*destTraitPrivate*/ = b/*dest*/._mochaTraitPrivate,
                    g/*sourceTraitPrivate*/ = c/*source*/._mochaTraitPrivate,
                    h/*destTraitPublic*/ = b/*dest*/._mochaTraitPublic,
                    i/*sourceTraitPublic*/ = c/*source*/._mochaTraitPublic,
                    j/*sourceRequires*/ = c/*source*/._mochaRequires,
                    k/*destRequires*/ = b/*dest*/._mochaRequires,
                    l/*tmp*/;
                
                for ( var m/*i*/ in g/*sourceTraitPrivate*/ ){
                  if ( !e/*without*/[m/*i*/] ){
                    l/*tmp*/ = ( !d/*with_*/[m/*i*/] )?m/*i*/ : d/*with_*/[m/*i*/];
                    
                    f/*destTraitPrivate*/[l/*tmp*/] = g/*sourceTraitPrivate*/[m/*i*/];
                  };
                };
                
                for ( m/*i*/ in i/*sourceTraitPublic*/ ){
                  if ( !e/*without*/[m/*i*/] ){
                    l/*tmp*/ = ( !d/*with_*/[m/*i*/] )?m/*i*/ : d/*with_*/[m/*i*/];
                    
                    h/*destTraitPublic*/[l/*tmp*/] = i/*sourceTraitPublic*/[m/*i*/];
                  };
                };
                
                for ( m/*i*/ in j/*sourceRequires*/ ){
                  k/*destRequires*/[m/*i*/] = j/*sourceRequires*/[m/*i*/];
                };
              };
            };
        
        var I/*classMixin*/ = l/*_mochaLocalExport*/.classMixin = function I/*classMixin*/( b/*_mochaLocalTmp5*/,c/*_mochaLocalTmp6*/,d/*_mochaLocalTmp7*/,e/*with_*/,f/*without*/ ) {
              var g/*constructorProto*/ = b/*_mochaLocalTmp5*/.prototype,
                  h/*privateProto*/ = c/*_mochaLocalTmp6*/.prototype,
                  i/*mark*/ = d/*_mochaLocalTmp7*/._mochaTraitMark,
                  j/*traitPublic*/ = d/*_mochaLocalTmp7*/._mochaTraitPublic,
                  k/*traitPrivate*/ = d/*_mochaLocalTmp7*/._mochaTraitPrivate;
              
              if ( !i/*mark*/ ){
                a/*Runtime*/.throwException( "mixin only used for trait." );
              } else {
                var l/*tmp*/;
                
                for ( var m/*i*/ in j/*traitPublic*/ ){
                  if ( !f/*without*/[m/*i*/] ){
                    l/*tmp*/ = ( !e/*with_*/[m/*i*/] )?m/*i*/ : e/*with_*/[m/*i*/];
                    
                    g/*constructorProto*/[l/*tmp*/] = j/*traitPublic*/[m/*i*/];
                  };
                };
                
                for ( m/*i*/ in k/*traitPrivate*/ ){
                  if ( !f/*without*/[m/*i*/] ){
                    l/*tmp*/ = ( !e/*with_*/[m/*i*/] )?m/*i*/ : e/*with_*/[m/*i*/];
                    
                    h/*privateProto*/[l/*tmp*/] = k/*traitPrivate*/[m/*i*/];
                  };
                };
              };
            };
        
        var J/*checkRequirements*/ = l/*_mochaLocalExport*/.checkRequirements = function J/*checkRequirements*/( b/*_mochaLocalTmp8*/,c/*_mochaLocalTmp9*/,d/*traits*/,e/*file*/,f/*line*/ ) {
              var g/*proto1*/ = b/*_mochaLocalTmp8*/.prototype,
                  h/*proto2*/ = c/*_mochaLocalTmp9*/.prototype;
              
              for ( var i/*i*/ = 0,j/*len*/ = d/*traits*/.length;i/*i*/<j/*len*/;i/*i*/ ++  ){
                var k/*_mochaLocalTmp10*/ = d/*traits*/[i/*i*/],
                    l/*_mochaRequires*/ = k/*_mochaLocalTmp10*/._mochaRequires;
                
                for ( var m/*prop*/ in l/*_mochaRequires*/ ){
                  if ( !( m/*prop*/ in g/*proto1*/ ) && !( m/*prop*/ in h/*proto2*/ ) ){
                    a/*Runtime*/.throwException( "Class dose not meet the traits requirement. traits require implementation of property "+m/*prop*/+"\nin file "+e/*file*/+" at line "+f/*line*/ );
                  };
                };
              };
            };
        
        ( function () {
          var n/*assert*/ = l/*_mochaLocalExport*/.assert = ( console && console.assert )?function ( b/*expect*/,c/*exp*/,d/*str*/,e/*line*/,f/*filename*/ ) {
                return console.assert( b/*expect*/ === c/*exp*/,"assertion failed : "+d/*str*/+"\nexpect "+b/*expect*/+" but got "+c/*exp*/+"\nin file "+f/*filename*/+" at : "+e/*line*/ );
              } : function ( b/*expect*/,c/*exp*/,d/*str*/,e/*line*/,f/*filename*/ ) {
                if ( b/*expect*/ !== c/*exp*/ ){
                  a/*Runtime*/.throwException( "assertion failed : "+d/*str*/+"\nexpect "+b/*expect*/+" but got "+c/*exp*/+"\nin file "+f/*filename*/+" at : "+e/*line*/ );
                };
              };
        })();
        return l/*_mochaLocalExport*/;
      })();
  
  if ( !( "StopIteration" in window ) ){
    window.StopIteration =  {
      toString : function d/*toString*/() {
        return "[object StopIteration]";
      }
    };
  };
  
  __LINE__ = 0;
  ( function () {
    try {
      var __FILE__ = "/var/samba/mocha/src/test/js/harmony/for_each_test.js",
          __LINE__ = 0;
      __LINE__ = 2;
      b/*_mochaGlobalExport*/['./for_each_test.js'] = {};
      
      __LINE__ = 3;
      var d/*_mochaGlobalAlias*/ = b/*_mochaGlobalExport*/['./for_each_test.js'];
      
      __LINE__ = 1;
      var e/*targetObject*/ =  {
            value1 : 100,
            value2 : 200,
            value3 : 300
          },
          f/*arr*/ = [];
      
      __LINE__ = 7;
      for ( var g/*i*/ in e/*targetObject*/ ){
        __LINE__ = 0;
        g/*i*/ = e/*targetObject*/[g/*i*/];
        
        __LINE__ = 0;
        f/*arr*/.push( g/*i*/ );
      };
      
      __LINE__ = 10;
      a/*Runtime*/.assert( true,f/*arr*/[0] === 100,"arr[0] === 100",10,'./for_each_test.js' );
      
      __LINE__ = 11;
      a/*Runtime*/.assert( true,f/*arr*/[1] === 200,"arr[1] === 200",11,'./for_each_test.js' );
      
      __LINE__ = 12;
      a/*Runtime*/.assert( true,f/*arr*/[2] === 300,"arr[2] === 300",12,'./for_each_test.js' );
      
      __LINE__ = 0;
      f/*arr*/ = [];
      
      __LINE__ = 15;
      for ( g/*i*/ in e/*targetObject*/ ){
        __LINE__ = 0;
        g/*i*/ = e/*targetObject*/[g/*i*/];
        
        __LINE__ = 0;
        f/*arr*/.push( g/*i*/ );
      };
      
      __LINE__ = 18;
      a/*Runtime*/.assert( true,f/*arr*/[0] === 100,"arr[0] === 100",18,'./for_each_test.js' );
      
      __LINE__ = 19;
      a/*Runtime*/.assert( true,f/*arr*/[1] === 200,"arr[1] === 200",19,'./for_each_test.js' );
      
      __LINE__ = 20;
      a/*Runtime*/.assert( true,f/*arr*/[2] === 300,"arr[2] === 300",20,'./for_each_test.js' );
      
      __LINE__ = 0;
      f/*arr*/ = [];
      
      __LINE__ = 23;
      for ( var g/*i*/ in e/*targetObject*/ ){
        __LINE__ = 0;
        g/*i*/ = e/*targetObject*/[g/*i*/];
        
        __LINE__ = 0;
        f/*arr*/.push( g/*i*/ );
      };
      
      __LINE__ = 26;
      a/*Runtime*/.assert( true,f/*arr*/[0] === 100,"arr[0] === 100",26,'./for_each_test.js' );
      
      __LINE__ = 27;
      a/*Runtime*/.assert( true,f/*arr*/[1] === 200,"arr[1] === 200",27,'./for_each_test.js' );
      
      __LINE__ = 28;
      a/*Runtime*/.assert( true,f/*arr*/[2] === 300,"arr[2] === 300",28,'./for_each_test.js' );
      
      __LINE__ = 0;
      f/*arr*/ = [];
      
      __LINE__ = 31;
      for ( g/*i*/ in e/*targetObject*/ ){
        __LINE__ = 0;
        g/*i*/ = e/*targetObject*/[g/*i*/];
        
        __LINE__ = 0;
        f/*arr*/.push( g/*i*/ );
      };
      
      __LINE__ = 34;
      a/*Runtime*/.assert( true,f/*arr*/[0] === 100,"arr[0] === 100",34,'./for_each_test.js' );
      
      __LINE__ = 35;
      a/*Runtime*/.assert( true,f/*arr*/[1] === 200,"arr[1] === 200",35,'./for_each_test.js' );
      
      __LINE__ = 36;
      a/*Runtime*/.assert( true,f/*arr*/[2] === 300,"arr[2] === 300",36,'./for_each_test.js' );
      
      __LINE__ = 38;
      var h/*prop*/ =  {
            val : ""
          };
      
      __LINE__ = 0;
      f/*arr*/ = [];
      
      __LINE__ = 42;
      for ( h/*prop*/.val in e/*targetObject*/ ){
        __LINE__ = 0;
        h/*prop*/.val = e/*targetObject*/[h/*prop*/.val];
        
        __LINE__ = 0;
        f/*arr*/.push( h/*prop*/.val );
      };
      
      __LINE__ = 46;
      a/*Runtime*/.assert( true,f/*arr*/[0] === 100,"arr[0] === 100",46,'./for_each_test.js' );
      
      __LINE__ = 47;
      a/*Runtime*/.assert( true,f/*arr*/[1] === 200,"arr[1] === 200",47,'./for_each_test.js' );
      
      __LINE__ = 48;
      a/*Runtime*/.assert( true,f/*arr*/[2] === 300,"arr[2] === 300",48,'./for_each_test.js' );
    } catch( e ){
      a.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  })();
})();
