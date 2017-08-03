cmake_minimum_required(VERSION 3.8)
project(Tasks)

set(CMAKE_CXX_STANDARD 11)

set(Tests 1)


if (Tests MATCHES 1)
    add_definitions(-DRunTests=4)
    set(SOURCE_FILES
            main.cpp
            problem_A.cpp problem_A.h
            problem_B.cpp problem_B.h
            problem_C.cpp problem_C.h
            #std_vector_2d.cpp std_vector_2d.h
            #templates.cpp templates.h
            )

elseif (Tests MATCHES 2)
    set(SOURCE_FILES
            problem_A.cpp problem_A.h
            )
elseif (Tests MATCHES 3)
    set(SOURCE_FILES
            problem_B.cpp problem_B.h

            )
elseif (Tests MATCHES 4)
    set(SOURCE_FILES
            problem_C.cpp
            )

endif ()

add_executable(Tasks ${SOURCE_FILES})