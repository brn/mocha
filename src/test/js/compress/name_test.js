function b () {};
(function () {
  var c = 0;
  var test1 = function (){
    b();
  }
  var test2 = function () {
        var c,l;
        l = b();
      };
})();