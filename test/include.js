fs = mocha.import("fs");
print(fs.Path.getcwd());
print(new fs.Path("../src").fullpath());
var dir = new fs.Dir("./../src/test/js/out/");
print(dir.entries(true).forEach(function (item) {
  print(item.fullpath())
}));
test = mocha.import("./include2.js").test;
print(test());


