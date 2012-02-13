(function() {
  var __FILE__ = "Runtime",
      __LINE__ = 0;
  
  var _mochaGlobalExport = {},
      _mochaClassTable = {};
  
  var Runtime = ( function Runtime() {
        var _mochaLocalExport = {};
        
        function Exception( line,file,e ) {
          this.toString = function () {
            return Runtime.getErrorMessage( e )+" in file "+file+" at : "+line;
          };
        }
        var Runtime =  {
              getErrorMessage : function getErrorMessage( e ) {
                return ( e.message )?e.message : ( e.description )?e.description : e.toString();
              },
              exceptionHandler : function exceptionHandler( line,file,e ) {
                if ( isStopIteration( e ) ){
                  this.throwException( e );
                } else {
                  this.throwException( new Exception( line,file,e ) );
                };
              },
              throwException : function throwException( exception ) {
                try {
                  throw exception;
                } catch( e ){
                  if ( isStopIteration( e ) ){
                    throw new Error( e );
                  } else {
                    throw new Error( this.getErrorMessage( e ) );
                  };
                };
              },
              hasProto : "__proto__" in {}
            };
        
        if ( !String.prototype.trim ){
          String.prototype.trim = function () {
            return this.replace( String.prototype.trim.rtrim,"" );
          };
          
          String.prototype.trim.rtrim = /^\s*|\s*$/g;
        };
        
        if ( !Function.prototype.bind ){
          Function.prototype.bind = function () {
            var argArray = Array.prototype.slice.call( arguments ),
                context = argArray.shift(),
                ret = function () {
                  var args = argArray.concat( Array.prototype.slice.call( arguments ) );
                  
                  if ( this !== null && this !== window && this instanceof ret ){
                    return ret.context.apply( this,args );
                  } else {
                    return ret.context.apply( context,args );
                  };
                };
            
            ret.prototype = this.prototype;
            
            ret.context = this;
            return ret;
          };
        };
        
        if ( !Array.prototype.forEach ){
          Array.prototype.forEach = function ( fn,that ) {
            var iter = -1,
                ta;
            
            if ( that ){
              while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                fn.call( that,ta,iter,this );
              };
            } else {
              while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                fn( ta,iter,this );
              };
            };
          };
        };
        
        if ( !Array.prototype.every ){
          Array.prototype.every = function ( fn,that ) {
            var iter = -1,
                ta;
            
            if ( that ){
              while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                if ( !( fn.call( that,ta,iter,this ) ) ){
                  return false;
                };
              };
            } else {
              while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                if ( !( fn( ta,iter,this ) ) ){
                  return false;
                };
              };
            };
            return true;
          };
        };
        
        if ( !Array.prototype.some ){
          Array.prototype.some = function ( fn,that ) {
            var iter = -1,
                ta;
            
            if ( that ){
              while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                if ( fn.call( that,ta,iter,this ) ){
                  return true;
                };
              };
            } else {
              while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
                if ( fn( ta,iter,this ) ){
                  return true;
                };
              };
            };
            return false;
          };
        };
        
        if ( !Array.prototype.filter ){
          Array.prototype.filter = function ( fn,that ) {
            var iter = -1,
                ret = [],
                ta;
            
            if ( that ){
              for ( var i = 0,len = this.length;i<len; ++ i ){
                if ( ( ta = this[i] ) !== null && ta !== undefined ){
                  if ( fn.call( that,ta,i,this ) ){
                    ret[ ++ iter] = ta;
                  };
                };
              };
            } else {
              for ( var i = 0,len = this.length;i<len; ++ i ){
                if ( ( ta = this[i] ) !== null && ta !== undefined ){
                  if ( fn( ta,i,this ) ){
                    ret[ ++ iter] = ta;
                  };
                };
              };
            };
            return ret;
          };
        };
        
        if ( !Array.prototype.indexOf ){
          Array.prototype.indexOf = function ( subject ) {
            var iter = -1,
                index = -1,
                ta;
            
            while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
              if ( ta === subject ){
                index = iter;
                break;
              };
            };
            return index;
          };
        };
        
        if ( !Array.prototype.lastIndexOf ){
          Array.prototype.lastIndexOf = function ( subject ) {
            var iter = this.length,
                index = -1,
                ta;
            
            while ( ( ta = this[ -- iter] ) !== null && ta !== undefined ){
              if ( ta === subject ){
                index = iter;
                break;
              };
            };
            return index;
          };
        };
        
        if ( !Array.prototype.map ){
          Array.prototype.map = function ( fn,that ) {
            var ret = [],
                iter = -1,
                ta;
            
            if ( that ){
              for ( var i = 0,len = this.length;i<len; ++ i ){
                if ( ( ta = this[i] ) !== null && ta !== undefined ){
                  ret[ ++ iter] = fn.call( that,ta,i,this );
                };
              };
            } else {
              for ( var i = 0,len = this.length;i<len; ++ i ){
                if ( ( ta = this[i] ) !== null && ta !== undefined ){
                  ret[ ++ iter] = fn( ta,i,this );
                };
              };
            };
            return ret;
          };
        };
        
        if ( !Array.prototype.reduce ){
          Array.prototype.reduce = function ( fn,initial ) {
            var ret = initial || this[0],
                i = ( initial )?0 : 1,
                ta,
                len;
            
            for ( i , len = this.length;i<len; ++ i ){
              if ( ( ta = this[i] ) !== null && ta !== undefined ){
                ret = fn( ret,ta,i,this );
              };
            };
            return ret;
          };
        };
        
        if ( !Array.prototype.reduceRight ){
          Array.prototype.reduceRight = function ( fn,initial ) {
            var ret = initial || this[this.length-1],
                i = ( initial )?this.length-1 : this.length-2,
                ta;
            
            for ( i;i>-1; -- i ){
              if ( ( ta = this[i] ) !== null && ta !== undefined ){
                ret = fn( ret,ta,i,this );
              };
            };
            return ret;
          };
        };
        
        if ( !Date.prototype.toJSON ){
          Date.prototype.toJSON = function () {
            return '"'+this.getUTCFullYear()+'-'+"0"+( this.getUTCMonth()+1 )+'-'+"0"+( this.getUTCDate()-1 )+'T'+this.getUTCHours()+':'+this.getMinutes()+':'+this.getSeconds()+'.'+this.getUTCMilliseconds()+'"';
          };
        };
        
        if ( !Date.now ){
          Date.now = function () {
            return +new Date();
          };
        };
        
        if ( !Object.keys ){
          Object.keys = function ( obj ) {
            var ret = [],
                iter = -1;
            
            for ( var i in obj ){
              if ( obj.hasOwnProperty( i ) ){
                ret[ ++ iter] = obj[i];
              };
            };
            return ret;
          };
        };
        
        if ( !Object.preventExtensions ){
          Object.preventExtensions = function ( o ) {
            return o;
          };
        };
        
        if ( !Object.seal ){
          Object.seal = function ( o ) {
            return o;
          };
        };
        
        if ( !Object.freeze ){
          Object.freeze = function ( o ) {
            return o;
          };
        };
        
        var hasRealEcma5 = ( function () {
              try {
                var obj = {};
                
                Object.defineProperty( obj,"test", {
                  configurable : false,
                  writable : false,
                  enumerable : false,
                  value : 0
                });
                
                obj.test = 200;
                return ( obj.test === 200 )?false : true;
              } catch( e ){
                return false;
              };
            })();
        
        if ( !hasRealEcma5 ){
          Object.defineProperty = function ( obj,prop,valobj ) {
            if ( valobj.value ){
              obj[prop] = valobj.value;
            };
          };
        };
        
        if ( !Array.isArray ){
          var arrayString = "[object Array]";
          
          Array.isArray = function ( arr ) {
            if ( arguments.length === 0 ){
              return false;
            };
            return ( arr )?Object.prototype.toString.call( arr ) === arrayString : false;
          };
        };
        
        var slice = Array.prototype.slice;
        
        var createUnenumProp = _mochaLocalExport.createUnenumProp = function createUnenumProp( obj,prop,value ) {
              return Object.defineProperty( obj,prop, {
                configurable : true,
                enumerable : false,
                writable : true,
                value : value
              });
            };
        
        var constant = _mochaLocalExport.constant = function constant( obj,prop,value ) {
              return Object.defineProperty( obj,prop, {
                configurable : false,
                enumerable : false,
                writable : false,
                value : value
              });
            };
        
        var toArray = _mochaLocalExport.toArray = function toArray( likeArray,index ) {
              return ( likeArray )?slice.call( likeArray,index ) : [];
            };
        
        var Generator = function (){};
        
        var createGenerator = _mochaLocalExport.createGenerator = function createGenerator( generatorFn,closeFn,context ) {
              var ret = new Generator;
              
              createUnenumProp( ret,"next",generatorFn.bind( context,false,false ) );
              
              createUnenumProp( ret,"send",generatorFn.bind( context,true,false ) );
              
              createUnenumProp( ret,"close",closeFn.bind( context ) );
              
              createUnenumProp( ret,"__nothrowNext__",generatorFn.bind( context,false,true ) );
              
              createUnenumProp( ret,"toString",
              function () {
                return "[object Generator]";
              });
              
              Object.freeze( ret );
              return ret;
            };
        
        function getErrorMessage( e ) {
          return ( e.message )?e.message : ( e.description )?e.description : e.toString();
        }
        var throwException = _mochaLocalExport.throwException = Runtime.throwException.bind( Runtime );
        
        var exceptionHandler = _mochaLocalExport.exceptionHandler = Runtime.exceptionHandler.bind( Runtime );
        
        var extendPrototype = _mochaLocalExport.extendPrototype = function ( derived,base ) {
              derived.prototype = base;
            };
        
        var getPrototype = ( "getPrototypeOf" in Object )?function ( obj ) {
              return Object.getPrototypeOf( obj );
            } : function ( obj ) {
              if ( "constructor" in obj ){
                return obj.constructor.prototype || {};
              };
            };
        
        var extendClass = _mochaLocalExport.extendClass = ( Runtime.hasProto )?function ( derived,base ) {
              if ( typeof base === 'function' ){
                derived.prototype.__proto__ = base.prototype;
                
                for ( var i in base ){
                  derived[i] = base[i];
                };
              } else {
                derived.prototype.__proto__ = base.__proto__;
              };
            } : function ( derived,base ) {
              var baseType = typeof base;
              
              if ( baseType === "function" ){
                var inherit = function (){};
                
                inherit.prototype = base.prototype;
                
                derived.prototype = new inherit;
                
                for ( var i in base ){
                  derived[i] = base[i];
                };
              } else {
                var inherit = function (){},
                    proto = getPrototype( base );
                
                inherit.prototype = proto;
                
                derived.prototype = new inherit;
              };
            };
        
        var __ref_iterator__ = _mochaLocalExport.__ref_iterator__ = "__mocha_iterator_special_key__";
        
        var throwStopIteration = _mochaLocalExport.throwStopIteration = function throwStopIteration() {
              try {
                throw StopIteration;
              } catch( e ){
                throw new Error( e.toString() );
              };
            };
        
        var isGenerator = _mochaLocalExport.isGenerator = function isGenerator( obj ) {
              return obj instanceof Generator;
            };
        
        var getIterator = _mochaLocalExport.getIterator = function getIterator( obj ) {
              var ret = obj[__ref_iterator__](),
                  newObj;
              
              if ( isGenerator( ret ) ){
                return ret;
              };
              
              newObj = {};
              
              if ( ret.next ){
                createUnenumProp( newObj,"next",
                function () {
                  var result = ret.next();
                  
                  if ( result === undefined ){
                    throwStopIteration();
                  };
                  return result;
                });
              } else {
                return {};
              };
              
              if ( !( "__nothrowNext__" in ret ) ){
                createUnenumProp( newObj,"__nothrowNext__",ret.next.bind( ret ) );
              };
              
              for ( var prop in ret ){
                if ( prop !== "next" && prop !== "__nothrowNext__" ){
                  newObj[prop] = ret[prop];
                };
              };
              
              if ( !( "toString" in ret ) ){
                createUnenumProp( newObj,"toString",
                function () {
                  return "[object Iterator]";
                });
              };
              return newObj;
            };
        
        var hasIterator = _mochaLocalExport.hasIterator = function hasIterator( obj ) {
              return __ref_iterator__ in obj;
            };
        
        var rstopIteration = /StopIteration/;
        
        var isStopIteration = _mochaLocalExport.isStopIteration = function isStopIteration( obj ) {
              return obj === StopIteration || rstopIteration.test( obj );
            };
        
        var privateRecord,
            createPrivateRecord,
            getPrivateRecord;
        
        if ( "WeakMap" in window ){
          privateRecord = new WeakMap();
          
          createPrivateRecord = function ( self,privateHolder ) {
            privateRecord.set( self,new privateHolder );
          };
          
          getPrivateRecord = function ( self ) {
            if ( privateRecord.has( self ) ){
              return privateRecord.get( self );
            };
          };
        } else {
          var _uid = ( new Date() );
          
          privateRecord = {};
          
          createPrivateRecord = function ( self,privateHolder ) {
            if ( !self.__typeid__ ){
              var id = _uid ++ ;
              
              createUnenumProp( self,"__typeid__",id );
              
              privateRecord[id] = new privateHolder;
            };
          };
          
          getPrivateRecord = function ( self ) {
            if ( self.__typeid__ ){
              return privateRecord[self.__typeid__];
            };
          };
          if ( "addEventListener" in document ){
            window.addEventListener( "unload",
            function () {
              for ( var i in privateRecord ){
                delete privateRecord[i];
              };
            },false);
          };
        };
        
        ( _mochaLocalExport.createPrivateRecord = createPrivateRecord );
        
        ( _mochaLocalExport.getPrivateRecord = getPrivateRecord );
        
        var getSuper = _mochaLocalExport.getSuper = function getSuper( obj ) {
              var type = typeof obj,
                  ret;
              
              if ( type === "function" ){
                ret = function (){};
                
                ret.prototype = obj.prototype;
                
                ret = new ret();
                
                if ( obj.__harmony_class__ ){
                  ret.constructor = obj.constructor;
                } else {
                  ret.constructor = obj;
                };
                return ret;
              };
              return ret;
            };
        
        ( function () {
          var assert = _mochaLocalExport.assert = ( console && console.assert )?function ( expect,exp,str,line,filename ) {
                return console.assert( expect === exp,"assertion failed : "+str+"\nexpect "+expect+" but got "+exp+"\nin file "+filename+" at : "+line );
              } : function ( expect,exp,str,line,filename ) {
                if ( expect !== exp ){
                  Runtime.throwException( "assertion failed : "+str+"\nexpect "+expect+" but got "+exp+"\nin file "+filename+" at : "+line );
                };
              };
        })();
        return _mochaLocalExport;
      })();
  
  if ( !( "StopIteration" in window ) ){
    window.StopIteration =  {
      toString : function toString() {
        return "[object StopIteration]";
      }
    };
  };
  
  __LINE__ = 0;
  ( function () {
    try {
      var __FILE__ = "/var/samba/mocha/src/test/js/262/lib/json2_compiled.js",
          __LINE__ = 0;
      __LINE__ = 2;
      _mochaGlobalExport['./json2_compiled.js'] = {};
      
      __LINE__ = 3;
      var _mochaGlobalAlias = _mochaGlobalExport['./json2_compiled.js'];
      
      __LINE__ = 1;
      var g = null;
      
      __LINE__ = 1;
      var json_parse = function () {
            try {
              function o() {
                try {
                  __LINE__ = 0;
                  switch ( a ) {
                    case "t" :
                      __LINE__ = 1;
                      return b( "t" ) , b( "r" ) , b( "u" ) , b( "e" ) , !0;
                    case "f" :
                      __LINE__ = 1;
                      return b( "f" ) , b( "a" ) , b( "l" ) , b( "s" ) , b( "e" ) , !1;
                    case "n" :
                      __LINE__ = 1;
                      return b( "n" ) , b( "u" ) , b( "l" ) , b( "l" ) , g;
                      
                  };
                  
                  __LINE__ = 0;
                  h( "Unexpected '"+a+"'" );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              function e() {
                try {
                  __LINE__ = 1;
                  for ( ;a && a <= " "; ){
                    __LINE__ = 0;
                    b( g );
                  };
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              function l() {
                try {
                  __LINE__ = 1;
                  var c,
                      f,
                      d = "",
                      e;
                  
                  __LINE__ = 1;
                  if ( a === '"' ){
                    __LINE__ = 1;
                    for ( ;b( g ); ){
                      __LINE__ = 1;
                      if ( a === '"' ){
                        __LINE__ = 1;
                        return b( g ) , d;
                      } else if ( a === "\\" ){
                        if ( b( g ) , a === "u" ){
                          __LINE__ = 1;
                          for ( f = e = 0;f<4;f += 1 ){
                            __LINE__ = 0;
                            c = parseInt( b( g ),16 );
                            if ( !isFinite( c ) ){
                              __LINE__ = 1;
                              break;
                            };
                            
                            __LINE__ = 0;
                            e = e*16+c;
                          };
                          
                          __LINE__ = 0;
                          d += String.fromCharCode( e );
                        } else if ( typeof m[a] === "string" ){
                          __LINE__ = 0;
                          d += m[a];
                        } else {
                          __LINE__ = 1;
                          break;
                        };
                      } else {
                        __LINE__ = 0;
                        d += a;
                      };
                    };
                  };
                  
                  __LINE__ = 0;
                  h( "Bad string" );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              function n() {
                try {
                  __LINE__ = 1;
                  var c;
                  
                  __LINE__ = 0;
                  c = "";
                  
                  __LINE__ = 0;
                  a === "-" && ( c = "-" , b( "-" ) );
                  
                  __LINE__ = 1;
                  for ( ;a >= "0" && a <= "9"; ){
                    __LINE__ = 0;
                    c += a , b( g );
                  };
                  
                  __LINE__ = 1;
                  if ( a === "." ){
                    __LINE__ = 1;
                    for ( c += ".";b( g ) && a >= "0" && a <= "9"; ){
                      __LINE__ = 0;
                      c += a;
                    };
                  };
                  
                  __LINE__ = 1;
                  if ( a === "e" || a === "E" ){
                    __LINE__ = 0;
                    c += a;
                    
                    __LINE__ = 0;
                    b( g );
                    
                    __LINE__ = 1;
                    if ( a === "-" || a === "+" ){
                      __LINE__ = 0;
                      c += a , b( g );
                    };
                    
                    __LINE__ = 1;
                    for ( ;a >= "0" && a <= "9"; ){
                      __LINE__ = 0;
                      c += a , b( g );
                    };
                  };
                  
                  __LINE__ = 0;
                  c = +c;
                  
                  __LINE__ = 1;
                  if ( isFinite( c ) ){
                    __LINE__ = 1;
                    return c;
                  } else {
                    __LINE__ = 0;
                    h( "Bad number" );
                  };
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              function b( b ) {
                try {
                  __LINE__ = 0;
                  b && b !== a && h( "Expected '"+b+"' instead of '"+a+"'" );
                  
                  __LINE__ = 0;
                  a = k.charAt( i );
                  
                  __LINE__ = 0;
                  i += 1;
                  __LINE__ = 1;
                  return a;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              function h( a ) {
                try {
                  __LINE__ = 1;
                  throw  {
                    name : "SyntaxError",
                    message : a,
                    a : i,
                    text : k
                  };
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              __LINE__ = 1;
              var i,
                  a,
                  m =  {
                    '"' : '"',
                    "\\" : "\\",
                    "/" : "/",
                    b : "\u0008",
                    f : "\u000c",
                    n : "\n",
                    r : "\r",
                    t : "\t"
                  },
                  k,
                  j;
              
              __LINE__ = 0;
              j = function () {
                try {
                  __LINE__ = 0;
                  e();
                  
                  __LINE__ = 0;
                  switch ( a ) {
                    case "{" :
                      
                      __LINE__ = 1;
                      var c;
                      __LINE__ = 1;
                      a : 
                      {
                        __LINE__ = 1;
                        var f,
                            d = {};
                        
                        __LINE__ = 1;
                        if ( a === "{" ){
                          __LINE__ = 0;
                          b( "{" );
                          
                          __LINE__ = 0;
                          e();
                          
                          __LINE__ = 1;
                          if ( a === "}" ){
                            __LINE__ = 0;
                            b( "}" );
                            
                            __LINE__ = 0;
                            c = d;
                            __LINE__ = 1;
                            break a;
                          };
                          
                          __LINE__ = 1;
                          for ( ;a; ){
                            __LINE__ = 0;
                            f = l();
                            
                            __LINE__ = 0;
                            e();
                            
                            __LINE__ = 0;
                            b( ":" );
                            
                            __LINE__ = 0;
                            Object.hasOwnProperty.call( d,f ) && h( 'Duplicate key "'+f+'"' );
                            
                            __LINE__ = 0;
                            d[f] = j();
                            
                            __LINE__ = 0;
                            e();
                            
                            __LINE__ = 1;
                            if ( a === "}" ){
                              __LINE__ = 0;
                              b( "}" );
                              
                              __LINE__ = 0;
                              c = d;
                              __LINE__ = 1;
                              break a;
                            };
                            
                            __LINE__ = 0;
                            b( "," );
                            
                            __LINE__ = 0;
                            e();
                          };
                        };
                        
                        __LINE__ = 0;
                        h( "Bad object" );
                      };
                      __LINE__ = 1;
                      return c;
                    case "[" :
                      __LINE__ = 1;
                      a : 
                      {
                        __LINE__ = 0;
                        c = [];
                        
                        __LINE__ = 1;
                        if ( a === "[" ){
                          __LINE__ = 0;
                          b( "[" );
                          
                          __LINE__ = 0;
                          e();
                          
                          __LINE__ = 1;
                          if ( a === "]" ){
                            __LINE__ = 0;
                            b( "]" );
                            
                            __LINE__ = 0;
                            f = c;
                            __LINE__ = 1;
                            break a;
                          };
                          
                          __LINE__ = 1;
                          for ( ;a; ){
                            __LINE__ = 0;
                            c.push( j() );
                            
                            __LINE__ = 0;
                            e();
                            
                            __LINE__ = 1;
                            if ( a === "]" ){
                              __LINE__ = 0;
                              b( "]" );
                              
                              __LINE__ = 0;
                              f = c;
                              __LINE__ = 1;
                              break a;
                            };
                            
                            __LINE__ = 0;
                            b( "," );
                            
                            __LINE__ = 0;
                            e();
                          };
                        };
                        
                        __LINE__ = 0;
                        h( "Bad array" );
                      };
                      __LINE__ = 1;
                      return f;
                    case '"' :
                      __LINE__ = 1;
                      return l();
                    case "-" :
                      __LINE__ = 1;
                      return n();
                    default :
                      __LINE__ = 1;
                      return a >= "0" && a <= "9"?n() : o();
                      
                  };
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              __LINE__ = 1;
              return function ( b,f ) {
                try {
                  __LINE__ = 1;
                  var d;
                  
                  __LINE__ = 0;
                  k = b;
                  
                  __LINE__ = 0;
                  i = 0;
                  
                  __LINE__ = 0;
                  a = " ";
                  
                  __LINE__ = 0;
                  d = j();
                  
                  __LINE__ = 0;
                  e();
                  
                  __LINE__ = 0;
                  a && h( "Syntax error" );
                  __LINE__ = 1;
                  return typeof f === "function"?function p( a,b ) {
                    try {
                      __LINE__ = 1;
                      var c,
                          e,
                          d = a[b];
                      
                      __LINE__ = 1;
                      if ( d && typeof d === "object" ){
                        __LINE__ = 1;
                        for ( c in d ){
                          __LINE__ = 0;
                          Object.prototype.hasOwnProperty.call( d,c ) && ( e = p( d,c ) , e !== void 0?d[c] = e : delete d[c] );
                        };
                      };
                      __LINE__ = 1;
                      return f.call( a,b,d );
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  }(  {
                    "" : d
                  },"") : d;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }();
      
      __LINE__ = 0;
      ( function () {
        try {
          __LINE__ = 4;
          var json_str = '{"test" : 1,"test2":"test2","test3":null,"test4":{"test5":5}}';
          
          __LINE__ = 5;
          var json = json_parse( json_str );
          
          __LINE__ = 6;
          Runtime.assert( true,json["test"] === 1,"json[\"test\"] === 1",6,'./json2_compiled.js' );
          
          __LINE__ = 7;
          Runtime.assert( true,json["test2"] === "test2","json[\"test2\"] === \"test2\"",7,'./json2_compiled.js' );
          
          __LINE__ = 8;
          Runtime.assert( true,json["test3"] === null,"json[\"test3\"] === null",8,'./json2_compiled.js' );
          
          __LINE__ = 9;
          Runtime.assert( true,json["test4"]["test5"] === 5,"json[\"test4\"][\"test5\"] === 5",9,'./json2_compiled.js' );
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      })();
    } catch( e ){
      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  })();
})();
