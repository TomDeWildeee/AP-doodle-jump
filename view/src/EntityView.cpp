#include "../include/EntityView.h"

namespace View {

EntityView::EntityView(const std::shared_ptr<Logic::EntityModel>& model) : model(model) {}

EntityView::~EntityView() = default;

void EntityView::updateEntityView() {
    if (auto modelPtr = model.lock()) {
        updateView(modelPtr);
    }
}
bool EntityView::isOffScreen(float maxY) const {
    if (auto entity = model.lock()) {
        return entity->getCoords().second > maxY;
    }
    return true;
}

} // namespace View