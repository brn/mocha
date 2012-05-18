@include '_module';
module funcUtils {

  export once(fn) {
    var isRun = false;
    return => (isRun)? fn.apply(this, arguments) : undefined;
  }

  export memoize( fn ) {
    __Runtime.createUnenumProp(fn, '__cache__', undefined);
    return => (fn.__cache__ === undefined)? fn.__cache__ = fn.apply( this , arguments ) : fn.__cache__;
  }

  export compose(...fns) {
    for var i = 0,ret,len = fns.length; i < len; i++ {
      ret = fns[i](ret);
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
