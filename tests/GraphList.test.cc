// #include "../keys/GraphList.h"
#include "../sources/data-structure/graph/GraphList.h"

#include <gtest/gtest.h>

#include <sstream>

class GraphListTest : public ::testing::Test {
 protected:
  GraphList gl0_{5};
  std::stringstream out;
};

TEST_F(GraphListTest, Constructor) {
  GraphList gl{4, {{1, 0}, {2, 3}, {3, 2}, {1, 2}}};

  out << gl;
  std::cout << gl;
  ASSERT_EQ(out.str(),
            "strict Graph G {\n"
            "\t0 -- { 1 }\n"
            "\t1 -- { 0 2 }\n"
            "\t2 -- { 3 1 }\n"
            "\t3 -- { 2 }\n"
            "}\n");
}

TEST_F(GraphListTest, AddEdge) {
  ASSERT_NO_THROW(gl0_.AddEdge(2, 3));
  EXPECT_NO_THROW(gl0_.AddEdge(0, 3));
  EXPECT_NO_THROW(gl0_.AddEdge(4, 1));
  EXPECT_NO_THROW(gl0_.AddEdge(2, 1));
  EXPECT_NO_THROW(gl0_.AddEdge(4, 2));
  EXPECT_NO_THROW(gl0_.AddEdge(0, 1));

  out << gl0_;
  std::cout << gl0_;
  ASSERT_EQ(out.str(),
            "strict Graph G {\n"
            "\t0 -- { 3 1 }\n"
            "\t1 -- { 4 2 0 }\n"
            "\t2 -- { 3 1 4 }\n"
            "\t3 -- { 2 0 }\n"
            "\t4 -- { 1 2 }\n"
            "}\n");

  EXPECT_THROW(gl0_.AddEdge(0, 5), std::out_of_range)
      << "범위를 벗어난 입력을 받으면 에러가 발생해야 합니다.";
  EXPECT_THROW(gl0_.AddEdge(-1, 3), std::out_of_range)
      << "범위를 벗어난 입력을 받으면 에러가 발생해야 합니다.";
  EXPECT_THROW(gl0_.AddEdge(-1, 6), std::out_of_range);
}

TEST_F(GraphListTest, RemoveEdge) {
  EXPECT_NO_THROW(gl0_.AddEdge(0, 3));
  EXPECT_NO_THROW(gl0_.AddEdge(3, 1));
  EXPECT_NO_THROW(gl0_.AddEdge(0, 1));

  out << gl0_;
  std::cout << gl0_;
  ASSERT_EQ(out.str(),
            "strict Graph G {\n"
            "\t0 -- { 3 1 }\n"
            "\t1 -- { 3 0 }\n"
            "\t2 -- { }\n"
            "\t3 -- { 0 1 }\n"
            "\t4 -- { }\n"
            "}\n");

  EXPECT_NO_THROW(gl0_.RemoveEdge(1, 3));

  out.str("");
  out.clear();
  out << gl0_;
  std::cout << gl0_;
  ASSERT_EQ(out.str(),
            "strict Graph G {\n"
            "\t0 -- { 3 1 }\n"
            "\t1 -- { 0 }\n"
            "\t2 -- { }\n"
            "\t3 -- { 0 }\n"
            "\t4 -- { }\n"
            "}\n");

  EXPECT_NO_THROW(gl0_.RemoveEdge(0, 1));
  ASSERT_NO_THROW(gl0_.RemoveEdge(0, 2))
      << "존재하지 않는 간선을 삭제하더라도 에러가 발생하지 않아야 합니다.";
  EXPECT_NO_THROW(gl0_.RemoveEdge(0, 3));

  out.str("");
  out.clear();
  out << gl0_;
  std::cout << gl0_;
  ASSERT_EQ(out.str(),
            "strict Graph G {\n"
            "\t0 -- { }\n"
            "\t1 -- { }\n"
            "\t2 -- { }\n"
            "\t3 -- { }\n"
            "\t4 -- { }\n"
            "}\n");

  EXPECT_THROW(gl0_.RemoveEdge(0, 5), std::out_of_range)
      << "범위를 벗어난 입력을 받으면 에러가 발생해야 합니다.";
  EXPECT_THROW(gl0_.RemoveEdge(-1, 3), std::out_of_range)
      << "범위를 벗어난 입력을 받으면 에러가 발생해야 합니다.";
  EXPECT_THROW(gl0_.RemoveEdge(-1, 6), std::out_of_range);
}