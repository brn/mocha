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
    if ('iterator' in obj) {
      var ret = obj.iterator();
      if (@isGenerator(ret)) {
        return ret;
      }
      if (ret.next) {
        var next = ret.next.bind(ret);
        @createUnenumProp(ret, "next", function (nothrow) {
          var result = next();
          if (result === __Runtime._NULL && !nothrow) {
            @throwStopIteration();
          }
          return result;
        });
      } else {
        return @getIterator(ret);
      }
      if (!("__nothrowNext__" in ret)) {
        @createUnenumProp(ret, "__nothrowNext__", ret.next.bind(ret, true));
      }
      if (!("toString" in ret)) {
        @createUnenumProp(ret, "toString", -> "[object Iterator]");
      }
    } else if (@isGenerator(obj)) {
      return obj;
    } else if (typeof obj === 'object'){
      if Object.prototype.toString.call(obj) === '[object Object]' {
        var ret = [];
        for (var i in obj) {
          ret.push(i);
        }
        obj = ret;
      }
      return {
        __index : 0,
        __nothrowNext__ -> {
          var ret = obj[this.__index];
          this.__index++
          if (this.__index > obj.length) {
            this.__index = 0;
            return __Runtime._NULL;
          } else {
            return ret;
          }
        }
      }
    } else {
      return {__nothrowNext__-> {return __Runtime._NULL;}}
    }
    return ret;
  }
};

if (!("StopIteration" in __Runtime._global)) {
  __Runtime._global.StopIteration = {
    toString() -> "[object StopIteration]"
  }
}
