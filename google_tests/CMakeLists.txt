project(Google_tests)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run subject_test.cpp ../../logic/src/Subject.cpp ../../logic/include/ViewObserver.h
        ../../logic/include/ScoreObserver.h
        ../../logic/src/GameException.cpp
        ../../logic/src/EntityModel.cpp
        ../../logic/src/Camera.cpp
        ../../logic/src/Stopwatch.cpp
        ../../logic/src/Score.cpp
        entitymodel_test.cpp
        camera_test.cpp
        score_test.cpp
        stopwatch_test.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main)