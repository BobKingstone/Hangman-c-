cmake_minimum_required(VERSION 3.2)
project(Hangman)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Hangman/main.cpp)

add_executable(Hangman ${SOURCE_FILES})