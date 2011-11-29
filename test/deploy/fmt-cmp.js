(function() {
  var __FILE__ = '';
  var __LINE__ = 0;
  window.onerror=function( err ){try{throw new SyntaxError(err + ' in ' +  __FILE__ + ' at : ' + __LINE__ )}catch(e){  throw new Error(e);}};
  var __global_export__ = {},
      __MC_tmp__ = undefined;
  (function() {
    var __backup__ = __FILE__ = "/Users/aono_taketoshi/github/mocha/mocha/test/mains/fmt.js";
    __global_export__['{1-397-1092-205522212-1695-1977-60819523-2512-fmt.js}'] = {};
    (function () {
      var __export__ = __global_export__['{1-397-1092-205522212-1695-1977-60819523-2512-fmt.js}'];
      __LINE__ = 0;
      __LINE__ = 1;
      __export__.fmt = function ( format,args ) {
        __LINE__ = 1;
        __FILE__ = __backup__;
        __LINE__ = 2;
        for ( var i in args ){
          __LINE__ = 3;
          var reg = new RegExp( ( "\\$\\{"+i+"\\}" ) , "g" );
          __LINE__ = 4;
          format = format.replace( reg,args[i] );
        };
        __LINE__ = 6;
        return format;
      };
    })();
  })();
})();
