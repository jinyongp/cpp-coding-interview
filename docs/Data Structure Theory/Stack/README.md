[← Data Stucture Theory](../README.md)

# Stack <kbd>[Pass Me](../../../sources/data-structure/stack/Stack.h)</kbd>

> 선입후출의 데이터 관리 정책을 따르는 자료구조이다.
## 스택의 특징

- 먼저 입력된 데이터는 가장 나중에 출력된다.
- 가장 나중에 입력한 데이터에만 접근 가능하고, 중간에 위치한 데이터에는 접근할 수 없다.
- 데이터를 입력하는 행위를 `push`, 출력하는 행위를 `pop`이라고 한다.

## 스택의 사용

```cpp
#include <stack>

void main() {
  stack<int> s; // int 타입의 데이터를 저장하는 스택을 생성한다.

  s.push(2); // 스택 s에 데이터를 입력한다.
  s.push(15);
  s.push(10);

  cout << s.top() << endl; // 10 출력. 스택 s에 가장 마지막에 추가한 데이터를 가져온다.

  while (!s.empty()) {
    cout << s.top() << ' ';  // 10 15 2
    s.pop();  // 주의! 반환 없이 단순히 제거만 한다.
  }
}
```

- STL에서 주어지는 [`stack` 라이브러리](https://en.cppreference.com/w/cpp/container/stack)를 사용한다. [스택의 최대 크기를 걱정할 필요가 없다.](https://stackoverflow.com/q/1825964/9735184)
- `pop()` 메서드는 반환값을 가지지 않는다. 단순히 최상단의 값을 제거할 뿐이다.
- 스택의 최상단 값을 확인하고 싶다면 `top()` 메서드를 호출한다. `top()` 메서드는 최상단의 값을 반환할 뿐 제거하지 않는다.
