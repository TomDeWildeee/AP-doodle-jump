#ifndef DOODLE_JUMP_PLAYERVIEW_H
#define DOODLE_JUMP_PLAYERVIEW_H

#include "../logic/Player.h"
#include "EntityView.h"
#include <SFML/Graphics/RectangleShape.hpp>
namespace View {

class PlayerView : public EntityView {
public:
    explicit PlayerView(const std::shared_ptr<Logic::Player>& player);
    void draw(sf::RenderWindow& window) override;

protected:
    void updateView(std::shared_ptr<Logic::EntityModel> model) override;

private:
    sf::RectangleShape shape;
};

} // namespace View

#endif // DOODLE_JUMP_PLAYERVIEW_H
