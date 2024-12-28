#include "../../src/headers/logic/Camera.h"
#include <gtest/gtest.h>

TEST(CameraTest, InitialValues) {
    Logic::Camera camera(800, 600);
    EXPECT_EQ(camera.getY(), 0);
}

TEST(CameraTest, UpdateYPosition) {
    Logic::Camera camera(800, 600);
    camera.update(100);
    EXPECT_NEAR(camera.getY(), 100, 1e-5);
}

TEST(CameraTest, WorldToScreenConversion) {
    Logic::Camera camera(800, 600);
    float x = 0, y = 100;
    camera.worldToScreen(x, y);
    EXPECT_NEAR(y, 200, 1e-5);
}

TEST(CameraTest, VisibilityCheck) {
    Logic::Camera camera(800, 600);
    EXPECT_TRUE(camera.isVisible(0));
    EXPECT_TRUE(camera.isVisible(300));
    EXPECT_FALSE(camera.isVisible(400));
}