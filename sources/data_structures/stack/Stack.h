#ifndef STACK_H_
#define STACK_H_

#include <iostream>

#include "interfaces/StackInterface.h"

/**
 * @tparam T 항목 유형
 * @tparam SIZE 스택의 최대 크기
 */
template <typename T, size_t SIZE>
class Stack : public StackInterface<T, SIZE> {
 private:
  T stack_[SIZE];  // 항목을 저장할 공간
  int top_;        // 가장 최근에 입력한 항목을 참조

 public:
  /**
   * 새로운 스택 객체를 생성한다.
   */
  Stack() {}

  /**
   * 스택에 항목을 추가한다.
   *
   * @param item 추가할 항목
   * @exception out_of_range 스택이 가득 찼을 때 호출하면 에러가 발생한다.
   */
  void Push(const T &item) {
    // TODO: 코드 작성
  }

  /**
   * 스택에서 항목을 제거한다.
   *
   * @exception out_of_range 스택이 비어있을 때 호출하면 에러가 발생한다.
   */
  void Pop() {
    // TODO: 코드 작성
  }

  /**
   * 가장 마지막에 입력한 항목을 반환한다.
   *
   * @return T
   * @exception out_of_range 비어있는 스택에서 호출하면 에러를 발생한다.
   */
  T Top() const {
    // TODO: 코드 작성
    return T{};
  }

  /**
   * 스택이 비었는지 여부를 반환한다.
   *
   * @return bool
   */
  bool Empty() const {
    // TODO: 코드 작성
    return true;
  }

  /**
   * 스택이 가득 찼는지 여부를 반환한다.
   *
   * @return bool
   */
  bool Full() const {
    // TODO: 코드 작성
    return true;
  }

  /**
   * 스택을 비운다.
   */
  void Clear() {
    // TODO: 코드 작성
  }
};

#endif  // !STACK_H_