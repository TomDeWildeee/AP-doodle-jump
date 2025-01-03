/**
 * @file Player.h
 * @brief Defines the player character entity
 */

#ifndef DOODLE_JUMP_PLAYER_H
#define DOODLE_JUMP_PLAYER_H

#include "EntityModel.h"

namespace Logic {

/**
 * @class Player
 * @brief Represents the playable character
 */
class Player : public EntityModel {
public:
    /**
     * @brief Constructs player at specified position
     * @param coords Starting coordinates
     */
    explicit Player(const std::pair<float, float>& coords);

    /**
     * @brief Updates player state
     * @param deltaTime Time elapsed since last update
     */
    void update(float deltaTime) override;

    /**
     * @brief Moves player left
     */
    void moveLeft();

    /**
     * @brief Moves player right
     */
    void moveRight();

    /**
     * @brief Makes player jump
     * @param force Jump force multiplier
     */
    void jump(float force = 2.5f);

    /**
     * @brief Notifies player of collected bonus
     * @param bonusType Type of bonus collected
     * @param isActive Whether bonus is active
     */
    void bonusCollected(BonusType bonusType, bool isActive);

    /**
     * @brief Notifies player of platform reuse
     * @param platformType Type of platform reused
     */
    void platformReuse(PlatformType platformType);

private:
    float moveSpeed = 200.0f;
    float jumpForce = -300.0f;
    float gravity = 800.0f;
};

} // namespace Logic

#endif // DOODLE_JUMP_PLAYER_H