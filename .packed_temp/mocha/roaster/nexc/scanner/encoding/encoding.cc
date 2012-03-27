#include <string.h>
#include <iostream>
#include <third_party/icu/include/unicode/uclean.h>
#include <mocha/roaster/nexc/scanner/encoding/encoding.h>
namespace mocha {
SharedPtr<DetectResult> ICUWrapper::GetEncode(const char* source) {
  UErrorCode error = U_ZERO_ERROR;
  u_init(&error);
  UCharsetDetector* detector = ucsdet_open(&error);
  ucsdet_setText(detector, source, strlen(source), &error);
  const UCharsetMatch* match = ucsdet_detect(detector, &error);
  SharedPtr<DetectResult> result(new DetectResult);
  if (U_FAILURE(error)) {
    result->charset = 0;
    result->lang = 0;
    result->error = true;
  } else {
    result->charset = ucsdet_getName(match, &error);
    result->lang = ucsdet_getLanguage(match, &error);
    result->error = false;
  }
  ucsdet_close(detector);
  u_cleanup();
  return result;
}

SharedStr ICUWrapper::Convert(icu::UnicodeString* src) {
  int length = src->extract(0, src->length(), NULL, "UTF-8");
  std::vector<char> result(length + 1);
  src->extract(0, src->length(), &result[0], "UTF-8");
  std::string tmp(result.begin(), result.end() - 1);
  char* ret = new char[ tmp.size() + 1 ];
  strcpy(ret, tmp.c_str());
  return SharedStr(ret);
}

SharedStr ICUWrapper::EncodeToUtf8(const char* source, const char* type) {
  icu::UnicodeString src(source, type);
  return Convert(&src);
}

SharedStr ICUWrapper::EncodeToUtf8(const wchar_t* source) {
  wprintf(L"%s\n", source);
  icu::UnicodeString src(reinterpret_cast<const UChar*>(source));
  return Convert(&src);
}

}
