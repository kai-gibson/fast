cmake_minimum_required(VERSION 3.5)

project(fast VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(CMAKE_BUILD_TYPE MATCHES DEBUG)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,leak -Wall -Werror"})
endif()

add_executable(fast 
  src/main.cxx
  src/archives/json.cxx
  include/fast/archive.h
  include/fast/model.h
  include/fast/archives/json.h
)


target_include_directories(fast PRIVATE 
    include 
    external/rapidjson/include
)
