/**
 * @file ConcreteFactory.h
 * @brief Concrete implementation of entity factory
 */

#ifndef DOODLE_JUMP_CONCRETEFACTORY_H
#define DOODLE_JUMP_CONCRETEFACTORY_H

#include "../../logic/include/EntityFactory.h"
#include "EntityView.h"

namespace View {

/**
 * @class ConcreteFactory
 * @brief Creates and manages game entities and their views
 */
class ConcreteFactory : public Logic::EntityFactory {
public:
    ~ConcreteFactory() override;

    /**
     * @brief Creates player entity with view
     * @param coords Starting coordinates
     * @return Shared pointer to player
     */
    std::shared_ptr<Logic::Player> createPlayer(const std::pair<float, float>& coords) override;

    /**
     * @brief Creates platform entity with view
     * @param coords Platform coordinates
     * @param type Platform type
     * @return Shared pointer to platform
     */
    std::shared_ptr<Logic::Platform> createPlatform(const std::pair<float, float>& coords,
                                                    Logic::PlatformType type) override;

    /**
     * @brief Creates background tile with view
     * @param coords Tile coordinates
     * @return Shared pointer to tile
     */
    std::shared_ptr<Logic::BGTile> createBGTile(const std::pair<float, float>& coords) override;

    /**
     * @brief Creates bonus item with view
     * @param coords Bonus coordinates
     * @param type Bonus type
     * @return Shared pointer to bonus
     */
    std::shared_ptr<Logic::Bonus> createBonus(const std::pair<float, float>& coords, Logic::BonusType type) override;

    /**
     * @brief Gets all entity views
     * @return Vector of entity views
     */
    std::vector<std::shared_ptr<EntityView>>& getViews();

    /**
     * @brief Removes views below specified Y coordinate
     * @param maxY Maximum Y coordinate to keep
     */
    void cleanupViews(float maxY) override;

private:
    std::vector<std::shared_ptr<EntityView>> views;
};

} // namespace View

#endif // DOODLE_JUMP_CONCRETEFACTORY_H
