#ifndef RESULT_SET_
#define RESULT_SET_

#include "container/list.h"
#include "container/iterator.h"
#include "container/linked_list.h"
#include "container/array_list.h"

namespace algdb {

template <typename T>
class ResultSet {
 protected:
  List<Event *> *entries_;

 public:
  ResultSet() {
    entries_ = new ArrayList<Event *>();
  }

  ~ResultSet() {
    delete entries_;
  }

  Iterator<T> *GetIterator() const {
    return entries_->GetIterator();
  }

  void Append(T entry) {
    entries_->Append(entry);
  };
};

}

#endif  // RESULT_SET_