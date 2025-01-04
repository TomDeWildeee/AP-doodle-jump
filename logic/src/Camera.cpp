#include "../include/Camera.h"
#include "../include/Stopwatch.h"

// Lower y position of the camera = higher up the camera is in the game world

namespace Logic {

Camera::Camera(float width, float height) : width(width), height(height), y(0), minY(0), maxY(0) {}

void Camera::update(float newY) {
    // If the new y position is higher than the current y position, do not update the camera
    if (newY > y)
        return;

    // Get delta time and update the camera y position based on the new y position
    float deltaTime = Stopwatch::getInstance().getDeltaTime();
    y = newY;
    float difference = y - minY;
    // Update the min y position based on the difference between the new y position and the min y position * 0.1f *
    // delta time
    minY += difference * 0.1f * deltaTime;
}

bool Camera::isVisible(float givenY) const {
    // Check if the given y position is within the current y position + buffer zone of the camera
    return givenY < y + bufferZone;
}

float Camera::getY() const { return y; }
float Camera::getBufferzone() const { return bufferZone; }

} // namespace Logic