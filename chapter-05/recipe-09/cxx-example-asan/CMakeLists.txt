cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

include(before_project_setup OPTIONAL)
# project name and language
project(recipe-09 LANGUAGES CXX)
include(build_options OPTIONAL)

list(APPEND CXX_BASIC_FLAGS "-g3" "-O1")

include(CheckCXXCompilerFlag)

set(ASAN_FLAGS "-fsanitize=address -fno-omit-frame-pointer")
set(CMAKE_REQUIRED_FLAGS ${ASAN_FLAGS})
check_cxx_compiler_flag(${ASAN_FLAGS} asan_works)
unset(CMAKE_REQUIRED_FLAGS)
string(REPLACE " " ";" _asan_flags ${ASAN_FLAGS})

add_executable(asan-example asan-example.cpp)
target_compile_options(asan-example
  PUBLIC
    ${CXX_BASIC_FLAGS}
    $<$<BOOL:${asan_works}>:${_asan_flags}>
  )
target_link_libraries(asan-example
  PUBLIC
    $<$<BOOL:${asan_works}>:${ASAN_FLAGS}>
  )
