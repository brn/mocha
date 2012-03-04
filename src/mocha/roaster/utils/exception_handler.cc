#include <mocha/roaster/utils/exception_handler.h>

namespace mocha {

ExceptionHandle ExceptionHandler::CreateException(const char* message) {
  return ExceptionHandle(new ExceptionHandler(message));
}
ExceptionHandler::ExceptionHandler(const char* message) : error_(message) {}
ExceptionHandler::~ExceptionHandler() {}

}
