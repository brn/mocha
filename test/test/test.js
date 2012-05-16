var x = 100;

@version(compilation_test) {
  (function () {})();
}

var array = [0,1,2,3,4,5,6,7,8,9,10],
    test = -> {
      for (var i = 0; i < 10; i++) {
        if i % 2 === 0 {
          yield i;
        }
      }
    },
    test2 = (x for (x in __Runtime)),
    it = {
      iterator -> {
        var values = [0,1,2,3,4,5,6,7,8,9,10],
            index = 0;
            return {
              next -> {
                var ret = values[index];
                index++;
                if (index > values.length) {
                  throw StopIteration;
                }
                return ret;
              }
            }
      }
    }
for (var value of it) {
  console.log(value);
}
