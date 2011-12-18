#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <boost/unordered_map.hpp>
#include <utils/profiler.h>
#include <utils/bits.h>
#include <utils/int_types.h>
#include "str_hash.h"
#define MAX_WORDS 100
#define MAX_EACH_WORD 100
using namespace std;

double GetTimeOfDaySec() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec + tv.tv_usec * 1e-6;
}

class HashAutoTester {

public :
  static void cacheWord ( const char* dict , const char* word ) {
    printf( "%d %d\n" , sizeof(map_) , sizeof( mocha::HashBucket<std::string,const char*> ) );
    fprintf( stderr , "begin collecting words ." );
    FILE *fp = fopen ( dict , "r" );
    FILE *fp2 = fopen ( word , "r" );
    int ch;
    int index = 0;
    
    if ( fp != NULL ) {

      while ( ( ch = fgetc ( fp ) ) != EOF ) {
        if ( !isalpha ( ch ) || index > ( MAX_EACH_WORD - 1 ) ) {
          if ( index > 0 ) {
            word_list[words_count][index] = '\0';
            if ( words_count > ( MAX_WORDS - 1 ) ) {
              break;
            }
            words_count++;
            char tmp2[100];
            strcpy( tmp2 , word_list[( words_count - 1 )] );
            for ( int i = 1; i < 200 && words_count < MAX_WORDS; i++ ) {
              sprintf( word_list[words_count] , "%s%d" , tmp2 , i );
              words_count++;
              if ( words_count > ( MAX_WORDS - 1 ) ) {
                goto END;
              }
            }
            index = 0;
            continue;
          }else{
            continue;
          }
        }
        
        word_list[words_count][index] = ch;
        index++;
      }
   END:
      index = 0;
      fprintf( stderr , "." );
      while ( ( ch = fgetc ( fp2 ) ) != EOF && value_count < MAX_WORDS ) {
      
        if ( !isalpha ( ch ) || index > ( MAX_EACH_WORD - 1 ) ) {
          if ( index > 0 ) {
            value_list[value_count][index] = '\0';
            value_count++;
            index = 0;
            continue;
          }else{
            continue;
          }
        }
        
        value_list[value_count][index] = ch;
        index++;
      }
    }else{
      exit ( 2 );
    }
    fprintf( stderr , ".\n" );
  };
  
  static void RunSrtTest () {
    fprintf( stderr , "Begin str_hash test.\n" );
    int index = words_count;
    int value_index = value_count;
    int all_count = 0;
    double start,end , insert;
    start = GetTimeOfDaySec();
    
    while ( index > 0 ) {

      if ( hash_.Find ( word_list[index] )->IsEmpty() ) {
        
        hash_.Insert( word_list[index] , value_list[value_index] );
        // printf ( "ret is empty %d , value %s  list key %s value %s  hash %lld count %d \n" ,hash_.Find( word_list[ index ] )->IsEmpty() , hash_.Find( word_list[ index ] )->Value() , word_list[ index ] , value_list[ value_index ] , hash_.Find( word_list[index] )->Hash() , index );
        strcpy( testerDict_[all_count] , word_list[index] );
        strcpy( testerWord_[all_count], value_list[value_index] );
        all_count++;
      }
      
      index--;
      value_index--;
      
      if ( value_index == -1 ) {
        value_index = value_count;
      }
      
    }
    int all = all_count - 1;
    while ( all > 0 ) {
      //printf ( "ret value %s  list key %s value %s  hash %lld count %d \n" ,hash_.Find( testerDict_[ all ] )->Value() , testerDict_[ all ] , testerWord_[ all ] , hash_.Find( testerDict_[all] )->Hash() , all );
      if ( strcmp ( hash_.Find( testerDict_[ all ] )->Value() , testerWord_[ all ] ) != 0 ) {
        fprintf ( stderr , "Word count is %d\nFailed key : %s, value : %s\n" , all , testerDict_[ all ] , testerWord_[all] );
        fprintf ( stderr , "Get result =  key : %s , value = %s\n" , hash_.Find( testerDict_[ all ] )->Key().c_str() , hash_.Find( testerDict_[ all ] )->Value()  );
        perror ( "Fail test." );
        exit ( 2 );
      }
      all--;
    }
    end = GetTimeOfDaySec();
    fprintf ( stderr , "All words count are %d\nAll process time is %f\nTest success.\n", all_count , end - start );
    {
      mocha::Profiler profiler( stderr , "str-hash-find" );
      profiler.Begin();
      if ( strcmp ( hash_.Find( testerDict_[ 1000 ] )->Value() , testerWord_[ 1000 ] ) != 0 ) {
        fprintf ( stderr , "Word count is %d\nFailed key : %s, value : %s\n" , 1000 , testerDict_[ 1000 ] , testerWord_[1000] );
        perror ( "Fail test." );
        exit ( 2 );
      }
      profiler.End();
    }
  }

