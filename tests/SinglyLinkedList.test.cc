// #include "../keys/SinglyLinkedList.h"
#include "../sources/data_structures/linked_list/SinglyLinkedList.h"

#include <gtest/gtest.h>

class SinglyLinkedListTest : public ::testing::Test {
 protected:
  void Fill(size_t size) {
    for (int i = 1; i <= size; ++i) sll0_.Add(i);
  }

  /**
   * 리스트 목록 출력 (디버그용)
   */
  void Print() {
    sll0_.Foreach([](int value) { std::cout << value << ' '; });
    std::cout << '\n';
  }

  SinglyLinkedList<int> sll0_;
};

TEST_F(SinglyLinkedListTest, Add) {
  sll0_.Add(3);
  EXPECT_EQ(sll0_.Size(), 1);
  EXPECT_EQ(sll0_.Front(), 3);
  ASSERT_EQ(sll0_.Back(), 3);

  Fill(5);  // 1 2 3 4 5
  int sum = 0;
  auto Sum = [&sum](int num) { sum += num; };
  sll0_.Foreach(Sum);
  ASSERT_EQ(sum, 3 + 1 + 2 + 3 + 4 + 5);

  EXPECT_EQ(sll0_.Size(), 6);
  EXPECT_EQ(sll0_.Front(), 3);
  ASSERT_EQ(sll0_.Back(), 5);
}

TEST_F(SinglyLinkedListTest, RemoveLastItem) {
  ASSERT_THROW(sll0_.Remove(), std::out_of_range)
      << "비어있을 때 항목을 제거하면 에러가 발생해야 합니다.";

  sll0_.Add(1);
  EXPECT_NO_THROW(sll0_.Remove());
  EXPECT_EQ(sll0_.Size(), 0);
  EXPECT_THROW(sll0_.Front(), std::out_of_range)
      << "항목이 하나일 때 삭제한 이후, 참조가 제대로 정돈되어야 합니다.";
  ASSERT_THROW(sll0_.Back(), std::out_of_range)
      << "항목이 하나일 때 삭제한 이후, 참조가 제대로 정돈되어야 합니다.";

  Fill(5);                          // 1 2 3 4 5
  EXPECT_NO_THROW(sll0_.Remove());  // 5 -> 1 2 3 4
  EXPECT_NO_THROW(sll0_.Remove());  // 4 -> 1 2 3

  int sum = 0;
  auto Sum = [&sum](int num) { sum += num; };

  sll0_.Foreach(Sum);
  ASSERT_EQ(sum, 1 + 2 + 3);

  EXPECT_EQ(sll0_.Size(), 3);
  EXPECT_EQ(sll0_.Front(), 1);
  ASSERT_EQ(sll0_.Back(), 3);

  EXPECT_NO_THROW(sll0_.Remove());  // 3 -> 1 2
  EXPECT_NO_THROW(sll0_.Remove());  // 2 -> 1
  EXPECT_NO_THROW(sll0_.Remove());  // 1 -> Empty
  ASSERT_THROW(sll0_.Remove(), std::out_of_range)
      << "비어있을 때 항목을 제거하면 에러가 발생해야 합니다.";

  EXPECT_EQ(sll0_.Size(), 0);
  EXPECT_THROW(sll0_.Front(), std::out_of_range);
  EXPECT_THROW(sll0_.Back(), std::out_of_range);
  ASSERT_TRUE(sll0_.Empty());
}

