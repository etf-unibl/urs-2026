cmake_minimum_required(VERSION 3.0)
project(sqlite-test)

find_package(SQLite3 REQUIRED)

add_executable(sqlite-test sqlite-test.c)

target_include_directories(sqlite-test PRIVATE ${SQLite3_INCLUDE_DIRS})
target_link_libraries(sqlite-test PRIVATE ${SQLite3_LIBRARIES})