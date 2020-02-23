# set minimum cmake version
cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

include(before_project_setup OPTIONAL)
# project name and language
project(recipe-06 LANGUAGES CXX)
include(build_options OPTIONAL)

find_package(MPI REQUIRED)

add_executable(hello-mpi hello-mpi.cpp)

target_link_libraries(hello-mpi
  PUBLIC
    MPI::MPI_CXX
  )
