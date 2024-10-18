#include "fast/archives/sql.h"

#include <cstring>

namespace fast {

SQLiteIArchive::SQLiteIArchive(Row& row) : row(row) {}

// overrides
void SQLiteIArchive::add(const char* name, int64_t* data) {
  if (row.contains(name)) {
    try {
      *data = std::stol(row[name]);
    } catch (std::exception& e) {
      std::stringstream err;
      err << "error converting sql column to int64_t: " << e.what();
      throw std::runtime_error(err.str());
    }
  } else {
    std::stringstream err;
    err << "error, column \"" << name << "\" not found in results";
    throw std::runtime_error(err.str());
  }
}

void SQLiteIArchive::add(const char* name, double* data) {
  if (row.contains(name)) {
    try {
      *data = std::stod(row[name]);
    } catch (std::exception& e) {
      std::stringstream err;
      err << "error converting sql column to int64_t: " << e.what();
      throw std::runtime_error(err.str());
    }
  } else {
    std::stringstream err;
    err << "error, column \"" << name << "\" not found in results";
    throw std::runtime_error(err.str());
  }
}

void SQLiteIArchive::add(const char* name, std::string* data) {
  if (row.contains(name)) {
    try {
      *data = row[name];
    } catch (std::exception& e) {
      std::stringstream err;
      err << "error converting sql column to int64_t: " << e.what();
      throw std::runtime_error(err.str());
    }
  } else {
    std::stringstream err;
    err << "error, column \"" << name << "\" not found in results";
    throw std::runtime_error(err.str());
  }
}

void SQLiteIArchive::add(const char* name, bool* data) {
  if (row.contains(name)) {
    try {
      *data = row[name] == "true" ? true : false;
    } catch (std::exception& e) {
      std::stringstream err;
      err << "error converting sql column to int64_t: " << e.what();
      throw std::runtime_error(err.str());
    }
  } else {
    std::stringstream err;
    err << "error, column \"" << name << "\" not found in results";
    throw std::runtime_error(err.str());
  }
}

void SQLiteIArchive::add(const char* name, Model* data) {
  throw std::runtime_error("nested objects not possible in sql");
}

void SQLiteIArchive::add(const char* name, std::vector<int64_t>* data) {
  throw std::runtime_error("arrays not possible in sql");
}

void SQLiteIArchive::add(const char* name, std::vector<double>* data) {
  throw std::runtime_error("arrays not possible in sql");
}

void SQLiteIArchive::add(const char* name, std::vector<std::string>* data) {
  throw std::runtime_error("arrays not possible in sql");
}

void SQLiteIArchive::add(const char* name, std::vector<bool>* data) {
  throw std::runtime_error("arrays not possible in sql");
}

// shouldn't happen
size_t SQLiteIArchive::get_obj_arr_count(const char* name) {
  throw std::runtime_error(
      "serialisation of an array of objects is not possible in sql");
}

void SQLiteIArchive::assign_arr_val(const char* name, size_t indx, Model* obj) {
  throw std::runtime_error(
      "serialisation of an array of objects is not possible in sql");
}


std::string SQLiteIArchive::str() { return ""; }

} // namespace fast
