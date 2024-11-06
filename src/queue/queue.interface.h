#ifndef QUEUE_INTERFACE_H_
#define QUEUE_INTERFACE_H_

#include <cstddef>

/// @brief 큐 인터페이스를 정의하는 추상 기본 클래스.
///
/// @tparam T 큐에 저장되는 요소의 타입.
/// @tparam SIZE 큐의 최대 크기.
template <typename T, size_t SIZE>
class QueueInterface {
 public:
  /// @brief 기본 생성자.
  QueueInterface() = default;

  /// @brief  가상 소멸자.
  virtual ~QueueInterface() = default;

  /// @brief 큐에 항목을 추가합니다.
  /// @param item 큐에 추가할 항목.
  virtual void Enqueue(const T &item) = 0;

  /// @brief 큐에서 항목을 제거합니다.
  virtual void Dequeue() = 0;

  /// @brief 큐의 맨 앞 항목을 가져옵니다.
  /// @return 큐의 맨 앞 항목.
  virtual T Front() const = 0;

  /// @brief 큐의 맨 뒤 항목을 가져옵니다.
  /// @return 큐의 맨 뒤 항목.
  virtual T Rear() const = 0;

  /// @brief 큐가 비어 있는지 확인합니다.
  /// @return 큐가 비어 있으면 true, 그렇지 않으면 false.
  virtual bool IsEmpty() const = 0;

  /// @brief 큐가 가득 찼는지 확인합니다.
  /// @return 큐가 가득 찼으면 true, 그렇지 않으면 false.
  virtual bool IsFull() const = 0;

  /// @brief 큐의 요소 개수를 반환합니다.
  /// @return 큐의 요소 개수.
  virtual size_t Size() const = 0;

  /// @brief 큐의 모든 항목을 지웁니다.
  virtual void Clear() = 0;
};

#endif  // QUEUE_INTERFACE_H_
