
module __MC_runtime {
  var instance_prop = {};
  export __hide_prop( id , prop , value ) {
    if ( !( id in instance_prop ) ) {
      instance_prop[ id ] = {}
    }
    instance_prop[ id ][ prop ] = value;
  }
  export __hidden(){}
}


