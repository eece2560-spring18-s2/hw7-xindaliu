#include <cstdlib>
#include <iostream>

#include "database.h"
#include "timer.h"

int main() {
  using namespace algdb;

  Timer timer;
  Database db;
  db.LoadData("../data", 10000, 10000, 100000);

  timer.Start();
  db.BuildMemberGraph();
  auto time = timer.End();

  for (auto m : db.members) {
    m->DumpConnections();
  }
  std::cout << "Time to build member graph " << time << "\n";
}
