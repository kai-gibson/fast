#include "fast/db/create_db.h"

#include <iostream>
namespace fast {

std::tuple<std::shared_ptr<Database>, DBResult> create_db(
    DBProvider::Provider provider, const char* conn_str) {

  std::shared_ptr<Database> db;
  DBResult err {0, ""};
  
  switch (provider) {
    case DBProvider::SQLite:
      try {
        db = std::make_shared<SQLite>(conn_str);
      } catch (std::runtime_error& e) {
        return {nullptr, {-1, e.what()}};
      }
			break;
    case DBProvider::Firebird:
      err = {1, "not implemented"};
			break;
    case DBProvider::MariaDB:
      err = {1, "not implemented"};
			break;
    case DBProvider::PostgreSQL:
      err = {1, "not implemented"};
			break;
  }

  return {db, err};
}

}  // namespace fast
