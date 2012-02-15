
trait TestTraitP {
  private _greaterThant( x , y ) -> x < y;
  public greaterThan( x , y ) -> x < y;
}

trait TestTrait {
  requires compare;
  mixin TestTraitP
  private _lessThan( x , y ) -> x < y;
  public lessThan( x , y ) -> x < y;
}

var traitexp = trait {
      private mastercmp( x, y ) -> x > y;
      public lessthan( x , y ) -> x > y;
    }