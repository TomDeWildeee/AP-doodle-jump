#include "../headers/logic/Player.h"

namespace Logic {

Player::Player(const std::pair<float, float>& coords) : EntityModel(coords) {}

void Player::update() {
    // should add time here later instead of 2
    velocity.second += gravity * 2;

    coords.first += velocity.first * 2;
    coords.second += velocity.second * 2;

    notify();
}

void Player::moveLeft() { velocity.first = -moveSpeed; }
void Player::moveRight() { velocity.first = moveSpeed; }
void Player::jump(float force) { velocity.second = jumpForce * force; }
bool Player::isJumping() const { return velocity.second != 0; }
} // namespace Logic