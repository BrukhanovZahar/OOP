cmake_minimum_required(VERSION 3.25)
project(lab06)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra")

add_executable(task05
        src/main.cpp
)
#
#enable_testing()
#add_executable(tests05
#        src/tests.cpp
#)
#target_link_libraries(tests05 ${GTEST_LIBRARIES})
#
#add_test(NAME BASIC COMMAND tests05)