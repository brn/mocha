
function switchTest( type ) {
  var ret = 0;
  switch( type ) {
  case 1 :
    ret = 0;
    ret += 1;
    return ret;
  case 2 :
    ret = 100;
    break;
    
  case 3 :
  case 4 :
    ret = 0;
    ret++;
    break;
    
  case 5 : {
    ret = 0;
    ret = 1;
  }
    break;
  case 6 :
  case 7 : {
    ret = 10;
  }
    break;
  default : 
    ret = 100;
  }
  return ret;
}

@assert( true , switchTest( 1 ) === 1 );
@assert( true , switchTest( 2 ) === 100 );
@assert( true , switchTest( 3 ) === 1 );
@assert( true , switchTest( 4 ) === 1 );
@assert( true , switchTest( 5 ) === 1 );
@assert( true , switchTest( 6 ) === 10 );
@assert( true , switchTest( 7 ) === 10 );
@assert( true , switchTest( 8 ) === 100 );

