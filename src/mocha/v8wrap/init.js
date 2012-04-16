(function(env, natives, compile, cwd){
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
          return obj[prop];
        },
        loadFile : function (path) {
          var file = natives.io.fopen(path, 'rb'),
              result = file.getTextContent();
          file.close();
          return result;
        },
        deleteList : function () {
          for (var i in natives.script.watcher._settingList) {
            delete natives.script.watcher._settingList[i];
          }
        },
        globalExports : {},
        defaultExports : {},
        current : 'main'
      };

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
        } else if (str === '[object Object]') {
          return this._inspectObject(obj);
        } else {
          return str;
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
              return natives[path];
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

  var makeOptionList = function (i, isString, setting) {
        setting = setting || natives.script.watcher._settingList[i];
        var path_info = new natives.fs.Path(i),
            inputCharset = setting.inputCharset || 'utf8',
            outputCharset = setting.outputCharset || 'utf8',
            deployDir = setting.deployDir || path_info.directory(),
            deployName = setting.deployName || path_info.filename().replace('.js', '-cmp.js'),
            moduleDir = (isString)? '(' + (setting.moduleDir || ['']).reduce(function (item1, item2) { return item1 + ', ' + item2; }) + ')' : setting.moduleDir || [],
            options = setting.options || {},
            compress = (!isString)? options.compress || false : options.compress? 'yes' : 'no',
            debug = (!isString)? options.debug || false : options.debug? 'yes' : 'no',
            prettyPrint = (!isString)? options.prettyPrint || true : options.prettyPrint? 'yes' : 'no',
            versions = (isString)? '(' + (options.versions || ['']).reduce(function (item1, item2) { return item1 + ', ' + item2; }) + ')' : options.versions || [];
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
          versions : (!isString)? Array.prototype.slice.call(versions) : versions
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
          ret.push([i, option.inputCharset || '', option.outputCharset || '', option.deployDir, option.deployName, option.moduleDir, option.compress, option.debug, option.prettyPrint, option.versions]);
        } else if (showOpt) {
          ret.push([i, option.compress, option.debug, option.prettyPrint, option.versions]);
        } else if (showDeploy) {
          ret.push([i, option.inputCharset || '', option.outputCharset || '', option.deployDir, option.deployName, option.moduleDir]);
        } else {
          ret.push([i]);
        }
      }
    }
    if (showDeploy && showOpt) {
      mocha.printAsciiBox(ret, ['name', 'charset(in)', 'charset(out)', 'deploy(dir)', 'deploy(name)', 'moduleDir', 'compress', 'debug', 'prettyPrint', 'versions'], 2);
    } else if (showOpt) {
      mocha.printAsciiBox(ret, ['name', 'compress', 'debug', 'prettyPrint', 'versions'], 2);
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
    for (var i in natives.script.watcher._settingList) {
      var option = makeOptionList(i, false, opt);
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
      for (var i in natives.script.watcher._settingList) {
        var option = makeOptionList(i, false, opt);
        option.versions.push("test");
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
      var file = natives.io.fopen(path, 'w+b'),
          source = natives.config._watchFileTemplate;
      file.writeTextContent(source);
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
      var file = natives.io.fopen(path, 'w+b'),
          source = natives.config._testDriverTemplate;
      file.writeTextContent(source);
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