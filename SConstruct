import os, sys
from stat import *
import shutil
import commands
import platform
import locale
import SCons.Conftest
root_dir = os.path.dirname(File('SConstruct').rfile().abspath)
sys.path.insert(0, os.path.join(root_dir, 'tools/scons_helper'))
import deps
from platform_utils import Config, platform
from sources import Sources

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

ROOT = 'src'
LIB_PREFIX = "src/third_party/icu"
WIN32_ICU = "src/third_party/icu/lib-win32/icuuc.lib src/third_party/icu/lib-win32/icuin.lib src/third_party/icu/lib-win32/icuio.lib src/third_party/icu/lib-win32/icutu.lib src/third_party/icu/lib-win32/icudt.lib src/third_party/icu/lib-win32/iculx.lib src/third_party/icu/lib-win32/icule.lib";
PLATFORM_CONFIG = {
    "linux" : {
        "TARGET" : 'bin/linux/mchd',
        "RELEASE" : '-Wall -O3 -DPLATFORM_POSIX -fno-exceptions -fno-rtti -DPLATFORM_LINUX -DNDEBUG -DCURRENT_DIR=\\"' + os.getcwd() + '/src\\" `icu-config --ldflags`',
        "DEBUG" : '-Wall -O0 -g -DPLATFORM_POSIX -fno-exceptions -fno-rtti -DDEBUG -DCURRENT_DIR=\\"' + os.getcwd() + '/src\\" `icu-config --ldflags`',
        "LD_FLAGS" : "-Xlinker -rpath -Xlinker `icu-config --icudata-install-dir --ldflags`",
        "LIBS" : ["pthread", "edit" ,"curses"],
        "EXCLUDE_FILES" : ["thread-win32.cc", "directory-win32.cc", "file_watcher-inotify-impl.cc", "shell-win32.cc"]
        },
    'macos' : {
        "TARGET" : 'bin/macos/mchd',
        "RELEASE" : '-Wall -Wextra -O3 -fno-exceptions -fno-rtti -DPLATFORM_POSIX -DPLATFORM_MACOS -DNDEBUG -DCURRENT_DIR=\\"' + os.getcwd() + '/src\\"',
        "DEBUG" : '-Wall -Wdisabled-optimization -Winline -O0 -g -fno-exceptions -fno-rtti -DDEBUG -DPLATFORM_POSIX -DCURRENT_DIR=\\"' + os.getcwd() + '/src\\"',
        "LD_FLAGS" : "",
        "LIBS" : ["pthread", "edit" ,"curses"],
        "STATIC_LIBS" : [LIB_PREFIX + '/lib-osx/libicui18n.a', LIB_PREFIX + '/lib-osx/libicuio.a', LIB_PREFIX + '/lib-osx/libiculx.a', LIB_PREFIX + '/lib-osx/libicudata.a', LIB_PREFIX + '/lib-osx/libicuuc.a', LIB_PREFIX + '/lib-osx/libicule.a'],
        "EXCLUDE_FILES" : ["thread-win32.cc", "directory-win32.cc", "file_watcher-inotify-impl.cc", "shell-win32.cc"]
        },
    "win32" : {
        "TARGET" : 'bin/win32/mchd.exe',
        "RELEASE" : '/Zi /nologo /W3 /WX- /O2 /Oi /Oy- /GL /D "NDEBUG" /D "_CRT_SECURE_NO_WARNINGS" /D "NOMINMAX" /D "_MBCS" /D "CURRENT_DIR=\\"' + os.getcwd().replace('\\', '/') + '/src\\"" /D "PLATFORM_WIN32" /Gm- /EHsc /MT /GS /Gy /fp:precise /Zc:wchar_t /Zc:forScope /Gd /analyze- /errorReport:queue',
        "DEBUG" : '/ZI /nologo /W3 /WX- /Od /Oy- /D "DEBUG" /D "_CRT_SECURE_NO_WARNINGS" /D "NOMINMAX" /D "_MBCS" /D "CURRENT_DIR=\\"' + os.getcwd().replace('\\', '/') + '/src\\"" /D "PLATFORM_WIN32" /Gm /EHsc /RTC1 /MTd /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd /analyze- /errorReport:queue',
        "LD_FLAGS" : "/NOLOGO /MACHINE:X86",
        "LIBS" : [LIB_PREFIX + '/lib-win32/icuin.lib', LIB_PREFIX + '/lib-win32/icudt.lib', LIB_PREFIX + '/lib-win32/icuuc.lib'],
        "EXCLUDE_FILES" : ["thread-posix.cc", "directory-posix.cc", "file_watcher-inotify-impl.cc", "shell-posix.cc"]
        }
    }
HEADER_LIST = [
    'unordered_map',
    'boost/unordered_map.hpp',
    'windows.h',
    'unistd.h',
    'sys/stat.h',
    'sys/inotify.h']

class MochaBuilder :
    def __init__(self, mode) :
        self.__config = Config(ROOT, PLATFORM_CONFIG)
        self.__config.AddExcludeDir(["v8","icu","phantomjs","ncurses-5.9"])
        self.__sources = Sources(self.__config)
        flags = self.__sources.GetFlags(mode)
        self.__env = Environment(CCFLAGS=flags[0],
                                 LIBS=flags[1],
                                 LINKFLAGS=flags[2])

    def Build(self) :
        self.__SetExtraHeaders(deps.CheckHeaders(self.__env, './src/mocha/config.h', 'C++', True, HEADER_LIST))
        targets = self.__sources.CreateSourceList()
        self.__env.Program(self.__config.target(), targets, CPPPATH=[self.__config.base()])

    def __SetExtraHeaders(self, has) :
        if has.has_key("HAVE_SYS_INOTIFY_H") and has["HAVE_SYS_INOTIFY_H"] is True :
            self.__config.RemoveExcludeFile("file_watcher-inotify-impl.cc")
            self.__config.AddExcludeFile(["file_watcher-impl.cc"])

