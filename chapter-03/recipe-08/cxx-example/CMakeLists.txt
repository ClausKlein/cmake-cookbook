# set minimum cmake version
cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

include(before_project_setup OPTIONAL)
# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
include(build_options OPTIONAL)

# project name and language
project(recipe-08 LANGUAGES CXX)

find_package(boost_filesystem 1.72 REQUIRED CONFIG)

add_executable(path-info path-info.cpp)

target_link_libraries(path-info
  PUBLIC
    Boost::filesystem
  )
