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

class Archive {
 public:
  virtual void add(std::string name, int64_t* data) = 0;
  virtual void add(std::string name, double* data) = 0;
  virtual void add(std::string name, std::string* data) = 0;
  virtual void add(std::string name, bool* data) = 0;
  virtual void add(std::string name, Archivable* data) = 0;
  virtual void add(std::string name, std::vector<int64_t>* data) = 0;
  virtual void add(std::string name, std::vector<double>* data) = 0;
  virtual void add(std::string name, std::vector<std::string>* data) = 0;
  virtual void add(std::string name, std::vector<bool>* data) = 0;
  virtual void add(std::string name, std::vector<Archivable>* data) = 0;
  virtual void deserialise() = 0;
  virtual void serialise() = 0;
};

}  // namespace fast

#endif  // ARCHIVE_H
