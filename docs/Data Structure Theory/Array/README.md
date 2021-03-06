[← Data Stucture Theory](../README.md)

# Array

> 데이터를 나열하고, 각 데이터를 인덱스에 대응하도록 구성한 자료구조이다.

## 배열의 특징

- 동일한 종류의 데이터를 효율적으로 관리하기 위해 사용한다.
- 인덱스 번호를 통한 빠른 데이터 접근이 가능하다.
  - 데이터가 순차적으로 저장되어 있다.
  - 첫 데이터를 기준(index: 0)으로 매겨져 있는 **인덱스 번호**를 통해 접근한다.
- 최대 크기가 고정되어 있어, 데이터 추가 및 삭제가 어렵다.

## 정적 배열의 사용

```cpp
const size_t SIZE = 10; // 배열의 최대 크기

void main() {
  int arr[SIZE]; // int 타입의 데이터를 SIZE 크기만큼 가지는 배열을 생성한다.
  // ... 배열 초기화 코드를 작성한다.
}
```

정적 배열은 처음 생성할 때 크기가 고정되어 있고 변경할 수 없다. 실제 데이터의 크기를 가늠할 수 없을 때, 영역이 부족하거나 혹은 너무 과하여 낭비될 수 있다. 그러므로, 데이터의 크기가 확실한 상황일 때 사용한다.

## 동적 배열의 사용

```cpp
#include <vector>

void main() {
  vector<int> vec; // int 타입의 데이터를 여러 개 가질 수 있는 배열을 생성한다.
  // ... 배열 초기화 코드를 작성한다.
}
```

C++ STL Container 중 하나인 vector를 주로 동적 배열로써 활용한다. 동적 배열은 정적 배열과 달리 데이터의 삽입과 삭제가 자유롭다. 그러므로, 데이터의 크기를 가늠하기 어려울 때 사용한다.
