#include "stack.h"

#include <gtest/gtest.h>

#include "stack.hint.h"

class stack : public ::testing::Test {
 protected:
  StackInterface<int, 3>* s0_;

  void SetUp() override {
    if (is_dev()) {
      s0_ = new _Stack<int, 3>();
    } else {
      s0_ = new Stack<int, 3>();
    }
  }

  void TearDown() override {
    delete s0_;
  }

  void MakeFull() {
    for (int i = 1; !s0_->Full(); ++i) {
      s0_->Push(i);
    }
  }
};

TEST_F(stack, Push) {
  EXPECT_NO_THROW(s0_->Push(1));
  ASSERT_FALSE(s0_->Empty()) << "항목이 추가되어야 합니다.";
  EXPECT_NO_THROW(s0_->Push(2));
  EXPECT_NO_THROW(s0_->Push(3));
  ASSERT_THROW(s0_->Push(4), std::out_of_range) << "최대 크기를 벗어나 항목을 추가하면 에러가 발생해야 합니다.\n"
                                                << "hint: throw std::out_of_range(\"description\");";
}

TEST_F(stack, Pop) {
  MakeFull();

  EXPECT_NO_THROW(s0_->Pop());  // 3
  ASSERT_EQ(s0_->Top(), 2) << "가장 나중에 넣은 항목을 먼저 출력해야 합니다.";

  EXPECT_NO_THROW(s0_->Pop());  // 2
  EXPECT_NO_THROW(s0_->Pop());  // 1
  ASSERT_THROW(s0_->Pop(), std::out_of_range) << "비어있을 때 항목을 출력하면 에러가 발생해야 합니다."
                                              << "hint: throw std::out_of_range(\"description\");";
}

TEST_F(stack, Top) {
  ASSERT_THROW(s0_->Top(), std::out_of_range) << "비어있을 때 항목을 조회하면 에러가 발생해야 합니다.\n"
                                              << "hint: throw std::out_of_range(\"description\");";
  s0_->Push(1);
  s0_->Push(2);
  ASSERT_EQ(s0_->Top(), 2) << "가장 나중에 넣은 항목을 조회합니다.";
  s0_->Push(3);
  ASSERT_EQ(s0_->Top(), 3) << "가장 나중에 넣은 항목을 조회합니다.";
}

TEST_F(stack, Empty) {
  ASSERT_TRUE(s0_->Empty());
  s0_->Push(1);
  ASSERT_FALSE(s0_->Empty());
}

TEST_F(stack, Full) {
  ASSERT_FALSE(s0_->Full());
  MakeFull();
  ASSERT_TRUE(s0_->Full());
}

TEST_F(stack, Clear) {
  MakeFull();
  s0_->Clear();
  ASSERT_TRUE(s0_->Empty());
  ASSERT_FALSE(s0_->Full());
}
