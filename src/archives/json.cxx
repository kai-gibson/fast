#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>
#include <rapidjson/error/en.h>

#include <sstream>
#include <iostream>

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

JsonArchive::JsonArchive(rj::Value* json_root) {
  if (json_root) {
    this->json_root = json_root;
  } else {
    this->json_root = &json_doc;
  }
}

JsonArchive::JsonArchive(std::string json_str) {
  rj::ParseResult res = json_doc.Parse(json_str.c_str());
  if (!res) {
    std::stringstream err;
    err << "JSON Parse Error " << rj::GetParseError_En(res.Code()) << " "
        << res.Offset();

    std::cerr << err.str();
    throw std::runtime_error("parse error");
  }
  this->json_root = &json_doc;
}

void JsonArchive::add(std::string name, int64_t* data) {
  if (json_root->HasMember(name.c_str())) {
    rj::Value& json_val = (*json_root)[name.c_str()];

    if (json_val.IsInt64()) {
      *data = json_val.GetInt64();
    } else {
      std::stringstream err;

      err << "Error, key \"" << name << "\" type is " 
          << JSON_TYPE_NAMES[json_val.GetType()]
          << " but Int64 was expected";

      throw std::runtime_error(err.str());
    }
  } else {
    std::stringstream err;
    err << "error, key \"" << name << "\" does not exist in parsed json\n";

    throw std::runtime_error(err.str());
  }
}

void JsonArchive::add(std::string name, double* data) {
  if (json_root->HasMember(name.c_str())) {
    rj::Value& json_val = (*json_root)[name.c_str()];

    if (json_val.IsDouble()) {
      *data = json_val.GetDouble();
    } else {
      std::stringstream err;

      err << "Error, key \"" << name << "\" type is " 
          << JSON_TYPE_NAMES[json_val.GetType()]
          << " but Float64 was expected";

      throw std::runtime_error(err.str());
    }
  } else {
    std::stringstream err;
    err << "error, key \"" << name << "\" does not exist in parsed json\n";

    throw std::runtime_error(err.str());
  }
}

void JsonArchive::add(std::string name, std::string* data) {
  if (json_root->HasMember(name.c_str())) {
    rj::Value& json_val = (*json_root)[name.c_str()];

    if (json_val.IsString()) {
      *data = json_val.GetString();
    } else {
      std::stringstream err;

      err << "Error, key \"" << name << "\" type is " 
          << JSON_TYPE_NAMES[json_val.GetType()]
          << " but String was expected";

      throw std::runtime_error(err.str());
    }
  } else {
    std::stringstream err;
    err << "error, key \"" << name << "\" does not exist in parsed json\n";

    throw std::runtime_error(err.str());
  }
}

void JsonArchive::add(std::string name, bool* data) { 
  if (json_root->HasMember(name.c_str())) {
    rj::Value& json_val = (*json_root)[name.c_str()];

    if (json_val.IsBool()) {
      *data = json_val.GetBool();
    } else {
      std::stringstream err;

      err << "Error, key \"" << name << "\" type is " 
          << JSON_TYPE_NAMES[json_val.GetType()]
          << " but Bool was expected";

      throw std::runtime_error(err.str());
    }
  } else {
    std::stringstream err;
    err << "error, key \"" << name << "\" does not exist in parsed json\n";

    throw std::runtime_error(err.str());
  }
}

void JsonArchive::add(std::string name, Archivable* data) {
  if (json_root->HasMember(name.c_str())) {
    rj::Value& json_val = (*json_root)[name.c_str()];

    if (json_val.IsObject()) {
      // recursive assign to object
      JsonArchive iar(&json_val);
      data->load_metadata(iar);

    } else {
      std::stringstream err;

      err << "Error, key \"" << name << "\" type is " << JSON_TYPE_NAMES[json_val.GetType()]
          << " but Object was expected";

      throw std::runtime_error(err.str());
    }
  } else {
    std::stringstream err;
    err << "error, key \"" << name << "\" does not exist in parsed json\n";

    throw std::runtime_error(err.str());
  }
}

