var fs = mocha.import("fs"),
    watcher = mocha.import("script").watcher;
var dir = new fs.Dir("./mains/");
var dir2 = new fs.Dir("../src/test/js/harmony/");
dir.entries(false).forEach(function (item) {
  if (item.fullpath.indexOf('.js') > -1) {
    watcher.addSetting(item.fullpath, {
      deployDir : './deploy',
      deployName : item.filename.replace('.js', '-cmp.js'),
      options : {
        prettyPrint : true
      }
    });
  }
});


