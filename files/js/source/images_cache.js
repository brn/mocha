class CacheFunctions {
  static checkType(arg) -> {
    if typeof arg === 'string' {
      CacheFunctions.caseString(arg);
    } else {
      CacheFunctions.caseArray(arg);
    }
  }
  static caseArray(obj) -> {
    obj.forEach((item, index)->{
      (new Image).src = item;
    });
  }
  static caseString(filename) -> (new Image).src = filename;
}

module imageCache {
  export cache = (filename) -> CacheFunctions.checkType(filename);
}
