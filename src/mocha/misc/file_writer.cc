#include <string.h>
#include <mocha/misc/file_writer.h>
#include <mocha/fileinfo/fileinfo.h>
#include <mocha/roaster/nexl/compilation_result/compilation_result.h>
namespace mocha {

void FileWriter::WriteResult(CompilationResult* result){
  //Current directory -> main js file path.
  //Get file name of main js file.
  std::string val;
  FileInfo* resource = FileInfoMap::SafeGet(result->fullpath());
  if (resource) {
    const char* deploydir = resource->GetDeploy();
    const char* deployname = resource->GetDeployName();
    if (!deploydir && !deployname) {
      std::string name = result->filename();
      name.erase(name.find('.'), name.size());
      os::SPrintf(&val, "%s/%s-cmp.js", result->dir(), name.c_str());
    } else if (deploydir) {
      std::string name = result->filename();
      name.erase(name.find('.'), name.size());
      os::SPrintf(&val, "%s/%s-cmp.js", deploydir, name.c_str());
    } else if (deployname) {
      os::SPrintf(&val, "%s/%s", result->dir(), deployname);
    }

    const char* dir = ((deploydir)?deploydir : result->dir());
    os::fs::Stat stat(dir);
    if (!stat.IsExist()) {
      os::fs::mkdir(dir, 0777);
      os::fs::Directory::chmod(dir, 0777);
    }
    DEBUG_LOG(Info, "write file to\n[\n%s\n]", val.c_str());
    FILE* fp = os::FOpen(val.c_str(), "w+b");
    if (fp != NULL) {
      os::fs::Directory::chmod(val.c_str(), 0777);
      const char* source = result->source();
      fwrite(source, sizeof(char), strlen(source) ,fp);
      os::FClose(fp);
    }
  }
}

void FileWriter::operator()(CompilationResult* result) {
  WriteResult(result);
}

}
