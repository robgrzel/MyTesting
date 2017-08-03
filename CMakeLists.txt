cmake_minimum_required(VERSION 3.4)

project(MyTesting)

find_package(Threads REQUIRED)

enable_testing()

include(CTest)

add_subdirectory(GTest)

add_subdirectory(ToDo)

add_dependencies(ToDo gtest)
