cmake_minimum_required(VERSION 3.10)

project(L0Ad)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(vendor)

add_subdirectory(src/engine)
add_subdirectory(src/editor)
add_subdirectory(src/runtime)
