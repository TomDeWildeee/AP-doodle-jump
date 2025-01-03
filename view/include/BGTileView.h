/**
 * @file BGTileView.h
 * @brief View class for background tile entities
 */

#ifndef DOODLE_JUMP_BGTILEVIEW_H
#define DOODLE_JUMP_BGTILEVIEW_H

#include "../../logic/include/BGTile.h"
#include "EntityView.h"
#include <SFML/Graphics/RectangleShape.hpp>
namespace View {

/**
 * @class BGTileView
 * @brief Handles rendering of background tile entities
 */
class BGTileView : public EntityView {
public:
    /**
     * @brief Constructs view for a background tile
     * @param bgTile Shared pointer to tile model
     */
    explicit BGTileView(const std::shared_ptr<Logic::BGTile>& bgTile);

    /**
     * @brief Renders tile to window
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
    sf::RectangleShape shape;
};
} // namespace View

#endif // DOODLE_JUMP_BGTILEVIEW_H
