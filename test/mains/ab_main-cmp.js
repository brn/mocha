(function(){
  var __global_exports = {};
  __global_exports["/var/samba/back/mocha/test/3rd-modules/Base.js"] = (function(){
    var exports = {};
    Class("Base")(function (self, privates) {
      self.__static__.init = function () {
        $("img[src*=_off]").bind("mouseover", function () {
          this.src = this.src.replace("_off", "_on");
        }).bind("mouseout", function () {
          this.src = this.src.replace("_on", "_off");
        });
      };
    });
    
    return exports;
  })();
  __global_exports["/var/samba/back/mocha/test/mains/ab_main.js"] = (function(){
    var exports = {};
    var Base = __global_exports["../3rd-modules/Base"].Base;
    function main() {
      ready(function () {
        Base.init();
      });
    }
    exports.main = main;
    
    return exports;
  })();
})();