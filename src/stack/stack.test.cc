#include <gtest/gtest.h>

#ifdef DEV
#include "stack.hint.h"
#else
#include "stack.h"
#endif

class stack : public ::testing::Test {
 protected:
  StackInterface<int, 3>* s0_;

  void SetUp() override {
    s0_ = new Stack<int, 3>();
  }

  void TearDown() override {
    delete s0_;
  }
};

TEST_F(stack, Push) {
  EXPECT_NO_THROW(s0_->Push(1));
  ASSERT_FALSE(s0_->IsEmpty()) << "항목이 추가되어야 합니다.";
  EXPECT_NO_THROW(s0_->Push(2));
  EXPECT_NO_THROW(s0_->Push(3));
  ASSERT_THROW(s0_->Push(4), std::overflow_error) << "최대 크기를 벗어나 항목을 추가하면 에러가 발생해야 합니다.\n"
                                                  << "hint: throw std::overflow_error(\"description\");";
}

TEST_F(stack, Pop) {
  times(3) s0_->Push(i);  // 0 1 2

  EXPECT_NO_THROW(s0_->Pop());  // 2
  ASSERT_EQ(s0_->Peek(), 1) << "가장 나중에 넣은 항목을 먼저 출력해야 합니다.";

  EXPECT_NO_THROW(s0_->Pop());  // 1
  EXPECT_NO_THROW(s0_->Pop());  // 0
  ASSERT_THROW(s0_->Pop(), std::underflow_error) << "비어있을 때 항목을 제거하면 에러가 발생해야 합니다.\n"
                                                 << "hint: throw std::underflow_error(\"description\");";
}

TEST_F(stack, Peek) {
  ASSERT_THROW(s0_->Peek(), std::underflow_error) << "비어있을 때 항목을 조회하면 에러가 발생해야 합니다.\n"
                                                  << "hint: throw std::underflow_error(\"description\");";
  s0_->Push(1);
  ASSERT_EQ(s0_->Peek(), 1) << "가장 나중에 넣은 항목을 조회합니다.";
  s0_->Push(2);
  ASSERT_EQ(s0_->Peek(), 2) << "가장 나중에 넣은 항목을 조회합니다.";
  s0_->Push(3);
  ASSERT_EQ(s0_->Peek(), 3) << "가장 나중에 넣은 항목을 조회합니다.";
}

TEST_F(stack, IsEmpty) {
  ASSERT_TRUE(s0_->IsEmpty());
  s0_->Push(1);
  ASSERT_FALSE(s0_->IsEmpty());
}

TEST_F(stack, IsFull) {
  ASSERT_FALSE(s0_->IsFull());

  times(3) s0_->Push(i);
  ASSERT_TRUE(s0_->IsFull());
}

TEST_F(stack, Size) {
  times(3) {
    s0_->Push(i);
    ASSERT_EQ(s0_->Size(), i + 1) << "항목을 추가할 때마다 크기가 증가해야 합니다.";
  }

  s0_->Clear();
  ASSERT_EQ(s0_->Size(), 0) << "모든 항목을 제거하면 크기가 0이어야 합니다.";
}

TEST_F(stack, Clear) {
  s0_->Push(0);

  s0_->Clear();
  ASSERT_TRUE(s0_->IsEmpty());
  ASSERT_FALSE(s0_->IsFull());
}

TEST_F(stack, Reference) {
  auto s = new Stack<utils::dummy, 3>();

  times(2) {
    ASSERT_TRUE(s->IsEmpty()) << "스택이 비어있어야 합니다.";
    ASSERT_FALSE(s->IsFull()) << "스택이 가득 차지 않았어야 합니다.";
    ASSERT_EQ(s->Size(), 0) << "스택이 비어있어야 합니다.";
    ASSERT_THROW(s->Peek(), std::underflow_error) << "비어있을 때 항목을 조회하면 에러가 발생해야 합니다.";
    ASSERT_THROW(s->Pop(), std::underflow_error) << "비어있을 때 항목을 제거하면 에러가 발생해야 합니다.";

    times(3) {
      ASSERT_NO_THROW(s->Push(utils::dummy{i}));
      ASSERT_EQ(s->Peek().value, i) << "가장 나중에 넣은 항목을 조회합니다.";
      ASSERT_EQ(s->Size(), i + 1) << "항목을 추가할 때마다 크기가 증가해야 합니다.";
    }  // | 0 | 1 | 2 | -> top: 2, size: 3

    ASSERT_THROW(s->Push(utils::dummy{0}), std::overflow_error);
    ASSERT_FALSE(s->IsEmpty()) << "스택이 비어있지 않아야 합니다.";
    ASSERT_TRUE(s->IsFull()) << "스택이 가득 차야 합니다.";
    ASSERT_EQ(s->Size(), 3) << "스택이 가득 찼을 때 크기는 최대 크기와 같아야 합니다.";

    times(3) {
      ASSERT_EQ(s->Peek().value, 3 - (i + 1)) << "가장 나중에 넣은 항목을 조회합니다.";
      ASSERT_EQ(s->Size(), 3 - i) << "항목을 제거할 때마다 크기가 감소해야 합니다.";
      ASSERT_NO_THROW(s->Pop());  // 2 1 0
    }

    ASSERT_TRUE(s->IsEmpty()) << "모든 항목을 제거하면 스택이 비어있어야 합니다.";
    ASSERT_FALSE(s->IsFull()) << "스택이 가득 차지 않았어야 합니다.";
    ASSERT_EQ(s->Size(), 0) << "모든 항목을 제거하면 크기가 0이어야 합니다.";
    ASSERT_THROW(s->Pop(), std::underflow_error);
    ASSERT_THROW(s->Peek(), std::underflow_error);

    times(3) s->Push(utils::dummy{i});  // 0 1 2
    ASSERT_EQ(s->Peek().value, 2) << "가장 나중에 넣은 항목을 조회합니다.";

    s->Clear();
    ASSERT_TRUE(s->IsEmpty()) << "Clear 함수를 호출하면 스택이 비어있어야 합니다.";
  }

  delete s;
}
