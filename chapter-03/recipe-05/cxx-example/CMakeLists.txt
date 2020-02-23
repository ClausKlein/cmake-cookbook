# set minimum cmake version
cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

include(before_project_setup OPTIONAL)
# project name and language
project(recipe-05 LANGUAGES CXX)
include(before_project_setup OPTIONAL)

find_package(OpenMP REQUIRED)

add_executable(example example.cpp)

target_link_libraries(example
  PUBLIC
    OpenMP::OpenMP_CXX
  )
