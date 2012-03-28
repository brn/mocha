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
  if (resource && resource->GetDeploy()) {
    const char* dir = resource->GetDeploy();
    os::fs::Stat stat(dir);
    if (!stat.IsExist() || !stat.IsDir()) {
      os::fs::mkdir(dir, 0777);
      os::fs::Directory::chmod(dir, 0777);
    }
    val = dir;
    val += '/';
    val += result->filename();
  } else if (!resource) {
    return;
  } else {
    val = result->fullpath();
  }
  //Get deploy path of -cmp.js file.
  SharedStr handle = resource->GetDeployName(val.c_str());
  DEBUG_LOG(Info, "write file to\n[\n%s\n]", handle.Get());
  FILE* fp = os::FOpen(handle.Get(), "w+b");
  if (fp != NULL) {
    os::fs::Directory::chmod(handle.Get(), 0777);
    const char* source = result->source();
    fwrite(source, sizeof(char), strlen(source) ,fp);
    os::FClose(fp);
  }
}

void FileWriter::operator()(CompilationResult* result) {
  WriteResult(result);
}

}
