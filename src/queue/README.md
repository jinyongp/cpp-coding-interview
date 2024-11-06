# Queue <kbd>[Pass Me](./queue.h)</kbd>

> 선입선출의 데이터 관리 정책을 따르는 자료구조이다.

## 큐의 특징

- 먼저 입력된 데이터는 가장 먼저 출력된다.
- 가장 먼저 입력한 데이터에만 접근 가능하고, 중간에 위치한 데이터에는 접근할 수 없다.
- 데이터를 입력하는 행위를 `push` 또는 `enqueue`, 출력하는 행위를 `pop` 또는 `dequeue`라고 한다.

## 큐의 사용

[Example Code](./queue.cc)

- STL에서 주어지는 [`queue` 라이브러리](https://en.cppreference.com/w/cpp/container/queue)를 사용한다.
- `pop()` 메서드는 반환값을 가지지 않는다. 단순히 최전단의 값을 제거할 뿐이다.
- 큐의 최전단 값을 확인하고 싶다면 `front()` 메서드를 호출한다. `front()` 메서드는 최전단의 값을 반환할 뿐 제거하지 않는다.
