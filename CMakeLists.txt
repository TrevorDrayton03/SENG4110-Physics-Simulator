# CMakeLists.txt is a configuration file for building executables and testing in Docker.
# 
# 
# Author: Trevor Drayton

cmake_minimum_required(VERSION 2.6)
project(Project)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
enable_testing()
find_package(GTest REQUIRED)
find_package(Threads)
include(GoogleTest)
include_directories(${GTEST_INCLUDE_DIRS})
add_library(project_lib simulation.cc simulation.h ball.cc ball.h cannonball.cc cannonball.h cannon.h cannon.cc)
add_executable(project main.cc)
install ( TARGETS project DESTINATION ${CMAKE_INSTALL_BINDIR})
target_link_libraries(project project_lib)

add_executable(runtest projecttest.cc)
install ( TARGETS runtest DESTINATION ${CMAKE_INSTALL_BINDIR})
target_link_libraries(runtest project_lib)
target_link_libraries(runtest ${GTEST_LIBRARIES})