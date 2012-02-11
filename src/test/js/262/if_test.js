function ifTest( flg ) {
  if ( flg === 1 ) {
    return 1;
  } else if ( flg === 2 ) {
    return 2
  } else {
    return 3;
  }
}

@assert( true , ifTest( 1 ) === 1 );
@assert( true , ifTest( 2 ) === 2 );
@assert( true , ifTest( 3 ) === 3 );
