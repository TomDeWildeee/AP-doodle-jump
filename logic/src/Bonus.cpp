#include "../include/Bonus.h"
#include "../include/Player.h"

namespace Logic {

Bonus::Bonus(const std::pair<float, float>& coords, BonusType type)
    : EntityModel(coords), type(type), jetpackDuration(2.0f) {}

void Bonus::update(float deltaTime) {

    // Get active player and check if bonus is active and player exists
    std::shared_ptr<Player> player = activePlayer.lock();
    if (active && player) {

        // Set player velocity to jetpack force and update jetpack timer
        player->setVelocity({player->getVelocity().first, jetpackForce});
        jetpackTimer += deltaTime;

        // If jetpack timer is greater than or equal to jetpack duration, deactivate jetpack and make player jump
        if (jetpackTimer >= jetpackDuration) {
            active = false;
            jetpackTimer = 0.0f;
            player->jump();
        }
    }
    notifyEntityUpdate();
}

BonusType Bonus::getType() const { return type; }

void Bonus::activate(const std::shared_ptr<Player>& player) {
    if (active)
        return;

    switch (type) {
    case BonusType::SPRING:
        player->jump(5.0f);
        active = true;
        break;
    case BonusType::JETPACK:
        activePlayer = player;
        active = true;
        jetpackTimer = 0.0f;
        player->setVelocity({player->getVelocity().first, jetpackForce});
        break;
    }
    notifyEntityUpdate();
    notifyBonusCollected(getType());
}
bool Bonus::isActive() const { return active; }

} // namespace Logic