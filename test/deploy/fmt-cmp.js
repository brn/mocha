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
          var x = _mochaLocalTmp0.x;
          __LINE__ = 20;
          return 400;
        } catch( e ){
          Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
        }
      };
})();
