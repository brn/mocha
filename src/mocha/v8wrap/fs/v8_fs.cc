#include <string.h>
#include <mocha/v8wrap/init.h>
#include <mocha/v8wrap/fs/v8_fs.h>
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

void V8FS::Init(Handle<Object> object) {
  printf("a");
  Handle<Object> ns_fs = Object::New();
  printf("b");
  V8FS::Directory::Init(ns_fs);
  V8FS::Path::Init(ns_fs);
  V8FS::Stat::Init(ns_fs);
  V8FS::IO::Init(ns_fs);
  object->Set(String::New("fs"), ns_fs);
}

Handle<Object> V8FS::Directory::Entry::Init(const os::fs::DirEntry* ent) {
  Handle<FunctionTemplate> fn = FunctionTemplate::New();
  fn->SetClassName(String::New("Entry"));
  Handle<ObjectTemplate> inst = fn->InstanceTemplate();
  inst->SetInternalFieldCount(1);
  Handle<ObjectTemplate> proto = fn->PrototypeTemplate();
  proto->Set(String::New("name"), FunctionTemplate::New(Name));
  proto->Set(String::New("fullpath"), FunctionTemplate::New(FullPath));
  proto->Set(String::New("path"), FunctionTemplate::New(Path));
  proto->Set(String::New("isDir"), FunctionTemplate::New(IsDir));
  proto->Set(String::New("isFile"), FunctionTemplate::New(IsFile));
  Handle<Object> instance = fn->GetFunction()->NewInstance();
  instance->SetInternalField(0, External::New(const_cast<os::fs::DirEntry*>(ent)));
  Persistent<Object> holder = Persistent<Object>::New(instance);
  holder.MakeWeak(const_cast<os::fs::DirEntry*>(ent), V8FS::Directory::Entry::Dispose);
  return instance;
}

METHOD_IMPL(V8FS::Directory::Entry::Name) {
  os::fs::DirEntry* dir = V8Init::GetInternal<os::fs::DirEntry>(args.This());
  return String::New(dir->GetName());
}

METHOD_IMPL(V8FS::Directory::Entry::FullPath) {
  os::fs::DirEntry* dir = V8Init::GetInternal<os::fs::DirEntry>(args.This());
  return String::New(dir->GetFullPath());
}

METHOD_IMPL(V8FS::Directory::Entry::Path) {
  os::fs::DirEntry* dir = V8Init::GetInternal<os::fs::DirEntry>(args.This());
  return String::New(dir->GetDirName());
}

METHOD_IMPL(V8FS::Directory::Entry::IsDir) {
  os::fs::DirEntry* dir = V8Init::GetInternal<os::fs::DirEntry>(args.This());
  return Boolean::New(dir->IsDir());
}

METHOD_IMPL(V8FS::Directory::Entry::IsFile) {
  os::fs::DirEntry* dir = V8Init::GetInternal<os::fs::DirEntry>(args.This());
  return Boolean::New(dir->IsFile());
}

DISPOSE_IMPL(V8FS::Directory::Entry, os::fs::DirEntry);


void V8FS::Directory::Init(Handle<Object> object) {
  Handle<FunctionTemplate> fn = FunctionTemplate::New(V8FS::Directory::Dir);
  fn->SetClassName(String::New("Dir"));
  Handle<ObjectTemplate> inst = fn->InstanceTemplate();
  inst->SetInternalFieldCount(1);
  Handle<ObjectTemplate> proto = fn->PrototypeTemplate();
  proto->Set(String::New("entries"), FunctionTemplate::New(V8FS::Directory::Entries));
  Handle<Function> function = fn->GetFunction();
  Handle<FunctionTemplate> mkdir_tmp = FunctionTemplate::New(V8FS::Directory::Mkdir);
  Handle<FunctionTemplate> rm_tmp = FunctionTemplate::New(V8FS::Directory::Rm);
  Handle<FunctionTemplate> chdir_tmp = FunctionTemplate::New(V8FS::Directory::Chdir);
  function->Set(String::New("mkdir"), mkdir_tmp->GetFunction());
  function->Set(String::New("rm"), rm_tmp->GetFunction());
  function->Set(String::New("chdir"), chdir_tmp->GetFunction());
  object->Set(String::New("Dir"), function);
}

