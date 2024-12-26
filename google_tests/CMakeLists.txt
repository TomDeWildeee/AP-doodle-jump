project(Google_tests)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run subject_test.cpp ../../src/logic/Subject.cpp ../../src/headers/logic/Observer.h)
target_link_libraries(Google_Tests_run gtest gtest_main)