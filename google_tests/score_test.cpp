#include "../../src/headers/logic/Score.h"
#include <gtest/gtest.h>

TEST(ScoreTest, InitialValues) {
    Logic::Score score = Logic::Score();
    EXPECT_EQ(score.getScore(), 0);
    EXPECT_EQ(score.getHighScore(), 0);
}

TEST(ScoreTest, UpdateScoreOnNewHeight) {
    Logic::Score score = Logic::Score();
    score.onNewHeight(10.0f);
    EXPECT_EQ(score.getScore(), 100);
    EXPECT_EQ(score.getHighScore(), 100);
}

TEST(ScoreTest, UpdateScoreOnBonusCollected) {
    Logic::Score score = Logic::Score();
    score.onBonusCollected(Logic::BonusType::JETPACK);
    EXPECT_EQ(score.getScore(), 100);
    EXPECT_EQ(score.getHighScore(), 100);
}