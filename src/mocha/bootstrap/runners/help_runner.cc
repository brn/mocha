#include <stdio.h>
#include <mocha/bootstrap/runners/help_runner.h>

namespace mocha {

HelpRunner::HelpRunner(Options* option) : ICommandLineRunner(option) {}

void HelpRunner::Run() {
  fprintf(stderr, "Usage: mocha [watch] [unwatch] [exit] [help]\n"
          "Options:\n"
          " watch : Watch the files that is descripted in watch.xml.\n"
          " unwatch : Unwatch the files, if watch command is running.\n"
          " list : Show watching xml and javascript file list."
          " help : Show help.\n");
}

}
