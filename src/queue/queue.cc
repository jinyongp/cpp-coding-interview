#include <iostream>
#include <queue>

using namespace std;

int main() {
  queue<int> q;

  q.push(1);
  q.push(2);
  q.push(3);

  while (!q.empty()) {
    cout << q.front() << endl;  // 1 2 3
    q.pop();                    // 주의! 반환 없이 단순히 제거만 한다.
  }

  return 0;
}
