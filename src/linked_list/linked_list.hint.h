#ifndef LINKED_LIST_HINT_H_
#define LINKED_LIST_HINT_H_

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
    Node* new_node = new Node{item, nullptr};

    if (IsEmpty()) {
      head_ = tail_ = new_node;
    } else {
      tail_->next = new_node;
      tail_ = new_node;
    }

    size_ += 1;
  }

  void Remove(const T& item) override {
    if (IsEmpty()) {
      throw std::underflow_error("List is empty");
    }

    Node* current = head_;
    Node* previous = nullptr;

    while (current != nullptr && current->data != item) {
      previous = current;
      current = current->next;
    }

    if (current == nullptr) {
      return;
    }

    if (current == head_) {
      head_ = head_->next;
    } else {
      previous->next = current->next;
    }

    if (current == tail_) {
      tail_ = previous;
    }

    delete current;
    size_ -= 1;
  }

  T Front() const override {
    if (IsEmpty()) {
      throw std::underflow_error("List is empty");
    }

    return head_->data;
  }

  T Back() const override {
    if (IsEmpty()) {
      throw std::underflow_error("List is empty");
    }

    return tail_->data;
  }

  bool IsEmpty() const override {
    return size_ == 0;
  }

  size_t Size() const override {
    return size_;
  }

  void Clear() override {
    while (!IsEmpty()) {
      Remove(Front());
    }
  }
};

#endif  // LINKED_LIST_HINT_H_
