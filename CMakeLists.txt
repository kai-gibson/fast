cmake_minimum_required(VERSION 3.5)

project(fast VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -Wall -Werror -ggdb -O0")
if(CMAKE_BUILD_TYPE MATCHES DEBUG)
endif()

find_package(SQLite3 REQUIRED)


add_executable(fast 
  src/main.cxx
  src/archives/json.cxx
  src/db/create_db.cxx
  src/db/sqlite3.cxx
  src/archives/sql.cxx
  src/json.cxx
  include/fast/archive.h
  include/fast/model.h
  include/fast/archives/json.h
)

target_link_libraries(fast PRIVATE SQLite::SQLite3)

target_include_directories(fast PRIVATE 
    include 
    external/rapidjson/include
)
