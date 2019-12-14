cmake_minimum_required(VERSION 3.10)

project(cracking-the-coding-interview
    VERSION 0.1
    DESCRIPTION "A project implementing the interview questions to the 6th edition of McDowell's <<Cracking the Coding Interview>>"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include/ctci include/thirdparty)
set(SOURCES src/urlify.cpp src/uniqueCharacters.cpp src/checkPermutation.cpp)
add_library(ctci-lib ${SOURCES})
add_executable(ctci src/main.cpp)
target_link_libraries(ctci ctci-lib)

option(BUILD_TESTS "Toggle test build manually" ON)

if((PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME) AND BUILD_TESTS)
	message(STATUS "Building tests...")
	enable_testing()
	include(GoogleTest)
	add_subdirectory(test)
endif()

install(TARGETS ctci DESTINATION /usr/local/bin)
