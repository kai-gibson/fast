#ifndef FAST_ARCHIVE_JSON_H
#define FAST_ARCHIVE_JSON_H

#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

#include "fast/archive.h"

#include <memory>

namespace rj = rapidjson;

namespace fast {

// scoped enum
struct JsonType {
  enum {
    Null,
    False,
    True,
    Object,
    Array,
    String,
    Number,
  };
};

const std::array<const char*, 7> JSON_TYPE_NAMES = {
    "Null",
    "False",
    "True",
    "Object",
    "Array",
    "String",
    "Number"
};

//template <class T>
//concept DerivedFromArchivable = std::derived_from<T, Archivable>;

class JsonIArchive : public Archive {
 private:
  rj::Document json_doc;
  
  // use this pointer to handle nested objects
  rj::Value* json_root{};
  bool err;

 public:
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
  
  // need these 2 for object arrays
  size_t get_obj_arr_count(const char* name) override;
  void assign_arr_val(const char* name, size_t indx, Model* obj) override;

  std::string str() override;

  // construct from either string or a pointer to a rj value
  JsonIArchive(rj::Value* json_root = nullptr);
  JsonIArchive(const char* json_str);
};

class JsonOArchive : public Archive {
 private:
  rj::StringBuffer s;
  //rj::Writer<rj::StringBuffer> writer_obj{s};
  std::shared_ptr<rj::Writer<rj::StringBuffer>> writer;

 public:
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
  
  // need these 2 for object arrays
  size_t get_obj_arr_count(const char* name) override;
  void assign_arr_val(const char* name, size_t indx, Model* obj) override;

  std::string str() override;
  JsonOArchive(std::shared_ptr<rj::Writer<rj::StringBuffer>>& writer);
  JsonOArchive();
};

};  // namespace fast


#endif  // FAST_ARCHIVE_JSON_H
