cmake_minimum_required(VERSION 3.5)

project(fast VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(fast 
  src/main.cxx
  src/archives/json.cxx
  include/fast/archive.h
  include/fast/archivable.h
  include/fast/archives/json.h
)

target_include_directories(fast PRIVATE 
    include 
    external/rapidjson/include
)
