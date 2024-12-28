#include "../headers/view/PlayerView.h"

namespace View {

PlayerView::PlayerView(const std::shared_ptr<Logic::Player>& player) : EntityView(player) {
    shape.setSize(sf::Vector2f(50.0f, 50.0f));
    shape.setFillColor(sf::Color::Red);
    shape.setOrigin(25.0f, 25.0f);
}

void PlayerView::updateView(std::shared_ptr<Logic::EntityModel> model) {
    std::pair<float, float> coords = model->getCoords();
    shape.setPosition(coords.first, coords.second);
}

void PlayerView::draw(sf::RenderWindow& window) { window.draw(shape); }

} // namespace View