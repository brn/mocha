/**
 *@author Taketoshi Aono
 *@fileOverview
 *@license
 *Copyright (c) 2011 Taketoshi Aono
 *Licensed under the BSD.
 *
 *Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
 *associated doc umentation files (the "Software"), to deal in the Software without restriction,
 *including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 *subject to the following conditions:
 *
 *The above copyright notice and this permission notice shall be included in all copies or
 *substantial portions ofthe Software.
 *
 *THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 *TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 *THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 *CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *DEALINGS IN THE SOFTWARE.
 */

//Global module container.
var _mochaGlobalExport = {};

//ecma262 5th edition compatible buitin extensions.
(->{
  "use strict";  
  builtinTypeError( message ) -> {
    try {
      throw new TypeError( message );
    } catch ( e ) {
      throw new  Error( e );
    }
  }
  
  callbackCheck( callback , type ) -> {
    @assert( true , typeof type === "string" );
    if ( typeof callback !== "function" ) {
      builtinTypeError( type + " : first argument is not callable" );
    }
  }
  
  if( !String.prototype.trim ){
    /**
     * [MDN String/Trim]
     * Removes whitespace from both ends of the string.
     * @return {String}
     */
    String.prototype.trim = -> this.replace( String.prototype.trim.rtrim , "" );
    //To avoid closure, we set regular expression to function's property.
    String.prototype.trim.rtrim = /^\s*|\s*$/g;
  }
  
  if( !Function.prototype.bind ){
    /**
     * [MDN Function/Bind]
     * Creates a new function that, when called,
     * itself calls this function in the context of the provided this value,
     * with a given sequence of arguments preceding any provided when the new function was called.
     * @param {*} -> context object, nullable.
     * @param {...args} -> binding arguments list.
     * @return {Function}
     */
    Function.prototype.bind = -> {
      var argArray = Array.prototype.slice.call ( arguments ),
          context = argArray.shift (),
          ret = ->{
            var args = argArray.concat ( Array.prototype.slice.call ( arguments ) );
            if ( this !== null && this !== window && this instanceof ret ) {
              return ret.context.apply ( this , args );
            } else {
              return ret.context.apply( context , args );
            }
          }
      //Avoid closure.
      ret.prototype = this.prototype;
      ret.context = this;
      return ret;
    }
  }

  if( !Array.prototype.forEach ){
    /**
     * [MDN Array/ForEach]
     * Executes a provided function once per array element.
     * @param {Function} callback -> Function( current , index , array )
     * * Callback function taking three arguments.
     * current
     *   |- The current element begin processed in array.
     * index
     *   |- The index of the current element begin processed in array.
     * array
     *   |- The array map was called upon.
     * @param {*} that -> context object. 
     */
    Array.prototype.forEach = ( callback , that ) -> {
      callbackCheck( callback , "Array.forEach" );
      var iter = -1,
          ta;
      if ( this === null ) {
        builtinTypeError( "Array.forEach : this is null or not defined" );
      }
      if( that ){
        while( ( ta = this[ ++iter ] ) !== null && ta !== undefined ){
          callback.call( that , ta , iter , this );
        }
      }else{
        while( ( ta = this[ ++iter ] ) !== null && ta !== undefined ){
          callback( ta , iter , this );
        }
      }
    }
  }

  if( !Array.prototype.every ){
    /**
     * [MDN Array/every]
     * Tests whether all elements in the array pass the test implemented by the provided function.
     * @param {Function} callback -> Function( current , index , array )
     * Callback function taking three arguments.
     * current
     *   |- The current element begin processed in array.
     * index
     *   |- The index of the current element begin processed in array.
     * array
     *   |- The array map was called upon.
     * @param {*} that -> context object.
     */
    Array.prototype.every = ( callback , that ) -> {
      callbackCheck( callback , "Array.every" );
      var iter = -1,
          ta;
      if ( this === null ) {
        builtinTypeError( "Array.every : this is null or not defined" );
      }
      if( that ){
        while( ( ta = this[ ++iter ] ) !== null && ta !== undefined ){
          if( ! ( callback.call( that , ta , iter , this ) ) ){
            return false;
          }
        }
      }else{
        while( ( ta = this[ ++iter ] ) !== null && ta !== undefined ){
          if( !( callback( ta , iter , this ) ) ){
            return false;
          }
        }
      }
      return true;
    }
  }

  if( !Array.prototype.some ){
    /**
     * [MDN Array/Some]
     * Tests whether some element in the array passes the test implemented by the provided function.
     * @param {Function} callback -> Function( current , index ,array )
     * Callback function taking three arguments.
     * current
     *   |- The current element begin processed in array.
     * index
     *   |- The index of the current element begin processed in array.
     * array
     *   |- The array map was called upon.
     * @param {*} that -> context object.
     */
    Array.prototype.some = ( callback , that ) -> {
      callbackCheck( callback , "Array.some" );
      var iter = -1,
          ta;
      if ( this === null ) {
        builtinTypeError( "Array.some : this is null or not defined" );
      }
      if( that ){
        while( ( ta = this[ ++iter ] ) !== null && ta !== undefined ){
          if( callback.call( that , ta , iter , this ) ){
            return true;
          }
        }
      }else{
        while( ( ta = this[ ++iter ] ) !== null && ta !== undefined ){
          if( callback( ta , iter , this ) ){
            return true;
          }
        }
      }
      return false;
    }
  }

  if( !Array.prototype.filter ){
    /**
     * [MDN Array/Filter]
     * Creates a new array with all elements that pass the test implemented by the provided function.
     * @param {Function} callback -> Function( current , index , array )
     * Callback function taking three arguments.
     * current
     *   |- The current element begin processed in array.
     * index
     *   |- The index of the current element begin processed in array.
     * array
     *   |- The array map was called upon.
     * @param {*} that -> context object
     */
    Array.prototype.filter = ( callback , that ) -> {
      callbackCheck( callback , "Array.filter" );
      var len = this.length,
          iter = -1,
          ret = [],
          ta;
      if ( this === null ) {
        builtinTypeError( "Array.filter : this is null or not defined" );
      }
      if( that ){
        for( var i = 0,len = this.length; i < len; ++i ){
          if( ( ta = this[ i ] ) !== null && ta !== undefined ){
            if( callback.call( that , ta , i , this ) ){
              ret[ ++iter ] = ta;
            }
          }
        }
      }else{
        for( var i = 0,len = this.length; i < len; ++i ){
          if( ( ta = this[ i ] ) !== null && ta !== undefined ){
            if( callback( ta , i , this ) ){
              ret[ ++iter ] = ta;
            }
          }
        }
      }
      return ret;
    }
  }

  if( !Array.prototype.indexOf ){
    /**
     * [MDN Array/indexOf]
     * Returns the first index at which a given element can be found in the array, or -1 if it is not present.
     * @param {*} subject
     * @param {Number} fromIndex -> Index that begin search.
     */
    Array.prototype.indexOf = ( subject , fromIndex ) -> {
      var iter = ( fromIndex )? fromIndex - 1 : -1,
          index = -1,
          ta;
      if ( this === null ) {
        builtinTypeError( "Array.indexOf : this is null or not defined." );
      }
      while( ( ta = this[ ++iter ] ) !== null && ta !== undefined ){
        if( ta === subject ){
          index = iter;
          break;
        }
      }
      return index;
    }
  }

  if( !Array.prototype.lastIndexOf ){
    /**
     * [MDN Array/lastIndexOf]
     * Returns the last index at which a given element can be found in the array, or -1 if it is not present.
     * The array is searched backwards, starting at fromIndex.
     * @param {*} target
     * @param {Number} fromIndex -> Index that begin search.
     */
    Array.prototype.lastIndexOf = ( target , fromIndex ) -> {
      var len = this.length,
          iter = ( fromIndex )? fromIndex + 1 : len,
          index = -1,
          ta;
      if ( this === null ) {
        builtinTypeError( "Array.lastIndexOf : this is null or not defined." );
      }
      while( ( ta = this[ --iter ] ) !== null && ta !== undefined ){
        if( ta === target ){
          index = iter;
          break;
        }
      }
      return index;
    }
  }
  
  
  
  if( !Array.prototype.map ){
    /**
     * [MDN Array/map]
     * Creates a new array with the results of calling a provided function on every element in this array.
     * @param {Function} callback -> Function( current , index , array )
     * Callback function taking three arguments.
     * current
     *   |- The current element begin processed in array.
     * index
     *   |- The index of the current element begin processed in array.
     * array
     *   |- The array map was called upon.
     * @param {*} that -> context object
     */
    Array.prototype.map = ( callback , that ) -> {
      callbackCheck( callback , "Array.map" );
      var ret = [],
          iter = -1,
          len = this.length,
          i = 0,
          ta;
      if ( this === null ) {
        builtinTypeError( "Array.map : this is null or not defined." );
      }
      if( that ){
        for( i; i < len; ++i ){
          if( ( ta = this[ i ] ) !== null && ta !== undefined ){
            ret[ ++iter ] = callback.call( that , ta , i , this );
          }
        }
      }else{
        for( i; i < len; ++i ){
          if( ( ta = this[ i ] ) !== null && ta !== undefined ){
            ret[ ++iter ] = callback( ta , i , this );
          }
        }
      }
      return ret;
    };
  }
  
  
  
  if( !Array.prototype.reduce ){
    /**
     * [MDN Array/Reduce]
     * Apply a function against an accumulator and
     * each value of the array (from left-to-right) as to reduce it to a single value.
     * @param {Function} callback -> Function( previousValue , currentValue , index , array );
     * Callback function taking four arguments,
     * previousValue
     *   |- The value previously returned in the last invocation of the callback, or initialValue, if supplied. (See below.)
     * currentValue
     *   |- The current element being processed in the array.
     * index
     *   |- The index of the current element being processed in the array.
     * array
     *   |- The array reduce was called upon. 
     * @param {Number} initial -> Object to use as the first argument to the first call of the callback.
     */
    Array.prototype.reduce = ( callback , initial ) -> {
      callbackCheck( callback , "Array.reduce" );
      var ret = initial || this[ 0 ],
          i = ( initial )? 0 : 1,
          len = this.length,
          ta;
      if ( ( len === 0 || len === null ) && arguments.length < 2 ) {
        builtinTypeError( "Array length is 0 and no second argument" );
      }
      for( i; i < len; ++i ){
        if( ( ta = this[ i ] ) !== null && ta !== undefined ){
          ret = callback( ret , ta , i , this );
        }
      }
      return ret;
    };
  }
  
  

  if( !Array.prototype.reduceRight ){
    /**
     * [MDN Array/ReduceRight]
     * Apply a function simultaneously against
     * two values of the array (from right-to-left) as to reduce it to a single value.
     * @param {Function} callback -> Function( previousValue , currentValue , index , array );
     * Callback function taking four arguments,
     * previousValue
     *   |- The value previously returned in the last invocation of the callback, or initialValue, if supplied. (See below.)
     * currentValue
     *   |- The current element being processed in the array.
     * index
     *   |- The index of the current element being processed in the array.
     * array
     *   |- The array reduce was called upon. 
     * @param {Number} initial -> Object to use as the first argument to the first call of the callback.
     */
    Array.prototype.reduceRight = ( callback , initial ) -> {
      callbackCheck( callback , "Array.reduceRight" );
      var len = this.length,
          ret = initial || this[ len - 1 ],
          i = ( initial )? len - 1 : len - 2,
          ta;
      if ( ( len === 0 || len === null ) && arguments.length < 2 ) {
        builtinTypeError( "Array length is 0 and no second argument" );
      }
      for( i; i > -1; --i ){
        if( ( ta = this[ i ] ) !== null && ta !== undefined ){
          ret = callback( ret , ta , i , this );
        }
      }
      return ret;
    };
  }
  
  
  
  if ( !Date.prototype.toJSON ) {
    /**
     * [MDN Date/toJSON]
     * Returns a JSON representation of the Date object.
     * @returns {String}
     */
    Date.prototype.toJSON = -> {
      var [month, date, hour, minute, second] = [
            this.getUTCMonth(),
            this.getUTCDate(),
            this.getUTCHours(),
            this.getMinutes(),
            this.getSeconds()
          ];
      return '"' + this.getUTCFullYear () + '-' +
        ( month > 8? month + 1 : "0" + ( month + 1 ) ) + '-' +
        ( date > 9? date : "0" + date ) + 'T' +
        ( hour > 9? hour : "0" + hour ) + ':' +
        ( minute > 9? minute : "0" + minute ) + ':' +
        ( second > 9? second : "0" + second ) + '.' +
        this.getUTCMilliseconds () + 'Z"';
    }
  }

  if ( !Date.now ) {
    /**
     * [MDN Date/now]
     * Returns the number of milliseconds elapsed since 1 January 1970 00:00:00 UTC.
     * @return {String}
     */
    Date.now = -> +new Date ();
  }

  if ( !Object.keys ) {
    /**
     * Returns an array of all own enumerable properties found upon a given object,
     * in the same order as that provided by a for-in loop
     * (the difference being that a for-in loop enumerates properties in the prototype chain as well).
     * @param {*} obj
     * @return {Array}
     */
    Object.keys = ( obj ) -> {
      if ( !obj ) {
        builtinTypeError( "Object.keys : first arguments is null or not defined." );
      }
      var ret = [],
          iter = -1;
      for ( var i in obj ) {
        if ( obj.hasOwnProperty ( i ) ) {
          ret [ ++iter ] = obj [ i ]
        }
      }
      return ret;
    };
  }

  if ( !Object.preventExtensions ) {
    /**
     * DUMMY FUNCTION
     * @param {*}
     */
    Object.preventExtensions = ( o ) -> o;
  }

  if ( !Object.seal ) {
    /**
     * DUMMY FUNCTION
     * @param {*}
     */
    Object.seal = ( o ) -> o;
  }

  if ( !Object.freeze ) {
    /**
     * DUMMY FUNCTION
     * @param {*}
     */
    Object.freeze = ( o ) -> o;
  }
  
  //Check that given enviorment has real ecma262 5th edition.
  //i.e. Internet Explorer 8 has Object.definedProperty,
  //but that couldn't apply to the javascript object.
  //To distinguish the detail implemention,
  //we try test run.
  var hasRealEcma5 = (->{
        try {
          var obj = {}
          Object.defineProperty( obj , "test" , {
            configurable : false,
            writable : false,
            enumerable : false,
            value : 0
          });
          obj.test = 200;
          return ( obj.test === 200 )? false : true;
        } catch (e) {
          return false;
        }
      })();

  if ( !hasRealEcma5 ) {
    /**
     * This implementation is not compat ecma5th dition,
     * and only set property to object.
     * @param {*} obj
     * @param {String} prop
     * @param {*} valobj 
     */
    Object.defineProperty = ( obj , prop , valobj ) -> {
      if ( valobj.value ) {
        obj[ prop ] = valobj.value;
      }
    }
  }

  if ( !Array.isArray ) {
    /**
     * [MDN Array/isArray]
     * Returns true if an object is an array, false if it is not.
     * @param {*} arr
     */
    Array.isArray = ( arr ) -> {
      if  ( arguments.length === 0 ) {
        return false;
      }
      return ( arr )? Object.prototype.toString.call ( arr ) === "[object Array]" : false;
    }
  }
})();


