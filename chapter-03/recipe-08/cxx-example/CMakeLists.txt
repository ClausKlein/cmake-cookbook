# set minimum cmake version
cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

include(before_project_setup OPTIONAL)
# project name and language
project(recipe-08 LANGUAGES CXX)
include(build_options OPTIONAL)

find_package(boost_filesystem 1.72 REQUIRED CONFIG)
find_package(boost_thread 1.72 REQUIRED CONFIG)
find_package(boost_chrono 1.72 REQUIRED CONFIG)

add_executable(path-info path-info.cpp)
target_link_libraries(path-info
  PUBLIC
    Boost::filesystem
  )

add_executable(thread thread.cpp)
target_link_libraries(thread
  PUBLIC
    Boost::thread
    Boost::chrono
  )
