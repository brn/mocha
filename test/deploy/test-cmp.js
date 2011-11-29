(function() {
  var __global_export__ = {},
      __MC_tmp__ = undefined;
  (function() {
    var x = function ( __tmp__0,__tmp__1,ValueNode ) {
          
        };
    var __tmp__2 = location,
        href = ( __tmp__2.href )?__tmp__2.href : undefined;
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
    var __tmp__3 = x,
        age = ( __tmp__3.age )?__tmp__3.age : undefined,
        name = ( __tmp__3.name )?__tmp__3.name : undefined,
        country = ( __tmp__3.addr && ( __MC_tmp__ = ( __tmp__3.addr[0] || ( __tmp__3.addr.charAt && __tmp__3.addr.charAt( 0 ) ) ) ) )?__MC_tmp__ : undefined,
        city = ( __tmp__3.addr && ( __MC_tmp__ = ( __tmp__3.addr[1] || ( __tmp__3.addr.charAt && __tmp__3.addr.charAt( 1 ) ) ) ) )?__MC_tmp__ : undefined,
        ward = ( __tmp__3.addr && ( __MC_tmp__ = ( __tmp__3.addr[2] || ( __tmp__3.addr.charAt && __tmp__3.addr.charAt( 2 ) ) ) ) )?__MC_tmp__ : undefined,
        zip = ( __tmp__3.addr && ( __MC_tmp__ = ( __tmp__3.addr[3] || ( __tmp__3.addr.charAt && __tmp__3.addr.charAt( 3 ) ) ) ) )?__MC_tmp__ : undefined,
        ztype = ( __tmp__3.addr && ( __MC_tmp__ = ( __tmp__3.addr[4] || ( __tmp__3.addr.charAt && __tmp__3.addr.charAt( 4 ) ) ) ) && __MC_tmp__.dataType && ( __MC_tmp__ = ( __MC_tmp__.dataType[0] || ( __MC_tmp__.dataType.charAt && __MC_tmp__.dataType.charAt( 0 ) ) ) ) && ( __MC_tmp__ = ( __MC_tmp__[0] || ( __MC_tmp__.charAt && __MC_tmp__.charAt( 0 ) ) ) ) )?__MC_tmp__ : undefined,
        btype = ( __tmp__3.addr && ( __MC_tmp__ = ( __tmp__3.addr[4] || ( __tmp__3.addr.charAt && __tmp__3.addr.charAt( 4 ) ) ) ) && __MC_tmp__.dataType && ( __MC_tmp__ = ( __MC_tmp__.dataType[1] || ( __MC_tmp__.dataType.charAt && __MC_tmp__.dataType.charAt( 1 ) ) ) ) && ( __MC_tmp__ = ( __MC_tmp__[0] || ( __MC_tmp__.charAt && __MC_tmp__.charAt( 0 ) ) ) ) )?__MC_tmp__ : undefined,
        dtype = ( __tmp__3.addr && ( __MC_tmp__ = ( __tmp__3.addr[4] || ( __tmp__3.addr.charAt && __tmp__3.addr.charAt( 4 ) ) ) ) && __MC_tmp__.dataType && ( __MC_tmp__ = ( __MC_tmp__.dataType[2] || ( __MC_tmp__.dataType.charAt && __MC_tmp__.dataType.charAt( 2 ) ) ) ) && ( __MC_tmp__ = ( __MC_tmp__[0] || ( __MC_tmp__.charAt && __MC_tmp__.charAt( 0 ) ) ) ) )?__MC_tmp__ : undefined;
    console.log( age,name,country,city,ward,zip,ztype,btype,dtype );
    for ( var __tmp__17 in obj ){
      __tmp__17 = obj[__tmp__17];
      var i = ( __tmp__17.i )?__tmp__17.i : undefined;
      console.log( i );
    };
  })();
})();
