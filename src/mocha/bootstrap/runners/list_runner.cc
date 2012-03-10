#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <string>
#include <mocha/xml/xml_setting_info.h>
#include <mocha/bootstrap/runners/list_runner.h>

namespace mocha {

inline int Max(int x, int y) {
  return (x > y)? x : y;
}

class ListData {
  friend class ListRunner;
 public :
  ListData() : xml_max_len_(0), file_max_len_(0){}
  void Collect() {
    include_list_.push_back(xml_);
    file_list_.push_back(js_);
    XMLSettingInfo::IterateIncludeList(&ListData::SetToXMLList, this);
    XMLSettingInfo::IterateFileList(&ListData::SetToFileList, this);
    xml_max_len_ = (xml_max_len_ > 10)? xml_max_len_ : 10;
    file_max_len_ = (file_max_len_ > 10)? file_max_len_ : 10;
  }
  void SetToXMLList(const char* path) {
    xml_max_len_ = Max(xml_max_len_, strlen(path));
    include_list_.push_back(path);
  }
  
  void SetToFileList(const char* path) {
    file_max_len_ = Max(file_max_len_, strlen(path));
    file_list_.push_back(path);
  }

 private :
  static const char xml_[];
  static const char js_[];
  int xml_max_len_;
  int file_max_len_;
  std::vector<std::string> include_list_;
  std::vector<std::string> file_list_;
};

const char ListData::xml_[] = "xml";
const char ListData::js_[] = "javascript";


ListRunner::ListRunner(Options *options) : ICommandLineRunner(options) {}

void ListRunner::Run() {
  ListData data;
  data.Collect();
  int file_size = data.file_list_.size();
  int xml_size = data.include_list_.size();
  int index = Max(xml_size, file_size);
  Shell* shell = Shell::GetInstance();
  shell->SafeBreak(false);
  shell->SafePrint('+');
  for (int i = 0; i < data.xml_max_len_ + 5; i++) {
    shell->SafePrint('-');
  }
  for (int i = 0; i < data.file_max_len_ + 4; i++) {
    shell->SafePrint('-');
  }
  shell->SafePrint('+');
  shell->SafePrint('\n');
  for (int i = 0; i < index; i++) {
    shell->SafePrint('|');
    if (xml_size > i) {
      int diff = data.xml_max_len_ - data.include_list_[ i ].size();
      int mod = diff % 2;
      diff = (diff > 1)? diff / 2 : diff;
      for (int j = 0; j < diff ; j++) {
        shell->SafePrint(' ');
      }
      shell->SafePrint(' ');
      shell->SafePrint(data.include_list_[ i ].c_str());
      shell->SafePrint(' ');
      for (int j = 0; j < diff + mod ; j++) {
        shell->SafePrint(' ');
      }
    } else {
      for (int j = 0; j < data.xml_max_len_ + 4; j++) {
        shell->SafePrint(' ');
      }
    }
    shell->SafePrint('|');
    if (file_size > i) {
      int diff = data.file_max_len_ - data.file_list_[ i ].size();
      int mod = diff % 2;
      diff = (diff > 1)? diff / 2 : diff;
      for (int j = 0; j < diff ; j++) {
        shell->SafePrint(' ');
      }
      shell->SafePrint(' ');
      shell->SafePrint(data.file_list_[ i ].c_str());
      shell->SafePrint(' ');
      for (int j = 0; j < diff + mod ; j++) {
        shell->SafePrint(' ');
      }
      if (i == 0) {
        shell->SafePrint('|');
        shell->SafePrint("\n|");
        for (int j = 0; j < data.xml_max_len_ + 4; j++) {
          shell->SafePrint('-');
        }
        shell->SafePrint('|');
        for (int j = 0; j < data.file_max_len_ + 4; j++) {
          shell->SafePrint('-');
        }
      }
    } else {
      for (int j = 0; j < data.file_max_len_ + 4; j++) {
        shell->SafePrint(' ');
      }
    }
    shell->SafePrint('|');
    shell->SafePrint('\n');
  }
  for (int i = 0; i < (data.xml_max_len_ + data.file_max_len_ + 11); i++) {
    shell->SafePrint('-');
  }
  shell->SafePrint('\n');
  shell->SafeBreak();
}
}