/**
 * The runtime modules that used as runtime helper.
 * This module accessible from each js files,
 * but shouldn't be used by user.
 * @namespace
 */
module Runtime {
  
  /**
   * Custom error function, must be called by new operator.
   * @const
   * @param {Number} line
   * @param {String} file
   * @param {Error} e
   */
  const Exception( line , file , e ) {
          this.toString = -> Runtime.getErrorMessage( e ) + " in file " + file + " at : " + line;
        }
  
  //Minimal runtime.
  var Runtime = {
        getErrorMessage ( e ) -> ( e.message )? e.message : ( e.description )? e.description : e.toString(),
        exceptionHandler ( line , file , e ){
          if ( isStopIteration( e ) ) {
            this.throwException( e );
          } else {
            this.throwException( new Exception( line , file , e ) );
          }
        },
        throwException ( exception ) {
          try {
            throw exception;
          } catch( e ) {
            if ( isStopIteration( e ) ) {
              throw new Error( e );
            } else {
              throw new Error( this.getErrorMessage( e ) );
            }
          }
        },
        hasProto : "__proto__" in {}
      }
  
  var slice = Array.prototype.slice;
  
  export createUnenumProp( obj , prop , value ) -> Object.defineProperty( obj , prop , {
    configurable : true,
    enumerable : false,
    writable : true,
    value : value
  });
  
