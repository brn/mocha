
#include <stdio.h>
#include "codegen.h"

void mocha::Codegen::Write ( const char* str ) {
  result_ += str;
}

void mocha::Codegen::Write ( const char* str , long int line ) {
  WriteLine ( line );
  Write ( str );
}

void mocha::Codegen::WriteLine ( long int line ) {
  char tmp [50];
  sprintf ( tmp, "%ld", line );
  Write ( "_LINE_=" );
  Write ( tmp );
  Write ( ";" );
}



