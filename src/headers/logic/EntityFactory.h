#ifndef DOODLE_JUMP_ENTITYFACTORY_H
#define DOODLE_JUMP_ENTITYFACTORY_H

#include "BGTile.h"
#include "Bonus.h"
#include "Platform.h"
#include "Player.h"
#include <memory>
namespace Logic {

class EntityFactory {
public:
    virtual ~EntityFactory() = default;
    virtual std::shared_ptr<Player> createPlayer(const std::pair<float, float>& coords) = 0;
    virtual std::shared_ptr<Platform> createPlatform(const std::pair<float, float>& coords, PlatformType type) = 0;
    virtual std::shared_ptr<Bonus> createBonus(const std::pair<float, float>& coords, BonusType type) = 0;
    virtual std::shared_ptr<BGTile> createBGTile(const std::pair<float, float>& coords) = 0;
};

} // namespace Logic

#endif // DOODLE_JUMP_ENTITYFACTORY_H
