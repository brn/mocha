#include <stdio.h>
#include <mocha/v8wrap/init.h>
#include <mocha/v8wrap/initjs.h>
#include <mocha/roaster/log/logging.h>
#include <mocha/roaster/platform/fs/fs.h>
#include <mocha/v8wrap/native_wrap/native_wrap.h>
using namespace v8;
namespace mocha {

V8Init* V8Init::GetInstance() {
  int ret = Atomic::CompareAndSwap(&atomic_, 0 , 1);
  if (ret == 0) {
    atomic_ = 1;
    instance_(new V8Init);
  }
  return instance_.Get();
}

AtomicWord V8Init::atomic_ = 0;
ScopedPtr<V8Init> V8Init::instance_;

V8Init::V8Init() {
  Initialize();
}

V8Init::~V8Init() {
  config_global_template_.Dispose();
  config_global_.Dispose();
  context_.Dispose();
  function_.Dispose();
  compile_.Dispose();
  native_.Dispose();
}

void V8Init::Print(Handle<Value> value) {
  if (!value.IsEmpty() && !value->IsUndefined()) {
    String::Utf8Value str(value);
    os::Printf("%s\n", *str);
  } else if (value->IsUndefined()) {
    os::Printf("undefined\n");
  }
}


Handle<Value> V8Init::RunInConfigContext(const char* source) {
  HandleScope scope;
  context_->Enter();
  Context::Scope context_scope(context_);
  Handle<Value> args[] = {String::New(source)};
  Handle<Value> ret = function_->Call(function_, 1, args);
  context_->Exit();
  return ret;
}

Handle<Value> V8Init::RunInGlobalContext(const char* source) {
  context_->Enter();
  Handle<Value> ret = DoRun(source);
  context_->Exit();
  return ret;
}

bool V8Init::IsInvalidValue(Handle<Value> value) {
  return value->StrictEquals(native_->Get(String::New("invalidValue")));
}

bool V8Init::IsExitStatus(Handle<Value> value) {
  return value->StrictEquals(native_->Get(String::New("exitStatus")));
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


void V8Init::HandleException(TryCatch* try_catch) {
  HandleScope handle_scope;
  Handle<Message> message = try_catch->Message();
  String::Utf8Value exception(try_catch->Exception());
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
    String::Utf8Value stack_trace(try_catch->StackTrace());
    if (stack_trace.length() > 0) {
      const char* stack_trace_string = ToCString(stack_trace);
      os::Printf("%s\n", stack_trace_string);
    }
  }
}


Handle<Value> V8Init::DoRun(const char* src, const char* name) {
  //os::ScopedLock lock(mutex_);
  HandleScope handle_scope;
  Handle<String> source = String::New(src);
  Handle<Value> exception;
  Handle<Value> val;
  std::string begin = os::fs::Path::current_directory();
  {
    v8::TryCatch try_catch;
    Handle<Script> script = (name == NULL)? Script::Compile(source) : Script::Compile(source, String::New(name));
    if (script.IsEmpty()) {
      exception = Local<Value>::New(try_catch.Exception());
    } else {
      val = script->Run();
      if (val.IsEmpty()) {
        exception = Local<Value>::New(try_catch.Exception());
      }
    }
    if (!exception.IsEmpty()) {
      HandleException(&try_catch);
      try_catch.Reset();
    }
  }
  os::fs::Directory::chdir(begin.c_str());
  if (!val.IsEmpty()) {
    return handle_scope.Close(val);
  } else {
    return Undefined();
  }
}


void V8Init::Initialize() {
  HandleScope handle_scope;
  config_global_template_ = Persistent<ObjectTemplate>::New(ObjectTemplate::New());
  context_ = Context::New(NULL, config_global_template_);
  context_->Enter();
  Context::Scope context_scope(context_);
  native_ = Persistent<Object>::New(Object::New());
  Handle<Value> fn = DoRun(init_js::initjs);
  Handle<FunctionTemplate> compile_tmp = FunctionTemplate::New(Compile);
  Handle<Function> callable = Handle<Function>::Cast(fn);
  compile_ = Persistent<Function>::New(compile_tmp->GetFunction());
  Extension<NativeWrap>();
  config_global_ = Persistent<Object>::New(context_->Global());
  Handle<Value> args[] = {config_global_, native_, compile_, String::New(os::fs::Path::current_directory())};
  Handle<Value> ret = callable->Call(callable, 4, args);
  Handle<Function> config_context = Handle<Function>::Cast(ret);
  function_ = Persistent<Function>::New(config_context);
  context_->Exit();
}



os::Mutex V8Init::mutex_;

}
