fs = require( "fs" )
if ( phantom.args.length > 0 ) {
  for ( var i = 0,len = phantom.args.length; i < len; i++ ) {
    var filename = phantom.args[i];
    if ( fs.isFile( filename ) ) {
      console.log( "run " + filename );
      try {
        Function( fs.read( filename , "read" ) )();
      } catch( e ) {
        console.log( "test failed." );
        console.log( e );
        continue;
      }
      console.log( "test success." );
    }
  }
  phantom.exit();
}