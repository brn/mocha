#include <sstream>
#include <mocha/options/options.h>

namespace mocha {

static const char* kCompileOnly = {"--compile"};
static const char* kConfigSpecified = {"--config"};
static const char* kDependencieCheckOnly = {"--deps"};
class OptionsState {
 public :
  enum {
    kCompileOnly,
    kConfigSpecified,
    kDependencieCheckOnly
  };
  OptionsState() : current_(-1){}
  ~OptionsState(){}
  bool IsEmpty() const {return current_ == -1;}
  bool Match(int type) const {return current_ == type;}
  void Set(int type) {current_ = type;}
  void Reset() {current_ = -1;}
 private :
  int current_;
};

Options::Options()
    : errors_(0),
      state_(new OptionsState){}

void Options::Parse(int argc, char** argv) {
  for (int i = 1; i < argc; i++) {
    const char* arg = argv[i];
    Analyze(arg);
  }
  if (!state_->IsEmpty()) {
    os::SPrintf(&error_, "expect arguments\n");
    errors_++;
  }
}

void Options::Analyze(const char* arg) {
  int len = strlen(arg);
  if (len > 2) {
    if (arg[0] == '-' && arg[1] == '-') {
      ParseCommand(arg);
    } else {
      ParseArguments(arg);
    }
  } else {
    if (arg[0] != '-') {
      ParseArguments(arg);
    }
  }
}

void Options::ParseCommand(const char* arg) {
  if (state_->IsEmpty()) {
    if (strcmp(arg, kCompileOnly) == 0) {
      return state_->Set(OptionsState::kCompileOnly);
    } else if (strcmp(arg, kConfigSpecified) == 0) {
      return state_->Set(OptionsState::kConfigSpecified);
    } else if (strcmp(arg, kDependencieCheckOnly) == 0) {
      return state_->Set(OptionsState::kDependencieCheckOnly);
    }
  }
  os::SPrintf(&error_, "%s is not valid arguments\n", &arg[2]);
  errors_++;
}

void Options::ParseArguments(const char* arg) {
  if (!state_->IsEmpty()) {
    if (state_->Match(OptionsState::kCompileOnly)) {
      if (IsDependencieCheckOnly()) {
        os::SPrintf(&error_, "--compile and --deps options can not set together.\n", arg);
        errors_++;
      } else {
        file_path_ = arg;
        flags_.Set(OptionsState::kCompileOnly);
      }
      state_->Reset();
    } else if (state_->Match(OptionsState::kConfigSpecified)) {
      config_path_ = arg;
      flags_.Set(OptionsState::kConfigSpecified);
      state_->Reset();
    } else if (state_->Match(OptionsState::kDependencieCheckOnly)) {
      if (IsCompileOnly()) {
        os::SPrintf(&error_, "--compile and --deps options can not set together.\n", arg);
        errors_++;
      } else {
        flags_.Set(OptionsState::kDependencieCheckOnly);
      }
      state_->Reset();
    }
  } else {
    os::SPrintf(&error_, "%s is not valid option\n", arg);
    errors_++;
  }
}
}
