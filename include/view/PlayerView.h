#ifndef DOODLE_JUMP_PLAYERVIEW_H
#define DOODLE_JUMP_PLAYERVIEW_H

#include "../logic/Player.h"
#include "EntityView.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
namespace View {

class PlayerView : public EntityView {
public:
    explicit PlayerView(const std::shared_ptr<Logic::Player>& player);
    void draw(sf::RenderWindow& window) override;

protected:
    void updateView(std::shared_ptr<Logic::EntityModel> model) override;

private:
    sf::Texture leftDoodleTexture;
    sf::Texture rightDoodleTexture;
    sf::Sprite sprite;
};

} // namespace View

#endif // DOODLE_JUMP_PLAYERVIEW_H
