/**
 * @file World.h
 * @brief Manages the game world and all entities within it
 */

#ifndef DOODLE_JUMP_WORLD_H
#define DOODLE_JUMP_WORLD_H

#include "Camera.h"
#include "EntityFactory.h"
#include "Score.h"

namespace Logic {

/**
 * @class World
 * @brief Controls game world state, entity generation and interactions
 */
class World {
public:
    /**
     * @brief Constructs game world with specified dimensions
     * @param width World width
     * @param height World height
     * @param factory Entity factory for creating game objects
     */
    World(float width, float height, const std::shared_ptr<EntityFactory>& factory);
    ~World();

    /**
     * @brief Updates world state
     */
    void update();

    /**
     * @brief Gets player entity
     * @return Shared pointer to player
     */
    [[nodiscard]] std::shared_ptr<Player> getPlayer() const { return player; }

    /**
     * @brief Gets camera view
     * @return Const reference to camera
     */
    [[nodiscard]] const Camera& getCamera() const { return *camera; }

private:
    std::shared_ptr<EntityFactory> factory;
    std::shared_ptr<Player> player;
    std::vector<std::shared_ptr<Platform>> platforms;
    std::vector<std::shared_ptr<Bonus>> bonuses;
    std::vector<std::shared_ptr<BGTile>> bgTiles;
    std::unique_ptr<Camera> camera;

    float width;
    float height;

    /**
     * @brief Generates random platform type based on value
     * @param randValue Random value
     * @return Random platform type
     */
    static PlatformType getRandomPlatformType(float randValue);

    /**
     * @brief Generates platforms within specified Y range
     * @param fromY Lower Y bound
     * @param toY Upper Y bound
     */
    void generatePlatforms(float fromY, float toY);

    /**
     * @brief Generates background tiles in Y range
     * @param fromY Lower Y bound
     * @param toY Upper Y bound
     */
    void generateBGTiles(float fromY, float toY);

    /**
     * @brief Determines if bonus should be generated
     * @param platform Platform to check
     * @param playerY Player's Y position
     * @return True if bonus should be generated
     */
    static bool shouldGenerateBonus(const std::shared_ptr<Platform>& platform, float playerY);

    /**
     * @brief Checks if bonus can be placed at coordinates
     * @param coords Proposed coordinates
     * @return True if placement is valid
     */
    bool canPlaceBonus(const std::pair<float, float>& coords);

    /**
     * @brief Removes off-screen entities
     */
    void cleanup();

    /**
     * @brief Checks for collisions between entities
     */
    void checkCollisions();
};

} // namespace Logic

#endif // DOODLE_JUMP_WORLD_H
