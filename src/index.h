#ifndef INDEX_H_
#define INDEX_H_

namespace algdb {

template <typename K, typename V>
class Index {
 public:
  virtual ~Index() {}

  void Insert(K key, V value);
  V Select(K key);
}

}

#endif  // INDEX_H_
