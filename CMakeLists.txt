cmake_minimum_required(VERSION 3.25)
project(oop_labs)

add_subdirectory(laba01)
add_subdirectory(laba02)

add_custom_target(clean_all
        COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/*
        COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/*
)