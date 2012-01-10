
var privateName = new Date();
var testObj = {
      m : {
        [privateName] : {
          v : {
            [privateName] : 20
          }
        }
      }
    }

var m = function () {
      if ( window ) {
        for (var i = 0; i < 10; i ++) {
          yield i
        }
      } else  {
        for (var m = 0; m < 10; m ++) {
        yield m
        }
      }
    }

var x = function () {
      for( var i = 0; i < 200; i++ ) {
        try {
          yield i
          var j = 0;
          while( j < 100 ){
            var {x} = {x:300};
            var m = yield 200;
            yield j;
            j++
          }
        }catch(e) {
        }finally{
          console.log(100);
        }
      }
      for ( var l = 0; l < 20; l++ ) {
        yield l;
      }
      yield 200;
    }
for ( var m of x() ) {
  console.log(m);
}