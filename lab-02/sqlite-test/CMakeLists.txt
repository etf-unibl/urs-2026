cmake_minimum_required(VERSION 3.0)
project(sqlite-test)

find_package(SQLite3 REQUIRED)

add_executable(sqliteTestCmake sqlite-test.c)

target_include_directories(sqliteTestCmake PRIVATE ${SQLITE3_INCLUDE_DIRS} ${SQLite3_INCLUDE_DIRS})
target_link_libraries(sqliteTestCmake PRIVATE ${SQLITE3_LIBRARIES} ${SQLite3_LIBRARIES})
