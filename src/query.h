#ifndef QUERY_H_
#define QUERY_H_

#include "database.h"
#include "result_set.h"

namespace algdb {

template <typename T>
class Query {
 protected:
  Database *db_;

 public:
  Query(Database *db) {
    db_ = db;
    priority = 0;
  }

  virtual ~Query() {}

  virtual ResultSet<T> Execute() = 0;

  int priority;
};

class MockQuery : public Query<int> {
  public:
   MockQuery() : Query(NULL) {}

   ResultSet<int> Execute() {
     ResultSet<int> rs;
     return rs;
   }
};

}

#endif  // QUERY_H_