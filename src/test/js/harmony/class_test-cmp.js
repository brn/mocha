(function() {
  var __FILE__ = "Runtime",
      __LINE__ = 0;
  
  var f/*_mochaGlobalExport*/ = {};
  
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
      toString : function c/*toString*/() {
        return "[object StopIteration]";
      }
    };
  };
  
  __LINE__ = 0;
  ( function () {
    try {
      var __FILE__ = "/var/samba/mocha/src/test/js/harmony/class_test.js",
          __LINE__ = 0;
      __LINE__ = 2;
      f/*_mochaGlobalExport*/['./class_test.js'] = {};
      
      __LINE__ = 3;
      var h/*_mochaGlobalAlias*/ = f/*_mochaGlobalExport*/['./class_test.js'];
      
      __LINE__ = 1;
      var i/*Monster*/ = ( function () {
            try {
              __LINE__ = 0;
              var c/*_mochaPrivateHolder*/ = function (){};
              
              __LINE__ = 1;
              function d/*Monster*/() {
                try {
                  __LINE__ = 0;
                  a/*Runtime*/.createPrivateRecord( this,_mochaPrivateHolder );
                  
                  __LINE__ = 0;
                  constructor.apply( this,arguments );
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              function e/*constructor*/( b/*name*/,c/*health*/ ) {
                try {
                  
                  __LINE__ = 8;
                  this.name = b/*name*/;
                  
                  __LINE__ = 9;
                  a/*Runtime*/.getPrivateRecord( this ).health = c/*health*/;
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              __LINE__ = 0;
              a/*Runtime*/.createUnenumProp( e/*constructor*/,"__harmony_class__",1 );
              
              __LINE__ = 0;
              d/*Monster*/.prototype.attack = function attack( b/*target*/ ) {
                try {
                  __LINE__ = 0;
                  log( 'The monster attacks '+b/*target*/ );
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              d/*Monster*/.prototype.isAlive = function isAlive() {
                try {
                  __LINE__ = 23;
                  return a/*Runtime*/.getPrivateRecord( this ).health>0;
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              d/*Monster*/.prototype.health = function health( b/*value*/ ) {
                try {
                  __LINE__ = 0;
                  if ( b/*value*/<0 ){
                    __LINE__ = 0;
                    throw new Error( 'Health must be non-negative.' );
                  };
                  
                  __LINE__ = 0;
                  a/*Runtime*/.getPrivateRecord( this ).health = b/*value*/;
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 38;
              d/*Monster*/.prototype.numAttacks = 0;
              
              __LINE__ = 43;
              a/*Runtime*/.constant( d/*Monster*/.prototype,'attackMessage','The monster hits you!' );
              
              __LINE__ = 44;
              a/*Runtime*/.constant( d/*Monster*/,'DEFAULT_LIFE',100 );
              
              __LINE__ = 0;
              a/*Runtime*/.createUnenumProp( d/*Monster*/.prototype,"constructor",constructor );
              __LINE__ = 0;
              return d/*Monster*/;
            } catch( e ){
              a.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })();
      
      __LINE__ = 47;
      var j/*monster*/ = new i/*Monster*/( "slime",100 );
      
      __LINE__ = 48;
      a/*Runtime*/.assert( true,j/*monster*/.isAlive(),"monster.isAlive()",48,'./class_test.js' );
      
      __LINE__ = 49;
      a/*Runtime*/.assert( 0,j/*monster*/.numAttacks,"monster.numAttacks",49,'./class_test.js' );
      
      __LINE__ = 50;
      a/*Runtime*/.assert( 100,i/*Monster*/.DEFAULT_LIFE,"Monster.DEFAULT_LIFE",50,'./class_test.js' );
      
      __LINE__ = 51;
      a/*Runtime*/.assert( undefined,i/*Monster*/.health,"Monster.health",51,'./class_test.js' );
      
      __LINE__ = 52;
      var c/*BaseTest*/ = ( function () {
            try {
              __LINE__ = 0;
              var b/*_mochaPrivateHolder*/ = function (){};
              
              __LINE__ = 52;
              function c/*BaseTest*/() {
                try {
                  __LINE__ = 0;
                  a/*Runtime*/.createPrivateRecord( this,_mochaPrivateHolder );
                  
                  __LINE__ = 0;
                  constructor.apply( this,arguments );
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              function d/*constructor*/( b/*_mochaLocalTmp2*/,c/*_mochaLocalTmp3*/,d/*_mochaLocalTmp4*/ ) {
                try {
                  __LINE__ = 0;
                  this.name = b/*_mochaLocalTmp2*/ || 200;
                  
                  __LINE__ = 0;
                  a/*Runtime*/.getPrivateRecord( this ).addr = c/*_mochaLocalTmp3*/ || "tokyo";
                  
                  __LINE__ = 0;
                  a/*Runtime*/.getPrivateRecord( this ).age = d/*_mochaLocalTmp4*/;
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              __LINE__ = 0;
              a/*Runtime*/.createUnenumProp( d/*constructor*/,"__harmony_class__",1 );
              
              __LINE__ = 0;
              c/*BaseTest*/.prototype.getName = function getName() {
                try {
                  __LINE__ = 55;
                  return "hogehoge";
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              c/*BaseTest*/.getName = function getName() {
                try {
                  __LINE__ = 57;
                  return "static hogehoge";
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              a/*Runtime*/.createUnenumProp( c/*BaseTest*/.prototype,"constructor",constructor );
              __LINE__ = 0;
              return c/*BaseTest*/;
            } catch( e ){
              a.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })();
      
      __LINE__ = 60;
      var d/*DeriveTest*/ = ( function () {
            try {
              __LINE__ = 0;
              var d/*_mochaPrivateHolder*/ = function (){};
              
              __LINE__ = 60;
              function e/*DeriveTest*/() {
                try {
                  __LINE__ = 0;
                  a/*Runtime*/.createPrivateRecord( this,_mochaPrivateHolder );
                  
                  __LINE__ = 0;
                  constructor.apply( this,arguments );
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              var f/*_mochaLocalTmp6*/ = c/*BaseTest*/;
              
              __LINE__ = 60;
              a/*Runtime*/.extendClass( e/*DeriveTest*/,f/*_mochaLocalTmp6*/ );
              
              __LINE__ = 0;
              var b/*_mochaSuper*/ = a/*Runtime*/.getSuper( f/*_mochaLocalTmp6*/ );
              
              function g/*constructor*/() {
                try {
                  __LINE__ = 0;
                  b/*_mochaSuper*/.constructor.call( this );
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              __LINE__ = 0;
              a/*Runtime*/.createUnenumProp( g/*constructor*/,"__harmony_class__",1 );
              
              __LINE__ = 0;
              d/*_mochaPrivateHolder*/.prototype.getName = function getName() {
                try {
                  __LINE__ = 65;
                  return b/*_mochaSuper*/.getName.constructor.call( this );
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              a/*Runtime*/.createUnenumProp( e/*DeriveTest*/.prototype,"constructor",constructor );
              __LINE__ = 0;
              return e/*DeriveTest*/;
            } catch( e ){
              a.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })();
      
      __LINE__ = 70;
      var k/*Derive2*/ = ( function () {
            try {
              __LINE__ = 0;
              var e/*_mochaPrivateHolder*/ = function (){};
              
              __LINE__ = 70;
              function f/*Derive2*/() {
                try {
                  __LINE__ = 0;
                  a/*Runtime*/.createPrivateRecord( this,_mochaPrivateHolder );
                  
                  __LINE__ = 0;
                  constructor.apply( this,arguments );
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              var g/*_mochaLocalTmp8*/ = d/*DeriveTest*/;
              
              __LINE__ = 70;
              a/*Runtime*/.extendClass( f/*Derive2*/,g/*_mochaLocalTmp8*/ );
              
              __LINE__ = 0;
              var b/*_mochaSuper*/ = a/*Runtime*/.getSuper( g/*_mochaLocalTmp8*/ );
              
              function h/*constructor*/() {
                try {
                  __LINE__ = 71;
                  return b/*_mochaSuper*/.constructor.call( this );
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              __LINE__ = 0;
              a/*Runtime*/.createUnenumProp( h/*constructor*/,"__harmony_class__",1 );
              
              __LINE__ = 0;
              f/*Derive2*/.prototype.getAddr = function getAddr() {
                try {
                  __LINE__ = 0;
                  return a/*Runtime*/.getPrivateRecord( this ).addr;
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              a/*Runtime*/.createUnenumProp( f/*Derive2*/.prototype,"constructor",constructor );
              __LINE__ = 0;
              return f/*Derive2*/;
            } catch( e ){
              a.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })();
      
      __LINE__ = 76;
      var l/*TestClass*/ = ( function () {
            try {
              __LINE__ = 0;
              var b/*_mochaPrivateHolder*/ = function (){};
              
              __LINE__ = 85;
              function c/*_mochaLocalTmp10*/() {
                try {
                  __LINE__ = 0;
                  a/*Runtime*/.createPrivateRecord( this,_mochaPrivateHolder );
                  
                  __LINE__ = 0;
                  constructor.apply( this,arguments );
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              function d/*constructor*/( b/*_mochaLocalTmp11*/,c/*_mochaLocalTmp12*/ ) {
                try {
                  __LINE__ = 0;
                  a/*Runtime*/.getPrivateRecord( this )._name = b/*_mochaLocalTmp11*/ || "test";
                  
                  __LINE__ = 0;
                  a/*Runtime*/.getPrivateRecord( this )._age = c/*_mochaLocalTmp12*/ || 20;
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              __LINE__ = 0;
              a/*Runtime*/.createUnenumProp( d/*constructor*/,"__harmony_class__",1 );
              
              __LINE__ = 0;
              c/*_mochaLocalTmp10*/.prototype.getName = function getName() {
                try {
                  __LINE__ = 0;
                  return a/*Runtime*/.getPrivateRecord( this )._name;
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              c/*_mochaLocalTmp10*/.prototype.getAge = function getAge() {
                try {
                  __LINE__ = 0;
                  return a/*Runtime*/.getPrivateRecord( this )._age;
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 80;
              b/*_mochaPrivateHolder*/.prototype.Inner = ( function () {
                try {
                  __LINE__ = 0;
                  var b/*_mochaPrivateHolder*/ = function (){};
                  
                  __LINE__ = 80;
                  function c/*Inner*/() {
                    try {
                      __LINE__ = 0;
                      a/*Runtime*/.createPrivateRecord( this,_mochaPrivateHolder );
                      
                      __LINE__ = 0;
                      constructor.apply( this,arguments );
                    } catch( e ){
                      a.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  };
                  
                  function d/*constructor*/(){}
                  __LINE__ = 0;
                  a/*Runtime*/.createUnenumProp( d/*constructor*/,"__harmony_class__",1 );
                  
                  __LINE__ = 0;
                  a/*Runtime*/.createUnenumProp( c/*Inner*/.prototype,"constructor",constructor );
                  __LINE__ = 0;
                  return c/*Inner*/;
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              })();
              
              __LINE__ = 0;
              a/*Runtime*/.createUnenumProp( c/*_mochaLocalTmp10*/.prototype,"constructor",constructor );
              __LINE__ = 0;
              return c/*_mochaLocalTmp10*/;
            } catch( e ){
              a.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })();
      
      __LINE__ = 85;
      a/*Runtime*/.assert( true,new d/*DeriveTest*/().getName() === "hogehoge","new DeriveTest().getName() === \"hogehoge\"",85,'./class_test.js' );
      
      __LINE__ = 86;
      a/*Runtime*/.assert( true,d/*DeriveTest*/.getName() === "static hogehoge","DeriveTest.getName() === \"static hogehoge\"",86,'./class_test.js' );
      
      __LINE__ = 87;
      a/*Runtime*/.assert( true,new k/*Derive2*/().getAddr() === "tokyo","new Derive2().getAddr() === \"tokyo\"",87,'./class_test.js' );
      
      __LINE__ = 88;
      var m/*instance*/ = new l/*TestClass*/();
      
      __LINE__ = 89;
      a/*Runtime*/.assert( true,m/*instance*/.getName() === "test","instance.getName() === \"test\"",89,'./class_test.js' );
      
      __LINE__ = 90;
      a/*Runtime*/.assert( true,m/*instance*/.getAge() === 20,"instance.getAge() === 20",90,'./class_test.js' );
      
      __LINE__ = 0;
      var b/*TestTrait*/ =  {
            _mochaTraitPrivate :  {
              
            },
            _mochaTraitPublic :  {
              testm1 : function n/*testm1*/(  ) {
                try {
                  __LINE__ = 0;
                  var b/*arg*/ = a/*Runtime*/.toArray( arguments,0 );
                  __LINE__ = 94;
                  return b/*arg*/[0];
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
            },
            _mochaRequires :  {
              doTestm1 : true
            },
            _mochaTraitMark : true
          };
      
      __LINE__ = 0;
      var e/*TestTrait2*/ =  {
            _mochaTraitPrivate :  {
              
            },
            _mochaTraitPublic :  {
              testm2 : function o/*testm2*/(  ) {
                try {
                  __LINE__ = 0;
                  var b/*arg*/ = a/*Runtime*/.toArray( arguments,0 );
                  __LINE__ = 99;
                  return b/*arg*/[0];
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              },
              testm3 : function p/*testm3*/() {
                try {
                  __LINE__ = 100;
                  return "ok";
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
            },
            _mochaRequires :  {
              doTestm2 : true
            },
            _mochaTraitMark : true
          };
      
      __LINE__ = 103;
      var q/*MixinTest*/ = ( function () {
            try {
              __LINE__ = 0;
              var f/*_mochaPrivateHolder*/ = function (){};
              
              __LINE__ = 103;
              function g/*MixinTest*/() {
                try {
                  __LINE__ = 0;
                  a/*Runtime*/.createPrivateRecord( this,_mochaPrivateHolder );
                  
                  __LINE__ = 0;
                  constructor.apply( this,arguments );
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              function h/*constructor*/(){}
              __LINE__ = 0;
              a/*Runtime*/.createUnenumProp( h/*constructor*/,"__harmony_class__",1 );
              
              __LINE__ = 0;
              g/*MixinTest*/.prototype.doTestm1 = function doTestm1() {
                try {
                  __LINE__ = 104;
                  return "aaa";
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              g/*MixinTest*/.prototype.doTestm2 = function doTestm2() {
                try {
                  __LINE__ = 106;
                  return "bbb";
                } catch( e ){
                  a.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              a/*Runtime*/.classMixin( g/*MixinTest*/,f/*_mochaPrivateHolder*/,b/*TestTrait*/, {
                testm1 : "m1"
              },{});
              
              __LINE__ = 0;
              a/*Runtime*/.classMixin( g/*MixinTest*/,f/*_mochaPrivateHolder*/,e/*TestTrait2*/,{}, {
                testm2 : true,
                testm3 : true
              });
              
              __LINE__ = 0;
              a/*Runtime*/.checkRequirements( g/*MixinTest*/,f/*_mochaPrivateHolder*/,[b/*TestTrait*/,e/*TestTrait2*/],'./class_test.js',107 );
              
              __LINE__ = 0;
              a/*Runtime*/.createUnenumProp( g/*MixinTest*/.prototype,"constructor",constructor );
              __LINE__ = 0;
              return g/*MixinTest*/;
            } catch( e ){
              a.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })();
      
      __LINE__ = 109;
      var r/*instance2*/ = new q/*MixinTest*/();
      
      __LINE__ = 110;
      a/*Runtime*/.assert( true,r/*instance2*/.m1( "foo" ) === "foo","instance2.m1( \"foo\" ) === \"foo\"",110,'./class_test.js' );
      
      __LINE__ = 111;
      a/*Runtime*/.assert( true,r/*instance2*/.m2 === undefined,"instance2.m2 === undefined",111,'./class_test.js' );
    } catch( e ){
      a.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  })();
})();
