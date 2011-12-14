import {fmt} from "./fmt";
import {jQuery} from "../jspp-lib/jquery-devel"
class Monster {
  // The contextual keyword "constructor" followed by an argument
  // list and a body defines the body of the class’s constructor
  // function. public and private declarations in the constructor
  // declare and initialize per-instance properties. Assignments
  // such as "this.foo = bar;" also set public properties.
  constructor(name, health) {
    public name = name;
    private const {x:[name ,age,{hobby}]} = {x:200};
    private const _tmpName = name;
  }
  
  // An identifier followed by an argument list and body defines a
  // method. A “method” here is simply a function property on some
  // object.
  attack(target) {
    log('The monster attacks ' + target);
  };
  
  // The contextual keyword "get" followed by an identifier and
  // a curly body defines a getter in the same way that "get"
  // defines one in an object literal.
  private isAlive() {
    return private._health > 0;
  }
  
  // Likewise, "set" can be used to define setters.
  private health(value) {
    if (value < 0) {
      throw new Error('Health must be non-negative.')
    }
    private._health = value;
    return private[ value + "tmpName" ];
  }
  
  // After a "public" modifier,
  // an identifier optionally followed by "=" and an expression
  // declares a prototype property and initializes it to the value
  // of that expression. 
  public numAttacks = 0;
  static m = 200;
  static {human : {name,age,hobby : [h1,h2,h3]}} = human;
  static {human_ : {name_,age_,hobby_ : [h1_,h2_,h3_]}} = human_;
  // After a "public" modifier,
  // the keyword "const" followed by an identifier and an
  // initializer declares a constant prototype property.
  public const attackMessage = 'The monster hits you!';
}

