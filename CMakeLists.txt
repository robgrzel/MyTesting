cmake_minimum_required(VERSION 3.4)

project(MyTesting)

find_package(Threads REQUIRED)

enable_testing()

include(CTest)

add_subdirectory(GTest)

set(run-tutorials 0)
set(run-tasks 1)

if (run-tutorials)
    message(TUTORIALS)
    add_subdirectory(Tutorials)
elseif (run-tasks)
    message(TASKS)
    add_subdirectory(Tasks)
endif (run-tutorials)
