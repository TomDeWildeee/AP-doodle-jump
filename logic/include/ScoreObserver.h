/**
 * @file ScoreObserver.h
 * @brief Observer interface for score updates
 */

#ifndef DOODLE_JUMP_OBSERVER_H
#define DOODLE_JUMP_OBSERVER_H

namespace Logic {
enum class BonusType;
enum class PlatformType;

/**
 * @class ScoreObserver
 * @brief Abstract observer interface for score-related events
 */
class ScoreObserver {
public:
    virtual ~ScoreObserver() = default;

    /**
     * @brief Called when height score should be updated
     * @param height New height reached
     */
    virtual void updateHeightScore(float height) = 0;

    /**
     * @brief Called when bonus score should be updated
     * @param bonusType Type of bonus collected
     */
    virtual void updateBonusScore(BonusType bonusType) = 0;

    /**
     * @brief Called when platform reuse score should be updated
     * @param platformType Type of platform reused
     */
    virtual void updatePlatformReuseScore(PlatformType platformType) = 0;
};
} // namespace Logic

#endif // DOODLE_JUMP_OBSERVER_H