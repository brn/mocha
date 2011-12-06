(function() {
  var __global_export__ = {},
      __MC_tmp__ = undefined;
  (function() {
    ( function () {
      var __MC_local_export__ = __MC_global_alias__;
      __MC_local_export__.fmt = function fmt( format,args ) {
        for ( var i in args ){
          var reg = new RegExp( ( "\\$\\{"+i+"\\}" ) , "g" );
          format = format.replace( reg,args[i] );
        };
        return format;
      };
      __MC_local_export__.x = x;
      __MC_local_export__.y = y;
      __MC_local_export__.z = z;
      return __MC_local_export__;
    })();
  })();
})();
