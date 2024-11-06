#ifndef UTILS_H
#define UTILS_H

#include <exception>
#include <string>

class todo : public std::exception {
 private:
  std::string message;

 public:
  todo(const std::string& message = "") : message(message.empty() ? "todo" : message) {}

  const char* what() const noexcept override {
    return message.c_str();
  }
};

inline bool is_dev() {
  const char* dev = std::getenv("DEV");
  return dev && std::string(dev) == "true";
}

#endif  // UTILS_H
