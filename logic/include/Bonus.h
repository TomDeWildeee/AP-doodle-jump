/**
 * @file Bonus.h
 * @brief Defines bonus items that provide special abilities to the player
 */

#ifndef DOODLE_JUMP_BONUS_H
#define DOODLE_JUMP_BONUS_H

#include "EntityModel.h"

namespace Logic {
class Player;

/**
 * @enum BonusType
 * @brief Types of bonuses available in the game
 */
enum class BonusType { SPRING, JETPACK };

/**
 * @class Bonus
 * @brief Represents collectible bonus items in the game
 */
class Bonus : public EntityModel {
public:
    /**
     * @brief Constructs a bonus at specified coordinates
     * @param coords The x,y coordinates for the bonus
     * @param type The type of bonus (SPRING or JETPACK)
     */
    Bonus(const std::pair<float, float>& coords, BonusType type);

    /**
     * @brief Updates the bonus state
     * @param deltaTime Time elapsed since last update
     */
    void update(float deltaTime) override;

    /**
     * @brief Activates the bonus effect on a player
     * @param player The player to apply the bonus effect to
     */
    void activate(const std::shared_ptr<Player>& player);

    /**
     * @brief Gets the bonus type
     * @return The type of this bonus
     */
    [[nodiscard]] BonusType getType() const;

    /**
     * @brief Checks if the bonus is currently active
     * @return True if bonus is active, false otherwise
     */
    [[nodiscard]] bool isActive() const;

private:
    bool active = false;
    BonusType type;
    std::weak_ptr<Player> activePlayer;

    float jetpackForce = -800.0f;
    float jetpackDuration = 2.0f;
    float jetpackTimer = 0.0f;
};

} // namespace Logic

#endif // DOODLE_JUMP_BONUS_H
