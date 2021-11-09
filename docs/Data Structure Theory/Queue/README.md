[← Data Stucture Theory](../README.md)

# Queue <kbd>[Pass Me - Circular](../../../sources/data-structure/queue/CircularQueue.h)</kbd>

## Linear Queue

>선입선출의 데이터 관리 정책을 따르는 자료구조이다.

### 선형 큐의 특징

- 일반적인 큐를 말할 때, 선형 큐를 의미한다.
- 먼저 입력된 데이터가 가장 먼저 출력된다.
- 가장 먼저 입력된 데이터에만 접근 가능하고, 중간에 위치한 데이터에는 접근할 수 없다.
- 데이터를 입력하는 행위를 `enqueue`, 출력하는 행위를 `dequeue`라고 한다.
- 선형 큐에서 `enqueue`와 `dequeue`를 반복하다보면, 큐의 맨 마지막 항목을 가리키는 곳(`rear`)이 큐의 마지막에 위치한다면 더 이상 아이템을 추가할 수 없다는 문제점이 존재한다.

  ```text
  front는 첫 항목, rear는 마지막 항목을 참조하고 있다.

  front -> |item1|item2|item3|     | <- rear : enqueue item1, item2, item3
  front -> |     |     |item3|     | <- rear : dequeue item1, item2
  front -> |     |     |item3|item4| <- rear : enqueue item4
  front -> |     |     |item3|item4| <- rear : ❗️cannot enqueue item anymore
  ```

### 큐의 사용

```cpp
#include <queue>

void main() {
  queue<int> q; // int 타입의 데이터를 저장하는 큐를 생성한다.

  q.push(2); // 큐 q에 데이터를 입력한다.
  q.push(15);
  q.push(10);

  cout << q.front() << endl; // 2 출력. 가장 먼저 넣은 데이터가 출력된다.
  cout << q.back() << endl; // 10 출력. 가장 나중에 넣은 데이터가 출력된다.

  while (!q.empty()) {
    cout << q.front() << ' ';  // 2 15 10
    q.pop();
  }
}
```

- STL에서 주어지는 [`queue` 라이브러리](https://en.cppreference.com/w/cpp/container/queue)를 사용한다. 큐의 최대 크기를 걱정할 필요가 없다.
- c++에서 queue의 메서드는 명칭이 약간 다르기 때문에 주의한다.

## Circular Queue

>선형 큐의 문제점을 해결하기 위한 자료구조이다.

### 원형 큐의 특징

- `rear`가 참조하는 항목이 큐의 마지막에 위치하더라도 `head` 항목 뒤에 여유 공간이 있다면, 큐의 맨 앞부터 다시 항목을 추가한다.
- 빈 공간을 생각할 필요 없이 계속해서 항목을 추가하고 삭제할 수 있다는 장점이 있다. (최대 항목에 도달하면 삽입은 불가능하다.)

## Priority Queue

> 항목마다 우선순위를 매겨 더 높은 우선순위를 가진 항목을 출력한다.

### 우선순위 큐의 특징

- 우선순위가 높은 항목이 있다면, 들어온 순서에 상관없이 해당 항목을 먼저 출력한다.(보통 매개져 있는 우선순위의 숫자가 낮을수록 높다.)
- 우선순위가 동일하다면 일반적인 큐의 선입선출 정책을 따른다.
- 일반적으로 [힙](../Heap/README.md)을 이용해 구현한다.

### 우선순위 큐의 사용

```cpp
#include <queue>

void main() {
  priority_queue<int> pq; // int 타입의 데이터를 저장하는 우선순위 큐를 생성한다.

  pq.push(5);
  pq.push(2);
  pq.push(7);

  while (!pq.empty()) {
    cout << pq.top() << ' ';  // 7 5 2
    pq.pop();
  }
}
```

- STL에서 주어지는 [`priority_queue` 라이브러리](https://en.cppreference.com/w/cpp/container/priority_queue)를 사용한다.
- 비교가 가능한 항목을 저장할 수 있으며, 기본적으로 비교해서 더 큰 경우 높은 우선순위를 부여한다. (최대 힙)
- 비교 함수를 재정의하여 우선순위를 변경할 수 있다. [예제](./priority_queue.cc)

## Deque (Double-ended Queue)
> 스택과 큐의 특성을 모두 따르는 자료구조이다.

### 덱의 특징

- 전단(front), 후단(back)으로 나뉘어 양방향 모두 삽입과 삭제가 가능하다.
- 스택과 큐와 마찬가지로 중간에 값을 삽입하거나 삭제할 수 없다.

### 덱의 사용

```cpp
#include <deque>

void main() {
  deque<int> d;

  d.push_front(1);   // 1
  d.push_front(10);  // 10 1
  d.push_back(5);    // 10 1 5

  d.pop_back(); // 5
  d.pop_front(); // 10
  d.pop_front(); // 1
}
```

- STL에서 주어지는 [`deque` 라이브러리](https://en.cppreference.com/w/cpp/container/deque)를 사용한다.
- `operator[]`가 정의되어 있어 인덱스를 통해 값을 가져올 수 있다.
