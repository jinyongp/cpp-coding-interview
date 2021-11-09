#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
  queue<int> q;

  q.push(2);
  q.push(15);
  q.push(10);

  cout << q.front() << endl;  // 2
  cout << q.back() << endl;   // 10

  while (!q.empty()) {
    cout << q.front() << ' ';  // 2 15 10
    q.pop();
  }
  cout << endl;

  return 0;
}
