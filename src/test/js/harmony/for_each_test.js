var m;
var target = {m:200,g:200}
var each = function () {};
for each ( var i in target ) {
  console.log(i)
}

for each ( i in target ) {
  console.log(i)
}

for each ( var i in target )
  console.log(i);

for each ( i in target )
  console.log(i);

for each ( m.g.i in target ) {
  console.log(m.g.i);
}