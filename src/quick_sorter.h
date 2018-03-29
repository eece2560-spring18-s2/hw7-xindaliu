#ifndef QUICK_SORTER_H_
#define QUICK_SORTER_H_

#include "sorter.h"
#include "container/list.h"

namespace algdb {

template<typename T>
class QuickSorter : public Sorter<T> {

  void QuickSort(List<T> *list, int p, int r, Comparator<T> *comparator) {
    if (r - p > 1) {
      int q = Partition(list, p, r, comparator);
      QuickSort(list, p, q, comparator);
      QuickSort(list, q + 1, r, comparator);
    }
  }

  int Partition(List<T> *list, int p, int r, Comparator<T> *comparator) {
    T x = list->Get(r-1);
    int i = p;
    int j = p;

    while (j < r - 1) {
      T curr = list->Get(j);
      if (comparator->Compare(list->Get(j), x)) {
        list->Set(j, list->Get(i));
        list->Set(i, curr);
        i++;
      }
      j++;
    }

    list->Set(r - 1, list->Get(i));
    list->Set(i, x);
    return i;
  }

 public:

  void Sort(List<T> *list, Comparator<T> *comparator) {
    QuickSort(list, 0, list->Length(), comparator);
  }
};

}

#endif  // QUICK_SORTER_H_
