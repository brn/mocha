#include <string.h>
#include <mocha/roaster/platform/fs/event/md5.h>
#include <mocha/roaster/platform/fs/stat/stat.h>
#include <mocha/roaster/platform/fs/event/event.h>
#include <mocha/roaster/smart_pointer/scope/scoped_ptr.h>
#include <mocha/roaster/platform/utils/utils.h>
namespace mocha {namespace os {
namespace fs {

void ReadFile(std::string* buf, const char* path) {
  FILE* fp = FOpen(path, "rb");
  if (fp != NULL) {
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    rewind(fp);
    ScopedStr contents_handle(new char[size + 1]);
    char* contents = const_cast<char*>(contents_handle.Get());
    contents[size] = '\0';
    for (int i = 0; i < size;) {
      int read = fread(&contents[i], 1, size - i, fp);
      i += read;
    }
    fclose(fp);
    buf->assign(contents);
  } else {
    buf->assign("");
  }
}

FSEvent::FSEvent(const char* path, FSWatcher* fs_watcher)
    : path_(path),
      fs_watcher_(fs_watcher){
  Stat stat(path);
  std::string buf;
  ReadFile(&buf, path_.c_str());
  MD5 md5(buf.c_str());
  md5_ = md5.hexdigest();
  mtime_ = stat.MTime();
}

FSEvent::~FSEvent(){}

bool FSEvent::IsModified() {
  Stat stat(path_.c_str());
  if (stat.IsExist()) {
    std::string buf;
    ReadFile(&buf, path_.c_str());
    MD5 md5(buf.c_str());
    bool ret = md5_ == md5.hexdigest();
    if (!ret) {
      md5_ = md5.hexdigest();
    }
    return !ret;
  }
  return false;
}

bool FSEvent::IsUpdate() {
  Stat stat(path_.c_str());
  if (stat.IsExist()) {
    std::string mtime = stat.MTime();
    bool ret = mtime_ == mtime;
    if (!ret) {
      mtime_ = mtime;
    }
    return !ret;
  }
  return false;
}

bool FSEvent::IsExist() const {
  Stat stat(path_.c_str());
  return stat.IsExist();
}

const char* FSEvent::filename() const {return path_.c_str();}
const char* FSEvent::md5() const {return md5_.c_str();}
}}}
