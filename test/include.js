var fs = mocha.import("fs"),
    watcher = mocha.import("script").watcher;

var options = (filename) -> ({
      deployDir : '../src/test/js/out/devel',
      deployName : filename.replace('.js', '-cmp.js'),
      outputCharset : 'shift_jis',
      options : {
        prettyPrint : true,
        debug : true,
        versions : ['ex']
      }
    });

class FileSeaker {
  constructor(_@dir, _@fn = []) {}

  public addSetting(recursive, optionCallback) ->
    new fs.Dir(_@dir).entries(recursive).forEach((item) => _@setCompileSetting(item, optionCallback));

  public addFilter(fn) -> _@fn.push(fn);

  private setCompileSetting(file, optionCallbacks) {
    if (_@fn.every((item) => item(file))) {
      optionCallbacks(file);
    }
  }
}

fileSeaker = new FileSeaker('../src/test/js/');
fileSeaker.addFilter(({fullpath}) -> fullpath.indexOf('.js') > -1);
fileSeaker.addFilter(({fullpath}) -> fullpath.indexOf("-cmp.js") === -1)
fileSeaker.addSetting(true, ({fullpath,filename}) -> watcher.addSetting(fullpath, options(filename)));


