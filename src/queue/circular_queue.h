#ifndef CIRCULAR_QUEUE_H_
#define CIRCULAR_QUEUE_H_

#include <stdexcept>

#include "circular_queue.interface.h"
#include "utils.cc"

/// @brief 원형 큐 (Circular Queue) 클래스를 구현합니다.
/// @tparam T 항목 유형
/// @tparam SIZE 큐의 최대 크기
template <typename T, size_t SIZE>
class CircularQueue : public CircularQueueInterface<T, SIZE> {
 private:
  T queue_[SIZE + 1];  // 항목을 저장할 공간
  int front_;          // 가장 먼저 입력한 항목을 참조
  int rear_;           // 가장 나중에 입력한 항목을 참조
  int size_;           // 저장한 항목 수

 public:
  /// @brief 원형 큐 객체를 생성한다.
  CircularQueue() {
    throw todo();
  }

  /// @brief 큐에 항목을 추가한다.
  /// @param item 추가할 항목
  /// @exception out_of_range 큐가 가득 찼을 때 호출하면 에러가 발생한다.
  void Enqueue(const T& item) {
    throw todo();
  }

  /// @brief 큐에서 항목을 제거한다.
  /// @exception out_of_range 큐가 비었을 때 호출하면 에러가 발생한다.
  void Dequeue() {
    throw todo();
  }

  /// @brief 가장 예전에 입력한 데이터를 반환한다.
  /// @return 큐의 가장 앞에 있는 항목
  /// @exception out_of_range 큐가 비었을 때 호출하면 에러가 발생한다.
  T Front() const {
    throw todo();
  }

  /// @brief 가장 최근에 입력한 데이터를 반환한다.
  /// @return 큐의 가장 뒤에 있는 항목
  /// @exception out_of_range 큐가 비었을 때 호출하면 에러가 발생한다.
  T Back() const {
    throw todo();
  }

  /// @brief 큐가 비었는지 여부를 반환한다.
  /// @return 큐가 비었으면 true, 그렇지 않으면 false
  bool Empty() const {
    throw todo();
  }

  /// @brief 큐가 가득 찼는지 여부를 반환한다.
  /// @return 큐가 가득 찼으면 true, 그렇지 않으면 false
  bool Full() const {
    throw todo();
  }

  /// @brief 큐를 비운다.
  void Clear() {
    throw todo();
  }
};

#endif  // CIRCULAR_QUEUE_H_
