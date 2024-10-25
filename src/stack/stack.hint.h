#ifndef _STACK_H_
#define _STACK_H_

#include <stdexcept>

#include "stack.interface.h"

/// _Stack<int, 3>()
/// Create |     |     |     | -> top_: -1
/// Push   |item1|     |     | -> top_: 0
/// Push   |item1|item2|     | -> top_: 1
/// Push   |item1|item2|item3| -> top_: 2 (Full)
/// Push   |item1|item2|item3| -> out_of_range
/// Pop    |item1|item2|     | -> top_: 1
/// Pop    |item1|     |     | -> top_: 0
/// Pop    |     |     |     | -> top_: -1
/// Pop    |     |     |     | -> out_of_range
template <typename T, size_t SIZE>
class _Stack : public StackInterface<T, SIZE> {
 private:
  T stack_[SIZE];  // 항목을 저장할 공간
  int top_;        // 가장 최근에 입력한 항목을 참조

 public:
  _Stack() : top_{-1} {}

  void Push(const T &item) {
    if (Full()) {
      throw std::out_of_range("stack is full");
    }

    stack_[++top_] = item;
  }

  void Pop() {
    if (Empty()) {
      throw std::out_of_range("stack is empty");
    }

    top_ -= 1;
  }

  T Top() const {
    if (Empty()) {
      throw std::out_of_range("stack is empty");
    }

    return stack_[top_];
  }

  bool Empty() const {
    return top_ < 0;
  }

  bool Full() const {
    return top_ == SIZE - 1;
  }

  void Clear() {
    top_ = -1;
  }
};

#endif  // _STACK_H_
