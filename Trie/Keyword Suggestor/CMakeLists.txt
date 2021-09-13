cmake_minimum_required(VERSION 3.5.21)

project(KeywordSuggestor)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")

include_directories(header)

add_executable(${PROJECT_NAME} 
               "header/WordNode.h"
               "header/Dictionary.h"
               "header/helper.h"
               "source/helper.cpp"
               "source/WordNode.cpp"
               "source/Dictionary.cpp"
               "source/KeywordSuggestor.cpp")

install(TARGETS KeywordSuggestor DESTINATION bin)