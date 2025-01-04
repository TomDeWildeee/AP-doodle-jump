#include "../include/BonusView.h"
#include "GameException.h"

namespace View {

BonusView::BonusView(const std::shared_ptr<Logic::Bonus>& bonus) : EntityView(bonus) {

    // Load textures for spring and jetpack
    if (!springTexture.loadFromFile("../../assets/spring.png")) {
        throw Logic::ResourceLoadException("spring.png");
    }
    if (!jetpackTexture.loadFromFile("../../assets/jetpack.png")) {
        throw Logic::ResourceLoadException("jetpack.png");
    }

    // Set sprite properties and update texture based on bonus type
    updateTexture(bonus->getType());
}

void BonusView::updateView(std::shared_ptr<Logic::EntityModel> model) {
    // Get coords from model and set sprite position
    std::pair<float, float> coords = model->getCoords();
    sprite.setPosition(coords.first, coords.second);
}

void BonusView::updateTexture(Logic::BonusType type) {
    // Update texture based on bonus type
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