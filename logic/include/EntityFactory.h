/**
 * @file EntityFactory.h
 * @brief Abstract factory for creating game entities
 */

#ifndef DOODLE_JUMP_ENTITYFACTORY_H
#define DOODLE_JUMP_ENTITYFACTORY_H

#include "BGTile.h"
#include "Bonus.h"
#include "Platform.h"

namespace Logic {

/**
 * @class EntityFactory
 * @brief Abstract factory interface for creating game entities
 */
class EntityFactory {
public:
    virtual ~EntityFactory() = default;

    /**
     * @brief Creates a player entity
     * @param coords Starting coordinates
     * @return Shared pointer to created player
     */
    virtual std::shared_ptr<Player> createPlayer(const std::pair<float, float>& coords) = 0;

    /**
     * @brief Creates a platform entity
     * @param coords Platform coordinates
     * @param type Platform type
     * @return Shared pointer to created platform
     */
    virtual std::shared_ptr<Platform> createPlatform(const std::pair<float, float>& coords, PlatformType type) = 0;

    /**
     * @brief Creates a bonus entity
     * @param coords Bonus coordinates
     * @param type Bonus type
     * @return Shared pointer to created bonus
     */
    virtual std::shared_ptr<Bonus> createBonus(const std::pair<float, float>& coords, BonusType type) = 0;

    /**
     * @brief Creates a background tile
     * @param coords Tile coordinates
     * @return Shared pointer to created tile
     */
    virtual std::shared_ptr<BGTile> createBGTile(const std::pair<float, float>& coords) = 0;

    /**
     * @brief Cleans up entity views below specified Y coordinate
     * @param maxY Maximum Y coordinate to keep
     */
    virtual void cleanupViews(float maxY) = 0;
};

} // namespace Logic

#endif // DOODLE_JUMP_ENTITYFACTORY_H
