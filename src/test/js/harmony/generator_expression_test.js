import {keys,allItems} from "iterators".iterators;

var testObject = {
      value1 : 100,
      value2 : 200,
      value3 : 300
    }
var test = ( x for each ( x in testObject ) );

@assert( true , test.next() === 100 );
@assert( true , test.next() === 200 );
@assert( true , test.next() === 300 );

test = ( x for ( x of keys( testObject ) ) );

@assert( true , test.next() === "value1" );
@assert( true , test.next() === "value2" );
@assert( true , test.next() === "value3" );

test = ( x for each ( x in testObject ) if ( x === 200 ) );
@assert( true , test.next() === 200 );

test = ( x for ( x of keys( testObject ) ) if ( x === "value2" ) );
@assert( true , test.next() === "value2" );
