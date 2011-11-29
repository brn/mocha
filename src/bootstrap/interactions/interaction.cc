#include <stdio.h>
#include <stdlib.h>
#include <bootstrap/interactions/interaction.h>
#include <bootstrap/runners/observer_runner.h>

namespace mocha {

void Interaction::Begin () {
BEGIN :
  char buf[500];
  fprintf( stderr , "mocha > " );
  scanf( "%499[^\n]%*[^\n]", buf );
  getchar();
  fflush(stdin);
  commands_.Exec( buf );
  goto BEGIN;
}

Commands Interaction::commands_;
}
