#include "fast/archives/json.h"
#include <iostream>
#include <vector>

struct Data : fast::Model {
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

struct Nest : fast::Model {
  int64_t id;
  int64_t points;

  void load_metadata(fast::Archive& arc) {
    arc.add("id", &id);
    arc.add("points", &points);
  }
};

struct Test : fast::Model {
  std::vector<Nest> arr;

  void load_metadata(fast::Archive& arc) {
    arc.add("arr", &arr);
  }
};

struct Big : public fast::Model {
  int64_t id;
  std::string name;
  std::vector<Nest> purchases;
  Data extra_data;

  void load_metadata(fast::Archive& arc) {
		std::cout << "add id\n";
    arc.add("id", &id);
		std::cout << "add name\n";
    arc.add("name", &name);
		std::cout << "add purchases\n";
    arc.add("purchases", &purchases);
		std::cout << "add extra_data\n";
    arc.add("extra_data", &extra_data);
  }

  friend std::ostream& operator<<(std::ostream& os, Big& b) {
    os << "id: " << b.id << " name: " << b.name << " purchases: [";
    for (auto& elem : b.purchases) {
      os << "id: " << elem.id << " points: " << elem.points << " ";
    }

    return os << b.extra_data;
  }
};

int main() {

  Test test;

  fast::JsonIArchive iar(R"(
    {
      "arr": [
        {
          "id": 120,
          "points": 1200
        },
        {
          "id": 1241,
          "points": 834
        },
        {
          "id": 99,
          "points": 9900
        }
      ]
    }
  )");

  test.load_metadata(iar);

  for (auto& elem : test.arr) {
    std::cout << "id: " << elem.id << " points: " << elem.points << "\n";
  }

  fast::JsonIArchive new_iar(R"(
    {
      "id": 12,
      "name": "Kai Gibson",
      "purchases": [
        {
          "id": 120,
          "points": 1200
        },
        {
          "id": 1241,
          "points": 834
        },
        {
          "id": 99,
          "points": 9900
        }
      ],
      "extra_data": {
        "id": 19,
        "name": "Kyle Gisbourne",
        "address": "alternative_address"
      }
    }
  )");

  Big big;
  
  try {
    big.load_metadata(new_iar);
    std::cout << big << "\n";
  } catch (std::exception& e) {
    std::cout << e.what() << "\n";
  }

  std::cout << "init archive\n";
  fast::JsonOArchive oar;
  std::cout << "load_metadata\n";
  big.load_metadata(oar);
  std::cout << "output json\n";
  std::cout << "back to json: " << oar.str() << "\n";

}
