/**
 * @file PlatformView.h
 * @brief Handles rendering of platform entities
 */

#ifndef DOODLE_JUMP_PLATFORMVIEW_H
#define DOODLE_JUMP_PLATFORMVIEW_H

#include "../../logic/include/Platform.h"
#include "EntityView.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
namespace View {

/**
 * @class PlatformView
 * @brief Renders platform entities with different textures based on type
 */
class PlatformView : public EntityView {
public:
    /**
     * @brief Constructs view for platform entity
     * @param platform Shared pointer to platform model
     */
    explicit PlatformView(const std::shared_ptr<Logic::Platform>& platform);

    /**
     * @brief Renders platform to window
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
    sf::Texture greenTexture;
    sf::Texture yellowTexture;
    sf::Texture blueTexture;
    sf::Texture whiteTexture;
    sf::Sprite sprite;

    /**
     * @brief Loads platform textures from files
     */
    void loadTextures();

    /**
     * @brief Updates sprite texture based on platform type
     * @param type Platform type to render
     */
    void updateTexture(Logic::PlatformType type);
};

} // namespace View

#endif // DOODLE_JUMP_PLATFORMVIEW_H
