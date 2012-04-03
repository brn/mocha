var fs = mocha.import("fs"),
    watcher = mocha.import("script").watcher;
var dir = new fs.Dir("./mains/");
var dir2 = new fs.Dir("../src/test/js/harmony/");
dir.entries(false).forEach(function (item) {
  console.log(item.fullpath);
  watcher.addSetting(item.fullpath);
});


