#if !defined(CIRCULAR_QUEUE_H_)
#define CIRCULAR_QUEUE_H_

#include <iostream>

/**
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
  CircularQueue() {}

  /**
   * 큐에 항목을 추가한다.
   *
   * @param item 추가할 항목
   * @exception out_of_range 큐가 가득 찼을 때 호출하면 에러가 발생한다.
   */
  void Enqueue(const Object& item) {
    // TODO: 코드 작성
  }

  /**
   * 큐에서 항목을 제거한다.
   *
   */
  void Dequeue() {
    // TODO: 코드 작성
  }

  /**
   * 가장 예전에 입력한 데이터를 반환한다.
   *
   * @return Object
   * @exception out_of_range 큐가 비었을 때 호출하면 에러가 발생한다.
   */
  Object Front() const {
    // TODO: 코드 작성
    return Object{};
  }

  /**
   * 가장 최근에 입력한 데이터를 반환한다.
   *
   * @return Object
   * @exception out_of_range 큐가 비었을 때 호출하면 에러가 발생한다.
   */
  Object Back() {
    // TODO: 코드 작성
    return Object{};
  }

  /**
   * 큐가 비었는지 여부를 반환한다.
   *
   * @return bool
   */
  bool Empty() const {
    // TODO: 코드 작성
    return true;
  }

  /**
   * 큐가 가득 찼는지 여부를 반환한다.
   *
   * @return bool
   */
  bool Full() const {
    // TODO: 코드 작성
    return true;
  }

  /**
   * 큐를 비운다.
   */
  void Clear() {
    // TODO: 코드 작성
  }
};

#endif  // CIRCULAR_QUEUE_H_
