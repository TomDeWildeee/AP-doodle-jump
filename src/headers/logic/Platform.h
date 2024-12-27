#ifndef DOODLE_JUMP_PLATFORM_H
#define DOODLE_JUMP_PLATFORM_H

#include "EntityModel.h"
namespace Logic {

enum class PlatformType { NORMAL, BREAKABLE, MOVABLE, DISAPPEARING };

class Platform : public EntityModel {
public:
    Platform(const std::pair<float, float>& coords, PlatformType type);
    void update(float deltaTime) override;

    [[nodiscard]] PlatformType getType() const;
    [[nodiscard]] bool isActive() const;
    void deActivate();
    
    // For disappearing platforms
    float getAlpha() const;

private:
    PlatformType type;
    bool active = true;
    float alpha = 1.0f;
    float initialX;
    float moveDistance = 1.0f;
    float moveSpeed = 1.0f;
    float disappearTimer = 0.01f;
};

} // namespace Logic
#endif // DOODLE_JUMP_PLATFORM_H
