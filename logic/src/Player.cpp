#include "../include/Player.h"

namespace Logic {

Player::Player(const std::pair<float, float>& coords) : EntityModel(coords) {}

void Player::update(float deltaTime) {

    // Update player y velocity with += gravity * deltaTime
    velocity.second += gravity * deltaTime;

    // Update player coords with += velocity * deltaTime
    coords.first += velocity.first * deltaTime;
    coords.second += velocity.second * deltaTime;

    // Notify observers of entity update
    notifyEntityUpdate();
}

void Player::moveLeft() { velocity.first = -moveSpeed; }
void Player::moveRight() { velocity.first = moveSpeed; }
void Player::jump(float force) { velocity.second = jumpForce * force; }
void Player::bonusCollected(BonusType bonusType, bool isActive) {
    // Check if bonus is active and notify observers of bonus collected
    if (isActive)
        return;
    notifyBonusCollected(bonusType);
}
void Player::platformReuse(PlatformType platformType) { notifyPlatformReuse(platformType); }

} // namespace Logic