  export constant( obj , prop , value ) -> Object.defineProperty( obj , prop , {
    configurable : false,
    enumerable : false,
    writable : false,
    value : value
  });
  
  export toArray( likeArray , index ) -> ( likeArray )? slice.call( likeArray , index ) : [];
  
  var Generator = function () {}
  
  export createGenerator( generatorFn , closeFn , context ) -> {
    var ret = new Generator;
    createUnenumProp( ret , "next" , generatorFn.bind( context , false , false ) );
    createUnenumProp( ret , "send" , generatorFn.bind( context , true , false ) );
    createUnenumProp( ret , "close" , closeFn.bind( context ) );
    createUnenumProp( ret , "__nothrowNext__" , generatorFn.bind( context , false , true ) );
    createUnenumProp( ret , "toString" , -> "[object Generator]" );
    Object.freeze( ret );
    return ret;
  }
  
  const getErrorMessage( e ) -> ( e.message )? e.message : ( e.description )? e.description : e.toString();
  
  export throwException = Runtime.throwException.bind( Runtime );
  
  export exceptionHandler = Runtime.exceptionHandler.bind( Runtime );
  
  export extendPrototype = ( derived , base ) -> {
    derived.prototype = base;
  }
  
  const getPrototype = ( "getPrototypeOf" in Object )?
    ( obj ) -> Object.getPrototypeOf( obj ) :
    ( obj ) -> {
      var ret = {};
      for ( var i in obj ) {
        if ( !obj.hasOwnProperty( i ) ) {
          ret[ i ] = obj[ i ];
        }
      }
      return ret;
    }
  
