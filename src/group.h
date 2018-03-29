#ifndef GROUP_H_
#define GROUP_H_

#include <vector>
#include <string>
#include <stdint.h>

namespace algdb {

class Member;

class Group {
 public:
  uint64_t group_id;
  std::vector<Member *> members;
  std::string group_name;
  uint32_t organizer_id;
  Member *organizer = NULL;
  double rating;
};

}

#endif
