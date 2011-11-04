
require.setActivePath ( "${cwd}test/jspp-drivers/" );

#define TEST_MACRO (x){
  x.length > 0? x : "nothing";
} #enddef

var TestUnit = require ( "JsppTestUnit" ).JppTestUnit,
    classTest = require ( "Class-test" ),
    typeTest = require ( "type-test" ),
    scopeTest = require ( "Class-scope-test" ),
    builtinTest = require ( "builtin-test" ),
    ppTest = require ( "preprocessor-test" ),
    Hash = require ( "Hash" ).Hash;

function main () {
  
  var rett = TEST_MACRO ( "test" );
  
  console.log ( rett );
  
  var testUnit = TestUnit ( window , document );
  
  var hash = Hash ( builtinTest )  
  
  console.log ( hash.keys () );
  
  testUnit.addTestDriver ( classTest );
  testUnit.addTestDriver ( typeTest );
  testUnit.addTestDriver ( scopeTest );
  testUnit.addTestDriver ( builtinTest );
  testUnit.runAllTest ();
}
exports.main = main;

