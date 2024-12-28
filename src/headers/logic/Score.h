#ifndef DOODLE_JUMP_SCORE_H
#define DOODLE_JUMP_SCORE_H

#include "Bonus.h"
#include "Observer.h"
#include "Platform.h"
namespace Logic {

class Score : public Observer {
public:
    // Also made score a singleton
    static Score& getInstance();

    void update() override;
    void onNewHeight(float height);

    // Added, because I saw they were getting used in scoring as well. Not sure if they are needed
    void onBonusCollected(BonusType bonusType);
    void onPlatformReuse(PlatformType platformType);

    [[nodiscard]] int getScore() const;
    [[nodiscard]] int getHighScore() const;

private:
    Score();
    int score = 0;
    int highScore = 0;
    float maxHeight = 0.0f;
};

} // namespace Logic

#endif // DOODLE_JUMP_SCORE_H
