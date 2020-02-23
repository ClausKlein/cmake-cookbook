# set minimum cmake version
cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

include(before_project_setup OPTIONAL)
# project name and language
project(recipe-05 LANGUAGES CXX)
include(build_options OPTIONAL)

find_package(OpenMP REQUIRED)

add_executable(example example.cpp)

target_compile_options(example
  PUBLIC
    ${OpenMP_CXX_FLAGS}
  )

set_target_properties(example
  PROPERTIES
    LINK_FLAGS ${OpenMP_CXX_FLAGS}
  )
