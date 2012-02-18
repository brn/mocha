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
      var __FILE__ = "/var/samba/mocha/src/test/js/harmony/yield_test.js",
          __LINE__ = 0;
      __LINE__ = 2;
      b/*_mochaGlobalExport*/['./yield_test.js'] = {};
      
      __LINE__ = 3;
      var c/*_mochaGlobalAlias*/ = b/*_mochaGlobalExport*/['./yield_test.js'];
      
      __LINE__ = 1;
      var q/*tests*/ =  {
            case1 : function d/*case1*/() {
              try {
                __LINE__ = 0;
                function b/*yieldTest2*/(  ) {
                  try {
                    __LINE__ = 0;
                    var a/*_mochaIsNewBorn*/ = true;
                    
                    __LINE__ = 0;
                    var d/*_yieldResult*/ = undefined;
                    
                    __LINE__ = 0;
                    var b/*_yieldState*/ = 0;
                    
                    __LINE__ = 4;
                    var e/*i*/;
                    
                    __LINE__ = 0;
                    var f/*_mochaGenerator*/ = function ( c/*_isYieldSend*/,d/*_isYieldSafe*/ ) {
                          try {
                            __LINE__ = 0;
                            if ( !c/*_isYieldSend*/ ){
                              __LINE__ = 0;
                              a/*_mochaIsNewBorn*/ = false;
                            } else if ( c/*_isYieldSend*/ && a/*_mochaIsNewBorn*/ && arguments[1] !== undefined ){
                              __LINE__ = 0;
                              a/*Runtime*/.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 9;
                            while ( 1 ){
                              __LINE__ = 9;
                              switch ( b/*_yieldState*/ ) {
                                case 0 :
                                  
                                  __LINE__ = 4;
                                  e/*i*/ = 0;
                                  
                                  __LINE__ = 4;
                                  if ( !( e/*i*/<10 ) ){
                                    __LINE__ = 9;
                                    b/*_yieldState*/ = -1;
                                    __LINE__ = 9;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 0;
                                  b/*_yieldState*/ = 2;
                                  __LINE__ = 0;
                                  return e/*i*/;
                                case 2 :
                                  
                                  __LINE__ = 0;
                                  e/*i*/ ++ ;
                                  
                                  __LINE__ = 9;
                                  if ( e/*i*/<10 ){
                                    __LINE__ = 9;
                                    b/*_yieldState*/ = 1;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 9;
                                    b/*_yieldState*/ = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 0;
                                  if ( d/*_isYieldSafe*/ ){
                                    __LINE__ = 0;
                                    return undefined;
                                  } else {
                                    __LINE__ = 9;
                                    a/*Runtime*/.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            a.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 0;
                    return a/*Runtime*/.createGenerator( f/*_mochaGenerator*/,
                    function (  ) {
                      try {
                        __LINE__ = 0;
                        b/*_yieldState*/ = -1;
                      } catch( e ){
                        a.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    a.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
                
                __LINE__ = 9;
                var c/*generator*/ = b/*yieldTest2*/();
                
                __LINE__ = 11;
                a/*Runtime*/.assert( true,c/*generator*/.next() === 0,"generator.next() === 0",11,'./yield_test.js' );
                
                __LINE__ = 12;
                a/*Runtime*/.assert( true,c/*generator*/.next() === 1,"generator.next() === 1",12,'./yield_test.js' );
                
                __LINE__ = 13;
                a/*Runtime*/.assert( true,c/*generator*/.next() === 2,"generator.next() === 2",13,'./yield_test.js' );
                
                __LINE__ = 14;
                a/*Runtime*/.assert( true,c/*generator*/.next() === 3,"generator.next() === 3",14,'./yield_test.js' );
                
                __LINE__ = 15;
                a/*Runtime*/.assert( true,c/*generator*/.next() === 4,"generator.next() === 4",15,'./yield_test.js' );
                
                __LINE__ = 16;
                a/*Runtime*/.assert( true,c/*generator*/.next() === 5,"generator.next() === 5",16,'./yield_test.js' );
                
                __LINE__ = 17;
                a/*Runtime*/.assert( true,c/*generator*/.next() === 6,"generator.next() === 6",17,'./yield_test.js' );
                
                __LINE__ = 18;
                a/*Runtime*/.assert( true,c/*generator*/.next() === 7,"generator.next() === 7",18,'./yield_test.js' );
                
                __LINE__ = 19;
                a/*Runtime*/.assert( true,c/*generator*/.next() === 8,"generator.next() === 8",19,'./yield_test.js' );
                
                __LINE__ = 20;
                a/*Runtime*/.assert( true,c/*generator*/.next() === 9,"generator.next() === 9",20,'./yield_test.js' );
              } catch( e ){
                a.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case2 : function e/*case2*/() {
              try {
                __LINE__ = 0;
                function c/*yieldTest3*/(  ) {
                  try {
                    __LINE__ = 0;
                    var a/*_mochaIsNewBorn*/ = true;
                    
                    __LINE__ = 0;
                    var d/*_yieldResult*/ = undefined;
                    
                    __LINE__ = 0;
                    var b/*_yieldState*/ = 0;
                    
                    __LINE__ = 25;
                    var e/*i*/;
                    
                    __LINE__ = 0;
                    var f/*_mochaGenerator*/ = function ( c/*_isYieldSend*/,d/*_isYieldSafe*/ ) {
                          try {
                            __LINE__ = 0;
                            if ( !c/*_isYieldSend*/ ){
                              __LINE__ = 0;
                              a/*_mochaIsNewBorn*/ = false;
                            } else if ( c/*_isYieldSend*/ && a/*_mochaIsNewBorn*/ && arguments[1] !== undefined ){
                              __LINE__ = 0;
                              a/*Runtime*/.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 31;
                            while ( 1 ){
                              __LINE__ = 31;
                              switch ( b/*_yieldState*/ ) {
                                case 0 :
                                  
                                  __LINE__ = 25;
                                  e/*i*/ = 0;
                                  
                                  __LINE__ = 25;
                                  if ( !( e/*i*/<10 ) ){
                                    __LINE__ = 31;
                                    b/*_yieldState*/ = -1;
                                    __LINE__ = 31;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 26;
                                  if ( e/*i*/%2 === 0 ){
                                    __LINE__ = 31;
                                    b/*_yieldState*/ = 2;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 31;
                                    b/*_yieldState*/ = 3;
                                    __LINE__ = 0;
                                    break;
                                  };
                                case 2 :
                                  
                                  __LINE__ = 0;
                                  b/*_yieldState*/ = 3;
                                  __LINE__ = 0;
                                  return e/*i*/;
                                case 3 :
                                  
                                  __LINE__ = 0;
                                  b/*_yieldState*/ = 4;
                                  __LINE__ = 0;
                                  break;
                                case 4 :
                                  
                                  __LINE__ = 0;
                                  e/*i*/ ++ ;
                                  
                                  __LINE__ = 31;
                                  if ( e/*i*/<10 ){
                                    __LINE__ = 31;
                                    b/*_yieldState*/ = 1;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 31;
                                    b/*_yieldState*/ = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 0;
                                  if ( d/*_isYieldSafe*/ ){
                                    __LINE__ = 0;
                                    return undefined;
                                  } else {
                                    __LINE__ = 31;
                                    a/*Runtime*/.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            a.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 0;
                    return a/*Runtime*/.createGenerator( f/*_mochaGenerator*/,
                    function (  ) {
                      try {
                        __LINE__ = 0;
                        b/*_yieldState*/ = -1;
                      } catch( e ){
                        a.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    a.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
                
                __LINE__ = 0;
                generator = c/*yieldTest3*/();
                
                __LINE__ = 32;
                a/*Runtime*/.assert( true,generator.next() === 0,"generator.next() === 0",32,'./yield_test.js' );
                
                __LINE__ = 33;
                a/*Runtime*/.assert( true,generator.next() === 2,"generator.next() === 2",33,'./yield_test.js' );
                
                __LINE__ = 34;
                a/*Runtime*/.assert( true,generator.next() === 4,"generator.next() === 4",34,'./yield_test.js' );
                
                __LINE__ = 35;
                a/*Runtime*/.assert( true,generator.next() === 6,"generator.next() === 6",35,'./yield_test.js' );
                
                __LINE__ = 36;
                a/*Runtime*/.assert( true,generator.next() === 8,"generator.next() === 8",36,'./yield_test.js' );
              } catch( e ){
                a.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case3 : function f/*case3*/() {
              try {
                __LINE__ = 0;
                function c/*yieldTest4*/(  ) {
                  try {
                    __LINE__ = 0;
                    var a/*_mochaIsNewBorn*/ = true;
                    
                    __LINE__ = 0;
                    var d/*_yieldResult*/ = undefined;
                    
                    __LINE__ = 0;
                    var b/*_yieldState*/ = 0;
                    
                    __LINE__ = 41;
                    var e/*j*/;
                    
                    __LINE__ = 40;
                    var f/*i*/;
                    
                    __LINE__ = 0;
                    var g/*_mochaGenerator*/ = function ( c/*_isYieldSend*/,d/*_isYieldSafe*/ ) {
                          try {
                            __LINE__ = 0;
                            if ( !c/*_isYieldSend*/ ){
                              __LINE__ = 0;
                              a/*_mochaIsNewBorn*/ = false;
                            } else if ( c/*_isYieldSend*/ && a/*_mochaIsNewBorn*/ && arguments[1] !== undefined ){
                              __LINE__ = 0;
                              a/*Runtime*/.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 48;
                            while ( 1 ){
                              __LINE__ = 48;
                              switch ( b/*_yieldState*/ ) {
                                case 0 :
                                  
                                  __LINE__ = 40;
                                  f/*i*/ = 0;
                                  
                                  __LINE__ = 40;
                                  if ( !( f/*i*/<10 ) ){
                                    __LINE__ = 48;
                                    b/*_yieldState*/ = -1;
                                    __LINE__ = 48;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 41;
                                  e/*j*/ = 0;
                                  
                                  __LINE__ = 41;
                                  if ( !( e/*j*/<10 ) ){
                                    __LINE__ = 48;
                                    b/*_yieldState*/ = 6;
                                    __LINE__ = 48;
                                    break;
                                  };
                                case 2 :
                                  
                                  __LINE__ = 42;
                                  if ( e/*j*/%2 === 0 ){
                                    __LINE__ = 48;
                                    b/*_yieldState*/ = 3;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 48;
                                    b/*_yieldState*/ = 4;
                                    __LINE__ = 0;
                                    break;
                                  };
                                case 3 :
                                  
                                  __LINE__ = 0;
                                  b/*_yieldState*/ = 4;
                                  __LINE__ = 0;
                                  return e/*j*/;
                                case 4 :
                                  
                                  __LINE__ = 0;
                                  b/*_yieldState*/ = 5;
                                  __LINE__ = 0;
                                  break;
                                case 5 :
                                  
                                  __LINE__ = 0;
                                  e/*j*/ ++ ;
                                  
                                  __LINE__ = 48;
                                  if ( e/*j*/<10 ){
                                    __LINE__ = 48;
                                    b/*_yieldState*/ = 2;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 48;
                                    b/*_yieldState*/ = 6;
                                  };
                                case 6 :
                                  
                                  __LINE__ = 0;
                                  f/*i*/ ++ ;
                                  
                                  __LINE__ = 48;
                                  if ( f/*i*/<10 ){
                                    __LINE__ = 48;
                                    b/*_yieldState*/ = 1;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 48;
                                    b/*_yieldState*/ = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 0;
                                  if ( d/*_isYieldSafe*/ ){
                                    __LINE__ = 0;
                                    return undefined;
                                  } else {
                                    __LINE__ = 48;
                                    a/*Runtime*/.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            a.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 0;
                    return a/*Runtime*/.createGenerator( g/*_mochaGenerator*/,
                    function (  ) {
                      try {
                        __LINE__ = 0;
                        b/*_yieldState*/ = -1;
                      } catch( e ){
                        a.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    a.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
                
                __LINE__ = 0;
                generator = c/*yieldTest4*/();
                
                __LINE__ = 49;
                a/*Runtime*/.assert( true,generator.next() === 0,"generator.next() === 0",49,'./yield_test.js' );
                
                __LINE__ = 50;
                a/*Runtime*/.assert( true,generator.next() === 2,"generator.next() === 2",50,'./yield_test.js' );
                
                __LINE__ = 51;
                a/*Runtime*/.assert( true,generator.next() === 4,"generator.next() === 4",51,'./yield_test.js' );
                
                __LINE__ = 52;
                a/*Runtime*/.assert( true,generator.next() === 6,"generator.next() === 6",52,'./yield_test.js' );
                
                __LINE__ = 53;
                a/*Runtime*/.assert( true,generator.next() === 8,"generator.next() === 8",53,'./yield_test.js' );
                
                __LINE__ = 55;
                a/*Runtime*/.assert( true,generator.next() === 0,"generator.next() === 0",55,'./yield_test.js' );
                
                __LINE__ = 56;
                a/*Runtime*/.assert( true,generator.next() === 2,"generator.next() === 2",56,'./yield_test.js' );
                
                __LINE__ = 57;
                a/*Runtime*/.assert( true,generator.next() === 4,"generator.next() === 4",57,'./yield_test.js' );
                
                __LINE__ = 58;
                a/*Runtime*/.assert( true,generator.next() === 6,"generator.next() === 6",58,'./yield_test.js' );
                
                __LINE__ = 59;
                a/*Runtime*/.assert( true,generator.next() === 8,"generator.next() === 8",59,'./yield_test.js' );
                
                __LINE__ = 61;
                a/*Runtime*/.assert( true,generator.next() === 0,"generator.next() === 0",61,'./yield_test.js' );
                
                __LINE__ = 62;
                a/*Runtime*/.assert( true,generator.next() === 2,"generator.next() === 2",62,'./yield_test.js' );
                
                __LINE__ = 63;
                a/*Runtime*/.assert( true,generator.next() === 4,"generator.next() === 4",63,'./yield_test.js' );
                
                __LINE__ = 64;
                a/*Runtime*/.assert( true,generator.next() === 6,"generator.next() === 6",64,'./yield_test.js' );
                
                __LINE__ = 65;
                a/*Runtime*/.assert( true,generator.next() === 8,"generator.next() === 8",65,'./yield_test.js' );
                
                __LINE__ = 67;
                a/*Runtime*/.assert( true,generator.next() === 0,"generator.next() === 0",67,'./yield_test.js' );
                
                __LINE__ = 68;
                a/*Runtime*/.assert( true,generator.next() === 2,"generator.next() === 2",68,'./yield_test.js' );
                
                __LINE__ = 69;
                a/*Runtime*/.assert( true,generator.next() === 4,"generator.next() === 4",69,'./yield_test.js' );
                
                __LINE__ = 70;
                a/*Runtime*/.assert( true,generator.next() === 6,"generator.next() === 6",70,'./yield_test.js' );
                
                __LINE__ = 71;
                a/*Runtime*/.assert( true,generator.next() === 8,"generator.next() === 8",71,'./yield_test.js' );
                
                __LINE__ = 73;
                a/*Runtime*/.assert( true,generator.next() === 0,"generator.next() === 0",73,'./yield_test.js' );
                
                __LINE__ = 74;
                a/*Runtime*/.assert( true,generator.next() === 2,"generator.next() === 2",74,'./yield_test.js' );
                
                __LINE__ = 75;
                a/*Runtime*/.assert( true,generator.next() === 4,"generator.next() === 4",75,'./yield_test.js' );
                
                __LINE__ = 76;
                a/*Runtime*/.assert( true,generator.next() === 6,"generator.next() === 6",76,'./yield_test.js' );
                
                __LINE__ = 77;
                a/*Runtime*/.assert( true,generator.next() === 8,"generator.next() === 8",77,'./yield_test.js' );
                
                __LINE__ = 79;
                a/*Runtime*/.assert( true,generator.next() === 0,"generator.next() === 0",79,'./yield_test.js' );
                
                __LINE__ = 80;
                a/*Runtime*/.assert( true,generator.next() === 2,"generator.next() === 2",80,'./yield_test.js' );
                
                __LINE__ = 81;
                a/*Runtime*/.assert( true,generator.next() === 4,"generator.next() === 4",81,'./yield_test.js' );
                
                __LINE__ = 82;
                a/*Runtime*/.assert( true,generator.next() === 6,"generator.next() === 6",82,'./yield_test.js' );
                
                __LINE__ = 83;
                a/*Runtime*/.assert( true,generator.next() === 8,"generator.next() === 8",83,'./yield_test.js' );
                
                __LINE__ = 85;
                a/*Runtime*/.assert( true,generator.next() === 0,"generator.next() === 0",85,'./yield_test.js' );
                
                __LINE__ = 86;
                a/*Runtime*/.assert( true,generator.next() === 2,"generator.next() === 2",86,'./yield_test.js' );
                
                __LINE__ = 87;
                a/*Runtime*/.assert( true,generator.next() === 4,"generator.next() === 4",87,'./yield_test.js' );
                
                __LINE__ = 88;
                a/*Runtime*/.assert( true,generator.next() === 6,"generator.next() === 6",88,'./yield_test.js' );
                
                __LINE__ = 89;
                a/*Runtime*/.assert( true,generator.next() === 8,"generator.next() === 8",89,'./yield_test.js' );
                
                __LINE__ = 91;
                a/*Runtime*/.assert( true,generator.next() === 0,"generator.next() === 0",91,'./yield_test.js' );
                
                __LINE__ = 92;
                a/*Runtime*/.assert( true,generator.next() === 2,"generator.next() === 2",92,'./yield_test.js' );
                
                __LINE__ = 93;
                a/*Runtime*/.assert( true,generator.next() === 4,"generator.next() === 4",93,'./yield_test.js' );
                
                __LINE__ = 94;
                a/*Runtime*/.assert( true,generator.next() === 6,"generator.next() === 6",94,'./yield_test.js' );
                
                __LINE__ = 95;
                a/*Runtime*/.assert( true,generator.next() === 8,"generator.next() === 8",95,'./yield_test.js' );
                
                __LINE__ = 97;
                a/*Runtime*/.assert( true,generator.next() === 0,"generator.next() === 0",97,'./yield_test.js' );
                
                __LINE__ = 98;
                a/*Runtime*/.assert( true,generator.next() === 2,"generator.next() === 2",98,'./yield_test.js' );
                
                __LINE__ = 99;
                a/*Runtime*/.assert( true,generator.next() === 4,"generator.next() === 4",99,'./yield_test.js' );
                
                __LINE__ = 100;
                a/*Runtime*/.assert( true,generator.next() === 6,"generator.next() === 6",100,'./yield_test.js' );
                
                __LINE__ = 101;
                a/*Runtime*/.assert( true,generator.next() === 8,"generator.next() === 8",101,'./yield_test.js' );
                
                __LINE__ = 103;
                a/*Runtime*/.assert( true,generator.next() === 0,"generator.next() === 0",103,'./yield_test.js' );
                
                __LINE__ = 104;
                a/*Runtime*/.assert( true,generator.next() === 2,"generator.next() === 2",104,'./yield_test.js' );
                
                __LINE__ = 105;
                a/*Runtime*/.assert( true,generator.next() === 4,"generator.next() === 4",105,'./yield_test.js' );
                
                __LINE__ = 106;
                a/*Runtime*/.assert( true,generator.next() === 6,"generator.next() === 6",106,'./yield_test.js' );
                
                __LINE__ = 107;
                a/*Runtime*/.assert( true,generator.next() === 8,"generator.next() === 8",107,'./yield_test.js' );
              } catch( e ){
                a.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case4 : function g/*case4*/() {
              try {
                __LINE__ = 0;
                function c/*yieldTest5*/(  ) {
                  try {
                    __LINE__ = 0;
                    var a/*_mochaIsNewBorn*/ = true;
                    
                    __LINE__ = 0;
                    var d/*_yieldResult*/ = undefined;
                    
                    __LINE__ = 0;
                    var b/*_yieldState*/ = 0;
                    
                    __LINE__ = 111;
                    var e/*i*/;
                    
                    __LINE__ = 0;
                    var f/*_mochaGenerator*/ = function ( c/*_isYieldSend*/,d/*_isYieldSafe*/ ) {
                          try {
                            __LINE__ = 0;
                            if ( !c/*_isYieldSend*/ ){
                              __LINE__ = 0;
                              a/*_mochaIsNewBorn*/ = false;
                            } else if ( c/*_isYieldSend*/ && a/*_mochaIsNewBorn*/ && arguments[1] !== undefined ){
                              __LINE__ = 0;
                              a/*Runtime*/.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 117;
                            while ( 1 ){
                              __LINE__ = 117;
                              switch ( b/*_yieldState*/ ) {
                                case 0 :
                                  
                                  __LINE__ = 111;
                                  e/*i*/ = 0;
                                  
                                  __LINE__ = 112;
                                  if ( !(  ++ e/*i*/<10 ) ){
                                    __LINE__ = 117;
                                    b/*_yieldState*/ = -1;
                                    __LINE__ = 117;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 0;
                                  b/*_yieldState*/ = 2;
                                  __LINE__ = 0;
                                  return e/*i*/;
                                case 2 :
                                  
                                  __LINE__ = 117;
                                  if (  ++ e/*i*/<10 ){
                                    __LINE__ = 117;
                                    b/*_yieldState*/ = 1;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 117;
                                    b/*_yieldState*/ = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 0;
                                  if ( d/*_isYieldSafe*/ ){
                                    __LINE__ = 0;
                                    return undefined;
                                  } else {
                                    __LINE__ = 117;
                                    a/*Runtime*/.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            a.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 0;
                    return a/*Runtime*/.createGenerator( f/*_mochaGenerator*/,
                    function (  ) {
                      try {
                        __LINE__ = 0;
                        b/*_yieldState*/ = -1;
                      } catch( e ){
                        a.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    a.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
                
                __LINE__ = 0;
                generator = c/*yieldTest5*/();
                
                __LINE__ = 118;
                a/*Runtime*/.assert( true,generator.next() === 1,"generator.next() === 1",118,'./yield_test.js' );
                
                __LINE__ = 119;
                a/*Runtime*/.assert( true,generator.next() === 2,"generator.next() === 2",119,'./yield_test.js' );
                
                __LINE__ = 120;
                a/*Runtime*/.assert( true,generator.next() === 3,"generator.next() === 3",120,'./yield_test.js' );
                
                __LINE__ = 121;
                a/*Runtime*/.assert( true,generator.next() === 4,"generator.next() === 4",121,'./yield_test.js' );
                
                __LINE__ = 122;
                a/*Runtime*/.assert( true,generator.next() === 5,"generator.next() === 5",122,'./yield_test.js' );
                
                __LINE__ = 123;
                a/*Runtime*/.assert( true,generator.next() === 6,"generator.next() === 6",123,'./yield_test.js' );
                
                __LINE__ = 124;
                a/*Runtime*/.assert( true,generator.next() === 7,"generator.next() === 7",124,'./yield_test.js' );
                
                __LINE__ = 125;
                a/*Runtime*/.assert( true,generator.next() === 8,"generator.next() === 8",125,'./yield_test.js' );
                
                __LINE__ = 126;
                a/*Runtime*/.assert( true,generator.next() === 9,"generator.next() === 9",126,'./yield_test.js' );
              } catch( e ){
                a.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case5 : function h/*case5*/() {
              try {
                __LINE__ = 0;
                function c/*yieldTest6*/(  ) {
                  try {
                    __LINE__ = 0;
                    var a/*_mochaIsNewBorn*/ = true;
                    
                    __LINE__ = 0;
                    var d/*_yieldResult*/ = undefined;
                    
                    __LINE__ = 0;
                    var b/*_yieldState*/ = 0;
                    
                    __LINE__ = 130;
                    var e/*i*/;
                    
                    __LINE__ = 0;
                    var f/*_mochaGenerator*/ = function ( c/*_isYieldSend*/,d/*_isYieldSafe*/ ) {
                          try {
                            __LINE__ = 0;
                            if ( !c/*_isYieldSend*/ ){
                              __LINE__ = 0;
                              a/*_mochaIsNewBorn*/ = false;
                            } else if ( c/*_isYieldSend*/ && a/*_mochaIsNewBorn*/ && arguments[1] !== undefined ){
                              __LINE__ = 0;
                              a/*Runtime*/.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 136;
                            while ( 1 ){
                              __LINE__ = 136;
                              switch ( b/*_yieldState*/ ) {
                                case 0 :
                                  
                                  __LINE__ = 130;
                                  e/*i*/ = 0;
                                case 1 :
                                  
                                  __LINE__ = 0;
                                  b/*_yieldState*/ = 2;
                                  __LINE__ = 0;
                                  return e/*i*/;
                                case 2 :
                                  
                                  __LINE__ = 136;
                                  if (  ++ e/*i*/<10 ){
                                    __LINE__ = 136;
                                    b/*_yieldState*/ = 1;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 136;
                                    b/*_yieldState*/ = 3;
                                  };
                                case 3 :
                                case -1 :
                                  
                                  __LINE__ = 0;
                                  if ( d/*_isYieldSafe*/ ){
                                    __LINE__ = 0;
                                    return undefined;
                                  } else {
                                    __LINE__ = 136;
                                    a/*Runtime*/.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            a.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 0;
                    return a/*Runtime*/.createGenerator( f/*_mochaGenerator*/,
                    function (  ) {
                      try {
                        __LINE__ = 0;
                        b/*_yieldState*/ = -1;
                      } catch( e ){
                        a.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    a.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
                
                __LINE__ = 0;
                generator = c/*yieldTest6*/();
                
                __LINE__ = 137;
                a/*Runtime*/.assert( true,generator.next() === 0,"generator.next() === 0",137,'./yield_test.js' );
                
                __LINE__ = 138;
                a/*Runtime*/.assert( true,generator.next() === 1,"generator.next() === 1",138,'./yield_test.js' );
                
                __LINE__ = 139;
                a/*Runtime*/.assert( true,generator.next() === 2,"generator.next() === 2",139,'./yield_test.js' );
                
                __LINE__ = 140;
                a/*Runtime*/.assert( true,generator.next() === 3,"generator.next() === 3",140,'./yield_test.js' );
                
                __LINE__ = 141;
                a/*Runtime*/.assert( true,generator.next() === 4,"generator.next() === 4",141,'./yield_test.js' );
                
                __LINE__ = 142;
                a/*Runtime*/.assert( true,generator.next() === 5,"generator.next() === 5",142,'./yield_test.js' );
                
                __LINE__ = 143;
                a/*Runtime*/.assert( true,generator.next() === 6,"generator.next() === 6",143,'./yield_test.js' );
                
                __LINE__ = 144;
                a/*Runtime*/.assert( true,generator.next() === 7,"generator.next() === 7",144,'./yield_test.js' );
                
                __LINE__ = 145;
                a/*Runtime*/.assert( true,generator.next() === 8,"generator.next() === 8",145,'./yield_test.js' );
                
                __LINE__ = 146;
                a/*Runtime*/.assert( true,generator.next() === 9,"generator.next() === 9",146,'./yield_test.js' );
              } catch( e ){
                a.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case6 : function i/*case6*/() {
              try {
                __LINE__ = 0;
                function c/*yieldTest7*/(  ) {
                  try {
                    __LINE__ = 0;
                    var a/*_mochaIsNewBorn*/ = true;
                    
                    __LINE__ = 0;
                    var d/*_yieldResult*/ = undefined;
                    
                    __LINE__ = 0;
                    var b/*_yieldState*/ = 0;
                    
                    __LINE__ = 151;
                    var e/*m*/;
                    
                    __LINE__ = 150;
                    var f/*i*/;
                    
                    __LINE__ = 0;
                    var g/*_mochaGenerator*/ = function ( c/*_isYieldSend*/,d/*_isYieldSafe*/ ) {
                          try {
                            __LINE__ = 0;
                            if ( !c/*_isYieldSend*/ ){
                              __LINE__ = 0;
                              a/*_mochaIsNewBorn*/ = false;
                            } else if ( c/*_isYieldSend*/ && a/*_mochaIsNewBorn*/ && arguments[1] !== undefined ){
                              __LINE__ = 0;
                              a/*Runtime*/.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 162;
                            while ( 1 ){
                              __LINE__ = 162;
                              switch ( b/*_yieldState*/ ) {
                                case 0 :
                                  
                                  __LINE__ = 150;
                                  f/*i*/ = 0;
                                  
                                  __LINE__ = 150;
                                  if ( !( f/*i*/<10 ) ){
                                    __LINE__ = 162;
                                    b/*_yieldState*/ = -1;
                                    __LINE__ = 162;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 151;
                                  b/*_yieldState*/ = 2;
                                  __LINE__ = 151;
                                  return f/*i*/;
                                case 2 :
                                  
                                  __LINE__ = 0;
                                  d/*_yieldResult*/ = c/*_isYieldSend*/ && arguments.length>2?a/*Runtime*/.toArray( arguments,2 )[0] : c/*_isYieldSend*/?f/*i*/ : undefined;
                                  
                                  __LINE__ = 151;
                                  e/*m*/ = d/*_yieldResult*/;
                                  
                                  __LINE__ = 152;
                                  if ( e/*m*/ === true ){
                                    __LINE__ = 162;
                                    b/*_yieldState*/ = 3;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 162;
                                    b/*_yieldState*/ = 5;
                                    __LINE__ = 0;
                                    break;
                                  };
                                case 3 :
                                  
                                  __LINE__ = 0;
                                  b/*_yieldState*/ = 4;
                                  __LINE__ = 0;
                                  return f/*i*/+1;
                                case 4 :
                                  
                                  __LINE__ = 0;
                                  b/*_yieldState*/ = 9;
                                  __LINE__ = 0;
                                  break;
                                case 5 :
                                  
                                  __LINE__ = 154;
                                  if ( e/*m*/ === false ){
                                    __LINE__ = 162;
                                    b/*_yieldState*/ = 6;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 162;
                                    b/*_yieldState*/ = 8;
                                    __LINE__ = 0;
                                    break;
                                  };
                                case 6 :
                                  
                                  __LINE__ = 0;
                                  b/*_yieldState*/ = 7;
                                  __LINE__ = 0;
                                  return f/*i*/-1;
                                case 7 :
                                  
                                  __LINE__ = 0;
                                  b/*_yieldState*/ = 9;
                                  __LINE__ = 0;
                                  break;
                                case 8 :
                                  
                                  __LINE__ = 0;
                                  b/*_yieldState*/ = 9;
                                  __LINE__ = 0;
                                  return f/*i*/;
                                case 9 :
                                  
                                  __LINE__ = 0;
                                  f/*i*/ ++ ;
                                  
                                  __LINE__ = 162;
                                  if ( f/*i*/<10 ){
                                    __LINE__ = 162;
                                    b/*_yieldState*/ = 1;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 162;
                                    b/*_yieldState*/ = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 0;
                                  if ( d/*_isYieldSafe*/ ){
                                    __LINE__ = 0;
                                    return undefined;
                                  } else {
                                    __LINE__ = 162;
                                    a/*Runtime*/.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            a.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 0;
                    return a/*Runtime*/.createGenerator( g/*_mochaGenerator*/,
                    function (  ) {
                      try {
                        __LINE__ = 0;
                        b/*_yieldState*/ = -1;
                      } catch( e ){
                        a.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    a.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
                
                __LINE__ = 0;
                generator = c/*yieldTest7*/();
                
                __LINE__ = 163;
                a/*Runtime*/.assert( true,generator.next() === 0,"generator.next() === 0",163,'./yield_test.js' );
                
                __LINE__ = 164;
                a/*Runtime*/.assert( true,generator.send( true ) === 1,"generator.send( true ) === 1",164,'./yield_test.js' );
                
                __LINE__ = 165;
                a/*Runtime*/.assert( true,generator.send( false ) === 1,"generator.send( false ) === 1",165,'./yield_test.js' );
                
                __LINE__ = 166;
                a/*Runtime*/.assert( true,generator.send( true ) === 2,"generator.send( true ) === 2",166,'./yield_test.js' );
                
                __LINE__ = 167;
                a/*Runtime*/.assert( true,generator.send( false ) === 2,"generator.send( false ) === 2",167,'./yield_test.js' );
                
                __LINE__ = 168;
                a/*Runtime*/.assert( true,generator.send( true ) === 3,"generator.send( true ) === 3",168,'./yield_test.js' );
                
                __LINE__ = 169;
                a/*Runtime*/.assert( true,generator.send( true ) === 3,"generator.send( true ) === 3",169,'./yield_test.js' );
                
                __LINE__ = 170;
                a/*Runtime*/.assert( true,generator.send( true ) === 4,"generator.send( true ) === 4",170,'./yield_test.js' );
                
                __LINE__ = 171;
                a/*Runtime*/.assert( true,generator.send( false ) === 4,"generator.send( false ) === 4",171,'./yield_test.js' );
                
                __LINE__ = 172;
                a/*Runtime*/.assert( true,generator.send( true ) === 5,"generator.send( true ) === 5",172,'./yield_test.js' );
              } catch( e ){
                a.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case7 : function j/*case7*/() {
              try {
                __LINE__ = 0;
                function c/*yieldTest8*/(  ) {
                  try {
                    __LINE__ = 0;
                    var a/*_mochaIsNewBorn*/ = true;
                    
                    __LINE__ = 0;
                    var d/*_yieldResult*/ = undefined;
                    
                    __LINE__ = 0;
                    var b/*_yieldState*/ = 0;
                    
                    __LINE__ = 178;
                    var e/*j*/;
                    
                    __LINE__ = 177;
                    var f/*m*/;
                    
                    __LINE__ = 176;
                    var g/*i*/;
                    
                    __LINE__ = 0;
                    var h/*_mochaGenerator*/ = function ( c/*_isYieldSend*/,d/*_isYieldSafe*/ ) {
                          try {
                            __LINE__ = 0;
                            if ( !c/*_isYieldSend*/ ){
                              __LINE__ = 0;
                              a/*_mochaIsNewBorn*/ = false;
                            } else if ( c/*_isYieldSend*/ && a/*_mochaIsNewBorn*/ && arguments[1] !== undefined ){
                              __LINE__ = 0;
                              a/*Runtime*/.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 191;
                            while ( 1 ){
                              __LINE__ = 191;
                              switch ( b/*_yieldState*/ ) {
                                case 0 :
                                  
                                  __LINE__ = 176;
                                  g/*i*/ = 0;
                                  
                                  __LINE__ = 176;
                                  if ( !( g/*i*/<10 ) ){
                                    __LINE__ = 191;
                                    b/*_yieldState*/ = -1;
                                    __LINE__ = 191;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 177;
                                  b/*_yieldState*/ = 2;
                                  __LINE__ = 177;
                                  return g/*i*/;
                                case 2 :
                                  
                                  __LINE__ = 0;
                                  d/*_yieldResult*/ = c/*_isYieldSend*/ && arguments.length>2?a/*Runtime*/.toArray( arguments,2 )[0] : c/*_isYieldSend*/?g/*i*/ : undefined;
                                  
                                  __LINE__ = 177;
                                  f/*m*/ = d/*_yieldResult*/;
                                  
                                  __LINE__ = 178;
                                  e/*j*/ = 0;
                                  
                                  __LINE__ = 178;
                                  if ( !( e/*j*/<10 ) ){
                                    __LINE__ = 191;
                                    b/*_yieldState*/ = 11;
                                    __LINE__ = 191;
                                    break;
                                  };
                                case 3 :
                                  
                                  __LINE__ = 179;
                                  if ( f/*m*/ === true ){
                                    __LINE__ = 191;
                                    b/*_yieldState*/ = 4;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 191;
                                    b/*_yieldState*/ = 6;
                                    __LINE__ = 0;
                                    break;
                                  };
                                case 4 :
                                  
                                  __LINE__ = 0;
                                  b/*_yieldState*/ = 5;
                                  __LINE__ = 0;
                                  return e/*j*/*2;
                                case 5 :
                                  
                                  __LINE__ = 0;
                                  b/*_yieldState*/ = 10;
                                  __LINE__ = 0;
                                  break;
                                case 6 :
                                  
                                  __LINE__ = 181;
                                  if ( f/*m*/ === false ){
                                    __LINE__ = 191;
                                    b/*_yieldState*/ = 7;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 191;
                                    b/*_yieldState*/ = 9;
                                    __LINE__ = 0;
                                    break;
                                  };
                                case 7 :
                                  
                                  __LINE__ = 0;
                                  b/*_yieldState*/ = 8;
                                  __LINE__ = 0;
                                  return e/*j*//2;
                                case 8 :
                                  
                                  __LINE__ = 0;
                                  b/*_yieldState*/ = 10;
                                  __LINE__ = 0;
                                  break;
                                case 9 :
                                  
                                  __LINE__ = 0;
                                  b/*_yieldState*/ = 10;
                                  __LINE__ = 0;
                                  return e/*j*/;
                                case 10 :
                                  
                                  __LINE__ = 0;
                                  e/*j*/ ++ ;
                                  
                                  __LINE__ = 191;
                                  if ( e/*j*/<10 ){
                                    __LINE__ = 191;
                                    b/*_yieldState*/ = 3;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 191;
                                    b/*_yieldState*/ = 11;
                                  };
                                case 11 :
                                  
                                  __LINE__ = 0;
                                  g/*i*/ ++ ;
                                  
                                  __LINE__ = 191;
                                  if ( g/*i*/<10 ){
                                    __LINE__ = 191;
                                    b/*_yieldState*/ = 1;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 191;
                                    b/*_yieldState*/ = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 0;
                                  if ( d/*_isYieldSafe*/ ){
                                    __LINE__ = 0;
                                    return undefined;
                                  } else {
                                    __LINE__ = 191;
                                    a/*Runtime*/.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            a.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 0;
                    return a/*Runtime*/.createGenerator( h/*_mochaGenerator*/,
                    function (  ) {
                      try {
                        __LINE__ = 0;
                        b/*_yieldState*/ = -1;
                      } catch( e ){
                        a.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    a.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
                
                __LINE__ = 0;
                generator = c/*yieldTest8*/();
                
                __LINE__ = 192;
                a/*Runtime*/.assert( true,generator.next() === 0,"generator.next() === 0",192,'./yield_test.js' );
                
                __LINE__ = 193;
                a/*Runtime*/.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",193,'./yield_test.js' );
                
                __LINE__ = 194;
                a/*Runtime*/.assert( true,generator.send( false ) === 2,"generator.send( false ) === 2",194,'./yield_test.js' );
                
                __LINE__ = 195;
                a/*Runtime*/.assert( true,generator.send( true ) === 4,"generator.send( true ) === 4",195,'./yield_test.js' );
                
                __LINE__ = 196;
                a/*Runtime*/.assert( true,generator.send( false ) === 6,"generator.send( false ) === 6",196,'./yield_test.js' );
                
                __LINE__ = 197;
                a/*Runtime*/.assert( true,generator.send( true ) === 8,"generator.send( true ) === 8",197,'./yield_test.js' );
                
                __LINE__ = 198;
                a/*Runtime*/.assert( true,generator.send( true ) === 10,"generator.send( true ) === 10",198,'./yield_test.js' );
                
                __LINE__ = 199;
                a/*Runtime*/.assert( true,generator.send( true ) === 12,"generator.send( true ) === 12",199,'./yield_test.js' );
                
                __LINE__ = 200;
                a/*Runtime*/.assert( true,generator.send( false ) === 14,"generator.send( false ) === 14",200,'./yield_test.js' );
                
                __LINE__ = 201;
                a/*Runtime*/.assert( true,generator.send( true ) === 16,"generator.send( true ) === 16",201,'./yield_test.js' );
                
                __LINE__ = 202;
                a/*Runtime*/.assert( true,generator.send( true ) === 18,"generator.send( true ) === 18",202,'./yield_test.js' );
                
                __LINE__ = 203;
                a/*Runtime*/.assert( true,generator.send( false ) === 1,"generator.send( false ) === 1",203,'./yield_test.js' );
                
                __LINE__ = 204;
                a/*Runtime*/.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",204,'./yield_test.js' );
                
                __LINE__ = 205;
                a/*Runtime*/.assert( true,generator.send( false ) === 2,"generator.send( false ) === 2",205,'./yield_test.js' );
                
                __LINE__ = 206;
                a/*Runtime*/.assert( true,generator.send( true ) === 4,"generator.send( true ) === 4",206,'./yield_test.js' );
                
                __LINE__ = 207;
                a/*Runtime*/.assert( true,generator.send( true ) === 6,"generator.send( true ) === 6",207,'./yield_test.js' );
                
                __LINE__ = 208;
                a/*Runtime*/.assert( true,generator.send( true ) === 8,"generator.send( true ) === 8",208,'./yield_test.js' );
                
                __LINE__ = 209;
                a/*Runtime*/.assert( true,generator.send( false ) === 10,"generator.send( false ) === 10",209,'./yield_test.js' );
                
                __LINE__ = 210;
                a/*Runtime*/.assert( true,generator.send( true ) === 12,"generator.send( true ) === 12",210,'./yield_test.js' );
              } catch( e ){
                a.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case8 : function k/*case8*/() {
              try {
                __LINE__ = 0;
                function c/*yieldTest9*/(  ) {
                  try {
                    __LINE__ = 0;
                    var a/*_mochaIsNewBorn*/ = true;
                    
                    __LINE__ = 0;
                    var d/*_yieldResult*/ = undefined;
                    
                    __LINE__ = 0;
                    var b/*_yieldState*/ = 0;
                    
                    __LINE__ = 217;
                    var e/*m*/;
                    
                    __LINE__ = 216;
                    var f/*j*/;
                    
                    __LINE__ = 215;
                    var g/*i*/;
                    
                    __LINE__ = 0;
                    var h/*_mochaGenerator*/ = function ( c/*_isYieldSend*/,d/*_isYieldSafe*/ ) {
                          try {
                            __LINE__ = 0;
                            if ( !c/*_isYieldSend*/ ){
                              __LINE__ = 0;
                              a/*_mochaIsNewBorn*/ = false;
                            } else if ( c/*_isYieldSend*/ && a/*_mochaIsNewBorn*/ && arguments[1] !== undefined ){
                              __LINE__ = 0;
                              a/*Runtime*/.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 230;
                            while ( 1 ){
                              __LINE__ = 230;
                              switch ( b/*_yieldState*/ ) {
                                case 0 :
                                  
                                  __LINE__ = 215;
                                  g/*i*/ = 0;
                                  
                                  __LINE__ = 215;
                                  if ( !( g/*i*/<10 ) ){
                                    __LINE__ = 230;
                                    b/*_yieldState*/ = -1;
                                    __LINE__ = 230;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 216;
                                  f/*j*/ = 0;
                                  
                                  __LINE__ = 216;
                                  if ( !( f/*j*/<10 ) ){
                                    __LINE__ = 230;
                                    b/*_yieldState*/ = 11;
                                    __LINE__ = 230;
                                    break;
                                  };
                                case 2 :
                                  
                                  __LINE__ = 217;
                                  b/*_yieldState*/ = 3;
                                  __LINE__ = 217;
                                  return g/*i*/;
                                case 3 :
                                  
                                  __LINE__ = 0;
                                  d/*_yieldResult*/ = c/*_isYieldSend*/ && arguments.length>2?a/*Runtime*/.toArray( arguments,2 )[0] : c/*_isYieldSend*/?g/*i*/ : undefined;
                                  
                                  __LINE__ = 217;
                                  e/*m*/ = d/*_yieldResult*/;
                                  
                                  __LINE__ = 218;
                                  if ( e/*m*/ === true ){
                                    __LINE__ = 230;
                                    b/*_yieldState*/ = 4;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 230;
                                    b/*_yieldState*/ = 6;
                                    __LINE__ = 0;
                                    break;
                                  };
                                case 4 :
                                  
                                  __LINE__ = 0;
                                  b/*_yieldState*/ = 5;
                                  __LINE__ = 0;
                                  return f/*j*/*2;
                                case 5 :
                                  
                                  __LINE__ = 0;
                                  b/*_yieldState*/ = 10;
                                  __LINE__ = 0;
                                  break;
                                case 6 :
                                  
                                  __LINE__ = 220;
                                  if ( e/*m*/ === false ){
                                    __LINE__ = 230;
                                    b/*_yieldState*/ = 7;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 230;
                                    b/*_yieldState*/ = 9;
                                    __LINE__ = 0;
                                    break;
                                  };
                                case 7 :
                                  
                                  __LINE__ = 0;
                                  b/*_yieldState*/ = 8;
                                  __LINE__ = 0;
                                  return f/*j*//2;
                                case 8 :
                                  
                                  __LINE__ = 0;
                                  b/*_yieldState*/ = 10;
                                  __LINE__ = 0;
                                  break;
                                case 9 :
                                  
                                  __LINE__ = 0;
                                  b/*_yieldState*/ = 10;
                                  __LINE__ = 0;
                                  return f/*j*/;
                                case 10 :
                                  
                                  __LINE__ = 0;
                                  f/*j*/ ++ ;
                                  
                                  __LINE__ = 230;
                                  if ( f/*j*/<10 ){
                                    __LINE__ = 230;
                                    b/*_yieldState*/ = 2;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 230;
                                    b/*_yieldState*/ = 11;
                                  };
                                case 11 :
                                  
                                  __LINE__ = 0;
                                  g/*i*/ ++ ;
                                  
                                  __LINE__ = 230;
                                  if ( g/*i*/<10 ){
                                    __LINE__ = 230;
                                    b/*_yieldState*/ = 1;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 230;
                                    b/*_yieldState*/ = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 0;
                                  if ( d/*_isYieldSafe*/ ){
                                    __LINE__ = 0;
                                    return undefined;
                                  } else {
                                    __LINE__ = 230;
                                    a/*Runtime*/.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            a.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 0;
                    return a/*Runtime*/.createGenerator( h/*_mochaGenerator*/,
                    function (  ) {
                      try {
                        __LINE__ = 0;
                        b/*_yieldState*/ = -1;
                      } catch( e ){
                        a.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    a.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
                
                __LINE__ = 0;
                generator = c/*yieldTest9*/();
                
                __LINE__ = 231;
                a/*Runtime*/.assert( true,generator.next() === 0,"generator.next() === 0",231,'./yield_test.js' );
                
                __LINE__ = 232;
                a/*Runtime*/.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",232,'./yield_test.js' );
                
                __LINE__ = 233;
                a/*Runtime*/.assert( true,generator.send( false ) === 0,"generator.send( false ) === 0",233,'./yield_test.js' );
                
                __LINE__ = 234;
                a/*Runtime*/.assert( true,generator.send( true ) === 2,"generator.send( true ) === 2",234,'./yield_test.js' );
                
                __LINE__ = 235;
                a/*Runtime*/.assert( true,generator.send( false ) === 0,"generator.send( false ) === 0",235,'./yield_test.js' );
                
                __LINE__ = 236;
                a/*Runtime*/.assert( true,generator.send( true ) === 4,"generator.send( true ) === 4",236,'./yield_test.js' );
                
                __LINE__ = 237;
                a/*Runtime*/.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",237,'./yield_test.js' );
                
                __LINE__ = 238;
                a/*Runtime*/.assert( true,generator.send( true ) === 6,"generator.send( true ) === 6",238,'./yield_test.js' );
                
                __LINE__ = 239;
                a/*Runtime*/.assert( true,generator.send( false ) === 0,"generator.send( false ) === 0",239,'./yield_test.js' );
                
                __LINE__ = 240;
                a/*Runtime*/.assert( true,generator.send( true ) === 8,"generator.send( true ) === 8",240,'./yield_test.js' );
                
                __LINE__ = 241;
                a/*Runtime*/.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",241,'./yield_test.js' );
                
                __LINE__ = 242;
                a/*Runtime*/.assert( true,generator.send( false ) === 2.5,"generator.send( false ) === 2.5",242,'./yield_test.js' );
                
                __LINE__ = 243;
                a/*Runtime*/.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",243,'./yield_test.js' );
                
                __LINE__ = 244;
                a/*Runtime*/.assert( true,generator.send( false ) === 3,"generator.send( false ) === 3",244,'./yield_test.js' );
                
                __LINE__ = 245;
                a/*Runtime*/.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",245,'./yield_test.js' );
                
                __LINE__ = 246;
                a/*Runtime*/.assert( true,generator.send( true ) === 14,"generator.send( true ) === 14",246,'./yield_test.js' );
                
                __LINE__ = 247;
                a/*Runtime*/.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",247,'./yield_test.js' );
                
                __LINE__ = 248;
                a/*Runtime*/.assert( true,generator.send( false ) === 4,"generator.send( false ) === 4",248,'./yield_test.js' );
                
                __LINE__ = 249;
                a/*Runtime*/.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",249,'./yield_test.js' );
              } catch( e ){
                a.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case9 : function l/*case9*/() {
              try {
                __LINE__ = 0;
                function c/*yieldTest10*/(  ) {
                  try {
                    __LINE__ = 0;
                    var c/*_mochaIsNewBorn*/ = true;
                    
                    __LINE__ = 0;
                    var e/*_yieldResult*/ = undefined;
                    
                    __LINE__ = 0;
                    var a/*_yieldState*/ = 0;
                    
                    __LINE__ = 0;
                    var f/*_mochaFinallyCache*/;
                    
                    __LINE__ = 0;
                    var g/*_mochaCatchCache*/;
                    
                    __LINE__ = 257;
                    var h/*m*/;
                    
                    __LINE__ = 255;
                    var i/*i*/;
                    
                    __LINE__ = 254;
                    var b/*flg*/;
                    
                    __LINE__ = 0;
                    var j/*_mochaGenerator*/ = function ( e/*_isYieldSend*/,f/*_isYieldSafe*/ ) {
                          try {
                            __LINE__ = 0;
                            if ( !e/*_isYieldSend*/ ){
                              __LINE__ = 0;
                              c/*_mochaIsNewBorn*/ = false;
                            } else if ( e/*_isYieldSend*/ && c/*_mochaIsNewBorn*/ && arguments[1] !== undefined ){
                              __LINE__ = 0;
                              a/*Runtime*/.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 266;
                            while ( 1 ){
                              try {
                                __LINE__ = 266;
                                switch ( a/*_yieldState*/ ) {
                                  case 0 :
                                    
                                    __LINE__ = 254;
                                    b/*flg*/ = false;
                                    
                                    __LINE__ = 255;
                                    i/*i*/ = 0;
                                    
                                    __LINE__ = 255;
                                    if ( !( i/*i*/<10 ) ){
                                      __LINE__ = 266;
                                      a/*_yieldState*/ = -1;
                                      __LINE__ = 266;
                                      break;
                                    };
                                  case 1 :
                                    
                                    __LINE__ = 0;
                                    a/*_yieldState*/ = 2;
                                    
                                    __LINE__ = 260;
                                    g/*_mochaCatchCache*/ = function ( c/*e*/ ) {
                                      try {
                                        __LINE__ = 266;
                                        a/*_yieldState*/ = 3;
                                      } catch( e ){
                                        a.exceptionHandler( __LINE__ , __FILE__ , e );
                                      }
                                    };
                                    
                                    __LINE__ = 0;
                                    f/*_mochaFinallyCache*/ = function (  ) {
                                      try {
                                        __LINE__ = 0;
                                        b/*flg*/ = true;
                                      } catch( e ){
                                        a.exceptionHandler( __LINE__ , __FILE__ , e );
                                      }
                                    };
                                    
                                    __LINE__ = 257;
                                    h/*m*/ = ( b/*flg*/ )?1 : 0;
                                    __LINE__ = 0;
                                    return h/*m*/;
                                  case 2 :
                                    
                                    __LINE__ = 0;
                                    ddddd();
                                    
                                    __LINE__ = 0;
                                    g/*_mochaCatchCache*/ = undefined;
                                    
                                    __LINE__ = 0;
                                    f/*_mochaFinallyCache*/ = undefined;
                                  case 3 :
                                    
                                    __LINE__ = 0;
                                    i/*i*/ ++ ;
                                    
                                    __LINE__ = 266;
                                    if ( i/*i*/<10 ){
                                      __LINE__ = 266;
                                      a/*_yieldState*/ = 1;
                                      __LINE__ = 0;
                                      break;
                                    } else {
                                      __LINE__ = 266;
                                      a/*_yieldState*/ = -1;
                                    };
                                  case -1 :
                                    
                                    __LINE__ = 0;
                                    if ( f/*_isYieldSafe*/ ){
                                      __LINE__ = 0;
                                      return undefined;
                                    } else {
                                      __LINE__ = 266;
                                      a/*Runtime*/.throwStopIteration();
                                    };
                                    
                                };
                              } catch( _mochaException ){
                                __LINE__ = 0;
                                if ( g/*_mochaCatchCache*/ ){
                                  __LINE__ = 0;
                                  var g/*_mochaLocalTmp0*/ = g/*_mochaCatchCache*/( _mochaException );
                                  
                                  __LINE__ = 0;
                                  if ( g/*_mochaLocalTmp0*/ !== undefined ){
                                    __LINE__ = 0;
                                    return g/*_mochaLocalTmp0*/;
                                  };
                                } else {
                                  __LINE__ = 0;
                                  a/*Runtime*/.throwException( _mochaException );
                                };
                              } finally {
                                __LINE__ = 0;
                                if ( f/*_mochaFinallyCache*/ ){
                                  __LINE__ = 0;
                                  var _mochaLocalTmp1 = f/*_mochaFinallyCache*/(  );
                                  
                                  __LINE__ = 0;
                                  if ( _mochaLocalTmp1 !== undefined ){
                                    __LINE__ = 0;
                                    return _mochaLocalTmp1;
                                  };
                                };
                              };
                            };
                          } catch( e ){
                            a.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 0;
                    return a/*Runtime*/.createGenerator( j/*_mochaGenerator*/,
                    function (  ) {
                      try {
                        __LINE__ = 0;
                        a/*_yieldState*/ = -1;
                        
                        __LINE__ = 0;
                        if ( f/*_mochaFinallyCache*/ ){
                          __LINE__ = 0;
                          f/*_mochaFinallyCache*/(  );
                        };
                      } catch( e ){
                        a.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    a.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
                
                __LINE__ = 0;
                generator = c/*yieldTest10*/();
                
                __LINE__ = 267;
                a/*Runtime*/.assert( true,generator.next() === 0,"generator.next() === 0",267,'./yield_test.js' );
                
                __LINE__ = 268;
                a/*Runtime*/.assert( true,generator.next() === 1,"generator.next() === 1",268,'./yield_test.js' );
                
                __LINE__ = 269;
                a/*Runtime*/.assert( true,generator.next() === 1,"generator.next() === 1",269,'./yield_test.js' );
                
                __LINE__ = 270;
                a/*Runtime*/.assert( true,generator.next() === 1,"generator.next() === 1",270,'./yield_test.js' );
                
                __LINE__ = 271;
                a/*Runtime*/.assert( true,generator.next() === 1,"generator.next() === 1",271,'./yield_test.js' );
              } catch( e ){
                a.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case10 : function m/*case10*/() {
              try {
                __LINE__ = 0;
                function c/*yieldTest11*/(  ) {
                  try {
                    __LINE__ = 0;
                    var a/*_mochaIsNewBorn*/ = true;
                    
                    __LINE__ = 0;
                    var d/*_yieldResult*/ = undefined;
                    
                    __LINE__ = 0;
                    var b/*_yieldState*/ = 0;
                    
                    __LINE__ = 276;
                    var e/*type*/;
                    
                    __LINE__ = 275;
                    var f/*i*/;
                    
                    __LINE__ = 0;
                    var g/*_mochaGenerator*/ = function ( c/*_isYieldSend*/,d/*_isYieldSafe*/ ) {
                          try {
                            __LINE__ = 0;
                            if ( !c/*_isYieldSend*/ ){
                              __LINE__ = 0;
                              a/*_mochaIsNewBorn*/ = false;
                            } else if ( c/*_isYieldSend*/ && a/*_mochaIsNewBorn*/ && arguments[1] !== undefined ){
                              __LINE__ = 0;
                              a/*Runtime*/.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 289;
                            while ( 1 ){
                              __LINE__ = 289;
                              switch ( b/*_yieldState*/ ) {
                                case 0 :
                                  
                                  __LINE__ = 275;
                                  f/*i*/ = 0;
                                  
                                  __LINE__ = 275;
                                  if ( !( f/*i*/<10 ) ){
                                    __LINE__ = 289;
                                    b/*_yieldState*/ = -1;
                                    __LINE__ = 289;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 276;
                                  b/*_yieldState*/ = 2;
                                  __LINE__ = 276;
                                  return ;
                                case 2 :
                                  
                                  __LINE__ = 0;
                                  d/*_yieldResult*/ = c/*_isYieldSend*/ && arguments.length>2?a/*Runtime*/.toArray( arguments,2 )[0] : undefined;
                                  
                                  __LINE__ = 276;
                                  e/*type*/ = d/*_yieldResult*/;
                                  
                                  __LINE__ = 0;
                                  switch ( e/*type*/ ) {
                                    case 0 :
                                      
                                      __LINE__ = 0;
                                      b/*_yieldState*/ = 3;
                                      __LINE__ = 0;
                                      break;
                                    case 2 :
                                      
                                      __LINE__ = 0;
                                      b/*_yieldState*/ = 4;
                                      __LINE__ = 0;
                                      break;
                                    case 3 :
                                      
                                      __LINE__ = 0;
                                      b/*_yieldState*/ = 5;
                                      __LINE__ = 0;
                                      break;
                                    default :
                                      
                                      __LINE__ = 0;
                                      b/*_yieldState*/ = 6;
                                      __LINE__ = 0;
                                      break;
                                      
                                  };
                                  __LINE__ = 0;
                                  break;
                                case 3 :
                                  
                                  __LINE__ = 0;
                                  b/*_yieldState*/ = 7;
                                  __LINE__ = 0;
                                  return 200;
                                case 4 :
                                  
                                  __LINE__ = 0;
                                  b/*_yieldState*/ = 7;
                                  __LINE__ = 0;
                                  return 400;
                                case 5 :
                                  
                                  __LINE__ = 0;
                                  b/*_yieldState*/ = 7;
                                  __LINE__ = 0;
                                  return 600;
                                case 6 :
                                  
                                  __LINE__ = 0;
                                  b/*_yieldState*/ = 7;
                                  __LINE__ = 0;
                                  return 700;
                                case 7 :
                                  
                                  __LINE__ = 0;
                                  f/*i*/ ++ ;
                                  
                                  __LINE__ = 289;
                                  if ( f/*i*/<10 ){
                                    __LINE__ = 289;
                                    b/*_yieldState*/ = 1;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 289;
                                    b/*_yieldState*/ = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 0;
                                  if ( d/*_isYieldSafe*/ ){
                                    __LINE__ = 0;
                                    return undefined;
                                  } else {
                                    __LINE__ = 289;
                                    a/*Runtime*/.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            a.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 0;
                    return a/*Runtime*/.createGenerator( g/*_mochaGenerator*/,
                    function (  ) {
                      try {
                        __LINE__ = 0;
                        b/*_yieldState*/ = -1;
                      } catch( e ){
                        a.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    a.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
                
                __LINE__ = 0;
                generator = c/*yieldTest11*/();
                
                __LINE__ = 0;
                generator.next();
                
                __LINE__ = 291;
                a/*Runtime*/.assert( true,generator.send( 0 ) === 200,"generator.send( 0 ) === 200",291,'./yield_test.js' );
                
                __LINE__ = 0;
                generator.next();
                
                __LINE__ = 293;
                a/*Runtime*/.assert( true,generator.send( 2 ) === 400,"generator.send( 2 ) === 400",293,'./yield_test.js' );
                
                __LINE__ = 0;
                generator.next();
                
                __LINE__ = 295;
                a/*Runtime*/.assert( true,generator.send( 3 ) === 600,"generator.send( 3 ) === 600",295,'./yield_test.js' );
                
                __LINE__ = 0;
                generator.next();
                
                __LINE__ = 297;
                a/*Runtime*/.assert( true,generator.send( null ) === 700,"generator.send( null ) === 700",297,'./yield_test.js' );
              } catch( e ){
                a.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case11 : function n/*case11*/() {
              try {
                __LINE__ = 0;
                function c/*yieldTest12*/(  ) {
                  try {
                    __LINE__ = 0;
                    var a/*_mochaIsNewBorn*/ = true;
                    
                    __LINE__ = 0;
                    var d/*_yieldResult*/ = undefined;
                    
                    __LINE__ = 0;
                    var b/*_yieldState*/ = 0;
                    
                    __LINE__ = 303;
                    var e/*type*/;
                    
                    __LINE__ = 302;
                    var f/*i*/;
                    
                    __LINE__ = 0;
                    var g/*_mochaGenerator*/ = function ( c/*_isYieldSend*/,d/*_isYieldSafe*/ ) {
                          try {
                            __LINE__ = 0;
                            if ( !c/*_isYieldSend*/ ){
                              __LINE__ = 0;
                              a/*_mochaIsNewBorn*/ = false;
                            } else if ( c/*_isYieldSend*/ && a/*_mochaIsNewBorn*/ && arguments[1] !== undefined ){
                              __LINE__ = 0;
                              a/*Runtime*/.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 320;
                            while ( 1 ){
                              __LINE__ = 320;
                              switch ( b/*_yieldState*/ ) {
                                case 0 :
                                  
                                  __LINE__ = 302;
                                  f/*i*/ = 0;
                                  
                                  __LINE__ = 302;
                                  if ( !( f/*i*/<15 ) ){
                                    __LINE__ = 320;
                                    b/*_yieldState*/ = -1;
                                    __LINE__ = 320;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 303;
                                  b/*_yieldState*/ = 2;
                                  __LINE__ = 303;
                                  return ;
                                case 2 :
                                  
                                  __LINE__ = 0;
                                  d/*_yieldResult*/ = c/*_isYieldSend*/ && arguments.length>2?a/*Runtime*/.toArray( arguments,2 )[0] : undefined;
                                  
                                  __LINE__ = 303;
                                  e/*type*/ = d/*_yieldResult*/;
                                  
                                  __LINE__ = 0;
                                  switch ( e/*type*/ ) {
                                    case 4 :
                                    case 0 :
                                      
                                      __LINE__ = 0;
                                      b/*_yieldState*/ = 3;
                                      __LINE__ = 0;
                                      break;
                                    case 5 :
                                      
                                      __LINE__ = 0;
                                      b/*_yieldState*/ = 7;
                                      __LINE__ = 0;
                                      break;
                                    case 6 :
                                    case 2 :
                                      
                                      __LINE__ = 0;
                                      b/*_yieldState*/ = 4;
                                      __LINE__ = 0;
                                      break;
                                    case 3 :
                                      
                                      __LINE__ = 0;
                                      b/*_yieldState*/ = 5;
                                      __LINE__ = 0;
                                      break;
                                    default :
                                      
                                      __LINE__ = 0;
                                      b/*_yieldState*/ = 6;
                                      __LINE__ = 0;
                                      break;
                                      
                                  };
                                  __LINE__ = 0;
                                  break;
                                case 3 :
                                  
                                  __LINE__ = 0;
                                  b/*_yieldState*/ = 8;
                                  __LINE__ = 0;
                                  return 200;
                                case 4 :
                                  
                                  __LINE__ = 0;
                                  b/*_yieldState*/ = 8;
                                  __LINE__ = 0;
                                  return 400;
                                case 5 :
                                  
                                  __LINE__ = 0;
                                  b/*_yieldState*/ = 8;
                                  __LINE__ = 0;
                                  return 600;
                                case 6 :
                                  
                                  __LINE__ = 0;
                                  b/*_yieldState*/ = 8;
                                  __LINE__ = 0;
                                  return 700;
                                case 7 :
                                  
                                  __LINE__ = 0;
                                  b/*_yieldState*/ = 8;
                                  __LINE__ = 0;
                                  break;
                                case 8 :
                                  
                                  __LINE__ = 0;
                                  f/*i*/ ++ ;
                                  
                                  __LINE__ = 320;
                                  if ( f/*i*/<15 ){
                                    __LINE__ = 320;
                                    b/*_yieldState*/ = 1;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 320;
                                    b/*_yieldState*/ = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 0;
                                  if ( d/*_isYieldSafe*/ ){
                                    __LINE__ = 0;
                                    return undefined;
                                  } else {
                                    __LINE__ = 320;
                                    a/*Runtime*/.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            a.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 0;
                    return a/*Runtime*/.createGenerator( g/*_mochaGenerator*/,
                    function (  ) {
                      try {
                        __LINE__ = 0;
                        b/*_yieldState*/ = -1;
                      } catch( e ){
                        a.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    a.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
                
                __LINE__ = 0;
                generator = c/*yieldTest12*/();
                
                __LINE__ = 0;
                generator.next();
                
                __LINE__ = 322;
                a/*Runtime*/.assert( true,generator.send( 0 ) === 200,"generator.send( 0 ) === 200",322,'./yield_test.js' );
                
                __LINE__ = 0;
                generator.next();
                
                __LINE__ = 324;
                a/*Runtime*/.assert( true,generator.send( 4 ) === 200,"generator.send( 4 ) === 200",324,'./yield_test.js' );
                
                __LINE__ = 0;
                generator.next();
                
                __LINE__ = 326;
                a/*Runtime*/.assert( true,generator.send( 2 ) === 400,"generator.send( 2 ) === 400",326,'./yield_test.js' );
                
                __LINE__ = 0;
                generator.next();
                
                __LINE__ = 328;
                a/*Runtime*/.assert( true,generator.send( 5 ) === undefined,"generator.send( 5 ) === undefined",328,'./yield_test.js' );
                
                __LINE__ = 329;
                a/*Runtime*/.assert( true,generator.send( 3 ) === 600,"generator.send( 3 ) === 600",329,'./yield_test.js' );
                
                __LINE__ = 0;
                generator.next();
                
                __LINE__ = 331;
                a/*Runtime*/.assert( true,generator.send( null ) === 700,"generator.send( null ) === 700",331,'./yield_test.js' );
              } catch( e ){
                a.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case12 : function o/*case12*/() {
              try {
                __LINE__ = 0;
                function c/*yieldTest13*/() {
                  try {
                    __LINE__ = 0;
                    var a/*_mochaIsNewBorn*/ = true;
                    
                    __LINE__ = 0;
                    var d/*_yieldResult*/ = undefined;
                    
                    __LINE__ = 0;
                    var b/*_yieldState*/ = 0;
                    
                    __LINE__ = 337;
                    var e/*length*/;
                    
                    __LINE__ = 337;
                    var f/*_mochaLocalTmp4*/;
                    
                    __LINE__ = 0;
                    var g/*i*/;
                    
                    __LINE__ = 336;
                    var h/*obj*/;
                    
                    __LINE__ = 0;
                    var i/*_mochaLocalTmp3*/ = [];
                    
                    __LINE__ = 0;
                    var j/*_mochaGenerator*/ = function ( c/*_isYieldSend*/,d/*_isYieldSafe*/ ) {
                          try {
                            __LINE__ = 0;
                            if ( !c/*_isYieldSend*/ ){
                              __LINE__ = 0;
                              a/*_mochaIsNewBorn*/ = false;
                            } else if ( c/*_isYieldSend*/ && a/*_mochaIsNewBorn*/ && arguments[1] !== undefined ){
                              __LINE__ = 0;
                              a/*Runtime*/.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 342;
                            while ( 1 ){
                              __LINE__ = 342;
                              switch ( b/*_yieldState*/ ) {
                                case 0 :
                                  
                                  __LINE__ = 336;
                                  h/*obj*/ =  {
                                    x : 200,
                                    y : 300,
                                    z : 400
                                  };
                                  
                                  __LINE__ = 337;
                                  for ( var e/*_mochaLocalTmp2*/ in h/*obj*/ ){
                                    
                                    __LINE__ = 342;
                                    i/*_mochaLocalTmp3*/.push( e/*_mochaLocalTmp2*/ );
                                  };
                                  
                                  __LINE__ = 337;
                                  f/*_mochaLocalTmp4*/ = 0;
                                  
                                  __LINE__ = 337;
                                  e/*length*/ = i/*_mochaLocalTmp3*/.length;
                                  
                                  __LINE__ = 337;
                                  if ( !( f/*_mochaLocalTmp4*/<e/*length*/ ) ){
                                    __LINE__ = 342;
                                    b/*_yieldState*/ = -1;
                                    __LINE__ = 342;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 0;
                                  b/*_yieldState*/ = 2;
                                  
                                  __LINE__ = 0;
                                  g/*i*/ = i/*_mochaLocalTmp3*/[f/*_mochaLocalTmp4*/];
                                  __LINE__ = 0;
                                  return [g/*i*/,h/*obj*/[g/*i*/]];
                                case 2 :
                                  
                                  __LINE__ = 0;
                                   ++ f/*_mochaLocalTmp4*/;
                                  
                                  __LINE__ = 342;
                                  if ( f/*_mochaLocalTmp4*/<e/*length*/ ){
                                    __LINE__ = 342;
                                    b/*_yieldState*/ = 1;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 342;
                                    b/*_yieldState*/ = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 0;
                                  if ( d/*_isYieldSafe*/ ){
                                    __LINE__ = 0;
                                    return undefined;
                                  } else {
                                    __LINE__ = 342;
                                    a/*Runtime*/.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            a.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 0;
                    return a/*Runtime*/.createGenerator( j/*_mochaGenerator*/,
                    function (  ) {
                      try {
                        __LINE__ = 0;
                        b/*_yieldState*/ = -1;
                      } catch( e ){
                        a.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    a.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
                
                __LINE__ = 0;
                generator = c/*yieldTest13*/();
                
                __LINE__ = 343;
                var d/*ret*/ = generator.next();
                
                __LINE__ = 344;
                a/*Runtime*/.assert( true,d/*ret*/[0] === "x","ret[0] === \"x\"",344,'./yield_test.js' );
                
                __LINE__ = 345;
                a/*Runtime*/.assert( true,d/*ret*/[1] === 200,"ret[1] === 200",345,'./yield_test.js' );
                
                __LINE__ = 0;
                d/*ret*/ = generator.next();
                
                __LINE__ = 347;
                a/*Runtime*/.assert( true,d/*ret*/[0] === "y","ret[0] === \"y\"",347,'./yield_test.js' );
                
                __LINE__ = 348;
                a/*Runtime*/.assert( true,d/*ret*/[1] === 300,"ret[1] === 300",348,'./yield_test.js' );
                
                __LINE__ = 0;
                d/*ret*/ = generator.next();
                
                __LINE__ = 350;
                a/*Runtime*/.assert( true,d/*ret*/[0] === "z","ret[0] === \"z\"",350,'./yield_test.js' );
                
                __LINE__ = 351;
                a/*Runtime*/.assert( true,d/*ret*/[1] === 400,"ret[1] === 400",351,'./yield_test.js' );
              } catch( e ){
                a.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case13 : function p/*case13*/() {
              try {
                __LINE__ = 0;
                function b/*keys*/( d/*obj*/ ) {
                  try {
                    __LINE__ = 0;
                    var a/*_mochaIsNewBorn*/ = true;
                    
                    __LINE__ = 0;
                    var e/*_yieldResult*/ = undefined;
                    
                    __LINE__ = 0;
                    var b/*_yieldState*/ = 0;
                    
                    __LINE__ = 355;
                    var f/*length*/;
                    
                    __LINE__ = 355;
                    var g/*_mochaLocalTmp7*/;
                    
                    __LINE__ = 0;
                    var h/*prop*/;
                    
                    __LINE__ = 0;
                    var i/*_mochaLocalTmp6*/ = [];
                    
                    __LINE__ = 0;
                    var j/*_mochaGenerator*/ = function ( c/*_isYieldSend*/,d/*_isYieldSafe*/ ) {
                          try {
                            __LINE__ = 0;
                            if ( !c/*_isYieldSend*/ ){
                              __LINE__ = 0;
                              a/*_mochaIsNewBorn*/ = false;
                            } else if ( c/*_isYieldSend*/ && a/*_mochaIsNewBorn*/ && arguments[1] !== undefined ){
                              __LINE__ = 0;
                              a/*Runtime*/.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 362;
                            while ( 1 ){
                              __LINE__ = 362;
                              switch ( b/*_yieldState*/ ) {
                                case 0 :
                                  
                                  __LINE__ = 355;
                                  for ( var e/*_mochaLocalTmp5*/ in d/*obj*/ ){
                                    
                                    __LINE__ = 362;
                                    i/*_mochaLocalTmp6*/.push( e/*_mochaLocalTmp5*/ );
                                  };
                                  
                                  __LINE__ = 355;
                                  g/*_mochaLocalTmp7*/ = 0;
                                  
                                  __LINE__ = 355;
                                  f/*length*/ = i/*_mochaLocalTmp6*/.length;
                                  
                                  __LINE__ = 355;
                                  if ( !( g/*_mochaLocalTmp7*/<f/*length*/ ) ){
                                    __LINE__ = 362;
                                    b/*_yieldState*/ = -1;
                                    __LINE__ = 362;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 0;
                                  h/*prop*/ = i/*_mochaLocalTmp6*/[g/*_mochaLocalTmp7*/];
                                  
                                  __LINE__ = 356;
                                  if ( d/*obj*/.hasOwnProperty( h/*prop*/ ) ){
                                    __LINE__ = 362;
                                    b/*_yieldState*/ = 2;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 362;
                                    b/*_yieldState*/ = 3;
                                    __LINE__ = 0;
                                    break;
                                  };
                                case 2 :
                                  
                                  __LINE__ = 0;
                                  b/*_yieldState*/ = 3;
                                  __LINE__ = 0;
                                  return h/*prop*/;
                                case 3 :
                                  
                                  __LINE__ = 0;
                                  b/*_yieldState*/ = 4;
                                  __LINE__ = 0;
                                  break;
                                case 4 :
                                  
                                  __LINE__ = 0;
                                   ++ g/*_mochaLocalTmp7*/;
                                  
                                  __LINE__ = 362;
                                  if ( g/*_mochaLocalTmp7*/<f/*length*/ ){
                                    __LINE__ = 362;
                                    b/*_yieldState*/ = 1;
                                    __LINE__ = 0;
                                    break;
                                  } else {
                                    __LINE__ = 362;
                                    b/*_yieldState*/ = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 0;
                                  if ( d/*_isYieldSafe*/ ){
                                    __LINE__ = 0;
                                    return undefined;
                                  } else {
                                    __LINE__ = 362;
                                    a/*Runtime*/.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            a.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 0;
                    return a/*Runtime*/.createGenerator( j/*_mochaGenerator*/,
                    function (  ) {
                      try {
                        __LINE__ = 0;
                        b/*_yieldState*/ = -1;
                      } catch( e ){
                        a.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    a.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
                
                __LINE__ = 362;
                var c/*testObject*/ =  {
                      value1 : 1,
                      value2 : 2,
                      value3 : 3,
                      value4 : 4
                    };
                
                try {
                  __LINE__ = 369;
                  var d/*itemGen*/ = b/*keys*/( c/*testObject*/ );
                  
                  __LINE__ = 370;
                  a/*Runtime*/.assert( true,d/*itemGen*/.next() == "value1","itemGen.next() == \"value1\"",370,'./yield_test.js' );
                  
                  __LINE__ = 371;
                  a/*Runtime*/.assert( true,d/*itemGen*/.next() == "value2","itemGen.next() == \"value2\"",371,'./yield_test.js' );
                  
                  __LINE__ = 372;
                  a/*Runtime*/.assert( true,d/*itemGen*/.next() == "value3","itemGen.next() == \"value3\"",372,'./yield_test.js' );
                  
                  __LINE__ = 373;
                  a/*Runtime*/.assert( true,d/*itemGen*/.next() == "value4","itemGen.next() == \"value4\"",373,'./yield_test.js' );
                } catch( e ){
                  
                };
              } catch( e ){
                a.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            }
          };
      
      __LINE__ = 382;
      for ( var r/*i*/ = 1;r/*i*/<13;r/*i*/ ++  ){
        __LINE__ = 0;
        q/*tests*/["case"+r/*i*/]();
      };
    } catch( e ){
      a.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  })();
})();
