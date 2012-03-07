#include <string.h>
#include <mocha/misc/xml/versions.h>



namespace mocha {

static const char all[] = {"all"};
static const char none[] = {"none"};
static const char debug[] = {"debug"};

Version::Version() {
  container_.insert(std::pair<std::string,int>(all, 1));
  container_.insert(std::pair<std::string,int>(none, 1));
}

void Version::Add(const char* ver) {
  container_.insert(std::pair<std::string,int>(ver, 1));
}

bool Version::Get(const char* ver) {
  return (strcmp(ver, none) == 0)? false : container_.find(ver) != container_.end();
}

void Version::Debug() {
  container_.insert(std::pair<const char*,int>(debug, 1));
}

}