METHOD_IMPL(V8FS::Directory::Dir) {
  if (args.Length() > 0) {
    if (args[0]->IsString()) {
      String::Utf8Value path(args[0]);
      os::fs::Path path_info(*path);
      os::fs::Stat stat(path_info.absolute_path());
      if (stat.IsExist() && stat.IsDir()) {
        printf("%s\n", path_info.absolute_path());
        os::fs::Directory* dir = new os::fs::Directory(path_info.absolute_path());
        Local<Object> thisObject = args.This();
        thisObject->SetInternalField(0, External::New(dir));
        Persistent<Object> holder = Persistent<Object>::New(thisObject);
        holder.MakeWeak(dir, V8FS::Directory::Dispose);
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


DISPOSE_IMPL(V8FS::Directory, os::fs::Directory);


METHOD_IMPL(V8FS::Directory::Entries) {
  if (args.Length() > 0) {
    if (args[0]->IsBoolean()) {
      bool recursive = args[0]->IsTrue();
      os::fs::Directory* dir = V8Init::GetInternal<os::fs::Directory>(args.This());
      os::fs::Directory::const_iterator it = dir->Entries(recursive);
      Handle<Array> entries = Array::New();
      int count = 0;
      for (; it != dir->end(); ++it) {
        Handle<Object> obj = V8FS::Directory::Entry::Init(&(*it));
        entries->Set(Integer::New(count), obj);
        count++;
      }
      return entries;
    }
    return ThrowException(Exception::Error(String::New("The arguments of dir.entries must be a boolean.")));
  }
  return ThrowException(Exception::Error(String::New("The function dir.entries need at least one arguments.")));
}


METHOD_IMPL(V8FS::Directory::Mkdir) {
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

METHOD_IMPL(V8FS::Directory::Chdir) {
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

METHOD_IMPL(V8FS::Directory::Rm) {
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


void V8FS::Path::Init(Handle<Object> object) {
  Handle<FunctionTemplate> fn = FunctionTemplate::New(V8FS::Path::New);
  fn->SetClassName(String::New("Path"));
  Handle<ObjectTemplate> inst = fn->InstanceTemplate();
  inst->SetInternalFieldCount(1);
  Handle<ObjectTemplate> proto = fn->PrototypeTemplate();
  proto->Set(String::New("filename"), FunctionTemplate::New(V8FS::Path::Filename));
  proto->Set(String::New("fullpath"), FunctionTemplate::New(V8FS::Path::AbsolutePath));
  proto->Set(String::New("directory"), FunctionTemplate::New(V8FS::Path::Directory));
  Handle<Function> function = fn->GetFunction();
  Handle<FunctionTemplate> getcwd_tmp = FunctionTemplate::New(V8FS::Path::Getcwd);
  Handle<FunctionTemplate> home_tmp = FunctionTemplate::New(V8FS::Path::Home);
  function->Set(String::New("getcwd"), getcwd_tmp->GetFunction());
  function->Set(String::New("homeDir"), home_tmp->GetFunction());
  object->Set(String::New("Path"), function);
}


METHOD_IMPL(V8FS::Path::New) {
  if (args.Length() > 0) {
    if (args[0]->IsString()) {
      String::Utf8Value path(args[0]);
      os::fs::Path* path_info = new os::fs::Path(*path);
      Local<Object> thisObject = args.This();
      thisObject->SetInternalField(0, External::New(path_info));
      Persistent<Object> holder = Persistent<Object>::New(thisObject);
      holder.MakeWeak(path_info, V8FS::Path::Dispose);
      return thisObject;
    } else {
      return ThrowException(Exception::Error(String::New("The arguments of path must be a string.")));
    }
  }
  return ThrowException(Exception::Error(String::New("The function path need at least one arguments.")));
}

METHOD_IMPL(V8FS::Path::Filename) {
  os::fs::Path* path_info = V8Init::GetInternal<os::fs::Path>(args.This());
  return String::New(path_info->filename());
}

METHOD_IMPL(V8FS::Path::AbsolutePath) {
  os::fs::Path* path_info = V8Init::GetInternal<os::fs::Path>(args.This());
  return String::New(path_info->absolute_path());
}

METHOD_IMPL(V8FS::Path::Directory) {
  os::fs::Path* path_info = V8Init::GetInternal<os::fs::Path>(args.This());
  return String::New(path_info->directory());
}

METHOD_IMPL(V8FS::Path::Getcwd) {
  return String::New(os::fs::Path::current_directory());
}

METHOD_IMPL(V8FS::Path::Home) {
  return String::New(os::fs::Path::home_directory());
}

DISPOSE_IMPL(V8FS::Path, os::fs::Path);

void V8FS::Stat::Init(Handle<Object> object) {
  Handle<FunctionTemplate> fn = FunctionTemplate::New(V8FS::Stat::New);
  fn->SetClassName(String::New("Stat"));
  Handle<ObjectTemplate> inst = fn->InstanceTemplate();
  inst->SetInternalFieldCount(1);
  Handle<ObjectTemplate> proto = fn->PrototypeTemplate();
  proto->Set(String::New("isDir"), FunctionTemplate::New(V8FS::Stat::IsDir));
  proto->Set(String::New("isReg"), FunctionTemplate::New(V8FS::Stat::IsReg));
  proto->Set(String::New("isChr"), FunctionTemplate::New(V8FS::Stat::IsChr));
  proto->Set(String::New("isExist"), FunctionTemplate::New(V8FS::Stat::IsExist));
  proto->Set(String::New("dev"), FunctionTemplate::New(V8FS::Stat::Dev));
  proto->Set(String::New("ino"), FunctionTemplate::New(V8FS::Stat::Ino));
  proto->Set(String::New("nlink"), FunctionTemplate::New(V8FS::Stat::NLink));
  proto->Set(String::New("uid"), FunctionTemplate::New(V8FS::Stat::UId));
  proto->Set(String::New("gid"), FunctionTemplate::New(V8FS::Stat::GId));
  proto->Set(String::New("rdev"), FunctionTemplate::New(V8FS::Stat::RDev));
  proto->Set(String::New("size"), FunctionTemplate::New(V8FS::Stat::Size));
  proto->Set(String::New("atime"), FunctionTemplate::New(V8FS::Stat::ATime));
  proto->Set(String::New("mtime"), FunctionTemplate::New(V8FS::Stat::MTime));
  proto->Set(String::New("ctime"), FunctionTemplate::New(V8FS::Stat::CTime));
  object->Set(String::New("Stat"), fn->GetFunction());
}

METHOD_IMPL(V8FS::Stat::New) {
  if (args.Length() > 0) {
    if (args[0]->IsString()) {
      String::Utf8Value path(args[0]);
      os::fs::Stat* stat = new os::fs::Stat(*path);
      Local<Object> thisObject = args.This();
      thisObject->SetInternalField(0, External::New(stat));
      Persistent<Object> holder = Persistent<Object>::New(thisObject);
      holder.MakeWeak(stat, V8FS::Stat::Dispose);
      return thisObject;
    } else {
      return ThrowException(Exception::Error(String::New("The arguments of stat must be a string.")));
    }
  }
  return ThrowException(Exception::Error(String::New("The function stat need at least one arguments.")));
}

METHOD_IMPL(V8FS::Stat::IsDir) {
  os::fs::Stat* stat = V8Init::GetInternal<os::fs::Stat>(args.This());
  return Boolean::New(stat->IsDir());
}

METHOD_IMPL(V8FS::Stat::IsChr) {
  os::fs::Stat* stat = V8Init::GetInternal<os::fs::Stat>(args.This());
  return Boolean::New(stat->IsChr());
}

METHOD_IMPL(V8FS::Stat::IsExist) {
  os::fs::Stat* stat = V8Init::GetInternal<os::fs::Stat>(args.This());
  return Boolean::New(stat->IsExist());
}

METHOD_IMPL(V8FS::Stat::Dev) {
  os::fs::Stat* stat = V8Init::GetInternal<os::fs::Stat>(args.This());
  return Integer::New(stat->Dev());
}

METHOD_IMPL(V8FS::Stat::Ino) {
  os::fs::Stat* stat = V8Init::GetInternal<os::fs::Stat>(args.This());
  return Integer::New(stat->Ino());
}

METHOD_IMPL(V8FS::Stat::NLink) {
  os::fs::Stat* stat = V8Init::GetInternal<os::fs::Stat>(args.This());
  return Integer::New(stat->NLink());
}

METHOD_IMPL(V8FS::Stat::UId) {
  os::fs::Stat* stat = V8Init::GetInternal<os::fs::Stat>(args.This());
  return Integer::New(stat->UId());
}

METHOD_IMPL(V8FS::Stat::GId) {
  os::fs::Stat* stat = V8Init::GetInternal<os::fs::Stat>(args.This());
  return Integer::New(stat->GId());
}

METHOD_IMPL(V8FS::Stat::RDev) {
  os::fs::Stat* stat = V8Init::GetInternal<os::fs::Stat>(args.This());
  return Integer::New(stat->RDev());
}

METHOD_IMPL(V8FS::Stat::Size) {
  os::fs::Stat* stat = V8Init::GetInternal<os::fs::Stat>(args.This());
  return Integer::New(stat->Size());
}

METHOD_IMPL(V8FS::Stat::ATime) {
  os::fs::Stat* stat = V8Init::GetInternal<os::fs::Stat>(args.This());
  return String::New(stat->ATime());
}

METHOD_IMPL(V8FS::Stat::MTime) {
  os::fs::Stat* stat = V8Init::GetInternal<os::fs::Stat>(args.This());
  return String::New(stat->MTime());
}

METHOD_IMPL(V8FS::Stat::CTime) {
  os::fs::Stat* stat = V8Init::GetInternal<os::fs::Stat>(args.This());
  return String::New(stat->CTime());
}

METHOD_IMPL(V8FS::Stat::IsReg) {
  os::fs::Stat* stat = V8Init::GetInternal<os::fs::Stat>(args.This());
  return Boolean::New(stat->IsReg());
}

DISPOSE_IMPL(V8FS::Stat, os::fs::Stat);


void V8FS::IO::Init(Handle<Object> object) {
  Handle<FunctionTemplate> fn = FunctionTemplate::New(V8FS::IO::FOpen);
  fn->SetClassName(String::New("fopen"));
  object->Set(String::New("fopen"), fn->GetFunction());
}


Handle<Object> V8FS::File::Init(FILE* fp) {
  Handle<FunctionTemplate> fn = FunctionTemplate::New();
  Handle<ObjectTemplate> inst = fn->InstanceTemplate();
  inst->SetInternalFieldCount(2);
  Handle<ObjectTemplate> proto = fn->PrototypeTemplate();
  proto->Set(String::New("write"), FunctionTemplate::New(FWrite));
  proto->Set(String::New("read"), FunctionTemplate::New(FRead));
  proto->Set(String::New("close"), FunctionTemplate::New(FClose));
  Handle<Object> instance = fn->GetFunction()->NewInstance();
  instance->SetInternalField(0, External::New(fp));
  instance->SetInternalField(1, Boolean::New(true));
  return instance;
}

METHOD_IMPL(V8FS::File::FWrite) {
  if (args.Length() > 0) {
    if (args[0]->IsString()) {
      String::Utf8Value str(args[0]);
      const char* content = *str;
      FILE* fp = V8Init::GetInternal<FILE>(args.This());
      fwrite(content, sizeof(char), strlen(content), fp);
    } else {
      return ThrowException(Exception::Error(String::New("The arguments of stat must be a string.")));
    }
  }
  return ThrowException(Exception::Error(String::New("The function stat need at least one arguments.")));
}

METHOD_IMPL(V8FS::File::FRead) {
  FILE* fp = V8Init::GetInternal<FILE>(args.This());
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
}

METHOD_IMPL(V8FS::File::FClose) {
  FILE* fp = V8Init::GetInternal<FILE>(args.This());
  bool is_opened = args.This()->GetInternalField(1)->IsTrue();
  if (is_opened) {
    os::FClose(fp);
    args.This()->SetInternalField(1, Boolean::New(false));
  }
  return Undefined();
}

METHOD_IMPL(V8FS::IO::FOpen) {
  if (args.Length() == 2) {
    if (args[0]->IsString() && args[1]->IsString()) {
      String::Utf8Value path(args[0]);
      String::Utf8Value permiss(args[1]);
      FILE *fp = os::FOpen(*path, *permiss);
      if (fp != NULL) {
        return File::Init(fp);
      } else {
        std::string buf;
        os::Strerror(&buf, K_ERRNO);
        return ThrowException(Exception::Error(String::New(buf.c_str())));
      }
    } else {
      return ThrowException(Exception::Error(String::New("The arguments of fopen must be a string.")));
    }
  }
  return ThrowException(Exception::Error(String::New("The function fopen need at least one arguments.")));  
}

}
