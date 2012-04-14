/**
 *@author Taketoshi Aono
 *@fileOverview
 *@license
 *Copyright (c) 2011 Taketoshi Aono
 *Licensed under the BSD.
 *
 *Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
 *associated doc umentation files (the "Software"), to deal in the Software without restriction,
 *including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 *subject to the following conditions:
 *
 *The above copyright notice and this permission notice shall be included in all copies or
 *substantial portions ofthe Software.
 *
 *THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 *TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 *THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 *CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *DEALINGS IN THE SOFTWARE.
 */
#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/ast/translator/translator_data/translator_data.h>
#include <mocha/roaster/ast/translator/processors/dsta_processor.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/roaster/platform/fs/fs.h>

namespace mocha {

void CreateRelativePath(const char* base, const char* target, std::string *buffer) {
  os::fs::Path base_path_info(base);
  os::fs::Path target_path_info(target);
  std::string relative_path;
  os::fs::Path::relative_path(base_path_info.directory(), target_path_info.directory(), &relative_path);
  buffer->assign("'");
  buffer->append(relative_path.c_str());
  buffer->append(target_path_info.filename());
  buffer->append("'");
}

TranslatorData::TranslatorData(bool is_runtime, CompilationEvent *event, DstaExtractedExpressions* dsta_exp) :
    tmp_index_(0),
    object_depth_(0),
    is_in_class_(0),
    is_in_module_(0),
    dsta_exp_(dsta_exp),
    event_(event),
    current_stmt_(0),
    current_fn_(0),
    file_root_(0),
    builder_(AstBuilder::Local()){
  if (is_runtime){
    bit_vector_.Set(2);
  }
  CreateRelativePath(event->filename(), event->mainfile_path(), &relative_path_);
};

}
