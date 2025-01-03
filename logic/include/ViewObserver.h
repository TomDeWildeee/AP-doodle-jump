/**
 * @file ViewObserver.h
 * @brief Interface for view observers in Observer pattern
 */

#ifndef DOODLE_JUMP_VIEWOBSERVER_H
#define DOODLE_JUMP_VIEWOBSERVER_H

namespace Logic {
enum class BonusType;
enum class PlatformType;

/**
 * @class ViewObserver
 * @brief Abstract base class for view observers
 */
class ViewObserver {
public:
    virtual ~ViewObserver() = default;
    
    /**
     * @brief Called when entity needs view update
     */
    virtual void updateEntityView() = 0;
};
} // namespace Logic

#endif // DOODLE_JUMP_VIEWOBSERVER_H