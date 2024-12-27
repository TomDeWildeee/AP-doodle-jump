#ifndef DOODLE_JUMP_PLAYER_H
#define DOODLE_JUMP_PLAYER_H

#include "EntityModel.h"

namespace Logic {

class Player : public EntityModel {
public:
    explicit Player(const std::pair<float, float>& coords);
    void update() override;
    void moveLeft();
    void moveRight();
    // I don't know if force is high or low enough, should be tested
    void jump(float force = 1.0f);
    [[nodiscard]] bool isJumping() const;

private:
    // Test values, not sure if values make sense
    float moveSpeed = 0.1f;
    float jumpForce = -0.5f;
    float gravity = 0.01f;
};

} // namespace Logic

#endif // DOODLE_JUMP_PLAYER_H
