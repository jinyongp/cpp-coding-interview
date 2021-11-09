// #include "../keys/HashTable.h"
#include "../sources/data-structure/hash_table/HashTable.h"

#include <gtest/gtest.h>

#include <fstream>
#include <string>
#include <vector>

using namespace std;

class HashTableTest : public ::testing::Test {
 protected:
  void Fill(size_t size) {
    for (size_t i = 1; i <= size; ++i) {
      auto num = to_string(i);
      string key = "key" + num;
      string value = "value" + num;
      htl0_[key] = value;
    }
  }

  HashTable<string, string> htl0_;
};

TEST_F(HashTableTest, SubscriptOperator) {
  try {
    ASSERT_NO_FATAL_FAILURE(htl0_["key1"] = "value1");
    // htl0_["key2"] = "value2";
    // htl0_["key3"] = "value3";
    // htl0_["key4"] = "value4";
  } catch (const std::exception& e) {
    FAIL() << e.what();
  }

  ASSERT_EQ(htl0_["key1"], "value1") << "key1은 value1을 가지고 있어야 합니다.";
  EXPECT_EQ(htl0_["key2"], "value2");
  EXPECT_EQ(htl0_["key3"], "value3");
  EXPECT_EQ(htl0_["key4"], "value4");
  ASSERT_EQ(htl0_["key5"], "")
      << "존재하지 않는 key에 접근하면 기본값을 반환해야 합니다.";

  htl0_["key3"] = "new_value3";
  ASSERT_EQ(htl0_["key3"], "new_value3");
}

TEST_F(HashTableTest, Resizing) {
  try {
    htl0_["key1"] = "value1";
    htl0_["key2"] = "value2";
    htl0_["key3"] = "value3";
    htl0_["key4"] = "value4";
    htl0_["key5"] = "value5";
  } catch (const std::exception& e) {
    FAIL() << e.what();
  }

  EXPECT_EQ(htl0_.Size(), 5);
  ASSERT_EQ(htl0_.Capacity(), 7);

  try {
    htl0_.Remove("key1");
    htl0_.Remove("key2");
    htl0_.Remove("key3");
    htl0_.Remove("key4");
    htl0_.Remove("key5");
    htl0_.Remove("key6");
  } catch (const std::exception& e) {
    FAIL() << e.what();
  }

  EXPECT_EQ(htl0_.Size(), 0);
  ASSERT_EQ(htl0_.Capacity(), 3);
}

TEST_F(HashTableTest, Remove) {
  Fill(5);
  ASSERT_EQ(htl0_["key1"], "value1") << "operator[]를 완성하세요.";

  EXPECT_TRUE(htl0_.Remove("key3"));
  EXPECT_FALSE(htl0_.Remove("key6"));
  EXPECT_FALSE(htl0_.Remove("key3"))
      << "이미 삭제된 항목은 다시 지울 수 없어야 합니다.";
}

TEST_F(HashTableTest, Contain) {
  Fill(5);
  ASSERT_EQ(htl0_["key1"], "value1");

  EXPECT_TRUE(htl0_.Contain("key3"));
  EXPECT_FALSE(htl0_.Contain("key6"));
}

TEST_F(HashTableTest, Get) {
  Fill(5);
  ASSERT_EQ(htl0_["key1"], "value1") << "operator[]를 완성하세요.";

  EXPECT_EQ(htl0_.Get("key3"), "value3")
      << "key에 상응하는 value를 반환해야 합니다.";
  EXPECT_THROW(htl0_.Get("key6"), std::out_of_range)
      << "존재하지 않는 key를 입력하면 에러가 발생해야 합니다.";
}

TEST_F(HashTableTest, Clear) {
  Fill(3);
  ASSERT_EQ(htl0_["key1"], "value1") << "operator[]를 완성하세요.";

  htl0_.Clear();
  EXPECT_FALSE(htl0_.Contain("key1"));
  EXPECT_FALSE(htl0_.Contain("key2"));
  EXPECT_FALSE(htl0_.Contain("key3"));
}

TEST_F(HashTableTest, Dictionary) {
  std::string file_path{__FILE__};
  file_path = file_path.substr(0, file_path.rfind("/"));
  std::string words_file = file_path + "/data/words.txt";

  std::string word;
  std::ifstream words{words_file.data()};
  std::vector<string> word_list;
  int index = 0;
  if (!words.is_open()) FAIL() << " 파일이 열리지 않았습니다.";
  while (getline(words, word)) {
    htl0_[word];
    if (index++ % 2 == 0 || index % 3 == 0) word_list.push_back(word);
  }

  for (const auto& word : word_list) {
    ASSERT_TRUE(htl0_.Contain(word)) << word << "가 포함되어 있어야 합니다.";
  }

  EXPECT_EQ(htl0_.Size(), 466514);
  EXPECT_EQ(htl0_.Capacity(), 701819);

  int removed = 0;
  for (const auto& word : word_list) {
    removed += htl0_.Remove(word);
  }

  EXPECT_EQ(removed, 466514 - 155505);
  EXPECT_EQ(htl0_.Size(), 155505);
  EXPECT_EQ(htl0_.Capacity(), 350941);
}
