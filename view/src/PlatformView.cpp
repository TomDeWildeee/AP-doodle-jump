#include "../include/PlatformView.h"
#include "GameException.h"

namespace View {

void PlatformView::loadTextures() {
    // Load textures for each platform type and throw exception if it fails
    if (!greenTexture.loadFromFile("../../assets/green_platform.png")) {
        throw Logic::ResourceLoadException("green_platform.png");
    }
    if (!yellowTexture.loadFromFile("../../assets/yellow_platform.png")) {
        throw Logic::ResourceLoadException("yellow_platform.png");
    }
    if (!blueTexture.loadFromFile("../../assets/blue_platform.png")) {
        throw Logic::ResourceLoadException("blue_platform.png");
    }
    if (!whiteTexture.loadFromFile("../../assets/white_platform.png")) {
        throw Logic::ResourceLoadException("white_platform.png");
    }
}

PlatformView::PlatformView(const std::shared_ptr<Logic::Platform>& platform) : EntityView(platform) {

    // Load textures and set sprite origin and update texture based on platform type
    loadTextures();

    sprite.setOrigin(greenTexture.getSize().x / 2, greenTexture.getSize().y / 2);
    updateTexture(platform->getType());
}

void PlatformView::updateView(std::shared_ptr<Logic::EntityModel> model) {

    // Get coords from model and set sprite position
    std::pair<float, float> coords = model->getCoords();
    sprite.setPosition(coords.first, coords.second);
}

void PlatformView::updateTexture(Logic::PlatformType type) {
    // Update texture based on platform type
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