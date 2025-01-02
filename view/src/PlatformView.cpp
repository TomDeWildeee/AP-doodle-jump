#include "../include/PlatformView.h"

namespace View {

void PlatformView::loadTextures() {
    if (!greenTexture.loadFromFile("../../assets/green_platform.png")) {
        throw std::runtime_error("Could not load doodle texture");
    }
    if (!yellowTexture.loadFromFile("../../assets/yellow_platform.png")) {
        throw std::runtime_error("Could not load doodle texture");
    }
    if (!blueTexture.loadFromFile("../../assets/blue_platform.png")) {
        throw std::runtime_error("Could not load doodle texture");
    }
    if (!whiteTexture.loadFromFile("../../assets/white_platform.png")) {
        throw std::runtime_error("Could not load doodle texture");
    }
}

PlatformView::PlatformView(const std::shared_ptr<Logic::Platform>& platform) : EntityView(platform) {
    loadTextures();

    sprite.setOrigin(greenTexture.getSize().x / 2, greenTexture.getSize().y / 2);
    updateTexture(platform->getType());
}

void PlatformView::updateView(std::shared_ptr<Logic::EntityModel> model) {
    std::pair<float, float> coords = model->getCoords();
    sprite.setPosition(coords.first, coords.second);
}

void PlatformView::updateTexture(Logic::PlatformType type) {
    switch (type) {
    case Logic::PlatformType::STATIC:
        sprite.setTexture(greenTexture);
        break;
    case Logic::PlatformType::TEMPORARY:
        sprite.setTexture(whiteTexture);
        break;
    case Logic::PlatformType::HORIZONTAL:
        sprite.setTexture(blueTexture);
        break;
    case Logic::PlatformType::VERTICAL:
        sprite.setTexture(yellowTexture);
        break;
    }
}

void PlatformView::draw(sf::RenderWindow& window) { window.draw(sprite); }

} // namespace View