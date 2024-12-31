#include "../../include/logic/Bonus.h"

namespace Logic {

Bonus::Bonus(const std::pair<float, float>& coords, BonusType type)
    : EntityModel(coords), type(type), jetpackDuration(2.0f) {}

void Bonus::update(float deltaTime) {
    std::shared_ptr<Player> player = activePlayer.lock();
    if (active && player) {
        player->setVelocity({player->getVelocity().first, jetpackForce});
        jetpackTimer += deltaTime;
        if (jetpackTimer >= jetpackDuration) {
            active = false;
            jetpackTimer = 0.0f;
            player->jump();
        }
    }
    notify();
}

BonusType Bonus::getType() const { return type; }

void Bonus::activate(const std::shared_ptr<Player>& player) {
    if (active)
        return;

    switch (type) {
    case BonusType::SPRING:
        player->jump(5.0f);
        break;
    case BonusType::JETPACK:
        activePlayer = player;
        active = true;
        jetpackTimer = 0.0f;
        player->setVelocity({player->getVelocity().first, jetpackForce});
        break;
    }
    notify();
}
bool Bonus::isActive() const { return active; }

} // namespace Logic