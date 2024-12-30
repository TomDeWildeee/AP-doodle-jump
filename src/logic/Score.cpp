#include "../headers/logic/Score.h"

namespace Logic {

Score::Score() = default;

void Score::update() {
    if (score > highScore) {
        highScore = score;
    }
};

void Score::onNewHeight(float height) {
    if (height > maxHeight) {
        int newScore = (int)(height - maxHeight) * 10;
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

int Score::getScore() const { return score; }
int Score::getHighScore() const { return highScore; }
void Score::resetScore() { score = 0; }

} // namespace Logic