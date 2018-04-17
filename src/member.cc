#include "member.h"

#include <queue>

#include "database.h"
#include <limits>

namespace algdb {

void Member::DumpConnections() {
  std::cout << "(" << member_id << ")";
  for (auto &m : connecting_members) {
    auto conn = m.second;
    std::cout << "->" << conn.dst->member_id << 
      "(" << conn.group->group_id << ")";
  }
  std::cout << "\n";
}

void Member::PathToMemberBFS(uint64_t dst_member_id) {
  std::queue<Member *> myq;
  this->color = COLOR_GRAY;
  this->parent = NULL;
  this->key = 0;
  myq.push(this);
  while(!myq.empty()) {
    Member *m = myq.front();
    myq.pop();
    for(auto it : m->connecting_members) {
      auto u = it.second;
      if(u.dst->member_id == dst_member_id) {
           PrintPath(u.dst);
        }
      if(u.dst->color == COLOR_BLACK) {
        u.dst->color = COLOR_GRAY;
        u.dst->key += 1;
        u.dst->parent = m;
        myq.push(u.dst);
        
      }
    }
  m->color = COLOR_BLACK;
  }
}

Member * Member::DLS(Member * node, int iteration, uint64_t dst_member_id) {
  if(iteration == 0 && node->member_id == dst_member_id) {
    return node;
  }
  if(iteration > 0) {
  for (auto child = node->connecting_members.begin(); child != node->connecting_members.end(); ++child ){
      Member *m = child->second.dst;
      m->parent = node;
      Member * match = DLS(m, iteration - 1, dst_member_id);
      if(match != NULL) {
      return match;
      }
    }
  }
  return NULL;
}

void Member::PathToMemberIDDFS(uint64_t dst_member_id) {
  for(int i = 0; i < std::numeric_limits<int>::max(); i++) {
     Member * match = DLS(this, i, dst_member_id);
    if(match != NULL) {
    this->PrintPath(match);
    return;
    }
  }
}

void Member::PrintPath(Member* dst) {
  Member *curr = dst;
  while(curr && curr != this) {
    std::cout << curr->member_name << " <- ";
    curr = curr->parent;
  }
  std::cout << this->member_name << "\n";
}

}
