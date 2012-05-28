var testvalue = {prop:200}
with( testvalue ) {
  @assert( true , prop === 200 );
}

var ret = [];
for( var i = 0;i < 10; i++ ) {
  with( {i:i} ) {
    ret.push(function () { return i; });
  }
}

@assert( true , ret[ 0 ]() === 0 );
@assert( true , ret[ 1 ]() === 1 );
@assert( true , ret[ 2 ]() === 2 );
@assert( true , ret[ 3 ]() === 3 );
@assert( true , ret[ 4 ]() === 4 );
@assert( true , ret[ 5 ]() === 5 );
@assert( true , ret[ 6 ]() === 6 );
@assert( true , ret[ 7 ]() === 7 );
@assert( true , ret[ 8 ]() === 8 );
@assert( true , ret[ 9 ]() === 9 );