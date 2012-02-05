
function test () {
  console.log(1);
}
test();
var testExpression = function () {
      console.log(1);
    }

var testObject = {
      v : function () {
        console.log(1)
      },
      m : 0
    }

function testFormal ( args , args2 , args3 ) {
  console.log(1);
}

function testDstaFormal ( {args}, {tmp:{"args2":args2}} , [args3 , args4 , {args5,args6:{args7}}] , ...args8 ) {
  console.log(1);
}

var testExpressionFormal = function ( args , args2 , args3 ) {
      console.log(1);
    }

var testExpressionFormalDsta = function ( {args}, {tmp:{"args2":args2}} , [args3 , args4 , {args5,args6:{args7}}] , ...args8 ) {
      console.log(1);
    }

var testObjectFormal = {
      v : function ( args , args2 , args3 ) {
        console.log(1)
      }
    }

var testObjectFormalDsta = {
      v : function ( {args}, {tmp:{"args2":args2}} , [args3 , args4 , {args5,args6:{args7}}] , ...args8 ) {
        console.log(1)
      }
    }

