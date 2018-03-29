#ifndef TIMER_H_
#define TIMER_H_

#include <time.h>

namespace algdb {

class Timer {
  double start_time_;

  double now() {
    struct timespec time;
    clock_gettime(CLOCK_MONOTONIC, &time);
    double timeInSec = static_cast<double>(time.tv_sec) +
                        static_cast<double>(time.tv_nsec) * 1e-9;
    return timeInSec;
  }

 public:

  void Start() {
    start_time_ = now();
  };

  double End() {
    double end_time = now();
    return end_time - start_time_;
  };
};

}

#endif  // TIMER_H_