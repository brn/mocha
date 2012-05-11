var script = mocha.import('script'),
    fs = mocha.import('fs')

addWatcher(filename, depname, lib) ->
  script.watcher.addSetting(filename, {
    inputCharset : 'utf8',
    outputCharset : 'utf8',
    deployName : depname,
    deployDir : './',
    options : {
      debug : false,//true,
      prettyPrint : false,//true,
      fileScope : true,
      globalScope : true,
      moduleDir : ['./lib'],
      libs : lib,
      compress : true
    }
  });

addWatcher('source/index.js', 'index.js', ['jQuery']);
addWatcher('source/api.js', 'api.js', ['jQuery', 'prettify']);
