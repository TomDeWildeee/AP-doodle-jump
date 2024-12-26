#include "../headers/logic/Subject.h"
#include <algorithm>

namespace Logic {
Subject::~Subject() = default;

void Subject::attach(const std::shared_ptr<Observer>& observer) { observers.push_back(observer); }

void Subject::detach(const std::shared_ptr<Observer>& observer) {
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end()) {
        observers.erase(it);
    }
}

void Subject::notify() {
    for (const auto& observer : observers) {
        observer->update();
    }
}

} // namespace Logic
