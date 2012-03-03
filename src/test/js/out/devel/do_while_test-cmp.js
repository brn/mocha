!function() {
  var __FILE__ = "Runtime",
      __LINE__ = 0;
  
  __LINE__ = 25;
  var _mochaGlobalExport = {};
  
  __LINE__ = 33;
  !function ( _mochaLocalTmp0,_mochaLocalTmp1,_mochaLocalTmp2,_mochaLocalTmp3 ) {
    try {
      function callbackCheck( callback,type ) {
        try {
          
          __LINE__ = 43;
          Runtime.assert( true,typeof type === "string","typeof type === \"string\"",43,'./mocha_runtime.js' );
          
          __LINE__ = 44;
          if ( typeof callback !== "function" ){
            
            __LINE__ = 45;
            builtinTypeError( type+" : first argument is not callable" );
          };
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }
      function builtinTypeError( message ) {
        try {
          try {
            __LINE__ = 36;
            throw new TypeError( message );
          } catch( e ){
            __LINE__ = 38;
            throw new Error( e );
          };
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }
      __LINE__ = 33;
      var stringProto = _mochaLocalTmp0.prototype,
          arrayProto = _mochaLocalTmp1.prototype,
          functionProto = _mochaLocalTmp2.prototype,
          dateProto = _mochaLocalTmp3.prototype;
      
      __LINE__ = 57;
      !Object.keys && ( Object.keys = function ( obj ) {
        try {
          __LINE__ = 59;
          !obj && builtinTypeError( "Object.keys : first arguments is null or not defined." );
          
          __LINE__ = 61;
          var ret = [],
              iter = -1;
          
          __LINE__ = 63;
          for ( var i in obj ){
            
            __LINE__ = 65;
            obj.hasOwnProperty( i ) && ( ret[ ++ iter] = obj[i] );
          };
          __LINE__ = 68;
          return ret;
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      });
      
      __LINE__ = 77;
      !Object.preventExtensions && ( Object.preventExtensions = function ( o ) {
        try {
          __LINE__ = 77;
          return o;
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      });
      
      __LINE__ = 85;
      !Object.seal && ( Object.seal = function ( o ) {
        try {
          __LINE__ = 85;
          return o;
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      });
      
      __LINE__ = 93;
      !Object.freeze && ( Object.freeze = function ( o ) {
        try {
          __LINE__ = 93;
          return o;
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      });
      
      __LINE__ = 101;
      var hasRealEcma5 = function () {
            try {
              __LINE__ = 102;
              var ret;
              
              try {
                
                __LINE__ = 104;
                var obj = {};
                
                __LINE__ = 105;
                Object.defineProperty( obj,"test", {
                  configurable : false,
                  writable : false,
                  enumerable : false,
                  value : 0
                });
                
                __LINE__ = 111;
                obj.test = 200;
                
                __LINE__ = 112;
                ret = ( obj.test === 200 )?false : true;
              } catch( e ){
                
                __LINE__ = 114;
                ret = false;
              };
              __LINE__ = 116;
              return ret;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }();
      
      __LINE__ = 127;
      !hasRealEcma5 && ( Object.defineProperty = function ( obj,prop,valobj ) {
        try {
          __LINE__ = 129;
          valobj.value && ( obj[prop] = valobj.value );
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      });
      
      __LINE__ = 134;
      if ( !stringProto.trim ){
        
        __LINE__ = 140;
        stringProto.trim = function () {
          try {
            __LINE__ = 140;
            return this.replace( stringProto.trim.rtrim,"" );
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        };
        
        __LINE__ = 142;
        stringProto.trim.rtrim = /^\s*|\s*$/g;
      };
      
      __LINE__ = 147;
      !stringProto.repeat && Object.defineProperty( stringProto,"repeat", {
        value : function ( num ) {
          try {
            __LINE__ = 148;
            return Array( num+1 ).join( this.toString() );
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        },
        configurable : true,
        enumerable : false,
        writable : true
      });
      
      __LINE__ = 156;
      !stringProto.startsWith && Object.defineProperty( stringProto,"startsWith", {
        value : function ( str ) {
          try {
            __LINE__ = 157;
            return !this.indexOf( str );
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        },
        configurable : true,
        enumerable : false,
        writable : true
      });
      
      __LINE__ = 165;
      !stringProto.endsWith && Object.defineProperty( stringProto,"endsWith", {
        value : function ( str ) {
          try {
            __LINE__ = 167;
            var t = String( str );
            
            __LINE__ = 168;
            var index = this.lastIndexOf( t );
            __LINE__ = 169;
            return index >= 0 && index === this.length-t.length;
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        },
        configurable : true,
        enumerable : false,
        writable : true
      });
      
      __LINE__ = 178;
      !stringProto.contains && Object.defineProperty( stringProto,"contains", {
        value : function ( str ) {
          try {
            __LINE__ = 179;
            return this.indexOf( str ) !== -1;
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        },
        configurable : true,
        enumerable : false,
        writable : true
      });
      
      __LINE__ = 187;
      !stringProto.toArray && Object.defineProperty( stringProto,"toArray", {
        value : function ( str ) {
          try {
            __LINE__ = 188;
            return this.split( "" );
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        },
        configurable : true,
        enumerable : false,
        writable : true
      });
      
      __LINE__ = 206;
      !functionProto.bind && ( functionProto.bind = function () {
        try {
          __LINE__ = 207;
          var argArray = arrayProto.slice.call( arguments ),
              context = argArray.shift(),
              ret = function () {
                try {
                  __LINE__ = 210;
                  var args = argArray.concat( arrayProto.slice.call( arguments ) );
                  
                  __LINE__ = 211;
                  if ( this !== null && this !== window && this instanceof ret ){
                    __LINE__ = 212;
                    return ret.context.apply( this,args );
                  } else {
                    __LINE__ = 214;
                    return ret.context.apply( context,args );
                  };
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
          
          __LINE__ = 218;
          ret.prototype = this.prototype;
          
          __LINE__ = 219;
          ret.context = this;
          __LINE__ = 220;
          return ret;
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      });
      
      __LINE__ = 239;
      !arrayProto.forEach && ( arrayProto.forEach = function ( callback,that ) {
        try {
          __LINE__ = 240;
          callbackCheck( callback,"Array.forEach" );
          
          __LINE__ = 241;
          var iter = -1,
              ta;
          
          __LINE__ = 244;
          this === null && builtinTypeError( "Array.forEach : this is null or not defined" );
          
          __LINE__ = 246;
          if ( that ){
            __LINE__ = 247;
            while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
              callback.call( that,ta,iter,this )
            };
          } else {
            __LINE__ = 251;
            while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
              callback( ta,iter,this )
            };
          };
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      });
      
      __LINE__ = 272;
      !arrayProto.every && ( arrayProto.every = function ( callback,that ) {
        try {
          __LINE__ = 273;
          callbackCheck( callback,"Array.every" );
          
          __LINE__ = 274;
          var iter = -1,
              ta;
          
          __LINE__ = 277;
          this === null && builtinTypeError( "Array.every : this is null or not defined" );
          
          __LINE__ = 279;
          if ( that ){
            __LINE__ = 280;
            while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
              
              __LINE__ = 281;
              if ( !( callback.call( that,ta,iter,this ) ) ){
                __LINE__ = 282;
                return false;
              };
            };
          } else {
            __LINE__ = 286;
            while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
              if ( !( callback( ta,iter,this ) ) ){
                __LINE__ = 288;
                return false;
              };
            };
          };
          __LINE__ = 292;
          return true;
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      });
      
      __LINE__ = 310;
      !arrayProto.some && ( arrayProto.some = function ( callback,that ) {
        try {
          __LINE__ = 311;
          callbackCheck( callback,"Array.some" );
          
          __LINE__ = 312;
          var iter = -1,
              ta;
          
          __LINE__ = 315;
          this === null && builtinTypeError( "Array.some : this is null or not defined" );
          
          __LINE__ = 317;
          if ( that ){
            __LINE__ = 318;
            while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
              
              __LINE__ = 319;
              if ( callback.call( that,ta,iter,this ) ){
                __LINE__ = 320;
                return true;
              };
            };
          } else {
            __LINE__ = 324;
            while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
              if ( callback( ta,iter,this ) ){
                __LINE__ = 326;
                return true;
              };
            };
          };
          __LINE__ = 330;
          return false;
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      });
      
      __LINE__ = 348;
      !arrayProto.filter && ( arrayProto.filter = function ( callback,that ) {
        try {
          __LINE__ = 349;
          callbackCheck( callback,"Array.filter" );
          
          __LINE__ = 350;
          var len = this.length,
              iter = -1,
              ret = [],
              ta;
          
          __LINE__ = 355;
          this === null && builtinTypeError( "Array.filter : this is null or not defined" );
          
          __LINE__ = 357;
          if ( that ){
            __LINE__ = 358;
            for ( var i = 0,len = this.length;i<len; ++ i ){
              
              __LINE__ = 361;
              ( ta = this[i] ) !== null && ta !== undefined && callback.call( that,ta,i,this ) && ( ret[ ++ iter] = ta );
            };
          } else {
            __LINE__ = 366;
            for ( var i = 0,len = this.length;i<len; ++ i ){
              
              __LINE__ = 369;
              ( ta = this[i] ) !== null && ta !== undefined && callback( ta,i,this ) && ( ret[ ++ iter] = ta );
            };
          };
          __LINE__ = 374;
          return ret;
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      });
      
      __LINE__ = 385;
      !arrayProto.indexOf && ( arrayProto.indexOf = function ( subject,fromIndex ) {
        try {
          __LINE__ = 386;
          var iter = ( fromIndex )?fromIndex-1 : -1,
              index = -1,
              ta;
          
          __LINE__ = 390;
          this === null && builtinTypeError( "Array.indexOf : this is null or not defined." );
          
          __LINE__ = 392;
          while ( ( ta = this[ ++ iter] ) !== null && ta !== undefined ){
            
            __LINE__ = 393;
            if ( ta === subject ){
              
              __LINE__ = 394;
              index = iter;
              __LINE__ = 395;
              break;
            };
          };
          __LINE__ = 398;
          return index;
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      });
      
      __LINE__ = 410;
      !arrayProto.lastIndexOf && ( arrayProto.lastIndexOf = function ( target,fromIndex ) {
        try {
          __LINE__ = 411;
          var len = this.length,
              iter = ( fromIndex )?fromIndex+1 : len,
              index = -1,
              ta;
          
          __LINE__ = 416;
          this === null && builtinTypeError( "Array.lastIndexOf : this is null or not defined." );
          
          __LINE__ = 418;
          while ( ( ta = this[ -- iter] ) !== null && ta !== undefined ){
            
            __LINE__ = 419;
            if ( ta === target ){
              
              __LINE__ = 420;
              index = iter;
              __LINE__ = 421;
              break;
            };
          };
          __LINE__ = 424;
          return index;
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      });
      
      __LINE__ = 444;
      !arrayProto.map && ( arrayProto.map = function ( callback,that ) {
        try {
          __LINE__ = 445;
          callbackCheck( callback,"Array.map" );
          
          __LINE__ = 446;
          var ret = [],
              iter = -1,
              len = this.length,
              i = 0,
              ta;
          
          __LINE__ = 452;
          this === null && builtinTypeError( "Array.map : this is null or not defined." );
          
          __LINE__ = 454;
          if ( that ){
            __LINE__ = 455;
            for ( i;i<len; ++ i ){
              
              __LINE__ = 457;
              ( ta = this[i] ) !== null && ta !== undefined && ( ret[ ++ iter] = callback.call( that,ta,i,this ) );
            };
          } else {
            __LINE__ = 461;
            for ( i;i<len; ++ i ){
              
              __LINE__ = 463;
              ( ta = this[i] ) !== null && ta !== undefined && ( ret[ ++ iter] = callback( ta,i,this ) );
            };
          };
          __LINE__ = 467;
          return ret;
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      });
      
      __LINE__ = 490;
      !arrayProto.reduce && ( arrayProto.reduce = function ( callback,initial ) {
        try {
          __LINE__ = 491;
          callbackCheck( callback,"Array.reduce" );
          
          __LINE__ = 492;
          var ret = initial || this[0],
              i = ( initial )?0 : 1,
              len = this.length,
              ta;
          
          __LINE__ = 497;
          ( len === 0 || len === null ) && arguments.length<2 && builtinTypeError( "Array length is 0 and no second argument" );
          
          __LINE__ = 499;
          for ( i;i<len; ++ i ){
            
            __LINE__ = 501;
            ( ta = this[i] ) !== null && ta !== undefined && ( ret = callback( ret,ta,i,this ) );
          };
          __LINE__ = 504;
          return ret;
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      });
      
      __LINE__ = 527;
      !arrayProto.reduceRight && ( arrayProto.reduceRight = function ( callback,initial ) {
        try {
          __LINE__ = 528;
          callbackCheck( callback,"Array.reduceRight" );
          
          __LINE__ = 529;
          var len = this.length,
              ret = initial || this[len-1],
              i = ( initial )?len-1 : len-2,
              ta;
          
          __LINE__ = 534;
          ( len === 0 || len === null ) && arguments.length<2 && builtinTypeError( "Array length is 0 and no second argument" );
          
          __LINE__ = 536;
          for ( i;i>-1; -- i ){
            
            __LINE__ = 538;
            ( ta = this[i] ) !== null && ta !== undefined && ( ret = callback( ret,ta,i,this ) );
          };
          __LINE__ = 541;
          return ret;
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      });
      
      __LINE__ = 553;
      !dateProto.toJSON && ( dateProto.toJSON = function () {
        try {
          __LINE__ = 554;
          var _mochaLocalTmp4 = [],
              month = _mochaLocalTmp4[0],
              date = _mochaLocalTmp4[1],
              hour = _mochaLocalTmp4[2],
              minute = _mochaLocalTmp4[3],
              second = _mochaLocalTmp4[4];
          __LINE__ = 561;
          return '"'+this.getUTCFullYear()+'-'+( month>8?month+1 : "0"+( month+1 ) )+'-'+( date>9?date : "0"+date )+'T'+( hour>9?hour : "0"+hour )+':'+( minute>9?minute : "0"+minute )+':'+( second>9?second : "0"+second )+'.'+this.getUTCMilliseconds()+'Z"';
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      });
      
      __LINE__ = 577;
      !Date.now && ( Date.now = function () {
        try {
          __LINE__ = 577;
          return +new Date();
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      });
      
      __LINE__ = 587;
      !Array.isArray && ( Array.isArray = function ( arr ) {
        try {
          __LINE__ = 588;
          if ( arguments.length === 0 ){
            __LINE__ = 589;
            return false;
          };
          __LINE__ = 591;
          return ( arr )?( {} ).toString.call( arr ) === "[object Array]" : false;
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      });
    } catch( e ){
      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  }.call( this,String,Array,Function,Date );
  
  __LINE__ = 603;
  var Runtime = function () {
        try {
          __LINE__ = 603;
          var _mochaLocalExport = {};
          
          function Exception( line,file,e ) {
            try {
              __LINE__ = 613;
              this.toString = function () {
                try {
                  __LINE__ = 613;
                  return Runtime.getErrorMessage( e )+" in file "+file+" at : "+line;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          __LINE__ = 615;
          var _mochaLocalTmp5 = Math,
              max = _mochaLocalTmp5.max;
          
          __LINE__ = 616;
          var _mochaLocalTmp6 = Array.prototype,
              slice = _mochaLocalTmp6.slice;
          
          __LINE__ = 619;
          var Runtime =  {
                getErrorMessage : function ( e ) {
                  try {
                    __LINE__ = 620;
                    return ( e.message )?e.message : ( e.description )?e.description : e.toString();
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                exceptionHandler : function ( line,file,e ) {
                  try {
                    __LINE__ = 622;
                    if ( isStopIteration( e ) ){
                      
                      __LINE__ = 623;
                      this.throwException( e );
                    } else {
                      
                      __LINE__ = 625;
                      this.throwException( new Exception( line,file,e ) );
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                throwException : function ( exception ) {
                  try {
                    try {
                      __LINE__ = 630;
                      throw exception;
                    } catch( e ){
                      
                      __LINE__ = 632;
                      if ( isStopIteration( e ) ){
                        __LINE__ = 633;
                        throw new Error( e );
                      } else {
                        __LINE__ = 635;
                        throw new Error( this.getErrorMessage( e ) );
                      };
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                hasProto : "__proto__" in {}
              };
          
          function createUnenumProp( obj,prop,value ) {
            try {
              __LINE__ = 642;
              return Object.defineProperty( obj,prop, {
                configurable : true,
                enumerable : false,
                writable : true,
                value : value
              });
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          __LINE__ = 642;
          _mochaLocalExport.createUnenumProp = createUnenumProp;
          
          function constant( obj,prop,value ) {
            try {
              __LINE__ = 649;
              return Object.defineProperty( obj,prop, {
                configurable : false,
                enumerable : false,
                writable : false,
                value : value
              });
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          __LINE__ = 649;
          _mochaLocalExport.constant = constant;
          
          function toArray( likeArray,index ) {
            try {
              __LINE__ = 656;
              return ( likeArray )?slice.call( likeArray,index ) : [];
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          __LINE__ = 656;
          _mochaLocalExport.toArray = toArray;
          
          function Generator(  ){}
          function createGenerator( generatorFn,closeFn,context ) {
            try {
              __LINE__ = 660;
              var ret = new Generator;
              
              __LINE__ = 661;
              createUnenumProp( ret,"next",generatorFn.bind( context,false,false ) );
              
              __LINE__ = 662;
              createUnenumProp( ret,"send",generatorFn.bind( context,true,false ) );
              
              __LINE__ = 663;
              createUnenumProp( ret,"close",closeFn.bind( context ) );
              
              __LINE__ = 664;
              createUnenumProp( ret,"__nothrowNext__",generatorFn.bind( context,false,true ) );
              
              __LINE__ = 665;
              createUnenumProp( ret,"toString",
              function () {
                try {
                  __LINE__ = 665;
                  return "[object Generator]";
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              });
              
              __LINE__ = 666;
              Object.freeze( ret );
              __LINE__ = 667;
              return ret;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          __LINE__ = 659;
          _mochaLocalExport.createGenerator = createGenerator;
          
          function getErrorMessage( e ) {
            try {
              __LINE__ = 670;
              return ( e.message )?e.message : ( e.description )?e.description : e.toString();
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          __LINE__ = 672;
          var throwException = _mochaLocalExport.throwException = Runtime.throwException.bind( Runtime );
          
          __LINE__ = 674;
          var exceptionHandler = _mochaLocalExport.exceptionHandler = Runtime.exceptionHandler.bind( Runtime );
          
          function extend( dest,source ) {
            try {
              __LINE__ = 677;
              for ( var prop in source ){
                
                __LINE__ = 678;
                dest[prop] = source[prop];
              };
              __LINE__ = 680;
              return dest;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          __LINE__ = 676;
          _mochaLocalExport.extend = extend;
          
          function compareTuple( tuple ) {
            try {
              __LINE__ = 684;
              var maxIndex = max( tuple.length,this.length ),
                  i = -1;
              
              __LINE__ = 686;
              while (  ++ i<maxIndex && tuple[i] === this[i] ){
                
              };
              __LINE__ = 687;
              return maxIndex === i;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          function tupleToArray() {
            try {
              __LINE__ = 690;
              return Array.prototype.slice.call( this );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          function createTuple( obj,size ) {
            try {
              __LINE__ = 693;
              createUnenumProp( obj,"length",size );
              
              __LINE__ = 694;
              createUnenumProp( obj,"equal",compareTuple );
              
              __LINE__ = 695;
              createUnenumProp( obj,"toArray",tupleToArray );
              
              __LINE__ = 696;
              createUnenumProp( obj,"toString",
              function () {
                try {
                  __LINE__ = 696;
                  return "[object Tuple]";
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              });
              __LINE__ = 697;
              return Object.freeze( obj );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          __LINE__ = 692;
          _mochaLocalExport.createTuple = createTuple;
          
          function createRecord( obj ) {
            try {
              __LINE__ = 701;
              if ( obj.toString() === "[object Object]" ){
                
                __LINE__ = 702;
                createUnenumProp( obj,"toString",
                function () {
                  try {
                    __LINE__ = 702;
                    return "[object Record]";
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                });
              };
              __LINE__ = 704;
              return Object.freeze( obj );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          __LINE__ = 700;
          _mochaLocalExport.createRecord = createRecord;
          
          __LINE__ = 707;
          var extendPrototype = _mochaLocalExport.extendPrototype = function ( derived,base ) {
                try {
                  __LINE__ = 708;
                  derived.prototype = base;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
          
          __LINE__ = 711;
          var getPrototype = ( "getPrototypeOf" in Object )?function ( obj ) {
                try {
                  __LINE__ = 712;
                  return Object.getPrototypeOf( obj );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              } : function ( obj ) {
                try {
                  __LINE__ = 714;
                  var ret = {};
                  
                  __LINE__ = 715;
                  for ( var i in obj ){
                    
                    __LINE__ = 716;
                    if ( !obj.hasOwnProperty( i ) ){
                      
                      __LINE__ = 717;
                      ret[i] = obj[i];
                    };
                  };
                  __LINE__ = 720;
                  return ret;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
          
          __LINE__ = 723;
          var extendClass = _mochaLocalExport.extendClass = ( Runtime.hasProto )?function ( derived,base ) {
                try {
                  __LINE__ = 725;
                  if ( typeof base === 'function' ){
                    
                    __LINE__ = 726;
                    derived.prototype.__proto__ = base.prototype;
                    
                    __LINE__ = 727;
                    for ( var i in base ){
                      
                      __LINE__ = 728;
                      derived[i] = base[i];
                    };
                  } else {
                    
                    __LINE__ = 731;
                    derived.prototype.__proto__ = base.__proto__;
                  };
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              } : function ( derived,base ) {
                try {
                  __LINE__ = 735;
                  var baseType = typeof base;
                  
                  __LINE__ = 736;
                  if ( baseType === "function" ){
                    
                    __LINE__ = 737;
                    var inherit = function (){};
                    
                    __LINE__ = 738;
                    inherit.prototype = base.prototype;
                    
                    __LINE__ = 739;
                    derived.prototype = new inherit;
                    
                    __LINE__ = 740;
                    for ( var i in base ){
                      
                      __LINE__ = 741;
                      derived[i] = base[i];
                    };
                  } else {
                    
                    __LINE__ = 744;
                    var inherit = function (){},
                        proto = getPrototype( base );
                    
                    __LINE__ = 746;
                    inherit.prototype = proto;
                    
                    __LINE__ = 747;
                    derived.prototype = new inherit;
                  };
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
          
          __LINE__ = 751;
          var __ref_iterator__ = _mochaLocalExport.__ref_iterator__ = "__mocha_iterator_special_key__";
          
          function throwStopIteration() {
            try {
              try {
                __LINE__ = 755;
                throw StopIteration;
              } catch( e ){
                __LINE__ = 757;
                throw new Error( e.toString() );
              };
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          __LINE__ = 753;
          _mochaLocalExport.throwStopIteration = throwStopIteration;
          
          function isGenerator( obj ) {
            try {
              __LINE__ = 762;
              return obj instanceof Generator;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          __LINE__ = 761;
          _mochaLocalExport.isGenerator = isGenerator;
          
          function getIterator( obj ) {
            try {
              __LINE__ = 766;
              var ret = obj[__ref_iterator__](),
                  newObj;
              
              __LINE__ = 768;
              if ( isGenerator( ret ) ){
                __LINE__ = 769;
                return ret;
              };
              
              __LINE__ = 771;
              newObj = {};
              
              __LINE__ = 772;
              if ( ret.next ){
                
                __LINE__ = 773;
                createUnenumProp( newObj,"next",
                function () {
                  try {
                    __LINE__ = 774;
                    var result = ret.next();
                    
                    __LINE__ = 775;
                    if ( result === undefined ){
                      
                      __LINE__ = 776;
                      throwStopIteration();
                    };
                    __LINE__ = 778;
                    return result;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                });
              } else {
                __LINE__ = 781;
                return {};
              };
              
              __LINE__ = 783;
              if ( !( "__nothrowNext__" in ret ) ){
                
                __LINE__ = 784;
                createUnenumProp( newObj,"__nothrowNext__",ret.next.bind( ret ) );
              };
              
              __LINE__ = 786;
              for ( var prop in ret ){
                
                __LINE__ = 787;
                if ( prop !== "next" && prop !== "__nothrowNext__" ){
                  
                  __LINE__ = 788;
                  newObj[prop] = ret[prop];
                };
              };
              
              __LINE__ = 791;
              if ( !( "toString" in ret ) ){
                
                __LINE__ = 792;
                createUnenumProp( newObj,"toString",
                function () {
                  try {
                    __LINE__ = 792;
                    return "[object Iterator]";
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                });
              };
              __LINE__ = 794;
              return newObj;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          __LINE__ = 765;
          _mochaLocalExport.getIterator = getIterator;
          
          function hasIterator( obj ) {
            try {
              __LINE__ = 798;
              return __ref_iterator__ in obj;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          __LINE__ = 797;
          _mochaLocalExport.hasIterator = hasIterator;
          
          __LINE__ = 801;
          var rstopIteration = /StopIteration/;
          
          function isStopIteration( obj ) {
            try {
              __LINE__ = 803;
              return obj === StopIteration || rstopIteration.test( obj );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          __LINE__ = 802;
          _mochaLocalExport.isStopIteration = isStopIteration;
          
          __LINE__ = 806;
          var privateRecord,
              createPrivateRecord,
              getPrivateRecord;
          
          __LINE__ = 809;
          if ( "WeakMap" in window ){
            
            __LINE__ = 810;
            privateRecord = new WeakMap();
            
            __LINE__ = 811;
            createPrivateRecord = function ( self,privateHolder ) {
              try {
                __LINE__ = 812;
                var holder = new privateHolder;
                
                __LINE__ = 813;
                createUnenumProp( holder.constructor,"__is_private__",1 );
                
                __LINE__ = 814;
                privateRecord.set( self,holder );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
            
            __LINE__ = 816;
            getPrivateRecord = function ( self ) {
              try {
                __LINE__ = 817;
                if ( privateRecord.has( self ) ){
                  __LINE__ = 818;
                  return privateRecord.get( self );
                } else if ( self.constructor === "__is_private__" ){
                  __LINE__ = 820;
                  return self;
                };
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          } else {
            
            __LINE__ = 824;
            createPrivateRecord = function ( self,privateHolder ) {
              try {
                if ( !self.__typeid__ ){
                  
                  __LINE__ = 826;
                  var holder = new privateHolder;
                  
                  __LINE__ = 827;
                  createUnenumProp( holder.constructor,"__is_private__",1 );
                  
                  __LINE__ = 828;
                  createUnenumProp( self,"__private__",holder );
                };
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
            
            __LINE__ = 831;
            getPrivateRecord = function ( self ) {
              try {
                if ( self.__private__ ){
                  __LINE__ = 833;
                  return self.__private__;
                } else if ( self.constructor === "__is_private__" ){
                  __LINE__ = 835;
                  return self;
                };
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          };
          
          __LINE__ = 840;
          _mochaLocalExport.getPrivateRecord = getPrivateRecord;
          
          function initializeClass( instance,classObject,privateHolder,constructor,args,name,line ) {
            try {
              __LINE__ = 843;
              if ( !instance || !( instance instanceof classObject ) ){
                
                __LINE__ = 844;
                throwException( "class "+name+" must be called by new. line : "+line );
              };
              
              __LINE__ = 846;
              createPrivateRecord( instance,privateHolder );
              
              __LINE__ = 847;
              constructor.apply( instance,args );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          __LINE__ = 842;
          _mochaLocalExport.initializeClass = initializeClass;
          
          function getSuper( obj ) {
            try {
              __LINE__ = 851;
              var type = typeof obj,
                  ret;
              
              __LINE__ = 853;
              if ( type === "function" ){
                
                __LINE__ = 854;
                ret = function (){};
                
                __LINE__ = 855;
                ret.prototype = obj.prototype;
                
                __LINE__ = 856;
                ret = new ret();
                
                __LINE__ = 857;
                if ( obj.__harmony_class__ ){
                  
                  __LINE__ = 858;
                  ret.constructor = obj.constructor;
                } else {
                  
                  __LINE__ = 860;
                  ret.constructor = obj;
                };
                __LINE__ = 862;
                return ret;
              };
              __LINE__ = 864;
              return ret;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          __LINE__ = 850;
          _mochaLocalExport.getSuper = getSuper;
          
          function traitMixin( dest,source,with_,without ) {
            try {
              __LINE__ = 869;
              if ( !dest._mochaTraitMark || !source._mochaTraitMark ){
                
                __LINE__ = 870;
                Runtime.throwException( "mixin only used for trait." );
              } else {
                
                __LINE__ = 872;
                var destTraitPrivate = dest._mochaTraitPrivate,
                    sourceTraitPrivate = source._mochaTraitPrivate,
                    destTraitPublic = dest._mochaTraitPublic,
                    sourceTraitPublic = source._mochaTraitPublic,
                    sourceRequires = source._mochaRequires,
                    destRequires = dest._mochaRequires,
                    tmp;
                
                __LINE__ = 879;
                for ( var i in sourceTraitPrivate ){
                  if ( !without[i] ){
                    
                    __LINE__ = 881;
                    tmp = ( !with_[i] )?i : with_[i];
                    
                    __LINE__ = 882;
                    destTraitPrivate[tmp] = sourceTraitPrivate[i];
                  };
                };
                
                __LINE__ = 885;
                for ( i in sourceTraitPublic ){
                  if ( !without[i] ){
                    
                    __LINE__ = 887;
                    tmp = ( !with_[i] )?i : with_[i];
                    
                    __LINE__ = 888;
                    destTraitPublic[tmp] = sourceTraitPublic[i];
                  };
                };
                
                __LINE__ = 891;
                for ( i in sourceRequires ){
                  
                  __LINE__ = 892;
                  destRequires[i] = sourceRequires[i];
                };
              };
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          __LINE__ = 868;
          _mochaLocalExport.traitMixin = traitMixin;
          
          function classMixin( _mochaLocalTmp7,_mochaLocalTmp8,_mochaLocalTmp9,with_,without ) {
            try {
              __LINE__ = 897;
              var constructorProto = _mochaLocalTmp7.prototype,
                  privateProto = _mochaLocalTmp8.prototype,
                  mark = _mochaLocalTmp9._mochaTraitMark,
                  traitPublic = _mochaLocalTmp9._mochaTraitPublic,
                  traitPrivate = _mochaLocalTmp9._mochaTraitPrivate;
              
              __LINE__ = 901;
              if ( !mark ){
                
                __LINE__ = 902;
                Runtime.throwException( "mixin only used for trait." );
              } else {
                
                __LINE__ = 904;
                var tmp;
                
                __LINE__ = 905;
                for ( var i in traitPublic ){
                  if ( !without[i] ){
                    
                    __LINE__ = 907;
                    tmp = ( !with_[i] )?i : with_[i];
                    
                    __LINE__ = 908;
                    constructorProto[tmp] = traitPublic[i];
                  };
                };
                
                __LINE__ = 911;
                for ( i in traitPrivate ){
                  if ( !without[i] ){
                    
                    __LINE__ = 913;
                    tmp = ( !with_[i] )?i : with_[i];
                    
                    __LINE__ = 914;
                    privateProto[tmp] = traitPrivate[i];
                  };
                };
              };
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          __LINE__ = 897;
          _mochaLocalExport.classMixin = classMixin;
          
          function checkRequirements( _mochaLocalTmp10,_mochaLocalTmp11,traits,file,line ) {
            try {
              __LINE__ = 920;
              var proto1 = _mochaLocalTmp10.prototype,
                  proto2 = _mochaLocalTmp11.prototype;
              
              __LINE__ = 921;
              for ( var i = 0,len = traits.length;i<len;i ++  ){
                
                __LINE__ = 922;
                var _mochaLocalTmp12 = traits[i],
                    _mochaRequires = _mochaLocalTmp12._mochaRequires;
                
                __LINE__ = 923;
                for ( var prop in _mochaRequires ){
                  
                  __LINE__ = 924;
                  if ( !( prop in proto1 ) && !( prop in proto2 ) ){
                    
                    __LINE__ = 925;
                    Runtime.throwException( "Class dose not meet the traits requirement. traits require implementation of property "+prop+"\nin file "+file+" at line "+line );
                  };
                };
              };
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          __LINE__ = 920;
          _mochaLocalExport.checkRequirements = checkRequirements;
          
          __LINE__ = 932;
          ( function () {
            try {
              __LINE__ = 933;
              var assert = _mochaLocalExport.assert = ( console && console.assert )?function ( expect,exp,str,line,filename ) {
                    try {
                      console.assert( expect === exp,"assertion failed : "+str+"\nexpect "+expect+" but got "+exp+"\nin file "+filename+" at : "+line )
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  } : function ( expect,exp,str,line,filename ) {
                    try {
                      __LINE__ = 936;
                      if ( expect !== exp ){
                        
                        __LINE__ = 937;
                        Runtime.throwException( "assertion failed : "+str+"\nexpect "+expect+" but got "+exp+"\nin file "+filename+" at : "+line );
                      };
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  };
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }).call( this );
          __LINE__ = 603;
          return _mochaLocalExport;
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      }();
  
  __LINE__ = 944;
  !( "StopIteration" in window ) && ( window.StopIteration =  {
    toString : function () {
      try {
        __LINE__ = 945;
        return "[object StopIteration]";
      } catch( e ){
        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
      }
    }
  });
  
  function Tuple(  ) {
    try {
      __LINE__ = 949;
      var args = Runtime.toArray( arguments,1 ),
          ret = {};
      
      __LINE__ = 951;
      ret.length = 0;
      
      __LINE__ = 952;
      [].push.apply( ret,args );
      
      __LINE__ = 953;
      Runtime.createTuple( ret,arguments.length );
      __LINE__ = 954;
      return ret;
    } catch( e ){
      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  }
  function Record( member ) {
    try {
      __LINE__ = 956;
      return Runtime.createRecord( member );
    } catch( e ){
      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  }
  __LINE__ = 0;
  function () {
    try {
      var __FILE__ = "/var/samba/mocha/src/test/js/262/do_while_test.js",
          __LINE__ = 0;
      __LINE__ = 2;
      _mochaGlobalExport['./do_while_test.js'] = {};
      
      __LINE__ = 3;
      var _mochaGlobalAlias = _mochaGlobalExport['./do_while_test.js'],
          testvalue = 9,
          table = [],
          ret = [];
      
      __LINE__ = 4;
      do {
        ret.push( table[testvalue] )
      }while ( testvalue --  );
      
      __LINE__ = 8;
      Runtime.assert( true,ret[0] === 'j',"ret[0] === 'j'",8,'./do_while_test.js' );
      
      __LINE__ = 9;
      Runtime.assert( true,ret[1] === 'i',"ret[1] === 'i'",9,'./do_while_test.js' );
      
      __LINE__ = 10;
      Runtime.assert( true,ret[2] === 'h',"ret[2] === 'h'",10,'./do_while_test.js' );
      
      __LINE__ = 11;
      Runtime.assert( true,ret[3] === 'g',"ret[3] === 'g'",11,'./do_while_test.js' );
      
      __LINE__ = 12;
      Runtime.assert( true,ret[4] === 'f',"ret[4] === 'f'",12,'./do_while_test.js' );
      
      __LINE__ = 13;
      Runtime.assert( true,ret[5] === 'e',"ret[5] === 'e'",13,'./do_while_test.js' );
      
      __LINE__ = 14;
      Runtime.assert( true,ret[6] === 'd',"ret[6] === 'd'",14,'./do_while_test.js' );
      
      __LINE__ = 15;
      Runtime.assert( true,ret[7] === 'c',"ret[7] === 'c'",15,'./do_while_test.js' );
      
      __LINE__ = 16;
      Runtime.assert( true,ret[8] === 'b',"ret[8] === 'b'",16,'./do_while_test.js' );
      
      __LINE__ = 17;
      Runtime.assert( true,ret[9] === 'a',"ret[9] === 'a'",17,'./do_while_test.js' );
      
      __LINE__ = 19;
      testvalue = 9;
      
      __LINE__ = 20;
      ret = [];
      
      __LINE__ = 21;
      do {
        ret.push( table[testvalue] )
      }while ( testvalue --  );
      
      __LINE__ = 24;
      Runtime.assert( true,ret[0] === 'j',"ret[0] === 'j'",24,'./do_while_test.js' );
      
      __LINE__ = 25;
      Runtime.assert( true,ret[1] === 'i',"ret[1] === 'i'",25,'./do_while_test.js' );
      
      __LINE__ = 26;
      Runtime.assert( true,ret[2] === 'h',"ret[2] === 'h'",26,'./do_while_test.js' );
      
      __LINE__ = 27;
      Runtime.assert( true,ret[3] === 'g',"ret[3] === 'g'",27,'./do_while_test.js' );
      
      __LINE__ = 28;
      Runtime.assert( true,ret[4] === 'f',"ret[4] === 'f'",28,'./do_while_test.js' );
      
      __LINE__ = 29;
      Runtime.assert( true,ret[5] === 'e',"ret[5] === 'e'",29,'./do_while_test.js' );
      
      __LINE__ = 30;
      Runtime.assert( true,ret[6] === 'd',"ret[6] === 'd'",30,'./do_while_test.js' );
      
      __LINE__ = 31;
      Runtime.assert( true,ret[7] === 'c',"ret[7] === 'c'",31,'./do_while_test.js' );
      
      __LINE__ = 32;
      Runtime.assert( true,ret[8] === 'b',"ret[8] === 'b'",32,'./do_while_test.js' );
      
      __LINE__ = 33;
      Runtime.assert( true,ret[9] === 'a',"ret[9] === 'a'",33,'./do_while_test.js' );
    } catch( e ){
      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  }();
}();
