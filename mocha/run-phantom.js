fs = require( "fs" );
if ( phantom.args.length > 0 ) {
  for ( var i = 0,len = phantom.args.length; i < len; i++ ) {
    var filename = phantom.args[i];
    if ( fs.isFile( filename ) ) {
      console.log( "run " + filename );
      try {
        Function( "var begin = new Date();\n" + fs.read( filename , "read" ) + "\nconsole.log( 'elapsed : ' + ( new Date() - begin ) / 1000 );" )();
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