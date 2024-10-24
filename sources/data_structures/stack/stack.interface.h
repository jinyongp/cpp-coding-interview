#ifndef STACK_INTERFACE_H_
#define STACK_INTERFACE_H_

#include <cstddef>

template <typename T, size_t SIZE>
class StackInterface {
 public:
  virtual ~StackInterface() = default;
  virtual void Push(const T &item) = 0;
  virtual void Pop() = 0;
  virtual T Top() const = 0;
  virtual bool Empty() const = 0;
  virtual bool Full() const = 0;
  virtual void Clear() = 0;
};

#endif  // STACK_INTERFACE_H_