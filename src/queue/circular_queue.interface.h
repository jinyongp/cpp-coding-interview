#ifndef CIRCULAR_QUEUE_INTERFACE_H_
#define CIRCULAR_QUEUE_INTERFACE_H_

#include <cstddef>

template <typename T, size_t SIZE>
class CircularQueueInterface {
 public:
  virtual ~CircularQueueInterface() = default;
  virtual void Enqueue(const T &item) = 0;
  virtual void Dequeue() = 0;
  virtual T Front() const = 0;
  virtual T Back() const = 0;
  virtual bool Empty() const = 0;
  virtual bool Full() const = 0;
  virtual void Clear() = 0;
};

#endif  // QUEUE_INTERFACE_H_
