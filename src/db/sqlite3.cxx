#include "fast/db/sqlite3.h"
#include "fast/archives/sql.h"

#include <cstring>
#include <cassert>
#include <iostream>

namespace fast {
namespace sqlite {

int callback(void* data, int argc, char** col_data, char** col_names) {
  auto rows = static_cast<Rows*>(data);

  rows->push_back({});

  // fill the rows
  for (int i = 0; i < argc; i++) {
    rows->back()[col_names[i]] = col_data[i] ? col_data[i] : "null";
  }

  return 0;
}

} // namespace sqlite

SQLite::SQLite(const char* conn_str) {
  int result = sqlite3_open(conn_str, &db);

  if (result != SQLITE_OK) {
    throw std::runtime_error("failed to open db");
  }
}

SQLite::~SQLite() {
  sqlite3_close(db);
}


DBResult SQLite::query(const char* stmt) {
  DBResult err{};

  char* err_msg;
  int rc = sqlite3_exec(db, stmt, &sqlite::callback, nullptr, &err_msg);

  if (rc != SQLITE_OK) {
    err = {rc, std::string(err_msg)};

    sqlite3_free(err_msg);
    return err;
  }
  
  return err;
}

void SQLite::rollback() {
}

DBResult SQLite::populate_rows(const char* stmt, Rows* rows) {
  DBResult err;

  char* err_msg {};
  int rc = sqlite3_exec(db, stmt, &sqlite::callback, (void*)rows, &err_msg);

  if (rc != SQLITE_OK) {
    err = {rc, std::string(err_msg)};

    sqlite3_free(err_msg);
    return err;
  }
  
  return err;
}

DBResult SQLite::assign_row_to_model(Row& row, Model* obj) {
  DBResult err;
  SQLiteIArchive iar(row);

  try {
    obj->load_metadata(iar);
  } catch (std::runtime_error& e) {
    err = {1, e.what()};
  }

  return err;
}



} // namespace fast
