/**
 * @file Platform.h
 * @brief Defines platform entities that the player can jump on
 */

#ifndef DOODLE_JUMP_PLATFORM_H
#define DOODLE_JUMP_PLATFORM_H

#include "EntityModel.h"
namespace Logic {

/**
 * @enum PlatformType
 * @brief Types of platforms available in the game
 */
enum class PlatformType { STATIC, HORIZONTAL, VERTICAL, TEMPORARY };

/**
 * @class Platform
 * @brief Represents platforms that the player can jump on
 */
class Platform : public EntityModel {
public:
    /**
     * @brief Constructs a platform
     * @param coords Initial position
     * @param type Platform type
     */
    Platform(const std::pair<float, float>& coords, PlatformType type);

    /**
     * @brief Updates platform state
     * @param deltaTime Time elapsed since last update
     */
    void update(float deltaTime) override;

    /**
     * @brief Deactivates the platform
     */
    void deActivate();

    /**
     * @brief Gets platform type
     * @return Platform type
     */
    [[nodiscard]] PlatformType getType() const;

    /**
     * @brief Checks if platform is active
     * @return True if active, false if deactivated
     */
    [[nodiscard]] bool isActive() const;

    /**
     * @brief Increments jump counter
     */
    void incrementJumps();

    /**
     * @brief Gets number of times jumped on
     * @return Jump count
     */
    [[nodiscard]] int getTimesJumpedOn() const;

private:
    PlatformType type;
    bool active = true;
    float initialX;
    float initialY;
    float moveDistance = 100.0f;
    float moveSpeed = 100.0f;
    float timeElapsed;

    int timesJumpedOn = 0;
};

} // namespace Logic
#endif // DOODLE_JUMP_PLATFORM_H