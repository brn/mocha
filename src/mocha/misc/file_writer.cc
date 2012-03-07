#include <mocha/misc/file_writer.h>
#include <mocha/roaster/external/external_resource.h>
namespace mocha {

void FileWriter::WriteResult(CompilationResultHandle result){
  //Current directory -> main js file path.
  //Get file name of main js file.
  std::string val;
  Resource* resource = ExternalResource::SafeGet(result->filename());
  if (resource->GetDeploy()) {
    const char* dir = resource->GetDeploy();
    fprintf(stderr,"%s\n",dir);
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
  fprintf(stderr,"%s\n",handle.Get());
  SharedPtr<filesystem::File> ret = filesystem::FileIO::Open (handle.Get(),
                                                              "rwn",
                                                              filesystem::FileIO::P_ReadWrite);
  //Setting::GetInstance()->Log("deploy to %s", handle.Get());
  //Set permission to rw for all.
  filesystem::chmod(handle.Get(), 0777);
  ret->Write(result->source());
}

void FileWriter::operator()(CompilationResultHandle handle) {
  WriteResult(handle);
}

}
