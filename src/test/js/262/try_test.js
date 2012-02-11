var value = 0;
try {
  value = 100;
  throw new Error( "message" )
} catch( e ) {
  @assert( true , e instanceof Error );
} finally {
  @assert( true , value === 100 );
}