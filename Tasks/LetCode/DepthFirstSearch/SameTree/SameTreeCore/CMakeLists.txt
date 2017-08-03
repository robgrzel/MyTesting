
project(${MP}Core)

add_library(
        ${MP}Core
        ToDoCore.cc
)

target_include_directories(
        ${MP}Core
        PUBLIC
        .
)

