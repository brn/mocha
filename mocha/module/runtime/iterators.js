module {
  const call = Function.prototype.call.bind(Function.prototype.call);
  const hasOwn = Object.prototype.hasOwnProperty;
  export iterator = "__iterator__";
  export keys(obj) {
    return {
      [iterator] : function() {
        return (function() {
          for (var x in obj) {
            if (call(hasOwn, obj, x))
              yield x;
          }
        })();
      }
    };
  }
  export values(obj) {
    return {
      [iterator]: function() {
        return (function() {
          for (var x in obj) {
            if (call(hasOwn, obj, x))
              yield obj[x];
          }
        })();
      }
    };
  }
  export items(obj) {
    return {
      [iterator]: function() {
        return (function() {
          for (var x in obj) {
            if (call(hasOwn, obj, x))
              yield [x, obj[x]];
          }
        })();
      }
    };
  }
  export allKeys(obj) {
    return {
      [iterator]: function() {
        return (function() {
          for (var x in obj)
            yield x;
        })();
      }
    };
  }
  export allValues(obj) {
    return {
      [iterator]: function() {
        return (function() {
          for (var x in obj)
            yield obj[x];
        })();
      }
    };
  }
  export allItems(obj) {
    return {
      [iterator]: function() {
        return (function() {
          for (var x in obj)
            yield [x, obj[x]];
        })();
      }
    };
  }
}