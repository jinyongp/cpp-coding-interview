#include <exception>
#include <string>

class todo : public std::exception {
 private:
  std::string message;

 public:
  todo(const std::string& message = "")
      : message(message.empty() ? "TODO" : message) {}

  const char* what() const noexcept override {
    return message.c_str();
  }
};
