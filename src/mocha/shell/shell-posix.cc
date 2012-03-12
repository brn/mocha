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
const char kInput[] = {">>> "};
const int kMin = strlen(kInput);

void move(int y, int x) {
  printf("\033[%d;%dH" , y, x);
  fflush(stdin);
}

void getyx(int *y, int *x) {
  printf("\x1B[6n");
  scanf("\x1B[%d;%dR", y, x);
}

void getsize(winsize* win) {
  ioctl(STDOUT_FILENO, TIOCGWINSZ, win);
}

void Init(bool norefresh = false) {
  printf("%s", kInput);
}

void Shell::Move(int move_y, int move_x, int max, bool clear) {
  int y;
  int x;
  int back = 0;
  getyx(&y, &x);
  winsize win;
  getsize(&win);
  if (win.ws_col < max) {
    int size = max;
    while(size > win.ws_col) {
      size -= win.ws_col;
      ++back;
    }
  }
  max = max + kMin;
  ResetShell();
  printf("\r");
  InitShell();
  int start_x;
  int start_y;
  getyx(&start_y, &start_x);
  int current = y - start_y;
  move(y, x);
  if (clear) {
    move(y - back, 0);
  } else {
    x = x + move_x;
    if (x < (kMin + 1) && back > 0) {
      if (x == 0) {
        move(y - back, win.ws_col);
      } else {
        move(y, x);
      }
    } else if (x == win.ws_col + 1 && back > 0) {
      if (current == y) {
        move(y + back, 0);
      } else {
        if (current == back) {
          move(y, win.ws_col);
        } else {
          move(y + back, 0);
        }
      }
    } else {
      x = (x > kMin + 1)? x : kMin + 1;
      x = (x > max)? (max + 1) : x;
      if (current > 0 && back > 0) {
        if (current == back) {
          int limit = (current > 1)? max - (current - 1) * win.ws_col : max - win.ws_col;
          if (x > limit) {
            move(y, limit);
          }
        }
        move(y, x);
      } else {
        move(y, x);
      }
    }
  }
}

void Shell::ResetCursor() {
  Move(0, 0, 0, true);
}

void Shell::Deleteln(std::string* buffer) {
  winsize win;
  getsize(&win);
  int x,y;
  getyx(&y, &x);
  int size = buffer->size();
  if (win.ws_col < size) {
    int i = 0;
    while(size > win.ws_col) {
      size -= win.ws_col;
      i++;
    }
    move(y - i, 0);
  } else {
    ResetCursor();
  }
  printf("\033[0K");
}

void Shell::delch(std::string* buf) {
  int x,y;
  getyx(&y, &x);
  int pos = x - kMin - 1;
  Deleteln(buf);
  Init();
  if (!buf->empty() && buf->size() > pos) {
    buf->assign(buf->erase(pos, 1));
    printf("%s", buf->c_str());
  }
  move(y, x);
}


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
    : history_cursor_(0),
      action_(action){
  setlocale(LC_ALL,"");
  printf("mocha 0.7 (r"MOCHA_REV")");
  printf("\nusage -> run 'help'");
  InitShell();
  Break();
}

Shell::~Shell() {
  ResetShell();
  printf("\n");
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

int getch() {
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

void Shell::Read() {
  int ch;
  while((ch = getch())) {
    usleep(700);
    bool execute = CheckInput(ch);
    if (execute) {
      AddHistory();
      if(CallAction()) {
        break;
      }
    }
  }
}

void Shell::Print(const char* str) {
  ResetCursor();
  int i = 0;
  while (str[i]) {
    if (str[i] == '\n') {
      Break(false);
    } else {
      putc(str[i], stdout);
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
    Break(false);
  } else {
    putc(ch, stdout);
  }
}

void Shell::SafePrint(char ch) {
  platform::ScopedLock lock(mutex_);
  Print(ch);
}


void Shell::AddHistory() {
  input_history_.push_back(input_buffer_);
  history_cursor_ = input_history_.size();
}

bool Shell::CallAction() {
  int ret = action_(input_buffer_);
  input_buffer_.clear();
  return ret;
}

void Shell::Break(bool initial) {
  printf("\n\r");
  if (initial) {
    Init();
  }
}

void Shell::SafeBreak(bool initial) {
  platform::ScopedLock lock(mutex_);
  Break(initial);
}

bool Shell::CheckInput(int ch) {
  if (ch == kEnter) {
    if (input_buffer_.size() == 0) {
      Break();
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
      PrevHistory();
      break;

    case kEmacsDown :
    case kKeyDown :
      NextHistory();
      break;

    case kEmacsLeft :
    case kKeyLeft :
      MoveLeft();
      break;

    case kEmacsRight :
    case kKeyRight :
      MoveRight();
      break;

    case kBackSpace :
      BackSpace();
      break;

    case kEmacsDl :
      Delete();
      break;

    case kEndOfBuffer :
      EndOfBuffer();
      break;

    case kBeginingOfBuffer :
      BeginingOfBuffer();
      break;
      
    default : {
      ResetShell();
      if (isprint(ch)) {
        input_buffer_ += ch;
      }
      putc(ch, stdout);
      InitShell();
    }
  }
}

void Shell::History() {
  if (!input_history_.empty() && history_cursor_ < static_cast<int>(input_history_.size()) && history_cursor_ > -1) {
    Deleteln(&input_buffer_);
    ResetShell();
    Init(true);
    input_buffer_ = input_history_.at(history_cursor_).c_str();
    int size = input_buffer_.size();
    for(int i = 0;i < size; i++) {
      if (input_buffer_.at(i) != '\n') {
        putc(input_buffer_.at(i), stdout);
      }
    }
    InitShell();
  }
}

void Shell::PrevHistory() {
  if (history_cursor_ > 0) {
    history_cursor_--;
    History();
  }
}

void Shell::NextHistory() {
  if (history_cursor_ < static_cast<int>(input_history_.size() - 1)) {
    history_cursor_++;
    History();
  }
}

void Shell::MoveLeft() {
  Move(0, -1, input_buffer_.size());
}

void Shell::MoveRight() {
  Move(0, 1, input_buffer_.size());
}

void Shell::BackSpace() {
  int y,x;
  getyx(&y, &x);
  if (x == kMin) {
    return;
  }
  MoveLeft();
  getyx(&y, &x);
  if (x < kMin) {
    MoveRight();
    return;
  }
  delch(&input_buffer_);
  //input_buffer_.erase((x - kMin), 1);
}

void Shell::Delete() {
  int y,x;
  getyx(&y, &x);
  delch(&input_buffer_);
  //input_buffer_.erase((x - kMin), 1);
}

void Shell::EndOfBuffer() {
  int size = input_buffer_.size();
  Move(0, size, size);
}

void Shell::BeginingOfBuffer() {
  Move(0, 0, input_buffer_.size());
}

platform::Mutex Shell::mutex_;
ScopedPtr<Shell> Shell::shell_;
AtomicWord Shell::init_;

}
