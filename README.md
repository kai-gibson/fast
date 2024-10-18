# Fast: A Modern Web Library In C++

## Project goals:
* A modern c++ web framework that includes:
    * simple, flask like server api
    * json parsing
    * web requests
    * sql wrapper (not an ORM, but a generic cpp interface for any DB provider)
* Fast at runtime and fast to compile -- i.e. no abuse of templates, a
  statically linked library instead of header-only

## TODO:
 [x] Json In/Out
 [] SQL In
 [] xml In/Out 
 [] toml In/Out 
 [] web server


## Components:
This project leans on several existing, thoroughly tested and fast c++ libraries
that usually have poor interfaces. These include:
    * Boost beast for web client/server
    * rapidjson for json in/out
    * Sqlite3, MySQL, PostgreSQL, Firebird SQL libraries


## Usage:
Basic web server:
```

#include <fast/server.h>
#include <fast/sql/sqlite.h>

// we need a cpp struct-like construct with reflection like a hashmap

int main() {
    fast::sql::Session session(fast::SqlProvider::SQLite3, "example.db");

    fast::App app("0.0.0.0", 8026);

    app.get("/get_user", [](fast::Request request) -> fast::Response response {
        fast::Json user = request.body.json();

        fast::SQLRows user_rows;

        // specify whether query should throw an exception or return an empty
        // vec with .or_empty() and .or_except()
        user_rows = session.query(R"(
            SELECT 
                name, 
                id, 
                address 
            FROM tbl_users 
            WHERE password = {}
            AND id = {}
            )", user["password"].get_str(), user["id"].get_int()).or_empty(); 

        if (!user_rows.empty()) {

        }

        fast::Response response;
    });
}

```
