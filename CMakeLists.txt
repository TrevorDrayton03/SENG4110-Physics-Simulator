# CMakeLists.txt is a configuration file for building executables and testing in Docker.
# This file is used for creating the lab7 and runtest executables which run the integrationNextDate solution and test it using a call-graph pairwise integration test suite.
# Also to use graphviz to generate a dependency graph and lcov to check for line coverage.
# Author: Trevor Drayton

cmake_minimum_required(VERSION 2.6)
project(lab7)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(DependencyGraph)
include(CodeCoverage)
append_coverage_compiler_flags()
enable_testing()
find_package(GTest REQUIRED)
find_package(Threads)
include(GoogleTest)
include_directories(${GTEST_INCLUDE_DIRS})
add_library(lab7_lib integrationnextdate.cc)
add_executable(lab7 main.cc)
install ( TARGETS lab7 DESTINATION ${CMAKE_INSTALL_BINDIR})
target_link_libraries(lab7 lab7_lib)
add_executable(runtest integrationnextdatetest.cc)
install ( TARGETS runtest DESTINATION ${CMAKE_INSTALL_BINDIR})
target_link_libraries(runtest lab7_lib)
target_link_libraries(runtest ${GTEST_LIBRARIES})

setup_target_for_coverage_lcov(
     NAME IntegrationNextDate_coverage           
     EXECUTABLE runtest 							
     DEPENDENCIES runtest                   		  
     BASE_DIRECTORY "../"                          
     EXCLUDE "/usr/include/c++/9/*" "/usr/include/gtest/*"
     NO_DEMANGLE                                 
)