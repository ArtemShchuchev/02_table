cmake_minimum_required(VERSION 3.5)
project(02_table)
add_executable(myTable main.cpp Table.hpp)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT myTable)




### add_subdirectory(../Catch2 Catch2-build)
find_package(Catch2 3 REQUIRED)
## 		These tests need their own main
add_executable(test test.cpp Table.hpp)
target_link_libraries(test PRIVATE Catch2::Catch2)
