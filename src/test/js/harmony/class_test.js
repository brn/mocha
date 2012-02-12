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
  constructor( this.name = 200 , private.addr = "tokyo" , private.age ) {}
  public getName() {
    return "hogehoge";
  }
}

class DeriveTest extends BaseTest {
}


@assert( true , new DeriveTest().getName() === "hogehoge" );



