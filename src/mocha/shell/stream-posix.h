#ifndef mocha_shell_stream_posix_h_
#define mocha_shell_stream_posix_h_
#include <stdio.h>
#include <sys/ioctl.h>
#include <deque>
#include <vector>
#include <string>
#include <mocha/roaster/misc/class_traits/uncopyable.h>
namespace mocha {
typedef std::string ConsoleInput;
typedef std::vector<ConsoleInput> LineBuffer;
typedef std::deque<std::string> ConsoleHistory;
class Stream : private Uncopyable{
 public :
  Stream(const char* prompt);
  ~Stream(){}
  void Write(const char*);
  void Write(char);
  const char* Data();
  const ConsoleInput buffer();
  void Clear();
  void AddHistory();
  void PrevHistory();
  void NextHistory();
  void Bs();
  void Delete();
  void MoveLeft();
  void MoveRight();
  void Break(bool show_prompt = true);
  void ReadPos();
 private :
  class Pos;
  void Fold();
  void Initialize();
  void InitLine();
  winsize* Winsize();
  void MoveRelative(int x, int y);
  void ClearLine(int direction);
  void UpdateCursorPos(int x);
  void History();
  Pos Getxy() const;
  void WriteNegativeXSeqence(int x) const { printf("\x1b[%dD", x); }
  void WritePositiveXSeqence(int x) const { printf("\x1b[%dC", x); }
  void WritePositiveYSeqence(int y) const { printf("\x1b[%dB", y); }
  void WriteNegativeYSeqence(int y) const { printf("\x1b[%dA", y); }
  void WriteAbXY(int x, int y) const { printf("\x1b[%d;%dH", y, x); }
  void WriteClearLineLeft() const { printf("\x1b[1K"); }
  void WriteClearLineRight() const { printf("\x1b[0K"); }
  void WriteClearLine() const { printf("\x1b[2K"); }
  void WriteAbX(int x) const { printf("\x1b[%dG", x); }
  void CheckLogicalLine();
  void Insert(char val);
  int GetRealCursorPosition();
  void AddBuffer();
  const char* buffer_string() const;
  void RemoveBuffer(int num);
  int cursor_;
  int line_;
  int prompt_size_;
  int history_cursor_;
  int logical_linefeed_;
  int current_line_;
  const char* prompt_;
  LineBuffer buffer_;
  ConsoleHistory history_;
  ConsoleInput return_buffer_;
  winsize winsize_;
};

}

#endif
