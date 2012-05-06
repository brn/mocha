var script = mocha.import('script'),
    fs = mocha.import('fs')

addWatcher(filename) ->
script.watcher.addSetting(fs.Path.getcwd() + filename, {
  inputCharset : 'utf8',
  outputCharset : 'utf8',
  options : {
    debug : true,
    deployDir : './',
    moduleDir : ['lib']
    prettyPrint : true,
    fileScope : true,
    globalScope : true
  }
})

addWatcher('/source/index.js');
addWatcher('/source/api.js')
