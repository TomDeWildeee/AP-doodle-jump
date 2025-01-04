#include "../include/EntityView.h"

namespace View {

EntityView::EntityView(const std::shared_ptr<Logic::EntityModel>& model) : model(model) {}

EntityView::~EntityView() = default;

void EntityView::updateEntityView() {
    // Get model pointer and update view
    if (auto modelPtr = model.lock()) {
        updateView(modelPtr);
    }
}
bool EntityView::isOffScreen(float maxY) const {
    // Get model pointer and check if entity is offscreen
    if (auto entity = model.lock()) {
        return entity->getCoords().second > maxY;
    }
    return true;
}

} // namespace View