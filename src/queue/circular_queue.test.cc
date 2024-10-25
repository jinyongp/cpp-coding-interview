
#include "circular_queue.h"

#include <gtest/gtest.h>

#include "circular_queue.hint.h"

class circular_queue : public ::testing::Test {
 protected:
  CircularQueueInterface<int, 5>* q0_;

  void SetUp() override {
    const char* dev = std::getenv("DEV");
    if (dev && std::string(dev) == "true") {
      q0_ = new _CircularQueue<int, 5>();
    } else {
      q0_ = new CircularQueue<int, 5>();
    }
  }

  void TearDown() override {
    delete q0_;
  }

  void MakeFull() {
    for (int i = 1; !q0_->Full(); ++i) {
      q0_->Enqueue(i);
    }
  }
};

TEST_F(circular_queue, Enqueue) {
  EXPECT_NO_THROW(q0_->Enqueue(1));
  ASSERT_FALSE(q0_->Empty()) << "항목이 추가되어야 합니다.";
  EXPECT_NO_THROW(q0_->Enqueue(2));
  EXPECT_NO_THROW(q0_->Enqueue(3));
  EXPECT_NO_THROW(q0_->Enqueue(4));
  EXPECT_NO_THROW(q0_->Enqueue(5));
  ASSERT_THROW(q0_->Enqueue(6), std::out_of_range) << "최대 크기를 벗어나 항목을 추가하면 에러가 발생해야 합니다.";
}

TEST_F(circular_queue, Dequeue) {
  MakeFull();  // 1, 2, 3, 4, 5

  EXPECT_NO_THROW(q0_->Dequeue());  // 1
  ASSERT_EQ(q0_->Front(), 2) << "가장 먼저 입력한 항목을 제거해야 합니다.";
  EXPECT_NO_THROW(q0_->Dequeue());  // 2
  EXPECT_NO_THROW(q0_->Dequeue());  // 3
  ASSERT_EQ(q0_->Front(), 4) << "가장 먼저 입력한 항목을 제거해야 합니다.";
  EXPECT_NO_THROW(q0_->Dequeue());  // 4
  EXPECT_NO_THROW(q0_->Dequeue());  // 5
  EXPECT_THROW(q0_->Dequeue(), std::out_of_range) << "비어있을 때 항목을 출력하면 에러가 발생해야 합니다.";
}

TEST_F(circular_queue, Circular) {
  MakeFull();

  q0_->Dequeue();
  q0_->Dequeue();
  ASSERT_NO_THROW(q0_->Enqueue(6)) << "항목을 추가할 때 뒷 공간이 없으면 앞 공간의 빈 공백을 채워야 합니다.";
  EXPECT_NO_THROW(q0_->Enqueue(7));
  ASSERT_THROW(q0_->Enqueue(7), std::out_of_range) << "최대 크기를 벗어나 항목을 추가하면 에러가 발생해야 합니다.";
  ASSERT_NO_THROW(q0_->Dequeue()) << "앞에서부터 다시 채워진 항목을 제거할 수 있어야 합니다.";
  q0_->Dequeue();
  EXPECT_NO_THROW(q0_->Enqueue(8));
  EXPECT_NO_THROW(q0_->Enqueue(9));
  ASSERT_THROW(q0_->Enqueue(10), std::out_of_range) << "최대 크기를 벗어나 항목을 추가하면 에러가 발생해야 합니다.";
}

TEST_F(circular_queue, Front) {
  ASSERT_THROW(q0_->Front(), std::out_of_range) << "비어있을 때 항목을 조회하면 에러가 발생해야 합니다.";
  q0_->Enqueue(1);
  q0_->Enqueue(2);
  ASSERT_EQ(q0_->Front(), 1) << "가장 먼저 입력한 항목을 출력해야 합니다.";
  q0_->Enqueue(3);
  ASSERT_EQ(q0_->Front(), 1) << "가장 먼저 입력한 항목을 출력해야 합니다.";
  q0_->Dequeue();  // 1
  q0_->Dequeue();  // 2
  q0_->Enqueue(4);
  q0_->Enqueue(5);
  ASSERT_EQ(q0_->Front(), 3) << "가장 먼저 입력한 항목을 출력해야 합니다.";

  q0_->Dequeue();  // 3
  q0_->Enqueue(6);
  q0_->Enqueue(7);
  q0_->Dequeue();  // 4
  q0_->Dequeue();  // 5
  ASSERT_EQ(q0_->Front(), 6) << "가장 먼저 입력한 항목을 출력해야 합니다.";
}

TEST_F(circular_queue, Back) {
  ASSERT_THROW(q0_->Back(), std::out_of_range) << "비어있을 때 항목을 조회하면 에러가 발생해야 합니다.";
  q0_->Enqueue(1);
  q0_->Enqueue(2);
  ASSERT_EQ(q0_->Back(), 2) << "가장 최근에 입력한 항목을 출력해야 합니다.";
  q0_->Enqueue(3);
  ASSERT_EQ(q0_->Back(), 3) << "가장 최근에 입력한 항목을 출력해야 합니다.";
  q0_->Dequeue();  // 1
  q0_->Dequeue();  // 2
  q0_->Enqueue(4);
  ASSERT_EQ(q0_->Back(), 4) << "가장 최근에 입력한 항목을 출력해야 합니다.";
}

TEST_F(circular_queue, Empty) {
  ASSERT_TRUE(q0_->Empty());
  MakeFull();
  ASSERT_FALSE(q0_->Empty());
}

TEST_F(circular_queue, Full) {
  ASSERT_FALSE(q0_->Full());
  MakeFull();
  ASSERT_TRUE(q0_->Full());
}

TEST_F(circular_queue, Clear) {
  MakeFull();
  q0_->Clear();
  ASSERT_TRUE(q0_->Empty());
  ASSERT_FALSE(q0_->Full());
}
