# Set the minimum version of CMake that can be used
cmake_minimum_required(VERSION 3.0)

project(HASHPROJECT)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall")

set(CMAKE_BUILD_TYPE Debug)

include_directories(${CMAKE_SOURCE_DIR}/include)

# aux_source_directory(${CMAKE_SOURCE_DIR}/src SRC_LIST)
set(SRC_LIST src/hash.c src/hashsep.c src/prime.c)

add_executable(main ${SRC_LIST} hashingTest.c)