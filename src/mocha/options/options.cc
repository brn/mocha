#include <sstream>
#include <mocha/options/options.h>

namespace mocha {

void Options::DoAnalyzeOption(const char* argv) {
  if (strcmp(argv, "compile") == 0) {
    CommandLineCompile();
    SetFile();
  } else if (argv[ 0 ] == '-') {
    if (strlen(argv) == 2) {
      MatchOptions(argv[ 1 ]);
    } else {
      if (argv[ 1 ] == '-') {
        if (strcmp(argv, "--pretty-print") == 0) {
          PrettyPrint();
        } else if (strcmp(argv, "--file") == 0) {
          SetFile();
        } else if (strcmp(argv, "--debug") == 0) {
          Debug();
        } else if (strcmp(argv, "--compress") == 0) {
          Compress();
        } else {
          if (!IsUnmatch()) {
            Unmatch(argv);
          }
        }
      }
    }
  } else {
    path_ = argv;
    HasPath();
    if (!IsCommandLineCompile()) {
      if (!IsUnmatch()) {
        Unmatch(path_.c_str());
      }
    }
  }
}

void Options::MatchOptions(char arg) {
  switch(arg) {
    case 'c' :
      CommandLineCompile();
      SetFile();
      break;
    case 'P' :
      PrettyPrint();
      break;
    case 'D' :
      Debug();
      break;
    case 'C' :
      Compress();
      break;
    default :
      if (!IsUnmatch()) {
        std::string arg_str;
        arg_str += arg;
        Unmatch(arg_str.c_str());
      }
  }
}

void Options::UnrecognizedOption(const char* opt) {
  std::stringstream st;
  st << opt << " is unrecognized option. See help.\n";
  error_ = st.str();
}

void Options::OptionNotEnough(const char* opt) {
  fprintf(stderr, "%s require parameter\nSee mocha --help.\n", opt);
}

}
