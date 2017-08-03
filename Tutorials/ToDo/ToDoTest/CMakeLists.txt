project(${MY_PROJECT}Test)


#dirs should be before add_executable

add_executable(${PROJECT_NAME} ${MY_PROJECT}UnitTest.cc)

target_include_directories(
        ${MY_PROJECT}Test
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/${MY_PROJECT}/${MY_PROJECT}Test)



target_link_libraries(
        ${PROJECT_NAME}
        ${MY_PROJECT}Core
        gmock_main
        )



add_test(
        NAME ${PROJECT_NAME}
        COMMAND ${PROJECT_NAME}
)

