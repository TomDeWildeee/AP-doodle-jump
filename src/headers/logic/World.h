#ifndef DOODLE_JUMP_WORLD_H
#define DOODLE_JUMP_WORLD_H

#include "Camera.h"
#include "EntityFactory.h"

namespace Logic {

class World {
public:
    World(float width, float height, const std::shared_ptr<EntityFactory>& factory);

    void update();
    void generatePlatforms(float fromY, float toY);
    void cleanup();
    void checkCollisions();

    std::shared_ptr<Player> getPlayer() const { return player; }
    // Get camera by reference to avoid copying it (hopefully)
    const Camera& getCamera() const { return *camera; }

private:
    std::shared_ptr<EntityFactory> factory;
    std::shared_ptr<Player> player;
    std::vector<std::shared_ptr<Platform>> platforms;
    std::vector<std::shared_ptr<Bonus>> bonuses;
    std::vector<std::shared_ptr<BGTile>> bgTiles;
    std::unique_ptr<Camera> camera;

    float width;
    float height;
    float highestY;
    void generateBGTiles(float fromY, float toY);
    bool shouldGenerateBonus();
};

} // namespace Logic

#endif // DOODLE_JUMP_WORLD_H
