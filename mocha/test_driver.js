var fs = require( "fs" );
if (phantom.args.length > 0) {
  for (var i = 0,len = phantom.args.length; i < len; i++) {
    var filename = phantom.args[i];
    if (fs.isFile(filename)) {
      console.log("[Info] Run " + filename);
      var ifr = document.createElement( "iframe" );
      try {
        document.body.appendChild(ifr);
        ifr.contentDocument.open();
        ifr.contentDocument.write("<!doctype html><html><head><title>mocha test</title>");
        ifr.contentDocument.write("<script type=\"text/javascript\">var begin = new Date();</script>");
        ifr.contentDocument.write('<script type="text/javascript">' + fs.read(filename) + '</script>');
        ifr.contentDocument.write('<script type="text/javascript">console.log( "elapsed : " + ( new Date() - begin ) / 1000 );</script>');
        ifr.contentDocument.write("</head><body></body></html>");
      } catch(e) {
        console.log("[Error] "  + e);
        continue;
      } finally {
        ifr.contentDocument.close();
        document.body.removeChild(ifr);
      }
    }
  }
  phantom.exit();
}