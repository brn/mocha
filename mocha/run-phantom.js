var fs = require( "fs" );
if ( phantom.args.length > 0 ) {
  for ( var i = 0,len = phantom.args.length; i < len; i++ ) {
    var filename = phantom.args[i];
    if ( fs.isFile( filename ) ) {
      console.log( "run " + filename );
      var ifr = document.createElement( "iframe" );
      try {
        document.body.appendChild( ifr );
        ifr.contentDocument.write( "<script type = \"text/javascript\">\nvar begin = new Date();\n" + fs.read( filename , "read" ) + "\nconsole.log( 'elapsed : ' + ( new Date() - begin ) / 1000 );</script>" );
      } catch( e ) {
        console.log( "test failed." );
        console.log( e );
        continue;
      } finally {
        document.body.removeChild( ifr );
      }
      console.log( "test success." );
    }
  }
  phantom.exit();
}