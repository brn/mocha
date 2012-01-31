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
    v2 = function ( {x} , y ) { return 400; }
