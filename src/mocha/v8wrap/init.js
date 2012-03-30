(function(env, cwd){
  "use strict";
  var loadFile = env.loadFile,
      include = function (path) {
        if (path[0] !== '.' && path[0] !== '/' && path[0] !== '~') {
          if (path in env.guard) {
            return env.guard[path];
          } else {
            throw new Error(path + ' No such module.');
          }
        } else {
          var pathInfo = new env.guard.fs.Path(path),
              stat = new env.guard.fs.Stat(pathInfo.fullpath()),
              fullpath = pathInfo.fullpath();
          if (stat.isExist() && stat.isReg() && !(path in env.guard)) {
            var source = loadFile(fullpath);
            env.exports[fullpath] = {};
            mocha.__file__ = fullpath;
            source = '(function(mocha) {"use strict";' + source + '})';
            env.guard.fs.Dir.chdir(pathInfo.directory());
            env.compile(source, fullpath)(mocha);
            env.guard[fullpath] = env.exports[fullpath];
            return env.exports[fullpath];
          };
          return env.guard[fullpath];
        }
      },
      defProp = function (obj, prop, val, type) {
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
      mocha = {};

  defProp(mocha, 'export', function(name, val) {
    env.exports[this.__file__][name] = val;
  });
  defProp(mocha, 'import', include);
  defProp(mocha, 'loadFile', loadFile);
  defProp(mocha, 'addCommand', function (name , val, help) {
    defProp(this._commands, name, val, '-e -c -w');
    defProp(this._commandsHelp, name, help || '', '-e -c -w');
  });
  defProp(mocha, 'getCommand', function (name) {
    return this._commands[name];
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
    if (env.guard.fs.watcher.isEnd()) {
      env.guard.fs.watcher.run();
    } else {
      print("watch server is now working.");
    }
    return 0;
  }, "Begin watching the file, and compile immediately if modified.");

  mocha.addCommand("unwatch", function (type) {
    if (!env.guard.fs.watcher.isEnd()) {
      env.guard.fs.watcher.exit();
    } else {
      print("watch sever is now stopping.");
    }
    return 0;
  }, "Stop watching the file, if watch server is working.");

  mocha.addCommand("exit", function () {
    if (!env.guard.fs.watcher.isEnd()) {
      env.guard.fs.watcher.exit();
      while (!env.guard.fs.watcher.isEnd()) {}
    }
    return 1;
  }, "Exit mocha.");

  mocha.addCommand("help", function () {
    print("Usage: [command]\n"
          + "options:\n"
          + " watch : Watch the files that is descripted in watch.xml.\n"
          + " unwatch : Unwatch the files, if watch command is running.\n"
          + " list : Show watching xml and javascript file list."
          + " help : Show help.\n"
          + " exit : exit mocha.");
    return 0;
  }, "Show help.");

  mocha.addCommand('commandList', function () {
    for (var command in mocha._commands) {
      print("  " + command + '  :  ' + mocha._commandsHelp[command]);
    }
  })

  mocha.setting = {
    addSetting : function (name, obj) {
      var path_info = new env.guard.fs.Path(name);
      if (env.guard.fs.Stat.isReg(path_info.fullpath())) {
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
        return env.guard.fs.__settings.addSetting(name,obj);
      }
    },
    removeSetting : function (name) {
      return env.guard.fs.__settings.removeSetting(name);
    }
  }

  return function (source) {
    source = '(function(mocha) {"use strict";\n' + source + '\n})';
    mocha.__file__ = 'main';
    var ret = env.compile(source)(mocha);
    return ret;
  };

});