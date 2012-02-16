

var testObject = {
      value1 : 100,
      value2 : 200,
      value3 : 300
    }
var test = ( x for each ( x in testObject ) );

console.log(test.next())