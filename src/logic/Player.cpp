// src/logic/Player.cpp
#include "../headers/logic/Player.h"

namespace Logic {

Player::Player(const std::pair<float, float>& coords) : EntityModel(coords) {}

void Player::update(float deltaTime) {
    velocity.second += gravity * deltaTime;

    coords.first += velocity.first * deltaTime;
    coords.second += velocity.second * deltaTime;

    notify();
}

void Player::moveLeft() { velocity.first = -moveSpeed; }
void Player::moveRight() { velocity.first = moveSpeed; }
void Player::jump(float force) { velocity.second = jumpForce * force; }

} // namespace Logic