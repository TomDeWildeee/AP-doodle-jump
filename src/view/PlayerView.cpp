#include "../../include/view/PlayerView.h"

namespace View {

PlayerView::PlayerView(const std::shared_ptr<Logic::Player>& player) : EntityView(player) {
    if (!rightDoodleTexture.loadFromFile("../../assets/doodle_right.png")) {
        throw std::runtime_error("Could not load doodle texture");
    }
    if (!leftDoodleTexture.loadFromFile("../../assets/doodle_left.png")) {
        throw std::runtime_error("Could not load doodle texture");
    }

    sprite.setTexture(rightDoodleTexture);
    sprite.setOrigin(rightDoodleTexture.getSize().x / 2, rightDoodleTexture.getSize().y / 2);
    sprite.setScale(0.1f, 0.1f);
}

void PlayerView::updateView(std::shared_ptr<Logic::EntityModel> model) {
    std::pair<float, float> coords = model->getCoords();
    sprite.setPosition(coords.first, coords.second);

    if (model->getVelocity().first < 0) {
        sprite.setTexture(leftDoodleTexture);
    } else {
        sprite.setTexture(rightDoodleTexture);
    }
}

void PlayerView::draw(sf::RenderWindow& window) { window.draw(sprite); }

} // namespace View