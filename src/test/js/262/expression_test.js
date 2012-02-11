/aaaa/.test( "aaaa" );
function parseTest() {
  var x = .200 * 10;
  @assert( true , x === 2 );
  
  x = function () {
    return .200 * 10;
  }
  @assert( true , x() === 2 );
  
  x = function () {
    return /aaa/;
  }
  @assert( true , Object.prototype.toString.call( x() ) === "[object RegExp]" );
  @assert( true , /aaa/.test( "aaa" ) === true );
  @assert( true , .200 * 10 === 2 );
}
function objectAndNewTest() {
  var testObject = {};
  testObject.testProp = {}
  testObject.testProp.testProp = {}
  testObject.testProp.testProp.testProp = {}
  testObject.testFn = function () { return true };
  testObject.testProp.testFn = function () { return false; };
  testObject.testProp.testProp.testFn = function () { return 2};

  @assert( true , testObject.testFn() === true );
  @assert( true , testObject.testProp.testFn() === false );
  @assert( true , testObject.testProp.testProp.testFn() === 2 );

  var highFn = function () { return inner1; }
  var inner1 = function () { return inner2 }
  var inner2 = function () {}
  var instance = new highFn();
  var instance2 = new new highFn();
  var instance3 = new new new highFn();
  @assert( true , instance === inner1 );
  @assert( true , instance2 === inner2 );
  @assert( true , instance3 instanceof inner2 );
  
  var fnObj = {
        highFn : highFn,
        highFnInner : {
          highFn : highFn
        }
      }

  var instance4 = new fnObj.highFn();
  var instance5 = new new fnObj.highFn();
  var instance6 = new new new fnObj.highFn();
  @assert( true , instance4 === inner1 );
  @assert( true , instance5 === inner2 );
  @assert( true , instance6 instanceof inner2 );
  var instance7 = new fnObj.highFnInner.highFn();
  var instance8 = new new fnObj.highFnInner.highFn();
  var instance9 = new new new fnObj.highFnInner.highFn();
  @assert( true , instance7 === inner1 );
  @assert( true , instance8 === inner2 );
  @assert( true , instance9 instanceof inner2 );
};

function callExpressionTest () {
  var highFn = function(){
        return function () {
          return function () {
            return true;
          }
        }
      }
  @assert( true , highFn()()() === true );
  highFn = function () { return inner1; }
  var inner1 = function () { return inner2 }
  var inner2 = function () {}
  var flg = 1;
  var instance = new ( ( flg )? highFn : inner1 );
  @assert( true , instance === inner1 );
  var flg2 = 0;
  instance = new ( ( flg2 )? highFn : inner1 );
  @assert( true , instance === inner2 );
}

