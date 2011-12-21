#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <map>
#include <boost/unordered_map.hpp>
#include <utils/profiler.h>
#include <utils/bits.h>
#include <utils/int_types.h>
#include "str_hash.h"
#define MAX_WORDS 100000
#define MAX_EACH_WORD 30
using namespace std;

double GetTimeOfDaySec() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec + tv.tv_usec * 1e-6;
}

class HashAutoTester {

public :
  static void cacheWord ( const char* dict , const char* word ) {
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
            for ( int i = 1; i < 200000 && words_count < MAX_WORDS; i++ ) {
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
    fclose( fp );
    fclose( fp2 );
  };
  
  static void RunSrtTest () {
    fprintf( stderr , "Begin str_hash test.\n" );
    int index = words_count;
    int value_index = value_count;
    int all_count = 0;
    int count = 0;
    double start,end , insert;
    start = GetTimeOfDaySec();
    mocha::Profiler insert_profiler( stderr , "StrHash::Insert" );
    insert_profiler.Begin();
    while ( index > 0 ) {

      if ( /*hash_.Find ( word_list[index] )->IsEmpty()*/1 ) {
        
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
    insert_profiler.End();
    mocha::Profiler find_profiler( stderr , "StrHash::Find" );
    find_profiler.Begin();
    int all = all_count - 1;
    while ( all > 0 ) {
      count++;
      //printf ( "ret value %s  list key %s value %s  hash %lld count %d \n" ,hash_.Find( testerDict_[ all ] )->Value() , testerDict_[ all ] , testerWord_[ all ] , hash_.Find( testerDict_[all] )->Hash() , all );
      if ( strcmp ( hash_.Find( testerDict_[ all ] )->Value() , testerWord_[ all ] ) != 0 ) {
        fprintf ( stderr , "Word count is %d\nFailed key : %s, value : %s\n" , all , testerDict_[ all ] , testerWord_[all] );
        fprintf ( stderr , "Get result =  key : %s , value = %s\n" , hash_.Find( testerDict_[ all ] )->Key().c_str() , hash_.Find( testerDict_[ all ] )->Value()  );
        perror ( "Fail test." );
        exit ( 2 );
      }
      all--;
    }
    find_profiler.End();
    end = GetTimeOfDaySec();
    fprintf ( stderr , "All words count are %d\nAll process time is %f\nTest success.\n", count , end - start );
    {
      mocha::Profiler profiler( stderr , "str-hash-find" );
      profiler.Begin();
      if ( strcmp ( hash_.Find( testerDict_[ 1 ] )->Value() , testerWord_[ 1 ] ) != 0 ) {
        fprintf ( stderr , "Word count is %d\nFailed key : %s, value : %s\n" , words_count , testerDict_[ 1 ] , testerWord_[ 1 ] );
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
    int count = 0;
    double start,end,insert;
    start = GetTimeOfDaySec();
    mocha::Profiler insert_profiler( stderr , "boost::unordered_map::insert" );
    insert_profiler.Begin();
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
    insert_profiler.End();
    int all = all_count - 1;
    mocha::Profiler find_profiler( stderr , "boost::unordered_map::find" );
    find_profiler.Begin();
    while ( all > 0 ) {
      count++;
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
    find_profiler.End();
    end = GetTimeOfDaySec();
    fprintf ( stderr , "All words count are %d\nAll process time is %f\nTest success.\n", count , end - start );
    {
      mocha::Profiler profiler( stderr , "boost::unordered_map::find test." );
      profiler.Begin();
      boost::unordered_map<std::string,std::string>::iterator find = map_.find( testerDict_[ 0 ] );
      if ( strcmp ( find->second.c_str() , testerWord_[ 0 ] ) != 0 ) {
        fprintf ( stderr , "Word count is %d\nFailed key : %s, value : %s\n" , words_count , testerDict_[ words_count - 1 ] , testerWord_[words_count - 1] );
        perror ( "Fail test." );
        exit ( 2 );
      }
      profiler.End();
    }
  }

  static void RunMapTest () {
    fprintf( stderr , "Begin std::map test.\n" );
    int index = words_count;
    int value_index = value_count;
    int all_count = 0;
    int count = 0;
    double start,end,insert;
    start = GetTimeOfDaySec();
    mocha::Profiler insert_profiler( stderr , "std::map::insert" );
    insert_profiler.Begin();
    while ( index > 0 ) {
      
      if ( map2_.find( word_list[index] ) == map2_.end() ) {
        //printf ( "key %s value %s count %d \n" , word_list[index] , value_list[value_index] , all_count );
        
        map2_.insert( std::pair<const char*,const char*>( word_list[index] , value_list[value_index] ) );
        
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
    insert_profiler.End();
    int all = all_count - 1;
    mocha::Profiler find_profiler( stderr , "std::map::find" );
    find_profiler.Begin();
    while ( all > 0 ) {
      count++;
      //insert = GetTimeOfDaySec();
      std::map<std::string,std::string>::iterator find = map2_.find( testerDict_[ all ] );
      if ( strcmp ( find->second.c_str() , testerWord_[ all ] ) != 0 ) {
        fprintf ( stderr , "Word count is %d\nFailed key : %s, value : %s\n" , all , testerDict_[ all ] , testerWord_[all] );
        perror ( "Fail test." );
        exit ( 2 );
      }
      //double iend = GetTimeOfDaySec();
      //fprintf( stderr , "find time is %f\n" , iend - insert );
      all--;
    }
    find_profiler.End();
    end = GetTimeOfDaySec();
    fprintf ( stderr , "All words count are %d\nAll process time is %f\nTest success.\n", count , end - start );
    {
      mocha::Profiler profiler( stderr , "std::map::find test." );
      profiler.Begin();
      std::map<std::string,std::string>::iterator find = map2_.find( testerDict_[ 0 ] );
      if ( strcmp ( find->second.c_str() , testerWord_[ 0 ] ) != 0 ) {
        fprintf ( stderr , "Word count is %d\nFailed key : %s, value : %s\n" , words_count , testerDict_[ words_count - 1 ] , testerWord_[words_count - 1] );
        perror ( "Fail test." );
        exit ( 2 );
      }
      profiler.End();
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
  static std::map<std::string,std::string> map2_;
};

long long int HashAutoTester::dictCount_ = 0;
long long int HashAutoTester::wordCount_ = 0;
char HashAutoTester::testerDict_[MAX_WORDS][MAX_EACH_WORD];
char HashAutoTester::testerWord_[MAX_WORDS][MAX_EACH_WORD];
char HashAutoTester::word_list[MAX_WORDS][MAX_EACH_WORD];
char HashAutoTester::value_list[MAX_WORDS][MAX_EACH_WORD];
int HashAutoTester::words_count = 0;
int HashAutoTester::value_count = 0;
mocha::StrHash<const char*> HashAutoTester::hash_;
boost::unordered_map<std::string,std::string> HashAutoTester::map_;
std::map<std::string,std::string> HashAutoTester::map2_; 
char HashAutoTester::delimiter [] = ",.;:|";


int main ( int argc , char** argv ) {
  if ( argc < 3 ) {
    
    printf ( "%s\n", "Usage: HashAutoTester [dict file] [word file]" );
    return 0;
  } else {
    //mocha::StrHash<const char*> hash;
    /*for ( int i = 0; i < 100; i++ ) {
      char tmp[100];
      sprintf( tmp , "%dabcdefg%d" , i , i );
      char ret[100];
      sprintf( ret , "%dxxx%d" , i , i );
      hash.Insert( tmp , ret );
    }
    for ( int i = 0; i < 100; i++ ) {
      char tmp[100];
      sprintf( tmp , "%dabcdefg%d" , i , i );
      mocha::StrHash<const char*>::HashEntry entry = hash.Find( tmp );
      if ( !entry->IsEmpty() ) {
        printf( "%s\n" , hash.Find( tmp )->Value() );
      }
      }*/
    HashAutoTester::cacheWord( argv[ 1 ] , argv[ 2 ] );
    HashAutoTester::RunBoostTest();
    //HashAutoTester::RunMapTest();
    HashAutoTester::RunSrtTest();
  }
  return 0;
}


