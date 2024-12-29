#include "../headers/view/PlatformView.h"
#include <iostream>

namespace View {

PlatformView::PlatformView(const std::shared_ptr<Logic::Platform>& platform) : EntityView(platform) {
    shape.setSize(sf::Vector2f(120, 20.0f));
    shape.setOrigin(30.0f, 10.0f);
    updateColor(platform->getType());
}

void PlatformView::updateView(std::shared_ptr<Logic::EntityModel> model) {
    // I know dynamic pointer cast is not the best practice, but I'm not sure how to avoid it here
    std::shared_ptr<Logic::Platform> platform = std::dynamic_pointer_cast<Logic::Platform>(model);
    if (model) {
        std::pair<float, float> coords = model->getCoords();
        shape.setPosition(coords.first, coords.second);
        updateColor(platform->getType());
    }
}

void PlatformView::updateColor(Logic::PlatformType type) {
    switch (type) {
    case Logic::PlatformType::NORMAL:
        shape.setFillColor(sf::Color::Green);
        break;
    case Logic::PlatformType::BREAKABLE:
        shape.setFillColor(sf::Color::White);
        break;
    case Logic::PlatformType::MOVABLE:
        shape.setFillColor(sf::Color::Blue);
        break;
    case Logic::PlatformType::DISAPPEARING:
        shape.setFillColor(sf::Color::Yellow);
        break;
    }
}

void PlatformView::draw(sf::RenderWindow& window) { window.draw(shape); }

} // namespace View