#ifndef FAST_ARCHIVE_JSON_H
#define FAST_ARCHIVE_JSON_H

#include <rapidjson/document.h>

#include "fast/archive.h"

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

class JsonArchive : public Archive {
 private:
  //std::unordered_map<
  //    std::string, std::variant<int64_t*, double*, std::string*, bool*,
  //                              Archivable*, std::vector<int64_t>*,
  //                              std::vector<double>*, std::vector<std::string>*,
  //                              std::vector<bool>*, std::vector<Archivable>*>>
  //    map;

  rj::Document json_doc;
  rj::Value* json_root{};
  std::string json_str;
  bool err;

 public:
  void load_data(std::string json_str);

  //// handle array of objects
  //template <DerivedFromArchivable T>
  //void add(std::string name, std::vector<T>* data) {
  //  if (json_root->HasMember(name.c_str())) {
  //    rj::Value& json_val = (*json_root)[name.c_str()];

  //    if (json_val.IsArray()) {
  //      // remove all existing elements
  //      data->clear();

  //      for (auto& elem : json_val.GetArray()) {
  //        if (elem.IsObject()) {
  //          JsonArchive iar(&elem);
  //          data->push_back(T());
  //          data->end().load_metadata(iar);

  //          //rj::Value* prev_root = json_root;
  //          //this->json_root = &elem;

  //          //data->end().load_metadata(*this);
  //          //this->json_root = prev_root;
  //        } else {
  //          std::stringstream err;

  //          err << "Error, key \"" << name << "\" type is " << json_val.GetType()
  //              << " but Array<Bool> was expected";
  //        }

  //      }
  //    } else {
  //      std::stringstream err;

  //      err << "Error, key \"" << name << "\" type is " << json_val.GetType()
  //          << " but Array<Bool> was expected";

  //      throw std::runtime_error(err.str());
  //    }
  //  } else {
  //    std::stringstream err;
  //    err << "error, key \"" << name << "\" does not exist in parsed json\n";

  //    throw std::runtime_error(err.str());
  //  }
  //}

  // overrides
  void add(std::string name, int64_t* data) override;
  void add(std::string name, double* data) override;
  void add(std::string name, std::string* data) override;
  void add(std::string name, bool* data) override;
  void add(std::string name, Archivable* data) override;
  void add(std::string name, std::vector<int64_t>* data) override;
  void add(std::string name, std::vector<double>* data) override;
  void add(std::string name, std::vector<std::string>* data) override;
  void add(std::string name, std::vector<bool>* data) override;
  
  // need these 2 for object arrays
  size_t get_obj_arr_count(std::string name) override;
  void assign_arr_val(std::string name, size_t indx, Archivable* obj) override;

  void deserialise() override;
  void serialise() override;

  JsonArchive(rj::Value* json_root = nullptr);
  JsonArchive(std::string json_str);
};

};  // namespace fast


#endif  // FAST_ARCHIVE_JSON_H
