import functions from 'functions'
import {fmt} from "./fmt"
module {
  export equalTo = ( arg1 , arg2 ) -> arg1 === arg2;
}
class Box {
  constructor(){
    private _width = 0;
  }
  public width -> private._width
}
var m = 0;
