#include "../headers/view/BonusView.h"

namespace View {

BonusView::BonusView(const std::shared_ptr<Logic::Bonus>& bonus) : EntityView(bonus) {
    shape_.setRadius(15.0f);
    shape_.setOrigin(15.0f, 15.0f);
    updateColor(bonus->getType());
}

void BonusView::updateView(std::shared_ptr<Logic::EntityModel> model) {
    std::pair<float, float> coords = model->getCoords();
    shape_.setPosition(coords.first, coords.second);
}

void BonusView::updateColor(Logic::BonusType type) {
    switch (type) {
    case Logic::BonusType::SPRING:
        shape_.setFillColor(sf::Color::Magenta);
        break;
    case Logic::BonusType::JETPACK:
        shape_.setFillColor(sf::Color::Cyan);
        break;
    }
}

void BonusView::draw(sf::RenderWindow& window) { window.draw(shape_); }

} // namespace View