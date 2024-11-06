#include <gtest/gtest.h>

#ifdef DEV
#include "queue.hint.h"
#else
#include "queue.h"
#endif

class queue : public ::testing::Test {
 protected:
  QueueInterface<int, 3>* q0_;

  void SetUp() override {
    q0_ = new Queue<int, 3>();
  }

  void TearDown() override {
    delete q0_;
  }
};

TEST_F(queue, Enqueue) {
  EXPECT_NO_THROW(q0_->Enqueue(1));
  ASSERT_FALSE(q0_->IsEmpty()) << "항목이 추가되어야 합니다.";
  EXPECT_NO_THROW(q0_->Enqueue(2));
  EXPECT_NO_THROW(q0_->Enqueue(3));
  ASSERT_THROW(q0_->Enqueue(4), std::overflow_error) << "최대 크기를 벗어나 항목을 추가하면 에러가 발생해야 합니다.\n"
                                                     << "hint: throw std::overflow_error(\"description\");";
}

TEST_F(queue, Dequeue) {
  times(3) q0_->Enqueue(i);  // 0 1 2

  EXPECT_NO_THROW(q0_->Dequeue());  // 0
  ASSERT_EQ(q0_->Front(), 1) << "가장 먼저 넣은 항목을 먼저 출력해야 합니다.";

  EXPECT_NO_THROW(q0_->Dequeue());  // 1
  EXPECT_NO_THROW(q0_->Dequeue());  // 2
  ASSERT_THROW(q0_->Dequeue(), std::underflow_error) << "비어있을 때 항목을 제거하면 에러가 발생해야 합니다.\n"
                                                     << "hint: throw std::underflow_error(\"description\");";
}

TEST_F(queue, Front) {
  ASSERT_THROW(q0_->Front(), std::underflow_error) << "비어있을 때 항목을 조회하면 에러가 발생해야 합니다.\n"
                                                   << "hint: throw std::underflow_error(\"description\");";
  q0_->Enqueue(1);
  ASSERT_EQ(q0_->Front(), 1) << "가장 먼저 넣은 항목을 조회합니다.";
  q0_->Enqueue(2);
  ASSERT_EQ(q0_->Front(), 1) << "가장 먼저 넣은 항목을 조회합니다.";
  q0_->Enqueue(3);
  ASSERT_EQ(q0_->Front(), 1) << "가장 먼저 넣은 항목을 조회합니다.";
}

TEST_F(queue, Rear) {
  ASSERT_THROW(q0_->Rear(), std::underflow_error) << "비어있을 때 항목을 조회하면 에러가 발생해야 합니다.\n"
                                                  << "hint: throw std::underflow_error(\"description\");";
  q0_->Enqueue(1);
  ASSERT_EQ(q0_->Rear(), 1) << "가장 나중에 넣은 항목을 조회합니다.";
  q0_->Enqueue(2);
  ASSERT_EQ(q0_->Rear(), 2) << "가장 나중에 넣은 항목을 조회합니다.";
  q0_->Enqueue(3);
  ASSERT_EQ(q0_->Rear(), 3) << "가장 나중에 넣은 항목을 조회합니다.";
}

TEST_F(queue, IsEmpty) {
  ASSERT_TRUE(q0_->IsEmpty());
  q0_->Enqueue(1);
  ASSERT_FALSE(q0_->IsEmpty());
}

TEST_F(queue, IsFull) {
  ASSERT_FALSE(q0_->IsFull());

  times(3) q0_->Enqueue(i);
  ASSERT_TRUE(q0_->IsFull());
}

TEST_F(queue, Size) {
  times(3) {
    q0_->Enqueue(i);
    ASSERT_EQ(q0_->Size(), i + 1) << "항목을 추가할 때마다 크기가 증가해야 합니다.";
  }

  q0_->Clear();
  ASSERT_EQ(q0_->Size(), 0) << "모든 항목을 제거하면 크기가 0이어야 합니다.";
}

TEST_F(queue, Clear) {
  q0_->Enqueue(0);

  q0_->Clear();
  ASSERT_TRUE(q0_->IsEmpty());
  ASSERT_FALSE(q0_->IsFull());
}

TEST_F(queue, Reference) {
  times(2) {
    auto q = new Queue<utils::dummy, 3>();

    times(3) {
      q->Enqueue(utils::dummy{i});
      ASSERT_EQ(q->Rear().value, i) << "가장 나중에 넣은 항목을 조회합니다.";
      ASSERT_EQ(q->Size(), i + 1) << "항목을 추가할 때마다 크기가 증가해야 합니다.";
    }

    ASSERT_THROW(q->Enqueue(utils::dummy{0}), std::overflow_error);
    ASSERT_TRUE(q->IsFull());

    ASSERT_EQ(q->Front().value, 0) << "가장 먼저 넣은 항목을 조회합니다.";
    q->Dequeue();  // 0
    ASSERT_EQ(q->Front().value, 1) << "Dequeue 함수를 호출하면 가장 먼저 넣은 항목을 제거합니다.";
    q->Dequeue();  // 1
    ASSERT_EQ(q->Front().value, 2) << "Dequeue 함수를 호출하면 가장 먼저 넣은 항목을 제거합니다.";
    q->Dequeue();  // 2

    ASSERT_TRUE(q->IsEmpty()) << "모든 항목을 제거하면 큐가 비어있어야 합니다.";
    ASSERT_THROW(q->Dequeue(), std::underflow_error);
    ASSERT_THROW(q->Front(), std::underflow_error);

    q->Enqueue(utils::dummy{3});
    ASSERT_EQ(q->Front().value, 3) << "가장 먼저 넣은 항목을 조회합니다.";

    q->Clear();
    ASSERT_TRUE(q->IsEmpty()) << "Clear 함수를 호출하면 큐가 비어있어야 합니다.";

    delete q;
  }
}
