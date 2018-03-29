#ifndef EVENT_H_
#define EVENT_H_

#include <string>
#include <stdint.h>

namespace algdb {

class Event {
 public:
  std::string event_id;
  std::string time;
  uint64_t duration;
  uint32_t fee;
  uint32_t yes_rsvp_count;
  uint64_t group_id;
};

}

#endif
