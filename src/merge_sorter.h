#ifndef MERGE_SORTER_H_
#define MERGE_SORTER_H_

#include "sorter.h"
#include "container/list.h"

namespace algdb {

template<typename T>
class MergeSorter : public Sorter<T> {

  void MergeSort(List<T> *list, int p, int r, Comparator<T> *comparator) {
    if (r - p <= 1) return;

    int mid = (p + r) / 2;
    MergeSort(list, p, mid, comparator);
    MergeSort(list, mid, r, comparator);
    Merge(list, p, mid, r, comparator);
  }

  void Merge(List<T> *list, int p, int q, int r, Comparator<T>* comparator) {
    int pl = p;
    int pr = q;
    T *temp = new T[r-p];

    for (int i = 0; i < r - p; i++) {
      if (pl >= q) {
        temp[i] = list->Get(pr++);
      } else if (pr >= r) {
        temp[i] = list->Get(pl++);
      } else if (comparator->Compare(list->Get(pl), list->Get(pr))) {
        temp[i] = list->Get(pl++);
      } else {
        temp[i] = list->Get(pr++);
      }
    }

    for (int i = 0; i < r - p; i++) {
      list->Set(p + i, temp[i]);
    }

    delete[] temp;
  }

 public:

  void Sort(List<T> *list, Comparator<T> *comparator) {
    MergeSort(list, 0, list->Length(), comparator);
  }
};

}

#endif  // MERGE_SORTER_H_
