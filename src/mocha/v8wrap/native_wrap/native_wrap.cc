#include <string.h>
#include <mocha/v8wrap/init.h>
#include <mocha/v8wrap/native_wrap/native_wrap.h>
#include <mocha/roaster/ast/seriarization/byte.h>
#include <mocha/fileinfo/fileinfo.h>
#include <mocha/options/setting.h>
#include <mocha/xml/xml_setting_info.h>
#include <mocha/misc/file_watcher/observer/xml_observer.h>
#include <mocha/roaster/platform/fs/fs.h>
using namespace v8;
namespace mocha {
#define METHOD_IMPL(name) Handle<Value> name(const Arguments& args)

#define DISPOSE_IMPL(name,type)                                 \
  void name::Dispose(Persistent<Value> handle, void* ptr) {     \
    type* entity = static_cast<type*>(ptr);                     \
    delete entity;                                              \
    handle.Dispose();                                           \
  }

void NativeWrap::Init(Handle<Object> object) {
  Handle<Object> ns_fs = Object::New();
  Handle<Object> ns_io = Object::New();
  Handle<Object> ns_console = Object::New();
  Handle<Object> ns_setting = Object::New();
  NativeWrap::Directory::Init(ns_fs);
  NativeWrap::Path::Init(ns_fs);
  NativeWrap::Stat::Init(ns_fs);
  NativeWrap::IO::Init(ns_io);
  NativeWrap::IO::NativeConsole::Init(ns_console);
  ns_io->Set(String::New("nativeConsole"), ns_console);
  NativeWrap::Setting::Init(ns_setting);
  NativeWrap::Watcher::Init(ns_setting);
  object->Set(String::New("fs"), ns_fs);
  object->Set(String::New("scriptUtils"), ns_setting);
  object->Set(String::New("io"), ns_io);
  object->Set(String::New("invalid"), Object::New());
  object->Set(String::New("exitStatus"), Object::New());
}

Handle<Object> NativeWrap::Directory::Entry::Init(const os::fs::DirEntry* ent) {
  Handle<v8::FunctionTemplate> fn = v8::FunctionTemplate::New();
  fn->SetClassName(String::New("Entry"));
  Handle<ObjectTemplate> inst = fn->InstanceTemplate();
  inst->SetInternalFieldCount(1);
  Handle<ObjectTemplate> proto = fn->PrototypeTemplate();
  proto->Set(String::New("name"), v8::FunctionTemplate::New(Name));
  proto->Set(String::New("fullpath"), v8::FunctionTemplate::New(FullPath));
  proto->Set(String::New("path"), v8::FunctionTemplate::New(Path));
  proto->Set(String::New("isDir"), v8::FunctionTemplate::New(IsDir));
  proto->Set(String::New("isFile"), v8::FunctionTemplate::New(IsFile));
  Handle<Object> instance = fn->GetFunction()->NewInstance();
  instance->SetInternalField(0, External::New(const_cast<os::fs::DirEntry*>(ent)));
  Persistent<Object> holder = Persistent<Object>::New(instance);
  holder.MakeWeak(const_cast<os::fs::DirEntry*>(ent), NativeWrap::Directory::Entry::Dispose);
  return instance;
}

METHOD_IMPL(NativeWrap::Directory::Entry::Name) {
  os::fs::DirEntry* dir = V8Init::GetInternal<os::fs::DirEntry>(args.This());
  return String::New(dir->GetName());
}

METHOD_IMPL(NativeWrap::Directory::Entry::FullPath) {
  os::fs::DirEntry* dir = V8Init::GetInternal<os::fs::DirEntry>(args.This());
  return String::New(dir->GetFullPath());
}

METHOD_IMPL(NativeWrap::Directory::Entry::Path) {
  os::fs::DirEntry* dir = V8Init::GetInternal<os::fs::DirEntry>(args.This());
  return String::New(dir->GetDirName());
}

METHOD_IMPL(NativeWrap::Directory::Entry::IsDir) {
  os::fs::DirEntry* dir = V8Init::GetInternal<os::fs::DirEntry>(args.This());
  return Boolean::New(dir->IsDir());
}

METHOD_IMPL(NativeWrap::Directory::Entry::IsFile) {
  os::fs::DirEntry* dir = V8Init::GetInternal<os::fs::DirEntry>(args.This());
  return Boolean::New(dir->IsFile());
}

DISPOSE_IMPL(NativeWrap::Directory::Entry, os::fs::DirEntry);


void NativeWrap::Directory::Init(Handle<Object> object) {
  HandleScope handle_scope;
  Handle<v8::FunctionTemplate> fn = v8::FunctionTemplate::New(NativeWrap::Directory::Dir);
  fn->SetClassName(String::New("Dir"));
  Handle<ObjectTemplate> inst = fn->InstanceTemplate();
  inst->SetInternalFieldCount(1);
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
  if (args.IsConstructCall()) {
    if (args.Length() > 0) {
      if (args[0]->IsString()) {
        String::Utf8Value path(args[0]);
        os::fs::Path path_info(*path);
        os::fs::Stat stat(path_info.absolute_path());
        if (stat.IsExist() && stat.IsDir()) {
          os::fs::Directory* dir = new os::fs::Directory(path_info.absolute_path());
          Local<Object> thisObject = args.This();
          thisObject->SetInternalField(0, External::New(dir));
          Persistent<Object> holder = Persistent<Object>::New(thisObject);
          holder.MakeWeak(dir, NativeWrap::Directory::Dispose);
          return thisObject;
        } else if (!stat.IsExist()){
          std::string buf;
          os::SPrintf(&buf, "%s No such directory.");
          return ThrowException(Exception::Error(String::New(buf.c_str())));
        } else if (!stat.IsDir()) {
          std::string buf;
          os::SPrintf(&buf, "%s Not a directory.");
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
      os::fs::Directory* dir = V8Init::GetInternal<os::fs::Directory>(args.This());
      os::fs::Directory::const_iterator it = dir->Entries(recursive);
      Handle<Array> entries = Array::New();
      int count = 0;
      for (; it != dir->end(); ++it) {
        Handle<Object> obj = NativeWrap::Directory::Entry::Init(&(*it));
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
  object->Set(String::New("Path"), function);
}


METHOD_IMPL(NativeWrap::Path::New) {
  if (args.Length() > 0) {
    if (args[0]->IsString()) {
      String::Utf8Value path(args[0]);
      os::fs::Path* path_info = new os::fs::Path(*path);
      Local<Object> thisObject = args.This();
      thisObject->SetInternalField(0, External::New(path_info));
      Persistent<Object> holder = Persistent<Object>::New(thisObject);
      holder.MakeWeak(path_info, NativeWrap::Path::Dispose);
      return thisObject;
    } else {
      return ThrowException(Exception::Error(String::New("The arguments of path must be a string.")));
    }
  }
  return ThrowException(Exception::Error(String::New("The function path need at least one arguments.")));
}

METHOD_IMPL(NativeWrap::Path::Filename) {
  os::fs::Path* path_info = V8Init::GetInternal<os::fs::Path>(args.This());
  return String::New(path_info->filename());
}

METHOD_IMPL(NativeWrap::Path::AbsolutePath) {
  os::fs::Path* path_info = V8Init::GetInternal<os::fs::Path>(args.This());
  return String::New(path_info->absolute_path());
}

METHOD_IMPL(NativeWrap::Path::Directory) {
  os::fs::Path* path_info = V8Init::GetInternal<os::fs::Path>(args.This());
  return String::New(path_info->directory());
}

METHOD_IMPL(NativeWrap::Path::Getcwd) {
  return String::New(os::fs::Path::current_directory());
}

METHOD_IMPL(NativeWrap::Path::Home) {
  return String::New(os::fs::Path::home_directory());
}

DISPOSE_IMPL(NativeWrap::Path, os::fs::Path);

void NativeWrap::Stat::Init(Handle<Object> object) {
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
  object->Set(String::New("Stat"), function);
}

METHOD_IMPL(NativeWrap::Stat::New) {
  if (args.Length() > 0) {
    if (args[0]->IsString()) {
      String::Utf8Value path(args[0]);
      os::fs::Stat* stat = new os::fs::Stat(*path);
      Local<Object> thisObject = args.This();
      thisObject->SetInternalField(0, External::New(stat));
      Persistent<Object> holder = Persistent<Object>::New(thisObject);
      holder.MakeWeak(stat, NativeWrap::Stat::Dispose);
      return thisObject;
    } else {
      return ThrowException(Exception::Error(String::New("The arguments of stat must be a string.")));
    }
  }
  return ThrowException(Exception::Error(String::New("The function stat need at least one arguments.")));
}

METHOD_IMPL(NativeWrap::Stat::IsDir) {
  os::fs::Stat* stat = V8Init::GetInternal<os::fs::Stat>(args.This());
  return Boolean::New(stat->IsDir());
}

METHOD_IMPL(NativeWrap::Stat::IsChr) {
  os::fs::Stat* stat = V8Init::GetInternal<os::fs::Stat>(args.This());
  return Boolean::New(stat->IsChr());
}

METHOD_IMPL(NativeWrap::Stat::IsExist) {
  os::fs::Stat* stat = V8Init::GetInternal<os::fs::Stat>(args.This());
  return Boolean::New(stat->IsExist());
}

METHOD_IMPL(NativeWrap::Stat::Dev) {
  os::fs::Stat* stat = V8Init::GetInternal<os::fs::Stat>(args.This());
  return Integer::New(stat->Dev());
}

METHOD_IMPL(NativeWrap::Stat::Ino) {
  os::fs::Stat* stat = V8Init::GetInternal<os::fs::Stat>(args.This());
  return Integer::New(stat->Ino());
}

METHOD_IMPL(NativeWrap::Stat::NLink) {
  os::fs::Stat* stat = V8Init::GetInternal<os::fs::Stat>(args.This());
  return Integer::New(stat->NLink());
}

METHOD_IMPL(NativeWrap::Stat::UId) {
  os::fs::Stat* stat = V8Init::GetInternal<os::fs::Stat>(args.This());
  return Integer::New(stat->UId());
}

METHOD_IMPL(NativeWrap::Stat::GId) {
  os::fs::Stat* stat = V8Init::GetInternal<os::fs::Stat>(args.This());
  return Integer::New(stat->GId());
}

METHOD_IMPL(NativeWrap::Stat::RDev) {
  os::fs::Stat* stat = V8Init::GetInternal<os::fs::Stat>(args.This());
  return Integer::New(stat->RDev());
}

METHOD_IMPL(NativeWrap::Stat::Size) {
  os::fs::Stat* stat = V8Init::GetInternal<os::fs::Stat>(args.This());
  return Integer::New(stat->Size());
}

METHOD_IMPL(NativeWrap::Stat::ATime) {
  os::fs::Stat* stat = V8Init::GetInternal<os::fs::Stat>(args.This());
  return String::New(stat->ATime());
}

METHOD_IMPL(NativeWrap::Stat::MTime) {
  os::fs::Stat* stat = V8Init::GetInternal<os::fs::Stat>(args.This());
  return String::New(stat->MTime());
}

METHOD_IMPL(NativeWrap::Stat::CTime) {
  os::fs::Stat* stat = V8Init::GetInternal<os::fs::Stat>(args.This());
  return String::New(stat->CTime());
}

METHOD_IMPL(NativeWrap::Stat::IsReg) {
  os::fs::Stat* stat = V8Init::GetInternal<os::fs::Stat>(args.This());
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
  Handle<FunctionTemplate> fn = FunctionTemplate::New(NativeWrap::IO::FOpen);
  fn->SetClassName(String::New("fopen"));
  object->Set(String::New("fopen"), fn->GetFunction());
}


Handle<Object> NativeWrap::File::Init(FILE* fp) {
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
  instance->SetInternalField(0, External::New(fp));
  instance->SetInternalField(1, Boolean::New(true));
  return instance;
}

METHOD_IMPL(NativeWrap::File::WriteTextContent) {
  if (args.Length() > 0) {
    if (args[0]->IsString()) {
      bool is_opened = args.This()->GetInternalField(1)->IsTrue();
      if (is_opened) {
        String::Utf8Value str(args[0]);
        const char* content = *str;
        FILE* fp = V8Init::GetInternal<FILE>(args.This());
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
  }
  return ThrowException(Exception::Error(String::New("The function stat need at least one arguments.")));
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
            FILE* fp = V8Init::GetInternal<FILE>(args.This());
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
  FILE* fp = V8Init::GetInternal<FILE>(args.This());
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
    FILE* fp = V8Init::GetInternal<FILE>(args.This());
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
  FILE* fp = V8Init::GetInternal<FILE>(args.This());
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
        if (stat.IsExist() && stat.IsReg()) {
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
        } else if (!stat.IsExist()){
          std::string buf;
          os::SPrintf(&buf, "%s No such file.");
          return ThrowException(Exception::Error(String::New(buf.c_str())));
        } else if (stat.IsDir()) {
          std::string buf;
          os::SPrintf(&buf, "%s is a directory.");
          return ThrowException(Exception::Error(String::New(buf.c_str())));
        } else if (!stat.IsReg()) {
          std::string buf;
          os::SPrintf(&buf, "%s is not a valid file.");
          return ThrowException(Exception::Error(String::New(buf.c_str())));
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

void NativeWrap::Setting::Init(Handle<Object> object) {
  HandleScope handle_scope;
  Handle<v8::FunctionTemplate> fn = v8::FunctionTemplate::New();
  Handle<ObjectTemplate> proto = fn->PrototypeTemplate();
  proto->Set(String::New("addSetting"), v8::FunctionTemplate::New(NativeWrap::Setting::AddSetting));
  proto->Set(String::New("removeSetting"), v8::FunctionTemplate::New(NativeWrap::Setting::RemoveSetting));
  object->Set(String::New("__settings"), handle_scope.Close(fn->GetFunction()->NewInstance()));
}


METHOD_IMPL(NativeWrap::Setting::AddSetting) {
  if (args.Length() == 2) {
    if (args[0]->IsString() && args[1]->IsObject()) {
      String::Utf8Value str(args[0]);
      Handle<Object> obj = Handle<Object>::Cast(args[1]);
      const char* name = *str;
      os::fs::Stat stat(name);
      if (stat.IsExist() && stat.IsReg()) {
        FileInfoMap::UnsafeSet(name);
        FileInfo* resource = FileInfoMap::UnsafeGet(name);
        String::Utf8Value icharset(obj->Get(String::New("inputCharset")));
        String::Utf8Value ocharset(obj->Get(String::New("outputCharset")));
        String::Utf8Value dep_dir(obj->Get(String::New("deployDir")));
        String::Utf8Value dep_name(obj->Get(String::New("deployName")));
        Handle<Array> mod_list = Handle<Array>::Cast(obj->Get(String::New("moduleDir")));
        Handle<Object> options = Handle<Object>::Cast(obj->Get(String::New("options")));
        resource->SetInputCharset(*icharset);
        resource->SetOutputCharset(*ocharset);
        resource->SetDeploy(*dep_dir);
        resource->SetDeployName(*dep_name);
        for (int i = 0,len = mod_list->Length(); i < len; i++) {
          String::Utf8Value dir(mod_list->Get(Integer::New(i)));
          resource->SetModule(*dir);
        }
        CompilationInfo* info = resource->compilation_info().Get();
        if (options->Get(String::New("compress"))->IsTrue()) {
          info->SetCompress();
        }
        if (options->Get(String::New("debug"))->IsTrue()) {
          info->SetDebug();
        }
        if (options->Get(String::New("prettyPrint"))->IsTrue()) {
          info->SetPrettyPrint();
        }
        Handle<Array> versions = Handle<Array>::Cast(options->Get(String::New("versions")));
        for (int i = 0,len = versions->Length();i < len;i++) {
          String::Utf8Value ver(versions->Get(Integer::New(i)));
          info->SetVersion(*ver);
        }
        XMLSettingInfo::set_file_list(name);
      }
    }
  }
  return Undefined();
}

METHOD_IMPL(NativeWrap::Setting::RemoveSetting) {
  if (args.Length() == 1) {
    if (args[0]->IsString()) {
      String::Utf8Value str(args[0]);
      FileInfoMap::UnsafeRemove(*str);
    }
  }
  return Undefined();
}

void NativeWrap::Watcher::Init(Handle<Object> object) {
  HandleScope handle_scope;
  static XMLObserver ob;
  Handle<v8::FunctionTemplate> fn = v8::FunctionTemplate::New();
  Handle<ObjectTemplate> inst = fn->InstanceTemplate();
  inst->SetInternalFieldCount(1);
  Handle<ObjectTemplate> proto = fn->PrototypeTemplate();
  proto->Set(String::New("run"), v8::FunctionTemplate::New(NativeWrap::Watcher::Run));
  proto->Set(String::New("addConfig"), v8::FunctionTemplate::New(NativeWrap::Watcher::AddConfig));
  proto->Set(String::New("exit"), v8::FunctionTemplate::New(NativeWrap::Watcher::Exit));
  proto->Set(String::New("isEnd"), v8::FunctionTemplate::New(NativeWrap::Watcher::IsEnd));
  Handle<Object> instance = fn->GetFunction()->NewInstance();
  instance->SetInternalField(0, External::New(&ob));
  object->Set(String::New("watcher"), handle_scope.Close(instance));
  
}

DISPOSE_IMPL(NativeWrap::Watcher, XMLObserver);

METHOD_IMPL(NativeWrap::Watcher::Run) {
  XMLObserver* observer = V8Init::GetInternal<XMLObserver>(args.This());
  observer->Run();
  return Undefined();
}

METHOD_IMPL(NativeWrap::Watcher::AddConfig) {
  if (args.Length() == 1) {
    if (args[0]->IsString()) {
      String::Utf8Value str(args[0]);
      XMLSettingInfo::set_include_list(*str);
    }
  }
  return Undefined();
}

METHOD_IMPL(NativeWrap::Watcher::Exit) {
  XMLObserver* observer = V8Init::GetInternal<XMLObserver>(args.This());
  observer->Exit();
  return Integer::New(1);
}

METHOD_IMPL(NativeWrap::Watcher::IsEnd) {
  XMLObserver* observer = V8Init::GetInternal<XMLObserver>(args.This());
  return Boolean::New(observer->IsEnd());
}

}
