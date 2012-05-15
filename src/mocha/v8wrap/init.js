(function(env, natives, compile, cwd) {
  "use strict";
  /**
   * @namespace
   * utility functions and values.
   */
  var utils = {
        defProp : function (obj, prop, val, type) {
          type = type || '';
          var desc = [],
              configurable = false,
              writable = false,
              enumerable = false,
              propArray = prop.split('.'),
              tmpRef = obj;
          type.split(' ').forEach(function (item) {
            if (item !== ' ') {
              if (item === '-c') configurable = true;
              else if (item === '-w') writable = true;
              else if (item === '-e') enumerable = true;
            }
          });
          for (var i = 0, len = propArray.length; i < len; i++) {
            if (i == (len - 1)) {
              break;
            } else {
              if (!(propArray[i] in tmpRef)) {
                tmpRef[propArray[i]] = {};
              }
              tmpRef = tmpRef[propArray[i]];
            }
          }
          Object.defineProperty(tmpRef, propArray[propArray.length - 1], {
            value : val,
            configurable : configurable,
            writable : writable,
            enumerable : enumerable
          });
          return obj[propArray[0]];
        },
        loadFile : function (path) {
          var file = natives.io.open(path, 'rb'),
              result = file.read();
          file.close();
          return result;
        },
        replaceHome : function (path) {
          return (path[0] === '~')? path.replace('~', natives.fs.Path.homeDir()) : path;
        },
        deleteList : function () {
          for (var i in natives.script.watcher._settingList) {
            delete natives.script.watcher._settingList[i];
          }
        },
        globalExports : {},
        defaultExports : {},
        current : 'main',
        isDefined : function (item) {
          return item !== undefined && item !== null;
        }
      };

  var modules = {};
  utils.defProp(modules, 'fs', {
    open : function (path, permiss) {
      return natives.io.open(utils.replaceHome(path), permiss || 'r');
    },
    read : function (path ,permiss) {
      var file = natives.io.open(utils.replaceHome(path), permiss || 'r'),
          ret = file.read();
      file.close();
      return ret;
    },
    write : function (path, str, opt_size) {
      var file = natives.io.open(utils.replaceHome(path), 'w');
      file.write(str, opt_size);
      file.close();
    },
    listdir : function (path, recursive) {
      path = path || '/';
      var dir = new natives.fs.Dir(utils.replaceHome(path));
      return dir.entries((utils.isDefined(recursive))? !!recursive : false);
    },
    getcwd : function () {return natives.fs.Path.getcwd();},
    makeDirectory : function (path, permiss) {
      natives.fs.Dir.mkdir(path, permiss);
    },
    changeDirectory : function (path) {
      natives.fs.Dir.chdir(path);
    },
    remove : function (path) {
      natives.fs.Dir.rm(path);
    },
    move : function (path, dest) {
      natives.fs.Path.move(path, dest);
    },
    copy : function (source, dest) {
      var file = modules.fs.open(source, 'rb'),
          target = modules.fs.open(dest, 'w+b');
      target.write(file.read());
      target.close();
      file.close();
    },
    copyTree : function (source, dest) {
      source = modules.fs.path.abspath(utils.replaceHome(source));
      dest = modules.fs.path.abspath(utils.replaceHome(dest));
      if (modules.fs.path.isfile(source)) {
        return modules.fs.copy(source, dest);
      }
      var dirList = modules.fs.listdir(source, false);
      modules.fs.makeDirectory(dest);
      console.log(source, dest);
      dirList.forEach(function (item, index) {
        if (item.isdir) {
          modules.fs.copyTree(item.fullpath, dest + '/' + item.name);
        } else {
          modules.fs.copy(item.fullpath, dest + '/' + item.name);
        }
      });
    }
  }, '-c -w');

  utils.defProp(modules, 'fs.path', {
    abspath : function (path) {
      path = path || '/';
      if (modules.fs.path.isexist(path)) {
        return (path === '/')? path : new natives.fs.Path(utils.replaceHome(path)).fullpath();
      } else {
        return (path[0] !== '/' && path[0] !== '~' && !(/^[a-zA-Z]\:/.test(path)))? natives.fs.Path.normal(modules.fs.getcwd() + '/' + path) : path;
      }
    },
    basename : function (path) {
      var index = path.lastIndexOf('/');
      if (index === 0) {return '';}
      return path.slice(index + 1);
    },
    normal : function (path) {
      return natives.fs.Path.normal(path);
    },
    join : function () {
      return Array.prototype.slice.call(arguments).join('/');
    },
    split : function (path) {
      return path.split('/');
    },
    relative : function (path, target) {
      path = modules.fs.path.abspath(utils.replaceHome(path));
      target = modules.fs.path.abspath(utils.replaceHome(target));
      return natives.fs.Path.relative(path, target);
    },
    mtime : function (path) {
      var stat = new natives.fs.Stat(path);
      return new Date(stat.mtime());
    },
    ctime : function (path) {
      var stat = new natives.fs.Stat(path);
      return new Date(stat.ctime());
    },
    atime : function (path) {
      var stat = new natives.fs.Stat(path);
      return new Date(stat.atime());
    },
    isexist : function (path) {
      var stat = new natives.fs.Stat(utils.replaceHome(path));
      return stat.isExist();
    },
    isfile : function (path) {
      var stat = new natives.fs.Stat(utils.replaceHome(path));
      return stat.isExist() && !stat.isDir() && stat.isReg();
    },
    isdir : function (path) {
      var stat = new natives.fs.Stat(utils.replaceHome(path));
      return stat.isExist() && stat.isDir();
    }
  }, '-c -w');

  utils.defProp(modules, 'os', {
    name : function () {
      return natives.os.name();
    }
  }, '-c -w');

  utils.defProp(modules, 'os.process', {
    spawn : function (path, args) {
      return natives.os.process.spawn(path, args);
    },
    system : function (arg) {
      return natives.os.process.system(arg);
    },
    run : function (arg) {
      return natives.os.process.run(arg);
    }
  }, '-c -w');

  utils.defProp(modules, 'script', {
    watcher : {
      run : function () {natives.script.watcher.run();},
      exit : function () {natives.script.watcher.exit();},
      isRunning : function () {return natives.script.watcher.isRunning();},
      addSetting : function (path, setting) {
        natives.script.watcher.addSetting(path, setting);
      },
      removeSetting : function (path) {
        natives.script.watcher.removeSetting(path);
      },
      getSetting : function (path) {
        return natives.script.wathcer._settingList[path];
      }
    },
    compiler : {
      compile : function (path, charset, option) {
        return natives.script.Roaster.compile(path, charset, option);
      },
      compileFile : function (path, charset, option) {
        return natives.script.Roaster.compileFile(path, charset, option);
      },
      checkDependencies : function (path) {
        return natives.script.Roaster.checkDependencies(path);
      },
      deploy : function (path, charset, option) {
        return natives.script.Roaster.deploy(path, charset, option);
      }
    }
  } , '-c -w');

  (function(global){

    if (typeof(global['uneval']) !== 'function') {
      var stringOf = function (obj) {return obj.toString();},
          name2uneval = {
            '[object Boolean]':stringOf,
            '[object Number]': stringOf,
            '[object String]': function(o){
              return '"' + o + '"';
            },
            'undefined': function(o){ return 'undefined' },
            '[object Function]':function (m, depth) { return (depth !== 0)? '[object Function]' : m.toString();},
            '[object Array]' : function (arr) {
              var str = ((arr.length > 0)? arr : ['']).reduce(function (item, item2) {
                    return this.inspect(item) + ', ' + this.inspect(item2);
                  }.bind(this));
              return '[' + (str? str : '') + ']';
            },
            '[object Arguments]' : function (arr) {
              return name2uneval['[object Array]'].call(this, Array.prototype.slice.call(arr));
            },
            '[object RegExp]' : stringOf,
            '[object Date]' : function (d) {return d.toJSON();},
            '[object Undefined]' : function () {return 'undefined';}
          };

      var Inspector = function () {
            this._indent = '';
            this._depth = 0;
          }
      Inspector.prototype.inspect = function (obj) {
        if (obj === null) {
          return 'null';
        }
        var str = Object.prototype.toString.call(obj);
        if (str in name2uneval) {
          return name2uneval[str].call(this, obj, this._depth);
        } else {
          return this._inspectObject(obj);
        }
      }

      Inspector.prototype._addIndent = function () {
        this._indent += '  ';
        this._depth++;
      }

      Inspector.prototype._outdent = function () {
        this._indent = this._indent.slice(0, this._indent.length - 2);
        this._depth--;
      }

      Inspector.prototype._inspectObject = function(o){
        this._addIndent();
        var src = [],
            props = Object.getOwnPropertyNames(o);
        for (var i = 0,len = props.length; i < len; i++){
          src[src.length] = props[i]  + ':' + this.inspect(o[props[i]], 1);
        };
        var ret;
        if (src.length > 0) {
          ret = '{' + '\n' + this._indent + src.join('\n' + this._indent) + '\n';
          this._outdent();
          ret += this._indent + '}';
        } else {
          ret = '{}';
        }
        return ret;
      };

      global.uneval = function(o){
        var inspector = new Inspector();
        return inspector.inspect(o);
      }
    }
  })(env);

  /**
   * @namespace
   * The global core functions definitions.
   */
  var mocha = function () {
        //Define global mocha object.
        var mocha = utils.defProp(env, 'mocha', {});

        //Define file config utils.
        utils.defProp(mocha, 'config', {
          set : function (name, val) {
            var stat = new natives.fs.Stat(val);
            if (stat.isExist()) {
              var path_info = new natives.fs.Path(val);
              natives.config.set(name, path_info.fullpath());
            }
          },
          get : function (key) {return natives.config.get(key);}
        });

        //Define global console api.
        utils.defProp(env, 'console', {
          _print : function (method, args, isInspect) {
            for (var i = 0,len = args.length; i < len; i++) {
              if (!isInspect) {
                natives.io.nativeConsole[method](Object(args[i]).toString());
              } else {
                natives.io.nativeConsole[method](env.uneval(args[i]));
              }
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
          dir : function () {
            this._print('printStdout', arguments, true);
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

        //Define mocha module system.
        utils.defProp(mocha, 'import', function (path, force) {
          if (path[0] !== '.' && path[0] !== '/' && path[0] !== '~' && path[1] != ':') {
            if (path in natives) {
              return modules[path];
            } else {
              throw new Error(path + ' No such module.');
            }
          } else {
            var pathInfo = new natives.fs.Path(path),
                stat = new natives.fs.Stat(pathInfo.fullpath()),
                fullpath = pathInfo.fullpath();
            if (stat.isExist() && stat.isReg()) {
              if (!(path in utils.globalExports) || force) {
                var source = utils.loadFile(fullpath);
                utils.globalExports[fullpath] = {};
                var file = utils.current;
                utils.current = fullpath;
                //source = '(function(mocha) {"use strict";\n' + source + '\n})';
                natives.fs.Dir.chdir(pathInfo.directory());
                //compile(source, fullpath)(mocha);
                runInConfigContext(source, fullpath);
                utils.current = file;
              }
            } else {
              throw new Error(path + ' No such module.');
            }
            return utils.globalExports[fullpath];
          }
        });

        //Define export function
        utils.defProp(mocha, 'export', function (name, val) {
          utils.globalExports[utils.current][name] = val;
        });

        //export loadFile function.
        utils.defProp(mocha, 'loadFile', utils.loadFile);

        //Define command utilities.
        utils.defProp(mocha, 'addCommand', function (name , val, help) {
          utils.defProp(this._commands, name, val, '-e -c -w');
          utils.defProp(this._commandsHelp, name, help || '', '-e -c -w');
        });
        utils.defProp(mocha, 'getCommand', function (name) {
          return this._commands[name];
        });
        utils.defProp(mocha, 'callCommand', function (source) {
          var isString = typeof source === 'string';
          if (isString && source[0] == '.') {
            var compiled = natives.script.Roaster.compile('mocha._commands' + source + ';', 'utf-8', {prettyPrint : true, unversions : 'backCompat'});
            return compile(compiled);
          } else if (isString) {
            return mocha._commands[Array.prototype.shift.call(arguments)].apply(null, arguments);
          }
        });
        utils.defProp(mocha, '_commands', {});
        utils.defProp(mocha, '_commandsHelp', {});
        mocha.addCommand("watch", function () {
          if (!natives.script.watcher.isRunning()) {
            natives.script.watcher.run();
          } else {
            env.console.log("watch server is now working.");
          }
        }, "Begin watch server, and compile immediately if modified.");
        return mocha;
      }();

  var isObject = function (o) {
        return Object.prototype.toString.call(o) === '[object Object]';
      }

  var merge = function(dest, source) {
        for (var prop in source) {
          if (isObject(source[prop])) {
            if (!(prop in dest) || !isObject(dest[prop])) {
              dest[prop] = {}
            }
            merge(dest[prop], source[prop]);
          } else if (Array.isArray(source[prop])) {
            if (!(prop in dest) || Array.isArray(dest[prop])) {
              dest[prop] = []
            }
            dest[prop] = source[prop].concat(dest[prop]);
          } else if (!(prop in dest)) {
            dest[prop] = source[prop];
          }
        }
      }

  var makeOptionList = function (i, isString, setting) {
        setting = setting || {};
        merge(setting, natives.script.watcher._settingList[i]);
        var path_info = new natives.fs.Path(i),
            inputCharset = setting.inputCharset || 'utf8',
            outputCharset = setting.outputCharset || 'utf8',
            deployDir = setting.deployDir || path_info.directory(),
            deployName = setting.deployName || path_info.filename().replace('.js', '-cmp.js'),
            options = setting.options || {},
            moduleDir = (isString)? '(' + (options.moduleDir || ['']).reduce(function (item1, item2) { return item1 + ', ' + item2; }) + ')' : options.moduleDir || [],
            compress = (!isString)? ((utils.isDefined(options.compress))?options.compress : false) : options.compress? 'yes' : 'no',
            debug = (!isString)? ((utils.isDefined(options.debug))? options.debug : false) : options.debug? 'yes' : 'no',
            prettyPrint = (!isString)? (utils.isDefined(options.prettyPrint)? options.prettyPrint : true) : options.prettyPrint? 'yes' : 'no',
            fileScope = (!isString)? ((utils.isDefined(options.fileScope))? true : options.fileScope) : options.fileScope? 'yes' : (!('fileScope' in options))? 'yes' : (options.fileScope)? 'yes' : 'no',
            globalScope = (!isString)? ((utils.isDefined(options.globalScope))? true : options.globalScope) : options.globalScope? 'yes' : (!('globalScope' in options))? 'yes' : (!options.globalScope)? 'no' : 'yes',
            prototypeExt = (!isString)? ((utils.isDefined(options.prototypeExtensions))? options.prototypeExtensions : true) : options.prototypeExtensions? 'no' : 'yes',
            versions = (isString)? '(' + (options.versions || ['']).reduce(function (item1, item2) { return item1 + ', ' + item2; }) + ')' : options.versions || [],
            libs = (isString)? '(' + (options.libs || ['']).reduce(function (item1, item2){ return item1 + ', ' + item2;}) + ')' : options.libs || []
        return {
          name : i,
          inputCharset : inputCharset,
          outputCharset : outputCharset,
          deployDir : deployDir,
          deployName : deployName,
          moduleDir : (!isString)? Array.prototype.slice.call(moduleDir) : moduleDir,
          compress : compress,
          debug : debug,
          prettyPrint : prettyPrint,
          fileScope : fileScope,
          globalScope : globalScope,
          prototypeExtensions : prototypeExt,
          versions : (!isString)? Array.prototype.slice.call(versions) : versions,
          libs : (!isString)? Array.prototype.slice.call(libs) : libs
        }
      }

  //Builtin command definitions.
  mocha.addCommand("settingList", function (showDeploy, showOpt, pred) {
    pred = makePredicate(pred);
    var ret = [],
        dir = "";
    for (var i in natives.script.watcher._settingList) {
      var option = makeOptionList(i, true);
      var is_match = pred(option);
      if (is_match) {
        if (showDeploy && showOpt) {
          ret.push([i, option.inputCharset || '', option.outputCharset || '', option.deployDir, option.deployName, option.moduleDir, option.compress, option.debug, option.prettyPrint, option.fileScope, option.globalScope, option.prototypeExtensions, option.versions, option.libs]);
        } else if (showOpt) {
          ret.push([i, option.compress, option.debug, option.prettyPrint, option.fileScope, option.globalScope, option.prototypeExtensions, option.versions, option.libs]);
        } else if (showDeploy) {
          ret.push([i, option.inputCharset || '', option.outputCharset || '', option.deployDir, option.deployName, option.moduleDir]);
        } else {
          ret.push([i]);
        }
      }
    }
    if (showDeploy && showOpt) {
      mocha.printAsciiBox(ret, ['name', 'charset(in)', 'charset(out)', 'deploy(dir)', 'deploy(name)', 'moduleDir', 'compress', 'debug', 'prettyPrint', 'fileScope', 'globalScope', 'prototypeExt', 'versions', 'libs'], 2);
    } else if (showOpt) {
      mocha.printAsciiBox(ret, ['name', 'compress', 'debug', 'prettyPrint', 'fileScope', 'globalScope', 'prototypeExt', 'versions', 'libs'], 2);
    } else if (showDeploy) {
      mocha.printAsciiBox(ret, ['name', 'charset(in)', 'charset(out)', 'deploy(dir)', 'deploy(name)', 'moduleDir'], 2);
    } else {
      mocha.printAsciiBox(ret, ['name'], 2);
    }
  }, "watchList([deployInfo], [optionInfo], [predicate]) : Begin watch server, and compile immediately if modified.");

  mocha.addCommand("unwatch", function (type) {
    if (natives.script.watcher.isRunning()) {
      natives.script.watcher.exit();
      while (natives.script.watcher.isRunning()) {}
      utils.deleteList();
      utils.globalExports = {};
    } else {
      env.console.log("watch sever is now stopping.");
    }
    natives.script.watcher._settingList = {};
  }, "unwatch() : Exit watc server, if watch server is working.");

  mocha.addCommand("restart", function (type) {
    if (natives.script.watcher.isRunning()) {
      natives.script.watcher.exit();
      while (natives.script.watcher.isRunning()) {}
      utils.deleteList();
      utils.globalExports = {};
      natives.script.watcher.run();
    } else {
      env.console.log("watch sever is now stopping.");
    }
  }, "restart() : Restart watch server, if watch server is working.");

  mocha.addCommand("deploy", function (pred, opt) {
    pred = makePredicate(pred);
    if (typeof opt === 'string') {
      if (opt === 'release') {
        opt = {options : {compress : true, debug : false, prettyPrint : false, versions : ['release']}};
      } else if (opt === 'debug') {
        opt = {options : {compress : false, debug : true, prettyPrint : true, versions : ['debug']}};
      } else {
        opt = opt || {};
      }
    }
    for (var i in natives.script.watcher._settingList) {
      var option = makeOptionList(i, false, opt);
      option.options = {
        compress : option.compress,
        prettyPrint : option.prettyPrint,
        debug : option.debug,
        versions : option.versions,
        moduleDir : option.moduleDir,
        fileScope : option.fileScope,
        globalScope : option.globalScope,
        prototypeExtensions : option.prototypeExtensions,
        libs : option.libs
      }
      if (pred(option)) {
        natives.script.Roaster.deploy(i, option.inputCharset, option);
      }
    }
  }, "deploy(predicate, [option]) : Compile file that is selected by predicate function.");

  function makePredicate(type) {
    return typeof type === 'string'?
      function (setting) {return type === setting.name;} :
    type instanceof RegExp? function (setting) {return type.test(setting.name);} :
    typeof type === 'function'? type : function () {return true;};
  }

  mocha.addCommand("test", function (pred, opt) {
    pred = makePredicate(pred);
    var phantom = natives.config.get('phantomInstallDir'),
        argList = [],
        dir,
        pathInfo,
        name;
    if (phantom) {
      if (typeof opt === 'string') {
        if (opt === 'release') {
          opt = {options : {compress : true, debug : false, prettyPrint : false, versions : ['release']}};
        } else if (opt === 'debug') {
          opt = {options : {compress : false, debug : true, prettyPrint : true, versions : ['debug']}};
        } else {
          opt = opt || {};
        }
      }
      for (var i in natives.script.watcher._settingList) {
        var option = makeOptionList(i, false, opt);
        option.versions.push("test");
        option.options = {
          compress : option.compress,
          prettyPrint : option.prettyPrint,
          debug : option.debug,
          versions : option.versions,
          moduleDir : option.moduleDir,
          fileScope : option.fileScope,
          globalScope : option.globalScope,
          prototypeExtensions : option.prototypeExtensions,
          libs : option.libs
        }
        if (pred(option)) {
          natives.script.Roaster.deploy(i, option.inputCharset, option);
          dir = natives.script.watcher._settingList[i].deployDir;
          pathInfo = new natives.fs.Path(i);
          if (!dir) {
            dir = pathInfo.directory();
          }
          name = natives.script.watcher._settingList[i].deployName;
          if (!name) {
            name = pathInfo.filename().replace('.js', '-cmp.js');
          }
          argList.push(dir + '/' + name);
        }
      }
      if (natives.config.has('testDriver') && argList.length > 0) {
        console.log(natives.os.process.spawn(phantom, natives.config.get('testDriver') + " " + argList.join(' ')));
      }
    }
  }, "test(predicate, [option]) : Start test with the file that selected by predicate function.");

  mocha.addCommand("exit", function () {
    if (natives.script.watcher.isRunning()) {
      natives.script.watcher.exit();
      while (natives.script.watcher.isRunning()) {}
      utils.deleteList();
    }
    natives.repl.exit();
  }, "exit() : Exit mocha.");

  mocha.addCommand('help', function () {
    for (var command in mocha._commands) {
      env.console.log("  " + command + '  :  ' + mocha._commandsHelp[command]);
    }
  }, 'help() : show all command and help list.');

  mocha.printAsciiBox = function (array, title, additionalPadding) {
    additionalPadding = additionalPadding || 0
    var max = Math.max,
        colInfo = [],
        nconsole = natives.io.nativeConsole,
        hasHeader = false;
    if (title) {
      array.unshift(title);
      hasHeader = true;
    }
    array.forEach(function (item, i) {
      if (item instanceof Array && 'forEach' in item) {
        item.forEach(function (inner, index) {
          colInfo[index] = (colInfo[index] != undefined)? max(colInfo[index], inner.toString().length + additionalPadding) : inner.toString().length + additionalPadding;
        });
      } else {
        return;
      }
    });

    nconsole.printStdout('+');
    colInfo.forEach(function (item, index) {
      for (var i = 0; i < item; i++) {
        nconsole.printStdout('-');
      }
      if (index + 1 < array[0].length) {
        nconsole.printStdout('+');
      }
    });
    nconsole.printStdout('+\n');
    array.forEach(function(item, index) {
      nconsole.printStdout('|');
      item.forEach(function (innerItem , innerIndex) {
        var padding = colInfo[innerIndex] - innerItem.toString().length;
        for (var i = 0; i < padding; i++) {
          nconsole.printStdout(' ');
        }
        nconsole.printStdout(innerItem);
        nconsole.printStdout('|');
      });
      if (hasHeader && index === 0) {
        nconsole.printStdout('\n');
        nconsole.printStdout('+');
        colInfo.forEach(function (item, index) {
          for (var i = 0; i < item; i++) {
            nconsole.printStdout('-');
          }
          nconsole.printStdout('+');
        });
      }
      nconsole.printStdout('\n');
    });
    nconsole.printStdout('+');
    colInfo.forEach(function (item, index) {
      for (var i = 0; i < item; i++) {
        nconsole.printStdout('-');
      }
      nconsole.printStdout('+');
    });
    nconsole.printStdout('\n');
  };

  (function () {
    var path = natives.config._configPath;
    var configStat = new natives.fs.Stat(path);
    if (!configStat.isExist()) {
      var file = natives.io.open(path, 'w+b'),
          source = natives.config._watchFileTemplate;
      file.write(source);
      file.close();
    }
    var source = utils.loadFile(path),
        current = natives.fs.Path.getcwd();
    try {
      natives.fs.Dir.chdir(natives.fs.Path.homeDir() + '/.mocha');
      compile('(function(mocha, config) {\n' + source + '\n})')(mocha, mocha.config);
    } catch(e) {
      env.console.log(e);
    }
    natives.fs.Dir.chdir(current);
  })();

  (function () {
    var path = natives.config.get('testDriver'),
        driverStat = new natives.fs.Stat(path);
    if (!driverStat.isExist()) {
      var file = natives.io.open(path, 'w+b'),
          source = natives.config._testDriverTemplate;
      file.write(source);
      file.close();
    }
  })();

  natives.internalLogger.initialize();
  function runInConfigContext (source, path) {
    path = path || 'anonymous';
    var compiled = natives.script.Roaster.compile(source, 'utf-8', {prettyPrint : true, unversions : "backCompat"});
    source = '(function(mocha) {\n' + compiled + '\n})';
    compile(source, path)(mocha);
  };
  return runInConfigContext;
});