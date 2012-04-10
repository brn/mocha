var fs = mocha.import("fs"),
    watcher = mocha.import("script").watcher;
var dir = new fs.Dir("../src/test/js/");
dir.entries(true).forEach(function (item) {
  if (item.fullpath.indexOf('.js') > -1 && item.fullpath.indexOf("-cmp.js") === -1) {
    watcher.addSetting(item.fullpath, {
      deployDir : '../src/test/js/out/devel',
      deployName : item.filename.replace('.js', '-cmp.js'),
      options : {
        prettyPrint : true
      }
    });
  }
});


