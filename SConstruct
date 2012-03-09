import os, sys
from stat import *

PLATFORM_FLAGS = {
"posix" : {
        "CXX_FLAGS" : '-Wall -optimize -DPLATFORM_POSIX -DCURRENT_DIR=\\"' + os.getcwd() + '\\" `icu-config --ldflags`',
        "LD_FLAGS" : "-lpthread -Xlinker -rpath -Xlinker `icu-config --icudata-install-dir --ldflags`"
        },
'mac' : {
        "CXX_FLAGS" : '-Wall -optimize -DPLATFORM_POSIX -DCURRENT_DIR=\\"' + os.getcwd() + '\\" `icu-config --ldflags`',
        "LD_FLAGS" : "-lpthread -Xlinker -rpath -Xlinker `icu-config --icudata-install-dir"
        },
"win32" : {
        "CXX_FLAGS" : '-W3 -optimize -DPLATFORM_WIN32 -DCURRENT_DIR=\\"' + os.getcwd().replace('\\', '/') + '\\"',
        "LD_FLAGS" : ""
        }
}

def GetFlags(platform, optimize_level = 'O0') :
    return (PLATFORM_FLAGS[platform]["CXX_FLAGS"].replace('optimize', optimize_level),
            PLATFORM_FLAGS[platform]["LD_FLAGS"])

class MochaBuilder :
    def __init__(self, target, platform, optimize_level) :
        self.__platform = platform
        self.__target = target
        flags = GetFlags(platform, optimize_level)
        self.__env = Environment(CCFLAGS=flags[0],
                                 LINKFLAGS=flags[1])
        self.__root = 'src'
        self.__targets = []
        self.__third_party = {
            "v8" : 1,
            "icu" : 1,
            "phantomjs" : 1
            }
        self.__platform_mismatches = {
            "win32" : { 
                "thread-posix.cc" : 1,
                "directory-posix.cc" : 1,
                "file_watcher-inotify-impl.cc" : 1
                },
            "mac" : {
                "thread-win32.cc" : 1,
                "directory-win32.cc" : 1,
                "file_watcher-inotify-impl.cc" : 1
                },
            "posix" : {
                "thread-win32.cc" : 1,
                "directory-win32.cc" : 1,
                "file_watcher-inotify-impl.cc" : 1
                }
            }
    
    @staticmethod
    def CheckArgs(argname):
        platforms = ARGUMENTS.get(argname)
        opt = ARGUMENTS.get('optimize');
        if not platforms or (platforms != 'win32' and platforms != 'mac' and platforms != 'posix') :
            print """
error you must set specific build platform as arguments.
buildable platforms :
  [win32 mac posix]
"""
            exit()
        else :
            return (platforms, opt);

    def Build(self) :
        self.__CollectSources()
        self.__env.Program(self.__target, self.__targets, CPPPATH=[self.__root])

    def __CollectSources(self) : 
        self.__IterateDir(self.__root);

    def __IterateDir(self, dirname) :
        for file_or_dir in os.listdir(dirname) :
            name = dirname + '/' + file_or_dir
            if os.path.isdir(name) and not self.__third_party.has_key(file_or_dir) and not file_or_dir == '.deps' :
                print name
                self.__IterateDir(name)
            elif os.path.isfile(name) :
                if (not self.__CheckMismatch(file_or_dir)) and file_or_dir.endswith('.cc'):
                    self.__targets.append(name)

    def __CheckMismatch(self, name) :
        return self.__platform_mismatches[self.__platform].has_key(name)

TARGET_NAME = 'mchd'
args = MochaBuilder.CheckArgs('platform')
builder = MochaBuilder(TARGET_NAME, args[0], args[1])
builder.Build()
"""
target  = 'scontest'
sources = [Glob('*.cc'),
           Glob('src/*.cc'),
           Glob('src/*/*.cc'),
           Glob('src/*/*/*.cc')]
//env.Program(target, sources, CPPPATH=['src'])
"""

