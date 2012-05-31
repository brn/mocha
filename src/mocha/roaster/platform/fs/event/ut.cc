import os, sys
root_dir = os.path.dirname(File('SConscript').rfile().abspath + '/../../../../')
sys.path.insert(0, os.path.join(root_dir, 'tools/scons_helper'))
from platform_utils import Config
from test import TestBuilder
Import('CURRENT')
Import('ENV')
Import('CONFIG')
ROOT = os.getcwd().replace('\\', '/')
TEST_CONFIG = CONFIG.Copy()
TEST_CONFIG.Extend({
        "linux" : {
            "LD_FLAGS" : "",
            "LIBS" : ['pthread'],
            "EXCLUDE_FILES" : [],
            "EXCLUDE_DIRS" : ['macos', 'win32'],
            "DEPENDS" : ['linux/ut.cc', 'linux/fs_watcher_linux.cc', CURRENT + '/src/mocha/roaster/platform/thread/thread-posix.cc',
            CURRENT + '/src/mocha/roaster/platform/utils/utils-posix.cc']
            },
        'macos' : {
            "LD_FLAGS" : "",
            "LIBS" : [],
            "STATIC_LIBS" : [],
            "EXCLUDE_FILES" : [],
            "DEPENDS" : ['macos/ut.cc', 'macos/fs_watcher_linux.cc', CURRENT + '/src/mocha/roaster/platform/thread/thread-posix.cc',
            CURRENT + '/src/mocha/roaster/platform/utils/utils-posix.cc',]
            },
        "win32" : {
            "LD_FLAGS" : "/NOLOGO /MACHINE:X86",
            "LIBS" : [],
            "EXCLUDE_FILES" : [],
            "DEPENDS" : ['win32/ut.cc', 'win32/fs_watcher_linux.cc', CURRENT + '/src/mocha/roaster/platform/thread/thread-win32.cc',
            CURRENT + '/src/mocha/roaster/platform/utils/utils-win.cc',]
            }
        })
TEST_CONFIG.set_base(ROOT)
builder = TestBuilder(ARGUMENTS.get('mode'), [CURRENT + '/src/mocha/roaster/platform/fs/event/event.cc',
                                              CURRENT + '/src/mocha/roaster/platform/fs/stat/stat.cc',
                                              CURRENT + '/src/mocha/roaster/platform/fs/mv/mv.cc',
                                              CURRENT + '/src/mocha/roaster/platform/fs/event/md5.cc',
                                              CURRENT + '/src/mocha/roaster/memory/pool.cc'], ENV, TEST_CONFIG)
builder.Build(CURRENT + '/src', ROOT, CURRENT, True)

