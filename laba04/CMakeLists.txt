cmake_minimum_required(VERSION 3.25)
project(lab04)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra")

add_executable(task04
        src/main.cpp
        src/Figure.cpp
        src/Pentagon.cpp
        src/Hexagon.cpp
        src/Octagon.cpp
        src/FigureValidator.cpp
        src/HexagonValidator.cpp
        src/IFigureValidator.cpp
        src/OctagonValidator.cpp
        src/PentagonValidator.cpp
        src/Point.cpp
)

#enable_testing()
#add_executable(tests04
#        src/tests.cpp
#        src/Figure.cpp
#        src/Pentagon.cpp
#        src/Hexagon.cpp
#        src/Octagon.cpp
#        src/FigureValidator.cpp
#        src/HexagonValidator.cpp
#        src/IFigureValidator.cpp
#        src/OctagonValidator.cpp
#        src/PentagonValidator.cpp
#        src/Point.cpp
#)
#target_link_libraries(tests04 ${GTEST_LIBRARIES})
#
#add_test(NAME BASIC COMMAND tests04)