TEST_F(SinglyLinkedListTest, RemoveByItem) {
  ASSERT_THROW(sll0_.Remove(3), std::out_of_range)
      << "비어있을 때 항목을 제거하면 에러가 발생해야 합니다.";

  sll0_.Add(1);
  EXPECT_NO_THROW(sll0_.Remove(2));
  EXPECT_EQ(sll0_.Size(), 1);
  EXPECT_EQ(sll0_.Front(), 1);
  ASSERT_EQ(sll0_.Back(), 1);

  EXPECT_NO_THROW(sll0_.Remove(1));
  EXPECT_EQ(sll0_.Size(), 0);
  EXPECT_THROW(sll0_.Front(), std::out_of_range)
      << "항목이 하나일 때 삭제한 이후, 참조가 제대로 정돈되어야 합니다.";
  ASSERT_THROW(sll0_.Back(), std::out_of_range)
      << "항목이 하나일 때 삭제한 이후, 참조가 제대로 정돈되어야 합니다.";

  Fill(5);
  sll0_.Add(1);
  sll0_.Add(2);  // 1 2 3 4 5 1 2

  int sum = 0;
  auto Sum = [&sum](int num) { sum += num; };
  // 맨 앞 항목 제거
  sum = 0;
  EXPECT_NO_THROW(sll0_.Remove(1));  // 1 -> 2 3 4 5 1 2
  sll0_.Foreach(Sum);
  ASSERT_EQ(sum, 2 + 3 + 4 + 5 + 1 + 2);

  EXPECT_EQ(sll0_.Size(), 6);
  EXPECT_EQ(sll0_.Front(), 2);
  ASSERT_EQ(sll0_.Back(), 2);

  // 중간 항목 제거
  sum = 0;
  EXPECT_NO_THROW(sll0_.Remove(3));  // 3 -> 2 4 5 1 2
  EXPECT_NO_THROW(sll0_.Remove(1));  // 1 -> 2 4 5 2
  sll0_.Foreach(Sum);
  ASSERT_EQ(sum, 2 + 4 + 5 + 2);

  EXPECT_EQ(sll0_.Size(), 4);
  EXPECT_EQ(sll0_.Front(), 2);
  ASSERT_EQ(sll0_.Back(), 2);

  // 마지막 항목 제거
  sum = 0;
  EXPECT_NO_THROW(sll0_.Remove(2));  // 2 -> 4 5 2
  sll0_.Foreach(Sum);
  ASSERT_EQ(sum, 4 + 5 + 2);

  EXPECT_EQ(sll0_.Size(), 3);
  EXPECT_EQ(sll0_.Front(), 4);
  ASSERT_EQ(sll0_.Back(), 2);

  // 존재하지 않는 항목 제거
  EXPECT_NO_THROW(sll0_.Remove(6));  // X -> 4 5 2
  sum = 0;
  sll0_.Foreach(Sum);
  ASSERT_EQ(sum, 4 + 5 + 2)
      << "존재하지 않는 항목이라면 삭제하지 않아야 합니다.";

  EXPECT_NO_THROW(sll0_.Remove(5));  // 5 -> 4 2
  EXPECT_NO_THROW(sll0_.Remove(2));  // 2 -> 4
  EXPECT_NO_THROW(sll0_.Remove(4));  // 4 ->

  EXPECT_EQ(sll0_.Size(), 0);
  EXPECT_THROW(sll0_.Front(), std::out_of_range);
  EXPECT_THROW(sll0_.Back(), std::out_of_range);
  ASSERT_THROW(sll0_.Remove(3), std::out_of_range)
      << "비어있을 때 항목을 제거하면 에러가 발생해야 합니다.";
}

TEST_F(SinglyLinkedListTest, Contain) {
  ASSERT_FALSE(sll0_.Contain(6));
  Fill(5);

  EXPECT_TRUE(sll0_.Contain(2)) << "2를 포함해야 합니다.";
  EXPECT_TRUE(sll0_.Contain(4));
  EXPECT_FALSE(sll0_.Contain(6)) << "6을 포함하지 않아야 합니다.";
}

TEST_F(SinglyLinkedListTest, FrontAndBack) {
  ASSERT_THROW(sll0_.Front(), std::out_of_range)
      << "비어있을 때 항목을 조회하면 에러가 발생해야 합니다.";
  Fill(5);

  EXPECT_EQ(sll0_.Front(), 1) << "맨 앞 항목을 가져와야 합니다.";
  EXPECT_EQ(sll0_.Back(), 5) << "맨 뒤 항목을 가져와야 합니다.";
}

TEST_F(SinglyLinkedListTest, Empty) {
  ASSERT_TRUE(sll0_.Empty());
  Fill(3);
  ASSERT_FALSE(sll0_.Empty());
}

TEST_F(SinglyLinkedListTest, Size) {
  Fill(3);
  ASSERT_EQ(sll0_.Size(), 3);
  Fill(3);
  ASSERT_EQ(sll0_.Size(), 6);
}

TEST_F(SinglyLinkedListTest, Clear) {
  Fill(3);
  sll0_.Clear();
  EXPECT_THROW(sll0_.Front(), std::out_of_range);
  EXPECT_THROW(sll0_.Back(), std::out_of_range);
  EXPECT_EQ(sll0_.Size(), 0);
}