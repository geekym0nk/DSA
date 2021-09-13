cmake_minimum_required(VERSION 3.5.21)

project(staircases)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")

add_executable(${PROJECT_NAME} 
               "source/main.cpp"
               "source/staircases.cpp")

install(TARGETS ${PROJECT_NAME} DESTINATION bin)