#include "../include/Score.h"
#include <cmath>
#include <fstream>

namespace Logic {

Score::Score() { readHighScore(); }
Score::~Score() { writeHighScore(); }

void Score::readHighScore() {
    std::ifstream file("highscore.txt");
    if (file.is_open()) {
        file >> highScore;
        file.close();
    } else {
        highScore = 0;
    }
}

void Score::writeHighScore() const {
    std::ofstream file("highscore.txt");
    if (file.is_open()) {
        file << highScore;
        file.close();
    }
}

void Score::updateHeightScore(float height) {
    float absHeight = std::abs(height);
    if (absHeight > maxHeight) {
        int newScore = (int)(absHeight - maxHeight);
        score += newScore;
        maxHeight = absHeight;
        highScore = std::max(score, highScore);
    }
}

void Score::updateBonusScore(BonusType bonusType) {
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
void Score::updatePlatformReuseScore(PlatformType platformType) {
    switch (platformType) {
    case PlatformType::STATIC:
        score -= 500;
        break;
    case PlatformType::TEMPORARY:
        break;
    default:
        score -= 200;
        break;
    }

    highScore = std::max(score, highScore);
}
} // namespace Logic