#ifndef UTILS_H_
#define UTILS_H_

#define times(n) for (int i = 0; i < n; i++)

#include <exception>
#include <functional>
#include <iostream>
#include <string>

namespace utils {

class todo : public std::exception {
 private:
  std::string message;

 public:
  todo(const std::string& message = "") : message(message.empty() ? "todo" : message) {}

  const char* what() const noexcept override {
    return message.c_str();
  }
};

class dummy {
 public:
  int value;

  void method() {}
  void mutate() {
    value = 1;
  }

  bool operator==(const dummy& other) const {
    return value == other.value;
  }
};

// inline bool is_dev() {
//   const char* dev = std::getenv("DEV");
//   return dev && std::string(dev) == "true";
// }

struct RangeArgs {
  int start = 0;
  int end = 0;
  int count = 0;
  int step = 1;
};

/// @brief 지정된 범위에 대해 반복하며 함수를 호출한다.
/// @param args 범위 인수
/// @param func 호출할 함수
inline void range(RangeArgs args, const std::function<void(int)>& func) {
  if (args.count > 0) {
    for (int i = 0; i < args.count; i++) {
      func(args.start + i * args.step);
    }
  } else {
    for (int i = args.start; i < args.end; i += args.step) {
      func(i);
    }
  }
}

template <typename Func, typename ReturnType = std::invoke_result_t<Func>>
auto guard(Func func) -> std::conditional_t<std::is_void_v<ReturnType>, void, std::optional<ReturnType>> {
  if constexpr (std::is_void_v<ReturnType>) {
    try {
      func();
    } catch (...) {
      // void
    }
  } else {
    try {
      return std::optional<ReturnType>(func());
    } catch (...) {
      return std::nullopt;
    }
  }
}

}  // namespace utils

#endif  // UTILS_H_
