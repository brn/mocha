
var privateName = new Date();
var testObj = {
      m : {
        [privateName] : {
          v : {
            [privateName] : 20
          }
        }
      },
      test : {
        [Math.random()] : 200
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

var m = {v:200,g:300}
var i = iterator.allItems( m );
for ( var [item,val] of i ) {
  console.log(item , val);
}
