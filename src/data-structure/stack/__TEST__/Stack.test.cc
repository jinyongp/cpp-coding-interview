#include "../Stack.h"

#include <gtest/gtest.h>

class StackTest : public ::testing::Test {
 protected:
  void SetUp() override {}

  Stack<int, 3> s0_;
};

TEST_F(StackTest, Push) {
  EXPECT_NO_THROW(s0_.push(1));
  ASSERT_FALSE(s0_.empty()) << "항목이 추가되어야 합니다.";
  EXPECT_NO_THROW(s0_.push(2));
  EXPECT_NO_THROW(s0_.push(3));
  EXPECT_THROW(s0_.push(4), std::out_of_range)
      << "스택이 가득 찼을 때 항목을 추가하면 out of range 에러를 발생해야 "
         "합니다.\n"
      << "hint: throw std::out_of_range(\"description\");";
}

TEST_F(StackTest, Top) {
  EXPECT_THROW(s0_.top(), std::out_of_range)
      << "스택이 비어있을 때 항목을 조회하면 out of range 에러를 발생해야 "
         "합니다.\n"
      << "hint: throw std::out_of_range(\"description\");";
  ASSERT_NO_THROW(s0_.push(1));
  ASSERT_NO_THROW(s0_.push(2));
  EXPECT_EQ(s0_.top(), 2) << "가장 나중에 넣은 항목을 조회합니다.";
  ASSERT_NO_THROW(s0_.push(3));
  EXPECT_EQ(s0_.top(), 3) << "가장 나중에 넣은 항목을 조회합니다.";
}

TEST_F(StackTest, Pop) {
  ASSERT_NO_THROW(s0_.push(1));
  EXPECT_NO_THROW(s0_.push(2));
  EXPECT_NO_THROW(s0_.push(3));

  EXPECT_NO_THROW(s0_.pop());  // 3
  EXPECT_EQ(s0_.top(), 2) << "가장 나중에 넣은 항목을 먼저 출력해야 합니다.";

  EXPECT_NO_THROW(s0_.pop());  // 2
  EXPECT_NO_THROW(s0_.pop());  // 1
  EXPECT_THROW(s0_.pop(), std::out_of_range)
      << "스택이 비어있을 때 항목을 제거하면 out of range 에러가 발생해야 "
         "합니다.\n"
      << "hint: throw std::out_of_range(\"description\");";
}

TEST_F(StackTest, Empty) {
  EXPECT_TRUE(s0_.empty());
  ASSERT_NO_THROW(s0_.push(1));
  EXPECT_FALSE(s0_.empty());
}

TEST_F(StackTest, Full) {
  EXPECT_FALSE(s0_.full());
  ASSERT_NO_THROW(s0_.push(1));
  ASSERT_NO_THROW(s0_.push(2));
  ASSERT_NO_THROW(s0_.push(3));
  EXPECT_TRUE(s0_.full());
}

TEST_F(StackTest, Clear) {
  ASSERT_NO_THROW(s0_.push(1));
  ASSERT_NO_THROW(s0_.push(2));
  ASSERT_NO_THROW(s0_.push(3));
  s0_.clear();
  EXPECT_TRUE(s0_.empty());
  EXPECT_FALSE(s0_.full());
}
