#include <stdio.h>
#include <mocha/shell/shell.h>
#include <mocha/bootstrap/runners/help_runner.h>

namespace mocha {

HelpRunner::HelpRunner(Options* option) : ICommandLineRunner(option) {}

void HelpRunner::Run() {
  Shell* shell = Shell::GetInstance();
  shell->Break(false);
  shell->Print("Usage: [command]\n"
               "options:\n"
               " watch : Watch the files that is descripted in watch.xml.\n"
               " unwatch : Unwatch the files, if watch command is running.\n"
               " list : Show watching xml and javascript file list."
               " help : Show help.\n"
               " exit : exit mocha.");
  shell->Break(true);
}

}
