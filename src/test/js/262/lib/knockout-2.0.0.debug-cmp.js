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
      var __FILE__ = "/var/samba/mocha/src/test/js/262/lib/knockout-2.0.0.debug.js",
          __LINE__ = 0;
      __LINE__ = 2;
      _mochaGlobalExport['./knockout-2.0.0.debug.js'] = {};
      
      __LINE__ = 3;
      var _mochaGlobalAlias = _mochaGlobalExport['./knockout-2.0.0.debug.js'];
      
      __LINE__ = 0;
      ( function ( window,undefined ) {
        try {
          __LINE__ = 6;
          var ko = window["ko"] = {};
          
          __LINE__ = 0;
          ko.exportSymbol = function ( publicPath,object ) {
            try {
              __LINE__ = 9;
              var tokens = publicPath.split( "." );
              
              __LINE__ = 10;
              var target = window;
              
              __LINE__ = 11;
              for ( var i = 0;i<tokens.length-1;i ++  ){
                __LINE__ = 0;
                target = target[tokens[i]];
              };
              
              __LINE__ = 0;
              target[tokens[tokens.length-1]] = object;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          ko.exportProperty = function ( owner,publicName,object ) {
            try {
              __LINE__ = 0;
              owner[publicName] = object;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          ko.utils = new ( function () {
            try {
              __LINE__ = 19;
              var stringTrimRegex = /^(\s|\u00A0)+|(\s|\u00A0)+$/g;
              
              __LINE__ = 22;
              var knownEvents = {},
                  knownEventTypesByEventName = {};
              
              __LINE__ = 23;
              var keyEventTypeName = /Firefox\/2/i.test( navigator.userAgent )?'KeyboardEvent' : 'UIEvents';
              
              __LINE__ = 0;
              knownEvents[keyEventTypeName] = ['keyup','keydown','keypress'];
              
              __LINE__ = 0;
              knownEvents['MouseEvents'] = ['click','dblclick','mousedown','mouseup','mousemove','mouseover','mouseout','mouseenter','mouseleave'];
              
              __LINE__ = 26;
              for ( var eventType in knownEvents ){
                __LINE__ = 27;
                var knownEventsForType = knownEvents[eventType];
                
                __LINE__ = 28;
                if ( knownEventsForType.length ){
                  __LINE__ = 29;
                  for ( var i = 0,j = knownEventsForType.length;i<j;i ++  ){
                    __LINE__ = 0;
                    knownEventTypesByEventName[knownEventsForType[i]] = eventType;
                  };
                };
              };
              
              __LINE__ = 35;
              var ieVersion = ( function () {
                    try {
                      __LINE__ = 36;
                      var version = 3,
                          div = document.createElement( 'div' ),
                          iElems = div.getElementsByTagName( 'i' );
                      
                      __LINE__ = 39;
                      while ( div.innerHTML = '<!--[if gt IE '+(  ++ version )+']><i></i><![endif]-->' , iElems[0] ){
                        
                      };
                      __LINE__ = 43;
                      return version>4?version : undefined;
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  }());
              
              __LINE__ = 45;
              var isIe6 = ieVersion === 6,
                  isIe7 = ieVersion === 7;
              
              function isClickOnCheckableElement( element,eventType ) {
                try {
                  __LINE__ = 49;
                  if ( ( element.tagName != "INPUT" ) || !element.type ){
                    __LINE__ = 49;
                    return false;
                  };
                  
                  __LINE__ = 50;
                  if ( eventType.toLowerCase() != "click" ){
                    __LINE__ = 50;
                    return false;
                  };
                  
                  __LINE__ = 51;
                  var inputType = element.type.toLowerCase();
                  __LINE__ = 52;
                  return ( inputType == "checkbox" ) || ( inputType == "radio" );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }__LINE__ = 55;
              return  {
                fieldsIncludedWithJsonPost : ['authenticity_token',/^__RequestVerificationToken(_.*)?$/],
                arrayForEach : function ( array,action ) {
                  try {
                    __LINE__ = 59;
                    for ( var i = 0,j = array.length;i<j;i ++  ){
                      __LINE__ = 0;
                      action( array[i] );
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                arrayIndexOf : function ( array,item ) {
                  try {
                    __LINE__ = 64;
                    if ( typeof Array.prototype.indexOf == "function" ){
                      __LINE__ = 65;
                      return Array.prototype.indexOf.call( array,item );
                    };
                    
                    __LINE__ = 66;
                    for ( var i = 0,j = array.length;i<j;i ++  ){
                      __LINE__ = 67;
                      if ( array[i] === item ){
                        __LINE__ = 68;
                        return i;
                      };
                    };
                    __LINE__ = 69;
                    return -1;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                arrayFirst : function ( array,predicate,predicateOwner ) {
                  try {
                    __LINE__ = 73;
                    for ( var i = 0,j = array.length;i<j;i ++  ){
                      __LINE__ = 74;
                      if ( predicate.call( predicateOwner,array[i] ) ){
                        __LINE__ = 75;
                        return array[i];
                      };
                    };
                    __LINE__ = 76;
                    return null;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                arrayRemoveItem : function ( array,itemToRemove ) {
                  try {
                    __LINE__ = 80;
                    var index = ko.utils.arrayIndexOf( array,itemToRemove );
                    
                    __LINE__ = 81;
                    if ( index >= 0 ){
                      __LINE__ = 0;
                      array.splice( index,1 );
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                arrayGetDistinctValues : function ( array ) {
                  try {
                    __LINE__ = 0;
                    array = array || [];
                    
                    __LINE__ = 87;
                    var result = [];
                    
                    __LINE__ = 88;
                    for ( var i = 0,j = array.length;i<j;i ++  ){
                      __LINE__ = 89;
                      if ( ko.utils.arrayIndexOf( result,array[i] )<0 ){
                        __LINE__ = 0;
                        result.push( array[i] );
                      };
                    };
                    __LINE__ = 92;
                    return result;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                arrayMap : function ( array,mapping ) {
                  try {
                    __LINE__ = 0;
                    array = array || [];
                    
                    __LINE__ = 97;
                    var result = [];
                    
                    __LINE__ = 98;
                    for ( var i = 0,j = array.length;i<j;i ++  ){
                      __LINE__ = 0;
                      result.push( mapping( array[i] ) );
                    };
                    __LINE__ = 100;
                    return result;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                arrayFilter : function ( array,predicate ) {
                  try {
                    __LINE__ = 0;
                    array = array || [];
                    
                    __LINE__ = 105;
                    var result = [];
                    
                    __LINE__ = 106;
                    for ( var i = 0,j = array.length;i<j;i ++  ){
                      __LINE__ = 107;
                      if ( predicate( array[i] ) ){
                        __LINE__ = 0;
                        result.push( array[i] );
                      };
                    };
                    __LINE__ = 109;
                    return result;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                arrayPushAll : function ( array,valuesToPush ) {
                  try {
                    __LINE__ = 113;
                    for ( var i = 0,j = valuesToPush.length;i<j;i ++  ){
                      __LINE__ = 0;
                      array.push( valuesToPush[i] );
                    };
                    __LINE__ = 115;
                    return array;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                extend : function ( target,source ) {
                  try {
                    __LINE__ = 119;
                    for ( var prop in source ){
                      __LINE__ = 120;
                      if ( source.hasOwnProperty( prop ) ){
                        __LINE__ = 0;
                        target[prop] = source[prop];
                      };
                    };
                    __LINE__ = 124;
                    return target;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                emptyDomNode : function ( domNode ) {
                  try {
                    __LINE__ = 128;
                    while ( domNode.firstChild ){
                      __LINE__ = 0;
                      ko.removeNode( domNode.firstChild );
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                setDomNodeChildren : function ( domNode,childNodes ) {
                  try {
                    __LINE__ = 0;
                    ko.utils.emptyDomNode( domNode );
                    
                    __LINE__ = 135;
                    if ( childNodes ){
                      __LINE__ = 0;
                      ko.utils.arrayForEach( childNodes,
                      function ( childNode ) {
                        try {
                          __LINE__ = 0;
                          domNode.appendChild( childNode );
                        } catch( e ){
                          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      });
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                replaceDomNodes : function ( nodeToReplaceOrNodeArray,newNodesArray ) {
                  try {
                    __LINE__ = 143;
                    var nodesToReplaceArray = nodeToReplaceOrNodeArray.nodeType?[nodeToReplaceOrNodeArray] : nodeToReplaceOrNodeArray;
                    
                    __LINE__ = 144;
                    if ( nodesToReplaceArray.length>0 ){
                      __LINE__ = 145;
                      var insertionPoint = nodesToReplaceArray[0];
                      
                      __LINE__ = 146;
                      var parent = insertionPoint.parentNode;
                      
                      __LINE__ = 147;
                      for ( var i = 0,j = newNodesArray.length;i<j;i ++  ){
                        __LINE__ = 0;
                        parent.insertBefore( newNodesArray[i],insertionPoint );
                      };
                      
                      __LINE__ = 149;
                      for ( var i = 0,j = nodesToReplaceArray.length;i<j;i ++  ){
                        __LINE__ = 0;
                        ko.removeNode( nodesToReplaceArray[i] );
                      };
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                setOptionNodeSelectionState : function ( optionNode,isSelected ) {
                  try {
                    __LINE__ = 157;
                    if ( navigator.userAgent.indexOf( "MSIE 6" ) >= 0 ){
                      __LINE__ = 0;
                      optionNode.setAttribute( "selected",isSelected );
                    } else {
                      __LINE__ = 0;
                      optionNode.selected = isSelected;
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                stringTrim : function ( string ) {
                  try {
                    __LINE__ = 164;
                    return ( string || "" ).replace( stringTrimRegex,"" );
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                stringTokenize : function ( string,delimiter ) {
                  try {
                    __LINE__ = 168;
                    var result = [];
                    
                    __LINE__ = 169;
                    var tokens = ( string || "" ).split( delimiter );
                    
                    __LINE__ = 170;
                    for ( var i = 0,j = tokens.length;i<j;i ++  ){
                      __LINE__ = 171;
                      var trimmed = ko.utils.stringTrim( tokens[i] );
                      
                      __LINE__ = 172;
                      if ( trimmed !== "" ){
                        __LINE__ = 0;
                        result.push( trimmed );
                      };
                    };
                    __LINE__ = 175;
                    return result;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                stringStartsWith : function ( string,startsWith ) {
                  try {
                    __LINE__ = 0;
                    string = string || "";
                    
                    __LINE__ = 180;
                    if ( startsWith.length>string.length ){
                      __LINE__ = 181;
                      return false;
                    };
                    __LINE__ = 182;
                    return string.substring( 0,startsWith.length ) === startsWith;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                evalWithinScope : function ( expression ) {
                  try {
                    __LINE__ = 189;
                    var scopes = Array.prototype.slice.call( arguments,1 );
                    
                    __LINE__ = 190;
                    var functionBody = "return ("+expression+")";
                    
                    __LINE__ = 191;
                    for ( var i = 0;i<scopes.length;i ++  ){
                      __LINE__ = 192;
                      if ( scopes[i] && typeof scopes[i] == "object" ){
                        __LINE__ = 0;
                        functionBody = "with(sc["+i+"]) { "+functionBody+" } ";
                      };
                    };
                    __LINE__ = 195;
                    return ( new Function( "sc",functionBody ) )( scopes );
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                domNodeIsContainedBy : function ( node,containedByNode ) {
                  try {
                    __LINE__ = 199;
                    if ( containedByNode.compareDocumentPosition ){
                      __LINE__ = 200;
                      return ( containedByNode.compareDocumentPosition( node )&16 ) == 16;
                    };
                    
                    __LINE__ = 201;
                    while ( node != null ){
                      __LINE__ = 202;
                      if ( node == containedByNode ){
                        __LINE__ = 203;
                        return true;
                      };
                      
                      __LINE__ = 0;
                      node = node.parentNode;
                    };
                    __LINE__ = 206;
                    return false;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                domNodeIsAttachedToDocument : function ( node ) {
                  try {
                    __LINE__ = 210;
                    return ko.utils.domNodeIsContainedBy( node,document );
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                registerEventHandler : function ( element,eventType,handler ) {
                  try {
                    __LINE__ = 214;
                    if ( typeof jQuery != "undefined" ){
                      __LINE__ = 215;
                      if ( isClickOnCheckableElement( element,eventType ) ){
                        __LINE__ = 220;
                        var originalHandler = handler;
                        
                        __LINE__ = 0;
                        handler = function ( event,eventData ) {
                          try {
                            __LINE__ = 222;
                            var jQuerySuppliedCheckedState = this.checked;
                            
                            __LINE__ = 223;
                            if ( eventData ){
                              __LINE__ = 0;
                              this.checked = eventData.checkedStateBeforeEvent !== true;
                            };
                            
                            __LINE__ = 0;
                            originalHandler.call( this,event );
                            
                            __LINE__ = 0;
                            this.checked = jQuerySuppliedCheckedState;
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                      };
                      
                      __LINE__ = 0;
                      jQuery( element )['bind']( eventType,handler );
                    } else if ( typeof element.addEventListener == "function" ){
                      __LINE__ = 0;
                      element.addEventListener( eventType,handler,false );
                    } else if ( typeof element.attachEvent != "undefined" ){
                      __LINE__ = 0;
                      element.attachEvent( "on"+eventType,
                      function ( event ) {
                        try {
                          __LINE__ = 0;
                          handler.call( element,event );
                        } catch( e ){
                          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      });
                    } else {
                      __LINE__ = 237;
                      throw new Error( "Browser doesn't support addEventListener or attachEvent" );
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                triggerEvent : function ( element,eventType ) {
                  try {
                    __LINE__ = 241;
                    if ( !( element && element.nodeType ) ){
                      __LINE__ = 242;
                      throw new Error( "element must be a DOM node when calling triggerEvent" );
                    };
                    
                    __LINE__ = 244;
                    if ( typeof jQuery != "undefined" ){
                      __LINE__ = 245;
                      var eventData = [];
                      
                      __LINE__ = 246;
                      if ( isClickOnCheckableElement( element,eventType ) ){
                        __LINE__ = 0;
                        eventData.push(  {
                          checkedStateBeforeEvent : element.checked
                        });
                      };
                      
                      __LINE__ = 0;
                      jQuery( element )['trigger']( eventType,eventData );
                    } else if ( typeof document.createEvent == "function" ){
                      if ( typeof element.dispatchEvent == "function" ){
                        __LINE__ = 253;
                        var eventCategory = knownEventTypesByEventName[eventType] || "HTMLEvents";
                        
                        __LINE__ = 254;
                        var event = document.createEvent( eventCategory );
                        
                        __LINE__ = 0;
                        event.initEvent( eventType,true,true,window,0,0,0,0,0,false,false,false,false,0,element );
                        
                        __LINE__ = 0;
                        element.dispatchEvent( event );
                      } else {
                        __LINE__ = 259;
                        throw new Error( "The supplied element doesn't support dispatchEvent" );
                      };
                    } else if ( typeof element.fireEvent != "undefined" ){
                      if ( eventType == "click" ){
                        if ( ( element.tagName == "INPUT" ) && ( ( element.type.toLowerCase() == "checkbox" ) || ( element.type.toLowerCase() == "radio" ) ) ){
                          __LINE__ = 0;
                          element.checked = element.checked !== true;
                        };
                      };
                      
                      __LINE__ = 0;
                      element.fireEvent( "on"+eventType );
                    } else {
                      __LINE__ = 270;
                      throw new Error( "Browser doesn't support triggering events" );
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                unwrapObservable : function ( value ) {
                  try {
                    __LINE__ = 274;
                    return ko.isObservable( value )?value() : value;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                domNodeHasCssClass : function ( node,className ) {
                  try {
                    __LINE__ = 278;
                    var currentClassNames = ( node.className || "" ).split( /\s+/ );
                    __LINE__ = 279;
                    return ko.utils.arrayIndexOf( currentClassNames,className ) >= 0;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                toggleDomNodeCssClass : function ( node,className,shouldHaveClass ) {
                  try {
                    __LINE__ = 283;
                    var hasClass = ko.utils.domNodeHasCssClass( node,className );
                    
                    __LINE__ = 284;
                    if ( shouldHaveClass && !hasClass ){
                      __LINE__ = 0;
                      node.className = ( node.className || "" )+" "+className;
                    } else if ( hasClass && !shouldHaveClass ){
                      __LINE__ = 287;
                      var currentClassNames = ( node.className || "" ).split( /\s+/ );
                      
                      __LINE__ = 288;
                      var newClassName = "";
                      
                      __LINE__ = 289;
                      for ( var i = 0;i<currentClassNames.length;i ++  ){
                        if ( currentClassNames[i] != className ){
                          __LINE__ = 0;
                          newClassName += currentClassNames[i]+" ";
                        };
                      };
                      
                      __LINE__ = 0;
                      node.className = ko.utils.stringTrim( newClassName );
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                outerHTML : function ( node ) {
                  try {
                    __LINE__ = 299;
                    if ( ieVersion === undefined ){
                      __LINE__ = 300;
                      var nativeOuterHtml = node.outerHTML;
                      
                      __LINE__ = 301;
                      if ( typeof nativeOuterHtml == "string" ){
                        __LINE__ = 302;
                        return nativeOuterHtml;
                      };
                    };
                    
                    __LINE__ = 306;
                    var dummyContainer = window.document.createElement( "div" );
                    
                    __LINE__ = 0;
                    dummyContainer.appendChild( node.cloneNode( true ) );
                    __LINE__ = 308;
                    return dummyContainer.innerHTML;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                setTextContent : function ( element,textContent ) {
                  try {
                    __LINE__ = 312;
                    var value = ko.utils.unwrapObservable( textContent );
                    
                    __LINE__ = 313;
                    if ( ( value === null ) || ( value === undefined ) ){
                      __LINE__ = 0;
                      value = "";
                    };
                    
                    __LINE__ = 0;
                    'innerText' in element?element.innerText = value : element.textContent = value;
                    
                    __LINE__ = 319;
                    if ( ieVersion >= 9 ){
                      __LINE__ = 0;
                      element.innerHTML = element.innerHTML;
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                range : function ( min,max ) {
                  try {
                    __LINE__ = 0;
                    min = ko.utils.unwrapObservable( min );
                    
                    __LINE__ = 0;
                    max = ko.utils.unwrapObservable( max );
                    
                    __LINE__ = 328;
                    var result = [];
                    
                    __LINE__ = 329;
                    for ( var i = min;i <= max;i ++  ){
                      __LINE__ = 0;
                      result.push( i );
                    };
                    __LINE__ = 331;
                    return result;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                makeArray : function ( arrayLikeObject ) {
                  try {
                    __LINE__ = 335;
                    var result = [];
                    
                    __LINE__ = 336;
                    for ( var i = 0,j = arrayLikeObject.length;i<j;i ++  ){
                      __LINE__ = 0;
                      result.push( arrayLikeObject[i] );
                    };
                    __LINE__ = 339;
                    return result;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                isIe6 : isIe6,
                isIe7 : isIe7,
                getFormFields : function ( form,fieldName ) {
                  try {
                    __LINE__ = 346;
                    var fields = ko.utils.makeArray( form.getElementsByTagName( "INPUT" ) ).concat( ko.utils.makeArray( form.getElementsByTagName( "TEXTAREA" ) ) );
                    
                    __LINE__ = 347;
                    var isMatchingField = ( typeof fieldName == 'string' )?function ( field ) {
                          try {
                            __LINE__ = 348;
                            return field.name === fieldName;
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        } : function ( field ) {
                          try {
                            __LINE__ = 349;
                            return fieldName.test( field.name );
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    
                    __LINE__ = 350;
                    var matches = [];
                    
                    __LINE__ = 351;
                    for ( var i = fields.length-1;i >= 0;i --  ){
                      __LINE__ = 352;
                      if ( isMatchingField( fields[i] ) ){
                        __LINE__ = 0;
                        matches.push( fields[i] );
                      };
                    };
                    __LINE__ = 355;
                    return matches;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                parseJson : function ( jsonString ) {
                  try {
                    __LINE__ = 359;
                    if ( typeof jsonString == "string" ){
                      __LINE__ = 0;
                      jsonString = ko.utils.stringTrim( jsonString );
                      
                      __LINE__ = 361;
                      if ( jsonString ){
                        __LINE__ = 362;
                        if ( window.JSON && window.JSON.parse ){
                          __LINE__ = 363;
                          return window.JSON.parse( jsonString );
                        };
                        __LINE__ = 364;
                        return ( new Function( "return "+jsonString ) )();
                      };
                    };
                    __LINE__ = 367;
                    return null;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                stringifyJson : function ( data ) {
                  try {
                    __LINE__ = 371;
                    if ( ( typeof JSON == "undefined" ) || ( typeof JSON.stringify == "undefined" ) ){
                      __LINE__ = 372;
                      throw new Error( "Cannot find JSON.stringify(). Some browsers (e.g., IE < 8) don't support it natively, but you can overcome this by adding a script reference to json2.js, downloadable from http://www.json.org/json2.js" );
                    };
                    __LINE__ = 373;
                    return JSON.stringify( ko.utils.unwrapObservable( data ) );
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                postJson : function ( urlOrForm,data,options ) {
                  try {
                    __LINE__ = 0;
                    options = options || {};
                    
                    __LINE__ = 378;
                    var params = options['params'] || {};
                    
                    __LINE__ = 379;
                    var includeFields = options['includeFields'] || this.fieldsIncludedWithJsonPost;
                    
                    __LINE__ = 380;
                    var url = urlOrForm;
                    
                    __LINE__ = 383;
                    if ( ( typeof urlOrForm == 'object' ) && ( urlOrForm.tagName == "FORM" ) ){
                      __LINE__ = 384;
                      var originalForm = urlOrForm;
                      
                      __LINE__ = 0;
                      url = originalForm.action;
                      
                      __LINE__ = 386;
                      for ( var i = includeFields.length-1;i >= 0;i --  ){
                        __LINE__ = 387;
                        var fields = ko.utils.getFormFields( originalForm,includeFields[i] );
                        
                        __LINE__ = 388;
                        for ( var j = fields.length-1;j >= 0;j --  ){
                          __LINE__ = 0;
                          params[fields[j].name] = fields[j].value;
                        };
                      };
                    };
                    
                    __LINE__ = 0;
                    data = ko.utils.unwrapObservable( data );
                    
                    __LINE__ = 394;
                    var form = document.createElement( "FORM" );
                    
                    __LINE__ = 0;
                    form.style.display = "none";
                    
                    __LINE__ = 0;
                    form.action = url;
                    
                    __LINE__ = 0;
                    form.method = "post";
                    
                    __LINE__ = 398;
                    for ( var key in data ){
                      __LINE__ = 399;
                      var input = document.createElement( "INPUT" );
                      
                      __LINE__ = 0;
                      input.name = key;
                      
                      __LINE__ = 0;
                      input.value = ko.utils.stringifyJson( ko.utils.unwrapObservable( data[key] ) );
                      
                      __LINE__ = 0;
                      form.appendChild( input );
                    };
                    
                    __LINE__ = 404;
                    for ( var key in params ){
                      __LINE__ = 405;
                      var input = document.createElement( "INPUT" );
                      
                      __LINE__ = 0;
                      input.name = key;
                      
                      __LINE__ = 0;
                      input.value = params[key];
                      
                      __LINE__ = 0;
                      form.appendChild( input );
                    };
                    
                    __LINE__ = 0;
                    document.body.appendChild( form );
                    
                    __LINE__ = 0;
                    options['submitter']?options['submitter']( form ) : form.submit();
                    
                    __LINE__ = 0;
                    setTimeout( function () {
                      try {
                        __LINE__ = 0;
                        form.parentNode.removeChild( form );
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },0);
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
              };
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })();
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.utils',ko.utils );
          
          __LINE__ = 0;
          ko.utils.arrayForEach( [['arrayForEach',ko.utils.arrayForEach],['arrayFirst',ko.utils.arrayFirst],['arrayFilter',ko.utils.arrayFilter],['arrayGetDistinctValues',ko.utils.arrayGetDistinctValues],['arrayIndexOf',ko.utils.arrayIndexOf],['arrayMap',ko.utils.arrayMap],['arrayPushAll',ko.utils.arrayPushAll],['arrayRemoveItem',ko.utils.arrayRemoveItem],['extend',ko.utils.extend],['fieldsIncludedWithJsonPost',ko.utils.fieldsIncludedWithJsonPost],['getFormFields',ko.utils.getFormFields],['postJson',ko.utils.postJson],['parseJson',ko.utils.parseJson],['registerEventHandler',ko.utils.registerEventHandler],['stringifyJson',ko.utils.stringifyJson],['range',ko.utils.range],['toggleDomNodeCssClass',ko.utils.toggleDomNodeCssClass],['triggerEvent',ko.utils.triggerEvent],['unwrapObservable',ko.utils.unwrapObservable]],
          function ( item ) {
            try {
              __LINE__ = 0;
              ko.exportSymbol( 'ko.utils.'+item[0],item[1] );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          });
          
          __LINE__ = 442;
          if ( !Function.prototype['bind'] ){
            __LINE__ = 0;
            Function.prototype['bind'] = function ( object ) {
              try {
                __LINE__ = 446;
                var originalFunction = this,
                    args = Array.prototype.slice.call( arguments ),
                    object = args.shift();
                __LINE__ = 447;
                return function () {
                  try {
                    __LINE__ = 448;
                    return originalFunction.apply( object,args.concat( Array.prototype.slice.call( arguments ) ) );
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
          };
          
          __LINE__ = 0;
          ko.utils.domData = new ( function () {
            try {
              __LINE__ = 453;
              var uniqueId = 0;
              
              __LINE__ = 454;
              var dataStoreKeyExpandoPropertyName = "__ko__"+( new Date ).getTime();
              
              __LINE__ = 455;
              var dataStore = {};
              __LINE__ = 456;
              return  {
                get : function ( node,key ) {
                  try {
                    __LINE__ = 458;
                    var allDataForNode = ko.utils.domData.getAll( node,false );
                    __LINE__ = 459;
                    return allDataForNode === undefined?undefined : allDataForNode[key];
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                set : function ( node,key,value ) {
                  try {
                    __LINE__ = 462;
                    if ( value === undefined ){
                      __LINE__ = 464;
                      if ( ko.utils.domData.getAll( node,false ) === undefined ){
                        __LINE__ = 465;
                        return ;
                      };
                    };
                    
                    __LINE__ = 467;
                    var allDataForNode = ko.utils.domData.getAll( node,true );
                    
                    __LINE__ = 0;
                    allDataForNode[key] = value;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                getAll : function ( node,createIfNotFound ) {
                  try {
                    __LINE__ = 471;
                    var dataStoreKey = node[dataStoreKeyExpandoPropertyName];
                    
                    __LINE__ = 472;
                    var hasExistingDataStore = dataStoreKey && ( dataStoreKey !== "null" );
                    
                    __LINE__ = 473;
                    if ( !hasExistingDataStore ){
                      __LINE__ = 474;
                      if ( !createIfNotFound ){
                        __LINE__ = 475;
                        return undefined;
                      };
                      
                      __LINE__ = 0;
                      dataStoreKey = node[dataStoreKeyExpandoPropertyName] = "ko"+uniqueId ++ ;
                      
                      __LINE__ = 0;
                      dataStore[dataStoreKey] = {};
                    };
                    __LINE__ = 479;
                    return dataStore[dataStoreKey];
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                clear : function ( node ) {
                  try {
                    __LINE__ = 482;
                    var dataStoreKey = node[dataStoreKeyExpandoPropertyName];
                    
                    __LINE__ = 483;
                    if ( dataStoreKey ){
                      __LINE__ = 0;
                      delete dataStore[dataStoreKey];
                      
                      __LINE__ = 0;
                      node[dataStoreKeyExpandoPropertyName] = null;
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
              };
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })();
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.utils.domData',ko.utils.domData );
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.utils.domData.clear',ko.utils.domData.clear );
          
          __LINE__ = 0;
          ko.utils.domNodeDisposal = new ( function () {
            try {
              __LINE__ = 494;
              var domDataKey = "__ko_domNodeDisposal__"+( new Date ).getTime();
              
              function getDisposeCallbacksCollection( node,createIfNotFound ) {
                try {
                  __LINE__ = 497;
                  var allDisposeCallbacks = ko.utils.domData.get( node,domDataKey );
                  
                  __LINE__ = 498;
                  if ( ( allDisposeCallbacks === undefined ) && createIfNotFound ){
                    __LINE__ = 0;
                    allDisposeCallbacks = [];
                    
                    __LINE__ = 0;
                    ko.utils.domData.set( node,domDataKey,allDisposeCallbacks );
                  };
                  __LINE__ = 502;
                  return allDisposeCallbacks;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              function destroyCallbacksCollection( node ) {
                try {
                  __LINE__ = 0;
                  ko.utils.domData.set( node,domDataKey,undefined );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              function cleanSingleNode( node ) {
                try {
                  __LINE__ = 510;
                  var callbacks = getDisposeCallbacksCollection( node,false );
                  
                  __LINE__ = 511;
                  if ( callbacks ){
                    __LINE__ = 0;
                    callbacks = callbacks.slice( 0 );
                    
                    __LINE__ = 513;
                    for ( var i = 0;i<callbacks.length;i ++  ){
                      __LINE__ = 0;
                      callbacks[i]( node );
                    };
                  };
                  
                  __LINE__ = 0;
                  ko.utils.domData.clear( node );
                  
                  __LINE__ = 523;
                  if ( ( typeof jQuery == "function" ) && ( typeof jQuery['cleanData'] == "function" ) ){
                    __LINE__ = 0;
                    jQuery['cleanData']( [node] );
                  };
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }__LINE__ = 527;
              return  {
                addDisposeCallback : function ( node,callback ) {
                  try {
                    __LINE__ = 529;
                    if ( typeof callback != "function" ){
                      __LINE__ = 530;
                      throw new Error( "Callback must be a function" );
                    };
                    
                    __LINE__ = 0;
                    getDisposeCallbacksCollection( node,true ).push( callback );
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                removeDisposeCallback : function ( node,callback ) {
                  try {
                    __LINE__ = 535;
                    var callbacksCollection = getDisposeCallbacksCollection( node,false );
                    
                    __LINE__ = 536;
                    if ( callbacksCollection ){
                      __LINE__ = 0;
                      ko.utils.arrayRemoveItem( callbacksCollection,callback );
                      
                      __LINE__ = 538;
                      if ( callbacksCollection.length == 0 ){
                        __LINE__ = 0;
                        destroyCallbacksCollection( node );
                      };
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                cleanNode : function ( node ) {
                  try {
                    __LINE__ = 544;
                    if ( ( node.nodeType != 1 ) && ( node.nodeType != 9 ) ){
                      __LINE__ = 545;
                      return ;
                    };
                    
                    __LINE__ = 0;
                    cleanSingleNode( node );
                    
                    __LINE__ = 549;
                    var descendants = [];
                    
                    __LINE__ = 0;
                    ko.utils.arrayPushAll( descendants,node.getElementsByTagName( "*" ) );
                    
                    __LINE__ = 551;
                    for ( var i = 0,j = descendants.length;i<j;i ++  ){
                      __LINE__ = 0;
                      cleanSingleNode( descendants[i] );
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                removeNode : function ( node ) {
                  try {
                    __LINE__ = 0;
                    ko.cleanNode( node );
                    
                    __LINE__ = 557;
                    if ( node.parentNode ){
                      __LINE__ = 0;
                      node.parentNode.removeChild( node );
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
              };
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })();
          
          __LINE__ = 0;
          ko.cleanNode = ko.utils.domNodeDisposal.cleanNode;
          
          __LINE__ = 0;
          ko.removeNode = ko.utils.domNodeDisposal.removeNode;
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.cleanNode',ko.cleanNode );
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.removeNode',ko.removeNode );
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.utils.domNodeDisposal',ko.utils.domNodeDisposal );
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.utils.domNodeDisposal.addDisposeCallback',ko.utils.domNodeDisposal.addDisposeCallback );
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.utils.domNodeDisposal.removeDisposeCallback',ko.utils.domNodeDisposal.removeDisposeCallback );
          
          __LINE__ = 0;
          ( function () {
            try {
              __LINE__ = 569;
              var leadingCommentRegex = /^(\s*)<!--(.*?)-->/;
              
              function simpleHtmlParse( html ) {
                try {
                  __LINE__ = 581;
                  var tags = ko.utils.stringTrim( html ).toLowerCase(),
                      div = document.createElement( "div" );
                  
                  __LINE__ = 584;
                  var wrap = tags.match( /^<(thead|tbody|tfoot)/ ) && [1,"<table>","</table>"] || !tags.indexOf( "<tr" ) && [2,"<table><tbody>","</tbody></table>"] || ( !tags.indexOf( "<td" ) || !tags.indexOf( "<th" ) ) && [3,"<table><tbody><tr>","</tr></tbody></table>"] || [0,"",""];
                  
                  __LINE__ = 591;
                  var markup = "ignored<div>"+wrap[1]+html+wrap[2]+"</div>";
                  
                  __LINE__ = 592;
                  if ( typeof window['innerShiv'] == "function" ){
                    __LINE__ = 0;
                    div.appendChild( window['innerShiv']( markup ) );
                  } else {
                    __LINE__ = 0;
                    div.innerHTML = markup;
                  };
                  
                  __LINE__ = 599;
                  while ( wrap[0] --  ){
                    __LINE__ = 0;
                    div = div.lastChild;
                  };
                  __LINE__ = 602;
                  return ko.utils.makeArray( div.lastChild.childNodes );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              function jQueryHtmlParse( html ) {
                try {
                  __LINE__ = 606;
                  var elems = jQuery['clean']( [html] );
                  
                  __LINE__ = 611;
                  if ( elems && elems[0] ){
                    __LINE__ = 613;
                    var elem = elems[0];
                    
                    __LINE__ = 614;
                    while ( elem.parentNode && elem.parentNode.nodeType !== 11 ){
                      __LINE__ = 0;
                      elem = elem.parentNode;
                    };
                    
                    __LINE__ = 617;
                    if ( elem.parentNode ){
                      __LINE__ = 0;
                      elem.parentNode.removeChild( elem );
                    };
                  };
                  __LINE__ = 621;
                  return elems;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              __LINE__ = 0;
              ko.utils.parseHtmlFragment = function ( html ) {
                try {
                  __LINE__ = 625;
                  return typeof jQuery != 'undefined'?jQueryHtmlParse( html ) : simpleHtmlParse( html );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              ko.utils.setHtml = function ( node,html ) {
                try {
                  __LINE__ = 0;
                  ko.utils.emptyDomNode( node );
                  
                  __LINE__ = 632;
                  if ( ( html !== null ) && ( html !== undefined ) ){
                    __LINE__ = 633;
                    if ( typeof html != 'string' ){
                      __LINE__ = 0;
                      html = html.toString();
                    };
                    
                    __LINE__ = 639;
                    if ( typeof jQuery != 'undefined' ){
                      __LINE__ = 0;
                      jQuery( node )['html']( html );
                    } else {
                      __LINE__ = 643;
                      var parsedNodes = ko.utils.parseHtmlFragment( html );
                      
                      __LINE__ = 644;
                      for ( var i = 0;i<parsedNodes.length;i ++  ){
                        __LINE__ = 0;
                        node.appendChild( parsedNodes[i] );
                      };
                    };
                  };
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })();
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.utils.parseHtmlFragment',ko.utils.parseHtmlFragment );
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.utils.setHtml',ko.utils.setHtml );
          
          __LINE__ = 0;
          ko.memoization = ( function () {
            try {
              __LINE__ = 654;
              var memos = {};
              
              function randomMax8HexChars() {
                try {
                  __LINE__ = 657;
                  return ( ( ( 1+Math.random() )*0x00000000 )|0 ).toString( 16 ).substring( 1 );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              function generateRandomId() {
                try {
                  __LINE__ = 660;
                  return randomMax8HexChars()+randomMax8HexChars();
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              function findMemoNodes( rootNode,appendToArray ) {
                try {
                  __LINE__ = 663;
                  if ( !rootNode ){
                    __LINE__ = 664;
                    return ;
                  };
                  
                  __LINE__ = 665;
                  if ( rootNode.nodeType == 8 ){
                    __LINE__ = 666;
                    var memoId = ko.memoization.parseMemoText( rootNode.nodeValue );
                    
                    __LINE__ = 667;
                    if ( memoId != null ){
                      __LINE__ = 0;
                      appendToArray.push(  {
                        domNode : rootNode,
                        memoId : memoId
                      });
                    };
                  } else if ( rootNode.nodeType == 1 ){
                    __LINE__ = 670;
                    for ( var i = 0,childNodes = rootNode.childNodes,j = childNodes.length;i<j;i ++  ){
                      __LINE__ = 0;
                      findMemoNodes( childNodes[i],appendToArray );
                    };
                  };
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }__LINE__ = 675;
              return  {
                memoize : function ( callback ) {
                  try {
                    __LINE__ = 677;
                    if ( typeof callback != "function" ){
                      __LINE__ = 678;
                      throw new Error( "You can only pass a function to ko.memoization.memoize()" );
                    };
                    
                    __LINE__ = 679;
                    var memoId = generateRandomId();
                    
                    __LINE__ = 0;
                    memos[memoId] = callback;
                    __LINE__ = 681;
                    return "<!--[ko_memo:"+memoId+"]-->";
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                unmemoize : function ( memoId,callbackParams ) {
                  try {
                    __LINE__ = 685;
                    var callback = memos[memoId];
                    
                    __LINE__ = 686;
                    if ( callback === undefined ){
                      __LINE__ = 687;
                      throw new Error( "Couldn't find any memo with ID "+memoId+". Perhaps it's already been unmemoized." );
                    };
                    
                    try {
                      __LINE__ = 0;
                      callback.apply( null,callbackParams || [] );
                      __LINE__ = 690;
                      return true;
                    } finally {
                      __LINE__ = 0;
                      delete memos[memoId];
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                unmemoizeDomNodeAndDescendants : function ( domNode,extraCallbackParamsArray ) {
                  try {
                    __LINE__ = 696;
                    var memos = [];
                    
                    __LINE__ = 0;
                    findMemoNodes( domNode,memos );
                    
                    __LINE__ = 698;
                    for ( var i = 0,j = memos.length;i<j;i ++  ){
                      __LINE__ = 699;
                      var node = memos[i].domNode;
                      
                      __LINE__ = 700;
                      var combinedParams = [node];
                      
                      __LINE__ = 701;
                      if ( extraCallbackParamsArray ){
                        __LINE__ = 0;
                        ko.utils.arrayPushAll( combinedParams,extraCallbackParamsArray );
                      };
                      
                      __LINE__ = 0;
                      ko.memoization.unmemoize( memos[i].memoId,combinedParams );
                      
                      __LINE__ = 0;
                      node.nodeValue = "";
                      
                      __LINE__ = 705;
                      if ( node.parentNode ){
                        __LINE__ = 0;
                        node.parentNode.removeChild( node );
                      };
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                parseMemoText : function ( memoText ) {
                  try {
                    __LINE__ = 711;
                    var match = memoText.match( /^\[ko_memo\:(.*?)\]$/ );
                    __LINE__ = 712;
                    return match?match[1] : null;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
              };
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })();
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.memoization',ko.memoization );
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.memoization.memoize',ko.memoization.memoize );
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.memoization.unmemoize',ko.memoization.unmemoize );
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.memoization.parseMemoText',ko.memoization.parseMemoText );
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.memoization.unmemoizeDomNodeAndDescendants',ko.memoization.unmemoizeDomNodeAndDescendants );
          
          __LINE__ = 0;
          ko.extenders =  {
            'throttle' : function ( target,timeout ) {
              try {
                __LINE__ = 0;
                target['throttleEvaluation'] = timeout;
                
                __LINE__ = 732;
                var writeTimeoutInstance = null;
                __LINE__ = 733;
                return ko.dependentObservable(  {
                  'read' : target,
                  'write' : function ( value ) {
                    try {
                      __LINE__ = 0;
                      clearTimeout( writeTimeoutInstance );
                      
                      __LINE__ = 0;
                      writeTimeoutInstance = setTimeout( function () {
                        try {
                          __LINE__ = 0;
                          target( value );
                        } catch( e ){
                          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      },timeout);
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  }
                });
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            'notify' : function ( target,notifyWhen ) {
              try {
                __LINE__ = 0;
                target["equalityComparer"] = notifyWhen == "always"?function () {
                  try {
                    __LINE__ = 746;
                    return false;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                } : ko.observable["fn"]["equalityComparer"];
                __LINE__ = 748;
                return target;
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            }
          };
          
          function applyExtenders( requestedExtenders ) {
            try {
              __LINE__ = 753;
              var target = this;
              
              __LINE__ = 754;
              if ( requestedExtenders ){
                __LINE__ = 755;
                for ( var key in requestedExtenders ){
                  __LINE__ = 756;
                  var extenderHandler = ko.extenders[key];
                  
                  __LINE__ = 757;
                  if ( typeof extenderHandler == 'function' ){
                    __LINE__ = 0;
                    target = extenderHandler( target,requestedExtenders[key] );
                  };
                };
              };
              __LINE__ = 762;
              return target;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          __LINE__ = 0;
          ko.exportSymbol( 'ko.extenders',ko.extenders );
          
          __LINE__ = 0;
          ko.subscription = function ( callback,disposeCallback ) {
            try {
              __LINE__ = 0;
              this.callback = callback;
              
              __LINE__ = 0;
              this.disposeCallback = disposeCallback;
              
              __LINE__ = 0;
              ko.exportProperty( this,'dispose',this.dispose );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          ko.subscription.prototype.dispose = function () {
            try {
              __LINE__ = 0;
              this.isDisposed = true;
              
              __LINE__ = 0;
              this.disposeCallback();
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          ko.subscribable = function () {
            try {
              __LINE__ = 0;
              this._subscriptions = {};
              
              __LINE__ = 0;
              ko.utils.extend( this,ko.subscribable['fn'] );
              
              __LINE__ = 0;
              ko.exportProperty( this,'subscribe',this.subscribe );
              
              __LINE__ = 0;
              ko.exportProperty( this,'extend',this.extend );
              
              __LINE__ = 0;
              ko.exportProperty( this,'getSubscriptionsCount',this.getSubscriptionsCount );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 785;
          var defaultEvent = "change";
          
          __LINE__ = 0;
          ko.subscribable['fn'] =  {
            subscribe : function ( callback,callbackTarget,event ) {
              try {
                __LINE__ = 0;
                event = event || defaultEvent;
                
                __LINE__ = 790;
                var boundCallback = callbackTarget?callback.bind( callbackTarget ) : callback;
                
                __LINE__ = 792;
                var subscription = new ko.subscription( boundCallback,function () {
                      try {
                        __LINE__ = 0;
                        ko.utils.arrayRemoveItem( this._subscriptions[event],subscription );
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    }.bind( this ) );
                
                __LINE__ = 796;
                if ( !this._subscriptions[event] ){
                  __LINE__ = 0;
                  this._subscriptions[event] = [];
                };
                
                __LINE__ = 0;
                this._subscriptions[event].push( subscription );
                __LINE__ = 799;
                return subscription;
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            "notifySubscribers" : function ( valueToNotify,event ) {
              try {
                __LINE__ = 0;
                event = event || defaultEvent;
                
                __LINE__ = 804;
                if ( this._subscriptions[event] ){
                  __LINE__ = 0;
                  ko.utils.arrayForEach( this._subscriptions[event].slice( 0 ),
                  function ( subscription ) {
                    try {
                      __LINE__ = 808;
                      if ( subscription && ( subscription.isDisposed !== true ) ){
                        __LINE__ = 0;
                        subscription.callback( valueToNotify );
                      };
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  });
                };
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            getSubscriptionsCount : function () {
              try {
                __LINE__ = 815;
                var total = 0;
                
                __LINE__ = 816;
                for ( var eventName in this._subscriptions ){
                  __LINE__ = 817;
                  if ( this._subscriptions.hasOwnProperty( eventName ) ){
                    __LINE__ = 0;
                    total += this._subscriptions[eventName].length;
                  };
                };
                __LINE__ = 820;
                return total;
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            extend : applyExtenders
          };
          
          __LINE__ = 0;
          ko.isSubscribable = function ( instance ) {
            try {
              __LINE__ = 828;
              return typeof instance.subscribe == "function" && typeof instance["notifySubscribers"] == "function";
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.subscribable',ko.subscribable );
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.isSubscribable',ko.isSubscribable );
          
          __LINE__ = 0;
          ko.dependencyDetection = ( function () {
            try {
              __LINE__ = 835;
              var _frames = [];
              __LINE__ = 837;
              return  {
                begin : function ( callback ) {
                  try {
                    __LINE__ = 0;
                    _frames.push(  {
                      callback : callback,
                      distinctDependencies : []
                    });
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                end : function () {
                  try {
                    __LINE__ = 0;
                    _frames.pop();
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                registerDependency : function ( subscribable ) {
                  try {
                    __LINE__ = 847;
                    if ( !ko.isSubscribable( subscribable ) ){
                      __LINE__ = 848;
                      throw "Only subscribable things can act as dependencies";
                    };
                    
                    __LINE__ = 849;
                    if ( _frames.length>0 ){
                      __LINE__ = 850;
                      var topFrame = _frames[_frames.length-1];
                      
                      __LINE__ = 851;
                      if ( ko.utils.arrayIndexOf( topFrame.distinctDependencies,subscribable ) >= 0 ){
                        __LINE__ = 852;
                        return ;
                      };
                      
                      __LINE__ = 0;
                      topFrame.distinctDependencies.push( subscribable );
                      
                      __LINE__ = 0;
                      topFrame.callback( subscribable );
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
              };
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })();
          
          __LINE__ = 858;
          var primitiveTypes =  {
                'undefined' : true,
                'boolean' : true,
                'number' : true,
                'string' : true
              };
          
          __LINE__ = 0;
          ko.observable = function ( initialValue ) {
            try {
              __LINE__ = 861;
              var _latestValue = initialValue;
              
              function observable() {
                try {
                  __LINE__ = 864;
                  if ( arguments.length>0 ){
                    __LINE__ = 868;
                    if ( ( !observable['equalityComparer'] ) || !observable['equalityComparer']( _latestValue,arguments[0] ) ){
                      __LINE__ = 0;
                      observable.valueWillMutate();
                      
                      __LINE__ = 0;
                      _latestValue = arguments[0];
                      
                      __LINE__ = 0;
                      observable.valueHasMutated();
                    };
                    __LINE__ = 873;
                    return this;
                  } else {
                    __LINE__ = 0;
                    ko.dependencyDetection.registerDependency( observable );
                    __LINE__ = 878;
                    return _latestValue;
                  };
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              __LINE__ = 0;
              ko.subscribable.call( observable );
              
              __LINE__ = 0;
              observable.valueHasMutated = function () {
                try {
                  __LINE__ = 0;
                  observable["notifySubscribers"]( _latestValue );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              observable.valueWillMutate = function () {
                try {
                  __LINE__ = 0;
                  observable["notifySubscribers"]( _latestValue,"beforeChange" );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              ko.utils.extend( observable,ko.observable['fn'] );
              
              __LINE__ = 0;
              ko.exportProperty( observable,"valueHasMutated",observable.valueHasMutated );
              
              __LINE__ = 0;
              ko.exportProperty( observable,"valueWillMutate",observable.valueWillMutate );
              __LINE__ = 889;
              return observable;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          ko.observable['fn'] =  {
            __ko_proto__ : ko.observable,
            "equalityComparer" : function valuesArePrimitiveAndEqual( a,b ) {
              try {
                __LINE__ = 896;
                var oldValueIsPrimitive = ( a === null ) || ( typeof ( a ) in primitiveTypes );
                __LINE__ = 897;
                return oldValueIsPrimitive?( a === b ) : false;
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            }
          };
          
          __LINE__ = 0;
          ko.isObservable = function ( instance ) {
            try {
              __LINE__ = 902;
              if ( ( instance === null ) || ( instance === undefined ) || ( instance.__ko_proto__ === undefined ) ){
                __LINE__ = 902;
                return false;
              };
              
              __LINE__ = 903;
              if ( instance.__ko_proto__ === ko.observable ){
                __LINE__ = 903;
                return true;
              };
              __LINE__ = 904;
              return ko.isObservable( instance.__ko_proto__ );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          ko.isWriteableObservable = function ( instance ) {
            try {
              __LINE__ = 908;
              if ( ( typeof instance == "function" ) && instance.__ko_proto__ === ko.observable ){
                __LINE__ = 909;
                return true;
              };
              
              __LINE__ = 911;
              if ( ( typeof instance == "function" ) && ( instance.__ko_proto__ === ko.dependentObservable ) && ( instance.hasWriteFunction ) ){
                __LINE__ = 912;
                return true;
              };
              __LINE__ = 914;
              return false;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.observable',ko.observable );
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.isObservable',ko.isObservable );
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.isWriteableObservable',ko.isWriteableObservable );
          
          __LINE__ = 0;
          ko.observableArray = function ( initialValues ) {
            try {
              __LINE__ = 922;
              if ( arguments.length == 0 ){
                __LINE__ = 0;
                initialValues = [];
              };
              
              __LINE__ = 926;
              if ( ( initialValues !== null ) && ( initialValues !== undefined ) && !( 'length' in initialValues ) ){
                __LINE__ = 927;
                throw new Error( "The argument passed when initializing an observable array must be an array, or null, or undefined." );
              };
              
              __LINE__ = 929;
              var result = new ko.observable( initialValues );
              
              __LINE__ = 0;
              ko.utils.extend( result,ko.observableArray['fn'] );
              
              __LINE__ = 0;
              ko.exportProperty( result,"remove",result.remove );
              
              __LINE__ = 0;
              ko.exportProperty( result,"removeAll",result.removeAll );
              
              __LINE__ = 0;
              ko.exportProperty( result,"destroy",result.destroy );
              
              __LINE__ = 0;
              ko.exportProperty( result,"destroyAll",result.destroyAll );
              
              __LINE__ = 0;
              ko.exportProperty( result,"indexOf",result.indexOf );
              
              __LINE__ = 0;
              ko.exportProperty( result,"replace",result.replace );
              __LINE__ = 939;
              return result;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          ko.observableArray['fn'] =  {
            remove : function ( valueOrPredicate ) {
              try {
                __LINE__ = 944;
                var underlyingArray = this();
                
                __LINE__ = 945;
                var removedValues = [];
                
                __LINE__ = 946;
                var predicate = typeof valueOrPredicate == "function"?valueOrPredicate : function ( value ) {
                      try {
                        __LINE__ = 946;
                        return value === valueOrPredicate;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    };
                
                __LINE__ = 947;
                for ( var i = 0;i<underlyingArray.length;i ++  ){
                  __LINE__ = 948;
                  var value = underlyingArray[i];
                  
                  __LINE__ = 949;
                  if ( predicate( value ) ){
                    __LINE__ = 950;
                    if ( removedValues.length === 0 ){
                      __LINE__ = 0;
                      this.valueWillMutate();
                    };
                    
                    __LINE__ = 0;
                    removedValues.push( value );
                    
                    __LINE__ = 0;
                    underlyingArray.splice( i,1 );
                    
                    __LINE__ = 0;
                    i -- ;
                  };
                };
                
                __LINE__ = 958;
                if ( removedValues.length ){
                  __LINE__ = 0;
                  this.valueHasMutated();
                };
                __LINE__ = 961;
                return removedValues;
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            removeAll : function ( arrayOfValues ) {
              try {
                __LINE__ = 966;
                if ( arrayOfValues === undefined ){
                  __LINE__ = 967;
                  var underlyingArray = this();
                  
                  __LINE__ = 968;
                  var allValues = underlyingArray.slice( 0 );
                  
                  __LINE__ = 0;
                  this.valueWillMutate();
                  
                  __LINE__ = 0;
                  underlyingArray.splice( 0,underlyingArray.length );
                  
                  __LINE__ = 0;
                  this.valueHasMutated();
                  __LINE__ = 972;
                  return allValues;
                };
                
                __LINE__ = 975;
                if ( !arrayOfValues ){
                  __LINE__ = 976;
                  return [];
                };
                __LINE__ = 977;
                return this.remove( function ( value ) {
                  try {
                    __LINE__ = 978;
                    return ko.utils.arrayIndexOf( arrayOfValues,value ) >= 0;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                });
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            destroy : function ( valueOrPredicate ) {
              try {
                __LINE__ = 983;
                var underlyingArray = this();
                
                __LINE__ = 984;
                var predicate = typeof valueOrPredicate == "function"?valueOrPredicate : function ( value ) {
                      try {
                        __LINE__ = 984;
                        return value === valueOrPredicate;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    };
                
                __LINE__ = 0;
                this.valueWillMutate();
                
                __LINE__ = 986;
                for ( var i = underlyingArray.length-1;i >= 0;i --  ){
                  __LINE__ = 987;
                  var value = underlyingArray[i];
                  
                  __LINE__ = 988;
                  if ( predicate( value ) ){
                    __LINE__ = 0;
                    underlyingArray[i]["_destroy"] = true;
                  };
                };
                
                __LINE__ = 0;
                this.valueHasMutated();
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            destroyAll : function ( arrayOfValues ) {
              try {
                __LINE__ = 996;
                if ( arrayOfValues === undefined ){
                  __LINE__ = 997;
                  return this.destroy( function () {
                    try {
                      __LINE__ = 997;
                      return true;
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  });
                };
                
                __LINE__ = 1000;
                if ( !arrayOfValues ){
                  __LINE__ = 1001;
                  return [];
                };
                __LINE__ = 1002;
                return this.destroy( function ( value ) {
                  try {
                    __LINE__ = 1003;
                    return ko.utils.arrayIndexOf( arrayOfValues,value ) >= 0;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                });
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            indexOf : function ( item ) {
              try {
                __LINE__ = 1008;
                var underlyingArray = this();
                __LINE__ = 1009;
                return ko.utils.arrayIndexOf( underlyingArray,item );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            replace : function ( oldItem,newItem ) {
              try {
                __LINE__ = 1013;
                var index = this.indexOf( oldItem );
                
                __LINE__ = 1014;
                if ( index >= 0 ){
                  __LINE__ = 0;
                  this.valueWillMutate();
                  
                  __LINE__ = 0;
                  this()[index] = newItem;
                  
                  __LINE__ = 0;
                  this.valueHasMutated();
                };
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            }
          };
          
          __LINE__ = 0;
          ko.utils.arrayForEach( ["pop","push","reverse","shift","sort","splice","unshift"],
          function ( methodName ) {
            try {
              __LINE__ = 0;
              ko.observableArray['fn'][methodName] = function () {
                try {
                  __LINE__ = 1025;
                  var underlyingArray = this();
                  
                  __LINE__ = 0;
                  this.valueWillMutate();
                  
                  __LINE__ = 1027;
                  var methodCallResult = underlyingArray[methodName].apply( underlyingArray,arguments );
                  
                  __LINE__ = 0;
                  this.valueHasMutated();
                  __LINE__ = 1029;
                  return methodCallResult;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          });
          
          __LINE__ = 0;
          ko.utils.arrayForEach( ["slice"],
          function ( methodName ) {
            try {
              __LINE__ = 0;
              ko.observableArray['fn'][methodName] = function () {
                try {
                  __LINE__ = 1036;
                  var underlyingArray = this();
                  __LINE__ = 1037;
                  return underlyingArray[methodName].apply( underlyingArray,arguments );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          });
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.observableArray',ko.observableArray );
          
          function prepareOptions( evaluatorFunctionOrOptions,evaluatorFunctionTarget,options ) {
            try {
              __LINE__ = 1043;
              if ( evaluatorFunctionOrOptions && typeof evaluatorFunctionOrOptions == "object" ){
                __LINE__ = 0;
                options = evaluatorFunctionOrOptions;
              } else {
                __LINE__ = 0;
                options = options || {};
                
                __LINE__ = 0;
                options["read"] = evaluatorFunctionOrOptions || options["read"];
              };
              
              __LINE__ = 1053;
              if ( typeof options["read"] != "function" ){
                __LINE__ = 1054;
                throw "Pass a function that returns the value of the dependentObservable";
              };
              __LINE__ = 1056;
              return options;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          __LINE__ = 0;
          ko.dependentObservable = function ( evaluatorFunctionOrOptions,evaluatorFunctionTarget,options ) {
            try {
              __LINE__ = 1060;
              var _latestValue,
                  _hasBeenEvaluated = false,
                  options = prepareOptions( evaluatorFunctionOrOptions,evaluatorFunctionTarget,options );
              
              __LINE__ = 1067;
              var disposeWhenNodeIsRemoved = ( typeof options["disposeWhenNodeIsRemoved"] == "object" )?options["disposeWhenNodeIsRemoved"] : null;
              
              __LINE__ = 1068;
              var disposeWhenNodeIsRemovedCallback = null;
              
              __LINE__ = 1069;
              if ( disposeWhenNodeIsRemoved ){
                __LINE__ = 0;
                disposeWhenNodeIsRemovedCallback = function () {
                  try {
                    __LINE__ = 0;
                    dependentObservable.dispose();
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
                
                __LINE__ = 0;
                ko.utils.domNodeDisposal.addDisposeCallback( disposeWhenNodeIsRemoved,disposeWhenNodeIsRemovedCallback );
                
                __LINE__ = 1072;
                var existingDisposeWhenFunction = options["disposeWhen"];
                
                __LINE__ = 0;
                options["disposeWhen"] = function () {
                  try {
                    __LINE__ = 1074;
                    return ( !ko.utils.domNodeIsAttachedToDocument( disposeWhenNodeIsRemoved ) ) || ( ( typeof existingDisposeWhenFunction == "function" ) && existingDisposeWhenFunction() );
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
              };
              
              __LINE__ = 1079;
              var _subscriptionsToDependencies = [];
              
              function disposeAllSubscriptionsToDependencies() {
                try {
                  __LINE__ = 0;
                  ko.utils.arrayForEach( _subscriptionsToDependencies,
                  function ( subscription ) {
                    try {
                      __LINE__ = 0;
                      subscription.dispose();
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  });
                  
                  __LINE__ = 0;
                  _subscriptionsToDependencies = [];
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              __LINE__ = 1087;
              var evaluationTimeoutInstance = null;
              
              function evaluatePossiblyAsync() {
                try {
                  __LINE__ = 1089;
                  var throttleEvaluationTimeout = dependentObservable['throttleEvaluation'];
                  
                  __LINE__ = 1090;
                  if ( throttleEvaluationTimeout && throttleEvaluationTimeout >= 0 ){
                    __LINE__ = 0;
                    clearTimeout( evaluationTimeoutInstance );
                    
                    __LINE__ = 0;
                    evaluationTimeoutInstance = setTimeout( evaluateImmediate,throttleEvaluationTimeout );
                  } else {
                    __LINE__ = 0;
                    evaluateImmediate();
                  };
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              function evaluateImmediate() {
                try {
                  __LINE__ = 1101;
                  if ( ( _hasBeenEvaluated ) && typeof options["disposeWhen"] == "function" ){
                    __LINE__ = 1102;
                    if ( options["disposeWhen"]() ){
                      __LINE__ = 0;
                      dependentObservable.dispose();
                      __LINE__ = 1104;
                      return ;
                    };
                  };
                  
                  try {
                    __LINE__ = 0;
                    disposeAllSubscriptionsToDependencies();
                    
                    __LINE__ = 0;
                    ko.dependencyDetection.begin( function ( subscribable ) {
                      try {
                        __LINE__ = 0;
                        _subscriptionsToDependencies.push( subscribable.subscribe( evaluatePossiblyAsync ) );
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    });
                    
                    __LINE__ = 1113;
                    var valueForThis = options["owner"] || evaluatorFunctionTarget;
                    
                    __LINE__ = 1114;
                    var newValue = options["read"].call( valueForThis );
                    
                    __LINE__ = 0;
                    dependentObservable["notifySubscribers"]( _latestValue,"beforeChange" );
                    
                    __LINE__ = 0;
                    _latestValue = newValue;
                  } finally {
                    __LINE__ = 0;
                    ko.dependencyDetection.end();
                  };
                  
                  __LINE__ = 0;
                  dependentObservable["notifySubscribers"]( _latestValue );
                  
                  __LINE__ = 0;
                  _hasBeenEvaluated = true;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              function dependentObservable() {
                try {
                  __LINE__ = 1126;
                  if ( arguments.length>0 ){
                    __LINE__ = 1127;
                    if ( typeof options["write"] === "function" ){
                      __LINE__ = 1129;
                      var valueForThis = options["owner"] || evaluatorFunctionTarget;
                      
                      __LINE__ = 0;
                      options["write"].apply( valueForThis,arguments );
                    } else {
                      __LINE__ = 1132;
                      throw "Cannot write a value to a dependentObservable unless you specify a 'write' option. If you wish to read the current value, don't pass any parameters.";
                    };
                  } else {
                    if ( !_hasBeenEvaluated ){
                      __LINE__ = 0;
                      evaluateImmediate();
                    };
                    
                    __LINE__ = 0;
                    ko.dependencyDetection.registerDependency( dependentObservable );
                    __LINE__ = 1139;
                    return _latestValue;
                  };
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              __LINE__ = 0;
              dependentObservable.getDependenciesCount = function () {
                try {
                  __LINE__ = 1142;
                  return _subscriptionsToDependencies.length;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              dependentObservable.hasWriteFunction = typeof options["write"] === "function";
              
              __LINE__ = 0;
              dependentObservable.dispose = function () {
                try {
                  __LINE__ = 1145;
                  if ( disposeWhenNodeIsRemoved ){
                    __LINE__ = 0;
                    ko.utils.domNodeDisposal.removeDisposeCallback( disposeWhenNodeIsRemoved,disposeWhenNodeIsRemovedCallback );
                  };
                  
                  __LINE__ = 0;
                  disposeAllSubscriptionsToDependencies();
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              ko.subscribable.call( dependentObservable );
              
              __LINE__ = 0;
              ko.utils.extend( dependentObservable,ko.dependentObservable['fn'] );
              
              __LINE__ = 1153;
              if ( options['deferEvaluation'] !== true ){
                __LINE__ = 0;
                evaluateImmediate();
              };
              
              __LINE__ = 0;
              ko.exportProperty( dependentObservable,'dispose',dependentObservable.dispose );
              
              __LINE__ = 0;
              ko.exportProperty( dependentObservable,'getDependenciesCount',dependentObservable.getDependenciesCount );
              __LINE__ = 1159;
              return dependentObservable;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          ko.dependentObservable['fn'] =  {
            __ko_proto__ : ko.dependentObservable
          };
          
          __LINE__ = 0;
          ko.dependentObservable.__ko_proto__ = ko.observable;
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.dependentObservable',ko.dependentObservable );
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.computed',ko.dependentObservable );
          
          __LINE__ = 0;
          ( function () {
            try {
              __LINE__ = 1171;
              var maxNestedObservableDepth = 10;
              
              __LINE__ = 0;
              ko.toJS = function ( rootObject ) {
                try {
                  __LINE__ = 1174;
                  if ( arguments.length == 0 ){
                    __LINE__ = 1175;
                    throw new Error( "When calling ko.toJS, pass the object you want to convert." );
                  };
                  __LINE__ = 1178;
                  return mapJsObjectGraph( rootObject,
                  function ( valueToMap ) {
                    try {
                      __LINE__ = 1180;
                      for ( var i = 0;ko.isObservable( valueToMap ) && ( i<maxNestedObservableDepth );i ++  ){
                        __LINE__ = 0;
                        valueToMap = valueToMap();
                      };
                      __LINE__ = 1182;
                      return valueToMap;
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  });
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              ko.toJSON = function ( rootObject ) {
                try {
                  __LINE__ = 1187;
                  var plainJavaScriptObject = ko.toJS( rootObject );
                  __LINE__ = 1188;
                  return ko.utils.stringifyJson( plainJavaScriptObject );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              function mapJsObjectGraph( rootObject,mapInputCallback,visitedObjects ) {
                try {
                  __LINE__ = 0;
                  visitedObjects = visitedObjects || new objectLookup();
                  
                  __LINE__ = 0;
                  rootObject = mapInputCallback( rootObject );
                  
                  __LINE__ = 1195;
                  var canHaveProperties = ( typeof rootObject == "object" ) && ( rootObject !== null ) && ( rootObject !== undefined ) && ( !( rootObject instanceof Date ) );
                  
                  __LINE__ = 1196;
                  if ( !canHaveProperties ){
                    __LINE__ = 1197;
                    return rootObject;
                  };
                  
                  __LINE__ = 1199;
                  var outputProperties = rootObject instanceof Array?[] : {};
                  
                  __LINE__ = 0;
                  visitedObjects.save( rootObject,outputProperties );
                  
                  __LINE__ = 0;
                  visitPropertiesOrArrayEntries( rootObject,
                  function ( indexer ) {
                    try {
                      __LINE__ = 1203;
                      var propertyValue = mapInputCallback( rootObject[indexer] );
                      
                      __LINE__ = 0;
                      switch ( typeof propertyValue ) {
                        case "boolean" :
                        case "number" :
                        case "string" :
                        case "function" :
                          
                          __LINE__ = 0;
                          outputProperties[indexer] = propertyValue;
                          __LINE__ = 1211;
                          break;
                        case "object" :
                        case "undefined" :
                          
                          __LINE__ = 1214;
                          var previouslyMappedValue = visitedObjects.get( propertyValue );
                          
                          __LINE__ = 0;
                          outputProperties[indexer] = ( previouslyMappedValue !== undefined )?previouslyMappedValue : mapJsObjectGraph( propertyValue,mapInputCallback,visitedObjects );
                          __LINE__ = 1218;
                          break;
                          
                      };
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  });
                  __LINE__ = 1222;
                  return outputProperties;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              function visitPropertiesOrArrayEntries( rootObject,visitorCallback ) {
                try {
                  __LINE__ = 1226;
                  if ( rootObject instanceof Array ){
                    __LINE__ = 1227;
                    for ( var i = 0;i<rootObject.length;i ++  ){
                      __LINE__ = 0;
                      visitorCallback( i );
                    };
                  } else {
                    __LINE__ = 1230;
                    for ( var propertyName in rootObject ){
                      __LINE__ = 0;
                      visitorCallback( propertyName );
                    };
                  };
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              function objectLookup() {
                try {
                  __LINE__ = 1236;
                  var keys = [];
                  
                  __LINE__ = 1237;
                  var values = [];
                  
                  __LINE__ = 0;
                  this.save = function ( key,value ) {
                    try {
                      __LINE__ = 1239;
                      var existingIndex = ko.utils.arrayIndexOf( keys,key );
                      
                      __LINE__ = 1240;
                      if ( existingIndex >= 0 ){
                        __LINE__ = 0;
                        values[existingIndex] = value;
                      } else {
                        __LINE__ = 0;
                        keys.push( key );
                        
                        __LINE__ = 0;
                        values.push( value );
                      };
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  };
                  
                  __LINE__ = 0;
                  this.get = function ( key ) {
                    try {
                      __LINE__ = 1248;
                      var existingIndex = ko.utils.arrayIndexOf( keys,key );
                      __LINE__ = 1249;
                      return ( existingIndex >= 0 )?values[existingIndex] : undefined;
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  };
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })();
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.toJS',ko.toJS );
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.toJSON',ko.toJSON );
          
          __LINE__ = 0;
          ( function () {
            try {
              __LINE__ = 1256;
              var hasDomDataExpandoProperty = '__ko__hasDomDataOptionValue__';
              
              __LINE__ = 0;
              ko.selectExtensions =  {
                readValue : function ( element ) {
                  try {
                    __LINE__ = 1263;
                    if ( element.tagName == 'OPTION' ){
                      __LINE__ = 1264;
                      if ( element[hasDomDataExpandoProperty] === true ){
                        __LINE__ = 1265;
                        return ko.utils.domData.get( element,ko.bindingHandlers.options.optionValueDomDataKey );
                      };
                      __LINE__ = 1266;
                      return element.getAttribute( "value" );
                    } else if ( element.tagName == 'SELECT' ){
                      __LINE__ = 1268;
                      return element.selectedIndex >= 0?ko.selectExtensions.readValue( element.options[element.selectedIndex] ) : undefined;
                    } else {
                      __LINE__ = 1270;
                      return element.value;
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                writeValue : function ( element,value ) {
                  try {
                    __LINE__ = 1274;
                    if ( element.tagName == 'OPTION' ){
                      __LINE__ = 0;
                      switch ( typeof value ) {
                        case "string" :
                          
                          __LINE__ = 0;
                          ko.utils.domData.set( element,ko.bindingHandlers.options.optionValueDomDataKey,undefined );
                          
                          __LINE__ = 1278;
                          if ( hasDomDataExpandoProperty in element ){
                            __LINE__ = 0;
                            delete element[hasDomDataExpandoProperty];
                          };
                          
                          __LINE__ = 0;
                          element.value = value;
                          __LINE__ = 1282;
                          break;
                        default :
                          
                          __LINE__ = 0;
                          ko.utils.domData.set( element,ko.bindingHandlers.options.optionValueDomDataKey,value );
                          
                          __LINE__ = 0;
                          element[hasDomDataExpandoProperty] = true;
                          
                          __LINE__ = 0;
                          element.value = typeof value === "number"?value : "";
                          __LINE__ = 1290;
                          break;
                          
                      };
                    } else if ( element.tagName == 'SELECT' ){
                      __LINE__ = 1293;
                      for ( var i = element.options.length-1;i >= 0;i --  ){
                        if ( ko.selectExtensions.readValue( element.options[i] ) == value ){
                          __LINE__ = 0;
                          element.selectedIndex = i;
                          __LINE__ = 1296;
                          break;
                        };
                      };
                    } else {
                      if ( ( value === null ) || ( value === undefined ) ){
                        __LINE__ = 0;
                        value = "";
                      };
                      
                      __LINE__ = 0;
                      element.value = value;
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
              };
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })();
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.selectExtensions',ko.selectExtensions );
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.selectExtensions.readValue',ko.selectExtensions.readValue );
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.selectExtensions.writeValue',ko.selectExtensions.writeValue );
          
          __LINE__ = 0;
          ko.jsonExpressionRewriting = ( function () {
            try {
              __LINE__ = 1313;
              var restoreCapturedTokensRegex = /\@ko_token_(\d+)\@/g;
              
              __LINE__ = 1314;
              var javaScriptAssignmentTarget = /^[\_$a-z][\_$a-z0-9]*(\[.*?\])*(\.[\_$a-z][\_$a-z0-9]*(\[.*?\])*)*$/i;
              
              __LINE__ = 1315;
              var javaScriptReservedWords = ["true","false"];
              
              function restoreTokens( string,tokens ) {
                try {
                  __LINE__ = 1318;
                  var prevValue = null;
                  
                  __LINE__ = 1319;
                  while ( string != prevValue ){
                    __LINE__ = 0;
                    prevValue = string;
                    
                    __LINE__ = 0;
                    string = string.replace( restoreCapturedTokensRegex,
                    function ( match,tokenIndex ) {
                      try {
                        __LINE__ = 1322;
                        return tokens[tokenIndex];
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    });
                  };
                  __LINE__ = 1325;
                  return string;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              function isWriteableValue( expression ) {
                try {
                  __LINE__ = 1329;
                  if ( ko.utils.arrayIndexOf( javaScriptReservedWords,ko.utils.stringTrim( expression ).toLowerCase() ) >= 0 ){
                    __LINE__ = 1330;
                    return false;
                  };
                  __LINE__ = 1331;
                  return expression.match( javaScriptAssignmentTarget ) !== null;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              function ensureQuoted( key ) {
                try {
                  __LINE__ = 1335;
                  var trimmedKey = ko.utils.stringTrim( key );
                  
                  __LINE__ = 0;
                  switch ( trimmedKey.length && trimmedKey.charAt( 0 ) ) {
                    case "'" :
                    case '"' :
                      __LINE__ = 1339;
                      return key;
                    default :
                      __LINE__ = 1341;
                      return "'"+trimmedKey+"'";
                      
                  };
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }__LINE__ = 1345;
              return  {
                bindingRewriteValidators : [],
                parseObjectLiteral : function ( objectLiteralString ) {
                  try {
                    __LINE__ = 1352;
                    var str = ko.utils.stringTrim( objectLiteralString );
                    
                    __LINE__ = 1353;
                    if ( str.length<3 ){
                      __LINE__ = 1354;
                      return [];
                    };
                    
                    __LINE__ = 1355;
                    if ( str.charAt( 0 ) === "{" ){
                      __LINE__ = 0;
                      str = str.substring( 1,str.length-1 );
                    };
                    
                    __LINE__ = 1359;
                    var tokens = [];
                    
                    __LINE__ = 1360;
                    var tokenStart = null,
                        tokenEndChar;
                    
                    __LINE__ = 1361;
                    for ( var position = 0;position<str.length;position ++  ){
                      __LINE__ = 1362;
                      var c = str.charAt( position );
                      
                      __LINE__ = 1363;
                      if ( tokenStart === null ){
                        __LINE__ = 0;
                        switch ( c ) {
                          case '"' :
                          case "'" :
                          case "/" :
                            
                            __LINE__ = 0;
                            tokenStart = position;
                            
                            __LINE__ = 0;
                            tokenEndChar = c;
                            __LINE__ = 1370;
                            break;
                            
                        };
                      } else if ( ( c == tokenEndChar ) && ( str.charAt( position-1 ) !== "\\" ) ){
                        __LINE__ = 1373;
                        var token = str.substring( tokenStart,position+1 );
                        
                        __LINE__ = 0;
                        tokens.push( token );
                        
                        __LINE__ = 1375;
                        var replacement = "@ko_token_"+( tokens.length-1 )+"@";
                        
                        __LINE__ = 0;
                        str = str.substring( 0,tokenStart )+replacement+str.substring( position+1 );
                        
                        __LINE__ = 0;
                        position -= ( token.length-replacement.length );
                        
                        __LINE__ = 0;
                        tokenStart = null;
                      };
                    };
                    
                    __LINE__ = 0;
                    tokenStart = null;
                    
                    __LINE__ = 0;
                    tokenEndChar = null;
                    
                    __LINE__ = 1385;
                    var tokenDepth = 0,
                        tokenStartChar = null;
                    
                    __LINE__ = 1386;
                    for ( var position = 0;position<str.length;position ++  ){
                      __LINE__ = 1387;
                      var c = str.charAt( position );
                      
                      __LINE__ = 1388;
                      if ( tokenStart === null ){
                        __LINE__ = 0;
                        switch ( c ) {
                          case "{" :
                            
                            __LINE__ = 0;
                            tokenStart = position;
                            
                            __LINE__ = 0;
                            tokenStartChar = c;
                            
                            __LINE__ = 0;
                            tokenEndChar = "}";
                            __LINE__ = 1392;
                            break;
                          case "(" :
                            
                            __LINE__ = 0;
                            tokenStart = position;
                            
                            __LINE__ = 0;
                            tokenStartChar = c;
                            
                            __LINE__ = 0;
                            tokenEndChar = ")";
                            __LINE__ = 1395;
                            break;
                          case "[" :
                            
                            __LINE__ = 0;
                            tokenStart = position;
                            
                            __LINE__ = 0;
                            tokenStartChar = c;
                            
                            __LINE__ = 0;
                            tokenEndChar = "]";
                            __LINE__ = 1398;
                            break;
                            
                        };
                      };
                      
                      __LINE__ = 1402;
                      if ( c === tokenStartChar ){
                        __LINE__ = 0;
                        tokenDepth ++ ;
                      } else if ( c === tokenEndChar ){
                        __LINE__ = 0;
                        tokenDepth -- ;
                        if ( tokenDepth === 0 ){
                          __LINE__ = 1407;
                          var token = str.substring( tokenStart,position+1 );
                          
                          __LINE__ = 0;
                          tokens.push( token );
                          
                          __LINE__ = 1409;
                          var replacement = "@ko_token_"+( tokens.length-1 )+"@";
                          
                          __LINE__ = 0;
                          str = str.substring( 0,tokenStart )+replacement+str.substring( position+1 );
                          
                          __LINE__ = 0;
                          position -= ( token.length-replacement.length );
                          
                          __LINE__ = 0;
                          tokenStart = null;
                        };
                      };
                    };
                    
                    __LINE__ = 1418;
                    var result = [];
                    
                    __LINE__ = 1419;
                    var keyValuePairs = str.split( "," );
                    
                    __LINE__ = 1420;
                    for ( var i = 0,j = keyValuePairs.length;i<j;i ++  ){
                      __LINE__ = 1421;
                      var pair = keyValuePairs[i];
                      
                      __LINE__ = 1422;
                      var colonPos = pair.indexOf( ":" );
                      
                      __LINE__ = 1423;
                      if ( ( colonPos>0 ) && ( colonPos<pair.length-1 ) ){
                        __LINE__ = 1424;
                        var key = pair.substring( 0,colonPos );
                        
                        __LINE__ = 1425;
                        var value = pair.substring( colonPos+1 );
                        
                        __LINE__ = 0;
                        result.push(  {
                          'key' : restoreTokens( key,tokens ),
                          'value' : restoreTokens( value,tokens )
                        });
                      } else {
                        __LINE__ = 0;
                        result.push(  {
                          'unknown' : restoreTokens( pair,tokens )
                        });
                      };
                    };
                    __LINE__ = 1431;
                    return result;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                insertPropertyAccessorsIntoJson : function ( objectLiteralStringOrKeyValueArray ) {
                  try {
                    __LINE__ = 1435;
                    var keyValueArray = typeof objectLiteralStringOrKeyValueArray === "string"?ko.jsonExpressionRewriting.parseObjectLiteral( objectLiteralStringOrKeyValueArray ) : objectLiteralStringOrKeyValueArray;
                    
                    __LINE__ = 1438;
                    var resultStrings = [],
                        propertyAccessorResultStrings = [];
                    
                    __LINE__ = 1440;
                    var keyValueEntry;
                    
                    __LINE__ = 1441;
                    for ( var i = 0;keyValueEntry = keyValueArray[i];i ++  ){
                      __LINE__ = 1442;
                      if ( resultStrings.length>0 ){
                        __LINE__ = 0;
                        resultStrings.push( "," );
                      };
                      
                      __LINE__ = 1445;
                      if ( keyValueEntry['key'] ){
                        __LINE__ = 1446;
                        var quotedKey = ensureQuoted( keyValueEntry['key'] ),
                            val = keyValueEntry['value'];
                        
                        __LINE__ = 0;
                        resultStrings.push( quotedKey );
                        
                        __LINE__ = 0;
                        resultStrings.push( ":" );
                        
                        __LINE__ = 0;
                        resultStrings.push( val );
                        
                        __LINE__ = 1451;
                        if ( isWriteableValue( ko.utils.stringTrim( val ) ) ){
                          __LINE__ = 1452;
                          if ( propertyAccessorResultStrings.length>0 ){
                            __LINE__ = 0;
                            propertyAccessorResultStrings.push( ", " );
                          };
                          
                          __LINE__ = 0;
                          propertyAccessorResultStrings.push( quotedKey+" : function(__ko_value) { "+val+" = __ko_value; }" );
                        };
                      } else if ( keyValueEntry['unknown'] ){
                        __LINE__ = 0;
                        resultStrings.push( keyValueEntry['unknown'] );
                      };
                    };
                    
                    __LINE__ = 1461;
                    var combinedResult = resultStrings.join( "" );
                    
                    __LINE__ = 1462;
                    if ( propertyAccessorResultStrings.length>0 ){
                      __LINE__ = 1463;
                      var allPropertyAccessors = propertyAccessorResultStrings.join( "" );
                      
                      __LINE__ = 0;
                      combinedResult = combinedResult+", '_ko_property_writers' : { "+allPropertyAccessors+" } ";
                    };
                    __LINE__ = 1467;
                    return combinedResult;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                keyValueArrayContainsKey : function ( keyValueArray,key ) {
                  try {
                    __LINE__ = 1471;
                    for ( var i = 0;i<keyValueArray.length;i ++  ){
                      __LINE__ = 1472;
                      if ( ko.utils.stringTrim( keyValueArray[i]['key'] ) == key ){
                        __LINE__ = 1473;
                        return true;
                      };
                    };
                    __LINE__ = 1474;
                    return false;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
              };
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })();
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.jsonExpressionRewriting',ko.jsonExpressionRewriting );
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.jsonExpressionRewriting.bindingRewriteValidators',ko.jsonExpressionRewriting.bindingRewriteValidators );
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.jsonExpressionRewriting.parseObjectLiteral',ko.jsonExpressionRewriting.parseObjectLiteral );
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.jsonExpressionRewriting.insertPropertyAccessorsIntoJson',ko.jsonExpressionRewriting.insertPropertyAccessorsIntoJson );
          
          __LINE__ = 0;
          ( function () {
            try {
              __LINE__ = 1495;
              var commentNodesHaveTextProperty = document.createComment( "test" ).text === "<!--test-->";
              
              __LINE__ = 1497;
              var startCommentRegex = commentNodesHaveTextProperty?/^<!--\s*ko\s+(.*\:.*)\s*-->$/ : /^\s*ko\s+(.*\:.*)\s*$/;
              
              __LINE__ = 1498;
              var endCommentRegex = commentNodesHaveTextProperty?/^<!--\s*\/ko\s*-->$/ : /^\s*\/ko\s*$/;
              
              __LINE__ = 1499;
              var htmlTagsWithOptionallyClosingChildren =  {
                    'ul' : true,
                    'ol' : true
                  };
              
              function isStartComment( node ) {
                try {
                  __LINE__ = 1502;
                  return ( node.nodeType == 8 ) && ( commentNodesHaveTextProperty?node.text : node.nodeValue ).match( startCommentRegex );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              function isEndComment( node ) {
                try {
                  __LINE__ = 1506;
                  return ( node.nodeType == 8 ) && ( commentNodesHaveTextProperty?node.text : node.nodeValue ).match( endCommentRegex );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              function getVirtualChildren( startComment,allowUnbalanced ) {
                try {
                  __LINE__ = 1510;
                  var currentNode = startComment;
                  
                  __LINE__ = 1511;
                  var depth = 1;
                  
                  __LINE__ = 1512;
                  var children = [];
                  
                  __LINE__ = 1513;
                  while ( currentNode = currentNode.nextSibling ){
                    __LINE__ = 1514;
                    if ( isEndComment( currentNode ) ){
                      __LINE__ = 0;
                      depth -- ;
                      
                      __LINE__ = 1516;
                      if ( depth === 0 ){
                        __LINE__ = 1517;
                        return children;
                      };
                    };
                    
                    __LINE__ = 0;
                    children.push( currentNode );
                    
                    __LINE__ = 1522;
                    if ( isStartComment( currentNode ) ){
                      __LINE__ = 0;
                      depth ++ ;
                    };
                  };
                  
                  __LINE__ = 1525;
                  if ( !allowUnbalanced ){
                    __LINE__ = 1526;
                    throw new Error( "Cannot find closing comment tag to match: "+startComment.nodeValue );
                  };
                  __LINE__ = 1527;
                  return null;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              function getMatchingEndComment( startComment,allowUnbalanced ) {
                try {
                  __LINE__ = 1531;
                  var allVirtualChildren = getVirtualChildren( startComment,allowUnbalanced );
                  
                  __LINE__ = 1532;
                  if ( allVirtualChildren ){
                    __LINE__ = 1533;
                    if ( allVirtualChildren.length>0 ){
                      __LINE__ = 1534;
                      return allVirtualChildren[allVirtualChildren.length-1].nextSibling;
                    };
                    __LINE__ = 1535;
                    return startComment.nextSibling;
                  } else {
                    __LINE__ = 1537;
                    return null;
                  };
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              function nodeArrayToText( nodeArray,cleanNodes ) {
                try {
                  __LINE__ = 1541;
                  var texts = [];
                  
                  __LINE__ = 1542;
                  for ( var i = 0,j = nodeArray.length;i<j;i ++  ){
                    __LINE__ = 1543;
                    if ( cleanNodes ){
                      __LINE__ = 0;
                      ko.utils.domNodeDisposal.cleanNode( nodeArray[i] );
                    };
                    
                    __LINE__ = 0;
                    texts.push( ko.utils.outerHTML( nodeArray[i] ) );
                  };
                  __LINE__ = 1547;
                  return String.prototype.concat.apply( "",texts );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              function getUnbalancedChildTags( node ) {
                try {
                  __LINE__ = 1553;
                  var childNode = node.firstChild,
                      captureRemaining = null;
                  
                  __LINE__ = 1554;
                  if ( childNode ){
                    __LINE__ = 1555;
                    do {
                      __LINE__ = 1556;
                      if ( captureRemaining ){
                        __LINE__ = 0;
                        captureRemaining.push( childNode );
                      } else if ( isStartComment( childNode ) ){
                        __LINE__ = 1559;
                        var matchingEndComment = getMatchingEndComment( childNode,true );
                        if ( matchingEndComment ){
                          __LINE__ = 0;
                          childNode = matchingEndComment;
                        } else {
                          __LINE__ = 0;
                          captureRemaining = [childNode];
                        };
                      } else if ( isEndComment( childNode ) ){
                        __LINE__ = 0;
                        captureRemaining = [childNode];
                      };
                    }while ( childNode = childNode.nextSibling );
                  };
                  __LINE__ = 1569;
                  return captureRemaining;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              __LINE__ = 0;
              ko.virtualElements =  {
                allowedBindings : {},
                childNodes : function ( node ) {
                  try {
                    __LINE__ = 1576;
                    return isStartComment( node )?getVirtualChildren( node ) : node.childNodes;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                emptyNode : function ( node ) {
                  try {
                    __LINE__ = 1580;
                    if ( !isStartComment( node ) ){
                      __LINE__ = 0;
                      ko.utils.emptyDomNode( node );
                    } else {
                      __LINE__ = 1583;
                      var virtualChildren = ko.virtualElements.childNodes( node );
                      
                      __LINE__ = 1584;
                      for ( var i = 0,j = virtualChildren.length;i<j;i ++  ){
                        __LINE__ = 0;
                        ko.removeNode( virtualChildren[i] );
                      };
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                setDomNodeChildren : function ( node,childNodes ) {
                  try {
                    __LINE__ = 1590;
                    if ( !isStartComment( node ) ){
                      __LINE__ = 0;
                      ko.utils.setDomNodeChildren( node,childNodes );
                    } else {
                      __LINE__ = 0;
                      ko.virtualElements.emptyNode( node );
                      
                      __LINE__ = 1594;
                      var endCommentNode = node.nextSibling;
                      
                      __LINE__ = 1595;
                      for ( var i = 0,j = childNodes.length;i<j;i ++  ){
                        __LINE__ = 0;
                        endCommentNode.parentNode.insertBefore( childNodes[i],endCommentNode );
                      };
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                prepend : function ( containerNode,nodeToPrepend ) {
                  try {
                    __LINE__ = 1601;
                    if ( !isStartComment( containerNode ) ){
                      __LINE__ = 1602;
                      if ( containerNode.firstChild ){
                        __LINE__ = 0;
                        containerNode.insertBefore( nodeToPrepend,containerNode.firstChild );
                      } else {
                        __LINE__ = 0;
                        containerNode.appendChild( nodeToPrepend );
                      };
                    } else {
                      __LINE__ = 0;
                      containerNode.parentNode.insertBefore( nodeToPrepend,containerNode.nextSibling );
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                insertAfter : function ( containerNode,nodeToInsert,insertAfterNode ) {
                  try {
                    __LINE__ = 1613;
                    if ( !isStartComment( containerNode ) ){
                      __LINE__ = 1615;
                      if ( insertAfterNode.nextSibling ){
                        __LINE__ = 0;
                        containerNode.insertBefore( nodeToInsert,insertAfterNode.nextSibling );
                      } else {
                        __LINE__ = 0;
                        containerNode.appendChild( nodeToInsert );
                      };
                    } else {
                      __LINE__ = 0;
                      containerNode.parentNode.insertBefore( nodeToInsert,insertAfterNode.nextSibling );
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                nextSibling : function ( node ) {
                  try {
                    __LINE__ = 1626;
                    if ( !isStartComment( node ) ){
                      __LINE__ = 1627;
                      if ( node.nextSibling && isEndComment( node.nextSibling ) ){
                        __LINE__ = 1628;
                        return undefined;
                      };
                      __LINE__ = 1629;
                      return node.nextSibling;
                    } else {
                      __LINE__ = 1631;
                      return getMatchingEndComment( node ).nextSibling;
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                virtualNodeBindingValue : function ( node ) {
                  try {
                    __LINE__ = 1636;
                    var regexMatch = isStartComment( node );
                    __LINE__ = 1637;
                    return regexMatch?regexMatch[1] : null;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                extractAnonymousTemplateIfVirtualElement : function ( node ) {
                  try {
                    __LINE__ = 1641;
                    if ( ko.virtualElements.virtualNodeBindingValue( node ) ){
                      __LINE__ = 1643;
                      var virtualChildren = ko.virtualElements.childNodes( node );
                      
                      __LINE__ = 1644;
                      var anonymousTemplateText = nodeArrayToText( virtualChildren,true );
                      
                      __LINE__ = 0;
                      ko.virtualElements.emptyNode( node );
                      
                      __LINE__ = 0;
                      new ko.templateSources.anonymousTemplate( node ).text( anonymousTemplateText );
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                normaliseVirtualElementDomStructure : function ( elementVerified ) {
                  try {
                    __LINE__ = 1654;
                    if ( !htmlTagsWithOptionallyClosingChildren[elementVerified.tagName.toLowerCase()] ){
                      __LINE__ = 1655;
                      return ;
                    };
                    
                    __LINE__ = 1659;
                    var childNode = elementVerified.firstChild;
                    
                    __LINE__ = 1660;
                    if ( childNode ){
                      __LINE__ = 1661;
                      do {
                        __LINE__ = 1662;
                        if ( childNode.nodeType === 1 ){
                          __LINE__ = 1663;
                          var unbalancedTags = getUnbalancedChildTags( childNode );
                          
                          __LINE__ = 1664;
                          if ( unbalancedTags ){
                            __LINE__ = 1666;
                            var nodeToInsertBefore = childNode.nextSibling;
                            
                            __LINE__ = 1667;
                            for ( var i = 0;i<unbalancedTags.length;i ++  ){
                              __LINE__ = 1668;
                              if ( nodeToInsertBefore ){
                                __LINE__ = 0;
                                elementVerified.insertBefore( unbalancedTags[i],nodeToInsertBefore );
                              } else {
                                __LINE__ = 0;
                                elementVerified.appendChild( unbalancedTags[i] );
                              };
                            };
                          };
                        };
                      }while ( childNode = childNode.nextSibling );
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
              };
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })();
          
          __LINE__ = 0;
          ( function () {
            try {
              __LINE__ = 1681;
              var defaultBindingAttributeName = "data-bind";
              
              __LINE__ = 0;
              ko.bindingProvider = function (){};
              
              __LINE__ = 0;
              ko.utils.extend( ko.bindingProvider.prototype, {
                'nodeHasBindings' : function ( node ) {
                  try {
                    __LINE__ = 0;
                    switch ( node.nodeType ) {
                      case 1 :
                        __LINE__ = 1688;
                        return node.getAttribute( defaultBindingAttributeName ) != null;
                      case 8 :
                        __LINE__ = 1689;
                        return ko.virtualElements.virtualNodeBindingValue( node ) != null;
                      default :
                        __LINE__ = 1690;
                        return false;
                        
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                'getBindings' : function ( node,bindingContext ) {
                  try {
                    __LINE__ = 1695;
                    var bindingsString = this['getBindingsString']( node,bindingContext );
                    __LINE__ = 1696;
                    return bindingsString?this['parseBindingsString']( bindingsString,bindingContext ) : null;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                'getBindingsString' : function ( node,bindingContext ) {
                  try {
                    __LINE__ = 0;
                    switch ( node.nodeType ) {
                      case 1 :
                        __LINE__ = 1703;
                        return node.getAttribute( defaultBindingAttributeName );
                      case 8 :
                        __LINE__ = 1704;
                        return ko.virtualElements.virtualNodeBindingValue( node );
                      default :
                        __LINE__ = 1705;
                        return null;
                        
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                'parseBindingsString' : function ( bindingsString,bindingContext ) {
                  try {
                    try {
                      __LINE__ = 1713;
                      var viewModel = bindingContext['$data'];
                      
                      __LINE__ = 1714;
                      var rewrittenBindings = " { "+ko.jsonExpressionRewriting.insertPropertyAccessorsIntoJson( bindingsString )+" } ";
                      __LINE__ = 1715;
                      return ko.utils.evalWithinScope( rewrittenBindings,viewModel === null?window : viewModel,bindingContext );
                    } catch( ex ){
                      __LINE__ = 1717;
                      throw new Error( "Unable to parse bindings.\nMessage: "+ex+";\nBindings value: "+bindingsString );
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
              });
              
              __LINE__ = 0;
              ko.bindingProvider['instance'] = new ko.bindingProvider();
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })();
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.bindingProvider',ko.bindingProvider );
          
          __LINE__ = 0;
          ( function () {
            try {
              __LINE__ = 0;
              ko.bindingHandlers = {};
              
              __LINE__ = 0;
              ko.bindingContext = function ( dataItem,parentBindingContext ) {
                try {
                  __LINE__ = 0;
                  this['$data'] = dataItem;
                  
                  __LINE__ = 1730;
                  if ( parentBindingContext ){
                    __LINE__ = 0;
                    this['$parent'] = parentBindingContext['$data'];
                    
                    __LINE__ = 0;
                    this['$parents'] = ( parentBindingContext['$parents'] || [] ).slice( 0 );
                    
                    __LINE__ = 0;
                    this['$parents'].unshift( this['$parent'] );
                    
                    __LINE__ = 0;
                    this['$root'] = parentBindingContext['$root'];
                  } else {
                    __LINE__ = 0;
                    this['$parents'] = [];
                    
                    __LINE__ = 0;
                    this['$root'] = dataItem;
                  };
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              ko.bindingContext.prototype['createChildContext'] = function ( dataItem ) {
                try {
                  __LINE__ = 1741;
                  return new ko.bindingContext( dataItem,this );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              function validateThatBindingIsAllowedForVirtualElements( bindingName ) {
                try {
                  __LINE__ = 1745;
                  var validator = ko.virtualElements.allowedBindings[bindingName];
                  
                  __LINE__ = 1746;
                  if ( !validator ){
                    __LINE__ = 1747;
                    throw new Error( "The binding '"+bindingName+"' cannot be used with virtual elements" );
                  };
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              function applyBindingsToDescendantsInternal( viewModel,elementVerified ) {
                try {
                  __LINE__ = 1751;
                  var currentChild,
                      nextInQueue = elementVerified.childNodes[0];
                  
                  __LINE__ = 1752;
                  while ( currentChild = nextInQueue ){
                    __LINE__ = 0;
                    nextInQueue = ko.virtualElements.nextSibling( currentChild );
                    
                    __LINE__ = 0;
                    applyBindingsToNodeAndDescendantsInternal( viewModel,currentChild,false );
                  };
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              function applyBindingsToNodeAndDescendantsInternal( viewModel,nodeVerified,isRootNodeForBindingContext ) {
                try {
                  __LINE__ = 1760;
                  var shouldBindDescendants = true;
                  
                  __LINE__ = 1766;
                  var isElement = ( nodeVerified.nodeType == 1 );
                  
                  __LINE__ = 1767;
                  if ( isElement ){
                    __LINE__ = 0;
                    ko.virtualElements.normaliseVirtualElementDomStructure( nodeVerified );
                  };
                  
                  __LINE__ = 1770;
                  var shouldApplyBindings = ( isElement && isRootNodeForBindingContext ) || ko.bindingProvider['instance']['nodeHasBindings']( nodeVerified );
                  
                  __LINE__ = 1772;
                  if ( shouldApplyBindings ){
                    __LINE__ = 0;
                    shouldBindDescendants = applyBindingsToNodeInternal( nodeVerified,null,viewModel,isRootNodeForBindingContext ).shouldBindDescendants;
                  };
                  
                  __LINE__ = 1775;
                  if ( isElement && shouldBindDescendants ){
                    __LINE__ = 0;
                    applyBindingsToDescendantsInternal( viewModel,nodeVerified );
                  };
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              function applyBindingsToNodeInternal( node,bindings,viewModelOrBindingContext,isRootNodeForBindingContext ) {
                try {
                  __LINE__ = 1781;
                  var initPhase = 0;
                  
                  __LINE__ = 0;
                  ko.virtualElements.extractAnonymousTemplateIfVirtualElement( node );
                  
                  __LINE__ = 1792;
                  var parsedBindings;
                  
                  function makeValueAccessor( bindingKey ) {
                    try {
                      __LINE__ = 1794;
                      return function () {
                        try {
                          __LINE__ = 1794;
                          return parsedBindings[bindingKey];
                        } catch( e ){
                          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      };
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  }
                  function parsedBindingsAccessor() {
                    try {
                      __LINE__ = 1797;
                      return parsedBindings;
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  }
                  __LINE__ = 1800;
                  var bindingHandlerThatControlsDescendantBindings;
                  
                  __LINE__ = 0;
                  new ko.dependentObservable( function () {
                    try {
                      __LINE__ = 1804;
                      var bindingContextInstance = viewModelOrBindingContext && ( viewModelOrBindingContext instanceof ko.bindingContext )?viewModelOrBindingContext : new ko.bindingContext( ko.utils.unwrapObservable( viewModelOrBindingContext ) );
                      
                      __LINE__ = 1807;
                      var viewModel = bindingContextInstance['$data'];
                      
                      __LINE__ = 1811;
                      if ( isRootNodeForBindingContext ){
                        __LINE__ = 0;
                        ko.storedBindingContextForNode( node,bindingContextInstance );
                      };
                      
                      __LINE__ = 1815;
                      var evaluatedBindings = ( typeof bindings == "function" )?bindings() : bindings;
                      
                      __LINE__ = 0;
                      parsedBindings = evaluatedBindings || ko.bindingProvider['instance']['getBindings']( node,bindingContextInstance );
                      
                      __LINE__ = 1818;
                      if ( parsedBindings ){
                        __LINE__ = 1820;
                        if ( initPhase === 0 ){
                          __LINE__ = 0;
                          initPhase = 1;
                          
                          __LINE__ = 1822;
                          for ( var bindingKey in parsedBindings ){
                            __LINE__ = 1823;
                            var binding = ko.bindingHandlers[bindingKey];
                            
                            __LINE__ = 1824;
                            if ( binding && node.nodeType === 8 ){
                              __LINE__ = 0;
                              validateThatBindingIsAllowedForVirtualElements( bindingKey );
                            };
                            
                            __LINE__ = 1827;
                            if ( binding && typeof binding["init"] == "function" ){
                              __LINE__ = 1828;
                              var handlerInitFn = binding["init"];
                              
                              __LINE__ = 1829;
                              var initResult = handlerInitFn( node,makeValueAccessor( bindingKey ),parsedBindingsAccessor,viewModel,bindingContextInstance );
                              
                              __LINE__ = 1832;
                              if ( initResult && initResult['controlsDescendantBindings'] ){
                                __LINE__ = 1833;
                                if ( bindingHandlerThatControlsDescendantBindings !== undefined ){
                                  __LINE__ = 1834;
                                  throw new Error( "Multiple bindings ("+bindingHandlerThatControlsDescendantBindings+" and "+bindingKey+") are trying to control descendant bindings of the same element. You cannot use these bindings together on the same element." );
                                };
                                
                                __LINE__ = 0;
                                bindingHandlerThatControlsDescendantBindings = bindingKey;
                              };
                            };
                          };
                          
                          __LINE__ = 0;
                          initPhase = 2;
                        };
                        
                        __LINE__ = 1843;
                        if ( initPhase === 2 ){
                          __LINE__ = 1844;
                          for ( var bindingKey in parsedBindings ){
                            __LINE__ = 1845;
                            var binding = ko.bindingHandlers[bindingKey];
                            
                            __LINE__ = 1846;
                            if ( binding && typeof binding["update"] == "function" ){
                              __LINE__ = 1847;
                              var handlerUpdateFn = binding["update"];
                              
                              __LINE__ = 0;
                              handlerUpdateFn( node,makeValueAccessor( bindingKey ),parsedBindingsAccessor,viewModel,bindingContextInstance );
                            };
                          };
                        };
                      };
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  },null, {
                    'disposeWhenNodeIsRemoved' : node
                  });
                  __LINE__ = 1858;
                  return  {
                    shouldBindDescendants : bindingHandlerThatControlsDescendantBindings === undefined
                  };
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              __LINE__ = 1863;
              var storedBindingContextDomDataKey = "__ko_bindingContext__";
              
              __LINE__ = 0;
              ko.storedBindingContextForNode = function ( node,bindingContext ) {
                try {
                  __LINE__ = 1865;
                  if ( arguments.length == 2 ){
                    __LINE__ = 0;
                    ko.utils.domData.set( node,storedBindingContextDomDataKey,bindingContext );
                  } else {
                    __LINE__ = 1868;
                    return ko.utils.domData.get( node,storedBindingContextDomDataKey );
                  };
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              ko.applyBindingsToNode = function ( node,bindings,viewModel ) {
                try {
                  __LINE__ = 1872;
                  if ( node.nodeType === 1 ){
                    __LINE__ = 0;
                    ko.virtualElements.normaliseVirtualElementDomStructure( node );
                  };
                  __LINE__ = 1874;
                  return applyBindingsToNodeInternal( node,bindings,viewModel,true );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              ko.applyBindingsToDescendants = function ( viewModel,rootNode ) {
                try {
                  __LINE__ = 1878;
                  if ( rootNode.nodeType === 1 ){
                    __LINE__ = 0;
                    applyBindingsToDescendantsInternal( viewModel,rootNode );
                  };
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              ko.applyBindings = function ( viewModel,rootNode ) {
                try {
                  __LINE__ = 1883;
                  if ( rootNode && ( rootNode.nodeType !== 1 ) && ( rootNode.nodeType !== 8 ) ){
                    __LINE__ = 1884;
                    throw new Error( "ko.applyBindings: first parameter should be your view model; second parameter should be a DOM node" );
                  };
                  
                  __LINE__ = 0;
                  rootNode = rootNode || window.document.body;
                  
                  __LINE__ = 0;
                  applyBindingsToNodeAndDescendantsInternal( viewModel,rootNode,true );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              ko.contextFor = function ( node ) {
                try {
                  __LINE__ = 0;
                  switch ( node.nodeType ) {
                    case 1 :
                    case 8 :
                      
                      __LINE__ = 1896;
                      var context = ko.storedBindingContextForNode( node );
                      
                      __LINE__ = 1897;
                      if ( context ){
                        __LINE__ = 1897;
                        return context;
                      };
                      
                      __LINE__ = 1898;
                      if ( node.parentNode ){
                        __LINE__ = 1898;
                        return ko.contextFor( node.parentNode );
                      };
                      __LINE__ = 1899;
                      break;
                      
                  };
                  __LINE__ = 1901;
                  return undefined;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              ko.dataFor = function ( node ) {
                try {
                  __LINE__ = 1904;
                  var context = ko.contextFor( node );
                  __LINE__ = 1905;
                  return context?context['$data'] : undefined;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              ko.exportSymbol( 'ko.bindingHandlers',ko.bindingHandlers );
              
              __LINE__ = 0;
              ko.exportSymbol( 'ko.applyBindings',ko.applyBindings );
              
              __LINE__ = 0;
              ko.exportSymbol( 'ko.applyBindingsToDescendants',ko.applyBindingsToDescendants );
              
              __LINE__ = 0;
              ko.exportSymbol( 'ko.applyBindingsToNode',ko.applyBindingsToNode );
              
              __LINE__ = 0;
              ko.exportSymbol( 'ko.contextFor',ko.contextFor );
              
              __LINE__ = 0;
              ko.exportSymbol( 'ko.dataFor',ko.dataFor );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })();
          
          __LINE__ = 1916;
          var eventHandlersWithShortcuts = ['click'];
          
          __LINE__ = 0;
          ko.utils.arrayForEach( eventHandlersWithShortcuts,
          function ( eventName ) {
            try {
              __LINE__ = 0;
              ko.bindingHandlers[eventName] =  {
                'init' : function ( element,valueAccessor,allBindingsAccessor,viewModel ) {
                  try {
                    __LINE__ = 1920;
                    var newValueAccessor = function () {
                          try {
                            __LINE__ = 1921;
                            var result = {};
                            
                            __LINE__ = 0;
                            result[eventName] = valueAccessor();
                            __LINE__ = 1923;
                            return result;
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    __LINE__ = 1925;
                    return ko.bindingHandlers['event']['init'].call( this,element,newValueAccessor,allBindingsAccessor,viewModel );
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
              };
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          });
          
          __LINE__ = 0;
          ko.bindingHandlers['event'] =  {
            'init' : function ( element,valueAccessor,allBindingsAccessor,viewModel ) {
              try {
                __LINE__ = 1933;
                var eventsToHandle = valueAccessor() || {};
                
                __LINE__ = 1934;
                for ( var eventNameOutsideClosure in eventsToHandle ){
                  __LINE__ = 0;
                  ( function () {
                    try {
                      __LINE__ = 1936;
                      var eventName = eventNameOutsideClosure;
                      
                      __LINE__ = 1937;
                      if ( typeof eventName == "string" ){
                        __LINE__ = 0;
                        ko.utils.registerEventHandler( element,eventName,
                        function ( event ) {
                          try {
                            __LINE__ = 1939;
                            var handlerReturnValue;
                            
                            __LINE__ = 1940;
                            var handlerFunction = valueAccessor()[eventName];
                            
                            __LINE__ = 1941;
                            if ( !handlerFunction ){
                              __LINE__ = 1942;
                              return ;
                            };
                            
                            __LINE__ = 1943;
                            var allBindings = allBindingsAccessor();
                            
                            try {
                              __LINE__ = 1947;
                              var argsForHandler = ko.utils.makeArray( arguments );
                              
                              __LINE__ = 0;
                              argsForHandler.unshift( viewModel );
                              
                              __LINE__ = 0;
                              handlerReturnValue = handlerFunction.apply( viewModel,argsForHandler );
                            } finally {
                              __LINE__ = 1951;
                              if ( handlerReturnValue !== true ){
                                __LINE__ = 1952;
                                if ( event.preventDefault ){
                                  __LINE__ = 0;
                                  event.preventDefault();
                                } else {
                                  __LINE__ = 0;
                                  event.returnValue = false;
                                };
                              };
                            };
                            
                            __LINE__ = 1959;
                            var bubble = allBindings[eventName+'Bubble'] !== false;
                            
                            __LINE__ = 1960;
                            if ( !bubble ){
                              __LINE__ = 0;
                              event.cancelBubble = true;
                              
                              __LINE__ = 1962;
                              if ( event.stopPropagation ){
                                __LINE__ = 0;
                                event.stopPropagation();
                              };
                            };
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        });
                      };
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  })();
                };
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            }
          };
          
          __LINE__ = 0;
          ko.bindingHandlers['submit'] =  {
            'init' : function ( element,valueAccessor,allBindingsAccessor,viewModel ) {
              try {
                __LINE__ = 1974;
                if ( typeof valueAccessor() != "function" ){
                  __LINE__ = 1975;
                  throw new Error( "The value for a submit binding must be a function" );
                };
                
                __LINE__ = 0;
                ko.utils.registerEventHandler( element,"submit",
                function ( event ) {
                  try {
                    __LINE__ = 1977;
                    var handlerReturnValue;
                    
                    __LINE__ = 1978;
                    var value = valueAccessor();
                    
                    try {
                      __LINE__ = 0;
                      handlerReturnValue = value.call( viewModel,element );
                    } finally {
                      __LINE__ = 1981;
                      if ( handlerReturnValue !== true ){
                        __LINE__ = 1982;
                        if ( event.preventDefault ){
                          __LINE__ = 0;
                          event.preventDefault();
                        } else {
                          __LINE__ = 0;
                          event.returnValue = false;
                        };
                      };
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                });
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            }
          };
          
          __LINE__ = 0;
          ko.bindingHandlers['visible'] =  {
            'update' : function ( element,valueAccessor ) {
              try {
                __LINE__ = 1994;
                var value = ko.utils.unwrapObservable( valueAccessor() );
                
                __LINE__ = 1995;
                var isCurrentlyVisible = !( element.style.display == "none" );
                
                __LINE__ = 1996;
                if ( value && !isCurrentlyVisible ){
                  __LINE__ = 0;
                  element.style.display = "";
                } else if ( ( !value ) && isCurrentlyVisible ){
                  __LINE__ = 0;
                  element.style.display = "none";
                };
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            }
          };
          
          __LINE__ = 0;
          ko.bindingHandlers['enable'] =  {
            'update' : function ( element,valueAccessor ) {
              try {
                __LINE__ = 2005;
                var value = ko.utils.unwrapObservable( valueAccessor() );
                
                __LINE__ = 2006;
                if ( value && element.disabled ){
                  __LINE__ = 0;
                  element.removeAttribute( "disabled" );
                } else if ( ( !value ) && ( !element.disabled ) ){
                  __LINE__ = 0;
                  element.disabled = true;
                };
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            }
          };
          
          __LINE__ = 0;
          ko.bindingHandlers['disable'] =  {
            'update' : function ( element,valueAccessor ) {
              try {
                __LINE__ = 0;
                ko.bindingHandlers['enable']['update']( element,
                function () {
                  try {
                    __LINE__ = 2015;
                    return !ko.utils.unwrapObservable( valueAccessor() );
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                });
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            }
          };
          
          function ensureDropdownSelectionIsConsistentWithModelValue( element,modelValue,preferModelValue ) {
            try {
              __LINE__ = 2020;
              if ( preferModelValue ){
                __LINE__ = 2021;
                if ( modelValue !== ko.selectExtensions.readValue( element ) ){
                  __LINE__ = 0;
                  ko.selectExtensions.writeValue( element,modelValue );
                };
              };
              
              __LINE__ = 2028;
              if ( modelValue !== ko.selectExtensions.readValue( element ) ){
                __LINE__ = 0;
                ko.utils.triggerEvent( element,"change" );
              };
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          }
          __LINE__ = 0;
          ko.bindingHandlers['value'] =  {
            'init' : function ( element,valueAccessor,allBindingsAccessor ) {
              try {
                __LINE__ = 2035;
                var eventsToCatch = ["change"];
                
                __LINE__ = 2036;
                var requestedEventsToCatch = allBindingsAccessor()["valueUpdate"];
                
                __LINE__ = 2037;
                if ( requestedEventsToCatch ){
                  __LINE__ = 2038;
                  if ( typeof requestedEventsToCatch == "string" ){
                    __LINE__ = 0;
                    requestedEventsToCatch = [requestedEventsToCatch];
                  };
                  
                  __LINE__ = 0;
                  ko.utils.arrayPushAll( eventsToCatch,requestedEventsToCatch );
                  
                  __LINE__ = 0;
                  eventsToCatch = ko.utils.arrayGetDistinctValues( eventsToCatch );
                };
                
                __LINE__ = 0;
                ko.utils.arrayForEach( eventsToCatch,
                function ( eventName ) {
                  try {
                    __LINE__ = 2048;
                    var handleEventAsynchronously = false;
                    
                    __LINE__ = 2049;
                    if ( ko.utils.stringStartsWith( eventName,"after" ) ){
                      __LINE__ = 0;
                      handleEventAsynchronously = true;
                      
                      __LINE__ = 0;
                      eventName = eventName.substring( "after".length );
                    };
                    
                    __LINE__ = 2053;
                    var runEventHandler = handleEventAsynchronously?function ( handler ) {
                          try {
                            __LINE__ = 0;
                            setTimeout( handler,0 );
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        } : function ( handler ) {
                          try {
                            __LINE__ = 0;
                            handler();
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    
                    __LINE__ = 0;
                    ko.utils.registerEventHandler( element,eventName,
                    function () {
                      try {
                        __LINE__ = 0;
                        runEventHandler( function () {
                          try {
                            __LINE__ = 2058;
                            var modelValue = valueAccessor();
                            
                            __LINE__ = 2059;
                            var elementValue = ko.selectExtensions.readValue( element );
                            
                            __LINE__ = 2060;
                            if ( ko.isWriteableObservable( modelValue ) ){
                              __LINE__ = 0;
                              modelValue( elementValue );
                            } else {
                              __LINE__ = 2063;
                              var allBindings = allBindingsAccessor();
                              if ( allBindings['_ko_property_writers'] && allBindings['_ko_property_writers']['value'] ){
                                __LINE__ = 0;
                                allBindings['_ko_property_writers']['value']( elementValue );
                              };
                            };
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        });
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    });
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                });
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            'update' : function ( element,valueAccessor ) {
              try {
                __LINE__ = 2072;
                var newValue = ko.utils.unwrapObservable( valueAccessor() );
                
                __LINE__ = 2073;
                var elementValue = ko.selectExtensions.readValue( element );
                
                __LINE__ = 2074;
                var valueHasChanged = ( newValue != elementValue );
                
                __LINE__ = 2078;
                if ( ( newValue === 0 ) && ( elementValue !== 0 ) && ( elementValue !== "0" ) ){
                  __LINE__ = 0;
                  valueHasChanged = true;
                };
                
                __LINE__ = 2081;
                if ( valueHasChanged ){
                  __LINE__ = 2082;
                  var applyValueAction = function () {
                        try {
                          __LINE__ = 0;
                          ko.selectExtensions.writeValue( element,newValue );
                        } catch( e ){
                          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      };
                  
                  __LINE__ = 0;
                  applyValueAction();
                  
                  __LINE__ = 2088;
                  var alsoApplyAsynchronously = element.tagName == "SELECT";
                  
                  __LINE__ = 2089;
                  if ( alsoApplyAsynchronously ){
                    __LINE__ = 0;
                    setTimeout( applyValueAction,0 );
                  };
                };
                
                __LINE__ = 2095;
                if ( ( element.tagName == "SELECT" ) && ( element.length>0 ) ){
                  __LINE__ = 0;
                  ensureDropdownSelectionIsConsistentWithModelValue( element,newValue,false );
                };
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            }
          };
          
          __LINE__ = 0;
          ko.bindingHandlers['options'] =  {
            'update' : function ( element,valueAccessor,allBindingsAccessor ) {
              try {
                __LINE__ = 2102;
                if ( element.tagName != "SELECT" ){
                  __LINE__ = 2103;
                  throw new Error( "options binding applies only to SELECT elements" );
                };
                
                __LINE__ = 2105;
                var selectWasPreviouslyEmpty = element.length == 0;
                
                __LINE__ = 2106;
                var previousSelectedValues = ko.utils.arrayMap( ko.utils.arrayFilter( element.childNodes,
                    function ( node ) {
                      try {
                        __LINE__ = 2107;
                        return node.tagName && node.tagName == "OPTION" && node.selected;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    }),
                    function ( node ) {
                      try {
                        __LINE__ = 2109;
                        return ko.selectExtensions.readValue( node ) || node.innerText || node.textContent;
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    });
                
                __LINE__ = 2111;
                var previousScrollTop = element.scrollTop;
                
                __LINE__ = 0;
                element.scrollTop = 0;
                
                __LINE__ = 2114;
                var value = ko.utils.unwrapObservable( valueAccessor() );
                
                __LINE__ = 2115;
                var selectedValue = element.value;
                
                __LINE__ = 2119;
                while ( element.length>0 ){
                  __LINE__ = 0;
                  ko.cleanNode( element.options[0] );
                  
                  __LINE__ = 0;
                  element.remove( 0 );
                };
                
                __LINE__ = 2124;
                if ( value ){
                  __LINE__ = 2125;
                  var allBindings = allBindingsAccessor();
                  
                  __LINE__ = 2126;
                  if ( typeof value.length != "number" ){
                    __LINE__ = 0;
                    value = [value];
                  };
                  
                  __LINE__ = 2128;
                  if ( allBindings['optionsCaption'] ){
                    __LINE__ = 2129;
                    var option = document.createElement( "OPTION" );
                    
                    __LINE__ = 0;
                    ko.utils.setHtml( option,allBindings['optionsCaption'] );
                    
                    __LINE__ = 0;
                    ko.selectExtensions.writeValue( option,undefined );
                    
                    __LINE__ = 0;
                    element.appendChild( option );
                  };
                  
                  __LINE__ = 2134;
                  for ( var i = 0,j = value.length;i<j;i ++  ){
                    __LINE__ = 2135;
                    var option = document.createElement( "OPTION" );
                    
                    __LINE__ = 2138;
                    var optionValue = typeof allBindings['optionsValue'] == "string"?value[i][allBindings['optionsValue']] : value[i];
                    
                    __LINE__ = 0;
                    optionValue = ko.utils.unwrapObservable( optionValue );
                    
                    __LINE__ = 0;
                    ko.selectExtensions.writeValue( option,optionValue );
                    
                    __LINE__ = 2143;
                    var optionsTextValue = allBindings['optionsText'];
                    
                    __LINE__ = 2144;
                    var optionText;
                    
                    __LINE__ = 2145;
                    if ( typeof optionsTextValue == "function" ){
                      __LINE__ = 0;
                      optionText = optionsTextValue( value[i] );
                    } else if ( typeof optionsTextValue == "string" ){
                      __LINE__ = 0;
                      optionText = value[i][optionsTextValue];
                    } else {
                      __LINE__ = 0;
                      optionText = optionValue;
                    };
                    
                    __LINE__ = 2151;
                    if ( ( optionText === null ) || ( optionText === undefined ) ){
                      __LINE__ = 0;
                      optionText = "";
                    };
                    
                    __LINE__ = 0;
                    ko.utils.setTextContent( option,optionText );
                    
                    __LINE__ = 0;
                    element.appendChild( option );
                  };
                  
                  __LINE__ = 2161;
                  var newOptions = element.getElementsByTagName( "OPTION" );
                  
                  __LINE__ = 2162;
                  var countSelectionsRetained = 0;
                  
                  __LINE__ = 2163;
                  for ( var i = 0,j = newOptions.length;i<j;i ++  ){
                    __LINE__ = 2164;
                    if ( ko.utils.arrayIndexOf( previousSelectedValues,ko.selectExtensions.readValue( newOptions[i] ) ) >= 0 ){
                      __LINE__ = 0;
                      ko.utils.setOptionNodeSelectionState( newOptions[i],true );
                      
                      __LINE__ = 0;
                      countSelectionsRetained ++ ;
                    };
                  };
                  
                  __LINE__ = 2170;
                  if ( previousScrollTop ){
                    __LINE__ = 0;
                    element.scrollTop = previousScrollTop;
                  };
                  
                  __LINE__ = 2173;
                  if ( selectWasPreviouslyEmpty && ( 'value' in allBindings ) ){
                    __LINE__ = 0;
                    ensureDropdownSelectionIsConsistentWithModelValue( element,ko.utils.unwrapObservable( allBindings['value'] ),true );
                  };
                };
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            }
          };
          
          __LINE__ = 0;
          ko.bindingHandlers['options'].optionValueDomDataKey = '__ko.optionValueDomData__';
          
          __LINE__ = 0;
          ko.bindingHandlers['selectedOptions'] =  {
            getSelectedValuesFromSelectNode : function ( selectNode ) {
              try {
                __LINE__ = 2186;
                var result = [];
                
                __LINE__ = 2187;
                var nodes = selectNode.childNodes;
                
                __LINE__ = 2188;
                for ( var i = 0,j = nodes.length;i<j;i ++  ){
                  __LINE__ = 2189;
                  var node = nodes[i];
                  
                  __LINE__ = 2190;
                  if ( ( node.tagName == "OPTION" ) && node.selected ){
                    __LINE__ = 0;
                    result.push( ko.selectExtensions.readValue( node ) );
                  };
                };
                __LINE__ = 2193;
                return result;
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            'init' : function ( element,valueAccessor,allBindingsAccessor ) {
              try {
                __LINE__ = 0;
                ko.utils.registerEventHandler( element,"change",
                function () {
                  try {
                    __LINE__ = 2197;
                    var value = valueAccessor();
                    
                    __LINE__ = 2198;
                    if ( ko.isWriteableObservable( value ) ){
                      __LINE__ = 0;
                      value( ko.bindingHandlers['selectedOptions'].getSelectedValuesFromSelectNode( this ) );
                    } else {
                      __LINE__ = 2201;
                      var allBindings = allBindingsAccessor();
                      if ( allBindings['_ko_property_writers'] && allBindings['_ko_property_writers']['value'] ){
                        __LINE__ = 0;
                        allBindings['_ko_property_writers']['value']( ko.bindingHandlers['selectedOptions'].getSelectedValuesFromSelectNode( this ) );
                      };
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                });
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            'update' : function ( element,valueAccessor ) {
              try {
                __LINE__ = 2208;
                if ( element.tagName != "SELECT" ){
                  __LINE__ = 2209;
                  throw new Error( "values binding applies only to SELECT elements" );
                };
                
                __LINE__ = 2211;
                var newValue = ko.utils.unwrapObservable( valueAccessor() );
                
                __LINE__ = 2212;
                if ( newValue && typeof newValue.length == "number" ){
                  __LINE__ = 2213;
                  var nodes = element.childNodes;
                  
                  __LINE__ = 2214;
                  for ( var i = 0,j = nodes.length;i<j;i ++  ){
                    __LINE__ = 2215;
                    var node = nodes[i];
                    
                    __LINE__ = 2216;
                    if ( node.tagName == "OPTION" ){
                      __LINE__ = 0;
                      ko.utils.setOptionNodeSelectionState( node,ko.utils.arrayIndexOf( newValue,ko.selectExtensions.readValue( node ) ) >= 0 );
                    };
                  };
                };
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            }
          };
          
          __LINE__ = 0;
          ko.bindingHandlers['text'] =  {
            'update' : function ( element,valueAccessor ) {
              try {
                __LINE__ = 0;
                ko.utils.setTextContent( element,valueAccessor() );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            }
          };
          
          __LINE__ = 0;
          ko.bindingHandlers['html'] =  {
            'init' : function () {
              try {
                __LINE__ = 2232;
                return  {
                  'controlsDescendantBindings' : true
                };
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            'update' : function ( element,valueAccessor ) {
              try {
                __LINE__ = 2235;
                var value = ko.utils.unwrapObservable( valueAccessor() );
                
                __LINE__ = 0;
                ko.utils.setHtml( element,value );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            }
          };
          
          __LINE__ = 0;
          ko.bindingHandlers['css'] =  {
            'update' : function ( element,valueAccessor ) {
              try {
                __LINE__ = 2242;
                var value = ko.utils.unwrapObservable( valueAccessor() || {} );
                
                __LINE__ = 2243;
                for ( var className in value ){
                  __LINE__ = 2244;
                  if ( typeof className == "string" ){
                    __LINE__ = 2245;
                    var shouldHaveClass = ko.utils.unwrapObservable( value[className] );
                    
                    __LINE__ = 0;
                    ko.utils.toggleDomNodeCssClass( element,className,shouldHaveClass );
                  };
                };
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            }
          };
          
          __LINE__ = 0;
          ko.bindingHandlers['style'] =  {
            'update' : function ( element,valueAccessor ) {
              try {
                __LINE__ = 2254;
                var value = ko.utils.unwrapObservable( valueAccessor() || {} );
                
                __LINE__ = 2255;
                for ( var styleName in value ){
                  __LINE__ = 2256;
                  if ( typeof styleName == "string" ){
                    __LINE__ = 2257;
                    var styleValue = ko.utils.unwrapObservable( value[styleName] );
                    
                    __LINE__ = 0;
                    element.style[styleName] = styleValue || "";
                  };
                };
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            }
          };
          
          __LINE__ = 0;
          ko.bindingHandlers['uniqueName'] =  {
            'init' : function ( element,valueAccessor ) {
              try {
                __LINE__ = 2266;
                if ( valueAccessor() ){
                  __LINE__ = 0;
                  element.name = "ko_unique_"+(  ++ ko.bindingHandlers['uniqueName'].currentIndex );
                  
                  __LINE__ = 2272;
                  if ( ko.utils.isIe6 || ko.utils.isIe7 ){
                    __LINE__ = 0;
                    element.mergeAttributes( document.createElement( "<input name='"+element.name+"'/>" ),false );
                  };
                };
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            }
          };
          
          __LINE__ = 0;
          ko.bindingHandlers['uniqueName'].currentIndex = 0;
          
          __LINE__ = 0;
          ko.bindingHandlers['checked'] =  {
            'init' : function ( element,valueAccessor,allBindingsAccessor ) {
              try {
                __LINE__ = 2281;
                var updateHandler = function () {
                      try {
                        __LINE__ = 2282;
                        var valueToWrite;
                        
                        __LINE__ = 2283;
                        if ( element.type == "checkbox" ){
                          __LINE__ = 0;
                          valueToWrite = element.checked;
                        } else if ( ( element.type == "radio" ) && ( element.checked ) ){
                          __LINE__ = 0;
                          valueToWrite = element.value;
                        } else {
                          __LINE__ = 2288;
                          return ;
                        };
                        
                        __LINE__ = 2291;
                        var modelValue = valueAccessor();
                        
                        __LINE__ = 2292;
                        if ( ( element.type == "checkbox" ) && ( ko.utils.unwrapObservable( modelValue ) instanceof Array ) ){
                          __LINE__ = 2295;
                          var existingEntryIndex = ko.utils.arrayIndexOf( ko.utils.unwrapObservable( modelValue ),element.value );
                          
                          __LINE__ = 2296;
                          if ( element.checked && ( existingEntryIndex<0 ) ){
                            __LINE__ = 0;
                            modelValue.push( element.value );
                          } else if ( ( !element.checked ) && ( existingEntryIndex >= 0 ) ){
                            __LINE__ = 0;
                            modelValue.splice( existingEntryIndex,1 );
                          };
                        } else if ( ko.isWriteableObservable( modelValue ) ){
                          if ( modelValue() !== valueToWrite ){
                            __LINE__ = 0;
                            modelValue( valueToWrite );
                          };
                        } else {
                          __LINE__ = 2305;
                          var allBindings = allBindingsAccessor();
                          if ( allBindings['_ko_property_writers'] && allBindings['_ko_property_writers']['checked'] ){
                            __LINE__ = 0;
                            allBindings['_ko_property_writers']['checked']( valueToWrite );
                          };
                        };
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    };
                
                __LINE__ = 0;
                ko.utils.registerEventHandler( element,"click",updateHandler );
                
                __LINE__ = 2314;
                if ( ( element.type == "radio" ) && !element.name ){
                  __LINE__ = 0;
                  ko.bindingHandlers['uniqueName']['init']( element,
                  function () {
                    try {
                      __LINE__ = 2315;
                      return true;
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  });
                };
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            'update' : function ( element,valueAccessor ) {
              try {
                __LINE__ = 2318;
                var value = ko.utils.unwrapObservable( valueAccessor() );
                
                __LINE__ = 2320;
                if ( element.type == "checkbox" ){
                  __LINE__ = 2321;
                  if ( value instanceof Array ){
                    __LINE__ = 0;
                    element.checked = ko.utils.arrayIndexOf( value,element.value ) >= 0;
                  } else {
                    __LINE__ = 0;
                    element.checked = value;
                  };
                } else if ( element.type == "radio" ){
                  __LINE__ = 0;
                  element.checked = ( element.value == value );
                };
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            }
          };
          
          __LINE__ = 0;
          ko.bindingHandlers['attr'] =  {
            'update' : function ( element,valueAccessor,allBindingsAccessor ) {
              try {
                __LINE__ = 2336;
                var value = ko.utils.unwrapObservable( valueAccessor() ) || {};
                
                __LINE__ = 2337;
                for ( var attrName in value ){
                  __LINE__ = 2338;
                  if ( typeof attrName == "string" ){
                    __LINE__ = 2339;
                    var attrValue = ko.utils.unwrapObservable( value[attrName] );
                    
                    __LINE__ = 2344;
                    if ( ( attrValue === false ) || ( attrValue === null ) || ( attrValue === undefined ) ){
                      __LINE__ = 0;
                      element.removeAttribute( attrName );
                    } else {
                      __LINE__ = 0;
                      element.setAttribute( attrName,attrValue.toString() );
                    };
                  };
                };
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            }
          };
          
          __LINE__ = 0;
          ko.bindingHandlers['hasfocus'] =  {
            'init' : function ( element,valueAccessor,allBindingsAccessor ) {
              try {
                __LINE__ = 2355;
                var writeValue = function ( valueToWrite ) {
                      try {
                        __LINE__ = 2356;
                        var modelValue = valueAccessor();
                        
                        __LINE__ = 2357;
                        if ( valueToWrite == ko.utils.unwrapObservable( modelValue ) ){
                          __LINE__ = 2358;
                          return ;
                        };
                        
                        __LINE__ = 2360;
                        if ( ko.isWriteableObservable( modelValue ) ){
                          __LINE__ = 0;
                          modelValue( valueToWrite );
                        } else {
                          __LINE__ = 2363;
                          var allBindings = allBindingsAccessor();
                          if ( allBindings['_ko_property_writers'] && allBindings['_ko_property_writers']['hasfocus'] ){
                            __LINE__ = 0;
                            allBindings['_ko_property_writers']['hasfocus']( valueToWrite );
                          };
                        };
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    };
                
                __LINE__ = 0;
                ko.utils.registerEventHandler( element,"focus",
                function () {
                  try {
                    __LINE__ = 0;
                    writeValue( true );
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                });
                
                __LINE__ = 0;
                ko.utils.registerEventHandler( element,"focusin",
                function () {
                  try {
                    __LINE__ = 0;
                    writeValue( true );
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                });
                
                __LINE__ = 0;
                ko.utils.registerEventHandler( element,"blur",
                function () {
                  try {
                    __LINE__ = 0;
                    writeValue( false );
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                });
                
                __LINE__ = 0;
                ko.utils.registerEventHandler( element,"focusout",
                function () {
                  try {
                    __LINE__ = 0;
                    writeValue( false );
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                });
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            'update' : function ( element,valueAccessor ) {
              try {
                __LINE__ = 2375;
                var value = ko.utils.unwrapObservable( valueAccessor() );
                
                __LINE__ = 0;
                value?element.focus() : element.blur();
                
                __LINE__ = 0;
                ko.utils.triggerEvent( element,value?"focusin" : "focusout" );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            }
          };
          
          __LINE__ = 0;
          ko.bindingHandlers['with'] =  {
            makeTemplateValueAccessor : function ( valueAccessor ) {
              try {
                __LINE__ = 2384;
                return function () {
                  try {
                    __LINE__ = 2384;
                    var value = valueAccessor();
                    __LINE__ = 2384;
                    return  {
                      'if' : value,
                      'data' : value,
                      'templateEngine' : ko.nativeTemplateEngine.instance
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            'init' : function ( element,valueAccessor,allBindingsAccessor,viewModel,bindingContext ) {
              try {
                __LINE__ = 2387;
                return ko.bindingHandlers['template']['init']( element,ko.bindingHandlers['with'].makeTemplateValueAccessor( valueAccessor ) );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            'update' : function ( element,valueAccessor,allBindingsAccessor,viewModel,bindingContext ) {
              try {
                __LINE__ = 2390;
                return ko.bindingHandlers['template']['update']( element,ko.bindingHandlers['with'].makeTemplateValueAccessor( valueAccessor ),allBindingsAccessor,viewModel,bindingContext );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            }
          };
          
          __LINE__ = 0;
          ko.jsonExpressionRewriting.bindingRewriteValidators['with'] = false;
          
          __LINE__ = 0;
          ko.virtualElements.allowedBindings['with'] = true;
          
          __LINE__ = 0;
          ko.bindingHandlers['if'] =  {
            makeTemplateValueAccessor : function ( valueAccessor ) {
              try {
                __LINE__ = 2399;
                return function () {
                  try {
                    __LINE__ = 2399;
                    return  {
                      'if' : valueAccessor(),
                      'templateEngine' : ko.nativeTemplateEngine.instance
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            'init' : function ( element,valueAccessor,allBindingsAccessor,viewModel,bindingContext ) {
              try {
                __LINE__ = 2402;
                return ko.bindingHandlers['template']['init']( element,ko.bindingHandlers['if'].makeTemplateValueAccessor( valueAccessor ) );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            'update' : function ( element,valueAccessor,allBindingsAccessor,viewModel,bindingContext ) {
              try {
                __LINE__ = 2405;
                return ko.bindingHandlers['template']['update']( element,ko.bindingHandlers['if'].makeTemplateValueAccessor( valueAccessor ),allBindingsAccessor,viewModel,bindingContext );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            }
          };
          
          __LINE__ = 0;
          ko.jsonExpressionRewriting.bindingRewriteValidators['if'] = false;
          
          __LINE__ = 0;
          ko.virtualElements.allowedBindings['if'] = true;
          
          __LINE__ = 0;
          ko.bindingHandlers['ifnot'] =  {
            makeTemplateValueAccessor : function ( valueAccessor ) {
              try {
                __LINE__ = 2414;
                return function () {
                  try {
                    __LINE__ = 2414;
                    return  {
                      'ifnot' : valueAccessor(),
                      'templateEngine' : ko.nativeTemplateEngine.instance
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            'init' : function ( element,valueAccessor,allBindingsAccessor,viewModel,bindingContext ) {
              try {
                __LINE__ = 2417;
                return ko.bindingHandlers['template']['init']( element,ko.bindingHandlers['ifnot'].makeTemplateValueAccessor( valueAccessor ) );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            'update' : function ( element,valueAccessor,allBindingsAccessor,viewModel,bindingContext ) {
              try {
                __LINE__ = 2420;
                return ko.bindingHandlers['template']['update']( element,ko.bindingHandlers['ifnot'].makeTemplateValueAccessor( valueAccessor ),allBindingsAccessor,viewModel,bindingContext );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            }
          };
          
          __LINE__ = 0;
          ko.jsonExpressionRewriting.bindingRewriteValidators['ifnot'] = false;
          
          __LINE__ = 0;
          ko.virtualElements.allowedBindings['ifnot'] = true;
          
          __LINE__ = 0;
          ko.bindingHandlers['foreach'] =  {
            makeTemplateValueAccessor : function ( valueAccessor ) {
              try {
                __LINE__ = 2430;
                return function () {
                  try {
                    __LINE__ = 2431;
                    var bindingValue = ko.utils.unwrapObservable( valueAccessor() );
                    
                    __LINE__ = 2434;
                    if ( ( !bindingValue ) || typeof bindingValue.length == "number" ){
                      __LINE__ = 2435;
                      return  {
                        'foreach' : bindingValue,
                        'templateEngine' : ko.nativeTemplateEngine.instance
                      };
                    };
                    __LINE__ = 2438;
                    return  {
                      'foreach' : bindingValue['data'],
                      'includeDestroyed' : bindingValue['includeDestroyed'],
                      'afterAdd' : bindingValue['afterAdd'],
                      'beforeRemove' : bindingValue['beforeRemove'],
                      'afterRender' : bindingValue['afterRender'],
                      'templateEngine' : ko.nativeTemplateEngine.instance
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                };
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            'init' : function ( element,valueAccessor,allBindingsAccessor,viewModel,bindingContext ) {
              try {
                __LINE__ = 2449;
                return ko.bindingHandlers['template']['init']( element,ko.bindingHandlers['foreach'].makeTemplateValueAccessor( valueAccessor ) );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            },
            'update' : function ( element,valueAccessor,allBindingsAccessor,viewModel,bindingContext ) {
              try {
                __LINE__ = 2452;
                return ko.bindingHandlers['template']['update']( element,ko.bindingHandlers['foreach'].makeTemplateValueAccessor( valueAccessor ),allBindingsAccessor,viewModel,bindingContext );
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            }
          };
          
          __LINE__ = 0;
          ko.jsonExpressionRewriting.bindingRewriteValidators['foreach'] = false;
          
          __LINE__ = 0;
          ko.virtualElements.allowedBindings['foreach'] = true;
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.allowedVirtualElementBindings',ko.virtualElements.allowedBindings );
          
          __LINE__ = 0;
          ko.templateEngine = function (){};
          
          __LINE__ = 0;
          ko.templateEngine.prototype['renderTemplateSource'] = function ( templateSource,bindingContext,options ) {
            try {
              __LINE__ = 2486;
              throw "Override renderTemplateSource";
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          ko.templateEngine.prototype['createJavaScriptEvaluatorBlock'] = function ( script ) {
            try {
              __LINE__ = 2490;
              throw "Override createJavaScriptEvaluatorBlock";
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          ko.templateEngine.prototype['makeTemplateSource'] = function ( template ) {
            try {
              __LINE__ = 2495;
              if ( typeof template == "string" ){
                __LINE__ = 2496;
                var elem = document.getElementById( template );
                
                __LINE__ = 2497;
                if ( !elem ){
                  __LINE__ = 2498;
                  throw new Error( "Cannot find template with ID "+template );
                };
                __LINE__ = 2499;
                return new ko.templateSources.domElement( elem );
              } else if ( ( template.nodeType == 1 ) || ( template.nodeType == 8 ) ){
                __LINE__ = 2502;
                return new ko.templateSources.anonymousTemplate( template );
              } else {
                __LINE__ = 2504;
                throw new Error( "Unknown template type: "+template );
              };
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          ko.templateEngine.prototype['renderTemplate'] = function ( template,bindingContext,options ) {
            try {
              __LINE__ = 2508;
              var templateSource = this['makeTemplateSource']( template );
              __LINE__ = 2509;
              return this['renderTemplateSource']( templateSource,bindingContext,options );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          ko.templateEngine.prototype['isTemplateRewritten'] = function ( template ) {
            try {
              __LINE__ = 2514;
              if ( this['allowTemplateRewriting'] === false ){
                __LINE__ = 2515;
                return true;
              };
              
              __LINE__ = 2518;
              if ( this.knownRewrittenTemplates && this.knownRewrittenTemplates[template] ){
                __LINE__ = 2519;
                return true;
              };
              __LINE__ = 2521;
              return this['makeTemplateSource']( template )['data']( "isRewritten" );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          ko.templateEngine.prototype['rewriteTemplate'] = function ( template,rewriterCallback ) {
            try {
              __LINE__ = 2525;
              var templateSource = this['makeTemplateSource']( template );
              
              __LINE__ = 2526;
              var rewritten = rewriterCallback( templateSource['text']() );
              
              __LINE__ = 0;
              templateSource['text']( rewritten );
              
              __LINE__ = 0;
              templateSource['data']( "isRewritten",true );
              
              __LINE__ = 2532;
              if ( typeof template == "string" ){
                __LINE__ = 0;
                this.knownRewrittenTemplates = this.knownRewrittenTemplates || {};
                
                __LINE__ = 0;
                this.knownRewrittenTemplates[template] = true;
              };
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.templateEngine',ko.templateEngine );
          
          __LINE__ = 0;
          ko.templateRewriting = ( function () {
            try {
              __LINE__ = 2540;
              var memoizeDataBindingAttributeSyntaxRegex = /(<[a-z]+\d*(\s+(?!data-bind=)[a-z0-9\-]+(=(\"[^\"]*\"|\'[^\']*\'))?)*\s+)data-bind=(["'])([\s\S]*?)\5/gi;
              
              __LINE__ = 2541;
              var memoizeVirtualContainerBindingSyntaxRegex = /<!--\s*ko\b\s*([\s\S]*?)\s*-->/g;
              
              function validateDataBindValuesForRewriting( keyValueArray ) {
                try {
                  __LINE__ = 2544;
                  var allValidators = ko.jsonExpressionRewriting.bindingRewriteValidators;
                  
                  __LINE__ = 2545;
                  for ( var i = 0;i<keyValueArray.length;i ++  ){
                    __LINE__ = 2546;
                    var key = keyValueArray[i]['key'];
                    
                    __LINE__ = 2547;
                    if ( allValidators.hasOwnProperty( key ) ){
                      __LINE__ = 2548;
                      var validator = allValidators[key];
                      
                      __LINE__ = 2550;
                      if ( typeof validator === "function" ){
                        __LINE__ = 2551;
                        var possibleErrorMessage = validator( keyValueArray[i]['value'] );
                        
                        __LINE__ = 2552;
                        if ( possibleErrorMessage ){
                          __LINE__ = 2553;
                          throw new Error( possibleErrorMessage );
                        };
                      } else if ( !validator ){
                        __LINE__ = 2555;
                        throw new Error( "This template engine does not support the '"+key+"' binding within its templates" );
                      };
                    };
                  };
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              function constructMemoizedTagReplacement( dataBindAttributeValue,tagToRetain,templateEngine ) {
                try {
                  __LINE__ = 2562;
                  var dataBindKeyValueArray = ko.jsonExpressionRewriting.parseObjectLiteral( dataBindAttributeValue );
                  
                  __LINE__ = 0;
                  validateDataBindValuesForRewriting( dataBindKeyValueArray );
                  
                  __LINE__ = 2564;
                  var rewrittenDataBindAttributeValue = ko.jsonExpressionRewriting.insertPropertyAccessorsIntoJson( dataBindKeyValueArray );
                  
                  __LINE__ = 2569;
                  var applyBindingsToNextSiblingScript = "ko.templateRewriting.applyMemoizedBindingsToNextSibling(function() { \
            return (function() { return { "+rewrittenDataBindAttributeValue+" } })() \
        })";
                  __LINE__ = 2570;
                  return templateEngine['createJavaScriptEvaluatorBlock']( applyBindingsToNextSiblingScript )+tagToRetain;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }__LINE__ = 2573;
              return  {
                ensureTemplateIsRewritten : function ( template,templateEngine ) {
                  try {
                    __LINE__ = 2575;
                    if ( !templateEngine['isTemplateRewritten']( template ) ){
                      __LINE__ = 0;
                      templateEngine['rewriteTemplate']( template,
                      function ( htmlString ) {
                        try {
                          __LINE__ = 2577;
                          return ko.templateRewriting.memoizeBindingAttributeSyntax( htmlString,templateEngine );
                        } catch( e ){
                          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      });
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                memoizeBindingAttributeSyntax : function ( htmlString,templateEngine ) {
                  try {
                    __LINE__ = 2582;
                    return htmlString.replace( memoizeDataBindingAttributeSyntaxRegex,
                    function () {
                      try {
                        __LINE__ = 2583;
                        return constructMemoizedTagReplacement( arguments[6],arguments[1],templateEngine );
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    }).replace( memoizeVirtualContainerBindingSyntaxRegex,
                    function () {
                      try {
                        __LINE__ = 2585;
                        return constructMemoizedTagReplacement( arguments[1],"<!-- ko -->",templateEngine );
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    });
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                applyMemoizedBindingsToNextSibling : function ( bindings ) {
                  try {
                    __LINE__ = 2590;
                    return ko.memoization.memoize( function ( domNode,bindingContext ) {
                      try {
                        __LINE__ = 2591;
                        if ( domNode.nextSibling ){
                          __LINE__ = 0;
                          ko.applyBindingsToNode( domNode.nextSibling,bindings,bindingContext );
                        };
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    });
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
              };
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })();
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.templateRewriting',ko.templateRewriting );
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.templateRewriting.applyMemoizedBindingsToNextSibling',ko.templateRewriting.applyMemoizedBindingsToNextSibling );
          
          __LINE__ = 0;
          ( function () {
            try {
              __LINE__ = 0;
              ko.templateSources = {};
              
              __LINE__ = 0;
              ko.templateSources.domElement = function ( element ) {
                try {
                  __LINE__ = 0;
                  this.domElement = element;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              ko.templateSources.domElement.prototype['text'] = function () {
                try {
                  __LINE__ = 2628;
                  if ( arguments.length == 0 ){
                    __LINE__ = 2629;
                    return this.domElement.tagName.toLowerCase() == "script"?this.domElement.text : this.domElement.innerHTML;
                  } else {
                    __LINE__ = 2631;
                    var valueToWrite = arguments[0];
                    if ( this.domElement.tagName.toLowerCase() == "script" ){
                      __LINE__ = 0;
                      this.domElement.text = valueToWrite;
                    } else {
                      __LINE__ = 0;
                      ko.utils.setHtml( this.domElement,valueToWrite );
                    };
                  };
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              ko.templateSources.domElement.prototype['data'] = function ( key ) {
                try {
                  __LINE__ = 2640;
                  if ( arguments.length === 1 ){
                    __LINE__ = 2641;
                    return ko.utils.domData.get( this.domElement,"templateSourceData_"+key );
                  } else {
                    __LINE__ = 0;
                    ko.utils.domData.set( this.domElement,"templateSourceData_"+key,arguments[1] );
                  };
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 2649;
              var anonymousTemplatesDomDataKey = "__ko_anon_template__";
              
              __LINE__ = 0;
              ko.templateSources.anonymousTemplate = function ( element ) {
                try {
                  __LINE__ = 0;
                  this.domElement = element;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              ko.templateSources.anonymousTemplate.prototype = new ko.templateSources.domElement();
              
              __LINE__ = 0;
              ko.templateSources.anonymousTemplate.prototype['text'] = function () {
                try {
                  __LINE__ = 2655;
                  if ( arguments.length == 0 ){
                    __LINE__ = 2656;
                    return ko.utils.domData.get( this.domElement,anonymousTemplatesDomDataKey );
                  } else {
                    __LINE__ = 2658;
                    var valueToWrite = arguments[0];
                    
                    __LINE__ = 0;
                    ko.utils.domData.set( this.domElement,anonymousTemplatesDomDataKey,valueToWrite );
                  };
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              ko.exportSymbol( 'ko.templateSources',ko.templateSources );
              
              __LINE__ = 0;
              ko.exportSymbol( 'ko.templateSources.domElement',ko.templateSources.domElement );
              
              __LINE__ = 0;
              ko.exportSymbol( 'ko.templateSources.anonymousTemplate',ko.templateSources.anonymousTemplate );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })();
          
          __LINE__ = 0;
          ( function () {
            try {
              __LINE__ = 2668;
              var _templateEngine;
              
              __LINE__ = 0;
              ko.setTemplateEngine = function ( templateEngine ) {
                try {
                  __LINE__ = 2670;
                  if ( ( templateEngine != undefined ) && !( templateEngine instanceof ko.templateEngine ) ){
                    __LINE__ = 2671;
                    throw "templateEngine must inherit from ko.templateEngine";
                  };
                  
                  __LINE__ = 0;
                  _templateEngine = templateEngine;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              function invokeForEachNodeOrCommentInParent( nodeArray,parent,action ) {
                try {
                  __LINE__ = 2676;
                  for ( var i = 0;node = nodeArray[i];i ++  ){
                    __LINE__ = 2677;
                    if ( node.parentNode !== parent ){
                      __LINE__ = 2678;
                      continue ;
                    };
                    
                    __LINE__ = 2679;
                    if ( ( node.nodeType === 1 ) || ( node.nodeType === 8 ) ){
                      __LINE__ = 0;
                      action( node );
                    };
                  };
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              __LINE__ = 0;
              ko.activateBindingsOnTemplateRenderedNodes = function ( nodeArray,bindingContext ) {
                try {
                  __LINE__ = 2691;
                  var nodeArrayClone = ko.utils.arrayPushAll( [],nodeArray );
                  
                  __LINE__ = 2692;
                  var commonParentElement = ( nodeArray.length>0 )?nodeArray[0].parentNode : null;
                  
                  __LINE__ = 0;
                  invokeForEachNodeOrCommentInParent( nodeArrayClone,commonParentElement,
                  function ( node ) {
                    try {
                      __LINE__ = 0;
                      ko.applyBindings( bindingContext,node );
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  });
                  
                  __LINE__ = 0;
                  invokeForEachNodeOrCommentInParent( nodeArrayClone,commonParentElement,
                  function ( node ) {
                    try {
                      __LINE__ = 0;
                      ko.memoization.unmemoizeDomNodeAndDescendants( node,[bindingContext] );
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  });
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              function getFirstNodeFromPossibleArray( nodeOrNodeArray ) {
                try {
                  __LINE__ = 2706;
                  return nodeOrNodeArray.nodeType?nodeOrNodeArray : nodeOrNodeArray.length>0?nodeOrNodeArray[0] : null;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              function executeTemplate( targetNodeOrNodeArray,renderMode,template,bindingContext,options ) {
                try {
                  __LINE__ = 0;
                  options = options || {};
                  
                  __LINE__ = 2713;
                  var templateEngineToUse = ( options['templateEngine'] || _templateEngine );
                  
                  __LINE__ = 0;
                  ko.templateRewriting.ensureTemplateIsRewritten( template,templateEngineToUse );
                  
                  __LINE__ = 2715;
                  var renderedNodesArray = templateEngineToUse['renderTemplate']( template,bindingContext,options );
                  
                  __LINE__ = 2718;
                  if ( ( typeof renderedNodesArray.length != "number" ) || ( renderedNodesArray.length>0 && typeof renderedNodesArray[0].nodeType != "number" ) ){
                    __LINE__ = 2719;
                    throw "Template engine must return an array of DOM nodes";
                  };
                  
                  __LINE__ = 2721;
                  var haveAddedNodesToParent = false;
                  
                  __LINE__ = 0;
                  switch ( renderMode ) {
                    case "replaceChildren" :
                      
                      __LINE__ = 0;
                      ko.virtualElements.setDomNodeChildren( targetNodeOrNodeArray,renderedNodesArray );
                      
                      __LINE__ = 0;
                      haveAddedNodesToParent = true;
                      __LINE__ = 2726;
                      break;
                    case "replaceNode" :
                      
                      __LINE__ = 0;
                      ko.utils.replaceDomNodes( targetNodeOrNodeArray,renderedNodesArray );
                      
                      __LINE__ = 0;
                      haveAddedNodesToParent = true;
                      __LINE__ = 2730;
                      break;
                    case "ignoreTargetNode" :
                      __LINE__ = 2731;
                      break;
                    default :
                      __LINE__ = 2733;
                      throw new Error( "Unknown renderMode: "+renderMode );
                      
                  };
                  
                  __LINE__ = 2736;
                  if ( haveAddedNodesToParent ){
                    __LINE__ = 0;
                    ko.activateBindingsOnTemplateRenderedNodes( renderedNodesArray,bindingContext );
                    
                    __LINE__ = 2738;
                    if ( options['afterRender'] ){
                      __LINE__ = 0;
                      options['afterRender']( renderedNodesArray,bindingContext['$data'] );
                    };
                  };
                  __LINE__ = 2742;
                  return renderedNodesArray;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              __LINE__ = 0;
              ko.renderTemplate = function ( template,dataOrBindingContext,options,targetNodeOrNodeArray,renderMode ) {
                try {
                  __LINE__ = 0;
                  options = options || {};
                  
                  __LINE__ = 2747;
                  if ( ( options['templateEngine'] || _templateEngine ) == undefined ){
                    __LINE__ = 2748;
                    throw "Set a template engine before calling renderTemplate";
                  };
                  
                  __LINE__ = 0;
                  renderMode = renderMode || "replaceChildren";
                  
                  __LINE__ = 2751;
                  if ( targetNodeOrNodeArray ){
                    __LINE__ = 2752;
                    var firstTargetNode = getFirstNodeFromPossibleArray( targetNodeOrNodeArray );
                    
                    __LINE__ = 2754;
                    var whenToDispose = function () {
                          try {
                            __LINE__ = 2754;
                            return ( !firstTargetNode ) || !ko.utils.domNodeIsAttachedToDocument( firstTargetNode );
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        };
                    
                    __LINE__ = 2755;
                    var activelyDisposeWhenNodeIsRemoved = ( firstTargetNode && renderMode == "replaceNode" )?firstTargetNode.parentNode : firstTargetNode;
                    __LINE__ = 2757;
                    return new ko.dependentObservable( function () {
                      try {
                        __LINE__ = 2760;
                        var bindingContext = ( dataOrBindingContext && ( dataOrBindingContext instanceof ko.bindingContext ) )?dataOrBindingContext : new ko.bindingContext( ko.utils.unwrapObservable( dataOrBindingContext ) );
                        
                        __LINE__ = 2765;
                        var templateName = typeof ( template ) == 'function'?template( bindingContext['$data'] ) : template;
                        
                        __LINE__ = 2767;
                        var renderedNodesArray = executeTemplate( targetNodeOrNodeArray,renderMode,templateName,bindingContext,options );
                        
                        __LINE__ = 2768;
                        if ( renderMode == "replaceNode" ){
                          __LINE__ = 0;
                          targetNodeOrNodeArray = renderedNodesArray;
                          
                          __LINE__ = 0;
                          firstTargetNode = getFirstNodeFromPossibleArray( targetNodeOrNodeArray );
                        };
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    },null, {
                      'disposeWhen' : whenToDispose,
                      'disposeWhenNodeIsRemoved' : activelyDisposeWhenNodeIsRemoved
                    });
                  } else {
                    __LINE__ = 2778;
                    return ko.memoization.memoize( function ( domNode ) {
                      try {
                        __LINE__ = 0;
                        ko.renderTemplate( template,dataOrBindingContext,options,domNode,"replaceNode" );
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    });
                  };
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              ko.renderTemplateForEach = function ( template,arrayOrObservableArray,options,targetNode,parentBindingContext ) {
                try {
                  __LINE__ = 2785;
                  var createInnerBindingContext = function ( arrayValue ) {
                        try {
                          __LINE__ = 2786;
                          return parentBindingContext['createChildContext']( ko.utils.unwrapObservable( arrayValue ) );
                        } catch( e ){
                          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      };
                  
                  __LINE__ = 2790;
                  var activateBindingsCallback = function ( arrayValue,addedNodesArray ) {
                        try {
                          __LINE__ = 2791;
                          var bindingContext = createInnerBindingContext( arrayValue );
                          
                          __LINE__ = 0;
                          ko.activateBindingsOnTemplateRenderedNodes( addedNodesArray,bindingContext );
                          
                          __LINE__ = 2793;
                          if ( options['afterRender'] ){
                            __LINE__ = 0;
                            options['afterRender']( addedNodesArray,bindingContext['$data'] );
                          };
                        } catch( e ){
                          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      };
                  __LINE__ = 2797;
                  return new ko.dependentObservable( function () {
                    try {
                      __LINE__ = 2798;
                      var unwrappedArray = ko.utils.unwrapObservable( arrayOrObservableArray ) || [];
                      
                      __LINE__ = 2799;
                      if ( typeof unwrappedArray.length == "undefined" ){
                        __LINE__ = 0;
                        unwrappedArray = [unwrappedArray];
                      };
                      
                      __LINE__ = 2803;
                      var filteredArray = ko.utils.arrayFilter( unwrappedArray,
                          function ( item ) {
                            try {
                              __LINE__ = 2804;
                              return options['includeDestroyed'] || item === undefined || item === null || !ko.utils.unwrapObservable( item['_destroy'] );
                            } catch( e ){
                              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                            }
                          });
                      
                      __LINE__ = 0;
                      ko.utils.setDomNodeChildrenFromArrayMapping( targetNode,filteredArray,
                      function ( arrayValue ) {
                        try {
                          __LINE__ = 2809;
                          var templateName = typeof ( template ) == 'function'?template( arrayValue ) : template;
                          __LINE__ = 2810;
                          return executeTemplate( null,"ignoreTargetNode",templateName,createInnerBindingContext( arrayValue ),options );
                        } catch( e ){
                          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      },options,activateBindingsCallback);
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  },null, {
                    'disposeWhenNodeIsRemoved' : targetNode
                  });
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 2816;
              var templateSubscriptionDomDataKey = '__ko__templateSubscriptionDomDataKey__';
              
              function disposeOldSubscriptionAndStoreNewOne( element,newSubscription ) {
                try {
                  __LINE__ = 2818;
                  var oldSubscription = ko.utils.domData.get( element,templateSubscriptionDomDataKey );
                  
                  __LINE__ = 2819;
                  if ( oldSubscription && ( typeof ( oldSubscription.dispose ) == 'function' ) ){
                    __LINE__ = 0;
                    oldSubscription.dispose();
                  };
                  
                  __LINE__ = 0;
                  ko.utils.domData.set( element,templateSubscriptionDomDataKey,newSubscription );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              __LINE__ = 0;
              ko.bindingHandlers['template'] =  {
                'init' : function ( element,valueAccessor ) {
                  try {
                    __LINE__ = 2827;
                    var bindingValue = ko.utils.unwrapObservable( valueAccessor() );
                    
                    __LINE__ = 2828;
                    if ( ( typeof bindingValue != "string" ) && ( !bindingValue.name ) && ( element.nodeType == 1 ) ){
                      __LINE__ = 0;
                      new ko.templateSources.anonymousTemplate( element ).text( element.innerHTML );
                      
                      __LINE__ = 0;
                      ko.utils.emptyDomNode( element );
                    };
                    __LINE__ = 2833;
                    return  {
                      'controlsDescendantBindings' : true
                    };
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                },
                'update' : function ( element,valueAccessor,allBindingsAccessor,viewModel,bindingContext ) {
                  try {
                    __LINE__ = 2836;
                    var bindingValue = ko.utils.unwrapObservable( valueAccessor() );
                    
                    __LINE__ = 2837;
                    var templateName;
                    
                    __LINE__ = 2838;
                    var shouldDisplay = true;
                    
                    __LINE__ = 2840;
                    if ( typeof bindingValue == "string" ){
                      __LINE__ = 0;
                      templateName = bindingValue;
                    } else {
                      __LINE__ = 0;
                      templateName = bindingValue.name;
                      if ( 'if' in bindingValue ){
                        __LINE__ = 0;
                        shouldDisplay = shouldDisplay && ko.utils.unwrapObservable( bindingValue['if'] );
                      };
                      if ( 'ifnot' in bindingValue ){
                        __LINE__ = 0;
                        shouldDisplay = shouldDisplay && !ko.utils.unwrapObservable( bindingValue['ifnot'] );
                      };
                    };
                    
                    __LINE__ = 2852;
                    var templateSubscription = null;
                    
                    __LINE__ = 2854;
                    if ( ( typeof bindingValue === 'object' ) && ( 'foreach' in bindingValue ) ){
                      __LINE__ = 2856;
                      var dataArray = ( shouldDisplay && bindingValue['foreach'] ) || [];
                      
                      __LINE__ = 0;
                      templateSubscription = ko.renderTemplateForEach( templateName || element,dataArray,bindingValue,element,bindingContext );
                    } else {
                      if ( shouldDisplay ){
                        __LINE__ = 2861;
                        var innerBindingContext = ( typeof bindingValue == 'object' ) && ( 'data' in bindingValue )?bindingContext['createChildContext']( ko.utils.unwrapObservable( bindingValue['data'] ) ) : bindingContext;
                        
                        __LINE__ = 0;
                        templateSubscription = ko.renderTemplate( templateName || element,innerBindingContext,bindingValue,element );
                      } else {
                        __LINE__ = 0;
                        ko.virtualElements.emptyNode( element );
                      };
                    };
                    
                    __LINE__ = 0;
                    disposeOldSubscriptionAndStoreNewOne( element,templateSubscription );
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
              };
              
              __LINE__ = 0;
              ko.jsonExpressionRewriting.bindingRewriteValidators['template'] = function ( bindingValue ) {
                try {
                  __LINE__ = 2876;
                  var parsedBindingValue = ko.jsonExpressionRewriting.parseObjectLiteral( bindingValue );
                  
                  __LINE__ = 2878;
                  if ( ( parsedBindingValue.length == 1 ) && parsedBindingValue[0]['unknown'] ){
                    __LINE__ = 2879;
                    return null;
                  };
                  
                  __LINE__ = 2881;
                  if ( ko.jsonExpressionRewriting.keyValueArrayContainsKey( parsedBindingValue,"name" ) ){
                    __LINE__ = 2882;
                    return null;
                  };
                  __LINE__ = 2883;
                  return "This template engine does not support anonymous templates nested within its templates";
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              ko.virtualElements.allowedBindings['template'] = true;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })();
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.setTemplateEngine',ko.setTemplateEngine );
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.renderTemplate',ko.renderTemplate );
          
          __LINE__ = 0;
          ( function () {
            try {
              function calculateEditDistanceMatrix( oldArray,newArray,maxAllowedDistance ) {
                try {
                  __LINE__ = 2894;
                  var distances = [];
                  
                  __LINE__ = 2895;
                  for ( var i = 0;i <= newArray.length;i ++  ){
                    __LINE__ = 0;
                    distances[i] = [];
                  };
                  
                  __LINE__ = 2899;
                  for ( var i = 0,j = Math.min( oldArray.length,maxAllowedDistance );i <= j;i ++  ){
                    __LINE__ = 0;
                    distances[0][i] = i;
                  };
                  
                  __LINE__ = 2903;
                  for ( var i = 1,j = Math.min( newArray.length,maxAllowedDistance );i <= j;i ++  ){
                    __LINE__ = 0;
                    distances[i][0] = i;
                  };
                  
                  __LINE__ = 2908;
                  var oldIndex,
                      oldIndexMax = oldArray.length,
                      newIndex,
                      newIndexMax = newArray.length;
                  
                  __LINE__ = 2909;
                  var distanceViaAddition,
                      distanceViaDeletion;
                  
                  __LINE__ = 2910;
                  for ( oldIndex = 1;oldIndex <= oldIndexMax;oldIndex ++  ){
                    __LINE__ = 2911;
                    var newIndexMinForRow = Math.max( 1,oldIndex-maxAllowedDistance );
                    
                    __LINE__ = 2912;
                    var newIndexMaxForRow = Math.min( newIndexMax,oldIndex+maxAllowedDistance );
                    
                    __LINE__ = 2913;
                    for ( newIndex = newIndexMinForRow;newIndex <= newIndexMaxForRow;newIndex ++  ){
                      __LINE__ = 2914;
                      if ( oldArray[oldIndex-1] === newArray[newIndex-1] ){
                        __LINE__ = 0;
                        distances[newIndex][oldIndex] = distances[newIndex-1][oldIndex-1];
                      } else {
                        __LINE__ = 2917;
                        var northDistance = distances[newIndex-1][oldIndex] === undefined?Number.MAX_VALUE : distances[newIndex-1][oldIndex]+1;
                        
                        __LINE__ = 2918;
                        var westDistance = distances[newIndex][oldIndex-1] === undefined?Number.MAX_VALUE : distances[newIndex][oldIndex-1]+1;
                        
                        __LINE__ = 0;
                        distances[newIndex][oldIndex] = Math.min( northDistance,westDistance );
                      };
                    };
                  };
                  __LINE__ = 2924;
                  return distances;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              function findEditScriptFromEditDistanceMatrix( editDistanceMatrix,oldArray,newArray ) {
                try {
                  __LINE__ = 2928;
                  var oldIndex = oldArray.length;
                  
                  __LINE__ = 2929;
                  var newIndex = newArray.length;
                  
                  __LINE__ = 2930;
                  var editScript = [];
                  
                  __LINE__ = 2931;
                  var maxDistance = editDistanceMatrix[newIndex][oldIndex];
                  
                  __LINE__ = 2932;
                  if ( maxDistance === undefined ){
                    __LINE__ = 2933;
                    return null;
                  };
                  
                  __LINE__ = 2934;
                  while ( ( oldIndex>0 ) || ( newIndex>0 ) ){
                    __LINE__ = 2935;
                    var me = editDistanceMatrix[newIndex][oldIndex];
                    
                    __LINE__ = 2936;
                    var distanceViaAdd = ( newIndex>0 )?editDistanceMatrix[newIndex-1][oldIndex] : maxDistance+1;
                    
                    __LINE__ = 2937;
                    var distanceViaDelete = ( oldIndex>0 )?editDistanceMatrix[newIndex][oldIndex-1] : maxDistance+1;
                    
                    __LINE__ = 2938;
                    var distanceViaRetain = ( newIndex>0 ) && ( oldIndex>0 )?editDistanceMatrix[newIndex-1][oldIndex-1] : maxDistance+1;
                    
                    __LINE__ = 2939;
                    if ( ( distanceViaAdd === undefined ) || ( distanceViaAdd<me-1 ) ){
                      __LINE__ = 0;
                      distanceViaAdd = maxDistance+1;
                    };
                    
                    __LINE__ = 2940;
                    if ( ( distanceViaDelete === undefined ) || ( distanceViaDelete<me-1 ) ){
                      __LINE__ = 0;
                      distanceViaDelete = maxDistance+1;
                    };
                    
                    __LINE__ = 2941;
                    if ( distanceViaRetain<me-1 ){
                      __LINE__ = 0;
                      distanceViaRetain = maxDistance+1;
                    };
                    
                    __LINE__ = 2943;
                    if ( ( distanceViaAdd <= distanceViaDelete ) && ( distanceViaAdd<distanceViaRetain ) ){
                      __LINE__ = 0;
                      editScript.push(  {
                        status : "added",
                        value : newArray[newIndex-1]
                      });
                      
                      __LINE__ = 0;
                      newIndex -- ;
                    } else if ( ( distanceViaDelete<distanceViaAdd ) && ( distanceViaDelete<distanceViaRetain ) ){
                      __LINE__ = 0;
                      editScript.push(  {
                        status : "deleted",
                        value : oldArray[oldIndex-1]
                      });
                      
                      __LINE__ = 0;
                      oldIndex -- ;
                    } else {
                      __LINE__ = 0;
                      editScript.push(  {
                        status : "retained",
                        value : oldArray[oldIndex-1]
                      });
                      
                      __LINE__ = 0;
                      newIndex -- ;
                      
                      __LINE__ = 0;
                      oldIndex -- ;
                    };
                  };
                  __LINE__ = 2955;
                  return editScript.reverse();
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              __LINE__ = 0;
              ko.utils.compareArrays = function ( oldArray,newArray,maxEditsToConsider ) {
                try {
                  __LINE__ = 2959;
                  if ( maxEditsToConsider === undefined ){
                    __LINE__ = 2960;
                    return ko.utils.compareArrays( oldArray,newArray,1 ) || ko.utils.compareArrays( oldArray,newArray,10 ) || ko.utils.compareArrays( oldArray,newArray,Number.MAX_VALUE );
                  } else {
                    __LINE__ = 0;
                    oldArray = oldArray || [];
                    
                    __LINE__ = 0;
                    newArray = newArray || [];
                    
                    __LINE__ = 2966;
                    var editDistanceMatrix = calculateEditDistanceMatrix( oldArray,newArray,maxEditsToConsider );
                    __LINE__ = 2967;
                    return findEditScriptFromEditDistanceMatrix( editDistanceMatrix,oldArray,newArray );
                  };
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })();
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.utils.compareArrays',ko.utils.compareArrays );
          
          __LINE__ = 0;
          ( function () {
            try {
              function fixUpVirtualElements( contiguousNodeArray ) {
                try {
                  __LINE__ = 2991;
                  if ( contiguousNodeArray.length>2 ){
                    __LINE__ = 2993;
                    var current = contiguousNodeArray[0],
                        last = contiguousNodeArray[contiguousNodeArray.length-1],
                        newContiguousSet = [current];
                    
                    __LINE__ = 2994;
                    while ( current !== last ){
                      __LINE__ = 0;
                      current = current.nextSibling;
                      
                      __LINE__ = 2996;
                      if ( !current ){
                        __LINE__ = 2997;
                        return ;
                      };
                      
                      __LINE__ = 0;
                      newContiguousSet.push( current );
                    };
                    
                    __LINE__ = 0;
                    Array.prototype.splice.apply( contiguousNodeArray,[0,contiguousNodeArray.length].concat( newContiguousSet ) );
                  };
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              function mapNodeAndRefreshWhenChanged( containerNode,mapping,valueToMap,callbackAfterAddingNodes ) {
                try {
                  __LINE__ = 3009;
                  var mappedNodes = [];
                  
                  __LINE__ = 3010;
                  var dependentObservable = ko.dependentObservable( function () {
                        try {
                          __LINE__ = 3011;
                          var newMappedNodes = mapping( valueToMap ) || [];
                          
                          __LINE__ = 3014;
                          if ( mappedNodes.length>0 ){
                            __LINE__ = 0;
                            fixUpVirtualElements( mappedNodes );
                            
                            __LINE__ = 0;
                            ko.utils.replaceDomNodes( mappedNodes,newMappedNodes );
                            
                            __LINE__ = 3017;
                            if ( callbackAfterAddingNodes ){
                              __LINE__ = 0;
                              callbackAfterAddingNodes( valueToMap,newMappedNodes );
                            };
                          };
                          
                          __LINE__ = 0;
                          mappedNodes.splice( 0,mappedNodes.length );
                          
                          __LINE__ = 0;
                          ko.utils.arrayPushAll( mappedNodes,newMappedNodes );
                        } catch( e ){
                          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      },null, {
                        'disposeWhenNodeIsRemoved' : containerNode,
                        'disposeWhen' : function () {
                          try {
                            __LINE__ = 3025;
                            return ( mappedNodes.length == 0 ) || !ko.utils.domNodeIsAttachedToDocument( mappedNodes[0] );
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        }
                      });
                  __LINE__ = 3026;
                  return  {
                    mappedNodes : mappedNodes,
                    dependentObservable : dependentObservable
                  };
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
              __LINE__ = 3029;
              var lastMappingResultDomDataKey = "setDomNodeChildrenFromArrayMapping_lastMappingResult";
              
              __LINE__ = 0;
              ko.utils.setDomNodeChildrenFromArrayMapping = function ( domNode,array,mapping,options,callbackAfterAddingNodes ) {
                try {
                  __LINE__ = 0;
                  array = array || [];
                  
                  __LINE__ = 0;
                  options = options || {};
                  
                  __LINE__ = 3035;
                  var isFirstExecution = ko.utils.domData.get( domNode,lastMappingResultDomDataKey ) === undefined;
                  
                  __LINE__ = 3036;
                  var lastMappingResult = ko.utils.domData.get( domNode,lastMappingResultDomDataKey ) || [];
                  
                  __LINE__ = 3037;
                  var lastArray = ko.utils.arrayMap( lastMappingResult,
                      function ( x ) {
                        try {
                          __LINE__ = 3037;
                          return x.arrayEntry;
                        } catch( e ){
                          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      });
                  
                  __LINE__ = 3038;
                  var editScript = ko.utils.compareArrays( lastArray,array );
                  
                  __LINE__ = 3041;
                  var newMappingResult = [];
                  
                  __LINE__ = 3042;
                  var lastMappingResultIndex = 0;
                  
                  __LINE__ = 3043;
                  var nodesToDelete = [];
                  
                  __LINE__ = 3044;
                  var nodesAdded = [];
                  
                  __LINE__ = 3045;
                  var insertAfterNode = null;
                  
                  __LINE__ = 3046;
                  for ( var i = 0,j = editScript.length;i<j;i ++  ){
                    __LINE__ = 0;
                    switch ( editScript[i].status ) {
                      case "retained" :
                        
                        __LINE__ = 3050;
                        var dataToRetain = lastMappingResult[lastMappingResultIndex];
                        
                        __LINE__ = 0;
                        newMappingResult.push( dataToRetain );
                        
                        __LINE__ = 3052;
                        if ( dataToRetain.domNodes.length>0 ){
                          __LINE__ = 0;
                          insertAfterNode = dataToRetain.domNodes[dataToRetain.domNodes.length-1];
                        };
                        
                        __LINE__ = 0;
                        lastMappingResultIndex ++ ;
                        __LINE__ = 3055;
                        break;
                      case "deleted" :
                        
                        __LINE__ = 0;
                        lastMappingResult[lastMappingResultIndex].dependentObservable.dispose();
                        
                        __LINE__ = 0;
                        fixUpVirtualElements( lastMappingResult[lastMappingResultIndex].domNodes );
                        
                        __LINE__ = 0;
                        ko.utils.arrayForEach( lastMappingResult[lastMappingResultIndex].domNodes,
                        function ( node ) {
                          try {
                            __LINE__ = 0;
                            nodesToDelete.push(  {
                              element : node,
                              index : i,
                              value : editScript[i].value
                            });
                            
                            __LINE__ = 0;
                            insertAfterNode = node;
                          } catch( e ){
                            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                          }
                        });
                        
                        __LINE__ = 0;
                        lastMappingResultIndex ++ ;
                        __LINE__ = 3072;
                        break;
                      case "added" :
                        
                        __LINE__ = 3075;
                        var valueToMap = editScript[i].value;
                        
                        __LINE__ = 3076;
                        var mapData = mapNodeAndRefreshWhenChanged( domNode,mapping,valueToMap,callbackAfterAddingNodes );
                        
                        __LINE__ = 3077;
                        var mappedNodes = mapData.mappedNodes;
                        
                        __LINE__ = 0;
                        newMappingResult.push(  {
                          arrayEntry : editScript[i].value,
                          domNodes : mappedNodes,
                          dependentObservable : mapData.dependentObservable
                        });
                        
                        __LINE__ = 3081;
                        for ( var nodeIndex = 0,nodeIndexMax = mappedNodes.length;nodeIndex<nodeIndexMax;nodeIndex ++  ){
                          __LINE__ = 3082;
                          var node = mappedNodes[nodeIndex];
                          
                          __LINE__ = 0;
                          nodesAdded.push(  {
                            element : node,
                            index : i,
                            value : editScript[i].value
                          });
                          
                          __LINE__ = 3088;
                          if ( insertAfterNode == null ){
                            __LINE__ = 0;
                            ko.virtualElements.prepend( domNode,node );
                          } else {
                            __LINE__ = 0;
                            ko.virtualElements.insertAfter( domNode,node,insertAfterNode );
                          };
                          
                          __LINE__ = 0;
                          insertAfterNode = node;
                        };
                        
                        __LINE__ = 3097;
                        if ( callbackAfterAddingNodes ){
                          __LINE__ = 0;
                          callbackAfterAddingNodes( valueToMap,mappedNodes );
                        };
                        __LINE__ = 3099;
                        break;
                        
                    };
                  };
                  
                  __LINE__ = 0;
                  ko.utils.arrayForEach( nodesToDelete,
                  function ( node ) {
                    try {
                      __LINE__ = 0;
                      ko.cleanNode( node.element );
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  });
                  
                  __LINE__ = 3105;
                  var invokedBeforeRemoveCallback = false;
                  
                  __LINE__ = 3106;
                  if ( !isFirstExecution ){
                    __LINE__ = 3107;
                    if ( options['afterAdd'] ){
                      __LINE__ = 3108;
                      for ( var i = 0;i<nodesAdded.length;i ++  ){
                        __LINE__ = 0;
                        options['afterAdd']( nodesAdded[i].element,nodesAdded[i].index,nodesAdded[i].value );
                      };
                    };
                    
                    __LINE__ = 3111;
                    if ( options['beforeRemove'] ){
                      __LINE__ = 3112;
                      for ( var i = 0;i<nodesToDelete.length;i ++  ){
                        __LINE__ = 0;
                        options['beforeRemove']( nodesToDelete[i].element,nodesToDelete[i].index,nodesToDelete[i].value );
                      };
                      
                      __LINE__ = 0;
                      invokedBeforeRemoveCallback = true;
                    };
                  };
                  
                  __LINE__ = 3117;
                  if ( !invokedBeforeRemoveCallback ){
                    __LINE__ = 0;
                    ko.utils.arrayForEach( nodesToDelete,
                    function ( node ) {
                      try {
                        __LINE__ = 0;
                        ko.removeNode( node.element );
                      } catch( e ){
                        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                      }
                    });
                  };
                  
                  __LINE__ = 0;
                  ko.utils.domData.set( domNode,lastMappingResultDomDataKey,newMappingResult );
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })();
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.utils.setDomNodeChildrenFromArrayMapping',ko.utils.setDomNodeChildrenFromArrayMapping );
          
          __LINE__ = 0;
          ko.nativeTemplateEngine = function () {
            try {
              __LINE__ = 0;
              this['allowTemplateRewriting'] = false;
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          ko.nativeTemplateEngine.prototype = new ko.templateEngine();
          
          __LINE__ = 0;
          ko.nativeTemplateEngine.prototype['renderTemplateSource'] = function ( templateSource,bindingContext,options ) {
            try {
              __LINE__ = 3134;
              var templateText = templateSource.text();
              __LINE__ = 3135;
              return ko.utils.parseHtmlFragment( templateText );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          };
          
          __LINE__ = 0;
          ko.nativeTemplateEngine.instance = new ko.nativeTemplateEngine();
          
          __LINE__ = 0;
          ko.setTemplateEngine( ko.nativeTemplateEngine.instance );
          
          __LINE__ = 0;
          ko.exportSymbol( 'ko.nativeTemplateEngine',ko.nativeTemplateEngine );
          
          __LINE__ = 0;
          ( function () {
            try {
              __LINE__ = 0;
              ko.jqueryTmplTemplateEngine = function () {
                try {
                  __LINE__ = 3147;
                  var jQueryTmplVersion = this.jQueryTmplVersion = ( function () {
                        try {
                          __LINE__ = 3148;
                          if ( ( typeof ( jQuery ) == "undefined" ) || !( jQuery['tmpl'] ) ){
                            __LINE__ = 3149;
                            return 0;
                          };
                          
                          try {
                            __LINE__ = 3152;
                            if ( jQuery['tmpl']['tag']['tmpl']['open'].toString().indexOf( '__' ) >= 0 ){
                              __LINE__ = 3154;
                              return 2;
                            };
                          } catch( ex ){
                            
                          };
                          __LINE__ = 3158;
                          return 1;
                        } catch( e ){
                          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                        }
                      })();
                  
                  function ensureHasReferencedJQueryTemplates() {
                    try {
                      __LINE__ = 3162;
                      if ( jQueryTmplVersion<2 ){
                        __LINE__ = 3163;
                        throw new Error( "Your version of jQuery.tmpl is too old. Please upgrade to jQuery.tmpl 1.0.0pre or later." );
                      };
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  }
                  function executeTemplate( compiledTemplate,data,jQueryTemplateOptions ) {
                    try {
                      __LINE__ = 3167;
                      return jQuery['tmpl']( compiledTemplate,data,jQueryTemplateOptions );
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  }
                  __LINE__ = 0;
                  this['renderTemplateSource'] = function ( templateSource,bindingContext,options ) {
                    try {
                      __LINE__ = 0;
                      options = options || {};
                      
                      __LINE__ = 0;
                      ensureHasReferencedJQueryTemplates();
                      
                      __LINE__ = 3175;
                      var precompiled = templateSource['data']( 'precompiled' );
                      
                      __LINE__ = 3176;
                      if ( !precompiled ){
                        __LINE__ = 3177;
                        var templateText = templateSource.text() || "";
                        
                        __LINE__ = 0;
                        templateText = "{{ko_with $item.koBindingContext}}"+templateText+"{{/ko_with}}";
                        
                        __LINE__ = 0;
                        precompiled = jQuery['template']( null,templateText );
                        
                        __LINE__ = 0;
                        templateSource['data']( 'precompiled',precompiled );
                      };
                      
                      __LINE__ = 3185;
                      var data = [bindingContext['$data']];
                      
                      __LINE__ = 3186;
                      var jQueryTemplateOptions = jQuery['extend'](  {
                            'koBindingContext' : bindingContext
                          },options['templateOptions'] );
                      
                      __LINE__ = 3188;
                      var resultNodes = executeTemplate( precompiled,data,jQueryTemplateOptions );
                      
                      __LINE__ = 0;
                      resultNodes['appendTo']( document.createElement( "div" ) );
                      
                      __LINE__ = 0;
                      jQuery['fragments'] = {};
                      __LINE__ = 3191;
                      return resultNodes;
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  };
                  
                  __LINE__ = 0;
                  this['createJavaScriptEvaluatorBlock'] = function ( script ) {
                    try {
                      __LINE__ = 3195;
                      return "{{ko_code ((function() { return "+script+" })()) }}";
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  };
                  
                  __LINE__ = 0;
                  this['addTemplate'] = function ( templateName,templateMarkup ) {
                    try {
                      __LINE__ = 0;
                      document.write( "<script type='text/html' id='"+templateName+"'>"+templateMarkup+"</script>" );
                    } catch( e ){
                      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                    }
                  };
                  
                  __LINE__ = 3202;
                  if ( jQueryTmplVersion>0 ){
                    __LINE__ = 0;
                    jQuery['tmpl']['tag']['ko_code'] =  {
                      open : "__.push($1 || '');"
                    };
                    
                    __LINE__ = 0;
                    jQuery['tmpl']['tag']['ko_with'] =  {
                      open : "with($1) {",
                      close : "} "
                    };
                  };
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              };
              
              __LINE__ = 0;
              ko.jqueryTmplTemplateEngine.prototype = new ko.templateEngine();
              
              __LINE__ = 3216;
              var jqueryTmplTemplateEngineInstance = new ko.jqueryTmplTemplateEngine();
              
              __LINE__ = 3217;
              if ( jqueryTmplTemplateEngineInstance.jQueryTmplVersion>0 ){
                __LINE__ = 0;
                ko.setTemplateEngine( jqueryTmplTemplateEngineInstance );
              };
              
              __LINE__ = 0;
              ko.exportSymbol( 'ko.jqueryTmplTemplateEngine',ko.jqueryTmplTemplateEngine );
            } catch( e ){
              Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
            }
          })();
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      })( window );
    } catch( e ){
      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  })();
})();
