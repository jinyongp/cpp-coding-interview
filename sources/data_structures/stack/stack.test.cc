#include "stack.h"

#include <gtest/gtest.h>

#include "stack.hint.h"
#include "stack.interface.h"

class StackTest : public ::testing::Test {
 protected:
  StackInterface<int, 3>* stack;

  void SetUp() override {
    stack = new Stack<int, 3>();
    const char* is_dev = std::getenv("DEV");
    if (is_dev && std::string(is_dev) == "true") {
      stack = new _Stack<int, 3>();
    } else {
      stack = new Stack<int, 3>();
    }
  }

  void TearDown() override {
    delete stack;
  }

  void MakeFull() {
    for (int i = 1; !stack->Full(); ++i) stack->Push(i);
  }
};

TEST_F(StackTest, Push) {
  EXPECT_NO_THROW(stack->Push(1));
  ASSERT_FALSE(stack->Empty()) << "항목이 추가되어야 합니다.";
  EXPECT_NO_THROW(stack->Push(2));
  EXPECT_NO_THROW(stack->Push(3));
  ASSERT_THROW(stack->Push(4), std::out_of_range)
      << "최대 크기를 벗어나 항목을 추가하면 에러가 발생해야 합니다.\n"
      << "hint: throw std::out_of_range(\"description\");";
}

TEST_F(StackTest, Pop) {
  MakeFull();

  EXPECT_NO_THROW(stack->Pop());  // 3
  ASSERT_EQ(stack->Top(), 2) << "가장 나중에 넣은 항목을 먼저 출력해야 합니다.";

  EXPECT_NO_THROW(stack->Pop());  // 2
  EXPECT_NO_THROW(stack->Pop());  // 1
  ASSERT_THROW(stack->Pop(), std::out_of_range)
      << "비어있을 때 항목을 출력하면 에러가 발생해야 합니다."
      << "hint: throw std::out_of_range(\"description\");";
}

TEST_F(StackTest, Top) {
  ASSERT_THROW(stack->Top(), std::out_of_range)
      << "비어있을 때 항목을 조회하면 에러가 발생해야 합니다.\n"
      << "hint: throw std::out_of_range(\"description\");";
  stack->Push(1);
  stack->Push(2);
  ASSERT_EQ(stack->Top(), 2) << "가장 나중에 넣은 항목을 조회합니다.";
  stack->Push(3);
  ASSERT_EQ(stack->Top(), 3) << "가장 나중에 넣은 항목을 조회합니다.";
}

TEST_F(StackTest, Empty) {
  ASSERT_TRUE(stack->Empty());
  stack->Push(1);
  ASSERT_FALSE(stack->Empty());
}

TEST_F(StackTest, Full) {
  ASSERT_FALSE(stack->Full());
  MakeFull();
  ASSERT_TRUE(stack->Full());
}

TEST_F(StackTest, Clear) {
  MakeFull();
  stack->Clear();
  ASSERT_TRUE(stack->Empty());
  ASSERT_FALSE(stack->Full());
}
