#include "../headers/logic/Camera.h"
#include "../headers/logic/Stopwatch.h"

namespace Logic {

Camera::Camera(float width, float height) : width(width), height(height), y(0), minY(0), maxY(0) {}

void Camera::update(float newY) {
    float deltaTime = Stopwatch::getInstance().getDeltaTime();
    y = newY;
    float difference = y - minY;
    minY += difference * 0.1f * deltaTime;
}

void Camera::worldToScreen(float& givenX, float& givenY) const { givenY = height / 2 - (givenY - minY); }

bool Camera::isVisible(float givenY) const { return givenY >= minY - height / 2 && givenY <= minY + height / 2; }

float Camera::getY() const { return y; }

} // namespace Logic