#include "../../src/headers/logic/Score.h"
#include <gtest/gtest.h>

TEST(ScoreTest, InitialValues) {
    Logic::Score& score = Logic::Score::getInstance();
    EXPECT_EQ(score.getScore(), 0);
    EXPECT_EQ(score.getHighScore(), 0);
}

TEST(ScoreTest, UpdateScoreOnNewHeight) {
    Logic::Score& score = Logic::Score::getInstance();
    score.onNewHeight(10.0f);
    EXPECT_EQ(score.getScore(), 100);
    EXPECT_EQ(score.getHighScore(), 100);
}

TEST(ScoreTest, UpdateScoreOnBonusCollected) {
    Logic::Score& score = Logic::Score::getInstance();
    score.onBonusCollected(Logic::BonusType::JETPACK);
    EXPECT_EQ(score.getScore(), 200); // 100 from height + 100 from jetpack
    EXPECT_EQ(score.getHighScore(), 200);
}

TEST(ScoreTest, UpdateScoreOnPlatformReuse) {
    Logic::Score& score = Logic::Score::getInstance();
    score.onPlatformReuse(Logic::PlatformType::DISAPPEARING);
    EXPECT_EQ(score.getScore(), 215);
    EXPECT_EQ(score.getHighScore(), 215);
}