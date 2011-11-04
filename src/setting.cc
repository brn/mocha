#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include "setting.h"
#include "file_system.h"
#include "file_io.h"
#include "handle.h"
#include "thread.h"
#include "stat.h"

namespace mocha {

class Setting::PtrImpl {
 public :
  void Log( const char* str , const char* type , bool is_date ) {
    MutexLock lock( mutex );
    std::string tmp;
    if ( is_date ) {
      tmp = ::asctime( date );
      tmp.erase( tmp.size() - 1 , tmp.size() );
      tmp += " ";
      tmp += type;
      tmp += " : ";
    }
    tmp += str;
    tmp += "\n";
    file_handle->write( tmp.c_str() );
  }
  
  time_t timer;
  tm* date;
  std::string base_dir;
  std::string xml_path;
  std::string module_path;
  std::string log_path;
  Handle<File> file_handle;
  
  static const char info[];
  static const char error[];
  static const char fatal[];
  static Mutex mutex;
};

const char Setting::PtrImpl::info[] = { "info" };
const char Setting::PtrImpl::error[] = { "error" };
const char Setting::PtrImpl::fatal[] = { "fatal" };
Mutex Setting::PtrImpl::mutex;

Setting* Setting::GetInstance() {
  if ( instance_ == 0 ) {
    fprintf( stderr , "class Setting not initialized." );
    abort();
  }
  return instance_;
}

const char* Setting::GetBasePath() { return implementation_->base_dir.c_str(); }
const char* Setting::GetXMLPath() { return implementation_->xml_path.c_str(); }
const char* Setting::GetModulePath() { return implementation_->module_path.c_str(); }
const char* Setting::GetLogPath() { return implementation_->log_path.c_str(); }
void Setting::Close(){ implementation_->file_handle->close(); }

void Setting::LogNoDate( const char* format , ... ) {
  char buffer[ 1000 ];
  va_list ap;
  va_start(ap, format);
  vsprintf(buffer, format, ap);
  va_end(ap);
  implementation_->Log( buffer , &( implementation_->info[0] ) , false);
}

void Setting::Log( const char* format , ... )  {
  char buffer[ 1000 ];
  va_list ap;
  va_start(ap, format);
  vsprintf(buffer, format, ap);
  va_end(ap);
  implementation_->Log( buffer , &( implementation_->info[0] ) , true );
}


void Setting::LogError( const char* format , ... )  {
  char buffer[ 1000 ];
  va_list ap;
  va_start(ap, format);
  vsprintf(buffer, format, ap);
  va_end(ap);
  implementation_->Log( buffer ,  &( implementation_->error[0] ) , true );
}


void Setting::LogFatal( const char* format , ... )  {
  char buffer[ 1000 ];
  va_list ap;
  va_start(ap, format);
  vsprintf(buffer, format, ap);
  va_end(ap);
  implementation_->Log( buffer , &( implementation_->fatal[0] ) , true );
}


Setting::Setting() {
  implementation_( new PtrImpl() );
  ::time( &( implementation_->timer ) );
  implementation_->date = localtime( &( implementation_->timer ) );
  implementation_->base_dir = FileSystem::GetUserHomeDir().get();
  implementation_->base_dir += "/.mocha/";
  implementation_->xml_path = implementation_->base_dir;
  implementation_->xml_path += "setting.xml";
  implementation_->module_path = implementation_->base_dir;
  implementation_->module_path += "module/";
  implementation_->log_path = implementation_->base_dir;
  implementation_->log_path += "mocha.log";
}

void Setting::SetLogFileHandle() {
  implementation_->file_handle = FileIO::Open( implementation_->log_path.c_str() , "rwa" , FileIO::P_ReadWrite );
}

Setting* Setting::instance_ = 0;

}
