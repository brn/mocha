
var {watcher} = mocha.import('script'),
    fs = mocha.import('fs')

watcher.addSetting('test/test.js', {
  deployDir : 'test/deploy',
  deployName : 'test-deployed.js',
  inputCharset : 'utf8',
  outputCharset : 'utf8',
  options : {
    prettyPrint : true,
    debug : true,
    fileScope : true,
    globalScope : true,
    moduleDir : ['test/lib'],
    versions : ['compilation_test'],
    libs : ['jQuery']
  }
});
