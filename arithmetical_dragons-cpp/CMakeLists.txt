cmake_minimum_required(VERSION 3.12)
project(dragons)

set(CMAKE_C_STANDARD 11)

include_directories(include)

set(SOURCE_EXE src/arithmetical_dragons.cpp)

add_executable(dragons ${SOURCE_EXE})

