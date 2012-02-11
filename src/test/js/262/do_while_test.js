var testvalue = 9;
var table = ['a','b','c','d','e','f','g','h','i','j'];
var ret = [];
do {
  ret.push( table[ testvalue ] );
} while( testvalue-- );

@assert( true , ret[ 0 ] === 'j' );
@assert( true , ret[ 1 ] === 'i' );
@assert( true , ret[ 2 ] === 'h' );
@assert( true , ret[ 3 ] === 'g' );
@assert( true , ret[ 4 ] === 'f' );
@assert( true , ret[ 5 ] === 'e' );
@assert( true , ret[ 6 ] === 'd' );
@assert( true , ret[ 7 ] === 'c' );
@assert( true , ret[ 8 ] === 'b' );
@assert( true , ret[ 9 ] === 'a' );

testvalue = 9;
ret = [];
do ret.push( table[ testvalue ] );
  while ( testvalue-- );

@assert( true , ret[ 0 ] === 'j' );
@assert( true , ret[ 1 ] === 'i' );
@assert( true , ret[ 2 ] === 'h' );
@assert( true , ret[ 3 ] === 'g' );
@assert( true , ret[ 4 ] === 'f' );
@assert( true , ret[ 5 ] === 'e' );
@assert( true , ret[ 6 ] === 'd' );
@assert( true , ret[ 7 ] === 'c' );
@assert( true , ret[ 8 ] === 'b' );
@assert( true , ret[ 9 ] === 'a' );

