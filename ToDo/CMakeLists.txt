set(MY_PROJECT ToDo)

project(${MY_PROJECT})

#dirs should be before add_executable
add_subdirectory(${MY_PROJECT}Core)
add_subdirectory(${MY_PROJECT}Test)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/${MY_PROJECT})

add_executable(${MY_PROJECT}
        main.cc)

target_link_libraries(${MY_PROJECT}
        ${MY_PROJECT}Core
        )

add_dependencies(${PROJECT_NAME} ${MY_PROJECT}Test)


#cmake tests
add_test(
        NAME ${PROJECT_NAME}
        COMMAND ${PROJECT_NAME}
)

add_custom_command(
        TARGET ${MY_PROJECT}
        COMMENT "Show CMake ctests"
        POST_BUILD
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_CTEST_COMMAND} -N
)

add_custom_command(
        TARGET ${MY_PROJECT}
        COMMENT "Run CMake ctests"
        POST_BUILD
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_CTEST_COMMAND} -j4 --verbose
)


