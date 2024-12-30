#include "../headers/view/PlayerView.h"

namespace View {

PlayerView::PlayerView(const std::shared_ptr<Logic::Player>& player) : EntityView(player) {
    if (!texture.loadFromFile("../../assets/doodle.png")) {
        throw std::runtime_error("Could not load doodle texture");
    }
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    sprite.setScale(0.1f, 0.1f);
}

void PlayerView::updateView(std::shared_ptr<Logic::EntityModel> model) {
    std::pair<float, float> coords = model->getCoords();
    sprite.setPosition(coords.first, coords.second);
}

void PlayerView::draw(sf::RenderWindow& window) { window.draw(sprite); }

} // namespace View