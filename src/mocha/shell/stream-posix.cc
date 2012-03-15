#include <math.h>
#include <string.h>
#include <mocha/shell/stream-posix.h>

namespace mocha {

class Stream::Pos{
 public :
  Pos(int x, int y)
      : x_(x),
        y_(y){}
  ~Pos(){}
  Pos(const Pos& pos) {
    x_ = pos.x_;
    y_ = pos.y_;
  }
  int x() {return x_;}
  int y() {return y_;}
 private :
  int x_;
  int y_;
};

Stream::Stream(const char* prompt)
      : cursor_(0),
        line_(0),
        history_cursor_(0),
        logical_linefeed_(0),
        current_line_(0),
        prompt_(prompt){ Initialize(); }

void Stream::Write(const char* buf) {
  /*int len = strlen(buf);
  buffer_.append(buf);
  printf("%s", buf);
  UpdateCursorPos(len);
  CheckLogicalLine();*/
}


void Stream::Fold() {
  return_buffer_.clear();
  LineBuffer::iterator it;
  for (it = buffer_.begin(); it < buffer_.end(); ++it) {
    return_buffer_ += (*it);
  }
}


const ConsoleInput Stream::buffer() {
  Fold();
  return return_buffer_;
}

const char* Stream::Data() {
  Fold();
  return return_buffer_.c_str();
}

int Stream::GetRealCursorPosition() {
  if (logical_linefeed_ > 0) {
    return Winsize()->ws_col * logical_linefeed_ + cursor_;
  } else {
    return cursor_;
  }
}

void Stream::AddBuffer() {
  buffer_.push_back(std::string(""));
}

void Stream::RemoveBuffer(int num) {
  buffer_.erase(buffer_.begin() + num);
}

const char* Stream::buffer_string() const {
  return buffer_.at(current_line_).c_str();
}

void Stream::Insert(char val) {
  char tmp[2];
  tmp[0] = val;
  tmp[1] = 0;
  buffer_.at(current_line_).insert(GetRealCursorPosition(), tmp);
}

void Stream::Write(char ch) {
  Insert(ch);
  ClearLine(0);
  WriteAbX(0);
  UpdateCursorPos(1);
  if (current_line_ == 0) {
    printf("%s%s", prompt_, buffer_string());
  } else {
    printf("%s", buffer_string());
  }
  if (cursor_ + prompt_size_ > Winsize()->ws_col) {
    cursor_ = 0;
    WriteAbX(0);
    AddBuffer();
  } else {
    if (current_line_ == 0) {
      WriteAbX(cursor_ + 1 + prompt_size_);
    } else {
      WriteAbX(cursor_ + 1);
    }
  }
}
  
void Stream::Clear() {
  buffer_.clear();
  cursor_ = 0;
  logical_linefeed_ = 0;
  current_line_ = 0;
  AddBuffer();
}

void Stream::AddHistory() {
}

void Stream::PrevHistory() {
}

void Stream::NextHistory() {
}

void Stream::Bs() {
}

void Stream::Delete() {
}

void Stream::MoveLeft() {
  CheckLogicalLine();
  MoveRelative(-1, 0);
}

void Stream::MoveRight() {
  CheckLogicalLine();
  MoveRelative(1, 0);
}

void Stream::Break(bool show_prompt) {
  printf("\n\r");
  cursor_ = 0;
  buffer_.clear();
  AddBuffer();
  if (Winsize()->ws_row > line_) {
    line_++;
  }
  logical_linefeed_ = 0;
  current_line_ = 0;
  if (show_prompt) {
    printf("%s", prompt_);
  }
}

void Stream::ReadPos() {
  Stream::Pos pos = Getxy();
  line_ = pos.y();
}

void Stream::Initialize() {
  InitLine();
  prompt_size_ = strlen(prompt_);
  AddBuffer();
}

void Stream::InitLine() {
  Stream::Pos pos = Getxy();
  line_ = pos.y();
}

winsize* Stream::Winsize() {
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &winsize_);
  return &winsize_;
}
  
void Stream::MoveRelative(int x, int y) {
  if (x < 0) {
    WriteNegativeXSeqence(-x);
  } else if (x > 0){
    WritePositiveXSeqence(x);
  }
  if (y < 0) {
    WriteNegativeYSeqence(-y);
  } else if (y > 0){
    WritePositiveYSeqence(y);
  }
  UpdateCursorPos(x);
}
  
void Stream::ClearLine(int direction) {
  if (direction < 0) {
    WriteClearLineLeft();
  } else if (direction > 0) {
    WriteClearLineRight();
  } else {
    WriteClearLine();
  }
}
  
void Stream::UpdateCursorPos(int x) {
  if (x != 0) {
    int buffer_size = buffer_.size();
    int real_pos = GetRealCursorPosition();
    int last_cursor = cursor_;
    cursor_ += x;
    //Move right;
    if (x > 0) {
      if (current_line_ == 0) {
        if (last_cursor + prompt_size_ - 1 == Winsize()->ws_col) {
          current_line_++;
        }
      } else {
        if (last_cursor == Winsize()->ws_col) {
          current_line_++;
        }
      }
    } else {
      if (last_cursor == 0) {
        current_line_--;
      }
    }
  }
}

      
void Stream::History() {
}

Stream::Pos Stream::Getxy() const {
  int x,y;
  printf("\x1B[6n");
  scanf("\x1B[%d;%dR", &y, &x);
  return Pos(x,y);
}

void Stream::CheckLogicalLine() {
  int col = Winsize()->ws_col;
  int size = buffer_.size() + prompt_size_;
  if (size > col) {
    logical_linefeed_ = floor(size / col);
    current_line_ = floor((cursor_ + prompt_size_) / col);
  } else {
    logical_linefeed_ = 0;
    current_line_ = 0;
  }
}

}
