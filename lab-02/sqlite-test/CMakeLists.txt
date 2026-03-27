cmake_minimum_required(VERSION 3.10)

project(sqlite_test)

find_package(SQLite3 REQUIRED)

add_executable(sqlite-test sqlite-test.c)

target_include_directories(sqlite-test PRIVATE SQLite::SQLite3)
target_link_libraries(sqlite-test PRIVATE SQLite::SQLite3)