#include <deque>
#include <iostream>
using namespace std;

int main() {
  deque<int> d;

  d.push_front(1);   // 1
  d.push_front(10);  // 10 1
  d.push_back(3);    // 10 1 3
  d.push_back(5);    // 10 1 3 5

  cout << d.back() << endl;  // 5
  d.pop_back();
  cout << d.front() << endl;  // 10
  d.pop_front();
  cout << d.back() << endl;  // 3
  d.pop_back();
  cout << d.front() << endl;  // 1
  d.pop_front();

  return 0;
}
