import iterator from "iterators".iterator;
 
@pragma( __debug )
var name = Math.random();
var m = {
      [name] : {
        v : {
          [name] : {
            g : {
              g : function (){}
            }
          },
          gd : {}
        }
      }
    }

var ret = [ [i,j] for (i of rows) for (j of columns) ];
var x = {xa:200,ya:200};
x.{ret,m,name}
/*var privateName = new Date();
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
var [ig,vg] = {x,y};
var m = {v:200,g:300}
var i = allItems( m );
for ( var [item,val] of i ) {
  console.log(item , val);
}
*/