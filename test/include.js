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
        versions : ['ex']
        //fileScope : false,
        //globalScope : false
      }
    });

class FileSeaker {
  constructor(@dir, @fn = []) {}

  public addSetting(recursive, optionCallback) ->
    new fs.Dir(@dir).entries(recursive).forEach((item) => @setCompileSetting(item, optionCallback));

  public addFilter(fn) -> @fn.push(fn);

  private setCompileSetting(file, optionCallbacks) {
    if (@fn.every((item) => item(file))) {
      optionCallbacks(file);
    }
  }
}

fileSeaker = new FileSeaker('../src/test/js/');
fileSeaker.addFilter(({fullpath}) -> fullpath.indexOf('.js') > -1);
fileSeaker.addFilter(({fullpath}) -> fullpath.indexOf("-cmp.js") === -1)
fileSeaker.addSetting(true, ({fullpath,filename}) -> watcher.addSetting(fullpath, options(filename)));


