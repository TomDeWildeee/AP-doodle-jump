#include "../../include/logic/Stopwatch.h"
#include <gtest/gtest.h>
#include <thread>

// Some tests learned from the internet like the thread sleep stuff

TEST(StopwatchTest, InitialDeltaTime) {
    Logic::Stopwatch& stopwatch = Logic::Stopwatch::getInstance();
    EXPECT_FLOAT_EQ(stopwatch.getDeltaTime(), 0.0f);
}

TEST(StopwatchTest, StartAndTick) {
    Logic::Stopwatch& stopwatch = Logic::Stopwatch::getInstance();
    stopwatch.start();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    stopwatch.tick();
    EXPECT_NEAR(stopwatch.getDeltaTime(), 0.1f, 0.015f);
}

TEST(StopwatchTest, MultipleTicks) {
    Logic::Stopwatch& stopwatch = Logic::Stopwatch::getInstance();
    stopwatch.start();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    stopwatch.tick();
    float firstDelta = stopwatch.getDeltaTime();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    stopwatch.tick();
    float secondDelta = stopwatch.getDeltaTime();
    EXPECT_NEAR(firstDelta, 0.05f, 0.015f);
    EXPECT_NEAR(secondDelta, 0.05f, 0.015f);
}