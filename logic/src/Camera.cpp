#include "../include/Camera.h"
#include "../include/Stopwatch.h"

namespace Logic {

Camera::Camera(float width, float height) : width(width), height(height), y(0), minY(0), maxY(0) {}

void Camera::update(float newY) {
    if (newY > y)
        return;
    float deltaTime = Stopwatch::getInstance().getDeltaTime();
    y = newY;
    float difference = y - minY;
    minY += difference * 0.1f * deltaTime;
}

bool Camera::isVisible(float givenY) const { return givenY < y + bufferZone; }

float Camera::getY() const { return y; }
float Camera::getBufferzone() const { return bufferZone; }

} // namespace Logic