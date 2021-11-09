#include <iostream>
#include <stack>
using namespace std;

int main() {
  stack<int> s;

  s.push(2);
  s.push(15);
  s.push(10);

  while (!s.empty()) {
    cout << s.top() << ' ';  // 10 15 2
    s.pop();  // 주의! 반환 없이 단순히 제거만 한다.
  }

  return 0;
}
