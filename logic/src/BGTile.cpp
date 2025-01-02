#include "../include/BGTile.h"
namespace Logic {

BGTile::BGTile(const std::pair<float, float>& coords) : EntityModel(coords) {}

void BGTile::update(float deltaTime) { notifyEntityUpdate(); }

} // namespace Logic