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
  int len = strlen(buf);
  buffer_.append(buf);
  printf("%s", buf);
  UpdateCursorPos(len, 0);
  CheckLogicalLine();
}

void Stream::Write(char ch) {
  buffer_ += ch;
  UpdateCursorPos(1, 0);
  putc(ch, stdout);
  CheckLogicalLine();
}
  
void Stream::Clear() {
  buffer_.clear();
  cursor_ = 0;
  logical_linefeed_ = 0;
  current_line_ = 0;
}

void Stream::AddHistory() {
  if (!buffer_.empty()) {
    history_.push_back(buffer_);
    history_cursor_ = history_.size();
  }
}

void Stream::PrevHistory() {
  if (history_cursor_ > 0) {
    history_cursor_--;
    History();
  }
}

void Stream::NextHistory() {
  if (history_cursor_ < static_cast<int>(history_.size() - 1)) {
    history_cursor_++;
    History();
  }
}

void Stream::Bs() {
  if ((cursor_ + prompt_size_) > prompt_size_) {
    buffer_.erase((cursor_ - 1), 1);
    ClearLine(0);
    WriteNegativeXSeqence(cursor_ + prompt_size_);
    printf("%s%s", prompt_, buffer_.c_str());
    UpdateCursorPos(-1, 0);
  }
}

void Stream::Delete() {
  int size = buffer_.size();
  if (cursor_ <= size) {
    buffer_.erase(cursor_, 1);
    ResetCursor();
    ClearLine(1);
    printf("%s%s", prompt_, buffer_.c_str());
    WriteAbX(cursor_ + prompt_size_ + 1);
  }
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
  line_++;
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
  UpdateCursorPos(x, y);
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
  
void Stream::UpdateCursorPos(int x, int y) {
  winsize *pos = Winsize();
  int buffer_size = buffer_.size();
  if (x != 0) {
    cursor_ += x;
    if (logical_linefeed_ > 0) {
      if (current_line_ > 0) {
        if (current_line_ < logical_linefeed_) {
          if ((cursor_ + prompt_size_) < pos->ws_col * current_line_) {
            current_line_--;
            WriteAbX(pos->ws_col);
            WriteNegativeYSeqence(1);
          } else if (cursor_ > pos->ws_col * (current_line_ + 1)) {
            current_line_++;
            WriteAbX(0);
            WritePositiveYSeqence(1);
          }
        } else {
          printf("%d %d\n" , (cursor_ + prompt_size_) , (pos->ws_col * current_line_));
          if (x < 0 && (cursor_ + prompt_size_) < (pos->ws_col * current_line_)) {
            current_line_--;
            WriteAbX(pos->ws_col);
            WriteNegativeYSeqence(1);
          } else if (x > 0 && (cursor_ + prompt_size_) > (buffer_.size() + 1)) {
            cursor_ = buffer_.size() % pos->ws_col;
            WriteAbX(cursor_);
          }
        }
      } else {
        if (cursor_ > pos->ws_col) {
          current_line_++;
          WriteAbX(0);
          WritePositiveYSeqence(1);
        }
      }
    } else if (buffer_size > 0 && cursor_ > 0 && cursor_ > buffer_size) {
      cursor_ = buffer_size;
      WriteAbX(cursor_ + prompt_size_ + 1);
    } else if (cursor_ < 0) {
      WriteAbX(prompt_size_ + 1);
      cursor_ = 0;
    }
  }
  
  if (y != 0) {
    line_ += y;
    if (line_ < 0) {
      line_ = 0;
    } else if(line_ > pos->ws_row) {
      line_ = pos->ws_row;
    }
  }
}

      
void Stream::History() {
  if (!history_.empty() && history_cursor_ < static_cast<int>(history_.size()) && history_cursor_ > -1) {
    ClearLine(0);
    Clear();
    buffer_ = history_.at(history_cursor_).c_str();
    int size = buffer_.size();
    cursor_ = 0;
    UpdateCursorPos(size, 0);
    for(int i = 0;i < size; i++) {
      putc(buffer_.at(i), stdout);
    }
  }
}

Stream::Pos Stream::Getxy() const {
  int x,y;
  printf("\x1B[6n");
  scanf("\x1B[%d;%dR", &y, &x);
  return Pos(x,y);
}

void Stream::ResetCursor() {
  if (logical_linefeed_ == 0) {
    WriteAbX(0);
  } else {
    int tmp = logical_linefeed_;
    while (tmp > 0) {
      tmp--;
      MoveRelative(0, -1);
    }
    WriteAbX(0);
  }
}

void Stream::CheckLogicalLine() {
  int col = Winsize()->ws_col;
  int size = buffer_.size();
  if (size > col) {
    logical_linefeed_ = floor(size / col);
    current_line_ = floor((cursor_ + prompt_size_) / col);
  } else {
    logical_linefeed_ = 0;
    current_line_ = 0;
  }
}

}
