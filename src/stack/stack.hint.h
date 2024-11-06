#ifndef STACK_H_
#define STACK_H_

#include "stack.interface.h"
#include "utils.h"

// Stack<int, 3>()
// Create |     |     |     | -> top_: -1
// Push   |item1|     |     | -> top_: 0
// Push   |item1|item2|     | -> top_: 1
// Push   |item1|item2|item3| -> top_: 2 (Full)
// Push   |item1|item2|item3| -> overflow_error
// Pop    |item1|item2|     | -> top_: 1
// Pop    |item1|     |     | -> top_: 0
// Pop    |     |     |     | -> top_: -1
// Pop    |     |     |     | -> underflow_error

template <typename T, size_t SIZE>
class Stack : public StackInterface<T, SIZE> {
 private:
  T stack_[SIZE];
  int top_;

 public:
  Stack() : top_{-1} {}

  void Push(const T &item) override {
    if (IsFull()) {
      throw std::overflow_error("stack is full");
    }

    stack_[++top_] = item;
  }

  void Pop() override {
    if (IsEmpty()) {
      throw std::underflow_error("stack is empty");
    }

    top_ -= 1;
  }

  T Peek() const override {
    if (IsEmpty()) {
      throw std::underflow_error("stack is empty");
    }

    return stack_[top_];
  }

  bool IsEmpty() const override {
    return top_ < 0;
  }

  bool IsFull() const override {
    return top_ == SIZE - 1;
  }

  size_t Size() const override {
    return top_ + 1;
  }

  void Clear() override {
    top_ = -1;
  }
};

#endif  // STACK_H_
