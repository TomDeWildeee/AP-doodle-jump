#include "../include/World.h"
#include "../include/Random.h"
#include "../include/Stopwatch.h"
#include "GameException.h"
#include <algorithm>
#include <iostream>

namespace Logic {

const float TILE_SIZE = 20.0f;
const float MIN_DISTANCE = 30.0f;

World::World(float width, float height, const std::shared_ptr<EntityFactory>& factory)
    : factory(factory), width(width), height(height) {

    if (!factory) {
        throw NotInitializedException("EntityFactory not initialized");
    }

    // Create player and camera and check if they are initialized correctly
    player = factory->createPlayer({width / 2, height / 2});
    camera = std::make_unique<Camera>(width, height);

    if (!player) {
        throw NotInitializedException("Player not initialized");
    }

    if (!camera) {
        throw NotInitializedException("Camera not initialized");
    }

    // Make player jump at the start of the game
    player->jump();

    // Generate platforms and background tiles and check if they are initialized correctly
    generatePlatforms(height, 0);
    generateBGTiles(height, 0);

    if (platforms.empty()) {
        throw NotInitializedException("No platforms generated");
    }

    if (bgTiles.empty()) {
        throw NotInitializedException("No background tiles generated");
    }
}

void World::update() {

    // Get random instance and stopwatch instance
    Random& random = Random::getInstance();
    Stopwatch stopwatch = Stopwatch::getInstance();

    // Get delta time
    float deltaTime = stopwatch.getDeltaTime();

    // Update player and check if player is out of bounds
    player->update(deltaTime);

    float playerX = player->getCoords().first;
    float playerY = player->getCoords().second;

    // Check if player is out of bounds and set player coords to the opposite side
    if (playerX < 25) {
        player->setCoords({width - 25, player->getCoords().second});
    } else if (playerX > width - 25) {
        player->setCoords({25, player->getCoords().second});
    }

    // Update background tiles, platforms and bonuses with delta time
    for (auto& bgTile : bgTiles) {
        bgTile->update(deltaTime);
    }

    for (auto& platform : platforms) {
        platform->update(deltaTime);
    }

    for (auto& bonus : bonuses) {
        bonus->update(deltaTime);
    }

    // Update camera so it follows the player going upwards
    camera->update(player->getCoords().second);

    float highestYCoord = 0;
    float highestBGTileYCoord = 0;

    // Check highest y coordinate of platforms and notify player of the highest y coordinate reached to update score
    if (!platforms.empty()) {
        highestYCoord = platforms[0]->getCoords().second;
        for (const auto& platform : platforms) {
            if (platform->getCoords().second < highestYCoord) {
                highestYCoord = platform->getCoords().second;
                player->notifyHeight(highestYCoord);
            }
        }
    }

    // Get highest y coordinate of background tiles
    for (const auto& tile : bgTiles) {
        highestBGTileYCoord = std::min(highestBGTileYCoord, tile->getCoords().second);
    }

    float cameraY = camera->getY();
    float topOfView = cameraY - height / 2;

    // Generate background tiles from the highest y coordinate of the background tiles to the top of the view - height
    if (highestBGTileYCoord > topOfView - 100) {
        generateBGTiles(highestBGTileYCoord, topOfView - height);
    }

    // Generate platforms and bonuses from the highest y coordinate of the platforms to the top of the view - height
    if (highestYCoord > topOfView - 300) {
        generatePlatforms(highestYCoord - width / 2, topOfView - height);

        for (const auto& platform : platforms) {

            // Check if a bonus should be generated on the platform
            if (shouldGenerateBonus(platform, playerY)) {
                float bonusX = platform->getCoords().first;
                float bonusY = platform->getCoords().second - 30.0f;

                // Check if a bonus can be placed on the platform
                if (canPlaceBonus({bonusX, bonusY})) {
                    BonusType type = (random.getFloat(0, 1) < 0.8f) ? BonusType::SPRING : BonusType::JETPACK;
                    bonuses.push_back(factory->createBonus({bonusX, bonusY}, type));
                }
            }
        }
    }

    // Check collisions between player and platforms and bonuses
    checkCollisions();

    // Clean up platforms, bonuses and background tiles
    cleanup();
}

void World::checkCollisions() {

    // Loop through all platforms and check if player collides with the platform
    for (const auto& platform : platforms) {

        // Check if platform is active
        if (!platform->isActive())
            continue;

        float px = player->getCoords().first;
        float py = player->getCoords().second;
        float platX = platform->getCoords().first;
        float platY = platform->getCoords().second - 20; // - 20 to make the collision be at the top of the platform

        // Check if player is falling and collides with the platform
        if (player->getVelocity().second > 0) {

            // Compute distance between player and platform
            float verticalDistance = std::abs(py - platY);
            float horizontalDistance = std::abs(px - platX);

            // Check if player is close enough to the platform to jump
            if (verticalDistance < 20 && horizontalDistance < 60) {

                // Increment jumps and check if player reuses the platform
                platform->incrementJumps();
                if (platform->getTimesJumpedOn() > 1) {
                    player->platformReuse(platform->getType());
                }

                // Make player jump
                player->jump();
            }
        }
    }

    // Loop through all bonuses and check if player collides with the bonus
    for (const auto& bonus : bonuses) {

        float px = player->getCoords().first;
        float py = player->getCoords().second;
        float bonusX = bonus->getCoords().first;
        float bonusY = bonus->getCoords().second;

        // Compute distance between player and bonus
        float verticalDistance = std::abs(py - bonusY);
        float horizontalDistance = std::abs(px - bonusX);

        // Check if player is close enough to the bonus to collect it
        if (verticalDistance < 30 && horizontalDistance < 30) {

            // Notify player of the bonus collected and activate the bonus
            player->bonusCollected(bonus->getType(), bonus->isActive());
            bonus->activate(player);
            break;
        }
    }
}

PlatformType World::getRandomPlatformType(float randValue) {
    std::vector<std::pair<PlatformType, float>> weightedTypes = {{PlatformType::STATIC, 80.0f},
                                                                 {PlatformType::TEMPORARY, 10.0f},
                                                                 {PlatformType::HORIZONTAL, 5.0f},
                                                                 {PlatformType::VERTICAL, 5.0f}};
    // Go through the weighted types and return the type if the random value is less than or equal the cumulative weight
    float cumulativeWeight = 0.0f;
    for (const auto& typeWeight : weightedTypes) {
        cumulativeWeight += typeWeight.second;
        if (randValue <= cumulativeWeight) {
            return typeWeight.first;
        }
    }

    return PlatformType::STATIC;
}

void World::generatePlatforms(float fromY, float toY) {
    // Get random instance
    Random& random = Random::getInstance();

    // Compute height factor
    float heightFactor = std::min((-fromY / 100000.0f), 100.0f);

    // Small struct to store platform positions, used to check if platforms are too close
    struct PlatformPos {
        float x, y;
    };

    std::vector<PlatformPos> generatedPositions;
    float verticalSpacing = random.getFloat(40.0f, 70.0f);

    // Generate platforms from the top of the view to the bottom of the view with a vertical spacing between platforms
    for (float y = fromY; y > toY; y -= verticalSpacing) {

        // Compute spawn chance based on height factor
        float spawnChance = 0.95f - (heightFactor * 0.15f);

        // Generate random x position and check if a platform should be spawned based on the spawn chance
        if (random.getFloat(0, 1) < spawnChance) {
            float x;

            // Randomly choose x position to spawn the platform on the left or right side of the screen
            if (random.getInt(0, 1) == 0) {
                x = random.getFloat(100.0f, width / 2 - 50.0f);
            } else {
                x = random.getFloat(width / 2 + 50.0f, width - 100.0f);
            }

            // Check if the platform is too close to another platform
            bool tooClose = false;
            for (const auto& pos : generatedPositions) {
                float dx = std::abs(x - pos.x);
                float dy = std::abs(y - pos.y);

                // Compute distance between the platforms using Pythagorean theorem (sqrt(dx^2 + dy^2))
                float distance = std::sqrt(dx * dx + dy * dy);

                // If the distance between the platforms is less than 60, the platform is too close
                if (distance < 60.0f) {
                    tooClose = true;
                    break;
                }
            }

            // Generate random platform type based on the random value
            float randomValue = random.getFloat(0.0f, 100.0f);
            PlatformType randomPlatformType = getRandomPlatformType(randomValue);

            // If the platform is not too close to another platform, create the platform and add it to the list of
            // platforms and generated positions list
            if (!tooClose) {
                platforms.push_back(factory->createPlatform({x, y}, randomPlatformType));
                generatedPositions.push_back({x, y});
            }
        }

        // Randomize vertical spacing between platforms
        verticalSpacing = random.getFloat(40.0f, 70.0f);
    }
}

void World::cleanup() {

    // Remove platforms if they are not visible or not active
    platforms.erase(std::remove_if(platforms.begin(), platforms.end(),
                                   [this](const std::shared_ptr<Platform>& platform) {
                                       if (!platform->isActive())
                                           return true;
                                       auto y = platform->getCoords().second;
                                       return !camera->isVisible(y);
                                   }),
                    platforms.end());

    // Remove bonuses if they are not visible
    bonuses.erase(std::remove_if(bonuses.begin(), bonuses.end(),
                                 [this](const std::shared_ptr<Bonus>& bonus) {
                                     auto y = bonus->getCoords().second;
                                     return (!camera->isVisible(y) && !bonus->isActive());
                                 }),
                  bonuses.end());

    // Remove background tiles if they are not visible
    bgTiles.erase(std::remove_if(bgTiles.begin(), bgTiles.end(),
                                 [this](const std::shared_ptr<BGTile>& tile) {
                                     auto y = tile->getCoords().second;
                                     return !camera->isVisible(y);
                                 }),
                  bgTiles.end());

    // Cleanup views of the entity factory to remove entities that are not visible anymore
    factory->cleanupViews(camera->getY() + camera->getBufferzone());
}

bool World::canPlaceBonus(const std::pair<float, float>& coords) {

    // Check if the distance between the bonus and the other bonuses is less than the minimum distance to place a bonus
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

    // Get random instance
    Random& random = Random::getInstance();

    // Check if a bonus should be generated based on the random value and the position of the platform
    bool shouldGenerate = (random.getFloat(0, 1) < 0.025f) && (platform->getCoords().second < playerY) &&
                          platform->getType() == PlatformType::STATIC;
    return shouldGenerate;
}

void World::generateBGTiles(float fromY, float toY) {
    // Generate background tiles from the top of the view to the bottom of the view with a set TILE_SIZE
    for (float y = fromY; y > toY; y -= TILE_SIZE) {
        for (float x = 0; x < width; x += TILE_SIZE) {
            bgTiles.push_back(factory->createBGTile({x, y}));
        }
    }
}

World::~World() = default;

} // namespace Logic