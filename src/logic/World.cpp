#include "../headers/logic/World.h"
#include "../headers/logic/Random.h"
#include "../headers/logic/Score.h"
#include "../headers/logic/Stopwatch.h"

namespace Logic {

World::World(float width, float height, const std::shared_ptr<EntityFactory>& factory)
    : factory(factory), width(width), height(height), highestY(height) {

    player = factory->createPlayer({width / 2, height / 2});

    camera = std::make_unique<Camera>(width, height);

    generatePlatforms(height, 0);
    generateBGTiles(height, 0);
}

void World::update() {
    Stopwatch stopwatch = Stopwatch::getInstance();
    float deltaTime = stopwatch.getDeltaTime();

    player->update(deltaTime);

    for (auto& platform : platforms) {
        platform->update(deltaTime);
    }

    for (auto& bonus : bonuses) {
        bonus->update(deltaTime);
    }

    for (auto& bgTile : bgTiles) {
        bgTile->update(deltaTime);
    }

    camera->update(player->getCoords().second);

    checkCollisions();

    // Logic to generate new platforms and bg tiles when the camera reaches a certain height
    float cameraY = camera->getY();
    if (cameraY - height / 2 < highestY) {
        generatePlatforms(highestY, cameraY - height / 2);
        generateBGTiles(highestY, cameraY - height / 2);

        highestY = cameraY - height / 2;

        Score::getInstance().onNewHeight(highestY);
    }

    cleanup();
}

// Most of the values in here are randomly found online, so they might not be the best
void World::generatePlatforms(float fromY, float toY) {
    float y = fromY;
    while (y > toY) {
        float x = Random::getInstance().getFloat(0, width);
        float aFloat = Random::getInstance().getFloat(toY - height, fromY + height);
        auto type = static_cast<PlatformType>(Random::getInstance().getInt(0, 3));
        std::shared_ptr<Platform> platform = factory->createPlatform({x, aFloat}, type);
        platforms.push_back(platform);
        y = aFloat;
    }
}

} // namespace Logic