  static void RunBoostTest () {
    fprintf( stderr , "Begin boost::unordered_map test.\n" );
    int index = words_count;
    int value_index = value_count;
    int all_count = 0;
    double start,end,insert;
    start = GetTimeOfDaySec();
    while ( index > 0 ) {
      
      if ( map_.find( word_list[index] ) == map_.end() ) {
        //printf ( "key %s value %s count %d \n" , word_list[index] , value_list[value_index] , all_count );
        
        map_.insert( std::pair<const char*,const char*>( word_list[index] , value_list[value_index] ) );
        
        strcpy( testerDict_[all_count] , word_list[index] );
        strcpy( testerWord_[all_count], value_list[value_index] );
        all_count++;
      }
      
      index--;
      value_index--;
      
      if ( value_index == -1 ) {
        value_index = value_count;
      }
      
    }
    int all = all_count - 1;
    
    while ( all > 0 ) {
      //insert = GetTimeOfDaySec();
      boost::unordered_map<std::string,std::string>::iterator find = map_.find( testerDict_[ all ] );
      if ( strcmp ( find->second.c_str() , testerWord_[ all ] ) != 0 ) {
        fprintf ( stderr , "Word count is %d\nFailed key : %s, value : %s\n" , all , testerDict_[ all ] , testerWord_[all] );
        perror ( "Fail test." );
        exit ( 2 );
      }
      //double iend = GetTimeOfDaySec();
      //fprintf( stderr , "find time is %f\n" , iend - insert );
      all--;
    }
    end = GetTimeOfDaySec();
    fprintf ( stderr , "All words count are %d\nAll process time is %f\nTest success.\n", all_count , end - start );
    {
      insert = GetTimeOfDaySec();
      boost::unordered_map<std::string,std::string>::iterator find = map_.find( testerDict_[ 1000 ] );
      if ( strcmp ( find->second.c_str() , testerWord_[ 1000 ] ) != 0 ) {
        fprintf ( stderr , "Word count is %d\nFailed key : %s, value : %s\n" , words_count , testerDict_[ 1000 ] , testerWord_[1000] );
        perror ( "Fail test." );
        exit ( 2 );
      }
      double iend = GetTimeOfDaySec();
      fprintf( stderr , "find time is %f\n" , iend - insert );
    }
  }
  
private:
  static long long int dictCount_;
  static long long int wordCount_;
  static char delimiter[];
  static char testerDict_[MAX_WORDS][MAX_EACH_WORD];
  static char testerWord_[MAX_WORDS][MAX_EACH_WORD];
  static char word_list[MAX_WORDS][MAX_EACH_WORD];
  static char value_list[MAX_WORDS][MAX_EACH_WORD];
  static int words_count;
  static int value_count;
  static mocha::StrHash<const char*> hash_;
  static boost::unordered_map<std::string,std::string> map_;
};

long long int HashAutoTester::dictCount_ = 0;
long long int HashAutoTester::wordCount_ = 0;
int HashAutoTester::words_count = 0; 
int HashAutoTester::value_count = 0;
char HashAutoTester::testerDict_[MAX_WORDS][MAX_EACH_WORD];
char HashAutoTester::testerWord_[MAX_WORDS][MAX_EACH_WORD];
char HashAutoTester::word_list[MAX_WORDS][MAX_EACH_WORD];  
char HashAutoTester::value_list[MAX_WORDS][MAX_EACH_WORD];
char HashAutoTester::delimiter [] = ",.;:|";
mocha::StrHash<const char*> HashAutoTester::hash_;
boost::unordered_map<std::string,std::string> HashAutoTester::map_;


int main ( int argc , char** argv ) {
  if ( argc < 3 ) {
    
    printf ( "%s\n", "Usage: HashAutoTester [dict file] [word file]" );
    return 0;
  } else {
    uint64_t v = 1ULL;
    uint64_t diff = 63 - mocha::bits::MSB64( v );
    uint64_t bited_ = ( v << diff );
    uint64_t bited = bited_ | ( ( bited_ << ( 63ULL - diff ) ) >> ( 63ULL - diff ) );
    uint64_t msb5 = bited >> 59ULL;
    uint64_t nmsb5 = ( bited << 5ULL ) >> 59ULL;
    printf( "%d,%lld,%lld,%llud,%llud\n" , mocha::bits::MSB64( v ) , msb5 , nmsb5 , UINT64_MAX , ( bited_ | (~bited_) ) );
    //HashAutoTester::cacheWord ( argv [ 1 ] , argv [ 2 ] );
    //HashAutoTester::RunSrtTest();
    //HashAutoTester::RunBoostTest();
    
  }
  return 0;
}


