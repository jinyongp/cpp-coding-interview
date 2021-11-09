#if !defined(GRAPH_MATRIX_H_)
#define GRAPH_MATRIX_H_

#include <iostream>
#include <sstream>
#include <utility>
#include <vector>

class GraphMatrix {
 private:
  size_t v_;
  std::vector<std::vector<bool>> matrix_;

 public:
  /**
  * 그래프를 생성한다.
  *
  * @param v 정점의 수
  */
  GraphMatrix(size_t v) : v_{v} {
    matrix_.resize(v, std::vector<bool>(v, false));
  }

  /**
   * 그래프를 생성한다.
   *
   * @param v 정점의 수
   * @param edges 간선 목록
   */
  GraphMatrix(size_t v, std::vector<std::pair<size_t, size_t>> edges) : v_{v} {
    matrix_.resize(v, std::vector<bool>(v, false));
    for (const auto& edge : edges) AddEdge(edge.first, edge.second);
  }

  /**
   * 간선을 추가한다.
   *
   * @param from
   * @param to
   * @exception out_of_range 범위를 벗어난 입력을 하면 에러가 발생한다.
   */
  void AddEdge(size_t from, size_t to) {
    if ((from < 0 or from >= v_) or (to < 0 or to >= v_))
      throw std::out_of_range("out of range");
    matrix_[from][to] = true;
    matrix_[to][from] = true;
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
    matrix_[from][to] = false;
    matrix_[to][from] = false;
  }

  /**
   * 그래프를 출력한다.
   *
   * @param out
   * @param graph
   * @return std::ostream&
   */
  friend std::ostream& operator<<(std::ostream& out, const GraphMatrix& graph) {
    out << "strict Graph G {\n";
    for (size_t i = 0; i < graph.v_; ++i) {
      out << "\t" << i << " -- { ";
      for (size_t j = 0; j < graph.v_; ++j) {
        bool connect = graph.matrix_[i][j];
        if (connect) out << j << ' ';
      }
      out << "}\n";
    }
    out << "}\n";
    return out;
  }
};

#endif  // GRAPH_MATRIX_H_
