#include <rapidjson/error/en.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>

#include <iostream>
#include <sstream>

#include "fast/archives/json.h"

/*
 * JsonIArchive implementation
 * TODO:
 *  - make exception type
 *  - handle arrays with differently typed elements
 *  - optional fields
 *
 */

namespace fast {

JsonIArchive::JsonIArchive(rj::Value* json_root) {
  if (json_root) {
    this->json_root = json_root;
  } else {
    this->json_root = &json_doc;
  }
}

JsonIArchive::JsonIArchive(const char* json_str) {
  rj::ParseResult res = json_doc.Parse(json_str);

  if (!res) {
    std::stringstream err;
    err << "JSON Parse Error " << rj::GetParseError_En(res.Code()) << " "
        << res.Offset();

    std::cerr << err.str();
    throw std::runtime_error("parse error");
  }

  this->json_root = &json_doc;
}

void JsonIArchive::add(const char* name, int64_t* data) {
  if (json_root->HasMember(name)) {
    rj::Value& json_val = (*json_root)[name];

    if (json_val.IsInt64()) {
      *data = json_val.GetInt64();
    } else {
      std::stringstream err;

      err << "Error, key \"" << name << "\" type is "
          << JSON_TYPE_NAMES[json_val.GetType()] << " but Int64 was expected";

      throw std::runtime_error(err.str());
    }
  } else {
    std::stringstream err;
    err << "error, key \"" << name << "\" does not exist in parsed json\n";

    throw std::runtime_error(err.str());
  }
}

void JsonIArchive::add(const char* name, double* data) {
  if (json_root->HasMember(name)) {
    rj::Value& json_val = (*json_root)[name];

    if (json_val.IsDouble()) {
      *data = json_val.GetDouble();
    } else {
      std::stringstream err;

      err << "Error, key \"" << name << "\" type is "
          << JSON_TYPE_NAMES[json_val.GetType()] << " but Float64 was expected";

      throw std::runtime_error(err.str());
    }
  } else {
    std::stringstream err;
    err << "error, key \"" << name << "\" does not exist in parsed json\n";

    throw std::runtime_error(err.str());
  }
}

void JsonIArchive::add(const char* name, std::string* data) {
  if (json_root->HasMember(name)) {
    rj::Value& json_val = (*json_root)[name];

    if (json_val.IsString()) {
      *data = json_val.GetString();
    } else {
      std::stringstream err;

      err << "Error, key \"" << name << "\" type is "
          << JSON_TYPE_NAMES[json_val.GetType()] << " but String was expected";

      throw std::runtime_error(err.str());
    }
  } else {
    std::stringstream err;
    err << "error, key \"" << name << "\" does not exist in parsed json\n";

    throw std::runtime_error(err.str());
  }
}

void JsonIArchive::add(const char* name, bool* data) {
  if (json_root->HasMember(name)) {
    rj::Value& json_val = (*json_root)[name];

    if (json_val.IsBool()) {
      *data = json_val.GetBool();
    } else {
      std::stringstream err;

      err << "Error, key \"" << name << "\" type is "
          << JSON_TYPE_NAMES[json_val.GetType()] << " but Bool was expected";

      throw std::runtime_error(err.str());
    }
  } else {
    std::stringstream err;
    err << "error, key \"" << name << "\" does not exist in parsed json\n";

    throw std::runtime_error(err.str());
  }
}

void JsonIArchive::add(const char* name, Model* data) {
  if (json_root->HasMember(name)) {
    rj::Value& json_val = (*json_root)[name];

    if (json_val.IsObject()) {
      // recursive assign to object
      JsonIArchive iar(&json_val);
      data->load_metadata(iar);

    } else {
      std::stringstream err;

      err << "Error, key \"" << name << "\" type is "
          << JSON_TYPE_NAMES[json_val.GetType()] << " but Object was expected";

      throw std::runtime_error(err.str());
    }
  } else {
    std::stringstream err;
    err << "error, key \"" << name << "\" does not exist in parsed json\n";

    throw std::runtime_error(err.str());
  }
}

void JsonIArchive::add(const char* name, std::vector<int64_t>* data) {
  if (json_root->HasMember(name)) {
    rj::Value& json_val = (*json_root)[name];

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

void JsonIArchive::add(const char* name, std::vector<double>* data) {
  if (json_root->HasMember(name)) {
    rj::Value& json_val = (*json_root)[name];

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

void JsonIArchive::add(const char* name, std::vector<std::string>* data) {
  if (json_root->HasMember(name)) {
    rj::Value& json_val = (*json_root)[name];

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

void JsonIArchive::add(const char* name, std::vector<bool>* data) {
  if (json_root->HasMember(name)) {
    rj::Value& json_val = (*json_root)[name];

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

size_t JsonIArchive::get_obj_arr_count(const char* name) {
  if (json_root->HasMember(name)) {
    rj::Value& val = (*json_root)[name];

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

void JsonIArchive::assign_arr_val(const char* name, size_t indx, Model* obj) {
  rj::Value& val = (*json_root)[name];
  rj::Value& elem = val[indx];

  if (elem.IsObject()) {
    JsonIArchive iar(&elem);
    obj->load_metadata(iar);
  } else {
    std::stringstream err;

    err << "Error, key \"" << name << "\" type is "
        << JSON_TYPE_NAMES[val.GetType()] << " but Array<Object> was expected";
    throw std::runtime_error(err.str());
  }
}

std::string JsonIArchive::str() { return json_root->GetString(); }

// Json Output Archive

// constructors
JsonOArchive::JsonOArchive() {
  writer = std::make_shared<rj::Writer<rj::StringBuffer>>(s);
  writer->StartObject();
}
JsonOArchive::JsonOArchive(
    std::shared_ptr<rj::Writer<rj::StringBuffer>>& writer) {
  this->writer = writer;
}

// add methods
void JsonOArchive::add(const char* name, int64_t* data) {
  writer->Key(name);
  writer->Int64(*data);
}

void JsonOArchive::add(const char* name, double* data) {
  writer->Key(name);
  writer->Double(*data);
}

void JsonOArchive::add(const char* name, std::string* data) {
  writer->Key(name);
  writer->String(data->c_str());
}

void JsonOArchive::add(const char* name, bool* data) {
  writer->Key(name);
  writer->Bool(*data);
}

void JsonOArchive::add(const char* name, Model* data) {
  writer->Key(name);
  writer->StartObject();

  JsonOArchive oar(writer);
  data->load_metadata(oar);

  writer->EndObject();
}

void JsonOArchive::add(const char* name, std::vector<int64_t>* data) {
  writer->Key(name);
  writer->StartArray();
  for (auto& elem : *data) {
    writer->Int64(elem);
  }
  writer->EndArray();
}

void JsonOArchive::add(const char* name, std::vector<double>* data) {
  writer->Key(name);
  writer->StartArray();
  for (auto& elem : *data) {
    writer->Double(elem);
  }
  writer->EndArray();
}

void JsonOArchive::add(const char* name, std::vector<std::string>* data) {
  writer->Key(name);
  writer->StartArray();
  for (auto& elem : *data) {
    writer->String(elem.c_str());
  }
  writer->EndArray();
}

void JsonOArchive::add(const char* name, std::vector<bool>* data) {
  writer->Key(name);
  writer->StartArray();
  for (auto elem : *data) {
    writer->Bool(elem);
  }
  writer->EndArray();
}

size_t JsonOArchive::get_obj_arr_count(const char* name) { return 0; }

void JsonOArchive::assign_arr_val(const char* name, size_t indx, Model* obj) {
  if (indx == 0) {
    writer->Key(name);
    writer->StartArray();
  }

  writer->StartObject();

  JsonOArchive oar(writer);
  obj->load_metadata(oar);

  writer->EndObject();
  if (indx == static_cast<size_t>(-1)) writer->EndArray();
}

std::string JsonOArchive::str() {
  writer->EndObject();
  return s.GetString();
}

}  // namespace fast
