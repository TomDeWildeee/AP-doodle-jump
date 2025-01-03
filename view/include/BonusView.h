/**
 * @file BonusView.h
 * @brief View class for bonus item entities
 */

#ifndef DOODLE_JUMP_BONUSVIEW_H
#define DOODLE_JUMP_BONUSVIEW_H

#include "../../logic/include/Bonus.h"
#include "EntityView.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
namespace View {

/**
 * @class BonusView
 * @brief Handles rendering of bonus items
 */
class BonusView : public EntityView {
public:
    /**
     * @brief Constructs view for a bonus item
     * @param bonus Shared pointer to bonus model
     */
    explicit BonusView(const std::shared_ptr<Logic::Bonus>& bonus);

    /**
     * @brief Renders bonus to window
     * @param window Target render window
     */
    void draw(sf::RenderWindow& window) override;

protected:
    /**
     * @brief Updates view based on model state
     * @param model Updated entity model
     */
    void updateView(std::shared_ptr<Logic::EntityModel> model) override;

private:
    sf::Sprite sprite;
    sf::Texture jetpackTexture;
    sf::Texture springTexture;

    /**
     * @brief Updates texture based on bonus type
     * @param type Type of bonus
     */
    void updateTexture(Logic::BonusType type);
};

} // namespace View

#endif // DOODLE_JUMP_BONUSVIEW_H
