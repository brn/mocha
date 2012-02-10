var targetObject = {
      value1 : 100,
      value2 : 200,
      value3 : 300
    },
    arr = [];
for each ( var i in targetObject ) {
  arr.push( i );
}
@assert( true , arr[ 0 ] === 100 );
@assert( true , arr[ 1 ] === 200 );
@assert( true , arr[ 2 ] === 300 );

arr = [];
for each ( i in targetObject ) {
  arr.push( i );
}
@assert( true , arr[ 0 ] === 100 );
@assert( true , arr[ 1 ] === 200 );
@assert( true , arr[ 2 ] === 300 );

arr = [];
for each ( var i in targetObject )
  arr.push( i );

@assert( true , arr[ 0 ] === 100 );
@assert( true , arr[ 1 ] === 200 );
@assert( true , arr[ 2 ] === 300 );

arr = [];
for each ( i in targetObject )
  arr.push( i );

@assert( true , arr[ 0 ] === 100 );
@assert( true , arr[ 1 ] === 200 );
@assert( true , arr[ 2 ] === 300 );

var prop = {
      val : ""
    }
arr = [];
for each ( prop.val in targetObject ) {
  arr.push( prop.val );
}

@assert( true , arr[ 0 ] === 100 );
@assert( true , arr[ 1 ] === 200 );
@assert( true , arr[ 2 ] === 300 );