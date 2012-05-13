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
do {
  const getPrototype = ("getPrototypeOf" in Object)?
    (obj) -> Object.getPrototypeOf(obj) :
    (obj) -> {
      var ret = {};
      for (var i in obj) {
        if (!obj.hasOwnProperty(i)) {
          ret[ i ] = obj[ i ];
        }
      }
      return ret;
    }
  
  var privateRecord,
      createPrivateRecord,
      getPrivateRecord,
      getInstanceBody;
  if ("WeakMap" in __Runtime._global) {
    privateRecord = new WeakMap();
    createPrivateRecord = (self, privateHolder, constructor) -> {
      var holder = new privateHolder;
      __Runtime.createUnenumProp(holder, "__is_private__", 1);
      Rutnime.createUnenumProp(self, "constructor", constructor);
      privateRecord.set(self, holder);
      privateRecord.set(holder, self);
    }
    getPrivateRecord = (self) -> {
      if (privateRecord.has(self)) {
        return privateRecord.get(self);
      } else if (self.__is_private__ === 1) {
        return self;
      }
    }
    getInstanceBody = (privateHolder) -> {
      return privateRecord.get(privateHolder);
    }
  } else {
    createPrivateRecord = (self, privateHolder, constructor) -> {
      if (!self.__typeid__) {
        var holder = new privateHolder,
            privateSlot = {};
        Object.defineProperty(privateSlot, "__is_private__", {value : 1});
        Object.defineProperty(privateSlot, "__parent__", {value : self});
        Object.defineProperty(holder, "constructor", {value : privateSlot});
        __Runtime.createUnenumProp(constructor, "__private__", holder);
        __Runtime.createUnenumProp(self, "constructor", constructor);
      }
    }
    getPrivateRecord = (self) -> {
      if (self.constructor.__private__) {
        return self.constructor.__private__;
      } else if (self.constructor.__is_private__ === 1) {
        return self;
      }
    }
    getInstanceBody = (privateHolder) -> {
      return privateHolder.constructor.__parent__;
    }
  }
  
  var hasProto = '__proto__' in {};
  
  __Runtime.{
    extendClass : (hasProto)?
      (derived, base) -> {
        if typeof base === 'function' {
          derived.prototype.__proto__ = base.prototype;
          for (var i in base) {
            //for webkit.
            //in webkit, for in loop is enumerate prototype, if __proto__ property is manipurated.
            if (i !== 'prototype') {
              derived[ i ] = base[ i ];
            }
          }
        } else {
          derived.prototype.__proto__ = base.__proto__;
        }
      } :
    (derived, base) -> {
      var baseType = typeof base;
      if baseType === "function" {
        var inherit = ->{};
        inherit.prototype = base.prototype;
        derived.prototype = new inherit;
        for (var i in base) {
          //for webkit.
          //in webkit, for in loop is enumerate prototype, if __proto__ property is manipurated.
          if (i !== 'prototype') {
            derived[ i ] = base[ i ];
          }
        }
      } else {
        var inherit = ->{},
            proto = getPrototype(base);
        inherit.prototype = proto;
        derived.prototype = new inherit;
      }
    },
    extendPrototype( derived , base ) -> {
      derived.prototype = base;
    },
    getPrivateRecord,
    getInstanceBody,
    initializeClass(instance, classObject, privateHolder, constructor, args, name, line) {
      if (!instance || !(instance instanceof classObject)) {
        throwException("class " + name + " must be called by new. line : " + line);
      }
      createPrivateRecord(instance, privateHolder, constructor);
      constructor.apply(instance, args);
    },
    getSuper(obj) {
      var type = typeof obj,
          ret;
      if (type === "function") {
        ret = function () {}
        ret.prototype = obj.prototype;
        ret = new ret();
        if (obj.__harmony_class__) {
          ret.constructor = obj.constructor;
        } else {
          ret.constructor = obj;
        }
        return ret;
      }
      return ret;
    }
  };
}