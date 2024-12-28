#ifndef DOODLE_JUMP_PLATFORMVIEW_H
#define DOODLE_JUMP_PLATFORMVIEW_H

#include "../logic/Platform.h"
#include "EntityView.h"
#include <SFML/Graphics/RectangleShape.hpp>
namespace View {

class PlatformView : public EntityView {
public:
    explicit PlatformView(const std::shared_ptr<Logic::Platform>& platform);
    void draw(sf::RenderWindow& window) override;

protected:
    void updateView(std::shared_ptr<Logic::EntityModel> model) override;

private:
    sf::RectangleShape shape;
    void updateColor(Logic::PlatformType type);
};

} // namespace View

#endif // DOODLE_JUMP_PLATFORMVIEW_H
