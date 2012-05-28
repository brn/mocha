var target = {
      value1 : 100,
      value2 : 200,
      value3 : 300,
      value4 : 400
    }
var arr = [];
for ( var i in target ) {
  arr.push( target[ i ] );
}
@assert( true , arr[ 0 ] === 100 );
@assert( true , arr[ 1 ] === 200 );
@assert( true , arr[ 2 ] === 300 );
@assert( true , arr[ 3 ] === 400 );

arr = [];
for( i in target ) {
  arr.push( target[ i ] );
}
@assert( true , arr[ 0 ] === 100 );
@assert( true , arr[ 1 ] === 200 );
@assert( true , arr[ 2 ] === 300 );
@assert( true , arr[ 3 ] === 400 );

arr = [];
for( var i in target )
  arr.push( target[ i ] )
@assert( true , arr[ 0 ] === 100 );
@assert( true , arr[ 1 ] === 200 );
@assert( true , arr[ 2 ] === 300 );
@assert( true , arr[ 3 ] === 400 );

arr = [];
for( i in target )
  arr.push( target[ i ] )
@assert( true , arr[ 0 ] === 100 );
@assert( true , arr[ 1 ] === 200 );
@assert( true , arr[ 2 ] === 300 );
@assert( true , arr[ 3 ] === 400 );

var index = { prop : "" }
arr = [];
for ( index.prop in target ) {
  arr.push( target[index.prop] );
}
@assert( true , arr[ 0 ] === 100 );
@assert( true , arr[ 1 ] === 200 );
@assert( true , arr[ 2 ] === 300 );
@assert( true , arr[ 3 ] === 400 );