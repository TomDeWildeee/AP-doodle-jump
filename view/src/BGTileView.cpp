#include "../include/BGTileView.h"

namespace View {

BGTileView::BGTileView(const std::shared_ptr<Logic::BGTile>& bgTile) : EntityView(bgTile) {

    // Set shape properties
    shape.setSize(sf::Vector2f(20.0f, 20.0f));
    shape.setFillColor(sf::Color::White);
    shape.setOutlineColor(sf::Color(160, 200, 220));
    shape.setOutlineThickness(1.0f);
}

void BGTileView::updateView(std::shared_ptr<Logic::EntityModel> model) {
    // Get coords from model and set shape position
    std::pair<float, float> coords = model->getCoords();
    shape.setPosition(coords.first, coords.second);
}

void BGTileView::draw(sf::RenderWindow& window) { window.draw(shape); }

} // namespace View