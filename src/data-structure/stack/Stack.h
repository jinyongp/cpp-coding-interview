#ifndef STACK_H_
#define STACK_H_

#include <iostream>

template <typename Object, size_t SIZE>
class Stack {
 private:
  Object stack_[SIZE];  // 항목이 저장될 공간
  int top_;             // 가장 마지막에 넣은 항목을 참조

 public:
  /**
   * 새로운 스택 객체를 생성한다.
   */
  Stack() {}

  /**
   * 스택에 항목을 추가한다.
   *
   * @param item 추가할 항목
   * @return bool 성공 여부
   * @exception out_of_range 스택이 가득 찼을 때 호출하면 에러가 발생한다.
   */
  void push(const Object &item) {
    // TODO: 코드 작성
  }

  /**
   * 스택에서 항목을 제거한다.
   *
   * @return bool 성공 여부
   * @exception out_of_range 스택이 비어있을 때 호출하면 에러가 발생한다.
   */
  void pop() {
    // TODO: 코드 작성
  }

  /**
   * 가장 마지막에 입력한 항목을 반환한다.
   *
   * @return Object
   * @exception out_of_range 비어있는 스택에서 호출하면 에러를 발생한다.
   */
  Object top() const {
    // TODO: 코드 작성
    return Object{};
  }

  /**
   * 스택이 비었는지 여부를 반환한다.
   *
   * @return bool
   */
  bool empty() const {
    // TODO: 코드 작성
    return false;
  }

  /**
   * 스택이 가득 찼는지 여부를 반환한다.
   *
   * @return bool
   */
  bool full() const {
    // TODO: 코드 작성
    return false;
  }

  /**
   * 스택을 비운다.
   */
  void clear() {
    // TODO: 코드 작성
  }
};

#endif  // !STACK_H_