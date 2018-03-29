#ifndef HEAP_SORTER_H_
#define HEAP_SORTER_H_

#include "sorter.h"
#include "container/heap.h"

namespace algdb {

template<typename T>
class HeapSorter : public Sorter<T> {

 public:

  void Sort(List<T> *list, Comparator<T> *comparator) {
    Heap<T> heap(list, comparator);

    heap.BuildMaxHeap();
    for (int i = list->Length() - 1; i >= 1; i--) {
      list->Swap(0, i);
      heap.SetHeapSize(heap.GetHeapSize() - 1);
      heap.MaxHeapify(0);
    }

  }
};

}

#endif  // HEAP_SORTER_H_
