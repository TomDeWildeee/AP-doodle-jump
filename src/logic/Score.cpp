#include "../../include/logic/Score.h"
#include <cmath>

namespace Logic {

Score::Score() = default;

void Score::update() {
    if (score > highScore) {
        highScore = score;
    }
};

void Score::onNewHeight(float height) {
    float absHeight = std::abs(height);
    if (absHeight > maxHeight) {
        int newScore = (int)(absHeight - maxHeight);
        score += newScore;
        maxHeight = absHeight;
        highScore = std::max(score, highScore);
    }
}

void Score::onBonusCollected(BonusType bonusType) {
    switch (bonusType) {
    case BonusType::JETPACK:
        score += 700;
        break;
    case BonusType::SPRING:
        score += 350;
        break;
    }

    highScore = std::max(score, highScore);
}

int Score::getScore() const { return score; }
int Score::getHighScore() const { return highScore; }
void Score::resetScore() {
    score = 0;
    maxHeight = 0;
}

} // namespace Logic