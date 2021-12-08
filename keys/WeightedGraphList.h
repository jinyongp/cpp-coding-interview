#if !defined(WEIGHTED_GRAPH_LIST_H_)
#define WEIGHTED_GRAPH_LIST_H_

#include <iostream>
#include <list>
#include <tuple>
#include <utility>
#include <vector>

/**
 * 무방향 가중치 그래프 (인접 리스트)
 */
class WeightedGraphList {
 private:
  typedef std::pair<size_t, size_t> Edge;              // <to, weight>
  typedef std::tuple<size_t, size_t, size_t> EdgeAll;  // <from, to, weight>
  typedef std::list<Edge> Edges;
  typedef std::vector<std::list<Edge>> AdjacencyList;

  size_t v_;            // 정점의 수
  AdjacencyList list_;  // 그래프 인접 리스트 pair<노드, 가중치>

  /**
   * list_[n]에 t의 포함 여부를 반환한다.
   *
   * @param n
   * @param t
   * @return bool
   */
  bool contain(size_t n, size_t t) const {
    auto begin = list_[n].begin(), end = list_[n].end();
    auto compare = [t](const Edge& edge) { return std::get<0>(edge) == t; };
    return std::find_if(begin, end, compare) != end;
  }

 public:
  /**
  * 그래프를 생성한다.
  *
  * @param v 정점의 수
  */
  WeightedGraphList(size_t v) : v_{v} {
    list_.resize(v, Edges{});
  }

  /**
   * 그래프를 생성한다.
   *
   * @param v 정점의 수
   * @param edges 간선 목록
   */
  WeightedGraphList(size_t v, std::list<EdgeAll> edges) : v_{v} {
    list_.resize(v, Edges{});

    size_t from, to, weight;
    for (const auto& edge : edges) {
      auto [from, to, weight] = edge;  // C++17 Structured Binding
      AddEdge(from, to, weight);
    }
  }

  /**
   * 간선을 추가한다.
   *
   * @param from
   * @param to
   * @exception out_of_range 범위를 벗어난 입력을 하면 에러가 발생한다.
   */
  void AddEdge(size_t from, size_t to, size_t weight) {
    if ((from < 0 or from >= v_) or (to < 0 or to >= v_))
      throw std::out_of_range("out of range");

    if (!contain(from, to)) list_[from].push_back({to, weight});
    if (!contain(to, from)) list_[to].push_back({from, weight});
  }

  /**
   * 간선을 제거한다.
   *
   * @param from
   * @param to
   * @exception out_of_range 범위를 벗어난 입력을 하면 에러가 발생한다.
   */
  void RemoveEdge(size_t from, size_t to) {
    if ((from < 0 or from >= v_) or (to < 0 or to >= v_))
      throw std::out_of_range("out of range");

    list_[from].remove_if(
        [to](const Edge& edge) { return std::get<0>(edge) == to; });
    list_[to].remove_if(
        [from](const Edge& edge) { return std::get<0>(edge) == from; });
  }

  /**
   * 그래프를 출력한다.
   *
   * @param out
   * @param graph
   * @return std::ostream&
   */
  friend std::ostream& operator<<(std::ostream& out,
                                  const WeightedGraphList& graph) {
    out << "strict Graph G {\n";
    for (size_t i = 0; i < graph.v_; ++i) {
      auto iter = graph.list_[i].begin();
      auto end = graph.list_[i].end();
      for (; iter != end; ++iter) {
        out << "\t" << i << " -- ";
        out << std::get<0>(*iter) << " [label=";
        out << std::get<1>(*iter) << "]\n";
      }
    }
    out << "}\n";
    return out;
  }
};

#endif  // WEIGHTED_GRAPH_LIST_H_
