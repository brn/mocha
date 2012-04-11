var fs = require( "fs" );
if (phantom.args.length > 0) {
  for (var i = 0,len = phantom.args.length; i < len; i++) {
    var filename = phantom.args[i];
    if (fs.isFile(filename)) {
      phantom.injectJs(filename);
    }
  }
  phantom.exit();
}