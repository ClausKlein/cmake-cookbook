cmake_minimum_required(VERSION 3.9 FATAL_ERROR)

project(recipe-06 LANGUAGES CXX)

find_package(OpenMP)

if(OpenMP_FOUND)
  # this will get wiped unless you run cmake with --debug-trycompile
  set(_scratch_directory ${CMAKE_CURRENT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/omp_try_compile)

  try_compile(
    omp_taskloop_test_1
    ${_scratch_directory}
    SOURCES
      ${PROJECT_SOURCE_DIR}/taskloop.cpp
    LINK_LIBRARIES
      OpenMP::OpenMP_CXX
    )
  message(STATUS "Result of try_compile: ${omp_taskloop_test_1}")

  include(CheckCXXSourceCompiles)
  file(READ ${PROJECT_SOURCE_DIR}/taskloop.cpp _snippet)
  set(CMAKE_REQUIRED_LIBRARIES OpenMP::OpenMP_CXX)
  check_cxx_source_compiles("${_snippet}" omp_taskloop_test_2)
  unset(CMAKE_REQUIRED_LIBRARIES)
  message(STATUS "Result of check_cxx_source_compiles: ${omp_taskloop_test_2}")
else()
  message(STATUS "OpenMP not found: no test for taskloop is run")
endif()