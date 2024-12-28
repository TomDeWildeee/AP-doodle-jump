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
    // I don't know if force is high or low enough, should be tested
    void jump(float force = 1.0f);
    [[nodiscard]] bool isJumping() const;

    void setJetpack(bool b);
    void controlJetpack(bool activate);

private:
    // Test values, not sure if values make sense
    float moveSpeed = 0.1f;
    float jumpForce = -0.5f;
    float gravity = 0.01f;
    float jetpackForce = -0.2f;
    float jetpackDuration = 5.0f;
    float jetpackTimer = 0.0f;

    bool jumping = false;
    bool jetpack = false;
    bool jetpackActive = false;
};

} // namespace Logic

#endif // DOODLE_JUMP_PLAYER_H
