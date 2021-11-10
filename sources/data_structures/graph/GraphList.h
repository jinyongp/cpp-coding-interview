#if !defined(GRAPH_LIST_H_)
#define GRAPH_LIST_H_

#include <iostream>
#include <list>
#include <utility>
#include <vector>

class GraphList {
 private:
  size_t v_;
  std::vector<std::list<size_t>> list_;

  /**
   * list_[n]에 t의 포함 여부를 반환한다.
   *
   * @param n
   * @param t
   * @return bool
   */
  bool contain(size_t n, size_t t) const {
    return std::find(list_[n].begin(), list_[n].end(), t) != list_[n].end();
  }

 public:
  /**
  * 그래프를 생성한다.
  *
  * @param v 정점의 수
  */
  GraphList(size_t v) : v_{v} {
    // TODO: 코드 작성
  }

  /**
   * 그래프를 생성한다.
   *
   * @param v 정점의 수
   * @param edges 간선 목록
   */
  GraphList(size_t v, std::list<std::pair<size_t, size_t>> edges) : v_{v} {
    // TODO: 코드 작성
  }

  /**
   * 간선을 추가한다.
   *
   * @param from
   * @param to
   * @exception out_of_range 범위를 벗어난 입력을 하면 에러가 발생한다.
   */
  void AddEdge(size_t from, size_t to) {
    // TODO: 코드 작성
  }

  /**
   * 간선을 제거한다.
   *
   * @param from
   * @param to
   * @exception out_of_range 범위를 벗어난 입력을 하면 에러가 발생한다.
   */
  void RemoveEdge(size_t from, size_t to) {
    // TODO: 코드 작성
  }

  /**
   * 그래프를 출력한다.
   *
   * @param out
   * @param graph
   * @return std::ostream&
   */
  friend std::ostream& operator<<(std::ostream& out, const GraphList& graph) {
    out << "strict Graph G {\n";
    for (size_t i = 0; i < graph.v_; ++i) {
      out << "\t" << i << " -- { ";
      auto iter = graph.list_[i].begin();
      auto end = graph.list_[i].end();
      for (; iter != end; ++iter) {
        out << *iter << ' ';
      }
      out << "}\n";
    }
    out << "}\n";
    return out;
  }
};

#endif  // GRAPH_LIST_H_
