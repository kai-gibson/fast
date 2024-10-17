#ifndef ARCHIVE_H
#define ARCHIVE_H

#include <array>
#include <sstream>
#include <stdexcept>
#include <string> 
#include <unordered_map>
#include <variant>
#include <vector>
#include <type_traits>

#include "fast/model.h"

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
concept DerivedFromModel = std::derived_from<T, Model>;

class Archive {
 public:
  template<DerivedFromModel D>
  void add(const char* name, std::vector<D>* data) {
    // base method demands enough elements in vector, then passes on to other
    // derived add methods?

    // get_arr_count should throw if it's not an array, so after this it's safe
    size_t requested_size = get_obj_arr_count(name);

    // input archive
    if (requested_size) {
      // clear vector
      data->clear();

      // create enough elements
      for (size_t i=0; i < requested_size; i++) {
        data->push_back(D());
        assign_arr_val(name, i, &data->back());
      }
    } else {
      // output archive
      for (size_t i{}; i<data->size(); i++) {
        if (i == data->size()-1) {
          assign_arr_val("", -1, &data->at(i));
        } else if (i == 0) {
          assign_arr_val(name, i, &data->at(i));
        } else {
          assign_arr_val("", i, &data->at(i));
        }
      }
    }
  }
  // we use const char* because they're smaller and never modified
  virtual void add(const char* name, int64_t* data) = 0;
  virtual void add(const char* name, double* data) = 0;
  virtual void add(const char* name, std::string* data) = 0;
  virtual void add(const char* name, bool* data) = 0;
  virtual void add(const char* name, Model* data) = 0;
  virtual void add(const char* name, std::vector<int64_t>* data) = 0;
  virtual void add(const char* name, std::vector<double>* data) = 0;
  virtual void add(const char* name, std::vector<std::string>* data) = 0;
  virtual void add(const char* name, std::vector<bool>* data) = 0;


  // helper methods to facilitate serialisation of vectors of objects
  // TODO change these to make sense for input and output
  virtual size_t get_obj_arr_count(const char* name) = 0;
  virtual void assign_arr_val(const char* name, size_t indx, Model* obj) = 0;

  virtual std::string str() = 0;
};

}  // namespace fast

#endif  // ARCHIVE_H
