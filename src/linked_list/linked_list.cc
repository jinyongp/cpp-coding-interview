#include <iostream>
#include <list>

int main() {
  std::list<int> list;

  list.push_back(1);
  list.push_back(2);
  list.push_back(3);

  while (!list.empty()) {
    std::cout << list.front() << std::endl;  // 1 2 3
    list.pop_front();
  }

  return 0;
}