ut = ARGUMENTS.get('ut')
CURRENT = os.getcwd().replace('\\', '/')
GTEST_DIR = CURRENT + '/src/third_party'
PLATFORM = platform
UNIT_TEST_CONFIG = {
    "linux" : {
        "TARGET" : 'ut',
        "RELEASE" : '-Wall -O3 -fno-exceptions -DPLATFORM_POSIX -DGOOGLE_TEST -DPLATFORM_LINUX -DNDEBUG -I' + GTEST_DIR + '/gtest-1.6.0-linux/include -I' + GTEST_DIR + '/gtest-1.6.0-linux -DCURRENT_DIR=\\"' + CURRENT + '\\" -I' + CURRENT + '/src',
        "DEBUG" : '-Wall -O0 -g -fno-exceptions -DDEBUG -DPLATFORM_POSIX  -DGOOGLE_TEST -I' + GTEST_DIR + '/gtest-1.6.0-linux/include -I' + GTEST_DIR + '/gtest-1.6.0-linux -DCURRENT_DIR=\\"' + CURRENT + '\\" -I' + CURRENT + '/src',
        "DEPENDS" : [GTEST_DIR + '/gtest-1.6.0-linux/src/gtest-all.cc',
                   GTEST_DIR + '/gtest-1.6.0-linux/src/gtest_main.cc']
        },
    'macos' : {
        "TARGET" : 'ut',
        "RELEASE" : '-Wall -Wextra -O3 -fno-exceptions -DPLATFORM_POSIX -DGOOGLE_TEST -DPLATFORM_MACOS -DNDEBUG -I' + GTEST_DIR + 'gtest-1.6.0-macos/include -I' + GTEST_DIR + ' -DCURRENT_DIR=\\"' + CURRENT + '\\" -I' + CURRENT + '/src',
        "DEBUG" : '-Wall -Wdisabled-optimization -DDEBUG -Winline -O0 -g -fno-exceptions  -DGOOGLE_TEST -DPLATFORM_POSIX -I' + GTEST_DIR + 'gtest-1.6.0-macos/include -I' + GTEST_DIR + ' -DCURRENT_DIR=\\"' + CURRENT + '\\" -I' + CURRENT + '/src',
        "DEPENDS" : [GTEST_DIR + '/gtest-1.6.0-osx/src/gtest-all.cc',
                   GTEST_DIR + '/gtest-1.6.0-osx/src/gtest_main.cc']
        },
    "win32" : {
        "TARGET" : 'ut.exe',
        "RELEASE" : '/Zi /nologo /W3 /WX- /O2 /Oi /Oy- /GL /D "NDEBUG" /D "GOOGLE_TEST" /D "_CRT_SECURE_NO_WARNINGS" /D "NOMINMAX" /D "_MBCS" /D "PLATFORM_WIN32" /Gm- /EHsc /MT /GS /Gy /fp:precise /Zc:wchar_t /Zc:forScope /Gd /analyze- /errorReport:queue /I ' + GTEST_DIR + '/gtest-1.6.0-win/include /I ' + GTEST_DIR + '/gtest-1.6.0-win /D CURRENT_DIR=\\"' + CURRENT + '\\" /I' + CURRENT + '/src',
        "DEBUG" : '/ZI /nologo /W3 /WX- /Od /Oy- /D "DEBUG" /D "_CRT_SECURE_NO_WARNINGS"  /D "GOOGLE_TEST" /D "NOMINMAX" /D "_MBCS" /D "PLATFORM_WIN32" /Gm /EHsc /RTC1 /MTd /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd /analyze- /errorReport:queue /I "' + GTEST_DIR + '/gtest-1.6.0-win/include" /I "' + GTEST_DIR + '/gtest-1.6.0-win" /D CURRENT_DIR=\\"' + CURRENT + '\\" /I' + CURRENT + '/src',
        "DEPENDS" : [GTEST_DIR + '/gtest-1.6.0-win/src/gtest-all.cc',
                   GTEST_DIR + '/gtest-1.6.0-win/src/gtest_main.cc'],
        "STATIC_LIBS" : [GTEST_DIR + '/gtest-1.6.0-win/msvc/gtest/Debug/gtestd.lib',]
        }
    }
TESTS = {'notificator' : 'src/mocha/roaster/notificator',
         'platform_utils' : 'src/mocha/roaster/platform/utils',
         'compiler_loader' : 'src/mocha/roaster/compiler/loader'}
if ut :
    ENV = Environment()
    CONFIG = Config(CURRENT, UNIT_TEST_CONFIG)
    if ut == 'all' :
        for test in TESTS :
            SConscript(test + '/SConscript', exports = ['CURRENT', 'ENV', 'CONFIG'])
    else :
        tests = ut.split(':')
        for test in tests :
            SConscript(TESTS[test] + '/SConscript', exports = ['CURRENT', 'ENV', 'CONFIG'])
else :
    builder = MochaBuilder(ARGUMENTS.get('mode'))
    builder.Build()
#MoveBinary(args[0])

