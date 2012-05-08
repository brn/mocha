var script = mocha.import('script'),
    fs = mocha.import('fs')

addWatcher(filename, depname) ->
script.watcher.addSetting(fs.Path.getcwd() + filename, {
  inputCharset : 'utf8',
  outputCharset : 'utf8',
  deployName : depname,
  deployDir : './',
  moduleDir : ['lib'],
  options : {
    debug : true,
    prettyPrint : true,
    fileScope : true,
    globalScope : true
  }
})

addWatcher('/source/index.js', 'index.js');
addWatcher('/source/api.js', 'api.js')
