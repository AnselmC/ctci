cmake_minimum_required(VERSION 3.7)

project(cracking-the-coding-interview
    VERSION 0.1
    DESCRIPTION "A project implementing the interview questions to the 6th edition of McDowell's <<Cracking the Coding Interview>>"
    LANGUAGES CXX)

include_directories(include/ctci include/thirdparty)

set(SOURCES src/main.cpp src/urlify.cpp)

add_executable(ctci ${SOURCES})

install(TARGETS ctci DESTINATION /usr/local/bin)
