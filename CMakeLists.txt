cmake_minimum_required(VERSION 3.0)

project(Little_endian_and_Big_endian)

set(SOURCE_EXE src/main.cpp)
set(SOURCE_LIB src/LE_system.cpp)

add_library(LE_system STATIC ${SOURCE_LIB})
add_executable(main ${SOURCE_EXE})

target_link_libraries(main LE_system)
