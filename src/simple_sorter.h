#ifndef SIMPLE_SORTER_H_
#define SIMPLE_SORTER_H_

#include "sorter.h"
#include "container/list.h"

namespace algdb {

template<typename T>
class SimpleSorter : public Sorter<T> {
 public:
  void Sort(List<T> *list, Comparator<T> *comparator) {
    for(int i = 0; i < list->Length(); i++) {
      int min = i;
      for (int j = i; j < list->Length(); j++) {
        if (comparator->Compare(list->Get(j), list->Get(min))) {
          min = j;
        }
      }

      if (min != i) {
        T temp = list->Get(min);
        list->Set(min, list->Get(i));
        list->Set(i, temp);
      }
    }
  }
};

}

#endif  // SIMPLE_SORTER_H_
