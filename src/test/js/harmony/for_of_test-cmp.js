(function() {
  
  var D/*_mochaGlobalExport*/ = {};
  
  ( function ( x/*_mochaLocalTmp0*/,y/*_mochaLocalTmp1*/,z/*_mochaLocalTmp2*/,A/*_mochaLocalTmp3*/ ) {
    var n/*stringProto*/ = x/*_mochaLocalTmp0*/.prototype,
        o/*arrayProto*/ = y/*_mochaLocalTmp1*/.prototype,
        B/*functionProto*/ = z/*_mochaLocalTmp2*/.prototype,
        C/*dateProto*/ = A/*_mochaLocalTmp3*/.prototype;
    
    "use strict";
    
    function m/*builtinTypeError*/( b/*message*/ ) {
      try {
        throw new TypeError( b/*message*/ );
      } catch( e ){
        throw new Error( e );
      };
    };
    
    function s/*callbackCheck*/( n/*callback*/,o/*type*/ ) {
      
      if ( typeof n/*callback*/ !== "function" ){
        m/*builtinTypeError*/( o/*type*/+" : first argument is not callable" );
      };
    };
    
    if ( !Object.keys ){
      Object.keys = function ( e/*obj*/ ) {
        if ( !e/*obj*/ ){
          m/*builtinTypeError*/( "Object.keys : first arguments is null or not defined." );
        };
        
        var f/*ret*/ = [],
            g/*iter*/ = -1;
        
        for ( var h/*i*/ in e/*obj*/ ){
          if ( e/*obj*/.hasOwnProperty( h/*i*/ ) ){
            f/*ret*/[ ++ g/*iter*/] = e/*obj*/[h/*i*/];
          };
        };
        return f/*ret*/;
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
    
    var D/*hasRealEcma5*/ = ( function () {
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
    
    if ( !D/*hasRealEcma5*/ ){
      Object.defineProperty = function ( d/*obj*/,e/*prop*/,f/*valobj*/ ) {
        if ( f/*valobj*/.value ){
          d/*obj*/[e/*prop*/] = f/*valobj*/.value;
        };
      };
    };
    
    if ( !n/*stringProto*/.trim ){
      n/*stringProto*/.trim = function () {
        return this.replace( n/*stringProto*/.trim.rtrim,"" );
      };
      
      n/*stringProto*/.trim.rtrim = /^\s*|\s*$/g;
    };
    
    if ( !n/*stringProto*/.repeat ){
      Object.defineProperty( n/*stringProto*/,"repeat", {
        value : function E/*value*/( b/*num*/ ) {
          return Array( b/*num*/+1 ).join( this.toString() );
        },
        configurable : true,
        enumerable : false,
        writable : true
      });
    };
    
    if ( !n/*stringProto*/.startsWith ){
      Object.defineProperty( n/*stringProto*/,"startsWith", {
        value : function E/*value*/( b/*str*/ ) {
          return !this.indexOf( b/*str*/ );
        },
        configurable : true,
        enumerable : false,
        writable : true
      });
    };
    
    if ( !n/*stringProto*/.endsWith ){
      Object.defineProperty( n/*stringProto*/,"endsWith", {
        value : function E/*value*/( d/*str*/ ) {
          var e/*t*/ = String( d/*str*/ );
          
          var f/*index*/ = this.lastIndexOf( e/*t*/ );
          return f/*index*/ >= 0 && f/*index*/ === this.length-e/*t*/.length;
        },
        configurable : true,
        enumerable : false,
        writable : true
      });
    };
    
    if ( !n/*stringProto*/.contains ){
      Object.defineProperty( n/*stringProto*/,"contains", {
        value : function E/*value*/( b/*str*/ ) {
          return this.indexOf( b/*str*/ ) !== -1;
        },
        configurable : true,
        enumerable : false,
        writable : true
      });
    };
    
    if ( !n/*stringProto*/.toArray ){
      Object.defineProperty( n/*stringProto*/,"toArray", {
        value : function E/*value*/( a/*str*/ ) {
          return this.split( "" );
        },
        configurable : true,
        enumerable : false,
        writable : true
      });
    };
    
    if ( !B/*functionProto*/.bind ){
      B/*functionProto*/.bind = function () {
        var a/*argArray*/ = o/*arrayProto*/.slice.call( arguments ),
            d/*context*/ = a/*argArray*/.shift(),
            b/*ret*/ = function () {
              var e/*args*/ = a/*argArray*/.concat( o/*arrayProto*/.slice.call( arguments ) );
              
              if ( this !== null && this !== window && this instanceof b/*ret*/ ){
                return b/*ret*/.context.apply( this,e/*args*/ );
              } else {
                return b/*ret*/.context.apply( d/*context*/,e/*args*/ );
              };
            };
        
        b/*ret*/.prototype = this.prototype;
        
        b/*ret*/.context = this;
        return b/*ret*/;
      };
    };
    
    if ( !o/*arrayProto*/.forEach ){
      o/*arrayProto*/.forEach = function ( x/*callback*/,y/*that*/ ) {
        s/*callbackCheck*/( x/*callback*/,"Array.forEach" );
        
        var z/*iter*/ = -1,
            A/*ta*/;
        
        if ( this === null ){
          m/*builtinTypeError*/( "Array.forEach : this is null or not defined" );
        };
        
        if ( y/*that*/ ){
          while ( ( A/*ta*/ = this[ ++ z/*iter*/] ) !== null && A/*ta*/ !== undefined ){
            x/*callback*/.call( y/*that*/,A/*ta*/,z/*iter*/,this );
          };
        } else {
          while ( ( A/*ta*/ = this[ ++ z/*iter*/] ) !== null && A/*ta*/ !== undefined ){
            x/*callback*/( A/*ta*/,z/*iter*/,this );
          };
        };
      };
    };
    
    if ( !o/*arrayProto*/.every ){
      o/*arrayProto*/.every = function ( e/*callback*/,f/*that*/ ) {
        s/*callbackCheck*/( e/*callback*/,"Array.every" );
        
        var g/*iter*/ = -1,
            h/*ta*/;
        
        if ( this === null ){
          m/*builtinTypeError*/( "Array.every : this is null or not defined" );
        };
        
        if ( f/*that*/ ){
          while ( ( h/*ta*/ = this[ ++ g/*iter*/] ) !== null && h/*ta*/ !== undefined ){
            if ( !( e/*callback*/.call( f/*that*/,h/*ta*/,g/*iter*/,this ) ) ){
              return false;
            };
          };
        } else {
          while ( ( h/*ta*/ = this[ ++ g/*iter*/] ) !== null && h/*ta*/ !== undefined ){
            if ( !( e/*callback*/( h/*ta*/,g/*iter*/,this ) ) ){
              return false;
            };
          };
        };
        return true;
      };
    };
    
    if ( !o/*arrayProto*/.some ){
      o/*arrayProto*/.some = function ( e/*callback*/,f/*that*/ ) {
        s/*callbackCheck*/( e/*callback*/,"Array.some" );
        
        var g/*iter*/ = -1,
            h/*ta*/;
        
        if ( this === null ){
          m/*builtinTypeError*/( "Array.some : this is null or not defined" );
        };
        
        if ( f/*that*/ ){
          while ( ( h/*ta*/ = this[ ++ g/*iter*/] ) !== null && h/*ta*/ !== undefined ){
            if ( e/*callback*/.call( f/*that*/,h/*ta*/,g/*iter*/,this ) ){
              return true;
            };
          };
        } else {
          while ( ( h/*ta*/ = this[ ++ g/*iter*/] ) !== null && h/*ta*/ !== undefined ){
            if ( e/*callback*/( h/*ta*/,g/*iter*/,this ) ){
              return true;
            };
          };
        };
        return false;
      };
    };
    
    if ( !o/*arrayProto*/.filter ){
      o/*arrayProto*/.filter = function ( h/*callback*/,i/*that*/ ) {
        s/*callbackCheck*/( h/*callback*/,"Array.filter" );
        
        var j/*len*/ = this.length,
            k/*iter*/ = -1,
            l/*ret*/ = [],
            n/*ta*/;
        
        if ( this === null ){
          m/*builtinTypeError*/( "Array.filter : this is null or not defined" );
        };
        
        if ( i/*that*/ ){
          for ( var o/*i*/ = 0,j/*len*/ = this.length;o/*i*/<j/*len*/; ++ o/*i*/ ){
            if ( ( n/*ta*/ = this[o/*i*/] ) !== null && n/*ta*/ !== undefined ){
              if ( h/*callback*/.call( i/*that*/,n/*ta*/,o/*i*/,this ) ){
                l/*ret*/[ ++ k/*iter*/] = n/*ta*/;
              };
            };
          };
        } else {
          for ( var o/*i*/ = 0,j/*len*/ = this.length;o/*i*/<j/*len*/; ++ o/*i*/ ){
            if ( ( n/*ta*/ = this[o/*i*/] ) !== null && n/*ta*/ !== undefined ){
              if ( h/*callback*/( n/*ta*/,o/*i*/,this ) ){
                l/*ret*/[ ++ k/*iter*/] = n/*ta*/;
              };
            };
          };
        };
        return l/*ret*/;
      };
    };
    
    if ( !o/*arrayProto*/.indexOf ){
      o/*arrayProto*/.indexOf = function ( f/*subject*/,g/*fromIndex*/ ) {
        var h/*iter*/ = ( g/*fromIndex*/ )?g/*fromIndex*/-1 : -1,
            i/*index*/ = -1,
            j/*ta*/;
        
        if ( this === null ){
          m/*builtinTypeError*/( "Array.indexOf : this is null or not defined." );
        };
        
        while ( ( j/*ta*/ = this[ ++ h/*iter*/] ) !== null && j/*ta*/ !== undefined ){
          if ( j/*ta*/ === f/*subject*/ ){
            i/*index*/ = h/*iter*/;
            break;
          };
        };
        return i/*index*/;
      };
    };
    
    if ( !o/*arrayProto*/.lastIndexOf ){
      o/*arrayProto*/.lastIndexOf = function ( g/*target*/,h/*fromIndex*/ ) {
        var i/*len*/ = this.length,
            j/*iter*/ = ( h/*fromIndex*/ )?h/*fromIndex*/+1 : i/*len*/,
            k/*index*/ = -1,
            l/*ta*/;
        
        if ( this === null ){
          m/*builtinTypeError*/( "Array.lastIndexOf : this is null or not defined." );
        };
        
        while ( ( l/*ta*/ = this[ -- j/*iter*/] ) !== null && l/*ta*/ !== undefined ){
          if ( l/*ta*/ === g/*target*/ ){
            k/*index*/ = j/*iter*/;
            break;
          };
        };
        return k/*index*/;
      };
    };
    
    if ( !o/*arrayProto*/.map ){
      o/*arrayProto*/.map = function ( h/*callback*/,i/*that*/ ) {
        s/*callbackCheck*/( h/*callback*/,"Array.map" );
        
        var j/*ret*/ = [],
            k/*iter*/ = -1,
            l/*len*/ = this.length,
            n/*i*/ = 0,
            o/*ta*/;
        
        if ( this === null ){
          m/*builtinTypeError*/( "Array.map : this is null or not defined." );
        };
        
        if ( i/*that*/ ){
          for ( n/*i*/;n/*i*/<l/*len*/; ++ n/*i*/ ){
            if ( ( o/*ta*/ = this[n/*i*/] ) !== null && o/*ta*/ !== undefined ){
              j/*ret*/[ ++ k/*iter*/] = h/*callback*/.call( i/*that*/,o/*ta*/,n/*i*/,this );
            };
          };
        } else {
          for ( n/*i*/;n/*i*/<l/*len*/; ++ n/*i*/ ){
            if ( ( o/*ta*/ = this[n/*i*/] ) !== null && o/*ta*/ !== undefined ){
              j/*ret*/[ ++ k/*iter*/] = h/*callback*/( o/*ta*/,n/*i*/,this );
            };
          };
        };
        return j/*ret*/;
      };
    };
    
    if ( !o/*arrayProto*/.reduce ){
      o/*arrayProto*/.reduce = function ( g/*callback*/,h/*initial*/ ) {
        s/*callbackCheck*/( g/*callback*/,"Array.reduce" );
        
        var i/*ret*/ = h/*initial*/ || this[0],
            j/*i*/ = ( h/*initial*/ )?0 : 1,
            k/*len*/ = this.length,
            l/*ta*/;
        
        if ( ( k/*len*/ === 0 || k/*len*/ === null ) && arguments.length<2 ){
          m/*builtinTypeError*/( "Array length is 0 and no second argument" );
        };
        
        for ( j/*i*/;j/*i*/<k/*len*/; ++ j/*i*/ ){
          if ( ( l/*ta*/ = this[j/*i*/] ) !== null && l/*ta*/ !== undefined ){
            i/*ret*/ = g/*callback*/( i/*ret*/,l/*ta*/,j/*i*/,this );
          };
        };
        return i/*ret*/;
      };
    };
    
    if ( !o/*arrayProto*/.reduceRight ){
      o/*arrayProto*/.reduceRight = function ( g/*callback*/,h/*initial*/ ) {
        s/*callbackCheck*/( g/*callback*/,"Array.reduceRight" );
        
        var i/*len*/ = this.length,
            j/*ret*/ = h/*initial*/ || this[i/*len*/-1],
            k/*i*/ = ( h/*initial*/ )?i/*len*/-1 : i/*len*/-2,
            l/*ta*/;
        
        if ( ( i/*len*/ === 0 || i/*len*/ === null ) && arguments.length<2 ){
          m/*builtinTypeError*/( "Array length is 0 and no second argument" );
        };
        
        for ( k/*i*/;k/*i*/>-1; -- k/*i*/ ){
          if ( ( l/*ta*/ = this[k/*i*/] ) !== null && l/*ta*/ !== undefined ){
            j/*ret*/ = g/*callback*/( j/*ret*/,l/*ta*/,k/*i*/,this );
          };
        };
        return j/*ret*/;
      };
    };
    
    if ( !C/*dateProto*/.toJSON ){
      C/*dateProto*/.toJSON = function () {
        var g/*_mochaLocalTmp4*/ = [this.getUTCMonth(),this.getUTCDate(),this.getUTCHours(),this.getMinutes(),this.getSeconds()],
            h/*month*/ = g/*_mochaLocalTmp4*/[0],
            i/*date*/ = g/*_mochaLocalTmp4*/[1],
            j/*hour*/ = g/*_mochaLocalTmp4*/[2],
            k/*minute*/ = g/*_mochaLocalTmp4*/[3],
            l/*second*/ = g/*_mochaLocalTmp4*/[4];
        return '"'+this.getUTCFullYear()+'-'+( h/*month*/>8?h/*month*/+1 : "0"+( h/*month*/+1 ) )+'-'+( i/*date*/>9?i/*date*/ : "0"+i/*date*/ )+'T'+( j/*hour*/>9?j/*hour*/ : "0"+j/*hour*/ )+':'+( k/*minute*/>9?k/*minute*/ : "0"+k/*minute*/ )+':'+( l/*second*/>9?l/*second*/ : "0"+l/*second*/ )+'.'+this.getUTCMilliseconds()+'Z"';
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
  
  var m/*Runtime*/ = ( function Runtime() {
        var Z/*_mochaLocalExport*/ = {};
        
        "use strict";
        
        function h/*Exception*/( g/*line*/,f/*file*/,a/*e*/ ) {
          this.toString = function () {
            return b/*Runtime*/.getErrorMessage( a/*e*/ )+" in file "+f/*file*/+" at : "+g/*line*/;
          };
        }
        var J/*fastMax*/ = Math.max;
        
        var b/*Runtime*/ =  {
              getErrorMessage : function _/*getErrorMessage*/( b/*e*/ ) {
                return ( b/*e*/.message )?b/*e*/.message : ( b/*e*/.description )?b/*e*/.description : b/*e*/.toString();
              },
              exceptionHandler : function $/*exceptionHandler*/( k/*line*/,l/*file*/,m/*e*/ ) {
                if ( f/*isStopIteration*/( m/*e*/ ) ){
                  this.throwException( m/*e*/ );
                } else {
                  this.throwException( new h/*Exception*/( k/*line*/,l/*file*/,m/*e*/ ) );
                };
              },
              throwException : function bb/*throwException*/( b/*exception*/ ) {
                try {
                  throw b/*exception*/;
                } catch( e ){
                  if ( f/*isStopIteration*/( e ) ){
                    throw new Error( e );
                  } else {
                    throw new Error( this.getErrorMessage( e ) );
                  };
                };
              },
              hasProto : "__proto__" in {}
            };
        
        var k/*slice*/ = Array.prototype.slice;
        
        var E/*createUnenumProp*/ = Z/*_mochaLocalExport*/.createUnenumProp = function E/*createUnenumProp*/( d/*obj*/,e/*prop*/,f/*value*/ ) {
              return Object.defineProperty( d/*obj*/,e/*prop*/, {
                configurable : true,
                enumerable : false,
                writable : true,
                value : f/*value*/
              });
            };
        
        var bc/*constant*/ = Z/*_mochaLocalExport*/.constant = function bc/*constant*/( d/*obj*/,e/*prop*/,f/*value*/ ) {
              return Object.defineProperty( d/*obj*/,e/*prop*/, {
                configurable : false,
                enumerable : false,
                writable : false,
                value : f/*value*/
              });
            };
        
        var bd/*toArray*/ = Z/*_mochaLocalExport*/.toArray = function bd/*toArray*/( m/*likeArray*/,n/*index*/ ) {
              return ( m/*likeArray*/ )?k/*slice*/.call( m/*likeArray*/,n/*index*/ ) : [];
            };
        
        var D/*Generator*/ = function (){};
        
        var be/*createGenerator*/ = Z/*_mochaLocalExport*/.createGenerator = function be/*createGenerator*/( J/*generatorFn*/,K/*closeFn*/,L/*context*/ ) {
              var M/*ret*/ = new D/*Generator*/;
              
              E/*createUnenumProp*/( M/*ret*/,"next",J/*generatorFn*/.bind( L/*context*/,false,false ) );
              
              E/*createUnenumProp*/( M/*ret*/,"send",J/*generatorFn*/.bind( L/*context*/,true,false ) );
              
              E/*createUnenumProp*/( M/*ret*/,"close",K/*closeFn*/.bind( L/*context*/ ) );
              
              E/*createUnenumProp*/( M/*ret*/,"__nothrowNext__",J/*generatorFn*/.bind( L/*context*/,false,true ) );
              
              E/*createUnenumProp*/( M/*ret*/,"toString",
              function () {
                return "[object Generator]";
              });
              
              Object.freeze( M/*ret*/ );
              return M/*ret*/;
            };
        
        function _/*getErrorMessage*/( b/*e*/ ) {
          return ( b/*e*/.message )?b/*e*/.message : ( b/*e*/.description )?b/*e*/.description : b/*e*/.toString();
        }
        var bb/*throwException*/ = Z/*_mochaLocalExport*/.throwException = b/*Runtime*/.throwException.bind( b/*Runtime*/ );
        
        var $/*exceptionHandler*/ = Z/*_mochaLocalExport*/.exceptionHandler = b/*Runtime*/.exceptionHandler.bind( b/*Runtime*/ );
        
        var bf/*extend*/ = Z/*_mochaLocalExport*/.extend = function bf/*extend*/( d/*dest*/,e/*source*/ ) {
              for ( var f/*prop*/ in e/*source*/ ){
                d/*dest*/[f/*prop*/] = e/*source*/[f/*prop*/];
              };
              return d/*dest*/;
            };
        
        function N/*compareTuple*/( N/*tuple*/ ) {
          var O/*max*/ = J/*fastMax*/( N/*tuple*/.length,this.length ),
              P/*i*/ = -1;
          
          while (  ++ P/*i*/<O/*max*/ && N/*tuple*/[P/*i*/] === this[P/*i*/] ){
            
          };
          return O/*max*/ === P/*i*/;
        };
        
        function O/*tupleToArray*/() {
          return Array.prototype.slice.call( this );
        };
        
        var bg/*createTuple*/ = Z/*_mochaLocalExport*/.createTuple = function bg/*createTuple*/( P/*obj*/,Q/*size*/ ) {
              E/*createUnenumProp*/( P/*obj*/,"length",Q/*size*/ );
              
              E/*createUnenumProp*/( P/*obj*/,"equal",N/*compareTuple*/ );
              
              E/*createUnenumProp*/( P/*obj*/,"toArray",O/*tupleToArray*/ );
              
              E/*createUnenumProp*/( P/*obj*/,"toString",
              function () {
                return "[object Tuple]";
              });
              return Object.freeze( P/*obj*/ );
            };
        
        var bh/*createRecord*/ = Z/*_mochaLocalExport*/.createRecord = function bh/*createRecord*/( b/*obj*/ ) {
              if ( b/*obj*/.toString() === "[object Object]" ){
                E/*createUnenumProp*/( b/*obj*/,"toString",
                function () {
                  return "[object Record]";
                });
              };
              return Object.freeze( b/*obj*/ );
            };
        
        var bi/*extendPrototype*/ = Z/*_mochaLocalExport*/.extendPrototype = function ( c/*derived*/,d/*base*/ ) {
              c/*derived*/.prototype = d/*base*/;
            };
        
        var P/*getPrototype*/ = ( "getPrototypeOf" in Object )?function ( b/*obj*/ ) {
              return Object.getPrototypeOf( b/*obj*/ );
            } : function ( d/*obj*/ ) {
              var e/*ret*/ = {};
              
              for ( var f/*i*/ in d/*obj*/ ){
                if ( !d/*obj*/.hasOwnProperty( f/*i*/ ) ){
                  e/*ret*/[f/*i*/] = d/*obj*/[f/*i*/];
                };
              };
              return e/*ret*/;
            };
        
        var bj/*extendClass*/ = Z/*_mochaLocalExport*/.extendClass = ( b/*Runtime*/.hasProto )?function ( d/*derived*/,e/*base*/ ) {
              if ( typeof e/*base*/ === 'function' ){
                d/*derived*/.prototype.__proto__ = e/*base*/.prototype;
                
                for ( var f/*i*/ in e/*base*/ ){
                  d/*derived*/[f/*i*/] = e/*base*/[f/*i*/];
                };
              } else {
                d/*derived*/.prototype.__proto__ = e/*base*/.__proto__;
              };
            } : function ( R/*derived*/,S/*base*/ ) {
              var T/*baseType*/ = typeof S/*base*/;
              
              if ( T/*baseType*/ === "function" ){
                var U/*inherit*/ = function (){};
                
                U/*inherit*/.prototype = S/*base*/.prototype;
                
                R/*derived*/.prototype = new U/*inherit*/;
                
                for ( var V/*i*/ in S/*base*/ ){
                  R/*derived*/[V/*i*/] = S/*base*/[V/*i*/];
                };
              } else {
                var U/*inherit*/ = function (){},
                    W/*proto*/ = P/*getPrototype*/( S/*base*/ );
                
                U/*inherit*/.prototype = W/*proto*/;
                
                R/*derived*/.prototype = new U/*inherit*/;
              };
            };
        
        var R/*__ref_iterator__*/ = Z/*_mochaLocalExport*/.__ref_iterator__ = "__mocha_iterator_special_key__";
        
        var W/*throwStopIteration*/ = Z/*_mochaLocalExport*/.throwStopIteration = function W/*throwStopIteration*/() {
              try {
                throw StopIteration;
              } catch( e ){
                throw new Error( e.toString() );
              };
            };
        
        var S/*isGenerator*/ = Z/*_mochaLocalExport*/.isGenerator = function S/*isGenerator*/( b/*obj*/ ) {
              return b/*obj*/ instanceof D/*Generator*/;
            };
        
        var bk/*getIterator*/ = Z/*_mochaLocalExport*/.getIterator = function bk/*getIterator*/( X/*obj*/ ) {
              var b/*ret*/ = X/*obj*/[R/*__ref_iterator__*/](),
                  Y/*newObj*/;
              
              if ( S/*isGenerator*/( b/*ret*/ ) ){
                return b/*ret*/;
              };
              
              Y/*newObj*/ = {};
              
              if ( b/*ret*/.next ){
                E/*createUnenumProp*/( Y/*newObj*/,"next",
                function () {
                  var d/*result*/ = b/*ret*/.next();
                  
                  if ( d/*result*/ === undefined ){
                    W/*throwStopIteration*/();
                  };
                  return d/*result*/;
                });
              } else {
                return {};
              };
              
              if ( !( "__nothrowNext__" in b/*ret*/ ) ){
                E/*createUnenumProp*/( Y/*newObj*/,"__nothrowNext__",b/*ret*/.next.bind( b/*ret*/ ) );
              };
              
              for ( var Z/*prop*/ in b/*ret*/ ){
                if ( Z/*prop*/ !== "next" && Z/*prop*/ !== "__nothrowNext__" ){
                  Y/*newObj*/[Z/*prop*/] = b/*ret*/[Z/*prop*/];
                };
              };
              
              if ( !( "toString" in b/*ret*/ ) ){
                E/*createUnenumProp*/( Y/*newObj*/,"toString",
                function () {
                  return "[object Iterator]";
                });
              };
              return Y/*newObj*/;
            };
        
        var bl/*hasIterator*/ = Z/*_mochaLocalExport*/.hasIterator = function bl/*hasIterator*/( b/*obj*/ ) {
              return R/*__ref_iterator__*/ in b/*obj*/;
            };
        
        var X/*rstopIteration*/ = /StopIteration/;
        
        var f/*isStopIteration*/ = Z/*_mochaLocalExport*/.isStopIteration = function f/*isStopIteration*/( Y/*obj*/ ) {
              return Y/*obj*/ === StopIteration || X/*rstopIteration*/.test( Y/*obj*/ );
            };
        
        var Y/*privateRecord*/,
            bm/*createPrivateRecord*/,
            bn/*getPrivateRecord*/;
        
        if ( "WeakMap" in window ){
          Y/*privateRecord*/ = new WeakMap();
          
          bm/*createPrivateRecord*/ = function ( self,Z/*privateHolder*/ ) {
            var _/*holder*/ = new Z/*privateHolder*/;
            
            E/*createUnenumProp*/( _/*holder*/.constructor,"__is_private__",1 );
            
            Y/*privateRecord*/.set( self,_/*holder*/ );
          };
          
          bn/*getPrivateRecord*/ = function ( self ) {
            if ( Y/*privateRecord*/.has( self ) ){
              return Y/*privateRecord*/.get( self );
            } else if ( self.constructor === "__is_private__" ){
              return self;
            };
          };
        } else {
          bm/*createPrivateRecord*/ = function ( self,c/*privateHolder*/ ) {
            if ( !self.__typeid__ ){
              var d/*holder*/ = new c/*privateHolder*/;
              
              E/*createUnenumProp*/( d/*holder*/.constructor,"__is_private__",1 );
              
              E/*createUnenumProp*/( self,"__private__",d/*holder*/ );
            };
          };
          
          bn/*getPrivateRecord*/ = function ( self ) {
            if ( self.__private__ ){
              return self.__private__;
            } else if ( self.constructor === "__is_private__" ){
              return self;
            };
          };
        };
        
        Z/*_mochaLocalExport*/.createPrivateRecord = bm/*createPrivateRecord*/;
        
        Z/*_mochaLocalExport*/.getPrivateRecord = bn/*getPrivateRecord*/;
        
        var bo/*getSuper*/ = Z/*_mochaLocalExport*/.getSuper = function bo/*getSuper*/( d/*obj*/ ) {
              var e/*type*/ = typeof d/*obj*/,
                  f/*ret*/;
              
              if ( e/*type*/ === "function" ){
                f/*ret*/ = function (){};
                
                f/*ret*/.prototype = d/*obj*/.prototype;
                
                f/*ret*/ = new f/*ret*/();
                
                if ( d/*obj*/.__harmony_class__ ){
                  f/*ret*/.constructor = d/*obj*/.constructor;
                } else {
                  f/*ret*/.constructor = d/*obj*/;
                };
                return f/*ret*/;
              };
              return f/*ret*/;
            };
        
        var bp/*traitMixin*/ = Z/*_mochaLocalExport*/.traitMixin = function bp/*traitMixin*/( m/*dest*/,n/*source*/,o/*with_*/,p/*without*/ ) {
              if ( !m/*dest*/._mochaTraitMark || !n/*source*/._mochaTraitMark ){
                b/*Runtime*/.throwException( "mixin only used for trait." );
              } else {
                var q/*destTraitPrivate*/ = m/*dest*/._mochaTraitPrivate,
                    r/*sourceTraitPrivate*/ = n/*source*/._mochaTraitPrivate,
                    s/*destTraitPublic*/ = m/*dest*/._mochaTraitPublic,
                    t/*sourceTraitPublic*/ = n/*source*/._mochaTraitPublic,
                    u/*sourceRequires*/ = n/*source*/._mochaRequires,
                    v/*destRequires*/ = m/*dest*/._mochaRequires,
                    w/*tmp*/;
                
                for ( var x/*i*/ in r/*sourceTraitPrivate*/ ){
                  if ( !p/*without*/[x/*i*/] ){
                    w/*tmp*/ = ( !o/*with_*/[x/*i*/] )?x/*i*/ : o/*with_*/[x/*i*/];
                    
                    q/*destTraitPrivate*/[w/*tmp*/] = r/*sourceTraitPrivate*/[x/*i*/];
                  };
                };
                
                for ( x/*i*/ in t/*sourceTraitPublic*/ ){
                  if ( !p/*without*/[x/*i*/] ){
                    w/*tmp*/ = ( !o/*with_*/[x/*i*/] )?x/*i*/ : o/*with_*/[x/*i*/];
                    
                    s/*destTraitPublic*/[w/*tmp*/] = t/*sourceTraitPublic*/[x/*i*/];
                  };
                };
                
                for ( x/*i*/ in u/*sourceRequires*/ ){
                  v/*destRequires*/[x/*i*/] = u/*sourceRequires*/[x/*i*/];
                };
              };
            };
        
        var bq/*classMixin*/ = Z/*_mochaLocalExport*/.classMixin = function bq/*classMixin*/( m/*_mochaLocalTmp5*/,n/*_mochaLocalTmp6*/,o/*_mochaLocalTmp7*/,p/*with_*/,q/*without*/ ) {
              var r/*constructorProto*/ = m/*_mochaLocalTmp5*/.prototype,
                  s/*privateProto*/ = n/*_mochaLocalTmp6*/.prototype,
                  t/*mark*/ = o/*_mochaLocalTmp7*/._mochaTraitMark,
                  u/*traitPublic*/ = o/*_mochaLocalTmp7*/._mochaTraitPublic,
                  v/*traitPrivate*/ = o/*_mochaLocalTmp7*/._mochaTraitPrivate;
              
              if ( !t/*mark*/ ){
                b/*Runtime*/.throwException( "mixin only used for trait." );
              } else {
                var w/*tmp*/;
                
                for ( var x/*i*/ in u/*traitPublic*/ ){
                  if ( !q/*without*/[x/*i*/] ){
                    w/*tmp*/ = ( !p/*with_*/[x/*i*/] )?x/*i*/ : p/*with_*/[x/*i*/];
                    
                    r/*constructorProto*/[w/*tmp*/] = u/*traitPublic*/[x/*i*/];
                  };
                };
                
                for ( x/*i*/ in v/*traitPrivate*/ ){
                  if ( !q/*without*/[x/*i*/] ){
                    w/*tmp*/ = ( !p/*with_*/[x/*i*/] )?x/*i*/ : p/*with_*/[x/*i*/];
                    
                    s/*privateProto*/[w/*tmp*/] = v/*traitPrivate*/[x/*i*/];
                  };
                };
              };
            };
        
        var br/*checkRequirements*/ = Z/*_mochaLocalExport*/.checkRequirements = function br/*checkRequirements*/( m/*_mochaLocalTmp8*/,n/*_mochaLocalTmp9*/,o/*traits*/,p/*file*/,q/*line*/ ) {
              var r/*proto1*/ = m/*_mochaLocalTmp8*/.prototype,
                  s/*proto2*/ = n/*_mochaLocalTmp9*/.prototype;
              
              for ( var t/*i*/ = 0,u/*len*/ = o/*traits*/.length;t/*i*/<u/*len*/;t/*i*/ ++  ){
                var v/*_mochaLocalTmp10*/ = o/*traits*/[t/*i*/],
                    w/*_mochaRequires*/ = v/*_mochaLocalTmp10*/._mochaRequires;
                
                for ( var x/*prop*/ in w/*_mochaRequires*/ ){
                  if ( !( x/*prop*/ in r/*proto1*/ ) && !( x/*prop*/ in s/*proto2*/ ) ){
                    b/*Runtime*/.throwException( "Class dose not meet the traits requirement. traits require implementation of property "+x/*prop*/+"\nin file "+p/*file*/+" at line "+q/*line*/ );
                  };
                };
              };
            };
        return Z/*_mochaLocalExport*/;
      })();
  
  if ( !( "StopIteration" in window ) ){
    window.StopIteration =  {
      toString : function J/*toString*/() {
        return "[object StopIteration]";
      }
    };
  };
  
  ( function () {
    D/*_mochaGlobalExport*/['../../../../../../../home/brn/.mocha/module/iterators.js'] = {};
    
    var a/*_mochaGlobalAlias*/ = D/*_mochaGlobalExport*/['../../../../../../../home/brn/.mocha/module/iterators.js'];
    
    ( function () {
      var h/*_mochaLocalExport*/ = a/*_mochaGlobalAlias*/;
      
      var g/*hasOwn*/ = Object.prototype.hasOwnProperty;
      
      var e/*iterator*/ = h/*_mochaLocalExport*/.iterator = "__mocha_iterator_special_key__";
      
      var i/*keys*/ = h/*_mochaLocalExport*/.keys = function i/*keys*/( b/*obj*/ ) {
            var h/*_mochaLocalTmp3*/ =  {
                  
                };
            
            m/*Runtime*/.createUnenumProp( h/*_mochaLocalTmp3*/,e/*iterator*/,
            function () {
              return function () {
                var h/*_mochaIsNewBorn*/ = true;
                
                var q/*_yieldResult*/ = undefined;
                
                var i/*_yieldState*/ = 0;
                
                var n/*length*/;
                
                var l/*_mochaLocalTmp2*/;
                
                var o/*x*/;
                
                var j/*_mochaLocalTmp1*/ = [];
                
                var r/*_mochaGenerator*/ = function ( q/*_isYieldSend*/,r/*_isYieldSafe*/ ) {
                      if ( !q/*_isYieldSend*/ ){
                        h/*_mochaIsNewBorn*/ = false;
                      } else if ( q/*_isYieldSend*/ && h/*_mochaIsNewBorn*/ && arguments[1] !== undefined ){
                        m/*Runtime*/.exceptionHandler( 'attempt to send to newborn generator.' );
                      };
                      
                      while ( 1 ){
                        switch ( i/*_yieldState*/ ) {
                          case 0 :
                            
                            for ( var s/*_mochaLocalTmp0*/ in b/*obj*/ )
                            j/*_mochaLocalTmp1*/.push( s/*_mochaLocalTmp0*/ );
                            
                            l/*_mochaLocalTmp2*/ = 0;
                            
                            n/*length*/ = j/*_mochaLocalTmp1*/.length;
                            
                            if ( !( l/*_mochaLocalTmp2*/<n/*length*/ ) ){
                              i/*_yieldState*/ = -1;
                              break;
                            };
                          case 1 :
                            
                            o/*x*/ = j/*_mochaLocalTmp1*/[l/*_mochaLocalTmp2*/];
                            
                            if ( g/*hasOwn*/.call( b/*obj*/,o/*x*/ ) ){
                              i/*_yieldState*/ = 2;
                              break;
                            } else {
                              i/*_yieldState*/ = 3;
                              break;
                            };
                          case 2 :
                            
                            i/*_yieldState*/ = 3;
                            return o/*x*/;
                          case 3 :
                            
                            i/*_yieldState*/ = 4;
                            break;
                          case 4 :
                            
                             ++ l/*_mochaLocalTmp2*/;
                            
                            if ( l/*_mochaLocalTmp2*/<n/*length*/ ){
                              i/*_yieldState*/ = 1;
                              break;
                            } else {
                              i/*_yieldState*/ = -1;
                            };
                          case -1 :
                            
                            if ( r/*_isYieldSafe*/ ){
                              return undefined;
                            } else {
                              m/*Runtime*/.throwStopIteration();
                            };
                            
                        };
                      };
                    };
                return m/*Runtime*/.createGenerator( r/*_mochaGenerator*/,
                function (  ) {
                  i/*_yieldState*/ = -1;
                },this);
              }();
            });
            return h/*_mochaLocalTmp3*/;
          };
      
      var j/*values*/ = h/*_mochaLocalExport*/.values = function j/*values*/( c/*obj*/ ) {
            var h/*_mochaLocalTmp7*/ =  {
                  
                };
            
            m/*Runtime*/.createUnenumProp( h/*_mochaLocalTmp7*/,e/*iterator*/,
            function () {
              return function () {
                var h/*_mochaIsNewBorn*/ = true;
                
                var q/*_yieldResult*/ = undefined;
                
                var i/*_yieldState*/ = 0;
                
                var n/*length*/;
                
                var l/*_mochaLocalTmp6*/;
                
                var o/*x*/;
                
                var j/*_mochaLocalTmp5*/ = [];
                
                var r/*_mochaGenerator*/ = function ( q/*_isYieldSend*/,r/*_isYieldSafe*/ ) {
                      if ( !q/*_isYieldSend*/ ){
                        h/*_mochaIsNewBorn*/ = false;
                      } else if ( q/*_isYieldSend*/ && h/*_mochaIsNewBorn*/ && arguments[1] !== undefined ){
                        m/*Runtime*/.exceptionHandler( 'attempt to send to newborn generator.' );
                      };
                      
                      while ( 1 ){
                        switch ( i/*_yieldState*/ ) {
                          case 0 :
                            
                            for ( var s/*_mochaLocalTmp4*/ in c/*obj*/ )
                            j/*_mochaLocalTmp5*/.push( s/*_mochaLocalTmp4*/ );
                            
                            l/*_mochaLocalTmp6*/ = 0;
                            
                            n/*length*/ = j/*_mochaLocalTmp5*/.length;
                            
                            if ( !( l/*_mochaLocalTmp6*/<n/*length*/ ) ){
                              i/*_yieldState*/ = -1;
                              break;
                            };
                          case 1 :
                            
                            o/*x*/ = j/*_mochaLocalTmp5*/[l/*_mochaLocalTmp6*/];
                            
                            if ( g/*hasOwn*/.call( c/*obj*/,o/*x*/ ) ){
                              i/*_yieldState*/ = 2;
                              break;
                            } else {
                              i/*_yieldState*/ = 3;
                              break;
                            };
                          case 2 :
                            
                            i/*_yieldState*/ = 3;
                            return c/*obj*/[o/*x*/];
                          case 3 :
                            
                            i/*_yieldState*/ = 4;
                            break;
                          case 4 :
                            
                             ++ l/*_mochaLocalTmp6*/;
                            
                            if ( l/*_mochaLocalTmp6*/<n/*length*/ ){
                              i/*_yieldState*/ = 1;
                              break;
                            } else {
                              i/*_yieldState*/ = -1;
                            };
                          case -1 :
                            
                            if ( r/*_isYieldSafe*/ ){
                              return undefined;
                            } else {
                              m/*Runtime*/.throwStopIteration();
                            };
                            
                        };
                      };
                    };
                return m/*Runtime*/.createGenerator( r/*_mochaGenerator*/,
                function (  ) {
                  i/*_yieldState*/ = -1;
                },this);
              }();
            });
            return h/*_mochaLocalTmp7*/;
          };
      
      var l/*items*/ = h/*_mochaLocalExport*/.items = function l/*items*/( c/*obj*/ ) {
            var h/*_mochaLocalTmp11*/ =  {
                  
                };
            
            m/*Runtime*/.createUnenumProp( h/*_mochaLocalTmp11*/,e/*iterator*/,
            function () {
              return function () {
                var h/*_mochaIsNewBorn*/ = true;
                
                var q/*_yieldResult*/ = undefined;
                
                var i/*_yieldState*/ = 0;
                
                var n/*length*/;
                
                var l/*_mochaLocalTmp10*/;
                
                var o/*x*/;
                
                var j/*_mochaLocalTmp9*/ = [];
                
                var r/*_mochaGenerator*/ = function ( q/*_isYieldSend*/,r/*_isYieldSafe*/ ) {
                      if ( !q/*_isYieldSend*/ ){
                        h/*_mochaIsNewBorn*/ = false;
                      } else if ( q/*_isYieldSend*/ && h/*_mochaIsNewBorn*/ && arguments[1] !== undefined ){
                        m/*Runtime*/.exceptionHandler( 'attempt to send to newborn generator.' );
                      };
                      
                      while ( 1 ){
                        switch ( i/*_yieldState*/ ) {
                          case 0 :
                            
                            for ( var s/*_mochaLocalTmp8*/ in c/*obj*/ )
                            j/*_mochaLocalTmp9*/.push( s/*_mochaLocalTmp8*/ );
                            
                            l/*_mochaLocalTmp10*/ = 0;
                            
                            n/*length*/ = j/*_mochaLocalTmp9*/.length;
                            
                            if ( !( l/*_mochaLocalTmp10*/<n/*length*/ ) ){
                              i/*_yieldState*/ = -1;
                              break;
                            };
                          case 1 :
                            
                            o/*x*/ = j/*_mochaLocalTmp9*/[l/*_mochaLocalTmp10*/];
                            
                            if ( g/*hasOwn*/.call( c/*obj*/,o/*x*/ ) ){
                              i/*_yieldState*/ = 2;
                              break;
                            } else {
                              i/*_yieldState*/ = 3;
                              break;
                            };
                          case 2 :
                            
                            i/*_yieldState*/ = 3;
                            return [o/*x*/,c/*obj*/[o/*x*/]];
                          case 3 :
                            
                            i/*_yieldState*/ = 4;
                            break;
                          case 4 :
                            
                             ++ l/*_mochaLocalTmp10*/;
                            
                            if ( l/*_mochaLocalTmp10*/<n/*length*/ ){
                              i/*_yieldState*/ = 1;
                              break;
                            } else {
                              i/*_yieldState*/ = -1;
                            };
                          case -1 :
                            
                            if ( r/*_isYieldSafe*/ ){
                              return undefined;
                            } else {
                              m/*Runtime*/.throwStopIteration();
                            };
                            
                        };
                      };
                    };
                return m/*Runtime*/.createGenerator( r/*_mochaGenerator*/,
                function (  ) {
                  i/*_yieldState*/ = -1;
                },this);
              }();
            });
            return h/*_mochaLocalTmp11*/;
          };
      
      var n/*allKeys*/ = h/*_mochaLocalExport*/.allKeys = function n/*allKeys*/( c/*obj*/ ) {
            var h/*_mochaLocalTmp15*/ =  {
                  
                };
            
            m/*Runtime*/.createUnenumProp( h/*_mochaLocalTmp15*/,e/*iterator*/,
            function () {
              return function () {
                var h/*_mochaIsNewBorn*/ = true;
                
                var q/*_yieldResult*/ = undefined;
                
                var i/*_yieldState*/ = 0;
                
                var n/*length*/;
                
                var l/*_mochaLocalTmp14*/;
                
                var o/*x*/;
                
                var j/*_mochaLocalTmp13*/ = [];
                
                var r/*_mochaGenerator*/ = function ( q/*_isYieldSend*/,r/*_isYieldSafe*/ ) {
                      if ( !q/*_isYieldSend*/ ){
                        h/*_mochaIsNewBorn*/ = false;
                      } else if ( q/*_isYieldSend*/ && h/*_mochaIsNewBorn*/ && arguments[1] !== undefined ){
                        m/*Runtime*/.exceptionHandler( 'attempt to send to newborn generator.' );
                      };
                      
                      while ( 1 ){
                        switch ( i/*_yieldState*/ ) {
                          case 0 :
                            
                            for ( var s/*_mochaLocalTmp12*/ in c/*obj*/ )
                            j/*_mochaLocalTmp13*/.push( s/*_mochaLocalTmp12*/ );
                            
                            l/*_mochaLocalTmp14*/ = 0;
                            
                            n/*length*/ = j/*_mochaLocalTmp13*/.length;
                            
                            if ( !( l/*_mochaLocalTmp14*/<n/*length*/ ) ){
                              i/*_yieldState*/ = -1;
                              break;
                            };
                          case 1 :
                            
                            i/*_yieldState*/ = 2;
                            
                            o/*x*/ = j/*_mochaLocalTmp13*/[l/*_mochaLocalTmp14*/];
                            return o/*x*/;
                          case 2 :
                            
                             ++ l/*_mochaLocalTmp14*/;
                            
                            if ( l/*_mochaLocalTmp14*/<n/*length*/ ){
                              i/*_yieldState*/ = 1;
                              break;
                            } else {
                              i/*_yieldState*/ = -1;
                            };
                          case -1 :
                            
                            if ( r/*_isYieldSafe*/ ){
                              return undefined;
                            } else {
                              m/*Runtime*/.throwStopIteration();
                            };
                            
                        };
                      };
                    };
                return m/*Runtime*/.createGenerator( r/*_mochaGenerator*/,
                function (  ) {
                  i/*_yieldState*/ = -1;
                },this);
              }();
            });
            return h/*_mochaLocalTmp15*/;
          };
      
      var o/*allValues*/ = h/*_mochaLocalExport*/.allValues = function o/*allValues*/( c/*obj*/ ) {
            var h/*_mochaLocalTmp19*/ =  {
                  
                };
            
            m/*Runtime*/.createUnenumProp( h/*_mochaLocalTmp19*/,e/*iterator*/,
            function () {
              return function () {
                var h/*_mochaIsNewBorn*/ = true;
                
                var q/*_yieldResult*/ = undefined;
                
                var i/*_yieldState*/ = 0;
                
                var n/*length*/;
                
                var l/*_mochaLocalTmp18*/;
                
                var o/*x*/;
                
                var j/*_mochaLocalTmp17*/ = [];
                
                var r/*_mochaGenerator*/ = function ( q/*_isYieldSend*/,r/*_isYieldSafe*/ ) {
                      if ( !q/*_isYieldSend*/ ){
                        h/*_mochaIsNewBorn*/ = false;
                      } else if ( q/*_isYieldSend*/ && h/*_mochaIsNewBorn*/ && arguments[1] !== undefined ){
                        m/*Runtime*/.exceptionHandler( 'attempt to send to newborn generator.' );
                      };
                      
                      while ( 1 ){
                        switch ( i/*_yieldState*/ ) {
                          case 0 :
                            
                            for ( var s/*_mochaLocalTmp16*/ in c/*obj*/ )
                            j/*_mochaLocalTmp17*/.push( s/*_mochaLocalTmp16*/ );
                            
                            l/*_mochaLocalTmp18*/ = 0;
                            
                            n/*length*/ = j/*_mochaLocalTmp17*/.length;
                            
                            if ( !( l/*_mochaLocalTmp18*/<n/*length*/ ) ){
                              i/*_yieldState*/ = -1;
                              break;
                            };
                          case 1 :
                            
                            i/*_yieldState*/ = 2;
                            
                            o/*x*/ = j/*_mochaLocalTmp17*/[l/*_mochaLocalTmp18*/];
                            return c/*obj*/[o/*x*/];
                          case 2 :
                            
                             ++ l/*_mochaLocalTmp18*/;
                            
                            if ( l/*_mochaLocalTmp18*/<n/*length*/ ){
                              i/*_yieldState*/ = 1;
                              break;
                            } else {
                              i/*_yieldState*/ = -1;
                            };
                          case -1 :
                            
                            if ( r/*_isYieldSafe*/ ){
                              return undefined;
                            } else {
                              m/*Runtime*/.throwStopIteration();
                            };
                            
                        };
                      };
                    };
                return m/*Runtime*/.createGenerator( r/*_mochaGenerator*/,
                function (  ) {
                  i/*_yieldState*/ = -1;
                },this);
              }();
            });
            return h/*_mochaLocalTmp19*/;
          };
      
      var q/*allItems*/ = h/*_mochaLocalExport*/.allItems = function q/*allItems*/( c/*obj*/ ) {
            var h/*_mochaLocalTmp23*/ =  {
                  
                };
            
            m/*Runtime*/.createUnenumProp( h/*_mochaLocalTmp23*/,e/*iterator*/,
            function () {
              return function () {
                var h/*_mochaIsNewBorn*/ = true;
                
                var q/*_yieldResult*/ = undefined;
                
                var i/*_yieldState*/ = 0;
                
                var n/*length*/;
                
                var l/*_mochaLocalTmp22*/;
                
                var o/*x*/;
                
                var j/*_mochaLocalTmp21*/ = [];
                
                var r/*_mochaGenerator*/ = function ( q/*_isYieldSend*/,r/*_isYieldSafe*/ ) {
                      if ( !q/*_isYieldSend*/ ){
                        h/*_mochaIsNewBorn*/ = false;
                      } else if ( q/*_isYieldSend*/ && h/*_mochaIsNewBorn*/ && arguments[1] !== undefined ){
                        m/*Runtime*/.exceptionHandler( 'attempt to send to newborn generator.' );
                      };
                      
                      while ( 1 ){
                        switch ( i/*_yieldState*/ ) {
                          case 0 :
                            
                            for ( var s/*_mochaLocalTmp20*/ in c/*obj*/ )
                            j/*_mochaLocalTmp21*/.push( s/*_mochaLocalTmp20*/ );
                            
                            l/*_mochaLocalTmp22*/ = 0;
                            
                            n/*length*/ = j/*_mochaLocalTmp21*/.length;
                            
                            if ( !( l/*_mochaLocalTmp22*/<n/*length*/ ) ){
                              i/*_yieldState*/ = -1;
                              break;
                            };
                          case 1 :
                            
                            i/*_yieldState*/ = 2;
                            
                            o/*x*/ = j/*_mochaLocalTmp21*/[l/*_mochaLocalTmp22*/];
                            return [o/*x*/,c/*obj*/[o/*x*/]];
                          case 2 :
                            
                             ++ l/*_mochaLocalTmp22*/;
                            
                            if ( l/*_mochaLocalTmp22*/<n/*length*/ ){
                              i/*_yieldState*/ = 1;
                              break;
                            } else {
                              i/*_yieldState*/ = -1;
                            };
                          case -1 :
                            
                            if ( r/*_isYieldSafe*/ ){
                              return undefined;
                            } else {
                              m/*Runtime*/.throwStopIteration();
                            };
                            
                        };
                      };
                    };
                return m/*Runtime*/.createGenerator( r/*_mochaGenerator*/,
                function (  ) {
                  i/*_yieldState*/ = -1;
                },this);
              }();
            });
            return h/*_mochaLocalTmp23*/;
          };
      return h/*_mochaLocalExport*/;
    })();
  })();
  
  ( function () {
    D/*_mochaGlobalExport*/['./for_of_test.js'] = {};
    
    var w/*_mochaGlobalAlias*/ = D/*_mochaGlobalExport*/['./for_of_test.js'];
    
    var x/*_mochaLocalTmp0*/ = D/*_mochaGlobalExport*/['../../../../../../../home/brn/.mocha/module/iterators.js'],
        p/*iterator*/ = x/*_mochaLocalTmp0*/.iterator;
    
    var y/*_mochaLocalTmp9*/ =  {
          arr : [],
          add : function ( b/*value*/ ) {
            this.arr.push( b/*value*/ );
          },
          
        };
    
    m/*Runtime*/.createUnenumProp( y/*_mochaLocalTmp9*/,p/*iterator*/,
    function () {
      var b/*arr*/ = this.arr;
      return  {
        index : 0,
        next : function () {
          if ( b/*arr*/.length>this.index ){
            var p/*ret*/ = b/*arr*/[this.index];
            
            this.index ++ ;
            return p/*ret*/;
          } else {
            return undefined;
          };
        }
      };
    });
    
    var z/*item*/ = function ( d/*obj*/ ) {
          var u/*_mochaLocalTmp4*/ =  {
                
              };
          
          m/*Runtime*/.createUnenumProp( u/*_mochaLocalTmp4*/,p/*iterator*/,
          function () {
            var g/*_mochaIsNewBorn*/ = true;
            
            var u/*_yieldResult*/ = undefined;
            
            var h/*_yieldState*/ = 0;
            
            var l/*length*/;
            
            var k/*_mochaLocalTmp3*/;
            
            var n/*i*/;
            
            var i/*_mochaLocalTmp2*/ = [];
            
            var v/*_mochaGenerator*/ = function ( p/*_isYieldSend*/,q/*_isYieldSafe*/ ) {
                  if ( !p/*_isYieldSend*/ ){
                    g/*_mochaIsNewBorn*/ = false;
                  } else if ( p/*_isYieldSend*/ && g/*_mochaIsNewBorn*/ && arguments[1] !== undefined ){
                    m/*Runtime*/.exceptionHandler( 'attempt to send to newborn generator.' );
                  };
                  
                  while ( 1 ){
                    switch ( h/*_yieldState*/ ) {
                      case 0 :
                        
                        for ( var r/*_mochaLocalTmp1*/ in d/*obj*/ )
                        i/*_mochaLocalTmp2*/.push( r/*_mochaLocalTmp1*/ );
                        
                        k/*_mochaLocalTmp3*/ = 0;
                        
                        l/*length*/ = i/*_mochaLocalTmp2*/.length;
                        
                        if ( !( k/*_mochaLocalTmp3*/<l/*length*/ ) ){
                          h/*_yieldState*/ = -1;
                          break;
                        };
                      case 1 :
                        
                        h/*_yieldState*/ = 2;
                        
                        n/*i*/ = i/*_mochaLocalTmp2*/[k/*_mochaLocalTmp3*/];
                        
                        n/*i*/ = d/*obj*/[n/*i*/];
                        return n/*i*/;
                      case 2 :
                        
                         ++ k/*_mochaLocalTmp3*/;
                        
                        if ( k/*_mochaLocalTmp3*/<l/*length*/ ){
                          h/*_yieldState*/ = 1;
                          break;
                        } else {
                          h/*_yieldState*/ = -1;
                        };
                      case -1 :
                        
                        if ( q/*_isYieldSafe*/ ){
                          return undefined;
                        } else {
                          m/*Runtime*/.throwStopIteration();
                        };
                        
                    };
                  };
                };
            return m/*Runtime*/.createGenerator( v/*_mochaGenerator*/,
            function (  ) {
              h/*_yieldState*/ = -1;
            },this);
          });
          return u/*_mochaLocalTmp4*/;
        },
        A/*key*/ = function ( d/*obj*/ ) {
          var h/*_mochaLocalTmp8*/ =  {
                
              };
          
          m/*Runtime*/.createUnenumProp( h/*_mochaLocalTmp8*/,p/*iterator*/,
          function () {
            var g/*_mochaIsNewBorn*/ = true;
            
            var w/*_yieldResult*/ = undefined;
            
            var h/*_yieldState*/ = 0;
            
            var l/*length*/;
            
            var k/*_mochaLocalTmp7*/;
            
            var n/*i*/;
            
            var i/*_mochaLocalTmp6*/ = [];
            
            var x/*_mochaGenerator*/ = function ( p/*_isYieldSend*/,q/*_isYieldSafe*/ ) {
                  if ( !p/*_isYieldSend*/ ){
                    g/*_mochaIsNewBorn*/ = false;
                  } else if ( p/*_isYieldSend*/ && g/*_mochaIsNewBorn*/ && arguments[1] !== undefined ){
                    m/*Runtime*/.exceptionHandler( 'attempt to send to newborn generator.' );
                  };
                  
                  while ( 1 ){
                    switch ( h/*_yieldState*/ ) {
                      case 0 :
                        
                        for ( var r/*_mochaLocalTmp5*/ in d/*obj*/ )
                        i/*_mochaLocalTmp6*/.push( r/*_mochaLocalTmp5*/ );
                        
                        k/*_mochaLocalTmp7*/ = 0;
                        
                        l/*length*/ = i/*_mochaLocalTmp6*/.length;
                        
                        if ( !( k/*_mochaLocalTmp7*/<l/*length*/ ) ){
                          h/*_yieldState*/ = -1;
                          break;
                        };
                      case 1 :
                        
                        h/*_yieldState*/ = 2;
                        
                        n/*i*/ = i/*_mochaLocalTmp6*/[k/*_mochaLocalTmp7*/];
                        return n/*i*/;
                      case 2 :
                        
                         ++ k/*_mochaLocalTmp7*/;
                        
                        if ( k/*_mochaLocalTmp7*/<l/*length*/ ){
                          h/*_yieldState*/ = 1;
                          break;
                        } else {
                          h/*_yieldState*/ = -1;
                        };
                      case -1 :
                        
                        if ( q/*_isYieldSafe*/ ){
                          return undefined;
                        } else {
                          m/*Runtime*/.throwStopIteration();
                        };
                        
                    };
                  };
                };
            return m/*Runtime*/.createGenerator( x/*_mochaGenerator*/,
            function (  ) {
              h/*_yieldState*/ = -1;
            },this);
          });
          return h/*_mochaLocalTmp8*/;
        },
        B/*iter*/ = y/*_mochaLocalTmp9*/;
    
    var C/*testObj*/ =  {
          value1 : 100,
          value2 : 200,
          value3 : 300,
          value4 : 400
        };
    
    var o/*ret*/ = [];
    
    var v/*i*/;
    
    var E/*_mochaLocalTmp10*/ = z/*item*/( C/*testObj*/ );
    
    E/*_mochaLocalTmp10*/ = m/*Runtime*/.hasIterator( E/*_mochaLocalTmp10*/ )?m/*Runtime*/.getIterator( E/*_mochaLocalTmp10*/ ) : E/*_mochaLocalTmp10*/;
    
    if ( E/*_mochaLocalTmp10*/.__nothrowNext__ ){
      while ( ( v/*i*/ = E/*_mochaLocalTmp10*/.__nothrowNext__(  ) ) ){
        o/*ret*/.push( v/*i*/ );
      };
    } else {
      m/*Runtime*/.exceptionHandler( 49,'./for_of_test.js','for of statement expect iterator or generator object.' );
    };
    
    o/*ret*/ = [];
    
    var F/*x*/;
    
    var G/*_mochaLocalTmp11*/ = A/*key*/( C/*testObj*/ );
    
    G/*_mochaLocalTmp11*/ = m/*Runtime*/.hasIterator( G/*_mochaLocalTmp11*/ )?m/*Runtime*/.getIterator( G/*_mochaLocalTmp11*/ ) : G/*_mochaLocalTmp11*/;
    
    if ( G/*_mochaLocalTmp11*/.__nothrowNext__ ){
      while ( ( F/*x*/ = G/*_mochaLocalTmp11*/.__nothrowNext__(  ) ) ){
        o/*ret*/.push( F/*x*/ );
      };
    } else {
      m/*Runtime*/.exceptionHandler( 58,'./for_of_test.js','for of statement expect iterator or generator object.' );
    };
    
    o/*ret*/ = [];
    
    B/*iter*/.add( 100 );
    
    B/*iter*/.add( 200 );
    
    B/*iter*/.add( 300 );
    
    B/*iter*/.add( 400 );
    
    var H/*_mochaLocalTmp12*/ = B/*iter*/;
    
    H/*_mochaLocalTmp12*/ = m/*Runtime*/.hasIterator( H/*_mochaLocalTmp12*/ )?m/*Runtime*/.getIterator( H/*_mochaLocalTmp12*/ ) : H/*_mochaLocalTmp12*/;
    
    if ( H/*_mochaLocalTmp12*/.__nothrowNext__ ){
      while ( ( v/*i*/ = H/*_mochaLocalTmp12*/.__nothrowNext__(  ) ) ){
        o/*ret*/.push( v/*i*/ );
      };
    } else {
      m/*Runtime*/.exceptionHandler( 71,'./for_of_test.js','for of statement expect iterator or generator object.' );
    };
  })();
})();
