#include <stdio.h>
#include "help_runner.h"

namespace mocha {

HelpRunner::HelpRunner( Options* option ) : ICommandLineRunner( option ) {}

void HelpRunner::Run() {
  fprintf( stderr , "Usage: mocha [-c[--compile] source] [-w[--watch] source] [-X[--XML]]\n"
                    "           [-P[--PrettyPrint]] [-L[--Line]] [--help]\n"
           "Options:\n"
           "-c/--compile      Compile only one file in command line.\n"
           "-w/--watch        Observe file and detect changes. When file is changed run compile.\n"
           "-X/--XML          Observe xml setting file.\n"
           "-P/--PrettyPrint  Compile file as aligned format.\n"
           "-L/--Line         Embed _LINE_ property in compiled file.\n"
           "--help            Show help.\n");
  exit(0);
}

}
