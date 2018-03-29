#include <iostream>
#include <string>

#define private public
#include "database.h"
#include "member.h"
#include "group.h"

using namespace algdb;

#define EXPECT_EQ(act, exp) \
  if ((act) != (exp)) { \
    std::cout << __FILE__ << ":" << __LINE__ << " " << __FUNCTION__ << " " \
      << "expected " << exp << ", but get " << act << ".\n"; \
    return false;\
  }

void add_member_to_group(Member *m, Group *g) {
  m->groups.push_back(g);
  g->members.push_back(m);
}

bool TestMST() {
  Database db;

  for (int i = 0; i < 6; i++) {
    Member *m = new Member();
    m->member_id = i;
    m->member_name = std::to_string(i);
    db.members.push_back(m);
  }

  for (int i = 0; i < 3; i++) {
    Group *g = new Group();
    g->group_id = i;
    g->group_name = std::to_string(i);
    db.groups.push_back(g);
  }

  add_member_to_group(db.members[0], db.groups[0]);
  add_member_to_group(db.members[0], db.groups[1]);
  add_member_to_group(db.members[0], db.groups[2]);
  add_member_to_group(db.members[1], db.groups[0]);
  add_member_to_group(db.members[1], db.groups[1]);
  add_member_to_group(db.members[2], db.groups[1]);
  add_member_to_group(db.members[2], db.groups[2]);
  add_member_to_group(db.members[3], db.groups[2]);
  add_member_to_group(db.members[4], db.groups[0]);
  add_member_to_group(db.members[5], db.groups[1]);

  db.BuildMemberGraph();
  double total_weight = db.BestGroupsToJoin(db.members[3]);
  EXPECT_EQ(total_weight, 21);


  return true;
}


int main() {

  if (!TestMST()) {
    std::cout << "TestMST failed\n";
    return -1;
  }

  std::cout << "Test passed.\n";
}
