#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "linked_list.interface.h"
#include "utils.h"

template <typename T>
class LinkedList : public LinkedListInterface<T> {
 private:
  struct Node {
    T data;
    Node* next;
  };

  Node* head_;
  Node* tail_;
  size_t size_;

 public:
  LinkedList() {}

  ~LinkedList() {
    Clear();
  }

  void Insert(const T& item) override {
    throw utils::todo("링크드 리스트에 항목을 추가해야 합니다.");
  }

  void Remove(const T& item) override {
    throw utils::todo("링크드 리스트에서 항목을 제거해야 합니다.");
  }

  T Front() const override {
    throw utils::todo("링크드 리스트의 첫 번째 항목을 반환해야 합니다. 비어있는 리스트에서 호출하면 에러가 발생해야 합니다.");
  }

  T Back() const override {
    throw utils::todo("링크드 리스트의 마지막 항목을 반환해야 합니다. 비어있는 리스트에서 호출하면 에러가 발생해야 합니다.");
  }

  bool IsEmpty() const override {
    throw utils::todo("링크드 리스트가 비었는지 여부를 반환해야 합니다.");
  }

  size_t Size() const override {
    throw utils::todo("링크드 리스트의 요소 개수를 반환해야 합니다.");
  }

  void Clear() override {
    throw utils::todo("링크드 리스트의 모든 항목을 지워야 합니다.");
  }
};

#endif  // LINKED_LIST_H_
