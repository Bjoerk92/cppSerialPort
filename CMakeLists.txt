cmake_minimum_required(VERSION 3.20)

project(Serial VERSION 3.24)

set(CMAKE_CXX_STANDARD 17)

if(WIN32)
    set(SERIAL_SOURCE src/Serial_win.cpp)
else()
    set(SERIAL_SOURCE src/Serial_unix.cpp)
endif(WIN32)

add_library(${PROJECT_NAME}_lib ${SERIAL_SOURCE})

target_include_directories(${PROJECT_NAME}_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)