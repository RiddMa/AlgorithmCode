cmake_minimum_required(VERSION 3.17)
project(FinalTest)

set(CMAKE_CXX_STANDARD 17)

#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
include_directories(./Header)

file(GLOB SOURCES "*.cpp")

add_executable(TSK2 ${SOURCES})