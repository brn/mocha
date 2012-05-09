var fs = mocha.import("fs"),
    watcher = mocha.import("script").watcher;

var options = (filename) -> ({
      deployDir : '../src/test/js/out/devel',
      deployName : filename.replace('.js', '-cmp.js'),
      outputCharset : 'utf8',
      options : {
        compress : false,
        prettyPrint : true,
        debug : true,
        versions : ['ex'],
        fileScope : true,
        globalScope : true,
        moduleDir : ['./3rd-modules']
      }
    });

class FileSeaker {
  constructor(private(this).dir, private(this).fn = []) {}

  public addSetting(recursive, optionCallback) ->
    new fs.Dir(private(this).dir).entries(recursive).forEach((item) => private(this).setCompileSetting(item, optionCallback));

  public addFilter(fn) -> private(this).fn.push(fn);

  private setCompileSetting(file, optionCallbacks) {
    if (file.isfile && private(this).fn.every((item) => item(file))) {
      optionCallbacks(file);
    }
  }
}

var fileSeaker = new FileSeaker('../src/test/js/');
fileSeaker.addFilter(({fullpath}) -> fullpath.indexOf('.js') > -1);
fileSeaker.addFilter(({fullpath}) -> fullpath.indexOf("-cmp.js") === -1)
fileSeaker.addSetting(true, ({fullpath,name}) -> watcher.addSetting(fullpath, options(name)));
