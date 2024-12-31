#ifndef DOODLE_JUMP_SCORE_H
#define DOODLE_JUMP_SCORE_H

#include "Bonus.h"
#include "Observer.h"
namespace Logic {

class Score : public Observer {
public:
    Score();
    void update() override;

    void onNewHeight(float height);
    void onBonusCollected(BonusType bonusType);

    [[nodiscard]] int getScore() const;
    [[nodiscard]] int getHighScore() const;

    void resetScore();

private:
    int score = 0;
    int highScore = 0;
    float maxHeight = 0.0f;
};

} // namespace Logic

#endif // DOODLE_JUMP_SCORE_H
