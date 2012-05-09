#ifndef mocha_setting_h_
#define mocha_setting_h_
#include <mocha/options/options.h>
#include <mocha/roaster/lib/unordered_map.h>
#include <mocha/roaster/misc/class_traits/static.h>
#include <mocha/bootstrap/bootstrap.h>
namespace mocha {
class Setting : private Static{
  typedef std::pair<const char*, const char*> SettingPair;
  typedef roastlib::unordered_map<std::string, std::string> SettingMap;
 public :
  static void Initialize(const Options& options);
  static void Destruct();
  static const char* config_path();
  static const char* tmp_path();
  static const char* base();
  static const char* Get(const char* key);
  static void Set(const char* key, const char* val);
  static bool Has(const char* key);
  static const char* moduledir();
  static const char kCompileSettingPath[];
  static const char kPhantomPath[];
  static const char kLogPath[];
  static const char kTestRunner[];
  static const char* WatchFileTemplate();
 private :
  static SettingMap setting_map_;
  static std::string base_;
  static std::string tmp_file_;
  static std::string config_path_;
  static std::string moduledir_;
};
}

#endif
