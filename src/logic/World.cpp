#include "../headers/logic/World.h"
#include "../headers/logic/Random.h"
#include "../headers/logic/Score.h"
#include "../headers/logic/Stopwatch.h"
#include "../headers/view/PlatformView.h"
#include <algorithm>
#include <iostream>

namespace Logic {

World::World(float width, float height, const std::shared_ptr<EntityFactory>& factory)
    : factory(factory), width(width), height(height), highestY(height) {

    player = factory->createPlayer({width / 2, height / 2});

    camera = std::make_unique<Camera>(width, height);

    platforms.push_back(factory->createPlatform({width / 2, height / 2}, PlatformType::NORMAL));
    generatePlatforms(height, 0);
}

void World::update() {
    Stopwatch stopwatch = Stopwatch::getInstance();
    float deltaTime = stopwatch.getDeltaTime();

    player->update(deltaTime);

    float playerX = player->getCoords().first;
    if (playerX < 0) {
        player->setCoords({width, player->getCoords().second});
    } else if (playerX > width) {
        player->setCoords({0, player->getCoords().second});
    }

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

    float highestY = 0;
    if (!platforms.empty()) {
        highestY = platforms[0]->getCoords().second;
        for (const auto& platform : platforms) {
            if (platform->getCoords().second < highestY) {
                highestY = platform->getCoords().second;

                Score& score = Score::getInstance();
                score.onNewHeight(highestY);
            }
        }
    }

    float cameraY = camera->getY();
    float topOfView = cameraY - height / 2;

    if (highestY > topOfView - 300) {
        generatePlatforms(highestY - 240, topOfView - 800);
    }

    checkCollisions();

    cleanup();
}

void World::checkCollisions() {
    for (const auto& platform : platforms) {
        if (!platform->isActive())
            continue;

        float px = player->getCoords().first;
        float py = player->getCoords().second;
        float platX = platform->getCoords().first;
        float platY = platform->getCoords().second;

        if (player->getVelocity().second > 0) {

            float verticalDistance = std::abs(py - platY);
            float horizontalDistance = std::abs(px - platX);

            if (verticalDistance < 20 && horizontalDistance < 60) {
                player->setCoords({px, platY - 30});
                player->setVelocity({player->getVelocity().first, 0});
                player->jump();

                if (platform->getType() == PlatformType::BREAKABLE) {
                    platform->deActivate();
                }

                break;
            }
        }
    }
}

// Took me ages to figure out and get good
void World::generatePlatforms(float fromY, float toY) {
    Random& random = Random::getInstance();

    const float VERTICAL_SPACING = random.getFloat(100.0f, 200.0f);
    std::cout << VERTICAL_SPACING << std::endl;

    const float LEFT_EDGE = 100.0f;
    const float RIGHT_EDGE = width - 100.0f;

    for (float y = fromY; y > toY; y -= VERTICAL_SPACING) {
        int generateLeft = random.getInt(0, 1);
        float x;
        if (generateLeft == 1) {
            x = random.getFloat(LEFT_EDGE, width / 2 - 50.0f);
        } else {
            x = random.getFloat(width / 2 + 50.0f, RIGHT_EDGE);
        }

        platforms.push_back(factory->createPlatform({x, y}, PlatformType::NORMAL));
    }
}

void World::cleanup() {
    float cameraY = camera->getY();
    float bufferZone = height / 2 + 200.0f;

    platforms.erase(std::remove_if(platforms.begin(), platforms.end(),
                                   [cameraY, bufferZone](const std::shared_ptr<Platform>& platform) {
                                       if (!platform->isActive())
                                           return true;
                                       auto y = platform->getCoords().second;
                                       return y > cameraY + bufferZone;
                                   }),
                    platforms.end());

    factory->cleanupViews(cameraY + bufferZone);
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