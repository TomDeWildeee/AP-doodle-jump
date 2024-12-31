#include "../../include/logic/BGTile.h"
namespace Logic {

BGTile::BGTile(const std::pair<float, float>& coords) : EntityModel(coords) {}

void BGTile::update(float deltaTime) { notify(); }

} // namespace Logic