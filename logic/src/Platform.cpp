#include "../include/Platform.h"
#include <cmath>
#include <utility>

namespace Logic {

Platform::Platform(const std::pair<float, float>& coords, PlatformType type)
    : EntityModel(coords), type(type), initialX(coords.first), initialY(coords.second), timeElapsed(0.0f) {}

void Platform::update(float deltaTime) {
    if (!active)
        return;

    timeElapsed += deltaTime;

    switch (type) {
    case PlatformType::HORIZONTAL:
        coords.first = initialX + std::sin(timeElapsed * moveSpeed * 0.015f) * moveDistance;
        break;

    case PlatformType::VERTICAL:
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