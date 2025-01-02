#include "../include/EntityModel.h"

namespace Logic {

EntityModel::EntityModel(const std::pair<float, float>& coords) : coords(coords), velocity({0, 0}) {}

EntityModel::~EntityModel() = default;

const std::pair<float, float>& EntityModel::getCoords() const { return coords; }

const std::pair<float, float>& EntityModel::getVelocity() const { return velocity; }

void EntityModel::setCoords(const std::pair<float, float>& pair) {
    EntityModel::coords = pair;
    notifyEntityUpdate();
}
void EntityModel::setVelocity(const std::pair<float, float>& pair) {
    EntityModel::velocity = pair;
    notifyEntityUpdate();
}
} // namespace Logic
