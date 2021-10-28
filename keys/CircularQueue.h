#if !defined(CIRCULAR_QUEUE_H_)
#define CIRCULAR_QUEUE_H_

#include <cstddef>
#include <stdexcept>

/**
 * EXAMPLE: SIZE{5}(+1)
 * Create  |     |     |     |     |     |     | -> front_: -1, rear: -1
 * Enqueue |item1|     |     |     |     |     | -> front_: 0, rear: 1
 * Enqueue |item1|item2|     |     |     |     | -> front_: 0, rear: 2
 * Enqueue |item1|item2|item3|     |     |     | -> front_: 0, rear: 3
 * Enqueue |item1|item2|item3|item4|     |     | -> front_: 0, rear: 4
 * Enqueue |item1|item2|item3|item4|item5|     | -> front_: 0, rear: 5 (Full)
 * Dequeue |     |item2|item3|item4|item5|     | -> front_: 1, rear: 5
 * Dequeue |     |     |item3|item4|item5|     | -> front_: 2, rear: 5
 * Dequeue |     |     |     |item4|item5|     | -> front_: 3, rear: 5
 * Enqueue |     |     |     |item4|item5|item6| -> front_: 3, rear: 0
 * Enqueue |item7|     |     |item4|item5|item6| -> front_: 3, rear: 1
 * Enqueue |item7|item8|     |item4|item5|item6| -> front_: 3, rear: 2 (Full)
 * Dequeue |item7|item8|     |     |item5|item6| -> front_: 4, rear: 2
 * Dequeue |item7|item8|     |     |     |item6| -> front_: 5, rear: 2
 * Dequeue |item7|item8|     |     |     |     | -> front_: 0, rear: 2
 * Dequeue |     |item8|     |     |     |     | -> front_: 1, rear: 2
 * Dequeue |     |     |     |     |     |     | -> front_: -1, rear: -1 (Empty)
 *
 * @tparam Object 항목 유형
 * @tparam SIZE 큐의 최대 크기
 */
template <typename Object, size_t SIZE>
class CircularQueue {
 private:
  Object queue_[SIZE + 1];  // 항목을 저장할 공간
  int front_;               // 가장 먼저 입력한 항목을 참조
  int rear_;                // 가장 나중에 입력한 항목을 참조
  int size_;                // 저장한 항목 수

 public:
  /**
   * 새로운 원형 큐 객체를 생성한다.
   */
  CircularQueue() : front_{-1}, rear_{-1}, size_{0} {}

  /**
   * 큐에 항목을 추가한다.
   *
   * @param item 추가할 항목
   * @exception out_of_range 큐가 가득 찼을 때 호출하면 에러가 발생한다.
   */
  void Enqueue(const Object& item) {
    if (Full()) throw std::out_of_range("queue is full");
    if (Empty()) front_ = rear_ = 0;
    queue_[rear_] = item;

    if (rear_ == SIZE) rear_ = 0;
    else rear_ += 1;
    size_ += 1;
  }

  /**
   * 큐에서 항목을 제거한다.
   *
   */
  void Dequeue() {
    if (Empty()) throw std::out_of_range("queue is empty");
    if (++front_ == rear_) front_ = rear_ = -1;
    size_ -= 1;
  }

  /**
   * 가장 예전에 입력한 데이터를 반환한다.
   *
   * @return Object
   * @exception out_of_range 큐가 비었을 때 호출하면 에러가 발생한다.
   */
  Object Front() const {
    if (Empty()) throw std::out_of_range("queue is empty");
    return queue_[front_];
  }

  /**
   * 가장 최근에 입력한 데이터를 반환한다.
   *
   * @return Object
   * @exception out_of_range 큐가 비었을 때 호출하면 에러가 발생한다.
   */
  Object Back() {
    if (Empty()) throw std::out_of_range("queue is empty");
    return queue_[(rear_ ? rear_ - 1 : SIZE)];
  }

  /**
   * 큐가 비었는지 여부를 반환한다.
   *
   * @return bool
   */
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

  /**
   * 큐를 비운다.
   */
  void Clear() {
    front_ = rear_ = -1;
    size_ = 0;
  }
};

#endif  // CIRCULAR_QUEUE_H_
