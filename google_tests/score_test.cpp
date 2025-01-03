#include "../logic/include/Score.h"
#include <gtest/gtest.h>

TEST(ScoreTest, InitialValues) {
    Logic::Score score = Logic::Score();
    EXPECT_EQ(score.getScore(), 0);
}

TEST(ScoreTest, UpdateScoreOnNewHeight) {
    Logic::Score score = Logic::Score();
    score.updateHeightScore(10.0f);
    EXPECT_EQ(score.getScore(), 10);
}

TEST(ScoreTest, UpdateScoreOnBonusCollected) {
    Logic::Score score = Logic::Score();
    score.updateBonusScore(Logic::BonusType::JETPACK);
    EXPECT_EQ(score.getScore(), 700);
}

TEST(ScoreTest, UpdateScoreOnPlatformReuse) {
    Logic::Score score = Logic::Score();
    score.updatePlatformReuseScore(Logic::PlatformType::STATIC);
    EXPECT_EQ(score.getScore(), -500);
}