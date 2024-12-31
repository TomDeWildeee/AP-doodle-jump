#include "../../include/logic/Platform.h"
#include <cmath>

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
        if (disappearTimer > 0) {
            disappearTimer -= deltaTime;
        } else {
            alpha -= deltaTime * 0.5f;
            if (alpha <= 0) {
                alpha = 0;
                active = false;
            }
        }
        break;
    default:
        break;
    }

    notify();
}

PlatformType Platform::getType() const { return type; }
bool Platform::isActive() const { return active; }
float Platform::getAlpha() const { return alpha; }

void Platform::deActivate() {
    active = false;
    notify();
}
} // namespace Logic