#include <string.h>
#include <ncurses.h>
#include <mocha/shell/shell.h>
namespace mocha {

const int kEnter = 10;
const int kEsc = 27;
const int kBackSpace = 127;
const int kEmacsRight = 6;
const int kEmacsLeft = 2;
const int kEmacsUp = 16;
const int kEmacsDown = 14;
const int kEmacsDl = 4;
const int kEndOfBuffer = 5;
const int kBeginingOfBuffer = 1;
const char kInput[] = {">>> "};
const int kMin = strlen(kInput);
void Init(bool norefresh = false) {
  addstr(kInput);
  if (!norefresh) {
    refresh();
  }
}

void Move(int move_y, int move_x, int max, bool clear = false) {
  int y;
  int x;
  getyx(stdscr, y, x);
  max = max + kMin;
  if (clear) {
    move(y, 0);
  } else {
    x = x + move_x;
    x = (x > -1)? x : 0;
    x = (x > max)? max : x;
    y += move_y;
    move(y, x);
  }
}

void ResetCursor() {
  Move(0, 0, 0, true);
}

void Deleteln() {
  ResetCursor();
  clrtoeol();
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
  initscr();
  cbreak();
  keypad(stdscr, TRUE);
  noecho();
  nl();
  idlok(stdscr, true);
  scrollok(stdscr, true);
  Print("mocha 0.7 (r"MOCHA_REV")");
  Break();
}
Shell::~Shell() {
  endwin();
}

void Shell::Read() {
  int ch;
  while((ch = getch())) {
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
  addstr(str);
}

void Shell::SafePrint(const char* str) {
  platform::ScopedLock lock(mutex_);
  addstr(str);
}

void Shell::Print(char ch) {
  echochar(ch);
}

void Shell::SafePrint(char ch) {
  platform::ScopedLock lock(mutex_);
  echochar(ch);
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
  int y;
  int x;
  getyx(stdscr, y, x);
  Move(1, 0, input_buffer_.size());
  if (y == (LINES - 1)) {
    wscrl(stdscr, 1);
  }
  ResetCursor();
  if (initial) {
    Init();
  } else {
    refresh();
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
    case KEY_UP :
      PrevHistory();
      break;

    case kEmacsDown :
    case KEY_DOWN :
      NextHistory();
      break;

    case kEmacsLeft :
    case KEY_LEFT :
      MoveLeft();
      break;

    case kEmacsRight :
    case KEY_RIGHT :
      MoveRight();
      break;

    case kBackSpace :
    case KEY_BACKSPACE :
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
      
    default :
      input_buffer_ += ch;
      if (isprint(ch)) {
        insch(ch);
        MoveRight();
        refresh();
      } else {
        char tmp[2];
        tmp[0] = ch;
        tmp[1] = 0;
        printw("%d",ch);
        refresh();
      }
  }
}

void Shell::History() {
  if (!input_history_.empty() && history_cursor_ < static_cast<int>(input_history_.size()) && history_cursor_ > -1) {
    Deleteln();
    Init(true);
    insstr(input_history_.at(history_cursor_).c_str());
    refresh();
  }
}

void Shell::PrevHistory() {
  if (history_cursor_ > 0) {
    history_cursor_--;
  }
  History();
}

void Shell::NextHistory() {
  if (history_cursor_ < static_cast<int>(input_history_.size() - 1)) {
    history_cursor_++;
  }
  History();
}

void Shell::MoveLeft() {
  Move(0, -1, input_buffer_.size());
}

void Shell::MoveRight() {
  Move(0, 1, input_buffer_.size());
}

void Shell::BackSpace() {
  int y,x;
  getyx(stdscr, y, x);
  if (x == 0) {
    return;
  }
  MoveLeft();
  getyx(stdscr, y, x);
  if (x < kMin) {
    MoveRight();
    return;
  }
  delch();
  input_buffer_.erase((x - kMin));
}

void Shell::Delete() {
  int y,x;
  getyx(stdscr, y, x);
  delch();
  input_buffer_.erase((x - kMin), 1);
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
