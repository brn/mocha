var fs = mocha.import("fs"),
    watcher = mocha.import("script").watcher;
var dir = new fs.Dir("./mains/");
dir.entries(true).forEach(function (item) {
  console.log(item.fullpath);
  watcher.addSetting(item.fullpath);
});


