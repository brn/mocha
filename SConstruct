import os, sys
from stat import *
import shutil
import commands
TARGET_NAME = 'mchd'
WIN32_ICU = "src/third_party/icu/lib-win32/icuuc.lib src/third_party/icu/lib-win32/icuin.lib src/third_party/icu/lib-win32/icuio.lib src/third_party/icu/lib-win32/icutu.lib src/third_party/icu/lib-win32/icudt.lib src/third_party/icu/lib-win32/iculx.lib src/third_party/icu/lib-win32/icule.lib";
REV = '\\"' + commands.getoutput("git show --format='%h' -s") + '\\"';
PLATFORM_FLAGS = {
"posix" : {
        "RELEASE" : '-Wall -O3 -DPLATFORM_POSIX -DMOCHA_REV=' + REV + ' -DNCURSES_STATIC -DNDEBUG -DCURRENT_DIR=\\"' + os.getcwd() + '/src\\" `icu-config --ldflags`',
        "DEBUG" : '-Wall -O0 -g -DPLATFORM_POSIX -DMOCHA_REV=' + REV + ' -DNCURSES_STATIC -DCURRENT_DIR=\\"' + os.getcwd() + '/src\\" `icu-config --ldflags`',
        "LD_FLAGS" : "-Xlinker -rpath -Xlinker `icu-config --icudata-install-dir --ldflags` -lpthread -Lsrc/third_party/ncurses-5.9/lib-posix",
        "LIBS" : ':ncursesw.a'
        },
'mac' : {
        "RELEASE" : '-Wall -O3 -DPLATFORM_POSIX -DNDEBUG -DCURRENT_DIR=\\"' + os.getcwd() + '/src\\" `icu-config --ldflags`',
        "DEBUG" : '-Wall -O0 -g -DPLATFORM_POSIX -DCURRENT_DIR=\\"' + os.getcwd() + '/src\\" `icu-config --ldflags`',
        "LD_FLAGS" : "-lpthread -Lsrc/third_party/ncurses-5.9/lib-posix -lncursesw -Xlinker -rpath -Xlinker `icu-config --icudata-install-dir -lpthread",
        "LIBS" : ':ncursesw.a'
        },
"win32" : {
        "RELEASE" : '/Zi /nologo /W3 /WX- /O2 /Oi /Oy- /GL /D "NDEBUG" /D "_CRT_SECURE_NO_WARNINGS" /D "NOMINMAX" /D "_MBCS" /D "CURRENT_DIR=\\"' + os.getcwd().replace('\\', '/') + '/src\\"" /D "PLATFORM_WIN32" /Gm- /EHsc /MT /GS /Gy /fp:precise /Zc:wchar_t /Zc:forScope /Gd /analyze- /errorReport:queue',
        "DEBUG" : '/ZI /nologo /W3 /WX- /Od /Oy- /D "_CRT_SECURE_NO_WARNINGS" /D "NOMINMAX" /D "_MBCS" /D "CURRENT_DIR=\\"' + os.getcwd().replace('\\', '/') + '/src\\"" /D "PLATFORM_WIN32" /Gm /EHsc /RTC1 /MTd /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd /analyze- /errorReport:queue',
        "LD_FLAGS" : "/NOLOGO /MACHINE:X86 " + WIN32_ICU
        }
}

def MoveBinary(path) :
    target_path = "bin/" + path
    try :
        if (not os.path.isdir(target_path) and not os.path.isfile(target_path)) :
            os.makedirs(target_path)
    except WindowsError :
        "nothing"
    suffix = '.exe' if path == 'win32' else ''
    binary = TARGET_NAME + suffix
    if (os.path.isfile(binary)) :
        target_file = target_path + '/' + binary
        shutil.copyfile(binary, target_file)
        if (path == 'win32') :
            dll_list = WIN32_ICU.split(' ')
            for dll in dll_list :
                target_dll = target_path + '/' + dll.rsplit('/', 1)[1].replace('.lib', '48.dll')
                if (not os.path.isfile(target_dll)) :
                    shutil.copyfile(dll, target_dll)

def GetFlags(platform, mode = 'DEBUG') :
    return (PLATFORM_FLAGS[platform][mode],
            PLATFORM_FLAGS[platform]["LIBS"],
            PLATFORM_FLAGS[platform]["LD_FLAGS"])

class MochaBuilder :
    def __init__(self, target, platform, mode) :
        self.__platform = platform
        self.__target = target
        flags = GetFlags(platform, mode)
        self.__env = Environment(CCFLAGS=flags[0],
                                 LIBS=flags[1],
                                 LINKFLAGS=flags[2])
        self.__root = 'src'
        self.__targets = []
        self.__third_party = {
            "v8" : 1,
            "icu" : 1,
            "phantomjs" : 1,
            "ncurses-5.9" : 1
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
                "file_watcher-inotify-impl.cc" : 1,
                "shell-win32.cc" : 1
                }
            }
    
    @staticmethod
    def CheckArgs():
        platforms = ARGUMENTS.get('platform')
        opt = ARGUMENTS.get('mode');
        if not platforms or (platforms != 'win32' and platforms != 'mac' and platforms != 'posix') :
            print """
error you must select specific build platform as arguments.
selectable platforms :
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

args = MochaBuilder.CheckArgs()
builder = MochaBuilder(TARGET_NAME, args[0], args[1])
builder.Build()
MoveBinary(args[0])


