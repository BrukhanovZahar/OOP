cmake_minimum_required(VERSION 3.25)
project(lab01)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra")

add_executable(task01 src/main.cpp src/remove_vowels.cpp)
add_executable(tests01 src/tests.cpp src/remove_vowels.cpp)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()
target_link_libraries(tests01 ${GTEST_LIBRARIES})