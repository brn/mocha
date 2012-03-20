/**
 *@author Taketoshi Aono
 *@fileOverview
 *@license
 *Copyright (c) 2011 Taketoshi Aono
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

#include <mocha/roaster/ast/node_manip/node_manip.h>

namespace mocha {
void TransformEventLitener::operator()(CompilationEvent* e) {
  ErrorReporter* reporter = e->error_reporter();
  bool runtime = e->runtime();
  ScopeRegistry* registry = e->scope_registry();
  const char* mainfile_path = e->mainfile_path();
  const char* target_filename = e->filename();
  if (!reporter->Error()) {
    AstTransformer visitor (runtime, registry, compiler_, mainfile_path, target_filename);
    AstRoot tmp_root;
    tmp_root.AddChild(root);
    tmp_root.Accept (&visitor);
    e->set_ast(tmp_root.first_child());
    e->notificator()->NotifyForKey(CompilationEvent::EventKey::kCompileSuccess, e);
  } else {
    std::string buf;
    reporter->SetError(&buf);
    e->ast(new(e->pool()) Empty);
    e->notificator()->NotifyForKey(CompilationEvent::EventKey::kParseError, e);
  }
}
}
