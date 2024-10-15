#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>

#include <sstream>

#include "fast/archives/json.h"

/*
 * JsonArchive implementation
 * TODO:
 *  - make exception type
 *  - handle arrays with differently typed elements
 *  - optional fields
 *  
*/

namespace fast {

void JsonArchive::add(std::string name, int64_t* data) {
  this->map[name] = data;
}

void JsonArchive::add(std::string name, double* data) {
  this->map[name] = data;
}

void JsonArchive::add(std::string name, std::string* data) {
  this->map[name] = data;
}

void JsonArchive::add(std::string name, bool* data) { this->map[name] = data; }

void JsonArchive::add(std::string name, Archivable* data) {
  this->map[name] = data;
}

void JsonArchive::add(std::string name, std::vector<int64_t>* data) {
  this->map[name] = data;
}

void JsonArchive::add(std::string name, std::vector<double>* data) {
  this->map[name] = data;
}

void JsonArchive::add(std::string name, std::vector<std::string>* data) {
  this->map[name] = data;
}

void JsonArchive::add(std::string name, std::vector<bool>* data) {
  this->map[name] = data;
}

void JsonArchive::add(std::string name, std::vector<Archivable>* data) {
  this->map[name] = data;
}

void JsonArchive::load_data(std::string json_str) { this->json_str = json_str; }

void JsonArchive::deserialise() {
  if (json_doc.Parse(json_str.c_str()).HasParseError()) {
    std::runtime_error("Error parsing json, invalid json");
  } 

  json_root = &json_doc;

  std::stringstream err;

  for (auto& [key, value] : this->map) {
    if (json_root->HasMember(key.c_str())) {
      rj::Value& json_val = (*json_root)[key.c_str()];

      switch (value.index()) {
        case JsonType::Int64: {
          if (json_val.IsInt64()) {
            int64_t* ptr = std::get<JsonType::Int64>(value);
            *ptr = json_val.GetInt64();
          } else {
            err << "Error, key \"" << key << "\" type is " << json_val.GetType() 
                << " but " << JSON_TYPE_NAMES[value.index()]
                << " was expected";

            throw std::runtime_error(err.str());
          }
          break;
        }

        case JsonType::Float64: {
          if (json_val.IsDouble()) {
            double* ptr = std::get<JsonType::Float64>(value);
            *ptr = json_val.GetDouble();
          } else {
            err << "Error, key \"" << key << "\" type is " << json_val.GetType() 
                << " but " << JSON_TYPE_NAMES[value.index()]
                << " was expected";

            throw std::runtime_error(err.str());
          }
          break;
        }

        case JsonType::String: {
          if (json_val.IsString()) {
            std::string* ptr = std::get<JsonType::String>(value);
            *ptr = json_val.GetString();
          } else {
            err << "Error, key \"" << key << "\" type is " << json_val.GetType() 
                << " but " << JSON_TYPE_NAMES[value.index()]
                << " was expected";

            throw std::runtime_error(err.str());
          }
          break;
        }

        case JsonType::Bool: {
          if (json_val.IsBool()) {
            bool* ptr = std::get<JsonType::Bool>(value);
            *ptr = json_val.GetBool();
          } else {
            err << "Error, key \"" << key << "\" type is " << json_val.GetType() 
                << " but " << JSON_TYPE_NAMES[value.index()]
                << " was expected";

            throw std::runtime_error(err.str());
          }
          break;
        }

        case JsonType::Object: {
          if (json_val.IsObject()) {
            JsonArchive iar(&json_val);

            Archivable* ptr = std::get<JsonType::Object>(value);
            ptr->load_metadata(iar);
            iar.deserialise();

          } else {
            err << "Error, key \"" << key << "\" type is " << json_val.GetType() 
                << " but " << JSON_TYPE_NAMES[value.index()]
                << " was expected";

            throw std::runtime_error(err.str());
          }
          break;
        }

        case JsonType::ArrayInt64: {
          if (json_val.IsArray()) {
            std::vector<int64_t>* int_vec_ptr = 
              std::get<JsonType::ArrayInt64>(value);

            for (auto& elem : json_val.GetArray()) {
              if (elem.IsInt64()) {
                int_vec_ptr->push_back(elem.GetInt64());
              } else {
                err << "Error, key \"" << key << "\" type is " << json_val.GetType() 
                    << " but " << JSON_TYPE_NAMES[value.index()]
                    << " was expected";
              }
            }
          } else {
            err << "Error, key \"" << key << "\" type is " << json_val.GetType() 
                << " but " << JSON_TYPE_NAMES[value.index()]
                << " was expected";

            throw std::runtime_error(err.str());
          }
          break;
        }

        case JsonType::ArrayFloat64: {
          if (json_val.IsArray()) {
            std::vector<double>* int_vec_ptr = 
              std::get<JsonType::ArrayFloat64>(value);

            for (auto& elem : json_val.GetArray()) {
              if (elem.IsDouble()) {
                int_vec_ptr->push_back(elem.GetDouble());
              } else {
                err << "Error, key \"" << key << "\" type is " << json_val.GetType() 
                    << " but " << JSON_TYPE_NAMES[value.index()]
                    << " was expected";
              }
            }
          } else {
            err << "Error, key \"" << key << "\" type is " << json_val.GetType() 
                << " but " << JSON_TYPE_NAMES[value.index()]
                << " was expected";

            throw std::runtime_error(err.str());
          }
          break;
        }

        case JsonType::ArrayBool: {
          if (json_val.IsArray()) {
            std::vector<bool>* int_vec_ptr = 
              std::get<JsonType::ArrayBool>(value);

            for (auto& elem : json_val.GetArray()) {
              if (elem.IsBool()) {
                int_vec_ptr->push_back(elem.GetBool());
              } else {
                err << "Error, key \"" << key << "\" type is " << json_val.GetType() 
                    << " but " << JSON_TYPE_NAMES[value.index()]
                    << " was expected";
              }
            }
          } else {
            err << "Error, key \"" << key << "\" type is " << json_val.GetType() 
                << " but " << JSON_TYPE_NAMES[value.index()]
                << " was expected";

            throw std::runtime_error(err.str());
          }
          break;
        }

        case JsonType::ArrayString: {
          if (json_val.IsArray()) {
            std::vector<std::string>* int_vec_ptr = 
              std::get<JsonType::ArrayString>(value);

            for (auto& elem : json_val.GetArray()) {
              if (elem.IsString()) {
                int_vec_ptr->push_back(elem.GetString());
              } else {
                err << "Error, key \"" << key << "\" type is " << json_val.GetType() 
                    << " but " << JSON_TYPE_NAMES[value.index()]
                    << " was expected";
              }
            }
          } else {
            err << "Error, key \"" << key << "\" type is " << json_val.GetType() 
                << " but " << JSON_TYPE_NAMES[value.index()]
                << " was expected";

            throw std::runtime_error(err.str());
          }
          break;
        }

        case JsonType::ArrayObject: {
          if (json_val.IsArray()) {
            std::vector<Archivable>* obj_vec_ptr = 
              std::get<JsonType::ArrayObject>(value);

            for (auto& elem : json_val.GetArray()) {
              if (elem.IsObject()) {

                json_val.GetArray().Size();

                JsonArchive iar(&elem);

                // next challenge...
              } else {
                err << "Error, key \"" << key << "\" type is " 
                    << json_val.GetType() 
                    << " but " << JSON_TYPE_NAMES[value.index()]
                    << " was expected";
              }
            }
          } else {
            err << "Error, key \"" << key << "\" type is " << json_val.GetType() 
                << " but " << JSON_TYPE_NAMES[value.index()]
                << " was expected";

            throw std::runtime_error(err.str());
          }
          break;
        }
      }
    } else {
      err << "error, key " << key << " does not exist in parsed json\n";
      throw std::runtime_error(err.str());
    }
  }
}

}  // namespace fast
