[← Data Stucture Theory](../README.md)

# Linked List <kbd>[Pass Me - Singly](../../../sources/data_structures/linked_list/SinglyLinkedList.h)</kbd>

> 메모리 상에 따로 떨어진 공간에 존재하는 데이터가 연결된 상태로 존재하는 자료구조이다.

## Singly Linked List

### 단일 연결 리스트의 특징

- 데이터과 포인터를 가진 노드로 구성되어 있다.
- 노드의 포인터는 다음 노드를 참조한다.
- 각 노드가 메모리 상에 불연속적으로 위치해 있어서 맨 앞의 노드(head)부터 차례대로 탐색해야 한다. 즉, 인덱스로 상수 시간 내에 접근이 불가능하다.
- 위치에 무관하게 데이터를 삽입/삭제하기 쉽다.

## Doubly Linked List

### 이중 연결 리스트의 특징

- 단일 연결 리스트와 달리 각 노드가 양방향으로 연결되어 있다.
- 노드의 두 포인터는 각각 앞의 노드와 뒤의 노드를 참조한다.

## Circular Linked List

### 원형 연결 리스트의 특징

- 단일 연결 리스트와 달리 맨 끝에 위치한 노드의 포인터가 null을 참조하는 것이 아닌 맨 앞의 노드를 참조한다.
- 맨 앞의 노드가 시작점이자 가장 마지막을 나타내는 노드가 된다.

## 연결 리스트의 사용

```cpp
#include <list>

int main() {
  list<int> lst{3, 5, 7};

  lst.push_back(9);
  lst.push_front(1);
  // lst {1, 3, 5, 7, 9}

  auto iter = lst.begin(); // insert를 하기 위해선 iterator를 사용해야 한다.
  advance(iter, 2);

  iter = lst.insert(iter, 4);
  // lst {1, 3, 4, 5, 7, 9}

  lst.remove(5);
  // lst {1, 3, 4, 7, 9}

  return 0;
}
```

- STL에서 주어지는 [`list` 라이브러리](https://en.cppreference.com/w/cpp/container/list)를 사용한다. 양방향 연결 리스트로 구현되어 있다.
- 위치가 어디든 데이터의 삽입과 삭제를 상수 시간에 할 수 있다. 다만, 인덱스를 통한 접근은 불가능하고 iterator를 사용해야 한다.
