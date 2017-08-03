project(${MP}Test)


#dirs should be before add_executable

add_executable(${PROJECT_NAME} ${MP}UnitTest.cc)

target_include_directories(
        ${MP}Test
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/${MP}/${MP}Test)


target_link_libraries(
        ${PROJECT_NAME}
        ${MP}Core
        gmock_main
        )


add_test(
        NAME ${PROJECT_NAME}
        COMMAND ${PROJECT_NAME}
)

