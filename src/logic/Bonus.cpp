#include "../headers/logic/Bonus.h"

namespace Logic {

Bonus::Bonus(const std::pair<float, float>& coords, BonusType type) : EntityModel(coords), type(type) {}

void Bonus::update(float deltaTime) {
    if (!active)
        return;
}

BonusType Bonus::getType() const { return type; }

void Bonus::activate(const std::shared_ptr<Player>& player) {
    if (!active)
        return;

    switch (type) {
    case BonusType::SPRING:
        player->jump(1.5f);
        break;
    case BonusType::JETPACK:
        player->setJetpack(true);
        player->controlJetpack(true);
        break;
    }
    active = false;
    notify();
}

} // namespace Logic