(function () {
function testDeclHasFormal()->console.log(1);
function testDeclNonFormal->console.log(1);
function testDeclHasFormalWithContext()=>console.log(1);
function testDeclNonForamlWithContext=>console.log(1);

const testConstFunctionHasBlockHasFormal() {
        console.log(1);
      }
  
  var contextTest = =>console.log(this);
  
const testConstFunctionHasForaml()->console.log(1);
const testConstFunctionNonFormal->console.log(1);

const testConstFunctionHasFormalWithContext()=>console.log(1);
const testConstFunctionWithContext=>console.log(1);

testHasFormalHasBlock()->{
  console.log(1);
}
testHasFormal()->console.log(1);
test->console.log(1);

testHasFormalHasBlockWithContext()=>{
  console.log(1);
}
testHasFormalWithContext()=>console.log(1);
testWithContext=>console.log(1);
})();

(function () {
  
  function testDeclHasFormal( args , args2 , args3 )->console.log(1);
  function testDeclHasFormalDsta( {args}, {tmp:{"args2":args2}} , [args3 , args4 , {args5,args6:{args7}}] , ...args8 )->console.log(1);
  function testDeclHasFormalWithContext( args , args2 , args3 )=>console.log(1);
  function testDeclHasFormalDstaWithContext( {args}, {tmp:{"args2":args2}} , [args3 , args4 , {args5,args6:{args7}}] , ...args8 )=>console.log(this);
  const testConstFunctionHasBlockHasFormal( args , args2 , args3 ) {
          console.log(1);
        }
  const testConstFunctionHasBlockHasFormalDsta( {args}, {tmp:{"args2":args2}} , [args3 , args4 , {args5,args6:{args7}}] , ...args8 ) {
          console.log(1);
        }

  const testConstFunctionHasForaml( args , args2 , args3)->console.log(1);
  const testConstFunctionHasForamlDsta( {args}, {tmp:{"args2":args2}} , [args3 , args4 , {args5,args6:{args7}}] , ...args8 )->console.log(1);
  const testConstFunctionHasFormalWithContext( args , args2 , args3 )=>console.log(1);
  const testConstFunctionHasFormalDstaWithContext( {args}, {tmp:{"args2":args2}} , [args3 , args4 , {args5,args6:{args7}}] , ...args8 )=>console.log(1);
  
  testHasFormalHasBlock( args , args2 , args3 )->{
    console.log(1);
  }
  testHasFormalDstaHasBlock( {args}, {tmp:{"args2":args2}} , [args3 , args4 , {args5,args6:{args7}}] , ...args8 )->{
    console.log(1);
  }
  testHasFormal( args , args2 , args3 )->console.log(1);
  testHasFormalDsta( {args}, {tmp:{"args2":args2}} , [args3 , args4 , {args5,args6:{args7}}] , ...args8 )->console.log(1);
  testHasFormalHasBlockWithContext( args , args2 , args3 )=>{
    console.log(1);
  }
  testHasFormalDstaHasBlockWithContext( {args}, {tmp:{"args2":args2}} , [args3 , args4 , {args5,args6:{args7}}] , ...args8)=>{
    console.log(1);
  }
  testHasFormalWithContext( args , args2 , args3 )=>console.log(1);
  testHasFormalDstaWithContext( {args}, {tmp:{"args2":args2}} , [args3 , args4 , {args5,args6:{args7}}] , ...args8)=>console.log(1);
})()
