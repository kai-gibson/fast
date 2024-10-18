#ifndef FAST_SQLITE3_H
#define FAST_SQLITE3_H

#include "fast/db/db.h"
#include "fast/archives/sql.h"
#include <sqlite3.h>

namespace fast {

namespace sqlite {

int callback(void* data, int argc, char** col_data, char** col_names);

} // namespace sqlite

class SQLite : public Database, public std::enable_shared_from_this<SQLite> {
 private:
  sqlite3* db {};

 public:
  SQLite(const char* conn_str);
  // virtual methods
  DBResult query(const char* stmt);

  // should make these private
  DBResult populate_rows(const char* stmt, Rows* rows);
  DBResult assign_row_to_model(Row& row, Model* obj);
  std::string str();
  void rollback();

  ~SQLite();
};

} // namespace fast

#endif //FAST_SQLITE3_H
