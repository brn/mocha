import os, sys
from stat import *
import shutil
import commands
import platform
import locale
import SCons.Conftest
root_dir = os.path.dirname(File('SConstruct').rfile().abspath)
sys.path.insert(0, os.path.join(root_dir, 'tools'))
sys.path.insert(0, os.path.join(root_dir, 'tools/scons_helper'))
import deps, makedeps
from platform_utils import Config, platform, platform
from sources import Sources
os.system('python tools/runtime.py')
CURRENT = os.getcwd().replace('\\', '/')
ROOT = 'src'
LIB_PREFIX = CURRENT + "/src/lib/icu"
WIN32_ICU = "src/third_party/icu/lib-win32/icuuc.lib src/third_party/icu/lib-win32/icuin.lib src/third_party/icu/lib-win32/icuio.lib src/third_party/icu/lib-win32/icutu.lib src/third_party/icu/lib-win32/icudt.lib src/third_party/icu/lib-win32/iculx.lib src/third_party/icu/lib-win32/icule.lib";
LINUX_INCLUDE = '-Isrc/.deps/linux/v8/include -Isrc/.deps/linux/libuv/include -Isrc/.deps/linux/icu/include -Isrc/.deps/linux/libedit/include'
MACOS_INCLUDE = '-I/opt/local/include -Isrc/.deps/macos/v8/include -Isrc/.deps/macos/libuv/include -Isrc/.deps/macos/icu/include -Isrc/.deps/macos/libedit/include'
PLATFORM_CONFIG = {
    "linux" : {
        "TARGET" : 'bin/linux/mchd',
        "RELEASE" : '-Wall -Wextra -O3 -DPLATFORM_POSIX -fno-exceptions -fno-rtti -fomit-frame-pointer -DPLATFORM_LINUX -DNDEBUG -DCURRENT_DIR=\\"' + os.getcwd() + '/src\\" ' + LINUX_INCLUDE,
        "DEBUG" : '-Wall -Wextra -O0 -g -DPLATFORM_POSIX -fno-exceptions -fno-rtti -DDEBUG -DCURRENT_DIR=\\"' + os.getcwd() + '/src\\" ' + LINUX_INCLUDE,
        "LD_FLAGS" : "",
        "LIBS" : ["pthread", "curses", "rt", "dl", "curses"],
        "STATIC_LIBS" : ['src/.deps/linux/v8/libv8.a' , 'src/.deps/linux/libuv/uv.a', 'src/.deps/linux/icu/libicui18n.a', 'src/.deps/linux/icu/libicuuc.a', 'src/.deps/linux/icu/libicudata.a', 'src/.deps/linux/libedit/libedit.a'],
        "EXCLUDE_FILES" : ["thread-win32.cc",
                           "process-win32.cc",
                           "directory-win32.cc",
                           "file_watcher-inotify-impl.cc",
                           "shell-win32.cc",
                           'utils-win32.cc']
        },
    'macos' : {
        "TARGET" : 'bin/macos/mchd',
        "RELEASE" : '-Wall -Wextra -O3 -fno-exceptions -fno-rtti -fomit-frame-pointer -DPLATFORM_POSIX -DPLATFORM_MACOS -DNDEBUG -DCURRENT_DIR=\\"' + os.getcwd() + '/src\\" ' + MACOS_INCLUDE,
        "DEBUG" : '-Wall -Wextra -Wdisabled-optimization -Winline -O0 -g -fno-exceptions -fno-rtti -DDEBUG -DPLATFORM_POSIX -DPLATFORM_MACOS -DCURRENT_DIR=\\"' + os.getcwd() + '/src\\" ' + MACOS_INCLUDE,
        "LD_FLAGS" : "",
        "LIBS" : ["pthread", "curses"],
        "STATIC_LIBS" : ['src/.deps/macos/icu/libicui18n.a', 'src/.deps/macos/icu/libicudata.a', 'src/.deps/macos/icu/libicuuc.a', 'src/.deps/macos/libedit/libedit.a', 'src/.deps/macos/v8/libv8.a' , 'src/.deps/macos/libuv/libuv.a'],
        "EXCLUDE_FILES" : ["thread-win32.cc",
                           "directory-win32.cc",
                           "file_watcher-inotify-impl.cc",
                           "shell-win32.cc",
                           'utils-win32.cc',
                           'process-win32.cc']
        },
    "win32" : {
        "TARGET" : 'bin/win32/mchd.exe',
        "RELEASE" : '/Zi /nologo /W3 /WX- /O2 /Oi /Oy- /GL /D "NDEBUG" /D "_CRT_SECURE_NO_WARNINGS" /D "NOMINMAX" /D "_MBCS" /D "CURRENT_DIR=\\"' + os.getcwd().replace('\\', '/') + '/src\\"" /D "PLATFORM_WIN32" /Gm- /EHsc /MT /GS /Gy /fp:precise /Zc:wchar_t /Zc:forScope /Gd /analyze- /errorReport:queue /I src/third_party/v8/include -/src/third_party/libuv/include',
        "DEBUG" : '/ZI /nologo /W3 /WX- /Od /Oy- /D "DEBUG" /D "_CRT_SECURE_NO_WARNINGS" /D "NOMINMAX" /D "_MBCS" /D "CURRENT_DIR=\\"' + os.getcwd().replace('\\', '/') + '/src\\"" /D "PLATFORM_WIN32" /Gm /EHsc /RTC1 /MTd /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd /analyze- /errorReport:queue /I src/third_party/v8/include /I src/third_party/libuv/include /FI WinSock2.h',
        "STATIC_LIBS" : ['src/third_party/v8/win32/v8_g.lib', 'src/third_party/libuv/Debug/lib/uv.lib'],
        "LD_FLAGS" : "/NOLOGO /MACHINE:X86",
        "LIBS" : [LIB_PREFIX + '/lib-win32/icuin.lib', LIB_PREFIX + '/lib-win32/icudt.lib', LIB_PREFIX + '/lib-win32/icuuc.lib', 'ws2_32', 'winmm', 'psapi', 'Advapi32', 'Iphlpapi'],
        "EXCLUDE_FILES" : ["thread-posix.cc", "directory-posix.cc", "file_watcher-inotify-impl.cc", "shell-posix.cc", 'utils-posix.cc']
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
        self.__config.AddExcludeFile(['ut.cc', 'ct.cc', 'notificator_test.cc', 'pack.cc', 'file_watcher-normal-impl.cc'])
        self.__config.AddExcludeDir(["v8","icu","phantomjs","ncurses-5.9", "gtest-1.6.0-win", "gtest-1.6.0-linux", "gtest-1.6.0-macos",'libuv'])
        self.__sources = Sources(self.__config)
        flags = self.__sources.GetFlags(mode)
        self.__env = Environment(CCFLAGS=flags[0],
                                 LIBS=flags[1],
                                 LINKFLAGS=flags[2])

    def Build(self) :
        #self.__SetExtraHeaders(deps.CheckHeaders(self.__env, './src/mocha/config.h', 'C++', True, HEADER_LIST))
        targets = self.__sources.CreateSourceList()
        target = self.__config.target()
        base_path = self.__config.base()
        self.__env.Program(target, targets, CPPPATH=[base_path])

    def __SetExtraHeaders(self, has) :
        if has.has_key("HAVE_SYS_INOTIFY_H") and has["HAVE_SYS_INOTIFY_H"] is True :
            self.__config.RemoveExcludeFile("file_watcher-inotify-impl.cc")
            self.__config.AddExcludeFile(["file_watcher-normal-impl.cc"])

ut = ARGUMENTS.get('ut')
ct = ARGUMENTS.get('ct')
pack = ARGUMENTS.get('pack')
GTEST_DIR = CURRENT + '/src/third_party'
PLATFORM = platform
UNIT_TEST_CONFIG = {
    "linux" : {
        "TARGET" : 'ut',
        "RELEASE" : '-Wall -O3 -fno-exceptions -DPLATFORM_POSIX -DGOOGLE_TEST -DPLATFORM_LINUX -DNDEBUG -I' + GTEST_DIR + '/gtest-1.6.0-linux/include -I' + GTEST_DIR + '/gtest-1.6.0-linux -DCURRENT_DIR=\\"' + CURRENT + '\\" -I' + CURRENT + '/src',
        "DEBUG" : '-Wall -O0 -g -fno-exceptions -DDEBUG -DPLATFORM_POSIX  -DGOOGLE_TEST -I' + GTEST_DIR + '/gtest-1.6.0-linux/include -I' + GTEST_DIR + '/gtest-1.6.0-linux -DCURRENT_DIR=\\"' + CURRENT + '\\" -I' + CURRENT + '/src',
        "DEPENDS" : [GTEST_DIR + '/gtest-1.6.0-linux/src/gtest-all.cc',
                     GTEST_DIR + '/gtest-1.6.0-linux/src/gtest_main.cc',
                     CURRENT + '/src/mocha/roaster/log/logging.cc']
        },
    'macos' : {
        "TARGET" : 'ut',
        "RELEASE" : '-Wall -Wextra -O3 -fno-exceptions -DPLATFORM_POSIX -DPLATFORM_MACOS -DGOOGLE_TEST -DPLATFORM_MACOS -DNDEBUG -I' + GTEST_DIR + '/gtest-1.6.0-macos/include -I' + GTEST_DIR + '/gtest-1.6.0-macos -DCURRENT_DIR=\\"' + CURRENT + '\\" -I' + CURRENT + '/src',
        "DEBUG" : '-Wall -Wdisabled-optimization -DDEBUG -Winline -O0 -g -fno-exceptions  -DGOOGLE_TEST -DPLATFORM_POSIX -DPLATFORM_MACOS -I' + GTEST_DIR + '/gtest-1.6.0-macos/include -I' + GTEST_DIR + '/gtest-1.6.0-macos -DCURRENT_DIR=\\"' + CURRENT + '\\" -I' + CURRENT + '/src',
        "DEPENDS" : [GTEST_DIR + '/gtest-1.6.0-macos/src/gtest-all.cc',
                     GTEST_DIR + '/gtest-1.6.0-macos/src/gtest_main.cc',
                     CURRENT + '/src/mocha/roaster/log/logging.cc'],
        "STATIC_LIBS" : []
        },
    "win32" : {
        "TARGET" : 'ut.exe',
        "RELEASE" : '/Zi /nologo /W3 /WX- /O2 /Oi /Oy- /GL /D "NDEBUG" /D "GOOGLE_TEST" /D "_CRT_SECURE_NO_WARNINGS" /D "NOMINMAX" /D "_MBCS" /D "PLATFORM_WIN32" /Gm- /EHsc /MT /GS /Gy /fp:precise /Zc:wchar_t /Zc:forScope /Gd /analyze- /errorReport:queue /I ' + GTEST_DIR + '/gtest-1.6.0-win/include /I ' + GTEST_DIR + '/gtest-1.6.0-win /D CURRENT_DIR=\\"' + CURRENT + '\\" /I' + CURRENT + '/src',
        "DEBUG" : '/ZI /nologo /W3 /WX- /Od /Oy- /D "DEBUG" /D "U_STATIC_IMPLEMENTATION" /D "_CRT_SECURE_NO_WARNINGS"  /D "GOOGLE_TEST" /D "NOMINMAX" /D "_MBCS" /D "PLATFORM_WIN32" /Gm /EHsc /RTC1 /MTd /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd /analyze- /errorReport:queue /I "' + GTEST_DIR + '/gtest-1.6.0-win/include" /I "' + GTEST_DIR + '/gtest-1.6.0-win" /D CURRENT_DIR=\\"' + CURRENT + '\\" /I' + CURRENT + '/src /I src/third_party/icu/include/',
        "DEPENDS" : [GTEST_DIR + '/gtest-1.6.0-win/src/gtest-all.cc',
                     GTEST_DIR + '/gtest-1.6.0-win/src/gtest_main.cc',
                     CURRENT + '/src/mocha/roaster/log/logging.cc'],
        "STATIC_LIBS" : [GTEST_DIR + '/gtest-1.6.0-win/msvc/gtest/Debug/gtestd.lib',]
        }
    }
TESTS = {'notificator' : 'src/mocha/roaster/notificator',
         'platform_utils' : 'src/mocha/roaster/platform/utils',
         'nexc-loader' : 'src/mocha/roaster/compiler/loader',
         'platform_stat' : 'src/mocha/roaster/platform/fs/stat',
         'platform_directory' : 'src/mocha/roaster/platform/fs/directory',
         'platform_path' : 'src/mocha/roaster/platform/fs/path',
         'platform_fsevent' : 'src/mocha/roaster/platform/fs/event/macos',
         'nexc' : 'src/mocha/roaster/nexc',
         'nexc-scanner' : 'src/mocha/roaster/nexc/scanner',
         'nexc-parser' : 'src/mocha/roaster/nexc/parser',
         'nexc-translator' : 'src/mocha/roaster/ast/translator',
         'nexc-pool' : 'src/mocha/roaster/memory'
         }
CT = {
   'nexc' : 'src/mocha/roaster/nexc/ct',
   'roaster' : 'src/mocha/roaster'
}


if ut :
    ENV = Environment()
    CONFIG = Config(CURRENT, UNIT_TEST_CONFIG)
    if ut == 'all' :
        for test in TESTS.values() :
            SConscript(test + '/SConscript', variant_dir=('.ut_temp_' + test), src_dir='./src', duplicate=0, exports = ['CURRENT', 'ENV', 'CONFIG', 'LIB_PREFIX'])
    else :
        tests = ut.split(':')
        for test in tests :
            SConscript(TESTS[test] + '/SConscript',  variant_dir=('.ut_temp_' + test), src_dir='./src', duplicate=0, exports = ['CURRENT', 'ENV', 'CONFIG', 'LIB_PREFIX'])

elif ct :
    ENV = Environment()
    CONFIG = Config(CURRENT, UNIT_TEST_CONFIG)
    if ct == 'all' :
        for test in CT.values() :
            SConscript(test + '/SConscript', variant_dir=('.ct_temp_' + test), src_dir='./src', duplicate=0, exports = ['CURRENT', 'ENV', 'CONFIG', 'LIB_PREFIX'])
    else :
        tests = ct.split(':')
        for test in tests :
            SConscript(CT[test] + '/SConscript', variant_dir=('.ct_temp_' + test), src_dir='./src', duplicate=0, exports = ['CURRENT', 'ENV', 'CONFIG', 'LIB_PREFIX'])
elif pack :
    ENV = Environment()
    SConscript('src/mocha/roaster/nexc/runtime/SConscript', variant_dir='.packed_temp', src_dir='./src', duplicate=0, exports = ['CURRENT', 'ENV', 'LIB_PREFIX'])
else :
    makedeps.MakeDeps()
    mode = ARGUMENTS.get('mode', 'release')
    builder = MochaBuilder(mode)
    builder.Build()

