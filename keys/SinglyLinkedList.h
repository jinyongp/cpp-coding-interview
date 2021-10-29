#if !defined(SINGLY_LINKED_LIST_H_)
#define SINGLY_LINKED_LIST_H_

#include <functional>
#include <iostream>

/**
 * EXAMPLE:
 * Create : front_ -> | <- back_, size_: 0
 * Add    : front_ -> |item1| <- back_, size_: 1
 * Add    : front_ -> |item1|item2| <- back_, size_: 2
 * Add    : front_ -> |item1|item2|item3| <- back_, size_: 3
 * Add    : front_ -> |item1|item2|item3|item4| <- back_, size_: 4
 * Add    : front_ -> |item1|item2|item3|item4|item5| <- back_, size_: 5
 * Remove : front_ -> |item1|item2|item3|item4| <- back_, size_: 4
 * Remove : front_ -> |item1|item2|item4| <- back_, size_: 3
 * Remove : front_ -> |item1|item4| <- back_, size_: 3
 *
 * @tparam Object
 */
template <typename Object>
class SinglyLinkedList {
 private:
  /**
   * 연결 리스트를 구성하는 노드를 정의한다.
   */
  struct Node {
    Object value;  // 노드에 저장될 값
    Node* next;    // 다음 노드를 가리키는 포인터

    /**
     * 새로운 노드 객체를 생성한다.
     *
     * @param item 노드에 저장할 값
     */
    Node(const Object& item) : value{item}, next{nullptr} {}

    /**
     * 새로운 노드 객체를 생성한다.
     *
     * @param item 노드에 저장할 값
     * @param next 다음 노드
     */
    Node(const Object& item, Node* next) : value{item}, next{next} {}
  };

  Node* front_;  // 맨 앞 노드
  Node* back_;   // 맨 뒤 노드
  size_t size_;  // 항목 수

 public:
  /**
   * 단일 연결 리스트 객체를 생성한다.
   */
  SinglyLinkedList() : front_{nullptr}, back_{nullptr}, size_{0} {}

  /**
   * 단일 연결 리스트 객체를 삭제한다.
   */
  ~SinglyLinkedList() {
    Clear();
  }

  /**
   * 리스트의 맨 마지막에 항목을 추가한다.
   *
   * @param item
   */
  void Add(const Object& item) {
    Node* node = front_;
    Node* new_node = new Node{item};

    if (front_ == nullptr) {
      front_ = new_node;
    } else {
      while (node->next != nullptr) node = node->next;
      node->next = new_node;
    }
    back_ = new_node;
    size_ += 1;
  }

  /**
   * 리스트의 맨 마지막에 항목을 삭제한다.
   *
   * @exception out_of_range 리스트가 비어있을 때 호출하면 에러가 발생한다.
   */
  void Remove() {
    if (Empty()) throw std::out_of_range("list is empty");
    Node* prev = nullptr;
    Node* node = front_;

    if (node->next == nullptr) {
      Clear();
      return;
    }

    while (node->next != nullptr) {
      prev = node;
      node = node->next;
    }
    prev->next = nullptr;
    back_ = prev;
    delete node;
    size_ -= 1;
  }

  /**
   * 리스트로부터 해당 항목을 삭제한다.
   * 동일한 항목이 존재한다면, 앞에서 찾은 항목만 제거한다.
   * 해당 항목을 찾지 못하면 아무것도 하지 않는다.
   *
   * @param item
   * @exception out_of_range 리스트가 비어있을 때 호출하면 에러가 발생한다.
   */
  void Remove(const Object& item) {
    if (Empty()) throw std::out_of_range("list is empty");
    Node* prev = nullptr;
    Node* node = front_;

    if (node->value == item) {
      front_ = node->next;
      if (front_ == nullptr) back_ = nullptr;
      delete node;
      size_ -= 1;
      return;
    }

    bool found = false;
    while (node != nullptr) {
      if (node->value == item) {
        found = true;
        break;
      }
      prev = node;
      node = node->next;
    }
    if (found) {
      prev->next = node->next;
      if (node->next == nullptr) back_ = prev;
      delete node;
      size_ -= 1;
    }
  }

  /**
   * 리스트에 해당 항목이 존재하는지를 반환한다.
   *
   * @param item
   * @return bool
   */
  bool Contain(const Object& item) {
    Node* node = front_;
    while (node != nullptr) {
      if (node->value == item) return true;
      node = node->next;
    }
    return false;
  }

  /**
   * 리스트를 순회하며 해당 항목을 매개변수로 가지는 함수를 호출한다.
   *
   * @tparam Arg
   * @param func
   */
  void Foreach(const std::function<void(Object)>& func) {
    Node* node = front_;
    while (node != nullptr) {
      func(node->value);
      node = node->next;
    }
  }

  /**
   * 리스트의 맨 앞 항목을 반환한다.
   *
   * @return Object
   * @exception out_of_range 리스트가 비어있을 때 호출하면 에러가 발생한다.
   */
  Object Front() const {
    if (front_ == nullptr) throw std::out_of_range("list is empty");
    return front_->value;
  }

  /**
   * 리스트의 맨 뒤 항목을 반환한다.
   *
   * @return Object
   * @exception out_of_range 리스트가 비어있을 때 호출하면 에러가 발생한다.
   */
  Object Back() const {
    if (back_ == nullptr) throw std::out_of_range("list is empty");
    return back_->value;
  }

  /**
   * 리스트가 비었는지를 반환한다.
   *
   * @return bool
   */
  bool Empty() const {
    return front_ == nullptr;
  }

  /**
   * 리스트에 있는 항목의 수를 반환한다.
   *
   * @return size_t
   */
  size_t Size() const {
    return size_;
  }

  /**
   * 리스트를 비운다.
   */
  void Clear() {
    Node* node = front_;
    while (node != nullptr) {
      Node* next = node->next;
      delete node;
      node = next;
    }
    front_ = nullptr;
    back_ = nullptr;
    size_ = 0;
  }
};

#endif  // SINGLY_LINKED_LIST_H_
