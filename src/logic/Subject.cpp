#include "../../include/logic/Subject.h"
#include <algorithm>

namespace Logic {
Subject::~Subject() = default;

void Subject::attachViewObserver(const std::shared_ptr<ViewObserver>& observer) { viewObservers.push_back(observer); }

void Subject::detachViewObserver(const std::shared_ptr<ViewObserver>& observer) {
    auto it = std::find(viewObservers.begin(), viewObservers.end(), observer);
    if (it != viewObservers.end()) {
        viewObservers.erase(it);
    }
}

void Subject::attachScoreObserver(const std::shared_ptr<ScoreObserver>& observer) {
    scoreObservers.push_back(observer);
}

void Subject::detachScoreObserver(const std::shared_ptr<ScoreObserver>& observer) {
    auto it = std::find(scoreObservers.begin(), scoreObservers.end(), observer);
    if (it != scoreObservers.end()) {
        scoreObservers.erase(it);
    }
}

void Subject::notifyEntityUpdate() {
    for (const auto& observer : viewObservers) {
        observer->updateEntityView();
    }
}

void Subject::notifyBonusCollected(BonusType type) {
    for (const auto& observer : scoreObservers) {
        observer->updateBonusScore(type);
    }
}

void Subject::notifyPlatformReuse(PlatformType type) {
    for (const auto& observer : scoreObservers) {
        observer->updatePlatformReuseScore(type);
    }
}

void Subject::notifyHeight(float height) {
    for (const auto& observer : scoreObservers) {
        observer->updateHeightScore(height);
    }
}

} // namespace Logic