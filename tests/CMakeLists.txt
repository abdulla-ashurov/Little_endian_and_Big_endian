cmake_minimum_required(VERSION 3.0)

project(Little_endian_and_Big_endian_Tests)

set(SOURCE_EXE test.cpp)
set(SOURCE_LIB catch_amalgamated.cpp ../src/LE_system.cpp)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(UNIT_TESTS_LIB STATIC ${SOURCE_LIB})
add_executable(UNIT_TESTS ${SOURCE_EXE})

target_link_libraries(UNIT_TESTS UNIT_TESTS_LIB)
