cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

include(before_project_setup OPTIONAL)
# Fortran needed to discover LAPACK with some compilers
project(recipe-04 LANGUAGES CXX Fortran)
include(build_options OPTIONAL)

add_subdirectory(deps)

add_executable(linear-algebra linear-algebra.cpp)

target_link_libraries(linear-algebra
  PRIVATE
    math
  )
