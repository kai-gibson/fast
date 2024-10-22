#ifndef FAST_ARCHIVE_SQL_H
#define FAST_ARCHIVE_SQL_H

#include "fast/archive.h"
#include "fast/db/db.h"

namespace fast {

// idk if i need this
class SqlArchive : public Archive {
 private:
 public:
};

class SQLiteIArchive : public SqlArchive {
 private:
  Row& row;
 public:
  SQLiteIArchive(Row& row);
  // overrides
  void add(const char* name, int64_t* data) override;
  void add(const char* name, double* data) override;
  void add(const char* name, std::string* data) override;
  void add(const char* name, bool* data) override;
  void add(const char* name, Model* data) override;
  void add(const char* name, std::vector<int64_t>* data) override;
  void add(const char* name, std::vector<double>* data) override;
  void add(const char* name, std::vector<std::string>* data) override;
  void add(const char* name, std::vector<bool>* data) override;

  size_t get_obj_arr_count(const char* name) override;
  void assign_arr_val(const char* name, size_t indx, Model* obj) override;

  std::string str() override;
};

}  // namespace fast

#endif  // FAST_ARCHIVE_SQL_H