function binaryExpressionTest() {
  var item = 100,
      trueValue = true,
      falseValue = false,
      val = 0;
  if ( item && trueValue && !falseValue ) {
    val = 1;
  }
  @assert( true , val === 1 );
  if ( ( item && trueValue ) || falseValue ) {
    val = 2;
  }
  @assert( true , val === 2 );
  if ( ( item && falseValue ) || !trueValue ) {
    val = 3;
  }
  @assert( false , val === 3 );
  
  var changeVal = function ( value ) {
        val = value;
      };
  
  ( item ) && ( trueValue ) && ( !falseValue ) && ( changeVal( 4 ) );
  @assert( true , val === 4 );
  
  var eq = 0,
      eqVal = 0;
  if ( eq == 0 ) {
    eqVal = 1;
  }
  @assert( true , eqVal === 1 );
  
  if ( eq === 0 ) {
    eqVal = 2;
  }
  @assert( true , eqVal === 2 );
  
  var bit = 1,
      ret = 0;
  ret = bit << 1;
  @assert( true , ret === 2 );
  ret = bit >> 1;
  @assert( true , ret === 0 );
  ret = bit | 2;
  @assert( true , ret === 3 );
  
  bit = 1;
  bit <<= 1;
  @assert( true , bit === 2 );
  bit = 1;
  bit >>= 1;
  @assert( true , bit === 0 );
  bit = 1;
  bit |= 2;
  @assert( true , bit === 3 );
  
  bit = 10;
  ret = bit >>> 2;
  @assert( true , ret === 2 );
  bit = 10;
  bit >>>= 2;
  @assert( true , bit === 2 );
  
  bit = 3;
  ret = bit & 1;
  @assert( true , ret === 1 );
  bit &= 1;
  @assert( true , bit === 1 );
  
  bit = 2;
  ret = bit ^ 1;
  @assert( true , ret === 3 );
  bit = 2;
  bit ^= 1;
  @assert( true , bit === 3 );
  
  var lt = 0,
      gt = 1,
      cmpVal = 0;
  
  if ( lt > gt ) {
    cmpVal = 1;
  }
  @assert( true , cmpVal === 0 );
  
  cmpVal = 0;
  if ( lt < gt ) {
    cmpVal = 1;
  }
  @assert( true , cmpVal === 1 );
  
  cmpVal = 0;
  if ( lt <= gt ) {
    cmpVal = 1;
  }
  @assert( true , cmpVal === 1 );
  
  cmpVal = 0;
  if ( lt >= gt ) {
    cmpVal = 1;
  }
  @assert( false , cmpVal === 1 );
  
  cmpVal = 0;
  lt = 1;
  if ( lt <= gt ) {
    cmpVal = 1;
  }
  @assert( true , cmpVal === 1 );
  
  cmpVal = 1;
  if ( lt >= gt ) {
    cmpVal = 1;
  }
  @assert( true , cmpVal === 1 );
  
  var pl = 0;
  ret = pl + 1;
  @assert( true , ret === 1 );
  
  var mi = 1;
  ret = mi - 1;
  @assert( true , ret === 0 );
  
  var mul = 1;
  ret = mul * 2;
  @assert( true , ret === 2 );
  
  var div = 2;
  ret = div / 2;
  @assert( true , ret === 1 );
  
  var mod = 3;
  ret = mod % 2;
  @assert( true , ret === 1 );
  
  pl = 0
  pl += 1;
  @assert( true , pl === 1 );
  
  mi = 1;
  mi -= 1;
  @assert( true , mi === 0 );
  
  mul = 1;
  mul *= 2;
  @assert( true , mul === 2 );
  
  div = 2;
  div /= 2;
  @assert( true , div === 1 );
  
  mod = 3;
  mod %= 2;
  @assert( true , mod === 1 );
  
  var obj = {
        'onmouseenter' : 1,
        'onmouseleave' : 1
      }
  
  var testInAnd = 'onmouseenter' in obj
        && 'onmouseleave' in obj;
  @assert( true , testInAnd === true );
}

function postfixExpressionTest() {
  var add = 0;
  add++;
  @assert( true , add === 1 );
  
  var sub = 1;
  sub--;
  @assert( true , sub === 0 );
  
  add = 0;
  sub = add
  ++sub;
  @assert( true , sub === 1 );
  
  add = 1;
  sub = add
  --sub;
  @assert( true , sub === 0 );
  
  sub = 1;
  sub--
  add = sub;
  @assert( true , add === 0 );
  
}

function unaryExpressionTest() {
  var strNum = "1",
      ret = +strNum;
  @assert( true , ret === 1 );
  
  ret = -strNum;
  @assert( true , ret === -1 );
  
  var num = -5;
  ret = ~num;
  @assert( true , ret === 4 );
  
  var flg = true;
  ret = !flg;
  @assert( true , ret === false );
  
  ret = !!flg;
  @assert( true , ret === true );
}

function memberExpressionTest() {
  var test = {
        test2 : {
          "@test" : {
            0 : {
              "1" : function () {
                return function () {return 1;};
              }
            }
          }
        }
      }
  @assert( true , test["test2"]["@test"]["0"]["1"]()() === 1 );
  @assert( true , test.test2["@test"][0]["1"]()() === 1 );
}

function expressionTest() {
  var exp = function () {
        return 1;
      }()
  @assert( true , exp === 1 );
  
  var a,b,c;
  exp = ( a = 0, b = 1,c = 2 );
  @assert( true , a === 0 );
  @assert( true , b === 1 );
  @assert( true , c === 2 );
  @assert( true , exp === 2 );
  
  (function () {
    exp = 10;
  })();
  
  @assert( true , exp === 10 );
  
  (function ( a , b ) {
    exp = a + b;
  })( (function () { return 100; })() , function () { return 200; }() );
  
  @assert( true , exp === 300 );
  
  !function () {
    exp = 1;
  }();
  @assert( true , exp === 1 );
}

function primaryTest() {
  var array = [,,,];
  @assert( true , array.length === 3 );
}

parseTest();
objectAndNewTest();
callExpressionTest();
binaryExpressionTest();
postfixExpressionTest();
unaryExpressionTest();
memberExpressionTest();
expressionTest();
primaryTest();
