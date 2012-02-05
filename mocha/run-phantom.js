if ( phantom.args.length > 0 ) {
  for ( var i = 0,len = phantom.args.length; i < len; i++ ) {
    phantom.injectJs( phantom.args[i] );
  }
  phantom.exit();
}