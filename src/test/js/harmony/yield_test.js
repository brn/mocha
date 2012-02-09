yieldTest()-> {
  yield arguments;
}

yieldTest2() -> {
  for ( var i = 0; i < 10; i++ ) {
    yield i;
  }
}

var generator = yieldTest2();

@assert( true , generator.next() === 0 );
@assert( true , generator.next() === 1 );
@assert( true , generator.next() === 2 );
@assert( true , generator.next() === 3 );
@assert( true , generator.next() === 4 );
@assert( true , generator.next() === 5 );
@assert( true , generator.next() === 6 );
@assert( true , generator.next() === 7 );
@assert( true , generator.next() === 8 );
@assert( true , generator.next() === 9 );


yieldTest3() -> {
  for ( var i = 0; i < 10; i++ ) {
    if ( i % 2 === 0 ) {
      yield i;
    }
  }
}
generator = yieldTest3();
@assert( true , generator.next() === 0 );
@assert( true , generator.next() === 2 );
@assert( true , generator.next() === 4 );
@assert( true , generator.next() === 6 );
@assert( true , generator.next() === 8 );

yieldTest3() -> {
  for ( var i = 0; i < 10; i++ ) {
    for ( var j = 0; j < 10; j++ ) {
      if ( j % 2 === 0 ) {
        yield j;
      }
    }
  }
}
generator = yieldTest3();
@assert( true , generator.next() === 0 );
@assert( true , generator.next() === 2 );
@assert( true , generator.next() === 4 );
@assert( true , generator.next() === 6 );
@assert( true , generator.next() === 8 );

@assert( true , generator.next() === 0 );
@assert( true , generator.next() === 2 );
@assert( true , generator.next() === 4 );
@assert( true , generator.next() === 6 );
@assert( true , generator.next() === 8 );

@assert( true , generator.next() === 0 );
@assert( true , generator.next() === 2 );
@assert( true , generator.next() === 4 );
@assert( true , generator.next() === 6 );
@assert( true , generator.next() === 8 );

@assert( true , generator.next() === 0 );
@assert( true , generator.next() === 2 );
@assert( true , generator.next() === 4 );
@assert( true , generator.next() === 6 );
@assert( true , generator.next() === 8 );

@assert( true , generator.next() === 0 );
@assert( true , generator.next() === 2 );
@assert( true , generator.next() === 4 );
@assert( true , generator.next() === 6 );
@assert( true , generator.next() === 8 );

@assert( true , generator.next() === 0 );
@assert( true , generator.next() === 2 );
@assert( true , generator.next() === 4 );
@assert( true , generator.next() === 6 );
@assert( true , generator.next() === 8 );

@assert( true , generator.next() === 0 );
@assert( true , generator.next() === 2 );
@assert( true , generator.next() === 4 );
@assert( true , generator.next() === 6 );
@assert( true , generator.next() === 8 );

@assert( true , generator.next() === 0 );
@assert( true , generator.next() === 2 );
@assert( true , generator.next() === 4 );
@assert( true , generator.next() === 6 );
@assert( true , generator.next() === 8 );

@assert( true , generator.next() === 0 );
@assert( true , generator.next() === 2 );
@assert( true , generator.next() === 4 );
@assert( true , generator.next() === 6 );
@assert( true , generator.next() === 8 );

@assert( true , generator.next() === 0 );
@assert( true , generator.next() === 2 );
@assert( true , generator.next() === 4 );
@assert( true , generator.next() === 6 );
@assert( true , generator.next() === 8 );


yieldTest4() -> {
  var i = 0;
  while ( ++i < 10 ) {
    yield i;
  }
}

generator = yieldTest4();
@assert( true , generator.next() === 1 );
@assert( true , generator.next() === 2 );
@assert( true , generator.next() === 3 );
@assert( true , generator.next() === 4 );
@assert( true , generator.next() === 5 );
@assert( true , generator.next() === 6 );
@assert( true , generator.next() === 7 );
@assert( true , generator.next() === 8 );
@assert( true , generator.next() === 9 );

yieldTest5() -> {
  var i = 0;
  do{
    yield i;
  }while ( ++i < 10 );
}

generator = yieldTest5();
@assert( true , generator.next() === 0 );
@assert( true , generator.next() === 1 );
@assert( true , generator.next() === 2 );
@assert( true , generator.next() === 3 );
@assert( true , generator.next() === 4 );
@assert( true , generator.next() === 5 );
@assert( true , generator.next() === 6 );
@assert( true , generator.next() === 7 );
@assert( true , generator.next() === 8 );
@assert( true , generator.next() === 9 );

