cmake_minimum_required(VERSION 3.25)
project(lab_02)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra")

add_executable(task02 src/main.cpp src/five_array.cpp)
#add_executable(tests src/tests.cpp src/remove_vowels.cpp)

#set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
#set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
#
#include_directories(${INCLUDE_DIR})

add_custom_target(clean_all
        COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/*
        COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/*
)

#find_package(GTest REQUIRED)
#include_directories(${GTEST_INCLUDE_DIRS})
#
#enable_testing()
#target_link_libraries(tests ${GTEST_LIBRARIES})