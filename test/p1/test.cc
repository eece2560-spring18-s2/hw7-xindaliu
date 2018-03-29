#include <iostream>

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

#define EXPECT_PTR_EQ(act, exp) \
  if ((act) != (exp)) { \
    printf("%s:%d %s expected %p, but get %p\n",\
        __FILE__, __LINE__, __FUNCTION__, exp, act); \
    return false;\
  }

void add_member_to_group(Member *m, Group *g) {
  m->groups.push_back(g);
  g->members.push_back(m);
}

bool TestBuildMemberGraph() {
  Database db;

  for (int i = 0; i < 6; i++) {
    Member *m = new Member();
    m->member_id = i;
    db.members.push_back(m);
  }

  for (int i = 0; i < 3; i++) {
    Group *g = new Group();
    g->group_id = i;
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

  EXPECT_EQ(db.members[0]->connecting_members.size(), 5);
  EXPECT_EQ(db.members[1]->connecting_members.size(), 4);
  EXPECT_EQ(db.members[2]->connecting_members.size(), 4);
  EXPECT_EQ(db.members[3]->connecting_members.size(), 2);
  EXPECT_EQ(db.members[4]->connecting_members.size(), 2);
  EXPECT_EQ(db.members[5]->connecting_members.size(), 3);

  return true;
}


int main() {

  if (!TestBuildMemberGraph()) {
    std::cout << "TestBuildMemberGraph failed\n";
    return -1;
  }

  std::cout << "Test passed.\n";
}
