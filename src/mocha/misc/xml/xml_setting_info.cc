#include <mocha/misc/xml/xml_setting_info.h>
#include <mocha/options/setting.h>
#include <mocha/roaster/file_system/file_system.h>

#define SETTINGS Setting::GetInstance()

namespace mocha {

static const char utf8[] = { "UTF-8" };

void XMLSettingInfo::EraseData() {
  file_list_.clear();
  include_list_.clear();
  module_list_.clear();
}

XMLSettingInfo::List XMLSettingInfo::file_list_;   
XMLSettingInfo::List XMLSettingInfo::include_list_;
XMLSettingInfo::Hash XMLSettingInfo::module_list_;


}
