#include "../headers/logic/Score.h"

namespace Logic {

Score::Score() = default;

Score& Score::getInstance() {
    static Score instance;
    return instance;
}

void Score::update(){};

void Score::onNewHeight(float height) {
    if (height > maxHeight) {
        int newScore = static_cast<int>((height - maxHeight) * 10);
        score += newScore;
        maxHeight = height;
        highScore = std::max(score, highScore);
    }
}

void Score::onBonusCollected(BonusType bonusType) {
    switch (bonusType) {
    case BonusType::JETPACK:
        score += 100;
        break;
    case BonusType::SPRING:
        score += 50;
        break;
    }
    highScore = std::max(score, highScore);
}

void Score::onPlatformReuse(PlatformType platformType) {
    switch (platformType) {
    case PlatformType::NORMAL:
        score -= 10;
        break;
    case PlatformType::MOVABLE:
        score -= 5;
        break;
    case PlatformType::DISAPPEARING:
        score += 15;
        break;
    case PlatformType::BREAKABLE:
        break;
    }
    score = std::max(score, highScore);
}

} // namespace Logic