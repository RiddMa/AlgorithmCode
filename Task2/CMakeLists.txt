cmake_minimum_required(VERSION 3.17)
project(FinalTest)

set(CMAKE_CXX_STANDARD 17)

#aux_source_directory(. DIRSRCS)

#INCLUDE_DIRECTORIES(./ ./Task2)

#add_subdirectory(Task2)

file(GLOB SOURCES "*.cpp")

add_executable(TSK2 ${SOURCES})