void JsonArchive::add(std::string name, std::vector<int64_t>* data) {
  if (json_root->HasMember(name.c_str())) {
    rj::Value& json_val = (*json_root)[name.c_str()];

    if (json_val.IsArray()) {
      // remove all existing elements
      data->clear();

      for (auto& elem : json_val.GetArray()) {
        if (elem.IsInt64()) {
          data->push_back(elem.GetInt64());
        } else {
          std::stringstream err;

          err << "Error, key \"" << name << "\" type is " 
              << JSON_TYPE_NAMES[json_val.GetType()]
              << " but Array<Int64> was expected";
        }

      }
    } else {
      std::stringstream err;

      err << "Error, key \"" << name << "\" type is " 
          << JSON_TYPE_NAMES[json_val.GetType()]
          << " but Array<Int64> was expected";

      throw std::runtime_error(err.str());
    }
  } else {
    std::stringstream err;
    err << "error, key \"" << name << "\" does not exist in parsed json\n";

    throw std::runtime_error(err.str());
  }
}

void JsonArchive::add(std::string name, std::vector<double>* data) {
  if (json_root->HasMember(name.c_str())) {
    rj::Value& json_val = (*json_root)[name.c_str()];

    if (json_val.IsArray()) {
      // remove all existing elements
      data->clear();

      for (auto& elem : json_val.GetArray()) {
        if (elem.IsDouble()) {
          data->push_back(elem.GetDouble());
        } else {
          std::stringstream err;

          err << "Error, key \"" << name << "\" type is " 
              << JSON_TYPE_NAMES[json_val.GetType()]
              << " but Array<Float64> was expected";
        }

      }
    } else {
      std::stringstream err;

      err << "Error, key \"" << name << "\" type is " 
          << JSON_TYPE_NAMES[json_val.GetType()]
          << " but Array<Float64> was expected";

      throw std::runtime_error(err.str());
    }
  } else {
    std::stringstream err;
    err << "error, key \"" << name << "\" does not exist in parsed json\n";

    throw std::runtime_error(err.str());
  }
}

void JsonArchive::add(std::string name, std::vector<std::string>* data) {
  if (json_root->HasMember(name.c_str())) {
    rj::Value& json_val = (*json_root)[name.c_str()];

    if (json_val.IsArray()) {
      // remove all existing elements
      data->clear();

      for (auto& elem : json_val.GetArray()) {
        if (elem.IsString()) {
          data->push_back(elem.GetString());

        } else {
          std::stringstream err;

          err << "Error, key \"" << name << "\" type is " 
              << JSON_TYPE_NAMES[json_val.GetType()]
              << " but Array<String> was expected";
        }

      }
    } else {
      std::stringstream err;

      err << "Error, key \"" << name << "\" type is " 
          << JSON_TYPE_NAMES[json_val.GetType()]
          << " but Array<String> was expected";

      throw std::runtime_error(err.str());
    }
  } else {
    std::stringstream err;
    err << "error, key \"" << name << "\" does not exist in parsed json\n";

    throw std::runtime_error(err.str());
  }
}

void JsonArchive::add(std::string name, std::vector<bool>* data) {
  if (json_root->HasMember(name.c_str())) {
    rj::Value& json_val = (*json_root)[name.c_str()];

    if (json_val.IsArray()) {
      // remove all existing elements
      data->clear();

      for (auto& elem : json_val.GetArray()) {
        if (elem.IsBool()) {
          data->push_back(elem.GetBool());

        } else {
          std::stringstream err;

          err << "Error, key \"" << name << "\" type is " 
              << JSON_TYPE_NAMES[json_val.GetType()]
              << " but Array<Bool> was expected";
          throw std::runtime_error(err.str());
        }

      }
    } else {
      std::stringstream err;

      err << "Error, key \"" << name << "\" type is " 
          << JSON_TYPE_NAMES[json_val.GetType()]
          << " but Array<Bool> was expected";

      throw std::runtime_error(err.str());
    }
  } else {
    std::stringstream err;
    err << "error, key \"" << name << "\" does not exist in parsed json\n";

    throw std::runtime_error(err.str());
  }
}

void JsonArchive::load_data(std::string json_str) { this->json_str = json_str; }

