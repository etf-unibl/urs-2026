cmake_minimum_required(VERSION 3.0)
project(app)
add_executable(appCmakeStatic app.c)
add_subdirectory(test)
target_link_libraries(appCmakeStatic PUBLIC test)
target_link_options(appCmakeStatic PRIVATE -static)
target_include_directories(appCmakeStatic PUBLIC
    "${PROJECT_SOURCE_DIR}/test")
