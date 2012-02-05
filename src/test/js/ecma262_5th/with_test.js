var m = {v:{v:200 }}
with( m ) {
  console.log( v );
}

var x = [];
for( var i = 0;i < 0; i++ ) {
  with( {i:i} ) {
    x.push(function () { console.log(i); });
  }
}