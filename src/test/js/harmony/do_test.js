var testvalue = do {
      var x = 0;
      x;
    }

var testvalue2 = do {
      var x = 0;
      if x == 0 {
        var m = 1;
        m;
      } else {
        x;
      }
      var v = 100;
    }

var testError = do {
      try {
        m();
      } catch(e) {
        e
      }
    }

var testvalue3 = do {
      var [m] = [1,2,3,4];
    }

@assert(true, testvalue === 0);
@assert(true, testvalue2 === 1);
