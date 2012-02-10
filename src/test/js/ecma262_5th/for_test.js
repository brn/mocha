var target = [ 'a','b','c','d','e','f','g','h','i','j' ];
var arr = [];
for ( var i = 0; i < 10; i++ ) {
  arr.push( target[ i ] );
}
@assert( true , arr[ 0 ] === 'a' );
@assert( true , arr[ 1 ] === 'b' );
@assert( true , arr[ 2 ] === 'c' );
@assert( true , arr[ 3 ] === 'd' );
@assert( true , arr[ 4 ] === 'e' );
@assert( true , arr[ 5 ] === 'f' );
@assert( true , arr[ 6 ] === 'g' );
@assert( true , arr[ 7 ] === 'h' );
@assert( true , arr[ 8 ] === 'i' );
@assert( true , arr[ 9 ] === 'j' );

arr = [];
for (  i = 0; i < 10; i++ ) {
  arr.push( target[ i ] );
}
@assert( true , arr[ 0 ] === 'a' );
@assert( true , arr[ 1 ] === 'b' );
@assert( true , arr[ 2 ] === 'c' );
@assert( true , arr[ 3 ] === 'd' );
@assert( true , arr[ 4 ] === 'e' );
@assert( true , arr[ 5 ] === 'f' );
@assert( true , arr[ 6 ] === 'g' );
@assert( true , arr[ 7 ] === 'h' );
@assert( true , arr[ 8 ] === 'i' );
@assert( true , arr[ 9 ] === 'j' );

i = 0;
for ( ;; ) {
  arr.push( target[ i ] );
  i++;
  if ( i === 10 ) break;
}
@assert( true , arr[ 0 ] === 'a' );
@assert( true , arr[ 1 ] === 'b' );
@assert( true , arr[ 2 ] === 'c' );
@assert( true , arr[ 3 ] === 'd' );
@assert( true , arr[ 4 ] === 'e' );
@assert( true , arr[ 5 ] === 'f' );
@assert( true , arr[ 6 ] === 'g' );
@assert( true , arr[ 7 ] === 'h' );
@assert( true , arr[ 8 ] === 'i' );
@assert( true , arr[ 9 ] === 'j' );

i = 9;
for ( i; i; ) {
  arr.push( target[ i ] );
  i--;
}
@assert( true , arr[ 0 ] === 'a' );
@assert( true , arr[ 1 ] === 'b' );
@assert( true , arr[ 2 ] === 'c' );
@assert( true , arr[ 3 ] === 'd' );
@assert( true , arr[ 4 ] === 'e' );
@assert( true , arr[ 5 ] === 'f' );
@assert( true , arr[ 6 ] === 'g' );
@assert( true , arr[ 7 ] === 'h' );
@assert( true , arr[ 8 ] === 'i' );
@assert( true , arr[ 9 ] === 'j' );