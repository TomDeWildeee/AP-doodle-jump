/**
 * @file Subject.h
 * @brief Implementation of Observer pattern subject
 */

#ifndef DOODLE_JUMP_SUBJECT_H
#define DOODLE_JUMP_SUBJECT_H

#include "ScoreObserver.h"
#include "ViewObserver.h"
#include <memory>
#include <vector>
namespace Logic {

/**
 * @class Subject
 * @brief Base class for observable objects in Observer pattern
 */
class Subject {
public:
    virtual ~Subject();

    /**
     * @brief Adds view observer
     * @param observer Observer to add
     */
    void attachViewObserver(const std::shared_ptr<ViewObserver>& observer);

    /**
     * @brief Removes view observer
     * @param observer Observer to remove
     */
    void detachViewObserver(const std::shared_ptr<ViewObserver>& observer);

    /**
     * @brief Adds score observer
     * @param observer Observer to add
     */
    void attachScoreObserver(const std::shared_ptr<ScoreObserver>& observer);

    /**
     * @brief Removes score observer
     * @param observer Observer to remove
     */
    void detachScoreObserver(const std::shared_ptr<ScoreObserver>& observer);

    /**
     * @brief Notifies view observers of entity updates
     */
    void notifyEntityUpdate();

    /**
     * @brief Notifies score observers of bonus collection
     * @param type Type of bonus collected
     */
    void notifyBonusCollected(BonusType type);

    /**
     * @brief Notifies score observers of platform reuse
     * @param type Type of platform reused
     */
    void notifyPlatformReuse(PlatformType type);

    /**
     * @brief Notifies score observers of height update
     * @param height New height reached
     */
    void notifyHeight(float height);

private:
    std::vector<std::shared_ptr<ViewObserver>> viewObservers;
    std::vector<std::shared_ptr<ScoreObserver>> scoreObservers;
};

} // namespace Logic

#endif // DOODLE_JUMP_SUBJECT_H