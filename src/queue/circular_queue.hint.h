#ifndef _CIRCULAR_QUEUE_H_
#define _CIRCULAR_QUEUE_H_

#include <stdexcept>

#include "circular_queue.interface.h"

/// _CircularQueue<int, 5>()
/// Create  |     |     |     |     |     | -> front_: -1, rear: -1, size: 0
/// Enqueue |item1|     |     |     |     | -> front_: 0, rear: 1
/// Enqueue |item1|item2|     |     |     | -> front_: 0, rear: 2
/// Enqueue |item1|item2|item3|     |     | -> front_: 0, rear: 3
/// Enqueue |item1|item2|item3|item4|     | -> front_: 0, rear: 4
/// Dequeue |     |item2|item3|item4|     | -> front_: 1, rear: 4
/// Dequeue |     |     |item3|item4|     | -> front_: 2, rear: 4
/// Enqueue |     |     |item3|item4|item5| -> front_: 2, rear: 0
/// Enqueue |item6|     |item3|item4|item5| -> front_: 2, rear: 1
/// Enqueue |item6|item7|item3|item4|item5| -> front_: 2, rear: 2
/// Enqueue |item6|item7|item3|item4|item5| -> out_of_range
/// Dequeue |item6|item7|     |item4|item5| -> front_: 3, rear: 2
/// Dequeue |item6|item7|     |     |item5| -> front_: 4, rear: 2
/// Dequeue |item6|item7|     |     |     | -> front_: 0, rear: 2
/// Dequeue |     |item7|     |     |     | -> front_: 1, rear: 2
/// Dequeue |     |     |     |     |     | -> front_: -1, rear: -1
/// Dequeue |     |     |     |     |     | -> out_of_range
template <typename T, size_t SIZE>
class _CircularQueue : public CircularQueueInterface<T, SIZE> {
 private:
  T queue_[SIZE + 1];  // 항목을 저장할 공간
  int front_;          // 가장 먼저 입력한 항목을 참조
  int rear_;           // 가장 나중에 입력한 항목을 참조
  int size_;           // 저장한 항목 수

 public:
  _CircularQueue() : front_{-1}, rear_{-1}, size_{0} {}

  void Enqueue(const T& item) {
    if (Full()) {
      throw std::out_of_range("queue is full");
    }

    if (Empty()) {
      front_ = rear_ = 0;
    }

    queue_[rear_] = item;

    if (rear_ == SIZE) {
      rear_ = 0;
    } else {
      rear_ += 1;
    }
    size_ += 1;
  }

  void Dequeue() {
    if (Empty()) {
      throw std::out_of_range("queue is empty");
    }

    if (++front_ == rear_) {
      front_ = rear_ = -1;
    }
    size_ -= 1;
  }

  T Front() const {
    if (Empty()) {
      throw std::out_of_range("queue is empty");
    }

    return queue_[front_];
  }

  T Back() const {
    if (Empty()) {
      throw std::out_of_range("queue is empty");
    }

    return queue_[(rear_ ? rear_ - 1 : SIZE)];
  }

  bool Empty() const {
    return size_ == 0;
  }

  /**
   * 큐가 가득 찼는지 여부를 반환한다.
   *
   * @return bool
   */
  bool Full() const {
    return size_ == SIZE;
  }

  void Clear() {
    front_ = rear_ = -1;
    size_ = 0;
  }
};

#endif  // _CIRCULAR_QUEUE_H_
