project(Google_tests)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run subject_test.cpp ../../src/logic/Subject.cpp ../../include/logic/Observer.h
        ../../src/logic/EntityModel.cpp
        ../../src/logic/Camera.cpp
        ../../src/logic/Stopwatch.cpp
        ../../src/logic/Score.cpp
        entitymodel_test.cpp
        camera_test.cpp
        score_test.cpp
        stopwatch_test.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main)