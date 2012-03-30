var fs = mocha.import("fs");
print(fs);
var dir = new fs.Dir("./mains/");
print(dir.entries(true).forEach(function (item) {
  mocha.setting.addSetting(item.fullpath());
}));


