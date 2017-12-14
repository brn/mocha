const script = mocha.import('script');
const fs = mocha.import('fs');

script.watcher.addSetting('test/test.js', {
  deployDir : 'test/deploy',
  deployName : 'test-deployed.js',
  inputCharset : 'utf8',
  outputCharset : 'utf8',
  options : {
    prettyPrint : true,
    debug : true,
    fileScope : false,
    globalScope : true,
    moduleDir : ['test/lib'],
    versions : ['compilation_test'],
    libs : []
  }
});
