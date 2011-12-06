#include <stdio.h>
#include <stdlib.h>
#include <bootstrap/interactions/interaction.h>
#include <bootstrap/runners/observer_runner.h>

namespace mocha {

void Interaction::Begin () {
  while (true) {
    char buffer[500];
    fprintf( stderr , "mocha > " );
    char* str = fgets(buffer, 500, stdin);
    int len = strlen( str );
    if ( len > 1 ) {
      str[ len - 1 ] = '\0';
      commands_.Exec( buffer );
    }
  }
}

Commands Interaction::commands_;
}
