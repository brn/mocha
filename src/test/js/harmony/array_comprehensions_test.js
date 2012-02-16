import {items} from "iterators";

var testTarget = {
      value1 : 100,
      value2 : 200,
      value3 : 300
    }

var cmpTest = [ prop for each ( prop in testTarget ) ];
@assert( true , cmpTest[ 0 ] === 100 );
@assert( true , cmpTest[ 1 ] === 200 );
@assert( true , cmpTest[ 2 ] === 300 );

cmpTest = [ prop for ( prop in testTarget ) ];
@assert( true , cmpTest[ 0 ] === "value1" );
@assert( true , cmpTest[ 1 ] === "value2" );
@assert( true , cmpTest[ 2 ] === "value3" );

cmpTest = [ prop for ( prop of items( testTarget ) ) ];
@assert( true , cmpTest[ 0 ][ 0 ] === "value1" );
@assert( true , cmpTest[ 0 ][ 1 ] === 100 );
@assert( true , cmpTest[ 1 ][ 0 ] === "value2" );
@assert( true , cmpTest[ 1 ][ 1 ] === 200 );
@assert( true , cmpTest[ 2 ][ 0 ] === "value3" );
@assert( true , cmpTest[ 2 ][ 1 ] === 300 );


var cmpTest = [ prop for each ( prop in testTarget ) if ( prop === 200 ) ];
@assert( true , cmpTest[ 0 ] === 200 );

cmpTest = [ prop for ( prop in testTarget ) if ( prop === "value2" ) ];
@assert( true , cmpTest[ 0 ] === "value2" );

cmpTest = [ prop for ( prop of items( testTarget ) ) if ( prop[ 1 ] === 200 ) ];
@assert( true , cmpTest[ 0 ][ 0 ] === "value2" );
@assert( true , cmpTest[ 0 ][ 1 ] === 200 );

testTarget = {
  value1 : { value1 : 100 },
  value2 : { value2 : 200 },
  value3 : { value3 : 300 }
}

cmpTest = [ x for each ( prop in testTarget ) for each( x  in prop ) ];
@assert( true , cmpTest[ 0 ] === 100 );
@assert( true , cmpTest[ 1 ] === 200 );
@assert( true , cmpTest[ 2 ] === 300 );

cmpTest = [ x for each ( prop in testTarget ) for ( x in prop ) ];
@assert( true , cmpTest[ 0 ] === "value1" );
@assert( true , cmpTest[ 1 ] === "value2" );
@assert( true , cmpTest[ 2 ] === "value3" );

cmpTest = [ x for each ( prop in testTarget ) for ( x of items( prop ) ) ];
@assert( true , cmpTest[ 0 ][ 0 ] === "value1" );
@assert( true , cmpTest[ 0 ][ 1 ] === 100 );
@assert( true , cmpTest[ 1 ][ 0 ] === "value2" );
@assert( true , cmpTest[ 1 ][ 1 ] === 200 );
@assert( true , cmpTest[ 2 ][ 0 ] === "value3" );
@assert( true , cmpTest[ 2 ][ 1 ] === 300 );


