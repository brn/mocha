@def std {
  @def( __callblock ) forEach( array , index , item , block ) {
    var str = array.toString(),
        blockStr = block.toString(),
        indexStr = index.toString(),
        itemStr = item.toString();
    return "(function () {"
      + "var " + itemStr + " = " + str
      + "if ( Object.prototype.toString.call(" + str + ") === '[object Array]' ) {"
      + "for( var i = 0,len = " + itemStr + ".length(); i < len; i++ )" + blockStr
      + "} else if( Object.prototype.toString.call(" + str + ") === '[object object]' ) {"
      + "for( var i in tmp )" + blockStr
      + "}})();";
  }
}

std.forEach!( [0,1,2,3,5] , i , arr ) {
  if ( i === 0 ) {
    
  }
}