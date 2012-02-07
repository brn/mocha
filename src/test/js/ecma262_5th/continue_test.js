for ( var i = 0;i < 10; i++ ) {
  continue;
}
@assert( true , i === 10 );
@assert( true , i === 10 );
for ( i = 0; i < 10 ; i++ ) {
  END :
  for ( var j = 0; j < 5; j++ ) {
    break  END;
  };
  @assert( true , j === 0 );
};
@assert( true , i === 10 );
@assert( true , i === 10 );
@assert( true , i === 10 );