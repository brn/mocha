if( !Function.prototype.bind ){
  Function.prototype.bind = -> {
    var argArray = 0,
        ret = ->{
          var args = 0;
        }
    return ret;
  }
}

var i  =0;
for ( i = 0; i < 200; i++ ) {
  consol.log(i);
}
var m = 10
while ( m-- ) {
  console.log( m );
}
var v = function () { return 200; },
    v2 = function ( [a,{b},...rest] , y ) { return 400; }

const testConst() {
        return 300;
      }
testFn( {x:[a,b,c],z} )->{ return 200};
const m = ({x},{y},{z})->{return 200};
var {test2 : {x},test,v:[a,b,c]} = {test2:300};
var testObject = {
      a,
      b->200
    }
