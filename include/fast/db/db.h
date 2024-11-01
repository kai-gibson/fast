#ifndef FAST_DB_H
#define FAST_DB_H

#include <memory>

#include "fast/archive.h"
#include "fast/model.h"
#include <unordered_map>
#include <vector>
#include <string>

namespace fast {

struct DBProvider {
  enum Provider {
    SQLite,
    Firebird,
    MariaDB,
    PostgreSQL,
  };
};

struct DBResult {
  int result_code;
  std::string detail;
  operator bool() const { return result_code != 0; }
};

typedef std::unordered_map<std::string, std::string> Row;
typedef std::vector<Row> Rows;

class Database {
 public:
  template <DerivedFromModel D>
  DBResult select(const char* stmt, std::vector<D>* obj) {
    DBResult err {0, ""};
  
    Rows rows;

    err = populate_rows(stmt, &rows);
    if (err) return err;

    for (Row& row : rows) {
      obj->push_back(D());

      err = assign_row_to_model(row, &obj->back());
      if (err) return err;
    }

    return err;
  }

  virtual DBResult populate_rows(const char* stmt, Rows* rows) = 0;
  virtual DBResult assign_row_to_model(Row& row, Model* obj) = 0;
  virtual DBResult query(const char* stmt) = 0;
  virtual void rollback() = 0;

  virtual ~Database() {}
};

}  // namespace fast

#endif  // FAST_DB_H
