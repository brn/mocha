#ifndef mocha_v8wrap_v8_fs_h_
#define mocha_v8wrap_v8_fs_h_
#include <stdio.h>
#include <v8.h>
#include <mocha/roaster/misc/class_traits/static.h>
namespace mocha {
namespace os { namespace fs {
class DirEntry;
}}
#define DECL_METHOD(name) static v8::Handle<v8::Value> name(const v8::Arguments& args)
#define DECL_DIPOSER static void Dispose(v8::Persistent<v8::Value> handle, void* ptr);
#define INIT_DECL static void Init(v8::Handle<v8::Object> object)
class NativeWrap : private Static {
 public :
  INIT_DECL;
  class Directory : private Static {
   public :
    INIT_DECL;
    DECL_DIPOSER;
    DECL_METHOD(New);
    DECL_METHOD(Dir);
    DECL_METHOD(Entries);
    DECL_METHOD(Mkdir);
    DECL_METHOD(Rm);
    DECL_METHOD(Chdir);
    class Entry : private Static {
     public :
      static v8::Handle<v8::Function> Init();
      DECL_DIPOSER;
      static v8::Handle<v8::Object> New(const os::fs::DirEntry* ent, v8::Handle<v8::Function> fn);
      DECL_METHOD(Name);
      DECL_METHOD(Path);
      DECL_METHOD(FullPath);
      DECL_METHOD(IsDir);
      DECL_METHOD(IsFile);
    };
  };
  class Path : private Static {
   public :
    INIT_DECL;
    DECL_DIPOSER;
    DECL_METHOD(New);
    DECL_METHOD(Filename);
    DECL_METHOD(AbsolutePath);
    DECL_METHOD(Directory);
    DECL_METHOD(Getcwd);
    DECL_METHOD(Home);
  };
  class Stat : private Static {
   public :
    INIT_DECL;
    DECL_DIPOSER;
    DECL_METHOD(New);
    DECL_METHOD(IsDir);
    DECL_METHOD(IsReg);
    DECL_METHOD(IsChr);
    DECL_METHOD(IsExist);
    DECL_METHOD(Dev);
    DECL_METHOD(Ino);
    DECL_METHOD(NLink);
    DECL_METHOD(UId);
    DECL_METHOD(GId);
    DECL_METHOD(RDev);
    DECL_METHOD(Size);
    DECL_METHOD(ATime);
    DECL_METHOD(MTime);
    DECL_METHOD(CTime);
    DECL_METHOD(StaticIsDir);
    DECL_METHOD(StaticIsReg);
  };

  class File : private Static {
   public :
    static v8::Handle<v8::Object> Init(FILE* fp);
    DECL_METHOD(GetTextContent);
    DECL_METHOD(WriteTextContent);
    DECL_METHOD(FWrite);
    DECL_METHOD(FRead);
    DECL_METHOD(FClose);
  };
  
  class IO : private Static {
   public :
    INIT_DECL;
    DECL_METHOD(FOpen);
    class NativeConsole : private Static {
     public :
      INIT_DECL;
      DECL_METHOD(Stdout);
      DECL_METHOD(StdError);
    };
  };
  
  class Watcher : private Static {
   public :
    INIT_DECL;
    DECL_DIPOSER;
    DECL_METHOD(Run);
    DECL_METHOD(Exit);
    DECL_METHOD(IsRunning);
    DECL_METHOD(Stop);
    DECL_METHOD(Resume);
    DECL_METHOD(AddSetting);
    DECL_METHOD(GetSettingList);
    DECL_METHOD(RemoveSetting);
  };

  class Config : private Static {
   public :
    INIT_DECL;
    DECL_METHOD(Set);
    DECL_METHOD(Get);
    DECL_METHOD(Has);
  };

  class Compiler : private Static {
   public :
    INIT_DECL;
    DECL_METHOD(Compile);
    DECL_METHOD(CheckDepends);
    DECL_METHOD(CompileFile);
    DECL_METHOD(Deploy);
  };

  class Repl {
   public :
    INIT_DECL;
    DECL_METHOD(Exit);
  };

  class ProcessSpawner {
   public :
    INIT_DECL;
    DECL_METHOD(Spawn);
  };

  class InternalLogger {
   public :
    INIT_DECL;
    DECL_METHOD(Initialize);
  };
};
#undef DECL_METHOD
#undef DECL_DIPOSER
#undef INIT_DECL
}

#endif
