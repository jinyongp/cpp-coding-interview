# Coding Interview

> This file was written as [Typora](https://typora.io/)

[TOC]

## Getting Started

### Prerequisites

#### Packages

프로젝트에 필요한 패키지를 설치한다.

```sh
brew install cmake clang-format
```

#### Extensions

아래 목록의 vscode extension을 설치한다.

- C/C++: `ms-vscode.cpptools`
- C++ TestMate: `matepek.vscode-catch2-test-adapter`
- Better C++ Syntax: `jeff-hykin.better-cpp-syntax`

#### Initialize Project

프로젝트를 초기화한다.

```sh
make init
```

### Implements

`src` 폴더 내, `TODO`로 작성되어 있는 부분을 채우면서 모든 테스트를 통과하도록 구현한다.

- 코드를 수정하고 테스트를 위해 , `make` 명령어를 실행한다.
- `make test` 명령어로 테스트를 확인할 수 있다. 혹은, 좌측 Testing 탭(C++ TestMate)에서 개별 테스트가 가능하다.
- `src` 폴더 내에 있는 `*.test.cc` 파일을 확인하여 어느 부분에서 문제가 있는건지 확인할 수 있다.

### Notes

- 코드의 간결함을 위해 `#include <iostream>`와 같은 라이브러리 및 `using namespace std;` 작성을 생략한다.

## Data Structure Theory

### Array

> 데이터를 나열하고, 각 데이터를 인덱스에 대응하도록 구성한 자료구조이다.

#### 배열의 특징

- 동일한 종류의 데이터를 효율적으로 관리하기 위해 사용한다.
- 인덱스 번호를 통한 빠른 데이터 접근이 가능하다.
  - 데이터가 순차적으로 저장되어 있다.
  - 첫 데이터를 기준(index: 0)으로 매겨져 있는 **인덱스 번호**를 통해 접근한다.
- 최대 크기가 고정되어 있어, 데이터 추가 및 삭제가 어렵다.

#### 정적 배열의 사용

```cpp
const size_t SIZE = 10; // 배열의 최대 크기

void main() {
  int arr[SIZE]; // int 타입의 데이터를 SIZE 크기만큼 가지는 배열을 생성한다.
  // ... 배열 초기화 코드를 작성한다.
}
```

정적 배열은 처음 생성할 때 크기가 고정되어 있고 변경할 수 없다. 실제 데이터의 크기를 가늠할 수 없을 때, 영역이 부족하거나 혹은 너무 과하여 낭비될 수 있다. 그러므로, 데이터의 크기가 확실한 상황일 때 사용한다.

#### 동적 배열의 사용

```cpp
#include <vector>

void main() {
  vector<int> vec; // int 타입의 데이터를 여러 개 가질 수 있는 배열을 생성한다.
  // ... 배열 초기화 코드를 작성한다.
}
```

동적 배열은 정적 배열과 달리 데이터의 삽입과 삭제가 자유롭다. 그러므로, 데이터의 크기를 가늠하기 어려울 때 사용한다.

### Stack

> 선입후출의 데이터 관리 정책을 따르는 자료구조이다.

#### 스택의 특징

- 먼저 입력된 데이터는 가장 나중에 출력된다.
- 가장 나중에 입력한 데이터에만 접근 가능하고, 중간에 위치한 데이터에는 접근할 수 없다.
- 데이터를 입력하는 행위를 `push`, 출력하는 행위를 `pop`이라고 한다.	  

#### 스택의 사용

```cpp
#include <stack>

void main() {
  stack<int> s; // int 타입의 데이터를 저장하는 스택을 생성한다.

  s.push(2); // 스택 s에 데이터를 입력한다.
  s.push(15);
  s.push(10);

  cout << s.top() << endl; // 10 출력. 스택 s에 가장 마지막에 추가한 데이터를 가져온다.

  s.pop(); // 스택 s에 가장 마지막에 추가된 데이터를 제거한다.
}
```

- STL에서 주어지는 `stack` 라이브러리를 사용한다. 스택의 최대 크기를 걱정할 필요가 없다.
- `pop()` 메서드는 반환값을 가지지 않는다. 단순히 최상단의 값을 제거할 뿐이다.
  스택의 최상단 값을 확인하고 싶다면 `top()` 메서드를 호출한다. `top()` 메서드 또한 최상단의 값을 반환할 뿐 제거하지 않는다.

### Queue

#### Linear Queue

>선입선출의 데이터 관리 정책을 따르는 자료구조이다.

##### 선형 큐의 특징

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

##### 선형 큐의 사용

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

#### Circular Queue

>선형 큐의 문제점을 해결하기 위한 자료구조이다.

#### 원형 큐의 특징

- `rear`가 참조하는 항목이 큐의 마지막에 위치하더라도 `head` 항목 뒤에 여유 공간이 있다면, 큐의 맨 앞부터 다시 항목을 추가한다.
- 빈 공간을 생각할 필요 없이 계속해서 항목을 추가하고 삭제할 수 있다는 장점이 있다. (최대 항목에 도달하면 삽입은 불가능하다.)

#### Priority Queue

> 항목마다 우선순위를 매겨 더 높은 우선순위를 가진 항목을 출력한다.

#### 우선순위 큐의 특징

- 우선순위가 높은 항목이 있다면, 들어온 순서에 상관없이 해당 항목을 먼저 출력한다.(보통 매개져 있는 우선순위의 숫자가 낮을수록 높다.)
- 우선순위가 동일하다면 일반적인 큐의 선입선출 정책을 따른다.
- 일반적으로 [힙](#heap)을 이용해 구현한다.

#### 우선순위 큐의 사용

```cpp
#include <queue>

void main() {
  priorty_queue<int> pq; // int 타입의 데이터를 저장하는 우선순위 큐를 생성한다.
  
  pq.push()
}
```



#### Deque (Double-ended Queue)



### Linked List



#### Singly Linked List



### Doubly Linked List



### Hash Table



#### Hash Function



#### Hash Collision



### Graph



#### Adjacency matrix



#### Adjacency List



### Tree



#### Binary Search Tree



#### Segment Tree



#### Treap



#### Trie



### Heap



### String



#### Trie



### Disjoint Set (Union-find)



## Algorithm Theory

### Time / Space Complexity Analysis



### Basic Sorting Algorithm



### Recursion



### Dynamic Programming



### Divide and conquer



### Advanced Sorting Alogrithm



### Binary Search



### BFS(Breadth First Search) / DFS(Depth First Search)



### Back Tracking



### Greedy Algorithm



### Dijksta's Algorithm



### Minimum Spanning Tree



#### Kruskal's Algorithm



#### Prim's Algorithm



## Problem Solving



### Brute Force



### Sorting Algorithm



### Binary Search



### Two Pointer



### Graph & Search



### Tree



### Topological Sort



### Shortest Path



### Dynamic Programming



## References
