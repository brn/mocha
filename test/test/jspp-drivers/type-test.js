
var request = require ( "Request" );
                        
exports.classWithTypeTester = function () {
  Class ( "TypeTestClass" ) (
    function ( self , privates) {
      self.__init__ = function () {
        privates ( this , {
          test : 200
        })
      }
      self.getData = function () {
        return privates ( this ).test;
      }
    }
  )
  
  Class ( "TypeTestClassChild" , TypeTestClass )(
    function () {
      self.__init__ = function () {}
    }
  )
  
  assert.True ( isType ( TypeTestClass () , TypeTestClass ) );
  assert.True ( isType ( TypeTestClassChild () , TypeTestClass ) );
  assert.True ( isType ( TypeTestClassChild () , TypeTestClassChild ) );
  assert.True ( isType ( TypeTestClassChild , Class ) );
}

exports.typeInstanceTester = function () {
  var typedArray = type ( [0,1,2,3,4,5] , "myArray"),
      typedObject = type ({
        test1 : 100,
        test2 : 200,
        test3 : function () {
          return 300;
        }
      } , "myObject" ),
      typedString = type ( "typedString" , "myString" ),
      typedNumber = type ( 300 , "myNumber" ),
      typedRegExp = type ( /typedRegExp/ , "myRegExp" ),
      typedFunction = type ( function () { return 300  } , "myFunction" ),
      typedDate = type ( new Date () , "myDate" );
  
  assert.True ( isType ( typedArray , myArray ) );
  assert.True ( isType ( typedObject , myObject ) );
  assert.True ( isType ( typedString , myString ) );
  assert.True ( isType ( typedNumber , myNumber ) );
  assert.True ( isType ( typedRegExp , myRegExp ) );
  assert.True ( isType ( typedNumber , myNumber ) );
  assert.True ( isType ( typedFunction , myFunction ) );
  
  assert.True ( isType ( myArray , myArray ) );
  assert.True ( isType ( myObject , myObject ) );
  assert.True ( isType ( myString , myString ) );
  assert.True ( isType ( myNumber , myNumber ) );
  assert.True ( isType ( myRegExp , myRegExp ) );
  assert.True ( isType ( myNumber , myNumber ) );
  assert.True ( isType ( myFunction , myFunction ) );
  
  assert.True ( isType ( myArray () , myArray ) );
  assert.True ( isType ( myObject () , myObject ) );
  assert.True ( isType ( myString () , myString ) );
  assert.True ( isType ( myNumber () , myNumber ) );
  assert.True ( isType ( myRegExp () , myRegExp ) );
  assert.True ( isType ( myNumber () , myNumber ) );
  assert.True ( isType ( new myFunction () , myFunction ) );
  
  var count = -1;
  typedArray.forEach ( function ( i ) {
    assert.True ( i === ++count  );
  })
  count = 100;
  for ( var prop in typedObject ) {
    if ( typeof typedObject [ prop ] === "function" ){
      assert.True ( count === typedObject [ prop ] () );
    }else{
      assert.True ( count  === typedObject [ prop ] );
    }
    count = count + 100;
  }

  assert.True ( /typedString/.test ( typedString ) );
  assert.True ( ( typedNumber + 1 )  === 301 );
  assert.True ( typedRegExp.test ( "typedRegExp" ) );
 
}
