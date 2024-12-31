#include "../headers/logic/World.h"
#include "../headers/logic/Random.h"
#include "../headers/logic/Stopwatch.h"
#include "../headers/view/PlatformView.h"
#include <algorithm>
#include <iostream>

namespace Logic {

const float TILE_SIZE = 20.0f;
const float MIN_DISTANCE = 30.0f;

World::World(float width, float height, const std::shared_ptr<EntityFactory>& factory,
             const std::shared_ptr<Score>& score)
    : factory(factory), score(score), width(width), height(height) {

    player = factory->createPlayer({width / 2, height / 2});

    camera = std::make_unique<Camera>(width, height);

    player->jump();
    generatePlatforms(height, 0);
    generateBGTiles(height, 0);
}

void World::update() {
    Random& random = Random::getInstance();
    Stopwatch stopwatch = Stopwatch::getInstance();
    float deltaTime = stopwatch.getDeltaTime();

    player->update(deltaTime);

    float playerX = player->getCoords().first;
    float playerY = player->getCoords().second;

    if (playerX < 25) {
        player->setCoords({25, player->getCoords().second});
    } else if (playerX > width - 25) {
        player->setCoords({width - 25, player->getCoords().second});
    }

    for (auto& bgTile : bgTiles) {
        bgTile->update(deltaTime);
    }

    for (auto& platform : platforms) {
        platform->update(deltaTime);
    }

    for (auto& bonus : bonuses) {
        bonus->update(deltaTime);
    }

    camera->update(player->getCoords().second);

    float highestYCoord = 0;
    float highestBGTileYCoord = 0;

    if (!platforms.empty()) {
        highestYCoord = platforms[0]->getCoords().second;
        for (const auto& platform : platforms) {
            if (platform->getCoords().second < highestYCoord) {
                highestYCoord = platform->getCoords().second;

                score->onNewHeight(highestYCoord);
            }
        }
    }

    for (const auto& tile : bgTiles) {
        highestBGTileYCoord = std::min(highestBGTileYCoord, tile->getCoords().second);
    }

    float cameraY = camera->getY();
    float topOfView = cameraY - height / 2;

    if (highestBGTileYCoord > topOfView - 100) {
        generateBGTiles(highestBGTileYCoord, topOfView - 800);
    }

    if (highestYCoord > topOfView - 300) {
        generatePlatforms(highestYCoord - 240, topOfView - 800);

        for (const auto& platform : platforms) {
            if (shouldGenerateBonus(platform, playerY)) {
                float bonusX = platform->getCoords().first;
                float bonusY = platform->getCoords().second - 30.0f;

                if (canPlaceBonus({bonusX, bonusY})) {
                    BonusType type = (random.getFloat(0, 1) < 0.8f) ? BonusType::SPRING : BonusType::JETPACK;
                    bonuses.push_back(factory->createBonus({bonusX, bonusY}, type));
                }
            }
        }
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
        float platY = platform->getCoords().second - 20; // - 20 voor hitbox omdat getCoords() de origin coords geeft

        if (player->getVelocity().second > 0) {

            float verticalDistance = std::abs(py - platY);
            float horizontalDistance = std::abs(px - platX);

            if (verticalDistance < 20 && horizontalDistance < 60) {
                player->jump();

                if (platform->getType() == PlatformType::TEMPORARY) {
                    platform->deActivate();
                }

                break;
            }
        }
    }

    for (const auto& bonus : bonuses) {

        float px = player->getCoords().first;
        float py = player->getCoords().second;
        float bonusX = bonus->getCoords().first;
        float bonusY = bonus->getCoords().second;

        float verticalDistance = std::abs(py - bonusY);
        float horizontalDistance = std::abs(px - bonusX);

        if (verticalDistance < 30 && horizontalDistance < 30) {
            score->onBonusCollected(bonus->getType());
            bonus->activate(player);

            break;
        }
    }
}

PlatformType getRandomPlatformType(float randValue) {
    std::vector<std::pair<PlatformType, float>> weightedTypes = {{PlatformType::STATIC, 80.0f},
                                                                 {PlatformType::TEMPORARY, 10.0f},
                                                                 {PlatformType::HORIZONTAL, 5.0f},
                                                                 {PlatformType::VERTICAL, 5.0f}};

    float cumulativeWeight = 0.0f;
    for (const auto& typeWeight : weightedTypes) {
        cumulativeWeight += typeWeight.second;
        if (randValue <= cumulativeWeight) {
            return typeWeight.first;
        }
    }

    return PlatformType::STATIC;
}

// Took me ages to figure out and get good
void World::generatePlatforms(float fromY, float toY) {
    Random& random = Random::getInstance();

    float heightFactor = std::min((-fromY / 5000.0f), 1.0f);

    struct PlatformPos {
        float x, y;
    };

    std::vector<PlatformPos> generatedPositions;
    float verticalSpacing = random.getFloat(40.0f, 70.0f);

    for (float y = fromY; y > toY; y -= verticalSpacing) {
        float spawnChance = 0.95f - (heightFactor * 0.15f);

        if (random.getFloat(0, 1) < spawnChance) {
            float x;
            if (random.getInt(0, 1) == 0) {
                x = random.getFloat(100.0f, width / 2 - 50.0f);
            } else {
                x = random.getFloat(width / 2 + 50.0f, width - 100.0f);
            }

            bool tooClose = false;

            for (const auto& pos : generatedPositions) {
                float dx = std::abs(x - pos.x);
                float dy = std::abs(y - pos.y);
                float distance = std::sqrt(dx * dx + dy * dy);
                if (distance < 60.0f) {
                    tooClose = true;
                    break;
                }
            }

            float randomValue = random.getFloat(0.0f, 100.0f);
            PlatformType randomPlatformType = getRandomPlatformType(randomValue);

            if (!tooClose) {
                platforms.push_back(factory->createPlatform({x, y}, randomPlatformType));
                generatedPositions.push_back({x, y});
            }
        }

        verticalSpacing = random.getFloat(40.0f, 70.0f);
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

    bonuses.erase(std::remove_if(bonuses.begin(), bonuses.end(),
                                 [cameraY, bufferZone](const std::shared_ptr<Bonus>& bonus) {
                                     auto y = bonus->getCoords().second;
                                     return (y > cameraY + bufferZone && !bonus->isActive());
                                 }),
                  bonuses.end());

    bgTiles.erase(std::remove_if(bgTiles.begin(), bgTiles.end(),
                                 [cameraY, bufferZone](const std::shared_ptr<BGTile>& tile) {
                                     auto y = tile->getCoords().second;
                                     return y > cameraY + bufferZone;
                                 }),
                  bgTiles.end());

    factory->cleanupViews(cameraY + bufferZone);
}

bool World::canPlaceBonus(const std::pair<float, float>& coords) {
    for (const auto& bonus : bonuses) {

        float bonusX = bonus->getCoords().first;
        float bonusY = bonus->getCoords().second;

        float dx = coords.first - bonusX;
        float dy = coords.second - bonusY;
        float distance = std::sqrt(dx * dx + dy * dy);

        if (distance < MIN_DISTANCE) {
            return false;
        }
    }
    return true;
}

bool World::shouldGenerateBonus(const std::shared_ptr<Platform>& platform, float playerY) {
    Random& random = Random::getInstance();
    bool shouldGenerate = (random.getFloat(0, 1) < 0.025f) && (platform->getCoords().second < playerY) &&
                          platform->getType() == PlatformType::STATIC;
    return shouldGenerate;
}

void World::generateBGTiles(float fromY, float toY) {
    for (float y = fromY; y > toY; y -= TILE_SIZE) {
        for (float x = 0; x < width; x += TILE_SIZE) {
            bgTiles.push_back(factory->createBGTile({x, y}));
        }
    }
}

World::~World() = default;

} // namespace Logic