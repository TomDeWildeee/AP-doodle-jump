/**
 * @file PlayerView.h
 * @brief Handles rendering of player character
 */

#ifndef DOODLE_JUMP_PLAYERVIEW_H
#define DOODLE_JUMP_PLAYERVIEW_H

#include "../../logic/include/Player.h"
#include "EntityView.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace View {

/**
 * @class PlayerView
 * @brief Renders player character with directional sprites
 */
class PlayerView : public EntityView {
public:
    /**
     * @brief Constructs view for player entity
     * @param player Shared pointer to player model
     */
    explicit PlayerView(const std::shared_ptr<Logic::Player>& player);

    /**
     * @brief Renders player to window
     * @param window Target render window
     */
    void draw(sf::RenderWindow& window) override;

protected:
    /**
     * @brief Updates view based on model changes
     * @param model Updated entity model
     */
    void updateView(std::shared_ptr<Logic::EntityModel> model) override;

private:
    sf::Texture leftDoodleTexture;
    sf::Texture rightDoodleTexture;
    sf::Sprite sprite;
};

} // namespace View

#endif // DOODLE_JUMP_PLAYERVIEW_H
