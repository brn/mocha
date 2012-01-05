
var x = function () {
      for( var i = 0; i < 200; i++ ) {
        for ( var j = 0; j < 200; j++ ){
          var {x} = {x:300};
          var m = 200;
          yield i;
        }
      }
      for ( var l = 0; l < 20; l++ ) {
        yield l;
      }
      yield 200;
    }
