#ifndef STACK_INTERFACE_H_
#define STACK_INTERFACE_H_

#include <cstddef>

/// @brief 스택 인터페이스를 정의하는 추상 기본 클래스.
///
/// @tparam T 스택에 저장되는 요소의 타입.
/// @tparam SIZE 스택의 최대 크기.
template <typename T, size_t SIZE>
class StackInterface {
 public:
  /// @brief 기본 생성자.
  StackInterface() = default;

  /// @brief 가상 소멸자.
  virtual ~StackInterface() = default;

  /// @brief 스택에 항목을 푸시합니다.
  /// @param item 스택에 푸시할 항목.
  /// @throw std::overflow_error 스택이 가득 차 있을 때.
  virtual void Push(const T &item) = 0;

  /// @brief 스택에서 항목을 팝합니다.
  /// @throw std::underflow_error 스택이 비어 있을 때.
  virtual void Pop() = 0;

  /// @brief 스택의 맨 위 항목을 가져옵니다.
  /// @return 스택의 맨 위 항목.
  /// @throw std::underflow_error 스택이 비어 있을 때.
  virtual T Peek() const = 0;

  /// @brief 스택이 비어 있는지 확인합니다.
  /// @return 스택이 비어 있으면 true, 그렇지 않으면 false.
  virtual bool IsEmpty() const = 0;

  /// @brief 스택이 가득 찼는지 확인합니다.
  /// @return 스택이 가득 찼으면 true, 그렇지 않으면 false.
  virtual bool IsFull() const = 0;

  /// @brief 스택의 요소 개수를 반환합니다.
  /// @return 스택의 요소 개수.
  virtual size_t Size() const = 0;

  /// @brief 스택의 모든 항목을 지웁니다.
  virtual void Clear() = 0;
};

#endif  // STACK_INTERFACE_H_
