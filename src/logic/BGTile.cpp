#include "../headers/logic/BGTile.h"

namespace Logic {

BGTile::BGTile(const std::pair<float, float>& coords) : EntityModel(coords) {}

void BGTile::update(float deltaTime) {
    // Should probably be empty, cause background are not gonna move?
}

} // namespace Logic