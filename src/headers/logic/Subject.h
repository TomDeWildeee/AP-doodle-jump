#ifndef DOODLE_JUMP_SUBJECT_H
#define DOODLE_JUMP_SUBJECT_H

#include "Observer.h"
#include <memory>
#include <vector>
namespace Logic {

class Subject {
public:
    virtual ~Subject();

    void attach(const std::shared_ptr<Observer>& observer);
    void detach(const std::shared_ptr<Observer>& observer);
    void notify();

private:
    std::vector<std::shared_ptr<Observer>> observers;
};

} // namespace Logic

#endif // DOODLE_JUMP_SUBJECT_H