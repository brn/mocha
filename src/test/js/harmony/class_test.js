class Monster {
  // The contextual keyword "constructor" followed by an argument
  // list and a body defines the body of the class’s constructor
  // function. public and private declarations in the constructor
  // declare and initialize per-instance properties. Assignments
  // such as "this.foo = bar;" also set public properties.
  constructor(name, health) {
    public name = name;
    private health = health;
  }

  // An identifier followed by an argument list and body defines a
  // method. A “method” here is simply a function property on some
  // object.
  public attack(target) {
    log('The monster attacks ' + target);
  }

  // The contextual keyword "get" followed by an identifier and
  // a curly body defines a getter in the same way that "get"
  // defines one in an object literal.
  public isAlive() {
    return private.health > 0;
  }

  // Likewise, "set" can be used to define setters.
  public health(value) {
    if (value < 0) {
      throw new Error('Health must be non-negative.')
    }
    private.health = value
  }

  // After a "public" modifier,
  // an identifier optionally followed by "=" and an expression
  // declares a prototype property and initializes it to the value
  // of that expression.
  public numAttacks = 0;

  // After a "public" modifier,
  // the keyword "const" followed by an identifier and an
  // initializer declares a constant prototype property.
  public const attackMessage = 'The monster hits you!';
  static const DEFAULT_LIFE = 100;
}

var monster = new Monster( "slime" , 100 );
@assert( true , monster.isAlive() );
@assert( 0 , monster.numAttacks );
@assert( 100 , Monster.DEFAULT_LIFE );
@assert( undefined , Monster.health );
class BaseTest {
  constructor( _@name = "foo" , _@addr = "tokyo" , _@age ) {}
  public getName() -> _@name;
}

class DeriveTest extends BaseTest {
  constructor() -> super();
  public getName() -> super.getName();
}


class Derive2 extends DeriveTest {
  constructor -> super();
  public getAddr -> private.addr;
}


class Drive3 prototype BaseTest {
  constructor() {
    super(200, 'tokyo', 20);
  }
}

var TestClass = class {
      constructor( private._name = "test" , private._age = 20 ){}
      public getName -> private._name;
      public getAge -> private._age;
      private class Inner {
        constructor->{}
      }
    }

@assert( true , new DeriveTest().getName() === "foo" );
@assert( true , new Derive2().getAddr() === "tokyo" );
var instance = new TestClass();
@assert( true , instance.getName() === "test" );
@assert( true , instance.getAge() === 20 );

trait TestTrait {
  requires doTestm1;
  public testm1( ...arg )->arg[0];
}

trait TestTrait2 {
  requires doTestm2;
  public testm2( ...arg )->arg[0];
  public testm3->"ok";
}

class MixinTest {
  public doTestm1() -> "aaa";
  public doTestm2() -> "bbb"
  mixin TestTrait with testm1 as m1;
  mixin TestTrait2 without testm2, without testm3;
}
var instance2 = new MixinTest();
@assert( true , instance2.m1( "foo" ) === "foo" );
@assert( true , instance2.m2 === undefined );


class Box {
  constructor( _@width = 100 , _@height = 100 ) {}
  public height -> _@height;
  public width -> _@width;
  private {_type,_max} = {type:200,_max:400};
}

var inst = new Box();
console.log( inst.height() );
console.log( inst.width() );

console.log([,,,,]);
