#ifndef DOODLE_JUMP_PLATFORMVIEW_H
#define DOODLE_JUMP_PLATFORMVIEW_H

#include "../../logic/include/Platform.h"
#include "EntityView.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
namespace View {

class PlatformView : public EntityView {
public:
    explicit PlatformView(const std::shared_ptr<Logic::Platform>& platform);
    void draw(sf::RenderWindow& window) override;

protected:
    void updateView(std::shared_ptr<Logic::EntityModel> model) override;

private:
    sf::Texture greenTexture;
    sf::Texture yellowTexture;
    sf::Texture blueTexture;
    sf::Texture whiteTexture;
    sf::Sprite sprite;
    void loadTextures();
    void updateTexture(Logic::PlatformType type);
};

} // namespace View

#endif // DOODLE_JUMP_PLATFORMVIEW_H
