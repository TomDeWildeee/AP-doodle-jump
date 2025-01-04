#include "../include/PlayerView.h"
#include "GameException.h"

namespace View {

PlayerView::PlayerView(const std::shared_ptr<Logic::Player>& player) : EntityView(player) {
    // Load textures for doodle and throw exception if it fails
    if (!rightDoodleTexture.loadFromFile("../../assets/doodle_right.png")) {
        throw Logic::ResourceLoadException("doodle_right.png");
    }
    if (!leftDoodleTexture.loadFromFile("../../assets/doodle_left.png")) {
        throw Logic::ResourceLoadException("doodle_left.png");
    }

    // Set sprite properties
    sprite.setTexture(rightDoodleTexture);
    sprite.setOrigin(rightDoodleTexture.getSize().x / 2, rightDoodleTexture.getSize().y / 2);
    sprite.setScale(0.1f, 0.1f);
}

void PlayerView::updateView(std::shared_ptr<Logic::EntityModel> model) {

    // Get coords from model and set sprite position
    std::pair<float, float> coords = model->getCoords();
    sprite.setPosition(coords.first, coords.second);

    // Update texture based on player velocity direction (left or right)
    if (model->getVelocity().first < 0) {
        sprite.setTexture(leftDoodleTexture);
    } else {
        sprite.setTexture(rightDoodleTexture);
    }
}

void PlayerView::draw(sf::RenderWindow& window) { window.draw(sprite); }

} // namespace View