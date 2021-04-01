cmake_minimum_required(VERSION 3.17)
project(FinalTest)

set(CMAKE_CXX_STANDARD 17)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

file(GLOB SOURCES "Resources/*.cpp" "Headers/*.h")

<<<<<<< HEAD:3RoundRobin/CMakeLists.txt
add_executable(ROUNDROBIN ${SOURCES})
=======
add_executable(TSK4 ${SOURCES})
>>>>>>> d24869bf3a2a9f1ec0d067c674bc4878628a0d5c:Task4_RoundRobin/CMakeLists.txt
