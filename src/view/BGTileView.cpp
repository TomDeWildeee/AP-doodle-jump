#include "../headers/view/BGTileView.h"

namespace View {

BGTileView::BGTileView(const std::shared_ptr<Logic::BGTile>& bgTile) : EntityView(bgTile) {
    shape.setSize(sf::Vector2f(70.0f, 70.0f));
    shape.setFillColor(sf::Color::Black);
    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(1.0f);
    shape.setOrigin(35.0f, 35.0f);
}

void BGTileView::updateView(std::shared_ptr<Logic::EntityModel> model) {
    std::pair<float, float> coords = model->getCoords();
    shape.setPosition(coords.first, coords.second);
}

void BGTileView::draw(sf::RenderWindow& window) { window.draw(shape); }

} // namespace View