#include "fast/archives/json.h"
#include "fast/archives/sql.h"
#include <iostream>
#include <memory>
#include <vector>

struct Data : fast::Archivable {
  int64_t id;
  std::string name;
  std::string address;

  void load_metadata(fast::Archive& arc) {
    arc.add("id", &id);
    arc.add("name", &name);
    arc.add("address", &address);
  }

  friend std::ostream& operator<<(std::ostream& os, Data& d) {
    return os << "{" << d.id << ", " << d.name << ", " << d.address << "}";
  }
};

struct Nest : fast::Archivable {
  int64_t id;
  int64_t points;

  void load_metadata(fast::Archive& arc) {
    arc.add("id", &id);
    arc.add("points", &points);
  }
};

struct Test : fast::Archivable {
  std::vector<int64_t> arr;

  void load_metadata(fast::Archive& arc) {
    arc.add("arr", &arr);
  }
};

int main() {
  std::vector<Nest> vec;
  std::vector<std::unique_ptr<fast::Archivable>> vec_two;
  vec_two.push_back({});

  //Data d;

  //fast::SqlArchive arc;
  //arc.load_data({
  //    {"id", "1234"},
  //    {"name", "kai gibson"},
  //    {"address", "224 Cardigan St"},
  //});

  //d.load_metadata(arc);

  //arc.deserialise();

  //std::cout << d << "\n";
}
