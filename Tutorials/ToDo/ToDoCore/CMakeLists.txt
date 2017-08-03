
project(${MY_PROJECT}Core)

add_library(
        ${MY_PROJECT}Core
        ToDoCore.cc
)

target_include_directories(
        ${MY_PROJECT}Core
        PUBLIC
        .
)

