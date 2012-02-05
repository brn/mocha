try {
  throw new Error( "message" )
} catch( e ) {
  throw new Error( e );
} finally {
  console.log("end");
}