#ifndef FAST_CREATE_DB
#define FAST_CREATE_DB

#include <tuple>

#include "fast/db/sqlite3.h"

namespace fast {

std::tuple<std::shared_ptr<Database>, DBResult> create_db(
    DBProvider::Provider provider, const char* conn_str);
}  // namespace fast

#endif  // FAST_CREATE_DB