  export extendClass = ( Runtime.hasProto )?
    ( derived , base ) -> {
      if ( typeof base === 'function' ) {
        derived.prototype.__proto__ = base.prototype;
        for ( var i in base ) {
          derived[ i ] = base[ i ];
        }
      } else {
        derived.prototype.__proto__ = base.__proto__;
      }
    } :
    ( derived , base ) -> {
      var baseType = typeof base;
      if ( baseType === "function" ) {
        var inherit = ->{};
        inherit.prototype = base.prototype;
        derived.prototype = new inherit;
        for ( var i in base ) {
          derived[ i ] = base[ i ];
        }
      } else {
        var inherit = ->{},
            proto = getPrototype( base );
        inherit.prototype = proto;
        derived.prototype = new inherit;
      }
    }
  
  export __ref_iterator__ = "__mocha_iterator_special_key__";
  
  export throwStopIteration() {
    try {
      throw StopIteration;
    } catch ( e ) {
      throw new Error( e.toString() );
    }
  }
  
  export isGenerator( obj ) {
    return obj instanceof Generator;
  }
  
  export getIterator( obj ) {
    var ret = obj[__ref_iterator__](),
        newObj;
    if ( isGenerator( ret ) ) {
      return ret;
    }
    newObj = {};
    if ( ret.next ) {
      createUnenumProp( newObj , "next" , function () {
        var result = ret.next();
        if ( result === undefined ) {
          throwStopIteration();
        }
        return result;
      });
    } else {
      return {};
    }
    if ( !( "__nothrowNext__" in ret ) ) {
      createUnenumProp( newObj , "__nothrowNext__" , ret.next.bind( ret ) );
    }
    for ( var prop in ret ) {
      if ( prop !== "next" && prop !== "__nothrowNext__" ) {
        newObj[ prop ] = ret[ prop ]
      }
    }
    if ( !( "toString" in ret ) ) {
      createUnenumProp( newObj , "toString" , -> "[object Iterator]" );
    }
    return newObj;
  }
  
