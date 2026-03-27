set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_SYSROOT /home/student/x-tools/arm-etfbl-linux-gnueabihf/arm-etfbl-linux-gnueabihf/sysroot)
set(CMAKE_STAGING_PREFIX ./build)

set(tools /home/student/x-tools/arm-etfbl-linux-gnueabihf)
set(CMAKE_C_COMPILER ${tools}/bin/arm-linux-gcc)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

cmake_minimum_required(VERSION 3.0)
project(sqlite-test)
add_executable(sqlite-test sqlite-test.c)
find_package(SQLite3)
target_include_directories(sqlite-test PRIVATE "${SQLite3_INCLUDE_DIRS}")
target_link_libraries(sqlite-test PRIVATE ${SQLite3_LIBRARIES})
