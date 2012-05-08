var script = mocha.import('script'),
    fs = mocha.import('fs')

addWatcher(filename) ->
script.watcher.addSetting(fs.Path.getcwd() + filename, {
  inputCharset : 'utf8',
  outputCharset : 'utf8',
  deployDir : '../',
  moduleDir : ['lib'],
  options : {
    debug : true,
    prettyPrint : true,
    fileScope : true,
    globalScope : true
  }
})

addWatcher('/source/index.js');
addWatcher('/source/api.js')
