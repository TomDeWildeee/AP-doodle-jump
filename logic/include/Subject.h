#ifndef DOODLE_JUMP_SUBJECT_H
#define DOODLE_JUMP_SUBJECT_H

#include "ScoreObserver.h"
#include "ViewObserver.h"
#include <memory>
#include <vector>
namespace Logic {

class Subject {
public:
    virtual ~Subject();

    void attachViewObserver(const std::shared_ptr<ViewObserver>& observer);
    void detachViewObserver(const std::shared_ptr<ViewObserver>& observer);
    void attachScoreObserver(const std::shared_ptr<ScoreObserver>& observer);
    void detachScoreObserver(const std::shared_ptr<ScoreObserver>& observer);

    void notifyEntityUpdate();
    void notifyBonusCollected(BonusType type);
    void notifyPlatformReuse(PlatformType type);
    void notifyHeight(float height);

private:
    std::vector<std::shared_ptr<ViewObserver>> viewObservers;
    std::vector<std::shared_ptr<ScoreObserver>> scoreObservers;
};

} // namespace Logic

#endif // DOODLE_JUMP_SUBJECT_H