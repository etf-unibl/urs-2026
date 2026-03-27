cmake_minimum_required(VERSION 3.0)
project(app)
add_executable(appCmakeDynamic app.c)
add_subdirectory(test)
target_link_libraries(appCmakeDynamic PUBLIC test)
target_include_directories(appCmakeDynamic PUBLIC
    "${PROJECT_SOURCE_DIR}/test")
