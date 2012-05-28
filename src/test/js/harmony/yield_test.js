var generator;
var tests = {
      case1->{
        yieldTest2() -> {
          for ( var i = 0; i < 10; i++ ) {
            yield i;
          }
        }

        generator = yieldTest2();

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
      },

      case2-> {
        yieldTest3()-> {
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
      },
      case3->{
        yieldTest4() -> {
          for ( var i = 0; i < 10; i++ ) {
            for ( var j = 0; j < 10; j++ ) {
              if ( j % 2 === 0 ) {
                yield j;
              }
            }
          }
        }
        generator = yieldTest4();
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
      },
      case4 -> {
        yieldTest5() -> {
          var i = 0;
          while ( ++i < 10 ) {
            yield i;
          }
        }

        generator = yieldTest5();
        @assert( true , generator.next() === 1 );
        @assert( true , generator.next() === 2 );
        @assert( true , generator.next() === 3 );
        @assert( true , generator.next() === 4 );
        @assert( true , generator.next() === 5 );
        @assert( true , generator.next() === 6 );
        @assert( true , generator.next() === 7 );
        @assert( true , generator.next() === 8 );
        @assert( true , generator.next() === 9 );
      },
      case5 -> {
        yieldTest6() -> {
          var i = 0;
          do{
            yield i;
          }while ( ++i < 10 );
        }

        generator = yieldTest6();
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
      },
      case6 -> {
        yieldTest7()-> {
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

        generator = yieldTest7();
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
      },
      case7 -> {
        yieldTest8()-> {
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


        generator = yieldTest8();
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
      },
      case8 -> {

        yieldTest9()-> {
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


        generator = yieldTest9();
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
      },
      case9 -> {

        yieldTest10()-> {
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
        generator = yieldTest10();
        @assert( true , generator.next() === 0 );
        @assert( true , generator.next() === 1 );
        @assert( true , generator.next() === 1 );
        @assert( true , generator.next() === 1 );
        @assert( true , generator.next() === 1 );
      },
      case10 -> {
        yieldTest11()-> {
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
        generator = yieldTest11();
        generator.next();
        @assert( true , generator.send( 0 ) === 200 );
        generator.next()
        @assert( true , generator.send( 2 ) === 400 );
        generator.next()
        @assert( true , generator.send( 3 ) === 600 );
        generator.next()
        @assert( true , generator.send(null) === 700 );
      },
      case11 -> {

        yieldTest12()-> {
          for ( var i = 0; i < 15; i++ ) {
            var type = yield;
            switch( type ) {
            case 4 :
            case 0 :
              yield 200;
            case 5 :
              break;
            case 6 :
            case 2 :
              yield 400;
            case 3 :
              yield 600;
            default :
              yield 700;
            }
          }
        }
        generator = yieldTest12();
        generator.next();
        @assert( true , generator.send( 0 ) === 200 );
        generator.next();
        @assert( true , generator.send( 4 ) === 200 );
        generator.next();
        @assert( true , generator.send( 2 ) === 400 );
        generator.next()
        @assert( true , generator.send( 5 ) === undefined );
        @assert( true , generator.send( 3 ) === 600 );
        generator.next()
        @assert( true , generator.send(null) === 700 );
      },
      case12 -> {

        yieldTest13 -> {
          var obj = {x:200,y:300,z:400};
          for ( var i in obj ) {
            yield [ i , obj[ i ] ];
          }
        }

        generator = yieldTest13();
        var ret = generator.next();
        @assert( true , ret[ 0 ] === "x" );
        @assert( true , ret[ 1 ] === 200 );
        ret = generator.next();
        @assert( true , ret[ 0 ] === "y" );
        @assert( true , ret[ 1 ] === 300 );
        ret = generator.next();
        @assert( true , ret[ 0 ] === "z" );
        @assert( true , ret[ 1 ] === 400 );
      },
      case13 -> {
        keys( obj ) -> {
          for ( var prop in obj ) {
            if ( obj.hasOwnProperty( prop ) ) {
              yield prop;
            }
          }
        }

        var testObject = {
              value1 : 1,
              value2 : 2,
              value3 : 3,
              value4 : 4
            };
        try {
          var itemGen = keys( testObject );
          @assert( true , itemGen.next() == "value1" );
          @assert( true , itemGen.next() == "value2" );
          @assert( true , itemGen.next() == "value3" );
          @assert( true , itemGen.next() == "value4" );
          //@assert( true , itemGen.next() == "value5" );
        } catch( e ) {
          //@assert( true , Runtime.isStopIteration( e ) );
        }
      }

    }

for ( var i = 1; i < 13;i++ ) {
  tests[ "case" + i ]();
}

