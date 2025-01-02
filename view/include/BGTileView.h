#ifndef DOODLE_JUMP_BGTILEVIEW_H
#define DOODLE_JUMP_BGTILEVIEW_H

#include "../../logic/include/BGTile.h"
#include "EntityView.h"
#include <SFML/Graphics/RectangleShape.hpp>
namespace View {

class BGTileView : public EntityView {
public:
    explicit BGTileView(const std::shared_ptr<Logic::BGTile>& bgTile);
    void draw(sf::RenderWindow& window) override;

protected:
    void updateView(std::shared_ptr<Logic::EntityModel> model) override;

private:
    sf::RectangleShape shape;
};
} // namespace View

#endif // DOODLE_JUMP_BGTILEVIEW_H
