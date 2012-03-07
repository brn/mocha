#ifndef mocha_file_writer_h_
#define mocha_file_writer_h_
#include <mocha/roaster/roaster.h>
namespace mocha {
class FileWriter : public AsyncCallback {
 public :
  void operator()(CompilationResultHandle handle);
 protected :
  void WriteResult(CompilationResultHandle handle);
};
}

#endif
