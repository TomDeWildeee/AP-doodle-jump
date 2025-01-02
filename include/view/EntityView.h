#ifndef DOODLE_JUMP_ENTITYVIEW_H
#define DOODLE_JUMP_ENTITYVIEW_H

#include "../logic/EntityModel.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>

namespace View {

class EntityView : public Logic::ViewObserver {
public:
    explicit EntityView(const std::shared_ptr<Logic::EntityModel>& model);
    ~EntityView() override;

    void updateEntityView() override;
    virtual void draw(sf::RenderWindow& window) = 0;
    [[nodiscard]] bool isOffScreen(float maxY) const;

protected:
    virtual void updateView(std::shared_ptr<Logic::EntityModel> model) = 0;

    // I believe I need a weak pointer here?
    std::weak_ptr<Logic::EntityModel> model;
};

} // namespace View

#endif // DOODLE_JUMP_ENTITYVIEW_H
