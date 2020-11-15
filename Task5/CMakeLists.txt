cmake_minimum_required(VERSION 3.17)
project(01Backpack)

set(CMAKE_CXX_STANDARD 17)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

file(GLOB SOURCES "Resources/*.cpp" "Headers/*.h")

add_executable(TSK5 ${SOURCES})