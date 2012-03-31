(function(env, natives, compile, cwd){
  "use strict";
  var defProp = function (obj, prop, val, type) {
        type = type || '';
        var desc = [],
            configurable = false,
            writable = false,
            enumerable = false;
        type.split(' ').forEach(function (item) {
          if (item !== ' ') {
            if (item === '-c') configurable = true;
            else if (item === '-w') writable = true;
            else if (item === '-e') enumerable = true;
          }
        });
        Object.defineProperty(obj, prop, {
          value : val,
          configurable : configurable,
          writable : writable,
          enumerable : enumerable
        });
      },
      globalExports = {},
      loadFile = function (path) {
        var file = natives.fs.io.fopen(path, 'w+b'),
            result = file.getTextContent();
        file.close();
        return result;
      }
  
  //Define mocha object
  defProp(env, 'mocha', {});
  var mocha = env.mocha;
  defProp(env, 'console', {
    _print : function (method, args) {
      for (var i = 0,len = args.length; i < len; i++) {
        natives.io.nativeConsole[method](Object(args[i]).toString());
        if ((i + 1) != len) {
          natives.io.nativeConsole.printStdout(',');
        }
      }
      if (args.length > 0) {
        natives.io.nativeConsole.printStdout('\n');
      }
    },
    log : function () {
      this._print('printStdout', arguments);
    },
    error : function () {
      natives.io.nativeConsole.printStderr('[Error]');
      this._print('printStderr', arguments);
    },
    info : function () {
      natives.io.nativeConsole.printStderr('[Info]');
      this._print('printStdout', arguments);
    },
    warn : function () {
      natives.io.nativeConsole.printStderr('[Warn]');
      this._print('printStdout', arguments);
    }
  });
  defProp(mocha, 'utils', {});
  defProp(mocha, 'import', function (path) {
    if (path[0] !== '.' && path[0] !== '/' && path[0] !== '~') {
      if (path in natives) {
        return natives[path];
      } else {
        throw new Error(path + ' No such module.');
      }
    } else {
      var pathInfo = new natives.fs.Path(path),
          stat = new natives.fs.Stat(pathInfo.fullpath()),
          fullpath = pathInfo.fullpath();
      if (stat.isExist() && stat.isReg() && !(path in globalExports)) {
        var source = loadFile(fullpath);
        globalExports[fullpath] = {};
        mocha.__file__ = fullpath;
        source = '(function(mocha) {"use strict";mocha.export = {};\n' + source + '\nreturn mocha.export})';
        natives.fs.Dir.chdir(pathInfo.directory());
        var results = compile(source, fullpath)(mocha);
        for (var result in results) {
          globalExports[fullpath][result] = results[result];
        }
      } else {
        if (path === natives.fs.Path.homeDir() + '/.mocha/config.js') {
          env.console.log('first you need to create config.js in ' + natives.fs.Path.homeDir() + '/.mocha');
          return natives.invalidValue;
        } else {
          throw new Error(path + ' No such module.');
        }
      }
      return globalExports[fullpath];
    }
  });
  defProp(mocha.utils, 'loadFile', loadFile);
  defProp(mocha, 'addCommand', function (name , val, help) {
    defProp(this._commands, name, val, '-e -c -w');
    defProp(this._commandsHelp, name, help || '', '-e -c -w');
  });
  defProp(mocha, 'getCommand', function (name) {
    return this._commands[name];
  });
  defProp(mocha, 'callCommand', function (args) {
    if (typeof args === 'string') {
      var str = args.replace(/\s+/g, ' ');
      str = str.trim();
      var command = str.split(' ');
      if (command.length > 0 && command[0].length > 0) {
        var name = command.shift();
        name = name.replace('--', '');
        if (name in this._commands) {
          return this._commands[name].apply(null, command);
        } else {
          env.console.log(name + ' is unrecognized command\nsee --help.');
        }
      }
    } else {
      throw new Error('The arguments of callCommand is must be string.');
    }
  });
  defProp(mocha, '_commands', {});
  defProp(mocha, '_commandsHelp', {});
  defProp(mocha, 'addSetting', function (setting) {
    for (var i in setting) {
      this._settings[i] = setting[i];
    }
  });
  defProp(mocha, '_setting', {});
  defProp(mocha, '__file__', '', '-c -w');

  mocha.addCommand("watch", function () {
    if (natives.scriptUtils.watcher.isEnd()) {
      natives.scriptUtils.watcher.run();
    } else {
      env.console.log("watch server is now working.");
    }
  }, "Begin watching the file, and compile immediately if modified.");

  mocha.addCommand("unwatch", function (type) {
    if (!natives.scriptUtils.watcher.isEnd()) {
      natives.scriptUtils.watcher.exit();
    } else {
      env.console.log("watch sever is now stopping.");
    }
  }, "Stop watching the file, if watch server is working.");

  mocha.addCommand("exit", function () {
    if (!natives.scriptUtils.watcher.isEnd()) {
      natives.scriptUtils.watcher.exit();
      while (!natives.scriptUtils.watcher.isEnd()) {}
    }
    return natives.exitStatus;
  }, "Exit mocha.");

  mocha.addCommand('help', function () {
    for (var command in mocha._commands) {
      env.console.log("  " + command + '  :  ' + mocha._commandsHelp[command]);
    }
  }, 'show all command and help list.');

  mocha.setting = {
    addSetting : function (name, obj) {
      var path_info = new natives.fs.Path(name);
      if (natives.fs.Stat.isReg(path_info.fullpath())) {
        obj = obj || {};
        if (!('inputCharset' in obj)) {
          obj.inputCharset = 'utf-8';
        }
        if (!('outputCharset' in obj)) {
          obj.outputCharset = 'utf-8';
        }
        if (!('moduleDir' in obj)) {
          obj.moduleDir = [];
        }
        if (!('deployDir' in obj)) {
          obj.deployDir = path_info.directory();
        }
        if (!('deployName' in obj)) {
          obj.deployName = (path_info.filename().split('.')[0] + '-cmp.js');
        }
        if (!('options' in obj)) {
          obj.options = {
            compress : false,
            debug : false,
            prettyPrint : true,
            versions : []
          }
        } else {
          if (obj.options instanceof Object) {
            if (!('compress'in obj.options)) {
              obj.options.compress = false;
            }
            if (!('debug'in obj.options)) {
              obj.options.debug = false;
            }
            if (!('prettyPrint'in obj.options)) {
              obj.options.prettyPrint = true;
            }
            if (!('versions'in obj.options)) {
              obj.options.versions = [];
            }
          }
        }
        return natives.scriptUtils.__settings.addSetting(name,obj);
      }
    },
    removeSetting : function (name) {
      return natives.scriptUtils.__settings.removeSetting(name);
    }
  }
  return function (source) {
    source = '(function(mocha) {"use strict";\n' + source + '\n})';
    mocha.__file__ = 'main';
    var ret = compile(source)(mocha);
    return ret;
  };
});