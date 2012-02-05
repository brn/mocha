var testvalue = 1;
do {
  break;
} while( testvalue );

var testDstaObject = { test : 200  };
var testDstaTarget;

do {
  break;
} while ( ( {test:testDstaTarget} = testDstaObject ) );

var i = 1;

do break;
while( i );

