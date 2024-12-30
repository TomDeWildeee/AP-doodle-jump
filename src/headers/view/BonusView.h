#ifndef DOODLE_JUMP_BONUSVIEW_H
#define DOODLE_JUMP_BONUSVIEW_H

#include "../logic/Bonus.h"
#include "EntityView.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
namespace View {

class BonusView : public EntityView {
public:
    explicit BonusView(const std::shared_ptr<Logic::Bonus>& bonus);
    void draw(sf::RenderWindow& window) override;

protected:
    void updateView(std::shared_ptr<Logic::EntityModel> model) override;

private:
    sf::Sprite sprite;
    sf::Texture jetpackTexture;
    sf::Texture springTexture;
    void updateTexture(Logic::BonusType type);
};

} // namespace View

#endif // DOODLE_JUMP_BONUSVIEW_H
