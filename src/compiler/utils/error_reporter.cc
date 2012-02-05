#include <sstream>
#include <compiler/utils/error_reporter.h>

namespace mocha {
ErrorReporter::ErrorReporter() : error_num_( 0 ) {}
ErrorReporter::~ErrorReporter(){}
void ErrorReporter::ReportSyntaxError( const char* error ) {
  raw_list_.push_back( error );
  std::stringstream st;
  st << "try{\n"
      "  throw new SyntaxError(\"" << error << "\")\n"
      "}catch(e){\n"
      "  throw new Error(e);\n"
      "}\n;";
  std::string ret = st.str();
  buffer_.push_back( ret );
  error_num_++;
}

void ErrorReporter::SetError( std::string *buf ) {
  if ( error_num_ > 0 ) {
    ErrorList::iterator begin = buffer_.begin(),end = buffer_.end();
    while ( begin != end ) {
      (*buf) += begin->c_str();
      ++begin;
    }
  }
}

void ErrorReporter::SetRawError( std::string *buf ) {
  if ( error_num_ > 0 ) {
    ErrorList::iterator begin = raw_list_.begin(),end = raw_list_.end();
    while ( begin != end ) {
      (*buf) += begin->c_str();
      (*buf) += "\n";
      ++begin;
    }
  }
}
}
