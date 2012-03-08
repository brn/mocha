#include <mocha/misc/file_writer.h>
#include <mocha/fileinfo/fileinfo.h>
namespace mocha {

void FileWriter::WriteResult(CompilationResultHandle result){
  //Current directory -> main js file path.
  //Get file name of main js file.
  std::string val;
  FileInfo* resource = FileInfoMap::SafeGet(result->filename());
  if (resource->GetDeploy()) {
    const char* dir = resource->GetDeploy();
    filesystem::Stat stat(dir);
    if (!stat.IsExist() || !stat.IsDir()) {
      filesystem::mkdir(dir, 0777);
      filesystem::chmod(dir, 0777);
    }
    filesystem::Path path(result->filename());
    val = dir;
    val += '/';
    val += path.filename();
  } else {
    val = result->filename();
  }
  //Get deploy path of -cmp.js file.
  SharedStr handle = resource->GetDeployName(val.c_str());
  SharedPtr<filesystem::File> ret = filesystem::FileIO::Open (handle.Get(),
                                                              "rwn",
                                                              filesystem::FileIO::P_ReadWrite);
  //Setting::GetInstance()->Log("deploy to %s", handle.Get());
  if (ret->IsValidFile()) {
    //Set permission to rw for all.
    filesystem::chmod(handle.Get(), 0777);
    ret->Write(result->source());
  }
}

void FileWriter::operator()(CompilationResultHandle handle) {
  WriteResult(handle);
}

}
