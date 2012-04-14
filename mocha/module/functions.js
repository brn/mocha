module Functions {

  export once( fn ) {
    var isRun = false;
    return => ( isRun )? fn.apply( this , arguments ) : undefined;
  }

  export memoize( fn ) {
    var memo = undefined;
    return => ( memo === undefined )? memo = fn.apply( this , arguments ) : memo;
  }

  export compose( ...fns ) {
    for ( var i = 0,ret,len = fns.length; i < len; i++ ) {
      ret = fns[ i ]( ret );
    }
    return ret;
  }
  
  export equalTo = ( arg1 , arg2 ) -> arg1 === arg2;

  export greater = ( arg1 , arg2 ) -> arg1 > arg2;

  export greaterEq = ( arg1 , arg2 ) -> arg1 >= arg2;

  export less = ( arg1 , arg2 ) -> arg1 < arg2;

  export lessEq = ( arg1 , arg2 ) -> arg1 <= arg2;

  export notEqual = ( arg1 , arg2 ) -> arg1 !== arg2;
}