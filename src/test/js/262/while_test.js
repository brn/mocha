var testvalue = 0;
var table = ['a','b','c','d','e','f','g','h','i','j'];
var ret = [];
while ( testvalue < 10 ) {
  ret.push( table[ testvalue++ ] );
}
@assert( true , ret[ 0 ] === 'a' );
@assert( true , ret[ 1 ] === 'b' );
@assert( true , ret[ 2 ] === 'c' );
@assert( true , ret[ 3 ] === 'd' );
@assert( true , ret[ 4 ] === 'e' );
@assert( true , ret[ 5 ] === 'f' );
@assert( true , ret[ 6 ] === 'g' );
@assert( true , ret[ 7 ] === 'h' );
@assert( true , ret[ 8 ] === 'i' );
@assert( true , ret[ 9 ] === 'j' );

testvalue = 0;
ret = [];
while ( testvalue < 10 )
  ret.push( table[ testvalue++ ] );

@assert( true , ret[ 0 ] === 'a' );
@assert( true , ret[ 1 ] === 'b' );
@assert( true , ret[ 2 ] === 'c' );
@assert( true , ret[ 3 ] === 'd' );
@assert( true , ret[ 4 ] === 'e' );
@assert( true , ret[ 5 ] === 'f' );
@assert( true , ret[ 6 ] === 'g' );
@assert( true , ret[ 7 ] === 'h' );
@assert( true , ret[ 8 ] === 'i' );
@assert( true , ret[ 9 ] === 'j' );