#ifndef mocha_file_writer_h_
#define mocha_file_writer_h_
#include <mocha/roaster/roaster.h>
namespace mocha {
class FileWriter {
 public :
  void operator()(CompilationResult* handle);
 protected :
  void WriteResult(CompilationResult* handle);
};
}

#endif
