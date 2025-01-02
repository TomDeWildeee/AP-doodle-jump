#ifndef DOODLE_JUMP_SCORE_H
#define DOODLE_JUMP_SCORE_H

#include "Bonus.h"
#include "Platform.h"
#include "Player.h"
#include "ViewObserver.h"
namespace Logic {

class Score : public ScoreObserver {
public:
    Score();
    ~Score();
    void updateHeightScore(float height) override;
    void updateBonusScore(BonusType bonusType) override;
    void updatePlatformReuseScore(PlatformType platformType) override;

    [[nodiscard]] int getScore() const;
    [[nodiscard]] int getHighScore() const;

    void readHighScore();
    void writeHighScore() const;

    void resetScore();

private:
    int score = 0;
    int highScore = 0;
    float maxHeight = 0.0f;
    std::weak_ptr<Player> player;
};

} // namespace Logic

#endif // DOODLE_JUMP_SCORE_H