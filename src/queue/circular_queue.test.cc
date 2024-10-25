
#include "circular_queue.h"

#include <gtest/gtest.h>

#include "circular_queue.hint.h"

class CircularQueueTest : public ::testing::Test {
 protected:
  CircularQueueInterface<int, 5>* queue;

  void SetUp() override {
    if (std::string(std::getenv("DEV")) == "true") {
      queue = new _CircularQueue<int, 5>();
    } else {
      queue = new CircularQueue<int, 5>();
    }
  }

  void TearDown() override {
    delete queue;
  }

  void MakeFull() {
    for (int i = 1; !queue->Full(); ++i) {
      queue->Enqueue(i);
    }
  }
};

TEST_F(CircularQueueTest, Enqueue) {
  EXPECT_NO_THROW(queue->Enqueue(1));
  ASSERT_FALSE(queue->Empty()) << "항목이 추가되어야 합니다.";
  EXPECT_NO_THROW(queue->Enqueue(2));
  EXPECT_NO_THROW(queue->Enqueue(3));
  EXPECT_NO_THROW(queue->Enqueue(4));
  EXPECT_NO_THROW(queue->Enqueue(5));
  ASSERT_THROW(queue->Enqueue(6), std::out_of_range)
      << "최대 크기를 벗어나 항목을 추가하면 에러가 발생해야 합니다.";
}

TEST_F(CircularQueueTest, Dequeue) {
  MakeFull();  // 1, 2, 3, 4, 5

  EXPECT_NO_THROW(queue->Dequeue());  // 1
  ASSERT_EQ(queue->Front(), 2) << "가장 먼저 입력한 항목을 제거해야 합니다.";
  EXPECT_NO_THROW(queue->Dequeue());  // 2
  EXPECT_NO_THROW(queue->Dequeue());  // 3
  ASSERT_EQ(queue->Front(), 4) << "가장 먼저 입력한 항목을 제거해야 합니다.";
  EXPECT_NO_THROW(queue->Dequeue());  // 4
  EXPECT_NO_THROW(queue->Dequeue());  // 5
  EXPECT_THROW(queue->Dequeue(), std::out_of_range)
      << "비어있을 때 항목을 출력하면 에러가 발생해야 합니다.";
}

TEST_F(CircularQueueTest, Circular) {
  MakeFull();

  queue->Dequeue();
  queue->Dequeue();
  ASSERT_NO_THROW(queue->Enqueue(6))
      << "항목을 추가할 때 뒷 공간이 없으면 앞 공간의 빈 공백을 채워야 합니다.";
  EXPECT_NO_THROW(queue->Enqueue(7));
  ASSERT_THROW(queue->Enqueue(7), std::out_of_range)
      << "최대 크기를 벗어나 항목을 추가하면 에러가 발생해야 합니다.";
  ASSERT_NO_THROW(queue->Dequeue())
      << "앞에서부터 다시 채워진 항목을 제거할 수 있어야 합니다.";
  queue->Dequeue();
  EXPECT_NO_THROW(queue->Enqueue(8));
  EXPECT_NO_THROW(queue->Enqueue(9));
  ASSERT_THROW(queue->Enqueue(10), std::out_of_range)
      << "최대 크기를 벗어나 항목을 추가하면 에러가 발생해야 합니다.";
}

TEST_F(CircularQueueTest, Front) {
  ASSERT_THROW(queue->Front(), std::out_of_range)
      << "비어있을 때 항목을 조회하면 에러가 발생해야 합니다.";
  queue->Enqueue(1);
  queue->Enqueue(2);
  ASSERT_EQ(queue->Front(), 1) << "가장 먼저 입력한 항목을 출력해야 합니다.";
  queue->Enqueue(3);
  ASSERT_EQ(queue->Front(), 1) << "가장 먼저 입력한 항목을 출력해야 합니다.";
  queue->Dequeue();  // 1
  queue->Dequeue();  // 2
  queue->Enqueue(4);
  queue->Enqueue(5);
  ASSERT_EQ(queue->Front(), 3) << "가장 먼저 입력한 항목을 출력해야 합니다.";

  queue->Dequeue();  // 3
  queue->Enqueue(6);
  queue->Enqueue(7);
  queue->Dequeue();  // 4
  queue->Dequeue();  // 5
  ASSERT_EQ(queue->Front(), 6) << "가장 먼저 입력한 항목을 출력해야 합니다.";
}

TEST_F(CircularQueueTest, Back) {
  ASSERT_THROW(queue->Back(), std::out_of_range)
      << "비어있을 때 항목을 조회하면 에러가 발생해야 합니다.";
  queue->Enqueue(1);
  queue->Enqueue(2);
  ASSERT_EQ(queue->Back(), 2) << "가장 최근에 입력한 항목을 출력해야 합니다.";
  queue->Enqueue(3);
  ASSERT_EQ(queue->Back(), 3) << "가장 최근에 입력한 항목을 출력해야 합니다.";
  queue->Dequeue();  // 1
  queue->Dequeue();  // 2
  queue->Enqueue(4);
  ASSERT_EQ(queue->Back(), 4) << "가장 최근에 입력한 항목을 출력해야 합니다.";
}

TEST_F(CircularQueueTest, Empty) {
  ASSERT_TRUE(queue->Empty());
  MakeFull();
  ASSERT_FALSE(queue->Empty());
}

TEST_F(CircularQueueTest, Full) {
  ASSERT_FALSE(queue->Full());
  MakeFull();
  ASSERT_TRUE(queue->Full());
}

TEST_F(CircularQueueTest, Clear) {
  MakeFull();
  queue->Clear();
  ASSERT_TRUE(queue->Empty());
  ASSERT_FALSE(queue->Full());
}
