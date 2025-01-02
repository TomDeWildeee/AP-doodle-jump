#ifndef DOODLE_JUMP_OBSERVER_H
#define DOODLE_JUMP_OBSERVER_H

namespace Logic {
enum class BonusType;
enum class PlatformType;
class ScoreObserver {
public:
    virtual ~ScoreObserver() = default;
    virtual void updateHeightScore(float height) = 0;
    virtual void updateBonusScore(BonusType bonusType) = 0;
    virtual void updatePlatformReuseScore(PlatformType platformType) = 0;
};
} // namespace Logic

#endif // DOODLE_JUMP_OBSERVER_H