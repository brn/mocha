(function() {
  
  var b/*_mochaGlobalExport*/ = {};
  
  ( function ( f/*_mochaLocalTmp0*/,g/*_mochaLocalTmp1*/,h/*_mochaLocalTmp2*/,i/*_mochaLocalTmp3*/ ) {
    var c/*stringProto*/ = f/*_mochaLocalTmp0*/.prototype,
        d/*arrayProto*/ = g/*_mochaLocalTmp1*/.prototype,
        j/*functionProto*/ = h/*_mochaLocalTmp2*/.prototype,
        k/*dateProto*/ = i/*_mochaLocalTmp3*/.prototype;
    
    "use strict";
    
    function b/*builtinTypeError*/( a/*message*/ ) {
      try {
        throw new TypeError( a/*message*/ );
      } catch( e ){
        throw new Error( e );
      };
    };
    
    function e/*callbackCheck*/( c/*callback*/,d/*type*/ ) {
      
      if ( typeof c/*callback*/ !== "function" ){
        b/*builtinTypeError*/( d/*type*/+" : first argument is not callable" );
      };
    };
    
    if ( !Object.keys ){
      Object.keys = function ( a/*obj*/ ) {
        if ( !a/*obj*/ ){
          b/*builtinTypeError*/( "Object.keys : first arguments is null or not defined." );
        };
        
        var c/*ret*/ = [],
            d/*iter*/ = -1;
        
        for ( var e/*i*/ in a/*obj*/ ){
          if ( a/*obj*/.hasOwnProperty( e/*i*/ ) ){
            c/*ret*/[ ++ d/*iter*/] = a/*obj*/[e/*i*/];
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
    
    var l/*hasRealEcma5*/ = ( function () {
          var a/*ret*/;
          
          try {
            var b/*obj*/ = {};
            
            Object.defineProperty( b/*obj*/,"test", {
              configurable : false,
              writable : false,
              enumerable : false,
              value : 0
            });
            
            b/*obj*/.test = 200;
            
            a/*ret*/ = ( b/*obj*/.test === 200 )?false : true;
          } catch( e ){
            a/*ret*/ = false;
          };
          return a/*ret*/;
        })();
    
    if ( !l/*hasRealEcma5*/ ){
      Object.defineProperty = function ( a/*obj*/,b/*prop*/,c/*valobj*/ ) {
        if ( c/*valobj*/.value ){
          a/*obj*/[b/*prop*/] = c/*valobj*/.value;
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
        value : function m/*value*/( a/*num*/ ) {
          return Array( a/*num*/+1 ).join( this.toString() );
        },
        configurable : true,
        enumerable : false,
        writable : true
      });
    };
    
    if ( !c/*stringProto*/.startsWith ){
      Object.defineProperty( c/*stringProto*/,"startsWith", {
        value : function m/*value*/( a/*str*/ ) {
          return !this.indexOf( a/*str*/ );
        },
        configurable : true,
        enumerable : false,
        writable : true
      });
    };
    
    if ( !c/*stringProto*/.endsWith ){
      Object.defineProperty( c/*stringProto*/,"endsWith", {
        value : function m/*value*/( a/*str*/ ) {
          var b/*t*/ = String( a/*str*/ );
          
          var c/*index*/ = this.lastIndexOf( b/*t*/ );
          return c/*index*/ >= 0 && c/*index*/ === this.length-b/*t*/.length;
        },
        configurable : true,
        enumerable : false,
        writable : true
      });
    };
    
    if ( !c/*stringProto*/.contains ){
      Object.defineProperty( c/*stringProto*/,"contains", {
        value : function m/*value*/( a/*str*/ ) {
          return this.indexOf( a/*str*/ ) !== -1;
        },
        configurable : true,
        enumerable : false,
        writable : true
      });
    };
    
    if ( !c/*stringProto*/.toArray ){
      Object.defineProperty( c/*stringProto*/,"toArray", {
        value : function m/*value*/( a/*str*/ ) {
          return this.split( "" );
        },
        configurable : true,
        enumerable : false,
        writable : true
      });
    };
    
    if ( !j/*functionProto*/.bind ){
      j/*functionProto*/.bind = function () {
        var a/*argArray*/ = d/*arrayProto*/.slice.call( arguments ),
            c/*context*/ = a/*argArray*/.shift(),
            b/*ret*/ = function () {
              var e/*args*/ = a/*argArray*/.concat( d/*arrayProto*/.slice.call( arguments ) );
              
              if ( this !== null && this !== window && this instanceof b/*ret*/ ){
                return b/*ret*/.context.apply( this,e/*args*/ );
              } else {
                return b/*ret*/.context.apply( c/*context*/,e/*args*/ );
              };
            };
        
        b/*ret*/.prototype = this.prototype;
        
        b/*ret*/.context = this;
        return b/*ret*/;
      };
    };
    
    if ( !d/*arrayProto*/.forEach ){
      d/*arrayProto*/.forEach = function ( f/*callback*/,g/*that*/ ) {
        e/*callbackCheck*/( f/*callback*/,"Array.forEach" );
        
        var h/*iter*/ = -1,
            i/*ta*/;
        
        if ( this === null ){
          b/*builtinTypeError*/( "Array.forEach : this is null or not defined" );
        };
        
        if ( g/*that*/ ){
          while ( ( i/*ta*/ = this[ ++ h/*iter*/] ) !== null && i/*ta*/ !== undefined ){
            f/*callback*/.call( g/*that*/,i/*ta*/,h/*iter*/,this );
          };
        } else {
          while ( ( i/*ta*/ = this[ ++ h/*iter*/] ) !== null && i/*ta*/ !== undefined ){
            f/*callback*/( i/*ta*/,h/*iter*/,this );
          };
        };
      };
    };
    
    if ( !d/*arrayProto*/.every ){
      d/*arrayProto*/.every = function ( a/*callback*/,c/*that*/ ) {
        e/*callbackCheck*/( a/*callback*/,"Array.every" );
        
        var d/*iter*/ = -1,
            f/*ta*/;
        
        if ( this === null ){
          b/*builtinTypeError*/( "Array.every : this is null or not defined" );
        };
        
        if ( c/*that*/ ){
          while ( ( f/*ta*/ = this[ ++ d/*iter*/] ) !== null && f/*ta*/ !== undefined ){
            if ( !( a/*callback*/.call( c/*that*/,f/*ta*/,d/*iter*/,this ) ) ){
              return false;
            };
          };
        } else {
          while ( ( f/*ta*/ = this[ ++ d/*iter*/] ) !== null && f/*ta*/ !== undefined ){
            if ( !( a/*callback*/( f/*ta*/,d/*iter*/,this ) ) ){
              return false;
            };
          };
        };
        return true;
      };
    };
    
    if ( !d/*arrayProto*/.some ){
      d/*arrayProto*/.some = function ( a/*callback*/,c/*that*/ ) {
        e/*callbackCheck*/( a/*callback*/,"Array.some" );
        
        var d/*iter*/ = -1,
            f/*ta*/;
        
        if ( this === null ){
          b/*builtinTypeError*/( "Array.some : this is null or not defined" );
        };
        
        if ( c/*that*/ ){
          while ( ( f/*ta*/ = this[ ++ d/*iter*/] ) !== null && f/*ta*/ !== undefined ){
            if ( a/*callback*/.call( c/*that*/,f/*ta*/,d/*iter*/,this ) ){
              return true;
            };
          };
        } else {
          while ( ( f/*ta*/ = this[ ++ d/*iter*/] ) !== null && f/*ta*/ !== undefined ){
            if ( a/*callback*/( f/*ta*/,d/*iter*/,this ) ){
              return true;
            };
          };
        };
        return false;
      };
    };
    
    if ( !d/*arrayProto*/.filter ){
      d/*arrayProto*/.filter = function ( a/*callback*/,c/*that*/ ) {
        e/*callbackCheck*/( a/*callback*/,"Array.filter" );
        
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
              if ( a/*callback*/.call( c/*that*/,h/*ta*/,i/*i*/,this ) ){
                g/*ret*/[ ++ f/*iter*/] = h/*ta*/;
              };
            };
          };
        } else {
          for ( var i/*i*/ = 0,d/*len*/ = this.length;i/*i*/<d/*len*/; ++ i/*i*/ ){
            if ( ( h/*ta*/ = this[i/*i*/] ) !== null && h/*ta*/ !== undefined ){
              if ( a/*callback*/( h/*ta*/,i/*i*/,this ) ){
                g/*ret*/[ ++ f/*iter*/] = h/*ta*/;
              };
            };
          };
        };
        return g/*ret*/;
      };
    };
    
    if ( !d/*arrayProto*/.indexOf ){
      d/*arrayProto*/.indexOf = function ( a/*subject*/,c/*fromIndex*/ ) {
        var d/*iter*/ = ( c/*fromIndex*/ )?c/*fromIndex*/-1 : -1,
            e/*index*/ = -1,
            f/*ta*/;
        
        if ( this === null ){
          b/*builtinTypeError*/( "Array.indexOf : this is null or not defined." );
        };
        
        while ( ( f/*ta*/ = this[ ++ d/*iter*/] ) !== null && f/*ta*/ !== undefined ){
          if ( f/*ta*/ === a/*subject*/ ){
            e/*index*/ = d/*iter*/;
            break;
          };
        };
        return e/*index*/;
      };
    };
    
    if ( !d/*arrayProto*/.lastIndexOf ){
      d/*arrayProto*/.lastIndexOf = function ( a/*target*/,c/*fromIndex*/ ) {
        var d/*len*/ = this.length,
            e/*iter*/ = ( c/*fromIndex*/ )?c/*fromIndex*/+1 : d/*len*/,
            f/*index*/ = -1,
            g/*ta*/;
        
        if ( this === null ){
          b/*builtinTypeError*/( "Array.lastIndexOf : this is null or not defined." );
        };
        
        while ( ( g/*ta*/ = this[ -- e/*iter*/] ) !== null && g/*ta*/ !== undefined ){
          if ( g/*ta*/ === a/*target*/ ){
            f/*index*/ = e/*iter*/;
            break;
          };
        };
        return f/*index*/;
      };
    };
    
    if ( !d/*arrayProto*/.map ){
      d/*arrayProto*/.map = function ( a/*callback*/,c/*that*/ ) {
        e/*callbackCheck*/( a/*callback*/,"Array.map" );
        
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
              d/*ret*/[ ++ f/*iter*/] = a/*callback*/.call( c/*that*/,i/*ta*/,h/*i*/,this );
            };
          };
        } else {
          for ( h/*i*/;h/*i*/<g/*len*/; ++ h/*i*/ ){
            if ( ( i/*ta*/ = this[h/*i*/] ) !== null && i/*ta*/ !== undefined ){
              d/*ret*/[ ++ f/*iter*/] = a/*callback*/( i/*ta*/,h/*i*/,this );
            };
          };
        };
        return d/*ret*/;
      };
    };
    
    if ( !d/*arrayProto*/.reduce ){
      d/*arrayProto*/.reduce = function ( a/*callback*/,c/*initial*/ ) {
        e/*callbackCheck*/( a/*callback*/,"Array.reduce" );
        
        var d/*ret*/ = c/*initial*/ || this[0],
            f/*i*/ = ( c/*initial*/ )?0 : 1,
            g/*len*/ = this.length,
            h/*ta*/;
        
        if ( ( g/*len*/ === 0 || g/*len*/ === null ) && arguments.length<2 ){
          b/*builtinTypeError*/( "Array length is 0 and no second argument" );
        };
        
        for ( f/*i*/;f/*i*/<g/*len*/; ++ f/*i*/ ){
          if ( ( h/*ta*/ = this[f/*i*/] ) !== null && h/*ta*/ !== undefined ){
            d/*ret*/ = a/*callback*/( d/*ret*/,h/*ta*/,f/*i*/,this );
          };
        };
        return d/*ret*/;
      };
    };
    
    if ( !d/*arrayProto*/.reduceRight ){
      d/*arrayProto*/.reduceRight = function ( a/*callback*/,c/*initial*/ ) {
        e/*callbackCheck*/( a/*callback*/,"Array.reduceRight" );
        
        var d/*len*/ = this.length,
            f/*ret*/ = c/*initial*/ || this[d/*len*/-1],
            g/*i*/ = ( c/*initial*/ )?d/*len*/-1 : d/*len*/-2,
            h/*ta*/;
        
        if ( ( d/*len*/ === 0 || d/*len*/ === null ) && arguments.length<2 ){
          b/*builtinTypeError*/( "Array length is 0 and no second argument" );
        };
        
        for ( g/*i*/;g/*i*/>-1; -- g/*i*/ ){
          if ( ( h/*ta*/ = this[g/*i*/] ) !== null && h/*ta*/ !== undefined ){
            f/*ret*/ = a/*callback*/( f/*ret*/,h/*ta*/,g/*i*/,this );
          };
        };
        return f/*ret*/;
      };
    };
    
    if ( !k/*dateProto*/.toJSON ){
      k/*dateProto*/.toJSON = function () {
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
      Array.isArray = function ( a/*arr*/ ) {
        if ( arguments.length === 0 ){
          return false;
        };
        return ( a/*arr*/ )?Object.prototype.toString.call( a/*arr*/ ) === "[object Array]" : false;
      };
    };
  }).call( this,String,Array,Function,Date );
  
  var a/*Runtime*/ = ( function Runtime() {
        var p/*_mochaLocalExport*/ = {};
        
        "use strict";
        
        function c/*Exception*/( d/*line*/,c/*file*/,b/*e*/ ) {
          this.toString = function () {
            return a/*Runtime*/.getErrorMessage( b/*e*/ )+" in file "+c/*file*/+" at : "+d/*line*/;
          };
        }
        var g/*fastMax*/ = Math.max;
        
        var a/*Runtime*/ =  {
              getErrorMessage : function q/*getErrorMessage*/( a/*e*/ ) {
                return ( a/*e*/.message )?a/*e*/.message : ( a/*e*/.description )?a/*e*/.description : a/*e*/.toString();
              },
              exceptionHandler : function r/*exceptionHandler*/( d/*line*/,e/*file*/,f/*e*/ ) {
                if ( b/*isStopIteration*/( f/*e*/ ) ){
                  this.throwException( f/*e*/ );
                } else {
                  this.throwException( new c/*Exception*/( d/*line*/,e/*file*/,f/*e*/ ) );
                };
              },
              throwException : function s/*throwException*/( a/*exception*/ ) {
                try {
                  throw a/*exception*/;
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
        
        var f/*createUnenumProp*/ = p/*_mochaLocalExport*/.createUnenumProp = function f/*createUnenumProp*/( a/*obj*/,b/*prop*/,c/*value*/ ) {
              return Object.defineProperty( a/*obj*/,b/*prop*/, {
                configurable : true,
                enumerable : false,
                writable : true,
                value : c/*value*/
              });
            };
        
        var t/*constant*/ = p/*_mochaLocalExport*/.constant = function t/*constant*/( a/*obj*/,b/*prop*/,c/*value*/ ) {
              return Object.defineProperty( a/*obj*/,b/*prop*/, {
                configurable : false,
                enumerable : false,
                writable : false,
                value : c/*value*/
              });
            };
        
        var u/*toArray*/ = p/*_mochaLocalExport*/.toArray = function u/*toArray*/( e/*likeArray*/,f/*index*/ ) {
              return ( e/*likeArray*/ )?d/*slice*/.call( e/*likeArray*/,f/*index*/ ) : [];
            };
        
        var e/*Generator*/ = function (){};
        
        var v/*createGenerator*/ = p/*_mochaLocalExport*/.createGenerator = function v/*createGenerator*/( g/*generatorFn*/,h/*closeFn*/,i/*context*/ ) {
              var j/*ret*/ = new e/*Generator*/;
              
              f/*createUnenumProp*/( j/*ret*/,"next",g/*generatorFn*/.bind( i/*context*/,false,false ) );
              
              f/*createUnenumProp*/( j/*ret*/,"send",g/*generatorFn*/.bind( i/*context*/,true,false ) );
              
              f/*createUnenumProp*/( j/*ret*/,"close",h/*closeFn*/.bind( i/*context*/ ) );
              
              f/*createUnenumProp*/( j/*ret*/,"__nothrowNext__",g/*generatorFn*/.bind( i/*context*/,false,true ) );
              
              f/*createUnenumProp*/( j/*ret*/,"toString",
              function () {
                return "[object Generator]";
              });
              
              Object.freeze( j/*ret*/ );
              return j/*ret*/;
            };
        
        function q/*getErrorMessage*/( a/*e*/ ) {
          return ( a/*e*/.message )?a/*e*/.message : ( a/*e*/.description )?a/*e*/.description : a/*e*/.toString();
        }
        var s/*throwException*/ = p/*_mochaLocalExport*/.throwException = a/*Runtime*/.throwException.bind( a/*Runtime*/ );
        
        var r/*exceptionHandler*/ = p/*_mochaLocalExport*/.exceptionHandler = a/*Runtime*/.exceptionHandler.bind( a/*Runtime*/ );
        
        var w/*extend*/ = p/*_mochaLocalExport*/.extend = function w/*extend*/( a/*dest*/,b/*source*/ ) {
              for ( var c/*prop*/ in b/*source*/ ){
                a/*dest*/[c/*prop*/] = b/*source*/[c/*prop*/];
              };
              return a/*dest*/;
            };
        
        function h/*compareTuple*/( h/*tuple*/ ) {
          var i/*max*/ = g/*fastMax*/( h/*tuple*/.length,this.length ),
              j/*i*/ = -1;
          
          while (  ++ j/*i*/<i/*max*/ && h/*tuple*/[j/*i*/] === this[j/*i*/] ){
            
          };
          return i/*max*/ === j/*i*/;
        };
        
        function i/*tupleToArray*/() {
          return Array.prototype.slice.call( this );
        };
        
        var x/*createTuple*/ = p/*_mochaLocalExport*/.createTuple = function x/*createTuple*/( j/*obj*/,k/*size*/ ) {
              f/*createUnenumProp*/( j/*obj*/,"length",k/*size*/ );
              
              f/*createUnenumProp*/( j/*obj*/,"equal",h/*compareTuple*/ );
              
              f/*createUnenumProp*/( j/*obj*/,"toArray",i/*tupleToArray*/ );
              
              f/*createUnenumProp*/( j/*obj*/,"toString",
              function () {
                return "[object Tuple]";
              });
              return Object.freeze( j/*obj*/ );
            };
        
        var y/*createRecord*/ = p/*_mochaLocalExport*/.createRecord = function y/*createRecord*/( a/*obj*/ ) {
              if ( a/*obj*/.toString() === "[object Object]" ){
                f/*createUnenumProp*/( a/*obj*/,"toString",
                function () {
                  return "[object Record]";
                });
              };
              return Object.freeze( a/*obj*/ );
            };
        
        var z/*extendPrototype*/ = p/*_mochaLocalExport*/.extendPrototype = function ( a/*derived*/,b/*base*/ ) {
              a/*derived*/.prototype = b/*base*/;
            };
        
        var j/*getPrototype*/ = ( "getPrototypeOf" in Object )?function ( a/*obj*/ ) {
              return Object.getPrototypeOf( a/*obj*/ );
            } : function ( a/*obj*/ ) {
              var b/*ret*/ = {};
              
              for ( var c/*i*/ in a/*obj*/ ){
                if ( !a/*obj*/.hasOwnProperty( c/*i*/ ) ){
                  b/*ret*/[c/*i*/] = a/*obj*/[c/*i*/];
                };
              };
              return b/*ret*/;
            };
        
        var A/*extendClass*/ = p/*_mochaLocalExport*/.extendClass = ( a/*Runtime*/.hasProto )?function ( a/*derived*/,b/*base*/ ) {
              if ( typeof b/*base*/ === 'function' ){
                a/*derived*/.prototype.__proto__ = b/*base*/.prototype;
                
                for ( var c/*i*/ in b/*base*/ ){
                  a/*derived*/[c/*i*/] = b/*base*/[c/*i*/];
                };
              } else {
                a/*derived*/.prototype.__proto__ = b/*base*/.__proto__;
              };
            } : function ( k/*derived*/,l/*base*/ ) {
              var m/*baseType*/ = typeof l/*base*/;
              
              if ( m/*baseType*/ === "function" ){
                var n/*inherit*/ = function (){};
                
                n/*inherit*/.prototype = l/*base*/.prototype;
                
                k/*derived*/.prototype = new n/*inherit*/;
                
                for ( var o/*i*/ in l/*base*/ ){
                  k/*derived*/[o/*i*/] = l/*base*/[o/*i*/];
                };
              } else {
                var n/*inherit*/ = function (){},
                    p/*proto*/ = j/*getPrototype*/( l/*base*/ );
                
                n/*inherit*/.prototype = p/*proto*/;
                
                k/*derived*/.prototype = new n/*inherit*/;
              };
            };
        
        var k/*__ref_iterator__*/ = p/*_mochaLocalExport*/.__ref_iterator__ = "__mocha_iterator_special_key__";
        
        var m/*throwStopIteration*/ = p/*_mochaLocalExport*/.throwStopIteration = function m/*throwStopIteration*/() {
              try {
                throw StopIteration;
              } catch( e ){
                throw new Error( e.toString() );
              };
            };
        
        var l/*isGenerator*/ = p/*_mochaLocalExport*/.isGenerator = function l/*isGenerator*/( a/*obj*/ ) {
              return a/*obj*/ instanceof e/*Generator*/;
            };
        
        var B/*getIterator*/ = p/*_mochaLocalExport*/.getIterator = function B/*getIterator*/( n/*obj*/ ) {
              var a/*ret*/ = n/*obj*/[k/*__ref_iterator__*/](),
                  o/*newObj*/;
              
              if ( l/*isGenerator*/( a/*ret*/ ) ){
                return a/*ret*/;
              };
              
              o/*newObj*/ = {};
              
              if ( a/*ret*/.next ){
                f/*createUnenumProp*/( o/*newObj*/,"next",
                function () {
                  var b/*result*/ = a/*ret*/.next();
                  
                  if ( b/*result*/ === undefined ){
                    m/*throwStopIteration*/();
                  };
                  return b/*result*/;
                });
              } else {
                return {};
              };
              
              if ( !( "__nothrowNext__" in a/*ret*/ ) ){
                f/*createUnenumProp*/( o/*newObj*/,"__nothrowNext__",a/*ret*/.next.bind( a/*ret*/ ) );
              };
              
              for ( var p/*prop*/ in a/*ret*/ ){
                if ( p/*prop*/ !== "next" && p/*prop*/ !== "__nothrowNext__" ){
                  o/*newObj*/[p/*prop*/] = a/*ret*/[p/*prop*/];
                };
              };
              
              if ( !( "toString" in a/*ret*/ ) ){
                f/*createUnenumProp*/( o/*newObj*/,"toString",
                function () {
                  return "[object Iterator]";
                });
              };
              return o/*newObj*/;
            };
        
        var C/*hasIterator*/ = p/*_mochaLocalExport*/.hasIterator = function C/*hasIterator*/( a/*obj*/ ) {
              return k/*__ref_iterator__*/ in a/*obj*/;
            };
        
        var n/*rstopIteration*/ = /StopIteration/;
        
        var b/*isStopIteration*/ = p/*_mochaLocalExport*/.isStopIteration = function b/*isStopIteration*/( o/*obj*/ ) {
              return o/*obj*/ === StopIteration || n/*rstopIteration*/.test( o/*obj*/ );
            };
        
        var o/*privateRecord*/,
            D/*createPrivateRecord*/,
            E/*getPrivateRecord*/;
        
        if ( "WeakMap" in window ){
          o/*privateRecord*/ = new WeakMap();
          
          D/*createPrivateRecord*/ = function ( self,p/*privateHolder*/ ) {
            var q/*holder*/ = new p/*privateHolder*/;
            
            f/*createUnenumProp*/( q/*holder*/.constructor,"__is_private__",1 );
            
            o/*privateRecord*/.set( self,q/*holder*/ );
          };
          
          E/*getPrivateRecord*/ = function ( self ) {
            if ( o/*privateRecord*/.has( self ) ){
              return o/*privateRecord*/.get( self );
            } else if ( self.constructor === "__is_private__" ){
              return self;
            };
          };
        } else {
          D/*createPrivateRecord*/ = function ( self,a/*privateHolder*/ ) {
            if ( !self.__typeid__ ){
              var b/*holder*/ = new a/*privateHolder*/;
              
              f/*createUnenumProp*/( b/*holder*/.constructor,"__is_private__",1 );
              
              f/*createUnenumProp*/( self,"__private__",b/*holder*/ );
            };
          };
          
          E/*getPrivateRecord*/ = function ( self ) {
            if ( self.__private__ ){
              return self.__private__;
            } else if ( self.constructor === "__is_private__" ){
              return self;
            };
          };
        };
        
        p/*_mochaLocalExport*/.createPrivateRecord = D/*createPrivateRecord*/;
        
        p/*_mochaLocalExport*/.getPrivateRecord = E/*getPrivateRecord*/;
        
        var F/*getSuper*/ = p/*_mochaLocalExport*/.getSuper = function F/*getSuper*/( a/*obj*/ ) {
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
        
        var G/*traitMixin*/ = p/*_mochaLocalExport*/.traitMixin = function G/*traitMixin*/( b/*dest*/,c/*source*/,d/*with_*/,e/*without*/ ) {
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
        
        var H/*classMixin*/ = p/*_mochaLocalExport*/.classMixin = function H/*classMixin*/( b/*_mochaLocalTmp5*/,c/*_mochaLocalTmp6*/,d/*_mochaLocalTmp7*/,e/*with_*/,f/*without*/ ) {
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
        
        var I/*checkRequirements*/ = p/*_mochaLocalExport*/.checkRequirements = function I/*checkRequirements*/( b/*_mochaLocalTmp8*/,c/*_mochaLocalTmp9*/,d/*traits*/,e/*file*/,f/*line*/ ) {
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
        return p/*_mochaLocalExport*/;
      })();
  
  if ( !( "StopIteration" in window ) ){
    window.StopIteration =  {
      toString : function c/*toString*/() {
        return "[object StopIteration]";
      }
    };
  };
  
  ( function () {
    b/*_mochaGlobalExport*/['./name_test.js'] = {};
    
    var c/*_mochaGlobalAlias*/ = b/*_mochaGlobalExport*/['./name_test.js'];
    
    function a/*b*/(){}
    ( function () {
      var b/*c*/ = 0;
      
      var c/*test1*/ = function () {
            a/*b*/();
          };
      
      var d/*test2*/ = function () {
            var b/*c*/,
                c/*l*/;
            
            c/*l*/ = a/*b*/();
          };
    })();
  })();
})();
