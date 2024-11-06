#ifndef STACK_H_
#define STACK_H_

#include "stack.interface.h"
#include "utils.h"

template <typename T, size_t SIZE>
class Stack : public StackInterface<T, SIZE> {
 private:
  T stack_[SIZE];  // 항목을 저장할 공간
  int top_;        // 가장 최근에 입력한 항목을 참조

 public:
  Stack() : top_{-1} {}

  void Push(const T &item) override {
    throw utils::todo("스택에 항목을 추가해야 합니다. 스택이 가득 찼을 때 호출하면 에러가 발생해야 합니다.");
  }

  void Pop() override {
    throw utils::todo("스택에서 항목을 제거해야 합니다. 스택이 비어있을 때 호출하면 에러가 발생해야 합니다.");
  }

  T Peek() const override {
    throw utils::todo("가장 최근에 입력한 항목을 반환해야 합니다. 비어있는 스택에서 호출하면 에러가 발생해야 합니다.");
  }

  bool IsEmpty() const override {
    throw utils::todo("스택이 비었는지 여부를 반환해야 합니다.");
  }

  bool IsFull() const override {
    throw utils::todo("스택이 가득 찼는지 여부를 반환해야 합니다.");
  }

  size_t Size() const override {
    throw utils::todo("스택이 가지고 있는 요소의 개수를 반환해야 합니다.");
  }

  void Clear() override {
    throw utils::todo("스택을 비워야 합니다.");
  }
};

#endif  // STACK_H_
