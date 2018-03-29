#ifndef SORTER_H_
#define SORTER_H_

#include "container/list.h"

namespace algdb {

/**
 * Comprarator is a class has helps the Sorter to compare values
 */
template <typename T>
class Comparator {
 public:
  virtual ~Comparator() {}

  /**
   * Compare determines if how two value a and b should be ordered. If return
   * true, a should be in front of b in the final sorted array.
   */
  virtual bool Compare(T a, T b) = 0;
};

/**
 * Sorter defines the interface to sort a list
 */
template <typename T>
class Sorter {

 public:
  virtual ~Sorter() {}

  /**
   * Sort the list and store the elements in the lists in order
   */
  virtual void Sort(List<T> *list, Comparator<T> *comparator) = 0;
};

}

#endif  // SORTER_H_
