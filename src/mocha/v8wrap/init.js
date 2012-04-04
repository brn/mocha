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
        var file = natives.io.fopen(path, 'rb'),
            result = file.getTextContent();
        file.close();
        return result;
      },
      current = 'main';

  //Define mocha object
  defProp(env, 'mocha', {});
  var mocha = env.mocha;
  mocha.config = {
    set : function (name, val) {
      var stat = new natives.fs.Stat(val);
      if (stat.isExist()) {
        var path_info = new natives.fs.Path(val);
        natives.config.set(name, path_info.fullpath());
      }
    },
    get : function (key) {return natives.config.get(key);}
  };
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
  defProp(mocha, 'import', function (path, force) {
    if (path[0] !== '.' && path[0] !== '/' && path[0] !== '~' && path[1] != ':') {
      if (path in natives) {
        return natives[path];
      } else {
        throw new Error(path + ' No such module.');
      }
    } else {
      var pathInfo = new natives.fs.Path(path),
          stat = new natives.fs.Stat(pathInfo.fullpath()),
          fullpath = pathInfo.fullpath();
      if (stat.isExist() && stat.isReg()) {
        if (!(path in globalExports) || force) {
          var source = loadFile(fullpath);
          globalExports[fullpath] = {};
          var file = current;
          current = fullpath;
          source = '(function(mocha) {"use strict";\n' + source + '\n})';
          natives.fs.Dir.chdir(pathInfo.directory());
          compile(source, fullpath)(mocha);
          current = file;
        }
      } else {
        throw new Error(path + ' No such module.');
      }
      return globalExports[fullpath];
    }
  });
  defProp(mocha, 'export', function (name, val) {
    globalExports[current][name] = val;
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
      var source = args.replace('@', '');
      return compile('mocha._commands.' + source);
    } else {
      throw new Error('The arguments of callCommand is must be string.');
    }
    return null;
  });

  defProp(mocha, '_commands', {});
  defProp(mocha, '_commandsHelp', {});
  mocha.addCommand("watch", function () {
    if (!natives.script.watcher.isRunning()) {
      natives.script.watcher.run();
    } else {
      env.console.log("watch server is now working.");
    }
  }, "Begin watch server, and compile immediately if modified.");

  mocha.addCommand("unwatch", function (type) {
    if (natives.script.watcher.isRunning()) {
      natives.script.watcher.exit();
      while (natives.script.watcher.isRunning()) {}
      globalExports = {};
    } else {
      env.console.log("watch sever is now stopping.");
    }
  }, "Exit watc server, if watch server is working.");

  mocha.addCommand("restart", function (type) {
    if (natives.script.watcher.isRunning()) {
      natives.script.watcher.exit();
      while (natives.script.watcher.isRunning()) {}
      natives.script.watcher.run();
    } else {
      env.console.log("watch sever is now stopping.");
    }
  }, "Restart watch server, if watch server is working.");

  mocha.addCommand("exit", function () {
    if (natives.script.watcher.isRunning()) {
      natives.script.watcher.exit();
      while (natives.script.watcher.isRunning()) {}
    }
    return natives.exitStatus;
  }, "Exit mocha.");

  mocha.addCommand('help', function () {
    for (var command in mocha._commands) {
      env.console.log("  " + command + '  :  ' + mocha._commandsHelp[command]);
    }
  }, 'show all command and help list.');
  
  (function () {
    var path = natives.config._configPath;
    var configStat = new natives.fs.Stat(path);
    if (!configStat.isExist()) {
      var file = natives.io.fopen(path, 'w+b'),
          source = natives.config._watchFileTemplate;
      file.writeTextContent(source);
      file.close();
    }
    var source = loadFile(path),
        current = natives.fs.Path.getcwd();
    try {
      natives.fs.Dir.chdir(natives.fs.Path.homeDir() + '/.mocha');
      compile('(function(mocha, config) {\n' + source + '\n})')(mocha, mocha.config);
    } catch(e) {
      console.log(e);
    }
    natives.fs.Dir.chdir(current);
  })();
  
  return function (source) {
    source = '(function(mocha) {"use strict";\n' + source + '\n})';
    var ret = compile(source)(mocha);
    return ret;
  };
});