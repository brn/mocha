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
Runtime.{
  Generator()->{},
  createGenerator(generatorFn, closeFn, context) -> {
    var ret = new this.Generator;
    @createUnenumProp(ret, "next", generatorFn.bind(context, false, false));
    @createUnenumProp(ret, "send", generatorFn.bind(context, true, false));
    @createUnenumProp(ret, "close", closeFn.bind(context));
    @createUnenumProp(ret, "__nothrowNext__", generatorFn.bind(context, false, true));
    @createUnenumProp(ret, "toString", -> "[object Generator]");
    Object.freeze(ret);
    return ret;
  },
  
  throwStopIteration() {
    try {
      throw StopIteration;
    } catch (e) {
      throw new Error(e.toString());
    }
  },

  isGenerator(obj) -> obj instanceof @Generator,

  getIterator(obj) {
    var ret = obj.iterator(),
        newObj;
    if (@isGenerator(ret)) {
      return ret;
    }
    newObj = {};
    if ( ret.next ) {
      @createUnenumProp(newObj, "next", function () {
        var result = ret.next();
        if ( result === undefined ) {
          @throwStopIteration();
        }
        return result;
      });
    } else {
      return {};
    }
    if ( !( "__nothrowNext__" in ret ) ) {
      @createUnenumProp( newObj , "__nothrowNext__" , ret.next.bind( ret ) );
    }
    for ( var prop in ret ) {
      if ( prop !== "next" && prop !== "__nothrowNext__" ) {
        newObj[ prop ] = ret[ prop ]
      }
    }
    if ( !( "toString" in ret ) ) {
      @createUnenumProp( newObj , "toString" , -> "[object Iterator]" );
    }
    return newObj;
  },

  hasIterator( obj ) -> 'iterator' in obj 
};

if (!("StopIteration" in Runtime._global)) {
  Runtime._global.StopIteration = {
    toString() -> "[object StopIteration]"
  }
}
