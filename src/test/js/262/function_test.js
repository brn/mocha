
function test () {
  return 1;
}
@assert( true , 1 === test() );

var testExpression = function () {
      return 1;
    }
@assert( true , 1 === testExpression() );

var testObject = {
      prop : function () {
        return 1;
      }
    }

@assert( true , 1 === testObject.prop() );

function testFormal ( arg , arg2 , arg3 ) {
  return arg + arg2 + arg3;
}
@assert( true , 3 === testFormal( 1 , 1 , 1 ) );


var testExpressionFormal = function ( arg , arg2 , arg3 ) {
      return arg + arg2 + arg3;
    }
@assert( true , 3 === testExpressionFormal( 1 , 1 , 1 ) );

var testObjectFormal = {
      prop : function ( arg , arg2 , arg3 ) {
        return arg + arg2 + arg3;
      }
    }
@assert( true , 3 === testObjectFormal.prop( 1 , 1 , 1 ) );


