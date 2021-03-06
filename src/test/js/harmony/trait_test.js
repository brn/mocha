trait TestTraitP {
  private _greaterThant( x , y ) -> x < y;
  public greaterThan( x , y ) -> x < y;
}

trait TestTrait {
  requires compare,test1,test2;
  requires test3,test4
  mixin TestTraitP with greaterThan as gt, with _greaterThant as _gt;
  private _lessThan( x , y ) -> x < y;
  public lessThan( x , y ) -> x < y;
}

var traitexp = trait {
      private mastercmp( x, y ) -> x > y;
      public lessthan( x , y ) -> x > y;
    }