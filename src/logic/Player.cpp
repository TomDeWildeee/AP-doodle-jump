// src/logic/Player.cpp
#include "../headers/logic/Player.h"

namespace Logic {

Player::Player(const std::pair<float, float>& coords) : EntityModel(coords) {}

void Player::update(float deltaTime) {
    if (jetpackActive) {
        velocity.second = jetpackForce;
        jetpackTimer += deltaTime;
        if (jetpackTimer >= jetpackDuration) {
            jetpackActive = false;
            jetpackTimer = 0.0f;
            velocity.second = 0;
        }
    } else {
        velocity.second += gravity * deltaTime;
    }

    coords.first += velocity.first * deltaTime;
    coords.second += velocity.second * deltaTime;

    notify();
}

void Player::moveLeft() { velocity.first = -moveSpeed; }
void Player::moveRight() { velocity.first = moveSpeed; }
void Player::jump(float force) { velocity.second = jumpForce * force; }
bool Player::isJumping() const { return velocity.second != 0; }

// TODO: split code off to bonus class ->

void Player::setJetpack(bool b) { this->jetpack = b; }

void Player::controlJetpack() {
    if (jetpack && !jetpackActive) {
        jetpackActive = true;
        jetpackTimer = 0.0f;
        velocity.second = jetpackForce;
    }
}

} // namespace Logic