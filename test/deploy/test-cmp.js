(function() {
  var __FILE__ = '';
  var __LINE__ = 0;
  window.onerror=function( err ){try{throw new SyntaxError(err + ' in ' +  __FILE__ + ' at : ' + __LINE__ )}catch(e){  throw new Error(e);}};
  var __global_export__ = {},
      __MC_tmp__ = undefined;
      (function() {
        var __backup__ = __FILE__ = "/home/brn/Dropbox/Public/mocha/test/mains/test.js";
        __LINE__ = 3;
        var __tmp__0 = location,
            href = ( __tmp__0.href )?__tmp__0.href : undefined;
        __LINE__ = 5;
        var message = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
        __LINE__ = 9;
        var m = function ( x,y,z ) {
              __LINE__ = 9;
              __FILE__ = __backup__;
              return cosole.log( arguments );
            };
        __LINE__ = 10;
        var x =  {
              age : 15,
              name : "aono",
              addr : ["japan","tokyo","setagaya",322401, {
                dataType : ["za","ba","da"]
              }]
            };
        __LINE__ = 15;
        var __tmp__1 = x,
            age = ( __tmp__1.age )?__tmp__1.age : undefined,
            name = ( __tmp__1.name )?__tmp__1.name : undefined,
            country = ( __tmp__1.addr && ( __MC_tmp__ = ( __tmp__1.addr[0] || ( __tmp__1.addr.charAt && __tmp__1.addr.charAt( 0 ) ) ) ) )?__MC_tmp__ : undefined,
            city = ( __tmp__1.addr && ( __MC_tmp__ = ( __tmp__1.addr[1] || ( __tmp__1.addr.charAt && __tmp__1.addr.charAt( 1 ) ) ) ) )?__MC_tmp__ : undefined,
            ward = ( __tmp__1.addr && ( __MC_tmp__ = ( __tmp__1.addr[2] || ( __tmp__1.addr.charAt && __tmp__1.addr.charAt( 2 ) ) ) ) )?__MC_tmp__ : undefined,
            zip = ( __tmp__1.addr && ( __MC_tmp__ = ( __tmp__1.addr[3] || ( __tmp__1.addr.charAt && __tmp__1.addr.charAt( 3 ) ) ) ) )?__MC_tmp__ : undefined,
            ztype = ( __tmp__1.addr && ( __MC_tmp__ = ( __tmp__1.addr[4] || ( __tmp__1.addr.charAt && __tmp__1.addr.charAt( 4 ) ) ) ) && __MC_tmp__.dataType && ( __MC_tmp__ = ( __MC_tmp__.dataType[0] || ( __MC_tmp__.dataType.charAt && __MC_tmp__.dataType.charAt( 0 ) ) ) ) && ( __MC_tmp__ = ( __MC_tmp__[0] || ( __MC_tmp__.charAt && __MC_tmp__.charAt( 0 ) ) ) ) )?__MC_tmp__ : undefined,
            btype = ( __tmp__1.addr && ( __MC_tmp__ = ( __tmp__1.addr[4] || ( __tmp__1.addr.charAt && __tmp__1.addr.charAt( 4 ) ) ) ) && __MC_tmp__.dataType && ( __MC_tmp__ = ( __MC_tmp__.dataType[1] || ( __MC_tmp__.dataType.charAt && __MC_tmp__.dataType.charAt( 1 ) ) ) ) && ( __MC_tmp__ = ( __MC_tmp__[0] || ( __MC_tmp__.charAt && __MC_tmp__.charAt( 0 ) ) ) ) )?__MC_tmp__ : undefined,
            dtype = ( __tmp__1.addr && ( __MC_tmp__ = ( __tmp__1.addr[4] || ( __tmp__1.addr.charAt && __tmp__1.addr.charAt( 4 ) ) ) ) && __MC_tmp__.dataType && ( __MC_tmp__ = ( __MC_tmp__.dataType[2] || ( __MC_tmp__.dataType.charAt && __MC_tmp__.dataType.charAt( 2 ) ) ) ) && ( __MC_tmp__ = ( __MC_tmp__[0] || ( __MC_tmp__.charAt && __MC_tmp__.charAt( 0 ) ) ) ) )?__MC_tmp__ : undefined;
        __LINE__ = 16;
        console.log( age,name,country,city,ward,zip,ztype,btype,dtype );
        __LINE__ = 17;
        for ( var i in obj ){
          i = obj[i];
          __LINE__ = 17;
          console.log( i );
        };
      })();
    })();
    