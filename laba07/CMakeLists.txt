cmake_minimum_required(VERSION 3.25)
project(lab07)

set(JSONCPP_INCLUDE_DIRS "/opt/homebrew/Cellar/jsoncpp/1.9.5/include")
set(JSONCPP_LIB_DIRS "/opt/homebrew/Cellar/jsoncpp/1.9.5/lib")

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra")

add_executable(task07
        src/main.cpp
        src/characters/Bear.cpp
        src/characters/Elf.cpp
        src/characters/Rogue.cpp
)

target_link_libraries(task07 sfml-graphics sfml-window sfml-system)
target_include_directories(task07 PRIVATE ${JSONCPP_INCLUDE_DIRS})
target_link_directories(task07 PRIVATE ${JSONCPP_LIB_DIRS})
target_link_libraries(task07 jsoncpp)

enable_testing()
add_executable(tests07
        src/tests.cpp
        src/characters/Bear.cpp
        src/characters/Elf.cpp
        src/characters/Rogue.cpp
)
target_link_libraries(tests07 ${GTEST_LIBRARIES})
target_link_libraries(tests07 sfml-graphics sfml-window sfml-system)
target_include_directories(tests07 PRIVATE ${JSONCPP_INCLUDE_DIRS})
target_link_directories(tests07 PRIVATE ${JSONCPP_LIB_DIRS})
target_link_libraries(tests07 jsoncpp)

add_test(NAME BASIC COMMAND tests07)