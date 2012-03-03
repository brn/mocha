#include <string.h>
#include <iostream>
#include <mocha/roaster/encoding/encoding.h>
#include <unicode/ucsdet.h>
#include <unicode/ucnv.h>
namespace mocha {
Handle<DetectResult> ICUWrapper::GetEncode( const char* source ) {
  UErrorCode error = U_ZERO_ERROR;
  UCharsetDetector* detector = ucsdet_open(&error);
  ucsdet_setText(detector, source, strlen( source ), &error);
  const UCharsetMatch* match = ucsdet_detect(detector, &error);
  Handle<DetectResult> result( new DetectResult );
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
  return result;
}

StrHandle ICUWrapper::EncodeToUtf8( const char* source , const char* type ) {
  icu::UnicodeString src( source, type );
  int length = src.extract( 0, src.length(), NULL, "UTF-8" );

  std::vector<char> result( length + 1 );
  src.extract( 0, src.length(), &result[0], "UTF-8" );
  std::string tmp( result.begin(), result.end() - 1 );
  char* ret = new char[ tmp.size() + 1 ];
  strcpy( ret , tmp.c_str() );
  return StrHandle( ret );
}

}
