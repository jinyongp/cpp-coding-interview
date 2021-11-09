#if !defined(HASH_TABLE_H_)
#define HASH_TABLE_H_

#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

namespace {

bool IsPrime(size_t n) {
  if (n < 2) return false;
  if (n % 2 == 0) return n == 2;
  for (int i = 3; i * i <= n; i += 2)
    if (n % i == 0) return false;
  return true;
}

size_t GetNextPrime(size_t n) {
  if (n % 2 == 0) n += 1;
  while (!IsPrime(n)) n += 2;
  return n;
}

}  // namespace

/**
 * 해시테이블 원형
 *
 * @tparam K key type
 * @tparam V value type
 */
template <typename K, typename V>
class HashTable {
 private:
  enum Status { ACTIVE, EMPTY, INACTIVE };

  struct Bucket {
    K key;
    V value;
    Status status;

    Bucket(const V& v = V{}, Status s = EMPTY) : value{v}, status{s} {}
  };

  vector<Bucket> buckets_;  // 해시 테이블 버킷
  size_t size_;             // 항목 개수
  float load_factor_;       // size_ / buckets_.size()

  const float LOAD_FACTOR_MAX = 0.75;
  const float LOAD_FACTOR_MIN = 0.25;

  /**
   * position에 위치한 버킷이 ACTIVE 상태인지 확인한다.
   *
   * @param position
   * @return bool
   */
  bool IsActive(size_t position) const {
    return buckets_[position].status == ACTIVE;
  }

  /**
   * key에 상응하는 인덱스 위치를 반환한다.
   *
   * @param key
   * @return size_t
   */
  size_t GetPosition(const K& key) const {
    size_t pos = Hash(key);
    while (buckets_[pos].status != EMPTY and buckets_[pos].key != key) {
      pos += 1;
      if (pos >= buckets_.size()) pos -= buckets_.size();
    }
    return pos;
  }

  /**
   * 항목의 개수가 기준치보다 많아질 경우, 버킷의 크기를 늘리고 항목을 다시 추가한다.
   */
  void Rehash() {
    vector<Bucket> buckets_old = buckets_;
    buckets_.clear();
    size_ = 0;

    if (load_factor_ > LOAD_FACTOR_MAX)
      buckets_.resize(GetNextPrime(buckets_old.size() * 2));
    else if (load_factor_ < LOAD_FACTOR_MIN)
      buckets_.resize(GetNextPrime(buckets_old.size() / 2));

    for (const auto& bucket : buckets_old) {
      if (bucket.status == ACTIVE) (*this)[bucket.key] = bucket.value;
    }
  }

  size_t Hash(const K& key) const {
    hash<K> hash;
    return hash(key) % buckets_.size();
  }

 public:
  /**
   * 새로운 해시 테이블 객체를 생성한다.
   */
  HashTable() {
    Clear();
  }

  /**
   * 해시 테이블에 (key, value) 쌍을 추가한다.
   * value의 할당이 이뤄지지 않는다면 기본값이 저장된다. (이 동작을 방지하기 위해선 Get을 통해 값을 얻어야 한다.)
   *
   * @param key
   * @return V&
   */
  V& operator[](const K& key) {
    size_t pos = GetPosition(key);
    if (!IsActive(pos)) {
      buckets_[pos].key = key;
      buckets_[pos].value = V{};
      buckets_[pos].status = ACTIVE;
      size_ += 1;
      load_factor_ = (float)size_ / buckets_.size();
      if (load_factor_ > LOAD_FACTOR_MAX) Rehash();
      pos = GetPosition(key);
    }
    return buckets_[pos].value;
  }

  /**
   * 해시 테이블에서 항목을 제거한다.
   * 삭제에 성공하면 true를 반환한다.
   *
   * @param key
   * @return bool
   */
  bool Remove(const K& key) {
    size_t pos = GetPosition(key);
    if (!IsActive(pos)) return false;
    buckets_[pos].status = INACTIVE;
    size_ -= 1;

    load_factor_ = (float)size_ / buckets_.size();
    if (load_factor_ < LOAD_FACTOR_MIN) Rehash();
    return true;
  }

  /**
   * 해시 테이블에서 항목의 여부를 확인한다.
   *
   * @param key
   * @return bool
   */
  bool Contain(const K& key) const {
    return IsActive(GetPosition(key));
  }

  /**
   * 해시 테이블로부터 key에 대응하는 value를 반환한다.
   *
   * @param key
   * @return const V&
   * @exception out_of_range 해시 테이블에 존재하지 않는 key라면 에러가 발생한다.
   */
  const V& Get(const K& key) const {
    size_t pos = GetPosition(key);
    if (!IsActive(pos))
      throw out_of_range("the key does not exist in hash table");
    return buckets_[pos].value;
  }

  /**
   * 해시 테이블을 초기화한다.
   */
  void Clear() {
    size_ = 0;
    load_factor_ = 0;
    buckets_.clear();
    buckets_.resize(3);
  }

  /**
   * 항목의 수를 반환한다.
   *
   * @return size_t
   */
  size_t Size() const {
    return size_;
  }

  /**
   * 버킷의 크기를 반환한다.
   *
   * @return size_t
   */
  size_t Capacity() const {
    return buckets_.size();
  }
};

#endif  // HASH_TABLE_H_
