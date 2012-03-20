namespace mocha {
CompilationEvent::CompilationEvent(CompilationInfo* info, ErrorReporter* reporter,
                                   Notificator* notificator, memory::Pool* pool)
    : compilation_info_(info),
      error_reporter_(reporter),
      notificator_(notificator),
      pool_(pool){}

const char CompilationEvent::EventKey::kScan[] = {"Compile<Scan>"};
const char CompilationEvent::EventKey::kParse[] = {"Compile<Parse>"};
const char CompilationEvent::EventKey::kTransform[] = {"Compile<Transform>"};
}
