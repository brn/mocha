#include <stdio.h>
#include <stdlib.h>
#include <mocha/bootstrap/interactions/interaction.h>
#include <mocha/bootstrap/runners/observer_runner.h>

namespace mocha {

void Interaction::Begin () {
  while (1) {
    char buffer[500];
    fprintf(stderr, "mocha > ");
    char* str = fgets(buffer, 500, stdin);
    int len = strlen(str);
    if (len > 1) {
      str[ len - 1 ] = '\0';
      commands_.Exec(buffer);
      if (is_end_) {
        if (commands_.IsObserving()) {
          commands_.Exec("unobserve");
        }
        break;
      }
    }
  }
}

bool Interaction::is_end_ = false;
Commands Interaction::commands_;
}
