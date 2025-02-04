#include "../logic/include/Camera.h"
#include <gtest/gtest.h>

TEST(CameraTest, InitialValues) {
    Logic::Camera camera(800, 600);
    EXPECT_EQ(camera.getY(), 0);
}

// Positive coords means down
TEST(CameraTest, UpdateYPositionLower) {
    Logic::Camera camera(800, 600);
    camera.update(100);
    EXPECT_EQ(camera.getY(), 0);
}

// Negative coords means up
TEST(CameraTest, UpdateYPositionHigher) {
    Logic::Camera camera(800, 600);
    camera.update(-100);
    EXPECT_NEAR(camera.getY(), -100, 1e-5);
}
// Positive coords means down, negative means up
TEST(CameraTest, VisibilityCheck) {
    Logic::Camera camera(800, 600);
    EXPECT_TRUE(camera.isVisible(0));
    EXPECT_TRUE(camera.isVisible(300));
    EXPECT_TRUE(camera.isVisible(400));
    // 499 is bottom of the screen
    EXPECT_FALSE(camera.isVisible(500));
}