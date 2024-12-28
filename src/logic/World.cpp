#include "../headers/logic/World.h"
#include "../headers/logic/Random.h"
#include "../headers/logic/Score.h"
#include "../headers/logic/Stopwatch.h"
#include <algorithm>
#include <iostream>

namespace Logic {

World::World(float width, float height, const std::shared_ptr<EntityFactory>& factory)
    : factory(factory), width(width), height(height), highestY(height) {

    player = factory->createPlayer({width / 2, height / 2});

    camera = std::make_unique<Camera>(width, height);

    //    generatePlatforms(height, 0);
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

    // TODO: fix this

    float cameraY = camera->getY();
    if (cameraY - height / 2 < highestY) {
        generatePlatforms(highestY, cameraY - height / 2);
        generateBGTiles(highestY, cameraY - height / 2);

        highestY = cameraY - height / 2;

        Score::getInstance().onNewHeight(highestY);
    }

    cleanup();
}

// TODO: fix this
void World::checkCollisions() {
    for (const auto& platform : platforms) {
        if (!platform->isActive())
            continue;

        float px = player->getCoords().first;
        float py = player->getCoords().second;
        float platX = platform->getCoords().first;
        float platY = platform->getCoords().second;

        if (player->getVelocity().second > 0) {
            const float PLAYER_WIDTH = 40.0f;
            const float PLAYER_HEIGHT = 40.0f;
            const float PLATFORM_WIDTH = 60.0f;
            const float PLATFORM_HEIGHT = 20.0f;

            if (px + PLAYER_WIDTH / 2 > platX - PLATFORM_WIDTH / 2 &&
                px - PLAYER_WIDTH / 2 < platX + PLATFORM_WIDTH / 2 &&
                py + PLAYER_HEIGHT / 2 > platY - PLATFORM_HEIGHT / 2 &&
                py + PLAYER_HEIGHT / 2 < platY + PLATFORM_HEIGHT / 2) {

                player->setCoords({px, platY - PLATFORM_HEIGHT / 2 - PLAYER_HEIGHT / 2});
                player->jump();

                if (platform->getType() == PlatformType::BREAKABLE) {
                    platform->deActivate();
                }
            }
        }
    }
}

void World::generatePlatforms(float fromY, float toY) {
    //    Random random = Random::getInstance();

    platforms.push_back(factory->createPlatform({300, 300}, PlatformType::NORMAL));
}

void World::cleanup() {
    auto isOffScreen = [this](const std::shared_ptr<EntityModel>& entity) {
        return !camera->isVisible(entity->getCoords().second);
    };

    platforms.erase(std::remove_if(platforms.begin(), platforms.end(), isOffScreen), platforms.end());

    bonuses.erase(std::remove_if(bonuses.begin(), bonuses.end(), isOffScreen), bonuses.end());

    bgTiles.erase(std::remove_if(bgTiles.begin(), bgTiles.end(), isOffScreen), bgTiles.end());
}

bool World::shouldGenerateBonus() {
    //    return Random::getInstance().getFloat(0, 1) < 0.1f; // 10% chance
    return false;
}

void World::generateBGTiles(float fromY, float toY) {
    //    float tileSize = 100.0f;
    //    int numColumns = static_cast<int>(width / tileSize) + 1;
    //
    //    for (float y = fromY; y > toY; y -= tileSize) {
    //        for (int x = 0; x < numColumns; ++x) {
    //            auto tile = factory->createBGTile({x * tileSize, y});
    //            bgTiles.push_back(tile);
    //        }
    //    }
}
} // namespace Logic