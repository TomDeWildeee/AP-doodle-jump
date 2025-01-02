#ifndef DOODLE_JUMP_VIEWOBSERVER_H
#define DOODLE_JUMP_VIEWOBSERVER_H

namespace Logic {
enum class BonusType;
enum class PlatformType;
class ViewObserver {
public:
    virtual ~ViewObserver() = default;
    virtual void updateEntityView() = 0;
};
} // namespace Logic

#endif // DOODLE_JUMP_VIEWOBSERVER_H