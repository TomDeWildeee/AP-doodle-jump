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
    [[nodiscard]] bool isJumping() const;

    void setJetpack(bool b);
    void controlJetpack();

private:
    // Test values, not sure if values make sense
    float moveSpeed = 200.0f;
    float jumpForce = -300.0f;
    float gravity = 800.0f;
    float jetpackForce = -800.0f;
    float jetpackDuration = 2.0f;
    float jetpackTimer = 0.0f;

    bool jetpack = false;
    bool jetpackActive = false;
};

} // namespace Logic

#endif // DOODLE_JUMP_PLAYER_H