size_t JsonArchive::get_obj_arr_count(std::string name) {
  if (json_root->HasMember(name.c_str())) {
    rj::Value& val = (*json_root)[name.c_str()];

    if (val.IsArray()) {
      return val.Size();
    } else {
      std::stringstream err;

      err << "Error, key \"" << name << "\" type is " 
          << JSON_TYPE_NAMES[val.GetType()]
          << " but Array<Object> was expected";
      throw std::runtime_error(err.str());
    }
  } else {
    std::stringstream err;
    err << "error, key \"" << name << "\" does not exist in parsed json\n";
    throw std::runtime_error(err.str());
  }
}

void JsonArchive::assign_arr_val(std::string name, size_t indx, Archivable* obj) {
  rj::Value& val = (*json_root)[name.c_str()]; 
  rj::Value& elem = val[indx];

  if (elem.IsObject()) {
    JsonArchive iar(&elem);
    obj->load_metadata(iar);
  } else {
    std::stringstream err;

    err << "Error, key \"" << name << "\" type is " 
        << JSON_TYPE_NAMES[val.GetType()]
        << " but Array<Object> was expected";
    throw std::runtime_error(err.str());
  }
}

void JsonArchive::serialise() {}
void JsonArchive::deserialise() {
  //if (json_doc.Parse(json_str.c_str()).HasParseError()) {
  //  std::runtime_error("Error parsing json, invalid json");
  //}

  //json_root = &json_doc;

  //std::stringstream err;

  //for (auto& [key, value] : this->map) {
  //  if (json_root->HasMember(key.c_str())) {
  //    rj::Value& json_val = (*json_root)[key.c_str()];

  //    switch (value.index()) {
  //      case JsonType::Int64: {
  //        if (json_val.IsInt64()) {
  //          int64_t* ptr = std::get<JsonType::Int64>(value);
  //          *ptr = json_val.GetInt64();
  //        } else {
  //          err << "Error, key \"" << key << "\" type is " << json_val.GetType()
  //              << " but " << JSON_TYPE_NAMES[value.index()] << " was expected";

  //          throw std::runtime_error(err.str());
  //        }
  //        break;
  //      }

  //      case JsonType::Float64: {
  //        if (json_val.IsDouble()) {
  //          double* ptr = std::get<JsonType::Float64>(value);
  //          *ptr = json_val.GetDouble();
  //        } else {
  //          err << "Error, key \"" << key << "\" type is " << json_val.GetType()
  //              << " but " << JSON_TYPE_NAMES[value.index()] << " was expected";

  //          throw std::runtime_error(err.str());
  //        }
  //        break;
  //      }

  //      case JsonType::String: {
  //        if (json_val.IsString()) {
  //          std::string* ptr = std::get<JsonType::String>(value);
  //          *ptr = json_val.GetString();
  //        } else {
  //          err << "Error, key \"" << key << "\" type is " << json_val.GetType()
  //              << " but " << JSON_TYPE_NAMES[value.index()] << " was expected";

  //          throw std::runtime_error(err.str());
  //        }
  //        break;
  //      }

  //      case JsonType::Bool: {
  //        if (json_val.IsBool()) {
  //          bool* ptr = std::get<JsonType::Bool>(value);
  //          *ptr = json_val.GetBool();
  //        } else {
  //          err << "Error, key \"" << key << "\" type is " << json_val.GetType()
  //              << " but " << JSON_TYPE_NAMES[value.index()] << " was expected";

  //          throw std::runtime_error(err.str());
  //        }
  //        break;
  //      }

  //      case JsonType::Object: {
  //        if (json_val.IsObject()) {
  //          JsonArchive iar(&json_val);

  //          Archivable* ptr = std::get<JsonType::Object>(value);
  //          ptr->load_metadata(iar);
  //          iar.deserialise();

  //        } else {
  //          err << "Error, key \"" << key << "\" type is " << json_val.GetType()
  //              << " but " << JSON_TYPE_NAMES[value.index()] << " was expected";

  //          throw std::runtime_error(err.str());
  //        }
  //        break;
  //      }

  //      case JsonType::ArrayInt64: {
  //        if (json_val.IsArray()) {
  //          std::vector<int64_t>* int_vec_ptr =
  //              std::get<JsonType::ArrayInt64>(value);

  //          for (auto& elem : json_val.GetArray()) {
  //            if (elem.IsInt64()) {
  //              int_vec_ptr->push_back(elem.GetInt64());
  //            } else {
  //              err << "Error, key \"" << key << "\" type is "
  //                  << json_val.GetType() << " but "
  //                  << JSON_TYPE_NAMES[value.index()] << " was expected";
  //            }
  //          }
  //        } else {
  //          err << "Error, key \"" << key << "\" type is " << json_val.GetType()
  //              << " but " << JSON_TYPE_NAMES[value.index()] << " was expected";

  //          throw std::runtime_error(err.str());
  //        }
  //        break;
  //      }

  //      case JsonType::ArrayFloat64: {
  //        if (json_val.IsArray()) {
  //          std::vector<double>* int_vec_ptr =
  //              std::get<JsonType::ArrayFloat64>(value);

  //          for (auto& elem : json_val.GetArray()) {
  //            if (elem.IsDouble()) {
  //              int_vec_ptr->push_back(elem.GetDouble());
  //            } else {
  //              err << "Error, key \"" << key << "\" type is "
  //                  << json_val.GetType() << " but "
  //                  << JSON_TYPE_NAMES[value.index()] << " was expected";
  //            }
  //          }
  //        } else {
  //          err << "Error, key \"" << key << "\" type is " << json_val.GetType()
  //              << " but " << JSON_TYPE_NAMES[value.index()] << " was expected";

  //          throw std::runtime_error(err.str());
  //        }
  //        break;
  //      }

  //      case JsonType::ArrayBool: {
  //        if (json_val.IsArray()) {
  //          std::vector<bool>* int_vec_ptr =
  //              std::get<JsonType::ArrayBool>(value);

  //          for (auto& elem : json_val.GetArray()) {
  //            if (elem.IsBool()) {
  //              int_vec_ptr->push_back(elem.GetBool());
  //            } else {
  //              err << "Error, key \"" << key << "\" type is "
  //                  << json_val.GetType() << " but "
  //                  << JSON_TYPE_NAMES[value.index()] << " was expected";
  //            }
  //          }
  //        } else {
  //          err << "Error, key \"" << key << "\" type is " << json_val.GetType()
  //              << " but " << JSON_TYPE_NAMES[value.index()] << " was expected";

  //          throw std::runtime_error(err.str());
  //        }
  //        break;
  //      }

  //      case JsonType::ArrayString: {
  //        if (json_val.IsArray()) {
  //          std::vector<std::string>* int_vec_ptr =
  //              std::get<JsonType::ArrayString>(value);

  //          for (auto& elem : json_val.GetArray()) {
  //            if (elem.IsString()) {
  //              int_vec_ptr->push_back(elem.GetString());
  //            } else {
  //              err << "Error, key \"" << key << "\" type is "
  //                  << json_val.GetType() << " but "
  //                  << JSON_TYPE_NAMES[value.index()] << " was expected";
  //            }
  //          }
  //        } else {
  //          err << "Error, key \"" << key << "\" type is " << json_val.GetType()
  //              << " but " << JSON_TYPE_NAMES[value.index()] << " was expected";

  //          throw std::runtime_error(err.str());
  //        }
  //        break;
  //      }

  //      case JsonType::ArrayObject: {
  //        if (json_val.IsArray()) {
  //          std::vector<Archivable>* obj_vec_ptr =
  //              std::get<JsonType::ArrayObject>(value);

  //          for (auto& elem : json_val.GetArray()) {
  //            if (elem.IsObject()) {
  //              json_val.GetArray().Size();

  //              JsonArchive iar(&elem);

  //              // next challenge...
  //            } else {
  //              err << "Error, key \"" << key << "\" type is "
  //                  << json_val.GetType() << " but "
  //                  << JSON_TYPE_NAMES[value.index()] << " was expected";
  //            }
  //          }
  //        } else {
  //          err << "Error, key \"" << key << "\" type is " << json_val.GetType()
  //              << " but " << JSON_TYPE_NAMES[value.index()] << " was expected";

  //          throw std::runtime_error(err.str());
  //        }
  //        break;
  //      }
  //    }
  //  } else {
  //    err << "error, key " << key << " does not exist in parsed json\n";
  //    throw std::runtime_error(err.str());
  //  }
  //}
}

}  // namespace fast
