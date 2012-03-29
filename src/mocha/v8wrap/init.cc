#include <mocha/v8wrap/init.h>
#include <mocha/roaster/log/logging.h>
#include <mocha/roaster/platform/fs/fs.h>
namespace mocha {
using namespace v8;

Handle<Value> LoadFile(const v8::Arguments& args) {
  HandleScope scope;
  TryCatch try_catch;
  try_catch.SetVerbose(true);
  if (args.Length() > 0) {
    if (args[0]->IsString()) {
      v8::String::Utf8Value str(args[0]);
      const char* src = *str;
      os::fs::Path path_info(src);
      os::fs::Stat stat(path_info.absolute_path());
      if (!stat.IsDir() && stat.IsExist()) {
        FILE* fp = os::FOpen(path_info.absolute_path(), "rb");
        if (fp != NULL) {
          fpos_t fsize = 0;
          fpos_t fsizeb =  fseek(fp,0,SEEK_END);
          fgetpos(fp,&fsize);
          fseek(fp,fsizeb,SEEK_SET);
          char* script = new char[fsize + 1];
          fread(script, sizeof(char), fsize, fp);
          Handle<Value> ret = String::New(script);
          delete[] script;
          return ret;
        }
      } else if (!stat.IsExist()) {
        std::string buf;
        os::SPrintf(&buf, "%s No such file.", path_info.absolute_path());
        return ThrowException(Exception::Error(String::New(buf.c_str())));
      } else if (stat.IsDir()) {
        std::string buf;
        os::SPrintf(&buf, "%s is a directory.", path_info.absolute_path());
        return ThrowException(Exception::Error(String::New(buf.c_str())));
      }
    } else {
      return ThrowException(Exception::Error(String::New("The arguments of loadFile must be a string.")));
    }
  } else {
    return ThrowException(Exception::Error(String::New("The function loadFile need at least one arguments.")));
  }
}

void V8Init::SetHelper(Handle<Object> object) {
  Local<FunctionTemplate> load_file = FunctionTemplate::New(LoadFile);
  load_file->SetClassName(String::New("loadFile"));
  object->Set(String::New("loadFile"), load_file->GetFunction());
  Local<FunctionTemplate> compile = FunctionTemplate::New(Compile);
  load_file->SetClassName(String::New("compile"));
  object->Set(String::New("compile"), compile->GetFunction());
}

V8Init::V8Init()
: global_(ObjectTemplate::New()) {
  Initialize();
}

Handle<Value> V8Init::Run(const char* source) {
  HandleScope scope;
  Context::Scope context_scope(context_);
  Handle<Value> args[] = {String::New(source)};
  return function_->Call(function_, 1, args);
}

Handle<Value> V8Init::Compile(const Arguments& args) {
  if (args.Length() > 0) {
    if (args[0]->IsString()) {
      v8::String::Utf8Value str(args[0]);
      const char* src = *str;
      if (args.Length() > 1) {
        if (args[1]->IsString()) {
          v8::String::Utf8Value name_val(args[1]);
          const char* name = *name_val;
          return DoRun(src, name);
        }
      } else {
        return DoRun(src);
      }
    }
  }
  return Undefined();
}

const char* ToCString(const String::Utf8Value& value) {
  return *value;
}

Handle<Value> V8Init::DoRun(const char* src, const char* name) {
  Handle<String> source = String::New(src);
  Handle<Value> exception;
  Handle<Value> val;
  v8::TryCatch try_catch;
  {
    Handle<Script> script = (name == NULL)? Script::Compile(source) : Script::Compile(source, String::New(name));
    if (script.IsEmpty()) {
      exception = Local<Value>::New(try_catch.Exception());
    } else {
      val = script->Run();
      if (val.IsEmpty()) {
        exception = Local<Value>::New(try_catch.Exception());
      }
    }
  }
  if (!exception.IsEmpty()) {
    Handle<Message> message = try_catch.Message();
    v8::String::Utf8Value exception(try_catch.Exception());
    const char* exception_string = ToCString(exception);
    if (message.IsEmpty()) {
      os::Printf("%s\n", exception_string);
    } else {
      String::Utf8Value filename(message->GetScriptResourceName());
      const char* filename_string = ToCString(filename);
      int linenum = message->GetLineNumber();
      os::Printf("%s:%i: %s\n", filename_string, linenum, exception_string);
      // Print line of source code.
      String::Utf8Value sourceline(message->GetSourceLine());
      const char* sourceline_string = ToCString(sourceline);
      os::Printf("%s\n", sourceline_string);
      // Print wavy underline (GetUnderline is deprecated).
      int start = message->GetStartColumn();
      for (int i = 0; i < start; i++) {
        os::Printf(" ");
      }
      int end = message->GetEndColumn();
      for (int i = start; i < end; i++) {
        os::Printf("^");
      }
      os::Printf("\n");
      String::Utf8Value stack_trace(try_catch.StackTrace());
      if (stack_trace.length() > 0) {
        const char* stack_trace_string = ToCString(stack_trace);
        os::Printf("%s\n", stack_trace_string);
      }
    }
    return Undefined();
  } else {
    return val;
  }
}

Handle<Value> Print(const v8::Arguments& args) {
  if (args.Length() > 0) {
    for (int i = 0; i < args.Length(); i++) {
      v8::String::Utf8Value str(args[i]->ToString());
      os::Printf("%s\n", *str);
    }
  }
  return Undefined();
}

void V8Init::Initialize() {
  Local<FunctionTemplate> fn_tmpl = FunctionTemplate::New(Print);
  fn_tmpl->SetClassName(String::New("print"));
  global_->Set(String::New("print"), fn_tmpl);
  context_ = Context::New(NULL, global_);
  Context::Scope context_scope(context_);
  std::string wrap = "(function(env, cwd){"
      "var loadFile = env.loadFile;"
      "var guard = {};"
      "var current_dir = cwd;"
      "var getcwd = function () {return current_dir};"
      "var include = function (path) {"
      "if (!(path in guard)) {"
      "env.exports[path] = {};"
      "var source = loadFile(path);"
      "source = '(function(include, loadFile, exports) {' + source + '})';"
      "env.compile(source, path)(include, loadFile, env.exports[path]);"
      "guard[path] = env.exports[path];"
      "return env.exports[path];"
      "};"
      "return guard[path];"
      "};"
      "return function (source) {"
      "source = '(function(include, loadFile, exports) {' + source + '})';"
      "return env.compile(source)(include, loadFile, env.exports);"
      "};"
      "});";
  Handle<Value> fn = DoRun(wrap.c_str());
  Handle<Function> callable = Handle<Function>::Cast(fn);
  Handle<Object> object = Object::New();
  exports_ = Object::New();
  object->Set(String::New("exports"), exports_);
  SetHelper(object);
  Handle<Value> args[] = {object, exports_, String::New(os::fs::Path::current_directory())};
  Handle<Value> ret = callable->Call(callable, 2, args);
  function_ = Handle<Function>::Cast(ret);
}

}
