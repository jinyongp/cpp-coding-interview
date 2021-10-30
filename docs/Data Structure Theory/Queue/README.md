[← Data Stucture Theory](../README.md)

# Queue

## Linear Queue

>선입선출의 데이터 관리 정책을 따르는 자료구조이다.

### 선형 큐의 특징

- 일반적인 큐를 말할 때, 선형 큐를 의미한다.
- 먼저 입력된 데이터가 가장 먼저 출력된다.
- 가장 먼저 입력된 데이터에만 접근 가능하고, 중간에 위치한 데이터에는 접근할 수 없다.
- 데이터를 입력하는 행위를 `enqueue`, 출력하는 행위를 `dequeue`라고 한다.
- 선형 큐에서 `enqueue`와 `dequeue`를 반복하다보면, 큐의 맨 마지막 항목을 가리키는 곳(`rear`)이 큐의 마지막에 위치한다면 더 이상 아이템을 추가할 수 없다는 문제점이 존재한다.

  ```
  front는 첫 항목, rear는 마지막 항목을 참조하고 있다.

  front -> |item1|item2|item3|     | <- rear : enqueue item1, item2, item3
  front -> |     |     |item3|     | <- rear : dequeue item1, item2
  front -> |     |     |item3|item4| <- rear : enqueue item4
  front -> |     |     |item3|item4| <- rear : ❗️cannot enqueue item anymore
  ```

### 선형 큐의 사용

```cpp
#include <queue>

void main() {
  queue<int> q; // int 타입의 데이터를 저장하는 큐를 생성한다.

  q.push(2); // 큐 q에 데이터를 입력한다.
	q.push(15);
  q.push(10);

  cout << q.front() << endl; // 2 출력. 가장 먼저 넣은 데이터가 출력된다.
  cout << q.back() << endl; // 10 출력. 가장 나중에 넣은 데이터가 출력된다.
}
```

- STL에서 주어지는 `queue` 라이브러리를 사용한다. 큐의 최대 크기를 걱정할 필요가 없다.
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

  pq.push()
}
```

## Deque (Double-ended Queue)
