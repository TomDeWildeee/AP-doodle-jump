#include "../headers/logic/Platform.h"
#include <cmath>

namespace Logic {

Platform::Platform(const std::pair<float, float>& coords, PlatformType type)
    : EntityModel(coords), type(type), initialX(coords.first) {}

void Platform::update(float deltaTime) {
    if (!active)
        return;

    switch (type) {
    case PlatformType::MOVABLE:
        coords.first = initialX + std::sin(moveSpeed * deltaTime) * moveDistance;
        break;

    case PlatformType::DISAPPEARING:
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