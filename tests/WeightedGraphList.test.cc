// #include "../keys/WeightedGraphList.h"
#include "../sources/data_structures/graph/WeightedGraphList.h"

#include <gtest/gtest.h>

#include <sstream>

class GraphListTest : public ::testing::Test {
 protected:
  WeightedGraphList wgl0_{5};
  std::stringstream out;
};

TEST_F(GraphListTest, Constructor) {
  WeightedGraphList wgl1{3};

  out << wgl1;
  std::cout << wgl1;
  ASSERT_EQ(out.str(), "strict Graph G {\n}\n");

  WeightedGraphList wgl2{5, {{1, 0, 5}, {2, 3, 2}, {3, 0, 1}, {1, 2, 3}}};

  out.str("");
  out.clear();
  out << wgl2;
  std::cout << wgl2;
  ASSERT_EQ(out.str(),
            "strict Graph G {\n"
            "\t0 -- 1 [label=5]\n"
            "\t0 -- 3 [label=1]\n"
            "\t1 -- 0 [label=5]\n"
            "\t1 -- 2 [label=3]\n"
            "\t2 -- 3 [label=2]\n"
            "\t2 -- 1 [label=3]\n"
            "\t3 -- 2 [label=2]\n"
            "\t3 -- 0 [label=1]\n"
            "}\n");
}

TEST_F(GraphListTest, AddEdge) {
  ASSERT_NO_THROW(wgl0_.AddEdge(2, 3, 2));
  EXPECT_NO_THROW(wgl0_.AddEdge(0, 3, 5));
  EXPECT_NO_THROW(wgl0_.AddEdge(4, 1, 0));
  EXPECT_NO_THROW(wgl0_.AddEdge(2, 1, 1));
  EXPECT_NO_THROW(wgl0_.AddEdge(4, 2, 9));
  EXPECT_NO_THROW(wgl0_.AddEdge(0, 1, 10));

  out << wgl0_;
  std::cout << wgl0_;
  ASSERT_EQ(out.str(),
            "strict Graph G {\n"
            "\t0 -- 3 [label=5]\n"
            "\t0 -- 1 [label=10]\n"
            "\t1 -- 4 [label=0]\n"
            "\t1 -- 2 [label=1]\n"
            "\t1 -- 0 [label=10]\n"
            "\t2 -- 3 [label=2]\n"
            "\t2 -- 1 [label=1]\n"
            "\t2 -- 4 [label=9]\n"
            "\t3 -- 2 [label=2]\n"
            "\t3 -- 0 [label=5]\n"
            "\t4 -- 1 [label=0]\n"
            "\t4 -- 2 [label=9]\n"
            "}\n");

  EXPECT_THROW(wgl0_.AddEdge(0, 5, 1), std::out_of_range)
      << "범위를 벗어난 입력을 받으면 에러가 발생해야 합니다.";
  EXPECT_THROW(wgl0_.AddEdge(-1, 3, 1), std::out_of_range)
      << "범위를 벗어난 입력을 받으면 에러가 발생해야 합니다.";
  EXPECT_THROW(wgl0_.AddEdge(-1, 6, 1), std::out_of_range);
}

TEST_F(GraphListTest, RemoveEdge) {
  EXPECT_NO_THROW(wgl0_.AddEdge(0, 3, 5));
  EXPECT_NO_THROW(wgl0_.AddEdge(3, 1, 0));
  EXPECT_NO_THROW(wgl0_.AddEdge(0, 1, 10));

  out << wgl0_;
  std::cout << wgl0_;
  ASSERT_EQ(out.str(),
            "strict Graph G {\n"
            "\t0 -- 3 [label=5]\n"
            "\t0 -- 1 [label=10]\n"
            "\t1 -- 3 [label=0]\n"
            "\t1 -- 0 [label=10]\n"
            "\t3 -- 0 [label=5]\n"
            "\t3 -- 1 [label=0]\n"
            "}\n");

  EXPECT_NO_THROW(wgl0_.RemoveEdge(1, 3));

  out.str("");
  out.clear();
  out << wgl0_;
  std::cout << wgl0_;
  ASSERT_EQ(out.str(),
            "strict Graph G {\n"
            "\t0 -- 3 [label=5]\n"
            "\t0 -- 1 [label=10]\n"
            "\t1 -- 0 [label=10]\n"
            "\t3 -- 0 [label=5]\n"
            "}\n");

  EXPECT_NO_THROW(wgl0_.RemoveEdge(0, 1));
  ASSERT_NO_THROW(wgl0_.RemoveEdge(0, 2))
      << "존재하지 않는 간선을 삭제하더라도 에러가 발생하지 않아야 합니다.";
  EXPECT_NO_THROW(wgl0_.RemoveEdge(0, 3));

  out.str("");
  out.clear();
  out << wgl0_;
  std::cout << wgl0_;
  ASSERT_EQ(out.str(), "strict Graph G {\n}\n");

  EXPECT_THROW(wgl0_.RemoveEdge(0, 5), std::out_of_range)
      << "범위를 벗어난 입력을 받으면 에러가 발생해야 합니다.";
  EXPECT_THROW(wgl0_.RemoveEdge(-1, 3), std::out_of_range)
      << "범위를 벗어난 입력을 받으면 에러가 발생해야 합니다.";
  EXPECT_THROW(wgl0_.RemoveEdge(-1, 6), std::out_of_range);
}