set(MP SameTree)

project(${MP})

#dirs should be before add_executable
add_subdirectory(${MP}Core)
add_subdirectory(${MP}Test)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/${MP})

set(SOURCES
        DepthFirstSearch/SameTree/SameTreeCore/SameTreeCore.cpp
        DepthFirstSearch/SameTree/SameTreeCore/SameTreeCore.h
        )

add_executable(${MP} ${SOURCES})
target_link_libraries(${MP} ${MP}Core)

add_dependencies(${PROJECT_NAME} ${MP}Test)


#cmake tests
add_test(
        NAME ${PROJECT_NAME}
        COMMAND ${PROJECT_NAME}
)

add_custom_command(
        TARGET ${MP}
        COMMENT "Show CMake ctests"
        POST_BUILD
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_CTEST_COMMAND} -N
)

add_custom_command(
        TARGET ${MP}
        COMMENT "Run CMake ctests"
        POST_BUILD
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_CTEST_COMMAND} -j4 --verbose
)


