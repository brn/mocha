


document.getElementById( "id" );
document.test.test2.test3();
document.test.test3 = 1;
document.{
  extendtest : true,
  extendtest2 : false
};
({destructuring,destructuring2}) = {destructuring:1,destructuring2:2};
({destructuring,destructuring2}) = {destructuring,destructuring2};
({destructuring,dsta2 : [destructuring2]}) = {destructuring:1,destructuring2:2};
({destructuring,dsta2 : destructuring2,dsta3 : {dsta4}}) = {destructuring,destructuring2};

[destructuring,destructuring2] = [0,1];
[destructuring,[destructuring2]] = [0,[1]];
[{dsta,dsta2:[a]},{dsta2}] = [{dsta}];
({getname , getage}) = {
  getname : function () { return "aaaa" },
  getage : function () { return "aaaaa"; }
};
({getname , getage}) = {
  getname(){ return "aaaa" },
  getage() { return "aaaaa"; }
};
({getname , getage}) = {
  getname()->"aaaa",
  getage()->"aaaaa"
};

({getname , getage}) = {
  getname->"aaaa",
  getage->"aaaaa"
}

var m = function () { return function () { return function() {} }; }
var m2 = {m : {m:{m:function () {}}}}
var m3 = {m : {m:{m}}}
var instance = new m();
var instance2 = new new m();
var instance3 = new new new m();
var instance4 = new m2.m.m();
var instance5 = new new new m3.m.m();