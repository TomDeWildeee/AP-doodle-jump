#ifndef DOODLE_JUMP_PLAYER_H
#define DOODLE_JUMP_PLAYER_H

#include "EntityModel.h"

namespace Logic {

class Player : public EntityModel {
public:
    explicit Player(const std::pair<float, float>& coords);
    void update(float deltaTime) override;
    void moveLeft();
    void moveRight();
    void jump(float force = 2.5f);

    void bonusCollected(BonusType bonusType, bool isActive);
    void platformReuse(PlatformType platformType);

private:
    float moveSpeed = 200.0f;
    float jumpForce = -300.0f;
    float gravity = 800.0f;
};

} // namespace Logic

#endif // DOODLE_JUMP_PLAYER_H