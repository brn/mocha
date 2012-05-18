@include '_module'
module objUtils {

  const {toString} = Object.prototype.toString;

  module extractor {
    export functions( obj ) {
      var ret = [],
          iter = -1;
      for (var i in obj) {
        if ( typeof obj === "function" ) {
          ret[ ++iter ] = obj[ i ];
        }
      }
      return ret;
    }

    export searchByKey(obj, regexp) {
      var ret = [];
      for var prop in obj {
        if regexp.test(prop) {
          ret[ret.length] = {
            key : prop,
            value : obj[prop]
          }
        }
      }
      return ret;
    }

    export searchByValues(obj, ...typeStrings) {
      var ret = [],
          typeString = typeString.join(' ');
      for var prop in obj {
        var type = typeof obj[prop],
            doPush = false;
        if type !== 'object' && typeString.contain(' ' + type + ' ') {
          doPush = true;
        } else if Array.isArray(obj[prop]) && typeString.contain(' array ') {
          doPush = true;
        } else if RegExp instanceof obj[prop] && typeString.contain(' regexp ') {
          doPush = true;
        } else if typeString.contain(' object ') {
          doPush = true;
        }
        if doPush {
          ret[ret.length] = {
            key : prop,
            value : obj[prop]
          }
        }
      }
      return ret;
    }
  }

  if (typeof(__Runtime._global['uneval']) !== 'function') {
    var stringOf = (obj) -> obj.toString(),
        name2uneval = {
          '[object Boolean]':stringOf,
          '[object Number]': stringOf,
          '[object String]': (o) -> '"' + o + '"',
          'undefined': -> 'undefined',
          '[object Function]': (m) -> Function.prototype.toString.call(m),
          '[object Array]' : (arr) -> {
            var str = ((arr.length > 0)? arr : ['']).reduce((item, item2) => @inspect(item) + ', ' + @inspect(item2));
            return '[' + (str? str : '') + ']';
          },
          '[object Arguments]' : (arr) -> name2uneval['[object Array]'].call(this, Array.prototype.slice.call(arr)),
          '[object RegExp]' : stringOf,
          '[object Date]' : (d) -> d.toJSON(),
          '[object Undefined]' : -> 'undefined'
        };

    class Inspector {
      constructor() {
        @_indent = '';
        @_depth = 0;
      }

      public inspect (obj) {
        if obj === null {
          return 'null';
        }
        var str = toString.call(obj);
        if str in name2uneval {
          return name2uneval[str].call(this, obj, @_depth);
        } else {
          return @_inspectObject(obj);
        }
      }

      private _addIndent () {
        @_indent += '  ';
        @_depth++;
      }

      private _outdent () {
        @_indent = @_indent.slice(0, @_indent.length - 2);
        @_depth--;
      }

      _inspectObject = function(o){
        @_addIndent();
        var src = [],
            props = Object.getOwnPropertyNames(o);
        for var i = 0,len = props.length; i < len; i++ {
          src[src.length] = props[i]  + ':' + @inspect(o[props[i]], 1);
        };
        var ret;
        if (src.length > 0) {
          ret = '{' + '\n' + @_indent + src.join('\n' + @_indent) + '\n';
          @_outdent();
          ret += @_indent + '}';
        } else {
          ret = '{}';
        }
        return ret;
      }
    }
    export uneval (o) -> new Inspector().inspect(o);
  } else {
    export uneval (o) -> __Runtime._global.uneval(o);
  }

  export clone( obj ) -> Function(("return " + uneval(obj)))();

  export isObject(o) -> toString.call(o) === '[object Object]';
}