/**
 *@author Taketoshi Aono
 *@fileOverview
 *@license
 *Copyright (c) 2011 Taketoshi Aono
 *
 *Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
 *associated doc umentation files (the "Software"), to deal in the Software without restriction,
 *including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 *subject to the following conditions:
 *
 *The above copyright notice and this permission notice shall be included in all copies or
 *substantial portions ofthe Software.
 *
 *THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 *TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 *THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 *CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *DEALINGS IN THE SOFTWARE.
 */
#ifndef mocha_options_h_
#define mocha_options_h_

#include <string.h>
#include <utils/int_types.h>
#include <string>
#include <vector>
#include <utils/smart_pointer/ref_count/handle.h>
#include <options/setting.h>

namespace mocha {
class Options {
 public :
  Options() : options_( 0 ){}
  ~Options(){}
  inline void AnalyzeOption ( const char* argv ) {
    AnalyzeOption_( argv );
  }
  inline const char* GetPath () {
    return path_.c_str();
  }
  inline bool IsCommandLineCompile() { return ( options_ & 1 )  == 1; }
  inline bool IsPrettyPrint() { return ( options_ & 2 ) == 2; }
  inline bool IsDebug() { return ( options_ & 4 ) == 4; }
  inline bool IsPath() { return ( options_ & 8 ) == 8; }
  inline bool IsCompress() { return ( options_ & 16 ) == 16; }
  inline bool IsUnmatch() { return ( options_ & 32 ) == 32; }
  inline void ShowError() {
    fprintf( stderr , "%s\n" , error_.c_str() );
  }
  inline void StopObserve() {
    options_ |= 32;
  }
  inline bool IsStopObserving() {
    return ( options_ & 32 ) == 32;
  }
  inline void Reset() {
    options_ = 0;
    error_.clear();
    path_.clear();
  }
 private :

  void AnalyzeOption_( const char* argv ) {
    if ( argv[ 0 ] == '-' ) {
      if ( strlen( argv ) == 2 ) {
        MatchOptions_( argv[ 1 ] );
      } else {
        if ( argv[ 1 ] == '-' ) {
          if ( strcmp( argv , "--compile" ) == 0 ) {
            CommandLineCompile_();
          } else if ( strcmp( argv , "--pretty-print" ) == 0 ) {
            PrettyPrint_();
          } else if ( strcmp( argv , "--debug" ) == 0 ) {
            Debug_();
          } else if ( strcmp( argv , "--compress" ) == 0 ) {
            Compress_();
          } else {
            if ( !IsUnmatch() ) {
              Unmatch_( argv );
            }
          }
        }
      }
    } else {
      path_ = argv;
      HasPath_();
      if ( !IsCommandLineCompile() ) {
        if ( !IsUnmatch() ) {
          Unmatch_( path_.c_str() );
        }
      }
    }
  }
  
  void MatchOptions_ ( char arg ) {
    switch( arg ) {
      case 'c' :
        CommandLineCompile_();
        break;
      case 'P' :
        PrettyPrint_();
        break;
      case 'D' :
        Debug_();
        break;
      case 'C' :
        Compress_();
        break;
      default :
        if ( !IsUnmatch() ) {
          std::string arg_str;
          arg_str += arg;
          Unmatch_( arg_str.c_str() );
        }
    }
  }

  void UnrecognizedOption_( const char* opt ) {
    char tmp[1000];
    sprintf( tmp , "%s is unrecognized option. See help.\n" , opt );
    error_ = tmp;
  }
  
  void OptionNotEnough_( const char* opt ) {
    fprintf( stderr , "%s require parameter\nSee mocha --help.\n" , opt );
  }
  void CommandLineCompile_() { options_ |= 1; }
  void PrettyPrint_() { options_ |= 2; }
  void Debug_() { options_ |= 4; }
  void HasPath_() { options_ |= 8; }
  void Compress_() { options_ |= 16; }
  void Unmatch_( const char* op ) { options_ |= 32;UnrecognizedOption_( op ); }
  int32_t options_;
  std::string error_;
  std::string path_;
};

}

#endif //mocha_options_h_
