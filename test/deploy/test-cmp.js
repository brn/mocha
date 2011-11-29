(function() {
  var __global_export__ = {},
      __MC_tmp__ = undefined;
  (function() {
    __global_export__['{1-397-1092-205522212-1695-1977-60819523-2512-fmt.js}'] = {};
    (function () {
      var __export__ = __global_export__['{1-397-1092-205522212-1695-1977-60819523-2512-fmt.js}'];
      __export__.fmt = function ( format,args ) {
        for ( var i in args ){
          var reg = new RegExp( ( "\\$\\{"+i+"\\}" ) , "g" );
          format = format.replace( reg,args[i] );
        };
        return format;
      };
    })();
  })();
  (function() {
    var __tmp__0 = __global_export__['{1-397-1092-205522212-1695-1977-60819523-2512-fmt.js}'],
        fmt = ( __tmp__0.fmt )?__tmp__0.fmt : undefined;
    var __tmp__1 = location,
        href = ( __tmp__1.href )?__tmp__1.href : undefined;
    var message = "the message to you";
    var m = function ( x,y,z ) {
          return cosole.log( arguments );
        };
    var x =  {
          age : 15,
          name : "aono",
          addr : ["japan","tokyo","setagaya",322401, {
            dataType : ["za","ba","da"]
          }]
        };
    var __tmp__2 = x,
        age = ( __tmp__2.age )?__tmp__2.age : undefined,
        name = ( __tmp__2.name )?__tmp__2.name : undefined,
        country = ( __tmp__2.addr && ( __MC_tmp__ = ( __tmp__2.addr[0] || ( __tmp__2.addr.charAt && __tmp__2.addr.charAt( 0 ) ) ) ) )?__MC_tmp__ : undefined,
        city = ( __tmp__2.addr && ( __MC_tmp__ = ( __tmp__2.addr[1] || ( __tmp__2.addr.charAt && __tmp__2.addr.charAt( 1 ) ) ) ) )?__MC_tmp__ : undefined,
        ward = ( __tmp__2.addr && ( __MC_tmp__ = ( __tmp__2.addr[2] || ( __tmp__2.addr.charAt && __tmp__2.addr.charAt( 2 ) ) ) ) )?__MC_tmp__ : undefined,
        zip = ( __tmp__2.addr && ( __MC_tmp__ = ( __tmp__2.addr[3] || ( __tmp__2.addr.charAt && __tmp__2.addr.charAt( 3 ) ) ) ) )?__MC_tmp__ : undefined,
        ztype = ( __tmp__2.addr && ( __MC_tmp__ = ( __tmp__2.addr[4] || ( __tmp__2.addr.charAt && __tmp__2.addr.charAt( 4 ) ) ) ) && __MC_tmp__.dataType && ( __MC_tmp__ = ( __MC_tmp__.dataType[0] || ( __MC_tmp__.dataType.charAt && __MC_tmp__.dataType.charAt( 0 ) ) ) ) && ( __MC_tmp__ = ( __MC_tmp__[0] || ( __MC_tmp__.charAt && __MC_tmp__.charAt( 0 ) ) ) ) )?__MC_tmp__ : undefined,
        btype = ( __tmp__2.addr && ( __MC_tmp__ = ( __tmp__2.addr[4] || ( __tmp__2.addr.charAt && __tmp__2.addr.charAt( 4 ) ) ) ) && __MC_tmp__.dataType && ( __MC_tmp__ = ( __MC_tmp__.dataType[1] || ( __MC_tmp__.dataType.charAt && __MC_tmp__.dataType.charAt( 1 ) ) ) ) && ( __MC_tmp__ = ( __MC_tmp__[0] || ( __MC_tmp__.charAt && __MC_tmp__.charAt( 0 ) ) ) ) )?__MC_tmp__ : undefined,
        dtype = ( __tmp__2.addr && ( __MC_tmp__ = ( __tmp__2.addr[4] || ( __tmp__2.addr.charAt && __tmp__2.addr.charAt( 4 ) ) ) ) && __MC_tmp__.dataType && ( __MC_tmp__ = ( __MC_tmp__.dataType[2] || ( __MC_tmp__.dataType.charAt && __MC_tmp__.dataType.charAt( 2 ) ) ) ) && ( __MC_tmp__ = ( __MC_tmp__[0] || ( __MC_tmp__.charAt && __MC_tmp__.charAt( 0 ) ) ) ) )?__MC_tmp__ : undefined;
    console.log( age,name,country,city,ward,zip,ztype,btype,dtype );
    for ( var __tmp__16 in obj ){
      __tmp__16 = obj[__tmp__16];
      var i = ( __tmp__16.i )?__tmp__16.i : undefined;
      console.log( i );
    };
  })();
})();
