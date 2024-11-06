#include "stack.h"

#include <gtest/gtest.h>

#include "stack.hint.h"

class stack : public ::testing::Test {
 protected:
  StackInterface<int, 3>* s0_;
  StackInterface<utils::dummy, 3>* s1_;

  void SetUp() override {
    if (utils::is_dev()) {
      s0_ = new _Stack<int, 3>();
      s1_ = new _Stack<utils::dummy, 3>();
    } else {
      s0_ = new Stack<int, 3>();
      s1_ = new Stack<utils::dummy, 3>();
    }
  }

  void TearDown() override {
    delete s0_;
    delete s1_;
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
  utils::range({.count = 3}, [this](int i) { s0_->Push(i); });  // 0 1 2

  EXPECT_NO_THROW(s0_->Pop());  // 2
  ASSERT_EQ(s0_->Top(), 1) << "가장 나중에 넣은 항목을 먼저 출력해야 합니다.";

  EXPECT_NO_THROW(s0_->Pop());  // 1
  EXPECT_NO_THROW(s0_->Pop());  // 0
  ASSERT_THROW(s0_->Pop(), std::out_of_range) << "비어있을 때 항목을 출력하면 에러가 발생해야 합니다."
                                              << "hint: throw std::out_of_range(\"description\");";
}

TEST_F(stack, Top) {
  ASSERT_THROW(s0_->Top(), std::out_of_range) << "비어있을 때 항목을 조회하면 에러가 발생해야 합니다.\n"
                                              << "hint: throw std::out_of_range(\"description\");";
  s0_->Push(1);
  ASSERT_EQ(s0_->Top(), 1) << "가장 나중에 넣은 항목을 조회합니다.";
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

  utils::range({.count = 3}, [this](int i) { s0_->Push(i); });
  ASSERT_TRUE(s0_->Full());
}

TEST_F(stack, Clear) {
  s0_->Push(0);

  s0_->Clear();
  ASSERT_TRUE(s0_->Empty());
  ASSERT_FALSE(s0_->Full());
}

TEST_F(stack, Reference) {
  loop(2) {
    utils::range({.count = 3}, [this](int i) { s1_->Push(utils::dummy{i}); });
    ASSERT_TRUE(s1_->Full());

    ASSERT_EQ(s1_->Top().value, 2) << "가장 나중에 넣은 항목을 조회합니다.";
    s1_->Pop();  // 2
    ASSERT_EQ(s1_->Top().value, 1) << "Pop 함수를 호출하면 가장 최근에 넣은 항목을 제거합니다.";
    s1_->Pop();  // 1
    ASSERT_EQ(s1_->Top().value, 0) << "Pop 함수를 호출하면 가장 최근에 넣은 항목을 제거합니다.";
    s1_->Pop();  // 0

    ASSERT_TRUE(s1_->Empty()) << "모든 항목을 제거하면 스택이 비어있어야 합니다.";
    ASSERT_THROW(s1_->Pop(), std::out_of_range);
    ASSERT_THROW(s1_->Top(), std::out_of_range);

    s1_->Push(utils::dummy{3});
    ASSERT_EQ(s1_->Top().value, 3) << "가장 나중에 넣은 항목을 조회합니다.";

    s1_->Clear();
    ASSERT_TRUE(s1_->Empty()) << "Clear 함수를 호출하면 스택이 비어있어야 합니다.";
  }
}
