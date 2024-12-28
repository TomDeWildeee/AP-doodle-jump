#ifndef DOODLE_JUMP_BGTILE_H
#define DOODLE_JUMP_BGTILE_H

#include "EntityModel.h"

namespace Logic {

class BGTile : public EntityModel {
public:
    explicit BGTile(const std::pair<float, float>& coords);
    void update(float deltaTime) override;
};

} // namespace Logic

#endif // DOODLE_JUMP_BGTILE_H
