cmake_minimum_required(VERSION 3.25)
project(lab03)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra")

add_executable(task03
        src/main.cpp
        src/figure.cpp
        src/pentagon.cpp
        src/hexagon.cpp
        src/octagon.cpp
        src/FigureValidator.cpp
        src/HexagonValidator.cpp
        src/IFigureValidator.cpp
        src/OctagonValidator.cpp
        src/PentagonValidator.cpp
        src/point.cpp
)

enable_testing()
add_executable(tests03
        src/tests.cpp
        src/figure.cpp
        src/pentagon.cpp
        src/hexagon.cpp
        src/octagon.cpp
        src/FigureValidator.cpp
        src/HexagonValidator.cpp
        src/IFigureValidator.cpp
        src/OctagonValidator.cpp
        src/PentagonValidator.cpp
        src/point.cpp
)
target_link_libraries(tests03 ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests03)