#include "../../include/logic/Player.h"

namespace Logic {

Player::Player(const std::pair<float, float>& coords) : EntityModel(coords) {}

void Player::update(float deltaTime) {
    velocity.second += gravity * deltaTime;

    coords.first += velocity.first * deltaTime;
    coords.second += velocity.second * deltaTime;

    notifyEntityUpdate();
}

void Player::moveLeft() { velocity.first = -moveSpeed; }
void Player::moveRight() { velocity.first = moveSpeed; }
void Player::jump(float force) { velocity.second = jumpForce * force; }
void Player::bonusCollected(BonusType bonusType, bool isActive) {
    if (isActive)
        return;
    notifyBonusCollected(bonusType);
}
void Player::platformReuse(PlatformType platformType) { notifyPlatformReuse(platformType); }

} // namespace Logic