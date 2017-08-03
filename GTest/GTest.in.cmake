


cmake_minimum_required(VERSION 2.8.2)

project(googletest-download NONE)

include(ExternalProject)

ExternalProject_Add(googletest
        GIT_REPOSITORY    https://github.com/google/googletest.git
        GIT_TAG           master
        SOURCE_DIR        "${path}/googletest-src"
        BINARY_DIR        "${path}/googletest-build"
        CONFIGURE_COMMAND ""
        BUILD_COMMAND     ""
        INSTALL_COMMAND   ""
        TEST_COMMAND      ""
        )


# Get GTest source and binary directories from CMake project
ExternalProject_Get_Property(googletest source_dir binary_dir)
