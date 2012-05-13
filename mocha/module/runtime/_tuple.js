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

__Runtime.{
  TupleConstructor : do {
    TupleConstructor(args) -> {
      __Runtime._push.apply(this, args);
      Object.freeze(this);
    }
    TupleConstructor.prototype = {
      compareTuple(tuple) -> {
        var maxIndex = max(tuple.length, this.length),
            i = -1;
        while (++i < maxIndex && tuple[ i ] === this[ i ]){}
        return maxIndex === i;
      },
      tupleToArray -> __Runtime._slice.call(this),
      toString -> "[object Tuple]"
    }
    TupleConstructor;
  }
};

Tuple(...args) -> new __Runtime.TupleConstructor(args);
Tuple.prototype = __Runtime.TupleConstructor.prototype;

