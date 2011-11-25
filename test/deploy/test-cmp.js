(function() {
  var __FILE__ = '';
  var __LINE__ = 0;
  window.onerror=function( err ){try{throw new SyntaxError(err + ' in ' +  __FILE__ + ' at : ' + __LINE__ )}catch(e){  throw new Error(e);}};
  var __global_export__ = {};
  (function() {
    var __backup__ = __FILE__ = "/Users/aono_taketoshi/github/mocha/mocha/test/mains/fmt.js";
    __global_export__['{1-397-1092-205522212-1695-1977-60819523-2512-fmt.js}'] = {};
    __global_export__['{1-397-1092-205522212-1695-1977-60819523-2512-fmt.js}']['fmt'] = (function () {
      var __export__ = {};
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
      return __export__;
    })();
  })();
  (function() {
    var __backup__ = __FILE__ = "/Users/aono_taketoshi/github/mocha/mocha/test/mains/test.js";
    __LINE__ = 1;
    var __tmp__0 = __global_export__['{1-397-1092-205522212-1695-1977-60819523-2512-fmt.js}'],
        x = ( __tmp__0.fmt && __tmp__0.fmt[0] )?__tmp__0.fmt[0] : undefined,
        x = ( __tmp__0.fmt && __tmp__0.fmt[1] && __tmp__0.fmt[1].y && __tmp__0.fmt[1].y[0] )?__tmp__0.fmt[1].y[0] : undefined,
        y = ( __tmp__0.fmt && __tmp__0.fmt[1] && __tmp__0.fmt[1].y && __tmp__0.fmt[1].y[1] )?__tmp__0.fmt[1].y[1] : undefined,
        z = ( __tmp__0.fmt && __tmp__0.fmt[1] && __tmp__0.fmt[1].y && __tmp__0.fmt[1].y[2] )?__tmp__0.fmt[1].y[2] : undefined,
        json = ( __tmp__0.fmt && __tmp__0.fmt[1] && __tmp__0.fmt[1].y && __tmp__0.fmt[1].y[3] && __tmp__0.fmt[1].y[3]["@ok"] )?__tmp__0.fmt[1].y[3]["@ok"] : undefined;
    __LINE__ = 2;
    var __tmp__1 = location,
        href = ( __tmp__1.href )?__tmp__1.href : undefined,
        protocol = ( __tmp__1.protocol )?__tmp__1.protocol : undefined;
  })();
})();
