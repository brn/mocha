#include <mocha/misc/file_writer.h>
#include <mocha/fileinfo/fileinfo.h>
namespace mocha {

void FileWriter::WriteResult(CompilationResultHandle result){
  //Current directory -> main js file path.
  //Get file name of main js file.
  std::string val;
    printf("%s\n" , result->filename());
  FileInfo* resource = FileInfoMap::SafeGet(result->filename());
  if (resource && resource->GetDeploy()) {
    const char* dir = resource->GetDeploy();
    os::fs::Stat stat(dir);
    if (!stat.IsExist() || !stat.IsDir()) {
      os::fs::mkdir(dir, 0777);
      os::fs::chmod(dir, 0777);
    }
    os::fs::Path path(result->filename());
    val = dir;
    val += '/';
    val += path.filename();
  } else if (!resource) {
    return;
  } else {
    val = result->filename();
  }
  //Get deploy path of -cmp.js file.
  SharedStr handle = resource->GetDeployName(val.c_str());
  SharedPtr<os::fs::File> ret = os::fs::FileIO::Open (handle.Get(),
                                                              "rwn",
                                                              os::fs::FileIO::P_ReadWrite);
  //Setting::GetInstance()->Log("deploy to %s", handle.Get());
  if (ret->IsValidFile()) {
    //Set permission to rw for all.
    os::fs::chmod(handle.Get(), 0777);
    ret->Write(result->source());
  }
}

void FileWriter::operator()(CompilationResultHandle handle) {
  WriteResult(handle);
}

}
