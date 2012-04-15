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
  var x = (a,b,c) -> {
        a + b
      };
  var x = function(a,b,c) { return a + b; }
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
})();

(function () {
  var args = [1,2,3,4];
  function normalSpread(a,b,c,d) {
    console.log(a===1,a,b,c,d);
    @assert(true, a === 1);
    @assert(true, b === 2);
    @assert(true, c === 3);
    @assert(true, d === 4);
  }
  
  var propertySpread = {
        invoke : function (a,b,c,d) {
          @assert(true, a === 1);
          @assert(true, b === 2);
          @assert(true, c === 3);
          @assert(true, d === 4);
          @assert(true, this === propertySpread);
        }
      }
  
  function newSpread(a,b,c,d) {
    @assert(true, a === 1);
    @assert(true, b === 2);
    @assert(true, c === 3);
    @assert(true, d === 4);
    @assert(true, this.valid);
  }
  newSpread.prototype.valid = true;
  
  normalSpread(...args);
  propertySpread.invoke(...args);
  new newSpread(...args);
  
  var tinyArgs = [100,200];
  
  function normalSpreadWithArgs($1,a,b,c,d,$2,e,f) {
    @assert(true, $1 === 0);
    @assert(true, a === 1);
    @assert(true, b === 2);
    @assert(true, c === 3);
    @assert(true, $2 === 0);
    @assert(true, d === 4);
    @assert(true, e === 100);
    @assert(true, f === 200);
  }
  
  var propertySpreadWithArgs = {
        invoke : function ($1,a,b,c,d,$2,e,f) {
          @assert(true, $1 === 0);
          @assert(true, a === 1);
          @assert(true, b === 2);
          @assert(true, c === 3);
          @assert(true, $2 === 0);
          @assert(true, d === 4);
          @assert(true, e === 100);
          @assert(true, f === 200);
          @assert(true, this === propertySpreadWithArgs);
        }
      }
  
  function newSpreadWithArgs($1,a,b,c,d,$2,e,f) {
    @assert(true, $1 === 0);
    @assert(true, a === 1);
    @assert(true, b === 2);
    @assert(true, c === 3);
    @assert(true, $2 === 0);
    @assert(true, d === 4);
    @assert(true, e === 100);
    @assert(true, f === 200);
    @assert(true, this.valid);
  }
  newSpreadWithArgs.prototype.valid = true;
  
  normalSpreadWithArgs(0,...args,0,...tinyArgs);
  propertySpreadWithArgs.invoke(0,...args,0,...tinyArgs);
  new newSpreadWithArgs(0,...args,0,...tinyArgs);
})();
