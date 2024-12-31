#include "../../include/view/BonusView.h"

namespace View {

BonusView::BonusView(const std::shared_ptr<Logic::Bonus>& bonus) : EntityView(bonus) {
    if (!springTexture.loadFromFile("../../assets/spring.png")) {
        throw std::runtime_error("Could not load doodle texture");
    }
    if (!jetpackTexture.loadFromFile("../../assets/jetpack.png")) {
        throw std::runtime_error("Could not load doodle texture");
    }
    updateTexture(bonus->getType());
}

void BonusView::updateView(std::shared_ptr<Logic::EntityModel> model) {
    std::pair<float, float> coords = model->getCoords();
    sprite.setPosition(coords.first, coords.second);
}

void BonusView::updateTexture(Logic::BonusType type) {
    switch (type) {
    case Logic::BonusType::SPRING:
        sprite.setTexture(springTexture);
        sprite.setOrigin(springTexture.getSize().x / 2, springTexture.getSize().y / 2);
        break;
    case Logic::BonusType::JETPACK:
        sprite.setTexture(jetpackTexture);
        sprite.setOrigin(jetpackTexture.getSize().x / 2, jetpackTexture.getSize().y / 2);
        break;
    }
}

void BonusView::draw(sf::RenderWindow& window) { window.draw(sprite); }

} // namespace View