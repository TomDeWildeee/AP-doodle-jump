/**
 * @file Score.h
 * @brief Manages game scoring system
 */

#ifndef DOODLE_JUMP_SCORE_H
#define DOODLE_JUMP_SCORE_H

#include "Bonus.h"
#include "Platform.h"
#include "Player.h"
#include "ViewObserver.h"
namespace Logic {

/**
 * @class Score
 * @brief Handles score tracking and high score management
 */
class Score : public ScoreObserver {
public:
    /**
     * @brief Constructs a score manager (reads high score from file, if available)
     */
    Score();

    /**
     * @brief Destructs the score manager (writes high score to file)
     */
    ~Score() override;

    /**
     * @brief Updates score based on height reached
     * @param height Current height reached
     */
    void updateHeightScore(float height) override;

    /**
     * @brief Updates score based on bonus collection
     * @param bonusType Type of bonus collected
     */
    void updateBonusScore(BonusType bonusType) override;

    /**
     * @brief Updates score based on platform reuse
     * @param platformType Type of platform reused
     */
    void updatePlatformReuseScore(PlatformType platformType) override;

    /**
     * @brief Gets current score
     * @return Current score value
     */
    [[nodiscard]] int getScore() const;

    /**
     * @brief Gets high score
     * @return High score value
     */
    [[nodiscard]] int getHighScore() const;

    /**
     * @brief Reads high score from file (if available)
     */
    void readHighScore();

    /**
     * @brief Writes current high score to file
     */
    void writeHighScore() const;

    /**
     * @brief Resets current score to zero
     */
    void resetScore();

private:
    int score = 0;
    int highScore = 0;
    float maxHeight = 0.0f;
    std::weak_ptr<Player> player;
};

} // namespace Logic

#endif // DOODLE_JUMP_SCORE_H