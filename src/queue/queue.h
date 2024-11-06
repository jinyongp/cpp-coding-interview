#ifndef QUEUE_H_
#define QUEUE_H_

#include "queue.interface.h"
#include "utils.h"

template <typename T, size_t SIZE>
class Queue : public QueueInterface<T, SIZE> {
 private:
  T queue_[SIZE];  // 항목을 저장할 공간
  int front_;      // 가장 먼저 입력한 항목을 참조
  int rear_;       // 가장 나중에 입력한 항목을 참조

 public:
  Queue() : front_{0}, rear_{-1} {}

  void Enqueue(const T &item) override {
    throw utils::todo("큐에 항목을 추가해야 합니다. 큐가 가득 찼을 때 호출하면 에러가 발생해야 합니다.");
  }

  void Dequeue() override {
    throw utils::todo("큐에서 항목을 제거해야 합니다. 큐가 비어있을 때 호출하면 에러가 발생해야 합니다.");
  }

  T Front() const override {
    throw utils::todo("가장 먼저 입력한 항목을 반환해야 합니다. 비어있는 큐에서 호출하면 에러가 발생해야 합니다.");
  }

  T Rear() const override {
    throw utils::todo("가장 나중에 입력한 항목을 반환해야 합니다. 비어있는 큐에서 호출하면 에러가 발생해야 합니다.");
  }

  bool IsEmpty() const override {
    throw utils::todo("큐가 비었는지 여부를 반환해야 합니다.");
  }

  bool IsFull() const override {
    throw utils::todo("큐가 가득 찼는지 여부를 반환해야 합니다.");
  }

  size_t Size() const override {
    throw utils::todo("큐가 가지고 있는 요소의 개수를 반환해야 합니다.");
  }

  void Clear() override {
    throw utils::todo("큐를 비워야 합니다.");
  }
};

#endif  // QUEUE_H_
