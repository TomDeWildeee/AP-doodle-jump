#include "../include/Platform.h"
#include <cmath>
#include <utility>

namespace Logic {

Platform::Platform(const std::pair<float, float>& coords, PlatformType type)
    : EntityModel(coords), type(type), initialX(coords.first), initialY(coords.second), timeElapsed(0.0f) {}

void Platform::update(float deltaTime) {

    // Check if platform is active
    if (!active)
        return;

    // Update time elapsed
    timeElapsed += deltaTime;

    // Update platform based on type
    switch (type) {
    case PlatformType::HORIZONTAL:
        coords.first += moveSpeed * deltaTime;

        // 45 is half the width of the platform, 480 is the width of the window
        if (coords.first <= 45 || coords.first >= 480 - 45) {
            moveSpeed = -moveSpeed;
        }
        break;

    case PlatformType::VERTICAL:
        // Move platform up and down based on sine function
        coords.second = initialY + std::cos(timeElapsed * moveSpeed * 0.015f) * moveDistance;
        break;

    case PlatformType::TEMPORARY:
        if (timesJumpedOn > 0)
            deActivate();
        break;
    default:
        break;
    }

    notifyEntityUpdate();
}

PlatformType Platform::getType() const { return type; }
bool Platform::isActive() const { return active; }

void Platform::deActivate() {
    active = false;
    notifyEntityUpdate();
}

void Platform::incrementJumps() { timesJumpedOn++; }

int Platform::getTimesJumpedOn() const { return timesJumpedOn; }

} // namespace Logic