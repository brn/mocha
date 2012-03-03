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
      var __FILE__ = "/var/samba/mocha/src/test/js/harmony/yield_test.js",
          __LINE__ = 0;
      __LINE__ = 2;
      _mochaGlobalExport['./yield_test.js'] = {};
      
      __LINE__ = 3;
      var _mochaGlobalAlias = _mochaGlobalExport['./yield_test.js'],
          tests =  {
            case1 : function () {
              try {
                function yieldTest2(  ) {
                  try {
                    __LINE__ = 3;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 3;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 3;
                    var _yieldState = 0;
                    
                    __LINE__ = 4;
                    var i = 0;
                    
                    __LINE__ = 3;
                    var _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 3;
                            if ( !_isYieldSend ){
                              
                              __LINE__ = 3;
                              _mochaIsNewBorn = false;
                            } else if ( _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined ){
                              
                              __LINE__ = 3;
                              Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 3;
                            while ( 1 ){
                              __LINE__ = 3;
                              switch ( _yieldState ) {
                                case 0 :
                                  
                                  __LINE__ = 4;
                                  if ( !( i<10 ) ){
                                    
                                    __LINE__ = 4;
                                    _yieldState = -1;
                                    __LINE__ = 4;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 0;
                                  _yieldState = -1;
                                  __LINE__ = 5;
                                  return i;
                                  
                                  __LINE__ = 4;
                                  i ++ ;
                                  
                                  __LINE__ = 4;
                                  if ( i<10 ){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 1;
                                    __LINE__ = 4;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 3;
                                  if ( _isYieldSafe ){
                                    __LINE__ = 3;
                                    return undefined;
                                  } else {
                                    __LINE__ = 3;
                                    Runtime.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 3;
                    return Runtime.createGenerator( _mochaGenerator,
                    function (  ) {
                      try {
                        __LINE__ = 3;
                        _yieldState = -1;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
                __LINE__ = 9;
                var generator = yieldTest2();
                
                __LINE__ = 11;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",11,'./yield_test.js' );
                
                __LINE__ = 12;
                Runtime.assert( true,generator.next() === 1,"generator.next() === 1",12,'./yield_test.js' );
                
                __LINE__ = 13;
                Runtime.assert( true,generator.next() === 2,"generator.next() === 2",13,'./yield_test.js' );
                
                __LINE__ = 14;
                Runtime.assert( true,generator.next() === 3,"generator.next() === 3",14,'./yield_test.js' );
                
                __LINE__ = 15;
                Runtime.assert( true,generator.next() === 4,"generator.next() === 4",15,'./yield_test.js' );
                
                __LINE__ = 16;
                Runtime.assert( true,generator.next() === 5,"generator.next() === 5",16,'./yield_test.js' );
                
                __LINE__ = 17;
                Runtime.assert( true,generator.next() === 6,"generator.next() === 6",17,'./yield_test.js' );
                
                __LINE__ = 18;
                Runtime.assert( true,generator.next() === 7,"generator.next() === 7",18,'./yield_test.js' );
                
                __LINE__ = 19;
                Runtime.assert( true,generator.next() === 8,"generator.next() === 8",19,'./yield_test.js' );
                
                __LINE__ = 20;
                Runtime.assert( true,generator.next() === 9,"generator.next() === 9",20,'./yield_test.js' );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case2 : function () {
              try {
                function yieldTest3(  ) {
                  try {
                    __LINE__ = 24;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 24;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 24;
                    var _yieldState = 0;
                    
                    __LINE__ = 25;
                    var i = 0;
                    
                    __LINE__ = 24;
                    var _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 24;
                            if ( !_isYieldSend ){
                              
                              __LINE__ = 24;
                              _mochaIsNewBorn = false;
                            } else if ( _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined ){
                              
                              __LINE__ = 24;
                              Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 24;
                            while ( 1 ){
                              __LINE__ = 24;
                              switch ( _yieldState ) {
                                case 0 :
                                  
                                  __LINE__ = 25;
                                  if ( !( i<10 ) ){
                                    
                                    __LINE__ = 25;
                                    _yieldState = -1;
                                    __LINE__ = 25;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 26;
                                  if ( i%2 === 0 ){
                                    
                                    __LINE__ = 26;
                                    _yieldState = 2;
                                    __LINE__ = 26;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 26;
                                    _yieldState = 3;
                                    __LINE__ = 26;
                                    break;
                                  };
                                case 2 :
                                  
                                  __LINE__ = 27;
                                  _yieldState = 3;
                                  __LINE__ = 27;
                                  return i;
                                case 3 :
                                  
                                  __LINE__ = 26;
                                  _yieldState = 4;
                                  __LINE__ = 26;
                                  break;
                                case 4 :
                                  
                                  __LINE__ = 25;
                                  i ++ ;
                                  
                                  __LINE__ = 25;
                                  if ( i<10 ){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 1;
                                    __LINE__ = 25;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 24;
                                  if ( _isYieldSafe ){
                                    __LINE__ = 24;
                                    return undefined;
                                  } else {
                                    __LINE__ = 24;
                                    Runtime.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 24;
                    return Runtime.createGenerator( _mochaGenerator,
                    function (  ) {
                      try {
                        __LINE__ = 24;
                        _yieldState = -1;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
                __LINE__ = 31;
                generator = yieldTest3();
                
                __LINE__ = 32;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",32,'./yield_test.js' );
                
                __LINE__ = 33;
                Runtime.assert( true,generator.next() === 2,"generator.next() === 2",33,'./yield_test.js' );
                
                __LINE__ = 34;
                Runtime.assert( true,generator.next() === 4,"generator.next() === 4",34,'./yield_test.js' );
                
                __LINE__ = 35;
                Runtime.assert( true,generator.next() === 6,"generator.next() === 6",35,'./yield_test.js' );
                
                __LINE__ = 36;
                Runtime.assert( true,generator.next() === 8,"generator.next() === 8",36,'./yield_test.js' );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case3 : function () {
              try {
                function yieldTest4(  ) {
                  try {
                    __LINE__ = 39;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 39;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 39;
                    var _yieldState = 0;
                    
                    __LINE__ = 40;
                    var i = 0;
                    
                    __LINE__ = 41;
                    var j = 0;
                    
                    __LINE__ = 39;
                    var _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 39;
                            if ( !_isYieldSend ){
                              
                              __LINE__ = 39;
                              _mochaIsNewBorn = false;
                            } else if ( _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined ){
                              
                              __LINE__ = 39;
                              Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 39;
                            while ( 1 ){
                              __LINE__ = 39;
                              switch ( _yieldState ) {
                                case 0 :
                                  
                                  __LINE__ = 40;
                                  if ( !( i<10 ) ){
                                    
                                    __LINE__ = 40;
                                    _yieldState = -1;
                                    __LINE__ = 40;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 41;
                                  if ( !( j<10 ) ){
                                    
                                    __LINE__ = 41;
                                    _yieldState = 6;
                                    __LINE__ = 41;
                                    break;
                                  };
                                case 2 :
                                  
                                  __LINE__ = 42;
                                  if ( j%2 === 0 ){
                                    
                                    __LINE__ = 42;
                                    _yieldState = 3;
                                    __LINE__ = 42;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 42;
                                    _yieldState = 4;
                                    __LINE__ = 42;
                                    break;
                                  };
                                case 3 :
                                  
                                  __LINE__ = 43;
                                  _yieldState = 4;
                                  __LINE__ = 43;
                                  return j;
                                case 4 :
                                  
                                  __LINE__ = 42;
                                  _yieldState = 5;
                                  __LINE__ = 42;
                                  break;
                                case 5 :
                                  
                                  __LINE__ = 41;
                                  j ++ ;
                                  
                                  __LINE__ = 41;
                                  if ( j<10 ){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 2;
                                    __LINE__ = 41;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = 6;
                                  };
                                case 6 :
                                  
                                  __LINE__ = 40;
                                  i ++ ;
                                  
                                  __LINE__ = 40;
                                  if ( i<10 ){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 1;
                                    __LINE__ = 40;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 39;
                                  if ( _isYieldSafe ){
                                    __LINE__ = 39;
                                    return undefined;
                                  } else {
                                    __LINE__ = 39;
                                    Runtime.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 39;
                    return Runtime.createGenerator( _mochaGenerator,
                    function (  ) {
                      try {
                        __LINE__ = 39;
                        _yieldState = -1;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
                __LINE__ = 48;
                generator = yieldTest4();
                
                __LINE__ = 49;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",49,'./yield_test.js' );
                
                __LINE__ = 50;
                Runtime.assert( true,generator.next() === 2,"generator.next() === 2",50,'./yield_test.js' );
                
                __LINE__ = 51;
                Runtime.assert( true,generator.next() === 4,"generator.next() === 4",51,'./yield_test.js' );
                
                __LINE__ = 52;
                Runtime.assert( true,generator.next() === 6,"generator.next() === 6",52,'./yield_test.js' );
                
                __LINE__ = 53;
                Runtime.assert( true,generator.next() === 8,"generator.next() === 8",53,'./yield_test.js' );
                
                __LINE__ = 55;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",55,'./yield_test.js' );
                
                __LINE__ = 56;
                Runtime.assert( true,generator.next() === 2,"generator.next() === 2",56,'./yield_test.js' );
                
                __LINE__ = 57;
                Runtime.assert( true,generator.next() === 4,"generator.next() === 4",57,'./yield_test.js' );
                
                __LINE__ = 58;
                Runtime.assert( true,generator.next() === 6,"generator.next() === 6",58,'./yield_test.js' );
                
                __LINE__ = 59;
                Runtime.assert( true,generator.next() === 8,"generator.next() === 8",59,'./yield_test.js' );
                
                __LINE__ = 61;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",61,'./yield_test.js' );
                
                __LINE__ = 62;
                Runtime.assert( true,generator.next() === 2,"generator.next() === 2",62,'./yield_test.js' );
                
                __LINE__ = 63;
                Runtime.assert( true,generator.next() === 4,"generator.next() === 4",63,'./yield_test.js' );
                
                __LINE__ = 64;
                Runtime.assert( true,generator.next() === 6,"generator.next() === 6",64,'./yield_test.js' );
                
                __LINE__ = 65;
                Runtime.assert( true,generator.next() === 8,"generator.next() === 8",65,'./yield_test.js' );
                
                __LINE__ = 67;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",67,'./yield_test.js' );
                
                __LINE__ = 68;
                Runtime.assert( true,generator.next() === 2,"generator.next() === 2",68,'./yield_test.js' );
                
                __LINE__ = 69;
                Runtime.assert( true,generator.next() === 4,"generator.next() === 4",69,'./yield_test.js' );
                
                __LINE__ = 70;
                Runtime.assert( true,generator.next() === 6,"generator.next() === 6",70,'./yield_test.js' );
                
                __LINE__ = 71;
                Runtime.assert( true,generator.next() === 8,"generator.next() === 8",71,'./yield_test.js' );
                
                __LINE__ = 73;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",73,'./yield_test.js' );
                
                __LINE__ = 74;
                Runtime.assert( true,generator.next() === 2,"generator.next() === 2",74,'./yield_test.js' );
                
                __LINE__ = 75;
                Runtime.assert( true,generator.next() === 4,"generator.next() === 4",75,'./yield_test.js' );
                
                __LINE__ = 76;
                Runtime.assert( true,generator.next() === 6,"generator.next() === 6",76,'./yield_test.js' );
                
                __LINE__ = 77;
                Runtime.assert( true,generator.next() === 8,"generator.next() === 8",77,'./yield_test.js' );
                
                __LINE__ = 79;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",79,'./yield_test.js' );
                
                __LINE__ = 80;
                Runtime.assert( true,generator.next() === 2,"generator.next() === 2",80,'./yield_test.js' );
                
                __LINE__ = 81;
                Runtime.assert( true,generator.next() === 4,"generator.next() === 4",81,'./yield_test.js' );
                
                __LINE__ = 82;
                Runtime.assert( true,generator.next() === 6,"generator.next() === 6",82,'./yield_test.js' );
                
                __LINE__ = 83;
                Runtime.assert( true,generator.next() === 8,"generator.next() === 8",83,'./yield_test.js' );
                
                __LINE__ = 85;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",85,'./yield_test.js' );
                
                __LINE__ = 86;
                Runtime.assert( true,generator.next() === 2,"generator.next() === 2",86,'./yield_test.js' );
                
                __LINE__ = 87;
                Runtime.assert( true,generator.next() === 4,"generator.next() === 4",87,'./yield_test.js' );
                
                __LINE__ = 88;
                Runtime.assert( true,generator.next() === 6,"generator.next() === 6",88,'./yield_test.js' );
                
                __LINE__ = 89;
                Runtime.assert( true,generator.next() === 8,"generator.next() === 8",89,'./yield_test.js' );
                
                __LINE__ = 91;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",91,'./yield_test.js' );
                
                __LINE__ = 92;
                Runtime.assert( true,generator.next() === 2,"generator.next() === 2",92,'./yield_test.js' );
                
                __LINE__ = 93;
                Runtime.assert( true,generator.next() === 4,"generator.next() === 4",93,'./yield_test.js' );
                
                __LINE__ = 94;
                Runtime.assert( true,generator.next() === 6,"generator.next() === 6",94,'./yield_test.js' );
                
                __LINE__ = 95;
                Runtime.assert( true,generator.next() === 8,"generator.next() === 8",95,'./yield_test.js' );
                
                __LINE__ = 97;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",97,'./yield_test.js' );
                
                __LINE__ = 98;
                Runtime.assert( true,generator.next() === 2,"generator.next() === 2",98,'./yield_test.js' );
                
                __LINE__ = 99;
                Runtime.assert( true,generator.next() === 4,"generator.next() === 4",99,'./yield_test.js' );
                
                __LINE__ = 100;
                Runtime.assert( true,generator.next() === 6,"generator.next() === 6",100,'./yield_test.js' );
                
                __LINE__ = 101;
                Runtime.assert( true,generator.next() === 8,"generator.next() === 8",101,'./yield_test.js' );
                
                __LINE__ = 103;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",103,'./yield_test.js' );
                
                __LINE__ = 104;
                Runtime.assert( true,generator.next() === 2,"generator.next() === 2",104,'./yield_test.js' );
                
                __LINE__ = 105;
                Runtime.assert( true,generator.next() === 4,"generator.next() === 4",105,'./yield_test.js' );
                
                __LINE__ = 106;
                Runtime.assert( true,generator.next() === 6,"generator.next() === 6",106,'./yield_test.js' );
                
                __LINE__ = 107;
                Runtime.assert( true,generator.next() === 8,"generator.next() === 8",107,'./yield_test.js' );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case4 : function () {
              try {
                function yieldTest5(  ) {
                  try {
                    __LINE__ = 110;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 110;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 110;
                    var _yieldState = 0;
                    
                    __LINE__ = 111;
                    var i;
                    
                    __LINE__ = 110;
                    var _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 110;
                            if ( !_isYieldSend ){
                              
                              __LINE__ = 110;
                              _mochaIsNewBorn = false;
                            } else if ( _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined ){
                              
                              __LINE__ = 110;
                              Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 110;
                            while ( 1 ){
                              __LINE__ = 110;
                              switch ( _yieldState ) {
                                case 0 :
                                  
                                  __LINE__ = 111;
                                  i = 0;
                                  
                                  __LINE__ = 112;
                                  if ( !(  ++ i<10 ) ){
                                    
                                    __LINE__ = 112;
                                    _yieldState = -1;
                                    __LINE__ = 112;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 0;
                                  _yieldState = -1;
                                  __LINE__ = 113;
                                  return i;
                                  
                                  __LINE__ = 112;
                                  if (  ++ i<10 ){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 1;
                                    __LINE__ = 112;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 110;
                                  if ( _isYieldSafe ){
                                    __LINE__ = 110;
                                    return undefined;
                                  } else {
                                    __LINE__ = 110;
                                    Runtime.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 110;
                    return Runtime.createGenerator( _mochaGenerator,
                    function (  ) {
                      try {
                        __LINE__ = 110;
                        _yieldState = -1;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
                __LINE__ = 117;
                generator = yieldTest5();
                
                __LINE__ = 118;
                Runtime.assert( true,generator.next() === 1,"generator.next() === 1",118,'./yield_test.js' );
                
                __LINE__ = 119;
                Runtime.assert( true,generator.next() === 2,"generator.next() === 2",119,'./yield_test.js' );
                
                __LINE__ = 120;
                Runtime.assert( true,generator.next() === 3,"generator.next() === 3",120,'./yield_test.js' );
                
                __LINE__ = 121;
                Runtime.assert( true,generator.next() === 4,"generator.next() === 4",121,'./yield_test.js' );
                
                __LINE__ = 122;
                Runtime.assert( true,generator.next() === 5,"generator.next() === 5",122,'./yield_test.js' );
                
                __LINE__ = 123;
                Runtime.assert( true,generator.next() === 6,"generator.next() === 6",123,'./yield_test.js' );
                
                __LINE__ = 124;
                Runtime.assert( true,generator.next() === 7,"generator.next() === 7",124,'./yield_test.js' );
                
                __LINE__ = 125;
                Runtime.assert( true,generator.next() === 8,"generator.next() === 8",125,'./yield_test.js' );
                
                __LINE__ = 126;
                Runtime.assert( true,generator.next() === 9,"generator.next() === 9",126,'./yield_test.js' );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case5 : function () {
              try {
                function yieldTest6(  ) {
                  try {
                    __LINE__ = 129;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 129;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 129;
                    var _yieldState = 0;
                    
                    __LINE__ = 130;
                    var i;
                    
                    __LINE__ = 129;
                    var _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 129;
                            if ( !_isYieldSend ){
                              
                              __LINE__ = 129;
                              _mochaIsNewBorn = false;
                            } else if ( _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined ){
                              
                              __LINE__ = 129;
                              Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 129;
                            while ( 1 ){
                              __LINE__ = 129;
                              switch ( _yieldState ) {
                                case 0 :
                                  
                                  __LINE__ = 130;
                                  i = 0;
                                case 1 :
                                  
                                  __LINE__ = 0;
                                  _yieldState = 2;
                                  __LINE__ = 132;
                                  return i;
                                  
                                  __LINE__ = 133;
                                  if (  ++ i<10 ){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 1;
                                    __LINE__ = 133;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = 2;
                                  };
                                case 2 :
                                case -1 :
                                  
                                  __LINE__ = 129;
                                  if ( _isYieldSafe ){
                                    __LINE__ = 129;
                                    return undefined;
                                  } else {
                                    __LINE__ = 129;
                                    Runtime.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 129;
                    return Runtime.createGenerator( _mochaGenerator,
                    function (  ) {
                      try {
                        __LINE__ = 129;
                        _yieldState = -1;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
                __LINE__ = 136;
                generator = yieldTest6();
                
                __LINE__ = 137;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",137,'./yield_test.js' );
                
                __LINE__ = 138;
                Runtime.assert( true,generator.next() === 1,"generator.next() === 1",138,'./yield_test.js' );
                
                __LINE__ = 139;
                Runtime.assert( true,generator.next() === 2,"generator.next() === 2",139,'./yield_test.js' );
                
                __LINE__ = 140;
                Runtime.assert( true,generator.next() === 3,"generator.next() === 3",140,'./yield_test.js' );
                
                __LINE__ = 141;
                Runtime.assert( true,generator.next() === 4,"generator.next() === 4",141,'./yield_test.js' );
                
                __LINE__ = 142;
                Runtime.assert( true,generator.next() === 5,"generator.next() === 5",142,'./yield_test.js' );
                
                __LINE__ = 143;
                Runtime.assert( true,generator.next() === 6,"generator.next() === 6",143,'./yield_test.js' );
                
                __LINE__ = 144;
                Runtime.assert( true,generator.next() === 7,"generator.next() === 7",144,'./yield_test.js' );
                
                __LINE__ = 145;
                Runtime.assert( true,generator.next() === 8,"generator.next() === 8",145,'./yield_test.js' );
                
                __LINE__ = 146;
                Runtime.assert( true,generator.next() === 9,"generator.next() === 9",146,'./yield_test.js' );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case6 : function () {
              try {
                function yieldTest7(  ) {
                  try {
                    __LINE__ = 149;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 149;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 149;
                    var _yieldState = 0;
                    
                    __LINE__ = 151;
                    var m;
                    
                    __LINE__ = 150;
                    var i = 0;
                    
                    __LINE__ = 149;
                    var _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 149;
                            if ( !_isYieldSend ){
                              
                              __LINE__ = 149;
                              _mochaIsNewBorn = false;
                            } else if ( _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined ){
                              
                              __LINE__ = 149;
                              Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 149;
                            while ( 1 ){
                              __LINE__ = 149;
                              switch ( _yieldState ) {
                                case 0 :
                                  
                                  __LINE__ = 150;
                                  if ( !( i<10 ) ){
                                    
                                    __LINE__ = 150;
                                    _yieldState = -1;
                                    __LINE__ = 150;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 152;
                                  _yieldState = 2;
                                  __LINE__ = 151;
                                  return i;
                                  
                                  __LINE__ = 151;
                                  _yieldResult = _isYieldSend && arguments.length>2?Runtime.toArray( arguments,2 )[0] : _isYieldSend?i : undefined;
                                  
                                  __LINE__ = 151;
                                  m = _yieldResult;
                                  
                                  __LINE__ = 152;
                                  if ( m === true ){
                                    
                                    __LINE__ = 152;
                                    _yieldState = 2;
                                    __LINE__ = 152;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 152;
                                    _yieldState = 4;
                                    __LINE__ = 152;
                                    break;
                                  };
                                case 2 :
                                  
                                  __LINE__ = 153;
                                  _yieldState = 3;
                                  __LINE__ = 153;
                                  return i+1;
                                case 3 :
                                  
                                  __LINE__ = 152;
                                  _yieldState = 8;
                                  __LINE__ = 152;
                                  break;
                                case 4 :
                                  
                                  __LINE__ = 154;
                                  if ( m === false ){
                                    
                                    __LINE__ = 154;
                                    _yieldState = 5;
                                    __LINE__ = 154;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 154;
                                    _yieldState = 7;
                                    __LINE__ = 154;
                                    break;
                                  };
                                case 5 :
                                  
                                  __LINE__ = 155;
                                  _yieldState = 6;
                                  __LINE__ = 155;
                                  return i-1;
                                case 6 :
                                  
                                  __LINE__ = 154;
                                  _yieldState = 8;
                                  __LINE__ = 154;
                                  break;
                                case 7 :
                                  
                                  __LINE__ = 157;
                                  _yieldState = 8;
                                  __LINE__ = 157;
                                  return i;
                                case 8 :
                                  
                                  __LINE__ = 150;
                                  i ++ ;
                                  
                                  __LINE__ = 150;
                                  if ( i<10 ){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 1;
                                    __LINE__ = 150;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 149;
                                  if ( _isYieldSafe ){
                                    __LINE__ = 149;
                                    return undefined;
                                  } else {
                                    __LINE__ = 149;
                                    Runtime.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 149;
                    return Runtime.createGenerator( _mochaGenerator,
                    function (  ) {
                      try {
                        __LINE__ = 149;
                        _yieldState = -1;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
                __LINE__ = 162;
                generator = yieldTest7();
                
                __LINE__ = 163;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",163,'./yield_test.js' );
                
                __LINE__ = 164;
                Runtime.assert( true,generator.send( true ) === 1,"generator.send( true ) === 1",164,'./yield_test.js' );
                
                __LINE__ = 165;
                Runtime.assert( true,generator.send( false ) === 1,"generator.send( false ) === 1",165,'./yield_test.js' );
                
                __LINE__ = 166;
                Runtime.assert( true,generator.send( true ) === 2,"generator.send( true ) === 2",166,'./yield_test.js' );
                
                __LINE__ = 167;
                Runtime.assert( true,generator.send( false ) === 2,"generator.send( false ) === 2",167,'./yield_test.js' );
                
                __LINE__ = 168;
                Runtime.assert( true,generator.send( true ) === 3,"generator.send( true ) === 3",168,'./yield_test.js' );
                
                __LINE__ = 169;
                Runtime.assert( true,generator.send( true ) === 3,"generator.send( true ) === 3",169,'./yield_test.js' );
                
                __LINE__ = 170;
                Runtime.assert( true,generator.send( true ) === 4,"generator.send( true ) === 4",170,'./yield_test.js' );
                
                __LINE__ = 171;
                Runtime.assert( true,generator.send( false ) === 4,"generator.send( false ) === 4",171,'./yield_test.js' );
                
                __LINE__ = 172;
                Runtime.assert( true,generator.send( true ) === 5,"generator.send( true ) === 5",172,'./yield_test.js' );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case7 : function () {
              try {
                function yieldTest8(  ) {
                  try {
                    __LINE__ = 175;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 175;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 175;
                    var _yieldState = 0;
                    
                    __LINE__ = 177;
                    var m;
                    
                    __LINE__ = 176;
                    var i = 0;
                    
                    __LINE__ = 178;
                    var j = 0;
                    
                    __LINE__ = 175;
                    var _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 175;
                            if ( !_isYieldSend ){
                              
                              __LINE__ = 175;
                              _mochaIsNewBorn = false;
                            } else if ( _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined ){
                              
                              __LINE__ = 175;
                              Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 175;
                            while ( 1 ){
                              __LINE__ = 175;
                              switch ( _yieldState ) {
                                case 0 :
                                  
                                  __LINE__ = 176;
                                  if ( !( i<10 ) ){
                                    
                                    __LINE__ = 176;
                                    _yieldState = -1;
                                    __LINE__ = 176;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 178;
                                  _yieldState = 2;
                                  __LINE__ = 177;
                                  return i;
                                  
                                  __LINE__ = 177;
                                  _yieldResult = _isYieldSend && arguments.length>2?Runtime.toArray( arguments,2 )[0] : _isYieldSend?i : undefined;
                                  
                                  __LINE__ = 177;
                                  m = _yieldResult;
                                  
                                  __LINE__ = 178;
                                  if ( !( j<10 ) ){
                                    
                                    __LINE__ = 178;
                                    _yieldState = 10;
                                    __LINE__ = 178;
                                    break;
                                  };
                                case 2 :
                                  
                                  __LINE__ = 179;
                                  if ( m === true ){
                                    
                                    __LINE__ = 179;
                                    _yieldState = 3;
                                    __LINE__ = 179;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 179;
                                    _yieldState = 5;
                                    __LINE__ = 179;
                                    break;
                                  };
                                case 3 :
                                  
                                  __LINE__ = 180;
                                  _yieldState = 4;
                                  __LINE__ = 180;
                                  return j*2;
                                case 4 :
                                  
                                  __LINE__ = 179;
                                  _yieldState = 9;
                                  __LINE__ = 179;
                                  break;
                                case 5 :
                                  
                                  __LINE__ = 181;
                                  if ( m === false ){
                                    
                                    __LINE__ = 181;
                                    _yieldState = 6;
                                    __LINE__ = 181;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 181;
                                    _yieldState = 8;
                                    __LINE__ = 181;
                                    break;
                                  };
                                case 6 :
                                  
                                  __LINE__ = 182;
                                  _yieldState = 7;
                                  __LINE__ = 182;
                                  return j/2;
                                case 7 :
                                  
                                  __LINE__ = 181;
                                  _yieldState = 9;
                                  __LINE__ = 181;
                                  break;
                                case 8 :
                                  
                                  __LINE__ = 184;
                                  _yieldState = 9;
                                  __LINE__ = 184;
                                  return j;
                                case 9 :
                                  
                                  __LINE__ = 178;
                                  j ++ ;
                                  
                                  __LINE__ = 178;
                                  if ( j<10 ){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 2;
                                    __LINE__ = 178;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = 10;
                                  };
                                case 10 :
                                  
                                  __LINE__ = 176;
                                  i ++ ;
                                  
                                  __LINE__ = 176;
                                  if ( i<10 ){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 1;
                                    __LINE__ = 176;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 175;
                                  if ( _isYieldSafe ){
                                    __LINE__ = 175;
                                    return undefined;
                                  } else {
                                    __LINE__ = 175;
                                    Runtime.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 175;
                    return Runtime.createGenerator( _mochaGenerator,
                    function (  ) {
                      try {
                        __LINE__ = 175;
                        _yieldState = -1;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
                __LINE__ = 191;
                generator = yieldTest8();
                
                __LINE__ = 192;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",192,'./yield_test.js' );
                
                __LINE__ = 193;
                Runtime.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",193,'./yield_test.js' );
                
                __LINE__ = 194;
                Runtime.assert( true,generator.send( false ) === 2,"generator.send( false ) === 2",194,'./yield_test.js' );
                
                __LINE__ = 195;
                Runtime.assert( true,generator.send( true ) === 4,"generator.send( true ) === 4",195,'./yield_test.js' );
                
                __LINE__ = 196;
                Runtime.assert( true,generator.send( false ) === 6,"generator.send( false ) === 6",196,'./yield_test.js' );
                
                __LINE__ = 197;
                Runtime.assert( true,generator.send( true ) === 8,"generator.send( true ) === 8",197,'./yield_test.js' );
                
                __LINE__ = 198;
                Runtime.assert( true,generator.send( true ) === 10,"generator.send( true ) === 10",198,'./yield_test.js' );
                
                __LINE__ = 199;
                Runtime.assert( true,generator.send( true ) === 12,"generator.send( true ) === 12",199,'./yield_test.js' );
                
                __LINE__ = 200;
                Runtime.assert( true,generator.send( false ) === 14,"generator.send( false ) === 14",200,'./yield_test.js' );
                
                __LINE__ = 201;
                Runtime.assert( true,generator.send( true ) === 16,"generator.send( true ) === 16",201,'./yield_test.js' );
                
                __LINE__ = 202;
                Runtime.assert( true,generator.send( true ) === 18,"generator.send( true ) === 18",202,'./yield_test.js' );
                
                __LINE__ = 203;
                Runtime.assert( true,generator.send( false ) === 1,"generator.send( false ) === 1",203,'./yield_test.js' );
                
                __LINE__ = 204;
                Runtime.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",204,'./yield_test.js' );
                
                __LINE__ = 205;
                Runtime.assert( true,generator.send( false ) === 2,"generator.send( false ) === 2",205,'./yield_test.js' );
                
                __LINE__ = 206;
                Runtime.assert( true,generator.send( true ) === 4,"generator.send( true ) === 4",206,'./yield_test.js' );
                
                __LINE__ = 207;
                Runtime.assert( true,generator.send( true ) === 6,"generator.send( true ) === 6",207,'./yield_test.js' );
                
                __LINE__ = 208;
                Runtime.assert( true,generator.send( true ) === 8,"generator.send( true ) === 8",208,'./yield_test.js' );
                
                __LINE__ = 209;
                Runtime.assert( true,generator.send( false ) === 10,"generator.send( false ) === 10",209,'./yield_test.js' );
                
                __LINE__ = 210;
                Runtime.assert( true,generator.send( true ) === 12,"generator.send( true ) === 12",210,'./yield_test.js' );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case8 : function () {
              try {
                function yieldTest9(  ) {
                  try {
                    __LINE__ = 214;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 214;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 214;
                    var _yieldState = 0;
                    
                    __LINE__ = 217;
                    var m;
                    
                    __LINE__ = 215;
                    var i = 0;
                    
                    __LINE__ = 216;
                    var j = 0;
                    
                    __LINE__ = 214;
                    var _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 214;
                            if ( !_isYieldSend ){
                              
                              __LINE__ = 214;
                              _mochaIsNewBorn = false;
                            } else if ( _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined ){
                              
                              __LINE__ = 214;
                              Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 214;
                            while ( 1 ){
                              __LINE__ = 214;
                              switch ( _yieldState ) {
                                case 0 :
                                  
                                  __LINE__ = 215;
                                  if ( !( i<10 ) ){
                                    
                                    __LINE__ = 215;
                                    _yieldState = -1;
                                    __LINE__ = 215;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 216;
                                  if ( !( j<10 ) ){
                                    
                                    __LINE__ = 216;
                                    _yieldState = 10;
                                    __LINE__ = 216;
                                    break;
                                  };
                                case 2 :
                                  
                                  __LINE__ = 218;
                                  _yieldState = 3;
                                  __LINE__ = 217;
                                  return i;
                                  
                                  __LINE__ = 217;
                                  _yieldResult = _isYieldSend && arguments.length>2?Runtime.toArray( arguments,2 )[0] : _isYieldSend?i : undefined;
                                  
                                  __LINE__ = 217;
                                  m = _yieldResult;
                                  
                                  __LINE__ = 218;
                                  if ( m === true ){
                                    
                                    __LINE__ = 218;
                                    _yieldState = 3;
                                    __LINE__ = 218;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 218;
                                    _yieldState = 5;
                                    __LINE__ = 218;
                                    break;
                                  };
                                case 3 :
                                  
                                  __LINE__ = 219;
                                  _yieldState = 4;
                                  __LINE__ = 219;
                                  return j*2;
                                case 4 :
                                  
                                  __LINE__ = 218;
                                  _yieldState = 9;
                                  __LINE__ = 218;
                                  break;
                                case 5 :
                                  
                                  __LINE__ = 220;
                                  if ( m === false ){
                                    
                                    __LINE__ = 220;
                                    _yieldState = 6;
                                    __LINE__ = 220;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 220;
                                    _yieldState = 8;
                                    __LINE__ = 220;
                                    break;
                                  };
                                case 6 :
                                  
                                  __LINE__ = 221;
                                  _yieldState = 7;
                                  __LINE__ = 221;
                                  return j/2;
                                case 7 :
                                  
                                  __LINE__ = 220;
                                  _yieldState = 9;
                                  __LINE__ = 220;
                                  break;
                                case 8 :
                                  
                                  __LINE__ = 223;
                                  _yieldState = 9;
                                  __LINE__ = 223;
                                  return j;
                                case 9 :
                                  
                                  __LINE__ = 216;
                                  j ++ ;
                                  
                                  __LINE__ = 216;
                                  if ( j<10 ){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 2;
                                    __LINE__ = 216;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = 10;
                                  };
                                case 10 :
                                  
                                  __LINE__ = 215;
                                  i ++ ;
                                  
                                  __LINE__ = 215;
                                  if ( i<10 ){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 1;
                                    __LINE__ = 215;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 214;
                                  if ( _isYieldSafe ){
                                    __LINE__ = 214;
                                    return undefined;
                                  } else {
                                    __LINE__ = 214;
                                    Runtime.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 214;
                    return Runtime.createGenerator( _mochaGenerator,
                    function (  ) {
                      try {
                        __LINE__ = 214;
                        _yieldState = -1;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
                __LINE__ = 230;
                generator = yieldTest9();
                
                __LINE__ = 231;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",231,'./yield_test.js' );
                
                __LINE__ = 232;
                Runtime.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",232,'./yield_test.js' );
                
                __LINE__ = 233;
                Runtime.assert( true,generator.send( false ) === 0,"generator.send( false ) === 0",233,'./yield_test.js' );
                
                __LINE__ = 234;
                Runtime.assert( true,generator.send( true ) === 2,"generator.send( true ) === 2",234,'./yield_test.js' );
                
                __LINE__ = 235;
                Runtime.assert( true,generator.send( false ) === 0,"generator.send( false ) === 0",235,'./yield_test.js' );
                
                __LINE__ = 236;
                Runtime.assert( true,generator.send( true ) === 4,"generator.send( true ) === 4",236,'./yield_test.js' );
                
                __LINE__ = 237;
                Runtime.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",237,'./yield_test.js' );
                
                __LINE__ = 238;
                Runtime.assert( true,generator.send( true ) === 6,"generator.send( true ) === 6",238,'./yield_test.js' );
                
                __LINE__ = 239;
                Runtime.assert( true,generator.send( false ) === 0,"generator.send( false ) === 0",239,'./yield_test.js' );
                
                __LINE__ = 240;
                Runtime.assert( true,generator.send( true ) === 8,"generator.send( true ) === 8",240,'./yield_test.js' );
                
                __LINE__ = 241;
                Runtime.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",241,'./yield_test.js' );
                
                __LINE__ = 242;
                Runtime.assert( true,generator.send( false ) === 2.5,"generator.send( false ) === 2.5",242,'./yield_test.js' );
                
                __LINE__ = 243;
                Runtime.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",243,'./yield_test.js' );
                
                __LINE__ = 244;
                Runtime.assert( true,generator.send( false ) === 3,"generator.send( false ) === 3",244,'./yield_test.js' );
                
                __LINE__ = 245;
                Runtime.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",245,'./yield_test.js' );
                
                __LINE__ = 246;
                Runtime.assert( true,generator.send( true ) === 14,"generator.send( true ) === 14",246,'./yield_test.js' );
                
                __LINE__ = 247;
                Runtime.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",247,'./yield_test.js' );
                
                __LINE__ = 248;
                Runtime.assert( true,generator.send( false ) === 4,"generator.send( false ) === 4",248,'./yield_test.js' );
                
                __LINE__ = 249;
                Runtime.assert( true,generator.send( true ) === 0,"generator.send( true ) === 0",249,'./yield_test.js' );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case9 : function () {
              try {
                function yieldTest10(  ) {
                  try {
                    __LINE__ = 253;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 253;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 253;
                    var _yieldState = 0;
                    
                    __LINE__ = 253;
                    var _mochaFinallyCache;
                    
                    __LINE__ = 253;
                    var _mochaCatchCache;
                    
                    __LINE__ = 257;
                    var m;
                    
                    __LINE__ = 254;
                    var flg;
                    
                    __LINE__ = 255;
                    var i = 0;
                    
                    __LINE__ = 253;
                    var _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 253;
                            if ( !_isYieldSend ){
                              
                              __LINE__ = 253;
                              _mochaIsNewBorn = false;
                            } else if ( _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined ){
                              
                              __LINE__ = 253;
                              Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 253;
                            while ( 1 ){
                              try {
                                __LINE__ = 253;
                                switch ( _yieldState ) {
                                  case 0 :
                                    
                                    __LINE__ = 254;
                                    flg = false;
                                    
                                    __LINE__ = 255;
                                    if ( !( i<10 ) ){
                                      
                                      __LINE__ = 255;
                                      _yieldState = -1;
                                      __LINE__ = 255;
                                      break;
                                    };
                                  case 1 :
                                    
                                    __LINE__ = 253;
                                    _yieldState = 2;
                                    
                                    __LINE__ = 256;
                                    _mochaCatchCache = function ( e ) {
                                      try {
                                        __LINE__ = 256;
                                        _yieldState = 2;
                                      } catch( e ){
                                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                                      }
                                    };
                                    
                                    __LINE__ = 256;
                                    _mochaFinallyCache = function (  ) {
                                      try {
                                        flg = true
                                      } catch( e ){
                                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                                      }
                                    };
                                    
                                    __LINE__ = 257;
                                    m = ( flg )?1 : 0;
                                    __LINE__ = 258;
                                    return m;
                                    
                                    __LINE__ = 259;
                                    ddddd();
                                    
                                    __LINE__ = 253;
                                    _mochaCatchCache = undefined;
                                    
                                    __LINE__ = 253;
                                    _mochaFinallyCache = undefined;
                                  case 2 :
                                    
                                    __LINE__ = 255;
                                    i ++ ;
                                    
                                    __LINE__ = 255;
                                    if ( i<10 ){
                                      
                                      __LINE__ = 0;
                                      _yieldState = 1;
                                      __LINE__ = 255;
                                      break;
                                    } else {
                                      
                                      __LINE__ = 0;
                                      _yieldState = -1;
                                    };
                                  case -1 :
                                    
                                    __LINE__ = 253;
                                    if ( _isYieldSafe ){
                                      __LINE__ = 253;
                                      return undefined;
                                    } else {
                                      __LINE__ = 253;
                                      Runtime.throwStopIteration();
                                    };
                                    
                                };
                              } catch( _mochaException ){
                                __LINE__ = 253;
                                if ( _mochaCatchCache ){
                                  
                                  __LINE__ = 253;
                                  var _mochaLocalTmp0 = _mochaCatchCache( _mochaException );
                                  
                                  __LINE__ = 253;
                                  if ( _mochaLocalTmp0 !== undefined ){
                                    __LINE__ = 253;
                                    return _mochaLocalTmp0;
                                  };
                                } else {
                                  __LINE__ = 253;
                                  Runtime.throwException( _mochaException );
                                };
                              } finally {
                                __LINE__ = 253;
                                if ( _mochaFinallyCache ){
                                  
                                  __LINE__ = 253;
                                  var _mochaLocalTmp1 = _mochaFinallyCache(  );
                                  
                                  __LINE__ = 253;
                                  if ( _mochaLocalTmp1 !== undefined ){
                                    __LINE__ = 253;
                                    return _mochaLocalTmp1;
                                  };
                                };
                              };
                            };
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 253;
                    return Runtime.createGenerator( _mochaGenerator,
                    function (  ) {
                      try {
                        __LINE__ = 253;
                        _yieldState = -1;
                        
                        __LINE__ = 253;
                        if ( _mochaFinallyCache ){
                          __LINE__ = 253;
                          _mochaFinallyCache(  );
                        };
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
                __LINE__ = 266;
                generator = yieldTest10();
                
                __LINE__ = 267;
                Runtime.assert( true,generator.next() === 0,"generator.next() === 0",267,'./yield_test.js' );
                
                __LINE__ = 268;
                Runtime.assert( true,generator.next() === 1,"generator.next() === 1",268,'./yield_test.js' );
                
                __LINE__ = 269;
                Runtime.assert( true,generator.next() === 1,"generator.next() === 1",269,'./yield_test.js' );
                
                __LINE__ = 270;
                Runtime.assert( true,generator.next() === 1,"generator.next() === 1",270,'./yield_test.js' );
                
                __LINE__ = 271;
                Runtime.assert( true,generator.next() === 1,"generator.next() === 1",271,'./yield_test.js' );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case10 : function () {
              try {
                function yieldTest11(  ) {
                  try {
                    __LINE__ = 274;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 274;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 274;
                    var _yieldState = 0;
                    
                    __LINE__ = 276;
                    var type;
                    
                    __LINE__ = 275;
                    var i = 0;
                    
                    __LINE__ = 274;
                    var _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 274;
                            if ( !_isYieldSend ){
                              
                              __LINE__ = 274;
                              _mochaIsNewBorn = false;
                            } else if ( _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined ){
                              
                              __LINE__ = 274;
                              Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 274;
                            while ( 1 ){
                              __LINE__ = 274;
                              switch ( _yieldState ) {
                                case 0 :
                                  
                                  __LINE__ = 275;
                                  if ( !( i<10 ) ){
                                    
                                    __LINE__ = 275;
                                    _yieldState = -1;
                                    __LINE__ = 275;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 277;
                                  _yieldState = 2;
                                  __LINE__ = 276;
                                  return ;
                                  
                                  __LINE__ = 276;
                                  _yieldResult = _isYieldSend && arguments.length>2?Runtime.toArray( arguments,2 )[0] : undefined;
                                  
                                  __LINE__ = 276;
                                  type = _yieldResult;
                                  
                                  __LINE__ = 277;
                                  switch ( type ) {
                                    case 0 :
                                      
                                      __LINE__ = 277;
                                      _yieldState = 2;
                                      __LINE__ = 278;
                                      break;
                                    case 2 :
                                      
                                      __LINE__ = 277;
                                      _yieldState = 3;
                                      __LINE__ = 280;
                                      break;
                                    case 3 :
                                      
                                      __LINE__ = 277;
                                      _yieldState = 4;
                                      __LINE__ = 282;
                                      break;
                                    default :
                                      
                                      __LINE__ = 277;
                                      _yieldState = 5;
                                      __LINE__ = 284;
                                      break;
                                      
                                  };
                                  __LINE__ = 277;
                                  break;
                                case 2 :
                                  
                                  __LINE__ = 277;
                                  _yieldState = 6;
                                  __LINE__ = 279;
                                  return 200;
                                case 3 :
                                  
                                  __LINE__ = 277;
                                  _yieldState = 6;
                                  __LINE__ = 281;
                                  return 400;
                                case 4 :
                                  
                                  __LINE__ = 277;
                                  _yieldState = 6;
                                  __LINE__ = 283;
                                  return 600;
                                case 5 :
                                  
                                  __LINE__ = 277;
                                  _yieldState = 6;
                                  __LINE__ = 285;
                                  return 700;
                                case 6 :
                                  
                                  __LINE__ = 275;
                                  i ++ ;
                                  
                                  __LINE__ = 275;
                                  if ( i<10 ){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 1;
                                    __LINE__ = 275;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 274;
                                  if ( _isYieldSafe ){
                                    __LINE__ = 274;
                                    return undefined;
                                  } else {
                                    __LINE__ = 274;
                                    Runtime.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 274;
                    return Runtime.createGenerator( _mochaGenerator,
                    function (  ) {
                      try {
                        __LINE__ = 274;
                        _yieldState = -1;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
                __LINE__ = 289;
                generator = yieldTest11();
                
                __LINE__ = 290;
                generator.next();
                
                __LINE__ = 291;
                Runtime.assert( true,generator.send( 0 ) === 200,"generator.send( 0 ) === 200",291,'./yield_test.js' );
                
                __LINE__ = 292;
                generator.next();
                
                __LINE__ = 293;
                Runtime.assert( true,generator.send( 2 ) === 400,"generator.send( 2 ) === 400",293,'./yield_test.js' );
                
                __LINE__ = 294;
                generator.next();
                
                __LINE__ = 295;
                Runtime.assert( true,generator.send( 3 ) === 600,"generator.send( 3 ) === 600",295,'./yield_test.js' );
                
                __LINE__ = 296;
                generator.next();
                
                __LINE__ = 297;
                Runtime.assert( true,generator.send( null ) === 700,"generator.send( null ) === 700",297,'./yield_test.js' );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case11 : function () {
              try {
                function yieldTest12(  ) {
                  try {
                    __LINE__ = 301;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 301;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 301;
                    var _yieldState = 0;
                    
                    __LINE__ = 303;
                    var type;
                    
                    __LINE__ = 302;
                    var i = 0;
                    
                    __LINE__ = 301;
                    var _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 301;
                            if ( !_isYieldSend ){
                              
                              __LINE__ = 301;
                              _mochaIsNewBorn = false;
                            } else if ( _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined ){
                              
                              __LINE__ = 301;
                              Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 301;
                            while ( 1 ){
                              __LINE__ = 301;
                              switch ( _yieldState ) {
                                case 0 :
                                  
                                  __LINE__ = 302;
                                  if ( !( i<15 ) ){
                                    
                                    __LINE__ = 302;
                                    _yieldState = -1;
                                    __LINE__ = 302;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 304;
                                  _yieldState = 2;
                                  __LINE__ = 303;
                                  return ;
                                  
                                  __LINE__ = 303;
                                  _yieldResult = _isYieldSend && arguments.length>2?Runtime.toArray( arguments,2 )[0] : undefined;
                                  
                                  __LINE__ = 303;
                                  type = _yieldResult;
                                  
                                  __LINE__ = 304;
                                  switch ( type ) {
                                    case 4 :
                                    case 0 :
                                      
                                      __LINE__ = 304;
                                      _yieldState = 2;
                                      __LINE__ = 306;
                                      break;
                                    case 5 :
                                      
                                      __LINE__ = 304;
                                      _yieldState = 6;
                                      __LINE__ = 308;
                                      break;
                                    case 6 :
                                    case 2 :
                                      
                                      __LINE__ = 304;
                                      _yieldState = 3;
                                      __LINE__ = 311;
                                      break;
                                    case 3 :
                                      
                                      __LINE__ = 304;
                                      _yieldState = 4;
                                      __LINE__ = 313;
                                      break;
                                    default :
                                      
                                      __LINE__ = 304;
                                      _yieldState = 5;
                                      __LINE__ = 315;
                                      break;
                                      
                                  };
                                  __LINE__ = 304;
                                  break;
                                case 2 :
                                  
                                  __LINE__ = 304;
                                  _yieldState = 7;
                                  __LINE__ = 307;
                                  return 200;
                                case 3 :
                                  
                                  __LINE__ = 304;
                                  _yieldState = 7;
                                  __LINE__ = 312;
                                  return 400;
                                case 4 :
                                  
                                  __LINE__ = 304;
                                  _yieldState = 7;
                                  __LINE__ = 314;
                                  return 600;
                                case 5 :
                                  
                                  __LINE__ = 304;
                                  _yieldState = 7;
                                  __LINE__ = 316;
                                  return 700;
                                case 6 :
                                  
                                  __LINE__ = 304;
                                  _yieldState = 7;
                                  __LINE__ = 308;
                                  break;
                                case 7 :
                                  
                                  __LINE__ = 302;
                                  i ++ ;
                                  
                                  __LINE__ = 302;
                                  if ( i<15 ){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 1;
                                    __LINE__ = 302;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 301;
                                  if ( _isYieldSafe ){
                                    __LINE__ = 301;
                                    return undefined;
                                  } else {
                                    __LINE__ = 301;
                                    Runtime.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 301;
                    return Runtime.createGenerator( _mochaGenerator,
                    function (  ) {
                      try {
                        __LINE__ = 301;
                        _yieldState = -1;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
                __LINE__ = 320;
                generator = yieldTest12();
                
                __LINE__ = 321;
                generator.next();
                
                __LINE__ = 322;
                Runtime.assert( true,generator.send( 0 ) === 200,"generator.send( 0 ) === 200",322,'./yield_test.js' );
                
                __LINE__ = 323;
                generator.next();
                
                __LINE__ = 324;
                Runtime.assert( true,generator.send( 4 ) === 200,"generator.send( 4 ) === 200",324,'./yield_test.js' );
                
                __LINE__ = 325;
                generator.next();
                
                __LINE__ = 326;
                Runtime.assert( true,generator.send( 2 ) === 400,"generator.send( 2 ) === 400",326,'./yield_test.js' );
                
                __LINE__ = 327;
                generator.next();
                
                __LINE__ = 328;
                Runtime.assert( true,generator.send( 5 ) === undefined,"generator.send( 5 ) === undefined",328,'./yield_test.js' );
                
                __LINE__ = 329;
                Runtime.assert( true,generator.send( 3 ) === 600,"generator.send( 3 ) === 600",329,'./yield_test.js' );
                
                __LINE__ = 330;
                generator.next();
                
                __LINE__ = 331;
                Runtime.assert( true,generator.send( null ) === 700,"generator.send( null ) === 700",331,'./yield_test.js' );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case12 : function () {
              try {
                function yieldTest13() {
                  try {
                    __LINE__ = 335;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 335;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 335;
                    var _yieldState = 0;
                    
                    __LINE__ = 337;
                    var length;
                    
                    __LINE__ = 337;
                    var _mochaLocalTmp4;
                    
                    __LINE__ = 337;
                    var i;
                    
                    __LINE__ = 336;
                    var obj;
                    
                    __LINE__ = 337;
                    var _mochaLocalTmp3 = [];
                    
                    __LINE__ = 335;
                    var _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 335;
                            if ( !_isYieldSend ){
                              
                              __LINE__ = 335;
                              _mochaIsNewBorn = false;
                            } else if ( _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined ){
                              
                              __LINE__ = 335;
                              Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 335;
                            while ( 1 ){
                              __LINE__ = 335;
                              switch ( _yieldState ) {
                                case 0 :
                                  
                                  __LINE__ = 336;
                                  obj =  {
                                    x : 200,
                                    y : 300,
                                    z : 400
                                  };
                                  
                                  __LINE__ = 337;
                                  for ( var _mochaLocalTmp2 in obj ){
                                    
                                    __LINE__ = 337;
                                    _mochaLocalTmp3.push( _mochaLocalTmp2 );
                                  };
                                  
                                  __LINE__ = 337;
                                  _mochaLocalTmp4 = 0;
                                  
                                  __LINE__ = 337;
                                  length = _mochaLocalTmp3.length;
                                  
                                  __LINE__ = 337;
                                  if ( !( _mochaLocalTmp4<length ) ){
                                    
                                    __LINE__ = 337;
                                    _yieldState = -1;
                                    __LINE__ = 337;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 337;
                                  i = _mochaLocalTmp3[_mochaLocalTmp4];
                                  
                                  __LINE__ = 337;
                                   ++ _mochaLocalTmp4;
                                  
                                  __LINE__ = 337;
                                  if ( _mochaLocalTmp4<length ){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 1;
                                    __LINE__ = 337;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 335;
                                  if ( _isYieldSafe ){
                                    __LINE__ = 335;
                                    return undefined;
                                  } else {
                                    __LINE__ = 335;
                                    Runtime.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 335;
                    return Runtime.createGenerator( _mochaGenerator,
                    function (  ) {
                      try {
                        __LINE__ = 335;
                        _yieldState = -1;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
                __LINE__ = 342;
                generator = yieldTest13();
                
                __LINE__ = 343;
                var ret = generator.next();
                
                __LINE__ = 344;
                Runtime.assert( true,ret[0] === "x","ret[0] === \"x\"",344,'./yield_test.js' );
                
                __LINE__ = 345;
                Runtime.assert( true,ret[1] === 200,"ret[1] === 200",345,'./yield_test.js' );
                
                __LINE__ = 346;
                ret = generator.next();
                
                __LINE__ = 347;
                Runtime.assert( true,ret[0] === "y","ret[0] === \"y\"",347,'./yield_test.js' );
                
                __LINE__ = 348;
                Runtime.assert( true,ret[1] === 300,"ret[1] === 300",348,'./yield_test.js' );
                
                __LINE__ = 349;
                ret = generator.next();
                
                __LINE__ = 350;
                Runtime.assert( true,ret[0] === "z","ret[0] === \"z\"",350,'./yield_test.js' );
                
                __LINE__ = 351;
                Runtime.assert( true,ret[1] === 400,"ret[1] === 400",351,'./yield_test.js' );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            case13 : function () {
              try {
                function keys( obj ) {
                  try {
                    __LINE__ = 354;
                    var _mochaIsNewBorn = true;
                    
                    __LINE__ = 354;
                    var _yieldResult = undefined;
                    
                    __LINE__ = 354;
                    var _yieldState = 0;
                    
                    __LINE__ = 355;
                    var length;
                    
                    __LINE__ = 355;
                    var _mochaLocalTmp7;
                    
                    __LINE__ = 355;
                    var prop;
                    
                    __LINE__ = 355;
                    var _mochaLocalTmp6 = [];
                    
                    __LINE__ = 354;
                    var _mochaGenerator = function ( _isYieldSend,_isYieldSafe ) {
                          try {
                            __LINE__ = 354;
                            if ( !_isYieldSend ){
                              
                              __LINE__ = 354;
                              _mochaIsNewBorn = false;
                            } else if ( _isYieldSend && _mochaIsNewBorn && arguments[1] !== undefined ){
                              
                              __LINE__ = 354;
                              Runtime.exceptionHandler( 'attempt to send to newborn generator.' );
                            };
                            
                            __LINE__ = 354;
                            while ( 1 ){
                              __LINE__ = 354;
                              switch ( _yieldState ) {
                                case 0 :
                                  
                                  __LINE__ = 355;
                                  for ( var _mochaLocalTmp5 in obj ){
                                    
                                    __LINE__ = 355;
                                    _mochaLocalTmp6.push( _mochaLocalTmp5 );
                                  };
                                  
                                  __LINE__ = 355;
                                  _mochaLocalTmp7 = 0;
                                  
                                  __LINE__ = 355;
                                  length = _mochaLocalTmp6.length;
                                  
                                  __LINE__ = 355;
                                  if ( !( _mochaLocalTmp7<length ) ){
                                    
                                    __LINE__ = 355;
                                    _yieldState = -1;
                                    __LINE__ = 355;
                                    break;
                                  };
                                case 1 :
                                  
                                  __LINE__ = 355;
                                  prop = _mochaLocalTmp6[_mochaLocalTmp7];
                                  
                                  __LINE__ = 355;
                                   ++ _mochaLocalTmp7;
                                  
                                  __LINE__ = 355;
                                  if ( _mochaLocalTmp7<length ){
                                    
                                    __LINE__ = 0;
                                    _yieldState = 1;
                                    __LINE__ = 355;
                                    break;
                                  } else {
                                    
                                    __LINE__ = 0;
                                    _yieldState = -1;
                                  };
                                case -1 :
                                  
                                  __LINE__ = 354;
                                  if ( _isYieldSafe ){
                                    __LINE__ = 354;
                                    return undefined;
                                  } else {
                                    __LINE__ = 354;
                                    Runtime.throwStopIteration();
                                  };
                                  
                              };
                            };
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 354;
                    return Runtime.createGenerator( _mochaGenerator,
                    function (  ) {
                      try {
                        __LINE__ = 354;
                        _yieldState = -1;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },this);
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
                __LINE__ = 362;
                var testObject =  {
                      value1 : 1,
                      value2 : 2,
                      value3 : 3,
                      value4 : 4
                    };
                
                try {
                  
                  __LINE__ = 369;
                  var itemGen = keys( testObject );
                  __LINE__ = 370;
                  Runtime.assert( true,itemGen.next() == "value1","itemGen.next() == \"value1\"",370,'./yield_test.js' );
                  __LINE__ = 371;
                  Runtime.assert( true,itemGen.next() == "value2","itemGen.next() == \"value2\"",371,'./yield_test.js' );
                  __LINE__ = 372;
                  Runtime.assert( true,itemGen.next() == "value3","itemGen.next() == \"value3\"",372,'./yield_test.js' );
                  __LINE__ = 373;
                  Runtime.assert( true,itemGen.next() == "value4","itemGen.next() == \"value4\"",373,'./yield_test.js' );
                } catch( e ){
                  
                };
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            }
          };
      
      __LINE__ = 382;
      for ( var i = 1;i<13;i ++  ){
        tests["case"+i]()
      };
    } catch( e ){
      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  }();
}();
