import os, shutil, sys
sys.path.insert(0, os.path.join(str(os.getcwd()), 'scons_helper'))
from platform_utils import platform

def MakeDeps() :
    if platform == 'linux' :
        os.system('tools/make_lib.sh linux libv8.a uv.a uv.a')
    elif platform == 'macos' :
        os.system('tools/make_lib.sh macos libv8.a libuv.a build/Release/libuv.a')
    elif platform == 'win32' :
        os.system('tools/winbuild.bat')
