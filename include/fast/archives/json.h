#ifndef FAST_ARCHIVE_JSON_H
#define FAST_ARCHIVE_JSON_H

#include <rapidjson/document.h>

#include "fast/archive.h"

namespace rj = rapidjson;

namespace fast {

// scoped enum
struct JsonType {
  enum {
    Int64,
    Float64,
    String,
    Bool,
    Object,
    ArrayInt64,
    ArrayFloat64,
    ArrayString,
    ArrayBool,
    ArrayObject,
  };
};

const std::array<const char*, 6> JSON_TYPE_NAMES = {
    "Int64", "Float64", "String", "Bool", "Object", "Array",
};

class JsonArchive : public Archive {
 private:
  std::unordered_map<
      std::string, std::variant<int64_t*, double*, std::string*, bool*,
                                Archivable*, std::vector<int64_t>*,
                                std::vector<double>*, std::vector<std::string>*,
                                std::vector<bool>*, std::vector<Archivable>*>>
      map;

  rj::Document json_doc;
  rj::Value* json_root{};
  std::string json_str;
  bool err;

 public:
  void load_data(std::string json_str);

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
  void add(std::string name, std::vector<Archivable>* data) override;
  void deserialise() override;
  void serialise() override;

  JsonArchive(rj::Value* json_root = nullptr) {
    if (json_root) {
      this->json_root = json_root;
    } else {
      this->json_root = &json_doc;
    }
  }
};

};  // namespace fast

#endif  // FAST_ARCHIVE_JSON_H
