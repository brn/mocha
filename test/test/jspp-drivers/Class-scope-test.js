
var scope = require ( "./scope" );

exports.ClassScopeTest = function () {
  
  assert.True ( ( "publicClass" in scope  ) );
  assert.False ( ( "privateClass" in scope ) );
  
  assert.True ( "publicMember" in scope );
  
}

