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
#include <stdint.h>
#include <string>
#include "handle.h"
#include "setting.h"

namespace mocha {
class Options {
 public :
  Options(){}
  ~Options(){}
  inline void AnalyzeOption ( int argc , char** argv ) {
    if ( argc == 1 ) {
      OptionNotEnough_( "mocha" );
    }
    for ( int i = 1; i < argc; i++ ) {
      if ( argv[ i ][ 0 ] == '-' ) {
        if ( strlen( argv[ i ] ) == 2 ) {
          MatchOptions_( argv[ i ][ 1 ] , argv[ i ] );
        } else {
          if ( argv[ i ][ 1 ] == '-' ) {
            if ( strcmp( argv[ i ] , "--compile" ) == 0 ) {
              CommandLineCompile_();
            } else if ( strcmp( argv[ i ] , "--watch" ) == 0 ) {
              WatchFile_();
            } else if ( strcmp( argv[ i ] , "--XML" ) == 0 ) {
              WatchXML_();
            } else if ( strcmp( argv[ i ] , "--PrettyPrint" ) == 0 ) {
              PrettyPrint_();
            } else if ( strcmp( argv[ i ] , "--Line" ) == 0 ) {
              EmbedLine_();
            } else if ( strcmp( argv[ i ] , "--help" ) == 0 ) {
              ShowHelp_();
            }
          } else {
            for ( int j = 1,len = strlen( argv[ i ] ); j < len; ++j ) {
              MatchOptions_( argv[ i ][ j ] , argv[ i ] );
            }
          }
        }
      } else {
        char* path = new char[ strlen( argv[ i ] ) + 1 ];
        strcpy( path , argv[ i ] );
        path_( path );
        HasPath_();
      }
    }
    if ( IsCommandLineCompile() && !IsPath() ) {
      OptionNotEnough_( "-c/--compile" );
    }
  }
  inline StrHandle GetPath () {
    return path_;
  }
  inline bool IsCommandLineCompile() { return ( options_ & 1 )  == 1; }
  inline bool IsWatchFile() { return ( options_ & 2 )  == 2; }
  inline bool IsWatchXML() { return ( options_ & 4 ) == 4; }
  inline bool IsPrettyPrint() { return ( options_ & 8 ) == 8; }
  inline bool IsEmbedLine() { return ( options_ & 16 ) == 16; }
  inline bool IsShowHelp() { return ( options_ & 32 ) == 32; }
  inline bool IsPath() { return ( options_ & 64 ) == 64; }
 private :
  void MatchOptions_ ( char arg , const char* argv ) {
    switch( arg ) {
      case 'c' :
        CommandLineCompile_();
        break;
      case 'w' :
        WatchFile_();
        break;
      case 'X' :
        WatchXML_();
        break;
      case 'P' :
        PrettyPrint_();
        break;
      case 'L' :
        EmbedLine_();
        break;
      default :
        UnrecognizedOption_( argv );
    }
  }
  void UnrecognizedOption_( const char* opt ) { fprintf( stderr , "%s is unrecognized option. See mocha --help.\n" , opt );exit(1); }
  void OptionNotEnough_( const char* opt ) {
    fprintf( stderr , "%s require parameter\nSee mocha --help.\n" , opt );
    exit(1);
  }
  void CommandLineCompile_() { options_ |= 1; }
  void WatchFile_() { options_ |= 2; }
  void WatchXML_() { options_ |= 4; }
  void PrettyPrint_() { options_ |= 8; }
  void EmbedLine_() { options_ |= 16; }
  void ShowHelp_() { options_ |= 32; }
  void HasPath_() { options_ |= 64; }
  int8_t options_;
  StrHandle path_;
};

}

#endif //mocha_options_h_
