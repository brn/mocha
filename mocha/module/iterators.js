module iterators {
  const hasOwn = Object.prototype.hasOwnProperty;
  export iterator = "__mocha_iterator_special_key__";
  export keys(obj) {
    return {
      [iterator] : -> -> {
        for (var x in obj) {
          if (hasOwn.call(obj, x))
            yield x;
        }
      }()
    };
  }
  
  export values(obj) {
    return {
      [iterator]: -> -> {
        for (var x in obj) {
          if (hasOwn.call(obj, x))
            yield obj[x];
        }
      }()
    };
  }
  
  export items(obj) {
    return {
      [iterator]: -> -> {
        for (var x in obj) {
          if (hasOwn.call(obj, x))
            yield [x, obj[x]];
        }
      }()
    };
  }
  export allKeys(obj) {
    return {
      [iterator]: -> -> {
        for (var x in obj)
          yield x;
      }()
    };
  }
  export allValues(obj) {
    return {
      [iterator]: -> -> {
        for (var x in obj)
          yield obj[x];
      }()
    };
  }
  export allItems(obj) {
    return {
      [iterator]: -> -> {
        for (var x in obj)
          yield [x, obj[x]];
      }()
    };
  }
  
}