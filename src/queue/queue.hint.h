#ifndef QUEUE_H_
#define QUEUE_H_

#include "queue.interface.h"
#include "utils.h"

// Queue<int, 3>()
// Create  |     |     |     | -> front_: -1, rear_: -1
// Enqueue |item1|     |     | -> front_: 0, rear_: 0
// Enqueue |item1|item2|     | -> front_: 0, rear_: 1
// Front   |item1|item2|     | -> item1
// Rear    |item1|item2|     | -> item2
// Enqueue |item1|item2|item3| -> front_: 0, rear_: 2 (Full)
// Enqueue |item1|item2|item3| -> overflow_error
// Dequeue |     |item2|item3| -> front_: 1, rear_: 2
// Front   |     |item2|item3| -> item2
// Rear    |     |item2|item3| -> item3
// Dequeue |     |     |item3| -> front_: 2, rear_: 2
// Dequeue |     |     |     | -> front_: -1, rear_: -1
// Dequeue |     |     |     | -> underflow_error
// Front   |     |     |     | -> underflow_error
// Rear    |     |     |     | -> underflow_error

template <typename T, size_t SIZE>
class Queue : public QueueInterface<T, SIZE> {
 private:
  T queue_[SIZE];
  int front_;
  int rear_;

 public:
  Queue() : front_{-1}, rear_{-1} {}

  void Enqueue(const T &item) override {
    if (IsFull()) {
      throw std::overflow_error("Queue is full");
    }

    if (IsEmpty()) {
      front_ = 0;
    }

    rear_ = (rear_ + 1) % SIZE;
    queue_[rear_] = item;
  }

  void Dequeue() override {
    if (IsEmpty()) {
      throw std::underflow_error("Queue is empty");
    }

    if (front_ == rear_) {
      front_ = rear_ = -1;
    } else {
      front_ = (front_ + 1) % SIZE;
    }
  }

  T Front() const override {
    if (IsEmpty()) {
      throw std::underflow_error("Queue is empty");
    }

    return queue_[front_];
  }

  T Rear() const override {
    if (IsEmpty()) {
      throw std::underflow_error("Queue is empty");
    }

    return queue_[rear_];
  }

  bool IsEmpty() const override {
    return front_ == -1;
  }

  bool IsFull() const override {
    return (rear_ + 1) % SIZE == front_;
  }

  size_t Size() const override {
    if (IsEmpty()) {
      return 0;
    }

    if (rear_ >= front_) {
      return rear_ - front_ + 1;
    }

    return SIZE - front_ + rear_ + 1;
  }

  void Clear() override {
    front_ = rear_ = -1;
  }
};

#endif  // QUEUE_H_
