#include <iostream>
#include <stack>

using namespace std;

int main() {
  stack<int> s;

  s.push(1);
  s.push(2);
  s.push(3);

  while (!s.empty()) {
    cout << s.top() << endl;  // 3 2 1
    s.pop();                  // 주의! 반환 없이 단순히 제거만 한다.
  }

  return 0;
}
