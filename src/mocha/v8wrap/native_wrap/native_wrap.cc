#include <string.h>
#include <mocha/v8wrap/init.h>
#include <mocha/v8wrap/initjs.h>
#include <mocha/v8wrap/native_wrap/native_wrap.h>
#include <mocha/roaster/ast/seriarization/byte.h>
#include <mocha/fileinfo/fileinfo.h>
#include <mocha/options/setting.h>
#include <mocha/misc/file_watcher/observer/javascript_observer.h>
#include <mocha/roaster/platform/fs/fs.h>
#include <mocha/roaster/roaster.h>
#include <mocha/misc/file_writer.h>
#include <mocha/bootstrap/interactions/interaction.h>
#include <mocha/process/process.h>
using namespace v8;
namespace mocha {
#define METHOD_IMPL(name) Handle<Value> name(const Arguments& args)

#define DISPOSE_IMPL(name,type)                                 \
  void name::Dispose(Persistent<Value> handle, void* ptr) {     \
    DoDispose<type>(ptr);                                       \
    handle.ClearWeak();                                         \
    handle.Dispose();                                           \
    handle.Clear();                                             \
  }

template <typename T>
void DoDispose(void* ptr) {
  T* entity = static_cast<T*>(ptr);
  delete entity;
}

void NativeWrap::Init(Handle<Object> object) {
  HandleScope handle_scope;
  Persistent<Object> ns_fs = V8Init::GetInstance()->REGIST_PERSISTENT(Object::New(), "Namespace<FS>");
  Persistent<Object> ns_io = V8Init::GetInstance()->REGIST_PERSISTENT(Object::New(), "Namespace<IO>");
  Persistent<Object> ns_console = V8Init::GetInstance()->REGIST_PERSISTENT(Object::New(), "Namespace<Config>");
  Persistent<Object> ns_setting = V8Init::GetInstance()->REGIST_PERSISTENT(Object::New(), "Namespace<Setting>");
  Persistent<Object> invalid = V8Init::GetInstance()->REGIST_PERSISTENT(Object::New(), "InvalidObject");
  Persistent<Object> repl_ns = V8Init::GetInstance()->REGIST_PERSISTENT(Object::New(), "Namespace<Repl>");
  Persistent<Object> os_ns = V8Init::GetInstance()->REGIST_PERSISTENT(Object::New(), "Namespace<OS>");
  Persistent<Object> logger_ns = V8Init::GetInstance()->REGIST_PERSISTENT(Object::New(), "Namespace<InternalLogger>");
  NativeWrap::Directory::Init(ns_fs);
  NativeWrap::Path::Init(ns_fs);
  NativeWrap::Stat::Init(ns_fs);
  NativeWrap::IO::Init(ns_io);
  NativeWrap::IO::NativeConsole::Init(ns_console);
  NativeWrap::Watcher::Init(ns_setting);
  NativeWrap::Config::Init(object);
  NativeWrap::Compiler::Init(ns_setting);
  NativeWrap::Repl::Init(repl_ns);
  NativeWrap::ProcessSpawner::Init(os_ns);
  NativeWrap::InternalLogger::Init(logger_ns);
  ns_io->Set(String::New("nativeConsole"), ns_console);
  object->Set(String::New("fs"), ns_fs);
  object->Set(String::New("script"), ns_setting);
  object->Set(String::New("io"), ns_io);
  object->Set(String::New("invalid"), invalid);
  object->Set(String::New("repl"), repl_ns);
  object->Set(String::New("os"), os_ns);
  object->Set(String::New("internalLogger"), logger_ns);
}


Handle<v8::Function> NativeWrap::Directory::Entry::Init() {
  HandleScope handle_scope;
  Handle<v8::FunctionTemplate> fn = v8::FunctionTemplate::New();
  fn->SetClassName(String::New("Entry"));
  Handle<ObjectTemplate> inst = fn->InstanceTemplate();
  return handle_scope.Close(fn->GetFunction());
}

Handle<Object> NativeWrap::Directory::Entry::New(const os::fs::DirEntry* ent, Handle<v8::Function> fn) {
  HandleScope handle_scope;
  Handle<Object> instance = fn->NewInstance();
  instance->Set(String::New("fullpath"), String::New(ent->GetFullPath()));
  instance->Set(String::New("name"), String::New(ent->GetName()));
  instance->Set(String::New("dir"), String::New(ent->GetDirName()));
  instance->Set(String::New("isdir"), Boolean::New(ent->IsDir()));
  instance->Set(String::New("isfile"), Boolean::New(ent->IsFile()));
  return handle_scope.Close(instance);
}

METHOD_IMPL(NativeWrap::Directory::Entry::Name) {
  os::fs::DirEntry* dir = V8Init::GetInternalPtr<os::fs::DirEntry, 0>(args.This());
  return String::New(dir->GetName());
}

METHOD_IMPL(NativeWrap::Directory::Entry::FullPath) {
  os::fs::DirEntry* dir = V8Init::GetInternalPtr<os::fs::DirEntry, 0>(args.This());
  return String::New(dir->GetFullPath());
}

METHOD_IMPL(NativeWrap::Directory::Entry::Path) {
  os::fs::DirEntry* dir = V8Init::GetInternalPtr<os::fs::DirEntry, 0>(args.This());
  return String::New(dir->GetDirName());
}

METHOD_IMPL(NativeWrap::Directory::Entry::IsDir) {
  os::fs::DirEntry* dir = V8Init::GetInternalPtr<os::fs::DirEntry, 0>(args.This());
  return Boolean::New(dir->IsDir());
}

METHOD_IMPL(NativeWrap::Directory::Entry::IsFile) {
  os::fs::DirEntry* dir = V8Init::GetInternalPtr<os::fs::DirEntry, 0>(args.This());
  return Boolean::New(dir->IsFile());
}

DISPOSE_IMPL(NativeWrap::Directory::Entry, os::fs::DirEntry);


void NativeWrap::Directory::Init(Handle<Object> object) {
  HandleScope handle_scope;
  Handle<v8::FunctionTemplate> fn = v8::FunctionTemplate::New(NativeWrap::Directory::Dir);
  fn->SetClassName(String::New("Dir"));
  Handle<ObjectTemplate> inst = fn->InstanceTemplate();
  inst->SetInternalFieldCount(2);
  Handle<ObjectTemplate> proto = fn->PrototypeTemplate();
  proto->Set(String::New("entries"), v8::FunctionTemplate::New(NativeWrap::Directory::Entries));
  Handle<v8::FunctionTemplate> mkdir_tmp = v8::FunctionTemplate::New(NativeWrap::Directory::Mkdir);
  Handle<v8::FunctionTemplate> rm_tmp = v8::FunctionTemplate::New(NativeWrap::Directory::Rm);
  Handle<v8::FunctionTemplate> chdir_tmp = v8::FunctionTemplate::New(NativeWrap::Directory::Chdir);
  Handle<v8::Function> function = fn->GetFunction();
  function->Set(String::New("mkdir"), mkdir_tmp->GetFunction());
  function->Set(String::New("rm"), rm_tmp->GetFunction());
  function->Set(String::New("chdir"), chdir_tmp->GetFunction());
  object->Set(String::New("Dir"), handle_scope.Close(function));
}


METHOD_IMPL(NativeWrap::Directory::Dir) {
  HandleScope handle_scope;
  if (args.IsConstructCall()) {
    if (args.Length() > 0) {
      if (args[0]->IsString()) {
        String::Utf8Value path(args[0]);
        os::fs::Path path_info(*path);
        os::fs::Stat stat(path_info.absolute_path());
        if (stat.IsExist() && stat.IsDir()) {
          os::fs::Directory* dir = new os::fs::Directory(path_info.absolute_path());
          V8::AdjustAmountOfExternalAllocatedMemory(sizeof(os::fs::Directory));
          Handle<Object> this_object = args.This();
          this_object->SetPointerInInternalField(0, dir);
          this_object->SetInternalField(1, NativeWrap::Directory::Entry::Init());
          Persistent<Object> holder = Persistent<Object>::New(this_object);
          holder.MakeWeak(dir, NativeWrap::Directory::Dispose);
          holder.MarkIndependent();
          return handle_scope.Close(this_object);
        } else if (!stat.IsExist()){
          std::string buf;
		  os::SPrintf(&buf, "%s No such directory.", path_info.absolute_path());
          return ThrowException(Exception::Error(String::New(buf.c_str())));
        } else if (!stat.IsDir()) {
          std::string buf;
		  os::SPrintf(&buf, "%s Not a directory.", path_info.absolute_path());
          return ThrowException(Exception::Error(String::New(buf.c_str())));
        }
      } else {
        return ThrowException(Exception::Error(String::New("The arguments of dir must be a string.")));
      }
    }
    return ThrowException(Exception::Error(String::New("The function dir need at least one arguments.")));
  }
  return ThrowException(Exception::Error(String::New("To call the function Dir, use new operator.")));
}


DISPOSE_IMPL(NativeWrap::Directory, os::fs::Directory);


METHOD_IMPL(NativeWrap::Directory::Entries) {
  if (args.Length() > 0) {
    if (args[0]->IsBoolean()) {
      bool recursive = args[0]->IsTrue();
      os::fs::Directory* dir = V8Init::GetInternalPtr<os::fs::Directory, 0>(args.This());
      os::fs::Directory::const_iterator it = dir->Entries(recursive);
      Handle<Array> entries = Array::New();
      int count = 0;
      for (; it != dir->end(); ++it) {
        Handle<v8::Function> entry = Handle<v8::Function>::Cast(args.This()->GetInternalField(1));
        Handle<Object> obj = NativeWrap::Directory::Entry::New(&(*it), entry);
        entries->Set(Integer::New(count), obj);
        count++;
      }
      return entries;
    }
    return ThrowException(Exception::Error(String::New("The arguments of dir.entries must be a boolean.")));
  }
  return ThrowException(Exception::Error(String::New("The function dir.entries need at least one arguments.")));
}


METHOD_IMPL(NativeWrap::Directory::Mkdir) {
  if (args.Length() > 0) {
    if (args[0]->IsString()) {
      String::Utf8Value path(args[0]);
      os::fs::mkdir(*path, 0777);
      os::fs::Directory::chmod(*path, 0777);
      return Undefined();
    }
    return ThrowException(Exception::Error(String::New("The arguments of dir.mkdir must be a boolean.")));
  }
  return ThrowException(Exception::Error(String::New("The function dir.mkdir need at least one arguments.")));
}

METHOD_IMPL(NativeWrap::Directory::Chdir) {
  if (args.Length() > 0) {
    if (args[0]->IsString()) {
      String::Utf8Value path(args[0]);
      os::fs::Directory::chdir(*path);
      return Undefined();
    }
    return ThrowException(Exception::Error(String::New("The arguments of dir.mkdir must be a boolean.")));
  }
  return ThrowException(Exception::Error(String::New("The function dir.mkdir need at least one arguments.")));
}

METHOD_IMPL(NativeWrap::Directory::Rm) {
  if (args.Length() > 0) {
    if (args[0]->IsString()) {
      String::Utf8Value path(args[0]);
      os::fs::rm(*path);
      return Undefined();
    }
    return ThrowException(Exception::Error(String::New("The arguments of dir.rm must be a boolean.")));
  }
  return ThrowException(Exception::Error(String::New("The function dir.rm need at least one arguments.")));  
}


void NativeWrap::Path::Init(Handle<Object> object) {
  HandleScope handle_scope;
  Handle<v8::FunctionTemplate> fn = v8::FunctionTemplate::New(NativeWrap::Path::New);
  fn->SetClassName(String::New("Path"));
  Handle<ObjectTemplate> inst = fn->InstanceTemplate();
  inst->SetInternalFieldCount(1);
  Handle<ObjectTemplate> proto = fn->PrototypeTemplate();
  proto->Set(String::New("filename"), v8::FunctionTemplate::New(NativeWrap::Path::Filename));
  proto->Set(String::New("fullpath"), v8::FunctionTemplate::New(NativeWrap::Path::AbsolutePath));
  proto->Set(String::New("directory"), v8::FunctionTemplate::New(NativeWrap::Path::Directory));
  Handle<v8::Function> function = fn->GetFunction();
  Handle<v8::FunctionTemplate> getcwd_tmp = v8::FunctionTemplate::New(NativeWrap::Path::Getcwd);
  Handle<v8::FunctionTemplate> home_tmp = v8::FunctionTemplate::New(NativeWrap::Path::Home);
  function->Set(String::New("getcwd"), getcwd_tmp->GetFunction());
  function->Set(String::New("homeDir"), home_tmp->GetFunction());
  object->Set(String::New("Path"), handle_scope.Close(function));
}


METHOD_IMPL(NativeWrap::Path::New) {
  if (args.Length() > 0) {
    if (args[0]->IsString()) {
      HandleScope handle_scope;
      String::Utf8Value path(args[0]);
      os::fs::Path* path_info = new os::fs::Path(*path);
      V8::AdjustAmountOfExternalAllocatedMemory(sizeof(os::fs::Path));
      Handle<Object> this_object = args.This();
      this_object->SetPointerInInternalField(0, path_info);
      Persistent<Object> holder = Persistent<Object>::New(this_object);
      holder.MakeWeak(path_info, NativeWrap::Path::Dispose);
      holder.MarkIndependent();
      return handle_scope.Close(this_object);
    } else {
      return ThrowException(Exception::Error(String::New("The arguments of path must be a string.")));
    }
  }
  return ThrowException(Exception::Error(String::New("The function path need at least one arguments.")));
}

METHOD_IMPL(NativeWrap::Path::Filename) {
  os::fs::Path* path_info = V8Init::GetInternalPtr<os::fs::Path, 0>(args.This());
  return String::New(path_info->filename());
}

METHOD_IMPL(NativeWrap::Path::AbsolutePath) {
  os::fs::Path* path_info = V8Init::GetInternalPtr<os::fs::Path, 0>(args.This());
  return String::New(path_info->absolute_path());
}

METHOD_IMPL(NativeWrap::Path::Directory) {
  os::fs::Path* path_info = V8Init::GetInternalPtr<os::fs::Path, 0>(args.This());
  return String::New(path_info->directory());
}

Handle<Value> NativeWrap::Path::Getcwd(const Arguments&) {
  return String::New(os::fs::Path::current_directory());
}

Handle<Value> NativeWrap::Path::Home(const Arguments&) {
  return String::New(os::fs::Path::home_directory());
}

DISPOSE_IMPL(NativeWrap::Path, os::fs::Path);

void NativeWrap::Stat::Init(Handle<Object> object) {
  HandleScope handle_scope;
  Handle<v8::FunctionTemplate> fn = v8::FunctionTemplate::New(NativeWrap::Stat::New);
  fn->SetClassName(String::New("Stat"));
  Handle<ObjectTemplate> inst = fn->InstanceTemplate();
  inst->SetInternalFieldCount(1);
  Handle<ObjectTemplate> proto = fn->PrototypeTemplate();
  proto->Set(String::New("isDir"), v8::FunctionTemplate::New(NativeWrap::Stat::IsDir));
  proto->Set(String::New("isReg"), v8::FunctionTemplate::New(NativeWrap::Stat::IsReg));
  proto->Set(String::New("isChr"), v8::FunctionTemplate::New(NativeWrap::Stat::IsChr));
  proto->Set(String::New("isExist"), v8::FunctionTemplate::New(NativeWrap::Stat::IsExist));
  proto->Set(String::New("dev"), v8::FunctionTemplate::New(NativeWrap::Stat::Dev));
  proto->Set(String::New("ino"), v8::FunctionTemplate::New(NativeWrap::Stat::Ino));
  proto->Set(String::New("nlink"), v8::FunctionTemplate::New(NativeWrap::Stat::NLink));
  proto->Set(String::New("uid"), v8::FunctionTemplate::New(NativeWrap::Stat::UId));
  proto->Set(String::New("gid"), v8::FunctionTemplate::New(NativeWrap::Stat::GId));
  proto->Set(String::New("rdev"), v8::FunctionTemplate::New(NativeWrap::Stat::RDev));
  proto->Set(String::New("size"), v8::FunctionTemplate::New(NativeWrap::Stat::Size));
  proto->Set(String::New("atime"), v8::FunctionTemplate::New(NativeWrap::Stat::ATime));
  proto->Set(String::New("mtime"), v8::FunctionTemplate::New(NativeWrap::Stat::MTime));
  proto->Set(String::New("ctime"), v8::FunctionTemplate::New(NativeWrap::Stat::CTime));
  Handle<v8::Function> function = fn->GetFunction();
  function->Set(String::New("isDir"), v8::FunctionTemplate::New(NativeWrap::Stat::StaticIsDir)->GetFunction());
  function->Set(String::New("isReg"), v8::FunctionTemplate::New(NativeWrap::Stat::StaticIsReg)->GetFunction());
  object->Set(String::New("Stat"), handle_scope.Close(function));
}

METHOD_IMPL(NativeWrap::Stat::New) {
  if (args.Length() > 0) {
    if (args[0]->IsString()) {
      HandleScope handle_scope;
      String::Utf8Value path(args[0]);
      os::fs::Stat* stat = new os::fs::Stat(*path);
      V8::AdjustAmountOfExternalAllocatedMemory(sizeof(os::fs::Stat));
      Local<Object> this_object = args.This();
      this_object->SetPointerInInternalField(0, stat);
      Persistent<Object> holder = Persistent<Object>::New(this_object);
      holder.MakeWeak(stat, NativeWrap::Stat::Dispose);
      holder.MarkIndependent();
      return handle_scope.Close(this_object);
    } else {
      return ThrowException(Exception::Error(String::New("The arguments of stat must be a string.")));
    }
  }
  return ThrowException(Exception::Error(String::New("The function stat need at least one arguments.")));
}

METHOD_IMPL(NativeWrap::Stat::IsDir) {
  os::fs::Stat* stat = V8Init::GetInternalPtr<os::fs::Stat, 0>(args.This());
  return Boolean::New(stat->IsDir());
}

METHOD_IMPL(NativeWrap::Stat::IsChr) {
  os::fs::Stat* stat = V8Init::GetInternalPtr<os::fs::Stat, 0>(args.This());
  return Boolean::New(stat->IsChr());
}

METHOD_IMPL(NativeWrap::Stat::IsExist) {
  os::fs::Stat* stat = V8Init::GetInternalPtr<os::fs::Stat, 0>(args.This());
  return Boolean::New(stat->IsExist());
}

METHOD_IMPL(NativeWrap::Stat::Dev) {
  os::fs::Stat* stat = V8Init::GetInternalPtr<os::fs::Stat, 0>(args.This());
  return Integer::New(stat->Dev());
}

METHOD_IMPL(NativeWrap::Stat::Ino) {
  os::fs::Stat* stat = V8Init::GetInternalPtr<os::fs::Stat, 0>(args.This());
  return Integer::New(stat->Ino());
}

METHOD_IMPL(NativeWrap::Stat::NLink) {
  os::fs::Stat* stat = V8Init::GetInternalPtr<os::fs::Stat, 0>(args.This());
  return Integer::New(stat->NLink());
}

METHOD_IMPL(NativeWrap::Stat::UId) {
  os::fs::Stat* stat = V8Init::GetInternalPtr<os::fs::Stat, 0>(args.This());
  return Integer::New(stat->UId());
}

METHOD_IMPL(NativeWrap::Stat::GId) {
  os::fs::Stat* stat = V8Init::GetInternalPtr<os::fs::Stat, 0>(args.This());
  return Integer::New(stat->GId());
}

METHOD_IMPL(NativeWrap::Stat::RDev) {
  os::fs::Stat* stat = V8Init::GetInternalPtr<os::fs::Stat, 0>(args.This());
  return Integer::New(stat->RDev());
}

METHOD_IMPL(NativeWrap::Stat::Size) {
  os::fs::Stat* stat = V8Init::GetInternalPtr<os::fs::Stat, 0>(args.This());
  return Integer::New(stat->Size());
}

METHOD_IMPL(NativeWrap::Stat::ATime) {
  os::fs::Stat* stat = V8Init::GetInternalPtr<os::fs::Stat, 0>(args.This());
  return String::New(stat->ATime());
}

METHOD_IMPL(NativeWrap::Stat::MTime) {
  os::fs::Stat* stat = V8Init::GetInternalPtr<os::fs::Stat, 0>(args.This());
  return String::New(stat->MTime());
}

METHOD_IMPL(NativeWrap::Stat::CTime) {
  os::fs::Stat* stat = V8Init::GetInternalPtr<os::fs::Stat, 0>(args.This());
  return String::New(stat->CTime());
}

METHOD_IMPL(NativeWrap::Stat::IsReg) {
  os::fs::Stat* stat = V8Init::GetInternalPtr<os::fs::Stat, 0>(args.This());
  return Boolean::New(stat->IsReg());
}

METHOD_IMPL(NativeWrap::Stat::StaticIsReg) {
  if (args.Length() > 0) {
    if (args[0]->IsString()) {
      String::Utf8Value str(args[0]);
      os::fs::Stat stat(*str);
      return Boolean::New(stat.IsReg());
    }
  }
  return Undefined();
}

METHOD_IMPL(NativeWrap::Stat::StaticIsDir) {
  if (args.Length() > 0) {
    if (args[0]->IsString()) {
      String::Utf8Value str(args[0]);
      os::fs::Stat stat(*str);
      return Boolean::New(stat.IsDir());
    }
  }
  return Undefined();
}

DISPOSE_IMPL(NativeWrap::Stat, os::fs::Stat);


void NativeWrap::IO::Init(Handle<Object> object) {
  HandleScope handle_scope;
  Handle<FunctionTemplate> fn = FunctionTemplate::New(NativeWrap::IO::FOpen);
  fn->SetClassName(String::New("fopen"));
  object->Set(String::New("fopen"), handle_scope.Close(fn->GetFunction()));
}


Handle<Object> NativeWrap::File::Init(FILE* fp) {
  HandleScope handle_scope;
  Handle<v8::FunctionTemplate> fn = v8::FunctionTemplate::New();
  Handle<ObjectTemplate> inst = fn->InstanceTemplate();
  inst->SetInternalFieldCount(2);
  Handle<ObjectTemplate> proto = fn->PrototypeTemplate();
  proto->Set(String::New("write"), v8::FunctionTemplate::New(FWrite));
  proto->Set(String::New("read"), v8::FunctionTemplate::New(FRead));
  proto->Set(String::New("writeTextContent"), v8::FunctionTemplate::New(WriteTextContent));
  proto->Set(String::New("getTextContent"), v8::FunctionTemplate::New(GetTextContent));
  proto->Set(String::New("close"), v8::FunctionTemplate::New(FClose));
  Handle<Object> instance = fn->GetFunction()->NewInstance();
  instance->SetPointerInInternalField(0, fp);
  instance->SetInternalField(1, Boolean::New(true));
  return handle_scope.Close(instance);
}

METHOD_IMPL(NativeWrap::File::WriteTextContent) {
  if (args.Length() == 1) {
    if (args[0]->IsString()) {
      bool is_opened = args.This()->GetInternalField(1)->IsTrue();
      if (is_opened) {
        String::Utf8Value str(args[0]);
        const char* content = *str;
        FILE* fp = V8Init::GetInternalPtr<FILE, 0>(args.This());
        if (fp != NULL) {
          fwrite(content, sizeof(char), strlen(content), fp);
        } else {
          return ThrowException(Exception::Error(String::New("Invalid file.")));
        }
      } else {
        return ThrowException(Exception::Error(String::New("File is already closed.")));
      }
    } else {
      return ThrowException(Exception::Error(String::New("The arguments of stat must be a string.")));
    }
  } else {
    return ThrowException(Exception::Error(String::New("The function writeTextContent need at least one arguments.")));
  }
  return Undefined();
}

bool BinaryFlagIsValid(char val) {
  if (val != 'B' &&
      val != 'H' &&
      val != 'L') {
    return false;
  }
  return true;
}

int GetWriteSizeFromBinaryFlag(char flag) {
  return (flag == 'B')? 1 : (flag == 'H')? 2 : 4;
}

METHOD_IMPL(NativeWrap::File::FWrite) {
  if (args.Length() == 2) {
    if (args[0]->IsString()) {
      String::Utf8Value type(args[0]);
      if (type.length() > 0) {
        bool has_endian_flag = false;
        const char* ctype = *type;
        if (type.length() == 1 && BinaryFlagIsValid(ctype[0])) {
          return ThrowException(Exception::Error(String::New("Invalid byte flag.")));
        } else if (type.length() == 2) {
          has_endian_flag = true;
          if (ctype[0] != '<' &&
              ctype[0] != '>' &&
              BinaryFlagIsValid(ctype[1])) {
            return ThrowException(Exception::Error(String::New("Invalid byte flag.")));
          }
        }
        if (args[1]->IsNumber() && args[1]->IsNumberObject()) {
          bool is_opened = args.This()->GetInternalField(1)->IsTrue();
          if (is_opened) {
            FILE* fp = V8Init::GetInternalPtr<FILE, 0>(args.This());
            if (fp != NULL) {
              if (has_endian_flag) {
                int size = GetWriteSizeFromBinaryFlag(ctype[1]);
                int* reversed = 0;
                if (ctype[0] == '<') {
                  reversed = ByteUtils<int>::ToLittleEndian(&size);
                } else {
                  reversed = ByteUtils<int>::ToBigEndian(&size);
                }
                fwrite(reversed, 1, size, fp);
              } else {
                int size = GetWriteSizeFromBinaryFlag(ctype[0]);
                double value = args[1]->ToNumber()->Value();
                fwrite(&value, 1, size, fp);
              }
            } else {
              return ThrowException(Exception::Error(String::New("Invalid file.")));
            }
          } else {
            return ThrowException(Exception::Error(String::New("File is already closed.")));
          }
        } else {
          return ThrowException(Exception::Error(String::New("The second arguments of stat must be a integer.")));
        }
      } else {
        return ThrowException(Exception::Error(String::New("The first arguments of stat must be a string.")));
      }
    }
  }
  return ThrowException(Exception::Error(String::New("The function stat need 2 arguments.")));
}

METHOD_IMPL(NativeWrap::File::GetTextContent) {
  FILE* fp = V8Init::GetInternalPtr<FILE, 0>(args.This());
  if (fp != NULL) {
    bool is_opened = args.This()->GetInternalField(1)->IsTrue();
    if (is_opened) {
      fseek(fp, 0, SEEK_END);
      int size = ftell(fp);
      rewind(fp);
      char* contents = new char[size + 1];
      contents[size] = '\0';
      for (int i = 0; i < size;) {
        int read = fread(&contents[i], 1, size - i, fp);
        i += read;
      }
      rewind(fp);
      Handle<Value> ret = String::New(contents);
      delete []contents;
      return ret;
    } else {
      return ThrowException(Exception::Error(String::New("File is already closed.")));
    }
  } else {
    return ThrowException(Exception::Error(String::New("Invalid file.")));
  }
}


METHOD_IMPL(NativeWrap::File::FRead) {
  if (args.Length() > 0) {
    FILE* fp = V8Init::GetInternalPtr<FILE, 0>(args.This());
    if (fp != NULL) {
      bool is_opened = args.This()->GetInternalField(1)->IsTrue();
      if (args[0]->IsInt32()) {
        if (is_opened) {
          int read_size = args[0]->Int32Value();
          char* value = new char[read_size];
          int read = fread(value, 1, read_size, fp);
          if (read < read_size) {
            return Undefined();
          }
          Handle<Array> array = Array::New();
          for (int i = 0; i < read_size; i++) {
            array->Set(Integer::New(i), Number::New(static_cast<int>(value[i])));
          }
          return array;
        } else {
          return ThrowException(Exception::Error(String::New("The arguments of fread must be a Interger.")));
        }
      } else {
        return ThrowException(Exception::Error(String::New("File is already closed.")));
      }
    } else {
      return ThrowException(Exception::Error(String::New("Invalid file.")));
    }
  } else {
    return ThrowException(Exception::Error(String::New("fread need at least one arguments.")));
  }
}

METHOD_IMPL(NativeWrap::File::FClose) {
  FILE* fp = V8Init::GetInternalPtr<FILE, 0>(args.This());
  if (fp != NULL) {
    bool is_opened = args.This()->GetInternalField(1)->IsTrue();
    if (is_opened) {
      os::FClose(fp);
      args.This()->SetInternalField(1, Boolean::New(false));
    }
    return Undefined();
  } else {
    return ThrowException(Exception::Error(String::New("Invalid file.")));
  }
}

METHOD_IMPL(NativeWrap::IO::FOpen) {
  if (args.Length() == 2) {
    if (args[0]->IsString() && args[1]->IsString()) {
      String::Utf8Value path(args[0]);
      String::Utf8Value mode(args[1]);
      if (path.length() > 0) {
        os::fs::Path path_info(*path);
        os::fs::Stat stat(path_info.absolute_path());
        if (mode.length() > 0) {
          const char* mode_cstr = *mode;
          for (int i = 0, len = mode.length(); i < len; i++) {
            if (mode_cstr[i] != 'r' &&
                mode_cstr[i] != '+' &&
                mode_cstr[i] != 'w' &&
                mode_cstr[i] != 'b' &&
                mode_cstr[i] != 'a') {
              std::string buf;
              os::SPrintf(&buf, "%s is not a valid open mode.", mode_cstr);
              return ThrowException(Exception::Error(String::New(buf.c_str())));
            }
          }
          FILE *fp = os::FOpen(*path, mode_cstr);
          if (fp != NULL) {
            return File::Init(fp);
          } else {
            std::string buf;
            os::Strerror(&buf, K_ERRNO);
            return ThrowException(Exception::Error(String::New(buf.c_str())));
          }
        } else {
          return ThrowException(Exception::Error(String::New("The second arguments of fopen must be a string.")));
        }
      } else {
        return ThrowException(Exception::Error(String::New("The arguments of fopen must be a string.")));
      }
    } else {
      return ThrowException(Exception::Error(String::New("The arguments of fopen must be a string.")));
    }
  }
  return ThrowException(Exception::Error(String::New("The function fopen need at least one arguments.")));  
}

void NativeWrap::IO::NativeConsole::Init(Handle<Object> object) {
  HandleScope handle_scope;
  Handle<FunctionTemplate> print_stdout = FunctionTemplate::New(NativeWrap::IO::NativeConsole::Stdout);
  Handle<FunctionTemplate> print_stderr = FunctionTemplate::New(NativeWrap::IO::NativeConsole::StdError);
  object->Set(String::New("printStdout"), print_stdout->GetFunction());
  object->Set(String::New("printStderr"), print_stderr->GetFunction());
}

void V8Print(const Arguments& args, FILE* fp) {
  if (args.Length() == 1) {
    String::Utf8Value val(args[0]);
    if (val.length() > 0) {
      os::FPrintf(fp, "%s", *val);
    }
  }
}

METHOD_IMPL(NativeWrap::IO::NativeConsole::Stdout) {
  V8Print(args, stdout);
  return Undefined();
}

METHOD_IMPL(NativeWrap::IO::NativeConsole::StdError) {
  V8Print(args, stderr);
  return Undefined();
}


void SetCompilationOption(Handle<Object> options, CompilationInfo* info) {
  if (options->Get(String::New("compress"))->IsTrue()) {
    info->SetCompress();
  } else {
    info->UnsetCompress();
  }
  if (options->Get(String::New("debug"))->IsTrue()) {
    info->SetDebug();
  } else {
    info->UnsetDebug();
  }
  if (options->Get(String::New("prettyPrint"))->IsTrue()) {
    info->SetPrettyPrint();
  } else {
    info->UnsetPrettyPrint();
  }
  if (options->Get(String::New("fileScope"))->IsFalse()) {
    info->UnsetFileScope();
  }
  if (options->Get(String::New("globalScope"))->IsFalse()) {
    info->UnsetGlobalScope();
  }
  if (options->Has(String::New("versions"))) {
    Handle<Array> versions = Handle<Array>::Cast(options->Get(String::New("versions")));
    for (int i = 0,len = versions->Length();i < len;i++) {
      String::Utf8Value ver(versions->Get(Integer::New(i)));
      info->SetVersion(*ver);
    }
  }
  if (options->Has(String::New("disabledVersions"))) {
    Handle<Array> versions = Handle<Array>::Cast(options->Get(String::New("versions")));
    for (int i = 0,len = versions->Length();i < len;i++) {
      String::Utf8Value ver(versions->Get(Integer::New(i)));
      info->UnsetVersion(*ver);
    }
  }
  if (options->Has(String::New("moduleDir"))) {
    Handle<Array> mod_list = Handle<Array>::Cast(options->Get(String::New("moduleDir")));
    for (int i = 0,len = mod_list->Length(); i < len; i++) {
      String::Utf8Value dir(mod_list->Get(Integer::New(i)));
      os::fs::Path path_info(*dir);
      info->SetLibDirectory(path_info.directory());
    }
  }
}


METHOD_IMPL(NativeWrap::Watcher::AddSetting) {
  HandleScope handle_scope;
  if (args.Length() > 0) {
    if (args[0]->IsString()) {
      String::Utf8Value str(args[0]);
      Handle<Object> obj = (args.Length() == 2 && args[1]->IsObject())? Handle<Object>::Cast(args[1]) : Object::New();
      const char* name = *str;
      os::fs::Stat stat(name);
      if (stat.IsExist() && stat.IsReg()) {
        Handle<Value> val = args.This()->Get(String::New("_settingList"));
        Handle<Object> setting_lsit = Handle<Object>::Cast(val);
        setting_lsit->Set(String::New(name), obj);
        JavascriptObserver* observer = V8Init::GetInternalPtr<JavascriptObserver, 0>(args.This());
        FileInfoMap::UnsafeSet(name);
        FileInfo* resource = FileInfoMap::UnsafeGet(name);        
        if (obj->Has(String::New("inputCharset")) && !obj->Get(String::New("inputCharset"))->IsUndefined()) {
          String::Utf8Value icharset(obj->Get(String::New("inputCharset")));
          resource->SetInputCharset(*icharset);
        }
        if (obj->Has(String::New("outputCharset")) && !obj->Get(String::New("outputCharset"))->IsUndefined()) {
          String::Utf8Value ocharset(obj->Get(String::New("outputCharset")));
          resource->SetOutputCharset(*ocharset);
        }
        if (obj->Has(String::New("deployDir"))) {
          String::Utf8Value dep_dir(obj->Get(String::New("deployDir")));
          os::fs::Path path_info(*dep_dir);
          resource->SetDeploy(path_info.directory());
          obj->Set(String::New("deployDir"), String::New(path_info.directory()));
        }
        if (obj->Has(String::New("deployName"))) {
          String::Utf8Value dep_name(obj->Get(String::New("deployName")));
          resource->SetDeployName(*dep_name);
        }
        
        if (obj->Has(String::New("options"))) {
          Handle<Object> options = Handle<Object>::Cast(obj->Get(String::New("options")));
          CompilationInfo* info = resource->compilation_info().Get();
          SetCompilationOption(options, info);
          Handle<Array> versions;
          if (options->Has(String::New("versions"))) {
            Handle<Value> tmp = options->Get(String::New("versions"));
            versions = Handle<Array>::Cast(tmp);
          } else {
            versions = Array::New();
            options->Set(String::New("versions"), versions);
          }
          versions->Set(Integer::New(versions->Length()), String::New("all"));
          versions->Set(Integer::New(versions->Length()), String::New("none"));
        } else {
          Handle<Object> options = Object::New();
          Handle<Array> versions = Array::New();
          versions->Set(Integer::New(0), String::New("all"));
          versions->Set(Integer::New(1), String::New("none"));
          options->Set(String::New("versions"), versions);
          obj->Set(String::New("options"), options);
        }
        observer->AddFile(name);
      }
    }
  }
  return Undefined();
}

METHOD_IMPL(NativeWrap::Watcher::RemoveSetting) {
  if (args.Length() == 1) {
    if (args[0]->IsString()) {
      JavascriptObserver* observer = V8Init::GetInternalPtr<JavascriptObserver, 0>(args.This());
      String::Utf8Value str(args[0]);
      FileInfoMap::UnsafeRemove(*str);
      observer->RemoveFile(*str);
    }
  }
  return Undefined();
}

void NativeWrap::Watcher::Init(Handle<Object> object) {
  static JavascriptObserver ob;
  HandleScope handle_scope;
  Handle<v8::FunctionTemplate> fn = v8::FunctionTemplate::New();
  Handle<ObjectTemplate> inst = fn->InstanceTemplate();
  inst->SetInternalFieldCount(1);
  Handle<ObjectTemplate> proto = fn->PrototypeTemplate();
  proto->Set(String::New("run"), v8::FunctionTemplate::New(NativeWrap::Watcher::Run));
  proto->Set(String::New("exit"), v8::FunctionTemplate::New(NativeWrap::Watcher::Exit));
  proto->Set(String::New("stop"), v8::FunctionTemplate::New(NativeWrap::Watcher::Stop));
  proto->Set(String::New("resume"), v8::FunctionTemplate::New(NativeWrap::Watcher::Resume));
  proto->Set(String::New("isRunning"), v8::FunctionTemplate::New(NativeWrap::Watcher::IsRunning));
  proto->Set(String::New("addSetting"), v8::FunctionTemplate::New(NativeWrap::Watcher::AddSetting));
  proto->Set(String::New("_settingList"), V8Init::GetInstance()->REGIST_PERSISTENT(Object::New(), "SettingList"));
  proto->Set(String::New("removeSetting"), v8::FunctionTemplate::New(NativeWrap::Watcher::RemoveSetting));
  Handle<Object> instance = fn->GetFunction()->NewInstance();
  instance->SetPointerInInternalField(0, &ob);
  object->Set(String::New("watcher"), handle_scope.Close(instance));
}

DISPOSE_IMPL(NativeWrap::Watcher, JavascriptObserver);

METHOD_IMPL(NativeWrap::Watcher::Run) {
  const char* path = Setting::Get(Setting::kCompileSettingPath);
  if (path != NULL) {
    std::string source;
    os::SPrintf(&source, "mocha.import('%s');", path);
    V8Init::GetInstance()->RunInConfigContext(source.c_str());
    JavascriptObserver* observer = V8Init::GetInternalPtr<JavascriptObserver, 0>(args.This());
    observer->Run();
  } else {
    os::Printf("plese set watch file path.\n");
  }
  return Undefined();
}

METHOD_IMPL(NativeWrap::Watcher::Exit) {
  JavascriptObserver* observer = V8Init::GetInternalPtr<JavascriptObserver, 0>(args.This());
  observer->Exit();
  return Undefined();
}

METHOD_IMPL(NativeWrap::Watcher::Stop) {
  JavascriptObserver* observer = V8Init::GetInternalPtr<JavascriptObserver, 0>(args.This());
  observer->Stop();
  return Undefined();
}

METHOD_IMPL(NativeWrap::Watcher::Resume) {
  JavascriptObserver* observer = V8Init::GetInternalPtr<JavascriptObserver, 0>(args.This());
  observer->Resume();
  return Undefined();
}

METHOD_IMPL(NativeWrap::Watcher::IsRunning) {
  JavascriptObserver* observer = V8Init::GetInternalPtr<JavascriptObserver, 0>(args.This());
  return Boolean::New(observer->IsRunning());
}

void NativeWrap::Config::Init(Handle<Object> object) {
  HandleScope handle_scope;
  Handle<Object> setting = Object::New();
  Handle<FunctionTemplate> set = FunctionTemplate::New(NativeWrap::Config::Set);
  Handle<FunctionTemplate> get = FunctionTemplate::New(NativeWrap::Config::Get);
  Handle<FunctionTemplate> has = FunctionTemplate::New(NativeWrap::Config::Has);
  setting->Set(String::New("set"), set->GetFunction());
  setting->Set(String::New("get"), get->GetFunction());
  setting->Set(String::New("has"), has->GetFunction());
  setting->Set(String::New("_watchFileTemplate"), String::New(Setting::WatchFileTemplate()));
  setting->Set(String::New("_testDriverTemplate"), String::New(packed_script::test_driver));
  setting->Set(String::New("_configPath"), String::New(Setting::config_path()));
  object->Set(String::New("config"), setting);
}

METHOD_IMPL(NativeWrap::Config::Set) {
  if (args.Length() == 2) {
    if (args[0]->IsString() && args[1]->IsString()) {
      String::Utf8Value key(args[0]);
      String::Utf8Value val(args[1]);
      Setting::Set(*key, *val);
    }
  }
  return Undefined();
}

METHOD_IMPL(NativeWrap::Config::Get) {
  HandleScope handle_scope;
  if (args.Length() == 1) {
    if (args[0]->IsString()) {
      String::Utf8Value key(args[0]);
      const char* val = Setting::Get(*key);
      return val != NULL? String::New(val) : Undefined();
    }
  }
  return Undefined();
}

METHOD_IMPL(NativeWrap::Config::Has) {
  HandleScope handle_scope;
  if (args.Length() == 1) {
    if (args[0]->IsString()) {
      String::Utf8Value key(args[0]);
      return Boolean::New(Setting::Has(*key));
    }
  }
  return Boolean::New(false);
}

void NativeWrap::Compiler::Init(Handle<Object> object) {
  HandleScope handle_scope;
  Handle<v8::FunctionTemplate> compile_tmp = v8::FunctionTemplate::New(NativeWrap::Compiler::Compile);
  Handle<v8::FunctionTemplate> compile_file_tmp = v8::FunctionTemplate::New(NativeWrap::Compiler::CompileFile);
  Handle<v8::FunctionTemplate> deploy_tmp = v8::FunctionTemplate::New(NativeWrap::Compiler::Deploy);
  Handle<v8::FunctionTemplate> deps_tmp = v8::FunctionTemplate::New(NativeWrap::Compiler::CheckDepends);
  Persistent<Object> obj = V8Init::GetInstance()->REGIST_PERSISTENT(Object::New(), "Roaster");
  obj->Set(String::New("compile"), compile_tmp->GetFunction());
  obj->Set(String::New("compileFile"), compile_file_tmp->GetFunction());
  obj->Set(String::New("deploy"), deploy_tmp->GetFunction());
  obj->Set(String::New("checkDependencies"), deps_tmp->GetFunction());
  object->Set(String::New("Roaster"), obj);
}

METHOD_IMPL(NativeWrap::Compiler::Compile) {
  HandleScope handle_scope;
  if (args.Length() == 3) {
    CompilationInfo info;
    Handle<String> source = args[0]->ToString();
    Handle<String> charset = args[1]->ToString();
    Handle<Object> options = Handle<Object>::Cast(args[2]);
    String::Utf8Value source_str(source);
    String::Utf8Value charset_str(charset);
    const char* charset_cstr = (charset->IsUndefined() || charset->IsNull() || charset_str.length() == 0)?
        NULL : *charset_str;
    SetCompilationOption(options, &info);
    Roaster ro;
    CompilationResultHandle handle = ro.Compile(*source_str, charset_cstr, &info);
    return handle_scope.Close(String::New(handle->source()));
  }
  return Undefined();
}

METHOD_IMPL(NativeWrap::Compiler::CompileFile) {
  HandleScope handle_scope;
  if (args.Length() == 3) {
    CompilationInfo info;
    Handle<String> src = args[0]->ToString();
    Handle<String> charset = args[1]->ToString();
    Handle<Object> options = Handle<Object>::Cast(args[2]);
    String::Utf8Value src_str(src);
    String::Utf8Value charset_str(charset);
    const char* charset_cstr = (charset->IsUndefined() || charset->IsNull() || charset_str.length() == 0)?
        NULL : *charset_str;
    SetCompilationOption(options, &info);
    Roaster ro;
    CompilationResultHandle handle = ro.Compile(*src_str, charset_cstr, &info);
    return handle_scope.Close(String::New(handle->source()));
  }
  return Undefined();
}

METHOD_IMPL(NativeWrap::Compiler::Deploy) {
  HandleScope handle_scope;
  if (args.Length() == 3) {
    CompilationInfo info;
    Handle<String> src = args[0]->ToString();
    Handle<String> charset = args[1]->ToString();
    Handle<Object> options = Handle<Object>::Cast(args[2]);
    Handle<Object> compilation_option;
    if (options->Has(String::New("options"))) {
      compilation_option = Handle<Object>::Cast(options->Get(String::New("options")));
    } else {
      compilation_option = Object::New();
    }
    String::Utf8Value src_str(src);
    String::Utf8Value charset_str(charset);
    const char* charset_cstr = (charset->IsUndefined() || charset->IsNull() || charset_str.length() == 0)?
        NULL : *charset_str;
    SetCompilationOption(compilation_option, &info);
    Roaster ro;
    CompilationResultHandle handle = ro.CompileFile(*src_str, charset_cstr, &info);
    FileWriter writer;
    writer(handle.Get());
    return handle_scope.Close(String::New(handle->source()));
  }
  return Undefined();
}

METHOD_IMPL(NativeWrap::Compiler::CheckDepends) {
  HandleScope handle_scope;
  if (args.Length() == 1) {
    CompilationInfo info;
    Handle<String> src = args[0]->ToString();
    String::Utf8Value src_str(src);
    DepsListHandle handle = Roaster::CheckDepends(*src_str);
    DepsList::iterator it = handle->begin();
    Handle<Array> arr = Array::New();
    int i = 0;
    for (; it != handle->end(); ++it) {
      arr->Set(Integer::New(i), String::New(it->c_str()));
      i++;
    }
    return handle_scope.Close(arr);
  }
  return Undefined();
}

void NativeWrap::Repl::Init(Handle<Object> object) {
  HandleScope handle_scope;
  Handle<FunctionTemplate> fn = FunctionTemplate::New(NativeWrap::Repl::Exit);
  object->Set(String::New("exit"), handle_scope.Close(fn->GetFunction()));
}

METHOD_IMPL(NativeWrap::Repl::Exit) {
  Interaction::Exit();
  return Undefined();
}

void NativeWrap::ProcessSpawner::Init(Handle<Object> object) {
  HandleScope handle_scope;
  Persistent<Object> process = V8Init::GetInstance()->REGIST_PERSISTENT(Object::New(), "Process");
  Handle<FunctionTemplate> spawn_tmp = FunctionTemplate::New(NativeWrap::ProcessSpawner::Spawn);
  process->Set(String::New("spawn"), spawn_tmp->GetFunction());
  object->Set(String::New("process"), handle_scope.Close(process));
}

METHOD_IMPL(NativeWrap::ProcessSpawner::Spawn) {
  HandleScope handle_scope;
  if (args.Length() == 2) {
    String::Utf8Value name(args[0]->ToString());
    String::Utf8Value proc_args(args[1]->ToString());
    if (name.length() > 0) {
      const char* proc_args_str = (proc_args.length() > 0)? *proc_args : "";
      os::Process process;
      if (process.Spawn(*name, proc_args_str)) {
        return process.HasResult()? handle_scope.Close(String::New(process.result())) : handle_scope.Close(String::New(""));
      }
    }
  }
  return Undefined();
}

void NativeWrap::InternalLogger::Init(Handle<Object> object) {
  HandleScope handle_scope;
  Handle<FunctionTemplate> tmp = FunctionTemplate::New(NativeWrap::InternalLogger::Initialize);
  object->Set(String::New("initialize"), handle_scope.Close(tmp->GetFunction()));
}

METHOD_IMPL(NativeWrap::InternalLogger::Initialize) {
  const char* logpath = Setting::Get(Setting::kLogPath);
  if (logpath != NULL) {
    os::fs::Stat stat(logpath);
    if (stat.IsExist() && stat.IsReg()) {
      Logging::Initialize(logpath, "a+");
      return Undefined();
    }
  }
  Logging::Initialize(stdout);
  return Undefined();
}

}
