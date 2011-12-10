/**module {
  export fmt ( format , args ) {
    for ( var i in args ) {
      let reg = new RegExp( ( "\\$\\{" + i + "\\}" ) , "g" );
      format = format.replace( reg , args[ i ] );
    }
    return format;
  }
  export x,y,z;
 };*/
import {ext:{Objects}} from "./ecma262-5th-compatible-devel";
var {a:[{z:[name , test]},yt,{x}]} = [200,2,2];

var x = ({x,g:[z,yg]},[aaa,bbb],...rest)->{return x*y*z;}

[x,y,z] = [100,200,300];

var {m} = 200;

for each( var {x} in obj ) {
  console.log(x);
}