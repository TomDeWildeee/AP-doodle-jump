#ifndef DOODLE_JUMP_PLATFORM_H
#define DOODLE_JUMP_PLATFORM_H

#include "EntityModel.h"
namespace Logic {

enum class PlatformType { STATIC, HORIZONTAL, VERTICAL, TEMPORARY };

class Platform : public EntityModel {
public:
    Platform(const std::pair<float, float>& coords, PlatformType type);
    void update(float deltaTime) override;
    void deActivate();

    [[nodiscard]] PlatformType getType() const;
    [[nodiscard]] bool isActive() const;
    [[nodiscard]] float getAlpha() const;

    // For disappearing platforms

private:
    PlatformType type;
    bool active = true;
    float alpha = 1.0f;
    float initialX;
    float initialY;
    float moveDistance = 100.0f;
    float moveSpeed = 100.0f;
    float disappearTimer = 3.0f;
    float timeElapsed;
};

} // namespace Logic
#endif // DOODLE_JUMP_PLATFORM_H
