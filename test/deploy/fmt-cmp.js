(function() {
  var __FILE__ = "Runtime",
      __LINE__ = 0;
  
  __LINE__ = 0;
  if ( !Function.prototype.bind ){
    __LINE__ = 0;
    Function.prototype.bind = function () {
      try {
        __LINE__ = 0;
        var argArray = 0,
            ret = function () {
              try {
                __LINE__ = 0;
                var args = 0;
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            };
        __LINE__ = 7;
        return ret;
      } catch( e ){
        Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
      }
    };
  };
  
  __LINE__ = 0;
  var i = 0;
  
  __LINE__ = 12;
  for ( i = 0;i<200;i ++  ){
    __LINE__ = 0;
    consol.log( i );
  };
  
  __LINE__ = 0;
  var m = 10;
  
  __LINE__ = 16;
  while ( m --  ){
    __LINE__ = 0;
    console.log( m );
  };
  
  __LINE__ = 0;
  var v = function () {
        try {
          __LINE__ = 19;
          return 200;
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      },
      v2 = function ( _mochaLocalTmp0,y ) {
        try {
          __LINE__ = 0;
          var a = _mochaLocalTmp0[0],
              b = ( _mochaLocalTmp0[1] && _mochaLocalTmp0[1].b )?_mochaLocalTmp0[1].b : undefined,
              rest = Runtime.toArray( _mochaLocalTmp0,2 );
          __LINE__ = 20;
          return 400;
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      };
  
  function () {
    try {
      __LINE__ = 23;
      return 300;
    } catch( e ){
      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  }
  __LINE__ = 0;
  function testFn( _mochaLocalTmp1 ) {
    try {
      __LINE__ = 0;
      var a = ( _mochaLocalTmp1.x && _mochaLocalTmp1.x[0] )?_mochaLocalTmp1.x[0] : undefined,
          b = ( _mochaLocalTmp1.x && _mochaLocalTmp1.x[1] )?_mochaLocalTmp1.x[1] : undefined,
          c = ( _mochaLocalTmp1.x && _mochaLocalTmp1.x[2] )?_mochaLocalTmp1.x[2] : undefined,
          z = _mochaLocalTmp1.z;
      __LINE__ = 25;
      return 200;
    } catch( e ){
      Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
    }
  };
  
  __LINE__ = 0;
  var m = function ( _mochaLocalTmp2,_mochaLocalTmp3,_mochaLocalTmp4 ) {
        try {
          __LINE__ = 0;
          var x = _mochaLocalTmp2.x,
              y = _mochaLocalTmp3.y,
              z = _mochaLocalTmp4.z;
          __LINE__ = 26;
          return 200;
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      };
  
  __LINE__ = 0;
  var _mochaLocalTmp5 =  {
        test2 : 300
      },
      x = ( _mochaLocalTmp5.test2 && _mochaLocalTmp5.test2.x )?_mochaLocalTmp5.test2.x : undefined,
      test = _mochaLocalTmp5.test,
      a = ( _mochaLocalTmp5.v && _mochaLocalTmp5.v[0] )?_mochaLocalTmp5.v[0] : undefined,
      b = ( _mochaLocalTmp5.v && _mochaLocalTmp5.v[1] )?_mochaLocalTmp5.v[1] : undefined,
      c = ( _mochaLocalTmp5.v && _mochaLocalTmp5.v[2] )?_mochaLocalTmp5.v[2] : undefined;
  
  __LINE__ = 0;
  var testObject =  {
        a : a,
        b : function b() {
          try {
            __LINE__ = 30;
            return 200;
          } catch( e ){
            Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
          }
        }
      };
})();
