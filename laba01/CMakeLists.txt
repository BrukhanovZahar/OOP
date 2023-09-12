cmake_minimum_required(VERSION 3.25)
project(first_laba)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra")

add_executable(task01 src/main.cpp src/remove_vowels.cpp)
add_executable(tests src/tests.cpp src/remove_vowels.cpp)

add_custom_target(clean_all
        COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/*
        COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/*
)

add_custom_target(info
        COMMAND ${CMAKE_COMMAND} -DMORE_INFORMATION=ON .
        COMMAND make
        COMMAND ${CMAKE_COMMAND} -DMORE_INFORMATION=OFF .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Building with MORE_INFORMATION flag"
)

if(MORE_INFORMATION)
    target_compile_definitions(task01 PRIVATE MORE_INFORMATION)
endif()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()
target_link_libraries(tests ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests01)