#include <iostream>
#include <vector>
using namespace std;

int main() {
  // 정적 배열
  int arr[5]{1, 2, 3, 4, 5};

  // 동적 배열
  vector<int> vec{1, 2, 3, 4, 5};
  vec.pop_back();    // 5
  vec.pop_back();    // 4
  vec.push_back(6);  // {1, 2, 3, 6}
  vec.push_back(7);  // {1, 2, 3, 6, 7}

  // 동적 할당을 이용한 방법
  int size = 5;
  int *d_arr = new int[size]{1, 2, 3, 4, 5};

  // 일일이 메모리를 해제해야 하는 것이 번거로우므로 사용을 자제한다.
  delete[] d_arr;

  return 0;
}
