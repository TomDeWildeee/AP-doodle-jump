#ifndef DOODLE_JUMP_OBSERVER_H
#define DOODLE_JUMP_OBSERVER_H

namespace Logic {
class Observer {
public:
    virtual ~Observer() = default;

    // Default update method
    virtual void update() = 0;
};
} // namespace Logic

#endif // DOODLE_JUMP_OBSERVER_H