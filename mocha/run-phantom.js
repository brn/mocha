var fs = require( "fs" );
if ( phantom.args.length > 0 ) {
  for ( var i = 0,len = phantom.args.length; i < len; i++ ) {
    var filename = phantom.args[i];
    console.log(filename);
    if ( fs.isFile( filename ) ) {
      console.log( "run " + filename );
      //phantom.injectJs( filename );
      var ifr = document.createElement( "iframe" );
      try {
        document.body.appendChild( ifr );
        ifr.contentDocument.open();
        ifr.contentDocument.write( "<!doctype html><html><head><title>mocha test</title>" );
        ifr.contentDocument.write( "<script type = \"text/javascript\">\n//<![CDATA[\nvar runtest=function(){var begin = new Date();\n" + fs.read( filename , "read" ) + "\nconsole.log( 'elapsed : ' + ( new Date() - begin ) / 1000 );};\n//]]>\n</script>" );
        ifr.contentDocument.write( "</head><body><script type=\"text/javascript\">try{runtest()}catch(e){throw e;}console.log( 'test success.' );</script></body></html>" );
      } catch( e ) {
        console.log( "test failed." );
        console.log( e );
        continue;
      } finally {
        ifr.contentDocument.close();
        document.body.removeChild( ifr );
      }
    }
  }
  phantom.exit();
}