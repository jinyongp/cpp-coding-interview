// #include "../keys/GraphMatrix.h"
#include "../sources/data-structure/graph/GraphMatrix.h"

#include <gtest/gtest.h>

#include <sstream>

class GraphMatrixTest : public ::testing::Test {
 protected:
  GraphMatrix gm0_{5};
  std::stringstream out;
};

TEST_F(GraphMatrixTest, Constructor) {
  GraphMatrix gm{4, {{1, 0}, {2, 3}, {3, 2}, {1, 2}}};

  out << gm;
  std::cout << gm;
  ASSERT_EQ(out.str(),
            "strict Graph G {\n"
            "\t0 -- { 1 }\n"
            "\t1 -- { 0 2 }\n"
            "\t2 -- { 1 3 }\n"
            "\t3 -- { 2 }\n"
            "}\n");
}

TEST_F(GraphMatrixTest, AddEdge) {
  ASSERT_NO_THROW(gm0_.AddEdge(2, 3));
  EXPECT_NO_THROW(gm0_.AddEdge(0, 3));
  EXPECT_NO_THROW(gm0_.AddEdge(4, 1));
  EXPECT_NO_THROW(gm0_.AddEdge(2, 1));
  EXPECT_NO_THROW(gm0_.AddEdge(4, 2));
  EXPECT_NO_THROW(gm0_.AddEdge(0, 1));

  out << gm0_;
  std::cout << gm0_;
  ASSERT_EQ(out.str(),
            "strict Graph G {\n"
            "\t0 -- { 1 3 }\n"
            "\t1 -- { 0 2 4 }\n"
            "\t2 -- { 1 3 4 }\n"
            "\t3 -- { 0 2 }\n"
            "\t4 -- { 1 2 }\n"
            "}\n");

  EXPECT_THROW(gm0_.AddEdge(0, 5), std::out_of_range)
      << "범위를 벗어난 입력을 받으면 에러가 발생해야 합니다.";
  EXPECT_THROW(gm0_.AddEdge(-1, 3), std::out_of_range)
      << "범위를 벗어난 입력을 받으면 에러가 발생해야 합니다.";
  EXPECT_THROW(gm0_.AddEdge(-1, 6), std::out_of_range);
}

TEST_F(GraphMatrixTest, RemoveEdge) {
  EXPECT_NO_THROW(gm0_.AddEdge(0, 3));
  EXPECT_NO_THROW(gm0_.AddEdge(3, 1));
  EXPECT_NO_THROW(gm0_.AddEdge(0, 1));

  out << gm0_;
  std::cout << gm0_;
  ASSERT_EQ(out.str(),
            "strict Graph G {\n"
            "\t0 -- { 1 3 }\n"
            "\t1 -- { 0 3 }\n"
            "\t2 -- { }\n"
            "\t3 -- { 0 1 }\n"
            "\t4 -- { }\n"
            "}\n");

  EXPECT_NO_THROW(gm0_.RemoveEdge(1, 3));

  out.str("");
  out.clear();
  out << gm0_;
  std::cout << gm0_;
  ASSERT_EQ(out.str(),
            "strict Graph G {\n"
            "\t0 -- { 1 3 }\n"
            "\t1 -- { 0 }\n"
            "\t2 -- { }\n"
            "\t3 -- { 0 }\n"
            "\t4 -- { }\n"
            "}\n");

  EXPECT_NO_THROW(gm0_.RemoveEdge(0, 1));
  ASSERT_NO_THROW(gm0_.RemoveEdge(0, 2))
      << "존재하지 않는 간선을 삭제하더라도 에러가 발생하지 않아야 합니다.";
  EXPECT_NO_THROW(gm0_.RemoveEdge(0, 3));

  out.str("");
  out.clear();
  out << gm0_;
  std::cout << gm0_;
  ASSERT_EQ(out.str(),
            "strict Graph G {\n"
            "\t0 -- { }\n"
            "\t1 -- { }\n"
            "\t2 -- { }\n"
            "\t3 -- { }\n"
            "\t4 -- { }\n"
            "}\n");

  EXPECT_THROW(gm0_.RemoveEdge(0, 5), std::out_of_range)
      << "범위를 벗어난 입력을 받으면 에러가 발생해야 합니다.";
  EXPECT_THROW(gm0_.RemoveEdge(-1, 3), std::out_of_range)
      << "범위를 벗어난 입력을 받으면 에러가 발생해야 합니다.";
  EXPECT_THROW(gm0_.RemoveEdge(-1, 6), std::out_of_range);
}