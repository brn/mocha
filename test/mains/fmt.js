
var x = function () {
      for( var i = 0; i < 200; i++ ) {
        for ( var j = 0; j < 200; j++ ){
          yield i;
        }
      }
      yield 200;
    }
