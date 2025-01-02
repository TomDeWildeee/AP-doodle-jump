#include "../logic/include/EntityModel.h"
#include <gtest/gtest.h>
#include <memory>

class TestObserver : public Logic::ViewObserver {
public:
    bool updated = false;

    void updateEntityView() override { updated = true; }
};

class TestEntityModel : public Logic::EntityModel {
public:
    explicit TestEntityModel(const std::pair<float, float>& coords) : EntityModel(coords) {}

    void update(float deltaTime) override {}
};

TEST(EntityModelTest, GetCoords) {
    TestEntityModel entity({10.0f, 20.0f});
    auto coords = entity.getCoords();
    ASSERT_EQ(coords.first, 10.0f);
    ASSERT_EQ(coords.second, 20.0f);
}

TEST(EntityModelTest, GetVelocity) {
    TestEntityModel entity({10.0f, 20.0f});
    auto velocity = entity.getVelocity();
    ASSERT_EQ(velocity.first, 0.0f);
    ASSERT_EQ(velocity.second, 0.0f);
}

TEST(EntityModelTest, SetCoords) {
    TestEntityModel entity({10.0f, 20.0f});
    auto observer = std::make_shared<TestObserver>();
    entity.attachViewObserver(observer);

    entity.setCoords({30.0f, 40.0f});
    auto coords = entity.getCoords();
    ASSERT_EQ(coords.first, 30.0f);
    ASSERT_EQ(coords.second, 40.0f);
    ASSERT_TRUE(observer->updated);
}

TEST(EntityModelTest, SetVelocity) {
    TestEntityModel entity({10.0f, 20.0f});
    auto observer = std::make_shared<TestObserver>();
    entity.attachViewObserver(observer);

    entity.setVelocity({5.0f, 15.0f});
    auto velocity = entity.getVelocity();
    ASSERT_EQ(velocity.first, 5.0f);
    ASSERT_EQ(velocity.second, 15.0f);
    ASSERT_TRUE(observer->updated);
}