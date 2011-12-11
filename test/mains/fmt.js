import ext from "./ecma262-5th-compatible-devel";
module fmt {
  export fmt ( format , args ) {
    for ( var i in args ) {
      let reg = new RegExp( ( "\\$\\{" + i + "\\}" ) , "g" );
      format = format.replace( reg , args[ i ] );
    }
    return format;
  }
  module text {
    export text ( format , args ) {
      return fmt( format , args );
    }
  }
  export const x = (x,y)->x*y;
  export x,y,z;
};
var {a:[{z:[name , test]},yt,{x}]} = [200,2,2];

function x({x,g:[z,yg]},[aaa,bbb],...rest){return x*y*z;}
let x = -> ({x}) = {x:200}
[x,y,z] = [100,200,300];

var {m} = 200;

for each( var {x} in obj ) {
  console.log(x);
 }

switch ( ([x,yn,z] = [1,2,5,6]) ) {
default : 
}

if ( ( [x,y,z] = [1,2,4]) ) {
  console.log(x,y,z);
} else if ( ( [a,b,c] = [1,2,5] ) ) {
  console.log( a,b,c );
}

versionof(all) {
  console.log(1);
}

versionof(debug) {
  console.log(2);
}