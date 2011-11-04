
exports.typeOfTest = function () {
  var _Object = {},
      _Array = [],
      _Function = function () {},
      _String = "",
      _Number = 100,
      _RegExp = /test/,
      _Boolean = true
  
  Class ( "__testClass" ) (
    function ( self, privates ) {
      self.__init__ = function () {};
    }
  )
  
  assert.True ( typeOf ( _Object ) === "Object" );
  assert.True ( typeOf ( _Array ) === "Array" );
  assert.True ( typeOf ( _Function ) === "Function" );
  assert.True ( typeOf ( _String ) === "String" );
  assert.True ( typeOf ( _Number ) === "Number" );
  assert.True ( typeOf ( _RegExp ) === "RegExp" );
  assert.True ( typeOf ( _Boolean ) === "Boolean" );
  assert.True ( typeOf ( testClass ) === "Class" );
  
}

exports.typeOfTestForUserTyped = function () {
  
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
  
  assert.True ( typeOf ( typedArray ) === "myArray" );
  assert.True ( typeOf ( typedObject ) === "myObject" );
  assert.True ( typeOf ( typedString ) === "myString" );
  assert.True ( typeOf ( typedNumber ) === "myNumber" );
  assert.True ( typeOf ( typedRegExp ) === "myRegExp" );
  assert.True ( typeOf ( typedNumber ) === "myNumber" );
  assert.True ( typeOf ( typedFunction ) === "myFunction" );
  assert.True ( typeOf ( typedDate ) === "myDate" );
  
  assert.True ( typeOf ( myArray ) === "Class" );
  assert.True ( typeOf ( myObject ) === "Class" );
  assert.True ( typeOf ( myString ) === "Class" );
  assert.True ( typeOf ( myNumber ) === "Class" );
  assert.True ( typeOf ( myRegExp ) === "Class" );
  assert.True ( typeOf ( myNumber ) === "Class" );
  assert.True ( typeOf ( myFunction ) === "myFunction" );
  assert.True ( typeOf ( myDate ) === "Class" );
  
  assert.True ( typeOf ( myArray () ) === "myArray" );
  assert.True ( typeOf ( myObject () ) === "myObject" );
  assert.True ( typeOf ( myString () ) === "myString" );
  assert.True ( typeOf ( myNumber () ) === "myNumber" );
  assert.True ( typeOf ( myRegExp () ) === "myRegExp" );
  assert.True ( typeOf ( myNumber () ) === "myNumber" );
  assert.True ( typeOf ( new myFunction () ) === "myFunction" )
  assert.True ( typeOf ( myDate () ) === "myDate" );
  
}

exports.baseTypeOfTest = function () {
  
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
  
  assert.True ( baseTypeOf ( typedArray ) === "Object" );
  assert.True ( baseTypeOf ( typedObject ) === "Object" );
  assert.True ( baseTypeOf ( typedString ) === "Object" );
  assert.True ( baseTypeOf ( typedNumber ) === "Object" );
  assert.True ( baseTypeOf ( typedRegExp ) === "Object" );
  assert.True ( baseTypeOf ( typedNumber ) === "Object" );
  assert.True ( baseTypeOf ( typedFunction ) === "Function" );
  
  assert.True ( baseTypeOf ( myArray ) === "Function" );
  assert.True ( baseTypeOf ( myObject ) === "Function" );
  assert.True ( baseTypeOf ( myString ) === "Function" );
  assert.True ( baseTypeOf ( myNumber ) === "Function" );
  assert.True ( baseTypeOf ( myRegExp ) === "Function" );
  assert.True ( baseTypeOf ( myNumber ) === "Function" );
  assert.True ( baseTypeOf ( myFunction ) === "Function" );
  
  assert.True ( baseTypeOf ( myArray () ) === "Object" );
  assert.True ( baseTypeOf ( myObject () ) === "Object" );
  assert.True ( baseTypeOf ( myString () ) === "Object" );
  assert.True ( baseTypeOf ( myNumber () ) === "Object" );
  assert.True ( baseTypeOf ( myRegExp () ) === "Object" );
  assert.True ( baseTypeOf ( myNumber () ) === "Object" );
  assert.True ( baseTypeOf ( new myFunction () ) === "Object" )
  
}

exports.typeFromTest = function () {
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
  
  assert.True ( typeFrom ( typedArray ) === myArray );
  assert.True ( typeFrom ( typedObject ) === myObject );
  assert.True ( typeFrom ( typedString ) === myString );
  assert.True ( typeFrom ( typedNumber ) === myNumber );
  assert.True ( typeFrom ( typedRegExp ) === myRegExp );
  assert.True ( typeFrom ( typedFunction ) === myFunction );
  assert.True ( typeFrom ( typedDate ) === myDate );
  
}

exports.toIntegerTest = function () {
  
  var str1 = "067",
      str2 = "NaN",
      str3 = "aaa",
      str4 = "10000000000000000000000000",
      str5 = {},
      num = 100
  
  assert.True ( toInteger ( str1 ) === 67 )
  assert.True ( toInteger ( str2 ) === 0 )
  assert.True ( toInteger ( str3 ) === 0 )
  assert.True ( toInteger ( str4 ) === 10000000000000000000000000 )
  assert.True ( toInteger ( str5 ) === 0 );
  assert.True ( toInteger ( num ) === 100 );
  
}
