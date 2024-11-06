#ifndef LINKED_LIST_INTERFACE_H_
#define LINKED_LIST_INTERFACE_H_

#include <cstddef>

/// @brief 링크드 리스트 인터페이스를 정의하는 추상 기본 클래스.
///
/// @tparam T 링크드 리스트에 저장되는 요소의 타입.
template <typename T>
class LinkedListInterface {
 public:
  /// @brief 기본 생성자.
  LinkedListInterface() = default;

  /// @brief 가상 소멸자.
  virtual ~LinkedListInterface() = default;

  /// @brief 링크드 리스트에 항목을 추가합니다.
  /// @param item 링크드 리스트에 추가할 항목.
  virtual void Insert(const T &item) = 0;

  /// @brief 링크드 리스트에서 항목을 제거합니다.
  /// @param item 링크드 리스트에서 제거할 항목.
  virtual void Remove(const T &item) = 0;

  /// @brief 링크드 리스트의 첫 번째 항목을 가져옵니다.
  /// @return 링크드 리스트의 첫 번째 항목.
  virtual T Front() const = 0;

  /// @brief 링크드 리스트의 마지막 항목을 가져옵니다.
  /// @return 링크드 리스트의 마지막 항목.
  virtual T Back() const = 0;

  /// @brief 링크드 리스트가 비어 있는지 확인합니다.
  /// @return 링크드 리스트가 비어 있으면 true, 그렇지 않으면 false.
  virtual bool IsEmpty() const = 0;

  /// @brief 링크드 리스트의 요소 개수를 반환합니다.
  /// @return 링크드 리스트의 요소 개수.
  virtual size_t Size() const = 0;

  /// @brief 링크드 리스트의 모든 항목을 지웁니다.
  virtual void Clear() = 0;
};

#endif  // LINKED_LIST_INTERFACE_H_
