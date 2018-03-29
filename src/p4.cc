#include <cstdlib>
#include <iostream>

#include "database.h"
#include "timer.h"

int main() {
  using namespace algdb;

  Timer timer;
  Database db;
  db.LoadData("../data", 10000, 10000, 100000);
  db.RandomizeGraph(100000);
  std::cout << "Building graph completed.\n";

  Member *src = db.member_id_hash_index[3];
  Member *dst = db.member_id_hash_index[6];

  timer.Start();
  db.BestGroupsToJoin(src);
  auto time = timer.End();

  src->PrintPath(dst);

  std::cout << "\nTime to generate MST " << time << "\n";
}
