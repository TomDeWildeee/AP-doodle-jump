/**
 * @file EntityView.h
 * @brief Base class for all entity view components
 */

#ifndef DOODLE_JUMP_ENTITYVIEW_H
#define DOODLE_JUMP_ENTITYVIEW_H

#include "../../logic/include/EntityModel.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>

namespace View {

/**
 * @class EntityView
 * @brief Abstract base class for rendering game entities
 *
 * Implements observer pattern to update views when model changes
 */
class EntityView : public Logic::ViewObserver {
public:
    /**
     * @brief Constructs view for an entity model
     * @param model Shared pointer to entity model
     */
    explicit EntityView(const std::shared_ptr<Logic::EntityModel>& model);
    ~EntityView() override;

    /**
     * @brief Updates view when model changes
     */
    void updateEntityView() override;

    /**
     * @brief Renders entity to window
     * @param window Target render window
     */
    virtual void draw(sf::RenderWindow& window) = 0;

    /**
     * @brief Checks if entity is off screen
     * @param maxY Maximum Y coordinate visible
     * @return True if entity is off screen
     */
    [[nodiscard]] bool isOffScreen(float maxY) const;

protected:
    /**
     * @brief Updates view based on model state
     * @param model Updated entity model
     */
    virtual void updateView(std::shared_ptr<Logic::EntityModel> model) = 0;

    std::weak_ptr<Logic::EntityModel> model;
};

} // namespace View

#endif // DOODLE_JUMP_ENTITYVIEW_H
