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
  char tmp[2];
  tmp[0] = ch;
  tmp[1] = 0;
  buffer_.insert(cursor_, tmp);
  ClearLine(0);
  ResetCursor();
  int pos = (cursor_ + prompt_size_ + 2);
  int real_size = cursor_ + prompt_size_;
  if ((cursor_ + 1) >= buffer_.size() && real_size > Winsize()->ws_col && real_size % Winsize()->ws_col == 0) {
    WritePositiveYSeqence(1);
    current_line_++;
    logical_linefeed_++;
  }
  if (logical_linefeed_ > 0) {
    int target = pos - Winsize()->ws_col * current_line_;
    printf("%s%s", prompt_, buffer_.c_str());
    if (current_line_ < logical_linefeed_) {
      WriteNegativeYSeqence(logical_linefeed_ - current_line_);
    }
    WriteAbX(target);
  } else {
    printf("%s%s", prompt_, buffer_.c_str());
    if (real_size == Winsize()->ws_col) {
      WriteAbX(1);
    } else {
      WriteAbX(pos);
    }
  }
  UpdateCursorPos(1, 0);
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
  if (cursor_ > 0) {
    buffer_.erase((cursor_ - 1), 1);
    ClearLine(0);
    ResetCursor();
    UpdateCursorPos(-1, 0);
    int pos = (cursor_ + prompt_size_);
    int target = pos - Winsize()->ws_col * current_line_;
    int real_size = cursor_ + prompt_size_;
    printf("%s%s", prompt_, buffer_.c_str());
    if (cursor_ >= buffer_.size() && real_size % Winsize()->ws_col == 0) {
      WritePositiveYSeqence(1);
    }
    if (cursor_ >= buffer_.size() && real_size % Winsize()->ws_col == 0) {
      WriteAbX(0);
    } else if ((real_size + 1) % Winsize()->ws_col == 0) {
      WriteAbX(Winsize()->ws_col);
    } else {
      WriteAbX(target + 1);
    }
  }
}

void Stream::Delete() {
  if ((cursor_ + 1) <= buffer_.size()) {
    MoveRelative(1, 0);
    Bs();
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
    if (logical_linefeed_ > 0) {
      int tmp = logical_linefeed_;
      if (logical_linefeed_ - current_line_ > 0) {
        WritePositiveYSeqence(logical_linefeed_ - current_line_);
      }
      while (tmp > 0) {
        tmp--;
        WriteClearLine();
        WriteNegativeYSeqence(1);
      }
      if (current_line_ > 0) {
        WritePositiveYSeqence(current_line_);
      }
    } else {
      WriteClearLine();
    }
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
          if (x < 0 && (cursor_ + prompt_size_) < pos->ws_col * current_line_) {
            current_line_--;
            WriteAbX(pos->ws_col);
            WriteNegativeYSeqence(1);
          } else if (x > 0 && (cursor_ + prompt_size_ + 1) > (pos->ws_col * (current_line_ + 1))) {
            current_line_++;
            WriteAbX(0);
            WritePositiveYSeqence(1);
          }
        } else {
          if (x < 0 && (cursor_ + prompt_size_) < (pos->ws_col * current_line_)) {
            current_line_--;
            WriteAbX(pos->ws_col);
            WriteNegativeYSeqence(1);
          } else if (x > 0 && cursor_ > buffer_size) {
            cursor_ -= x;
            WriteAbX((buffer_size + prompt_size_) % pos->ws_col + 1);
          }
        }
      } else {
        if (x > 0 && (cursor_ + prompt_size_ + 1) > pos->ws_col) {
          current_line_++;
          WriteAbX(0);
          WritePositiveYSeqence(1);
        } else if (cursor_ < 0) {
          cursor_ = 0;
          WriteAbX(prompt_size_ + 1);
        }
      }
    } else if (buffer_size > 0 && cursor_ > 0 && cursor_ > buffer_size) {
      cursor_ = buffer_size;
      WriteAbX(cursor_ + prompt_size_ + 1);
    } else if (cursor_ < 0) {
      cursor_ = 0;
      WriteAbX(prompt_size_ + 1);
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
    ResetCursor();
    ClearLine(1);
    Clear();
    buffer_ = history_.at(history_cursor_).c_str();
    int size = buffer_.size();
    int real_size = prompt_size_ + size;
    if (real_size > Winsize()->ws_col) {
      logical_linefeed_ = floor(real_size / Winsize()->ws_col);
      current_line_ = logical_linefeed_;
      cursor_ = size;
    } else {
      cursor_ = 0;
    }
    printf("%s%s", prompt_, buffer_.c_str());
    UpdateCursorPos(size, 0);
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
    if (current_line_ > 0) {
      WriteNegativeYSeqence(current_line_);
    }
    WriteAbX(0);
  }
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
