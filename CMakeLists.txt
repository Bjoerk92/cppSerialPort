cmake_minimum_required(VERSION 3.24)

project(Serial VERSION 3.24)

set(CMAKE_CXX_STANDARD 17)

add_library(${PROJECT_NAME}_lib 
    src/Serial_win.cpp
)

target_link_directories(${PROJECT_NAME}_lib 
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)