yieldTest6()-> {
  for ( var i = 0;i<10; i++ ) {
    var m = yield i;
    if ( m === true ) {
      yield i + 1;
    } else if ( m === false ){
      yield i - 1;
    } else {
      yield i;
    }
  }
}

generator = yieldTest6();
@assert( true , generator.next() === 0 );
@assert( true , generator.send( true ) === 1 );
@assert( true , generator.send( false ) === 1 );
@assert( true , generator.send( true ) === 2 );
@assert( true , generator.send( false ) === 2 );
@assert( true , generator.send( true ) === 3 );
@assert( true , generator.send( true ) === 3 );
@assert( true , generator.send( true ) === 4 );
@assert( true , generator.send( false ) === 4 );
@assert( true , generator.send( true ) === 5 );

yieldTest7()-> {
  for ( var i = 0;i<10; i++ ) {
    var m = yield i;
    for ( var j = 0;j<10;j++ ) {
      if ( m === true ) {
        yield j * 2;
      } else if ( m === false ){
        yield j / 2;
      } else {
        yield j;
      }
    }
  }
}


generator = yieldTest7();
@assert( true , generator.next() === 0 );
@assert( true , generator.send( true ) === 0 );
@assert( true , generator.send( false ) === 2 );
@assert( true , generator.send( true ) === 4 );
@assert( true , generator.send( false ) === 6 );
@assert( true , generator.send( true ) === 8 );
@assert( true , generator.send( true ) === 10 );
@assert( true , generator.send( true ) === 12 );
@assert( true , generator.send( false ) === 14 );
@assert( true , generator.send( true ) === 16 );
@assert( true , generator.send( true ) === 18 );
@assert( true , generator.send( false ) === 1 );
@assert( true , generator.send( true ) === 0 );
@assert( true , generator.send( false ) === 2 );
@assert( true , generator.send( true ) === 4 );
@assert( true , generator.send( true ) === 6 );
@assert( true , generator.send( true ) === 8 );
@assert( true , generator.send( false ) === 10 );
@assert( true , generator.send( true ) === 12 );


yieldTest8()-> {
  for ( var i = 0;i<10; i++ ) {
    for ( var j = 0;j<10;j++ ) {
      var m = yield i;
      if ( m === true ) {
        yield j * 2;
      } else if ( m === false ){
        yield j / 2;
      } else {
        yield j;
      }
    }
  }
}


generator = yieldTest8();
@assert( true , generator.next() === 0 );
@assert( true , generator.send( true ) === 0 );
@assert( true , generator.send( false ) === 0 );
@assert( true , generator.send( true ) === 2 );
@assert( true , generator.send( false ) === 0 );
@assert( true , generator.send( true ) === 4 );
@assert( true , generator.send( true ) === 0 );
@assert( true , generator.send( true ) === 6 );
@assert( true , generator.send( false ) === 0 );
@assert( true , generator.send( true ) === 8 );
@assert( true , generator.send( true ) === 0 );
@assert( true , generator.send( false ) === 2.5 );
@assert( true , generator.send( true ) === 0 );
@assert( true , generator.send( false ) === 3 );
@assert( true , generator.send( true ) === 0 );
@assert( true , generator.send( true ) === 14 );
@assert( true , generator.send( true ) === 0 );
@assert( true , generator.send( false ) === 4 );
@assert( true , generator.send( true ) === 0 );


yieldTest9()-> {
  var flg = false;
  for ( var i = 0; i < 10; i++ ) {
    try {
      var m = ( flg )? 1 : 0
      yield m;
      ddddd();
    } catch(e) {}
    finally {
      flg = true;
    }
  }
}
generator = yieldTest9();
@assert( true , generator.next() === 0 );
@assert( true , generator.next() === 1 );
@assert( true , generator.next() === 1 );
@assert( true , generator.next() === 1 );
@assert( true , generator.next() === 1 );

yieldTest10()-> {
  for ( var i = 0; i < 10; i++ ) {
    var type = yield;
    switch( type ) {
    case 0 :
      yield 200;
    case 2 :
      yield 400;
    case 3 :
      yield 600;
    default :
      yield 700;
    }
  }
}
generator = yieldTest10();
generator.next();
@assert( true , generator.send( 0 ) === 200 );
generator.next()
@assert( true , generator.send( 2 ) === 400 );
generator.next()
@assert( true , generator.send( 3 ) === 600 );
generator.next()
@assert( true , generator.send(null) === 700 );

