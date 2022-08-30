cmake_minimum_required(VERSION 3.0)

project(Little_endian_and_Big_endian)

set(SOURCE_EXE src/main.cpp)
set(SOURCE_LIB src/LE_system.cpp)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(LE_system STATIC ${SOURCE_LIB})
add_executable(main ${SOURCE_EXE})
add_subdirectory(tests)

target_link_libraries(main LE_system)
