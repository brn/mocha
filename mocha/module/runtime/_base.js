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
var global = (this !== null)?this : typeof window === 'object'? window : {};

/**
 * The runtime modules that used as runtime helper.
 * This module accessible from each js files,
 * but shouldn't be used by user.
 * @namespace
 */
var __Runtime = {
      _global : global,
      _push : Array.prototype.push,
      _slice : Array.prototype.slice,
      getErrorMessage (e) -> (e.message)? e.message : (e.description)? e.description : e.toString(),
      isStopIteration : do {
        const rstopIteration = /StopIteration/;
        isStopIteration( obj ) -> obj === __Runtime.StopIteration || rstopIteration.test( obj );
        isStopIteration;
      },
      
      throwException (exception) {
        try {
          throw exception;
        } catch(e) {
          if (__Runtime.isStopIteration(e)) {
            throw new Error(e);
          } else {
            throw new Error(this.getErrorMessage(e));
          }
        }
      },
      
      createUnenumProp(obj, prop, value) -> Object.defineProperty(obj, prop, {
        configurable : true,
        enumerable : false,
        writable : true,
        value : value
      }),
      
      constant(obj, prop, value) -> Object.defineProperty(obj, prop, {
        configurable : false,
        enumerable : false,
        writable : false,
        value : value
      }),
      
      toArray(likeArray, index) -> (likeArray)? this._slice.call(likeArray, index) : [],
      
      extend(dest, source) {
        for (var prop in source) {
          dest[ prop ] = source[ prop ];
        }
        return dest;
      }
    }

