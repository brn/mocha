module fmt {
  export fmt = ( format , args )-> {
    for ( var i in args ) {
      let reg = new RegExp( ( "\\$\\{" + i + "\\}" ) , "g" );
      format = format.replace( reg , args[ i ] );
    }
    return format;
  }
};