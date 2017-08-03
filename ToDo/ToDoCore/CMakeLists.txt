add_library(
        ${MY_PROJECT}Core
        ToDo.cc
)

target_include_directories(
        ${MY_PROJECT}Core
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

