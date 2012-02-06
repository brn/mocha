var m = "/Users/aono_taketoshi/mocha/test/js"
var v = "/url/local/includes";
function getPathArray( path ) {
  if ( path[ path.length - 1 ] !== '/' ) path += '/';
  var i = 0;
  var arr = [];
  var tmp = "";
  while ( path[i] ) {
    if ( path[ i ] == '/' ) {
      if ( i == 0 )arr.push( "/" );
      else arr.push(tmp);
      tmp = "";
    } else {
      tmp += path[i]
    }
    i++
  }
  return arr
}

var arr1 = getPathArray( m ),
    arr2 = getPathArray( v );
function cmp(arr1 ,arr2) {
  var ret = ""
  var i = 0;
  var unmatch = false;
  while ( arr1[ i ] || arr2[ i ] ) {
    if ( !arr1[ i ] ) {
      ret += arr2[i] + "/";
    }else if ( !arr2[ i ] ) {
      var tmp = "";
      while ( arr1[ i ] ) {
        tmp += "../";
        i++;
      }
      return tmp + ret;
    } else if ( arr1[ i ] != arr2[ i ] ) {
      unmatch = true;
      while ( arr1[i] ) {
        ret += "../";
        arr1.pop();
      }
      while ( arr2[ i ] ) {
        ret += arr2[i] + "/"
        i++
      }
      return ret;
    }
    i++;
  }
  return ret;
}
cmp(arr1 , arr2);