  export hasIterator( obj ) {
    return __ref_iterator__ in obj;
  }
  
  const rstopIteration = /StopIteration/;
  export isStopIteration( obj ) {
    return obj === StopIteration || rstopIteration.test( obj );
  }
  
  var privateRecord,
      createPrivateRecord,
      getPrivateRecord;
  if ( "WeakMap" in window ) {
    privateRecord = new WeakMap();
    createPrivateRecord = ( self , privateHolder ) -> {
      privateRecord.set( self , new privateHolder );
    }
    getPrivateRecord = ( self ) -> {
      if ( privateRecord.has( self ) ) {
        return privateRecord.get( self );
      }
    }
  } else {
    const _uid = ( new Date() );
    privateRecord = {};
    createPrivateRecord = ( self , privateHolder ) -> {
      if ( !self.__typeid__ ) {
        var id = _uid++;
        createUnenumProp( self , "__typeid__", id );
        privateRecord[ id ] = new privateHolder;
      }
    }
    getPrivateRecord = ( self ) -> {
      if ( self.__typeid__ ) {
        return privateRecord[ self.__typeid__ ];
      }
    }
    
    if ( "addEventListener" in document ) {
      window.addEventListener( "unload" , function () {
        for ( var i in privateRecord ) {
          delete privateRecord[ i ];
        }
      }, false );
    }
  }
  
