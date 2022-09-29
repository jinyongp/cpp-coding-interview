#include <iostream>
#include <list>
using namespace std;

template <typename T>
void PrintList(const list<T>& lst) {
  auto print = [](int n) { cout << n << ' '; };
  for_each(lst.begin(), lst.end(), print);
  cout << endl;
}

int main() {
  list<int> lst{3, 5, 7};

  lst.push_back(9);
  lst.push_front(1);
  PrintList(lst);  // 1 3 5 7 9

  auto iter = lst.begin();  // insert를 하기 위해선 iterator를 사용해야 한다.
  advance(iter, 2);

  iter = lst.insert(iter, 4);
  PrintList(lst);  // 1 3 4 5 7 9

  lst.remove(5);
  PrintList(lst);  // 1 3 4 7 9

  return 0;
}
