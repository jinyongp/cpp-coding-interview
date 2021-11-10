// #include "../keys/CircularQueue.h"
#include "../sources/data_structures/queue/CircularQueue.h"

#include <gtest/gtest.h>

class CircularQueueTest : public ::testing::Test {
 protected:
  void MakeFull() {
    for (int i = 1; !cq0_.Full(); ++i) cq0_.Enqueue(i);
  }

  CircularQueue<int, 5> cq0_;
};

TEST_F(CircularQueueTest, Enqueue) {
  EXPECT_NO_THROW(cq0_.Enqueue(1));
  ASSERT_FALSE(cq0_.Empty()) << "항목이 추가되어야 합니다.";
  EXPECT_NO_THROW(cq0_.Enqueue(2));
  EXPECT_NO_THROW(cq0_.Enqueue(3));
  EXPECT_NO_THROW(cq0_.Enqueue(4));
  EXPECT_NO_THROW(cq0_.Enqueue(5));
  ASSERT_THROW(cq0_.Enqueue(6), std::out_of_range)
      << "최대 크기를 벗어나 항목을 추가하면 에러가 발생해야 합니다.";
}

TEST_F(CircularQueueTest, Dequeue) {
  MakeFull();

  EXPECT_NO_THROW(cq0_.Dequeue());  // 1
  ASSERT_EQ(cq0_.Front(), 2) << "가장 먼저 입력한 항목을 제거해야 합니다.";
  EXPECT_NO_THROW(cq0_.Dequeue());  // 2
  EXPECT_NO_THROW(cq0_.Dequeue());  // 3
  ASSERT_EQ(cq0_.Front(), 4) << "가장 먼저 입력한 항목을 제거해야 합니다.";
  EXPECT_NO_THROW(cq0_.Dequeue());  // 4
  EXPECT_NO_THROW(cq0_.Dequeue());  // 5
  EXPECT_THROW(cq0_.Dequeue(), std::out_of_range)
      << "비어있을 때 항목을 출력하면 에러가 발생해야 합니다.";
}

TEST_F(CircularQueueTest, Circular) {
  MakeFull();

  cq0_.Dequeue();
  cq0_.Dequeue();
  ASSERT_NO_THROW(cq0_.Enqueue(6))
      << "항목을 추가할 때 뒷 공간이 없으면 앞 공간의 빈 공백을 채워야 합니다.";
  EXPECT_NO_THROW(cq0_.Enqueue(7));
  ASSERT_THROW(cq0_.Enqueue(7), std::out_of_range)
      << "최대 크기를 벗어나 항목을 추가하면 에러가 발생해야 합니다.";
  ASSERT_NO_THROW(cq0_.Dequeue())
      << "앞에서부터 다시 채워진 항목을 제거할 수 있어야 합니다.";
  cq0_.Dequeue();
  EXPECT_NO_THROW(cq0_.Enqueue(8));
  EXPECT_NO_THROW(cq0_.Enqueue(9));
  ASSERT_THROW(cq0_.Enqueue(10), std::out_of_range)
      << "최대 크기를 벗어나 항목을 추가하면 에러가 발생해야 합니다.";
}

TEST_F(CircularQueueTest, Front) {
  ASSERT_THROW(cq0_.Front(), std::out_of_range)
      << "비어있을 때 항목을 조회하면 에러가 발생해야 합니다.";
  cq0_.Enqueue(1);
  cq0_.Enqueue(2);
  ASSERT_EQ(cq0_.Front(), 1) << "가장 먼저 입력한 항목을 출력해야 합니다.";
  cq0_.Enqueue(3);
  ASSERT_EQ(cq0_.Front(), 1) << "가장 먼저 입력한 항목을 출력해야 합니다.";
  cq0_.Dequeue();  // 1
  cq0_.Dequeue();  // 2
  cq0_.Enqueue(4);
  cq0_.Enqueue(5);
  ASSERT_EQ(cq0_.Front(), 3) << "가장 먼저 입력한 항목을 출력해야 합니다.";

  cq0_.Dequeue();  // 3
  cq0_.Enqueue(6);
  cq0_.Enqueue(7);
  cq0_.Dequeue();  // 4
  cq0_.Dequeue();  // 5
  ASSERT_EQ(cq0_.Front(), 6) << "가장 먼저 입력한 항목을 출력해야 합니다.";
}

TEST_F(CircularQueueTest, Back) {
  ASSERT_THROW(cq0_.Back(), std::out_of_range)
      << "비어있을 때 항목을 조회하면 에러가 발생해야 합니다.";
  cq0_.Enqueue(1);
  cq0_.Enqueue(2);
  ASSERT_EQ(cq0_.Back(), 2) << "가장 최근에 입력한 항목을 출력해야 합니다.";
  cq0_.Enqueue(3);
  ASSERT_EQ(cq0_.Back(), 3) << "가장 최근에 입력한 항목을 출력해야 합니다.";
  cq0_.Dequeue();  // 1
  cq0_.Dequeue();  // 2
  cq0_.Enqueue(4);
  ASSERT_EQ(cq0_.Back(), 4) << "가장 최근에 입력한 항목을 출력해야 합니다.";
}

TEST_F(CircularQueueTest, Empty) {
  ASSERT_TRUE(cq0_.Empty());
  MakeFull();
  ASSERT_FALSE(cq0_.Empty());
}

TEST_F(CircularQueueTest, Full) {
  ASSERT_FALSE(cq0_.Full());
  MakeFull();
  ASSERT_TRUE(cq0_.Full());
}

TEST_F(CircularQueueTest, Clear) {
  MakeFull();
  cq0_.Clear();
  ASSERT_TRUE(cq0_.Empty());
  ASSERT_FALSE(cq0_.Full());
}