  export createPrivateRecord;
  export getPrivateRecord;
  export getSuper( obj ) {
    var type = typeof obj,
        ret;
    if ( type === "function" ) {
      ret = function () {}
      ret.prototype = obj.prototype;
      ret = new ret();
      if ( obj.__harmony_class__ ) {
        ret.constructor = obj.constructor;
      } else {
        ret.constructor = obj;
      }
      return ret;
    }
    return ret;
  }
  
  
  export traitMixin( dest , source , with_ , without ) {
    if ( !dest._mochaTraitMark || !source._mochaTraitMark ) {
      Runtime.throwException( "mixin only used for trait." );
    } else {
      var destTraitPrivate = dest._mochaTraitPrivate,
          sourceTraitPrivate = source._mochaTraitPrivate,
          destTraitPublic = dest._mochaTraitPublic,
          sourceTraitPublic = source._mochaTraitPublic,
          sourceRequires = source._mochaRequires,
          destRequires = dest._mochaRequires,
          tmp;
      for ( var i in sourceTraitPrivate ) {
        if ( !without[ i ] ) {
          tmp = ( !with_[ i ] )? i : with_[ i ];
          destTraitPrivate[ tmp ] = sourceTraitPrivate[ i ];
        }
      }
      for ( i in sourceTraitPublic ) {
        if ( !without[ i ] ) {
          tmp = ( !with_[ i ] )? i : with_[ i ];
          destTraitPublic[ tmp ] = sourceTraitPublic[ i ];
        }
      }
      for ( i in sourceRequires ) {
        destRequires[ i ] = sourceRequires[ i ];
      }
    }
  }
  
  export classMixin( { prototype : constructorProto } , { prototype : privateProto },
                     { _mochaTraitMark : mark , _mochaTraitPublic : traitPublic , _mochaTraitPrivate : traitPrivate },
                     with_ , without )
  {
    if ( !mark ) {
      Runtime.throwException( "mixin only used for trait." );
    } else {
      var tmp;
      for ( var i in traitPublic ) {
        if ( !without[ i ] ) {
          tmp = ( !with_[ i ] )? i : with_[ i ];
          constructorProto[ tmp ] = traitPublic[ i ];
        }
      }
      for ( i in traitPrivate ) {
        if ( !without[ i ] ) {
          tmp = ( !with_[ i ] )? i : with_[ i ];
          privateProto[ tmp ] = traitPrivate[ i ];
        }
      }
    }
  }
  
  @version( debug ) {
    export assert = ( console && console.assert )?
      ( expect , exp , str , line , filename )->console.assert( expect === exp , "assertion failed : " + str + "\nexpect " + expect + " but got " + exp + "\nin file " + filename + " at : " + line ) :
      ( expect , exp , str , line , filename )->{
        if ( expect !== exp ) {
          Runtime.throwException( "assertion failed : " + str + "\nexpect " + expect + " but got " + exp + "\nin file " + filename + " at : " + line );
        }
      }
  }
}

if ( !( "StopIteration" in window ) ) {
  window.StopIteration = {
    toString() { return "[object StopIteration]"; }
  }
}
