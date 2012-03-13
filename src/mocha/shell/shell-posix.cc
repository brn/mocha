#include <string.h>
#include <unistd.h>
#include <mocha/shell/shell.h>
#include <sys/ioctl.h>
namespace mocha {

const int kEnter = 13;
const int kEsc = 27;
const int kBackSpace = 127;
const int kEmacsRight = 6;
const int kEmacsLeft = 2;
const int kEmacsUp = 16;
const int kEmacsDown = 14;
const int kEmacsDl = 4;
const int kEndOfBuffer = 5;
const int kBeginingOfBuffer = 1;
const int kKeyUp = 65;
const int kKeyDown = 66;
const int kKeyLeft = 67;
const int kKeyRight = 68;
const char kPrompt[] = {">>> "};


Shell* Shell::Initialize(Action& action) {
  if (Atomic::CompareAndSwap(&init_, 0, 1) == 0) {
    init_ = 1;
    shell_(new Shell(action));
    return shell_.Get();
  }
  return 0;
}

Shell* Shell::GetInstance() {
  return shell_.Get();
}

Shell::Shell(Action& action)
    : action_(action){
  setlocale(LC_ALL,"");
  printf("mocha 0.7 (r"MOCHA_REV")");
  printf("\nusage -> run 'help'");
  InitShell();
  stream_(new Stream(kPrompt));
  stream_->Break();
}

Shell::~Shell() {
  ResetShell();
  printf("\n");
}


void Shell::Read() {
  int ch;
  while((ch = Getch())) {
    usleep(700);
    bool execute = CheckInput(ch);
    if (execute) {
      stream_->AddHistory();
      if(CallAction()) {
        break;
      }
      stream_->Clear();
    }
  }
}

void Shell::InitShell() {
  tcgetattr(STDIN_FILENO, &cooked_term_ios_);
  raw_term_ios_ = cooked_term_ios_;
  cfmakeraw(&raw_term_ios_);
  raw_term_ios_.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
  raw_term_ios_.c_oflag |= (ONLCR | OPOST);
  raw_term_ios_.c_cflag |= (CS8);
  raw_term_ios_.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
  raw_term_ios_.c_cc[VMIN] = 1;
  raw_term_ios_.c_cc[VTIME] = 0;
  tcsetattr(STDIN_FILENO, TCSADRAIN, &raw_term_ios_);
}

void Shell::ResetShell() {
  tcsetattr(STDIN_FILENO, 0, &cooked_term_ios_);
}

int Shell::Getch() {
  int ch;
  do{
    ch = getchar();
  }while(ch == '\n');
  if (ch == 27) {
    ch = getchar();
    if (ch == 91) {
      ch = getchar();
      switch(ch) {
        case 65 :
          return kKeyUp;
        case 66 :
          return kKeyDown;
        case 67 :
          return kKeyRight;
        case 68 :
          return kKeyLeft;
      }
    }
  }
  return ch;
}

void Shell::Print(const char* str) {
  int i = 0;
  while (str[i]) {
    if (str[i] == '\n') {
      stream_->Break(false);
    } else {
      stream_->Write(str[i]);
    }
    i++;
  }
}

void Shell::SafePrint(const char* str) {
  platform::ScopedLock lock(mutex_);
  Print(str);
}

void Shell::Print(char ch) {
  if (ch == '\n') {
    stream_->Break(false);
  } else {
    stream_->Write(ch);
  }
}

void Shell::SafePrint(char ch) {
  platform::ScopedLock lock(mutex_);
  Print(ch);
}


bool Shell::CallAction() {
  ResetShell();
  int ret = action_(stream_->buffer());
  InitShell();
  stream_->ReadPos();
  stream_->Clear();
  return ret;
}

void Shell::Break(bool initial) {
  stream_->Break();
}

void Shell::SafeBreak(bool initial) {
  platform::ScopedLock lock(mutex_);
  Break(initial);
}

bool Shell::CheckInput(int ch) {
  if (ch == kEnter) {
    if ( stream_->buffer().size() == 0) {
      stream_->Break();
      return false;
    } else {
      //Break();
      return true;
    }
  } else {
    SwitchShellAction(ch);
  }
  return false;
}

void Shell::SwitchShellAction(int ch) {
  switch (ch) {
    case kEmacsUp :
    case kKeyUp :
      stream_->PrevHistory();
      break;

    case kEmacsDown :
    case kKeyDown :
      stream_->NextHistory();
      break;

    case kEmacsLeft :
    case kKeyLeft :
      stream_->MoveLeft();
      break;

    case kEmacsRight :
    case kKeyRight :
      stream_->MoveRight();
      break;

    case kBackSpace :
      stream_->Bs();
      break;

    case kEmacsDl :
      stream_->Delete();
      break;

    case kEndOfBuffer :
      //stream_->EndOfBuffer();
      break;

    case kBeginingOfBuffer :
      //stream_->BeginingOfBuffer();
      break;
      
    default : {
      stream_->Write(ch);
    }
  }
}

platform::Mutex Shell::mutex_;
ScopedPtr<Shell> Shell::shell_;
AtomicWord Shell::init_;

}
