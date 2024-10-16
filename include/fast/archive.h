#ifndef ARCHIVE_H
#define ARCHIVE_H

#include <array>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

#include "fast/archivable.h"

namespace fast {

// interface for an Archiver classes
/*
 * This is a generic archiver interface that enables associating struct fields
 * with their string names, loading json data, string data, sql data, etc into
 * the archiver, then mapping that data against the struct fields.
 *
 * It does this without using any fancy templating and so avoids significant
 * compile time overhead.
 *
 * Any type of archive, i.e. JsonInputArchive, JsonOutputArchive,
 * SqlInputArchive, etc. must implement "add" functions for ALL datatypes
 * If you'd like to support your own datatypes then add an add function to the
 * Archive interface for it, then implement that new function for every archive
 * type.
 *
 */

template <class T>
concept DerivedFromArchivable = std::derived_from<T, Archivable>;

class Archive {
 public:

  template<DerivedFromArchivable T>
  void add(std::string name, std::vector<T>* data) {
    // base method demands enough elements in vector, then passes on to other
    // derived add methods?

    // get_arr_count should throw if it's not an array, so after this it's safe
    size_t requested_size = get_obj_arr_count(name);

    // clear vector
    data->clear();

    // create enough elements
    for (size_t i=0; i < requested_size; i++) {
      data->push_back(T());
      assign_arr_val(name, i, &data->back());
    }
  }

  virtual void add(std::string name, int64_t* data) = 0;
  virtual void add(std::string name, double* data) = 0;
  virtual void add(std::string name, std::string* data) = 0;
  virtual void add(std::string name, bool* data) = 0;
  virtual void add(std::string name, Archivable* data) = 0;
  virtual void add(std::string name, std::vector<int64_t>* data) = 0;
  virtual void add(std::string name, std::vector<double>* data) = 0;
  virtual void add(std::string name, std::vector<std::string>* data) = 0;
  virtual void add(std::string name, std::vector<bool>* data) = 0;
  virtual size_t get_obj_arr_count(std::string name) = 0;
  virtual void assign_arr_val(std::string name, size_t indx, Archivable* obj) = 0;
  //virtual void add(std::string name, std::vector<Archivable>* data) = 0;
  virtual void deserialise() = 0;
  virtual void serialise() = 0;

};

}  // namespace fast

#endif  // ARCHIVE_H
