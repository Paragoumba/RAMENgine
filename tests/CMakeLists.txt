cmake_minimum_required(VERSION 3.16)

add_executable(Engine_Tests tests.cpp)
target_link_libraries(Engine_Tests gtest gtest_main)