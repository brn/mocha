module utility {
  
  export isPrimitive( obj ) {
    switch ( obj ) {
    case Array :
    case String :
    case RegExp :
    case Function :
    case Number :
    case Object :
    case Boolean:
      return true;
    default :
      return false;
    }
  }
  
  const TYPE_STRING = {
          "[object Function]"       :   "Function",
          "[object Array]"          :   "Array",
          "[object String]"         :   "String",
          "[object Boolean]"        :   "Boolean",
          "[object Object]"         :   "Object",
          "[object RegExp]"         :   "RegExp",
          "[object Number]"         :   "Number",
          "[object Window]"         :   "Window",
          "[object global]"         :   "Window",
          "[object HTMLDocument]"   :   "Document",
          "[object HTMLCollection]" :   "NodeList",
          "[object Class]"          :   "Class",
          "[object XML]"            :   "XML",
          "[object Iterator]"       :   "Iterator",
          "[object Element]"        :   "Element",
          "[object Date]"           :   "Date",
          "[object Generator]"      :   "Generator"
        },
        TO_STRING = Object.prototype.toString;
  
  
  export typeOf( obj ) {
    var ret,
        to = TO_STRING,
        os = TYPE_STRING,
        str = obj.toString();
    if ( ( ret = os[ str ] ) ) {
      return ret;
    }
    ret = to.call( obj );
    if ( obj === StopIteration ) {
      return "StopIteration";
    } else if( ( ret = os[ ret ] ) ){
      return ret;
    } else if ( obj.nodeType ){
      return "Element"
    } else {
      return "Object"
    }
  }
  
  export isDefined = ( obj ) -> obj !== undefined && obj !== null;
  
  const rnd = Math.random();
  
  export guidgen = -> ( "{" + [
    rnd().toString(16).slice(2, 10),
    rnd().toString(16).slice(2, 6),
    (rnd() * .0625 /* 0x.1 */ + .25 /* 0x.4 */).toString(16).slice(2, 6),
    (rnd() * .25 /* 0x.4 */ + .5 /* 0x.8 */).toString(16).slice(2, 6),
    rnd().toString(16).slice(2, 14)
  ].join('-') + "}" );
  
}