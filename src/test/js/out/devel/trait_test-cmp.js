!function() {
  var __FILE__ = "Runtime",
      __LINE__ = 0;
  
  __LINE__ = 0;
  function () {
    try {
      var __FILE__ = "/var/samba/mocha/src/test/js/harmony/trait_test.js",
          __LINE__ = 0;
      __LINE__ = 2;
      _mochaGlobalExport['./trait_test.js'] = {};
      
      __LINE__ = 3;
      var _mochaGlobalAlias = _mochaGlobalExport['./trait_test.js'];
      ;
  
  __LINE__ = 1;
  function () {
    try {
      __LINE__ = 1;
      var TestTraitP =  {
            _mochaTraitPrivate :  {
              _greaterThant : function _greaterThant( x,y ) {
                try {
                  __LINE__ = 2;
                  return x<y;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
            },
            _mochaTraitPublic :  {
              greaterThan : function greaterThan( x,y ) {
                try {
                  __LINE__ = 3;
                  return x<y;
                } catch( e ){
                  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                }
              }
            },
            _mochaRequires : {},
            _mochaTraitMark : true
          };
      ;
  __LINE__ = 1;
  return TestTraitP;
} catch( e ){
  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
}
}();

__LINE__ = 6;
function () {
  try {
    __LINE__ = 6;
    var TestTrait =  {
          _mochaTraitPrivate :  {
            _lessThan : function _lessThan( x,y ) {
              try {
                __LINE__ = 10;
                return x<y;
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            }
          },
          _mochaTraitPublic :  {
            lessThan : function lessThan( x,y ) {
              try {
                __LINE__ = 11;
                return x<y;
              } catch( e ){
                Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
              }
            }
          },
          _mochaRequires :  {
            compare : true,
            test1 : true,
            test2 : true,
            test3 : true,
            test4 : true
          },
          _mochaTraitMark : true
        };
    ;
__LINE__ = 6;
return TestTrait} catch( e ){
  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
}
}();

__LINE__ = 14;
var traitexp = function () {
      try {
        __LINE__ = 14;
        var _mochaLocalTmp0 =  {
              _mochaTraitPrivate :  {
                mastercmp : function mastercmp( x,y ) {
                  try {
                    __LINE__ = 15;
                    return x>y;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
              },
              _mochaTraitPublic :  {
                lessthan : function lessthan( x,y ) {
                  try {
                    __LINE__ = 16;
                    return x>y;
                  } catch( e ){
                    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
                  }
                }
              },
              _mochaRequires : {},
              _mochaTraitMark : true
            };
        ;
    __LINE__ = 14;
    return _mochaLocalTmp0;
  } catch( e ){
    Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
  }
}();
} catch( e ){
  Runtime.exceptionHandler( __LINE__ , __FILE__ , e );
}
}()}();
