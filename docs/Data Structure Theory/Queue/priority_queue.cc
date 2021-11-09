#include <iostream>
#include <queue>
using namespace std;

int main() {
  // 큰 수가 높은 우선순위
  priority_queue<int> pq1;

  pq1.push(5);
  pq1.push(2);
  pq1.push(7);

  while (!pq1.empty()) {
    cout << pq1.top() << ' ';  // 7 5 2
    pq1.pop();
  }
  cout << endl;

  // 작은 수가 높은 우선순위
  priority_queue<int, vector<int>, greater<int>> pq2;

  pq2.push(5);
  pq2.push(2);
  pq2.push(7);

  while (!pq2.empty()) {
    cout << pq2.top() << ' ';  // 2 5 7
    pq2.pop();
  }
  cout << endl;

  typedef pair<char, int> Object;
  auto cmp = [](const Object& lhs, const Object& rhs) {
    if (lhs.second == rhs.second) return lhs.first > rhs.first;
    return lhs.second > rhs.second;
  };

  // 우선순위 재정의 (수가 작을수록 높은 순위, 동일한 경우 알파벳 순)
  priority_queue<Object, vector<Object>, decltype(cmp)> pq3(cmp);

  pq3.push({'C', 3});
  pq3.push({'C', 2});
  pq3.push({'A', 5});
  pq3.push({'D', 7});
  pq3.push({'A', 2});
  pq3.push({'F', 1});

  while (!pq3.empty()) {
    auto obj = pq3.top();
    cout << "[" << (char)obj.first << ", ";
    cout << obj.second << "] ";  // [F, 1] [A, 2] [C, 2] [C, 3] [A, 5] [D, 7]
    pq3.pop();
  }
  cout << endl;

  return 0;
}
