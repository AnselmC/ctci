cmake_minimum_required(VERSION 3.10) add_subdirectory(
    "${PROJECT_SOURCE_DIR}/thirdparty/googletest"
    "thirdparty/googletest" EXCLUDE_FROM_ALL)

    include(GoogleTest)

        enable_testing()

            add_executable(dummyTest dummyTest.cpp) target_link_libraries(
                dummyTest gtest gtest_main)

                add_executable(testArraysAndStrings testArraysAndStrings.cpp)
                    target_link_libraries(testArraysAndStrings ctci -
                                          lib gtest gtest_main)

                        gtest_discover_tests(dummyTest DISCOVERY_TIMEOUT 60)
                            gtest_discover_tests(
                                testArraysAndStrings DISCOVERY_TIMEOUT 60)
