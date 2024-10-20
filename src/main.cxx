#include "fast/db/create_db.h"
#include "fast/macros.h"
#include "fast/archives/json.h"
#include "fast/json.h"

#include "sqlite3.h"
#include <iostream>
#include <vector>
#include <format>

struct Data : fast::Model {
  int64_t id;
  std::string name;
  std::string address;

  FAST_LOAD_METADATA(id, name, address);

  friend std::ostream& operator<<(std::ostream& os, Data& d) {
    return os << "{" << d.id << ", " << d.name << ", " << d.address << "}";
  }
};

struct Nest : fast::Model {
  int64_t id;
  int64_t points;

  FAST_LOAD_METADATA(id, points);
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


  FAST_LOAD_METADATA(id, name, purchases, extra_data);

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

  std::cout << "user def\n";

  struct User : public fast::Model {
    int64_t id;
    std::string name;
    std::string address;
    double balance;

    FAST_LOAD_METADATA(id, name, address, balance);
  };

  using fast::DBProvider;
  auto [db, err] = fast::create_db(DBProvider::SQLite, "example.db");

  if (err) {
    std::cerr << "err: " << err.detail << "\n";
    return EXIT_FAILURE;
  }

  std::vector<User> users;
  err = db->select("SELECT * FROM tbl_users", &users);

  if (!err) {
    for (User& user : users) {
      std::cout << "user data as json: " << fast::to_json(user) << "\n";
    }
  } else {
    std::cerr << "error " << err.result_code << " " << err.detail << "\n";
  }

  //err = db->query(std::format(R"(
  //  INSERT INTO tbl_users 
  //    (id, name, address) 
  //  VALUES ({}, {}, {}))",
  //      10, "\"uzbekh\"", "\"Dagestan\"").c_str());

  if (err) {
    std::cerr << "error inserting: " << err.detail << "\n";
  } 
}
