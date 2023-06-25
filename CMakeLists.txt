cmake_minimum_required(VERSION 3.5)
project(test-third-party CXX)

set(CMAKE_BUILD_TYPE "Debug")

set(DEFAULT_WANT_TESTS OFF)
option(WANT_TESTS "Enables tests" ${DEFAULT_WANT_TESTS})

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 11)

set(CXX_STANDARD
        c++11
        CACHE STRING "The language standard to target for C++.")

set(CMAKE_CXX_FLAGS
        "${CMAKE_CXX_FLAGS} --std=${CXX_STANDARD} -g -Wall -Wextra -fstack-protector-strong ${CXX_EXTRA_FLAGS}"
        )
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG")

add_compile_options(-Wall -fPIC)

set(TARGET "test-third-party")

file(GLOB_RECURSE SRC_LIST "src/*.cc")

add_executable(${TARGET} ${SRC_LIST})

target_include_directories(
        ${TARGET}
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/third_party)

target_link_directories(
        ${TARGET}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/third_party/3rdlib)

target_link_libraries(
        ${TARGET}
        PRIVATE muduo_base
        muduo_net
        gflags
        pthread)
