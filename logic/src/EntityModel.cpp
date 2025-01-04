#include "../include/EntityModel.h"
#include "../include/GameException.h"
#include <cmath>

namespace Logic {

EntityModel::EntityModel(const std::pair<float, float>& coords) : coords(coords), velocity({0, 0}) {}

EntityModel::~EntityModel() = default;

const std::pair<float, float>& EntityModel::getCoords() const { return coords; }

const std::pair<float, float>& EntityModel::getVelocity() const { return velocity; }

void EntityModel::setCoords(const std::pair<float, float>& pair) {
    // Check if coords are NaN and throw exception if they are
    if (std::isnan(coords.first) || std::isnan(coords.second)) {
        throw InvalidCoordinatesException("NaN detected");
    }

    // Set coords and notify observers of entity update
    EntityModel::coords = pair;
    notifyEntityUpdate();
}
void EntityModel::setVelocity(const std::pair<float, float>& pair) {

    // Set velocity and notify observers of entity update
    EntityModel::velocity = pair;
    notifyEntityUpdate();
}
} // namespace Logic
