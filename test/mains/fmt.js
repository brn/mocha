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

var [x,y,z] = [200,2,2];