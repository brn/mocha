(function() {
  var __global_export__ = {};
  (function() {
    __global_export__['{1-397-1092-205522212-1695-1977-60819523-2512-fmt.js}'] = {};
    __global_export__['{1-397-1092-205522212-1695-1977-60819523-2512-fmt.js}']['fmt'] = (function () {
      var __export__ = {};
      __export__.fmt = function ( format,args ) {
        for ( var i in args ){
          var reg = new RegExp( ( "\\$\\{"+i+"\\}" ) , "g" );
          format = format.replace( reg,args[i] );
        };
        return format;
      };
      return __export__;
    })();
  })();
})();
