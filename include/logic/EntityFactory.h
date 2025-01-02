#ifndef DOODLE_JUMP_ENTITYFACTORY_H
#define DOODLE_JUMP_ENTITYFACTORY_H

#include "../view/EntityView.h"
#include "BGTile.h"
#include "Bonus.h"
#include "Platform.h"

namespace Logic {

class EntityFactory {
public:
    virtual ~EntityFactory() = default;
    virtual std::shared_ptr<Player> createPlayer(const std::pair<float, float>& coords) = 0;
    virtual std::shared_ptr<Platform> createPlatform(const std::pair<float, float>& coords, PlatformType type) = 0;
    virtual std::shared_ptr<Bonus> createBonus(const std::pair<float, float>& coords, BonusType type) = 0;
    virtual std::shared_ptr<BGTile> createBGTile(const std::pair<float, float>& coords) = 0;
    virtual std::vector<std::shared_ptr<View::EntityView>>& getViews() = 0;
    virtual void cleanupViews(float maxY) = 0;
};

} // namespace Logic

#endif // DOODLE_JUMP_ENTITYFACTORY_H
