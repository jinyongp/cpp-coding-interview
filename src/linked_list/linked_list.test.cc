#include <gtest/gtest.h>

#ifdef DEV
#include "linked_list.hint.h"
#else
#include "linked_list.h"
#endif

class linked_list : public ::testing::Test {
 protected:
  LinkedListInterface<int>* list_;

  void SetUp() override {
    list_ = new LinkedList<int>();
  }

  void TearDown() override {
    delete list_;
  }
};

TEST_F(linked_list, Insert) {
  EXPECT_NO_THROW(list_->Insert(1));
  ASSERT_FALSE(list_->IsEmpty());
  EXPECT_NO_THROW(list_->Insert(2));
  EXPECT_NO_THROW(list_->Insert(3));
  ASSERT_EQ(list_->Size(), 3);
}

TEST_F(linked_list, Remove) {
  list_->Insert(1);
  list_->Insert(2);
  list_->Insert(3);

  EXPECT_NO_THROW(list_->Remove(2));
  ASSERT_EQ(list_->Size(), 2);
  EXPECT_NO_THROW(list_->Remove(1));
  EXPECT_NO_THROW(list_->Remove(3));
  ASSERT_TRUE(list_->IsEmpty());
  ASSERT_THROW(list_->Remove(4), std::underflow_error);
}

TEST_F(linked_list, Front) {
  ASSERT_THROW(list_->Front(), std::underflow_error);
  list_->Insert(1);
  ASSERT_EQ(list_->Front(), 1);
  list_->Insert(2);
  ASSERT_EQ(list_->Front(), 1);
}

TEST_F(linked_list, Back) {
  ASSERT_THROW(list_->Back(), std::underflow_error);
  list_->Insert(1);
  ASSERT_EQ(list_->Back(), 1);
  list_->Insert(2);
  ASSERT_EQ(list_->Back(), 2);
}

TEST_F(linked_list, IsEmpty) {
  ASSERT_TRUE(list_->IsEmpty());
  list_->Insert(1);
  ASSERT_FALSE(list_->IsEmpty());
}

TEST_F(linked_list, Size) {
  ASSERT_EQ(list_->Size(), 0);
  list_->Insert(1);
  ASSERT_EQ(list_->Size(), 1);
  list_->Insert(2);
  ASSERT_EQ(list_->Size(), 2);
}

TEST_F(linked_list, Clear) {
  list_->Insert(1);
  list_->Insert(2);
  list_->Clear();
  ASSERT_TRUE(list_->IsEmpty());
}

TEST_F(linked_list, Reference) {
  auto l = new LinkedList<utils::dummy>();

  times(2) {
    ASSERT_TRUE(l->IsEmpty()) << "리스트가 비어있어야 합니다.";
    ASSERT_EQ(l->Size(), 0) << "리스트가 비어있어야 합니다.";
    ASSERT_THROW(l->Front(), std::underflow_error) << "비어있을 때 항목을 조회하면 에러가 발생해야 합니다.";
    ASSERT_THROW(l->Back(), std::underflow_error) << "비어있을 때 항목을 조회하면 에러가 발생해야 합니다.";

    times(3) {
      ASSERT_NO_THROW(l->Insert(utils::dummy{i}));
      ASSERT_EQ(l->Front().value, 0) << "가장 먼저 넣은 항목을 조회합니다.";
      ASSERT_EQ(l->Back().value, i) << "가장 나중에 넣은 항목을 조회합니다.";
      ASSERT_EQ(l->Size(), i + 1) << "항목을 추가할 때마다 크기가 증가해야 합니다.";
    }  // | 0 | 1 | 2 | -> front: 0, back: 2, size: 3

    ASSERT_FALSE(l->IsEmpty()) << "리스트가 비어있지 않아야 합니다.";
    ASSERT_EQ(l->Size(), 3) << "리스트의 크기는 3이어야 합니다.";

    times(3) {
      ASSERT_EQ(l->Size(), 3 - i) << "항목을 제거할 때마다 크기가 감소해야 합니다.";
      ASSERT_EQ(l->Front().value, i) << "가장 먼저 넣은 항목을 조회합니다.";
      ASSERT_EQ(l->Back().value, 2) << "가장 나중에 넣은 항목을 조회합니다.";
      ASSERT_NO_THROW(l->Remove(utils::dummy{i}));
    }

    ASSERT_TRUE(l->IsEmpty()) << "모든 항목을 제거하면 리스트가 비어있어야 합니다.";
    ASSERT_EQ(l->Size(), 0) << "모든 항목을 제거하면 크기가 0이어야 합니다.";

    ASSERT_THROW(l->Remove(utils::dummy{3}), std::underflow_error) << "비어있을 때 항목을 제거하면 에러가 발생해야 합니다.";
    ASSERT_THROW(l->Front(), std::underflow_error) << "비어있을 때 항목을 조회하면 에러가 발생해야 합니다.";
    ASSERT_THROW(l->Back(), std::underflow_error) << "비어있을 때 항목을 조회하면 에러가 발생해야 합니다.";

    times(3) l->Insert(utils::dummy{i});  // 0 1 2
    ASSERT_EQ(l->Front().value, 0) << "가장 먼저 넣은 항목을 조회합니다.";
    ASSERT_EQ(l->Back().value, 2) << "가장 나중에 넣은 항목을 조회합니다.";

    l->Clear();
    ASSERT_TRUE(l->IsEmpty()) << "Clear 함수를 호출하면 리스트가 비어있어야 합니다.";
  }

  delete l;
}
